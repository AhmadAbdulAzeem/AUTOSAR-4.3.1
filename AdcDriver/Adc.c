#include "Adc.h"
#include "Adc_MemMap.h"
#include "tm4c123gh6pm.h"



/* Array of pointers to hold the address of the result buffer given by the user for each group. */
static Adc_ValueGroupType* DataBufferPtrAddr[Max_No_Of_Groups];

/* array to hold groups info */
groupInfo groupChannelArray[Max_No_Of_Groups];

/* array to check whether the result buffer has been initialized for the corresponding group or not */
static boolean Adc_resultBufferInit[8];


Adc_DriverStateType Adc_DriverState  = ADC_DRIVER_NOT_INIT;

void Adc_Init ( const Adc_ConfigType* ConfigPtr )
{
		int i;
		boolean adcFlag = TRUE;
		/* dummy variable to wait 3 clocks */
		volatile uint32_t delay;		
	
		if(ConfigPtr->AdcModuleId == ADC_MODULE0)
		{
				for(i = 0; i < ConfigPtr->AdcGroupNumOfChannels; i++)
				{
					if((ConfigPtr->channelArray[i] >= 4) && (ConfigPtr->channelArray[i] <= 7))
					{
						SYSCTL_RCGCGPIO_R |= 8;  		/* enable clock to port D */
						delay = 0;
						if(adcFlag == TRUE)
						{
							adcFlag = FALSE;
							/* enable clock to ADC0 */
							SYSCTL_RCGCADC_R |= 1;
							delay = 0;
						}
						if(ConfigPtr->channelArray[i] == PE5)
						{
							GPIO_PORTD_AFSEL_R |= 0X20;    		//enable alternate function
							GPIO_PORTD_DEN_R &= ~0X20;					//disable digital function
							GPIO_PORTD_AMSEL_R |= 0X20;				//enable analog function
						}
						else
						{
							GPIO_PORTD_AFSEL_R |= (8 >> ConfigPtr->channelArray[i]);  //enable alternate function
							GPIO_PORTD_DEN_R &= ~(8 >> ConfigPtr->channelArray[i]);					//disable digital function
							GPIO_PORTD_AMSEL_R |= (8 >> ConfigPtr->channelArray[i]);				//enable analog function
						}
					}
					else
					{
						SYSCTL_RCGCGPIO_R |= 0x10;  		/* enable clock to port E */
						delay = 0;
						if(adcFlag == TRUE)
						{
							adcFlag = FALSE;
							/* enable clock to ADC0 */
							SYSCTL_RCGCADC_R |= 1;
							delay = 0;
						}
						if(ConfigPtr->channelArray[i] == PE5)
						{
							GPIO_PORTE_AFSEL_R |= 0X20;    		//enable alternate function
							GPIO_PORTE_DEN_R &= ~0X20;					//disable digital function
							GPIO_PORTE_AMSEL_R |= 0X20;				//enable analog function
						}
						else
						{
							GPIO_PORTE_AFSEL_R |= (8 >> ConfigPtr->channelArray[i]);  //enable alternate function
							GPIO_PORTE_DEN_R &= ~(8 >> ConfigPtr->channelArray[i]);					//disable digital function
							GPIO_PORTE_AMSEL_R |= (8 >> ConfigPtr->channelArray[i]);				//enable analog function
						}
					}
				}
				
				
				
				/* disable Sample sequencer during configuration */
				ADC0_ACTSS_R &= ~(1 << ConfigPtr->AdcSequencerId);	
			
				/* software trigger conversion */
				if(ConfigPtr->AdcTriggerSource == ADC_TRIGG_SRC_SW)
				{
						ADC0_EMUX_R &= ~(0X000F << (ConfigPtr->AdcSequencerId * 4));
				}
				if(ConfigPtr->AdcTriggerSource == ADC_TRIGG_SRC_SW)
				{
					ADC0_EMUX_R |= ((ConfigPtr->AdcHwTriggerSource) << (ConfigPtr->AdcSequencerId * 4));
				}
				
				for(i = 0; i < ConfigPtr->AdcGroupNumOfChannels; i++)
				{
					if(ConfigPtr->AdcSequencerId == Adc_SS0)
					{
						ADC0_SSMUX0_R &= ~(0X000F << (ConfigPtr->channelArray[i] * 4));
						ADC0_SSCTL0_R |= (0x04<<(4*i));
					}
					else if(ConfigPtr->AdcSequencerId == Adc_SS1)
					{
						ADC0_SSMUX1_R &= ~(0X000F << (ConfigPtr->channelArray[i] * 4));
						ADC0_SSCTL1_R |= (0x04<<(4*i));
					}
					else if(ConfigPtr->AdcSequencerId == Adc_SS2)
					{
						ADC0_SSMUX2_R &= ~(0X000F << (ConfigPtr->channelArray[i] * 4));
						ADC0_SSCTL2_R |= (0x04<<(4*i));
					}
					else
					{
						ADC0_SSMUX3_R &= ~(0X000F << (ConfigPtr->channelArray[i] * 4));
						ADC0_SSCTL3_R |= (0x04<<(4*i));
					}
				}
		}
		if(ConfigPtr->AdcModuleId == ADC_MODULE1)
		{
			
				for(i = 0; i < ConfigPtr->AdcGroupNumOfChannels; i++)
				{
					if((ConfigPtr->channelArray[i] >= 4) && (ConfigPtr->channelArray[i] <= 7))
					{
						SYSCTL_RCGCGPIO_R |= 8;  		/* enable clock to port D */
						delay = 0;
						if(adcFlag == TRUE)
						{
							adcFlag = FALSE;
							/* enable clock to ADC1 */
							SYSCTL_RCGCADC_R |= 2;
							delay = 0;
						}
						if(ConfigPtr->channelArray[i] == PE5)
						{
							GPIO_PORTD_AFSEL_R |= 0X20;    		//enable alternate function
							GPIO_PORTD_DEN_R &= ~0X20;					//disable digital function
							GPIO_PORTD_AMSEL_R |= 0X20;				//enable analog function
						}
						else
						{
							GPIO_PORTD_AFSEL_R |= (8 >> ConfigPtr->channelArray[i]);  //enable alternate function
							GPIO_PORTD_DEN_R &= ~(8 >> ConfigPtr->channelArray[i]);					//disable digital function
							GPIO_PORTD_AMSEL_R |= (8 >> ConfigPtr->channelArray[i]);				//enable analog function
						}
					}
					else
					{
						SYSCTL_RCGCGPIO_R |= 0x10;  		/* enable clock to port E */
						delay = 0;
						if(adcFlag == TRUE)
						{
							adcFlag = FALSE;
							/* enable clock to ADC1 */
							SYSCTL_RCGCADC_R |= 2;
							delay = 0;
						}
						if(ConfigPtr->channelArray[i] == PE5)
						{
							GPIO_PORTE_AFSEL_R |= 0X20;    		//enable alternate function
							GPIO_PORTE_DEN_R &= ~0X20;					//disable digital function
							GPIO_PORTE_AMSEL_R |= 0X20;				//enable analog function
						}
						else
						{
							GPIO_PORTE_AFSEL_R |= (8 >> ConfigPtr->channelArray[i]);  //enable alternate function
							GPIO_PORTE_DEN_R &= ~(8 >> ConfigPtr->channelArray[i]);					//disable digital function
							GPIO_PORTE_AMSEL_R |= (8 >> ConfigPtr->channelArray[i]);				//enable analog function
						}
					}
				}
				
				
				/* disable Sample sequencer during configuration */
				ADC1_ACTSS_R &= ~(1 << ConfigPtr->AdcSequencerId);
				
				/* software trigger conversion */
				if(ConfigPtr->AdcTriggerSource == ADC_TRIGG_SRC_SW)
				{
						ADC1_EMUX_R &= ~(0X000F << (ConfigPtr->AdcSequencerId * 4));
				}
				if(ConfigPtr->AdcTriggerSource == ADC_TRIGG_SRC_SW)
				{
					ADC1_EMUX_R |= ((ConfigPtr->AdcHwTriggerSource) << (ConfigPtr->AdcSequencerId * 4));
				}
				
				for(i = 0; i < ConfigPtr->AdcGroupNumOfChannels; i++)
				{
					if(ConfigPtr->AdcSequencerId == Adc_SS0)
					{
						ADC1_SSMUX0_R &= ~(0X000F << (ConfigPtr->channelArray[i] * 4));
						ADC1_SSCTL0_R |= (0x04<<(4*i));
					}
					else if(ConfigPtr->AdcSequencerId == Adc_SS1)
					{
						ADC1_SSMUX1_R &= ~(0X000F << (ConfigPtr->channelArray[i] * 4));
						ADC1_SSCTL1_R |= (0x04<<(4*i));
					}
					else if(ConfigPtr->AdcSequencerId == Adc_SS2)
					{
						ADC1_SSMUX2_R &= ~(0X000F << (ConfigPtr->channelArray[i] * 4));
						ADC1_SSCTL2_R |= (0x04<<(4*i));
					}
					else
					{
						ADC1_SSMUX3_R &= ~(0X000F << (ConfigPtr->channelArray[i] * 4));
						ADC1_SSCTL3_R |= (0x04<<(4*i));
					}
				}
		}
		/* enable Sample sequencer */
		ADC0_ACTSS_R |= (1 << ConfigPtr->AdcSequencerId);	
		
		Adc_DriverState = ADC_DRIVER_INITIALIZED;
		
		/* Initialize group */
		groupChannelArray[ConfigPtr->AdcGroupId].AdcGroupConversionMode = ConfigPtr->AdcGroupConversionMode;
		groupChannelArray[ConfigPtr->AdcGroupId].AdcGroupNumOfChannels = ConfigPtr->AdcGroupNumOfChannels;
		groupChannelArray[ConfigPtr->AdcGroupId].AdcModuleId = ConfigPtr->AdcModuleId;
		groupChannelArray[ConfigPtr->AdcGroupId].AdcSequencerId = ConfigPtr->AdcSequencerId;
		groupChannelArray[ConfigPtr->AdcGroupId].AdcGroupPriority = ConfigPtr->AdcGroupPriority;
		groupChannelArray[ConfigPtr->AdcGroupId].AdcStreamingBufferMode = ConfigPtr->AdcStreamingBufferMode;
		groupChannelArray[ConfigPtr->AdcGroupId].groupStatus = ADC_IDLE;
		groupChannelArray[ConfigPtr->AdcGroupId].AdcTriggerSource = ConfigPtr->AdcTriggerSource;
}

