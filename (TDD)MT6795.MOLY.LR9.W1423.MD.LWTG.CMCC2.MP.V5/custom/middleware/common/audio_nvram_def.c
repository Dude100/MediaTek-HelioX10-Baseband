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
 * audio_nvram_def.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef NVRAM_NOT_PRESENT

/*
 *   Include Headers
 */

#include "kal_general_types.h"

/*
 *   NVRAM Basic Headers
 */
#ifdef NVRAM_AUTO_GEN
#include "nvram_auto_gen.h"
#endif

#include "nvram_enums.h"
#include "nvram_defs.h"
#include "nvram_data_items.h"

/*
 *   User Headers
 */
#include "audio_nvram_def.h"


/*
 *   Default value
 */

#include "nvram_default_audio.h"
#include "AudCoeff.h"
#include "audcoeff_default.h"

/**
	Default values for each LID struture
*/


#if !defined(MED_NOT_PRESENT)

static nvram_ef_audio_param_struct const NVRAM_EF_AUDIO_PARAM_DEFAULT[NVRAM_EF_AUDIO_PARAM_TOTAL]
= { 
	{
		SPEECH_INPUT_FIR_COEFF_DEFAULT,
		SPEECH_OUTPUT_FIR_COEFF_DEFAULT,
		0, //selected_FIR_output_index
		DEFAULT_SPEECH_COMMON_PARA, //speech_common_para
		{
			DEFAULT_SPEECH_NORMAL_MODE_PARA,
			DEFAULT_SPEECH_EARPHONE_MODE_PARA,			
			DEFAULT_SPEECH_LOUDSPK_MODE_PARA,
			DEFAULT_SPEECH_BT_EARPHONE_MODE_PARA,
			DEFAULT_SPEECH_BT_CORDLESS_MODE_PARA,
			DEFAULT_SPEECH_CARKIT_MODE_PARA,			
			DEFAULT_SPEECH_AUX1_MODE_PARA,
			DEFAULT_SPEECH_AUX2_MODE_PARA,
		}, //speech_mode_para
		{
			{{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0}},
			{{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0}},
			{{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0},{0, 0, 0, 0}}
		}, //speech_volume_para
		DEFAULT_MEDIA_PLAYBACK_MAXIMUM_SWING, //Media_Playback_Maximum_Swing
		DEFAULT_MELODY_FIR, //Melody_FIR_Coeff_Tbl
		DEFAULT_COMPENSATION_FLT //audio_compensation_coeff
	}
};

#ifdef __BES_LOUDNESS_SUPPORT__
static nvram_ef_audio_besloudness_struct const NVRAM_EF_AUDIO_BESLOUDNESS_DEFAULT[NVRAM_EF_AUDIO_BESLOUDNESS_TOTAL]
= {
	{
		DEFAULT_AUDIO_COMPENSATION_HSF_COEFFS, //audio_besloudness_hsf_coeffs
		DEFAULT_AUDIO_COMPENSATION_BPF_COEFFS,//audio_besloudness_bpf_coeffs
		DEFAULT_BESLOUDNESS_GAIN_PROFILE_FORGET_FACT_TABLE,//audio_besloudness_DRC_Forget_Table
		DEFAULT_BESLOUDNESS_WS_GAIN_MAX, //audio_besloudness_WS_Gain_Max
		DEFAULT_BESLOUDNESS_WS_GAIN_MIN, //audio_besloudness_WS_Gain_Min
		DEFAULT_BESLOUDNESS_FILTER_FIRST, //audio_besloudness_Filter_First
		DEFAULT_BESLOUDNESS_GAINMAP_IN, //audio_besloudness_Gain_Map_In
		DEFAULT_BESLOUDNESS_GAINMAP_OUT //audio_besloudness_Gain_Map_Out
	}
};
#endif //__BES_LOUDNESS_SUPPORT__

#ifdef __AUDIO_COMPENSATION_SW_VERSION__
static nvram_ef_audio_swfir_struct const NVRAM_EF_AUDIO_SWFIR_DEFAULT[NVRAM_EF_AUDIO_SWFIR_TOTAL]
= {
	{DEFAULT_AUDIO_COMPENSATION_FILTER_SW}
};
#endif

