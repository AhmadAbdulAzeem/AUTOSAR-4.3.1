#ifndef ADC_TYPEDEF_H_
#define ADC_TYPEDEF_H_

#include "Std_Types.h"
#include "Adc_Cfg.h"

#define Max_No_Of_Samples 8
#define Max_No_Of_Channels 8
#define Max_No_Of_Groups 8

/************************************************ ADC Typedefs *************************************************************/

typedef uint8_t Adc_ChannelType;             /* Numeric ID of an ADC channel */
typedef uint8_t Adc_GroupType;              /* Numeric ID of an ADC channel group.*/

typedef uint16_t Adc_ValueGroupType;         /* ADC conversion value */

typedef int8_t Adc_SamplingTimeType;        /* Time during which the value is sampled,
                                                 (in clock cycles) for each channel, if supported by hardware.l */
typedef uint8_t Adc_GroupPriorityType;       /* Priority level of the AdcGroup. */

typedef uint8_t Adc_GroupDefType;           /* Type for assignment of channels (AdcChannels)
                                                to a channel group (AdcGroups) */

typedef uint8_t Adc_StreamNumSampleType;     /* Number of ADC values to be acquired per channel in streaming access mode
                                                in single access mode =1 */

typedef uint32_t Adc_HwTriggerTimerType;     /* Type for the reload value of the ADC module embedded timer
                                                (only if supported by the ADC hardware).*/

/* Not used in TM4C123X */
typedef uint8_t Adc_PrescaleType;
typedef uint8_t Adc_ConversionTimeType ;
typedef uint8_t Adc_ResolutionType ;


/************************************************ ADC ENUMS ****************************************************************/

/*Returns the conversion status of the requested ADC Channel group.*/

typedef enum {
ADC_IDLE,
ADC_BUSY,
ADC_COMPLETED,
ADC_STREAM_COMPLETED
}Adc_StatusType;

/*Type for configuring the trigger source for an ADC Channel group
  Type of source event that starts a group conversion.*/
typedef enum {
ADC_TRIGG_SRC_SW,
ADC_TRIGG_SRC_HW
}Adc_TriggerSourceType;

/*Type for configuring the conversion mode of an ADC Channel group*/
typedef enum {
ADC_CONV_MODE_ONESHOT,
ADC_CONV_MODE_CONTINUOUS
}Adc_GroupConvModeType;

/* Type for configuring the streaming access mode buffer type
 * Configure streaming buffer as "linear buffer"
 * (i.e. the ADC Driver stops the conversion as soon as the stream buffer is full)
 * or as "ring buffer" (wraps around if the end of the stream buffer is reached).
 */
typedef enum {
ADC_STREAM_BUFFER_LINEAR,
ADC_STREAM_BUFFER_CIRCULAR
}Adc_StreamBufferModeType;

/* Type for configuring the access mode to group conversion results
 * AdcGroupTriggSrc / AdcGroupConvMode: streaming access mode is not available
 * for one-shot conversion mode with software trigger source
 */
typedef enum {
ADC_ACCESS_MODE_SINGLE,
ADC_ACCESS_MODE_STREAMING
}Adc_GroupAccessModeType;

/* Configures on which edge of the hardware trigger signal the driver should react,
 * i.e. start the conversion (only if supported by the ADC hardware).
 */
typedef enum {
ADC_HW_TRIG_RISING_EDGE,
ADC_HW_TRIG_FALLING_EDGE,
ADC_HW_TRIG_BOTH_EDGES
}Adc_HwTriggerSignalType;

/* Type for configuring the prioritization mechanism.
 *
 * Determines whether a priority mechanism is available for prioritization of the conversion requests
 * and if available, the type of prioritization mechanism.
 * The selection applies for groups with trigger source software and trigger source hardware.
 * Two types of prioritization mechanism can be selected.
 * The hardware prioritization mechanism (AdcPriorityHw) uses the ADC hardware features for prioritization
 * of the software conversion requests and hardware trigger signals for groups with trigger source hardware.
 * The mixed hardware and software prioritization mechanism (AdcPriorityHwSw)
 * uses the ADC hardware features for prioritization of ADC hardware trigger for groups with trigger source hardware
 * and a software implemented prioritization mechanism for groups with trigger source software.
 * the group priorities for software triggered groups are typically configured with lower priority levels
 * than the group priorities for hardware triggered groups.
 *
 *
 */
typedef enum {
ADC_PRIORITY_NONE,
ADC_PRIORITY_HW,
ADC_PRIORITY_HW_SW
}Adc_PriorityImplementationType;


/* Replacement mechanism, which is used on ADC group level,
 * if a group conversion is interrupted by a group which has a higher priority.
 */

typedef enum {
ADC_GROUP_REPL_ABORT_RESTART,
ADC_GROUP_REPL_SUSPEND_RESUME
}Adc_GroupReplacementType;

