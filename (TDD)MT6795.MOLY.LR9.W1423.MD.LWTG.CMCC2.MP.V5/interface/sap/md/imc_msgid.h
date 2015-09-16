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
 *   imc_msgid.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
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
 * IMC interface to LTECSR no rtppkt
 *
 * removed!
 * removed!
 * sync MP5 --> MP6 and lock MP5 code for IMC
 *
 * removed!
 * removed!
 * 	Merging timer
 *  	
 * 	//MOLY_CBr/ariel.lin/MOLY_IMC.TIMER/mcu/interface/sap/md/imc_msgid.h
 *  	
 * 	to //MOLY/BRANCHES_LR9/LR9.W1421.MD.LWTG.MP/mcu/interface/sap/md/imc_msgid.h
 *
 * removed!
 * removed!
 * Integration change for AT+ECCTRL and 2/3G auto sanity bug fixed (cancel retry timer)
 *
 * removed!
 * removed!
 * AT+ECCTRL feature
 *
 * removed!
 * removed!
 * TMO-US requirement: 60417
 * rat change ind to UA
 *
 * removed!
 * removed!
 * Add emergency bearer service indication from PS to IMC (IMSP-->IMC)
 *
 * removed!
 * removed!
 * AT+CDU=0 feature in
 *
 * removed!
 * IMSP handlers
 * 	.
 ****************************************************************************/

#ifndef _IMC_MSGID_H_
#define _IMC_MSGID_H_

#include "module_msg_range.h"

#define IMC_IN_RANGE (600)

	/*------------------- IMC_MSG_CODE_BEGIN---------------------*/
MODULE_MSG_BEGIN( MSG_ID_IMC_CODE_BEGIN )

  /* { */
  MSG_ID_IMC_BEGIN,

  /* -----------------------------------------------------*/
  /* this is for vm external messages */
  /* -----------------------------------------------------*/
  MSG_ID_IMC_EX_BEGIN,

    /* with ims proxy */
    MSG_ID_IMSP_IMC_BEGIN,
      /* inject */ 
      MSG_ID_IMSP_IMC_LOOP_TEST_RSP,

      MSG_ID_IMSP_IMC_INIT_IMS_CONFIG_REQ,
      MSG_ID_IMSP_IMC_UE_MODE_UPDATE_REQ,
      MSG_ID_IMSP_IMC_IMSVOPS_NOTIFICATION_REQ,
      MSG_ID_IMSP_IMC_CELL_INFO_UPDATE_REQ,
      MSG_ID_IMSP_IMC_POWER_OFF_REQ,
      MSG_ID_IMSP_IMC_OOS_START_REQ,
      MSG_ID_IMSP_IMC_OOS_END_REQ,
      MSG_ID_IMSP_IMC_EMB_S1_SUPP_REQ,
      MSG_ID_IMSP_IMC_NAS_PS_REG_STATUS_REQ,

      /* ss */
      MSG_ID_IMSP_IMC_SS_BEGIN,
        MSG_ID_IMSP_IMC_SS_SET_VIDEO_ABILITY_REQ,        
        MSG_ID_IMSP_IMC_SS_CONFERENCE_CONTROL_REQ,        
      MSG_ID_IMSP_IMC_SS_END,

      /* cc */
      MSG_ID_IMSP_IMC_CC_BEGIN,
        /* +ECCTRL */
        MSG_ID_IMSP_IMC_CALL_CONTROL_REQ,
      MSG_ID_IMSP_IMC_CC_END,

      /* IMS SIM */
      MSG_ID_IMSP_IMC_SIM_INVALID_REQ,

      /* configure */
      MSG_ID_IMSP_IMC_ECFG_SET_REQ, // IMSP --> IMC      
      MSG_ID_IMSP_IMC_ECFG_GET_REQ, // IMSP --> IMC
      
      /* AT+CDU=0 */
      MSG_ID_IMSP_IMC_QUERY_URI_TYPE_REQ,

      /* timer testing */
      MSG_ID_IMSP_IMC_TIMER_TEST_REQ,
      MSG_ID_IMSP_IMC_TIMER_TEST_CNF,

    MSG_ID_IMSP_IMC_END,

    /* with vdm */
    MSG_ID_VDM_IMC_BEGIN,

      MSG_ID_VDM_IMC_CC_BEGIN,
        MSG_ID_VDM_IMC_SRVCC_STATUS_UPDATE_REQ,
        MSG_ID_VDM_IMC_IMS_CC_MO_CALL_REQ,
        MSG_ID_VDM_IMC_IMS_CC_MT_CALL_PRESENT_RSP,
        MSG_ID_VDM_IMC_IMS_CC_MT_CALL_ACCEPT_REQ,
        MSG_ID_VDM_IMC_IMS_CC_FORCE_HANGUP_REQ,
        MSG_ID_VDM_IMC_IMS_CC_SEND_DIGIT_REQ,
        MSG_ID_VDM_IMC_IMS_CC_START_SEND_DIGIT_REQ,
        MSG_ID_VDM_IMC_IMS_CC_STOP_SEND_DIGIT_REQ,

      MSG_ID_VDM_IMC_CC_END,
      
      MSG_ID_VDM_IMC_SS_BEGIN,
        MSG_ID_VDM_IMC_IMS_CC_CALL_RELATED_SS_REQ,
        MSG_ID_VDM_IMC_IMS_CC_EXT_ERROR_REPORT_REQ,
        MSG_ID_VDM_IMC_IMS_CC_HANGUP_ALL_REQ,
        MSG_ID_VDM_IMC_IMS_CC_LIST_CURRENT_CALLS_REQ,
        MSG_ID_VDM_IMC_IMS_CC_ALLOC_CONF_CALL_RSP,
      MSG_ID_VDM_IMC_SS_END,
    MSG_ID_VDM_IMC_END,

    /* with lte csr */
    MSG_ID_IMC_LTECSR_BEGIN,
      MSG_ID_IMC_LTECSR_LOOP_TEST_REQ,
      MSG_ID_IMC_LTECSR_LOOP_TEST_CNF,
      MSG_ID_LTECSR_MEDIA_NO_DLPKT, 
    MSG_ID_IMC_LTECSR_END,

    MSG_ID_IMCSMS_IMC_BEGIN,
      MSG_ID_IMCSMS_IMC_SEND_SMS_REQ,
      MSG_ID_IMCSMS_IMC_RECV_SMS_RSP,
      MSG_ID_IMCSMS_IMC_REL_SMS_REQ,
      MSG_ID_IMCSMS_IMC_ABORT_SEND_SMS_REQ,
      MSG_ID_IMCSMS_IMC_ABORT_RECV_SMS_REQ,
    MSG_ID_IMCSMS_IMC_END,

  MSG_ID_IMC_EX_END,
  /* } */

  MSG_ID_IMC_IN_BEGIN,
    /* for internal used space */
  MSG_ID_IMC_IN_END = MSG_ID_IMC_IN_BEGIN + IMC_IN_RANGE,

  MSG_ID_IMC_END,

MODULE_MSG_END( MSG_ID_IMC_CODE_TAIL )
	/*------------------- IMC_MSG_CODE_END-----------------------*/


#endif /* _IMC_MSGID_H_ */
