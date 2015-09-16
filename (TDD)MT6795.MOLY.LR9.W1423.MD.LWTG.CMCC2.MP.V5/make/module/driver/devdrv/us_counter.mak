##############################################################################
#                             devdrv/FRC                                     #
##############################################################################
ifeq ($(strip $(PLATFORM)),MT6752)
  ifdef MDSYS
    ifeq ($(strip $(MDSYS)),MD2)
      DEVDRV_PLATFORM_FRC = DEVDRV_WR8_FRC
    endif
  endif
endif

ifneq ($(strip $(DEVDRV_PLATFORM_FRC)),DEVDRV_WR8_FRC)
SRC_LIST  += driver/devdrv/us_counter/src/uscounter_v2.c

SRC_PATH  += driver/devdrv/us_counter/src

INC_DIR   += driver/devdrv/us_counter/inc \
    driver/sleep_drv/public/inc

else
SRC_LIST  += driver/devdrv/us_counter/src/uscounter_v1.c

SRC_PATH  += driver/devdrv/us_counter/src

INC_DIR   += driver/devdrv/us_counter/inc
endif


