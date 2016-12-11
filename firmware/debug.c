#include "debug.h"

void trap(trap_stage_t stage){
    DDRA = (1 << stage);
    PORTA = 0x0;
    while(1){
        PORTA ^= (1 << stage);
        _delay_ms(500);
    }
}

#if DEBUG
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
