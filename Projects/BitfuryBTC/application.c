/*
 Bitfury BF1 USB miner
 Copyright (C) Andreas Auer, 2013.

 aauer1 [at] gmail [dot] com
 www.emicrotec.at

 Want to say thanks? You can donate at:
 1Q2kFyoqVdYjoguvSsVAhsr66CtF2c3YX4
 */

/*
 Copyright 2013  Andreas Auer (aauer1 [at] gmail [dot] com)

 Permission to use, copy, modify, distribute, and sell this
 software and its documentation for any purpose is hereby granted
 without fee, provided that the above copyright notice appear in
 all copies and that both that the copyright notice and this
 permission notice and warranty disclaimer appear in supporting
 documentation, and that the name of the author not be used in
 advertising or publicity pertaining to distribution of the
 software without specific, written prior permission.

 The author disclaim all warranties with regard to this
 software, including all implied warranties of merchantability
 and fitness.  In no event shall the author be liable for any
 special, indirect or consequential damages or any damages
 whatsoever resulting from loss of use, data or profits, whether
 in an action of contract, negligence or other tortious action,
 arising out of or in connection with the use or performance of
 this software.
 */

#include <avr/boot.h>

#include <LUFA/Drivers/Peripheral/Serial.h>

#include "application.h"
#include "bitfury.h"
#include "timer.h"
#include "main.h"

// c0fd4d9ce1c955f09d070fe6daa6adee3d8859d49d9a04d8969a9fd4ed2f971528258b044f2dcb7a1a0c290b
/*
 * 0x9c4dfdc0, 0xf055c9e1, 0xe60f079d, 0xeeada6da, 0xd459883d, 0xd8049a9d, 0xd49f9a96, 0x15972fed, MIDSTATE
 * 0,0,0,0,0,0,0,0,
 * 0x048b2528, 0x7acb2d4f, 0x0b290c1a, 0xbe00084a
 */
//#define GOOD_MIDSTATE       { 0x5fddb5bc,0x00bdafd2,0x144684c7,0x19c68fa2,0x27d0a8e3,0x34ad84b2,0xa92c66be,0x3e99a4fd }
//#define GOOD_DATA           { 0xf64684bb,0x51bc1508,0x1a011337, 0x00000000 }

// 8e2de7b062b8c51da6c4e7e9f5f150307e6b1a8ae884c37efcc3c142a158d18eb7b70b8a4f30af331a0c290b

#define GOOD_MIDSTATE   { 0xb0e72d8e, 0x1dc5b862, 0xe9e7c4a6, 0x3050f1f5, 0x8a1a6b7e, 0x7ec384e8, 0x42c1c3fc, 0x8ed158a1 }
#define GOOD_DATA       { 0x8a0bb7b7, 0x33af304f, 0x0b290c1a, 0xf0c4e61f }

static Identity ID =
{
    .version = 1,
    .product = "BF1",
    .serial  = 0x20130712,
};

const static WorkUnit GOOD_WORK =
{
    .midstate = GOOD_MIDSTATE,
    .junk = { 0, 0, 0, 0, 0, 0, 0, 0 },
    .data = GOOD_DATA,
};

//------------------------------------------------------------------------------
static void usbWrite(Application *app, uint8_t *data, uint8_t size)
{
    uint8_t i=0;
    for(i=0; i<size; i++)
        RingBuffer_Insert(&app->USARTtoUSB_Buffer, data[i]);
}

//------------------------------------------------------------------------------
static void sendCmdReply(Application *app, uint8_t cmd, uint8_t *data, uint8_t size)
{
    usbWrite(app, &cmd, 1);
    usbWrite(app, data, size);
}

//------------------------------------------------------------------------------
static void pushWork(Application *app, WorkUnit *work)
{
    asicSendHashData(work);
}

