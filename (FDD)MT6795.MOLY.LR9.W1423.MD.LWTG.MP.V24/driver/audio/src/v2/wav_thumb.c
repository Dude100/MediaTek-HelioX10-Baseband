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
 * wav_thumb.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   critical routines of WAV playback/recording functionality
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

#include "fs_type.h"
#include "string.h"
#include "fs_func.h"
#include "fs_errcode.h"
                 
#include "l1audio.h"
#include "l1audio_def.h"
#include "fc_def.h"
#include "am.h"
#include "media.h"
#include "wav.h"
#include "afe.h"
#include "exp_SphFasTypDef.h"

#include "audio_enum.h"
#if defined(WAV_CODEC)

struct wavHeader_Struct wavHeader;
struct wav_Struct wav;

#define  REAL_RESUMING_SUPPORT
#define TEMP_SOLUTION_FOR_WB_SPEECH_RECORD_NB_PCM

extern SAC_SphRecordPcmPar_t SAC_SphRecordPcmPar;
// #define  DSP_DEBUG_DEDICATED_MODE_RECORD  // This flag is for DSP to record stereo wave in dedicated mode.

extern void wavADPCMPutData( int32 dsp_len );
extern void wavADPCMPutData_ST( int32 dsp_len );
extern void wavMSADPCMPutData( int32 dsp_len );
extern void (*MS_ADPCM_Decode)( uint16 data, uint32 position );
extern void ms_adpcm_decode_stereo( uint16 data, uint32 position );
extern void ms_adpcm_decode_mono( uint16 data, uint32 position );

extern struct wavHeader_Struct wavHeader;
extern struct wav_Struct wav;

#if defined(REAL_RESUMING_SUPPORT)
static uint16         tmp_BlockCount[2];
static dviAdpcm_State tmp_dvi_state_ch1[2];
static dviAdpcm_State tmp_dvi_state_ch2[2];
static MS_ADPCM_STATE tmp_ms_adpcm_state[2][2];
static short          tmp_aCoeff[2][MSADPCM_EXTRA_COEFF][2];
#endif

#define abs(v) (((v) > 0) ? (v) : (-(v)))

static bool wavRECpcmPutSample( uint16 **pbuf, uint16 data, uint16 *sample_count  )
{
   **pbuf = data;
   *pbuf = *pbuf + 1;
   *sample_count = 1;
   return true;
}

static bool wavRECalawPutSample( uint16 **pbuf, uint16 data, uint16 *sample_count  )
{
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
#endif
   return false;
}

static bool wavRECulawPutSample( uint16 **pbuf, uint16 data, uint16 *sample_count  )
{
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
#endif
   return false;
}

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
#endif

/*----------------------------------------------------------------------*/
static void wavDataEncode( void *data ) /* This function works in L1Audio Task */
{
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
#ifdef   DSP_DEBUG_DEDICATED_MODE_RECORD
/* under construction !*/
/* under construction !*/
#else    // DSP_DEBUG_DEDICATED_MODE_RECORD
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__DUAL_MIC_SUPPORT__) && defined(__HQA_AUDIO__)
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif   // DSP_DEBUG_DEDICATED_MODE_RECORD
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
}

static bool wavGetDWord(uint8 *pBuf, uint32 *readPos, uint32 len, uint32 *data32)
{
   uint32 readPosCache;
   uint8 *pTemp;
   
   readPosCache = *readPos;
   pTemp = pBuf + readPosCache;
   
   // Check the length
   if (len < readPosCache+4)
      return false;

   *data32 = pTemp[0] | (pTemp[1]<<8) | (pTemp[2]<<16) | (pTemp[3]<<24);
   *readPos = readPosCache + 4;
   return true;
}

static bool wavGetWord(uint8 *pBuf, uint32 *readPos, uint32 len, uint16 *data16)
{
   uint32 readPosCache;
   uint8 *pTemp;
   
   readPosCache = *readPos;
   pTemp = pBuf + readPosCache;
   
   // Check the length
   if (len < readPosCache+2)
      return false;

   *data16 = pTemp[0] | (pTemp[1]<<8);
   *readPos = readPosCache + 2;
   return true;
}

