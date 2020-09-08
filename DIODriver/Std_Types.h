/**
 * @file Std_Types.h 
 * @brief Standard types
 *
 * @author Ahmed AbdulAzeem 
 * @date 4/9/2020
 *
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include <stdint.h>



#define HIGH        (1u)
#define LOW         (0u)

typedef uint8_t Std_ReturnType;

#define STD_HIGH	0x01u		/* Standard HIGH */
#define STD_LOW		0x00u		/* Stanard  low */

#define STD_ACTIVE	0x01u		/* Logical State Active*/
#define STD_IDLE	0x00u		/* Logical State Idle*/

#define STD_ON		TRUE
#define STD_OFF		FALSE


#define E_OK		((Std_ReturnType)0x00u)		/* Function Return Ok */
#define E_NOT_OK	((Std_ReturnType)0x01u)		/* Function Return NOT Ok */


typedef enum {
TRUE,
FALSE
}boolean;



#endif /* STD_TYPE_H_ */