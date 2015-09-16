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
 * tone.c
 *
 * Project:
 * --------
 *   MTK6208
 *
 * Description:
 * ------------
 *   New Tone Interface for MT6205B and later
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
                         
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "reg_base.h"

#include "l1audio.h"
#include "audio_enum.h"
#include "l1audio_def.h"                     
#include "am.h"
#include "fc_def.h"
#include "media.h"
#include "afe.h"
#include "l1sp_trc.h"

uint32   SaveAndSetIRQMask( void );
void     RestoreIRQMask( uint32 );
extern kal_bool AFE_IsSpeakerMuted( kal_uint8 aud_func); 
uint8 tone_mute_audio = 0; 
#if defined( __I2S_INPUT_MODE_SUPPORT__ ) 
uint8 i2s_change_outdev = 0; 
kal_uint32 I2S_Output_Device;
#endif

// 0 -> 1 -> 2 -> 3 -> 4 -> 1 -> 0 
#define TONE_STATE_NONE 0
#define TONE_STATE_IDLE 1
#define TONE_STATE_INIT 2
#define TONE_STATE_PLAY 3
#define TONE_STATE_STOP 4
#define TONE_STATE_UNHOOKING 5
#define TONE_STATE_UNHOOKED  6

#if IS_EV_BOARD
#define KT_INIT_AMP     0x1000
#else
#define KT_INIT_AMP     0x3FFF
#endif

#if IS_EV_BOARD
#define TONE_INIT_AMP   0x1000
#else
#define TONE_INIT_AMP   0x1FFF
#endif

static struct
{
   const L1SP_Tones  *tonelist;
   const L1SP_QTMF   *curr_qtmf;
   void              (*handler)(void);
   uint16            aud_id;
   uint16            amp;
   bool              bQTMF;

   kal_uint16        fc_aud_id;
   kal_uint8         state;
   kal_bool          isReentrance;
   kal_bool          isOnDur;
   kal_bool          isWait;
   kal_uint8         seqNum;
   AUD_TONE_INFO     *info;
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   
#ifdef BGSND_ENABLE
   void (*sndOnHandler)(void *hdl); 
   void (*sndOffHandler)(void *hdl);
   void *sndHdl;
#endif   
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   

} tone;

static struct
{
   uint16            aud_id;
   int8              lock;
   uint8             volume1;
   int8             digital_gain_index;
#if defined(__GAIN_TABLE_SUPPORT__)
   uint32            gain;
#endif

   kal_uint16        fc_aud_id;
   kal_uint8         state;
   kal_bool          isReentrance;
   kal_bool          isWait;
   kal_uint8         seqNum;
   kal_bool          isBlocking;
   AUD_TONE_INFO     *info;
#ifdef BGSND_ENABLE
   void (*sndOnHandler)(void *hdl); 
   void (*sndOffHandler)(void *hdl);
   void *sndHdl;
#endif   

} keytone;


__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI"))) 
   AUD_TONE_INFO toneInfo;
__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI"))) 
   AUD_TONE_INFO ktInfo;


/* ------------------------------------------------------------------------------ */
/*  Check tone state                                           */
/* ------------------------------------------------------------------------------ */
kal_bool Tone_KT_CheckWait(kal_uint32 msg)
{
   kal_uint32 fc_aud_id = msg & 0xFFFF;
   
   if ( (fc_aud_id == keytone.fc_aud_id) && (!keytone.isWait) )
      return false;
   
   if ( (fc_aud_id == tone.fc_aud_id) && (!tone.isWait) )
      return false;
   
   return true;
}

/* ------------------------------------------------------------------------------ */
/*  Functions for Playing Comfort Tones                                           */
/* ------------------------------------------------------------------------------ */
static void tonePlayOff( void *data );

static void toneStop( void *data )
{
   if (tone.state == TONE_STATE_NONE)
      return;

   if( !L1Audio_CheckFlag( tone.aud_id ) )
      return;

   if (tone.isReentrance)
      return;
   else
      tone.isReentrance = true;

   tone.bQTMF = false;
   
   if (tone.state == TONE_STATE_INIT) {
      int I;
      
      for (I = 0; ; I++) {
         if (tone.state != TONE_STATE_INIT)
            break;
         
         ASSERT_REBOOT( I < 20 );
         kal_sleep_task( 2 );
      }
   }
   
   if (tone.state == TONE_STATE_PLAY) {
      tone.state = TONE_STATE_STOP;
      tone.isWait = true;
      L1Audio_FC_TonePlaybackOff(tone.fc_aud_id);
      tone.isWait = false;
      tone.state = TONE_STATE_IDLE;
   }
   
   if (tone.state == TONE_STATE_IDLE) {
      tone.state = TONE_STATE_NONE;
      L1Audio_FC_UnHookHandler(tone.fc_aud_id, 0);
      tone.fc_aud_id = 0xFFFF;
   }
   
   AM_ToneOff();
   AFE_TurnOffSpeaker( L1SP_TONE );
   L1Audio_ClearFlag( tone.aud_id );
   tone.seqNum++;
   L1Audio_SetEvent( tone.aud_id, 0 );
}

