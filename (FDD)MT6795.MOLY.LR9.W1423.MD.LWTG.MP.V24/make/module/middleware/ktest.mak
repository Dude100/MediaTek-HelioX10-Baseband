# Define source file lists to SRC_LIST
SRC_PATH = middleware/mtkdebug/ktest
ifneq ($(filter __KTEST__, $(strip $(MODULE_DEFS))),)
SRC_LIST += middleware/mtkdebug/ktest/kal_autotest.c \
		   middleware/mtkdebug/ktest/ktest_adaptation_oscar.c \
           middleware/mtkdebug/ktest/ktest_tc_timer.c \
           middleware/mtkdebug/ktest/ktest_tc_nu_timer.c \
           middleware/mtkdebug/ktest/ktest_lib_timer.c \
           middleware/mtkdebug/ktest/ktest_adaptation_target.c \
           middleware/mtkdebug/ktest/ktest_fsm.c \
           middleware/mtkdebug/ktest/ktest_interface.c \
           middleware/mtkdebug/ktest/ktest_tc_ipc.c \
           middleware/mtkdebug/ktest/ktest_tc_mm_adm.c \
           middleware/mtkdebug/ktest/ktest_tc_mm_afm.c \
           middleware/mtkdebug/ktest/ktest_tc_mm_ctrlbuf.c  \
           middleware/mtkdebug/ktest/ktest_tc_task.c \
           middleware/mtkdebug/ktest/ktest_tc_utl.c \
           middleware/mtkdebug/ktest/ktest_tc_sandbox.c \
           middleware/mtkdebug/ktest/ktest_tc_mlib.c \
           middleware/mtkdebug/ktest/ktest_tc_slmm.c \
           middleware/mtkdebug/ktest/ktest_tc_vm.c
endif 
#  Define include path lists to INC_DIR
INC_DIR = interface/service/config \
          interface/service/kal \
          interface/driver/peripheral \
          interface/service/tst \
          interface/driver/hwdrv \
          middleware/mtkdebug/ktest \
          service/kal/adaptation/include \
          service/kal/common/include \
          service/kal/mlib/include \
          service/kal/nucleus/include \
          service/kal/oscar/include \
          interface/sap/svc \
          service/fsm/include \
          driver/sys_drv/cache/inc/ \
          service/sys_svc/dp/inc \
          service/sst/include \
          modem/interface \
          modem/interface/general \
          interface/service/fsm \
          service/nucleus_v2/inc \
          service/nucleus/inc 

# Define the specified compile options to COMP_DEFS
COMP_DEFS =

 
