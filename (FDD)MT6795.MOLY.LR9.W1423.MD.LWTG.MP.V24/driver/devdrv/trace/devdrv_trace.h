#ifndef __DRVTEST_TRACE_H__
#define __DRVTEST_TRACE_H__

#ifndef GEN_FOR_PC
#include "stack_config.h"
#endif

#include "dhl_trace.h"

#if !defined(GEN_FOR_PC)
  #include "devdrv_trace_gen.h"
#endif

#define DRIVER_GROUP_SYSTEM TRACE_GROUP_1

BEGIN_TRACE_MAP(MOD_DEVDRV)
    TRC_MSG(DEVDRV_HELLO_WORLD,       "Hello World!!!")
    TRC_MSG(DEVDRV_CURRENT_HISR_ID,   "DEVDRV_HISR:%d")

    /* DCM/LPM Trace */
    TRC_MSG(DCM_COUNTER,          "[DCM] DCM_CNT:%d")
    TRC_MSG(DCM_ACTIVE_CYCLES,    "[DCM] HW_DCM_CYCLES:%d")
    TRC_MSG(LPM_L1,               "[DCM] L1 LPM CON/TIME/L2H/HIDUR:%x, %x, %x, %x")
    TRC_MSG(LPM_L1_CON,           "[DCM] L1 LPM_CON:%x")
    TRC_MSG(LPM_L1_STATUS,        "[DCM] L1 LPM_TTL_TIME/L2H/HIDUR:%x, %x, %x")
    TRC_MSG(LPM_L2,               "[DCM] L2 LPM CON/TIME/L2H/HIDUR:%x, %x, %x, %x")
    TRC_MSG(LPM_L2_CON,           "[DCM] L2 LPM_CON:%x")
    TRC_MSG(LPM_L2_STATUS,        "[DCM] L2 LPM_TTL_TIME/L2H/HIDUR:%x, %x, %x")

END_TRACE_MAP(MOD_DEVDRV)


#endif /* __DRVTEST_TRACE_H__ */
