# Define source file lists to SRC_LIST
SRC_LIST = $(strip $(MODEM_FOLDER))/smt/uesim_lte/gsim_hw/src/m134000.c \
					 $(strip $(MODEM_FOLDER))/smt/uesim_lte/gsim_hw/src/m134001.c \
					 $(strip $(MODEM_FOLDER))/smt/uesim_lte/gsim_hw/src/m134002.c \
					 $(strip $(MODEM_FOLDER))/smt/uesim_lte/gsim_hw/src/m134003.c

SRC_LIST += $(strip $(MODEM_FOLDER))/smt/uesim_lte/gsim_hw/src/m13500.c

# Define include path lists to INC_DIR
INC_DIR = $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/generic/intf \
					$(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208 \
					$(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/rf \
					$(strip $(MODEM_FOLDER))/smt/uesim_lte/gsim_nw/intf \
					$(strip $(MODEM_FOLDER))/smt/uesim_lte/gsim_hw/intf \
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
						L1_SIM \
						L1D_SIM \
						__HYPER_SLEEP_MODE_CHIP__ \
						AFC_13bit \
						TRACING_SUPPORT

# Define the source file search paths to SRC_PATH
SRC_PATH = $(strip $(MODEM_FOLDER))/smt/uesim_lte/gsim_hw/src
