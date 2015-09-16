##############################################################
# Define source file lists to SRC_LIST
##############################################################


ifeq ($(strip $(COMPILER)),GCC)

SRC_LIST = service/sys_svc/bootloader/src/bl_BOOTARM_GCC.S \
            service/sys_svc/bootloader/src/bl_regioninit_gcc.S \
            driver/sys_drv/cache/src/cp15_gcc.S
else
SRC_LIST = service/sys_svc/bootloader/src/bl_BOOTARM_RVCT.S \
            service/sys_svc/bootloader/src/bl_regioninit_RVCT.S \
            driver/sys_drv/cache/src/cp15_RVCT.S
endif

SRC_LIST += \
            service/sys_svc/bootloader/src/bl_Cache.c \
            service/sys_svc/bootloader/src/bl_DBGPRINT.c \
            service/sys_svc/bootloader/src/bl_FTL.c \
            service/sys_svc/bootloader/src/bl_GFH_body.c \
            service/sys_svc/bootloader/src/bl_ImageLoaderCommon.c \
            service/sys_svc/bootloader/src/bl_ImageLoader_v5.c \
            service/sys_svc/bootloader/src/bl_Init.c \
            service/sys_svc/bootloader/src/bl_Main.c \
            service/sys_svc/bootloader/src/bl_NFI.c \
            service/sys_svc/bootloader/src/bl_NFI_V3.c \
            service/sys_svc/bootloader/src/bl_NFI_V31.c \
            service/sys_svc/bootloader/src/bl_portingfunc.c \
            service/sys_svc/bootloader/src/bl_UART.c \
            service/sys_svc/bootloader/src/bl_pdn.c \
            service/sys_svc/bootloader/src/bl_Alg.c \
            $(strip $(BUILDBTLDVERNODIR))/bl_verno.c \
            service/sys_svc/bootloader/src/drv_comm_bl.c \
            service/sys_svc/bootloader/src/lcd_display.c \
            service/sys_svc/bootloader/src/msdc_adap_bl.c \
            service/sys_svc/bootloader/src/msdc_dma_bl.c \
            service/sys_svc/bootloader/src/pmic_adpt_bl.c \
            service/sys_svc/bootloader/src/usbdl_debug_tool.c \
            service/sys_svc/bootloader/src/usbdl_pmu.c \
            service/sys_svc/bootloader/src/usbdl_upll.c \
            service/sys_svc/bootloader/src/usbdl_usb.c \
            service/sys_svc/bootloader/src/usbdl_usbacm_adap.c \
            service/sys_svc/bootloader/src/usbdl_usbacm_drv.c \
            service/sys_svc/bootloader/src/usbdl_usb_drv.c \
            service/sys_svc/bootloader/src/usbdl_usb_resource.c \
            service/sys_svc/gfh/public/br_GFH_parser.c \
            service/sys_svc/gfh/public/br_GFH_file_info.c \
            $(strip $(BUILD_SYSDIR))/custom_blconfig.c \
            custom/driver/common/custom_flash.c \
            $(strip $(BUILD_SYSDIR))/custom_img_config.c \
            $(call AUTO_MERGE_FILE_CHECK,custom/driver/drv/misc_drv,custom_hw_default.c) \
            $(call AUTO_MERGE_FILE_CHECK,custom/driver/drv/misc_drv,gpio_drv.c) \
            $(call AUTO_MERGE_FILE_CHECK,custom/driver/drv/misc_drv,keypad_def.c) \
            $(call AUTO_MERGE_FILE_CHECK,custom/driver/drv/misc_drv,usb_custom.c) \
            driver/peripheral/src/gpio_setting.c \
            driver/peripheral/src/dcl_gpio.c \
            driver/peripheral/src/gpio.c \
            driver/sys_drv/cache/src/cache.c \
            driver/sys_drv/cache/src/mpu.c \
            driver/sys_drv/init/src/init_comm.c \
            driver/peripheral/src/lpwr.c \
            driver/peripheral/src/pwm.c \
            driver/peripheral/src/dcl_rtc.c \
            driver/peripheral/src/rtc.c \
            driver/peripheral/src/f32k_clk.c \
            driver/peripheral/src/dcl_f32k_clk.c \
            driver/md_drv/interface/l1_interface.c
            
            
