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
#include "../../../include/HAL/TFT/TFT_Private.h"
#include "../../../include/HAL/TFT/TFT_Interface.h"
#include "../../../include/HAL/TFT/TFT_Config.h"

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
* \Syntax          : void TFT_voidInit(void)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void TFT_voidInit(void)
{
	/*SET A0 AND RST PINS MODE*/
	GPIO_voidSetPinMode(TFT_A0_PORT , TFT_A0_PIN , GPIO_OUTPUT_PIN_MODE);
	GPIO_voidSetPinMode(TFT_RST_PORT , TFT_RST_PIN , GPIO_OUTPUT_PIN_MODE);
	
	/*SPI INITIALIZATION*/
	SPI1_voidInit();
	
	/*INITIALIZATION SEQUENCE*/
	/*RST SEQUENCE*/
	GPIO_voidSetPinValue(TFT_RST_PORT , TFT_RST_PIN , GPIO_HIGH);
	STK_VoidSetBusyWait(100);
    GPIO_voidSetPinValue(TFT_RST_PORT , TFT_RST_PIN , GPIO_LOW);
    STK_VoidSetBusyWait(1);
    GPIO_voidSetPinValue(TFT_RST_PORT , TFT_RST_PIN , GPIO_HIGH);
    STK_VoidSetBusyWait(100);
    GPIO_voidSetPinValue(TFT_RST_PORT , TFT_RST_PIN , GPIO_LOW);
    STK_VoidSetBusyWait(100);
    GPIO_voidSetPinValue(TFT_RST_PORT , TFT_RST_PIN , GPIO_HIGH);
    STK_VoidSetBusyWait(120000);
	/*SLEEP OUT*/
	TFT_voidSendCommand(TFT_SLP_OUT);
	STK_VoidSetBusyWait(150000);
	/*COLOR MODE*/
	TFT_voidSendCommand(TFT_ColorMode_Command);
	TFT_voidSendData(TFT_COLOR_MODE);
	/*DISPLAT ON*/
	TFT_voidSendCommand(TFT_DISPON);
}

/******************************************************************************
* \Syntax          : void TFT_voidSendCommand(u8 Command)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void TFT_voidSendCommand(u8 Command)
{
	/*SET COMMAND MODE*/
	GPIO_voidSetPinValue(TFT_A0_PORT , TFT_A0_PIN , GPIO_LOW);
	
	/*SEND THE COMMAND*/
	SPI1_voidTranciever(Command);
}

/******************************************************************************
* \Syntax          : void TFT_voidSendData(u16 Data)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void TFT_voidSendData(u8 Data)
{
	/*SET DATA MODE*/
	GPIO_voidSetPinValue(TFT_A0_PORT , TFT_A0_PIN , GPIO_HIGH);
	
	/*SEND THE DATA*/
	SPI1_voidTranciever(Data);
}

/******************************************************************************
* \Syntax          : void TFT_voidSetWindow(u8 x0 , u8 x1 , u8 y0 , u8 y1)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void TFT_voidSetWindow(u8 x0 , u8 x1 , u8 y0 , u8 y1)
{
	/*SEND X DIMENSIONS*/
	TFT_voidSendCommand(TFT_X_SetWindow);
	TFT_voidSendData(0);
	TFT_voidSendData(x0);
	TFT_voidSendData(0);
	TFT_voidSendData(x1);
	
	/*SEND Y DIMENSIONS*/
	TFT_voidSendCommand(TFT_Y_SetWindow);
	TFT_voidSendData(0);
	TFT_voidSendData(y0);
	TFT_voidSendData(0);
	TFT_voidSendData(y1);
}

/******************************************************************************
* \Syntax          : void TFT_voidDisplayImage(u16 *Image)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void TFT_voidDisplayImage(u16 *Image)
{
	u16 cnt=0;
	/*SET WINDOW*/
	TFT_voidSetWindow(0, 127, 0, 159);
	
	/*SEND IMAGE DATA*/
	TFT_voidSendCommand(RAM_WR_CMD);
	for(cnt=0;cnt<20480;cnt++)
	{
		TFT_voidSendData(Image[cnt]>>8);
		TFT_voidSendData((u8)(Image[cnt]));
	}
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
