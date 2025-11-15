#include "ds_adc.h"
#include <stdint.h>

void adc_setup(){
  ADMUX |= (1 << 6);    //AVcc
  ADCSRA |= (1 << 7) | (1 << 2) | (1 << 1) | (1 << 0);  //adc enable, 128 prescale
}
uint16_t adc_conversion(){
   uint16_t conversion_result;
   ADCSRA |= (1 << 6);
   while((ADCSRA & (1 << 6)));
   conversion_result = ADCL;
   conversion_result |= ADCH << 8;
   return conversion_result;
}
uint16_t adc_to_volts(uint16_t valueU){
   uint16_t volt_inU = (uint32_t)valueU * 5000 / 1023;
   return volt_inU;
}
