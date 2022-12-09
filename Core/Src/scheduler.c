/*
 * scheduler.c
 *
 *  Created on: Nov 11, 2022
 *      Author: anhni
 */
#include "scheduler.h"

sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;

///init
void SCH_Init(void){
	unsigned char i;
	for(i = 0; i< SCH_MAX_TASKS; i++){
		SCH_Delete_Task(i);
	}
//	Error_code_G = 0;
//	Timer_init();
//	Wacthdog_init();
}

unsigned char SCH_Add_Task ( void (*pFunction)() , uint32_t DELAY, uint32_t PERIOD){
	unsigned char Index = 0;
	while((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS)){
		Index++;
	}
	if(Index == SCH_MAX_TASKS)
	{
		//Error_code_G = ERROR_SCH_TOO_MANY_TASK;
		return SCH_MAX_TASKS;
	}
	SCH_tasks_G[Index].pTask = pFunction;
	SCH_tasks_G[Index].Delay = DELAY;
	SCH_tasks_G[Index].Period =  PERIOD;
	SCH_tasks_G[Index].RunMe = 0;
	SCH_tasks_G[Index].TaskID = Index;

	return Index;
}

void SCH_Update(void){
	unsigned char Index ;
	// NOTE: calculations are in *TICKS* (not milliseconds)
	for( Index = 0; Index < SCH_MAX_TASKS; Index++) {
		// Check i f there is a task at this location
		if(SCH_tasks_G[Index].pTask ) {
			if(SCH_tasks_G[Index].Delay == 0 ) {
				// The task i s due to run
				// Inc . the ’RunMe’ flag
				SCH_tasks_G[Index].RunMe += 1;
				if(SCH_tasks_G [Index].Period ) {
					// Schedule periodic tasks to run again
					SCH_tasks_G [Index].Delay = SCH_tasks_G[Index].Period ;
				}
			}else{
				// Not yet ready to run : just decrement the delay
				SCH_tasks_G [Index].Delay -= 1;
			}
		}
	}
//	for(int i = 0; i < current_index_task;i++){
//		if(SCH_tasks_G[i].Delay > 0){
//			SCH_tasks_G[i].Delay --;
//		}else{
//			SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
//			SCH_tasks_G[i].RunMe+=1;
//		}
//	}
}
void SCH_Dispatch_Tasks(void){
	unsigned char Index ;

		for( Index = 0; Index < SCH_MAX_TASKS; Index++) {
			// Check i f there is a task at this location
			if(SCH_tasks_G[Index].RunMe > 0) {
				SCH_tasks_G[Index].RunMe--;
				(*SCH_tasks_G[Index].pTask)();

				if(SCH_tasks_G[Index].Period == 0){
					SCH_Delete_Task(Index);
				}
			}
		}
//	for(int i = 0; i < current_index_task; i++){
//		if(SCH_tasks_G[i].RunMe > 0){
//			SCH_tasks_G[i].RunMe--;
//			(*SCH_tasks_G[i].pTask)();
//		}
//	}
}

unsigned char SCH_Delete_Task(unsigned char TASK_INDEX){
//	unsigned char Return_code;
//	if(SCH_tasks_G[TASK_INDEX].pTask == 0){
//		//Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
//		Return_code = RETURN_ERROR;
//	}else{
//		Return_code = RETURN_NORMAL;
//	}
	SCH_tasks_G[TASK_INDEX].pTask = 0x0000;
	SCH_tasks_G[TASK_INDEX].Delay = 0;
	SCH_tasks_G[TASK_INDEX].Period =  0;
	SCH_tasks_G[TASK_INDEX].RunMe = 0;
	//return Return_code;
	return TASK_INDEX;
}
