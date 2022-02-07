#include <linux/init.h>
#include <linux/slab.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/moduleparam.h>
#include <linux/stat.h>

MODULE_LICENSE("Module licence");
MODULE_DESCRIPTION("Module description");
MODULE_AUTHOR("Hugo Altiery");

static int n;
static char *str;

module_param(n, int, S_IRUSR | S_IWUSR);
module_param(str, charp, S_IRUSR | S_IWUSR);

static int __init my_init(void)
{
  int i;
  printk(KERN_DEBUG "Hello kernel!\n");

  for (i = 0; i < n; i++)
    {
      printk(KERN_DEBUG "Hello %s\n", str);
    }

  return (0);
}

static void __exit my_exit(void)
{
  int i;
  printk(KERN_DEBUG "Goodbye kernel!\n");

  for (i = 0; i < n; i++)
    {
      printk(KERN_DEBUG "Goodbye %s\n", str);
    }
  return;
}

module_init(my_init);
module_exit(my_exit);
