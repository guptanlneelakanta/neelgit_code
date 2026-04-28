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
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x77358855, "iomem_resource" },
	{ 0x85bd1608, "__request_region" },
	{ 0x1035c7c2, "__release_region" },
	{ 0x92d5838e, "request_threaded_irq" },
	{ 0xc1514a3b, "free_irq" },
	{ 0xdae5e528, "uart_suspend_port" },
	{ 0x87a21cb3, "__ubsan_handle_out_of_bounds" },
	{ 0x720cb3a2, "uart_resume_port" },
	{ 0xbf6afdb6, "uart_add_one_port" },
	{ 0xaefd579d, "uart_remove_one_port" },
	{ 0x85abef3e, "uart_register_driver" },
	{ 0xf6f06725, "platform_device_register_full" },
	{ 0x23509fba, "__platform_driver_register" },
	{ 0xc402aed6, "uart_unregister_driver" },
	{ 0x32a08632, "platform_device_unregister" },
	{ 0xf0fdf6cb, "__stack_chk_fail" },
	{ 0xe2fd41e5, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "D57A81A84D27CFEA10ABE10");
