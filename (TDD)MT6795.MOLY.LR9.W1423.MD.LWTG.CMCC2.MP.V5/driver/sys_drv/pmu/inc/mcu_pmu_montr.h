/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   mcu_pmu_montr.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file general ARM core performance monitor API
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MCU_PMU_MONTR_H
#define _MCU_PMU_MONTR_H
#include "kal_general_types.h"
// API Lists:
/*
void MCU_PMU_Initialize(void);
Initialize PMU, also reset all counters
Can only be called once after boot-up

void MCU_PMU_CycleCountDivide(kal_bool en);
Set cycle counter as 64-cycle unit

void MCU_PMU_SetEvent(kal_uint32 counter, PMU_MONITOR_EVENT_TYPE event);
Set event counter #(counter) to log certain event

void MCU_PMU_StartCounter(kal_uint32 start_counter);
General start counter API, ex: MCU_PMU_StartCounter(PMU_EVENT_COUNTER_1|PMU_EVENT_COUNTER_2|PMU_CYCLE_COUNTER);

void MCU_PMU_StopCounter(kal_uint32 stop_counters);
General stop counter API, ex: MCU_PMU_StopCounter(PMU_EVENT_COUNTER_1|PMU_EVENT_COUNTER_2|PMU_CYCLE_COUNTER);

kal_uint32 MCU_PMU_ReadCounter(kal_uint32 counter);
Read counter API, read one counter at a time ex: value = MCU_PMU_ReadCounter(PMU_CYCLE_COUNTER);

kal_uint32 MCU_PMU_ResetCounter(kal_uint32 counter);
Reet counter API, reset one counter at a time ex: MCU_PMU_ResetCounter(PMU_CYCLE_COUNTER);

*/

// Common Macros
#define PMU_EVENT_COUNTER_1       0x00000001
#define PMU_EVENT_COUNTER_2       0x00000002
#define PMU_EVENT_COUNTER_3       0x00000004
#define PMU_CYCLE_COUNTER         0x80000000

// Supported ARM Core:
// ARM11
// Cortex-R4
#if defined(__CR4__) 
// Include core-dependent header file
#include "cr4_pmu_montr.h"

// Total event counter number
#define PMU_EVENT_COUNTER_NUM     3

// Redirect general APIs
#define MCU_PMU_Initialize()              CR4PMU_Initialize()
#define MCU_PMU_CycleCountDivide(en)      CR4PMU_CycleCountDivide((en))
#define MCU_PMU_SetEvent(counter, event)  CR4PMU_SetEvent((counter),(event))
#define MCU_PMU_StartCounter(counter)     CR4PMU_StartCounter((counter))
#define MCU_PMU_StopCounter(counter)      CR4PMU_StopCounter((counter))
#define MCU_PMU_ReadCounter(counter)      CR4PMU_ReadCounter((counter))
#define MCU_PMU_ResetCounter(counter)     CR4PMU_ResetCounter((counter))

//#elif defined(__ARM11_MMU__) /* __CR4__ */
// TBD
#else
#define PMU_EVENT_COUNTER_NUM     0

#define MCU_PMU_Initialize()              ASSERT(0)
#define MCU_PMU_CycleCountDivide(en)      ASSERT(0)
#define MCU_PMU_SetEvent(counter, event)  ASSERT(0)
#define MCU_PMU_StartCounter(counter)     ASSERT(0)
#define MCU_PMU_StopCounter(counter)      ASSERT(0)
#define MCU_PMU_ReadCounter(counter)      ASSERT(0)
#define MCU_PMU_ResetCounter(counter)     ASSERT(0)

#endif /* __ARM11_MMU__ */
#endif /* _MCU_PMU_MONTR_H */
