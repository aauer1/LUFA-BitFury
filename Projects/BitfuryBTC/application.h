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

#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <LUFA/Drivers/USB/USB.h>
#include <LUFA/Drivers/Misc/RingBuffer.h>

#include "timer.h"

typedef struct Application_     Application;
typedef struct Identity_        Identity;
typedef struct WorkUnit_        WorkUnit;
typedef struct State_           State;

#define STATE_WORKING           'W'
#define STATE_DONE              'D'
#define STATE_RESET             'R'

struct Identity_
{
    uint8_t version;
    char product[8];
    uint32_t serial;
};

struct WorkUnit_
{
    uint32_t midstate[8];
    uint32_t junk[8];
    uint32_t data[4];

    uint8_t  num_results;
    uint32_t results[16];
};

struct State_
{
    uint8_t state;
    uint8_t switched;
    uint32_t nonce;
};

struct Application_
{
    USB_ClassInfo_CDC_Device_t *cdc_info;

    //private:
    RingBuffer_t USARTtoUSB_Buffer;
    uint8_t USARTtoUSB_Buffer_Data[128];

    RingBuffer_t buffer_;
    uint8_t buffer_data_[64];

    WorkUnit worktask;
    State state;

    Timer work_timer;
};

void appInit(Application *app);
void appService(Application *app);
void appUsbDataReceived(Application *app);

#endif /* APPLICATION_H_ */
