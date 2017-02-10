#include "debug.h"

void trap(trap_stage_t stage){
    DDRA = (1 << stage);
    PORTA = 0x0;
    while(1){
        PORTA ^= (1 << stage);
        _delay_ms(500);
    }
}

#if DEBUG_UART_TX
void testTxUART(){
    usart_init(&cfg);
    uint8_t data[3] = {'G', '\r', '\n'};
    uint8_t i;
    if(!set_io_direction(&DDRF, pin0, OUTPUT)){
        trap(STAGE1);
    }
    if(!toggle_pin(&PORTF, pin0, OFF)){
        trap(STAGE2);
    }
    while (1) {
        _delay_ms(500);
        if(!toggle_pin(&PORTF, pin0, TOGGLE)){
            trap(STAGE3);
        }
        for(i=0; i < 3; i++){
            if(!put_char(data[i])){
                trap(STAGE4);
            }
        }
    }
}
#endif

#if DEBUG_ADC
void testADC(){
    usart_config_t usart_cfg = {
    	.module = UART0,
    	.baud = 51, //9600
    	.mode = MODE_8_BIT
    };
    if(!adc_init()){
        trap(STAGE1);
    }
    if(!usart_init(&usart_cfg)){
        trap(STAGE2);
    }
    if(!set_io_direction(&DDRF, pin2, OUTPUT)){
        trap(STAGE3);
    }
    unsigned char data = 'G';
    while(1){
	_delay_ms(500);
        if(!toggle_pin(&PORTF, pin2, TOGGLE)){
            trap(STAGE3);
        }
	uint16_t meas = adc_read();
        unsigned char meas_msb = (meas >> 8) & 0xFF;
        unsigned char meas_lsb = meas & 0xFF;
	if(!put_char(meas_msb) || !put_char(meas_lsb) /*|| !put_char('\r') || !put_char('\n')*/){
		trap(STAGE4);
        }
	//if(!put_char(data) || !put_char('\r') || !put_char('\n')){
        //    trap(STAGE4);
        //}
    }
}
#endif
