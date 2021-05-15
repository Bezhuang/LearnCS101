/*******************************************************************************
注意事项：
将NRF24L01插入对应插座

实验操作：
P2^1 --- J19 D1
P3^1 --- JP1 K1
P3^2 --- JP1 K2
CE   --- P1^2;
CSN  --- P1^3;
SCK  --- P1^7;
MOSI --- P1^1;
MISO --- P1^6;
IRQ  --- P1^4;
*******************************************************************************/
#include <reg52.h>

#define uchar unsigned char

/***************************************************/
#define TX_ADR_WIDTH   5  // 5个字节宽度的发送/接收地址	
#define TX_PLOAD_WIDTH 4  // 数据通道有效数据宽度
sbit LED = P2^1;
sbit KEY1 = P3^1;
sbit KEY2 = P3^2;

uchar code TX_ADDRESS[TX_ADR_WIDTH] = {0x34,0x43,0x10,0x10,0x01};  // 定义静态发送地址
uchar RX_BUF[TX_PLOAD_WIDTH];
uchar TX_BUF[TX_PLOAD_WIDTH];
uchar flag;
uchar DATA = 0x01;
uchar bdata sta;
sbit  RX_DR     = sta^6;
sbit  TX_DS     = sta^5;
sbit  MAX_RT = sta^4;

sbit CE =  P1^2;
sbit CSN=  P1^3;
sbit SCK=  P1^7;
sbit MOSI= P1^1;
sbit MISO= P1^6;
sbit IRQ = P1^4;

// SPI(nRF24L01) commands
#define READ_REG    0x00  // Define read command to register
#define WRITE_REG   0x20  // Define write command to register
#define RD_RX_PLOAD 0x61  // Define RX payload register address
#define WR_TX_PLOAD 0xA0  // Define TX payload register address
#define FLUSH_TX    0xE1  // Define flush TX register command
#define FLUSH_RX    0xE2  // Define flush RX register command
#define REUSE_TX_PL 0xE3  // Define reuse TX payload register command
#define NOP         0xFF  // Define No Operation, might be used to read status register

// SPI(nRF24L01) registers(addresses)
#define CONFIG      0x00  // 'Config' register address
#define EN_AA       0x01  // 'Enable Auto Acknowledgment' register address
#define EN_RXADDR   0x02  // 'Enabled RX addresses' register address
#define SETUP_AW    0x03  // 'Setup address width' register address
#define SETUP_RETR  0x04  // 'Setup Auto. Retrans' register address
#define RF_CH       0x05  // 'RF channel' register address
#define RF_SETUP    0x06  // 'RF setup' register address
#define STATUS      0x07  // 'Status' register address
#define OBSERVE_TX  0x08  // 'Observe TX' register address
#define CD          0x09  // 'Carrier Detect' register address
#define RX_ADDR_P0  0x0A  // 'RX address pipe0' register address
#define RX_ADDR_P1  0x0B  // 'RX address pipe1' register address
#define RX_ADDR_P2  0x0C  // 'RX address pipe2' register address
#define RX_ADDR_P3  0x0D  // 'RX address pipe3' register address
#define RX_ADDR_P4  0x0E  // 'RX address pipe4' register address
#define RX_ADDR_P5  0x0F  // 'RX address pipe5' register address
#define TX_ADDR     0x10  // 'TX address' register address
#define RX_PW_P0    0x11  // 'RX payload width, pipe0' register address
#define RX_PW_P1    0x12  // 'RX payload width, pipe1' register address
#define RX_PW_P2    0x13  // 'RX payload width, pipe2' register address
#define RX_PW_P3    0x14  // 'RX payload width, pipe3' register address
#define RX_PW_P4    0x15  // 'RX payload width, pipe4' register address
#define RX_PW_P5    0x16  // 'RX payload width, pipe5' register address
#define FIFO_STATUS 0x17  // 'FIFO Status Register' register address

void blink(char i);

/**************************************************
*函数名：                              init_io
*函数功能：                            初始化IO
*输入：                                无
*输出：                                无
/**************************************************/
void init_io(void)
{
    CE  = 0;        // 关闭使能
    CSN = 1;        // SPI禁止
    SCK = 0;        // SPI时钟置低
    IRQ = 1;        // 中断复位
    LED = 1;        // 关闭指示灯
}
/**************************************************/

