#ifndef __GPIO_COMMON_HW_H__
#define __GPIO_COMMON_HW_H__
#if defined(DRV_GPIO_NEW_INIT_ARCHI)

#if defined(DRV_GPIO_REG_AS_6280)
#include "gpio6280_hw.h"
#endif//defined(DRV_GPIO_REG_AS_6280)

#else //defined(DRV_GPIO_NEW_INIT_ARCHI)
#include "gpio_hw.h"
#endif//defined(DRV_GPIO_NEW_INIT_ARCHI)

#endif//__GPIO_COMMON_HW_H__