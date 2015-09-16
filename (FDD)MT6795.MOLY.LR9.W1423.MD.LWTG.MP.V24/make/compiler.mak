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

# ----------------------------------------------------------
# Environment and Tools
# ----------------------------------------------------------
ifndef COMPILE_MODE
  COMPILE_MODE = INST16                            # 16bits instruction set
endif

ifdef COMPILER
  ifeq ($(strip $(COMPILER)),GCC)
    VIA = @
    DEPEND = -MMD -MF
    BIN_FORMAT     = -O binary
    DIR_TOOL       = $(strip $(DIR_TOOL))
    ifeq ($(strip $(OS_VERSION)),MSWin32)
      CROSS          = tools\GCC\4.6.2\win\bin\arm-none-eabi-
      CPL             = $(CROSS)gcc.exe       # compiler
      CC             = $(CROSS)gcc.exe  -mthumb       # compiler
      CC32           = $(CROSS)gcc.exe  -marm         # compiler
      CPPC           = $(CROSS)g++.exe                # C++ compiler
      CPPC32         = $(CROSS)g++.exe -marm     # compiler
      LINK           = $(CROSS)ld.exe         # Linker
      DUMP           = $(CROSS)objdump.exe         # Linker
      ASM            = $(CROSS)as           # ARM assembler
      LIB            = $(CROSS)ar.exe          # Library tool
      BIN_CREATE     = $(CROSS)objcopy     # Binary tool
      CPLUSFLAGS     = $(CFLAGS)
      MD             = ""
    else
      CROSS          = tools/GCC/4.6.2/linux/bin/arm-none-eabi-
      CPL             = $(CROSS)gcc       # compiler
      CC             = $(CROSS)gcc  -mthumb       # compiler
      CC32           = $(CROSS)gcc  -marm         # compiler
      CPPC           = $(CROSS)g++                # C++ compiler
      CPPC32         = $(CROSS)g++ -marm     # compiler
      LINK           = $(CROSS)ld         # Linker
      DUMP           = $(CROSS)objdump         # Linker
      ASM            = $(CROSS)as           # ARM assembler
      LIB            = $(CROSS)ar          # Library tool
      BIN_CREATE     = $(CROSS)objcopy     # Binary tool
      CPLUSFLAGS     = $(CFLAGS)
      MD             = ""
    endif
  endif

  ifeq ($(strip $(COMPILER)),RVCT)
    VIA = --via #
    DEPEND = --depend
    BIN_FORMAT  =  -bin
  endif
endif

# default is RVCT compiler
ifndef COMPILER
   COMPILER = RVCT
   VIA = --via #
endif

ifdef RVCT_VERSION
  ifneq ($(strip $(RVCT_VERSION)),NONE)
    ifneq ($(strip $(COMPILER)),RVCT)
      $(call DEP_ERR_SETA_OR_OFFB,COMPILER,RVCT,RVCT_VERSION)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(COMPILER)),RVCT)
  ifndef RVCT_VERSION
    $(call DEP_ERR_SETA_OR_ONB,COMPILER,non RVCT,RVCT_VERSION)
    DEPENDENCY_CONFLICT = TRUE
  endif 
  ifeq ($(strip $(RVCT_VERSION)),NONE)
    $(call DEP_ERR_SETA_OR_ONB,COMPILER,non RVCT,RVCT_VERSION)
    DEPENDENCY_CONFLICT = TRUE
  endif
  DIR_ARM  = C:\Progra~1\ARM\RVCT
  DIR_ARM := $(strip $(DIR_ARM))

  ifeq ($(strip $(RVCT_VERSION)),V31)
    DIR_TOOL       =  $(DIR_ARM)\Programs\3.1\569\win_32-pentium
    DIR_ARMLIB     =  $(DIR_ARM)\Data\3.1\569\lib
    DIR_ARMINC     =  $(DIR_ARM)\Data\3.1\569\include\windows

  ifeq ($(strip $(call Upper,$(MTK_INTERNAL))),TRUE)
    ifeq ($(strip $(MTK_SUBSIDIARY)),FALSE)  
      include make\verifyCus.mak
    endif
  endif

  endif

  DIR_TOOL := $(strip $(DIR_TOOL))
  LINK           =  $(DIR_TOOL)\armlink.exe          # Linker
  ASM            =  $(DIR_TOOL)\armasm.exe           # ARM assembler
  LIB            =  $(DIR_ARM)\Programs\3.1\569\win_32-pentium\armar.exe         # Library tool
  BIN_CREATE     =  $(DIR_TOOL)\fromelf.exe          # Binary tool

  ifeq ($(strip $(COMPILE_MODE)),INST16)
    CC          =  $(DIR_TOOL)\armcc.exe --thumb $(VFP_OPTION_SOFT)     # Thumb Mode(16bits), use tcc
    CC32        =  $(DIR_TOOL)\armcc.exe --arm $(VFP_OPTION)       # ARM Mode(32bits), use armcc
  else
    ifeq ($(strip $(COMPILE_MODE)),INST32)
      CC          =  $(DIR_TOOL)\armcc.exe --arm $(VFP_OPTION)     # ARM Mode(32bits), use armcc
    else
      CC          =  $(DIR_TOOL)\armcc.exe --thumb $(VFP_OPTION_SOFT)   # Default tcc
      CC32        =  $(DIR_TOOL)\armcc.exe --arm $(VFP_OPTION)     # ARM Mode(32bits), use armcc
    endif
  endif
