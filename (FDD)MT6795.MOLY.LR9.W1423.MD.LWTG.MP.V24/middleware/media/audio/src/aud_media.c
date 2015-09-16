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
 *   aud_media.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes media related functions of audio manager task.
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
 *    AUD_MEDIA
 * DESCRIPTION
 *    This module defines the media related function for Audio Manager.
 *  
 ******************************************************************/

#ifndef MED_NOT_PRESENT

/*-----------------------------------------------------------------------------
                    include files
-----------------------------------------------------------------------------*/

#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "med_msgid.h"

/* global includes */
#include "l1audio.h"
#include "device.h"
#include "resource_audio.h"
 
/* local includes */
#include "med_global.h"
#include "aud_defs.h"
#include "med_struct.h"
#include "med_context.h"
#include "med_main.h"
#include "aud_main.h"

 
#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 

/*****************************************************************************
 * FUNCTION
 *  aud_media_play_by_id_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_play_by_id_req_hdlr(ilm_struct *ilm_ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_uint8 audio_id;
    kal_uint8 audio_out_device;    
    kal_uint8 volume;
    media_aud_play_by_id_req_struct *req_p = (media_aud_play_by_id_req_struct*) ilm_ptr->local_para_ptr;
    media_aud_play_by_id_cnf_struct *cnf_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    audio_id = req_p->audio_id;

    if (req_p->output_path == AUDIO_DEVICE_SPEAKER2)
    {
        /* Use default configuration */
        aud_cfg_audio_out_device(audio_id, &audio_out_device);
    }
    else
    {
        /* Use user-specified path */
        audio_out_device = req_p->output_path;
    }

    if (audio_id <= TONE_KEY_CLICK)
    {
        aud_keytone_stop();

        /* Update keytone volume */
        volume = aud_get_volume_gain(aud_context_p->audio_mode, AUD_VOLUME_KEY, req_p->volume);
        aud_keytone_set_output_volume(volume, 0);
    
        aud_keytone_play(audio_id, audio_out_device, req_p->play_style);
    }
    else if ((audio_id > TONE_KEY_CLICK) && (audio_id <= MAX_TONE_ID))
    {
        /* if keytone is playing, stop it */
        aud_keytone_stop();

        if (req_p->play_style == DEVICE_AUDIO_PLAY_INFINITE)
        {
            aud_context_p->tone_playing = KAL_TRUE;
        }

        /* Update tone volume */
        volume = aud_get_volume_gain(aud_context_p->audio_mode, AUD_VOLUME_CTN, req_p->volume);
        aud_tone_set_output_volume(volume, 0);

        aud_tone_play(audio_id, audio_out_device);
    }

    cnf_p = (media_aud_play_by_id_cnf_struct*)
        construct_local_para(sizeof(media_aud_play_by_id_cnf_struct), TD_CTRL);

    cnf_p->result = MED_RES_OK;

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_PLAY_BY_ID_CNF, cnf_p, NULL);

}


/*****************************************************************************
 * FUNCTION
 *  aud_media_stop_by_id_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_media_stop_by_id_req_hdlr(ilm_struct *ilm_ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 audio_id;
    media_aud_stop_by_id_req_struct *req_p = (media_aud_stop_by_id_req_struct*) ilm_ptr->local_para_ptr;
    media_aud_stop_by_id_cnf_struct *cnf_p = NULL;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    aud_context_p->src_mod = ilm_ptr->src_mod_id;

    audio_id = req_p->audio_id;

    if (audio_id <= TONE_KEY_CLICK)
    {
        aud_keytone_stop();
    }
    else if ((audio_id > TONE_KEY_CLICK) && (audio_id <= MAX_TONE_ID))
    {
        aud_tone_stop();
    }

    cnf_p = (media_aud_stop_by_id_cnf_struct*)
        construct_local_para(sizeof(media_aud_stop_by_id_cnf_struct), TD_CTRL);

    cnf_p->result = MED_RES_OK;

    aud_send_ilm(ilm_ptr->src_mod_id, MSG_ID_MEDIA_AUD_STOP_BY_ID_CNF, cnf_p, NULL);

}

#endif /* MED_NOT_PRESENT */ 

