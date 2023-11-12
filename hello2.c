// SPDX-License-Identifier: GPL-2-Clause
#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include "hello1.h"

MODULE_AUTHOR("Chernoivanenko Viktoriia");
MODULE_DESCRIPTION("Hello, world message");
MODULE_LICENSE("Dual BSD/GPL");

static uint howmany = 1;
module_param(howmany, uint, 0444);
MODULE_PARM_DESC(howmany, "how many times the greeting will be printed");


static int __init hello_init(void)
{
	if (howmany == 0 || (howmany >= 5 && howmany <= 10)) {
		pr_warn("Warning: howmany is equal to %d\n", howmany);
	} else if (howmany > 10) {
		pr_err("Error: howmany is greater then 10");
		return -EINVAL;
	}
	print_hello(howmany);
	return 0;
}

static void __exit hello_exit(void)
{
	pr_info("Bye, hello2 is not here anymore.\n");
}

module_init(hello_init);
module_exit(hello_exit);
