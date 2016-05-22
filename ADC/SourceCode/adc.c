/* -------------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** <ADC.c
** <this is the functions implmentations of the library ADC.H , analog to digital
    converter are good for audience who are new to micro-controllers and writing
	libraries , also it contains the 8-bit mode and 10-bit mode >
**
** Author: <Mustafa Bahaa>
** -----------------------------------------------------------------------------*/


#include "ADC.H"

void ADC_Intialization ()
{
	/*enable the ADC operation*/
     	SET_BIT(ADCSRA,ADEN); 
	
	/* choosing prescallers
	   ADC best works between 50khz and 200khz
	   in order to find a good prescaller betwen
	   these then max prescaller = clock / 50khz 
	   min prescaller =   clock / 200khz
	   we have 8 , 16 prescallers in datasheet
	   both should work fine here we choose 16
	   so the following bits must be set 
	*/   
	   SET_BIT (ADCSRA,ADPS2);
	   CLR_BIT (ADCSRA,ADPS1);
	   CLR_BIT (ADCSRA,ADPS0);
	

    /* atmega gives you the option to make the 
	   voltage referene other value than the 
	   actual vcc voltage , but we don't use 
	   that in our library we are statcified with
	   our vcc voltage = voltage refernce and that
	   is done by setting the following
	*/
       CLR_BIT(ADMUX,REFS1);
       SET_BIT(ADMUX,REFS0);	   
	   	
	   
	/* The bit ADLAR is either be high or low
       it doesn't matter every status has it's  
       own way to read data 
    */
	
	   CLR_BIT(ADMUX,ADLAR);   
	   
}

u8_t ADC_bit_8_convert (u8_t pinNumber)
{
	/* bit 0 to bit 4 in ADMUX register
	   are specified to determine which
	   pin you want to use 
	*/
	ADMUX |= pinNumber;
	
	/*Start conversation */
	SET_BIT(ADCSRA,ADSC);
	
	/*ADCH holds a value from 0,255*/
	return ADCH;
}


u16_t ADC_bit_10_convert (u8_t pinNumber)
{
	
	/* bit 0 to bit 4 in ADMUX register
	   are specified to determine which
	   pin you want to use 
	*/
	ADMUX |= pinNumber;
	
	/*Start conversation */
	SET_BIT(ADCSRA,ADSC);
	
	/* we could have ignored this value and 
	   accessed ADCL but the program may gives
	   you an error if you attempted to access
	   ADCH , before you access ADCL
	*/   
	u8_t LOW_ADCL = ADCL;
	
	
	/* ADCH is left shifted 8 types to leave
	   a place for the two bits of ADCL to make
	   one big 10-bit number , review the data sheet
	   and ADLAR modes to understand this more 
	*/    
	u16_t bit_10_result = ((ADCH <<8) | LOW_ADCL);
	
	return bit_10_result;
	
}







