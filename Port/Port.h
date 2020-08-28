#ifndef PORT_H
#define PORT_H

#include "Std_Types.h"
#include "Port_Cfg.h"
#include "Port_MemMap.h"

/* Data type for the symbolic name of a port pin. */
typedef uint8_t Port_PinType;

/* Possible directions of a port pin. */
typedef enum{
	PORT_PIN_IN,
	PORT_PIN_OUT
}Port_PinDirectionType;

typedef enum{
	PORT_PIN_MODE_ADC,
	PORT_PIN_MODE_CAN,
	PORT_PIN_MODE_DIO,
	PORT_PIN_MODE_DIO_GPT,
	PORT_PIN_MODE_DIO_WDG,
	PORT_PIN_MODE_FLEXRAY,
	PORT_PIN_MODE_ICU,
	PORT_PIN_MODE_LIN,
	PORT_PIN_MODE_MEM,
	PORT_PIN_MODE_PWM,
	PORT_PIN_MODE_SPI
}Pin_Mode;

typedef enum{
	PORT_PIN_LEVEL_LOW,
	PORT_PIN_LEVEL_HIGH
}Pin_Level;


/* Different port pin modes. */
typedef uint8_t Port_PinModeType;


typedef enum{
	PORTA = 0X40004000,
	PORTB = 0x40005000,
	PORTC = 0x40006000,
	PORTD = 0x40007000,
	PORTE = 0x40024000,
	PORTF = 0x40025000
}Port_Id;

/* Type of the external data structure containing the initialization data for this module */
typedef struct{
	/* The initial direction of the pin (IN or OUT) */
	Port_PinDirectionType PortPinDirection;
	
	/* Parameter to indicate if the direction is changeable on a port pin during runtime. */
	boolean PortPinDirectionChangeable;
	
	/* Pin Id of the port pin. */
	Port_PinType PortPinId;
	
	/* Port pin mode from mode list for use with Port_Init() function.*/
	Pin_Mode PortPinInitialMode;
	
	/* Port Pin Level value from Port pin list. */
	Pin_Level PortPinLevelValue;
	
	/* Activation of internal pull-ups. */
	boolean pullUp;
	
	Port_Id port;
}PortPin;

typedef struct{
	PortPin* pinsArray;
	uint8_t PortNumberOfPortPins;
}Port_ConfigType;

void Port_Init( const Port_ConfigType* ConfigPtr );
Port_Id getPortId(Port_PinType PortPinId);

#if(PortSetPinDirectionApi == STD_ON)
	void Port_SetPinDirection( Port_PinType Pin, Port_PinDirectionType Direction );
#endif

void Port_RefreshPortDirection( void );

#endif
