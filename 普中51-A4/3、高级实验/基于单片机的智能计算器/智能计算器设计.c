/*
实验说明：
	根据自己使用的LCD1602是否带有转接板，如果带有转接板的即为4位，需在LCD.H头文件中
	将宏#define LCD1602_4PINS打开，我们这里使用的LCD1602是8位，所以默认将该宏注释。
实验接线：
	1，LCD1602液晶模块-->单片机管脚
	参考LCD1602液晶显示实验接线（开发攻略内在对应的实验章节内实验现象有接线说明）
	2，矩阵按键模块-->单片机管脚 
	参考矩阵按键实验接线（开发攻略内在对应的实验章节内实验现象有接线说明）
	3，蜂鸣器模块-->单片机管脚
	BEEP-->P20（未使用，用户可自行扩展）
	
实验现象：
	S16 S12 S8 S4分别是123+
	S15 S11 S7 S3分别是456-
	S14 S10 S6 S2分别是789*
	S13 S9 S5 S1分别是0 CLR =
*/


/* 实现两个数的运算，每个数的位数至少可以八位  */
#include<reg51.h>
#include"lcd.h"
			
typedef unsigned char uint8;
typedef unsigned int uint16;

sbit led=P3^7;

sbit beep=P2^0;
uint8 key,num;
uint8 fuhao;//定义具体的那个符号，是加减还是乘除。
uint8 flag;	//定义有没有按下符号键，这个是统称
long a,b,c,d;	//定义运算数据的第一个和第二个及等于的数变量
uint8 k; //定义小数点后面显示的位数
uint8 biao;

uint8 dat1[]={1,2,3,0x2b-0x30, 4,5,6,0x2d-0x30, 7,8,9,0x2a-0x30, 0,0x01-0x30,0x3d-0x30,0x2b-0x30 };//保存显示的数据

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
	key=0;
	num=0;
	flag=0;
	fuhao=0;
	a=0;
	b=0;
	c=0;
	d=0;
	biao=0;
	led=0;

}

