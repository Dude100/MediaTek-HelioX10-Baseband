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
 *   snd_effect.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Sound effect interface and driver, providing in-call background sound and sound event playback
 *     support FSAL stream input with Microsoft WAV format
 *
 * Author:
 * -------
 * -------
 * -------
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
*                E X T E R N A L   R E F E R E N C E S
******************************************************************************
*/

#ifdef BGSND_ENABLE

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "reg_base.h"
#include "fsal.h"
#include "string.h"

#include "l1audio.h"
#include "audio_enum.h"
#include "l1audio_def.h"
#include "fc_def.h"  
#include "afe.h"
#include "am.h"
//#include "wav.h"
#include "media.h"

#include "kal_trace.h"
#include "l1sp_trc.h"

#define L1SND_TRC_ON


/*****************************************************************************
*                          C O N S T A N T S
******************************************************************************
*/
#define DP_BUFFER_DEFAULT_LEN       4096   /* The frame size of DSP. */
#define DSP_BUFFER_LEN              160
#define SND_RB_DEFAULT_THRESHOLD    512
#define MASTER_GAIN_FACTOR          12
#define SND_EFFECT_MAGIC_NO           0xAA57

/* DSP Sound Effect State */
#define DP_SND_STATE_IDLE           0     /* MCU: 0 -> 1 */
#define DP_SND_STATE_READY          1     /* DSP: 1 -> 2 */
#define DP_SND_STATE_PLAYING        2     /* MCU: 2 -> 3 */
#define DP_SND_STATE_STOPPED        3     /* DSP: 3 -> 0 */

#define SND_PCM_BUFFER_SIZE         2048

#define SND_GAIN_CONFIG   1 /* 0: right shamt, 1: multiplier */


// Background Control State
#define BGSNG_STATE_NONE  0
#define BGSNG_STATE_PLAY  1
#define BGSNG_STATE_PAUSE 2
#define BGSNG_STATE_STOPPING 3


#define BGS_BUF_SIZE  (2*DP_BUFFER_DEFAULT_LEN*2 + SND_PCM_BUFFER_SIZE + 1024*10)
kal_uint8 BGS_BUF[BGS_BUF_SIZE];

/*****************************************************************************
*                         D A T A   T Y P E S
******************************************************************************
*/

#ifdef SND_CHECK_DATA
int16 snd_check_data[0x80000];
int16 *snd_check_w2;
#endif

//#define SND_UNIT_TEST
typedef struct {
   int16 formatTag;
   uint16 numChannels;
   uint32 sampleRate;
   uint32 avgBytesPerSec;
   uint16 blockAlign;
   uint16 bitsPerSample;
   uint32 extHeaderOffset;
   uint16 extHeaderSize;
   uint32 dataChunkOffset;
   uint32 dataChunkSize;
} sndHeader;

typedef struct sndcontrol SndControl;
struct sndcontrol{
   uint16 aud_id;
   uint16 aud_decode_id;
   void (*SND_PutData)(SndControl *snd_ctrl);
   Media_Event end_status;
   int16 level;
   kal_bool bULSPHFlag; /* if KAL_TRUE, mix uplink speech */
   kal_bool bDLSPHFlag; /* if KAL_TRUE, mix downlink speech */
   kal_int16 ULSNDGain; /* 0 ~ 100, digital gain for mixed uplink sound */
   kal_int16 DLSNDGain; /* 0 ~ 100, digital gain for mixed downlink sound */

   sndHeader info;

   /* Ring buffer control variables */
   uint16 rb_threshold;
   uint16 rb_size;          /* Size of the ring buffer(word) */
   uint16 write;            /* R/W by MMI, R by WAV driver   */
   uint16 read;             /* R by MMI, R/W by WAV driver   */
   int16  *rb_base;         /* Pointer to the ring buffer    */
   int16  *spk_buffer;      // temp code: should be erased
   uint32 total_write_bytes;
   uint32 total_consume_bytes;
   bool waiting;
   bool eof;              /* Flag indicating End-Of-File   */
   void *parent;

   AUD_RB_INFO        rbInfo;
   kal_uint16         fc_aud_id;
   kal_uint8          fc_state;
   bool               isChanged;
   kal_uint8          ctrl_state;

};

typedef struct {
   kal_int8       repeat_count;
   kal_uint8      volume_level;
   kal_uint32     data;
   void           (*handler)( Media_Handle *handle, Media_Event event );
   void           *param;
} mhandle;

