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
 * pcm_strm.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Streaming PCM Playback and Record
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __L1_STANDALONE__ // avoid link error

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "string.h"  
                       
#include "l1audio.h"
#include "audio_enum.h"
#include "l1audio_def.h"                     
#include "media.h"                                             
#include "am.h"                             
#include "fc_def.h" 
#include "l1sp_trc.h"
#include "exp_SphFasTypDef.h"

#if defined(WAV_CODEC)

#define WAV_STATE_IDLE          0     // 1,3
#define WAV_STATE_RECORDING     1     // 2,0
#define WAV_STATE_RECORD_PAUSE  2     // 0,1
#define WAV_STATE_READY_TO_PLAY 3     // 0,6,4
#define WAV_STATE_PLAYING       4     // 5,0
#define WAV_STATE_PLAY_PAUSE    5     // 0,4
#define WAV_STATE_READY_PAUSE   6     // 3,0

#define FRAME_BUF_SIZE 160

// This flag is for DSP to record stereo PCM in dedicated mode
// #define  DSP_DEBUG_DEDICATED_MODE_RECORD


typedef struct pcmStrm_Internal {
   kal_bool         isPlayback;        // true:Playback, false:Record
   kal_bool         isStereo;
   kal_bool         dedicated_mode;
   kal_bool         is8KVoice;
   kal_int8         bitPerSample;
   kal_uint8        freqType;
   kal_uint16       sampleFreq;
   kal_uint16       dsp_last_sample;
} pcmStrmInternal;

typedef struct pcmStrm_MediaHdlInternal {
   MHdl             mh;
   pcmStrmInternal  pcmStrm;
   Media_Event      end_status;
   kal_uint32       accumulateSize;    // In sample
   kal_uint32       accumulateTime;    // In milli-second
   kal_uint16       frameDuration;

   // EOF handling
   kal_bool         decode_EOF;
   kal_int32        zeroCount;
} pcmStrmMediaHdl;


extern SAC_SphPlayPar_t SAC_SphPlayPar;
static void pcmStrmMsgHandler(kal_uint16 msgOp, kal_uint32 msgData, void *userData)
{
   MHdl *hdl = (MHdl *) userData;
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)userData;
   kal_uint8 *prevRead, *curRead; 
   FC_Buf *fc_BufHdr;
   
   switch (msgOp) {
      case MSG_SAC2L1AUDIO_AUDIO_PLAYBACK_ON_ACK:
         ASSERT( FC_STATE_IDLE == hdl->fc_state);
         hdl->fc_state = FC_STATE_PLAY;
         break;
      case MSG_SAC2L1AUDIO_AUDIO_PLAYBACK_OFF_ACK:
         ASSERT( FC_STATE_PLAY == hdl->fc_state);
         hdl->fc_state = FC_STATE_IDLE;
         break;
      case MSG_SAC2L1AUDIO_AUDIO_WRITE_DATA_ACK:
         // Update flag
         break;
      case MSG_SAC2L1AUDIO_AUDIO_DATA_REQUEST:
         if ( ihdl->end_status == MEDIA_TERMINATED )
            return;
         
         fc_BufHdr = (FC_Buf *)hdl->rbInfo.param;
         prevRead = fc_BufHdr->pRead;
         
#if __DRIVER_PRESERVE_DSP_SHARE_BUFFER__
         // Update read pointer
         L1Audio_FC_UpdateDspReadPointer(&hdl->rbInfo, msgData);
         
         // Write data to share buffer with FC.
         L1Audio_FC_WriteBufferToDSP(&hdl->rbInfo);
         
         // Ack to FC
         L1Audio_FC_AudioDataRequestAck(hdl->fc_aud_id, &hdl->rbInfo);
         
#endif
         
         curRead = fc_BufHdr->pRead;
         
         // Notify MED to refill media buffer
         if (!hdl->eof) {
            #if defined(__SMART_PHONE_MODEM__)
            spc_RequestPcmData();
            #else  
            mhdlDataRequest((MHdl*)ihdl, ihdl->end_status);
            #endif 
         } else if (hdl->GetDataCount((MHdl*)hdl) == 0) {
            
            ihdl->end_status = MEDIA_END;

            if (prevRead == curRead) {
               mhdlException( (MHdl*)ihdl, MEDIA_END );
               ihdl->end_status = MEDIA_TERMINATED;
            }
         }
         
         break;
      case MSG_SAC2L1AUDIO_SPEECH_IDLE_PLAY_START_ACK:
         ASSERT( FC_STATE_IDLE == hdl->fc_state);
         hdl->fc_state = FC_STATE_PLAY;
         L1Audio_FC_SetWait(false);
         break;
      case MSG_SAC2L1AUDIO_SPEECH_IDLE_PLAY_STOP_ACK:
         ASSERT( FC_STATE_PLAY == hdl->fc_state);
         hdl->fc_state = FC_STATE_IDLE;
         L1Audio_FC_SetWait(false);
         break;
      case MSG_SAC2L1AUDIO_SPEECH_IDLE_PLAY_REQUEST_WRITE_DATA:
      {
         FC_Buf *fcBufHdr;
         
         // Update read pointer
         L1Audio_FC_UpdateDspReadPointer(&hdl->rbInfo, msgData);
         // Write data to share buffer with FC.
         L1Audio_FC_WriteBufferToDSP(&hdl->rbInfo);
         // Ack to FC
         fcBufHdr = (FC_Buf *)hdl->rbInfo.param;
         L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_IDLE_PLAY_REQUEST_DATA_ACK, ihdl->mh.fc_aud_id, (kal_uint32)fcBufHdr->pWrite);
         // Notify MED to refill media buffer
         if ( (hdl->eof) && (hdl->GetDataCount((MHdl*)hdl) == 0) ) {
            ihdl->end_status = MEDIA_END;
            mhdlException( (MHdl*)ihdl, MEDIA_END );
         }else
            #if defined(__SMART_PHONE_MODEM__)
            spc_RequestPcmData();
            #else  
            mhdlDataRequest((MHdl*)ihdl, ihdl->end_status);
            #endif
         break;
      }
      default:
         ASSERT(0);
   }
}

