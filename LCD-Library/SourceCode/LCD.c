/* -------------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** <LCD.c
** <this is the functions implmentations of the library LCD.H , these functions
    are good for audience who are new to micro-controllers and writing libraries>
**
** Author: <Mustafa Bahaa>
** -----------------------------------------------------------------------------*/
/*Comments*/
/* in order to understand the code please read the function decription
** at LCD.h also read the following control bits information , also 
** move to Lcdconfig.h to adjust the pin configuration as your current
** circuit.
   
/* R/S bit is low when writing command , high if data */
/* R/W bit is low when writing and high when reading  */
/* E bit must be toggled with each instruction in order to refresh LCD*/
/* -----------------------------------------------------------------------------*/
  
#include "LCD.h"
#include "lcd_config.h"


/* the following functions works for 4bit mode and 8bit mode */

void Lcd_Enable ()
{
	CLR_BIT(LCD_Control_PORT,E);
	_delay_ms(1);
	SET_BIT(LCD_Control_PORT,E);
	_delay_ms(5);
}


void Lcd_Clear ()
{
	Lcd_send_command(CLEAR_DISPLAY_AND_RAM);
}


void Lcd_displayString(s8_t *string)
{
	/* this loop will move over all the string 
	   and only will exit the loop if it come 
	   cross over \0 null which is end of string
	*/   
	int i=0;
	while (string[i] != '\0')   
	{
		/* print elemnt of string and i++ to get the next */
		Lcd_display_char(string[i]);
		i++;
	}
}


void gotoXY(u8_t row , u8_t col)
{
	if ( row ==  0 )
	{
		Lcd_send_command(LCD_ROW_1+col);
	}
	else if ( row == 1)
	{
	   Lcd_send_command(LCD_ROW_2+col);
	}
}


/*------------------------------------------------------------*/


#if BIT_8_MODE
/* this functions only work for the 8 bit mode meaning that you use
** 8 bits to control the LCD ( 8 wires ) 
*/   
   
void LCD_intialization(void)
{
	LCD_DDR = ALL_OUTPUT;
	/* making all control pins OUTPUT */
	SET_BIT(LCD_Control_DDR,E);  
	SET_BIT(LCD_Control_DDR,RS);
	SET_BIT(LCD_Control_DDR,RW);
	
	/* making RS in command and R/W as write */ 
	CLR_BIT(LCD_Control_PORT,RS); 
	CLR_BIT(LCD_Control_PORT,RW); 
	PORTC = ALL_PORT_OFF;    
	
	Lcd_send_command(BIT_8_MODE);              
	Lcd_send_command(DISPLAY_ON_CURSOR_ON); 
	
}


void Lcd_send_command(u8_t command)
{
	LCD_PORT = command;
	CLR_BIT(LCD_Control_PORT,RS);   // RS Low to be command
	Lcd_Enable();
	_delay_ms(5);
}


void Lcd_display_char (u8_t data)
{
	LCD_PORT = data;
	SET_BIT(LCD_Control_PORT,RS);    // RS HIGH to be data
	Lcd_Enable();
	_delay_ms(5);
}


#elif BIT_4_MODE
/* this functions only work for the 4 bit mode meaning that you use
** 8 bits to control the LCD ( 4 wires ) 
*/ 
void LCD_intialization() 						
{
	/* Most significant bits are output , half port */
	LCD_DDR = MSB_OUTPUT;
	/* making all control pins OUTPUT */
	SET_BIT(LCD_Control_DDR,E);
	SET_BIT(LCD_Control_DDR,RS);
	SET_BIT(LCD_Control_DDR,RW);
	
	/* making RS in command and R/W as write */
	CLR_BIT(LCD_Control_PORT,RS);
	CLR_BIT(LCD_Control_PORT,RW);
	/* Intialize LCD pins low */
	LCD_PORT = MSB_LWO;
	
	Lcd_send_command(HOME_SCREEN); 							
	Lcd_send_command(MODE_4_BIT); 								  
	Lcd_send_command(DISPLAY_ON_CURSOR_ON);
}
 
void Lcd_send_command(u8_t command)				
{
	/*the following line sends the MSB bits of variable
      command (B7 TO B4) by logic and with 11110000 the 
	  result is we only get the most significant bits */
 	LCD_PORT = command & 0xF0;         
	CLR_BIT(LCD_Control_PORT,RS);
    Lcd_Enable(); 				      
 
    /* then we shift (B3 TO B0) to the left then we logic 
	   and them with 11110000 (0xF0) in order to send only 
	   the half because we only have 4 wires to send data
	*/   
    LCD_PORT = ((command<<4) & 0xF0); 	   
	CLR_BIT(LCD_Control_PORT,RS);
    Lcd_Enable(); 			          
} 
 
 
void Lcd_display_char (u8_t data)			   
{				
	/*the following line sends the MSB bits of variable
      command (B7 TO B4) by logic and with 11110000 the 
	  result is we only get the most significant bits */	
 	LCD_PORT = data & 0xF0;	
	SET_BIT(LCD_Control_PORT,RS);	
	Lcd_Enable(); 
	
	/* then we shift (B3 TO B0) to the left then we logic 
	   and them with 11110000 (0xF0) in order to send only 
	   the half because we only have 4 wires to send data
	*/ 
 	LCD_PORT=((data<<4) & 0xF0);
	SET_BIT(LCD_Control_PORT,RS);
	Lcd_Enable(); 
}


#endif

