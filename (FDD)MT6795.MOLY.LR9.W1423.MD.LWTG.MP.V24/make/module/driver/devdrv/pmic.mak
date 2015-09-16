##############################################################################
#                             devdrv/pmic                                    #
##############################################################################
SRC_LIST  += driver/devdrv/pmic/src/dcl_pmu.c \
             driver/devdrv/pmic/src/dcl_pmu_common.c \

ifeq ($(strip $(PMIC)),MT6339)
COMP_DEFS += MT6339
SRC_LIST    += driver/devdrv/pmic/src/dcl_pmic6339.c \
	driver/devdrv/pmic/src/dcl_pmic6339_init.c \

INC_DIR   += driver/devdrv/bsi/inc

endif

MT6331_MT6332_COMPILER_FILTER_LIST = MT6331_PLUS_MT6332 MT6331 MT6332

ifneq ($(filter $(MT6331_MT6332_COMPILER_FILTER_LIST),$(PMIC)),)
COMP_DEFS += DRV_PMIC_WRAP_6595_REG DRV_PMIC_WRAP_V2
SRC_LIST    += driver/devdrv/pmic/src/dcl_pmic6331_32.c
  ifeq ($(strip $(PMIC)),MT6331)
        SRC_LIST    += driver/devdrv/pmic/src/dcl_pmic6331_init.c  
  endif
  ifeq ($(strip $(PMIC)),MT6332)
        SRC_LIST    += driver/devdrv/pmic/src/dcl_pmic6332_init.c  
  endif
  ifeq ($(strip $(PMIC)),MT6331_PLUS_MT6332)
        SRC_LIST    += driver/devdrv/pmic/src/dcl_pmic6331_init.c \
                       driver/devdrv/pmic/src/dcl_pmic6332_init.c
  endif
INC_DIR   += driver/devdrv/pmic_wrap/inc

endif

ifeq ($(strip $(PMIC)),MT6325)
COMP_DEFS += MT6325 DRV_PMIC_WRAP_6752_REG DRV_PMIC_WRAP_V2
SRC_LIST    += driver/devdrv/pmic/src/dcl_pmic6325.c \
               driver/devdrv/pmic/src/dcl_pmic6325_init.c  
INC_DIR   += driver/devdrv/pmic_wrap/inc

endif

SRC_PATH  += driver/devdrv/pmic/src

INC_DIR   += driver/devdrv/pmic/inc

