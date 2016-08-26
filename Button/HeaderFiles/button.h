
#ifndef BUTTON_H_
#define BUTTON_H_

#include <avr/io.h>
#include "standardtypes.h"
#include "macros.h"



typedef enum  {keyPressed,keyNotPressed} e_buttonStatus;

void button_intialization();
e_buttonStatus GetKeyStatus ();


#endif /* BUTTON_H_ */