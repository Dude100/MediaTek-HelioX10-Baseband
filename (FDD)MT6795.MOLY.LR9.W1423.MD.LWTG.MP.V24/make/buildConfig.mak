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
SHELL:=/bin/bash

# *************************************************************************
# Build path, directories
# *************************************************************************
FIXPATH        =  .
BUILDDIR       =  $(strip $(FIXPATH))/build
RELDIR         =  $(strip $(FIXPATH))/mtk_rel

COPRODIR      =  md_copro
COPRO_PROJDIR =  $(strip $(BUILDDIR))/$(strip $(PROJECT_NAME))/$(strip $(FLAVOR))/$(strip $(COPRODIR))
COPRO_TARGDIR =  $(strip $(COPRO_PROJDIR))/bin
COPRO_SYSDIR  =  $(strip $(COPRO_PROJDIR))/custom/system

ifeq ($(strip $(NEED_BUILD_MD_OFFLOAD_COPRO)),TRUE)
  PROJDIR        =  $(strip $(COPRO_PROJDIR))
  CUS_MTK_REL    =  $(strip $(RELDIR))/$(strip $(ORIGINAL_PROJECT_NAME))/$(strip $(ORIGINAL_FLAVOR))/$(COPRODIR)
else
  PROJDIR        =  $(strip $(BUILDDIR))/$(strip $(PROJECT_NAME))/$(strip $(FLAVOR))
  CUS_MTK_REL    =  $(strip $(RELDIR))/$(strip $(ORIGINAL_PROJECT_NAME))/$(strip $(ORIGINAL_FLAVOR))
endif
PROJ_INTERNAL_DIR := $(subst build/,build_internal/,$(PROJDIR))

include $(strip $(PROJDIR))/Custom.bld

TARGDIR        =  $(strip $(PROJDIR))/bin
TMPDIR         =  $(strip $(PROJDIR))/tmp
CUSTPACKDIR    =  $(strip $(PROJDIR))/custpack
BUILD_RELDIR   =  $(strip $(PROJDIR))/rel

OBJSDIR        =  $(strip $(TARGDIR))/obj
RULESDIR       =  $(strip $(TARGDIR))/dep
COMPLIBDIR     =  $(strip $(TARGDIR))/lib
COMPLOGDIR     =  $(strip $(TARGDIR))/log
MODULEINFODIR  =  $(strip $(TARGDIR))/module

CUS_MTK_LIB    = $(strip $(CUS_MTK_REL))/lib

GEN_L4DIR      =  $(strip $(BUILD_RELDIR))/L4
GEN_MMIDIR     =  $(strip $(BUILD_RELDIR))/BASIC
REL_L4DIR      =  $(strip $(CUS_MTK_REL))/L4
REL_MMIDIR     =  $(strip $(CUS_MTK_REL))/BASIC

GEN_MCDDIR      =  $(strip $(PROJDIR))/modem/mcd
GEN_SCSIDIR     =  $(strip $(PROJDIR))/modem/scsi
REL_MCDDIR      =  $(strip $(CUS_MTK_REL))/modem/mcd
REL_SCSIDIR     =  $(strip $(CUS_MTK_REL))/modem/scsi

BUILD_L4DIR    =  $(strip $(GEN_L4DIR))
BUILD_MMIDIR   =  $(strip $(GEN_MMIDIR))
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  BUILD_L4DIR    =  $(strip $(REL_L4DIR))
  BUILD_MMIDIR   =  $(strip $(REL_MMIDIR))
  ifneq ($(findstring _PROTOCOL, $(RELEASE_PACKAGE)),)
    BUILD_L4DIR    =  $(strip $(GEN_L4DIR))
    BUILD_MMIDIR   =  $(strip $(GEN_MMIDIR))
  else ifneq ($(findstring _L4, $(RELEASE_PACKAGE)),)
    BUILD_MMIDIR   =  $(strip $(GEN_MMIDIR))
  endif
  ifneq ($(RELEASE_PACKAGE_SUB_PS),)
  ifneq ($(wildcard make/rel/sub_ps/$(strip $(RELEASE_PACKAGE_SUB_PS)).mak),)
    BUILD_L4DIR    =  $(strip $(GEN_L4DIR))
  endif
  endif
