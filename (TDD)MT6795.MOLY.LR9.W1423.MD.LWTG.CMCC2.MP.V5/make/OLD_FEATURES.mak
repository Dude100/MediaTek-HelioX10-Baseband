#################################################################
# Use this file to keep removed or renamed features' reminders
# Use this file to keep value-changed features' reminders
#################################################################

# Removed feature

ifdef UID_SUPPORT
    $(warning ERROR: UID_SUPPORT was renamed to SW_BINDING_SUPPORT. UID_SUPPORT=TRUE was mapped to SW_BINDING_SUPPORT=BIND_TO_CHIP_BASIC)
    DEPENDENCY_CONFLICT = TRUE
endif

ifdef SW_CHANGE_BLOCKING
    $(warning ERROR: SW_CHANGE_BLOCKING was phased-out. Please remove this feature option from project makefile.)
    DEPENDENCY_CONFLICT = TRUE
endif

ifdef BTSTACK_SUPPORT
    $(warning ERROR: BTSTACK_SUPPORT was phased-out. Please remove this feature option from project makefile.)
    DEPENDENCY_CONFLICT = TRUE
endif

# MAUI_02621426
ifdef SIM_NEW_ARCH
    $(warning ERROR: SIM_NEW_ARCH was phased-out. Please remove this feature option from project makefile.)
    DEPENDENCY_CONFLICT = TRUE
endif

# MAUI_02864904
ifdef SECLIB_SUPPORT
    $(warning ERROR: SECLIB_SUPPORT was phased-out. Please remove this feature option from project makefile.)
    DEPENDENCY_CONFLICT = TRUE
endif

# MAUI_02451889
ifdef SVG_SUPPORT
    $(warning ERROR: SVG_SUPPORT was phased-out. Please remove this feature option from project makefile.)
    DEPENDENCY_CONFLICT = TRUE
endif

# MAUI_02943789
ifdef CONNECTED_OOS
    $(warning ERROR: CONNECTED_OOS was phased-out. Please remove this feature option from project makefile.)
    DEPENDENCY_CONFLICT = TRUE
endif

# MAUI_02961543
ifdef PICTBRIDGE_SUPPORT
    $(warning ERROR: PICTBRIDGE_SUPPORT was phased-out. Please remove this feature option from project makefile.)
    DEPENDENCY_CONFLICT = TRUE
endif

# MAUI_02994074
ifdef PANORAMA_VIEW_SUPPORT
    $(warning ERROR: PANORAMA_VIEW_SUPPORT was phased-out. Please remove this feature option from project makefile.)
    DEPENDENCY_CONFLICT = TRUE
endif

ifdef NVRAM_COMPRESS_SUPPORT
  $(warning ERROR: NVRAM_COMPRESS_SUPPORT was phased-out. Please remove this feature option from project makefile.)
  DEPENDENCY_CONFLICT = TRUE
endif

ifdef CBM_BEARER_FALLBACK_SUPPORT
  $(warning ERROR: CBM_BEARER_FALLBACK_SUPPORT was phased-out. Please remove this feature option from project makefile.)
  DEPENDENCY_CONFLICT = TRUE
endif

ifdef CBM_ALWAYS_ASK_SUPPORT
  $(warning ERROR: CBM_ALWAYS_ASK_SUPPORT was phased-out. Please remove this feature option from project makefile.)
  DEPENDENCY_CONFLICT = TRUE
endif

#MAUI_03174776
ifdef ZIMAGE_AUTO_CONFIG
  $(warning ERROR: ZIMAGE_AUTO_CONFIG was phased-out.please remove this feature option from project makefile.)
  DEPENDENCY_CONFLICT = TRUE
endif

#MOLY00001574
ifdef CARD_DOWNLOAD
  $(warning ERROR: CARD_DOWNLOAD was phased-out.please remove this feature option from project makefile.)
  DEPENDENCY_CONFLICT = TRUE
endif

# Renamed feature

# MAUI_02852515
ifdef USB_DOWNLOAD
    $(warning ERROR: USB_DOWNLOAD was renamed to USB_DOWNLOAD_IN_BL. Please change this feature option from project makefile.)
    DEPENDENCY_CONFLICT = TRUE
endif

# Value-changed feature
ifdef GEMINI
  ifeq ($(strip $(GEMINI)),TRUE)
    $(warning ERROR: Please set GEMINI = 2 instead of TRUE.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# MAUI_02646026
ifdef NMC_SUPPORT
  ifeq ($(strip $(NMC_SUPPORT)),TRUE)
    $(warning ERROR: Please turn off NMC_SUPPORT.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# MAUI_02642831
VRE_NOT_SUPPORT_VALUE = VRE_V20 VRE_V21 VRE_V30
ifdef VRE_SUPPORT
  ifneq ($(filter $(strip $(VRE_SUPPORT)),$(VRE_NOT_SUPPORT_VALUE)),)
    $(warning ERROR: $(strip $(VRE_SUPPORT)) is NOT a valid value of VRE_SUPPORT.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# MAUI_02844902
ifdef DSP_COMPRESS
  ifeq ($(strip $(DSP_COMPRESS)),TRUE)
    $(warning ERROR: Please set DSP_COMPRESS as NONE/ZIP/7Z.)
    DEPENDENCY_CONFLICT = TRUE
  endif
  ifeq ($(strip $(DSP_COMPRESS)),FALSE)
    $(warning ERROR: Please set DSP_COMPRESS as NONE/ZIP/7Z.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# MAUI_02841775
JPG_DECODE_SUPPORT_VALUE = TRUE FALSE
ifdef JPG_DECODE
  ifeq ($(filter $(strip $(JPG_DECODE)),$(JPG_DECODE_SUPPORT_VALUE)),)
    $(warning ERROR: $(strip $(JPG_DECODE)) is NOT a valid value of JPG_DECODE.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# MAUI_02841775
JPG_ENCODE_SUPPORT_VALUE = TRUE FALSE 
ifdef JPG_ENCODE
  ifeq ($(filter $(strip $(JPG_ENCODE)),$(JPG_ENCODE_SUPPORT_VALUE)),)
    $(warning ERROR: $(strip $(JPG_ENCODE)) is NOT a valid value of JPG_ENCODE.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# MAUI_02885432
CARD_DOWNLOAD_SUPPORT_VALUE = NONE RAW_FORMAT_CARD FILESYSTEM_ON_CARD
ifdef CARD_DOWNLOAD
  ifeq ($(filter $(strip $(CARD_DOWNLOAD)),$(CARD_DOWNLOAD_SUPPORT_VALUE)),)
    $(warning ERROR: $(strip $(CARD_DOWNLOAD)) is NOT a valid value of CARD_DOWNLOAD.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# MAUI_02983456
SLIMMING_WITH_DEMAND_PAGING = NONE
ifdef SLIMMING_WITH_DEMAND_PAGING
  ifneq ($(strip $(NAND_FLASH_BOOTING)), ONDEMAND)
    ifneq ($(strip $(SLIMMING_WITH_DEMAND_PAGING)), NONE)
      $(warning ERROR: Please set SLIMMING_WITH_DEMAND_PAGING to NONE when NAND_FLASH_BOOTING is not set to ONDEMAND.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif 
  ifeq ($(strip $(SLIMMING_WITH_DEMAND_PAGING)), LEVEL1)
    COM_DEFS += __SLIMMING_WITH_DEMAND_PAGING_LEVEL1__
  endif
endif