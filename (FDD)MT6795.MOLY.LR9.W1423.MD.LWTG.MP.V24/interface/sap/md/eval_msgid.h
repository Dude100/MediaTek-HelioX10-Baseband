/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   eval_msgid.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   LTE NAS EVAL (EVNAS Adaptation Layer) related message identity definition
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * MMIVT2MP6
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .EVAL interface part.
 *
 * removed!
 * removed!
 * .check in actvie sim info req interface
 *
 * removed!
 * removed!
 * Check in VoLTE+Gemini related interfaces for VDM, IMSP, L4C, EVAL, and ERRC
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Check in LPP CP interfaces & capability for EMM (OA domain)
 *
 * removed!
 * removed!
 * Add PLMN SEARCH Abort Interface:
 * 1.MSG_ID_EVAL_ERRC_PLMN_SEARCH_ABORT_REQ
 * 2.MSG_ID_NWSEL_EVAL_PLMN_SEARCH_ABORT_REQ
 *
 * removed!
 * removed!
 * [ESM/TFTLIB] Modification fot "TFT validate" and "PS init deactivation"
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * MOLY
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * 	Add message ids & SAP ids
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * integrate EAS_TO_PEER_INFO_IND.
 *
 * 10 18 2013 hc.chu
 * removed!
 * merge prebuild cbr back to trunk.
 *
 * removed!
 * removed!
 * .
 *
 * 08 30 2013 hc.chu
 * removed!
 * [MMDS_DC] Add EVAL_ESM_PS_SWITCH_COMPLETE_IND related handing.
 *
 * removed!
 * removed!
 * .
 *
 * 08 23 2013 hc.chu
 * removed!
 * remove unused mmdc rac codes
 *
 * removed!
 * removed!
 * <saved by Perforce>
 *
 * removed!
 * removed!
 * add __MMDC__ for message/structure.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * MM IT merge back to MOLY.
 *
 * removed!
 * removed!
 * common file: EVAL part.
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * MOLY_CBr to MOLY.
 *
 * removed!
 * removed!
 * [EVAL] Add EVAL related interfaces and common strust
 ****************************************************************************/
#include "module_msg_range.h"

#ifndef _EVAL_MSGID_H
#define _EVAL_MSGID_H

MODULE_MSG_BEGIN( MSG_ID_EVAL_CODE_BEGIN )

/****************************************************************************
 *                          Destination: EVAL (L4C to EVAL) 
 ****************************************************************************/
MSG_ID_L4C_EVAL_RAT_CHANGE_REQ              = MSG_ID_EVAL_CODE_BEGIN,
MSG_ID_L4C_EVAL_RAT_CHANGE_RSP,
MSG_ID_L4C_EVAL_ETWS_SETTING_REQ,
MSG_ID_L4C_EVAL_GET_SSAC_PARAM_REQ,

/* defined in l4_msgid.h for maintenance
 * MSG_ID_L4C_EVAL_ADJUST_MEAS_REQ,
 */

MSG_ID_L4C_EVAL_NBR_CELL_INFO_START_REQ,
MSG_ID_L4C_EVAL_NBR_CELL_INFO_STOP_REQ,

#ifdef __SGLTE__
MSG_ID_L4C_EVAL_PS_SWITCH_CONTEXT_TRANSFER_REQ,
MSG_ID_L4C_EVAL_PS_SWITCH_CONTEXT_TRANSFER_RSP,
#endif /* __SGLTE__ */

MSG_ID_L4C_EVAL_VDM_VOICE_STATUS_REQ,


/****************************************************************************
 *                          Destination: EVAL (ERAC to EVAL) 
 ****************************************************************************/
MSG_ID_EMMREG_INIT_REQ,
MSG_ID_EMMREG_SET_RAT_MODE_REQ,
MSG_ID_EMMREG_ATTACH_REQ,
MSG_ID_EMMREG_DETACH_REQ,
MSG_ID_EMMREG_RFOFF_REQ,
MSG_ID_EMMREG_SET_PREFERRED_BAND_REQ,
MSG_ID_EMMREG_EMC_ATTACH_REQ, // for IMS
MSG_ID_EMMREG_EPS_ATTACH_NEEDED_REJ_RSP,
MSG_ID_EMMREG_SET_IMS_VOICE_AVAILABILITY_REQ, // for IMS
MSG_ID_EMMREG_SET_IMS_VOICE_TERMINATION_REQ, // for IMS

#ifdef __SGLTE__
MSG_ID_EMMREG_PS_SWITCH_REQ,
MSG_ID_EMMREG_PS_SWITCH_SUSPEND_REQ, 
MSG_ID_EMMREG_PS_SWITCH_RESUME_REQ, 
#endif /* __SGLTE__ */

MSG_ID_EMMREG_ACTIVE_SIM_INFO_REQ,

/****************************************************************************
 *                          Destination: EVAL (NWSEL to EVAL) 
 ****************************************************************************/
