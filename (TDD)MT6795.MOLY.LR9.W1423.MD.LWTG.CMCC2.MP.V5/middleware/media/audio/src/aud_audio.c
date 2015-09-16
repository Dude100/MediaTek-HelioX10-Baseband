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
 * aud_audio.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes audio functions of audio manager task.
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/******************************************************************
 * MODULE
 *    AUD_AUDIO
 * DESCRIPTION
 *    This module defines the audio related function for Audio Manager.
 *  
 ******************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES =======*/

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "kal_trace.h"
#include "med_msgid.h"
#include "nvram_msgid.h"

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
#include "custom_equipment.h"
#include "audio_nvram_def.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"
#include "med_utility.h"
#include "aud_common_config.h"


#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

static kal_uint16 g_aud_mute_digital_gain_app;


/*****************************************************************************
 * FUNCTION
 *  aud_audio_init
 * DESCRIPTION
 *  This function is used to init audio module for audio manager.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_audio_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->audio_mode = AUD_MODE_NORMAL;
    aud_context_p->identifier = 0;
    aud_context_p->melody_output_device = AUDIO_DEVICE_SPEAKER2;
    aud_context_p->audio_mute = KAL_FALSE;
    aud_context_p->melody_max_volume_level = 16; /* 16-level */
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  aud_set_audio_mode_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_audio_mode_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_audio_mode_cnf_struct *cnf_p = NULL;

    media_aud_set_audio_mode_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_SET_AUDIO_MODE_REQ_HDLR);

    req_p = (media_aud_set_audio_mode_req_struct*) ilm_ptr->local_para_ptr;

    aud_context_p->audio_mode = req_p->mode;
    aud_set_aud_path_volume(req_p->mode);

    cnf_p = (media_aud_set_audio_mode_cnf_struct*) construct_local_para(sizeof(media_aud_set_audio_mode_cnf_struct), TD_CTRL);

    cnf_p->src_id = req_p->src_id;
    cnf_p->result = KAL_TRUE;
    cnf_p->cause = MED_RES_OK;

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_SET_AUDIO_MODE_CNF, cnf_p, NULL);

}

