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
 *   cc_irq_msg.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This Module defines CC IRQ Message-Passing API.
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
#include "kal_public_defs.h"
#include "cc_irq_public.h"
#include "cc_irq_int.h"
#include "cc_irq_adaptation.h"
#include "us_timer.h"
#include "intrCtrl.h"
#include "dhl_trace.h"
#include "mdipc_trace.h"

#define CC_IRQ_MSG_SEQ_MAX            255
#define CC_IRQ_MSG_PKT_HDR_LEN        4
#define CC_IRQ_MSG_MAGIC_LEN          4
#define CC_IRQ_MSG_MAGIC_NUMBER       0x534D4343    //- CCMS

#define CC_IRQ_MSG_PKT_MAX_LEN        (CC_IRQ_BUFF_MAX)
#define CC_IRQ_MSG_PKT_PLD_MAX_LEN    (CC_IRQ_MSG_PKT_MAX_LEN - CC_IRQ_MSG_PKT_HDR_LEN - CC_IRQ_MSG_MAGIC_LEN)
#define CC_IRQ_MSG_1ST_PKT_LP_MAX_LEN    (CC_IRQ_MSG_PKT_PLD_MAX_LEN - sizeof(ilm_struct))

#define CC_IRQ_MSG_RX_CONCUR_SKT_NUMBER    16
#define CC_IRQ_MSG_RX_SKT_SEQ_NOT_USED     0xFFFFFFFF

typedef enum {
    CC_IRQ_SYS_PKT_TYPE_HEAD = 0,
    CC_IRQ_SYS_PKT_TYPE_BODY,
    CC_IRQ_SYS_PKT_TYPE_TAIL,
    CC_IRQ_SYS_PKT_TYPE_SINGLE,
    CC_IRQ_SYS_PKT_TYPE_ACK,
    CC_IRQ_SYS_PKT_TYPE_MAX
} cc_irq_sys_pkt_type_t;

typedef struct {
    kal_uint32 op_id:4;
    kal_uint32 type:4;
    kal_uint32 seq:8;
    kal_uint32 pkt_num:8;
    kal_uint32 pkt_len:8;
} cc_irq_msg_pkt_hdr_t;

typedef struct {
    kal_uint32  seq;
    kal_uint32  total_len;
    kal_uint32  rx_len;
    kal_uint32  pkt_num;
    kal_uint8   *rx_ptr;
    module_type ilm_dst_mod;
    module_type ilm_src_mod;
    msg_type    ilm_msg_id;
    sap_type    ilm_sap_id;
} cc_irq_msg_rx_socket_t;

#define CC_IRQ_MSG_MOD_ID_IN_TX_RANGE(module_id)    (1)
#define CC_IRQ_MSG_GET_INDEX(dst_mod_id)            (CC_IRQ_SYS_TX_INDEX)

cc_irq_msg_rx_socket_t cc_irq_msg_rx_socket[CC_IRQ_MSG_RX_CONCUR_SKT_NUMBER];
kal_uint32 cc_irq_msg_seq = 0;

void cc_irq_msg_init()
{
    kal_uint32 i;
	
    for (i = 0; i < CC_IRQ_MSG_RX_CONCUR_SKT_NUMBER; i++)
        cc_irq_msg_rx_socket[i].seq = CC_IRQ_MSG_RX_SKT_SEQ_NOT_USED;
}

void cc_irq_msg_runtime_reset()
{
    cc_irq_msg_seq = 0;
    cc_irq_msg_init();
}

void cc_irq_msg_write_hdr(cc_irq_msg_pkt_hdr_t* hdr, kal_uint32 type, kal_uint32 pkt_num, kal_uint32 pkt_len, kal_uint32 seq)
{
    hdr->op_id   = CC_IRQ_SYS_OP_MSG;
    hdr->type    = type;
    hdr->pkt_num = pkt_num;
    hdr->seq     = seq;
    hdr->pkt_len = pkt_len;
}

