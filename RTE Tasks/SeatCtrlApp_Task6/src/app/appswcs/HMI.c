/**
 *
 * \file HMI_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: HMI
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/13/2020 05:27 PM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_HMI.h"


static MultiStateBtnType btnValueToSate(uint8 value)
{
	 MultiStateBtnType btnSatae;
	 if(value == 1)
		 btnSatae = MULTI_STATE_BTN_MINUS;
	 else if(value == 2)
		 btnSatae = MULTI_STATE_BTN_PLUS;
	 else
		 btnSatae = MULTI_STATE_BTN_INIT;
	 
	 return btnSatae;
}

/**
 *
 * Runnable HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_HMI_MainFunction_100ms
 *
 */

void HMI_MainFunction (void)
{
	Std_ReturnType status;
	MultiStateBtnType HeightBtnState;
	MultiStateBtnType InclineBtnState;
	MultiStateBtnType SlideBtnState;
	uint8 Height;
	uint8 Inclne;
	uint8 Slide;
	boolean IsUpdated;
	
	/* read status to make sure that timeout doesn't happen */ 
	status = Rte_Read_rpSeatCtrlData_Height(&Height);
	/* communication specs not supported in SAAT tool */
	IsUpdated = Rte_IsUpdated_rpSeatCtrlData_Height();
	if(status == RTE_E_OK && IsUpdated == TRUE)
	{
		HeightBtnState = btnValueToSate(Height);
		(void)Rte_Write_ppSeatCtrlBtns_HeightBtnState(HeightBtnState);
	}
	
	/* read status to make sure that timeout doesn't happen */ 
	status = Rte_Read_rpSeatCtrlData_Inclne(&Inclne);
	/* communication specs not supported in SAAT tool */
	IsUpdated = Rte_IsUpdated_rpSeatCtrlData_Inclne();
	if(status == RTE_E_OK && IsUpdated == TRUE)
	{
		InclineBtnState = btnValueToSate(Inclne);
		(void)Rte_Write_ppSeatCtrlBtns_InclineBtnState(InclineBtnState);
	}
	
	/* read status to make sure that timeout doesn't happen */ 
	status = Rte_Read_rpSeatCtrlData_Slide(&Slide);
	/* communication specs not supported in SAAT tool */
	IsUpdated = Rte_IsUpdated_rpSeatCtrlData_Slide();
	if(status == RTE_E_OK && IsUpdated == TRUE)
	{
		SlideBtnState = btnValueToSate(Slide);
		(void)Rte_Write_ppSeatCtrlBtns_SlideBtnState(SlideBtnState);
	}
	
}


/**
 *
 * Runnable HMI_SeatModeChanged
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpSeatModeBtn_SeatModeBtn
 *
 */

void HMI_SeatModeChanged (void)
{
	Std_ReturnType status;
	SeatModeBtnType SeatModeBtn;
	uint8 SeatCtrlMode = RTE_MODE_SeatCtrlMode_INIT;

	/* Data Receive Points */
	status = Rte_Read_rpSeatModeBtn_SeatModeBtn(&SeatModeBtn);
	
	if(SeatModeBtn == SEAT_MODE_BTN_MANUAL)
		SeatCtrlMode = RTE_MODE_SeatCtrlMode_MANUAL;
	else if(SeatModeBtn == SEAT_MODE_BTN_AUTO)
		SeatCtrlMode = RTE_MODE_SeatCtrlMode_AUTO;
	else
		//Keep INIT
	
	/* Mode Switch Points */
	status = Rte_Switch_ppSeatCtrlMode_SeatCtrlMode(SeatCtrlMode);
	
}

