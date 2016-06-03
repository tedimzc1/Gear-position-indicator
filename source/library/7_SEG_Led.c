/*
 * 7_SEG_Led.c
 *
 *  Created on: 10.04.2016 ã.
 *      Author: ilian
 */
/*
 * Pin character map
 */
/*******************************************************************************

       B'00000010'     ; decode 0    0x02
       B'10011110'     ; decode 1    0x9E
       B'00100100'     ; decode 2    0x24
       B'00001100'     ; decode 3    0x0C
       B'10011000'     ; decode 4    0x98
       B'01001000'     ; decode 5    0x48
       B'01000000'     ; decode 6    0x40
       B'11100010'     ; decode L    0xE2
       B'11011100'     ; decode up   0xDC
       B'11100011'     ; decode down 0xE3
       B'11111100'     ; decode "-"  0xFC  (indicates the clutch is pulled in)


       B (abcdefg.)  port B to display

    a
   ----
  |    |
 f|    |b
   ----
  | g  |
 e|    |c
   ----
    d
*******************************************************************************/
#include <avr/io.h>
#include <util/delay.h>

#include "../IO/io_setup.h"

void led_char (char _char){

     switch(_char){                                                             // Char map, for normal view

      case 0 :    LED_PORT = 0b11000000;
         break;
      case 1 :    LED_PORT = 0b11111001;
         break;
      case 2 :    LED_PORT = 0b10100100;
         break;
      case 3 :    LED_PORT = 0b10110000;
         break;
      case 4 :    LED_PORT = 0b10011001;
         break;
      case 5 :    LED_PORT = 0b10010010;
         break;
      case 6 :    LED_PORT = 0b10000010;
         break;
      case 7 :    LED_PORT = 0b11111000;
         break;
      case 8 :    LED_PORT = 0b10000000;
         break;
      case 9 :    LED_PORT = 0b10010000;
         break;
      case '-' :  LED_PORT = 0b10111111;
         break;
      case 'R' :  LED_PORT = 0b10001000;
         break;
      case 'U' :  LED_PORT = 0b11011100;
         break;
      case 'D' :  LED_PORT = 0b11100011;
	     break;
      default  :  LED_PORT = 0b11111111;
      	  break;
     }
}


void led_off(void){                                                             // Turn off display

	LED_PORT = 0b11111111;
}

void flash_char(char n, int time){
	    for(int i=0; i<time; i++){
	      led_off();                                                                // Next giar number flash until
	      _delay_ms(100);                                                           // clutch change position
	      led_char(n);                                                              //
	      _delay_ms(100);
	   }
//	   led_off();
}
