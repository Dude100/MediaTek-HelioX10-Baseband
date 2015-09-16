#
# HIF service interface exported to other catagories (e.g. modem)
#
COMMINCDIRS += interface/service/hif

#
# HIF service common components
#
COMPLIST         += hmu
COMPLIST         += hmu_sec
COM_DEFS         += __HMU_ENABLE__
COMP_TRACE_DEFS_MODEM  += service/hif/hmu/include/hmu_trace.h

#
# HIF middleware interface exported to other catagories (e.g. modem)
#
COMMINCDIRS += interface/middleware/hif

#
# HIF middleware common compnents
#
COMPLIST         += nmu
COM_DEFS         += __NMU_ENABLE__
COMP_TRACE_DEFS_MODEM  += middleware/hif/nmu/core/inc/nmu_trace.h
COMP_TRACE_DEFS_MODEM  += middleware/hif/nmu/dhcp4c/include/dhcp4c_trace.h
COMP_TRACE_DEFS_MODEM  += middleware/hif/nmu/ndpc/include/ndpc_trace.h

COMPLIST         += ipcore
COM_DEFS         += __IPCORE_SUPPORT__
COMP_TRACE_DEFS_MODEM  += middleware/hif/ipcore/include/ipc_trace.h

#
# HIF data path trace log
#
COMMON_TMD_FILES	+= middleware/hif/interface/hif_mw_data_path_trace.tmd
COMMON_TMD_FILES	+= service/hif/interface/hif_srv_data_path_trace.tmd
COMMON_TMD_FILES	+= driver/hif_drv/src/hif_drv_data_path_trace.tmd

#COM_DEFS	+= __TTY_UT__
#COM_DEFS	+= __EXCEPT_TTY_UT__

#
# HIF dependent makefile
#
ifdef HIF_AOMGR_SUPPORT
  ifeq ($(strip $(HIF_AOMGR_SUPPORT)), TRUE)
    COM_DEFS        += __HIF_AOMGR_SUPPORT__
    COMPLIST        += aomgr
    COMP_TRACE_DEFS_MODEM  += middleware/hif/aomgr/include/aomgr_trace.h
  endif
endif

ifdef HIF_USB_SUPPORT
ifeq ($(strip $(HIF_USB_SUPPORT)), TRUE)
  #
  # USB common compiler option
  #
  COM_DEFS         += __HIF_USB_SUPPORT__
  
  #
  # USB common components
  #
  COMPLIST         += usbcore
  COMPLIST         += usbidle
  COM_DEFS         += __USBCORE_SUPPORT__
  COMP_TRACE_DEFS_MODEM  += middleware/hif/usbcore/include/usbcore_trace.h
  
  COMPLIST         += usbclass
  COM_DEFS         += __USBCLASS_SUPPORT__
  COMP_TRACE_DEFS_MODEM  += middleware/hif/usbclass/task/include/ucd_trace.h
  
  #
  # USB Class specific makefile macro and compiler option
  #
  ifdef USB_ACM_SUPPORT
    ifeq ($(strip $(USB_ACM_SUPPORT)), TRUE)
         COM_DEFS += __USB_ACM_SUPPORT__
         COMP_TRACE_DEFS_MODEM  += middleware/hif/usbclass/acm/include/cdcacm_trace.h
    endif
  endif
  
  ifdef USB_RNDIS_SUPPORT
    ifeq ($(strip $(USB_RNDIS_SUPPORT)), TRUE) 
         COM_DEFS += __USB_RNDIS_SUPPORT__
         COMP_TRACE_DEFS_MODEM += middleware/hif/usbclass/rndis/include/rndis_trace.h
  
         # RNDIS needs to attach with ETHERCORE
         ETHERCORE_SUPPORT = TRUE
    endif
  endif
  
  ifdef USB_ECM_SUPPORT
    ifeq ($(strip $(USB_ECM_SUPPORT)), TRUE) 
       COM_DEFS += __USB_ECM_SUPPORT__
       COMP_TRACE_DEFS_MODEM += middleware/hif/usbclass/ecm/include/cdcecm_trace.h

       # ECM needs to attach with ETHERCORE
       ETHERCORE_SUPPORT = TRUE
    endif
  endif
  
  ifdef USB_MBIM_SUPPORT
    ifeq ($(strip $(USB_MBIM_SUPPORT)), TRUE) 
         COM_DEFS += __USB_MBIM_SUPPORT__
         COMP_TRACE_DEFS_MODEM += middleware/hif/usbclass/mbim/include/mbim_trace.h
    endif
  endif

  ifdef USB_MSD_SUPPORT
    ifeq ($(strip $(USB_MSD_SUPPORT)), TRUE) 
         COM_DEFS += __USB_MSD_SUPPORT__
         COMP_TRACE_DEFS_MODEM += middleware/hif/usbclass/msd/include/ms_trace.h
    endif
  endif
  