SRC_LIST    += service/sys_svc/cbr/src/cbr.c \
            service/sys_svc/cbr/src/cbr_util.c

# PMU
SRC_LIST    += driver/peripheral/src/dcl_pmu.c \
           driver/peripheral/src/dcl_pmu_common.c

ifeq ($(strip $(PMIC)),MT6235PMU)
   SRC_LIST    += driver/peripheral/src/dcl_pmu6235.c
endif
ifneq ($(filter MT6236PMU MT6921PMU, $(strip $(PMIC))),)
   SRC_LIST    += driver/peripheral/src/dcl_pmu6236.c
endif
ifeq ($(strip $(PMIC)),MT6253PMU)
   SRC_LIST    += driver/peripheral/src/dcl_pmu6253.c
endif
ifeq ($(strip $(PMIC)),MT6326_CCCI)
   SRC_LIST    += driver/peripheral/src/dcl_pmic6326_ccci.c
endif

ifeq ($(strip $(PMIC)),MT6326)
   SRC_LIST    += driver/peripheral/src/dcl_pmic6326.c \
                driver/peripheral/src/i2c_dual.c
   SRC_LIST +=  $(call AUTO_MERGE_FILE_CHECK,custom/driver/drv/misc_drv,pmic_custom.c)
endif

ifeq ($(strip $(PMIC)),MT6327)
   SRC_LIST    += driver/peripheral/src/dcl_pmic6327.c \
                driver/peripheral/src/dcl_pmic6327_init.c \
                driver/peripheral/src/i2c_pmic.c
   SRC_LIST +=  $(call AUTO_MERGE_FILE_CHECK,custom/driver/drv/misc_drv,pmic_custom.c)
endif

ifeq ($(strip $(PMIC)),MT6251PMU)
   SRC_LIST    += driver/peripheral/src/dcl_pmu6251.c
endif
ifeq ($(strip $(PMIC)),MT6252PMU)
   SRC_LIST    += driver/peripheral/src/dcl_pmu6252.c
endif
ifeq ($(strip $(PMIC)),MT6255PMU)
   SRC_LIST    += driver/peripheral/src/dcl_pmu6255.c \
               driver/peripheral/src/dcl_pmu6255_init.c
endif
ifeq ($(strip $(PMIC)),MT6256PMU)
   SRC_LIST    += driver/peripheral/src/dcl_pmu6256.c \
               driver/peripheral/src/dcl_pmu6256_init.c
endif
ifeq ($(strip $(PMIC)),MT6276PMU)
   SRC_LIST    += driver/peripheral/src/dcl_pmu6276.c
endif
ifeq ($(strip $(PMIC)),MT6573PMU)
   SRC_LIST    += driver/peripheral/src/dcl_pmu6573.c
endif

SRC_LIST +=  $(call AUTO_MERGE_FILE_CHECK,custom/driver/drv/misc_drv,pmu_custom.c)

FILE_EXIST = $(shell $(LIST_DIR) "$(strip $(BUILD_CODEGENDIR))/gpio_var.c"  2>$(DEV_NUL))
ifneq ($(words $(strip $(FILE_EXIST))),0)
  SRC_LIST += $(strip $(BUILD_CODEGENDIR))/gpio_var.c
endif
     
SRC_LIST    += driver/peripheral/src/keypad_bl.c

#FILE_EXIST = $(shell dir $(strip $(BUILD_SYSDIR))\custom_SFI.c  2>/dev/null 2>nul)
#ifneq ($(words $(strip $(FILE_EXIST))),0)
#  SRC_LIST += $(strip $(BUILD_SYSDIR))\custom_SFI.c
#endif