endif

GEN_SSDIR = $(strip $(PROJDIR))/rel/L4/csm/ss
REL_SSDIR = $(strip $(CUS_MTK_REL))/L4/csm/ss
BUILD_SSDIR = $(strip $(GEN_SSDIR))
ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  BUILD_SSDIR = $(strip $(REL_SSDIR))
endif

TARGNAME       =  $(strip $(PROJECT_NAME))_MDBIN_$(strip $(SUB_BOARD_VER))_$(strip $(PLATFORM))_$(strip $(CHIP_VER))
#PLATLIBROOT    =  $(strip $(FIXPATH))\lib\$(strip $(PLATFORM))

ifeq ($(strip $(DHL_SUPPORT)),TRUE)
TSTDIR         =  $(strip $(FIXPATH))/service/dhl
TSTDIR_SEC =  $(strip $(FIXPATH))/modem/lte_sec/dhl
BUILD_TSTDIR         := $(strip $(PROJDIR))/dhl
BUILD_TSTDIR_SEC := $(strip $(PROJDIR))/dhl/lte_sec
else
TSTDIR         =  $(strip $(FIXPATH))/service/tst
BUILD_TSTDIR := $(strip $(PROJDIR))/tst
endif
TST_DB         =  $(strip $(TSTDIR))/database
TST_DB_SEC =  $(strip $(TSTDIR_SEC))/database
DBG_INFO_VERNO = $(subst .,_,$(VERNO))
CODE_GEN_LOG  := $(strip $(COMPLOGDIR))/codegen.log
BUILD_TST_DB         := $(BUILD_TSTDIR)/database
BUILD_TST_DB_SEC := $(BUILD_TSTDIR_SEC)/database
BPLGUINFOCUSTOMPREFIX = BPLGUInfoCustomApp_$(strip $(PLATFORM))_$(strip $(CHIP_VER))
MODIS_TST_DB         := $(strip $(TST_DB))
MODIS_TST_DB_SEC := $(strip $(TST_DB_SEC))
MODISBUILD_TST_DB         := $(strip $(BUILD_TST_DB))
MODISBUILD_TST_DB_SEC := $(strip $(BUILD_TST_DB_SEC))
MODIS_RULESDIR := $(strip $(RULESDIR))
CGEN_L1_OUTDIR := $(strip $(PROJ_INTERNAL_DIR))/l1trace
ifeq ($(strip $(COMPILER)),RVCT)
  CGEN_DEF_FILE = Tgt_Cnf_RVCT
else ifeq ($(strip $(COMPILER)),GCC)
  CGEN_DEF_FILE = Tgt_Cnf_GCC
else ifeq ($(strip $(COMPILER)),ADS)
  CGEN_DEF_FILE = Tgt_Cnf
else
  CGEN_DEF_FILE = Tgt_Cnf
endif

BUILD_SYSDIR = $(strip $(PROJDIR))/custom/system
BUILD_CODEGENDIR = $(strip $(PROJDIR))/custom/driver/drv_gen

NOT_REMOVAL_DIR_FILE = make/NotRemovalCodeDir.def

#  Settings for emigen
FLASH_OPTIONS_HDR = $(strip $(FIXPATH))/custom/driver/common/flash_opt.h
CUSTOM_EMI_H      = $(strip $(BUILD_SYSDIR))/custom_EMI.h
CUSTOM_EMI_RELEASE_H = $(strip $(BUILD_SYSDIR))/custom_EMI_release.h
CUSTOM_EMI_C      = $(strip $(BUILD_SYSDIR))/custom_EMI.c
CUSTOM_FLASH_C    = $(strip $(FIXPATH))/custom/driver/common/custom_flash.c
CUSTOM_FLASH_NORFDM5_C = $(strip $(BUILD_SYSDIR))/custom_flash_norfdm5.c
MEMORY_DEVICE_HDR = $(strip $(BUILD_SYSDIR))/custom_MemoryDevice.h

