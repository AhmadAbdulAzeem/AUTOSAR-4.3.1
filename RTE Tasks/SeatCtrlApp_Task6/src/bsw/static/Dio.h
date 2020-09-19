/**
 *
 * \brief Sprints AUTOSAR Master Class - SeatCtrlApp
 * \author Hassan Farahat
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */
 
#ifndef DIO_H
#define DIO_H

#include "Std_Types.h"
#include "Dio_Cfg.h"

typedef uint8				Dio_ChannelType;
typedef uint8 				Dio_LevelType;

extern void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

#endif