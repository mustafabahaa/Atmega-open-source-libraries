/* -------------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
**  uart.c
**  this is the functions implmentations of uart.h and uart_configurations.h 
**  please review configuration file to set your settings
**
** Author: <Mustafa Bahaa>
** -----------------------------------------------------------------------------*/

#include "uart.h"
#include "uart_configurations.h"
#include <math.h>


void uart_intialization()
{
	
	/*First we choose asynchronous mode*/
	CLR_BIT(UCSRC,UMSEL);

    /* choosing normal mode or double speed mode*/
    /* the next line choose normal mode */
    CLR_BIT(UCSRA,U2X);

    /* choosing the baud rate of*/
	/* the output value will have decimal values and we only 
	   need integer value we could have cast it but that will
	   give us round to lowest integer and we don't want that
	   we want to round that value to the next integer thats
	   why we use the function lrint from math.h , example 
	   if the value is 25.5 UBBR_value will equal to 26 */
	
	u16_t UBBR_value = lrint((F_CPU / (16L * BAUD) ) - 1);	
	
	/* installing the deduced baud rate into register UBBR
	   and that is done by UBBRH and UBBRL because the value 
	   could be more than 255 (8-bit value) */
	UBRRH = (u8_t) UBBR_value >> 8;
    UBRRL = (u8_t) UBBR_value;	
	
	#if PARITY_MODE_EVEN
	/* set parity mode to even parity */
	CLR_BIT(UCSRC,UPM0);
	SET_BIT(UCSRC,UPM1);
	
	#elif PARITY_MODE_ODD
	/* set parity mode to odd parity */
	SET_BIT(UCSRC,UPM0);
	SET_BIT(UCSRC,UPM1);
	
	#elif PARITY_MODE_DISABLED
	/* set parity mode to no parity */
	CLR_BIT(UCSRC,UPM0);
	CLR_BIT(UCSRC,UPM1);
	#endif
	
	
	/*choose one bit stop or two*/
	#if ONE_STOP_BIT_MODE
	CLR_BIT(UCSRC,USBS);
	#elif TWO_STOP_BIT_MODE
	SET_BIT(UCSRC,USBS);
	#endif
	
	/*choose wide of data*/
	#if BIT_5_MODE
	CLR_BIT(UCSRB,UCSZ0);
	CLR_BIT(UCSRB,UCSZ1);
	CLR_BIT(UCSRB,UCSZ2);
	#elif BIT_6_MODE
	SET_BIT(UCSRB,UCSZ0);
	CLR_BIT(UCSRB,UCSZ1);
	CLR_BIT(UCSRB,UCSZ2);
	#elif BIT_7_MODE
	CLR_BIT(UCSRB,UCSZ0);
	SET_BIT(UCSRB,UCSZ1);
	CLR_BIT(UCSRB,UCSZ2);
	#elif BIT_8_MODE
	SET_BIT(UCSRB,UCSZ0);
	SET_BIT(UCSRB,UCSZ1);
	CLR_BIT(UCSRB,UCSZ2);
	#endif
	
	
	/*finally we enable transmitter and receiver*/
	SET_BIT(UCSRB,RXEN);  
	SET_BIT(UCSRB,TXEN);  
}


void UART_SendByte (s8_t data)        
{                                     
	/* while UDRE is cleared means data is currently 
	   transmitted wait for it to finish transmitting
	*/   
	while (bit_is_clear(UCSRA,UDRE));
	
	/* once it exits the while loop means the data has
	   finished the transmitting and the buffer is ready
	   for a new packet to be transmitted
	*/   
	UDR = data;                       
	
}                                     

s8_t UART_RecieveByte()               
{                                     
	/* while RXC is cleared means data is still 
	   receiving wait for it to finish receiving
	*/   
	while (bit_is_clear(UCSRA,RXC));  
	
	/* once it exits the while loop means the data has
	   finished the receiving and the buffer is ready
	   for a new packet to be received 
	*/   
	return UDR;                      
	
}                                     



void UART_SendString (s8_t *string)        
{                                     
	
	int i=0;
	
	/* because at string end there is a null this while
	   loop will continue to excute until the last of string
	*/  
	while (string[i] != '\0')
	{
		/* while UDRE is cleared means data is currently 
	    transmitted wait for it to finish transmitting
	    */   
		while (bit_is_clear(UCSRA,UDRE));
	    
	/* once it exits the while loop means the data has
	   finished the transmitting and the buffer is ready
	   for a new packet to be transmitted
	*/   
	UDR = string[i]; 
	
	/*the transmitter buffer equal to the current char
	  and increment i for the next time entering this
	  while loop we get the next char in string
	*/  
	i++;
	}                      
	
}       


s8_t * UART_RecieveString()               
{                                     
	int i =0;  
	static s8_t character[100];
	
	/* while RXC is cleared means data is still 
	   receiving wait for it to finish receiving
	*/ 
	while (bit_is_clear(UCSRA,RXC));  
	
	
	/* because at string end there is a null this while
	   loop will continue to execute until the last of string
	*/  
	while (UDR != '\0')
	{
		/* the incoming data will equal to char of array*/
	   character[i] = UDR;
	   
	   /*now increment i to save to next char in array*/ 
	   i++;
	}	
	return character;       
	
}   









   