#ifdef __AMRWB_LINK_SUPPORT__
//TODO: [MSBB] remove usage to med structure
//static nvram_ef_audio_wb_speech_input_fir_coeff_struct const NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_COEFF_DEFAULT[NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_TOTAL] 
static audio_wb_speech_fir_struct const NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_COEFF_DEFAULT[NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_TOTAL] 
= {
	{WB_SPEECH_INPUT_FIR_COEFF_DEFAULT}
};
//static nvram_ef_audio_wb_speech_output_fir_coeff_struct const NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_COEFF_DEFAULT[NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_TOTAL] 
static audio_wb_speech_fir_struct const NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_COEFF_DEFAULT[NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_TOTAL] 
= {
	{WB_SPEECH_OUTPUT_FIR_COEFF_DEFAULT}
};
//static nvram_ef_audio_wb_speech_mode_param_struct const NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_DEFAULT[NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_TOTAL]
static audio_wb_speech_mode_struct const NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_DEFAULT[NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_TOTAL]
= {
	{
		{
			DEFAULT_WB_SPEECH_NORMAL_MODE_PARA,
			DEFAULT_WB_SPEECH_EARPHONE_MODE_PARA,
			DEFAULT_WB_SPEECH_LOUDSPK_MODE_PARA,
			DEFAULT_WB_SPEECH_BT_EARPHONE_MODE_PARA,
			DEFAULT_WB_SPEECH_BT_CORDLESS_MODE_PARA,
			DEFAULT_WB_SPEECH_CARKIT_MODE_PARA,
			DEFAULT_WB_SPEECH_AUX1_MODE_PARA,
			DEFAULT_WB_SPEECH_AUX2_MODE_PARA
		}
	}
};

#endif

#if defined(__DUAL_MIC_SUPPORT__)
//static nvram_ef_audio_dual_mic_param_struct const NVRAM_EF_AUDIO_DUAL_MIC_PARAM_DEFAULT[NVRAM_EF_AUDIO_DUAL_MIC_PARAM_TOTAL]
static audio_dual_mic_param_struct const NVRAM_EF_AUDIO_DUAL_MIC_PARAM_DEFAULT[NVRAM_EF_AUDIO_DUAL_MIC_PARAM_TOTAL]
={
	{
		DEFAULT_DMNR_PARAM,
	#if defined(__AMRWB_LINK_SUPPORT__) 
		DEFAULT_WB_DMNR_PARAM
	#else
		{ \
			0, 0, 0, 0, 0,    0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,    0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,    0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,    0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,    0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,    0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,    0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,    0
		}
	#endif //__AMRWB_LINK_SUPPORT__
		, DEFAULT_LSPK_DMNR_PARAM,
	#if defined(__AMRWB_LINK_SUPPORT__) 
		DEFAULT_LSPK_WB_DMNR_PARAM
	#else
		{ \
			0, 0, 0, 0, 0,    0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,    0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,    0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,    0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,    0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,    0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,    0, 0, 0, 0, 0,
			0, 0, 0, 0, 0,    0
		}
	#endif //__AMRWB_LINK_SUPPORT__
	}
};
#endif //__DUAL_MIC_SUPPORT__

static nvram_ef_audio_dc_calibration_struct const NVRAM_EF_AUDIO_DC_CALIBRATION_DEFAULT[NVRAM_EF_AUDIO_DC_CALIBRATION_TOTAL]
= { {0} };

/*
 *   LID table
 */

