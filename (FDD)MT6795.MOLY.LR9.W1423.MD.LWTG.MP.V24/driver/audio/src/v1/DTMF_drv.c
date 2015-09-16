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
 *   DTMF_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   ARM DTMF driver
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
*******************************************************************************/

#include "kal_public_api.h"
#include "kal_trace.h"
#include "l1audio.h"
#include "audio_def.h"
#include "l1sp_trc.h"
#include "am.h"
//#include "med_utility.h"
#include "l1audio_trace.h"



#if defined(__MCU_DTMF_SUPPORT__) //&& !defined( MED_MODEM )

//#include "pcmsink.h"
#include "dtmf_exp.h"

#define DTMF_MAX_DURATION           (0xFFFFFFFF)
#define DTMF_DEFALUT_SAMPLE_RATE    (16000)
#define DTMF_BUFFERED_FRAME_NUMBER  (4)
#define DTMF_MAX_FRAME              (0xFFFF)
#define DTMF_MIN_FRAME              (3)  // 5 * 20 msec
#define DTMF_FRAME_LEN              (20) // 20 msec
#define DTMF_STOP_WAIT_TICK         (80)//((DTMF_FRAME_LEN*DTMF_BUFFERED_FRAME_NUMBER+2)/4)
//#define DTMF_FLUSH_FRAME_NUMBER     ((PCM_SOUND_FILLDATA_THRESHOLD/DTMF_FRAME_LEN)+1)
#pragma arm section code="SECONDARY_ROCODE"

static kal_uint32 DTMF_FLUSH_FRAME_NUMBER = 3; 
static kal_uint32 uDtmfMuteLength1 = 6;
static kal_uint32 uDtmfMuteLength2 = 0;//13;
static kal_uint32 uDtmfMuteLength3 = 1;
static kal_uint32 uDtmfMuteLength4 = 3;
static kal_uint32 uMuteLength      = 150;//60;
static kal_uint32 uPreSilenceLength= 3;

static struct {
   const L1SP_QTMF   *pCurrQTMF;
   const L1SP_Tones  *pToneList;
   void             *pHandle;

   kal_uint32       uRemainDuration[3];
   kal_uint32       uTotalDuration[3];
   kal_bool         fIsQTMF[3];
   kal_bool         fIsOn[3];
   kal_bool         fEnable[3];

   //buffer
   AUD_RB_INFO      RingBuffer;
   kal_uint32       uFrameByte;

   //Current Tone
   kal_bool         fNewDTMF;
   kal_bool         fClearDTMF;  
   kal_bool         fIsToneListQTMF;
   kal_bool         fEnding;

   kal_uint16       uAudId;
   kal_uint16       uSampleRate;
   kal_uint8        uCurIdx;

   kal_bool         fIsKeytonePlaying;
   kal_bool         fIsTonePlaying;
   kal_uint8        uFlushSilenceCount;
   kal_bool         fForceStop;
}DTMF_SW;

static kal_uint32 dtmf_mcu_CheckDuration(kal_uint16 uDuration)
{
   if(uDuration)
   {
      uDuration = (uDuration+DTMF_FRAME_LEN-1)/DTMF_FRAME_LEN;
   }
   else
   {
      uDuration = DTMF_MAX_DURATION;
   }
   return uDuration;
}

static kal_bool dtmf_mcu_IsPlaying()
{
   if( DTMF_SW.fEnable[0] || DTMF_SW.fEnable[1] || DTMF_SW.fEnable[2] )
   {
      return KAL_TRUE;
   }
   return KAL_FALSE;
}

static void dtmf_mcu_GetKeyID(kal_uint32 uIndex, DTMF_KEY *uKey1, DTMF_KEY *uKey2 )
{
   ASSERT(uIndex<3);
   if(uIndex==0)
   {
      *uKey1 = DTMFKEY_Ext0;
      *uKey2 = DTMFKEY_Ext1;
   }
   else if(uIndex==1)
   {
      *uKey1 = DTMFKEY_Ext2;
      *uKey2 = DTMFKEY_Ext3;
   }
   else if(uIndex==2)
   {
      *uKey1 = DTMFKEY_Ext4;
      *uKey2 = DTMFKEY_Ext5;
   }
}