static void pcmStrmOpenDevice( pcmStrmMediaHdl *ihdl )
{
   MHdl *hdl = (MHdl *)ihdl;

   ihdl->end_status = MEDIA_NONE;
   ihdl->mh.dsp_rb_base = 0;
   mhdlDisallowSleep( (MHdl*)ihdl );

   if( ihdl->pcmStrm.is8KVoice ){
      MHdl *hdl = (MHdl *)ihdl;
      FC_Buf *fcBufHdr;
      hdl->rbInfo.param = (void *)L1Audio_FC_GetAudioBufferHeader();
      L1Audio_FC_WriteBufferToDSP( &hdl->rbInfo );
      fcBufHdr = (FC_Buf *)hdl->rbInfo.param;
      SAC_SphPlayPar.pucRingBuf   = fcBufHdr->pBuf;
      SAC_SphPlayPar.u4RingBufLen = fcBufHdr->uBufLength;
      SAC_SphPlayPar.pucWritePtr  = fcBufHdr->pWrite;
      SAC_SphPlayPar.u4PlyMod     = 1;
      
      SAC_SphPlayPar.u4WbPcm = 0;
      ihdl->mh.fc_aud_id = L1Audio_FC_HookHandler( (void *)ihdl, pcmStrmMsgHandler, 1, 0 );
      if( L1SP_PCMPlayback_CheckFlag() )
         SetSpeechEnhancement(true);//META taste function
      L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_IDLE_PLAY_START, ihdl->mh.fc_aud_id, (kal_uint32)&SAC_SphPlayPar, KAL_TRUE );
      
      AM_PCM8K_PlaybackOn( );
   } else {
      hdl->rbInfo.fc_format = FC_MEDIA_FORMAT_PCM;
      hdl->rbInfo.fc_operation = MEDIA_OPERATE_PLAYBACK;
      {
         kal_uint16 msg16;
         
         msg16 = (hdl->rbInfo.fc_format << 8) | hdl->rbInfo.fc_operation;
         hdl->fc_aud_id = L1Audio_FC_HookHandler( (void *)hdl, pcmStrmMsgHandler, 0, msg16 );
      }
      
#if __DRIVER_PRESERVE_DSP_SHARE_BUFFER__
      ihdl->mh.rbInfo.param = (void *)L1Audio_FC_GetAudioBufferHeader();
#endif
         
      // Fill bitstream information to FC
      {
         FC_Buf *fcBufHdr = (FC_Buf *)ihdl->mh.rbInfo.param;
         
         fcBufHdr->uTime = ihdl->mh.start_time;
         fcBufHdr->uSamplingFreq = ihdl->pcmStrm.sampleFreq;
         fcBufHdr->uChannelNum = ihdl->pcmStrm.isStereo + 1;
      }
      
      L1Audio_FC_AudioPlaybackOn(ihdl->mh.fc_aud_id, &ihdl->mh.rbInfo);
      AM_AudioPlaybackOn( ASP_TYPE_PCM_HI, ihdl->pcmStrm.freqType );
   }
}

