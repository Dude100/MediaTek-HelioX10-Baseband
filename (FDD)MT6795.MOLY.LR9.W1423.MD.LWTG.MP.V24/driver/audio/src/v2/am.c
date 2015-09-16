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
 * am.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Audio Manager(AM) for Audio Mode Changes
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.152  $
 * $Modtime:   Aug 17 2005 11:17:12  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1audio/am.c-arc  $
 *
 * removed!
 * removed!
 * .
 *
 * 06 14 2012 kh.hung
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * 06 05 2012 kh.hung
 * removed!
 * .
 *
 * 05 11 2012 kh.hung
 * removed!
 * .
 *
 * 11 10 2011 kh.hung
 * removed!
 * .
 *
 * removed!
 * removed!
 * fix daily build error
 *
 * removed!
 * removed!
 * Merge V1/V2 afe driver
 *
 * 09 27 2011 kh.hung
 * removed!
 * .
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
 * 08 08 2011 kh.hung
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * 07 06 2011 kh.hung
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 *
 *******************************************************************************/

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "reg_base.h"
#include "l1audio_trace.h"

#include "l1audio_def.h"
#include "l1audio.h"
#include "audio_enum.h"
#include "l1audio_def.h"
#include "exp_SphFasTypDef.h"
#include "fc_def.h"
#include "am.h"
#include "media.h"
#include "afe.h"

/* ========================================================================= */
uint32   SaveAndSetIRQMask( void );
void     RestoreIRQMask( uint32 );
int8     L1D_GetT2( void );
void     L1D_CCCDReset( void );
void     L1D_ENABLE_DTIRQ( void );
uint16   L1D_Get_Win_TQ_WRAP( void );
/* ========================================================================= */
#define  AM_STATE_KEYTONE  (1<<L1SP_KEYTONE  )
#define  AM_STATE_TONE     (1<<L1SP_TONE     )
#define  AM_STATE_SPEECH   (1<<L1SP_SPEECH   )
#define  AM_STATE_VOIP   (1<<(L1SP_MAX_AUDIO+0)   )
#define  AM_STATE_VOICE    (1<<L1SP_VOICE    )
#define  AM_STATE_DAI      (1<<L1SP_DAI      )
#define  AM_STATE_AUDIO    (1<<L1SP_AUDIO  )
#define  AM_STATE_SND_EFFECT  (1<<L1SP_SND_EFFECT)
#define  AM_STATE_AvBT     (1 << (L1SP_MAX_AUDIO + 1))
#define  AM_STATE_AVSYNC   (1 << (L1SP_MAX_AUDIO + 2))

#define AM_CONFLICT_STATE (AM_STATE_SPEECH + AM_STATE_VOIP + AM_STATE_VOICE + AM_STATE_AUDIO) 

/*========  Speech State : record features in dedicated-mode speech  ========= */    
#define SP_STATE_VMR          (1 << 0)
#define SP_STATE_PCM8K_REC    (1 << 1)
#define SP_STATE_PCM4WAY      (1 << 2)


/*========  VoIP State ======================================= */    
#define VOIP_STATE_VMR          (1 << 0)
#define VOIP_STATE_REC_ONLY_CAL (1 << 1)
#define VOIP_STATE_REC_PLAY_CAL (1 << 2)


/*=============  DSP&AFE IO types  ============================ */
#define NORMAL_MODE        0
#define DAI_MODE           1
#define BT_CORDLESS_MODE   2
#define BT_EARPHONE_MODE   3

/*============= low byte flags of *DP_AUDIO_PAR ============================ */
#define VOICE_INPUT_FILTER_FLAG     0x1 
#define VOICE_OUTPUT_FILTER_FLAG    0x2
#define VOICE_WB_AMR_FLAG           0x8 
#define VOICE_16K_SWITCH_FLAG       0x10                
#define VOICE_MIC_MUTE_FLAG         0x20
#define VOICE_SIDETONE_FILTER_FLAG  0x40 

/* =========== Block Filter Switch Between old/New Usage===================== */
#if defined( NEW_BLOCK_FILTER_SUPPORT )
volatile kal_uint16 *g_Compen_Blk_Flt;
#endif

typedef struct {
   void     (*code)(uint32);
   uint32   data;
} AM_QFunction;

static struct {
   uint16   state;
   uint16   speech_mode;
   int16    speech_off_delay;
   int8     sub_channel;

#if defined(__BT_SUPPORT__)
   uint16  bt_digital_gain;
   uint16  bt_mic_gain;
#endif

   RINGBUFFER_T(AM_QFunction,8) qfunc;

   uint8    speech_state;
   uint8	   voip_state;   
   uint8    io_type;
   bool     fLoopBack;
   bool     ul_mute;
   bool     toneLoopbackRec;
   bool     sp3g_flag;
   bool     isRecord;  
} am;

/* SAC global structure definction*/
__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI"))) 
SAC_SphRecordPcmPar_t SAC_SphRecordPcmPar;

extern SAC_SphModePar_t SAC_SphModePar;
extern SAC_SphComPar_t  SAC_SphCommonPar;

/* --------------------------------------------------------------------------*/
const  uint16  DSP_PCM_IDLE_DELAY_TABLE[7][3] =
{ 
   { 0x20, 0x20 , 0x4B+(16<<10)+(2<<8)}, // for AMR codec 
   { 0x20, 0x20 , 0x96+(16<<10)+(2<<8)}, // for speech codec except AMR 
   { 0x0A, 0x0A , 0x4F+(16<<10)+(2<<8)}, // for PCM8K_Playback.....
   { 0x0A, 0x0A , 0x28+(16<<10)+(2<<8)}, // for PCM16K  
   { 0x0A, 0x0A , 0x9F+(16<<10)+(2<<8)},  // for Keytone/Tone/ 
   { 0x0A, 0x0A , 0x96+(16<<10)+(2<<8)}, // for PCM8K_Playback/VoIP
   { 0x10, 0x100, 0x96+(16<<10)+(2<<8)}  // for 3G Speech    
};