Std_ReturnType Adc_SetupResultBuffer( Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr )
{
	Std_ReturnType Std_Return = E_OK;
	
	/* Development error reporting not supported for now*/
	
	/* take the address of the result buffer and save it in global variable */
	DataBufferPtrAddr[Group] = DataBufferPtr;
	
	/* Result buffer has been setup successfully for the required group */
	Adc_resultBufferInit[Group]=TRUE;
	
	return Std_Return;
	
}

void Adc_DeInit( void )
{
	ADC0_EMUX_R &= ~0xffffffff;
	ADC1_EMUX_R &= ~0xffffffff;
	
	ADC0_ACTSS_R &= ~0XF;
	ADC1_ACTSS_R &= ~0XF;
	
	SYSCTL_RCGCADC_R &= ~0X3;
}

void Adc_StartGroupConversion( Adc_GroupType Group )
{
	#if(ADC_DEV_ERROR_DETECT == STD_ON)
		if(Group >= Max_No_Of_Groups)
		{
			/* development error ADC_E_PARAM_GROUP */
		}
		if(groupChannelArray[Group].AdcTriggerSource == ADC_TRIGG_SRC_HW)
		{
			/* development error ADC_E_WRONG_TRIGG_SRC */
		}
		if(groupChannelArray[Group].groupStatus != ADC_IDLE)
		{
			/* runtime error ADC_E_BUSY */
		}
	#endif
	
	groupChannelArray[Group].groupStatus = ADC_BUSY;
	if(groupChannelArray[Group].AdcModuleId == ADC_MODULE0)
	{
		ADC0_PSSI_R |= (1<<groupChannelArray[Group].AdcSequencerId);
	}
	if(groupChannelArray[Group].AdcModuleId == ADC_MODULE1)
	{
		ADC1_PSSI_R |= (1<<groupChannelArray[Group].AdcSequencerId);
	}
}


