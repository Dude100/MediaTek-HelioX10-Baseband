#ifndef __BL_DRAMC_DRV_H__
#define __BL_DRAMC_DRV_H__

#include "dramc_hw.h"
#include "emi_hw.h"
#include "sync_data.h"
#include "custom_EMI_release.h"
#include "custom_EMI.h"
#if defined(BL_ENABLE)
#include "bl_GPT.h"
#include "sw_types.h"
#include "bl_common.h"
#include "bl_drv_common.h"
#elif defined(__DOWNLOAD_AGENT__)
#include "brom_gpt_drv.h"
#include "drv_comm.h"
#include "debug_print.h"
#else
#include <base/drv/drv_common.h>
#include <base/ut/ut_common.h>
#endif

#define GRAY_ENCODED(a) (a)

// TODO: Guo-Huei Chang: Why need to add "delay_a_while(1000)" ???
#define DDR_PHY_RESET()    \
do {    \
    DRV_SetReg32(DRAMC_PHYCTL1, DRAMC_PHYCTL1_PHYRST);    \
    DRV_SetReg32(DRAMC_GDDR3CTL1, DRAMC_GDDR3CTL1_RDATRST);    \
    BL_GPT_UDELAY(1);    \
    DRV_ClrReg32(DRAMC_PHYCTL1, DRAMC_PHYCTL1_PHYRST);    \
    DRV_ClrReg32_NPW(DRAMC_GDDR3CTL1, DRAMC_GDDR3CTL1_RDATRST);    \
    Data_Mem_Barrier(); \
} while(0)

#ifndef BL_ENABLE
typedef enum {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
    LOG_CRIT,
    LOG_NONE,
} RAMC_LOG_LEVEL;

#if defined(__DOWNLOAD_AGENT__)
#define BL_PRINT(level, fmt,args...)    \
do {    \
    if (level >= LOG_LEVEL) {           \
        dbg_printf(fmt,##args);         \
    }   \
} while(0)
#define BL_GPT_UDELAY(us)       gpt_delay_us(us)
#else
#define BL_PRINT(fmt,args...)
#define BL_GPT_UDELAY(us)       UT_UDELAY(us)
#endif


#endif

#endif // end of __BL_DRAMC_DRV_H__
