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
 * aud_ilm.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes send-ilm related funcions of audio manager task.
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES ===========*/

/* system includes */ 
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "mw_sap.h"
#include "svc_sap.h"
#include "drv_sap.h"
#include "med_msgid.h"
#include "nvram_msgid.h"

/* global includes */
#include "l1audio.h"
#include "nvram_struct.h"
#include "audio_nvram_def.h"
 
/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_context.h"
#include "aud_main.h"


#include "string.h"
 
/*****************************************************************************
 * FUNCTION
 *  aud_send_ilm
 * DESCRIPTION
 *  This function is used to send ilm.
 * PARAMETERS
 *  dest_id             [IN]        
 *  msg_id              [IN]        
 *  local_param_ptr     [?]         
 *  peer_buf_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_ilm(module_type dest_id, kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type src_id;
    sap_type sap_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Check destination module ID */
    if (dest_id == MOD_NIL)
    {
        return;
    }

    /* Get source module ID */
    if (kal_if_hisr())
    {
        src_id = MOD_VISUAL_HISR;//MOD_VISUAL_HISR;//MOD_TIMER_HISR or  MOD_GPT_TIMER

       // return;
    }
    else
    {
        src_id = kal_get_active_module_id();
    }

    switch (dest_id)
    {
        case MOD_MED:
            sap_id = MED_SAP;
            break;
        case MOD_UEM:
            sap_id = MED_SAP;
            break;
        case MOD_NVRAM:
            sap_id = PS_NVRAM_SAP;
            break;
        default:
            sap_id = MED_SAP;
            break;
    }
    
    msg_send6(src_id,dest_id,sap_id,msg_id,(local_para_struct*)local_param_ptr,(peer_buff_struct*)peer_buf_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_msg_to_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_name        [IN]        
 *  ef_id           [IN]        
 *  data_ptr        [?]         
 *  length          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_msg_to_nvram(msg_type msg_name, kal_uint16 ef_id, void *data_ptr, kal_uint16 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    peer_buff_struct *data_stream;
    local_para_struct *parm_stream;
    kal_uint16 pdu_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_name)
    {
        case MSG_ID_NVRAM_WRITE_REQ:
            switch (ef_id)
            {
                case NVRAM_EF_CUST_ACOUSTIC_DATA_LID:
                case NVRAM_EF_AUDIO_PARAM_LID:
                case NVRAM_EF_AUDIO_DC_CALIBRATION_LID:
            #ifdef __AMRWB_LINK_SUPPORT__
                case NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID:
                case NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_LID:
                case NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_LID:
            #endif /* __AMRWB_LINK_SUPPORT__ */
                    parm_stream = construct_local_para(sizeof(nvram_write_req_struct), TD_CTRL);
                    data_stream = construct_peer_buff(length, 0, 0, TD_CTRL);

                    ((nvram_write_req_struct*) parm_stream)->file_idx = (kal_uint16) ef_id;
                    ((nvram_write_req_struct*) parm_stream)->para = 1;
                    ((nvram_write_req_struct*) parm_stream)->access_id = 0;

                    pdu_len = length;
                    kal_mem_cpy(get_peer_buff_pdu(data_stream, &pdu_len), data_ptr, length);

                    aud_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_WRITE_REQ, parm_stream, data_stream);
                    break;
                default:
                    /* error write */
                    break;
            }
            break;
        case MSG_ID_NVRAM_READ_REQ:
            switch (ef_id)
            {
                case NVRAM_EF_CUST_ACOUSTIC_DATA_LID:
                case NVRAM_EF_AUDIO_PARAM_LID:
                case NVRAM_EF_AUDIO_DC_CALIBRATION_LID:
            #ifdef __GAIN_TABLE_SUPPORT__
                case NVRAM_EF_AUDIO_GAIN_TABLE_LID:
            #endif /* __GAIN_TABLE_SUPPORT__ */
            #ifdef __SPEECH_MODE_TABLE_SUPPORT__
                case NVRAM_EF_AUDIO_SPEECH_MODE_TABLE_LID:
            #endif /* __SPEECH_MODE_TABLE_SUPPORT__ */
            #ifdef __AMRWB_LINK_SUPPORT__
                case NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID:
                case NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_LID:
                case NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_LID:
            #endif /* __AMRWB_LINK_SUPPORT__ */
            #ifdef __DUAL_MIC_SUPPORT__
                case NVRAM_EF_AUDIO_DUAL_MIC_PARAM_LID:
            #endif
                    parm_stream = construct_local_para(sizeof(nvram_read_req_struct), TD_CTRL);

                    ((nvram_read_req_struct*) parm_stream)->file_idx = (kal_uint16) ef_id;
                    ((nvram_read_req_struct*) parm_stream)->para = 1;

                    aud_send_ilm(MOD_NVRAM, MSG_ID_NVRAM_READ_REQ, parm_stream, NULL);
                    break;
                default:
                    /* error read */
                    break;
            }
            break;
        default:
            break;
    }   /* End Switch */

    return;
}


