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
 *   mm.sap
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MM related message identity definition
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
#include "module_msg_range.h"

MODULE_MSG_BEGIN()
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/
#include "module_msg_range.h"

#ifndef _MM_MSG_H
#define _MM_MSG_H

/*----------------------- MM_MSG_CODE_BEGIN------------------*/

MODULE_MSG_BEGIN( MSG_ID_MM_CODE_BEGIN )
/* mesage received from TIMER at MMTIMER SAP */
/*TBD*/

/* messages received from CC at MMCC sap */
    MSG_ID_MMCC_PROMPT_REJ = MSG_ID_MM_CODE_BEGIN,
    MSG_ID_MMCC_PROMPT_RSP,
    MSG_ID_MMCC_REL_REQ,
    MSG_ID_MMCC_EST_REQ,
    MSG_ID_MMCC_REEST_REQ,
    MSG_ID_MMCC_DATA_REQ,
    MSG_ID_MMCC_START_CALL_REQ,
    MSG_ID_MMCC_ABORT_CALL_REQ,
    MSG_ID_MMCC_SRVCC_EST_REQ,
    MSG_ID_MMCC_SRVCC_ABORT_REQ,

/* messages received from SS at MMSS sap */
    MSG_ID_MMSS_EST_REQ,
    MSG_ID_MMSS_DATA_REQ,
    MSG_ID_MMSS_REL_REQ,
/* messages received from SMS at MMSMS sap*/
    MSG_ID_MMSMS_REL_REQ,
    MSG_ID_MMSMS_DATA_REQ,
    MSG_ID_MMSMS_EST_REQ,
#ifdef __SGLTE__ 
    MSG_ID_GMMREG_PS_SWITCH_REQ,
    MSG_ID_GMMREG_PS_SWITCH_SUSPEND_REQ,
    MSG_ID_GMMREG_PS_SWITCH_RESUME_REQ,
#endif
/* messages received from RAC at GMMREG  sap */
    MSG_ID_GMMREG_ATTACH_REQ,
    MSG_ID_GMMREG_DETACH_REQ,
    //MSG_ID_GMMREG_PLMN_SEARCH_REQ,
    MSG_ID_GMMREG_INIT_REQ,
    //MSG_ID_GMMREG_SEL_MODE_REQ,
    MSG_ID_GMMREG_RFOFF_REQ,
    MSG_ID_GMMREG_SET_ROAMING_MODE_REQ,
    //MSG_ID_GMMREG_SET_PREFER_RAT_REQ,
    //MSG_ID_GMMREG_PLMN_LIST_REQ,
    //MSG_ID_GMMREG_PLMN_LIST_STOP_REQ,
    //MSG_ID_GMMREG_CSG_LIST_REQ,
    //MSG_ID_GMMREG_CSG_LIST_STOP_REQ,
    MSG_ID_GMMREG_SET_RAT_MODE_REQ,
    MSG_ID_GMMREG_SET_GPRS_TRANSFER_PREFERENCE_REQ,
    MSG_ID_GMMREG_SET_PREFERRED_BAND_REQ,   /* mtk02475: for set band without reboot*/
    MSG_ID_GMMREG_END_PS_DATA_SESSION_REQ, //mtk02475: for Fast Dormancy
    MSG_ID_GMMREG_ACTIVE_SIM_INFO_REQ,  //for DSDS ,ps on which sim
    MSG_ID_GMMREG_SET_IMS_VOICE_TERMINATION_REQ,
    MSG_ID_GMMREG_SET_IMS_VOICE_AVAILABILITY_REQ,
#if defined (__GEMINI__) || defined (__SGLTE__)
    MSG_ID_GMMREG_SIM_STATUS_UPDATE_REQ,
#endif
#ifdef __LTE_RAT__
    MSG_ID_GMMREG_CSFB_PAGE_RSP,
#endif
/* messages received from EMM at MM_EMM sap */
    MSG_ID_MM_EMM_INIT_NAS_CTXT_IND,
    MSG_ID_MM_EMM_EMM_UPDATE_REGISTRATION_IND,
    MSG_ID_MM_EMM_EMM_UPDATE_DEREGISTRATION_IND,
    MSG_ID_MM_EMM_CSFB_CNF,
    MSG_ID_MM_EMM_CSFB_PAGE_IND,
    MSG_ID_MM_EMM_ISR_UPDATE_IND,
