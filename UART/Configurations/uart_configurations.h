/* -------------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
**  uart_configurations.h
**  this is the configurations file for controlloing universal asynchrnous 
**  reciver transmitter (uart) you have to  set the current setting as your
**  project require , set the required setting as 1 and others are 0 
**
** Author: <Mustafa Bahaa>
** -----------------------------------------------------------------------------*/

  #ifndef UART_CONFIGURATIONS_H_
  #define UART_CONFIGURATIONS_H_

  
  /* Define clock speed and BAUD rate (speed rate) bps*/
  #define F_CPU 1000000UL
  #define BAUD  9600        
  
  /* CHOOSE PARITY MODE */
  #define PARITY_MODE_EVEN     1
  #define PARITY_MODE_ODD      0
  #define PARITY_MODE_DISABLED 0
  
  /*Choose one or two stop bits mode */
  #define ONE_STOP_BIT_MODE 1
  #define TWO_STOP_BIT_MODE 0
  
  /*Choose character size in a frame (width)*/
  #define BIT_5_MODE 0
  #define BIT_6_MODE 0
  #define BIT_7_MODE 0
  #define BIT_8_MODE 1
  


  #endif /* UART_CONFIGURATIONS_H_ */