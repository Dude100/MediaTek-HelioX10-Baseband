# Define source file lists to SRC_LIST
# flash_mtd.c is necessary for L1 to call NOR_GetReturnReadyLatency
SRC_LIST = driver/storage/flash/mtd/src/flash_mtd.c

ifeq ($(strip $(SERIAL_FLASH_SUPPORT)),TRUE)
    SRC_LIST += driver/storage/flash/mtd/src/mtd_dal_spi.c \
                	     driver/storage/flash/mtd/src/drv_spi.c
    ifeq ($(strip $(FLASH_TEST_SELECT)),NOR_FLASH)
      SRC_LIST    += driver/storage/flash/mtd/src/flash_mtd_sf_ut.c
    endif
endif

# NOR/SF driver
ifeq ($(filter _NAND_FLASH_BOOTING_, $(strip $(MODULE_DEFS))),)
ifeq ($(filter __EMMC_BOOTING__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += \
              driver/storage/flash/mtd/src/flash_mtd.ramdisk.c \
              driver/storage/flash/mtd/src/flash_cfi.c \
              driver/storage/flash/mtd/src/flash_disk.c \
              driver/storage/flash/mtd/src/flash_mtd_pf_dal.c \
              driver/storage/flash/mtd/src/flash_mtd.amd.c \
              driver/storage/flash/mtd/src/flash_mtd.intel.c
  ifneq ($(filter __SERIAL_FLASH_EN__, $(strip $(MODULE_DEFS))),)
    #SRC_LIST += \
                #driver/storage/flash/mtd/src/flash_mtd_sf_common.c \
                #driver/storage/flash/mtd/src/flash_mtd_sf_dal.c \
                #driver/storage/flash/mtd/src/flash_mtd_sf_ut.c
  endif
endif
endif

ifeq ($(strip $(NAND_SUPPORT)),TRUE)
# NAND driver build condition
SRC_LIST    += driver/storage/flash/mtd/src/NAND_MTD.c \
            driver/storage/flash/mtd/src/flash_user.c
endif
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
       SRC_LIST    += driver/storage/flash/mtd/src/NAND_MTD_DRV.c
     endif
  endif
endif

#  RAM Disk for smartphone modem-only projects
ifneq ($(filter __FS_RAMDISK__, $(strip $(MODULE_DEFS))),)
  SRC_LIST    += driver/storage/flash/mtd/src/flash_mtd.ramdisk.c
endif

#  Define include path lists to INC_DIR
INC_DIR = service/sss/interface/inc \
          driver/drv/include \
          service/sst/include \
          driver/storage/flash/fdm/inc \
          driver/storage/flash/mtd/inc \
          driver/peripheral/inc \
          service/fs/common/include \
          service/sys_svc/dp/inc \
          service/sys_svc/gfh/public \
          driver/devdrv/common/inc

# Define the specified compile options to COMP_DEFS
COMP_DEFS = 

# Define the source file search paths to SRC_PATH
SRC_PATH = driver/storage/flash/mtd/src

