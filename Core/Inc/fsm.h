/*
 * fsm.h
 *
 *  Created on: Nov 5, 2022
 *      Author: lephu
 */

#ifndef INC_FSM_H_
#define INC_FSM_H_

/* Include -----*/
#include "global.h"
#include "button.h"
#include "led_control.h"
#include "timer_interrupt.h"

/* Function -----*/
//Run state machine
void fsm_simple_buttons_run(void);
void fsm_led_blinky(void);

#endif /* INC_FSM_H_ */
