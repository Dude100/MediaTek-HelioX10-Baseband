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
 *   ccci_sys_msg_trace.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines CCCI SYS MSG DHL debug messages
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * 
 ****************************************************************************/
#ifndef _CCCI_SYS_MSG_TRACH_H
#define _CCCI_SYS_MSG_TRACH_H


#if HIF_CONSOLE_TRACE_ENABLED != 1

#ifndef GEN_FOR_PC
 #include "kal_public_defs.h"
#endif /* GEN_FOR_PC */

#include "dhl_trace.h"
#include "dhl_def.h"

#if !defined(GEN_FOR_PC)
#if defined(__DHL_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "ccci_sys_msg_trace_gen.h"
#endif /* TST Trace Defintion */
#endif

#endif /* HIF_CONSOLE_TRACE_ENABLED != 1 */

BEGIN_TRACE_MAP(MOD_CCCIMSG)
   //4  <fatal_error_msg>, follow by ASSERT(0);

   //info msg 
   TRC_MSG(CCCI_SYS_MSG_INIT, "[CCCISYSMSG] Init done !")
   TRC_MSG(CCCI_SYS_MSG_REG_CB, "[CCCISYSMSG] Register msgid( %x) callback Funp(%x) successfully !")
   TRC_MSG(CCCI_SYS_MSG_INVK_CB, "[CCCISYSMSG] Invoke  msgid( %x ) callback!")
   TRC_MSG(CCCI_SYS_MSG_SEND_SLEEPMASKING_MSG, "[CCCISYSMSG] Send SYSMSG CCMSG_ID_SYSMSGSVC_L1_SLEEPMASKING, data ( %d )")
   TRC_MSG(CCCI_SYS_MSG_SEND_ILM_D, "[CCCISYSMSG] Send ILM TO L4C with data, msgid( %x ), data( %d )")
   TRC_MSG(CCCI_SYS_MSG_SEND_ILM, "[CCCISYSMSG] Send ILM TO L4C, msgid( %x )")

   //warning msg
   TRC_MSG(CCCI_SYS_MSG_SLEEPMASKING, "[CCCISYSMSG] CCCI_SLEEPMASKING : warning1\0")
   TRC_MSG(CCCI_SYS_MSG_UNKNOW_MB_ID, "[CCCISYSMSG] Unknow mailbox ID : %d")
   TRC_MSG(CCCI_SYS_MSG_INVALID_PARM, "[CCCISYSMSG] Invalid parameter for ccci_register_sysmsgsvc_callback, ( %d ), ( %x )")
   TRC_MSG(CCCI_SYS_MSG_INVALID_ID, "[CCCISYSMSG] Invalid Message ID from AP, ( %x )")
   TRC_MSG(CCCI_SYS_MSG_INVALID_REG_CB, "[CCCISYSMSG] No Registered Call Back Function, ( %x )")

   //error msg
   TRC_MSG(CCCI_SYS_MSG_ABNORMAL_DL_CB, "[CCCISYSMSG] Abnormal TX (Downlink) callback")
   TRC_MSG(CCCI_SYS_MSG_UL_CHANNEL_INIT_RESULT, "[CCCISYSMSG] Uplink channel (%d) init, %d")
   TRC_MSG(CCCI_SYS_MSG_DL_CHANNEL_INIT_RESULT, "[CCCISYSMSG] Downlink channel (%d) init, %d")

   //sleep control msg
   TRC_MSG(CCCI_SYS_MSG_CCCI_MD_SLEEP_LOCK, "[CCCISYSMSG] CCCI MD SLEEP LOCK Request, sleepHd(%d)")
   TRC_MSG(CCCI_SYS_MSG_CCCI_MD_SLEEP_UNLOCK, "[CCCISYSMSG] CCCI MD SLEEP UNLOCK Request, sleepHd(%d)")
   TRC_MSG(CCCI_SYS_MSG_CCCI_MD_SLEEP_INVALID, "[CCCISYSMSG] CCCI MD SLEEP INVALID Value, %d")
   
END_TRACE_MAP(MOD_CCCIMSG)


#endif //#ifndef _CCCI_SYS_MSG_TRACH_H