Media_Status wavParseRecordFile( uint8 *pBuf, uint32 len, Media_Record_File_Info *info )
{
   uint32 readPos;
   uint32 dummy_32, riffSize, fmtSize, avgByteRate, headerSize = 0;
   uint16 dummy_16, audioFormat, blockAlign, bitPerSample;

   if (len < 44)
      return MEDIA_BAD_FORMAT;

   readPos = 0;
   // 1: Check RIFF (0~3)
   wavGetDWord(pBuf, &readPos, len, &dummy_32);
   if (dummy_32 != 0x46464952) {
      return MEDIA_BAD_FORMAT;
   }

   // 2 : Get RIFF size (4~7)
   wavGetDWord(pBuf, &readPos, len, &riffSize);
   
   // 3: Check WAVE (8~11)
   wavGetDWord(pBuf, &readPos, len, &dummy_32);
   if (dummy_32 != 0x45564157) {
      return MEDIA_BAD_FORMAT;
   }
   
   // 4: Check fmt (12~15)
   wavGetDWord(pBuf, &readPos, len, &dummy_32);
   if (dummy_32 != 0x20746D66) {
      return MEDIA_BAD_FORMAT;
   }
   
   // 5: fmt size (16~19)
   wavGetDWord(pBuf, &readPos, len, &fmtSize);
   if (fmtSize < 16) {
      return MEDIA_BAD_FORMAT;
   }

   // 6: Audio Format (20~21)
   wavGetWord(pBuf, &readPos, len, &audioFormat);
   
   // 7: Number of Channel (22~23)
   wavGetWord(pBuf, &readPos, len, &dummy_16);
   info->channel = dummy_16;
   if (dummy_16 != 1)
      return MEDIA_UNSUPPORTED_CHANNEL;
   
   // 8: Sample Rate (24~27)
   wavGetDWord(pBuf, &readPos, len, &dummy_32);
   info->sampleFreq = dummy_32;
   if ( (dummy_32 != 8000) && (dummy_32 != 16000) ) {
      return MEDIA_UNSUPPORTED_FREQ;
   }
   
   // 9: Average Byte Rate(28~31), Block Align (32~33), Bit Per Sample (34~35)
   wavGetDWord(pBuf, &readPos, len, &avgByteRate);
   wavGetWord(pBuf, &readPos, len, &blockAlign);
   wavGetWord(pBuf, &readPos, len, &bitPerSample);
   
   // 10: Process each kind of audio format
   switch (audioFormat) {
      case 0x0001:   // Linear PCM
         if (fmtSize != 16) {
            return MEDIA_BAD_FORMAT;
         }
         if (info->sampleFreq != 8000) {
             return MEDIA_UNSUPPORTED_FREQ;
         }
         if ( (avgByteRate != 16000) || (blockAlign != 2) || (bitPerSample != 16) ) {
            return MEDIA_UNSUPPORTED_TYPE;
         }
         info->format = MEDIA_FORMAT_WAV;
         info->sampleCount = (info->fileSize - 44)>>1;
         headerSize = 44;
         break;
      
      case 0x0006:   // A law
      case 0x0007:   // U Law
         if (len < 58) {
            return MEDIA_BAD_FORMAT;
         }
         if (fmtSize != 18) {
            return MEDIA_BAD_FORMAT;
         }
         if (info->sampleFreq != 8000) {
             return MEDIA_UNSUPPORTED_FREQ;
         }
         if ( (avgByteRate != 8000) || (blockAlign != 1) || (bitPerSample != 8) ) {
            return MEDIA_UNSUPPORTED_TYPE;
         }
         
         // Ext Size
         wavGetWord(pBuf, &readPos, len, &dummy_16);
         if (dummy_16 != 0)
            return MEDIA_BAD_FORMAT;
         // fact
         wavGetDWord(pBuf, &readPos, len, &dummy_32);
         if (dummy_32 != 0x74636166) {
            return MEDIA_BAD_FORMAT;
         }
         // fact size
         wavGetDWord(pBuf, &readPos, len, &dummy_32);
         if (dummy_32 != 0x4) {
            return MEDIA_BAD_FORMAT;
         }
         // sampleWritten
         wavGetDWord(pBuf, &readPos, len, &info->sampleCount);
         
         if (audioFormat == 0x0006)
            info->format = MEDIA_FORMAT_WAV_ALAW;
         else
            info->format = MEDIA_FORMAT_WAV_ULAW;
         headerSize = 58;
         break;
      
      case 0x0011:   // DVI-ADPCM
         if (len < 60) {
            return MEDIA_BAD_FORMAT;
         }
         if (fmtSize != 20) {
            return MEDIA_BAD_FORMAT;
         }
         if ( (blockAlign != 256) || (bitPerSample != 4) ) {
            return MEDIA_UNSUPPORTED_TYPE;
         }
         
         // Ext Size
         wavGetWord(pBuf, &readPos, len, &dummy_16);
         if (dummy_16 != 2)
            return MEDIA_BAD_FORMAT;
         // Sample Per Block
         wavGetWord(pBuf, &readPos, len, &dummy_16);
         if (dummy_16 != 505)
            return MEDIA_UNSUPPORTED_TYPE;
         // fact
         wavGetDWord(pBuf, &readPos, len, &dummy_32);
         if (dummy_32 != 0x74636166) {
            return MEDIA_BAD_FORMAT;
         }
         // fact size
         wavGetDWord(pBuf, &readPos, len, &dummy_32);
         if (dummy_32 != 0x4) {
            return MEDIA_BAD_FORMAT;
         }
         // sampleWritten
         wavGetDWord(pBuf, &readPos, len, &info->sampleCount);
         
         if ((info->sampleCount % 505) != 0)
            return MEDIA_UNSUPPORTED_TYPE;
         
         if (info->sampleFreq == 8000) {
            if (avgByteRate != 4055) {
               return MEDIA_UNSUPPORTED_TYPE;
            }
            info->format = MEDIA_FORMAT_WAV_DVI_ADPCM;
         } else if (info->sampleFreq == 16000) {
            if (avgByteRate != 8110) {
               return MEDIA_UNSUPPORTED_TYPE;
            }
            info->format = MEDIA_FORMAT_WAV_DVI_ADPCM_16K;
         } else {
             return MEDIA_UNSUPPORTED_FREQ;
         }
         headerSize = 60;
         break;
      
      default:
         return MEDIA_UNSUPPORTED_TYPE;
   }
   
   // 11: Check data
   wavGetDWord(pBuf, &readPos, len, &dummy_32);
   if (dummy_32 != 0x61746164) {
      return MEDIA_BAD_FORMAT;
   }
   
   // 12: Get data size
   wavGetDWord(pBuf, &readPos, len, &info->dataSize);
   if ( (info->dataSize + headerSize) != info->fileSize )
      return MEDIA_FAIL;

   if ( (info->format == MEDIA_FORMAT_WAV_DVI_ADPCM) || (info->format == MEDIA_FORMAT_WAV_DVI_ADPCM_16K) ) {
      if ( (info->dataSize & 0xFF) != 0 )
         return MEDIA_UNSUPPORTED_TYPE;
   }

   return MEDIA_SUCCESS;
}