endif

DIR_INT_569  =  $(DIR_ARM)\Programs\3.1\569_init

# ----------------------------------------------------------
# Build Options
# ----------------------------------------------------------

# *****************************
# CODEGEN option
# *****************************
ifeq ($(strip $(COMPILER)),RVCT)
  CGENFLAG = -D__RVCT__
endif

# *****************************
# Interwork option
# *****************************
APCSINT     =

# *****************************
# C options COPTION16 for thumb mode and COPTION32 for arm mode
# *****************************
-include tools/RVCTBuildNo.tmp

ifeq ($(strip $(COMPILER)),GCC)
  CFLAGS          := -Wno-attributes -Wno-pragmas
  ifeq ($(strip $(GCC_WARN_AS_ERROR)),TRUE)
    CFLAGS          += -Werror
  endif
endif

ifneq ($(filter MT6280, $(strip $(PLATFORM))),)
ifeq ($(strip $(COMPILER)),GCC)
    PLATFORM_FLAGS  := -march=armv7-r -mcpu=cortex-r4 -mlittle-endian -Wa,-mimplicit-it=always -mabi=aapcs
    PLATFORM_AFLAGS  := -march=armv7-r -mcpu=cortex-r4 -mlittle-endian -mimplicit-it=always -mapcs-32
    OFLAGS          := -Os -fno-strict-aliasing -fno-common -fno-exceptions -ffunction-sections -fdata-sections
    OAFLAGS         := -gdwarf-2
    CFLAGS          += $(PLATFORM_FLAGS) $(OFLAGS) -Wall -c -mno-unaligned-access -fshort-wchar
 ifeq ($(strip $(OS_VERSION)),MSWin32)
    LINK_SEARCH_PATH = -L "./tools/GCC/4.6.2/win/arm-none-eabi/lib/armv7-r/thumb" \
                       -L "./tools/GCC/4.6.2/win/lib/gcc/arm-none-eabi/4.6.2/armv7-r/thumb"
 else
    LINK_SEARCH_PATH = -L "./tools/GCC/4.6.2/linux/arm-none-eabi/lib/armv7-r/thumb" \
                       -L "./tools/GCC/4.6.2/linux/lib/gcc/arm-none-eabi/4.6.2/armv7-r/thumb"
 endif
endif
endif

