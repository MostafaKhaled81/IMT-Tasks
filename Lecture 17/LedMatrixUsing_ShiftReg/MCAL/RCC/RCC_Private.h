/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <RCC_Private.h>
 *       Module:  RCC
 *
 *  Description:  <Write File DESCRIPTION here>
 *
 *********************************************************************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/*RCC base address*/
#define  RCC_BASE_ADDRESS 0x40023800

/*RCC registers addresses*/
#define  RCC_CR          *(volatile u32*)(RCC_BASE_ADDRESS+0x00)
#define  RCC_PLLCFGR     *(volatile u32*)(RCC_BASE_ADDRESS+0x04)
#define  RCC_CFGR        *(volatile u32*)(RCC_BASE_ADDRESS+0x08)
#define  RCC_CIR         *(volatile u32*)(RCC_BASE_ADDRESS+0x0C)
#define  RCC_AHB1RSTR    *(volatile u32*)(RCC_BASE_ADDRESS+0x10)
#define  RCC_AHB2RSTR    *(volatile u32*)(RCC_BASE_ADDRESS+0x14)
#define  RCC_APB1RSTR    *(volatile u32*)(RCC_BASE_ADDRESS+0x20)
#define  RCC_APB2RSTR    *(volatile u32*)(RCC_BASE_ADDRESS+0x24)
#define  RCC_AHB1ENR     *(volatile u32*)(RCC_BASE_ADDRESS+0x30)
#define  RCC_AHB2ENR     *(volatile u32*)(RCC_BASE_ADDRESS+0x34)
#define  RCC_APB1ENR     *(volatile u32*)(RCC_BASE_ADDRESS+0x40)
#define  RCC_APB2ENR     *(volatile u32*)(RCC_BASE_ADDRESS+0x44)
#define  RCC_AHB1LPENR   *(volatile u32*)(RCC_BASE_ADDRESS+0x50)
#define  RCC_AHB2LPENR   *(volatile u32*)(RCC_BASE_ADDRESS+0x54)
#define  RCC_APB1LPENR   *(volatile u32*)(RCC_BASE_ADDRESS+0x60)
#define  RCC_APB2LPENR   *(volatile u32*)(RCC_BASE_ADDRESS+0x64)
#define  RCC_BDCR        *(volatile u32*)(RCC_BASE_ADDRESS+0x70)
#define  RCC_CSR         *(volatile u32*)(RCC_BASE_ADDRESS+0x74)
#define  RCC_SSCGR       *(volatile u32*)(RCC_BASE_ADDRESS+0x80)
#define  RCC_PLLI2SCFGR  *(volatile u32*)(RCC_BASE_ADDRESS+0x84)
#define  RCC_DCKCFG      *(volatile u32*)(RCC_BASE_ADDRESS+0x8C)

/*Clock sources*/
#define  RCC_HSI  0
#define  RCC_HSE  1
#define  RCC_PLL  2

/*PLL prescaler (PLLP)*/
#define  RCC_PLLP_2  0b00
#define  RCC_PLLP_4  0b01
#define  RCC_PLLP_6  0b10
#define  RCC_PLLP_8  0b11

/*AHB prescaler*/
#define  RCC_AHB_NotDivided     0
#define  RCC_AHB_DIV_2     0b1000
#define  RCC_AHB_DIV_4     0b1001
#define  RCC_AHB_DIV_8     0b1010
#define  RCC_AHB_DIV_16    0b1011
#define  RCC_AHB_DIV_64    0b1100
#define  RCC_AHB_DIV1_128  0b1101
#define  RCC_AHB_DIV1_256  0b1110
#define  RCC_AHB_DIV1_512  0b1111

/*APB1 prescaler*/
#define  RCC_APB1_NotDivided    0
#define  RCC_APB1_DIV_2     0b100
#define  RCC_APB1_DIV_4     0b101
#define  RCC_APB1_DIV_8     0b110
#define  RCC_APB1_DIV_16    0b111

/*APB2 prescaler*/
#define  RCC_APB2_NotDivided    0
#define  RCC_APB2_DIV_2     0b100
#define  RCC_APB2_DIV_4     0b101
#define  RCC_APB2_DIV_8     0b110
#define  RCC_APB2_DIV_16    0b111


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


#endif  /* RCC_PRIVATE_H */

/**********************************************************************************************************************
 *  END OF FILE: RCC_Pivate.h
 *********************************************************************************************************************/
