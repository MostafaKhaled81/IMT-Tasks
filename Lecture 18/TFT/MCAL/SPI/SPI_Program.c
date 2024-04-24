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
#include "../../../include/MCAL/SPI/SPI_Interface.h"
#include "../../../include/MCAL/SPI/SPI_Private.h"
#include "../../../include/MCAL/SPI/SPI_Config.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
static void (*SPI1_CallBackFunction)(void)=0;
static void (*SPI2_CallBackFunction)(void)=0;
static void (*SPI3_CallBackFunction)(void)=0;
static void (*SPI4_CallBackFunction)(void)=0;

u16 SPI1_RecievedData = 0;
u16 SPI2_RecievedData = 0;
u16 SPI3_RecievedData = 0;
u16 SPI4_RecievedData = 0;

u16 SPI1_TransmissionData = 0;
u16 SPI2_TransmissionData = 0;
u16 SPI3_TransmissionData = 0;
u16 SPI4_TransmissionData = 0;

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
* \Syntax          : void SPI1_voidInit(void)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void SPI1_voidInit(void)
{
	/*GPIO INITIOLIZATION*/
	GPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN4, GPIO_ALTERNATE_FUNCTION_PIN_MODE);
	GPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN5, GPIO_ALTERNATE_FUNCTION_PIN_MODE);
	GPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN6, GPIO_ALTERNATE_FUNCTION_PIN_MODE);
	GPIO_voidSetPinMode(GPIO_PORTA, GPIO_PIN7, GPIO_ALTERNATE_FUNCTION_PIN_MODE);
	
	GPIO_voidSetAlternativeFunction(GPIO_PORTA, GPIO_PIN4, 5);
	GPIO_voidSetAlternativeFunction(GPIO_PORTA, GPIO_PIN5, 5);
	GPIO_voidSetAlternativeFunction(GPIO_PORTA, GPIO_PIN6, 5);
	GPIO_voidSetAlternativeFunction(GPIO_PORTA, GPIO_PIN7, 5);
	
	/*ENABLE/DISABLE SPI*/
	SPI1->SPI_CR1 &= ~(1<<6);
	SPI1->SPI_CR1 |= (SPI1_Status<<6);
	
	/*ENABLE/DISABLE INTERRUPT SELECTION*/
	#if (SPI1_INTStatus == SPI_INT_ENABLE)
		SET_BIT(SPI1->SPI_CR2 , 7);
	    NVIC_voidPeripheralInterruptControl(35,NVIC_INT_ENABLE);
	#endif
	   
	/*SPI CLK PHASE SELECTION*/
	SPI1->SPI_CR1 &= ~(1<<0);
	SPI1->SPI_CR1 |= (SPI1_ClkPhase<<0);
	
	/*SPI CLK POLARITY SELECTION*/
	SPI1->SPI_CR1 &= ~(1<<1);
	SPI1->SPI_CR1 |= (SPI1_ClkPolarity<<1);
	
	/*SPI Master Slave Selection*/
	SPI1->SPI_CR1 &= ~(1<<2);
	SPI1->SPI_CR1 |= (SPI1_MasterSelection<<2);
	
	/*SPI BAUD RATE SELECTION*/
	SPI1->SPI_CR1 &= ~(0b111<<3);
	SPI1->SPI_CR1 |= (SPI1_BaudRate<<3);
	
	/*SPI FIRST MOST BIT FIRST LEAST BIT SELECTION*/
	SPI1->SPI_CR1 &= ~(1<<7);
	SPI1->SPI_CR1 |= (SPI1_MostLeastBitSelection<<7);
	
	/*SPI Software Slave Management Selection*/
	SPI1->SPI_CR1 &= ~(1<<9);
	SPI1->SPI_CR1 |= (SPI1_SoftwareSlaveManagement<<9);
	
	/*SPI NUMBER OF FRAME BITS SELECTION*/
	SPI1->SPI_CR1 &= ~(1<<11);
	SPI1->SPI_CR1 |= (SPI1_NoOfFrameBits<<11);
}

