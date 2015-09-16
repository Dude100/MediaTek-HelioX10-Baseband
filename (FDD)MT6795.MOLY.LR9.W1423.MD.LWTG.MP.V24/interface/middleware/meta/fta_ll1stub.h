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
 *   fta_ll1stub.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
* Include Statements for KAL
 *************************************************************************/
#ifndef FTA_LL1STUB_H
#define FTA_LL1STUB_H

#if defined(TL1_TESTCASE) || ((defined(IC_MODULE_TEST)||defined(__IC_SLT__)) && defined(__TDDSYS_SLT_FACTORY_BOOT__))
#include "tl1_msgid.h"
enum
{

#if defined( __GEMINI_MONITOR_PAGE_DURING_TRANSFER__)
	MSG_ID_LL1_START_GSM_GAP_SERVICE =MSG_ID_PHY_CHANNEL_PRIORITY_ADJUSTMENT_REQ+1,
#elif defined( __GEMINI_GSM__ ) && defined ( __UMTS_RAT__ )  
    MSG_ID_LL1_START_GSM_GAP_SERVICE =MSG_ID_RSVAS_UL1_SUSPEND_CNF+1,
#else
    MSG_ID_LL1_START_GSM_GAP_SERVICE =MSG_ID_CPHY_CHANNEL_QUALITY_STATUS_IND+1,
#endif

//	MSG_ID_LL1_START_GSM_GAP_SERVICE = MSG_ID_CPHY_MSG_CONTAINER_REQ_UNPACK+1,
	MSG_ID_LL1_STOP_GSM_GAP_SERVICE,
	MSG_ID_LL1_L1A_SET_GAP_FUNC_IDLE,
	MSG_ID_LL1_L1A_SET_GAP_FUNC_FACH,
	MSG_ID_LL1_L1A_SET_GAP_FUNC_DCH, 
	MSG_ID_LL1_L1A_SET_GAP_FUNC_DPA,
	MSG_ID_LL1_L1A_STOP_GAP_CONFIRM, 
	MSG_ID_LL1_INFORM_UMTS_MODE, 
	MSG_ID_LL1_SEND_UMTS_GAP_AVAILABLE_IND,
	MSG_ID_LL1_SEND_UMTS_GAP_UNAVAILABLE_IND, 
	MSG_ID_LL1_L1A_SET_FACH_GAP_LOCK, 
	MSG_ID_LL1_UMTS_CELL_MEAS_DONE_IND, 
	MSG_ID_LL1_START_SET_GAP_FUNC_DCH, 
	MSG_ID_LL1_START_SET_GAP_FUNC_FACH, 
	MSG_ID_TL1_START_UMTS_GAP_SERVICE_CNF, 
	MSG_ID_TL1_STOP_UMTS_GAP_SERVICE_CNF, 
	MSG_ID_LL1STUB_START_SYNC_CNF,
	MSG_ID_LL1STUB_STOP_SYNC_CNF, 
	MSG_ID_LL1STUB_SYNC_RPT_IND,
	MSG_ID_TL1_START_UMTS_GAP_SERVICE_REQ,
	MSG_ID_TL1_STOP_UMTS_GAP_SERVICE_REQ,
	MSG_ID_TL1_SET_GAP_FUNC,
	MSG_ID_TL1_DM_SET_GSM_MODE,
	MSG_ID_TL1_RECEIVE_GSM_GAP_AVAILABLE_IND,
	MSG_ID_TL1_RECEIVE_GSM_GAP_UNAVAILABLE_IND,
	MSG_ID_TL1_FACH_GAP_LOCK_CNF,
	MSG_ID_TL1_RECEIVE_GSM_PM_DONE_IND,
	MSG_ID_LL1STUB_START_SYNC_REQ,
	MSG_ID_LL1STUB_STOP_SYNC_REQ
};

extern void ll1stub_handle_sync_timeout();
#endif
#endif //FTA_LL1STUB_H
