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
 * Filename:
 * ---------
 *   ipc_defs.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   IP Core internal configuration and data structure definition.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                 HISTORY
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
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __INC_IPC_DEFS_H
#define __INC_IPC_DEFS_H

#include "kal_public_api.h"

#include "ipc_api.h"
#include "ipc_session.h"
#include "ipc_ut.h"

#define IPC_PEER_NULL_DROP          1
#define IPC_PEER_NULL_LOOPBACK      2
#define IPC_PEER_LTM_SIM            3
#define IPC_PEER_UPCM               4
#define IPC_PEER_UT                 5

/*------------------------------------------------------------------------------
 * Configuration.
 *----------------------------------------------------------------------------*/
#ifdef IPC_PEER_LOOPBACK
#define IPC_PEER                    IPC_PEER_NULL_LOOPBACK
#else
#define IPC_PEER                    IPC_PEER_UPCM
#endif

#if defined(__LTM_SIMULATION_SUPPORT__)
    #undef IPC_PEER
    #define IPC_PEER                    IPC_PEER_LTM_SIM
#endif

#ifdef ATEST_SYS_IPCORE
    #undef IPC_PEER
    #define IPC_PEER                    IPC_PEER_UT
#endif

/*------------------------------------------------------------------------------
 * Constant definition.
 *----------------------------------------------------------------------------*/
#define IPC_ASSERT ASSERT               /* To completely bypass the overhead of ASSERT(), we could define IPC_ASSERT(...) to nothing. */

#define IPC_DL_INVALID_LEN_DROP_EN      1// 0: disable, 1: enable
#define IPC_DL_VALID_PACKET_LEN         1500

/*------------------------------------------------------------------------------
 * Internal data structure defintion.
 *----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 * Global variables. 
 *----------------------------------------------------------------------------*/

/*------------------------------------------------------------------------------
 * Internal function prototype.
 *----------------------------------------------------------------------------*/
kal_bool ipc_init(void);
void ipc_on_ilm(ilm_struct *ilm);
kal_bool ipc_reset(void);
kal_bool ipc_is_in_reset(void);
void ipc_set_ul_throttle(local_para_struct *local_para_ptr);
void ipc_ul_throttle_sysmsgsvc_cbk(kal_uint32 ap_param);

#endif /* __INC_IPC_DEFS_H */