static void dtmf_mcu_GetPreIndex(kal_uint32 uCurIndex, kal_uint32 *uPreIndex1, kal_uint32 *uPreIndex2 )
{
   ASSERT(uCurIndex<3);
   if(uCurIndex==0)
   {
      *uPreIndex1 = 2;
      *uPreIndex2 = 1;
   }
   else if(uCurIndex==1)
   {
      *uPreIndex1 = 0;
      *uPreIndex2 = 2;
   }
   else
   {
      *uPreIndex1 = 1;
      *uPreIndex2 = 0;
   }
}

static void dtmf_mcu_DeActivatAllKey()
{
   kal_uint32 I = 0;
   for(I=0;I<3;I++)
   {
      if(DTMF_SW.fEnable[I])
      {
         if(DTMF_SW.fIsOn[I] == KAL_FALSE)
         {
            DTMF_SW.fEnable[I] = KAL_FALSE;
         }
         DTMF_SW.uRemainDuration[I] = 1;        
      }
   }
}

static void dtmf_mcu_ActivatNewKey()
{
   DTMF_KEY uKey1, uKey2;
   kal_uint32 uPreIndex1, uPreIndex2;
   kal_uint32 uCurrentDur;
   DTMF_SW.uCurIdx++;
   if(DTMF_SW.uCurIdx > 2)
   {
      DTMF_SW.uCurIdx = 0;
   }
   dtmf_mcu_GetPreIndex(DTMF_SW.uCurIdx, &uPreIndex1, &uPreIndex2);
   dtmf_mcu_GetKeyID(DTMF_SW.uCurIdx, &uKey1, &uKey2);
   DTMF_SetKey( DTMF_SW.pHandle, uKey1, (kal_int32)DTMF_SW.pCurrQTMF->freq1, (kal_int32)DTMF_SW.pCurrQTMF->freq2); 
   DTMF_SetKey( DTMF_SW.pHandle, uKey2, (kal_int32)DTMF_SW.pCurrQTMF->freq3, (kal_int32)DTMF_SW.pCurrQTMF->freq4); 
   uCurrentDur = dtmf_mcu_CheckDuration(DTMF_SW.pCurrQTMF->on_duration);
   DTMF_SW.uRemainDuration[DTMF_SW.uCurIdx] = DTMF_SW.uTotalDuration[DTMF_SW.uCurIdx] = uCurrentDur;
   DTMF_SW.fIsQTMF[DTMF_SW.uCurIdx] = DTMF_SW.fIsToneListQTMF;
   DTMF_SW.fEnable[DTMF_SW.uCurIdx] = KAL_TRUE;
   DTMF_SW.fIsOn[DTMF_SW.uCurIdx] = KAL_TRUE;
   if(DTMF_SW.fEnable[uPreIndex2])
   {
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, MCU_DTMF_NEWKEY_FORCE_END_2, uPreIndex2, DTMF_SW.uRemainDuration[uPreIndex2], DTMF_SW.uTotalDuration[uPreIndex2]);
      DTMF_SW.uRemainDuration[uPreIndex2] = 1;             
   } 
   if(DTMF_SW.fEnable[uPreIndex1])
   {
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, MCU_DTMF_NEWKEY_FORCE_END_1, uPreIndex1, DTMF_SW.uRemainDuration[uPreIndex1], DTMF_SW.uTotalDuration[uPreIndex1]);
      if(DTMF_SW.uTotalDuration[uPreIndex1] > DTMF_MIN_FRAME)
      {
         kal_uint32 uPlayedDur = DTMF_SW.uTotalDuration[uPreIndex1]-DTMF_SW.uRemainDuration[uPreIndex1];
         if(uPlayedDur >= DTMF_MIN_FRAME )
         {
            DTMF_SW.uRemainDuration[uPreIndex1] = 1;      
         }
         else
         {
            DTMF_SW.uRemainDuration[uPreIndex1] = DTMF_MIN_FRAME - uPlayedDur;    
         }
      }
      if(DTMF_SW.uRemainDuration[uPreIndex1] > uCurrentDur)
      {
         DTMF_SW.uRemainDuration[uPreIndex1] = uCurrentDur;
      }
   }
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, MCU_DTMF_NEWKEY, DTMF_SW.uCurIdx, uCurrentDur, DTMF_SW.fIsToneListQTMF, DTMF_SW.pCurrQTMF->freq1, DTMF_SW.pCurrQTMF->freq2, DTMF_SW.pCurrQTMF->freq3, DTMF_SW.pCurrQTMF->freq4);
}

