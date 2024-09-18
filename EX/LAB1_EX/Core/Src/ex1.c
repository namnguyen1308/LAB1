/*
 * ex1.c
 *
 *  Created on: Sep 18, 2024
 *      Author: NAM NGUYEN
 */
#include "ex1.h"
void System_init_Lab1(){
	timer_init();
	setTimer2(1000);
	setTimer3(3000);// timer traffic begin
	setTimer4(1000);// set time_step 7 seg = 1s
}
bool bool_red = 1;
bool bool_yellow = 0;

void Exercise_1(){
	if(flag_timer2){
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, bool_red);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, bool_yellow);
		bool_red = !bool_red;
		bool_yellow = !bool_yellow;

		flag_timer2 = 0;
	}
}
