/*
 * USART_Init.c
 *
 *  Created on: 10.04.2016 ã.
 *      Author: ilian
 */
#include <avr/io.h>
#include <stdio.h>

#include "../main.h"


void USART_Init(void){

   UCSRB |= (1 << RXEN)  | (1 << TXEN);   				// Turn on receive and trasmit
   UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1); // Format data frame Data 8 Bit, No Parity and 1 Stop Bit

   UBRRH = (BAUD_PRESCALE >> 8);
   UBRRL = BAUD_PRESCALE;
   UCSRB |= (1 << RXCIE);
}

int uart_putch(char ch, FILE *stream){

   if (ch == '\n')
	   uart_putch('\r', stream);

   while (!(UCSRA & (1 << UDRE)));

   UDR=ch;

return 0;
}

int uart_getch(FILE *stream){

   unsigned char ch;

   while (!(UCSRA & (1<<RXC)));

   ch=UDR;
//   Start echo
//   uart_putch(ch,stream);

   return ch;
}

void ansi_cl(void){

	  // ANSI clear screen: cl=\E[H\E[J
	  putchar(27);
	  putchar('[');
	  putchar('H');
	  putchar(27);
	  putchar('[');
	  putchar('J');
}
