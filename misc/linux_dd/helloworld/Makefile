obj-m += hello_world.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean


#Explanation:
#obj-m += helloworld.o → tells kernel build system to build a module
#-C /lib/modules/.../build → switches to kernel build directory
#M=$(PWD) → current module directory
#modules → builds the module
#clean → removes generated files