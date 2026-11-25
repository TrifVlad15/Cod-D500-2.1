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
 
uint16_t st7789_window_set(uint16_t xs, uint16_t ys, uint16_t xe, uint16_t ye, uint32_t *hi, uint32_t *lo)
{


    lcd_cmd(0x2A); /*CASET-column address set*/

    lcd_data((uint8_t)(xs >> 8)); /* send high byte of xs */
    lcd_data((uint8_t)(xs & 0xFF)); /* send low byte of xs */

    lcd_data((uint8_t)(xe >> 8)); /* send high byte of xe */
    lcd_data((uint8_t)(xe & 0xFF)); /* send low byte of xe */

    lcd_cmd(0x2B); /*RASET-row address set*/

    lcd_data((uint8_t)(ys >> 8)); /* send high byte of ys */
    lcd_data((uint8_t)(ys & 0xFF)); /* send low byte of ys */

    lcd_data((uint8_t)(ye >> 8)); /* send high byte of ye */
    lcd_data((uint8_t)(ye & 0xFF)); /* send low byte of ye */

    lcd_cmd(0x2C); /*RAMWR-write to RAM*/

    *hi = (uint8_t)(xs >> 8)*(uint8_t)(xe & 0xFF); 
    *lo = (uint8_t)(ys >> 8)*(uint8_t)(ye & 0xFF); 

}

void st7789_fill_screen(uint16_t color)
{
  lcd_cs_low(); /* start conversation */
  uint8_t hi, lo;
  st7789_window_set(0, 0, 239,239, &hi, &lo); /* set the window to the entire screen */
  
  for(uint32_t i =0; i<=(hi*lo); i++)
  {
    lcd_data((uint8_t)(color >> 8)); /* send high byte of color */
    lcd_data((uint8_t)(color & 0xFF)); /* send low byte of color */
  }
  lcd_cs_high(); /* stop conversation */

}