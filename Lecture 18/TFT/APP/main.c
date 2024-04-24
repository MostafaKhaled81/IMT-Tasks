// ----------------------------------------------------------------------------
#include "../include/HAL/TFT/TFT_Interface.h"
#include "../include/MCAL/RCC/RCC_Interface.h"
#include "../include/Image.h"

// ----------------------------------------------------------------------------

int main()
{
	RCC_voidInit();
	RCC_voidEnablePeripheralClk(RCC_AHB1,RCC_GPIOA);
	RCC_voidEnablePeripheralClk(RCC_APB2,RCC_SPI1);

	STK_VoidInit();

	TFT_voidInit();

  while (1)
    {
	  TFT_voidDisplayImage(&Image);
    }
}

// ----------------------------------------------------------------------------
