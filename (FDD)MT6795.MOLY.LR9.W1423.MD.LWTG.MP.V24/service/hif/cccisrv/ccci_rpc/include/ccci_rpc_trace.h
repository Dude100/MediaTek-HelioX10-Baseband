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
 *   ccci_rpc_trace.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines CCCI_RPC DHL debug messages
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
 * [CCCI RPC] Debug enhancement & Add log.
 *
 * 05 14 2013 ap.wang
 * removed!
 * [CCCI RPC] Add trace log
 *
 * 05 14 2013 ap.wang
 * removed!
 * [CCCI RPC] Add trace log
 *
 ****************************************************************************/
#ifndef __CCCI_RPC_TRACH_H__
#define __CCCI_RPC_TRACH_H__


#if HIF_CONSOLE_TRACE_ENABLED != 1

#ifndef GEN_FOR_PC
 #include "kal_public_defs.h"
#endif /* GEN_FOR_PC */

#include "dhl_trace.h"
#include "dhl_def.h"

#if !defined(GEN_FOR_PC)
#if defined(__DHL_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "ccci_rpc_trace_gen.h"
#endif /* TST Trace Defintion */
#endif

#endif /* HIF_CONSOLE_TRACE_ENABLED != 1 */

BEGIN_TRACE_MAP(MOD_CCCIRPC)

    //4  <data path msg>
    TRC_MSG(CCCI_RPC_IPC_RPC_CCCI_Write_FUNC_TRA,            "[CCCI_RPC] IPC_RPC_CCCI_Write START \n")
    TRC_MSG(CCCI_RPC_IPC_RPC_CCCI_Write_FUNC_PASS_TRA,       "[CCCI_RPC] IPC_RPC_CCCI_Write PASS \n")
    TRC_MSG(CCCI_RPC_IPC_RPC_CCCI_Read_FUNC_TRA,             "[CCCI_RPC] IPC_RPC_CCCI_Read START \n")
    TRC_MSG(CCCI_RPC_IPC_RPC_CCCI_Read_FUNC_PASS_TRA,        "[CCCI_RPC] IPC_RPC_CCCI_Read PASS \n")
    TRC_MSG(CCCI_RPC_IPC_RPC_Process_CMD_FUNC_TRA,           "[CCCI_RPC] IPC_RPC_Process_CMD START \n")
    TRC_MSG(CCCI_RPC_IPC_RPC_Process_CMD_FUNC_PASS_TRA,      "[CCCI_RPC] IPC_RPC_Process_CMD PASS \n")
    TRC_MSG(CCCI_RPC_IPC_RPC_Wrapper_FUNC_TRA,               "[CCCI_RPC] IPC_RPC_Wrapper START \n")
    TRC_MSG(CCCI_RPC_IPC_RPC_Wrapper_FUNC_PASS_TRA,          "[CCCI_RPC] IPC_RPC_Wrapper PASS \n")
    TRC_MSG(CCCI_RPC_ccci_rpc_send_cb_FUNC_TRA,              "[CCCI_RPC] ccci_rpc_send_cb START \n")
    TRC_MSG(CCCI_RPC_ccci_rpc_send_cb_FUNC_PASS_TRA,         "[CCCI_RPC] ccci_rpc_send_cb PASS \n")
    TRC_MSG(CCCI_RPC_ccci_rpc_receive_cb_FUNC_TRA,           "[CCCI_RPC] ccci_rpc_receive_cb START \n")
    TRC_MSG(CCCI_RPC_ccci_rpc_receive_cb_FUNC_PASS_TRA,      "[CCCI_RPC] ccci_rpc_receive_cb PASS \n")
    TRC_MSG(CCCI_RPC_CCCI_HEADER_TRA,                        "[CCCI_RPC] CCCI Header %#X %#X %#X %#X \n")
    TRC_MSG(CCCI_RPC_HEADER_TRA,                             "[CCCI_RPC] RPC Header OPID=%#X NUM_PARA=%#X \n")
    TRC_MSG(CCCI_RPC_EVENT_WAKEUP_FUNC_TRA,                  "[CCCI_RPC] ccci_rpc_receive_cb event wakeup:%d \n")
    TRC_MSG(CCCI_RPC_GET_FREE_INDEX_TRA,                     "[CCCI_RPC] ccci get free index:%d \n")
    TRC_MSG(CCCI_RPC_WRITE_FAIL_TRA,                         "[CCCI_RPC] ccci write gpd fail \n")
    TRC_MSG(CCCI_RPC_GPD_POOL_FULL_ERR,             "[CCCI_RPC][ERROR] Index:%d GPD have received \n")
    TRC_MSG(CCCI_RPC_ALLOC_GPD_ERROR,               "[CCCI_RPC][ERROR] IPC_RPC_CCCI_Write alloc GPD error \n")
    TRC_MSG(CCCI_RPC_RECEIVE_OPID_ERR,              "[CCCI_RPC][ERROR] IPC_RPC_CCCI_Read OPID error, expect %#X receive %#X\n")
    TRC_MSG(CCCI_RPC_PRAR_NUM_ERR,                  "[CCCI_RPC][ERROR] IPC_RPC_CCCI_Read PARA NUM error, expect %d receive %d\n")
    TRC_MSG(CCCI_RPC_PRAR_LENGTH_ERR,               "[CCCI_RPC][ERROR] IPC_RPC_CCCI_Read PARA Length too long error, prar %d expect %d receive %d\n")
    TRC_MSG(CCCI_RPC_PARA_NUM_FULL_ERROR,           "[CCCI_RPC][ERROR] MAX: %d Input: %d \n")
    //4 <init msd>

    //4 <ut msg>


    
END_TRACE_MAP(MOD_CCCIRPC)


#endif //#ifndef __CCCI_RPC_TRACH_H__

