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
 *   imsp_msgid.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   imsp related message identity definition
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

#ifndef _IMSP_MSGID_H
#define _IMSP_MSGID_H

    /*--------------- MSG_ID_IMSP_CODE_BEGIN------------------------*/

MODULE_MSG_BEGIN( MSG_ID_IMSP_CODE_BEGIN )

    /* IMCSMS --> IMSP*/
  MSG_ID_IMSP_IMCSMS_RANGE_BEGIN = MSG_ID_IMSP_CODE_BEGIN,
    MSG_ID_IMSP_IMCSMS_SUBMIT_CHECK_IND,
    MSG_ID_IMSP_IMCSMS_COMMAND_CHECK_IND,
    MSG_ID_IMSP_IMCSMS_SMMA_CHECK_IND,
  MSG_ID_IMSP_IMCSMS_RANGE_END,
  
    /* SDM --> IMSP*/
  MSG_ID_SDM_IMSP_RANGE_BEGIN,
    MSG_ID_SDM_IMSP_CMD_SEND_SMS_RSP,
    MSG_ID_SDM_IMSP_URC_RCV_SMS_REQ,
    MSG_ID_SDM_IMSP_CMD_SEND_SMMA_UPDATE_REQ,
    MSG_ID_SDM_IMSP_CS_SMS_SUBMIT,
    MSG_ID_SDM_IMSP_CMD_SEND_DELIVER_REPORT_RSP,
    MSG_ID_SDM_IMSP_CS_SMS_COMMAND,
    MSG_ID_SDM_IMSP_CS_SMS_SMMA,
  MSG_ID_SDM_IMSP_RANGE_END,
  
    /* VDM --> IMSP */
  MSG_ID_VDM_IMSP_RANGE_BEGIN,
    MSG_ID_VDM_IMSP_CMD_DIAL_RSP,
    MSG_ID_VDM_IMSP_CMD_DIAL_URI_RSP,
    MSG_ID_VDM_IMSP_CMD_DIAL_EMERG_RSP,
    MSG_ID_VDM_IMSP_CMD_STK_CALL_RSP,
    MSG_ID_VDM_IMSP_CMD_MT_CALL_APPROVE_RSP,
    MSG_ID_VDM_IMSP_CMD_MT_CALL_ACCEPT_RSP,
    MSG_ID_VDM_IMSP_CMD_HANGUP_ALL_RSP,
    MSG_ID_VDM_IMSP_CMD_FORCE_HANGUP_RSP,
    MSG_ID_VDM_IMSP_CMD_CALL_RELATED_SS_RSP,
    MSG_ID_VDM_IMSP_CMD_DTMF_RSP,
    MSG_ID_VDM_IMSP_CMD_EXT_DTMF_RSP,
    MSG_ID_VDM_IMSP_CMD_EXT_ERROR_REPORT_RSP,
    MSG_ID_VDM_IMSP_CMD_LIST_CURRENT_CALLS_RSP,
    MSG_ID_VDM_IMSP_SND_ECPI_MO_CALL_ID_ALLOC_REQ,
    MSG_ID_VDM_IMSP_SND_ECPI_MT_CALL_SETUP_REQ,
    MSG_ID_VDM_IMSP_SND_ECPI_CALL_RELEASE_REQ,
    MSG_ID_VDM_IMSP_SND_MT_CALL_APPROVE_REQ,

    MSG_ID_VDM_IMSP_CS_CC_MO_CALL_REQ,
    MSG_ID_VDM_IMSP_CS_CC_STK_CALL_REQ,
    MSG_ID_VDM_IMSP_CS_CC_MT_CALL_PRESENT_RSP,
    MSG_ID_VDM_IMSP_CS_CC_MT_CALL_ACCEPT_REQ,
    MSG_ID_VDM_IMSP_CS_CC_HANGUP_ALL_REQ,
    MSG_ID_VDM_IMSP_CS_CC_FORCE_HANGUP_REQ,
    MSG_ID_VDM_IMSP_CS_CC_CALL_RELATED_SS_REQ,
    MSG_ID_VDM_IMSP_CS_CC_EXT_ERROR_REPORT_REQ,
    MSG_ID_VDM_IMSP_CS_CC_SEND_DIGIT_REQ,
    MSG_ID_VDM_IMSP_CS_CC_START_SEND_DIGIT_REQ,
    MSG_ID_VDM_IMSP_CS_CC_STOP_SEND_DIGIT_REQ,
    MSG_ID_VDM_IMSP_CS_CC_ECPI_TRANSLATE_RSP,
    MSG_ID_VDM_IMSP_CS_CC_LIST_CURRENT_CALLS_REQ,
    MSG_ID_VDM_IMSP_CS_CC_EMERG_CALL_REQ,
    
    MSG_ID_VDM_IMSP_SND_ADS_STATUS_REQ,
    MSG_ID_VDM_IMSP_FDN_ECC_CHECK_REQ,
    MSG_ID_VDM_IMSP_GET_SSAC_PARAM_REQ,
    MSG_ID_VDM_IMSP_NW_SELECT_REQ,
    MSG_ID_VDM_IMSP_ABORT_NW_SELECT_REQ,
    MSG_ID_VDM_IMSP_SRVCC_CONTEXT_TRANSFER_REQ,
    MSG_ID_VDM_IMSP_SND_MT_CALL_RING_REQ,
    MSG_ID_VDM_IMSP_SND_SRVCC_CONF_CALL_ID_REQ,
    MSG_ID_VDM_IMSP_SND_STK_CALL_TR_REQ,
    MSG_ID_VDM_IMSP_VDM_VOICE_STATUS_REQ,
    MSG_ID_VDM_IMSP_SND_ADS_RESULT_REPORT_REQ,
  MSG_ID_VDM_IMSP_RANGE_END,

    /*IMC --> IMSP*/
  MSG_ID_IMSP_IMC_RANGE_BEGIN,
    MSG_ID_IMSP_IMC_LOOP_TEST_IND,
    MSG_ID_IMSP_IMC_POWER_OFF_CNF,
    MSG_ID_IMSP_IMC_IMS_REG_STATUS_IND,
    MSG_ID_IMSP_IMC_IMS_ENABLE_IND,
    MSG_ID_IMSP_IMC_CC_CALL_PROGRESS_IND,
    MSG_ID_IMSP_IMC_CC_PAU_IND,
    MSG_ID_IMSP_IMC_CC_IMSEMS_IND,
    MSG_ID_IMSP_IMC_CC_EVTSTATUS_IND,
    MSG_ID_IMSP_IMC_CC_ESPEECH_IND,
    MSG_ID_IMSP_IMC_SS_SET_VIDEO_ABILITY_CNF,
    MSG_ID_IMSP_IMC_SS_CONFERENCE_CONTROL_CNF,
    MSG_ID_IMSP_IMC_SS_SUBSCRIBE_CONTROL_IND,
    MSG_ID_IMSP_IMC_SS_CONFERENCE_CONTROL_IND,
    MSG_ID_IMSP_IMC_SS_PROGRESS_NOTIFY_IND,
    MSG_ID_IMSP_IMC_ECFG_SET_CNF, 
    MSG_ID_IMSP_IMC_ECFG_GET_CNF, 
    MSG_ID_IMSP_IMC_CC_CSSU_IND,
    MSG_ID_IMSP_IMC_QUERY_URI_TYPE_CNF,
    MSG_ID_IMSP_IMC_CALL_CONTROL_CNF,
    MSG_ID_IMSP_IMC_IMS_REG_START_IND,
    MSG_ID_IMSP_IMC_SIP_CALL_PROGRESS_IND,
  MSG_ID_IMSP_IMC_RANGE_END, 

MODULE_MSG_END( MSG_ID_IMSP_CODE_TAIL )

    /*---------------MSG_ID_IMSP_CODE_END---------------------*/

#endif  /* _IMSP_MSGID_H */