EMI_GENERATOR  = $(strip $(FIXPATH))/tools/emigenMD.pl

FLASHFILE = $(strip $(TMPDIR))/~flash_cfg_tmp.c
MEMORY_CFG = $(strip $(CUSTOM_EMI_H))

KEYFILE_PATH = tools/sw_binding_key.ini

# Settings for MSC
MSCWORKSPACE = $(strip $(FIXPATH))/mtk_tools/AutoTest/MSC_TestCase/target.msc
CUSTMENUTREE = $(strip $(FIXPATH))/$(strip $(MMIDIR))/Customer/CustResource/CustMenuTree_Out.c


MODEM_FOLDER=modem
EAS_FOLDER=modem/eas
UAS_FOLDER=modem/uas
GAS_FOLDER=modem/gas
FLC_FOLDER=service/flc2_v2
PPP_FOLDER=middleware/ppp_v2
SCSI_FOLDER=modem/common/scsi
SLEEPDRV_FOLDER=driver/sleep_drv
ifeq ($(strip $(L1_TDD128)),TRUE)
  UAS_FOLDER=modem/uas_tdd128
  GAS_FOLDER=modem/gas_tdd128
# FLC_FOLDER=service/flc2_v1
  PPP_FOLDER=middleware/ppp_v1
  SCSI_FOLDER=modem/common/scsi_tdd128
endif
ifeq ($(strip $(call Upper,$(UE_SIMULATOR))),TRUE)
EL1_FOLDER=modem/lte_sec/el1_smt
else
EL1_FOLDER=modem/lte_sec/el1
endif
UESIM_SMT_FOLDER = modem\smt\uesim

# Do not support new mmi feature file architecture
PURE_VERNO = $(subst .,_, $(subst $(call Upper,$(strip $(PROJECT_NAME))).,, $(subst MAUI_SW.,, $(subst MAUI_SW.CLASSB.,, $(call Upper,$(VERNO))))))
BPLGUINFOCUSTOMSRCP := BPLGUInfoCustomAppSrcP_$(strip $(PLATFORM))_$(strip $(CHIP_VER))_$(strip $(PURE_VERNO))
NEWTARGNAME    =  $(strip $(TARGNAME)).$(strip $(PURE_VERNO))
MMI_FEATURES_FILE = $(FIXPATH)/$(MMIDIR)/MMI/Inc/MMI_features.h
MMI_FEATURES_SWITCH_FILE = $(FIXPATH)/$(MMIDIR)/MMI/Inc/MMI_features_switch.h
PLATFORM_LIB   =

# L1 database
L1_DB_COMM     =  $(strip $(FIXPATH))/l1/common

# version no dir
VERNODIR       =  $(strip $(PROJDIR))/verno

# summary log
LOG            =  $(strip $(TARGDIR))/link.log
BOOTLOADER_LOG =  $(strip $(TARGDIR))/bootloader.log
BOOTLOADER_EXT_LOG =  $(strip $(TARGDIR))/bootloader_ext.log
LNKERRORLOG    =  $(strip $(TARGDIR))/link_error.log

# Component's log file
COMPLOGDIR     =  $(strip $(TARGDIR))/log
COMPLINTLOGDIR     =  $(strip $(TARGDIR))/lint_log
MMI_FEATURES_LOG   =  $(strip $(COMPLOGDIR))/MMI_features.log
DB_CHECK_LOG   =  $(strip $(COMPLOGDIR))/db_check.log

INFOLOG := $(strip $(COMPLOGDIR))/info.log
INFOMAKELOG = $(strip $(COMPLOGDIR))/infomake.log
MCDDLL_INFOLOG = $(strip $(COMPLOGDIR))/mcddll_info.log
MCDDLL_UPDATE_LOG = $(strip $(COMPLOGDIR))/mcddll_update.log
INFOLOG_$(strip $(BLUETOOTH_SUPPORT)) = $(strip $(COMPLOGDIR_BT))/info_$(strip $(BLUETOOTH_SUPPORT)).log

