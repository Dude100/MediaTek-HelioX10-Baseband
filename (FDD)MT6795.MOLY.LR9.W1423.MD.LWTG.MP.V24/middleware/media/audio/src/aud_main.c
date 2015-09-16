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
 *   aud_main.c
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

/*==== INCLUDES =========*/

/* system includes */
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "kal_trace.h"
#include "nvram_msgid.h"
#include "med_msgid.h"
 
/* global includes */
#include "l1audio.h"
#include "audio_nvram_def.h"
#include "nvram_interface.h"

/* local includes */
#include "med_global.h"
#include "med_struct.h"
#include "med_context.h" 
#include "aud_main.h"
 

#ifdef __AUD_TRACE_ON__
#include "med_trc.h"
#endif 
 
aud_context_struct *aud_context_p = &(med_context.aud_context);
 
/*****************************************************************************
 * FUNCTION
 *  aud_startup_hdlr
 * DESCRIPTION
 *  This function is handle startup procedure of audio module.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_startup_hdlr(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    aud_context_p->src_mod = ilm_ptr->src_mod_id;
 
}

/*****************************************************************************
 * FUNCTION
 *  aud_startup_read_nvram_data
 * DESCRIPTION
 *  This function is to read audio nvram data when startup.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void aud_startup_read_nvram_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AUD_FUNC_ENTRY(AUD_STARTUP_READ_NVRAM_DATA);

    med_context_p->nvram_state = MED_POWERON_READING_NVRAM;
    aud_send_msg_to_nvram(MSG_ID_NVRAM_READ_REQ, NVRAM_EF_CUST_ACOUSTIC_DATA_LID, 0, 0);
}


/*****************************************************************************
 * FUNCTION
 *  aud_main
 * DESCRIPTION
 *  This function is main message dispatching function of audio module.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
#ifdef __MED_ECALL_MOD__
    if (ilm_ptr->msg_id >= MSG_ID_MEDIA_AUD_EMSD_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MEDIA_AUD_EMSD_CODE_END)
    {
        aud_ecall_main(ilm_ptr);
        return;
    }
#endif /*__MED_ECALL_MOD__*/

    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_MEDIA_AUD_SET_AUDIO_MODE_REQ:
            aud_set_audio_mode_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_GET_AUDIO_PROFILE_REQ:
            aud_get_audio_profile_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_AUDIO_PROFILE_REQ:
            aud_set_audio_profile_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_GET_AUDIO_PARAM_REQ:
            aud_get_audio_param_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_AUDIO_PARAM_REQ:
            aud_set_audio_param_req_hdlr(ilm_ptr);
            break;
    #ifdef __AMRWB_LINK_SUPPORT__
        case MSG_ID_MEDIA_AUD_GET_AUDIO_WB_INPUT_FIR_PARAM_REQ:
            aud_get_audio_wb_input_fir_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_GET_AUDIO_WB_OUTPUT_FIR_PARAM_REQ:
            aud_get_audio_wb_output_fir_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_GET_AUDIO_WB_MODE_PARAM_REQ:
            aud_get_audio_wb_mode_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_AUDIO_WB_INPUT_FIR_PARAM_REQ:
            aud_set_audio_wb_input_fir_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_AUDIO_WB_OUTPUT_FIR_PARAM_REQ:
            aud_set_audio_wb_output_fir_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_AUDIO_WB_MODE_PARAM_REQ:
            aud_set_audio_wb_mode_req_hdlr(ilm_ptr);
            break;
    #endif

        case MSG_ID_MEDIA_AUD_SP_SET_MODE_REQ:
            aud_speech_set_mode_req_hdlr(ilm_ptr);
            break;

        case MSG_ID_MEDIA_AUD_SET_DEVICE_REQ:
            aud_audio_set_device_req_hdlr(ilm_ptr);
            break;

        case MSG_ID_MEDIA_AUD_GET_VOLUME_REQ:
            aud_audio_get_volume_req_hdlr(ilm_ptr);
            break;

        case MSG_ID_MEDIA_AUD_SET_VOLUME_REQ:
            aud_audio_set_volume_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_PLAY_BY_ID_REQ:
            aud_media_play_by_id_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_STOP_BY_ID_REQ:
            aud_media_stop_by_id_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_MUTE_REQ:
            aud_audio_mute_req_hdlr(ilm_ptr);
            break;

        case MSG_ID_MEDIA_IN_PROC_CALL_REQ:
            aud_util_in_proc_call_req_hdlr(ilm_ptr);
            break;

        default:
            /* assert */
            break;

    }
    return;

}


