/*
 * interrupt.c
 *
 * Created: 3/18/2016 2:16:55 AM
 *  Author: Mustafa
 */ 

#include "interrupt.h"

void interrupt_intialization(s8_t interrupt_name )
{
	sei();
	MCUCR |= (1<<ISC11) | (1<<ISC10);
	
	if (interrupt_name == INT0)
	{
		GICR |= (1<<INT0);
	}
	else if (interrupt_name == INT1)
	{
		GICR |= (1<<INT1);
	}
	else if (interrupt_name == INT2)
	{
		GICR |= (1<<INT2);
	}
	
}


/*Must specify interrupt process here*/

ISR(INT0_vect)
{
	//  INT0 interrupt process 
}

ISR(INT1_vect)
{
	// INT1 interrupt process
}

ISR(INT2_vect)
{
	// INT2 interrupt process
}



