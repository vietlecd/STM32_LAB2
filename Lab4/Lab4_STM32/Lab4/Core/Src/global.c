/*
 * global.c
 *
 *  Created on: Nov 24, 2024
 *      Author: lenovo
 */

#include "global.h"

int autoStatus = INIT;

int timeRed = 5;
int timeYellow = 2;
int timeGreen = 3;

int count = 0;

int FSM_STATUS = INIT;
int valueSetting = 0;
int BLINKY_LED_STATUS = INIT;

int led_buffer[4] = {0, 0, 0, 0};
int STATUS_7SEG = INIT;

int count_7SEG = 25;

int TIME_CYCLE = 10;

int count_blink = 25;
int count_auto = 99;
