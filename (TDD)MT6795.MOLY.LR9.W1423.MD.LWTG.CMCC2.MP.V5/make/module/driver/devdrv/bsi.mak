##############################################################################
#                             devdrv/bsi                                     #
##############################################################################
ifneq ($(filter MT6290, $(strip $(MODULE_DEFS))),)
SRC_LIST  += driver/devdrv/bsi/src/drv_bsi.c

SRC_PATH  += driver/devdrv/bsi/src

INC_DIR   += driver/devdrv/bsi/inc
endif
