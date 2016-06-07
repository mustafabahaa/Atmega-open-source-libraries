/* -------------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** spi.c
** this is the functions implementations of Serial Peripheral interface ( SPI ) 
** please head to spi_config.h to choose configurations and spi.h to see prototypes
** library 
**
** Author: <Mustafa Bahaa>
** -----------------------------------------------------------------------------*/

#include "spi.h"
#include "spi_config.h"

void SPI_Init(void)
{
	#if SPI_MASTER
	/* Set MOSI and SCK output and SS ,MISO input */
	SET_BIT(DDR_SPI,DD_MOSI);
	SET_BIT(DDR_SPI,DD_SCK);
	SET_BIT(DDR_SPI,DD_SS);
	CLR_BIT(DDR_SPI,DD_MISO);
	
	/* Enable SPI, Master*/
	SPCR |= (1<<SPE) | (1<<MSTR);
	
	#elif SPI_SALVE
	/* Set MISO output, all others input */
	SET_BIT(DDR_SPI,DD_MISO);
	CLR_BIT(DDR_SPI,DD_SCK);
	CLR_BIT(DDR_SPI,DD_MOSI);
	CLR_BIT(DDR_SPI,DD_SS);
	
	/* Enable SPI */
	SPCR = (1<<SPE);
	
	#endif  /* SPI MODE */
	
	/*choose sck_frequancy*/
	#if SCK_FREQUANCY_FOC_4
	/* default */
	#elif SCK_FREQUANCY_FOC_16
	SPCR |= (1<<SPR0);
	
	#elif SCK_FREQUANCY_FOC_64
	SPCR |= (1<<SPR1);
	
	#elif SCK_FREQUANCY_FOC_128
	SPCR |= (1<<SPR0) | (1<SPR1);
	
	#elif SCK_FREQUANCY_FOC_2
	SPSR |= (1<<SPI2X);
	
	#elif SCK_FREQUANCY_FOC_8
	SPSR |= (1<<SPI2X);
	SPCR |= (1<<SPR0);
	
	#elif SCK_FREQUANCY_FOC_32
	SPSR |= (1<<SPI2X);
	SPCR |= (1<<SPR1);
	
	#elif SCK_FREQUANCY_FOC_64
	SPSR |= (1<<SPI2X);
	SPCR |= (1<<SPR1) | (1<<SPR0);
	
	#endif /* sck speed */
}

void SPI_SendByte (s8_t data)   
{                    
	SPDR = data;
	
	/* check if operation of transmit or receive is running */
	while (bit_is_clear(SPSR,SPIF));   
	
}                     

s8_t SPI_Receive_Byte() 
{                     
	/* check if operation of transmit or receive is running */
	while (bit_is_clear(SPSR,SPIF));   
	return SPDR;
	
}                 

s8_t SPI_SwapByte()       
{                      
	 /* send 0XFF to salve to shift all the 8 bits in the data buffer
	    in the slave and receive it at the master , if you don't 
		understand this please read more on SPI communication protocol */
	SPI_SendByte(DUMB);  
	
	/* receive the value you wanted from slave */
	return SPI_Receive_Byte();   
}                        