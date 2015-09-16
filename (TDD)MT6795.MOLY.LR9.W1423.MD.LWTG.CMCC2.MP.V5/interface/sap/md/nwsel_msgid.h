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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/
 /*******************************************************************************
 * Filename:
 * ---------
 *   nwsel.sap
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   NWSEL related message identity definition
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "module_msg_range.h"
/*----------------------- MM_MSG_CODE_BEGIN------------------*/
MODULE_MSG_BEGIN( MSG_ID_NWSEL_CODE_BEGIN )
/* messages received from RAC at RAC_NWSEL_SAP */
    MSG_ID_RAC_NWSEL_ATTACH_REQ = MSG_ID_NWSEL_CODE_BEGIN,
    MSG_ID_RAC_NWSEL_DETACH_REQ,
    MSG_ID_RAC_NWSEL_PLMN_SEARCH_REQ,
    MSG_ID_RAC_NWSEL_INIT_REQ,
    MSG_ID_RAC_NWSEL_RFOFF_REQ, 
    MSG_ID_RAC_NWSEL_SEL_MODE_REQ,
    MSG_ID_RAC_NWSEL_SET_ROAMING_MODE_REQ,
    MSG_ID_RAC_NWSEL_SET_PREFER_RAT_REQ,
    MSG_ID_RAC_NWSEL_PLMN_LIST_REQ,
    MSG_ID_RAC_NWSEL_PLMN_LIST_STOP_REQ,
    MSG_ID_RAC_NWSEL_CSG_LIST_REQ,
    MSG_ID_RAC_NWSEL_CSG_LIST_STOP_REQ,
    MSG_ID_RAC_NWSEL_SET_RAT_MODE_REQ,
    MSG_ID_RAC_NWSEL_UPDATE_UEMODE_REQ, /* should be replaced by the following MSG_ID_RAC_NWSEL_UEMODE_PARAM_UPDATE_REQ */
    MSG_ID_RAC_NWSEL_UEMODE_PARAM_UPDATE_REQ,
    MSG_ID_RAC_NWSEL_RAT_CHANGE_START_REQ,
    MSG_ID_RAC_NWSEL_RAT_CHANGE_FINISH_REQ,
    MSG_ID_RAC_NWSEL_SUSP_RESU_UPDATE_REQ,
    MSG_ID_RAC_NWSEL_ABORT_EMERGENCY_PLMN_SEARCH_REQ,
#ifdef __SGLTE__    
    MSG_ID_RAC_NWSEL_MMDC_MODE_UPDATE_REQ,
    MSG_ID_RAC_NWSEL_MMDC_PS_DOMAIN_ON_REQ,
    MSG_ID_RAC_NWSEL_MMDC_RECOVERY_SEARCH_REQ,
    MSG_ID_RAC_NWSEL_PLMN_SEARCH_ABORT_REQ,
#endif /* __SGLTE__ */
    MSG_ID_RAC_NWSEL_SET_RECOVERY_SEARCH_TIMER_REQ,
    MSG_ID_RAC_NWSEL_GET_RECOVERY_SEARCH_TIMER_REQ,
    MSG_ID_RAC_NWSEL_UE_OPLMN_UPDATE_REQ,
    MSG_ID_RAC_NWSEL_SET_UTRAN_VOICE_DOMAIN_PREFERENCE_REQ,
    MSG_ID_RAC_NWSEL_DATA_SERVICE_STATUS_UPDATE_REQ,

/* messages received from MM at NWSEL_MM_SAP */
    MSG_ID_NWSEL_MM_PLMN_SEARCH_CNF,
    MSG_ID_NWSEL_MM_PLMN_SEARCH_IND,
    MSG_ID_NWSEL_MM_PLMN_LOSS_IND,
    MSG_ID_NWSEL_MM_OUT_OF_SERVICE_IND,
    MSG_ID_NWSEL_MM_PLMN_LIST_CNF,
    MSG_ID_NWSEL_MM_PLMN_LIST_STOP_CNF,
    MSG_ID_NWSEL_MM_CSG_LIST_CNF,
    MSG_ID_NWSEL_MM_CSG_LIST_STOP_CNF,
    MSG_ID_NWSEL_MM_RESUME_IND,
    MSG_ID_NWSEL_MM_SUSPEND_IND,
    MSG_ID_NWSEL_MM_VIRTUAL_MODE_IND,
    MSG_ID_NWSEL_MM_REGN_RESULT_IND,
    MSG_ID_NWSEL_MM_NO_ACTION_IND,
    MSG_ID_NWSEL_MM_EVENT_IND,
    /* #ifdef __LTE_RAT__ */
    MSG_ID_NWSEL_MM_DEACTIVATE_CNF,
    MSG_ID_NWSEL_MM_NAS_CTXT_TRANSFER_CNF,
    MSG_ID_NWSEL_MM_EUTRAN_CAP_UPDATE_CNF,
    /* #endif */
    MSG_ID_NWSEL_MM_CELL_GLOBAL_IDENTITY_INFO_IND,
    MSG_ID_NWSEL_MM_SYS_INFO_IND,
#ifdef __SGLTE__
    MSG_ID_NWSEL_MM_PS_SWITCH_IND,
#endif

/* messages received from MM at NWSEL_EVAL_SAP */
    MSG_ID_NWSEL_EVAL_PLMN_SEARCH_CNF,
    MSG_ID_NWSEL_EVAL_PLMN_SEARCH_IND,
    MSG_ID_NWSEL_EVAL_PLMN_LOSS_IND,
    MSG_ID_NWSEL_EVAL_OUT_OF_SERVICE_IND,
    MSG_ID_NWSEL_EVAL_PLMN_LIST_CNF,
    MSG_ID_NWSEL_EVAL_PLMN_LIST_STOP_CNF,
    MSG_ID_NWSEL_EVAL_CSG_LIST_CNF,
    MSG_ID_NWSEL_EVAL_CSG_LIST_STOP_CNF,
    MSG_ID_NWSEL_EVAL_REGN_RESULT_IND,
    MSG_ID_NWSEL_EVAL_NO_ACTION_IND,
    MSG_ID_NWSEL_EVAL_DEACTIVATE_CNF,
    MSG_ID_NWSEL_EVAL_NAS_CTXT_TRANSFER_CNF,
    MSG_ID_NWSEL_EVAL_SYS_INFO_IND,
    MSG_ID_NWSEL_EVAL_SIGNAL_APPEAR_IND,
#ifdef __SGLTE__
    MSG_ID_NWSEL_EVAL_PS_SWITCH_IND,
#endif
    MSG_ID_NWSEL_EVAL_EMERGENCY_STATUS_UPDATE_IND, // for IMS
/* message received from SIM at MM_SIM_SAP*/
/*TBD*/
/* messages received from RATCM at NWSEL_RATCM_SAP */
    MSG_ID_NWSEL_RATCM_CELL_CHANGE_START_IND,
    MSG_ID_NWSEL_RATCM_CELL_CHANGE_FINISH_IND,
    MSG_ID_NWSEL_RATCM_SIGNAL_APPEAR_IND,

    MSG_ID_NWSEL_CODE_END = MSG_ID_NWSEL_RATCM_SIGNAL_APPEAR_IND,
MODULE_MSG_END( MSG_ID_NWSEL_CODE_TAIL )
/*----------------------- MM_MSG_CODE_END--------------------*/
