/*
 * main.h
 *
 *  Created on: 10.04.2016 ã.
 *      Author: ilian
 */

#ifndef MAIN_H_
#define MAIN_H_

//#define F_CPU 8000000UL														// Set CPU frequency
#define USART_BAUDRATE 9600													// Define Baudrate to 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)				// Izchisliava preskaler na Baudrate

#define ON  1
#define OFF 0

#include <util/delay.h>
static inline void _delay_loop_2(uint16_t __count) __attribute__((always_inline));

#define delay_us(us)   _delay_loop_2((unsigned int)(((float)F_CPU*us)/4000000L))
#define nop()         asm("nop")
//#define DEBUG
//#define DEBUG_SHIFT

#endif /* MAIN_H_ */