/*
    HDR - OP_ID   (4b)
        - TYPE    (4b) (HEAD, BODY, TAIL, ACK)        
        - SEQ     (1B)
        - PKT_NUM (1B)
        - PKT_LEN (1B) (not include size of header / footer)
*/
kal_int32 cc_irq_msg_send5(module_type _src_mod_id, module_type _dest_mod_id, 
                           sap_type    _sap_id,     msg_type    _msg_id,      
                           local_para_struct *_local_para_ptr)
{
    kal_uint32 payload_len, payload_remain_len, pkt_len, pkt_num, pkt_type, cur_seq, savedMask;
    kal_int32  ret;
    kal_uint8  *pkt_ptr, *lp_ptr;
    kal_uint8  pkt_buffer[CC_IRQ_BUFF_MAX];

#ifdef __TST_MODULE__
    /* TST primitive log here */
    tst_log_primitive((ilm_struct *)pkt_ptr);
#endif /* __TST_MODULE__ */	

    if (!CC_IRQ_MSG_MOD_ID_IN_TX_RANGE(_dest_mod_id))
        return CC_IRQ_ERR_PARAM;

    /* calculate length of ILM + local parameter */
    payload_len = sizeof(ilm_struct);
    if (_local_para_ptr)
        payload_len += _local_para_ptr->msg_len;
    
    /* Only 1 packet. 1st packet length depends on length of ILM + local parameter */
    if (payload_len <= CC_IRQ_MSG_PKT_PLD_MAX_LEN)
    {
        /* indlucde header and magic number in pkt_len */    	
        pkt_len = payload_len;
        pkt_type = CC_IRQ_SYS_PKT_TYPE_SINGLE;
    }
    /* More than 1 packet. 1st packet length will be max size of a packet */
    else
    {
        /* packet length will be max (inlucde header and magic number */
        pkt_len = CC_IRQ_MSG_PKT_PLD_MAX_LEN;
        pkt_type = CC_IRQ_SYS_PKT_TYPE_HEAD;
    }
    
    /* update seq */
    savedMask = SaveAndSetIRQMask();
    cur_seq = cc_irq_msg_seq;
    cc_irq_msg_seq = (cc_irq_msg_seq + 1) % CC_IRQ_MSG_SEQ_MAX;
    RestoreIRQMask(savedMask);
    
    pkt_ptr = pkt_buffer;
    cc_irq_msg_write_hdr((cc_irq_msg_pkt_hdr_t*)pkt_ptr, pkt_type, 0, pkt_len + CC_IRQ_MSG_PKT_HDR_LEN + CC_IRQ_MSG_MAGIC_LEN, cur_seq);
    pkt_ptr += sizeof(cc_irq_msg_pkt_hdr_t);
    payload_remain_len = payload_len;

    /* 1st pkt: fill in magin number */
    *(kal_uint32*)pkt_ptr = CC_IRQ_MSG_MAGIC_NUMBER;
    pkt_ptr += CC_IRQ_MSG_MAGIC_LEN;
    
    /* 1st pkt: fill ILM */
    ((ilm_struct *)pkt_ptr)->src_mod_id     = CC_IRQ_MSG_TX_GET_GLB_MOD_ID(_src_mod_id);
    ((ilm_struct *)pkt_ptr)->dest_mod_id    = _dest_mod_id;
    ((ilm_struct *)pkt_ptr)->sap_id         = _sap_id;
    ((ilm_struct *)pkt_ptr)->msg_id         = _msg_id;
    ((ilm_struct *)pkt_ptr)->local_para_ptr = _local_para_ptr;
    ((ilm_struct *)pkt_ptr)->peer_buff_ptr  = NULL;

#ifdef __TST_MODULE__
    /* TST primitive log here */
    tst_log_primitive((ilm_struct *)pkt_ptr);
#endif /* __TST_MODULE__ */	
    
    pkt_ptr += sizeof(ilm_struct);

    
    /* logging for cross core ILM event */
    dhl_trace(TRACE_INFO, 0, MDIPC_MSG);
    dhl_log_primitive((ilm_struct *)pkt_ptr);
    
    
    
    /* decrease copy length of HDR and magic number */
    payload_remain_len -= sizeof(ilm_struct);
    
    /* case for local_para is not NULL */
    if (payload_remain_len > 0)
    {
        /* copy local parameter to buff of 1st packet */
        if (payload_remain_len > CC_IRQ_MSG_1ST_PKT_LP_MAX_LEN)
        {
            /* case when we need more packet */
            ASSERT(pkt_type == CC_IRQ_SYS_PKT_TYPE_HEAD);
            kal_mem_cpy((void*)pkt_ptr, (void*)_local_para_ptr, CC_IRQ_MSG_1ST_PKT_LP_MAX_LEN);
            pkt_ptr += CC_IRQ_MSG_1ST_PKT_LP_MAX_LEN;
            payload_remain_len -= CC_IRQ_MSG_1ST_PKT_LP_MAX_LEN;
            lp_ptr = (kal_uint8*)_local_para_ptr + CC_IRQ_MSG_1ST_PKT_LP_MAX_LEN;
        }
        else
        {
            /* case that only one packet is enough */
            ASSERT(pkt_type == CC_IRQ_SYS_PKT_TYPE_SINGLE);
            kal_mem_cpy((void*)pkt_ptr, (void*)_local_para_ptr, payload_remain_len);
            pkt_ptr += payload_remain_len;
            payload_remain_len = 0;
        }
    }

    /* send 1st packet */
    ret = cc_irq_sys_tx_with_buffer((void*)pkt_buffer, (kal_uint32)pkt_ptr - (kal_uint32)pkt_buffer);
    if (ret != CC_IRQ_SUCCESS)
        return ret;
    
    pkt_num = 1;
    /* copy remaining packet */
    while(payload_remain_len)
    {
        kal_uint32 back_for_hdr, back_for_magic;
        
        /* use 8 byte ahead of current pointer for HDR and magic number, backup this two words first */
        back_for_hdr = *(kal_uint32*)((kal_uint32)lp_ptr - CC_IRQ_MSG_PKT_HDR_LEN - CC_IRQ_MSG_MAGIC_LEN);
        back_for_magic = *(kal_uint32*)((kal_uint32)lp_ptr - CC_IRQ_MSG_MAGIC_LEN);
        lp_ptr -= (CC_IRQ_MSG_PKT_HDR_LEN + CC_IRQ_MSG_MAGIC_LEN);
        
        /* last packet */
        if (payload_remain_len <= CC_IRQ_MSG_PKT_PLD_MAX_LEN)
        {
            pkt_type = CC_IRQ_SYS_PKT_TYPE_TAIL;
            pkt_len  = payload_remain_len;
            payload_remain_len = 0;
        }
        else
        {
            pkt_type = CC_IRQ_SYS_PKT_TYPE_BODY;
            pkt_len  = CC_IRQ_MSG_PKT_PLD_MAX_LEN;
            payload_remain_len -= CC_IRQ_MSG_PKT_PLD_MAX_LEN;
        }
        pkt_len += (CC_IRQ_MSG_PKT_HDR_LEN + CC_IRQ_MSG_MAGIC_LEN);
        
        /* write HDR */
        cc_irq_msg_write_hdr((cc_irq_msg_pkt_hdr_t*)lp_ptr, pkt_type, pkt_num++, pkt_len, cur_seq);
        
        /* write magic number */
        *((kal_uint32*)lp_ptr + 1) = CC_IRQ_MSG_MAGIC_NUMBER;

#if defined(__CC_IRQ_UT__)
extern kal_uint32 cc_irq_msg_ut_pkt_enqueue(void *ptr, kal_uint32 length);
        if (!cc_irq_msg_ut_pkt_enqueue((void*)lp_ptr, pkt_len))
        {
            cc_irq_sys_tx_with_buffer((void*)lp_ptr, pkt_len);
            if (ret != CC_IRQ_SUCCESS)
                return ret;
        }
#else        
        /* send packet */
        cc_irq_sys_tx_with_buffer((void*)lp_ptr, pkt_len);
        if (ret != CC_IRQ_SUCCESS)
            return ret;

#endif
        /* restore backup for back_for_hdr and back_for_magic */
        *(kal_uint32*)((kal_uint32)lp_ptr - CC_IRQ_MSG_PKT_HDR_LEN - CC_IRQ_MSG_MAGIC_LEN) = back_for_hdr;
        *(kal_uint32*)((kal_uint32)lp_ptr - CC_IRQ_MSG_MAGIC_LEN) = back_for_magic;
        
        /* update pointer in local parameter */
        /* pkt_len includes header and magic number that lp_ptr decreased */
        /* lp_ptr no need to add length of header and magic number */
        lp_ptr = lp_ptr + pkt_len;
    }

    /* need to check whether this is NULL? */
    free_local_para(_local_para_ptr);
    
    return CC_IRQ_SUCCESS;
}

