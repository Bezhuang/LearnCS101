/* 定时一段时间来控制蜂鸣器发出声音,模拟电脑故障时的声音  */
//BEEP-->P15
#include<reg52.h>
typedef unsigned char u8;
typedef unsigned int u16;
sbit beep=P1^5;
void tim1init()//定时器1初始化
{
	TMOD=0X10;	//t1 方式1
	TH1=0XFC;
	TL1=0X18;//定时1ms
	TR1=1;	 //打开t1定时器
}
void main()
{
	u16 j;
	tim1init();
	while(1)
	{
		if(TF1==1)
		{
			TF1=0;
			TH1=0XFC;
			TL1=0X18;//定时1ms
			j++;
			if(j==1)	 //1ms
			{	
				j=0;
				beep=~beep;
			}
		}
	}	
}
