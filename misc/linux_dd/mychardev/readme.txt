make
sudo insmod mychardev.ko
dmesg | tail
Check major number:


Create device node:
cat /proc/devices | grep mychardev

Create device node:

sudo mknod /dev/mychardev c <major> 0
sudo mknod /dev/mychardev c 235 0
sudo chmod 666 /dev/mychardev