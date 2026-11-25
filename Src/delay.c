#include "delay.h"
#include "stm32wbxx.h"
 
static volatile uint32_t msTicks; /* numără milisecunde de la pornire */
 
void systick_init(void)
{
    SysTick->LOAD = (uint32_t)(SystemCoreClock / 1000UL) - 1UL; /* set reload register */
    SysTick->VAL = 0UL;                                         /* reset the SysTick counter value */
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk; /* enable SysTick IRQ and SysTick Timer */
}
 
void SysTick_Handler(void)
{
    msTicks++; /* increment counter necessary in delay() */
}
///////////////////////////////////
uint32_t millis(void)
{
    return msTicks;
}
 
void delay_ms(uint32_t ms)
{
    uint32_t start = millis();
    while ((millis() - start) < ms) {
        /* wait until the specified time has passed */
    }
}
 