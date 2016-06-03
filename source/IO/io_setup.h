/*
 * io_setup.h
 *
 *  Created on: 10.04.2016 ã.
 *      Author: ilian
 */

#ifndef IO_IO_SETUP_H_
#define IO_IO_SETUP_H_

#define VSS_PIN		 PD2
#define IPG_PIN		 PD3
#define NEUTRAL_PIN	 PD4
#define LEARN_PIN    PD5

#define VSS			 ((PIND & 0x04)>>2)
#define IPG			 ((PIND & 0x08)>>3)
#define NEUTRAL_SW	 ((PIND & 0x10)>>4)
#define LEARN_SW	!((PIND & 0x20)>>5)

#define LED_PORT	PORTB

void io_init(void);

#endif /* IO_IO_SETUP_H_ */
