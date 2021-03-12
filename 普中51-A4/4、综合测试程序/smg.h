#ifndef _smg_H
#define	_smg_H

#include "public.h"

#define SMG_PORT	P0
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

void SMG_Test(void);
void DigDisplay(void);

#endif