/* Note: The speech pattern length for amr-wb can be calculated from
lenSpeechBitsAMR_WB in amr_table.h; therefore, remove them out.
Those for amr might be removed if vm.c does not handle amr any more. */
static const uint8 SpeechPatternLength[] = {
   (uint8)((260 + 15) / 16),           /*  FR       */
   (uint8)((112 + 15) / 16 + 1),       /*  HR       */
   (uint8)((244 + 15) / 16),           /* EFR       */
   (uint8)((244 + 15) / 16),           /* AMR 12.2K */
   (uint8)((204 + 15) / 16),           /* AMR 10.2K */
   (uint8)((159 + 15) / 16),           /* AMR 7.95K */
   (uint8)((148 + 15) / 16),           /* AMR 7.4K  */
   (uint8)((134 + 15) / 16),           /* AMR 6.7K  */
   (uint8)((118 + 15) / 16),           /* AMR 5.9K  */
   (uint8)((103 + 15) / 16),           /* AMR 5.15K */
   (uint8)(( 95 + 15) / 16),           /* AMR 4.75K */
#if defined(AMRWB_DECODE)
   (uint8)((132 + 15) / 16),           /* AMR-WB 6.60  */
   (uint8)((177 + 15) / 16),           /* AMR-WB 8.85  */
   (uint8)((253 + 15) / 16),           /* AMR-WB 12.65 */
   (uint8)((285 + 15) / 16),           /* AMR-WB 14.25 */
   (uint8)((317 + 15) / 16),           /* AMR-WB 15.85 */
   (uint8)((365 + 15) / 16),           /* AMR-WB 18.25 */
   (uint8)((397 + 15) / 16),           /* AMR-WB 19.85 */
   (uint8)((461 + 15) / 16),           /* AMR-WB 23.05 */
   (uint8)((477 + 15) / 16),           /* AMR-WB 23.85 */
#endif
};

bool AM_CodecMode_IsLegal(uint8 codec_mode)
{
   if (codec_mode <= 0xA) {
      return true;
   }
#if defined(AMRWB_DECODE)
   if ( (codec_mode >= 0x20) && (codec_mode <= 0x28) ) {
      return true;
   }
#endif
   return false;
}

uint16 AM_GetSpeechPatternLength( uint8 speech_mode )
{
   if( speech_mode >= 0x20 )
      speech_mode = speech_mode - 0x20 + 0x0B;
   if( speech_mode<(sizeof(SpeechPatternLength)/sizeof(SpeechPatternLength[0])))
      return (uint16)SpeechPatternLength[speech_mode];
   else
      return 0;
}

void AM_FillSilencePattern( volatile uint16 *addr, uint16 info, uint16 speech_mode )
{

}

/* -------------------------------------------------------------------------- */
bool AM_AudioManager( bool handover, uint16 speech_mode, int8 sub_channel )
{
   AM_QFunction func;

   if( speech_mode >= 0x20 ) //ReMap WM AMR from 0x20~0x28- =>0xB~0x13(6.60~23.85)
      speech_mode = speech_mode - 0x20 + 0x0B;
      
   if( speech_mode != am.speech_mode )
      am.speech_mode = speech_mode;

   if( sub_channel != am.sub_channel )
      am.sub_channel = sub_channel;

   if( handover && (am.state & AM_STATE_DAI) == 0 && (!am.sp3g_flag) ) {
      if( am.state & AM_STATE_SPEECH ) {
         L1Audio_Msg_AM_Handover( am.speech_mode );
      }
   }
   else if( !RB_EMPTY( am.qfunc ) ) {
      RB_GET( am.qfunc, func );
      func.code( func.data );
   }
   else {
      AFE_Manager();
   }

   return false;
}

void AM_FlushQFunction( void )
{
#ifndef  L1D_TEST
   while( !RB_EMPTY(am.qfunc) )
      kal_sleep_task( 1 );
#endif
}

/* ========================================================================= */
/*   Interface Functions                                                     */
/* ========================================================================= */
__attribute__ ((section ("DMDSP_SHARE_AUDIO_RODATA"))) 
#ifdef L1D_TEST
const signed short Sidetone_FIR[31] = 
{ 
   287,   -37,  -407,  -201,   432,   541,  -305,  -936,   -48,  1292, 
   818, -1545, -2548,  1657,  9937, 14977,  9937,  1657, -2548, -1545, 
   818,  1292,   -48,  -936,  -305,   541,   432,  -201,  -407,   -37, 
   287 
};
#else
const signed short Sidetone_FIR[31] = 
{ 
   287,   -37,  -407,  -201,   432,   541,  -305,  -936,   -48,  1292, 
   818, -1545, -2548,  1657,  9937, 14977,  9937,  1657, -2548, -1545, 
   818,  1292,   -48,  -936,  -305,   541,   432,  -201,  -407,   -37, 
   287 
};
#endif

static void AM_WriteSpeechCompensationFilter( const int16 in_coeff[45], const int16 out_coeff[45] )
{
}

void AM_WriteFirCoeffs( const int16 in_coeff[45], const int16 out_coeff[45] )
{
   if(am.toneLoopbackRec)
      return;

   /* Write audio FIR filter coeficients */
   AM_WriteSpeechCompensationFilter(in_coeff, out_coeff);

}




/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_VMRecordOff( uint32 data );

