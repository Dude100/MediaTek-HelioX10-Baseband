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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   cc_sys_comm.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This Module defines CC IRQ system control functions.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "cc_irq_public.h"
#include "cc_irq_adaptation.h"
#include "dhl_trace.h"
#include "mdipc_trace.h"

#define CC_IRQ_DBG_ENABLE
#define CC_IRQ_DBG_LOG_ENABLE

extern void cc_irq_msg_init();
extern void cc_irq_msg_isr();
extern void cc_irq_msg_runtime_reset();

CC_IRQ_CALLBACK_P cc_irq_sys_misc_cb[CC_IRQ_SYS_USER_CB_NUMBER];
kal_uint32        cc_sys_state = 0;
kal_uint32        cc_sys_last_excep_tx_ret;

mdipc_msg_sys_state_enum    cc_sys_state_trace[CC_IRQ_SYS_STATE_MAX] = {MSG_ID_MDIPC_SYS_STATE_INIT, MSG_ID_MDIPC_SYS_STATE_RUNNING, MSG_ID_MDIPC_SYS_STATE_ASYNC};


#if defined(CC_IRQ_DBG_ENABLE)
kal_uint32 cc_sys_state_dbg_0[64], cc_sys_state_dbg_1[64];
kal_uint32 cc_sys_state_dbg_ptr = 0;
#endif

kal_int32 cc_sys_state_trans(kal_uint32 current_state, kal_uint32 next_state)
{
#if defined(CC_IRQ_DBG_ENABLE)
    if (current_state >= CC_IRQ_SYS_STATE_MAX || next_state >= CC_IRQ_SYS_STATE_MAX)
        return -1;
    
    dhl_trace(TRACE_INFO, 0, MDIPC_SYS_STATE_TRANS, cc_sys_state_trace[current_state], cc_sys_state_trace[next_state]);

#if defined(CC_IRQ_DBG_LOG_ENABLE)
    cc_sys_state_dbg_0[cc_sys_state_dbg_ptr] = current_state;
    cc_sys_state_dbg_1[cc_sys_state_dbg_ptr] = next_state;
    cc_sys_state_dbg_ptr = (cc_sys_state_dbg_ptr + 1) % 64;
#endif
#endif

    return 0;
}

kal_int32 cc_irq_sys_tx_with_buffer(void *addr, kal_uint32 length)
{
    kal_int32            ret;
    kal_uint32           usc_start, usc_current;

    usc_start = ust_get_current_time();
    
    while (1)
    {
        ret = cc_irq_trigger_interrupt_with_buff(CC_IRQ_SYS_TX_INDEX, addr, length);

        if (ret == CC_IRQ_SUCCESS)
        {
            return ret;
        }
        else if (ret == CC_IRQ_ERR_CHANNEL_FULL)
        {
            usc_current = ust_get_current_time();
            if (ust_us_duration(usc_start, usc_current) > CC_IRQ_NR_TIMEOUT_US)
            {
                /* state transition */
                ASSERT(cc_sys_state_trans(cc_sys_state, CC_IRQ_SYS_STATE_ASYNC) == 0);
                dhl_trace(TRACE_INFO, 0, MDIPC_SYS_STATE_PEER_HANG);
                cc_sys_state = CC_IRQ_SYS_STATE_ASYNC;
                CC_IRQ_SET_DISABLE();
                return CC_IRQ_ERR_PEER_ASYNC;
            }
        }
        else if (ret == CC_IRQ_ERR_PEER_ASYNC)
        {
            return CC_IRQ_ERR_PEER_ASYNC;
        }
        else
        {
            EXT_ASSERT(0, ret, CC_IRQ_SYS_TX_INDEX, (kal_uint32)addr);
        }
    }
}

