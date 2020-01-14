/*
 * os_usart.h
 *
 *  Created on: Dec 25, 2019
 *      Author: oleh
 */

#ifndef INC_OS_USART_H_
#define INC_OS_USART_H_

#include "main.h"

void usart_init(void);
int usart_read(char*);
int usart_write(char);
void usart_open(void);
void usart_close(void);
void usart_deinit(void);
void usart_loop(void);

#endif /* INC_OS_USART_H_ */
