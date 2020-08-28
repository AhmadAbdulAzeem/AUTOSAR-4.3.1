#include "Port.h"
#include "tm4c123gh6pm.h"

void Port_Init( const Port_ConfigType* ConfigPtr )
{
	uint8_t i;
	uint8_t delay;
	Port_Id port;
	Port_PinType PortPinId;
	port = ConfigPtr->port;
	
	/* Enable clock to port */
	if(port == PORTA)
		SYSCTL_RCGCGPIO_R |= 1;
	else if(port == PORTB)
		SYSCTL_RCGCGPIO_R |= 2;
	else if(port == PORTC)
		SYSCTL_RCGCGPIO_R |= 4;
	else if(port == PORTD)
		SYSCTL_RCGCGPIO_R |= 8;
	else if(port == PORTE)
		SYSCTL_RCGCGPIO_R |= 16;
	else
		SYSCTL_RCGCGPIO_R |= 32;
	delay = 0;		/* wait 3 clocks */
	
	REG(port, GPIOLOCK_OFFSET) = 0x4C4F434B;
	
	for(i = 0; i < ConfigPtr->PortNumberOfPortPins; i++)
	{
		PortPinId = (ConfigPtr->pinsArray[i].PortPinId) % PINS_NUMBER_PER_PORT;
		
		/* Set the direction of the GPIO port pin */
		REG(port, GPIODIR_OFFSET) = (REG(port, GPIODIR_OFFSET) & (~(1 << PortPinId)) ) | (ConfigPtr->pinsArray[i].PortPinDirection<<PortPinId);
		
		if(ConfigPtr->pinsArray[i].PortPinInitialMode != PORT_PIN_MODE_DIO)
		{
			/* Configure the GPIOAFSEL register to program each bit as alternate pin */
			REG(port, GPIOAFSEL_OFFSET) = (REG(port, GPIOAFSEL_OFFSET) & (~(1 << PortPinId)) ) | (1<<PortPinId);
			
			if(ConfigPtr->pinsArray[i].PortPinInitialMode == PORT_PIN_MODE_ADC)
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
			if(ConfigPtr->pinsArray[i].PortPinDirection == PORT_PIN_OUT)
			{
				REG(port, GPIODATA_OFFSET) = (REG(port, GPIODATA_OFFSET) & (~(1 << PortPinId)) ) | (ConfigPtr->pinsArray[i].PortPinLevelValue<<PortPinId);
			}
		}
		
		/* configure pullup resistor */
		REG(port, GPIOPUR_OFFSET) = (REG(port, GPIOPUR_OFFSET) & (~(1 << PortPinId)) ) | (ConfigPtr->pinsArray[i].pullUp<<PortPinId);
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