#if defined (__SGLTE__)
    MSG_ID_MM_EMM_PEER_LR_HANDLE_PREPARATION_CNF,
    MSG_ID_MM_EMM_PEER_LR_RESULT_IND,
    /*from 2G MM to 3G MM, or from 3G MM to 2G MM*/
    MSG_ID_MM_MM_PEER_LR_HANDLE_PREPARATION_REQ,
    MSG_ID_MM_MM_PEER_LR_HANDLE_PREPARATION_CNF,
    MSG_ID_MM_MM_PEER_LR_RESULT_IND,
#endif
/* messages received from NWSEL at NWSEL_MM sap */
    MSG_ID_NWSEL_MM_PLMN_SEARCH_REQ,
    MSG_ID_NWSEL_MM_PLMN_LIST_REQ,
    MSG_ID_NWSEL_MM_PLMN_LIST_STOP_REQ,
    MSG_ID_NWSEL_MM_CSG_LIST_REQ,
    MSG_ID_NWSEL_MM_CSG_LIST_STOP_REQ,
    MSG_ID_NWSEL_MM_RESUME_REQ,
    MSG_ID_NWSEL_MM_CELL_GLOBAL_IDENTITY_INFO_UPDATE_REQ,
    MSG_ID_NWSEL_MM_SYS_INFO_UPDATE_REQ,
    MSG_ID_NWSEL_MM_REGN_STATUS_UPDATE_REQ,
    MSG_ID_NWSEL_MM_HPLMN_INFO_UPDATE_REQ,
    /* #ifdef __LTE_RAT__ */
    MSG_ID_NWSEL_MM_DEACTIVATE_REQ,
    MSG_ID_NWSEL_MM_NAS_CTXT_TRANSFER_REQ,
    MSG_ID_NWSEL_MM_SEARCH_STATUS_UPDATE_REQ,
    MSG_ID_NWSEL_MM_EUTRAN_CAP_UPDATE_REQ,
    MSG_ID_NWSEL_MM_EUTRAN_CAP_ABORT_REQ,
    MSG_ID_NWSEL_MM_VOICE_PREFER_UE_USAGE_UPDATE_REQ,
    MSG_ID_NWSEL_MM_ATTACH_RESUME_REQ,
    /* #endif */
#if defined(__LTE_RAT__) && (defined(__GSM_RAT__) || defined(__UMTS_RAT__))  /* dual or multi mode including LTE */
#if (defined(__OP01__)) && (!defined(__SGLTE__))
    MSG_ID_NWSEL_MM_PLMN_SEARCH_ABORT_REQ,
#endif
#endif

/* message received from SIM GMM_SIM_SAP */
/*TBD*/

/* message received from SMS GMM_SMS_SAP*/
    MSG_ID_GMMSMS_EST_REQ,
    MSG_ID_GMMSMS_UNITDATA_REQ,

/* message received from SM GMM_SM_SAP */
    MSG_ID_GMMSM_UNITDATA_REQ,
    MSG_ID_GMMSM_NSAPI_STATUS_REQ,
    MSG_ID_GMMSM_ATTACH_REQ,
    MSG_ID_GMMSM_EST_REQ,
    MSG_ID_GMMSM_RAT_CHANGE_RSP, //  (23G4 finish)
    MSG_ID_GMMSM_RAT_CHANGE_REQ, // (4G23 start)
    MSG_ID_GMMSM_ISR_DEACTIVATE_REQ,  // __LTE_RAT__    ISR Deactivate
#ifdef __SGLTE__ 
    MSG_ID_GMMSM_PS_SWITCH_CONTEXT_TRANSFER_REQ,
    MSG_ID_GMMSM_PS_SWITCH_CONTEXT_TRANSFER_RSP,
#endif
#ifdef __GEMINI__
    MSG_ID_GMMSM_SESSION_BEGIN_REQ,
    MSG_ID_GMMSM_SESSION_END_REQ,
#endif
/* message received from RABM at GMM_RABM_SAP*/
/*TBD*/

/* message received from SIM at MM_SIM_SAP*/
/*TBD*/

/* Temporarily Added the TC MSG_IDs here */
/*TBD*/

/* messages received from RATDM at MM_RATDM_SAP */
    MSG_ID_MM_RATDM_SEQUENCE_CNF,
    MSG_ID_MM_RATDM_REESTABLISH_RAB_IND,
    MSG_ID_MM_RATDM_SEND_USER_DATA_IND,
    MSG_ID_MM_RATDM_RAB_RELEASE_IND,

