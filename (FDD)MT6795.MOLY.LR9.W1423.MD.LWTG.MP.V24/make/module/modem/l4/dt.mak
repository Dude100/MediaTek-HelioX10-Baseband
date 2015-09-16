# Define source file lists to SRC_LIST
SRC_LIST = $(strip $(MODEM_FOLDER))/l4/dt/src/dt_create.c \
           $(strip $(MODEM_FOLDER))/l4/dt/src/dt_init.c \
           $(strip $(MODEM_FOLDER))/l4/dt/src/dt_main.c \
           $(strip $(MODEM_FOLDER))/l4/dt/src/dt_msg_hdlr.c \
           $(strip $(MODEM_FOLDER))/l4/dt/src/dt_aux_msg_hdlr.c \
           $(strip $(MODEM_FOLDER))/l4/dt/src/dt_utility.c \
           $(strip $(MODEM_FOLDER))/l4/dt/src/dt_rspfmttr.c \
           $(strip $(MODEM_FOLDER))/l4/dt/src/dt_analyzer.c \
           $(strip $(MODEM_FOLDER))/l4/dt/src/dt_validator.c

#  Define include path lists to INC_DIR
INC_DIR = $(strip $(MODEM_FOLDER))/l4/dt/include \
          interface/bt

# Define the specified compile options to COMP_DEFS
COMP_DEFS = UART_ENABLE \
            DATA_DOWNLOAD \
            __CATEGORY_MODEM__

# Define the source file search paths to SRC_PATH
SRC_PATH = $(strip $(MODEM_FOLDER))/l4/dt/src