#ifndef WDT_PUBLIC_H
#define WDT_PUBLIC_H

#include "drv_features_wdt.h"
#include "reg_base.h"
#include "kal_general_types.h"


/*nucleus schedule for WDT restart******************************************/
extern const kal_uint32 g_WATCHDOG_RESTART_REG;
extern const kal_uint32 g_WATCHDOG_RESTART_VALUE;
#if !defined(MT6575)
extern const kal_uint32 g_ABNORMAL_RST_REG;
extern const kal_uint32 g_ABNORMAL_RST_VAL;
#else /* MT6575 */
extern const kal_uint32 g_ABNORMAL_RST_REG;
extern const kal_uint32 g_ABNORMAL_RST_VAL; 
#endif /* MT6575 */
/*******************************************/

//WDT_RESINTERVAL will be 0xfff(default) when the first bootup, then WDT_RESINTERVAL will be 0xffa when wdt_init()
//if the value is 0xfff when bootup,we will kown this is the first bootup or normal reset
//if the value is 0ffa when bootup,we will kown this is abnormal reset
extern kal_bool Is_WDT_Init(void);

extern kal_uint32 Get_WATCHDOG_BASE(void);

extern kal_uint32 Get_WATCHDOG_RESTART_CMD(void);


#endif


