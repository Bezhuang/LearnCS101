/*
实验说明：
	根据自己使用的LCD1602是否带有转接板，如果带有转接板的即为4位，需在LCD.H头文件中
	将宏#define LCD1602_4PINS打开，我们这里使用的LCD1602是8位，所以默认将该宏注释。
实验接线：
	1，LCD1602液晶模块-->单片机管脚
	参考LCD1602液晶显示实验接线（开发攻略内在对应的实验章节内实验现象有接线说明）
	2，独立按键模块-->单片机管脚 
	K1-->P34
	K2-->P35
	K3-->P32
	3，蜂鸣器模块-->单片机管脚
	BEEP-->P15
	4，LED模块-->单片机管脚
	D1-->P24
	5，LED模块-->单片机管脚
	D1-->P24
	6，继电器模块-->单片机管脚
	RELAY-->P14
	7，直流电机模块-->单片机管脚
	IN1-->P10（参考直流电机实验接线）
	8，EEPROM模块-->单片机管脚
	参考EEPROM实验接线
	9，DS18B20模块-->单片机管脚
	参考DS18B20温度传感器实验接线
	
实验现象：
	首先它能显示环境的温度并能设置上下限阀值，这是最基本的功能，系统上电的时候显示的是当前环境温度
	和设定的温度阀值，我们可以通过按键来修改温度上下限阀值。我们看，按下这个K1键会进入温度阀值设置
	界面，每按一下，切换一次阀值设置（上下阀值）界面，按第3次时，会自动回到主界面，如此循环。
	在进入温度阀值设计界面时，可以通过K2、K3键对阀值进行加减，这里我们只对温度整数部分进行设置，
	小数部分我们就不需要了，将设置好的上下限阀值保存到AT24C02（EEPROM）内，当下一次开启系统时只需
	从AT24C02内读取保存的阀值数据，而不需要重复设置上下限阀值。这样的话，我们用3个按键就实现了温度上下
	限阀值的设定，这是温度检测控制系统基本的功能。假如我们把温度上限设置为32°C，下限设置为30°C。
	另外还有恒定温度的功能。当设定好上下限阀值时，系统即会把当前的温度与设定的上下限阀值对比，
	如果高于上限温度，开启散热进行降温，同时报警；如果低于下限温度，开启加热，同时报警；
	如果当前温度处于下限和上限温度之间时，关闭散热、加热及报警。从而可将温度控制在阀值的范围内。
*/

#include "public.h"
#include "lcd.h"
#include "temp.h"
#include "i2c.h"


sbit k3=P3^2;	//设置温度上下限   
sbit k1=P3^4;	//加			   
sbit k2=P3^5;	//减			  

sbit led=P2^4; //报警指示灯

sbit beep=P1^5;	  //蜂鸣器报警
sbit relay=P1^4;  //加热设备
sbit moto=P1^0;   //电机散热


char set_templ=22,set_temph=40;  //设定温度上下限默认值
u16 temp_val;  //检测的实际温度
u8 mode;  //温度模式

void Temp_DataPros()
{
	short temp;
	u8 temp_buf[5];
	temp=Ds18b20ReadTemp();
	temp_val=temp;	
	if(temp<0)
	{
		temp=-temp;
		LCD_Dispstring(2+5,0,"-");
	}
	else
	{
		LCD_Dispstring(2+5,0," ");
	}

	temp_buf[0]=temp/100+0x30;
	temp_buf[1]=temp%100/10+0x30;
	temp_buf[2]='.';
	temp_buf[3]=temp%100%10+0x30;
	temp_buf[4]='\0';
	LCD_Dispstring(2+6,0,temp_buf);		 //显示检测的温度xx.x

	temp_buf[0]=set_temph/10+0x30;
   	temp_buf[1]=set_temph%10+0x30;
	temp_buf[2]='\0';
	LCD_Dispstring(5,1,temp_buf);	  //显示设定的温度上限值xx

	temp_buf[0]=set_templ/10+0x30;
   	temp_buf[1]=set_templ%10+0x30;
	temp_buf[2]='\0';
	LCD_Dispstring(14,1,temp_buf);	 //显示设定的温度下限值xx
}



