#ifndef SPI_H_
#define SPI_H_

#if defined(__cplusplus)
extern "C" {
#endif

#include "stm32f10x.h"

void SPI_SendByte(SPI_TypeDef *SPIx, uint8_t data);
uint8_t SPI_ReadByte(SPI_TypeDef *SPIx);

uint8_t SPI_SendReadByte(SPI_TypeDef *SPIx, uint8_t data);

void SPI_SendData8(SPI_TypeDef *SPIx, uint8_t *buff, uint32_t buffSize);
void SPI_ReadData8(SPI_TypeDef *SPIx, uint8_t *buff, uint8_t buffSize);

#if defined(__cplusplus)
}
#endif

#endif
