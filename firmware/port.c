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
    /* only accept PORTx registers */
    if((port != &PORTA) &&
       (port != &PORTB) &&
       (port != &PORTC) &&
       (port != &PORTD) &&
       (port != &PORTE) &&
       (port != &PORTF) &&
       (port != &PORTG)) return false;
    
    switch(mode){
        case TOGGLE:
            return toggleBit(port, pin);
        case ON:
            return setBit(port, pin);
        case OFF:
            return clearBit(port, pin);
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
        case OUTPUT:
            return setBit(reg, pin);
        default: return false;
    }
}

bool gpio_init(void){
    //Setup the GPIO pins to output and sets initial value
    
    /* PORTA */
    
    /* efuse enable pins */
    uint8_t i;
    for(i = 0; i < 8; i++){
        if(!toggle_pin(&PORTA, i, ON)){
            return false;
        }
    }
    for(i = 0; i < 8; i++){
        if(!set_io_direction(&DDRA, i, OUTPUT)){
            return false;
        }
    }
    
    /* PORTC */
    
    /* efuse fault indicator pins */
    for(i = 0; i < 8; i++){
        if(!toggle_pin(&PORTC, i, OFF)){
            return false;
        }
    }
    for(i = 0; i < 8; i++){
        if(!set_io_direction(&DDRC, i, INPUT)){
            return false;
        }
    }
    
    /* PORTD */
    
    /* MUX address pins */
    for(i = 4; i < 7; i++){
        if(!toggle_pin(&PORTD, i, OFF)){
            return false;
        }
    }
    for(i = 4; i < 7; i++){
        if(!set_io_direction(&DDRD, i, OUTPUT)){
            return false;
        }
    }
    
    /* PORTF */
    
    /* MUX Output voltage */
    if(!toggle_pin(&PORTF, pin0, OFF)){
        return false;
    }
    if(!set_io_direction(&DDRF, pin0, INPUT)){
        return false;
    }
    
    /* PORTG */
    
    /* nuclear option pins */
    for(i = 0; i < 3; i++){
        if(!toggle_pin(&PORTG, i, OFF)){
            return false;
        }
    }
    for(i = 0; i < 3; i++){
        if(!set_io_direction(&DDRG, i, OUTPUT)){
            return false;
        }
    }
    return true;
}
