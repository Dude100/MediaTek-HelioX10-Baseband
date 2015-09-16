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

#  Define include path lists to XGEN_INC_DIR
#XGEN_INC_DIR = $(COMMINCDIRS)


ifneq ($(strip $(L1_UMTS)),TRUE)
  XGEN_INC_DIR +=   $(strip $(GAS_FOLDER))/common/include \
                    $(strip $(GAS_FOLDER))/rrm/common/include \
                    $(strip $(GAS_FOLDER))/rrm/rmc/include \
                    $(strip $(GAS_FOLDER))/rrm/rcs/include \
                    $(strip $(GAS_FOLDER))/lapdm/include \
                    $(strip $(GAS_FOLDER))/mpal/include \
                    $(strip $(GAS_FOLDER))/rlc/include \
                    $(strip $(GAS_FOLDER))/mac/include \
                    $(strip $(GAS_FOLDER))/rrm/rmp/include \
                    $(strip $(MODEM_FOLDER))/nas/mm/cmm/include \
                    $(strip $(MODEM_FOLDER))/nas/mm/common/include \
                    $(strip $(MODEM_FOLDER))/nas/mm/pmm/include \
                    $(strip $(MODEM_FOLDER))/nas/ratcm/include \
                    $(strip $(MODEM_FOLDER))/nas/ratdm/include \
                    $(strip $(MODEM_FOLDER))/common/scsi/gen/include \
                    $(strip $(MODEM_FOLDER))/common/scsi/include \
                    $(strip $(MODEM_FOLDER))/interface/l1/inner \
                    service/fsm/include
 ifdef GEMINI
    ifneq ($(strip $(GEMINI)),FALSE)
      XGEN_INC_DIR += $(strip $(MODEM_FOLDER))/common/rsva/rsvas/include \
                        $(strip $(MODEM_FOLDER))/common/rsva/interface/enum \
                        $(strip $(MODEM_FOLDER))/common/rsva/interface/local_inc \
                        $(strip $(MODEM_FOLDER))/common/rsva/common/include

    endif
  endif
else
  ifneq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
    GAS_INC_SUPPORT = TRUE
  else
    ifeq ($(filter BASIC,$(TEST_LOAD_TYPE)),)
      GAS_INC_SUPPORT = TRUE
    endif
  endif
  ifeq ($(strip $(GAS_INC_SUPPORT)),TRUE)
      XGEN_INC_DIR += $(strip $(GAS_FOLDER))/common/include \
                      $(strip $(GAS_FOLDER))/rrm/common/include \
                      $(strip $(GAS_FOLDER))/rrm/rmc/include \
                      $(strip $(GAS_FOLDER))/rrm/rcs/include \
                      $(strip $(GAS_FOLDER))/lapdm/include \
                      $(strip $(GAS_FOLDER))/mpal/include \
                      $(strip $(GAS_FOLDER))/rlc/include \
                      $(strip $(GAS_FOLDER))/mac/include \
                      $(strip $(GAS_FOLDER))/rrm/rmp/include \
                      $(strip $(MODEM_FOLDER))/nas/mm/cmm/include \
                      $(strip $(MODEM_FOLDER))/nas/mm/common/include \
                      $(strip $(MODEM_FOLDER))/nas/mm/pmm/include \
                      $(strip $(MODEM_FOLDER))/nas/ratcm/include \
                      $(strip $(MODEM_FOLDER))/nas/ratdm/include \
                      $(strip $(MODEM_FOLDER))/common/scsi/gen/include \
                      $(strip $(MODEM_FOLDER))/common/scsi/include \
                      $(strip $(UAS_FOLDER))/interface/include \
                      $(strip $(UAS_FOLDER))/asn1/gen/include \
                      $(strip $(UAS_FOLDER))/common/include \
                      $(strip $(UAS_FOLDER))/interface/enum \
                      $(strip $(UAS_FOLDER))/interface/local_inc \
                      $(strip $(UAS_FOLDER))/ul2/common/include \
                      $(strip $(UAS_FOLDER))/ul2/bmc/include \
                      $(strip $(UAS_FOLDER))/ul2/csr/include \
                      $(strip $(UAS_FOLDER))/ul2/pdcp/include \
                      $(strip $(UAS_FOLDER))/ul2/rabm/include \
                      $(strip $(UAS_FOLDER))/ul2/umac/include \
                      $(strip $(UAS_FOLDER))/ul2/urlc/include \
                      $(strip $(UAS_FOLDER))/ul2/seq/include \
                      $(strip $(UAS_FOLDER))/urr/common/include \
                      $(strip $(UAS_FOLDER))/urr/meme/include \
                      $(strip $(UAS_FOLDER))/urr/rrce/include \
                      $(strip $(UAS_FOLDER))/urr/slce/include \
                      $(strip $(UAS_FOLDER))/urr/dbme/include \
                      $(strip $(UAS_FOLDER))/urr/cise/include \
                      service/fsm/include \
                      driver/bytecopy/inc \
                      interface/modem/l1/fdd/internal \
                      interface/modem/l1/gsm/internal \
                      service/event_info
      ifdef GEMINI
        ifneq ($(strip $(GEMINI)),FALSE)
          XGEN_INC_DIR += $(strip $(MODEM_FOLDER))/common/rsva/rsvas/include \
                          $(strip $(MODEM_FOLDER))/common/rsva/interface/enum \
                          $(strip $(MODEM_FOLDER))/common/rsva/interface/local_inc \
                          $(strip $(MODEM_FOLDER))/common/rsva/common/include \
                          $(strip $(MODEM_FOLDER))/common/rsva/rsvak/include \
                          $(strip $(MODEM_FOLDER))/common/rsva/rsvau/include \
                          $(strip $(MODEM_FOLDER))/common/rsva/rsvae/include \
                          $(strip $(MODEM_FOLDER))/common/rsva/rsvag/include  
        endif
      endif
      XGEN_INC_DIR += interface/uas
  endif
