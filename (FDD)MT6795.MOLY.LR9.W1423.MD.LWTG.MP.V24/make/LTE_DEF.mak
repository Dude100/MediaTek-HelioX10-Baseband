#------------------------------
# LTE Components
#------------------------------
ifneq ($(call Upper,$(strip $(EUTRAN_MODE_SUPPORT))),NONE)

#MODEM
  COMPLIST         += tft_pf ratadp upcm rohc

  #COMMINCDIRS      += interface
  COMMINCDIRS      += interface/modem/lte
  COMMINCDIRS      += modem/interface/lte
  
  COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/nwsel/include/nwsel_trc.h
  COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/upcm/include/upcm_trc.h

  LTE_SOURCE_BUILD = FALSE
  ifneq ($(wildcard modem/lte_sec/),)
    LTE_SOURCE_BUILD = TRUE
  endif
  
  ifeq ($(LTE_SOURCE_BUILD),TRUE)
    NO_LTELIB = FALSE
  endif

  #LTE sec module list
  LTE_SEC_COMP := 
  ifeq ($(strip $(LTE_DUMMY_PROTOCOL_ENABLE)),TRUE)
    LTE_SEC_COMP      = l1edps
  else
    LTE_SEC_COMP      = el2 emm esm eval errc etc
  endif
  LTE_SEC_COMP      += edyn etmr ltm_multi el1 tstm

  ifeq ($(strip $(UE_SIMULATOR)), TRUE)
     LTE_SEC_COMP   += esim_phy 
  endif

  ifeq ($(strip $(NO_LTELIB)),FALSE)
    COM_DEFS += $(foreach mod,$(call Upper,$(LTE_SEC_COMP)), __$(mod)_ENABLE__)
  endif
  
  ifeq ($(LTE_SOURCE_BUILD),TRUE)

    COMMINCDIRS      += modem/lte_sec
    COMMINCDIRS      += modem/lte_sec/interface
    
    # CODEGEN PATH
    COMMINCDIRS      += modem/lte_sec/interface/etmr
    
    # EL1 CODEGEN PATH
    COMMINCDIRS      += $(strip $(EL1_FOLDER))/irt/include    \
                        $(strip $(EL1_FOLDER))/irt/src        \
                        $(strip $(EL1_FOLDER))/common/include \
                        $(strip $(EL1_FOLDER))/interface      \
                        modem/lte_sec/common/include     \
                        modem/lte_sec/interface/el1      \
                        $(strip $(EL1_FOLDER))/csr/include    \
                        $(strip $(EL1_FOLDER))/csr/src        \
                        $(strip $(EL1_FOLDER))/meas/include   \
                        $(strip $(EL1_FOLDER))/meas/src       \
                        $(strip $(EL1_FOLDER))/ch/include     \
                        $(strip $(EL1_FOLDER))/ch/src         \
                        $(strip $(EL1_FOLDER))/drv/include    \
                        $(strip $(EL1_FOLDER))/common/include
    
    # EL2 CODEGEN PATH
    COMMINCDIRS      += modem/lte_sec/el2/interface \
                        modem/lte_sec/interface/el2

    # LTE Test Mode CODEGEN PTAH
    COMMINCDIRS      += $(strip $(EL1_FOLDER))/tstm/include
    
    # PS TRACE FILES
    COMP_TRACE_DEFS_MODEM_LTE_SEC += $(strip $(EL1_FOLDER))/common/include/el1_trc.h \
                                     $(strip $(EL1_FOLDER))/tstm/include/test_mode_trc.h
    
    # L1 TRACE FILES
    ifneq (,$(findstring __EL1_ENABLE__,$(COM_DEFS)))
      L1_TMD_FILES_LTE_SEC += $(strip $(EL1_FOLDER))/phs/src/el1_phs_1_trace.tmd \
                              $(strip $(EL1_FOLDER))/phs/src/el1_phs_2_trace.tmd \
                              $(strip $(EL1_FOLDER))/phs/src/el1_phs_rtb_1_trace.tmd \
                              $(strip $(EL1_FOLDER))/drv/src/el1_drv_1_trace.tmd \
                              $(strip $(EL1_FOLDER))/drv/src/el1_drv_2_trace.tmd \
                              $(strip $(EL1_FOLDER))/irt/src/el1_irt_1_trace.tmd \
                              $(strip $(EL1_FOLDER))/tx/src/el1tx_trace.tmd \
                              $(strip $(EL1_FOLDER))/common/src/el1_main_trace.tmd

    endif


    # L2 TRACE FILES (re-use L1_TMD_FILES_LTE_SEC)
    ifneq (,$(findstring __L1EDPS_ENABLE__,$(COM_DEFS)))
      COMP_TRACE_DEFS_MODEM_LTE_SEC += modem/lte_sec/el2/interface/el2_trc.h
    endif

    # L2 TRACE FILES (re-use L1_TMD_FILES_LTE_SEC)
    ifneq (,$(findstring __EL2_ENABLE__,$(COM_DEFS)))         
      COMP_TRACE_DEFS_MODEM_LTE_SEC += modem/lte_sec/el2/interface/el2_trc.h

      L1_TMD_FILES_LTE_SEC += modem/lte_sec/el2/erlcul/erlcul_trace.tmd \
                              modem/lte_sec/el2/erlcul/erlcul_detail_trace.tmd \
                              modem/lte_sec/el2/erlcdl/erlcdl_trace.tmd \
                              modem/lte_sec/el2/erlcdl/erlcdl_detail_trace.tmd \
                              modem/lte_sec/el2/emac/src/emac_trace.tmd \
                              modem/lte_sec/el2/emac/src/emac_detail_trace.tmd \
                              modem/lte_sec/el2/epdcp/src/epdcp_trace.tmd \
                              modem/lte_sec/el2/epdcp/src/epdcp_detail_trace.tmd


    endif

    # L1-TX TRACE FILES
    ifneq (,$(findstring __EL1TX_ENABLE__,$(COM_DEFS)))
      L1_TMD_FILES_LTE_SEC += $(strip $(EL1_FOLDER))/tx/src/el1tx_trace.tmd
    endif

    L1_TMD_FILES_LTE_SEC += $(strip $(MODEM_FOLDER))/lte_sec/edyn/src/edata_path_trace.tmd
    L1_TMD_FILES_LTE_SEC += $(strip $(MODEM_FOLDER))/lte_sec/edyn/src/edata_path_detail_trace.tmd
      
    # MT6290 FPGA setting
    ifeq ($(strip $(MT6290_FIRST_CALL)),TRUE)
      ifneq ($(strip $(MODIS_CONFIG)),TRUE)
        COM_DEFS       += __MT6290_FIRST_CALL__
      endif
    endif
    ifeq ($(strip $(MT6290E2_FIRST_CALL)),TRUE)
      ifneq ($(strip $(MODIS_CONFIG)),TRUE)
        COM_DEFS       += __MT6290E2_FIRST_CALL__
      endif
    endif
    ifeq ($(strip $(MT6290_FPGA)),TRUE)
      COM_DEFS       += __MT6290_FPGA__
    endif

    ifeq ($(strip $(LTE_DUMMY_PROTOCOL_ENABLE)),TRUE)
      COMMINCDIRS      += modem/lte_sec/l1edps/include/internal \
                          interface/modem/lte 
    endif
    
    # ERRC CODEGEN PATH
    # external structure
    ifneq ($(filter __ERRC_ENABLE__ __L1EDPS_ENABLE__,$(COM_DEFS)),)
      COMMINCDIRS      += modem/lte_sec/interface/el2 \
                          modem/lte_sec/enas/emm/interface \
                          modem/lte_sec/enas/emm/common/include
      # internal structure
      COMMINCDIRS      += modem/lte_sec/errc/cel/include \
                          modem/lte_sec/errc/conn/include \
                          modem/lte_sec/errc/chm/include \
                          modem/lte_sec/errc/sys/include \
                          modem/lte_sec/errc/rcm/include \
                          modem/lte_sec/errc/mob/include \
                          modem/lte_sec/errc/spv/include \
                          modem/lte_sec/errc/evth/include
      # trace file path
      COMP_TRACE_DEFS_MODEM_LTE_SEC += modem/lte_sec/errc/evth/include/errc_evth_trc.h \
                                       modem/lte_sec/errc/conn/include/errc_conn_trc.h \
                                       modem/lte_sec/errc/chm/include/errc_chm_trc.h \
                                       modem/lte_sec/errc/sys/include/errc_sys_trc.h \
                                       modem/lte_sec/errc/rcm/include/errc_rcm_trc.h \
                                       modem/lte_sec/errc/mob/include/errc_mob_trc.h \
                                       modem/lte_sec/errc/cel/include/errc_cel_trc.h \
                                       modem/lte_sec/errc/spv/include/errc_spv_trc.h \
                                       modem/lte_sec/errc/common/include/errc_trc.h
    endif
   
    # ESM CODEGEN PATH
    ifneq (,$(findstring __ESM_ENABLE__,$(COM_DEFS)))
      COMMINCDIRS      += modem/lte_sec/enas/esm \
                          modem/lte_sec/interface/ltm_multi
                          
      COMP_TRACE_DEFS_MODEM_LTE_SEC += modem/lte_sec/enas/esm/esm_dhl_trace.h
    endif

    # ETC CODEGEN PATH
    ifneq (,$(findstring __ETC_ENABLE__,$(COM_DEFS)))
      COMMINCDIRS      += modem/lte_sec/enas/etc/include
    
      COMP_TRACE_DEFS_MODEM_LTE_SEC += modem/lte_sec/enas/etc/include/etc_trc.h
    endif

    ifneq (,$(findstring __EMM_ENABLE__,$(COM_DEFS)))
      # EMM CODEGEN PATH
      COMMINCDIRS      += modem/lte_sec/enas/emm/interface \
                          modem/lte_sec/enas/emm/common/include \
                          modem/lte_sec/enas/emm/evtctrl/include \
                          modem/lte_sec/enas/emm/plmnsel/include \
                          modem/lte_sec/enas/emm/sv/include \
                          modem/lte_sec/enas/emm/ratband/include \
                          modem/lte_sec/enas/emm/call/include \
                          modem/lte_sec/enas/emm/conn/include \
                          modem/lte_sec/enas/emm/nasmsg/include \
                          modem/lte_sec/enas/emm/opidsrv/include \
                          modem/lte_sec/enas/emm/sec/include \
                          modem/lte_sec/enas/emm/reg/include \
                          modem/lte_sec/enas/emm/nmsrv/include \
                          modem/lte_sec/enas/emm/usimsrv/include \
                          modem/lte_sec/enas/emm/nvmsrv/include \
                          modem/lte_sec/enas/emm/cmnproc/include \
                          modem/lte_sec/enas/emm/errcif/include \
                          modem/lte_sec/enas/emm/etcif/include \
                          modem/lte_sec/enas/emm/ratchg/include \
                          modem/lte_sec/enas/emm/evalif/include \
                          modem/lte_sec/enas/emm/esmif/include \
                          modem/lte_sec/enas/emm/mmif


      COMP_TRACE_DEFS_MODEM_LTE_SEC += modem/lte_sec/enas/emm/evtctrl/include/emm_evtctrl_trc.h \
                                       modem/lte_sec/enas/emm/plmnsel/include/emm_plmnsel_trc.h \
                                       modem/lte_sec/enas/emm/conn/include/emm_conn_trc.h \
                                       modem/lte_sec/enas/emm/nasmsg/include/emm_nasmsg_trc.h \
                                       modem/lte_sec/enas/emm/opidsrv/include/emm_opidsrv_trc.h \
                                       modem/lte_sec/enas/emm/sec/include/emm_sec_trc.h \
                                       modem/lte_sec/enas/emm/call/include/emm_call_trc.h \
                                       modem/lte_sec/enas/emm/common/include/emm_dhl_trace.h \
                                       modem/lte_sec/enas/emm/reg/include/emm_reg_trc.h \
                                       modem/lte_sec/enas/emm/nmsrv/include/emm_nmsrv_trc.h \
                                       modem/lte_sec/enas/emm/usimsrv/include/emm_usimsrv_trc.h \
                                       modem/lte_sec/enas/emm/nvmsrv/include/emm_nvmsrv_trc.h \
                                       modem/lte_sec/enas/emm/cmnproc/include/emm_cmnproc_trc.h \
                                       modem/lte_sec/enas/emm/errcif/include/emm_errcif_trc.h \
                                       modem/lte_sec/enas/emm/sv/include/emm_sv_trc.h \
                                       modem/lte_sec/enas/emm/etcif/include/emm_etcif_trc.h \
                                       modem/lte_sec/enas/emm/ratband/include/emm_ratband_trc.h \
                                       modem/lte_sec/enas/emm/ratchg/include/emm_ratchg_trc.h \
                                       modem/lte_sec/enas/emm/evalif/include/emm_evalif_trc.h \
                                       modem/lte_sec/enas/emm/esmif/include/emm_esmif_trc.h \
                                       modem/lte_sec/enas/emm/mmif/include/emm_mmif_trc.h
    endif
    
    # EVAL trace
    COMMINCDIRS      += modem/lte_sec/enas/eval/include
    COMP_TRACE_DEFS_MODEM_LTE_SEC += modem/lte_sec/enas/eval/include/eval_trc.h
  
    COMPLIST         += $(LTE_SEC_COMP)
  else
    #LTE_SOURCE_BUILD = FALSE
    ifeq ($(strip $(NO_LTELIB)),FALSE)
      COMPOBJS += $(call sort,$(foreach lib,$(LTE_SEC_COMP),$(CUS_MTK_LIB)/$(lib).a))
      COMPLIST  := $(filter-out ,$(COMPLIST))
    endif
  endif#ifeq ($(LTE_SOURCE_BUILD),TRUE)


  # TFT library trace
  COMP_TRACE_DEFS_MODEM += modem/l4/tcm/tftlib/tftlib_dhl_trace.h

  # DSPFM trace
  COMP_TRACE_DEFS_MODEM += service/sys_svc/dspfm_lte/inc/dspfm_trace.h

  ifeq ($(strip $(ETSTM_EN)),TRUE)
      COM_DEFS += __ETSTM_ENABLE__ 
  endif

  COM_DEFS         += __MASK_L4__ __LTE_RAT__ __LTE_REL9__  
  
  ifeq ($(strip $(SIM_STANDALONE)),TRUE)
    COM_DEFS         += __SIM_STANDALONE__
    #COM_DEFS         += __USIM_UT__ 
  endif

  #BSP
  COMPLIST         += l2_lte_copro

  COMPLIST += ephy ephy_ext
  
  COM_DEFS += __23G_PRI_RESEL_SUPPORT__
  
