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
 *    dcl_pmu_common_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for PMU common function
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 ****************************************************************************/


#ifndef __DCL_PMU_COMMON_SW_H__
#define __DCL_PMU_COMMON_SW_H__

#include "dcl.h"
#include "intrCtrl.h"

#if !defined(__UBL__)
// PMIC DCL ACCESS Time Log Enable
#define DCL_PMIC_ACCESS_TIME_LOG
#endif

#ifndef __DRV_DEBUG_PMU_REG_READ_WRITE__
#define PMU_DRV_ClearBits16(addr, data)             DRV_ClearBits(addr,data)
#define PMU_DRV_SetBits16(addr, data)               DRV_SetBits(addr,data)
#define PMU_DRV_WriteReg16(addr, data)              DRV_WriteReg(addr, data)
#define PMU_DRV_ReadReg16(addr)                     DRV_Reg(addr)
#define PMU_DRV_ReadReg32(addr)                     DRV_Reg32(addr)
#define PMU_DRV_SetData16(addr, bitmask, value)     DRV_SetData(addr, bitmask, value)
#else // #ifndef __DRV_DEBUG_PMU_REG_READ_WRITE__
#define PMU_DRV_ClearBits16(addr,data)              DRV_DBG_ClearBits(addr,data)
#define PMU_DRV_SetBits16(addr, data)               DRV_DBG_SetBits(addr, data)
#define PMU_DRV_WriteReg16(addr, data)              DRV_DBG_WriteReg(addr, data)
#define PMU_DRV_ReadReg16(addr)                     DRV_DBG_Reg(addr)
#define PMU_DRV_ReadReg32(addr)                     DRV_DBG_Reg32(addr)
#define PMU_DRV_SetData16(addr, bitmask, value)     DRV_DBG_SetData(addr, bitmask, value)
#endif // #ifndef __DRV_DEBUG_PMU_REG_READ_WRITE__

#define PMU_SaveAndSetIRQMask()    SaveAndSetIRQMask()
#define PMU_RestoreIRQMask(n)      RestoreIRQMask(n)

#define M(mod) (((DCL_UINT64)1)<<mod)
#define NM(mod)  (~(((DCL_UINT64)1)<<mod))
#define ONSEL(modlist) (modlist)
#define OFFSEL(modlist) (~(modlist))


#define ISLDO(mod) ((M(mod)&LDO_GROUP)>0)

// module control
#define PMU_UNSUPPORT_MOD 0x00

// PARAMETER control
#define PARAMETERVAL_UNKNOWN 0xffffffff
#define PARAMETER_UNKNOWN 0xffff

#define ALLMOD	0xff
#define MODMASK ALLMOD
#define CMDMASK 0xffff00
#define ENC(cmd,mod) (((cmd<<8)+mod))
#define GETARRNUM(array) (sizeof(array)/sizeof(array[0]))
#define GENFUN(fun) fun,GETARRNUM(fun)

#define GETLDOIDX(mod) (pmuModtoIdx[mod])
#define GETBUCKIDX(mod) (pmuModtoIdx[mod])

#define PMU_SaveAndSetIRQMask()    SaveAndSetIRQMask()
#define PMU_RestoreIRQMask(n)      RestoreIRQMask(n)

typedef void    DCL_VOID;

typedef struct
{
	DCL_UINT32 cmd;
	const DCL_VOID *pVals;
	const DCL_VOID  *pRegVals;
	DCL_UINT8 size;
}PMU_PARAMETER_TABLE_ENTRY;

typedef struct
{
	DCL_UINT32 modidx;
	DCL_UINT32	addr;
	DCL_UINT32	usageBitMap;
}PMU_MOD_BASEADDR_ENTRY;


typedef struct
{
	DCL_UINT8 flagname;
	DCL_UINT8 offset;
	DCL_UINT16 mask;
	DCL_UINT8 shift;	
}PMU_FLAG_TABLE_ENTRY;

typedef struct
{
	DCL_UINT16 offset;
	DCL_UINT16 mask;
	DCL_UINT8 shift;	
}PMIC_FLAG_TABLE_ENTRY;

