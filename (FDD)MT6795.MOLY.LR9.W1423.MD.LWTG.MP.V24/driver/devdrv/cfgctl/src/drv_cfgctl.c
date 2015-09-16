#include <kal_general_types.h>
#include <reg_base.h>
#include <drv_comm.h>

#ifdef MT6290

#define REG_SW_MISC                   (BASE_ADDR_MDCFGCTL + 0x50)

#define SPECIAL_REG_KEY               (0x34680000)

void drv_cfgctl_clear_misc()
{
    DRV_WriteReg32(REG_SW_MISC, SPECIAL_REG_KEY);
}

void drv_cfgctl_set_misc(kal_uint32 data)
{
    DRV_WriteReg32(REG_SW_MISC, SPECIAL_REG_KEY|data);
}

#else

void drv_cfgctl_clear_misc()
{
}

void drv_cfgctl_set_misc(kal_uint32 data)
{
}

#endif
