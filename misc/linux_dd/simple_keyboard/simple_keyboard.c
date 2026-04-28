#include <linux/module.h>
#include <linux/input.h>
#include <linux/init.h>
#include <linux/timer.h>

static struct input_dev *kbd_dev;
static struct timer_list key_timer;
static int key_pressed;

/* Simulate key press/release */
static void key_timer_fn(struct timer_list *t)
{
    key_pressed = !key_pressed;

    input_report_key(kbd_dev, KEY_A, key_pressed);
    input_sync(kbd_dev);

    mod_timer(&key_timer, jiffies + msecs_to_jiffies(1000));
}

static int __init kbd_init(void)
{
    kbd_dev = input_allocate_device();
    if (!kbd_dev)
        return -ENOMEM;

    kbd_dev->name = "Simple Virtual Keyboard";
    kbd_dev->phys = "kbd/input0";

    /* Enable key events */
    __set_bit(EV_KEY, kbd_dev->evbit);
    __set_bit(KEY_A, kbd_dev->keybit);

    input_register_device(kbd_dev);

    timer_setup(&key_timer, key_timer_fn, 0);
    mod_timer(&key_timer, jiffies + msecs_to_jiffies(1000));

    printk(KERN_INFO "Virtual keyboard loaded\n");
    return 0;
}

static void __exit kbd_exit(void)
{
    del_timer_sync(&key_timer);
    input_unregister_device(kbd_dev);
    printk(KERN_INFO "Virtual keyboard unloaded\n");
}

module_init(kbd_init);
module_exit(kbd_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Example");
MODULE_DESCRIPTION("Simple Linux Keyboard Driver");
