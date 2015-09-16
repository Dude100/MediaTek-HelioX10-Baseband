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
 *   med_struct.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary global variables of media task.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

//kmoly
#ifndef _MED_STRUCT_H
#define _MED_STRUCT_H

#include "kal_general_types.h"
#include "kal_public_api.h"

#define MAX_MEDIA_FILE_NAME 512

#define WB_SPEECH_FIR_COEFF_NUM 90
#define SPEECH_FIR_COEFF_NUM 45
#define MELODY_FIR_COEFF_NUM 25
#define AUDIO_COMP_COEFF_NUM 45

#define EMSD_DATA_LEN 140


/* start up */
typedef struct
{
    LOCAL_PARA_HDR
}
med_startup_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
med_startup_cnf_struct;


typedef void (*media_in_proc_call_type) (kal_uint32 arg1, void *arg2);

typedef struct
{
    LOCAL_PARA_HDR
    media_in_proc_call_type func;
    kal_uint32 func_arg1;
    void *func_arg2;
}
media_in_proc_call_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 result;
    void *result_p;
}
media_in_proc_call_cnf_struct;

/* audio */

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 mode;
}
media_aud_set_audio_mode_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    kal_uint16 cause;
}
media_aud_set_audio_mode_cnf_struct;

typedef struct
{
    kal_uint8 mode;
    kal_uint8 melody[7];
    kal_uint8 sound[7];
    kal_uint8 keytone[7];
    kal_uint8 speech[7];
    kal_uint8 mic[7];
    kal_uint8 sidetone;
    kal_uint8 max_melody_volume_gain;
    kal_uint8 melody_volume_gain_step;
    kal_uint8 tv_out_volume_gain[7];
}
audio_profile_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool update_nvram;
    audio_profile_struct audio_profile;
}
media_aud_set_audio_profile_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    kal_uint16 cause;
}
media_aud_set_audio_profile_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 mode;
}
media_aud_get_audio_profile_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    audio_profile_struct audio_profile;
}
media_aud_get_audio_profile_cnf_struct;

typedef struct
{
    kal_int16 coeff[6][WB_SPEECH_FIR_COEFF_NUM];
}
audio_wb_speech_fir_struct;

typedef struct
{
    kal_int16 param[8][16];
}
audio_wb_speech_mode_struct;

typedef struct
{
    kal_int16 speech_input_FIR_coeffs[6][SPEECH_FIR_COEFF_NUM];
    kal_int16 speech_output_FIR_coeffs[6][SPEECH_FIR_COEFF_NUM];
    kal_uint16 selected_FIR_output_index;
    kal_uint16 speech_common_para[12];
    kal_uint16 speech_mode_para[8][16];
    kal_uint16 speech_volume_para[3][7][4];
    kal_uint16 max_swing;
    kal_int16 Melody_FIR_Coeff_Tbl[MELODY_FIR_COEFF_NUM];
    kal_int16 audio_compensation_coeff[3][AUDIO_COMP_COEFF_NUM]; /* LOUDSPEAKER/EARPHONE/LOUDSPEAKER_RINGTONE */
}
audio_param_struct;

#ifdef __DUAL_MIC_SUPPORT__

typedef struct
{
    /* Volume */
    kal_int16 vol_calibration_shift[8];
    kal_int16 vol_calibration_subband[8];
    /* Delay */
    kal_int16 delay_cal_int;
    kal_int16 delay_cal_frac;
    kal_int16 delay_cal_subband[8];
    /* Leakage */
    kal_int16 power_ratio_scale;
    kal_int16 wind_index_threshold;
    kal_int16 subband_bmg[8];
    /*Mockup Diagnosis*/
    kal_int16 mockup_level;
    kal_int16 shielding_level;
    kal_int16 NR_Level;
    /* Reserve */
    kal_int16 reserve[5];
}
audio_dual_mic_nb_param_struct;

typedef struct 
{           
    /* Volume */
    kal_int16 vol_calibration_shift[16];
    kal_int16 vol_calibration_subband[16];
    /* Delay */
    kal_int16 delay_cal_int;
    kal_int16 delay_cal_frac;
    kal_int16 delay_cal_subband[16];
    /* Leakage */
    kal_int16 power_ratio_scale;
    kal_int16 wind_index_threshold;
    kal_int16 subband_bmg[16];
    /*Mockup Diagnosis*/
    kal_int16 mockup_level;
    kal_int16 shielding_level;    
    kal_int16 NR_Level;        
    /* Reserve */
    kal_int16 reserve[5];
}
audio_dual_mic_wb_param_struct;

typedef struct
{
    audio_dual_mic_nb_param_struct nb_param; /* narrow band parameter*/
    audio_dual_mic_wb_param_struct wb_param; /* wide band parameter */
    audio_dual_mic_nb_param_struct lspk_nb_param; /* narrow band parameter*/
    audio_dual_mic_wb_param_struct lspk_wb_param; /* wide band parameter */
}
audio_dual_mic_param_struct;

