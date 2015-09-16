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
 * l1_sap.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Layer 1 and Protocol Stack related message identity definition
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "module_msg_range.h"

#ifndef L1_MSGID_H
#define L1_MSGID_H

/* Note that GPRS REQ should before GSM CNF/IND, GSM should before 
   GPRS for MPAL's requirement!!! That is, all REQ first and GSM 
   before GPRS, and then all CNF/IND together with GSM before GPRS */ 

/* Request for GSM */

MODULE_MSG_BEGIN( L1_MSG_CODE_BEGIN )
MSG_ID_MPHC_POWER_SCAN_REQ = L1_MSG_CODE_BEGIN,
MSG_ID_MPHC_MANUSEL_PWRSCAN_REQ,
MSG_ID_MPHC_MANUSEL_PWRSCAN_STOP_REQ,
MSG_ID_MPHC_BSIC_SYNC_REQ,
MSG_ID_MPHC_SPECIFIC_SYNC_REQ,
MSG_ID_MPHC_SERV_BCCH_MONITOR_REQ,
MSG_ID_MPHC_IDLE_CCCH_START_REQ,
MSG_ID_MPHC_CCCH_UPDATE_REQ,
MSG_ID_MPHC_PAGE_MODE_CHANGE_REQ,
MSG_ID_MPHC_SMART_PAGE_START_REQ,
MSG_ID_MPHC_RANDOM_ACCESS_REQ,
MSG_ID_MPHC_RACH_ABORT_REQ,
MSG_ID_MPHC_IMMED_ASSIGN_REQ,
MSG_ID_MPHC_CHANNEL_ASSIGN_REQ,
MSG_ID_MPHC_CHANNEL_RELEASE_REQ,
MSG_ID_MPHC_HANDOVER_REQ,
MSG_ID_MPHC_HANDOVER_ACCESS_STOP_REQ,
MSG_ID_MPHC_CHANNEL_RECONNECT_REQ,
MSG_ID_MPHC_FREQUENCY_REDEFINITION_REQ,
MSG_ID_MPHC_CHANNEL_MODE_MODIFY_REQ,
MSG_ID_MPHC_CIPHERING_MODE_COMMAND_REQ,
MSG_ID_MPHC_CLOSE_TCH_LOOP_REQ,
MSG_ID_MPHC_OPEN_TCH_LOOP_REQ,
MSG_ID_MPHC_DAI_TEST_REQ,
MSG_ID_MPHC_POWER_CLASS_REQ,
MSG_ID_MPHC_CELL_OPTION_UPDATE_REQ,
MSG_ID_MPHC_EXTENDED_MEAS_REQ,
MSG_ID_MPHC_NEIGHBOR_MEAS_REQ,
MSG_ID_MPHC_NEIGHBOR_BSIC_START_REQ,
MSG_ID_MPHC_NEIGHBOR_BSIC_STOP_REQ,
MSG_ID_MPHC_NEIGHBOR_SYS_INFO_READ_REQ,
MSG_ID_MPHC_NEIGHBOR_SYS_INFO_STOP_REQ,
MSG_ID_MPHC_CELL_BSIC_START_REQ,
MSG_ID_MPHC_CELL_BSIC_STOP_REQ,
MSG_ID_MPHC_CELL_SYS_INFO_READ_REQ,
MSG_ID_MPHC_CELL_SYS_INFO_STOP_REQ,
#ifdef __GEMINI_GSM__
MSG_ID_MPHC_CELL_SYS_INFO_PRI_ADJUST_REQ,
#endif /* end of __GEMINI_GSM__ */
MSG_ID_MPHC_CBCH_CONFIG_REQ,
MSG_ID_MPHC_CBCH_START_REQ,
MSG_ID_MPHC_CBCH_STOP_REQ,
MSG_ID_MPHC_CBCH_SKIP_REQ,
MSG_ID_MPHC_BLIND_HANDOVER_BSIC_REQ,
MSG_ID_MPHC_DEACTIVATE_REQ,
MSG_ID_MPHC_SIM_READY_NOTIFY_REQ,
MSG_ID_MPHC_CELL_SELECTION_INIT_REQ,


