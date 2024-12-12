/*
 * scheduler.h
 *
 *  Created on: Nov 28, 2024
 *      Author: lenovo
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "main.h"
#include "software_timer.h"

#define SCH_MAX_TASKS	40
#define NO_TASK_ID 		0

extern int currentTaskIndex;

void SCH_Init(void);
void SCH_Update(void);
void SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD);
void SCH_Dispatch_Tasks(void);
void SCH_Delete_Task(uint32_t taskID);

#endif /* INC_SCHEDULER_H_ */
