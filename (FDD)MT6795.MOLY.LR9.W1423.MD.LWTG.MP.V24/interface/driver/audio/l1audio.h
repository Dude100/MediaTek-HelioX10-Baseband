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
 *  l1sp.h
 *
 * Project:
 * --------
 *   MTK6208
 *
 * Description:
 * ------------
 *   Audio Task interface definition
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.119  $
 * $Modtime:   Jul 25 2005 16:49:38  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/interface/l1audio/l1audio.h-arc  $
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * HAC
 *
 * removed!
 * removed!
 * 	Support MUTE_NOTIFY for LTECSR.
 *
 * removed!
 * removed!
 * Merge VoLTE to LR9.W1423.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * 	Back out changelist 541440
 *
 * removed!
 * removed!
 * Support Frame Aggregation
 *
 * removed!
 * removed!
 * MagConconference Control
 *
 * removed!
 * removed!
 * reorg speech enhancement
 *
 * removed!
 * removed!
 * MagiConference - part 1, EM sending
 *
 * removed!
 * removed!
 * pnw check-in
 * Merging	//MOLY_CBr/sheila.chen/MOLY_95It/mcu/driver/audio/src/...
 * to //MOLY/TRUNK/MOLY/mcu/driver/audio/src/...
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
 * remove unused code
 *
 * removed!
 * removed!
 * remove unused comment / #if 0, #endif
 *
 * removed!
 * removed!
 * remove unused function. Media_SetOutputVolume
 *
 * removed!
 * removed!
 * Remove unused code. (mainly on w32_audio.c simulation functions)
 *
 * removed!
 * removed!
 * remove unused code
 *
 * removed!
 * removed!
 * remove unused code
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Lenovo's new feature for MT6582 & MT657
 *
 * removed!
 * removed!
 * Add Set Speech Mode remind note
 *
 * removed!
 * removed!
 * Warming removal 3
 * 
 * Fix CTM potential bug
 * 
 * removed!
 * removed!
 * WB FIR coefficient
 *  settubg
 * 
 * removed!
 * removed!
 * 1. Add WB enhancement
 * 2. Temp workaround for TD MD2
 * 
 * removed!
 * removed!
 * Chip Rename to MT6589
 * Remove unused AFE functions
 * Phase in phone call usage
 * 
 * removed!
 * removed!
 * Sync Mode number
 * 
 * removed!
 * removed!
 * Remove phase out function --> PCM playback via speech path (DSP not support)
 * 
 * removed!
 * removed!
 * Remove unused functions --> Line-in related
 * 
 * removed!
 * removed!
 * Remove phase out function - L1SP_SetDualMicNR
 * 
 * removed!
 * removed!
 * Remove unused function.
 * 
 * removed!
 * removed!
 * Phase-in CTM
 *  (v1) without debug
 * 
 * removed!
 * removed!
 * Phase in background sound and SAL
 * 
 * removed!
 * removed!
 * Phase in background sound and SAL
 * 
 * 07 31 2012 kh.hung
 * removed!
 * .
 *
 * 05 14 2012 kh.hung
 * removed!
 * .
 *
 * 12 22 2011 wn.chen
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef L1AUDIO_H
#define L1AUDIO_H


#include "kal_general_types.h"
#include "kal_public_defs.h"

#ifdef __MTK_TARGET__
  #include "fs_type.h"
  #include "fsal.h"
#else
  #include "fsal.h"
#endif

#define MED_STAT_AUDIO_START          200


/* ------------------------------------------------------------------------------ */
/*  Function ptr prototype [HAL rule]                                             */ 
/* ------------------------------------------------------------------------------ */
// For In Process Call
typedef void (*in_proc_call_type)( kal_uint32 arg1, void* arg2 );

typedef void*      (*fp_audio_alloc_aud_mem)(kal_uint32 size, char* file_p, long line_p);
typedef void       (*fp_audio_free_aud_mem)(void** ptr, char* file_p, long line_p);
typedef void       (*fp_audio_set_path_volume)(kal_uint8 audio_mode);
typedef kal_uint8  (*fp_audio_get_active_mode)(void);
typedef void       (*fp_send_proc_call_req)(module_type src_mod_id, in_proc_call_type func, kal_uint32 func_arg1, void *func_arg2);
typedef kal_bool   (*fp_get_meta_data_file)(kal_wchar *filename, void *aud_info_p);
typedef kal_bool   (*fp_get_meta_data_array)(kal_char *ptr, kal_uint32 size, void *aud_info_p);


extern void *audio_alloc_ext_mem (kal_int32 size,char* file_p, long line_p);
extern void *audio_alloc_ext_mem_cacheable (kal_int32 size,char* file_p, long line_p);
extern void  audio_free_ext_mem (void **ptr,char* file_p, long line_p);

#define audio_alloc_mem(size)	            audio_alloc_ext_mem(size,__FILE__,__LINE__)
#define audio_alloc_mem_cacheable(size)   audio_alloc_ext_mem_cacheable(size,__FILE__,__LINE__)
#define audio_free_mem(ptr)               audio_free_ext_mem(ptr,__FILE__,__LINE__)


typedef struct {
   fp_audio_alloc_aud_mem      alloc_mem;          
   fp_audio_alloc_aud_mem      alloc_mem_cacheable;                                    
   fp_audio_free_aud_mem       free_mem;  
   fp_audio_set_path_volume    set_path_volume;
   fp_audio_get_active_mode    get_active_mode; 
   fp_send_proc_call_req       send_proc_call;
   fp_send_proc_call_req       send_proc_call2;
   fp_get_meta_data_file       get_meta_file;
   fp_get_meta_data_array      get_meta_array;
} Media_Func_Reg_Type;

void  Audio_MedFuncReg(Media_Func_Reg_Type *func);

typedef void       (*fp_a2dp_set_br_from_qos_init)(kal_uint32 bit_rate_cur);
typedef kal_uint32 (*fp_a2dp_set_br_from_qos)(kal_uint8 qos, kal_uint32 bit_rate_prev, kal_uint32 (*SetCodecBitRate)(kal_uint32));


