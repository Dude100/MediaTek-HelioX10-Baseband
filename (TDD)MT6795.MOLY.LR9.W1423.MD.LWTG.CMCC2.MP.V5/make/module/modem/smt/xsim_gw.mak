# Define source file lists to SRC_LIST
SRC_LIST = $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/uegw2/src/uegw2_mngr.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/uegw2/src/uegw2_mngr.h \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/uegw2/src/uegw2_typedb.h \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/uegw2/src/sim_utc.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/uegw2/src/sim_utc_intf.h 

# Define include path lists to INC_DIR
INC_DIR = $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/xcomm/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/esim_nw/mns_f_generic/intf  \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/uegw2/intf  \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/aos/intf

# Define the specified compile options to COMP_DEFS
COMP_DEFS = TRACING_SUPPORT \
            INTEGER_SIM_TIME \
            AOS_DLL_RELATIVE_PATH='&quot;&quot;..\\..\\modem\\smt\\uesim_lte\\xsim_generic\\aos\\lib&quot;&quot';

# Define the source file search paths to SRC_PATH
SRC_PATH = $(strip $(MODEM_FOLDER))/smt/xsim_generic/uegw2/src \
           $(strip $(MODEM_FOLDER))/smt/xsim_generic/uegw2/intf \
           $(strip $(MODEM_FOLDER))/smt/xsim_generic/xcomm/intf
           

