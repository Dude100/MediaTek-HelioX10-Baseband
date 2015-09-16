# Define source file lists to SRC_LIST
SRC_LIST = service/config/src/hal/syscomp_config.c \
           service/config/src/hal/task_config.c \
           service/config/src/hal/stack_config.c \
           service/config/src/hal/ctrl_buff_pool.c

#  Define include path lists to INC_DIR
INC_DIR = driver/peripheral/inc \
          service/kal/adaptation/include \
          interface/service/dhl\
          service/sys_svc/dp/inc

# Define the specified compile options to COMP_DEFS
COMP_DEFS = 

ifeq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
  ifeq ($(strip $(L1_3GSOLUTION)),MTK_UL1_FDD)
    # special for AST projects
    COMP_DEFS += __UL1_ON_MNT__
  endif
endif

# Define the source file search paths to SRC_PATH
SRC_PATH = service/config/src/hal
