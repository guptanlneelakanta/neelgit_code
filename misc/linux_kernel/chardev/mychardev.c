#include <linux/module.h>
#include <linux/fs.h>

#define DEVICE_NAME "mychardev"
static int major;

static int __init dev_init(void)
{
    major = register_chrdev(0, DEVICE_NAME, NULL);
    printk(KERN_INFO "Registered with major %d\n", major);
    return 0;
}

static void __exit dev_exit(void)
{
    unregister_chrdev(major, DEVICE_NAME);
    printk(KERN_INFO "Device unregistered\n");
}

module_init(dev_init);
module_exit(dev_exit);
MODULE_LICENSE("GPL");