endif
endif

ifdef HIF_CLDMA_SUPPORT
  ifeq ($(strip $(HIF_CLDMA_SUPPORT)), TRUE)
    #
    # CLDMA common compiler option
    #
    COM_DEFS         += __HIF_CLDMA_SUPPORT__
    
    #
    # CLDMA common components
    #
    COMPLIST         += cldmacore
    COM_DEFS         += __CLDMACORE_SUPPORT__ 
    #COM_DEFS         += __CLDMAIPC_SUPPORT__
	  COMPLIST += cldmadev
	  
    #
    # CLDMA common Include Path
    #
    INC_DIR = driver/regbase/inc            \
    	  driver/devdrv/cirq_v1/inc                   \
          driver/hif/inc/hif_cldmadev

    COMMINCDIRS += interface/driver/cldmacore
  endif
endif


ifdef HIF_CCIF_SUPPORT
  ifeq ($(strip $(HIF_CCIF_SUPPORT)), TRUE)
    #
    # CCIF common compiler option
    #
    COM_DEFS         += __HIF_CCIF_SUPPORT__
    
    #
    # CCIF common components
    #
    #COMPLIST         += ccifcore
    #COM_DEFS         += __CCIFCORE_SUPPORT__ 
    COMPLIST += ccifdev
ifdef HIF_USB_SUPPORT
ifeq ($(strip $(HIF_USB_SUPPORT)), FALSE)  
    COM_DEFS         += __CCIFTTY_SUPPORT__ 
endif
else
    COM_DEFS	     += __CCIFTTY_SUPPORT__
endif

    COM_DEFS         += __CCIFGPD_SUPPORT__ 

    #
    # CCIF common Include Path
    #
    INC_DIR = driver/regbase/inc            \
    	  driver/devdrv/cirq_v1/inc                   \
          driver/hif/inc/hif_ccif

    COMMINCDIRS += interface/driver/ccifcore
  endif
endif

ifdef HIF_WCCIF_SUPPORT
  ifeq ($(strip $(HIF_WCCIF_SUPPORT)), TRUE)
    #
    # CCIF common compiler option
    #
    COM_DEFS         += __HIF_WCCIF_SUPPORT__
    COMPLIST += wccifdev
    #
    # CCIF common components
    #
    #COMPLIST         += wccifcore
    ifeq ($(strip $(HIF_CLDMA_SUPPORT)), FALSE)
      COM_DEFS         += __CCIFCORE_SUPPORT__ __CCIFRX_HISR_DISABLE__
      COMPLIST += ccifcore
    endif
    #
    # CCIF common Include Path
    #
    INC_DIR = driver/regbase/inc            \
          driver/devdrv/cirq_v1/inc                   \
          driver/hif/inc/hif_ccif

    #COMMINCDIRS += interface/driver/wccifcore
  endif
endif

ifdef HIF_UART_SUPPORT
  ifeq ($(strip $(HIF_UART_SUPPORT)), TRUE)
    #
    # UART common compiler option
    #
    COM_DEFS		+= __HIF_UART_SUPPORT__

    #
    # UART common components
    #
    COMPLIST		+= uartcore
    COM_DEFS		+= __UARTCORE_SUPPORT__
  endif
endif

#
# HIF optional components
#
ifdef ETHERCORE_SUPPORT
  ifeq ($(strip $(ETHERCORE_SUPPORT)), TRUE)
    COMPLIST         += ethercore
    COM_DEFS += __ETHERCORE_SUPPORT__
  endif
endif

ifdef LTM_SIMULATION_SUPPORT
  ifeq ($(strip $(LTM_SIMULATION_SUPPORT)), TRUE)
       COMPLIST         += ltm_sim
       COM_DEFS         += __LTM_SIMULATION_SUPPORT__
  endif
