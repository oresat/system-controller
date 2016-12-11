/*****************************************************
 * System Controller for ORESAT Sputnik C3 module    *
 * The system controller is designed to reset the    *
 * low gain radio and payload if a latch up event    *
 * is detected.					     *
 * This controller firmware resets a countdown timer *
 * whenever a 'G' is received by the uart. If a 'G'  *
 * isn't received in time, the timer interrupt will  * 
 * run the reset_lgr routine. 			     *
 * Originally programmed by Michael Mathis	     *
 * Refactored and maintained by William Harrington   *
 *****************************************************/

#include <avr/io.h>
#include <util/delay.h>
//#define F_CPU 8000000UL add this to your util/delay.h to get rid of compiler warning

#include <avr/interrupt.h>
#include "uart.h"
#include "port.h"
#include "adc.h"
#include "i2c.h"
#include <stdlib.h>
#include "debug.h"
#include "timer.h"

/* uart configuration */
usart_config_t usart_cfg = {
    .module = UART0,
    .baud = 51, //9600
    .mode = MODE_8_BIT
};

/* timer configuration */
timer_cfg_t timer_cfg = {
    .clk_divider = 0x5,
    .compare_val = 0xFA0,
    .interrupt_mask = 0x10,
};

enum efuse {VCB0_EN = (uint8_t)'1',
	    VCB1_EN,
	    VCB2_EN,
	    VCB3_EN,
	    VCB4_EN,
	    VCB5_EN,
	    VCB6_EN,
	    VCB7_EN
	   };

bool reset_lgr(void){
    //critical task, must be performed, disable interrupts
    cli();
    
	//Pull PORTA pins 0 and 1 down for 2 seconds then reset the timer count
    uint8_t i;
    for(i = 0; i < 2; i++){
        if(!toggle_pin(&PORTA, i, OFF)){
            return false;
        }
    }
	_delay_ms(2000);
    for(i = 0; i < 2; i++){
        if(!toggle_pin(&PORTA, i, ON)){
            return false;
        }
    }

    //reset the counter
	TCNT1 = 0x0000;

    //allow for interrupts again
    sei();

    return true;
}

bool start_periph(){
    return (gpio_init() &&
            usart_init(&usart_cfg) &&
            adc_init() &&
            i2c_init() &&
            timer_init(&timer_cfg));
}

int main (void){
    #if DEBUG_UART_TX
    testTxUART();
    #endif
    #if DEBUG_MAIN
    unsigned char data = 'G';
    #endif

    if(!start_periph()){
        trap(STAGE1);
    }
	sei(); //Enable global interrupts
	
	while (1) {
        #if DEBUG_MAIN
   		_delay_ms(500);
        if(!put_char(data)){
            trap(STAGE2);
        }
        toggle_pin(&PORTF, pin0, TOGGLE);
        #endif
	}
	return 0;
}

ISR(TIMER1_COMPA_vect){
	//Timer 1 compare register A interrupt handler
	if(!reset_lgr()){
        trap(STAGE2);
    }
}

ISR(USART0_RX_vect){
	//UART receive interrupt handler
	unsigned char * data;
	get_char(data);
	if ((*data) == 'G'){		//Test against lgr's I'm alive signal
		TCNT1 = 0x0000;		//Reset timer count
	}
	switch(*data){			//Toggle port f pins
		case VCB0_EN: 
			toggle_pin(&PORTA, pin7, TOGGLE);
            break;
		case VCB1_EN: 
			toggle_pin(&PORTA, pin6, TOGGLE);
            break;
		case VCB2_EN: 
			toggle_pin(&PORTA, pin5, TOGGLE);
            break;
		case VCB3_EN: 
            toggle_pin(&PORTA, pin4, TOGGLE);
            break;
		case VCB4_EN: 
            toggle_pin(&PORTA, pin3, TOGGLE);
            break;
		case VCB5_EN: 
            toggle_pin(&PORTA, pin2, TOGGLE);
            break;
		case VCB6_EN: 
            toggle_pin(&PORTA, pin1, TOGGLE);
            break;
		case VCB7_EN: 
            toggle_pin(&PORTA, pin0, TOGGLE);
            break;
	}

	//Echo the RX data back for analysis
	put_char(*data);
}

//General interrupt handler, do nothing if we get stray interrupts
EMPTY_INTERRUPT(BADISR_vect);
