#!/bin/bash
export INTELFPGAOCLSDKROOT=/root/aocl-rte-17.1.0-590.arm32.4.9
export AOCL_BOARD_PACKAGE_ROOT=$INTELFPGAOCLSDKROOT/board/c5soc
export PATH=$INTELFPGAOCLSDKROOT/bin:$PATH
export LD_LIBRARY_PATH=$INTELFPGAOCLSDKROOT/host/arm32/lib:$AOCL_BOARD_PACKAGE_ROOT/arm32/lib:$LD_LIBRARY_PATH
insmod $AOCL_BOARD_PACKAGE_ROOT/arm32/driver/aclsoc_drv.ko
#export CL_CONTEXT_COMPILER_MODE_INTELFPGA=3
