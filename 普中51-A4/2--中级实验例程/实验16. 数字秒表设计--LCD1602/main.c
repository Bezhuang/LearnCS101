/*
实验说明：
	根据自己使用的LCD1602是否带有转接板，如果带有转接板的即为4位，需在LCD.H头文件中
	将宏#define LCD1602_4PINS打开，我们这里使用的LCD1602是8位，所以默认将该宏注释。
实验接线：
	1，LCD1602液晶模块-->单片机管脚
	参考LCD1602液晶显示实验接线（开发攻略内在对应的实验章节内实验现象有接线说明）
	
实验现象：
	LCD1602上显示秒表
*/

#include<reg52.h>
#include "lcd.h"

typedef unsigned char uint8;
typedef unsigned int uint16;

uint8 a[]="LCD Design of Tm";  //要显示的字符
uint8 num[]="0123456789";
uint8 b[8],shi,fen,miao;
void delay(uint16 i)
{
	while(i--);
}
void wrc(uint8 c)	 //写命令
{
	LcdWriteCom(c);
}
void wrd(uint8 dat)	  //写数据
{
	LcdWriteData(dat);
}
void lcd_init()
{
	LcdInit();	
}
void time0init()
{
	TMOD=0X01;
	TH0=0XFC;
	TL0=0X18; //1ms
	TR0=1;
	ET0=1;
	EA=1;
}
void timepros()
{
	b[0]=num[shi/10];
	b[1]=num[shi%10];
	b[2]=0x3a;
	b[3]=num[fen/10];
	b[4]=num[fen%10];
	b[5]=0x3a;
	b[6]=num[miao/10];
	b[7]=num[miao%10];
}
void display()
{
	uint8 i;
	timepros();
	wrc(0x00+0x80);
	for(i=0;i<16;i++)
	{
		wrd(a[i]);
	}
	wrc(0x44+0x80);
	wrd(b[0]);
	wrd(b[1]);
	wrd(b[2]);
	wrd(b[3]);
	wrd(b[4]);
	wrd(b[5]);
	wrd(b[6]);
	wrd(b[7]);
}
void main()
{
	lcd_init();
	time0init();
	while(1)
	{
		display();
	}	
}
void tim0() interrupt 1
{
	static uint16 n;
	TH0=0XFC;
	TL0=0X18;//1ms
	n++;
	if(n==1000)
	{
		n=0;
		miao++;
		if(miao==60)
		{
			miao=0;
			fen++;
			if(fen==60)
			{
				fen=0;
				shi++;
				if(shi==60)
				{
					shi=0;
					miao=0;
					fen=0;
				}
			}
		}
	}
//	display();
}

