/**
 *
 * \brief Sprints AUTOSAR Master Class - SeatCtrlApp
 * \author Hassan Farahat
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */
 
#include "Spi.h"
#include "vfb.h"

Std_ReturnType Spi_ReadIB(Spi_ChannelType Channel, Spi_DataType* DataBufferPtr)
{
	/* Read from VFB variables */
	switch(Channel)
	{
		case SpiConf_SpiChannel_WeightSensor:
			*DataBufferPtr = (Spi_DataType)VFB_DriverWeight;
			break;
			
		default:
			break;
	}
	
	return E_OK;
}