/**************************************************
*函数名：                              delay_ms
*函数功能：                            延时函数
*输入：                                无
*输出：                                无
/**************************************************/
void delay_ms(uchar x)
{
    uchar i, j;
    i = 0;
    for(i=0; i<x; i++)
    {
       j = 250;
       while(--j);
       j = 250;
       while(--j);
    }
}
/**************************************************/

/**************************************************
*函数名：                              SPI_RW
*函数功能：                            读写一个字节
*输入：                                无
*输出：                                无
/**************************************************/
uchar SPI_RW(uchar byte)
{
    uchar i;
       for(i=0; i<8; i++)          // 循环8次
       {
           MOSI = (byte & 0x80);   // byte最高位输出到MOSI
           byte <<= 1;             // 低一位移位到最高位
           SCK = 1;                // 拉高SCK,nRF24L01从MOSI读取1位数据,同时从MISO输出1位数据
           byte |= MISO;           // 读MISO到byte最低位
           SCK = 0;                // SCK置低
       }
    return(byte);               // 返回读取一个字节
}
/**************************************************/

/**************************************************
*函数名：                              SPI_RW_Reg
*函数功能：                            写数据到reg
*输入：                                无
*输出：                                无
/**************************************************/
uchar SPI_RW_Reg(uchar reg, uchar value)
{
    uchar status;
      CSN = 0;                   // CSN置低，开始传输数据
      status = SPI_RW(reg);      // 选择寄存器，同时返回状态字
      SPI_RW(value);             // 写数据到寄存器
      CSN = 1;                   // CSN拉高，结束数据传输
      return(status);            // 返回状态寄存器
}
/**************************************************/

/**************************************************
*函数名：                              SPI_Read
*函数功能：                            从reg寄存器读字节
*输入：                                无
*输出：                                无
/**************************************************/
uchar SPI_Read(uchar reg)
{
    uchar reg_val;
      CSN = 0;                    // CSN置低,开始传输数据
      SPI_RW(reg);                // 选择寄存器
      reg_val = SPI_RW(0);        // 然后从该寄存器读数据
      CSN = 1;                    // CSN拉高,结束数据传输
      return(reg_val);            // 返回寄存器数据
}
/**************************************************/

/**************************************************
*函数名：                              SPI_Read_Buf
*函数功能：                            从reg寄存器读数据
*输入：                                无
*输出：                                无
/**************************************************/
uchar SPI_Read_Buf(uchar reg, uchar * pBuf, uchar bytes)
{
    uchar status, i;
      CSN = 0;                    // CSN置低，开始传输数据
      status = SPI_RW(reg);       // 选择寄存器，同时返回状态字
      for(i=0; i<bytes; i++)
        pBuf[i] = SPI_RW(0);    // 逐个字节从nRF24L01读出
      CSN = 1;                    // CSN拉高，结束数据传输
      return(status);             // 返回状态寄存器
}
/**************************************************/

/**************************************************
*函数名：                              SPI_Write_Buf
*函数功能：                            把缓存的数据写入NRF
*输入：                                无
*输出：                                无
/**************************************************/
uchar SPI_Write_Buf(uchar reg, uchar * pBuf, uchar bytes)
{
    uchar status, i;
      CSN = 0;                    // CSN置低，开始传输数据
      status = SPI_RW(reg);       // 选择寄存器，同时返回状态字
      for(i=0; i<bytes; i++)
        SPI_RW(pBuf[i]);        // 逐个字节写入nRF24L01
      CSN = 1;                    // CSN拉高,结束数据传输
      return(status);             // 返回状态寄存器
}
/**************************************************/

