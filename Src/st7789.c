#include "st7789.h"
#include "spi_lcd.h"
#include "delay.h"
#include "stm32wbxx.h"

void st7789_init(void)
{
    /*RESET stage begin*/
    LCD_RES_PORT->BSRR = (1UL << (LCD_RES_PIN+16UL)); /* set low RES_PIN */
    
    delay_ms(2);

    LCD_RES_PORT->BSRR = (1UL << LCD_RES_PIN); /* set high RES_PIN */

    delay_ms(120);
    /*RESET stage end*/

    
    lcd_cs_low();/*now the ST7789 listens*/
    
    lcd_cmd(0x36);  /*MADCTL-orientation on display*/
    lcd_data(0x00); /* if red and blue are swaped change to 0x08*/
    
    lcd_cmd(0x01);/*SWREST-software reset*/
    lcd_data(0x00);
    delay_ms(120);
    
    lcd_cmd(0x11)/*SLPOUT-Stops sleep mode */
    lcd_data(0x00)
    delay_ms(120)

    lcd_cmd(0x3A)/*COLMOD-pixel format*/
    lcd_cmd

    lcd_cs_high();

    
}

