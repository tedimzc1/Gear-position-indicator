/*
 * set_interrupt.h
 *
 *  Created on: 15.04.2016 ã.
 *      Author: ilian
 */

#ifndef INIT_SET_INTERRUPT_H_
#define INIT_SET_INTERRUPT_H_

void set_external_interrupt(void);
void set_timer2_interrupt(void);

void disable_VSS_interrupt(void);
void enable_VSS_interrupt(void);
void disable_IPG_interrupt(void);
void enable_IPG_interrupt(void);

#endif /* INIT_SET_INTERRUPT_H_ */