static void dtmf_mcu_PrepareTone(kal_uint32 uIndex)
{
   DTMF_KEY uKey1, uKey2;
   if(!DTMF_SW.fEnable[uIndex])
   {
      return;
   }
   dtmf_mcu_GetKeyID(uIndex, &uKey1, &uKey2);
   if(DTMF_SW.uRemainDuration[uIndex] == DTMF_SW.uTotalDuration[uIndex])
   {
      if(DTMF_SW.fIsOn[uIndex] == KAL_FALSE)
      {
         DTMF_Tone(DTMF_SW.pHandle, uKey1, 0);
         DTMF_Tone(DTMF_SW.pHandle, uKey2, 0);
      }
      else if(DTMF_SW.fIsQTMF[uIndex])
      {
         DTMF_Tone(DTMF_SW.pHandle, uKey1, 1);
         DTMF_Tone(DTMF_SW.pHandle, uKey2, 1);
      }
      else
      {
         DTMF_Tone(DTMF_SW.pHandle, uKey1, 1);
         DTMF_Tone(DTMF_SW.pHandle, uKey2, 0);
      }
   }
   else if(DTMF_SW.uRemainDuration[uIndex] == 1)
   {
      DTMF_Tone(DTMF_SW.pHandle, uKey1, 0);
      DTMF_Tone(DTMF_SW.pHandle, uKey2, 0);
   }
}

static void dtmf_mcu_UpdateTone(kal_uint32 uIndex)
{
   DTMF_KEY uKey1, uKey2;
   if(!DTMF_SW.fEnable[uIndex])
   {
      return;
   }
   dtmf_mcu_GetKeyID(uIndex, &uKey1, &uKey2);
   DTMF_SW.uRemainDuration[uIndex]--;
   if(DTMF_SW.uRemainDuration[uIndex] == 0)
   {
      if(DTMF_SW.uCurIdx != uIndex)
      {
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, MCU_DTMF_UPDATE_TONE_PREV_END, uIndex);
         DTMF_SW.fEnable[uIndex] = KAL_FALSE;
      }
      else
      {
         if(DTMF_SW.fIsOn[uIndex])
         {
            if( DTMF_SW.pCurrQTMF->off_duration == 0 || DTMF_SW.fClearDTMF)
            {
               kal_trace( TRACE_GROUP_AUD_PLAYBACK, MCU_DTMF_UPDATE_TONE_CURR_END, uIndex);
               DTMF_SW.fEnable[uIndex] = KAL_FALSE;
            }
            else
            {
               kal_trace( TRACE_GROUP_AUD_PLAYBACK, MCU_DTMF_UPDATE_TONE_CURR_OFF, uIndex);
               DTMF_SW.fIsOn[uIndex] = KAL_FALSE;
               DTMF_SW.uRemainDuration[uIndex] = DTMF_SW.uTotalDuration[uIndex] = dtmf_mcu_CheckDuration(DTMF_SW.pCurrQTMF->off_duration);
               if(DTMF_SW.pCurrQTMF->off_duration)
               {
                  if(DTMF_SW.fIsToneListQTMF)
                  {
                     DTMF_SW.pCurrQTMF = (L1SP_QTMF *)DTMF_SW.pToneList + DTMF_SW.pCurrQTMF->next_tone;
                  }
                  else
                  {
                     DTMF_SW.pCurrQTMF = (L1SP_QTMF *)(DTMF_SW.pToneList + DTMF_SW.pCurrQTMF->next_tone);
                  }
               }
            }
         }
         else
         {
            kal_trace( TRACE_GROUP_AUD_PLAYBACK, MCU_DTMF_UPDATE_TONE_CURR_ON, uIndex);
            DTMF_SetKey( DTMF_SW.pHandle, uKey1, (kal_int32)DTMF_SW.pCurrQTMF->freq1, (kal_int32)DTMF_SW.pCurrQTMF->freq2); 
            DTMF_SetKey( DTMF_SW.pHandle, uKey2, (kal_int32)DTMF_SW.pCurrQTMF->freq3, (kal_int32)DTMF_SW.pCurrQTMF->freq4); 
            DTMF_SW.uRemainDuration[DTMF_SW.uCurIdx] = DTMF_SW.uTotalDuration[DTMF_SW.uCurIdx] = dtmf_mcu_CheckDuration(DTMF_SW.pCurrQTMF->on_duration);
            DTMF_SW.fIsOn[uIndex] = KAL_TRUE;
         }
      }
   }
   else if(DTMF_SW.uRemainDuration[uIndex] == 1 && DTMF_SW.fIsOn[uIndex])
   {  //ramp down
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, MCU_DTMF_UPDATE_TONE_RAMPDOWN, uIndex);
      DTMF_Tone(DTMF_SW.pHandle, uKey1, 0);
      DTMF_Tone(DTMF_SW.pHandle, uKey2, 0);
   }
}