MSG_ID_NWSEL_EVAL_PLMN_SEARCH_REQ,
MSG_ID_NWSEL_EVAL_SEARCH_STATUS_UPDATE_REQ,
MSG_ID_NWSEL_EVAL_SYS_INFO_UPDATE_REQ,
MSG_ID_NWSEL_EVAL_REGN_STATUS_UPDATE_REQ,
MSG_ID_NWSEL_EVAL_PLMN_LIST_REQ,
MSG_ID_NWSEL_EVAL_PLMN_LIST_STOP_REQ,
MSG_ID_NWSEL_EVAL_CSG_LIST_REQ,
MSG_ID_NWSEL_EVAL_CSG_LIST_STOP_REQ,
MSG_ID_NWSEL_EVAL_EQ_PLMN_LIST_UPDATE_REQ,
MSG_ID_NWSEL_EVAL_HPLMN_INFO_UPDATE_REQ,
MSG_ID_NWSEL_EVAL_DEACTIVATE_REQ,
MSG_ID_NWSEL_EVAL_NAS_CTXT_TRANSFER_REQ,
MSG_ID_NWSEL_EVAL_UEMODE_PARAM_UPDATE_REQ,
MSG_ID_NWSEL_EVAL_PLMN_SEARCH_PREFERENCE_UPDATE_REQ, // for IMS
MSG_ID_NWSEL_EVAL_EMC_FPLMN_LIST_UPDATE_REQ, // for IMS
MSG_ID_NWSEL_EVAL_RESUME_REQ,
#ifdef __OP01__
MSG_ID_NWSEL_EVAL_PLMN_SEARCH_ABORT_REQ,
#endif /*__OP01__*/
#if (defined(__OP01__) && defined(__GEMINI__)) 
MSG_ID_NWSEL_EVAL_POWER_ON_PROTECTION_REQ,
#endif

/****************************************************************************
 *                          Destination: EVAL (ETCM to EVAL) 
 ****************************************************************************/
MSG_ID_ESMREG_PDN_CONN_EST_REQ,
MSG_ID_ESMREG_BEARER_RSC_ALLOC_REQ,
MSG_ID_ESMREG_BEARER_RSC_MOD_REQ,
MSG_ID_ESMREG_EPSB_DEACT_REQ,
MSG_ID_ESMREG_PDN_CONN_EST_RSP,
MSG_ID_ESMREG_PDN_CONN_UPDATE_RSP,


/****************************************************************************
 *                          Destination: EVAL (SMS to EVAL) 
 ****************************************************************************/
MSG_ID_SMS_EVAL_EST_REQ,
MSG_ID_SMS_EVAL_UNITDATA_REQ,


/****************************************************************************
 *                          Destination: EVAL (SMSAL to EVAL) 
 ****************************************************************************/
MSG_ID_SMSAL_EVAL_CBCH_REQ,
MSG_ID_SMSAL_EVAL_CB_UPDATE_REQ,
MSG_ID_SMSAL_EVAL_CB_MSG_REMOVAL_REQ,

/****************************************************************************
 *                          Destination: EVAL (ETC to EVAL)
 ****************************************************************************/
MSG_ID_EVAL_ETC_NW_RESET_UE_STORED_POS_INFO_IND, // for LPP

/****************************************************************************
 *                          Destination: EVAL (EMM to EVAL) 
 ****************************************************************************/
