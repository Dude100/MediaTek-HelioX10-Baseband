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
 * aud_ecall.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes eCall service functions
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/*==== INCLUDES =========*/

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "mw_sap.h"

#include "l1audio.h"
#include "med_global.h"
#include "med_msgid.h"
#include "med_struct.h"

#include "med_trc.h"

#ifdef __ECALL_PSAP_SUPPORT__
static void aud_ecall_psap_send_data_ind(void* data);
#endif

/*****************************************************************************
 * FUNCTION
 *  aud_ecall_send_ilm
 * DESCRIPTION
 *  This function is used to send ilm to ATCI
 * PARAMETERS
 *  msg_id              [IN]
 *  local_param_ptr     [IN]         
 *  peer_buf_ptr        [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_ecall_send_ilm(kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    module_type src_id = kal_get_active_module_id();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    msg_send6(src_id, MOD_ATCI, MED_SAP, msg_id, local_param_ptr, peer_buf_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  aud_ecall_send_monitor_cnf
 * DESCRIPTION
 *  
 * PARAMETERS 
 *  result          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_ecall_send_monitor_cnf(eCall_Modem_Status result, kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_emsd_monitor_cnf_struct *msg_p = (media_aud_emsd_monitor_cnf_struct*)
        construct_local_para(sizeof(media_aud_emsd_monitor_cnf_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(result == eCALL_OPERATION_SUCCESS)
    {
        msg_p->result = KAL_TRUE;
        msg_p->cause_present = KAL_FALSE;
    }
    else
    {
        msg_p->result = KAL_FALSE;
        msg_p->cause_present = KAL_TRUE;
        msg_p->cause = (kal_uint8)result;
    }

    msg_p->src_id = src_id;

    aud_ecall_send_ilm(MSG_ID_MEDIA_AUD_EMSD_MONITOR_CNF, (void*)msg_p, NULL);

}

/*****************************************************************************
 * FUNCTION
 *  aud_ecall_send_set_msd_cnf
 * DESCRIPTION
 * 
 * PARAMETERS 
 *  result          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_ecall_send_set_msd_cnf(eCall_Modem_Status result, kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_emsd_set_cnf_struct *msg_p = (media_aud_emsd_set_cnf_struct*)
        construct_local_para(sizeof(media_aud_emsd_set_cnf_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(result == eCALL_OPERATION_SUCCESS)
    {
        msg_p->result = KAL_TRUE;
        msg_p->cause_present = KAL_FALSE;
    }
    else
    {
        msg_p->result = KAL_FALSE;
        msg_p->cause_present = KAL_TRUE;
        msg_p->cause = (kal_uint8)result;
    }

    msg_p->src_id = src_id;

    aud_ecall_send_ilm(MSG_ID_MEDIA_AUD_EMSD_SET_CNF, (void*)msg_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_ecall_send_push_cnf
 * DESCRIPTION
 * 
 * PARAMETERS 
 *  result          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_ecall_send_push_cnf(eCall_Modem_Status result, kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_emsd_push_cnf_struct *msg_p = (media_aud_emsd_push_cnf_struct*)
        construct_local_para(sizeof(media_aud_emsd_push_cnf_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(result == eCALL_OPERATION_SUCCESS)
    {
        msg_p->result = KAL_TRUE;
        msg_p->cause_present = KAL_FALSE;
    }
    else
    {
        msg_p->result = KAL_FALSE;
        msg_p->cause_present = KAL_TRUE;
        msg_p->cause = (kal_uint8)result;
    }

    msg_p->src_id = src_id;

    aud_ecall_send_ilm(MSG_ID_MEDIA_AUD_EMSD_PUSH_CNF, (void*)msg_p, NULL);

}

/*****************************************************************************
 * FUNCTION
 *  aud_ecall_send_pull_ind
 * DESCRIPTION
 * 
 * PARAMETERS 
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_ecall_send_pull_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_emsd_pull_ind_struct *msg_p = (media_aud_emsd_pull_ind_struct*)
        construct_local_para(sizeof(media_aud_emsd_pull_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    aud_ecall_send_ilm(MSG_ID_MEDIA_AUD_EMSD_PULL_IND, (void*)msg_p, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  aud_ecall_send_sync_ind
 * DESCRIPTION
 * 
 * PARAMETERS 
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_ecall_send_sync_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_emsd_sync_ind_struct *msg_p = (media_aud_emsd_sync_ind_struct*)
        construct_local_para(sizeof(media_aud_emsd_sync_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    aud_ecall_send_ilm(MSG_ID_MEDIA_AUD_EMSD_SYNC_IND, (void*)msg_p, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  aud_ecall_send_lack_ind
 * DESCRIPTION
 * 
 * PARAMETERS 
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_ecall_send_lack_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_emsd_lack_ind_struct *msg_p = (media_aud_emsd_lack_ind_struct*)
        construct_local_para(sizeof(media_aud_emsd_lack_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    aud_ecall_send_ilm(MSG_ID_MEDIA_AUD_EMSD_LACK_IND, (void*)msg_p, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  aud_ecall_send_hack_ind
 * DESCRIPTION
 * 
 * PARAMETERS 
 *  event
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_ecall_send_hack_ind(eCall_Modem_Event event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_emsd_hack_ind_struct *msg_p = (media_aud_emsd_hack_ind_struct*)
        construct_local_para(sizeof(media_aud_emsd_hack_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(event == eCALL_EVENT_RECV_HL_ACK_CORRECT)
    {
        msg_p->result = KAL_TRUE;
        msg_p->cause_present = KAL_FALSE;
    }
    else
    {
        msg_p->result = KAL_FALSE;
        msg_p->cause_present = KAL_TRUE;
        msg_p->cause = (kal_uint8)event;
    }

    aud_ecall_send_ilm(MSG_ID_MEDIA_AUD_EMSD_HACK_IND, (void*)msg_p, NULL);

}

/*****************************************************************************
 * FUNCTION
 *  aud_ecall_event_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event       [IN]        
 *  param       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_ecall_event_callback(eCall_Modem_Event event, void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(MED_NOT_PRESENT)
    ECALL_FUNC_ENTRY(AUD_ECALL_EVENT_CALLBACK)
    ECALL_VALUE_TRACE(event)
#endif

    switch(event)
    {
        case eCALL_EVENT_RECV_START:
        {
            aud_ecall_send_pull_ind();
            break;
        }

        case eCALL_EVENT_RECV_NACK:
        {
            aud_ecall_send_sync_ind();
            break;
        }

        case eCALL_EVENT_RECV_LL_ACK:
        {
            aud_ecall_send_lack_ind();
            break;
        }

        case eCALL_EVENT_RECV_HL_ACK_CORRECT:
        case eCALL_EVENT_RECV_HL_ACK_MISMATCH:
        {
            aud_ecall_send_hack_ind(event);
            break;
        }

    #ifdef __ECALL_PSAP_SUPPORT__
        case eCALL_EVENT_PSAP_RECV_MSD:
        {
            aud_ecall_psap_send_data_ind(param);
            break;
        }
    #endif
        default:
            break;

    }

}



/*****************************************************************************
 * FUNCTION
 *  aud_ecall_monitor_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_ecall_monitor_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_emsd_monitor_req_struct *req = (media_aud_emsd_monitor_req_struct*) ilm_ptr->local_para_ptr;
    eCall_Modem_Status result;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(MED_NOT_PRESENT)
    ECALL_FUNC_ENTRY(AUD_ECALL_MONITOR_REQ_HDLR)
#endif

    if(req->monitor)
    {
        /*Open*/
        result = eCall_IVS_Open(aud_ecall_event_callback);
    }
    else
    {
        /*Close*/
        result = eCall_IVS_Close();
    }

    aud_ecall_send_monitor_cnf(result,req->src_id);

}

