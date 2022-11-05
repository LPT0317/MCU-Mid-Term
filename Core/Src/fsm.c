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
#define IDLE_STATE 1
#define RESET_STATE 2
#define INC_STATE 3
#define DEC_STATE 4
#define AUTO_INC_STATE 11
#define AUTO_DEC_STATE 12

//Time increase
#define AUTO_TIME 1000
/* Init -----*/
//counter for FSM
int counter = 0;
//status of state machine
int status = INIT_STATE;

/* Function -----*/
//Increase counter
void inc_counter(void) {
  counter++;
  if(counter > 9) {
    counter = 0;
  }
}
//Decrease counter
void dec_counter(void) {
  counter--;
  if(counter < 0) {
    counter = 9;
  }
}
//Run state machine
void fsm_simple_buttons_run(void) {
  switch(status) {
  case INIT_STATE:
    counter = 0;
    status = IDLE_STATE;
    break;
  case IDLE_STATE:
	display7SEG(counter);
    if(isButtonPressed(RESET_BUTTON) == 1) {
      status = RESET_STATE;
    }
    if(isButtonPressed(INC_BUTTON) == 1) {
      status = INC_STATE;
    }
    if(isButtonPressed(DEC_BUTTON) == 1) {
      status = DEC_STATE;
    }
    break;
  case RESET_STATE:
	counter = 0;
	status = IDLE_STATE;
	break;
  case INC_STATE:
	inc_counter();
	status = IDLE_STATE;
	break;
  case DEC_STATE:
	dec_counter();
	status = IDLE_STATE;
	break;
  }
}
