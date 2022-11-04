/*
 * led_control.h
 *
 *  Created on: Nov 3, 2022
 *      Author: lephu
 */

#ifndef INC_LED_CONTROL_H_
#define INC_LED_CONTROL_H_

/* Include -----*/
#include "main.h"
#include "global.h"

/* Function -----*/
//open LED index
void openLED(int index);
//display 7 SEGMENT LED
void display7SEG(int num);

#endif /* INC_LED_CONTROL_H_ */
