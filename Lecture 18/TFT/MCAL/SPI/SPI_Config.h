/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define  SPI1_Status  SPI_Enable
#define  SPI2_Status  SPI_Disable
#define  SPI3_Status  SPI_Disable
#define  SPI4_Status  SPI_Disable

#define  SPI1_ClkPhase  SPI_LEADING
#define  SPI2_ClkPhase  SPI_LEADING
#define  SPI3_ClkPhase  SPI_LEADING
#define  SPI4_ClkPhase  SPI_LEADING

#define  SPI1_ClkPolarity  IDLE_IN1
#define  SPI2_ClkPolarity  IDLE_IN0
#define  SPI3_ClkPolarity  IDLE_IN0
#define  SPI4_ClkPolarity  IDLE_IN0

#define  SPI1_MasterSelection  SPI_Master
#define  SPI2_MasterSelection  SPI_Master
#define  SPI3_MasterSelection  SPI_Master
#define  SPI4_MasterSelection  SPI_Master

#define  SPI1_BaudRate  SPI_FREQ2
#define  SPI2_BaudRate  SPI_FREQ2
#define  SPI3_BaudRate  SPI_FREQ2
#define  SPI4_BaudRate  SPI_FREQ2

#define  SPI1_MostLeastBitSelection  SPI_MostBit
#define  SPI2_MostLeastBitSelection  SPI_MostBit
#define  SPI3_MostLeastBitSelection  SPI_MostBit
#define  SPI4_MostLeastBitSelection  SPI_MostBit

#define  SPI1_SoftwareSlaveManagement  SPI_Disable
#define  SPI2_SoftwareSlaveManagement  SPI_Disable
#define  SPI3_SoftwareSlaveManagement  SPI_Disable
#define  SPI4_SoftwareSlaveManagement  SPI_Disable

#define  SPI1_NoOfFrameBits  SPI_8bit
#define  SPI2_NoOfFrameBits  SPI_8bit
#define  SPI3_NoOfFrameBits  SPI_8bit
#define  SPI4_NoOfFrameBits  SPI_8bit

#define  SPI1_INTStatus  SPI_INT_DISABLE
#define  SPI2_INTStatus  SPI_INT_ENABLE
#define  SPI3_INTStatus  SPI_INT_ENABLE
#define  SPI4_INTStatus  SPI_INT_ENABLE

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

 
#endif  /* SPI_CONFIG_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