#define  K1_MODE  1
#define  K2_ADD  2
#define  K3_DEC  3

//mode:  0-单次扫描   1-连续扫描
u8 KEY_Scan(u8 mode)
{
	static u8 key=1;
	if(key&&(k1==0||k2==0||k3==0))
	{
		delay(1000);   //消抖
		key=0;
		if(k3==0)
		{
			return K1_MODE;
		}
		else if(k1==0)
		{
			return K2_ADD;
		}
		else if(k2==0)
		{
			return K3_DEC;	
		}
	}
	else if(k1==1&&k2==1&&k3==1)
	{
		key=1;	
	}
	if(mode)
	{
		key=1;
	}
	return 0;	
}

void KEY_Pros()
{
	u8 key;
	u8 temph_buf[3];

	key=KEY_Scan(0);
	
	if(key==K1_MODE)   //模式选择
	{
		mode++;
		LCD_Clear();

		if(mode==1)
		{
			LCD_Dispstring(0,0,"SETH:   C");		
		}
		else if(mode==2)
		{
			LCD_Dispstring(0,1,"SETL:   C");	
		}
		else 
		{
			mode=0;
			LCD_Dispstring(2,0,"Temp:     C");
			LCD_Dispstring(0,1,"SETH:  ");
			LCD_Dispstring(9,1,"SETL:  ");	
		}
	}
	if(mode==1)	 //温度上限设置
	{
		switch(key)	
		{
			case K2_ADD: 	   //加
						set_temph++;
						if(set_temph>=80)set_temph=80;
						break;
			case K3_DEC: 	 //减
						set_temph--;
						if(set_temph<=0)set_temph=0;
						break;
		}

		temph_buf[0]=set_temph/10+0x30;
		temph_buf[1]=set_temph%10+0x30;
		temph_buf[2]='\0';
	   	LCD_Dispstring(6,0,temph_buf);
		At24c02Write(0,set_temph);
	}

	else if(mode==2)  //温度下限设置
	{
		switch(key)	
		{
			case K2_ADD: 	   //加
						set_templ++;
						if(set_templ>=80)set_templ=80;
						break;
			case K3_DEC: 	 //减
						set_templ--;
						if(set_templ<=0)set_templ=0;
						break;
		}

		temph_buf[0]=set_templ/10+0x30;
		temph_buf[1]=set_templ%10+0x30;
		temph_buf[2]='\0';
	   	LCD_Dispstring(6,1,temph_buf);
		At24c02Write(2,set_templ);
	}
	


}



void sound()
{
	u8 i=50;
	while(i--)
	{
		beep=!beep;
		delay(10);
	}
}
void TempData_Compare()
{
	if(temp_val>set_temph*10)	//实际温度高于上限值   报警  散热
	{
		led=1;
		moto=1;
		relay=1;
		sound();		
	}
	else if(temp_val<set_templ*10)	 //实际温度低于下限值   报警  加热
	{
		led=1;
		moto=0;
		relay=0;
		sound();		
	}
	else		      //实际温度在下限值和上限值之间   取消报警  取消加热  取消散热
	{
		moto=0;
		led=0;
		relay=1;
	}
}

void kai_display()
{
	if(At24c02Read(255)!=18)
	{
		At24c02Write(0,set_temph);
		At24c02Write(2,set_templ);
		At24c02Write(255,18);	
	}
	else
	{
		set_temph=At24c02Read(0);
		set_templ=At24c02Read(2);	
	}

	LCD_Dispstring(2,0,"Temp:     C");
	LCD_Dispstring(0,1,"SETH:  ");
	LCD_Dispstring(9,1,"SETL:  ");
}

void main()
{
	moto=0;
	led=0;
	relay=1;

	LCD_Init();
	kai_display();
	while(1)
	{
		if(mode==0)
			Temp_DataPros();
		KEY_Pros();	
		TempData_Compare();				
	}
}


