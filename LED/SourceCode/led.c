

#include "led.h"
#include "ledconfig.h"

void led_intialization()
{
	/* set as output */
	SET_BIT(LED_DDR,LED_BIT);
	
	/*Set initial state*/
	#if INITIAL_ON 
	SET_BIT(LED_PORT,LED_BIT);
	
	#elif INITIAL_OFF
	CLR_BIT(LED_PORT,LED_BIT);
	#endif
	
}


void turnOnLED()
{
	SET_BIT(LED_PORT,LED_BIT);
}

void turnOffLed()
{
	CLR_BIT(LED_PORT,LED_BIT);
}