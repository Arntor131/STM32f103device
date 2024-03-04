#include "STM32F10X_GPIO.h"

void GPIO_ClockInit(void)
{
	RCC->APB2ENR |= (RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN);
}

void GPIO_ConfigPin(GPIO_TypeDef *GPIOx, uint8_t pin, GpioPinMode_e mode)
{
	uint8_t pinOffset;

	if(pin > 15) return;

	if(pin <= 7)
	{
		pinOffset = pin * 4;
		GPIOx->CRL &= ~(MODE_CNF_MSK << (pin*4));

		switch(mode)
		{
			case GPIO_INPUT_FLOAT:
				GPIOx->CRL |= ((MODE_INPUT | CNF_FLOAT) << pinOffset);
				break;

			case GPIO_INPUT_PULLUP:
				GPIOx->CRL |= ((MODE_INPUT | CNF_PULL) << pinOffset);
				GPIOx->ODR |= (1 << pin);
				break;

			case GPIO_INPUT_PULLDOWN:
				GPIOx->CRL |= ((MODE_INPUT | CNF_PULL) << pinOffset);
				GPIOx->ODR &= ~(1 << pin);
				break;

			case GPIO_INPUT_ADC:
				GPIOx->CRL |= ((MODE_INPUT | CNF_ADC) << pinOffset);
				break;

			case GPIO_OUTPUT_OPEN_DRAIN:
				GPIOx->CRL |= ((MODE_OUTPUT_50MHZ | CNF_OPEN_DRAIN) << pinOffset);
				break;

			case GPIO_OUTPUT_PUSH_PULL:
				GPIOx->CRL |= ((MODE_OUTPUT_50MHZ | CNF_PUSH_PULL) << pinOffset);
				break;

			case GPIO_OUTPUT_AF_PUSH_PULL:
				GPIOx->CRL |= ((MODE_OUTPUT_50MHZ | CNF_AF_PUSH_PULL) << pinOffset);
				break;

			case GPIO_OUTPUT_AF_OPEN_DRAIN:
				GPIOx->CRL |= ((MODE_OUTPUT_50MHZ | CNF_AF_PUSH_PULL) << pinOffset);
				break;
		}

		return;
	}
	else if(pin > 7)
	{
		pinOffset = pin * 4 - 32;
		GPIOx->CRH &= ~(MODE_CNF_MSK << ((pin*4) - 32));

		switch(mode)
		{
			case GPIO_INPUT_FLOAT:
				GPIOx->CRH |= ((MODE_INPUT | CNF_FLOAT) << pinOffset);
				break;

			case GPIO_INPUT_PULLUP:
				GPIOx->CRH |= ((MODE_INPUT | CNF_PULL) << pinOffset);
				GPIOx->ODR |= (1 << pin);
				break;

			case GPIO_INPUT_PULLDOWN:
				GPIOx->CRH |= ((MODE_INPUT | CNF_PULL) << pinOffset);
				GPIOx->ODR &= ~(1 << pin);
				break;

			case GPIO_INPUT_ADC:
				GPIOx->CRH |= ((MODE_INPUT | CNF_ADC) << pinOffset);
				break;

			case GPIO_OUTPUT_OPEN_DRAIN:
				GPIOx->CRH |= ((MODE_OUTPUT_50MHZ | CNF_OPEN_DRAIN) << pinOffset);
				break;

			case GPIO_OUTPUT_PUSH_PULL:
				GPIOx->CRH |= ((MODE_OUTPUT_50MHZ | CNF_PUSH_PULL) << pinOffset);
				break;

			case GPIO_OUTPUT_AF_PUSH_PULL:
				GPIOx->CRH |= ((MODE_OUTPUT_50MHZ | CNF_AF_PUSH_PULL) << pinOffset);
				break;

			case GPIO_OUTPUT_AF_OPEN_DRAIN:
				GPIOx->CRH |= ((MODE_OUTPUT_50MHZ | CNF_AF_PUSH_PULL) << pinOffset);
				break;
		}
	}
	else
	{
		return;
	}
}

void GPIO_SetPin(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t state)
{
	if(pin > 15) return;

	if(state == 0)
	{
		GPIOx->BSRR = (1<<(pin + 16));
	}
	else
	{
		GPIOx->BSRR = (1<<pin);
	}
}

void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint8_t pin)
{
	if(pin > 15) return;

	GPIOx->ODR ^= (1 << pin);
}

uint8_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint8_t pin)
{
	if(pin > 15) return 255;

	if(GPIOx->IDR & (1 << pin)) return 1;
	else return 0;
}
