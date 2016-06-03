/*
 * set_interrupt.c
 *
 *  Created on: 15.04.2016 ã.
 *      Author: ilian
 */
#include <avr/interrupt.h>
#include <avr/io.h>

void set_timer2_interrupt(void){
	/*
	 *  enable timer overflow interrupt
	 */
    TIMSK |= (1 << TOIE2);
    TIMSK |= (0 << OCIE2);
	/*
	 *  set timer counter initial value
	 */
    TCNT2 = 0xF8;

	/*
	 *  start timer with pre-scaler 0
	 */
    TCCR2 |= _BV(CS20);
}

void set_external_interrupt(void){
    MCUCR |=  (1 << ISC00);
    MCUCR |=  (1 << ISC01);      // set INT0 to trigger on rising edge
}

void disable_VSS_interrupt(void){
	GICR &= ~(1 << INT0);
}

void enable_VSS_interrupt(void){

	GICR  |=  (1 << INT0);
}

void disable_IPG_interrupt(void){
	GICR  &=  ~(1 << INT1);
}

void enable_IPG_interrupt(void){
	GICR  |=  (1 << INT1);
}