Media_Status wavRecordAppendable( Media_Format format, FS_HANDLE fs, Media_Record_File_Info *info )
{
   uint8 *pBuf;
   Media_Status status;
   uint32 len;
   
   // To initialize info
   memset(info, 0, sizeof(Media_Record_File_Info));

   // Get the file size
   if (FS_NO_ERROR != FS_GetFileSize(fs, &info->fileSize) )
      return MEDIA_READ_FAIL;

   // To get the enough wav header which is supported by MediaTek
   pBuf = (uint8*)get_ctrl_buffer( 60*sizeof(uint8) );
   memset(pBuf, 0, 60*sizeof(uint8));

   if ( FS_NO_ERROR != FS_Read(fs, pBuf, 60, &len) ) {
      status = MEDIA_READ_FAIL;
   } else {
      // Parse the wav header
      status = wavParseRecordFile(pBuf, len, info);
   }

   free_ctrl_buffer( pBuf );
   
   // Compare the file information and wav format
   if (status == MEDIA_SUCCESS)
   {
      // Type mismatch
      if (format != info->format)
         return MEDIA_FAIL;
   }
   
   return status;
}


static void wavReadFromFC( int16 *buf, kal_uint32 msgData )
{
   int32 I, count;
   uint16 *pSrc;

   SAS_RecPcmRequestReadUlData_t *pcmBufPar = (SAS_RecPcmRequestReadUlData_t *)msgData;
   ASSERT( pcmBufPar->u4Len == 320 || pcmBufPar->u4Len == 640 );

   if ( pcmBufPar->u4Wb == 1 ){ 
      count = 320;
   } else {
      count = 160;
   }
   
#if defined(__DUAL_MIC_SUPPORT__) && defined(__HQA_AUDIO__)
   if(wav.ctrl->is_stereo){
      //need interleave
      pSrc = (uint16 *)pcmBufPar->pucBufPtr;
      for( I = 0 ; I < count ; I++ )
         buf[I*2] = *pSrc++;
      
      //need interleave
      pSrc = (uint16 *)pcmBufPar->pucNxtStrPtr;
      for( I = 0 ; I < count ; I++ )
         buf[I*2+1] = *pSrc++;
      buf += (uint32)count * 2;
   } else {
      pSrc = (uint16 *)pcmBufPar->pucBufPtr;
      for (I = count; I>0; I--)
         *buf++ = *pSrc++;
   }

#else
   pSrc = (uint16 *)pcmBufPar->pucBufPtr;
#if defined(TEMP_SOLUTION_FOR_WB_SPEECH_RECORD_NB_PCM)
   if( wav.dedicated_mode && pcmBufPar->u4Wb == 1 ){
      count = 160;
      for ( I = 0 ; I < count ; I++ )
         *buf++ = pSrc[I*2];
   } else
#endif
#if !(defined(MED_MODEM) || defined(MED_NOT_PRESENT) || defined(__SMART_PHONE_MODEM__))
   if(Media_IsRecordSilence())
   {
      for (I = count; I>0; I--)
      {
         *buf++ = 0;
      }
   }
   else
#endif
   {
      for (I = count; I>0; I--)
      {
         *buf++ = *pSrc++;
      }
   }
#endif
}

/**
	@isNeedDrop: source input will drop 1 channel sample 
	@isNeedReplenish: after source input processes "isNeedDrop", it will make one channel to 2 channel. 
*/
//void wavGetRecordData(kal_uint16 *pau2Buf, kal_uint32 u4length)
void wavGetRecordData(kal_uint16 *pau2Buf, kal_uint32 u4length, 
	const kal_bool isNeedDrop, const kal_bool isNeedReplenish)
{
    kal_uint16 *ptr;
    kal_uint32 count = 0;
    int32 I, srcJ;

    count = u4length;
    
    ASSERT(pau2Buf != NULL);
    
    ptr = wav.tmp_buf[wav.tmp_r&FRAME_BUF_MASK];

	if((!isNeedDrop) && (!isNeedReplenish)) { //keep the same
		for (I = count; I>0; I--) {
			*pau2Buf++ = *ptr++;
		}
	} else if (isNeedDrop && isNeedReplenish){ // 2ch -> 1ch -> 2ch
		for (I = count; I>0; I--) {
			*pau2Buf++ = *ptr;
			if(I&0x1) {
				ptr+=2;
			}
		}
	} else if(isNeedDrop) { //2ch -> 1ch
		for (I = count; I>0; I--) {
			*pau2Buf++ = *ptr++;
			ptr++;
		}
	} else { // 1ch -> 2ch
		for (I = count; I>0; I--) {
			*pau2Buf++ = *ptr;
			if(I&0x1) {
				ptr++;
			}
		}
	}

    wav.tmp_r++;

}

