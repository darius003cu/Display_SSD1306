#ifndef DS_ADC_H
#define DS_ADC_H

#include <stdint.h>

#define ADMUX           (*(volatile uint8_t*)(0x7C))
#define ADCSRA          (*(volatile uint8_t*)(0x7A))
#define ADCH            (*(volatile uint8_t*)(0x79))
#define ADCL            (*(volatile uint8_t*)(0x78))


void adc_setup(void);
uint16_t adc_conversion(void);
uint16_t adc_to_volts(uint16_t value);

#endif