endif

ifdef HIF_SDIO_SUPPORT
  ifeq ($(strip $(HIF_SDIO_SUPPORT)), TRUE)
    #
    # SDIO common compiler option
    #
    COM_DEFS         += __HIF_SDIO_SUPPORT__
    
    #
    # SDIO common components
    #
    COMPLIST         += sdiocore
    COM_DEFS         += __SDIOCORE_SUPPORT__
    
    COMP_TRACE_DEFS_MODEM += driver/sdiocore/include/sdiocore_trace.h

	#
	# SDIO interface exported to other catagories (e.g. service/CCCI)
	#
    COMMINCDIRS += interface/driver/sdiocore
  endif
endif

ifdef HIF_CCCI_SUPPORT
  ifeq ($(strip $(HIF_CCCI_SUPPORT)), TRUE)
    #
    # CCCI common compiler option
    #
    COM_DEFS         += __HIF_CCCI_SUPPORT__
    
    #
    # CCCI common components
    #
    COMPLIST         += ccci
    COM_DEFS         += __CCCI_SUPPORT__
    
    #
    # For CCCI MT6575 loopback test
    #
    #COM_DEFS         += __CCCI_LB_IT__  #conflict with __CCCI_FS_IT__
    
    COMP_TRACE_DEFS_MODEM += service/hif/ccci/include/ccci_trace.h
  endif
  
  ifdef CCCI_DEV_SUPPORT
    ifeq ($(strip $(CCCI_DEV_SUPPORT)), TRUE)
      COMPLIST         += cccidev cccisrv
      COM_DEFS         += __CCCIDEV_SUPPORT__ __CCCITTY_SUPPORT__ __CCCIIPC_SUPPORT__ __CCCIRPC_SUPPORT__
  
       #
       # For CCCI_FS/EMCS IT 
       #
       #COM_DEFS         += __CCCI_FS_IT__  #conflict with __CCCI_LB_IT__

       #
       # For CCCI_TTY IT 
       #
       #COM_DEFS         += __CCCI_TTY_IT__  #conflict with __CCCI_LB_IT__

       #
       # For CCCI IT MODE CONTROL
       #
       #COM_DEFS		 += __CCCI_IT_CTRL__ CCCI_IT_MODE_CONTROL_CCCI_IPC CCCI_IT_MODE_CONTROL_CCCI_RPC

      COMP_TRACE_DEFS_MODEM  += middleware/hif/cccidev/cccidev_task/include/cccidev_trace.h
      COMP_TRACE_DEFS_MODEM  += middleware/hif/cccidev/ccci_tty/include/cccitty_trace.h
      COMP_TRACE_DEFS_MODEM  += service/hif/cccisrv/ccci_ipc/include/ccci_ipc_trace.h
      COMP_TRACE_DEFS_MODEM  += service/hif/cccisrv/ccci_rpc/include/ccci_rpc_trace.h
      COMP_TRACE_DEFS_MODEM  += service/hif/cccisrv/cccisrv_task/include/cccisrv_trace.h
      COMP_TRACE_DEFS_MODEM  += service/hif/cccisrv/ccci_sys_msg/include/ccci_sys_msg_trace.h
      #RPC IPC shall add here like ccci_fs

      ifdef CCCI_FS_SUPPORT
        ifeq ($(strip $(CCCI_FS_SUPPORT)), TRUE)
          COMP_TRACE_DEFS_MODEM  += service/hif/cccisrv/ccci_fs/include/ccci_fs_trace.h
        endif
      endif  
      #	
      # CCMNI
      # if not ROUTER MODE enable CCMNI 
      #
      ifdef CCCI_CCMNI_SUPPORT
         ifeq ($(strip $(CCCI_CCMNI_SUPPORT)), TRUE)
	        COM_DEFS   += __CCCICCMNI_SUPPORT__

	        #
	        # For CCCI_CCMNI/EMCS IT 
	        #
	        #COM_DEFS         += __CCMNI_IT__ __CCCI_IT_CTRL__ CCCI_IT_MODE_CONTROL_CCCI_CCMNI

	        COMP_TRACE_DEFS_MODEM  += middleware/hif/cccidev/ccci_ccmni/include/ccmni_trace.h
         endif    
      endif	
   
    endif
  endif
endif