endif

ifeq ($(strip $(L1_UMTS)),TRUE)
  XGEN_INC_DIR += $(strip $(MODEM_FOLDER))/nas/sndcp/include \
                  $(strip $(MODEM_FOLDER))/nas/sm/include \
                  $(strip $(MODEM_FOLDER))/nas/llc/include
else
  ifeq ($(strip $(GERAN_MODE_SUPPORT)),GERAN_EGPRS_MODE)
    ifeq ($(strip $(UTRAN_MODE_SUPPORT)),NONE)
      XGEN_INC_DIR +=   $(strip $(MODEM_FOLDER))/nas/sndcp/include \
                        $(strip $(MODEM_FOLDER))/nas/sm/include \
                        $(strip $(MODEM_FOLDER))/nas/llc/include
    endif
  endif
endif

XGEN_INC_DIR    += $(strip $(MODEM_FOLDER))/common/config/include \
                   $(strip $(MODEM_FOLDER))/nas/cc-ss/cc/include \
                   $(strip $(MODEM_FOLDER))/nas/sms/include \
                   $(strip $(PPP_FOLDER))/include \
                   $(strip $(MODEM_FOLDER))/nas/data/include \
                   $(strip $(MODEM_FOLDER))/nas/data/l2r/include \
                   $(strip $(MODEM_FOLDER))/nas/data/rlp/include \
                   $(strip $(MODEM_FOLDER))/nas/data/tdt/include \
                   $(strip $(MODEM_FOLDER))/nas/data/t30/include \
                   $(strip $(MODEM_FOLDER))/nas/data/fa/include \
                   $(strip $(MODEM_FOLDER))/common/mcd/include \
                   $(strip $(MODEM_FOLDER))/ircomm/include \
                   $(strip $(MODEM_FOLDER))/gl1/l1_dm/common \
                   $(strip $(MODEM_FOLDER))/interface/l1/gsm \
                   $(strip $(MODEM_FOLDER))/interface/l1/inner \
                   $(strip $(MODEM_FOLDER))/interface/l1/fdd \
                   $(strip $(MODEM_FOLDER))/interface/l1/tdd \
                   $(strip $(MODEM_FOLDER))/interface/l4 \
                   $(strip $(MODEM_FOLDER))/interface/l4misc \
                   $(strip $(MODEM_FOLDER))/interface/general \
                   $(strip $(MODEM_FOLDER))/interface/asn/rr/include \
                   $(strip $(MODEM_FOLDER))/nwsel/include \
                   $(strip $(MODEM_FOLDER))/l4/include \
                   $(strip $(MODEM_FOLDER))/l4/csm \
                   $(strip $(MODEM_FOLDER))/l4/csm/cc/include \
                   $(strip $(MODEM_FOLDER))/l4/smu/include \
                   $(strip $(MODEM_FOLDER))/l4/smsal/include \
                   $(strip $(MODEM_FOLDER))/l4/tcm/common \
                   $(strip $(MODEM_FOLDER))/l4/rac/common/include \
                   $(strip $(MODEM_FOLDER))/l4/rac/ugrac/include \
                   $(strip $(MODEM_FOLDER))/interface/mcd/include \
                   $(strip $(MODEM_FOLDER))/l4/tcm/ugtcm \
                   $(strip $(MODEM_FOLDER))/l4/tcm/etcm/include \
                   $(strip $(MODEM_FOLDER))/l4/tcm/rat_tcm/inc \
                   $(strip $(MODEM_FOLDER))/l4/psdm/include \
                   $(strip $(MODEM_FOLDER))/ephy/ephy_rf \
                   $(strip $(MODEM_FOLDER))/sim/include \
                   service/sst/include \
                   service/kal/common/include \
                   service/kal/mlib/include \
                   middleware/interfaces/local_inc \
                   middleware/media/audio/include \
                   middleware/media/common/include \
                   interface/modem/l1/fdd/internal \
                   interface/modem/l1/gsm/internal
              