/*****************************************************************************
 * FUNCTION
 *  aud_get_audio_profile_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_audio_profile_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_audio_profile_req_struct *req_p;
    media_aud_get_audio_profile_cnf_struct *cnf_p = NULL;
    kal_uint8 mode;
    audio_profile_struct *profile_p;
    custom_acoustic_struct *data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_GET_AUDIO_PROFILE_REQ_HDLR);
    req_p = (media_aud_get_audio_profile_req_struct*) ilm_ptr->local_para_ptr;

    cnf_p = (media_aud_get_audio_profile_cnf_struct*)
        construct_local_para(sizeof(media_aud_get_audio_profile_cnf_struct), TD_CTRL);

    cnf_p->src_id = req_p->src_id;
    mode = req_p->mode;
    profile_p = &cnf_p->audio_profile;
    data_p = &aud_context_p->acoustic_data;
    profile_p->mode = mode;

    if (mode < MAX_VOL_CATE)
    {
        kal_mem_cpy(
            profile_p->speech,
            data_p->volume_gain[mode][AUD_VOLUME_SPH],
            sizeof(data_p->volume_gain[mode][AUD_VOLUME_SPH]));
        kal_mem_cpy(
            profile_p->keytone,
            data_p->volume_gain[mode][AUD_VOLUME_KEY],
            sizeof(data_p->volume_gain[mode][AUD_VOLUME_KEY]));
        kal_mem_cpy(
            profile_p->melody,
            data_p->volume_gain[mode][AUD_VOLUME_MEDIA],
            sizeof(data_p->volume_gain[mode][AUD_VOLUME_MEDIA]));
        kal_mem_cpy(
            profile_p->sound,
            data_p->volume_gain[mode][AUD_VOLUME_FMR],
            sizeof(data_p->volume_gain[mode][AUD_VOLUME_FMR]));
        kal_mem_cpy(
            profile_p->mic,
            data_p->volume_gain[mode][AUD_VOLUME_MIC],
            sizeof(data_p->volume_gain[mode][AUD_VOLUME_MIC]));
        profile_p->sidetone = data_p->volume_gain[mode][AUD_VOLUME_SID][data_p->volume[mode][AUD_VOLUME_SID]];
    #ifdef __16_LEVEL_AUDIO_VOLUME__
        /* get 16-level audio volume settings */
        profile_p->max_melody_volume_gain = data_p->max_melody_volume_gain[mode];
        profile_p->melody_volume_gain_step = data_p->melody_volume_gain_step[mode];
    #endif /* __16_LEVEL_AUDIO_VOLUME__ */
        cnf_p->result = KAL_TRUE;
    }
    else
    {
        cnf_p->result = KAL_FALSE;
    }

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_GET_AUDIO_PROFILE_CNF, cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_set_audio_profile_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_audio_profile_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    media_aud_set_audio_profile_req_struct *req_p = NULL;
    audio_profile_struct *profile_p;
    custom_acoustic_struct *data_p;
    kal_uint8 mode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_set_audio_profile_req_struct*) ilm_ptr->local_para_ptr;

    AUD_FUNC_ENTRY(AUD_SET_AUDIO_PROFILE_REQ_HDLR);

    if (req_p)
    {
        aud_context_p->src_id = req_p->src_id;
        profile_p = &req_p->audio_profile;
        data_p = &aud_context_p->acoustic_data;
        mode = profile_p->mode;

        if (mode < MAX_VOL_CATE)
        {
            kal_mem_cpy(
                data_p->volume_gain[mode][AUD_VOLUME_SPH],
                profile_p->speech,
                sizeof(data_p->volume_gain[mode][AUD_VOLUME_SPH]));
            kal_mem_cpy(
                data_p->volume_gain[mode][AUD_VOLUME_KEY],
                profile_p->keytone,
                sizeof(data_p->volume_gain[mode][AUD_VOLUME_KEY]));
            kal_mem_cpy(
                data_p->volume_gain[mode][AUD_VOLUME_MEDIA],
                profile_p->melody,
                sizeof(data_p->volume_gain[mode][AUD_VOLUME_MEDIA]));
            kal_mem_cpy(
                data_p->volume_gain[mode][AUD_VOLUME_FMR],
                profile_p->sound,
                sizeof(data_p->volume_gain[mode][AUD_VOLUME_FMR]));
            kal_mem_cpy(
                data_p->volume_gain[mode][AUD_VOLUME_MIC],
                profile_p->mic,
                sizeof(data_p->volume_gain[mode][AUD_VOLUME_MIC]));
            kal_mem_set(
                data_p->volume_gain[mode][AUD_VOLUME_SID],
                profile_p->sidetone,
                sizeof(data_p->volume_gain[mode][AUD_VOLUME_SID]));
    #ifdef __16_LEVEL_AUDIO_VOLUME__
            /* set 16-level audio volume settings */
            data_p->max_melody_volume_gain[mode] = profile_p->max_melody_volume_gain;
            data_p->melody_volume_gain_step[mode] = profile_p->melody_volume_gain_step;
    #endif /* __16_LEVEL_AUDIO_VOLUME__ */
            aud_set_aud_path_volume(aud_context_p->audio_mode);
        }

        if (req_p->update_nvram)
        {
            if(med_context_p->nvram_state == MED_POWERON_READING_NVRAM_FINISH)
            {
                aud_context_p->src_mod = ilm_ptr->src_mod_id;
                aud_send_msg_to_nvram(
                    MSG_ID_NVRAM_WRITE_REQ,
                    NVRAM_EF_CUST_ACOUSTIC_DATA_LID,
                    &(aud_context_p->acoustic_data),
                    sizeof(custom_acoustic_struct));
            }
            else
            {
                aud_send_set_audio_profile_cnf(MED_RES_FAIL);
            }
        }
        else
        {
            aud_send_set_audio_profile_cnf(MED_RES_OK);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_get_audio_param_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_audio_param_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_audio_param_req_struct *req_p;
    media_aud_get_audio_param_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_GET_AUDIO_PARAM_REQ_HDLR);

    req_p = (media_aud_get_audio_param_req_struct*) ilm_ptr->local_para_ptr;

    /* MED start finish, send message to get value from NVRAM */
    if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM_FINISH)
    {
        aud_context_p->src_id = req_p->src_id;
        aud_context_p->src_mod = ilm_ptr->src_mod_id;
        aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_AUDIO_PARAM_LID, 0, 0);
    }
    else
    {
        cnf_p = (media_aud_get_audio_param_cnf_struct*)
            construct_local_para(sizeof(media_aud_get_audio_param_cnf_struct), TD_CTRL);

        cnf_p->src_id = req_p->src_id;
        cnf_p->result = KAL_FALSE;

        aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_GET_AUDIO_PARAM_CNF, cnf_p, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  aud_get_audio_param_from_nvram_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_audio_param_from_nvram_rsp(void* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_audio_param_cnf_struct *cnf_p;
    audio_param_struct *nvram_param_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_param_p = (audio_param_struct*)param;

    cnf_p = (media_aud_get_audio_param_cnf_struct*)
        construct_local_para(sizeof(media_aud_get_audio_param_cnf_struct), TD_CTRL);

    cnf_p->src_id = aud_context_p->src_id;
    cnf_p->result = KAL_TRUE;
    kal_mem_cpy(&cnf_p->audio_param, nvram_param_p, sizeof(audio_param_struct));

    aud_send_ilm(aud_context_p->src_mod, MSG_ID_MEDIA_AUD_GET_AUDIO_PARAM_CNF, cnf_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  aud_set_audio_param_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_audio_param_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    media_aud_set_audio_param_req_struct *req_p = NULL;
    audio_param_struct *param_p;
    kal_uint8 *nvram_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_SET_AUDIO_PARAM_REQ_HDLR);

    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    req_p = (media_aud_set_audio_param_req_struct*) ilm_ptr->local_para_ptr;

    if (req_p)
    {
        param_p = &req_p->audio_param;

        /*set to L1SP directly*/
        L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_PARAM,(kal_uint8*)param_p, sizeof(audio_param_struct));

        /* Apply change to driver */
        L1SP_LoadCommonSpeechPara(param_p->speech_common_para);
        Media_SetMelodyFilter(MELODY_FIR_COEFF_NUM, param_p->Melody_FIR_Coeff_Tbl);
        aud_set_aud_path_volume(aud_context_p->audio_mode);

        /* Write to NVRAM */
        if(req_p->update_nvram)
        {
            if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM_FINISH)
            {
                nvram_data = (kal_uint8*)get_ctrl_buffer(sizeof(audio_param_struct));

                if (nvram_data)
                {
                    kal_mem_cpy(nvram_data, param_p, sizeof(audio_param_struct));
                    aud_send_msg_to_nvram(MSG_ID_NVRAM_WRITE_REQ, NVRAM_EF_AUDIO_PARAM_LID, nvram_data, sizeof(audio_param_struct));
                    free_ctrl_buffer((void*)nvram_data);
                }
                else
                {
                    aud_send_set_audio_param_cnf(MED_RES_FAIL);
                }
            }
            else
            {
                aud_send_set_audio_param_cnf(MED_RES_FAIL);
            }
        }
        else
        {
            aud_send_set_audio_param_cnf(MED_RES_OK);
        }
    }
}

