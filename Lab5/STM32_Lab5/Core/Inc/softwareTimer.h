/*
 * softwareTimer.h
 *
 *  Created on: Nov 22, 2024
 *      Author: lenovo
 */



#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer0_flag;
extern int timer1_flag;

void setTimer0(int duration);
void setTimer1(int duration);
void timer_run();

#endif /* INC_SOFTWARE_TIMER_H_ */