# eMMC driver
ifneq ($(filter __EMMC_BOOTING__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(call AUTO_MERGE_FILE_CHECK,custom/driver/drv/misc_drv,msdc_custom.c) \
              driver/storage/mc/src/msdc.c \
              driver/storage/mc/src/sd.c \
              driver/storage/mc/src/msdc_fake_kal.c \
              driver/storage/mc/src/dcl_memory_card.c \
              driver/storage/mc/src/sd_drv.c \
              driver/storage/mc/src/sd_adap.c
endif


# Add by Kuohong
# NAND driver build condition
# #if ( defined(__NAND_FDM_50__) && (defined(__NFI_VERSION2__)||defined(__NFI_VERSION3_1__)) )
ifneq ($(filter __NAND_FDM_50__, $(strip $(MODULE_DEFS))),)
  ifneq ($(filter __NFI_VERSION2__, $(strip $(MODULE_DEFS))),)
    SRC_LIST    += driver/storage/flash/mtd/src/NAND_DAL.c
    SRC_LIST    += driver/storage/flash/mtd/src/NAND_MTD_FDM50.c
    SRC_LIST    += driver/storage/flash/mtd/src/NAND_DevConfig.c
  else 
     ifneq ($(filter __NFI_VERSION3_1__, $(strip $(MODULE_DEFS))),)
       SRC_LIST    += driver/storage/flash/mtd/src/NAND_DAL.c
       SRC_LIST    += driver/storage/flash/mtd/src/NAND_MTD_FDM50.c
       SRC_LIST    += driver/storage/flash/mtd/src/NAND_DevConfig.c
       ifneq ($(filter __NAND_MDL_APPEND__, $(strip $(MODULE_DEFS))),)
         SRC_LIST += custom/driver/common/combo_flash_init.c
       endif       
     endif
  endif
endif
ifneq ($(filter _NAND_FLASH_BOOTING_, $(strip $(MODULE_DEFS))),)
  ifeq ($(filter __NFI_VERSION3__, $(strip $(MODULE_DEFS))),)
    ifeq ($(filter __NFI_VERSION2__, $(strip $(MODULE_DEFS))),)    
    endif
  endif
else
 ifneq ($(filter __NOR_FLASH_BOOTING__, $(strip $(MODULE_DEFS))),)
  ifeq ($(filter __NFI_VERSION3__, $(strip $(MODULE_DEFS))),)
    ifeq ($(filter __NFI_VERSION2__, $(strip $(MODULE_DEFS))),)    
    endif
  endif 
 endif
endif
# Add by Kuohong

# NOR/SF driver
ifeq ($(filter _NAND_FLASH_BOOTING_, $(strip $(MODULE_DEFS))),)
ifeq ($(filter __EMMC_BOOTING__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += custom/driver/common/combo_flash_init.c \
              custom/driver/common/combo_flash_nor.c \
              driver/storage/flash/mtd/src/flash_mtd_sf_common.c \
              driver/storage/flash/mtd/src/flash_cfi.c \
              driver/storage/flash/mtd/src/flash_disk.c \
              driver/storage/flash/mtd/src/flash_mtd.c \
              driver/storage/flash/mtd/src/flash_mtd_sf_dal.c \
              driver/storage/flash/mtd/src/flash_mtd_pf_dal.c \
              driver/storage/flash/mtd/src/flash_mtd.amd.c \
              driver/storage/flash/mtd/src/flash_mtd.intel.c \
              driver/storage/flash/mtd/src/bl_STT_SF.c \
              driver/devdrv/emi/src/emi.c
endif
endif

# X-Booting driver
ifneq ($(filter __X_BOOTING__, $(strip $(MODULE_DEFS))),)
  SRC_LIST    += service/sys_svc/bootloader/src/bl_SDIO_drv.c
endif

ifneq ($(filter __SV5_ENABLED__,$(strip $(MODULE_DEFS))),)
  SRC_LIST    += service/sys_svc/bootloader/src/bl_GFH_body.c \
              service/sys_svc/bootloader/src/bl_ImageLoader_v5.c
endif

##############################################################
#  Define include path lists to INC_DIR
##############################################################
INC_DIR = service/sys_svc/bootloader/inc \
          driver/sys_drv/cache/inc \
          driver/drv/include \
          driver/storage/flash/mtd/inc \
          driver/storage/flash/fdm/inc \
          driver/storage/mc/inc \
          driver/dp_engine/che/include \
          $(strip $(BUILD_CODEGENDIR)) \
          $(strip $(BUILD_SYSDIR)) \
          service/sss/interface/inc \
          service/sst/include \
          service/fs/Efs/include \
          service/fs/fat/include \
          interface/service/fs \
          service/sys_svc/cbr/inc \
          service/sys_svc/gfh/public \
          service/sys_svc/profile/inc \
          driver/peripheral/inc \
          driver/storage/mc/inc \
          driver/dsp_ram \
          service/security/sds \
          driver/connectivity/usb_class/include \
          interface/driver/peripheral \
          service/sys_svc/dp/inc \
          driver/connectivity/sdio_device_boot/inc
