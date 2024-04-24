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
#include"../../../include/MCAL/SYSTICK/STK_Private.h"
#include"../../../include/MCAL/SYSTICK/STK_Interface.h"
#include"../../../include/MCAL/SYSTICK/STK_Config.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
u8 SinglePriodic_Flag = Single_Interval;

static void (*STK_CallBackFunc)(void) = 0;
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
* \Syntax          : void STK_VoidInit(void)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void STK_VoidInit(void)
{
	/*ENANLE/DISABL SYSTICK*/
	STK->STK_CTRL&= ~(STK_SingleMusck<<0);
	STK->STK_CTRL|= (STK_STATUS<<0);
	
	/*ENANLE/DISABL SYSTICK INTERRUPT*/
	STK->STK_CTRL&= ~(STK_SingleMusck<<1);
	STK->STK_CTRL|= (STK_INT_STATUS<<1);
	
	/*SET SYSTICK CLK SOURCE*/
	STK->STK_CTRL&= ~(STK_SingleMusck<<2);
	STK->STK_CTRL|= (STK_CLK_SOURCE<<2);
}

/******************************************************************************
* \Syntax          : void STK_VoidSetBusyWait(u32 NO_TICKS)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void STK_VoidSetBusyWait(u32 NO_TICKS)
{
	STK->STK_LOAD=NO_TICKS;
	
	/*BLOCKING*/
	while(GET_BIT(STK->STK_CTRL,16)==0);
	
}

/******************************************************************************
* \Syntax          : u32 STK_u32GetRemainingTime(void)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
u32 STK_u32GetRemainingTime(void)
{
	u32 RemainingTime = STK->VAL;
	return RemainingTime;
}

/******************************************************************************
* \Syntax          : u32 STK_u32GetElapsedTime(void)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
u32 STK_u32GetElapsedTime(void)
{
	u32 ElapsedTime = STK->LOAD - STK->VAL;
	return ElapsedTime;
}

/******************************************************************************
* \Syntax          : void STK_voidSetPreloadValue(u32 NO_TICKS)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void STK_voidSetPreloadValue(u32 NO_TICKS)
{
	STK->STK_LOAD=NO_TICKS;
}

/******************************************************************************
* \Syntax          : void STK_voidResetTimer(void)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void STK_voidResetTimer(void)
{
	STK->STK_VAL=0;
}

/******************************************************************************
* \Syntax          : void STK_voidSetSingleInterval(void (*MyFunc)(void))
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void STK_voidSetSingleInterval(void (*MyFunc)(void))
{
	SinglePriodic_Flag = Single_Interval;
	STK_CallBackFunc = MyFunc;
}

/******************************************************************************
* \Syntax          : void STK_voidSetPriodicInterval(void (*MyFunc)(void))
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void STK_voidSetPriodicInterval(void (*MyFunc)(void))
{
	SinglePriodic_Flag = Priodic_Interval;
	STK_CallBackFunc = MyFunc;
}

void SysTick_Handler(void)
{
	if(SinglePriodic_Flag == Single_Interval)
	{
		STK->STK_LOAD=0;
		STK->STK_VAL=0;
		CLR_BIT(STK->CTRL,0);
	}
	if(STK_CallBackFunc != 0)
	{
		STK_CallBackFunc();
	}
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
