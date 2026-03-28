#ifndef IIC_REG_H
#define IIC_REG_H

#include <stdint.h>

/* ------------------ Base Address ------------------ */
#define IIC1_BASE_ADDR   (0x40005400UL)

/* ------------------ Register Structure ------------ */
typedef struct
{
    volatile uint32_t CR;     /* Control Register */
    volatile uint32_t SR;     /* Status Register */
    volatile uint32_t DR;     /* Data Register */
    volatile uint32_t CCR;    /* Clock Control */
    volatile uint32_t AR;     /* Address Register */
} IIC_Reg_t;

/* ------------------ IIC Instance ------------------ */
#define IIC1   ((IIC_Reg_t *)IIC1_BASE_ADDR)


/* IIC Control Register (CR) bits */
#define IIC_CR_PE        (1U << 0)   /* Peripheral Enable */
#define IIC_CR_START     (1U << 8)   /* Start Condition */
#define IIC_CR_STOP      (1U << 9)   /* Stop Condition */
#define IIC_CR_ACK       (1U << 10)  /* Acknowledge Enable */

/* IIC Status Register (SR) bits */
#define IIC_SR_TXE       (1U << 7)   /* Transmit buffer empty */
#define IIC_SR_RXNE      (1U << 6)   /* Receive buffer not empty */
#define IIC_SR_BUSY      (1U << 1)   /* Bus busy */
#define IIC_SR_SB        (1U << 0)   /* Start bit sent */

/* Address Register */
#define IIC_AR_7BIT_ADDR_MASK   (0x7FU << 1)
#endif /* IIC_REG_H */
