/*
 * led_control.c
 *
 *  Created on: Nov 3, 2022
 *      Author: lephu
 */

/* Include -----*/
#include "led_control.h"

/* Init -----*/
//LED Pin
uint16_t LED[NO_LED] = {LED1_Pin, LED2_Pin, LED3_Pin};
/* Register for num 0 to 9 for display 7SEG
 * num[0] = 0x003f
 * set a,b,c,d,e,f to 0 and g to 1
 */
uint16_t SEG7[10] = {0x003f, 0x0006, 0x005b, 0x004f, 0x0066,
		             0x006d, 0x007d, 0x0007, 0x007f, 0x006f};

/* Function -----*/
//open LED index
void openLED(int index) {
  if(checkIndex(index, NO_LED)) {
    HAL_GPIO_WritePin(GPIOA, LED[index], RESET);
  }
}
//display 7 SEGMENT LED
void display7SEG(int num) {
  if(checkIndex(num, 10)) {
    HAL_GPIO_WritePin(GPIOB, SEG7[num], RESET);
  }
}