typedef struct {
   mhandle mh;
   SndControl snd_ctrl;
} sndMediaHandleInternal;


/*****************************************************************************
*              F U N C T I O N   D E C L A R A T I O N S
******************************************************************************
*/
static int32 sndGetDataCount( SndControl *snd_ctrl );

/*****************************************************************************
*                             M A C R O S
******************************************************************************
*/


/*****************************************************************************
*                          F U N C T I O N S
******************************************************************************
*/

__inline void sndShiftReadPointer(SndControl *snd_ctrl, uint32 len )
{
   snd_ctrl->read += len;
   if (snd_ctrl->read == snd_ctrl->rb_size)
      snd_ctrl->read = 0;

   snd_ctrl->total_consume_bytes += (len<<1);
}

static int32 rbGetFreeSpaceInternal( AUD_RB_INFO *rb )
{
   int32 count;
   count = (int32)rb->read - (int32)rb->write - 1;
   if ( count < 0 )
      count += (int32)rb->rb_size;
   return count;
}

static void rbGetWriteBufferInternal( AUD_RB_INFO *rb, kal_uint8 **buffer, kal_uint32 *buf_len )
{
   int32 count;

   if( rb->read > rb->write )
      count = rb->read - rb->write - 1;
   else if( rb->read == 0 )
      count = rb->rb_size - rb->write - 1;
   else
      count = rb->rb_size - rb->write;

   ASSERT( count>=0 );
   *buffer = (uint8 *)&rb->rb_base[rb->write];
   *buf_len = count;
}

static void rbWriteDataDoneInternal( AUD_RB_INFO *rb, kal_uint32 len )
{
   rb->write += len;

   ASSERT(rb->write <= rb->rb_size);
   if( rb->write == rb->rb_size )
      rb->write = 0;
}

static void sndAUlawPCM_DecodeSample( SndControl *snd_ctrl, uint16 (*law2linear)( uint8 aval ) )
{
   int32 numSamples, I;
   int16 sample;
   bool sampleType = (snd_ctrl->info.bitsPerSample==8);

   kal_uint8 *pWriteBuf8;
   kal_int16 *pWriteBuf16;
   kal_uint32 uWriteSize8;

   numSamples = sndGetDataCount(snd_ctrl)*(sampleType?2:1);
   rbGetWriteBufferInternal( &snd_ctrl->rbInfo, &pWriteBuf8, &uWriteSize8);
   pWriteBuf16 = (kal_int16 *)pWriteBuf8;
   
   if (numSamples > (uWriteSize8>>1) )
      numSamples = (uWriteSize8>>1);

   if (sampleType) {
      for (I=numSamples; I>0; I-=2) {
         uint16 data = snd_ctrl->rb_base[snd_ctrl->read];
         sample = (law2linear?law2linear(data&0x00FF):((data<<8)-0x8000));
         *pWriteBuf16++ = sample;
      
         sample = (law2linear?law2linear(data>>8):((data&0xFF00)-0x8000)); 
         *pWriteBuf16++ = sample;
      
         sndShiftReadPointer(snd_ctrl , 1);
      
         if ( snd_ctrl->total_consume_bytes >= snd_ctrl->info.dataChunkSize ){
            snd_ctrl->total_consume_bytes = 0;
         }
      }
   } else {
      for (I=numSamples; I>0; I--) {
         uint16 data = snd_ctrl->rb_base[snd_ctrl->read];
         sample = data;
         *pWriteBuf16++ = sample;
      
         sndShiftReadPointer(snd_ctrl, 1);
      
         if ( snd_ctrl->total_consume_bytes >= snd_ctrl->info.dataChunkSize ){
            snd_ctrl->total_consume_bytes = 0;
         }
      }
   }
   
   rbWriteDataDoneInternal(&snd_ctrl->rbInfo, numSamples<<1);
}

static void sndPutData_PCM( SndControl *snd_ctrl ) /* 16 bit linear pcm */
{
   sndAUlawPCM_DecodeSample( snd_ctrl, NULL );
}

/* ------------------------------------------------------------------------------ */

static int32 sndGetDataCount( SndControl *snd_ctrl )
{
   int32 count = (int32)snd_ctrl->write - (int32)snd_ctrl->read;
   if ( count < 0 )
      count += snd_ctrl->rb_size;
   return count;
}

