#FDA
COMP_DEFS += __UBL_NAND_FULL_DRIVER__
COMP_DEFS += FDA_DEBUG

#SPI Driver
ifeq ($(strip $(SERIAL_FLASH_SUPPORT)),TRUE)
SRC_LIST += driver/storage/flash/mtd/src/mtd_dal_spi.c \
                      driver/storage/flash/mtd/src/drv_spi.c \
                      driver/storage/flash/mtd/src/flash_mtd.c \
                      driver/storage/flash/mtd/src/flash_disk.c \
                      driver/storage/flash/mtd/src/flash_cfi.c \
                      custom/driver/common/custom_flash.c \
                      custom/driver/common/combo_flash_nor.c \
                      custom/driver/common/combo_flash_init.c
endif

INC_DIR +=  service/sys_svc/bootloader_fda/inc	\
			service/sys_svc/bootloader_fda/inc/hif	\
			service/sys_svc/bootloader_fda/inc/hif/u3dev

SRC_LIST += service/sys_svc/bootloader_fda/src/fda_main.c \
			service/sys_svc/bootloader_fda/src/hif/u3dev/brom_acm_drv.c \
			service/sys_svc/bootloader_fda/src/hif/u3dev/brom_i2c.c \
			service/sys_svc/bootloader_fda/src/hif/u3dev/brom_u3_drv.c \
			service/sys_svc/bootloader_fda/src/hif/u3dev/brom_usb_drv.c \
			service/sys_svc/bootloader_fda/src/hif/brom_efuse_drv.c \
			service/sys_svc/bootloader_fda/src/hif/brom_gpt_drv.c \
			service/sys_svc/bootloader_fda/src/hif/brom_bm.c \
			service/sys_svc/bootloader_fda/src/fda_usb_drv.c \
			service/sys_svc/bootloader_fda/src/fda_command.c \
			driver/devdrv/rstctl/src/dcl_rstctl.c \
			driver/devdrv/boot_init/src/drv_boot_init.c
#if FDA is sent from host, need to add DA header, and change RegionList.csv
ifeq ($(filter $(strip $(COMP_DEFS)),__FDA_FLASH_BOOT__),)
SRC_LIST += service/sys_svc/bootloader_fda/src/fda_head.c
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
