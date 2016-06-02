/* -------------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** macros.h
** this is the most common macros and defines
**
** Author: <Mustafa Bahaa>
** -----------------------------------------------------------------------------*/


#ifndef INCFILE1_H_
#define INCFILE1_H_


#define SET_BIT(var,bit)    ( var|= (1<<bit) )  // Define SET BIT macro
#define CLR_BIT(var,bit)    ( var&=~(1<<bit) )  // Define CLR BIT macro
#define TOGGLE_BIT(var,bit) ( var^=(1<<bit)  )  // Define Toggle macro


#define ALL_INPUT    0x00
#define ALL_OUTPUT   0xFF
#define ALL_PORT_ON  0xFF
#define ALL_PORT_OFF 0x00


#endif /* INCFILE1_H_ */