/* ------------------------------------------------------------------------------ */
/*  Audio memory allocation.                                                      */
/* ------------------------------------------------------------------------------ */
#if defined(MT6276)
   #define  MAX_AUDIO_FUNCTIONS     30
#else
   //#define  MAX_AUDIO_FUNCTIONS     18
   //for new tone interface, MD-DSP and MD-MCU can generate tone at the same time.
   #define  MAX_AUDIO_FUNCTIONS     20
#endif

/* ------------------------------------------------------------------------------ */
/*  Audio Function Definition                                                     */
/* ------------------------------------------------------------------------------ */
#define  L1SP_KEYTONE         0
#define  L1SP_TONE            1
#define  L1SP_SPEECH          2
#define  L1SP_SND_EFFECT      3
#define  L1SP_AUDIO           4
#define  L1SP_VOICE           5
#define  L1SP_DAI             6
#define  L1SP_LINEIN          7
#define  L1SP_MAX_AUDIO       8

#define  SRC_VOICE_DAC        0
#define  SRC_AUDIO_DAC        1
#define  SRC_EXT_INPUT        2

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

#define  INVALID_AUDIO_ID        MAX_AUDIO_FUNCTIONS

typedef  void  (*L1Audio_EventHandler)(void*);

kal_int8 L1Audio_Disable_DSPSlowIdle(void);
kal_int8 L1Audio_Enable_DSPSlowIdle(void);

/*
typedef enum {
  MEDIA_BGSND,
  MEDIA_PCM_PLAYBACK,
  MEDIA_VM_PLAYBACK
} Media_Func_Type;

void L1Audio_Register_Handle(Media_Func_Type type, void *hdl);
void L1Audio_UnRegister_Handle(Media_Func_Type type);
*/

void        L1Audio_SendILM(kal_uint16 msg_id, module_type src_module, module_type dst_module, void *local_param_ptr, void *peer_buf_ptr);
kal_uint16  L1Audio_GetAudioID( void );
void        L1Audio_FreeAudioID( kal_uint16 aud_id );
kal_bool    L1Audio_CheckAudioID( kal_uint16 audio_id );
void        L1Audio_SetEventHandler( kal_uint16 audio_id, L1Audio_EventHandler handler );
void        L1Audio_SetEvent( kal_uint16 audio_id, void *data );
void        L1Audio_LSetEvent( kal_uint16 audio_id, void *data );
kal_bool    L1Audio_CheckFlag( kal_uint16 audio_id );
void        L1Audio_SetFlag( kal_uint16 audio_id );
void        L1Audio_ClearFlag( kal_uint16 audio_id );
void        L1Audio_AllowSleep( kal_uint16 audio_id );
void        L1Audio_DisallowSleep( kal_uint16 audio_id );
void        L1Audio_HookHisrHandler( kal_uint16 magic_no, L1Audio_EventHandler handler, void *userData );
void        L1Audio_UnhookHisrHandler( kal_uint16 magic_no );
// void        L1Audio_SetPostHisrHandler( L1Audio_EventHandler handler );
// void        L1Audio_ResetPostHisrHandler( void );

void        L1Audio_ResetDevice( void );

void        L1Audio_SetDebugInfoN( kal_uint16 index, kal_uint16 debug_info );

#define  NUM_DEBUG_INFO      9
#define  VM_DEBUG_INFO       0
#define  VOIPEVL_DEBUG_INFO  1
#define  AMR_REC_DEBUG_INFO  2
#define  AWB_REC_DEBUG_INFO  3
#define  APM_DEBUG_INFO      4
#define  STEREO_RECORD_INFO  5
#define  AUDIO_DEBUG_MISC    6  // factory mode audio debug parameter 6
#define  CTM_DEBUG_INFO      7
#define  AVB_DEBUG_INFO      8

/* -------------------------------- */
/*  AUDIO_DEBUG_MISC Definition     */
/* -------------------------------- */
#define  AAC_DSCE_CHANNEL_CHANGE 3000
#define  AUDIO_DBG_INFOVAL_AUDLP_DISABLE   32768


void        L1Audio_SetDebugInfo( kal_uint16 debug_info[NUM_DEBUG_INFO]);
kal_uint16  L1Audio_GetDebugInfo( kal_uint8 index );
/* ------------------------------------------------------------------------------ */
/*  Audio Front End Interface                                                     */
/* ------------------------------------------------------------------------------ */
/* -------------------------------- */
/*  Audio Output Device Definition  */
/* -------------------------------- */
#define  L1SP_BUFFER_0        0x01    /* NOTE: Don't use buffer definition directly   */
#define  L1SP_BUFFER_1        0x02    /*       Use speaker definition below           */
#define  L1SP_BUFFER_ST       0x04
#define  L1SP_BUFFER_EXT      0x08
#define  L1SP_BUFFER_EXT_G    0x10
#define  L1SP_STEREO2MONO     0x20     /* Do not use this term for speaker definition */
#define  L1SP_BUFFER_ST_M     (L1SP_BUFFER_ST|L1SP_STEREO2MONO)
#define  L1SP_EXT_DAC_BUF0    0x40 
#define  L1SP_EXT_DAC_BUF1    0x80

#define  L1SP_LNA_0           0
#define  L1SP_LNA_1           1
#define  L1SP_LNA_DIGITAL     2
#define  L1SP_LNA_FMRR        3

extern const kal_uint8  L1SP_MICROPHONE1;
extern const kal_uint8  L1SP_MICROPHONE2;
extern const kal_uint8  L1SP_SPEAKER1;
extern const kal_uint8  L1SP_SPEAKER2;
extern const kal_uint8  L1SP_LOUD_SPEAKER;