/******************************************************************************
* \Syntax          : void SPI2_voidInit(void)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void SPI2_voidInit(void)
{
	/*ENABLE/DISABLE SPI*/
	SPI2->SPI_CR1 &= ~(1<<6);
	SPI2->SPI_CR1 |= (SPI2_Status<<6);
	
	/*ENABLE/DISABLE INTERRUPT SELECTION*/
	#if (SPI2_INTStatus == SPI_INT_ENABLE)
		SET_BIT(SPI2->SPI_CR2 , 7);
	    NVIC_voidPeripheralInterruptControl(36,NVIC_INT_ENABLE);
	#endif
	
	/*SPI CLK PHASE SELECTION*/
	SPI1->SPI_CR1 &= ~(1<<0);
	SPI1->SPI_CR1 |= (SPI2_ClkPhase<<0);
	
	/*SPI CLK POLARITY SELECTION*/
	SPI2->SPI_CR1 &= ~(1<<1);
	SPI2->SPI_CR1 |= (SPI2_ClkPolarity<<1);
	
	/*SPI Master Slave Selection*/
	SPI2->SPI_CR1 &= ~(1<<2);
	SPI2->SPI_CR1 |= (SPI2_MasterSelection<<2);
	
	/*SPI BAUD RATE SELECTION*/
	SPI2->SPI_CR1 &= ~(0b111<<3);
	SPI2->SPI_CR1 |= (SPI2_BaudRate<<3);
	
	/*SPI FIRST MOST BIT FIRST LEAST BIT SELECTION*/
	SPI1->SPI_CR1 &= ~(1<<7);
	SPI1->SPI_CR1 |= (SPI2_MostLeastBitSelection<<7);
	
	/*SPI Software Slave Management Selection*/
	SPI2->SPI_CR1 &= ~(1<<9);
	SPI2->SPI_CR1 |= (SPI2_SoftwareSlaveManagement<<9);
	
	/*SPI NUMBER OF FRAME BITS SELECTION*/
	SPI2->SPI_CR1 &= ~(1<<11);
	SPI2->SPI_CR1 |= (SPI2_NoOfFrameBits<<11);
}

/******************************************************************************
* \Syntax          : void SPI3_voidInit(void)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void SPI3_voidInit(void)
{
	/*ENABLE/DISABLE SPI*/
	SPI3->SPI_CR1 &= ~(1<<6);
	SPI3->SPI_CR1 |= (SPI3_Status<<6);
	
	/*ENABLE/DISABLE INTERRUPT SELECTION*/
	#if (SPI3_INTStatus == SPI_INT_ENABLE)
		SET_BIT(SPI3->SPI_CR2 , 7);
	    NVIC_voidPeripheralInterruptControl(51,NVIC_INT_ENABLE);
	#endif
	
	/*SPI CLK PHASE SELECTION*/
	SPI1->SPI_CR1 &= ~(1<<0);
	SPI1->SPI_CR1 |= (SPI3_ClkPhase<<0);
	
	/*SPI CLK POLARITY SELECTION*/
	SPI3->SPI_CR1 &= ~(1<<1);
	SPI3->SPI_CR1 |= (SPI3_ClkPolarity<<1);
	
	/*SPI Master Slave Selection*/
	SPI3->SPI_CR1 &= ~(1<<2);
	SPI3->SPI_CR1 |= (SPI1_MasterSelection<<2);
	
	/*SPI BAUD RATE SELECTION*/
	SPI3->SPI_CR1 &= ~(0b111<<3);
	SPI3->SPI_CR1 |= (SPI3_BaudRate<<3);
	
	/*SPI FIRST MOST BIT FIRST LEAST BIT SELECTION*/
	SPI3->SPI_CR1 &= ~(1<<7);
	SPI3->SPI_CR1 |= (SPI3_MostLeastBitSelection<<7);
	
	/*SPI Software Slave Management Selection*/
	SPI3->SPI_CR1 &= ~(1<<9);
	SPI3->SPI_CR1 |= (SPI3_SoftwareSlaveManagement<<9);
	
	/*SPI NUMBER OF FRAME BITS SELECTION*/
	SPI3->SPI_CR1 &= ~(1<<11);
	SPI3->SPI_CR1 |= (SPI3_NoOfFrameBits<<11);
}

/******************************************************************************
* \Syntax          : void SPI4_voidInit(void)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void SPI4_voidInit(void)
{
	/*ENABLE/DISABLE SPI*/
	SPI4->SPI_CR1 &= ~(1<<6);
	SPI4->SPI_CR1 |= (SPI4_Status<<6);
	
	/*ENABLE/DISABLE INTERRUPT SELECTION*/
	#if (SPI4_INTStatus == SPI_INT_ENABLE)
		SET_BIT(SPI4->SPI_CR2 , 7);
	    NVIC_voidPeripheralInterruptControl(84,NVIC_INT_ENABLE);
	#endif
	
	/*SPI CLK PHASE SELECTION*/
	SPI4->SPI_CR1 &= ~(1<<0);
	SPI4->SPI_CR1 |= (SPI4_ClkPhase<<0);
	
	/*SPI CLK POLARITY SELECTION*/
	SPI4->SPI_CR1 &= ~(1<<1);
	SPI4->SPI_CR1 |= (SPI4_ClkPolarity<<1);
	
	/*SPI Master Slave Selection*/
	SPI4->SPI_CR1 &= ~(1<<2);
	SPI4->SPI_CR1 |= (SPI4_MasterSelection<<2);
	
	/*SPI BAUD RATE SELECTION*/
	SPI4->SPI_CR1 &= ~(0b111<<3);
	SPI4->SPI_CR1 |= (SPI4_BaudRate<<3);
	
	/*SPI FIRST MOST BIT FIRST LEAST BIT SELECTION*/
	SPI4->SPI_CR1 &= ~(1<<7);
	SPI4->SPI_CR1 |= (SPI4_MostLeastBitSelection<<7);
	
	/*SPI Software Slave Management Selection*/
	SPI4->SPI_CR1 &= ~(1<<9);
	SPI4->SPI_CR1 |= (SPI4_SoftwareSlaveManagement<<9);
	
	/*SPI NUMBER OF FRAME BITS SELECTION*/
	SPI4->SPI_CR1 &= ~(1<<11);
	SPI4->SPI_CR1 |= (SPI4_NoOfFrameBits<<11);
}

