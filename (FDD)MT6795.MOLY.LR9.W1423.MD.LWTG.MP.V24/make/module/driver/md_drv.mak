# Define source file lists to SRC_LIST
SRC_LIST = driver/md_drv/interface/l1_interface.c

#  Define include path lists to INC_DIR
INC_DIR =

ifeq ($(strip $(call Upper,$(UE_SIMULATOR))),TRUE)
    INC_DIR += modem/gl1/l1_dm/common \
               modem/gl1/l1_dm/interface \
               modem/gl1/l1_dm/l1c \
               modem/gl1/l1_dm/l1d \
               modem/gl1/l1_dm/l1d_ext \
               modem/interface/l1/gsm \
               modem/interface/l1/inner \
               modem/md_sm/l1sm \
               modem/md_sm/common/l1sm
endif

# Define the specified compile options to COMP_DEFS
COMP_DEFS = 
