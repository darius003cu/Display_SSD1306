#include "ds_i2c.h"
#include <stdint.h>

#define START     0
#define STOP      1

void i2c_toggle(uint8_t state){
    if(state == START){
      TWCR = (1 << 2) | (1 << 7) | (1 << 5);
      while(!(TWCR & (1 << 7)));
    }
    else if(state == STOP){
      TWCR = (1 << 7) | (1 << 4) | (1 << 2);
    }
}

void i2c_send(uint8_t package[], uint8_t length_of_package){
  for(uint8_t i=0; i<length_of_package; i++){
      TWDR = package[i];
      TWCR = (1 << 7) | (1 << 2);
      while(!(TWCR & (1 << 7)));
      }
}
