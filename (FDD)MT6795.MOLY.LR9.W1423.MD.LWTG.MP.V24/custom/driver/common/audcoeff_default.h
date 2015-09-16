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
 *
 * Filename:
 * ---------
 * audcoeff_default.h
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   The default value of audio coefficients
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef AUDCOEFF_COMMON_DOT_H
#define AUDCOEFF_COMMON_DOT_H

#include "l1audio.h"

#if defined(__VORBIS_ENCODE__)
#define AUDIO_RECORD_IDLE_MODE_HIGH    MEDIA_FORMAT_WAV_DVI_ADPCM_16K
#define AUDIO_RECORD_IDLE_MODE_LOW     MEDIA_FORMAT_VORBIS
#elif defined(WAV_CODEC) && defined(AMRWB_ENCODE)
#define AUDIO_RECORD_IDLE_MODE_HIGH    MEDIA_FORMAT_WAV_DVI_ADPCM_16K
#define AUDIO_RECORD_IDLE_MODE_LOW     MEDIA_FORMAT_AMR_WB
#elif defined(WAV_CODEC) && defined(AMR_CODEC)
#define AUDIO_RECORD_IDLE_MODE_HIGH    MEDIA_FORMAT_WAV_DVI_ADPCM_16K
#define AUDIO_RECORD_IDLE_MODE_LOW     MEDIA_FORMAT_AMR
#elif defined(WAV_CODEC)
#define AUDIO_RECORD_IDLE_MODE_HIGH    MEDIA_FORMAT_WAV_DVI_ADPCM_16K
#define AUDIO_RECORD_IDLE_MODE_LOW     MEDIA_FORMAT_WAV_DVI_ADPCM_16K
#elif defined(AMR_CODEC)
#define AUDIO_RECORD_IDLE_MODE_HIGH    MEDIA_FORMAT_AMR
#define AUDIO_RECORD_IDLE_MODE_LOW     MEDIA_FORMAT_AMR
#else
#define AUDIO_RECORD_IDLE_MODE_HIGH    MEDIA_FORMAT_UNKNOWN
#define AUDIO_RECORD_IDLE_MODE_LOW     MEDIA_FORMAT_UNKNOWN
#endif

#if defined(__VORBIS_ENCODE__) && defined(MT6276)
#define AUDIO_RECORD_SPEECH_MODE_HIGH    MEDIA_FORMAT_WAV_DVI_ADPCM_16K
#define AUDIO_RECORD_SPEECH_MODE_LOW     MEDIA_FORMAT_VORBIS
#elif defined(__VORBIS_ENCODE__)
#define AUDIO_RECORD_SPEECH_MODE_HIGH    MEDIA_FORMAT_WAV_DVI_ADPCM
#define AUDIO_RECORD_SPEECH_MODE_LOW     MEDIA_FORMAT_VORBIS
#elif defined(WAV_CODEC) && defined(DEDI_AMR_REC) && defined(MT6276)
#define AUDIO_RECORD_SPEECH_MODE_HIGH    MEDIA_FORMAT_WAV_DVI_ADPCM_16K
#define AUDIO_RECORD_SPEECH_MODE_LOW     MEDIA_FORMAT_AMR
#elif defined(WAV_CODEC) && defined(DEDI_AMR_REC)
#define AUDIO_RECORD_SPEECH_MODE_HIGH    MEDIA_FORMAT_WAV_DVI_ADPCM
#define AUDIO_RECORD_SPEECH_MODE_LOW     MEDIA_FORMAT_AMR
#elif defined(WAV_CODEC)
#define AUDIO_RECORD_SPEECH_MODE_HIGH    MEDIA_FORMAT_WAV_DVI_ADPCM
#define AUDIO_RECORD_SPEECH_MODE_LOW     MEDIA_FORMAT_WAV_DVI_ADPCM
#elif defined(DEDI_AMR_REC)
#define AUDIO_RECORD_SPEECH_MODE_HIGH    MEDIA_FORMAT_AMR
#define AUDIO_RECORD_SPEECH_MODE_LOW     MEDIA_FORMAT_AMR
#else
#define AUDIO_RECORD_SPEECH_MODE_HIGH    MEDIA_FORMAT_UNKNOWN
#define AUDIO_RECORD_SPEECH_MODE_LOW     MEDIA_FORMAT_UNKNOWN
#endif

#if defined( __FMRADIO_I2S_SUPPORT__ )
#define AUDIO_RECORD_FM_MODE_HIGH    AUDIO_RECORD_SPEECH_MODE_HIGH
#define AUDIO_RECORD_FM_MODE_LOW     AUDIO_RECORD_SPEECH_MODE_LOW
#else
#define AUDIO_RECORD_FM_MODE_HIGH    AUDIO_RECORD_IDLE_MODE_HIGH
#define AUDIO_RECORD_FM_MODE_LOW     AUDIO_RECORD_IDLE_MODE_LOW
#endif