kal_int32 cc_sys_comm_tx(void *addr, kal_uint32 length, cc_irq_sys_pkt_hdr_t *hdr)
{
    kal_uint8  buffer[CC_IRQ_BUFF_MAX];
    
    ASSERT(length <= CC_IRQ_BUFF_MAX - sizeof(cc_irq_sys_pkt_hdr_t));
    
    /* init header */
    *(cc_irq_sys_pkt_hdr_t*)buffer = *hdr;
    
    /* copy payload */
    if (addr && (length != 0))
        kal_mem_cpy((void*)buffer + sizeof(cc_irq_sys_pkt_hdr_t), addr, length);
    
    return cc_irq_sys_tx_with_buffer((void*)buffer, length + sizeof(cc_irq_sys_pkt_hdr_t));
}

void cc_sys_comm_cb(kal_uint32 para0, kal_uint32 para1, kal_uint32 para2)
{
    cc_irq_sys_pkt_hdr_t *hdr;
    kal_int32            ret;
    
    hdr = (cc_irq_sys_pkt_hdr_t *)para0;
    
    dhl_trace(TRACE_INFO, 0, MDIPC_SYS_HISR, hdr->op_id);
    
    switch (hdr->op_id)
    {
    case CC_IRQ_SYS_OP_CTRL:
        {
            cc_irq_sys_pkt_ctrl_t *sys_hdr = (cc_irq_sys_pkt_ctrl_t *)hdr;
            
            /* INIT -> RUNNING */
            if (cc_sys_state == CC_IRQ_SYS_STATE_INIT && sys_hdr->ctrl_type == CC_IRQ_SYS_PKT_TYPE_INIT_HS)
            {
                ASSERT(cc_sys_state_trans(cc_sys_state, CC_IRQ_SYS_STATE_RUNNING) == 0);
                dhl_trace(TRACE_INFO, 0, MDIPC_SYS_STATE_RX_INIT_HS);
                
                cc_sys_state = CC_IRQ_SYS_STATE_RUNNING;
                CC_IRQ_SET_ENABLE();
           }
            /* ASYNC -> RUNNING */
            /* RUNNING -> RUNNING with runtime reset */            
            else if (sys_hdr->ctrl_type == CC_IRQ_SYS_PKT_TYPE_INIT_HS && cc_sys_state == CC_IRQ_SYS_STATE_ASYNC)
            {
                cc_irq_sys_pkt_ctrl_t sys_hdr;
            	
                dhl_trace(TRACE_INFO, 0, MDIPC_SYS_STATE_RX_INIT_HS);
                
                /* runtime reset takes place */
                cc_irq_msg_runtime_reset();
                
                /* another core has exception, send a HS packet for state transition of another core */
                sys_hdr.op_id = CC_IRQ_SYS_OP_CTRL;
                sys_hdr.ctrl_type = CC_IRQ_SYS_PKT_TYPE_INIT_HS;
                sys_hdr.reserved = 0;
                
                CC_IRQ_SET_ENABLE();
                
                ret = cc_sys_comm_tx(NULL, 0, (cc_irq_sys_pkt_hdr_t*)&sys_hdr);
                EXT_ASSERT(ret == CC_IRQ_SUCCESS, ret, 0, 0);
                
                /* change state for running state */
                ASSERT(cc_sys_state_trans(cc_sys_state, CC_IRQ_SYS_STATE_RUNNING) == 0);
                cc_sys_state = CC_IRQ_SYS_STATE_RUNNING;
            }           
            /* RUNNING -> ASYNC */
            else if (cc_sys_state == CC_IRQ_SYS_STATE_RUNNING && sys_hdr->ctrl_type == CC_IRQ_SYS_PKT_TYPE_EXCEP)
            {
                ASSERT(cc_sys_state_trans(cc_sys_state, CC_IRQ_SYS_STATE_ASYNC) == 0);
                dhl_trace(TRACE_INFO, 0, MDIPC_SYS_STATE_RX_EXCEP_HS);
                cc_sys_state = CC_IRQ_SYS_STATE_ASYNC;
                CC_IRQ_SET_DISABLE();
            }
            else
            {
                ASSERT(0);
            }
        }
        break;
    case CC_IRQ_SYS_OP_MSG:
        {
            cc_irq_msg_isr((void*)para0, para1);
        }
        break;
    case CC_IRQ_SYS_OP_MISC:
        {
            cc_irq_sys_pkt_misc_t *misc_hdr = (cc_irq_sys_pkt_misc_t *)hdr;
            
            ASSERT(misc_hdr->ext_id < CC_IRQ_SYS_USER_CB_NUMBER);
            EXT_ASSERT(cc_irq_sys_misc_cb[misc_hdr->ext_id] != NULL, misc_hdr->ext_id, 0, 0);
            cc_irq_sys_misc_cb[misc_hdr->ext_id](para0 + sizeof(cc_irq_sys_pkt_hdr_t), para1 - sizeof(cc_irq_sys_pkt_hdr_t), 0);
        }
        break;
    default:
        ASSERT(0);
    }
}