void wavSkip1FrameData()
{
    //if( (uint8)(wav.tmp_w - wav.tmp_r) >= FRAME_BUF_NO ){
    wav.tmp_r++;
    //}
}

void wavRecordData( kal_uint32 msgData )
{
   
   if(wav.state != WAV_STATE_RECORDING)
      return;

   if( wav.ctrl->end_status == MEDIA_TERMINATED) {
   		/* for samrtphone, do not need encode. As the result , phase it out
      if( (wav.ctrl->format==MEDIA_FORMAT_WAV_DVI_ADPCM  || wav.ctrl->format==MEDIA_FORMAT_WAV_DVI_ADPCM_16K )
         && wav.BlockCount != 128 && wav.state == WAV_STATE_IDLE){
         L1Audio_SetEvent( wav.aud_id, (void *)0 );        // zero padding
      }
      */
      return;
   }
   
   if( (uint8)(wav.tmp_w - wav.tmp_r) < FRAME_BUF_NO )
   {
      wavReadFromFC((int16 *)wav.tmp_buf[wav.tmp_w&FRAME_BUF_MASK], msgData );
      wav.tmp_w++;
      // for samrtphone, do not need encode. As the result , phase it out
      // L1Audio_SetEvent( wav.aud_id, (void *)0 );  // Activate the encoder runing in l1audio task 
   }
}

uint32 wavGetFrameIntensity()
{
   if( ( WAV_STATE_RECORDING == wav.state ) && 
       ( wav.tmp_w > 0))
   {
      uint16 I;
      int32 sum=0, v;
      int framesize = wav.MIC1_framesize;
      int16 * pBuf = wav.tmp_buf[(wav.tmp_w-1)&FRAME_BUF_MASK];
      for ( I = 0 ; I < framesize ; I++ ){
         v = pBuf[I];
         sum += abs(v);         
      }
      //kal_prompt_trace(MOD_L1SP, "Sum %d ", sum);     
      return (((sum == 0) || (framesize == 0)) ? 
                0 :
               (uint32)(sum / framesize));           
   }else
      return 0;     
}

static void wavRecMsgHandler(kal_uint16 msgOp, kal_uint32 msgData, void *userData)
{
   switch (msgOp) {
      case MSG_SAC2L1AUDIO_SPEECH_IDLE_RECORD_PCM_START_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_CALL_RECORD_PCM_START_ACK:
         #if !(defined(MT6573) || defined(MT6575) || defined(MT6577))
         ASSERT( FC_STATE_IDLE == wav.ctrl->fc_state);
         #endif
         wav.ctrl->fc_state = FC_STATE_RECORD;
         L1Audio_FC_SetWait(false);
         break;
      case MSG_SAC2L1AUDIO_SPEECH_IDLE_RECORD_PCM_STOP_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_CALL_RECORD_PCM_STOP_ACK:
         #if !(defined(MT6573) || defined(MT6575) || defined(MT6577))
         ASSERT( FC_STATE_RECORD == wav.ctrl->fc_state);
         #endif
         wav.ctrl->fc_state = FC_STATE_IDLE;
         L1Audio_FC_SetWait(false);
         break;
      case MSG_SAC2L1AUDIO_SPEECH_CALL_RECORD_PCM_REQUEST_READ_DATA:
      case MSG_SAC2L1AUDIO_SPEECH_IDLE_RECORD_PCM_REQUEST_READ_DATA:
      
         #if defined(__SMART_PHONE_MODEM__)   
            // Read data from shared buffer with FC.
            wavRecordData(msgData);
            wavRecordHandler(msgOp, 0x0005);  // PCM
            mediaIncRecordTime();  //for update record time
         #else
            // Read data from shared buffer with FC.
            if (Media_IsRecordTimeUp() == KAL_FALSE)
            {
               wavRecordData(msgData);
               mediaIncRecordTime();  //for update record time
            }
         #endif 
         
         // Notify FC to ack.
         if(msgOp == MSG_SAC2L1AUDIO_SPEECH_CALL_RECORD_PCM_REQUEST_READ_DATA)
            L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_CALL_RECORD_PCM_REQUEST_READ_DATA_ACK, 0, 0);
         else
            L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_IDLE_RECORD_PCM_REQUEST_READ_DATA_ACK, 0, 0);
         // Notify MED to empty media buffer
         mediaDataNotification();
         
         break;
      default:
         ASSERT(0);
   }
}

static void wavRecOpenDeviceHandler( void *state )
{
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   
#if !(defined(MT6573) || defined(MT6575) || defined(MT6577))
   TONE_StopAndWait();
   KT_StopAndWait();
#endif

#ifdef BGSND_ENABLE
   if ((!AM_IsSpeechOn()) && (wav.sndOffHandler != NULL))
      wav.sndOffHandler( wav.sndHdl );
#endif
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   
   
   if ( wav.ctrl->format == MEDIA_FORMAT_WAV_DVI_ADPCM_16K || wav.ctrl->format==MEDIA_FORMAT_PCM_16K )
      AM_PCM16K_RecordOn_V2(wav.dedicated_mode, wav.ctrl->fc_aud_id);
   else
      AM_PCM8K_RecordOn_V2(wav.dedicated_mode, wav.ctrl->fc_aud_id);
}