#endif // #define __DUAL_MIC_SUPPORT__

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool update_nvram;
    audio_param_struct audio_param;
}
media_aud_set_audio_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    kal_uint16 cause;
}
media_aud_set_audio_param_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
media_aud_get_audio_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    audio_param_struct audio_param;
}
media_aud_get_audio_param_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool update_nvram;
    audio_wb_speech_fir_struct fir_param;
}
media_aud_set_audio_wb_input_fir_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    kal_uint16 cause;
}
media_aud_set_audio_wb_input_fir_param_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool update_nvram;
    audio_wb_speech_fir_struct fir_param;
}
media_aud_set_audio_wb_output_fir_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    kal_uint16 cause;
}
media_aud_set_audio_wb_output_fir_param_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool update_nvram;
    audio_wb_speech_mode_struct mode;
}
media_aud_set_audio_wb_mode_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    kal_uint16 cause;
}
media_aud_set_audio_wb_mode_param_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
media_aud_get_audio_wb_input_fir_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    audio_wb_speech_fir_struct fir_param;
}
media_aud_get_audio_wb_input_fir_param_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
media_aud_get_audio_wb_output_fir_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    audio_wb_speech_fir_struct fir_param;
}
media_aud_get_audio_wb_output_fir_param_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
media_aud_get_audio_wb_mode_param_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    audio_wb_speech_mode_struct fir_param;
}
media_aud_get_audio_wb_mode_param_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 volume_type;
}
media_aud_get_volume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    kal_uint8 volume_type;
    kal_uint8 volume;
}
media_aud_get_volume_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 audio_type;
    kal_uint8 device;
}
media_aud_set_device_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
media_aud_set_device_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint64 volume;      /* volume data */
    kal_uint8 audio_type;   /* volume type */
    kal_uint8 aux_volume;   /* no use */
    kal_uint8 mode;         /* no use */
    kal_bool apply;         /* use for media type only */
    kal_bool blocking;
}
media_aud_set_volume_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
media_aud_set_volume_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool monitor; /* KAL_TRUE: open monitor, KAL_FALSE: close monitor */
}
media_aud_emsd_monitor_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    kal_bool cause_present;
    kal_uint8 cause;
}
media_aud_emsd_monitor_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 data[EMSD_DATA_LEN];
}
media_aud_emsd_set_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    kal_bool cause_present;
    kal_uint8 cause;
}
media_aud_emsd_set_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
media_aud_emsd_push_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    kal_bool cause_present;
    kal_uint8 cause;
}
media_aud_emsd_push_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_aud_emsd_pull_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool result;
    kal_bool cause_present;
    kal_uint8 cause;
}
media_aud_emsd_hack_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_aud_emsd_lack_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
}
media_aud_emsd_sync_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool monitor; /* KAL_TRUE: open monitor, KAL_FALSE: close monitor */
}
media_aud_emsd_psap_monitor_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    kal_bool cause_present;
    kal_uint8 cause;
}
media_aud_emsd_psap_monitor_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
media_aud_emsd_psap_pull_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_bool result;
    kal_bool cause_present;
    kal_uint8 cause;
}
media_aud_emsd_psap_pull_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 data[EMSD_DATA_LEN];
}
media_aud_emsd_psap_data_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint64 volume;
    kal_uint16 identifier;
    kal_uint8 audio_id;
    kal_uint8 play_style;
    kal_uint8 output_path;
}
media_aud_play_by_id_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
media_aud_play_by_id_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 audio_id;
}
media_aud_stop_by_id_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
media_aud_stop_by_id_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint64 volume;
    /* set both start_offset and end_offset to 0 for backward compatible */
    kal_uint32 start_offset;    /* 0 : file begining */
    kal_uint32 end_offset;      /* 0 or file data len-1: file end */
    void* cache_p;              /* cache */
    kal_wchar file_name[MAX_MEDIA_FILE_NAME];
    kal_uint16 identifier;
    kal_uint8 src_id;
    kal_uint8 play_style;
    kal_uint8 output_path;
}
media_aud_play_by_file_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
media_aud_play_by_file_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
media_aud_stop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
media_aud_stop_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint64 volume;
    const kal_uint8 *melody;
    kal_uint32 len;
    kal_uint32 start_offset;
    kal_uint32 end_offset;
    kal_uint16 identifier;
    kal_uint8 src_id;
    kal_uint8 format;
    kal_uint8 play_style;
    kal_uint8 output_path;
    kal_uint8 blocking;
}
media_aud_play_by_string_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
media_aud_play_by_string_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
}
media_aud_stop_by_string_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 src_id;
    kal_uint8 result;
}
media_aud_stop_by_string_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 identifier;
    kal_uint8 result;
}
media_aud_play_finish_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 device;
    kal_bool mute;
}
media_aud_mute_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
media_aud_mute_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 input_idx;
    kal_int16 output_idx;
}
media_aud_sp_set_fir_coeff_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 mode;
    kal_bool is_with_param;
    kal_uint16 param[16];
    kal_uint16 wb_param[16];
}
media_aud_sp_set_enhance_mode_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool speech_on;
    kal_uint8 rat_mode;
}
meida_aud_sp_set_mode_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 result;
}
media_aud_sp_set_mode_cnf_struct;


#endif /* _MED_STRUCT_H */
