


#include <avr/io.h>
#include "macros.h"
#include "StandardTypes.h"

#ifndef TIMER_H_
#define TIMER_H_

void timer_0_initialization();
void timer_0_normal_mode(u8_t count);
void timer_0_CTC(u8_t ctc ,u8_t count);

void timer_1_initialization();
void timer_1_normal_mode(u16_t count);
void timer_1_CTC(u16_t ctc ,u16_t count);
void timer_1_2_CTC(u16_t ctc ,u16_t count);

void timer_2_initialization();
void timer_2_normal_mode(u8_t count);
void timer_2_CTC(u8_t ctc ,u8_t count);

#endif /* TIMER_H_ */