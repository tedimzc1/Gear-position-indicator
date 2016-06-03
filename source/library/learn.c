/*
 * learn.c
 *
 *  Created on: 24.04.2016 ã.
 *      Author: ilian
 */

/*******************************************************************************
Data EEPROM storage map -
   Addr   Description
   ----   -----------

   0x00   Number of IGP cycles per VSS cycle for 1st giar                       // For one giar have 4 positions, last one position is biggest
   0x04   Number of IGP cycles per VSS cycle for 2nd giar                       // The next one is next biggest value
   0x08   Number of IGP cycles per VSS cycle for 3rd giar
   0x0C   Number of IGP cycles per VSS cycle for 4th giar
   0x10   Number of IGP cycles per VSS cycle for 5th giar
   0x14   Number of IGP cycles per VSS cycle for 6th giar
   0x18   Number of giars

   ????0x07   Valid data signature. 0xCC indicates valid data.
   Anything else indicates invalid data

   0x08   The ambient light sensor threshold
*******************************************************************************/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/eeprom.h>

#include "../main.h"
#include "../IO/io_setup.h"
#include "../init/set_interrupt.h"
#include "../common/common.h"
#include "../library/7_SEG_Led.h"
#include "../library/measure.h"

//DEBUG
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//DEBUG

void gear_lern_count(int n, int address){

   uint16_t high=0;
   uint16_t low=0;
   uint16_t current;
   int i;

   led_char(n);

   while(LEARN_SW);
   _delay_ms(100);
   while(!LEARN_SW);

   flash_char(n,1);

#ifdef DEBUG
	  printf("START LEARN\r\n");
#endif

   current = read_puls_20();
   current = read_puls_20();
   current = read_puls_20();
   current = read_puls_20();

   low  = current;
   high = current;

   for(i=0; i<10; i++){

	  current = read_puls_20();												// Read result for 10 pulses

	  if(current < low){                                                     // Set min & max value
	 	low = current;
	  }
	  if(current > high){
	 	high = current;
	  }
#ifdef DEBUG
         printf("low, high > %d, %d\r\n",low, high);
#endif
    }

   if((low <= 0)||(high > 1000)){                                              // Error condition
#ifdef DEBUG
	   printf(">%d-%d\r\n", low, high);
#endif
      for(;;){
         led_char('R');
         _delay_ms(300);
         led_off();
         _delay_ms(300);
      }
   }
   eeprom_write_word((uint16_t*)address,low);									// Write low value
   address += 2;
   eeprom_write_word((uint16_t*)address, high);								    // Write high value

   flash_char(n,3);
}


void learn_device(void){

uint16_t i;
uint8_t address = 0x00;
int time_min=0;
int time_max=0;
int temp_time=0;


   for(;;){                                                                  // Chose 5 or 6 gear position

      while (LEARN_SW);

      if(gear_num == 0){                                                     // 5 gear
         led_char(5);
         for(i=0; i<=1000; i++){
            _delay_ms (1);
            if(LEARN_SW){
            	gear_num=5;
               for(i=0; i<=3; i++){
                  led_char(5);
                     _delay_ms(200);
                  led_off();
                     _delay_ms(200);
               }
               break;
            }
         }
      }

      if(gear_num == 0){                                                     // 6 gear
         led_char(6);
         for(i=0; i<=1000; i++){
            _delay_ms (1);
            if (LEARN_SW){
            	gear_num=6;
               for(i=0; i<=3; i++){
                  led_char(6);
                     _delay_ms(200);
                  led_off();
                     _delay_ms(200);
               }
               break;
            }
         }
      }
      if ((gear_num == 5) || (gear_num == 6)) break;
   }

   eeprom_write_word((uint16_t*)0x18, gear_num);							 // Write value to eeprom

   for(i=1; i<=gear_num; i++){                                               // Choose address from EEPROM for each gear
                                                                             // to save parameters
      switch (i){
       case 1 : address = 0x00;
          break;
       case 2 : address = 0x04;
          break;
       case 3 : address = 0x08;
          break;
       case 4 : address = 0x0C;
          break;
       case 5 : address = 0x10;
          break;
       case 6 : address = 0x14;
          break;
       default : break;
      }
     gear_lern_count(i, address);
   }

   /*
    * Learn shift up
    */

   flash_char('U',1);

   while(LEARN_SW);
   _delay_ms(100);
   while(!LEARN_SW);

   led_char('U');

   temp_time = measure_freq();
   time_max = temp_time;
   time_min = temp_time;


   for(i=0; i<100; i++){
	   if(temp_time > time_max) time_max = temp_time;
//	   if(temp_time < time_min) time_min = temp_time;
   }
   eeprom_write_word((uint16_t*)0x1A, time_min);							 // Write value to eeprom
   eeprom_write_word((uint16_t*)0x1C, time_max);

   flash_char('U',3);

   /*
    * Learn shift down					//das se napraviat simvoli za poziciite
    */

   led_char('D');

   while(LEARN_SW);
   _delay_ms(100);
   while(!LEARN_SW);

   flash_char('D',1);

   temp_time = measure_freq();
   time_max = temp_time;
   time_min = temp_time;

   for(i=0; i<100; i++){
	   if(temp_time > time_max) time_max = temp_time;
	   if(temp_time < time_min) time_min = temp_time;
   }
   eeprom_write_word((uint16_t*)0x1E, time_min);							 // Write value to eeprom
//   eeprom_write_word((uint16_t*)0x20, time_max);
   flash_char('D',3);
   led_off();

}


