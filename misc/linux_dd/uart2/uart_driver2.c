#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/interrupt.h>
#include <linux/io.h>
#include <linux/tty.h>
#include <linux/tty_flip.h>
#include <linux/serial_core.h>

#define DRIVER_NAME "my_uart"
#define UART_NR     1

#define UART_BASE_ADDR  0x40000000
#define UART_MEM_SIZE   0x1000
#define UART_IRQ        42

#define TX_REG     0x00
#define RX_REG     0x04
#define STATUS_REG 0x08

#define RX_READY   (1 << 0)
#define TX_EMPTY   (1 << 1)

static struct uart_driver my_uart_driver;
static struct uart_port my_uart_port;

/* -------------------------------------------------- */
/* UART OPS                                           */
/* -------------------------------------------------- */

static unsigned int my_tx_empty(struct uart_port *port)
{
    return readl(port->membase + STATUS_REG) & TX_EMPTY;
}

static void my_set_mctrl(struct uart_port *port, unsigned int mctrl) {}
static unsigned int my_get_mctrl(struct uart_port *port)
{
    return TIOCM_CTS | TIOCM_DSR | TIOCM_CAR;
}

static void my_start_tx(struct uart_port *port)
{
    struct circ_buf *xmit = &port->state->xmit;

    if (uart_circ_empty(xmit))
        return;

    while (!(readl(port->membase + STATUS_REG) & TX_EMPTY))
        cpu_relax();

    writel(xmit->buf[xmit->tail], port->membase + TX_REG);
    xmit->tail = (xmit->tail + 1) & (UART_XMIT_SIZE - 1);

    uart_write_wakeup(port);
}

static void my_stop_tx(struct uart_port *port) {}
static void my_stop_rx(struct uart_port *port) {}
static irqreturn_t my_uart_isr(int irq, void *dev_id);

static int my_startup(struct uart_port *port)
{
    return request_irq(port->irq, my_uart_isr, 0,
                       DRIVER_NAME, port);
}

static void my_shutdown(struct uart_port *port)
{
    free_irq(port->irq, port);
}

static void my_set_termios(struct uart_port *port,
                           struct ktermios *termios,
                           const struct ktermios *old)
{
    uart_update_timeout(port, termios->c_cflag, 115200);
}

static const char *my_type(struct uart_port *port)
{
    return DRIVER_NAME;
}

static struct uart_ops my_uart_ops = {
    .tx_empty   = my_tx_empty,
    .set_mctrl  = my_set_mctrl,
    .get_mctrl  = my_get_mctrl,
    .start_tx   = my_start_tx,
    .stop_tx    = my_stop_tx,
    .stop_rx    = my_stop_rx,
    .startup    = my_startup,
    .shutdown   = my_shutdown,
    .set_termios = my_set_termios,
    .type       = my_type,
};

/* -------------------------------------------------- */
/* INTERRUPT HANDLER                                  */
/* -------------------------------------------------- */

static irqreturn_t my_uart_isr(int irq, void *dev_id)
{
    struct uart_port *port = dev_id;
    unsigned char ch;

    if (!(readl(port->membase + STATUS_REG) & RX_READY))
        return IRQ_NONE;

    ch = readl(port->membase + RX_REG) & 0xFF;

    uart_insert_char(port, 0, 0, ch, TTY_NORMAL);
    tty_flip_buffer_push(&port->state->port);

    return IRQ_HANDLED;
}

/* -------------------------------------------------- */
/* INIT / EXIT                                        */
/* -------------------------------------------------- */

static int __init my_uart_init(void)
{
    int ret;

    my_uart_driver.owner       = THIS_MODULE;
    my_uart_driver.driver_name = DRIVER_NAME;
    my_uart_driver.dev_name    = "ttyMY";
    my_uart_driver.nr          = UART_NR;

    ret = uart_register_driver(&my_uart_driver);
    if (ret)
        return ret;

    my_uart_port.iotype  = UPIO_MEM;
    my_uart_port.mapbase = UART_BASE_ADDR;
    my_uart_port.membase = ioremap(UART_BASE_ADDR, UART_MEM_SIZE);
    my_uart_port.irq     = UART_IRQ;
    my_uart_port.ops     = &my_uart_ops;
    my_uart_port.flags   = UPF_BOOT_AUTOCONF;
    my_uart_port.line    = 0;
    my_uart_port.fifosize = 1;

    ret = uart_add_one_port(&my_uart_driver, &my_uart_port);
    if (ret)
        uart_unregister_driver(&my_uart_driver);

    return ret;
}

static void __exit my_uart_exit(void)
{
    uart_remove_one_port(&my_uart_driver, &my_uart_port);
    uart_unregister_driver(&my_uart_driver);
    iounmap(my_uart_port.membase);
}

module_init(my_uart_init);
module_exit(my_uart_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Example");
MODULE_DESCRIPTION("Custom UART Driver");
