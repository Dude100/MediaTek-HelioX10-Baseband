/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   ulcs_sap.h
 *
 * Project:
 * --------
 *   AGPS
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *===========================================================================
 * $Log:$
 *
 * removed!
 * removed!
 * 1) confirm all _msgid.h is same as old (exclude fold ../delete/);
 * 2) fix range error in module_msg_range.h.
 *
 * removed!
 * removed!
 * Qinghua Yu check in global enum (MSG & SAP) at modem_dev.
 *
 * removed!
 * removed!
 * Qinghua Yu check in global enum (MSG & SAP) at modem_dev.
 *
 * removed!
 * removed!
 * Qinghua Yu check in global enum (MSG & SAP) at modem_dev.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * <saved by Perforce>
 *
 * removed!
 * removed!
 * 2G parameter initialization and UP/CP conflict handling modification
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * add to source control recursely
 *
 *===========================================================================
 ****************************************************************************/
#include "module_msg_range.h"

#ifndef _ULCS_MSG_H
#define _ULCS_MSG_H

MODULE_MSG_BEGIN( MSG_ID_UAGPS_CP_CODE_BEGIN )
//MSG_ID_UAGPS_CP_CODE_BEGIN,
// L4
MSG_ID_L4C_UAGPS_CP_AGPS_ENABLE_DISABLE_REQ = MSG_ID_UAGPS_CP_CODE_BEGIN,
MSG_ID_L4C_UAGPS_CP_AGPS_KEY_UPDATE_REQ,
MSG_ID_L4C_UAGPS_CP_AGPS_NEW_KEY_NEEDED_IND,

// CSCE
MSG_ID_UAGPS_CP_CSCE_START_SIB15_COLLECTION_REQ,
MSG_ID_UAGPS_CP_CSCE_START_SIB15_COLLECTION_CNF,
MSG_ID_UAGPS_CP_CSCE_STOP_SIB15_COLLECTION_REQ,
MSG_ID_UAGPS_CP_CSCE_STOP_SIB15_COLLECTION_CNF,
MSG_ID_UAGPS_CP_CSCE_CELL_CHANGE_IND,

// SIBE
MSG_ID_UAGPS_CP_SIBE_SIB15_CHANGE_IND,

// MEME
MSG_ID_UAGPS_CP_MEME_MOVE_TO_STATE_IND,
MSG_ID_UAGPS_CP_MEME_POSITIONING_DATA_IND,
MSG_ID_UAGPS_CP_MEME_RELEASE_MEASUREMENT_IND,
MSG_ID_UAGPS_CP_MEME_POSITIONING_DATA_REQ,
MSG_ID_UAGPS_CP_MEME_RELEASE_MEASUREMENT_REQ,
MSG_ID_UAGPS_CP_MEME_MEASUREMENT_REPORT_CNF,

MSG_ID_UAGPS_CP_CODE_END = MSG_ID_UAGPS_CP_MEME_MEASUREMENT_REPORT_CNF,
//MSG_ID_UAGPS_CP_CODE_END,
MODULE_MSG_END( MSG_ID_UAGPS_CP_CODE_TAIL )

#endif  //_ULCS_MSG_H
