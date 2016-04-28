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
#define RECEIVER_ENABLE		0x10
#define TRANSMITTER_ENABLE	0x08
#define UCSR0B_CHAR_SIZE_MASK	0x08

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

struct uart_options {
	uint8_t double_baud;
	uint8_t char_size;
	uint8_t stop_bits;
	uint8_t parity;
	uint16_t baud_rate;
};

void uart_init(struct uart_options);
void get_char(uint8_t * recv_char);
void put_char(uint8_t * send_char);
void put_char_9(int * send_val);


#endif /* USART_H_ */