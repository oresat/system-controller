#include "debug.h"

void trap(trap_stage_t stage){
    DDRA = (1 << stage);
    PORTA = 0x0;
    while(1){
        PORTA ^= (1 << stage);
        _delay_ms(500);
    }
}