static void tonePlayOn( void *data )
{
   tone.isOnDur = true;

   if( tone.bQTMF ) {
      tone.curr_qtmf = (L1SP_QTMF *)tone.tonelist + (uint32)data;
      
      tone.info->freq1 = tone.curr_qtmf->freq1;
      tone.info->freq2 = tone.curr_qtmf->freq2;
      tone.info->freq3 = tone.curr_qtmf->freq3;
      tone.info->freq4 = tone.curr_qtmf->freq4;
   } else {
      tone.curr_qtmf = (L1SP_QTMF *)(tone.tonelist + (uint32)data);
      
      tone.info->freq1 = tone.curr_qtmf->freq1;
      tone.info->freq2 = tone.curr_qtmf->freq2;
      tone.info->freq3 = 0;
      tone.info->freq4 = 0;
   }

   if (tone.curr_qtmf->on_duration == 0) {
      tone.info->msDur = -1;
   } else {
      tone.info->msDur = tone.curr_qtmf->on_duration;
   }

      AFE_TurnOnSpeaker( L1SP_TONE ); 
      kal_sleep_task(1);
   
   tone.state = TONE_STATE_INIT;
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/ 
#ifdef BGSND_ENABLE
   if (tone.sndOffHandler != NULL)
      tone.sndOffHandler( tone.sndHdl );
#endif      
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/    
   
   L1Audio_FC_TonePlaybackOn(tone.fc_aud_id, tone.info);

   // apply hardware mute during tone playback 
   //AFE_TurnOnSpeaker( L1SP_TONE ); 
}

static void toneMute( void *data )
{
   int32 dura = (int32)data;
   
   AFE_TurnOffSpeaker( L1SP_TONE );
   
   tone.info->freq1 = 0;
   tone.info->freq2 = 0;
   tone.info->freq3 = 0;
   tone.info->freq4 = 0;
   tone.info->msDur = dura;
   
   tone.state = TONE_STATE_INIT; 
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/ 
#ifdef BGSND_ENABLE
   if (tone.sndOffHandler != NULL)
      tone.sndOffHandler( tone.sndHdl );
#endif      
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/     
     
   L1Audio_FC_TonePlaybackOn(tone.fc_aud_id, tone.info);
}

static void tonePlayOff( void *data )
{
   uint16 dura = tone.curr_qtmf->off_duration;
   
   tone.isOnDur = false;
   
   if( dura == 0 )
      toneStop( 0 );
   else
      toneMute( (void*)dura );
}

static void toneHandler( void *data )     /* This function works in L1Audio Task */
{
   (void)data;
   if( tone.handler != 0 )
      tone.handler();
}

void toneInit( uint16 aud_id )
{
   tone.aud_id    = aud_id;
   tone.handler   = 0;
   L1Audio_SetEventHandler( aud_id, toneHandler );

   tone.amp = TONE_INIT_AMP;
   tone.bQTMF = false;
   tone.state = TONE_STATE_NONE;
   tone.isWait = false;
   tone.seqNum = 0;
   tone.info = &toneInfo;

   AFE_TurnOnFIR( L1SP_TONE );
}

/* ------------------------------------------------------------------------------ */
/*  Tone Interface                                                                */
/* ------------------------------------------------------------------------------ */
void TONE_SetOutputDevice( uint8 device )
{
   AFE_SetOutputDevice( L1SP_TONE, device );
}

void TONE_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
   AFE_SetOutputVolume( L1SP_TONE, volume1, digital_gain_index );
}

#if defined(__GAIN_TABLE_SUPPORT__)
void TONE_SetOutputGainControl( uint32 gain )
{
   AFE_SetOutputGainControl( L1SP_TONE, gain );
}
#endif

