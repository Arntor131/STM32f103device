#ifndef GPIO_H_
#define GPIO_H_

#include "stm32f10x.h"

#define MODE_CNF_MSK      0b1111

#define MODE_INPUT        0b00
#define MODE_OUTPUT_2MHZ  0b01
#define MODE_OUTPUT_10MHZ 0b10
#define MODE_OUTPUT_50MHZ 0b11

#define CNF_FLOAT         0b0100
#define CNF_PULL          0b1000
#define CNF_ADC           0b0000

#define CNF_OPEN_DRAIN    0b0100
#define CNF_PUSH_PULL     0b0000
#define CNF_AF_PUSH_PULL  0b1000
#define CNF_AF_OPEN_DRAIN 0b1100

typedef enum
{
	GPIO_INPUT_FLOAT = 0,
	GPIO_INPUT_PULLUP,
	GPIO_INPUT_PULLDOWN,
	GPIO_INPUT_ADC,
	GPIO_OUTPUT_OPEN_DRAIN,
	GPIO_OUTPUT_PUSH_PULL,
	GPIO_OUTPUT_AF_OPEN_DRAIN,
	GPIO_OUTPUT_AF_PUSH_PULL
}GpioPinMode_e;

typedef enum
{
	PIN_FREQ_2MHZ = 0,
	PIN_FREQ_10MHZ,
	PIN_FREQ_50MHZ
}GpioPinFreq_e;

void GPIO_ClockInit(void);
void GPIO_ConfigPin(GPIO_TypeDef *GPIOx, uint8_t pin, GpioPinMode_e mode);
void GPIO_SetPin(GPIO_TypeDef *GPIOx, uint8_t pin, uint8_t state);
void GPIO_TogglePin(GPIO_TypeDef *GPIOx, uint8_t pin);
uint8_t GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint8_t pin);


#endif
