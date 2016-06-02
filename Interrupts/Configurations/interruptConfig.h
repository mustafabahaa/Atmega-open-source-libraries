/* -------------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
**  interruptConfig.h
**  this is the configurations file for controlloing the external interrupts and 
**  choosing the moder of operations (rising edge , falling edge)
**
** Author: <Mustafa Bahaa>
** -----------------------------------------------------------------------------*/

  #ifndef INTERRUPTCONFIG_H_
  #define INTERRUPTCONFIG_H_

  
  /*choose External interrupt*/
  #define INT0 1
  #define INT1 0
  #define INT2 0
  
  /*choose mode of operation*/
  #define RISING_EDGE  1
  #define FALLING_EDGE 0
  #define CHANGE_EDGE  0
  /*Notice that change_edge mode doesn't work for INT2*/
  
  


  #endif /* INTERRUPTCONFIG_H_ */