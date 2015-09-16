# Define source file lists to SRC_LIST
SRC_LIST = middleware/meut/UDVT/Dvt_Target_Module/TS/src/dvt_ts.c \
           middleware/meut/UDVT/Dvt_Target_Module/Rgu/src/dvt_RGU.c \
           middleware/meut/UDVT/Dvt_Target_Module/I2c/src/dvt_i2c.c \
           middleware/meut/UDVT/Dvt_Target_Module/Pwm/src/dvt_PWM.c \
           middleware/meut/UDVT/Dvt_Target_Module/SIM/src/dvt_sim.c \
           middleware/meut/UDVT/Dvt_Target_Module/Gpt/src/dvt_gpt.c \
           middleware/meut/UDVT/Dvt_Target_Module/Comm_Protocol/src/dvt_comm_seq.c \
           middleware/meut/UDVT/Dvt_Target_Module/Comm_Protocol/src/dvt_common.c \
           middleware/meut/UDVT/Dvt_Target_Module/Rtc/src/Dvt_Rtc.c \
           middleware/meut/UDVT/Dvt_Target_Module/Adc/src/Dvt_Adc.c \
           middleware/meut/UDVT/Dvt_Target_Module/Uart/src/dvt_uart.c \
           middleware/meut/UDVT/Dvt_Target_Module/Usb/src/dvt_usb.c \
           middleware/meut/UDVT/Dvt_Target_Module/Usb/src/dvt_usbacm_drv.c \
           middleware/meut/UDVT/Dvt_Target_Module/Usb/src/dvt_usb_mode.c \
           middleware/meut/UDVT/Dvt_Target_Module/Usb/src/meut_usb.c \
           middleware/meut/UDVT/Dvt_Target_Module/Usb/src/meut_testcase.c \
           middleware/meut/UDVT/Dvt_Target_Module/Pmu/src/dvt_pmu.c \
           middleware/meut/src/meut_main.c         \
           middleware/meut/src/meut_init.c
 
# Define include path lists to INC_DIR
INC_DIR = driver/drv/include \
          driver/peripheral/inc \
          driver/storage/mc/inc \
          driver/storage/sim/inc \
          service/kal/common/include \
          service/kal/mlib/include \
          middleware/meut/UDVT/Dvt_Target_Module/Comm_Protocol/inc \
          middleware/meut/UDVT/Dvt_Target_Module/Gpt/inc \
          middleware/meut/UDVT/Dvt_Target_Module/Pwm/inc \
          middleware/meut/UDVT/Dvt_Target_Module/Rtc/inc \
          middleware/meut/UDVT/Dvt_Target_Module/I2c/inc \
          middleware/meut/UDVT/Dvt_Target_Module/SIM/inc \
          middleware/meut/UDVT/Dvt_Target_Module/TS/inc \
          middleware/meut/UDVT/Dvt_Target_Module/Rgu/inc \
          middleware/meut/UDVT/Dvt_Target_Module/Uart/inc \
          driver/connectivity/usb_class/include \
          middleware/meut/UDVT/Dvt_Target_Module/Usb/inc \
          middleware/meut/UDVT/Dvt_Target_Module/Pmu/inc \
          middleware/meut/UDVT/Dvt_Target_Module/Adc/inc \
          middleware/mtkdebug \
          driver/drv_def \
          interface/driver/peripheral \
 
# Define the specified compile options to COMP_DEFS
COMP_DEFS =
 
