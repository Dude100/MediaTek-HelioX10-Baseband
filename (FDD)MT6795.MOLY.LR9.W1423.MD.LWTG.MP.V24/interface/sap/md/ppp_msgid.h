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
 *   ppp.sap
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   PPP related message identity definition
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
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "module_msg_range.h"

#ifndef _PPP_MSG_H
#define _PPP_MSG_H

	/*-------------- PPP_MSG_CODE_BEGIN ------------------------*/

MODULE_MSG_BEGIN( MSG_ID_PPP_CODE_BEGIN )
	/*-------------- PPP for GPRS messages ---------------------*/
	/* msg from L4C */

	MSG_TAG_PPP_FIRST_GPRS_MSG = MSG_ID_PPP_CODE_BEGIN,
	MSG_ID_L4CPPP_ACTIVATE_REQ = MSG_TAG_PPP_FIRST_GPRS_MSG,
	MSG_ID_L4CPPP_DEACTIVATE_REQ,
	MSG_ID_L4CPPP_RESUME_REQ,
	MSG_ID_L4CPPP_PPPTYPEPDP_UART_TRANSFER_IND, // PPP Type PDP Dialup Feature
	MSG_ID_L4CPPP_IPV4V6_FALLBACK_RSP,          //__IPV4V6__

    /* msg from TCM */
	MSG_ID_TAF_EXT_PDP_ACTIVATE_ACK_RSP,
  	MSG_ID_TAF_EXT_PDP_ACTIVATE_REJ_RSP,
  	MSG_ID_TAF_EXT_PDP_DEACTIVATE_ACK_RSP,
  	MSG_ID_TAF_EXT_PDP_DEACTIVATE_REQ,
  	MSG_ID_TAF_DATA_REQ,
  	MSG_ID_TAF_EXT_UPDATE_PDP_ADDR_REQ,
  	MSG_ID_TAF_EXT_PDP_SET_IP_AND_DNS_INFO_CNF,
	//mtk04121
	/* PPP Dial-up */
	MSG_ID_TAF_EXT_ENTER_DATA_MODE_CNF,

	/* msg to self(PPP) */
	MSG_ID_PPP_FLC_DATA_RESUME_IND,
	MSG_ID_PPP_STATUS_REPORT_IND,
	MSG_ID_PPP_PROCESS_PKT_IND,

       MSG_ID_TAF_PS_SUSPEND_IND,
       MSG_ID_TAF_PS_RESUME_IND,
	MSG_TAG_PPP_LAST_GPRS_MSG = MSG_ID_TAF_PS_RESUME_IND,

	
	/*-------------- PPP for CSD messages ---------------------*/
	/* msg from L4C */
	MSG_TAG_PPP_FIRST_CSD_MSG,
	MSG_ID_L4CPPP_CSD_ACTIVATE_REQ = MSG_TAG_PPP_FIRST_CSD_MSG,
	MSG_ID_L4CPPP_CSD_DEACTIVATE_REQ,
	
	/* msg from TCPIP */
	MSG_ID_TCPIP_PPP_DATA_REQ,
	MSG_ID_SOC_PPP_DL_SRPDU_RESUME,
	
	/* msg from CSD */
	MSG_ID_FLC_PPP_UL_APPDU_RESUME,
	MSG_ID_PPP_TDT_DATA_IND,

#ifdef __PPP_UT__ 
        MSG_ID_PPP_TST_DATA_REQ,
#endif /* ~ __PPP_UT__ */
	MSG_ID_PPP_L2R_DATA_IND,		
		
	MSG_TAG_PPP_LAST_CSD_MSG = MSG_ID_PPP_L2R_DATA_IND,

       /*------------- EXT MODEM related messages ----------------*/
       MSG_TAG_PPP_FIRST_EXT_MODEM_MSG,  
       /* EXT_MODEM <--> PPP */
       MSG_ID_PPP_EXT_MODEM_DATA_REQ = MSG_TAG_PPP_FIRST_EXT_MODEM_MSG,
       MSG_ID_PPP_EXT_MODEM_DATA_IND,
       MSG_ID_EXT_MODEM_PPP_ACTIVATE_REQ,
       MSG_ID_EXT_MODEM_PPP_ACTIVATE_CNF,
       MSG_ID_EXT_MODEM_PPP_DEACTIVATE_REQ,
       MSG_ID_EXT_MODEM_PPP_DEACTIVATE_CNF,
       MSG_ID_EXT_MODEM_PPP_DEACTIVATE_IND,

       MSG_TAG_PPP_LAST_EXT_MODEM_MSG = MSG_ID_EXT_MODEM_PPP_DEACTIVATE_IND,

       MSG_ID_PPP_CODE_END = MSG_TAG_PPP_LAST_EXT_MODEM_MSG,
MODULE_MSG_END( MSG_ID_PPP_CODE_TAIL )
	
	/*--------------- PPP_MSG_CODE_END--------------------*/

#endif //_PPP_MSG_H
