#include <stdio.h>
#include "NUC230_240.h"

#define START_BYTE				0x08
#define REPEAT_START_BYTE		0x10
#define MSTR_TX_ADD_ACK			0x18
#define MSTR_TX_DATA_ACK		0x28
#define MSTR_RX_ADD_ACK			0x40
#define MSTR_RX_ADD_NACK		0x58

#define BMP180_WR_ADD			0xEE
#define BMP180_RD_ADD			0xEF
#define ID_REG					0xD0 //Default : 0x55
#define MSB_REG					0xF6 //Default : 0x80
#define LSB_REG					0xF7 //Default : 0x00
#define XLSB_REG				0xF8 //Default : 0x00


void SYS_Init(void)
{
    CLK->APBCLK = CLK_APBCLK_UART0_EN_Msk;
    CLK->APBCLK |= CLK_APBCLK_I2C0_EN_Msk;
    SystemCoreClockUpdate();

    SYS->GPB_MFP &= ~(SYS_GPB_MFP_PB0_Msk | SYS_GPB_MFP_PB1_Msk);
    SYS->GPB_MFP |= SYS_GPB_MFP_PB0_UART0_RXD | SYS_GPB_MFP_PB1_UART0_TXD;

    SYS->GPA_MFP &= ~(SYS_GPA_MFP_PA8_Msk | SYS_GPA_MFP_PA9_Msk);
    SYS->GPA_MFP |= SYS_GPA_MFP_PA8_I2C0_SDA | SYS_GPA_MFP_PA9_I2C0_SCL;
}

int main()
{
    uint8_t MstRxData;
    SYS_UnlockReg();
    SYS_Init();
    SYS_LockReg();

    UART_Open(UART0, 115200);
    I2C0->I2CLK = 0x36;
    I2C0->I2CON |= I2C_I2CON_ENS1_Msk;
    printf("CPU clock %d Hz\n",CLK_GetCPUFreq());
    printf("I2C clock %d Hz\n", I2C_GetBusClockFreq(I2C0));

// SEND MODULE ADD AND DEVICE ADD
    I2C_SET_CONTROL_REG(I2C0, I2C_I2CON_STA);
    while(I2C_GET_STATUS(I2C0) != 0x08);printf("1\n");
    I2C_SET_DATA(I2C0, 0xEE);
    I2C_SET_CONTROL_REG(I2C0, I2C_I2CON_SI);

    while(I2C_GET_STATUS(I2C0) != 0x18);printf("2\n");
    I2C_SET_DATA(I2C0, ID_REG);
    I2C_SET_CONTROL_REG(I2C0, I2C_I2CON_SI);

    while(I2C_GET_STATUS(I2C0) != 0x28);printf("3\n");

    I2C_SET_CONTROL_REG(I2C0, I2C_I2CON_STA_SI);
    while(I2C_GET_STATUS(I2C0) != 0x10){
    	printf("4\n");
    }
    I2C_SET_DATA(I2C0, 0xEF);
    I2C_SET_CONTROL_REG(I2C0, I2C_I2CON_SI);

    while(I2C_GET_STATUS(I2C0) != 0x40);printf("5\n");
    MstRxData = (unsigned char) I2C_GET_DATA(I2C0);
    I2C_SET_CONTROL_REG(I2C0, I2C_I2CON_SI);

    while(I2C_GET_STATUS(I2C0) != 0x58);printf("6\n");
    MstRxData = (unsigned char) I2C_GET_DATA(I2C0);
    printf("device ID = %d \n",MstRxData);
    I2C_SET_CONTROL_REG(I2C0, I2C_I2CON_STO_SI);

    while(1);
}
