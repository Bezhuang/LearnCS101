#include "public.h"  
#include "uart.h"
#include "tftlcd.h"
#include "gui.h"
#include "touch.h"
//#include "picture.h"



void main()
{

	UART_Init();
	TFTLCD_Init();
		
	FRONT_COLOR=WHITE;
	LCD_ShowFontHZ(tftlcd_data.width/2-2*24-12, 10,"Bezhuang");
	LCD_ShowString(tftlcd_data.width/2-7*12,40,tftlcd_data.width,tftlcd_data.height,24,"2021-03-12  22Yo");
	//LCD_ShowPicture(10,60,56,56,gImage_picture);


		
	while(1)
	{
		
	}					
}
