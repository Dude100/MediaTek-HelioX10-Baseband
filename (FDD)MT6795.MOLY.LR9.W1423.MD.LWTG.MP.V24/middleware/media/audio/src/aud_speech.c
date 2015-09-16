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
 * aud_speech.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary functions of audio manager task.
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
 *    AUD_SPEECH
 * DESCRIPTION
 *    This module defines the speech related function for Audio Manager.
 *  
 ******************************************************************/

#ifndef MED_NOT_PRESENT

/*==== INCLUDES ===========*/

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "med_msgid.h"
 
/* global includes */
#include "l1audio.h"
//#include "device.h"

/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h" 
#include "med_context.h"
#include "aud_main.h"
#include "med_main.h"
 

//#include "string.h"

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 
 
/*****************************************************************************
 * FUNCTION
 *  aud_speech_init
 * DESCRIPTION
 *  This function is used to init this module.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_speech_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->speech_on = KAL_FALSE;
    aud_context_p->rat_mode = 0xFF;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_output_device
 * DESCRIPTION
 *  
 * PARAMETERS
 *  device      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_set_output_device(kal_uint8 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_PATH(AUD_TYPE_SPEECH, device, -1);
    L1SP_SetOutputDevice(device);
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_output_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume1                 [IN]        
 *  digital_gain_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_set_output_volume(kal_uint8 volume1, kal_int8 digital_gain_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_SPH, volume1, digital_gain_index);
    L1SP_SetOutputVolume(volume1, digital_gain_index);
}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_volume_level_param
 * DESCRIPTION
 *  
 * PARAMETERS
 *  speech_volume    [IN]        
 *  speech_mode      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_set_volume_level_param(kal_uint8 speech_volume_level, kal_uint8 speech_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 param_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (speech_mode)
    {
        case SPH_MODE_LOUDSPK:
            param_index = 0;
            break;
        case SPH_MODE_BT_CARKIT:
            param_index = 1;
            break;
        case SPH_MODE_AUX1:
            param_index = 2;
            break;
        default:
            param_index = 0;   /* For other mode, don't care parameter. Choose anyone to set */
            break;
    }

   L1SP_SetSpeechVolumeLevelByIndex(speech_volume_level,param_index);

}


/*****************************************************************************
 * FUNCTION
 *  aud_mic_set_device
 * DESCRIPTION
 *  
 * PARAMETERS
 *  device      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mic_set_device(kal_uint8 device)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_PATH(AUD_TYPE_MIC, device, -1);

    L1SP_SetInputSource(device);
}

/*****************************************************************************
 * FUNCTION
 *  aud_mic_set_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume1     [IN]        
 *  volume2     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mic_set_volume(kal_uint8 volume1, kal_uint8 volume2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_MIC, volume1, volume2);
    L1SP_SetMicrophoneVolume(volume1);
}


/*****************************************************************************
 * FUNCTION
 *  aud_mic_mute
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mute        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_mic_mute(kal_bool mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    L1SP_MuteMicrophone(mute);
}

/*****************************************************************************
 * FUNCTION
 *  aud_side_tone_set_volume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  volume1                 [IN]        
 *  digital_gain_index      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void aud_side_tone_set_volume(kal_uint8 volume1, kal_int8 digital_gain_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_TRACE_VOLUME(AUD_VOLUME_SID, volume1, digital_gain_index);
    L1SP_SetSidetoneVolume(volume1);
}

/*****************************************************************************
 * FUNCTION
 *  aud_speech_query_speech_scenario_by_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
SPH_ENH_AND_FIR_SCENE aud_speech_query_speech_scenario_by_mode(kal_uint8 audio_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SPH_ENH_AND_FIR_SCENE scene;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (audio_mode)
    {
        case AUD_MODE_HEADSET:
        {
            scene = SPH_ENH_AND_FIR_SCENE_EARPHONE;
            break;
        }

        case AUD_MODE_LOUDSPK:
        {
            scene = SPH_ENH_AND_FIR_SCENE_LOUDSPK;
            break;
        }

        /*AUD_MODE_NORMAL*/
        default:
        {
            scene = SPH_ENH_AND_FIR_SCENE_NORMAL;
            break;
        }

    }

    return scene;
}

/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_fir_index_by_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_set_fir_index_by_mode(kal_uint8 audio_mode)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SPH_ENH_AND_FIR_SCENE scene;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    scene = aud_speech_query_speech_scenario_by_mode(audio_mode);

    L1SP_SetSpeechEnhanceAndFir(scene,SPH_ENH_AND_FIR_UPDATE_TYPE_ALL);
}

/*****************************************************************************
 * FUNCTION
 *  aud_speech_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_on(kal_uint8 rat_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY2(AUD_TRC_SPEECH_ON, rat_mode, aud_context_p->state);

    /* Un-mute digital gain in case it is turn off by set mute function */
    aud_audio_mute_digital_gain(KAL_FALSE, AUD_DIGITAL_GAIN_AUDIO);

    L1SP_Speech_On(rat_mode);
    aud_context_p->speech_on = KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  aud_speech_off
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_off(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_TRC_SPEECH_OFF);

    L1SP_Speech_Off();
    aud_context_p->speech_on = KAL_FALSE;

}

/*****************************************************************************
 * FUNCTION
 *  aud_speech_set_mode_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_speech_set_mode_req_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 cnf_msg_id;
    media_aud_sp_set_mode_cnf_struct *cnf_p = NULL;
    meida_aud_sp_set_mode_req_struct *req_p;
    kal_uint8 volume;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req_p = (meida_aud_sp_set_mode_req_struct*) ilm_ptr->local_para_ptr;

    AUD_FUNC_ENTRY1(AUD_TRC_SPEECH_SET_MODE_REQ_HDLR, aud_context_p->state);

    /* if keytone is playing, stop it */
    aud_keytone_stop();

    /* set general tone volume */
    if (req_p->speech_on)
    {
        /* use speech volume for tone */
        volume = aud_get_volume_gain(aud_context_p->audio_mode, AUD_VOLUME_SPH, aud_get_volume_level(aud_context_p->audio_mode, AUD_VOLUME_SPH));
    }
    else
    {
        /* reset tone volume level, use key tone volume level */
        volume = aud_get_volume_gain(aud_context_p->audio_mode, AUD_VOLUME_CTN, aud_get_volume_level(aud_context_p->audio_mode, AUD_VOLUME_KEY));
    }

    aud_tone_set_output_volume(volume, 0);

    if (req_p->speech_on)
    {
        aud_context_p->rat_mode = req_p->rat_mode;

        aud_speech_on(aud_context_p->rat_mode);
    }
    else
    {
        aud_speech_off();
        aud_context_p->rat_mode = 0xFF;

    }

    cnf_msg_id = MSG_ID_MEDIA_AUD_SP_SET_MODE_CNF;
    cnf_p = (media_aud_sp_set_mode_cnf_struct*) construct_local_para(sizeof(media_aud_sp_set_mode_cnf_struct), TD_CTRL);

    cnf_p->result = MED_RES_OK;

    aud_send_ilm(ilm_ptr->src_mod_id, cnf_msg_id, cnf_p, NULL);

}

#endif /* MED_NOT_PRESENT */ 

