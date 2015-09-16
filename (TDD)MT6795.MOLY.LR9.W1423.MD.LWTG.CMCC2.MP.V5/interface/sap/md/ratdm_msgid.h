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
 *   ratdm_sap.h
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *****************************************************************************
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/
#include "module_msg_range.h"

#ifndef _RATDM_MSG_H
#define _RATDM_MSG_H

MODULE_MSG_BEGIN(MSG_ID_RATDM_CODE_BEGIN)

/* TCM -> RATDM */
MSG_ID_TCM_RATDM_DATA_REQ = MSG_ID_RATDM_CODE_BEGIN,
MSG_ID_TCM_RATDM_CONFIG_REQ,
MSG_ID_TCM_RATDM_DECONFIG_REQ,
MSG_ID_TCM_RATDM_ENTER_DATA_MODE_REQ,
MSG_ID_TCM_RATDM_QUERY_PS_STATISTICS_REQ,
MSG_ID_TCM_RATDM_RESET_PS_STATISTICS_REQ,

/* CMUX -> RATDM */
MSG_ID_CMUX_RATDM_DATA_ACTIVATE_RSP,
MSG_ID_CMUX_RATDM_DATA_DEACTIVATE_RSP,

/* PS - RATDM */
MSG_ID_PS_DATA_REQ,
MSG_ID_PS_DATA_IND,
#ifdef __3G_NEW_DATA_PLANE_ARCH__
MSG_ID_PS_DSCR_DATA_IND,
#endif

/* RATDM SHAQ UT Usage */
MSG_ID_RATDM_SHAQ_PRINT_CS_Q_ELEMENT,
MSG_ID_RATDM_SHAQ_PRINT_PS_Q_ELEMENT,

/* RATDM TST Log UL data usage*/
MSG_ID_RATDM_LOG_SHAQ_UL_ELEMENT,

/* SM -> RATDM */
MSG_ID_SM_RATDM_RAB_ACTIVATE_REQ,
MSG_ID_SM_RATDM_RAB_ACTIVATE_RSP,
MSG_ID_SM_RATDM_ACTIVATE_REQ,
MSG_ID_SM_RATDM_DEACTIVATE_REQ,
MSG_ID_SM_RATDM_MODIFY_REQ,
MSG_ID_SM_RATDM_ALLOW_DL_PACKET_IND, // LTE multimode
//MSG_ID_SM_RATDM_UPDATE_MAX_TRAFFIC_CLASS_REQ, // LTE multimode 4G23 IR_TYPE_SEARCH interRAT


/* MM -> RATDM */
MSG_ID_MM_RATDM_REESTABLISH_RAB_RSP,
MSG_ID_MM_RATDM_SEQUENCE_REQ,
MSG_ID_MM_RATDM_SEND_USER_DATA_RSP,
#ifdef __REL6__
MSG_ID_MM_RATDM_REESTABLISH_RAB_READY_IND,
#endif
MSG_ID_MM_RATDM_SERVICE_PROC_IND,

/* RATCM -> RATDM */
MSG_ID_RATCM_RATDM_RAT_CHANGE_REQ,
MSG_ID_RATCM_RATDM_REGAIN_COVERAGE_REQ,

/* RABM -> RATDM */
MSG_ID_RATDM_RABM_ACTIVATE_CNF,
MSG_ID_RATDM_RABM_ACTIVATE_IND,
MSG_ID_RATDM_RABM_DEACTIVATE_CNF,
MSG_ID_RATDM_RABM_DEACTIVATE_IND,
MSG_ID_RATDM_RABM_MODIFY_CNF,
MSG_ID_RATDM_RABM_REESTABLISH_IND,
MSG_ID_RATDM_RABM_DATA_CNF,
MSG_ID_RATDM_RABM_DATA_IND,
MSG_ID_RATDM_RABM_SUSPEND_DATA_PLANE_IND,
MSG_ID_RATDM_RABM_RESUME_DATA_PLANE_IND,
MSG_ID_RATDM_RABM_PDCP_RELOC_IND,
MSG_ID_RATDM_RABM_RETRANSMIT_IND,
MSG_ID_RATDM_RABM_RB_CONFIG_IND,
#ifdef __REL6__
MSG_ID_RATDM_RABM_RAB_RELEASE_IND,
#endif
MSG_ID_RATDM_RABM_RAB_CAPABILITY_IND,
//MSG_ID_RATDM_RABM_CONFIG_CNF,
//MSG_ID_RATDM_RABM_QUERY_STATISTICS_RSP,
//MSG_ID_RATDM_RABM_RESET_STATISTICS_RSP,
//MSG_ID_RATDM_RABM_STATISTICS_IND,
//MSG_ID_RATDM_RABM_SET_STATISTICS_CNF,
MSG_ID_RATDM_PDCP_RESET_STATISTICS_RSP,

/* URLC -> RATDM */
MSG_ID_RATDM_URLC_DEACTIVATE_PS_RAB_CNF,

/* SNDCP - RATDM */
MSG_ID_RATDM_SNDCP_DATA_IND,
MSG_ID_RATDM_SNDCP_DATA_CNF,
MSG_ID_RATDM_SNDCP_ACTIVATE_CNF,
MSG_ID_RATDM_SNDCP_MODIFY_CNF,
MSG_ID_RATDM_SNDCP_DEACTIVATE_CNF,
MSG_ID_RATDM_SNDCP_STATUS_IND,
MSG_ID_RATDM_SNDCP_SUSPEND_DATA_PLANE_IND,
MSG_ID_RATDM_SNDCP_RESUME_DATA_PLANE_IND,
MSG_ID_RATDM_SNDCP_FLUSH_IND,  
MSG_ID_RATDM_SNDCP_TRANSMIT_IND,
MSG_ID_RATDM_SNDCP_SEQUENCE_CNF,
MSG_ID_RATDM_SNDCP_RESET_NPDU_SEQ_IND,  

/* LTE */
//#ifdef __LTE_RAT__
MSG_ID_RATDM_UT_MULTIMODE_UG_DATA_IND_CB,
MSG_ID_RATDM_UT_MULTIMODE_HOOK_UL_DEST_CB,
MSG_ID_RATDM_UT_MULTIMODE_UG_READY_IND_CB,
MSG_ID_RATDM_UT_MULTIMODE_FORWARD_FROM_UG_DATA_CB,
//#endif // ~ #ifdef __LTE_RAT__

/* Jeff Wu 2006-04-22: RATDM -> RATDM */
MSG_ID_RATDM_PROCESS_TX_QUEUE_IND,
MSG_ID_RATDM_CODE_END = MSG_ID_RATDM_PROCESS_TX_QUEUE_IND,
//MSG_ID_RATDM_CODE_END,
MODULE_MSG_END(MSG_ID_RATDM_CODE_TAIL)

#endif //_RATDM_MSG_H