static void wavRecCloseDeviceHandler( void *state )
{
   if( wav.state == WAV_STATE_RECORD_PAUSE )
      return;
   if ( wav.ctrl->format == MEDIA_FORMAT_WAV_DVI_ADPCM_16K || wav.ctrl->format==MEDIA_FORMAT_PCM_16K )
      AM_PCM16K_RecordOff( true );
   else
      AM_PCM8K_RecordOff( true );
      
   if( wav.dedicated_mode ){
      L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_CALL_RECORD_PCM_STOP, wav.ctrl->fc_aud_id, 0, KAL_TRUE);
   } else {
      L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_IDLE_RECORD_PCM_STOP, wav.ctrl->fc_aud_id, 0, KAL_TRUE);
   }
}

static void wavInternalRecord( void )
{
   wav.state = WAV_STATE_RECORDING;
   wav.ctrl->end_status = MEDIA_NONE;

#if defined(__I2S_WAV_RECORD__)
   if(I2S_is_I2S_open())
      return;
#endif

   wav.ctrl->fc_format = FC_MEDIA_FORMAT_PCM;
   wav.ctrl->fc_operation = MEDIA_OPERATE_RECORD;
   
   {
      kal_uint16 msg16;
      
      msg16 = (wav.ctrl->fc_format << 8) | wav.ctrl->fc_operation;
      wav.ctrl->fc_aud_id = L1Audio_FC_HookHandler( (void *)0, wavRecMsgHandler, 1, msg16 );
   }
   
#if defined(__DUAL_MIC_SUPPORT__) && defined(__HQA_AUDIO__)
   if( wav.ctrl->is_stereo )
      SAC_SphRecordPcmPar.u4DualMic = 1;
   else
      SAC_SphRecordPcmPar.u4DualMic = 0;
#endif

   wavRecOpenDeviceHandler(NULL);
   
   if( wav.dedicated_mode )
      L1SP_Register_Service( wavRecOpenDeviceHandler, wavRecCloseDeviceHandler );
}

void wavRecordTurnOffDSP(void)
{
   wavRecCloseDeviceHandler(NULL);
   
   if( wav.dedicated_mode )
      L1SP_UnRegister_Service();
   
   L1Audio_FC_UnHookHandler(wav.ctrl->fc_aud_id, 1);  
}


void wavSetDropFrame(int num)
{
   wav.dropFrame = num; 
}


void wavRecord( mediaControl *ctrl, void *param )
{
   uint16 I, frame_len = 0;
   wav.ctrl = ctrl;

   wav.BlockCount = 0;
   wav.data_count  = 0;

   if (param != NULL) {
      Media_Record_File_Info *info;
      
      info = (Media_Record_File_Info *)param;
      wavHeader.wSamplesWritten = info->sampleCount;
      wavHeader.wDataLength = info->dataSize;
      wav.ctrl->file_len = (info->fileSize >> 1);
   } else {
      wavHeader.wSamplesWritten = 0;
      wavHeader.wDataLength = 0;
   }
#if defined(__I2S_WAV_RECORD__)
   if(!I2S_is_I2S_open())
#endif
   {
#ifdef   DSP_DEBUG_DEDICATED_MODE_RECORD
      ASSERT(ctrl->rb_size > FRAME_BUF_SIZE * FRAME_BUF_NO * 4);
      ctrl->rb_size -= FRAME_BUF_SIZE * FRAME_BUF_NO * 2; /* Get temp buffer */
      for( I = 0; I < FRAME_BUF_NO; I++ )
         wav.tmp_buf[I] = &ctrl->rb_base[ctrl->rb_size + FRAME_BUF_SIZE*I*2];
#else    // DSP_DEBUG_DEDICATED_MODE_RECORD
      if ( ctrl->format == MEDIA_FORMAT_WAV_DVI_ADPCM_16K || wav.ctrl->format==MEDIA_FORMAT_PCM_16K)
         frame_len = FRAME_BUF_SIZE_16K;
      else
      {
#if defined(__DUAL_MIC_SUPPORT__) && defined(__HQA_AUDIO__)
         if((L1Audio_GetDebugInfo(STEREO_RECORD_INFO) & 1) == 1 && ( wav.ctrl->format == MEDIA_FORMAT_WAV || wav.ctrl->format == MEDIA_FORMAT_WAV_DVI_ADPCM )){
            wav.ctrl->format = MEDIA_FORMAT_WAV;
            wav.ctrl->is_stereo = KAL_TRUE;
         }
         else
            wav.ctrl->is_stereo = KAL_FALSE;
#endif
#if defined(__DUAL_MIC_SUPPORT__) && defined(__HQA_AUDIO__)
         if( wav.ctrl->is_stereo ){
            frame_len = FRAME_BUF_SIZE*2;
         }
         else
#endif
         frame_len = FRAME_BUF_SIZE;
      }
      ASSERT(ctrl->rb_size > frame_len * FRAME_BUF_NO * 2);
      ctrl->rb_size -= frame_len * FRAME_BUF_NO; /* Get temp buffer */
      for( I = 0; I < FRAME_BUF_NO; I++ )
         wav.tmp_buf[I] = &ctrl->rb_base[ctrl->rb_size + frame_len*I];
#endif   // DSP_DEBUG_DEDICATED_MODE_RECORD
      wav.tmp_r = 0;
      wav.tmp_w = 0;
   }
   
#ifdef   DSP_DEBUG_DEDICATED_MODE_RECORD
   wav.ctrl->format = MEDIA_FORMAT_WAV;
#endif   // DSP_DEBUG_DEDICATED_MODE_RECORD

   {
      uint32 writeOffset = 0;
      wav.sample_rate = 8000;
      switch(wav.ctrl->format){
         case MEDIA_FORMAT_PCM_16K:
            wav.sample_rate = 16000;
         case MEDIA_FORMAT_PCM:
         case MEDIA_FORMAT_PCM_8K:
            wav.PutSample = wavRECpcmPutSample;
            wav.data_size = 1;
            wavHeader.wRiffLength=0;
            writeOffset = 0;
            break;
         case MEDIA_FORMAT_WAV:
            wav.PutSample = wavRECpcmPutSample;
            wav.data_size = 1;
            wavHeader.wRiffLength=36;
            writeOffset = 22;
            break;
         case MEDIA_FORMAT_WAV_ALAW:
         case MEDIA_FORMAT_WAV_ULAW:
            wav.PutSample = (wav.ctrl->format == MEDIA_FORMAT_WAV_ALAW)? wavRECalawPutSample:wavRECulawPutSample;
            wav.data_size = 2;
            wavHeader.wRiffLength=50;
            writeOffset = 29;
            break;
         case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
            wav.sample_rate = 16000;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            break;
         default:
            break;
      }
      if (param == NULL) {
         wav.ctrl->write += writeOffset;
      } else {
         Media_Record_File_Info *info;
      
         info = (Media_Record_File_Info *)param;
         wavHeader.wRiffLength = info->fileSize-8;
      }
   }
   wav.MIC1_framesize = frame_len;      
   wav.dedicated_mode = AM_IsSpeechOn();
   wavInternalRecord();
}

