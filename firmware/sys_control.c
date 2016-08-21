/*****************************************************
 * System Controller for ORESAT Sputnik C3 module    *
 * The system controller is designed to reset the    *
 * low gain radio and payload if a latch up event    *
 * is detected.					     *
 * This controller firmware resets a countdown timer *
 * whenever a 'G' is received by the uart. If a 'G'  *
 * isn't received in time, the timer interrupt will  * 
 * run the reset_lgr routine. 			     *
 * Written by Michael Mathis			     *
 *****************************************************/

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart.h"

//#define F_CPU 8000000UL add this to your util/delay.h to get rid of compiler warning

enum pin_mode {ON, OFF, TOGGLE};
enum data_direction {INPUT, OUTPUT};

void toggle_pin(volatile uint8_t * port, uint8_t pin, enum pin_mode mode){
	/* only accept PORTx registers */
	if((port != &PORTA) |
	   (port != &PORTB) |
	   (port != &PORTC) |
	   (port != &PORTD) |
	   (port != &PORTE) |
	   (port != &PORTF) |
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
	if((reg != &DDRA) |
           (reg != &DDRB) |
     	   (reg != &DDRC) |
     	   (reg != &DDRD) |
           (reg != &DDRE) |
           (reg != &DDRF) |
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


//Pull PORTA pins 0 and 1 down for 2 seconds then reset the timer count
void reset_lgr(void){
	//PORTA &= 0xFC;		//Pull lgr reset line down
	toggle_pin(&PORTA, 0x3, OFF);  //Pull lgr reset line down
	_delay_ms(2000);
	//PORTA |= 0x03;		//Start the lgr again
	toggle_pin(&PORTA, 0x03, ON);   //Start the lgr again
	TCNT1 = 0x0000;			//Reset the count or the countdown will run a long time
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
	uart_init(options);
	UCSR0B |= 0x80;			//Enable RX interrupts
}

//Setup the GPIO pins to output and sets initial value
void gpio_init(void){
	//PORTA = 0x03;		//Output high on PORTA pins 0 and 1
	toggle_pin(&PORTA, 0x3, ON);
	//DDRA = 0x03;		//Output direction for same pins
	set_io_direction(&DDRA, 0x3, OUTPUT);
	//PORTF = 0x00;		//Output value 0 for all portf
        toggle_pin(&PORTF, 0xFF, OFF);
	//DDRF = 0xFF;		//Output enable for PORTF pin 1
	set_io_direction(&DDRF, 0xFF, OUTPUT);
}


int main (void){
	gpio_init();
	usart_init();
	timer_init();
	sei();			//Enable global interrupts
	

	
	while (1) {
		//Toggle an I'm alive LED
		_delay_ms(100);
		//PORTF ^= 0x02;
		toggle_pin(&PORTF, 0x2, TOGGLE);
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
	data = UDR0;			//Read in data
	if (data == 'G'){		//Test against lgr's I'm alive signal
		TCNT1 = 0x0000;		//Reset timer count
	}
	switch(data){			//Toggle port f pins
		case '1': 
			//PORTF ^= 0x1;
			toggle_pin(&PORTF, 0x1, TOGGLE);
		case '2': 
			//PORTF ^= 0x2;
			toggle_pin(&PORTF, 0x2, TOGGLE);
		case '3': 
			//PORTF ^= 0x4;
			toggle_pin(&PORTF, 0x4, TOGGLE);
		case '4': 
                  	//PORTF ^= 0x8;
			toggle_pin(&PORTF, 0x8, TOGGLE);
		case '5': 
                  	//PORTF ^= 0x10;
			toggle_pin(&PORTF, 0x10, TOGGLE);
		case '6': 
                  	//PORTF ^= 0x20;
			toggle_pin(&PORTF, 0x20, TOGGLE);
		case '7': 
                  	//PORTF ^= 0x40;
			toggle_pin(&PORTF, 0x40, TOGGLE);
		case '8': 
                  	//PORTF ^= 0x80;
			toggle_pin(&PORTF, 0x80, TOGGLE);
	}

	//Echo the RX data back for analysis
	put_char(&data);
}

//General interrupt handler, do nothing if we get stray interrupts
EMPTY_INTERRUPT(BADISR_vect);
