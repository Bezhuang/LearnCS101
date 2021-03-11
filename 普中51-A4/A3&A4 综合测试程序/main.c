/**  
测试方法：
矩阵键盘的键值分布如下：
1			2			3			4
5			6			7			8
9		   10		   11		   12
13		   14		   15		   16
按键1：LED测试，实验效果是一盏点亮的LED循环右移。
按键2：蜂鸣器测试，实验效果是蜂鸣器一直响。
按键3：数码管测试，实验效果是数码管显示0-7数字。
按键4：DS18B20测试，实验效果是数码管显示温度。
按键5：LED点阵测试，首先将点阵模块上的J24端子短接到GND侧（OE与GND短接），实验效果是逐行显示
按键6：DS1302测试，实验效果是数码管上显示时钟。
按键7：ADC测试，实验效果是数码管显示电位器AD值。
按键8: DAC测试，实验效果是DA1指示灯呈呼吸灯效果
按键9：红外遥控测试，实验效果是数码管上显示红外遥控器的键码值
按键10：步进电机测试，连接好步进电机，实验效果是步进电机转动
按键11：EEPROM测试，实验效果是，K1键为写，K2为清零，K3为读，K4为数字加1，将数据写入到EEPROM内，按下K3后数码管可显示读取的数据。测试完成后需复位下系统！
按键12：LCD1602测试，插上LCD1602液晶，可显示字符等信息
其他按键值：可扩展其他功能
注意！！
1、如果LCD1602没有显示，调整LCD接口下的电位器，隐约看到LCD1602有一格格显示的时候就可以显示了。


*/

#include "public.h"
#include "key.h"
#include "led.h"
#include "time.h"
#include "beep.h"
#include "smg.h"
#include "leddz.h"
#include "zlmoto.h"
#include "bjmoto.h"
#include "eeprom.h"
#include "ds18b20.h"
#include "ds1302.h"
#include "xpt2046.h"
#include "dac.h"
#include "hwjs.h"
#include "lcd1602.h"


void main()
{
	Timer0Init();
	
	while(1)
	{
		switch(KeyValue)
		{
			case LED_TEST: LED_Test();break;		//LED测试
			case BEEP_TEST: BEEP_Test();break;		//蜂鸣器测试
			case SMG_TEST: SMG_Test();break;		//数码管测试
			case DS18B20_TEST: DS18B20_Test();break;	//DS18B20测试
			case LEDDZ_TEST: LEDDZ_Test();break;		//LED点阵测试
			case DS1302_TEST: DS1302_Test();break;		//DS1302测试
			case ADC_TEST: ADC_Test();break;		//ADC测试
			case DAC_TEST: DAC_Test();break;		//DAC测试
			case HWJS_TEST: HWJS_Test();break;		//红外遥控测试
			case BJMOTO_TEST: BJMOTO_Test();break;	//步进电机测试
			case EEPROM_TEST: EEPROM_Test();break;	//EEPROM测试
			case LCD1602_TEST: LCD1602_Test();break;	//LCD1602测试
			case ZLMOTO_TEST: ZLMOTO_Test();break;	//直流电机测试			
			
		}
		
		
	}		
}
