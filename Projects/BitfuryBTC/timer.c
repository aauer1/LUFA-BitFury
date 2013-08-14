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

#include "timer.h"
#include "clock.h"

//------------------------------------------------------------------------------
void timerSet(Timer *t, uint32_t interval)
{
    t->active = 1;
    t->start = clockGetTime();
    t->interval = interval;
}

//------------------------------------------------------------------------------
void timerStop(Timer *t)
{
    t->active = 0;
}

//------------------------------------------------------------------------------
void timerReset(Timer *t)
{
    t->active = 1;
    t->start += t->interval;
}

//------------------------------------------------------------------------------
void timerRestart(Timer *t)
{
    t->active = 1;
    t->start = clockGetTime();
}

//------------------------------------------------------------------------------
unsigned char timerExpired(Timer *t)
{
    uint32_t time = clockGetTime();

    if(!t->active)
    {
        return 0;
    }
    
    if(time > t->start)
    {
        uint32_t diff = (time - t->start);
        if(diff > t->interval)
        {
            t->active = 0;
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if(((~t->start) + time + 1) >= t->interval)
        {
            t->active = 0;
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
