/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *
 * Filename:
 * ---------
 * aud_custom_exp.h
 *
 * Project:
 * --------
 *   DUMA
 *
 * Description:
 * ------------
 * This file is the header of audio customization related function or definition.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Revision:$
 * $Modtime:$
 * $Log:$
 * 
 * removed!
 * removed!
 * Sync Mode number
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Check in MT6255 related modfication.
 *
 * removed!
 * removed!
 * 
 * DMNR calibration format changing. (MAUI)
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * [DUMA00002520] Check in Mic bias and audio customization message
 * 
 *
 * removed!
 * [DUMA00001411] Add LoudSpeaker enable
 * 
 *
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by CC/CQ. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef AUDIO_CUSTOM_EXP_H
#define AUDIO_CUSTOM_EXP_H


/* audio nvram structure definition*/

typedef struct _AUDIO_CUSTOM_PARAM_STRUCT
{
   /* volume setting */
   char volume[3][7];
   /* speech enhancement */
   unsigned short speech_common_para[12];
   unsigned short speech_mode_para[8][16];
   unsigned short speech_volume_para[4];//in the feature, should extend to [MAX_VOL_CATE][MAX_VOL_TYPE][4]
   /* debug info */
   unsigned short debug_info[16];
   /* speech input FIR */
   short          sph_in_fir[6][45];
   /* speech output FIR */
   short          sph_out_fir[6][45];
   /* digital gain of DL speech */
   unsigned short Digi_DL_Speech;
   /* digital gain of uplink speech */
   unsigned short Digi_Microphone;
   /* FM record volume*/
   unsigned short FM_Record_Volume;    
   /* user mode : normal mode, earphone mode, loud speaker mode */
   unsigned short Bluetooth_Sync_Type;
   unsigned short Bluetooth_Sync_Length;
   unsigned short bt_pcm_in_vol;
   unsigned short bt_pcm_out_vol;
   unsigned short user_mode;
   /* auto VM record setting */
   unsigned short bSupportVM;
   unsigned short bAutoVM;
   unsigned short uMicbiasVolt;
} AUDIO_CUSTOM_PARAM_STRUCT;

typedef struct _AUDIO_CUSTOM_WB_PARAM_STRUCT_
{
   /* WB speech enhancement */
   unsigned short speech_mode_wb_para[8][16];
   /* WB speech input FIR */
   short          sph_wb_fir[6][90];
   /* WB speech output FIR */
   short          input_out_fir_flag; // 0: input, 1: output
} AUDIO_CUSTOM_WB_PARAM_STRUCT;


#define SPC_MAX_NUM_RECORD_SPH_MODE 30
#define SPC_MAX_NUM_RECORD_INPUT_FIR 8

typedef struct _AUDIO_HD_RECORD_PARAM_STRUCT
{
    /* HD RECORD Param Num*/
    unsigned short hd_rec_mode_num; // max(hd_rec_fir_num) == 16 ??
    unsigned short hd_rec_fir_num; //max(hd_rec_fir_num) == 4 ?? 
    
    /* HD RECORD Speech Enhancement */
    unsigned short hd_rec_speech_mode_para[SPC_MAX_NUM_RECORD_SPH_MODE][NUM_MODE_PARAS]; 
    
    /* HD RECORD FIR */
    short          hd_rec_fir[SPC_MAX_NUM_RECORD_INPUT_FIR][NUM_WB_FIR_COEFFS];
    
    /* HD RECORD Mapping (ex, mapping[mode] =  hd_rec_fir's index) */
    unsigned short hd_rec_map_to_fir_for_ch1[SPC_MAX_NUM_RECORD_SPH_MODE];
    unsigned short hd_rec_map_to_fir_for_ch2[SPC_MAX_NUM_RECORD_SPH_MODE];
		
	unsigned char  hd_rec_map_to_device_mode [SPC_MAX_NUM_RECORD_SPH_MODE];
	

	/* HD RECORD Input Source Mapping (ex, map[sph_mode] = BT Earphone mic)*/
	/* Only use in AP side, here is keeping the structure the same*/
    unsigned char hd_rec_map_to_input_src[SPC_MAX_NUM_RECORD_SPH_MODE];

    /* HD RECORD mode is stereo or not (ex, map[sph_mode] = 0(mono), 1(stereo) )*/
	/* Only use in AP side, here is keeping the structure the same*/
    unsigned char hd_rec_map_to_stereo_flag[SPC_MAX_NUM_RECORD_SPH_MODE];
    
} AUDIO_HD_RECORD_PARAM_STRUCT;


#define     NUM_DMNR_PARAM 44
#define		NUM_WB_DMNR_PARAM 76
typedef struct _AUDIO_CUSTOM_DMNR_PARAM_STRUCT_
{
   /* NB DMNR parameters */
   unsigned short DMNR_para[NUM_DMNR_PARAM];
   /* WB DMNR parameters */
   unsigned short WB_DMNR_para[NUM_WB_DMNR_PARAM];
} AUDIO_CUSTOM_DMNR_PARAM_STRUCT;


#endif
