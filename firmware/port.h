/*
 * Port utility functions
 * Programmed by William Harrington
 */

#ifndef PORT_H_
#define PORT_H_

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum {ON, OFF, TOGGLE} pin_mode_t;
typedef enum {INPUT, OUTPUT} data_direction_t;

typedef enum {
    pin0,
    pin1,
    pin2,
    pin3,
    pin4,
    pin5,
    pin6,
    pin7
}pin_num_t;

bool toggleBit(volatile uint8_t * reg, uint8_t bit);
bool setBit(volatile uint8_t * reg, uint8_t bit);
bool clearBit(volatile uint8_t * reg, uint8_t bit);
bool toggle_pin(volatile uint8_t * port, uint8_t pin, pin_mode_t mode);
bool set_io_direction(volatile uint8_t * reg, uint8_t pin, data_direction_t dir);
bool gpio_init();


#endif
