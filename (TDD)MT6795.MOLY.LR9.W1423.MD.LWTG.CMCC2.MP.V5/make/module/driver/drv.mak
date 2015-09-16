# Define source file lists to SRC_LIST
SRC_LIST = driver/drv/src/bf.c \
           driver/drv/src/e_compass_sensor.c \
           driver/drv/src/e_compass_main.c \
           driver/drv/src/BC_drv.c

#  Define include path lists to INC_DIR
INC_DIR = driver/drv/include \
          interface/driver/connectivity/usb_driver \
          driver/connectivity/usb_driver/inc \
          driver/storage/flash/mtd/inc \
          driver/storage/flash/fdm/inc \
          driver/storage/mc/inc \
          driver/connectivity/usb_class/include \
          service/sst/include \
          service/ssf/inc \
          driver/drv_def \
          driver/regbase/inc \
          driver/devdrv/dma/inc \
          driver/devdrv/us_counter/inc \
          driver/peripheral/inc

# Define the specified compile options to COMP_DEFS
COMP_DEFS = APCS_INTWORK

# Define the source file search paths to SRC_PATH
SRC_PATH = driver/drv/src \
           driver/connectivity/usb_driver/src \
           driver/storage/mc/src