static void dtmf_mcu_Destroy(kal_uint32 arg1, void* arg2)
{
   
   kal_bool fIsAudioRunning = false;//PcmSink_IsAudioRuning() || PcmSink_IsMixerRuning();   
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, MCU_DTMF_DESTROY, DTMF_SW.pHandle, DTMF_SW.fNewDTMF, DTMF_SW.fEnding, DTMF_SW.fForceStop);
   if(DTMF_SW.pHandle == NULL)
   {
      return;
   }
   if((DTMF_SW.fNewDTMF == KAL_FALSE && DTMF_SW.fEnding == KAL_TRUE) || DTMF_SW.fForceStop)
   {
      {
         {
//            void AM_SWToneOff( void );
//            AM_SWToneOff();
         }   
      }
      DTMF_SW.pHandle = NULL;
      L1Audio_ClearFlag( DTMF_SW.uAudId);
      L1Audio_FreeAudioID(DTMF_SW.uAudId);
      audio_free_mem( (void **) &DTMF_SW.RingBuffer.rb_base);//
      DTMF_SW.RingBuffer.rb_base = NULL;
      if(fIsAudioRunning)
      {
////!    PcmSink_Mute(KAL_TRUE, PCMSINK_MUTE_TONE);
         kal_sleep_task(uDtmfMuteLength3);
      }
      if(DTMF_SW.fIsKeytonePlaying)
      {
////!         PcmSink_StopSound(PCM_FUNC_KEYTONE);
      }
      else if(DTMF_SW.fIsTonePlaying)
      {
////!         PcmSink_StopSound(PCM_FUNC_TONE);
      }
      else
      {
         ASSERT(0);
      }
      memset(&DTMF_SW, 0, sizeof(DTMF_SW));
      if(fIsAudioRunning)
      {
         kal_sleep_task(uDtmfMuteLength4);
      }
////!      PcmSink_DepopUnMute( NULL );
////!      PcmSink_Mute(KAL_FALSE, PCMSINK_MUTE_TONE);
   }
}

