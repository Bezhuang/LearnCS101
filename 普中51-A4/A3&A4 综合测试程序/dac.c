#include "dac.h"

bit DIR;

//--定义一个全局变量--// 
u16 count,value,timer1;


void Timer1Init()
{
	TMOD|=0X10;//选择为定时器1模式，工作方式1，仅用TR1打开启动。

	TH1 = 0xFF; 
	TL1 = 0xff;   //1us
		
	ET1=1;//打开定时器1中断允许
	EA=1;//打开总中断
	TR1=1;//打开定时器			
}


void Time1(void) interrupt 3    //3 为定时器1的中断号  1 定时器0的中断号 0 外部中断1 2 外部中断2  4 串口中断
{
	TH1 = 0xFF; 
	TL1 = 0xff;   //1us
	timer1++; 
    count++;
	
}


void DAC_Test(void)
{
	Timer1Init();  //定时器1初始化

	while(1)
	{
		if(count>100)							
		{  
			count=0;
			if(DIR==1)					   //DIR控制增加或减小
			{
			  value++;
			}			
			if(DIR==0)
			{
			  value--;
			}
				
		}

		if(value==1000)
		{
		  DIR=0;
		}
		if(value==0)
		{
		  DIR=1;
		}	
				
		if(timer1>1000)  //PWM周期为1000*1us
		{
			timer1=0;
		}
		if(timer1 <value)	
		{
			PWM=1;
		}
		else
		{
			PWM=0;
		}			

		if(KeyValue!=DAC_TEST)
		{
			TR1=0;
			return;	
		}
	}
}