/*****************************************************************************
* FUNCTION
*  TONE_PlayQTMF
* DESCRIPTION
*   This function is used to play comfort tones.
*   Totally 4 frequencies can be generated
*
* PARAMETERS
*  tonelist - QTMF list
* RETURNS
*  None.
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void TONE_PlayQTMF( const L1SP_QTMF *tonelist )
{
   if( L1Audio_CheckFlag( tone.aud_id ) )
      return;
   tone.bQTMF = true;
   TONE_Play((const L1SP_Tones *)tonelist);
}



static void tonePlayInMedTask(kal_uint32 arg1, void *arg2)
{
   if (arg1 != tone.seqNum)
      return;
   
   if (tone.isOnDur) {
      // To play off duration
      tonePlayOff(0);
   } else {
      // To play on duration
      tonePlayOn( (void *)tone.curr_qtmf->next_tone );
   }
}

static void toneMsgHandler(kal_uint16 msgOp, kal_uint32 msgData, void *userData)
{
   switch (msgOp) {
      case MSG_SAC2L1AUDIO_AUDIO_PLAYBACK_ON_ACK:
         ASSERT( tone.state == TONE_STATE_INIT);
         tone.state = TONE_STATE_PLAY;
         break;
      case MSG_SAC2L1AUDIO_AUDIO_PLAYBACK_OFF_ACK:
         if (tone.state == TONE_STATE_PLAY) {
            tone.state = TONE_STATE_IDLE;
            L1Audio_InProcCall( tonePlayInMedTask, tone.seqNum, 0 );
         } else if (tone.state == TONE_STATE_STOP) {
            tone.state = TONE_STATE_IDLE;
         } else {
            return;
         }
         
         if (tone.isReentrance)
            return;
         
         break;
      default:
         ASSERT(0);
   }
}


/*****************************************************************************
* FUNCTION
*  TONE_Play
* DESCRIPTION
*   This function is used to play comfort tones.
*
* PARAMETERS
*  tonelist - Tone list
* RETURNS
*  None.
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void TONE_Play( const L1SP_Tones *tonelist )
{
   if( L1Audio_CheckFlag( tone.aud_id ) )
      return;

   if (tone.state != TONE_STATE_NONE)
      return;

   if( L1Audio_CheckFlag( keytone.aud_id ) ) {
      KT_StopAndWait();
   }

   L1Audio_SetFlag( tone.aud_id );
   tone.tonelist = tonelist;
   
   tone.fc_aud_id = L1Audio_FC_HookHandler( (void *)0, toneMsgHandler, 0, (FC_MEDIA_FORMAT_QTMF<<8)|MEDIA_OPERATE_PLAYBACK );
   tone.state = TONE_STATE_IDLE;
   
   tone.isReentrance = false;
   tone.seqNum++;
   tonePlayOn( 0 );
   
   AM_ToneOn();
}

/*****************************************************************************
* FUNCTION
*  TONE_Stop
* DESCRIPTION
*   This function is used to stop playing comfort tones.
*
* PARAMETERS
*  None
* RETURNS
*  None
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void TONE_Stop( void )
{
   tone.seqNum++;
   toneStop( 0 );
}

void TONE_StopAndWait( void )
{
   kal_trace( TRACE_INFO, TONE_STOP_AND_WAIT );
   AM_FlushQFunction();
   TONE_Stop();
}

void TONE_SetAmplitude( int16 amp )
{
   tone.amp = (uint16)amp;
}

void TONE_SetFIR( bool enable )
{
   if( enable )
      AFE_TurnOnFIR( L1SP_TONE );
   else
      AFE_TurnOffFIR( L1SP_TONE );
}

void TONE_SetHandler( void (*handler)(void) )
{
   tone.handler = handler;
}

/* ------------------------------------------------------------------------------ */
/*  Keytone Interface                                                             */
/* ------------------------------------------------------------------------------ */
kal_bool KT_Check_ID(kal_uint32 id)
{
   if (id != keytone.fc_aud_id)
      return KAL_FALSE;

   if (keytone.state == TONE_STATE_UNHOOKING) {
      keytone.state = TONE_STATE_UNHOOKED;
   }
   
   if (keytone.isBlocking)
      return false;
   
   return true;
}

static void ktStop( void *data );

static void ktStopInMedTask(kal_uint32 arg1, void *arg2)
{   
   ktStop( (void *)1 );
}

static void ktStop_blocking( void *data )
{
   int I;
   
   if (keytone.state == TONE_STATE_NONE)
      return;

   if( !L1Audio_CheckFlag( keytone.aud_id ) )
      return;

   if (keytone.state == TONE_STATE_INIT) {
      for (I = 0; ; I++) {
         if (keytone.state != TONE_STATE_INIT)
            break;
         
         ASSERT_REBOOT( I < 120 );
         kal_sleep_task( 2 );
      }
   }
   
   if (keytone.state == TONE_STATE_PLAY) {
      keytone.state = TONE_STATE_STOP;
      keytone.isWait = true;
      L1Audio_FC_TonePlaybackOff(keytone.fc_aud_id);
      keytone.isWait = false;
      keytone.state = TONE_STATE_IDLE;
   }
   
   if (keytone.state == TONE_STATE_STOP) {
      for (I = 0; ; I++) {
         if (keytone.state == TONE_STATE_IDLE)
            break;
         
         ASSERT_REBOOT( I < 120 );
         kal_sleep_task( 2 );
      }
   }
   
   if (keytone.state == TONE_STATE_UNHOOKING) {
      for (I = 0; ; I++) {
         if (keytone.state == TONE_STATE_UNHOOKED)
            break;
         
         ASSERT_REBOOT( I < 120 );
         kal_sleep_task( 2 );
      }
      return;
   }
   
   if (keytone.state == TONE_STATE_UNHOOKED) {
      keytone.state = TONE_STATE_NONE;
      L1Audio_FC_UnHookHandler_WithoutWaitingClear(keytone.fc_aud_id, 0);
      keytone.fc_aud_id = 0xFFFF;
   }
   
   if (keytone.state == TONE_STATE_IDLE) {
      keytone.state = TONE_STATE_NONE;
      L1Audio_FC_UnHookHandler(keytone.fc_aud_id, 0);
      keytone.fc_aud_id = 0xFFFF;
   }

   AM_KeyToneOff();
   L1Audio_ClearFlag( keytone.aud_id );
}