ifneq ($(filter MT6290 MT6595 MT6795, $(strip $(PLATFORM))),)
ifeq ($(strip $(NEED_BUILD_MD_OFFLOAD_COPRO)),FALSE)
 ifeq ($(strip $(COMPILER)),GCC)
     PLATFORM_FLAGS  := -march=armv7-r -mcpu=cortex-r4 -mlittle-endian -Wa,-mimplicit-it=always -mabi=aapcs
     PLATFORM_AFLAGS  := -march=armv7-r -mcpu=cortex-r4 -mlittle-endian -mimplicit-it=always -mapcs-32
     OFLAGS          := -Os -fno-strict-aliasing -fno-common -fno-exceptions -ffunction-sections -fdata-sections
     OAFLAGS         := -gdwarf-2
     CFLAGS          += $(PLATFORM_FLAGS) $(OFLAGS) -Wall -c -mno-unaligned-access -fshort-wchar
  ifeq ($(strip $(OS_VERSION)),MSWin32)
     LINK_SEARCH_PATH = -L "./tools/GCC/4.6.2/win/arm-none-eabi/lib/armv7-r/thumb" \
                        -L "./tools/GCC/4.6.2/win/lib/gcc/arm-none-eabi/4.6.2/armv7-r/thumb"
  else
     LINK_SEARCH_PATH = -L "./tools/GCC/4.6.2/linux/arm-none-eabi/lib/armv7-r/thumb" \
                        -L "./tools/GCC/4.6.2/linux/lib/gcc/arm-none-eabi/4.6.2/armv7-r/thumb"
  endif
 endif
endif
ifeq ($(strip $(NEED_BUILD_MD_OFFLOAD_COPRO)),TRUE)
 ifeq ($(strip $(COMPILER)),GCC)
     PLATFORM_FLAGS  := -march=armv5te -mlittle-endian -Wa,-mimplicit-it=arm -mabi=aapcs -mthumb-interwork ##add interwork, remove mcpu
     PLATFORM_AFLAGS  := -march=armv5te -mlittle-endian -mimplicit-it=arm -mapcs-32 -mthumb-interwork #add interwork, remove mcpu
     OFLAGS          := -Os -fno-strict-aliasing -fno-common -fno-exceptions -ffunction-sections -fdata-sections
     OAFLAGS         := -gdwarf-2
     CFLAGS          += $(PLATFORM_FLAGS) $(OFLAGS) -Wall -c -mno-unaligned-access -fshort-wchar
  ifeq ($(strip $(OS_VERSION)),MSWin32)
     LINK_SEARCH_PATH = -L "./tools/GCC/4.6.2/win/arm-none-eabi/lib/thumb" \
                        -L "./tools/GCC/4.6.2/win/lib/gcc/arm-none-eabi/4.6.2/thumb"
  else
     LINK_SEARCH_PATH = -L "./tools/GCC/4.6.2/linux/arm-none-eabi/lib/thumb" \
                        -L "./tools/GCC/4.6.2/linux/lib/gcc/arm-none-eabi/4.6.2/thumb"
  endif
 endif
endif # NEED_BUILD_MD_OFFLOAD_COPRO
endif # PLATFORM

ifneq ($(filter MT6752, $(strip $(PLATFORM))),)
ifeq ($(strip $(MDSYS)),MD1)
ifeq ($(strip $(COMPILER)),GCC)
    PLATFORM_FLAGS  := -march=armv7-r -mcpu=cortex-r4 -mlittle-endian -Wa,-mimplicit-it=always -mabi=aapcs
    PLATFORM_AFLAGS  := -march=armv7-r -mcpu=cortex-r4 -mlittle-endian -mimplicit-it=always -mapcs-32
    OFLAGS          := -Os -fno-strict-aliasing -fno-common -fno-exceptions -ffunction-sections -fdata-sections
    OAFLAGS         := -gdwarf-2
    CFLAGS          += $(PLATFORM_FLAGS) $(OFLAGS) -Wall -Wno-attributes -Wno-pragmas -c -mno-unaligned-access -fshort-wchar
 ifeq ($(strip $(OS_VERSION)),MSWin32)
    LINK_SEARCH_PATH = -L "./tools/GCC/4.6.2/win/arm-none-eabi/lib/armv7-r/thumb" \
                       -L "./tools/GCC/4.6.2/win/lib/gcc/arm-none-eabi/4.6.2/armv7-r/thumb"
 else
    LINK_SEARCH_PATH = -L "./tools/GCC/4.6.2/linux/arm-none-eabi/lib/armv7-r/thumb" \
                       -L "./tools/GCC/4.6.2/linux/lib/gcc/arm-none-eabi/4.6.2/armv7-r/thumb"
 endif
endif
endif
endif

