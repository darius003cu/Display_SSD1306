#include "ds_i2c.h"
#include <stdint.h>

#define START_TRANSMISSION      1
#define STOP_TRANSMISSION       0
#define SENDING_DATA            2

void i2c_send(uint8_t state, uint8_t package[], uint8_t length_of_package){
  if(state == SENDING_DATA){
  for(uint8_t i=0; i<length_of_package; i++){
      TWDR = package[i];
      TWCR = (1 << 7) | (1 << 2);
      while(!(TWCR & (1 << 7)));
      }
  }
  else if(state == START_TRANSMISSION){
    TWCR = (1 << 2) | (1 << 7) | (1 << 5);
    while(!(TWCR & (1 << 7)));
  }
  else if(state == STOP_TRANSMISSION){
    TWCR = (1 << 7) | (1 << 4) | (1 << 2);
  }
  else{
    ;;
  }
}
