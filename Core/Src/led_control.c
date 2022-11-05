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
uint16_t LED[NO_LED] = {LED_RED_Pin};
/* Register for num 0 to 9 for display 7SEG
 * num[0] = 0x003f
 * set a,b,c,d,e,f to 0 and g to 1
 */
uint16_t SEG7[10] = {0x003f, 0x0006, 0x005b, 0x004f, 0x0066,
		             0x006d, 0x007d, 0x0007, 0x007f, 0x006f};
uint16_t offSEG7[10] = {0x0040, 0x0079, 0x0024, 0x0030, 0x0019,
		             0x0012, 0x0002, 0x0078, 0x0000, 0x0010};

/* Function -----*/
//turn on LED index
void LED_on(int index) {
  if(checkIndex(index, NO_LED)) {
    HAL_GPIO_WritePin(GPIOA, LED[index], RESET);
  }
}
//turn off LED[index]
void LED_off(int index) {
  if(checkIndex(index, NO_LED)) {
	HAL_GPIO_WritePin(GPIOA, LED[index], SET);
  }
}
//display 7 SEGMENT LED
void display7SEG(int num) {
  if(checkIndex(num, 10)) {
	HAL_GPIO_WritePin(GPIOB, offSEG7[num], SET);
    HAL_GPIO_WritePin(GPIOB, SEG7[num], RESET);
  }
}
