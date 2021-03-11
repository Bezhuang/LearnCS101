/*
实验说明：
	根据自己使用的LCD1602是否带有转接板，如果带有转接板的即为4位，需在LCD.H头文件中
	将宏#define LCD1602_4PINS打开，我们这里使用的LCD1602是8位，所以默认将该宏注释。
实验接线：
	1，LCD1602液晶模块-->单片机管脚
	参考LCD1602液晶显示实验接线（开发攻略内在对应的实验章节内实验现象有接线说明）
	2，MQ-135传感器模块-->单片机管脚 
	将传感器模块对应插入到开发板上的接口处，然后使用杜邦线将MQ135模块的P6端子上AO脚与开发板上
	DAC模块边上的J52端子的AIN3脚连接
	3，ADC模块-->单片机管脚
	参考ADC模数转换实验接线（开发攻略内在对应的实验章节内实验现象有接线说明）
	4，独立按键模块-->单片机管脚
	K1-->P33
	K2-->P21
	K3-->P22
	5，蜂鸣器模块-->单片机管脚
	BEEP-->P15
	6，直流电机模块-->单片机管脚
	参考直流电机实验接线（开发攻略内在对应的实验章节内实验现象有接线说明）
	
实验现象：
	通过按键K1可对气体浓度阀值进行设定
	按下一次K1，进入上限设定，再按下K1一次，退出设定模式，进入正常气体浓度采集状态。
	进入阀值设定模式后，通过K2和K3进行数值加减。当采集的气体浓度高于设定上限值，蜂鸣器报警且
	电机旋转排气，当采集的气体浓度低于设定上限值，蜂鸣器和电机不工作，处于正常工作状态。
*/

#include<reg51.h>
#include "XPT2046.h"
#include"lcd.h"

typedef unsigned char uint8;
typedef unsigned int uint16;


sbit k1=P3^3; //模式
sbit k2=P2^1; //加
sbit k3=P2^2; //减

sbit moto=P1^0;
sbit beep=P1^5;


uint8 mode=0;
char temph=20;
uint8 temp,flag;

uint8 code num[10]="0123456789";

uint8 code str1[]="GAS:";  
uint8 code str2[]="SET:"; 



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
void lcd_init()	   // LCD1602初始化
{
	LcdInit();
}

void key_pros()  //按键处理函数
{
	if(k1==0)
	{
		delay(1000);
		if(k1==0)
		{
			mode++;
			flag=0;
			if(mode==2)
			{
				mode=0;
				flag=1;	
			}
			
		}
		while(!k1);
	}
	if(mode==1)		  //对空气检测报警值设定
	{
		if(k2==0)		  //加
		{
			delay(1000);
			if(k2==0)
			{
				temph+=1;
				if(temph>=100)temph=100;
			}
			while(!k2);
		}
		if(k3==0)	   //减
		{
			delay(1000);
			if(k3==0)
			{
				temph-=1;
				if(temph<=0)temph=0;	
			}
			while(!k3);
		}
	}
	
}

void lcd_init_display()	   //LCD初始化显示
{
	uint8 i;
	for(i=0;i<4;i++)
	{
		wrc(0x80+i);
		wrd(str1[i]);	
	}

	for(i=0;i<4;i++)
	{
		wrc(0xc0+i);
		wrd(str2[i]);	
	}
}

void data_pros()	//数据处理函数
{
	uint8 tempbuf[3],temp_buf[3],i;
	tempbuf[0]=temp/100+0x30;
	tempbuf[1]=temp%100/10+0x30;				
	tempbuf[2]=temp%100%10+0x30;
	
	temp_buf[0]=temph/100+0x30;
	temp_buf[1]=temph%100/10+0x30;				
	temp_buf[2]=temph%100%10+0x30;

	for(i=0;i<3;i++)
	{
		wrc(0x84+i);
		wrd(tempbuf[i]);
	}

	for(i=0;i<3;i++)
	{
		wrc(0xc4+i);
		wrd(temp_buf[i]);
	}
}

void sound()
{
	uint8 i=100;
	while(i--)
	{
		beep=~beep;
		delay(100);	
	}
}
void baojinpros()	//报警处理
{
	if(temp>=temph&&flag==1)
	{
		moto=1;
		sound();
	}
	else
	{	
		moto=0;
		beep=1;
	}
}

void main()
{
	moto=1;
	beep=1;
	lcd_init();
	lcd_init_display();	   //LCD初始化显示
	while(1)
	{	
		key_pros();
		data_pros();
		baojinpros();
		temp = Read_AD_Data(0x94)/40;			
	}	
}
