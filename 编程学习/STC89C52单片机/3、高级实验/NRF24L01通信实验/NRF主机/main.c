/*******************************************************************************
ע�����
��NRF24L01�����Ӧ����

ʵ�������
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
#define TX_ADR_WIDTH   5  // 5���ֽڿ�ȵķ���/���յ�ַ	
#define TX_PLOAD_WIDTH 4  // ����ͨ����Ч���ݿ��
sbit LED = P2^1;
sbit KEY1 = P3^1;
sbit KEY2 = P3^2;

uchar code TX_ADDRESS[TX_ADR_WIDTH] = {0x34,0x43,0x10,0x10,0x01};  // ���徲̬���͵�ַ
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
*��������                              init_io
*�������ܣ�                            ��ʼ��IO
*���룺                                ��
*�����                                ��
/**************************************************/
void init_io(void)
{
    CE  = 0;        // �ر�ʹ��
    CSN = 1;        // SPI��ֹ
    SCK = 0;        // SPIʱ���õ�
    IRQ = 1;        // �жϸ�λ
    LED = 1;        // �ر�ָʾ��
}
/**************************************************/

/**************************************************
*��������                              delay_ms
*�������ܣ�                            ��ʱ����
*���룺                                ��
*�����                                ��
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
*��������                              SPI_RW
*�������ܣ�                            ��дһ���ֽ�
*���룺                                ��
*�����                                ��
/**************************************************/
uchar SPI_RW(uchar byte)
{
    uchar i;
       for(i=0; i<8; i++)          // ѭ��8��
       {
           MOSI = (byte & 0x80);   // byte���λ�����MOSI
           byte <<= 1;             // ��һλ��λ�����λ
           SCK = 1;                // ����SCK,nRF24L01��MOSI��ȡ1λ����,ͬʱ��MISO���1λ����
           byte |= MISO;           // ��MISO��byte���λ
           SCK = 0;                // SCK�õ�
       }
    return(byte);               // ���ض�ȡһ���ֽ�
}
/**************************************************/

/**************************************************
*��������                              SPI_RW_Reg
*�������ܣ�                            д���ݵ�reg
*���룺                                ��
*�����                                ��
/**************************************************/
uchar SPI_RW_Reg(uchar reg, uchar value)
{
    uchar status;
      CSN = 0;                   // CSN�õͣ���ʼ��������
      status = SPI_RW(reg);      // ѡ��Ĵ�����ͬʱ����״̬��
      SPI_RW(value);             // д���ݵ��Ĵ���
      CSN = 1;                   // CSN���ߣ��������ݴ���
      return(status);            // ����״̬�Ĵ���
}
/**************************************************/

/**************************************************
*��������                              SPI_Read
*�������ܣ�                            ��reg�Ĵ������ֽ�
*���룺                                ��
*�����                                ��
/**************************************************/
uchar SPI_Read(uchar reg)
{
    uchar reg_val;
      CSN = 0;                    // CSN�õ�,��ʼ��������
      SPI_RW(reg);                // ѡ��Ĵ���
      reg_val = SPI_RW(0);        // Ȼ��ӸüĴ���������
      CSN = 1;                    // CSN����,�������ݴ���
      return(reg_val);            // ���ؼĴ�������
}
/**************************************************/

/**************************************************
*��������                              SPI_Read_Buf
*�������ܣ�                            ��reg�Ĵ���������
*���룺                                ��
*�����                                ��
/**************************************************/
uchar SPI_Read_Buf(uchar reg, uchar * pBuf, uchar bytes)
{
    uchar status, i;
      CSN = 0;                    // CSN�õͣ���ʼ��������
      status = SPI_RW(reg);       // ѡ��Ĵ�����ͬʱ����״̬��
      for(i=0; i<bytes; i++)
        pBuf[i] = SPI_RW(0);    // ����ֽڴ�nRF24L01����
      CSN = 1;                    // CSN���ߣ��������ݴ���
      return(status);             // ����״̬�Ĵ���
}
/**************************************************/

/**************************************************
*��������                              SPI_Write_Buf
*�������ܣ�                            �ѻ��������д��NRF
*���룺                                ��
*�����                                ��
/**************************************************/
uchar SPI_Write_Buf(uchar reg, uchar * pBuf, uchar bytes)
{
    uchar status, i;
      CSN = 0;                    // CSN�õͣ���ʼ��������
      status = SPI_RW(reg);       // ѡ��Ĵ�����ͬʱ����״̬��
      for(i=0; i<bytes; i++)
        SPI_RW(pBuf[i]);        // ����ֽ�д��nRF24L01
      CSN = 1;                    // CSN����,�������ݴ���
      return(status);             // ����״̬�Ĵ���
}
/**************************************************/

