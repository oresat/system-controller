#ifndef DEBUG_H_
#define DEBUG_H_

#include <util/delay.h>
#include <avr/io.h>
#include "uart.h"
#include "port.h"
#include "adc.h"

#define DEBUG_UART_TX 0
#define DEBUG_MAIN 0
#define DEBUG_ADC 1

typedef enum{
    STAGE1,
    STAGE2,
    STAGE3,
    STAGE4
} trap_stage_t;

void trap(trap_stage_t stage);

#if DEBUG_UART_TX
void testTxUART();
#endif

#if DEBUG_ADC
void testADC();
#endif

#endif
