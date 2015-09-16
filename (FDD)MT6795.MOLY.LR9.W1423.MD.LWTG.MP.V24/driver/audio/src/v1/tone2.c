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
 * Tone Interface
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
#include "dcl.h"
#include "reg_base.h"

#include "common_def.h"
#include "l1audio.h"
#include "media.h"
#include "afe.h"
#include "am.h"
#include "speech_def.h"
#include "audio_def.h"
#include "afe_def.h"

uint32   SaveAndSetIRQMask( void );
void     RestoreIRQMask( uint32 );


#define KT_INIT_AMP     0x3FFF
#define TONE_INIT_AMP   0x1FFF

static struct
{
   const L1SP_Tones  *tonelist;
   const L1SP_QTMF   *curr_qtmf;
   void              (*handler)(void);
   uint32            gpt;
   uint16            aud_id;
   uint16            amp;
   bool              bQTMF;
   bool              isRun;
} tone;

static struct
{
   uint32            gpt;
   uint16            aud_id;
   int8              lock;
   uint8             volume1;
   int8             digital_gain_index;
   bool              isRun;
} keytone;


#define DSP_QTMF_FREQ(f1,f2,f3,f4)  {  DSP_TONE_F2A  = (f1);                \
                                       DSP_TONE_F2B  = (f2);                \
                                       DSP_TONE_F1A  = (tone.bQTMF)?(f3):0; \
                                       DSP_TONE_F1B  = (tone.bQTMF)?(f4):0; }

#define DSP_KT_FREQ(f1,f2)    {  DSP_TONE_F2A  = (f1);               \
                                 DSP_TONE_F2B  = (f2);               }

/* When Audio Ramp Down Enable, MCU waits until Audio RampDown of DSP.  If the time of DSP's RampDown exceeds this value, the beginning part of Tone maybe be cut */
#define SW_WAIT_AUDIO_RAMPDOWN (6)

/* ------------------------------------------------------------------------------ */
/*  Functions for Playing Comfort Tones                                           */
/* ------------------------------------------------------------------------------ */
static void tonePlayOff( void *data );

