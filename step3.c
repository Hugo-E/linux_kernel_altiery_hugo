include <linux/init.h>
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

static int major;
static int device_is_open = 0;

static int my_dev_open(struct inode *inode, struct file *file);
static int my_dev_close(struct inode *inode, struct file *file);
static ssize_t my_dev_read(struct file *file, char *buf, size_t len, loff_t *off);
static ssize_t my_dev_write(struct file *file, const char *buf, size_t len, loff_t *off);

static struct file_operations fops = {
  .read = my_dev_read,
  .write = my_dev_write,
  .open = my_dev_open,
  .release = my_dev_close
};

static int my_dev_open(struct inode *inode, struct file *file)
{
  if (device_is_open)
    {
      printk("Device is already open");
      return (-EBUSY);
    }
  device_is_open = 1;
  printk("Device is open\n");
  return (0);
}

static int my_dev_close(struct inode *inode, struct file *file)
{
  if (device_is_open)
    {
        device_is_open = 0;
        printk("Device is close\n");
    } else {
    printk("Device %s cannot be closed");
  }
  return 0;
}

static ssize_t my_dev_read(struct file *file, char* buf, size_t len, loff_t *off)
{
  printk("The device is read");
  return (0);
}

static ssize_t my_dev_write(struct file *file, const char *buf, size_t len, loff_t *off)
{
  printk("Someone write on the device");
  return (len);
}


static int __init my_init(void)
{
  int i;
  printk(KERN_DEBUG "Hello kernel!\n");
  return (0);
}

static void __exit my_exit(void)
{
  int i;
  printk(KERN_DEBUG "Goodbye kernel!\n");
  return;
}

module_init(my_init);
module_exit(my_exit);
