#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).

# *************************************************************************
# Include GNU Make Standard Library (GMSL)
# *************************************************************************
include tools/GMSL/gmsl
Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))


CUSTOM_FLD_MAPPING = $(if $($(subst /,_,$(patsubst %/,%,$(subst //,/,$(subst \,/,$(call lc, $(1))))))), \
                     $($(subst /,_,$(patsubst %/,%,$(subst //,/,$(subst \,/,$(call lc, $(1))))))),\
                     $(if $(wildcard $(subst //,/,$(subst \,/,$(call lc, $(1))))/$(BOARD_VER)/$(strip $(CUSTOM_FLAVOR))),\
                     $(subst //,/,$(subst \,/,$(call lc, $(1))))/$(BOARD_VER)/$(strip $(CUSTOM_FLAVOR)),\
                     $(if $(wildcard $(subst //,/,$(subst \,/,$(call lc, $(1))))/$(BOARD_VER)/DEFAULT), \
                     $(subst //,/,$(subst \,/,$(call lc, $(1))))/$(BOARD_VER)/DEFAULT,)))

                      
AUTO_MERGE_FILE_CHECK = $(if $(shell $(LIST_DIR) "$(call CUSTOM_FLD_MAPPING,$(1))/$(2)"  2>$(DEV_NUL)), $(call CUSTOM_FLD_MAPPING,$(1))/$(2), \
                        $(if $(shell $(LIST_DIR) "$(1)/_Default_BB/$(strip $(PLATFORM))/$(2)"  2>$(DEV_NUL)), $(1)/_Default_BB/$(strip $(PLATFORM))/$(2),))
# *************************************************************************
# Set defaul value to Ckmake flag 
# *************************************************************************
DEPENDENCY_CONFLICT = FALSE
# *************************************************************************
# Dependency Check error message Interfaces
# *************************************************************************
# ------------------------------------------------------------------------
# Usage:        $(call DEP_ERR_SETA_OR_SETB,OptA,ValA,OptB,ValB)
#               $(call DEP_ERR_SETA_OR_SETB,OptA,ValA,OptB,ValB1/ValB2/.../ValBn)
#               $(call DEP_ERR_SETA_OR_SETB,OptA,ValA,OptB,non ValB)
# Output:       PLEASE set OptA as ValA or set OptB as ValB
#               PLEASE set OptA as ValA or set OptB as ValB1/ValB2/.../ValBn
#               PLEASE set OptA as ValA or set OptB as non ValB
#
# Example:      $(call DEP_ERR_SETA_OR_SETB,BROWSER_SUPPORT,OBIGO_Q05A,UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT,non OBIGO_Q05A)
#               PLEASE set BROWSER_SUPPORT as OBIGO_Q05A or set UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT as non OBIGO_Q05A
# ------------------------------------------------------------------------
DEP_ERR_SETA_OR_SETB = $(warning ERROR: PLEASE set $1 as $2 or set $3 as $4)
# ------------------------------------------------------------------------
# Usage:        $(call DEP_ERR_ONA_OR_OFFB,OptA,OptB)
#               $(call DEP_ERR_ONA_OR_OFFB,OptA,OptB$OptC&...&OptN)
# Output:       PLEASE turn on OptA or turn off OptB
#
# Example:      $(call DEP_ERR_ONA_OR_OFFB,NAND_SUPPORT,NAND_FLASH_BOOTING)
#               PLEASE turn on NAND_SUPPORT or turn off NAND_FLASH_BOOTING
# ------------------------------------------------------------------------
DEP_ERR_ONA_OR_OFFB = $(warning ERROR: PLEASE turn on $1 or turn off $2)
# ------------------------------------------------------------------------
# Usage:        $(call DEP_ERR_SETA_OR_OFFB,OptA,ValA,OptB)
#               $(call DEP_ERR_SETA_OR_OFFB,OptA,ValA1/ValA2/.../ValAn,OptB)
#               $(call DEP_ERR_SETA_OR_OFFB,OptA,non ValA,OptB)
# Output:       PLEASE set OptA as ValA or turn off OptB
#               PLEASE set OptA as ValA1/ValA2/.../ValAn or turn off OptB
#               PLEASE set OptA as non ValA or turn off OptB
#
# Example:      $(call DEP_ERR_SETA_OR_OFFB,MELODY_VER,DSP_WT_SYN,J2ME_SUPPORT)
#               PLEASE set MELODY_VER as DSP_WT_SYN or turn off J2ME_SUPPORT
# ------------------------------------------------------------------------
DEP_ERR_SETA_OR_OFFB = $(warning ERROR: PLEASE set $1 as $2 or turn off $3)
# ------------------------------------------------------------------------
# Usage:        $(call DEP_ERR_SETA_OR_ONB,OptA,ValA,OptB)
#               $(call DEP_ERR_SETA_OR_ONB,OptA,ValA1/ValA2/.../ValAn,OptB)
#               $(call DEP_ERR_SETA_OR_ONB,OptA,non ValA,OptB)
# Output:       PLEASE set OptA as ValA or turn on OptB
#               PLEASE set OptA as ValA1/ValA2/.../ValAn or turn on OptB
#               PLEASE set OptA as non ValA or turn on OptB
#
# Example:      $(call DEP_ERR_SETA_OR_ONB,MMS_SUPPORT,non OBIGO_Q05A,UNIFIED_MESSAGE_FOLDER)
#               PLEASE set MMS_SUPPORT as non OBIGO_Q05A or turn on UNIFIED_MESSAGE_FOLDER
# ------------------------------------------------------------------------
DEP_ERR_SETA_OR_ONB = $(warning ERROR: PLEASE set $1 as $2 or turn on $3)
# ------------------------------------------------------------------------
# Usage:        $(call DEP_ERR_OFFA_OR_OFFB,OptA,OptB)
# Output:       PLEASE turn off OptA or turn off OptB
#
# Example:      $(call DEP_ERR_OFFA_OR_OFFB,CMUX_SUPPORT,BLUETOOTH_SUPPORT)
#               PLEASE turn off CMUX_SUPPORT or turn off BLUETOOTH_SUPPORT
# ------------------------------------------------------------------------
DEP_ERR_OFFA_OR_OFFB = $(warning ERROR: PLEASE turn off $1 or turn off $2)
# ------------------------------------------------------------------------
# Usage:        $(call DEP_ERR_ONA_OR_ONB,OptA,OptB)
# Output:       PLEASE turn on OptA or turn on OptB
#
# Example:      $(call DEP_ERR_ONA_OR_ONB,UCM_SUPPORT,VOIP_SUPPORT)
#               PLEASE turn on UCM_SUPPORT or turn on VOIP_SUPPORT
# ------------------------------------------------------------------------
DEP_ERR_ONA_OR_ONB = $(warning ERROR: PLEASE turn on $1 or turn on $2)
# *************************************************************************
# Set defaul value to eliminate "option not define" warning
# *************************************************************************
BM_NEW      = FALSE

ifndef PROJECT_NAME
$(error PROJECT_NAME is not defined)
endif
ifndef PROJECT_MAKEFILE
$(error PROJECT_MAKEFILE is not defined)
endif
ifndef FLAVOR
$(error FLAVOR is not defined)
endif

# *************************************************************************
# Include temporary build script
# *************************************************************************

# Custom specific build script
include make/Custom.bld         # Custom release build
# default cmd setting
include make/cmd_cfg.mak

ifndef CUSTOM_RELEASE
  CUSTOM_RELEASE = FALSE         # Default custom release
endif
ifndef MTK_SUBSIDIARY
  MTK_SUBSIDIARY = FALSE
endif

-include make/Verno.bld
HW_VER := $(call Upper,$(strip $(PROJECT_NAME)))_HW
include $(PROJECT_MAKEFILE)

ifndef CUSTOM_FLAVOR
$(error CUSTOM_FLAVOR is not defined)
endif

-include $(strip $(TMPDIR))/~buildinfo.tmp
-include $(strip $(TMPDIR))/~net_path.tmp
-include $(strip $(TMPDIR))/cus_folder.tmp
-include make/USER_SPECIFIC.mak

ENABLE_PARTIAL_TRACE=FALSE
ifdef KAL_TRACE_OUTPUT
  ifdef PARTIAL_TRACE_LIB
    ifeq ($(strip $(KAL_TRACE_OUTPUT)),CUST_PARTIAL)
      ifneq ($(strip $(PARTIAL_TRACE_LIB)),)
        ENABLE_PARTIAL_TRACE=TRUE
      endif
    endif
  endif
endif

COMMINCDIRS    += $(CUSTOM_COMMINC)
COM_DEFS       += $(CUSTOM_OPTION)

#*************************************************************************
# auto-add interface/* folder to global include path if it exist *.h 
#*************************************************************************
#disable since some interface folder cannot open
#COMMINCDIRS += $(call uniq,$(patsubst %/,%,$(dir $(shell $(RECURSIVE_DIR) interface "\.h"))))
COMMINCDIRS += interface/common 
COMMINCDIRS += interface/driver/audio 
COMMINCDIRS += interface/driver/cipher/include 
COMMINCDIRS += interface/driver/cmux 
COMMINCDIRS += interface/driver/connectivity/sdio_device
COMMINCDIRS += interface/driver/connectivity/usb_driver 
COMMINCDIRS += interface/driver/dp_engine/che
COMMINCDIRS += interface/driver/drv_sw_def 
COMMINCDIRS += interface/driver/hwdrv 
COMMINCDIRS += interface/driver/peripheral 
COMMINCDIRS += interface/driver/sleep_drv 
COMMINCDIRS += interface/driver/storage 
COMMINCDIRS += interface/driver/storage/mc 
COMMINCDIRS += interface/driver/storage/sim 
COMMINCDIRS += interface/driver/sys_drv 
COMMINCDIRS += interface/middleware/general 
COMMINCDIRS += interface/middleware/gps 
COMMINCDIRS += interface/middleware/media 
COMMINCDIRS += interface/middleware/meta 
COMMINCDIRS += interface/modem/general 
COMMINCDIRS += interface/modem/l1/fdd/external 
COMMINCDIRS += interface/modem/l1/gsm/external 
COMMINCDIRS += interface/modem/l1/tdd 
COMMINCDIRS += interface/modem/mcd 
COMMINCDIRS += interface/modem/tl1interface 
COMMINCDIRS += interface/sap 
COMMINCDIRS += interface/sap/drv 
COMMINCDIRS += interface/sap/md
COMMINCDIRS += interface/sap/mw 
COMMINCDIRS += interface/sap/svc 
COMMINCDIRS += interface/sap/cross_core 
COMMINCDIRS += interface/service/asn1_common 
COMMINCDIRS += interface/service/config 
COMMINCDIRS += interface/service/event_info 
COMMINCDIRS += interface/service/fota 
COMMINCDIRS += interface/service/fs 
COMMINCDIRS += interface/service/fsm 
COMMINCDIRS += interface/service/kal 
COMMINCDIRS += interface/service/nvram 
COMMINCDIRS += interface/service/qmu_bm
COMMINCDIRS += interface/service/sst 
COMMINCDIRS += interface/service/stacklib 
COMMINCDIRS += interface/service/sys_svc 
COMMINCDIRS += interface/service/flc2 
ifeq ($(strip $(DHL_SUPPORT)),TRUE)
  COMMINCDIRS += interface/service/dhl
else
  COMMINCDIRS += interface/service/tst
endif
# *************************************************************************
# Include checkvalue.mak to check invalid feature values.
# *************************************************************************
-include make/checkvalue.mak
-include make/OLD_FEATURES.mak


ifndef RTOS
  RTOS = NUCLEUS
endif

ifndef RTOS_DEBUG
  RTOS_DEBUG = TRUE
endif

ifeq ($(strip $(RTOS)),NUCLEUS)
  COMMINCDIRS    += interface/service/kal
endif

ifeq ($(strip $(RTOS)),NUCLEUS_V2)
  COMMINCDIRS    += interface/service/kal
endif

ifeq ($(strip $(RTOS)),THREADX)
  COMMINCDIRS   +=  threadx/inc \
                    interface/service/kal \
                    service/kal/threadx/include
endif

ifeq ($(strip $(RTOS)),NUCLEUS)
  COM_DEFS += KAL_ON_NUCLEUS
  ifeq ($(strip $(RTOS_DEBUG)),TRUE)
     COM_DEFS += NU_DEBUG
  else
     COM_DEFS += NU_NO_ERROR_CHECKING
  endif
endif

ifeq ($(strip $(RTOS)),NUCLEUS_V2)
  COM_DEFS += KAL_ON_NUCLEUS __NUCLEUS_VERSION_2__
  ifeq ($(strip $(RTOS_DEBUG)),TRUE)
     COM_DEFS += NU_DEBUG
  else
     COM_DEFS += NU_NO_ERROR_CHECKING
  endif
endif

ifeq ($(strip $(RTOS)),THREADX)
  COM_DEFS += KAL_ON_THREADX
  COM_DEFS += TX_ENABLE_IRQ_NESTING TX_DISABLE_NOTIFY_CALLBACKS \
              TX_DISABLE_PREEMPTION_THRESHOLD TX_DISABLE_STACK_FILLING TX_REACTIVE_INLINE
  ifneq ($(strip $(RTOS_DEBUG)),TRUE)
     COM_DEFS += TX_DISABLE_ERROR_CHECKING
  endif
endif

CPU_ARCH = CR4
ifneq ($(filter MT6752,$(PLATFORM)),)
  ifeq ($(strip $(MDSYS)),MD2)
    CPU_ARCH = ARM9
  endif
endif

ifneq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  COMMINCDIRS    += $(strip $(TSTDIR))/database/unionTag
endif


ifeq ($(filter BASIC,$(TEST_LOAD_TYPE)),)
  COMP_TRACE_DEFS_MODEM    += driver/drv/include/drv_trc.h
endif

ifeq ($(filter UDVT,$(TEST_LOAD_TYPE)),)
  COMP_TRACE_DEFS_MODEM    += driver/drv/include/drv_trc.h
endif

ifneq ($(strip $(RAM_SUPPORT_TYPE)),NONE)
  COMP_TRACE_DEFS_MODEM += driver/devdrv/emi/inc/emi_trace.h
endif

COMMINCDIRS    += driver/drv_def

COMMINCDIRS    += driver/sys_drv/pmu/inc
#COMMINCDIRS   +=  interface/hal
COMMINCDIRS    += interface/driver/connectivity/usb_driver
COMMINCDIRS    += interface/driver/audio
COMMINCDIRS    += interface/driver/drv_sw_def
COMMINCDIRS    += interface/driver/storage/mc
COMMINCDIRS    += interface/driver/storage/sim
COMMINCDIRS    += interface/driver/peripheral
COMMINCDIRS    += interface/driver/cipher/include
COMMINCDIRS    += interface/driver/devdrv/coresight
COMMINCDIRS    += interface/driver/devdrv/cpu
COMMINCDIRS    += interface/driver/devdrv/gdma
COMMINCDIRS    += interface/driver/devdrv/busmon
#COMMINCDIRS    += interface/driver/devdrv/hif
#COMMINCDIRS    += interface/driver/devdrv/hif/hif_cldmadev
#COMMINCDIRS    += interface/driver/devdrv/hif/hif_sdiodev
#COMMINCDIRS    += interface/driver/devdrv/hif/hif_usbdev
#COMMINCDIRS    += interface/driver/devdrv/l2copro
COMMINCDIRS    += interface/driver/devdrv/pcmon
COMMINCDIRS    += interface/driver/devdrv/rstctl
COMMINCDIRS    += interface/driver/drvtest
COMMINCDIRS    += interface/middleware/meta
#COMMINCDIRS    += interface/driver/security
COMMINCDIRS    += interface/service/sst
ifeq ($(strip $(DHL_MALMO_SUPPORT)),TRUE)
  COMMINCDIRS    += interface/driver/devdrv/malmo
endif

ifeq ($(filter BASIC,$(TEST_LOAD_TYPE)),)
  COMPLIST += sleep_drv sys_svc sys_drv tty devdrv qmu_bm tft_pf ratadp upcm
  ifeq ($(strip $(HIF_USB_SUPPORT)),TRUE)
    COMPLIST += drv_hif
  else
    ifeq ($(strip $(HIF_SDIO_SUPPORT)),TRUE)
      COMPLIST += drv_hif
    endif
  endif
else
  COMPLIST += sleep_drv sys_svc sys_drv tty devdrv qmu_bm
endif

ifeq ($(strip $(PLATFORM)),MT6752)
  ifeq ($(MDSYS),MD2)
    COMPLIST += peripheral
    COMPLIST += sim_driver
    #COMPLIST += mtd
  endif
endif

ifeq ($(strip $(HW_PFC_SUPPORT)),TRUE)
  COMPLIST += drv_pfc
endif

#COMPLIST += mtd sim_driver sys_svc_sec usb_driver
COMPLIST += sys_svc_sec

# GEMINI
ifdef GEMINI
  ifneq ($(strip $(GEMINI)),FALSE)
    ifneq ($(strip $(GEMINI)),2)
      ifneq ($(filter __LOWCOST_MERGE_TASK__,$(COM_DEFS)),)
            $(warning ERROR: __LOWCOST_MERGE_TASK__ cannot be defined when GEMINI_PLUS is larger than 2)
            DEPENDENCY_CONFLICT = TRUE
      endif
    endif

    COMPLIST += rsva
    
    ifdef UNIFIED_MESSAGE_FOLDER
      ifeq ($(strip $(UNIFIED_MESSAGE_FOLDER)),TRUE)
        ifneq ($(strip $(MMS_SUPPORT)), OBIGO_Q03C_MMS_V02)
          $(call DEP_ERR_ONA_OR_OFFB,MMS_SUPPORT,GEMINI & UNIFIED_MESSAGE)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif

    COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1a_trace.h

    COM_DEFS += __GEMINI__ __GEMINI_GSM__ __GSM_RAT__ DRV_MULTIPLE_SIM __CTA_DUAL_SIM_STANDARD__
    COM_DEFS += __L4C_ROOT__ __GEMINI_3G_SWITCH__

    # assign GEMINI to GEMINI_PLUS_GSM
    ifndef GEMINI_PLUS
      GEMINI_PLUS = $(strip $(GEMINI))
    endif
    ifndef GEMINI_PLUS_GSM
      GEMINI_PLUS_GSM = $(strip $(GEMINI))
    endif

    COM_DEFS    += GEMINI_PLUS=$(strip $(GEMINI))
    COM_DEFS    += GEMINI_PLUS_GSM=$(strip $(GEMINI_PLUS_GSM))
       
    COMPLIST += as_semaphore_utility
  endif
endif

# GPS_SUPPORT
ifdef GPS_SUPPORT
  ifeq ($(strip $(GPS_SUPPORT)),SMART_PHONE_MODEM)
    COM_DEFS    += __GPS_SUPPORT__
  endif
endif

#always enable except l1s/basic
ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  COMP_TRACE_DEFS_MODEM += middleware/lbs/common/inc/lbs_trc.h
  COMPLIST    += lbs
else
  COM_DEFS += LBS_NOT_PRESENT
endif

ifneq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
  ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
    COM_DEFS    +=  IDMA_DOWNLOAD
  endif
endif

ifneq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  COM_DEFS +=  EMPTY_MMI
endif

ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
  COMP_TRACE_DEFS_MODEM    += driver/audio/src/v2/inc/l1sp_trc.h
else
  COMP_TRACE_DEFS_MODEM    += driver/audio/src/v1/inc/l1sp_trc.h
endif

ifneq ($(strip $(MODIS_CONFIG)),TRUE)
  ifeq ($(filter __MAUI_BASIC__,$(COM_DEFS)),)
    ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
      COMP_TRACE_DEFS_MODEM    += driver/audio/src/v2/inc/l1audio_sph_trc.h
    else
      COMP_TRACE_DEFS_MODEM    += driver/audio/src/v1/inc/l1audio_sph_trc.h
    endif
  endif
endif

ifdef DT_SUPPORT
  ifneq ($(strip $(DT_SUPPORT)),FALSE)
    ifeq ($(filter L1S BASIC UDVT,$(strip $(TEST_LOAD_TYPE))),)
      COMP_TRACE_DEFS_MODEM   += $(strip $(MODEM_FOLDER))/l4/dt/include/dt_trc.h
    endif
  endif
endif

ifeq ($(filter L1S BASIC UDVT,$(strip $(TEST_LOAD_TYPE))),)
  #COMP_TRACE_DEFS_MODEM   += inet_ps\ems\include\ems_trc.h
  ifneq ($(filter __MTK_3G_MRAT_ARCH__,$(strip $(COM_DEFS))),)
    COMP_TRACE_DEFS_MODEM   +=    $(strip $(GAS_FOLDER))/mpal/include/mpal_trace.h
  else
    ifeq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_EGPRS_MODE)
      ifeq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
        COMP_TRACE_DEFS_MODEM   +=    $(strip $(GAS_FOLDER))/mpal/include/mpal_trace.h
      endif
    endif
  endif
endif

  L1_TMD_FILES   +=   $(strip $(SLEEPDRV_FOLDER))/common/DCXO_DIV_Trace1.tmd \
                      $(strip $(SLEEPDRV_FOLDER))/common/OSTD_Trace1.tmd \
                      $(strip $(SLEEPDRV_FOLDER))/common/SleepDrv_Trace1.tmd \
                      $(strip $(SLEEPDRV_FOLDER))/common/MD_TOPSM_Trace1.tmd \
                      $(strip $(SLEEPDRV_FOLDER))/common/MODEM_TOPSM_Trace1.tmd
                      
ifneq ($(filter __MTK_3G_MRAT_ARCH__,$(strip $(COM_DEFS))),)
  L1_TMD_FILES   +=   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1D3_Trace.tmd \
                      $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1_AFC_Trace.tmd \
                      $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c3_trace.tmd \
                      $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c4_trace.tmd \
                      $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c5_trace.tmd
  L1_TMD_FILES   +=   $(strip $(MODEM_FOLDER))/md_sm/common/l1sm/L1SM_Trace1.tmd
else
  ifeq ($(call Upper,$(strip $(L1_WCDMA))),TRUE)
    L1_TMD_FILES   +=   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1D3_Trace.tmd \
                        $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1_AFC_Trace.tmd \
                        $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c3_trace.tmd \
                        $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c4_trace.tmd \
                        $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c5_trace.tmd
    L1_TMD_FILES   +=   $(strip $(MODEM_FOLDER))/md_sm/common/l1sm/L1SM_Trace1.tmd
  else
    ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
    L1_TMD_FILES   +=   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1D3_Trace.tmd \
                        $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/L1_AFC_Trace.tmd \
                        $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c3_trace.tmd \
                        $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c4_trace.tmd \
                        $(strip $(MODEM_FOLDER))/gl1/l1_dm/common/l1c5_trace.tmd
    L1_TMD_FILES   +=   $(strip $(MODEM_FOLDER))/md_sm/common/l1sm/L1SM_Trace1.tmd    
    endif
  endif
endif

ifeq ($(strip $(EUTRAN_MODE_SUPPORT)),EUTRAN_MODE)
  ifeq ($(strip $(NO_LTELIB)),FALSE)
    L1_TMD_FILES += $(strip $(MODEM_FOLDER))/md_sm/common/el1sm/EL1SM_Trace1.tmd
  endif
endif



COMP_TRACE_DEFS_MODEM += driver/dp_engine/dp_engine_trc.h


# ---------------------------------------------------------------
# The followings are global options from $(PROJECT_NAME).bld
# ---------------------------------------------------------------
# Platform Options
COM_DEFS_FOR_FPGA    = FPGA
COM_DEFS_FOR_ASTRO36V2_DEMO_AD6546    = AD6546_RF ASTRO36V2_DEMO_AD6546

COM_DEFS_FOR_MT6575  = MT6575 __HW_DIVIDER__ MT6575_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6577  = MT6577 __HW_DIVIDER__ MT6577_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6280  = MT6280 __HW_DIVIDER__ MT6280_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6752  = MT6752 __HW_DIVIDER__ MT6752_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6290  = MT6290 __HW_DIVIDER__ MT6290_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6595  = MT6595                MT6595_$(strip $(CHIP_VER))
COM_DEFS_FOR_MT6795  = MT6795                MT6795_$(strip $(CHIP_VER)) MT6595 MT6595_$(strip $(CHIP_VER))

COM_DEFS_FOR_PLATFORM =  COM_DEFS_FOR_$(strip $(PLATFORM))
ifdef $(COM_DEFS_FOR_PLATFORM)
  COM_DEFS +=  $(COM_DEFS_FOR_$(strip $(PLATFORM)))
else
  $(warning ERROR: [COM_DEFS_FOR_$(strip $(PLATFORM))] was not defined)
  DEPENDENCY_CONFLICT = TRUE
endif

# RF Module Options
# Move to project.mak except EVB
COM_DEFS_FOR_BRIGHT4                  = BRIGHT4_RF BRIGHT4_EVB
COM_DEFS_FOR_EUROPA                   = MT6129C_RF EUROPA_EVB
COM_DEFS_FOR_FOUNTAIN2                = MT6119C_RF FOUNTAIN2_EVB  FOUNTAIN2_RF
COM_DEFS_FOR_MT6129C                  = MT6129C_RF MT6129C_EVB
COM_DEFS_FOR_MT6129D                  = MT6129D_RF MT6129D_EVB
COM_DEFS_FOR_MT6139B                  = MT6139B_RF MT6139B_EVB
COM_DEFS_FOR_MT6139C                  = MT6139C_RF MT6139C_EVB
COM_DEFS_FOR_MT6139E                  = MT6139E_RF MT6139E_EVB
COM_DEFS_FOR_MT6140A                  = MT6140A_RF MT6140A_EVB
COM_DEFS_FOR_MT6140C                  = MT6140C_RF MT6140C_EVB
COM_DEFS_FOR_MT6140D                  = MT6140D_RF MT6140D_EVB
COM_DEFS_FOR_SKY74117                 = SKY74117_RF SKY74117_EVB
COM_DEFS_FOR_SKY74137                 = SKY74137_RF SKY74137_EVB
COM_DEFS_FOR_SKY74045                 = SKY74045_RF SKY74045_EVB
COM_DEFS_FOR_BRIGHT5P                 = BRIGHT5P_RF BRIGHT5P_EVB
COM_DEFS_FOR_AERO2                    = AERO2_RF   AERO2_EVB
COM_DEFS_FOR_SONY_CXA3359             = SONY_CXA3359_RF SONY_CXA3359_EVB
COM_DEFS_FOR_SMARTI3G                 = SMARTI3G_RF SMARTI3G_EVB
COM_DEFS_FOR_MTKSOC1                  = MTKSOC1_RF MTKSOC1_EVB
COM_DEFS_FOR_MT6253ELRF               = MT6253ELRF_RF MT6253ELRF_EVB
COM_DEFS_FOR_MT6250RF                 = MT6250RF_RF MT6250RF_EVB
COM_DEFS_FOR_MT6250RF_CUSTOM          = MT6250RF_RF MT6250RF_CUSTOM
COM_DEFS_FOR_MT6255RF                 = MT6255RF_RF MT6255RF_EVB
COM_DEFS_FOR_MT6255RF_CUSTOM          = MT6255RF_RF MT6255RF_CUSTOM
COM_DEFS_FOR_MT6922RF                 = MT6922RF_RF MT6922RF_EVB
COM_DEFS_FOR_MT6922RF_CUSTOM          = MT6922RF_RF MT6922RF_CUSTOM
COM_DEFS_FOR_CHAMPAGNE55N_DEMO_MT6255RF  = MT6255RF_RF CHAMPAGNE55N_DEMO_MT6255RF
COM_DEFS_FOR_MT6256RF                 = MT6256RF_RF MT6256RF_EVB
COM_DEFS_FOR_MT6256RF_CUSTOM          = MT6256RF_RF MT6256RF_CUSTOM
COM_DEFS_FOR_MT6251RF                 = MT6251RF_RF MT6251RF_EVB
COM_DEFS_FOR_MT6251RF_CUSTOM          = MT6251RF_RF MT6251RF_CUSTOM
COM_DEFS_FOR_SPARROW51_DEMO_MT6251RF  = MT6251RF_RF SPARROW51_DEMO_MT6251RF
COM_DEFS_FOR_SPARROW51V2_DEMO_MT6251RF  = MT6251RF_RF SPARROW51V2_DEMO_MT6251RF
COM_DEFS_FOR_MT6160                   = MT6160_RF MT6160_EVB
COM_DEFS_FOR_AD6546                   = AD6546_RF AD6546_EVB
COM_DEFS_FOR_TECHFAITH68_DEMO_MT6160  = MT6160_RF TECHFAITH68_DEMO_MT6160
COM_DEFS_FOR_TECHFAITH68_DEMO_AD6546  = AD6546_RF TECHFAITH68_DEMO_AD6546
COM_DEFS_FOR_MT6162                   = MT6162_RF MT6162_EVB
COM_DEFS_FOR_MT6162_DUAL              = MT6162_DUAL_RF MT6162_EVB
COM_DEFS_FOR_MT6163_2G                = MT6163_2G_RF MT6163_2G_EVB
COM_DEFS_FOR_MT6168_2G                = MT6168_2G_RF MT6168_2G_EVB
COM_DEFS_FOR_NAMI70_DEMO_MT6162       = MT6162_RF NAMI70_DEMO_MT6162
COM_DEFS_FOR_LION52V2_NC_128X128_DEMO_MT6252RF  = MT6252RF_RF LION52V2_NC_128X128_DEMO_MT6252RF
COM_DEFS_FOR_LION52H_V2_6432_MT6252RF  = MT6252RF_RF LION52H_V2_6432_MT6252RF
COM_DEFS_FOR_LION52_V2_DEMO_MT6252RF  = MT6252RF_RF LION52_V2_DEMO_MT6252RF
COM_DEFS_FOR_LION52V2_NC_128X128_DEMO_MT6252RF  = MT6252RF_RF LION52V2_NC_128X128_DEMO_MT6252RF
COM_DEFS_FOR_LION52V2_NB_96X64_DEMO_MT6252RF  = MT6252RF_RF LION52V2_NB_96X64_DEMO_MT6252RF
COM_DEFS_FOR_WISTRON_DUAL_DEMO_LCM = HX8340B COLOR_LCD WISTRON_DUAL_DEMO_LCM TFT_MAINLCD COLOR_SUBLCD DUAL_LCD
COM_DEFS_FOR_TRULY_HVGA_IPS320480_52_LCM = IPS320480_52 COLOR_LCD TRULY_HVGA_IPS320480_52_LCM TFT_MAINLCD
COM_DEFS_FOR_MT6280RF_2G              = MT6280RF_2G_RF MT6280RF_2G_EVB
COM_DEFS_FOR_MT6167_2G                = MT6167_2G_RF MT6167_2G_EVB
COM_DEFS_FOR_MT6169_2G                = MT6169_2G_RF MT6169_2G_EVB
COM_DEFS_FOR_MT6169_MIFI_2G           = MT6169_2G_RF MT6169_2G_EVB
COM_DEFS_FOR_MT6166_DUAL_TALK_2G      = MT6166_2G_RF MT6166_2G_EVB
COM_DEFS_FOR_MT6165_DUAL_TALK_2G      = MT6165_2G_RF MT6165_2G_EVB

COM_DEFS_FOR_MT6280RF_UMTS_FDD        = MT6280RF_UMTS_FDD_RF MT6280RF_UMTS_FDD_EVB
COM_DEFS_FOR_MT6167_UMTS_FDD = MT6167_RF MT6167_UMTS_FDD
COM_DEFS_FOR_MT6169_UMTS_FDD = MT6169_RF MT6169_UMTS_FDD
COM_DEFS_FOR_MT6169_UMTS_FDD_MIFI = MT6169_RF MT6169_UMTS_FDD
COM_DEFS_FOR_MT6250_ILI9486_HVGA_LCM = ILI9486 COLOR_LCD MT6250_ILI9486_HVGA_LCM TFT_MAINLCD
COM_DEFS_FOR_KUBLAI50_V11_DEMO_LCM = ST7735 COLOR_LCD KUBLAI50_V11_DEMO_LCM TFT_MAINLCD
COM_DEFS_FOR_MT6169_UMTS_TDD = MT6169_RF MT6169_UMTS_TDD
COM_DEFS_FOR_MT6169_LTE = MT6169_RF MT6169_LTE_RF
COM_DEFS_FOR_MT6169_LTE_MIFI = MT6169_RF MT6169_LTE_RF
COM_DEFS_FOR_MT6290_EVB_MT6169RF_UMTS_TDD = MT6169_RF MT6169_UMTS_TDD
COM_DEFS_FOR_MT6290_EVB_MT6169RF_UMTS_TDD_MIFI = MT6169_RF MT6169_UMTS_TDD

# For Internal Phoone
COM_DEFS_FOR_MT6582LTE_2G_MT6169       = MT6169_2G_RF MT6169_2G_EVB
COM_DEFS_FOR_MT6582LTE_2G_MT6166       = MT6166_2G_RF MT6166_2G_EVB
COM_DEFS_FOR_MT6582LTE_2G_MT6165       = MT6165_2G_RF MT6165_2G_EVB
COM_DEFS_FOR_MT6582LTE_UMTS_FDD_MT6169 = MT6169_RF MT6169_UMTS_FDD MT6169_UMTS_FDD_CUSTOM
COM_DEFS_FOR_MT6582LTE_UMTS_TDD_MT6169 = MT6169_RF MT6169_UMTS_TDD MT6169_UMTS_TDD_CUSTOM
COM_DEFS_FOR_MT6582LTE_LTE_MT6169      = MT6169_RF MT6169_LTE_RF MT6169_LTE_RF_CUSTOM
COM_DEFS_FOR_A1EU_2G_MT6169            = MT6169_2G_RF
COM_DEFS_FOR_A1EU_UMTS_FDD_MT6169      = MT6169_RF MT6169_UMTS_FDD
COM_DEFS_FOR_A1EU_LTE_MT6169           = MT6169_RF MT6169_LTE_RF
COM_DEFS_FOR_A1US_2G_MT6169            = MT6169_2G_RF
COM_DEFS_FOR_A1US_UMTS_FDD_MT6169      = MT6169_RF MT6169_UMTS_FDD 
COM_DEFS_FOR_A1US_LTE_MT6169           = MT6169_RF MT6169_LTE_RF
COM_DEFS_FOR_V1UK_2G_MT6169            = MT6169_2G_RF
COM_DEFS_FOR_V1UK_UMTS_FDD_MT6169      = MT6169_RF MT6169_UMTS_FDD 
COM_DEFS_FOR_V1UK_LTE_MT6169           = MT6169_RF MT6169_LTE_RF
COM_DEFS_FOR_V1UK_EVB_2G_MT6169        = MT6169_2G_RF
COM_DEFS_FOR_V1UK_EVB_UMTS_FDD_MT6169  = MT6169_RF MT6169_UMTS_FDD 
COM_DEFS_FOR_V1UK_EVB_LTE_MT6169       = MT6169_RF MT6169_LTE_RF
COM_DEFS_FOR_RIO5EU_2G_MT6169          = MT6169_2G_RF
COM_DEFS_FOR_RIO5EU_UMTS_FDD_MT6169    = MT6169_RF MT6169_UMTS_FDD
COM_DEFS_FOR_RIO5EU_LTE_MT6169         = MT6169_RF MT6169_LTE_RF
COM_DEFS_FOR_RIO5US_2G_MT6169          = MT6169_2G_RF
COM_DEFS_FOR_RIO5US_UMTS_FDD_MT6169    = MT6169_RF MT6169_UMTS_FDD 
COM_DEFS_FOR_RIO5US_LTE_MT6169         = MT6169_RF MT6169_LTE_RF

# For Customer projects.
COM_DEFS_FOR_MT6140_CUSTOM = MT6140D_RF MT6140_CUSTOM
COM_DEFS_FOR_MT6139_CUSTOM = MT6139E_RF MT6139_CUSTOM
COM_DEFS_FOR_MT6129_CUSTOM = MT6129D_RF MT6129_CUSTOM
COM_DEFS_FOR_AD6548_CUSTOM = AD6548_RF AD6548_CUSTOM
COM_DEFS_FOR_AD6546_CUSTOM = AD6546_RF AD6546_CUSTOM
COM_DEFS_FOR_MT6162_CUSTOM = MT6162_RF MT6162_CUSTOM
COM_DEFS_FOR_MT6162_DUAL_CUSTOM = MT6162_DUAL_RF MT6162_DUAL_CUSTOM
COM_DEFS_FOR_MT6163_2G_CUSTOM = MT6163_2G_RF MT6163_2G_CUSTOM
COM_DEFS_FOR_MT6168_2G_CUSTOM = MT6168_2G_RF MT6168_2G_CUSTOM
COM_DEFS_FOR_SKY74137_CUSTOM = SKY74137_RF SKY74137_CUSTOM
COM_DEFS_FOR_UNICORN53_DEMO_MTKSOC1 = MTKSOC1_RF UNICORN53_DEMO_MTKSOC1
COM_DEFS_FOR_UNICORN53V2_DEMO_MTKSOC1 = MTKSOC1_RF UNICORN53V2_DEMO_MTKSOC1
COM_DEFS_FOR_UNICORN53V3_DEMO_MTKSOC1 = MTKSOC1_RF UNICORN53V3_DEMO_MTKSOC1
COM_DEFS_FOR_UNICORN53V4_DEMO_MTKSOC1 = MTKSOC1_RF UNICORN53V4_DEMO_MTKSOC1
COM_DEFS_FOR_UNICORN53V3_DEMO_GSM_MTKSOC1 = MTKSOC1_RF UNICORN53V3_DEMO_GSM_MTKSOC1
COM_DEFS_FOR_MT6161_AST = MT6161_RF
COM_DEFS_FOR_MT6280_CUSTOM = MT6280RF_2G_RF MT6280RF_2G_CUSTOM
COM_DEFS_FOR_MT6169_2G_CUSTOM = MT6169_2G_RF MT6169_2G_CUSTOM
COM_DEFS_FOR_MT6169_MIFI_2G_CUSTOM = MT6169_2G_RF MT6169_2G_CUSTOM
COM_DEFS_FOR_MT6169_UMTS_FDD_CUSTOM = MT6169_RF MT6169_UMTS_FDD MT6169_UMTS_FDD_CUSTOM
COM_DEFS_FOR_MT6169_UMTS_FDD_MIFI_CUSTOM = MT6169_RF MT6169_UMTS_FDD MT6169_UMTS_FDD_CUSTOM
COM_DEFS_FOR_MT6169_UMTS_TDD_CUSTOM = MT6169_RF MT6169_UMTS_TDD MT6169_UMTS_TDD_CUSTOM
COM_DEFS_FOR_MT6169_LTE_CUSTOM = MT6169_RF MT6169_LTE_RF MT6169_LTE_RF_CUSTOM
COM_DEFS_FOR_K82V2_2G_MT6169       = MT6169_2G_RF MT6169_2G_EVB
COM_DEFS_FOR_K82V2_UMTS_FDD_MT6169 = MT6169_RF MT6169_UMTS_FDD MT6169_UMTS_FDD_CUSTOM
COM_DEFS_FOR_K82V2_UMTS_FDD_MT6169_DCMIOT = MT6169_RF MT6169_UMTS_FDD MT6169_UMTS_FDD_CUSTOM
COM_DEFS_FOR_K82V2_LTE_MT6169      = MT6169_RF MT6169_LTE_RF MT6169_LTE_RF_CUSTOM
COM_DEFS_FOR_K82V2_UMTS_TDD_MT6169 = MT6169_RF MT6169_UMTS_TDD MT6169_UMTS_TDD_CUSTOM
COM_DEFS_FOR_HERO2_2G_MT6165       = MT6165_2G_RF MT6165_2G_EVB
COM_DEFS_FOR_HERO2_2G_MT6169       = MT6169_2G_RF MT6169_2G_EVB
COM_DEFS_FOR_HERO2_UMTS_FDD_MT6169 = MT6169_RF MT6169_UMTS_FDD MT6169_UMTS_FDD_CUSTOM
COM_DEFS_FOR_HERO2_UMTS_TDD_MT6169 = MT6169_RF MT6169_UMTS_TDD MT6169_UMTS_TDD_CUSTOM
COM_DEFS_FOR_HERO2_LTE_MT6169      = MT6169_RF MT6169_LTE_RF MT6169_LTE_RF_CUSTOM
COM_DEFS_FOR_K82CMCC_2G_MT6169       = MT6169_2G_RF MT6169_2G_EVB
COM_DEFS_FOR_K82CMCC_UMTS_FDD_MT6169 = MT6169_RF MT6169_UMTS_FDD MT6169_UMTS_FDD_CUSTOM
COM_DEFS_FOR_K82CMCC_LTE_MT6169      = MT6169_RF MT6169_LTE_RF MT6169_LTE_RF_CUSTOM
COM_DEFS_FOR_K82CMCC_LTE_TDD_MT6169  = MT6169_RF MT6169_LTE_RF MT6169_LTE_RF_CUSTOM
COM_DEFS_FOR_K95_EU_LTE_MT6169 = MT6169_RF MT6169_LTE_RF
COM_DEFS_FOR_K95_EU_2G_MT6169  = MT6169_2G_RF 
COM_DEFS_FOR_K95_EU_UMTS_FDD_MT6169 = MT6169_RF MT6169_UMTS_FDD
COM_DEFS_FOR_K95_US_LTE_MT6169 = MT6169_RF MT6169_LTE_RF
COM_DEFS_FOR_K95_US_2G_MT6169  = MT6169_2G_RF 
COM_DEFS_FOR_K95_US_UMTS_FDD_MT6169 = MT6169_RF MT6169_UMTS_FDD
COM_DEFS_FOR_K95_VERIZON_LTE_MT6169 = MT6169_RF MT6169_LTE_RF
COM_DEFS_FOR_K95_VERIZON_2G_MT6169  = MT6169_2G_RF 
COM_DEFS_FOR_K95_VERIZON_UMTS_FDD_MT6169 = MT6169_RF MT6169_UMTS_FDD

COM_DEFS_FOR_MT6582LTE_2G_MT6165_CUSTOM = MT6165_2G_RF MT6165_2G_EVB
COM_DEFS_FOR_K82V2_2G_MT6169_CUSTOM = MT6169_2G_RF MT6169_2G_EVB
COM_DEFS_FOR_K82V2_UMTS_TDD_MT6169_CUSTOM = MT6169_RF MT6169_UMTS_TDD MT6169_UMTS_TDD_CUSTOM
COM_DEFS_FOR_K82CMCC_2G_MT6169_CUSTOM = MT6169_2G_RF MT6169_2G_EVB
COM_DEFS_FOR_K82CMCC_LTE_MT6169_CUSTOM = MT6169_RF MT6169_LTE_RF MT6169_LTE_RF_CUSTOM
COM_DEFS_FOR_K82CMCC_UMTS_FDD_MT6169_CUSTOM = MT6169_RF MT6169_UMTS_FDD MT6169_UMTS_FDD_CUSTOM

COM_DEFS_FOR_AUBEST_CU_LTE_MT6169_CUSTOM = MT6169_RF MT6169_LTE_RF AUBEST_CU_LTE_MT6169_CUSTOM
COM_DEFS_FOR_AUBEST_CU_2G_MT6169_CUSTOM = MT6169_RF MT6169_2G_RF AUBEST_CU_2G_MT6169_CUSTOM 
COM_DEFS_FOR_AUBEST_CU_UMTS_FDD_MT6169_CUSTOM = MT6169_RF MT6169_UMTS_FDD AUBEST_CU_UMTS_FDD_MT6169_CUSTOM

COM_DEFS_FOR_K52_LTE_MT6169_CUSTOM = MT6169_RF MT6169_LTE_RF K52_LTE_MT6169_CUSTOM
COM_DEFS_FOR_K52_2G_MT6169_CUSTOM = MT6169_2G_RF K52_2G_MT6169_CUSTOM
COM_DEFS_FOR_K52_UMTS_FDD_MT6169_CUSTOM = MT6169_RF MT6169_UMTS_FDD K52_UMTS_FDD_MT6169_CUSTOM

COM_DEFS_FOR_MT6169_GGE_CUSTOM      = MT6169_RF MT6169_2G_RF MT6169_GGE_CUSTOM      
COM_DEFS_FOR_MT6165_GGE_CUSTOM      = MT6165_RF MT6165_2G_RF MT6165_GGE_CUSTOM      
COM_DEFS_FOR_MT6169_UMTS_FDD_CUSTOM = MT6169_RF MT6169_UMTS_FDD MT6169_UMTS_FDD_CUSTOM
COM_DEFS_FOR_MT6169_LTE_CUSTOM      = MT6169_RF MT6169_LTE_RF MT6169_LTE_CUSTOM    

COM_DEFS_FOR_MT6795_LTE_MT6169_CUSTOM = MT6169_RF MT6169_LTE_RF MT6795_LTE_MT6169_CUSTOM
COM_DEFS_FOR_MT6795_2G_MT6169_CUSTOM  = MT6169_2G_RF MT6795_2G_MT6169_CUSTOM
COM_DEFS_FOR_MT6795_UMTS_FDD_MT6169_CUSTOM = MT6169_RF MT6169_UMTS_FDD MT6795_UMTS_FDD_MT6169_CUSTOM
COM_DEFS_FOR_MT6795_K95_MT6169_UMTS_TDD_CUSTOM = MT6169_RF MT6169_UMTS_TDD MT6795_K95_MT6169_UMTS_TDD_CUSTOM

COM_DEFS_FOR_RF_MODULE =  COM_DEFS_FOR_$(strip $(RF_MODULE))
ifdef $(COM_DEFS_FOR_RF_MODULE)
  COM_DEFS +=  $(COM_DEFS_FOR_$(strip $(RF_MODULE)))
else
  $(warning ERROR: [COM_DEFS_FOR_$(strip $(RF_MODULE))] was not defined)
  DEPENDENCY_CONFLICT = TRUE
endif

ifdef UMTS_RF_MODULE
ifneq ($(strip $(UMTS_RF_MODULE)),NONE)
  COM_DEFS_FOR_RF_MODULE =  COM_DEFS_FOR_$(strip $(UMTS_RF_MODULE))
  ifdef $(COM_DEFS_FOR_RF_MODULE)
    COM_DEFS  +=  $(COM_DEFS_FOR_$(strip $(UMTS_RF_MODULE)))
  else
    $(warning ERROR: [COM_DEFS_FOR_$(strip $(UMTS_RF_MODULE))] was not defined)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
endif

ifdef UMTS_TDD128_RF_MODULE
ifneq ($(strip $(UMTS_TDD128_RF_MODULE)),NONE)
  COM_DEFS_FOR_RF_MODULE =  COM_DEFS_FOR_$(strip $(UMTS_TDD128_RF_MODULE))
  ifdef $(COM_DEFS_FOR_RF_MODULE)
    COM_DEFS  +=  $(COM_DEFS_FOR_$(strip $(UMTS_TDD128_RF_MODULE)))
  else
    $(warning ERROR: [COM_DEFS_FOR_$(strip $(UMTS_TDD128_RF_MODULE))] was not defined) 
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
endif

ifdef LTE_RF_MODULE
ifneq ($(strip $(LTE_RF_MODULE)),NONE)
  COM_DEFS_FOR_RF_MODULE =  COM_DEFS_FOR_$(strip $(LTE_RF_MODULE))
  ifdef $(COM_DEFS_FOR_RF_MODULE)
    COM_DEFS  +=  $(COM_DEFS_FOR_$(strip $(LTE_RF_MODULE)))
  else
    $(warning ERROR: [COM_DEFS_FOR_$(strip $(LTE_RF_MODULE))] was not defined) 
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
endif

# check AFC_VCXO_TYPE matches RF_MODULE
ifdef AFC_VCXO_TYPE
  ifdef RF_MODULE

    VCXO_PLATFORM = MT6139B MT6139C MT6139E
    ifneq ($(filter $(strip $(RF_MODULE)),$(VCXO_PLATFORM)),)
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCXO)
        ifeq ($(filter MT6268A MT6270A MT6276,$(strip $(PLATFORM))),)
          $(warning ERROR: MT6139 series RF_MODULE project must set AFC_VCXO_TYPE = VCXO )
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
    
    VCTCXO_RF_MODULE_LIST = MT6129D MT6129 MT6119 BRIGHT4 MT6140A SKY74117 SKY74045 BRIGHT5P FOUNTAIN
    ifneq ($(filter $(strip $(VCTCXO_RF_MODULE_LIST)),$(strip $(RF_MODULE))),)
      VCTCXO_RF_MODULE = $(filter $(strip $(VCTCXO_RF_MODULE_LIST)),$(strip $(RF_MODULE)))
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
        $(warning WARNING $(VCTCXO_RF_MODULE) series RF_MODULE project must set AFC_VCXO_TYPE = VCTCXO )
      endif
    endif

    VCXO_RF_MODULE_LIST = AERO MT6139
    ifneq ($(filter $(strip $(VCXO_RF_MODULE_LIST)),$(strip $(RF_MODULE))),)
      VCXO_RF_MODULE = $(filter $(strip $(VCXO_RF_MODULE_LIST)),$(strip $(RF_MODULE)))
      ifneq ($(strip $(AFC_VCXO_TYPE)),VCXO)
        $(warning WARNING $(VCXO_RF_MODULE) series RF_MODULE project must set AFC_VCXO_TYPE = VCXO )
      endif
    endif

  endif
endif

# Board Options
ifneq ($(strip $(BOARD_VER)),)
  COM_DEFS    += $(BOARD_VER)
endif

# Board Subversion
ifneq ($(strip $(SUB_BOARD_VER)),)
  COM_DEFS    += $(SUB_BOARD_VER)
endif

# BAND_SUPPORT Options
COM_DEFS_FOR_PGSM900   = __PGSM900__
COM_DEFS_FOR_EGSM900   = __EGSM900__
COM_DEFS_FOR_RGSM900   = __RGSM900__
COM_DEFS_FOR_DCS1800   = __DCS1800__
COM_DEFS_FOR_PCS1900   = __PCS1900__
COM_DEFS_FOR_GSM850    = __GSM850__
COM_DEFS_FOR_GSM450    = __GSM450__
COM_DEFS_FOR_DUAL900   = __EGSM900__ __DCS1800__
COM_DEFS_FOR_TRIPLE    = __EGSM900__ __DCS1800__ __PCS1900__
COM_DEFS_FOR_QUAD      = __EGSM900__ __DCS1800__ __PCS1900__  __GSM850__
COM_DEFS_FOR_DUAL850   = __GSM850__ __PCS1900__
COM_DEFS_FOR_TRIPLE850 = __GSM850__ __DCS1800__ __PCS1900__  TRIPLE850

COM_DEFS_FOR_BAND_SUPPORT =  COM_DEFS_FOR_$(strip $(BAND_SUPPORT))
ifdef $(COM_DEFS_FOR_BAND_SUPPORT)
  COM_DEFS +=  $(COM_DEFS_FOR_$(strip $(BAND_SUPPORT)))
else
  COM_DEFS += __EGSM900__ __DCS1800__   # the same as DUAL900
endif


# UMTS_BAND_SUPPORT Options
UMTS_SUPPORT_BAND =
ifdef UMTS_BAND_I
  ifeq ($(strip $(UMTS_BAND_I)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_I__
  endif
endif
ifdef UMTS_BAND_II
  ifeq ($(strip $(UMTS_BAND_II)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_II__
  endif
endif
ifdef UMTS_BAND_III
  ifeq ($(strip $(UMTS_BAND_III)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_III__
  endif
endif
ifdef UMTS_BAND_IV
  ifeq ($(strip $(UMTS_BAND_IV)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_IV__
  endif
endif
ifdef UMTS_BAND_V
  ifeq ($(strip $(UMTS_BAND_V)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_V__
    UMTS_SUPPORT_BAND  += __UMTS_BAND_VI__
  endif
endif
ifdef UMTS_BAND_VI
  ifeq ($(strip $(UMTS_BAND_VI)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_V__
    UMTS_SUPPORT_BAND  += __UMTS_BAND_VI__
  endif
endif
ifdef UMTS_BAND_VII
  ifeq ($(strip $(UMTS_BAND_VII)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_VII__
  endif
endif
ifdef UMTS_BAND_VIII
  ifeq ($(strip $(UMTS_BAND_VIII)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_VIII__
  endif
endif
ifdef UMTS_BAND_IX
  ifeq ($(strip $(UMTS_BAND_IX)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_IX__
  endif
endif
ifdef UMTS_BAND_X
  ifeq ($(strip $(UMTS_BAND_X)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_X__
  endif
endif
ifeq ($(strip $(UMTS_BAND_XI)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XI__
endif
ifeq ($(strip $(UMTS_BAND_XII)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XII__
endif
ifeq ($(strip $(UMTS_BAND_XIII)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XIII__
endif
ifeq ($(strip $(UMTS_BAND_XIV)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XIV__
endif
ifeq ($(strip $(UMTS_BAND_XV)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XV__
endif
ifeq ($(strip $(UMTS_BAND_XVI)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XVI__
endif
ifeq ($(strip $(UMTS_BAND_XVII)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XVII__
endif
ifeq ($(strip $(UMTS_BAND_XVIII)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XVIII__
endif
ifeq ($(strip $(UMTS_BAND_XIX)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XIX__
endif
ifeq ($(strip $(UMTS_BAND_XX)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XX__
endif
ifeq ($(strip $(UMTS_BAND_XXI)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XXI__
endif
ifeq ($(strip $(UMTS_BAND_XXII)),TRUE)
    UMTS_SUPPORT_BAND  += __UMTS_BAND_XXII__
endif
COM_DEFS    +=  $(strip $(UMTS_SUPPORT_BAND))
# Due to uas ul2 RRC Specification (InterRATHandoverInfo message) limitation, UE at most supports 4 bands in band I~VII.
UMTS_SUPPORT_BAND_I_TO_VII_COUNT = $(words $(filter __UMTS_BAND_I__ __UMTS_BAND_II__ __UMTS_BAND_III__ __UMTS_BAND_IV__ __UMTS_BAND_V__ __UMTS_BAND_VI__ __UMTS_BAND_VII__,$(sort $(strip $(UMTS_SUPPORT_BAND)))))
ifeq ($(call gt,$(strip $(UMTS_SUPPORT_BAND_I_TO_VII_COUNT)),4),T)
  $(warning ERROR: UE at most supports 4 bands in band I~VII due to RRC Specification limitation (UE supports $(strip $(UMTS_SUPPORT_BAND))))
  DEPENDENCY_CONFLICT = TRUE
endif

# UMTS TDD128 BAND SUPPORT Options
ifdef UMTS_TDD128_BAND_A
  ifeq ($(strip $(UMTS_TDD128_BAND_A)),TRUE)
    COM_DEFS += __UMTS_TDD128_BAND_A__
  endif
endif
ifdef UMTS_TDD128_BAND_B
  ifeq ($(strip $(UMTS_TDD128_BAND_B)),TRUE)
    COM_DEFS += __UMTS_TDD128_BAND_B__
  endif
endif
ifdef UMTS_TDD128_BAND_C
  ifeq ($(strip $(UMTS_TDD128_BAND_C)),TRUE)
    COM_DEFS += __UMTS_TDD128_BAND_C__
  endif
endif
ifdef UMTS_TDD128_BAND_D
  ifeq ($(strip $(UMTS_TDD128_BAND_D)),TRUE)
    COM_DEFS += __UMTS_TDD128_BAND_D__
  endif
endif
ifdef UMTS_TDD128_BAND_E
  ifeq ($(strip $(UMTS_TDD128_BAND_E)),TRUE)
    COM_DEFS += __UMTS_TDD128_BAND_E__
  endif
endif
ifdef UMTS_TDD128_BAND_F
  ifeq ($(strip $(UMTS_TDD128_BAND_F)),TRUE)
    COM_DEFS += __UMTS_TDD128_BAND_F__
  endif
endif

# AFC_VCXO_TYPE Options
COM_DEFS_FOR_VCXO       = AFC_VCXO
COM_DEFS_FOR_VCXO_SC    = AFC_VCXO AFC_SC
COM_DEFS_FOR_VCXO_TC    = AFC_VCXO AFC_TC
COM_DEFS_FOR_VCXO_SC_TC = AFC_VCXO AFC_SC AFC_TC
COM_DEFS_FOR_VCXO_2G    = AFC_VCXO_2G

COM_DEFS_FOR_AFC_VCXO_TYPE =  COM_DEFS_FOR_$(strip $(AFC_VCXO_TYPE))
ifdef $(COM_DEFS_FOR_AFC_VCXO_TYPE)
  COM_DEFS +=  $(COM_DEFS_FOR_$(strip $(AFC_VCXO_TYPE)))
endif

COM_DEFS_FOR_AFC_VCXO_TYPE_2G =  COM_DEFS_FOR_$(strip $(AFC_VCXO_TYPE_2G))
ifdef $(COM_DEFS_FOR_AFC_VCXO_TYPE_2G)
  COM_DEFS +=  $(COM_DEFS_FOR_$(strip $(AFC_VCXO_TYPE_2G)))
endif

ifeq ($(strip $(DUAL_TALK_RFIC2_SUPPORT)),TRUE)
  COM_DEFS    += __DUAL_TALK_SUPPORT__
endif

DUMMY_SCATTER_ENABLE_PLATFORM = MT6252 MT6250
ifeq ($(filter $(strip $(PLATFORM)),$(DUMMY_SCATTER_ENABLE_PLATFORM)),)
  ifeq ($(strip $(DUMMY_SCATTER_ENABLE)),TRUE)
    $(warning ERROR: DUMMY_SCATTER_ENABLE can only be enabled when PLATFORM is $(DUMMY_SCATTER_ENABLE_PLATFORM))
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(DUMMY_SCATTER_ENABLE)),TRUE)
  ifeq ($(strip $(DEMO_PROJECT)),TRUE)
    $(warning ERROR: DUMMY_SCATTER_ENABLE cannot be enabled when DEMO_PROJECT=TRUE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifdef NAND_FLASH_BOOTING
    ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
      $(warning ERROR: DUMMY_SCATTER_ENABLE cannot be enabled when NAND_FLASH_BOOTING is not NONE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef PMIC_PRESENT
  ifeq ($(strip $(PMIC_PRESENT)),TRUE)
    COM_DEFS    += PMIC_PRESENT
  endif
endif

ifdef PMIC
  ifneq ($(strip $(PMIC)),NONE)
     COM_DEFS    += PMIC_PRESENT
  endif

  ifeq ($(strip $(PMIC)),MT6235PMU)
    ifneq ($(strip $(PLATFORM)),MT6235B)
        $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6235B series chips support $(strip $(PMIC)) PMIC) 
        DEPENDENCY_CONFLICT = TRUE
    endif
  endif

  ifeq ($(strip $(PMIC)),MT6238PMU)
    ifneq ($(strip $(PLATFORM)),MT6238)
      ifneq ($(strip $(PLATFORM)),MT6239)
        $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6238 & MT6239 series chips support $(strip $(PMIC)) PMIC) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif

  ifeq ($(strip $(PMIC)),MT6223PMU)
    ifneq ($(strip $(PLATFORM)),MT6223)
      ifneq ($(strip $(PLATFORM)),MT6223P)
        $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6223 series chips support $(strip $(PMIC)) PMIC) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif

  PMIC_MT6326_SUPPORT_PLATFORM = MT6268A MT6270A 
  ifeq ($(strip $(PMIC)),MT6326)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(PMIC_MT6326_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support PMIC=$(strip $(PMIC))) 
        DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6253PMU)
    ifneq ($(strip $(PLATFORM)),MT6253T)
       $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6253 series chips support $(strip $(PMIC)) PMIC) 
       DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6253ELPMU)
    ifneq ($(strip $(PLATFORM)),MT6253E)
      ifneq ($(strip $(PLATFORM)),MT6253L)
        $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6253EL series chips support $(strip $(PMIC)) PMIC)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6252PMU)
    ifneq ($(strip $(PLATFORM)),MT6252)
      ifneq ($(strip $(PLATFORM)),MT6252H)
        $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6252/H series chips support $(strip $(PMIC)) PMIC)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6236PMU)
    ifneq ($(strip $(PLATFORM)),MT6236)
      ifneq ($(strip $(PLATFORM)),MT6236B)
        $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6236 series chips support $(strip $(PMIC)) PMIC)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6921PMU)
    ifneq ($(strip $(PLATFORM)),MT6921)
      $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6921 series chips support $(strip $(PMIC)) PMIC)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6251PMU)
    ifneq ($(strip $(PLATFORM)),MT6251)
      $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6251 series chips support $(strip $(PMIC)) PMIC)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6276PMU)
    ifneq ($(strip $(PLATFORM)),MT6276)
      $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6276 series chips support $(strip $(PMIC)) PMIC)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6256PMU)
    ifneq ($(strip $(PLATFORM)),MT6256)
      $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6256 series chips support $(strip $(PMIC)) PMIC)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(PMIC)),MT6255PMU)
    ifneq ($(strip $(PLATFORM)),MT6255)
      ifneq ($(strip $(PLATFORM)),MT6922)
      $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6255 series chips support $(strip $(PMIC)) PMIC)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  endif
   ifeq ($(strip $(PMIC)),MT6250PMU)
    ifneq ($(strip $(PLATFORM)),MT6250)
      $(warning ERROR: $(strip $(PLATFORM)) does not support $(strip $(PMIC)),only MT6250 series chips support $(strip $(PMIC)) PMIC)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  PMIC_MT6329_SUPPORT_PLATFORM = MT6575 MT6577
  ifeq ($(strip $(PMIC)),MT6329)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(PMIC_MT6329_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support PMIC=$(strip $(PMIC))) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  PMIC_MT6327_SUPPORT_PLATFORM = MT6280
  ifeq ($(strip $(PMIC)),MT6327)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(PMIC_MT6327_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support PMIC=$(strip $(PMIC)))
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  
  PMIC_MT6339_SUPPORT_PLATFORM = MT6290
  ifeq ($(strip $(PMIC)),MT6339)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(PMIC_MT6339_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support PMIC=$(strip $(PMIC))) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  
  PMIC_MT6331_MT6332_SUPPORT_PLATFORM = MT6595 MT6795
  ifeq ($(strip $(PMIC)),MT6331)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(PMIC_MT6331_MT6332_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support PMIC=$(strip $(PMIC)))
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif

  ifeq ($(strip $(PMIC)),MT6332)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(PMIC_MT6331_MT6332_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support PMIC=$(strip $(PMIC)))
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  
  ifeq ($(strip $(PMIC)),MT6331_PLUS_MT6332)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(PMIC_MT6331_MT6332_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support PMIC=$(strip $(PMIC)))
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  
  PMIC_MT6325_SUPPORT_PLATFORM = MT6752
  ifeq ($(strip $(PMIC)),MT6325)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(PMIC_MT6325_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support PMIC=$(strip $(PMIC)))
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

NEED_ADD_PMIC_COMPILE_LIST = MT6223PMU MT6238PMU MT6235PMU MT6236PMU MT6573PMU MT6575PMU MT6577PMU MT6305 MT6318 MT6326 MT6253PMU MT6253ELPMU MT6252PMU MT6326_CCCI MT6251PMU MT6276PMU MT6256PMU MT6921PMU MT6329 MT6255PMU MT6922PMU MT6250PMU MT6327 MT6320 MT6339 MT6331 MT6332 MT6331_PLUS_MT6332 MT6325

ifneq ($(filter $(NEED_ADD_PMIC_COMPILE_LIST),$(PMIC)),)
  ifeq ($(strip $(PMIC)),MT6921PMU)
    COM_DEFS    += MT6236PMU
  else
    ifeq ($(strip $(PMIC)),MT6331_PLUS_MT6332)
        COM_DEFS    += MT6331 MT6332
    else
        COM_DEFS    += $(PMIC)
    endif    
  endif
endif

# Dependency check for PMIC/PMU which support custom tool configuration
# The PMIC/PMU list which support custom tool configuration
CUSTOM_TOOL_IF_SUPPORTED_PMIC = MT6236PMU MT6256PMU MT6276PMU MT6251PMU MT6921PMU MT6255PMU MT6922PMU MT6250PMU
ifdef DRV_CUSTOM_TOOL_SUPPORT
  ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
    ifneq ($(findstring $(strip $(PMIC)),$(strip $(CUSTOM_TOOL_IF_SUPPORTED_PMIC))),)
      COM_DEFS += __CUST_NEW_PMIC__
    endif
  endif
endif

ifdef DRV_CUSTOM_TOOL_SUPPORT
  ifeq ($(strip $(DRV_CUSTOM_TOOL_SUPPORT)),TRUE)
     COM_DEFS    +=  __CUST_NEW__
  endif
endif

# Check 53 PMU API version
PMU53_API_V1_PLATFORM = MT6253_EVB% MT6253T_EVB% TIANYU6253T% UNICORN53%
ifeq ($(strip $(PMIC)),MT6253PMU)
   COM_DEFS    += MT6253PMU
   ifneq ($(filter $(strip $(PMU53_API_V1_PLATFORM)),$(strip $(BOARD_VER))),)
      COM_DEFS    += __DRV_PMU53_SPEC_V1__
   else
      COM_DEFS    += __DRV_PMU53_SPEC_V2__
   endif
endif

ifeq ($(strip $(FLASH_TEST_SELECT)),NAND_FLASH)
  ifneq ($(strip $(NAND_SUPPORT)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,FLASH_TEST_SELECT,non NAND_FLASH,NAND_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __NAND_FLASH_HARDWARE_TEST__
endif

ifeq ($(strip $(FLASH_TEST_SELECT)),NOR_FLASH)
  COM_DEFS    += __NOR_FLASH_HARDWARE_TEST__
endif

ifdef NAND_SUPPORT
  ifdef SYSTEM_DRIVE_ON_NAND
    ifeq ($(strip $(NAND_SUPPORT)),FALSE)
      ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
         $(call DEP_ERR_ONA_OR_OFFB,NAND_SUPPORT,SYSTEM_DRIVE_ON_NAND)
         DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef NAND_SUPPORT
  ifeq ($(strip $(NAND_SUPPORT)),TRUE)
    COM_DEFS    += NAND_SUPPORT
  endif
endif

ifdef NAND_SUPPORT
  ifdef SYSTEM_DRIVE_ON_NAND
    ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
      SYSTEM_DRIVE_ON_NAND_SUPPORT_PLATFORM =  MT6575 MT6577 MT6280
      ifeq ($(filter $(strip $(PLATFORM)) ,$(SYSTEM_DRIVE_ON_NAND_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support SYSTEM_DRIVE_ON_NAND.)
        DEPENDENCY_CONFLICT = TRUE
      else
        ifeq ($(strip $(NAND_SUPPORT)),TRUE)
          COM_DEFS    += __FS_SYSDRV_ON_NAND__
        endif
      endif
    endif
  endif
endif

ifdef NAND_FLASH_BOOTING
  ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    NAND_FLASH_BOOTING_SUPPORT_PLATFORM = MT6575 MT6280 MT6290
    NFB_ONDEMAND_SUPPORT_PLATFORM = MT6575 MT6280
    ifeq ($(strip $(SMART_PHONE_CORE)),AP)
      NAND_FLASH_BOOTING_SUPPORT_PLATFORM += MT6573 MT6575 MT6577
      NFB_ONDEMAND_SUPPORT_PLATFORM += MT6573 MT6575 MT6577
    endif
    ifeq ($(filter $(strip $(PLATFORM)) ,$(NAND_FLASH_BOOTING_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support NAND_FLASH_BOOTING) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef NAND_SUPPORT
      ifeq ($(strip $(NAND_SUPPORT)),FALSE)
       $(call DEP_ERR_ONA_OR_OFFB,NAND_SUPPORT,NAND_FLASH_BOOTING)
       DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS    += _NAND_FLASH_BOOTING_
    ifeq ($(strip $(NAND_FLASH_BOOTING)),ENFB)
      ifneq ($(filter $(strip $(PLATFORM)) ,$(NFB_ONDEMAND_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) should use NAND_FLASH_BOOTING = ONDEMAND / MIXED instead of ENFB) 
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += __NFB_THIRD_ROM_SUPPORT__
    endif
    ifeq ($(strip $(NAND_FLASH_BOOTING)),ONDEMAND)
      ifeq ($(filter $(strip $(PLATFORM)) ,$(NFB_ONDEMAND_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support NAND_FLASH_BOOTING = ONDEMAND) 
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += __DEMAND_PAGING__
    endif
    ifeq ($(strip $(NAND_FLASH_BOOTING)),MIXED)
      ifeq ($(filter $(strip $(PLATFORM)) ,$(NFB_ONDEMAND_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support NAND_FLASH_BOOTING = MIXED) 
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += __NFB_THIRD_ROM_SUPPORT__
      COM_DEFS    += __DEMAND_PAGING__
    endif
    ifeq ($(strip $(NAND_FLASH_BOOTING)),SINGLE)
      COM_DEFS    += __NFB_SINGLE_ROM__
    endif
  endif
endif

ifdef DEMAND_PAGING_LEVEL
  ifeq ($(strip $(DEMAND_PAGING_LEVEL)),DPV2)
    ifneq ($(strip $(NAND_FLASH_BOOTING)),ONDEMAND)
      $(warning ERROR: Please set NAND_FLASH_BOOTING = ONDEMAND to enable DEMAND_PAGING_LEVEL = DPV2.)
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS    += __DEMAND_PAGING_V2__
    endif
  endif
endif

ifneq ($(strip $(USB_SUPPORT)),TRUE)
  ifneq ($(filter __CHARGER_USB_DETECT_WIHT_ONE_EINT__ ,$(CUSTOM_OPTION)),)
    $(warning ERROR: Please remove __CHARGER_USB_DETECT_WIHT_ONE_EINT__ from CUSTOM_OPTION when USB_SUPPORT is not TRUE!) 
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(filter __USB_AND_UART_WITH_ONE_GPIO__ ,$(CUSTOM_OPTION)),)
    $(warning ERROR: Please remove __USB_AND_UART_WITH_ONE_GPIO__ from CUSTOM_OPTION when USB_SUPPORT is not TRUE!) 
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(USB_SUPPORT)),TRUE)
  USB_SUPPORT_PLATFORM = MT6280 MT6575 MT6577 MT6752
  ifeq ($(filter $(strip $(PLATFORM)) ,$(USB_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support USB.) 
    DEPENDENCY_CONFLICT = TRUE
  else
    ifeq ($(strip $(USB_SUPPORT)),TRUE)
      COM_DEFS    += __USB_ENABLE__ __NVRAM_IN_USB_MS__
      ifeq ($(strip $(BOARD_VER)),MT6228_EVB)
        COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
      endif
      ifeq ($(strip $(BOARD_VER)),MT6229_EVB)
        COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
      endif
      ifeq ($(strip $(BOARD_VER)),MT6229_MGM_EVB)
        COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
      endif
      ifeq ($(strip $(BOARD_VER)),MT6230_EVB)
        COM_DEFS    += _USB_VBUS_DETECT_WITH_NIRQ_
      endif
    endif
  endif
endif

BROM_USB_DOWNLOAD_SUPPORT_PLATFORM = MT6280 MT6290
BROM_USB_DOWNLOAD_V2_PLATFORM = MT6280

#Platform support bootloader download in normal flow
BOOTLOADER_USB_DOWNLOAD_V2_PLATFORM = MT6290  

ifneq ($(filter $(strip $(PLATFORM)) ,$(BROM_USB_DOWNLOAD_SUPPORT_PLATFORM)),)
  COM_DEFS    += __USBDL_IN_BOOTROM__
  ifdef USB_DOWNLOAD_IN_BL
    ifeq ($(strip $(USB_DOWNLOAD_IN_BL)),NORMAL)
      ifeq ($(filter $(strip $(PLATFORM)) ,$(BROM_USB_DOWNLOAD_V2_PLATFORM)),)
         ifeq ($(filter $(strip $(PLATFORM)) ,$(BOOTLOADER_USB_DOWNLOAD_V2_PLATFORM)),)   
            $(warning WARNING: $(PLATFORM) already supports BootROM USBDL. USB_DOWNLOAD_IN_BL = NORMAL is unnecessary)
            #DEPENDENCY_CONFLICT = TRUE
         endif
      endif
    endif
  endif
endif
ifneq ($(filter $(strip $(PLATFORM)) ,$(BROM_USB_DOWNLOAD_V2_PLATFORM)),)
  COM_DEFS    += __BROM_USBDL_V2__
endif


ifdef USB_DOWNLOAD_IN_BL
  ifeq ($(strip $(USB_DOWNLOAD_IN_BL)),SECURE)
    ifneq ($(strip $(SECURE_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_ONB,USB_DOWNLOAD_IN_BL,non SECURE,SECURE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(USB_SUPPORT)),TRUE)
      $(call DEP_ERR_SETA_OR_ONB,USB_DOWNLOAD_IN_BL,non SECURE,USB_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef USB_DOWNLOAD_IN_BL
  ifneq ($(strip $(USB_DOWNLOAD_IN_BL)),NONE)
      USB_DOWNLOAD_SUPPORT_PLATFORM = MT6290
      ifeq ($(filter $(strip $(PLATFORM)) ,$(USB_DOWNLOAD_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support USB_DOWNLOAD.) 
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS    += __USB_DOWNLOAD__
      ifeq ($(strip $(USB_DOWNLOAD_IN_BL)),SECURE)
        COM_DEFS  += __SECURE_USB_DOWNLOAD__
      endif
  endif
endif

ifdef AEC_ENABLE
  ifeq ($(strip $(AEC_ENABLE)),TRUE)
    COM_DEFS    += AEC_ENABLE
  else
    ifdef IC_TEST_TYPE
      ifneq ($(strip $(IC_TEST_TYPE)),IC_BURNIN_TEST)
        $(warning ERROR: AEC_ENABLE is a mandatory feature. Please turn on AEC_ENABLE!)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef IC_TEST_TYPE
  ifneq ($(strip $(IC_TEST_TYPE)),NONE)
    ifeq ($(findstring _SLT,$(IC_TEST_TYPE)),_SLT)
      COMPLIST     += slt
      COM_DEFS += __IC_SLT__
      COMP_TRACE_DEFS_MODEM += driver/drvtest/slt/inc/slt_trace.h
    endif
  endif
endif


ifdef AMR_LINK_SUPPORT
  ifeq ($(strip $(AMR_LINK_SUPPORT)),TRUE)
    COM_DEFS   += __AMR_SUPPORT__
  endif
endif

ifndef GPRS_MAX_PDP_SUPPORT
  GPRS_MAX_PDP_SUPPORT = 2
  ifdef LOW_COST_SUPPORT
    ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
      GPRS_MAX_PDP_SUPPORT = 1
    endif
  endif
endif

ifdef LTE_MAX_EPSB_SUPPORT
  COM_DEFS    += LTE_MAX_EPSB_SUPPORT=$(strip $(LTE_MAX_EPSB_SUPPORT))
endif

# define GPRS_MAX_PDP_SUPPORT = 2~7
ifdef GPRS_MAX_PDP_SUPPORT
  COM_DEFS    += GPRS_MAX_PDP_SUPPORT=$(strip $(GPRS_MAX_PDP_SUPPORT))
endif

ifdef GPRS_MAX_PDP_SUPPORT
  ifdef LTE_MAX_EPSB_SUPPORT
    MAX_EXT_PDP_CONTEXT := $(call max,$(strip $(GPRS_MAX_PDP_SUPPORT)),$(strip $(LTE_MAX_EPSB_SUPPORT)))
    COM_DEFS    += MAX_EXT_PDP_CONTEXT=$(call plus,$(strip $(MAX_EXT_PDP_CONTEXT)),3)
  endif
endif

# for backward compatible, need define a value for MAX_INT_PDP_CONTEXT
MAX_INT_PDP_CONTEXT = 0
COM_DEFS    += MAX_INT_PDP_CONTEXT=0

# if MAX_INT_PDP_CONTEXT + MAX_EXT_PDP_CONTEXT < GPRS_MAX_PDP_SUPPORT
#   error and stop build (in tcm hedear file check)
# if the MAX_EXT_PDP_CONTEXT < 0, error and stop compile
# if the MAX_EXT_PDP_CONTEXT > 7, error and stop compile
# if the MAX_EXT_PDP_CONTEXT > 0, that means we support at least 1 GPRS AT context ID, so we define __EXT_PDP_CONTEXT_ON__
#ifeq ($(call lt,$(strip $(MAX_EXT_PDP_CONTEXT)),0),T)
#  $(warning ERROR: MAX_EXT_PDP_CONTEXT value ($(MAX_EXT_PDP_CONTEXT)) should not be less than 0)
#  DEPENDENCY_CONFLICT = TRUE
#endif

#ifeq ($(call gt,$(strip $(MAX_EXT_PDP_CONTEXT)),0),T)
#  COM_DEFS          += __EXT_PDP_CONTEXT_ON__
#endif

# if the MAX_EXT_PDP_CONTEXT > 1 and GPRS_MAX_PDP_SUPPORT > 1,
#   that means we support at least 2 GPRS AT context ID,
#   and the SM can activate at least 2 PDP context,
#   in this situation, we can support AT triggered secondary PDP context, so we define __EXT_SECONDARY_PDP_FEASIBLE__
# if AT_COMMAND_SET is not SLIM, that means we can use AT+CGDSCONT and AT+CGTFT
#   so we can define __TURN_ON_EXTERNAL_SECONDARY_PDP__ and __TURN_ON_GENERAL_SECONDARY_PDP__

#ifeq ($(call gt,$(strip $(MAX_EXT_PDP_CONTEXT)),1),T)
# TCM support >= 2 external PDP
#  ifeq ($(call gt,$(strip $(GPRS_MAX_PDP_SUPPORT)),1),T)
  # SM support >= 2 PDP
#    COM_DEFS          += __EXT_SECONDARY_PDP_FEASIBLE__
#    ifdef AT_COMMAND_SET
#      ifeq ($(strip $(AT_COMMAND_SET)),SLIM)
        # SLIM AT, there are no AT+CGDSCONT and no AT+CGTFT
#      else
        # FULL AT, so AT support AT+CGDSCONT and AT+CGTFT
#        COM_DEFS          += __TURN_ON_EXTERNAL_SECONDARY_PDP__
#        COM_DEFS          += __TURN_ON_GENERAL_SECONDARY_PDP__      
#      endif
#    else
      # backward compatible, not define AT_COMMAND_SET, we assume using full at command set
#      COM_DEFS          += __TURN_ON_EXTERNAL_SECONDARY_PDP__
#      COM_DEFS          += __TURN_ON_GENERAL_SECONDARY_PDP__  
#    endif
#  endif
#endif

COM_DEFS          += __EXT_PDP_CONTEXT_ON__
COM_DEFS          += __EXT_SECONDARY_PDP_FEASIBLE__
COM_DEFS          += __TURN_ON_EXTERNAL_SECONDARY_PDP__
COM_DEFS          += __TURN_ON_GENERAL_SECONDARY_PDP__  


ifdef IPV6_PDP_SUPPORT
  ifeq ($(strip $(IPV6_PDP_SUPPORT)),TRUE)
    COM_DEFS          += __IPV6__
    COM_DEFS          += __IPV4V6__
  endif
endif

ifdef UART3_SUPPORT
  ifeq ($(strip $(UART3_SUPPORT)),TRUE)

    COM_DEFS    += __UART3_SUPPORT__
    UART_PORT_FREE_COUNT = 1
  else
    UART_PORT_FREE_COUNT = 0
  endif
else
    UART_PORT_FREE_COUNT = 0
endif

UART_PORT_USED_COUNT = 0

ifeq ($(strip $(UART_PORT_FREE_COUNT)),1)
  ifeq ($(strip $(UART_PORT_USED_COUNT)),2)
    # uart count is not enough for engineer mode
    COM_DEFS += __ONLY_ONE_UART__
  endif
endif

ifeq ($(strip $(UART_PORT_FREE_COUNT)),0)
  ifneq ($(strip $(UART_PORT_USED_COUNT)),0)
    # uart count is not enough for engineer mode
    COM_DEFS += __ONLY_ONE_UART__
  endif
endif

ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT_SUPPORTED_PLATFORM = MT6280 MT6290
ifdef ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT
  ifeq ($(strip $(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
    ifeq ($(filter $(strip $(PLATFORM)) ,$(ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT_SUPPORTED_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT,SYSTEM_DRIVE_ON_NAND)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SINGLE_BANK_NOR_FLASH_SUPPORT)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,ENHANCED_SINGLE_BANK_NOR_FLASH_SUPPORT,SINGLE_BANK_NOR_FLASH_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS += __SINGLE_BANK_NOR_FLASH_SUPPORT__
    endif
  endif
endif

ifdef SW_BINDING_SUPPORT
  ifneq ($(strip $(SW_BINDING_SUPPORT)),NONE)
    ifeq ($(strip $(SW_BINDING_SUPPORT)),BIND_TO_CHIP_BASIC)
    BIND_TO_CHIP_BASIC_SUPPORT_PLATFORM = MT6223 MT6223P MT6225 MT6235B MT6238 MT6239 MT6236 MT6921 MT6252
      ifeq ($(filter $(strip $(PLATFORM)) ,$(BIND_TO_CHIP_BASIC_SUPPORT_PLATFORM)),)
        $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support SW_BINDING_SUPPORT=BIND_TO_CHIP_BASIC.) 
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS += __BIND_TO_CHIP_BASIC__
    endif
    ifeq ($(strip $(SW_BINDING_SUPPORT)),BIND_TO_CHIP)
      COM_DEFS += __BIND_TO_CHIP__
    endif
    ifneq ($(filter BIND_TO_KEY BIND_TO_CHIP_AND_KEY, $(strip $(SW_BINDING_SUPPORT))),)
      COM_DEFS += __BIND_TO_KEY__
    endif
    ifneq ($(filter BIND_TO_CHIP BIND_TO_CHIP_AND_KEY, $(strip $(SW_BINDING_SUPPORT))),)
      COM_DEFS += __BIND_TO_CHIP__ 
    endif
  endif
else
  SW_BINDING_SUPPORT = NONE
endif

ifdef RES_PROT
  ifeq ($(strip $(RES_PROT)),TRUE)
    ifndef SW_BINDING_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,SW_BINDING_SUPPORT,RES_PROT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SW_BINDING_SUPPORT)),NONE)
      $(call DEP_ERR_ONA_OR_OFFB,SW_BINDING_SUPPORT,RES_PROT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS  += __RES_PROT__
  endif
endif

ifdef EDGE_SUPPORT
  ifeq ($(strip $(EDGE_SUPPORT)),TRUE)
    EDGE_SUPPORT_PLATFORM = MT6575 MT6577 MT6280 MT6752 MT6290 MT6595 MT6795
    ifeq ($(filter $(strip $(PLATFORM)) ,$(EDGE_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support EGPRS.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(R99_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,R99_SUPPORT,EDGE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif

    COM_DEFS    += __EGPRS_MODE__

    ifeq ($(strip $(L1_EPSK_TX)),TRUE)
      COM_DEFS    +=  __EPSK_TX__
    endif
  else
     ifdef L1_EPSK_TX
       ifeq ($(strip $(L1_EPSK_TX)),TRUE)
         $(call DEP_ERR_ONA_OR_OFFB,EDGE_SUPPORT,L1_EPSK_TX)
         DEPENDENCY_CONFLICT = TRUE
       endif
     endif
   endif
endif

ifdef R99_SUPPORT
  ifeq ($(strip $(R99_SUPPORT)),TRUE)
    COM_DEFS    +=   __R99__
    ifeq ($(strip $(LOW_COST_SUPPORT)),NONE)
      ifeq ($(strip $(L1_GPRS)),TRUE)
        COM_DEFS    +=   __TBF_EST__
      endif
    endif
  endif
endif

ifdef R4_SUPPORT
  ifeq ($(strip $(R4_SUPPORT)),TRUE)
    ifneq ($(strip $(R99_SUPPORT)),TRUE)
          $(call DEP_ERR_ONA_OR_OFFB,R99_SUPPORT,R4_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
    endif

    COM_DEFS    +=   __REL4__ __GERAN_R4__
  endif
endif

ifdef R5_SUPPORT
  ifeq ($(strip $(R5_SUPPORT)),TRUE)
    ifneq ($(strip $(R4_SUPPORT)),TRUE)
          $(call DEP_ERR_ONA_OR_OFFB,R4_SUPPORT,R5_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(USIM_SUPPORT)),TRUE)
      ifeq ($(filter ANDROID_MODEM,$(strip $(SMART_PHONE_CORE))),)
        $(call DEP_ERR_ONA_OR_OFFB,USIM_SUPPORT,R5_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif

    COM_DEFS    +=   __REL5__ __GERAN_R5__
  endif
endif

ifdef DSPIRDBG
  ifeq ($(strip $(DSPIRDBG)),TRUE)
    COM_DEFS    += __DSPIRDBG__
  endif
endif

ifdef DSPIRDBG_SP
  ifeq ($(strip $(DSPIRDBG_SP)),TRUE)
    COM_DEFS    += __DSPIRDBG_SP__
  endif
endif

ifdef DISPLAY_TYPE
  COM_DEFS    += __MMI_DISPLAY_TYPE_$(call Upper,$(strip $(DISPLAY_TYPE)))__
endif

ifdef SECURE_SUPPORT
  ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
    ifneq ($(strip $(SECURE_RO_ENABLE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SECURE_RO_ENABLE,SECURE_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __MTK_SECURE_PLATFORM__
  endif
endif

ifdef SECURE_RO_ENABLE
  ifeq ($(strip $(SECURE_RO_ENABLE)),TRUE)
    COM_DEFS    += __SECURE_RO_ENABLE__
  endif
endif  

ifdef CHIP_VERSION_CHECK
  ifeq ($(strip $(CHIP_VERSION_CHECK)),TRUE)
    COM_DEFS += __CHIP_VERSION_CHECK__
  endif
else
  $(warning ERROR: The feature CHIP_VERSION_CHECK should be defined as TRUE or FALSE)
  DEPENDENCY_CONFLICT = TRUE
endif

ifeq ($(strip $(SYSDRV_BACKUP_DISK_SUPPORT)),RAW)
  ifneq ($(strip $(NOR_SUPPORT_RAW_DISK)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,SYSDRV_BACKUP_DISK_SUPPORT),non RAW,NOR_SUPPORT_RAW_DISK)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
ifeq ($(strip $(SYSDRV_BACKUP_DISK_SUPPORT)),FAT)
  ifneq ($(strip $(NANDFDM_MULTI_INSTANCE)),TRUE)
    $(call DEP_ERR_SETA_OR_ONB,SYSDRV_BACKUP_DISK_SUPPORT),non FAT,NANDFDM_MULTI_INSTANCE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(DISABLE_A5_2)),TRUE)
  COM_DEFS += __DISABLE_A5_2__
endif

ifeq ($(strip $(TST_LOGACC_SUPPORT)),TRUE)
  ifneq ($(strip $(TST_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,TST_SUPPORT,TST_LOGACC_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS    += __LOGACC_ENABLE__
  endif
endif

ifeq ($(strip $(USB_MASS_STORAGE_SUPPORT)),TRUE)
  ifeq ($(strip $(USB_SUPPORT)),FALSE)
    $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_MASS_STORAGE_SUPPORT )
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS +=  __USB_MASS_STORAGE_ENABLE__
endif

ifeq ($(strip $(USB_COM_PORT_SUPPORT)),TRUE)
  ifeq ($(strip $(USB_SUPPORT)),FALSE)
    $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_COM_PORT_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS +=  __USB_COM_PORT_ENABLE__
endif

ifdef USB_HS_SUPPORT
  ifeq ($(strip $(USB_HS_SUPPORT)),TRUE)
     ifneq ($(strip $(USB_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_HS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
     else
       USB_HS_SUPPORT_PLATFORM = MT6575 MT6577 MT6280 MT6752
       ifeq ($(filter $(strip $(PLATFORM)),$(USB_HS_SUPPORT_PLATFORM)),)
         $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support USB_HS_SUPPORT.)
         DEPENDENCY_CONFLICT = TRUE
       else
         COM_DEFS += __USB_HS_ENABLE__
       endif
     endif
   endif
endif

ifeq ($(strip $(AMRWB_LINK_SUPPORT)),TRUE)
  AMRWB_LINK_SUPPORT_PLATFORM = MT6575 MT6577 MT6280 MT6752 MT6290 MT6595 MT6795
  ifeq ($(filter $(strip $(PLATFORM)) ,$(AMRWB_LINK_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support AMRWB_LINK_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS  +=  __AMRWB_LINK_SUPPORT__
endif

ifdef EMMC_BOOTING
  ifneq ($(strip $(EMMC_BOOTING)),NONE)
    EMMC_BOOTING_SUPPORT_PLATFORM = MT6256 MT6276
    ifeq ($(filter $(strip $(PLATFORM)) ,$(EMMC_BOOTING_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does not support EMMC_BOOTING)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifdef NAND_FLASH_BOOTING
      ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
        $(warning ERROR: NAND_FLASH_BOOTING and EMMC_BOOTING could not turn on simutaneously. Please turn of one.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif 
    ifeq ($(strip $(NAND_SUPPORT)),TRUE)
      $(warning ERROR: EMMC_BOOTING cannot be enabled when NAND_SUPPORT is TRUE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(SYSTEM_DRIVE_ON_NAND)),TRUE)
      $(warning ERROR: EMMC_BOOTING cannot be enabled when SYSTEM_DRIVE_ON_NAND is TRUE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(COMBO_MEMORY_SUPPORT)),TRUE)
      $(warning ERROR: EMMC_BOOTING cannot be enabled when COMBO_MEMORY_SUPPORT is TRUE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __EMMC_BOOTING__
    ifeq ($(strip $(EMMC_BOOTING)),ONDEMAND)
      COM_DEFS    += __DEMAND_PAGING__
    endif
    ifeq ($(strip $(EMMC_BOOTING)),MIXED)
      COM_DEFS    += __NFB_THIRD_ROM_SUPPORT__
      COM_DEFS    += __DEMAND_PAGING__
    endif
  endif
endif

SV5_PLATFORM = MT6280
SV5X_PLATFORM = MT6290

# Determine if BOOTLOADER built required
NEED_BUILD_BOOTLOADER = FALSE
ifneq ($(filter $(strip $(PLATFORM)),$(strip $(SV5_PLATFORM))),)
  NEED_BUILD_BOOTLOADER = TRUE
  BOOTLOADER_CHE = ON
endif

ifneq ($(filter $(strip $(PLATFORM)),$(strip $(SV5X_PLATFORM))),)
  NEED_BUILD_BOOTLOADER = TRUE
  BOOTLOADER_CHE = ON
endif

ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
  NEED_BUILD_BOOTLOADER = TRUE
  BOOTLOADER_CHE = ON
else
  ifdef USB_DOWNLOAD_IN_BL
    ifneq ($(strip $(USB_DOWNLOAD_IN_BL)),NONE)
      NEED_BUILD_BOOTLOADER = TRUE
      BOOTLOADER_CHE = ON
    endif
  endif
endif

# =================================================
# MD OFFLOAD COPRO Setting
# =================================================
MD_COPRO_CONFIG := FALSE
ifndef NEED_BUILD_MD_OFFLOAD_COPRO
  NEED_BUILD_MD_OFFLOAD_COPRO := FALSE
endif

FORCE_GEN := FALSE
# Determine if MD offload corp built required
ifeq ($(strip $(NEED_BUILD_MD_OFFLOAD_COPRO)),TRUE)
  ifndef MD_OFFLOAD_COPRO
    DEPENDENCY_CONFLICT = TRUE
    $(warning ERROR: This project does NOT support MD_OFFLOAD_COPRO)
  else
    ifeq ($(strip $(MD_OFFLOAD_COPRO)),NONE)
      DEPENDENCY_CONFLICT = TRUE
      $(warning ERROR: This project does NOT support MD_OFFLOAD_COPRO)
    endif
  endif
  MD_COPRO_CONFIG := TRUE
  NEED_BUILD_BOOTLOADER = FALSE
  BOOTLOADER_CHE = OFF
  COM_DEFS += NEED_BUILD_MD_OFFLOAD_COPRO
endif

ifdef NAND_FLASH_BOOTING
  ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    NAND_FLASH_BOOTING_IS_NONE = TRUE
  endif
else
  NAND_FLASH_BOOTING_IS_NONE = TRUE
endif

ifdef EMMC_BOOTING
  ifeq ($(strip $(EMMC_BOOTING)),NONE)
    EMMC_BOOTING_IS_NONE = TRUE
  endif
else
  EMMC_BOOTING_IS_NONE = TRUE
endif

ifndef SMART_PHONE_CORE
  SMART_PHONE_CORE = NONE
endif

ifndef X_BOOTING
  X_BOOTING = NONE
endif
ifneq ($(strip $(X_BOOTING)),NONE)
  COM_DEFS    += __X_BOOTING__
  ifeq ($(strip $(X_BOOTING)),SDIO)
    COM_DEFS    += __SDIO_X_BOOTING__
  endif
  ifeq ($(strip $(X_BOOTING)),USB)
    COM_DEFS    += __USB_X_BOOTING__
  endif
  ifeq ($(strip $(X_BOOTING)),UART)
    COM_DEFS    += __UART_X_BOOTING__
  endif
endif

ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
  ifeq ($(strip $(X_BOOTING)),NONE) 
    COM_DEFS += __NO_MDBL_SHARE_INFO__
  endif
endif

MAIN_CODE_NEED_GFH = FALSE
ifneq ($(filter $(strip $(PLATFORM)),$(SV5_PLATFORM)),)
  MAIN_CODE_NEED_GFH = TRUE
endif
ifneq ($(filter $(strip $(PLATFORM)),$(SV5X_PLATFORM)),)
  MAIN_CODE_NEED_GFH = TRUE
else
  ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
    ifeq ($(strip $(X_BOOTING)),NONE)
      MAIN_CODE_NEED_GFH = FALSE
    endif
  endif
endif

ifeq ($(strip $(NEED_BUILD_MD_OFFLOAD_COPRO)),TRUE)
  MAIN_CODE_NEED_GFH = FALSE
endif

ifneq ($(filter $(strip $(PLATFORM)),$(SV5_PLATFORM)),)
  ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
    ifeq ($(strip $(X_BOOTING)),NONE)
      COM_DEFS += __AP_BOOTUP_BY_MDBL__
    endif
  endif
endif

ifneq ($(filter $(strip $(PLATFORM)),$(SV5X_PLATFORM)),)
  ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
    ifeq ($(strip $(X_BOOTING)),NONE)
      COM_DEFS += __AP_BOOTUP_BY_MDBL__
    endif
  endif
endif

ifneq ($(strip $(X_BOOTING)),NONE)
  ifeq ($(strip $(SMART_PHONE_CORE)),NONE)
      $(warning ERROR: X_BOOTING can be only supported on SMART_PHONE_CORE!=NONE) 
      DEPENDENCY_CONFLICT = TRUE
  endif 
endif 

ifdef FLASH_DRV_IN_BL
  ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    ifneq ($(strip $(FLASH_DRV_IN_BL)),NAND)
      $(warning ERROR: FLASH_DRV_IN_BL must be NAND when NAND_FLASH_BOOTING!=NONE) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif

  ifneq ($(strip $(EMMC_BOOTING)),NONE)
    ifneq ($(strip $(FLASH_DRV_IN_BL)),EMMC)
      $(warning ERROR: FLASH_DRV_IN_BL must be EMMC when EMMC_BOOTING!=NONE) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif

  ifeq ($(strip $(SERIAL_FLASH_SUPPORT)),TRUE)
    ifneq ($(strip $(FLASH_DRV_IN_BL)),SF)
      $(warning ERROR: FLASH_DRV_IN_BL must be SF when SERIAL_FLASH_SUPPORT=TRUE) 
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif

  ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    ifeq ($(strip $(EMMC_BOOTING)),NONE)
      ifneq ($(strip $(SERIAL_FLASH_SUPPORT)),TRUE)
        ifeq ($(strip $(SMART_PHONE_CORE)),NONE)
          ifeq ($(strip $(X_BOOTING)),NONE)
            ifneq ($(strip $(FLASH_DRV_IN_BL)),NOR)
              $(warning ERROR: FLASH_DRV_IN_BL must be NOR when NAND_FLASH_BOOTING=NONE and EMMC_BOOTING=NONE and SERIAL_FLASH_SUPPORT!=TRUE) 
              DEPENDENCY_CONFLICT = TRUE
            endif
          endif
        endif
      endif
    endif
  endif
endif

ifdef UMTS_MODE_SUPPORT
  ifneq ($(strip $(UMTS_MODE_SUPPORT)),NONE)
    ifeq ($(filter __UMTS_RAT__,$(strip $(COM_DEFS))),)
      $(warning ERROR: UMTS_MODE_SUPPORT can only be turned on when __UMTS_RAT__ defined)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
      COM_DEFS += __UMTS_FDD_MODE__
      COM_DEFS   += __3G_AUTO_BAND_MECHANISM__
    endif
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
       COM_DEFS += __UMTS_TDD128_MODE__ __R7_EHPLMN__ __ME_STORED_EHPLMN__ __VSIM__
    endif
  else
    ifeq ($(strip $(SMART_PHONE_CORE)),ANDROID_MODEM)
      ifneq ($(filter MT6575 MT6577,$(strip $(PLATFORM))),)
        COM_DEFS +=  __SMARTPHONE_GPRS_ONLY__
      endif
    endif
  endif
endif

ifdef USB_MULTIPLE_COMPORT_ENABLE
  ifeq ($(strip $(USB_MULTIPLE_COMPORT_ENABLE)),TRUE)
    ifneq ($(strip $(USB_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_MULTIPLE_COMPORT_ENABLE)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifneq ($(strip $(USB_COM_PORT_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,USB_COM_PORT_SUPPORT,USB_MULTIPLE_COMPORT_ENABLE)
        DEPENDENCY_CONFLICT = TRUE
      else
          COM_DEFS += __USB_SUPPORT_MULTIPLE_DMA_CHANNEL__
          COM_DEFS += __USB_MULTIPLE_COMPORT_SUPPORT__
          COM_DEFS += __USB_COMPOSITE_DEVICE_SUPPORT__
      endif
    endif
  endif
endif

# Customer specific factory mode detection
ifdef CUSTOMER_SPECIFIC_FACTORY_DETECTION
  ifneq ($(strip $(CUSTOMER_SPECIFIC_FACTORY_DETECTION)),NONE)
    COM_DEFS    +=  __CS_FAC_DET__
    COM_DEFS    +=  __$(strip $(CUSTOMER_SPECIFIC_FACTORY_DETECTION))__
  endif
endif

# Memory Remap Setting
# Default is BANK0_BANKF_REMAP
# For MT629X series, it is BANK0_BANK4_REMAP
BANK0_BANK4_REMAP_PLATFORM = MT6290
ifneq ($(filter $(strip $(PLATFORM)),$(BANK0_BANK4_REMAP_PLATFORM)),)
  COM_DEFS += __BANK0_BANK4_REMAP__
endif

ifeq ($(strip $(KAL_RECORD_BOOTUP_LOG)),TRUE)
  COM_DEFS += __KAL_RECORD_BOOTUP_LOG__
endif

CENTRALIZED_SLEEP_MANAGER_PLATFORM =  MT6752 MT6595 MT6290 MT6795
ifeq ($(strip $(CENTRALIZED_SLEEP_MANAGER)),TRUE)
  ifneq ($(filter __NEW_OS_TICK__,$(COM_DEFS)),)
    $(warning ERROR:  __NEW_OS_TICK__ cannot be defined if CENTRALIZED_SLEEP_MANAGER is TRUE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS += __CENTRALIZED_SLEEP_MANAGER__
  ifneq ($(strip $(TEST_LOAD_TYPE)),UDVT)
    COM_DEFS += __EVENT_BASED_TIMER__
  endif
else
  ifneq ($(filter $(strip $(PLATFORM)),$(CENTRALIZED_SLEEP_MANAGER_PLATFORM)),)
    $(warning ERROR: CENTRALIZED_SLEEP_MANAGER must be TRUE on $(strip $(PLATFORM)))
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
  COM_DEFS += __DSP_FCORE4__ __ARM_MOVE_DATA__
endif

ifeq ($(strip $(USB_HIGH_SPEED_COM_PORT_SUPPORT)),TRUE)
  ifneq ($(strip $(USB_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_HIGH_SPEED_COM_PORT_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  else
    ifneq ($(strip $(USB_COM_PORT_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,USB_COM_PORT_SUPPORT,USB_HIGH_SPEED_COM_PORT_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  COM_DEFS +=  __USB_HIGH_SPEED_COM_PORT_ENABLE__
endif

ifdef GPRS_CLASS_10
  ifeq ($(strip $(GPRS_CLASS_10)),TRUE)
    COM_DEFS    += __GPRS_MULTISLOT_CLASS_10__
  endif
endif

ifdef EDGE_CLASS_10 
  ifeq ($(strip $(EDGE_CLASS_10 )),TRUE)
    COM_DEFS    += __EDGE_MULTISLOT_CLASS_10__
  endif
endif

ifdef MCU_CLOCK
  # convert MCU_XXX_YYM to XXX.YY
  CLOCK_MHZ = $(subst _,.,$(subst M,,$(subst MCU_,,$(strip $(MCU_CLOCK)))))
  ifneq ($(CLOCK_MHZ),)
    COM_DEFS += CPU_CLOCK_MHZ=$(CLOCK_MHZ)
  endif
endif

EDGE_PS_HANDOVER_MULTIPLE_TBF_SUPPORT_FLATFORM = MT6575 MT6577
ifeq ($(strip $(PS_HANDOVER)),TRUE)
  ## temporary not support PS_HANDOVER
  $(warning ERROR: PS_HANDOVER cannot be TRUE for current platform.)
  DEPENDENCY_CONFLICT = TRUE
  ##
  ifneq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R6_SUPPORT)
    ifneq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R7_SUPPORT)
      ifneq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R8_SUPPORT)
        $(call DEP_ERR_SETA_OR_OFFB,GERAN_RELEASE_SUPPORT,GERAN_R6_SUPPORT,PS_HANDOVER)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  ifneq ($(filter __EGPRS_MODE__,$(COM_DEFS)),)
    ifeq ($(filter $(strip $(PLATFORM)),$(EDGE_PS_HANDOVER_MULTIPLE_TBF_SUPPORT_FLATFORM)),)
      $(warning ERROR: PS_HANDOVER cannot be TRUE for PLATFORM $(strip $(PLATFORM)).)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  COM_DEFS += __PS_HO__  __EXT_SEG_CTRL_BLK__
endif

ifeq ($(strip $(MULTIPLE_TBF)),TRUE)
  ## temporary not support MULTIPLE_TBF
  $(warning ERROR: MULTIPLE_TBF cannot be TRUE for current platform.)
  DEPENDENCY_CONFLICT = TRUE
  ##
  ifneq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R6_SUPPORT)
    ifneq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R7_SUPPORT)
      ifneq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R8_SUPPORT)
        $(call DEP_ERR_SETA_OR_OFFB,GERAN_RELEASE_SUPPORT,GERAN_R6_SUPPORT,MULTIPLE_TBF)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif  
  endif
  ifneq ($(filter __EGPRS_MODE__,$(COM_DEFS)),)
    ifeq ($(filter $(strip $(PLATFORM)),$(EDGE_PS_HANDOVER_MULTIPLE_TBF_SUPPORT_FLATFORM)),)
      $(warning ERROR: MULTIPLE_TBF cannot be TRUE for PLATFORM $(strip $(PLATFORM)).)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  COM_DEFS += __MTBF__
endif

ifeq ($(strip $(SMART_PHONE_CORE)),ANDROID_MODEM)
  COM_DEFS += MED_NOT_PRESENT MED_V_NOT_PRESENT
else
  ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
    ifneq ($(filter NONE MODEM_ONLY,$(strip $(SMART_PHONE_CORE))),)
      COMPLIST += media
    endif
  endif
endif

#ifdef L1_GPRS
#  ifneq ($(call Upper ,$(strip $(L1_GPRS))),TRUE)
#    ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
#      $(warning ERROR: __PS_SERVICE__ is not supported with L1_GPRS != TURE)
#      DEPENDENCY_CONFLICT = TRUE
#    endif
#  endif
#endif

COM_DEFS  += __SMART_PAGING_IN_IDLE__ __SMART_PAGING__
ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  COM_DEFS  += __MONITOR_PAGE_DURING_TRANSFER__
endif

ifeq ($(strip $(GEMINI_VERSION)),V2)
  ifdef GEMINI
    ifneq ($(strip $(GEMINI)),FALSE)
      COM_DEFS  += __GEMINI_PREEMPT_PEER_SERVICE__ __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ __SMART_PAGING__ __SMART_PAGING_IN_IDLE__
      ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
        COM_DEFS  += __MONITOR_PEER_PAGING_IN_CELL_PCH__
      endif
    endif
  endif
endif
ifneq ($(filter __SMART_PAGING_IN_IDLE__,$(COM_DEFS)),)
  ifeq ($(filter __SMART_PAGING__,$(COM_DEFS)),)
    $(warning ERROR: __SMART_PAGING_IN_IDLE__ can only be defined when __SMART_PAGING__ is defined.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(USB_MASS_STORAGE_CDROM_SUPPORT)),TRUE)
  ifeq ($(strip $(USB_SUPPORT)),FALSE)
    $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_MASS_STORAGE_CDROM_SUPPORT )
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(USB_MASS_STORAGE_SUPPORT)),FALSE)
    $(call DEP_ERR_ONA_OR_OFFB,USB_MASS_STORAGE_SUPPORT,USB_MASS_STORAGE_CDROM_SUPPORT )
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS +=  __USB_MASS_STORAGE_CDROM_ENABLE__
endif

MDP_VT_PREVIEW_UPSCALE_PLATFORM = MT6276 MT6256 MT6236 MT6255 MT6922
ifneq ($(filter $(strip $(PLATFORM)),$(MDP_VT_PREVIEW_UPSCALE_PLATFORM)),)
  COM_DEFS    += __MDP_VT_PREVIEW_UPSCALE_SUPPORT__
endif

ifneq ($(filter __RF_DESENSE_TEST__,$(CUSTOM_OPTION)),)
  COMPLIST     += btmt
#  CUS_REL_MTK_COMP  +=  btmt
endif

ifdef AVI_FILE_FORMAT_SUPPORT
  ifeq ($(strip $(AVI_FILE_FORMAT_SUPPORT)),TRUE)
    COM_DEFS    += __AVI_FILE_FORMAT_SUPPORT__
  else

  endif
endif

ifdef RM_FILE_FORMAT_SUPPORT
  ifeq ($(strip $(RM_FILE_FORMAT_SUPPORT)),TRUE)
    COM_DEFS    += __RM_FILE_FORMAT_SUPPORT__
  else
    ifeq ($(strip $(COOK_DECODE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,RM_FILE_FORMAT_SUPPORT,COOK_DECODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(RM_DECODE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,RM_FILE_FORMAT_SUPPORT,RM_DECODE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

#ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
  COM_DEFS    += __EMPTY_MMI__
#endif

ifdef WAV_CODEC
  ifeq ($(strip $(WAV_CODEC)),TRUE)
    COM_DEFS    += WAV_CODEC
  endif
endif

ifdef BACKGROUND_SOUND
  ifeq ($(strip $(BACKGROUND_SOUND)),TRUE)
    COM_DEFS += BGSND_ENABLE
  endif
endif

ifdef CTM_SUPPORT
  ifneq ($(strip $(CTM_SUPPORT)),FALSE)
    COM_DEFS    +=  __CTM_SUPPORT__
    COMPLIST += dp_engine
  endif
endif

ifeq ($(strip $(SERIAL_FLASH_SUPPORT)),TRUE)
  ifdef EMMC_BOOTING
    ifneq ($(strip $(EMMC_BOOTING)),NONE)
      $(warning ERROR: when SERIAL_FLASH_SUPPORT is TRUE, please set EMMC_BOOTING = NONE.)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifdef NAND_FLASH_BOOTING
        ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
          $(warning ERROR: when SERIAL_FLASH_SUPPORT is TRUE, please set NAND_FLASH_BOOTING = NONE.)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  else
    ifdef NAND_FLASH_BOOTING
      ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
        $(warning ERROR: when SERIAL_FLASH_SUPPORT is TRUE, please set NAND_FLASH_BOOTING = NONE.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
  COM_DEFS     += __SERIAL_FLASH_EN__
  COM_DEFS     += __SERIAL_FLASH_SUPPORT__
  COM_DEFS     += __NOR_IDLE_SWEEP__
  COMPLIST += mtd 
endif

ifeq ($(strip $(ECALL_SUPPORT)),TRUE)
  ifneq ($(strip $(R4_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,R4_SUPPORT,ECALL_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __ECALL_SUPPORT__
  COM_DEFS    += __ECALL_PSAP_SUPPORT__
  COMPLIST    += dp_engine
endif

ifeq ($(strip $(USB_SUPPORT)),TRUE)
  COM_DEFS    += __CHARGER_USB_DETECT_WIHT_ONE_EINT__
endif

ifeq ($(strip $(HIF_USB_SUPPORT)),TRUE)
  ifeq ($(strip $(HIF_USB30_SUPPORT)),TRUE)
    COMP_TRACE_DEFS_MODEM    += driver/hif/inc/hif_usbdev/hif_u3dev/u3dev_trace.h
  endif
endif

ifdef 3G_VIDEO_CALL
  ifeq ($(strip $(3G_VIDEO_CALL)),TRUE)
      COM_DEFS    += __VT_MONA__
  endif
endif

ifneq ($(filter __UMTS_TDD128_MODE__,$(strip $(COM_DEFS))),)
  COM_DEFS    += __ATCI_QUEUE_AT__
endif

XIP_SHADOWING_ENABLE_PLATFORM = MT6280
ifneq ($(filter $(strip $(XIP_SHADOWING_ENABLE_PLATFORM)),$(strip $(PLATFORM))),)
  ifeq ($(strip $(SERIAL_FLASH_SUPPORT)),TRUE)
    COM_DEFS += __XIP_SHADOWING__
  endif
endif

COMP_TRACE_DEFS_MODEM    += interface/driver/storage/sim/sim_drv_trc.h

#end of option_HAL.mak
# *************************************************************************
# Environment and Tools
# *************************************************************************

include make/compiler.mak

# -----------------------------
# custom release library path
# -----------------------------

# *************************************************************************
# Common include file and output directory path
# *************************************************************************

COMMINCDIRS    += interface/service/nvram
COMMINCDIRS   +=  $(strip $(BUILD_SYSDIR))
ifeq ($(strip $(CUST_CODE)),TC01)
  COMMINCDIRS += $(strip $(BUILD_SYSDIR))/ERS
endif

COMMINCDIRS   += interface/driver/cmux \
                 interface/middleware/gps
                  

COMMINCDIRS    += driver/drv/include

COMMINCDIRS   += $(strip $(PROJDIR))/nvram_auto_gen


ifneq ($(filter FMT_NOT_PRESENT,$(CUSTOM_OPTION)),)
  ifneq ($(filter fmt,$(COMPLIST)),)
    $(warning ERROR: Please remove FMT_NOT_PRESENT from CUSTOM_OPTION when fmt module is defined in COMPLIST)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# *************************************************************************
# Component Compile Options
# *************************************************************************

ifndef FLAVOR
   COM_DEFS     += __FLAVOR_NOT_PRESENT__
endif

ifdef FLAVOR
  ifneq ($(strip $(FLAVOR)),NONE)
    COM_DEFS    += __FLAVOR_$(strip $(FLAVOR))__
  else
    COM_DEFS    += __FLAVOR_NOT_PRESENT__
  endif
endif

ifeq ($(strip $(IC_TEST_TYPE)),IC_BURNIN_TEST)
  ifneq ($(strip $(KAL_DEBUG_LEVEL)), RELEASE_KAL)
    $(warning ERROR: Please set KAL_DEBUG_LEVEL=RELEASE_KAL when  IC_TEST_TYPE = IC_BURNIN_TEST ) 
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef KAL_TRACE_OUTPUT
  ifeq ($(strip $(KAL_TRACE_OUTPUT)),NONE)
    COM_DEFS += MODULE_TRACE_OFF
  endif
  ifeq ($(strip $(KAL_TRACE_OUTPUT)),CUST_PARTIAL)
    COM_DEFS += MODULE_TRACE_OFF
  endif
endif

ifdef KAL_DEBUG_LEVEL
  ifeq ($(strip $(KAL_DEBUG_LEVEL)),RICH_DEBUG_KAL)
    COM_DEFS += DEBUG_KAL DEBUG_BUF2 DEBUG_BUF3 DEBUG_ITC DEBUG_SWLA DEBUG_TIMER DEBUG_TIMER2
     DEP_DEBUG_COMPILE_OPTION =DEBUG_KAL DEBUG_BUF2 DEBUG_BUF3 DEBUG_ITC DEBUG_TIMER DEBUG_TIMER2
     ENABLED_DEBUG_COMPILE_OPTION = $(sort $(filter $(strip $(DEP_DEBUG_COMPILE_OPTION)),$(CUSTOM_OPTION)))
  endif
  ifeq ($(strip $(KAL_DEBUG_LEVEL)),NORMAL_DEBUG_KAL)
    COM_DEFS += DEBUG_KAL DEBUG_BUF2 DEBUG_ITC DEBUG_TIMER
     DEP_DEBUG_COMPILE_OPTION =DEBUG_KAL DEBUG_BUF2 DEBUG_ITC DEBUG_TIMER
     ENABLED_DEBUG_COMPILE_OPTION = $(sort $(filter $(strip $(DEP_DEBUG_COMPILE_OPTION)),$(CUSTOM_OPTION)))
  endif
  ifeq ($(strip $(KAL_DEBUG_LEVEL)),SLIM_DEBUG_KAL)
    COM_DEFS += DEBUG_KAL DEBUG_BUF1
    DEP_DEBUG_COMPILE_OPTION = DEBUG_KAL DEBUG_BUF1
    ENABLED_DEBUG_COMPILE_OPTION = $(sort $(filter $(strip $(DEP_DEBUG_COMPILE_OPTION)),$(CUSTOM_OPTION)))
  endif
  # dependency rule for KAL,BUFFER & ITC debug compile options
  ifneq ($(strip $(ENABLED_DEBUG_COMPILE_OPTION)),)
    ifneq ($(strip $(ENABLED_DEBUG_COMPILE_OPTION)),$(sort $(strip $(DEP_DEBUG_COMPILE_OPTION))))
      DISABLED_DEBUG_COMPILE_OPTION = $(filter-out $(strip $(ENABLED_DEBUG_COMPILE_OPTION)),$(strip $(DEP_DEBUG_COMPILE_OPTION)))
      $(warning ERROR: PLEASE turn on $(DISABLED_DEBUG_COMPILE_OPTION) or turn off $(ENABLED_DEBUG_COMPILE_OPTION))
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  # end
  ifeq ($(strip $(KAL_DEBUG_LEVEL)),RELEASE_KAL)
    COM_DEFS += RELEASE_KAL
    DEP_DEBUG_COMPILE_OPTION =
    ENABLED_DEBUG_COMPILE_OPTION = $(sort $(filter $(strip $(DEP_DEBUG_COMPILE_OPTION)),$(CUSTOM_OPTION)))
  endif
endif

COM_DEFS    += __BLIND_HANDOVER__

COM_DEFS    +=  IDLE_TASK _DEBUG MTK_KAL  __MTK_TARGET__

COM_DEFS    +=  SME_NOT_PRESENT SME_READER_NOT_PRESENT STDC_HEADERS TARGET_BUILD

COM_DEFS    += DEBUG_LEVEL=0

COM_DEFS    += __MSLT__

ifeq ($(strip $(COMPILER)),RVCT)
  COM_DEFS += __RVCT__
endif

#ifdef OPTR_SPEC
#    ifeq ($(strip $(OPTR_SPEC)),NONE)
       COM_DEFS += __OPTR_NONE__
#    endif
#endif

ifdef DEMO_PROJECT
  ifeq ($(strip $(DEMO_PROJECT)),TRUE)
    COM_DEFS   += MTK_INTERNAL_MMI_FEATURES
    COM_DEFS   += __MTK_INTERNAL__  
  endif
endif

ifdef RSAT_SUPPORT
  ifeq ($(strip $(RSAT_SUPPORT)),MODEM_WITH_RSAT)
#    ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
#      $(call DEP_ERR_SETA_OR_OFFB,MMI_VERSION,EMPTY_MMI,RSAT_SUPPORT)
#      DEPENDENCY_CONFLICT = TRUE
#    else
      COM_DEFS    += __RSAT__
#    endif
  endif
  ifeq ($(strip $(RSAT_SUPPORT)),MMI_WITH_RSAT)
    COM_DEFS    += __RSAT__
  endif
endif

ifdef UL1D_COSIM
  ifeq ($(strip $(UL1D_COSIM)),TRUE)
    ifeq ($(strip $(UL1D_LOOPBACK)),0)
      $(call DEP_ERR_SETA_OR_OFFB,UL1D_LOOPBACK,non 0,UL1D_COSIM)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

# *************************************************************************
# Include LTE compile settings.
# *************************************************************************
include make/LTE_DEF.mak

# *************************************************************************
# Components
# *************************************************************************
# -----------------------------
# Common Components
# -----------------------------

AUTO_MERGE_FLR = custom/driver/audio custom/driver/drv/misc_drv
AUTO_MERGE_PTH = $(foreach DIR,$(AUTO_MERGE_FLR),$(call CUSTOM_FLD_MAPPING,$(DIR)) $(DIR)/_Default_BB/$(strip $(PLATFORM)))
COMMINCDIRS := $(AUTO_MERGE_PTH) $(COMMINCDIRS)

# *************************************************************************
# Component trace definition header files
# *************************************************************************
# -----------------------------
# Common trace
# -----------------------------

#
# Check the dependency of each options
#

# WIFI_BB_MODULE Options
COM_DEFS_FOR_NONE         = WIFI_BB_NONE

# WIFI_RF_MODULE Options
COM_DEFS_FOR_NONE        = WIFI_RF_NONE

#ifdef WIFI_SUPPORT
#  ifeq ($(strip $(WIFI_SUPPORT)),NONE)
     COM_DEFS   +=  $(COM_DEFS_FOR_NONE)
#  endif
#endif

ifdef 3G_VIDEO_CALL
  ifeq ($(strip $(3G_VIDEO_CALL)),TRUE)
    ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
      COMPLIST        += 3g324m
      COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/3g324m/appl/inc/vt_trc.h
      COM_DEFS   += __MEDIA_VT__ __VIDEO_CALL_SUPPORT__
    endif
  endif
endif

ifdef SP_VIDEO_CALL_SUPPORT
  ifeq ($(strip $(SP_VIDEO_CALL_SUPPORT)),TRUE)
    ifdef 3G_VIDEO_CALL
      ifeq ($(strip $(3G_VIDEO_CALL)),TRUE)
        $(warning ERROR: 3G_VIDEO_CALL, SP_VIDEO_CALL_SUPPORT can not enable at the same time)
      endif
    endif
    ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
      COMPLIST        += 3g324m_tvt
      COMP_TRACE_DEFS_MODEM += middleware/3g324m/tvt/inc/TVT_trc.h
      COM_DEFS   += __VT_TRANSPORT_SUPPORT__ __VIDEO_CALL_SUPPORT__
    endif
  endif
endif

ifdef UUS_SUPPORT
  ifeq ($(strip $(UUS_SUPPORT)),TRUE)
     COM_DEFS    += __UUS_SUPPORT__
  endif   
endif

ifdef EMLPP_SUPPORT
  ifeq ($(strip $(EMLPP_SUPPORT)),TRUE)
     COM_DEFS    += __EMLPP_SUPPORT__
  endif   
endif

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
    FLC_LIB_INCLUDE_CONDITION = FALSE
    ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
      FLC_LIB_INCLUDE_CONDITION = TRUE
    endif
    ifneq ($(strip $(CSD_SUPPORT)),NONE)
      FLC_LIB_INCLUDE_CONDITION = TRUE
    endif
    ifeq ($(strip $(FAX_SUPPORT)),TRUE)
      FLC_LIB_INCLUDE_CONDITION = TRUE
    endif
    ifeq ($(strip $(FLC_LIB_INCLUDE_CONDITION)),TRUE)
      ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
        ifeq ($(strip $(3G_NEW_DATA_PLANE_ARCH)), TRUE)
          COMPLIST += flc2_v2 flc2_v2_sec
        else
          COMPLIST += flc2_v1
        endif
      else
        COMPLIST += flc2_v2 flc2_v2_sec
      endif
      COMP_TRACE_DEFS_MODEM += $(strip $(FLC_FOLDER))/include/flc_trc.h
      COM_DEFS += __FLC2__ __FLC_SUPPORT__
    endif
  endif
endif

#ifneq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
  COM_DEFS    += __PHB_0x81_SUPPORT__
#endif

ifeq ($(strip $(L1_CATCHER)),TRUE)
  ifeq ($(strip $(TST_SUPPORT)),TRUE)
    COM_DEFS    += L1_CATCHER
  endif
  ifeq ($(strip $(DHL_SUPPORT)),TRUE)
    COM_DEFS    += L1_CATCHER
  endif
endif

ifeq ($(strip $(MTK_DSP_DEBUG)),TRUE)
  COM_DEFS    += MTK_DSP_DEBUG
endif

ifeq ($(strip $(FAX_SUPPORT)),TRUE)
  ifneq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
    $(warning ERROR: FAX_SUPPORT cannot be turned on in $(strip $(TEST_LOAD_TYPE)) project.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(FAX_SUPPORT)),TRUE)
  ifeq ($(strip $(CSD_SUPPORT)),NONE)
    $(warning ERROR: Please turn off FAX_SUPPORT when CSD_SUPPORT = NONE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef CSD_SUPPORT
  ifneq ($(strip $(CSD_SUPPORT)),NONE)
    ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
      $(warning ERROR: Please turn off CSD_SUPPORT in $(strip $(TEST_LOAD_TYPE)) project.) 
      DEPENDENCY_CONFLICT = TRUE
    endif
    # Support CSD
    COM_DEFS    += CSD_SUPPORT 
    ifeq ($(strip $(CSD_SUPPORT)),T_NT)
      COM_DEFS    += __CSD_NT__ __CSD_T__
    else
      ifeq ($(strip $(CSD_SUPPORT)),NT_ONLY)
        COM_DEFS    += __CSD_NT__ 
      else
        $(warning ERROR: CSD_SUPPORT setting is wrong) 
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifeq ($(strip $(FAX_SUPPORT)),TRUE)
      COM_DEFS    += __CSD_FAX__
    endif
  else
    # FAX only, Not support CSD
    ifeq ($(strip $(FAX_SUPPORT)),TRUE)
      COM_DEFS    += CSD_SUPPORT __CSD_FAX__
    endif
  endif
else
  # FAX only, Not support CSD
  ifeq ($(strip $(FAX_SUPPORT)),TRUE)
    COM_DEFS    += CSD_SUPPORT __CSD_FAX__
  endif
endif

ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
  COM_DEFS += KAL_ENH_MUTEX
else
  ifneq ($(filter __CS_SERVICE__,$(COM_DEFS)),)
    ifneq ($(strip $(CSD_SUPPORT)),NONE)
      COM_DEFS    += KAL_ENH_MUTEX
    endif
  endif
endif

ifeq ($(strip $(FAST_UART)),TRUE)
  COM_DEFS    += __FAST_UART__
endif

ifeq ($(filter __KBD_JOYSTICK_SUPPORT__,$(COM_DEFS)),__KBD_JOYSTICK_SUPPORT__)
   ifeq ($(filter __TWO_KEY_DETECTION_SWITCHABLE__,$(COM_DEFS)),__TWO_KEY_DETECTION_SWITCHABLE__)
      $(call DEP_ERR_OFFA_OR_OFFB,__TWO_KEY_DETECTION_SWITCHABLE__,__KBD_JOYSTICK_SUPPORT__)
      DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef BOOT_FAT_RESET
  ifeq ($(strip $(BOOT_FAT_RESET)),TRUE)
    COM_DEFS    += __BOOT_FAT_RESET__
  endif
endif

#ifdef APP_STORAGE_IN_SYS_DRV
#  ifeq ($(strip $(APP_STORAGE_IN_SYS_DRV)),FALSE)
#    ifdef MMS_SUPPORT
      COM_DEFS    += MMS_IN_LARGE_STORAGE
#    endif
#    ifeq ($(strip $(IMPS_SUPPORT)),TRUE)
#      COM_DEFS   += IMPS_IN_LARGE_STORAGE
#    endif
#  else
#    COM_DEFS    += APP_STORAGE_IN_SYS_DRV
#  endif
#endif

ifdef MSDC_CARD_SUPPORT_TYPE
  ifneq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),NONE)
    MSDC_SUPPORT_PLATFORM = MT6280 MT6290
    ifeq ($(filter $(strip $(PLATFORM)) ,$(MSDC_SUPPORT_PLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) does NOT support MSDC_CARD_SUPPORT_TYPE) 
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS += __FS_CARD_SUPPORT__
      ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_SD_MMC)
        COM_DEFS += __MSDC_SD_MMC__
      endif
      ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_MS)
        COM_DEFS += __MSDC_MS__
      endif
      ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_MSPRO)
        COM_DEFS += __MSDC_MSPRO__
      endif
      ifeq ($(strip $(MSDC_CARD_SUPPORT_TYPE)),MSDC_SD_SDIO)
        COM_DEFS += __MSDC_SD_MMC__ __MSDC_SD_SDIO__
      endif
    endif
  endif
endif

ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
  COM_DEFS      += ABM_NOT_PRESENT TCPIP_NOT_PRESENT SOC_NOT_PRESENT
else
  ifeq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_EGPRS_MODE)
    COM_DEFS   += ABM_NOT_PRESENT TCPIP_NOT_PRESENT SOC_NOT_PRESENT
  endif
endif

ifndef FS_SORT_MAX_ENTRY
  FS_SORT_MAX_ENTRY = 256
endif

ifdef FS_SORT_MAX_ENTRY
  FS_SORT_MAX_ENTRY_PLATFORM =  MT6280
  ifneq ($(filter $(strip $(PLATFORM)),$(FS_SORT_MAX_ENTRY_PLATFORM)),)
    ifeq ($(call gt,$(strip $(FS_SORT_MAX_ENTRY)),20000),T)
      $(warning ERROR: FS_SORT_MAX_ENTRY value ($(FS_SORT_MAX_ENTRY)) on $(strip $(PLATFORM)) should not be larger than 20000)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(call lt,$(strip $(FS_SORT_MAX_ENTRY)),64),T)
      $(warning ERROR: FS_SORT_MAX_ENTRY value ($(FS_SORT_MAX_ENTRY)) on $(strip $(PLATFORM)) should not be less than 64)
      DEPENDENCY_CONFLICT = TRUE
    endif
  else
    ifeq ($(call gt,$(strip $(FS_SORT_MAX_ENTRY)),256),T)
      $(warning ERROR: FS_SORT_MAX_ENTRY value ($(FS_SORT_MAX_ENTRY)) on $(strip $(PLATFORM)) should not be larger than 256)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(call lt,$(strip $(FS_SORT_MAX_ENTRY)),64),T)
      $(warning ERROR: FS_SORT_MAX_ENTRY value ($(FS_SORT_MAX_ENTRY)) on $(strip $(PLATFORM)) should not be less than 64)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef FS_OPEN_HINT_SUPPORT
  ifeq ($(strip $(FS_OPEN_HINT_SUPPORT)),TRUE)
     COM_DEFS   += __FS_OPEN_HINT__
  endif
endif

ifdef FS_DEDICATED_BUFFER
  ifeq ($(strip $(FS_DEDICATED_BUFFER)),TRUE)
     COM_DEFS   += __FS_DEDICATED_BUFFER__  
  endif
endif

ifdef TST_SUPPORT
  ifeq ($(strip $(TEST_LOAD_TYPE)),BASIC)
    ifeq ($(strip $(TST_SUPPORT)),TRUE)
      $(warning ERROR: TST_SUPPORT should be FALSE in BASIC project)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

COMP_TRACE_DEFS_MODEM    += service/fs/common/include/fs_trc.h

ifdef FS_TRACE_SUPPORT
  ifdef TST_SUPPORT
    ifeq ($(strip $(FS_TRACE_SUPPORT)),TRUE)
      ifeq ($(strip $(DHL_SUPPORT)),TRUE)
        COM_DEFS   += __FS_TRACE_SUPPORT__
      else
        $(call DEP_ERR_ONA_OR_OFFB,DHL_SUPPORT,FS_TRACE_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef CMUX_SUPPORT
  ifeq ($(strip $(CMUX_SUPPORT)),TRUE)
    ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
      COMPLIST          += cmux
      COM_DEFS     += __CMUX_SUPPORT__
      COMP_TRACE_DEFS_MODEM    += driver/cmux/include/cmux_trc.h
    endif
  endif
endif

#ifdef APP_SECONDARY_PDP_SUPPORT
#  ifeq ($(strip $(APP_SECONDARY_PDP_SUPPORT)),TRUE)
#     COM_DEFS    += __APP_SECONDARY_PDP_SUPPORT__
#  endif
#endif

# if APP_SECONDARY_PDP_SUPPORT is defined TRUE in compile option
#    but there is no enough internal PDP context, error and stop compile
# if APP_SECONDARY_PDP_SUPPORT is defined TRUE and there are enough internal PDP contexts
#    add a __TURN_ON_INTERNAL_SECONDARY_PDP__ option
#    add a __TURN_ON_GENERAL_SECONDARY_PDP__ option
#ifdef APP_SECONDARY_PDP_SUPPORT
#  ifeq ($(strip $(APP_SECONDARY_PDP_SUPPORT)),TRUE)
#    ifeq ($(call lt,$(strip $(MAX_INT_PDP_CONTEXT)),2),T)
#      $(warning ERROR: MAX_INT_PDP_CONTEXT is less than 2, it is impossible to define APP_SECONDARY_PDP_SUPPORT)
#      DEPENDENCY_CONFLICT = TRUE
#    endif
#      $(warning ERROR: GPRS_MAX_PDP_SUPPORT is less than 2, it is impossible to define APP_SECONDARY_PDP_SUPPORT)
#      DEPENDENCY_CONFLICT = TRUE
#    endif
#    # here means MAX_INT_PDP_CONTEXT >= 2 and GPRS_MAX_PDP_SUPPORT >= 2 and APP_SECONDARY_PDP_SUPPORT == TRUE
#    COM_DEFS          += __TURN_ON_INTERNAL_SECONDARY_PDP__
#    COM_DEFS          += __TURN_ON_GENERAL_SECONDARY_PDP__
#  endif
#endif

ifdef DMA_UART_VIRTUAL_FIFO
  VFIFO_NOT_SUPPORT_PLATFORM = MT6205 MT6208 MT6205B MT6208B MT6290 MT6595 MT6795
  ifneq ($(filter $(strip $(PLATFORM)),$(VFIFO_NOT_SUPPORT_PLATFORM)),)
    ifeq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) dose NOT support DMA_UART_VIRTUAL_FIFO.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  else
    ifneq ($(filter MT6752,$(strip $(PLATFORM))),)
      ifneq ($(strip $(MDSYS)),MD2)
        ifeq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
          $(warning ERROR: PLATFORM $(strip $(PLATFORM)) with MDSYS=$(MDSYS) dose NOT support DMA_UART_VIRTUAL_FIFO.)
          DEPENDENCY_CONFLICT = TRUE
        endif
      else
        ifneq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
          $(warning ERROR: DMA_UART_VIRTUAL_FIFO is a mandatory feature on PLATFORM $(strip $(PLATFORM)) with MDSYS=$(MDSYS))
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    else  
      ifneq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
        ifeq ($(filter MT6256 MT6276 MT6573 MT6575 MT6577,$(strip $(PLATFORM))),)
          $(warning ERROR: DMA_UART_VIRTUAL_FIFO is a mandatory feature on PLATFORM $(strip $(PLATFORM)))
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  endif
  ifeq ($(strip $(DMA_UART_VIRTUAL_FIFO)),TRUE)
    COM_DEFS    += __DMA_UART_VIRTUAL_FIFO__
  endif
endif

ifndef PHB_SIM_ENTRY
  PHB_SIM_ENTRY = 250
endif

ifdef PHB_SIM_ENTRY
  COM_DEFS    += MAX_PHB_SIM_ENTRY=$(strip $(PHB_SIM_ENTRY))
endif

ifndef PHB_PHONE_ENTRY
  PHB_PHONE_ENTRY = 200
endif

ifdef PHB_PHONE_ENTRY
  COM_DEFS    += MAX_PHB_PHONE_ENTRY=$(strip $(PHB_PHONE_ENTRY))
endif

ifndef PHB_LN_ENTRY
  PHB_LN_ENTRY = 20
endif

ifdef PHB_LN_ENTRY
  COM_DEFS    += MAX_PHB_LN_ENTRY=$(strip $(PHB_LN_ENTRY))
endif

ifdef LOW_COST_SUPPORT
  ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
    COM_DEFS    +=  LOW_COST_SUPPORT
    COM_DEFS    +=  __SAT_DISABLE_ICON_SUPPORT__
  endif
  ifeq ($(strip $(LOW_COST_SUPPORT)),COMMON)
    COM_DEFS    +=  __LOW_COST_SUPPORT_COMMON__
  endif
  ifeq ($(strip $(LOW_COST_SUPPORT)),ULC)
    COM_DEFS    +=  __LOW_COST_SUPPORT_COMMON__ __LOW_COST_SUPPORT_ULC__
  endif
endif

ifndef MAX_MIDI_FILE_SIZE
  MAX_MIDI_FILE_SIZE = 2097152
endif

ifdef EMS_SUPPORT
  ifeq ($(strip $(EMS_SUPPORT)),EMS_50)
    COM_DEFS    +=  __EMS_REL5__
  endif
  ifeq ($(strip $(EMS_SUPPORT)),EMS_40)
    # do nothing
  endif
  ifeq ($(strip $(EMS_SUPPORT)),EMS_SLIM)
    COM_DEFS    +=  __SLIM_EMS__
  endif
  ifeq ($(strip $(EMS_SUPPORT)),EMS_ULC_SLIM)
    COM_DEFS    +=  __SLIM_EMS__ __ULC_SLIM_EMS__
  endif
endif

MULTI_LNA_MODE_CALIBRATION_SUPPORT_PLATFORM = MT6575 MT6280 MT6577 MT6752 MT6290 MT6595 MT6795
ifneq ($(filter $(MULTI_LNA_MODE_CALIBRATION_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
  COM_DEFS    +=  __MULTI_LNA_MODE_CALIBRATION_SUPPORT__
endif

ifeq ($(strip $(2G_RF_CUSTOM_TOOL_SUPPORT)),TRUE)
  COM_DEFS    += __2G_RF_CUSTOM_TOOL_SUPPORT__
endif

ifeq ($(strip $(USIM_SUPPORT)),TRUE)
  COM_DEFS    +=   __USIM_SUPPORT__ __EF_NETPAR_SUPPORT__
  COM_DEFS    +=   __PHB_USIM_SUPPORT__
endif

ifndef SUB_LCD_SIZE
  SUB_LCD_SIZE = NONE
endif

ifdef SUB_LCD_SIZE
  COM_DEFS += __MMI_SUBLCD_$(call Upper,$(strip $(SUB_LCD_SIZE)))__
endif

ifdef DT_SUPPORT
  ifneq ($(strip $(DT_SUPPORT)),FALSE)
     COM_DEFS    +=  __DT_SUPPORT__
     COMPLIST    +=  dt
  endif
endif

ifdef USB_IN_NORMAL_MODE_SUPPORT
  ifeq ($(strip $(USB_IN_NORMAL_MODE_SUPPORT)),TRUE)
    ifeq ($(strip $(USB_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,USB_IN_NORMAL_MODE_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS += __USB_IN_NORMAL_MODE__
#      ifneq ($(strip $(MMI_VERSION)),WISDOM_MMI)
        COM_DEFS += __USB_IN_NORMAL_MODE_IMPROVE__
#      endif
    endif
  endif
endif

ifeq ($(filter MT6205B MT6208 MT6218B MT6217,$(strip $(PLATFORM))),)
  COM_DEFS +=  __USIM_DRV__
endif

ifneq ($(filter __DISABLE_SMS_CONTROLLED_BY_SIM__,$(strip $(COM_DEFS))),)
  ifeq ($(filter __SAT__,$(strip $(COM_DEFS))),)
    $(warning ERROR: Please define __SAT__ or do not define __DISABLE_SMS_CONTROLLED_BY_SIM__)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

#ifeq ($(strip $(OBIGO_FEATURE)),NONE)
  COM_DEFS    += WAP_NOT_PRESENT
  COM_DEFS    += WPS_NOT_PRESENT
#else
#  ifeq ($(strip $(BROWSER_SUPPORT)),OBIGO_Q05A)
#    COM_DEFS    += WAP_NOT_PRESENT
#  endif
#endif

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  COM_DEFS    += __MANUAL_MODE_NW_SEL__ 
endif

ifdef CUST_PARA_SUPPORT
  ifeq ($(strip $(CUST_PARA_SUPPORT)),TRUE)
    ifneq ($(strip $(SECURE_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SECURE_SUPPORT,CUST_PARA_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __CUST_PARA_SUPPORT__
  endif
endif

ifdef OTP_SUPPORT
  ifeq ($(strip $(OTP_SUPPORT)),TRUE)
    COM_DEFS    += __SECURITY_OTP__
    COM_DEFS    += __NVRAM_OTP__
  endif
endif

ifneq ($(filter $(strip $(PLATFORM)),$(SV5_PLATFORM)),)
  ifeq ($(strip $(SMART_PHONE_CORE)),NONE)
    COM_DEFS += __SV5_ENABLED__
  endif
  ifndef X_BOOTING
    $(warning ERROR: X_BOOTING must be defined.)
  else
    ifneq ($(strip $(X_BOOTING)),NONE)
      COM_DEFS += __SV5_ENABLED__
    endif
  endif
endif

ifdef NEED_BUILD_MD_OFFLOAD_COPRO
ifneq ($(strip $(NEED_BUILD_MD_OFFLOAD_COPRO)),TRUE)
ifneq ($(filter $(strip $(PLATFORM)),$(SV5X_PLATFORM)),)
  COM_DEFS += __SV5X_ENABLED__
endif
endif
endif

ifdef SSS_SUPPORT
  ifeq ($(strip $(SSS_SUPPORT)),SSS_LIB)
    ifeq ($(strip $(COMPILER)),RVCT)
      ifneq ($(filter $(strip $(PLATFORM)),$(SV5_PLATFORM)),)
        COMPOBJS    += service/sss/lib/libsss_rvct_sv5.a
#        CUS_REL_OBJ_LIST    += service/sss/lib/libsss_rvct_sv5.a
      else
        COMPOBJS    += service/sss/lib/libsss_rvct_dummy.a
#        CUS_REL_OBJ_LIST    += service/sss/lib/sss_rvct_dummy.lib
      endif
    else
      ifeq ($(strip $(COMPILER)),GCC)
        ifneq ($(filter $(strip $(PLATFORM)),$(SV5_PLATFORM) $(SV5X_PLATFORM)),)
          ifneq ($(strip $(NEED_BUILD_MD_OFFLOAD_COPRO)),TRUE)
            COMPOBJS    += service/sss/lib/libsss_gcc_sv5.a
#           CUS_REL_OBJ_LIST    += service/sss/lib/sss_gcc_sv5.lib
          else
	        COMPOBJS    += service/sss/lib/libsss_gcc_dummy.a 	
          endif 
        else
          COMPOBJS    += service/sss/lib/libsss_gcc_dummy.a
#          CUS_REL_OBJ_LIST    += service/sss/lib/sss_gcc_dummy.lib
        endif
      else
       COMPOBJS    += service/sss/lib/libsss.a
#       CUS_REL_OBJ_LIST    += service/sss/lib/sss.lib
      endif
    endif
  endif
endif

COMPOBJS += modem/common/kdf/lib/gcc/libkdf.a

ifndef DLT_ALWAYS_LOAD_BUFFER_SIZE
  DLT_ALWAYS_LOAD_BUFFER_SIZE = 0
endif

ifdef DLT_ALWAYS_LOAD_BUFFER_SIZE
  COM_DEFS    += __DLT_ALWAYS_LOAD_BUFFER_SIZE__=$(strip $(DLT_ALWAYS_LOAD_BUFFER_SIZE))
endif

ifndef DLT_LOAD_ON_DEMAND_BUFFER_SIZE
  DLT_LOAD_ON_DEMAND_BUFFER_SIZE = 0
endif

ifdef DLT_LOAD_ON_DEMAND_BUFFER_SIZE
  COM_DEFS    += __DLT_LOAD_ON_DEMAND_BUFFER_SIZE__=$(strip $(DLT_LOAD_ON_DEMAND_BUFFER_SIZE))
endif

ifneq ($(strip $(OPTR_CODE)),OP12)
  COM_DEFS    += __IP_NUMBER__
endif


CR4_PLATFORM = TK6280 MT6280 MT6290 MT6595 MT6795
CR4_WITH_COPRO_PLATFORM = MT6290 MT6595 MT6795
ifdef PLATFORM
  ifeq ($(strip $(PLATFORM)),MT6280)
    COM_DEFS    += __CR4__ __DYNAMIC_SWITCH_CACHEABILITY__ __IS_NAS_ITCM_DTCM__
  endif
  ifeq ($(strip $(PLATFORM)),MT6575)
    COM_DEFS    += __ARM11_MMU__ __ARM1176__ __DYNAMIC_SWITCH_CACHEABILITY__ __UNALIGNED_ACCESS_SUPPORT__
  endif
  ifeq ($(strip $(PLATFORM)),MT6577)
    COM_DEFS    += __ARM11_MMU__ __ARM1176__ __DYNAMIC_SWITCH_CACHEABILITY__ __UNALIGNED_ACCESS_SUPPORT__
  endif
  ifeq ($(strip $(PLATFORM)),MT6752)
     ifeq ($(strip $(MDSYS)),MD1)
       ifeq ($(strip $(NEED_BUILD_MD_OFFLOAD_COPRO)),TRUE)
         COM_DEFS    += __ARM7EJ_S__ __MTK_MMU_V2__ __DYNAMIC_SWITCH_CACHEABILITY__ ##__REDUCE_TCM_SUPPORT__ ##DISABLE_MPU_RO_PROTECT
         COM_DEFS    += __COPRO_OFFLOAD_TASKS__ __COPRO_ENVIRON__
       else
         COM_DEFS    += __CR4__ __DYNAMIC_SWITCH_CACHEABILITY__ __IS_NAS_ITCM_DTCM__ ARMV6_INST_ENABLE
       endif
     endif
     ifeq ($(strip $(MDSYS)),MD2)
       COM_DEFS    += __ARM9_MMU__ __ARM9_DCACHEABLE__ __DYNAMIC_SWITCH_CACHEABILITY__
     endif
  endif
  ifneq ($(filter $(strip $(PLATFORM)), $(strip $(CR4_WITH_COPRO_PLATFORM))),)
    ifeq ($(strip $(NEED_BUILD_MD_OFFLOAD_COPRO)),FALSE)
      COM_DEFS    += __CR4__ __DYNAMIC_SWITCH_CACHEABILITY__ __IS_NAS_ITCM_DTCM__ ARMV6_INST_ENABLE
    endif
    ifeq ($(strip $(NEED_BUILD_MD_OFFLOAD_COPRO)),TRUE)
      COM_DEFS    += __ARM7EJ_S__ __MTK_MMU_V2__ __DYNAMIC_SWITCH_CACHEABILITY__ ##__REDUCE_TCM_SUPPORT__ ##DISABLE_MPU_RO_PROTECT
      COM_DEFS    += __COPRO_OFFLOAD_TASKS__ __COPRO_ENVIRON__
    endif
  endif
endif

ifeq ($(strip $(CLIB_TIME_SUPPORT)), TRUE)
  COM_DEFS += __SUPPORT_CLIB_TIME__
  ifneq ($(strip $(CCCI_DEV_SUPPORT)), TRUE)
    $(warning ERROR: please turn on CCCI_DEV_SUPPORT and HIF_CCCI_SUPPORT, when CLIB_TIME_SUPPORT is set.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(HIF_CCCI_SUPPORT)), TRUE)
    $(warning ERROR: please turn on CCCI_DEV_SUPPORT and HIF_CCCI_SUPPORT, when CLIB_TIME_SUPPORT is set.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef RRLP_VER_SUPPORT
  ifneq ($(strip $(RRLP_VER_SUPPORT)), NONE)
    ifeq ($(strip $(AGPS_SUPPORT)), NONE)
      $(call DEP_ERR_ONA_OR_OFFB,AGPS_SUPPORT,RRLP_VER_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef AGPS_SUPPORT
      $(call DEP_ERR_ONA_OR_OFFB,AGPS_SUPPORT,RRLP_VER_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifeq ($(strip $(RRLP_VER_SUPPORT)), R99)
    COM_DEFS += __RRLP_REL_99__
  endif
  ifeq ($(strip $(RRLP_VER_SUPPORT)), R5)
    COM_DEFS += __RRLP_REL_5__
  endif
  ifeq ($(strip $(RRLP_VER_SUPPORT)), R7)
    COM_DEFS += __RRLP_REL_5__ __RRLP_REL_7__ __POS_CAP_TRANSFER_PROCEDURE_SUPPORT__
  endif
endif

ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
  ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
    COM_DEFS +=  __GSM_RAT__ 
  endif
endif

ifeq ($(strip $(PLATFORM)),MT6575)
  COM_DEFS += __NFI_VERSION3_1__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6577)
  COM_DEFS += __NFI_VERSION3_1__ __NAND_FDM_50__
endif

ifeq ($(strip $(PLATFORM)),MT6280)
  COM_DEFS += __NFI_VERSION3_1__ __NAND_FDM_50__ __ECC_8_BIT_SUPPORT__ __NAND_MDL_APPEND__
endif

ifeq ($(strip $(PLATFORM)),MT6290)
  ifeq ($(strip $(NAND_SUPPORT)),TRUE)
    ifeq ($(strip $(SERIAL_FLASH_SUPPORT)),TRUE)
      $(warning ERROR: SERIAL_FLASH_SUPPORT cannot be enabled when NAND_SUPPORT is TRUE)
    endif
      COM_DEFS += __NFI_VERSION3_1__ __NAND_FDM_50__ __ECC_8_BIT_SUPPORT__
      COMPLIST += mtd
  endif
endif

ifdef NOR_SUPPORT_RAW_DISK
  ifeq ($(strip $(NOR_SUPPORT_RAW_DISK)),TRUE)
    COM_DEFS += __NOR_SUPPORT_RAW_DISK__
    ifdef SYSDRV_BACKUP_DISK_SUPPORT
      ifeq ($(strip $(SYSDRV_BACKUP_DISK_SUPPORT)),RAW)
        COM_DEFS += __SYSDRV_BACKUP_DISK__
        COM_DEFS += __SYSDRV_BACKUP_DISK_RAW__
      endif
    endif
    ifdef LGE_SECURITY
      ifeq ($(strip $(LGE_SECURITY)),TRUE)
        COM_DEFS += __CUSTOMER_TC01_DISK__
      endif
    endif
  endif
endif

SAIC_NOT_SUPPORT_FLATFORM = MT6205 MT6205B MT6208 MT6217 MT6218 MT6218B MT6219 MT6225 MT6226 MT6226D MT6226M MT6227 MT6227D MT6228 MT6229 MT6230 
ifeq ($(filter $(strip $(PLATFORM)),$(SAIC_NOT_SUPPORT_FLATFORM)),)
  COM_DEFS    +=    __SAIC__
endif

ifneq ($(filter __SAIC__,$(COM_DEFS)),)
  ifneq ($(filter $(strip $(PLATFORM)),$(SAIC_NOT_SUPPORT_FLATFORM)),)
    $(warning ERROR: __SAIC__ cannot be defined for PLATFORM $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

REPEATED_ACCH_NOT_SUPPORT_FLATFORM = MT6205 MT6205B MT6208 MT6217 MT6218 MT6218B MT6219 MT6223 MT6223P MT6225 MT6226 MT6226D MT6226M MT6227 MT6227D MT6228 MT6229 MT6230 MT6235B MT6238 MT6239 MT6268T MT6268H
ifeq ($(filter $(strip $(PLATFORM)),$(REPEATED_ACCH_NOT_SUPPORT_FLATFORM)),)
  COM_DEFS    +=    __REPEATED_ACCH__
endif
ifneq ($(filter __REPEATED_ACCH__,$(COM_DEFS)),)
  ifneq ($(filter $(strip $(PLATFORM)),$(REPEATED_ACCH_NOT_SUPPORT_FLATFORM)),)
    $(warning ERROR: __REPEATED_ACCH__ cannot be defined for PLATFORM $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

VAMOS_NOT_SUPPORT_FLATFORM = MT6575 MT6577
VAMOS_CAP_DEFAULT_NOT_SUPPORT_FLATFORM = MT6280
ifeq ($(strip $(VAMOS_SUPPORT)),TRUE)
    ifneq ($(filter $(strip $(PLATFORM)),$(VAMOS_NOT_SUPPORT_FLATFORM)),)
      $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support VAMOS_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS  += __VAMOS_1__ __VAMOS_2__
    ifeq ($(strip $(R7R8_FULL_SET_SUPPORT)),TRUE)
      COM_DEFS    +=   __CUSTOMIZE_VAMOS__
    else
      ifneq ($(strip $(L1_TDD128)),TRUE)
         ifneq ($(strip $(OP01_2G_ONLY)),TRUE) 
      ifeq ($(filter $(strip $(PLATFORM)),$(VAMOS_CAP_DEFAULT_NOT_SUPPORT_FLATFORM)),)
        COM_DEFS    +=   __CUSTOMIZE_VAMOS__
      endif
    endif
endif
    endif
endif


ifneq ($(filter __VAMOS_1__,$(COM_DEFS)),)
  ifneq ($(filter $(strip $(PLATFORM)),$(VAMOS_NOT_SUPPORT_FLATFORM)),)
    $(warning ERROR: __VAMOS_1__ cannot be defined for PLATFORM $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifneq ($(filter __VAMOS_2__,$(COM_DEFS)),)
  ifneq ($(filter $(strip $(PLATFORM)),$(VAMOS_NOT_SUPPORT_FLATFORM)),)
    $(warning ERROR: __VAMOS_2__ cannot be defined for PLATFORM $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(TST_WRITE_TO_FILE)),TRUE)
  ifeq ($(strip $(TST_SUPPORT)),TRUE)
    COM_DEFS    += __TST_WRITE_TO_FILE__
  endif
endif

ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
  ifdef LOW_COST_SUPPORT
    ifeq ($(strip $(LOW_COST_SUPPORT)),NONE)
      COM_DEFS += __GIS_INTERNAL__
    endif
  else
    COM_DEFS += __GIS_INTERNAL__
  endif
endif

ifdef RFC2507_SUPPORT
  ifeq ($(strip $(RFC2507_SUPPORT)),TRUE)
    ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
      COMPLIST          += rfc2507
      COMP_TRACE_DEFS_MODEM   += $(strip $(UAS_FOLDER))/ul2/rfc2507/include/rfc2507_lib_trc.h
      COM_DEFS          += __RFC2507_SUPPORT__
    endif
  endif
endif

#ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
  ifeq ($(strip $(USB_SUPPORT)),TRUE)
    ifneq ($(strip $(MODEM_CARD)),NONE)
      COM_DEFS += __USB_MODEM_CARD_SUPPORT__
      COM_DEFS += __USB_MASS_STORAGE_CDROM_ENABLE__
      ifeq ($(strip $(USB_MASS_STORAGE_SUPPORT)),TRUE)
        ifneq ($(strip $(USB_IN_NORMAL_MODE_SUPPORT)),TRUE)
          $(warning ERROR: please turn on USB_IN_NORMAL_MODE_SUPPORT , when USB_MASS_STORAGE_SUPPORT is set to TRUE .)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  endif
  ifneq ($(strip $(RSAT_SUPPORT)),MODEM_WITH_RSAT)
    $(call DEP_ERR_SETA_OR_OFFB,RSAT_SUPPORT,MODEM_WITH_RSAT,EMPTY_MMI)
    DEPENDENCY_CONFLICT = TRUE
  endif
#endif

ifneq ($(call Upper,$(strip $(EUTRAN_MODE_SUPPORT))),NONE)
  ifeq ($(strip $(LPP_SUPPORT)),CONTROL_PLANE)
    COMPLIST   += lpp
    COM_DEFS   += __LPP_SUPPORT__
    COM_DEFS   += __LPP_CP_SUPPORT__
    COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/agps/lpp/include/lpp_trc.h
  endif
endif
ifeq ($(strip $(LPP_SUPPORT)),CONTROL_PLANE)
  ifeq ($(call Upper,$(strip $(EUTRAN_MODE_SUPPORT))),NONE)
    $(warning ERROR: please turn on EUTRAN_MODE_SUPPORT, when LPP_SUPPORT is set.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif
ifeq ($(strip $(LPP_SUPPORT)),CONTROL_PLANE)
  ifeq ($(call Upper,$(strip $(AGPS_SUPPORT))),NONE)
  ifeq ($(call Upper,$(strip $(LTE_OTDOA_SUPPORT))),FALSE)
  ifeq ($(call Upper,$(strip $(LTE_ECID_SUPPORT))),FALSE)
    $(warning ERROR: please turn on at least one of AGPS_SUPPORT, LTE_OTDOA_SUPPORT, LTE_ECID_SUPPORT, when LPP_SUPPORT is set.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  endif
  endif
endif


ifneq ($(call Upper,$(strip $(EUTRAN_MODE_SUPPORT))),NONE)
  ifeq ($(strip $(LPP_SUPPORT)),CONTROL_PLANE)
    ifeq ($(strip $(LTE_OTDOA_SUPPORT)),TRUE)
      COM_DEFS += __LTE_OTDOA_SUPPORT__
    endif
  endif
endif
ifeq ($(strip $(LTE_OTDOA_SUPPORT)),TRUE)
  ifeq ($(call Upper,$(strip $(EUTRAN_MODE_SUPPORT))),NONE)
    $(warning ERROR: please turn on EUTRAN_MODE_SUPPORT and LPP_SUPPORT, when LTE_OTDOA_SUPPORT is set to TRUE.)
    DEPENDENCY_CONFLICT = TRUE
  else
    ifeq ($(strip $(LPP_SUPPORT)),NONE)
        $(warning ERROR: please turn on EUTRAN_MODE_SUPPORT and LPP_SUPPORT, when LTE_OTDOA_SUPPORT is set to TRUE.)
        DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif


ifneq ($(call Upper,$(strip $(EUTRAN_MODE_SUPPORT))),NONE)
  ifeq ($(strip $(LPP_SUPPORT)),CONTROL_PLANE)
    ifeq ($(strip $(LTE_ECID_SUPPORT)),TRUE)
      COM_DEFS += __LTE_ECID_SUPPORT__
    endif
  endif
endif
ifeq ($(strip $(LTE_ECID_SUPPORT)),TRUE)
  ifeq ($(call Upper,$(strip $(EUTRAN_MODE_SUPPORT))),NONE)
    $(warning ERROR: please turn on EUTRAN_MODE_SUPPORT and LPP_SUPPORT, when LTE_ECID_SUPPORT is set to TRUE.)
    DEPENDENCY_CONFLICT = TRUE
  else
    ifeq ($(strip $(LPP_SUPPORT)), NONE)
        $(warning ERROR: please turn on EUTRAN_MODE_SUPPORT and LPP_SUPPORT, when LTE_ECID_SUPPORT is set to TRUE.)
        DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef L1_GPS_REF_TIME_SUPPORT 
  ifeq ($(strip $(L1_GPS_REF_TIME_SUPPORT)), TRUE)
    COM_DEFS += __L1_GPS_AUTO_TIMING_SYNC_SUPPORT__
  endif
endif

ifdef AGPS_SUPPORT
  ifneq ($(strip $(AGPS_SUPPORT)), NONE)
    ifeq ($(strip $(GPS_SUPPORT)), NONE)
        $(call DEP_ERR_ONA_OR_OFFB,GPS_SUPPORT,AGPS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(RRLP_VER_SUPPORT)), NONE)
        $(call DEP_ERR_ONA_OR_OFFB,RRLP_VER_SUPPORT,AGPS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifndef RRLP_VER_SUPPORT
        $(call DEP_ERR_ONA_OR_OFFB,RRLP_VER_SUPPORT,AGPS_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), USER_PLANE)
      COM_DEFS += __AGPS_SUPPORT__ __AGNSS_SUPPORT__ __SUPL_SUPPORT__ __RRLP_SUPPORT__ __AGPS_USER_PLANE__ __NBR_CELL_INFO__
      COMPLIST        += supl rrlp
      COMP_TRACE_DEFS_MODEM += inet_ps/supl/include/supl_trc.h
      COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/agps/rrlp/include/rrlp_trc.h
      ifndef RRC_PAYLOAD_FOR_3G_UP_SUPPORT
        $(warning ERROR: Please define RRC_PAYLOAD_FOR_3G_UP_SUPPORT when AGPS_SUPPORT = $(strip $(AGPS_SUPPORT)))
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
        $(warning ERROR: AGPS_SUPPORT=USER_PLANE can only be set when __PS_SERVICE__ is defined.)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(RRC_PAYLOAD_FOR_3G_UP_SUPPORT)),TRUE)
        ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
          COM_DEFS += __UAGPS_UP_SUPPORT__
          ifeq ($(strip $(ULCS_ASN_SUPPORT_VERSION)), ULCS_ASN_SUPPORT_R6)
            COM_DEFS += __ULCS_ASN_SUPPORT_R6__
          endif
          COMPLIST += ulcs
          COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/agps/ulcs/uagps_up/include/uagps_up_trc.h
          COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/agps/ulcs/common/include/uagps_trc.h
        endif
        ifeq ($(strip $(UTRAN_MODE_SUPPORT)),UTRAN_FDD_MODE)
          COM_DEFS += __UAGPS_UP_SUPPORT__
          ifeq ($(strip $(ULCS_ASN_SUPPORT_VERSION)), ULCS_ASN_SUPPORT_R6)
            COM_DEFS += __ULCS_ASN_SUPPORT_R6__
          endif
          COMPLIST += ulcs
          COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/agps/ulcs/uagps_up/include/uagps_up_trc.h
          COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/agps/ulcs/common/include/uagps_trc.h
        endif
      endif
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), CONTROL_PLANE)
      COM_DEFS += __AGPS_SUPPORT__ __AGNSS_SUPPORT__ __RRLP_SUPPORT__ __AGPS_CONTROL_PLANE__
      COMPLIST        += rrlp asn1_common
      COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/agps/rrlp/include/rrlp_trc.h
      ifdef L1_GPS_REF_TIME_SUPPORT 
        ifeq ($(strip $(L1_GPS_REF_TIME_SUPPORT)), TRUE)
          COM_DEFS += __L1_GPS_REF_TIME_SUPPORT__
        endif
      endif
      ifdef AGPS_UP_CP_CONFLICT_HANDLING_SUPPORT
        ifeq ($(strip $(AGPS_UP_CP_CONFLICT_HANDLING_SUPPORT)), TRUE)
          COM_DEFS += __AGPS_UP_CP_CONFLICT_HANDLING__
        endif
      endif
      ifeq ($(strip $(UTRAN_MODE_SUPPORT)),UTRAN_FDD_MODE)
        COM_DEFS += __UAGPS_CP_SUPPORT__
        COMPLIST += ulcs
        COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/agps/ulcs/uagps_cp/include/uagps_cp_trc.h
        COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/agps/ulcs/common/include/uagps_trc.h
        ifdef AGPS_CP_SIB15_SUPPORT 
          ifeq ($(strip $(AGPS_CP_SIB15_SUPPORT)), TRUE)
            COM_DEFS += __AGPS_CP_SIB15__
          endif
        endif
        ifdef UMTS_RELEASE_SUPPORT
          ifeq ($(strip $(UMTS_RELEASE_SUPPORT)), UMTS_R6_SUPPORT)
            COM_DEFS += __ULCS_ASN_SUPPORT_R6__
          endif
          ifeq ($(strip $(UMTS_RELEASE_SUPPORT)), UMTS_R7_SUPPORT)
              COM_DEFS += __ULCS_ASN_SUPPORT_R6__
              COM_DEFS += __ULCS_ASN_SUPPORT_R7__
          endif
          ifeq ($(strip $(UMTS_RELEASE_SUPPORT)), UMTS_R8_SUPPORT)
              COM_DEFS += __ULCS_ASN_SUPPORT_R6__
              COM_DEFS += __ULCS_ASN_SUPPORT_R7__
              COM_DEFS += __ULCS_ASN_SUPPORT_R8__
          endif
          ifeq ($(strip $(UMTS_RELEASE_SUPPORT)), UMTS_R9_SUPPORT)
              COM_DEFS += __ULCS_ASN_SUPPORT_R6__
              COM_DEFS += __ULCS_ASN_SUPPORT_R7__
              COM_DEFS += __ULCS_ASN_SUPPORT_R8__
              COM_DEFS += __ULCS_ASN_SUPPORT_R9__
          endif
        endif
      endif
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), CP_AGPS)
      COM_DEFS += __AGPS_SUPPORT__ __AGNSS_SUPPORT__ __RRLP_SUPPORT__ __AGPS_CONTROL_PLANE__
      COMPLIST        += rrlp asn1_common
      COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/agps/rrlp/include/rrlp_trc.h
      ifdef L1_GPS_REF_TIME_SUPPORT 
        ifeq ($(strip $(L1_GPS_REF_TIME_SUPPORT)), TRUE)
          COM_DEFS += __L1_GPS_REF_TIME_SUPPORT__
        endif
      endif
      ifdef AGPS_UP_CP_CONFLICT_HANDLING_SUPPORT
        ifeq ($(strip $(AGPS_UP_CP_CONFLICT_HANDLING_SUPPORT)), TRUE)
          COM_DEFS += __AGPS_UP_CP_CONFLICT_HANDLING__
        endif
      endif
      ifeq ($(strip $(UTRAN_MODE_SUPPORT)),UTRAN_FDD_MODE)
        COM_DEFS += __UAGPS_CP_SUPPORT__
        COMPLIST += ulcs
        COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/agps/ulcs/uagps_cp/include/uagps_cp_trc.h
        COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/agps/ulcs/common/include/uagps_trc.h
        ifdef AGPS_CP_SIB15_SUPPORT 
          ifeq ($(strip $(AGPS_CP_SIB15_SUPPORT)), TRUE)
            COM_DEFS += __AGPS_CP_SIB15__
          endif
        endif
        ifdef UMTS_RELEASE_SUPPORT
          ifeq ($(strip $(UMTS_RELEASE_SUPPORT)), UMTS_R6_SUPPORT)
            COM_DEFS += __ULCS_ASN_SUPPORT_R6__
          endif
          ifeq ($(strip $(UMTS_RELEASE_SUPPORT)), UMTS_R7_SUPPORT)
              COM_DEFS += __ULCS_ASN_SUPPORT_R6__
              COM_DEFS += __ULCS_ASN_SUPPORT_R7__
          endif
          ifeq ($(strip $(UMTS_RELEASE_SUPPORT)), UMTS_R8_SUPPORT)
              COM_DEFS += __ULCS_ASN_SUPPORT_R6__
              COM_DEFS += __ULCS_ASN_SUPPORT_R7__
              COM_DEFS += __ULCS_ASN_SUPPORT_R8__
          endif
          ifeq ($(strip $(UMTS_RELEASE_SUPPORT)), UMTS_R9_SUPPORT)
              COM_DEFS += __ULCS_ASN_SUPPORT_R6__
              COM_DEFS += __ULCS_ASN_SUPPORT_R7__
              COM_DEFS += __ULCS_ASN_SUPPORT_R8__
              COM_DEFS += __ULCS_ASN_SUPPORT_R9__
          endif
        endif
      endif
      ifneq ($(filter __AGNSS_SUPPORT__,$(COM_DEFS)),)
        ifeq ($(filter __ULCS_ASN_SUPPORT_R7__,$(COM_DEFS)),)
          $(call DEP_ERR_ONA_OR_OFFB,__AGNSS_SUPPORT__,__ULCS_ASN_SUPPORT_R7__)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
      ifneq ($(filter __AGNSS_SUPPORT__,$(COM_DEFS)),)
        ifeq ($(filter __ULCS_ASN_SUPPORT_R8__,$(COM_DEFS)),)
          $(call DEP_ERR_ONA_OR_OFFB,__AGNSS_SUPPORT__,__ULCS_ASN_SUPPORT_R8__)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif    
    ifeq ($(strip $(AGPS_SUPPORT)), CP_AGPS_AGLONASS)
      COM_DEFS += __AGPS_SUPPORT__ __AGNSS_SUPPORT__ __AGLONASS_SUPPORT__ __RRLP_SUPPORT__ __AGPS_CONTROL_PLANE__
      COMPLIST        += rrlp asn1_common
      COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/agps/rrlp/include/rrlp_trc.h
      ifdef L1_GPS_REF_TIME_SUPPORT 
        ifeq ($(strip $(L1_GPS_REF_TIME_SUPPORT)), TRUE)
          COM_DEFS += __L1_GPS_REF_TIME_SUPPORT__
        endif
      endif
      ifdef AGPS_UP_CP_CONFLICT_HANDLING_SUPPORT
        ifeq ($(strip $(AGPS_UP_CP_CONFLICT_HANDLING_SUPPORT)), TRUE)
          COM_DEFS += __AGPS_UP_CP_CONFLICT_HANDLING__
        endif
      endif
      ifeq ($(strip $(UTRAN_MODE_SUPPORT)),UTRAN_FDD_MODE)
        COM_DEFS += __UAGPS_CP_SUPPORT__
        COMPLIST += ulcs
        COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/agps/ulcs/uagps_cp/include/uagps_cp_trc.h
        COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/agps/ulcs/common/include/uagps_trc.h
        ifdef AGPS_CP_SIB15_SUPPORT 
          ifeq ($(strip $(AGPS_CP_SIB15_SUPPORT)), TRUE)
            COM_DEFS += __AGPS_CP_SIB15__
          endif
        endif
        ifdef UMTS_RELEASE_SUPPORT
          ifeq ($(strip $(UMTS_RELEASE_SUPPORT)), UMTS_R6_SUPPORT)
            COM_DEFS += __ULCS_ASN_SUPPORT_R6__
          endif
          ifeq ($(strip $(UMTS_RELEASE_SUPPORT)), UMTS_R7_SUPPORT)
              COM_DEFS += __ULCS_ASN_SUPPORT_R6__
              COM_DEFS += __ULCS_ASN_SUPPORT_R7__
          endif
          ifeq ($(strip $(UMTS_RELEASE_SUPPORT)), UMTS_R8_SUPPORT)
              COM_DEFS += __ULCS_ASN_SUPPORT_R6__
              COM_DEFS += __ULCS_ASN_SUPPORT_R7__
              COM_DEFS += __ULCS_ASN_SUPPORT_R8__
          endif
          ifeq ($(strip $(UMTS_RELEASE_SUPPORT)), UMTS_R9_SUPPORT)
              COM_DEFS += __ULCS_ASN_SUPPORT_R6__
              COM_DEFS += __ULCS_ASN_SUPPORT_R7__
              COM_DEFS += __ULCS_ASN_SUPPORT_R8__
              COM_DEFS += __ULCS_ASN_SUPPORT_R9__
          endif
        endif
      endif
      ifneq ($(filter __AGNSS_SUPPORT__,$(COM_DEFS)),)
        ifeq ($(filter __ULCS_ASN_SUPPORT_R7__,$(COM_DEFS)),)
          $(call DEP_ERR_ONA_OR_OFFB,__AGNSS_SUPPORT__,__ULCS_ASN_SUPPORT_R7__)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
      ifneq ($(filter __AGNSS_SUPPORT__,$(COM_DEFS)),)
        ifeq ($(filter __ULCS_ASN_SUPPORT_R8__,$(COM_DEFS)),)
          $(call DEP_ERR_ONA_OR_OFFB,__AGNSS_SUPPORT__,__ULCS_ASN_SUPPORT_R8__)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), BOTH)
      COM_DEFS += __AGPS_SUPPORT__ __AGNSS_SUPPORT__ __SUPL_SUPPORT__ __RRLP_SUPPORT__ __AGPS_USER_PLANE__ __AGPS_CONTROL_PLANE__ __NBR_CELL_INFO__
      COMPLIST        += supl rrlp
      COMP_TRACE_DEFS_MODEM += inet_ps/supl/include/supl_trc.h
      COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/agps/rrlp/include/rrlp_trc.h
      ifdef L1_GPS_REF_TIME_SUPPORT 
        ifeq ($(strip $(L1_GPS_REF_TIME_SUPPORT)), TRUE)
          COM_DEFS += __L1_GPS_REF_TIME_SUPPORT__
        endif
      endif
      ifdef AGPS_UP_CP_CONFLICT_HANDLING_SUPPORT
        ifeq ($(strip $(AGPS_UP_CP_CONFLICT_HANDLING_SUPPORT)), TRUE)
          COM_DEFS += __AGPS_UP_CP_CONFLICT_HANDLING__
        endif                
      endif
      ifndef RRC_PAYLOAD_FOR_3G_UP_SUPPORT
        $(warning ERROR: Please define RRC_PAYLOAD_FOR_3G_UP_SUPPORT when AGPS_SUPPORT = $(strip $(AGPS_SUPPORT)))
        DEPENDENCY_CONFLICT = TRUE 
      endif
      ifeq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
        $(warning ERROR: AGPS_SUPPORT=BOTH can only be set when __PS_SERVICE__ is defined.)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifeq ($(strip $(UTRAN_MODE_SUPPORT)),UTRAN_FDD_MODE)
        COM_DEFS += __UAGPS_CP_SUPPORT__
        COMPLIST += ulcs
        COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/agps/ulcs/uagps_cp/include/uagps_cp_trc.h
        COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/agps/ulcs/common/include/uagps_trc.h
        ifdef AGPS_CP_SIB15_SUPPORT
          ifeq ($(strip $(AGPS_CP_SIB15_SUPPORT)), TRUE)
            COM_DEFS += __AGPS_CP_SIB15__
          endif
        endif
        ifdef UMTS_RELEASE_SUPPORT
          ifeq ($(strip $(UMTS_RELEASE_SUPPORT)), UMTS_R6_SUPPORT)
            COM_DEFS += __ULCS_ASN_SUPPORT_R6__
          endif
          ifeq ($(strip $(UMTS_RELEASE_SUPPORT)), UMTS_R7_SUPPORT)
              COM_DEFS += __ULCS_ASN_SUPPORT_R6__
              COM_DEFS += __ULCS_ASN_SUPPORT_R7__
          endif
          ifeq ($(strip $(UMTS_RELEASE_SUPPORT)), UMTS_R8_SUPPORT)
              COM_DEFS += __ULCS_ASN_SUPPORT_R6__
              COM_DEFS += __ULCS_ASN_SUPPORT_R7__
              COM_DEFS += __ULCS_ASN_SUPPORT_R8__
          endif
          ifeq ($(strip $(UMTS_RELEASE_SUPPORT)), UMTS_R9_SUPPORT)
              COM_DEFS += __ULCS_ASN_SUPPORT_R6__
              COM_DEFS += __ULCS_ASN_SUPPORT_R7__
              COM_DEFS += __ULCS_ASN_SUPPORT_R8__
              COM_DEFS += __ULCS_ASN_SUPPORT_R9__
          endif
        endif
        ifeq ($(strip $(RRC_PAYLOAD_FOR_3G_UP_SUPPORT)),TRUE)
          COM_DEFS += __UAGPS_UP_SUPPORT__
          ifeq ($(strip $(ULCS_ASN_SUPPORT_VERSION)), ULCS_ASN_SUPPORT_R6)
            COM_DEFS += __ULCS_ASN_SUPPORT_R6__
          endif
          COMP_TRACE_DEFS_MODEM += $(strip $(MODEM_FOLDER))/agps/ulcs/uagps_up/include/uagps_up_trc.h
        endif
      endif
    endif
  endif
endif

ifdef NDIS_SUPPORT
  ifeq ($(strip $(NDIS_SUPPORT)),TRUE)
    $(warning ERROR: Please set new value NONE/NDIS/UPS for NDIS_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif  
  ifeq ($(strip $(NDIS_SUPPORT)),FALSE)
    $(warning ERROR: Please set new value NONE/NDIS/UPS for NDIS_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(NDIS_SUPPORT)),NDIS)
    ifneq ($(strip $(CMUX_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,CMUX_SUPPORT,NDIS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __NDIS_SUPPORT__
  endif
  ifeq ($(strip $(NDIS_SUPPORT)),UPS)
    ifneq ($(strip $(CMUX_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,CMUX_SUPPORT,NDIS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
      COM_DEFS    += __NDIS_SUPPORT__ __UPS_SUPPORT__
      COMPLIST    += ups
      COMP_TRACE_DEFS_MODEM    += middleware/ups/ups/include/ups_trc.h
    endif
  endif

endif

ifdef CCBS_SUPPORT
  ifeq ($(strip $(CCBS_SUPPORT)),TRUE)
     COM_DEFS    += __CCBS_SUPPORT__
  endif
endif

ifdef CNAP_SUPPORT
  ifeq ($(strip $(CNAP_SUPPORT)),TRUE)
     COM_DEFS    += __CNAP_SUPPORT__
  endif
endif

ifdef SWITCHABLE_FEATURE_2ND
  ifneq ($(strip $(SWITCHABLE_FEATURE_2ND)),NONE)
    ifndef SWITCHABLE_FEATURE
      $(call DEP_ERR_ONA_OR_OFFB,SWITCHABLE_FEATURE,SWITCHABLE_FEATURE_2ND)
      DEPENDENCY_CONFLICT = TRUE
    else
      ifeq ($(strip $(SWITCHABLE_FEATURE)),NONE)
        $(call DEP_ERR_ONA_OR_OFFB,SWITCHABLE_FEATURE,SWITCHABLE_FEATURE_2ND)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef MODEM_3G_LOGGING
  ifeq ($(strip $(MODEM_3G_LOGGING)),TRUE)
    ifneq ($(strip $(USB_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,USB_SUPPORT,MODEM_3G_LOGGING)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    += __MODEM_3G_LOGGING__
    COM_DEFS    += __USB_LOGGING__
  endif
endif

ifdef EXT_MODEM_SUPPORT
  ifeq ($(strip $(EXT_MODEM_SUPPORT)), TRUE)
    COMPLIST          += ext_modem
    COMP_TRACE_DEFS_MODEM   += $(strip $(MODEM_FOLDER))/ext_modem/include/ext_modem_trc.h
    COM_DEFS += __EXT_MODEM__
  endif
endif

ifndef SMS_PHONE_ENTRY
  $(warning ERROR: Please define SMS_PHONE_ENTRY in project makefile.)
  DEPENDENCY_CONFLICT = TRUE
endif

ifndef SMS_TOTAL_ENTRY
  $(warning ERROR: Please define SMS_TOTAL_ENTRY in project makefile.)
  DEPENDENCY_CONFLICT = TRUE
endif

ifdef SMS_PHONE_ENTRY
  COM_DEFS    += SMS_PHONE_ENTRY=$(strip $(SMS_PHONE_ENTRY))
endif

ifdef SMS_TOTAL_ENTRY
  COM_DEFS    += SMS_TOTAL_ENTRY=$(strip $(SMS_TOTAL_ENTRY))
endif

ifdef SECURE_PORT_SUPPORT
  ifeq ($(strip $(SECURE_PORT_SUPPORT)),TRUE)
    ifneq ($(strip $(SECURE_RO_ENABLE)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,SECURE_RO_ENABLE,SECURE_PORT_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    else
      COM_DEFS    += __SECURE_PORT_SUPPORT__
    endif
  endif
endif

ifdef BIP_SCWS_SUPPORT
  ifeq ($(strip $(BIP_SCWS_SUPPORT)),TRUE)
    ifneq ($(strip $(TCPIP_LOOP_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,TCPIP_LOOP_SUPPORT,BIP_SCWS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(filter __SAT__,$(COM_DEFS)),)
        $(warning ERROR: __SAT__ must be defined when BIP_SCWS_SUPPORT is turned on.)
        DEPENDENCY_CONFLICT = TRUE
    endif   
    COM_DEFS    += __SATCE__
  endif
endif

ifdef IPSEC_SUPPORT
  ifneq ($(strip $(IPSEC_SUPPORT)),FALSE)
    COM_DEFS    += __IPSEC__
    COMP_TRACE_DEFS_MODEM    += service/security/ike/include/ike_trc.h
    COMMINCDIRS     +=  interface/security
    COMPLIST    += ipsec netkey ike
  endif
endif

ifndef VENDOR
  VENDOR = NONE
endif

ifdef VENDOR
  ifneq ($(strip $(VENDOR)),NONE)
    COM_DEFS +=  DEVAPP_RESOURCE
  endif
  COM_DEFS += VENDOR_$(strip $(VENDOR))
endif

ifdef PRODUCTION_RELEASE
  ifeq ($(strip $(PRODUCTION_RELEASE)),FALSE)
    COM_DEFS += L1A_DEVELOP_DEBUG
    ifeq ($(strip $(VENDOR)),NONE)
      ifneq ($(strip $(DEMO_PROJECT)),TRUE)
        ifeq ($(findstring REL_CR_OBJ_JAL_SRC,$(strip $(RELEASE_PACKAGE))),)
          $(call DEP_ERR_ONA_OR_ONB,PRODUCTION_RELEASE,DEMO_PROJECT)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    
      ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
        ifeq ($(filter REL_CR_OBJ_JAL_SRC% REL_CR_MMI_VOGINS% REL_CR_INET_MMI_ROLLTECH%,$(strip $(RELEASE_PACKAGE))),)
          $(call DEP_ERR_ONA_OR_ONB,PRODUCTION_RELEASE,MTK_SUBSIDIARY)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    endif
  else
    ifeq ($(strip $(DEMO_PROJECT)),TRUE)
      $(call DEP_ERR_OFFA_OR_OFFB,DEMO_PROJECT,PRODUCTION_RELEASE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifneq ($(filter __SMS_DEPERSONALIZATION__,$(COM_DEFS)),)
  ifeq ($(filter __MOD_SMU__,$(COM_DEFS)),)
    $(call DEP_ERR_ONA_OR_OFFB,__MOD_SMU__,__SMS_DEPERSONALIZATION__)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(filter __MOD_SMS__,$(COM_DEFS)),)
    $(call DEP_ERR_ONA_OR_OFFB,__MOD_SMS__,__SMS_DEPERSONALIZATION__)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef GPRS_DIALUP_PPP_SUPPORT_ESCAPE_ATO
  ifeq ($(strip $(GPRS_DIALUP_PPP_SUPPORT_ESCAPE_ATO)), TRUE)
    COM_DEFS += __GPRS_DIALUP_ESCAPE_ATO_SUPPORT__
  endif
endif

ifdef GPRS_DIALUP_PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND 
  ifeq ($(strip $(GPRS_DIALUP_PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND)), TRUE)
    COM_DEFS += __PPP_DROP_PACKETS_WHEN_2G_PS_SUSPEND__
  endif
endif

ifdef MULTIPLE_PPP_DIALUP_SUPPORT
  ifeq ($(strip $(MULTIPLE_PPP_DIALUP_SUPPORT)),TRUE)
    ifeq ($(call gt,$(strip $(MAX_NUM_OF_PPP_DIALUP_SUPPORT)),$(strip $(GPRS_MAX_PDP_SUPPORT))),T)
      $(warning ERROR: MAX_NUM_OF_PPP_DIALUP_SUPPORT value ($(MAX_NUM_OF_PPP_DIALUP_SUPPORT)) should not be larger than GPRS_MAX_PDP_SUPPORT value ($(GPRS_MAX_PDP_SUPPORT)))
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(call gt,$(strip $(MAX_NUM_OF_PPP_DIALUP_SUPPORT)),3),T)
      $(warning ERROR: MAX_NUM_OF_PPP_DIALUP_SUPPORT value ($(MAX_NUM_OF_PPP_DIALUP_SUPPORT)) should not be larger than 3)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(call lt,$(strip $(MAX_NUM_OF_PPP_DIALUP_SUPPORT)),2),T)
      $(warning ERROR: MAX_NUM_OF_PPP_DIALUP_SUPPORT value ($(MAX_NUM_OF_PPP_DIALUP_SUPPORT)) should not be less than 2)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS          += __MULTIPLE_PPP_DIALUP_SUPPORT__
    COM_DEFS          += __MAX_NUM_OF_PPP_DIALUP_SUPPORT__=$(strip $(MAX_NUM_OF_PPP_DIALUP_SUPPORT))
  endif
endif

ifneq ($(strip $(MODEM_CARD)),NONE)
  COM_DEFS += __MODEM_CARD__
  COM_DEFS += __DISABLE_MODEM_AUTO_POWER_OFF__
  COM_DEFS += __MODEM_AUTO_STARTUP_TO_FLIGHT_MODE__
  COM_DEFS += __CSCB_ALL_LANGUAGE_ON__
  COM_DEFS += __AT_LINUX_DATA_PORT__
  COM_DEFS += __MOBILE_BROADBAND_PROVISION_CONTEXT__
  COM_DEFS += __CSMSS_EXPLICIT_SS_OPERATION__
  ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
    COM_DEFS += __SPEECH_OVER_USB__
  endif
  ifeq ($(strip $(MODEM_CARD)),CS_CALL_DISABLE)
    COM_DEFS += __DISABLE_CSCALL__
  endif
  COM_DEFS += __SAT_AP_NOT_SUPPORT__
endif

ifdef MULTIPLE_NDIS_SUPPORT
  ifeq ($(strip $(MULTIPLE_NDIS_SUPPORT)),TRUE)
     ifndef NDIS_SUPPORT
       $(call DEP_ERR_ONA_OR_OFFB,NDIS_SUPPORT,MULTIPLE_NDIS_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(strip $(NDIS_SUPPORT)),NONE)
       $(call DEP_ERR_ONA_OR_OFFB,NDIS_SUPPORT,MULTIPLE_NDIS_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(strip $(MULTIPLE_PPP_DIALUP_SUPPORT)),TRUE)
       $(call DEP_ERR_OFFA_OR_OFFB,MULTIPLE_NDIS_SUPPORT,MULTIPLE_PPP_DIALUP_SUPPORT)
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(call gt,$(strip $(MAX_NUM_OF_NDIS_SUPPORT)),$(strip $(GPRS_MAX_PDP_SUPPORT))),T)
       $(warning ERROR: MAX_NUM_OF_NDIS_SUPPORT value ($(MAX_NUM_OF_NDIS_SUPPORT)) should not be larger than GPRS_MAX_PDP_SUPPORT value ($(GPRS_MAX_PDP_SUPPORT)))
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(call gt,$(strip $(MAX_NUM_OF_NDIS_SUPPORT)),6),T)
       $(warning ERROR: MAX_NUM_OF_NDIS_SUPPORT value ($(MAX_NUM_OF_NDIS_SUPPORT)) should not be larger than 6)
       DEPENDENCY_CONFLICT = TRUE
     endif
     ifeq ($(call lt,$(strip $(MAX_NUM_OF_NDIS_SUPPORT)),2),T)
       $(warning ERROR: MAX_NUM_OF_NDIS_SUPPORT value ($(MAX_NUM_OF_NDIS_SUPPORT)) should not be less than 2)
       DEPENDENCY_CONFLICT = TRUE
     endif
     COM_DEFS          += __MULTIPLE_NDIS_SUPPORT__
     COM_DEFS          += __MAX_NUM_OF_NDIS_SUPPORT__=$(strip $(MAX_NUM_OF_NDIS_SUPPORT))
  endif
endif

ifndef NVRAM_NOT_PRESENT
  ifdef NVRAM_PSEUDO_MERGE
    ifeq ($(strip $(NVRAM_PSEUDO_MERGE)),ON)
      COM_DEFS +=  __NVRAM_PSEUDO_MERGE__
    endif
  endif
endif

ifeq ($(strip $(SMS_R8_NATION_LANGUAGE)),TRUE)
  COM_DEFS += __SMS_R8_NATION_LANGUAGE__
endif

ifdef SMS_R8_TABLE_MECHANISM
  COM_DEFS += __$(strip $(SMS_R8_TABLE_MECHANISM))__
else
  COM_DEFS += __SMS_R8_DEFAULT__
endif

ifndef MELODY_BUFFER_LEN
  ifeq ($(strip $(MED_PROFILE)),MED_MODEM)
     MELODY_BUFFER_LEN = 512
  else
    ifeq ($(strip $(MED_PROFILE)),MED_LOW)
      MELODY_BUFFER_LEN = 1300
    else
      MELODY_BUFFER_LEN = 102400
    endif
  endif
endif 

ifdef OPTR_CODE
  ifeq ($(strip $(OPTR_CODE)),OP12)
    MELODY_BUFFER_LEN = 307200
  endif
endif

ifdef MELODY_BUFFER_LEN
  COM_DEFS += MAX_MELODY_BUF_LEN=$(strip $(MELODY_BUFFER_LEN))
endif

ifdef GPRS_DIALUP_PPP_SUPPORT_SPEED_UP_DIALUP
  ifeq ($(strip $(GPRS_DIALUP_PPP_SUPPORT_SPEED_UP_DIALUP)),TRUE)
    COM_DEFS += __PPP_SPEED_UP_IPV4_GPRS_DIALUP__
  endif
endif

COM_DEFS += __HO_IMPROVE__

ifdef DRV_DEBUG_MEMORY_TRACE_SUPPORT
  ifeq ($(strip $(DRV_DEBUG_MEMORY_TRACE_SUPPORT)),TRUE)
    COM_DEFS    +=  __DRV_DBG_MEMORY_TRACE_SUPPORT__
  endif
endif

ifdef SMART_PHONE_CORE
  ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
    COM_DEFS += __AT_EPBW_SUPPORT__
  endif
endif

ifndef PHB_NAME_LENGTH
#  ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
#    PHB_NAME_LENGTH = 30
#  else
    PHB_NAME_LENGTH = 40
#  endif
endif

ifdef PHB_NAME_LENGTH
  ifeq ($(call gt,$(strip $(PHB_NAME_LENGTH)),80),T)
    $(warning ERROR: PHB_NAME_LENGTH value should not be larger than 80)
    DEPENDENCY_CONFLICT = TRUE
  endif
#  ifeq ($(strip $(MMI_VERSION)),NEPTUNE_MMI)
#    COM_DEFS    += MAX_PHB_NAME_LENGTH=16
#  else
    COM_DEFS    += MAX_PHB_NAME_LENGTH=$(strip $(PHB_NAME_LENGTH))
#  endif
  COM_DEFS    += MAX_PS_NAME_SIZE=$(call plus,$(PHB_NAME_LENGTH),2)
endif

MCD_DEFS  = __R99__
MCD_DEFS += MAX_PS_NAME_SIZE=$(call plus,$(PHB_NAME_LENGTH),2)
ifdef MCD_CODESET_SHIFT_SUPPORT
  ifneq ($(strip $(MCD_CODESET_SHIFT_SUPPORT)),NONE)
    MCD_DEFS += __MCD_CODESET_SHIFT__
    MCD_DEFS += $(foreach def, $(MCD_CODESET_SHIFT_SUPPORT), __MCD_CODESET_SHIFT_$(def)__)
    COM_DEFS += __MCD_CODESET_SHIFT__
    COM_DEFS += $(foreach def, $(MCD_CODESET_SHIFT_SUPPORT), __MCD_CODESET_SHIFT_$(def)__)
  endif
endif

ifneq ($(filter __L4_MAX_NAME_60__,$(COM_DEFS)),)
  MCD_DEFS += __L4_MAX_NAME_60__
endif

ifeq ($(strip $(PLMN_LIST_PREF_SUPPORT)),ON)
  COM_DEFS += __PLMN_LIST_PREF_SUPPORT__
endif

ifneq ($(filter __MONITOR_PAGE_DURING_TRANSFER__,$(COM_DEFS)),)
  ifeq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
    $(warning ERROR: __MONITOR_PAGE_DURING_TRANSFER__ can only be defined when __PS_SERVICE__ is defined.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifneq ($(filter __MONITOR_PAGE_DURING_TRANSFER__ __GEMINI_MONITOR_PAGE_DURING_TRANSFER__,$(COM_DEFS)),)
  COM_DEFS  += __ADAPTIVE_PAGING_PERIOD_IN_UNACK_MODE__
endif

ifdef OPTR_SPEC_MODEM
  ifeq ($(strip $(OPTR_SPEC_MODEM)), ATT_0402_ADAPT)
    ifeq ($(strip $(USIM_SUPPORT)), TRUE)
      COM_DEFS  += __U_CSP_SUPPORT__
    endif
#    ifneq ($(filter PLUTO_MMI COSMOS_MMI ,$(strip $(MMI_VERSION))),)
#      COM_DEFS  += __SIM_FILE_CHANGE_WITH_MMI_ACK__
#    endif
    COM_DEFS  += __GPRS_PDP_ALL_QOS_ARE_SUBSCRIBED__
    COM_DEFS  += __IOT_TEST__ 
    COM_DEFS  += __ENS__
    COM_DEFS  += __ENS_RAT_BALANCING__ 
    COM_DEFS  += __ATT_FLIGHT_MODE_GPS_HANDLING__
    COM_DEFS  += __ATNT_HPPLMN_SEARCH__
    COM_DEFS  += __DISABLE_AUTO_RETURN_PRE_RPLMN__
    COM_DEFS  += __OPTIMAL_SIM_FILE_UPDATE__
    COM_DEFS  += __DISABLE_RPLMN_FROM_GLOCI__
    COM_DEFS  += __RESUME_GPRS_AFTER_LU_ABNORMAL__
    COM_DEFS  += __CSIM__
    COM_DEFS  += __ATCFUN_FLIGHTMODE_SUPPORT__
    COM_DEFS  += __NW_DETACH_SUPPORT__
    COM_DEFS  += __CLAC_SUPPORT__
    COM_DEFS  += __CGSMS_FULL_SUPPORT__
    COM_DEFS  += __UDH_MESSAGE_WAITING_HIGH_PRIORITY__
    COM_DEFS  += __AT_ME_IDENTIFICATION_WITHOUT_HEADER__
    COM_DEFS  += __SAT_NO_EVDL_IN_SESSION__
    COM_DEFS  += __IMEI_LOCK_SUPPORT__
    COM_DEFS  += __STAR_SHORT_STRING_AS_CALL__
    COM_DEFS  += __CUSTOMIZED_IDLE_STRING_AS_CALL__
    COM_DEFS  += __MM_DISABLE_RETRY_ABNORMAL_LAI__
  endif
  ifeq ($(strip $(OPTR_SPEC_MODEM)), H3G)
    COM_DEFS  += __PERMANENT_AUTO_SEL_MODE__
    COM_DEFS  += __DUMMY_OFF_R7_AUTO_RHPLMN_SEL__
    COM_DEFS  += __MM_HPPLMN_1ST_ATTEMPT_ENHANCE__
    COM_DEFS  += __MM_TRY_ABNORMAL_LAI_ONCE_MORE__
  endif
endif

ifdef UART_CHARGER_THE_SAME_INTERFACE
  ifeq ($(strip $(UART_CHARGER_THE_SAME_INTERFACE)),UART1)
    COM_DEFS    += __UART1_WITH_CHARGER__
  endif
  ifeq ($(strip $(UART_CHARGER_THE_SAME_INTERFACE)),UART2)
    COM_DEFS    += __UART2_WITH_CHARGER__
  endif
  ifeq ($(strip $(UART_CHARGER_THE_SAME_INTERFACE)),UART3)
    COM_DEFS    += __UART3_WITH_CHARGER__
  endif
endif

ifdef LOW_COST_SUPPORT
  ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
    COM_DEFS    +=  __SLIM_NWK_PROFILE__
  endif
endif

ifdef SMS_OVER_PS_SUPPORT
  ifeq ($(strip $(SMS_OVER_PS_SUPPORT)),TRUE)
    ifeq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
      $(warning ERROR: __PS_SERVICE__ must be defined when SMS_OVER_PS_SUPPORT is turned on.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __SMS_OVER_PS_SUPPORT__
  endif
endif

ifdef PPP_TYPE_PDP_DIALUP_SUPPORT
  ifeq ($(strip $(PPP_TYPE_PDP_DIALUP_SUPPORT)),TRUE)
    COM_DEFS  +=  __PPP_TYPE_PDP_DIALUP_SUPPORT__
  endif
endif

#############################################################################################
# Add PPP_SUPPORT feature rule here
# firstly, set/reset PS_DIALUP and TCPIP_OVER_CSD sub_feature_option
# then check rule of each option
# last modify COMPLIST, if PPP_SUPPORT != NONE, then compile PPP
# this part should after PPP_DEPENDENCE_OPTION define to check valid or not
# if not define PPP_SUPPORT, we should keep option as what it is before wrapping action
#############################################################################################

ifdef PPP_SUPPORT
  ifeq ($(strip $(PPP_SUPPORT)),CSD_PPP_SUPPORT)
    PS_DIALUP = FALSE
    TCPIP_OVER_CSD = TRUE
  endif
  ifeq ($(strip $(PPP_SUPPORT)),GPRS_PPP_SUPPORT)
    PS_DIALUP = TRUE
    TCPIP_OVER_CSD = FALSE
  endif
  ifeq ($(strip $(PPP_SUPPORT)),FULL_SUPPORT)
    PS_DIALUP = TRUE
    TCPIP_OVER_CSD = TRUE
  endif
  
  ifeq ($(strip $(PS_DIALUP)),TRUE)
#    COM_DEFS += __PS_DIALUP__
  else
    PS_DIALUP_DEPENDENCE_OPTION = __MULTIPLE_PPP_DIALUP_SUPPORT__
    ifneq ($(filter $(PS_DIALUP_DEPENDENCE_OPTION),$(COM_DEFS)),)
      $(call DEP_ERR_SETA_OR_ONB, MULTIPLE_PPP_DIALUP_SUPPORT, FALSE, PS_DIALUP)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif

  ifeq ($(strip $(TCPIP_OVER_CSD)),TRUE)
    ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
      ifdef CSD_SUPPORT
        ifneq ($(strip $(CSD_SUPPORT)),NONE)
          COM_DEFS += __TCPIP_OVER_CSD__
        else
          $(warning ERROR: When TCPIP_OVER_CSD support, some related option should be open, must open TCPIP_SUPPORT & CSD_SUPPORT.)
          DEPENDENCY_CONFLICT = TRUE
        endif
      else
        $(warning ERROR: When TCPIP_OVER_CSD support, some related option should be open, must open TCPIP_SUPPORT & CSD_SUPPORT.)
        DEPENDENCY_CONFLICT = TRUE
      endif
    else
      $(warning ERROR: When TCPIP_OVER_CSD support, some related option should be open, must open TCPIP_SUPPORT & CSD_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  else
    ifneq ($(filter __TCPIP_OVER_CSD__,$(COM_DEFS)),)
      $(warning ERROR: When TCPIP_OVER_CSD is not support, some related option should be closed.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  
  ifeq ($(strip $(PPP_SUPPORT)),NONE)
    PPP_DEPENDENCE_OPTION =__MULTIPLE_PPP_DIALUP_SUPPORT__ __TCPIP_OVER_CSD__ __EXT_MODEM__
    ifneq ($(filter $(PPP_DEPENDENCE_OPTION),$(COM_DEFS)),)
      $(call DEP_ERR_SETA_OR_ONB, MULTIPLE_PPP_DIALUP_SUPPORT, FALSE, PPP_SUPPORT)
      $(call DEP_ERR_SETA_OR_ONB, EXT_MODEM_SUPPORT, FALSE, PPP_SUPPORT)
      $(call DEP_ERR_SETA_OR_ONB, CSD_SUPPORT, NONE, PPP_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += PPP_NOT_PRESENT
  endif
else
  ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
    PS_DIALUP = TRUE
  else
    PS_DIALUP = FALSE
  endif
  ifeq ($(strip $(PS_DIALUP)),TRUE)
#    COM_DEFS += __PS_DIALUP__
  endif
endif

PPP_MODULE_BUILD=FALSE
ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
    PPP_MODULE_BUILD=TRUE
  else
    ifeq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_EGPRS_MODE)
      PPP_MODULE_BUILD=TRUE
    endif
  endif
endif

ifeq ($(strip $(PPP_MODULE_BUILD)),TRUE)
  ifndef PPP_SUPPORT
    ifeq ($(strip $(EUTRAN_MODE_SUPPORT)), EUTRAN_MODE)
      COM_DEFS += PPP_NOT_PRESENT
    endif
  else
     ifneq ($(strip $(PPP_SUPPORT)),NONE)
       ifeq ($(strip $(EUTRAN_MODE_SUPPORT)), EUTRAN_MODE)
         COM_DEFS += PPP_NOT_PRESENT
       endif
     endif
  endif
endif

#####################################################################
# End related rule of PPP_SUPPORT
#####################################################################

ifneq ($(filter __MTK_INTERNAL__,$(strip $(COM_DEFS))),)
  COM_DEFS    += __CATCHER_EVENT_INFO__
endif

ifneq ($(filter __UMTS_RAT__,$(strip $(COM_DEFS))),)
  COM_DEFS += __R6_OOS__
endif

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifndef LOW_COST_SUPPORT
    COM_DEFS += __STORED_CELL_SELECTION_INFO__
  endif
  ifeq ($(strip $(LOW_COST_SUPPORT)), NONE)
    COM_DEFS += __STORED_CELL_SELECTION_INFO__
  endif
  ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
    COM_DEFS += __STORED_CELL_SELECTION_INFO__
  endif
endif

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
    ifndef LOW_COST_SUPPORT
      COMPLIST       += scsi
    endif
    ifeq ($(strip $(LOW_COST_SUPPORT)), NONE)
      COMPLIST       += scsi
    endif
    ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
      COMPLIST       += scsi
    endif
  endif
endif

ifdef TST_SET_LOG_BUF_SIZ
  ifneq ($(strip $(TST_SET_LOG_BUF_SIZ)),NONE)
    ifeq ($(strip $(TST_SUPPORT)),TRUE)
      COM_DEFS += FORCE_TST_RING_BUFFER_SCALE=$(strip $(TST_SET_LOG_BUF_SIZ))
    else
      $(call DEP_ERR_ONA_OR_OFFB,TST_SUPPORT,TST_SET_LOG_BUF_SIZ)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef AT_COMMAND_SET
  ifeq ($(strip $(AT_COMMAND_SET)),SLIM)
#    ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
      $(call DEP_ERR_SETA_OR_SETB,MMI_VERSION,not EMPTY_MMI,AT_COMMAND_SET,FULL)
      DEPENDENCY_CONFLICT = TRUE
#    endif
    ifdef RSAT_SUPPORT
      ifneq ($(strip $(RSAT_SUPPORT)),NONE)
        $(call DEP_ERR_SETA_OR_SETB,RSAT_SUPPORT,NONE,AT_COMMAND_SET,FULL)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS    += __SLIM_AT__
  endif

  ifeq ($(strip $(AT_COMMAND_SET)),ULC)
#    ifeq ($(strip $(MMI_VERSION)),EMPTY_MMI)
      $(call DEP_ERR_SETA_OR_SETB,MMI_VERSION,not EMPTY_MMI,AT_COMMAND_SET,FULL)
      DEPENDENCY_CONFLICT = TRUE
#    endif
    ifdef RSAT_SUPPORT
      ifneq ($(strip $(RSAT_SUPPORT)),NONE)
        $(call DEP_ERR_SETA_OR_SETB,RSAT_SUPPORT,NONE,AT_COMMAND_SET,FULL)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    COM_DEFS    += __SLIM_AT__ __ULC_AT__
  endif
endif

ifeq ($(filter MS TC01 MTK MAC,$(strip $(USB_COMPORT_PC_DRIVER_SUPPORT))),)
  $(warning ERROR: USB_COMPORT_PC_DRIVER_SUPPORT must be defined as MS/TC01/MTK/MAC!)
  DEPENDENCY_CONFLICT = TRUE
endif

ifeq ($(strip $(USB_COMPORT_PC_DRIVER_SUPPORT)),TC01)
  ifeq ($(filter __TC01__,$(COM_DEFS)),)
    $(warning ERROR: USB_COMPORT_PC_DRIVER_SUPPORT can not be TC01 when __TC01__ not defined!)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __USB_COMPOSITE_REMOVE_IAD__
  COM_DEFS    += __USB_COMPORT_SUPPORT_TC01_DRIVER__
  COM_DEFS    += __USB_BOOT_NOT_CHECK_NVRAM_SETTING__
endif

ifeq ($(strip $(USB_COMPORT_PC_DRIVER_SUPPORT)),MAC)
  COM_DEFS    += __USB_COMPOSITE_REMOVE_IAD__
  COM_DEFS    += __USB_COMPORT_SUPPORT_MAC_DRIVER__
endif

ifeq ($(strip $(USB_COMPORT_PC_DRIVER_SUPPORT)),MTK)
  COM_DEFS    += __USB_COMPORT_SUPPORT_MTK_DRIVER__
endif

ifeq ($(strip $(CUST_CODE)),TC01)
  COM_DEFS += __ACOUSTIC_LOOPBACK_SUPPORT__
  COM_DEFS += __LATCH_POWER_IN_BOOTLOADER__
  COM_DEFS += __LATCH_POWER_IN_BOOTLOADER_TC01__
endif

COMP_TRACE_DEFS_MODEM    += driver/sys_drv/init/inc/system_trc.h

ifeq ($(strip $(PHB_SYNC)),ON)
  ifneq ($(strip $(USIM_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,USIM_SUPPORT,PHB_SYNC)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    +=   __PHB_USIM_SYNC__
endif

ifdef KAL_ASSERT_LEVEL
  ifeq ($(strip $(KAL_ASSERT_LEVEL)),KAL_ASSERT_LEVEL4)
    COM_DEFS += __KAL_ASSERT_LEVEL4__
  endif
  ifeq ($(strip $(KAL_ASSERT_LEVEL)),KAL_ASSERT_LEVEL3)
    COM_DEFS += __KAL_ASSERT_LEVEL3__
  endif
  ifeq ($(strip $(KAL_ASSERT_LEVEL)),KAL_ASSERT_LEVEL2)
    COM_DEFS += __KAL_ASSERT_LEVEL2__ __KAL_ASSERT_SHRINKING__
  endif
  ifeq ($(strip $(KAL_ASSERT_LEVEL)),KAL_ASSERT_LEVEL1)
    COM_DEFS += __KAL_ASSERT_LEVEL1__ __KAL_ASSERT_SHRINKING__
  endif
  ifeq ($(strip $(KAL_ASSERT_LEVEL)),KAL_ASSERT_LEVEL0)
    COM_DEFS += __KAL_ASSERT_LEVEL0__ __KAL_ASSERT_SHRINKING__
  endif
endif


ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
  COM_DEFS += __NEW_TBF_ARCH__
  COM_DEFS += __REMOVE_FA__
endif

COM_DEFS +=  __SW_MP4_LOSSY_SUPPORT__
COM_DEFS +=  __SW_H264_LOSSY_SUPPORT__

ifeq ($(strip $(USIM_SUPPORT)),TRUE)
  ifeq ($(call gt,$(strip $(PHB_SIM_ENTRY)),1000),T)
    $(warning ERROR: PHB_SIM_ENTRY value ($(PHB_SIM_ENTRY)) of USIM projects should not be larger than 1000)
    DEPENDENCY_CONFLICT = TRUE
  endif
else
  ifeq ($(call gt,$(strip $(PHB_SIM_ENTRY)),254),T)
    $(warning ERROR: PHB_SIM_ENTRY value ($(PHB_SIM_ENTRY)) of non USIM projects should not be larger than 254)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifneq ($(filter __L1_STANDALONE__,$(COM_DEFS)),)
    COM_DEFS  +=  DRV_LCD_NOT_EXIST 
endif

#ifneq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
#  COM_DEFS    += __RICH_AUDIO_PROFILE__
#endif

ifeq ($(strip $(ECC_RETRY_ENHANCEMENT)),TRUE)
  ifeq ($(filter __UMTS_RAT__,$(strip $(COM_DEFS))),)
    $(warning ERROR: ECC_RETRY_ENHANCEMENT can only be turned on when __UMTS_RAT__ defined)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(filter __GSM_RAT__,$(strip $(COM_DEFS))),)
    $(warning ERROR: ECC_RETRY_ENHANCEMENT can only be turned on when __GSM_RAT__ defined)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __ECC_RETRY_ENHANCEMENT__
endif

ifeq ($(strip $(HW_PFC_SUPPORT)),TRUE)
  COM_DEFS += __HW_PFC_SUPPORT__
endif

ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
COM_DEFS  += __TX_NEW_ARCHITECTURE__
endif

# Copro dependency check is valid only for FDD mode and non l1s project
ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
  ifneq ($(strip $(TEST_LOAD_TYPE)),L1S)
    ifeq ($(strip $(L2_HSDPA_COPRO)), TRUE)
      ifeq ($(call gt,$(strip $(GPRS_MAX_PDP_SUPPORT)),6),T)
        $(warning ERROR: GPRS_MAX_PDP_SUPPORT maximum value is 6 when HSDPA Copro exist due to hardware limitation, please reduce GPRS_MAX_PDP_SUPPORT value)
        DEPENDENCY_CONFLICT = TRUE 
      endif
      COM_DEFS        += __RLC_HSDPA_COPRO__ __MAC_HSDPA_COPRO__
      COMP_TRACE_DEFS_MODEM += $(strip $(UAS_FOLDER))/ul2/seq/include/seq_trc.h
    else
      ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,L2_HSDPA_COPRO,HSDPA_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif

    ifeq ($(strip $(L2_HSUPA_COPRO)), TRUE)
      ifneq ($(strip $(L2_HSDPA_COPRO)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,L2_HSDPA_COPRO,L2_HSUPA_COPRO)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(strip $(HSUPA_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,HSUPA_SUPPORT,L2_HSUPA_COPRO)
        DEPENDENCY_CONFLICT = TRUE
      endif
      ifneq ($(strip $(HSDPA_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,HSDPA_SUPPORT,L2_HSUPA_COPRO)
        DEPENDENCY_CONFLICT = TRUE
      endif
      COM_DEFS        += __L2_HSUPA_COPRO__
      COMP_TRACE_DEFS_MODEM += $(strip $(UAS_FOLDER))/ul2/seq/include/seq_trc.h
    else
      ifeq ($(strip $(HSUPA_SUPPORT)),TRUE)
        $(call DEP_ERR_ONA_OR_OFFB,L2_HSUPA_COPRO,HSUPA_SUPPORT)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifeq ($(strip $(TST_DNT_LOGGING)),TRUE)
  ifneq ($(strip $(TST_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,TST_SUPPORT,TST_DNT_LOGGING)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS    += __TST_DNT_LOGGING__ __TST_LMU_LOGGING__ __TST_DCC_ENABLED__
  endif
endif

ifneq ($(filter UNICORN53%,$(BOARD_VER)),)
  COM_DEFS    +=  __PHONE__
else
  ifneq ($(filter MT6921%,$(BOARD_VER)),)
     COM_DEFS    +=  __EVB__
  else
    ifneq ($(filter %_EVB,$(BOARD_VER)),)
      COM_DEFS    +=  __EVB__
    else  
      COM_DEFS    +=  __PHONE__
    endif
  endif
endif

ifdef AOC_SUPPORT
  ifeq ($(strip $(AOC_SUPPORT)),TRUE)
     COM_DEFS    += __AOC_SUPPORT__
  endif   
endif

ifeq ($(strip $(SML_SUPPORT)),TRUE)
  COM_DEFS += __SIM_ME_LOCK__
  ifdef TMO_SIM_LOCK
    ifeq ($(strip $(TMO_SIM_LOCK)),TRUE)
      COM_DEFS += __TMO_SIM_LOCK__
    endif
  endif
endif

ifeq ($(strip $(PHB_ADDITIONAL_SUPPORT)),TRUE)
  ifneq ($(strip $(USIM_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,USIM_SUPPORT,PHB_ADDITIONAL_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    +=   __PHB_USIM_ADDITIONAL_SUPPORT__
endif

ifdef MTK_SLEEP_ENABLE
  ifeq ($(strip $(MTK_SLEEP_ENABLE)),TRUE)
    COM_DEFS    += MTK_SLEEP_ENABLE
  else
    ifneq ($(strip $(DEMO_PROJECT)),TRUE)
      $(warning ERROR: MTK_SLEEP_ENABLE must be TRUE in all customer projects .)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(ICUSB_SUPPORT)),TRUE)
  COM_DEFS    +=   __ICUSB_SUPPORT__
endif
    
ifneq ($(filter __UMTS_RAT__,$(strip $(COM_DEFS))),)
  ifeq ($(strip $(FAST_DORMANCY_SUPPORT)),TRUE)
    COM_DEFS     += __FAST_DORMANCY__
    COM_DEFS     += __DIALUP_GPRS_COUNTER_SUPPORT__
  endif
  ifeq ($(strip $(FAST_DORMANCY_SUPPORT)),FALSE)
    COM_DEFS     += __NO_PSDATA_SEND_SCRI__
    COM_DEFS     += __DIALUP_GPRS_COUNTER_SUPPORT__
  endif
endif

ifeq ($(strip $(MOBILE_VIDEO_SUPPORT)),WONDER)

  ifneq ($(strip $(PGDL_SUPPORT)),TRUE)
    $(warning ERROR: Please turn on PGDL_SUPPORT when MOBILE_VIDEO_SUPPORT  defined! )
    DEPENDENCY_CONFLICT = TRUE
  endif

  COM_DEFS         += __MOBILE_VIDEO_SUPPORT__
  MMI_INCDIRS      += vendor/mobilevideo/adaption/mobilevideoinc
  COMPLIST         += mobilevideo
endif

ifeq ($(filter __TC02__,$(strip $(COM_DEFS))),)
  ifneq ($(filter __TC02_SECURITY_REQUIREMENT__,$(strip $(COM_DEFS))),)
    $(warning ERROR: __TC02_SECURITY_REQUIREMENT__ can only be turned on for MOTO project)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef SML_SUPPORT
  ifneq ($(strip $(SML_SUPPORT)),TRUE)
    ifneq ($(filter __TC02_SECURITY_REQUIREMENT__,$(strip $(COM_DEFS))),)
      $(warning ERROR: __TC02_SECURITY_REQUIREMENT__ need set SML_SUPPORT = TRUE)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef USB_TETHERING
  ifeq ($(strip $(USB_TETHERING)),TRUE)
    ifneq ($(strip $(DHCPD_SUPPORT)),TRUE)
      $(call DEP_ERR_ONA_OR_OFFB,DHCPD_SUPPORT,USB_TETHERING)
      DEPENDENCY_CONFLICT = TRUE
    endif

    ifeq ($(strip $(NDIS_SUPPORT)),UPS)
      $(call DEP_ERR_ONA_OR_OFFB,USB_TETHERING,NDIS_SUPPORT)
      DEPENDENCY_CONFLICT = TRUE
    endif
    
    ifeq ($(strip $(USB_HIGH_SPEED_COM_PORT_SUPPORT)),FALSE)
      $(call DEP_ERR_ONA_OR_OFFB,USB_HIGH_SPEED_COM_PORT_SUPPORT,USB_TETHERING)
      DEPENDENCY_CONFLICT = TRUE
    endif

    ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
      COM_DEFS    += __USB_TETHERING__ __UPS_SUPPORT__
      COMPLIST    += ups
      COMP_TRACE_DEFS_MODEM    += middleware/ups/rndis/include/rndis_trc.h
      COMP_TRACE_DEFS_MODEM    += driver/cmux/include/rndis_ctrl_trc.h
      ifeq ($(filter cmux,$(COMPLIST)),)
        COMPLIST    += cmux
      endif
    endif 
  endif
endif

ifdef MODIS_FDM
  ifeq ($(strip $(MODIS_FDM)),ON)
    COM_DEFS   += __FS_MODIS_FDM__ 
  endif
endif

COM_DEFS += __MP4_DEC_ASP_PARTIAL_SUPPORT__

ifdef COSMOS_3D_VERSION
  ifneq ($(strip $(COSMOS_3D_VERSION)),NONE)
    ifeq ($(filter __VENUS_3D_UI_ENGINE__,$(strip $(COM_DEFS))),)
      $(call DEP_ERR_SETA_OR_OFFB,VENUS_MMI,VENUS_3D,COSMOS_3D_VERSION)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef ZIMAGE_SUPPORT
  ifeq ($(strip $(ZIMAGE_SUPPORT)),TRUE)
    COM_DEFS   +=  __ZIMAGE_SUPPORT__
    COM_DEFS   +=  __VI_ENABLED__
  endif
endif

ifeq ($(strip $(ZIMAGE_AUTO_CONFIG)),TRUE)
   ifneq ($(strip $(ZIMAGE_SUPPORT)),TRUE)
      $(warning ERROR: PLEASE set ZIMAGE_SUPPORT=TRUE when ZIMAGE_AUTO_CONFIG=TRUE)
      DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifneq ($(filter __L4_INIT_MULTIUSB_COM__,$(COM_DEFS)),)
  ifeq ($(filter __USB_MULTIPLE_COMPORT_SUPPORT__,$(COM_DEFS)),)
    $(warning ERROR: __L4_INIT_MULTIUSB_COM__ can only be defined when __USB_MULTIPLE_COMPORT_SUPPORT__ is defined.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifndef PHB_FDN_ENTRY
     PHB_FDN_ENTRY = 32
endif

ifdef PHB_FDN_ENTRY
     COM_DEFS    += MAX_PHB_FDN_ENTRY=$(strip $(PHB_FDN_ENTRY))
endif

2G_TX_POWER_CONTROL_SUPPORT_PLATFORM = MT6575 MT6577 MT6280 MT6752 MT6572 MT6582 MT6290 MT6595 MT6795
ifneq ($(filter $(2G_TX_POWER_CONTROL_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
  COM_DEFS    +=  __2G_TX_POWER_CONTROL_SUPPORT__
endif

ifeq ($(strip $(2G_TX_VOLTAGE_COMPENSATION_SUPPORT)),TRUE)
  COM_DEFS    += __2G_TX_VOLTAGE_COMPENSATION_SUPPORT__
endif

# EMI latency setting, MPLLDISABLED, MPLLXHALF, MPLLX1, MPLLX2, MPLLX3, MPLLX4

MPLL_SETTING_FOR =  MPLL_SETTING_FOR_$(strip $(PLATFORM))_$(strip $(EXT_CLOCK))_$(strip $(MCU_CLOCK))

ifdef $(MPLL_SETTING_FOR)
  MPLL_SETTING      =  $(MPLL_SETTING_FOR_$(strip $(PLATFORM))_$(strip $(EXT_CLOCK))_$(strip $(MCU_CLOCK)))
endif
COM_DEFS    += $(MCU_CLOCK) $(EXT_CLOCK) $(MPLL_SETTING)

ifeq ($(strip $(MCU_DCM)),DCM_ENABLE)
   COM_DEFS    += DCM_ENABLE
endif

COMPLIST += che sst_sec

ifneq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
  COMPLIST += dsp_ram
endif

ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
  COMPLIST    +=  drv mc
endif

ifneq ($(strip $(SSS_SUPPORT)),SSS_LIB)
  ifneq ($(strip $(SSS_SUPPORT)),SSS_SOURCE)
    $(warning ERROR: Please define SSS_SUPPORT as SSS_LIB or SSS_SOURCE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef SSS_SUPPORT
  ifeq ($(strip $(SSS_SUPPORT)),SSS_SOURCE)
     COMPLIST         += sss
  endif
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R99_SUPPORT)
  COM_DEFS    +=   __R99__
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R4_SUPPORT)
  COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R5_SUPPORT)
    COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__ __GERAN_R5__ __REL5__ __USIM_SUPPORT__
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R6_SUPPORT)
    COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__ __GERAN_R5__ __REL5__ __GERAN_R6__  __REL6__ __USIM_SUPPORT__
    
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
       COM_DEFS    += __FDD_REDIRECTION__
    endif    
    
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
       COM_DEFS    += __CMCC_FR__
    endif
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R7_SUPPORT)
    COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__ __GERAN_R5__ __REL5__ __GERAN_R6__ __REL6__ __USIM_SUPPORT__ __NEW_TBF_ARCH__ __REMOVE_FA__ __MAC_NEW_ARCH__ __GERAN_R7__

    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
       COM_DEFS    += __FDD_REDIRECTION__
    endif    
    
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
       COM_DEFS    += __CMCC_FR__
    endif    
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R8_SUPPORT)
    COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__  __GERAN_R5__ __REL5__  __GERAN_R6__  __REL6__ __USIM_SUPPORT__ __NEW_TBF_ARCH__ __REMOVE_FA__ __MAC_NEW_ARCH__ __GERAN_R7__ __GERAN_R8__

    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
       COM_DEFS    += __FDD_REDIRECTION__
    endif    

    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
       COM_DEFS    += __CMCC_FR__
    endif        
endif

ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R9_SUPPORT)
    COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__  __GERAN_R5__ __REL5__  __GERAN_R6__  __REL6__ __USIM_SUPPORT__ __NEW_TBF_ARCH__ __REMOVE_FA__ __MAC_NEW_ARCH__ __GERAN_R7__ __GERAN_R8__ __GERAN_R9__

    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
       COM_DEFS    += __FDD_REDIRECTION__
    endif    
    
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
       COM_DEFS    += __CMCC_FR__
    endif        
endif

ifeq ($(strip $(EUTRAN_MODE_SUPPORT)),EUTRAN_MODE)
    COM_DEFS    +=   __REL4__ __REL5__ __REL6__ __REL7__ __REL8__ __CSG_SUPPORT__
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)    
    COM_DEFS    +=   __R6_NETWORK_SHARING__
    endif
endif

ifeq ($(strip $(EUTRAN_MODE_SUPPORT)),EUTRAN_MODE)
  ifneq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
    COM_DEFS += __ETWS_SUPPORT__ __EXT_SEG_CTRL_BLK__
  endif
endif

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R4_SUPPORT)
  COM_DEFS    +=   __UMTS_R4__ __REL4__
endif
ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R5_SUPPORT)
  COM_DEFS    +=  __UMTS_R4__ __UMTS_R5__ __REL4__ __REL5__
  ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
    COM_DEFS    +=   __HSDPA_SUPPORT__ __HSPA_PREFERENCE_SETTING__
    
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
      COM_DEFS    +=   FDD_HSDSCH_CATEGORY=$(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY))
    endif
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
      COM_DEFS    +=   TDD_HSDSCH_CATEGORY=$(strip $(TDD_HSDSCH_PHYSICAL_CATEGORY))
    endif
  endif
endif

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R6_SUPPORT)
  COM_DEFS    +=  __UMTS_R4__ __UMTS_R5__ __REL4__ __REL5__ __UMTS_R6__  __REL6__
  
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
     COM_DEFS    +=   __FDD_REDIRECTION__
  endif
  
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
     COM_DEFS    += __CMCC_FR__
  endif    
    
  ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
    COM_DEFS    +=   __HSDPA_SUPPORT__ __HSPA_PREFERENCE_SETTING__
    
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
      COM_DEFS    +=   FDD_HSDSCH_CATEGORY=$(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY))
    endif
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
      COM_DEFS    +=   TDD_HSDSCH_CATEGORY=$(strip $(TDD_HSDSCH_PHYSICAL_CATEGORY))
    endif
    
    ifeq ($(strip $(HSUPA_SUPPORT)),TRUE)
      COM_DEFS    +=   __HSUPA_SUPPORT__
      
      ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
        COM_DEFS    +=   FDD_EDCH_CATEGORY=$(strip $(FDD_EDCH_PHYSICAL_CATEGORY))
      endif
    endif
  endif
  ifeq ($(strip $(NOT_BENEFIT_FROM_BATTERY_CONSUMPTION_OPTIMISATION)),TRUE)
    COM_DEFS    +=   __NOT_BENEFIT_FROM_BATTERY_CONSUMPTION_OPTIMISATION__
  endif
endif

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R7_SUPPORT)
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
    COM_DEFS    +=   __UMTS_R4__ __UMTS_R5__ __REL4__ __REL5__ __UMTS_R6__  __REL6__ __UMTS_R7__  __REL7__ __FDD_REDIRECTION__
    ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
      COM_DEFS    +=   __HSDPA_SUPPORT__ __HSPA_PREFERENCE_SETTING__
      COM_DEFS    +=   FDD_HSDSCH_CATEGORY=$(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY))
      
      ifeq ($(strip $(R7_HSDPA_PLUS_SUPPORT)),TRUE)
        COM_DEFS    +=   __R7_HSDPA_PLUS_SUPPORT__ __MAC_EHS_SUPPORT__ __ENHANCED_COMMON_STATE_SUPPORT__
      endif
      
      ifeq ($(strip $(HSUPA_SUPPORT)),TRUE)
        COM_DEFS    +=   __HSUPA_SUPPORT__
        COM_DEFS    +=   FDD_EDCH_CATEGORY=$(strip $(FDD_EDCH_PHYSICAL_CATEGORY))
        
        ifeq ($(strip $(R7_HSUPA_PLUS_SUPPORT)),TRUE)
          COM_DEFS    +=   __R7_HSUPA_PLUS_SUPPORT__ __CPC_SUPPORT__
        endif
    
        ifeq ($(call gt,$(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY)),12),T)
          ifneq ($(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY)),15)
            ifneq ($(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY)),16)
                COM_DEFS    +=   __HOM_DL64QAM_SUPPORT__
            endif
          endif
        endif
    
        ifeq ($(call gt,$(strip $(FDD_EDCH_PHYSICAL_CATEGORY)),6),T)
            COM_DEFS    +=   __HOM_UL16QAM_SUPPORT__
        endif
      endif
    endif
    ifeq ($(strip $(R7R8_FULL_SET_SUPPORT)),TRUE)
      COM_DEFS    +=   __CUSTOMIZE_ENHANCED_COMMON_STATE_SUPPORT__ __CUSTOMIZE_CSHSPA_SUPPORT__ __CUSTOMIZE_HSSCCH_LESS_SUPPORT__ __CUSTOMIZE_UEA2_UIA2_SUPPORT__
      COM_DEFS    +=   __CUSTOMIZE_RFC2507_SUPPORT__
    endif
  endif
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
    COM_DEFS    +=   __UMTS_R4__ __UMTS_R5__ __REL4__ __REL5__ __UMTS_R6__  __REL6__ __UMTS_R7__ __CMCC_FR__
    ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
      COM_DEFS    +=   __HSDPA_SUPPORT__ __HSPA_PREFERENCE_SETTING__
      COM_DEFS    +=   TDD_HSDSCH_CATEGORY=$(strip $(TDD_HSDSCH_PHYSICAL_CATEGORY))
      ifeq ($(strip $(HSUPA_SUPPORT)),TRUE)
        COM_DEFS    +=   __HSUPA_SUPPORT__
        COM_DEFS    +=   TDD_EDCH_CATEGORY=$(strip $(TDD_EDCH_PHYSICAL_CATEGORY))
        ifeq ($(strip $(HSUPA_CAPABILITY_NOT_SUPPORT)),TRUE)
          COM_DEFS    +=   __HSUPA_CAPABILITY_NOT_SUPPORT__
        endif
      endif
    endif
  endif
endif

HSDSCH_HARQ_OFF_NOT_SUPPORT_PLATFORM = MT6280 MT6589 MT6572 MT6582
ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
  ifeq ($(filter $(HSDSCH_HARQ_OFF_NOT_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
    COM_DEFS    +=   __HSDSCH_HARQ_OFF__
  endif
endif

UMTS_MIPI_SUPPORT_PLATFORM = MT6290 MT6595 MT6752 MT6795
ifneq ($(filter $(UMTS_MIPI_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
  COM_DEFS    += __3G_MIPI_SUPPORT__
endif

UMTS_RX_PATH_SELECTION_NOT_SUPPORT_PLATFORM = MT6280 MT6589 MT6572 MT6582 MT6290 MT6595
ifeq ($(filter $(UMTS_RX_PATH_SELECTION_NOT_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
  COM_DEFS    +=   __3G_RX_PATH_SELECTION_SUPPORT__
endif

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R8_SUPPORT)
  COM_DEFS    +=  __UMTS_R4__ __UMTS_R5__ __REL4__ __REL5__ __UMTS_R6__ __REL6__ __UMTS_R7__ __REL7__ __UMTS_R8__ __REL8__  \
                  __HSDPA_2MS_DATA_IND__ __HSDPA_2MS_DATA_IND_LATENCY_IMPROVE__
  
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
    COM_DEFS    += __FDD_REDIRECTION__ __PPACR_SUPPORT__
  endif  
  
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
     COM_DEFS    += __CMCC_FR__   
  endif      
  
  ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
    COM_DEFS    +=   __HSDPA_SUPPORT__ __HSPA_PREFERENCE_SETTING__ __MAC_EHS_SUPPORT__ __ENHANCED_COMMON_STATE_SUPPORT__ __HSDSCH_DRX_CELL_FACH_SUPPORT__
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
      COM_DEFS    +=   FDD_HSDSCH_CATEGORY=$(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY))
    endif
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
      COM_DEFS    +=   TDD_HSDSCH_CATEGORY=$(strip $(TDD_HSDSCH_PHYSICAL_CATEGORY))
    endif
    
    ifeq ($(strip $(HSUPA_SUPPORT)),TRUE)
      COM_DEFS    +=   __HSUPA_SUPPORT__ __DCHSDPA_ADJ_FREQ_SUPPORT__ __CPC_SUPPORT__ __COMMON_EDCH_SUPPORT__ __MAC_IIS_SUPPORT__ __HSDSCH_CELL_CHANGE_ENHANCE_SUPPORT__
      
      ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)      
        COM_DEFS    +=   FDD_EDCH_CATEGORY=$(strip $(FDD_EDCH_PHYSICAL_CATEGORY))
      endif

      ifeq ($(call gt,$(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY)),12),T)
         ifneq ($(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY)),15)
            ifneq ($(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY)),16)
                 COM_DEFS    +=   __HOM_DL64QAM_SUPPORT__
            endif
         endif
      endif

      ifeq ($(call gt,$(strip $(FDD_EDCH_PHYSICAL_CATEGORY)),6),T)
           COM_DEFS    +=   __HOM_UL16QAM_SUPPORT__
      endif

    endif
  endif
  ifeq ($(strip $(NOT_BENEFIT_FROM_BATTERY_CONSUMPTION_OPTIMISATION)),TRUE)
    COM_DEFS    +=   __NOT_BENEFIT_FROM_BATTERY_CONSUMPTION_OPTIMISATION__
  endif
  ifeq ($(strip $(R7R8_FULL_SET_SUPPORT)),TRUE)
    COM_DEFS    +=   __CUSTOMIZE_ENHANCED_COMMON_STATE_SUPPORT__ __CUSTOMIZE_CSHSPA_SUPPORT__ __CUSTOMIZE_HSSCCH_LESS_SUPPORT__ __CUSTOMIZE_UEA2_UIA2_SUPPORT__
    COM_DEFS    +=   __CUSTOMIZE_MAC_IIS_SUPPORT__ __CUSTOMIZE_HSDSCH_DRX_CELL_FACH_SUPPORT__ __CUSTOMIZE_COMMON_EDCH_SUPPORT__ __CUSTOMIZE_HSDSCH_CELL_CHANGE_ENHANCE_SUPPORT__
    COM_DEFS    +=   __CUSTOMIZE_RFC2507_SUPPORT__
  endif
endif

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R9_SUPPORT)
  COM_DEFS    +=  __UMTS_R4__ __UMTS_R5__ __REL4__ __REL5__ __UMTS_R6__ __REL6__ __UMTS_R7__ __REL7__ __UMTS_R8__ __REL8__ __UMTS_R9__ __REL9__
  
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
    COM_DEFS     += __FDD_REDIRECTION__ __PPACR_SUPPORT__ __HSDPA_2MS_DATA_IND__ __HSDPA_2MS_DATA_IND_LATENCY_IMPROVE__
  endif   
  
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
     COM_DEFS    += __CMCC_FR__ __SIB19_DEFFER__
  endif      
  
  ifeq ($(strip $(HSDPA_SUPPORT)),TRUE)
    COM_DEFS    +=   __HSDPA_SUPPORT__ __HSPA_PREFERENCE_SETTING__   

    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
        COM_DEFS    +=   __MAC_EHS_SUPPORT__ __ENHANCED_COMMON_STATE_SUPPORT__ __HSDSCH_DRX_CELL_FACH_SUPPORT__
      COM_DEFS    +=   FDD_HSDSCH_CATEGORY=$(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY))
    endif
    ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
      COM_DEFS    +=   TDD_HSDSCH_CATEGORY=$(strip $(TDD_HSDSCH_PHYSICAL_CATEGORY))
    endif
    
    ifeq ($(strip $(HSUPA_SUPPORT)),TRUE)
      COM_DEFS    +=   __HSUPA_SUPPORT__
      
      ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
        COM_DEFS    +=    __DCHSDPA_ADJ_FREQ_SUPPORT__ __CPC_SUPPORT__ __COMMON_EDCH_SUPPORT__ __MAC_IIS_SUPPORT__ __HSDSCH_CELL_CHANGE_ENHANCE_SUPPORT__
        COM_DEFS    +=   FDD_EDCH_CATEGORY=$(strip $(FDD_EDCH_PHYSICAL_CATEGORY))
      

        ifeq ($(call gt,$(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY)),12),T)
           ifneq ($(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY)),15)
              ifneq ($(strip $(FDD_HSDSCH_PHYSICAL_CATEGORY)),16)
                   COM_DEFS    +=   __HOM_DL64QAM_SUPPORT__
              endif
           endif
        endif

        ifeq ($(call gt,$(strip $(FDD_EDCH_PHYSICAL_CATEGORY)),6),T)
             COM_DEFS    +=   __HOM_UL16QAM_SUPPORT__
        endif
      endif

      ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
        COM_DEFS    +=   TDD_EDCH_CATEGORY=$(strip $(TDD_EDCH_PHYSICAL_CATEGORY))
        ifeq ($(strip $(TDD_HSPA_PLUS_SUPPORT)),TRUE)
          COM_DEFS    +=   __ENHANCE_COMMON_STATE_SUPPORT__
          COM_DEFS    +=   __HSDSCH_DRX_CELL_FACH_SUPPORT__
          COM_DEFS    +=   __CPC_SUPPORT__
          COM_DEFS    +=   __COMMON_EDCH_SUPPORT__
          COM_DEFS    +=   __MAC_IIS_SUPPORT__
          COM_DEFS    +=   __MAC_ESH_SUPPORT__
          COM_DEFS    +=   __TDD128_HSPA_PLUS__
        endif
      endif
    endif
  endif
  ifeq ($(strip $(NOT_BENEFIT_FROM_BATTERY_CONSUMPTION_OPTIMISATION)),TRUE)
    COM_DEFS    +=   __NOT_BENEFIT_FROM_BATTERY_CONSUMPTION_OPTIMISATION__
  endif
  ifeq ($(strip $(R7R8_FULL_SET_SUPPORT)),TRUE)
    COM_DEFS    +=   __CUSTOMIZE_ENHANCED_COMMON_STATE_SUPPORT__ __CUSTOMIZE_CSHSPA_SUPPORT__ __CUSTOMIZE_HSSCCH_LESS_SUPPORT__ __CUSTOMIZE_UEA2_UIA2_SUPPORT__
    COM_DEFS    +=   __CUSTOMIZE_MAC_IIS_SUPPORT__ __CUSTOMIZE_HSDSCH_DRX_CELL_FACH_SUPPORT__ __CUSTOMIZE_COMMON_EDCH_SUPPORT__ __CUSTOMIZE_HSDSCH_CELL_CHANGE_ENHANCE_SUPPORT__
    COM_DEFS    +=   __CUSTOMIZE_RFC2507_SUPPORT__
  endif
endif

ifneq ($(filter __DYNAMIC_HSPA_PREFERENCE__,$(COM_DEFS)),)
  ifeq ($(filter __HSPA_PREFERENCE_SETTING__,$(strip $(COM_DEFS))),)
    $(error ERROR: PLEASE turn off __DYNAMIC_HSPA_PREFERENCE__ when __HSPA_PREFERENCE_SETTING__ is not defined.)
  endif
endif

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R5_SUPPORT)
  COM_DEFS    +=   __UMTS_R5__ __REL4__ __REL5__
endif

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R6_SUPPORT)
  COM_DEFS    +=   __UMTS_R5__ __REL4__ __REL5__ __UMTS_R6__  __REL6__ 
endif

ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
  ifeq ($(filter __UMTS_R6__,$(strip $(COM_DEFS))),)
    ifneq ($(filter __R6_DSAC__,$(strip $(COM_DEFS))),)
      $(error __R6_DSAC__ can only be turned on when __UMTS_R6__ defined)
    endif
  endif

  ifneq ($(filter __UMTS_R6__,$(strip $(COM_DEFS))),)
    ifeq ($(filter __R6_DSAC__,$(strip $(COM_DEFS))),)
      COM_DEFS += __R6_DSAC__
    endif
  endif
endif

ifneq ($(filter __REL7__,$(strip $(COM_DEFS))),)
  ifeq ($(filter __R7_EHPLMN__,$(strip $(COM_DEFS))),)
    COM_DEFS += __R7_EHPLMN__
  endif
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
    ifeq ($(filter __PLMN_LIST_WITH_LAC__,$(strip $(COM_DEFS))),)
      COM_DEFS += __PLMN_LIST_WITH_LAC__
    endif
  endif
endif


ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
  ifneq ($(filter __REL8__,$(strip $(COM_DEFS))),)
    ifeq ($(filter __ETWS_SUPPORT__,$(strip $(COM_DEFS))),)
      COM_DEFS += __ETWS_SUPPORT__ __EXT_SEG_CTRL_BLK__
    endif
  endif
endif

ifeq ($(filter __CPHS__,$(COM_DEFS)),)
  ifeq ($(filter __REL4__,$(COM_DEFS)),)
    ifneq ($(filter __SS_CPHS_QUERY_CFU_ALWAYS__,$(strip $(COM_DEFS))),)
      $(error ERROR: PLEASE turn on __CPHS__ or __REL4__ when __SS_CPHS_QUERY_CFU_ALWAYS__ is on)
    endif
  endif
endif

ifeq ($(strip $(LATENCY_REDUCTION)),TRUE)
  ifneq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R7_SUPPORT)
    ifneq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R8_SUPPORT)
      $(call DEP_ERR_SETA_OR_OFFB,GERAN_RELEASE_SUPPORT,GERAN_R7_SUPPORT,LATENCY_REDUCTION)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  COM_DEFS += __GERAN_RTTI__ __GERAN_FANR__
# Evelyn temp add for R7 feature detection
  COM_DEFS += __GERAN_EGPRS2__ __GERAN_RLC_PRESISTEN_MODE__ __GERAN_DLDC__
endif

#ifndef MMI_BASE
#  MMI_BASE = PLUTO_MMI
#  MMIDIR   = plutommi
#else
#  ifeq ($(strip $(MMI_BASE)),NEPTUNE_MMI)
#    MMIDIR         =  lcmmi
#  else
#    ifeq ($(strip $(MMI_BASE)), VENUS_MMI)
#      MMIDIR         =  plutommi
#    else
#      MMIDIR         =  plutommi
#    endif
#  endif
#endif

ifneq ($(filter __KTEST__,$(CUSTOM_OPTION)),)
  COMPLIST += ktest
endif

ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
  COMPLIST += cipher
endif

ifneq ($(filter DUAL_LCD,$(COM_DEFS)),)
  ifeq ($(strip $(SUB_LCD_SIZE)),NONE)
    ifneq ($(strip $(PLATFORM)),TK6516)
        $(warning ERROR: Please set SUB_LCD_SIZE when DUAL LCD (LCD_MODULE=$(strip $(LCD_MODULE))) is used)
        DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifdef CUST_CODE
  ifneq ($(strip $(CUST_CODE)),NONE)
    COM_DEFS += __$(strip $(CUST_CODE))__
  endif
  ifeq ($(strip $(CUST_CODE)),TC01)
    COM_DEFS += __RMMI_EXTEND_CUSTOM_CMD__ __AT_ME_IDENTIFICATION_WITHOUT_HEADER__
    COM_DEFS += __ATH_HANGUP_OTHER_SRC_CALL__
    ifneq ($(strip $(DRM_SUPPORT)),NONE)
      COM_DEFS += __LONG_AT_CMD_SUPPORT__
    endif
    ifdef TC01_ERS_LOCATION
      ifneq ($(strip $(TC01_ERS_LOCATION)),NONE)
        COM_DEFS += __TC01_ERS_SUPPORT__
      endif
    endif 
  endif
endif
    
ifdef TC01_ERS_LOCATION
  ifeq ($(strip $(TC01_ERS_LOCATION)),NVRAM)
    COM_DEFS += __TC01_ERS_NVRAM__
  endif
  ifeq ($(strip $(TC01_ERS_LOCATION)),BACKUP)
    ifndef SYSDRV_BACKUP_DISK_SUPPORT
      $(warning ERROR: PLEASE set SYSDRV_BACKUP_DISK_SUPPORT to be FAT or set TC01_ERS_LOCATION to be NVRAM)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(SYSDRV_BACKUP_DISK_SUPPORT)),FAT)
      $(warning ERROR: PLEASE set SYSDRV_BACKUP_DISK_SUPPORT to be FAT or set TC01_ERS_LOCATION to be NVRAM)
      DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS += __TC01_ERS_BACKUP__
  endif
endif

ifneq ($(filter __ACL_SUPPORT__,$(COM_DEFS)),)
  ifeq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
    $(warning ERROR:  __ACL_SUPPORT__ cannot be defined if __PS_SERVICE__ not defined)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef SDS_SUPPORT
  ifeq ($(strip $(SDS_SUPPORT)),TRUE)
    ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
      COM_DEFS += __SDS_DP_ENABLE__ __SECURE_DATA_STORAGE__ __SDS_NVRAM_SUPPORT__
    else    
      COM_DEFS += __SDS_DP_ENABLE__ __SECURE_DATA_STORAGE__ __NOR_FULL_DRIVER__ __SDS_NVRAM_SUPPORT__
    endif
  endif
endif

ifdef BOOT_CERT_SUPPORT
  ifeq ($(strip $(BOOT_CERT_SUPPORT)),BOOT_CERT_V1)
    COM_DEFS += __BOOT_CERT__ __BOOT_CERT_V1__
  endif
  ifeq ($(strip $(BOOT_CERT_SUPPORT)),BOOT_CERT_V2)
    COM_DEFS += __BOOT_CERT__ __BOOT_CERT_V2__
  endif
endif

MMA_MAX_NUM_VALUE = 2 3 4 5 6 7 8 9 10 11 12
ifdef MMA_MAX_NUM
  ifeq ($(filter $(strip $(MMA_MAX_NUM)),$(strip $(MMA_MAX_NUM_VALUE))),)
    $(warning ERROR: Please set MMA_MAX_NUM to 2-12.)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS += MMA_MAX_NUM=$(strip $(MMA_MAX_NUM))
  endif
else
  COM_DEFS += MMA_MAX_NUM=12
endif

ifdef PACKAGE_SEG
  ifneq ($(strip $(PACKAGE_SEG)), NONE)
    COM_DEFS    +=  __$(strip $(PACKAGE_SEG))__
  endif
endif

ifeq ($(strip $(PACKAGE_SEG)),16_3_SEG)
  ifneq ($(strip $(USB_DOWNLOAD_IN_BL)),NONE)
    $(warning ERROR: PACKAGE_SEG = 16_3_SEG only can be set when USB_DOWNLOAD_IN_BL = NONE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(SECURE_SUPPORT)),FALSE)
    $(warning ERROR: PACKAGE_SEG = 16_3_SEG only can be set when SECURE_SUPPORT = FALSE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(SW_BINDING_SUPPORT)),NONE)
    $(warning ERROR: PACKAGE_SEG = 16_3_SEG only can be set when SW_BINDING_SUPPORT = NONE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(DATA_CARD_SPEECH)),TRUE)
  DATA_CARD_SUPPORT_PLATFORM = MT6280 MT6290
  ifeq ($(filter $(strip $(PLATFORM)) ,$(DATA_CARD_SUPPORT_PLATFORM)),)
    $(warning ERROR: PLATFORM $(strip $(PLATFORM)) not support DATA_CARD_SPEECH.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(filter __MODEM_CARD__,$(COM_DEFS)),)
    $(warning ERROR: only __MODEM_CARD__ project support DATA_CARD_SPEECH.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    += __DATA_CARD_SPEECH__
endif

ifdef SIM_HOT_SWAP
  ifneq ($(strip $(SIM_HOT_SWAP)), NONE)
    COM_DEFS    +=  __SIM_HOT_SWAP_SUPPORT__
    ifneq ($(findstring SIM_SLOT_1,$(SIM_HOT_SWAP)),)
      COM_DEFS    +=  __SIM_HOT_SWAP_SLOT_1_SUPPORT__
    endif
    ifneq ($(findstring SIM_SLOT_2,$(SIM_HOT_SWAP)),)
      COM_DEFS    +=  __SIM_HOT_SWAP_SLOT_2_SUPPORT__
    endif
    ifneq ($(findstring SIM_SLOT_3,$(SIM_HOT_SWAP)),)
      COM_DEFS    +=  __SIM_HOT_SWAP_SLOT_3_SUPPORT__
    endif
    ifneq ($(findstring SIM_SLOT_4,$(SIM_HOT_SWAP)),)
      COM_DEFS    +=  __SIM_HOT_SWAP_SLOT_4_SUPPORT__
    endif
  endif
endif

ifeq ($(strip $(NAND_FLASH_BOOTING)),ONDEMAND)
  ifeq ($(strip $(DEMAND_PAGING_VERSION)),DPV2)
     COM_DEFS    += __DEMAND_PAGING_V2__
  endif
endif

# For smart phone settings.
#ifdef SMART_PHONE_CORE
#  ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
    include make/smart_phone_option.mak
#  endif
#endif

ifdef SMART_PHONE_CORE
  ifeq ($(strip $(SMART_PHONE_CORE)),ANDROID_MODEM)
    COM_DEFS += __CSCB_ALL_LANGUAGE_ON__
    ifeq ($(strip $(USIM_SUPPORT)),TRUE)
      COM_DEFS += __AT_EPBUM_SUPPORT__ __PHB_USIM_ADDITIONAL_SUPPORT__
    endif
  endif
endif

ifdef SMART_PHONE_CORE
  ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
    COM_DEFS += __ALLOW_SIM_REFRESH_RESET_WHEN_IN_CALL__
  endif
endif

# BASIC or UDVT projects do not need L1_TMD_FILES
ifeq ($(strip $(TEST_LOAD_TYPE)),BASIC)
  L1_TMD_FILES :=
endif
ifeq ($(strip $(TEST_LOAD_TYPE)),UDVT)
  L1_TMD_FILES :=
endif

ifdef PBCCH_SUPPORT
  ifeq ($(strip $(PBCCH_SUPPORT)),TRUE)
    COM_DEFS    +=    __RMP_PRESENT__
  endif
endif

ifdef LOW_COST_SUPPORT
  ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
    COM_DEFS += _L1_DISABLE_TRACE_LEVEL_=2
  endif
endif

ifdef LOW_COST_SUPPORT
  ifneq ($(strip $(LOW_COST_SUPPORT)),NONE)
    COM_DEFS += __SLIM_MODEM_EM_MODE__
  else
    COM_DEFS += __SLIM_MODEM_EM_MODE__ __MODEM_EM_MODE__
  endif
else
  COM_DEFS += __SLIM_MODEM_EM_MODE__ __MODEM_EM_MODE__
endif

ifeq ($(filter __EM_MODE__,$(CUSTOM_OPTION)),)
  COM_DEFS  := $(filter-out __SLIM_MODEM_EM_MODE__ __MODEM_EM_MODE__,$(COM_DEFS))
endif

ifneq ($(filter __UCM_SUPPORT__,$(COM_DEFS)),)
  COM_DEFS    += __FORCE_RELEASE__
endif

ifdef SIP_SERIAL_FLASH_SIZE
  ifneq ($(strip $(SIP_SERIAL_FLASH_SIZE)),NONE)
    ifneq ($(strip $(COMBO_MEMORY_SUPPORT)),TRUE)
      $(warning COMBO_MEMORY_SUPPORT must be TRUE when SIP_SERIAL_FLASH_SIZE is not NONE.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

COM_DEFS    += __CSMCC_CALLCONFIRM_TIMER__

ifdef CSD_SUPPORT
  ifneq ($(strip $(CSD_SUPPORT)),NONE)
    ifeq ($(strip $(AT_COMMAND_SET)),ULC)
       $(warning ERROR: PLease set AT_COMMAND_SET to SLIM or set CSD_SUPPORT  to NONE)
       DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

DSP_SOLUTION_SUPPORT_PLATFORM = MT6575 MT6577
ifneq ($(filter $(strip $(PLATFORM)) ,$(DSP_SOLUTION_SUPPORT_PLATFORM)),)
  ifneq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
    $(warning ERROR: DSP_SOLUTION must be DUALMACDSP,when PLATFORM is $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifneq ($(filter __CTP_SHIFT_FOR_HVGA_LCM__,$(strip $(COM_DEFS))),)
  ifeq ($(filter __MTK_INTERNAL__,$(strip $(COM_DEFS))),)
    $(warning ERROR: __CTP_SHIFT_FOR_HVGA_LCM__ is only available for VICTOR56V12 MTK internal project)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

#Rachel 20131125 add dependency for __4G_SW_DISABLE__
ifneq ($(filter __4G_SW_DISABLE__,$(strip $(COM_DEFS))),)
  ifeq ($(filter __MTK_INTERNAL__,$(strip $(COM_DEFS))),)
    $(warning ERROR: __4G_SW_DISABLE__ is only available for MTK internal project)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif 

ifeq ($(strip $(EMS_SUPPORT)),EMS_ULC_SLIM)
#  ifneq ($(strip $(MMI_VERSION)),COSMOS_MMI)
#  ifneq ($(strip $(MMI_VERSION)),PLUTO_MMI)
    $(warning ERROR: MMI_VERSION must be PLUTO_MMI/COSMOS_MMI,when EMS_SUPPORT is set to EMS_ULC_SLIM)
    DEPENDENCY_CONFLICT = TRUE
#  endif
#endif
endif

ifeq ($(strip $(ZIMAGE_SUPPORT)),TRUE)
  ifdef NAND_FLASH_BOOTING
    ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
      $(call DEP_ERR_OFFA_OR_OFFB,ZIMAGE_SUPPORT,NAND_FLASH_BOOTING)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  ifdef EMMC_BOOTING
    ifneq ($(strip $(EMMC_BOOTING)),NONE)
      $(call DEP_ERR_OFFA_OR_OFFB,ZIMAGE_SUPPORT,EMMC_BOOTING)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(MCU_DORMANT_MODE)),TRUE)
  COM_DEFS += __MCU_DORMANT_MODE__
endif

ifeq ($(strip $(SIM_RECOVERY_ENHANCEMENT)),TRUE)
  COM_DEFS    +=  __SIM_RECOVERY_ENHANCEMENT__
endif

ifeq ($(strip $(TDD_RF_CUSTOM_TOOL_SUPPORT)),TRUE)
  COM_DEFS    += __TDD_RF_CUSTOM_TOOL_SUPPORT__
  ifneq ($(strip $(L1_TDD128)),TRUE)
    $(warning ERROR: TDD_RF_CUSTOM_TOOL_SUPPORT can NOT be TRUE when L1_TDD128 is not TRUE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(MCU_DORMANT_MODE)),TRUE)
  ifeq ($(strip $(CENTRALIZED_SLEEP_MANAGER)),FALSE)
    $(call DEP_ERR_ONA_OR_OFFB,CENTRALIZED_SLEEP_MANAGER,MCU_DORMANT_MODE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(MTK_SLEEP_ENABLE)),FALSE)
    $(call DEP_ERR_ONA_OR_OFFB,MTK_SLEEP_ENABLE,MCU_DORMANT_MODE)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(USB_BOOTUP_TRACE)),TRUE)
  ifdef SMART_PHONE_CORE
    ifeq ($(filter NONE MODEM_ONLY,$(strip $(SMART_PHONE_CORE))),)
      $(warning ERROR: Smart Phone does not support USB_BOOTUP_TRACE!)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
  COM_DEFS += __USB_BOOTUP_TRACE__
endif

ifdef SIP_RAM_SIZE
  ifneq ($(strip $(SIP_RAM_SIZE)),NONE)
    COM_DEFS  += __SIP_RAM_SIZE__
  endif
endif

DCM_ENABLE_SUPPORT_PLATFORM = MT6280
ifneq ($(strip $(MCU_DCM)),DCM_ENABLE)
  ifneq ($(filter $(DCM_ENABLE_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
    $(warning ERROR: PLEASE set MCU_DCM as DCM_ENABLE on $(strip $(PLATFORM)) project)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# turn on the feature by default, except TDD, low cost, l1s, basic, udvt project
ifeq ($(strip $(PLMN_LIST_PREF_SUPPORT)),DEFAULT)
  ifneq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
    ifdef LOW_COST_SUPPORT
      ifeq ($(strip $(LOW_COST_SUPPORT)),NONE)
        ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
          COM_DEFS += __PLMN_LIST_PREF_SUPPORT__
        endif
      endif
    else
      ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
        COM_DEFS += __PLMN_LIST_PREF_SUPPORT__
      endif
    endif
  endif
endif

ifeq ($(strip $(3G_DATA_PLANE_MEMORY_SHRINK)),TRUE)
  COM_DEFS += __DL_MEMORY_SHRINK__ __UL_MEMORY_SHRINK__
endif

ifeq ($(strip $(3G_NEW_DATA_PLANE_ARCH)), TRUE)
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
    COM_DEFS +=   __3G_NEW_DATA_PLANE_ARCH__ __RATDM_UL_SHAQ__ __RATDM_SHAQ_HAS_PRIORITY_QUEUE__
  else
    COM_DEFS +=   __3G_NEW_DATA_PLANE_ARCH__ __RATDM_UL_SHAQ__ __RATDM_SHAQ_HAS_PRIORITY_QUEUE__ __CSHSPA_SUPPORT__
  endif
else
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
    COM_DEFS += __RATDM_UL_SHAQ__ __RATDM_SHAQ_HAS_PRIORITY_QUEUE__
  endif
endif

ifeq ($(strip $(UL2_HSPA_PLUS_RX_COPRO)), TRUE)
  ifneq ($(strip $(3G_NEW_DATA_PLANE_ARCH)),TRUE)
    $(warning ERROR: when UL2_HSPA_PLUS_RX_COPRO is set to TRUE , 3G_NEW_DATA_PLANE_ARCH must to be TRUE .)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(L2_HSDPA_COPRO)),TRUE)
    $(warning ERROR: when UL2_HSPA_PLUS_RX_COPRO is set to TRUE , L2_HSDPA_COPRO must to be TRUE .)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS        += __UL2_HSPA_PLUS_RX_COPRO__
endif

ifeq ($(strip $(UL2_HSPA_PLUS_TX_COPRO)), TRUE)
  ifneq ($(strip $(UL2_HSPA_PLUS_RX_COPRO)),TRUE)
    $(warning ERROR: when UL2_HSPA_PLUS_TX_COPRO is set to TRUE , UL2_HSPA_PLUS_RX_COPRO must to be TRUE .)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifneq ($(strip $(L2_HSUPA_COPRO)),TRUE)
    $(warning ERROR: when UL2_HSPA_PLUS_TX_COPRO is set to TRUE , L2_HSDPA_COPRO must to be TRUE .)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS        += __UL2_HSPA_PLUS_TX_COPRO__
endif

ifndef MAX_NUM_OF_PPP_DIALUP_SUPPORT
  ifeq ($(strip $(MULTIPLE_PPP_DIALUP_SUPPORT)),TRUE)
    $(warning ERROR: please set MULTIPLE_PPP_DIALUP_SUPPORT as FALSE on custom/internal project,otherwise there will be errors like:non-numeric second argument to 'wordlist' function.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifneq ($(filter __UMTS_TDD128_MODE__,$(strip $(COM_DEFS))),)
  ifneq ($(filter __R7_EHPLMN__,$(strip $(COM_DEFS))),)
    COM_DEFS += __SEARCH_ALL_EHPLMN_TOGETHER__
  endif
endif

ifeq ($(strip $(NVRAM_BIND_TO_CHIP_CIPHER)),ENABLE)
  ifeq ($(strip $(IC_TEST_TYPE)),IC_MODULE_TEST)
    $(warning ERROR: please enable NVRAM_BIND_TO_CHIP_CIPHER only when IC_TEST_TYPE is not set as IC_MODULE_TEST.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS    +=  __NVRAM_BIND_TO_CHIP_CIPHER__
endif

ifeq ($(strip $(3D_ANAGLYPH)),TRUE)
  COM_DEFS += __VIDEO_3D_ANAGLYPH__
endif

ifneq ($(filter MT6575 MT6577,$(PLATFORM)),)
  ifneq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
    $(warning ERROR: please set DSP_SOLUTION = DUALMACDSP, when PLATFORM = $(strip $(PLATFORM)).)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(call Upper,$(MTK_INTERNAL))),TRUE)
  COM_DEFS   += __FS_AUTO_CONFIG_SUPPORT__
endif

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
    COM_DEFS   += __FS_AUTO_CONFIG_SUPPORT__
  endif
endif

ifeq ($(strip $(GAMELOFT_CONTENT_SUPPORT)),TRUE)
  COM_DEFS     +=  __GAMELOFT_CONTENT_SUPPORT__
endif

ifeq ($(strip $(HD_RECORD_SUPPORT)),TRUE)
  COM_DEFS  +=  __HD_RECORD__
endif

ifeq ($(strip $(USB_TETHERING)),TRUE)
  ifdef USB_MULTIPLE_COMPORT_ENABLE
    ifneq ($(strip $(USB_MULTIPLE_COMPORT_ENABLE)),TRUE)
      $(warning ERROR: please turn on USB_MULTIPLE_COMPORT_ENABLE when USB_TETHERING = TRUE.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

2G_RF_CUSTOM_TOOL_SUPPORT_PLATFORM = MT6575 MT6577
ifeq ($(strip $(2G_RF_CUSTOM_TOOL_SUPPORT)),FALSE)
  ifneq ($(filter $(strip $(PLATFORM)),$(2G_RF_CUSTOM_TOOL_SUPPORT_PLATFORM)),)
    $(warning ERROR: 2G_RF_CUSTOM_TOOL_SUPPORT can NOT be FALSE when PLATFORM = $(strip $(PLATFORM)) .)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(NAND_SUPPORT)),TRUE)
  ifneq ($(filter __AST3001__,$(COM_DEFS)),)
    COM_DEFS  += __AST_L1_LOGGING_IN_LISR__
  endif
endif


ifeq ($(strip $(EXT_BL_UPDATE_SUPPORT)),TRUE)
  ifeq ($(strip $(USB_DOWNLOAD_IN_BL)),NONE)
    $(warning ERROR: USB_DOWNLOAD_IN_BL cannot be NONE when EXT_BL_UPDATE_SUPPORT = TRUE.)
    DEPENDENCY_CONFLICT = TRUE
  endif
    COM_DEFS  += __EXT_BL_UPDATE__
endif

ifeq ($(strip $(SDIO_DEVICE_CONNECTIVITY)),ENABLE)
  COM_DEFS += __SDIO_DEVICE_CONNECTIVITY__
  COMPLIST += sdio_device
  COMMINCDIRS    += interface/driver/connectivity/sdio_device
endif

CHK_UPPER_CASE = $(shell perl tools/chkUpperCase.pl "$(PROJECT_MAKEFILE)")
ifneq ($(strip $(CHK_UPPER_CASE)),)
  $(warning ERROR: $(strip $(CHK_UPPER_CASE)).)
  DEPENDENCY_CONFLICT = TRUE
endif

##############rule_2
ifneq ($(filter MT6575,$(PLATFORM)),)
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
    ifeq ($(filter MT6162_RF,$(strip $(COM_DEFS))),)
      $(warning ERROR: please define MT6162_RF when PLATFORM = MT6575 & UMTS_MODE_SUPPORT = UMTS_FDD_MODE_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
      $(warning ERROR: please set AFC_VCXO_TYPE as VCTCXO, when PLATFORM = MT6575 & UMTS_MODE_SUPPORT = UMTS_FDD_MODE_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif
##############rule_4
ifeq ($(strip $(PLATFORM)),MT6575)
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_TDD128_MODE_SUPPORT)
    ifeq ($(filter MT6140D_RF,$(strip $(COM_DEFS))),)
      $(warning ERROR: please define MT6140D_RF&MT6161_RF when PLATFORM = MT6575 & UMTS_MODE_SUPPORT = UMTS_TDD128_MODE_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(filter MT6161_RF,$(strip $(COM_DEFS))),)
      $(warning ERROR: please define MT6140D_RF&MT6161_RF when PLATFORM = MT6575 & UMTS_MODE_SUPPORT = UMTS_TDD128_MODE_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
      $(warning ERROR: please set AFC_VCXO_TYPE as VCTCXO, when PLATFORM = MT6575 & UMTS_MODE_SUPPORT = UMTS_TDD128_MODE_SUPPORT.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif
##############rule_6
ifeq ($(strip $(PLATFORM)),MT6575)
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),NONE)
    ifneq ($(filter MT6162_RF AD6548_RF MT6140D_RF,$(strip $(COM_DEFS))),)
      ifneq ($(filter AD6548_RF MT6140D_RF,$(strip $(COM_DEFS))),)
        ifneq ($(strip $(AFC_VCXO_TYPE)),VCXO)
          $(warning ERROR: please set AFC_VCXO_TYPE as VCXO, when PLATFORM = MT6575 & UMTS_MODE_SUPPORT = NONE & AD6548_RF/MT6140D_RF is defined.)
          DEPENDENCY_CONFLICT = TRUE
        endif
      else
        ifneq ($(strip $(AFC_VCXO_TYPE)),VCTCXO)
          $(warning ERROR: please set AFC_VCXO_TYPE as VCTCXO, when PLATFORM = MT6575 & UMTS_MODE_SUPPORT = NONE & MT6162_RF is defined.)
          DEPENDENCY_CONFLICT = TRUE
        endif
      endif
    else
      $(warning ERROR: please define MT6162_RF/AD6548_RF/MT6140D_RF, when PLATFORM = MT6575 & UMTS_MODE_SUPPORT = NONE .)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(WCDMA_PREFERRED)),TRUE)
  ifeq ($(strip $(UMTS_MODE_SUPPORT)),UMTS_FDD_MODE_SUPPORT)
    COM_DEFS        += __WCDMA_PREFERRED__
    COM_DEFS        += __UMTS_FDD_PREFER__
  endif
endif

ifeq ($(strip $(TST_MALMO_SUPPORT)),TRUE)
  ifneq ($(strip $(TST_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,TST_SUPPORT,TST_MALMO_SUPPORT)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS     += __TST_MALMO_SUPPORT__ __TST_ALC_SUPPORT__ __TST_ASM_SUPPORT__
  endif
endif

ifneq ($(filter __UMTS_TDD128_MODE__,$(strip $(COM_DEFS))),)
  COM_DEFS += __CMCC_STD_FR__
endif

ifndef VIRTUAL_PORTS_NUM
 VIRTUAL_PORTS_NUM         = 3
endif
ifdef VIRTUAL_PORTS_NUM
  COM_DEFS    += VIRTUAL_PORTS_NUM=$(strip $(VIRTUAL_PORTS_NUM))
endif

NVRAM_REDUCTION_NOT_SUPPORT_PLATFORM = MT6236
ifeq ($(filter $(strip $(PLATFORM)) ,$(NVRAM_REDUCTION_NOT_SUPPORT_PLATFORM)),)
   COM_DEFS    += __CAMERA_NVRAM_REDUCTION_ISP_SUPPORT__
   COM_DEFS    += __CAMERA_NVRAM_REDUCTION__
endif

ifdef SSDVT_TEST
  ifeq ($(strip $(SSDVT_TEST)),TRUE)
    COMPLIST     += ssdvt
    COM_DEFS     += __SSDVT_TEST__
  endif
endif

ifeq ($(strip $(FS_RAMDISK)),TRUE)
  COM_DEFS     += __FS_RAMDISK__
  COMPLIST += mtd
endif

ifdef MOBILE_BROADBAND
  ifeq ($(strip $(MOBILE_BROADBAND)),MBIM)
    ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
      COM_DEFS     += __MBIM_SUPPORT__ __NDIS_SUPPORT__
      ifneq ($(strip $(USB_MBIM_SUPPORT)),TRUE)
        ifeq ($(filter cmux,$(COMPLIST)),)
          COMPLIST     += cmux
        endif
        COM_DEFS     += __UPS_SUPPORT__
        COMPLIST     += ups
        COMP_TRACE_DEFS_MODEM   += middleware/ups/mbim/include/mbim_ctrl_trc.h
        COMP_TRACE_DEFS_MODEM   += middleware/ups/mbim/include/mbim_trc.h
      endif
      COMP_TRACE_DEFS_MODEM   += $(strip $(MODEM_FOLDER))/l4/mbci/include/mbci_trc.h
    endif
  endif
endif

COMPLIST += tdd_drv

ifneq ($(filter __UMTS_RAT__,$(strip $(COM_DEFS))),)
  COM_DEFS    +=  __SMART_PAGING_3G_FDD__
  ifeq ($(strip $(PLATFORM)),MT6280)
    COM_DEFS    +=  __SMART_PAGING_3G_FDD_OFF__
  endif
endif


32K_CRYSTAL_REMOVAL_SUPPORT_PLATFORM = MT6280 MT6290 
QUERY_32K_CRYSTAL_FROM_MD_PLATFORM = MT6280 MT6290
#QUERY_32K_CRYSTAL_FROM_AP_PLATFORM = 
ifdef 32K_XOSC_REMOVE
  ifeq ($(strip $(32K_XOSC_REMOVE)), TRUE)
    ifeq ($(filter $(32K_CRYSTAL_REMOVAL_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
      DEPENDENCY_CONFLICT = TRUE
      $(warning ERROR: 32K_XOSC_REMOVE only can be supported in $(32K_CRYSTAL_REMOVAL_SUPPORT_PLATFORM), $(PLATFORM) can not be supported)
    endif
  endif
endif
ifdef 32K_XOSC_REMOVE
  ifeq ($(strip $(32K_XOSC_REMOVE)), TRUE)
    COM_DEFS     +=  __F32_XOSC_REMOVAL_SUPPORT__
    ifneq ($(filter $(QUERY_32K_CRYSTAL_FROM_MD_PLATFORM), $(strip $(PLATFORM))),)
      COM_DEFS     +=  __QUERY_32K_CRYSTAL_FROM_MD__
    else
      ifneq ($(filter $(QUERY_32K_CRYSTAL_FROM_AP_PLATFORM), $(strip $(PLATFORM))),)
        COM_DEFS     +=  __QUERY_32K_CRYSTAL_FROM_AP__
      else 
        $(warning ERROR: MUST define query 32K crystal in MD or AP side )
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

DUAL_TALK_SUPPORT_PLATFORM = MT6752 MT6290 MT6595 MT6795
ifdef MDSYS
  ifeq ($(strip $(MDSYS)),MD1)
    COM_DEFS += __MD1__
    else
      ifeq ($(strip $(MDSYS)),MD2)
      COM_DEFS += __MD2__
    endif
  endif
endif

ifdef MDSYS
  ifneq ($(strip $(MDSYS)),NONE)
    ifeq ($(filter $(PLATFORM), $(strip $(DUAL_TALK_SUPPORT_PLATFORM))),)
      DEPENDENCY_CHECK = TRUE
      $(warning ERROR: MDSYS only can be set on $(DUAL_TALK_SUPPORT_PLATFORM).)
    endif
  endif
endif

COMBO_MEMORY_SUPPORT_PLATFORM = MT6280 MT6290
ifdef COMBO_MEMORY_SUPPORT
  ifeq ($(strip $(COMBO_MEMORY_SUPPORT)),TRUE)
    ifeq ($(filter $(PLATFORM), $(strip $(COMBO_MEMORY_SUPPORT_PLATFORM))),)
      $(warning ERROR: COMBO_MEMORY_SUPPORT = TRUE just can be supported on $(COMBO_MEMORY_SUPPORT_PLATFORM).)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif
ifdef COMBO_MEMORY_SUPPORT
  ifeq ($(strip $(COMBO_MEMORY_SUPPORT)),TRUE)
    COM_DEFS    += __COMBO_MEMORY_SUPPORT__
  endif
endif

ifdef GEMINI
 ifeq ($(strip $(GEMINI)),2)
    ifeq ($(strip $(GEMINI_VERSION)),V1)
      $(warning ERROR: Please set GEMINI_VERSION other than V1 when GEMINI = 2!)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

DHL_SUPPORT_PLATFORM = MT6290 MT6595  MT6752 MT6795
ifdef DHL_SUPPORT
 ifeq ($(strip $(DHL_SUPPORT)),TRUE)
    ifeq ($(filter $(PLATFORM), $(strip $(DHL_SUPPORT_PLATFORM))),)
      $(warning ERROR: DHL_SUPPORT can NOT be TRUE when PLATFORM = $(strip $(PLATFORM))!)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(DHL_DNT_LOGGING)),TRUE)
  ifneq ($(strip $(DHL_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,DHL_SUPPORT,DHL_DNT_LOGGING)
    DEPENDENCY_CONFLICT = TRUE
  else
    COM_DEFS    += __DHL_ADC_DCC_ENABLED__ __TST_DNT_LOGGING__
  endif
endif

ifeq ($(strip $(DHL_MALMO_SUPPORT)),TRUE)
  COM_DEFS     += __DHL_MALMO_SUPPORT__ __MALMO_ASM_SWTR__ 
else
  COM_DEFS     += DEBUG_SWLA
endif

# Non LTE single-mode
ifneq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
  ifneq ($(filter __REL7__,$(strip $(COM_DEFS))),)
    ifneq ($(filter __PS_SERVICE__,$(COM_DEFS)),)
      COM_DEFS    +=   __MEDIATEK_SMART_QOS__
    endif
  endif
endif

# LTE single-mode
ifeq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
  COM_DEFS += __LTE_SM__ __MULTI_BOOT__
endif


ifeq ($(strip $(NAND_FLASH_BOOTING_IS_NONE)),TRUE)
  ifeq ($(strip $(EMMC_BOOTING_IS_NONE)),TRUE)
    ifeq ($(strip $(SMART_PHONE_CORE)),NONE)
      COM_DEFS += __NOR_IDLE_SWEEP__
    endif
  endif
endif

# For NONE_FLASH_EXIST Setting
ifeq ($(strip $(NAND_SUPPORT)),FALSE)
  ifeq ($(strip $(SERIAL_FLASH_SUPPORT)),FALSE)
    COM_DEFS += __NONE_FLASH_EXIST__
  endif
endif


ifeq ($(strip $(GERAN_RELEASE_SUPPORT)),GERAN_R9_SUPPORT)
    COM_DEFS    +=   __R99__ __GERAN_R4__ __REL4__  __GERAN_R5__ __REL5__  __GERAN_R6__  __REL6__ __USIM_SUPPORT__ __NEW_TBF_ARCH__ __REMOVE_FA__ __MAC_NEW_ARCH__ __GERAN_R7__ __GERAN_R8__ __GERAN_R9__
endif

ifeq ($(strip $(ORIGINAL_FLAVOR)),SKYPA_R5)
    COM_DEFS    += __TDD_MODEM__  
endif

EDCH_HRT_IMPROVE_NOT_SUPPORT_PLATFORM = MT6280
ifeq ($(strip $(HSUPA_SUPPORT)),TRUE)
  ifeq ($(filter $(EDCH_HRT_IMPROVE_NOT_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
    COM_DEFS    +=   __EDCH_HRT_IMPROVE__
  endif
endif

ifeq ($(strip $(DUAL_EXT_BL)),TRUE)
  COM_DEFS += __DUAL_EXT_BL__
endif

ifeq ($(strip $(DUAL_LTE_DSP)),TRUE)
  COM_DEFS += __DUAL_LTE_DSP__
endif

ifeq ($(strip $(DUAL_PRIMARY_ROM)),TRUE)
  COM_DEFS += __DUAL_PRIMARY_ROM__
endif

ifdef L1_GPS_CO_CLOCK_SUPPORT 
  ifeq ($(strip $(L1_GPS_CO_CLOCK_SUPPORT)), TRUE)
    COM_DEFS += __L1_GPS_CO_CLOCK_SUPPORT__
  endif
endif

ifdef L1_LOCK_AFCDAC_AT_STARTUP_SUPPORT
  ifeq ($(strip $(L1_LOCK_AFCDAC_AT_STARTUP_SUPPORT)), TRUE)
    COM_DEFS += __L1_LOCK_AFCDAC_AT_STARTUP_SUPPORT__
  endif
endif

ifdef CCCI_FS_SUPPORT
  ifeq ($(strip $(CCCI_FS_SUPPORT)), TRUE)
    COM_DEFS += __CCCIFS_SUPPORT__
    COM_DEFS += __NVRAM_IMPORTANT_PARTITIONS__
  else
    COMPLIST += fs
  endif
else
  COMPLIST += fs
endif

ifdef MODEM_NFC_SUPPORT
  ifeq ($(strip $(MODEM_NFC_SUPPORT)),TRUE)
    ifneq ($(strip $(USIM_SUPPORT)),TRUE)
          $(call DEP_ERR_ONA_OR_OFFB,USIM_SUPPORT,MODEM_NFC_SUPPORT)
          DEPENDENCY_CONFLICT = TRUE
    endif
    COM_DEFS    +=  __CGLA__ __UICC_CHANNEL_SUPPORT__
  endif
endif

ifeq ($(strip $(HIF_USB_SUPPORT)),TRUE)
  ifeq ($(strip $(HIF_USB30_SUPPORT)),TRUE)
        COM_DEFS        += USB30_ENABLE
  endif
endif

ifdef RTOS
  ifeq ($(strip $(RTOS)),NUCLEUS)
    ifneq ($(strip $(PLATFORM)),MT6752)
    ifneq ($(strip $(MDSYS)),MD2)
      $(warning ERROR: Only allow RTOS = NUCLEUS, when PLATFORM = MT6752 and MDSYS = MD2. Otherwise, RTOS = NUCLEUS_V2.)
      DEPENDENCY_CONFLICT = TRUE
    endif
    endif
  endif
endif

ifeq ($(strip $(UNIFIED_ISR_LEVEL)),TRUE)
  COM_DEFS        += __UNIFIED_ISR_LEVEL__
endif

ifeq ($(strip $(BTT_AGENT_ENABLE)),TRUE)
  ifneq ($(strip $(DHL_SUPPORT)),TRUE)
    $(call DEP_ERR_ONA_OR_OFFB,DHL_SUPPORT,BTT_AGENT_ENABLE)
    DEPENDENCY_CONFLICT = TRUE
  else
    COMPLIST    += btt_agent
    COM_DEFS    += BTT_USE_DHL_VC __BTT_AGENT_ENABLE__
  endif
endif

ifeq ($(strip $(2G_BPI_PT3A_SUPPORT)),TRUE)
  COM_DEFS    += __2G_BPI_PT3A_SUPPORT__
endif

2G_TX_GAIN_RF_CALIBRATION = MT6165_2G_RF

ifneq ($(filter $(2G_TX_GAIN_RF_CALIBRATION),$(COM_DEFS_FOR_$(strip $(RF_MODULE)))),)
  COM_DEFS    += __2G_TX_GAIN_RF_CALIBRATION__
endif

ifneq ($(filter __23G_PRI_RESEL_SUPPORT__,$(COM_DEFS)),)
  COM_DEFS    +=  __PRI_RESEL_SUPPORT__
endif

ifdef GDB_STUB_SUPPORT
  ifeq ($(strip $(GDB_STUB_SUPPORT)),TRUE)
    COM_DEFS      += GDB_DEBUGGER=1
    COMMINCDIRS += driver/devdrv/gdb/inc
  endif
endif

ifneq ($(strip $(PMIC_INIT_TYPE)),)
  COM_DEFS += $(PMIC_INIT_TYPE)
endif

ifdef SGLTE_SUPPORT
  ifeq ($(strip $(SGLTE_SUPPORT)),TYPE2_SINGLE_LOAD)
    COM_DEFS    += __SGLTE__ __4G_BACKGROUND_SEARCH__ __CTA_DUAL_SIM_STANDARD__ __L4C_ROOT__
  endif
endif

ifeq ($(strip $(DUAL_SIM_HOT_SWAP_CO_DECK)),TRUE)
  ifeq ($(strip $(SIM_HOT_SWAP)),NONE)
    $(warning ERROR: DUAL_SIM_HOT_SWAP_CO_DECK only can be TRUE when SIM_HOT_SWAP != NONE)
    DEPENDENCY_CONFLICT = TRUE
  endif
  COM_DEFS += __DUAL_SIM_HOT_SWAP_CO_DECK_SUPPORT__
endif

ifeq ($(strip $(IMS_SUPPORT)),TRUE)
  COM_DEFS    += __IMS_SUPPORT__ __ISIM_SUPPORT__
  ifeq ($(strip $(VOLTE_SUPPORT)),TRUE)
    COM_DEFS    += __VOLTE_SUPPORT__
  endif
  ifeq ($(strip $(VOHSPA_SUPPORT)),TRUE)
    COM_DEFS    += __VOHSPA_SUPPORT__
  endif
endif

ifeq ($(strip $(UTRAN_MODE_SUPPORT)),UTRAN_TDD128_MODE)
  COM_DEFS += __DISABLE_2MIN_MINIMUM_HPPLMN_TIMER__ \
              __DYNAMIC_ROAMING_SUPPORT__ \
              __OP01__ \
              __R7_MANUAL_RHPLMN_SEL__ \
              __RESUME_GPRS_AFTER_LU_ABNORMAL__ \
              __REATTACH_AFTER_MT_DETACH_ABNORMAL_B__
endif

MD2_GGE_MIPI_NOT_SUPPORT_PLATFORM  = MT6752
ifneq ($(filter $(MD2_GGE_MIPI_NOT_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
  ifneq ($(filter $(MDSYS), MD2),)
    MD2_GGE_MIPI_NOT_SUPPORT = TRUE
  else
    MD2_GGE_MIPI_NOT_SUPPORT = FALSE
  endif
else
  MD2_GGE_MIPI_NOT_SUPPORT = FALSE
endif

GGE_MIPI_SUPPORT_PLATFORM = MT6290 MT6595 MT6752 MT6795
ifneq ($(strip $(call Upper,$(UE_SIMULATOR))),TRUE)
  ifneq ($(filter $(GGE_MIPI_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
    ifeq ($(strip $(MD2_GGE_MIPI_NOT_SUPPORT)),FALSE) 
      COM_DEFS    += __2G_MIPI_SUPPORT__
    endif
  endif
endif

# always turn on IVSR feature support
COM_DEFS    +=  __BT_SIM_PROFILE__

MULTI_RAT_AFC_TADC_SHARE_PLATFORM = MT6290 MT6595 MT6752 MT6795
ifneq ($(filter $(MULTI_RAT_AFC_TADC_SHARE_PLATFORM), $(strip $(PLATFORM))),)
  COM_DEFS    +=  __MULTI_RAT_AFC_TADC_SHARE_SUPPORT__
endif

ifdef EVDO_CT_SUPPORT
  ifeq ($(strip $(EVDO_CT_SUPPORT)),TRUE)
    COM_DEFS    +=  __REPORT_AVAILABLE_PLMN__
    COM_DEFS    +=  __2STAGE_NW_SELECTION__
    COM_DEFS    +=  __UE_EFOPLMN__
    COM_DEFS    +=  __MM_SEARCH_HPLMN_BEFORE_RPLMN__
    COM_DEFS    +=  __PERMANENT_AUTO_SEL_MODE__
  endif
endif

ifeq ($(strip $(DMA_EMI_TYPE_RESTRICT)),NON_CACHEABLE)
  COM_DEFS += __DMA_EMI_TYPE_NON_CACHEABLE__
endif

ifdef SGLTE_DSDS_SUPPORT
  ifeq ($(strip $(SGLTE_DSDS_SUPPORT)),TRUE)
    COM_DEFS    +=   __SGLTE_DSDS__
  endif
endif

ifeq ($(strip $(DUAL_TALK_RX_GAIN_TABLE_CO_BAND_SUPPORT)),TRUE)
  COM_DEFS    += __DUAL_TALK_RX_GAIN_TABLE_CO_BAND_SUPPORT__
endif

ifdef USB_FW_DL_SUPPORT
  ifeq ($(strip $(USB_FW_DL_SUPPORT)),TRUE)
    COM_DEFS += __USB_FW_DL_SUPPORT__
  endif
endif

ifeq ($(strip $(DCS_TX_NOTCH_SWITCH_SUPPORT)),TRUE)
  COM_DEFS    += __DCS_TX_NOTCH_SWITCH_SUPPORT__
endif

ifeq ($(strip $(CTA_ECC_SUPPORT)),TRUE)
    COM_DEFS    += __CTA_ECC_SUPPORT__
endif


ifeq ($(strip $(NEED_BUILD_MD_OFFLOAD_COPRO)),FALSE)
 ifneq ($(strip $(PLATFORM)),MT6752)
   COM_DEFS         += __FAST_FRC__
   COM_DEFS         += __STACK_ALIGN_MPU__=32
   COM_DEFS         += __THUMB2_UNIFIED__
 else
  ifneq ($(MDSYS),MD2)
   COM_DEFS         += __FAST_FRC__
   COM_DEFS         += __STACK_ALIGN_MPU__=32
   COM_DEFS         += __THUMB2_UNIFIED__
  endif
 endif
endif

ifeq ($(strip $(CSFB_WITH_SGLTE_HW_SUPPORT)),TRUE)
  COM_DEFS    += __CSFB_WITH_SGLTE_HW__
endif

ifeq ($(strip $(2G_MIPI_INTERSLOT_RAMPING_OPTIMIZE_SUPPORT)),TRUE)
  COM_DEFS    += __2G_MIPI_INTERSLOT_RAMPING_OPTIMIZE_SUPPORT__
endif

ifdef SET_IMEI_BY_PLMN
  ifeq ($(strip $(SET_IMEI_BY_PLMN)),TRUE)
    COM_DEFS    += __SET_IMEI_BY_PLMN__
  endif
endif

ifdef LTE_TX_PATH_SWITCH_SUPPORT
  ifeq ($(strip $(LTE_TX_PATH_SWITCH_SUPPORT)),TRUE)
    COM_DEFS += __LTE_TX_PATH_SWITCH_SUPPORT__
  endif
endif

ifeq ($(strip $(DUAL_MODEM_SUPPORT)),TRUE)
  COM_DEFS    += __DUAL_MODEM_SUPPORT__
endif

ifeq ($(strip $(TCM_ONLY_LOAD)),TRUE)
  COM_DEFS += __TCM_ONLY_LOAD__
endif

ifdef TX_POWER_OFFSET_SUPPORT
  ifeq ($(strip $(TX_POWER_OFFSET_SUPPORT)),TRUE)
    COM_DEFS += __TX_POWER_OFFSET_SUPPORT__
  endif
endif

ifdef DSP_IMG_ON_EMI
  ifeq ($(strip $(DSP_IMG_ON_EMI)),TRUE)
    ifneq ($(filter MT6752,$(PLATFORM)),)
      ifeq ($(strip $(MDSYS)),MD1)
        COM_DEFS += __DSP_IMG_ON_EMI__
      else
        $(warning ERROR: Can NOT set DSP_IMG_ON_EMI = TRUE on $(PLATFORM) $(MDSYS).)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifdef ROAMING_RETRY_FOR_CSFB
  ifeq ($(strip $(ROAMING_RETRY_FOR_CSFB)),TRUE)
    COM_DEFS    += __ROAMING_RETRY_FOR_CSFB__
  endif
endif

ifdef TAS_SUPPORT
  ifeq ($(strip $(TAS_SUPPORT)),TRUE)
    COM_DEFS    += __TAS_SUPPORT__
    ifeq ($(strip $(MTK_INTERNAL_NVRAM_VISIBLE)),TRUE)
      COM_DEFS += __TAS_INTERNAL_NVRAM_VISIBLE__
    endif
  endif
endif

ifneq ($(filter __TAS_INTERNAL_NVRAM_VISIBLE__,$(strip $(COM_DEFS))),)
  ifeq ($(filter __MTK_INTERNAL__,$(strip $(COM_DEFS))),)
    $(warning ERROR: __TAS_INTERNAL_NVRAM_VISIBLE__ is only available for MTK internal project)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

UMTS_MIPI_NVRAM_NOT_SUPPORT_PLATFORM = MT6280 MT6589 MT6572 MT6582 MT6290 MT6595 MT6752
ifneq ($(filter $(UMTS_MIPI_NVRAM_NOT_SUPPORT_PLATFORM), $(strip $(PLATFORM))),)
  ifneq ($(filter $(MT6795), $(strip $(PLATFORM))),)
      COM_DEFS    += __3G_MIPI_NVRAM_FULL_SUPPORT__
  endif
else
  COM_DEFS    += __3G_MIPI_NVRAM_FULL_SUPPORT__
endif

ifdef DHL_SET_LOG_BUF_SIZ
  ifneq ($(strip $(DHL_SET_LOG_BUF_SIZ)),NONE)
    ifeq ($(strip $(DHL_SUPPORT)),TRUE)
      COM_DEFS += FORCE_DHL_RING_BUFFER_SCALE=$(strip $(DHL_SET_LOG_BUF_SIZ))
    endif
  endif
endif

ifdef LTE_BPI_TIMING_DRDI_SUPPORT
  ifeq ($(strip $(LTE_BPI_TIMING_DRDI_SUPPORT)),TRUE)
    COM_DEFS += __LTE_BPI_TIMING_DRDI_SUPPORT__
  endif
endif

#####
# COMMON SECTION used by build.mak and custom_release.mak
#####

COMP_TRACE_DEFS = $(COMP_TRACE_DEFS_MODEM) $(COMP_TRACE_DEFS_FP)

# *************************************************************************
# Include extra dependency check.
# *************************************************************************
-include make/Extra_dep.mak

#ifneq ($(filter MODEM_PRODUCT MODEM_COMPONENT,$(strip $(SW_TYPE))),)
  # filter-out non_modem and mmi modules for modem product and modem component load.
  MMI_MODULES_MAK = $(shell $(LIST_DIR) "make/mmi/*.mak"  2>$(DEV_NUL))
  MMI_MODULES = $(MMI_MODULES_MAK:%.mak=%)

  NON_MODEM_BSP_MODULES_MAK = $(shell $(LIST_DIR) "make/bsp/non_modem/*.mak"  2>$(DEV_NUL))
  NON_MODEM_BSP_MODULES = $(NON_MODEM_BSP_MODULES_MAK:%.mak=%)
  
  COMPLIST := $(filter-out $(MMI_MODULES) $(NON_MODEM_BSP_MODULES),$(COMPLIST))
#else
#  # for FP projects ,$(MMI_INCDIRS) and $(BSP_AP_INCDIRS) must be included
#  COMMINCDIRS := $(COMMINCDIRS) $(MMI_INCDIRS) $(BSP_AP_INCDIRS)
#endif

# Generate CUS_REL_SRC_COMP/REL_MTK_COMP
CUS_REL_SRC_COMP_TEMP := $(filter $(REL_SRC_COMP),$(COMPLIST))
CUS_REL_SRC_COMP += $(CUS_REL_SRC_COMP_TEMP)

ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
  ifneq ($(filter bootloader,$(REL_SRC_COMP)),)
    CUS_REL_SRC_COMP += bootloader
  endif
  ifneq ($(filter bootloader_ext,$(REL_SRC_COMP)),)
    CUS_REL_SRC_COMP += bootloader_ext
  endif
endif

CUS_REL_MTK_COMP_TEMP := $(filter $(REL_MTK_COMP),$(COMPLIST))
CUS_REL_MTK_COMP += $(CUS_REL_MTK_COMP_TEMP)
#

ifeq ($(strip $(call Upper,$(LEVEL))),VENDOR)
  include make/REL_CR_VENDOR.mak
endif


# make sure AST_L1_TMD_FILES are located at the end of all L1_TMD_FILES
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
ifdef AST_SUPPORT
  ifneq ($(strip $(AST_SUPPORT)),NONE)
    AST_L1_TMD_FILES = CuStOm_StArT_AST \
                       $(strip $(MODEM_FOLDER))/tl1/ast_l1/l1trace/ast_l1_trace_isr_level_1.tmd \
                       $(strip $(MODEM_FOLDER))/tl1/ast_l1/l1trace/ast_l1_trace_isr_level_2.tmd \
                       $(strip $(MODEM_FOLDER))/tl1/ast_l1/l1trace/ast_l1_trace_isr_level_3.tmd \
                       $(strip $(MODEM_FOLDER))/tl1/ast_l1/l1trace/ast_l1_trace_isr_level_4.tmd \
                       $(strip $(MODEM_FOLDER))/tl1/ast_l1/l1trace/ast_l1_trace_task_level_1.tmd \
                       $(strip $(MODEM_FOLDER))/tl1/ast_l1/l1trace/ast_l1_trace_task_level_2.tmd \
                       $(strip $(MODEM_FOLDER))/tl1/ast_l1/l1trace/ast_l1_trace_task_level_3.tmd \
                       $(strip $(MODEM_FOLDER))/tl1/ast_l1/l1trace/ast_l1_trace_task_level_4.tmd \
                       CuStOm_EnD_AST

    L1_TMD_FILES += $(AST_L1_TMD_FILES)
  endif
endif
endif

#######################################################################
#COMPLIST Setting for bootloader
#######################################################################
BL_COMPLIST = che sst_sec

ifeq ($(strip $(SSS_SUPPORT)),SSS_SOURCE)
  ifeq ($(strip $(COMPILER)),RVCT)
    ifneq ($(filter $(strip $(SV5_PLATFORM)),$(PLATFORM)),)
      BL_COMPLIST += sss_rvct_sv5
    else
      BL_COMPLIST += sss_rvct_sv3
    endif
  else
    BL_COMPLIST += sss
  endif
endif

ifeq ($(strip $(SSS_SUPPORT)),SSS_LIB)
  ifeq ($(strip $(COMPILER)),RVCT)
    ifneq ($(filter $(strip $(SV5_PLATFORM)),$(PLATFORM)),)
      BL_COMPOBJS    += service/sss/lib/libsss_rvct_sv5.a
    else
      BL_COMPOBJS    += service/sss/lib/libsss_rvct_dummy.a
    endif
  else
   ifeq ($(strip $(COMPILER)),GCC)
     ifneq ($(filter $(strip $(PLATFORM)),$(SV5_PLATFORM) $(SV5X_PLATFORM)),)
       BL_COMPOBJS    += service/sss/lib/libsss_gcc_sv5.a
     else
       BL_COMPOBJS    += service/sss/lib/libsss_gcc_dummy.a
     endif
   else
     BL_COMPOBJS    += service/sss/lib/libsss.a
   endif
  endif
endif

# Remove the REMOVE_CUSTOM_OPTION specified in project makefile from COM_DEFS
COM_DEFS  := $(filter-out $(REMOVE_CUSTOM_OPTION),$(COM_DEFS))

CLEANROOM_COMP = j2me_11 j2me_hi sb51 sbpki2 sslplus5 bsci wndrv supc

###########################################
#temp add for module list
###########################################

ifeq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
#COMPLIST = che cmux config custom devdrv dhl ethercore event_info fdm fs hmu sys_drv ipcore kal l2_lte_copro l4 l4misc mcd mtkdebug nmu nucleus_v2 nucleus_v2_critical_data nucleus_v2_ctrl_code nucleus_v2_debug nucleus_v2_int nvram nvram_sec nwsel qmu_bm ratadp sim sst sst_sec sys_svc sys_svc_sec tft_pf upcm usbclass usbcore verno
#CUS_REL_SRC_COMP = cmux config custom event_info fs sys_drv kal l4 l4misc mtkdebug nvram sim sys_svc sys_svc_sec verno
#CUS_REL_MTK_COMP = che devdrv dhl ethercore fdm hmu ipcore l2_lte_copro mcd nmu nucleus_v2 nucleus_v2_critical_data nucleus_v2_ctrl_code nucleus_v2_debug nucleus_v2_int nvram_sec nwsel qmu_bm ratadp sst sst_sec tft_pf upcm usbclass usbcore
ifeq ($(LTE_SOURCE_BUILD),TRUE)
COMPLIST += $(LTE_SEC_COMP)
CUS_REL_MTK_COMP += $(LTE_SEC_COMP)
endif
endif

ifeq ($(strip $(ATEST_SYS_ENABLE)),TRUE)
include make/module/middleware/autotest/atest_sys.mak
endif

ifdef VARIATION_PROJ
ifneq ($(strip $(VARIATION_PROJ)),)
include make/variation/$(strip $(VARIATION_PROJ)).mak
CUS_REL_SRC_COMP_TEMP := $(filter $(REL_SRC_COMP) $(CUS_REL_SRC_COMP),$(COMPLIST))
CUS_REL_SRC_COMP := $(CUS_REL_SRC_COMP_TEMP)
CUS_REL_MTK_COMP_TEMP := $(filter $(REL_MTK_COMP) $(CUS_REL_MTK_COMP),$(COMPLIST))
CUS_REL_MTK_COMP := $(CUS_REL_MTK_COMP_TEMP)
endif
endif

# consistency check for COMPLIST & CUS_REL_XXX_COMP
# check each comp in $(COMPLIST) if it has been put in $(CUS_REL_XXX_COMP)
COMPLIST_NO_REL_TYPE_COMP = $(filter-out $(CUS_REL_SRC_COMP) $(CUS_REL_PAR_SRC_COMP) $(CUS_REL_HDR_COMP) $(CUS_REL_MTK_COMP),$(COMPLIST))
COMPLIST_NO_REL_TYPE_COMP := $(filter-out $(CLEANROOM_COMP),$(COMPLIST_NO_REL_TYPE_COMP))
ifneq ($(words $(COMPLIST_NO_REL_TYPE_COMP)),0)
  $(warning ERROR: $(foreach comp,$(COMPLIST_NO_REL_TYPE_COMP),"$(comp)") in COMPLIST but NOT in CUS_REL_XXX_COMP)
  DEPENDENCY_CONFLICT = TRUE
endif

# check each comp in $(CUS_REL_XXX_COMP) if it has been put in $(COMPLIST)
CREL_COMP_NOT_COMPLIST = $(filter-out $(COMPLIST),$(CUS_REL_SRC_COMP) $(CUS_REL_PAR_SRC_COMP) $(CUS_REL_HDR_COMP) $(CUS_REL_MTK_COMP))
CREL_COMP_NOT_COMPLIST := $(filter-out bootloader bootloader_ext,$(CREL_COMP_NOT_COMPLIST))
# CREL_COMP_NOT_COMPLIST := $(filter-out fota,$(CREL_COMP_NOT_COMPLIST))
ifneq ($(words $(CREL_COMP_NOT_COMPLIST)),0)
  $(warning ERROR: $(foreach comp,$(CREL_COMP_NOT_COMPLIST),"$(comp)") in CUS_REL_XXX_COMP but NOT in COMPLIST)
  DEPENDENCY_CONFLICT = TRUE
endif

# check no module define in $(CUS_REL_SRC_COMP) and $(CUS_REL_MTK_COMP) both
COMP_BOTH_IN_SRC_MTK = $(filter $(CUS_REL_SRC_COMP),$(CUS_REL_MTK_COMP))
ifneq ($(words $(COMP_BOTH_IN_SRC_MTK)),0)
  $(warning ERROR: $(foreach comp,$(COMP_BOTH_IN_SRC_MTK),"$(comp)") in CUS_REL_SRC_COMP but also in CUS_REL_MTK_COMP)
  DEPENDENCY_CONFLICT = TRUE
endif

# COMPLIST(during CUSTOM_RELEASE)      = CUS_REL_SRC_COMP + CUS_REL_PAR_SRC_COMP
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  COMPLIST =     $(strip $(CUS_REL_SRC_COMP))
  COMPLIST := $(filter-out bootloader bootloader_ext,$(COMPLIST))
endif

# check the COM_DEFS value
COM_DEFS_INVALID_LIST := TRUE FALSE ENABLE DISABLE FULL SLIM NONE
ifdef COM_DEFS
  COM_DEFS_INVALID_VALUE := $(filter $(strip $(COM_DEFS)),$(COM_DEFS_INVALID_LIST))
  ifneq ($(COM_DEFS_INVALID_VALUE),)
    $(warning ERROR: COM_DEFS value ($(strip $(COM_DEFS_INVALID_VALUE))) is NOT allowable, please do Not assign COM_DEFS value as : ($(strip $(COM_DEFS_INVALID_LIST)))) 
    DEPENDENCY_CONFLICT = TRUE 
  endif
endif

# L1_TMD_FILES check: the LTE security files can NOT be added to L1_TMD_FILES.
ifdef L1_TMD_FILES
L1_TMD_FILES_TEMP := $(filter modem/lte_sec/% ,$(L1_TMD_FILES))
  ifneq ($(strip $(L1_TMD_FILES_TEMP)),)
    $(warning ERROR: L1_TMD_FILES value $(foreach comp,$(L1_TMD_FILES_TEMP),"$(comp)") is NOT allowable,)
    $(warning ERROR: the LTE security files can NOT be added to L1_TMD_FILES.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# COMP_TRACE_DEFS_MODEM check: the LTE security files can NOT be added to COMP_TRACE_DEFS_MODEM
ifdef COMP_TRACE_DEFS_MODEM
COMP_TRACE_DEFS_MODEM_TEMP := $(filter modem/lte_sec/% ,$(COMP_TRACE_DEFS_MODEM))
  ifneq ($(strip $(COMP_TRACE_DEFS_MODEM_TEMP)),)
    $(warning ERROR: COMP_TRACE_DEFS_MODEM value $(foreach comp,$(COMP_TRACE_DEFS_MODEM_TEMP),"$(comp)") is NOT allowable,)
    $(warning ERROR: the LTE security files can NOT be added to COMP_TRACE_DEFS_MODEM.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# L1_TMD_FILES_LTE_SEC check: only the LTE security files can be added.
ifdef L1_TMD_FILES_LTE_SEC
L1_TMD_FILES_LTE_SEC_TEMP := $(filter-out modem/lte_sec/% ,$(L1_TMD_FILES_LTE_SEC))
  ifneq ($(strip $(L1_TMD_FILES_LTE_SEC_TEMP)),)
    $(warning ERROR: L1_TMD_FILES_LTE_SEC value $(foreach comp,$(L1_TMD_FILES_LTE_SEC_TEMP),"$(comp)") is NOT allowable,)
    $(warning ERROR: only the LTE security files can be added to L1_TMD_FILES_LTE_SEC.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# COMP_TRACE_DEFS_MODEM_LTE_SEC check: only the LTE security files can be added.
ifdef COMP_TRACE_DEFS_MODEM_LTE_SEC
COMP_TRACE_DEFS_MODEM_LTE_SEC_TEMP := $(filter-out modem/lte_sec/% ,$(COMP_TRACE_DEFS_MODEM_LTE_SEC))
  ifneq ($(strip $(COMP_TRACE_DEFS_MODEM_LTE_SEC_TEMP)),)
    $(warning ERROR: COMP_TRACE_DEFS_MODEM_LTE_SEC value $(foreach comp,$(COMP_TRACE_DEFS_MODEM_LTE_SEC_TEMP),"$(comp)") is NOT allowable,)
    $(warning ERROR: only the LTE security files can be added to COMP_TRACE_DEFS_MODEM_LTE_SEC.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  ifneq ($(strip $(FLAVOR)), $(strip $(ORIGINAL_FLAVOR)))
   $(warning ERROR: ORIGINAL_FLAVOR value should be $(FLAVOR))
   DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  ifneq ($(strip $(PROJECT_NAME)), $(strip $(ORIGINAL_PROJECT_NAME)))
   $(warning ERROR: ORIGINAL_PROJECT_NAME value should be $(PROJECT_NAME))
   DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef DEPENDENCY_CONFLICT
  ifeq ($(strip $(DEPENDENCY_CONFLICT)),TRUE)
    $(error PLEASE check above dependency errors!)
  endif
endif

ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
  RELEASE_LEVEL = NONE_RELEASE
endif

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
    RELEASE_LEVEL = SUB_RELEASE
  endif
endif

#rule for copy_br_bin
BR_FLAVOR := DEFAULT
BR_FILE   := cmdScript.bin
ifneq ($(strip $(CHIP_VER)),S00)
  BR_FLAVOR := $(CHIP_VER)
endif
ifneq ($(filter __FPGA__,$(strip $(COM_DEFS))),)
  BR_FLAVOR := FPGA
endif
ifneq ($(strip $(X_BOOTING)),NONE)
  BR_FILE   := xboot.bin 
endif
