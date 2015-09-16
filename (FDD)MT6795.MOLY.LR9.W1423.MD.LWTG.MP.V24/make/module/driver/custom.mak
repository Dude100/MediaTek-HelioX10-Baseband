AUTO_MERGE_FOLDER = custom/driver/audio custom/driver/drv/misc_drv

INC_DIR =
COMP_DEFS =
FOLDER_LIST =

# source file folder for xgen
GEN_FOLDER_LIST = $(strip $(BUILD_SYSDIR)) $(strip $(BUILD_CODEGENDIR))
INC_DIR += $(strip $(BUILD_SYSDIR)) $(strip $(BUILD_CODEGENDIR))


# Define source file lists to SRC_LIST
# Define source file folder to FOLDER_LIST

#driver
ifneq ($(strip $(TEST_LOAD_TYPE)),BASIC)
  FOLDER_LIST += $(call CUSTOM_FLD_MAPPING,custom/driver/audio)
endif

FOLDER_LIST += custom/driver/common \
               custom/driver/drv/ast

FOLDER_LIST += $(call CUSTOM_FLD_MAPPING,custom/driver/drv/misc_drv) \
               
ifneq ($(strip $(TEST_LOAD_TYPE)),BASIC)
  ifneq ($(strip $(TEST_LOAD_TYPE)),L1S)
    ifdef GPS_SUPPORT
      ifneq ($(strip $(GPS_SUPPORT)),NONE)
        FOLDER_LIST += $(call CUSTOM_FLD_MAPPING,custom/driver/drv/gps)
        INC_DIR += $(call CUSTOM_FLD_MAPPING,custom/driver/drv/gps)
      endif
    endif
  endif
endif

#middleware
FOLDER_LIST += custom/middleware/common
INC_DIR     += custom/middleware/common/usbc_custom_mode
ifneq ($(strip $(TEST_LOAD_TYPE)),BASIC)
  FOLDER_LIST += $(call CUSTOM_FLD_MAPPING,custom/middleware/meta)
endif

ifneq ($(filter __KTEST__,$(MODULE_DEFS)),)
  INC_DIR    += middleware/mtkdebug/ktest
endif

#modem
FOLDER_LIST += $(call CUSTOM_FLD_MAPPING,custom/modem/ps) \
               custom/modem/l1_rf/$(strip $(RF_MODULE)) \
               custom/modem/common/atci/src \
               custom/modem/common/ps \
               custom/modem/common

#Multi-Mode RF
ifdef MM_RF_MODULE
  ifneq ($(strip $(MM_RF_MODULE)),NONE)
    FOLDER_LIST += custom/modem/mml1_rf/$(strip $(MM_RF_MODULE))
    INC_DIR += custom/modem/mml1_rf/$(strip $(MM_RF_MODULE))
  endif
endif

ifdef UMTS_RF_MODULE
  ifneq ($(strip $(UMTS_RF_MODULE)),NONE)
    FOLDER_LIST += custom/modem/ul1_rf/$(strip $(UMTS_RF_MODULE))
    INC_DIR += custom/modem/ul1_rf/$(strip $(UMTS_RF_MODULE))
  endif
endif

ifdef UMTS_TDD128_RF_MODULE
  ifneq ($(strip $(UMTS_TDD128_RF_MODULE)),NONE)
    FOLDER_LIST += custom/modem/tl1_rf/$(strip $(UMTS_TDD128_RF_MODULE))
    INC_DIR += custom/modem/tl1_rf/$(strip $(UMTS_TDD128_RF_MODULE))
  endif
endif

ifdef LTE_RF_MODULE
  ifneq ($(strip $(LTE_RF_MODULE)),NONE)
    FOLDER_LIST += custom/modem/el1_rf/$(strip $(LTE_RF_MODULE))
    INC_DIR += custom/modem/el1_rf/$(strip $(LTE_RF_MODULE))
  endif
endif

ifeq ($(strip $(call Upper,$(UE_SIMULATOR))),TRUE)
    INC_DIR += modem/gl1/l1_dm/common \
               modem/gl1/l1_dm/interface \
               modem/gl1/l1_dm/l1c \
               modem/gl1/l1_dm/l1d \
               modem/gl1/l1_dm/l1d_ext \
               modem/interface/l1/inner \
               modem/md_sm/l1sm \
               modem/md_sm/common/l1sm
