/**
 *
 * \brief Sprints AUTOSAR Master Class - SeatCtrlApp
 * \author Hassan Farahat
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */
 
#include "Dio.h"
#include "vfb.h"

#include <stdio.h>

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	/* Write to VFB variables */
	switch(ChannelId)
	{
		case DioConfg_DioChannel_HeightMotorCh:
			VFB_HeightMotorState = (VFB_MotorStateEnum)Level;
			if(Level == STD_HIGH)
			{
				VFB_HeightPosition++;
			}
			else
			{
				VFB_HeightPosition--;
			}
			break;
			
		case DioConfg_DioChannel_InclineMotorCh:
			VFB_InclineMotorState = (VFB_MotorStateEnum)Level;
			if(Level == STD_HIGH)
			{
				VFB_InclinePosition++;
			}
			else
			{
				VFB_InclinePosition--;
			}
			break;
			
		case DioConfg_DioChannel_SlideMotorCh:
			VFB_SlideMotorState = (VFB_MotorStateEnum)Level;
			if(Level == STD_HIGH)
			{
				VFB_SlidePosition++;
			}
			else
			{
				VFB_SlidePosition--;
			}
			break;
			
		default:
			break;
	}

	printf("CurrentPosition:\n");
	printf("VFB_HeightPosition = %d\n", VFB_HeightPosition);
	printf("VFB_InclinePosition = %d\n", VFB_InclinePosition);
	printf("VFB_SlidePosition = %d\n", VFB_SlidePosition);
	printf("-------------------------------\n");
}
