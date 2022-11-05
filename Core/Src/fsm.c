/*
 * fsm.c
 *
 *  Created on: Nov 5, 2022
 *      Author: lephu
 */

/* Include -----*/
#include "fsm.h"

/* Define -----*/
//Define state
#define INIT_STATE 0
#define DISPLAY_STATE 1
#define RESET_STATE 2
#define INC_STATE 3
#define DEC_STATE 4

/* Init -----*/
//status of state machine
int status = INIT_STATE;

/* Function -----*/
//Run state machine
void fsm_simple_buttons_run(void) {
  switch(status) {
  case INIT_STATE:
    counter = 0;
    status = DISPLAY_STATE;
    break;
  case DISPLAY_STATE:
	display7SEG(counter);
    if(isButtonPressed(RESET_BUTTON) == 1) {
      status = RESET_STATE;
      counter = 0;
    }
    if(isButtonPressed(INC_BUTTON) == 1) {
      status = INC_STATE;
      counter++;
    }
    if(isButtonPressed(DEC_BUTTON) == 1) {
      status = DEC_STATE;
      counter--;
    }
    break;
  case RESET_STATE:
	status = DISPLAY_STATE;
	break;
  case INC_STATE:
	if(counter > 9) {
	  counter = 0;
	}
	status = DISPLAY_STATE;
	break;
  case DEC_STATE:
	if(counter < 0) {
	  counter = 9;
	}
	status = DISPLAY_STATE;
	break;
  }
}