#define AUDIO_RECORD_I2S_MODE_HIGH   AUDIO_RECORD_SPEECH_MODE_HIGH
#define AUDIO_RECORD_I2S_MODE_LOW    AUDIO_RECORD_SPEECH_MODE_LOW


/*
   BesBass Configuration
*/
#define DEFAULT_BBAS_LOUDSPK_CUTOFF_FREQ               500
/* The cutoff frequency of loudspeaker. Only 400, 500, 600, 700, 800 are allowed. */

#define DEFAULT_LOUDNESS_RINGTONE_MODE                 2   // for Ringtone 
#define DEFAULT_LOUDNESS_NON_RINGTONE_MODE             5   // for common audio playback

/*
 Besloudness Mode Description
 0 : BesLoudness Basic Mode
 1 : BesLoudness Enhanced Mode
 2 : BesLoudness Aggressive Mode
 3 : BesLoudness Lite Mode (loudness enhance without filtering)
 4 : Compensation Mode
 5 : Compensation Mode + BesLoudness Lite Mode 
 6 : Disable
*/

/*
 * The Bluetooth DAI Hardware COnfiguration Parameter
 */
#define DEFAULT_BLUETOOTH_SYNC_TYPE               0
#define DEFAULT_BLUETOOTH_SYNC_LENGTH             1

#define DEFAULT_DIGITAL_MIC_CHANNEL1_PHASE        3
#define DEFAULT_DIGITAL_MIC_CHANNEL2_PHASE        3
/*
phase: 0~7
*/
#define DEFAULT_DIGITAL_MIC_CLOCK_SELECTION       0
/* clock selection
0: 3P25M
1: 1P625M
*/

#if defined(__BTMODULE_MT6601__)

#define BT_COMP_FILTER (0 << 15)
#define BT_SYNC_DELAY  0

#elif defined(__BTMODULE_MT6611__)

#define BT_COMP_FILTER (1 << 15)
#define BT_SYNC_DELAY  86

#elif defined(__BTMODULE_MT6612__) || defined(__BTMODULE_MT6236__) || defined(__BTMODULE_MT6276__) || defined(__BTMODULE_MT6620__) || defined(__BTMODULE_MT6622__) || defined(__BTMODULE_MT6626__)

#define BT_COMP_FILTER (1 << 15)
#define BT_SYNC_DELAY  86

#elif defined(__BTMODULE_MT6616__)

#define BT_COMP_FILTER (1 << 15)
#define BT_SYNC_DELAY  86

#else

#define BT_COMP_FILTER (0 << 15)
#define BT_SYNC_DELAY  86

#endif
/*
 * Speech enhancement parameter
 * BT_CARKIT (from W0643; AfterW0809, BT_CARKIT replace AUX1)
 * AUX1 : undefined
 * AUX2 : undefined
 */

#if defined(MT6270A) || defined(MT6252) || defined(MT6252H) || defined(MT6236) || defined(MT6236B) || defined(MT6255) || defined(MT6250)
// KH: Must synchronize with DSP_SUPPORT_DRC in \mcu\l1audio\sp_enhance.c (asked by Pancho)
#if defined(__DUAL_MIC_SUPPORT__)
#define DEFAULT_SPEECH_NORMAL_MODE_PARA \
{ \
    96,  253, 16388,    31, 57351,    31,   400,     0, \
    80,  4325,   99,     0, 20488,   371,    23,  8192  \
}
#else
#define DEFAULT_SPEECH_NORMAL_MODE_PARA \
{ \
    96,  253, 16388,    31, 57351,    31,   400,     0, \
    80,  4325,   99,     0, 20488,     0,    0,   8192  \
}
#endif

#define DEFAULT_SPEECH_EARPHONE_MODE_PARA \
{ \
     0,   189, 10756,    31, 57351,    31,   400,     0, \
    80,  4325,    99,     0, 20488,     0,     0,     0  \
}

#define DEFAULT_SPEECH_BT_EARPHONE_MODE_PARA \
{ \
     0,   253, 10756,    31, 53255,    31,   400,     0, \
    80,  4325,    99,     0, 20488 | BT_COMP_FILTER,  0,     0, BT_SYNC_DELAY  \
}

#define DEFAULT_SPEECH_LOUDSPK_MODE_PARA \
{ \
    96,   224,  5256,    31, 57351, 24607,   400,   132, \
    80,  4325,    99,     0, 20488,     0,     0,     0  \
}

#define DEFAULT_SPEECH_CARKIT_MODE_PARA \
{ \
    96,   224,  5256,    31, 57351, 24607,   400,   132, \
    80,  4325,    99,     0, 20488,     0,     0,     0  \
}


