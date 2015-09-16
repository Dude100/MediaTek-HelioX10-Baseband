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

/*******************************************************************************
 * Filename:
 * ---------
 *	drv_hisr.c
 *
 * Project:
 * --------
 *		ALL
 *
 * Description:
 * ------------
 *   This file is intends for driver HISR management.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "drv_comm.h"
#include "hisr_config.h"
#include "drv_hisr.h"
#include "devdrv_ls.h"
#include "us_timer.h"
#include "intrCtrl.h"
#if defined(__DHL_MODULE__)||defined(__TST_MODULE__)
  #include "devdrv_trace.h"
#endif /* __DHL_MODULE__ || __TST_MODULE__ */

/* Debug/Log/Record Configuration */
#define DEVDRV_HISR_TRACE_ENABLE 1
#define DEVDRV_HISR_MEASURE_TIME 1
//#define DEVDRV_DEBUG_TRACE 1

#define MAX_DRV_HISR_DBG_INFO_SIZE 64  /*must be 2^n*/

typedef struct{
   kal_uint32      time_enter;
   kal_uint32      time_leave;
   kal_uint16      tag;
}DRV_HISR_DBG_DATA;

typedef struct{
   DRV_HISR_DBG_DATA dbg_data[MAX_DRV_HISR_DBG_INFO_SIZE];
   kal_uint16        dbg_data_idx;
}DRV_HISR_DBG_STRUCT;

#if defined(_MAUI_SOFTWARE_LA_)
#define SWLA_ACTION_LABEL   (2)
extern void SLA_CustomLogging(kal_char *customJob, kal_int32 saAction);
#endif

kal_hisrid drv_hisr;
kal_uint32 drv_hisr_status[(MAX_DRV_HISR_DEVICE+31)/32];

#if defined(DEVDRV_HISR_TRACE_ENABLE) && (defined(__DHL_MODULE__)||defined(__TST_MODULE__))
    #define DEVDRV_TRC(x...)       \
    do{                            \
        dhl_trace(x);              \
    }while(0)

    //remove us/10ms GPT timer monitor
    kal_uint32 devdrv_hisr_monitor_mask[] = {0xFFCFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
#else /* DEVDRV_HISR_TRACE_ENABLE && (__DHL_MODULE__ || __TST_MODULE__) */
    #define DEVDRV_TRC(...)
#endif /* DEVDRV_HISR_TRACE_ENABLE && (__DHL_MODULE__ || __TST_MODULE__)*/
#define DEVDRV_TRC_LEVEL TRACE_INFO

/* to measure time */
#if defined(DEVDRV_HISR_MEASURE_TIME)
#if defined(__CR4__)
#include "cp15_int.h"
#elif defined(__MTK_MMU_V2__)
#include "mpu_mtk_mmu_v2_int.h"
#endif

#define IFDEF_DEVDRV_HISR_MEASURE_TIME(x) x
kal_uint32 drv_hisr_exec_enter_time[MAX_DRV_HISR_DEVICE];
kal_uint32 drv_hisr_exec_leave_time[MAX_DRV_HISR_DEVICE];
#else
#define IFDEF_DEVDRV_HISR_MEASURE_TIME(x)
#endif /* DEVDRV_HISR_MEASURE_TIME */

void DRV_ERROR_HISR(void);

DRV_HISR_STRUCT DRV_HISR_TABLE[MAX_DRV_HISR_DEVICE];
DRV_HISR_ID     DRV_CURRENT_HISR;

#if defined(DEVDRV_DEBUG_TRACE)
DRV_HISR_DBG_STRUCT DRV_HISR_DBG_INFO_DATA;

void drv_hisr_dbg_trace(DRV_HISR_ID index, kal_uint32 time)
{
    //kal_uint32 savedMask;

    //savedMask = SaveAndSetIRQMask();
    if (DRV_UNKNOWN_HISR_ID != index) /* Means it's enter. */
    {
       DRV_HISR_DBG_INFO_DATA.dbg_data[DRV_HISR_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_HISR_DBG_INFO_SIZE - 1)].tag = (kal_uint16)index;
       DRV_HISR_DBG_INFO_DATA.dbg_data[DRV_HISR_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_HISR_DBG_INFO_SIZE - 1)].time_enter = time;
       DRV_HISR_DBG_INFO_DATA.dbg_data[DRV_HISR_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_HISR_DBG_INFO_SIZE - 1)].time_leave = 0;
    }
    else /* Means it's leave. */
    {
       DRV_HISR_DBG_INFO_DATA.dbg_data[DRV_HISR_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_HISR_DBG_INFO_SIZE - 1)].time_leave = time;
       DRV_HISR_DBG_INFO_DATA.dbg_data_idx++;
    }

    //RestoreIRQMask(savedMask);
}
#else  /* DEVDRV_DEBUG_TRACE */
#define drv_hisr_dbg_trace(x...)
#endif /* DEVDRV_DEBUG_TRACE */


void DRV_ERROR_HISR(void)
{
   ASSERT(0);
}

void DRV_Register_HISR(DRV_HISR_ID hisr_id, VOID_FUNC hisr_func)
{
   ASSERT(hisr_id < MAX_DRV_HISR_DEVICE);
   DRV_HISR_TABLE[hisr_id].hisr_func = hisr_func;
}