#ifdef __PS_SERVICE__
/* Request for GPRS */
MSG_ID_MPHP_DOWNLINK_SINGLE_BLOCK_REQ,
MSG_ID_MPHP_INTERFERENCE_MEAS_REQ,
MSG_ID_MPHP_PACKET_IDLE_CCCH_START_REQ,
#ifdef __RMP_PRESENT__
MSG_ID_MPHP_NEIGHBOR_PBCCH_START_REQ,
MSG_ID_MPHP_NEIGHBOR_PBCCH_STOP_REQ,
MSG_ID_MPHP_PACKET_CCCH_CONFIG_REQ,
MSG_ID_MPHP_PACKET_IDLE_PCCCH_START_REQ,
MSG_ID_MPHP_PACKET_PAGE_MODE_UPDATE_REQ,
MSG_ID_MPHP_PACKET_RANDOM_ACCESS_REQ,
MSG_ID_MPHP_PRACH_ABORT_REQ,
MSG_ID_MPHP_PBCCH_START_REQ,
MSG_ID_MPHP_PBCCH_STOP_REQ,
MSG_ID_MPHP_PCCCH_CONFIG_REQ,
#endif /* end of __RMP_PRESENT__*/
MSG_ID_MPHP_PACKET_DOWNLINK_ASSIGNMENT_REQ,
#ifdef __PKT_EXT_MEAS__
MSG_ID_MPHP_PACKET_EXTENDED_MEAS_REQ, 
#endif /*__PKT_EXT_MEAS__*/
MSG_ID_MPHP_PACKET_NC_MEAS_START_REQ,
MSG_ID_MPHP_PACKET_NC_MEAS_STOP_REQ,
MSG_ID_MPHP_PACKET_PDCH_RELEASE_REQ,
MSG_ID_MPHP_PACKET_UNASSIGNMENT_REQ,
MSG_ID_MPHP_PACKET_UPLINK_ASSIGNMENT_REQ,
MSG_ID_MPHP_PACKET_TIMESLOT_RECONFIGURE_REQ,
MSG_ID_MPHP_PDCH_FAIL_RECONNECT_REQ,
MSG_ID_MPHP_POLL_RESPONSE_REQ,
MSG_ID_MPHP_POWER_CONTROL_UPDATE_REQ,
MSG_ID_MPHP_REPEAT_ALLOCATION_REQ,
MSG_ID_MPHP_TIMING_ADVANCE_UPDATE_REQ,
MSG_ID_MPHP_UPLINK_SINGLE_BLOCK_REQ,
#ifdef __MONITOR_PAGE_DURING_TRANSFER__
MSG_ID_MPHP_MONITOR_PAGE_IN_PTM_START_REQ,
MSG_ID_MPHP_MONITOR_PAGE_IN_PTM_STOP_REQ,
#endif /* end of __MONITOR_PAGE_DURING_TRANSFER__ */
#ifdef __PS_HO__
MSG_ID_MPHP_PS_HANDOVER_REQ,
MSG_ID_MPHP_PS_HANDOVER_RECONNECT_REQ,
MSG_ID_MPHP_BLIND_PS_HANDOVER_BSIC_REQ,
#endif /* end of __PS_HO__ */
#endif  /* __PS_SERVICE__ */ 

MSG_ID_MPHC_ACTIVE_REQ,