/*****************************************************************************
 * FUNCTION
 *  aud_ecall_put_msd_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_ecall_set_msd_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_emsd_set_req_struct *req = (media_aud_emsd_set_req_struct*) ilm_ptr->local_para_ptr;
    eCall_Modem_Status result;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(MED_NOT_PRESENT)
    ECALL_FUNC_ENTRY(AUD_ECALL_SET_MSD_REQ_HDLR)
#endif

    result = eCall_IVS_PutMSD(req->data,EMSD_DATA_LEN);

    aud_ecall_send_set_msd_cnf(result,req->src_id);

}


/*****************************************************************************
 * FUNCTION
 *  aud_ecall_put_msd_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_ecall_push_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_emsd_push_req_struct *req = (media_aud_emsd_push_req_struct*) ilm_ptr->local_para_ptr;
    eCall_Modem_Status result;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(MED_NOT_PRESENT)
    ECALL_FUNC_ENTRY(AUD_ECALL_PUSH_REQ_HDLR)
#endif

    result = eCall_IVS_SendStart();

    aud_ecall_send_push_cnf(result,req->src_id);

}

#ifdef __ECALL_PSAP_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_ecall_psap_send_data_ind
 * DESCRIPTION
 * 
 * PARAMETERS 
 *  event
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_ecall_psap_send_data_ind(void* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_emsd_psap_data_ind_struct *msg_p = (media_aud_emsd_psap_data_ind_struct*)
        construct_local_para(sizeof(media_aud_emsd_psap_data_ind_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memcpy(msg_p->data, data, EMSD_DATA_LEN*sizeof(kal_uint8));

    aud_ecall_send_ilm(MSG_ID_MEDIA_AUD_EMSD_PSAP_DATA_IND, (void*)msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_ecall_psap_send_monitor_cnf
 * DESCRIPTION
 *  
 * PARAMETERS 
 *  result          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_ecall_psap_send_monitor_cnf(eCall_Modem_Status result, kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_emsd_psap_monitor_cnf_struct *msg_p = (media_aud_emsd_psap_monitor_cnf_struct*)
        construct_local_para(sizeof(media_aud_emsd_psap_monitor_cnf_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(result == eCALL_OPERATION_SUCCESS)
    {
        msg_p->result = KAL_TRUE;
        msg_p->cause_present = KAL_FALSE;
    }
    else
    {
        msg_p->result = KAL_FALSE;
        msg_p->cause_present = KAL_TRUE;
        msg_p->cause = (kal_uint8)result;
    }

    msg_p->src_id = src_id;

    aud_ecall_send_ilm(MSG_ID_MEDIA_AUD_EMSD_PSAP_MONITOR_CNF, (void*)msg_p, NULL);

}

/*****************************************************************************
 * FUNCTION
 *  aud_ecall_psap_monitor_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_ecall_psap_monitor_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_emsd_psap_monitor_req_struct *req = (media_aud_emsd_psap_monitor_req_struct*) ilm_ptr->local_para_ptr;
    eCall_Modem_Status result;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(MED_NOT_PRESENT)
    ECALL_FUNC_ENTRY(AUD_ECALL_MONITOR_REQ_HDLR)
#endif

    if(req->monitor)
    {
        /*Open*/
        result = eCall_PSAP_Open(aud_ecall_event_callback);
        
    }
    else
    {
        /*Close*/
        result = eCall_PSAP_Close();
    }

    aud_ecall_psap_send_monitor_cnf(result,req->src_id);

}

