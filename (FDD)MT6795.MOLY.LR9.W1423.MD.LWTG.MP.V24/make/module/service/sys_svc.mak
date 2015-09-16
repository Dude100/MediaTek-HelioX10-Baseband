##############################################################
# Define bootloader folder path
##############################################################
ifneq ($(filter MT6290, $(strip $(MODULE_DEFS))),)
BL_PATH = bootloader_lte
else
BL_PATH = bootloader
endif

# Define source file lists to SRC_LIST
      SRC_LIST  = service/sys_svc/excep_hdlr/src/excep_hdlr.c
      SRC_LIST +=   service/sys_svc/compression/src/lzmadec.c

ifneq ($(filter __SV5_ENABLED__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   service/sys_svc/compression/src/code_decompression_hal.c 
      SRC_LIST +=   service/sys_svc/compression/src/code_decompression.c
      SRC_LIST +=   service/sys_svc/dp/src/fault.c 
      SRC_LIST +=   service/sys_svc/gfh/public/br_GFH_parser.c 
      SRC_LIST +=   service/sys_svc/gfh/public/br_GFH_file_info.c 
      SRC_LIST +=   service/sys_svc/cbr/src/cbr.c 
      SRC_LIST +=   service/sys_svc/cbr/src/cbr_util.c 
      SRC_LIST +=   service/sys_svc/ftl/src/FTL.c 
      SRC_LIST +=   service/sys_svc/dcmgr/src/dcmgr.c
else ifneq ($(filter __SV5X_ENABLED__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   service/sys_svc/cbr/src/cbr.c 
      SRC_LIST +=   service/sys_svc/cbr/src/cbr_util.c 
      SRC_LIST +=   service/sys_svc/ftl/src/FTL.c 
      SRC_LIST +=   service/sys_svc/gfh/public/br_GFH_parser.c 
      SRC_LIST +=   service/sys_svc/gfh/public/br_GFH_file_info.c 
else
      SRC_LIST +=   service/sys_svc/gfh/public/br_GFH_parser.c 
      SRC_LIST +=   service/sys_svc/gfh/public/br_GFH_file_info.c 	
endif


ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   service/sys_svc/region/src/init_memory_stack.c
endif

ifneq ($(filter __VI_ENABLED__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   service/sys_svc/compression/src/viva.c
endif

ifneq ($(filter __SV5_ENABLED__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   service/sys_svc/gfh/public/maui_GFH_body.c
else ifneq ($(filter __SV5X_ENABLED__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   service/sys_svc/gfh/public/maui_GFH_body.c
endif

ifeq ($(strip $(COMPILER)), GCC)
   ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   service/sys_svc/region/src/stack_gcc.S
      SRC_LIST +=   service/sys_svc/region/src/regioninit_gcc.S 
   endif
else  # RVCT
   ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
      SRC_LIST +=   service/sys_svc/region/src/stack_rvct.S 
      SRC_LIST +=   service/sys_svc/region/src/regioninit_rvct.S 
      SRC_LIST +=   service/sys_svc/region/src/l6478e.s
   endif
endif


ifeq ($(TS_PROFILING),TRUE)
      SRC_LIST +=   service/sys_svc/profile/src/br_time_stamp.c
      SRC_LIST +=   service/sys_svc/profile/src/maui_time_stamp_util.c
      SRC_LIST +=   service/sys_svc/profile/src/time_stamp_timer.c
endif

ifneq ($(filter __LTE_RAT__, $(strip $(MODULE_DEFS))),)
       SRC_LIST +=   service/sys_svc/dspfm_lte/src/dspfm.c
endif

###################################################################
# Define include path lists to INC_DIR
INC_DIR = interface/modem/general \
          service/sst/include \
          $(strip $(PROJDIR))/verno \
          service/ssf/inc \
          service/sss/interface/inc \
          service/security/sds \
          driver/drv/include \
          driver/peripheral/inc \
          driver/storage/flash/fdm/inc \
          driver/sys_drv/cache/inc \
          driver/devdrv/bus/inc \
          driver/devdrv/cirq_v1/inc \
          driver/devdrv/us_counter/inc \
          driver/devdrv/dma/inc \
          driver/devdrv/emi/inc \
          driver/sys_drv/init/inc \
          driver/regbase/inc \
          driver/sys_drv/pmu/inc \
          service/sys_svc/region/inc \
          service/sys_svc/$(BL_PATH)/inc \
          service/sys_svc/dp/inc \
          service/sys_svc/dcmgr/inc \
          service/sys_svc/excep_hdlr/inc \
          service/sys_svc/cbr/inc \
          service/sys_svc/gfh/public \
          service/sys_svc/compression/inc \
          service/sys_svc/profile/inc \
          service/sys_svc/dspfm_lte/inc

###################################################################
# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWORK

COMP_DEFS += $(strip $(PLATFORM))


ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
  ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    ifdef EMMC_BOOTING
      ifeq ($(strip $(EMMC_BOOTING)),NONE)  
        COMP_DEFS += __BL_ENABLE__
      endif
    else
      COMP_DEFS += __BL_ENABLE__
    endif
  endif
endif

ifdef NAND_FLASH_BOOTING
  ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    COMP_DEFS  += _NAND_FLASH_BOOTING_
  endif
endif

ifdef EMMC_BOOTING
  ifneq ($(strip $(EMMC_BOOTING)),NONE)
    COMP_DEFS  += __EMMC_BOOTING__
  endif
endif

ifeq ($(strip $(MCU_DCM)),DCM_ENABLE)
  COMP_DEFS += DCM_ENABLE
endif

ifeq ($(strip $(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
  COMP_DEFS += SINGLE_BANK_SUPPORT
endif

ifeq ($(TS_PROFILING),TRUE)
    COMP_DEFS   +=  __TIME_STAMP__\
                    __TIME_STAMP_UTIL__\
                    __TIME_STAMP_TDMA_TIMER__\
                    __TIME_STAMP_FORCE_ENABLE__
endif

ifneq ($(filter __DSP_IMG_ON_EMI__, $(strip $(CUSTOM_OPTION))),) 
  COMP_DEFS += __DSP_IMG_ON_EMI__
endif
