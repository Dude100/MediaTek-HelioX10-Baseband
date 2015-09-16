SRC_LIST = driver/connectivity/sdio_device/src/sdio_custom.c \
    	   driver/connectivity/sdio_device/src/sdio_hw.c \
		   driver/connectivity/sdio_device/src/sdio_queue.c \
		   driver/connectivity/sdio_device/src/sdio_fw.c \
		   driver/connectivity/sdio_device/src/sdio_interrupt.c \
		   driver/connectivity/sdio_device/src/sdio_test_util.c


#  Define include path lists to INC_DIR
INC_DIR = driver/drv_def \
          driver/connectivity/sdio_device/inc \
          driver/regbase/inc \
          driver/sleep_drv


# Define the specified compile options to COMP_DEFS
COMP_DEFS =

# Define the source file search paths to SRC_PATH
SRC_PATH = driver/connectivity/sdio_device/src
