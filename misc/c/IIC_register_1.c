/**
 * @file i2c_regs.h
 * @brief Low-level I²C register definitions for ARM Cortex-M4 style MCUs
 * (e.g., STM32F4 / NXP / TI — CMSIS-style layout)
 */

#ifndef I2C_REGS_H
#define I2C_REGS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* --------------------------------------------------------------------------
 *  Base addresses (example for STM32-like Cortex-M4)
 * -------------------------------------------------------------------------- */
#define PERIPH_BASE         0x40000000UL
#define APB1PERIPH_BASE     (PERIPH_BASE + 0x00000UL)

#define I2C1_BASE           (APB1PERIPH_BASE + 0x5400UL)
#define I2C2_BASE           (APB1PERIPH_BASE + 0x5800UL)
#define I2C3_BASE           (APB1PERIPH_BASE + 0x5C00UL)

/* --------------------------------------------------------------------------
 *  I2C Register Map (Cortex-M4 style)
 * -------------------------------------------------------------------------- */
typedef struct
{
    volatile uint32_t CR1;      /*!< Control register 1,     offset: 0x00 */
    volatile uint32_t CR2;      /*!< Control register 2,     offset: 0x04 */
    volatile uint32_t OAR1;     /*!< Own address register 1, offset: 0x08 */
    volatile uint32_t OAR2;     /*!< Own address register 2, offset: 0x0C */
    volatile uint32_t DR;       /*!< Data register,          offset: 0x10 */
    volatile uint32_t SR1;      /*!< Status register 1,      offset: 0x14 */
    volatile uint32_t SR2;      /*!< Status register 2,      offset: 0x18 */
    volatile uint32_t CCR;      /*!< Clock control register, offset: 0x1C */
    volatile uint32_t TRISE;    /*!< TRISE register,         offset: 0x20 */
} I2C_TypeDef;

/* --------------------------------------------------------------------------
 *  Peripheral instances
 * -------------------------------------------------------------------------- */
#define I2C1    ((I2C_TypeDef *) I2C1_BASE)
#define I2C2    ((I2C_TypeDef *) I2C2_BASE)
#define I2C3    ((I2C_TypeDef *) I2C3_BASE)

/* --------------------------------------------------------------------------
 *  Bit definitions (based on typical STM32-like controller)
 * -------------------------------------------------------------------------- */
/* CR1 */
#define I2C_CR1_PE             (1U << 0)   /*!< Peripheral enable */
#define I2C_CR1_START          (1U << 8)   /*!< Start generation */
#define I2C_CR1_STOP           (1U << 9)   /*!< Stop generation */
#define I2C_CR1_ACK            (1U << 10)  /*!< Acknowledge enable */
#define I2C_CR1_SWRST          (1U << 15)  /*!< Software reset */

/* CR2 */
#define I2C_CR2_FREQ_Pos       0
#define I2C_CR2_FREQ_Msk       (0x3FU << I2C_CR2_FREQ_Pos)
#define I2C_CR2_ITERREN        (1U << 8)
#define I2C_CR2_ITEVTEN        (1U << 9)
#define I2C_CR2_ITBUFEN        (1U << 10)

/* SR1 */
#define I2C_SR1_SB             (1U << 0)
#define I2C_SR1_ADDR           (1U << 1)
#define I2C_SR1_BTF            (1U << 2)
#define I2C_SR1_RXNE           (1U << 6)
#define I2C_SR1_TXE            (1U << 7)
#define I2C_SR1_BERR           (1U << 8)
#define I2C_SR1_ARLO           (1U << 9)
#define I2C_SR1_AF             (1U << 10)
#define I2C_SR1_OVR            (1U << 11)

/* SR2 */
#define I2C_SR2_BUSY           (1U << 1)
#define I2C_SR2_MSL            (1U << 0)

/* --------------------------------------------------------------------------
 *  Inline low-level helpers
 * -------------------------------------------------------------------------- */
static inline void i2c_enable(I2C_TypeDef *i2c)
{
    i2c->CR1 |= I2C_CR1_PE;
}

static inline void i2c_disable(I2C_TypeDef *i2c)
{
    i2c->CR1 &= ~I2C_CR1_PE;
}

static inline void i2c_start(I2C_TypeDef *i2c)
{
    i2c->CR1 |= I2C_CR1_START;
}

static inline void i2c_stop(I2C_TypeDef *i2c)
{
    i2c->CR1 |= I2C_CR1_STOP;
}

static inline void i2c_send_addr(I2C_TypeDef *i2c, uint8_t addr)
{
    i2c->DR = addr & 0xFEU;  /* write address (R/W bit = 0 for write) */
}

static inline void i2c_write_data(I2C_TypeDef *i2c, uint8_t data)
{
    while (!(i2c->SR1 & I2C_SR1_TXE)) ;  /* Wait TX empty */
    i2c->DR = data;
}

static inline uint8_t i2c_read_data(I2C_TypeDef *i2c)
{
    while (!(i2c->SR1 & I2C_SR1_RXNE)) ;
    return (uint8_t)(i2c->DR & 0xFF);
}

/* --------------------------------------------------------------------------
 *  Example: Blocking single-byte write
 * -------------------------------------------------------------------------- */
static inline void i2c_write_byte(I2C_TypeDef *i2c, uint8_t dev_addr, uint8_t data)
{
    while (i2c->SR2 & I2C_SR2_BUSY) ;  /* Wait until bus free */

    i2c_start(i2c);
    while (!(i2c->SR1 & I2C_SR1_SB)) ;

    i2c_send_addr(i2c, dev_addr << 1);
    while (!(i2c->SR1 & I2C_SR1_ADDR)) ;
    (void)i2c->SR2; /* Clear ADDR flag */

    i2c_write_data(i2c, data);
    while (!(i2c->SR1 & I2C_SR1_BTF)) ;

    i2c_stop(i2c);
}

/* -------------------------------------------------------------------------- */
#ifdef __cplusplus
}
#endif

#endif /* I2C_REGS_H */