ifeq ($(strip $(DEMO_PROJECT)),TRUE)
VERNOFILE     :=  make/Verno.bld
else
VERNOFILE     := 
endif

SLIM_BRANCH := $(call Upper,$(strip $(BRANCH)))
BRANCH   +=   $(call Upper,$(strip $(PROJECT_NAME)))
# *************************************************************************
# Set defaul value to eliminate "option not define" warning
# *************************************************************************
BM_NEW      = FALSE

INSIDE_MTK = 0
ifeq ($(strip $(call Upper,$(MTK_INTERNAL))),TRUE)
    INSIDE_MTK = 1
endif

ifndef BLUETOOTH_SUPPORT_SWITCH
  BLUETOOTH_SUPPORT_SWITCH=NONE
endif

DEFAULT_CUSTOMER = MTK MTK_RF PLUTO
ifneq ($(filter $(call Upper,$(strip $(PROJECT_NAME))),$(strip $(DEFAULT_CUSTOMER))),)
  SCATTERNAME = scat$(strip $(PLATFORM)).txt
  ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
    SCATTERNAME := scat$(strip $(PLATFORM))_L1S.txt
  endif
  ifeq ($(strip $(TEST_LOAD_TYPE)),BASIC)
    SCATTERNAME := scat$(strip $(PLATFORM))_BASIC.txt
  endif
  ifeq ($(strip $(TEST_LOAD_TYPE)),UDVT)
    SCATTERNAME := scat$(strip $(PLATFORM))_UDVT.txt
  endif
else
  SCATTERNAME = scat$(strip $(PROJECT_NAME)).txt
  ifeq ($(strip $(TEST_LOAD_TYPE)),L1S)
    SCATTERNAME := scat$(strip $(PROJECT_NAME))_L1S.txt
  endif
  ifeq ($(strip $(TEST_LOAD_TYPE)),BASIC)
    SCATTERNAME := scat$(strip $(PROJECT_NAME))_BASIC.txt
  endif
  ifeq ($(strip $(TEST_LOAD_TYPE)),UDVT)
    SCATTERNAME := scat$(strip $(PROJECT_NAME))_UDVT.txt
  endif
endif

SCATTERFILE := $(strip $(BUILD_SYSDIR))/$(strip $(SCATTERNAME))
COPRO_SCATTERFILE = $(strip $(COPRO_SYSDIR))/$(strip $(SCATTERNAME))

BL_SCATTERFILE   = $(strip $(BUILD_SYSDIR))/scatBL_$(strip $(PLATFORM)).txt
BL_EXT_SCATTERFILE   = $(strip $(BUILD_SYSDIR))/scatBL_$(strip $(PLATFORM))_ext.txt

ifeq ($(strip $(COMPILER)),GCC)
  SCATTERFILE:= $(subst scat,lds,$(strip $(SCATTERFILE)))
  COPRO_SCATTERFILE := $(subst scat,lds,$(strip $(COPRO_SCATTERFILE)))
  BL_SCATTERFILE:= $(subst scat,lds,$(strip $(BL_SCATTERFILE)))
  BL_EXT_SCATTERFILE:= $(subst scat,lds,$(strip $(BL_EXT_SCATTERFILE)))
endif

SCATTERFILE_FLASHTOOL := $(subst .txt,_flashtool.txt,$(strip $(SCATTERFILE)))
SCATTERFILE_FLASHTOOL_NAME := $(filter %.txt,$(subst /, ,$(SCATTERFILE_FLASHTOOL)))

