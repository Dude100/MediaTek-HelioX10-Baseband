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
#
#
# *************************************************************************
#
#   		MediaTek Inc GSM/GPRS Wireless Communicatin Project
#					Build/Make Development Tools
#
#			Author			Date			Description
#			Sherman Wang 	2004/04/29		Create version 1.0
#
# *************************************************************************
# COMP.MAK  - Component build script
#
#  DISCUSSION:
#
#     This file is build script for component modules, and contains C source
#  files (.c), and Assembly source files(.s).
#
#  USAGE:
#
#  IMPORTANT NOTES:
#
# *************************************************************************
#
# $Revision:$
# $Modtime:$
# $Log:$
#
# 12 24 2013 amber.su
# [MOLY00051396] [Target Build] phase-in hToghther
# .
#
# 07 18 2013 xenia.tsou
# [MOLY00030211] [Target build] custom folder selection enhancement
# .
#
# 02 25 2013 po.hu
# [MOLY00008094] [Custom Release] UCR
# UCR TRUNK
#
# 12 14 2012 xenia.tsou
# [MOLY00007565] [Target] enhance the PCIBT mechanism and fix PCIBT error
# .
#
# 11 28 2012 po.hu
# [MOLY00006607] [MakeFile] [Modify: Others] Change the folder of UL1 codegen files
# .
#
# 11 15 2012 amber.su
# [MOLY00005533] [Taget Build] always keep via folder
# .
#
# 11 08 2012 po.hu
# [MOLY00005867] [Build script] Move internal out of build
# .
#
# 11 06 2012 ray.lin-wang
# [MOLY00005322] TATAKA merge to MOLY
# [SM] check-in SM Build flow part.
#
# 10 30 2012 ray.lin-wang
# [MOLY00005507] [Target Build] Fix the build flow related porting
# .
# 
# 10 19 2012 amber.su
# [MOLY00003791] [MakeFile] [Modify: Others] fota module removal
# .
# 
# 10 18 2012 xiaolin.qiao
# [MOLY00004980] [MakeFile] [Add/Modify: Feature Option] X_BOOTING
# .
# 
# 10 11 2012 jerry.chang
# [MOLY00004709] Specify dp_engine as ARM mode in dp_engine.mak instead of comp.mak
# .
# 
# 09 20 2012 amber.su
# [MOLY00003467] [Target Build] build command change modification
# .
# 
# 09 18 2012 po.hu
# [MOLY00003260] [Custom Release] Correct file name/path
# .
# 
# 09 13 2012 po.hu
# [MOLY00003506] [Target] Control ARM/THUMB code in module makefile
# .
# 
# 09 13 2012 amber.su
# [MOLY00003467] [Target Build] build command change modification
# .
# 
# 09 12 2012 amber.su
# [MOLY00003467] [Target Build] build command change modification
# .
# 
# 09 03 2012 amber.su
# NULL
# .
# 
# 08 17 2012 xenia.tsou
# [MOLY00001739] [Global Inc] Service category include path re-organization
# .
# 
# 07 26 2012 jerry.chang
# [MOLY00001186] [MOLY] remove MOLY unneeded feature option
# .
# 
# 07 23 2012 po.hu
# [MOLY00000289] [Build System] Let build script compatible for Windows and Linux
# .
# 
# 07 20 2012 ray.lin-wang
# [MOLY00000791] [Target Build] Remove redundant build flow
# remove Resgen.mak flow.
# remove app_cfg flow.
# remove ALIAS flow.
# 
# 07 20 2012 amber.su
# [MOLY00000942] [Target Build] add include path for armasm for compiling assembly code
# .
# 
# 07 19 2012 ray.lin-wang
# [MOLY00000043] [GCC on Linux] build flow related porting
# . Fix the TARGDEP causing error message when remake.
# *************************************************************************
# *************************************************************************
# Common macro definitions
# *************************************************************************
#$(call Upper,$(1)) ...... reference $(1) in upper-case letters
Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))
Lower = $(subst Z,z,$(subst Y,y,$(subst X,x,$(subst W,w,$(subst V,v,$(subst U,u,$(subst T,t,$(subst S,s,$(subst R,r,$(subst Q,q,$(subst P,p,$(subst O,o,$(subst N,n,$(subst M,m,$(subst L,l,$(subst K,k,$(subst J,j,$(subst I,i,$(subst H,h,$(subst G,g,$(subst F,f,$(subst E,e,$(subst D,d,$(subst C,c,$(subst B,b,$(subst A,a,$(1)))))))))))))))))))))))))))

