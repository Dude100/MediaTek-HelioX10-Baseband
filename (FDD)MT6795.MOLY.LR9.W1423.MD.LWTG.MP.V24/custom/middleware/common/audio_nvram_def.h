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
 * audio_nvram_def.h
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __AUDIO_NVRAM_DEF_H__
#define __AUDIO_NVRAM_DEF_H__

#if !defined(MED_NOT_PRESENT)

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

/*
 *   Include Headers
 */
#include "med_struct.h"

/*
 *   NVRAM Basic Headers
 */
#include "nvram_data_items.h"
#include "nvram_defs.h"


/*
 *   User Headers
 */


/*
 *   LID Enums
 */
 
typedef enum
{
    NVRAM_EF_CUST_ACOUSTIC_DATA_LID             = NVRAM_LID_GRP_AUDIO(0),
    NVRAM_EF_AUDIO_PARAM_LID                    = NVRAM_LID_GRP_AUDIO(1),
    NVRAM_EF_AUDIO_BESLOUDNESS_LID              = NVRAM_LID_GRP_AUDIO(2),
    NVRAM_EF_AUDIO_GAIN_TABLE_LID               = NVRAM_LID_GRP_AUDIO(3),
    NVRAM_EF_AUDIO_SWFIR_LID                    = NVRAM_LID_GRP_AUDIO(4),

    /* WB speech */
    NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID      = NVRAM_LID_GRP_AUDIO(5),
    NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_LID     = NVRAM_LID_GRP_AUDIO(6),
    NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_LID     = NVRAM_LID_GRP_AUDIO(7),

    /* Dual Mic */
    NVRAM_EF_AUDIO_DUAL_MIC_PARAM_LID           = NVRAM_LID_GRP_AUDIO(8),
    NVRAM_EF_AUDIO_DC_CALIBRATION_LID           = NVRAM_LID_GRP_AUDIO(9),

/*
 *  Last LID of GPS Group
 */
    NVRAM_EF_AUDIO_LAST_LID                     = NVRAM_LID_GRP_AUDIO(255)
}nvram_lid_audio_enum;


/*
 *   Verno
 */
#define NVRAM_EF_AUDIO_PARAM_STRUCT_VERNO                   "01"
#define NVRAM_EF_AUDIO_PARAM_DEFAULT_VERNO                  "0"
#define NVRAM_EF_AUDIO_PARAM_LID_VERNO                      NVRAM_EF_AUDIO_PARAM_STRUCT_VERNO NVRAM_EF_AUDIO_PARAM_DEFAULT_VERNO


#define NVRAM_EF_AUDIO_BESLOUDNESS_STRUCT_VERNO             "10"
#define NVRAM_EF_AUDIO_BESLOUDNESS_DEFAULT_VERNO            "1"
#define NVRAM_EF_AUDIO_BESLOUDNESS_LID_VERNO                NVRAM_EF_AUDIO_BESLOUDNESS_STRUCT_VERNO NVRAM_EF_AUDIO_BESLOUDNESS_DEFAULT_VERNO

#define NVRAM_EF_CUST_ACOUSTIC_DATA_LID_VERNO               "000"
#define NVRAM_EF_AUDIO_DC_CALIBRATION_LID_VERNO             "000" 
#define NVRAM_EF_AUDIO_SWFIR_LID_VERNO                      "000"  
#ifdef __AMRWB_LINK_SUPPORT__
#define NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID_VERNO  "000"
#define NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_LID_VERNO "000"
#define NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_LID_VERNO "000"
#endif /* __AMRWB_LINK_SUPPORT__ */

#if defined(__DUAL_MIC_SUPPORT__)
#define NVRAM_EF_AUDIO_DUAL_MIC_PARAM_LID_VERNO  "000"
#endif

#ifdef __GAIN_TABLE_SUPPORT__
#define NVRAM_EF_AUDIO_GAIN_TABLE_LID_VERNO           "000"
#endif /* __GAIN_TABLE_SUPPORT__ */


/*
 * Record Size/Total Records
 */

#define NVRAM_EF_AUDIO_PARAM_COUNT    1
#define NVRAM_EF_AUDIO_PARAM_SIZE     sizeof(nvram_ef_audio_param_struct)
#define NVRAM_EF_AUDIO_PARAM_TOTAL    1

