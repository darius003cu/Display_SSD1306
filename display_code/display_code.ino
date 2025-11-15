#include <stdint.h>
#include "ds_adc.h"
#include "ds_i2c.h"
#include "ds_display.h"

int main(void) {
  uint16_t adc_value;
  uint16_t vin;
  adc_setup();
  display_init();
  charge_pump();
  display_reset();
  page_setup(255);

  while(1) {
    adc_value = adc_conversion();
    vin = adc_to_volts(adc_value);

    character_print(vin / 1000);
    character_print(DOT);
    character_print((vin / 100) % 10);
    character_print((vin / 10) % 10);
    character_print(VOLT);
    page_setup(0);
  }
}
