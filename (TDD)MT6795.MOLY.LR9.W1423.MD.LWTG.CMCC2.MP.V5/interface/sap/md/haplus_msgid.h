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
 * haplus_sap.h
 *
 * Project:
 * --------
 *   katla
 *
 * Description:
 * ------------
 *   air controller related message identity definition
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
 *============================================================================
 ****************************************************************************/

#include "module_msg_range.h"

#ifndef _HALPLUS_MSGID_H
#define _HALPLUS_MSGID_H

/* Request for air controller */
#if defined (__UE_SIMULATOR__)
MODULE_MSG_BEGIN(MSG_ID_HAPLUS_MSG_CODE_BEGIN)
MSG_ID_HA_U_MSG_CODE_REQ_BEGIN = MSG_ID_HAPLUS_MSG_CODE_BEGIN,
MSG_ID_HA_U_FIND_PSCH_REQ,
MSG_ID_HA_U_FIND_SSCH_REQ,
MSG_ID_HA_U_FIND_CPICH_REQ,
MSG_ID_HA_U_FIND_PCCPCH_REQ,
MSG_ID_HA_U_FIND_PICH_REQ,
MSG_ID_HA_U_ENUM_DL_PATHS_REQ,
MSG_ID_HA_U_ENUM_DL_PATHS_BY_PSC_REQ,
MSG_ID_HA_U_CARRIER_RSSI_REQ,
MSG_ID_HA_U_FIND_SCCPCH_REQ,
MSG_ID_HA_U_FIND_DLDPCH_REQ,
MSG_ID_HA_U_SEND_ULDPCH_REQ,
MSG_ID_HA_U_FIND_AICH_REQ,
MSG_ID_HA_U_SEND_PRACH_REQ, 
MSG_ID_HA_U_FIND_HSSCCH_REQ,
MSG_ID_HA_U_FIND_HSPDSCH_REQ,
MSG_ID_HA_U_SEND_HSDPCCH_REQ,
MSG_ID_HA_U_SEND_EDCH_REQ,
MSG_ID_HA_U_FIND_EHICH_REQ,
MSG_ID_HA_U_FIND_ERGCH_REQ,
MSG_ID_HA_U_FIND_EAGCH_REQ,
MSG_ID_HA_U_FIND_FDPCH_REQ,
MSG_ID_HA_U_TIME_CONSUME_INFO_REQ,

MSG_ID_HA_U_FIND_PSCH_CNF = MSG_ID_HAPLUS_MSG_CODE_BEGIN + 101,
MSG_ID_HA_U_FIND_SSCH_CNF,
MSG_ID_HA_U_FIND_CPICH_CNF,
MSG_ID_HA_U_FIND_PCCPCH_CNF,
MSG_ID_HA_U_FIND_PICH_CNF,
MSG_ID_HA_U_ENUM_DL_PATHS_CNF,
MSG_ID_HA_U_ENUM_DL_PATHS_BY_PSC_CNF,
MSG_ID_HA_U_CARRIER_RSSI_CNF,
MSG_ID_HA_U_FIND_SCCPCH_CNF,
MSG_ID_HA_U_FIND_DLDPCH_CNF,
MSG_ID_HA_U_SEND_ULDPCH_CNF,
MSG_ID_HA_U_FIND_AICH_CNF,
MSG_ID_HA_U_SEND_PRACH_CNF,
MSG_ID_HA_U_FIND_HSSCCH_CNF,
MSG_ID_HA_U_FIND_HSPDSCH_CNF,
MSG_ID_HA_U_SEND_HSDPCCH_CNF,
MSG_ID_HA_U_SEND_EDCH_CNF,
MSG_ID_HA_U_FIND_EHICH_CNF,
MSG_ID_HA_U_FIND_ERGCH_CNF,
MSG_ID_HA_U_FIND_EAGCH_CNF,
MSG_ID_HA_U_FIND_FDPCH_CNF,
MSG_ID_HA_U_TIME_CONSUME_INFO_CNF,

MODULE_MSG_END(MSG_ID_HAPLUS_MSG_CODE_TAIL)
#endif

#endif  //_HALPLUS_MSGID_H