static void sndCallbackTask(void *data)
{
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)data;
   handle->mh.handler( (Media_Handle *)handle, (Media_Event)handle->mh.data );
}

static void sndSetEvent( SndControl *snd_ctrl, Media_Event event )
{
   mhandle *handle = (mhandle *)snd_ctrl->parent;
   handle->data = (kal_uint32)event;
   L1Audio_SetEvent( snd_ctrl->aud_id, (void *)handle );
}

__inline int16 sndSetSampleAmplitude(int16 sample, int16 arg)
{
   return((sample*arg)>>15);
}

/* ------------------------------------------------------------------------------ */

static void sndUpdateSettings( SndControl *snd_ctrl )
{
   kal_uint16 dgain;

   if (snd_ctrl->isChanged) {
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_BKG_SOUND_SET_DLGAIN, 0, snd_ctrl->DLSNDGain);
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_BKG_SOUND_SET_ULGAIN, 0, snd_ctrl->ULSNDGain);
//      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_BKG_SOUND_SET_DLMIX, 0, snd_ctrl->bDLSPHFlag);
//      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_BKG_SOUND_SET_ULMIX, 0, snd_ctrl->bULSPHFlag);
      
      // DL speech gain
      if (snd_ctrl->bDLSPHFlag)
         dgain = 32767;
      else
         dgain = 0;
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_DL_GAIN, 0, dgain);
      
      // UL speech gain
      if (snd_ctrl->bULSPHFlag)
         dgain = 32767;
      else
         dgain = 0;
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_UL_GAIN, 0, dgain);
      
      snd_ctrl->isChanged = false;
   }
}

static void sndDecodeTask( void *data )
{

}



void sndProcess( Media_Handle *hdl )
{
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)hdl;
   Media_Event event = (Media_Event)handle->mh.data;
   SndControl *snd_ctrl = &handle->snd_ctrl;

   if (event == MEDIA_DATA_REQUEST){
      if( snd_ctrl->end_status==MEDIA_NONE ) {
         sndDecodeTask( handle );
      }
   }
   return;
}

kal_bool SND_IsRunning(Media_Handle *hdl)
{
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)hdl;
   SndControl *snd_ctrl = &handle->snd_ctrl;
   if( snd_ctrl->ctrl_state == BGSNG_STATE_STOPPING || snd_ctrl->ctrl_state == BGSNG_STATE_PLAY )
      return KAL_TRUE;
   else
      return KAL_FALSE;
}

static void sndMsgHandler(kal_uint16 msgOp, kal_uint32 msgData, void *userData)
{
   Media_Handle *hdl = (Media_Handle *) userData;
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)hdl;
   SndControl *snd_ctrl = &handle->snd_ctrl;
   kal_uint8 *prevRead, *curRead; 
   FC_Buf *fc_BufHdr;

   switch (msgOp) {
      case MSG_SAC2L1AUDIO_AUDIO_PLAYBACK_ON_ACK:
         snd_ctrl->fc_state = FC_STATE_PLAY;
         break;
      case MSG_SAC2L1AUDIO_AUDIO_PLAYBACK_OFF_ACK:
         snd_ctrl->fc_state = FC_STATE_IDLE;
#if defined(__SMART_PHONE_MODEM__)
         spc_BGSOffAck();
#endif
         break;
      case MSG_SAC2L1AUDIO_AUDIO_WRITE_DATA_ACK:
         // Update flag
         break;
      case MSG_SAC2L1AUDIO_AUDIO_DATA_REQUEST:
         fc_BufHdr = (FC_Buf *)snd_ctrl->rbInfo.param;
         prevRead = fc_BufHdr->pRead;

         // Update read pointer
         L1Audio_FC_UpdateDspReadPointer(&snd_ctrl->rbInfo, msgData);
         
         // Write data to share buffer with FC.
         L1Audio_FC_WriteBufferToDSP(&snd_ctrl->rbInfo);
         
         // Ack to FC
         L1Audio_FC_AudioDataRequestAck(snd_ctrl->fc_aud_id, &snd_ctrl->rbInfo);
         
         curRead = fc_BufHdr->pRead;
         
         // Notify MED to refill media buffer
#if defined(__SMART_PHONE_MODEM__)
         if (!snd_ctrl->eof) {
            spc_RequestBgsData();
         } else if (sndGetDataCount(snd_ctrl) == 0) {            
            snd_ctrl->end_status = MEDIA_END;
            
            if (prevRead == curRead)
               sndSetEvent( snd_ctrl, MEDIA_END );
         }
#else
         L1Audio_SetEvent( snd_ctrl->aud_decode_id, (void *)handle );
         if ((snd_ctrl->eof) && (sndGetDataCount(snd_ctrl) == 0)) {            
            snd_ctrl->end_status = MEDIA_END;
            
            if (prevRead == curRead)
               sndSetEvent( snd_ctrl, MEDIA_END );
         }
#endif

         break;
      default:
         ASSERT(0);
   }
}