ifneq ($(filter MT6575 MT6577, $(strip $(PLATFORM))),)
ifeq ($(strip $(COMPILER)),GCC)
    PLATFORM_FLAGS  := -march=armv6zk -mcpu=arm1176jz-s -mlittle-endian -Wa,-mimplicit-it=arm -mabi=aapcs
    PLATFORM_AFLAGS  := -march=armv6zk -mcpu=arm1176jz-s -mlittle-endian -mimplicit-it=arm -mapcs-32
    OFLAGS          := -Os -fno-strict-aliasing -fno-common -fno-exceptions -ffunction-sections -fdata-sections
    OAFLAGS         := -gdwarf-3
    CFLAGS          += $(PLATFORM_FLAGS) $(OFLAGS) -Wall -c -mno-unaligned-access -fshort-wchar
 ifeq ($(strip $(OS_VERSION)),MSWin32)
    LINK_SEARCH_PATH = -L "./tools/GCC/4.6.2/win/arm-none-eabi/lib/thumb" \
                       -L "./tools/GCC/4.6.2/win/lib/gcc/arm-none-eabi/4.6.2/thumb"
 else
    LINK_SEARCH_PATH = -L "./tools/GCC/4.6.2/linux/arm-none-eabi/lib/thumb" \
                       -L "./tools/GCC/4.6.2/linux/lib/gcc/arm-none-eabi/4.6.2/thumb"
 endif
endif
endif

ifneq ($(filter MT6752, $(strip $(PLATFORM))),)
ifeq ($(strip $(MDSYS)),MD2)
ifeq ($(strip $(COMPILER)),GCC)
    PLATFORM_FLAGS  := -march=armv5te -mcpu=arm926ej-s -mlittle-endian -Wa,-mimplicit-it=arm -mabi=aapcs
    PLATFORM_AFLAGS  := -march=armv5te -mcpu=arm926ej-s -mlittle-endian -mimplicit-it=arm -mapcs-32
    OFLAGS          := -Os -fno-strict-aliasing -fno-common -fno-exceptions -ffunction-sections -fdata-sections
    OAFLAGS         := -gdwarf-2
    CFLAGS          += $(PLATFORM_FLAGS) $(OFLAGS) -Wall -c -mno-unaligned-access -fshort-wchar
 ifeq ($(strip $(OS_VERSION)),MSWin32)
    LINK_SEARCH_PATH = -L "./tools/GCC/4.6.2/win/arm-none-eabi/lib/thumb" \
                       -L "./tools/GCC/4.6.2/win/lib/gcc/arm-none-eabi/4.6.2/thumb"
 else
    LINK_SEARCH_PATH = -L "./tools/GCC/4.6.2/linux/arm-none-eabi/lib/thumb" \
                       -L "./tools/GCC/4.6.2/linux/lib/gcc/arm-none-eabi/4.6.2/thumb"

 endif
endif
endif
endif

ifeq ($(strip $(COMPILER)),RVCT)
armtoolinfo = $(shell $(CC) --vsn 2>&1)
armtoolver = $(shell perl tools/armversion.pl $(armtoolinfo))
ifeq ($(strip $(armtoolver)),GEQ794)
REMOVE_UNNEEDED_ENTITIES:=--remove_unneeded_entities -D__FILE__=__MODULE__
endif
ifeq ($(strip $(armtoolver)),LSS794)
  REMOVE_UNNEEDED_ENTITIES:=--remove_unneeded_entities
endif

  CPLUSFLAGS = --cpp --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) 
  CFLAGS     = --cpu ARM7EJ-S --littleend -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__  -J$(DIR_ARMINC) --fpmode=ieee_fixed
  LNKOPT     = --cpu ARM7EJ-S

  ifneq ($(filter MT6280 MT6290 MT6595 MT6795, $(strip $(PLATFORM))),)
    CFLAGS   :=   --cpu Cortex-R4 --littleend --no_unaligned_access -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
    LNKOPT   :=   --cpu Cortex-R4
  endif  
  ifeq ($(strip $(PLATFORM)),MT6575)
    ifdef SMART_PHONE_CORE
      CFLAGS   :=   --cpu ARM1176JZ-S --littleend --no_unaligned_access -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
      LNKOPT   :=   --cpu ARM1176JZ-S
    else      
      CFLAGS   :=   --cpu ARM1176JZ-S --littleend --no_unaligned_access -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
      LNKOPT   :=   --cpu ARM1176JZ-S
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6577)
    ifdef SMART_PHONE_CORE
      CFLAGS   :=   --cpu ARM1176JZ-S --littleend --no_unaligned_access -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
      LNKOPT   :=   --cpu ARM1176JZ-S
    else      
      CFLAGS   :=   --cpu ARM1176JZ-S --littleend --no_unaligned_access -O3 $(REMOVE_UNNEEDED_ENTITIES) -D__RVCT__ -J$(DIR_ARMINC) --fpmode=ieee_fixed
      LNKOPT   :=   --cpu ARM1176JZ-S
    endif
  endif
