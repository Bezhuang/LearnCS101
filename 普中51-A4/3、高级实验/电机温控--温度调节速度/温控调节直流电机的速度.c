/*
实验说明：
	根据自己使用的LCD1602是否带有转接板，如果带有转接板的即为4位，需在LCD.H头文件中
	将宏#define LCD1602_4PINS打开，我们这里使用的LCD1602是8位，所以默认将该宏注释。
实验接线：
	1，LCD1602液晶模块-->单片机管脚
	参考LCD1602液晶显示实验接线（开发攻略内在对应的实验章节内实验现象有接线说明）
	2，DS18B20温度传感器模块-->单片机管脚 
	参考DS18B20温度传感器实验接线（开发攻略内在对应的实验章节内实验现象有接线说明）
	3，直流电机模块-->单片机管脚
	IN1-->P10（参考直流电机实验接线）
	
实验现象：
	LCD1602显示温度值，温度变化改变直流电机旋转速度，这里仅仅是通过修改电机开关速度实现调速，
	温度调速范围在main函数内设置
*/

#include<reg51.h>
#include<intrins.h>
#include"lcd.h"
typedef unsigned char uint8;
typedef unsigned int uint16;
typedef unsigned long uint32;

sbit dq=P3^7;
sbit moto=P1^0;	//直流电机
uint8 d[16]="   tempertury   ";
uint8 num[10]="0123456789";
uint8 a,c,temp;
void delay(uint16 i)
{
	while(i--);
}
void wrc(uint8 c)
{
	LcdWriteCom(c);
}
void wrd(uint8 dat)
{
	LcdWriteData(dat);
}
void lcd_init()
{
	LcdInit();
}
void ds18b20init()		//18b20的初始化
{
	dq=1;
	delay(1);
	dq=0;
	delay(80);
	dq=1;
	delay(5);
	dq=0;
	delay(20);
	dq=1;
	delay(35);
}
void ds18b20wr(uint8 dat)	  //18b20写数据
{
	uint8 i;
	for(i=0;i<8;i++)
	{
		dq=0;
		dq=dat&0x01;
		dat>>=1;
		delay(8);//在时序上只有这一块对时序要求最准确，他的时间必须大于15us
		dq=1;
		delay(1);
	}	
}
uint8 ds18b20rd()		  //18b20读数据
{
	uint8 value,i;
	for(i=0;i<8;i++)	
	{
		dq=0;
		value>>=1;
		dq=1;
		if(dq==1)value|=0x80;
		delay(8);//在这一块也对时间要求特别准确，整段程序必须大于60us		
	}
	return value;
}
uint8 readtemp()			  //读取温度内需要复位的
{
	uint8 b;
	ds18b20init();		//初始化
	ds18b20wr(0xcc);   //发送忽略ROM指令
	ds18b20wr(0x44);   //发送温度转换指令
	delay(100);
	ds18b20init();	   //初始化
	ds18b20wr(0xcc);   //发送忽略ROM指令
	ds18b20wr(0xbe);   //发读暂存器指令
	a=ds18b20rd();	 //温度的低八位
	b=ds18b20rd();	 //温度的高八位
	b<<=4;			 //ssss s***；s为标志位s=0表示温度值为正数，s=1温度值为负数
	c=b&0x80;		//温度正负标志位确认
	b+=(a&0xf0)>>4;
	a=a&0x0f;	  //温度的小数部分
	return b;
}
void display()
{
	uint16 i,k;
	float dio;
	dio=a*0.0625;
	k=dio*10000;//取小数点后两位有效数字
	wrc(0x80+0x00);
	for(i=0;i<16;i++)
	{
		wrd(d[i]);
	}
	wrc(0x80+0x43);
	if(c==0x80)	//读取到负温度即为补码，要将其转换成源码
	{
		wrd('-');
		temp=temp-1;
		temp=(~temp)|0x80;//负数的补码即为反码+1；而负数的反码为其源码取反，除了符号位；正数的补码等于正数的反码等于正数的源码
	}	
	else
	{
		wrd('+');
		temp=(temp);
	}			
	wrd(num[temp/100]);
	wrd(num[temp%100/10]);
	wrd(num[temp%100%10]);
	wrd('.');
	wrd(num[k/1000]);
	wrd(num[k%1000/100]);
	wrd(0xdf);
	wrd('C');
}
void motospeed(uint16 i)
{
	while(i--)
	{
		moto=~moto;
	}		
}
void main()
{
	moto=0;
	lcd_init();
	while(1)
	{
		temp=readtemp();
		display();
		//具体的温度和速度范围自己可以设置
		if(temp>27&&temp<29) //速度1
			motospeed(1);
		if(temp>23&&temp<24) //速度2
			motospeed(10);
		if(temp>29&&temp<35) //速度3
			motospeed(100);			
	}		
}