#if defined(REAL_RESUMING_SUPPORT)
void wavSetAdpcmState(bool realResume, uint32 mode)
{
   if(realResume)
   {
      wav.BlockCount = tmp_BlockCount[mode];
      wav.dvi_state_ch1.index = tmp_dvi_state_ch1[mode].index;
      wav.dvi_state_ch2.index = tmp_dvi_state_ch2[mode].index;
      wav.dvi_state_ch1.valpred = tmp_dvi_state_ch1[mode].valpred;
      wav.dvi_state_ch2.valpred = tmp_dvi_state_ch2[mode].valpred;

      memcpy(wav.ms_adpcm_state, tmp_ms_adpcm_state[mode], 2*sizeof(MS_ADPCM_STATE));
      memcpy(wav.aCoeff, tmp_aCoeff[1], 20*sizeof(short));

   } else
    {
      wav.BlockCount = 0;  /* reset counter */
    }
}

void wavGetAdpcmState(uint32 mode)
{
    tmp_BlockCount[mode] = wav.BlockCount;
    tmp_dvi_state_ch1[mode].index = wav.dvi_state_ch1.index;
    tmp_dvi_state_ch2[mode].index = wav.dvi_state_ch2.index;
    tmp_dvi_state_ch1[mode].valpred = wav.dvi_state_ch1.valpred;
    tmp_dvi_state_ch2[mode].valpred = wav.dvi_state_ch2.valpred;

    memcpy(tmp_ms_adpcm_state[mode], wav.ms_adpcm_state, 2*sizeof(MS_ADPCM_STATE));
    memcpy(tmp_aCoeff[mode], wav.aCoeff, 20*sizeof(short));
}

void wavCopyAdpcmState(uint32 src_mode, uint32 dst_mode)
{
    tmp_BlockCount[dst_mode] = tmp_BlockCount[src_mode];
    memcpy( &tmp_dvi_state_ch1[dst_mode], &tmp_dvi_state_ch1[src_mode], sizeof(dviAdpcm_State) );
    memcpy( &tmp_dvi_state_ch2[dst_mode], &tmp_dvi_state_ch2[src_mode], sizeof(dviAdpcm_State) );
    memcpy( tmp_ms_adpcm_state[dst_mode], tmp_ms_adpcm_state[src_mode], sizeof(MS_ADPCM_STATE) );
    memcpy(tmp_aCoeff[dst_mode], tmp_aCoeff[src_mode], 20*sizeof(short));
}
#endif


void wavStop( void )
{
   wav.ctrl->end_status = MEDIA_TERMINATED;
   if(wav.state == WAV_STATE_IDLE)
      return;
   
   switch(wav.state) {
      case WAV_STATE_RECORD_PAUSE:
         break;
      case WAV_STATE_RECORDING:
         wavRecordTurnOffDSP();
         break;
      default:
         ASSERT(KAL_FALSE);
   }
   wav.state = WAV_STATE_IDLE;  /* return to idle state */

   if ( (wav.ctrl->format==MEDIA_FORMAT_WAV_DVI_ADPCM  || wav.ctrl->format==MEDIA_FORMAT_WAV_DVI_ADPCM_16K )
      && wav.BlockCount != 128){
      L1Audio_SetEvent( wav.aud_id, (void *)0 );        /* zero padding */
   }
}