#define  EXT_DAC_I2S          0x1 
#define  EXT_DAC_LINEIN       0x2 
extern const unsigned char  L1SP_EXT_DAC_I2S_BCLK_SCALE;
extern const unsigned char  L1SP_EXT_DAC_STEP; // the minimum step that has change of volume      
extern const unsigned char  L1SP_EXT_DAC_STEP_UNIT; // the times of 0.5dB in the minimum volume change    
extern const unsigned char  L1SP_I2S_INPUT_SCALE;
extern void EXT_DAC_Init( void ); 
extern void EXT_DAC_SetPlaybackFreq( kal_uint16 frequency ); 
extern void EXT_DAC_TurnOnSpeaker( kal_uint8 src, kal_uint8 spk );
extern void EXT_DAC_TurnOffSpeaker( kal_uint8 spk ); 
extern void EXT_DAC_SetVolume( kal_uint8 spk, kal_uint8 vol );
extern void EXT_DAC_FixedLineInGain( kal_uint8 spk );
extern void I2S_Input_GPIO_TurnOn( void );
extern void I2S_Input_GPIO_TurnOff( void );

/* ------------------------------------------------------------------------------ */
/*  Audio Related Global Variables                                                */
/* ------------------------------------------------------------------------------ */
extern const signed short     Speech_Input_FIR_Coeff[6][45];
extern const signed short     Speech_Output_FIR_Coeff[6][45];
#ifdef __AMRWB_LINK_SUPPORT__
extern const signed short     WB_Speech_Input_FIR_Coeff[6][90];
extern const signed short     WB_Speech_Output_FIR_Coeff[6][90];
#endif

// extern const unsigned short   Media_Playback_Maximum_Swing;
extern const signed short     Melody_FIR[25];

extern const unsigned short   DG_DL_Speech;
extern const unsigned short   DG_Microphone;
extern const unsigned short   DG_DAF;
extern const unsigned short   DG_MIDI;
extern const unsigned short   DG_IMY;
extern const unsigned short   DG_IMY_NOTE;
extern const unsigned short   DG_SMF_NOTE;
extern const unsigned short   DG_JTS_NOTE;

/* ------------------------------------------------------------------------------ */
/*  Key Tone Interface                                                            */
/* ------------------------------------------------------------------------------ */
typedef enum {
  DSP_TONE = 0,
  MCU_TONE,
  TOTAL_TONE_NUM
}TONE_TYPE;

void  KT_SetOutputDevice( kal_uint8 device );
void  KT_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index );
void  KT_Play( kal_uint16 freq1, kal_uint16 freq2, kal_uint16 duration, TONE_TYPE type);
void  KT_Stop( TONE_TYPE type );
void  KT_StopAndWait(void);
void  KT_SetAmplitude( kal_int16 amp );
void  KT_SetFIR( kal_bool enable );
kal_bool KT_IsPlayable(void);

/* ------------------------------------------------------------------------------ */
/*  Tone Interface                                                                */
/* ------------------------------------------------------------------------------ */
typedef struct {
   kal_uint16   freq1;         /* First frequency                              */
   kal_uint16   freq2;         /* Second frequency                             */
   kal_uint16   on_duration;   /* Tone on duation(ms), 0 for continuous tone   */
   kal_uint16   off_duration;  /* Tone off duation(ms), 0 for end of playing   */
   kal_int8     next_tone;     /* Index of the next tone                       */
} L1SP_Tones;

typedef struct {
   kal_uint16   freq1;         /* First frequency                              */
   kal_uint16   freq2;         /* Second frequency                             */
   kal_uint16   on_duration;   /* Tone on duation(ms), 0 for continuous tone   */
   kal_uint16   off_duration;  /* Tone off duation(ms), 0 for end of playing   */
   kal_int8     next_tone;     /* Index of the next tone                       */
   kal_uint16   freq3;         /* Third frequency                              */
   kal_uint16   freq4;         /* Fourth frequency                             */
} L1SP_QTMF;

/* -------------------------------- */
/*  Example of Tone Definition      */
/* -------------------------------- */
/*
static const L1SP_Tones tone1_gsm[] = { { 425,   0,   0,   0,   0 } };
static const L1SP_Tones tone1_pcs[] = { { 350, 440,   0,   0,   0 } };
static const L1SP_Tones tone2_gsm[] = { { 425,   0, 500, 500,   0 } };
static const L1SP_Tones tone2_pcs[] = { { 480, 620, 500, 500,   0 } };
static const L1SP_Tones tone3_gsm[] = { { 425,   0, 200, 200,   0 } };
static const L1SP_Tones tone3_pcs[] = { { 480, 620, 200, 200,   0 } };
static const L1SP_Tones tone4[]     = { { 425,   0, 200,   0,   0 } };
static const L1SP_Tones tone5[]     = { { 425,   0, 200, 200,   1 },
                                        { 425,   0, 200, 200,   2 },
                                        { 425,   0, 200,   0,   0 } };
static const L1SP_Tones tone61[]    = { { 950,   0, 330,1000,   0 } };
static const L1SP_Tones tone62[]    = { {1400,   0, 330,1000,   0 } };
static const L1SP_Tones tone63[]    = { {1800,   0, 330,1000,   0 } };
static const L1SP_Tones tone7[]     = { { 425,   0, 200, 600,   1 },
                                        { 425,   0, 200,3000,   2 },
                                        { 425,   0, 200, 600,   3 },
                                        { 425,   0, 200,   0,   0 } };
*/

void  TONE_SetOutputDevice( kal_uint8 device );
void  TONE_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index );
void  TONE_Play( const L1SP_Tones *tonelist, TONE_TYPE type );
void  TONE_Stop( TONE_TYPE type );
void  TONE_StopAndWait( void );
void  TONE_SetAmplitude( kal_int16 amp );
void  TONE_SetFIR( kal_bool enable );
void  TONE_SetHandler( void (*handler)(void), TONE_TYPE type );
void  TONE_PlayQTMF( const L1SP_QTMF *tonelist ); /* QTMF Play Interface */

