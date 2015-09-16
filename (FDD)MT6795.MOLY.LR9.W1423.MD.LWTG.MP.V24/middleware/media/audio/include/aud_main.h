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
 * aud_main.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary global variables of audio manager task.
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

#ifndef _AUD_MAIN_H
#define _AUD_MAIN_H

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"

#include "l1audio.h"
#include "med_struct.h"
#include "med_global.h"


/* for mute digital gain application */
typedef enum
{
    AUD_DIGITAL_GAIN_AUDIO =  0x0001,
    AUD_DIGITAL_GAIN_MTV   =  0x0002,
    AUD_DIGITAL_GAIN_VIDEO =  0x0004
} aud_mute_digital_gain_app_enum;

/*---- Audio utilities -----*/
extern void aud_util_in_proc_call_req_hdlr(ilm_struct *ilm_ptr);

/*---- main -----*/
extern kal_bool aud_init(void);
extern void aud_main(ilm_struct *ilm_ptr);
extern void aud_startup_hdlr(ilm_struct *ilm_ptr);
extern void aud_startup_set_param(void* param);
extern void aud_startup_read_nvram_data(void);

/* audio */
extern kal_bool aud_audio_init(void);
extern void aud_set_audio_mode_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_get_audio_profile_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_set_audio_profile_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_get_audio_param_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_get_audio_param_from_nvram_rsp(void* param);
extern void aud_set_audio_param_req_hdlr(ilm_struct *ilm_ptr);


#ifdef __AMRWB_LINK_SUPPORT__
extern void aud_get_audio_wb_input_fir_req_hdlr(ilm_struct * ilm_ptr);
extern void aud_get_audio_wb_output_fir_req_hdlr(ilm_struct * ilm_ptr);
extern void aud_get_audio_wb_mode_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_set_audio_wb_input_fir_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_set_audio_wb_output_fir_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_set_audio_wb_mode_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_send_set_audio_wb_input_fir_cnf(kal_uint8 result);
extern void aud_send_set_audio_wb_output_fir_cnf(kal_uint8 result);
extern void aud_send_set_audio_wb_mode_cnf(kal_uint8 result);
#endif

extern void aud_set_aud_path_volume(kal_uint8 audio_mode);
extern void aud_audio_get_volume_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_audio_set_volume_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_audio_mute_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_audio_mute_digital_gain(kal_bool set_mute, kal_uint16 mute_app);
extern kal_bool aud_cfg_audio_out_device(kal_uint8 audio_sound_id, kal_uint8 *out_device_path);
extern void aud_media_play_by_id_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_stop_by_id_req_hdlr(ilm_struct *ilm_ptr);

extern kal_uint8 aud_get_volume_gain(kal_uint8 mode, kal_uint8 type, kal_uint8 level);
extern kal_uint8 aud_get_volume_level(kal_uint8 mode, kal_uint8 type);
extern void aud_audio_set_device_req_hdlr(ilm_struct *ilm_ptr);

/* speech */
extern kal_bool aud_speech_init(void);
extern void aud_speech_set_output_device(kal_uint8 device);
extern void aud_speech_set_output_volume(kal_uint8 volume1, kal_int8 digital_gain_index);
extern void aud_speech_set_volume_level_param(kal_uint8 speech_volume_level, kal_uint8 speech_mode);

extern void aud_speech_on(kal_uint8 rat_mode);
extern void aud_speech_off(void);
extern void aud_speech_set_mode_req_hdlr(ilm_struct *ilm_ptr);

extern void aud_speech_set_fir_coefficient(kal_int16 input_FIR_index, kal_int16 output_FIR_index);
extern void aud_speech_set_fir_index_by_mode(kal_uint8 audio_mode);
extern SPH_ENH_AND_FIR_SCENE aud_speech_query_speech_scenario_by_mode(kal_uint8 audio_mode);

extern void aud_mic_set_device(kal_uint8 device);
extern void aud_mic_set_volume(kal_uint8 volume1, kal_uint8 volume2);
extern void aud_mic_mute(kal_bool mute);

/* Sidetone */
extern void aud_side_tone_set_volume(kal_uint8 volume1, kal_int8 digital_gain_index);

/* keytone */
extern void aud_keytone_set_output_device(kal_uint8 device);
extern void aud_keytone_set_output_volume(kal_uint8 volume1, kal_int8 digital_gain_index);
extern void aud_keytone_play(kal_uint8 audio_id, kal_uint8 audio_out_device, kal_uint8 play_style);
extern void aud_keytone_stop(void);

/* tone */
extern kal_bool aud_tone_init(void);

extern void aud_tone_set_output_device(kal_uint8 device);
extern void aud_tone_set_output_volume(kal_uint8 volume1, kal_int8 digital_gain_index);
extern void aud_tone_play(kal_uint8 audio_id, kal_uint8 audio_out_device);
extern void aud_tone_stop(void);

/* ilm */
extern void aud_send_ilm(module_type dest_id, kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr);
extern void aud_send_in_proc_call_req( module_type src_mod_id,  media_in_proc_call_type func, kal_uint32 func_arg1, void *func_arg2);

extern void aud_send_msg_to_nvram(msg_type msg_name, kal_uint16 ef_id, void *data_ptr, kal_uint16 length);
extern void aud_send_startup_cnf(kal_uint8 result);
extern void aud_send_set_audio_profile_cnf(kal_uint8 result);
extern void aud_send_set_audio_param_cnf(kal_uint8 result);

/* utility */
extern kal_uint8 aud_audio_out_dev_convert(kal_uint8 speaker_id);

#ifdef __MED_ECALL_MOD__
extern void aud_ecall_main(ilm_struct *ilm_ptr);
#endif /* __MED_ECALL_MOD__ */ 

#endif /* _AUD_MAIN_H */ /* _AUD_H */


#else /* MED_NOT_PRESENT */ 

#ifndef _AUD_MAIN_H
#define _AUD_MAIN_H

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"

#include "l1audio.h"
#include "med_struct.h"
#include "med_global.h"

/* ilm */
extern void aud_send_ilm(module_type dest_id, kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr);
extern void aud_send_in_proc_call_req( module_type src_mod_id,  media_in_proc_call_type func, kal_uint32 func_arg1, void *func_arg2);

#define aud_send_msg_to_med( src_id, msg_id, local_param_ptr ) aud_send_ilm(MOD_MED, msg_id, local_param_ptr, NULL)
#define aud_send_msg_from_med( dst_id, msg_id, local_param_ptr ) aud_send_ilm(dst_id, msg_id, local_param_ptr, NULL)
#endif /* _AUD_MAIN_H */ /* _AUD_H */

#endif /* MED_NOT_PRESENT */ 