static kal_bool dtmf_mcu_Process_Internal()
{   
   kal_uint32 uPreIndex1, uPreIndex2, uBufLen, uCurrentData;
   kal_uint8  *pBuf;
   kal_bool fIsPlaying = KAL_TRUE;
   kal_prompt_trace(MOD_L1SP, "[dtmf_mcu_Process_Internal] Enter");
   if(DTMF_SW.pHandle == NULL)
   {
      return KAL_FALSE;
   }
   rbGetWriteBuffer(&DTMF_SW.RingBuffer, &pBuf, &uBufLen);
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, MCU_DTMF_PROCESS_ENTRY, DTMF_SW.fNewDTMF, DTMF_SW.fClearDTMF, DTMF_SW.fEnding, uBufLen);
   if(DTMF_SW.fClearDTMF)
   {
      dtmf_mcu_DeActivatAllKey();
      if(!dtmf_mcu_IsPlaying())
      {
         DTMF_SW.fClearDTMF = KAL_FALSE;
      }
   }
   if(uBufLen < DTMF_SW.uFrameByte || (DTMF_SW.fEnding && !DTMF_SW.fNewDTMF) )
   {
      return KAL_FALSE;
   }
   dtmf_mcu_GetPreIndex(DTMF_SW.uCurIdx, &uPreIndex1, &uPreIndex2);
   if(DTMF_SW.fNewDTMF)
   {
      dtmf_mcu_ActivatNewKey(uPreIndex1, uPreIndex2);
      DTMF_SW.fNewDTMF = KAL_FALSE;
   }
   else
   {  //flush data
      fIsPlaying = dtmf_mcu_IsPlaying();
      uCurrentData = rbGetDataCount(&DTMF_SW.RingBuffer);
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, MCU_DTMF_PROCESS_STATUS, fIsPlaying, uCurrentData, DTMF_SW.uFlushSilenceCount);
      if(!fIsPlaying && DTMF_SW.uFlushSilenceCount<DTMF_FLUSH_FRAME_NUMBER)
      {
         DTMF_Gen(DTMF_SW.pHandle, pBuf); 
         rbWriteDataDone(&DTMF_SW.RingBuffer, DTMF_SW.uFrameByte);
         DTMF_SW.uFlushSilenceCount++;
      }
      if(!fIsPlaying && uCurrentData==0 && !DTMF_SW.fEnding)
      {
////!         PcmSink_Mute(KAL_TRUE, PCMSINK_MUTE_TONE);
         DTMF_SW.fEnding = KAL_TRUE;
         L1Audio_InProcCall(dtmf_mcu_Destroy, NULL, NULL);
         return KAL_FALSE;
      }
   }
   if(fIsPlaying)
   {
      dtmf_mcu_PrepareTone(0);
      dtmf_mcu_PrepareTone(1);
      dtmf_mcu_PrepareTone(2);
      DTMF_Gen(DTMF_SW.pHandle, pBuf);
      rbWriteDataDone(&DTMF_SW.RingBuffer, DTMF_SW.uFrameByte);
      dtmf_mcu_UpdateTone(0);
      dtmf_mcu_UpdateTone(1);
      dtmf_mcu_UpdateTone(2);
      DTMF_SW.fClearDTMF = KAL_FALSE;
      return KAL_TRUE;
   }
   kal_prompt_trace(MOD_L1SP, "[dtmf_mcu_Process_Internal] Leave");
   return KAL_FALSE;
}

static void dtmf_mcu_Process(void *pData)
{
   kal_bool fContinue;
   do
   {
      fContinue = dtmf_mcu_Process_Internal();
   }while(fContinue);
}

static void dtmf_mcu_Init(kal_uint16 uSampleRate)
{
   kal_uint32 uIntBufSize=0, uPcmBufSize=0, uTotalBufferSize=0;
   kal_uint8 *pAllocBuf;
   DTMF_SR uSr=0;
   memset(&DTMF_SW, 0, sizeof(DTMF_SW));
   DTMF_SW.uSampleRate = uSampleRate;
   switch (DTMF_SW.uSampleRate) 
   {
      case 8000:
         uSr = DTMF_8K;
         break;
      case 11025:
         uSr = DTMF_11K;
         break;
      case 12000:
         uSr = DTMF_12K;
         break;
      case 16000:
         uSr = DTMF_16K;
         break;
      case 22050:
         uSr = DTMF_22K;
         break;
      case 24000:
         uSr = DTMF_24K;
         break;
      case 32000:
         uSr = DTMF_32K;
         break;
      case 44100:
         uSr = DTMF_44K;
         break;
      case 48000:
         uSr = DTMF_48K;
         break;
      default:
         ASSERT(0); 
         break;	
   }
   DTMF_GetBufferSize(&uIntBufSize, &uPcmBufSize, uSr, DTMF_MONO);
   uTotalBufferSize = uIntBufSize + uPcmBufSize * DTMF_BUFFERED_FRAME_NUMBER;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, MCU_DTMF_INIT, uSampleRate, uPcmBufSize, uTotalBufferSize);
   pAllocBuf = (kal_uint8 *)audio_alloc_mem(uTotalBufferSize);  
   ASSERT(pAllocBuf);
   ASSERT(uIntBufSize);
   ASSERT(uPcmBufSize);
   DTMF_SW.uFrameByte = uPcmBufSize;
   DTMF_SW.RingBuffer.rb_base = (kal_uint8*)pAllocBuf;
   DTMF_SW.RingBuffer.rb_size = uPcmBufSize * DTMF_BUFFERED_FRAME_NUMBER;
   DTMF_SW.RingBuffer.write = uPcmBufSize * uPreSilenceLength; //fill a silence to prevent pop up noise
   DTMF_SW.RingBuffer.read=0;
   pAllocBuf += uPcmBufSize * DTMF_BUFFERED_FRAME_NUMBER;
   DTMF_SW.pHandle = DTMF_Init( (void *)pAllocBuf, DTMF_CONTINUOUS, uSr, DTMF_MONO);
   ASSERT(DTMF_SW.pHandle);
   DTMF_SW.uAudId = L1Audio_GetAudioID();
   L1Audio_SetFlag( DTMF_SW.uAudId );
   L1Audio_SetEventHandler( DTMF_SW.uAudId, dtmf_mcu_Process );
}

