
#include "button.h"
#include "buttonconfig.h"

void button_intialization()
{
	/*choose input pin and port*/
	CLR_BIT(BUTTON_DDR,BUTTON_BIT);
	
	
	/*pull up resistor config*/
	#if PULL_UP
    SET_BIT(BUTTON_PORT,BUTTON_BIT);
	#elif PULL_DOWN
	CLR_BIT(BUTTON_PORT,BUTTON_BIT);
	#endif
}


e_buttonStatus GetKeyStatus ()
{   
	#if PULL_UP
	if (bit_is_clear(BUTTON_PIN,BUTTON_BIT))
	return keyPressed;
	else
    return keyNotPressed;
		   
	#elif PULL_DOWN
	if (bit_is_set(BUTTON_PIN,BUTTON_BIT))
	return keyPressed;
	else
	return keyNotPressed;
	
	#endif
}


