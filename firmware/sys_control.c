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
#include <avr/interrupt.h>
#include "uart.h"
#include "port.h"
#include "adc.h"
#include "i2c.h"
#include <stdlib.h>

//#define F_CPU 8000000UL add this to your util/delay.h to get rid of compiler warning

enum efuse {VCB0_EN = (uint8_t)'1',
	    VCB1_EN,
	    VCB2_EN,
	    VCB3_EN,
	    VCB4_EN,
	    VCB5_EN,
	    VCB6_EN,
	    VCB7_EN
	   };

void reset_lgr(void){
	//Pull PORTA pins 0 and 1 down for 2 seconds then reset the timer count
	toggle_pin(&PORTA, (pin1 | pin0), OFF);  //Pull lgr reset line down
	_delay_ms(2000);
	toggle_pin(&PORTA, (pin1 | pin0), ON);   //Start the lgr again
	TCNT1 = 0x0000;			         //Reset the count or the countdown will run a long time
}

void timer_init(void){
	//Configures the timer enable timer interrupts
	TCCR1B = 0x05;			//Clock divider select  = IO clock/1024
	//OCR1A = 0x3E80;		//Set the compare value to 16000, about 2s if clock is running at 8Mhz
	OCR1A = 0x0FA0;
	TIMSK |= 0x10;			//Enable compare A interrupt
}

void usart_init(){
	//Setup the uart, enable uart RX interrupts
	struct uart_options options = {
		.double_baud = 0,
		.char_size = CHAR_SIZE_8,
		.stop_bits = ONE_STOP_BIT,
		.parity = NO_PARITY,
		.baud_rate = 51,			//9600bps at fosc = 8 MHz
	};
	uart0_init(options);
}

int main (void){
	gpio_init();
	adc_init();
	i2c_init();
	usart_init();
	timer_init();
	sei();			//Enable global interrupts	
	
	while (1) {
		_delay_ms(100);
	}
	return 0;
}

ISR(TIMER1_COMPA_vect){
	//Timer 1 compare register A interrupt handler
	reset_lgr();
}

ISR(USART0_RX_vect){
	//UART receive interrupt handler
	uint8_t data;
	uart0_get_char(&data);
	if (data == 'G'){		//Test against lgr's I'm alive signal
		TCNT1 = 0x0000;		//Reset timer count
	}
	switch(data){			//Toggle port f pins
		case VCB0_EN: 
			toggle_pin(&PORTA, pin7, TOGGLE);
		case VCB1_EN: 
			toggle_pin(&PORTA, pin6, TOGGLE);
		case VCB2_EN: 
			toggle_pin(&PORTA, pin5, TOGGLE);
		case VCB3_EN: 
                  	toggle_pin(&PORTA, pin4, TOGGLE);
		case VCB4_EN: 
                  	toggle_pin(&PORTA, pin3, TOGGLE);
		case VCB5_EN: 
                  	toggle_pin(&PORTA, pin2, TOGGLE);
		case VCB6_EN: 
                  	toggle_pin(&PORTA, pin1, TOGGLE);
		case VCB7_EN: 
                  	toggle_pin(&PORTA, pin0, TOGGLE);
	}

	//Echo the RX data back for analysis
	uart0_put_char(&data);
}

//General interrupt handler, do nothing if we get stray interrupts
EMPTY_INTERRUPT(BADISR_vect);