# *************************************************************************
#  Implicit Rules and Compiler Options
# *************************************************************************
BIN_FILE       =  $(strip $(NEWTARGNAME)).bin
IMG_FILE       =  $(strip $(TARGNAME)).elf
ROM_IMG_FILE   =  rompatch/$(strip $(PLATFORM))/$(strip $(CHIP_VER))/ROMSA_$(strip $(PLATFORM))_$(strip $(CHIP_VER)).sym
ifeq ($(strip $(COMPILER)),GCC)
LIS_FILE       =  $(strip $(TARGNAME)).map
else
LIS_FILE       =  $(strip $(TARGNAME)).lis
endif
# *************************************************************************
#  Settings for BOOTLOADER
# *************************************************************************
BTLDVERNODIR   =  $(strip $(FIXPATH))/service/sys_svc/bootloader/src
BUILDBTLDVERNODIR   =  $(strip $(PROJDIR))/verno_bootloader
BTLD_PREFIX    =  $(strip $(PROJECT_NAME))_BOOTLOADER_$(strip $(BTLD_VERNO))_$(strip $(PLATFORM))_$(strip $(PURE_VERNO))
BTLD_EXT_PREFIX = $(strip $(BTLD_PREFIX))_ext
BTLD_BIN_FILE  =  $(strip $(BTLD_PREFIX)).bin
BTLD_EXT_BIN_FILE  =  $(strip $(BTLD_EXT_PREFIX)).bin

ifndef MODIS_CONFIG
  MODIS_CONFIG := FALSE
endif
ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  ifeq ($(strip $(call Upper,$(UE_SIMULATOR))),TRUE)
    MODIS_UESIM := UESim
  else
    MODIS_UESIM := MoDIS
  endif
endif

# *************************************************************************
# Settings for DSP
# *************************************************************************
DSPDIR       := $(strip $(FIXPATH))/modem/dsp_bin
BUILD_DSPDIR := $(strip $(TARGDIR))/dsp
DSP_INFO     := $(DSPDIR)/$(strip $(LTE_DSP_PROJECT))/$(strip $(LTE_DSP_FLAVOR))/DSP.info
DSP_DBF      := $(DSPDIR)/common/DSP_Default.dbf
ifneq ($(strip $(MDSYS)),MD2)
  include $(strip $(DSP_INFO))
endif
DSP_VER      := $(strip $(PLATFORM))_$(subst .,_,$(call Upper,$(strip $(DSP_LABEL))))
BUILD_DSPDIR := $(strip $(TARGDIR))/dsp

# *************************************************************************
# Settings for Guardian
# *************************************************************************
ifndef PARTIAL_SOURCE 
PARTIAL_SOURCE := FALSE
endif

# *************************************************************************
# File setting for linux/win
# *************************************************************************
ifeq ($(strip $(OS_VERSION)),MSWin32)
   CGEN := $(strip $(FIXPATH))\tools\Cgen.exe
   DRV_GEN := $(FIXPATH)\custom\driver\drv\Drv_Tool\DrvGen.exe
   CREATE_EMPTY_TRC_GEN_FILES := tools\CreateEmptyTrcGenFiles.exe
   MBL_COMPOSER := tools\MBL_Composer.exe
   DBG_INFOGEN  := tools\DbgInfoGen.exe
   UPDATE_IMG   := tools\update_img.exe
   HEADER_TEMP  :=  $(subst /,\,$(strip $(PROJDIR)))\header_temp
   HTOGETHER    := tools\hTogether\htogether_list.bat
   MinGWDir     := tools\MinGW\4.6.2\win
else
   CGEN := $(strip $(FIXPATH))/tools/Cgen
   DRV_GEN := $(FIXPATH)/custom/driver/drv/Drv_Tool/DrvGen
   CREATE_EMPTY_TRC_GEN_FILES := tools/CreateEmptyTrcGenFiles
   MBL_COMPOSER := tools/MBL_Composer
   DBG_INFOGEN  := tools/DbgInfoGen
   UPDATE_IMG   := tools/update_img
   HEADER_TEMP  :=  $(strip $(PROJDIR))/header_temp
   HTOGETHER    := tools/hTogether/htogether_list.sh
   MinGWDir     := tools/MinGW/4.6.2/linux
endif