/******************************************************************************
* \Syntax          : void SPI_voidSetCallBack(void (*pFunc)(void))
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void SPI1_voidSetCallBack(void (*pFunc)(void))
{
	SPI1_CallBackFunction = pFunc;
}

/******************************************************************************
* \Syntax          : void SPI_voidSetCallBack(void (*pFunc)(void))
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void SPI2_voidSetCallBack(void (*pFunc)(void))
{
	SPI2_CallBackFunction = pFunc;
}

/******************************************************************************
* \Syntax          : void SPI_voidSetCallBack(void (*pFunc)(void))
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void SPI3_voidSetCallBack(void (*pFunc)(void))
{
	SPI3_CallBackFunction = pFunc;
}

/******************************************************************************
* \Syntax          : void SPI_voidSetCallBack(void (*pFunc)(void))
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
void SPI4_voidSetCallBack(void (*pFunc)(void))
{
	SPI4_CallBackFunction = pFunc;
}

/******************************************************************************
* \Syntax          : u16 SPI1_voidTranciever(u16 Trans_Data)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
u16 SPI1_voidTranciever(u16 Trans_Data)
{
	u16 Recieved_Data = 0;
	#if (SPI1_INTStatus == SPI_INT_DISABLE)
		SPI1->SPI_DR = Trans_Data;
	    while(GET_BIT(SPI1->SPI_DR , 7));
		Recieved_Data = SPI1->SPI_DR;
		return Recieved_Data;
	#elif (SPI1_INTStatus == SPI_INT_ENABLE)
		SPI1_RecievedData = SPI1->SPI_DR;
	    SPI1->SPI_DR = Trans_Data;
		#endif
}

/******************************************************************************
* \Syntax          : u16 SPI2_voidTranciever(u16 Trans_Data)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
u16 SPI2_voidTranciever(u16 Trans_Data)
{
	u16 Recieved_Data = 0;
	#if (SPI2_INTStatus == SPI_INT_DISABLE)
		SPI2->SPI_DR = Trans_Data;
	    while(GIT_BIT(SPI2->SPI_DR , 7));
		Recieved_Data = SPI2->SPI_DR;
		return Recieved_Data;
	#elif (SPI2_INTStatus == SPI_INT_ENABLE)
		SPI2_RecievedData = SPI2->SPI_DR;
	    SPI2->SPI_DR = Trans_Data;
		#endif
}

/******************************************************************************
* \Syntax          : u16 SPI3_voidTranciever(u16 Trans_Data)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
u16 SPI3_voidTranciever(u16 Trans_Data)
{
	u16 Recieved_Data = 0;
	#if (SPI3_INTStatus == SPI_INT_DISABLE)
		SPI3->SPI_DR = Trans_Data;
	    while(GIT_BIT(SPI3->SPI_DR , 7));
		Recieved_Data = SPI3->SPI_DR;
		return Recieved_Data;
	#elif (SPI3_INTStatus == SPI_INT_ENABLE)
		SPI3_RecievedData = SPI3->SPI_DR;
	    SPI3->SPI_DR = Trans_Data;
		#endif
}

/******************************************************************************
* \Syntax          : u16 SPI4_voidTranciever(u16 Trans_Data)
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/
u16 SPI4_voidTranciever(u16 Trans_Data)
{
	u16 Recieved_Data = 0;
	#if (SPI4_INTStatus == SPI_INT_DISABLE)
		SPI4->SPI_DR = Trans_Data;
	    while(GIT_BIT(SPI4->SPI_DR , 7));
		Recieved_Data = SPI4->SPI_DR;
		return Recieved_Data;
	#elif (SPI4_INTStatus == SPI_INT_ENABLE)
		SPI4_RecievedData = SPI4->SPI_DR;
	    SPI4->SPI_DR = Trans_Data;
		#endif
}

void SPI1_IRQHandler(void)
{
	SPI1_voidTranciever(SPI1_TransmissionData);
	if(SPI1_CallBackFunction != 0)
	{
		SPI1_CallBackFunction();
	}
}

void SPI2_IRQHandler(void)
{
	SPI2_voidTranciever(SPI2_TransmissionData);
	if(SPI2_CallBackFunction != 0)
	{
		SPI2_CallBackFunction();
	}
}

void SPI3_IRQHandler(void)
{
	SPI3_voidTranciever(SPI3_TransmissionData);
	if(SPI3_CallBackFunction != 0)
	{
		SPI3_CallBackFunction();
	}
}

void SPI4_IRQHandler(void)
{
	SPI4_voidTranciever(SPI4_TransmissionData);
	if(SPI4_CallBackFunction != 0)
	{
		SPI4_CallBackFunction();
	}
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
