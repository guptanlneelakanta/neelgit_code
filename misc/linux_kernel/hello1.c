#include <linux/module.h> // Required for all kernel modules
#include <linux/kernel.h> // Required for KERN_INFO

// Module initialization function
static int __init hello_init(void)
{
    // Print a message to the kernel log buffer
    printk(KERN_INFO "Hello World! The kernel module is now loaded.\n");
    return 0; // Success
}

// Module cleanup function
static void __exit hello_exit(void)
{
    printk(KERN_INFO "Goodbye, World! The kernel module is now unloaded.\n");
}

// Register the module entry and exit points
module_init(hello_init);
module_exit(hello_exit);

// Module metadata
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("A simple kernel module example.");
