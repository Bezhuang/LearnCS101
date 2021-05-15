#include "time.h"
#include "key.h"


void Timer0Init(void)
{
	TMOD|=0X01;//选择为定时器0模式，工作方式1，仅用TR0打开启动。

	TH0=0X8a;	//给定时器赋初值，定时30ms
	TL0=0Xd0;	
	ET0=1;//打开定时器0中断允许
	EA=1;//打开总中断
	TR0=1;//打开定时器			
}


void Timer0() interrupt 1
{
	static u8 i;
	TH0=0X8a;	//给定时器赋初值，定时30ms
	TL0=0Xd0;
	i++;
	if(i==1)
	{
		i=0;
		KEY_Scan();	
	}	
}