kal_bool DTMF_MCU_IsPlaying()
{
   if(DTMF_SW.pHandle)
   {
      return KAL_TRUE;
   }
   else
   {
      return KAL_FALSE;
   }
}

kal_bool DTMF_MCU_IsKeytonePlaying()
{
   return DTMF_SW.fIsKeytonePlaying;
}

kal_bool DTMF_MCU_IsTonePlaying()
{
   return DTMF_SW.fIsTonePlaying;
}

void DTMF_MCU_ReadDataDone(kal_uint32 uDataWord)
{
   kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, MCU_DTMF_READ_DATA_DONE, uDataWord);
   if(DTMF_SW.pHandle)
   {
      rbReadDataDone(&DTMF_SW.RingBuffer, uDataWord<<1);
   }
}

void DTMF_MCU_GetReadBuffer(kal_int16 **pBuf_16b, kal_uint32 *uDataWord)
{
   *pBuf_16b = NULL;
   *uDataWord = 0;
   if(DTMF_SW.pHandle)
   {
      kal_uint32 uDataByte;
      kal_uint8 *pBuf_8b;
      rbGetReadBuffer(&DTMF_SW.RingBuffer, &pBuf_8b, &uDataByte);
      ASSERT(!((kal_uint32)pBuf_8b & 0x1));
      *pBuf_16b = (kal_int16*)pBuf_8b;
      *uDataWord = uDataByte >> 1;
   }
   kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, MCU_DTMF_GET_REAR_BUFFER, *uDataWord);
}

kal_uint32 DTMF_MCU_GetDataCount()
{
   kal_uint32 uDataWord = 0;
   if(DTMF_SW.pHandle)
   {
      uDataWord = (rbGetDataCount(&DTMF_SW.RingBuffer))>>1;
   }
   kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, MCU_DTMF_GET_DATA_COUNT, uDataWord);
   return uDataWord;
}

void DTMF_MCU_DataRequestCallback()
{
   kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, MCU_DTMF_DATA_REQUEST, DTMF_SW.pHandle);
   if(DTMF_SW.pHandle)
   {
      L1Audio_SetEvent( DTMF_SW.uAudId, NULL );
   }
}

void DTMF_MCU_StopAndWait()
{
   kal_int32 I=0;
////!   kal_trace( TRACE_GROUP_AUD_PLAYBACK, MCU_DTMF_STOP_AND_WAIT, DTMF_SW.pHandle, I, AM_IsAudioPlaybackOn(), PcmSink_IsSoundRuning());
   DTMF_SW.fNewDTMF = KAL_FALSE;
   DTMF_SW.fForceStop = KAL_FALSE;
   if(DTMF_SW.pHandle)
   {
      DTMF_SW.fClearDTMF = KAL_TRUE;
      DTMF_MCU_DataRequestCallback();
      while(1)
      {  
////!    kal_trace( TRACE_GROUP_AUD_PLAYBACK, MCU_DTMF_STOP_AND_WAIT, DTMF_SW.pHandle, I, AM_IsAudioPlaybackOn(), PcmSink_IsSoundRuning());
////!    if(DTMF_SW.fEnding == KAL_TRUE || AM_IsAudioPlaybackOn() == -1 || !PcmSink_IsSoundRuning())
         {
            DTMF_SW.fForceStop = KAL_TRUE;
            dtmf_mcu_Destroy(NULL, NULL);
            break;
         }
         kal_sleep_task(1);
         I++;
         ASSERT(I<DTMF_STOP_WAIT_TICK);
      }
   }
}

