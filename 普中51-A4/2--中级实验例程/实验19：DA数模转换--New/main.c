/*
实验接线：
	AD/DAC模块-->单片机管脚
	J50-->P21
实验现象：
	AD/DAC模块上的DA1指示灯呈呼吸灯效果
*/


#include "reg52.h"			 //此文件中定义了单片机的一些特殊功能寄存器


//对数据类型进行声明定义
typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long u32;

//--定义使用的IO口--//
sbit PWMOUTLED=P2^1;

//#define SYSCLOCK	11059200		//晶振频率是11.0592MHZ
#define SYSCLOCK	12000000		//晶振频率是12MHZ

u8 heighHR0, heighLR0;//PWM一个周期中高电平高字节和低字节重载值
u8 lowHR0, lowLR0;//PWM一个机器周期中低电平时高字节和低字节重载值



/*使用T0配置PWM高低电平的频率*/
void PWM_Config(u16 fr, u8 dc)  //fr为PWM的频率，100HZ无闪烁，dc是PWM的占空比(高电平占的百分比)
{
	u32 tmp;
	u16 heigh, low;
	
	tmp = SYSCLOCK/12;//一个机器周期频率
	tmp = tmp / fr;  //一个机器周期中fr的频率所需计数值(包括高电平和低电平)
	heigh = (tmp * dc) / 100;//高电平占dc%，所需计数值
	low   = tmp - heigh;//低电平所需计数值
	heigh = 65536-heigh;//高电平计数初值
	low   = 65536-low;//低电平计数初值
	
	heighHR0 = (u8)(heigh >> 8);//高电平装入初值的高字节
	heighLR0 = (u8)heigh;    //高电平装入初值的低字节
	lowHR0   = (u8)(low >> 8);  //低电平装入初值的高字节
	lowLR0   = (u8)low;    //低电平装入初值的低字节
	
	TMOD &= 0xF0;//清零T0控制位
	TMOD |= 0x01;//设定T0工作方式1,16位可设定时器
	TH0 = heighHR0;
	TL0 = heighLR0;//装入高电平计数初值
	PWMOUTLED = 1;//开始时PWM输出高电平
	TR0 = 1;
	ET0 = 1;
	EA  = 1;
}

/*关闭PWM*/
void PWM_Close()
{
	TR0 = 0;//关闭Timer0
	ET0 = 0;//关闭T0中断
	PWMOUTLED = 1;//PWM输出高电平
}

void main()
{
	u16 i=0;
	int cont=0;
	u8 fx=0;

	while (1)     //呼吸灯效果
	{
		if(fx==0)
		{
			cont+=10;
			if(cont>=90)
				fx=1;	
		}
		else
		{
			cont-=10;
			if(cont<=0)
				fx=0;	
		}
		
		
		//LED亮->暗
		PWM_Config(100, cont);//配置PWM频率为100HZ,占空比为10%
		for (i = 0; i < 30000; i++); //软件测试延时大约76ms

		PWM_Close();
	} 
}


/*定时器T0中断服务*/
void Timer0_ISP() interrupt 1
{
	//判断PWM现在输出的是高电平还是低电平
	if (PWMOUTLED)
	{
		TH0 = lowHR0;
		TL0 = lowLR0;//装载低电平计数初值
		PWMOUTLED = 0;//PWM输出低电平
	}
	else
	{
		TH0 = heighHR0;
		TL0 = heighLR0;//重装装载高电平计数初值
		PWMOUTLED = 1;//PWM输出高电平
	}
}


