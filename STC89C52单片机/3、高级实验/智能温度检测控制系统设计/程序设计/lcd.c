#include "lcd.h"

/*******************************************************************************
* 函 数 名         : Lcd1602_Delay1ms
* 函数功能		   : 延时函数，延时1ms
* 输    入         : c
* 输    出         : 无
* 说    名         : 该函数是在12MHZ晶振下，12分频单片机的延时。
*******************************************************************************/

void Lcd1602_Delay1ms(uint c)   //误差 0us
{
    uchar a,b;
	for (; c>0; c--)
	{
		 for (b=199;b>0;b--)
		 {
		  	for(a=1;a>0;a--);
		 }      
	}
    	
}

#ifndef 	LCD1602_4PINS	 //当没有定义这个LCD1602_4PINS时
void LCD_WriteCmd(uchar com)	  //写入命令
{
	LCD1602_E = 0;     //使能
	LCD1602_RS = 0;	   //选择发送命令
	LCD1602_RW = 0;	   //选择写入
	
	LCD1602_DATAPINS = com;     //放入命令
	Lcd1602_Delay1ms(1);		//等待数据稳定

	LCD1602_E = 1;	          //写入时序
	Lcd1602_Delay1ms(5);	  //保持时间
	LCD1602_E = 0;
}
#else 
void LCD_WriteCmd(uchar com)	  //写入命令
{
	LCD1602_E = 0;	 //使能清零
	LCD1602_RS = 0;	 //选择写入命令
	LCD1602_RW = 0;	 //选择写入

	LCD1602_DATAPINS = com;	//由于4位的接线是接到P0口的高四位，所以传送高四位不用改
	Lcd1602_Delay1ms(1);

	LCD1602_E = 1;	 //写入时序
	Lcd1602_Delay1ms(5);
	LCD1602_E = 0;

//	Lcd1602_Delay1ms(1);
	LCD1602_DATAPINS = com << 4; //发送低四位
	Lcd1602_Delay1ms(1);

	LCD1602_E = 1;	 //写入时序
	Lcd1602_Delay1ms(5);
	LCD1602_E = 0;
}
#endif
/*******************************************************************************
* 函 数 名         : LcdWriteData
* 函数功能		   : 向LCD写入一个字节的数据
* 输    入         : dat
* 输    出         : 无
*******************************************************************************/		   
#ifndef 	LCD1602_4PINS		   
void LCD_WriteData(uchar dat)			//写入数据
{
	LCD1602_E = 0;	//使能清零
	LCD1602_RS = 1;	//选择输入数据
	LCD1602_RW = 0;	//选择写入

	LCD1602_DATAPINS = dat; //写入数据
	Lcd1602_Delay1ms(1);

	LCD1602_E = 1;   //写入时序
	Lcd1602_Delay1ms(5);   //保持时间
	LCD1602_E = 0;
}
#else
void LCD_WriteData(uchar dat)			//写入数据
{
	LCD1602_E = 0;	  //使能清零
	LCD1602_RS = 1;	  //选择写入数据
	LCD1602_RW = 0;	  //选择写入

	LCD1602_DATAPINS = dat;	//由于4位的接线是接到P0口的高四位，所以传送高四位不用改
	Lcd1602_Delay1ms(1);

	LCD1602_E = 1;	  //写入时序
	Lcd1602_Delay1ms(5);
	LCD1602_E = 0;

	LCD1602_DATAPINS = dat << 4; //写入低四位
	Lcd1602_Delay1ms(1);

	LCD1602_E = 1;	  //写入时序
	Lcd1602_Delay1ms(5);
	LCD1602_E = 0;
}
#endif
/*******************************************************************************
* 函 数 名       : LcdInit()
* 函数功能		 : 初始化LCD屏
* 输    入       : 无
* 输    出       : 无
*******************************************************************************/		   
#ifndef		LCD1602_4PINS
void LcdInit()						  //LCD初始化子程序
{
 	LCD_WriteCmd(0x38);  //开显示
	LCD_WriteCmd(0x0c);  //开显示不显示光标
	LCD_WriteCmd(0x06);  //写一个指针加1
	LCD_WriteCmd(0x01);  //清屏
	LCD_WriteCmd(0x80);  //设置数据指针起点
}
#else
void LCD_Init()						  //LCD初始化子程序
{
	LCD_WriteCmd(0x32);	 //将8位总线转为4位总线
	LCD_WriteCmd(0x28);	 //在四位线下的初始化
	LCD_WriteCmd(0x0c);  //开显示不显示光标
	LCD_WriteCmd(0x06);  //写一个指针加1
	LCD_WriteCmd(0x01);  //清屏
	LCD_WriteCmd(0x80);  //设置数据指针起点
}
#endif



void LCD_Clear()
{
	LCD_WriteCmd(0x01);
	LCD_WriteCmd(0x80);	
}

//在任何位置显示字符串

void LCD_Dispstring(u8 x,u8 line,u8 *p)	  
{
	char i=0;
	if(line<1)	   //第一行显示
	{	
		while(*p!='\0')
		{
			if(i<16-x)
			{
				LCD_WriteCmd(0x80+i+x);	
			}
			else
			{
				LCD_WriteCmd(0x40+0x80+i+x-16);	
			}
			LCD_WriteData(*p);
			p++;
			i++;	
		}	
	}
	else		   //第2行显示
	{
		while(*p!='\0')
		{
			if(i<16-x)
			{
				LCD_WriteCmd(0x80+0x40+i+x);	
			}
			else
			{
				LCD_WriteCmd(0x80+i+x-16);	
			}
			LCD_WriteData(*p);
			p++;
			i++;	
		}	
	}		
}


