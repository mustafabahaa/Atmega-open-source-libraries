
#include "timer.h"
#include "timer_config.h"

void timer_0_initialization()
{
	///////////////////////////////////
	#if NORMAL_MODE
	DOUBLE_CLR_BIT(TCCR0,WGM01,WGM00);

	#elif COMPARE_MATCH_MODE
	SET_BIT(TCCR0,WGM01);
	CLR_BIT(TCCR0,WGM00);
	#endif /*Mode of operation*/
	//////////////////////////////////
	#if NO_PRESCALLING
	SET_BIT(TCCR0,CS00);
	DOUBLE_CLR_BIT(TCCR0,CS01,CS02);

	#elif PRESCALLING_8_CLK
	SET_BIT(TCCR0,CS01);
	DOUBLE_CLR_BIT(TCCR0,CS00,CS02);
	
	#elif PRESCALLING_64_CLK
	DOUBLE_SET_BIT(TCCR0,CS00,CS01);
	CLR_BIT(TCCR0,CS02);
	
	#elif PRESCALLING_256_CLK
	DOUBLE_CLR_BIT(TCCR0,CS00,CS01);
	SET_BIT(TCCR0,CS02);
	
	#elif PRESCALLING_1024_CLK
	CLR_BIT(TCCR0,CS01);
	DOUBLE_SET_BIT(TCCR0,CS00,CS02);
	
	#elif EXTERNAL_PRESCALLING_FALLING
	CLR_BIT(TCCR0,CS00);
	DOUBLE_SET_BIT(TCCR0,CS01,CS02);
	
	#elif EXTERNAL_PRESCALLING_RISING
	TRIBLE_SET_BIT(TCCR0,CS00,CS01,CS02);
	#endif /*clock pre-scalling*/
	/////////////////////////////////////
}

void timer_0_normal_mode(u8_t count)
{
	if (TCNT0 >= count)
	{
		TCNT0 = 0;
		/* put your code here */
	}
}

void timer_0_CTC(u8_t ctc ,u8_t count )
{
	OCR0 = ctc;
	if (bit_is_set(TIFR,OCF0))
	{
	     TCNT0 = 0;
		 /* put your code here*/
		 
		 /*Clear flag manually*/
		SET_BIT(TIFR,OCF0);
	}
}


void timer_1_initialization ()
{
	///////////////////////////////////
	#if NORMAL_MODE
	DOUBLE_CLR_BIT(TCCR1A,WGM11,WGM10);
	DOUBLE_CLR_BIT(TCCR1B,WGM12,WGM13);
	
	#elif COMPARE_MATCH_MODE
	/*since TIMER1 has two CTC*/
	/*The following for top OCR1A*/
	SET_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);
	DOUBLE_CLR_BIT(TCCR1A,WGM11,WGM10);
	
	/*as for top ICR1 */
	DOUBLE_CLR_BIT(TCCR1A,WGM11,WGM10);
	DOUBLE_SET_BIT(TCCR1B,WGM12,WGM13);
	#endif /*mode of operation*/
	//////////////////////////////////
	#if NO_PRESCALLING
	SET_BIT(TCCR1B,CS10);
	DOUBLE_CLR_BIT(TCCR1B,CS10,CS11);

	#elif PRESCALLING_8_CLK
	SET_BIT(TCCR1B,CS11);
	DOUBLE_CLR_BIT(TCCR1B,CS10,CS12);
	
	#elif PRESCALLING_64_CLK
	DOUBLE_SET_BIT(TCCR1B,CS10,CS11);
	CLR_BIT(TCCR1B,CS12);
	
	#elif PRESCALLING_256_CLK
	DOUBLE_CLR_BIT(TCCR1B,CS10,CS11);
	SET_BIT(TCCR1B,CS12);
	
	#elif PRESCALLING_1024_CLK
	CLR_BIT(TCCR1B,CS11);
	DOUBLE_SET_BIT(TCCR1B,CS10,CS12);
	
	#elif EXTERNAL_PRESCALLING_FALLING
	CLR_BIT(TCCR1B,CS10);
	DOUBLE_SET_BIT(TCCR1B,CS11,CS12);
	
	#elif EXTERNAL_PRESCALLING_RISING
	TRIBLE_SET_BIT(TCCR1B,CS10,CS11,CS12);
	#endif /*clock pre-scalling*/
	/////////////////////////////////////
}

void timer_1_normal_mode(u16_t count)
{
	if (TCNT1 >= count)
	{
		TCNT1 = 0;
		/* put your code here */
	}
}

void timer_1_CTC(u16_t ctc ,u16_t count )
{
	OCR1A = ctc;
	if (bit_is_set(TIFR,OCF1A))
	{
		TCNT1 = 0;
		/* put your code here*/
		
		/*Clear flag manually*/
		SET_BIT(TIFR,OCF1A);
	}
}

void timer_1_2_CTC(u16_t ctc ,u16_t count )
{
	OCR1B = ctc;
	if (bit_is_set(TIFR,OCF1B))
	{
		TCNT1 = 0;
		/* put your code here*/
		
		/*Clear flag manually*/
		SET_BIT(TIFR,OCF1B);
	}
}


void timer_2_initialization()
{
	///////////////////////////////////
	#if NORMAL_MODE
	DOUBLE_CLR_BIT(TCCR2,WGM20,WGM21);

	#elif COMPARE_MATCH_MODE
	SET_BIT(TCCR2,WGM21);
	CLR_BIT(TCCR2,WGM20);
	#endif /*Mode of operation*/
	//////////////////////////////////
	
	#if PRESCALLING_64_CLK
	DOUBLE_CLR_BIT(TCCR2,CS20,CS21);
	SET_BIT(TCCR2,CS22);
	
	#elif PRESCALLING_128_CLK
	DOUBLE_SET_BIT(TCCR2,CS20,CS22);
	CLR_BIT(TCCR2,CS21);
	
	#elif PRESCALLING_256_CLK
	DOUBLE_SET_BIT(TCCR2,CS22,CS21);
	CLR_BIT(TCCR2,CS20);
	
	#elif PRESCALLING_1024_CLK
	TRIBLE_SET_BIT(TCCR2,CS20,CS21,CS22);
	#endif /*clock pre-scalling*/
	/////////////////////////////////////
}


void timer_2_normal_mode(u8_t count)
{
	if (TCNT2 >= count)
	{
		TCNT2 = 0;
		/* put your code here */
	}
}


void timer_2_CTC(u8_t ctc ,u8_t count)
{
	OCR2 = ctc;
	if (bit_is_set(TIFR,OCF2))
	{
		TCNT2 = 0;
		/* put your code here*/
		
		/*Clear flag manually*/
		SET_BIT(TIFR,OCF2);
	}
}