extern SAC_Sph2GCallPar_t SAC_Sph2GCallPar;
extern SAC_Sph3GCallPar_t SAC_Sph3GCallPar;
extern uint8 sp3g_codec_mode;
void AM_SpeechOn(uint32 rat_mode)
{   
   /* To do : update delay read, write, codec mode*/
#if defined( __UMTS_RAT__ )
   if( rat_mode == RAT_3G_MODE || rat_mode == RAT_3G324M_MODE ){
      L1SP_Send3GSpeechOn();
      am.sp3g_flag = true;
   } else
#endif
   {
      SAC_Sph2GCallPar.u4CodModUl = am.speech_mode;
      SAC_Sph2GCallPar.u4CodModDl = am.speech_mode;
      L1SP_Send2GSpeechOn();
   }
   
   
   AFE_TurnOnSpeaker( L1SP_SPEECH );
   AFE_TurnOnMicrophone( L1SP_SPEECH );
   
   //AM_FlushQFunction();
   L1Audio_Msg_AM_Switch( AM_Switch_Name(5), L1AUDIO_Str_onoff(1) );
   am.state |= AM_STATE_SPEECH;
}


void AM_SpeechOff( void )
{
#ifndef  L1D_TEST
   AFE_TurnOffMicrophone( L1SP_SPEECH );
   AFE_TurnOffSpeaker( L1SP_SPEECH );
#endif
#if defined( __UMTS_RAT__ )
   if( am.sp3g_flag ){
      L1SP_Send3GSpeechOff();
      am.sp3g_flag = false;
   }
   else
#endif
   L1SP_Send2GSpeechOff();
   L1Audio_Msg_AM_Switch( AM_Switch_Name(5), L1AUDIO_Str_onoff(0) );
   am.state &= ~AM_STATE_SPEECH;
}

bool AM_IsSpeechOn( void )
{
   return( (bool)((am.state & AM_STATE_SPEECH) != 0) );
}

bool AM_IsAmInSpeechState( void )
{
	if ((am.state & (AM_STATE_SPEECH | AM_STATE_VOICE | AM_STATE_VOIP )) != 0)
		return true;
	else 
		return false;
}
	

void AM_SetSpeechMode( uint16 speech_mode, int8 sub_channel )
{
   am.speech_mode = speech_mode;
   am.sub_channel = sub_channel;
}

#if defined( __UMTS_RAT__ )
__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI"))) 
SAC_SphHandoverPar_t SAC_SphHandoverPar;

void AM_InterRAT_W2G()
{
   //To DO: Send message
   if( !(am.state & AM_STATE_SPEECH) )
      return;
   SAC_SphHandoverPar.u4CodModUl = am.speech_mode;
   SAC_SphHandoverPar.u4CodModDl = am.speech_mode;
   SAC_SphHandoverPar.u4RAT = 2;
   L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_HANDOVER, sizeof(SAC_SphHandoverPar_t), (kal_uint32)&SAC_SphHandoverPar);
   am.sp3g_flag = false;
   L1Audio_Msg_INTERRAT_W2G();
}

void AM_InterRAT_G2W()
{
   //To Do: Send Message
   if( !(am.state & AM_STATE_SPEECH) )
      return;
   SAC_SphHandoverPar.u4CodModUl = sp3g_codec_mode;
   SAC_SphHandoverPar.u4CodModDl = sp3g_codec_mode;
   SAC_SphHandoverPar.u4RAT = 1;
   L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_HANDOVER, sizeof(SAC_SphHandoverPar_t), (kal_uint32)&SAC_SphHandoverPar);
   am.sp3g_flag = true;
   L1Audio_Msg_INTERRAT_G2W();
}
#endif

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
void AM_SetDAIMode ( uint8 mode )
{
   if( am.state & AM_STATE_VOICE )
      return;
   if( (am.state & AM_STATE_SPEECH) == 0 )
      return;

   if( mode == 4 )
      mode = 3;
   if( mode > 3 )
      mode = 0;
   if( mode == 0 ) {
      L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_ACOUSTIC_TEST_STOP, 0, 0 );
      am.state &= ~AM_STATE_DAI;
      am.io_type = NORMAL_MODE;
   }else{
      SAC_SphAcousticTestPar_t SAC_SphAcousticTestPar;
      SAC_SphAcousticTestPar.u4Wb = (kal_uint32)false;
      L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_ACOUSTIC_TEST_START, sizeof(SAC_SphAcousticTestPar), (kal_uint32)&SAC_SphAcousticTestPar );
      am.state |= AM_STATE_DAI;
      am.io_type = DAI_MODE;
   }
   L1D_CCCDReset();
   L1Audio_Msg_AM_IO_Switch( AM_IO_Name(am.io_type) );
}

bool AM_IsDAIMode( void )
{
   return false;
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
static void AM_DSP_VMRecordOn( uint32 speech_mode )
{
   if( am.state & AM_STATE_SPEECH ) {       /* Conversation Recording */
      ASSERT(!(am.speech_state & SP_STATE_VMR));
      am.speech_state |= SP_STATE_VMR;
      L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(0) , L1AUDIO_Str_onoff(1) );
   }
   else if	( am.state & AM_STATE_VOIP ) {    /* VoIP Recording */
      ASSERT(!(am.voip_state & VOIP_STATE_VMR));         
      am.voip_state |= VOIP_STATE_VMR;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(10), L1AUDIO_Str_onoff(1) );

   }   
   else {                                    /* VM in idle mode */
      ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) );                                 
      AFE_TurnOn8K();
      
      am.state |= AM_STATE_VOICE;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(6), L1AUDIO_Str_onoff(1) );
   }
   
}

