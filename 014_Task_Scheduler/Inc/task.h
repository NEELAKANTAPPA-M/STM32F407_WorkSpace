/*
 * task.h
 *
 *  Created on: 11-May-2023
 *      Author: neelakanta
 */

#ifndef TASK_H_
#define TASK_H_
#include <type.h>


#define TASK_READY_STATE	0x0
#define TASK_BLOCK_STATE	0xFF

#define SRAM_START			0x20000000U
#define SRAM_SIZE			(128 * 1024)
#define SRAM_END			(SRAM_START + SRAM_SIZE)

#define TASK_STACK_SIZE		(1024U)
#define T1_STACK_START		SRAM_END
#define T2_STACK_START		(SRAM_END - (1 * TASK_STACK_SIZE))
#define T3_STACK_START		(SRAM_END - (2 * TASK_STACK_SIZE))
#define T4_STACK_START		(SRAM_END - (3 * TASK_STACK_SIZE))
#define IDLE_STACK_START	(SRAM_END - (4 * TASK_STACK_SIZE))
#define SCHED_STACK_START	(SRAM_END - (5 * TASK_STACK_SIZE))

#define MAX_TASKS			5U

#define DUMMY_XPSR			0x01000000U

#define INTERRUPT_DISABLE()  do{__asm volatile ("MOV R0,#0x1"); asm volatile("MSR PRIMASK,R0"); } while(0)

#define INTERRUPT_ENABLE()  do{__asm volatile ("MOV R0,#0x0"); asm volatile("MSR PRIMASK,R0"); } while(0)

typedef struct{
	u32 psp_value;
	u32 block_cnt;
	u32 current_state;
	void (*task_handler)(void);
}TCB_st;

void t1_handler(void);
void t2_handler(void);
void t3_handler(void);
void t4_handler(void);
void init_tasks_stack();
void store_task_handler_addr(void);
u32 get_psp_value(void);
__attribute__((naked)) void init_scheduler_stack(u32 sched_stack_top);
__attribute__((naked)) void switch_sp_to_psp(void);

#endif /* TASK_H_ */
