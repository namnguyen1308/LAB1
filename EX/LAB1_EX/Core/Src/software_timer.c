/*
 * software_timer.c
 *
 *  Created on: Sep 18, 2024
 *      Author: NAM NGUYEN
 */


#include "software_timer.h"


#define TIMER_CYCLE_2 1
#define TIMER_CYCLE_3 1
#define TIMER_CYCLE_4 1
#define TIMER_CYCLE_5 1

uint16_t flag_timer2 = 0;
uint16_t timer2_counter = 0;
uint16_t timer2_MUL = 0;

uint16_t flag_timer3 = 0;
uint16_t timer3_counter = 0;
uint16_t timer3_MUL = 0;

uint16_t flag_timer4 = 0;
uint16_t timer4_counter = 0;
uint16_t timer4_MUL = 0;

uint16_t flag_timer5 = 0;
uint16_t timer5_counter = 0;
uint16_t timer5_MUL = 0;



void timer_init(){
	HAL_TIM_Base_Start_IT(&htim2);
}
/////////////////////////////////////////////////////////////
void setTimer2(uint16_t duration){
	timer2_MUL = duration/TIMER_CYCLE_2;
	flag_timer2 = 0;
	timer2_counter = timer2_MUL;
}

void timer2_run(){
	if(timer2_counter > 0){
		timer2_counter--;
		if(timer2_counter <= 0){
			flag_timer2 = 1;
			timer2_counter = timer2_MUL;
		}
	}

}
////////////////////////////////////////////////////////////////
void setTimer3(uint16_t duration){
	timer3_MUL = duration/TIMER_CYCLE_3;
	flag_timer3 = 0;
	timer3_counter = timer3_MUL;
}

void timer3_run(){
	if(timer3_counter > 0){
		timer3_counter--;
		if(timer3_counter <= 0){
			flag_timer3 = 1;
			timer3_counter = timer3_MUL;
		}
	}

}
///////////////////////////////////////////////////////////////
void setTimer4(uint16_t duration){
	timer4_MUL = duration/TIMER_CYCLE_4;
	flag_timer4 = 0;
	timer4_counter = timer4_MUL;
}

void timer4_run(){
	if(timer4_counter > 0){
		timer4_counter--;
		if(timer4_counter <= 0){
			flag_timer4 = 1;
			timer4_counter = timer4_MUL;
		}
	}

}
////////////////////////////////////////////////////////
void setTimer5(uint16_t duration){
	timer5_MUL = duration/TIMER_CYCLE_5;
	flag_timer5 = 0;
	timer5_counter = timer5_MUL;
}

void timer5_run(){
	if(timer5_counter > 0){
		timer5_counter--;
		if(timer5_counter <= 0){
			flag_timer5 = 1;
			timer5_counter = timer5_MUL;
		}
	}

}
///////////////////////////////////////////////////////////
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM2){
		timer2_run();
		timer3_run();
		timer4_run();
		timer5_run();
	}

}