ifneq ($(strip $(EUTRAN_MODE_SUPPORT)),NONE)
  XGEN_INC_DIR    += $(strip $(MODEM_FOLDER))/l4/rac/erac/include
endif
     
ifdef RFC2507_SUPPORT
  ifeq ($(strip $(RFC2507_SUPPORT)),TRUE)
    XGEN_INC_DIR    += $(strip $(UAS_FOLDER))/ul2/rfc2507/include
  endif
endif

ifdef AGPS_SUPPORT
  ifneq ($(strip $(AGPS_SUPPORT)), NONE)
    ifeq ($(strip $(AGPS_SUPPORT)), USER_PLANE)
      XGEN_INC_DIR     += inet_ps/supl/include
      XGEN_INC_DIR     += $(strip $(MODEM_FOLDER))/agps/rrlp/include
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), CP_AGPS)
      XGEN_INC_DIR     += $(strip $(MODEM_FOLDER))/agps/rrlp/include
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), CP_AGPS_AGLONASS)
      XGEN_INC_DIR     += $(strip $(MODEM_FOLDER))/agps/rrlp/include
    endif        
    ifeq ($(strip $(AGPS_SUPPORT)), BOTH)
      XGEN_INC_DIR     += inet_ps/supl/include
      XGEN_INC_DIR     += $(strip $(MODEM_FOLDER))/agps/rrlp/include
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), CONTROL_PLANE)
      XGEN_INC_DIR     += $(strip $(MODEM_FOLDER))/agps/rrlp/include
    endif
  endif
endif


ifdef USB_TETHERING
  ifeq ($(strip $(USB_TETHERING)),TRUE)
    XGEN_INC_DIR    += middleware/ups/rndis/include
  endif
endif

ifdef NDIS_SUPPORT
  ifeq ($(strip $(NDIS_SUPPORT)),UPS)
    XGEN_INC_DIR    += middleware/ups/ups/include
  endif
endif



ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
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
  ifeq ($(strip $(IRDA_SUPPORT)),TRUE)
    FLC_LIB_INCLUDE_CONDITION = TRUE
  endif
  ifneq ($(strip $(TCPIP_SUPPORT)),NONE)
    FLC_LIB_INCLUDE_CONDITION = TRUE
  endif
  ifeq ($(strip $(FLC_LIB_INCLUDE_CONDITION)),TRUE)
    XGEN_INC_DIR += $(strip $(FLC_FOLDER))/include
  endif
endif


ifdef GEMINI
  ifneq ($(strip $(GEMINI)),FALSE)
    XGEN_INC_DIR += $(strip $(MODEM_FOLDER))/common/as_semaphore_utility/include
  endif
endif

XGEN_INC_DIR +=  $(strip $(MODEM_FOLDER))/common/mcddll/include
XGEN_INC_DIR +=  $(strip $(MODEM_FOLDER))/l4/dt/include
XGEN_INC_DIR +=  inet_ps/ems/include $(strip $(MODEM_FOLDER))/nas/cc-ss/ss/include