void cc_irq_msg_isr(void *pkt, kal_uint32 len)
{
    cc_irq_msg_pkt_hdr_t *hdr;
    ilm_struct           *rx_ilm;
    local_para_struct    *lp_ptr, *int_lp_ptr = NULL;
    kal_uint32           pkt_len;

    hdr = (cc_irq_msg_pkt_hdr_t*)pkt;
    ASSERT(*((kal_uint32*)pkt + 1) == CC_IRQ_MSG_MAGIC_NUMBER);
    ASSERT(hdr->op_id == CC_IRQ_SYS_OP_MSG);
    ASSERT(kal_if_hisr());

    pkt += (CC_IRQ_MSG_PKT_HDR_LEN + CC_IRQ_MSG_MAGIC_LEN);
    pkt_len = hdr->pkt_len - (CC_IRQ_MSG_PKT_HDR_LEN + CC_IRQ_MSG_MAGIC_LEN);
    
    if (hdr->type == CC_IRQ_SYS_PKT_TYPE_SINGLE || hdr->type == CC_IRQ_SYS_PKT_TYPE_HEAD)
    {
        kal_uint32 dst_mod_id;
        
        rx_ilm  = (ilm_struct *)pkt;
        pkt += sizeof(ilm_struct);
    	
        ASSERT(pkt_len >= sizeof(ilm_struct));

        lp_ptr = (local_para_struct *)pkt;        
        if (pkt_len > sizeof(ilm_struct))
        {
            int_lp_ptr = (local_para_struct *)construct_local_para(lp_ptr->msg_len, TD_RESET);

            /* copy to tx local parameter */
            kal_mem_cpy((void *)int_lp_ptr, (void *)lp_ptr, pkt_len - sizeof(ilm_struct));
        }
        /* remap destination module ID */
        dst_mod_id = CC_IRQ_MSG_RX_GET_GLB_MOD_ID(rx_ilm->dest_mod_id);
        
        /* case for a ILM and parameter are packaged into one CC IRQ packet */
        if (hdr->type == CC_IRQ_SYS_PKT_TYPE_SINGLE)
        {
#if !defined(__CC_IRQ_UT__)
            msg_send5(rx_ilm->src_mod_id, dst_mod_id, rx_ilm->sap_id, rx_ilm->msg_id, int_lp_ptr);
#else
            if (int_lp_ptr)
            {
extern void cc_irq_ut_msg_isr(kal_uint32 dst_mod, kal_uint32 sap, kal_uint32 msg, local_para_struct *lp);
                cc_irq_ut_msg_isr(dst_mod_id, rx_ilm->sap_id, rx_ilm->msg_id, int_lp_ptr);
                free_local_para(int_lp_ptr);
            }
#endif            
        }
        /* case for a series of CC IRQ packet and this one is the first */
        else
        {
            kal_uint32 i;
            
            /* allocate space */
            for (i = 0; i < CC_IRQ_MSG_RX_CONCUR_SKT_NUMBER; i++)
            {
                /* no need to consider race condition because only CC_SYS_HISR will access this variable and it will not preempt itself */
                if (cc_irq_msg_rx_socket[i].seq == CC_IRQ_MSG_RX_SKT_SEQ_NOT_USED)
                {
                    break;
                }
            }
            ASSERT(i != CC_IRQ_MSG_RX_CONCUR_SKT_NUMBER);
            ASSERT(int_lp_ptr != NULL);
            
            /* fill in socket */
            cc_irq_msg_rx_socket[i].seq         = hdr->seq;
            cc_irq_msg_rx_socket[i].total_len   = lp_ptr->msg_len;
            cc_irq_msg_rx_socket[i].rx_len      = pkt_len - sizeof(ilm_struct);
            cc_irq_msg_rx_socket[i].rx_ptr      = (kal_uint8 *)int_lp_ptr;
            cc_irq_msg_rx_socket[i].pkt_num     = 1;
            cc_irq_msg_rx_socket[i].ilm_dst_mod = dst_mod_id;
            cc_irq_msg_rx_socket[i].ilm_src_mod = rx_ilm->src_mod_id;
            cc_irq_msg_rx_socket[i].ilm_msg_id  = rx_ilm->msg_id;
            cc_irq_msg_rx_socket[i].ilm_sap_id  = rx_ilm->sap_id;
        }
    }
    else if (hdr->type == CC_IRQ_SYS_PKT_TYPE_BODY || hdr->type == CC_IRQ_SYS_PKT_TYPE_TAIL)
    {
        /* get recorded socket */
        kal_uint32 i;
        
        for (i = 0; i < CC_IRQ_MSG_RX_CONCUR_SKT_NUMBER; i++)
        {
            if (cc_irq_msg_rx_socket[i].seq == hdr->seq)
                break;
        }
        ASSERT(i != CC_IRQ_MSG_RX_CONCUR_SKT_NUMBER);
        ASSERT(cc_irq_msg_rx_socket[i].pkt_num++ == hdr->pkt_num);
        
        kal_mem_cpy((void *)cc_irq_msg_rx_socket[i].rx_ptr + cc_irq_msg_rx_socket[i].rx_len, (void *)pkt, pkt_len);
        cc_irq_msg_rx_socket[i].rx_len += pkt_len;
        
        /* check rx len and wait for next packet */
        if (hdr->type == CC_IRQ_SYS_PKT_TYPE_BODY)
        {
            ASSERT(cc_irq_msg_rx_socket[i].rx_len < cc_irq_msg_rx_socket[i].total_len);
        }
        else
        {
            ASSERT(cc_irq_msg_rx_socket[i].rx_len == cc_irq_msg_rx_socket[i].total_len);

#if !defined(__CC_IRQ_UT__)
            /* teminate this socket */
            msg_send5(cc_irq_msg_rx_socket[i].ilm_src_mod, cc_irq_msg_rx_socket[i].ilm_dst_mod, \
                      cc_irq_msg_rx_socket[i].ilm_sap_id, cc_irq_msg_rx_socket[i].ilm_msg_id, \
                      (local_para_struct *)cc_irq_msg_rx_socket[i].rx_ptr);
#else
extern void cc_irq_ut_msg_isr(kal_uint32 dst_mod, kal_uint32 sap, kal_uint32 msg, local_para_struct *lp);
            cc_irq_ut_msg_isr(cc_irq_msg_rx_socket[i].ilm_dst_mod, cc_irq_msg_rx_socket[i].ilm_sap_id, cc_irq_msg_rx_socket[i].ilm_msg_id, (local_para_struct*)cc_irq_msg_rx_socket[i].rx_ptr);
            free_local_para((local_para_struct*)cc_irq_msg_rx_socket[i].rx_ptr);
#endif
            cc_irq_msg_rx_socket[i].seq = CC_IRQ_MSG_RX_SKT_SEQ_NOT_USED;
            
        }
    }
    else
    {
        ASSERT(0);
    }
}
