/* -------------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** i2c.h
** this is the header file of Two wire interface ( i2c ) library includes the 
** standard i2c address , also change your device address as you want and 
** add other address if there is more than one i2c device
**
** Author: <Mustafa Bahaa>
** -----------------------------------------------------------------------------*/

#define F_CPU 8000000UL

#ifndef I2C_MODULE_H_
#define I2C_MODULE_H_

#include "StandardTypes.h"
#include "macros.h"

/////////////////////////////
#define TW_MT_ARB_LOST   0x38
/////////////////////////////
#define TW_MR_ARB_LOST   0x38
/////////////////////////////
#define TW_START         0x08
/////////////////////////////
#define TW_REP_START     0x10
/////////////////////////////
#define TW_MT_SLA_ACK    0x18
/////////////////////////////
#define TW_MT_DATA_ACK   0x28
/////////////////////////////
#define TW_MR_DATA_NACK  0x58
/////////////////////////////
#define TW_MR_SLA_NACK   0x48
/////////////////////////////
#define TW_MT_SLA_NACK   0x20
/////////////////////////////
#define TW_MT_DATA_NACK  0x30
/////////////////////////////
#define TW_MR_DATA_ACK   0x50
/////////////////////////////
#define TW_MR_SLA_ACK    0x40
/////////////////////////////
#define DEVICE_WRITE     0x00
/////////////////////////////
#define DEVICE_READ      0x01


/* -- Global -----------------------------------------------------------------
** TWI_Init()
**
** paramters: void
** return : void
**
** -- implementation ---------------------------------------------------------
**  this function is used to intialize all the nessaccry control bits of the
**  i2c , also every bit is greatly documented for upgrading purposes
** -------------------------------------------------------------------------*/
void TWI_Init(void);


/* -- Global -----------------------------------------------------------------
** TWIStart()
**
** paramters: void
** return : void
**
** -- implementation ---------------------------------------------------------
**  this function is used to send the start bit of the packet
** -------------------------------------------------------------------------*/
void TWIStart(void);




/* -- Global -----------------------------------------------------------------
** TWIStop()
**
** paramters: void
** return : void
**
** -- implementation ---------------------------------------------------------
**  this function is used to send the stop bit of the packet
** -------------------------------------------------------------------------*/
void TWIStop(void);




/* -- Global -----------------------------------------------------------------
** TWIStop()
**
** paramters: u8_t data
** return : void
**
** -- implementation ---------------------------------------------------------
**  this function is used to write the actual data in register and send it
** -------------------------------------------------------------------------*/
void TWIWrite(u8_t data);



/* -- Global -----------------------------------------------------------------
** TWIReadACK()
**
** paramters: void
** return : u8_t
**
** -- implementation ---------------------------------------------------------
**  this function is used to read ACK bits from slave devices
** -------------------------------------------------------------------------*/
u8_t TWIReadACK(void);





/* -- Global -----------------------------------------------------------------
** TWIReadNACK()
**
** paramters: void
** return : u8_t
**
** -- implementation ---------------------------------------------------------
**  this function is used to read NACK bits from slave devices
** -------------------------------------------------------------------------*/
u8_t TWIReadNACK(void);



/* -- Global -----------------------------------------------------------------
** TWIGetStatus()
**
** paramters: void
** return : u8_t
**
** -- implementation ---------------------------------------------------------
**  this function is used to check the current state of i2c transmission
** -------------------------------------------------------------------------*/
u8_t TWIGetStatus(void);



/* -- Global -----------------------------------------------------------------
** DEVICE_WriteByte()
**
** paramters: u8_t addr, u8_t data
** return : u8_t
**
** -- implementation ---------------------------------------------------------
**  this function is used to send the address that we want to write data into
**  and of course the data needed to be written in that addreass
** -------------------------------------------------------------------------*/
u8_t DEVICE_WriteByte(u8_t addr, u8_t data);




/* -- Global -----------------------------------------------------------------
** DEVICE_ReadByte()
**
** paramters: u8_t addr, u8_t * const data
** return : u8_t
**
** -- implementation ---------------------------------------------------------
** this function is used to reciver data from salve device , the addr is used
** for the location we need to read from and data is a pointer to unsigned 
** 8-bit number to reciver the data recived. 
** -------------------------------------------------------------------------*/
u8_t DEVICE_ReadByte(u8_t addr, u8_t *data);


/* change it as you want for error handling */
#define DEVICE_WRITE_SUCCESS 0xF1
#define DEVICE_WRITE_FAILED 0xF2
#define DEVICE_READ_SUCCESS 0xF3
#define DEVICE_READ_FAILED 0xF4


/* choose device address from datasheet and add another if you want*/
#define DEVICE_ADDR 0xa0







#endif
