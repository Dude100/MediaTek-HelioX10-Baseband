##############################################################################
#                             devdrv/mdipc                                   #
##############################################################################
ifneq ($(filter __CC_IRQ_EXIST__, $(strip $(MODULE_DEFS))),)
SRC_LIST  += driver/devdrv/mdipc/src/cc_irq.c \
             driver/devdrv/mdipc/src/md_pccif.c \
             driver/devdrv/mdipc/src/cc_irq_msg.c \
             driver/devdrv/mdipc/src/cc_sys_comm.c
#             driver/devdrv/mdipc/src/cc_irq_ut.c

SRC_PATH  += driver/devdrv/mdipc/src
INC_DIR   += driver/devdrv/mdipc/inc \
             interface/driver/devdrv/mdipc
endif