void AM_VMRecordOn( uint16 speech_mode )
{
   AM_DSP_VMRecordOn( speech_mode );
   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) {
      AFE_TurnOnMicrophone( L1SP_LINEIN );
   }
   else {
      if(!(am.state & AM_STATE_SPEECH) && !(am.state & AM_STATE_VOIP) )
      {         
         AFE_TurnOnMicrophone( L1SP_VOICE );
      }   
   }
   
   if(!(am.state & AM_STATE_SPEECH) && !(am.state & AM_STATE_VOIP) )
      SPE_SetULNR(true);   
}


static void AM_DSP_VMRecordOff( uint32 data )
{
   (void)data;
   
   if(am.speech_state & SP_STATE_VMR) /* Conversation Recording */
   {
      am.speech_state &= ~SP_STATE_VMR;
      L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(0) , L1AUDIO_Str_onoff(0) );
   }
   else if	( am.voip_state & VOIP_STATE_VMR ) {    /* VoIP Recording */
      am.voip_state &= ~VOIP_STATE_VMR;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(10), L1AUDIO_Str_onoff(0) );
   }   
   else  /* VM in idle mode */ 
   {         
      am.state &= ~AM_STATE_VOICE;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(6), L1AUDIO_Str_onoff(0) );
   }
}

void AM_VMRecordOff( void )
{
   if(!(am.state & AM_STATE_SPEECH) && !(am.state & AM_STATE_VOIP) )
      SPE_SetULNR(false);
   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) {
      AFE_TurnOffMicrophone( L1SP_LINEIN );
   }
   else {      
      if( !(am.state & AM_STATE_VOIP) )        
      AFE_TurnOffMicrophone( L1SP_VOICE );
   }
   AM_DSP_VMRecordOff(0);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


void AM_VMPlaybackOn( uint16 control, uint32 style )
{
   L1Audio_Msg_AM_Switch( AM_Switch_Name(7), L1AUDIO_Str_onoff(1) );
   am.state |= AM_STATE_VOICE;

   if( (uint32)MEDIA_VMP_AS_SPEECH == (style&0x01)) {
      AFE_TurnOnSpeaker( L1SP_SPEECH );
   }
   else { /* MEDIA_VMP_AS_RINGTONE */
      AFE_TurnOnSpeaker( L1SP_VOICE );
   }
}

void AM_VMPlaybackOff( uint32 style )
{
   if( (uint32)MEDIA_VMP_AS_SPEECH == (style & 0x01)) {
      AFE_TurnOffSpeaker( L1SP_SPEECH );
   }
   else {    /* MEDIA_VMP_AS_RINGTONE */
      AFE_TurnOffSpeaker( L1SP_VOICE );
   }

   L1Audio_Msg_AM_Switch( AM_Switch_Name(7), L1AUDIO_Str_onoff(0) );   

   am.state &= ~AM_STATE_VOICE;
   /* Resume Digital Gain for Speech Mode */

   AFE_SetDigitalGain( L1SP_VOICE, 100 );

}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
void AM_KeyToneOn( void )
{
   L1Audio_Msg_AM_Switch( AM_Switch_Name(0), L1AUDIO_Str_onoff(1) );
   am.state |= AM_STATE_KEYTONE;
   AFE_TurnOnSpeaker( L1SP_KEYTONE );
}

void AM_KeyToneOff( void )
{
   AFE_TurnOffSpeaker( L1SP_KEYTONE );
   L1Audio_Msg_AM_Switch( AM_Switch_Name(0), L1AUDIO_Str_onoff(0) );
   am.state &= ~AM_STATE_KEYTONE;
}

bool AM_IsKeyToneOn( void )
{
   if (am.state & AM_STATE_KEYTONE)
      return true;
   return false;
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
void AM_ToneOn( void )
{
   L1Audio_Msg_AM_Switch( AM_Switch_Name(1), L1AUDIO_Str_onoff(1) );
   am.state |= AM_STATE_TONE;
}

void AM_ToneOff( void )
{
   L1Audio_Msg_AM_Switch( AM_Switch_Name(1), L1AUDIO_Str_onoff(0) );
   am.state &= ~AM_STATE_TONE;
}

bool AM_IsToneOn( void )
{
   if (am.state & AM_STATE_TONE)
      return true;
   return false;
}


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
bool AM_IsBgsndOn( void )
{
   if (am.state & AM_STATE_SND_EFFECT)
      return true;
   return false;
}

static void AM_DSP_PCM8K_PlaybackOn( uint32 data )
{
   (void)data;

#ifdef BGSND_ENABLE
   if ( data == 1 )
   {
      ASSERT(!(am.state & AM_STATE_SND_EFFECT));
      am.state |= AM_STATE_SND_EFFECT;                                    
      L1Audio_Msg_AM_Switch( AM_Switch_Name(9), L1AUDIO_Str_onoff(1) );         
   }
   else
#endif /* ...BGSND_ENABLE */
   {
      ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) );       
      am.state |= AM_STATE_VOICE;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(2), L1AUDIO_Str_onoff(1) );
   }
}

void AM_PCM8K_PlaybackOn( void )
{
   AM_DSP_PCM8K_PlaybackOn( 0 );
   if(!(am.state & AM_STATE_SPEECH))
      AFE_TurnOnSpeaker( L1SP_VOICE );
}

static void AM_DSP_PCM8K_PlaybackOff( uint32 data )
{
   (void)data;
   
#ifdef BGSND_ENABLE
   if( data == 1 )
   {
      am.state &= ~AM_STATE_SND_EFFECT;                  
      L1Audio_Msg_AM_Switch( AM_Switch_Name(9), L1AUDIO_Str_onoff(0) );         
   }
   else
#endif /* ...BGSND_ENABLE */
   {      
      am.state &= ~AM_STATE_VOICE;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(2), L1AUDIO_Str_onoff(0) );
   }
}