#elif defined(MT6276) || defined(MT6573) || defined(MT6575) || defined(MT6256) || defined(MT6280) || defined(MT6577) || defined(MT6589) || defined(MT6290) || defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571) || defined(MT6595) || defined(MT6752)

#if defined(__DUAL_MIC_SUPPORT__)
#define DEFAULT_SPEECH_NORMAL_MODE_PARA \
{ \
    96,  253, 16388,    31, 57351,    31,   400,     0, \
    80,  4325,   99,     0, 20488,   371,    23,  8192  \
}
#else
#define DEFAULT_SPEECH_NORMAL_MODE_PARA \
{ \
    128,  224, 5256,    31, 57351,    31,   400,     0, \
    80,  4325,   99,     0, 8200,     0,     0,  8192  \
}
#endif

#define DEFAULT_SPEECH_EARPHONE_MODE_PARA \
{ \
     0,   189, 10756,    31, 57351,    31,   400,     0, \
    80,  4325,    99,     0, 20488,     0,     0,     0  \
}

#define DEFAULT_SPEECH_BT_EARPHONE_MODE_PARA \
{ \
     0,   253, 10756,    31, 53255, 32799,   400,     0, \
    80,  4325,    99,     0, 20488 | BT_COMP_FILTER,  0,     0, BT_SYNC_DELAY  \
}

#define DEFAULT_SPEECH_LOUDSPK_MODE_PARA \
{ \
    96,   224,  5256,    31, 57351, 16407,   400,   132, \
    80,  4325,    99,     0, 20488,     0,     0,     0  \
}

#define DEFAULT_SPEECH_CARKIT_MODE_PARA \
{ \
    96,   224,  5256,    31, 57351, 16407,   400,   132, \
    80,  4325,    99,     0, 20488,     0,     0,     0  \
}


#elif defined(FPGA)

#define DEFAULT_SPEECH_NORMAL_MODE_PARA \
{ \
0x1002,0x1000,     0,     0,       0,     0,     0,     0, \
    0,      0,     0,     0,       0,     0,     0,     0  \
}

#define DEFAULT_SPEECH_EARPHONE_MODE_PARA \
{ \
0x1002,0x1000,     0,     0,       0,     0,     0,     0, \
    0,      0,     0,     0,       0,     0,     0,     0  \
}

#define DEFAULT_SPEECH_BT_EARPHONE_MODE_PARA \
{ \
0x1002,0x1000,     0,     0,       0,     0,     0,     0, \
    0,      0,     0,     0,       0,     0,     0,     0  \
}

#define DEFAULT_SPEECH_LOUDSPK_MODE_PARA \
{ \
0x0303,0x0100,     0,     0,       0,     0,     0,     0, \
    0,      0,     0,     0,       0,     0,     0,     0  \
}

#define DEFAULT_SPEECH_CARKIT_MODE_PARA \
{ \
    0,      0,     0,     0,       0,     0,     0,     0, \
    0,      0,     0,     0,       0,     0,     0,     0  \
}

#else
#error New chip needs new default value of audio coefficients, or check l1d_cid.h for the compile option of new chip
#endif

#define DEFAULT_SPEECH_BT_CORDLESS_MODE_PARA \
{ \
    0,      0,     0,     0,       0,     0,     0,     0, \
    0,      0,     0,     0,       0,     0,     0,     0  \
}

#define DEFAULT_SPEECH_AUX1_MODE_PARA \
{ \
    0,      0,     0,     0,       0,     0,     0,     0, \
    0,      0,     0,     0,       0,     0,     0,     0  \
}

#define DEFAULT_SPEECH_AUX2_MODE_PARA \
{ \
    0,      0,     0,     0,       0,     0,     0,     0, \
    0,      0,     0,     0,       0,     0,     0,     0  \
}

#ifdef __AMRWB_LINK_SUPPORT__
#if defined(__DUAL_MIC_SUPPORT__)
#define DEFAULT_WB_SPEECH_NORMAL_MODE_PARA \
{ \
    96,   253, 16388,    31, 57607,    31,   400,     0, \
    80,  4325,    99,     0, 16392,     0,     0,  8192  \
}
#else
#define DEFAULT_WB_SPEECH_NORMAL_MODE_PARA \
{ \
    128,   224, 5256,    31, 57607,    31,   400,     0, \
    80,  4325,    99,     0, 8200,     0,     0,  8192  \
}
#endif

#define DEFAULT_WB_SPEECH_EARPHONE_MODE_PARA \
{ \
     0,   189, 10756,    31, 57607,    31,   400,     0, \
    80,  4325,    99,     0, 16392,     0,     0,     0  \
}

