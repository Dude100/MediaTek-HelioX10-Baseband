# Define source file folder to SRC_LIST
ifeq ($(strip $(DSP_SOLUTION)),DUALMACDSP)
   AUDFOLDER = driver/audio/src/v2
   AUD_SOLUTION      =  V2
else   
   AUDFOLDER = driver/audio/src/v1
   AUD_SOLUTION      =  V1
endif


ifeq ($(strip $(GERAN_MODE_SUPPORT)),NONE)
  SRC_LIST = $(strip $(AUDFOLDER))/dummy_audio.c
else

ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
ifeq ($(strip $(DHL_SUPPORT)),TRUE)
  SRC_LIST = $(strip $(CUS_MTK_REL))/dhl/l1trace/l1audio_trace.c
else
  SRC_LIST = $(strip $(CUS_MTK_REL))/tst/l1trace/l1audio_trace.c
endif
else
  SRC_LIST = $(strip $(CGEN_L1_OUTDIR))/l1audio_trace.c
endif

# Start Define source file lists to SRC_LIST
# Common part in v1 and v2
SRC_LIST += $(strip $(AUDFOLDER))/am.c \
            $(strip $(AUDFOLDER))/audio_service.c \
            $(strip $(AUDFOLDER))/l1audio_sph_srv.c \
            $(strip $(AUDFOLDER))/media.c \
            $(strip $(AUDFOLDER))/tone_drv.c \
            $(strip $(AUDFOLDER))/DTMF_drv.c \
            $(strip $(AUDFOLDER))/pcm4way.c \
            $(strip $(AUDFOLDER))/sp_drv.c \
            $(strip $(AUDFOLDER))/vm.c \
            driver/audio/src/audio_create.c


# AFE part
AFE_SPLIT_DRIVER_PLATFORM  = MT6280 MT6589 MT6572 MT6582 MT6290 MT6592 MT6571 MT6595 MT6752 MT6795
ifneq ($(filter $(strip $(MODULE_DEFS)), $(AFE_SPLIT_DRIVER_PLATFORM)),)
   SRC_LIST +=  $(strip $(AUDFOLDER))/afe_common.c \

   ifeq ($(strip $(PLATFORM)),MT6290)
     SRC_LIST += $(strip $(AUDFOLDER))/afes/afe_6290.c
   endif
      
   ifeq ($(strip $(PLATFORM)),MT6280)
     SRC_LIST += $(strip $(AUDFOLDER))/afes/afe_6280.c
   endif
   
   ifeq ($(strip $(PLATFORM)),MT6589)
     SRC_LIST += $(strip $(AUDFOLDER))/afes/afe_6589.c
   endif
   
   ifeq ($(strip $(PLATFORM)),MT6572)
     SRC_LIST += $(strip $(AUDFOLDER))/afes/afe_6572.c
   endif
   
   ifeq ($(strip $(PLATFORM)),MT6582)
     SRC_LIST += $(strip $(AUDFOLDER))/afes/afe_6582.c
   endif
   
   ifeq ($(strip $(PLATFORM)),MT6592)
     SRC_LIST += $(strip $(AUDFOLDER))/afes/afe_6592.c
   endif
   
   ifeq ($(strip $(PLATFORM)),MT6571)
     SRC_LIST += $(strip $(AUDFOLDER))/afes/afe_6571.c
   endif
   
   ifeq ($(strip $(PLATFORM)),MT6595)
     SRC_LIST += $(strip $(AUDFOLDER))/afes/afe_6595.c
   endif
   
   ifeq ($(strip $(PLATFORM)),MT6795)
     SRC_LIST += $(strip $(AUDFOLDER))/afes/afe_6595.c
   endif

   ifeq ($(strip $(PLATFORM)),MT6752)
     SRC_LIST += $(strip $(AUDFOLDER))/afes/afe_6752.c
   endif
else
   SRC_LIST +=  $(strip $(AUDFOLDER))/afe2.c
endif