#ifdef __AMRWB_LINK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  aud_get_audio_wb_input_fir_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_audio_wb_input_fir_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    media_aud_get_audio_wb_input_fir_param_req_struct *req_p = NULL;
    media_aud_get_audio_wb_input_fir_param_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(AUD_GET_AUDIO_WB_PARAM_REQ_HDLR,0);
    req_p = (media_aud_get_audio_wb_input_fir_param_req_struct*) ilm_ptr->local_para_ptr;

    cnf_p = (media_aud_get_audio_wb_input_fir_param_cnf_struct*)
        construct_local_para(sizeof(media_aud_get_audio_wb_input_fir_param_cnf_struct), TD_CTRL);

    cnf_p->src_id = req_p->src_id;

    cnf_p->result = KAL_TRUE;

    L1SP_GetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_WB_SPEECH_INPUT_FIR,(void*) &(cnf_p->fir_param),sizeof(audio_wb_speech_fir_struct));

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_GET_AUDIO_WB_INPUT_FIR_PARAM_CNF, cnf_p, NULL);

}

/*****************************************************************************
 * FUNCTION
 *  aud_get_audio_wb_output_fir_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_audio_wb_output_fir_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_audio_wb_output_fir_param_req_struct *req_p = NULL;
    media_aud_get_audio_wb_output_fir_param_cnf_struct *cnf_p = NULL;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(AUD_GET_AUDIO_WB_PARAM_REQ_HDLR,1);
    req_p = (media_aud_get_audio_wb_output_fir_param_req_struct*) ilm_ptr->local_para_ptr;

    cnf_p = (media_aud_get_audio_wb_output_fir_param_cnf_struct*)
        construct_local_para(sizeof(media_aud_get_audio_wb_output_fir_param_cnf_struct), TD_CTRL);

    cnf_p->src_id = req_p->src_id;

    cnf_p->result = KAL_TRUE;

    L1SP_GetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_WB_SPEECH_OUTPUT_FIR,(void*) &(cnf_p->fir_param),sizeof(audio_wb_speech_fir_struct));

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_GET_AUDIO_WB_OUTPUT_FIR_PARAM_CNF, cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_get_audio_wb_mode_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_get_audio_wb_mode_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_audio_wb_mode_param_req_struct *req_p = NULL;
    media_aud_get_audio_wb_mode_param_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY1(AUD_GET_AUDIO_WB_PARAM_REQ_HDLR,2);
    
    req_p = (media_aud_get_audio_wb_mode_param_req_struct*) ilm_ptr->local_para_ptr;

    cnf_p = (media_aud_get_audio_wb_mode_param_cnf_struct*)
        construct_local_para(sizeof(media_aud_get_audio_wb_mode_param_cnf_struct), TD_CTRL);

    cnf_p->src_id = req_p->src_id;

    cnf_p->result = KAL_TRUE;

    L1SP_GetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_WB_SPEECH_MODE_PARAM,(void*) &(cnf_p->fir_param),sizeof(audio_wb_speech_mode_struct));

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_GET_AUDIO_WB_MODE_PARAM_CNF, cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_set_audio_wb_input_fir_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_audio_wb_input_fir_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_audio_wb_input_fir_param_req_struct *req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_set_audio_wb_input_fir_param_req_struct*) ilm_ptr->local_para_ptr;

    AUD_FUNC_ENTRY1(AUD_SET_AUDIO_WB_PARAM_REQ_HDLR,0);

    if(req_p == NULL)
    {
        return ;
    }

    aud_context_p->src_id = req_p->src_id;

    /*set to L1SP directly*/
    L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_WB_SPEECH_INPUT_FIR,(kal_uint8*) (&req_p->fir_param), sizeof(audio_wb_speech_fir_struct));

    aud_set_aud_path_volume(aud_context_p->audio_mode);

    if (req_p->update_nvram)
    {
        if(med_context_p->nvram_state == MED_POWERON_READING_NVRAM_FINISH)
        {
            aud_context_p->src_mod = ilm_ptr->src_mod_id;

            aud_send_msg_to_nvram(
                MSG_ID_NVRAM_WRITE_REQ,
                NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID,
                &(req_p->fir_param),
                sizeof(audio_wb_speech_fir_struct));
        }
        else
        {
            aud_send_set_audio_wb_input_fir_cnf(MED_RES_FAIL);
        }
    }
    else
    {
        aud_send_set_audio_wb_input_fir_cnf(MED_RES_OK);
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  aud_set_audio_wb_output_fir_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_audio_wb_output_fir_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_audio_wb_output_fir_param_req_struct *req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_set_audio_wb_output_fir_param_req_struct*) ilm_ptr->local_para_ptr;

    AUD_FUNC_ENTRY1(AUD_SET_AUDIO_WB_PARAM_REQ_HDLR,1);

    if(req_p == NULL)
    {
        return ;
    }

    aud_context_p->src_id = req_p->src_id;

    /*set to L1SP directly*/
    L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_WB_SPEECH_OUTPUT_FIR,(kal_uint8*) (&req_p->fir_param), sizeof(audio_wb_speech_fir_struct));


    aud_set_aud_path_volume(aud_context_p->audio_mode);

    if (req_p->update_nvram)
    {
        if(med_context_p->nvram_state == MED_POWERON_READING_NVRAM_FINISH)
        {
            aud_context_p->src_mod = ilm_ptr->src_mod_id;

            aud_send_msg_to_nvram(
                MSG_ID_NVRAM_WRITE_REQ,
                NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_LID,
                &(req_p->fir_param),
                sizeof(audio_wb_speech_fir_struct));
        }
        else
        {
            aud_send_set_audio_wb_output_fir_cnf(MED_RES_FAIL);
        }
    }
    else
    {
        aud_send_set_audio_wb_output_fir_cnf(MED_RES_OK);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  aud_set_audio_wb_mode_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_audio_wb_mode_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_audio_wb_mode_param_req_struct *req_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_set_audio_wb_mode_param_req_struct*) ilm_ptr->local_para_ptr;

    AUD_FUNC_ENTRY1(AUD_SET_AUDIO_WB_PARAM_REQ_HDLR,2);

    if(req_p == NULL)
    {
        return ;
    }

    aud_context_p->src_id = req_p->src_id;

    /*set to L1SP directly*/
    L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX_WB_SPEECH_MODE_PARAM,(kal_uint8*) (&req_p->mode), sizeof(audio_wb_speech_mode_struct));

    aud_set_aud_path_volume(aud_context_p->audio_mode);

    if (req_p->update_nvram)
    {
        if(med_context_p->nvram_state == MED_POWERON_READING_NVRAM_FINISH)
        {
            aud_context_p->src_mod = ilm_ptr->src_mod_id;

            aud_send_msg_to_nvram(
                MSG_ID_NVRAM_WRITE_REQ,
                NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_LID,
                &(req_p->mode),
                sizeof(audio_wb_speech_mode_struct));
        }
        else
        {
            aud_send_set_audio_wb_mode_cnf(MED_RES_FAIL);
        }
    }
    else
    {
        aud_send_set_audio_wb_mode_cnf(MED_RES_OK);
    }
    
}



