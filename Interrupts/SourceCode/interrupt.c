/* -------------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
**  interrupt.c
**  this is the functions implmentation of interrupt.h please head to your 
**  interrupt and begin to implement the interrupt routine immediatly in 
**  one of the ready functions
**
** Author: <Mustafa Bahaa>
** -----------------------------------------------------------------------------*/

#include "interrupt.h"
#include "standardTypes.h"
#include "macros.h"

void interrupt_intialization()
{
	/*the global interrupt mask*/
	sei();	
	
	////////////////////////////////////
	#if INT0
		/* Active INT0 interrupt*/
		SET_BIT(GICR,INT0);
		
		/*choosing interrupt modes*/
	
		#if RISING_EDGE 
			/*at rising edge*/
			SET_BIT(MCUCR,ISC01);
			SET_BIT(MCUCR,ISC00);
	
		#elif FALLING_EDGE 
			/*at falling edge*/
			SET_BIT(MCUCR,ISC01);
			CLR_BIT(MCUCR,ISC00);
	
		#elif CHANGE_EDGE
			/*at any change edge*/
			SET_BIT(MCUCR,ISC01);
			SET_BIT(MCUCR,ISC00);
		#endif	/* modes of operations */
	/////////////////////////////////////
	
	/////////////////////////////////////
	#elif INT1
		/* Active INT1 interrupt*/
		SET_BIT(GICR,INT1);
		
		/*choosing interrupt modes*/
		
		#if RISING_EDGE 	
			/*at rising edge*/
			SET_BIT(MCUCR,ISC11);
			SET_BIT(MCUCR,ISC10);
	
		#elif FALLING_EDGE 
			/*at falling edge*/
			SET_BIT(MCUCR,ISC11);
			CLR_BIT(MCUCR,ISC10);
	
		#elif CHANGE_EDGE
			/*at any change edge*/
			SET_BIT(MCUCR,ISC11);
			SET_BIT(MCUCR,ISC10);
		#endif	/* modes of operations */ 
	/////////////////////////////////////////

    /////////////////////////////////////////	
	#elif INT2	
			/* Active INT2 interrupt*/
			SET_BIT(GICR,INT2);
		
			/*choosing interrupt modes*/
		
		#if RISING_EDGE 		
			/*at rising edge*/
			SET_BIT(MCUCR,ISC2);
	
		#elif FALLING_EDGE 
			/*at falling edge*/
			CLR_BIT(MCUCR,ISC2);
		#endif	/* modes of operations */
	/////////////////////////////////////////
	
    #endif  /*external interrupt number*/
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



