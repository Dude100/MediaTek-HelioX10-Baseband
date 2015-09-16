Upper = $(subst z,Z,$(subst y,Y,$(subst x,X,$(subst w,W,$(subst v,V,$(subst u,U,$(subst t,T,$(subst s,S,$(subst r,R,$(subst q,Q,$(subst p,P,$(subst o,O,$(subst n,N,$(subst m,M,$(subst l,L,$(subst k,K,$(subst j,J,$(subst i,I,$(subst h,H,$(subst g,G,$(subst f,F,$(subst e,E,$(subst d,D,$(subst c,C,$(subst b,B,$(subst a,A,$(1)))))))))))))))))))))))))))

# *************************************************************************
# Feature Removing / Can't be enabled in custom projects.
# *************************************************************************
# MAUI_02604459
ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
  ifdef BLUETOOTH_SUPPORT
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6601)
      $(warning ERROR: BLUETOOTH_SUPPORT = BTMTK_MT6601 cannot be enabled in customer projects)
      DEPENDENCY_CONFLICT = TRUE
    endif
    ifeq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6611)
      $(warning ERROR: BLUETOOTH_SUPPORT = BTMTK_MT6601 cannot be enabled in customer projects)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

# *************************************************************************
# Feature Removing / non-MP
# *************************************************************************
ifdef WIFI_BB_MODULE
  $(warning ERROR: WIFI_BB_MODULE is not support, please refer to MAUI_00735277.)
  DEPENDENCY_CONFLICT = TRUE
endif

ifdef WIFI_RF_MODULE
  $(warning ERROR: WIFI_RF_MODULE is not support, please refer to MAUI_00735277.)
  DEPENDENCY_CONFLICT = TRUE
endif

