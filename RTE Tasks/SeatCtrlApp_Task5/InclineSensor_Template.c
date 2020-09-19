/**
 *
 * \file InclineSensor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: InclineSensor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/13/2020 05:27 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_InclineSensor.h"


/**
 *
 * Runnable InclineSensor_GetPosition
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppInclineSensor_GetPosition
 *
 */

void InclineSensor_GetPosition (SensorPositionType* position)
{
	Std_ReturnType status;
	IoPositionSensorReadingType position;

	/* Server Call Points */
	status = Rte_Call_rpIOGetIncline_IOGet(&position);
	
}

