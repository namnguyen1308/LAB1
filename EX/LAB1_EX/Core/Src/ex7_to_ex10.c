/*
 * ex7_to_ex10.c
 *
 *  Created on: Sep 19, 2024
 *      Author: NAM NGUYEN
 */

#include "ex7_to_ex10.h"
#include "main.h"
void clearAllClock() {
    HAL_GPIO_WritePin(GPIOA, LED_0_Pin|LED_1_Pin|LED_2_Pin|LED_3_Pin
                            |LED_4_Pin|LED_5_Pin|LED_6_Pin|LED_7_Pin
                            |LED_8_Pin|LED_9_Pin|LED_10_Pin|LED_11_Pin, RESET);
}
void clearNumberOnClock(int num) {
	switch(num) {
	        case 0: HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, RESET); break;
	        case 1: HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, RESET); break;
	        case 2: HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, RESET); break;
	        case 3: HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, RESET); break;
	        case 4: HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, RESET); break;
	        case 5: HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, RESET); break;
	        case 6: HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, RESET); break;
	        case 7: HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, RESET); break;
	        case 8: HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, RESET); break;
	        case 9: HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, RESET); break;
	        case 10: HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, RESET); break;
	        case 11: HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, RESET); break;
	        default:
	        break;
	    }
}
// Hàm bật một LED tại vị trí num
void setNumberOnClock(int num) {
    switch(num) {
        case 0: HAL_GPIO_WritePin(LED_10_GPIO_Port, LED_10_Pin, SET); break;
        case 1: HAL_GPIO_WritePin(LED_11_GPIO_Port, LED_11_Pin, SET); break;
        case 2: HAL_GPIO_WritePin(LED_0_GPIO_Port, LED_0_Pin, SET); break;
        case 3: HAL_GPIO_WritePin(LED_1_GPIO_Port, LED_1_Pin, SET); break;
        case 4: HAL_GPIO_WritePin(LED_2_GPIO_Port, LED_2_Pin, SET); break;
        case 5: HAL_GPIO_WritePin(LED_3_GPIO_Port, LED_3_Pin, SET); break;
        case 6: HAL_GPIO_WritePin(LED_4_GPIO_Port, LED_4_Pin, SET); break;
        case 7: HAL_GPIO_WritePin(LED_5_GPIO_Port, LED_5_Pin, SET); break;
        case 8: HAL_GPIO_WritePin(LED_6_GPIO_Port, LED_6_Pin, SET); break;
        case 9: HAL_GPIO_WritePin(LED_7_GPIO_Port, LED_7_Pin, SET); break;
        case 10: HAL_GPIO_WritePin(LED_8_GPIO_Port, LED_8_Pin, SET); break;
        case 11: HAL_GPIO_WritePin(LED_9_GPIO_Port, LED_9_Pin, SET); break;
        default:
        break;
    }
}
