/*
 * softwareTimer.h
 *
 *  Created on: Dec 18, 2023
 *      Author: hieun
 */



#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer0_flag;
extern int timer1_flag;

void setTimer0(int duration);
void setTimer1(int duration);
void timer_run();

#endif /* INC_SOFTWARE_TIMER_H_ */