void  SP4G_PSR_DL_KT_Play(kal_int16 freq1, kal_int16 freq2, kal_int16 duration);
void  SP4G_PSR_DL_KT_Stop( void );
void  SP4G_PSR_UL_KT_Play(kal_int16 freq1, kal_int16 freq2, kal_int16 duration);
void  SP4G_PSR_UL_KT_Stop( void );

void  SP4G_PSR_UL_Tone_Play(const L1SP_Tones *pToneList );
void  SP4G_PSR_UL_Tone_Stop( void );
void  SP4G_PSR_DL_Tone_Play(const L1SP_Tones *pToneList );
void  SP4G_PSR_DL_Tone_Stop( void );

/* ------------------------------------------------------------------------------ */
/*  Speech Interface                                                              */
/* ------------------------------------------------------------------------------ */
 typedef enum {
  L1SP_NVRAM_INFO_INDEX_UNDEF = 0,
  L1SP_NVRAM_INFO_INDEX_PARAM,
  L1SP_NVRAM_INFO_INDEX_WB_SPEECH_INPUT_FIR,
  L1SP_NVRAM_INFO_INDEX_WB_SPEECH_OUTPUT_FIR,
  L1SP_NVRAM_INFO_INDEX_WB_SPEECH_MODE_PARAM,
  L1SP_NVRAM_INFO_INDEX_HD_RECORD,  
} L1SP_NVRAM_INFO_INDEX;

void        L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX index,kal_uint8* buffer, kal_uint16 len);

void        L1SP_SetOutputDevice( kal_uint8 device );
void        L1SP_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index );
void        L1SP_Speech_On( kal_uint8 RAT_Mode );
void        L1SP_Speech_Off( void );
void        L1SP_SetInputSource( kal_uint8 src );
kal_uint8   L1SP_GetInputSource( void );
void        L1SP_SetMicrophoneVolume( kal_uint8 mic_volume );
kal_uint8   L1SP_GetMicrophoneVolume( void );
void        L1SP_MuteSpeaker( kal_bool mute );
void        L1SP_MutePCMOuputPort ( kal_bool fMute );
void        L1SP_SetSidetoneVolume( kal_uint8 sidetone );
kal_uint8   L1SP_GetSidetoneVolume( void );
void        L1SP_MuteMicrophone( kal_bool mute );
kal_bool    L1SP_IsMicrophoneMuted( void );
void        L1SP_SetFIR( kal_bool enable );
void        L1SP_Set_DAI_Mode( kal_uint8 mode );
// void        l1sp_Write_Audio_Coefficients( const kal_int16 in_coeff[30], const kal_int16 out_coeff[30] );
// void L1SP_Write_Audio_Coefficients_ByFirIndex( const kal_uint8 inOrOut2FirIndex, const kal_uint8 outFirIndex); 

void        L1SP_SetAfeLoopback( kal_bool enable );
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

kal_bool    L1SP_IsBluetoothOn( void );
kal_bool    L1SP_IsSpeechOn( void );
// void        L1SP_EnableSpeechEnhancement( kal_bool enable );
#define     FIRST_MIC (0)
// kal_uint32  L1SP_GetFrameIntensity(kal_uint32 channel);

// void        l1sp_Write_WB_Audio_Coefficients( const kal_int16 in_coeff[90], const kal_int16 out_coeff[90] );
// void        L1SP_UpdateSpeechPara(kal_uint16 sph_m_para[16] );//NUM_MAX_MODE_PARAS
void        L1SP_LoadSpeechPara( void );
// void        L1SP_Init_PCMPlayback(kal_uint8 sph_mode, kal_bool bDigitalGain, kal_uint16 digital_gain);

#define     NUM_DMNR_PARAM (44)
#define     NUM_WB_DMNR_PARAM (76)
#define     NUM_ABF_PARAM  (44)
void        L1SP_SetDMNRPara( const kal_int16 DMNR_para[NUM_DMNR_PARAM] );
void        L1SP_SetLSpkDMNRPara( const kal_int16 LSpk_DMNR_para[NUM_DMNR_PARAM] );
#if defined(__AMRWB_LINK_SUPPORT__)
void        L1SP_SetWbDMNRPara( const kal_int16 WB_DMNR_para[NUM_WB_DMNR_PARAM] );
void        L1SP_SetLSpkWbDMNRPara( const kal_int16 LSpk_Wb_DMNR_para[NUM_WB_DMNR_PARAM] );
#endif



/* deprecated function is replaced with functioins which have prefix "L1SP" */
void        AcousticLoopbackOn (void);
void        AcousticLoopbackOff (void);
void        AcousticLoopbackSpeechMode (kal_uint8 u1Mode);
kal_bool    AcousticLoopbackStatus(void);
void        AcousticLoopbackBypassMode (kal_uint8 u1Mode);
void        AcousticLoopbackLength (kal_uint32 u4Length);

#define     L1SP_DEFAULT_ACOUSTIC_LOOPBACK_LENGTH (1024) 
void        L1SP_AcousticLoopbackOn (void);
void        L1SP_AcousticLoopbackOff (void);
void        L1SP_AcousticLoopbackSpeechMode (kal_uint8 u1Mode);
kal_bool    L1SP_AcousticLoopbackStatus(void);
void        L1SP_AcousticLoopbackBypassMode (kal_uint8 u1Mode);
void        L1SP_AcousticLoopbackLength (kal_uint32 u4Length);


void        ABF_SetAcousticLoopback( kal_bool loopback );
kal_bool    ABF_GetAcousticLoopbackStatus( void );


/*******************************************************************/
/*   The new interface for DSP speech enhancement function / Bluetooth */
/*******************************************************************/
#define SPH_MODE_NORMAL  0
#define SPH_MODE_EARPHONE  1
#define SPH_MODE_LOUDSPK  2
#define SPH_MODE_BT_EARPHONE 3
#define SPH_MODE_BT_CORDLESS 4
#define SPH_MODE_BT_CARKIT   5
#define SPH_MODE_AUX1  6
#define SPH_MODE_AUX2  7
#define SPH_MODE_HAC   8
#define SPH_MODE_LINEIN_VIA_BT_CORDLESS 9
#define SPH_MODE_UNDEFINED  10

