/*
 * button.c
 *
 *  Created on: Nov 3, 2022
 *      Author: lephu
 */

/* Include -----*/
#include "button.h"

/* Define -----*/
/* Pull-up button */
#define PRESSED_STATE 0
#define NORMAL_STATE 1

/* Init -----*/
//Button Pin
uint16_t BUTTON[NO_BUTTON] = {RESET_Pin, INC_Pin, DEC_Pin};
/* Flag for button
 * Check button state
 * Array with size = NUM_BUTTON
 * example button_flag[0]: check flag on button 0;
 */
int button_flag[NO_BUTTON] = {0};
/* Debounce var
 * Save the past state of button
 * debounce 3 time
 */
int KeyReg0[NO_BUTTON] = {NORMAL_STATE};
int KeyReg1[NO_BUTTON] = {NORMAL_STATE};
int KeyReg2[NO_BUTTON] = {NORMAL_STATE};
/* Save last state of button */
int KeyReg3[NO_BUTTON] = {NORMAL_STATE};
/* Set time for debounce */
int TimeOutForKeyPress[NO_BUTTON] = {300};

/* Function -----*/
/* Button reading and debounce */
//debounce button
void getKeyInput() {
  for(int i = 0; i < NO_BUTTON; i++) {
    KeyReg2[i] = KeyReg1[i];
    KeyReg1[i] = KeyReg0[i];
    KeyReg0[i] = HAL_GPIO_ReadPin(GPIOA, BUTTON[i]);
    if((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])) {
      if(KeyReg3[i] != KeyReg2[i]) {
    	KeyReg3[i] = KeyReg2[i];
    	if(KeyReg3[i] == PRESSED_STATE) {
    	  TimeOutForKeyPress[i] = 300;
    	  button_flag[i] = 1;
    	}
      }
      else {
        TimeOutForKeyPress[i]--;
        if(TimeOutForKeyPress[i] == 0) {
          KeyReg3[i] = NORMAL_STATE;
        }
      }
    }
  }
}

/* Check button is pressed or not
 * Check button[index]
 */
int isButtonPressed(int index) {
  if(checkIndex(index, NO_BUTTON)) {
    if(button_flag[index] == 1) {
      button_flag[index] = 0;
      return 1;
    }
  }
  return 0;
}
