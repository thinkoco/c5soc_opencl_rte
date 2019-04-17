# How to do
## Get linux kernel

	git clone --depth 3 --branch socfpga-4.9.78-aocl https://github.com/thinkoco/linux-socfpga.git
	
	wget https://cdn.kernel.org/pub/linux/kernel/v4.x/linux-4.19.29.tar.xz

## Update linux kernel

**linux-x.x.x/drivers/fpga/Makefile**

	obj-$(CONFIG_FPGA)          += fpga-mgr.o  fpga-mgr-fops.o

**linux-x.x.x/drivers/video/fbdev/Makefile**

	# Hardware specific drivers go first
	obj-$(CONFIG_FB_ALTERA_VIP)   += altvipfb.o

**linux-x.x.x/drivers/video/fbdev/Kconfig**

	comment "Frame buffer hardware drivers"
		depends on FB

		config FB_ALTERA_VIP
		tristate "Altera VIP Frame Reader framebuffer support"
		depends on FB
		select FB_CFB_FILLRECT
		select FB_CFB_COPYAREA
		select FB_CFB_IMAGEBLIT
		help
		This driver supports the Altera Video and Image Processing(VIP)
		Frame Reader

**dts**

	cp socfpga.dtsi  linux-x.x.x/arch/arm/boot/dts/
	cp socfpga_cyclone5_de10_nano.dts  linux-x.x.x/arch/arm/boot/dts/

**c5socl_defconfig**

	cp c5socl_defconfig linux-x.x.x/arch/arm/configs/

## Build linux kernel

	export ARCH=arm
	export CROSS_COMPILE=arm-linux-gnueabihf-
	export LOADADDR=0x8000
	make c5socl_defconfig
	make zImage -j4
	make modules
	make socfpga_cyclone5_de10_nano.dtb

## Build opencl dirver

	tar xvf aocl-rte-17.1.0-590.arm32.4.19.tar.xz
	cd /aocl-rte-17.1.0-590.arm32.4.19/board/c5soc/arm32/driver/
	make KDIR=PATH_TO_linux-x.x.x

## Disable configure fpga by opencl host 

	export CL_CONTEXT_COMPILER_MODE_INTELFPGA=3

## FPGA reconfiguration within VIP core
source the `init_opencl_xxxx.sh` file and run the following commands in the `serial port terminal`
```
service lightdm stop

rmmod -f altvipfb
rmmod cfbfillrect
rmmod cfbimgblt
rmmod cfbcopyarea

aocl program /dev/acl0 yourtarget.aocx
 
modprobe altvipfb
service lightdm start
export DISPLAY=:0
```
the `yourtarget.aocx` is the new aocx file which contains the VIP core.