/* ------------------------------------------------------------------------------ */
#define RIFF_ID  0x46464952
#define MTK_ID  0x2044544D
#define WAVE_ID  0x45564157
#define FMT_ID  0x20746D66
#define DATA_ID  0x61746164


/*
 * Description
 * ---------
 *   The function sets the output device.
 *
 * Syntax
 * ---------
 *   void SND_SetOutputDevice( kal_uint8 device );
 *
 * where
 *   device   The output device (L1SP_SPEAKER1, L1SP_SPEAKER2, L1SP_LOUD_SPEAKER)
 *
 * Return Value
 * ---------
 *   None
 */
void SND_SetOutputDevice( kal_uint8 device )
{
   if ( !AM_IsSpeechOn() && !AM_IsVoIPOn())
      AFE_SetOutputDevice( L1SP_SND_EFFECT, device );
}

/*
 * Description
 * ---------
 *   The function sets the playback mode. The function can be invoked after the media
 *   handle is opened and during the media handle is playing.
 *
 * Syntax
 * ---------
 *   void SND_ConfigULMixer( Media_Handle *hdl, kal_bool bULSPHFlag, kal_int8 ULSNDGain );
 *   void SND_ConfigDLMixer( Media_Handle *hdl, kal_bool bDLSPHFlag, kal_int8 DLSNDGain );
 *
 * where
 *   hdl   The media handle
 *   bULSPHFlag   Mixer switch for uplink speech
 *   ULSNDGain   Sound effect gain for uplink mixer
 *   bDLSPHFlag   Mixer switch for downlink speech
 *   DLSNDGain   Sound effect gain for downlink mixer
 *
 * Return Value
 * ---------
 *   None
 */
void SND_ConfigULMixer( Media_Handle *hdl, kal_bool bULSPHFlag, kal_int8 ULSNDGain )
{
   kal_int16 gain = 0;
   ASSERT(ULSNDGain>=0 && ULSNDGain<=7);
   if ( ULSNDGain!=0 )
      gain = (kal_int16)(32767>>(7 - ULSNDGain));
      
   ((sndMediaHandleInternal *)hdl)->snd_ctrl.bULSPHFlag = bULSPHFlag;
   ((sndMediaHandleInternal *)hdl)->snd_ctrl.ULSNDGain = gain;
   ((sndMediaHandleInternal *)hdl)->snd_ctrl.level = gain;

#ifdef L1SND_TRC_ON
   kal_trace( TRACE_INFO, L1SND_CONFIG_ULMIXER, bULSPHFlag, ULSNDGain );
#endif

   ((sndMediaHandleInternal *)hdl)->snd_ctrl.isChanged = true;
   if ( AM_IsBgsndOn() ) {
      sndUpdateSettings( &((sndMediaHandleInternal *)hdl)->snd_ctrl );
   }
}
void SND_ConfigDLMixer( Media_Handle *hdl, kal_bool bDLSPHFlag, kal_int8 DLSNDGain )
{
   kal_int16 gain = 0;
   ASSERT(DLSNDGain>=0 && DLSNDGain<=7);
   if ( DLSNDGain!=0 )
      gain = (kal_int16)(32767>>(7 - DLSNDGain));
   
   ((sndMediaHandleInternal *)hdl)->snd_ctrl.bDLSPHFlag = bDLSPHFlag;
   ((sndMediaHandleInternal *)hdl)->snd_ctrl.DLSNDGain = gain;
   ((sndMediaHandleInternal *)hdl)->snd_ctrl.level = gain;

#ifdef L1SND_TRC_ON
   kal_trace( TRACE_INFO, L1SND_CONFIG_DLMIXER, bDLSPHFlag, DLSNDGain );
#endif

   ((sndMediaHandleInternal *)hdl)->snd_ctrl.isChanged = true;
   if ( AM_IsBgsndOn() ) {
      sndUpdateSettings( &((sndMediaHandleInternal *)hdl)->snd_ctrl );
   }
}

