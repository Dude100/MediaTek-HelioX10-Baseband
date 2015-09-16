#
# Define source file lists to SRC_LIST
#
#

# [cccisrv_task] 
# Control the ccci services (CCCI_FS, CCCI_IPC, CCCI_RPC)
#
SRC_LIST = service/hif/cccisrv/cccisrv_task/src/cccisrv_task.c 


#
# [CCCI_FS] 
#
ifeq ($(strip $(CCCI_FS_SUPPORT)), TRUE)
SRC_LIST += service/hif/cccisrv/ccci_fs/src/ccci_fs.c       \
            service/hif/cccisrv/ccci_fs/src/ccci_fs_apis.c  \
            service/hif/cccisrv/ccci_fs/src/ccci_fs_ut.c    \
            service/hif/cccisrv/ccci_fs/src/ccci_fs_it.c    \
            service/hif/cccisrv/ccci_fs/src/ccci_fs_except.c 
endif

#
# [CCCI_IPC] 
#
SRC_LIST += service/hif/cccisrv/ccci_ipc/src/ccci_ipc.c  	 \
            service/hif/cccisrv/ccci_ipc/src/ccci_ipc_data.c \
            service/hif/cccisrv/ccci_ipc/src/ccci_ipc_ut.c   \
            service/hif/cccisrv/ccci_ipc/src/ccci_ipc_it.c

#
# [CCCI_RPC] 
#
SRC_LIST += service/hif/cccisrv/ccci_rpc/src/ccci_rpc.c  	 \
            service/hif/cccisrv/ccci_rpc/src/ccci_rpc_data.c \
            service/hif/cccisrv/ccci_rpc/src/ccci_rpc_svc.c  \
            service/hif/cccisrv/ccci_rpc/src/ccci_rpc_ut.c   \
            service/hif/cccisrv/ccci_rpc/src/ccci_rpc_it.c   
            
            
#
# [CCCI_IMS] 
#
SRC_LIST 	+= service/hif/cccisrv/ccci_ims/src/ccci_ims.c   \
               service/hif/cccisrv/ccci_ims/src/ccci_ims_it.c


#
# [CCCI_IT_CTRL] 
#
ifneq ($(filter $(strip $(MODULE_DEFS)), __CCCI_IT_CTRL__),)
SRC_LIST 	+= service/hif/ccci_it_ctrl/src/ccci_it_ctrl.c         \
			   service/hif/ccci_it_ctrl/src/ccci_it_ctrl_setting.c \
			   service/hif/ccci_it_ctrl/src/ccci_it_ctrl_q0.c
endif
 
#
# [CCCI_SYS_MSG] 
#
SRC_LIST 	+= service/hif/cccisrv/ccci_sys_msg/src/ccci_sys_msg.c \
               service/hif/cccisrv/ccci_sys_msg/src/ccci_sys_msg_it.c \
               service/hif/cccisrv/ccci_sys_msg/src/ccci_sys_msg_ut.c
#
#  Define include path lists to INC_DIR
#
INC_DIR = interface/service/hif                       \
          service/hif/interface                       \
		  service/hif/cccisrv/cccisrv_task/include    \
		  service/hif/cccisrv/ccci_ipc/include        \
  		  service/hif/cccisrv/ccci_rpc/include        \
		  service/hif/cccisrv/ccci_ims/include        \
		  service/hif/cccisrv/ccci_sys_msg/include

ifneq ($(filter $(strip $(MODULE_DEFS)), __CCCI_IT_CTRL__),)
  INC_DIR +=  service/hif/ccci_it_ctrl/include
endif


ifeq ($(strip $(CCCI_FS_SUPPORT)), TRUE)
INC_DIR += service/hif/cccisrv/ccci_fs/include
endif

# Define the specified compile options to COMP_DEFS
#COMP_DEFS =
# Patch for MoDIS
#ifeq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
#   COMP_DEFS += 
#endif

# Define the source file search paths to SRC_PATH
SRC_PATH = service/hif/cccisrv/cccisrv_task/src \
           service/hif/cccisrv/ccci_ipc/src     \
           service/hif/cccisrv/ccci_rpc/src     \
           service/hif/cccisrv/ccci_ims/src     \
           service/hif/ccci_it_ctrl/src         \
           service/hif/cccisrv/ccci_sys_msg/src

ifeq ($(strip $(CCCI_FS_SUPPORT)), TRUE)
SRC_PATH += service/hif/cccisrv/ccci_fs/src
endif           
