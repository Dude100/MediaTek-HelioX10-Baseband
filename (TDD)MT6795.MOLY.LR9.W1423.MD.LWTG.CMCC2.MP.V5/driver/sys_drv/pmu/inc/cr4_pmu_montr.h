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
 *   cr4_pmu_montr.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file for CR4 performance monitor driver
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
#ifndef _CR4_PMU_MONTR_H
#define _CR4_PMU_MONTR_H
#if defined(__CR4__)
#include "kal_general_types.h"

typedef enum
{
    PMU_EVENT_ICACHE_MISS       =0x01,
    PMU_EVENT_DCACHE_MISS       =0x03,
    PMU_EVENT_DCACHE_ACCESS     =0x04,
    PMU_EVENT_DATA_READ         =0x06,
    PMU_EVENT_DATA_WRITE        =0x07,
    PMU_EVENT_INSTRUCTION_EXE   =0x08,
    PMU_EVENT_EXCEPTION         =0x09,
    PMU_EVENT_EXCEPTION_RETURN  =0x0A,  // RFE, MOVS PC, LDM Rn, {..,PC}^ ...
    PMU_EVENT_CONTEXT_ID_CHANGE =0x0B,
    PMU_EVENT_DIRECT_PC_CHANGE  =0x0C,  // PC change except by exception
    PMU_EVENT_BRANCH_IMMEDIATE  =0x0D,  // B imm, BL imm, BLX imm (either taken or not taken)
    PMU_EVENT_PROC_RETURN       =0x0E,
    PMU_EVENT_UNALIGNED_ACCESS  =0x0F,
    PMU_EVENT_BRANCH_PENALTY    =0x10,  // Branch mis-prediction or not predict (pipeline flush cause by branch)
    PMU_EVENT_CYCLE_COUNT       =0x11,
    PMU_EVENT_BRANCH_NO_PENALTY =0x12,  // Branches that is correctly predicted
    PMU_EVENT_IBUFFER_STALL     =0x40,  // Stall by instruction buffer cannot deliever instruction for running
    PMU_EVENT_DATA_DEP_STALL    =0x41,  // Stall by data dependency
    PMU_EVENT_DCACHE_WRITEBACK  =0x42,
    PMU_EVENT_EXTMEM_REQ        =0x43,  // CacheLine fill, cache write through, cache write back, non-cacheable access
    PMU_EVENT_LSU_STALL         =0x44,  // Stall by Load-store unit (accessing external bus)
    PMU_EVENT_BUFFER_DRAIN      =0x45,  // DMB, DSB, Strongly-ordered access etc..
    PMU_EVENT_FIQ_MASK_CYCLE    =0x46,
    PMU_EVENT_IRQ_MASK_CYCLE    =0x47,
    PMU_EVENT_STR_BUFFER_MERGE  =0x50,
    PMU_EVENT_STR_BUF_FULL_STALL=0x51,
    PMU_EVENT_STR_QUE_FULL_STALL=0x52,
    PMU_EVENT_INTEGER_DIV       =0x53,  // Divide instruction executed (SDIV, UDIV)
    PMU_EVENT_INTEGER_DIV_STALL =0x54,
    PMU_EVENT_PLD_LINEFILL      =0x55,
    PMU_EVENT_PLD_NOOP          =0x56,
    PMU_EVENT_NONCACHEABLE_ACC  =0x57,  // Non-cacheable access on AXI bus
    PMU_EVENT_ICACHE_ACCESS     =0x58,    
    PMU_EVENT_DUAL_ISSUE        =0x5E,    
} PMU_MONITOR_EVENT_TYPE;

#define PMU_EVENT_MASK            0xFF

#define PMU_CTRL_CYCLE_COUNT_DIV  0x00000008
#define PMU_CTRL_CYCLE_COUNT_RST  0x00000004
#define PMU_CTRL_EVENT_COUNT_RST  0x00000002
#define PMU_CTRL_ENABLE           0x00000001

/***********************************************************
 *  Public APIs
 ***********************************************************/
extern void CR4PMU_Initialize(void);
extern void CR4PMU_CycleCountDivide(kal_bool en);
extern void CR4PMU_SetEvent(kal_uint32 counter, PMU_MONITOR_EVENT_TYPE event);
extern void CR4PMU_StartCounter(kal_uint32 start_counter);
extern void CR4PMU_StopCounter(kal_uint32 stop_counters);
extern kal_uint32 CR4PMU_ReadCounter(kal_uint32 counter);
extern kal_uint32 CR4PMU_ResetCounter(kal_uint32 counter);
#endif /* __CR4__ */
#endif /* _CR4_PMU_MONTR_H */
