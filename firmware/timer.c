#include "timer.h"

bool timer_init(timer_cfg_t * cfg){
    uint8_t i;
    for(i = 0; i < 8; i++){
        if(((cfg->clk_divider) >> i) & 0x1){
            if(!setBit(&TCCR1B, i)){
                return false;
            }
        }
    }
    OCR1A = cfg->compare_val;
    if(!(OCR1A == (cfg->compare_val))){
        return false;
    }
    for(i = 0; i < 8; i++){
        if(((cfg->interrupt_mask) >> i) & 0x1){
            if(!setBit(&TIMSK, i)){
                return false;
            }
        }
    }
    return true;
}
