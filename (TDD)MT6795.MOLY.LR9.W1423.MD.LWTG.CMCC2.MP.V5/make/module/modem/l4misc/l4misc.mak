# Define source file lists to SRC_LIST
SRC_LIST = $(strip $(MODEM_FOLDER))/l4/uem/src/uem_proc_cmd.c \
           $(strip $(MODEM_FOLDER))/l4/uem/src/uem_proc_msg.c \
           $(strip $(MODEM_FOLDER))/l4/uem/src/uem_main.c \
           $(strip $(MODEM_FOLDER))/l4/uem/src/uem_msg_hdlr.c \
           $(strip $(MODEM_FOLDER))/l4/uem/src/uem_at_cmd.c \
           $(strip $(MODEM_FOLDER))/l4/uem/src/uem_utility.c \
           $(strip $(MODEM_FOLDER))/l4/uem/src/uem_gpio_ctrl.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_common.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_config.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_context.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_control_block.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_data_desc.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_data_entry_table.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_handler_approve.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_handler_delete.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_handler_delete_ln.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_handler_read.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_handler_read_ln.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_handler_sat.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_handler_search.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_handler_startup.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_handler_startup_ln.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_handler_write.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_handler_write_ln.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_ilm.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_main.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_name_num_index.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_nvram_access.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_pindex.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_sap.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_se.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_sim_access.c \
           $(strip $(MODEM_FOLDER))/l4/phb/src/phb_utils.c \
 
#  Define include path lists to INC_DIR
INC_DIR = $(strip $(MODEM_FOLDER))/l4/csm \
          $(strip $(MODEM_FOLDER))/l4/csm/cc/include \
          $(strip $(MODEM_FOLDER))/l4/csm/ss/include \
          $(strip $(MODEM_FOLDER))/l4/include \
          $(strip $(MODEM_FOLDER))/l4/uem/include \
          $(strip $(MODEM_FOLDER))/l4/smu/include \
          $(strip $(MODEM_FOLDER))/l4/atci/include \
          $(strip $(MODEM_FOLDER))/l4/l4c/include/common \
          $(strip $(MODEM_FOLDER))/l4/l4c/include/proc \
          $(strip $(MODEM_FOLDER))/l4/phb/include \
          $(strip $(MODEM_FOLDER))/l4/smsal/include \
          $(strip $(MODEM_FOLDER))/l4/rac/common/include \
          $(strip $(MODEM_FOLDER))/l4/rac/ugrac/include \
          $(strip $(MODEM_FOLDER))/l4/l4a/include \
          $(strip $(MODEM_FOLDER))/interface/l4 \
          $(strip $(MODEM_FOLDER))/interface/l4misc \
          $(strip $(MODEM_FOLDER))/interface/general \
          interface/middleware/meta \
          interface/driver/hwdrv \
          driver/drv_def \
          driver/peripheral/inc


#mtk04121
ifneq ($(filter __ETCM__, $(strip $(MODULE_DEFS))),)
INC_DIR += $(strip $(MODEM_FOLDER))/l4/tcm/etcm/include
endif

ifneq ($(strip $(EUTRAN_MODE_SUPPORT)),NONE)
    INC_DIR += $(strip $(MODEM_FOLDER))/l4/rac/erac/include
endif

# Define the specified compile options to COMP_DEFS
COMP_DEFS = SMG_REL_97 \
            __MOD_UEM__ \
            UART_ENABLE \
            __MOD_CSM__ \
            __MOD_SMU__ \
            __MOD_NVRAM__ \
            __MOD_PHB__ \
            __MOD_SMSAL__ \
            __MOD_ATCI__ \
            __MOD_L4C__ \
            __SMS_PDU_MODE__ \
            __SMS_ME_STORAGE__ \
            __CB__ \
            MP3_SUPPORT \
            __EMS__ \
            SMS_SHOW_REPORT_IN_SIM \
            __UEM_DRV_KPDQUEUE__ \
            __CB_MMI_MASK__ \
            EMS_LITTLE_ENDIAN \
            EMS_MEM_MANAGEMENT \
            SAVE_MSG_TO_SAME_STORAGE \
            DATA_DOWNLOAD \
            __PHB_USIM_MULTI_ADN__ \
            __CATEGORY_MODEM__
 
# Define the source file search paths to SRC_PATH
SRC_PATH = $(strip $(MODEM_FOLDER))/l4/src \
          $(strip $(MODEM_FOLDER))/l4/l4c/src/common \
          $(strip $(MODEM_FOLDER))/l4/atci/src \
          $(strip $(MODEM_FOLDER))/l4/l4c/src/proc \
          $(strip $(MODEM_FOLDER))/l4/uem/src \
          $(strip $(MODEM_FOLDER))/l4/smu/src \
          $(strip $(MODEM_FOLDER))/l4/uem/src  \
          $(strip $(MODEM_FOLDER))/l4/csm \
          $(strip $(MODEM_FOLDER))/l4/csm/cc/src  \
          $(strip $(MODEM_FOLDER))/l4/csm/ss/src  \
          $(strip $(MODEM_FOLDER))/l4/phb/src \
          $(strip $(MODEM_FOLDER))/l4/smsal/src \
          $(strip $(MODEM_FOLDER))/l4/rac/common/src \
          $(strip $(MODEM_FOLDER))/l4/rac/ugrac/src \
          $(strip $(MODEM_FOLDER))/l4/l4a/src \
          $(strip $(MODEM_FOLDER))/l4/tcm/common
 
ifneq ($(filter __UGTCM__, $(strip $(MODULE_DEFS))),)
SRC_PATH += $(strip $(MODEM_FOLDER))/l4/tcm/ugtcm
endif


NOT_USE_CATEGORY_INCLUDE = TRUE
