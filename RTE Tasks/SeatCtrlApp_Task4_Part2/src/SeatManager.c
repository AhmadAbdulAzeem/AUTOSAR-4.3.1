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

void SeatManager_AutoHeight (void)
{
	Std_ReturnType status;
	StepMotorStepType step = 0;
	SensorPositionType position;
	SensorWeightType Weighr;	//weight

	status = Rte_Call_rpWeightSensor_GetWeight(&Weighr);
	status = Rte_Call_rpHeightSensor_GetPosition(&position);
	if(Weighr > 100)
	{
		while(position != SENSOR_POSITION_STEP_3)
		{
			if(position < SENSOR_POSITION_STEP_3)
				status = Rte_Call_rpHeightMotor_Move(step++);
			else
				status = Rte_Call_rpHeightMotor_Move(step--);
			status = Rte_Call_rpHeightSensor_GetPosition(&position); 
		}
	}
	
	if(weighr < 80 && weighr > 100)
	{
		while(position != SENSOR_POSITION_STEP_2)
		{
			if(position < SENSOR_POSITION_STEP_2)
				status = Rte_Call_rpHeightMotor_Move(step++);
			else
				status = Rte_Call_rpHeightMotor_Move(step--);
			status = Rte_Call_rpHeightSensor_GetPosition(&position);
		}
	}
	
	if(weighr < 60 && weighr > 80)
	{
		while(position != SENSOR_POSITION_STEP_1)
		{
			if(position < SENSOR_POSITION_STEP_1)
				status = Rte_Call_rpHeightMotor_Move(step++);
			else
				status = Rte_Call_rpHeightMotor_Move(step--);
			status = Rte_Call_rpHeightSensor_GetPosition(&position);
		}
	}
	
	if(weighr < 60)
	{
		while(position != SENSOR_POSITION_STEP_0)
		{
			if(position < SENSOR_POSITION_STEP_0)
				status = Rte_Call_rpHeightMotor_Move(step++);
			else
				status = Rte_Call_rpHeightMotor_Move(step--);
			status = Rte_Call_rpHeightSensor_GetPosition(&position);
		}
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
	Std_ReturnType status;
	StepMotorStepType step;
	SensorPositionType position;
	SensorWeightType Weighr;

	status = Rte_Call_rpInclineSensor_GetPosition(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&Weighr);
	if(Weighr > 100)
	{
		while(position != SENSOR_POSITION_STEP_3)
		{
			if(position < SENSOR_POSITION_STEP_3)
				status = Rte_Call_rpInclineMotor_Move(step++);
			else
				status = Rte_Call_rpInclineMotor_Move(step--);
			status = Rte_Call_rpInclineSensor_GetPosition(&position); 
		}
	}
	
	if(weighr < 80 && weighr > 100)
	{
		while(position != SENSOR_POSITION_STEP_2)
		{
			if(position < SENSOR_POSITION_STEP_2)
				status = Rte_Call_rpInclineMotor_Move(step++);
			else
				status = Rte_Call_rpInclineMotor_Move(step--);
			status = Rte_Call_rpInclineSensor_GetPosition(&position);
		}
	}
	
	if(weighr < 60 && weighr > 80)
	{
		while(position != SENSOR_POSITION_STEP_1)
		{
			if(position < SENSOR_POSITION_STEP_1)
				status = Rte_Call_rpInclineMotor_Move(step++);
			else
				status = Rte_Call_rpInclineMotor_Move(step--);
			status = Rte_Call_rpInclineSensor_GetPosition(&position);
		}
	}
	
	if(weighr < 60)
	{
		while(position != SENSOR_POSITION_STEP_0)
		{
			if(position < SENSOR_POSITION_STEP_0)
				status = Rte_Call_rpInclineMotor_Move(step++);
			else
				status = Rte_Call_rpInclineMotor_Move(step--);
			status = Rte_Call_rpInclineSensor_GetPosition(&position);
		}
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
	Std_ReturnType status;
	StepMotorStepType step;
	SensorPositionType position;
	SensorWeightType Weighr;
	
	status = Rte_Call_rpWeightSensor_GetWeight(&Weighr);
	status = Rte_Call_rpSlideSensor_GetPosition(&position);
	if(Weighr > 100)
	{
		while(position != SENSOR_POSITION_STEP_3)
		{
			if(position < SENSOR_POSITION_STEP_3)
				status = Rte_Call_rpSlideMotor_Move(step++);
			else
				status = Rte_Call_rpSlideMotor_Move(step--);
			status = Rte_Call_rpSlideSensor_GetPosition(&position); 
		}
	}
	
	if(weighr < 80 && weighr > 100)
	{
		while(position != SENSOR_POSITION_STEP_2)
		{
			if(position < SENSOR_POSITION_STEP_2)
				status = Rte_Call_rpSlideMotor_Move(step++);
			else
				status = Rte_Call_rpSlideMotor_Move(step--);
			status = Rte_Call_rpSlideSensor_GetPosition(&position);
		}
	}
	
	if(weighr < 60 && weighr > 80)
	{
		while(position != SENSOR_POSITION_STEP_1)
		{
			if(position < SENSOR_POSITION_STEP_1)
				status = Rte_Call_rpSlideMotor_Move(step++);
			else
				status = Rte_Call_rpSlideMotor_Move(step--);
			status = Rte_Call_rpSlideSensor_GetPosition(&position);
		}
	}
	
	if(weighr < 60)
	{
		while(position != SENSOR_POSITION_STEP_0)
		{
			if(position < SENSOR_POSITION_STEP_0)
				status = Rte_Call_rpSlideMotor_Move(step++);
			else
				status = Rte_Call_rpSlideMotor_Move(step--);
			status = Rte_Call_rpSlideSensor_GetPosition(&position);
		}
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

