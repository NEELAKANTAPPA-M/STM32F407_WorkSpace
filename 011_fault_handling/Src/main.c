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

#define SHCSR 					0xE000ED24
#define MEMFAULTENA_POS 		16
#define BUSFAULTENA_POS 		17
#define USGFAULTENA_POS 		18
#define UFSR 					0xE000ED2A

int main(void)
{
	// enable mem fault, usage fault,bus fault
	uint32_t *pSHCSR = (uint32_t *)SHCSR;
	*pSHCSR |= ((1<< MEMFAULTENA_POS) | (1 << BUSFAULTENA_POS) | (1 << USGFAULTENA_POS));

	uint32_t *pSRAM = (uint32_t *) 0x20010000;
	*pSRAM = 0xFFFFFFFF;

	void (* some_address) (void );
	some_address = (void *) 0x20010001;
	some_address();
    /* Loop forever */
	for(;;);
}

void HardFault_Handler()
{
	printf("Exception: HardFault_Handler \n");
	while(1);
}

void MemManage_Handler()
{
	printf("Exception: MemManage_Handler \n");
	while(1);
}

void BusFault_Handler()
{
	printf("Exception: BusFault_Handler \n");
	while(1);
}

__attribute ((naked)) void UsageFault_Handler(void)
{
	__asm ("MRS R0, MSP");
	__asm ("b UsageFault_Handler_C");
}

void UsageFault_Handler_C(uint32_t *pMSP)
{
	printf("Exception: UsageFault_Handler \n");

	uint32_t *pUFSR = (uint32_t *)UFSR;
	printf("UFSR -> 0x%lx\n", (*pUFSR) & 0xFFFF);
	printf("pMSP -> 0x%p\n",pMSP);
	printf("R0 -> 0x%lX\n",pMSP[0]);
	printf("R1 -> 0x%lX\n",pMSP[1]);
	printf("R2 -> 0x%lX\n",pMSP[2]);
	printf("R3 -> 0x%lX\n",pMSP[3]);
	printf("R12 -> 0x%lX\n",pMSP[4]);
	printf("LR -> 0x%lX\n",pMSP[5]);
	printf("PC -> 0x%lX\n",pMSP[6]);
	printf("XPSR -> 0x%lX\n",pMSP[7]);
	while(1);
}