void cc_sys_comm_init()
{
    cc_irq_sys_pkt_ctrl_t hdr;
    kal_int32             ret;

    cc_irq_register_callback(CC_IRQ_SYS_RX_INDEX, cc_sys_comm_cb);
    cc_irq_msg_init();
    cc_irq_unmask(CC_IRQ_SYS_RX_INDEX);
    
    CC_IRQ_GET_CC_MUTEX();
    CC_IRQ_HW_RESET();
    
    /* send init HS packet */
    /* trigger cc irq to notify another core */
    hdr.op_id = CC_IRQ_SYS_OP_CTRL;
    hdr.ctrl_type = CC_IRQ_SYS_PKT_TYPE_INIT_HS;
    hdr.reserved = 0;
    
    /* enable TX for init HS */
    CC_IRQ_SET_ENABLE();
    ret = cc_sys_comm_tx(NULL, 0, (cc_irq_sys_pkt_hdr_t*)&hdr);
    ASSERT(ret == CC_IRQ_SUCCESS);
    /* disable TX */
    //CC_IRQ_SET_DISABLE();
    
    CC_IRQ_RELEASE_CC_MUTEX();
}

kal_int32 cc_irq_user_register_cb(kal_uint32 user_index, CC_IRQ_CALLBACK_P user_cb)
{
    if (!CC_IRQ_USER_RX_INDEX_IS_IN_RANGE(user_index) || user_cb == NULL)
    {
        return CC_IRQ_ERR_PARAM;
    }

    user_index = CC_IRQ_USER_RX_INDEX_OFFSET(user_index);

    cc_irq_sys_misc_cb[user_index] = user_cb;
    
    return CC_IRQ_SUCCESS;
}

kal_int32 cc_irq_user_tx(kal_uint32 user_index, void *addr, kal_uint32 length)
{
    cc_irq_sys_pkt_misc_t hdr;

    if (!CC_IRQ_USER_TX_INDEX_IS_IN_RANGE(user_index) || addr == NULL || length > CC_IRQ_BUFF_MAX - sizeof(cc_irq_sys_pkt_hdr_t))
        return CC_IRQ_ERR_PARAM;

    hdr.op_id = CC_IRQ_SYS_OP_MISC;
    hdr.ext_id = CC_IRQ_USER_TX_INDEX_OFFSET(user_index);
    hdr.reserved = 0;
    
    return cc_sys_comm_tx(addr, length, (cc_irq_sys_pkt_hdr_t*)&hdr);
}

void cc_sys_comm_excep_handling()
{
    cc_irq_sys_pkt_ctrl_t hdr;

    if (cc_sys_state != CC_IRQ_SYS_STATE_RUNNING)
    {
        cc_sys_last_excep_tx_ret = CC_IRQ_SYS_STATE_ASYNC;
        return;
    }

    /* notify another core the exception status */
    hdr.op_id = CC_IRQ_SYS_OP_CTRL;
    hdr.ctrl_type = CC_IRQ_SYS_PKT_TYPE_EXCEP;
    hdr.reserved = 0;
    cc_sys_last_excep_tx_ret = cc_sys_comm_tx(NULL, 0, (cc_irq_sys_pkt_hdr_t*)&hdr);
}