void keyscan()
{
	P1=0xfe;   //令第一行为0，然后判断是哪一列按下
	if(P1!=0xfe)
	{
		delay(1000);
		if(P1!=0xfe)
		{
			key=P1&0xf0;
			switch(key)
			{
				case 0xe0: num=0;break;	  //1
				case 0xd0: num=1;break;	  //2
				case 0xb0: num=2;break;	  //3
				case 0x70: num=3;break;	  //加
			}
		}
		while(P1!=0xfe);
		if(num==0||num==1||num==2)	 //确认第一行的数1,2,3
		{
			if(flag==0)	 //没有按下符号键
			{
				//led=1;
				a=a*10+dat1[num];	
			}
			else
			{
				//led=1;
				b=b*10+dat1[num];
			}
		
		}
		if(num==3)
		{
			//led=0;
			flag=1;
			fuhao=1;//加号+	
		}
		lcdwrd(0x30+dat1[num]);
	}


	P1=0xfd;				//令第二行为0，判断是哪一列按下
	if(P1!=0xfd)
	{
		delay(1000);
		if(P1!=0xfd)
		{
			key=P1&0xf0;
			switch(key)
			{
				case 0xe0: num=4;break;	  //4
				case 0xd0: num=5;break;	  //5
				case 0xb0: num=6;break;	  //6
				case 0x70: num=7;break;	  //减—
			}	
		}
		while(P1!=0xfd);
		if(num==4||num==5||num==6)
		{
			if(flag==0)	 //没有按下符号键
			{
				//led=1;
				a=a*10+dat1[num];	
			}
			else
			{
				//led=1;
				b=b*10+dat1[num];
			}			
		}
		else
		{
			flag=1;
			fuhao=2;//带表减号
		}
		lcdwrd(0x30+dat1[num]);
	}


	P1=0xfb;		 //令第三行为0，判断哪一列按下
	if(P1!=0xfb)
	{
		delay(1000);
		if(P1!=0xfb)
		{
			key=P1&0xf0;
			switch(key)
			{
				case 0xe0: num=8;break;	  //7
				case 0xd0: num=9;break;	  //8
				case 0xb0: num=10;break;  //9
				case 0x70: num=11;break;  //乘*
			}	
		}
		while(P1!=0xfb);
		if(num==8||num==9||num==10)
		{
			if(flag==0)	 //没有按下符号键
			{
				//led=1;
				a=a*10+dat1[num];	
			}
			else
			{
				//led=1;
				b=b*10+dat1[num];
			}			
		}
		else
		{
			flag=1;
			fuhao=3;//带表乘号*
		}
		lcdwrd(0x30+dat1[num]);
	}


	P1=0xf7;		 //令第四行为0，判断哪一列按下
	if(P1!=0xf7)
	{
		delay(1000);
		if(P1!=0xf7)
		{
			key=P1&0xf0;
			switch(key)
			{
				case 0xe0: num=12;break;  //0
				case 0xd0: num=13;break;  //清除rst
				case 0xb0: num=14;break;  //等号=
				case 0x70: num=15;break;  //除/
			}	
		}
		while(P1!=0xf7);
		switch(num)
		{
			case 12: 
					if(flag==0)	 //没有按下符号键
					{
						//led=1;
						a=a*10+dat1[num];
						lcdwrd(0x30);	
					}
					else
					{
						//led=1;
						b=b*10+dat1[num];
						lcdwrd(0x30);
					}
					break;
			
			case 13: 
					lcdwrc(0x01);	//清屏指令			
					a=0;
					b=0;
					flag=0;
					fuhao=0;
					break;

			case 15:
			
					flag=1;
					fuhao=4;
					lcdwrd(0x2f);//除号/
					break;
					
			case 14: 
					if(fuhao==1)//加
					{
						lcdwrc(0x4f+0x80);
						lcdwrc(0x04);//设置光标左移，屏幕不移动
						c=a+b;
						while(c!=0)	 //一位一位显示
						{
							lcdwrd(0x30+c%10);//显示结果的最后一位在0x4f的位置
							c=c/10;//取前面的结果数据	
						}
						lcdwrd(0x3d); //显示等于号=
						a=0;
						b=0;
						flag=0;
						fuhao=0;//全部清除为0
					}
					if(fuhao==2)   //减
					{
						lcdwrc(0x4f+0x80);
						lcdwrc(0x04);//设置光标左移，屏幕不移动
						if(a>b)
							c=a-b;
						else
							c=b-a;
						
						while(c!=0)	 //一位一位显示
						{
							lcdwrd(0x30+c%10);//显示结果的最后一位在0x4f的位置
							c=c/10;//取前面的结果数据	
						}
						if(a<b)	lcdwrd(0x2d); //显示-号
						lcdwrd(0x3d); //显示等于号=
						a=0;
						b=0;
						flag=0;
						fuhao=0;//全部清除为0
					}
					if(fuhao==3)//乘法		
					{
						lcdwrc(0x4f+0x80);
						lcdwrc(0x04);//设置光标左移，屏幕不移动
						c=a*b;
						while(c!=0)	 //一位一位显示
						{
							lcdwrd(0x30+c%10);//显示结果的最后一位在0x4f的位置
							c=c/10;//取前面的结果数据	
						}
						lcdwrd(0x3d); //显示等于号=
						a=0;
						b=0;
						flag=0;
						fuhao=0;//全部清除为0	
					}
					if(fuhao==3)//乘法		
					{
						lcdwrc(0x4f+0x80);
						lcdwrc(0x04);//设置光标左移，屏幕不移动
						c=a*b;
						while(c!=0)	 //一位一位显示
						{
							lcdwrd(0x30+c%10);//显示结果的最后一位在0x4f的位置
							c=c/10;//取前面的结果数据	
						}
						lcdwrd(0x3d); //显示等于号=
						a=0;
						b=0;
						flag=0;
						fuhao=0;//全部清除为0	
					}
					if(fuhao==4)
					{
						k=0;
						lcdwrc(0x4f+0x80);
						lcdwrc(0x04);//设置光标左移，屏幕不移动
						c=(long)(((float)a/b)*1000);//强制转换为long。
						while(c!=0)	 //一位一位显示
						{
							k++;
							lcdwrd(0x30+c%10);//显示结果的最后一位在0x4f的位置
							c=c/10;//取前面的结果数据
							if(k==3)
							{
								lcdwrd(0x2e);
								k=0;
							}		
						}
						if(a/b<0)	  //如果a比b小的话那么除的结果最高位是0
						{
							lcdwrd(0x30);	
						}
						lcdwrd(0x3d); //显示等号
						a=0;
						b=0;
						flag=0;
						fuhao=0;//全部清除为0
					}
					break;

		}
	}

}



void main()
{
	lcd_init();
	while(1)
	{
		keyscan();	
	}
}
