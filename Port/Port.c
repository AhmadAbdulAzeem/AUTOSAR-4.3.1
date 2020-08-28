#include "Port.h"

const Port_ConfigType* configuredPins;
boolean PortPinModeChangeable[PINS_NUMBER];

void Port_Init( const Port_ConfigType* ConfigPtr )
{
	uint8_t itr;
	Port_Id port;
	Port_PinType PortPinId;
	
	configuredPins = ConfigPtr;
	
	for(itr = 0; itr < ConfigPtr->PortNumberOfPortPins; itr++)
	{
		port = ConfigPtr->pinsArray[itr].port;
		PortPinId = (ConfigPtr->pinsArray[itr].PortPinId) % PINS_NUMBER_PER_PORT;
		
		PortPinModeChangeable[(ConfigPtr->pinsArray[itr].PortPinId)] = (ConfigPtr->pinsArray[itr].PortPinModeChangeable);
		
		/* Enable clock to port */
		if(port == PORTA)
		{
			SYSCTL_RCGCGPIO_R |= 1;
		}
		else if(port == PORTB)
		{
			SYSCTL_RCGCGPIO_R |= 2;
		}
		else if(port == PORTC)
		{
			SYSCTL_RCGCGPIO_R |= 4;
		}
		else if(port == PORTD)
		{
			SYSCTL_RCGCGPIO_R |= 8;
		}
		else if(port == PORTE)
		{
			SYSCTL_RCGCGPIO_R |= 16;
		}
		else
		{
			SYSCTL_RCGCGPIO_R |= 32;
		}
		
		REG(port, GPIOLOCK_OFFSET) = 0x4C4F434B;
		
		/* Set the direction of the GPIO port pin */
		REG(port, GPIODIR_OFFSET) = (REG(port, GPIODIR_OFFSET) & (~(1 << PortPinId)) ) | (ConfigPtr->pinsArray[itr].PortPinDirection<<PortPinId);
		
		if(ConfigPtr->pinsArray[itr].PortPinInitialMode != PORT_PIN_MODE_DIO)
		{
			/* Configure the GPIOAFSEL register to program each bit as alternate pin */
			REG(port, GPIOAFSEL_OFFSET) = (REG(port, GPIOAFSEL_OFFSET) & (~(1 << PortPinId)) ) | (1<<PortPinId);
			
			if(ConfigPtr->pinsArray[itr].PortPinInitialMode == PORT_PIN_MODE_ADC)
			{
				/* Enable analog function for adc */
				REG(port, GPIOAMSEL_OFFSET) = (REG(port, GPIOAMSEL_OFFSET) & (~(1 << PortPinId)) ) | (1<<PortPinId);
			}
			
			/* other alternative functions not implemented for now */
		}
		else		/* DIO */
		{
			REG(port, GPIOICR_OFFSET) = 0XFF;
			REG(port, GPIOAFSEL_OFFSET) &= ~ (1<<PortPinId);
			REG(port, GPIOPCTL_OFSSET) &= (0xf<<PortPinId);
			REG(port, GPIOAMSEL_OFFSET) &= ~ (1<<PortPinId);
			REG(port, GPIODEN_OFFSET) = (REG(port, GPIODEN_OFFSET) & (~(1 << PortPinId)) ) | (1<<PortPinId);
			
			/* write pin level */
			if(ConfigPtr->pinsArray[itr].PortPinDirection == PORT_PIN_OUT)
			{
				REG(port, GPIODATA_OFFSET) = (REG(port, GPIODATA_OFFSET) & (~(1 << PortPinId)) ) | (ConfigPtr->pinsArray[itr].PortPinLevelValue<<PortPinId);
			}
		}
		
		/* configure pullup resistor */
		REG(port, GPIOPUR_OFFSET) = (REG(port, GPIOPUR_OFFSET) & (~(1 << PortPinId)) ) | (ConfigPtr->pinsArray[itr].pullUp<<PortPinId);
	}
	
}

Port_Id getPortId(Port_PinType PortPinId)
{
	uint8_t port;
	port = ( (PortPinId/PINS_NUMBER_PER_PORT) % (PORTS_NUMBER) );
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

#if(PortSetPinDirectionApi == STD_ON)
	void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction )
	{
		Port_Id portId = getPortId(Pin);
		Pin = Pin % PINS_NUMBER_PER_PORT;
		/* Set the direction of the GPIO port pin */
		REG(portId, GPIODIR_OFFSET) = (REG(portId, GPIODIR_OFFSET) & (~(1 << Pin)) ) | (Direction<<Pin);
	}
#endif
	
void Port_RefreshPortDirection( void )
{
	uint8_t itr;
	Port_Id port;
	Port_PinType PortPinId;
	uint8_t numberOfPins = configuredPins->PortNumberOfPortPins;
	
	for(itr = 0; itr < numberOfPins; itr++)
	{
		port = configuredPins->pinsArray[itr].port;
		PortPinId = (configuredPins->pinsArray[itr].PortPinId) % PINS_NUMBER_PER_PORT;
		if(configuredPins->pinsArray[itr].PortPinDirectionChangeable == TRUE)
		{
			/* [SWS_Port_00061] ?The function Port_RefreshPortDirection shall
			exclude those port pins from refreshing that are configured as
			pin direction changeable during runtime‘.? (SRS_Port_12406) */
			continue;
		}
		/* Set the direction of the GPIO port pin */
		REG(port, GPIODIR_OFFSET) = (REG(port, GPIODIR_OFFSET) & (~(1 << PortPinId)) ) | (configuredPins->pinsArray[itr].PortPinDirection<<PortPinId);
	}
}

#if(PortSetPinModeApi == STD_ON)
	void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{
	Port_Id portId = getPortId(Pin);
	Pin = Pin % PINS_NUMBER_PER_PORT;
	
	#if(PortDevErrorDetect == STD_ON)
		if(PortPinModeChangeable[Pin] == FALSE)
		{
			/*[SWS_Port_00223] ?If Det is enabled, the function Port_SetPinMode shall report
			PORT_E_MODE_UNCHANGEABLE error and return without any other action, if the parameter
			PortPinModeChangeable is set to FALSE */
		}
	#endif
		
	/* Configure the GPIOAFSEL register to program each bit as alternate pin */
	REG(portId, GPIOAFSEL_OFFSET) = (REG(portId, GPIOAFSEL_OFFSET) & (~(1 << Pin)) ) | (1<<Pin);
			
	if(Mode == PORT_PIN_MODE_ADC)
	{
		/* Enable analog function for adc */
		REG(portId, GPIOAMSEL_OFFSET) = (REG(portId, GPIOAMSEL_OFFSET) & (~(1 << Pin)) ) | (1<<Pin);
	}
			
	/* other alternative functions not implemented for now */
}
#endif


#if(PortVersionInfoApi == STD_ON)
	void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
	{
		/* Not implented for now */
	}
#endif
	
