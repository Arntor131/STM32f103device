#include "STM32F10X_TIM.h"

uint64_t _systemUpTime_ms = 0;

void _init_timeBase(void)
{
	RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;

	NVIC_EnableIRQ(TIM3_IRQn);

	TIM3->PSC = 720 - 1;
	TIM3->ARR = 100 - 1;

	TIM3->DIER |= TIM_DIER_UIE;

	TIM3->CR1 |= TIM_CR1_CEN;
}

void TIM3_IRQHandler(void)
{
	uint32_t tmp = TIM3->SR;
	tmp &= TIM3->DIER;
	TIM3->SR = 0;

	if(tmp & TIM_SR_UIF)
	{
		_systemUpTime_ms++;
	}
}

void _delay_ms(uint64_t ms)
{
	uint64_t timeStamp = _getSystemUpTime_ms();

	while(_getSystemUpTime_ms() - timeStamp < ms);
}

uint64_t _getSystemUpTime_ms(void)
{
	return _systemUpTime_ms;
}
