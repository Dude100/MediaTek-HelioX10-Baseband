# Define source file lists to SRC_LIST
SRC_LIST = $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/generic/src/huge_time.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/generic/src/m13000.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/generic/src/m13003.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/generic/src/m13004.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/generic/src/m13005.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/generic/src/m13006.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/generic/src/m13007.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/generic/src/m13100.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/generic/src/m13101.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/generic/src/m13102.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/generic/src/m13103.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/generic/src/m13200.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/generic/src/m13201.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/generic/src/m13202.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/os_adaptation/src/xsim_kal_assert.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/os_adaptation/src/xsim_main_task.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/os_adaptation/src/xsim_oscar_consume_time.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/os_adaptation/src/xsim_oscar_os_timer.c

# Define include path lists to INC_DIR
INC_DIR = $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/generic/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/scripting/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208 \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/gsim_hw/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/gsim_nw/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_nw \
          $(strip $(MODEM_FOLDER))/gl1/l1_dm/common \
          $(strip $(MODEM_FOLDER))/gl1/l1_dm/interface \
          $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1c \
          $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d \
          $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_ext \
          $(strip $(MODEM_FOLDER))/interface/l1/gsm \
          $(strip $(MODEM_FOLDER))/interface/l1/inner \
          $(strip $(MODEM_FOLDER))/md_sm/l1sm \
          $(strip $(MODEM_FOLDER))/md_sm/common/l1sm \

# Define the specified compile options to COMP_DEFS
COMP_DEFS = INTEGER_SIM_TIME \
            SIMULATION_SUPPORT \
            TRACING_SUPPORT

COMP_DEFS += __ESIM_3G_HWSIM_DATA_PATH_ENABLE__ \
             __ESIM_3G_HWSIM_ASSERT_DISABLE__

# Define the source file search paths to SRC_PATH
SRC_PATH = $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/generic/src \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/os_adaptation/src