static void pcmStrmCloseDevice( MHdl *hdl )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;
   if ( ihdl->pcmStrm.is8KVoice ) {
      if( L1SP_PCMPlayback_CheckFlag() )
         SetSpeechEnhancement(false);//META taste function
      L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_IDLE_PLAY_STOP, ihdl->mh.fc_aud_id, 0, KAL_TRUE );
      L1Audio_FC_ReleaseAudioBufferHeader( (FC_Buf **) &hdl->rbInfo.param );
      L1Audio_FC_UnHookHandler(ihdl->mh.fc_aud_id, 1);
      AM_PCM8K_PlaybackOff( true );
   }else{
      L1Audio_FC_AudioPlaybackOff(hdl->fc_aud_id);
      L1Audio_FC_ReleaseAudioBufferHeader( (FC_Buf **) &hdl->rbInfo.param );
      L1Audio_FC_UnHookHandler(hdl->fc_aud_id, 0);
      AM_AudioPlaybackOff( true );
   }
   mhdlAllowSleep( hdl );
}

static void pcmRecMsgHandler(kal_uint16 msgOp, kal_uint32 msgData, void *userData)
{
   MHdl *hdl = (MHdl *) userData;
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)userData;
   
   switch (msgOp) {
      case MSG_SAC2L1AUDIO_AUDIO_RECORD_ON_ACK:
         ASSERT( FC_STATE_IDLE == hdl->fc_state);
         hdl->fc_state = FC_STATE_RECORD;
         break;
      case MSG_SAC2L1AUDIO_AUDIO_RECORD_OFF_ACK:
         ASSERT( FC_STATE_RECORD == hdl->fc_state);
         hdl->fc_state = FC_STATE_IDLE;
         break;
      case MSG_SAC2L1AUDIO_AUDIO_DATA_NOTIFICATION:
         // Read data from shared buffer with FC.
         
         // Save to media buffer
         
         // Notify FC to ack.
         L1Audio_FC_AudioDataNotifyAck(hdl->fc_aud_id);
         
         // Notify MED to empty media buffer
         mhdlDataNotification((MHdl*)ihdl);
         
         break;
      default:
         ASSERT(0);
   }
}

static void pcmStrmRecOpenDevice( pcmStrmMediaHdl *ihdl )
{
   ihdl->end_status = MEDIA_NONE;
   mhdlDisallowSleep( (MHdl*)ihdl );
   ihdl->mh.rbInfo.fc_format = FC_MEDIA_FORMAT_PCM;
   ihdl->mh.rbInfo.fc_operation = MEDIA_OPERATE_RECORD;
   {
      kal_uint16 msg16;
      
      msg16 = (ihdl->mh.rbInfo.fc_format << 8) | ihdl->mh.rbInfo.fc_operation;
      ihdl->mh.fc_aud_id = L1Audio_FC_HookHandler( (void *)ihdl, pcmRecMsgHandler, 0, msg16 );
   }
   //L1Audio_FC_RecordOn(ihdl->mh.fc_aud_id, ihdl->mh.rbInfo.fc_format);
   AM_PCM8K_RecordOn();

}

