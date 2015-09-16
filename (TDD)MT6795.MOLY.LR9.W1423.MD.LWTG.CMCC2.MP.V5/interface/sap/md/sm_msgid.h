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
 *   sm.sap
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   SM related message identity definition
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

#ifndef _SM_MSG_H
#define _SM_MSG_H

	/*------------------- SM_MSG_CODE_BEGIN---------------------*/

MODULE_MSG_BEGIN( MSG_ID_SM_CODE_BEGIN )
	MSG_ID_SMREG_PDP_ACTIVATE_REQ = MSG_ID_SM_CODE_BEGIN,
	MSG_ID_SMREG_PDP_DEACTIVATE_REQ,
	MSG_ID_SMREG_PDP_MODIFY_REQ,
	MSG_ID_SMREG_PDP_ACTIVATE_SEC_REQ,
	MSG_ID_SM_RATDM_ACTIVATE_CNF,
	MSG_ID_SM_RATDM_MODIFY_CNF,
	MSG_ID_SM_RATDM_DEACTIVATE_CNF,
	MSG_ID_SM_RATDM_STATUS_IND,
	MSG_ID_SM_NSAPI_MSG_CODE_END = MSG_ID_SM_RATDM_STATUS_IND,

	/* Carlson Lin 2012-04-17 LTE MultiMode */
	MSG_ID_GMMSM_RAT_CHANGE_IND, // (23G4 start)
	MSG_ID_L4CSM_RAT_CHANGE_RSP, // (23G4 finish)
	MSG_ID_GMMSM_RAT_CHANGE_CNF, // (4G23 finish) note: need two stage CNF if IRCCO
	MSG_ID_L4CSM_RAT_CHANGE_REQ, // (4G23 start)
	MSG_ID_SM_ESM_EPSB_CONTEXT_TRANSFER_IND, // 4G23 success context transfer: ESM --> SM
	MSG_ID_SM_ESM_EPSB_CONTEXT_TRANSFER_IND_FOR_SM_UT, // to verify function: sm_irat_local_activate_lte_transferred_context()
	//MSG_ID_SM_ESM_EPSB_CONTEXT_TRANSFER_RSP, // 4G23 success context transfer: SM --> ESM
	MSG_ID_SM_ESM_STANDBY_ON_OLD_RAT_IND, // 4G23 success context transfer : ESM --> SM
	//MSG_ID_SM_ESM_PDP_CONTEXT_TRANSFER_REQ, // 23G4 success context transfer: SM --> ESM
	MSG_ID_SM_ESM_PDP_CONTEXT_TRANSFER_CNF, // 23G4 success context transfer : ESM --> SM
	//MSG_ID_SM_ESM_STANDBY_ON_OLD_RAT_REQ, // 23G4 success context transfer: SM --> ESM
	MSG_ID_SM_TRACE_SMREG_PDP_ACTIVATE_REQ, // print structure to trace
	MSG_ID_SM_TRACE_SMREG_PDP_ACTIVATE_SEC_REQ, // print structure to trace
	MSG_ID_SMREG_ALLOW_DL_PACKET_IND,
	
        /*Huifeng: PS Swtich msg*/
        MSG_ID_GMMSM_PS_SWITCH_CONTEXT_TRANSFER_IND,
        MSG_ID_L4C_SM_PS_SWITCH_CONTEXT_TRANSFER_RSP,
        MSG_ID_GMMSM_PS_SWITCH_CONTEXT_TRANSFER_CNF,
        MSG_ID_L4C_SM_PS_SWITCH_CONTEXT_TRANSFER_REQ,
        MSG_ID_SM_PS_SWITCH_PDP_CONTEXT_TRANSFER_REQ,
        MSG_ID_SM_PS_SWITCH_PDP_CONTEXT_TRANSFER_CNF,
        MSG_ID_SM_PS_SWITCH_STANDBY_ON_OLD_RAT_REQ,

      /* Jeff Wu 2007-03-03: RATDM -> SM */
      MSG_ID_SM_RATDM_RAB_ACTIVATE_CNF,
      MSG_ID_SM_RATDM_RAB_ACTIVATE_IND,
      MSG_ID_SM_RATDM_RAB_DEACTIVATE_IND,
	/* 3G, MM -> SM */	
	MSG_ID_GMMSM_ATTACH_CNF,
	MSG_ID_GMMSM_ATTACH_REJ,
	MSG_ID_GMMSM_DETACH_IND,
	MSG_ID_GMMSM_EST_CNF,
	MSG_ID_GMMSM_EST_REJ,
	MSG_ID_GMMSM_ERR_IND,
	MSG_ID_GMMSM_UNITDATA_CNF,

	MSG_ID_GMMSM_UNITDATA_IND,
	MSG_ID_GMMSM_SUSPEND_REQ,
	MSG_ID_GMMSM_RESUME_REQ,
	MSG_ID_GMMSM_NSAPI_STATUS_IND, //__REL4__
	MSG_ID_GMMSM_RAT_IND, // When 4G23 irat_type==IR_TYPE_SEARCH, SM need to queue ESM transferred context until receiving GMMSM_RAT_IND. SM only need to process this message when __LTE_RAT__ is on because this message is only used when 4G23 IR_TYPE_SEARCH interRAT
	MSG_ID_SMREG_PDP_ACTIVATE_REJ_RSP,
	MSG_ID_SMREG_PDP_ACTIVATE_SEC_REJ_RSP,
	MSG_ID_SM_TEST_SM_CALCULATE_HOW_MANY_PDP_ARE_USED, // UT used
	MSG_ID_GMMSM_CELL_INFO_UPDATE_IND, /* erica 20051229: for egprs */
	MSG_ID_SM_CODE_END = MSG_ID_GMMSM_CELL_INFO_UPDATE_IND,
MODULE_MSG_END( MSG_ID_SM_CODE_TAIL )
	/*------------------- SM_MSG_CODE_END-----------------------*/

#endif  //_SM_MSG_H
