##############################################################
# Define mini bootloader internal configuration
##############################################################
CRYPTO_SHARED_DRV_PLATFORM = MT6255 MT6922 MT6250
NFI_SHARED_DRV_PLATFORM    = MT6255 MT6922

ifneq ($(filter __EMMC_BOOTING__, $(strip $(MODULE_DEFS))),)
CRYPTO_SHARED_DRV_PLATFORM += MT6276
endif

##############################################################
# Define bootloader folder path
##############################################################
ifneq ($(filter MT6290, $(strip $(MODULE_DEFS))),)
BL_PATH = bootloader_lte
else
BL_PATH = bootloader
endif

ifneq ($(filter MT6290, $(strip $(MODULE_DEFS))),)
include make/module/service/bootloader/bootloader_lte.mak
else
include make/module/service/bootloader/bootloader_23g.mak
endif

##############################################################
# Define the specified compile options to COMP_DEFS
##############################################################
COMP_DEFS = BL_ECC_ENABLE \
            __UBL__ \
            __MINI_BOOTLOADER__ \
            USBACM_TX_WITHOUT_DMA \
            BL_ENABLE \
            __CP_DEFINED_ALL_CONTEXT__ \
            __CP_DEFINED_WORKING_BUF__ \
            __CRYPTO_LIB__ \
            __CRYPTO_SCHEME__

ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
  COMP_DEFS += __MD_BOOTLOADER__
endif

ifneq ($(strip $(PLATFORM)),MT6251)
ifneq ($(strip $(PACKAGE_SEG)),32_32_SEG)
  COMP_DEFS += BL_DEBUG
endif
endif

ifneq ($(filter $(strip $(PLATFORM)),$(SV5_PLATFORM)),)
  COMP_DEFS += __SV5_ENABLED__
endif

COMP_DEFS += $(strip $(PLATFORM))

ifneq ($(filter $(strip $(PLATFORM)),$(ARM9_PLATFORM)),)
  COMP_DEFS += ARM9_MMU
endif

ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
  COMP_DEFS  += _NAND_FLASH_BOOTING_
endif
    
ifdef EMMC_BOOTING
  ifneq ($(strip $(EMMC_BOOTING)),NONE)
    COMP_DEFS  += __EMMC_BOOTING__
  endif
endif

ifeq ($(strip $(FLASH_DRV_IN_BL)),NAND)
  COMP_DEFS  += __NAND_DRV_IN_BL__
  COMP_DEFS  += _NAND_FLASH_BOOTING_
  COMP_DEFS  += NAND_SUPPORT
endif
ifeq ($(strip $(FLASH_DRV_IN_BL)),SF)
  COMP_DEFS  += __SF_DRV_IN_BL__
endif
ifeq ($(strip $(FLASH_DRV_IN_BL)),EMMC)
  COMP_DEFS  += __EMMC_DRV_IN_BL__
  COMP_DEFS  += __EMMC_BOOTING__
endif
ifeq ($(strip $(FLASH_DRV_IN_BL)),NOR)
  COMP_DEFS  += __NOR_DRV_IN_BL__
endif

ifdef USB_DOWNLOAD_IN_BL
  ifneq ($(strip $(USB_DOWNLOAD_IN_BL)),NONE)
    COMP_DEFS += __USB_DOWNLOAD__
    ifeq ($(strip $(USB_DOWNLOAD_IN_BL)),SECURE)
      COMP_DEFS += __SECURE_USB_DOWNLOAD__
    endif
  endif
endif

ifdef IC_TEST_TYPE
  ifneq ($(strip $(IC_TEST_TYPE)),NONE)
    COMP_DEFS += __SKIP_VERSION_CHECK_FOR_BTMT__
  endif
endif

ifdef CRYPTO_SHARED_DRV_PLATFORM
  ifneq ($(filter $(strip $(PLATFORM)), $(strip $(CRYPTO_SHARED_DRV_PLATFORM))),)
    COMP_DEFS += __CRYPTO_SHARED_DRV__
  endif
endif

ifdef NFI_SHARED_DRV_PLATFORM
  ifneq ($(filter $(strip $(PLATFORM)), $(strip $(NFI_SHARED_DRV_PLATFORM))),)
    COMP_DEFS += __NFI_SHARED_DRV__
  endif
endif

# TS_PROFILING := TRUE
ifeq ($(TS_PROFILING),TRUE)

COMP_DEFS += \
             __TIME_STAMP__ \
             __TIME_STAMP_UTIL__ \
             __TIME_STAMP_FRC_TIMER__ \
             __TIME_STAMP_FORCE_ENABLE__

COMP_DEFS += BL_DEBUG

SRC_LIST    += service/sys_svc/$(BL_PATH)/src/bl_time_stamp_util.c \
            service/sys_svc/$(BL_PATH)/src/bl_frc.c \
            service/sys_svc/profile/src/br_time_stamp.c \
            service/sys_svc/profile/src/time_stamp_timer.c

endif

# SLT
ifeq ($(strip $(IC_TEST_TYPE)),MT6290_SLT_LOADER)

INC_DIR += service/sys_svc/bootloader_slt/inc	\
			driver/devdrv/rstctl/inc	\
			driver/devdrv/gpio/inc		\
			driver/drvtest/slt/inc

SRC_LIST += service/sys_svc/bootloader_slt/src/bl_slt_ImageLoader_v5.c \
			service/sys_svc/bootloader_slt/src/bl_slt_Init.c \
			service/sys_svc/bootloader_slt/src/slt_emi.c \
			service/sys_svc/bootloader_slt/src/slt_dramc.c	\
			service/sys_svc/bootloader_slt/src/slt_efuse.c	\
			service/sys_svc/bootloader_slt/src/slt_uart.c	\
			driver/devdrv/rstctl/src/drv_rstctl.c	\
			driver/devdrv/gpio/src/dcl_gpio.c	\
			driver/devdrv/gpio/src/drv_gpio.c	\
			driver/devdrv/gpio/src/gpio_setting.c	\
			driver/drvtest/slt/src/slt_tool_drv.c

COMP_DEFS += __SLT_TOOL_SUPPORT__
endif

#FDA
ifeq ($(strip $(USB_FW_DL_SUPPORT)),TRUE)
include make/module/service/bootloader/bootloader_fda.mak
endif