#define DEFAULT_WB_SPEECH_BT_EARPHONE_MODE_PARA \
{ \
     0,   253, 10756,    31, 53511, 32799,   400,     0, \
    80,  4325,    99,     0, 16392 | BT_COMP_FILTER,  0,     0, BT_SYNC_DELAY  \
}

#define DEFAULT_WB_SPEECH_LOUDSPK_MODE_PARA \
{ \
    96,   224,  5256,    31, 57607, 16407,   400,   132, \
    80,  4325,    99,     0, 16392,     0,     0,     0  \
}

#define DEFAULT_WB_SPEECH_CARKIT_MODE_PARA \
{ \
    96,   224,  5256,    31, 57607, 16407,   400,   132, \
    80,  4325,    99,     0, 16392,     0,     0,     0  \
}

#define DEFAULT_WB_SPEECH_BT_CORDLESS_MODE_PARA \
{ \
    0,      0,     0,     0,       0,     0,     0,     0, \
    0,      0,     0,     0,       0,     0,     0,     0  \
}

#define DEFAULT_WB_SPEECH_AUX1_MODE_PARA \
{ \
    96,    224,  5256,    30, 57351,     0,   400,     0,  \
    4112, 4325,    11,     0,     0,     0,     0,     0   \
}

#define DEFAULT_WB_SPEECH_AUX2_MODE_PARA \
{ \
    0,      0,     0,     0,       0,     0,     0,     0, \
    0,      0,     0,     0,       0,     0,     0,     0  \
}
#endif // end of __AMRWB_LINK_SUPPORT__

#define DEFAULT_SPEECH_VOL_PARA \
{ \
     0,     0,     0,     0 \
}

// 3D Surround effect variable default value
/*
#if defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__)
#define DEFAULT_D_DISTANCE  			55
#define DEFAULT_D_LOUDSPEAKER  			5
#define DEFAULT_SURROUNDLEVELLOUDSPEAKER  	32
#endif
*/
/*
#if defined(__BES_BASS_SUPPORT__)
// only 400, 500, 600 is valid setting
#define DEFAULT_BASS_LOUDSPEAKER_CUTOFF  	600
#endif
*/

#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
#ifdef __AMRWB_LINK_SUPPORT__
#define DEFAULT_WB_DMNR_PARAM \
{ \
	460, 470, 480, 490, 500, \
	510, 520, 530, 540, 550, \
	560, 570, 580, 590, 600, \
	610, 620, 630, 640, 650, \
	660, 670, 680, 690, 700, \
	710, 720, 730, 740, 750, \
	760, 770, 780, 790, 800, \
	810, 820, 830, 840, 850, \
	860, 870, 880, 890, 900, \
	910, 920, 930, 940, 950, \
	960, 970, 980, 990, 1000, \
	1010, 1020, 1030, 1040, 1050, \
	1060, 1070, 1080, 1090, 1200, \
	1210, 1220, 1230, 1240, 1250, \
	1260, 1270, 1280, 1290, 1300, \
	1310		\
}

#define DEFAULT_LSPK_WB_DMNR_PARAM \
{ \
	460, 470, 480, 490, 500, \
	510, 520, 530, 540, 550, \
	560, 570, 580, 590, 600, \
	610, 620, 630, 640, 650, \
	660, 670, 680, 690, 700, \
	710, 720, 730, 740, 750, \
	760, 770, 780, 790, 800, \
	810, 820, 830, 840, 850, \
	860, 870, 880, 890, 900, \
	910, 920, 930, 940, 950, \
	960, 970, 980, 990, 1000, \
	1010, 1020, 1030, 1040, 1050, \
	1060, 1070, 1080, 1090, 1200, \
	1210, 1220, 1230, 1240, 1250, \
	1260, 1270, 1280, 1290, 1300, \
	1310		\
}

#endif
#define DEFAULT_DMNR_PARAM \
{ \
	0, 0, 0, 0, 0, \
	0, 0, 0, 0, 0, \
	0, 0, 0, 0, 0, \
	0, 0, 0, 0, 0, \
	0, 0, 0, 0, 0, \
	0, 0, 0, 0, 0, \
	0, 0, 0, 0, 0, \
	0, 0, 0, 0, 0, \
	68, 0, 0, 0 \
}

#define DEFAULT_LSPK_DMNR_PARAM \
{ \
	0, 0, 0, 0, 0, \
	0, 0, 0, 0, 0, \
	0, 0, 0, 0, 0, \
	0, 0, 0, 0, 0, \
	0, 0, 0, 0, 0, \
	0, 0, 0, 0, 0, \
	0, 0, 0, 0, 0, \
	0, 0, 0, 0, 0, \
	68, 0, 0, 0 \
}

#endif

#endif // ... AUDCOEFF_COMMON_DOT_H