void SND_SetWaitFlag(Media_Handle *hdl, kal_bool bWait)
{
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)hdl;
   handle->snd_ctrl.waiting = bWait;
}

kal_bool SND_GetWaitFlag(Media_Handle *hdl)
{
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)hdl;
   return handle->snd_ctrl.waiting;
}
/*
 * Description
 * ---------
 *   The function opens a handle for background sound playback. It should be invoked
 *   before any other operation.
 *
 * Syntax
 * ---------
 *   Media_Handle *SND_Open(void(*handler)(Media_Handle *, Media_Event ),
 *   Snd_Param **param);
 *
 * where
 *   handler   A callback function used for handling MEDIA_END event.
 *   param     Specific parameter for the background sound playback.
 *
 * Return Value
 * ---------
 *   Media_Handle   The media handle
 */

Media_Handle *SND_Open(void(*handler)(Media_Handle *, Media_Event ), Snd_Param **param)
{
   sndMediaHandleInternal *handle;
   Snd_Param *pparam;
   SndControl *snd_ctrl;
   kal_uint8 *ctrl_buffer;

#ifdef L1SND_TRC_ON
   kal_trace( TRACE_FUNC, L1SND_ENTER_SND_OPEN );
#endif

   ASSERT( handler != 0 );

   ctrl_buffer = (uint8 *)BGS_BUF;

   kal_mem_set (BGS_BUF, 0, BGS_BUF_SIZE*sizeof(kal_uint8));
   
   handle = (sndMediaHandleInternal *)ctrl_buffer;
   ctrl_buffer += sizeof(sndMediaHandleInternal);

   pparam = (Snd_Param *)ctrl_buffer;
   ctrl_buffer += sizeof(Snd_Param);

   pparam->pstFSAL = NULL;            // Should be initiated by caller
   pparam->repeats = 1;               // default
   pparam->format = (Media_Format)-1; // Should be initiated by caller

   snd_ctrl = &handle->snd_ctrl;
   snd_ctrl->bULSPHFlag = KAL_TRUE;
   snd_ctrl->bDLSPHFlag = KAL_TRUE;
   snd_ctrl->ULSNDGain = 32767; // default: full scale
   snd_ctrl->DLSNDGain = 32767; // default: full scale

   snd_ctrl->aud_id = L1Audio_GetAudioID();
   snd_ctrl->aud_decode_id = L1Audio_GetAudioID();
   snd_ctrl->rb_threshold = SND_RB_DEFAULT_THRESHOLD;
   snd_ctrl->rb_size = 2*DP_BUFFER_DEFAULT_LEN;
   snd_ctrl->rb_base = (int16 *)ctrl_buffer;

   ctrl_buffer += 2*DP_BUFFER_DEFAULT_LEN*sizeof(int16);
   snd_ctrl->spk_buffer = (int16 *)ctrl_buffer;  // temp code: should be erased
   snd_ctrl->rbInfo.rb_base = ctrl_buffer;
   snd_ctrl->rbInfo.rb_size = SND_PCM_BUFFER_SIZE;
   
   snd_ctrl->level = 32767;
   snd_ctrl->parent = (void *)handle;
   snd_ctrl->isChanged = true;
   snd_ctrl->fc_state = FC_STATE_IDLE;
   
   handle->mh.handler = handler;
   handle->mh.volume_level = 100;
   handle->mh.param = (void *)pparam;

   L1Audio_SetEventHandler( snd_ctrl->aud_id, sndCallbackTask );
   L1Audio_SetEventHandler( snd_ctrl->aud_decode_id, sndDecodeTask );
   AFE_SetOutputVolume( L1SP_SND_EFFECT, 200, 0 );

   *param = pparam;
   return((Media_Handle *)handle);
}

/*
 * Description
 * ---------
 *   To pause the background for internal use.
 *
 * Syntax
 * ---------
 *   Media_Status SND_Pause_Internal( void *hdl )
 *
 * where
 *   hdl   The media handle
 *
 * Return Value
 * ---------
 *   None
 */
static void SND_Pause_Internal( void *hdl )
{
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)hdl;
   SndControl *snd_ctrl;
   
   ASSERT(hdl != NULL);
   
   snd_ctrl = &handle->snd_ctrl;
   
   if (snd_ctrl->ctrl_state != BGSNG_STATE_PLAY)
      return;
   
   // Stop background sound
   L1Audio_FC_AudioPlaybackOff(snd_ctrl->fc_aud_id);

   AM_SND_PlaybackOff( true );
   
   snd_ctrl->ctrl_state = BGSNG_STATE_PAUSE;
}

