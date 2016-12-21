/*
 UART driver for ATMega128
 Programmed by William Harrington
 */

#include "uart.h"

static usart_config_t activeCfg;

static bool uart_init(usart_config_t * cfg){
    activeCfg = *cfg;
    switch(cfg->module){
        case UART0:
            UBRR0H = (cfg->baud >> 8) & 0xFF;
            UBRR0L = cfg->baud & 0xFF;
            return (setBit(&UCSR0B, RXEN) &&
                    setBit(&UCSR0B, TXEN) &&
                    setBit(&UCSR0C, USBS) &&
                    setBit(&UCSR0C, UCSZ0) &&
                    UBRR0H == ((cfg->baud >> 8) & 0xFF) &&
                    UBRR0L == ((cfg->baud) & 0xFF));
        case UART1:
            UBRR1H = (cfg->baud >> 8) & 0xFF;
            UBRR1L = cfg->baud & 0xFF;
            return (setBit(&UCSR1B, RXEN) &&
                    setBit(&UCSR1B, TXEN) &&
                    setBit(&UCSR1C, USBS) &&
                    setBit(&UCSR1C, UCSZ0) &&
                    UBRR1H == ((cfg->baud >> 8) & 0xFF) &&
                    UBRR1L == ((cfg->baud) & 0xFF));
        case USART0:
            UBRR0H = (cfg->baud >> 8) & 0xFF;
            UBRR0L = cfg->baud & 0xFF;
            return (setBit(&UCSR0B, RXEN) &&
                    setBit(&UCSR0B, TXEN) &&
                    setBit(&UCSR0C, USBS) &&
                    setBit(&UCSR0C, UCSZ0) &&
                    setBit(&UCSR0C, 6) &&
                    UBRR0H == ((cfg->baud >> 8) & 0xFF) &&
                    UBRR0L == ((cfg->baud) & 0xFF));
        case USART1:
            UBRR1H = (cfg->baud >> 8) & 0xFF;
            UBRR1L = cfg->baud & 0xFF;
            return (setBit(&UCSR1B, RXEN) &&
                    setBit(&UCSR1B, TXEN) &&
                    setBit(&UCSR1C, USBS) &&
                    setBit(&UCSR1C, UCSZ0) &&
                    setBit(&UCSR1C, 6) &&
                    UBRR1H == ((cfg->baud >> 8) & 0xFF) &&
                    UBRR1L == ((cfg->baud) & 0xFF));
        default:
            return false;
    }
}

bool usart_init(usart_config_t * cfg){
    return uart_init(cfg);
}

bool put_char(unsigned char ch){
    usart_module_t module = activeCfg.module;
    usart_mode_t mode = activeCfg.mode;
    if(module == UART0 || module == USART0){
        if(mode == MODE_8_BIT){
            while (!(UCSR0A & (1<<UDRE)));
            UDR0 = ch;
            while(!((UCSR0A >> 6) & 0x1));
            return true;
        }
        else if(mode == MODE_9_BIT){
            return false;
        }
    }
    else if(module == UART1 || module == USART1){
        if(mode == MODE_8_BIT){
            while (!(UCSR1A & (1<<UDRE)));
            UDR1 = ch;
            while(!((UCSR1A >> 6) & 0x1));
            return true;
        }
        else if(mode == MODE_9_BIT){
            return false;
        }
    }
    return false;
}

bool get_char(unsigned char * ch){
    usart_module_t module = activeCfg.module;
    usart_mode_t mode = activeCfg.mode;
    if(module == UART0 || module == USART0){
        if(mode == MODE_8_BIT){
            while(!(UCSR0A & (1<<RXC)));
            *ch = UDR0;
            return (bool)((UCSR0A >> 7) & 0x1);
        }
        else if(mode == MODE_9_BIT){
            return false;
        }
    }
    else if(module == UART1 || module == USART1){
        if(mode == MODE_8_BIT){
            while(!(UCSR1A & (1<<RXC)));
            *ch = UDR1;
            return (bool)((UCSR1A >> 7) & 0x1);
        }
        else if(mode == MODE_9_BIT){
            return false;
        }
    }
    return false;
}

bool println(char * string){
    while(*string != '\0'){
        if(!put_char(*string++)){
            return false;
        }
    }
    return true;
}
