##############################################################################
#                             devdrv/eint                                     #
##############################################################################
SRC_LIST  += driver/devdrv/auxadc/src/dcl_adc.c \
             driver/devdrv/auxadc/src/adc.c \
             driver/devdrv/auxadc/src/drv_thermal_protect.c \

SRC_PATH  += driver/devdrv/auxadc/src

INC_DIR   += driver/devdrv/auxadc/inc \
             interface/driver/devdrv/emi \
             interface/driver/devdrv/thermal \
             $(call CUSTOM_FLD_MAPPING,custom/driver/drv/misc_drv)
