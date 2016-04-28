/*
 * uart.c
 *
 * Created: 4/27/2016 6:26:03 PM
 *  Author: michael
 */ 

 #include "uart.h"
 
 /*
 
				fosc = 8MHz
			U2X = 0			U2X = 1
 +----------+------+-------+------+-------+
 | BaudRate | UBRR | Error | UBRR | Error |
 +----------+------+-------+------+-------+
 | 2400     | 207  | 0.2%  | 416  | -0.1% |
 | 4800     | 103  | 0.2%  | 207  | 0.2%  |
 | 9600     | 51   | 0.2%  | 103  | 0.2%  |
 | 14.4k    | 34   | -0.8% | 68   | 0.6%  |
 | 19.2k    | 25   | 0.2%  | 51   | 0.2%  |
 | 28.8k    | 16   | 2.1%  | 34   | -0.8% |
 | 38.4k    | 12   | 0.2%  | 25   | 0.2%  |
 | 57.6k    | 8    | -3.5% | 16   | 2.1%  |
 | 76.8k    | 6    | -7.0% | 12   | 0.2%  |
 | 115.2k   | 3    | 8.5%  | 8    | -3.5% |
 | 230.4k   | 1    | 8.5%  | 3    | 8.5%  |
 | 250k     | 1    | 0.0%  | 3    | 0.0%  |
 | 0.5M     | 0    | 0.0%  | 1    | 0.0%  |
 | 1M       | –    | –     | 0    | 0.0%  |
 +----------+------+-------+------+-------+
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

 void put_char(uint8_t * send_char){
	//This function was adapted from the Atmel ATmega128/ATmega128L datasheet
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE)) );
	/* Put data into buffer, sends the data */
	UDR0 = *send_char;
 }

 void put_char_9(int * send_val){
	 //This function was adapted from the Atmel ATmega128/ATmega128L datasheet
	 /* Copy 9th bit to TXB8 */
	 UCSR0B &= ~(1<<TXB8);
	 if ( *send_val & 0x0100 )
	 UCSR0B |= (1<<TXB8);
	 /* Put data into buffer, sends the data */
	 UDR0 = *send_val & 0xFF;
 }
