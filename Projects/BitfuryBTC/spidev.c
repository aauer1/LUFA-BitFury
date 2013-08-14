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
#include <string.h>
#include <stdio.h>

#include "spidev.h"

//------------------------------------------------------------------------------
#define SPIMAXSZ 128
static uint8_t spibuf[SPIMAXSZ];
static uint16_t spibufsz;

//------------------------------------------------------------------------------
void spiClearBuffer(void)
{
    spibufsz = 0;
}

//------------------------------------------------------------------------------
uint8_t spiGetBufferSize(void)
{
    return spibufsz;
}

//------------------------------------------------------------------------------
uint8_t *spiGetBuffer(void)
{
    return spibuf;
}

//------------------------------------------------------------------------------
void spiEmitBufferReverse(const uint8_t *str, uint16_t sz)
{
    uint16_t i;
    if (spibufsz + sz >= SPIMAXSZ)
    {
        printf("SPI overflow");
        return;
    }

    for (i = 0; i < sz; i++)
    {
        // Reverse bit order in each byte!
        uint8_t p = str[i];
        p = ((p & 0xaa)>>1) | ((p & 0x55) << 1);
        p = ((p & 0xcc)>>2) | ((p & 0x33) << 2);
        p = ((p & 0xf0)>>4) | ((p & 0x0f) << 4);
        spibuf[spibufsz+i] = p;
    }
    spibufsz += sz;
}

//------------------------------------------------------------------------------
void spiEmitBuffer(const uint8_t *str, uint16_t sz)
{
    if(spibufsz + sz >= SPIMAXSZ)
    {
        printf("SPI overflow");
        return;
    }

    memcpy(&spibuf[spibufsz], str, sz);
    spibufsz += sz;
}

//------------------------------------------------------------------------------
void spiEmitBreak(void)
{
    uint8_t temp[] = {0x04};
    spiEmitBuffer(temp, 1);
}

//------------------------------------------------------------------------------
void spiEmitFsync(void)
{
    uint8_t temp[] = {0x06};
    spiEmitBuffer(temp, 1);
}

//------------------------------------------------------------------------------
void spiEmitFasync(uint8_t n)
{
    uint8_t temp[] = {0x05};
    uint16_t i;
    for (i = 0; i < n; i++)
    {
        spiEmitBuffer(temp, 1);
    }
}

//------------------------------------------------------------------------------
void spiEmitData(uint16_t addr, const uint8_t *buf, uint8_t len)
{
    uint8_t otmp[3];
    if (len < 4 || len > 128)
        return;

    len /= 4;
    otmp[0] = (len - 1) | 0xE0;
    otmp[1] = (addr >> 8)&0xFF; otmp[2] = addr & 0xFF;
    spiEmitBuffer(otmp, 3);
    spiEmitBufferReverse(buf, len*4);
}

//------------------------------------------------------------------------------
void spiEmitDataStart(uint16_t addr, uint8_t len)
{
    uint8_t otmp[3];
    if (len < 4 || len > 128)
        return;

    len /= 4;
    otmp[0] = (len - 1) | 0xE0;
    otmp[1] = (addr >> 8)&0xFF;
    otmp[2] = addr & 0xFF;
    spiEmitBuffer(otmp, 3);
}

//------------------------------------------------------------------------------
uint8_t spiTxRx(uint8_t *buf, uint16_t bufsz)
{
    uint16_t i=0;

    for(i=0; i<bufsz; i++)
    {
        SPDR = buf[i];
        loop_until_bit_is_set(SPSR, SPIF);
        buf[i] = SPDR;
    }

    return 0;
}
