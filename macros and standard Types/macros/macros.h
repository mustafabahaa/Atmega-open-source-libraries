
#ifndef INCFILE1_H_
#define INCFILE1_H_

#define SET_BIT(var,bit)    ( var|= (1<<bit) )  // Define SET BIT macro
#define CLR_BIT(var,bit)    ( var&=~(1<<bit) )  // Define CLR BIT macro
#define TOGGLE_BIT(var,bit) ( var^=(1<<bit)  )  // Define Toggle macro

#define MSB_INPUT  0xF0
#define MSB_OUTPUT 0xF0
#define MSB_HIGH   0xF0
#define MSB_LWO    0xF0

#define LSB_INPUT  0x0F
#define LSB_OUTPUT 0x0F
#define LSB_HIGH   0x0F
#define LSB_LWO    0x0F


#define ALL_INPUT    0x00
#define ALL_OUTPUT   0xFF
#define ALL_PORT_ON  0xFF
#define ALL_PORT_OFF 0x00


#endif /* INCFILE1_H_ */