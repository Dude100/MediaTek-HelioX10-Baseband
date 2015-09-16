##############################################################################
#                             devdrv/iomux                                     #
##############################################################################
ifeq ($(filter MT6595 MT6752, $(strip $(MODULE_DEFS))),)
SRC_LIST  += driver/devdrv/iomux/src/drv_iomux.c\
						$(strip $(PROJDIR))/custom/driver/drv_gen/iomux_drv.c

SRC_PATH  += driver/devdrv/iomux/src \
						$(strip $(PROJDIR))/custom/driver/drv_gen

INC_DIR   += driver/devdrv/iomux/inc \
						$(strip $(PROJDIR))/custom/driver/drv_gen
endif						 