#if defined(__UMTS_RAT__) || defined(__LTE_RAT__)
MSG_ID_MPHM_STANDBY_REQ,
MSG_ID_MPHM_STANDBY_GSM_MEAS_START_REQ,
MSG_ID_MPHM_STANDBY_GSM_MEAS_STOP_REQ,
#if defined(__23G_PRI_RESEL_SUPPORT__) || defined(__LTE_RAT__)
MSG_ID_MPHM_STANDBY_GSM_PRIO_MEAS_START_REQ,
MSG_ID_MPHM_STANDBY_GSM_PRIO_MEAS_STOP_REQ,
#endif /* defined(__23G_PRI_RESEL_SUPPORT__) || defined(__LTE_RAT__) */
MSG_ID_MPHM_STANDBY_GSM_BSIC_READ_REQ,
MSG_ID_MPHM_STANDBY_GSM_BSIC_STOP_REQ,
MSG_ID_MPHM_STANDBY_CELL_BSIC_RES_REQ,
MSG_ID_MPHM_INTER_RAT_HANDOVER_REQ,
#if 0
/* under construction !*/
#endif /* 0 */
#ifdef __LTE_RAT__
MSG_ID_MPHM_STANDBY_GSM_REPORT_CGI_PWRSCAN_REQ,
MSG_ID_MPHM_STANDBY_GSM_REPORT_CGI_PWRSCAN_STOP_REQ,
MSG_ID_MPHM_STANDBY_GSM_REPORT_CGI_BSIC_START_REQ,
MSG_ID_MPHM_STANDBY_GSM_REPORT_CGI_BSIC_STOP_REQ,
MSG_ID_MPHM_STANDBY_GSM_REPORT_CGI_SYS_INFO_START_REQ,
MSG_ID_MPHM_STANDBY_GSM_REPORT_CGI_SYS_INFO_STOP_REQ,
#endif /* __LTE_RAT__ */

#ifdef __CSG_SUPPORT_NW_CTRL__
MSG_ID_MPHM_AUTO_GAP_START_REQ,
MSG_ID_MPHM_AUTO_GAP_STOP_REQ,
#endif /* __CSG_SUPPORT_NW_CTRL__ */
#endif /* defined(__UMTS_RAT__) || defined(__LTE_RAT__) */

#ifdef __EGPRS_MODE__
MSG_ID_MPHP_EGPRS_LOOP_REQ,
MSG_ID_MPHP_UPDATE_IR_RESET_REQ,
#endif

#if defined(__GEMINI_GSM__) || defined(__SGLTE__)
MSG_ID_MPHC_SIM_STATUS_UPDATE_REQ,
#endif /*end of __GEMINI_GSM__ || __SGLTE__ */

#ifdef __GEMINI__
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
/* Shihyao, gemini 2.0 development */
MSG_ID_MPHC_POWER_SCAN_STOP_REQ,
MSG_ID_MPHC_VIRTUAL_SUSPEND_REQ,
MSG_ID_MPHC_RESUME_REQ, /* it is sent from MPAL to L1 */
MSG_ID_MPHC_CHANNEL_PROTECT_START_REQ,
MSG_ID_MPHC_CHANNEL_PROTECT_STOP_REQ,
#endif /*end of __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */
#endif /*end of __GEMINI__*/


/* Confirmation & Indication for GSM */

