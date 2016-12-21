/*
 Atmega128 UART driver
 Programmed by William Harrington
 */


#ifndef UART_H_
#define UART_H_

#include <stdbool.h>
#include <stdint.h>
#include <avr/io.h>
#include "port.h"

typedef enum{
    UART0,
    UART1,
    USART0,
    USART1
} usart_module_t;

typedef enum{
    MODE_8_BIT,
    MODE_9_BIT
} usart_mode_t;

typedef struct {
    usart_module_t module;
    uint16_t baud;
    usart_mode_t mode;
} usart_config_t;

bool usart_init(usart_config_t * cfg);
bool get_char(unsigned char * ch);
bool put_char(unsigned char ch);
bool println(char * string);

#endif /* USART_H_ */
