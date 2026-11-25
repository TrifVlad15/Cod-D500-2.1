
#ifndef ST7789_H
#define ST7789_H

#include <stdint.h>


void st7789_init(void);
void st7789_window_set(uint16_t xs, uint16_t ys, uint16_t xe, uint16_t ye);

#endif /*ST7789_H*/