endif

ifeq ($(strip $(COMPILER)),RVCT)
  CFLAGS += --split_sections 
  CFLAGS += --diag_suppress 1,2548
  ifeq ($(strip $(RVCT_DEBUG_FORMAT)),DWARF3)
    CFLAGS += --dwarf3
  else
    CFLAGS += --dwarf2
  endif
  CPLUSFLAGS := --cpp $(CFLAGS)
endif

CFLAGS     +=  $(CUSTOM_CFLAGS)
CPLUSFLAGS +=  $(CUSTOM_CFLAGS)

# *****************************
# assembly option AOPTION16 for Thumb mode and AOPTION32 for Arm mode
# *****************************
ifeq ($(strip $(COMPILER)),GCC)
  AFLAGS := $(PLATFORM_AFLAGS) $(OAFLAGS) -g --defsym __SRS_CPS_OPTIMIZE__=1
endif # end of " COMPILER == GCC "

ifeq ($(strip $(COMPILER)),RVCT)
  AFLAGS     = --debug --littleend --cpu ARM7EJ-S --apcs /interwork
  ifeq ($(strip $(PLATFORM)),TK6280)
    AFLAGS     :=   --debug --littleend --cpu Cortex-R4 --no_unaligned_access --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6280)
    AFLAGS     :=   --debug --littleend --cpu Cortex-R4 --no_unaligned_access --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6290)
    AFLAGS     :=   --debug --littleend --cpu Cortex-R4 --no_unaligned_access --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6595)
    AFLAGS     :=   --debug --littleend --cpu Cortex-R4 --no_unaligned_access --apcs /interwork
  endif
  ifeq ($(strip $(PLATFORM)),MT6795)
    AFLAGS     :=   --debug --littleend --cpu Cortex-R4 --no_unaligned_access --apcs /interwork
  endif
  ifneq ($(filter MT6575 MT6577, $(strip $(PLATFORM))),)
    AFLAGS     :=   --debug --littleend --cpu ARM1176JZ-S --no_unaligned_access --apcs /interwork
  endif
  ifeq ($(strip $(COMPILE_MODE)),INST16)
    AFLAGS    +=  -16
    APCSINT   +=  --apcs /inter/noswst
  endif
endif

# -----------------------------
# Macros definition for GCC
# -----------------------------
PURELNKOPT     = $(strip $(LNKOPT))

ifeq ($(strip $(COMPILER)),GCC)
  WRAP_LIST = --wrap=memcpy --wrap=memset --wrap=memclr --wrap=strcmp --wrap=sprintf  --wrap=vsprintf --wrap=snprintf --wrap=vsnprintf --wrap=sscanf --wrap=vsscanf \
	--wrap=raise --wrap=__aeabi_div0 --wrap=setlocale --wrap=on_exit --wrap=getenv --wrap=clock --wrap=puts \
	--wrap=putchar --wrap=printf --wrap=vprintf --wrap=malloc --wrap=_malloc_r --wrap=calloc --wrap=_calloc_r --wrap=realloc --wrap=_realloc_r \
	--wrap=free --wrap=_free_r --wrap=qsort --wrap=fprintf --wrap=fflush --wrap=_fflush_r --wrap=setbuf --wrap=setvbuf --wrap=fscanf \
	--wrap=scanf --wrap=vfscanf --wrap=vscanf --wrap=vfprintf --wrap=fgetc --wrap=fgets --wrap=getc --wrap=getchar --wrap=gets \
	--wrap=putc  --wrap=ungetc --wrap=_ungetc_r --wrap=fgetpos --wrap=fseek --wrap=fsetpos --wrap=ftell --wrap=rewind --wrap=clearerr \
	--wrap=feof --wrap=ferror --wrap=fopen --wrap=freopen --wrap=_fclose_r --wrap=fclose --wrap=fprintf --wrap=fread --wrap=fwrite \
	--wrap=fputc --wrap=fputs --wrap=perror

