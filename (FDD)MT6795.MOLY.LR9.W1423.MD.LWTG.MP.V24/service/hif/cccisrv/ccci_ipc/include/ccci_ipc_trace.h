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
 *   ccci_ipc_trace.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines CCCI_IPC DHL debug messages
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
 * [CCCI IPC] Support Clibtime feature
 *
 * 03 31 2014 ap.wang
 * removed!
 * .
 *
 * 09 12 2013 ap.wang
 * removed!
 * 	Add CCCI Log
 *
 * 05 09 2013 ap.wang
 * removed!
 * [CCCI_IPC] Add allocate GPD fail error handling
 *
 ****************************************************************************/
#ifndef __CCCI_IPC_TRACH_H__
#define __CCCI_IPC_TRACH_H__


#if HIF_CONSOLE_TRACE_ENABLED != 1

#ifndef GEN_FOR_PC
 #include "kal_public_defs.h"
#endif /* GEN_FOR_PC */

#include "dhl_trace.h"
#include "dhl_def.h"

#if !defined(GEN_FOR_PC)
#if defined(__DHL_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "ccci_ipc_trace_gen.h"
#endif /* TST Trace Defintion */
#endif

#endif /* HIF_CONSOLE_TRACE_ENABLED != 1 */

BEGIN_TRACE_MAP(MOD_CCCIIPC)

    //4  <data path msg>
    TRC_MSG(CCCI_RECEIVE_MSG_FUNC_TRA,          "[CCCI_IPC] ccci_ipc_receive_msg_cb START \n")
    TRC_MSG(CCCI_RECEIVE_MSG_FUNC_PASS_TRA,     "[CCCI_IPC] ccci_ipc_receive_msg_cb PASS \n")
    TRC_MSG(CCCI_SEND_MSG_FUNC_TRA,             "[CCCI_IPC] ccci_ipc_send_msg START \n")
    TRC_MSG(CCCI_SEND_MSG_FUNC_PASS_TRA,        "[CCCI_IPC] ccci_ipc_send_msg PASS \n")
    TRC_MSG(CCCI_SEND_MSG_CB_FUNC_TRA,          "[CCCI_IPC] ccci_ipc_send_msg_cb START \n")
    TRC_MSG(CCCI_SEND_MSG_CB_FUNC_PASS_TRA,     "[CCCI_IPC] ccci_ipc_send_msg_cb PASS \n")
    TRC_MSG(CCCI_IPC_ERROR_CB_FUNC_ERR,         "[CCCI_IPC][ERROR] ccci_ipc_error_cb Not implement, should not be called\n")
    TRC_MSG(CCCI_IPC_ERROR_ILM_MSGID_ERR,       "[CCCI_IPC][ERROR] ccci_ipc_main ILM msgid = %d \n")
    TRC_MSG(CCCI_SEND_MSG_FUNC_ILM_ERROR,       "[CCCI_IPC][ERROR] ccci_ipc_send_msg ILM is not alloc from ipc_msgsvc_allocate_ilm \n")
    TRC_MSG(CCCI_SEND_MSG_FUNC_TASKID_ERROR,    "[CCCI_IPC][ERROR] ccci_ipc_send_msg error taskid, dest = %d, src = %d \n")
    TRC_MSG(CCCI_SEND_MSG_FUNC_DESTID_ERROR,    "[CCCI_IPC][ERROR] ccci_ipc_send_msg error destnation id, dest = %d\n")
    TRC_MSG(CCCI_ALLOC_ILM_FUNC_ERROR,          "[CCCI_IPC][ERROR] ipc_msgsvc_allocate_ilm error mutile alloc ilm, MOD_ID = %d\n")
    TRC_MSG(CCCI_IPC_RECEIVE_SEND_ILM_ERR,      "[CCCI_IPC][ERROR] ccci_ipc_receive_msg_cb ext_msg_queue exhausted \n")
    TRC_MSG(CCCI_SEND_MSG_FUNC_ALLOC_GPD_ERROR, "[CCCI_IPC][ERROR] ccci_ipc_send_msg Allocate GPD fail\n")


    TRC_MSG(CCCI_RECEIVE_MSG_TRA_CCCI,          "[CCCI_IPC][UL] CCCI(%08x %08x %08x %08x)\n")
    TRC_MSG(CCCI_RECEIVE_MSG_TRA_ILM,           "[CCCI_IPC][UL] ILM %08x src=%08x dest=%08x sap=%08x msg=%08x local=%08x peer=%08x \n")
    TRC_MSG(CCCI_RECEIVE_MSG_TRA_ILM_SEND,      "[CCCI_IPC][UL] dest=%08x msg=%08x local=%08x ref_count=%08x \n")
    TRC_MSG(CCCI_SEND_MSG_TRA_CCCI,             "[CCCI_IPC][DL] CCCI(%08x %08x %08x %08x)\n")
    TRC_MSG(CCCI_SEND_MSG_TRA_ILM,              "[CCCI_IPC][DL] ILM %08x src=%08x dest=%08x sap=%08x msg=%08x local=%08x peer=%08x \n")
    TRC_MSG(CCCI_ALLOC_ILM_FUNC,                "[CCCI_IPC] ipc_msgsvc_allocate_ilm MOD_ID = %d\n")
    TRC_MSG(CCCI_IPC_PROCESS_CB_START,          "[CCCI_IPC] ccci_ipc_process_cb_funp START msg_id = %d msg_pos = %d \n")
    TRC_MSG(CCCI_IPC_PROCESS_CB_PASS,           "[CCCI_IPC] ccci_ipc_process_cb_funp PASS msg_id = %d msg_pos = %d exe_time = %d \n")
    //4 <init msd>

    //4 <ut msg>


    
END_TRACE_MAP(MOD_CCCIIPC)


#endif //#ifndef __CCCI_IPC_TRACH_H__

