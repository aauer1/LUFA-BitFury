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

#include <avr/io.h>
#include <util/delay.h>

#include <string.h>

#include "spidev.h"
#include "bitfury.h"

#include "main.h"

#define BITFURY_REFRESH_DELAY 100
#define BITFURY_DETECT_TRIES 3000 / BITFURY_REFRESH_DELAY

// 0 .... 31 bit
// 1000 0011 0101 0110 1001 1010 1100 0111

// 1100 0001 0110 1010 0101 1001 1110 0011
// C16A59E3

uint8_t enaconf[4] = { 0xc1, 0x6a, 0x59, 0xe3 };
uint8_t disconf[4] = { 0, 0, 0, 0 };

#define FIRST_BASE 61
#define SECOND_BASE 4
char counters[16] = { 64, 64,
        SECOND_BASE, SECOND_BASE+4, SECOND_BASE+2, SECOND_BASE+2+16, SECOND_BASE, SECOND_BASE+1,
        (FIRST_BASE)%65,  (FIRST_BASE+1)%65,  (FIRST_BASE+3)%65, (FIRST_BASE+3+16)%65, (FIRST_BASE+4)%65, (FIRST_BASE+4+4)%65, (FIRST_BASE+3+3)%65, (FIRST_BASE+3+1+3)%65};

/* Oscillator setup variants (maybe more), values inside of chip ANDed to not allow by programming errors work it at higher speeds  */
/* WARNING! no chip temperature control limits, etc. It may self-fry and make fried chips with great ease :-) So if trying to overclock */
/* Do not place chip near flammable objects, provide adequate power protection and better wear eye protection ! */
/* Thermal runaway in this case could produce nice flames of chippy fries */

// Thermometer code from left to right - more ones ==> faster clock!
//uint8_t osc6[8] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x00 };
uint8_t osc6[8] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x00 };


#define rotrFixed(x,y) (((x) >> (y)) | ((x) << (32-(y))))
#define s0(x) (rotrFixed(x,7)^rotrFixed(x,18)^(x>>3))
#define s1(x) (rotrFixed(x,17)^rotrFixed(x,19)^(x>>10))
#define Ch(x,y,z) (z^(x&(y^z)))
#define Maj(x,y,z) (y^((x^y)&(y^z)))
#define S0(x) (rotrFixed(x,2)^rotrFixed(x,13)^rotrFixed(x,22))
#define S1(x) (rotrFixed(x,6)^rotrFixed(x,11)^rotrFixed(x,25))

static uint32_t oldbuf[17];
static uint8_t  switched = 0;

/* SHA256 CONSTANTS */
static uint32_t SHA_K[3] = { 0x428a2f98, 0x71374491, 0xb5c0fbcf };

//------------------------------------------------------------------------------
/* Configuration registers - control oscillators and such stuff.
 * PROGRAMMED when magic number is matches,
 * UNPROGRAMMED (default) otherwise
 */
static void asicConfigReg(uint16_t cfgreg, uint8_t ena)
{
    if (ena)
        spiEmitData(0x7000+cfgreg*32, (void*)enaconf, 4);
    else
        spiEmitData(0x7000+cfgreg*32, (void*)disconf, 4);
}

//------------------------------------------------------------------------------
void asicPrecompute(WorkUnit *task)
{
    uint32_t a,b,c,d,e,f,g,h, ne, na,  i;

    a = task->midstate[0];
    b = task->midstate[1];
    c = task->midstate[2];
    d = task->midstate[3];
    e = task->midstate[4];
    f = task->midstate[5];
    g = task->midstate[6];
    h = task->midstate[7];

    for (i = 0; i < 3; i++)
    {
            ne = task->data[i] + SHA_K[i] + h + Ch(e,f,g) + S1(e) + d;
            na = task->data[i] + SHA_K[i] + h + Ch(e,f,g) + S1(e) + S0(a) + Maj(a,b,c);
            d = c; c = b; b = a; a = na;
            h = g; g = f; f = e; e = ne;
    }

    task->junk[7] = a;
    task->junk[6] = b;
    task->junk[5] = c;
    task->junk[4] = d;
    task->junk[3] = e;
    task->junk[2] = f;
    task->junk[1] = g;
    task->junk[0] = h;
}

//------------------------------------------------------------------------------
void asicInit(void)
{
    uint8_t i=0;
    SPCR = _BV(SPE) | _BV(MSTR) | _BV(SPR0) | _BV(SPR1);
    for(i=0; i<17; i++)
        oldbuf[i] = 0;
}

