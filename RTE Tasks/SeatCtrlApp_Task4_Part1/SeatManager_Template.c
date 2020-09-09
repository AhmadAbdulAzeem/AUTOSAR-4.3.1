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
	StepMotorStepType step;
	SensorPositionType position;
	SensorWeightType Weighr;

	/* Server Call Points */
	status = Rte_Call_rpHeightMotor_Move(step);
	status = Rte_Call_rpHeightSensor_GetPosition(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&Weighr);
	
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

	/* Server Call Points */
	status = Rte_Call_rpInclineMotor_Move(step);
	status = Rte_Call_rpInclineSensor_GetPosition(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&Weighr);
	
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

	/* Server Call Points */
	status = Rte_Call_rpSlideMotor_Move(step);
	status = Rte_Call_rpSlideSensor_GetPosition(&position);
	status = Rte_Call_rpWeightSensor_GetWeight(&Weighr);
	
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
	
	/* Server Call Points */
	status = Rte_Call_rpHeightMotor_Move(step);
	
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
	
	/* Server Call Points */
	status = Rte_Call_rpInclineMotor_Move(step);
	
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
	
	/* Server Call Points */
	status = Rte_Call_rpSlideMotor_Move(step);
	
}

