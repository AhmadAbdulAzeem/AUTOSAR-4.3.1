#include "Port.h"
#include "Dio.h"


void SystemInit(){}
PortPin pins = {PORT_PIN_OUT, TRUE, PF4, PORT_PIN_MODE_DIO, PORT_PIN_LEVEL_LOW, FALSE, PORTF};
Port_ConfigType port = {&pins, 1};

	
// delay n milliseconds (16 MHz CPU clock) 
void delayMs(int n)
{
int i, j;
for(i = 0 ; i < n; i++)
for(j = 0; j < 3180; j++)
{} // do nothing for 1 ms 
}


int main()
{
	Dio_LevelType level;
	Port_Init(&port);
	//Port_SetPinDirection(PF4, PORT_PIN_IN);
	while(1)
	{
		//Dio_WriteChannel(PF4,PORT_PIN_LEVEL_HIGH);
		//Dio_WritePort(PORTF, PORT_PIN_LEVEL_HIGH);
		level = Dio_FlipChannel(PF4);
	}
}
