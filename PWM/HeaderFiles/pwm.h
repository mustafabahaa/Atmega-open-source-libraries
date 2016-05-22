/* ---------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
**  pwm.h
**
**  This library contains contain 4 pwm operators based on 4 timers 
**  8-bit timer0 and timer1 and also 16bit timer0 and timer1 also
**  it include software PWM functions >
**
** Author: <Mustafa Bahaa>
** -------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*
**  Sets the duty cycle of output. 
**  duty: Between 0 - 255
**  0= 0%  , 255= 100%
**
** The Function sets the duty cycle of pwm output generated on OC0 PIN
** The average voltage on this output pin will be
**
**         duty
** Vout=  ------ x 5v
**         255 
**
** This can be used to control the brightness of LED or Speed of Motor.
** -------------------------------------------------------------------------*/


#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>
#define F_CPU 1000000UL
#include "macros.h"
#include <standardtypes.h>

/* -- Global -----------------------------------------------------------------
**  PWM_1_intialization.h()
**
**  parameters : void
**  return    : void
**
** -- implementation ---------------------------------------------------------
** this function initialize the necessary control bits to enable fast pwm mode
** 
**  
**  TCCR0 - Timer Counter Control Register (TIMER0)
**  -----------------------------------------------
**  BITS DESCRIPTION
**   
**
** NO:   NAME   DESCRIPTION
** --------------------------
** BIT 6 : WGM00  Wave form generation mode  [SET to 1]
** BIT 5 : COM01  Compare Output Mode        [SET to 1]
** BIT 4 : COM00  Compare Output Mode        [SET to 0]
** BIT 3 : WGM01  Wave form generation mode  [SET to 1]
** BIT 2 : CS02   Clock Select               [SET to 0]
** BIT 1 : CS01   Clock Select               [SET to 0]
** BIT 0 : CS00   Clock Select               [SET to 1]
**
** The above settings are for
** --------------------------
**
** Timer Clock = CPU Clock (No Prescalling)
** Mode        = Fast PWM
** PWM Output  = Non Inverted
**
*/

/** ------------------------------------------------------------------------*/
void  PWM_1_intialization();






/* -- Global -----------------------------------------------------------------
**  PWM_1_OUTPUT.h()
**
**  parameters : u8_t duty
**  return    : void
**
** -- implementation ---------------------------------------------------------
**  this function pass a value from 0 to 255 to the OCR0 register which 
**  controls the output voltage of pin PB3 from 0 to v maximum 5 volts
**--------------------------------------------------------------------------*/
void  PWM_1_OUTPUT(u8_t duty);





/* -- Global -----------------------------------------------------------------
**  PWM_2_intialization.h()
**
**  parameters : void
**  return    : void
**
** -- implementation ---------------------------------------------------------
** this function initialize the necessary control bits to enable fast pwm mode
** 
**  TCCR1A - Timer Counter Control Register (TIMER1-channel 1)
**  -----------------------------------------------
**  BITS DESCRIPTION
**   
**
** NO:   NAME   DESCRIPTION
** --------------------------
** BIT 7 : COM1A1  Compare Output Mode         [SET to 1]
** BIT 6 : COM1A0  Compare Output Mode         [SET to 0]
** BIT 1 : WGM11   Wave form generation mode   [SET to 1]
** BIT 0 : WGM10   Wave form generation mode   [SET to 1]
**
**
**  TCCR1B - Timer Counter Control Register (TIMER1-channel 2)
**  ---------------------------------------------------------
**  BITS DESCRIPTION
**   
**
** NO:   NAME   DESCRIPTION
** --------------------------
** BIT 2 : CS12   Clock Select               [SET to 0]
** BIT 1 : CS11   Clock Select               [SET to 0]
** BIT 0 : CS10   Clock Select               [SET to 1]
**
** The above settings are for
** --------------------------
**
** Timer Clock = CPU Clock (No Prescalling)
** Mode        = Fast PWM
** PWM Output  = Non Inverted
**
*/
/** ------------------------------------------------------------------------*/
void  PWM_2_intialization();








