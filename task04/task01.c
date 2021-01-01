#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Sean Schoonover");
MODULE_DESCRIPTION("Hello World module");
MODULE_VERSION("0.1");

static int __init hello_world(void)
{
	printk(KERN_DEBUG "Hello World!\n");
	return 0;
}

static void __exit goodbye_world(void)
{
	printk(KERN_DEBUG "Goodbye World!\n");
}

module_init(hello_world);
module_exit(goodbye_world);