/* messages received from RATCM at MM_RATCM_SAP */
    MSG_ID_MM_RATCM_SET_RAT_MODE_CNF,
    MSG_ID_MM_RATCM_INIT_CNF,
    MSG_ID_MM_RATCM_RFOFF_CNF,
    MSG_ID_MM_RATCM_PLMN_SEARCH_CNF,
    MSG_ID_MM_RATCM_SYS_INFO_IND,
    MSG_ID_MM_RATCM_SET_IMEI_REQ,
    MSG_ID_MM_RATCM_CELL_GLOBAL_IDENTITY_INFO_IND,
    MSG_ID_MM_RATCM_PLMN_LOSS_IND,
    MSG_ID_MM_RATCM_OUT_OF_SERVICE_IND,
    MSG_ID_MM_RATCM_PLMN_LIST_CNF,
    MSG_ID_MM_RATCM_PLMN_LIST_STOP_CNF,
    MSG_ID_MM_RATCM_CSG_LIST_CNF,
    MSG_ID_MM_RATCM_CSG_LIST_STOP_CNF,
    MSG_ID_MM_RATCM_CELL_CHANGE_START_IND,
    MSG_ID_MM_RATCM_CELL_CHANGE_FINISH_IND,
    MSG_ID_MM_RATCM_PAGE_IND,
    MSG_ID_MM_RATCM_SYNC_IND,
    MSG_ID_MM_RATCM_SECURITY_MODE_COMPLETE_IND,
    MSG_ID_MM_RATCM_SECURITY_MODE_CHANGE_IND,
    MSG_ID_MM_RATCM_CONN_EST_CNF,
    MSG_ID_MM_RATCM_CONN_EST_IND,
    MSG_ID_MM_RATCM_CONN_REL_CNF,
    MSG_ID_MM_RATCM_CONN_REL_IND,
    MSG_ID_MM_RATCM_CONN_LOSS_IND,
    MSG_ID_MM_RATCM_CONN_ABORT_IND,
    MSG_ID_MM_RATCM_READY_TIMER_UPDATE_IND,
    MSG_ID_MM_RATCM_CS_DATA_IND,
    MSG_ID_MM_RATCM_PS_DATA_CNF,
    MSG_ID_MM_RATCM_PS_DATA_IND,
    MSG_ID_MM_RATCM_RESET_KEYS_IND,
    MSG_ID_MM_RATCM_T3122_TIMEOUT_IND,
    MSG_ID_MM_RATCM_CCO_ACTIVATION_TIME_TIMEOUT_IND,
    MSG_ID_MM_RATCM_END_PS_DATA_SESSION_CNF,  /* MAUI_02852442, __NO_PSDATA_SEND_SCRI__ */
    MSG_ID_MM_RATCM_SERVICE_ACCEPT_NOTIFY_REQ,
#ifdef __GEMINI__
    MSG_ID_MM_RATCM_PS_SESSION_START_CNF,
    MSG_ID_MM_RATCM_PS_SESSION_STOP_CNF,
    MSG_ID_MM_RATCM_SUSPEND_IND,
    MSG_ID_MM_RATCM_RESUME_IND,
    MSG_ID_MM_RATCM_VIRTUAL_MODE_IND,
    MSG_ID_MM_RATCM_CS_STATUS_UPDATE_REQ,
#endif
    MSG_ID_MM_RATCM_LCS_PROC_START_IND,
    MSG_ID_MM_RATCM_LCS_PROC_END_IND,
    MSG_ID_MM_RATCM_LLC_PSHO_IND,
    MSG_ID_MM_RATCM_PS_HO_SUCCESS_IND,
    MSG_ID_MM_RATCM_SIGNAL_APPEAR_IND,
    MSG_ID_MM_RATCM_LOCAL_RELEASE_IND, /* solve local release status asynchronization between UE and NW */
    //Add for LTE multimode
    MSG_ID_MM_RATCM_DEACTIVATE_CNF,
    MSG_ID_MM_RATCM_EUTRAN_CAP_UPDATE_CNF,
    MSG_ID_MM_RATCM_RAT_CHANGE_CNF,
    MSG_ID_MM_RATCM_RAT_CHANGE_IND,
    //End of LTE multimode
    MSG_ID_MM_RATCM_RRC_STATE_IND,
    MSG_ID_MM_RATCM_IDLE_OUT_OF_SERVICE_IND,
    MSG_ID_MM_RATCM_START_TEST_MODE_IND,
    MSG_ID_MM_RATCM_STOP_TEST_MODE_IND,
    MSG_ID_MM_CODE_END = MSG_ID_MM_RATCM_STOP_TEST_MODE_IND,
MODULE_MSG_END( MSG_ID_MM_CODE_TAIL )

/*----------------------- MM_MSG_CODE_END--------------------*/

#endif  //_MM_MSG_H
