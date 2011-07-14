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

int main(void)
{

  init_timer0(); // LCD needs timer0 to function
  LCDinit();

  /******************** MAIN LOOP *********************/
  while(1)
  {
    LCDgoto(0, 0); // Go to first line, first colum
    LCDputs("oi");
  }

  return 0;
}

void UNDEF_Routine(){}
void FIQ_Routine(){}
void SWI_Routine(){}
