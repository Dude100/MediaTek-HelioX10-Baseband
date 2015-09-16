/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   ps_public_l4_sap.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is the common public SAP for protocol stack.
 *
 * Author: Danny Kuo
 * -------
 *   
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
#include "module_msg_range.h"

#ifndef _PS_PUB_L4_MSG_H
#define _PS_PUB_L4_MSG_H

MODULE_MSG_BEGIN( MSG_ID_L4_PUBLIC_CODE_BEGIN )
    MSG_ID_GATI_DATA_IND = MSG_ID_L4_PUBLIC_CODE_BEGIN,  
    MSG_ID_GATI_DATA_RSP,
    MSG_ID_GATI_DATA_REQ,
    MSG_ID_GATI_DATA_CNF,
    MSG_ID_GATI_RTW_IND,
    MSG_ID_GATI_CTRL_REQ,
    MSG_ID_GATI_CTRL_CNF,
    MSG_ID_GATI_SWITCH_MODE_REQ,
    MSG_ID_GATI_SWITCH_MODE_CNF,
    MSG_ID_ATCIDT_FORCE_TRANSFER_REQ,
    MSG_ID_ATCIDT_FORCE_TRANSFER_CNF,
    MSG_ID_MMI_ATCI_MASTER_SIM_CHANGE_REQ,      
    MSG_ID_MMI_ATCI_MASTER_SIM_CHANGE_CNF,    
    MSG_ID_RMMI_REGISTER_CHANNEL_REQ,
    MSG_ID_RMMI_REGISTER_CHANNEL_CNF,
    MSG_ID_RMMI_EXE_AT_REQ,
    MSG_ID_RMMI_EXE_AT_CNF,
    MSG_ID_RMMI_RESPONSE_AT_IND,
    MSG_ID_RMMI_URC_AT_IND,
    MSG_ID_L4C_END_PS_DATA_SENSSION_REQ,
    MSG_ID_RMMI_LOCK_AT_CMD_REQ,
    MSG_ID_RMMI_LOCK_AT_CMD_CNF,
    MSG_ID_L4C_NBR_CELL_INFO_REG_REQ,       
    MSG_ID_L4C_NBR_CELL_INFO_REG_CNF,
    MSG_ID_L4C_NBR_CELL_INFO_DEREG_REQ,    
    MSG_ID_L4C_NBR_CELL_INFO_DEREG_CNF,
    MSG_ID_L4C_NBR_CELL_INFO_IND,
    MSG_ID_GAS_DATA_IND,
    MSG_ID_GAS_DATA_REQ,
    MSG_ID_L4C_MAX_TX_PWR_RED_REQ,
    MSG_ID_L4C_REGIONAL_PHONE_MODE_REQ,
    MSG_ID_L4C_MEAS_INFO_REQ, //for Thermal
    MSG_ID_L4C_ASSERT_BYPASS_TRACE_IND,
    MSG_ID_L4CTST_AT_RESPONSE_IND,
    MSG_ID_L4C_USB_SUSPEND_REQ,
    MSG_ID_L4C_USB_RESUME_REQ,
    /*not use
    MSG_ID_AGPS_ENABLE_DISABLE_RSP,
    MSG_ID_AGPS_KEY_UPDATE_RSP,
    MSG_ID_AGPS_NEW_KEY_NEEDED_IND,*/
    /*below are for AGPS auto test
    MSG_ID_AGPS_AUTO_TEST_IND,
    MSG_ID_AGPS_CP_UP_STATUS_IND,
    MSG_ID_AGPS_MOLR_START_IND,
    MSG_ID_AGPS_MOLR_STOP_IND,
    MSG_ID_AGPS_MTLR_RESPONSE_IND,*/
    MSG_ID_LBSAP_DATA_RECV_IND,
    MSG_ID_LBSAP_DATA_SEND_REQ,
    MSG_ID_L4C_INJECT_SBP_CHANGE_IND,
    MSG_ID_L4_PUBLIC_CODE_END = MSG_ID_L4C_INJECT_SBP_CHANGE_IND,
MODULE_MSG_END( MSG_ID_L4_PUBLIC_CODE_TAIL )

#endif //_PS_PUB_L4_MSG_H
