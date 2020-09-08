/**
 * @file Dio.h 
 * @brief Types and functions prototype 
 *
 * @author Ahmed AbdulAzeem 
 * @date 4/9/2020
 *
 */

#ifndef DIO_H
#define DIO_H

#include "Std_Types.h"
#include "Dio_Cfg.h"

#include "Port.h"

/*******************************************Typedef**************************************/
/* Numeric ID of a DIO channel. */
typedef uint8_t Dio_ChannelType;

/* Numeric ID of a DIO port. */
typedef int Dio_PortType;

/* These are the possible levels a DIO channel can have (input or output) */
typedef uint8_t Dio_LevelType;

/* the type for the value of a DIO port. */
typedef uint8_t Dio_PortLevelType;

typedef enum{
	PORTA = 0X40004000,
	PORTB = 0x40005000,
	PORTC = 0x40006000,
	PORTD = 0x40007000,
	PORTE = 0x40024000,
	PORTF = 0x40025000
}Port_Id;


/*********************************************Structs***************************************/
/* Type for the definition of a channel group, which consists of several adjoining channels within a port. */
typedef struct{
	/* This element mask which defines the positions of the channel group. */
	uint8_t maskl;
	
	/* This element shall be the position of the Channel Group on the port, counted from the LSB. */
	uint8_t offset;
	
	/* This shall be the port on which the Channel group is defined. */
	Dio_PortType port;
}Dio_ChannelGroupType;


/***************************************Functions prototypes*********************************/

/**
 * @brief Returns the port ID
 *
 * @param ChannelId ID of DIO channel
 *
 * @return Port ID
 */
Port_Id getPortId(Dio_ChannelType ChannelId);



/**
 * @brief Returns the value of the specified DIO channel.
 *
 * @param ChannelId ID of DIO channel
 *
 * @return value of the specified DIO channel.
 */
Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId );



/**
 * @brief Service to set a level of a channel.
 *
 * @param ChannelId ID of DIO channel
 * @param Level Value to be written
 *
 * @return void
 */
void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level );



/**
 * @brief Returns the level of all channels of that port.
 *
 * @param PortId ID of DIO Port
 *
 * @return the level of all channels of that port.
 */
Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId );


/**
 * @brief Service to set a value of the port.
 *
 * @param PortId ID of DIO Port
 * @param Level Value to be written
 *
 * @return void
 */
void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level );



/**
 * @brief Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return the level of the channel after flip.
 *
 * @param ChannelId ID of DIO channel
 *
 * @return The physical level of the corresponding Pin is STD_HIGH or STD_LOW
 */
 #if(DioFlipChannelApi == STD_ON)
	Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId);
#endif



/**
 * @brief Service to get the version information of this module.
 *
 * @param VersionInfo Pointer to where to store the version information of this module.
 *
 * @return void
 */
#if(DioVersionInfoApi == STD_ON)
	void Dio_GetVersionInfo( Std_VersionInfoType* VersionInfo );
#endif



/**
 * @brief This Service reads a subset of the adjoining bits of a port.
 *
 * @param ChannelGroupIdPtr Pointer to ChannelGroup
 *
 * @return Dio_PortLevelType Level of a subset of the adjoining bits of a port
 */
Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr );



/**
 * @brief Service to set a subset of the adjoining bits of a port to a specified level.
 *
 * @param ChannelGroupIdPtr Pointer to ChannelGroup
 * @param Level Value to be written
 *
 * @return void
 */
void Dio_WriteChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level );

#endif