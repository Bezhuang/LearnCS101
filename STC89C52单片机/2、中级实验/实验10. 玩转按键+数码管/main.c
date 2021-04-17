/*
实验说明：
	
实验接线：
	1，动态数码管模块-->单片机管脚
	参考动态数码管显示实验接线（开发攻略内在对应的实验章节内实验现象有接线说明）
	2，独立按键模块-->单片机管脚 
	K1-->P10
	K2-->P11
	K3-->P12
	K4-->P13
	
实验现象：
	按K4键进入数字设置，按K1和K3键对闪烁的数字进行加和减，按K2键进行数码管移位设置
	再次按下K4键退出设置。
*/


#include "reg52.h"			 //此文件中定义了单片机的一些特殊功能寄存器

typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

sbit k1=P3^0;
sbit k2=P3^1;
sbit k3=P3^2;
sbit k4=P3^3;	 //定义按键端口

#define KEY1 1
#define KEY2 2
#define KEY3 3
#define KEY4 4

u8 code smgduan[17]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,
					0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};//显示0~F的值

u8 DisplayData[8];
char datnum1=0,datnum2=0,datnum3=0,datnum4=0;
u8 setflag=0;
u8 wei_change=0;

/*******************************************************************************
* 函 数 名         : delay
* 函数功能		   : 延时函数，i=1时，大约延时10us
*******************************************************************************/
void delay(u16 i)
{
	while(i--);	
}

/*******************************************************************************
* 函 数 名         : Timer0Init
* 函数功能		   : 定时器0初始化
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Timer0Init()
{
	TMOD|=0X01;//选择为定时器0模式，工作方式1，仅用TR0打开启动。

	TH0=0Xd8;	//给定时器赋初值，定时10ms
	TL0=0Xf0;	
	ET0=1;//打开定时器0中断允许
	EA=1;//打开总中断
	//TR0=1;//打开定时器			
}

/*******************************************************************************
* 函 数 名         : DigDisplay
* 函数功能		   : 数码管动态扫描函数，循环扫描8个数码管显示
*******************************************************************************/
void DigDisplay()
{
	u8 i;
	for(i=0;i<8;i++)
	{
		switch(i)	 //位选，选择点亮的数码管，
		{
			case(0):
				LSA=1;LSB=1;LSC=1; break;//显示第7位
			case(1):
				LSA=0;LSB=1;LSC=1; break;//显示第6位
			case(2):
				LSA=1;LSB=0;LSC=1; break;//显示第5位
			case(3):
				LSA=0;LSB=0;LSC=1; break;//显示第4位
			case(4):
				LSA=1;LSB=1;LSC=0; break;//显示第3位 
			case(5):
				LSA=0;LSB=1;LSC=0; break;//显示第2位 
			case(6):
				LSA=1;LSB=0;LSC=0; break;//显示第1位 
			case(7):
				LSA=0;LSB=0;LSC=0; break;//显示第0位	
		}
		P0=DisplayData[i];//发送段码
		delay(100); //间隔一段时间扫描	
		P0=0x00;//消隐
	}
}

//mode=0 单次   1：连续
u8 KeyScan(u8 mode)
{
	static u8 keyen=1;
	if(mode==1)
	{
		keyen=1;
	}
	if(keyen==1&&(k1==0||k2==0||k3==0||k4==0))
	{
		delay(1000);  //消抖处理
		keyen=0;
		if(k1==0)return KEY1;
		else if(k2==0)return KEY2;
		else if(k3==0)return KEY3;
		else if(k4==0)return KEY4;				
	}
	else if(k1==1&&k2==1&&k3==1&&k4==1)
	{
		keyen=1;
	}
	return 0;	
}

void datapros()
{
	u8 key;
	key=KeyScan(0);
	
	if(key==KEY4)	   //设置
	{
		setflag++;
		TR0=1;	   //开启定时器
		if(setflag==2)
		{
			TR0=0;		//关闭定时器
			setflag=0;	
		}
	}

	if(setflag==0)	 //默认/退出设置显示
	{
		DisplayData[0]=smgduan[datnum4];
		DisplayData[1]=smgduan[datnum3];
		DisplayData[2]=smgduan[datnum2];
		DisplayData[3]=smgduan[datnum1];
	}
	else	  //进入设置  数码管选中闪烁
	{
		if(key==KEY2)	    //数据位数移动变化
		{
			wei_change++;
			if(wei_change>3)wei_change=0;
			DisplayData[0]=smgduan[datnum4];
			DisplayData[1]=smgduan[datnum3];
			DisplayData[2]=smgduan[datnum2];
			DisplayData[3]=smgduan[datnum1];	
		}

		else if(key==KEY1)	 //数据加
		{
			switch(wei_change)
			{
				case 0:  datnum1++;
						if(datnum1>9)datnum1=0;
						break;
				case 1:  datnum2++;
						if(datnum2>9)datnum2=0;
						break;
				case 2:  datnum3++;
						if(datnum3>9)datnum3=0;
						break;
				case 3:  datnum4++;
						if(datnum4>9)datnum4=0;
						break;

			}	
		}
		else if(key==KEY3)	 //数据减
		{
			switch(wei_change)
			{
				case 0:  datnum1--;
						if(datnum1<=0)datnum1=9;		
						break;
				case 1:  datnum2--;
						if(datnum2<=0)datnum2=9;
						break;
				case 2:  datnum3--;
						if(datnum3<=0)datnum3=9;
						break;
				case 3:  datnum4--;
						if(datnum4<=0)datnum4=9;
						break;

			}	
		}
			
	}
	
}
/*******************************************************************************
* 函 数 名       : main
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/
void main()
{	
	Timer0Init();
	while(1)
	{	
		datapros();
		DigDisplay();	
	}		
}

/*******************************************************************************
* 函 数 名         : void Timer0() interrupt 1
* 函数功能		   : 定时器0中断函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Timer0() interrupt 1
{
	static u8 i;
	TH0=0Xd8;	//给定时器赋初值，定时10ms
	TL0=0Xf0;
	i++;
	if(i==50)	  //500ms
	{
		switch(wei_change)
		{
			case 0: DisplayData[3]=0x00;break;
			case 1: DisplayData[2]=0x00;break;
			case 2: DisplayData[1]=0x00;break;
			case 3: DisplayData[0]=0x00;break;
		}	
	}
	if(i==100)	   //1s
	{
		i=0;
		switch(wei_change)
		{
			case 0: DisplayData[3]=smgduan[datnum1];break;
			case 1: DisplayData[2]=smgduan[datnum2];break;
			case 2: DisplayData[1]=smgduan[datnum3];break;
			case 3: DisplayData[0]=smgduan[datnum4];break;
		}			
	}
}

