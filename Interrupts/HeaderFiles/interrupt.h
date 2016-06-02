/* -------------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
**  interrupt.h
**  this is the header file of the interrupt library include interrupt this 
**  library and go to interrupt.c and put your interrupt there.
**
** Author: <Mustafa Bahaa>
** -----------------------------------------------------------------------------*/

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "macros.h"
#include "StandardTypes.h"
#include <avr/interrupt.h>
#include <string.h>


/* -- Global -----------------------------------------------------------------
** interrupt_intialization.h()
**
**  paramters : void 
**  return    : void

** -- implementation ---------------------------------------------------------
**  this function intialize the nessassry control bits to enable the interrupt
**  global flag and every nessassry registers you have the abality to pass
**  interrupt number (INT0,INT1,INT2) and head to the c file to implemennt your 
**  interrupt immediatly.
** -------------------------------------------------------------------------*/
void interrupt_intialization();

#endif /* INTERRUPT_H_ */