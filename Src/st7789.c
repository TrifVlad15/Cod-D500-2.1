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

void st7789_window_set(uint16_t xs, uint16_t ys, uint16_t xe, uint16_t ye)
{
    lcd_cs_low(); /*now the ST7789 starts conversation*/

    lcd_cmd(0x2A); /*CASET-column address set*/

    lcd_data(xs >> 8); /* send high byte of xs */
    lcd_data(xs & 0xFF); /* send low byte of xs */

    lcd_data(xe >> 8); /* send high byte of xe */
    lcd_data(xe & 0xFF); /* send low byte of xe */

    lcd_cmd(0x2B); /*RASET-row address set*/

    lcd_data(ys >> 8); /* send high byte of ys */
    lcd_data(ys & 0xFF); /* send low byte of ys */

    lcd_data(ye >> 8); /* send high byte of ye */
    lcd_data(ye & 0xFF); /* send low byte of ye */

    lcd_cmd(0x2C); /*RAMWR-write to RAM*/

    lcd_cs_high(); /* stop conversation */
}
