// ----------------------------------------------------------------------------
#include "../include/HAL/Shift_Register/ShiftRegister_Interface.h"
#include "../include/MCAL/RCC/RCC_Interface.h"

// ----------------------------------------------------------------------------

int main()
{
	u8 cnt=0;
	u16 Data[8] = {(255<<8)+(u8)(~(1<<0)), (2<<8)+(u8)(~(1<<1)), (4<<8)+(u8)(~(1<<2)), (8<<8)+(u8)(~(1<<3)), (4<<8)+(u8)(~(1<<4)), (2<<8)+(u8)(~(1<<5)), (255<<8)+(u8)(~(1<<6)), (0<<8)+(u8)(~(1<<7))};
	RCC_voidInit();
	RCC_voidEnablePeripheralClk(RCC_AHB1,RCC_GPIOA);

	ShiftReg_voidInit();

  while (1)
    {
	  for(cnt=0;cnt<8;cnt++)
	  {
		  ShiftReg_voidSendData(Data[cnt],16);
	  }
    }
}

// ----------------------------------------------------------------------------
