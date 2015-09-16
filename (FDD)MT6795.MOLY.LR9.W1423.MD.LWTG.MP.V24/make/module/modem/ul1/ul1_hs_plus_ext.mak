# Define source file lists to SRC_LIST
SRC_LIST = $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_ext/wdata.c
                 
# Define include path lists to INC_DIR
INC_DIR = $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_ext

# Define the specified compile options to COMP_DEFS
COMP_DEFS = __FS_FILTER__ \
            __CATEGORY_MODEM__

# Define the source file search paths to SRC_PATH
SRC_PATH = $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_ext

ifeq ($(strip $(PLATFORM)), MT6280)
  SRC_RULE_AUTOTCM := ALL  
  TARGET_AUTOTCM_LIST := NO_LIST modem/ul1/ul1_hs_plus/ul1d_ext/auto_tcm_variable_list_mt6280_ul1_hs_plus_ext.txt
else ifeq ($(strip $(PLATFORM)), MT6290)
  SRC_RULE_AUTOTCM := ALL
  TARGET_AUTOTCM_LIST := NO_LIST modem/ul1/ul1_hs_plus/ul1d_ext/auto_tcm_variable_list_mt6589_ul1_hs_plus_ext.txt
else ifeq ($(strip $(PLATFORM)), MT6595)
  SRC_RULE_AUTOTCM := ALL
  TARGET_AUTOTCM_LIST := NO_LIST modem/ul1/ul1_hs_plus/ul1d_ext/auto_tcm_variable_list_mt6589_ul1_hs_plus_ext.txt
else ifeq ($(strip $(PLATFORM)), MT6795)
  SRC_RULE_AUTOTCM := ALL
  TARGET_AUTOTCM_LIST := NO_LIST modem/ul1/ul1_hs_plus/ul1d_ext/auto_tcm_variable_list_mt6589_ul1_hs_plus_ext.txt
else ifeq ($(strip $(PLATFORM)), MT6752)
  SRC_RULE_AUTOTCM := ALL
  TARGET_AUTOTCM_LIST := NO_LIST modem/ul1/ul1_hs_plus/ul1d_ext/auto_tcm_variable_list_mt6589_ul1_hs_plus_ext.txt  
else
  $(warning ERROR: No AutoTCM Placement List for This Platform!)
endif
NOT_USE_CATEGORY_INCLUDE = TRUE
