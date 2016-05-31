/* -------------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
**  uart.h
**  this is the configurations file for controlloing universal asynchrnous 
**  reciver transmitter (uart) you have to  set the current setting as your
**  project require , set the required setting as 1 and others are 0 
**
** Author: <Mustafa Bahaa>
** -----------------------------------------------------------------------------*/


#ifndef UART_H_
#define UART_H_

#include "standardtypes.h"
#include "macros.h"
#include <avr/io.h>

/* -- Global -----------------------------------------------------------------
** uart_intialization()
**
** paramters: void
** return : void
**
** -- implementation ---------------------------------------------------------
**  this function is used to intialize all the nessaccry control bits of the
**  UART , also every bit is greatly documented for upgrading purposes
** -------------------------------------------------------------------------*/
void uart_intialization();


/* -- Global -----------------------------------------------------------------
** UART_SendByte()
**
** paramters: s8_t data
** return : void
**
** -- implementation ---------------------------------------------------------
**  this function is used to check if the transmitter buffer is busy or not 
**  and if it is not busy , send the new data packet
** -------------------------------------------------------------------------*/
void UART_SendByte (s8_t data);


/* -- Global -----------------------------------------------------------------
** UART_RecieveByte()
**
** paramters: void
** return : s8_t
**
** -- implementation ---------------------------------------------------------
**  this function is used to check if the reciver buffer is ready or not 
**  and if it is not , it recives the new packet.
** -------------------------------------------------------------------------*/
s8_t UART_RecieveByte();



/* -- Global -----------------------------------------------------------------
** UART_SendString()
**
** paramters: s8_t *string
** return : void
**
** -- implementation ---------------------------------------------------------
**  this function is a special function of UART_sendByte because it sends
**  a string instead of charachters 
** -------------------------------------------------------------------------*/
void UART_SendString (s8_t *string);






/* -- Global -----------------------------------------------------------------
** UART_RecieveString()
**
** paramters: void
** return : s8_t*
**
** -- implementation ---------------------------------------------------------
**  this function is a special function of UART_ReciveByte because it 
**  recives a string and save it into character array.
** -------------------------------------------------------------------------*/
s8_t* UART_RecieveString();       


#endif /* UART_H_ */