endif

ifeq ($(LTE_SOURCE_BUILD),TRUE)
  COMMINCDIRS      += interface/driver/hif
  COMMINCDIRS      += interface/driver/hif/hif_usbdev
  COMMINCDIRS      += interface/driver/hif/hif_sdiodev
  COMMINCDIRS      += interface/driver/hif/hif_cldmadev
  COMMINCDIRS      += interface/driver/devdrv/coresight
  ifeq ($(strip $(UE_SIMULATOR)), TRUE)  
    COMMINCDIRS      += interface/driver/devdrv/hif/
    COMMINCDIRS      += interface/driver/devdrv/hif/hif_usbdev
    COMMINCDIRS      += interface/driver/devdrv/hif/hif_sdiodev
    COMMINCDIRS      += interface/driver/devdrv/hif/hif_cldmadev 
  endif
endif
  
ifdef OS_TICK_PERIOD_IN_US
  COM_DEFS      += OS_TICK_PERIOD_US=$(strip $(OS_TICK_PERIOD_IN_US))
endif

ifeq ($(strip $(HIF_USB_SUPPORT)),TRUE)
  COM_DEFS	+= __CREATE_USB_HISR__
endif

ifeq ($(strip $(HIF_SDIO_SUPPORT)),TRUE)
  COM_DEFS      += __CREATE_SDIO_HISR__
endif

ifeq ($(strip $(SYS_TEST_EMSC_ENABLE)),TRUE)
  COM_DEFS      += SYS_TEST_EMSC_ENABLE
endif

ifeq ($(filter BASIC,$(TEST_LOAD_TYPE)),)
  include make/hif_main.mak
else
  COMMINCDIRS += interface/middleware/hif
endif