#ifdef __BES_LOUDNESS_SUPPORT__
#define NVRAM_EF_AUDIO_BESLOUDNESS_COUNT    1
#define NVRAM_EF_AUDIO_BESLOUDNESS_SIZE     sizeof(nvram_ef_audio_besloudness_struct)
#define NVRAM_EF_AUDIO_BESLOUDNESS_TOTAL    1
#endif /* __BES_LOUDNESS_SUPPORT__ */ 

#define NVRAM_EF_AUDIO_DC_CALIBRATION_COUNT    1
#define NVRAM_EF_AUDIO_DC_CALIBRATION_SIZE     sizeof(nvram_ef_audio_dc_calibration_struct)
#define NVRAM_EF_AUDIO_DC_CALIBRATION_TOTAL    1
#ifdef __AMRWB_LINK_SUPPORT__
/*
 * WB speech FIR coefficients
 */
#define NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_COUNT    1
#define NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_SIZE     sizeof(audio_wb_speech_fir_struct)
#define NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_TOTAL    1

#define NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_COUNT   1
#define NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_SIZE    sizeof(audio_wb_speech_fir_struct)
#define NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_TOTAL   1

#define NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_COUNT   1
#define NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_SIZE    sizeof(audio_wb_speech_mode_struct)
#define NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_TOTAL   1
#endif /* __AMRWB_LINK_SUPPORT__ */

#ifdef __AUDIO_COMPENSATION_SW_VERSION__
#define NVRAM_EF_AUDIO_SWFIR_COUNT    1
#define NVRAM_EF_AUDIO_SWFIR_SIZE     sizeof(nvram_ef_audio_swfir_struct)
#define NVRAM_EF_AUDIO_SWFIR_TOTAL    1
#endif /* __AUDIO_COMPENSATION_SW_VERSION__ */ 

#if defined(__DUAL_MIC_SUPPORT__)
#define NVRAM_EF_AUDIO_DUAL_MIC_PARAM_COUNT   1
#define NVRAM_EF_AUDIO_DUAL_MIC_PARAM_SIZE    sizeof(audio_dual_mic_param_struct)
#define NVRAM_EF_AUDIO_DUAL_MIC_PARAM_TOTAL   1
#endif

    /*
     * Audio Equalizer Settings
     */
#define NVRAM_EF_AUDIO_EQUALIZER_COUNT    8
#define NVRAM_EF_AUDIO_EQUALIZER_SIZE     500
#define NVRAM_EF_AUDIO_EQUALIZER_TOTAL    1

/*
 *   Data Structure
 */
typedef struct
{
   kal_uint32 audio_besloudness_hsf_coeffs[9][4];
   kal_uint32 audio_besloudness_bpf_coeffs[4][6][3];
   kal_uint32 audio_besloudness_DRC_Forget_Table[9][2];
   kal_uint32 audio_besloudness_WS_Gain_Max;          
   kal_uint32 audio_besloudness_WS_Gain_Min;          
   kal_uint32 audio_besloudness_Filter_First;          
   kal_int8   audio_besloudness_Gain_Map_In[5];                
   kal_int8   audio_besloudness_Gain_Map_Out[5];               
} nvram_ef_audio_besloudness_struct;

typedef struct
{
    kal_uint16 dc_offset;
} nvram_ef_audio_dc_calibration_struct;


typedef struct
{
    kal_int16 audio_compensation_filter_sw_ver_coeffs[3][3][45];
} nvram_ef_audio_swfir_struct;

typedef struct
{
    kal_int16 speech_input_FIR_coeffs[6][45];
    kal_int16 speech_output_FIR_coeffs[6][45];
    kal_uint16 selected_FIR_output_index;
    kal_uint16 speech_common_para[12];
    kal_uint16 speech_mode_para[8][16];
    kal_uint16 speech_volume_para[3][7][4];
    kal_uint16 Media_Playback_Maximum_Swing;
    kal_int16 Melody_FIR_Coeff_Tbl[25];
    kal_int16 audio_compensation_coeff[3][45];
} nvram_ef_audio_param_struct;

extern nvram_ltable_entry_struct logical_data_item_table_audio[];

#ifdef __cplusplus
}
#endif 

#endif

#endif /* __AUDIO_NVRAM_DEF_H__ */ 
