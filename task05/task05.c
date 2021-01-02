// SPDX-License-Identifier: GPL-2.0
/*
 * task05.c
 * Eudyptula Challenge: Task 05
 *
 * Kernel module that will automatically be loaded whenever any USB keyboard is connected.
 *
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/hid.h>
#include <linux/usb.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sean Schoonover");
MODULE_DESCRIPTION("Hello World keyboard hotplug module");

static struct usb_device_id keyboards[] = {
	{
		USB_INTERFACE_INFO(
			  USB_INTERFACE_CLASS_HID,
			  USB_INTERFACE_SUBCLASS_BOOT,
			  USB_INTERFACE_PROTOCOL_KEYBOARD
		)
	},
	{ }
};

MODULE_DEVICE_TABLE(usb, keyboards);

static int __init hello_world(void)
{
	pr_debug("Hello World!\n");
	return 0;
}

static void __exit goodbye_world(void)
{
	pr_debug("Goodbye World!\n");
}

module_init(hello_world);
module_exit(goodbye_world);