void AM_PCM8K_PlaybackOff( bool wait )
{
   AFE_TurnOffSpeaker( L1SP_VOICE );
   AM_DSP_PCM8K_PlaybackOff( 0 );
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
void AM_PCM16K_PlaybackOn( void )
{
   ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) ); 
   AFE_TurnOnSpeaker( L1SP_VOICE );
   am.state |= AM_STATE_VOICE;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(3), L1AUDIO_Str_onoff(1) );
}

void AM_PCM16K_PlaybackOff( bool wait )
{
   AFE_TurnOffSpeaker( L1SP_VOICE );
   am.state &= ~AM_STATE_VOICE;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(3), L1AUDIO_Str_onoff(0) );
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void AM_DSP_PCM16K_RecordOn( uint32 data )
{
   (void)data;

   ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) );
   am.state |= AM_STATE_VOICE;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(6), L1AUDIO_Str_onoff(1) );
}

void AM_PCM16K_RecordOn( void )
{
   ASSERT( !( am.state & AM_STATE_SPEECH ) );

   AM_DSP_PCM16K_RecordOn(0);
   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) {
      AFE_TurnOnMicrophone( L1SP_LINEIN );
   }
   else {      
      AFE_TurnOnMicrophone( L1SP_VOICE );
   }
}

void AM_PCM16K_RecordOn_V2( kal_bool isDedicated, kal_int32 fc_aud_id )
{
   ASSERT( !( am.state & AM_STATE_SPEECH ) ); //only support idle recording

   //SAC_SphRecordPcmPar.u4WbPcm = 1;
   //SPE_SetULNR(KAL_TRUE);
   
   
#ifndef __DUAL_MIC_SUPPORT__
   ASSERT( 0 == SAC_SphRecordPcmPar.u4RecMode); //if not dual mic supporting, system can not record stereo pcm
#endif 

   //setup the enhancement
#ifndef __HD_RECORD__
   SPE_SetULNR(KAL_TRUE);
#endif
      

   L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_MUTE_UPLINK_BY_FRAME, 0, (kal_uint32)MUTE_UL_FRAME_SIZE);
   if (isDedicated) {
      /* Recording in TCH mode */
      L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_CALL_RECORD_PCM_START, fc_aud_id, (kal_uint32)&SAC_SphRecordPcmPar, KAL_TRUE );
   }else{
      L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_IDLE_RECORD_PCM_START, fc_aud_id, (kal_uint32)&SAC_SphRecordPcmPar, KAL_TRUE );
   }

   AM_DSP_PCM16K_RecordOn(0);

   //only turn on UL NR and AGC, 
   //due to 16k always using in idle record, enhancement can trun on properly
   //FIXME: Smartphone has wb parameters, but feature phone may not have
#if defined(__SMART_PHONE_MODEM__) || defined(__AMRWB_LINK_SUPPORT__)   
   l1sp_updateSpeAppMask(0xffff, true); 	
   l1sp_updateDlSpeAppMask(0xffff, false);
   l1sp_updateUlSpeAppMask(0xffff, false);
   l1sp_updateUlSpeAppMask(SPH_ENH_MASK_NDC | SPH_ENH_MASK_AGC, true);
   SetSpeechEnhancement(true);
#endif //defined(__SMART_PHONE_MODEM__) || defined(__AMRWB_LINK_SUPPORT__)  

   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) {
      AFE_TurnOnMicrophone( L1SP_LINEIN );
   }
   else {      
      AFE_TurnOnMicrophone( L1SP_VOICE );
   }
}

static void AM_DSP_PCM16K_RecordOff( uint32 data )
{
   (void)data;

   am.state &= ~AM_STATE_VOICE;
   am.isRecord = false;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(6), L1AUDIO_Str_onoff(0) );
}

void AM_PCM16K_RecordOff( bool wait )
{
   ASSERT( !( am.state & AM_STATE_SPEECH ) );
   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) {
      AFE_TurnOffMicrophone( L1SP_LINEIN );
   }
   else {      
      AFE_TurnOffMicrophone( L1SP_VOICE );
   }

   SetSpeechEnhancement(false);
	  
   //resume the masks
   l1sp_updateUlSpeAppMask(0xffff, true);
   l1sp_updateDlSpeAppMask(0xffff, true);
   l1sp_updateSpeAppMask(0xffff, true);	  	  
#ifndef __HD_RECORD__
   SPE_SetULNR(false);
#endif //NOT __HD_RECORD__
   
   AM_DSP_PCM16K_RecordOff(0);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
void AM_PCM8K_RecordOn_V2( kal_bool isDedicated, kal_int32 fc_aud_id )
{

   L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_MUTE_UPLINK_BY_FRAME, 0, (kal_uint32)MUTE_UL_FRAME_SIZE);
   if (isDedicated) {
      /* Recording in TCH mode */
      L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_CALL_RECORD_PCM_START, fc_aud_id, (kal_uint32)&SAC_SphRecordPcmPar, KAL_TRUE );
   }else{
      ASSERT(0); //DSP did not support idle 8k record. 
      //L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_IDLE_RECORD_PCM_START, fc_aud_id, (kal_uint32)&SAC_SphRecordPcmPar, KAL_TRUE );
   }

   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) {
      AFE_TurnOnMicrophone( L1SP_LINEIN );
   }
   else {
      if(!(am.state & AM_STATE_SPEECH))
      {        
         AFE_TurnOnMicrophone( L1SP_VOICE );
      }   
   }
   if( am.state & AM_STATE_SPEECH ) {       /* Conversation Recording */
      ASSERT(!(am.speech_state & SP_STATE_PCM8K_REC));
      am.speech_state |= SP_STATE_PCM8K_REC;
      L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(1) , L1AUDIO_Str_onoff(1) );
      return;
   }else{
       ASSERT( !(am.state & AM_CONFLICT_STATE) );
       
       am.state |= AM_STATE_VOICE;
       L1Audio_Msg_AM_Switch( AM_Switch_Name(4), L1AUDIO_Str_onoff(1) );

       /* record under call do not need to change the ULNR setting 
	   if( AFE_GetInputSource() != L1SP_LNA_FMRR ) {// FM don't need ULNR
		  SPE_SetULNR(bool ec)(true);  
       }
       */
   }
   am.isRecord = true;
}

