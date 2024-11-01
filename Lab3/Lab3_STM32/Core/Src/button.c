/*
 * button.c
 *
 *  Created on: Nov 1, 2024
 *      Author: lenovo
 */

#include "button.h"

int KeyReg_0[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg_1[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg_2[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg_3[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int TimeOutForKeyPress =  300;
int btn_flag[3] = {0, 0, 0};

int isButtonPressed(int index) {
	if(btn_flag[index] == 1) {
		btn_flag[index] == 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index) {
	btn_flag[index] = 1;
}

GPIO_PinState btn_detector(int index)
{
	switch(index) {
		case 0:
			return HAL_GPIO_ReadPin(change_mode_GPIO_Port, change_mode_PIN);
			break;
		case 1:
			return HAL_GPIO_ReadPin(change_mode_GPIO_Port, change_time_PIN);
			break;
		case 2:
			return HAL_GPIO_ReadPin(change_mode_GPIO_Port, set_time_PIN);
			break;
		default:
			return NORMAL_STATE;
	}
}


