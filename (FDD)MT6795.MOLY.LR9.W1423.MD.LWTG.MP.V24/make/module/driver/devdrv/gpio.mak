##############################################################################
#                             devdrv/gpio                                     #
##############################################################################
SRC_LIST  += driver/devdrv/gpio/src/dcl_gpio.c \
             driver/devdrv/gpio/src/drv_gpio.c \
             driver/devdrv/gpio/src/gpio_setting.c \

SRC_PATH  += driver/devdrv/gpio/src

INC_DIR   += driver/devdrv/gpio/inc \
	     $(strip $(PROJDIR))/custom/driver/drv_gen

