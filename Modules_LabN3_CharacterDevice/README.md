# Description
In this lab character device was realized(honestly, it was only a try to implement character device).

To test this lab you need to do the following:
* Open your Terminal in root directory;
* Run `make` command;
* Run `sudo insmod cdev_module.ko` command;
* Goto to *cprog* directory;
* Run `main` command(or if you do not have `main` executable file in this directory, you need to build main.c file with *Makefile*)

And here it's. `Hello to console` will be displayed in your Terminal. But sometimes you can get an error 13 because your character device has no executing rights.

To fix that issue you need to run:

	sudo chmod 777 /dev/my_cdev

Then run `main` command once again. Have fun! ;)