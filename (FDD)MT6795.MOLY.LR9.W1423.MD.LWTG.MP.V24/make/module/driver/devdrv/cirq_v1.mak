##############################################################################
#                             devdrv/cirq_v1                                    #
##############################################################################
SRC_LIST  += driver/devdrv/cirq_v1/src/eint.c \
            driver/devdrv/cirq_v1/src/intrCtrl.c \
            driver/devdrv/cirq_v1/src/irq_gcc.S \
            driver/devdrv/cirq_v1/src/isrentry.c \

SRC_PATH  += driver/devdrv/cirq_v1/src

INC_DIR   += driver/devdrv/cirq_v1/inc \
            interface/driver/sys_drv

