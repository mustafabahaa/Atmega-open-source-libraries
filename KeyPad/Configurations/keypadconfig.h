----/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
**  keypadconfig.h
**  This is the header file of the interface of atmega16 with any keypad
**  size just change your wire configurations from this file
**
** Author: Mustafa Bahaa
** -------------------------------------------------------------------------------
** instructions 
** -------------------------------------------------------------------------------
** 1-adjust the rows and coloumn pins.
** 2-choose your keypad dimentions in ROW_NUMBERS and COL_NUMBERS.
** 3-specify the PORT and the PIN of the keypad and leave.
** 4-Don't change the address of NO_KEY_PRESSED.
** 5-adjust the matrix as your keypad or any output charachters you want.
** 6-the row pins have to be next to each other example PD1 , PD2 , PD3 ,..
** 7-the column pins have to be next to each other example PD1 , PD2 , PD3 ,..
** 8-keypad all pins has to be on same port.
** -------------------------------------------------------------------------------
** highly important note 
** -------------------------------------------------------------------------------
** Note1 :
** ROW_1 pin must be lower than ROW_2 , and thats is applyed to all pins meaning
** that you cant set ROW_4 as PA0 and ROW_1 as PA3 that won't give you the 
** required output and in fact will miss all program , same as for columns 
** it is recommend to configure the pin as this orginial libarary.
** Note2 :
** the total number of rows + col must be = 8 that means if you add 3 rows 
** you can add up two 5 columns and if you have 4 rows then you can add up
** to 4 columns , if rows + col > 8 no problem but it canot be otherwise
--------------------------------------------------------------------------------*/

#ifndef KEYPADCONFIG_H_
#define KEYPADCONFIG_H_


/* configure  your row pins*/
/* comment any line if you don't have 4 rows*/
#define ROW_1 PA0
#define ROW_2 PA1
#define ROW_3 PA2
#define ROW_4 PA3

/* configure  your columns pins */
/* comment any line if you don't have 4 columns*/
#define COL_1 PA4
#define COL_2 PA5
#define COL_3 PA6
#define COL_4 PA7

/* configure as your keypad dimention */
#define ROW_NUMBERS 4
#define COL_NUMBERS 4

/* configure the port of LCD */
#define KEYPAD_PORT PORTA
#define KEYPAD_PIN  PINA


/* configure as your keypad */
s8_t KeyPad [ROW_NUMBERS][COL_NUMBERS] =
{
	{'7', '8' , '9' , '/' },
	{'4', '5' , '6' , '*' },
	{'1', '2' , '3' , '-' },
	{'A', '0' , '=' , '+' }
};

/* Don't change this at all */
#define NO_KEY_PRESSED 0XFF

/* Don't change this variables at all */
s8_t pressed=0;
s8_t keypressed = 0;
s8_t col_loop=COL_1;


#endif /* KEYPADCONFIG_H_ */