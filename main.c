/******************************************
 *            SMART CARD READER           *
 *                                        *
 *            Pedro Vanzella              *
 ******************************************/

#include <arch/nxp/lpc23xx.h>
#include <stdio.h>
#include <stdlib.h>
#include "LCD.h"
#include "io.h"
#include "serial.h"
#include "timer.h"
#include "i2c.h"
#include "vic_cpsr.h"

int main(void)
{
	char buffer[17]; // Where we are reading to
	buffer[16] = '\0'; // Terminating string
	int page = 0xa0;
	int offset = 0;

	init_timer0(); // LCD needs timer0 to function
	LCDinit(); // Initializing LCD
	ini_i2c(); // Initializing i2c

	/******************** MAIN LOOP *********************/
	while(1) {
		offset &= 0xff;
		buffer[0] = offset;
		escreve_i2c(page, buffer, 1); /* tell i2c we want to read from page + offset */
		if(le_i2c(page, buffer, 16)) { /* If we failed to read 16 bytes */
			LCDclear();
			LCDgoto(0, 0);
			LCDputs("*****KABOOM*****");
			LCDgoto(1, 0);
			LCDputs(buffer);
		} else {
			LCDgoto(0, 0); // Go to first line, first column
			LCDputs("Pg = ");
			LCDputchar(page + '0'); // Prints page number as char

			LCDgoto(0, 8); // Go to the second half of first line
			LCDputs("Of = ");
			LCDputchar(offset + '0'); // Prints offset as char

			LCDgoto(1, 0); // Fisrt column of the second line
			LCDputs(buffer); // Prints buffer
		}
	}

	return 0;
}

void UNDEF_Routine(){}
void FIQ_Routine(){}
void SWI_Routine(){}