/**************************************************
*��������                              RX_Mode
*�������ܣ�                            ��nrf����Ϊ����ģʽ
*���룺                                ��
*�����                                ��
/**************************************************/
void RX_Mode(void)
{
    CE = 0;
	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH);  // �����豸����ͨ��0ʹ�úͷ����豸��ͬ�ķ��͵�ַ
      SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);               // ʹ�ܽ���ͨ��0�Զ�Ӧ��
      SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);           // ʹ�ܽ���ͨ��0
      SPI_RW_Reg(WRITE_REG + RF_CH, 40);                 // ѡ����Ƶͨ��0x40
	SPI_RW_Reg(WRITE_REG + RX_PW_P0, TX_PLOAD_WIDTH);  // ����ͨ��0ѡ��ͷ���ͨ����ͬ��Ч���ݿ��
      SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);            // ���ݴ�����1Mbps,���书��0dBm,�������Ŵ�������
      SPI_RW_Reg(WRITE_REG + CONFIG, 0x0f);              // CRCʹ�ܣ�16λCRCУ�飬�ϵ磬����ģʽ
    delay_ms(150);
      CE = 1;                                            // ����CE���������豸
}
/**************************************************/

/**************************************************
*��������                              TX_Mode
*�������ܣ�                            ��nrf����Ϊ����ģʽ
*���룺                                ��
*�����                                ��
/**************************************************/
void TX_Mode(uchar * BUF)
{
    CE = 0;
	SPI_Write_Buf(WRITE_REG + TX_ADDR, TX_ADDRESS, TX_ADR_WIDTH);     // д�뷢�͵�ַ
	SPI_Write_Buf(WRITE_REG + RX_ADDR_P0, TX_ADDRESS, TX_ADR_WIDTH);  // Ӧ������豸������ͨ��0��ַ�ͷ��͵�ַ��ͬ
      SPI_Write_Buf(WR_TX_PLOAD, BUF, TX_PLOAD_WIDTH);                  // д���ݰ���TX FIFO
      SPI_RW_Reg(WRITE_REG + EN_AA, 0x01);       // ʹ�ܽ���ͨ��0�Զ�Ӧ��
      SPI_RW_Reg(WRITE_REG + EN_RXADDR, 0x01);   // ʹ�ܽ���ͨ��0
      SPI_RW_Reg(WRITE_REG + SETUP_RETR, 0x0a);  // �Զ��ط���ʱ�ȴ�250us+86us���Զ��ط�
      SPI_RW_Reg(WRITE_REG + RF_CH, 40);         // ѡ����Ƶͨ��0x40
      SPI_RW_Reg(WRITE_REG + RF_SETUP, 0x07);    // ���ݴ�����1Mbps�����书��0dBm���������Ŵ�������
      SPI_RW_Reg(WRITE_REG + CONFIG, 0x0e);      // CRCʹ�ܣ�16λCRCУ�飬�ϵ�
    delay_ms(150);
    CE = 1;
}
/**************************************************/

/**************************************************
*��������                              Check_ACK
*�������ܣ�                            �������豸�������ݰ����趨û��Ӧ���ź��ط�
*���룺                                ��
*�����                                ��
/**************************************************/
uchar Check_ACK(bit clear)
{
    delay_ms(200);
    while(IRQ);
    sta = SPI_RW(NOP);                    // ����״̬�Ĵ���
    if(TX_DS)
    {
        blink(3);
    }
    //blink(5);
    if(MAX_RT)
        if(clear)                         // �Ƿ����TX FIFO��û������ڸ�λMAX_RT�жϱ�־���ط�
            SPI_RW(FLUSH_TX);
    SPI_RW_Reg(WRITE_REG + STATUS, sta);  // ���TX_DS��MAX_RT�жϱ�־
    IRQ = 1;
    if(TX_DS)
        return(0x00);
    else
        return(0xff);
}
/**************************************************/

/**************************************************
*��������                              CheckButtons
*�������ܣ�                            ��鰴���Ƿ��£����·���һ�ֽ�����
*���룺                                ��
*�����                                ��
/**************************************************/
void CheckButtons()
{
    if(KEY1 == 0)
    {
        delay_ms(20);
        if(KEY1 == 0)
        {
					TX_BUF[0] = 1;          // �����͵�����
					//TX_BUF[0] = 0xff;          // �����͵�����
					TX_Mode(TX_BUF);            // ��nrf����Ϊ����ģʽ����������           
					//LED = ~DATA;                // �����͵�LED��ʾ
					Check_ACK(0);               // �ȴ�������ϣ����TX FIFO
            delay_ms(250);
            delay_ms(250);
        }
    }

    if(KEY2 == 0)
    {
        delay_ms(20);
        if(KEY2 == 0)
        {
					TX_BUF[0] = 2;          // �����͵�����
					//TX_BUF[0] = 0xff;          // �����͵�����
					TX_Mode(TX_BUF);            // ��nrf����Ϊ����ģʽ����������           
					//LED = ~DATA;                // �����͵�LED��ʾ
					Check_ACK(0);               // �ȴ�������ϣ����TX FIFO
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
*��������                              main
*�������ܣ�                            ������
*���룺                                ��
*�����                                ��
/**************************************************/
void main(void)
{
    init_io();                      // ��ʼ��IO

    while(1)
    {
        CheckButtons();           // ����ɨ��
    }
}