#define NUM_SPH_MODE      8
#define NUM_SPH_INPUT_FIR  6
#define NUM_SPH_OUTPUT_FIR 6

#define SPH_FIR_COEFF_NORMAL           0
#define SPH_FIR_COEFF_HEADSET          1
#define SPH_FIR_COEFF_HANDFREE         2
#define SPH_FIR_COEFF_BT               3
#define SPH_FIR_COEFF_VOIP_NORMAL      4
#define SPH_FIR_COEFF_VOIP_HANDFREE    5
#define SPH_FIR_COEFF_HAC              6


#define NUM_COMMON_PARAS  12
#define NUM_MODE_PARAS   16
#define NUM_VOL_PARAS     4

#define NUM_FIR_COEFFS    45
#define NUM_WB_FIR_COEFFS    90


void L1SP_LoadCommonSpeechPara( kal_uint16 c_para[NUM_COMMON_PARAS] );

// void L1SP_SetSpeechVolumeLevel( kal_uint8 level, kal_uint16 v_para[NUM_VOL_PARAS] );
kal_uint8 L1SP_GetSpeechMode( void );

/**
	this function is to replace L1SP_SetSpeechVolumeLevel()
	
	@level: [input] speech volume level for speech
	@v_paraIndex: [input] volume paramter (saving in nvram) index
*/
void L1SP_SetSpeechVolumeLevelByIndex(kal_uint8 level, kal_uint8 v_paraIndex);

typedef enum {
	SPH_ENH_AND_FIR_SCENE_NORMAL = 0, //from 0 to 8, it is one to one mapping to speech mode. ie. SPH_MODE_NORMAL to SPH_MODE_LINEIN_VIA_BT_CORDLESS
	SPH_ENH_AND_FIR_SCENE_EARPHONE,
	SPH_ENH_AND_FIR_SCENE_LOUDSPK,
	SPH_ENH_AND_FIR_SCENE_BT_EARPHONE,
	SPH_ENH_AND_FIR_SCENE_BT_CORDLESS,
	SPH_ENH_AND_FIR_SCENE_BT_CARKIT, 
	SPH_ENH_AND_FIR_SCENE_AUX1,
	SPH_ENH_AND_FIR_SCENE_AUX2,
	SPH_ENH_AND_FIR_SCENE_HAC,
#ifndef __SMART_PHONE_MODEM__
	SPH_ENH_AND_FIR_SCENE_LINEIN_VIA_BT_CORDLESS,

	//VOIP related mode
	SPH_ENH_AND_FIR_SCENE_VOIP_NORMAL,
	SPH_ENH_AND_FIR_SCENE_VOIP_LOADSPK,

	//CTM related
	SPH_ENH_AND_FIR_SCENE_CTM_BAUDOT,
	SPH_ENH_AND_FIR_SCENE_CTM_DIRECT,

	SPH_ENH_AND_FIR_SCENE_CTM_HCO_NORMAL, // using Eng Mode's selected_FIR_output_index to decide which is 
	SPH_ENH_AND_FIR_SCENE_CTM_HCO_EARPHONE,
	SPH_ENH_AND_FIR_SCENE_CTM_HCO_LOUDSPK,
	SPH_ENH_AND_FIR_SCENE_CTM_HCO_BT,
	SPH_ENH_AND_FIR_SCENE_CTM_HCO_VOIP_NORMAL,
	SPH_ENH_AND_FIR_SCENE_CTM_HCO_VOIP_LOUDSPK,

	SPH_ENH_AND_FIR_SCENE_CTM_VCO_NORMAL,
	SPH_ENH_AND_FIR_SCENE_CTM_VCO_EARPHONE,
	SPH_ENH_AND_FIR_SCENE_CTM_VCO_LOUDSPK,
	SPH_ENH_AND_FIR_SCENE_CTM_VCO_BT,
	SPH_ENH_AND_FIR_SCENE_CTM_VCO_VOIP_NORMAL,
	SPH_ENH_AND_FIR_SCENE_CTM_VCO_VOIP_LOUDSPK,
	
	SPH_ENH_AND_FIR_SCENE_INCALL_END, // useless, just make as the ending point for in-call scene

#ifdef __HD_RECORD__
	#include "aud_hdRecord_scene.h"
#endif //__HD_RECORD__

#endif // __SMART_PHONE_MODEM__ not exist
    
	SPH_ENH_AND_FIR_SCENE_UNDEF = 0xFFFF,  
} SPH_ENH_AND_FIR_SCENE;

typedef enum {
	SPH_ENH_AND_FIR_UPDATE_TYPE_ALL = 0,
	SPH_ENH_AND_FIR_UPDATE_TYPE_NB_ENH_MODE = 0x2,
	SPH_ENH_AND_FIR_UPDATE_TYPE_NB_FIR = 0x4,	
	SPH_ENH_AND_FIR_UPDATE_TYPE_WB_ENH_MODE = 0x8,
	SPH_ENH_AND_FIR_UPDATE_TYPE_WB_FIR = 0x10,
	
} SPH_ENH_AND_FIR_UPDATE_TYPE;

/**
	new interface to replace L1SP_SetSpeechMode(), L1SP_Write_Audio_Coefficients(), 
	L1SP_Write_WB_Audio_Coefficients() in the same time. 

	if you want to use personal configuration, you can use original interfaces. 

	@scene: [Input] scenario for different enhancement and fir combination. Please refer to "SPH_ENH_AND_FIR_SCENE"
	@updatedCoeff: [Input] Please refer to "SPH_ENH_AND_FIR_UPDATE_TYPE"
*/
void L1SP_SetSpeechEnhanceAndFir(kal_uint32 scene, kal_uint32 updatedCoeff);

