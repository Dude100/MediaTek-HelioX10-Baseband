# Define source file lists to SRC_LIST
SRC_LIST  = driver/drvtest/common/src/drvtest_common.c \
            driver/drvtest/common/src/drvtest_dummy.c
ifeq ($(filter __ARM7EJ_S__, $(strip $(MODULE_DEFS))),)
    SRC_LIST  += driver/drvtest/common/src/drvtest_sm.c
endif

# Define include path lists to INC_DIR
INC_DIR   = driver/devdrv/common/inc \
            driver/devdrv/iomux/inc \
            driver/drvtest/common/inc \
            driver/sys_drv/cache/inc \
            driver/sys_drv/init/inc \
            service/sst/include

# Define the specified compile options to COMP_DEFS
COMP_DEFS =

# Define the source file search paths to SRC_PATH
SRC_PATH  = driver/drvtest/common/src

include make/module/driver/drvtest/gpt.mak
-include make/module/driver/drvtest/lmac.mak
include make/module/driver/drvtest/spic.mak
include make/module/driver/drvtest/nfi.mak
-include make/module/driver/drvtest/l2_cipher.mak
-include make/module/driver/drvtest/mac_phy_cosim.mak
-include make/module/driver/drvtest/l2_hw_logging.mak
include make/module/driver/drvtest/gdma.mak
include make/module/driver/drvtest/hif.mak
include make/module/driver/drvtest/usim.mak
include make/module/driver/drvtest/rstctl.mak
include make/module/driver/drvtest/cpu.mak
include make/module/driver/drvtest/coresight.mak
include make/module/driver/drvtest/gpio.mak
 include make/module/driver/drvtest/eint.mak

include make/module/driver/drvtest/dem.mak

include make/module/driver/drvtest/pfc.mak
include make/module/driver/drvtest/uart.mak
include make/module/driver/drvtest/idc.mak
include make/module/driver/drvtest/stress.mak
include make/module/driver/drvtest/drvtest_slt.mak
include make/module/driver/drvtest/mc_drvtest.mak
include make/module/driver/drvtest/dspfm.mak
include make/module/driver/drvtest/busmon.mak
include make/module/driver/drvtest/bsi.mak
include make/module/driver/drvtest/dormant.mak
-include make/module/driver/drvtest/ss.mak
-include make/module/driver/drvtest/emi.mak
