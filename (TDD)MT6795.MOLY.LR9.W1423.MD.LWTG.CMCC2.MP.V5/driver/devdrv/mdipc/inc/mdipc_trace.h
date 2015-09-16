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
 *   mdipc_trace.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines MDIPC debug message
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 ****************************************************************************/
#ifndef __MDIPC_TRACE_H__
#define __MDIPC_TRACE_H__

#if defined(__CC_IRQ_EXIST__)

#ifndef GEN_FOR_PC
 #include "kal_public_defs.h"
#endif /* GEN_FOR_PC */

#include "dhl_trace.h"
#include "dhl_def.h"

#if !defined(GEN_FOR_PC)
#if defined(__DHL_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "mdipc_trace_gen.h"
#endif /* TST Trace Defintion */
#endif

typedef enum {
    MSG_ID_MDIPC_SYS_STATE_INIT,
    MSG_ID_MDIPC_SYS_STATE_RUNNING,
    MSG_ID_MDIPC_SYS_STATE_ASYNC
} mdipc_msg_sys_state_enum;

#if defined(__MD1__)
BEGIN_TRACE_MAP(MOD_LISR2HISR_CC_IRQ_MD2MD1_SYS)
    TRC_MSG(MDIPC_SYS_STATE_TRANS, "[MDIPC] State transsion: %Mmdipc_msg_sys_state_enum to %Mmdipc_msg_sys_state_enum")
    TRC_MSG(MDIPC_SYS_STATE_RX_INIT_HS, "[MDIPC] Receive Init Handshake Packet")
    TRC_MSG(MDIPC_SYS_STATE_RX_EXCEP_HS, "[MDIPC] Receive Exception Handshake Packet")
    TRC_MSG(MDIPC_SYS_STATE_PEER_HANG, "[MDIPC] Peer has no response")
    TRC_MSG(MDIPC_SYS_USER_CB, "[MDIPC] User CB")
    TRC_MSG(MDIPC_SYS_HISR, "[MDIPC] HISR - %d")
    TRC_MSG(MDIPC_MSG, "[MDIPC] CCMSG")
END_TRACE_MAP(MOD_LISR2HISR_CC_IRQ_MD2MD1_SYS)
#else
BEGIN_TRACE_MAP(MOD_CC_SYS_HISR)
    TRC_MSG(MDIPC_SYS_STATE_TRANS, "[MDIPC] State transsion: %Mmdipc_msg_sys_state_enum to %Mmdipc_msg_sys_state_enum")
    TRC_MSG(MDIPC_SYS_STATE_RX_INIT_HS, "[MDIPC] Receive Init Handshake Packet")
    TRC_MSG(MDIPC_SYS_STATE_RX_EXCEP_HS, "[MDIPC] Receive Exception Handshake Packet")
    TRC_MSG(MDIPC_SYS_STATE_PEER_HANG, "[MDIPC] Peer has no response")
    TRC_MSG(MDIPC_SYS_USER_CB, "[MDIPC] User CB")
    TRC_MSG(MDIPC_SYS_HISR, "[MDIPC] HISR - %d")    
    TRC_MSG(MDIPC_MSG, "[MDIPC] CCMSG")
END_TRACE_MAP(MOD_CC_SYS_HISR)
#endif

#endif

#endif    /* __MDIPC_TRACE_H__ */
