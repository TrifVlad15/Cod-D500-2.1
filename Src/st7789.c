#include "st7789.h"
#include "spi_lcd.h"
#include "delay.h"


void st7789_init(void)
{
    /*RESET stage begin*/
    lcd_reset(); /*reset the display*/
    /*RESET stage end*/

    
    lcd_cs_low();/*now the ST7789 starts conversation*/
    
    lcd_cmd(0x01);/*SWREST-software reset*/
    delay_ms(120);

    lcd_cmd(0x36);  /*MADCTL-orientation on display*/
    lcd_data(0x00); /* if red and blue are swaped change to 0x08*/

    lcd_cmd(0x11);/*SLPOUT-Stops sleep mode */
    delay_ms(120);

    lcd_cmd(0x3A);/*COLMOD-pixel format*/
    lcd_data(0x55);

    lcd_cmd(0x29);/*DISPON-display on*/
    
    lcd_cs_high(); /* stop conversation */

    lcd_bl_on();/*turn on the backlight*/
}