void wavGetFileHeader( uint32 *len )
{
   rb_ClearRB();
   rb_PutDWord( 0x46464952 );/* RIFF , 0*/

   if((wavHeader.wRiffLength+8) == (wav.ctrl->file_len<<1)){
      rb_PutDWord(wavHeader.wRiffLength);   /* file size , 2*/
   }else{
       rb_PutDWord((wav.ctrl->file_len<<1)-8);   /* file size , 2*/
       wavHeader.wDataLength -= (wavHeader.wRiffLength+8)-(wav.ctrl->file_len<<1);
       if( wav.ctrl->format == MEDIA_FORMAT_WAV_DVI_ADPCM || wav.ctrl->format == MEDIA_FORMAT_WAV_DVI_ADPCM_16K )
          wavHeader.wSamplesWritten = (wavHeader.wDataLength>>8)*505;
       else
          wavHeader.wSamplesWritten = wavHeader.wDataLength;
    }

   rb_PutDWord( 0x45564157 );  /* WAVE , 4 */
   rb_PutDWord( 0x20746D66 );   /* fmt , 6 */

   switch (wav.ctrl->format) {
      case MEDIA_FORMAT_WAV:     /* linear PCM */
         rb_PutDWord(16);   /* wavHeader.wFmtSize , 8 */
         rb_PutWord(0x01); /*wavHeader.wFormatTag, 10 */
#ifdef   DSP_DEBUG_DEDICATED_MODE_RECORD
         rb_PutWord(2); /*wavHeader.wChannels , 11 */
#elif defined(__DUAL_MIC_SUPPORT__) && defined(__HQA_AUDIO__)
         if((L1Audio_GetDebugInfo(STEREO_RECORD_INFO) & 1) == 1 ){
            rb_PutWord(2); /*wavHeader.wChannels , 11 */
         }
         else{
            rb_PutWord(1); /*wavHeader.wChannels , 11 */
         }
#else    // DSP_DEBUG_DEDICATED_MODE_RECORD
         rb_PutWord(1); /*wavHeader.wChannels , 11 */
#endif   // DSP_DEBUG_DEDICATED_MODE_RECORD
         rb_PutDWord(wav.sample_rate); /* wavHeader.wSamplesPerSecond, 12 */
         rb_PutDWord(wav.sample_rate*2); /*wavHeader.wAvgBytesPerSec, 14 */
         rb_PutWord(2);   /* wavHeader.wBlockAlign, 16 */
         rb_PutWord(16);  /*wavHeader.wBitsPerSample, 17 */
         rb_PutDWord( 0x61746164 );   /* data , 18 */
         rb_PutDWord(wavHeader.wDataLength);   /* data cksize, 20 */
         *len = (uint32)44;   /* Byte pre unit */
         //wav.ctrl->write+=22;
         break;
      case MEDIA_FORMAT_WAV_ALAW:     /* G.711 a-law */
      case MEDIA_FORMAT_WAV_ULAW:     /* g.711 mu-law */
         rb_PutDWord(18);   /* wavHeader.wFmtSize , 8 */
         rb_PutWord((wav.ctrl->format==MEDIA_FORMAT_WAV_ALAW)?0x06:0x07); /*wavHeader.wFormatTag, 10 */
         rb_PutWord(1); /*wavHeader.wChannels , 11 */
         rb_PutDWord(wav.sample_rate); /* wavHeader.wSamplesPerSecond, 12 */
         rb_PutDWord(wav.sample_rate); /*wavHeader.wAvgBytesPerSec, 14 */
         rb_PutWord(1);   /* wavHeader.wBlockAlign, 16 */
         rb_PutWord(8);  /*wavHeader.wBitsPerSample, 17 */
         rb_PutWord(0);  /*wavHeader.wExtSize, 18 */
         rb_PutDWord( 0x74636166 );   /* fact , 19 */
         rb_PutDWord(4);   /* wavHeader.wFactSize, 21 */
         rb_PutDWord(wavHeader.wSamplesWritten); // 23
         rb_PutDWord(0x61746164);/* data, 25 */
         rb_PutDWord(wavHeader.wDataLength);   /* data cksize, 27 */
         *len = (uint32)58;
         //wav.ctrl->write+=29;
         break;
      case MEDIA_FORMAT_WAV_DVI_ADPCM:    /* dvi/ima adpcm */
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
         rb_PutDWord(20);   /* wavHeader.wFmtSize , 8 */
         rb_PutWord(0x11); /*wavHeader.wFormatTag, 10 */
         rb_PutWord(1); /*wavHeader.wChannels , 11 */
         rb_PutDWord(wav.sample_rate);/* wavHeader.wSamplesPerSecond, 12 */
         rb_PutDWord(wav.sample_rate*256/505); /*wavHeader.wAvgBytesPerSec, 14 */
         rb_PutWord(256);   /* wavHeader.wBlockAlign, 16 */
         rb_PutWord(4);  /*wavHeader.wBitsPerSample, 17 */
         rb_PutWord(2);  /*wavHeader.wExtSize, 18 */
         rb_PutWord(505);  /* wavHeader.wSamplesPerBlock, 19 */
         rb_PutDWord( 0x74636166 );   /* data , 20 */
         rb_PutDWord(4);   /* wavHeader.wFactSize, 22 */
         rb_PutDWord(wavHeader.wSamplesWritten); // 24
         rb_PutDWord(0x61746164);/* data, 26 */
         rb_PutDWord(wavHeader.wDataLength);   /* data cksize, 28 */
         *len = (uint32)60;
         //wav.ctrl->write+=30;
         break;
      default:
         *len = (uint32) 0;
   }
}

