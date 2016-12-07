#ifndef DEBUG_H_
#define DEBUG_H_

#include <util/delay.h>
#include <avr/io.h>

#define DEBUG 0

typedef enum{
    STAGE1,
    STAGE2,
    STAGE3,
    STAGE4
} trap_stage_t;

void trap(trap_stage_t stage);

#endif
