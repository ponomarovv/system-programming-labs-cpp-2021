# Description
It's simple module to print list and modified list to kernel logs.

Firstly, you need to run `make` command to compile module.
Secondly, you need to install module. In your Terminal Run:
	
    sudo insmod list_module.ko

To see the result run:

	dmesg

In order to remove module, run:

	sudo rmmod list_module.ko

And result:

	dmesg