/*
 * os_gpio.c
 *
 *  Created on: Dec 24, 2019
 *      Author: oleh
 */

#include "main.h"
#include "os_gpio.h"
#include "os_usart.h"

void timer_init()
{

	RCC -> APB1ENR	|= 0x00000002;//__TIM3_CLK_ENABLE();

	TIM3 -> PSC = 49999;
	TIM3 -> ARR = 7199;

	TIM3 -> CR1 |= 0x00000008;//OPM: One-pulse mode
//	TIM3 -> CR1 |= 0x00000001;
}

void gpio_init(void)
{
	RCC -> AHBENR  |= 0x00220000;//GPIOE,GPIOA clock enable
	GPIOE -> MODER   |= 0x55550000;//PE8-15 output
	GPIOE -> OSPEEDR |= 0xFFFF0000;//PE8-15
	timer_init();
}


void gpio_blink(void)
{

	static char on_off=0;
	if(((TIM3 -> CR1) & 0x00000001) == 0)
	{
		TIM3 -> CR1 |= 0x00000001;
		if(on_off)
		{
			on_off = 0;
			GPIOE -> BSRR = GPIO_BSRR_BS_9;
			GPIOE -> BSRR = GPIO_BSRR_BS_8;
			GPIOE -> BSRR = GPIO_BSRR_BS_10;
			GPIOE -> BSRR = GPIO_BSRR_BS_15;
			GPIOE -> BSRR = GPIO_BSRR_BS_11;
			GPIOE -> BSRR = GPIO_BSRR_BS_14;
			GPIOE -> BSRR = GPIO_BSRR_BS_12;
			GPIOE -> BSRR = GPIO_BSRR_BS_13;
			usart_open();
		}
		else
		{
			on_off = 1;
			GPIOE -> BSRR = GPIO_BSRR_BR_9;
			GPIOE -> BSRR = GPIO_BSRR_BR_8;
			GPIOE -> BSRR = GPIO_BSRR_BR_10;
			GPIOE -> BSRR = GPIO_BSRR_BR_15;
			GPIOE -> BSRR = GPIO_BSRR_BR_11;
			GPIOE -> BSRR = GPIO_BSRR_BR_14;
			GPIOE -> BSRR = GPIO_BSRR_BR_12;
			GPIOE -> BSRR = GPIO_BSRR_BR_13;
			usart_close();
		}
	}
}
