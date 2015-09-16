/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   init_trc_api.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains definitions for trace on target.
 *
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
  
/************************************************************
 * NOTE: prefix of trace id:
 *          TSID_:  can be found in mcu\service\sys_svc\profile\inc\maui_time_stamp_id.h
 *          SST_:   can be found in mcu\driver\sys_drv\init\inc\system_trc.h
 *          BOOT_:  can be found in mcu\driver\sys_drv\init\inc\init_trc_id.h
 ************************************************************/

#ifndef _INIT_TRC_API_H
#define _INIT_TRC_API_H

#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_trace.h"
#include "mcu_pmu_montr.h"
#include "init_trc_id.h"
#include "ccci.h"
#include "ex_mem_manager_public.h"



extern void INT_writeBootLogs(kal_uint32 index, kal_uint32 value);
extern void INT_backupBootLogs(void);

#define TASK_MAGIC 0x4B534154

/* 
 * Macro: INT_Trace_Enter(trc_id, , is_tst_duration)
 *      trc_id: trace id, for TSID and SST
 *      is_tst_duration: record duration or not
 */
 
#define INT_Trace_Enter(trc_id, is_tst_duration) \
    do {  \
        if(is_tst_duration) { \
            print_bootup_trace_enter(SST_##trc_id); \
        } else { \
            print_bootup_trace(SST_##trc_id##_ENTER); \
        } \
        EMM_BOOT_TS(trc_id); \
    } while(0)

/* 
 * Macro: INT_Trace_Exit(trc_id, is_ts, is_tst_duration)
 *      trc_id: trace id, for TSID and SST
 *      is_ts: if TS_BEGIN and TS_END invoked
 *      is_tst_duration: record duration or not
 */

#define INT_Trace_Exit(trc_id, is_tst_duration) \
    do {  \
        if(is_tst_duration) { \
            print_bootup_trace_exit(SST_##trc_id); \
        } else { \
            print_bootup_trace(SST_##trc_id##_EXIT); \
        } \
    } while (0)

/*************************************************************************
  * Bootup trace to CCCI share memory
  *************************************************************************/

#if defined(__CR4__) && defined(__SP_BOOTTRC_ENABLE__) && defined(__MTK_TARGET__)
#define EMM_BOOT_TS(trc_id) \
    if((BOOT_##trc_id > BOOT_INIT_CCCIHS1) && (BOOT_##trc_id <= BOOT_INIT_CCCIHS2)){ \
        EMM_WriteBootupTrace((kal_uint32)BOOT_##trc_id, MCU_PMU_ReadCounter(PMU_CYCLE_COUNTER)); \
    }

#define TASK_Trace(task_index) EMM_WriteBootupTrace((kal_uint32)task_index, MCU_PMU_ReadCounter(PMU_CYCLE_COUNTER));
#define TASK_Trace_Magic(magic1, magic2) EMM_WriteBootupTrace(magic1, magic2);
        
#else
#define EMM_BOOT_TS(trc_id)
#define TASK_Trace(task_index)
#define TASK_Trace_Magic(magic1, magic2)
#endif


/*************************************************************************
  * Bootup trace to Catcher
  *************************************************************************/
#if defined(__KAL_RECORD_BOOTUP_LOG__) || defined(__KEYPAD_DEBUG_TRACE__)

/*
 * NoteXXX: 
 *          (1) Use print_trace(_with_info)() instead of print_bootup_trace(_with_info)()
 *          after TST task init
 *          (2) xxx_enter() and xxx_exit() should be used in a pair
 *          (3) xxx_enter() and xxx_exit() are invalid before TDMA timer is init
 */

#define print_bootup_trace(i) \
        do {  \
            kal_bootup_trace(TRACE_INFO, i); \
        } while (0)

#define print_bootup_trace_enter(i) \
        do {  \
            extern kal_uint32 init_duration; \
            init_duration = drv_get_current_time(); \
            kal_bootup_trace(TRACE_INFO, i##_ENTER); \
        } while (0)

#define print_bootup_trace_exit(i) \
        do {  \
            extern kal_uint32 init_duration; \
            init_duration = drv_get_duration_ms(init_duration); \
            kal_bootup_trace(TRACE_INFO, i##_EXIT, init_duration); \
        } while (0)

#define print_trace(i) \
        do {  \
            kal_trace(TRACE_INFO, i); \
        } while (0)

#define print_bootup_trace_with_info_enter(i, info) \
        do {  \
            extern kal_uint32 init_duration; \
            init_duration = drv_get_current_time(); \
            kal_bootup_trace(TRACE_INFO, i##_ENTER, info); \
        } while (0)

#define print_bootup_trace_with_info_exit(i, info) \
        do {  \
            extern kal_uint32 init_duration; \
            init_duration = drv_get_duration_ms(init_duration); \
            kal_bootup_trace(TRACE_INFO, i##_EXIT, info, init_duration); \
        } while (0)

#define print_trace_with_info_enter(i, info) \
        do {  \
            extern kal_uint32 init_duration; \
            init_duration = drv_get_current_time(); \
            kal_trace(TRACE_INFO, i##_ENTER, info); \
        } while (0)

#define print_trace_with_info_exit(i, info) \
        do {  \
            extern kal_uint32 init_duration; \
            init_duration = drv_get_duration_ms(init_duration); \
            kal_trace(TRACE_INFO, i##_EXIT, info, init_duration); \
        } while (0)

#define print_boot_mode(m) \
        do {  \
            extern void INT_printBootMode(void); \
            INT_printBootMode(); \
        } while (0)
#else /* __KAL_RECORD_BOOTUP_LOG__ || __KEYPAD_DEBUG_TRACE__ */
#define print_bootup_trace(i)
#define print_bootup_trace_enter(i)
#define print_bootup_trace_exit(i)
#define print_trace(i)
#define print_bootup_trace_with_info_enter(i, info)
#define print_bootup_trace_with_info_exit(i, info)
#define print_trace_with_info_enter(i, info)
#define print_trace_with_info_exit(i, info)
#define print_boot_mode(m)
#endif /* __KAL_RECORD_BOOTUP_LOG__ || __KEYPAD_DEBUG_TRACE__ */

#endif	/* _INIT_TRC_API_H */

