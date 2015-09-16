# Define source file lists to SRC_LIST
SRC_LIST = driver/connectivity/usb_class/src/usb.c \
           driver/connectivity/usb_class/src/usb_adap.c \
           driver/connectivity/usb_class/src/usb_resource.c \
           driver/connectivity/usb_class/src/usb_mode.c \
           driver/connectivity/usb_class/src/usb_task.c \
           driver/connectivity/usb_class/src/usb_debug_tool.c


# USB LOGGING
ifneq ($(filter __USB_LOGGING__,$(strip $(MODULE_DEFS))),)
SRC_LIST +=driver/connectivity/usb_class/src/usbacm_logging.c
endif
           
 
# USB CDC ACM CLASS
ifneq ($(filter __USB_COM_PORT_ENABLE__,$(strip $(MODULE_DEFS))),)
SRC_LIST +=driver/connectivity/usb_class/src/usbacm_drv.c \
           driver/connectivity/usb_class/src/usbacm_adap.c \
           driver/connectivity/usb_class/src/usbacm_ft.c
endif


# USB STRESS TEST 
ifneq ($(filter __USB_STRESS_TEST__,$(strip $(MODULE_DEFS))),)
SRC_LIST +=driver/connectivity/usb_class/src/usbacm_echo.c
endif


# USB MASS STORAGE CLASS
ifneq ($(filter __USB_MASS_STORAGE_ENABLE__,$(strip $(MODULE_DEFS))),)
SRC_LIST +=driver/connectivity/usb_class/src/usbms_drv.c \
           driver/connectivity/usb_class/src/usbms_adap.c \
           driver/connectivity/usb_class/src/usbms_state.c
endif



# USB MTP CLASS
ifneq ($(filter __USB_IMAGE_CLASS__,$(strip $(MODULE_DEFS))),)
SRC_LIST +=driver/connectivity/usb_class/src/ptp_state.c \
           driver/connectivity/usb_class/src/usbimage_drv.c \
           driver/connectivity/usb_class/src/usbimage_mtp_state.c
endif



# USB WEBCAM CLASS
ifneq ($(filter WEBCAM_SUPPORT,$(strip $(MODULE_DEFS))),)
SRC_LIST +=driver/connectivity/usb_class/src/usbvideo_drv.c \
           driver/connectivity/usb_class/src/usbvideo_state.c
endif



# USB OTG
ifneq ($(filter __OTG_ENABLE__,$(strip $(MODULE_DEFS))),)
SRC_LIST +=driver/connectivity/usb_class/src/usbd.c \
           driver/connectivity/usb_class/src/usb_host_default_drv.c \
           driver/connectivity/usb_class/src/usb_host_ms_drv.c \
           driver/connectivity/usb_class/src/usb_host_ms_state.c \
           driver/connectivity/usb_class/src/usb_host_ms_adap.c \
           driver/connectivity/usb_class/src/usb_host_acm_drv.c \
           driver/connectivity/usb_class/src/otg.c
endif



# ICUSB
ifneq ($(filter __IC_USB_ENABLE__,$(strip $(MODULE_DEFS))),)
SRC_LIST +=driver/connectivity/usb_class/src/icusb_debug_tool.c \
           driver/connectivity/usb_class/src/icusb_eem_adap.c \
           driver/connectivity/usb_class/src/icusb_eem_drv.c \
           driver/connectivity/usb_class/src/icusb_iccd_adap.c \
           driver/connectivity/usb_class/src/icusb_iccd_drv.c
endif




# Define include path lists to INC_DIR
INC_DIR = driver/connectivity/usb_driver/inc \
          driver/connectivity/usb_class/include \
          interface/driver/connectivity/usb_driver \
          service/fs/common/include \
          $(strip $(MODEM_FOLDER))/l4/include \
          interface/driver/peripheral \
          driver/dsp_ram 
# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWOR
 
# Define the source file search paths to SRC_PATH
SRC_PATH = driver/connectivity/usb_class/src
 
