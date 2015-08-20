#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#define DRIVER_AUTHOR "Parinay <parinay@gmail.com>"
#define DRIVER_DESC "A sample Hello World driver"
/* Module License, author and description */
MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);

/* Init function called on module entry */
static int __init hello_1_init(void)
{
	printk(KERN_DEBUG "Hello world!\n");
	return 0;
}

/* Cleanup function called on module exit */
static void __exit hello_1_exit(void)
{
	printk(KERN_DEBUG "Goodbye world!\n");
}

/* Declare entry and exit functions */
module_init(hello_1_init);
module_exit(hello_1_exit);
