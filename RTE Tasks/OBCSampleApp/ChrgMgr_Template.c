/**
 *
 * \file ChrgMgr_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: ChrgMgr
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/1/2020 06:56 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_ChrgMgr.h"


/**
 *
 * Runnable ChrgMgr_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_ChrgMgr_MainFunction_100ms
 *
 */

void ChrgMgr_MainFunction (void)
{
	Std_ReturnType status;
	BatteryLevel BatteryLevel;

	/* Data Receive Points */
	status = Rte_Read_rpBatteryInfo_BatteryLevel(&BatteryLevel);
	
}

