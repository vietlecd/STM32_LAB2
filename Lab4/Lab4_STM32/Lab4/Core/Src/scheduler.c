/*
 * scheduler.c
 *
 *  Created on: Nov 28, 2024
 *      Author: lenovo
 */

#include "global.h"

typedef struct {
	void (*pTask)(void);
	uint32_t Delay;
	uint32_t Period;
	uint8_t RunMe;
	uint32_t TaskID;
} sTask;

sTask SCH_tasks_G[SCH_MAX_TASKS];

int numTask = 0;	// Number of tasks currently in the scheduler

/**
 * @brief:		Initialize all task by deleting all in array
 * @param:		None
 * @retval:		None
 */
void SCH_Init(void) {
	unsigned char i;
	for (i = 0; i < SCH_MAX_TASKS; i++) {
		SCH_Delete_Task(i);
	}
}

/**
 * @brief: 		Updates the task in scheduler
 * @param: 		None
 * @retval:		None
 */
void SCH_Update(void) {
/*
 * @brief:	Complexity O(N)
 */
	unsigned char index;
	for (index = 0; index < SCH_MAX_TASKS; index++) {
		if (SCH_tasks_G[index].pTask) {
			if (SCH_tasks_G[index].Delay == 0) {
				SCH_tasks_G[index].RunMe += 1;
				if (SCH_tasks_G[index].Period) {
					SCH_tasks_G[index].Delay = SCH_tasks_G[index].Period;
				}
			}
			else {
				SCH_tasks_G[index].Delay -= 1;
			}
		}
	}
}

/**
 * @brief: 		Add new task to the scheduler with a specified delay and period
 * @param: 		- pFunction: 	Pointer to the function to be executed for the task
 * 		   		- DELAY: 		Initial delay before the task runs for the first time
 * 		   		- PERIOD: 		The period at which the task should repeat
 * @retval:		None
 */
void SCH_Add_Task(void(*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {
	if (numTask < SCH_MAX_TASKS) {
		unsigned char index;
		for (index = 0; index < SCH_MAX_TASKS; index++) {
			if (SCH_tasks_G[index].pTask != 0) continue;
			SCH_tasks_G[index].pTask = pFunction;
			SCH_tasks_G[index].Delay = DELAY;
			SCH_tasks_G[index].Period = PERIOD;
			SCH_tasks_G[index].RunMe = 0;
			SCH_tasks_G[index].TaskID = index;
			numTask++;
			break;
		}
	}
}

/**
 * @brief: 		Dispatch the tasks in the scheduler
 * @param: 		None
 * @retval:		None
 */
void SCH_Dispatch_Tasks(void) {
/*
 * @brief	Complexity O(N)
 */
	unsigned char index;
	for (index = 0; index < SCH_MAX_TASKS; index++) {
		if (SCH_tasks_G[index].RunMe > 0) {
			(*SCH_tasks_G[index].pTask)();
			SCH_tasks_G[index].RunMe -= 1;
			if (SCH_tasks_G[index].Period == 0) SCH_Delete_Task(index);
		}
	}
}

/**
 * @brief: 		Deletes a task from the scheduler by clearing data
 * @param: 		ID of the task to be deleted
 * @retval:		None
 */
void SCH_Delete_Task(uint32_t taskID) {
	if (taskID >= SCH_MAX_TASKS || SCH_tasks_G[taskID].pTask == 0) return;
	SCH_tasks_G[taskID].pTask = 0x0000;
	SCH_tasks_G[taskID].Delay = 0;
	SCH_tasks_G[taskID].Period = 0;
	SCH_tasks_G[taskID].RunMe = 0;
}
