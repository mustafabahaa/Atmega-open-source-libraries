/* -------------------------------------------------------------------------------
** This software is in the public domain, furnished "as is", without technical
** support, and with no warranty, express or implied, as to its usefulness for
** any purpose.
**
** spi_config.h
** this is the configuration file of SPI please choose the appropriate SCK
** and choose mode of SPI also specify the port and the control pins of 
** SPI protocol.
**
** Author: <Mustafa Bahaa>
** -----------------------------------------------------------------------------*/

#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_


#define DUMB 0XFF

/*set the frequency you want to one*/
#define SCK_FREQUANCY_FOC_4   0
#define SCK_FREQUANCY_FOC_16  1
#define SCK_FREQUANCY_FOC_64  0
#define SCK_FREQUANCY_FOC_128 0
#define SCK_FREQUANCY_FOC_2   0
#define SCK_FREQUANCY_FOC_8   0
#define SCK_FREQUANCY_FOC_32  0
#define SCK_FREQUANCY_FOC_65  0


/*choose mode of operation master or slave*/
#define SPI_MASTER 1
#define SPI_SALVE 0

/*define port and of SPI control */
#define DDR_SPI DDRB
#define DD_SS   PB4
#define DD_MOSI PB5
#define DD_MISO PB6
#define DD_SCK  PB7

#endif /* SPI_CONFIG_H_ */