static void pcmStrmRecCloseDevice( MHdl *hdl )
{
   L1Audio_FC_RecordOff( KAL_FALSE );
   L1Audio_FC_UnHookHandler(hdl->fc_aud_id, 1);
   AM_PCM8K_RecordOff( true );
   mhdlAllowSleep( hdl );
}


static Media_Event pcmStrmMFProcess( MHdl *hdl, Media_Event event )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;
   ASSERT(ihdl != NULL);

   kal_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_PROCESS, MEDIA_FORMAT_PCM_8K );

   switch(event)
   {
      case MEDIA_END:
         if (ihdl->pcmStrm.isPlayback) {
            if ( hdl->state == WAV_STATE_PLAYING )
               pcmStrmCloseDevice( hdl );
         } else {
            if ( hdl->state == WAV_STATE_RECORDING )
               pcmStrmRecCloseDevice( hdl );
         }
         hdl->state = WAV_STATE_IDLE;
         return event;

      case MEDIA_DATA_REQUEST:
         return MEDIA_DATA_REQUEST;
      case MEDIA_DATA_NOTIFICATION:
         return MEDIA_DATA_NOTIFICATION;
      
      default:
         ASSERT(0);    // should never reach here
   }
   return MEDIA_NONE;  // no use (only for compile)
}

static Media_Status pcmStrmMFPlay( MHdl *hdl )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;

   hdl->eof = KAL_FALSE;
   hdl->waiting = KAL_FALSE;
   ihdl->end_status = MEDIA_NONE;
   ihdl->decode_EOF = false;
   ihdl->zeroCount = 0;
   hdl->LastRingBufferRead = 0;
   switch( ihdl->pcmStrm.sampleFreq / 1000 ){   // update sample rate index of control table
      case 8:
         ihdl->pcmStrm.freqType = 0x00;
         ihdl->pcmStrm.sampleFreq = 8000;
         ihdl->frameDuration    = 10;
         break;
      case 16:
         ihdl->pcmStrm.freqType = 0x20;
         ihdl->pcmStrm.sampleFreq = 16000;
         ihdl->frameDuration    = 10;
         break;
      case 11:
         ihdl->pcmStrm.freqType = 0x11;
         ihdl->pcmStrm.sampleFreq = 11025;
         ihdl->frameDuration    = 40;
         break;
      case 12:
         ihdl->pcmStrm.freqType = 0x12;
         ihdl->pcmStrm.sampleFreq = 12000;
         ihdl->frameDuration    = 10;
         break;
      case 22:
         ihdl->pcmStrm.freqType = 0x21;
         ihdl->pcmStrm.sampleFreq = 22050;
         ihdl->frameDuration    = 20;
         break;
      case 24:
         ihdl->pcmStrm.freqType = 0x22;
         ihdl->pcmStrm.sampleFreq = 24000;
         ihdl->frameDuration    = 10;
         break;
      case 32:
         ihdl->pcmStrm.freqType = 0x40;
         ihdl->pcmStrm.sampleFreq = 32000;
         ihdl->frameDuration    = 10;
         break;
      case 44:
         ihdl->pcmStrm.freqType = 0x41;
         ihdl->pcmStrm.sampleFreq = 44100;
         ihdl->frameDuration    = 10;
         break;
      case 48:
         ihdl->pcmStrm.freqType = 0x42;
         ihdl->pcmStrm.sampleFreq = 48000;
         ihdl->frameDuration    = 10;
         break;
      default: 
         return MEDIA_UNSUPPORTED_FREQ;
   }

   if ( (ihdl->pcmStrm.bitPerSample != 8) && (ihdl->pcmStrm.bitPerSample != 16) )
      return MEDIA_BAD_PARAMETER;

   // Check whether we force mono to stereo
   if (ihdl->pcmStrm.isStereo)
      hdl->mono2stereo = false;
   else
      hdl->mono2stereo = true;