void wavPause(mediaControl *mctrl)
{
   wav.ctrl->end_status = MEDIA_TERMINATED;
   switch(wav.state) {
      case WAV_STATE_RECORDING:
         wavRecordTurnOffDSP();
         wav.state = WAV_STATE_RECORD_PAUSE;
         break;
      default:
         ASSERT(KAL_FALSE);
   }
}

void wavResume(mediaControl *mctrl)
{
   switch(wav.state) {
      case WAV_STATE_RECORD_PAUSE:
         wav.state = WAV_STATE_RECORDING;
         wavInternalRecord();
         break;
      default:
         ASSERT(KAL_FALSE);
   }
}

void wavUpdateLevel( void )
{
   AFE_SetDigitalGain( L1SP_AUDIO, wav.ctrl->level );
}

void wavInit( uint16 aud_id )
{
   wav.aud_id = aud_id;
   wav.state = WAV_STATE_IDLE;  /* idle state */
   L1Audio_SetEventHandler( wav.aud_id, wavDataEncode );
}

#if defined(__I2S_WAV_RECORD__)

static kal_uint32 wav_i2s_GetMemSize()
{
   return 0;
}

static void wav_i2s_Free(void *hdl)
{
   ASSERT( wav.state == WAV_STATE_RECORDING );
   wav.state = WAV_STATE_IDLE;
}

static void* wav_i2s_Init(void *pEncBuf)
{
   ASSERT( wav.state == WAV_STATE_IDLE );
   wav.state = WAV_STATE_RECORDING;
   return 0;
}

static kal_uint32 wav_i2s_process(void *hdl, kal_int16 *inBuf, kal_uint32 inBufLen, kal_uint8 *outBuf, kal_uint32 *outBufLen, kal_bool flush_encoder)
{
   kal_uint32 inDataCnt = inBufLen;      //word
   kal_uint32 outFreeSpace = *outBufLen; //Byte
   
   if(wav.state != WAV_STATE_RECORDING)
      return 0;
   
   outFreeSpace &= 0xFFFFFFFE;

   if( wav.ctrl->format!=MEDIA_FORMAT_WAV_DVI_ADPCM && wav.ctrl->format!=MEDIA_FORMAT_WAV_DVI_ADPCM_16K )
   {
      while(inDataCnt && outFreeSpace)
      {
         kal_uint16 sample_count;
         if(wav.PutSample( (kal_uint16**)&outBuf, *inBuf++, &sample_count)) 
         {
            outFreeSpace-=2;
            wavHeader.wRiffLength+=2;
            wavHeader.wDataLength+=2;
            wavHeader.wSamplesWritten += sample_count;
         }
         inDataCnt--;
      }
   }
   else
   {
      while((inDataCnt>=505)&&(outFreeSpace >= 256))
      {
         kal_int32 I;
         for( I=505-1 ; I>=0 ; I--)
         {
            kal_uint16 sample_count;
            if( wav.PutSample( (kal_uint16**)&outBuf, *inBuf++, &sample_count) ) 
            { 
               outFreeSpace-=2;
               wavHeader.wRiffLength+=2;
               wavHeader.wDataLength+=2;
               wavHeader.wSamplesWritten += sample_count;
            }
            inDataCnt--;
         }
      }
   }
   *outBufLen = *outBufLen - outFreeSpace;
   return (inBufLen - inDataCnt);

}

void wav_I2S_Record(mediaControl *ctrl, kal_uint32 *param, Audio_Encode_Interface *AEI, kal_uint32 sample_rate)
{
   ASSERT(wav.state != WAV_STATE_RECORDING);
   AEI->Process    = wav_i2s_process;
   AEI->Init       = wav_i2s_Init;
   AEI->Free       = wav_i2s_Free;
   AEI->GetMemSize = wav_i2s_GetMemSize;
   wavRecord( ctrl, param );
   wav.sample_rate = sample_rate;
   wav.state = WAV_STATE_IDLE;
}
#endif

/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   
#ifdef BGSND_ENABLE
void wav_Register_SndService(
   void (*onHandler)(void *hdl),
   void (*offHandler)(void *hdl),
   void *hdl)
{
   wav.sndOnHandler  = onHandler;
   wav.sndOffHandler = offHandler;
   wav.sndHdl        = hdl;
}

void wav_UnRegister_SndService( void )
{
   wav.sndOnHandler  = NULL;
   wav.sndOffHandler = NULL;
}
#endif
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   

#endif    //  #if !defined(WAV_CODEC)