/**
	MED can get nvram values from this function.
	
	@index: [Input] Identify which LID is going to provide
	@buffer: [Output] Buffer with the contain the result
	@len: [Input] Length of the output buffer
*/
void L1SP_GetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX index, void *buffer, kal_uint16 len);
#define LEN_OF_ENHANCEMENT_MODE_NAME 30

#define LEN_OF_ENHANCEMENT_CATEGORY_NAME 20
/**
	user: should be META only
	(realted to customer folder)
	
	@return: number of all enhancement category
*/
kal_int16 L1SP_GetNumOfAllEnhancementCategory(void);



/* ------------------------------------------------------------------------------ */
/*  Media File Playback/Recording Interface (TOBE REMOVE                                      */
/* ------------------------------------------------------------------------------ */
typedef enum {
   MEDIA_SUCCESS = MED_STAT_AUDIO_START,
   MEDIA_FAIL,
   MEDIA_REENTRY,                /* media reentry error                       */
   MEDIA_NOT_INITIALIZED,        /* media control is not initialized          */
   MEDIA_BAD_FORMAT,             /* media format error                        */
   MEDIA_BAD_PARAMETER,          /* media bad parameter error                 */
   MEDIA_BAD_COMMAND,            /* media bad command error                   */
   MEDIA_NO_HANDLER,             /* media no handler error                    */
   MEDIA_UNSUPPORTED_CHANNEL,    /* unsupported audio channel count           */
   MEDIA_UNSUPPORTED_FREQ,       /* unsupported audio freqency                */
   MEDIA_UNSUPPORTED_TYPE,       /* unsupported audio content                 */
   MEDIA_UNSUPPORTED_OPERATION,   /* unsupported operation on such audio type  */
   MEDIA_SEEK_FAIL,              /* seek fail indicator */
   MEDIA_SEEK_EOF,               /* seek end of file indicator */
   MEDIA_READ_FAIL,              /* read fail indicator */
   MEDIA_WRITE_FAIL,             /* write fail indicator */
   MEDIA_DISK_FULL,              /* disk full indicator */
   MEDIA_MERGE_TYPE_MISMATCH ,
   MEDIA_FILE_INCOMPLETE
} Media_Status;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

// Note : New defined media format should always be added at the last one,    
// otherwise it may induce unsync media format problem between MMI/MED and L1Audio.
typedef enum {
   MEDIA_FORMAT_GSM_FR,
   MEDIA_FORMAT_GSM_HR,
   MEDIA_FORMAT_GSM_EFR,
   MEDIA_FORMAT_AMR,
   MEDIA_FORMAT_AMR_WB,
   MEDIA_FORMAT_DAF,
   MEDIA_FORMAT_AAC,
   MEDIA_FORMAT_PCM_8K,
   MEDIA_FORMAT_PCM_16K,
   MEDIA_FORMAT_G711_ALAW,
   MEDIA_FORMAT_G711_ULAW,
   MEDIA_FORMAT_DVI_ADPCM,
   MEDIA_FORMAT_VRD,
   MEDIA_FORMAT_WAV,
   MEDIA_FORMAT_WAV_ALAW,
   MEDIA_FORMAT_WAV_ULAW,
   MEDIA_FORMAT_WAV_DVI_ADPCM,
   MEDIA_FORMAT_SMF,
   MEDIA_FORMAT_IMELODY,
   MEDIA_FORMAT_SMF_SND,
   MEDIA_FORMAT_MMF,
   MEDIA_FORMAT_AU,
   MEDIA_FORMAT_AIFF,
   MEDIA_FORMAT_VRSI,
   MEDIA_FORMAT_WMA,
   MEDIA_FORMAT_M4A,
   MEDIA_FORMAT_WAV_DVI_ADPCM_16K,
   MEDIA_FORMAT_VOIPEVL,
   MEDIA_FORMAT_AAC_PLUS,
   MEDIA_FORMAT_AAC_PLUS_V2,
   MEDIA_FORMAT_BSAC,
   MEDIA_FORMAT_MUSICAM = 32,
   MEDIA_FORMAT_AWB_PLUS,
   MEDIA_FORMAT_AWB_PLUS_EXTEND,
   MEDIA_FORMAT_WAV_16K,
   MEDIA_FORMAT_MP4_AAC,
   MEDIA_FORMAT_MP4_AMR,
   MEDIA_FORMAT_MP4_AMR_WB,
   MEDIA_FORMAT_MP4_BSAC,
   MEDIA_FORMAT_DRA,
   MEDIA_FORMAT_COOK,
   MEDIA_FORMAT_APE,
   MEDIA_FORMAT_PCM,
   MEDIA_FORMAT_JTS,
   MEDIA_FORMAT_VORBIS,
   MEDIA_FORMAT_PCM_16K_STEREO,
   MEDIA_FORMAT_WAV_16K_STEREO,
   MEDIA_FORMAT_UNKNOWN
} Media_Format;

/*
typedef enum {
   MEDIA_AUD_COMP_LOUDSPEAKER,
   MEDIA_AUD_COMP_EARPHONE, 
   MEDIA_AUD_COMP_LOUDSPEAKER_RINGTONE
} Media_Aud_Comp_Mode;
*/
	
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct {
   const kal_uint8 *toneSeq;
   kal_int32     toneSeqLen;          /* tone sequence data length  */
   kal_int16     repeats;             /* 0 -> endless               */
} Media_ToneSeq_Param;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

// Audio Streaming Sender
#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct {
   kal_uint32      fc_format;
   kal_uint8       *rb_base;         // Pointer to the ring buffer
   kal_int32       rb_size;          // Size of the ring buffer
   kal_int32       write;
   kal_int32       read;
   void            *param;           // Extend parameter or information
   kal_uint8       fc_operation;
} AUD_RB_INFO;

// typedef  struct mhdl MHdl;
// typedef  struct media_handle Media_Handle;