/*
 * Description
 * ---------
 *   To resume the background for internal use.
 *
 * Syntax
 * ---------
 *   Media_Status SND_Resume_Internal( void *hdl )
 *
 * where
 *   hdl   The media handle
 *
 * Return Value
 * ---------
 *   None
 */
static void SND_Resume_Internal( void *hdl )
{
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)hdl;
   SndControl *snd_ctrl;

   ASSERT(hdl != NULL);
   
   snd_ctrl = &handle->snd_ctrl;
   
   if (snd_ctrl->ctrl_state != BGSNG_STATE_PAUSE)
      return;

   snd_ctrl->isChanged = true;
   sndUpdateSettings(snd_ctrl);

   sndDecodeTask(handle);
   L1Audio_FC_AudioPlaybackOn(snd_ctrl->fc_aud_id, &snd_ctrl->rbInfo);

   AM_SND_PlaybackOn();
   
   snd_ctrl->ctrl_state = BGSNG_STATE_PLAY;
}

/*
 * Description
 * ---------
 *   The function starts the background sound playback of the media handle.
 *
 * Syntax
 * ---------
 *   Media_Status SND_Play( Media_Handle *hdl );
 *
 * where
 *   hdl   The media handle
 *
 * Return Value
 * ---------
 *   Media_Status   MEDIA_SUCCESS => Background sound has been played.
 *                  MEDIA_REENTRY => Reentrance has occurred. Operation aborted.
 *                  MEDIA_NOT_INITIALIZED =>  The media handle is invalid. Operation
 *                                            aborted.
 *                  MEDIA_BAD_FORMAT => Bad sound format. Operation aborted.
 */
Media_Status SND_Play( Media_Handle *hdl )
{
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)hdl;
   SndControl *snd_ctrl = &handle->snd_ctrl;
   Snd_Param *param = (Snd_Param *)handle->mh.param;

#ifdef L1SND_TRC_ON
   kal_trace( TRACE_FUNC, L1SND_ENTER_SND_PLAY );
#endif

   if( L1Audio_CheckFlag( snd_ctrl->aud_id ) )
      return MEDIA_REENTRY;

   if( snd_ctrl->rb_base == (int16*)0 )
      return MEDIA_NOT_INITIALIZED;

   handle->mh.repeat_count = param->repeats;

   snd_ctrl->read = 0;
   snd_ctrl->write = 0;
   snd_ctrl->eof = false;

   snd_ctrl->end_status = MEDIA_NONE;
   snd_ctrl->waiting = false;

   snd_ctrl->info.formatTag =  0x0001;  // MEDIA_FORMAT_PCM_8K
   snd_ctrl->info.sampleRate = 16000;
   snd_ctrl->info.numChannels = 1; // mono
   snd_ctrl->info.bitsPerSample = 16;

   switch( snd_ctrl->info.formatTag ) {
      case 0x0001:
         if (snd_ctrl->info.bitsPerSample != 16 && snd_ctrl->info.bitsPerSample != 8)
            return MEDIA_BAD_FORMAT;
         param->format = MEDIA_FORMAT_PCM_8K;
         snd_ctrl->SND_PutData = sndPutData_PCM;
         break;
      default:
         return MEDIA_BAD_FORMAT;
   }

   snd_ctrl->total_consume_bytes = 0;
   snd_ctrl->total_write_bytes = 0;

   // Allocate memory for PCM buffer
   snd_ctrl->rbInfo.read = snd_ctrl->rbInfo.write = 0;
   

   sndDecodeTask(handle);
   
   L1Audio_SetFlag( snd_ctrl->aud_id );
   L1Audio_SetFlag( snd_ctrl->aud_decode_id );

#ifdef L1SND_TRC_ON
   kal_trace( TRACE_INFO, L1SND_DATACHUNK_SIZE, snd_ctrl->info.dataChunkSize );
