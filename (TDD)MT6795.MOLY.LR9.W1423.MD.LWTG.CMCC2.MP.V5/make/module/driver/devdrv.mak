ifeq ($(strip $(PLATFORM)),MT6752)
  ifdef MDSYS
    ifeq ($(strip $(MDSYS)),MD2)
      DEVDRV_PLATFORM = DEVDRV_WR8
    endif
  endif
endif
ifneq ($(strip $(DEVDRV_PLATFORM)),DEVDRV_WR8)
# Define source file lists to SRC_LIST
SRC_LIST  = driver/devdrv/common/src/devdrv_hisr.c \
		   driver/devdrv/common/src/devdrv_common.c
ifeq ($(filter __ARM7EJ_S__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += driver/devdrv/common/src/$(COMPILER)/mon_counter.S
endif

#SRC_LIST = driver/devdrv/common/src/drv_comm.c \
		   driver/devdrv/common/src/$(COMPILER)/mon_counter.S

# Define include path lists to INC_DIR
INC_DIR  = driver/devdrv/common/inc \
		   driver/devdrv/trace \
		   driver/devdrv/us_counter/inc \
		   driver/sys_drv/cache/inc \
		   service/sst/include \
		   service/sss/interface/inc \
		   service/sys_svc/gfh/public \
		   interface/service/sys_svc \
		   interface/service/hif \
		   $(strip $(PROJDIR))/custom/driver/drv_gen 

# Define the specified compile options to COMP_DEFS
COMP_DEFS =


# Define the source file search paths to SRC_PATH
SRC_PATH  = driver/devdrv/common/src \
			driver/devdrv/common/src/$(COMPILER)

-include make/module/driver/devdrv/gpt.mak

-include make/module/driver/devdrv/uart.mak
-include make/module/driver/devdrv/gdma.mak
-include make/module/driver/devdrv/usim.mak
-include make/module/driver/devdrv/coresight.mak
-include make/module/driver/devdrv/gpio.mak
-include make/module/driver/devdrv/eint.mak
-include make/module/driver/devdrv/dem.mak
#-include make/module/driver/devdrv/pfc.mak
-include make/module/driver/devdrv/idc.mak
-include make/module/driver/devdrv/cirq_v2.mak
-include make/module/driver/devdrv/us_counter.mak
-include make/module/driver/devdrv/devdrv_fakeapi.mak
-include make/module/driver/devdrv/auxadc.mak
-include make/module/driver/devdrv/pfb.mak
-include make/module/driver/mc.mak
-include make/module/driver/devdrv/rtc.mak
-include make/module/driver/devdrv/malmo.mak
-include make/module/driver/devdrv/pmic.mak
-include make/module/driver/devdrv/pmic_wrap.mak
-include make/module/driver/devdrv/bsi.mak
-include make/module/driver/devdrv/cfgctl.mak
-include make/module/driver/devdrv/f32k_clk.mak
-include make/module/driver/devdrv/dcm.mak
-include make/module/driver/devdrv/emi.mak
-include make/module/driver/devdrv/pll.mak
-include make/module/driver/devdrv/iomux.mak
-include make/module/driver/devdrv/busmon.mak
-include make/module/driver/devdrv/pdn.mak
-include make/module/driver/devdrv/arm7wdt.mak
-include make/module/driver/devdrv/boot_init.mak
-include make/module/driver/devdrv/pw.mak
-include make/module/driver/devdrv/chr_det.mak
-include make/module/driver/devdrv/bus.mak
-include make/module/driver/devdrv/i2c_pmic.mak
-include make/module/driver/devdrv/bus_err.mak
-include make/module/driver/devdrv/elm.mak
-include make/module/driver/devdrv/mdipc.mak

ifeq ($(filter __ARM7EJ_S__, $(strip $(MODULE_DEFS))),)
-include make/module/driver/devdrv/rstctl.mak
-include make/module/driver/devdrv/pcmon.mak
endif

    
else #ifneq ($(strip $(PLATFORM)),MT6589)

SRC_LIST  = driver/devdrv/common/src/devdrv_hisr.c


# Define include path lists to INC_DIR
INC_DIR  = driver/devdrv/common/inc \
		   driver/devdrv/trace \
		   driver/devdrv/us_counter/inc \
		   driver/sys_drv/cache/inc \
		   service/sst/include \
		   service/sss/interface/inc \
		   service/sys_svc/gfh/public \
		   interface/service/sys_svc \
		   $(strip $(PROJDIR))/custom/driver/drv_gen 

# Define the specified compile options to COMP_DEFS
COMP_DEFS =


# Define the source file search paths to SRC_PATH
SRC_PATH  = driver/devdrv/common/src \
			driver/devdrv/common/src/$(COMPILER)

-include make/module/driver/devdrv/dma.mak
-include make/module/driver/devdrv/bus.mak
-include make/module/driver/devdrv/dcm.mak
-include make/module/driver/devdrv/cirq_v1.mak
-include make/module/driver/devdrv/us_counter.mak
-include make/module/driver/devdrv/pdn.mak
-include make/module/driver/devdrv/pll.mak
-include make/module/driver/devdrv/timer.mak
-include make/module/driver/devdrv/mdipc.mak
-include make/module/driver/devdrv/elm.mak


ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
  ifneq ($(filter __DSP_FCORE4__, $(strip $(MODULE_DEFS))),)
#      SRC_LIST +=   driver/sys_drv/ipc/src/mdci.c
  endif
endif

endif #ifneq ($(strip $(PLATFORM)),MT6589)

ifneq ($(filter __EVENT_BASED_TIMER__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   driver/devdrv/timer/src/event_timer.c
endif


ifeq ($(strip $(COMPILER)),GCC)
    CFLAGS += -Werror
endif


# These modules have no HW & Drv now, only fake api for compile
#-include make\bsp\devdrv\lcd.mak

