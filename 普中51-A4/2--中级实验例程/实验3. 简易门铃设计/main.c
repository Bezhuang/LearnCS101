/*
实验说明：
	
实验接线：
	蜂鸣器模块-->单片机管脚
	参考蜂鸣器实验接线（开发攻略内在对应的实验章节内实验现象有接线说明）
	BEEP-->P15
	独立按键模块-->单片机管脚
	K1-->P31
实验现象：
	按下K1键，蜂鸣器发出”叮咚”门铃声
*/


#include "reg52.h"			 //此文件中定义了单片机的一些特殊功能寄存器

typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;

sbit beep=P2^5;
sbit k1=P3^1;
u8 ding,dong,flag,stop;
u16 n;
void delay(u16 i)
{
	while(i--);
}
void time0init()	  //定时器0初始化
{
	TMOD=0X01;	 //定时器0 方式1
	TH0=0Xff;
	TL0=0X06; //定时250us
//	TR0=1;
	EA=1;
	ET0=1;
}
void biaohaoinit()	   //各个标号初始化
{
	ding=0;		//叮声音  计数标志
	dong=0;		//咚声音  计数标志
	n=0;		//定时0.5s标志
	flag=0;
	stop=0;	   //结束标志
}
void main()
{
	time0init();
	biaohaoinit();
	while(1)
	{
		if(k1==0)	   //判断按键是否按下
		{
			delay(1000);  //消抖
			if(k1==0)
			{
				TR0=1;	//打开定时器0
				while(!stop);
			}
		}	
	}	
}
void time0() interrupt 1
{
	n++;
	TH0=0Xff;
	TL0=0X06; //250us
	if(n==2000)		//定时0.5s  叮响0.5秒，咚响0.5秒
	{
		n=0;
		if(flag==0)
		{
			flag=~flag;
		}
		else
		{
			flag=0;
			stop=1;
			TR0=0;	  //关闭定时器0
		}
	}
	if(flag==0)
	{					   //通过改变定时计数时间可以改变门铃的声音
		ding++;			  //叮
		if(ding==1)
		{
			ding=0;
			beep=~beep;
		}
	}
	else
	{
		dong++;
		if(dong==2)		  //咚
		{
			dong=0;
			beep=~beep;
		}	
	}
}
