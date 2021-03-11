#include "smg.h"



void DigDisplay(void)
{
	u8 i;
	for(i=0;i<8;i++)
	{
		switch(i)	 //位选，选择点亮的数码管，
		{
			case(0):
				LSA=0;LSB=0;LSC=0; break;//显示第0位
			case(1):
				LSA=1;LSB=0;LSC=0; break;//显示第1位
			case(2):
				LSA=0;LSB=1;LSC=0; break;//显示第2位
			case(3):
				LSA=1;LSB=1;LSC=0; break;//显示第3位
			case(4):
				LSA=0;LSB=0;LSC=1; break;//显示第4位
			case(5):
				LSA=1;LSB=0;LSC=1; break;//显示第5位
			case(6):
				LSA=0;LSB=1;LSC=1; break;//显示第6位
			case(7):
				LSA=1;LSB=1;LSC=1; break;//显示第7位	
		}
		SMG_PORT=DisPlayData[7-i];//发送段码
		delay(100); //间隔一段时间扫描	
		SMG_PORT=0x00;//消隐
	}
}

void SMG_Test(void)
{
	u8 i=0;
	for(i=0;i<8;i++)
	{
		DisPlayData[i]=smgduan[i];	
	}
	while(1)
	{
	
		DigDisplay();
		
		if(KeyValue!=SMG_TEST)
		{
			SMG_PORT=0x00;
			return;	
		}	
	}
}

