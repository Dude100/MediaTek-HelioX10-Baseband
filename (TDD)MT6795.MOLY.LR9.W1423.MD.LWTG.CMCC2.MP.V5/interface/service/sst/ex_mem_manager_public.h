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
 *   ex_mem_manager_public.h
 *
 * Project:
 * --------
 *   Moly
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 *  
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
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __EX_MEM_MANAGER_PUBLIC_H__
#define __EX_MEM_MANAGER_PUBLIC_H__

#include "kal_public_defs.h"

typedef enum{    
    EMM_IDLE_TASK_DCM_ENTER = 0,
    EMM_IDLE_TASK_DCM_LEAVE,
    EMM_IDLE_TASK_SLEEP_ENTER,
    EMM_IDLE_TASK_SLEEP_LEAVE,
    EMM_IDLE_TASK_WFI_ENTER,
    EMM_IDLE_TASK_WFI_LEAVE,
    EMM_INT_EXCEPTION_ENTER,
    EMM_EXCEPTION_FLOW_INDEX,
    EMM_SWLA_LOG_MARK,
    EMM_SWLA_LOG_TIME,
    EMM_EPOF_ENTER,
    EMM_INFINITESLEEP_WFI,
    EMM_SW_WDT_TIME,
    EMM_WDT_EN_CALLER,
    EMM_WDT_EN_TIME,
    EMM_WDT_DIS_CALLER,
    EMM_WDT_DIS_TIME,
    EMM_WDT_DRV_RST_CALLER,
    EMM_WDT_DRV_RST_TIME,
    EMM_WDT_ABN_RST_CALLER,
    EMM_WDT_ABN_RST_TIME,
    EMM_EPON,
    EMM_ELM_READ_TAG,
    EMM_ELM_READ_R_ALAT_NS,
    EMM_ELM_READ_R_ALAT,
    EMM_ELM_READ_R_TRANS,
    EMM_ELM_READ_W_ALAT,
    EMM_ELM_READ_W_TRANS,
    EMM_ELM_READ_DURATION,
    EMM_ELM_WRITE_TAG,
    EMM_ELM_WRITE_W_ALAT_NS,
    EMM_ELM_WRITE_R_ALAT,
    EMM_ELM_WRITE_R_TRANS,
    EMM_ELM_WRITE_W_ALAT,
    EMM_ELM_WRITE_W_TRANS,
    EMM_ELM_WRITE_DURATION,
    EMM_INDEX_MAX,
}EMM_LOG_INDEX;

typedef enum {
    EMM_EXCEPTION_RECORD = 0x0,
	EMM_USERSPECIAL_BUF,
    EMM_DBG_INFO,
} EMM_BUF_TYPE;

typedef enum
{
    EMM_DIRECT_WRITE_DORMANT,
    EMM_DIRECT_WRITE_SWLA,
    EMM_DIRECT_WRITE_MAX,
} EMM_DIRECT_WRITE_SM_INDEX;


kal_bool EMM_Init(void);
kal_bool EMM_WriteBootupTrace(kal_uint32 index, kal_uint32 value);
kal_bool EMM_WriteDbgInfo(kal_uint32 index, void* addr);
kal_bool EMM_ClearDbgInfo(void);
kal_bool EMM_GetBufInfo(kal_uint32 *pAddr, kal_uint32 *pSize, EMM_BUF_TYPE type);
kal_bool EMM_DirInfo_Query(kal_uint32 index, kal_uint32 *addr, kal_uint32 *size);
kal_bool EMM_Write_ExceptRecord(void);


#endif //__EX_MEM_MANAGER_PUBLIC_H__

