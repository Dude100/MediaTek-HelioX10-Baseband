#
# Define source file lists to SRC_LIST
#
SRC_LIST = middleware/hif/ipcore/src/ipc_task.c \
           middleware/hif/ipcore/src/ipc_if.c \
           middleware/hif/ipcore/src/ipc_session.c \
           middleware/hif/ipcore/src/ipc_filter.c \
           middleware/hif/ipcore/src/ipc_dhcp_adp.c \
           middleware/hif/ipcore/src/ipc_notify.c \
           middleware/hif/ipcore/src/ipc_utils.c

# Packet Filter Manager file lists
SRC_LIST += middleware/hif/ipcore/src/pfm_garbage_filter.c \
			middleware/hif/ipcore/src/pfm_if.c

ifneq ($(filter ATEST_SYS_IPCORE, $(strip $(MODULE_DEFS))),)
SRC_LIST += middleware/hif/ipcore/src/ipc_ut.c
endif

#
#  Define include path lists to INC_DIR
#
INC_DIR = middleware/hif/interface \
          middleware/hif/ipcore/include \
          interface/modem/upcm

#
# Define the specified compile options to COMP_DEFS
#
COMP_DEFS =

ifeq ($(strip $(LTM_EPDCP_SIMULATION_SUPPORT)), TRUE)
COMP_DEFS += __LTM_EPDCP_SIMULATION_SUPPORT__
endif

#
# Define the source file search paths to SRC_PATH
#
SRC_PATH = middleware/hif/ipcore/src
