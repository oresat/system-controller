/*
	I2C driver
	Programed by William Harrington
 */
#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>
#include <util/twi.h>
#include <stdint.h>
#include <stdbool.h>
#include "port.h"

//void i2c_init();
bool i2c_init();
bool i2c_read(uint8_t slave_addr, uint8_t * dest, uint8_t len);
bool i2c_write(uint8_t slave_addr, uint8_t * data, uint8_t len);

#endif
