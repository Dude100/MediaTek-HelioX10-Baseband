# Define source file lists to SRC_LIST

SRC_LIST = middleware/media/common/src/med_main.c \
           middleware/media/common/src/med_utility.c \
           middleware/media/common/src/med_ext_smalloc.c

ifeq ($(filter MED_NOT_PRESENT, $(strip $(MODULE_DEFS))),)
SRC_LIST += middleware/media/audio/src/aud_main.c \
            middleware/media/audio/src/aud_audio.c \
            middleware/media/audio/src/aud_speech.c \
            middleware/media/audio/src/aud_keytone.c \
            middleware/media/audio/src/aud_tone.c \
            middleware/media/audio/src/aud_ilm.c \
            middleware/media/audio/src/aud_utility.c \
            middleware/media/audio/src/aud_media.c
else
   ifneq ($(filter __VOLTE_SUPPORT__, $(strip $(MODULE_DEFS))),)
   SRC_LIST += middleware/media/audio/src/aud_ilm.c \
               middleware/media/audio/src/aud_main.c \
               middleware/media/audio/src/aud_utility.c
   endif            
endif



ifneq ($(filter __ECALL_SUPPORT__, $(strip $(MODULE_DEFS))),)
  SRC_LIST    += middleware/media/audio/src/aud_ecall.c
endif

#  Define include path lists to INC_DIR
INC_DIR = middleware/media/common/include \
          middleware/media/audio/include \
          interface/modem/general \
          $(strip $(MODEM_FOLDER))/l4/uem/include \
          interface/driver/hwdrv \
          interface/driver/drv_sw_def \
          driver/drv_def \
          interface/driver/connectivity/usb_driver \
          interface/driver/peripheral 

# Define the specified compile options to COMP_DEFS
COMP_DEFS = 
