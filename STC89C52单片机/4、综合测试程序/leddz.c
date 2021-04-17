#include "leddz.h"


void HC595SendByte(u8 dat)
{
	u8 a;
	SRCLK=0;
	RCLK=0;
	for(a=0;a<8;a++)
	{
		SER=dat>>7;
		dat<<=1;

		SRCLK=1;
		_nop_();
		_nop_();
		SRCLK=0;	
	}

	RCLK=1;
	_nop_();
	_nop_();
	RCLK=0;
}

void LEDDZ_Test(void)
{
	u8 i=0;
	while(1)
	{
		for(i=0;i<8;i++)
		{
			HC595SendByte(0x80>>i);   //74HC595控制点阵行
			LEDDZ_PORT=0x00;		//控制点阵列
			delay(15000);
			if(KeyValue!=LEDDZ_TEST)
			{
				LEDDZ_PORT=0xff;
				return;	
			}	
		}	
	}
}