static void ktStop_nonblocking( void *data )
{
   if (keytone.state == TONE_STATE_NONE)
      return;

   if( !L1Audio_CheckFlag( keytone.aud_id ) )
      return;

   keytone.isReentrance = true;

   if (keytone.state == TONE_STATE_INIT) {
      L1Audio_InProcCall( ktStopInMedTask, keytone.seqNum, 0 );
      kal_sleep_task( 2 );
   }
   
   if (keytone.state == TONE_STATE_PLAY) {
      keytone.state = TONE_STATE_STOP;
      L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_AUDIO_PLAYBACK_OFF, keytone.fc_aud_id, 0, false);
   }
   
   if (keytone.state == TONE_STATE_STOP) {
      L1Audio_InProcCall( ktStopInMedTask, keytone.seqNum, 0 );
      kal_sleep_task( 2 );
      return;
   }
   
   if (keytone.state == TONE_STATE_IDLE) {
      keytone.state = TONE_STATE_UNHOOKING;
      L1Audio_FC_UnHookHandler_WithoutWaitingSend(keytone.fc_aud_id, 0);
   }
   
   if (keytone.state == TONE_STATE_UNHOOKING) {
      L1Audio_InProcCall( ktStopInMedTask, keytone.seqNum, 0 );
      kal_sleep_task( 2 );
      return;
   }
   
   if (keytone.state == TONE_STATE_UNHOOKED) {
      keytone.state = TONE_STATE_NONE;
      L1Audio_FC_UnHookHandler_WithoutWaitingClear(keytone.fc_aud_id, 0);
      keytone.fc_aud_id = 0xFFFF;
   }
   
   AM_KeyToneOff();
   L1Audio_ClearFlag( keytone.aud_id );
   
   keytone.seqNum++;
}

static void ktStop( void *data )
{
   if (keytone.isBlocking) {
      ktStop_blocking(data);
   } else {
      ktStop_nonblocking(data);
   }
}

void ktInit( uint16 aud_id )
{
   keytone.aud_id = aud_id;
   keytone.lock   = 0;
   keytone.volume1 = 160;
#if defined(__GAIN_TABLE_SUPPORT__)
   keytone.gain = 0;
#endif
   keytone.digital_gain_index = 0;
   keytone.state = TONE_STATE_NONE;
   keytone.isReentrance = false;
   keytone.isWait = false;
   keytone.seqNum = 0;
   keytone.fc_aud_id = 0xFFFF;
   keytone.info = &ktInfo;
   AFE_TurnOnFIR( L1SP_KEYTONE );
}

void ktLock( void )
{
   uint32 savedMask;

   ASSERT( keytone.lock < 8 );
   savedMask = SaveAndSetIRQMask();
   keytone.lock++;
   RestoreIRQMask(savedMask);
}

void ktUnlock( void )
{
   uint32 savedMask;

   ASSERT( keytone.lock > 0 );
   savedMask = SaveAndSetIRQMask();
   keytone.lock--;
   RestoreIRQMask(savedMask);
}

void KT_SetOutputDevice( uint8 device )
{
   if( L1Audio_CheckFlag( keytone.aud_id ) ) { 
      KT_StopAndWait();
   }
   AFE_SetOutputDevice( L1SP_KEYTONE, device );
}

void KT_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
   keytone.volume1 = volume1;
   keytone.digital_gain_index = digital_gain_index;
}

#if defined(__GAIN_TABLE_SUPPORT__)
void KT_SetOutputGainControl( uint32 gain )
{
   keytone.gain = gain;
   AFE_SetOutputGainControl(L1SP_KEYTONE, gain);
}
#endif

