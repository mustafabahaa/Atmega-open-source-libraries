/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** <LCD.h
** <This is the header file of the interface of atmega16 with 2*16 LCD open 
    source and good library to start for beginners>
**
** Author: <Mustafa Bahaa>
** -------------------------------------------------------------------------*/

#ifndef LCD_H_
#define LCD_H_

#include <util/delay.h>
#include <avr/io.h>
#include "StandardTypes.h"
#include "macros.h"

///////////////////////////////////////////////////////////////////////////////
#define HOME_SCREEN           0x02        
///////////////////////////////////////////////////////////////////////////////
#define DISPLAY_ON_CURSOR_ON  0x0E      
///////////////////////////////////////////////////////////////////////////////
#define CURSOR_BLINKING       0x0F       
///////////////////////////////////////////////////////////////////////////////
#define MODE_8_BIT            0x38    
///////////////////////////////////////////////////////////////////////////////
#define CLEAR_DISPLAY_AND_RAM 0x01      
///////////////////////////////////////////////////////////////////////////////
#define LCD_ROW_1             0x80       
///////////////////////////////////////////////////////////////////////////////
#define LCD_ROW_2             0xc0       
///////////////////////////////////////////////////////////////////////////////
#define MODE_4_BIT            0x28       
///////////////////////////////////////////////////////////////////////////////



/* -- Global -----------------------------------------------------------------
** <LCD_intialization>()
**
** <paramters>
**  -- void 
** <return>
**  -- void
** -- implementation ---------------------------------------------------------
** <this function intialize the control bits for LCD Register select , 
    Enable and Read Write , also write the main address required to 
	initialize the LCD like mode of operation and home screen on >
** -------------------------------------------------------------------------*/
void LCD_intialization(void);





/* -- Global -----------------------------------------------------------------
** <Lcd_Enable>()
**
** <paramters>
**  -- void 
** <return>
**  -- void
** -- implementation ---------------------------------------------------------
** <this function give pulse to enable pin of the LCD in order to refresh
    it's ram and read the new data you have entered so it sets the pin ,
    then clear it after 1 ms delay in order for the LCD to read changes	>
** -------------------------------------------------------------------------*/
void Lcd_Enable (void);




/* -- Global -----------------------------------------------------------------
** <Lcd_send_command>()
**
** <paramters>
**  -- unsigned 8 bit command 
** <return>
**  -- void
** -- implementation ---------------------------------------------------------
** <this function is used to send commands ( addresss ) that is provided
    by the the LCD data sheet in order to do specific operation 
    Ex sends 0x28 initialize the LCD to operate in 8 wires mode >
** -------------------------------------------------------------------------*/
void Lcd_send_command(u8_t command);





/* -- Global -----------------------------------------------------------------
** <Lcd_display_char>()
**
** <paramters>
**  -- unsigned 8 bit data 
** <return>
**  -- void
** -- implementation ---------------------------------------------------------
** <this function is used to send data to the LCD meaning the data 
    you want to be displayed on LCD like character or litter or sentence >
** -------------------------------------------------------------------------*/
void Lcd_display_char (u8_t data);




/* -- Global -----------------------------------------------------------------
** <Lcd_displayString>()
**
** <paramters>
**  -- signed 8 bit pointer to string (string) 
** <return>
**  -- void
** -- implementation ---------------------------------------------------------
** <this function is a special function of Lcd_display_char because it holds
    a pointer of a string and begin to increment that pointer by one to displayed
    more than one character ( sentence ) until it finds null '\0' because 
    null is the end of every character array or (string)	>
** -------------------------------------------------------------------------*/
void Lcd_displayString(s8_t *string);




/* -- Global -----------------------------------------------------------------
** <gotoXY>()
**
** <paramters>
**  -- unsigned 8 bit row , unsigned 8 bit col
** <return>
**  -- void
** -- implementation ---------------------------------------------------------
** <this function takes x and y (corrdinates) of the LCD and jumps the 
    cursor to the required place based on (x,y) to begin writing there >
** -------------------------------------------------------------------------*/
void Lcd_gotoXY(u8_t row , u8_t col);



/* -- Global -----------------------------------------------------------------
** <Lcd_Clear>()
**
** <paramters>
**  -- void
** <return>
**  -- void
** -- implementation ---------------------------------------------------------
** <this function basically sends the adress of clearing the LCD to clear
    any data displayed on the LCD >
** -------------------------------------------------------------------------*/
void Lcd_Clear (void);


#endif /* LCD_H_ */








