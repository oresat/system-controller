#ifndef _TIMER_H_
#define _TIMER_H_

#include "port.h"

typedef struct{
    uint8_t clk_divider;
    uint16_t compare_val;
    uint8_t interrupt_mask;
} timer_cfg_t;

bool timer_init(timer_cfg_t * cfg);

#endif