#endif /*__AMRWB_LINK_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  aud_get_volume_gain
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 *  type        [IN]        
 *  level       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 aud_get_volume_gain(kal_uint8 mode, kal_uint8 type, kal_uint8 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 apply_level = level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Check if it should be muted at level 0 */
    if (level & 0x40)
    {
        /* Mute at level 0 */
        if ( (level & 0x3F) == 0)
        {
            return 0;
        }

        /* Decrease one level for the actually applied level */
        apply_level = (level & 0x3F) - 1;
    }

    /* Validate index */
    if ((mode >= MAX_VOL_CATE) || (type >= MAX_VOL_TYPE) || (apply_level >= MAX_VOL_LEVEL))
    {
        return 0;
    }

    return aud_context_p->acoustic_data.volume_gain[mode][type][apply_level];
}


/*****************************************************************************
 * FUNCTION
 *  aud_get_volume_level
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode        [IN]        
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 aud_get_volume_level(kal_uint8 mode, kal_uint8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((mode >= MAX_VOL_CATE) || (type >= MAX_VOL_TYPE))
    {
        return 0;
    }

    return aud_context_p->acoustic_data.volume[mode][type];
}


/*****************************************************************************
 * FUNCTION
 *  aud_is_set_melody_path_volume_by_bt
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool aud_is_set_melody_path_volume_by_bt(kal_uint8 check_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  aud_set_aud_path_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_mode      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_set_aud_path_volume(kal_uint8 audio_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 volume;
    kal_bool is_mute;
    kal_uint8 speech_mode;
    kal_uint8 speech_volume_level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Store mute state because the mute flag will be cleared when speech is off */
    is_mute = L1SP_IsMicrophoneMuted();
    L1SP_Speech_Off();
    kal_sleep_task(5);
    L1SP_MuteMicrophone(is_mute);

    speech_mode = audio_mode ; //aud_speech_get_param_mode(audio_mode);
    speech_volume_level = aud_get_volume_level(audio_mode, AUD_VOLUME_SPH);

    aud_speech_set_fir_index_by_mode(audio_mode);

    /* Set output path and volume for others */
    switch (audio_mode)
    {
        /*----------------------- Normal Mode -------------------------*/
        case AUD_MODE_NORMAL:
        {
            aud_speech_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER));

            aud_keytone_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER));
            aud_tone_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER));

            aud_mic_set_device(custom_cfg_hw_aud_input_path(AUDIO_DEVICE_MIC1));

            /* set mic volume */
            if(!aud_context_p->audio_mute)
            {
                volume = aud_get_volume_gain(VOL_NORMAL, AUD_VOLUME_MIC, aud_get_volume_level(VOL_NORMAL, AUD_VOLUME_MIC));
                aud_mic_set_volume(volume, volume);
            }

            /* set speech volume */
            volume = aud_get_volume_gain(VOL_NORMAL, AUD_VOLUME_SPH, speech_volume_level);

            aud_speech_set_output_volume(volume, 0);

            aud_speech_set_volume_level_param(speech_volume_level, speech_mode);

            /* set general tone volume, use keypad tone volume level */
            if (!aud_context_p->speech_on)
            {
                volume = aud_get_volume_gain(VOL_NORMAL, AUD_VOLUME_CTN, aud_get_volume_level(VOL_NORMAL, AUD_VOLUME_KEY));
            }

            aud_tone_set_output_volume(volume, 0);

            /* set key tone volume */
            volume = aud_get_volume_gain(VOL_NORMAL, AUD_VOLUME_KEY, aud_get_volume_level(VOL_NORMAL, AUD_VOLUME_KEY));

            aud_keytone_set_output_volume(volume, 0);

            /* set loopback volume */
            volume = aud_get_volume_gain(VOL_NORMAL, AUD_VOLUME_SID, aud_get_volume_level(VOL_NORMAL, AUD_VOLUME_SID));

            aud_side_tone_set_volume(volume, 0);
    
            break;
        }

        /*---------------------- Headset Mode -----------------------*/
        case AUD_MODE_HEADSET:

            /* Set output device */
            aud_speech_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER2));

            aud_keytone_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER2));
            aud_tone_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_SPEAKER2));

            aud_mic_set_device(custom_cfg_hw_aud_input_path(AUDIO_DEVICE_MIC2));

            /* set mic volume */
            if(!aud_context_p->audio_mute)
            {
                volume = aud_get_volume_gain(VOL_HEADSET, AUD_VOLUME_MIC, aud_get_volume_level(VOL_HEADSET, AUD_VOLUME_MIC));
                aud_mic_set_volume(volume, volume);
            }

            /* set speech volume */
            volume = aud_get_volume_gain(VOL_HEADSET, AUD_VOLUME_SPH, speech_volume_level);

            aud_speech_set_output_volume(volume, 0);

            aud_speech_set_volume_level_param(speech_volume_level, speech_mode);

            /* set general tone volume, use key tone volume level */
            if (!aud_context_p->speech_on)
            {
                volume = aud_get_volume_gain(VOL_HEADSET,AUD_VOLUME_CTN,aud_get_volume_level(VOL_HEADSET, AUD_VOLUME_KEY));
            }
            aud_tone_set_output_volume(volume, 0);
            /* set key tone volume */
            volume = aud_get_volume_gain(VOL_HEADSET, AUD_VOLUME_KEY, aud_get_volume_level(VOL_HEADSET, AUD_VOLUME_KEY));
            aud_keytone_set_output_volume(volume, 0);
            /* set loopback volume */
            volume = aud_get_volume_gain(VOL_HEADSET, AUD_VOLUME_SID, aud_get_volume_level(VOL_HEADSET, AUD_VOLUME_SID));
            aud_side_tone_set_volume(volume, 0);
    
            break;

        /*------------------------ Loud Speaker --------------------------------*/
        case AUD_MODE_LOUDSPK:

            aud_speech_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_LOUDSPEAKER));

            aud_keytone_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_LOUDSPEAKER));
            aud_tone_set_output_device(custom_cfg_hw_aud_output_path(AUDIO_DEVICE_LOUDSPEAKER));

            aud_mic_set_device(custom_cfg_hw_aud_input_path(AUDIO_DEVICE_MIC3));

            /* set mic volume */
            if(!aud_context_p->audio_mute)
            {
                volume = aud_get_volume_gain(VOL_HANDFREE, AUD_VOLUME_MIC, aud_get_volume_level(VOL_HANDFREE, AUD_VOLUME_MIC));
                aud_mic_set_volume(volume, volume);
            }
 
            /* set speech volume */
            volume = aud_get_volume_gain(VOL_HANDFREE, AUD_VOLUME_SPH, speech_volume_level);
 
            aud_speech_set_output_volume(volume, 0);
 
            aud_speech_set_volume_level_param(speech_volume_level, speech_mode);

            /* set general tone volume, use key tone volume level */
            if (!aud_context_p->speech_on)
            {
                volume = aud_get_volume_gain(VOL_HANDFREE,AUD_VOLUME_CTN,aud_get_volume_level(VOL_HANDFREE, AUD_VOLUME_KEY));
            }
            aud_tone_set_output_volume(volume, 0);
            /* set key tone volume */
            volume = aud_get_volume_gain(VOL_HANDFREE, AUD_VOLUME_KEY, aud_get_volume_level(VOL_HANDFREE, AUD_VOLUME_KEY));
            aud_keytone_set_output_volume(volume, 0);
            /* set loopback volume */
            volume = aud_get_volume_gain(VOL_HANDFREE, AUD_VOLUME_SID, aud_get_volume_level(VOL_HANDFREE, AUD_VOLUME_SID));
            aud_side_tone_set_volume(volume, 0);
 
            break;
    
        default:
            break;
    }

     if (aud_context_p->speech_on)
    {
        L1SP_Speech_On(aud_context_p->rat_mode);
    }
 
}

