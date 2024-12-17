/*
 * fsm_automatic.c
 *
 *  Created on: Nov 14, 2024
 *      Author: lenovo
 */

#include "fsm_automatic.h"
#include "software_timer.h"
#include "main.h"
#include "display_7seg.h"
#include "global.h"

/**
 * 	@brief:		All the LED of system off
 *	@param:		None
 * 	@retval:	None
 */
void allLEDoff() {
	HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin|LED_YELLOW_1_Pin|LED_GREEN_1_Pin
							|LED_RED_2_Pin|LED_YELLOW_2_Pin|LED_GREEN_2_Pin, SET);
}

/**
 * 	@brief:		Traffic light run automatically (Mode 1)
 *	@param:		None
 * 	@retval:	None
 */
void fsm_automatic() {
	switch (autoStatus) {
	case INIT:
		allLEDoff();
		autoStatus = RED_GREEN;
		count = timeGreen;
		count_auto = 99;
		break;
	case RED_GREEN:
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin|LED_GREEN_2_Pin, RESET);
		led_buffer[0] = (count + timeYellow) / 10;
		led_buffer[1] = (count + timeYellow) % 10;
		led_buffer[2] = count / 10;
		led_buffer[3] = count % 10;
		if (count_auto <= 0) {
			count_auto = 99;
			count--;
			if (count <= 0) {
				autoStatus = RED_YELLOW;
				count = timeYellow;
				allLEDoff();
			}
		}
		else {
			count_auto--;
		}
		break;
	case RED_YELLOW:
		HAL_GPIO_WritePin(GPIOA, LED_RED_1_Pin|LED_YELLOW_2_Pin, RESET);
		led_buffer[0] = count / 10;
		led_buffer[1] = count % 10;
		led_buffer[2] = count / 10;
		led_buffer[3] = count % 10;
		if (count_auto <= 0) {
			count_auto = 99;
			count--;
			if (count <= 0) {
				autoStatus = GREEN_RED;
				count = timeGreen;
				allLEDoff();
			}
		}
		else {
			count_auto--;
		}
		break;
	case GREEN_RED:
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin|LED_RED_2_Pin, RESET);
		led_buffer[0] = count / 10;
		led_buffer[1] = count % 10;
		led_buffer[2] = (count + timeYellow) / 10;
		led_buffer[3] = (count + timeYellow) % 10;
		if (count_auto <= 0) {
			count_auto = 99;
			count--;
			if (count <= 0) {
				autoStatus = YELLOW_RED;
				count = timeYellow;
				allLEDoff();
			}
		}
		else {
			count_auto--;
		}
		break;
	case YELLOW_RED:
		HAL_GPIO_WritePin(GPIOA, LED_GREEN_1_Pin|LED_YELLOW_2_Pin, RESET);
		led_buffer[0] = count / 10;
		led_buffer[1] = count % 10;
		led_buffer[2] = count / 10;
		led_buffer[3] = count % 10;
		if (count_auto <= 0) {
			count_auto = 99;
			count--;
			if (count <= 0) {
				autoStatus = RED_GREEN;
				count = timeGreen;
				allLEDoff();
			}
		}
		else {
			count_auto--;
		}
		break;
	default:
		break;
	}
}
