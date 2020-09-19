/**
 *
 * \file SlideMotor_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SlideMotor
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/13/2020 11:53 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SlideMotor.h"


/**
 *
 * Runnable SlideMotor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppSlideMotor_Move
 *
 */

void SlideMotor_Move (StepMotorStepType step)
{
	Std_ReturnType status;

	if(step == MOTOR_STEP_PLUS)
		status = Rte_Call_rpIOSetHeight_IOSetForward();
	if(step == MOTOR_STEP_MINUS)
		status = Rte_Call_rpIOSetHeight_IOSetReverse();
	
}

