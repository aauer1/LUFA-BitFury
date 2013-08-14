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

#ifndef TIMER_H
#define TIMER_H

#include <avr/io.h>

#define timerActive(timer)         ((timer)->active)

typedef struct Timer_ Timer;

/**
 * A timer.
 *
 * This structure is used for declaring a timer. The timer must be set
 * with timer_set() before it can be used.
 *
 * \hideinitializer
 */
struct Timer_
{
    uint8_t  active;
    uint32_t start;
    uint32_t interval;
};

/**
 * Set a timer.
 *
 * This function is used to set a timer for a time sometime in the
 * future. The function timerEpired() will evaluate to true after
 * the timer has expired.
 *
 * \param t A pointer to the timer
 * \param interval The interval before the timer expires.
 *
 */
void timerSet(Timer *t, uint32_t interval);

/**
 * Stop a timer.
 *
 * This function is used to stop a timer. The function timerExpired() will
 * never evaluate to true if timerStop() has been called.
 *
 * \param t A pointer to the timer
 *
 */
void timerStop(Timer *t);

/**
 * Reset the timer with the same interval.
 *
 * This function resets the timer with the same interval that was
 * given to the timerSet() function. The start point of the interval
 * is the exact time that the timer last expired. Therefore, this
 * function will cause the timer to be stable over time, unlike the
 * timer_rester() function.
 *
 * \param t A pointer to the timer.
 *
 * \sa timer_restart()
 */
void timerReset(Timer *t);

/**
 * Restart the timer from the current point in time
 *
 * This function restarts a timer with the same interval that was
 * given to the timerSet() function. The timer will start at the
 * current time.
 *
 * \note A periodic timer will drift if this function is used to reset
 * it. For preioric timers, use the timer_reset() function instead.
 *
 * \param t A pointer to the timer.
 *
 * \sa timer_reset()
 */
void timerRestart(Timer *t);

/**
 * Check if a timer has expired.
 *
 * This function tests if a timer has expired and returns true or
 * false depending on its status.
 *
 * \param t A pointer to the timer
 *
 * \return Non-zero if the timer has expired, zero otherwise.
 *
 */
unsigned char timerExpired(Timer *t);

#endif
