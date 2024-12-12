/*
 * display_7seg.h
 *
 *  Created on: Nov 4, 2024
 *      Author: lenovo
 */

#ifndef INC_DISPLAY_7SEG_H_
#define INC_DISPLAY_7SEG_H_

#define INIT 5
#define SEG0 0
#define SEG1 1
#define SEG2 2
#define SEG3 3

void setEnableSignal(int type);
void updateBufferWithMode(int MODE);
void displayNumber(int num);
void displaySegment(void);
#endif /* INC_DISPLAY_7SEG_H_ */
