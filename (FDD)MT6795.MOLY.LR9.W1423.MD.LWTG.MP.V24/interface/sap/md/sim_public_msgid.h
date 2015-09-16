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
 *   sim_public_msgid.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   SAP provided by SIM task and outside-PS task uses also
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

#ifndef _SIM_PUB_MSG_H
#define _SIM_PUB_MSG_H

   /*------------------------MSG_ID_SIM_PUBLIC_CODE_BEGIN ---------------*/
MODULE_MSG_BEGIN( MSG_ID_SIM_PUBLIC_CODE_BEGIN )
   MSG_ID_SIM_READY_IND = MSG_ID_SIM_PUBLIC_CODE_BEGIN,   
   MSG_ID_SIM_RESET_REQ,  
   MSG_ID_SIM_RESET_CNF,  
   MSG_ID_BT_SIM_CONNECT_REQ, /*mtk01612:  [MAUI_02023545] BT_SIM_Profile for MAUI and DUMA*/
   MSG_ID_BT_SIM_CONNECT_CNF,
   MSG_ID_BT_SIM_RESET_REQ,
   MSG_ID_BT_SIM_RESET_CNF,
   MSG_ID_BT_SIM_APDU_REQ,
   MSG_ID_BT_SIM_APDU_CNF,
   MSG_ID_BT_SIM_DISCONNECT_REQ,
   MSG_ID_BT_SIM_DISCONNECT_CNF,
   MSG_ID_BT_SIM_POWER_OFF_REQ,
   MSG_ID_BT_SIM_POWER_OFF_CNF,
   MSG_ID_BT_SIM_POWER_ON_REQ,
   MSG_ID_BT_SIM_POWER_ON_CNF,
   MSG_ID_SIM_AUTHENTICATE_REQ,
   MSG_ID_SIM_AUTHENTICATE_CNF,
   MSG_ID_SIM_QUERY_INFO_REQ,
   MSG_ID_SIM_QUERY_INFO_CNF,   
   MSG_ID_SIM_ACCESS_EXTMD_IND,
   MSG_ID_SIM_ACCESS_EXTMD_RES,
   MSG_ID_SIM_EXTMD_NOTIFY_REQ,
   MSG_ID_SIM_EXTMD_NOTIFY_CNF,
   MSG_ID_SIM_APP_AUTHENTICATE_REQ,
   MSG_ID_SIM_APP_AUTHENTICATE_CNF,
   MSG_ID_SIM_PUBLIC_CODE_END = MSG_ID_SIM_APP_AUTHENTICATE_CNF,
MODULE_MSG_END( MSG_ID_SIM_PUBLIC_CODE_TAIL )

   /*------------------------MSG_ID_SIM_PUBLIC_CODE_END -----------------*/

#endif  //_SIM_PUB_MSG_H
