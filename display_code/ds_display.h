#ifndef DS_DISPLAY_H
#define DS_DISPLAY_H

#include <stdint.h>
#include "ds_i2c.h"

#define VOLT                10
#define EMPTY               11 
#define DOT                 12
#define SLAVE_W             ((0x3C << 1) | 0)

void display_init(void);
void charge_pump(void);
void clear_page(void);
void page_setup(uint8_t nr);
void display_reset(void);
void character_print(uint8_t index);

#endif