MSG_ID_MPHC_POWER_SCAN_CNF,
MSG_ID_L1_CNF_CODE_BEGIN = MSG_ID_MPHC_POWER_SCAN_CNF,
MSG_ID_MPHC_MANUSEL_PWRSCAN_CNF,
MSG_ID_MPHC_BSIC_SYNC_CNF,
MSG_ID_MPHC_UNITDATA_IND,
MSG_ID_MPHC_RANDOM_ACCESS_CNF,
MSG_ID_MPHC_IMMED_ASSIGN_CNF,
MSG_ID_MPHC_CHANNEL_ASSIGN_CNF,
MSG_ID_MPHC_CHANNEL_RELEASE_CNF,
MSG_ID_MPHC_HANDOVER_CNF,
MSG_ID_MPHC_HANDOVER_ACCESS_START_IND,
MSG_ID_MPHC_HANDOVER_CONNECTED_IND,
MSG_ID_MPHC_HANDOVER_ACCESS_STOP_CNF,
MSG_ID_MPHC_CHANNEL_RECONNECT_CNF,
MSG_ID_MPHC_FREQUENCY_REDEFINITION_CNF,
MSG_ID_MPHC_CHANNEL_MODE_MODIFY_CNF,
MSG_ID_MPHC_CIPHERING_MODE_COMMAND_CNF,
MSG_ID_MPHC_CLOSE_TCH_LOOP_CNF,
MSG_ID_MPHC_OPEN_TCH_LOOP_CNF,
MSG_ID_MPHC_EXTENDED_MEAS_IND,
MSG_ID_MPHC_BLOCK_QUALITY_IND,
MSG_ID_MPHC_SERV_IDLE_MEAS_IND,
MSG_ID_MPHC_SERV_DEDI_MEAS_IND,
MSG_ID_MPHC_NEIGHBOR_MEAS_IND,
MSG_ID_MPHC_NEIGHBOR_BSIC_IND,
MSG_ID_MPHC_CELL_BSIC_IND,
MSG_ID_MPHC_BLIND_HANDOVER_BSIC_IND,
MSG_ID_MPHC_CELL_SELECTION_INIT_CNF,
MSG_ID_MPHC_ACTIVE_CNF,
MSG_ID_MPHC_DEACTIVATE_CNF,


#ifdef __PS_SERVICE__
/* Confirmation & Indication for GPRS */
MSG_ID_MPHP_DOWNLINK_SINGLE_BLOCK_CNF,
MSG_ID_MPHP_INTERFERENCE_MEAS_IND,
MSG_ID_MPHP_PACKET_BLOCK_QUALITY_IND,
MSG_ID_MPHP_PACKET_DATA_IND,
MSG_ID_MPHP_PACKET_DOWNLINK_ASSIGNMENT_CNF,
#ifdef __PKT_EXT_MEAS__
MSG_ID_MPHP_PACKET_EXTENDED_MEAS_IND,
#endif /*__PKT_EXT_MEAS__*/
MSG_ID_MPHP_PACKET_NC_MEAS_IND,
#ifdef __RMP_PRESENT__
MSG_ID_MPHP_PACKET_RANDOM_ACCESS_CNF,
#endif /* end of __RMP_PRESENT__*/
MSG_ID_MPHP_PACKET_SERV_MEAS_IND,
MSG_ID_MPHP_PACKET_UNASSIGNMENT_CNF,
MSG_ID_MPHP_PACKET_UPLINK_ASSIGNMENT_CNF,
MSG_ID_MPHP_PACKET_TIMESLOT_RECONFIGURE_CNF,
#ifndef __MTK_TARGET__
MSG_ID_MPHP_PKT_U1_IND,
MSG_ID_MPHP_PKT_U2_IND,
MSG_ID_MPHP_PACKET_DOWNLINK_IND,
#endif
MSG_ID_MPHP_PDCH_FAIL_RECONNECT_CNF,
MSG_ID_MPHP_POLL_RESPONSE_CNF,
MSG_ID_MPHP_REPEAT_ALLOCATION_IND,
#ifdef __PS_HO__
MSG_ID_MPHP_PS_HANDOVER_CNF,
MSG_ID_MPHP_PS_HANDOVER_RECONNECT_CNF,
MSG_ID_MPHP_BLIND_PS_HANDOVER_BSIC_IND,
#endif /* end of __PS_HO__ */
MSG_ID_MPHP_UPLINK_SINGLE_BLOCK_CNF,
#endif  /* __PS_SERVICE__ */   
#ifdef __EGPRS_MODE__
MSG_ID_MPHP_EGPRS_LOOP_CNF,
#endif

#ifdef __GEMINI__
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
/* Shihyao, gemini 2.0 development. */
MSG_ID_MPHC_VIRTUAL_SUSPEND_CNF,
#endif /*end of __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */
#endif /*end of __GEMINI__*/