void AM_PCM8K_RecordOn( void )
{
   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) {
      AFE_TurnOnMicrophone( L1SP_LINEIN );
   }
   else {
      if(!(am.state & AM_STATE_SPEECH))
      {        
         AFE_TurnOnMicrophone( L1SP_VOICE );
      }   
   }
   if( am.state & AM_STATE_SPEECH ) {       /* Conversation Recording */
      ASSERT(!(am.speech_state & SP_STATE_PCM8K_REC));
      am.speech_state |= SP_STATE_PCM8K_REC;
      L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(1) , L1AUDIO_Str_onoff(1) );
      return;
   }else{
       ASSERT( !(am.state & AM_CONFLICT_STATE) );
       // SPE_SetULNR(KAL_TRUE);
       am.state |= AM_STATE_VOICE;
       L1Audio_Msg_AM_Switch( AM_Switch_Name(4), L1AUDIO_Str_onoff(1) );

#ifndef __HD_RECORD__
	   SPE_SetULNR(true);	
#endif //NOT __HD_RECORD__
	  
	   //only turn on UL NR and AGC
	   l1sp_updateSpeAppMask(0xffff, true);  
	   l1sp_updateDlSpeAppMask(0xffff, false);
	   l1sp_updateUlSpeAppMask(0xffff, false);
	   l1sp_updateUlSpeAppMask(SPH_ENH_MASK_NDC | SPH_ENH_MASK_AGC, true);
	   SetSpeechEnhancement(true);
   }
}

static void AM_DSP_PCM8K_RecordOff( uint32 data )
{
   (void)data;
   if(am.speech_state & SP_STATE_PCM8K_REC) 
   { 
      am.speech_state &= ~SP_STATE_PCM8K_REC;   
      L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(1) , L1AUDIO_Str_onoff(0) );
   }
   else 
   {   
      am.state &= ~AM_STATE_VOICE;
      L1Audio_Msg_AM_Switch( AM_Switch_Name(4), L1AUDIO_Str_onoff(0) );
   }
   am.isRecord = false;
}

void AM_PCM8K_RecordOff( bool wait )
{   
   
   if( AFE_GetInputSource() == L1SP_LNA_FMRR ) {
      AFE_TurnOffMicrophone( L1SP_LINEIN );
   }
   else {      
      AFE_TurnOffMicrophone( L1SP_VOICE );
   }
   
   if(!(am.state & AM_STATE_SPEECH)) {
      //SPE_SetULNR(KAL_FALSE);
      SetSpeechEnhancement(false);
			 
      //resume the masks
      l1sp_updateUlSpeAppMask(0xffff, true);
      l1sp_updateDlSpeAppMask(0xffff, true);
      l1sp_updateSpeAppMask(0xffff, true);		 
#ifndef __HD_RECORD__
      SPE_SetULNR(false);
#endif //NOT __HD_RECORD__
   }
   
   AM_DSP_PCM8K_RecordOff(0);
}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
void AM_AudioPlaybackOn( uint16 asp_type, uint16 asp_fs )
{
#if APM_SUPPORT
   APM_Activate(2, asp_fs);
#endif

#ifndef  L1D_TEST 
   AFE_SetSamplingRate( (uint32)asp_fs );
   AFE_TurnOnSpeaker( L1SP_AUDIO );
   kal_sleep_task(1);
#endif

   am.state |= AM_STATE_AUDIO;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(8), L1AUDIO_Str_onoff(1) );
}

void AM_AudioPlaybackOn_Initialize( kal_uint32 channel, kal_uint32 asp_fs, kal_uint32 fc_aud_id )
{

}

void AM_AudioPlaybackOn_V2( kal_uint32 channel, kal_uint32 asp_fs, MHdl *hdl )
{
#if APM_SUPPORT

#if defined(__ACF_MCU_FIR_SUPPORT__) || defined(__ACF_DSP_FIR_SUPPORT__) || defined(__ACF_HW_FIR_SUPPORT__) || defined(__ACF_DSP_IIR_SUPPORT__)
   Audio_Compensation_Activate(AM_Convert_Sample_Index(asp_fs));
#endif

//   APM_Activate_Component(asp_fs, hdl);
#endif

#if defined ( __BT_AUDIO_VIA_SCO__ )
   if( AM_IsBluetoothOn() )
      HOST_APM_Register(APM_TASKID_AVB);
   else
      HOST_APM_UnRegister(APM_TASKID_AVB);
#endif

#ifndef  L1D_TEST 
   AFE_SetSamplingRate( (uint32)asp_fs );
   AFE_TurnOnSpeaker( L1SP_AUDIO );
   kal_sleep_task(1); 
#endif

   am.state |= AM_STATE_AUDIO;
   L1Audio_Msg_AM_Switch( AM_Switch_Name(8), L1AUDIO_Str_onoff(1) );
}

void AM_AudioPlaybackOff( bool wait )
{
#if APM_SUPPORT
   //APM_Deactivate();
#endif

#ifndef  L1D_TEST 
   AFE_TurnOffSpeaker( L1SP_AUDIO );
   kal_sleep_task(1);
#endif

   L1Audio_Msg_AM_Switch( AM_Switch_Name(8), L1AUDIO_Str_onoff(0) );
   
   am.state &= ~AM_STATE_AUDIO;
}

