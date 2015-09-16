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
 * ll1_sap.h
 *
 * Project:
 * --------
 *   WCDMA_Software
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/* Request for LL1 */
#include "module_msg_range.h"

#ifndef LL1_MSGID_H
#define LL1_MSGID_H

#ifdef _Test_Hdr_On_PC
enum {
#endif

MODULE_MSG_BEGIN( MSG_ID_LL1_MSG_CODE_BEGIN )
/* BEGIN:jake: 20051226, for LL1 implement, send/receive MSG to/form GSM L1 */
MSG_ID_MPHD_GSM_GAP_SERVICE_REQ = MSG_ID_LL1_MSG_CODE_BEGIN,
MSG_ID_MPHD_GSM_TICK_IND,
MSG_ID_MPHD_GSM_GAP_PATTERN_IND,
MSG_ID_MPHD_GSM_GAP_STOP_REQ,
MSG_ID_MPHD_GSM_GAP_STOP_CNF,
MSG_ID_MPHD_GSM_SC_MODE_IND, /*MTK L1 only, to inform 3G L1 currently 2G SC mode*/
MSG_ID_MPHD_UMTS_GAP_SERVICE_REQ,
MSG_ID_MPHD_UMTS_PARAM_NOTIFY_IND,
#if 0 /*Pop20090310 for low pwr improvement in 2G standby mode*/
/* under construction !*/
#endif
MSG_ID_MPHD_UMTS_GAP_STOP_REQ,
MSG_ID_MPHD_UMTS_GAP_STOP_CNF,
#ifdef __UMTS_TDD128_MODE__
MSG_ID_MPHD_UMTS_FACH_LOCK_REQ, 
MSG_ID_MPHD_UMTS_FACH_UNLOCK_REQ, 
MSG_ID_MPHD_UMTS_FACH_LOCK_CNF,
#endif /*__UMTS_TDD128_MODE__*/
#ifdef __UMTS_FDD_MODE__
MSG_ID_MPHD_UMTS_FMO_LOCK_REQ, /*MTK L1 only, to inform 2G L1 hold FMO for RACH*/
MSG_ID_MPHD_UMTS_FMO_UNLOCK_REQ, /*MTK L1 only, to inform 2G L1 resume FMO*/
MSG_ID_MPHD_UMTS_FMO_LOCK_CNF,
#endif /*__UMTS_FDD_MODE__*/
MSG_ID_MPHD_GSM_PM_DONE_IND,/*Popcafa 20090207 low pwr improvement in 2G standby mode*/
MSG_ID_MPHD_IRAT_SYNC_READY_IND,
MSG_ID_MPHD_IRAT_SYNC_COMPLETE_IND,
MSG_ID_MPHD_IRAT_SYNC_CNF,
MSG_ID_MPHD_IRAT_UMTS_TIMING_CHANGE_IND,
MSG_ID_MPHD_IRAT_SYNC_REQ,
MSG_ID_MPHD_IRAT_SYNC_IND,  /* SYY, 3G wake up to notify 2G do timing sync. when 2G in connection mode */
MSG_ID_MPHD_GSM_GAP_UNAVAILABLE_IND,
MSG_ID_MPHD_GSM_GAP_AVAILABLE_IND,
MSG_ID_MPHD_UMTS_GAP_UNAVAILABLE_IND,
MSG_ID_MPHD_UMTS_GAP_AVAILABLE_IND,
MSG_ID_MPHD_DUAL_MODE_PRIMITIVE_END,
#ifdef __UMTS_FDD_MODE__
#ifdef __MTK_UL1_FDD__
MSG_ID_MPHD_UMTS_GAP_PATTERN_PCH_IND,
MSG_ID_MPHD_UMTS_GAP_PATTERN_FACH_IND,
MSG_ID_MPHD_UMTS_GAP_PATTERN_DCH_IND,
#else
MSG_ID_MPHD_UMTS_GAP_PATTERN_IND,
#endif
#endif /*__UMTS_FDD_MODE__*/

#ifdef __UMTS_TDD128_MODE__
MSG_ID_MPHD_UMTS_GAP_PATTERN_PCH_IND,
MSG_ID_MPHD_UMTS_GAP_PATTERN_FACH_IND,
MSG_ID_MPHD_UMTS_GAP_PATTERN_DCH_IND,
MSG_ID_MPHD_UMTS_GAP_PATTERN_HSPA_IND,
#endif /*__UMTS_TDD128_MODE__*/
MSG_ID_MPHD_UMTS_MODE_IND, /* MTK L1 only, to inform 2G L1 the current 3G mode */
MSG_ID_MPHD_UMTS_CELL_MEAS_DONE_IND, /* Maruco20090120, add new interface(UL1A->LL1->L1A->L1C) for DM low power optimize */
MODULE_MSG_END( MSG_ID_LL1_MSG_CODE_TAIL )

/* END */
#ifdef _Test_Hdr_On_PC
};
#endif

#endif //LL1_MSGID_H
