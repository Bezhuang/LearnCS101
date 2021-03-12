/*
实验说明：
	根据自己使用的LCD1602是否带有转接板，如果带有转接板的即为4位，需在LCD.H头文件中
	将宏#define LCD1602_4PINS打开，我们这里使用的LCD1602是8位，所以默认将该宏注释。
实验接线：
	1，LCD1602液晶模块-->单片机管脚
	参考LCD1602液晶显示实验接线（开发攻略内在对应的实验章节内实验现象有接线说明）
	2，红外接收模块-->单片机管脚 
	参考红外遥控实验接线（开发攻略内在对应的实验章节内实验现象有接线说明）
	3，直流电机模块-->单片机管脚
	IN1-->P10（参考直流电机实验接线）
	
实验现象：
	LCD1602显示遥控器键值，并且显示电机状态（ON/OFF），通过按第一个按键可以控制马达的启动和停止
*/


#include<reg51.h>
#include"lcd.h"

typedef unsigned char uint8;
typedef unsigned int uint16;


sbit moto=P1^0;

uint8 d1[8]=" RED IR ";
uint8 d2[12]="MOTO STATE: ";
uint8 num[16]="0123456789ABCDEF";

uint8 irtime;	  //接收时间
uint8 startflag;  //开始检测
uint8 bitnum;	  //bit位数
uint8 irdata[33]; //寄存没有个bit的时间
uint8 irreceok;	  //接收完成标志位
uint8 ircode[4];  //将接收的四个字节数据保存
uint8 irprosok;	  //接收数据处理标志位
uint8 irdisp[8];  //将四个字节的16进制通过转换变成十进制存储
uint8 dat1,dat2;
uint8 keynum;
uint8 motoflag;
void delay(uint16 i)
{
	while(i--);
}
void lcdwrc(uint8 c)
{
	LcdWriteCom(c);
}
void lcdwrd(uint8 dat)
{
	LcdWriteData(dat);	
}
void lcd_init()
{
	LcdInit();
}
void int0init()
{
	EA=1;
	EX0=1;
	IT0=1;
}
void time0init()
{
	TMOD=0X02;	//设置定时器0模式2.该模式为自动装载模式
	TH0=0X00;
	TL0=0X00;//设定计数初值，每当TL0计数到255时，TH0将把自己的数据给TL0，又重新计数
	TR0=1;
	ET0=1;
	EA=1;	
}
void irpros() //红外接收数据处理 ，区分是数据0还是1
{
	uint8 i,j,value;
	uint8 k=1;	//引导码去掉，所以令k=1；
	for(j=0;j<4;j++)  //取出了一帧数据中的四个字节数据
	{
		for(i=0;i<8;i++)	//取出了一个字节的数据		
		{
			value>>=1;
			if(irdata[k]>6)
			{
				value=value|0x80;
			}
			k++;
		}
		ircode[j]=value;
	}
	irprosok=1;
}
void irwork()  //将四个字节的数据转换成10进制数显示
{
	irdisp[0]=ircode[0]/16;//显示高位
	irdisp[1]=ircode[0]%16;//显示低位  
	irdisp[2]=ircode[1]/16;
	irdisp[3]=ircode[1]%16;	 //同一个遥控器此2个字节的引导码数据是不会改变的，改变的只是数据码及反码
	irdisp[4]=ircode[2]/16;
	irdisp[5]=ircode[2]%16;
	irdisp[6]=ircode[3]/16;
	irdisp[7]=ircode[3]%16;
	dat1=irdisp[4];
	dat2=irdisp[5];
	keynum++;
}
void display()
{
	uint8 i;
	lcdwrc(0x00+0x80);
	for(i=0;i<8;i++)
	{
		lcdwrd(d1[i]);
	}	
	for(i=4;i<6;i++)
	{
		lcdwrd(num[irdisp[i]]);
	} 
	lcdwrc(0x40+0x80);
	for(i=0;i<12;i++)
	{
		lcdwrd(d2[i]);
	}
	if(motoflag==1)			//马达状态显示
	{
		lcdwrd('O');
		lcdwrd('N');
		lcdwrd(' ');
	}
	else
	{
		lcdwrd('O');
		lcdwrd('F');
		lcdwrd('F');	
	}
}
void motopros()
{
	if((dat1==4)&&(dat2==5)&&(keynum==1))  //按下第一次按键开马达
	{			
		dat1=0;
		dat2=0;
		motoflag=1;
		moto=1;						
	}
			
	if((dat1==4)&&(dat2==5)&&(keynum>=2))	//按下第二次此按键时关闭马达
	{
		dat1=0;
		dat2=0;
		keynum=0;
		motoflag=0;
		moto=0;			
	}				
}
void main()
{
	moto=0;	
	lcd_init();
	int0init();
	time0init();
	while(1)
	{
		if(irreceok)
		{
			irreceok=0;
			irpros();
			if(irprosok)
			{
				irwork();
			}
		}
		motopros();
		display();
	}		
}
void time0() interrupt 1
{
	irtime++;//每进来一次就说明定时时间为256us；	
}
void init0() interrupt 0
{
	if(startflag)
	{
		if(irtime>32)//检测引导码，求法是用引导码时间除以一次计数时间，看看要多少次
		{
			bitnum=0;	
		}
		irdata[bitnum]=irtime;
		irtime=0;
		bitnum++;
		if(bitnum==33)
		{
			bitnum=0;
			irreceok=1;//一帧红外数据接收完成标志
		}
	}
	else
	{
		startflag=1;//将开始标志位置1，等到下次进入中断即可进入if语句
		irtime=0;//将开始之前的计数器时间清零。等到下次进入中断的时候才是引导码真正的时间
	}
}