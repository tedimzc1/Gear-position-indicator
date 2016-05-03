/*
 * USART_Init.h
 *
 *  Created on: 10.04.2016 �.
 *      Author: ilian
 */

#ifndef INIT_USART_INIT_H_
#define INIT_USART_INIT_H_

#include <inttypes.h>

#ifdef DEBUG
void USART_Init(void);
int  uart_putch(char ch, FILE *stream);
int  uart_getch(FILE *stream);
#endif


void ansi_cl(void);
void ansi_me(void);
void ansi_cm(unsigned char row,unsigned char col);

#endif /* INIT_USART_INIT_H_ */
