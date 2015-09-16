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
#include "module_msg_range.h"

#ifndef _AUIDO_MSGID_H
#define _AUIDO_MSGID_H

MODULE_MSG_BEGIN( MSG_ID_AUDIO_MSG_CODE_BEGIN )
MSG_ID_AUDIO_CCCI_BEGIN = MSG_ID_AUDIO_MSG_CODE_BEGIN,

MSG_ID_AUDIO_A2M_CCCI,
MSG_ID_AUDIO_M2A_CCCI,
MSG_ID_AUDIO_AFE_REFRESH,
MSG_ID_AUDIO_CTM_PROCESS,
MSG_ID_AUDIO_CTM_RX_DATA,
MSG_ID_AUDIO_STRM_PCM4WAY_DATA,
MSG_ID_AUDIO_STRM_BGSND_DATA_REQUEST,
MSG_ID_AUDIO_STRM_VM_DATA_REQUEST,
MSG_ID_AUDIO_VM_DATA_NOTIFICATION,

MSG_ID_SPEECH_ON_ACK,
MSG_ID_SPEECH_OFF_ACK,
MSG_ID_STRM_SPEECH_DL_DATA_NOTIFY,
MSG_ID_STRM_SPEECH_UL_DATA_REQUEST,
// No Application Use, but code is reserved
MSG_ID_AUDIO_STRM_PCM_DATA_REQUEST,
MSG_ID_AUDIO_STRM_PCM_REC_DATA_NOTIFICATION,
MSG_ID_AUDIO_AMR_DATA_NOTIFICATION,
MSG_ID_AUDIO_BGSND_DATA_REQUEST,
MSG_ID_AUDIO_PCM_DATA_NOTIFICATION,
MSG_ID_AUDIO_TONE_STOP_REQUEST,
MSG_ID_AUDIO_TONE_DETECT,
MSG_ID_AUDIO_VM_DATA_REQUEST,
MSG_ID_AUDIO_WAV_DATA_REQUEST,
MSG_ID_AUDIO_WAV_DATA_NOTIFICATION,

MSG_ID_AUDIO_L4C_EPOF_NOTIFY, 

MSG_ID_AUDIO_CCCI_TAIL,

// M2M message
MSG_ID_AUDIO_M2M_BEGIN,

MSG_ID_AUDIO_M2M_VOLTE_MAC_TIMING_INFO,
MSG_ID_AUDIO_M2M_CCCI,
MSG_ID_AUDIO_M2M_VOLTE_KT_BGSND_CLOSE,
MSG_ID_AUDIO_M2M_VOLTE_TONE_BGSND_CLOSE,
MSG_ID_AUDIO_M2M_VOLTE_DL_KT_PLAY,
MSG_ID_AUDIO_M2M_VOLTE_DL_KT_STOP,
MSG_ID_AUDIO_M2M_VOLTE_UL_KT_PLAY,
MSG_ID_AUDIO_M2M_VOLTE_UL_KT_STOP,
MSG_ID_AUDIO_M2M_VOLTE_DL_TONE_PLAY,
MSG_ID_AUDIO_M2M_VOLTE_DL_TONE_STOP,
MSG_ID_AUDIO_M2M_VOLTE_UL_TONE_PLAY,
MSG_ID_AUDIO_M2M_VOLTE_UL_TONE_STOP,
MSG_ID_AUDIO_M2M_SP_L4C_SET_EVENT,

MSG_ID_AUDIO_M2M_TAIL,

MODULE_MSG_END( MSG_ID_AUDIO_MSG_CODE_TAIL )
#endif  //_AUIDO_MSGID_H
