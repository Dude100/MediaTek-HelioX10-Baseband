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
 *   uas_gas_gemini_sap.h
 *
 * Project:
 * --------
 *   GEMINI
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
 * 01 13 2012 ij.liao
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * add to source control recursely
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * add to source control recursely
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 *===========================================================================
 ****************************************************************************/
#include "module_msg_range.h"

#ifndef _UAS_GAS_GEMINI_MSG_H
#define _UAS_GAS_GEMINI_MSG_H

#ifdef __SOURCE_INSIGHT_PARSE__
typedef enum {
#endif

MODULE_MSG_BEGIN( MSG_ID_GEMINI_UAS_CODE_BEGIN )
//MSG_ID_GEMINI_UAS_CODE_BEGIN,
MSG_ID_GAS_UAS_SUSPEND_SERVICE_REQ = MSG_ID_GEMINI_UAS_CODE_BEGIN,
MSG_ID_GAS_UAS_RESUME_SERVICE_REQ,
MSG_ID_GEMINI_UAS_CODE_END = MSG_ID_GAS_UAS_RESUME_SERVICE_REQ, 
//MSG_ID_GEMINI_UAS_CODE_END,
MODULE_MSG_END( MSG_ID_GEMINI_UAS_CODE_TAIL )

MODULE_MSG_BEGIN( MSG_ID_GEMINI_GAS_CODE_BEGIN )
//MSG_ID_GEMINI_GAS_CODE_BEGIN,
MSG_ID_UAS_GAS_SUSPEND_SERVICE_REQ = MSG_ID_GEMINI_GAS_CODE_BEGIN,
MSG_ID_UAS_GAS_RESUME_SERVICE_REQ,
MSG_ID_GEMINI_GAS_CODE_END = MSG_ID_UAS_GAS_RESUME_SERVICE_REQ,
//MSG_ID_GEMINI_GAS_CODE_END,
MODULE_MSG_END( MSG_ID_GEMINI_GAS_CODE_TAIL )

#ifdef __SOURCE_INSIGHT_PARSE__
};
#endif

#endif  //_UAS_GAS_GEMINI_MSG_H