/**************************************************
*函数名：                              RX_Mode
*函数功能：                            将nrf设置为接收模式
*输入：                                无
*输出：                                无
/**************************************************/
void RX_Mode(void)
{
    CE = 0;
	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH);  // 接收设备接收通道0使用和发送设备相同的发送地址
      SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);               // 使能接收通道0自动应答
      SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);           // 使能接收通道0
      SPI_RW_Reg(WRITE_REG + RF_CH, 40);                 // 选择射频通道0x40
	SPI_RW_Reg(WRITE_REG + RX_PW_P0, TX_PLOAD_WIDTH);  // 接收通道0选择和发送通道相同有效数据宽度
      SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);            // 数据传输率1Mbps,发射功率0dBm,低噪声放大器增益
      SPI_RW_Reg(WRITE_REG + CONFIG, 0x0f);              // CRC使能，16位CRC校验，上电，接收模式
    delay_ms(150);
      CE = 1;                                            // 拉高CE启动接收设备
}
/**************************************************/

/**************************************************
*函数名：                              TX_Mode
*函数功能：                            将nrf设置为发送模式
*输入：                                无
*输出：                                无
/**************************************************/
void TX_Mode(uchar * BUF)
{
    CE = 0;
	SPI_Write_Buf(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);     // 写入发送地址
	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH);  // 应答接收设备，接收通道0地址和发送地址相同
      SPI_Write_Buf(WR_TX_PLOAD, BUF, TX_PLOAD_WIDTH);                  // 写数据包到TX FIFO
      SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);       // 使能接收通道0自动应答
      SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);   // 使能接收通道0
      SPI_RW_Reg(WRITE_REG + SETUP_RETR, 0x0a);  // 自动重发延时等待250us+86us，自动重发
      SPI_RW_Reg(WRITE_REG + RF_CH, 40);         // 选择射频通道0x40
      SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);    // 数据传输率1Mbps，发射功率0dBm，低噪声放大器增益
      SPI_RW_Reg(WRITE_REG + CONFIG, 0x0e);      // CRC使能，16位CRC校验，上电
    delay_ms(150);
    CE = 1;
}
/**************************************************/

/**************************************************
*函数名：                              Check_ACK
*函数功能：                            检查接收设备有无数据包，设定没有应答信号重发
*输入：                                无
*输出：                                无
/**************************************************/
uchar Check_ACK(bit clear)
{
    delay_ms(200);
    while(IRQ);
    sta = SPI_RW(NOP);                    // 返回状态寄存器
    if(TX_DS)
    {
        blink(3);
    }
    //blink(5);
    if(MAX_RT)
        if(clear)                         // 是否清除TX FIFO，没有清除在复位MAX_RT中断标志后重发
            SPI_RW(FLUSH_TX);
    SPI_RW_Reg(WRITE_REG + STATUS, sta);  // 清除TX_DS或MAX_RT中断标志
    IRQ = 1;
    if(TX_DS)
        return(0x00);
    else
        return(0xff);
}
/**************************************************/

/**************************************************
*函数名：                              CheckButtons
*函数功能：                            检查按键是否按下，按下发送一字节数据
*输入：                                无
*输出：                                无
/**************************************************/
void CheckButtons()
{
    if(KEY1 == 0)
    {
        delay_ms(20);
        if(KEY1 == 0)
        {
					TX_BUF[0] = 1;          // 数据送到缓存
					//TX_BUF[0] = 0xff;          // 数据送到缓存
					TX_Mode(TX_BUF);            // 将nrf设置为发送模式并发送数据           
					//LED = ~DATA;                // 数据送到LED显示
					Check_ACK(0);               // 等待发送完毕，清除TX FIFO
            delay_ms(250);
            delay_ms(250);
        }
    }

    if(KEY2 == 0)
    {
        delay_ms(20);
        if(KEY2 == 0)
        {
					TX_BUF[0] = 2;          // 数据送到缓存
					//TX_BUF[0] = 0xff;          // 数据送到缓存
					TX_Mode(TX_BUF);            // 把nrf设置为发送模式并发送数据           
					//LED = ~DATA;                // 数据送到LED显示
					Check_ACK(0);               // 等待发送完毕，清除TX FIFO
            delay_ms(250);
            delay_ms(250);
        }
    }


}
/**************************************************/

void blink(char i)
{
    while(i--)
    {
        LED = 1;
        delay_ms(500);
        LED = 0;
        delay_ms(500);
    }

}

/**************************************************
*函数名：                              main
*函数功能：                            主函数
*输入：                                无
*输出：                                无
/**************************************************/
void main(void)
{
    init_io();                      // 初始化IO

    while(1)
    {
        CheckButtons();           // 按键扫描
    }
}