ltable_entry_struct logical_data_item_table_audio[] =
{
    {
        NVRAM_EF_CUST_ACOUSTIC_DATA_LID,
        NVRAM_EF_CUST_ACOUSTIC_DATA_TOTAL,
        NVRAM_EF_CUST_ACOUSTIC_DATA_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_CUST_ACOUSTIC_DATA_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT6A",
        VER(NVRAM_EF_CUST_ACOUSTIC_DATA_LID)
    },
    
    {
        NVRAM_EF_AUDIO_PARAM_LID,
        NVRAM_EF_AUDIO_PARAM_TOTAL,
        NVRAM_EF_AUDIO_PARAM_SIZE,
        NVRAM_NORMAL(NVRAM_EF_AUDIO_PARAM_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIPLE,
        "MT6B",
        VER(NVRAM_EF_AUDIO_PARAM_LID)
    },

#ifdef __BES_LOUDNESS_SUPPORT__
    {
        NVRAM_EF_AUDIO_BESLOUDNESS_LID,
        NVRAM_EF_AUDIO_BESLOUDNESS_TOTAL,
        NVRAM_EF_AUDIO_BESLOUDNESS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_AUDIO_BESLOUDNESS_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT6C",
        VER(NVRAM_EF_AUDIO_BESLOUDNESS_LID)
    },
#endif/*__BES_LOUDNESS_SUPPORT__*/

#ifdef __AMRWB_LINK_SUPPORT__
    {
        NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID,
        NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_TOTAL,
        NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_COEFF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIPLE,
        "MT6O",
        VER(NVRAM_EF_AUDIO_WB_SPEECH_INPUT_FIR_LID)
    },
    
    {
        NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_LID,
        NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_TOTAL,
        NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_COEFF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIPLE,
        "MT6P",
        VER(NVRAM_EF_AUDIO_WB_SPEECH_OUTPUT_FIR_LID)
    },
    
    {
        NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_LID,
        NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_TOTAL,
        NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_SIZE,
        NVRAM_NORMAL(NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIPLE,
        "MT6Q",
        VER(NVRAM_EF_AUDIO_WB_SPEECH_MODE_PARAM_LID)
    },
#endif /* __AMRWB_LINK_SUPPORT__ */

#ifdef __GAIN_TABLE_SUPPORT__
    {
        NVRAM_EF_AUDIO_GAIN_TABLE_LID,
        NVRAM_EF_AUDIO_GAIN_TABLE_TOTAL,
        NVRAM_EF_AUDIO_GAIN_TABLE_SIZE,
        NVRAM_NORMAL((kal_uint8 const *)NVRAM_EF_AUDIO_GAIN_TABLE_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT6R",
        VER(NVRAM_EF_AUDIO_GAIN_TABLE_LID)
    },
#endif /* __GAIN_TABLE_SUPPORT__ */
    
    {
        NVRAM_EF_AUDIO_DC_CALIBRATION_LID,
        NVRAM_EF_AUDIO_DC_CALIBRATION_TOTAL,
        NVRAM_EF_AUDIO_DC_CALIBRATION_SIZE,
        NVRAM_NORMAL(NVRAM_EF_AUDIO_DC_CALIBRATION_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT6W",
        VER(NVRAM_EF_AUDIO_DC_CALIBRATION_LID)
    },
    
#ifdef __AUDIO_COMPENSATION_SW_VERSION__
    {
        NVRAM_EF_AUDIO_SWFIR_LID,
        NVRAM_EF_AUDIO_SWFIR_TOTAL,
        NVRAM_EF_AUDIO_SWFIR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_AUDIO_SWFIR_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT6X",
        VER(NVRAM_EF_AUDIO_SWFIR_LID)
    },
#endif/*__AUDIO_COMPENSATION_SW_VERSION__*/

#if defined(__DUAL_MIC_SUPPORT__)
    {
        NVRAM_EF_AUDIO_DUAL_MIC_PARAM_LID,
        NVRAM_EF_AUDIO_DUAL_MIC_PARAM_TOTAL,
        NVRAM_EF_AUDIO_DUAL_MIC_PARAM_SIZE,
        NVRAM_NORMAL(NVRAM_EF_AUDIO_DUAL_MIC_PARAM_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIPLE,
        "MT6Z",
        VER(NVRAM_EF_AUDIO_DUAL_MIC_PARAM_LID)
    },
#endif //__DUAL_MIC_SUPPORT__

};

#elif !defined(__MTK_TARGET__)

ltable_entry_struct logical_data_item_table_audio[] =
{
    {
        NVRAM_LID_GRP_AUDIO(0),
        1,
        1,
        NVRAM_NORMAL_NOT_GEN(0),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT6A",
        0
    },
};

#endif

#endif /* NVRAM_NOT_PRESENT */
