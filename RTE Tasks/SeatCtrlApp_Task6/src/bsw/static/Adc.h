/**
 *
 * \brief Sprints AUTOSAR Master Class - SeatCtrlApp
 * \author Hassan Farahat
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */
 
#ifndef ADC_H
#define ADC_H

#include "Std_Types.h"
#include "Adc_Cfg.h"

typedef uint8 				Adc_GroupType;
typedef uint8				Adc_ValueGroupType;

extern Std_ReturnType Adc_ReadGroup(Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr);

#endif