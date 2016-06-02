/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
**  LCD.h
**  This is the configurations file for LCD to quickly adjust the pins 
**  just like your pin configuration without changing the code over and over
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
** the main advantage of the 4 bit mode is to save 
** valuable micro controllers pin instead of using 8 
** pins you only use 4 pins , but this comes with
** the cost of less speed because you consume 
** more cycles than 8 bit mode cycles , hence
** 4 bit mode ( slow , less pins )
** 8 bit mode ( fast , more pins )
*/

#define BIT_4_MODE 0
#define BIT_8_MODE 1

#define LCD_DDR   DDRC
#define LCD_PORT  PORTC

/*control pins means RS , RW ,E*/
/*must be on the same port     */
#define LCD_Control_PORT PORTD
#define LCD_Control_DDR  DDRD

#define RS PD0
#define RW PD1
#define E  PD2

#endif /* LCD_CONFIG_H_ */