/*****************************************************************************
* FUNCTION
*  KT_Play
* DESCRIPTION
*   This function is used to play keytone.
*
* PARAMETERS
*  freq1 - The first frequency
*  freq2 - The second frequency
*  duration - Duration of the tone
* RETURNS
*  None.
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#if defined(KEYTONE_DEBUG)
uint16 m_para[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

#ifdef BT_Loopback_Test
kal_bool	BT_PROCESS_END;
extern uint32 BT_Loopback_Start(void(*callback)( void ) , kal_char *play_filename , kal_char *record_filename);
extern void BtRadio_SetupPCMGpioPins(void);
void BT_Loopback_Callback(void)
{
	BT_PROCESS_END = true;
}
#define SPH_MODE_BT_CORDLESS 4
#endif //#ifdef BT_Loopback_Test

void Key1Event( void )
{
   
#ifdef BT_Loopback_Test
   L1SP_Speech_Off();
   L1SP_SetOutputDevice(L1SP_SPEAKER1);
   L1SP_SetSpeechMode(SPH_MODE_BT_CORDLESS, m_para);
   L1SP_Speech_On(0);
#endif

#ifdef BT_Cordless_Test
   L1SP_Speech_Off();
   L1SP_SetOutputDevice(L1SP_SPEAKER1);
   L1SP_SetSpeechMode(SPH_MODE_BT_CORDLESS, m_para);
   L1SP_Cordless_On();
#endif

   return;   
}

void Key2Event( void )
{
#ifdef BT_Loopback_Test
   uint16 m_para_BT_Earphone[16] = {64,   223,     0,     30,    7,  20510,   400,     0,
                                    0,     0,     0,       0,    0,       0,    0,     0};
   
   L1SP_Speech_Off();
   L1SP_SetOutputDevice(L1SP_SPEAKER1);
   L1SP_SetSpeechMode(SPH_MODE_BT_EARPHONE, m_para_BT_Earphone);
   L1SP_Speech_On(0);
#endif

#ifdef BT_Cordless_Test
   uint16 m_para_BT_Earphone[16] = {64,   223,     0,     30,    7,  20510,   400,     0,
                                    0,     0,     0,       0,    0,       0,    0,     0};
   L1SP_Cordless_Off();
   L1SP_SetOutputDevice(L1SP_SPEAKER1);
   L1SP_SetSpeechMode(SPH_MODE_BT_EARPHONE, m_para_BT_Earphone);
   L1SP_Speech_On(0);
#endif
   return;   
}

void Key3Event( void )
{
#ifdef BT_Loopback_Test
   L1SP_Speech_Off();
   L1SP_SetOutputDevice(L1SP_SPEAKER1);
   L1SP_SetSpeechMode(SPH_MODE_BT_CORDLESS, m_para);
#endif
   return;   
}

void Key4Event( void )
{
#ifdef BT_Loopback_Test
      uint16 m_para_BT_Earphone[16] = {64,   223,     0,     30,    7,  20510,   400,     0,
                                       0,     0,     0,       0,    0,       0,    0,     0};
      
      L1SP_Speech_Off();
      L1SP_SetOutputDevice(L1SP_SPEAKER1);
      L1SP_SetSpeechMode(SPH_MODE_BT_EARPHONE, m_para_BT_Earphone); 
      //BtRadio_SetupPCMGpioPins();  
#endif         
   return;   
}

void Key5Event( void )
{    

   return;   
}

void Key6Event( void )
{  
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"1.wav","BTout1.pcm");    
#endif
   return;   
}

void Key7Event( void )
{
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"2.wav","BTout2.pcm");    
#endif
   return;   
}

void Key8Event( void )
{
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"3.wav","BTout3.pcm");     
#endif
   return;   
}

void Key9Event( void )
{
#ifdef BT_Loopback_Test
   BT_Loopback_Start(BT_Loopback_Callback,"4.wav","BTout4.pcm");  
#endif
   return;   
}
//===================================================================
#ifdef BT_Loopback_Test
void Key11Event( void )
{
   BT_Loopback_Start(BT_Loopback_Callback,"5.wav","BTout5.pcm"); 
   return;   
}

void Key12Event( void )
{   
   BT_Loopback_Start(BT_Loopback_Callback,"6.wav","BTout6.pcm"); 
   return;   
}

void Key13Event( void )
{
   BT_Loopback_Start(BT_Loopback_Callback,"7.wav","BTout7.pcm"); 
   return;   
}

void Key14Event( void )
{   
   BT_Loopback_Start(BT_Loopback_Callback,"8.wav","BTout8.pcm"); 
   return;   
}

void Key15Event( void )
{    
   BT_Loopback_Start(BT_Loopback_Callback,"9.wav","BTout9.pcm"); 
   return;   
}

void Key16Event( void )
{  
   BT_Loopback_Start(BT_Loopback_Callback,"10.wav","BTout10.pcm");    
   return;   
}

void Key17Event( void )
{
   BT_Loopback_Start(BT_Loopback_Callback,"11.wav","BTout11.pcm");  
   return;   
}

void Key18Event( void )
{
   BT_Loopback_Start(BT_Loopback_Callback,"12.wav","BTout12.pcm");     
   return;   
}

void Key19Event( void )
{
   BT_Loopback_Start(BT_Loopback_Callback,"13.wav","BTout13.pcm");   
   return;   
}

//===================================================================
void Key21Event( void )
{
   BT_Loopback_Start(BT_Loopback_Callback,"14.wav","BTout14.pcm");  
   return;   
}

void Key22Event( void )
{   
   BT_Loopback_Start(BT_Loopback_Callback,"15.wav","BTout15.pcm");  
   return;   
}

void Key23Event( void )
{
   BT_Loopback_Start(BT_Loopback_Callback,"16.wav","BTout16.pcm");  
   return;   
}

void Key24Event( void )
{   
   BT_Loopback_Start(BT_Loopback_Callback,"17.wav","BTout17.pcm");  
   return;   
}

void Key25Event( void )
{   
   BT_Loopback_Start(BT_Loopback_Callback,"18.wav","BTout18.pcm");  
   return;   
}

void Key26Event( void )
{  
   BT_Loopback_Start(BT_Loopback_Callback,"19.wav","BTout19.pcm");     
   return;   
}

void Key27Event( void )
{
   BT_Loopback_Start(BT_Loopback_Callback,"20.wav","BTout20.pcm");   
   return;   
}

void Key28Event( void )
{
   BT_Loopback_Start(BT_Loopback_Callback,"21.wav","BTout21.pcm");      
   return;   
}

void Key29Event( void )
{
   BT_Loopback_Start(BT_Loopback_Callback,"22.wav","BTout22.pcm");    
   return;   
}
//===================================================================
void Key31Event( void )
{
   BT_Loopback_Start(BT_Loopback_Callback,"23.wav","BTout23.pcm");  
   return;   
}

void Key32Event( void )
{   
   BT_Loopback_Start(BT_Loopback_Callback,"24.wav","BTout24.pcm");  
   return;   
}

void Key33Event( void )
{
   BT_Loopback_Start(BT_Loopback_Callback,"25.wav","BTout25.pcm");  
   return;   
}

void Key34Event( void )
{   
   BT_Loopback_Start(BT_Loopback_Callback,"26.wav","BTout26.pcm");  
   return;   
}

void Key35Event( void )
{ 
   BT_Loopback_Start(BT_Loopback_Callback,"27.wav","BTout27.pcm");  
   return;   
}

void Key36Event( void )
{  
   BT_Loopback_Start(BT_Loopback_Callback,"28.wav","BTout28.pcm");     
   return;   
}

void Key37Event( void )
{
   BT_Loopback_Start(BT_Loopback_Callback,"29.wav","BTout29.pcm");   
   return;   
}

void Key38Event( void )
{
   BT_Loopback_Start(BT_Loopback_Callback,"30.wav","BTout30.pcm");      
   return;   
}

void Key39Event( void )
{
   BT_Loopback_Start(BT_Loopback_Callback,"31.wav","BTout31.pcm");   
   return;   
}
//===================================================================
#endif

static uint8 KeyFlags = 0;
static uint8 KeyCommand = 0;
static uint8 KeyFlags1 = 0;
static uint8 KeyCommand1 = 0;
static uint8 KeyFlags2 = 0;
static uint8 KeyCommand2 = 0;
static uint8 KeyFlags3 = 0;
static uint8 KeyCommand3 = 0;
#endif//#if defined(KEYTONE_DEBUG)



static void ktMsgHandler(kal_uint16 msgOp, kal_uint32 msgData, void *userData)
{
   switch (msgOp) {
      case MSG_SAC2L1AUDIO_AUDIO_PLAYBACK_ON_ACK:
         ASSERT( keytone.state == TONE_STATE_INIT);
         keytone.state = TONE_STATE_PLAY;
         break;
      case MSG_SAC2L1AUDIO_AUDIO_PLAYBACK_OFF_ACK:
         if (keytone.state == TONE_STATE_PLAY) {
            keytone.state = TONE_STATE_IDLE;
            L1Audio_InProcCall( ktStopInMedTask, keytone.seqNum, 0 );
         } else if (keytone.state == TONE_STATE_STOP) {
            keytone.state = TONE_STATE_IDLE;
            if (!keytone.isBlocking) {
               L1Audio_InProcCall( ktStopInMedTask, keytone.seqNum, 0 );
            }
         } else {
            return;
         }

         break;
      default:
         ASSERT(0);
   }
}


void KT_Play( uint16 freq1, uint16 freq2, uint16 duration )
{
   
#if defined(KEYTONE_DEBUG)
   uint8 pressed_key;   
   
   pressed_key = 0;
   
   switch(freq1) {
      case 697:
         pressed_key = 1;
         break;
      case 770:
         pressed_key = 4;
         break;
      case 852:
         pressed_key = 7;
         break;
      case 941:
         pressed_key = 10;  //*
         break;
   }
   switch(freq2) {
      case 1209:
         pressed_key += 0;
         break;
      case 1336:
         pressed_key += 1;
         break;
      case 1477:
         pressed_key += 2;
         break;
   }

//===================================================================
	
   if(pressed_key == 10)  // * 
      KeyFlags = 0x1;
   else if(pressed_key == 12)  // #   
   {
      if(KeyFlags == 0x3)
      {
         switch(KeyCommand)
         {
            case 1:  
               Key1Event();
               break;
            case 2:
               Key2Event();               
               break;
            case 3:               
               Key3Event();   
               break;
            case 4:             
               Key4Event();                             
               break;
            case 5:  
               Key5Event();                      
               break;            
            case 6: 
               Key6Event();             
               break;   
            case 7: 
               Key7Event();                     
               break;            
            case 8:
               Key8Event();                            
               break; 
            case 9:                            
               Key9Event();
               break;
            default: 
               ASSERT(false);                           
         }            
      }      
      KeyFlags = 0;                           
   }
   else 
   {
      if(KeyFlags == 0x1)
      {
         switch(pressed_key)
         {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5: 
            case 6: 
            case 7:
            case 8:
            case 9: 
               KeyCommand = pressed_key;      
               KeyFlags = 0x3;
               break;
            default:
               KeyCommand = 0;
               KeyFlags = 0;
         }
      }
      else 
         KeyFlags = 0;
   }
#ifdef BT_Loopback_Test
   if(pressed_key == 12)  // # 
      KeyFlags1 = 0x11;
   else if(pressed_key == 10)  // *   
   {
      if(KeyFlags1 == 0x31)
      {
         switch(KeyCommand1)
         {
            case 1:  
               Key11Event();
               break;
            case 2:
               Key12Event();               
               break;
            case 3:               
               Key13Event();   
               break;
            case 4:             
               Key14Event();                             
               break;
            case 5:  
               Key15Event();                      
               break;            
            case 6: 
               Key16Event();             
               break;   
            case 7: 
               Key17Event();                     
               break;            
            case 8:
               Key18Event();                            
               break; 
            case 9:                            
               Key19Event();
               break;
            default: 
               ASSERT(false);                           
         }            
      }      
      KeyFlags1 = 0;                           
   }
   else 
   {
      if(KeyFlags1 == 0x11)
      {
         switch(pressed_key)
         {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5: 
            case 6: 
            case 7:
            case 8:
            case 9: 
               KeyCommand1 = pressed_key;      
               KeyFlags1 = 0x31;
               break;
            default:
               KeyCommand1 = 0;
               KeyFlags1 = 0;
         }
      }
      else 
         KeyFlags1 = 0;
   }   

//===================================================================
   if(pressed_key == 10)  // * 
      KeyFlags2 = 0x21;
   else if(pressed_key == 11)  // 0
   {
      if(KeyFlags2 == 0x32)
      {
         switch(KeyCommand2)
         {
            case 1:  
               Key21Event();
               break;
            case 2:
               Key22Event();               
               break;
            case 3:               
               Key23Event();   
               break;
            case 4:             
               Key24Event();                             
               break;
            case 5:  
               Key25Event();                      
               break;            
            case 6: 
               Key26Event();             
               break;   
            case 7: 
               Key27Event();                     
               break;            
            case 8:
               Key28Event();                            
               break; 
            case 9:                            
               Key29Event();
               break;
            default: 
               ASSERT(false);                           
         }            
      }      
      KeyFlags2 = 0;                           
   }
   else 
   {
      if(KeyFlags2 == 0x21)
      {
         switch(pressed_key)
         {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5: 
            case 6: 
            case 7:
            case 8:
            case 9: 
               KeyCommand2 = pressed_key;      
               KeyFlags2 = 0x32;
               break;
            default:
               KeyCommand2 = 0;
               KeyFlags = 0;
         }
      }
      else 
         KeyFlags2 = 0;
   }     

//===================================================================
   if(pressed_key == 12)  // #
      KeyFlags3 = 0x31;
   else if(pressed_key == 11)  // 0
   {
      if(KeyFlags3 == 0x33)
      {
         switch(KeyCommand3)
         {
            case 1:  
               Key31Event();
               break;
            case 2:
               Key32Event();               
               break;
            case 3:               
               Key33Event();   
               break;
            case 4:             
               Key34Event();                             
               break;
            case 5:  
               Key35Event();                      
               break;            
            case 6: 
               Key36Event();             
               break;   
            case 7: 
               Key37Event();                     
               break;            
            case 8:
               Key38Event();                            
               break; 
            case 9:                            
               Key39Event();
               break;
            default: 
               ASSERT(false);                           
         }            
      }      
      KeyFlags3 = 0;                           
   }
   else 
   {
      if(KeyFlags3 == 0x31)
      {
         switch(pressed_key)
         {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5: 
            case 6: 
            case 7:
            case 8:
            case 9: 
               KeyCommand3 = pressed_key;      
               KeyFlags3 = 0x33;
               break;
            default:
               KeyCommand3 = 0;
               KeyFlags3 = 0;
         }
      }
      else 
         KeyFlags3 = 0;
   }
   
   return;
#endif // #ifdef BT_Loopback_Test

#endif//#if defined(KEYTONE_DEBUG)

   if( keytone.lock > 0 || keytone.volume1 == 0 )
      return;
   if( mediaKeytoneForbidden() || AM_IsDAIMode() )
      return;
   if( L1Audio_CheckFlag( keytone.aud_id ) || L1Audio_CheckFlag( tone.aud_id ) )
      return;

   if (keytone.state != TONE_STATE_NONE)
      return;

   L1Audio_SetFlag( keytone.aud_id );

#if defined(__GAIN_TABLE_SUPPORT__)
   AFE_SetOutputGainControl(L1SP_KEYTONE,keytone.gain);
#else
   AFE_SetOutputVolume( L1SP_KEYTONE, keytone.volume1, keytone.digital_gain_index );
#endif

   keytone.fc_aud_id = L1Audio_FC_HookHandler( (void *)0, ktMsgHandler, 0, (FC_MEDIA_FORMAT_QTMF<<8)|MEDIA_OPERATE_PLAYBACK );
   keytone.state = TONE_STATE_IDLE;
   
   keytone.info->freq1 = freq1;
   keytone.info->freq2 = freq2;
   keytone.info->freq3 = 0;
   keytone.info->freq4 = 0;
   if (duration == 0) {
      keytone.info->msDur = -1;
   } else {
      keytone.info->msDur = duration;
   }
   
   AM_KeyToneOn(); 
   kal_sleep_task(1);
   
   keytone.state = TONE_STATE_INIT;
   keytone.isReentrance = false;
   keytone.seqNum++;
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/ 
#ifdef BGSND_ENABLE
   if (keytone.sndOffHandler != NULL)
      keytone.sndOffHandler( keytone.sndHdl );
#endif      
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/    
   
   L1Audio_FC_TonePlaybackOn(keytone.fc_aud_id, keytone.info);
   
   //AM_KeyToneOn(); 
}

/*****************************************************************************
* FUNCTION
*  KT_Stop
* DESCRIPTION
*   This function is used to stop key tone playing.
*****************************************************************************/
void KT_Stop( void )
{
   if (keytone.isReentrance)
      return;
   
   ktStop( (void *)0 );
}

