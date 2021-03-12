#include "public.h"  
#include "uart.h"
#include "tftlcd.h"
#include "touch.h"
#include "gui.h"



//×Ö·ûÊý×ÖÏÔÊ¾²âÊÔ
void CharacterShow_Test(void)
{
	FRONT_COLOR=RED;
	LCD_ShowString(10,10,tftlcd_data.width,tftlcd_data.height,12,"Hello World!");
	LCD_ShowString(10,30,tftlcd_data.width,tftlcd_data.height,16,"Hello World!");
	LCD_ShowString(10,50,tftlcd_data.width,tftlcd_data.height,24,"Hello World!");
	FRONT_COLOR=WHITE;
	LCD_ShowString(10,80,tftlcd_data.width,tftlcd_data.height,12,"1234567890");
	LCD_ShowString(10,100,tftlcd_data.width,tftlcd_data.height,16,"1234567890");
	LCD_ShowString(10,120,tftlcd_data.width,tftlcd_data.height,24,"1234567890");
		
}

void main()
{

	UART_Init();
	TFTLCD_Init();

	CharacterShow_Test();
	
	while(1)
	{
				
	}					
}
