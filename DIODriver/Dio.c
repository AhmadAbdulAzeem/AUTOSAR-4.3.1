#include "Dio.h"
#include "Dio_MemMap.h"

Port_Id getPortId(Dio_ChannelType ChannelId)
{
	uint8_t port;
	port = ( (ChannelId/PINS_NUMBER_PER_PORT) % (PORTS_NUMBER) );
	if(port == 0)
		return PORTA;
	else if(port == 1)
		return PORTB;
	else if(port == 2)
		return PORTC;
	else if(port == 3)
		return PORTD;
	else if(port == 4)
		return PORTE;
	else
		return PORTF;
}




Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId )
{
	Dio_LevelType level;
	Port_Id portId = getPortId(ChannelId);
	ChannelId = ChannelId % PINS_NUMBER_PER_PORT;
	if((REG(portId, GPIODATA_OFFSET) & (1<<ChannelId)))
		level = STD_HIGH;
	else
		level = STD_LOW;
	return level;
}




void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
{
	Port_Id portId = getPortId(ChannelId);
	ChannelId = ChannelId % PINS_NUMBER_PER_PORT;
	
	
	/* Corresponding pins is an output. */
	if((REG(portId, GPIODIR_OFFSET) & (1<<ChannelId)))
	{
		/* [SWS_Dio_00028] ?If the specified channel is configured as an output channel, the Dio_WriteChannel 
			 function shall set the specified Level for the specified channel. ? (SRS_Dio_12005) */
		REG(portId, GPIODATA_OFFSET) = (REG(portId, GPIODATA_OFFSET) & ((~ (1 << ChannelId)))) | (Level << ChannelId);
	}
	/* Corresponding pin is an input. */
	else
	{
		/* [SWS_Dio_00029] ?If the specified channel is configured as an input channel, the Dio_WriteChannel 
			 function shall have no influence on the physical output. ? (SRS_Dio_12005) */
	}
}


Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId )
{
	return REG(PortId, GPIODATA_OFFSET);
}


void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level )
{
	int itr;
	for(itr = 0; itr < PINS_NUMBER_PER_PORT; itr++)
	{
		/* Corresponding pins is an output. */
		if((REG(PortId, GPIODIR_OFFSET) & (1<<itr)))
		{
			/* ?The Dio_WritePort function shall set the specified value for the specified port. ? (SRS_Dio_12003) */
			REG(PortId, GPIODATA_OFFSET) = (REG(PortId, GPIODATA_OFFSET) & ((~ (1 << itr)))) | (Level << itr);
		}
		/* Corresponding pin is an input. */
		else
		{
			/* [SWS_Dio_00035] ?When the Dio_WritePort function is called, DIO Channels that
			are configured as input shall remain unchanged.? (SRS_Dio_12003) */
		}
	}
}




#if(DioFlipChannelApi == STD_ON)
	Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId)
	{
		Dio_LevelType level;
		Port_Id portId = getPortId(ChannelId);
		ChannelId = ChannelId % PINS_NUMBER_PER_PORT;
		
		/* Corresponding pins is an output. */
		if((REG(portId, GPIODIR_OFFSET) & (1<<ChannelId)))
		{
			/* [SWS_Dio_00191] ?If the specified channel is configured as an output channel, 
				the Dio_FlipChannel function shall read level of the channel (requirements 
				[SWS_Dio_00083] & [SWS_Dio_00084] are applicable) and invert it, then write the 
				inverted level to the channel. The return value shall be the inverted level of the specified channel. ? */
		
			/* STD_HIGH level */
			if((REG(portId, GPIODATA_OFFSET) & (1<<ChannelId)))
			{
				REG(portId, GPIODATA_OFFSET) &= ~(1 << ChannelId);
				level = STD_LOW;
			}
			/* STD_LOW level */
			else
			{
				REG(portId, GPIODATA_OFFSET) |= (1 << ChannelId);
				level = STD_HIGH;
			}
		}
		/* Corresponding pin is an input. */
		else
		{
			/* [SWS_Dio_00192] ?If the specified channel is configured as an input channel,
				the Dio_FlipChannel function shall have no influence on the physical output.
				The return value shall be the level of the specified channel. ? */
		
			/* STD_HIGH level */
			if((REG(portId, GPIODATA_OFFSET) & (1<<ChannelId)))
			{
				level = STD_HIGH;
			}
			/* STD_LOW level */
			else
			{
				level = STD_LOW;
			}
		}
		return level;
	}
#endif
	
	
	
#if(DioVersionInfoApi == STD_ON)
	void Dio_GetVersionInfo( Std_VersionInfoType* VersionInfo )
	{
		/* Not implemented for now */
	}
#endif
	

	
Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr )
{
	return ( (REG(ChannelGroupIdPtr->port, GPIODATA_OFFSET)) & ChannelGroupIdPtr->maskl ) >> ChannelGroupIdPtr->offset;
}


void Dio_WriteChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level )
{
	REG(ChannelGroupIdPtr->port, GPIODATA_OFFSET) = ( REG(ChannelGroupIdPtr->port, GPIODATA_OFFSET) & (~ ChannelGroupIdPtr->maskl) ) | ( Level << ChannelGroupIdPtr->offset );
}