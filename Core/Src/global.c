/*
 * global.c
 *
 *  Created on: Nov 3, 2022
 *      Author: lephu
 */

/* Include -----*/
#include "global.h"

/* Finite state machine -----*/
//counter for FSM
int counter = 0;

/* Function -----*/
int checkIndex(int index, int max) {
  if(index >= 0 && index < max) {
	return 1;
  }
  return 0;
}
