#include "main.h"
#include "os_usart.h"

char uart_enable = 0;

void usart_init(){

	RCC -> AHBENR  |= 0x00080000;//GPIOC_CLK_ENABLE
	GPIOC -> MODER   |= 0x00000A00;//PC5,PC4
	GPIOC -> AFR[0]  |= 0x00770000;
	GPIOC -> OSPEEDR |= 0x00000F00;

	RCC -> APB2ENR  |= 0x00004000;//USART1
	USART1 -> CR1 = 0;//~USART_CR1_UE; //stop uart
	USART1 -> CR1 = 0x0C; //TE=1 RE=1
	USART1 -> BRR = 625; //BAUD RATE 115200Hz //0x4E1
//	USART1 -> CR1 |= USART_CR1_UE; //start uart

}

int usart_read(char *r_char)
{
	if(USART1 -> ISR & USART_ISR_RXNE)
	{
		*r_char = USART1 -> RDR;
		return 1;
	}
	return 0;
}

int usart_write(char t_char)
{
	if(USART1 -> ISR & USART_ISR_TXE)
	{
		USART1 -> TDR = t_char;
		USART1 -> ISR &= ~USART_ISR_TXE;
		return 1;
	}
	return 0;
}

void usart_open()
{
	USART1 -> CR1 |= USART_CR1_UE;
}

void usart_close()
{
	USART1 -> CR1 &= ~USART_CR1_UE;
}

void usart_deinit(){

	GPIOC -> MODER   &= 0xFFFFF0FF;//PC5,PC4
	GPIOC -> AFR[0]  &= 0xFF00FFFF;
	GPIOC -> OSPEEDR &= 0xFFFFF0FF;

	RCC -> APB2RSTR  |= 0x00004000;//USART1
	USART1 -> CR1 = 0;//~USART_CR1_UE; //stop uart

}

void usart_loop()
{

	char rtbyte;

	if(usart_read(&rtbyte))
	{
		while(!usart_write(rtbyte));
	}

}