ifdef DT_SUPPORT
  ifneq ($(strip $(DT_SUPPORT)),FALSE)
    ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
      XGEN_INC_DIR       += $(strip $(MODEM_FOLDER))/l4/dt/include
    endif
  endif
endif

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  XGEN_INC_DIR += inet_ps/ems/include
endif

XGEN_INC_DIR    +=  external_mmi/wise/bal/telephony/include \
                    $(strip $(MODEM_FOLDER))/interface/asn/asn1lib/include \
                    $(strip $(MODEM_FOLDER))/gl1/l1_dm/common 

ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
  ifneq ($(filter __MTK_3G_MRAT_ARCH__,$(strip $(COM_DEFS))),)
    XGEN_INC_DIR += $(strip $(GAS_FOLDER))/mpal/include
  endif
endif

ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
  XGEN_INC_DIR += $(strip $(MODEM_FOLDER))/interface/l1/l1s
endif

ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
  XGEN_INC_DIR += $(strip $(MODEM_FOLDER))/ul1/ul1_hs/ul1c \
                  $(strip $(MODEM_FOLDER))/ul1/ul1_hs/ul1d \
                  $(strip $(MODEM_FOLDER))/ul1/ul1_hs/common \
                  $(strip $(MODEM_FOLDER))/md_sm/ul1sm \
                  $(strip $(MODEM_FOLDER))/md_sm/common\ul1sm
else ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLUS_PLATFORM)),)
  XGEN_INC_DIR += $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1c \
                  $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d \
                  $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/common \
                  $(strip $(MODEM_FOLDER))/md_sm/ul1sm \
                  $(strip $(MODEM_FOLDER))/md_sm/common\ul1sm
endif

ifdef AGPS_SUPPORT
    ifeq ($(strip $(AGPS_SUPPORT)), CP_AGPS)
      XGEN_INC_DIR    +=  $(strip $(MODEM_FOLDER))/agps/ulcs/common/include
      XGEN_INC_DIR    +=  $(strip $(MODEM_FOLDER))/agps/ulcs/uagps_up/include
      XGEN_INC_DIR    +=  $(strip $(MODEM_FOLDER))/agps/ulcs/uagps_cp/include 
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), CP_AGPS_AGLONASS)
      XGEN_INC_DIR    +=  $(strip $(MODEM_FOLDER))/agps/ulcs/common/include
      XGEN_INC_DIR    +=  $(strip $(MODEM_FOLDER))/agps/ulcs/uagps_up/include
      XGEN_INC_DIR    +=  $(strip $(MODEM_FOLDER))/agps/ulcs/uagps_cp/include 
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), CONTROL_PLANE)
      XGEN_INC_DIR    +=  $(strip $(MODEM_FOLDER))/agps/ulcs/common/include
      XGEN_INC_DIR    +=  $(strip $(MODEM_FOLDER))/agps/ulcs/uagps_up/include
      XGEN_INC_DIR    +=  $(strip $(MODEM_FOLDER))/agps/ulcs/uagps_cp/include 
    endif
    ifeq ($(strip $(AGPS_SUPPORT)), BOTH)
      XGEN_INC_DIR    +=  $(strip $(MODEM_FOLDER))/agps/ulcs/common/include
      XGEN_INC_DIR    +=  $(strip $(MODEM_FOLDER))/agps/ulcs/uagps_up/include
      XGEN_INC_DIR    +=  $(strip $(MODEM_FOLDER))/agps/ulcs/uagps_cp/include 
    endif
endif

ifneq ($(strip $(LPP_SUPPORT)), NONE)
  XGEN_INC_DIR += $(strip $(MODEM_FOLDER))/agps/lpp/include 
endif

XGEN_INC_DIR += interface/ul1interface/internal 

ifeq ($(strip $(IMS_SUPPORT)),TRUE)
    XGEN_INC_DIR +=$(strip $(MODEM_FOLDER))/interface/ims
endif

ifeq ($(strip $(L2_HSDPA_COPRO)), TRUE)
  ifeq ($(call gt,$(strip $(GPRS_MAX_PDP_SUPPORT)),6),T)
  else
    XGEN_INC_DIR     += $(strip $(UAS_FOLDER))/ul2/seq/include
  endif
endif

