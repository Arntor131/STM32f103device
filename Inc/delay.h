#ifndef DELAY_H_
#define DELAY_H_

#include "stm32f10x.h"

void DelayTimer_Init(void);
uint64_t getSystemTime(void);
void _delay_ms(uint32_t delayTime);

#endif
