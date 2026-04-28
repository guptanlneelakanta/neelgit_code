#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>

static int __init hw_mod_init(void)
{
printk(KERN_INFO "hello world module loaded success");
return 0;
}


static void __exit test_mod_exit(void)
{
printk(KERN_INFO "hello world module exit success");

}

module_init(hw_mod_init);
module_exit(test_mod_exit);

MODULE_LICENSE("gpl");
MODULE_AUTHOR("NEEL");
MODULE_DESCRIPTION("NEEL");
MODULE_VERSION("V.1.2.3");

