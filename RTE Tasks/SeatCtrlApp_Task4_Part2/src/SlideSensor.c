/**
 *
 * \file SlideSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SlideSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/13/2020 11:53 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SlideSensor.h"


/**
 *
 * Runnable SlideSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideSensor_GetPosition
 *
 */

void SlideSensor_GetPosition (SensorPositionType* position)
{
	Std_ReturnType status;
	IoPositionSensorReadingType position;

	/* Server Call Points */
	status = Rte_Call_rpIOGetSlide_IOGet(&position);
	
	if(position == 0)
		position = SENSOR_POSITION_STEP_1;
	if(position > 0 && position <= 64)
		position = SENSOR_POSITION_STEP_1;
	if(position > 64 && position <= 192)
		position = SENSOR_POSITION_STEP_2;
	if(position > 192 && position <= 255)
		position = SENSOR_POSITION_STEP_3;
}

