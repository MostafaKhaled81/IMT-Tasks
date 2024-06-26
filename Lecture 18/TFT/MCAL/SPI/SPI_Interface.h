/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../GPIO/GPIO_Interface.h"
#include "../NVIC/NVIC_Interface.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum{
	SPI_1=1,
	SPI_2,
	SPI_3,
	SPI_4
}SPI_NO;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void SPI1_voidInit(void);
void SPI2_voidInit(void);
void SPI3_voidInit(void);
void SPI4_voidInit(void);

void SPI1_voidSetCallBack(void (*pFunc)(void));
void SPI2_voidSetCallBack(void (*pFunc)(void));
void SPI3_voidSetCallBack(void (*pFunc)(void));
void SPI4_voidSetCallBack(void (*pFunc)(void));

u16 SPI1_voidTranciever(u16 Trans_Data);
u16 SPI2_voidTranciever(u16 Trans_Data);
u16 SPI3_voidTranciever(u16 Trans_Data);
u16 SPI4_voidTranciever(u16 Trans_Data);
 
#endif  /* SPI_INTERFACE_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
