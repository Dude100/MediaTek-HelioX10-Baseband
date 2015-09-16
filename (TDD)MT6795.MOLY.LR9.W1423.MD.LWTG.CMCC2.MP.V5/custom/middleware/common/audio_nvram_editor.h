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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * audio_nvram_editor.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file contains `vendor' defined logical data items stored in NVRAM.
 *    These logical data items are used in object code of Protocol Stack software.
 *
 *    As for customizable logical data items, they are defined in nvram_user_config.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __AUDIO_NVRAM_EDITOR_H__
#define __AUDIO_NVRAM_EDITOR_H__
#ifndef NVRAM_NOT_PRESENT

#if !defined(MED_NOT_PRESENT)

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

/*
 *   Include Headers
 */


/*
 *   NVRAM Basic Headers
 */
#include "nvram_data_items.h"
 
/*
 *   User Headers
 */
#include "audio_nvram_def.h"

/*
 *   Default value
 */
#include "nvram_default_audio.h"


/*
 *   Bit Level Description Language
 */
#ifdef GEN_FOR_PC
BEGIN_NVRAM_DATA

#if !defined(L4_NOT_PRESENT)
/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_CUST_ACOUSTIC_DATA_LID
  ***
  ***  Module: UEM
  ***
  ***  Description:
  ***
  ***  Maintainer: JL Lee, Robin Jian
  ***
  ***********************************************************************/
    LID_BIT VER_LID(NVRAM_EF_CUST_ACOUSTIC_DATA_LID)
     custom_acoustic_struct *NVRAM_EF_CUST_ACOUSTIC_DATA_TOTAL
     {
         volume_gain:"Volume Gain:[Mode (Normal, Headset, LoudSpk)][Tone type (Tone, Keytone, MIC, Sound, Speech, SideTone, Melody) ][Level (1~7)]";
         volume:"Current Volume Level[Mode (Normal, Headset, LoudSpk)][Tone type (Tone, Keytone, MIC, Sound, Speech, SideTone, Melody) ]";
         max_melody_volume_gain: "Max Melody Volume Gain [Mode (Normal, Headset, LoudSpk, TvOut)]";
         melody_volume_gain_step: "Melody Volume Gain Step [Mode (Normal, Headset, LoudSpk, TvOut)]";
         tv_out_volume_gain: "Tv Out Melody Volume Gain";
     };
#endif

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_ALS_LINE_ID_LID
  ***
  ***  Module:
  ***
  ***  Description:
  ***
  ***  Maintainer: Paul Yuang
  ***
  ***********************************************************************/
     LID_BIT MULTIPLE_LID NVRAM_EF_AUDIO_PARAM_STRUCT_VERNO NVRAM_EF_AUDIO_PARAM_LID
     nvram_ef_audio_param_struct *NVRAM_EF_AUDIO_PARAM_TOTAL
     {
       speech_input_FIR_coeffs:"speech_input_FIR_coeffs"
         {
         };
       speech_output_FIR_coeffs: "speech_output_FIR_coeffs"
         {
         };
       selected_FIR_output_index:"selected_FIR_output_index"
         {
         };
       speech_common_para:"speech_common_para"
         {
         };
       speech_mode_para: "speech_mode_para"
         {
         };
       speech_volume_para: "speech_volume_para"
         {
         };
       Media_Playback_Maximum_Swing:"Media_Playback_Maximum_Swing"
         {
         };
       Melody_FIR_Coeff_Tbl:"Melody_FIR_Coeff_Tbl"
         {
         };
       audio_compensation_coeff:"audio_compensation_coeff"
         {
         };
     };

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_AUDIO_BESLOUDNESS_LID
  ***
  ***  Module: L1AUDIO
  ***
  ***  Description: Audio BesLoudness parameter
  ***
  ***  Maintainer: Wn Chen
  ***
  ***********************************************************************/
#if defined(__BES_LOUDNESS_SUPPORT__)
LID_BIT NVRAM_EF_AUDIO_BESLOUDNESS_STRUCT_VERNO NVRAM_EF_AUDIO_BESLOUDNESS_LID
     nvram_ef_audio_besloudness_struct *NVRAM_EF_AUDIO_BESLOUDNESS_TOTAL
     {
         audio_besloudness_hsf_coeffs:"BESLOUDNESS HPF Coeffs"
         {
         };
         audio_besloudness_bpf_coeffs:"BESLOUDNESS BPF Coeffs"
         {
         };
         audio_besloudness_DRC_Forget_Table:"BESLOUDNESS DRC forget table"
         {
         };
         audio_besloudness_WS_Gain_Max:"BESLOUDNESS WS gain max"
         {
         };
         audio_besloudness_WS_Gain_Min:"BESLOUDNESS WS gain min"
         {
         };
         audio_besloudness_Filter_First:"BESLOUDNESS Filter first"
         {
         };
         audio_besloudness_Gain_Map_In:"BESLOUDNESS Gain Map in"
         {
         };
         audio_besloudness_Gain_Map_Out:"BESLOUDNESS Gain Map out"
         {
         };
    };
#endif

/***********************************************************************
  ***  This is a nvram data item bit level description for meta tools nvram editor
  ***
  ***  Logical Data Item ID : NVRAM_EF_AUDIO_SWFIR_LID
  ***
  ***  Module: L1AUDIO
  ***
  ***  Description: Audio Compensation Filter SW version cofficients
  ***
  ***  Maintainer: Wn Chen
  ***
  ***********************************************************************/
#if defined(__AUDIO_COMPENSATION_SW_VERSION__)
LID_BIT VER_LID(NVRAM_EF_AUDIO_SWFIR_LID)
     nvram_ef_audio_swfir_struct *NVRAM_EF_AUDIO_SWFIR_TOTAL
     {
         audio_compensation_filter_sw_ver_coeffs:"AUDIO COMPENSATION SWFIR Coeffs"
         {
         };
    };
#endif

#ifdef __AMRWB_LINK_SUPPORT__
     LID_BIT VER_LID(NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID)
     audio_wb_speech_fir_struct *NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_TOTAL
     {
     };

     LID_BIT VER_LID(NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_LID)
     audio_wb_speech_fir_struct *NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_TOTAL
     {
     };

     LID_BIT VER_LID(NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_LID)
     audio_wb_speech_mode_struct *NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_TOTAL
     {
     };
#endif /* __AMRWB_LINK_SUPPORT__ */

#if defined(__DUAL_MIC_SUPPORT__)
    LID_BIT VER_LID(NVRAM_EF_AUDIO_DUAL_MIC_PARAM_LID)
    audio_dual_mic_param_struct *NVRAM_EF_AUDIO_DUAL_MIC_PARAM_TOTAL
    {
    };
#endif


#ifdef __GAIN_TABLE_SUPPORT__
    LID_BIT VER_LID(NVRAM_EF_AUDIO_GAIN_TABLE_LID)
    nvram_gain_table_struct * NVRAM_EF_AUDIO_GAIN_TABLE_TOTAL
    {
    };
#endif /* __GAIN_TABLE_SUPPORT__ */


END_NVRAM_DATA

#endif  /* GEN_FOR_PC */
#endif
#endif  /* !NVRAM_NOT_PRESENT */
#endif  /* __AUDIO_NVRAM_EDITOR_H__ */
