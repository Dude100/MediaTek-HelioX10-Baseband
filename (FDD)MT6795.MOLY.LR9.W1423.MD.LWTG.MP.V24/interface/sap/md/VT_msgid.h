/*******************************************************************************
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
*******************************************************************************/
 /******************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 ******************************************************************************/

 /******************************************************************************
 * Filename:
 * ---------
 *   VT_sap.h
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *  VT related message identity definition (private)
 *
 * Author:
 * -------
 * -------
 *
 *=============================================================
 *                HISTORY
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *

*******************************************************************************
 * removed!
 * removed!
*
 * removed!
 * removed!
*
*******************************************************************************/
#include "module_msg_range.h"

#ifndef VT_MSG_H
#define VT_MSG_H

// ----------------------------------------
// Private
// ----------------------------------------

MODULE_MSG_BEGIN( MSG_ID_VT_CODE_BEGIN )

// CSM
MSG_ID_CSM_VT_ACTIVATE_REQ = MSG_ID_VT_CODE_BEGIN,
MSG_ID_CSM_VT_ACTIVATE_CNF,
MSG_ID_CSM_VT_DEACTIVATE_REQ,
MSG_ID_CSM_VT_DEACTIVATE_CNF,
MSG_ID_CSM_VT_DISC_IND,

// CSR
MSG_ID_VT_CSR_UPLINK_DATA_IND,
MSG_ID_VT_CSR_START_CONSUME_DL_IND,

// F_CSR
MSG_ID_VT_F_CSR_ACTIVATE_REQ,
MSG_ID_VT_F_CSR_DEACTIVATE_REQ,

// UT
/* Jeffery: H245 UT 1 */
MSG_ID_VT_UT_H245_SYNC_IND,
/* Jeffery: H245 UT 3 */
MSG_ID_VT_UT_H245_DL_MSG,

/* Jeffery: xSRP UT 3 */
MSG_ID_VT_UT_XSRP_RX_MSG,
/* Jeffery: xSRP UT 4 */
MSG_ID_VT_UT_XSRP_TX_MSG,
/* Jeffery: xSRP UT 5 */
MSG_ID_VT_UT_XSRP_H245_DL_DATA_IND,
/* Jeffery: xSRP UT 6 */
MSG_ID_VT_UT_XSRP_H245_UL_DATA_REQ,

/* Jeffery: H223 UT 3 - control */
MSG_ID_VT_UT_H223_CTRL_UL_DATA_REQ,
/* Jeffery: H223 UT 3 - audio */
MSG_ID_VT_UT_H223_AUDIO_UL_DATA_REQ,
/* Jeffery: H223 UT 3 - video */
MSG_ID_VT_UT_H223_VIDEO_UL_DATA_REQ,
/* Jeffery: H223 UT 4 - control */
MSG_ID_VT_UT_H223_CTRL_DL_DATA_IND,
/* Jeffery: H223 UT 4 - audio */
MSG_ID_VT_UT_H223_AUDIO_DL_DATA_IND,
/* Jeffery: H223 UT 4 - video */
MSG_ID_VT_UT_H223_VIDEO_DL_DATA_IND,

// VT
MSG_ID_VT_CSR_CONSUME_DL_IND,
MSG_ID_VT_LOOPBACK_AUDIO_DATA,
MSG_ID_VT_LOOPBACK_VIDEO_DATA,
MSG_ID_VT_DBG_DL_H245_MSG_IND,
MSG_ID_VT_DBG_UL_H245_MSG_IND,

// L1SP
MSG_ID_VT_SP3G_UL_DATA_READY_IND,

// MED
MSG_ID_MED_VT_CODEC_OPEN_ACK,
MSG_ID_MED_VT_PUT_UL_VIDEO_IND,

// TVT
MSG_ID_TVT_UT_UART_DATA_REQ,
MODULE_MSG_END( MSG_ID_VT_CODE_TAIL )

#endif  //VT_MSG_H
