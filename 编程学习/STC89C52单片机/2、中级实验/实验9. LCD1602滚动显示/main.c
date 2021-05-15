/**************************************************************************************
注意事项：
根据自己使用的LCD1602是否带有转接板，如果带有转接板的即为4位，需在LCD.H头文件中
将宏#define LCD1602_4PINS打开，我们这里使用的LCD1602是8位，所以默认将该宏注释。	
	
接线说明：（开发攻略每个实验章节内的实验现象都有对应的接线图说明）
参考LCD1602实验																		  
***************************************************************************************/

#include "reg52.h"			 //此文件中定义了单片机的一些特殊功能寄存器
#include "lcd.h"

typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;

u8 a[16]="perchin designed";
u8 b[27]="welcome to the world of mcu";

void delay(u16 i)  //当i=1，大约延时10us
{
	while(i--);
}

void LCD_Display(void)
{
	u8 i;

	LcdWriteCom(0x00+0x80);
	for(i=0;i<16;i++)
	{
		LcdWriteData(a[i]);	
	}
	LcdWriteCom(0x40+0x80);
	for(i=0;i<27;i++)
	{
		LcdWriteData(b[i]);
	} 
	LcdWriteCom(0x07);	 //每写一个数据屏幕就要右移一位，就相对于数据来说就是左移了；
	while(1)
	{	
		LcdWriteCom(0x00+0x80);
		for(i=0;i<16;i++)
		{
			LcdWriteData(a[i]);
			delay(30000);	//如果不加这条延时语句的话滚动会非常快。
		}
	}
}

/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void main(void)
{

	LcdInit();
	
	while(1)
	{
		LCD_Display();
	}				
}
