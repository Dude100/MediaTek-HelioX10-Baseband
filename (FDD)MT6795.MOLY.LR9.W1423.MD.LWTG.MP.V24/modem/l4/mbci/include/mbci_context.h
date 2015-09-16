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
 *   mbci_context.h
 *
 * Project:
 * --------
 *   MT6280
 *
 * Description:
 * ------------
 *   This file is intends for MBCI implementation.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


#ifndef _MBCI_CONTEXT_H
#define _MBCI_CONTEXT_H

#include "kal_general_types.h"
#include "mbim_defs.h"
#include "mbci_struct.h"
#include "layer4_context.h"
#include "ps_public_struct.h"
#include "sim_public_enum.h"
#include "mbci_timer.h"

#define MBCI_INVALID_PDP_CONTEXT_ID     (0xff)

#define MBCI_MAX_SIM_NUM      (L4_MAX_SIM_NUM)

#define MBCI_CURRENT_SIM    ((sim_interface_enum)(mbci_current_mod_id - MOD_MBCI))

//#define MBCI_MAX_SRC    (MBIM_MAX_SUPPORT_TRANSACTION)

typedef struct
{
    kal_uint8 context_id;
    kal_uint32 SessionId;
    kal_uint8 UserName[255];
    kal_uint8 Password[255];
    kal_uint32 AuthProtocol;
} mbci_set_connect_param_struct;

typedef struct
{
    kal_uint8 primary_cid;
    kal_uint8 secondary_cid;
} mbci_connect_session_struct;

typedef struct
{
    mbim_op_enum op;
    kal_uint16   src_id;
    mbim_uuid_enum uuid;
    kal_uint32  cid;
    kal_uint32  command_type;   // 0:query , 1:set
    kal_uint32  tid; // Transaction ID (0: unused)
    void    *parameter;
} mbci_transaction_struct;

typedef struct
{
    mbci_state_enum state;
    kal_bool loopback_mode;
    mbci_transaction_struct transaction[MBIM_MAX_SUPPORT_TRANSACTION];

    kal_uint32 loopback_SessionId;
    kal_uint32 loopback_IPType;
    kal_uint32 loopback_ContextType[16];

    kal_uint8 gsm_state; // reg_state_enum
    kal_uint8 gprs_state; // reg_state_enum

    kal_uint8 Rssi;
    kal_uint8 ErrorRate;
    kal_uint32 RssiThreshold;
    kal_uint32 ErrorRateThreshold;
    kal_uint32 SignalStrengthInterval;
    kal_bool SignalStrengthDisable;


    kal_uint8 no_msisdn;
    l4csmu_addr_struct msisdn[2];

    kal_uint8 request_oper[7];

    mbci_connect_session_struct session[MBIM_MAX_SESSION];

    kal_uint32 NwError;

    kal_uint8 device_service_subscribe_list[MBIM_UUID_MAX][MBIM_CID_BASIC_CONNECT_MAX];  // IMPORTTANT: Assume basic connect always has the most CIDs

    kal_uint16 waiting_for_sleep;

    kal_bool smsfull;

    kal_uint8 default_pdp_type;

    kal_bool pending_open;
    kal_uint32 pending_open_tid;

    mbci_timer_struct mbci_timer;
    mbci_timer_info_struct     timer_pool[MBCI_MAX_TIMER_ITEM];
} mbci_context_struct;

extern module_type mbci_current_mod_id;
extern mbci_context_struct *mbci_ptr_g;

#define MBCI_PTR        mbci_ptr_g

typedef void (*MBCI_CID_FUNCTION)(mbci_transaction_struct*, kal_uint32, kal_uint8 *);

#endif /* _MBCI_CONTEXT_H */

