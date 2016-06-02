/* -------------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
**  ADC.c
**  this is the functions implmentations of the library ADC.H , analog to digital
**  converter are good for audience who are new to micro-controllers and writing
**	libraries , also it contains the 8-bit mode and 10-bit mode 
**
** Author: <Mustafa Bahaa>
** -----------------------------------------------------------------------------*/

#ifndef ADC_H_
#define ADC_H_

#include <avr/io.h>
#include "standardtypes.h"
#include "macros.h"


/* -- Global -----------------------------------------------------------------
** ADC_Intialization.h()
**
**  paramters : void
**  return    : void

** -- implementation ---------------------------------------------------------
**  this function intialize the nessassry control bits to enable analog to 
**  to digital converter and also set the main options and modes in order
**	to operate in best condition 
** -------------------------------------------------------------------------*/
void ADC_Intialization ();




/* -- Global -----------------------------------------------------------------
**  ADC_bit_8_convert()
**
**  paramters : u8_t pinNumber
**  return    : u8_t (8 bit number 0 to 255)
**
** -- implementation ---------------------------------------------------------
**  this function returns a 8-bit number from 0 to 255 after convertion
**  from analog , the data stored in bit ADCH
**  and can work on pins from PA0 to PA7	
** -------------------------------------------------------------------------*/
u8_t ADC_bit_8_convert (u8_t pinNumber);





/* -- Global -----------------------------------------------------------------
**  ADC_bit_10_converter()
**
**  paramters : u8_t pinNumber
**  return    : u16_t (16 bit number)
**
** -- implementation ---------------------------------------------------------
**  this function returns a 16bit number holding but the actual data in it
**  is a 10-bit number from (0 to 1023) represents the conversation from
**  the analog signal , the value are a combination of ADCH and ADCL
**  and can work on pins from PA0 to PA7
** -------------------------------------------------------------------------*/
u16_t ADC_bit_10_convert (u8_t pinNumber);


#endif /* ADC_H_ */