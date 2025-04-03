/*
sudo insmod led_switch_driver.ko
dmesg
sudo mknod /dev/led_switch_driver c 223 0
sudo chmod 666 /dev/led_switch_driver
*/

#include <linux/fs.h>
#include <linux/gpio.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/uaccess.h>

#define DEV_MAJOR_NUMBER 223
#define DEV_NAME "led_switch_driver"

static int led_switch_driver_open(struct inode *inode, struct file *file);
static int led_switch_driver_release(struct inode *inode, struct file *file);
static ssize_t led_switch_driver_read(struct file *file, char __user *buf, size_t length, loff_t *ofs);
static ssize_t led_switch_driver_write(struct file *file, const char __user *buf, size_t length, loff_t *ofs);

int sw[4] = {4 + 512, 17 + 512, 27 + 512, 22 + 512};
int led[4] = {23 + 512, 24 + 512, 25 + 512, 1 + 512};

static struct file_operations led_switch_driver_fops = {
    .owner = THIS_MODULE,
    .open = led_switch_driver_open,
    .release = led_switch_driver_release,
    .read = led_switch_driver_read,
    .write = led_switch_driver_write,
};

static int led_switch_driver_init(void)
{
    printk(KERN_INFO "led_switch_driver init!\n");
    register_chrdev(DEV_MAJOR_NUMBER, DEV_NAME, &led_switch_driver_fops);
    return 0;
}

static void led_switch_driver_exit(void)
{
    printk(KERN_INFO "led_switch_driver exit!\n");
    unregister_chrdev(DEV_MAJOR_NUMBER, DEV_NAME);
}

static int led_switch_driver_open(struct inode *inode, struct file *file)
{
    int ret, i;
    printk(KERN_INFO "led_switch_driver open!\n");

    for (i = 0; i < 4; ++i) {
        ret = gpio_request(sw[i], "SWITCH");
        if (ret < 0)
            printk(KERN_INFO "switch %d request fail!\n", i);
        else
            gpio_direction_input(sw[i]);

        ret = gpio_request(led[i], "LED");
        if (ret < 0)
            printk(KERN_INFO "led %d request fail!\n", i);
        else
            gpio_direction_output(led[i], 0);  // 초기화는 꺼진 상태
    }
    return 0;
}

static int led_switch_driver_release(struct inode *inode, struct file *file)
{
    int i;
    printk(KERN_INFO "led_switch_driver release!\n");

    for (i = 0; i < 4; ++i) {
        gpio_free(sw[i]);
        gpio_free(led[i]);
    }

    return 0;
}

static ssize_t led_switch_driver_read(struct file *file, char __user *buf, size_t length, loff_t *ofs)
{
    int ret, i;
    char sw_status[4];

    printk(KERN_INFO "led_switch_driver read!\n");

    for (i = 0; i < 4; ++i)
        sw_status[i] = gpio_get_value(sw[i]);

    ret = copy_to_user(buf, sw_status, sizeof(sw_status));
    if (ret < 0)
        printk(KERN_INFO "copy_to_user fail!\n");

    return sizeof(sw_status);
}

static ssize_t led_switch_driver_write(struct file *file, const char __user *buf, size_t length, loff_t *ofs)
{
    int ret, i;
    unsigned char led_ctrl[4];

    ret = copy_from_user(led_ctrl, buf, sizeof(led_ctrl));
    if (ret < 0) {
        printk(KERN_INFO "copy_from_user error!\n");
        return -EFAULT;
    }

    printk(KERN_INFO "led_switch_driver write!\n");

    for (i = 0; i < 4; ++i) {
        ret = gpio_direction_output(led[i], led_ctrl[i]);
        if (ret < 0)
            printk(KERN_INFO "led %d direction output fail!\n", i);
    }

    return sizeof(led_ctrl);
}

module_init(led_switch_driver_init);
module_exit(led_switch_driver_exit);
MODULE_LICENSE("GPL");