/*****************************************************************************
 * FUNCTION
 *  aud_ecall_psap_send_pull_cnf
 * DESCRIPTION
 * 
 * PARAMETERS 
 *  result          [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_ecall_psap_send_pull_cnf(eCall_Modem_Status result, kal_uint8 src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_emsd_psap_pull_cnf_struct *msg_p = (media_aud_emsd_psap_pull_cnf_struct*)
        construct_local_para(sizeof(media_aud_emsd_psap_pull_cnf_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(result == eCALL_OPERATION_SUCCESS)
    {
        msg_p->result = KAL_TRUE;
        msg_p->cause_present = KAL_FALSE;
    }
    else
    {
        msg_p->result = KAL_FALSE;
        msg_p->cause_present = KAL_TRUE;
        msg_p->cause = (kal_uint8)result;
    }

    msg_p->src_id = src_id;

    aud_ecall_send_ilm(MSG_ID_MEDIA_AUD_EMSD_PSAP_PULL_CNF, (void*)msg_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_ecall_psap_pull_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void aud_ecall_psap_pull_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_emsd_psap_pull_req_struct *req = (media_aud_emsd_psap_pull_req_struct*) ilm_ptr->local_para_ptr;
    eCall_Modem_Status result;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(MED_NOT_PRESENT)
    ECALL_FUNC_ENTRY(AUD_ECALL_PSAP_PULL_REQ_HDLR)
#endif

    result = eCall_PSAP_SendStart();

    aud_ecall_psap_send_pull_cnf(result,req->src_id);
}

#endif /* __ECALL_PSAP_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  aud_ctm_main
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_ecall_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_MEDIA_AUD_EMSD_MONITOR_REQ:
            aud_ecall_monitor_req_hdlr(ilm_ptr);
            break;

        case MSG_ID_MEDIA_AUD_EMSD_SET_REQ:
            aud_ecall_set_msd_req_hdlr(ilm_ptr);
            break;

        case MSG_ID_MEDIA_AUD_EMSD_PUSH_REQ:
            aud_ecall_push_req_hdlr(ilm_ptr);
            break;

    #ifdef __ECALL_PSAP_SUPPORT__
        case MSG_ID_MEDIA_AUD_EMSD_PSAP_MONITOR_REQ:
            aud_ecall_psap_monitor_req_hdlr(ilm_ptr);
            break;

        case MSG_ID_MEDIA_AUD_EMSD_PSAP_PULL_REQ:
            aud_ecall_psap_pull_req_hdlr(ilm_ptr);
            break;

    #endif /*__ECALL_PSAP_SUPPORT__*/
        default:
            ASSERT(0);
    }
}

