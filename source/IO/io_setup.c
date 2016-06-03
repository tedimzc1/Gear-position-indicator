/*
 * io_setup.c
 *
 *  Created on: 10.04.2016 ã.
 *      Author: ilian
 */

#include <avr/io.h>

#include "io_setup.h"

void io_init(void){

	DDRB   |=  (1 << PB0) ;			    // LED Display port
	DDRB   |=  (1 << PB1) ;
	DDRB   |=  (1 << PB2) ;
	DDRB   |=  (1 << PB3) ;
	DDRB   |=  (1 << PB4) ;
	DDRB   |=  (1 << PB5) ;
	DDRB   |=  (1 << PB6) ;

	LED_PORT = 0xFF;				    // All segments off

    DDRD   &= ~(1 << VSS_PIN);          // PD2 (INT0 pin) VSS pin as input
    DDRD   &= ~(1 << IPG_PIN);   		// Set IPG as input
	DDRD   &= ~(1 << LEARN_PIN);		// Set LEARN_PIN as input
	DDRD   &= ~(1 << NEUTRAL_PIN); 	    // Set NEUTRAL_PIN as input

    PORTD  |=  (1 << VSS_PIN);          // turn On the Pull-ups
    PORTD  |=  (1 << IPG_PIN);
	PORTD  |=  (1 << LEARN_PIN);
	PORTD  |=  (1 << NEUTRAL_PIN);


	DDRC   |=  (1 << PC0); 				// Output signals for debug
	DDRC   |=  (1 << PC1);

	DDRC   |=  (1 << PC4); 				// Output signals for debug
	DDRC   |=  (1 << PC5);

	PORTC  &= ~(1 << PC0);
	PORTC  &= ~(1 << PC1);

	PORTC  &= ~(1 << PC4);
	PORTC  &= ~(1 << PC5);

}
