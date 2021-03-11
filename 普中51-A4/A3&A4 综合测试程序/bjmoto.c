#include "bjmoto.h"


void BJMOTO_Test(void)
{
	
	while(1)
	{
		MOTOA = 1;
		MOTOB = 0;
		MOTOC = 1;
		MOTOD = 1;
		delay(SPEED);

		MOTOA = 1;
		MOTOB = 1;
		MOTOC = 1;
		MOTOD = 0;
		delay(SPEED);

		MOTOA = 0;
		MOTOB = 1;
		MOTOC = 1;
		MOTOD = 1;
		delay(SPEED);

		MOTOA = 1;
		MOTOB = 1;
		MOTOC = 0;
		MOTOD = 1;
		delay(SPEED);

		if(KeyValue!=BJMOTO_TEST)
		{
			return;	
		}	
	}
}