# By Feature
ifneq ($(filter __ENABLE_SPEECH_DVT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST +=  $(strip $(AUDFOLDER))/speech_dvt.c
endif

ifneq ($(filter __DATA_CARD_SPEECH__, $(strip $(MODULE_DEFS))),)
   SRC_LIST +=  $(strip $(AUDFOLDER))/sp_strm_drv.c
endif

ifneq ($(filter __CVSD_CODEC_SUPPORT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST +=  $(strip $(AUDFOLDER))/bt_sco_drv.c                                                         
endif

ifneq ($(filter __ECALL_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))/eCall_drv.c
endif


ifeq ($(strip $(AUD_SOLUTION)),V1)
   SRC_LIST += $(strip $(AUDFOLDER))/audio_idma.c \
               $(strip $(AUDFOLDER))/sp_enhance.c \
               $(strip $(AUDFOLDER))/sidetone.c \
               $(strip $(AUDFOLDER))/sal_exp.c \
               $(strip $(AUDFOLDER))/sal_impl.c \
               $(strip $(AUDFOLDER))/sal_dsp.c \
               $(strip $(AUDFOLDER))/sp_daca.c \
               $(strip $(AUDFOLDER))/pcmRouter.c
   ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
      SRC_LIST += $(strip $(AUDFOLDER))/pcmrec_drv.c \
                  $(strip $(AUDFOLDER))/ExtBgSnd.c \
                  $(strip $(AUDFOLDER))/wm8904_config.c \
                  $(strip $(AUDFOLDER))/rawpcmrec_drv.c
      ifneq ($(strip $(SMART_PHONE_CORE)),MODEM_ONLY)
        SRC_LIST += $(strip $(AUDFOLDER))/spc_drv.c \
                    $(strip $(AUDFOLDER))/spc_io.c                    
      else
        SRC_LIST += $(strip $(AUDFOLDER))/apAudSysConfig.c
      endif 
   endif
endif

ifeq ($(strip $(AUD_SOLUTION)),V2)
   SRC_LIST +=  $(strip $(AUDFOLDER))/vm_drv.c
   ifneq ($(strip $(SMART_PHONE_CORE)),NONE)
      SRC_LIST += $(strip $(AUDFOLDER))/spc_drv.c
   endif

   ifneq ($(filter WAV_CODEC, $(strip $(MODULE_DEFS))),)
     SRC_LIST += $(strip $(AUDFOLDER))/wav_thumb.c
     SRC_LIST += $(strip $(AUDFOLDER))/pcm_strm_drv.c
   endif
endif

ifneq ($(filter __VOLTE_SUPPORT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST += $(strip $(AUDFOLDER))/sp_4g.c \            
         
   ifneq ($(filter __MCU_DTMF_SUPPORT__, $(strip $(MODULE_DEFS))),)   
      SRC_LIST += $(strip $(AUDFOLDER))/VoLTETone.c     
   endif   
   ifneq ($(filter __G_CODEC_SUPPORT__, $(strip $(MODULE_DEFS))),)   
      SRC_LIST += $(strip $(AUDFOLDER))/pcmrb.c
      SRC_LIST += $(strip $(AUDFOLDER))/streamrb.c
   endif   
endif

ifneq ($(filter __UMTS_RAT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST += $(strip $(AUDFOLDER))/amr_table.c \
               $(strip $(AUDFOLDER))/sp_3g.c
else
  ifneq ($(filter __UMTS_TDD128_MODE__, $(strip $(MODULE_DEFS))),)
    SRC_LIST += $(strip $(AUDFOLDER))/amr_table.c \
                $(strip $(AUDFOLDER))/sp_3g.c
  endif
endif

ifneq ($(filter BGSND_ENABLE, $(strip $(MODULE_DEFS))),)
  ifeq ($(strip $(AUD_SOLUTION)),V1)
    SRC_LIST += $(strip $(AUDFOLDER))/ExtBgSnd.c
  endif
  ifeq ($(strip $(AUD_SOLUTION)),V2)
    SRC_LIST += $(strip $(AUDFOLDER))/snd_effect.c
  endif
endif

ifneq ($(filter __CTM_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST += $(strip $(AUDFOLDER))/ctm_drv.c
endif

endif

#  Define include path lists to INC_DIR
INC_DIR = $(strip $(AUDFOLDER)) \
          $(strip $(AUDFOLDER))/inc \
          interface/driver/audio \
          driver/audio/src32_inc \
          driver/audio/lib/MTKINC \
          driver/drv/include \
          driver/sys_drv/init/inc \
          $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_ext \
          modem/interface/l4 \
          modem/interface/lte \
          interface/modem/mml1 \
          interface/modem/general \
          interface/driver/peripheral \
          custom/driver/common


ifneq ($(filter __CENTRALIZED_SLEEP_MANAGER__, $(strip $(MODULE_DEFS))),)
  INC_DIR    += driver/sleep_drv/public/inc
endif
 
# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWORK
 
# Define the source file search paths to SRC_PATH
SRC_PATH += $(strip $(AUDFOLDER))
SRC_PATH += $(strip $(AUDFOLDER))/afes
SRC_PATH += $(strip $(AUDFOLDER))/inc
SRC_PATH += driver/audio/src

