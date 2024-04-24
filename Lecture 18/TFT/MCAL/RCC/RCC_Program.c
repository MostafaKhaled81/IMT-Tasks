/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  RCC_Program.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include"../../../include/MCAL/RCC/RCC_Private.h"
#include"../../../include/MCAL/RCC/RCC_Interface.h"
#include"../../../include/MCAL/RCC/RCC_Config.h"

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
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void RCC_voidInit(void)
{
    /*Enable CSS*/
    SET_BIT(RCC_CR,19);

    /*Error correction*/
    RCC_CR&= ~(0b11111<<3);
    RCC_CR|=((16+(RCC_Error/40))<<3);

	#if RCC_CLK_SOURCE == RCC_HSI

	    SET_BIT(RCC_CR,0);   //Enable HSI
	    CLR_BIT(RCC_CR,16);  //Disable HSE
        CLR_BIT(RCC_CR,24);  //Disable pll

        while(GET_BIT(RCC_CR,1)==0);  //Polling until the clock source becomes stable

        /*Select HSI as the system clock source*/
        CLR_BIT(RCC_CFGR,0);
        CLR_BIT(RCC_CFGR,1);

    #elif RCC_CLK_SOURCE == RCC_HSE

        SET_BIT(RCC_CR,16);   //Enable HSe
	    CLR_BIT(RCC_CR,0);    //Disable HSi
        CLR_BIT(RCC_CR,24);   //Disable pll

        while(GET_BIT(RCC_CR,17)==0);   //Polling until the clock source becomes stable

        /*Select HSE as the system clock source*/
        SET_BIT(RCC_CFGR,0);
        CLR_BIT(RCC_CFGR,1);

    #elif RCC_CLK_SOURCE == RCC_PLL

        #if RCC_PLL_CLK_SOURCE == RCC_HSI

            SET_BIT(RCC_CR,24);   //Enable PLL
            SET_BIT(RCC_CR,0);    //Enable HSI
            CLR_BIT(RCC_CR,16);   //Disable HSE

            CLR_BIT(RCC_PLLCFGR,22);  //HSI clock selected as PLL clock entry

        #elif RCC_PLL_CLK_SOURCE == RCC_HSE

            SET_BIT(RCC_CR,24);   //Enable PLL
            SET_BIT(RCC_CR,16);   //Enable HSE
            CLR_BIT(RCC_CR,0);    //Disable HSI

            SET_BIT(RCC_PLLCFGR,22);  //HSE clock selected as PLL clock entry

        #endif // RCC_PLL_CLK_SOURCE

        /*Set PLL prescaler*/
        /*PLLM*/
        RCC_PLLCFGR&= ~(0b111111<<0);
	    RCC_PLLCFGR|=(RCC_PLLM<<0);
	    /*PLLN*/
	    RCC_PLLCFGR&=~(0b111111111<<6);
	    RCC_PLLCFGR|=(RCC_PLLN<<6);
	    /*PLLP*/
	    RCC_PLLCFGR&= ~(0b11<<16);
	    RCC_PLLCFGR|=(RCC_PLLP<<16);

        while(GET_BIT(RCC_CR,25)==0);   //Polling until the clock source becomes stable

        /*Select PLL as the system clock source*/
        SET_BIT(RCC_CFGR,1);
        CLR_BIT(RCC_CFGR,0);

	#endif // RCC_CLK_SOURCE

	/*Set AHB prescaler bits*/
	RCC_CFGR&= ~(0b1111<<4);   //Clear AHB Prescaler bits
	RCC_CFGR|=(RCC_AHB_PRESCALER<<4);   //Set AHB prescaler bits

	/*Set APB1 prescaler bits*/
	RCC_CFGR&= ~(0b111<<10);
	RCC_CFGR|=(RCC_APB1_PRESCALER<<10);

	/*Set APB2 prescaler bits*/
	RCC_CFGR&= ~(0b111<<13);
	RCC_CFGR|=(RCC_APB2_PRESCALER<<13);
}

/******************************************************************************
* \Syntax          : void RCC_voidEnablePeripheralClk(u8 Copy_u8BusName,u8 Copy_u8PeripheralName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void RCC_voidEnablePeripheralClk(u8 Copy_u8BusName,u8 Copy_u8PeripheralName)
{
	switch (Copy_u8BusName){
    case RCC_AHB1:
        SET_BIT(RCC_AHB1ENR,Copy_u8PeripheralName);
    break;
    case RCC_AHB2:
        SET_BIT(RCC_AHB2ENR,Copy_u8PeripheralName);
    break;
    case RCC_APB1:
        SET_BIT(RCC_APB1ENR,Copy_u8PeripheralName);
    break;
    case RCC_APB2:
        SET_BIT(RCC_APB2ENR,Copy_u8PeripheralName);
    break;
    default:
        //ERROR
    break;
	}
}

/******************************************************************************
* \Syntax          : void RCC_voidDisablePeripheralClk(u8 Copy_u8BusName,u8 Copy_u8PeripheralName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
void RCC_voidDisablePeripheralClk(u8 Copy_u8BusName,u8 Copy_u8PeripheralName)
{
	switch (Copy_u8BusName){
    case RCC_AHB1:
        CLR_BIT(RCC_AHB1ENR,Copy_u8PeripheralName);
    break;
    case RCC_AHB2:
        CLR_BIT(RCC_AHB2ENR,Copy_u8PeripheralName);
    break;
    case RCC_APB1:
        CLR_BIT(RCC_APB1ENR,Copy_u8PeripheralName);
    break;
    case RCC_APB2:
        CLR_BIT(RCC_APB2ENR,Copy_u8PeripheralName);
    break;
    default:
        //ERROR
    break;
	}
}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
