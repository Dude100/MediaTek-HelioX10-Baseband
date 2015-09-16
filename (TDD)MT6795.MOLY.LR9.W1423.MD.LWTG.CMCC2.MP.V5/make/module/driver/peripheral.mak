# Define source file lists to SRC_LIST
SRC_LIST = driver/peripheral/src/dcl_rtc.c \
		   driver/peripheral/src/auxmain.c \
		   driver/peripheral/src/rtc.c \
		   driver/peripheral/src/drv_comm.c \
		   driver/peripheral/src/drv_hisr.c \
       driver/peripheral/src/dcl_gpio.c \
       driver/peripheral/src/dcl_i2c.c \
       driver/peripheral/src/dcl_wdt.c \
       driver/peripheral/src/dcl_gpt.c \
       driver/peripheral/src/dcl_gpt_hw.c \
       driver/peripheral/src/dcl_pwm.c \
       driver/peripheral/src/dcl_adc.c \
       driver/peripheral/src/adc.c \
       driver/peripheral/src/adcmeasure.c \
       driver/peripheral/src/adcsche.c \
       driver/peripheral/src/gpio.c \
       driver/peripheral/src/wdt.c \
       driver/peripheral/src/pwm.c \
       driver/peripheral/src/dcl_chr_det.c \
       driver/peripheral/src/dcl_pmu.c \
       driver/peripheral/src/dcl_pmu_common.c \
       driver/peripheral/src/dcl_pw.c \
       driver/peripheral/src/DclH_kbd.c\
       driver/peripheral/src/Dcl_SeriPortDrv.c\
       driver/peripheral/src/uart.c\
       driver/peripheral/src/uart_vfifo.c\
       driver/peripheral/src/uart_handler.c\
       driver/peripheral/src/i2c_dual.c \
       driver/peripheral/src/f32k_clk.c \
       driver/peripheral/src/dcl_f32k_clk.c \
       driver/peripheral/src/gpio_setting.c \
       driver/peripheral/src/dbgprint.c
# accdet
ifneq ($(filter __ACCDET_SUPPORT__, $(strip $(MODULE_DEFS))),)
  ifeq ($(filter __L1_STANDALONE__, $(strip $(MODULE_DEFS))),)
    SRC_LIST    += driver/peripheral/src/accdet.c
  endif
endif
ifneq ($(filter __ACCDET_HYBRID_SOLUTION_SUPPORT__, $(strip $(MODULE_DEFS))),)
  ifeq ($(filter __L1_STANDALONE__, $(strip $(MODULE_DEFS))),)
    SRC_LIST    += driver/peripheral/src/accdet.c
  endif
endif


# PMU
ifeq ($(strip $(PMIC)),MT6235PMU)
   SRC_LIST    += driver/peripheral/src/dcl_pmu6235.c
endif
ifneq ($(filter MT6236PMU MT6921PMU, $(strip $(PMIC))),)
   SRC_LIST    += driver/peripheral/src/dcl_pmu6236.c
   SRC_LIST    += driver/peripheral/src/pmic_MT6236PMU_drv.c
endif
ifeq ($(strip $(PMIC)),MT6253PMU)
   SRC_LIST    += driver/peripheral/src/dcl_pmu6253.c
endif
ifeq ($(strip $(PMIC)),MT6326_CCCI)
   SRC_LIST    += driver/peripheral/src/dcl_pmic6326_ccci.c
endif
ifeq ($(strip $(PMIC)),MT6326)
   SRC_LIST    += driver/peripheral/src/dcl_pmic6326.c
endif
ifeq ($(strip $(PMIC)),MT6251PMU)
   SRC_LIST    += driver/peripheral/src/dcl_pmu6251.c
   SRC_LIST    += driver/peripheral/src/pmic_MT6251PMU_drv.c
endif
ifeq ($(strip $(PMIC)),MT6252PMU)
   SRC_LIST    += driver/peripheral/src/dcl_pmu6252.c
