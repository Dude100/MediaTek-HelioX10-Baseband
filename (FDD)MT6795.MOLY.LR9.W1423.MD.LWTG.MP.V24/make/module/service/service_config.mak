ifeq ($(strip $(RTOS)),NUCLEUS_V2)
  CATEGORY_INCDIRS += service/nucleus_v2/inc
  CATEGORY_INCDIRS += service/kal/common/include
  CATEGORY_INCDIRS += service/kal/nucleus/include
  CATEGORY_INCDIRS += service/kal/mlib/include
endif
ifeq ($(strip $(RTOS)),NUCLEUS)
  CATEGORY_INCDIRS    += service/nucleus/inc
  CATEGORY_INCDIRS += service/kal/common/include
  CATEGORY_INCDIRS += service/kal/nucleus/include
  CATEGORY_INCDIRS += service/kal/mlib/include
endif

ifeq ($(strip $(RTOS)),THREADX)
  CATEGORY_INCDIRS += service/kal/common/include
  CATEGORY_INCDIRS += service/kal/mlib/include
endif

CATEGORY_INCDIRS += service/sst/include
CATEGORY_INCDIRS += service/fs/common/include
CATEGORY_INCDIRS += service/fs/fat/include

CATEGORY_DEFS += 
