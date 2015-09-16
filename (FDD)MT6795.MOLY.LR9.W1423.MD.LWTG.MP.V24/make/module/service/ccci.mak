# Define source file lists to SRC_LIST
SRC_LIST = service/hif/ccci/src/ccci_ch_cfg.c                         \
           service/hif/ccci/src/ccci_hif_cfg.c                        \
           service/hif/ccci/src/ccci_apis.c                           \
           service/hif/ccci/src/ccci_hmu.c                            \
           service/hif/ccci/src/ccci_except.c                         \
           service/hif/ccci/src/ccci_sdio.c                           \
           service/hif/ccci/src/ccci_cldma.c                          \
           service/hif/ccci/src/ccci_ccif.c                           \
           service/hif/ccci/src/ccci_ut.c                             \
           service/hif/ccci/src/ccci_it.c                             \
	   service/hif/ccci/src/ccci_lb_it.c                          \
           service/hif/ccci/src/ccci_misc_data.c                      \
           service/hif/ccci/src/ccci_debug.c
	   
# Define include path lists to INC_DIR
INC_DIR = service/hif/ccci/include                                    \
          interface/service/hif                                       \
          service/hif/interface                                       \
	  interface/driver/hif                                        \
          interface/driver/hif/hif_sdiodev                            \
          interface/driver/hif/hif_cldmadev                           \
	  interface/driver/sdiocore                                   \
          interface/driver/cldmacore                                  \
          interface/driver/ccifcore                                   \
          driver/sys_drv/cache/inc                                    \
          driver/peripheral					      
	  	
# Define the specified compile options to COMP_DEFS
#COMP_DEFS =

# Patch for MoDIS
#ifeq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
#   COMP_DEFS += 
#endif

# Define the source file search paths to SRC_PATH
SRC_PATH = service/hif/ccci/src
