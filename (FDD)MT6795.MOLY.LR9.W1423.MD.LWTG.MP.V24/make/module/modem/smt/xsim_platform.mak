# Define source file lists to SRC_LIST
SRC_LIST = $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14000_uesim.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14100.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14101.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14102.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14103.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14104.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14105.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14106.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14107.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14108.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14109.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14110.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14111.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14120.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14121.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14122.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14123.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14124.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14125.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14126.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14127.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14128.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14129.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14130.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14140.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/m14999.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/os_timer.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/tdma_sm.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/top_sm.c

# Define include path lists to INC_DIR
INC_DIR = $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/generic/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/scripting/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/aos/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/uegw2/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/xcomm/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/esim_evrf_bridge/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/gsim_nw/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/gsim_hw/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/uvrf/intf \
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
            SIM_MT6280 \
            L1_SIM \
            L1D_SIM \
            REG_MAY_NOT_EXIST \
            AFC_13bit \
            CH_RF_TEST \
            __HYPER_SLEEP_MODE_CHIP__ \
            USE_WAKEUP_INT \
            MEM_CHECK_ON \
            __HSPA_PLUS_SIM__ \
            HARDWARE_SIMULATION=1 \
            MT6326 \
            TRACING_SUPPORT

# Define the source file search paths to SRC_PATH
SRC_PATH = $(strip $(MODEM_FOLDER))/smt/xsim_platform/mt6208
