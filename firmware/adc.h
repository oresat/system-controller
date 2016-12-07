/*
 * Analog-to-digital conversion utility functions
 * Programmed by William Harrington
 */

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>
#include "port.h"

bool adc_init();
//void adc_init();
uint16_t adc_read();

#endif
