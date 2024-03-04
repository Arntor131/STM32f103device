#ifndef STM32F10X_TIM_H
#define STM32F10X_TIM_H

#include "stm32f10x.h"

extern uint64_t _systemUpTime_ms;

void _init_timeBase(void);

void _delay_ms(uint64_t ms);
uint64_t _getSystemUpTime_ms(void);

#endif
