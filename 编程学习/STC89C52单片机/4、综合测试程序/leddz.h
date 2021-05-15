#ifndef _leddz_H
#define	_leddz_H

#include "public.h"

#define LEDDZ_PORT	P0
sbit SRCLK=P3^6;
sbit RCLK=P3^5;
sbit SER=P3^4;

void LEDDZ_Test(void);


#endif