//------------------------------------------------------------------------------
static uint8_t serialProcess(Application *app)
{
    uint16_t count = RingBuffer_GetCount(&app->buffer_);
    if(count == 0)
        return true;

    uint8_t cmd = RingBuffer_Peek(&app->buffer_);
    switch(cmd)
    {
        case 'L':
            RingBuffer_Remove(&app->buffer_);
            LEDs_ToggleLEDs(LEDS_LED1);
            break;

        case 'R':
            RingBuffer_Remove(&app->buffer_);
            memcpy(&app->worktask, &GOOD_WORK, sizeof(GOOD_WORK));
#if 0
            {
                uint8_t i=0;
                asicPrecompute(&app->worktask);
                for(i=0; i<8; i++)
                {
                    printf("%08lX ", app->worktask.junk[i]);
                }
            }
#endif
            asicReset();
            if(asicInitChip(&app->worktask))
            {
                uint8_t i=0;
                LEDs_ToggleLEDs(LEDS_LED1);
            }
            app->state.state = STATE_RESET;
            sendCmdReply(app, cmd, (uint8_t *)&app->state, sizeof(State));
            break;

        case 'I':
            RingBuffer_Remove(&app->buffer_);
            sendCmdReply(app, cmd, (uint8_t *)&ID, sizeof(ID));
            break;

        case 'A':
            RingBuffer_Remove(&app->buffer_);
            app->state.state = STATE_RESET;
            sendCmdReply(app, cmd, (uint8_t *)&app->state, sizeof(State));
            break;

        case 'S':
            RingBuffer_Remove(&app->buffer_);
            sendCmdReply(app, cmd, (uint8_t *)&app->state, sizeof(State));
            break;

        case 'W':
            if(count > 44) // 32 bytes midstate + 12 bytes data
            {
                RingBuffer_Remove(&app->buffer_);

                uint8_t i = 0;
                uint8_t *midstate = (uint8_t *)app->worktask.midstate;
                uint8_t *data = (uint8_t *)app->worktask.data;
                memset(&app->worktask, 0, sizeof(WorkUnit));
                for(i=0; i<32; i++)
                {
                    midstate[i] = RingBuffer_Remove(&app->buffer_);
                }
                for(i=0; i<12; i++)
                {
                    data[i] = RingBuffer_Remove(&app->buffer_);
                }

                asicPrecompute(&app->worktask);
                asicSendHashData(&app->worktask);
                timerSet(&app->work_timer, 100);

                app->state.state = STATE_WORKING;
                app->state.switched = 0;
                app->state.nonce = 0;

                sendCmdReply(app, cmd, (uint8_t *)&app->state, sizeof(State));
            }
            break;

        default:
            RingBuffer_Remove(&app->buffer_);
            break;
    }

    return true;
}

//------------------------------------------------------------------------------
void appInit(Application *app)
{
    uint8_t i=0;

    RingBuffer_InitBuffer(&app->USARTtoUSB_Buffer, app->USARTtoUSB_Buffer_Data, sizeof(app->USARTtoUSB_Buffer_Data));
    RingBuffer_InitBuffer(&app->buffer_, app->buffer_data_, sizeof(app->buffer_data_));

    app->state.state = STATE_RESET;

    ID.serial = 0;
    for(i=6; i<10; i++)
    {
        ID.serial <<= 8;
        ID.serial |= boot_signature_byte_get(i+0x0E);
    }

    asicInit();
    //asicStop();
}

//------------------------------------------------------------------------------
void appService(Application *app)
{
    if(timerExpired(&app->work_timer))
    {
        uint8_t i=0;
        WorkUnit *work = &app->worktask;

        asicSendHashData(&app->worktask);
        if(asicGetSwitched())
        {
            app->state.state = STATE_DONE;
            app->state.switched = asicGetSwitched();
            for(i=0; i < work->num_results; i++)
            {
                app->state.nonce = work->results[i];
                sendCmdReply(app, 'S', (uint8_t *)&app->state, sizeof(app->state));
            }
        }
        else
        {
            timerRestart(&app->work_timer);
        }
    }
}

//------------------------------------------------------------------------------
void appUsbDataReceived(Application *app)
{
    int16_t received_byte = 0;
    while((received_byte = CDC_Device_ReceiveByte(app->cdc_info)) >= 0)
    {
        RingBuffer_Insert(&app->buffer_, received_byte);
    }
    serialProcess(app);
}

