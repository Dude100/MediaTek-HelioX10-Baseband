##############################################################################
#                             devdrv/usim                                     #
##############################################################################
SRC_LIST  += driver/devdrv/usim/src/dcl_sim.c \
			 driver/devdrv/usim/src/icc_sim_common_mtk.c \
			 driver/devdrv/usim/src/icc_switchControl_al.c \
			 driver/devdrv/usim/src/icc_switchControl_mtk_0.c \
			 driver/devdrv/usim/src/icc_switchControl_mtk_1.c \
			 driver/devdrv/usim/src/usim_smt.c


SRC_PATH  += driver/devdrv/usim/src

# Define the specified compile options to COMP_DEFS
#COMP_DEFS += __NO_PMU__ \
#			 __No_2G_Timer__ \
 #            __temp_mask__ \
#open this flag to enable drv_trace
#COMP_DEFS += __SIM_DRV_TRACE__  \

#In drvtest, we need these flags to do unit test
ifeq ($(strip $(ATEST_ENABLE)),TRUE)
	ifeq ($(strip $(ATEST_DRV_ENABLE)),TRUE)
COMP_DEFS += __T1_HIGT_PRIORITY__ \
			 __CHAINING_TEST__ \
			 __SPEED_TEST__
	endif
endif
			 
#COMP_DEFS += __DBG_MSG__ \

COMP_DEFS += __DBG_MSG__ \
             __TBD__

#INC_DIR   += driver/devdrv/usim/inc \
#			 ps/sim2/include \
#			 dp_engine/che \
#			 base/inc/chip/MT6290 \

#  Define include path lists to INC_DIR
INC_DIR += driver/devdrv/usim/inc \
           service/sst/include \
           driver/regbase/inc \
           driver/devdrv/us_counter/inc \
           $(strip $(MODEM_FOLDER))/sim/include \
