#ifndef DEVICE_H_
#define DEVICE_H_

#if defined(__cplusplus)
extern "C" {
#endif

#define STM32F10X

#if defined(STM32F10X)
#include "STM32F10X_GPIO.h"
#include "STM32F10X_SPI.h"
#include "STM32F10X_ADC.h"
#include "STM32F10X_TIM.h"

#define STD_CORE_FREQ 72000000UL

#endif

void STM32_Init(void);

#if defined(__cplusplus)
}
#endif

#endif
