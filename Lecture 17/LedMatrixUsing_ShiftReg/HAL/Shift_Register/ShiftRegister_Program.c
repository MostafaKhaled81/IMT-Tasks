/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../../../include/HAL/Shift_Register/ShiftRegister_Private.h"
#include "../../../include/HAL/Shift_Register/ShiftRegister_Interface.h"
#include "../../../include/HAL/Shift_Register/ShiftRegister_Config.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void ShiftReg_voidInit(void)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void ShiftReg_voidInit(void)
{
	GPIO_voidSetPinMode(SR_DATA_PORT , SR_DATA_PIN , GPIO_OUTPUT_PIN_MODE);
    GPIO_voidSetPinMode(SR_SHCLK_PORT , SR_SHCLK_PIN , GPIO_OUTPUT_PIN_MODE);
    GPIO_voidSetPinMode(SR_STCLK_PORT , SR_STCLK_PIN , GPIO_OUTPUT_PIN_MODE);

    GPIO_voidSetPinOutputSpeed(SR_DATA_PORT , SR_DATA_PIN , GPIO_OUTPUT_PIN_VERY_HIGH_SPEED);
    GPIO_voidSetPinOutputSpeed(SR_SHCLK_PORT , SR_SHCLK_PIN , GPIO_OUTPUT_PIN_VERY_HIGH_SPEED);
    GPIO_voidSetPinOutputSpeed(SR_STCLK_PORT , SR_STCLK_PIN , GPIO_OUTPUT_PIN_VERY_HIGH_SPEED);
}

/******************************************************************************
* \Syntax          : void ShiftReg_voidSendData(u16 DATA , u8 Data_Size)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void ShiftReg_voidSendData(u16 DATA , u8 Data_Size)
{
	s8 cnt = Data_Size-1;
	for(;cnt>=0;cnt--)
	{
		/*SENDING DATA*/
		GPIO_voidSetPinValue(SR_DATA_PORT , SR_DATA_PIN , GET_BIT(DATA,cnt));
		
		/*SHIFTING CLK*/
		GPIO_voidSetPinValue(SR_SHCLK_PORT , SR_SHCLK_PIN , 1);
		GPIO_voidSetPinValue(SR_SHCLK_PORT , SR_SHCLK_PIN , 0);
	}
	
	/*STORING CLK*/
	GPIO_voidSetPinValue(SR_STCLK_PORT , SR_STCLK_PIN , 1);
	GPIO_voidSetPinValue(SR_STCLK_PORT , SR_STCLK_PIN , 0);
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
