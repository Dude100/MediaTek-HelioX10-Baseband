##############################################################
# Define source file lists to SRC_LIST
##############################################################


ifeq ($(strip $(COMPILER)),GCC)

SRC_LIST = service/sys_svc/$(BL_PATH)/src/bl_BOOTARM_GCC.S \
            service/sys_svc/$(BL_PATH)/src/bl_regioninit_gcc.S \
            driver/sys_drv/cache/src/cp15_gcc.S
else
SRC_LIST = service/sys_svc/$(BL_PATH)/src/bl_BOOTARM_RVCT.S \
            service/sys_svc/$(BL_PATH)/src/bl_regioninit_RVCT.S \
            driver/sys_drv/cache/src/cp15_RVCT.S
endif

SRC_LIST += service/sys_svc/$(BL_PATH)/src/bl_wdt.c \
			service/sys_svc/$(BL_PATH)/src/bl_imgtbl.c \
			service/sys_svc/$(BL_PATH)/src/bl_share_param.c \
            service/sys_svc/$(BL_PATH)/src/bl_trc_api.c \
            service/sys_svc/$(BL_PATH)/src/bl_fake_api.c

SRC_LIST += \
			service/sys_svc/$(BL_PATH)/src/bl_Init.c \
			service/sys_svc/$(BL_PATH)/src/bl_Main.c \
			service/sys_svc/$(BL_PATH)/src/bl_GFH_body.c \
			service/sys_svc/gfh/public/br_GFH_parser.c \
			service/sys_svc/gfh/public/br_GFH_file_info.c \
			service/sys_svc/$(BL_PATH)/src/bl_FTL.c \
			service/sys_svc/$(BL_PATH)/src/bl_DBGPRINT.c \
			service/sys_svc/$(BL_PATH)/src/bl_UART.c \
			service/sys_svc/$(BL_PATH)/src/bl_cfgctl.c \
			service/sys_svc/$(BL_PATH)/src/bl_efuse.c \
			service/sys_svc/$(BL_PATH)/src/bl_GPT.c \
			service/sys_svc/$(BL_PATH)/src/bl_topsm.c \
			$(strip $(BUILDBTLDVERNODIR))/bl_verno.c \
			$(strip $(BUILD_SYSDIR))/custom_blconfig.c \
			service/sys_svc/$(BL_PATH)/src/bl_portingfunc.c \
			service/sys_svc/$(BL_PATH)/src/bl_ImageLoader_v5.c \
			service/sys_svc/$(BL_PATH)/src/bl_ImageLoaderCommon.c \
			service/sys_svc/$(BL_PATH)/src/bl_Cache.c \
			service/sys_svc/$(BL_PATH)/src/bl_Alg.c \
			driver/devdrv/pll/src/pll.c
            
SRC_LIST    += service/sys_svc/cbr/src/cbr.c \
            service/sys_svc/cbr/src/cbr_util.c

# NAND driver 
ifneq ($(filter _NAND_FLASH_BOOTING_, $(strip $(MODULE_DEFS))),)
	SRC_LIST    += driver/storage/flash/mtd/src/NAND_DAL.c
	SRC_LIST    += driver/storage/flash/mtd/src/NAND_MTD_FDM50.c
	SRC_LIST    += driver/storage/flash/mtd/src/NAND_DevConfig.c
	SRC_LIST    += driver/storage/flash/mtd/src/NAND_MTD_DRV.c
endif					
			
# X-Booting driver
ifneq ($(filter __X_BOOTING__, $(strip $(MODULE_DEFS))),)
  SRC_LIST    += service/sys_svc/$(BL_PATH)/src/bl_xboot.c \
                 service/sys_svc/$(BL_PATH)/src/brom_sdio_drv.c \
                 service/sys_svc/$(BL_PATH)/src/brom_bm.c
endif			