# *************************
#  Settings for BOOTLOADER
# *************************
  BTLD_LNKOPT    = -Bstatic --cref --warn-common --gc-sections
  BTLDLNKOPT     = $(strip $(BTLD_LNKOPT)) -o $(strip $(TARGDIR))\$(BTLD_PREFIX).elf \
                   -Map $(strip $(TARGDIR))\$(BTLD_PREFIX).map \
                   -dT $(strip $(BL_SCATTERFILE)) \
                   $(strip $(LINK_SEARCH_PATH))
  BTLDEXTLNKOPT  = $(strip $(BTLD_LNKOPT)) -o $(strip $(TARGDIR))\$(BTLD_EXT_PREFIX).elf \
                   -Map $(strip $(TARGDIR))\$(BTLD_EXT_PREFIX).map \
                   -dT $(strip $(BL_EXT_SCATTERFILE)) \
                   $(strip $(LINK_SEARCH_PATH))

# *************************
#  Settings for TARGET
# *************************
  LNKOPT = $(strip $(WRAP_LIST)) -Bstatic --cref --warn-common --gc-sections\
           -o $(strip $(TARGDIR))\$(TARGNAME).elf \
           -Map $(strip $(TARGDIR))\$(TARGNAME).map \
           -dT $(strip $(SCATTERFILE)) \
           $(strip $(LINK_SEARCH_PATH))

  ifeq ($(strip $(PLATFORM)),MT6290)
    ifeq ($(strip $(NEED_BUILD_MD_OFFLOAD_COPRO)),FALSE)
      LNKOPT += --thumb-entry=INT_Vectors
    endif
    ifeq ($(strip $(NEED_BUILD_MD_OFFLOAD_COPRO)),TRUE)
      LNKOPT += --entry=INT_Vectors
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6595)
    ifeq ($(strip $(NEED_BUILD_MD_OFFLOAD_COPRO)),FALSE)
      LNKOPT += --thumb-entry=INT_Vectors
    endif
    ifeq ($(strip $(NEED_BUILD_MD_OFFLOAD_COPRO)),TRUE)
      LNKOPT += --entry=INT_Vectors
    endif
  endif
  ifeq ($(strip $(PLATFORM)),MT6795)
    ifeq ($(strip $(NEED_BUILD_MD_OFFLOAD_COPRO)),FALSE)
      LNKOPT += --thumb-entry=INT_Vectors
    endif
    ifeq ($(strip $(NEED_BUILD_MD_OFFLOAD_COPRO)),TRUE)
      LNKOPT += --entry=INT_Vectors
    endif
  endif

  ifneq ($(filter $(strip $(PLATFORM)),$(SV5X_PLATFORM)),)
    LNKOPT += --undefined=g_maui_gfh
#   LNKOPT += --undefined=g_maui_sig
  endif
endif #ifeq ($(strip $(COMPILER)),GCC)

# -----------------------------
# Macros definition for RVCT
# -----------------------------
ifeq ($(strip $(COMPILER)),RVCT)

# *************************
#  Settings for BOOTLOADER
# *************************
  ifneq ($(filter BIND_TO_KEY BIND_TO_CHIP BIND_TO_CHIP_AND_KEY, $(strip $(SW_BINDING_SUPPORT))),)
    BTLD_LNKOPT += --keep gfh_bl_anticlone
    BTLD_LNKOPT += --keep gfh_bl_brom_sec_cfg
  endif

  ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
    BTLD_LNKOPT += --keep g_BlSecInfo \
                   --keep g_BlSecureMAC \
                   --keep g_BlSecureMAC_Size
    ifeq ($(strip $(USB_DOWNLOAD_IN_BL)),SECURE)
      BTLD_LNKOPT += --keep g_BlFunc_Table
    endif
    BTLD_LNKOPT += --keep gfh_bl_brom_sec_cfg
    BTLD_LNKOPT += --keep gfh_bl_sec_key
  endif
  BTLD_LNKOPT += --keep IMG_BL_INFO
  BTLD_LNKOPT += --keep g_ExtBootloaderInfo
  BTLDLNKOPT     = $(strip $(LNKOPT)) $(strip $(BTLD_LNKOPT)) -scatter $(BL_SCATTERFILE) \
                    -output $(strip $(TARGDIR))\$(BTLD_PREFIX).elf \
                    -symdefs $(strip $(TARGDIR))\$(BTLD_PREFIX).sym \
                    -list $(strip $(TARGDIR))\$(BTLD_PREFIX).lis \
                    -libpath $(DIR_ARMLIB)
  BTLDEXTLNKOPT  = $(strip $(LNKOPT)) $(strip $(BTLD_LNKOPT)) -scatter $(BL_EXT_SCATTERFILE) \
                   -output $(strip $(TARGDIR))\$(BTLD_EXT_PREFIX).elf \
                   -symdefs $(strip $(TARGDIR))\$(BTLD_EXT_PREFIX).sym \
                   -list $(strip $(TARGDIR))\$(BTLD_EXT_PREFIX).lis \
                   -libpath $(DIR_ARMLIB)