MSG_ID_EVAL_EMM_SET_RAT_MODE_CNF,
MSG_ID_EVAL_EMM_ATTACH_CNF,
MSG_ID_EVAL_EMM_DETACH_IND,
MSG_ID_EVAL_EMM_RFOFF_CNF,
MSG_ID_EVAL_EMM_CELL_INFO_UPDATE_IND,
MSG_ID_EVAL_EMM_NW_INFO_IND,
MSG_ID_EVAL_EMM_NW_ECC_IND,
MSG_ID_EVAL_EMM_PLMN_SEARCH_CNF,
MSG_ID_EVAL_EMM_SYS_INFO_IND,
MSG_ID_EVAL_EMM_REGN_RESULT_IND,
MSG_ID_EVAL_EMM_NO_ACTION_IND,
MSG_ID_EVAL_EMM_PLMN_LIST_CNF,
MSG_ID_EVAL_EMM_PLMN_LIST_STOP_CNF,
MSG_ID_EVAL_EMM_CSG_LIST_CNF,
MSG_ID_EVAL_EMM_CSG_LIST_STOP_CNF,
MSG_ID_EVAL_EMM_OUT_OF_SERVICE_IND,
MSG_ID_EVAL_EMM_OUT_OF_SERVICE_FINISH_IND,
MSG_ID_EVAL_EMM_PLMN_LOSS_IND,
MSG_ID_EVAL_EMM_DEACTIVATE_CNF,
MSG_ID_EVAL_EMM_NAS_CTXT_TRANSFER_CNF,
MSG_ID_EVAL_EMM_SMS_EST_CNF,
MSG_ID_EVAL_EMM_SMS_EST_REJ,
MSG_ID_EVAL_EMM_SMS_UNITDATA_IND,
MSG_ID_EVAL_EMM_SMS_ERR_IND,
MSG_ID_EVAL_EMM_LPP_DATA_CNF, // for LPP
MSG_ID_EVAL_EMM_LPP_DATA_IND, // for LPP
MSG_ID_EVAL_EMM_LCS_DATA_CNF, // for LPP
MSG_ID_EVAL_EMM_LCS_DATA_IND, // for LPP
MSG_ID_EVAL_EMM_SIM_EPSNSC_INFO_IND,
MSG_ID_EVAL_EMM_SIM_EPSLOCI_INFO_IND,
MSG_ID_EVAL_EMM_AUTHENTICATE_IND,
MSG_ID_EVAL_EMM_PLMN_SEARCH_IND,
MSG_ID_EVAL_EMM_SIGNAL_APPEAR_IND,
MSG_ID_EVAL_EMM_EMERGENCY_STATUS_UPDATE_IND, // for IMS
MSG_ID_EVAL_EMM_EMC_ATTACH_CNF, // for IMS
MSG_ID_EVAL_EMM_EMC_DETACH_IND, // for IMS
MSG_ID_EVAL_EMM_NW_FEATURE_SUPPORT_IND, // for IMS
MSG_ID_EVAL_EMM_SRVCC_STATUS_UPDATE_IND, // for IMS
MSG_ID_EVAL_EMM_NW_REJECT_IND,
#ifdef __SGLTE__
MSG_ID_EVAL_EMM_PS_SWITCH_CNF,
MSG_ID_EVAL_EMM_PS_SWITCH_SUSPEND_CNF, 
MSG_ID_EVAL_EMM_PS_SWITCH_IND, 
#endif/* __SGLTE__ */


/****************************************************************************
 *                          Destination: EVAL (ESM to EVAL) 
 ****************************************************************************/
MSG_ID_EVAL_ESM_PDN_CONN_EST_REJ,
MSG_ID_EVAL_ESM_BEARER_RSC_ALLOC_REJ,
MSG_ID_EVAL_ESM_BEARER_RSC_MOD_REJ,
MSG_ID_EVAL_ESM_EPSB_DEACT_REJ,
MSG_ID_EVAL_ESM_PDN_CONN_EST_IND,
MSG_ID_EVAL_ESM_PDN_CONN_UPDATE_IND,
MSG_ID_EVAL_ESM_EPSB_DEACT_IND,
MSG_ID_EVAL_ESM_EPS_ATTACH_NEEDED_IND,
MSG_ID_EVAL_ESM_RAT_CHANGE_IND,
MSG_ID_EVAL_ESM_RAT_CHANGE_CNF,
MSG_ID_EVAL_ESM_RAT_CHANGE_COMPLETE_IND,
MSG_ID_EVAL_ESM_EMC_ATTACH_IND, // for IMS
MSG_ID_EVAL_ESM_SRVCC_STATUS_UPDATE_IND, // for IMS
#ifdef __SGLTE__ 
MSG_ID_EVAL_ESM_PS_SWITCH_CONTEXT_TRANSFER_CNF,
MSG_ID_EVAL_ESM_PS_SWITCH_CONTEXT_TRANSFER_IND,
MSG_ID_EVAL_ESM_PS_SWITCH_COMPLETE_IND,
#endif /* __SGLTE__  */
MSG_ID_EVAL_ESM_PS_INIT_BEARER_DEACT_IND,
/****************************************************************************
 *                          Destination: EVAL (ERRC to EVAL) 
 ****************************************************************************/
MSG_ID_EVAL_ERRC_CB_RECONFIG_IND,
MSG_ID_EVAL_ERRC_CB_GS_CHANGE_IND,
MSG_ID_EVAL_ERRC_CELL_POWER_LEVEL_IND,
MSG_ID_EVAL_ERRC_ADJUST_MEAS_CNF,
MSG_ID_EVAL_ERRC_PWS_INFORMATION_IND,
MSG_ID_EVAL_ERRC_NBR_CELL_INFO_START_CNF,
MSG_ID_EVAL_ERRC_NBR_CELL_INFO_IND,
MSG_ID_EVAL_ERRC_NBR_CELL_INFO_STOP_CNF,
MSG_ID_EVAL_ERRC_GET_SSAC_PARAM_CNF, // for IMS


#ifdef __SGLTE__
MSG_ID_EVAL_ERRC_TO_PEER_INFO_IND,
MSG_ID_EVAL_ERRC_CAPABILITY_CHANGE_IND,
#endif /* __SGLTE__ */

/****************************************************************************
 *                          Destination: EVAL (CISS to EVAL) 
 ****************************************************************************/
MSG_ID_CISS_EVAL_DATA_REQ,

/****************************************************************************/
MSG_ID_EVAL_CODE_END,

MODULE_MSG_END( MSG_ID_EVAL_CODE_TAIL )

#endif /* _EVAL_MSGID_H */