#if defined(CYBERON_DIC_TTS) || defined(IFLY_TTS) || defined(SINOVOICE_TTS) || defined(VRSI_ENABLE)
   // In order to reduce the loading of AvBT,
   // we force TTS/VRSI to be voice (not throught AvBT)
   if ( (ihdl->pcmStrm.freqType == 0x00) && (ihdl->pcmStrm.isStereo == false) ) {
#if defined(CYBERON_DIC_TTS) || defined(IFLY_TTS) || defined(SINOVOICE_TTS)
      if (ttsIsEnable()) {
         hdl->mono2stereo = false;
         ihdl->pcmStrm.is8KVoice = true;
      }
#endif
#if defined(VRSI_ENABLE)
      if (vrsiIsPlaying()) {
         hdl->mono2stereo = false;
         ihdl->pcmStrm.is8KVoice = true;
      }
#endif
   }

#endif

   pcmStrmOpenDevice(ihdl);
   ihdl->mh.state = WAV_STATE_PLAYING;
   kal_trace( TRACE_FUNC, L1AUDIO_PLAY_STREAM, MEDIA_FORMAT_PCM_8K );

   return MEDIA_SUCCESS;
}

static Media_Status pcmStrmMFRecord( MHdl *hdl )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;

   hdl->eof = KAL_FALSE;
   hdl->waiting = KAL_FALSE;
   ihdl->end_status = MEDIA_NONE;

   // Check buffer size
   ihdl->mh.rbInfo.rb_size = (FRAME_BUF_SIZE * 2) * (ihdl->mh.rbInfo.rb_size / (FRAME_BUF_SIZE * 2));
   if (ihdl->mh.rbInfo.rb_size == 0)
      return MEDIA_FAIL;

   ihdl->mh.state = WAV_STATE_RECORDING;
   pcmStrmRecOpenDevice(ihdl);
   kal_trace( TRACE_FUNC, L1AUDIO_RECORD, MEDIA_FORMAT_PCM_8K );

   return MEDIA_SUCCESS;
}

static Media_Status pcmStrmMFResume( MHdl *hdl )
{
   Media_Status result;
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;
   hdl->LastRingBufferRead = 0;
   if (ihdl->pcmStrm.isPlayback) {
      result = pcmStrmMFPlay(hdl);
   } else {
      result = pcmStrmMFRecord(hdl);
   }

   kal_trace( TRACE_FUNC, L1AUDIO_RESUME, MEDIA_FORMAT_PCM_8K );

   return result;
}

static Media_Status pcmStrmMFPause( MHdl *hdl )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;

   if (ihdl->pcmStrm.isPlayback) {
      ASSERT( hdl->state == WAV_STATE_PLAYING );

      ihdl->end_status = MEDIA_TERMINATED;
      pcmStrmCloseDevice( hdl );

      hdl->state = WAV_STATE_PLAY_PAUSE;
   } else {
      ASSERT( hdl->state == WAV_STATE_RECORDING );

      ihdl->end_status = MEDIA_TERMINATED;
      pcmStrmRecCloseDevice( hdl );

      hdl->state = WAV_STATE_PLAY_PAUSE;
   }

   kal_trace( TRACE_FUNC, L1AUDIO_PAUSE, MEDIA_FORMAT_PCM_8K );

   return MEDIA_SUCCESS;
}

static Media_Status pcmStrmMFStop( MHdl *hdl )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;

   if (ihdl->pcmStrm.isPlayback) {
      if( hdl->state == WAV_STATE_PLAY_PAUSE || hdl->state == WAV_STATE_IDLE )
         return MEDIA_SUCCESS;

      ihdl->end_status = MEDIA_TERMINATED;
      pcmStrmCloseDevice( hdl );
   } else {
      if( hdl->state == WAV_STATE_RECORD_PAUSE || hdl->state == WAV_STATE_IDLE )
         return MEDIA_SUCCESS;

      ihdl->end_status = MEDIA_TERMINATED;
      pcmStrmRecCloseDevice( hdl );
   }

   hdl->state = WAV_STATE_IDLE;
   kal_trace( TRACE_FUNC, L1AUDIO_STOP, MEDIA_FORMAT_PCM_8K );
   return MEDIA_SUCCESS;
}

