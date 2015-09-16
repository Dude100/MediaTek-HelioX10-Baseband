TARGET_SRC_LIST = service/fs/fat/src/fs_kal.c \
                  service/fs/fat/src/rtfbs.c \
                  service/fs/fat/src/rtfex.c \
                  service/fs/fat/src/format.c \
                  service/fs/fat/src/rtfiles.c \
                  service/fs/fat/src/rtfcore.c \
                  service/fs/fat/src/rtfbuf.c \
                  service/fs/common/src/fs_internal_api.c \
                  service/fs/common/src/fs_sst.c \
                  service/fs/Efs/src/fs_internal.c \
                  service/fs/Efs/src/fs_func.c \
                  service/fs/Efs/src/fs_func_adv.c \
                  service/fs/Efs/src/fs_func_async.c \
                  service/fs/Efs/src/fs_utility.c \
                  service/fs/Efs/src/fs_task.c \
                  service/fs/Efs/src/fs_usbms.c

MODIS_SRC_LIST = MoDIS_VC9/FileSystem/FileSystemSrc/FSSim_core.c \
                 MoDIS_VC9/FileSystem/FileSystemSrc/FSSim_data.c \
                 MoDIS_VC9/FileSystem/FileSystemSrc/FSSim_supplemental.c


# if defined(__FS_BENCHMARK__)
ifneq ($(filter __FS_BENCHMARK__, $(strip $(MODULE_DEFS))),)
  TARGET_SRC_LIST    += service/fs/Efs/src/fs_task.c
endif

# if !defined(__SMART_PHONE_MODEM__) || !defined(__MTK_TARGET__)
ifeq ($(filter __SMART_PHONE_MODEM__, $(strip $(MODULE_DEFS))),)
	 TARGET_SRC_LIST    += service/fs/Efs/src/fs_internal.c \
	                    service/fs/Efs/src/fs_func.c \
	                    service/fs/Efs/src/fs_func_adv.c
else
  ifeq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
	 TARGET_SRC_LIST    += service/fs/Efs/src/fs_internal.c \
	                    service/fs/Efs/src/fs_func.c \
	                    service/fs/Efs/src/fs_func_adv.c
  endif
endif

# if defined(__FS_TRACE_SUPPORT__)
ifneq ($(filter __FS_TRACE_SUPPORT__, $(strip $(MODULE_DEFS))),)
	TARGET_SRC_LIST    += service/fs/Efs/src/fs_utility.c
endif


# Define source file lists to SRC_LIST
ifneq ($(filter __MTK_TARGET__,$(strip $(MODULE_DEFS))),)
 SRC_LIST = $(TARGET_SRC_LIST)
else
 ifneq ($(filter __FS_MODIS_FDM__,$(strip $(MODULE_DEFS))),)
  SRC_LIST = $(TARGET_SRC_LIST)
 else
  SRC_LIST = $(MODIS_SRC_LIST)
 endif
endif
SRC_LIST    += service/fs/fsal/src/fsal.c \
			service/fs/fsal/src/fsal_buffer.c \
			service/fs/fsal/src/fsal_read.c \
			service/fs/fsal/src/fsal_write.c
			
#  Define include path lists to INC_DIR
ifneq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
 INC_DIR = service/fs/fat/include \
           service/fs/Efs/include \
           driver/drv/include \
           service/fs/common/include \
           middleware/hif/usbclass/msd/include\
           interface/service/hif
else
 ifneq ($(filter __FS_MODIS_FDM__,$(strip $(MODULE_DEFS))),)
  INC_DIR = service/fs/fat/include \
            service/fs/Efs/include \
            driver/drv/include \
            service/fs/common/include \
            middleware/hif/usbclass/msd/include
 else
  INC_DIR = MoDIS_VC9/FileSystem/FileSystemInc
 endif
endif

# Define the source file search paths to SRC_PATH
ifneq ($(filter __MTK_TARGET__,$(strip $(MODULE_DEFS))),)
 SRC_PATH = service/fs/fat/src \
            service/fs/common/src \
            service/fs/Efs/src
else
 ifneq ($(filter __FS_MODIS_FDM__,$(strip $(MODULE_DEFS))),)
  SRC_PATH = service/fs/fat/src \
             service/fs/common/src \
             service/fs/Efs/src
 else
  SRC_PATH = MoDIS_VC9/FileSystem/FileSystemSrc
 endif
endif

SRC_PATH    += service/fs/fsal/src

# Define the specified compile options to COMP_DEFS
COMP_DEFS = NODEBUG
ifneq ($(filter __MTK_TARGET__,$(strip $(MODULE_DEFS))),)
 COMP_DEFS = NODEBUG
else
 ifneq ($(filter __FS_MODIS_FDM__,$(strip $(MODULE_DEFS))),)
  COMP_DEFS = NODEBUG
 else
  COMP_DEFS = 
 endif
endif

COMP_DEFS += CURR_MODULE=MOD_$(strip $(call Upper,$(COMPONENT))) 