#USB driver
ifeq ($(strip $(HIF_USB30_SUPPORT)),TRUE)
SRC_LIST    += service/sys_svc/$(BL_PATH)/src/hif/brom_acm_drv.c
SRC_LIST    += service/sys_svc/$(BL_PATH)/src/hif/brom_u3_drv.c
SRC_LIST    += service/sys_svc/$(BL_PATH)/src/hif/brom_usb_drv.c
SRC_LIST    += service/sys_svc/$(BL_PATH)/src/brom_bm.c
endif

ifdef USB_DOWNLOAD_IN_BL
  ifneq ($(strip $(USB_DOWNLOAD_IN_BL)),NONE)
    SRC_LIST	+= service/sys_svc/$(BL_PATH)/src/bl_usb.c
  endif
endif  

#Driver for boot init setting			   
SRC_LIST  += driver/devdrv/boot_init/src/drv_boot_init.c \
             driver/devdrv/boot_init/src/abm_init.c \
             driver/devdrv/boot_init/src/arm7_init.c \
             driver/devdrv/boot_init/src/bootrom_init.c \
             driver/devdrv/boot_init/src/busmon_init.c \
             driver/devdrv/boot_init/src/ca7_init.c \
             driver/devdrv/boot_init/src/ccif_init.c \
             driver/devdrv/boot_init/src/cldma_init.c \
             driver/devdrv/boot_init/src/cr4pcmon_init.c \
             driver/devdrv/boot_init/src/dbgsys_init.c \
             driver/devdrv/boot_init/src/ehpi_master_init.c \
             driver/devdrv/boot_init/src/ehpi_slave_init.c \
             driver/devdrv/boot_init/src/gdma_init.c \
             driver/devdrv/boot_init/src/gpio_init.c \
             driver/devdrv/boot_init/src/gptm_init.c \
             driver/devdrv/boot_init/src/i2c_init.c \
             driver/devdrv/boot_init/src/ipsec_init.c \
             driver/devdrv/boot_init/src/led_init.c \
             driver/devdrv/boot_init/src/ltel2_init.c \
             driver/devdrv/boot_init/src/mdcaif_init.c \
             driver/devdrv/boot_init/src/mdcirq_init.c \
             driver/devdrv/boot_init/src/msdc_init.c \
             driver/devdrv/boot_init/src/nfi_init.c \
             driver/devdrv/boot_init/src/nic_init.c \
             driver/devdrv/boot_init/src/nli_init.c \
             driver/devdrv/boot_init/src/pfc_init.c \
             driver/devdrv/boot_init/src/rtc_init.c \
             driver/devdrv/boot_init/src/sdio_init.c \
             driver/devdrv/boot_init/src/spi_init.c \
             driver/devdrv/boot_init/src/trace_init.c \
             driver/devdrv/boot_init/src/u2_init.c \
             driver/devdrv/boot_init/src/u3_init.c \
             driver/devdrv/boot_init/src/uart_init.c \
             driver/devdrv/boot_init/src/usim_init.c \
             driver/devdrv/pdn/src/drvpdn.c
			 
##############################################################
#  Define include path lists to INC_DIR
##############################################################
INC_DIR = service/sys_svc/$(BL_PATH)/inc \
          service/sys_svc/$(BL_PATH)/inc/hif \
          driver/sys_drv/cache/inc \
          driver/storage/flash/mtd/inc \
          $(strip $(BUILD_CODEGENDIR)) \
          $(strip $(BUILD_SYSDIR)) \
          service/sss/interface/inc \
          service/sst/include \
          service/sys_svc/cbr/inc \
          service/sys_svc/gfh/public \
          service/sys_svc/profile/inc \
          service/security/sds \
          service/sys_svc/dp/inc \
          driver/connectivity/sdio_device_boot/inc \
          driver/devdrv/gpt/inc \
          driver/devdrv/pdn/inc \
          driver/devdrv/bsi/inc \
          driver/devdrv/boot_init/inc \
          driver/devdrv/pfb/inc

# Driver for temperary soludion of META mode
INC_DIR    += driver/devdrv/iomux/inc/ \
               driver/devdrv/gpio/inc/ \
	       driver/devdrv/common/inc/
