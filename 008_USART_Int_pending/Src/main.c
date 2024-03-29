/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define USART1_IRQ_NO 37


int main(void)
{
	//Mamually pending the NVIC register for USART1
	uint32_t *NVIC_ISPR1 = (uint32_t *)(0xE000E200 + 0x04);
	*NVIC_ISPR1 |= (1 << (USART1_IRQ_NO % 32) );

	//Enabling the interrupt in NVIC register for USART1
	uint32_t *NVIC_ISER1 = (uint32_t *)(0xE000E100 + 0x04);
	*NVIC_ISER1 |= (1 << (USART1_IRQ_NO % 32) );

	printf("hii");
	printf("hii");
	printf("hii");
	printf("hii");
	printf("hii");
	printf("hii");
	printf("hii");
	printf("hii");
	printf("hii");



    /* Loop forever */
	for(;;);
}

void USART1_IRQHandler()
{
	for(int i=0;i<5;i++);
}


