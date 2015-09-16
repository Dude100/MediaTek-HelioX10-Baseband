# Define source file lists to SRC_LIST

SRC_LIST = $(strip $(MODEM_FOLDER))/ul1/ul1_hs/ul1d_ext/wdata.c
                      
# Define include path lists to INC_DIR
INC_DIR = $(strip $(MODEM_FOLDER))/ul1/ul1_hs/ul1d_ext


# Define the specified compile options to COMP_DEFS
COMP_DEFS = __FS_FILTER__ \
            __CATEGORY_MODEM__

# Define the source file search paths to SRC_PATH
SRC_PATH = $(strip $(MODEM_FOLDER))/ul1/ul1_hs/ul1d_ext
