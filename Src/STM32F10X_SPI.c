#include "STM32F10X_SPI.h"

void spdelay(void);

void SPI_ClockEn(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_SPI1EN;
	RCC->APB1ENR |= RCC_APB1ENR_SPI2EN;
}


void SPI_MasterInit(SPI_TypeDef *SPIx)
{
	SPIx->CR1 |= SPI_CR1_MSTR | SPI_CR1_SSM | SPI_CR1_SSI;
	SPIx->CR1 |= SPI_CR1_SPE;
}


void SPI_SendByte(SPI_TypeDef *SPIx, uint8_t data)
{
	SPIx->DR = data;
	while(SPIx->SR & SPI_SR_BSY){}
}


uint8_t SPI_ReadByte(SPI_TypeDef *SPIx)
{
	while(!(SPIx->SR & SPI_SR_RXNE));

	return SPIx->DR;
}


uint8_t SPI_SendReadByte(SPI_TypeDef *SPIx, uint8_t data)
{
	while(!(SPIx->SR & SPI_SR_TXE));

	SPIx->DR = data;

	while(!(SPIx->SR & SPI_SR_RXNE));

	return SPIx->DR;
}

void SPI_SendData8(SPI_TypeDef *SPIx, uint8_t *buff, uint32_t buffSize)
{
	while(buffSize--)
	{
		while(!(SPIx->SR & SPI_SR_TXE));
		SPIx->DR = *buff++;
	}

	while(SPIx->SR & SPI_SR_BSY);
}


void SPI_ReadData8(SPI_TypeDef *SPIx, uint8_t *buff, uint8_t buffSize)
{
	while(buffSize--)
	{
		while(!(SPIx->SR & SPI_SR_RXNE));
		*buff++ = SPIx->DR;
	}

	while(SPIx->SR & SPI_SR_BSY);
}