void AM_AudioPlaybackOff_V2( bool wait )
{
   AM_AudioPlaybackOff(wait);

#if defined ( __BT_AUDIO_VIA_SCO__ )
   HOST_APM_UnRegister(APM_TASKID_AVB);
#endif
}

int16 AM_IsAudioPlaybackOn( void )
{
   if( am.state & AM_STATE_AUDIO )
      return 1;
   return -1;
}

int16 AM_IsRecordOn( void )
{
   return am.isRecord;
}

bool AM_IsVMPlaybackOn( void )
{
   if( am.state & AM_STATE_VOICE)
      return true;
   return false;
}

bool AM_IsVoiceOn( void )
{
   if( am.state & ~AM_STATE_AUDIO)
      return true;
   return false;
}

/* ==========================================================================*/
void AM_AVSync_On( void )
{
   am.state |= AM_STATE_AVSYNC;
}

void AM_AVSync_Off( void )
{
   am.state &= ~AM_STATE_AVSYNC;
}

bool AM_IsAVsyncOn( void )
{
   if (am.state & AM_STATE_AVSYNC)
      return true;
   else
      return false;
}

/* ==========================================================================*/
void AM_MuteULSpeech( bool mute )
{
   //   bit 0 : DL mute/unmute;
   //   bit 1 : UL mute/unmute
   if( mute ){
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_MUTE, 2, (kal_uint32)NULL);
   }
   else
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_UNMUTE, 2, (kal_uint32)NULL);
   am.ul_mute   = mute;
}

bool AM_IsULSpeechMuted( void )
{
   return am.ul_mute;
}

void AM_Init( void )
{
   RB_INIT( am.qfunc );
   am.state = 0;
   am.speech_mode = 0;
   am.sub_channel = 0;
   am.speech_off_delay = 0;
   
   am.io_type = NORMAL_MODE;  
   am.speech_state = 0;
   am.voip_state = 0;   
   am.fLoopBack = false; 
   am.sp3g_flag = false;
   am.ul_mute   = false;
   am.toneLoopbackRec = false;
}

/* ========================================================================= */
/*   Bluetooth control Functions                                             */
/* ========================================================================= */
#if defined(__BT_SUPPORT__)

#if defined(__SMART_PHONE_MODEM__)
const unsigned short default_bt_pcm_in_vol = 100;
const unsigned short default_bt_pcm_out_vol = 100;
#else
extern const unsigned short default_bt_pcm_in_vol;
extern const unsigned short default_bt_pcm_out_vol;
#endif

//*******************************************************************//
//*   bt_mode:        1 for cordless mode, 2 for earphone mode      *//
//*   bt_sync_type:   0 for short sync, 1 for long sync             *//
//*   bt_sync_length: range from 1 to 8                             *//
//*******************************************************************//
extern const unsigned char Bluetooth_Sync_Type;
extern const unsigned char Bluetooth_Sync_Length;
void AM_BluetoothOn( uint8 bt_mode )
{
   uint32 param = bt_mode;          // bt_mode will be either 1 for cordless mode, or 2 for earphone mode
   if( bt_mode == 1 ){ //cordless mode
      TONE_StopAndWait();
      KT_StopAndWait();
   }
   param <<= 12;
   param |= (Bluetooth_Sync_Type << 3);    // bt_sync_type will be either 0 for short sync, or 1 for long sync
   param |= (Bluetooth_Sync_Length - 1);   // 1 <= bt_sync_length <= 8

   if (bt_mode == 1)
      am.io_type = BT_CORDLESS_MODE; 
   else
      am.io_type = BT_EARPHONE_MODE;
   L1Audio_Msg_AM_IO_Switch( AM_IO_Name(am.io_type) );
   AFE_SetRefresh();//update digital gain
#if defined ( __BT_AUDIO_VIA_SCO__ )
   if( AM_IsAudioPlaybackOn() != -1 )
      HOST_APM_Register(APM_TASKID_AVB);
   else
      HOST_APM_UnRegister(APM_TASKID_AVB);
#endif
}

void AM_BluetoothOff( void )
{
   am.io_type = NORMAL_MODE; 
   L1Audio_Msg_AM_IO_Switch( AM_IO_Name(am.io_type) );
#if defined ( __BT_AUDIO_VIA_SCO__ )
   HOST_APM_UnRegister(APM_TASKID_AVB);
#endif
}

bool AM_IsBluetoothOn( void )
{
   if ( (am.io_type == BT_EARPHONE_MODE) || (am.io_type == BT_CORDLESS_MODE) )
      return true;
   else
      return false;
}

bool AM_IsBTCordlessMode( void )
{
   return false;
}

#endif   // __BT_SUPPORT__
/* ========================================================================= */


#ifdef BGSND_ENABLE
void AM_SND_PlaybackOn( void )
{
   AM_DSP_PCM8K_PlaybackOn(1);
   if ( !AM_IsSpeechOn() )
      AFE_TurnOnSpeaker( L1SP_SND_EFFECT );
}

void AM_SND_PlaybackOff( bool wait )
{
   AFE_TurnOffSpeaker( L1SP_SND_EFFECT );
   AM_DSP_PCM8K_PlaybackOff(1);
}
#endif /* ...BGSND_ENABLE */