/*****************************************************************************
 * FUNCTION
 *  aud_audio_set_device_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_set_device_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 cnf_msg_id;
    void *cnf_p = NULL;

    media_aud_set_device_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_set_device_req_struct*) ilm_ptr->local_para_ptr;

    switch (req_p->audio_type)
    {
        case AUD_TYPE_SPEECH:
            aud_speech_set_output_device(req_p->device);
            break;
        case AUD_TYPE_TONE:
            aud_tone_set_output_device(req_p->device);
            break;
        case AUD_TYPE_KEYTONE:
            aud_keytone_set_output_device(req_p->device);
            break;
        case AUD_TYPE_MIC:
            aud_mic_set_device(req_p->device);
            break;
        default:
            break;

    }

    cnf_p = (media_aud_set_device_cnf_struct*)
        construct_local_para(sizeof(media_aud_set_device_cnf_struct), TD_CTRL);

    cnf_msg_id = MSG_ID_MEDIA_AUD_SET_DEVICE_CNF;

    aud_send_ilm(ilm_ptr->src_mod_id, cnf_msg_id, cnf_p, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  aud_audio_get_volume_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_get_volume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_get_volume_req_struct *req_p;
    media_aud_get_volume_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_get_volume_req_struct*) ilm_ptr->local_para_ptr;

    cnf_p = (media_aud_get_volume_cnf_struct*) construct_local_para(sizeof(media_aud_get_volume_cnf_struct), TD_CTRL);

    cnf_p->src_id = req_p->src_id;
    cnf_p->volume_type = req_p->volume_type;
    cnf_p->result = KAL_TRUE;
    cnf_p->volume = aud_context_p->acoustic_data.volume[aud_context_p->audio_mode][req_p->volume_type];

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_GET_VOLUME_CNF, cnf_p, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  aud_audio_set_volume_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_set_volume_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_aud_set_volume_cnf_struct *cnf_p = NULL;
    kal_uint8 volume;
    kal_uint8 audio_type;

    media_aud_set_volume_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_set_volume_req_struct*) ilm_ptr->local_para_ptr;
    
    audio_type = req_p->audio_type;
    
    aud_context_p->acoustic_data.volume[AUD_MODE_NORMAL][audio_type] = req_p->volume;
    aud_context_p->acoustic_data.volume[AUD_MODE_HEADSET][audio_type] = req_p->volume;
    aud_context_p->acoustic_data.volume[AUD_MODE_LOUDSPK][audio_type] = req_p->volume;

    /* get volume gain from table */
    volume = aud_get_volume_gain(aud_context_p->audio_mode, audio_type, req_p->volume);

    /* call the corresponding handler */
    switch (req_p->audio_type)
    {
        case AUD_VOLUME_SPH:
            /* Use speech volume as tone volume when in-call */
            if (aud_context_p->speech_on)
            {
                aud_tone_set_output_volume(volume, 0);
            }
            aud_speech_set_output_volume(volume, 0);
            aud_speech_set_volume_level_param(req_p->volume, aud_context_p->audio_mode);
            break;

        case AUD_VOLUME_KEY:
            /* set keytone volume */
            aud_keytone_set_output_volume(volume, 0);
            
            /* set general tone volume, use key tone volume level */
            if (!aud_context_p->speech_on)
            {
                volume = aud_get_volume_gain(aud_context_p->audio_mode, AUD_VOLUME_CTN, req_p->volume);
                aud_tone_set_output_volume(volume, 0);
            }
            break;

        case AUD_VOLUME_MIC:
            aud_mic_set_volume(volume, 0);
            
            /* disable audio mute when the volume is set again */
            aud_context_p->audio_mute = KAL_FALSE;
            break;

        case AUD_VOLUME_SID:
            aud_side_tone_set_volume(volume, 0);
            break;
    
        default:
            break;

    }

    cnf_p = (media_aud_set_volume_cnf_struct*)
        construct_local_para(sizeof(media_aud_set_volume_cnf_struct), TD_CTRL);

    cnf_p->result = MED_RES_OK;

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_SET_VOLUME_CNF, cnf_p, NULL);

    /* Store default volumn level to NVRAM for MODEM project */

    if (med_context_p->nvram_state == MED_POWERON_READING_NVRAM_FINISH)
    {
        aud_context_p->no_cnf = KAL_TRUE; /* Indicate that the confirm message is not required */
        aud_context_p->src_mod = ilm_ptr->src_mod_id;
        aud_send_msg_to_nvram(
            MSG_ID_NVRAM_WRITE_REQ,
            NVRAM_EF_CUST_ACOUSTIC_DATA_LID,
            &(aud_context_p->acoustic_data),
            sizeof(custom_acoustic_struct));
    }
}

