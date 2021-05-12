#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kdev_t.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/ktime.h>
#include <linux/timekeeping.h>
#include <linux/uaccess.h>

MODULE_AUTHOR("Bastilo, Bosyk, Ponomarov");
MODULE_DESCRIPTION("Simple char device module");
MODULE_LICENSE("GPL");

#define BUF_LEN 256

#define _POSIX_C_SOURCE 199309L

#define MSG_PREF "GROUP7_MSG: "
#define print_msg(msg, ...) printk(KERN_ERR MSG_PREF msg, ##__VA_ARGS__);

// Kernel structures needed to create character device
dev_t devt = 0;
static struct class *dev_class = NULL;
static struct cdev my_cdev;
static struct device *dev = NULL;

static int      my_open(struct inode *inode, struct file *file);
static int      my_release(struct inode *inode, struct file *file);
static ssize_t  my_read(struct file *filp, char __user *buf, size_t len,loff_t * off);
static ssize_t  my_write(struct file *filp, const char *buf, size_t len, loff_t * off);
static long 	my_ioctl(struct file *filp, unsigned int cmd, unsigned long arg);

// Pointers to device operations
static struct file_operations fops = {
    .owner      	= THIS_MODULE,
    .read       	= my_read,
    .write      	= my_write,
    .open       	= my_open,
    .release    	= my_release,
    .unlocked_ioctl = my_ioctl,
};

static int my_open(struct inode *inode, struct file *file)
{
	print_msg("Driver Open Function Called...!!!\n");
	return 0;
}

static int my_release(struct inode *inode, struct file *file)
{
	print_msg("Driver Release Function Called...!!!\n");
	return 0;
}

static ssize_t my_read(struct file *filp, char __user *buf, size_t len, loff_t *off)
{
	uint8_t data[BUF_LEN] = {0};
	struct timespec64 t;
	print_msg("Driver Read Function Called...!!!\n");

	snprintf(data, BUF_LEN, "Hello to console");

	if (len > BUF_LEN) {
		len = BUF_LEN;
	}

	// Copying data from kernel to user
	if (copy_to_user(buf, data, len)) {
		return -EFAULT;
	}

	return len;
}

static ssize_t my_write(struct file *filp, const char __user *buf, size_t len, loff_t *off)
{
	uint8_t data[BUF_LEN] = {0};
	
	print_msg("Driver Write Function Called...!!!\n");
	return len;
}

static long my_ioctl(struct file *filp, unsigned int cmd, unsigned long arg) {
	print_msg("Driver Ioctl Function Called...!!!\n");
	return 0;
}

static int __init cdev_module_init(void)
{
	long res = 0;
	// Memory allocation for character device
	if((res = alloc_chrdev_region(&devt, 0, 1, "my_cdev")) < 0){
		print_msg("Cannot allocate major number\n");
		goto alloc_err;
	}
	print_msg("Major = %d Minor = %d\n", MAJOR(devt), MINOR(devt));

	// Device initialization
	cdev_init(&my_cdev, &fops);
	// Adding device to system
	if((res = cdev_add(&my_cdev, devt, 1)) < 0){
		print_msg("Cannot add the device to the system\n");
		goto cdev_add_err;
	}

	dev_class = class_create(THIS_MODULE, "my_class");
	// Errors processing
	if(IS_ERR(dev_class)){
		res = PTR_ERR(dev_class);
		print_msg("Cannot create the struct class\n");
		goto class_err;
	}

	dev = device_create(dev_class, NULL, devt, NULL, "my_cdev");
	// Errors processing
	if(IS_ERR(dev)){
		res = PTR_ERR(dev);
		print_msg("Cannot create the Device\n");
		goto dev_create_err;
	}

	print_msg("Device Driver Insert...Done!!!\n");
	return 0;
dev_create_err:
	class_destroy(dev_class);
class_err:
cdev_add_err:
	unregister_chrdev_region(devt, 1);
alloc_err:
	return res;
}

static void __exit cdev_module_exit(void)
{
	device_destroy(dev_class, devt);
	class_destroy(dev_class);
	cdev_del(&my_cdev);
	unregister_chrdev_region(devt, 1);
	print_msg("Device Driver Remove...Done!!!\n");
}
module_init(cdev_module_init);
module_exit(cdev_module_exit);
