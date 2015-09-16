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
 *   supl_sap.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is the common public SAP for protocol stack.
 *
 * Author:
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "module_msg_range.h"

#ifndef _PS_PUB_SUPL_MSG_H
#define _PS_PUB_SUPL_MSG_H

#ifdef __BUILD_DOM__
/**************************************
 * <GROUP Messages >
 *
 * SUPL_LCSP SAP primitives
 *************************************/
 typedef enum{
 #endif
MODULE_MSG_BEGIN( MSG_ID_PS_PUBLIC_SUPL_MSG_CODE_BEGIN )
    MSG_ID_SUPL_MMI_PUSH_REQ = MSG_ID_PS_PUBLIC_SUPL_MSG_CODE_BEGIN, /* MMI uses this message to notify SUPL a incoming push (SUPL INIT). If the push contains correct SUPL INIT, SUPL will use this message to notify the start of a SUPL session. Direction: MMI-> SUPL\n Local parameter: supl_mmi_push_req_struct. Peer buffer: None. */
    MSG_ID_SUPL_MMI_STATUS_IND, /* SUPL uses this message to notify MMI the new status. */
    MSG_ID_SUPL_MMI_STATUS_RSP, /* MMI uses this message to notify SUPL the result of STATUS_IND. */
    MSG_ID_SUPL_MMI_NOTIFY_IND, /* SUPL uses this message to notify an notification or verification coming. */
    MSG_ID_SUPL_MMI_NOTIFY_RSP, /* MMI uses this message to notify the response of an notification or verification. */ 
    MSG_ID_SUPL_MMI_START_REQ,  /* MMI uses this message to request starting a SUPL SET initiated session. */
    MSG_ID_SUPL_MMI_ABORT_REQ,  /* MMI uses this message to request aborting a SUPL SET initiated session. */
    MSG_ID_SUPL_MMI_ABORT_CNF,  /* SUPL uses this message to notify the result of aborting. */
MODULE_MSG_END( MSG_ID_PS_PUBLIC_SUPL_MSG_CODE_TAIL )

#ifdef __BUILD_DOM__
} sap_supl_mmi_enum;
#endif

#endif //_PS_PUB_SUPL_MSG_H