/* -- Global -----------------------------------------------------------------
**  PWM_2_OUTPUT.h()
**
**  parameters : u8_t duty
**  return    : void
**
** -- implementation ---------------------------------------------------------
**  this function pass a value from 0 to 1023 to the OC1A register which 
**  controls the output voltage of pin PD5 from 0 to v maximum 5 volts
**--------------------------------------------------------------------------*/
void  PWM_2_OUTPUT(u16_t duty);









/* -- Global -----------------------------------------------------------------
**  PWM_3_intialization.h()
**
**  parameters : void
**  return    : void
**
** -- implementation ---------------------------------------------------------
** this function initialize the necessary control bits to enable fast pwm mode
** 
**  TCCR1A - Timer Counter Control Register (TIMER1-channel 1)
**  ---------------------------------------------------------
**  BITS DESCRIPTION
**   
**
** NO:   NAME   DESCRIPTION
** --------------------------
** BIT 5 : COM1B1  Compare Output Mode         [SET to 1]
** BIT 4 : COM1B0  Compare Output Mode         [SET to 0]
** BIT 1 : WGM11   Wave form generation mode   [SET to 1]
** BIT 0 : WGM10   Wave form generation mode   [SET to 1]
**
**
**  TCCR1B - Timer Counter Control Register (TIMER1-channel 2)
**  ---------------------------------------------------------
**  BITS DESCRIPTION
**   
**
** NO:   NAME   DESCRIPTION
** --------------------------
** BIT 2 : CS12   Clock Select               [SET to 0]
** BIT 1 : CS11   Clock Select               [SET to 0]
** BIT 0 : CS10   Clock Select               [SET to 1]
**
** The above settings are for
** --------------------------
**
** Timer Clock = CPU Clock (No Prescalling)
** Mode        = Fast PWM
** PWM Output  = Non Inverted
**
*/
/** ------------------------------------------------------------------------*/
void  PWM_3_intialization();









/* -- Global -----------------------------------------------------------------
**  PWM_3_OUTPUT.h()
**
**  parameters : u16_t duty
**  return    : void
**
** -- implementation ---------------------------------------------------------
**  this function pass a value from 0 to 1023 to the OC1B register which 
**  controls the output voltage of pin PD4 from 0 to v maximum 5 volts
**--------------------------------------------------------------------------*/
void  PWM_3_OUTPUT(u16_t duty);












/* -- Global -----------------------------------------------------------------
**  PWM_4_intialization.h()
**
**  parameters : void
**  return    : void
**
** -- implementation ---------------------------------------------------------
** this function initialize the necessary control bits to enable fast pwm mode
** 
**  
**  TCCR2 - Timer Counter Control Register (TIMER2)
**  -----------------------------------------------
**  BITS DESCRIPTION
**   
**
** NO:   NAME   DESCRIPTION
** --------------------------
** BIT 6 : WGM20  Wave form generation mode  [SET to 1]
** BIT 5 : COM21  Compare Output Mode        [SET to 1]
** BIT 4 : COM20  Compare Output Mode        [SET to 0]
** BIT 3 : WGM21  Wave form generation mode  [SET to 1]
** BIT 2 : CS22   Clock Select               [SET to 0]
** BIT 1 : CS21   Clock Select               [SET to 0]
** BIT 0 : CS20   Clock Select               [SET to 1]
**
** The above settings are for
** --------------------------
**
** Timer Clock = CPU Clock (No Prescalling)
** Mode        = Fast PWM
** PWM Output  = Non Inverted
**
*/

/** ------------------------------------------------------------------------*/
void  PWM_4_intialization();







/* -- Global -----------------------------------------------------------------
**  PWM_4_OUTPUT.h()
**
**  parameters : u8_t duty
**  return    : void
**
** -- implementation ---------------------------------------------------------
**  this function pass a value from 0 to 255 to the OCR2 register which 
**  controls the output voltage of pin PD7 from 0 to v maximum 5 volts
**--------------------------------------------------------------------------*/
void  PWM_4_OUTPUT(u8_t duty);


#endif /* INCFILE1_H_ */