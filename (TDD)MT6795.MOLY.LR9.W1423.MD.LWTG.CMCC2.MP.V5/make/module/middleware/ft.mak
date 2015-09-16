# Define source file lists to SRC_LIST
# in this case there should be only ft_main.c is compiled
# keep ft_create for kal config
# if !defined(__FACTORY_BIN__) && defined(__SPLIT_BINARY__)
FACTORY_BIN_COMBINATION = __SPLIT_BINARY__ __FACTORY_BIN__
ifeq ($(filter $(FACTORY_BIN_COMBINATION), $(strip $(MODULE_DEFS))), __SPLIT_BINARY__)
SRC_LIST = middleware/meta/ft/src/ft_dummy.c
else
SRC_LIST = middleware/meta/ft/src/ft_main.c \
           middleware/meta/ft/src/ft_mem.c \
           middleware/meta/ft/src/ft_report.c \
           middleware/meta/ft/src/ft_fnc.c \
           middleware/meta/ft/src/ft_fnc_l1rf.c \
           middleware/meta/ft/src/ft_fnc_misc.c \
           middleware/meta/ft/src/ft_fnc_nvram.c \
           middleware/meta/ft/src/ft_fnc_fat.c \
           middleware/meta/ft/src/ft_fnc_custom.c \
           middleware/meta/ft/src/ft_fnc_misc_ex.c \
           middleware/meta/ft/src/ft_fnc_util.c
# Define optional source file
ifneq ($(filter __UMTS_RAT__, $(strip $(MODULE_DEFS))),)
ifneq ($(filter __MTK_UL1_FDD__, $(strip $(MODULE_DEFS))),)
SRC_LIST    += middleware/meta/ft/src/ft_fnc_wcdma.c
endif
endif

ifneq ($(filter __UMTS_TDD128_MODE__, $(strip $(MODULE_DEFS))),)
ifneq ($(filter __AST_TL1_TDD__, $(strip $(MODULE_DEFS))),)
SRC_LIST    += middleware/meta/ft/src/ft_fnc_aux.c
endif
endif

ifneq ($(filter __LTE_RAT__, $(strip $(MODULE_DEFS))),)
SRC_LIST    += middleware/meta/ft/src/ft_fnc_lterf.c
endif

endif
#  Define include path lists to INC_DIR
INC_DIR = interface/middleware/meta \
          interface/service/sst \
          interface/service/dhl \
          $(strip $(MODEM_FOLDER))/l4/include \
          middleware/meta/ft/inc \
          middleware/media/audio/include \
          driver/dp_engine/che/include
                    
# Non-MODEM BSP include path

# Define the specified compile options to COMP_DEFS
COMP_DEFS = 

# Define the source file search paths to SRC_PATH
SRC_PATH = middleware/meta/ft/src
