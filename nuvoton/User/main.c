#include <stdio.h>
#include "NUC230_240.h"

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
    int8_t ch;
    SYS_UnlockReg();
    SYS_Init();
    SYS_LockReg();

    UART_Open(UART0, 115200);
    I2C0->I2CLK = 0x36;
    I2C0->I2CON |= I2C_I2CON_ENS1_Msk;
    printf("CPU clock %d Hz\n",CLK_GetCPUFreq());
    printf("I2C clock %d Hz\n", I2C_GetBusClockFreq(I2C0));
    I2C_SET_CONTROL_REG(I2C0, I2C_I2CON_SI_AA);

    printf("Please Input Any Key\n\n");
    do {
        printf("Input: ");
        ch = getchar();
        printf("%c\n", ch);
    } while(1);
}
