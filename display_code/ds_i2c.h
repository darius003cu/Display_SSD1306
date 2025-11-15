#ifndef DS_I2C_H
#define DS_I2C_H

#include <stdint.h>

#define TWBR            (*(volatile uint8_t*)(0xB8))
#define TWCR            (*(volatile uint8_t*)(0xBC))
#define TWSR            (*(volatile uint8_t*)(0xB9))
#define TWDR            (*(volatile uint8_t*)(0xBB))
#define START           0
#define STOP            1

void i2c_send(uint8_t state, uint8_t package[], uint8_t length_of_package);

#endif
