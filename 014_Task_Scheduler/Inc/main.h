/*
 * main.h
 *
 *  Created on: 02-May-2023
 *      Author: neelakanta
 */

#ifndef MAIN_H_
#define MAIN_H_
#include <type.h>

void init_systick_timer(u32 tick_hz);
void enable_fault_handlers(void);
void SysTick_Handler(void);
void task_delay(u32 tick_count);

#define HSC_CLK				16000000U
#define SYS_TICK_TIMER_CLK	HSC_CLK
#define TICK_HZ				1000U
#define SYST_CSR			0xE000E010
#define SYST_RVR			0xE000E014
#define SYST_CVR			0xE000E018
#define SYST_CALIB			0xE000E01C
#define ICSR				0xE000ED04

#define SHCSR 					0xE000ED24
#define MEMFAULTENA_POS 		16
#define BUSFAULTENA_POS 		17
#define USGFAULTENA_POS 		18

#endif /* MAIN_H_ */
