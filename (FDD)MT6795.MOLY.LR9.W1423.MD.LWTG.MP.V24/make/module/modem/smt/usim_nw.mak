# Define source file lists to SRC_LIST
SRC_LIST = $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_nw/UsimBchCctrchUeSim.c \
 					 $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_nw/UsimCctrchUeSim.c \
	 				 $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_nw/UsimCmmn.h \
					 $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_nw/UsimDfn.h \
					 $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_nw/UsimDump_UL1C.h \
					 $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_nw/UsimFnct.h \
					 $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_nw/UsimFnctStub.c \
					 $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_nw/UsimMisc.c \
					 $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_nw/UsimScnnr.c \
					 $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_nw/UsimScnnr_UL1C.h \
					 $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_nw/UsimTypes.h \
					 $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_nw/UsimUlCctrchUeSim.c \
					 $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_nw/UsimUtil.c

# Define include path lists to INC_DIR
INC_DIR = $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/generic/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_nw \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw \
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
COMP_DEFS = __ESIM_3G_HWSIM_DATA_PATH_ENABLE__ \
            __ESIM_3G_HWSIM_ASSERT_DISABLE__ \
            INTEGER_SIM_TIME \
            L1_SIM \
            L1D_SIM \
            REG_MAY_NOT_EXIST \
            AFC_13bit \
            CH_RF_TEST \
            __HYPER_SLEEP_MODE_CHIP__ \
            USE_WAKEUP_INT \
            MEM_CHECK_ON \
            __HSPA_PLUS_SIM__ \
            MT6326 \
            TRACING_SUPPORT

# Define the source file search paths to SRC_PATH
SRC_PATH = $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_nw
