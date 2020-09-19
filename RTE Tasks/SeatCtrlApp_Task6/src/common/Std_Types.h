/**
 *
 * \brief Sprints AUTOSAR Master Class - SeatCtrlApp
 * \author Hassan Farahat
 *
 * For any inquiries: hassan.m.farahat@gmail.com
 *
 */
 
#ifndef STD_TYPES_H
#define STD_TYPES_H

/* Platform Types */
typedef signed char         sint8;
typedef unsigned char       uint8;
typedef signed short        sint16;
typedef unsigned short      uint16;
typedef signed long         sint32;
typedef unsigned long       uint32;
typedef float               float32;
typedef double              float64;
typedef unsigned char       boolean;

/* AUTOSAR Types */
typedef uint8 Std_ReturnType;

/* AUTOSAR Defines */
#define TRUE      			1U
#define FALSE     			0U
#define E_NOT_OK    		1U
#define E_OK      			0U
#define STD_HIGH    		1U
#define STD_LOW     		0U
#define E_OK			0U
#define E_NOK			1U

#endif
