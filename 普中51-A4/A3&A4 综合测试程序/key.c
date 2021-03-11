#include "key.h"


//mode=0 单次   1：连续
u8 KeyScan(u8 mode)
{
	static u8 keyen=1;
	if(mode==1)
	{
		keyen=1;
	}
	if(keyen==1&&(k1==0||k2==0||k3==0||k4==0))
	{
		delay(1000);  //消抖处理
		keyen=0;
		if(k1==0)return KEY1;
		else if(k2==0)return KEY2;
		else if(k3==0)return KEY3;
		else if(k4==0)return KEY4;				
	}
	else if(k1==1&&k2==1&&k3==1&&k4==1)
	{
		keyen=1;
	}
	return 0;	
}


void KEY_Scan(void)
{
	char a=0;
	
	KEY_PORT=0x0f;
	if(KEY_PORT!=0x0f)//读取按键是否按下
	{
		delay(1000);//延时10ms进行消抖
		if(KEY_PORT!=0x0f)//再次检测键盘是否按下
		{	
			//测试列
			KEY_PORT=0X0F;
			switch(KEY_PORT)
			{
				case(0X07):	KeyValue=1;break;
				case(0X0b):	KeyValue=2;break;
				case(0X0d): KeyValue=3;break;
				case(0X0e):	KeyValue=4;break;
			}
			//测试行
			KEY_PORT=0XF0;
			switch(KEY_PORT)
			{
				case(0X70):	KeyValue=KeyValue;break;
				case(0Xb0):	KeyValue=KeyValue+4;break;
				case(0Xd0): KeyValue=KeyValue+8;break;
				case(0Xe0):	KeyValue=KeyValue+12;break;
			}
			while((a<50)&&(KEY_PORT!=0xf0))	 //检测按键松手检测
			{
				delay(1000);
				a++;
			}
		}
	}
}
