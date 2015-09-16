#include "kal_general_types.h"
#include "reg_base.h"
#include "bl_drv_common.h"

#define FPGA

#ifdef FPGA
#define HAL_PLATFORM_FPGA
#else
#define HAL_PLATFORM_ASIC
#endif

kal_uint32 bl_clk_get_busclk()
{
#if defined(HAL_PLATFORM_FPGA)
    return 20*1000000;
#else
    return 0;
#endif
}

