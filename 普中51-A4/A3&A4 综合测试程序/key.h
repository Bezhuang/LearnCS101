#ifndef _key_H
#define	_key_H

#include "public.h"

#define KEY_PORT	P1


sbit k1=P3^1;
sbit k2=P3^0;
sbit k3=P3^2;
sbit k4=P3^3;	 //定义按键端口


#define KEY1 100
#define KEY2 101
#define KEY3 102
#define KEY4 103

u8 KeyScan(u8 mode);
void KEY_Scan(void);

#endif
