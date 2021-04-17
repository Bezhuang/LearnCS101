/*
实验说明：
	根据自己使用的LCD1602是否带有转接板，如果带有转接板的即为4位，需在LCD.H头文件中
	将宏#define LCD1602_4PINS打开，我们这里使用的LCD1602是8位，所以默认将该宏注释。	
实验接线：
	LCD1602液晶模块-->单片机管脚
	参考LCD1602液晶显示实验接线（开发攻略内在对应的实验章节内实验现象有接线说明）
	超声波模块-->单片机管脚
	TRIG-->P21
	ECHO-->P20

实验现象：
	LCD1602上显示超声波检测的距离，单位mm
*/


#include<reg51.h>
#include<intrins.h>	
#include"lcd.h"

sbit Trig = P2^1;
sbit Echo = P2^0;



unsigned char PuZh[]=" Pechin Science ";
unsigned char code ASCII[15] =    {'0','1','2','3','4','5','6','7','8','9','.','-','M'};

static unsigned char DisNum = 0; //显示用指针				  
       unsigned int  time=0;
	   unsigned long S=0;
	   bit      flag =0;
	   unsigned char disbuff[4]	   ={ 0,0,0,0,};
/*******************************************************************************
* 函 数 名         : main
* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void Conut(void)
	{
	 time=TH0*256+TL0;
	 TH0=0;
	 TL0=0;
	
	 S=(time*1.7)/100;     //算出来是CM
	 if((S>=700)||flag==1) //超出测量范围显示“-”
	 {	 
	  flag=0;
	 
	  DisplayOneChar(0, 1, ASCII[11]);
	  DisplayOneChar(1, 1, ASCII[10]);	//显示点
	  DisplayOneChar(2, 1, ASCII[11]);
	  DisplayOneChar(3, 1, ASCII[11]);
	  DisplayOneChar(4, 1, ASCII[12]);	//显示M
	 }
	 else
	 {
	  disbuff[0]=S%1000/100;
	  disbuff[1]=S%1000%100/10;
	  disbuff[2]=S%1000%10 %10;
	  DisplayOneChar(0, 1, ASCII[disbuff[0]]);
	  DisplayOneChar(1, 1, ASCII[10]);	//显示点
	  DisplayOneChar(2, 1, ASCII[disbuff[1]]);
	  DisplayOneChar(3, 1, ASCII[disbuff[2]]);
	  DisplayOneChar(4, 1, ASCII[12]);	//显示M
	 }
	}

void zd0() interrupt 1 		 //T0中断用来计数器溢出,超过测距范围
  {
    flag=1;							 //中断溢出标志
  }

 void  StartModule() 		         //启动模块
  {
	  Trig=1;			                     //启动一次模块
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_();
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_();
	  Trig=0;
  }



void delayms(unsigned int ms)
{
	unsigned char i=100,j;
	for(;ms;ms--)
	{
		while(--i)
		{
			j=10;
			while(--j);
		}
	}
}

void main(void)
{

	 TMOD=0x01;		   //设T0为方式1，GATE=1；
	 TH0=0;
	 TL0=0;          
	 ET0=1;             //允许T0中断
	 EA=1;			   //开启总中断	

	LcdInit();
	LcdShowStr(0,0,PuZh);
	while(1)
	{
		 StartModule();
	     while(!Echo);		//当RX为零时等待
	     TR0=1;			    //开启计数
	     while(Echo);			//当RX为1计数并等待
	     TR0=0;				//关闭计数
         Conut();			//计算
		 delayms(80);
	}
			
}