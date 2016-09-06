#include "port.h"

void gpio_init(void){
	//Setup the GPIO pins to output and sets initial value

	/* PORTA */

	/* efuse enable pins */
	toggle_pin(&PORTA, pinALL, ON);
	set_io_direction(&DDRA, pinALL, OUTPUT);

	/* PORTC */

	/* efuse fault indicator pins */
        toggle_pin(&PORTC, pinALL, OFF);
	set_io_direction(&DDRC, pinALL, INPUT);

	/* PORTD */

        /* MUX address pins */
        toggle_pin(&PORTD, (pin6 | pin5 | pin4), OFF);
	set_io_direction(&DDRD, pinALL, OUTPUT);

	/* PORTF */

        /* MUX Output voltage */
	toggle_pin(&PORTF, pin0, OFF);
	set_io_direction(&DDRF, pin0, INPUT);

}

void toggle_pin(volatile uint8_t * port, uint8_t pin, enum pin_mode mode){
	/* only accept PORTx registers */
	if((port != &PORTA) &&
	   (port != &PORTB) &&
	   (port != &PORTC) &&
	   (port != &PORTD) &&
	   (port != &PORTE) &&
	   (port != &PORTF) &&
	   (port != &PORTG)) return;
	switch(mode){
		case TOGGLE:
			*port ^= pin;
		case ON:
			*port |= pin;
		case OFF:
			*port &= ~pin;
		default: return;
        }
	return;
}

void set_io_direction(volatile uint8_t * reg, uint8_t pin, enum data_direction dir){
	/* only accept DDRx registers */
	if((reg != &DDRA) &&
           (reg != &DDRB) &&
     	   (reg != &DDRC) &&
     	   (reg != &DDRD) &&
           (reg != &DDRE) &&
           (reg != &DDRF) &&
           (reg != &DDRG)) return;
	switch(dir){
		case INPUT:
			*reg &= ~pin;
		case OUTPUT:
			*reg |= pin;
		default: return;
        }
	return;
}