CUSTOM_FLD_MAPPING = $(if $($(subst /,_,$(patsubst %/,%,$(subst //,/,$(subst \,/,$(call lc, $(1))))))), \
                     $($(subst /,_,$(patsubst %/,%,$(subst //,/,$(subst \,/,$(call lc, $(1))))))),\
                     $(if $(wildcard $(subst //,/,$(subst \,/,$(call lc, $(1))))/$(BOARD_VER)/$(strip $(CUSTOM_FLAVOR))),\
                     $(subst //,/,$(subst \,/,$(call lc, $(1))))/$(BOARD_VER)/$(strip $(CUSTOM_FLAVOR)),\
                     $(wildcard $(subst //,/,$(subst \,/,$(call lc, $(1))))/$(BOARD_VER)/DEFAULT)))


AUTO_MERGE_FILE_CHECK = $(if $(shell $(LIST_DIR) "$(call CUSTOM_FLD_MAPPING,$(1))/$(2)" 2>$(DEV_NUL)), $(call CUSTOM_FLD_MAPPING,$(1))/$(2), \
                        $(if $(shell $(LIST_DIR) "$(1)/_Default_BB/$(strip $(PLATFORM))/$(2)" 2>$(DEV_NUL)), $(1)/_Default_BB/$(strip $(PLATFORM))/$(2),))
# *************************************************************************
# Project Variables
# *************************************************************************
include make/cmd_cfg.mak
include tools/GMSL/gmsl
include make/Custom.bld             # Custom release build
include $(strip $(TMPDIR))/~compbld.tmp            # Temporary build script created by build.mak
include $(strip $(PROJECT_MAKEFILE))
-include $(strip $(TARGDIR))/MMI_DRV_DEFS.mak

ifeq ($(strip $(COMPILER)),GCC)
  ADEFTrans = $(strip -defsym $(1)=$(strip $(2)))
else ifeq ($(strip $(COMPILER)),RVCT)
  ADEFTrans = -pd "$(1) SETL {$(strip $(2))}"
endif

NEED_CHECK_DEPEND_LIST :=

ifneq ($(strip $(MODIS_CONFIG)),TRUE)
  ifeq ($(strip $(COMPILER)),RVCT)
  ifeq ($(strip $(RVCT_VERSION)),V31)
    #include make/compiler_cfg.mak for internal only
    ifeq ($(strip $(CUSTOM_RELEASE)),FALSE)
      include make/compiler_cfg.mak
    else ifeq ($(strip $(MTK_SUBSIDIARY)),TRUE)
      include make/compiler_cfg.mak
    endif
  endif
  endif
endif

MODULE_DEFS := $(DEFINES) $(MMI_DEFS) $(DRV_DEFS) $(OPTR_DEFS)

ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  MODULE_DEFS := $(filter-out __MTK_TARGET__,$(MODULE_DEFS))
  include make/modisConfig.mak
  NEED_CHECK_DEPEND_LIST += make/modisConfig.mak
endif

include $(strip $(TMPDIR))/~categorymapping.mak
MODULE_MAKEFILE := make/$($(call Upper,$(strip $(COMPONENT)))_MODULE_CATEGORY)/$(call Lower,$(strip $(COMPONENT))).mak
include $(MODULE_MAKEFILE)
NEED_CHECK_DEPEND_LIST += $(MODULE_MAKEFILE)

CATEGORY_CONFIG_MAKEFILE := make/module/$($(call Upper,$(strip $(COMPONENT)))_CATEGORY)/$($(call Upper,$(strip $(COMPONENT)))_CATEGORY)_config.mak
ifneq ($(strip $(NOT_USE_CATEGORY_INCLUDE)),TRUE)
  include $(CATEGORY_CONFIG_MAKEFILE)
  NEED_CHECK_DEPEND_LIST += $(CATEGORY_CONFIG_MAKEFILE)
endif

ifeq ($(strip $(ENABLE_PARTIAL_TRACE)),TRUE)
  ifneq ($(filter $(PARTIAL_TRACE_LIB),$(call Lower,$(COMPONENT))),)
    DEFINES := $(filter-out MODULE_TRACE_OFF,$(DEFINES))
  endif
endif
# *************************************************************************
# Set SUFFIXES
# *************************************************************************
.SUFFIXES:
.SUFFIXES: .obj .c .S .s .cpp .arm .ltp .det

# *************************************************************************
# Set PHONY
# *************************************************************************
.PHONY : update_lib update_dep


# *************************************************************************
# Set Shell
# *************************************************************************
#SHELL = $(ComSpec)

# *************************************************************************
# Construct $(COMPONENT) specific varible
# *************************************************************************
TARGLIB       =  $(subst \,/,$(strip $(COMPLIBDIR)))/lib$(strip $(COMPONENT)).a

COMPOBJS_DIR  =  $(subst \,/,$(OBJSDIR))/$(strip $(COMPONENT))
OBJ_ARCHIVE   =  $(OBJSDIR)/$(COMPONENT)/$(strip $(COMPONENT)).via
OBJ_ARCHIVE_SORT  =  $(OBJSDIR)/$(COMPONENT)/$(strip $(COMPONENT))_sort.via

TARGDEP       =  $(subst \,/,$(RULESDIR))/$(strip $(COMPONENT)).dep
COMPDETS_DIR  =  $(subst \,/,$(RULESDIR))/$(strip $(COMPONENT))
COMPVIA_DIR = $(TARGDIR)/via

TARGDEP_LIST :=

ifneq ($(strip $(MODIS_CONFIG)),TRUE)
  MODULE_FOLDER = $(TARGDIR)/module
else
  MODULE_FOLDER = $(strip $(BUILDDIR))/$(strip $(PROJECT_NAME))/$(strip $(FLAVOR))/$(strip $(MODIS_UESIM))/_BUILD_MODULE
endif

ifdef $($(COMPONENT))
  COMPONENT_FOLDER = $(MODULE_FOLDER)/$(strip $($(call Lower,$(COMPONENT))))/$(call Lower,$(strip $(COMPONENT)))
else
  COMPONENT_FOLDER = $(MODULE_FOLDER)/$(call Lower,$(strip $(COMPONENT)))
endif
COMPONENT_LOG = $(COMPONENT_FOLDER)/$(call Lower,$(strip $(COMPONENT)))

ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  COMPLOGDIR := $(MODISLOGDIR)
  TARGLIB := $(MODISPROJDIR)/$(strip $(COMPONENT))/$(strip $(MODIS_MODE))/$(strip $(COMPONENT)).lib
  COMPOBJS_DIR = $(MODISPROJDIR)/$(strip $(COMPONENT))/$(strip $(MODIS_MODE))
  OBJ_ARCHIVE = $(COMPONENT_FOLDER)/$(call Lower,$(strip $(COMPONENT)))_lib.via
  OBJ_ARCHIVE_SORT = $(COMPONENT_FOLDER)/$(call Lower,$(strip $(COMPONENT)))_lib_sort.via
  TARGDEP = $(MODIS_RULESDIR)/$(call Lower,$(strip $(COMPONENT))).dep
  COMPDETS_DIR = $(MODIS_RULESDIR)/$(call Lower,$(strip $(COMPONENT)))
  COMPVIA_DIR = $(COMPONENT_FOLDER)
  ifeq ($(strip $(MODIS_COMPILER)),MINGW)
    ifeq ($(strip $(MODIS_MODE)),Debug)
      DEBUG_MODULES := ALL
    else ifeq ($(strip $(MODIS_MODE)),Release)
      NON_DEBUG_MODULES := ALL
    endif
  endif
endif

# *************************************************************************
# Configure debug symbol compiler arguments
# *************************************************************************
ifndef DEBUG_MODULES
  DEBUG_MODULES =
endif

ifndef NON_DEBUG_MODULES
  NON_DEBUG_MODULES =
endif

ifneq ($(filter ALL,$(call Upper,$(DEBUG_MODULES))),)
  ifneq ($(strip $(MODIS_CONFIG)),TRUE)
  ifeq ($(strip $(COMPILER)),GCC)
      CFLAGS += -gdwarf-3
      CPLUSFLAGS += -gdwarf-3
  else ifeq ($(strip $(COMPILER)),RVCT)
    CFLAGS += --debug --no_debug_macros
    CPLUSFLAGS += --debug --no_debug_macros
  endif
  endif
else
  ifneq ($(filter $(call Upper,$(COMPONENT)),$(call Upper,$(DEBUG_MODULES))),)
    ifneq ($(strip $(MODIS_CONFIG)),TRUE)
    ifeq ($(strip $(COMPILER)),GCC)
      CFLAGS += -gdwarf-3
      CPLUSFLAGS += -gdwarf-3
    else ifeq ($(strip $(COMPILER)),RVCT)
      CFLAGS += --debug --no_debug_macros
      CPLUSFLAGS += --debug --no_debug_macros
    endif
    endif
  endif
endif

ifneq ($(filter ALL,$(call Upper,$(NON_DEBUG_MODULES))),)
  CFLAGS := $(filter-out -g -gtp --debug --no_debug_macros -gdwarf-% -g1 -g2 -g3,$(strip $(CFLAGS)))
  CPLUSFLAGS := $(filter-out -g -gtp --debug --no_debug_macros -gdwarf-% -g1 -g2 -g3,$(strip $(CPLUSFLAGS)))
else ifneq ($(filter $(call Upper,$(COMPONENT)),$(call Upper,$(NON_DEBUG_MODULES))),)
  CFLAGS := $(filter-out -g -gtp --debug --no_debug_macros -gdwarf-% -g1 -g2 -g3,$(strip $(CFLAGS)))
  CPLUSFLAGS := $(filter-out -g -gtp --debug --no_debug_macros -gdwarf-% -g1 -g2 -g3,$(strip $(CPLUSFLAGS)))
endif

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
  ifneq ($(strip $(MTK_SUBSIDIARY)),TRUE)
    ifneq ($(strip $(MODIS_CONFIG)),TRUE)
    ifeq ($(strip $(COMPILER)),RVCT)
      ifneq ($(filter --debug,$(strip $(CFLAGS))),)
        CFLAGS := $(filter-out --remove_unneeded_entities,$(strip $(CFLAGS)))
      endif
      ifneq ($(filter --debug,$(strip $(CPLUSFLAGS))),)
        CPLUSFLAGS := $(filter-out --remove_unneeded_entities,$(strip $(CPLUSFLAGS)))
      endif
    endif
    endif
  endif
endif

ifneq ($(filter $(call Upper,$(COMPONENT)),$(call Upper,$(NON_DEBUG_MODULES))),)
  $(info Module $(COMPONENT) is in NON_DEBUG mode)
else ifneq ($(filter $(call Upper,$(COMPONENT)),$(call Upper,$(DEBUG_MODULES))),)
  $(info Module $(COMPONENT) is in DEBUG mode)
else
  $(info Module $(COMPONENT) is in DEFALUT mode)
endif

# *************************************************************************
# Construct the list of object dependencies
# *************************************************************************
# THUMB + Assembly
SRCLIST0 := $(sort $(SRC_LIST) $(filter-out %.c %.C %.cpp,$(SRC_LIST_ARM)))
# ARM
SRCLIST5 := $(sort $(filter %.c %.C %.cpp,$(SRC_LIST_ARM)))
# BOTH
SRC_LIST := $(SRCLIST0) $(SRCLIST5)
ifdef SRC_RULE_FLAG32
  # SRC_RULE_FLAG32 means the asm file should be compiled by armasm using -32 flag
  SRCLIST9 := $(foreach file,$(SRCLIST0),$(if $(filter $(notdir $(call Upper,$(file))) $(call Upper,$(file)),$(call Upper,$(SRC_RULE_FLAG32))),$(file),))
  SRCLIST0 := $(foreach file,$(SRCLIST0),$(if $(filter $(notdir $(call Upper,$(file))) $(call Upper,$(file)),$(call Upper,$(SRC_RULE_FLAG32))),,$(file)))
endif
ifdef SRC_RULE_PREPROCESS
  # SRC_RULE_PREPROCESS means the asm file needs to be preprocessed by armcc -E and then armasm
  SRCLIST8 := $(foreach file,$(SRCLIST0),$(if $(filter $(notdir $(call Upper,$(file))) $(call Upper,$(file)),$(call Upper,$(SRC_RULE_PREPROCESS))),$(file),))
  SRCLIST0 := $(foreach file,$(SRCLIST0),$(if $(filter $(notdir $(call Upper,$(file))) $(call Upper,$(file)),$(call Upper,$(SRC_RULE_PREPROCESS))),,$(file)))
endif
ifdef SRC_RULE_AUTOTCM
  # SRC_RULE_AUTOTCM means the c file needs to be preprocessed by armcc -E and then auto tcm and then compiled by armcc -c
  ifeq ($(strip $(SRC_RULE_AUTOTCM)),ALL)
    SRCLIST1 := $(filter     %.c %.C %.cpp,$(SRCLIST0))
    SRCLIST0 := $(filter-out %.c %.C %.cpp,$(SRCLIST0))
    SRCLIST6 := $(filter     %.c %.C %.cpp,$(SRCLIST5))
    SRCLIST5 := $(filter-out %.c %.C %.cpp,$(SRCLIST5))
  else
    SRCLIST1 := $(foreach file,$(SRCLIST0),$(if $(filter $(notdir $(call Upper,$(file))) $(call Upper,$(file)),$(call Upper,$(SRC_RULE_AUTOTCM))),$(file),))
    SRCLIST0 := $(foreach file,$(SRCLIST0),$(if $(filter $(notdir $(call Upper,$(file))) $(call Upper,$(file)),$(call Upper,$(SRC_RULE_AUTOTCM))),,$(file)))
    SRCLIST6 := $(foreach file,$(SRCLIST5),$(if $(filter $(notdir $(call Upper,$(file))) $(call Upper,$(file)),$(call Upper,$(SRC_RULE_AUTOTCM))),$(file),))
    SRCLIST5 := $(foreach file,$(SRCLIST5),$(if $(filter $(notdir $(call Upper,$(file))) $(call Upper,$(file)),$(call Upper,$(SRC_RULE_AUTOTCM))),,$(file)))
  endif
endif

CSRCS   := $(filter %.c %.C %.cpp, $(SRCLIST0))
CSRCS1  := $(filter %.c %.C %.cpp, $(SRCLIST1))
CSRCS5  := $(filter %.c %.C %.cpp, $(SRCLIST5))
CSRCS6  := $(filter %.c %.C %.cpp, $(SRCLIST6))
ASRCS   := $(filter %.s %.S %.arm, $(SRCLIST0))
ASRCS1  := $(filter %.s %.S %.arm, $(SRCLIST9))
ASRCS2  := $(filter %.s %.S %.arm, $(SRCLIST8))

INC_DIR += $(CATEGORY_INCDIRS)
INCDIRS += $(INC_DIR)
INCDIRS := $(call uniq,$(INCDIRS))

#CATEGORY_DEFS is from $category_config.mak
DEFINES += $(CATEGORY_DEFS)
#COMP_DEFS is from $module.mak
DEFINES += $(COMP_DEFS)

ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  ifdef MODIS_DIS_INC_PATH
    INCDIRS := $(filter-out $(MODIS_DIS_INC_PATH),$(INCDIRS))
  endif
  ifdef MODIS_DIS_OPTION
    DEFINES := $(filter-out $(MODIS_DIS_OPTION),$(DEFINES))
  endif
endif

ifeq ($(strip $(WISDOM_CUSTOM_BUILD)),TRUE)
  ifeq ($(strip $(COMPONENT)),wise)
    WISE_INCDIRS = $(subst external_mmi/wise/wise_headers/$(strip $(BOARD_VER))/App,../App,$(INCDIRS))
    WISE_INCDIRS_APPS = $(subst external_mmi/wise/wise_headers/$(strip $(BOARD_VER))/apps,../apps,$(WISE_INCDIRS))
    CINCDIRS 	=  $(foreach inc, $(subst \,/,$(WISE_INCDIRS_APPS)),-I$(inc))
  else
    CINCDIRS 	=  $(foreach inc, $(subst \,/,$(INCDIRS)),-I$(inc))
  endif
else
    CINCDIRS 	=  $(foreach inc, $(subst \,/,$(INCDIRS)),-I$(inc))
endif

CDEFS 		=  $(foreach def, $(DEFINES),-D$(def))
A_CDEFS   = $(foreach def, $(strip $(DEFINES)),-D$(def)=$(def)) 


#*************************************************************************
# folder path check
#*************************************************************************

ifneq ($(strip $(NO_PCIBT)),TRUE)
  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
    include make/rel/hq/Comp_PCIBT.mak
  endif
endif


# *************************************************************************
# Set View Path
# *************************************************************************
vpath
vpath %.obj $(COMPOBJS_DIR)
vpath %.det $(COMPDETS_DIR)

# XXX!!! To use predefine for assembler is a little difficult and
# usually can be replaced with C sources.
#ifeq ($(filter wise ijet_adp custom,$(COMPONENT)),)
ifeq ($(filter wise ijet_adp gadget_adp,$(COMPONENT)),)
  ADEFS       = $(foreach def, $(COMP_DEFS),$(call ADEFTrans,$(def), TRUE))
else
  ADEFS       = 
endif

ADEFS += $(foreach def, $(strip $(COM_DEFS_FOR_$(strip $(PLATFORM)))),$(call ADEFTrans,$(def), TRUE))

ifeq ($(strip $(KAL_RECORD_BOOTUP_LOG)),TRUE)
  ADEFS += $(call ADEFTrans,__KAL_RECORD_BOOTUP_LOG__, TRUE)
endif

ifeq ($(strip $(SW_BINDING_SUPPORT)),BIND_TO_CHIP_BASIC)
  ADEFS += $(call ADEFTrans,__BIND_TO_CHIP_BASIC__, TRUE)
endif

ifneq ($(filter BIND_TO_KEY BIND_TO_CHIP_AND_KEY, $(strip $(SW_BINDING_SUPPORT))),)
  ADEFS += $(call ADEFTrans,__BIND_TO_KEY__, TRUE)
endif

ifneq ($(filter BIND_TO_CHIP BIND_TO_CHIP_AND_KEY, $(strip $(SW_BINDING_SUPPORT))),)
  ADEFS += $(call ADEFTrans,__BIND_TO_CHIP__, TRUE)
endif

ifneq ($(call Upper,$(strip $(PLATFORM))),MT6573)
ifneq ($(call Upper,$(strip $(PLATFORM))),MT6575)
ifneq ($(call Upper,$(strip $(PLATFORM))),MT6577)
ifneq ($(filter $(strip $(PLATFORM)),$(SV5_PLATFORM)),)
  ADEFS += $(call ADEFTrans,__SV5_ENABLED__, TRUE)
endif
endif
endif
endif

ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
  ADEFS += $(call ADEFTrans,DSP_BOOT_SEC, TRUE)
endif

ifdef CARD_DOWNLOAD
  ifneq ($(filter bootloader bootloader_ext,$(strip $(COMPONENT))),)
    ifneq ($(strip $(CARD_DOWNLOAD)),NONE)
      ADEFS += $(call ADEFTrans,__CARD_DOWNLOAD__, TRUE)
      CFLAGS += -D__CARD_DOWNLOAD__
      ifeq ($(strip $(CARD_DOWNLOAD)),FILESYSTEM_ON_CARD)
        ADEFS += $(call ADEFTrans,__FS_CARD_DOWNLOAD__, TRUE)
        CFLAGS += -D__FS_CARD_DOWNLOAD__
      endif
      ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
        ADEFS += $(call ADEFTrans,__UBL_NAND_FULL_DRIVER__, TRUE)
        CFLAGS += -D__UBL_NAND_FULL_DRIVER__
      else
        ADEFS += $(call ADEFTrans,__UBL_NOR_FULL_DRIVER__, TRUE)
        CFLAGS += -D__UBL_NOR_FULL_DRIVER__ -D__NOR_FULL_DRIVER__
      endif
    endif
  endif
endif

ifeq ($(strip $(NAND_FLASH_BOOTING)),ONDEMAND)
  ADEFS += $(call ADEFTrans,__DEMAND_PAGING__, TRUE)
endif

ifeq ($(strip $(NAND_FLASH_BOOTING)),MIXED)
  ADEFS += $(call ADEFTrans,__DEMAND_PAGING__, TRUE)
endif

ifeq ($(strip $(NAND_FLASH_BOOTING)),SINGLE)
  ADEFS += $(call ADEFTrans,__NFB_SINGLE_ROM__, TRUE)
endif

ifeq ($(strip $(EMMC_BOOTING)),ONDEMAND)
  ADEFS += $(call ADEFTrans,__DEMAND_PAGING__, TRUE)
endif

ifeq ($(strip $(EMMC_BOOTING)),MIXED)
  ADEFS += $(call ADEFTrans,__DEMAND_PAGING__, TRUE)
endif

ifdef NEED_BUILD_BOOTLOADER
  ifeq ($(strip $(NEED_BUILD_BOOTLOADER)),TRUE)
    ifeq ($(strip $(COMPONENT)),sys_drv)
      CFLAGS += -D__BL_ENABLE__
      ADEFS += $(call ADEFTrans,__BL_ENABLE__, TRUE)
      ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
      ifeq ($(strip $(EMMC_BOOTING)),NONE)
        CFLAGS += -DREMAPPING
        ADEFS += $(call ADEFTrans,REMAPPING, TRUE)
      endif
      endif
    endif
    ifeq ($(strip $(COMPONENT)),custom)
      CFLAGS += -D__BL_ENABLE__
      ADEFS += $(call ADEFTrans,__BL_ENABLE__, TRUE)
      ifeq ($(strip $(NAND_FLASH_BOOTING)),NONE)
        CFLAGS += -DREMAPPING
        ADEFS += $(call ADEFTrans,REMAPPING, TRUE)
      endif
    endif
  endif
endif

ifeq ($(strip $(KAL_RECORD_BOOTUP_LOG)),TRUE)
  ADEFS += $(call ADEFTrans,__KAL_RECORD_BOOTUP_LOG__, TRUE)
endif

ifneq ($(filter __KAL_STACK_ISOLATION__,$(strip $(DEFINES))),)
  ADEFS += $(call ADEFTrans,__KAL_STACK_ISOLATION__, TRUE)
endif

ifneq ($(filter __KAL_STACK_EXTENSIBLE__,$(strip $(DEFINES))),)
  ADEFS += $(call ADEFTrans,__KAL_STACK_EXTENSIBLE__, TRUE)
endif

ifneq ($(filter __EVENT_BASED_TIMER__,$(strip $(DEFINES))),)
  ADEFS += $(call ADEFTrans,__EVENT_BASED_TIMER__, TRUE)
endif

ifeq ($(strip $(COMPONENT)),nucleus_ctrl_code)
  ADEFS += $(call ADEFTrans,$(strip $(PLATFORM)), TRUE)
endif

ifeq ($(strip $(COMPONENT)),nucleus_v2_ctrl_code)
  ADEFS += $(call ADEFTrans,$(strip $(PLATFORM)), TRUE)
endif

ifeq ($(DEBUG_SAVE_CUR_THREAD),TRUE)
  ADEFS += $(call ADEFTrans,__DEBUG_SAVE_CUR_THREAD__, TRUE)
endif

ifeq ($(PRODUCTION_RELEASE),TRUE)
  ADEFS += $(call ADEFTrans,__PRODUCTION_RELEASE__, TRUE)
endif

ifeq ($(strip $(L1_GPRS)),TRUE)
  ifeq ($(strip $(L1_WCDMA)),TRUE)
    ifeq ($(strip $(L1_3GSOLUTION)),MA_L1)
       ifeq ($(findstring nucleus_ctrl_code,$(strip $(COMPONENT))),nucleus_ctrl_code) 
          ADEFS       += $(call ADEFTrans,__MA_L1__, TRUE)
       endif
       ifeq ($(findstring nucleus_ctrl_code_ma,$(strip $(COMPONENT))),nucleus_ctrl_code_ma) 
          ADEFS       += $(call ADEFTrans,__MA_L1__, TRUE)
       endif
    endif
  endif
endif

ifeq ($(strip $(RTOS)),NUCLEUS)
  ADEFS       +=  $(call ADEFTrans,KAL_ON_NUCLEUS, TRUE)
endif

ifeq ($(strip $(RTOS)),NUCLEUS_V2)
  ADEFS       +=  $(call ADEFTrans,KAL_ON_NUCLEUS, TRUE)
  ADEFS       +=  $(call ADEFTrans,__NUCLEUS_VERSION_2__, TRUE)
endif

ifeq ($(strip $(RTOS)),THREADX)
  ADEFS       +=  $(call ADEFTrans,KAL_ON_THREADX, TRUE)
endif

ifeq ($(strip $(CHIP_VERSION_CHECK)),TRUE)
   ADEFS       +=  $(call ADEFTrans,__CHIP_VERSION_CHECK__, TRUE)
endif

ifeq ($(strip $(TEST_LOAD_TYPE)),UDVT)
   ADEFS       +=  $(call ADEFTrans,__MEUT__, TRUE)
   ADEFS       +=  $(call ADEFTrans,__UDVT__, TRUE)
endif

ifeq ($(strip $(FLASH_TEST_SELECT)),NAND_FLASH)
  ifeq ($(strip $(COMPONENT)),nucleus_ctrl_code)
    ADEFS       +=  $(call ADEFTrans,__WATCHDOG_RESTART_DISABLE__, TRUE)
    CFLAGS += -D__WATCHDOG_RESTART_DISABLE__
  endif
  ifeq ($(strip $(COMPONENT)),nucleus_v2_ctrl_code)
    ADEFS       +=  $(call ADEFTrans,__WATCHDOG_RESTART_DISABLE__, TRUE)
    CFLAGS += -D__WATCHDOG_RESTART_DISABLE__
  endif
endif

ifeq ($(strip $(FLASH_TEST_SELECT)),NOR_FLASH)
  ifeq ($(strip $(COMPONENT)),nucleus_ctrl_code)
    ADEFS       +=  $(call ADEFTrans,__WATCHDOG_RESTART_DISABLE__, TRUE)
    CFLAGS += -D__WATCHDOG_RESTART_DISABLE__
  endif
  ifeq ($(strip $(COMPONENT)),nucleus_v2_ctrl_code)
    ADEFS       +=  $(call ADEFTrans,__WATCHDOG_RESTART_DISABLE__, TRUE)
    CFLAGS += -D__WATCHDOG_RESTART_DISABLE__
  endif
endif

ifdef GADGET_SUPPORT
ifneq ($(strip $(GADGET_SUPPORT)),NONE)
    ADEFS       +=  $(call ADEFTrans,__GADGET_SUPPORT__, TRUE)
endif
endif

ifeq ($(strip $(KEYPAD_DEBUG_TRACE)),TRUE)
  ADEFS       +=  $(call ADEFTrans,__KEYPAD_DEBUG_TRACE__, TRUE)
endif

ifeq ($(strip $(ZIMAGE_SUPPORT)),TRUE)
  ADEFS       +=  $(call ADEFTrans,__ZIMAGE_SUPPORT__, TRUE)
endif

ifneq ($(filter $(strip $(PLATFORM)),$(ARM9_PLATFORM)),)
  ADEFS       +=  $(call ADEFTrans,ARM9_MMU, TRUE) 
endif

ifneq ($(filter $(strip $(PLATFORM)),$(ARM11_PLATFORM)),)
  ADEFS       +=  $(call ADEFTrans,$(strip $(PLATFORM)), TRUE)
  ADEFS       +=  $(call ADEFTrans,ARM11_MMU, TRUE) 
  ADEFS       +=  $(call ADEFTrans,__ARM1176__, TRUE) 
  ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    ADEFS       +=  $(call ADEFTrans,_NAND_FLASH_BOOTING_, TRUE)
  endif
endif

ifneq ($(filter $(strip $(PLATFORM)),$(CR4_PLATFORM)),)
  ADEFS       +=  $(call ADEFTrans,$(strip $(PLATFORM)), TRUE)
  ADEFS       +=  $(call ADEFTrans,CR4, TRUE) 
endif

ifneq ($(filter MT6251 MT6252 MT6253L,$(PLATFORM)),)
  ADEFS       +=  $(call ADEFTrans,__SERIAL_FLASH_EN__, TRUE)
endif

ifeq ($(strip $(PLATFORM)),MT6256)
  ADEFS       +=  $(call ADEFTrans,ESAL_AR_STK_FPU_SUPPORT, TRUE)
  ADEFS       +=  $(call ADEFTrans,__ARM_FPUV2__, TRUE) 
#else
#  ADEFS       +=  $(call ADEFTrans,ESAL_AR_STK_FPU_SUPPORT, FALSE)
#  ADEFS       +=  $(call ADEFTrans,__ARM_FPUV2__, FALSE) 
endif

ifeq ($(strip $(USB_BOOTUP_TRACE)),TRUE)
  ADEFS       +=  $(call ADEFTrans,__USB_BOOTUP_TRACE__, TRUE)
endif

ifeq ($(strip $(SERIAL_FLASH_SUPPORT)),TRUE)
  ADEFS       +=  $(call ADEFTrans,__SERIAL_FLASH_EN__, TRUE)
  CFLAGS += -D__SERIAL_FLASH_EN__
  ADEFS       +=  $(call ADEFTrans,__SERIAL_FLASH_SUPPORT__, TRUE)
  CFLAGS += -D__SERIAL_FLASH_SUPPORT__
endif

## end of ADEFS

# if any component needs to interwork with other ARM mode components, it should
# add "APCS_INTWORK" into its .def
ifneq ($(filter -DAPCS_INTWORK,$(CDEFS)),)
  CINTWORK    =  $(APCSINT)
  AINTWORK    =  $(APCSINT)
else
  CINTWORK    =
  AINTWORK    =
endif

# Compiler settings for specific components
#the following will be removed after *.def are updated
ifeq ($(strip $(COMPONENT)),kal)
  CINTWORK    =  $(APCSINT)
  AINTWORK    =  $(APCSINT)
endif
ifneq ($(filter __HSUPA_SUPPORT__, $(MODULE_DEFS)),)
  ifneq ($(filter nucleus_v2%, $(COMPONENT)),)
    CINTWORK    =  $(APCSINT)
    AINTWORK    =  $(APCSINT)
    ifeq ($(strip $(COMPILER)),GCC)
      CFLAGS += -O3
    else
      CFLAGS += -Otime
    endif
  endif
endif #  __HSUPA_SUPPORT__

ifeq ($(strip $(COMPONENT)),dp_engine)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
   ifeq ($(strip $(COMPILER)),GCC)
      CFLAGS += -O3
   else
      CFLAGS += -Otime -Ono_autoinline
   endif
endif
ifneq ($(filter bootloader bootloader_ext,$(strip $(COMPONENT))),)
   CINTWORK    =  $(APCSINT)
   AINTWORK    =  $(APCSINT)
endif

ifeq ($(strip $(COMPONENT)),lgoem)
  CFLAGS      := --cpu ARM9EJ-S   --apcs /noswst/interwork -O3 -Ospace --dwarf2
  CFLAGS      += --thumb  --no_data_reorder  --pointer_alignment=4  --no_dollar
  CFLAGS      += --no_multibyte_chars  --alternative_tokens --loose_implicit_cast
  CFLAGS      += --diag_suppress  1,9,47,66,174,177,550,940,2874
endif

ifeq ($(strip $(COMPILER)),RVCT)
   CFLAGS += --bss_threshold=0
   CPLUSFLAGS += --bss_threshold=0
endif

ifeq ($(strip $(COMPILER)),GCC)
   depend = -MMD -MF
   AS_depend = -MD
else
   depend = --depend
   AS_depend = --depend
endif   



ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  ifeq ($(strip $(MODIS_COMPILER)),MINGW)
    CFLAGS := $(CFLAGS_MODIS)
    CPLUSFLAGS := $(CFLAGS)
    LIB := $(LIB_MODIS)
  endif
endif


# Generate module information
ifeq ($(strip $(GEN_MODULE_INFO)),TRUE)

COMP_TEMP:=$(shell $(IF_NOT_EXIST) $(strip $(MODULE_FOLDER)) $(THEN) $(MKDIR) $(strip $(MODULE_FOLDER)) $(CMD_END))
COMP_TEMP:=$(shell $(IF_EXIST) $(strip $(COMPONENT_FOLDER)) $(THEN) $(DEL_DIR) $(strip $(COMPONENT_FOLDER)) $(CMD_END))
COMP_TEMP:=$(shell $(IF_NOT_EXIST) $(strip $(COMPONENT_FOLDER)) $(THEN) $(MKDIR) $(strip $(COMPONENT_FOLDER)) $(CMD_END))

ifneq ($(words $(SRC_LIST)),0)
  ifeq ($(call lte,$(call strlen,$(SRC_LIST)),32000),T)
    COMP_TEMP:=$(shell perl tools/echoLongString4.pl $(COMPONENT_LOG).lis $(SRC_LIST))
    COMP_TEMP:=$(shell perl tools/lnitem.pl $(COMPONENT_LOG).lis)
  else
    COMP_TEMP:=$(foreach com,$(SRC_LIST),$(shell echo $(com)>>$(COMPONENT_LOG).lis))
  endif
else
  COMP_TEMP:=$(shell $(ECHO) "" >$(COMPONENT_LOG).lis)
endif

ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  ifneq ($(words $(INCDIRS)),0)
    ifeq ($(call lte,$(call strlen,$(INCDIRS)),32000),T)
      COMP_TEMP:=$(shell $(STRCMPEX) abc abc e $(COMPONENT_LOG).inc $(subst \,/,$(INCDIRS)))
      COMP_TEMP:=$(shell perl tools/lnitem.pl $(COMPONENT_LOG).inc)
    else
      COMP_TEMP:=$(foreach com,$(INCDIRS),$(shell echo $(subst \,/,$(com)) >>$(COMPONENT_LOG).inc))
    endif
  else
    COMP_TEMP:=$(shell $(ECHO) "" >$(COMPONENT_LOG).inc)
  endif
else
  ifneq ($(words $(INC_DIR)),0)
    ifeq ($(call lte,$(call strlen,$(INC_DIR)),32000),T)
      ifeq ($(strip $(COMPILER)),GCC)
        COMP_TEMP:=$(shell $(STRCMPEX) abc abc e $(COMPONENT_LOG).inc $(subst \,/,$(INC_DIR)))
      else
        COMP_TEMP:=$(shell $(STRCMPEX) abc abc e $(COMPONENT_LOG).inc $(INC_DIR))
      endif
      COMP_TEMP:=$(shell perl tools/lnitem.pl $(COMPONENT_LOG).inc)
    else
      ifeq ($(strip $(COMPILER)),GCC)
        COMP_TEMP:=$(foreach com,$(INC_DIR),$(shell echo $(subst \,/,$(com)) >>$(COMPONENT_LOG).inc))
      else
        COMP_TEMP:=$(foreach com,$(INC_DIR),$(shell echo $(com) >>$(COMPONENT_LOG).inc))
      endif
    endif
  else
    COMP_TEMP:=$(shell $(ECHO) "" >$(COMPONENT_LOG).inc)
  endif
endif

ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  ifneq ($(words $(DEFINES)),0)
    ifeq ($(call lte,$(call strlen,$(DEFINES)),32000),T)
      COMP_TEMP:=$(shell perl tools/echoLongString4.pl $(COMPONENT_LOG).def $(DEFINES))
      COMP_TEMP:=$(shell perl tools/lnitem.pl $(COMPONENT_LOG).def)
    else
      COMP_TEMP:=$(foreach def,$(DEFINES),$(shell echo $(def) >>$(COMPONENT_LOG).def))
    endif
  else
    COMP_TEMP:=$(shell $(ECHO) "" >$(COMPONENT_LOG).def)
  endif
else
  ifneq ($(words $(COMP_DEFS)),0)
    COMP_TEMP:=$(shell perl tools/echoLongString4.pl $(COMPONENT_LOG).def $(COMP_DEFS))
    COMP_TEMP:=$(shell perl tools/lnitem.pl $(COMPONENT_LOG).def)
  else
    COMP_TEMP:=$(shell $(ECHO) "" >$(COMPONENT_LOG).def)
  endif
endif

ifneq ($(strip $(MODIS_CONFIG)),TRUE)
  COMP_TEMP:=$(shell perl tools/echoLongString5.pl $(COMPONENT_LOG).ade ADEFS $(ADEFS))
endif

else ifeq ($(filter $(MAKECMDGOALS),setup_env),)
  SRC_LIST_OUT := $(filter-out %.rec %.ico %.rc %.bmp %.h,$(SRC_LIST))
  SRC_LIST_TMP := $(foreach file,$(sort $(call Lower,$(SRC_LIST_OUT))),$(if $(filter $(basename $(notdir $(file))),$(basename $(notdir $(filter-out $(file),$(call Lower,$(SRC_LIST_OUT)))))),$(file),))
  ifneq ($(strip $(SRC_LIST_TMP)),)
    $(info The following files are conflicted in SRC_LIST from $(strip $(COMPONENT)).mak:)
    $(info $(strip $(SRC_LIST_TMP)))
    $(error SRC_LIST)
  endif
endif
# end

# *************************************************************************
# Library Targets
# *************************************************************************
update_lib: $(TARGLIB)
	@$(IF_EXIST) $(COMPDETS_DIR) $(THEN) $(DEL_DIR) $(COMPDETS_DIR) $(CMD_END)

$(TARGLIB):
   # If library for customer release exists.
   # Copy and update it or create a new one
   # mbis time probe
ifeq ($(strip $(MBIS_EN_OBJ_LOG)),TRUE)
	@$(ECHO) -n -t "T_S,$@,L," >> $(COMPLOGDIR)/mbis/$(strip $(COMPONENT))/$(basename $(notdir $@))".mbis"
endif
	@$(IF_EXIST) $(OBJ_ARCHIVE) $(THEN)\
		($(DEL_FILE) $(OBJ_ARCHIVE)) $(CMD_END)
	@$(IF_EXIST) $(OBJ_ARCHIVE_SORT) $(THEN)\
		($(DEL_FILE) $(OBJ_ARCHIVE_SORT)) $(CMD_END)

	@$(FOR) $(F_OPT) $(DECLARE_VAR)i $(IN) `$(LIST_DIR) -n "$(COMPOBJS_DIR)/*.obj"` \
	$(DO) \
		$(ECHO) -n $(PRE_VAR)i>>$(OBJ_ARCHIVE)\
	$(DONE)
	@perl ./tools/sortobj.pl $(OBJ_ARCHIVE) $(OBJ_ARCHIVE_SORT)

ifneq ($(filter $(PARTIAL_TRACE_LIB),$(COMPONENT)),)
	@$(IF_EXIST) $(FIXPATH)/$(CUS_MTK_LIB_TRACE)/lib$(strip $(COMPONENT)).a $(THEN)\
		($(COPY_FILE) $(FIXPATH)/$(CUS_MTK_LIB_TRACE)/lib$(strip $(COMPONENT)).a $(TARGLIB))\
	$(CMD_END)
else
	@$(IF_EXIST) $(FIXPATH)/$(CUS_MTK_LIB)/lib$(strip $(COMPONENT)).a $(THEN)\
		($(COPY_FILE) $(FIXPATH)/$(CUS_MTK_LIB)/lib$(strip $(COMPONENT)).a $(TARGLIB)) \
	$(CMD_END)
endif

ifneq ($(strip $(MODIS_CONFIG)),TRUE)
  ifeq ($(strip $(COMPILER)),GCC)
	@$(strip $(LIB)) -r $(TARGLIB) $(VIA)$(OBJ_ARCHIVE_SORT)
  else
	@$(strip $(LIB)) -create $(TARGLIB) $(VIA)$(OBJ_ARCHIVE_SORT)
  endif
else
  ifeq ($(strip $(MODIS_COMPILER)),MINGW)
	@$(strip $(LIB)) -r $(TARGLIB) $(VIA)$(OBJ_ARCHIVE_SORT)
  endif
endif

	@$(ECHO) -n "$(TARGLIB) is updated"

	@$(IF_EXIST) $(OBJ_ARCHIVE) $(THEN)\
		($(DEL_FILE) $(OBJ_ARCHIVE)) $(CMD_END)
	@$(IF_EXIST) $(OBJ_ARCHIVE_SORT) $(THEN)\
		($(DEL_FILE) $(OBJ_ARCHIVE_SORT)) $(CMD_END)

ifneq ($(ACTION),remake)
  ifneq ($(strip $(MODIS_CONFIG)),TRUE)
    ifeq ($(strip $(COMPILER)),GCC)
	@$(IF_EXIST) $(COMPDETS_DIR) $(THEN) \
		perl ./tools/pack_dep_gcc.pl $(TARGDEP) $(COMPDETS_DIR) $(HTOGETHER) $(strip $(HEADER_TEMP))\
		$(CMD_END)
    else ifeq ($(strip $(COMPILER)),RVCT)
	@$(IF_EXIST) $(TARGDEP) $(THEN)\
			$(IF_EXIST) $(COMPDETS_DIR)/*.det $(THEN)\
				$(CAT) $(COMPDETS_DIR)/*.det >>$(TARGDEP)
			$(CMD_END)\
		$(CMD_END)
	@$(IF_NOT_EXIST) $(TARGDEP) $(THEN)\
			$(IF_EXIST) $(COMPDETS_DIR)/*.det $(THEN)\
				$(CAT) $(COMPDETS_DIR)/*.det >$(TARGDEP)
			$(CMD_END)\
		$(CMD_END)
	@$(IF_EXIST) $(COMPDETS_DIR)/*.det $(THEN)\
			$(DEL_FILE) $(COMPDETS_DIR)/*.det \
		$(CMD_END)
    endif
  else
    ifeq ($(strip $(MODIS_COMPILER)),MINGW)
	@$(IF_EXIST) $(COMPDETS_DIR) $(THEN) perl ./tools/pack_dep_gcc.pl $(TARGDEP) $(COMPDETS_DIR) $(HTOGETHER) $(strip $(HEADER_TEMP)) $(CMD_END)
    endif
  endif
  ifneq ($(PCIBT_ACTION_LIST),)
	$(PCIBT_SCRIPT_CMD) $(TARGDEP) $(PCIBT_ACTION_LIST)
  endif
endif
	@$(IF_EXIST) $(COMPDETS_DIR) $(THEN)\
		$(DEL_DIR) $(COMPDETS_DIR)\
	$(CMD_END)
   # mbis time probe
ifeq ($(strip $(MBIS_EN_OBJ_LOG)),TRUE)
	@$(ECHO) -n -t "T_E,$@,L," >> $(COMPLOGDIR)/mbis/$(strip $(COMPONENT))/$(basename $(notdir $@))".mbis"
endif


RUN_SETUP_ENV := TRUE
ifeq ($(strip $(GEN_MODULE_INFO)),TRUE)
  RUN_SETUP_ENV := FALSE
endif
ifeq ($(strip $(MODIS_CONFIG)),TRUE)
  ifeq ($(strip $(MODIS_COMPILER)),VC2008)
    RUN_SETUP_ENV := FALSE
  endif
endif

setup_env:
ifeq ($(strip $(RUN_SETUP_ENV)),TRUE)
	@$(IF_NOT_EXIST) $(COMPVIA_DIR) $(THEN) $(MKDIR) $(COMPVIA_DIR) $(CMD_END)
	@$(STRCMPEX) abc abc e $(COMPVIA_DIR)/$(strip $(COMPONENT)).via $(CINTWORK) $(CDEFS)
	@$(STRCMPEX) abc abc e $(COMPVIA_DIR)/$(strip $(COMPONENT))_inc.via $(CINCDIRS)
ifeq ($(strip $(OS_VERSION)),MSWin32)
	@tools\warp.exe $(subst /,\,$(COMPVIA_DIR))\$(strip $(COMPONENT)).via
	@tools\warp.exe $(subst /,\,$(COMPVIA_DIR))\$(strip $(COMPONENT))_inc.via
endif
	@$(IF_NOT_EXIST) $(COMPLOGDIR)/$(strip $(COMPONENT)) $(THEN) $(MKDIR) $(COMPLOGDIR)/$(strip $(COMPONENT)) $(CMD_END)
	@$(IF_NOT_EXIST) $(COMPDETS_DIR) $(THEN) $(MKDIR) $(COMPDETS_DIR) $(CMD_END)
	@$(IF_NOT_EXIST) $(COMPOBJS_DIR) $(THEN) $(MKDIR) $(COMPOBJS_DIR) $(CMD_END)
  ifneq ($(strip $(MODIS_CONFIG)),TRUE)
  ifdef SRC_RULE_AUTOTCM
  ifneq ($(strip $(SRC_RULE_AUTOTCM)),)
	@$(IF_EXIST) $(strip $(COMPLOGDIR))/$(strip $(COMPONENT))_auto_tcm.log $(THEN) $(DEL_FILE) $(strip $(COMPLOGDIR))/$(strip $(COMPONENT))_auto_tcm.log $(CMD_END)
	@$(IF_NOT_EXIST) $(PROJ_INTERNAL_DIR)/auto_tcm/$(strip $(COMPONENT)) $(THEN) $(MKDIR) $(PROJ_INTERNAL_DIR)/auto_tcm/$(strip $(COMPONENT)) $(CMD_END)
  endif
  endif
  endif
else
  ifneq ($(strip $(MODIS_CONFIG)),TRUE)
	@echo Generating $(COMPONENT) information is done.
  else
	@echo $(COMPONENT) MoDIS module setup is done.
  endif
endif
ifneq ($(PCIBT_ACTION_LIST),)
  ifeq ($(strip $(RUN_SETUP_ENV)),TRUE)
	$(PCIBT_SCRIPT_CMD) $(COMPONENT_LOG).lis,$(COMPVIA_DIR)/$(strip $(COMPONENT))_inc.via $(PCIBT_ACTION_LIST)
  else
	$(PCIBT_SCRIPT_CMD) $(COMPONENT_LOG).lis,$(COMPONENT_LOG).inc $(PCIBT_ACTION_LIST)
  endif
endif

# *************************************************************************
# Dependency Targets
# *************************************************************************
update_dep: $(TARGDEP)
	@$(IF_EXIST) $(COMPDETS_DIR) $(THEN) $(DEL_DIR) $(COMPDETS_DIR) $(CMD_END)

$(TARGDEP):
   # mbis time probe
ifeq ($(strip $(MBIS_EN_OBJ_LOG)),TRUE)
	@$(ECHO) -n -t "T_S,$@,D," >> $(COMPLOGDIR)/mbis/$(strip $(COMPONENT))/$(basename $(notdir $@))".mbis"
endif
ifneq ($(strip $(MODIS_CONFIG)),TRUE)
  ifeq ($(strip $(COMPILER)),GCC)
	@$(IF_EXIST) $(COMPDETS_DIR) $(THEN) \
		perl ./tools/pack_dep_gcc.pl $(TARGDEP) $(COMPDETS_DIR) $(HTOGETHER) $(strip $(HEADER_TEMP))\
	$(CMD_END)
	@$(IF_EXIST) $(COMPDETS_DIR) $(THEN) \
		$(DEL_DIR) $(COMPDETS_DIR)\
	$(CMD_END)
  else
	@$(IF_EXIST) $(TARGDEP) $(THEN)\
		$(LIST_DIR) "$(COMPDETS_DIR)/*.det" >$(DEV_NUL) 2>&1 $(WITH)\
		$(IF_ERR_FALSE) $(THEN) \
			$(CAT) $(COMPDETS_DIR)/*.det >>$(TARGDEP)\
		$(CMD_END)\
	$(CMD_END)
	@$(IF_NOT_EXIST) $(TARGDEP) $(THEN) \
		$(LIST_DIR) "$(COMPDETS_DIR)/*.det" >$(DEV_NUL) 2>&1 $(WITH)\
		$(IF_ERR_FALSE) $(THEN)\
			$(CAT) $(COMPDETS_DIR)/*.det >$(TARGDEP)\
		$(CMD_END)\
	$(CMD_END)
	@$(LIST_DIR) "$(COMPDETS_DIR)/*.det" >$(DEV_NUL) 2>&1 $(WITH)\
		$(IF_ERR_FALSE) $(THEN)\
			$(DEL_FILE) $(COMPDETS_DIR)/*.det\
		$(CMD_END)
  endif
else
  ifeq ($(strip $(MODIS_COMPILER)),MINGW)
	@$(IF_EXIST) $(COMPDETS_DIR) $(THEN) perl ./tools/pack_dep_gcc.pl $(TARGDEP) $(COMPDETS_DIR) $(HTOGETHER) $(strip $(HEADER_TEMP)) $(CMD_END)
  endif
endif
	@$(IF_EXIST) $(COMPDETS_DIR) $(THEN)\
		$(DEL_DIR) $(COMPDETS_DIR)\
	$(CMD_END)
ifneq ($(PCIBT_ACTION_LIST),)
	$(PCIBT_SCRIPT_CMD) $(TARGDEP) $(PCIBT_ACTION_LIST)
endif
   # mbis time probe
ifeq ($(strip $(MBIS_EN_OBJ_LOG)),TRUE)
	@$(ECHO) -n -t "T_E,$@,D," >> $(COMPLOGDIR)/mbis/$(strip $(COMPONENT))/$(basename $(notdir $@))".mbis"
endif

# *************************************************************************
# Component Targets
# *************************************************************************
# %.obj: %.c
# %.obj: %.cpp
define target_compile_c_obj
$(2): $(1)
   # mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_S,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
	@echo Compiling $$< ... >$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
ifeq ($$(strip $$(ACTION)),remake)
	$(3) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT)).via $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via -c $$(CFLAGS) -o $$(COMPOBJS_DIR)/$$(notdir $$@) $$< 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
else
	$(3) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT)).via $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via -c $$(CFLAGS) $$(depend) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d -o $$(COMPOBJS_DIR)/$$(notdir $$@) $$< 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
  ifeq ($$(strip $$(COMPILER)),GCC)
  else ifeq ($$(strip $$(COMPILER)),RVCT)
	@$$(IF_EXIST) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(THEN) \
		perl ./tools/pack_dep.pl $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(HTOGETHER) $$(strip $$(HEADER_TEMP)) >$$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).det \
	$$(CMD_END)
	@$$(IF_EXIST) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(THEN) \
		$$(DEL_FILE) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d \
	$$(CMD_END)
  endif
endif
   # mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_E,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
endef

# %.obj: %.c (tcm)
# %.obj: %.cpp (tcm)
define target_compile1_c_obj
$(2): $(1) $$(NEED_CHECK_DEPEND_LIST) ./tools/auto_tcm_attribute.pl $$(filter-out NO_LIST,$$(TARGET_AUTOTCM_LIST))
   # mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_S,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
	@echo Pre-compiling $$< ... >$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
ifeq ($$(strip $$(ACTION)),remake)
	$(3) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT)).via $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via -E -o $$(PROJ_INTERNAL_DIR)/auto_tcm/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).c $$< 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
else
  ifeq ($$(strip $$(COMPILER)),GCC)
	$(3) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT)).via $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via -E $$(depend) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d -o $$(PROJ_INTERNAL_DIR)/auto_tcm/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).c $$< 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
  else ifeq ($$(strip $$(COMPILER)),RVCT)
	$(3) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT)).via $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via -E -o $$(PROJ_INTERNAL_DIR)/auto_tcm/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).c $$< 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
	@$(3) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT)).via $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via -M $$< >$$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
	@$$(IF_EXIST) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(THEN) (perl ./tools/pack_dep.pl $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(HTOGETHER) $$(strip $$(HEADER_TEMP)) >$$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).det) $$(CMD_END)
	@$$(IF_EXIST) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(THEN) ($$(DEL_FILE) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d) $$(CMD_END)
  endif
endif
ifneq ($$(strip $$(MODIS_CONFIG)),TRUE)
ifneq ($$(filter-out NO_LIST,$$(TARGET_AUTOTCM_LIST)),)
# writing the same log at the same time is protected by OS
	@perl ./tools/auto_tcm_attribute.pl $$(PROJ_INTERNAL_DIR)/auto_tcm/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).c $$(TARGET_AUTOTCM_LIST) $$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))_auto_tcm.log >>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log 2>&1
endif
endif
	@echo $(3) -c $$(CFLAGS) -o $$(COMPOBJS_DIR)/$$(notdir $$@) $$(PROJ_INTERNAL_DIR)/auto_tcm/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).c
	@$(3) -c $$(CFLAGS) -o $$(COMPOBJS_DIR)/$$(notdir $$@) $$(PROJ_INTERNAL_DIR)/auto_tcm/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).c 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
   # mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_E,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
endef

# %.det: %.c
# %.det: %.cpp
define target_scan_c_det
$(2): $(1)
   # mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_S,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
	@echo Pre-compiling $$< ... >$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
	@$(3) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT)).via $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via -M $$< >$$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
ifeq ($$(strip $$(COMPILER)),GCC)
else ifeq ($$(strip $$(COMPILER)),RVCT)
	@$$(IF_EXIST) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(THEN) \
		perl ./tools/pack_dep.pl $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(HTOGETHER) $$(strip $$(HEADER_TEMP)) >$$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).det \
	$$(CMD_END)
	@$$(IF_EXIST) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(THEN) \
		$$(DEL_FILE) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d \
	$$(CMD_END)
endif
   # mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_E,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
endef

# %.obj: %.s
define target_compile_asm_obj
$(2): $(1)
   # mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_S,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
	@echo Compiling $$< ... >$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
ifeq ($$(strip $$(ACTION)),remake)
	@$$(ASM) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via $$(AINTWORK) $$(AFLAGS) $$(ADEFS) $$< -o $$(COMPOBJS_DIR)/$$(notdir $$@) 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
else
	@$$(ASM) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via $$(AINTWORK) $$(AFLAGS) $$(ADEFS) $$< $$(AS_depend) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d -o $$(COMPOBJS_DIR)/$$(notdir $$@) 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
  ifeq ($$(strip $$(COMPILER)),GCC)
  else ifeq ($$(strip $$(COMPILER)),RVCT)
	@$$(IF_EXIST) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(THEN) \
		perl ./tools/pack_dep.pl $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(HTOGETHER) $$(strip $$(HEADER_TEMP)) >$$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).det \
	$$(CMD_END)
	@$$(IF_EXIST) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(THEN) \
		$$(DEL_FILE) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d \
	$$(CMD_END)
  endif
endif
# mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_E,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
endef

# %.det: %.s
define target_scan_asm_det
$(2): $(1)
   # mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_S,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
	@echo Pre-compiling $$< ... >$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
ifeq ($$(strip $$(COMPILER)),GCC)
#
#	@$$(ASM) $$(AINTWORK) $$(AFLAGS) $$(ADEFS) -M $$< >$$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
#
else ifeq ($$(strip $$(COMPILER)),RVCT)
	@$$(ASM) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via $$(AINTWORK) $$(AFLAGS) $$(ADEFS) -M $$< >$$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
	@$$(IF_EXIST) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(THEN) \
		perl ./tools/pack_dep.pl $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(HTOGETHER) $$(strip $$(HEADER_TEMP)) >$$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).det \
	$$(CMD_END)
	@$$(IF_EXIST) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(THEN) \
		$$(DEL_FILE) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d \
	 $$(CMD_END)
endif
   # mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_E,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
endef

# %.obj: %.s (-32)
define target_compile1_asm_obj
$(2): $(1)
   # mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_S,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
	@echo Compiling $$< ... >$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
ifeq ($$(strip $$(ACTION)),remake)
  ifeq ($$(strip $$(COMPILER)),GCC)
	@$$(ASM) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via $$(AINTWORK) $$(AFLAGS) $$(ADEFS) -mapcs-32 $$< -o $$(COMPOBJS_DIR)/$$(notdir $$@) 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
  else ifeq ($$(strip $$(COMPILER)),RVCT)
	@$$(ASM) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via $$(AINTWORK) $$(AFLAGS) $$(ADEFS) -32 $$< -o $$(COMPOBJS_DIR)/$$(notdir $$@) 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
  endif
else
  ifeq ($$(strip $$(COMPILER)),GCC)
	@$$(ASM) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via $$(AINTWORK) $$(AFLAGS) $$(ADEFS) -mapcs-32 $$< $$(AS_depend) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d -o $$(COMPOBJS_DIR)/$$(notdir $$@) 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
  else ifeq ($$(strip $$(COMPILER)),RVCT)
	@$$(ASM) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via $$(AINTWORK) $$(AFLAGS) $$(ADEFS) -32 $$< $$(AS_depend) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d -o $$(COMPOBJS_DIR)/$$(notdir $$@) 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
	@$$(IF_EXIST) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(THEN) \
		perl ./tools/pack_dep.pl $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(HTOGETHER) $$(strip $$(HEADER_TEMP)) >$$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).det \
	$$(CMD_END)
	@$$(IF_EXIST) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(THEN) \
		$$(DEL_FILE) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d \
	$$(CMD_END)
  endif
endif
# mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_E,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
endef

# %.obj: %.s (preprocess)
define target_compile2_asm_obj
$(2): $(1)
   # mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_S,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
	@echo Pre-compiling $$< ... >$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
	@$$(STRCMPEX) abc abc e $$(COMPVIA_DIR)/$$(basename $$(notdir $$@))_det.via $$(A_CDEFS) -D$$(strip $$(PLATFORM))_$$(strip $$(CHIP_VER))=$$(strip $$(PLATFORM))_$$(strip $$(CHIP_VER))
ifeq ($$(strip $$(OS_VERSION)),MSWin32)
	@tools\warp.exe $$(COMPVIA_DIR)\$$(basename $$(notdir $$@))_det.via
endif
ifeq ($$(strip $$(ACTION)),remake)
	@$$(CC) $$(VIA)$$(COMPVIA_DIR)/$$(basename $$(notdir $$@))_det.via $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via -E $$< -o $$(COMPOBJS_DIR)/$$(basename $$(notdir $$@)).s >>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
else
  ifeq ($$(strip $$(COMPILER)),GCC)
	@$$(CC) $$(VIA)$$(COMPVIA_DIR)/$$(basename $$(notdir $$@))_det.via $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via -E $$< $$(depend) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d -o $$(COMPOBJS_DIR)/$$(basename $$(notdir $$@)).s >>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
  else ifeq ($$(strip $$(COMPILER)),RVCT)
	@$$(CC) $$(VIA)$$(COMPVIA_DIR)/$$(basename $$(notdir $$@))_det.via $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via -E $$< -o $$(COMPOBJS_DIR)/$$(basename $$(notdir $$@)).s >>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
	@$$(CC) $$(VIA)$$(COMPVIA_DIR)/$$(basename $$(notdir $$@))_det.via $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via -M $$< >$$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
  endif
endif
	@echo Compiling $$< ... >>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
ifeq ($$(strip $$(ACTION)),remake)
	@$$(ASM) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via $$(AINTWORK) $$(AFLAGS) $$(ADEFS) $$(COMPOBJS_DIR)/$$(basename $$(notdir $$@)).s -o $$(COMPOBJS_DIR)/$$(notdir $$@) 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
else
	@$$(ASM) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via $$(AINTWORK) $$(AFLAGS) $$(ADEFS) $$(COMPOBJS_DIR)/$$(basename $$(notdir $$@)).s $$(AS_depend) $$(COMPDETS_DIR)/~$$(basename $$(notdir $$@)).d -o $$(COMPOBJS_DIR)/$$(notdir $$@) 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
	@$$(IF_EXIST) $$(COMPDETS_DIR)/~$$(basename $$(notdir $$@)).d $$(THEN) \
		$$(CAT) $$(COMPDETS_DIR)/~$$(basename $$(notdir $$@)).d | $$(GREP_V) "$$(basename $$(notdir $$@)).s" >>$$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(WITH) (exit 0)\
	$$(CMD_END)
	@$$(IF_EXIST) $$(COMPDETS_DIR)/~$$(basename $$(notdir $$@)).d $$(THEN) \
		$$(DEL_FILE) $$(COMPDETS_DIR)/~$$(basename $$(notdir $$@)).d\
	$$(CMD_END)
  ifeq ($$(strip $$(COMPILER)),GCC)
  else ifeq ($$(strip $$(COMPILER)),RVCT)
	@$$(IF_EXIST) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(THEN) \
		perl ./tools/pack_dep.pl $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(HTOGETHER) $$(strip $$(HEADER_TEMP)) >$$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).det \
	$$(CMD_END)
	@$$(IF_EXIST) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(THEN) \
		$$(DEL_FILE) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d \
	$$(CMD_END)
  endif
endif

   # mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_E,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
endef

# %.det: %.s (preprocess)
define target_scan2_asm_det
$(2): $(1)
   # mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_S,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
	@echo Pre-compiling $$< ... >$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
	@$$(STRCMPEX) abc abc e $$(COMPVIA_DIR)/$$(basename $$(notdir $$@))_det.via $$(A_CDEFS) -D$$(strip $$(PLATFORM))_$$(strip $$(CHIP_VER))=$$(strip $$(PLATFORM))_$$(strip $$(CHIP_VER)) $$(CINCDIRS)
ifeq ($$(strip $$(OS_VERSION)),MSWin32)
	@tools\warp.exe $$(COMPVIA_DIR)\$$(basename $$(notdir $$@))_det.via
endif
ifeq ($$(strip $$(COMPILER)),GCC)
	@$$(CC) $$(VIA)$$(COMPVIA_DIR)/$$(basename $$(notdir $$@))_det.via $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via -E $$< $$(depend) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d -o $$(COMPOBJS_DIR)/$$(basename $$(notdir $$@)).s >>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
#
#	$$(ASM) $$(AINTWORK) $$(AFLAGS) $$(ADEFS) -M $$(COMPOBJS_DIR)/$$(basename $$(notdir $$@)).s >$$(COMPDETS_DIR)/~$$(basename $$(notdir $$@)).d
#
else ifeq ($$(strip $$(COMPILER)),RVCT)
	@$$(CC) $$(VIA)$$(COMPVIA_DIR)/$$(basename $$(notdir $$@))_det.via $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via -E $$< -o $$(COMPOBJS_DIR)/$$(basename $$(notdir $$@)).s >>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
	@$$(CC) $$(VIA)$$(COMPVIA_DIR)/$$(basename $$(notdir $$@))_det.via $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via -M $$< >$$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
	@$$(ASM) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via $$(AINTWORK) $$(AFLAGS) $$(ADEFS) -M $$(COMPOBJS_DIR)/$$(basename $$(notdir $$@)).s >$$(COMPDETS_DIR)/~$$(basename $$(notdir $$@)).d
endif
	@$$(IF_EXIST) $$(COMPDETS_DIR)/~$$(basename $$(notdir $$@)).d $$(THEN) \
		$$(CAT) $$(COMPDETS_DIR)/~$$(basename $$(notdir $$@)).d | $$(GREP_V) "$$(basename $$(notdir $$@)).s" >>$$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(WITH) (exit 0)\
	$$(CMD_END)
	@$$(IF_EXIST) $$(COMPDETS_DIR)/~$$(basename $$(notdir $$@)).d $$(THEN) \
		$$(DEL_FILE) $$(COMPDETS_DIR)/~$$(basename $$(notdir $$@)).d\
	$$(CMD_END)
ifeq ($$(strip $$(COMPILER)),GCC)
else ifeq ($$(strip $$(COMPILER)),RVCT)
	@$$(IF_EXIST) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(THEN) \
		perl ./tools/pack_dep.pl $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(HTOGETHER) $$(strip $$(HEADER_TEMP)) >$$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).det \
	$$(CMD_END)
	@$$(IF_EXIST) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(THEN) \
		$$(DEL_FILE) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d \
	$$(CMD_END)
endif

   # mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_E,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
endef

# %.obj: %.s (preprocess and -32)
define target_compile3_asm_obj
$(2): $(1)
# mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_S,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
	@echo Pre-compiling $$< ... >$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
	@$$(STRCMPEX) abc abc e $$(COMPVIA_DIR)/$$(basename $$(notdir $$@))_det.via $$(A_CDEFS) -D$$(strip $$(PLATFORM))_$$(strip $$(CHIP_VER))=$$(strip $$(PLATFORM))_$$(strip $$(CHIP_VER))
ifeq ($$(strip $$(OS_VERSION)),MSWin32)
	@tools\warp.exe $$(COMPVIA_DIR)\$$(basename $$(notdir $$@))_det.via
endif
ifeq ($$(strip $$(ACTION)),remake)
	@$$(CC) $$(VIA)$$(COMPVIA_DIR)/$$(basename $$(notdir $$@))_det.via $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via -E $$< -o $$(COMPOBJS_DIR)/$$(basename $$(notdir $$@)).s >>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
else
  ifeq ($$(strip $$(COMPILER)),GCC)
	@$$(CC) $$(VIA)$$(COMPVIA_DIR)/$$(basename $$(notdir $$@))_det.via $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via -E $$< $$(depend) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d -o $$(COMPOBJS_DIR)/$$(basename $$(notdir $$@)).s >>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
  else ifeq ($$(strip $$(COMPILER)),RVCT)
	@$$(CC) $$(VIA)$$(COMPVIA_DIR)/$$(basename $$(notdir $$@))_det.via $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via -E $$< -o $$(COMPOBJS_DIR)/$$(basename $$(notdir $$@)).s >>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
	@$$(CC) $$(VIA)$$(COMPVIA_DIR)/$$(basename $$(notdir $$@))_det.via $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via -M $$< >$$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
  endif
endif
	@echo Compiling $$< ... >>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
ifeq ($$(strip $$(ACTION)),remake)
  ifeq ($$(strip $$(COMPILER)),GCC)
	@$$(ASM) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via $$(AINTWORK) $$(AFLAGS) $$(ADEFS) -mapcs-32 $$(COMPOBJS_DIR)/$$(basename $$(notdir $$@)).s -o $$(COMPOBJS_DIR)/$$(notdir $$@) 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
  else
	@$$(ASM) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via $$(AINTWORK) $$(AFLAGS) $$(ADEFS) -32 $$(COMPOBJS_DIR)/$$(basename $$(notdir $$@)).s -o $$(COMPOBJS_DIR)/$$(notdir $$@) 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
  endif
else
  ifeq ($$(strip $$(COMPILER)),GCC)
	@$$(ASM) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via $$(AINTWORK) $$(AFLAGS) $$(ADEFS) -mapcs-32 $$(COMPOBJS_DIR)/$$(basename $$(notdir $$@)).s $$(AS_depend) $$(COMPDETS_DIR)/~$$(basename $$(notdir $$@)).d -o $$(COMPOBJS_DIR)/$$(notdir $$@) 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
  else
	@$$(ASM) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via $$(AINTWORK) $$(AFLAGS) $$(ADEFS) -32 $$(COMPOBJS_DIR)/$$(basename $$(notdir $$@)).s $$(AS_depend) $$(COMPDETS_DIR)/~$$(basename $$(notdir $$@)).d -o $$(COMPOBJS_DIR)/$$(notdir $$@) 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
  endif
	@$$(IF_EXIST) $$(COMPDETS_DIR)/~$$(basename $$(notdir $$@)).d $$(THEN) \
		$$(CAT) $$(COMPDETS_DIR)/~$$(basename $$(notdir $$@)).d | $$(GREP_V) "$$(basename $$(notdir $$@)).s" >>$$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(WITH) (exit 0)\
	$$(CMD_END)
	@$$(IF_EXIST) $$(COMPDETS_DIR)/~$$(basename $$(notdir $$@)).d $$(THEN) \
		$$(DEL_FILE) $$(COMPDETS_DIR)/~$$(basename $$(notdir $$@)).d\
	$$(CMD_END)
  ifeq ($$(strip $$(COMPILER)),GCC)
  else ifeq ($$(strip $$(COMPILER)),RVCT)
	@$$(IF_EXIST) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(THEN) \
		perl ./tools/pack_dep.pl $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(HTOGETHER) $$(strip $$(HEADER_TEMP)) >$$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).det \
	$$(CMD_END)
	@$$(IF_EXIST) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d $$(THEN) \
		$$(DEL_FILE) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d \
	$$(CMD_END)
  endif
endif

   # mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_E,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
endef


# %.obj: %.c (MoDIS)
define modis_compile_c_obj
$(2): $(1)
   # mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_S,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
	@echo Compiling $$< ... >$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
ifeq ($$(strip $$(ACTION)),remake)
	$(3) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT)).via $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via -c $$(CFLAGS) -o $$(COMPOBJS_DIR)/$$(notdir $$@) $$< 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
else
	$(3) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT)).via $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via -c $$(CFLAGS) $$(depend) $$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d -o $$(COMPOBJS_DIR)/$$(notdir $$@) $$< 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
endif
   # mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_E,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
endef


# %.det: %.c (MoDIS)
define modis_scan_c_det
$(2): $(1)
   # mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_S,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
	@echo Pre-compiling $$< ... >$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
	@$(3) $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT)).via $$(VIA)$$(COMPVIA_DIR)/$$(strip $$(COMPONENT))_inc.via -M $$< >$$(COMPDETS_DIR)/$$(basename $$(notdir $$@)).d 2>>$$(strip $$(COMPLOGDIR))/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@)).log
   # mbis time probe
ifeq ($$(strip $$(MBIS_EN_OBJ_LOG)),TRUE)
	@$$(ECHO) -n -t "T_E,$$(@F),O," >> $$(strip $$(COMPLOGDIR))/mbis/$$(strip $$(COMPONENT))/$$(basename $$(notdir $$@))".mbis"
endif
endef


ifneq ($(strip $(MODIS_CONFIG)),TRUE)

$(foreach argu,$(CSRCS), \
  $(eval COBJ := $(patsubst %.C,%, $(patsubst %.c,%, $(patsubst %.cpp,%, $(notdir $(argu)))))) \
  $(eval $(call target_compile_c_obj,$(argu),$(COBJ).obj,$(CC))) \
  $(eval $(call target_scan_c_det,$(argu),$(COBJ).det,$(CC))) \
  $(eval $(TARGLIB): $(COBJ).obj) \
  $(eval TARGDEP_LIST += $(COBJ).det) \
)

$(foreach argu,$(CSRCS1), \
  $(eval COBJ1 := $(patsubst %.C,%, $(patsubst %.c,%, $(patsubst %.cpp,%, $(notdir $(argu)))))) \
  $(eval $(call target_compile1_c_obj,$(argu),$(COBJ1).obj,$(CC))) \
  $(eval $(call target_scan_c_det,$(argu),$(COBJ1).det,$(CC))) \
  $(eval $(TARGLIB): $(COBJ1).obj) \
  $(eval TARGDEP_LIST += $(COBJ1).det) \
)

$(foreach argu,$(CSRCS5), \
  $(eval COBJ5 := $(patsubst %.C,%, $(patsubst %.c,%, $(patsubst %.cpp,%, $(notdir $(argu)))))) \
  $(eval $(call target_compile_c_obj,$(argu),$(COBJ5).obj,$(CC32))) \
  $(eval $(call target_scan_c_det,$(argu),$(COBJ5).det,$(CC32))) \
  $(eval $(TARGLIB): $(COBJ5).obj) \
  $(eval TARGDEP_LIST += $(COBJ5).det) \
)

$(foreach argu,$(CSRCS6), \
  $(eval COBJ6 := $(patsubst %.C,%, $(patsubst %.c,%, $(patsubst %.cpp,%, $(notdir $(argu)))))) \
  $(eval $(call target_compile1_c_obj,$(argu),$(COBJ6).obj,$(CC32))) \
  $(eval $(call target_scan_c_det,$(argu),$(COBJ6).det,$(CC32))) \
  $(eval $(TARGLIB): $(COBJ6).obj) \
  $(eval TARGDEP_LIST += $(COBJ6).det) \
)

$(foreach argu,$(ASRCS), \
  $(eval AOBJ := $(patsubst %.S,%, $(patsubst %.s,%, $(patsubst %.arm,%, $(notdir $(argu)))))) \
  $(eval $(call target_compile2_asm_obj,$(argu),$(AOBJ).obj)) \
  $(eval $(call target_scan2_asm_det,$(argu),$(AOBJ).det)) \
  $(eval $(TARGLIB): $(AOBJ).obj) \
  $(eval TARGDEP_LIST += $(AOBJ).det) \
)

$(foreach argu,$(ASRCS1), \
  $(eval AOBJ1 := $(patsubst %.S,%, $(patsubst %.s,%, $(notdir $(argu))))) \
  $(eval $(call target_compile3_asm_obj,$(argu),$(AOBJ1).obj)) \
  $(eval $(call target_scan2_asm_det,$(argu),$(AOBJ1).det)) \
  $(eval $(TARGLIB): $(AOBJ1).obj) \
  $(eval TARGDEP_LIST += $(AOBJ1).det) \
)

$(foreach argu,$(ASRCS2), \
  $(eval AOBJ2 := $(patsubst %.S,%, $(patsubst %.s,%, $(notdir $(argu))))) \
  $(eval $(call target_compile2_asm_obj,$(argu),$(AOBJ2).obj)) \
  $(eval $(call target_scan2_asm_det,$(argu),$(AOBJ2).det)) \
  $(eval $(TARGLIB): $(AOBJ2).obj) \
  $(eval TARGDEP_LIST += $(AOBJ2).det) \
)

else

$(foreach argu,$(filter %.c %.cpp,$(SRC_LIST)), \
  $(eval COBJ0 := $(patsubst %.c,%, $(patsubst %.cpp,%, $(notdir $(argu))))) \
  $(eval $(call modis_compile_c_obj,$(argu),$(COBJ0).obj,$(CC_MODIS))) \
  $(eval $(call modis_scan_c_det,$(argu),$(COBJ0).det,$(CC_MODIS))) \
  $(eval $(TARGLIB): $(COBJ0).obj) \
  $(eval TARGDEP_LIST += $(COBJ0).det) \
)

endif

# *************************************************************************
# Include dependencies for this component (updated by ScanDeps)
# *************************************************************************
ifneq ($(filter update_dep,$(MAKECMDGOALS)),)
$(TARGDEP): $(TARGDEP_LIST)
else ifneq ($(filter update_lib,$(MAKECMDGOALS)),)
  ifneq ($(wildcard $(TARGDEP)),)
    ifneq ($(filter remake,$(strip $(ACTION))),)
include $(TARGDEP)
    else ifeq ($(strip $(AUTO_CHECK_DEPEND)),TRUE)
include $(TARGDEP)
    endif
  endif
endif

