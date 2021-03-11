/*
实验说明：
	
实验接线：
	1，静态数码管模块-->单片机管脚
	参考静态数码管显示实验接线（开发攻略内在对应的实验章节内实验现象有接线说明）
	2，矩阵按键模块-->单片机管脚 
	参考矩阵按键实验接线（开发攻略内在对应的实验章节内实验现象有接线说明）
	3，蜂鸣器模块-->单片机管脚
	BEEP-->P20
	
实验现象：
	按下不同键，蜂鸣器发出不同声音，同时静态数码管上显示键值，这里仅仅是一个简单的调声程序，大家如要
	设计与实际电子琴功能，还需优化。
*/

#include<reg52.h>
typedef unsigned char u8;
typedef unsigned int u16;
sbit beep=P2^0;
#define GPIO_KEY P1

u8 KeyValue;	//用来存放读取到的键值
u8 value;
u8 smg[16]={~0x3F, ~0x06, ~0x5B, ~0x4F, ~0x66, ~0x6D, ~0x7D, ~0x07,
             ~0x7F, ~0x6F, ~0x77, ~0x7C, ~0x39, ~0x5E, ~0x79, ~0x71}; //0~A
void delay(u16 i)
{
	while(i--);
}
void KEY_Scan(void)
{
	char a=0;
	GPIO_KEY=0x0f;
	if(GPIO_KEY!=0x0f)//读取按键是否按下
	{
		delay(1000);//延时10ms进行消抖
		if(GPIO_KEY!=0x0f)//再次检测键盘是否按下
		{	
			//测试列
			GPIO_KEY=0X0F;
			switch(GPIO_KEY)
			{
				case(0X07):	KeyValue=1;break;
				case(0X0b):	KeyValue=2;break;
				case(0X0d): KeyValue=3;break;
				case(0X0e):	KeyValue=4;break;
			}
			//测试行
			GPIO_KEY=0XF0;
			switch(GPIO_KEY)
			{
				case(0X70):	KeyValue=KeyValue;break;
				case(0Xb0):	KeyValue=KeyValue+4;break;
				case(0Xd0): KeyValue=KeyValue+8;break;
				case(0Xe0):	KeyValue=KeyValue+12;break;
			}
			while((a<50)&&(GPIO_KEY!=0xf0))	 //检测按键松手检测
			{
				delay(1000);
				a++;
			}
		}
	}
}

void sound()
{
	u16 i=200;
	if(KeyValue==1)
	{
		KeyValue=0;
		P0=smg[0];
		while(i--)
		{
			beep=~beep;		 //低音1
			delay(380);
		}
		
	}

	if(KeyValue==2)
	{
		KeyValue=0;
		P0=smg[1];
		while(i--)
		{
			beep=~beep;	   //低音2
			delay(341);
		}
		
	}

	if(KeyValue==3)
	{
		KeyValue=0;
		P0=smg[2];
		while(i--)
		{
			beep=~beep;	  //低音3
			delay(303);
		}
	}

	if(KeyValue==4)
	{
		KeyValue=0;
		P0=smg[3];
		while(i--)
		{
			beep=~beep;	  //低音4
			delay(286);
		}
	}

	if(KeyValue==5)
	{
		KeyValue=0;
		P0=smg[4];
		while(i--)
		{
			beep=~beep;	  //低音5
			delay(255);
		}
	}

	if(KeyValue==6)
	{
		KeyValue=0;
		P0=smg[5];
		while(i--)
		{
			beep=~beep;		//低音6
			delay(227);
		}
	}

	if(KeyValue==7)
	{
		KeyValue=0;
		P0=smg[6];
		while(i--)
		{
			beep=~beep;	   //低音7
			delay(203);
		}
	}

	if(KeyValue==8)
	{
		KeyValue=0;
		P0=smg[7];
		while(i--)
		{
			beep=~beep;		//中音1
			delay(191);
		}
	}

	if(KeyValue==9)
	{
		KeyValue=0;
		P0=smg[8];
		while(i--)
		{
			beep=~beep;	   //中音2
			delay(170);
		}
	}

	if(KeyValue==10)
	{
		KeyValue=0;
		P0=smg[9];
		while(i--)
		{
			beep=~beep;	   //中音3
			delay(152);
		}
	}

	if(KeyValue==11)
	{
		KeyValue=0;
		P0=smg[10];
		while(i--)
		{
			beep=~beep;	   //中音4
			delay(143);
		}
	}

	if(KeyValue==12)
	{
		KeyValue=0;
		P0=smg[11];
		while(i--)
		{
			beep=~beep;	   //中音5
			delay(128);
		}
	}

	if(KeyValue==13)
	{
		KeyValue=0;
		P0=smg[12];
		while(i--)
		{
			beep=~beep;		//中音6
			delay(114);
		}
	}

	if(KeyValue==14)
	{
		KeyValue=0;
		P0=smg[13];
		while(i--)
		{
			beep=~beep;		//中音7
			delay(101);
		}
	}

	if(KeyValue==15)
	{
		KeyValue=0;
		P0=smg[14];
		while(i--)
		{
			beep=~beep;		//高音1
			delay(96);
		}
	}

	if(KeyValue==16)
	{
		KeyValue=0;
		P0=smg[15];
		while(i--)
		{
			beep=~beep;	  //高音2
			delay(85);
		}
	}
}
void time0init()
{
	TMOD=0X01;
	TH0=0XFc;
	TL0=0X18;
	TR0=1;
	ET0=1;
	EA=1;
}
void main()
{
	time0init();
	while(1);		
}
void tim0() interrupt 1
{
	TH0=0XFc;
	TL0=0X18;
	KEY_Scan();
	sound();		
}
