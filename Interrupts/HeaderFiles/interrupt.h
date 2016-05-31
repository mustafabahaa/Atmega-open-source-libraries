/*
 * interrupt.h
 *
 * Created: 3/18/2016 2:15:27 AM
 *  Author: Mustafa
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "macros.h"
#include "StandardTypes.h"
#include <avr/interrupt.h>
#include <string.h>

void interrupt_intialization(s8_t interrupt_name );

#endif /* INTERRUPT_H_ */