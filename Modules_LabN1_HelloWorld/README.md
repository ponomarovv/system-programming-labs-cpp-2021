# Description
It's simple module to print some message to kernel logs.

Firstly, you need to run `make` command to compile module.
Secondly, you need to install module. In your Terminal Run:
	
    sudo insmod hw_module.ko

To see the result run:

	dmesg

In order to remove module, run:

	sudo rmmod hw_module.ko

And result:

	dmesg