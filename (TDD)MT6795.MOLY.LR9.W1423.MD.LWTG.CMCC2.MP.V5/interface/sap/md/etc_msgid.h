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
 *   etc_msgid.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   LTE ETC (evolved test control) related message identity definition
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
 * Check in LPP CP interfaces & capability for EMM (OA domain)
 ****************************************************************************/

#ifndef _ETC_MSGID_H
#define _ETC_MSGID_H

#include "module_msg_range.h"

MODULE_MSG_BEGIN( MSG_ID_ETC_CODE_BEGIN )
/****************************************************************************
 *                          Destination: ETC (UPCM to ETC) 
 ****************************************************************************/
MSG_ID_ETC_UPCM_TESTMODE_CNF              = MSG_ID_ETC_CODE_BEGIN,
MSG_ID_ETC_UPCM_TESTLOOP_CNF,

/****************************************************************************
 *                          Destination: UPCM (ETC to UPCM) 
 ****************************************************************************/
MSG_ID_ETC_UPCM_TESTMODE_REQ,
MSG_ID_ETC_UPCM_TESTLOOP_REQ,


/****************************************************************************
 *                          Destination: ETC (EMM to ETC) 
 ****************************************************************************/
MSG_ID_ETC_EMM_TESTMODE_CNF,
MSG_ID_ETC_EMM_TESTLOOP_CNF,
MSG_ID_ETC_EMM_DATA_IND,
MSG_ID_ETC_EMM_DETACH_IND,
MSG_ID_ETC_EMM_RELEASE_IND,


/****************************************************************************
 *                          Destination: EMM (ETC to EMM) 
 ****************************************************************************/
MSG_ID_ETC_EMM_TESTMODE_REQ,
MSG_ID_ETC_EMM_TESTLOOP_REQ,
MSG_ID_ETC_EMM_DATA_REQ,
MSG_ID_ETC_EMM_NW_RESET_UE_STORED_POS_INFO_IND, // for LPP

MSG_ID_ETC_CODE_END,

MODULE_MSG_END( MSG_ID_ETC_CODE_TAIL )

#endif 