/* ========================================================================= */
/*   PCM_EX control Functions                                            */
/* ========================================================================= */
void  AM_PCM_EX_On( uint32 type )
{
   kal_uint8 aud_func = L1SP_MAX_AUDIO;
   switch(type)
   {
      case P2W_APP_TYPE_UNDER_CALL: //0:  PCM4WAY CTM
         ASSERT(!(am.speech_state & SP_STATE_PCM4WAY));
         am.speech_state |= SP_STATE_PCM4WAY;
         L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(2) , L1AUDIO_Str_onoff(1) );
         break;
         
      case P2W_APP_TYPE_WITHOUT_CALL: //1: PCM2WAY Voice
         ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) ); 
         am.state |= AM_STATE_VOICE;         
         break;
         
      case P2W_APP_TYPE_VOIP: //2:  PCM2WAY VoIP
         ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) );
         am.state |= AM_STATE_VOIP;
         break;

	  case P2W_APP_TYPE_REC_ONLY_CAL: //3: PCM2Way record only (for calibration)
	  	 ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) ); 
         am.state |= AM_STATE_VOIP; 
		 ASSERT_REBOOT( !(am.voip_state & VOIP_STATE_REC_ONLY_CAL) ); 
		 am.voip_state |= VOIP_STATE_REC_ONLY_CAL;
	  	 break;
		 
	  case P2W_APP_TYPE_REC_PLAY_CAL:// 4: PCM2Way record and play (for calibration)
	  	 ASSERT_REBOOT( !(am.state & AM_CONFLICT_STATE) ); 
         am.state |= AM_STATE_VOIP; 
		 ASSERT_REBOOT( !(am.voip_state & VOIP_STATE_REC_PLAY_CAL) ); 
		 am.voip_state |= VOIP_STATE_REC_PLAY_CAL;
	  	 break;
		 
      default:
         ASSERT(0);
         break;                 
   }   
   //if( type == 2 )
   if( type == P2W_APP_TYPE_VOIP || type == P2W_APP_TYPE_REC_ONLY_CAL || type == P2W_APP_TYPE_REC_PLAY_CAL)
   {
      AFE_SetDigitalGain( L1SP_SPEECH, 100 );
      aud_func = L1SP_SPEECH;
   }
   else if(!(am.state & AM_STATE_SPEECH))
      aud_func = L1SP_VOICE;

   if(aud_func < L1SP_MAX_AUDIO)
   {
   	  if(type == P2W_APP_TYPE_REC_ONLY_CAL){ //case when calibration with record only
	  	AFE_TurnOnMicrophone( aud_func );
   	  } else { //default
   		AFE_TurnOnSpeaker( aud_func );
	    AFE_TurnOnMicrophone( aud_func );
   	  }
   }
}


void  AM_PCM_EX_Off( uint32 type )
{
   kal_uint8 aud_func = L1SP_MAX_AUDIO;
   switch(type)
   {
      case 0:  //PCM4WAY CTM
         am.speech_state &= ~SP_STATE_PCM4WAY;
         L1Audio_Msg_AM_SetSpeech( AM_Speech_Feature_Name(2) , L1AUDIO_Str_onoff(0) );                   
         break;
         
      case 1:  //PCM2WAY Voice
         am.state &= ~AM_STATE_VOICE;
         break;
         
      case 2:  //PCM2WAY VoIP
         am.state &= ~AM_STATE_VOIP;
         break;

	  case 3:  //PCM2Way record only (for calibration)
	     am.voip_state &= ~VOIP_STATE_REC_ONLY_CAL;
         am.state &= ~AM_STATE_VOIP;
         break;

      case 4:  //PCM2Way record and play (for calibration)
         am.voip_state &= ~VOIP_STATE_REC_PLAY_CAL;
         am.state &= ~AM_STATE_VOIP;
         break;
      default:
         ASSERT(0);
         break;                  
   }    
   if( type == 2  || type == 3 || type == 4 )
      aud_func = L1SP_SPEECH;
   else if(!(am.state & AM_STATE_SPEECH))
      aud_func = L1SP_VOICE;

   if(aud_func < L1SP_MAX_AUDIO)
   {
   		if(type == 3){ //case when calibration with record only
			AFE_TurnOffMicrophone( aud_func );
   		} else { //default
   			AFE_TurnOffSpeaker( aud_func );
		    AFE_TurnOffMicrophone( aud_func );
   		}
      
   }
}

bool AM_IsVoIPOn( void )
{
   return( (bool)((am.state & AM_STATE_VOIP) != 0) );
}

/* ========================================================================= */
uint16 AM_Status( void ) 
{
   return am.state;   
}

void AM_EnableToneLoopBackFlag( kal_bool param )
{
   if(param)
      am.toneLoopbackRec = KAL_TRUE;
   else
      am.toneLoopbackRec = KAL_FALSE;
}

/* ========================================================================= */
/*   Functions for Modem LoopBack Test                                       */
/* ========================================================================= */
bool AM_IsLoopBackTest( void )
{   
   return am.fLoopBack; 
}

void AM_SetLoopBackTest(bool enable)
{
   am.fLoopBack = enable;          
} 

/* ========================================================================= */
/*   Functions for Buletooth Cordless Mode                                   */
/* ========================================================================= */

void AM_BTCordlessOn( void )
{
   AFE_TurnOnSpeaker( L1SP_SPEECH );
   AFE_TurnOnMicrophone( L1SP_SPEECH );
   am.state |= AM_STATE_SPEECH;
}

void AM_BTCordlessOff( void )
{
   am.state &= ~AM_STATE_SPEECH;
   AFE_TurnOffMicrophone( L1SP_SPEECH );
   AFE_TurnOffSpeaker( L1SP_SPEECH );
}

bool AM_IsConflictState( void )
{
   if( am.state & AM_CONFLICT_STATE )
      return true;
   else
      return false;
}

kal_uint16 AM_GetSpeechMode(void)
{
   return am.speech_mode;
}

void AM_TurnOnBlockFilter( void )
{
   AFE_TurnOnFIR( L1SP_SPEECH );
}

void AM_TurnOffBlockFilter( void )
{
   AFE_TurnOffFIR( L1SP_SPEECH );
}
