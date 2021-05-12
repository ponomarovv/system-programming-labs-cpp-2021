ifneq ($(KERNELRELEASE),)
# kbuild part of makefile
obj-m := hw_module.o
else
# normal makefile
KDIR ?= /lib/modules/`uname -r`/build

default:
	$(MAKE) -C $(KDIR) M=$$PWD
clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean
endif

# Как работает этот make файл можно прочитать в книге Linux device drivers в разделе Компиляция модулей,
# этот раздел находится на 23 странице в прикрепленном к репозиторию экземпляре книги