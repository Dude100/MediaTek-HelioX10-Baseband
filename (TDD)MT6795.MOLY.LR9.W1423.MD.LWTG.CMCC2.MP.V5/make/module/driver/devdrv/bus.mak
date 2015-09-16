##############################################################################
#                             devdrv/bus                                     #
##############################################################################
ifeq ($(strip $(PLATFORM)),MT6752)
    ifeq ($(strip $(MDSYS)),MD2)
      BUSDRV_VERSION = BUSDRV_V1
    endif
endif

ifneq ($(strip $(BUSDRV_VERSION)), BUSDRV_V1)
SRC_LIST  += driver/devdrv/bus/src/bus_drv_v2.c

SRC_PATH  += driver/devdrv/bus/src

INC_DIR   += driver/devdrv/bus/inc

else

SRC_LIST  += driver/devdrv/bus/src/bus_drv_v1.c

SRC_PATH  += driver/devdrv/bus/src

INC_DIR   += driver/devdrv/bus/inc

endif