/*****************************************************************************
 * FUNCTION
 *  aud_send_startup_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_startup_cnf(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    med_startup_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_p = (med_startup_cnf_struct*) construct_local_para(sizeof(med_startup_cnf_struct), TD_CTRL);

    /* send confirm message to L4 */
    cnf_p->result = result;

    aud_send_ilm(aud_context_p->src_mod, MSG_ID_MED_STARTUP_CNF, cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_send_set_audio_profile_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_set_audio_profile_cnf(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_audio_profile_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_p = (media_aud_set_audio_profile_cnf_struct*)
        construct_local_para(sizeof(media_aud_set_audio_profile_cnf_struct), TD_CTRL);

    /* send confirm message to L4 */
    cnf_p->src_id = aud_context_p->src_id;
    if(result == 0) /* MED_RES_OK */
    {
        cnf_p->result = KAL_TRUE;
    }
    else
    {
        cnf_p->result = KAL_FALSE;
    }
    cnf_p->cause = result;

    aud_send_ilm(aud_context_p->src_mod, MSG_ID_MEDIA_AUD_SET_AUDIO_PROFILE_CNF, cnf_p, NULL);

}

void aud_send_in_proc_call_req(
        module_type src_mod_id,
        media_in_proc_call_type func,
        kal_uint32 func_arg1,
        void *func_arg2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_in_proc_call_req_struct *msg_p = (media_in_proc_call_req_struct*)
        construct_local_para(sizeof(media_in_proc_call_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->func = func;
    msg_p->func_arg1 = func_arg1;
    msg_p->func_arg2 = func_arg2;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_IN_PROC_CALL_REQ, msg_p);
}

#ifdef __AMRWB_LINK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_send_set_audio_wb_input_fir_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_set_audio_wb_input_fir_cnf(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_audio_wb_input_fir_param_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_p = (media_aud_set_audio_wb_input_fir_param_cnf_struct*)
        construct_local_para(sizeof(media_aud_set_audio_wb_input_fir_param_cnf_struct), TD_CTRL);

    /* send confirm message to L4 */
    cnf_p->src_id = aud_context_p->src_id;

    if(result == 0) /* MED_RES_OK */
    {
        cnf_p->result = KAL_TRUE;
    }
    else
    {
        cnf_p->result = KAL_FALSE;
    }
    cnf_p->cause = result;

    aud_send_ilm(aud_context_p->src_mod, MSG_ID_MEDIA_AUD_SET_AUDIO_WB_INPUT_FIR_PARAM_CNF, cnf_p, NULL);

}

/*****************************************************************************
 * FUNCTION
 *  aud_send_set_audio_wb_output_fir_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input       [IN]
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_set_audio_wb_output_fir_cnf(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    media_aud_set_audio_wb_output_fir_param_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_p = (media_aud_set_audio_wb_output_fir_param_cnf_struct*)
        construct_local_para(sizeof(media_aud_set_audio_wb_output_fir_param_cnf_struct), TD_CTRL);

    /* send confirm message to L4 */
    cnf_p->src_id = aud_context_p->src_id;

    if(result == 0) /* MED_RES_OK */
    {
        cnf_p->result = KAL_TRUE;
    }
    else
    {
        cnf_p->result = KAL_FALSE;
    }
    cnf_p->cause = result;

    aud_send_ilm(aud_context_p->src_mod, MSG_ID_MEDIA_AUD_SET_AUDIO_WB_OUTPUT_FIR_PARAM_CNF, cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_send_set_audio_wb_mode_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_set_audio_wb_mode_cnf(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_audio_wb_mode_param_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_p = (media_aud_set_audio_wb_mode_param_cnf_struct*)
        construct_local_para(sizeof(media_aud_set_audio_wb_mode_param_cnf_struct), TD_CTRL);

    /* send confirm message to L4 */
    cnf_p->src_id = aud_context_p->src_id;

    if(result == 0) /* MED_RES_OK */
    {
        cnf_p->result = KAL_TRUE;
    }
    else
    {
        cnf_p->result = KAL_FALSE;
    }
    cnf_p->cause = result;

    aud_send_ilm(aud_context_p->src_mod, MSG_ID_MEDIA_AUD_SET_AUDIO_WB_MODE_PARAM_CNF, cnf_p, NULL);

}

#endif /*__AMRWB_LINK_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  aud_send_set_audio_param_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_set_audio_param_cnf(kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_audio_param_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnf_p = (media_aud_set_audio_param_cnf_struct*)
        construct_local_para(sizeof(media_aud_set_audio_param_cnf_struct), TD_CTRL);

    /* send confirm message to L4 */
    cnf_p->src_id = aud_context_p->src_id;
    if(result == 0) /* MED_RES_OK */
    {
        cnf_p->result = KAL_TRUE;
    }
    else
    {
        cnf_p->result = KAL_FALSE;
    }
    cnf_p->cause = result;

    aud_send_ilm(aud_context_p->src_mod, MSG_ID_MEDIA_AUD_SET_AUDIO_PARAM_CNF, cnf_p, NULL);

}

#else /* MED_NOT_PRESENT */ 

/*==== INCLUDES ===========*/

/* system includes */ 
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "mw_sap.h"
#include "svc_sap.h"
#include "drv_sap.h"
#include "med_msgid.h"
#include "nvram_msgid.h"

/* global includes */
#include "l1audio.h"
#include "nvram_struct.h"
#include "audio_nvram_def.h"
 
/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_context.h"
#include "aud_main.h"


#include "string.h"
 
/*****************************************************************************
 * FUNCTION
 *  aud_send_ilm
 * DESCRIPTION
 *  This function is used to send ilm.
 * PARAMETERS
 *  dest_id             [IN]        
 *  msg_id              [IN]        
 *  local_param_ptr     [?]         
 *  peer_buf_ptr        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void aud_send_ilm(module_type dest_id, kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type src_id;
    sap_type sap_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Check destination module ID */
    if (dest_id == MOD_NIL)
    {
        return;
    }

    /* Get source module ID */
    if (kal_if_hisr())
    {
        src_id = MOD_VISUAL_HISR;//MOD_VISUAL_HISR;//MOD_TIMER_HISR �٬O  MOD_GPT_TIMER

       // return;
    }
    else
    {
        src_id = kal_get_active_module_id();
    }

    switch (dest_id)
    {
        case MOD_MED:
            sap_id = MED_SAP;
            break;
        case MOD_UEM:
            sap_id = MED_SAP;
            break;
        case MOD_NVRAM:
            sap_id = PS_NVRAM_SAP;
            break;
        default:
            sap_id = MED_SAP;
            break;
    }
    
    msg_send6(src_id,dest_id,sap_id,msg_id,(local_para_struct*)local_param_ptr,(peer_buff_struct*)peer_buf_ptr);
}

void aud_send_in_proc_call_req(
        module_type src_mod_id,
        media_in_proc_call_type func,
        kal_uint32 func_arg1,
        void *func_arg2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_in_proc_call_req_struct *msg_p = (media_in_proc_call_req_struct*)
        construct_local_para(sizeof(media_in_proc_call_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p->func = func;
    msg_p->func_arg1 = func_arg1;
    msg_p->func_arg2 = func_arg2;

    aud_send_msg_to_med(src_mod_id, (kal_uint16) MSG_ID_MEDIA_IN_PROC_CALL_REQ, msg_p);
}


#endif /* MED_NOT_PRESENT */ 



