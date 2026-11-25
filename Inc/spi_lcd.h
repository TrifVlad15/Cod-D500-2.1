/* spi_lcd.h */
#ifndef SPI_LCD_H
#define SPI_LCD_H
 
#include <stdint.h>
 
#define     LCD_DC_PORT      GPIOA
#define     LCD_DC_PIN       8U
 
#define     LCD_RES_PORT     GPIOA
#define     LCD_RES_PIN      9U
 
#define     LCD_CS_PORT      GPIOA
#define     LCD_CS_PIN       4U
 
#define     LCD_BL_PORT      GPIOA
#define     LCD_BL_PIN       10U
 
void spi_lcd_gpio_init(void);          /* pini + ceasuri GPIO */
void spi_lcd_spi_init(void);           /* SPI1 pe registre   */
void lcd_cs_low(void);                  /* listens*/
void lcd_cs_high(void);                 /* dose not listen*/
uint8_t spi1_transfer(uint8_t byte);   /* trimite un octet, întoarce ce a primit */
void lcd_cmd(uint8_t c);                /*DC low-cmd*/
void lcd_data(uint8_t d);               /*DC high-value*/
 
#endif /* SPI_LCD_H */

/*so i have separated the cs_low/high frm lcd_cmd/data because it s more efficient 
to make the pin high one time and send the data u want, tahn to make it high and low 
for each comand*/