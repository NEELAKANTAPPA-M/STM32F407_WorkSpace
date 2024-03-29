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

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#define ALIAS_BASE 0x22000000U
#define BIT_BAND_BASE 0x20000000U

int main(void)
{

	uint8_t *ptr = (uint8_t *)0x20000200;
	//Normal method to change the value of 7th bit of some address
	*ptr = 0xff;
	*ptr &= ~(1<<7);
	//reset it to 0xff
	*ptr |= (1<<7);

	//bit band method to change bit of a address
	uint8_t *alias_addr;
	//formula to calc alias address of a bit in SRAM addrss space
	alias_addr = (uint8_t *) ALIAS_BASE + (32 *(0x20000200-BIT_BAND_BASE)) + 7*4;
	*alias_addr = 0;

    /* Loop forever */
	for(;;);
}
