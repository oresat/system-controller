/*
 * uart.c
 *
 * Created: 4/27/2016 6:26:03 PM
 *  Author: michael
 */ 

 #include "uart.h"
 
 /*
	Sets all the asyncronous options for the USART

	uart_options struct defined and explained in uart.h
 */
 void uart_init(struct uart_options options){
	UCSR0A |= options.double_baud;
	UCSR0B |= (TRANSMITTER_ENABLE | RECEIVER_ENABLE | 
		(options.char_size & UCSR0B_CHAR_SIZE_MASK));
	UCSR0C = options.parity + ONE_STOP_BIT + 
		(options.char_size & UCSR0C_CHAR_SIZE_MASK);
	UBRR0H = (options.baud_rate >> 8) & 0x0F;
	UBRR0L = options.baud_rate & 0xFF;
 }


/*
	Writes a single character to the UART out
*/
 void put_char(uint8_t * send_char){
	//This function was adapted from the Atmel ATmega128/ATmega128L datasheet
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE)) );
	/* Put data into buffer, sends the data */
	UDR0 = *send_char;
 }

/*
	There is a special protocol for sending and reading 9 bit characters
*/
 void put_char_9(int * send_val){
	 //This function was adapted from the Atmel ATmega128/ATmega128L datasheet
	 /* Copy 9th bit to TXB8 */
	 UCSR0B &= ~(1<<TXB8);
	 if ( *send_val & 0x0100 )
	 UCSR0B |= (1<<TXB8);
	 /* Put data into buffer, sends the data */
	 UDR0 = *send_val & 0xFF;
 }