# *************************
#  Settings for TARGET
# *************************
# -----------------------------
# Linker options
# -----------------------------
  # *****************************
  # Library option LIBOPT for generating libraries
  # *****************************
  LIBOPT      =  --create

  ifneq ($(strip $(CUSTOM_RELEASE)),TRUE)
    LNKOPT      +=  --map --info sizes,totals --symbols --feedback $(strip $(TARGDIR))\lnkfeedback.txt --xref --remove --pad 0x00 --datacompressor off --verbose
  else
    LNKOPT      +=  --map --info sizes,totals --symbols --feedback $(strip $(TARGDIR))\lnkfeedback.txt --xref --remove --pad 0x00 --datacompressor off
  endif
  ifeq ($(filter L1S BASIC,$(TEST_LOAD_TYPE)),)
    LNKOPT      +=  --first LARGEPOOL_FIRST_ZI
  endif
  ifeq ($(strip $(DEMO_PROJECT)),TRUE)
    ifeq ($(strip $(armtoolver)),GEQ794)
      LNKOPT += --max_veneer_passes=30
    endif
  endif
  LNKOPT += --verbose --trace p,v,t
ifdef VENUS_MMI
  ifneq ($(strip $(VENUS_MMI)),NONE)
    LNKOPT += --keep=vpi*
  endif
endif

  LNKOPT += --largeregions --scatter $(SCATTERFILE) --output $(strip $(TARGDIR))\$(TARGNAME).elf \
            --symdefs $(strip $(TARGDIR))\$(TARGNAME).sym \
            --list $(strip $(TARGDIR))\$(TARGNAME).lis \
            --libpath $(DIR_ARMLIB)
  LNKOPT += --keep EMI_INFO_2
  LNKOPT += --keep CUST_MEM_INFO
  LNKOPT += --keep g_bl_maui_paired_ver
  LNKOPT += --keep DL_CTRL_BIN \
            --keep g_boot_cert_sig

  ifeq ($(strip $(USB_DOWNLOAD_IN_BL)),SECURE)
    LNKOPT += --keep g_DummyKeep_Data
  endif

  ifeq ($(strip $(SECURE_SUPPORT)),TRUE)
    LNKOPT += --keep g_secinfo_tail \
              --keep g_SEC_RO \
              --keep g_FlashToolCfg \
              --keep g_SecureMAC_Size \
              --keep g_SecureMAC \
              --keep g_secinfo
  endif

  ifeq ($(strip $(SECURE_RO_ENABLE)),TRUE)
    LNKOPT += --keep g_SEC_RO
  endif

  ifeq ($(strip $(CUST_PARA_SUPPORT)),TRUE)
    LNKOPT += --keep g_CustParaCfg \
              --keep g_CustParaCfg_Tail
  endif

  ifneq ($(strip $(NAND_FLASH_BOOTING)),NONE)
    LNKOPT += --keep g_enfb_3rdrom_header
  endif

  ifeq ($(strip $(MULTIPLE_BINARY_FILES)),TRUE)
    CUSTPACK_LNKOPT = --map --info sizes,totals --symbols --xref --libpath $(DIR_ARMLIB) --remove
    CUSTPACK_LNKOPT += --keep mtk_theme_header
  endif

  LNKOPT += --keep verno.obj(*_RW)
  LNKOPT += $(NVRAM_LNK_OPT)
endif #ifeq ($(strip $(COMPILER)),RVCT)
