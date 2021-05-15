#ifndef _lcd_H
#define _lcd_H

#include "public.h"


/**********************************
当使用的是4位数据传输的时候定义，
使用8位取消这个定义
**********************************/
#define LCD1602_4PINS


//---重定义关键词---//
#ifndef uchar
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

/**********************************
PIN口定义
**********************************/
#define LCD1602_DATAPINS P0
sbit LCD1602_E=P2^7;
sbit LCD1602_RW=P2^5;
sbit LCD1602_RS=P2^6;



void LCD_WriteCmd(u8 cmd);
void LCD_WriteData(u8 dat);
void LcdInit();
void LCD_Clear();
void LCD_Dispstring(u8 x,u8 line,u8 *p);




#endif