/*
 * Analog-to-digital conversion utility functions
 * Programmed by William Harrington
 */

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include <stdint.h>

void adc_init();
uint16_t adc_read();

#endif
