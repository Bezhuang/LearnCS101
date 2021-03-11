#include "zlmoto.h"
#include "key.h"


void ZLMOTO_Test(void)
{
	u8 key=0;
	u8 mode=0;
	EA=0;
	KEY_PORT=0xff;
	while(1)
	{
		key=KeyScan(0);
		
		if(key==KEY1)
		{
			mode++;
			if(mode==2)mode=0;
		}
		if(mode==0)	  //Í£Ö¹
		{
			motoa=0;
			
		}
		else if(mode==1)  //¿ªÆô
		{
			motoa=1;		
		}
		if(KeyValue!=ZLMOTO_TEST)
		{
			motoa=0;
			return;	
		}	
	}
}