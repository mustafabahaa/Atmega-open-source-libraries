/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
**  pwm.c
** 
**  This library contains contain 4 pwm operators based on 4 timers 
**  8-bit timer0 and timer1 and also 16bit timer0 and timer1 also
**  it include software PWM functions implementations
**
**  8-bit  timer/counter0 with PWM on pin PB3 OC3
**  8-bit  timer/counter2 with PWM on pin PD7 OC0
**
**  16-bit timer/counter1 channel 1 on pin PD5 OCA1
**  16-bit timer/counter1 channel 2 on pin PD4 OCA2
**
**  comments : more details on pwm.H 
**
** Author: <Mustafa Bahaa>
** -------------------------------------------------------------------------*/


#include "PWM.h"

void  PWM_1_intialization()
{
	/* choosing mode of operation fast pwm */
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	
	/*choose non inverting mode of pwm */
	SET_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);
	
	/*choose clock no pre scalling option*/
	CLR_BIT(TCCR0,CS02);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS00);
	
	/* making the pin of pwm output */
	SET_BIT(DDRB,PB3); 
}


void  PWM_1_OUTPUT(u8_t duty)
{
	/* OCR0 holds a value from 0 to 255
       that vary the output of ON PIN PB3
       between 0 and v maximum (5v)
	*/   
	OCR0 = duty;
}




void  PWM_2_intialization()
{
	/* choosing mode of operation fast pwm */
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1A,WGM10);
	
	/*choose non inverting mode of pwm */
	SET_BIT(TCCR1A,COM1A1);
	CLR_BIT(TCCR1A,COM1A0);
	
	/*choose clock no pre scalling option*/
	CLR_BIT(TCCR1B,CS12);
	CLR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS10);
	
	/* making the pin of pwm output */
	SET_BIT(DDRD,PD5); 
	
}


void  PWM_2_OUTPUT(u16_t duty)
{
	/* OCR1A holds a value from 0 to 1023
       that vary the output of ON PIN PD5
       between 0 and v maximum (5v)
	*/   
	 OCR1A = duty;
	 
}





void  PWM_3_intialization()
{
	/* choosing mode of operation fast pwm */
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1A,WGM10);
	
	/*choose non inverting mode of pwm */
	SET_BIT(TCCR1A,COM1B1);
	CLR_BIT(TCCR1A,COM1B0);
	
	/*choose clock no pre scalling option*/
	CLR_BIT(TCCR1B,CS12);
	CLR_BIT(TCCR1B,CS11);
	SET_BIT(TCCR1B,CS10);
	
	/* making the pin of pwm output */
	SET_BIT(DDRD,PD4); 
	
}


void  PWM_3_OUTPUT(u16_t duty)
{
	/* OCR1B holds a value from 0 to 1023
       that vary the output of ON PIN PD5
       between 0 and v maximum (5v)
	*/   
	
	 OCR1BL = duty & 0x0F;
	 OCR1BH = duty & 0xF0;
}




void  PWM_4_intialization()
{
	/* choosing mode of operation fast pwm */
	SET_BIT(TCCR2,WGM20);
	SET_BIT(TCCR2,WGM21);
	
	/*choose non inverting mode of pwm */
	SET_BIT(TCCR2,COM21);
	CLR_BIT(TCCR2,COM20);
	
	/*choose clock no pre scalling option*/
	CLR_BIT(TCCR2,CS22);
	CLR_BIT(TCCR2,CS21);
	SET_BIT(TCCR2,CS20);
	
	/* making the pin of pwm output */
	SET_BIT(DDRD,PD7);
	
}
void  PWM_4_OUTPUT(u8_t duty)
{
	/* OCR2 holds a value from 0 to 255
       that vary the output of ON PIN PB3
       between 0 and v maximum (5v)
	*/   
	OCR2 = duty;
	
}



