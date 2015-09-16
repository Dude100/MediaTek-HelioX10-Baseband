##############################################################################
#                             devdrv/pmic_wrap                               #
##############################################################################
PMIC_WRAP_COMPILER_FILTER_LIST = MT6331_PLUS_MT6332 MT6331 MT6332 MT6325

ifneq ($(filter $(PMIC_WRAP_COMPILER_FILTER_LIST),$(PMIC)),)

SRC_LIST  += driver/devdrv/pmic_wrap/src/pmic_wrap.c

SRC_PATH  += driver/devdrv/pmic_wrap/src

INC_DIR   += driver/devdrv/pmic_wrap/inc \
             driver/devdrv/pmic/inc
endif