#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
void          Media_MuteSpeaker( kal_bool mute );
void  Media_SetMelodyFilter( kal_uint16 len, const kal_int16 *filter );
/* ------------------------------------------------------------------------------ */
// L1CTM interface 
/*
// Due to CTM is not use in the outside, so mode the interface in to ctm_drv.h to prevent redeclaration
typedef enum{
   DIRECT_MODE,
   BAUDOT_MODE       
} L1Ctm_Interface; 

typedef enum{
   CTM_MO_SUCCESS,
   CTM_MO_FAIL, 
   CTM_MT_DETECTED, 
   CTM_CHAR_SENT, 
   CTM_CHAR_RECEIVED,
   CTM_TX_BURST_START,
   CTM_TX_BURST_END   
} L1Ctm_Event; 

typedef struct
{
    kal_int16   cprm_tone_demod_down_samp;                  // 1 (0, 1)   
} CTM_Param;

typedef void (*L1Ctm_Callback)(L1Ctm_Event , void*); 
kal_uint32 L1Ctm_GetMemReq(void);
void L1Ctm_Open(L1Ctm_Interface a, L1Ctm_Callback handler, kal_uint8 *buf, kal_uint32 buf_len, CTM_Param *ctm_param);
void L1Ctm_Close(void);
void L1Ctm_StartNegotiation(void);
kal_uint32 L1Ctm_TxPutText(const kal_uint8 *text, kal_uint32 len, kal_uint32 *left_space);
kal_uint32 L1Ctm_RxGetText(kal_uint8 *text, kal_uint32 len, kal_uint32 *left_count);
*/

/* -------------------------------e-call modem ---------------------------------------- */
// eCall modem interface
typedef enum {
   eCALL_OPERATION_SUCCESS,
   eCALL_OPERATION_FAIL,
   eCALL_OPERATION_ALREADY_OPEN,
   eCALL_OPERATION_ALREADY_CLOSE,
   eCALL_OPERATION_DURING_TRANSMISSION
} eCall_Modem_Status;

typedef enum {
   eCALL_EVENT_SEND_START,
   eCALL_EVENT_RECV_START,
   eCALL_EVENT_RECV_NACK,
   eCALL_EVENT_RECV_LL_ACK,
   eCALL_EVENT_RECV_HL_ACK_CORRECT,
   eCALL_EVENT_RECV_HL_ACK_MISMATCH,
   eCALL_EVENT_PSAP_RECV_MSD
} eCall_Modem_Event;

typedef void (*eCall_Callback)(eCall_Modem_Event event, void *param);

eCall_Modem_Status eCall_IVS_Open(eCall_Callback handler);
eCall_Modem_Status eCall_IVS_Close(void);
eCall_Modem_Status eCall_IVS_PutMSD(const kal_uint8 *pMSD, const kal_uint32 uLen);
eCall_Modem_Status eCall_IVS_SendStart(void);
eCall_Modem_Status eCall_PSAP_Open(eCall_Callback handler);
eCall_Modem_Status eCall_PSAP_Close(void);
eCall_Modem_Status eCall_PSAP_SendStart(void);

/* ------------------------------------------------------------------------------ */

kal_bool BT_PcmLoopbackTest(void);

/* Ket tone detection interface*/
void KtDetectStart(void (*callback)(kal_int16 key));
void KtDetectStop( void );

typedef enum {
  L1SP_L4C_NONE       = 0x0000, 
  L1SP_L4C_QCELP13K   = 0x0001, 
  L1SP_L4C_EVRC       = 0x0002, 
  L1SP_L4C_EVRC_B     = 0x0003, 
  L1SP_L4C_EVRC_WB    = 0x0004, 
  L1SP_L4C_EVRC_NW    = 0x0005, 
  L1SP_L4C_AMR_NB     = 0x0006, 
  L1SP_L4C_AMR_WB     = 0x0007, 
  L1SP_L4C_GSM_EFR    = 0x0008, 
  L1SP_L4C_GSM_FR     = 0x0009, 
  L1SP_L4C_GSM_HR     = 0x000A, 
} L1SP_L4C_Codec;

typedef enum {
   L1SP_L4C_ESPEECH_0,
   L1SP_L4C_ESPEECH_1,
   L1SP_L4C_START_GENERATE_SID,
   L1SP_L4C_STOP_GENERATE_SID,
} L1SP_L4C_Event;

typedef enum {
   L1SP_L4C_EVENT_NONE,
   L1SP_L4C_EVENT_CS,
   L1SP_L4C_EVENT_PS,   
} L1SP_L4C_Event_Mode;

void SP_L4C_SetEvent(L1SP_L4C_Event event, L1SP_L4C_Event_Mode mode);


/*====================start of 3G interface ===================*/
//[REMIND] The following definition is related to L1SP_STATE_2G_SPEECH_ON, please use L1SP_GetState() to search the relationship
#define RAT_2G_MODE  0
#define RAT_3G_MODE  1 
#define RAT_3G324M_MODE 2
#define RAT_4G_MODE  3

typedef enum {
   SP3G_CODEC_READY,
   SP3G_CODEC_CLOSED,
   SP3G_UL_DATA_NOTIFY,
   SP3G_UL_DATA_DEALY_TICK
} SP3G_Event;

void SP3G_Request(void);
void SP3G_UL_SetFrameType(kal_uint8 amr_frame_type);
void SP3G_UL_GetSpeechFrame(kal_uint16*frame_index, kal_uint8 *frame_type, kal_uint8 *rab_byte_array, kal_uint8 *len);
void SP3G_DL_PutSpeechFrame(kal_uint32 CFN, kal_uint8 sub_flow_id, kal_uint8 frame_type, kal_bool crc_status, kal_uint8 *subflow);
void SP3G_Closed_Confirm( void );
void SP3G_Rab_Deest( void );
void SP3G_Rab_Est( kal_uint32 rab_id, kal_uint8 default_speech_codec ); //Cosine_NAS_Sync_Ind
void SP3G_SetDTX(kal_bool on);
//void SP3GVT_DL_PutSpeechFrame(kal_uint8 *dl_data, kal_uint32 size, kal_bool error_flag);
kal_uint8 SP3GVT_DL_PutSpeechFrame(kal_uint8 *dl_data, kal_uint32 size, kal_bool error_flag, kal_uint8 *dl_frame_number);
kal_uint8 SP3GVT_DL_DropSpeechFrame(kal_uint32 number, kal_uint8 *dl_frame_number);
void SP3GVT_UL_GetSpeechFrame(kal_uint8 *ul_data, kal_uint32 ul_space, kal_uint32 *size);
void SP3GVT_SetDelayValue(kal_uint32 delay);
/*====================end of 3G interface =====================*/

