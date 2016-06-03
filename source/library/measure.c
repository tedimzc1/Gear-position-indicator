/*
 * measure.c
 *
 *  Created on: 15.04.2016 ã.
 *      Author: ilian
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../IO/io_setup.h"
#include "../common/common.h"
#include "../init/set_interrupt.h"


uint16_t read_puls_20(void){											// Read IPG pulses for 10 VSS pulses



	uint16_t ipg_pulses = 0;
	pulse_counter = 0;

	do{
		while((IPG)&&(!NEUTRAL_SW));									// Count every falling edge
		while(!(IPG)&&(!NEUTRAL_SW));
		sei();
		ipg_pulses++;
		if (ipg_pulses > 1000) break;									// Error condition

	}while(pulse_counter < 20);
	cli();//


 return ipg_pulses;
}

uint16_t read_puls(void){											// Read IPG pulses for 10 VSS pulses

	uint16_t ipg_pulses = 0;
	pulse_counter = 0;

	do{
		while((IPG)&&(!NEUTRAL_SW));									// Count every falling edge
		while(!(IPG)&&(!NEUTRAL_SW));

		ipg_pulses++;
		if (ipg_pulses > 1000) break;									// Error condition

	}while(pulse_counter < 10);

	ipg_pulses = ipg_pulses * 2;

 return ipg_pulses;
}

int measure_freq (void){
	sei();
	_delay_ms(300);
	cli();
return IPG_time;
}