endif
ifeq ($(strip $(PMIC)),MT6253ELPMU)
   SRC_LIST    += driver/peripheral/src/dcl_pmu6252.c
endif
ifeq ($(strip $(PMIC)),MT6256PMU)
   SRC_LIST    += driver/peripheral/src/dcl_pmu6256.c \
   			   driver/peripheral/src/dcl_pmu6256_init.c
endif
ifeq ($(strip $(PMIC)),MT6255PMU)
   SRC_LIST    += driver/peripheral/src/dcl_pmu6255.c \
   			   driver/peripheral/src/dcl_pmu6255_init.c
endif
ifeq ($(strip $(PMIC)),MT6276PMU)
   SRC_LIST    += driver/peripheral/src/dcl_pmu6276.c
   SRC_LIST    += driver/peripheral/src/pmic_MT6276PMU_drv.c
endif
ifeq ($(strip $(PMIC)),MT6573PMU)
   SRC_LIST    += driver/peripheral/src/dcl_pmu6573.c
endif
ifeq ($(strip $(PMIC)),MT6329)
   SRC_LIST    += driver/peripheral/src/dcl_pmic6329.c \
				driver/peripheral/src/dcl_pmic6329_init.c
endif
ifeq ($(strip $(PMIC)),MT6327)
   SRC_LIST    += driver/peripheral/src/dcl_pmic6327.c \
				driver/peripheral/src/dcl_pmic6327_init.c 
endif
ifeq ($(strip $(PMIC)),MT6320)
   SRC_LIST    += driver/peripheral/src/dcl_pmic6320.c \
				driver/peripheral/src/dcl_pmic6320_init.c \
				driver/peripheral/src/mt6589_pmic_wrap.c
endif
ifeq ($(strip $(PMIC)),MT6323)
   SRC_LIST    += driver/peripheral/src/dcl_pmic6323.c \
				driver/peripheral/src/dcl_pmic6323_init.c \
				driver/peripheral/src/pmic_wrap.c
endif
ifeq ($(strip $(PMIC)),MT6325)
COMP_DEFS += DRV_PMIC_WRAP_6752_REG DRV_PMIC_WRAP_V2
SRC_LIST    += driver/peripheral/src/dcl_pmic6325.c \
               driver/peripheral/src/dcl_pmic6325_init.c \
               driver/peripheral/src/pmic_wrap.c
endif

ifneq ($(filter __DMA_UART_VIRTUAL_FIFO__, $(strip $(MODULE_DEFS))),)
	SRC_LIST    += driver/peripheral/src/uart_vfifo.c
endif

# HIF
# for HQA HIF/NFI concurrency test
ifneq ($(filter __NAND_FLASH_HARDWARE_TEST__, $(strip $(MODULE_DEFS))),)
    ifneq ($(filter __MAUI_BASIC__, $(strip $(MODULE_DEFS))),)
      SRC_LIST += driver/peripheral/src/hif_v2_test.c
    endif
endif       

COMP_DEFS += DRV_HTS_OFF
COMP_DEFS += DRV_STS_OFF


# Define include path lists to INC_DIR
INC_DIR =  \
          driver/peripheral/inc \
          driver/devdrv/dma/inc \
          interface/driver/connectivity/usb_driver \
          driver/connectivity/usb_driver/inc \
          driver/drv/include \
          custom/driver/drv/ast \
          $(strip $(BUILD_CODEGENDIR)) \
          interface/service/sys_svc \
          service/sst/include \
          driver/sys_drv/cache/inc \
          interface/service/hif \
         $(call CUSTOM_FLD_MAPPING,custom/driver/drv/misc_drv)
# Define the specified compile options to COMP_DEFS
COMP_DEFS = __DRV_COMM_INIT_DEINIT__

# Define the source file search paths to SRC_PATH
SRC_PATH = driver/peripheral/src