/* ------------------------------------------------------------------------------ */
typedef enum {
   SP4G_CODEC_READY,
   SP4G_CODEC_CLOSED,
   SP4G_UL_DATA_NOTIFY,
   SP4G_UL_MUTE_NOTIFY,
   SP4G_UL_DATA_DEALY_TICK
} SP4G_Event;

typedef enum{
   SP4G_PSR_AMR,
   SP4G_PSR_WBAMR,
   SP4G_PSR_G711,
   SP4G_PSR_G722,   
   SP4G_PSR_G723_1,
   SP4G_PSR_G726,
   SP4G_PSR_G729,
   
}SP4G_PSR_Codec;

typedef enum{
   SP4G_CODEC_AMR_4_75=0x00,
   SP4G_CODEC_AMR_5_15,
   SP4G_CODEC_AMR_5_9,
   SP4G_CODEC_AMR_6_7,
   SP4G_CODEC_AMR_7_4,
   SP4G_CODEC_AMR_7_95,
   SP4G_CODEC_AMR_10_2,
   SP4G_CODEC_AMR_12_2,
   SP4G_CODEC_AMR_SID,
   SP4G_CODEC_AMR_NO_DATA=0xF,
   SP4G_CODEC_WBAMR_6_6=0x10,
   SP4G_CODEC_WBAMR_8_85,
   SP4G_CODEC_WBAMR_12_65,
   SP4G_CODEC_WBAMR_14_25,
   SP4G_CODEC_WBAMR_15_85,
   SP4G_CODEC_WBAMR_18_25,
   SP4G_CODEC_WBAMR_19_85,
   SP4G_CODEC_WBAMR_23_05,
   SP4G_CODEC_WBAMR_23_85,
   SP4G_CODEC_WBAMR_SID,
   SP4G_CODEC_LOST_FRAME=0x40,
   SP4G_CODEC_G711=0x60,
   SP4G_CODEC_G722,   
   SP4G_CODEC_G723_1,
   SP4G_CODEC_G726,
   SP4G_CODEC_G729,
   
}SP4G_Codec;

void SP4G_PSR_UL_AMR_GetSpeechFrame(SP4G_Codec *frame_type, kal_uint8 *encodebits, kal_uint8 *bitlen);
void SP4G_PSR_DL_AMR_PutSpeechFrame(kal_uint32 CFN, SP4G_PSR_Codec codec, SP4G_Codec frame_type, kal_uint8 *encodebits);
void SP4G_PSR_UL_GSeries_GetSpeechFrame(SP4G_Codec *codec, kal_uint8 *encodebits, kal_uint8 *bitlen);
void SP4G_PSR_DL_GSeries_PutSpeechFrame(SP4G_Codec codec, kal_uint8 *encodebits, kal_uint8 *bitlen);
int SP4G_PSR_UL_GSeries_IsMoreData(void);

void SP4G_PSR_UL_SetFrameType(SP4G_Codec codec);

kal_uint32 SP4G_PSR_Link_Est( SP4G_Codec default_speech_codec );
void SP4G_PSR_Link_Deest(kal_uint32 id);

kal_uint16 SP4G_PSR_GetCodecBitLength(SP4G_Codec codec);

/* law:
        1: G711_ALAW
        2: G711_ULAW
    dec_init_CNG_enable:
        0: disable (default)
        1: enable              */
void SP4G_Set_G711Parameters(kal_int32 law, kal_int32 dec_init_CNG_enable);

/*====================start of PCM2WAY interface =====================*/


void PCM2WAY_Start(void (*pcm2way_hdlr)(void), kal_uint32 type); //@type please refer to P2W_App_Type
void PCM2WAY_Stop(kal_uint32 type);

// void PCM2Way_SetFormat(kal_uint32 format);

kal_uint16 PCM2WAY_GetFromMic(kal_uint16 *ul_buf);
kal_uint16 PCM2WAY_PutToSpk(const kal_uint16 *dl_data);
kal_uint16 PCM2WAY_FillSpk(kal_uint16 value);
// void PCM2WAY_QueryBufSize(P2W_Format format, kal_uint32 *mic_bufsize, kal_uint32 *spk_bufsize);
/*====================end of PCM2WAY interface =====================*/

/* ------------------------------------------------------------------------- */



extern const kal_uint16 Media_I2S_INPUT_MODE_SR;
extern const char Media_I2S_SLAVE_MODE;

/* ------------------------------------------------------------------------- */

/*====================start of AFE =====================*/

void L1SP_SetOutputGainControl(kal_uint32 vol);
void l1audio_consoleDVT(kal_char *string);

/*====================end   of AFE =====================*/

/* ------------------------------------------------------------------------- */

extern void custom_cfg_audio_ec_range
(
 kal_uint8 *min_vol, /* min volume level */
 kal_uint8 *max_vol /* max volume level */
 );

extern kal_uint8 custom_cfg_hw_aud_output_path
(
   kal_uint8 speaker_id /*audio_type_enum*/
   
   /* return  l1sp audio output device enum */
);

extern kal_uint8 custom_cfg_hw_aud_input_path
(
   kal_uint8 mic_id /* audio_input_path_enum */
);

void SP_Strm_Audl_Handler( ilm_struct *ilm_ptr );
void SpcIO_Msg_Handler_inAudL(ilm_struct *ilm_ptr);
kal_bool SP_Drv_Init_Bootup(void);
kal_bool SP_Drv_Init_Task(void);

#endif