/*****************************************************************************
 * FUNCTION
 *  aud_audio_mute_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_mute_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 cnf_msg_id;
    void *cnf_p = NULL;

    media_aud_mute_req_struct *req_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (media_aud_mute_req_struct*) ilm_ptr->local_para_ptr;

    switch (req_p->device)
    {
        case AUDIO_DEVICE_MICROPHONE:
            /* call L1AUD to set microphone mute */
            aud_mic_mute(req_p->mute);
            aud_context_p->audio_mute = req_p->mute;
            break;
        default:
            break;
    }

    cnf_p = (media_aud_mute_cnf_struct*) construct_local_para(sizeof(media_aud_mute_cnf_struct), TD_CTRL);

    cnf_msg_id = MSG_ID_MEDIA_AUD_MUTE_CNF;

    aud_send_ilm(ilm_ptr->src_mod_id, cnf_msg_id, cnf_p, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  aud_audio_mute_digital_gain
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_audio_mute_digital_gain(kal_bool set_mute, kal_uint16 mute_app)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY2(AUD_TRC_AUDIO_MUTE_DIGITAL_GAIN, set_mute, g_aud_mute_digital_gain_app);

    /* Only set mute for music volume in idle mode */
    if(aud_context_p->speech_on)
    {
        return;
    }

    if(set_mute)
    {
        g_aud_mute_digital_gain_app |= mute_app;
        Media_MuteSpeaker(KAL_TRUE);
    }
    else
    {
        g_aud_mute_digital_gain_app &= ~mute_app;
        if(g_aud_mute_digital_gain_app == 0)
        {
            Media_MuteSpeaker(KAL_FALSE);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  aud_cfg_audio_out_device
 * DESCRIPTION
 *  
 * PARAMETERS
 *  audio_sound_id      [IN]        
 *  out_device_path     [?]         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_cfg_audio_out_device(kal_uint8 audio_sound_id, kal_uint8 *out_device_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MED_ASSERT(out_device_path != NULL);

    /* if there is no change, it will use the default value at PS */
    /* specially for connect tone */
    if ((audio_sound_id == TONE_CALL_CONNECT) || (audio_sound_id == TONE_WARNING2) || (audio_sound_id == TONE_ERROR2))
    {
        switch (aud_context_p->audio_mode)
        {
            case AUD_MODE_NORMAL:
                *out_device_path = AUDIO_DEVICE_SPEAKER;
                break;
            case AUD_MODE_LOUDSPK:
                *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
            case AUD_MODE_HEADSET:
                *out_device_path = AUDIO_DEVICE_SPEAKER2;
                break;
            default:
                *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
        }
    }
    else if (audio_sound_id <= TONE_NEGATIVE_ACK)
    {
        switch (aud_context_p->audio_mode)
        {
            case AUD_MODE_NORMAL:
                *out_device_path = AUDIO_DEVICE_SPEAKER;
                break;
            case AUD_MODE_LOUDSPK:
                *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
            case AUD_MODE_HEADSET:
                *out_device_path = AUDIO_DEVICE_SPEAKER2;
                break;
            default:
                *out_device_path = AUDIO_DEVICE_SPEAKER;
                break;
        }
    }
    else if ((audio_sound_id > TONE_NEGATIVE_ACK) && (audio_sound_id <= MAX_TONE_ID))
    {
        switch (aud_context_p->audio_mode)
        {
            case AUD_MODE_NORMAL:
                /* if speech on, tone shall output via speaker1 */
                if (aud_context_p->speech_on)
                {
                    *out_device_path = AUDIO_DEVICE_SPEAKER;
                }
                else
                {
                    *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                }
                break;
            case AUD_MODE_LOUDSPK:
                *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                break;
            case AUD_MODE_HEADSET:
                *out_device_path = AUDIO_DEVICE_SPEAKER2;
                break;
            default:
                /* if speech on, tone shall output via speaker1 */
                if (aud_context_p->speech_on)
                {
                    *out_device_path = AUDIO_DEVICE_SPEAKER;
                }
                else
                {
                    *out_device_path = AUDIO_DEVICE_LOUDSPEAKER;
                }
                break;
        }
    }
    else
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}

#endif /* MED_NOT_PRESENT */ 

