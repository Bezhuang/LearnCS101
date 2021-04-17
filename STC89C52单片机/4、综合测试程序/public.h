#ifndef _public_H
#define	_public_H

#include "reg51.h"
#include "intrins.h"

typedef unsigned int u16;	  //对数据类型进行声明定义
typedef unsigned char u8;

extern u8 KeyValue;
extern u8 DisPlayData[8];
extern u8 smgduan[17];


#define LED_TEST		1
#define BEEP_TEST		2
#define SMG_TEST		3
#define DS18B20_TEST	4
#define LEDDZ_TEST		5
#define DS1302_TEST		6
#define ADC_TEST		7
#define DAC_TEST		8
#define HWJS_TEST		9
#define BJMOTO_TEST		10
#define EEPROM_TEST		11
#define LCD1602_TEST	12

#define ZLMOTO_TEST		16



void delay(u16 i);

#endif
