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

/* Function -----*/
/* Button reading and debounce */
//debounce button
void getKeyInput();

/* Check button is pressed or not
 * Check button[index]
 */
int isButtonPressed(int index);

#endif /* INC_BUTTON_H_ */
