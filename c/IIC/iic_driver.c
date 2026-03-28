#include<stdio.h>
#include "iic_reg.h"
#define IIC_CR_PE        (1U << 0)   /* Peripheral Enable */

void IIC_Init(void)
{
    /* Enable IIC */
    IIC1->CR |= IIC_CR_PE;

    /* Set clock */
    IIC1->CCR = 0x28;

    /* Set own address */
    IIC1->AR = (0x52 << 1);
}