Adc_StatusType Adc_GetGroupStatus( Adc_GroupType Group )
{
	int i;
	if(groupChannelArray[Group].AdcModuleId == ADC_MODULE0)
	{
		if(groupChannelArray[Group].AdcSequencerId == Adc_SS0)
		{
			while((ADC0_SSFSTAT0_R & (0X100)) == 1);
			for(i = 0; i < groupChannelArray[Group].AdcGroupNumOfChannels; i++)
			{
				*(DataBufferPtrAddr[Group] + i) = ADC0_SSFIFO0_R;
			}
		}
		if(groupChannelArray[Group].AdcSequencerId == Adc_SS1)
		{
			while((ADC0_SSFSTAT1_R & (0X100)) == 1);
			for(i = 0; i < groupChannelArray[Group].AdcGroupNumOfChannels; i++)
			{
				*(DataBufferPtrAddr[Group] + i) = ADC0_SSFIFO1_R;
			}
		}
		if(groupChannelArray[Group].AdcSequencerId == Adc_SS2)
		{
			while((ADC0_SSFSTAT2_R & (0X100)) == 1);
			for(i = 0; i < groupChannelArray[Group].AdcGroupNumOfChannels; i++)
			{
				*(DataBufferPtrAddr[Group] + i) = ADC0_SSFIFO2_R;
			}
		}
		if(groupChannelArray[Group].AdcSequencerId == Adc_SS3)
		{
			while((ADC0_SSFSTAT3_R & (0X100)) == 1);
			for(i = 0; i < groupChannelArray[Group].AdcGroupNumOfChannels; i++)
			{
				*(DataBufferPtrAddr[Group] + i) = ADC0_SSFIFO3_R;
			}
		}
	}
	
	if(groupChannelArray[Group].AdcModuleId == ADC_MODULE1)
	{
		if(groupChannelArray[Group].AdcSequencerId == Adc_SS0)
		{
			while((ADC1_SSFSTAT0_R & (0X100)) == 1);
			for(i = 0; i < groupChannelArray[Group].AdcGroupNumOfChannels; i++)
			{
				*(DataBufferPtrAddr[Group] + i) = ADC1_SSFIFO0_R;
			}
		}
		if(groupChannelArray[Group].AdcSequencerId == Adc_SS1)
		{
			while((ADC1_SSFSTAT1_R & (0X100)) == 1);
			for(i = 0; i < groupChannelArray[Group].AdcGroupNumOfChannels; i++)
			{
				*(DataBufferPtrAddr[Group] + i) = ADC1_SSFIFO1_R;
			}
		}
		if(groupChannelArray[Group].AdcSequencerId == Adc_SS2)
		{
			while((ADC1_SSFSTAT2_R & (0X100)) == 1);
			for(i = 0; i < groupChannelArray[Group].AdcGroupNumOfChannels; i++)
			{
				*(DataBufferPtrAddr[Group] + i) = ADC1_SSFIFO2_R;
			}
		}
		if(groupChannelArray[Group].AdcSequencerId == Adc_SS3)
		{
			while((ADC1_SSFSTAT3_R & (0X100)) == 1);
			for(i = 0; i < groupChannelArray[Group].AdcGroupNumOfChannels; i++)
			{
				*(DataBufferPtrAddr[Group] + i) = ADC1_SSFIFO3_R;
			}
		}
	}
	groupChannelArray[Group].groupStatus = ADC_COMPLETED;
	
	return ADC_COMPLETED;
}

Std_ReturnType Adc_ReadGroup( Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr )
{
	int i;
	for(i = 0; i < groupChannelArray[Group].AdcGroupNumOfChannels; i++)
	{
		DataBufferPtr[i] = *(DataBufferPtrAddr[Group] + i);
	}
	return E_OK ;
}

		
