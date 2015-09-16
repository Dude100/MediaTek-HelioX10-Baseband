# Define source file lists to SRC_LIST
SRC_LIST = $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimBpi.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimBsi.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimCdGn.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimCgi.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimCmbnr.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimCntr.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimCs4.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimDcxoSrchr.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimDftc.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimDtDmp.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimERx.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimETx.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimHaPlusAdapter.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimHsCe.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimHsRx.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimHsTx.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimHwCmmn.h \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimHwDfn.h \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimHwFnct.h \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimHwMisc.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimHwPublic.h\
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimHwTypes.h \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimHwUtil.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimIRatChkr.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimMs3.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimPac.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimPll.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimRake.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimRf.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimRfMt6159B.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimRfMt6159C.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimRfMt6160.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimRfMt6162.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimRfMt6162Dual.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimRfOrionHplus.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimRfPmic.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimRfSmarti3G.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimRfSonyCxa3359.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimRxAmp.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimRxBfe.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimRxBrp.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimRxBrpPhCh.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimRxSrp.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimSclrTmr.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimSdGn.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimSlwClk.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimSrchrTmr.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimSta.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimSysTmr.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimTrk.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimTxBrp.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimTxBrpDt.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimTxCrp.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/uvrf/src/uvrf_bridge.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/uvrf/src/uvrf_bridge_task.c \
           $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/UsimUSCntr.c

# Define include path lists to INC_DIR
INC_DIR = $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_framework/generic/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208 \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_platform/mt6208/rf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/gsim_nw/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/gsim_hw/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/uvrf/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw/uvrf/src \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_nw \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/uegw2/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/uegw2/src \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/xcomm/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/xsim_generic/aos/intf \
          $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_nw/mns_u_airctrl/intf \
          $(strip $(MODEM_FOLDER))/gl1/l1_dm/common \
          $(strip $(MODEM_FOLDER))/gl1/l1_dm/interface \
          $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1c \
          $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d \
          $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_ext \
          $(strip $(MODEM_FOLDER))/interface/l1/gsm \
          $(strip $(MODEM_FOLDER))/interface/l1/inner \
          $(strip $(MODEM_FOLDER))/md_sm/l1sm \
          $(strip $(MODEM_FOLDER))/md_sm/common/l1sm \
          driver/peripheral/inc

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
SRC_PATH = $(strip $(MODEM_FOLDER))/smt/uesim_lte/usim_hw
