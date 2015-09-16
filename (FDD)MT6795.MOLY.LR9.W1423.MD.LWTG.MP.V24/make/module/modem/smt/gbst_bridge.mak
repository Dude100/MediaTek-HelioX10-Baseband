# Define source file lists to SRC_LIST
SRC_LIST = $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/aos/interface/aos_intf.h \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/uegw2/intf/uegw2_intf.h \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/gbst_bridge/intf/csap_g_intf.h \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/gbst_bridge/intf/gbst_bridge_intf.h \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/gbst_bridge/src/gbst_bridge.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/gbst_bridge/src/gbst_bridge_task.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/gbst_bridge/src/gbst_oscar.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/gbst_bridge/src/gbst_oscar.h
           

# Define include path lists to INC_DIR
INC_DIR = $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/uegw2/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/aos/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/generic/src/ \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/gbst_bridge/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/gsim_nw/intf \
          $(strip $(MODEM_FOLDER))/gl1/l1_dm/common \
          $(strip $(MODEM_FOLDER))/gl1/l1_dm/interface \
          $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1c \
          $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d \
          $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_ext \
          $(strip $(MODEM_FOLDER))/interface/l1/gsm \
          $(strip $(MODEM_FOLDER))/interface/l1/inner \
          $(strip $(MODEM_FOLDER))/md_sm/l1sm \
          $(strip $(MODEM_FOLDER))/md_sm/common/l1sm 

# Define the specified compile options to COMP_DEFS
COMP_DEFS = INTEGER_SIM_TIME \
            TRACING_SUPPORT \
            __EL1SIM_WITH_MODIS__ \
            __MODIS_WITH_EPHYSIM__ \
            IDLE_TASK \
            KAL_ON_OSCAR \
            _MODIS_ON_VC9_ \
            __EL1TX_ENABLE__ \
            __EL1_ENABLE__ \
            __OSCAR_ON_WIN32__ \
            __PROTECT_OPTIMIZE__ \
            __UT_ISR_OPTIMIZE__ \
            __VM_CODEC_SUPPORT__ \
            __WATCHDOG_RESTART_DISABLE__

# Define the source file search paths to SRC_PATH
SRC_PATH = $(strip $(MODEM_FOLDER))/smt/uesim_lte/gbst_bridge/src