void DTMF_MCU_Stop(kal_bool fIsKeytone)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, MCU_DTMF_STOP, DTMF_SW.pHandle);
   if( (DTMF_SW.fIsKeytonePlaying && !fIsKeytone) || (DTMF_SW.fIsTonePlaying && fIsKeytone) ) 
   {
      return;
   }
   DTMF_SW.fNewDTMF = KAL_FALSE;
   if(DTMF_SW.pHandle)
   {
      DTMF_SW.fClearDTMF = KAL_TRUE;
      DTMF_MCU_DataRequestCallback();
   }
}

void DTMF_MCU_Play( const L1SP_Tones *pToneList, kal_bool fIsQTMF, kal_bool fIsKeytone)
{
   kal_uint32 uSaveMask;
   kal_bool fIsAudioRunning = false;//PcmSink_IsAudioRuning() || PcmSink_IsMixerRuning();
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, MCU_DTMF_PLAY, DTMF_SW.pHandle);
   if( (DTMF_SW.fIsKeytonePlaying && !fIsKeytone) || (DTMF_SW.fIsTonePlaying && fIsKeytone) ) 
   {
      DTMF_MCU_StopAndWait(); 
   }
   if(DTMF_SW.pHandle == NULL)
   {
      kal_uint16 uSampleRate;
      kal_uint8  uChannelNumber;
////!      PcmSink_GetCurrentPcmInfo(&uSampleRate, &uChannelNumber);
      uSampleRate = 0;
      uChannelNumber = 1;
      if(uSampleRate == 0)
      {
         uSampleRate = DTMF_DEFALUT_SAMPLE_RATE;
      }
      dtmf_mcu_Init(uSampleRate);
////!      PcmSink_Mute(KAL_TRUE, PCMSINK_MUTE_TONE);
      if(fIsAudioRunning)
      {
////!         PcmSink_DepopMute(uMuteLength);
         if(uDtmfMuteLength1)
         {
            kal_sleep_task(uDtmfMuteLength1);
         }
      }
   }
   uSaveMask = SaveAndSetIRQMask();
   DTMF_SW.pToneList = pToneList;
   DTMF_SW.pCurrQTMF = (const L1SP_QTMF *)pToneList;
   DTMF_SW.fIsToneListQTMF = fIsQTMF;
   DTMF_SW.fNewDTMF = KAL_TRUE;
   DTMF_SW.fEnding = KAL_FALSE;
   DTMF_SW.uFlushSilenceCount = 0;
   RestoreIRQMask(uSaveMask);
   DTMF_MCU_DataRequestCallback();
   if(fIsKeytone && !DTMF_SW.fIsKeytonePlaying)
   {
      DTMF_SW.fIsKeytonePlaying = KAL_TRUE; 
////!      PcmSink_StartSound(PCM_FUNC_KEYTONE, DTMF_SW.uSampleRate, 2);
      if(fIsAudioRunning && uDtmfMuteLength2)
      {
         kal_sleep_task(uDtmfMuteLength2);
      }
   }
   else if(!fIsKeytone && !DTMF_SW.fIsTonePlaying)
   {
      DTMF_SW.fIsTonePlaying = KAL_TRUE; 
////!      PcmSink_StartSound(PCM_FUNC_TONE, DTMF_SW.uSampleRate, 2);
      if(fIsAudioRunning && uDtmfMuteLength2)
      {
         kal_sleep_task(uDtmfMuteLength2);
      }
   }
   {
//      void AM_SWToneOn( void );
//      AM_SWToneOn();
   }
////!   PcmSink_Mute(KAL_FALSE, PCMSINK_MUTE_TONE);
}

#pragma arm section 

#else

void DTMF_MCU_Play( const L1SP_Tones *pToneList, kal_bool fIsQTMF, kal_bool fIsKeytone){}
void DTMF_MCU_Stop(){}
void DTMF_MCU_StopAndWait(){}
void DTMF_MCU_DataRequestCallback(){}
kal_uint32 DTMF_MCU_GetDataCount(){return 0;}
void DTMF_MCU_GetReadBuffer(kal_int16 **pBuf_16b, kal_uint32 *uDataWord){}
void DTMF_MCU_ReadDataDone(kal_uint32 uDataWord){}
kal_bool DTMF_MCU_IsPlaying(){return KAL_FALSE;}
kal_bool DTMF_MCU_IsKeytonePlaying(){return KAL_FALSE;}

#endif

