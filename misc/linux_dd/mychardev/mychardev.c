#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/uaccess.h>

#define DEVICE_NAME "mychardev"
#define BUF_SIZE 1024

static dev_t dev_num;
static struct cdev my_cdev;
static char kbuf[BUF_SIZE];
static int kbuf_len = 0;

/* Open */
static int my_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "mychardev: device opened\n");
    return 0;
}

/* Read */
static ssize_t my_read(struct file *file, char __user *ubuf,
                       size_t len, loff_t *offset)
{
    if (*offset >= kbuf_len)
        return 0;

    if (copy_to_user(ubuf, kbuf, kbuf_len))
        return -EFAULT;

    *offset = kbuf_len;
    printk(KERN_INFO "mychardev: data read\n");
    return kbuf_len;
}

/* Write */
static ssize_t my_write(struct file *file, const char __user *ubuf,
                        size_t len, loff_t *offset)
{
    if (len > BUF_SIZE)
        len = BUF_SIZE;

    if (copy_from_user(kbuf, ubuf, len))
        return -EFAULT;

    kbuf_len = len;
    printk(KERN_INFO "mychardev: data written (%d bytes)\n", len);
    return len;
}

/* File operations */
static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open  = my_open,
    .read  = my_read,
    .write = my_write,
};

/* Init */
static int __init my_init(void)
{
    alloc_chrdev_region(&dev_num, 0, 1, DEVICE_NAME);
    cdev_init(&my_cdev, &fops);
    cdev_add(&my_cdev, dev_num, 1);

    printk(KERN_INFO "mychardev loaded: major=%d minor=%d\n",
           MAJOR(dev_num), MINOR(dev_num));
    return 0;
}

/* Exit */
static void __exit my_exit(void)
{
    cdev_del(&my_cdev);
    unregister_chrdev_region(dev_num, 1);
    printk(KERN_INFO "mychardev unloaded\n");
}

module_init(my_init);
module_exit(my_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Example");
MODULE_DESCRIPTION("Simple Character Device Driver");
