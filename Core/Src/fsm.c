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
//State for counter FSM
#define IDLE_STATE 1
#define RESET_STATE 2
#define INC_STATE 3
#define DEC_STATE 4
#define AUTO_DEC_STATE 11
//State for led blinky FSM
#define ON_STATE 101
#define OFF_STATE 102

//Time
#define AUTO_TIME 10000
#define DEC_TIME 500
#define BLINK_TIME 500
/* Init -----*/
//counter for FSM
int counter = 0;
//status of counter FSM
int status = INIT_STATE;
//status of led blinky FSM
int led_status = INIT_STATE;

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
//Auto decrease counter
void auto_dec(void) {
  if(counter > 0) {
    counter--;
  }
}
//Run state machine
void fsm_simple_buttons_run(void) {
  switch(status) {
  case INIT_STATE:
    counter = 0;
    status = IDLE_STATE;
    setTimer(AUTO_TIME, AUTO_DEC_TIMER);
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
    if(isTimerOut(AUTO_DEC_TIMER) == 1) {
      status = AUTO_DEC_STATE;
      auto_dec();
      setTimer(DEC_TIME, AUTO_DEC_TIMER);
    }
    break;
  case RESET_STATE:
	counter = 0;
	status = IDLE_STATE;
	setTimer(AUTO_TIME, AUTO_DEC_TIMER);
	break;
  case INC_STATE:
	inc_counter();
	status = IDLE_STATE;
	setTimer(AUTO_TIME, AUTO_DEC_TIMER);
	break;
  case DEC_STATE:
	dec_counter();
	status = IDLE_STATE;
	setTimer(AUTO_TIME, AUTO_DEC_TIMER);
	break;
  case AUTO_DEC_STATE:
	display7SEG(counter);
	if(isTimerOut(AUTO_DEC_TIMER) == 1) {
	  auto_dec();
	  status = AUTO_DEC_STATE;
	  setTimer(DEC_TIME, AUTO_DEC_TIMER);
	}
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
  }
}

void fsm_led_blinky(void) {
  switch(led_status) {
  case INIT_STATE:
	led_status = ON_STATE;
	setTimer(BLINK_TIME, BLINK_TIMER);
    break;
  case ON_STATE:
	LED_on(LED_RED);
	if(isTimerOut(BLINK_TIMER) == 1) {
	  led_status = OFF_STATE;
	  setTimer(BLINK_TIME, BLINK_TIMER);
	}
	break;
  case OFF_STATE:
	LED_off(LED_RED);
	if(isTimerOut(BLINK_TIMER) == 1) {
	  led_status = ON_STATE;
	  setTimer(BLINK_TIME, BLINK_TIMER);
	}
	break;
  }
}
