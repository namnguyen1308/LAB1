/*
 * ex5.c
 *
 *  Created on: Sep 19, 2024
 *      Author: NAM NGUYEN
 */

#include "ex5.h"
#include "string.h"
#include "main.h"
  uint8_t segment_data[10] = {
        0xC0,  // 0: 1100 0000 (a,b,c,d,e,f - tắt các đoạn LED tương ứng)
        0xF9,  // 1: 1111 1001 (b,c)
        0xA4,  // 2: 1010 0100 (a,b,d,e,g)
        0xB0,  // 3: 1011 0000 (a,b,c,d,g)
        0x99,  // 4: 1001 1001 (b,c,f,g)
        0x92,  // 5: 1001 0010 (a,c,d,f,g)
        0x82,  // 6: 1000 0010 (a,c,d,e,f,g)
        0xF8,  // 7: 1111 1000 (a,b,c)
        0x80,  // 8: 1000 0000 (a,b,c,d,e,f,g)
        0x90   // 9: 1001 0000 (a,b,c,d,f,g)
    };
void display7SEG(int num) {
	if (num < 0 || num > 9) return;
    // Đặt giá trị các chân PB0-PB6 (LED1 đến LED7) tương ứng với số num
    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, (segment_data[num] & 0x01) ? SET : RESET);  // LED1
    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, (segment_data[num] & 0x02) ? SET : RESET);  // LED2
    HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, (segment_data[num] & 0x04) ? SET : RESET);  // LED3
    HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, (segment_data[num] & 0x08) ? SET : RESET);  // LED4
    HAL_GPIO_WritePin(LED5_GPIO_Port, LED5_Pin, (segment_data[num] & 0x10) ? SET : RESET);  // LED5
    HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, (segment_data[num] & 0x20) ? SET : RESET);  // LED6
    HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, (segment_data[num] & 0x40) ? SET : RESET);  // LED7
}
void displaySecond7SEG(int num) {
	if (num < 0 || num > 9) return;
	// Đặt giá trị các chân PB7-PB13 (LED11 đến LED77) tương ứng với số num
	HAL_GPIO_WritePin(LED11_GPIO_Port, LED11_Pin, (segment_data[num] & 0x01) ? SET : RESET);  // LED11
	HAL_GPIO_WritePin(LED22_GPIO_Port, LED22_Pin, (segment_data[num] & 0x02) ? SET : RESET);  // LED22
	HAL_GPIO_WritePin(LED33_GPIO_Port, LED33_Pin, (segment_data[num] & 0x04) ? SET : RESET);  // LED33
	HAL_GPIO_WritePin(LED44_GPIO_Port, LED44_Pin, (segment_data[num] & 0x08) ? SET : RESET);  // LED44
	HAL_GPIO_WritePin(LED55_GPIO_Port, LED55_Pin, (segment_data[num] & 0x10) ? SET : RESET);  // LED55
	HAL_GPIO_WritePin(LED66_GPIO_Port, LED66_Pin, (segment_data[num] & 0x20) ? SET : RESET);  // LED66
	HAL_GPIO_WritePin(LED77_GPIO_Port, LED77_Pin, (segment_data[num] & 0x40) ? SET : RESET);  // LED77
}
void trafficLightControl() {
    // Giai đoạn 1: Đèn đỏ tuyến 1 (5 giây), đèn xanh tuyến 2 (2 giây) và đèn vàng tuyến 2 (3 giây)
    HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, SET);     // Bật đèn đỏ tuyến 1
    HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, RESET); // Tắt đèn vàng tuyến 1
    HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);  // Tắt đèn xanh tuyến 1

    HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, RESET);   // Tắt đèn đỏ tuyến 2
    HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, RESET); // Tắt đèn vàng tuyến 2
    HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, SET);    // Bật đèn xanh tuyến 2

    for (int i = 5; i > 2; i--) {
        display7SEG(i);          // Hiển thị số đếm ngược cho tuyến đường 1
        displaySecond7SEG(i - 2);    // Hiển thị số đếm ngược cho tuyến đường 2 (3 giây đèn xanh)
        HAL_Delay(1000);  // Đợi 1 giây
    }

    // Giai đoạn 2: Đèn vàng tuyến 2 (2 giây), tuyến đường 1 tiếp tục đèn đỏ
    HAL_GPIO_WritePin(LED_GREEN2_GPIO_Port, LED_GREEN2_Pin, RESET);   // Tắt đèn xanh tuyến 2
    HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, SET);    // Bật đèn vàng tuyến 2
    for (int i = 2; i > 0; i--) {
        display7SEG(i);          // Hiển thị số đếm ngược cho tuyến đường 1
        displaySecond7SEG(i);    // Hiển thị số đếm ngược cho tuyến đường 2 (3 giây đèn vàng)
        HAL_Delay(1000);  // Đợi 1 giây
    }

    // Giai đoạn 3: Đèn xanh tuyến 1 (3 giây), đèn đỏ tuyến 2 (5 giây)
    HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, RESET);   // Tắt đèn đỏ tuyến 1
    HAL_GPIO_WritePin( LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, SET);   // Bật đèn xanh tuyến 1

    HAL_GPIO_WritePin(LED_YELLOW2_GPIO_Port, LED_YELLOW2_Pin, RESET); // Tắt đèn vàng tuyến 2
    HAL_GPIO_WritePin(LED_RED2_GPIO_Port, LED_RED2_Pin, SET);     // Bật đèn đỏ tuyến 2

    for (int i = 3; i > 0; i--) {
        display7SEG(i);          // Hiển thị số đếm ngược cho tuyến đường 1 (2 giây đèn xanh)
        displaySecond7SEG(5 - i);    // Hiển thị số đếm ngược cho tuyến đường 2 (5 giây đèn đỏ)
        HAL_Delay(1000);  // Đợi 1 giây
    }

    // Giai đoạn 4: Đèn vàng tuyến 1 (2 giây), đèn đỏ tuyến 2 (5 giây)
    HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, RESET);  // Tắt đèn xanh tuyến 1
    HAL_GPIO_WritePin(LED_YELLOW1_GPIO_Port, LED_YELLOW1_Pin, SET);   // Bật đèn vàng tuyến 1

    for (int i = 2; i > 0; i--) {
        display7SEG(i);          // Hiển thị số đếm ngược cho tuyến đường 1 (3 giây đèn vàng)
        displaySecond7SEG(5 - i);    // Hiển thị số đếm ngược cho tuyến đường 2 (5 giây đèn đỏ)
        HAL_Delay(1000);  // Đợi 1 giây
    }
}

