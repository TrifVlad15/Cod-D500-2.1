#ifndef DELAY_H
#define DELAY_H
 
#include <stdint.h>
 
void     systick_init(void);          /* pornește SysTick la 1 ms */
void     delay_ms(uint32_t n);        /* așteaptă n milisecunde  */
uint32_t millis(void);                /* milisecunde de la pornire */
 
#endif /* DELAY_H */
 