static Media_Status pcmStrmMFClose( MHdl *hdl )
{
   pcmStrmMediaHdl *ihdl = (pcmStrmMediaHdl *)hdl;

   if (ihdl->pcmStrm.isPlayback) {
      ASSERT( hdl != 0 && hdl->state != WAV_STATE_PLAYING);
      mhdlFinalize( hdl, 0 );
   } else {
      ASSERT( hdl != 0 && hdl->state != WAV_STATE_RECORDING);

      mhdlFinalize( hdl, 0 );
   }

   L1SP_PCMPlayback_ClearFlag();
   free_ctrl_buffer( hdl );
   kal_trace( TRACE_FUNC, L1AUDIO_CLOSE, MEDIA_FORMAT_PCM_8K );

   return MEDIA_SUCCESS;
}


#if defined(__WAV_DECODE_SWIP__) && !defined(MED_NOT_PRESENT)
MHdl *PCM_Strm_Open_cilent(void(*handler)( MHdl *handle, Media_Event event ), void *param);
#endif

MHdl *PCM_Strm_Open(void(*handler)( MHdl *handle, Media_Event event ), void *param)
{
   MHdl *hdl;
   pcmStrmMediaHdl *ihdl;
   Media_PCM_Stream_Param *pcm_param = (Media_PCM_Stream_Param *) param;

#if defined(__WAV_DECODE_SWIP__) && !defined(MED_NOT_PRESENT)
   if(!pcm_param->forceVoice)
   {
      return PCM_Strm_Open_cilent(handler, param);
   }
#endif

   ihdl = (pcmStrmMediaHdl*)get_ctrl_buffer( sizeof(pcmStrmMediaHdl) );
   memset(ihdl, 0, sizeof(pcmStrmMediaHdl));
   hdl = (MHdl *) ihdl;
   mhdlInit( hdl, 0, NULL );

   hdl->handler   = handler;
   hdl->state     = WAV_STATE_IDLE;
   ihdl->pcmStrm.isPlayback    = true;
   ihdl->pcmStrm.isStereo      = pcm_param->isStereo;
   ihdl->pcmStrm.bitPerSample  = pcm_param->bitPerSample;
   ihdl->pcmStrm.sampleFreq    = pcm_param->sampleFreq;
   ihdl->pcmStrm.is8KVoice     = pcm_param->forceVoice;
   if(pcm_param->forceVoice == true) {
   	  L1SP_PCMPlayback_SetFlag();
   }

   hdl->Close     = pcmStrmMFClose;
   hdl->Pause     = pcmStrmMFPause;
   hdl->Stop      = pcmStrmMFStop;
   hdl->Process   = pcmStrmMFProcess;
   hdl->Play      = pcmStrmMFPlay;
   hdl->Resume    = pcmStrmMFResume;

   kal_trace( TRACE_FUNC, L1AUDIO_OPEN_STREAM, MEDIA_FORMAT_PCM_8K );

   return hdl;
}


MHdl *PCM_Strm_Rec_Open(void(*handler)( MHdl *handle, Media_Event event ), void *param)
{
   MHdl *hdl;
   pcmStrmMediaHdl *ihdl;

   ihdl = (pcmStrmMediaHdl*)get_ctrl_buffer( sizeof(pcmStrmMediaHdl) );
   memset(ihdl, 0, sizeof(pcmStrmMediaHdl));
   hdl = (MHdl *) ihdl;

   ihdl->pcmStrm.dedicated_mode = AM_IsSpeechOn();

   mhdlInit( hdl, 0, NULL );

   hdl->handler   = handler;
   hdl->state     = WAV_STATE_IDLE;
   ihdl->pcmStrm.isPlayback    = false;

   hdl->Close     = pcmStrmMFClose;
   hdl->Pause     = pcmStrmMFPause;
   hdl->Stop      = pcmStrmMFStop;
   hdl->Process   = pcmStrmMFProcess;
   hdl->Record    = pcmStrmMFRecord;
   hdl->Resume    = pcmStrmMFResume;

   kal_trace( TRACE_FUNC, L1AUDIO_OPEN_STREAM, MEDIA_FORMAT_PCM_8K );

   return hdl;
}

#endif   //#if defined(WAV_CODEC)
#endif
