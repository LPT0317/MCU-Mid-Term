/*
 * timer_interrupt.c
 *
 *  Created on: Nov 3, 2022
 *      Author: lephu
 */

/* Include -----*/
#include "timer_interrupt.h"

/* Init -----*/
//Counter for all timer
int counter[NO_TIMER] = {0};
//Flag for all timer
int flag[NO_TIMER] = {0};

/* Function -----*/
//Set timer for counter[index]
void setTimer(int duration, int index) {
  if(checkIndex(index, NO_TIMER) == 1) {
    counter[index] = duration / TIME_CYCLE;
    flag[index] = 0;
  }
}

//Check if flag[index] == 1
int isTimerOut(int index) {
  if(checkIndex(index, NO_TIMER) == 1) {
    if(flag[index] == 1) {
      flag[index] = 0;
      return 1;
    }
  }
  return 0;
}

//Run Timer
void timerRun(void) {
  for(int i = 0; i < NO_TIMER; i++) {
    if(counter[i] > 0) {
      counter[i]--;
      if(counter[i] <= 0) {
        flag[i] = 1;
        counter[i] = 0;
      }
    }
  }
}
