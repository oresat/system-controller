/*
	ORESAT Sputnik System Controller Module

	Written by Michael Mathis

	Reset a countdown whenever a 'G' is received by the uart
	if a 'G' isn't received in time, the timer interrupt will 
	run the reset_lgr routine
 */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart.h"

//Pull PORTA pins 0 and 1 down for 2 seconds then reset the timer count
void reset_lgr(void){
	PORTA &= 0xFC;		//Pull lgr reset line down
	_delay_ms(2000);
	PORTA |= 0x03;		//Start the lgr again
	TCNT1 = 0x0000; 	//Reset the count or the countdown will run a long time
}

//Sets up the timer
void timer_init(void){
	TCCR1B = 0x05;			//Clock divider select  = IO clock/1024
	//OCR1A = 0x3E80;		//Set the compare value to 16000, about 2s if clock is running at 8Mhz
	OCR1A = 0x0FA0;
	TIMSK |= 0x10;			//Enable compare A interrupt
}

//Setup the uart
void usart_init(){
 struct uart_options options = {
	 .double_baud = 0,
	 .char_size = CHAR_SIZE_8,
	 .stop_bits = ONE_STOP_BIT,
	 .parity = NO_PARITY,
	 .baud_rate = 51,			//9600bps at fosc = 8 MHz
 };
	uart_init(options);
	UCSR0B |= 0x80;			//Enable RX interrupts
}

void gpio_init(void){
	PORTA = 0x03;		//Output high on PORTA pins 0 and 1
	DDRA = 0x03;		//Output direction for same pins
	PORTF = 0x00;		//Output value 0 for all portf
	DDRF = 0x02;		//Output enable for PORTF pin 1
}

int main (void){
	gpio_init();
	usart_init();
	timer_init();
	sei();			//Enable interrupts
	

	/* set all pins of PORTF for output*/
	while (1) {
		_delay_ms(100);
		PORTF ^= 0x02;
	}
	return 0;
}

//Timer 1 compare register A interrupt handler
ISR(TIMER1_COMPA_vect){
	reset_lgr();
}

//UART receive interrupt handler
ISR(USART0_RX_vect){
	uint8_t data;
	data = UDR0;
	if (data == 'G'){
		TCNT1 = 0x0000;
	}


}

//General interrupt handler, do nothing if we get stray interrupts
EMPTY_INTERRUPT(BADISR_vect);