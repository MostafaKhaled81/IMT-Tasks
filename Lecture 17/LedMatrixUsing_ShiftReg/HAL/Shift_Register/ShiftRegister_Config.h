/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef SHIFTREGISTER_CONFIG_H
#define SHIFTREGISTER_CONFIG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../MCAL/GPIO/GPIO_Interface.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define  SR_DATA_PORT  GPIO_PORTA
#define  SR_DATA_PIN   GPIO_PIN0

#define  SR_SHCLK_PORT  GPIO_PORTA
#define  SR_SHCLK_PIN   GPIO_PIN1

#define  SR_STCLK_PORT  GPIO_PORTA
#define  SR_STCLK_PIN   GPIO_PIN2

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* SHIFTREGISTER_CONFIG_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
