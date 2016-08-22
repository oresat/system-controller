/*
 * Port utility functions
 * Programmed by William Harrington
 */

#ifndef PORT_H_
#define PORT_H_

#include <avr/io.h>
#include <stdint.h>

enum pin_mode {ON, OFF, TOGGLE};
enum data_direction {INPUT, OUTPUT};

enum pin_num {pin0 = (1 << 0),
     	      pin1 = (1 << 1),
       	      pin2 = (1 << 2),
       	      pin3 = (1 << 3),
       	      pin4 = (1 << 4),
       	      pin5 = (1 << 5),
    	      pin6 = (1 << 6),
     	      pin7 = (1 << 7),
	      pinALL = 0xFF
};

void gpio_init();
void toggle_pin(volatile uint8_t * port, uint8_t pin, enum pin_mode mode);
void set_io_direction(volatile uint8_t * reg, uint8_t pin, enum data_direction dir);


#endif
