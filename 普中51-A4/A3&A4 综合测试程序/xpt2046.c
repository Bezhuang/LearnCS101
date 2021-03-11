#include "xpt2046.h"
#include "smg.h"

/****************************************************************************
*函数名：SPI_Write
*输  入：dat：写入数据
*输  出：无
*功  能：使用SPI写入数据
****************************************************************************/

void SPI_Write(uchar dat)
{
	uchar i;
	CLK = 0;
	for(i=0; i<8; i++)
	{
		DIN = dat >> 7;  	//放置最高位
		dat <<= 1;
		CLK = 0;			//上升沿放置数据

		CLK = 1;

	}
}
/****************************************************************************
*函数名：SPI_Read
*输  入：无
*输  出：dat：读取 到的数据
*功  能：使用SPI读取数据
****************************************************************************/

uint SPI_Read(void)
{
	uint i, dat=0;
	CLK = 0;
	for(i=0; i<12; i++)		//接收12位数据
	{
		dat <<= 1;

		CLK = 1;
		CLK = 0;

		dat |= DOUT;

	}
	return dat;	
}

/****************************************************************************
*函数名：Read_AD_Data
*输  入：cmd：读取的通道数据
*输  出：AD_Value：最终信号处理后返回的值
*功  能：读取通道采集的数据
****************************************************************************/
uint Read_AD_Data(uchar cmd)
{
	uchar i;
	uint AD_Value;
	CLK = 0;
	CS  = 0;
	SPI_Write(cmd);
	for(i=6; i>0; i--); 	//延时等待转换结果
	CLK = 1;	  //发送一个时钟周期，清除BUSY
	_nop_();
	_nop_();
	CLK = 0;
	_nop_();
	_nop_();
	AD_Value=SPI_Read();
	CS = 1;
	return AD_Value;	
}




void ADCdatapros()
{
	u16 temp;
	static u8 i;
	if(i==50)
	{
		i=0;
		temp = Read_AD_Data(0x94);		//   AIN0 电位器
	}
	i++;
	DisPlayData[0]=smgduan[temp/1000];//千位
	DisPlayData[1]=smgduan[temp%1000/100];//百位
	DisPlayData[2]=smgduan[temp%1000%100/10];//个位
	DisPlayData[3]=smgduan[temp%1000%100%10];
	DisPlayData[4]=0;
	DisPlayData[5]=0;
	DisPlayData[6]=0;
	DisPlayData[7]=0;		
}

void ADC_Test(void)
{
	
	while(1)
	{
		ADCdatapros();	 //数据处理函数
		DigDisplay();//数码管显示函数
		if(KeyValue!=ADC_TEST)
		{
			return;	
		}
	}
}