/*
 * In case of active limit checking: defines which conversion values are taken into account related to the boarders
 * defined with AdcChannelLowLimit and AdcChannelHighLimit.
 * globally enabled. AdcChannelLimitCheck: not available if channel specific limit check is not enabled.
 * AdcChannelHighLimit: has to be less or equal than AdcChannelHighLimit
 *
 */
typedef enum {
ADC_RANGE_UNDER_LOW,
ADC_RANGE_BETWEEN,
ADC_RANGE_OVER_HIGH,
ADC_RANGE_ALWAYS,
ADC_RANGE_NOT_UNDER_LOW,
ADC_RANGE_NOT_BETWEEN,
ADC_RANGE_NOT_OVER_HIGH
}Adc_ChannelRangeSelectType;

/*Type for alignment of ADC raw results in ADC result buffer (left/right alignment)*/
typedef enum {
ADC_ALIGN_LEFT,
ADC_ALIGN_RIGHT
}Adc_ResultAlignmentType;
/**************************************************** ENUMS ****************************************************************/

typedef enum{
    ADC_MODULE0,
    ADC_MODULE1
}Adc_ModuleId;

typedef enum {

    PROCESSOR = 0X0,
    COMP0 = 0X1,
    COMP1 = 0X2,
    GPIO = 0X4,
    TIMER = 0X5,

    PWM_MOD0_GEN0 = 0X6, 
    PWM_MOD0_GEN1 = 0X7,
    PWM_MOD0_GEN2 = 0X8,
    PWM_MOD0_GEN3 = 0X9, 

		ALWAYS = 0XF,
		NONE


}Adc_HwTriggerSourceType;

typedef enum{
    Adc_SS0,
    Adc_SS1,
    Adc_SS2,
    Adc_SS3,

}Adc_SequencerId;

typedef enum{
     AdcConvRate_125ksps =0x1,
     AdcConvRate_250ksps =0x3,
     AdcConvRate_500ksps =0x5,
     AdcConvRate_1Msps   =0x7,

}Adc_HWUnitConvRate;

typedef enum {
PE3,PE2,PE1,PE0,PD3,PD2,PD1,PD0,PE5 
}AdcChannel;

typedef enum{ADC_DRIVER_NOT_INIT=0, ADC_DRIVER_INITIALIZED}Adc_DriverStateType;

/*********************************************** config structs ************************************************************/



typedef struct{
    Adc_ModuleId AdcModuleId;
    Adc_SequencerId AdcSequencerId;
    Adc_GroupType AdcGroupId;
    Adc_ChannelType AdcGroupNumOfChannels;
		Adc_TriggerSourceType AdcTriggerSource;
    Adc_HwTriggerSourceType AdcHwTriggerSource;
		Adc_HwTriggerSignalType AdcHwTriggerSignal;
    Adc_GroupAccessModeType AdcGroupAccessMode;
    Adc_GroupPriorityType AdcGroupPriority;
    Adc_GroupConvModeType AdcGroupConversionMode;
    Adc_StreamBufferModeType AdcStreamingBufferMode;
    Adc_StreamNumSampleType AdcStreamingNumSamples;
    Adc_GroupReplacementType AdcGroupReplacement;
		AdcChannel *channelArray;
}Adc_ConfigType;

typedef struct{
	Adc_ModuleId AdcModuleId;
	Adc_SequencerId AdcSequencerId;
	Adc_ChannelType AdcGroupNumOfChannels;
	Adc_TriggerSourceType AdcTriggerSource;
	Adc_GroupPriorityType AdcGroupPriority;
	Adc_GroupConvModeType AdcGroupConversionMode;
	Adc_StreamBufferModeType AdcStreamingBufferMode;
	Adc_StatusType groupStatus;
}groupInfo;


void Adc_Init ( const Adc_ConfigType* ConfigPtr );
Std_ReturnType Adc_SetupResultBuffer( Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr );
void Adc_StartGroupConversion ( Adc_GroupType Group );
void Adc_StopGroupConversion ( Adc_GroupType Group );
Std_ReturnType Adc_ReadGroup ( Adc_GroupType Group, Adc_ValueGroupType* DataBufferPtr );
void Adc_EnableHardwareTrigger ( Adc_GroupType Group );
void Adc_DisableHardwareTrigger ( Adc_GroupType Group );
void Adc_EnableGroupNotification ( Adc_GroupType Group );
void Adc_DisableGroupNotification ( Adc_GroupType Group );
Adc_StatusType Adc_GetGroupStatus ( Adc_GroupType Group );
Adc_StreamNumSampleType Adc_GetStreamLastPointer ( Adc_GroupType Group, Adc_ValueGroupType** PtrToSamplePtr );
//void Adc_GetVersionInfo(Std_VersionInfoType* versioninfo);


#endif /* ADC_TYPEDEF_H_ */
