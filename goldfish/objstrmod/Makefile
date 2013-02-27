obj-m += objstr.o

KDIR=~/Desktop/AOSP/Android_4.2/device/goldfish
PWD := $(shell pwd)

default:
	make -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	make -C $(KDIR) SUBDIRS=$(PWD) clean
