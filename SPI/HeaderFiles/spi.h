/* -------------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** spi.h
** this is the header file of spi.c contain all the functions brief 
** description and prototypes.
**
** Author: <Mustafa Bahaa>
** -----------------------------------------------------------------------------*/

#include <avr/io.h>
#include "StandardTypes.h"
#include "macros.h"

#ifndef SPI_H_
#define SPI_H_


/* -- Global -----------------------------------------------------------------
** SPI_Init()
**
** parameters: void
** return : void
**
** -- implementation ---------------------------------------------------------
** this function is used to initialize SPI if it is in master mode or slave
** mode also specify the sck_freuqncy please go to to spi_config.h to adjust
** these operations.
** -------------------------------------------------------------------------*/
void SPI_Init(void);






/* -- Global -----------------------------------------------------------------
** SPI_SendByte()
**
** parameters: s8_t data
** return : void
**
** -- implementation ---------------------------------------------------------
** this function handles the sending operation with SPI protocol.
** -------------------------------------------------------------------------*/
void SPI_SendByte (s8_t data);





/* -- Global -----------------------------------------------------------------
** SPI_Receive_Byte()
**
** parameters: void
** return : s8_t
**
** -- implementation ---------------------------------------------------------
** this function handles the receiving operation with SPI protocol.
** -------------------------------------------------------------------------*/
s8_t SPI_Receive_Byte();


/* -- Global -----------------------------------------------------------------
** SPI_SwapByte()
**
** parameters: void
** return : s8_t
**
** -- implementation ---------------------------------------------------------
** this function returns the 8 bits in the slave buffer by sending 
** dumb useless 8 bits to the buffer.
** -------------------------------------------------------------------------*/
s8_t SPI_SwapByte() ;

#endif /* SPI_H_ */