# Define source file lists to SRC_LIST
SRC_LIST = $(strip $(MODEM_FOLDER))/smt/uesim_lte/esim_evrf_bridge/src/evrf_bridge.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/esim_evrf_bridge/src/evrf_bridge.h \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/esim_evrf_bridge/src/evrf_bridge_task.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/esim_evrf_bridge/src/evrf_bridge_task.h 

# Define include path lists to INC_DIR
INC_DIR = $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/xcomm/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/esim_evrf_bridge/intf  \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/esim_nw/mns_f_generic/intf  \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/uegw2/intf  \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/aos/intf

# Define the specified compile options to COMP_DEFS
COMP_DEFS = TRACING_SUPPORT \
            INTEGER_SIM_TIME

# Define the source file search paths to SRC_PATH
SRC_PATH = $(strip $(MODEM_FOLDER))/smt/esim_evrf_bridge/src \
           $(strip $(MODEM_FOLDER))/smt/esim_evrf_bridge/intf
           

