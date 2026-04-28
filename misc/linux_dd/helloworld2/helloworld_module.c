#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/moduleparam.h>
#include <linux/fs.h>
#include <linux/err.h>
#include <linux/device.h>

int valueETX, valueETXarr[4];
char *strETX;
int cb_valueETX=0;
module_param(valueETX, int, S_IRUSR | S_IWUSR);
module_param_array(valueETXarr, int, NULL, S_IRUSR | S_IWUSR);
module_param(strETX, charp, S_IRUSR | S_IWUSR);


//dev_t dev = MKDEV(235, 0);  //static alloc
dev_t dev = 0   ; //dynamic alloc

int notify_param_etx(const char *val, const struct kernel_param *kp){
    int res = param_set_int(val, kp);
    if(res == 0){
        printk("Call back function called...\n");
        printk("\n cb_valueETX changed to %d\n", cb_valueETX);        
    }
    else
        printk("Error setting cb_valueETX\n");

    return res;
}


const struct kernel_param_ops param_ops_etx = {
    .set = &notify_param_etx,
    .get = &param_get_int,
};

module_param_cb(cb_valueETX, &param_ops_etx, &cb_valueETX, S_IRUSR | S_IWUSR);

        static struct class *device_class;

static int __init helloworld_init(void){

    //dynamic allocation of major number
    if((alloc_chrdev_region(&dev, 0, 1, "etx_device")) <0){
                printk(KERN_INFO "Cannot allocate major number for device 1\n");
                return -1;
    }
    printk(KERN_INFO "Major = %d Minor = %d \n",MAJOR(dev), MINOR(dev));

            /*Creating struct class*/
    device_class = class_create("dev_class");
    if (IS_ERR(device_class)) {
        printk("Cannot create the struct class for device\n");
     goto r_class;     
    }
     /*Creating device*/
    if(IS_ERR(device_create(device_class, NULL, dev, NULL, "etx_device"))){
        printk("Cannot create the Device 1\n");
        goto r_device;
    }

    //register_chrdev_region(dev, 1, "Embetronicx_Dev");  //static alloc
    printk("valueETX = %d", valueETX);
    printk("strETX = %s", strETX);
    printk("cb_valueETX = %d", cb_valueETX);
    for(int i=0; i<4; i++)
        printk("valueETXarr[%d] = %d", i,valueETXarr[i]);

    pr_info("\n hello world module initialised\n");
    printk("\n hello world simple module \n");
    printk("\n hello world module inserted successfully\n");

    r_device:
    class_destroy(device_class);

    r_class:
    unregister_chrdev_region(dev, 1);

    return 0;
}

static void __exit helloworld_exit(void){
    printk("\n hello world module exiting\n");
}

module_init(helloworld_init);
module_exit(helloworld_exit);

MODULE_VERSION("V1.2");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Neelakanta");
MODULE_DESCRIPTION("hello world module");