ifdef GAME_ENGINE
  ifeq ($(strip $(GAME_ENGINE)),GE_INTERGRAFX)
    $(warning ERROR: GAME_ENGINE = GE_INTERGRAFX is not support.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

ifdef IRDA_SUPPORT
  ifneq ($(strip $(IRDA_SUPPORT)),FALSE)
    $(warning ERROR: IRDA_SUPPORT is not supported anymore, please refer to MAUI_01660529)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# *************************************************************************
# Feature Dependency
# *************************************************************************

# Do not release GEMINI to customers in 6223/6223D/6223P, and 6223C is OK.
ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
  ifneq ($(filter __GEMINI__,$(COM_DEFS)),)
    ifeq ($(strip $(PLATFORM)),MT6223)
      $(warning ERROR: $(PLATFORM) does not support the dual SIM feature. Please disable GEMINI)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

# Do not release H264_DECODE=H264_SW on 6225. H264_SW on 6235/6235B could be released from W09.44.
ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
  ifdef H264_DECODE
    ifeq ($(strip $(H264_DECODE)),H264_SW)
      ifeq ($(strip $(PLATFORM)),MT6225)
        $(warning ERROR: H264_DECODE = H264_SW cannot be enabled on $(strip $(PLATFORM)) in customer projects)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
  ifdef H264_DECODE
    ifeq ($(strip $(H264_DECODE)),H264_SW)
      ifeq ($(strip $(PLATFORM)),MT6225)
        $(warning ERROR: H264_DECODE = H264_SW cannot be enabled on $(strip $(PLATFORM)) in customer projects)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

# Actually, H264_DECODE=H264_SW cannot be released to customers in all platforms.
H264_SW_RELEASE_PLATFORM = MT6235 MT6235B
ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
  ifdef H264_DECODE
    ifeq ($(strip $(H264_DECODE)),H264_SW)
      ifeq ($(filter $(strip $(PLATFORM)),$(strip $(H264_SW_RELEASE_PLATFORM))),)
        $(warning ERROR: H264_DECODE = H264_SW cannot be enabled in customer projects)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
  ifdef H264_DECODE
    ifeq ($(strip $(H264_DECODE)),H264_SW)
      ifeq ($(filter $(strip $(PLATFORM)),$(strip $(H264_SW_RELEASE_PLATFORM))),)
        $(warning ERROR: H264_DECODE = H264_SW cannot be enabled in customer projects)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

# H.263 (MP4_DECODE = MP4_SW, MP4_ENCODE = MP4_SW) cannot be enabled in 6225 customer projects.
ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
  ifeq ($(strip $(PLATFORM)),MT6225)
    ifdef MP4_DECODE
      ifeq ($(strip $(MP4_DECODE)),MP4_SW)
        $(warning ERROR: MP4_DECODE = MP4_SW cannot be enabled on $(strip $(PLATFORM)) in customer projects)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifdef MP4_ENCODE
      ifeq ($(strip $(MP4_ENCODE)),MP4_SW)
        $(warning ERROR: MP4_ENCODE = MP4_SW cannot be enabled on $(strip $(PLATFORM)) in customer projects)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif 
  endif
endif

ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
  ifeq ($(strip $(PLATFORM)),MT6225)
    ifdef MP4_DECODE
      ifeq ($(strip $(MP4_DECODE)),MP4_SW)
        $(warning ERROR: MP4_DECODE = MP4_SW cannot be enabled on $(strip $(PLATFORM)) in customer projects)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifdef MP4_ENCODE
      ifeq ($(strip $(MP4_ENCODE)),MP4_SW)
        $(warning ERROR: MP4_ENCODE = MP4_SW cannot be enabled on $(strip $(PLATFORM)) in customer projects)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif 
  endif
endif

# Justin Chu: Customer project is not allowed to enable J2ME_SUPPORT on 6223C
ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
  ifdef J2ME_SUPPORT
    ifneq ($(strip $(J2ME_SUPPORT)),NONE)
      ifneq ($(filter MT6223%,$(strip $(PLATFORM))),)
        $(warning ERROR: MT6223 series do not support J2ME_SUPPORT in customer projects)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
  endif
endif

# Justin: Custom projects cannot enable J2ME_SUPPORT = DUMMY_VM unless SWPM turns on DUMMY_VM_CONFIRM.
ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
  ifeq ($(strip $(J2ME_SUPPORT)),MTK_DUMMYVM)
    ifneq ($(strip $(DUMMY_VM_CONFIRM)),TRUE)
      $(warning ERROR: Customer projects do not support J2ME_SUPPORT=MTK_DUMMYVM)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
  ifeq ($(strip $(J2ME_SUPPORT)),MTK_DUMMYVM)
    ifneq ($(strip $(DUMMY_VM_CONFIRM)),TRUE)
      $(warning ERROR: Customer projects do not support J2ME_SUPPORT=MTK_DUMMYVM)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

# Paul: 622x platforms support MCU_DCM=DCM_ENABLE
DCM_NOT_SUPPORT_PLATFORM = MT6205 MT6205B MT6205C MT6208
ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
  ifneq ($(strip $(MCU_DCM)),DCM_ENABLE)
    ifeq ($(filter $(strip $(PLATFORM)),$(strip $(DCM_NOT_SUPPORT_PLATFORM))),)
      $(warning ERROR: Please turn on MCU_DCM on $(strip $(PLATFORM)))
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

### MAUI_01301660 ###
ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
  ifneq ($(filter __SMS_DEPERSONALIZATION__,$(COM_DEFS)),)
    $(warning ERROR: __SMS_DEPERSONALIZATION__ cannot be defined in customer projects yet. Please refer to MAUI_01301660.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

### MAUI_01355273 ###
ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
  ifneq ($(filter __SYNCML_DEVICE_SYNC_INTERNAL_TEST__,$(COM_DEFS)),)
    $(warning ERROR: __SYNCML_DEVICE_SYNC_INTERNAL_TEST__ cannot be defined in customer projects yet. Please refer to MAUI_01355273.)
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# for operator projects (MMSICP for Orange & Vodafone, NONE for others)
SIM_PROVISIONING_FOR_OPERATOR = ORANGE% VODAFONE%
ifdef OPTR_SPEC
  ifneq ($(strip $(OPTR_SPEC)),NONE)
    ifeq ($(filter $(SIM_PROVISIONING_FOR_OPERATOR),$(strip $(OPTR_SPEC))),)
      ifneq ($(strip $(SIM_PROVISIONING)),NONE)
        $(warning ERROR: PLEASE turn off SIM_PROVISIONING on $(strip $(OPTR_SPEC)) project)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif

    ifeq ($(strip $(OPTR_SPEC)),ORANGE_0605_CAM240)
      ifeq ($(strip $(SIM_PROVISIONING)),NONE)
        $(warning ERROR: PLEASE turn on SIM_PROVISIONING on ORANGE project)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif
    ifeq ($(strip $(OPTR_SPEC)),VODAFONE_R12_LIVE)
      ifeq ($(strip $(SIM_PROVISIONING)),NONE)
        $(warning ERROR: PLEASE turn on SIM_PROVISIONING on VODAFONE project)
        DEPENDENCY_CONFLICT = TRUE
      endif
    endif 
  endif
endif

# for memory monitor projects
ifeq ($(strip $(MMI_FEATURES_SWITCH)),TRUE)
  ifeq ($(filter $(SIM_PROVISIONING_FOR_OPERATOR),$(strip $(OPTR_SPEC))),)
    ifneq ($(strip $(SIM_PROVISIONING)),NONE)
      $(warning ERROR: PLEASE turn off SIM_PROVISIONING on momory monitor project)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

# GEMINI cannot be enabled on customer's MODEM project. MAUI_01679079
# disable the rule for smartphone MODEM project 


    ifdef GEMINI
      ifneq ($(strip $(GEMINI)),FALSE)
        ifdef SMART_PHONE_CORE
          ifeq ($(strip $(SMART_PHONE_CORE)),NONE)
            $(warning ERROR: Customer MODEM projects do not support GEMINI enabled)
            DEPENDENCY_CONFLICT = TRUE
          endif
        else
          $(warning ERROR: Customer MODEM projects do not support GEMINI enabled)
          DEPENDENCY_CONFLICT = TRUE      
        endif
      endif
    endif




    ifdef GEMINI
      ifneq ($(strip $(GEMINI)),FALSE)
        ifdef SMART_PHONE_CORE
          ifeq ($(strip $(SMART_PHONE_CORE)),NONE)
            $(warning ERROR: Customer MODEM projects do not support GEMINI enabled)
            DEPENDENCY_CONFLICT = TRUE
          endif
        else
          $(warning ERROR: Customer MODEM projects do not support GEMINI enabled)
          DEPENDENCY_CONFLICT = TRUE      
        endif
      endif
    endif


# UNICORN53 V1 ONLY support BTMTK_MT6612 & UNICORN53 V2 ONLY support BTMTK_MT6611
ifneq ($(strip $(BLUETOOTH_SUPPORT)),NONE)

  ifneq ($(filter UNICORN53_DEMO%,$(strip $(BOARD_VER))),)
    ifneq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6612)
      $(warning ERROR: UNICORN53 V1 ONLY support BTMTK_MT6612)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif

  ifneq ($(filter UNICORN53V2_DEMO%,$(strip $(BOARD_VER))),)
    ifneq ($(strip $(BLUETOOTH_SUPPORT)),BTMTK_MT6611)
      $(warning ERROR: UNICORN53 V2 ONLY support BTMTK_MT6611)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif

endif

# It's not suggested to enable WMA_DECODE in custom projects.
ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
  ifeq ($(strip $(WMA_DECODE)),TRUE)
    ifneq ($(strip $(WMA_DECODE_CONFIRM)),TRUE)
      $(warning ERROR: Customer projects was not suggested to enable WMA_DECODE. Please confirm with SWPM)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

ifeq ($(strip $(EMPTY_RESOURCE)),TRUE)
  ifeq ($(strip $(WMA_DECODE)),TRUE)
    ifneq ($(strip $(WMA_DECODE_CONFIRM)),TRUE)
      $(warning ERROR: Customer projects was not suggested to enable WMA_DECODE. Please confirm with SWPM)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif

# MAUI_02005072
LQT_NOT_SUPPORT_PLATFORM = MT6205% MT6217 MT6218% MT6219 MT6223%
ifneq ($(strip $(LQT_SUPPORT)),TRUE)  
  ifneq ($(filter $(strip $(PLATFORM)),$(LQT_NOT_SUPPORT_PLATFORM)),)
    $(warning ERROR: Please turn on LQT_SUPPORT when PLATFORM = $(strip $(PLATFORM)))
    DEPENDENCY_CONFLICT = TRUE
  endif
endif

# MAUI_02832938
ifeq ($(strip $(DEMO_PROJECT)),FALSE)
  MTK_SLEEP_ENABLE=TRUE
endif

ifdef MONZA2G
  $(warning ERROR: MONZA2G is not used anymore. Please remove MONZA2G from the project make file)
  DEPENDENCY_CONFLICT = TRUE
endif

ifeq ($(strip $(PRODUCTION_RELEASE)),TRUE)
  ifdef CUSTOM_CFLAGS
    ifneq ($(strip $(CUSTOM_CFLAGS)),)
      $(warning ERROR: Customer projects can not define CUSTOM_CFLAGS such as --debug --no_debug_macros.)
      DEPENDENCY_CONFLICT = TRUE
    endif
  endif
endif
