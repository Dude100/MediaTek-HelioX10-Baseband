##############################################################################
#   NOTICE : We have no HW for this IP (lcd) now.                            #
#            But for SW complie request,                                     #
#            temporarily add the 'fake api' to make compile success.         #
##############################################################################

SRC_LIST  += driver/devdrv/lcd/src/wfd_lcd_adapter.c

SRC_PATH  += driver/devdrv/lcd/src

INC_DIR   += driver/devdrv/lcd/inc \
             interface/driver/display/ddv1/ \

COMP_DEFS += 
