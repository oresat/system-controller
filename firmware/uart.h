/*
 * uart.h
 *
 * Created: 4/27/2016 6:26:34 PM
 *  Author: michael
 */ 


#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <avr/io.h>

//UCSR0A Configuration
#define DOUBLE_BAUD	0x2

//UCSR0B Configuration
#define RECEIVER_ENABLE		1 << RXEN
#define TRANSMITTER_ENABLE	1 << TXEN
#define UCSR0B_CHAR_SIZE_MASK	1 << 3
#define TX_INTERRUPT_ENABLE     1 << RXCIE
#define RX_INTERRUPT_ENABLE     1 << TXCIE

//UCSR0C Configuration
#define NO_PARITY			0x00
#define EVEN_PARITY			0x20
#define ODD_PARITY			0x30

#define ONE_STOP_BIT		0x00
#define TWO_STOP_BITS		0x08

#define CHAR_SIZE_5			0x00
#define CHAR_SIZE_6			0x02
#define CHAR_SIZE_7			0x04
#define CHAR_SIZE_8			0x06
#define CHAR_SIZE_9			0x0E
#define UCSR0C_CHAR_SIZE_MASK	0x06


/*
				fosc = 8MHz
			U2X = 0			U2X = 1		Double baudrate setting
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
struct uart_options {
	uint8_t double_baud;	//Doubles the baud rate
	uint8_t char_size;		//Char size 5,6,7,8,9 bits
	uint8_t stop_bits;		//Number of stop bits, 1 or 2
	uint8_t parity;			//Odd, even, or no parity
	uint16_t baud_rate;		//Baudrate 
};

void uart0_init(struct uart_options);
void uart0_get_char(uint8_t * recv_char);
void uart0_put_char(uint8_t * send_char);
void uart0_put_char_9(int * send_val);

void uart1_init(struct uart_options);
void uart1_get_char(uint8_t * recv_char);
void uart1_put_char(uint8_t * send_char);
void uart1_put_char_9(int * send_val);


#endif /* USART_H_ */
