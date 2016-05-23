/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
**  keypad.c
**  This is the header file of keypad.h libary please go to keypadconfig.h
**  to understand how to configure your keypad 
**
** Author: Mustafa Bahaa
** -------------------------------------------------------------------------*/

#ifndef KEYPAD_H_
#define KEYPAD_H_

# define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "StandardTypes.h"
#include "macros.h"
#include <stdlib.h>


/* -- Global -----------------------------------------------------------------
**  getKey()
**
**  paramters : void 
**  return    : s8_t
** -- implementation ---------------------------------------------------------
**  this function loops the coloumns and rows of an keypad and return the 
**  keypressed at the intersection between the column and raw pressed , 
**  configure the wanted character to be returned from the matrix at 
**  keypadconfig.h , this function returns a s8_t characters value in
**  you can directly print it on LCD or to use the value as a integer 
**  you have to convert it back to integer.
** -------------------------------------------------------------------------
** important 
** -------------------------------------------------------------------------
** the function will return 0XFF when no key pressed 
** the function will return the pressed key as a character if key pressed
** -------------------------------------------------------------------------*/
s8_t getKey();


#endif /* KEYPAD_H_ */