/*****************************************************************************
 * FUNCTION
 *  aud_init
 * DESCRIPTION
 *  This function is used to init audio task.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool aud_init(void)
{    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    aud_context_p->state = AUD_IDLE;

    nvram_ltable_register(logical_data_item_table_audio);

    if (!aud_speech_init())
    {
        return KAL_FALSE;
    }

    if (!aud_audio_init())
    {
        return KAL_FALSE;
    }

    if (!aud_tone_init())
    {
        return KAL_FALSE;
    }
    return KAL_TRUE;
}

#else
/*==== INCLUDES =========*/

/* system includes */
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "kal_trace.h"
#include "nvram_msgid.h"
#include "med_msgid.h"
 
/* global includes */
#include "l1audio.h"
#include "audio_nvram_def.h"
#include "nvram_interface.h"

/* local includes */
#include "med_global.h"
#include "med_struct.h"
#include "med_context.h" 
#include "aud_main.h"
 
/*****************************************************************************
 * FUNCTION
 *  aud_main
 * DESCRIPTION
 *  This function is main message dispatching function of audio module.
 * PARAMETERS
 *  ilm_ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void aud_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
#ifdef __MED_ECALL_MOD__
    if (ilm_ptr->msg_id >= MSG_ID_MEDIA_AUD_EMSD_CODE_BEGIN && ilm_ptr->msg_id <= MSG_ID_MEDIA_AUD_EMSD_CODE_END)
    {
        aud_ecall_main(ilm_ptr);
        return;
    }
#endif /*__MED_ECALL_MOD__*/

    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_MEDIA_AUD_SET_AUDIO_MODE_REQ:
            ASSERT(0);//aud_set_audio_mode_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_GET_AUDIO_PROFILE_REQ:
            ASSERT(0);//aud_get_audio_profile_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_AUDIO_PROFILE_REQ:
            ASSERT(0);//aud_set_audio_profile_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_GET_AUDIO_PARAM_REQ:
            ASSERT(0);//aud_get_audio_param_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_AUDIO_PARAM_REQ:
            ASSERT(0);//aud_set_audio_param_req_hdlr(ilm_ptr);
            break;
    #ifdef __AMRWB_LINK_SUPPORT__
        case MSG_ID_MEDIA_AUD_GET_AUDIO_WB_INPUT_FIR_PARAM_REQ:
            ASSERT(0);//aud_get_audio_wb_input_fir_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_GET_AUDIO_WB_OUTPUT_FIR_PARAM_REQ:
            ASSERT(0);//aud_get_audio_wb_output_fir_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_GET_AUDIO_WB_MODE_PARAM_REQ:
            ASSERT(0);//aud_get_audio_wb_mode_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_AUDIO_WB_INPUT_FIR_PARAM_REQ:
            ASSERT(0);//aud_set_audio_wb_input_fir_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_AUDIO_WB_OUTPUT_FIR_PARAM_REQ:
            ASSERT(0);//aud_set_audio_wb_output_fir_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_SET_AUDIO_WB_MODE_PARAM_REQ:
            ASSERT(0);//aud_set_audio_wb_mode_req_hdlr(ilm_ptr);
            break;
    #endif

        case MSG_ID_MEDIA_AUD_SP_SET_MODE_REQ:
            ASSERT(0);//aud_speech_set_mode_req_hdlr(ilm_ptr);
            break;

        case MSG_ID_MEDIA_AUD_SET_DEVICE_REQ:
            ASSERT(0);//aud_audio_set_device_req_hdlr(ilm_ptr);
            break;

        case MSG_ID_MEDIA_AUD_GET_VOLUME_REQ:
            ASSERT(0);//aud_audio_get_volume_req_hdlr(ilm_ptr);
            break;

        case MSG_ID_MEDIA_AUD_SET_VOLUME_REQ:
            ASSERT(0);//aud_audio_set_volume_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_PLAY_BY_ID_REQ:
            ASSERT(0);//aud_media_play_by_id_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_STOP_BY_ID_REQ:
            ASSERT(0);//aud_media_stop_by_id_req_hdlr(ilm_ptr);
            break;
        case MSG_ID_MEDIA_AUD_MUTE_REQ:
            ASSERT(0);//aud_audio_mute_req_hdlr(ilm_ptr);
            break;

        case MSG_ID_MEDIA_IN_PROC_CALL_REQ:
            aud_util_in_proc_call_req_hdlr(ilm_ptr);
            break;

        default:
            /* assert */
            break;

    }
    return;

}
#endif /* MED_NOT_PRESENT */ 


