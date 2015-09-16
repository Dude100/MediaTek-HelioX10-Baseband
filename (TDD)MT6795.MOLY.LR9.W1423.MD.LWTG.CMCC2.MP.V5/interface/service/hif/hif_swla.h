#ifndef __INC_HIF_SWLA_H
#define __INC_HIF_SWLA_H

/*
 *  Purpose:
 *      Allow SWLA customLog profile.
 *      You can acquire the counter between HIF_SWLA_START() and HIF_SWLA_STOP().
 *
 *  Usage:
 *      step 1. Invoke HIF_SWLA_START() to start SWLA customLog in your function.
 *
 *      step 2. Invoke HIF_SWLA_STOP() to stop SWLA customLog in your function.
 *
 *      step 3. Use ELT to ASSERT MTK device and then MEMDUMP SWLA result.
 *              
 */


#if defined HIF_SWLA_CUSTOM_LOG
#include "swla_public.h"
#define HIF_SWLA_START(_x)      SLA_CustomLogging(_x, SA_start)
#define HIF_SWLA_STOP(_x)       SLA_CustomLogging(_x, SA_stop)

#else
#define HIF_SWLA_START(_x)
#define HIF_SWLA_STOP(_x)

#endif

#endif /* __INC_HIF_SWLA_H */