MSG_ID_L1_CNF_CODE_END, /* Must not include 3G msg since 3G msg use another function table */

#if defined(__UMTS_RAT__) || defined(__LTE_RAT__) 
MSG_ID_MPHM_STANDBY_CNF,
MSG_ID_MPHM_L1_CNF_CODE_BEGIN = MSG_ID_MPHM_STANDBY_CNF,
MSG_ID_MPHM_STANDBY_GSM_MEAS_IND,
#if defined(__23G_PRI_RESEL_SUPPORT__) || defined (__LTE_RAT__)
MSG_ID_MPHM_STANDBY_GSM_PRIO_MEAS_IND,
#endif /*defined(__23G_PRI_RESEL_SUPPORT__) || defined (__LTE_RAT__) */

MSG_ID_MPHM_STANDBY_GSM_BSIC_IND,
MSG_ID_MPHM_INTER_RAT_HANDOVER_CNF,

#ifdef __LTE_RAT__
MSG_ID_MPHM_STANDBY_GSM_REPORT_CGI_PWRSCAN_CNF,
MSG_ID_MPHM_STANDBY_GSM_REPORT_CGI_BSIC_IND,
#endif /* __LTE_RAT__ */

#ifdef __CSG_SUPPORT_NW_CTRL__
MSG_ID_MPHM_AUTO_GAP_START_CNF,
MSG_ID_MPHM_AUTO_GAP_STOP_CNF,
#endif /* __CSG_SUPPORT_NW_CTRL__ */

MSG_ID_MPHM_L1_CNF_CODE_END,

#ifdef __GEMINI_GSM__
MSG_ID_MPHC_ALT_L1_GSM_GAP_SERVICE_UPDATE_REQ,
MSG_ID_MPHC_ALT_L1_GSM_GAP_RESUME_REQ,
#endif /* __GEMINI_GSM__ */
#endif /* defined(__UMTS_RAT__) || defined(__LTE_RAT__) */

#ifdef L1A_SIM
MSG_ID_L1C_L1A_REPORT,
#ifndef __GEMINI_GSM__ /* To run WG_0, GW_0 scripts in Dual_Mode environment*/
MSG_ID_MPHC_SIM2_RSVAS_L1_SUSPEND_REQ,
MSG_ID_MPHC_SIM2_VIRTUAL_SUSPEND_REQ,
MSG_ID_MPHC_SIM2_DEACTIVATE_REQ,
MSG_ID_RSVAS_L1_SUSPEND_CNF,
MSG_ID_MPHC_VIRTUAL_SUSPEND_CNF,
#endif /* end of __GEMINI_GSM__*/   
#endif

/* To bypass SGLTE build error, these messages will be never sent in SGLTE without DSDS */
#if !defined(__GEMINI_GSM__) && defined(__SGLTE__)
MSG_ID_RSVAS_L1_SUSPEND_REQ,
MSG_ID_RSVAS_L1_SUSPEND_CNF,
MSG_ID_RSVAS_L1_RESUME_REQ,
MSG_ID_MPHC_ALT_L1_GSM_GAP_SERVICE_UPDATE_REQ,
MSG_ID_MPHC_ALT_L1_GSM_GAP_RESUME_REQ,
MSG_ID_MPHC_CELL_SYS_INFO_PRI_ADJUST_REQ,
MSG_ID_MPHC_POWER_SCAN_STOP_REQ,
MSG_ID_MPHC_VIRTUAL_SUSPEND_REQ,
MSG_ID_MPHC_RESUME_REQ,
MSG_ID_MPHC_CHANNEL_PROTECT_START_REQ,
MSG_ID_MPHC_CHANNEL_PROTECT_STOP_REQ,
MSG_ID_MPHC_VIRTUAL_SUSPEND_CNF,
#endif
MODULE_MSG_END( MSG_ID_L1_CODE_TAIL )

#endif //L1_MSGID_H