//------------------------------------------------------------------------------
void asicReset(void)
{
    unsigned char i=0;

    SPCR &= ~_BV(SPE);

    DDRB  |= _BV(SPI_SCK) | _BV(SPI_MOSI);
    PORTB |= _BV(SPI_SCK);
    for(i=0; i<32; i++)
    {
        PORTB ^= _BV(SPI_MOSI);
        _delay_us(1);
    }
    PORTB &= ~_BV(SPI_SCK);
    PORTB &= ~_BV(SPI_MOSI);

    _delay_ms(1);

    SPCR = _BV(SPE) | _BV(MSTR) | _BV(SPR0) | _BV(SPR1);
}

//------------------------------------------------------------------------------
uint8_t asicInitChip(WorkUnit *task)
{
    uint32_t w;
    uint32_t old = 0;
    uint8_t i;
    uint8_t ret = 0;

    asicPrecompute(task);

    spiClearBuffer();
    spiEmitBreak();   // 1
    spiEmitFasync(0); // 0

    // Program internal on-die slow oscillator frequency
    spiEmitData(0x6000, (void*)osc6, 8); // 11
    asicConfigReg(7,0); asicConfigReg(8,0); asicConfigReg(9,0); asicConfigReg(10,0); asicConfigReg(11,0); // 42
    asicConfigReg(6,1); // 7
    // Enable slow oscillator
    asicConfigReg(4,1); // 7
    asicConfigReg(1,0); asicConfigReg(2,0); asicConfigReg(3,0); // 21

    spiEmitData(0x0100, (void*)counters, 16); // 19

    // 108 Bytes
    spiTxRx(spiGetBuffer(), spiGetBufferSize());

    /* Prepare internal buffers */
    /* PREPARE BUFFERS (INITIAL PROGRAMMING) */
    spiClearBuffer();
    spiEmitDataStart(0x1000, 16*4); // 67
    for(i=0; i<16; i++)
    {
        if(i==3)
            w = 0xffffffff;
        else if(i == 4)
            w = 0x80000000;
        else if(i == 15)
            w = 0x00000280;
        else
            w = 0;
        spiEmitBufferReverse((uint8_t *)&w, 4);
    }
    spiTxRx(spiGetBuffer(), spiGetBufferSize());

    spiClearBuffer();
    spiEmitDataStart(0x1400, 8*4);      // 35
    for(i=0; i<8; i++)
    {
        if(i==0)
            w = 0x80000000;
        else if(i == 7)
            w = 0x00000100;
        else
            w = 0;
        spiEmitBufferReverse((uint8_t *)&w, 4);
    }
    spiTxRx(spiGetBuffer(), spiGetBufferSize());

    spiClearBuffer();
    spiEmitDataStart(0x1900, 8*4);      // 35
    for(i=0; i<8; i++)
    {
        if(i==0)
            w = 0x80000000;
        else if(i == 7)
            w = 0x00000100;
        else
            w = 0;
        spiEmitBufferReverse((uint8_t *)&w, 4);
    }

    // Prepare MS and W buffers!
    //spiEmitData(0x3000, (uint8_t *)task, 19*4); // 79

    // 216 Bytes(uint8_t *
    spiTxRx(spiGetBuffer(), spiGetBufferSize());

    // Send work data
    for(i=0; i<30; i++)
    {
        spiClearBuffer();
        spiEmitBreak();
        spiEmitData(0x3000, (uint8_t *)task, 19*4);
        spiTxRx(spiGetBuffer(), spiGetBufferSize());

        uint32_t *buffer = (uint32_t *)(spiGetBuffer() + 4);
        if(i && buffer[16] != old)
        {
            ret = 1;
            break;
        }
        {
            uint8_t j=0;
            for(j=0; j<100; j++)
                _delay_ms(2);
        }

        old = buffer[16];
    }

    return ret;
}

//------------------------------------------------------------------------------
void asicSendHashData(WorkUnit *task)
{
    uint32_t *buffer;
    static uint8_t second_run = 0;

    asicReset();

    spiClearBuffer();
    spiEmitBreak();
    spiEmitData(0x3000, (uint8_t *)task, 19*4);
    spiTxRx(spiGetBuffer(), spiGetBufferSize());

    buffer = (uint32_t *)(spiGetBuffer() + 4);
    switched = (oldbuf[16] != buffer[16]);

    task->num_results = 0;
    if(second_run && switched)
    {
        uint8_t i=0;
        for(i=0; i<16; i++)
        {
            if(oldbuf[i] != buffer[i])
            {
                task->results[task->num_results] = buffer[i];
                task->num_results++;
            }
            oldbuf[i] = buffer[i];
        }
    }

    oldbuf[16] = buffer[16];

    second_run = 1;
}

//------------------------------------------------------------------------------
uint8_t asicGetSwitched(void)
{
    return switched;
}

