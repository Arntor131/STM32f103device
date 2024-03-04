#include "delay.h"


uint64_t coreSystemTimeMilliseconds = 0;

void(*systemTickFunc)(void);

//Init System timer to implement delay function
void DelayTimer_Init(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

	NVIC_EnableIRQ(TIM2_IRQn);

	TIM2->PSC = 720;
	TIM2->ARR = 100;

	TIM2->DIER |= TIM_DIER_UIE;
	TIM2->CR1 |= TIM_CR1_CEN;
}

extern uint64_t systemTimeStamp;

//Timer 3 Interrupt handler
void TIM3_IRQHandler(void)
{
	if(TIM3->SR & TIM_SR_UIF)
	{
		TIM3->SR &= ~TIM_SR_UIF;
	}

	systemTimeStamp++;
}


uint64_t getSystemTime(void)
{
	return coreSystemTimeMilliseconds;
}

void _delay_ms(uint32_t delayTime)
{
	static uint64_t time = 0;

	time = systemTimeStamp;

	while((systemTimeStamp - time) < delayTime);

}