ifeq ($(strip $(L2_HSUPA_COPRO)), TRUE)
  ifneq ($(strip $(L2_HSDPA_COPRO)),TRUE)
  else
    XGEN_INC_DIR     += $(strip $(UAS_FOLDER))/ul2/seq/include
  endif
endif

XGEN_INC_DIR += $(strip $(MODEM_FOLDER))/smt/l1s/dummyps/include/internal

ifeq ($(LTE_SOURCE_BUILD),TRUE)
  XGEN_INC_DIR += interface/driver/l2copro
endif

ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
  XGEN_INC_DIR += dummyups/include/internal
endif

XGEN_INC_DIR += $(strip $(TSTDIR))/local_inc
XGEN_INC_DIR += $(strip $(MODEM_FOLDER))/md_sm/l1sm \
                $(strip $(MODEM_FOLDER))/md_sm/common/l1sm \
                service/sys_svc_sec/inc \
                driver/sleep_drv/internal/inc \
                driver/sleep_drv/public/inc \
                $(strip $(PROJDIR))/modem/eas_asn

ifeq ($(LTE_SOURCE_BUILD),TRUE)
  XGEN_INC_DIR += $(strip $(TSTDIR_SEC))/database/gv \
                  $(strip $(TSTDIR_SEC))/database/unionTag \
                  $(BUILD_TSTDIR_SEC)/database/unionTag

  XGEN_INC_DIR += modem/lte_sec/interface/etmr
  XGEN_INC_DIR += modem/lte_sec/enas/interface
  XGEN_INC_DIR += modem/lte_sec/errc/interface \
                  modem/lte_sec/errc/common/include
endif
XGEN_INC_DIR += $(strip $(TSTDIR))/database/gv \
                $(strip $(TSTDIR))/database/unionTag \
                $(strip $(TSTDIR))/database \
                $(BUILD_TSTDIR)/database/unionTag
XGEN_INC_DIR += service/fs/common/include
XGEN_INC_DIR += driver/sys_drv/cache/inc

XGEN_INC_DIR += interface/service/flc2
XGEN_INC_DIR += interface/modem/secured
XGEN_INC_DIR += $(strip $(MODEM_FOLDER))/ephy/common

ifdef CMUX_SUPPORT
  ifeq ($(strip $(CMUX_SUPPORT)),TRUE)
    ifeq ($(filter L1S BASIC UDVT,$(TEST_LOAD_TYPE)),)
      # move from Option.mak
      XGEN_INC_DIR += driver/cmux/include
    endif
  endif
endif

ifeq ($(strip $(RTOS)),NUCLEUS)
  XGEN_INC_DIR +=  service/nucleus_v2/inc
endif
  

ifeq ($(strip $(IMS_SUPPORT)),TRUE)
  XGEN_INC_DIR +=  $(strip $(MODEM_FOLDER))/imc/frmk/pub \
                   $(strip $(MODEM_FOLDER))/imc/pub \
                   $(strip $(MODEM_FOLDER))/imc/sap \
                   $(strip $(MODEM_FOLDER))/vdm/interface \
                   $(strip $(MODEM_FOLDER))/vdm/common/include \
                   $(strip $(MODEM_FOLDER))/vdm/trk/include \
                   $(strip $(MODEM_FOLDER))/vdm/ads/include \
                   $(strip $(MODEM_FOLDER))/vdm/vcc/include \
                   $(strip $(MODEM_FOLDER))/sdm/include \
                   $(strip $(MODEM_FOLDER))/imc/imcsms/include
endif
  
XGEN_INC_DIR_TARGET := $(XGEN_INC_DIR)

ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  ifeq ($(LTE_SOURCE_BUILD),TRUE)
    XGEN_INC_DIR += $(strip $(TSTDIR_SEC))/database_modis/gv \
                    $(strip $(TSTDIR_SEC))/database_modis/unionTag \
                    $(BUILD_TSTDIR_SEC)/database_modis/unionTag
  endif
  XGEN_INC_DIR += $(strip $(TSTDIR))/database_modis/gv \
                  $(strip $(TSTDIR))/database_modis/unionTag \
                  $(BUILD_TSTDIR)/database_modis/unionTag
  XGEN_INC_DIR += $(strip $(MODEM_FOLDER))/nas/ratdm/include 
  XGEN_INC_DIR := $(MODISPROJDIR)/_BUILD_XGEN/modem/eas_asn \
                  $(XGEN_INC_DIR)
endif

