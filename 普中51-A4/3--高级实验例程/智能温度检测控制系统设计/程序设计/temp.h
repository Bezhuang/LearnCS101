#ifndef _temp_H_
#define _temp_H_

#include "public.h"

sbit DSPORT=P3^7;

void Delay1ms(unsigned int );
unsigned char Ds18b20Init();
void Ds18b20WriteByte(unsigned char com);
unsigned char Ds18b20ReadByte();
void  Ds18b20ChangTemp();
void  Ds18b20ReadTempCom();
short Ds18b20ReadTemp();

#endif
