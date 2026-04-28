#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

#ifdef CONFIG_UNWINDER_ORC
#include <asm/orc_header.h>
ORC_HEADER;
#endif

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xde80cd09, "ioremap" },
	{ 0x1035c7c2, "__release_region" },
	{ 0xedc03953, "iounmap" },
	{ 0x18b0f0a7, "uart_get_baud_rate" },
	{ 0x298510e3, "uart_update_timeout" },
	{ 0x102fe6de, "hrtimer_cancel" },
	{ 0x4a77885d, "platform_driver_unregister" },
	{ 0xc402aed6, "uart_unregister_driver" },
	{ 0x848d372e, "iowrite8" },
	{ 0x87b8f972, "uart_write_wakeup" },
	{ 0x54b1fac6, "__ubsan_handle_load_invalid_value" },
	{ 0xf0a2251d, "tty_flip_buffer_push" },
	{ 0x84323a64, "__tty_insert_flip_string_flags" },
	{ 0xb19b445, "ioread8" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x23509fba, "__platform_driver_register" },
	{ 0x2cf56265, "__dynamic_pr_debug" },
	{ 0xa193b721, "devm_kmalloc" },
	{ 0x60a5786d, "platform_get_resource" },
	{ 0xea82d349, "hrtimer_init" },
	{ 0xbf6afdb6, "uart_add_one_port" },
	{ 0x85abef3e, "uart_register_driver" },
	{ 0xfe15742c, "_dev_err" },
	{ 0xf8145464, "__dynamic_dev_dbg" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x34db050b, "_raw_spin_lock_irqsave" },
	{ 0xa78af5f3, "ioread32" },
	{ 0xd35cce70, "_raw_spin_unlock_irqrestore" },
	{ 0xc0b7c197, "hrtimer_start_range_ns" },
	{ 0x4a453f53, "iowrite32" },
	{ 0x77358855, "iomem_resource" },
	{ 0x85bd1608, "__request_region" },
	{ 0xe2fd41e5, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "5BF6ADE5A5E498A18F619C2");