void toneStop_FlushQueue( void *data )
{
   if(AM_IsToneOn())
   {
      SGPT_CTRL_START_T start;
      start.u2Tick = 1;
      start.pfCallback = toneStop_FlushQueue;
      start.vPara = data;
      DclSGPT_Control( tone.gpt, SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
   } else {
      L1Audio_ClearFlag( tone.aud_id );
   }
}

static void toneStop( void *data )
{
   uint16 tone_ctrl;
   SGPT_CTRL_START_T start;

   if( !L1Audio_CheckFlag( tone.aud_id ) )
      return;
   tone_ctrl = (DSP_TONE_CTRL2 << 8) + DSP_TONE_CTRL1;
   switch( tone_ctrl ) {
   case 0:
      if (tone.isRun) {
         tone.isRun = false;
         tone.bQTMF = false;
         AM_ToneOff();
         DP_KT_ATT = 0;
         L1Audio_SetEvent( tone.aud_id, 0 );
         
         // unapply hardware mute during tone playback
         *AFE_AMCU_CON1 &= ~0x30;

#if defined(__BT_SUPPORT__)
         if( L1SP_GetSpeechMode() == SPH_MODE_LINEIN_VIA_BT_CORDLESS )
            *DP_AUDIO_PAR = (*DP_AUDIO_PAR & 0xFF) | 0x1000; // set back to cordless mode
#endif
      }
      start.u2Tick = 1;
      start.pfCallback = toneStop_FlushQueue;
      start.vPara = data;
      DclSGPT_Control( tone.gpt, SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
      break;
   case 0x202:
      DSP_TONE_CTRL1 = 4;
      DSP_TONE_CTRL2 = 4;
   default:
      start.u2Tick = 1;
      start.pfCallback = toneStop;
      start.vPara = data;
      DclSGPT_Control( tone.gpt, SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
      break;
   }
}

static void tonePlayOn( void *data )
{
   uint16 dura;

   if( tone.bQTMF )
      tone.curr_qtmf = (L1SP_QTMF *)tone.tonelist + (uint32)data;
   else
      tone.curr_qtmf = (L1SP_QTMF *)(tone.tonelist + (uint32)data);

   // apply hardware mute during tone playback
   *AFE_AMCU_CON1 |= 0x0C;
   DSP_QTMF_FREQ( tone.curr_qtmf->freq1, tone.curr_qtmf->freq2,
                  tone.curr_qtmf->freq3, tone.curr_qtmf->freq4 );
   DSP_TONE_CTRL1 = 1;
   DSP_TONE_CTRL2 = 1;

   if( ( dura = tone.curr_qtmf->on_duration / 10 ) > 0 ) {
      SGPT_CTRL_START_T start;
      start.u2Tick = dura;
      start.pfCallback = tonePlayOff;
      start.vPara = 0;
      DclSGPT_Control( tone.gpt, SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
   }
}

static void toneMute( void *data )
{
   int32 dura = (int32)data;
   uint16 tone_ctrl;
   SGPT_CTRL_START_T start;

   tone_ctrl = (DSP_TONE_CTRL2 << 8) + DSP_TONE_CTRL1;
   switch( tone_ctrl ) {
   case 0:
      start.u2Tick = dura+1;
      start.pfCallback = tonePlayOn;
      start.vPara = (void *)(kal_uint32)tone.curr_qtmf->next_tone;
      DclSGPT_Control( tone.gpt, SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
      break;
   case 0x202:
      DSP_TONE_CTRL1 = 4;
      DSP_TONE_CTRL2 = 4;
   default:
      start.u2Tick = 1;
      start.pfCallback = toneMute;
      start.vPara = (void*)((dura>0)?dura-1:0);
      DclSGPT_Control( tone.gpt, SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
      break;
   }
}

static void tonePlayOff( void *data )
{
   uint16 dura = tone.curr_qtmf->off_duration / 10;
   if( dura == 0 )
      toneStop( 0 );
   else
      toneMute( (void*)(kal_uint32)dura );
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
   tone.gpt = DclSGPT_Open( DCL_GPT_CB ,0 );
   DSP_TONE_CTRL1 = 0;

   tone.amp = TONE_INIT_AMP;
   tone.bQTMF = false;

   DP_KT_ATT      = 0;
#ifdef ANALOG_AFE_PATH_EXIST	
   AFE_TurnOnFIR( L1SP_TONE );
#endif // ANALOG_AFE_PATH_EXIST
}

/* ------------------------------------------------------------------------------ */
/*  Tone Interface                                                                */
/* ------------------------------------------------------------------------------ */
void TONE_SetOutputDevice( uint8 device )
{
#ifdef ANALOG_AFE_PATH_EXIST
   AFE_SetOutputDevice( L1SP_TONE, device );
#endif
}

void TONE_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
#ifdef ANALOG_AFE_PATH_EXIST
   AFE_SetOutputVolume( L1SP_TONE, volume1, digital_gain_index );
#endif
}

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
	// FIXME:
	return; 
	
   if(AM_IsSpeechOn()){/* Prevent Speech from being muted, becuase Tone/KT with volume = 0 results in DigitalGain = 0 */
      uint8 volume;
#ifdef ANALOG_AFE_PATH_EXIST
      int8 digital_gain_index;
      AFE_GetOutputVolume(L1SP_TONE, &volume, &digital_gain_index);
#else 		
		AFE_DigitalOnly_GetOutputVolume(L1SP_TONE, &volume);
#endif // ANALOG_AFE_PATH_EXIST		
      if(0 == volume)
         return;
   }

   if( L1Audio_CheckFlag( tone.aud_id ) )
      return;
   if( L1Audio_CheckFlag( keytone.aud_id ) ) {
      KT_Stop();
      while( L1Audio_CheckFlag( keytone.aud_id ) )
         kal_sleep_task( 1 );
   }

   if( AM_IsSpeechOn() )
      DP_KT_ATT = 0x4000;

#if defined(__BT_SUPPORT__)
   if( L1SP_IsBluetoothOn() ){
      if( L1SP_GetSpeechMode() == SPH_MODE_LINEIN_VIA_BT_CORDLESS )
         *DP_AUDIO_PAR = (*DP_AUDIO_PAR & 0xFF) | 0x2000; // set to earphone mode
      DSP_TONE_AMP1 = (TONE_INIT_AMP >> 2);               /* degrade bluetooth tone volume by 12dB */
      DSP_TONE_AMP2 = (TONE_INIT_AMP >> 2);               /* degrade bluetooth tone volume by 12dB */
   }else
#endif
   {
      DSP_TONE_AMP1 = tone.amp;
      DSP_TONE_AMP2 = tone.amp;
   }
   L1Audio_SetFlag( tone.aud_id );
   tone.tonelist = tonelist;
   AM_ToneOn();
   tonePlayOn( 0 );
   tone.isRun = true;
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
   DclSGPT_Control(tone.gpt ,SGPT_CMD_STOP, 0);
   toneStop( 0 );
}

void TONE_StopAndWait( void )
{
   int I;

   AM_FlushQFunction();
   TONE_Stop();

   for( I = 0; ; I++ ) {
      if ( !AM_IsToneOn() )
         break;

      ASSERT_REBOOT(I < 20);
      kal_sleep_task(2);
   }
   kal_sleep_task(2);//wait AFE also updated
}

void TONE_SetAmplitude( int16 amp )
{
   tone.amp = (uint16)amp;
}

void TONE_SetFIR( bool enable )
{
   if( enable ) {
#ifdef ANALOG_AFE_PATH_EXIST		
      AFE_TurnOnFIR( L1SP_TONE );
#endif // ANALOG_AFE_PATH_EXIST
   }else{
#ifdef ANALOG_AFE_PATH_EXIST   
      AFE_TurnOffFIR( L1SP_TONE );
#endif
	}
}

void TONE_SetHandler( void (*handler)(void) )
{
   tone.handler = handler;
}

/* ------------------------------------------------------------------------------ */
/*  Keytone Interface                                                             */
/* ------------------------------------------------------------------------------ */
void ktStop_FlushQueue( void *data )
{
   if(AM_IsKeyToneOn())
   {
      SGPT_CTRL_START_T start;
      start.u2Tick = 1;
      start.pfCallback = ktStop_FlushQueue;
      start.vPara = data;
      DclSGPT_Control( keytone.gpt, SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
   } else {
      L1Audio_ClearFlag( keytone.aud_id );
   }
}

static void ktStop( void *data )
{
   SGPT_CTRL_START_T start;
   if( !L1Audio_CheckFlag( keytone.aud_id ) )
      return;
   switch( DSP_TONE_CTRL2 ) {
   case 0:
      if (keytone.isRun) {
         keytone.isRun = false;
         AM_KeyToneOff();
      }
      start.u2Tick = 1;
      start.pfCallback = ktStop_FlushQueue;
      start.vPara = data;
      DclSGPT_Control( keytone.gpt, SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
      //L1Audio_ClearFlag( keytone.aud_id );
      break;
   case 2:
      DSP_TONE_CTRL2 = 4;
   default:
      start.u2Tick = 1;
      start.pfCallback = ktStop;
      start.vPara = data;
      DclSGPT_Control( keytone.gpt, SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
      break;
   }
}

void ktInit( uint16 aud_id )
{
   keytone.aud_id = aud_id;
   keytone.lock   = 0;
   keytone.volume1 = 160;
   keytone.digital_gain_index = 0;
   keytone.gpt = DclSGPT_Open(DCL_GPT_CB,0);
   DSP_TONE_CTRL2 = 0;
   DSP_TONE_AMP2  = KT_INIT_AMP;
#ifdef ANALOG_AFE_PATH_EXIST
   AFE_TurnOnFIR( L1SP_KEYTONE );
#endif
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
      KT_Stop();
      while( L1Audio_CheckFlag( keytone.aud_id ) )
         kal_sleep_task( 1 );
   }
#ifdef ANALOG_AFE_PATH_EXIST   
   AFE_SetOutputDevice( L1SP_KEYTONE, device );
#endif   
}

void KT_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
   keytone.volume1 = volume1;
   keytone.digital_gain_index = digital_gain_index;
}

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

void KT_Play( uint16 freq1, uint16 freq2, uint16 duration )
{
	// FIXME:
	return;
	// endif
	
   if( keytone.lock > 0 || keytone.volume1 == 0 )
      return;
   // if( mediaKeytoneForbidden() || AM_IsDAIMode() )
   if( AM_IsDAIMode() )
      return;
   if( L1Audio_CheckFlag( keytone.aud_id ) )
      return;

#if !defined(__DISABLE_SKIP_KEYTONE_DURING_TONE_PLAY__)
   if( L1Audio_CheckFlag( tone.aud_id ) )
      return;
#endif

   if( L1Audio_CheckFlag( tone.aud_id ) ) {
      TONE_Stop();
      while( L1Audio_CheckFlag( tone.aud_id ) )
         kal_sleep_task( 1 );
   }
   
   /* When Tone/KT with volume = 0 lets AFE set DigitalGain = 0, it causes the side effect. At the same time, Speech is muted, becuase digital gain is 0  */
   if(AM_IsSpeechOn()){
      uint8 volume;
#ifdef ANALOG_AFE_PATH_EXIST				
      int8 digital_gain_index;
      AFE_GetOutputVolume(L1SP_TONE, &volume, &digital_gain_index);
#else 		
		AFE_DigitalOnly_GetOutputVolume(L1SP_TONE, &volume);
#endif // ANALOG_AFE_PATH_EXIST
      if(0 == volume)
         return;
   }

   L1Audio_SetFlag( keytone.aud_id );

   /* keytone in speech mode, need special care */
#if defined(__BT_SUPPORT__)
   if( L1SP_IsBluetoothOn() ) {
      DSP_TONE_AMP2 = KT_INIT_AMP >> 2; /* degrade bluetooth keytone volume by 12dB */
#ifdef ANALOG_AFE_PATH_EXIST		
      AFE_SetOutputVolume( L1SP_KEYTONE, keytone.volume1, keytone.digital_gain_index );
#else
		// FIXME: take care here! still no implement
		ASSERT(0);
#endif
   }
   else
#endif
   if( AM_IsSpeechOn() && AFE_GetOutputDevice(L1SP_KEYTONE)==AFE_GetOutputDevice(L1SP_SPEECH) ) {
#ifdef ANALOG_AFE_PATH_EXIST		
      uint8 speech_vol1;
      int8 speech_digital_gain;
      int32 vol, dgain;
      AFE_GetOutputVolume( L1SP_SPEECH, &speech_vol1, &speech_digital_gain );
      AFE_SetOutputVolume( L1SP_KEYTONE, speech_vol1, speech_digital_gain );
      vol = (speech_vol1>>4) - (keytone.volume1>>4);
      dgain= KT_INIT_AMP;
      if( AFE_GetOutputDevice(L1SP_KEYTONE) & L1SP_BUFFER_ST ) {
         while( vol > 0 ) {
            dgain = (dgain * 725) >> 10;    vol--;   /* 3dB down */
         }
         while( vol < 0 ) {
            dgain = (dgain * 1446) >> 10;   vol++;   /* 3dB up */
         }
      }
      else {
         while( vol > 0 ) {
            dgain = (dgain * 813) >> 10;    vol--;   /* 2dB down */
         }
         while( vol < 0 ) {
            dgain = (dgain * 1289) >> 10;   vol++;   /* 2dB up */
         }
      }
      if( dgain >= 0x8000 )
         dgain = 0x7FFF;
      DSP_TONE_AMP2 = dgain;
#else
		DSP_TONE_AMP2 = KT_INIT_AMP;
#endif // ANALOG_AFE_PATH_EXIST
   }
   else {
      DSP_TONE_AMP2 = KT_INIT_AMP;
#ifdef ANALOG_AFE_PATH_EXIST		
      AFE_SetOutputVolume( L1SP_KEYTONE, keytone.volume1, keytone.digital_gain_index );
#else
		// FIXME: take care here! still no implement
		ASSERT(0);
#endif		
   }

   DSP_KT_FREQ( freq1, freq2 );
   DSP_TONE_CTRL2 = 1;
   keytone.isRun = true;

   AM_KeyToneOn();
   if( (duration = duration / 10) > 0 ) {
      SGPT_CTRL_START_T start;
      start.u2Tick = duration;
      start.pfCallback = ktStop;
      start.vPara = 0;
      DclSGPT_Control( keytone.gpt, SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
   }
}

/*****************************************************************************
* FUNCTION
*  KT_Stop
* DESCRIPTION
*   This function is used to stop key tone playing.
*****************************************************************************/
void KT_Stop( void )
{
   DclSGPT_Control( keytone.gpt, SGPT_CMD_STOP, 0);
   ktStop( 0 );
}

void KT_StopAndWait(void)
{
   int I;

   AM_FlushQFunction();
   KT_Stop();

   for( I = 0; ; I++ ) {
      if ( !AM_IsKeyToneOn() )
         break;

      ASSERT_REBOOT(I < 20);
      kal_sleep_task(2);
   }
   kal_sleep_task(2);//wait AFE also updated
}

void KT_SetAmplitude( int16 amp )
{
   DSP_TONE_AMP2   = amp;
}

void KT_SetFIR( bool enable )
{
   if( enable ){
#ifdef ANALOG_AFE_PATH_EXIST		
      AFE_TurnOnFIR( L1SP_KEYTONE );
#endif 
   } else {
#ifdef ANALOG_AFE_PATH_EXIST
      AFE_TurnOffFIR( L1SP_KEYTONE);
#endif
   }
}

/* To indicate if the keytone can be play */
kal_bool KT_IsPlayable(void)
{
   if( keytone.lock > 0 || keytone.volume1 == 0 )
      return KAL_FALSE;
   // if( mediaKeytoneForbidden() || AM_IsDAIMode() )
   if( AM_IsDAIMode() )
      return KAL_FALSE;
   if( L1Audio_CheckFlag( keytone.aud_id ) || L1Audio_CheckFlag( tone.aud_id ) )
      return KAL_FALSE;
   return KAL_TRUE;
}
