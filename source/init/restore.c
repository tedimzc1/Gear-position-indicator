/*
 * restore.c
 *
 *  Created on: 28.04.2016 ã.
 *      Author: ilian
 */
#include <avr/eeprom.h>
#include "../common/common.h"

//Memory map
//0x00   Number of IGP cycles per VSS cycle for 1st giar
//0x04   Number of IGP cycles per VSS cycle for 2nd giar
//0x08   Number of IGP cycles per VSS cycle for 3rd giar
//0x0C   Number of IGP cycles per VSS cycle for 4th giar
//0x10   Number of IGP cycles per VSS cycle for 5th giar
//0x14   Number of IGP cycles per VSS cycle for 6th giar
//0x18   Number of gears
//0x1A	 Shift_up
//0x1C	 Shift_up
//0x1E	 Shift_down
//0x20	 Shift_down

/*
 * Restore settings from eeprom
 */
void restore(void){
	int j;
gear_num = eeprom_read_word((uint16_t*)0x18);

	for(j=1; j<=gear_num; j++){
		switch(j){
			case 1 :
				gear1[0] = eeprom_read_word((uint16_t*)0x00);
				gear1[1] = eeprom_read_word((uint16_t*)0x02);
				break;
			case 2 :
				gear2[0] = eeprom_read_word((uint16_t*)0x04);
				gear2[1] = eeprom_read_word((uint16_t*)0x06);
				break;
			case 3 :
				gear3[0] = eeprom_read_word((uint16_t*)0x08);
				gear3[1] = eeprom_read_word((uint16_t*)0x0A);
				break;
			case 4 :
				gear4[0] = eeprom_read_word((uint16_t*)0x0C);
				gear4[1] = eeprom_read_word((uint16_t*)0x0E);
				break;
			case 5 :
				gear5[0] = eeprom_read_word((uint16_t*)0x10);
				gear5[1] = eeprom_read_word((uint16_t*)0x12);
				break;
			case 6 :
				gear6[0] = eeprom_read_word((uint16_t*)0x14);
				gear6[1] = eeprom_read_word((uint16_t*)0x16);
				break;
			default :
				break;
		}
	}

	shift_up_min   = eeprom_read_word((uint16_t*)0x1A);
	shift_up_max   = eeprom_read_word((uint16_t*)0x1C);
	shift_down_min = eeprom_read_word((uint16_t*)0x1E);
	shift_down_max = eeprom_read_word((uint16_t*)0x20);
}
