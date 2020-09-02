/**
 *
 * \file ChrgIf_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: ChrgIf
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/1/2020 06:56 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_ChrgIf.h"


/**
 *
 * Runnable CrgIf_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_CrgIf_MainFunction_100ms
 *
 */

void CrgIf_MainFunction (void)
{
	Std_ReturnType status;
	BatteryLevel BatteryLevel;

	/* Data Send Points */
	status = Rte_Write_ppBatteryInfo_BatteryLevel(BatteryLevel);
	
}

