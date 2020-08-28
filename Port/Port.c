#include "Port.h"

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
		PortPinId = ConfigPtr->pinsArray[i].PortPinId;
		
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