endif

#service
ifeq ($(strip $(TST_SUPPORT)), TRUE)
FOLDER_LIST += custom/service/tst
endif
FOLDER_LIST += custom/service/fs \
               custom/service/nvram \
               custom/service/common \
               $(strip $(PROJDIR))/nvram_auto_gen

## 
AUTO_MERGE_TMP := $(foreach DIR,$(AUTO_MERGE_FOLDER),$(if $(filter $(DIR)/_Default_BB/$(strip $(PLATFORM)) $(call CUSTOM_FLD_MAPPING,$(DIR)),$(FOLDER_LIST)),$(DIR),))

SRC_LIST += $(foreach DIR,$(AUTO_MERGE_TMP), \
  $(subst /,/,$(foreach file,$(wildcard $(DIR)/_Default_BB/$(strip $(PLATFORM))/*.c) $(wildcard $(DIR)/_Default_BB/$(strip $(PLATFORM))/*.cpp),$(if $(wildcard $(call CUSTOM_FLD_MAPPING,$(DIR))/$(notdir $(file))),,$(file))) $(wildcard $(call CUSTOM_FLD_MAPPING,$(DIR))/*.c) $(wildcard $(call CUSTOM_FLD_MAPPING,$(DIR))/*.cpp)) \
)

FOLDER_LIST := $(filter-out $(foreach DIR,$(AUTO_MERGE_TMP),$(DIR)/_Default_BB/$(strip $(PLATFORM)) $(call CUSTOM_FLD_MAPPING,$(DIR))),$(FOLDER_LIST))

FOLDER_LIST += $(GEN_FOLDER_LIST)

SRC_LIST += $(foreach DIR,$(FOLDER_LIST), \
  $(foreach FILE,$(wildcard $(DIR)/*.c),$(FILE)) \
)
SRC_LIST += $(foreach DIR,$(FOLDER_LIST), \
  $(foreach FILE,$(wildcard $(DIR)/*.cpp),$(FILE)) \
)
SRC_LIST += $(foreach DIR,$(FOLDER_LIST), \
  $(foreach FILE,$(wildcard $(DIR)/*.s),$(FILE)) \
)
SRC_LIST += $(foreach DIR,$(FOLDER_LIST), \
  $(foreach FILE,$(wildcard $(DIR)/*.dws),$(FILE)) \
)
SRC_LIST += $(foreach DIR,$(FOLDER_LIST), \
  $(foreach FILE,$(wildcard $(DIR)/*.rec),$(FILE)) \
)

# For cgen
ifneq ($(strip $(TEST_LOAD_TYPE)),BASIC)
  ifneq ($(strip $(TEST_LOAD_TYPE)),L1S)
    SRC_LIST += $(BUILD_TSTDIR)/src/tst_file_default_Catcher_filter.c
    SRC_LIST += $(BUILD_TSTDIR)/src/tst_mini_log_default_Catcher_filter.c
  endif
endif

ifeq ($(strip $(DHL_SUPPORT)), TRUE)
SRC_LIST += custom/service/tst/dhl_export_config.c
endif


#only in MoDIS
ifeq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
  MODIS_DIS_FILE := custom_emi.c custom_flash.c usb_custom.c wndrv_configure.c wndrv_rf_ah.c wndrv_rf_maxim.c
  MODIS_DIS_FILE += custom_flash_norfdm5.c afe.c mal1_create.c kbdmain_joystick.c ERS_api.c ERS_sys.s custom_sfi.c
  MODIS_DIS_FILE += combo_flash_init.c combo_flash_nor.c
  SRC_LIST := $(foreach file,$(SRC_LIST),$(if $(filter $(notdir $(call Lower,$(file))),$(call Lower,$(MODIS_DIS_FILE))),,$(file)))
endif

SRC_LIST :=  $(call uniq,$(SRC_LIST))

#  Define include path lists to INC_DIR
ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
  AUDFOLDER = driver/audio/src/v2
else
  AUDFOLDER = driver/audio/src/v1
endif

INC_DIR += driver/btmt/rf_desense


INC_DIR += custom/driver/drv/ast \
           custom/modem/common/ps \
           custom/modem/l1_rf/$(strip $(RF_MODULE)) \
           $(call CUSTOM_FLD_MAPPING,custom/modem/ps) \
           $(call CUSTOM_FLD_MAPPING,custom/middleware/meta)  \
           $(strip $(AUDFOLDER))/inc \
           $(strip $(MODEM_FOLDER))/interface/l4misc \
           $(strip $(MODEM_FOLDER))/interface/l4 \
           $(strip $(MODEM_FOLDER))/l4/include \
           $(strip $(MODEM_FOLDER))/l4/atci/include \
           $(strip $(MODEM_FOLDER))/l4/l4c/include/common \
           $(strip $(MODEM_FOLDER))/l4/l4c/include/proc \
           $(strip $(MODEM_FOLDER))/l4/csm/cc/include \
           $(strip $(MODEM_FOLDER))/l4/uem/include \
           $(strip $(MODEM_FOLDER))/l4/phb/include \
           $(strip $(MODEM_FOLDER))/l4/csm/cc/include \
           $(strip $(MODEM_FOLDER))/l4/csm \
           $(strip $(MODEM_FOLDER))/l4/tcm/etcm/include \
           $(strip $(MODEM_FOLDER))/l4/smsal/include \
           $(strip $(MODEM_FOLDER))/l4/csm/ss/asn1/gen/include \
           $(strip $(MODEM_FOLDER))/l4/smu/include \
           $(strip $(MODEM_FOLDER))/l4/rac/common/include \
           $(strip $(MODEM_FOLDER))/l4/rac/ugrac/include \
           middleware/media/audio/include

ifneq ($(strip $(EUTRAN_MODE_SUPPORT)),NONE)
  INC_DIR += $(strip $(MODEM_FOLDER))/l4/rac/erac/include
endif

INC_DIR += driver/btmt/rf_desense \
           $(strip $(PROJDIR))/verno \
           $(strip $(PROJDIR))/nvram_auto_gen \
           driver/drv/include \
           driver/peripheral/inc \
           driver/storage/flash/mtd/inc \
           driver/storage/flash/fdm/inc \
           driver/connectivity/usb_class/include

INC_DIR    += $(strip $(MODEM_FOLDER))/l4/include \
              service/nvram/include \
              service/fs/common/include \
              service/sys_svc/bootloader/inc \
              service/sys_svc/dp/inc
              

# SV5
INC_DIR    += service/sys_svc/gfh/public \
              service/sss/interface/inc \
              service/sst/include

INC_DIR    += driver/sys_drv/cache/inc

# File System custom file (temporary solution)
INC_DIR    += driver/storage/mc/inc

# ATCI is always needed.
INC_DIR += custom/modem/common/atci/include

ifeq ($(filter __MTK_TARGET__,$(strip $(MODULE_DEFS))),)
  INC_DIR += MoDIS_VC9/drv_sim/include
endif

#INC_DIR    += service/tst/local_inc
# for customize secure
INC_DIR    += interface/service/sys_svc


INC_DIR :=  $(call uniq,$(INC_DIR))



# Define the specified compile options to COMP_DEFS
COMP_DEFS += __UCS2_ENCODING \
            MMI_ON_HARDWARE_P \
            APCS_INTWORK \
            USE_JAM=0 \
            COMPILER_SUPPORTS_LONG=1

ifeq ($(filter __NOR_FLASH_BOOTING__,$(strip $(DEFINES))),)
  ifdef NEED_BUILD_BOOTLOADER
    ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
      ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
        COMP_DEFS += __BL_ENABLE__
        COMP_DEFS += REMAPPING
      endif
    endif
  endif
endif

ifdef USB_DOWNLOAD_IN_BL
  ifneq ($(strip $(USB_DOWNLOAD_IN_BL)),NONE)
    COMP_DEFS += REMAPPING
  endif
endif

ifeq ($(strip $(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
  COMP_DEFS += REMAPPING
endif

ifneq ($(words $(wildcard $(call CUSTOM_FLD_MAPPING,custom/modem/ps)/custom_port_setting.c)), 0)
    COMP_DEFS += __CUSTOMIZED_PORT_SETTING__
endif

INC_DIR += $(strip $(MODEM_FOLDER))/interface/general
INC_DIR += driver/peripheral/inc

