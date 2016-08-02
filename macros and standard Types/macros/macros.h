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


#define        SET_BIT(var,bit)			    (var|= (1<<bit))  
#define DOUBLE_SET_BIT(var,bit,bit2)        (var|= (1<<bit) | (1<<bit2))
#define TRIBLE_SET_BIT(var,bit,bit2,bit3)   (var|= (1<<bit) | (1<<bit2) | (1<<bit3))


#define		   CLR_BIT(var,bit)			     (var&=~(1<<bit)) 
#define DOUBLE_CLR_BIT(var,bit,bit2)         (var&=~(1<<bit) & ~(1<<bit2)) 
#define TRIBLE_CLR_BIT(var,bit,bit2,bit3)    (var&=~(1<<bit) & ~(1<<bit2) & ~(1<<bit3))


#define TOGGLE_BIT(var,bit) ( var^=(1<<bit))  


#define ALL_INPUT    0x00
#define ALL_OUTPUT   0xFF
#define ALL_PORT_ON  0xFF
#define ALL_PORT_OFF 0x00


#endif /* INCFILE1_H_ */