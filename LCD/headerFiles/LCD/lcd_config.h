/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** <LCD.h
** <This is the configurations file for LCD to quickly adjust the pins 
    just like your pin configuration without changing the code over and over>
**
** Author: <Mustafa Bahaa>
** -------------------------------------------------------------------------*/


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/* LCD port configurations */

#define LCD_PORT PORTC
#define LCD_DDR  DDRC


/* LCD mode configuration */
/* to use the mode make it 1 and make the other 0 
** the main advantge of the 4 bit mode is to save 
** valuable microntrollers pin insted of using 8 
** pins you only use 4 pins , but this comes with
** the cost of less speed because you consume 
** more cycles than 8 bit mode cycles , hence
** 4 bit mode ( slow , less pins )
** 8 bit mode ( fast , more pins )
*/

#define BIT_4_MODE 1
#define BIT_8_MODE 0


#if BIT_8_MODE 
/* control pins configurations if 8 bit mode */
#define LCD_Control_PORT PORTD
#define LCD_Control_DDR  DDRD
#define RS PD0
#define RW PD1
#define E  PD2

#elif BIT_4_MODE
/* control pins configurations if 4 bit mode */
#define LCD_Control_PORT PORTC
#define LCD_Control_DDR  DDRC
#define RS PC0
#define RW PC1
#define E  PC2

#endif

#endif /* LCD_CONFIG_H_ */