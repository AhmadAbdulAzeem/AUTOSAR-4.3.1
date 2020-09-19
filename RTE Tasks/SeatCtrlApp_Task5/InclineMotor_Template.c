/**
 *
 * \file InclineMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: InclineMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/13/2020 05:27 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_InclineMotor.h"


/**
 *
 * Runnable InclineMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppInclineMotor_Move
 *
 */

void InclineMotor_Move (StepMotorStepType step)
{
	Std_ReturnType status;

	/* Server Call Points */
	status = Rte_Call_rpIOSetIncline_IOSetForward();
	status = Rte_Call_rpIOSetIncline_IOSetReverse();
	
}

