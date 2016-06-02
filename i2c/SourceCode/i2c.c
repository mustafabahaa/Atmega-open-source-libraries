/* -------------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** i2c.c
** this is the functions implementations of Two wire interface ( i2c ) library
** includes the standard i2c address , also change your device address as you 
** want and add in i2c.h other address if there is more than one i2c device 
**
** Author: <Mustafa Bahaa>
** -----------------------------------------------------------------------------*/


#include <avr/io.h>
#include "I2C.h"
#include "macros.h"
#include "StandardTypes.h"

void TWI_Init(void)
{
	/* TWI initialization */
	/* Bit Rate: 400.000 kHz */
	TWBR=0x02;
	
	/* I2C Enable */
	SET_BIT(TWCR, TWEN);
}

void TWIStart(void)
{
	/* Send Start Condition */
	TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	
	/* Wait for TWINT flag set in TWCR Register*/
	while(bit_is_clear(TWCR,TWINT));
	
}

void TWIStop(void)
{
	/* Send Stop Condition */
	TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
}

void TWIWrite(u8_t data)
{
	// Put data On TWI Register
	TWDR = data;
	// Send Data
	TWCR = (1 << TWINT) | (1 << TWEN);
	
	/* Wait for TWINT flag set in TWCR Register */
	while(bit_is_clear(TWCR,TWINT));
}


u8_t TWIReadACK(void)
{
	/* enable acknowledge */
	TWCR = (1 << TWINT) | (1 << TWEN) | (1<<TWEA);  
	
	/* Wait for TWINT flag set in TWCR Register */
	while(bit_is_clear(TWCR,TWINT));
	
	/* Read Data */
	return TWDR;
}

u8_t TWIReadNACK(void)
{
	TWCR = (1 << TWINT) | (1 << TWEN);
	/* Wait for TWINT flag set in TWCR Register */
	while(bit_is_clear(TWCR,TWINT));
	
	/* Read Data */
	return TWDR;
}

u8_t TWIGetStatus(void)
{
	u8_t status;
	/* mask the last 3 bits because they are reserved*/
	status = TWSR & 0xF8;
	return status;
}




u8_t DEVICE_WriteByte(u8_t addr, u8_t data)
{
   
    /* Start TWI */
    TWIStart();
    /* Check if TWI Start */
    if(TWIGetStatus() != TW_START)
		return DEVICE_WRITE_FAILED;
	
    
	/* send write command */
    TWIWrite(DEVICE_ADDR + DEVICE_WRITE); 
    /* check if SLA+W has been transmitted ACK has been received */
    if(TWIGetStatus() != TW_MT_SLA_ACK)
        return DEVICE_WRITE_FAILED;
    
    /* Write address  */
    TWIWrite(addr);
    /* check if it is TW_MT_DATA_ACK */
    if(TWIGetStatus() != TW_MT_DATA_ACK)
        return DEVICE_WRITE_FAILED;
		
    
    /*Send Data*/
    TWIWrite(data);
    /* Check if it is TW_MT_DATA_ACK */
    if(TWIGetStatus() != TW_MT_DATA_ACK)
        return DEVICE_WRITE_FAILED;
    
	
    /* TWI Stop */
    TWIStop(); 
    /* Return Done */
    return DEVICE_WRITE_SUCCESS;
}



u8_t DEVICE_ReadByte(u8_t addr, u8_t *data)
{
    
    /* Start TWI */
    TWIStart();
    /*Check if TWI Start*/
    if(TWIGetStatus() != TW_START)
        return DEVICE_READ_FAILED;
		
		
	/* send write command 	*/
	TWIWrite(DEVICE_ADDR + DEVICE_WRITE); 
    /* Check if it is TW_MT_SLA_ACK */
    if(TWIGetStatus() != TW_MT_SLA_ACK)
        return DEVICE_READ_FAILED;
		
		
    /* write desired read address */
	TWIWrite(addr);
    /* check if it is TW_MT_DATA_ACK */
    if(TWIGetStatus() != TW_MT_DATA_ACK)
       return DEVICE_READ_FAILED;
    
  
    /* repeat Start TWI */
    TWIStart();
    // Check if TW_REP_START
    if(TWIGetStatus() != TW_REP_START)
        return DEVICE_READ_FAILED;
    
   
    /* send read command */
    TWIWrite(DEVICE_ADDR + DEVICE_READ);
    /* Check if it is TW_MR_SLA_ACK */
    if(TWIGetStatus() != TW_MR_SLA_ACK)
        return DEVICE_READ_FAILED; 
    
	
    /* Read Data */
    *data =  TWIReadNACK();
    /*Check if it is TW_MR_DATA_NACK */
    if(TWIGetStatus() != TW_MR_DATA_NACK)
        return DEVICE_READ_FAILED;
    
    /* TWI Stop */
    TWIStop(); 

    /* Return Done */
    return DEVICE_READ_SUCCESS; 
}
