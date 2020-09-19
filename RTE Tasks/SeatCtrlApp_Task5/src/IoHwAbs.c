/**
 *
 * \file IoHwAbs_Template.c
 * \brief Rte Component Template for AUTOSAR SWC: IoHwAbs
 *
 * \author Sprints AUTOSAR Authoring Tool (SAAT) v1.0.2
 * Generated on 9/13/2020 11:53 AM
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */

#include "Rte_IoHwAbs.h"

#include "Adc.h"
#include "Spi.h"
#include "Dio.h"

//reading for height, incline and slide
static Adc_ValueGroupType IoHwAbs_PositionSensorReading[ADC_GR0_NUM_CHANNELS] = {0, /* Height */
																				 0, /* Incline */
																				 0  /* Slide */
																				 }


/**
 *
 * Runnable IoHwAbs_ECUGet_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetHeight_IOGet
 *
 */

void IoHwAbs_ECUGet_Height (IoPositionSensorReadingType* position)
{
	Std_ReturnType status;
	
	status = Adc_ReadGroup(AdcConfig_AdcGroup_PositionsSensorsGrp, IoHwAbs_PositionSensorReading);
	
	if(statue == E_OK)
	{
		*position = (IoPositionSensorReadingType)IoHwAbs_PositionSensorReading[0];
	}
	else
		//do nothing
}


/**
 *
 * Runnable IoHwAbs_ECUGet_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetIncline_IOGet
 *
 */

void IoHwAbs_ECUGet_Incline (IoPositionSensorReadingType* position)
{
	Std_ReturnType status;
	
	status = Adc_ReadGroup(AdcConfig_AdcGroup_PositionsSensorsGrp, IoHwAbs_PositionSensorReading);
	
	if(statue == E_OK)
	{
		*position = (IoPositionSensorReadingType)IoHwAbs_PositionSensorReading[1];
	}
	else
		//do nothing
}


/**
 *
 * Runnable IoHwAbs_ECUGet_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetSlide_IOGet
 *
 */

void IoHwAbs_ECUGet_Slide (IoPositionSensorReadingType* position)
{
	Std_ReturnType status;
	
	status = Adc_ReadGroup(AdcConfig_AdcGroup_PositionsSensorsGrp, IoHwAbs_PositionSensorReading);
	
	if(statue == E_OK)
	{
		*position = (IoPositionSensorReadingType)IoHwAbs_PositionSensorReading[2];
	}
	else
		//do nothing
}


/**
 *
 * Runnable IoHwAbs_ECUGet_Weight
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOGetWeight_IOGet
 *
 */

void IoHwAbs_ECUGet_Weight (IoWeightSensorReadingType* weight)
{
	Std_ReturnType status;
	Spi_DataType spiData;
	
	status = Spi_ReadIB(SpiConf_SpiChannel_WeightSensor, &SpiData);
	
	if(status == E_OK)
		*weight = (IoWeightSensorReadingType)spiData;
	else
		//do nothing
	
}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_IOSetForward
 *
 */

void IoHwAbs_ECUSetForward_Height (void)
{
	Std_ReturnType status;
	Dio_WriteChannel(DioConfg_DioChannel_HeightMotorCh, STD_HIGH);
}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetIncline_IOSetForward
 *
 */

void IoHwAbs_ECUSetForward_Incline (void)
{
	Std_ReturnType status;
	Dio_WriteChannel(DioConfg_DioChannel_InclineMotorCh, STD_HIGH);
}


/**
 *
 * Runnable IoHwAbs_ECUSetForward_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_IOSetForward
 *
 */

void IoHwAbs_ECUSetForward_Slide (void)
{
	Std_ReturnType status;
	Dio_WriteChannel(DioConfg_DioChannel_SlideMotorCh, STD_HIGH);
}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Height
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetHeight_IOSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Height (void)
{
	Std_ReturnType status;
	Dio_WriteChannel(DioConfg_DioChannel_HeightMotorCh, STD_LOW);
}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Incline
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetIncline_IOSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Incline (void)
{
	Std_ReturnType status;
	Dio_WriteChannel(DioConfg_DioChannel_InclineMotorCh, STD_LOW);
}


/**
 *
 * Runnable IoHwAbs_ECUSetReverse_Slide
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_ppIOSetSlide_IOSetReverse
 *
 */

void IoHwAbs_ECUSetReverse_Slide (void)
{
	Std_ReturnType status;
	Dio_WriteChannel(DioConfg_DioChannel_SlideMotorCh, STD_LOW);
}