typedef enum
{
	PMIC_ECO_E1 = 0,
	PMIC_ECO_E2,
	PMIC_ECO_E3,
	PMIC_ECO_E4,
	PMIC_ECO_E5,
	PMIC_ECO_E6,
	PMIC_ECO_E7,
	PMIC_ECO_E8,
	PMIC_ECO_E9,
	PMIC_ECO_E10,
}PMU_CTRL_PMIC_ECO_VERSION_ENUM;

#if defined(DCL_PMIC_ACCESS_TIME_LOG)
#define MAX_PMIC_DURATION_INFO_SIZE				256
#define PMIC_ACCESS_DURATION_THRESHOLD			60

typedef struct
{
   DCL_UINT32 start_time;
   DCL_UINT32 end_time;
   DCL_UINT32 duration_time;
   DCL_UINT32 cmd;
   DCL_UINT32 pmu_time_start;
   DCL_UINT32 pmu_time_end;
   DCL_UINT32 pmu_time_duration;
   DCL_UINT32 pmu_time_qbit;
   DCL_UINT32 gpt3_time_start;
   DCL_UINT32 gpt3_time_end;   
   DCL_UINT32 gpt4_time_start;
   DCL_UINT32 gpt4_time_end;
   DCL_UINT32 ust_get_current_time_action1;
   DCL_UINT32 ust_get_current_time_action2;
   DCL_UINT32 ust_get_current_time_action3;
   DCL_UINT32 ust_get_current_time_action4;
   DCL_UINT32 ust_get_current_time_action5;   
   DCL_UINT32 drv_get_current_time_start;
   DCL_UINT32 drv_get_current_time_start1;
   DCL_UINT32 drv_get_current_time_start2;
   DCL_UINT32 drv_get_current_time_action1;
   DCL_UINT32 drv_get_current_time_action2;   
   DCL_UINT32 drv_get_current_time_action3;
   DCL_UINT32 drv_get_current_time_action4;
   DCL_UINT32 drv_get_current_time_action5;   
   DCL_UINT32 drv_get_current_time_end;   
   DCL_UINT32 drv_get_current_time_end1;   
   DCL_UINT32 drv_get_current_time_end2;      
}PMIC_ACCESS_DURATION_DBG;

typedef enum
{
    PMIC_DCL_DBG = 0,
    PMIC_INTERFACE_DBG = 1,
    PMIC_WRAPPER_WAIT_FOR_WACS_FSM_IDLE_DBG = 2,
    PMIC_WRAPPER_WAIT_FOR_WACS_FSM_WFVLDCLR_DBG = 3,
    PMIC_WRAPPER_READ_DBG = 4,
    PMIC_WRAPPER_INIT_DONE_DBG = 5,
    PMIC_WRAPPER_WACS0_WRITE0_DBG = 6,
    PMIC_WRAPPER_WACS0_WRITE1_DBG = 7,
    PMIC_WRAPPER_WACS1_WRITE0_DBG = 8,
    PMIC_WRAPPER_WACS1_WRITE1_DBG = 9,
    PMIC_DURATION_LOG_MAX   
}PMIC_DURATION_DBG_ENUM;

extern PMIC_ACCESS_DURATION_DBG pmic_access_duration_log[PMIC_DURATION_LOG_MAX][MAX_PMIC_DURATION_INFO_SIZE];
extern DCL_UINT32 pmic_access_duration_index;
extern DCL_UINT32 pmic_access_timing_issue_log[MAX_PMIC_DURATION_INFO_SIZE];
extern DCL_UINT32 pmic_access_timing_issue_index;
#endif // End of #if defined(DCL_PMIC_ACCESS_TIME_LOG)

DCL_UINT16 PMU_get_Parameter_Idx(DCL_CTRL_CMD cmd);
DCL_UINT16 PMU_Parameter_to_Value(DCL_CTRL_CMD cmd,DCL_UINT32 val);
DCL_UINT32 PMU_Value_to_Parameter(DCL_CTRL_CMD cmd,DCL_UINT32 val);
void PMU_SetData16(DCL_UINT32 Addr,DCL_UINT16 mask,DCL_UINT16 val);
#endif //#define __DCL_PMU_COMMON_SW_H__