void KT_StopAndWait(void)
{
   kal_trace( TRACE_INFO, KT_STOP_AND_WAIT );
   keytone.isBlocking = true;
   ktStop( (void *)0 );
   keytone.isBlocking = false;
}

void KT_SetAmplitude( int16 amp )
{

}

void KT_SetFIR( bool enable )
{
   if( enable )
      AFE_TurnOnFIR( L1SP_KEYTONE );
   else
      AFE_TurnOffFIR( L1SP_KEYTONE);
}

/* To indicate if the keytone can be play */
kal_bool KT_IsPlayable(void)
{
   if( keytone.lock > 0 || keytone.volume1 == 0 )
      return KAL_FALSE;
   if( mediaKeytoneForbidden() || AM_IsDAIMode() )
      return KAL_FALSE;
   if( L1Audio_CheckFlag( keytone.aud_id ) || L1Audio_CheckFlag( tone.aud_id ) )
      return KAL_FALSE;
   return KAL_TRUE;
}

/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   
#ifdef BGSND_ENABLE
void TONE_Register_SndService(
   void (*onHandler)(void *hdl),
   void (*offHandler)(void *hdl),
   void *hdl)
{
   tone.sndOnHandler  = onHandler;
   tone.sndOffHandler = offHandler;
   tone.sndHdl        = hdl;
}

void TONE_UnRegister_SndService( void )
{
   tone.sndOnHandler  = NULL;
   tone.sndOffHandler = NULL;
}

void KT_Register_SndService(
   void (*onHandler)(void *hdl),
   void (*offHandler)(void *hdl),
   void *hdl)
{
   keytone.sndOnHandler  = onHandler;
   keytone.sndOffHandler = offHandler;
   keytone.sndHdl        = hdl;
}

void KT_UnRegister_SndService( void )
{
   keytone.sndOnHandler  = NULL;
   keytone.sndOffHandler = NULL;
}
#endif
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   
