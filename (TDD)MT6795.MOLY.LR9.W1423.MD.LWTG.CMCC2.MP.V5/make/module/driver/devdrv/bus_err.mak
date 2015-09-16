##############################################################################
#                             devdrv/bus_err                                     #
##############################################################################


ifneq ($(filter MT6290, $(strip $(MODULE_DEFS))),)

SRC_LIST  += driver/devdrv/bus_err/src/drv_bus_err.c
SRC_PATH  += driver/devdrv/bus_err/src

INC_DIR   += driver/devdrv/bus_err/inc
endif