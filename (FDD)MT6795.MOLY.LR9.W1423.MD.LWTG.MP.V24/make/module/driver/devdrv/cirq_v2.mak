##############################################################################
#                             devdrv/gpt                                     #
##############################################################################
ifeq ($(filter __ARM7EJ_S__, $(strip $(MODULE_DEFS))),)
SRC_LIST  += driver/devdrv/cirq_v2/src/drv_mdcirq.c \
             driver/devdrv/cirq_v2/src/$(COMPILER)/vic_entry.S
else
SRC_LIST  += driver/devdrv/cirq_v2/src/drv_arm7cirq.c
endif
SRC_LIST  += driver/devdrv/cirq_v2/src/isrentry.c \
             driver/devdrv/cirq_v2/src/$(COMPILER)/irq_gcc.S
SRC_PATH  += driver/devdrv/cirq_v2/src
INC_DIR   += driver/devdrv/cirq_v2/inc

