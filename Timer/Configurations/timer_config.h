
#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_


////////////////////////////////////////////////
#define NORMAL_MODE         1
#define COMPARE_MATCH_MODE  0

/* choose pre-Scalling */
#define NO_PRESCALLING       0
#define PRESCALLING_8_CLK    0
#define PRESCALLING_64_CLK   0
#define PRESCALLING_128_CLK  0
#define PRESCALLING_256_CLK  0
#define PRESCALLING_1024_CLK 1 

/*pre-scalling from external source on pin T0*/
#define EXTERNAL_PRESCALLING_FALLING 0
#define EXTERNAL_PRESCALLING_RISING  0
///////////////////////////////////////////////

#endif /* TIMER_CONFIG_H_ */