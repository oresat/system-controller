#include "port.h"

static bool checkToggle(uint8_t * last, volatile uint8_t * reg, uint8_t bit){
    uint8_t current = *reg;
    if((*last) != current){
        return true;
    }
    else{
        return false;
    }
}

static bool checkSet(volatile uint8_t * reg, uint8_t bit){
    return (((*reg) >> bit) & 0x1);
}

static bool checkClear(volatile uint8_t * reg, uint8_t bit){
    return !(((*reg) >> bit) & 0x1);
}

bool toggleBit(volatile uint8_t * reg, uint8_t bit){
    uint8_t last = *reg;
    *reg ^= (1 << bit);
    return checkToggle(&last, reg, bit);
}

bool setBit(volatile uint8_t * reg, uint8_t bit){
    *reg |= (1 << bit);
    return checkSet(reg, bit);
}

bool clearBit(volatile uint8_t * reg, uint8_t bit){
    *reg &= ~(1 << bit);
    return checkClear(reg, bit);
}

bool toggle_pin(volatile uint8_t * port, uint8_t pin, pin_mode_t mode){
    //volatile uint8_t last, current;

	/* only accept PORTx registers */
	if((port != &PORTA) &&
	   (port != &PORTB) &&
	   (port != &PORTC) &&
	   (port != &PORTD) &&
	   (port != &PORTE) &&
	   (port != &PORTF) &&
	   (port != &PORTG)) return false;

    //last = (*port) & pin;
    
	switch(mode){
		case TOGGLE:
            return toggleBit(port, pin);
			//*port ^= pin;
            //current = (*port) & pin;
            //if(current != last) return true;
            //else return false;
            //break;
		case ON:
            return setBit(port, pin);
			//*port |= pin;
            //if((*port) & pin) return true;
            //else return false;
            //break;
		case OFF:
            return clearBit(port, pin);
			//*port &= ~pin;
            //if(!((*port) & pin)) return true;
            //else return false;
            //break;
        default: return false;
        }
}

bool set_io_direction(volatile uint8_t * reg, uint8_t pin, data_direction_t dir){
	/* only accept DDRx registers */
	if((reg != &DDRA) &&
           (reg != &DDRB) &&
     	   (reg != &DDRC) &&
     	   (reg != &DDRD) &&
           (reg != &DDRE) &&
           (reg != &DDRF) &&
           (reg != &DDRG)) return false;
	switch(dir){
		case INPUT:
            return clearBit(reg, pin);
			//*reg &= ~pin;
            //if(!((*reg) & pin)) return true;
            //else return false;
		case OUTPUT:
            return setBit(reg, pin);
			//*reg |= pin;
            //if((*reg) & pin) return true;
            //else return false;
        default: return false;
    }
}

bool gpio_init(void){
	//Setup the GPIO pins to output and sets initial value

	/* PORTA */

	/* efuse enable pins */
	if(!toggle_pin(&PORTA, pinALL, ON)){
        return false;
    }
	if(!set_io_direction(&DDRA, pinALL, OUTPUT)){
        return false;
    }

	/* PORTC */

	/* efuse fault indicator pins */
    if(!toggle_pin(&PORTC, pinALL, OFF)){
        return false;
    }
	if(!set_io_direction(&DDRC, pinALL, INPUT)){
        return false;
    }

	/* PORTD */

    /* MUX address pins */
    if(!toggle_pin(&PORTD, (pin6 | pin5 | pin4), OFF)){
        return false;
    }
	if(!set_io_direction(&DDRD, pinALL, OUTPUT)){
        return false;
    }

	/* PORTF */

    /* MUX Output voltage */
	if(!toggle_pin(&PORTF, pin0, OFF)){
        return false;
    }
	if(!set_io_direction(&DDRF, pin0, INPUT)){
        return false;
    }

    /* PORTA */
    //set_io_direction(&DDRA, pin0, OUTPUT);
    return true;
}
