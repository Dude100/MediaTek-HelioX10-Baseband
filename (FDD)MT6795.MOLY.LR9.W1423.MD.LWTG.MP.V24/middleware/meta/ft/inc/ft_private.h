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
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   ft_private.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   FT private stuff
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/

#ifndef FT_PRIVATE_H
#define FT_PRIVATE_H

#include "ft_msg.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "nvram_struct.h"
#include "l1_types_public.h"
#include "fs_type.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "l1cal.h"
#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
#include "ul1cal.h"
#endif // #if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
/***********************
 * TST module APIs
 **********************/
#include "kal_trace.h"
extern kal_uint8 tst_get_meta_mode_trace_enable();
extern kal_bool tst_set_meta_mode_trace_enable(kal_uint8 enable);

#ifdef	__cplusplus
extern "C" {
#endif

extern kal_uint16   ft_gl_token;
extern kal_uint16   ft_gl_rf_token;
extern kal_uint16   ft_gl_l4aud_token;
extern kal_uint16	ft_gl_l4aud_ind_token;
extern kal_uint16	ft_gl_l4aud_current_volume;
extern peer_buff_struct	*ft_gl_l4aud_peer_buf;
extern kal_uint16   ft_gl_nvram_token;

//extern kal_bool		g_META_DLL_Version_Incorrect;
extern kal_bool   g_b_ft_assert_check_enable;
extern kal_bool   g_b_ver_Incorrect;
extern kal_uint8  g_u1_msg_recv_times;
extern kal_bool   g_b_ft_nvram_rec; // true: get the checksum of the nvram LID, rid
extern kal_bool   g_b_ft_nvram_proc_locally; // true: don't return the CAL integrity data to PC side

/*  for build warning */
extern void FT_FtPMICRegisterRead(ft_PMICRegisterRead_req_T* req, unsigned char RegType);
extern void FT_FtPMICRegisterWrite(ft_PMICRegisterWrite_req_T* req, unsigned char RegType);

/* for backup and restore calibration data */
extern kal_uint8  ft_gl_path_check_flag;
/* for ft event group pointer */
#define FT_EVENT_TIMEOUT                5000       // 10 sec
extern kal_uint32 ft_event_group_ptr;              // event bit map in ft_public.h
/* ------------------------------------------------------------------------- */
typedef struct
{
    kal_uint16         ft_msg_id;
    RfTestCmdType    type;
    RfTestCmdAfc       afcCmd;
    RfTestResultParam  param;
    kal_bool           wait_cnf;
    kal_bool           result_ready;
#if MD_DRV_IS_FHC_SUPPORT == 1
    DTSParam*          pDTSBuf;  // for FDT calibration
    UTSParam*          pUTSBuf;
#endif // #if (MD_DRV_IS_FHC_SUPPORT == 1)
}L1RF_DATA_T;
typedef union
{
    l1cal_agcPathLoss_T     ft_l1cal_agcPathLoss;
    l1cal_rampTable_T       ft_l1cal_rampTable;
    l1cal_afcData_T         ft_l1cal_afcData;
    l1spfc_T                ft_l1spfc;
    l1cal_txiq_T            ft_l1cal_txiq;
    l1cal_interRampData_T   ft_l1cal_interRampData;
    l1cal_crystalAfcData_T  ft_l1cal_crystalAfcData;
    l1cal_crystalCapData_T  ft_l1cal_crystalCapData;
    l1cal_rfspecialcoef_T   ft_l1cal_rfspecialcoef;
    l1cal_txpc_T            ft_l1cal_txpc;
    kal_uint16              m_txpc_subband_compensation[11];
#if MD_DRV_IS_EPSK_TX_SUPPORT == 1
    l1cal_EPSK_interRampData_T  ft_l1cal_epsk_interramp;
#endif // #if MD_DRV_IS_EPSK_TX_SUPPORT == 1

#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
    ul1cal_tempdacData_T    ft_ul1cal_tempdacData;
    ul1cal_pathlossData_T   ft_ul1cal_pathlossData;
    ul1cal_txdacData_T      ft_ul1cal_txdacData;
#if defined(__UL1_HS_PLATFORM__) || defined(__UL1_HS_PLUS_PLATFORM__)
    ul1cal_txPaOctLevData_T ft_ul1cal_txPaOctLevData;
#endif // #if defined(__UL1_HS_PLATFORM__) || defined(__UL1_HS_PLUS_PLATFORM__)
#if defined(__UMTS_R8__)
    ul1cal_pathlossRxdData_T ft_ul1cal_rxdpathlossData;
#endif // #if defined(__UMTS_R8__)
#endif // #if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
}RuntimeUpdate_T;
extern L1RF_DATA_T ft_rfDATA;
extern RuntimeUpdate_T ft_rf_data_pt;

/*******************************************************************************
*
*  ft_fnc.c
*
*******************************************************************************/
void FT_DispatchMessage(ilm_struct* ptrMsg);
void FT_InitCalibrationData(task_entry_struct *task_entry_ptr);
void FT_InitFtData(void);
void FT_WriteTo_NVRAM (ft_nvram_write_req_struct_T* req, peer_buff_struct * peer_buff, ilm_struct* ptrMsg);
void FT_ReadFrom_NVRAM(ft_nvram_read_req_struct_T* req);
void FT_ReadFrom_NVRAM_CNF(nvram_read_cnf_struct*,peer_buff_struct*);
void FT_WriteTo_NVRAM_CNF(nvram_write_cnf_struct*);

/* BaseBand Testing */
void FT_FtRegisterRead         (ft_RegisterRead_req_T       *req, unsigned char RegType);
void FT_FtRegisterWrite        (ft_RegisterWrite_req_T      *req, unsigned char RegType);
void FT_FtADC_GetMeaData       (ft_FtADC_GetMeaData_req_T   *req);

/* Version Info */
extern void FT_GetVersionInfo(void);

/* FT task test alive */
extern void FT_TestAlive(void);

/* FT task Power Off */
extern void FT_PowerOff(void);

/* FT task utility command */
extern void FT_UtilityCommand(ilm_struct *ptrMsg);

/*******************************************************************************
*
*  other module's api
*
*******************************************************************************/
extern kal_uint32 SaveAndSetIRQMask(void);
/***************************
 * FT task self message API
 **************************/
typedef void (*ft_in_proc_call_type) (kal_uint32 arg1, void *arg2);
typedef struct
{
    LOCAL_PARA_HDR
    ft_in_proc_call_type func;
    kal_uint32 func_arg1;
    void *func_arg2;
} ft_in_proc_call_req_struct;
typedef enum
{
    MSG_ID_FT_IN_PROC_CALL_REQ,
    MSG_ID_FT_IN_PROC_CALL_CNF
}FT_TASK_MESSAGE_TYPE;
void ft_send_in_proc_call_req(ft_in_proc_call_type func, kal_uint32 func_arg1, void *func_arg2);
void ft_in_proc_call_handler(ilm_struct *ilm_ptr);
extern kal_char g_FT_debug_buf[128];
/***********************
 * NVRAM module APIs
 **********************/
extern kal_bool nvram_get_disk_file_info(kal_uint32 *diskfilesize, kal_uint32 *freespace, kal_uint32 *overhead);
/***********************
 * CCT module APIs
 **********************/
kal_uint8 ft_cct_check_op_is_support(kal_uint32 query_op_code);

#ifdef __cplusplus
}
#endif // #ifdef __cplusplus

#endif // #ifndef FT_PRIVATE_H

