##############################################################################
#                             devdrv/pll                                     #
##############################################################################

SRC_PATH  += driver/devdrv/pll/src

INC_DIR   += driver/devdrv/pll/inc

ifeq ($(strip $(PLATFORM)),MT6752)
 ifeq ($(strip $(MDSYS)),MD2)
  PLL_SRC_FILES = driver/devdrv/pll/src/pll_mt6752_md2.c
 else
  PLL_SRC_FILES = driver/devdrv/pll/src/pll_mt6752_md1.c
 endif
endif

ifeq ($(strip $(PLL_SRC_FILES)),)
 PLL_SRC_FILES  = driver/devdrv/pll/src/pll.c
endif

SRC_LIST   += $(PLL_SRC_FILES)