#endif

   {
      snd_ctrl->rbInfo.fc_format = FC_MEDIA_FORMAT_PCM;
      snd_ctrl->rbInfo.fc_operation = MEDIA_OPERATE_PLAYBACK;

      {
         kal_uint16 msg16;
      
         msg16 = (snd_ctrl->rbInfo.fc_format << 8) | snd_ctrl->rbInfo.fc_operation;
         snd_ctrl->fc_aud_id = L1Audio_FC_HookHandler( (void *)hdl, sndMsgHandler, 0, msg16);
      }

#if __DRIVER_PRESERVE_DSP_SHARE_BUFFER__
      snd_ctrl->rbInfo.param = (void *)L1Audio_FC_GetAudioBufferHeader();
#endif
      
      // Fill bitstream information to FC
      {
         FC_Buf *fcBufHdr = (FC_Buf *)snd_ctrl->rbInfo.param;
         
         fcBufHdr->uTime = 0;
         //fcBufHdr->uSamplingFreq = snd_ctrl->info.sampleRate;
         fcBufHdr->uSamplingFreq = snd_ctrl->info.sampleRate;
         fcBufHdr->uChannelNum = snd_ctrl->info.numChannels;
#if defined(EXT_DAC_SUPPORT) 
         fcBufHdr->uOutputDevice = AFE_GetOutputPath(L1SP_SND_EFFECT);
#else
         fcBufHdr->uOutputDevice = eAUD_OUTDEV_DAC;
#endif
      }
      
      sndUpdateSettings(snd_ctrl);

      L1Audio_FC_AudioPlaybackOn(snd_ctrl->fc_aud_id, &snd_ctrl->rbInfo);

      AM_SND_PlaybackOn();

   }
   
   L1SP_Register_SndService(SND_Resume_Internal, SND_Pause_Internal, (void *)hdl);
   TONE_Register_SndService(SND_Resume_Internal, SND_Pause_Internal, (void *)hdl);
   KT_Register_SndService(SND_Resume_Internal, SND_Pause_Internal, (void *)hdl);
   VMDrv_Register_SndService(SND_Resume_Internal, SND_Pause_Internal, (void *)hdl);
   vm_Register_SndService(SND_Resume_Internal, SND_Pause_Internal, (void *)hdl);

#if defined(WAV_CODEC)   
   wav_Register_SndService(SND_Resume_Internal, SND_Pause_Internal, (void *)hdl);
#endif  

   PCMNWAY_Register_SndService(SND_Resume_Internal, SND_Pause_Internal, (void *)hdl);
   
   snd_ctrl->ctrl_state = BGSNG_STATE_PLAY;
   
   return MEDIA_SUCCESS;
}

/*
 * Description
 * ---------
 *   The function stops the background sound playback of the media handle.
 *
 * Syntax
 * ---------
 *   void SND_Stop( Media_Handle *hdl );
 *
 * where
 *   hdl   The media handle
 *
 * Return Value
 * ---------
 *   None
 */
void SND_Stop( Media_Handle *hdl )
{
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)hdl;
   SndControl *snd_ctrl = &handle->snd_ctrl;
   Snd_Param *param = (Snd_Param *)handle->mh.param;

#ifdef L1SND_TRC_ON
   kal_trace( TRACE_FUNC, L1SND_ENTER_SND_STOP );
#endif


   if( !L1Audio_CheckFlag( snd_ctrl->aud_id ) )
      return;

   snd_ctrl->waiting = true;      /* Forbid data request */

   switch( param->format ) {
      case MEDIA_FORMAT_PCM_8K:

         snd_ctrl->end_status = MEDIA_TERMINATED;
         {
            if (snd_ctrl->ctrl_state != BGSNG_STATE_PAUSE) {
#if defined(__SMART_PHONE_MODEM__)
               if( snd_ctrl->ctrl_state != BGSNG_STATE_STOPPING ){
                  snd_ctrl->ctrl_state = BGSNG_STATE_STOPPING;
                  L1Audio_PutMessage(MSG_L1AUDIO2FAS_AUDIO_PLAYBACK_OFF, snd_ctrl->fc_aud_id, 0);
                  kal_prompt_trace(MOD_L1SP,"BGS_Stop Phase 1, waiting");
                  return;
                  //When ACK message comes, continue other stop procedure.
               } else {
                  //When run here, which means MSG_L1AUDIO2FAS_AUDIO_PLAYBACK_OFF ACK already
                  kal_prompt_trace(MOD_L1SP,"BGS_Stop Phase 2, receive playback off ACK");
                  AM_SND_PlaybackOff( true );
               }
#else
               // Stop background sound
               L1Audio_FC_AudioPlaybackOff(snd_ctrl->fc_aud_id);
               AM_SND_PlaybackOff( true );
#endif
            }
            L1Audio_FC_ReleaseAudioBufferHeader( (FC_Buf **) &snd_ctrl->rbInfo.param );
            // Free ID and unhook handler
            L1Audio_FC_UnHookHandler(snd_ctrl->fc_aud_id, 0);
            
            snd_ctrl->ctrl_state = BGSNG_STATE_NONE;

         }

         break;
      default:
         ASSERT(KAL_FALSE);
   }

   L1SP_UnRegister_SndService();
   TONE_UnRegister_SndService();
   KT_UnRegister_SndService();
   VMDrv_UnRegister_SndService();
   vm_UnRegister_SndService();

