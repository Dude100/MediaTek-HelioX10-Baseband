##############################################################################
#                             devdrv/eint                                     #
##############################################################################
SRC_LIST  += driver/devdrv/eint/src/dcl_eint.c \
             driver/devdrv/eint/src/drv_eint.c \
             driver/devdrv/eint/src/eint_setting_init.c

SRC_PATH  += driver/devdrv/eint/src

INC_DIR   += driver/devdrv/eint/inc \
	     $(strip $(PROJDIR))/custom/driver/drv_gen \
	     $(call CUSTOM_FLD_MAPPING,custom/driver/drv/misc_drv)

