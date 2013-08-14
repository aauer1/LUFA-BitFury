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

#ifndef BITFURY_H_
#define BITFURY_H_

#include "application.h"

#define SPI_SCK         1
#define SPI_MOSI        2
#define SPI_MISO        3

void asicInit(void);
void asicReset(void);
uint8_t asicInitChip(WorkUnit *task);
void asicSendHashData(WorkUnit *task);
uint8_t asicGetSwitched(void);

void asicPrecompute(WorkUnit *task);

#endif /* BITFURY_H_ */
