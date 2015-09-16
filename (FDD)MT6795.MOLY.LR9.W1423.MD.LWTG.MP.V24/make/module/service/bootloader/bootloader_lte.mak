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

SRC_LIST +=  \
            service/sys_svc/$(BL_PATH)/src/bl_Cache.c \
            service/sys_svc/$(BL_PATH)/src/bl_Init.c \
            service/sys_svc/$(BL_PATH)/src/bl_FTL.c \
            service/sys_svc/$(BL_PATH)/src/bl_GFH_body.c \
			service/sys_svc/$(BL_PATH)/src/bl_portingfunc.c \
			service/sys_svc/$(BL_PATH)/src/bl_UART.c \
			service/sys_svc/$(BL_PATH)/src/bl_GPT.c \
			service/sys_svc/$(BL_PATH)/src/bl_DBGPRINT.c \
			service/sys_svc/$(BL_PATH)/src/bl_ImageLoader_v5.c \
			service/sys_svc/$(BL_PATH)/src/bl_Main.c \
			$(strip $(BUILDBTLDVERNODIR))/bl_verno.c \
            service/sys_svc/$(BL_PATH)/src/bl_ImageLoaderCommon.c \
            service/sys_svc/$(BL_PATH)/src/bl_cfgctl.c \
            service/sys_svc/$(BL_PATH)/src/bl_topsm.c \
            service/sys_svc/$(BL_PATH)/src/bl_pfb.c \
            service/sys_svc/$(BL_PATH)/src/bl_efuse.c

SRC_LIST    += service/sys_svc/cbr/src/cbr.c \
            service/sys_svc/cbr/src/cbr_util.c			

SRC_LIST += driver/sys_drv/cache/src/mpu.c \
			$(strip $(BUILD_SYSDIR))/custom_blconfig.c \
			service/sys_svc/gfh/public/br_GFH_parser.c \
			service/sys_svc/gfh/public/br_GFH_file_info.c \
			driver/devdrv/pll/src/pll.c \
			driver/devdrv/bsi/src/drv_bsi.c \
			$(call AUTO_MERGE_FILE_CHECK,custom/driver/drv/misc_drv,gpio_drv.c) \
			$(strip $(PROJDIR))/custom/driver/drv_gen/gpio_var.c \
			driver/devdrv/gpio/src/dcl_gpio.c \
			driver/devdrv/gpio/src/drv_gpio.c \
			driver/devdrv/gpio/src/gpio_setting.c \
			driver/devdrv/eint/src/eint_setting_init.c \
			driver/devdrv/eint/src/drv_eint.c \
			driver/devdrv/eint/src/dcl_eint.c \
			$(call AUTO_MERGE_FILE_CHECK,custom/driver/drv/misc_drv,eint_def.c) \
			driver/devdrv/iomux/src/drv_iomux.c \
			driver/devdrv/boot_init/src/bus_init.c \
			driver/devdrv/pdn/src/drvpdn.c \
			driver/devdrv/rstctl/src/drv_rstctl.c \
			driver/devdrv/i2c/src/i2c_pmic.c
			
# Fro PMIC
ifeq ($(strip $(PMIC)),MT6339)
SRC_LIST    += driver/devdrv/pmic/src/dcl_pmic6339_init.c \
               driver/devdrv/pmic/src/dcl_pmic6339.c \
               driver/devdrv/pmic/src/dcl_pmu_common.c \
               $(strip $(BUILD_CODEGENDIR))/pmic_drv.c \
               driver/devdrv/pmic/src/dcl_pmu.c
endif

# For DRAMC auto calibration
SRC_LIST += service/sys_svc/$(BL_PATH)/src/emi/custom_emi.c \
            service/sys_svc/$(BL_PATH)/src/emi/dramc_calib.c \
            service/sys_svc/$(BL_PATH)/src/emi/dramc_dle_calib.c \
            service/sys_svc/$(BL_PATH)/src/emi/dramc_dqs_gw.c \
            service/sys_svc/$(BL_PATH)/src/emi/dramc_rx_calib.c \
            service/sys_svc/$(BL_PATH)/src/emi/dramc_tx_calib.c \
            service/sys_svc/$(BL_PATH)/src/emi/mt_emi.c \
            service/sys_svc/$(BL_PATH)/src/emi/mtk_pll.c

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
			
##############################################################
#  Define include path lists to INC_DIR
##############################################################

INC_DIR = service/sys_svc/$(BL_PATH)/inc \
          service/sys_svc/$(BL_PATH)/inc/emi \
          driver/sys_drv/cache/inc \
          driver/storage/flash/mtd/inc \
          $(strip $(BUILD_CODEGENDIR)) \
          $(strip $(BUILD_SYSDIR)) \
          service/ssf/inc \
          service/sst/include \
          interface/driver/sys_drv \
          service/sss/interface/inc \
          service/sys_svc/cbr/inc \
          service/sys_svc/gfh/public \
          service/sys_svc/profile/inc \
          service/security/sds \
          service/sys_svc/dp/inc \
          driver/devdrv/gpt/inc \
          driver/devdrv/pll/inc/ \
          driver/devdrv/bsi/inc/ \
          driver/devdrv/gpio/inc/ \
          driver/devdrv/common/inc/	\
          driver/devdrv/eint/inc \
          $(strip $(PROJDIR))/custom/driver/drv_gen \
          $(call CUSTOM_FLD_MAPPING,custom/driver/drv/misc_drv) \
          driver/devdrv/iomux/inc \
          driver/sleep_drv/public/inc \
          driver/devdrv/boot_init/inc \
          driver/devdrv/pdn/inc \
          driver/devdrv/pmic/inc \
          driver/devdrv/rstctl/inc \
          driver/devdrv/i2c/inc \
          driver/peripheral/inc \
          driver/devdrv/pfb/inc