#if defined(WAV_CODEC)   
   wav_UnRegister_SndService();
#endif   

   PCMNWAY_UnRegister_SndService();

   L1Audio_ClearFlag( snd_ctrl->aud_id );
   L1Audio_ClearFlag( snd_ctrl->aud_decode_id );
}

/*
 * Description
 * ---------
 *   The function closes the media handle.
 *
 * Syntax
 * ---------
 *   Media_Status SND_Close(Media_Handle *hdl);
 *
 * where
 *   hdl   The media handle
 *
 * Return Value
 * ---------
 *   Media_Status   MEDIA_SUCCESS => the operation is complete.
 */
Media_Status SND_Close(Media_Handle *hdl){
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)hdl;
   SndControl *snd_ctrl = &handle->snd_ctrl;

#ifdef L1SND_TRC_ON
   kal_trace( TRACE_FUNC, L1SND_ENTER_SND_CLOSE );
#endif

   L1Audio_FreeAudioID( snd_ctrl->aud_id );
   L1Audio_FreeAudioID( snd_ctrl->aud_decode_id );

   return MEDIA_SUCCESS;
}

#ifdef SND_APPLY_MCU_GAIN
/*
 * Description
 * ---------
 *   The function sets the digital gain of background sound. The function can be
 *   invoked after the media handle is opened and during the media handle is playing.
 *
 * Syntax
 * ---------
 *   Media_Status SND_SetLevel( Media_Handle *hdl, kal_uint8 level );
 *
 * where
 *   hdl     The media handle
 *   level   Volume level (0~100).
 *           Note 1: The default value is 100(maximum volume).
 *           Note 2: A level value larger than 100 will change nothing and cause the
 *                   return value to be MEDIA_FAIL.
 *           Note 3: The volume level 0 will mute the background sound at both downlink
 *                   and uplink.
 *
 * Return Value
 * ---------
 *   Media_Status   MEDIA_SUCCESS => the operation is complete.
 *                  MEDIA_FAIL    => otherwise
 */
Media_Status SND_SetLevel( Media_Handle *hdl, kal_uint8 level )
{
   sndMediaHandleInternal *handle = (sndMediaHandleInternal *)hdl;
   SndControl *snd_ctrl = &handle->snd_ctrl;
   if (level>100)
      return MEDIA_FAIL;

   hdl->volume_level= level;
   snd_ctrl->level = ((int16)level*level*26843)>>13;
   
   return MEDIA_SUCCESS;
}

/*
 * Description
 * ---------
 *   Get the current volume level setting.
 *
 * Syntax
 * ---------
 *   kal_uint8 SND_GetLevel( Media_Handle *hdl );
 *
 * where
 *   hdl   The media handle
 *
 * Return Value
 * ---------
 *   kal_uint8   current volume level setting
 */
kal_uint8 SND_GetLevel( Media_Handle *hdl )
{
   return(hdl->volume_level);
}

#endif


void SND_RBWriteDataDone( AUD_RB_INFO *rb, kal_uint32 len ) // in bytes
{
    rbWriteDataDoneInternal(rb, len );
}

void SND_RBGetWriteBuffer( AUD_RB_INFO *rb, kal_uint8 **buffer, kal_uint32 *buf_len )// in bytes
{
    rbGetWriteBufferInternal(rb, buffer, buf_len);    
}

int32 SND_RBGetFreeSpace( AUD_RB_INFO *rb )// in bytes
{
    return rbGetFreeSpaceInternal(rb);
}

AUD_RB_INFO * SND_RBGetInfo( Media_Handle *hdl)// in bytes
{
    sndMediaHandleInternal *handle = (sndMediaHandleInternal *)hdl;

    return &(handle->snd_ctrl.rbInfo);
}        

#endif /* ...BGSND_ENABLE */