// For fix 35 MGM platform over 60 q-bit issue
DEVDRV_LS_INTERNCODE void DRV_HISR(void)
{
   kal_uint16 index;
   kal_uint32 savedMask;
#if defined(_MAUI_SOFTWARE_LA_)
   kal_char   swla_label[4] = "DH ";
#endif

   if (drv_hisr_status[0] != 0)
      index = 0;
   else if (drv_hisr_status[1] != 0)
      index = 32;
#if defined(__UNIFIED_ISR_LEVEL__)
   else if (drv_hisr_status[2] != 0)
   {
      index = 64;
   }
   else if (drv_hisr_status[3] != 0)
   {
      index = 96;
   }
   /* Pseudo HISR_ID, does NOT map to real interupt line */
   else if (drv_hisr_status[6] != 0)
   {
      index = 192;
   }
#endif /* __UNIFIED_ISR_LEVEL__ */
   else
      return;

   while(index<(kal_uint16)MAX_DRV_HISR_DEVICE)
   {
      kal_bool bit_mask;
      kal_uint32 index_shift;
      kal_uint32 status_index;
      
      bit_mask = KAL_FALSE;
      index_shift = 1<<(index%32);
      status_index = index>>5;
      if(drv_hisr_status[status_index] & index_shift)
      {
         bit_mask = KAL_TRUE;
      }
      if (bit_mask == KAL_TRUE)
      {
         DRV_HISR_STRUCT *hisr_pointer;

         hisr_pointer = DRV_HISR_TABLE+index;
         ASSERT(hisr_pointer->hisr_count!=0);
         DRV_CURRENT_HISR = (DRV_HISR_ID)index;
#if defined(DEVDRV_HISR_TRACE_ENABLE)&&(__DHL_MODULE__ || __TST_MODULE__)
         if(devdrv_hisr_monitor_mask[status_index] & index_shift)
         {
            DEVDRV_TRC(DEVDRV_TRC_LEVEL, 0, DEVDRV_CURRENT_HISR_ID, (kal_uint32)index);
         }
#endif /* DEVDRV_HISR_TRACE_ENABLE */
         savedMask = SaveAndSetIRQMask();
#if defined(_MAUI_SOFTWARE_LA_)
         swla_label[2] += index;
         SLA_CustomLogging(swla_label, SWLA_ACTION_LABEL);
#endif
         hisr_pointer->hisr_count--;
         if (hisr_pointer->hisr_count == 0)
         {
            drv_hisr_status[status_index] &= ~(index_shift);
            if (drv_hisr_status[status_index] == 0)
            {
                index |= 0x1F;
            }
         }
         RestoreIRQMask(savedMask);
         drv_hisr_dbg_trace(DRV_CURRENT_HISR, ust_get_current_time());
#if defined(__CR4__)
         IFDEF_DEVDRV_HISR_MEASURE_TIME(CP15_PMU_GET_CYCLE_CNT(drv_hisr_exec_enter_time[DRV_CURRENT_HISR]));
#elif defined(__MTK_MMU_V2__)
         IFDEF_DEVDRV_HISR_MEASURE_TIME(drv_hisr_exec_enter_time[DRV_CURRENT_HISR]=CACHE_FREE_RUN_CYCLE_COUNTER_GET_CYCLE());
#endif
         hisr_pointer->hisr_func();
#if defined(__CR4__)
         IFDEF_DEVDRV_HISR_MEASURE_TIME(CP15_PMU_GET_CYCLE_CNT(drv_hisr_exec_leave_time[DRV_CURRENT_HISR]));
#elif defined(__MTK_MMU_V2__)                  
         IFDEF_DEVDRV_HISR_MEASURE_TIME(drv_hisr_exec_leave_time[DRV_CURRENT_HISR]=CACHE_FREE_RUN_CYCLE_COUNTER_GET_CYCLE());
#endif
         drv_hisr_dbg_trace(DRV_UNKNOWN_HISR_ID, ust_get_current_time());
         DRV_CURRENT_HISR = DRV_UNKNOWN_HISR_ID;
      }//if (bit_mask == KAL_TRUE)
      index++;
   } //while(index<(kal_uint16)MAX_DRV_HISR_DEVICE)
}

void drv_hisr_init(void)
{
   kal_uint32 index;

#if !defined(__UNIFIED_ISR_LEVEL__)
   ASSERT(MAX_DRV_HISR_DEVICE <= (DRV_HISR_ID)64);
#endif /* __UNIFIED_ISR_LEVEL__ */
   for(index=0;index<(kal_uint32)MAX_DRV_HISR_DEVICE;index++)
   {
      DRV_HISR_TABLE[index].hisr_func = DRV_ERROR_HISR;
      DRV_HISR_TABLE[index].hisr_count = 0;
   }
   if (drv_hisr == NULL)
   {
      drv_hisr = kal_init_hisr(DRVHISR);
   }
}

#if !defined(__FUE__) && !defined(__UBL__)

DEVDRV_LS_INTSRAM_ROCODE void drv_active_hisr(DRV_HISR_ID id)
{
    kal_uint32 savedMask;
    
    savedMask = SaveAndSetIRQMask();
    drv_hisr_status[id>>5] |= 1UL<<(id&0x1FUL);

    DRV_HISR_TABLE[id].hisr_count++;

    RestoreIRQMask(savedMask);
    kal_activate_hisr(drv_hisr);
}
#endif


