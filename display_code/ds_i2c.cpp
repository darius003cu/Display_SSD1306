#include "ds_i2c.h"
#include <stdint.h>


void i2c_send(uint8_t package[], uint8_t length_of_package){

  TWCR = (1 << 7) | (1 << 5) | (1 << 2);
  while(!(TWCR & (1 << 7)));
  
  for(uint8_t i=0; i<length_of_package; i++){
      TWDR = package[i];
      TWCR = (1 << 7) | (1 << 2);
      while(!(TWCR & (1 << 7)));
      }

  TWCR = (1 << 7) | (1 << 4) | (1 << 2);
  
}
