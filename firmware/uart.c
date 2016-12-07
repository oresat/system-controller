/*
    UART driver for ATMega128
    Programmed by William Harrington
 */

#include "uart.h"

static usart_config_t activeCfg;
/*
static bool check_configuration(usart_config_t * cfg){
    switch(cfg->module){
       case UART0:
           if((UBRR0H == ((cfg->baud >> 8) & 0xFF)) &&
              (UBRR0L == ((cfg->baud) & 0xFF)) &&
              ((UCSR0B >> RXEN) & 0x1) &&
              ((UCSR0B >> TXEN) & 0x1) &&
              ((UCSR0C >> USBS) & 0x1) &&
              ((UCSR0C >> UCSZ0) & 0x1)
              ){
               return true;
           }
           else return false;
       case UART1:
           if((UBRR1H == ((cfg->baud >> 8) & 0xFF)) &&
              (UBRR1L == ((cfg->baud) & 0xFF)) &&
              ((UCSR1B >> RXEN) & 0x1) &&
              ((UCSR1B >> TXEN) & 0x1) &&
              ((UCSR1C >> USBS) & 0x1) &&
              ((UCSR1C >> UCSZ0) & 0x1)
              ){
               return true;
           }
           else return false;
       case USART0:
           if((UBRR0H == ((cfg->baud >> 8) & 0xFF)) &&
              (UBRR0L == ((cfg->baud) & 0xFF)) &&
              ((UCSR0B >> RXEN) & 0x1) &&
              ((UCSR0B >> TXEN) & 0x1) &&
              ((UCSR0C >> USBS) & 0x1) &&
              ((UCSR0C >> UCSZ0) & 0x1) &&
              ((UCSR0C >> 6) & 0x1)
              ){
               return true;
           }
           else return false;
       case USART1:
           if(UBRR1H == ((cfg->baud >> 8) & 0xFF) &&
              (UBRR1L == ((cfg->baud) & 0xFF)) &&
              ((UCSR1B >> RXEN) & 0x1) &&
              ((UCSR1B >> TXEN) & 0x1) &&
              ((UCSR1C >> USBS) & 0x1) &&
              ((UCSR1C >> UCSZ0) & 0x1) &&
              ((UCSR1C >> 6) & 0x1)
              ){
               return true;
           }
           else return false;
       default:
           return false;
    }
}
*/
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
           //UCSR0B = (1<<RXEN) | (1<<TXEN);
           //UCSR0C = (1<<USBS)|(3<<UCSZ0);
           //return check_configuration(cfg);
       case UART1:
           UBRR1H = (cfg->baud >> 8) & 0xFF;
           UBRR1L = cfg->baud & 0xFF;
           return (setBit(&UCSR1B, RXEN) &&
                   setBit(&UCSR1B, TXEN) &&
                   setBit(&UCSR1C, USBS) &&
                   setBit(&UCSR1C, UCSZ0) &&
                   UBRR1H == ((cfg->baud >> 8) & 0xFF) &&
                   UBRR1L == ((cfg->baud) & 0xFF));
           //UCSR1B = (1<<RXEN) | (1<<TXEN);
           //UCSR1C = (1<<USBS)|(3<<UCSZ0);
           //return check_configuration(cfg);
       case USART0:
           UBRR0H = (cfg->baud >> 8) & 0xFF;
           UBRR0L = cfg->baud & 0xFF;
           return (setBit(&UCSR0B, RXEN) &&
                   setBit(&UCSR0B, TXEN) &&
                   setBit(&UCSR0C, USBS) &&
                   setBit(&UCSR0C, UCSZ0) &&
                   UBRR0H == ((cfg->baud >> 8) & 0xFF) &&
                   UBRR0L == ((cfg->baud) & 0xFF));
           //UCSR0B = (1<<RXEN) | (1<<TXEN);
           //UCSR0C = (1<<6)|(1<<USBS)|(3<<UCSZ0);
           //return check_configuration(cfg);
       case USART1:
           UBRR1H = (cfg->baud >> 8) & 0xFF;
           UBRR1L = cfg->baud & 0xFF;
           return (setBit(&UCSR1B, RXEN) &&
                   setBit(&UCSR1B, TXEN) &&
                   setBit(&UCSR1C, USBS) &&
                   setBit(&UCSR1C, UCSZ0) &&
                   UBRR1H == ((cfg->baud >> 8) & 0xFF) &&
                   UBRR1L == ((cfg->baud) & 0xFF));
           //UCSR1B = (1<<RXEN) | (1<<TXEN);
           //UCSR1C = (1<<6)|(1<<USBS)|(3<<UCSZ0);
           //return check_configuration(cfg);
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
