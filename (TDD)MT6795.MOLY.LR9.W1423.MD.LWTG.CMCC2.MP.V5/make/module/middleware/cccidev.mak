#
# Define source file lists to SRC_LIST
#
#

# [cccidev_task] 
# Control the ccci devices (CCCI_CCMNI, CCCI_TTY, CCCI_FS, CCCI_IPC, CCCI_MSG)
#
SRC_LIST = middleware/hif/cccidev/cccidev_task/src/cccidev_task.c 


#
# [CCCI_TTY] 
#
SRC_LIST += middleware/hif/cccidev/ccci_tty/src/cccitty_hdr.c  \
            middleware/hif/cccidev/ccci_tty/src/cccitty_data.c \
            middleware/hif/cccidev/ccci_tty/src/cccitty_sm.c   \
            middleware/hif/cccidev/ccci_tty/src/cccitty_hmu.c  \
            middleware/hif/cccidev/ccci_tty/src/cccitty_ut.c   \
            middleware/hif/cccidev/ccci_tty/src/cccitty_it.c   \
            middleware/hif/cccidev/ccci_tty/src/cccitty_except.c


#
#  Define include path lists to INC_DIR
#
INC_DIR = middleware/hif/interface                    \
          middleware/hif/cccidev/cccidev_task/include \
          middleware/hif/cccidev/ccci_tty/include     \
          interface/service/hif                       \
          interface/driver/hif                        \
          interface/driver/hif/hif_sdiodev  
		  

# Define the specified compile options to COMP_DEFS
#COMP_DEFS =
# Patch for MoDIS
#ifeq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
#   COMP_DEFS += 
#endif

# Define the source file search paths to SRC_PATH
SRC_PATH = middleware/hif/cccidev_task/src \
           middleware/hif/ccci_tty/src


ifdef CCCI_CCMNI_SUPPORT
         ifeq ($(strip $(CCCI_CCMNI_SUPPORT)), TRUE)            

	    #
	    # [CCCI_CCMNI] 
	    #
		SRC_LIST += middleware/hif/cccidev/ccci_ccmni/src/ccmni_pfp.c  \
		            middleware/hif/cccidev/ccci_ccmni/src/ccmni_data.c \
		            middleware/hif/cccidev/ccci_ccmni/src/ccmni_sm.c   \
		            middleware/hif/cccidev/ccci_ccmni/src/ccmni_hmu.c  \
		            middleware/hif/cccidev/ccci_ccmni/src/ccmni_ut.c   \
		            middleware/hif/cccidev/ccci_ccmni/src/ccmni_it.c
		            
		INC_DIR +=  middleware/hif/cccidev/ccci_ccmni/include  

		SRC_PATH +=  middleware/hif/ccci_ccmni/src 

	endif
endif
