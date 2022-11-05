/*
 * global.h
 *
 *  Created on: Nov 3, 2022
 *      Author: lephu
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

/* Include -----*/
#include "main.h"

/* Timer -----*/
//Timer Cycle T = 10ms
#define TIME_CYCLE 10
//Time unit 1s = 1000ms
#define TIME_UNIT 1000
//Number of timer
#define NO_TIMER 1

/* LED -----*/
//Number of LED
#define NO_LED 1

/* Button -----*/
//Number of button
#define NO_BUTTON 3

/* Finite state machine -----*/
//counter for FSM
extern int counter;

/* Check function */
//Check index (0 <= Index < max)
int checkIndex(int index, int max);
#endif /* INC_GLOBAL_H_ */
