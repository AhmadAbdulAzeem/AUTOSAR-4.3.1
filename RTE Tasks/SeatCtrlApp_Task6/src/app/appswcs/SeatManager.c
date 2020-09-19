/**
 *
 * \file SeatManager_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: SeatManager
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/4/2020 08:49 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_SeatManager.h"


/**
 *
 * Runnable SeatManager_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoHeight_200ms
 *
 */
 
 static boolean IsMotorAdjustNeeded(SensorPositionType Position, SensorWeightType Weight, StepMotorStepType* Step)
{
	boolean adjustMotor = FALSE;
	
	switch(Position)
	{
		case SENSOR_POSITION_STEP_0:
			if(Weight > 60)
			{
				*Step = MOTOR_STEP_PLUS;
				adjustMotor = TRUE;
			}
			break;
			
		case SENSOR_POSITION_STEP_1:
			if(Weight > 80)
			{
				*Step = MOTOR_STEP_PLUS;
				adjustMotor = TRUE;
			}
			else if(Weight <= 80 && Weight >= 60)
			{
				/* Position OK */
			}
			else
			{
				*Step = MOTOR_STEP_MINUS;
				adjustMotor = TRUE;
			}
			break;
			
		case SENSOR_POSITION_STEP_2:
			if(Weight > 100)
			{
				*Step = MOTOR_STEP_PLUS;
				adjustMotor = TRUE;
			}
			else if(Weight <= 100 && Weight >= 80)
			{
				/* Position OK */
			}
			else
			{
				*Step = MOTOR_STEP_MINUS;
				adjustMotor = TRUE;
			}
			break;
			
		case SENSOR_POSITION_STEP_3:
			if(Weight < 100)
			{
				*Step = MOTOR_STEP_MINUS;
				adjustMotor = TRUE;
			}
			break;		
			
		default:
			break;
	}
	
	return adjustMotor;
}
 
 

void SeatManager_AutoHeight (void)
{
	StepMotorStepType Step;
	SensorPositionType Position;
	SensorWeightType Weight;
	boolean adjustMotor;

	(void)Rte_Call_rpHeightSensor_GetPosition(&Position);
	(void)Rte_Call_rpWeightSensor_GetWeight(&Weight);
	
	adjustMotor = IsMotorAdjustNeeded(Position, Weight, &Step);
	if(adjustMotor)
	{
		(void)Rte_Call_rpHeightMotor_Move(Step);
	}
}


/**
 *
 * Runnable SeatManager_AutoIncline
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoIncline_200ms
 *
 */

void SeatManager_AutoIncline (void)
{
	StepMotorStepType Step;
	SensorPositionType Position;
	SensorWeightType Weight;
	boolean adjustMotor;

	(void)Rte_Call_rpInclineSensor_GetPosition(&Position);
	(void)Rte_Call_rpWeightSensor_GetWeight(&Weight);
	
	adjustMotor = IsMotorAdjustNeeded(Position, Weight, &Step);
	if(adjustMotor)
	{
		(void)Rte_Call_rpInclineMotor_Move(Step);
	}
}


/**
 *
 * Runnable SeatManager_AutoSlide
 *
 * Triggered By:
 *  - TimingEventImpl.TE_SeatManager_AutoSlide_200ms
 *
 */

void SeatManager_AutoSlide (void)
{
	StepMotorStepType Step;
	SensorPositionType Position;
	SensorWeightType Weight;
	boolean adjustMotor;

	(void)Rte_Call_rpSlideSensor_GetPosition(&Position);
	(void)Rte_Call_rpWeightSensor_GetWeight(&Weight);
	
	adjustMotor = IsMotorAdjustNeeded(Position, Weight, &Step);
	if(adjustMotor)
	{
		(void)Rte_Call_rpSlideMotor_Move(Step);
	}
}


/**
 *
 * Runnable SeatManager_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_HeightBtnState
 *
 */

void SeatManager_SetHeight (void)
{
	Std_ReturnType status;
	MultiStateBtnType HeightBtnState;
	StepMotorStepType step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_HeightBtnState(&HeightBtnState);
	
	if(HeightBtnState == MULTI_STATE_BTN_MINUS)
		status = Rte_Call_rpHeightMotor_Move(MOTOR_STEP_MINUS);
	
	if(HeightBtnState == MULTI_STATE_BTN_PLUS)
		status = Rte_Call_rpHeightMotor_Move(MOTOR_STEP_PLUS);	
}


/**
 *
 * Runnable SeatManager_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_InclineBtnState
 *
 */

void SeatManager_SetIncline (void)
{
	Std_ReturnType status;
	MultiStateBtnType InclineBtnState;
	StepMotorStepType step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_InclineBtnState(&InclineBtnState);
	
	if(InclineBtnState == MULTI_STATE_BTN_MINUS)
		status = Rte_Call_rpInclineMotor_Move(MOTOR_STEP_MINUS);
	
	if(InclineBtnState == MULTI_STATE_BTN_PLUS)
		status = Rte_Call_rpInclineMotor_Move(MOTOR_STEP_PLUS);
	
	
}


/**
 *
 * Runnable SeatManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatCtrlBtns_SlideBtnState
 *
 */

void SeatManager_SetSlide (void)
{
	Std_ReturnType status;
	MultiStateBtnType SlideBtnState;
	StepMotorStepType step;

	/* Data Receive Points */
	status = Rte_Read_rpSeatCtrlBtns_SlideBtnState(&SlideBtnState);
	
	if(SlideBtnState == MULTI_STATE_BTN_MINUS)
		status = Rte_Call_rpSlideMotor_Move(MOTOR_STEP_MINUS);
	
	if(SlideBtnState == MULTI_STATE_BTN_PLUS)
		status = Rte_Call_rpSlideMotor_Move(MOTOR_STEP_PLUS);
	
	
}

