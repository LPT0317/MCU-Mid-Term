/*
 * button.h
 *
 *  Created on: Nov 3, 2022
 *      Author: lephu
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

/* Include -----*/
#include "global.h"

/* Define -----*/
#define RESET_BUTTON 0
#define INC_BUTTON 1
#define DEC_BUTTON 2

/* Function -----*/
/* Button reading and debounce */
//debounce button
void getKeyInput();

/* Check button is pressed or not
 * Check button[index]
 */
int isButtonPressed(int index);

#endif /* INC_BUTTON_H_ */
