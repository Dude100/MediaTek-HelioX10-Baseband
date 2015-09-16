# Define source file lists to SRC_LIST
SRC_LIST = middleware/hif/usbcore/src/usbcore_task.c                           \
           middleware/hif/usbcore/src/usbcore_class_device.c                   \
           middleware/hif/usbcore/src/usbcore_hif.c                            \
           middleware/hif/usbcore/src/usbcore_notify_event.c                   \
           middleware/hif/usbcore/src/usbcore_stdreq.c                         \
           middleware/hif/usbcore/src/usbcore_vendreq.c                        \
           middleware/hif/usbcore/src/usbcore_except.c                         \
           middleware/hif/usbcore/src/usbcore_ind_q.c                          \
           middleware/hif/usbcore/src/usbcore_stack.c                          \
           middleware/hif/usbcore/src/usbcore_resource.c                       \
           middleware/hif/usbcore/src/usbcore_cosim.c

# Define include path lists to INC_DIR
INC_DIR = middleware/hif/interface                                             \
          middleware/hif/usbcore/include \
          interface/driver/hif \
          interface/driver/hif/hif_usbdev \
          interface/service/flc2

# Define the specified compile options to COMP_DEFS
ifdef HIF_USB30_SUPPORT
  ifeq ($(strip $(HIF_USB30_SUPPORT)), TRUE) 
       COMP_DEFS = __USBC_USB30_SUPPORT__
  endif
endif

# Patch for MoDIS
ifeq ($(filter __MTK_TARGET__, $(strip $(MODULE_DEFS))),)
   COMP_DEFS += __USBC_USB30_SUPPORT__
endif

ifneq ($(strip $(MODIS_CONFIG)),TRUE)
    COMP_DEFS += __USBC_TARGET_HIF_DRIVER_SUPPORT__
endif

# Define the source file search paths to SRC_PATH
SRC_PATH = middleware/hif/usbcore/src 

