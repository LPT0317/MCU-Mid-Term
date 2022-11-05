/*
 * timer_interrupt.h
 *
 *  Created on: Nov 3, 2022
 *      Author: lephu
 */

#ifndef INC_TIMER_INTERRUPT_H_
#define INC_TIMER_INTERRUPT_H_

/* Include -----*/
#include "global.h"

/* Define -----*/
//Long press timer
#define AUTO_DEC_TIMER 0
#define BLINK_TIMER 1

/* Function -----*/
//Set timer for counter[index]
void setTimer(int duration, int index);

//Check if flag[index] == 1
int isTimerOut(int index);

//Run Timer
void timerRun(void);

#endif /* INC_TIMER_INTERRUPT_H_ */
