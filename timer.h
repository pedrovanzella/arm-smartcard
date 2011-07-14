#ifndef TIMER_H
#define TIMER_H
#include <arch/nxp/lpc23xx.h>
#define CCLK 12000000

void init_timer0(void);
void init_timer1(void);

#endif /* TIMER_H */
