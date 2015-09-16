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
 * media.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Media file recording/playback
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "fs_type.h"
#include "audio_enum.h"
#include "kal_trace.h"
#include "string.h"
#include "fsal.h"
#include "audcoeff_default.h"
#include "l1audio.h"
#include "l1audio_def.h"
#include "am.h"
#include "fc_def.h"
#include "media.h"
#include "afe.h"
#include "l1sp_trc.h"
#include "fs_errcode.h"


#if VERIFY_DATA_TO_DSP
extern void VERIFY_DATA_TO_DSP_START( void );
extern void VERIFY_DATA_TO_DSP_RESUME( void );
extern void VERIFY_DATA_TO_DSP_STOP( void );
#endif

#define RECORD_PRESILENCE_NUM 5  //100ms

static struct {
   mediaControl   ctrl;
   bool           waiting;   
   bool           paused;
   uint16         aud_id;
   void           (*media_handler)( Media_Event event );
   int32          recorded_time;
   kal_uint32     uStopTime; 
   bool           fTimeUp;      
   uint8          presilence;
} media;

struct {
   kal_uint32 uCurOffset;
   kal_uint32 uResumeFrameOffset;
} audResumeInfo;

/* Functions for Ring Buffer Access */

/* Reset the read/write pointers and odd bye flags of ring buffer */
/* This function should be called in Media_SetBuffer to reset the media buffer */
// Rey: Checked
void rb_ClearRB( void )
{
   media.ctrl.read = 0;
   media.ctrl.write = 0;
   media.ctrl.ob_flag_r = false;
   media.ctrl.ob_flag_w = false;
}

/* Return the count of data (in byte) in ring buffer */
/* Note that the data unit of return value is BYTE!!! */
// Rey: Checked
int32 rb_GetByteCount( void )
{
   int32 count;
   count = (int32)media.ctrl.write - (int32)media.ctrl.read;
   if( count < 0 )
      count += media.ctrl.rb_size;
   count <<= 1;
   if( media.ctrl.ob_flag_r )
      count ++;
   if( media.ctrl.ob_flag_w )
      count ++;
   return count;
}

/* Return the remaining space (in byte) of ring buffer */
/* Note that the data unit of return value is BYTE!!! */
// Rey: Checked
int32 rb_GetFreeSpace( void )
{
   int32 count;
   count = (int32)media.ctrl.read - (int32)media.ctrl.write - 1;
   if( count < 0 )
      count += (int32)media.ctrl.rb_size;
   count <<= 1;
   if( media.ctrl.ob_flag_r )
      count --;
   if( media.ctrl.ob_flag_w )
      count --;
   return count;
}

/* Get a byte from ring buffer */
// Rey: Checked
bool rb_GetByte( uint8* data_8 )
{
   if( rb_GetByteCount()==0 )
      return false;     // Buffer underflow
   if( media.ctrl.ob_flag_r )
   {
      *data_8 = media.ctrl.odd_byte_r;
      media.ctrl.ob_flag_r = false;
   }
   else
   {
      // Special Case: there's only one byte in ring buffer and the byte is in odd_byte_w
      if( media.ctrl.read == media.ctrl.write )
      {
         *data_8 = media.ctrl.odd_byte_w;
         media.ctrl.ob_flag_w = false;
         return true;
      }
      *data_8 = (uint8)media.ctrl.rb_base[media.ctrl.read];
      media.ctrl.odd_byte_r = (uint8)(media.ctrl.rb_base[media.ctrl.read] >> 8);
      media.ctrl.ob_flag_r = true;
      if( ++media.ctrl.read == media.ctrl.rb_size )
         media.ctrl.read = 0;
   }
   return true;
}

/* Get a word from ring buffer */
// Rey: Checked
bool rb_GetWord( uint16* data_16 )
{
   if( rb_GetByteCount() < 2 )
      return false;     // Buffer underflow
   if( media.ctrl.ob_flag_r )
   {
      // Special case: there is only one word in ring buffer...
      if( media.ctrl.read == media.ctrl.write )
      {
         *data_16 = media.ctrl.odd_byte_r | ((uint16)media.ctrl.odd_byte_w << 8);
         media.ctrl.ob_flag_r = false;
         media.ctrl.ob_flag_w = false;
         return true;
      }
      *data_16 = media.ctrl.odd_byte_r | (media.ctrl.rb_base[media.ctrl.read] << 8);
      media.ctrl.odd_byte_r = (uint8)(media.ctrl.rb_base[media.ctrl.read] >> 8);
   }
   else
      *data_16 = media.ctrl.rb_base[media.ctrl.read];
   if( ++media.ctrl.read == media.ctrl.rb_size )
      media.ctrl.read = 0;
   return true;
}

/* Get a double word from ring buffer */
// Rey: Checked
bool rb_GetDWord( uint32* data_32 )
{
   if( rb_GetByteCount() < 4 )
      return false;     // Buffer underflow
   if( media.ctrl.ob_flag_r )
   {
      *data_32 = media.ctrl.odd_byte_r;
      *data_32 |= ((uint32)media.ctrl.rb_base[media.ctrl.read] << 8);
      if( ++media.ctrl.read == media.ctrl.rb_size )
         media.ctrl.read = 0;
      // Special Case: there is only one double-word in ring buffer...
      if( media.ctrl.read == media.ctrl.write )
      {
         *data_32 |= ((uint32)media.ctrl.odd_byte_w << 24);
         media.ctrl.ob_flag_r = false;
         media.ctrl.ob_flag_w = false;
         return true;
      }
      *data_32 |= ((uint32)media.ctrl.rb_base[media.ctrl.read] << 24);
      media.ctrl.odd_byte_r = (uint8)(media.ctrl.rb_base[media.ctrl.read] >> 8);
   }
   else
   {
      *data_32 = media.ctrl.rb_base[media.ctrl.read];
      if( ++media.ctrl.read == media.ctrl.rb_size )
         media.ctrl.read = 0;
      *data_32 |= ((uint32)media.ctrl.rb_base[media.ctrl.read] << 16);
   }
   if( ++media.ctrl.read == media.ctrl.rb_size )
      media.ctrl.read = 0;
   return true;
}

/* Peek the value of the incoming byte in ring buffer, without moving forward the read pointer */
// Rey: Checked
bool rb_PeekByte( uint8* data_8 )
{
   if( rb_GetByteCount()==0 )
      return false;     // Buffer underflow
   if( media.ctrl.ob_flag_r )
      *data_8 = media.ctrl.odd_byte_r;
   else
   {
      // Special Case: there's only one byte in ring buffer...
      if( media.ctrl.read == media.ctrl.write )
         *data_8 = media.ctrl.odd_byte_w;
      else
         *data_8 = (uint8)media.ctrl.rb_base[media.ctrl.read];
   }
   return true;
}

/* Peek the value of the incoming word in ring buffer, without moving forward the read pointer */
// Rey: Checked
bool rb_PeekWord( uint16* data_16 )
{
   if( rb_GetByteCount() < 2 )
      return false;     // Buffer underflow
   if( media.ctrl.ob_flag_r )
   {
      // Special Case: there is only one word in ring buffer
      if( media.ctrl.read == media.ctrl.write )
         *data_16 = media.ctrl.odd_byte_r | ((uint16)media.ctrl.odd_byte_w << 8);
      else
         *data_16 = media.ctrl.odd_byte_r | (media.ctrl.rb_base[media.ctrl.read] << 8);
   }
   else
      *data_16 = media.ctrl.rb_base[media.ctrl.read];
   return true;
}

/* Peek the value of the incoming double word in ring buffer, without moving forward the read pointer */
// Rey: Checked
bool rb_PeekDWord( uint32* data_32 )
{
   uint32 tmp_read;
   if( rb_GetByteCount() < 4 )
      return false;     // Buffer underflow
   tmp_read = media.ctrl.read;
   if( media.ctrl.ob_flag_r )
   {
      *data_32 = media.ctrl.odd_byte_r;
      *data_32 |= ((uint32)media.ctrl.rb_base[tmp_read] << 8);
      if( ++tmp_read == media.ctrl.rb_size )
         tmp_read = 0;
      if( tmp_read == media.ctrl.write )
         *data_32 |= ((uint32)media.ctrl.odd_byte_w << 24);
      else
         *data_32 |= ((uint32)media.ctrl.rb_base[tmp_read] << 24);
   }
   else
   {
      *data_32 = media.ctrl.rb_base[tmp_read];
      if( ++tmp_read == media.ctrl.rb_size )
         tmp_read = 0;
      *data_32 |= ((uint32)media.ctrl.rb_base[tmp_read] << 16);
   }
   return true;
}

/* Skip N byte in ring buffer, return the number of bytes skipped */
// Rey: Checked
uint32 rb_SkipNByte( uint32 skip_count )
{
   uint32 ret;
   if( skip_count == 0 )
      return 0;
   ret = rb_GetByteCount();
   if( ret <= skip_count )
   {
      rb_ClearRB();
      return ret;
   }
   ret = skip_count;
   if( media.ctrl.ob_flag_r )
   {
      media.ctrl.ob_flag_r = false;
      if( --skip_count == 0 )
         return 1;
   }
   media.ctrl.read += (skip_count >> 1);
   if( media.ctrl.read >= media.ctrl.rb_size )
      media.ctrl.read -= media.ctrl.rb_size;
   skip_count &= 0x01;
   if( skip_count == 0 )
      return ret;
   media.ctrl.odd_byte_r = (uint8)(media.ctrl.rb_base[media.ctrl.read] >> 8);
   media.ctrl.ob_flag_r = true;
   if( ++media.ctrl.read == media.ctrl.rb_size )
      media.ctrl.read = 0;
   return ret;
}

/* Skip N Words in ring buffer, return the number of words skipped */
// Rey: Checked
uint32 rb_SkipNWord( uint32 skip_count )
{
   uint32 ret;
   if( skip_count == 0 )
      return 0;
   ret = rb_GetByteCount();
   if( (ret >> 1) <= skip_count )
   {
      if((ret & 0x01) == 0)   // If ret is even, then the ring buffer should be cleared
      {
         rb_ClearRB();
         return (ret >> 1);
      }
      else
         ret >>= 1;
   }
   else
      ret = skip_count;

   if( ret == 0 )
      return 0;
   media.ctrl.read += ret - 1;
   if( media.ctrl.read >= media.ctrl.rb_size )
      media.ctrl.read -= media.ctrl.rb_size;
   if( media.ctrl.ob_flag_r )
      media.ctrl.odd_byte_r = (uint8)(media.ctrl.rb_base[media.ctrl.read] >> 8);
   if( ++media.ctrl.read == media.ctrl.rb_size )
      media.ctrl.read = 0;
   return ret;
}

/* Get len bytes from ring buffer to buffer */
/* The return value is the actual number of bytes moved */
int rb_GetNByte( uint8 *buffer, int len )
{
   uint8 *dst_ptr;
   const uint8 *src_ptr;
   int len_to_copy, remaining;
   if( len == 0 )
      return 0;
   ASSERT( buffer != NULL );
   len_to_copy = rb_GetByteCount();
   if( len_to_copy == 0 )
      return 0;
   if( len < len_to_copy )
      len_to_copy = len;
   remaining = len_to_copy;
   dst_ptr = buffer;
   if( media.ctrl.ob_flag_r )
   {
      *dst_ptr = media.ctrl.odd_byte_r;
      media.ctrl.ob_flag_r = false;
      if( --remaining == 0 )
         return 1;
      dst_ptr++;
   }
   if( media.ctrl.write < media.ctrl.read )
   {
      len = (media.ctrl.rb_size - media.ctrl.read ) << 1;
      if( len > remaining )
         len = remaining;
      src_ptr = (uint8*)&media.ctrl.rb_base[media.ctrl.read];
#ifdef _TESTENV
      memcpy( dst_ptr, src_ptr, len & 0xFFFFFFFE );
#else
      kal_mem_cpy( dst_ptr, src_ptr, len & 0xFFFFFFFE );
#endif
      dst_ptr += len;
      media.ctrl.read += (len >> 1);
      if( media.ctrl.read == media.ctrl.rb_size )
         media.ctrl.read = 0;
      remaining -= len;
      if( len & 0x01 )
      {
         media.ctrl.ob_flag_r = true;
         media.ctrl.odd_byte_r = *(src_ptr+len);
         if( ++media.ctrl.read == media.ctrl.rb_size )
            media.ctrl.read = 0;
         ASSERT( remaining == 0 );
         return len_to_copy;
      }
   }
   if( remaining )
   {
      src_ptr = (uint8*)&media.ctrl.rb_base[media.ctrl.read];
#ifdef _TESTENV
      memcpy( dst_ptr, src_ptr, remaining & 0xFFFFFFFE );
#else
      kal_mem_cpy( dst_ptr, src_ptr, remaining & 0xFFFFFFFE );
#endif
      media.ctrl.read += (remaining >> 1);
      if( remaining & 0x01 )
      {
         if( media.ctrl.read == media.ctrl.write )
         {
            *(dst_ptr+remaining - 1) = media.ctrl.odd_byte_w;
            media.ctrl.ob_flag_w = false;
         }else
         {
            *(dst_ptr+remaining - 1) = *(src_ptr+remaining - 1);
            media.ctrl.ob_flag_r = true;
            media.ctrl.odd_byte_r = *(src_ptr+remaining);
            media.ctrl.read ++;
         }
      }
   }
   return len_to_copy;
}

/* Put bytes from buffer into ring buffer */
/* The return value is the actual number of bytes moved */
int rb_PutNByte( const uint8 *buffer, int len )
{
   uint8 *dst_ptr;
   const uint8 *src_ptr;
   int len_to_copy, remaining;
   if( len == 0 )
      return 0;
   ASSERT( buffer!=NULL );
   len_to_copy = rb_GetFreeSpace();
   if( len_to_copy == 0 )
      return 0;
   if( len_to_copy > len )
      len_to_copy = len;
   remaining = len_to_copy;
   src_ptr = buffer;
   if( media.ctrl.ob_flag_w )
   {
      media.ctrl.rb_base[media.ctrl.write]=media.ctrl.odd_byte_w | (uint16)*src_ptr << 8;
      media.ctrl.ob_flag_w = false;
      if( ++media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
      if( --remaining == 0 )
         return 1;
      src_ptr++;
   }
   if( media.ctrl.write >= media.ctrl.read )
   {
      // step 1: copy from write index to the end of ring buffer
      len = (media.ctrl.rb_size - media.ctrl.write) << 1;
      if( remaining < len )
         len = remaining;
      dst_ptr = (uint8*)&(media.ctrl.rb_base[media.ctrl.write]);
#ifdef _TESTENV
      memcpy( dst_ptr, src_ptr, len & 0xFFFFFFFE );
#else
      kal_mem_cpy( dst_ptr, src_ptr, len & 0xFFFFFFFE );
#endif
      src_ptr += len;
      media.ctrl.write += (len >> 1);
      if( media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
      remaining -= len;
      if( len & 0x01 )
      {
         media.ctrl.ob_flag_w = true;
         media.ctrl.odd_byte_w = *(src_ptr - 1);
         ASSERT( remaining == 0 );
         return len_to_copy;
      }
   }
   if( remaining )
   {
      dst_ptr = (uint8*)&(media.ctrl.rb_base[media.ctrl.write]);
#ifdef _TESTENV
      memcpy( dst_ptr, src_ptr, remaining & 0xFFFFFFFE );
#else
      kal_mem_cpy( dst_ptr, src_ptr, remaining & 0xFFFFFFFE );
#endif
      media.ctrl.write += (remaining >> 1);
      if( media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
      if( remaining & 0x01 )
      {
         media.ctrl.ob_flag_w = true;
         media.ctrl.odd_byte_w = buffer[len_to_copy-1];
      }
   }
   return len_to_copy;
}

/* Put a byte into ringer buffer */
bool rb_PutByte( uint8 data_8 )
{
   if( rb_GetFreeSpace() == 0 )
      return false;     // Buffer overflow
   if( media.ctrl.ob_flag_w )
   {
      media.ctrl.ob_flag_w = false;
      media.ctrl.rb_base[media.ctrl.write] = media.ctrl.odd_byte_w | ((uint16)data_8 << 8);
      if( ++media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
   }
   else
   {
      media.ctrl.odd_byte_w = data_8;
      media.ctrl.ob_flag_w = true;
   }
   return true;
}

/* Put a word into ring buffer */
bool rb_PutWord( uint16 data_16 )
{
   if( rb_GetFreeSpace() < 2 )
      return false;     // Buffer overflow
   if( media.ctrl.ob_flag_w )
   {
      media.ctrl.rb_base[media.ctrl.write] = media.ctrl.odd_byte_w | (data_16 << 8);
      media.ctrl.odd_byte_w = (uint8)(data_16 >> 8);
   }
   else
      media.ctrl.rb_base[media.ctrl.write] = data_16;
   if( ++media.ctrl.write == media.ctrl.rb_size )
      media.ctrl.write = 0;
   return true;
}

/* Put a double word into ring buffer */
bool rb_PutDWord( uint32 data_32 )
{
   if( rb_GetFreeSpace() < 4 )
      return false;     // Buffer overflow
   if( media.ctrl.ob_flag_w )
   {
      media.ctrl.rb_base[media.ctrl.write] = media.ctrl.odd_byte_w | ((uint16)data_32 << 8);
      if( ++media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
      media.ctrl.rb_base[media.ctrl.write] = (uint16)(data_32 >> 8);
      media.ctrl.odd_byte_w = (uint8)(data_32 >> 24);
   }
   else
   {
      media.ctrl.rb_base[media.ctrl.write] = (uint16)data_32;
      if( ++media.ctrl.write == media.ctrl.rb_size )
         media.ctrl.write = 0;
      media.ctrl.rb_base[media.ctrl.write] = (uint16)(data_32 >> 16);
   }
   if( ++media.ctrl.write == media.ctrl.rb_size )
      media.ctrl.write = 0;
   return true;
}

/* Return media.ctrl.read */
uint32 rb_GetReadIndex( void )
{
   return media.ctrl.read;
}

/* Return media.ctrl.write */
uint32 rb_GetWriteIndex( void )
{
   return media.ctrl.write;
}

/* Return media.ctrl.rb_size */
uint32 rb_GetSize( void )
{
   return media.ctrl.rb_size << 1;
}

/* Return media.ctrl.odd_byte_r | ((uint16)media.ctrl.odd_byte_w)<<8 */
uint16 rb_GetOddByte( void )
{
   return media.ctrl.odd_byte_r | ((uint16)media.ctrl.odd_byte_w)<<8;
}

uint16 rb_GetOBFlag( void )
{
   uint16 ret=0;
   if( media.ctrl.ob_flag_r )
      ret |= 1;
   if( media.ctrl.ob_flag_w )
      ret |= 2;
   return ret;
}

/* ------------------------------------------------------------------------------ */
void mediaDataNotification( void )
{
   if( media.waiting )
      return;
   if( mediaGetDataCount() >= media.ctrl.rb_threshold) {
      mediaSetEvent( MEDIA_DATA_NOTIFICATION );
      media.waiting = true;
   }
}

kal_bool fPowerOffAudio = KAL_FALSE;

void Media_PowerOff(void)
{
   fPowerOffAudio = KAL_TRUE;
	//AFE_FastCloseSpk();
}

/* ------------------------------------------------------------------------------ */
/*  Media File Playback/Recording Interface                                       */
/* ------------------------------------------------------------------------------ */
extern void AudioPP_Loudness_Registry( void );

void Media_SetOutputDevice( uint8 device )
{
   AFE_SetOutputDevice( L1SP_VOICE, device );
   AFE_SetOutputDevice( L1SP_AUDIO, device );

#if APM_SUPPORT
#if defined( __BES_LOUDNESS_SUPPORT__ ) || defined(__BES_LOUDNESS_ON_I2S__)
   AudioPP_Loudness_Registry();
#endif
#endif

#if defined( __BES_BASS_SUPPORT__ )
   AudioPP_BassEnhance_Registry();
#endif

}

void  Media_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
   AFE_SetOutputVolume( L1SP_VOICE, volume1, digital_gain_index );
   AFE_SetOutputVolume( L1SP_AUDIO, volume1, digital_gain_index );
}

#if defined(__GAIN_TABLE_SUPPORT__)
/* uint32 ext_amp_gain is only for dual path scenario, used for loudspk ext amp gain control.
 Earphone ext amp control is still in gain */
void  Media_SetOutputGainControl( uint32 gain, uint32 ext_amp_gain )
{
   AFE_SetOutputGainControlDualPath( L1SP_AUDIO, ext_amp_gain );
   AFE_SetOutputGainControlDualPath( L1SP_VOICE, ext_amp_gain );
   AFE_SetOutputGainControl( L1SP_VOICE, gain );
   AFE_SetOutputGainControl( L1SP_AUDIO, gain );
}
#endif

void  Media_SetLevelVolume( kal_uint8 MaxAnalogGain, kal_uint8 step, kal_uint8 level )
{
   AFE_SetLevelVolume( L1SP_VOICE, MaxAnalogGain, step,level);
   AFE_SetLevelVolume( L1SP_AUDIO, MaxAnalogGain, step,level);
}

void Media_SetBuffer( uint16 *buffer, uint32 buf_len )
{
   media.ctrl.rb_base = buffer;
   media.ctrl.rb_size = buf_len;
   rb_ClearRB();
   media.ctrl.eof     = false;
   media.ctrl.file_len = 0;
   
   Media_SetRBOffset(0);
}

void Media_GetWriteBuffer( uint16 **buffer, uint32 *buf_len )
{
   int32 count;

   if( media.ctrl.read > media.ctrl.write )
      count = (int32)media.ctrl.read - (int32)media.ctrl.write - 1;
   else if( media.ctrl.read == 0 )
      count = (int32)media.ctrl.rb_size - (int32)media.ctrl.write - 1;
   else
      count = (int32)media.ctrl.rb_size - (int32)media.ctrl.write;

   *buffer = &media.ctrl.rb_base[media.ctrl.write];
   *buf_len = (uint32)count;
}

void Media_WriteDataDone( uint32 len )
{
   media.ctrl.write += len;
   if( media.ctrl.write >= media.ctrl.rb_size )
      media.ctrl.write = 0;
   media.waiting = false;
}

void Media_WriteDataDone_NoWaiting( uint32 len )
{
   media.ctrl.write += len;
   if( media.ctrl.write >= media.ctrl.rb_size )
      media.ctrl.write = 0;
}

void Media_DataFinished( void )
{
   media.ctrl.eof = true;
}

void Media_GetReadBuffer( uint16 **buffer, uint32 *buf_len )
{
   int32 count;

   if( media.ctrl.write >= media.ctrl.read )
      count = (int32)media.ctrl.write - (int32)media.ctrl.read;
   else
      count = (int32)media.ctrl.rb_size - (int32)media.ctrl.read;

   *buffer = &media.ctrl.rb_base[media.ctrl.read];
   *buf_len = (uint32)count;
}

void Media_ReadDataDone( uint32 len )
{
   media.ctrl.read += len;
   media.ctrl.file_len += len;
   if( media.ctrl.read >= media.ctrl.rb_size )
      media.ctrl.read = 0;
   media.waiting = false;
}

int32 mediaGetFreeSpace( void )
{
   int32 count;

   count = (int32)media.ctrl.read - (int32)media.ctrl.write - 1;
   if( count < 0 )
      count += (int32)media.ctrl.rb_size;
   return count;
}

int32 mediaGetDataCount( void )
{
   int32 count;

   count = (int32)media.ctrl.write - (int32)media.ctrl.read;
   if( count < 0 )
      count += media.ctrl.rb_size;
   return count;
}

void mediaIncRecordTime( void )
{
   media.recorded_time += 20;
}

kal_int32 Media_GetDataCount( void )
{
   return mediaGetDataCount();
}

bool mediaIsDataConsumed( void )
{
   return media.ctrl.isDataConsumed;
}

mediaControl *mediaGetControl( void )
{
   return &media.ctrl;
}

/* get .wav file header, return starting address pointer & header-length in byte*/
void Media_GetFileHeader( uint8 **header, uint32 *len )
{
   *len = 0;
   switch (media.ctrl.format) {
#if defined(WAV_CODEC)
      case MEDIA_FORMAT_WAV:     /* linear PCM */
      case MEDIA_FORMAT_WAV_ALAW:     /* G.711 a-law */
      case MEDIA_FORMAT_WAV_ULAW:     /* g.711 mu-law */
      case MEDIA_FORMAT_WAV_DVI_ADPCM:    /* dvi/ima adpcm */
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
         wavGetFileHeader( len );
         break;
#endif
      default:
         *len = 0;
   }
   *header = (uint8 *)media.ctrl.rb_base;
}
/* ------------------------------------------------------------------------------ */

#ifndef __L1_STANDALONE__ // avoid link error

Media_Status Media_Play( Media_Format format, void (*media_handler)( Media_Event event ), void *param )
{
   return MEDIA_FAIL;
}

#endif

kal_bool Media_IsRecordSilence( void )
{
   if(media.presilence > RECORD_PRESILENCE_NUM)
   {
      return KAL_FALSE;
   }
   media.presilence++;
   return KAL_TRUE;
}

kal_bool Media_IsRecordTimeUp( void )
{
   if((media.uStopTime && media.recorded_time > media.uStopTime) || media.fTimeUp)
   {
      if(media.fTimeUp==KAL_FALSE)
      {
         mediaSetEvent( MEDIA_STOP_TIME_UP );
         media.fTimeUp = KAL_TRUE;
         media.waiting = KAL_TRUE;
      }
      return KAL_TRUE;
   }
   return KAL_FALSE;
}

void Media_SetRecordedStopTime( kal_uint32 uStopTime )
{
   media.uStopTime = uStopTime;
}

kal_uint32 Media_GetRecordedTime( void )
{
   if(media.recorded_time <= 0) 
      return 0;
   return media.recorded_time;      
}

kal_uint32 Media_IncRecordedTime( kal_uint32 val )
{
   media.recorded_time += val;
   return media.recorded_time;
}

void Media_SetRecordedTime( kal_uint32 val )
{
   media.recorded_time = val;
}

kal_bool Media_IsCSDMode(void)
{
   return false;
}

#ifndef __L1_STANDALONE__ // avoid link error


Media_Status amrRecordAppendable( Media_Format format, FS_HANDLE fs, Media_Record_File_Info *info )
{
#if !defined(__SMART_PHONE_MODEM__) && !defined(MED_MODEM)
   kal_uint8 AMR_Header[9];
   uint32 len;
   
   memset(info, 0, sizeof(Media_Record_File_Info));
   if (FS_NO_ERROR != FS_GetFileSize(fs, &info->fileSize) )
   {
      return MEDIA_READ_FAIL;
   }
   FS_Read(fs, AMR_Header, 9, &len);
#if defined(AMR_CODEC)   
   if(MEDIA_FORMAT_AMR == format)
   {
      if(memcmp(AMR_Header, "#!AMR\n", 6)==0)
      {
         return MEDIA_SUCCESS;
      }   
   }
#endif
#if defined( AMRWB_ENCODE )
#if defined( __I2S_INPUT_MODE_SUPPORT__ )
   if(I2S_is_I2S_open())
   {
      return MEDIA_READ_FAIL;      
   }
   else
#endif
   if(MEDIA_FORMAT_AMR_WB == format)
   {
      if(memcmp(AMR_Header, "#!AMR-WB\n", 9)==0)
      {
         return MEDIA_SUCCESS;
      }     
   }   
#endif
#endif
   return MEDIA_READ_FAIL;
}

Media_Status Media_RecordAppendable( Media_Format format, FS_HANDLE fs, Media_Record_File_Info *info )
{
   switch (format) {
#if defined(WAV_CODEC)
      case MEDIA_FORMAT_WAV:                /* linear PCM */
      case MEDIA_FORMAT_WAV_ALAW:           /* G.711 a-law */
      case MEDIA_FORMAT_WAV_ULAW:           /* g.711 mu-law */
      case MEDIA_FORMAT_WAV_DVI_ADPCM:      /* dvi/ima adpcm */
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
         return wavRecordAppendable( format, fs, info );
#endif
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_AMR_WB:
         return amrRecordAppendable( format, fs, info );
      default:
         return MEDIA_FAIL;
   }
   
   return MEDIA_FAIL;
}

Media_Status Media_Record( Media_Format format, void (*media_handler)( Media_Event event ), void *param )
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MEDIA_RECORD, format, media_handler, param, AM_IsSpeechOn(), Media_IsCSDMode(), media.waiting,0,0);
   ASSERT( media.paused == false );

#if !defined(__SMART_PHONE_MODEM__) && !defined(__L1_STANDALONE__) && defined(__AUDIO_COMPONENT_SUPPORT__) && !defined( MED_MODEM )
   MixerOut_Stop_Immediate();
#endif
   
   if( L1Audio_CheckFlag( media.aud_id ) )
      return MEDIA_REENTRY;
   if( media_handler == 0 )
      return MEDIA_NO_HANDLER;
   if( media.ctrl.rb_base == (uint16*)0 )
      return MEDIA_NOT_INITIALIZED;

   L1Audio_SetFlag( media.aud_id );

   media.media_handler = media_handler;
   media.ctrl.format = format;
   media.waiting = false;
   media.ctrl.in_speech = AM_IsSpeechOn();
   media.ctrl.CSD_Mode = Media_IsCSDMode();
   media.recorded_time = 0;
   media.presilence = 0;
   media.fTimeUp = KAL_FALSE;
//   media.recorded_time = -100; // skip five frames 

#if VERIFY_AVSYNC
   ut_a2v_record_dsp_start();
#endif
#if defined( __I2S_INPUT_MODE_SUPPORT__ )
   if(I2S_is_I2S_open())
   {
      if(MEDIA_SUCCESS != I2S_Record_Start(&media.ctrl, param ))
      {
         return MEDIA_UNSUPPORTED_TYPE;
      }
      media.recorded_time = 0;
      media.ctrl.is_I2S_input = true;
   }else
#endif
   switch( format ) {
// #if defined(__VM_CODEC_SUPPORT__) // always on
      case MEDIA_FORMAT_VRD:
         if( media.ctrl.in_speech ){
         	  L1Audio_ClearFlag( media.aud_id );
            return MEDIA_FAIL;
          }
      case MEDIA_FORMAT_GSM_FR:
         vmRecord( &media.ctrl, 0 );
         break;
      case MEDIA_FORMAT_GSM_HR:
         vmRecord( &media.ctrl, 1 );
         break;
      case MEDIA_FORMAT_GSM_EFR:
         vmRecord( &media.ctrl, 2 );
         break;
// #endif
         
#if defined(AMR_CODEC)
      case MEDIA_FORMAT_AMR:
      #ifdef PCM_EX_UNIT_TEST
         memset( (kal_uint8 *)PCM_UL_BUF, 0x0, 2560 );
         memset( (kal_uint8 *)PCM_DL_BUF, 0x0, 2560 );
         pcm_buf_rw = 0;
         if(media.ctrl.in_speech)
         {
            L1SP_EnableSpeechEnhancement(false);
            PCM4WAY_Start(pcm4way_hisrHdl,0);
            pcm_ex_test_on = 1;
         }
         else
         {
            PCM2WAY_Start(pcm2way_hisrHdl,2);
            pcm_ex_test_on = 2;
         }
         return MEDIA_SUCCESS;
      #endif

#if 1
/** For verification of AMR encoder **/
         {
            kal_uint32 bitRate;
            
            // Set the mode of AMR according to Debug Info
            bitRate = L1Audio_GetDebugInfo(AMR_REC_DEBUG_INFO);
            switch (bitRate) {
               case 4750:
                  param = (void *) 10;
                  break;
               case 5150:
                  param = (void *) 9;
                  break;
               case 5900:
                  param = (void *) 8;
                  break;
               case 6700:
                  param = (void *) 7;
                  break;
               case 7400:
                  param = (void *) 6;
                  break;
               case 7950:
                  param = (void *) 5;
                  break;
               case 10200:
                  param = (void *) 4;
                  break;
               case 12200:
                  param = (void *) 3;
                  break;
            }
         }
#endif

         {
//            ASSERT(!media.ctrl.CSD_Mode);
            if( (uint32)param >= 3 && (uint32)param <= 10 )
               amrRecord( &media.ctrl, (uint16)(uint32)param );
            else
               amrRecord( &media.ctrl, 9 ); /* 0x03 - 0x0A */
         }
         break;
#endif // #if defined(AMR_CODEC)

#if defined(WAV_CODEC)
      case MEDIA_FORMAT_PCM:
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_WAV_ALAW:
      case MEDIA_FORMAT_WAV_ULAW:
      case MEDIA_FORMAT_WAV_DVI_ADPCM:
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
         wavRecord( &media.ctrl, param );
         break;
#endif // #if defined(WAV_CODEC)

#if defined(AMRWB_ENCODE)
      case MEDIA_FORMAT_AMR_WB:
#if 1
/** For verification of AWB encoder **/
         {
            kal_uint32 bitRate;
            
            // Set the mode of AWB according to Debug Info
            bitRate  = L1Audio_GetDebugInfo(AWB_REC_DEBUG_INFO);
            switch ( bitRate ) {
               case 6600:
                  param = (void *) 0x20;
                  break;
               case 8850:
                  param = (void *) 0x21;
                  break;
               case 12650:
                  param = (void *) 0x22;
                  break;
               case 14250:
                  param = (void *) 0x23;
                  break;
               case 15850:
                  param = (void *) 0x24;
                  break;
               case 18250:
                  param = (void *) 0x25;
                  break;
               case 19850:
                  param = (void *) 0x26;
                  break;
               case 23050:
                  param = (void *) 0x27;
                  break;
               case 23850:
                  param = (void *) 0x28;
                  break;
            }
         }
#endif

         ASSERT(!media.ctrl.in_speech);
         if( (uint32)param >= 0x20 && (uint32)param <= 0x28 )/* 0x20 - 0x28 */
            amrRecord( &media.ctrl, (uint16)(uint32)param );
         else
            amrRecord( &media.ctrl, 0x20 ); 
         break;
#endif

#if defined(__VOIP__)
      case MEDIA_FORMAT_VOIPEVL:
         VoIPevRecord( &media.ctrl );
         break;
#endif
#if defined(__VORBIS_ENCODE__)
      case MEDIA_FORMAT_VORBIS:
         VorbisEnc_Record( &media.ctrl );
         break;
#endif
      default:
      	 L1Audio_ClearFlag( media.aud_id );
         return MEDIA_BAD_FORMAT;
   }
   return MEDIA_SUCCESS;
}
#endif

#if defined(__DUAL_MIC_SUPPORT__)
kal_uint32 Media_GetRecordDataRate(Media_Format format, void *param)
{
	switch(format)
	{
		case MEDIA_FORMAT_GSM_FR:
			 return (L1Audio_GetDebugInfo(STEREO_RECORD_INFO) & 1) ? 128000  : 64000;
	    case MEDIA_FORMAT_GSM_HR:
			 return (L1Audio_GetDebugInfo(STEREO_RECORD_INFO) & 1) ? 64000  : 32000;
   		default:
   			return 0;
	}	
}
#endif
#ifndef __L1_STANDALONE__ // avoid link error
Media_Status Media_Pause( void )
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MEDIA_PAUSE, 0, 0, 0, 0 ,0 ,0);
   if( !L1Audio_CheckFlag( media.aud_id ) )
      return MEDIA_FAIL;

   media.paused = true;
#if defined( __I2S_INPUT_MODE_SUPPORT__ )
   if(media.ctrl.is_I2S_input)
   {
      I2S_Record_Pause();
   } else
#endif
   switch( media.ctrl.format ) {
#if defined(WAV_CODEC)
      case MEDIA_FORMAT_PCM:
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_WAV_ALAW:
      case MEDIA_FORMAT_WAV_ULAW:
      case MEDIA_FORMAT_WAV_DVI_ADPCM:
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
         wavPause( &media.ctrl );
         break;
#endif //#if defined(WAV_CODEC)
         
// #if defined(__VM_CODEC_SUPPORT__) // always on
      case MEDIA_FORMAT_VRD:
      case MEDIA_FORMAT_GSM_FR:
      case MEDIA_FORMAT_GSM_HR:
      case MEDIA_FORMAT_GSM_EFR:
         vmPause( &media.ctrl );
         break;
// #endif
         
#if defined(AMR_CODEC)
      case MEDIA_FORMAT_AMR:
         amrPause( &media.ctrl );
         break;

#if defined(AMRWB_DECODE) || defined(AMRWB_ENCODE)
      case MEDIA_FORMAT_AMR_WB:
         amrPause( &media.ctrl );
         break;
#endif
#endif //  defined(AMR_CODEC)

      case MEDIA_FORMAT_SMF:
         break;
      case MEDIA_FORMAT_IMELODY:
         break;
      case MEDIA_FORMAT_MMF:
         break;
#if defined(__VOIP__)
      case MEDIA_FORMAT_VOIPEVL:
         VoIPevPause();
         break;
#endif
#if defined(__VORBIS_ENCODE__)
      case MEDIA_FORMAT_VORBIS:
         VorbisEnc_Pause();
         break;
#endif
      default:
         ASSERT(KAL_FALSE);
   }
   
#if VERIFY_DATA_TO_DSP
   VERIFY_DATA_TO_DSP_STOP();
#endif

   L1Audio_ClearFlag( media.aud_id );

   return MEDIA_SUCCESS;
}
#endif

#ifndef __L1_STANDALONE__ // avoid link error
Media_Status Media_Resume( void )
{
#if !defined(__SMART_PHONE_MODEM__) && !defined(__L1_STANDALONE__) && defined(__AUDIO_COMPONENT_SUPPORT__) && !defined( MED_MODEM )
   MixerOut_Stop_Immediate();
#endif
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MEDIA_RESUME, media.paused, 0, 0, 0 ,0,0);
   if( L1Audio_CheckFlag( media.aud_id ) )
      return MEDIA_FAIL;

   ASSERT( media.paused == true );
   media.paused = false;
   media.waiting = false;
   media.presilence = 0;
   media.fTimeUp = KAL_FALSE;
   
   L1Audio_SetFlag( media.aud_id );

#if VERIFY_DATA_TO_DSP
   VERIFY_DATA_TO_DSP_RESUME();
#endif
#if defined( __I2S_INPUT_MODE_SUPPORT__ )
   if(media.ctrl.is_I2S_input)
   {
      I2S_Record_Resume();
   } else
#endif
   switch( media.ctrl.format ) {
#if defined(WAV_CODEC)
      case MEDIA_FORMAT_PCM:
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_WAV_ALAW:
      case MEDIA_FORMAT_WAV_ULAW:
      case MEDIA_FORMAT_WAV_DVI_ADPCM:
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
         wavResume( &media.ctrl );
         break;
#endif // #if defined(WAV_CODEC)

// #if defined(__VM_CODEC_SUPPORT__)
      case MEDIA_FORMAT_VRD:
      case MEDIA_FORMAT_GSM_FR:
      case MEDIA_FORMAT_GSM_HR:
      case MEDIA_FORMAT_GSM_EFR:
         vmResume( &media.ctrl );
         break;
// #endif // always on

#if defined(AMR_CODEC)
      case MEDIA_FORMAT_AMR:
         {
            amrResume( &media.ctrl );
         }
         break;
#endif   // #if defined(AMR_CODEC)

#if defined(AMRWB_DECODE) || defined(AMRWB_ENCODE)
      case MEDIA_FORMAT_AMR_WB:
         amrResume( &media.ctrl );
         break;
#endif

      case MEDIA_FORMAT_SMF:
         break;
      case MEDIA_FORMAT_IMELODY:
         break;
      case MEDIA_FORMAT_MMF:
         break;
#if defined(__VOIP__)
      case MEDIA_FORMAT_VOIPEVL:
         VoIPevResume();
         break;
#endif
#if defined(__VORBIS_ENCODE__)
      case MEDIA_FORMAT_VORBIS:
         VorbisEnc_Resume();
         break;
#endif
      default:
         ASSERT(KAL_FALSE);
  }
  return MEDIA_SUCCESS;
}
#endif

#ifndef __L1_STANDALONE__ // avoid link error
void Media_Stop( void )
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MEDIA_STOP, media.paused, media.waiting, media.ctrl.is_I2S_input, 0,0,0);
   if( media.paused == true ) {
   	  bool check;
   	  check = L1Audio_CheckFlag( media.aud_id );
      ASSERT( !check );
      L1Audio_SetFlag( media.aud_id );
      media.paused = false;
   }
   media.uStopTime = 0;

   if( !L1Audio_CheckFlag( media.aud_id ) )
      return;

#if VERIFY_AVSYNC
   ut_a2v_dsp_stop();
#endif

   media.waiting = true;      /* Forbid data request */
#if defined( __I2S_INPUT_MODE_SUPPORT__ )
   if(I2S_is_I2S_open())
   {
      media.waiting = false;      /* Forbid data request */
      I2S_Record_Stop();
      media.waiting = true;      /* Forbid data request */
      media.ctrl.is_I2S_input = false;
   } else
#endif
   switch( media.ctrl.format ) {
// #if defined(__VM_CODEC_SUPPORT__) //always on
      case MEDIA_FORMAT_VRD:
      case MEDIA_FORMAT_GSM_FR:
      case MEDIA_FORMAT_GSM_HR:
      case MEDIA_FORMAT_GSM_EFR:
      case MEDIA_FORMAT_VRSI:
         vmStop();
         break;
// #endif
#if defined(AMR_CODEC)
      case MEDIA_FORMAT_AMR:
         amrStop();
         break;
#endif  // #if defined(AMR_CODEC)

#if defined(AMRWB_DECODE) || defined(AMRWB_ENCODE)
      case MEDIA_FORMAT_AMR_WB:
         amrStop();
         break;
#endif

#if defined(WAV_CODEC)
      case MEDIA_FORMAT_PCM:
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_WAV_ALAW:
      case MEDIA_FORMAT_WAV_ULAW:
      case MEDIA_FORMAT_WAV_DVI_ADPCM:
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
         wavStop();
         break;
#endif // #if defined(WAV_CODEC)

      case MEDIA_FORMAT_SMF:
         break;
      case MEDIA_FORMAT_IMELODY:
         break;
      case MEDIA_FORMAT_MMF:
         break;
#if defined(__VOIP__)
      case MEDIA_FORMAT_VOIPEVL:
         VoIPevStop();
         break;
#endif
#if defined(__VORBIS_ENCODE__)
      case MEDIA_FORMAT_VORBIS:
         VorbisEnc_Stop();
         break;
#endif
      default:
         ASSERT(KAL_FALSE);
   }
#if VERIFY_DATA_TO_DSP
   VERIFY_DATA_TO_DSP_STOP();
#endif

   L1Audio_ClearFlag( media.aud_id );
   
   Media_SetRBOffset(0);
}
#endif

Media_Status Media_Control( Media_Ctrl ctrl_no, int32 ctrl_val )
{
   switch( ctrl_no ) {
   case MEDIA_CTRL_MAX_SWING:
      return MEDIA_BAD_COMMAND;
      case MEDIA_CTRL_KEY_SHIFT:
         return MEDIA_BAD_COMMAND;
      default:
         return MEDIA_BAD_COMMAND;
   }
}


void Media_SetMelodyFilter( uint16 len, const int16 *filter )
{      
}

void Media_SetUserData(Media_Handle *hdl, void* pAppData)
{
   hdl->pApplicateData = pAppData;
}

void Media_GetUserData(Media_Handle *hdl, void** pAppData)
{
   *pAppData = hdl->pApplicateData;
}

Media_Status Media_SetLevel( kal_uint8 level )
{
   media.ctrl.level = level;
   if( !L1Audio_CheckFlag( media.aud_id ) )
      return MEDIA_SUCCESS;
   switch( media.ctrl.format ) {
#if defined(AMR_CODEC)
      case MEDIA_FORMAT_AMR:
         amrUpdateLevel();
         break;
#endif
#if defined(WAV_CODEC)
      case MEDIA_FORMAT_WAV:
         wavUpdateLevel();
         break;
#endif

#if defined(AMRWB_DECODE) || defined(AMRWB_ENCODE)
      case MEDIA_FORMAT_AMR_WB:
         amrUpdateLevel();
         break;
#endif

      default:
         ASSERT(KAL_FALSE);
   }

   return MEDIA_SUCCESS;
}

kal_uint8 Media_GetLevel( void )
{
   return media.ctrl.level;
}

void Media_MuteSpeaker( bool mute )
{
   AFE_MuteSpeaker( L1SP_AUDIO, mute );
   AFE_MuteSpeaker( L1SP_VOICE, mute );
}

/* ------------------------------------------------------------------------------ */
void mediaHandler( void *data )     /* This function works in L1Audio Task */
{
   Media_Event event = (Media_Event)(int32)data;

   if( event == MEDIA_TERMINATED || !L1Audio_CheckFlag( media.aud_id ))      /* MEDIA_TERMINATED is no longer used */
      return;
   if( event == MEDIA_END || event == MEDIA_ERROR ) {
      L1Audio_ClearFlag( media.aud_id );
      media.waiting = false;
   }
   media.media_handler( event );
}
/* ------------------------------------------------------------------------------ */
#if defined(WAV_CODEC) || defined(AAC_PLUS_PS_DECODE) || defined(AWB_PLUS_DECODE)
kal_semid  WAVsema;
#endif

void mediaInit( uint16 aud_id )
{
#if defined(WAV_CODEC) || defined(AAC_PLUS_PS_DECODE) || defined(AWB_PLUS_DECODE)
   WAVsema = kal_create_sem( "wav_sema", 1 );
#endif
   media.aud_id = aud_id;
   L1Audio_SetEventHandler( media.aud_id, mediaHandler );

#if defined(WAV_CODEC)
   wavInit( L1Audio_GetAudioID() );
#endif

#if defined(__VORBIS_ENCODE__)
   VorbisEnc_Init();
#endif

#if defined(__VOIP__)
   VoIPevInit();
#endif


   media.ctrl.rb_threshold = MEDIA_RB_DEFAULT_THRESHOLD;
   media.ctrl.max_swing = (int32)Media_Playback_Maximum_Swing >> 3;
   media.ctrl.key_shift = 0;
   media.ctrl.level = 100;
   media.ctrl.rb_base = (uint16*)0;
   media.uStopTime = 0;
   media.fTimeUp = KAL_FALSE;
}

/* If the event is MEDIA_END or MEDIA_ERROR, make sure DSP has been stopped
   before calling this function. Refer to the function: mediaHandler */
void mediaSetEvent( Media_Event event )
{
   L1Audio_SetEvent( media.aud_id, (void *)event );
}

bool mediaKeytoneForbidden( void )
{
   return false;
}

void Media_SetRBThreshold( uint16 threshold )
{
   media.ctrl.rb_threshold = threshold;
}

void Media_SetRBOffset( kal_uint32 uOffset )
{
   ASSERT( uOffset < media.ctrl.rb_size);

   media.ctrl.uOffset = uOffset;
}

#ifndef __L1_STANDALONE__ // avoid link error

#if defined(AAC_DECODE)

#define AAC_ADTS_LENGTH 7
static const kal_uint8 AAC_Header[AAC_ADTS_LENGTH] = { 0xFF, 0xF9, 0x40, 0x20, 0x00, 0x1F, 0xFC };

#endif


void rbGetWriteBuffer( AUD_RB_INFO *rb, kal_uint8 **buffer, kal_uint32 *buf_len )// in bytes
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

void rbGetReadBuffer( AUD_RB_INFO *rb, kal_uint8 **buffer, kal_uint32 *buf_len )// in bytes
{
   int32 count;

   if( rb->write >= rb->read )
      count = rb->write - rb->read;
   else
      count = rb->rb_size - rb->read;

   ASSERT( count>=0 );
   *buffer = (uint8 *)&rb->rb_base[rb->read];
   *buf_len = count;
}

void rbReadDataDone( AUD_RB_INFO *rb, kal_uint32 len ) // in bytes
{
   rb->read += len;

   ASSERT(rb->read <= rb->rb_size);
   if( rb->read == rb->rb_size )
      rb->read = 0;

   kal_brief_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_READ_BYTE, len );
}


void rbWriteDataDone( AUD_RB_INFO *rb, kal_uint32 len ) // in bytes
{
   rb->write += len;

   ASSERT(rb->write <= rb->rb_size);
   if( rb->write == rb->rb_size )
      rb->write = 0;
}

int32 rbGetFreeSpace( AUD_RB_INFO *rb )
{
   int32 count;

   count = rb->read - rb->write - 1;
   if( count < 0 )
      count += rb->rb_size;
   return count; // free size in byte
}

int32 rbGetDataCount( AUD_RB_INFO *rb )
{
   return rb->rb_size - rbGetFreeSpace(rb) - 1;
}

static void mhdlSetBuffer( MHdl *hdl, kal_uint8 *buffer, kal_uint32 buf_len )
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_SET_BUFFER, buffer, buf_len, hdl,0,0,0,0);
   hdl->rbInfo.rb_base = buffer;
   hdl->rbInfo.rb_size = buf_len;
   hdl->rbInfo.write = 0;
   hdl->rbInfo.read = 0;
   hdl->eof = false;
   hdl->waiting = false;
}

static void mhdlGetWriteBuffer( MHdl *hdl, kal_uint8 **buffer, kal_uint32 *buf_len )// in bytes
{
   rbGetWriteBuffer(&hdl->rbInfo, buffer, buf_len);
}

static void mhdlGetReadBuffer( MHdl *hdl, kal_uint8 **buffer, kal_uint32 *buf_len )// in bytes
{
   rbGetReadBuffer(&hdl->rbInfo, buffer, buf_len);
}

static Media_Status mhdlSetLevel( MHdl *hdl, kal_uint8 level )
{
   ASSERT( level <= 100 );
   hdl->volume_level = level;
   AFE_SetDigitalGain( L1SP_AUDIO, level );
   AFE_SetDigitalGain( L1SP_VOICE, level );
   return MEDIA_SUCCESS;
}

static void mhdlWriteDataDone( MHdl *hdl, kal_uint32 len ) // in bytes
{
   kal_brief_trace (TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_WRITE_DATA_DONE, hdl, len,0,0,0,0);
   rbWriteDataDone(&hdl->rbInfo, len);
   hdl->isUnderflow = KAL_FALSE;
}

static void mhdlReadDataDone( MHdl *hdl, kal_uint32 len ) // in bytes
{
   rbReadDataDone(&hdl->rbInfo, len);
}

static void mhdlDataFinished( MHdl *hdl )
{
   kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_DATA_FINISH, hdl, hdl->mediaType,0,0,0,0);
   hdl->eof = true;
}

static void mhdlFinishWriteData( MHdl *hdl )
{
   kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_FINISH_WRITE_DATA, hdl, hdl->mediaType,hdl->waiting,hdl->isUnderflow,0,0);
   hdl->waiting = KAL_FALSE;
   hdl->isUnderflow = KAL_FALSE;  
   hdl->bReadingData = KAL_FALSE;   
}

static void mhdlResetMediaBuf( MHdl *hdl )
{
   hdl->rbInfo.write = 0;
   hdl->rbInfo.read = 0;
   hdl->eof = false;
   hdl->waiting = false;
}
static kal_uint8 mhdlGetLevel( MHdl *hdl )
{
   return hdl->volume_level;
}

static Media_Status mhdlSetStartTime( MHdl *hdl, kal_uint32 msStartTime )
{
   hdl->start_time = msStartTime;
   hdl->uSeekProgress = 0;
   hdl->uCurSeekFrm = 0;
   hdl->bIsPause = KAL_FALSE; 
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_SET_START_TIME, hdl->mediaType, msStartTime,0,0,0,0);
   return MEDIA_SUCCESS;
}

static Media_Status mhdlSetStopTime( MHdl *hdl, kal_uint32 msStopTime )
{
   hdl->stop_time = msStopTime;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_SET_STOP_TIME, hdl->mediaType, msStopTime,0,0,0,0);
   return MEDIA_SUCCESS;
}

static void mhdlSetStoreFlag( MHdl *hdl, kal_bool fStoreLastFileOffset )
{
   hdl->fStoreFileOffset = fStoreLastFileOffset;
}

static void mhdlStoreFileOffset(MHdl *hdl)
{
   audResumeInfo.uResumeFrameOffset = audResumeInfo.uCurOffset;
}

static kal_uint32 mhdlGetFileOffset(MHdl *hdl)
{
   return audResumeInfo.uCurOffset;
}

static void mhdlSetFileOffset( MHdl *hdl, kal_uint32 uCurOffset)
{
   audResumeInfo.uResumeFrameOffset = uCurOffset;
}

static kal_uint32 mhdlGetCurrentTime( MHdl *hdl )
{
   kal_uint32 uTSTime = 0;
   FC_Buf *fcBufHdr = (FC_Buf *)hdl->rbInfo.param;
   hdl->fStoreFileOffset = false;
   
   if (fcBufHdr != NULL)
   {
      hdl->current_time = fcBufHdr->uTime;
   }

#if defined(__BES_TS_SUPPORT__)
   uTSTime = AudioDrain_GetCurrentTimeFromTS();
#endif

   kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_CURRENT_TIME, hdl->mediaType, hdl->current_time, hdl->start_time,uTSTime,0,0,0);
   if(uTSTime)
   {
      hdl->current_time = hdl->start_time+uTSTime;
   }

   if (hdl->current_time < hdl->start_time)
      return hdl->start_time;
   else
      return hdl->current_time;

}

static kal_uint32 mhdlGetTotalDuration( MHdl *hdl )
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_TOTAL_DUR_NONAST, hdl->uTotalDuration, hdl, 0,0,0,0);
   return hdl->uTotalDuration;
}

static int32 mhdlGetFreeSpace( MHdl *hdl )
{
   int32 count;

   count = hdl->rbInfo.read - hdl->rbInfo.write - 1;
   if( count < 0 )
      count += hdl->rbInfo.rb_size;
   return count; // free size in byte
}

static int32 mhdlGetDataCount( MHdl *hdl )
{
   return hdl->rbInfo.rb_size - mhdlGetFreeSpace(hdl) - 1;
}

static void mhdlCallbackTask( void *data )
{
   MHdl *hdl = (MHdl *)data;
   hdl->handler( hdl, (Media_Event)hdl->data );
}

void mhdlEndHandler( void *data, Media_Event event )
{
    MHdl *hdl;
    
    hdl = (MHdl *) data;
    hdl->data = (uint32)event;
    hdl->handler( hdl, (Media_Event)hdl->data );
}


// to sync with FD216 component application
void mhdlExceptionComp2( MHdl *hdl, Media_Event event )
{
   mhdlException( hdl, event );
}


void mhdlException( MHdl *hdl, Media_Event event )
{
   kal_brief_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_MHDL_EXCEPTION, hdl->mediaType, event,0,0,0,0);
   hdl->data = (uint32)event;
   hdl->handler( hdl, (Media_Event)hdl->data );
}


void mhdlAllowSleep( MHdl *hdl )
{
   L1Audio_ClearFlag( hdl->aud_id );
   ktUnlock();
}

void mhdlAllowSleep_Id( kal_uint32 aud_id )
{
   L1Audio_ClearFlag( aud_id );
   ktUnlock();
}

void mhdlDisallowSleep( MHdl *hdl )
{
   L1Audio_SetFlag( hdl->aud_id ); // disable sleep mode
   ktLock();
}

void mhdlDisallowSleep_Id( kal_uint32 aud_id )
{
   L1Audio_SetFlag( aud_id ); // disable sleep mode
   ktLock();
}

static void mhdlDataRequestInternal( MHdl *hdl, Media_Event end_status, Media_Event event)
{
   kal_uint32 data_count;
   kal_uint32 free_space;

   kal_brief_trace ( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_DATA_REQUEST, hdl->waiting, hdl->eof, hdl->DataRequestThreshold, hdl->GetFreeSpace(hdl),0,0,0,0);

   if (hdl->waiting)
   {
      return;
   }
   
   if (end_status != MEDIA_UPDATE_DUR)
   {
      if ( hdl->eof || (end_status == MEDIA_END) )
         return;
   }

   data_count = hdl->GetDataCount(hdl);
   free_space = hdl->GetFreeSpace(hdl);

   if(  (hdl->DataRequestMode==MEDIA_FREE_SPACE_MODE && (free_space > hdl->DataRequestThreshold))
      ||(data_count<MEDIA_MIN_DATA_THRESHOLD))
   {
      mhdlException( hdl, event );
      hdl->waiting = true;
   }
   else if(hdl->DataRequestMode==MEDIA_DATA_COMSUME_MODE)
   {
      if(hdl->rbInfo.read > hdl->LastRingBufferRead)
      {
         if(hdl->rbInfo.read - hdl->LastRingBufferRead > hdl->DataRequestThreshold)
         {
            mhdlException( hdl, event );
            hdl->waiting = true;
            hdl->LastRingBufferRead = hdl->rbInfo.read; 
         }
      }
      else 
      {
         if(hdl->rbInfo.read + hdl->rbInfo.rb_size - hdl->LastRingBufferRead > hdl->DataRequestThreshold)
         {
            mhdlException( hdl, event );
            hdl->waiting = true;
            hdl->LastRingBufferRead = hdl->rbInfo.read; 
         }
      }
   }
}

void mhdlDataRequest( MHdl *hdl, Media_Event end_status)
{
   mhdlDataRequestInternal(hdl, end_status, MEDIA_DATA_REQUEST);
}

void mhdlDataRequestNone( MHdl *hdl, Media_Event end_status)
{
   mhdlDataRequestInternal(hdl, end_status, MEDIA_NONE);
}

void mhdlDataNotification( MHdl *hdl )
{
   if( hdl->waiting )
      return;

   if( hdl->GetDataCount(hdl) >= (MEDIA_RB_DEFAULT_THRESHOLD << 2) ) {
      mhdlException( hdl, MEDIA_DATA_NOTIFICATION );
      hdl->waiting = true;
   }
}

static void mhdlSetUserData( MHdl *hdl, void* pAppData)
{
   hdl->pApplicateData = pAppData;
}

static void mhdlGetUserData( MHdl *hdl, void** pAppData)
{
   *pAppData = hdl->pApplicateData;
}

static Media_Status mhdlReachValidRegion( MHdl *hdl )
{
   return MEDIA_SUCCESS;
}

static void mhdlBuildCache( MHdl *hdl, Media_Status *eLastRet, kal_uint32 *uProgress )
{
	*eLastRet = MEDIA_SUCCESS;
	*uProgress=100;
}

static void mhdlSetCacheTbl( MHdl *hdl, kal_uint8 *ptr, kal_uint32 usize )
{
}

static kal_uint32 mhdlGetCacheDur(MHdl *hdl)
{
   return hdl->uTotalDuration;
}

static void mhdlSetDataRequestThreshold(MHdl *hdl, Media_Buffer_Mode mode, kal_uint32 threshold, void* param)
{
   hdl->DataRequestThreshold = threshold;
   hdl->DataRequestMode = mode;
}

static void mhdlSetBufferInternal(MHdl *hdl , kal_uint32 uSize)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_SET_BUFFER_INTERNAL, hdl, hdl->rbInfo.rb_base, hdl->isAllocRingBuffer,uSize,0,0);
   if(hdl->rbInfo.rb_base == NULL)
   {
      hdl->rbInfo.rb_base = (kal_uint8 *)audio_alloc_mem_cacheable( uSize * sizeof(kal_uint8) );
      ASSERT(hdl->rbInfo.rb_base);
      hdl->rbInfo.rb_size = uSize;
      hdl->isAllocRingBuffer = KAL_TRUE;
      mhdlResetMediaBuf(hdl);
   }
}

static void mhdlFreeBufferInternal(MHdl *hdl)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_FREE_BUFFER_INTERNAL, hdl, hdl->rbInfo.rb_base, hdl->isAllocRingBuffer,0,0,0);
   if(hdl->isAllocRingBuffer)
   {
      ASSERT(hdl->rbInfo.rb_base);
      audio_free_mem( (void **) &hdl->rbInfo.rb_base ); 
      hdl->rbInfo.rb_base = NULL;
      hdl->rbInfo.rb_size = 0;
      hdl->isAllocRingBuffer = KAL_FALSE;
   }
}

void mhdlInitEx( MHdl *hdl, uint32 hisrMagic, void hisrHdlr( void *data ) )
{
   ASSERT(hdl);

   memset(hdl, 0, sizeof(MHdl));
   hdl->stop_time = 0xFFFFFFFF;

   hdl->SetBufferInternal = mhdlSetBufferInternal;
   hdl->FreeBufferInternal = mhdlFreeBufferInternal;
   hdl->SetBuffer = mhdlSetBuffer;
   hdl->GetWriteBuffer = mhdlGetWriteBuffer;
   hdl->GetReadBuffer = mhdlGetReadBuffer;
   hdl->WriteDataDone = mhdlWriteDataDone;
   hdl->FinishWriteData = mhdlFinishWriteData;
   hdl->ResetMediaBuf = mhdlResetMediaBuf;
   hdl->ReadDataDone = mhdlReadDataDone;
   hdl->DataFinished = mhdlDataFinished;
   hdl->GetFreeSpace = mhdlGetFreeSpace;
   hdl->GetDataCount = mhdlGetDataCount;
   hdl->SetLevel = mhdlSetLevel;
   hdl->GetLevel = mhdlGetLevel;
   hdl->SetStartTime = mhdlSetStartTime;
   hdl->SetStopTime = mhdlSetStopTime;
   hdl->GetCurrentTime = mhdlGetCurrentTime;
   hdl->GetTotalDuration = mhdlGetTotalDuration;
   hdl->SetStoreFlag = mhdlSetStoreFlag;
   hdl->StoreFileOffset = mhdlStoreFileOffset;
   hdl->GetFileOffset = mhdlGetFileOffset;
   hdl->SetFileOffset = mhdlSetFileOffset;
   hdl->ReachValidRegion = mhdlReachValidRegion;
   hdl->SetUserData = mhdlSetUserData;
   hdl->GetUserData = mhdlGetUserData;
   hdl->BuildCache  = mhdlBuildCache;
   hdl->SetCacheTbl = mhdlSetCacheTbl;
   hdl->GetCacheDuration = mhdlGetCacheDur;
   hdl->SetDataRequestThreshold = mhdlSetDataRequestThreshold;
   hdl->DataRequestThreshold = MEDIA_RB_DEFAULT_THRESHOLD << 2;
   hdl->DataRequestMode = MEDIA_FREE_SPACE_MODE;
}

void mhdlInit( MHdl *hdl, uint32 hisrMagic, void hisrHdlr( void *data ) )
{
   mhdlInitEx( hdl, hisrMagic, hisrHdlr );

   if(0xFFFF != hisrMagic){
      mhdlSetLevel( hdl, 100 );
      hdl->aud_id = L1Audio_GetAudioID();
      L1Audio_SetEventHandler( hdl->aud_id, mhdlCallbackTask );
   }
}

void mhdlFinalize( MHdl *hdl, uint32 hisrMagic )
{

}

#if !defined(__SMART_PHONE_MODEM__) && !defined(MED_MODEM)

kal_uint8 autGetBitsFromBuf(kal_uint8 *pBuf, kal_uint32 *puBitCnt, kal_uint32 uBitLen)
{
	static kal_uint8 bCurByte;
	kal_uint8 bMask;
	kal_uint32 uCurBitPos;
	kal_uint8 bValue;

   ASSERT(puBitCnt!=NULL);
	ASSERT(uBitLen>=1 && uBitLen<=8);

	uCurBitPos = *puBitCnt % 8;

	if(uCurBitPos==0) {
	   bCurByte = pBuf[*puBitCnt/8];
	}

	*puBitCnt += uBitLen;

	if(uCurBitPos+uBitLen<=8) {
		bMask = (unsigned char)((1 << (8-uCurBitPos)) - 1);
		bValue = (unsigned char)((bCurByte&bMask) >> (8-(uCurBitPos+uBitLen)));
	} else {
		bMask = (unsigned char)((1 << (8-uCurBitPos)) - 1);
		bValue = (unsigned char)((bCurByte&bMask) << (uBitLen-(8-uCurBitPos)));
		bCurByte = pBuf[*puBitCnt/8];
		bValue |= bCurByte>>(16-uBitLen-uCurBitPos);
	}
	return bValue;
}

#if !defined(MED_NOT_PRESENT)
static kal_int32 autGetBytesFromFileGeneral(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 fileOffset, kal_uint32 num_bytes, kal_uint8 *ptr, kal_uint32 method)
{
   kal_uint32 file_size, data_size;
   {
      FSAL_GetFileSize(pstFSAL, &file_size);
      data_size = file_size - fileOffset;
      
      if(data_size <= num_bytes){  // EOF
         num_bytes = data_size;
         if (method == 0)
            hdl->DataFinished(hdl);
      }
      
      FSAL_Seek( pstFSAL, fileOffset);
      if(FSAL_Read_Bytes( pstFSAL, ptr, num_bytes) != FSAL_OK)
         return -1; // Playback should be terminated
   }

   return num_bytes;
}


kal_int32 autGetBytesFromFile(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 fileOffset, kal_uint32 num_bytes, kal_uint8 *ptr)
{
   return autGetBytesFromFileGeneral(hdl, pstFSAL, fileOffset, num_bytes, ptr, 0);
}

kal_int32 autGetBytesFromFileNoEnd(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 fileOffset, kal_uint32 num_bytes, kal_uint8 *ptr)
{
   return autGetBytesFromFileGeneral(hdl, pstFSAL, fileOffset, num_bytes, ptr, 1);
}
#endif
#if !defined(MED_NOT_PRESENT)
#if !defined(FSAL_GetCurPos)
kal_int32 autGetBytes(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 uLen, kal_uint8 *pbBuf)
{
   kal_uint32 uDataSize, uFileSize, uCurPos;

   if(uLen == 0) return 0;
   FSAL_GetCurPos(pstFSAL, &uCurPos);
   FSAL_GetFileSize(pstFSAL, &uFileSize);
   uDataSize = uFileSize - uCurPos;

   if(uDataSize <= uLen){
      uLen = uDataSize;
      hdl->DataFinished(hdl);
   }
   if(uLen == 0) return 0;

   if(FSAL_Read_Bytes( pstFSAL, pbBuf, uLen) != FSAL_OK)
      return -1;

   return uLen;
}
#endif
#endif

#if !defined(MED_NOT_PRESENT)
void autSkipID3Tag( MHdl *hdl, STFSAL *pstFSAL, kal_uint32 *fileOffset, kal_uint8 *ptr )
{
   kal_uint32 num_bytes, file_size, tagsize;

   while(1){
      tagsize = 0;
      num_bytes = autGetBytesFromFile(hdl, pstFSAL, *fileOffset, ID3V2_HEADER_LEN, ptr);
      if(num_bytes != ID3V2_HEADER_LEN) return;
      
      if (kal_mem_cmp(ptr, "ID3", 3) == 0)
	   {
         tagsize = (ptr[6] << 21) | (ptr[7] << 14) |
               (ptr[8] <<  7) | (ptr[9] <<  0);
      
         FSAL_GetFileSize(pstFSAL, &file_size);
         if(file_size >= (tagsize + 10)){ // Don't skip ID3 tag if tagsize is invalid
            *fileOffset += (tagsize+10);            
         }else{
             return;
          }
         
      }else
         return;
   }
}
#endif

#if !defined(MED_NOT_PRESENT)
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
#endif
#endif

#if !defined(MED_NOT_PRESENT)
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
#endif
#endif

#endif /* #if !defined(__SMART_PHONE_MODEM__) */

#endif // #ifndef __L1_STANDALONE__
/* ------------------------------------------------------------------------------ */


//---------------------------------------------

#if defined(AMR_CODEC)
static const kal_uint8 AMR_FileHeader[6] = { 0x23, 0x21, 0x41, 0x4D, 0x52, 0x0A};
#endif
#if defined(AMRWB_DECODE)
static const kal_uint8 AWB_FileHeader[9] = { 0x23, 0x21, 0x41, 0x4D, 0x52, 0x2D, 0x57, 0x42, 0x0A};
#endif

#if !defined(MED_NOT_PRESENT)
Media_Status Media_GetSilenceFormat(
   Media_Format uFormat,
   kal_uint32 *uChannelNum,
   kal_uint32 *uSampleRate,
   kal_uint8 *pBuf, 
   kal_uint32 uBufLen
)
{
   switch (uFormat) 
   {
#if defined(AMR_CODEC)
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_MP4_AMR:
      {
         *uSampleRate = 8000;
         *uChannelNum = 1;
         break;
      }
#endif
#if defined(AMRWB_DECODE)
      case MEDIA_FORMAT_AMR_WB:
      case MEDIA_FORMAT_MP4_AMR_WB:
      {
         *uSampleRate = 16000;
         *uChannelNum = 1;
         break;
      }
#endif
#if defined(__DRA_DECODE_SUPPORT__)
      case MEDIA_FORMAT_DRA:
      {
         kal_uint32 uSampleRateIndex;
         
         uSampleRateIndex = ((pBuf[3] & 0x7)<<1) | (pBuf[4]>>7);
         if (uSampleRateIndex == 6)
            *uSampleRate = 32000;
         else if (uSampleRateIndex == 7)
            *uSampleRate = 44100;
         else if (uSampleRateIndex == 8)
            *uSampleRate = 48000;
         else
            *uSampleRate = 0;
         
         if (pBuf[4] & 0x1)
            *uChannelNum = 2;
         else
            *uChannelNum = 1;
      }
      break;
#endif
#if defined(AAC_DECODE)
      case MEDIA_FORMAT_AAC:
      case MEDIA_FORMAT_MP4_AAC:
      case MEDIA_FORMAT_AAC_PLUS:
      case MEDIA_FORMAT_AAC_PLUS_V2:
      {
         if(uBufLen==0)
         {
            return MEDIA_FAIL;
         }
         AAC_GetMediaFormat_Detail_v2(pBuf, uBufLen, uChannelNum, uSampleRate);
         break;
      }
#endif
      default:
         return MEDIA_FAIL;
   }
   return MEDIA_SUCCESS;
}
#endif

Media_Status Media_GetFileHeaderLength(
   Media_Format format,
   kal_uint32 channelNum,
   kal_uint32 freq,
   kal_uint32 subframeNum,
   kal_uint32 *len
)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_HEADER, format, channelNum, freq, subframeNum,0,0,0,0);
   *len = 0;
   switch (format) 
   {
#if defined(AMR_CODEC)
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_MP4_AMR:
         *len = 6;
         break;
#endif
#if defined(AMRWB_DECODE)
      case MEDIA_FORMAT_AMR_WB:
      case MEDIA_FORMAT_MP4_AMR_WB:
         *len = 9;
         break;
#endif
      default:
         break;
   }
   return MEDIA_SUCCESS;
}

Media_Status Media_GetFileHeaderPattern(Media_Format format, kal_uint32 channelNum, kal_uint32 freq, kal_uint32 subframeNum, kal_uint8 *pattern)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_HEADER, format, channelNum, freq, subframeNum,0,0,0,0);
   switch (format) 
   {
#if defined(AMR_CODEC)
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_MP4_AMR:
         memcpy(pattern, AMR_FileHeader, 6);
         break;
#endif
#if defined(AMRWB_DECODE)
      case MEDIA_FORMAT_AMR_WB:
      case MEDIA_FORMAT_MP4_AMR_WB:
         memcpy(pattern, AWB_FileHeader, 9);
         break;
#endif
      default:
         break;
   }
   return MEDIA_SUCCESS;
}

Media_Status Media_GetSilenceLength(Media_Format format, kal_uint32 channelNum, kal_uint32 freq, kal_uint32 subframeNum, kal_uint32 *len)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_SILENCE, format, channelNum, freq, subframeNum,0,0,0,0);
   *len = 0;
   switch (format) 
   {
#if defined(__COOK_DECODE__)
      case MEDIA_FORMAT_COOK:
         *len = 4;
         break;
#endif
#if defined(AMR_CODEC) || defined(AMRWB_DECODE)
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_AMR_WB:
      case MEDIA_FORMAT_MP4_AMR:
      case MEDIA_FORMAT_MP4_AMR_WB:
         *len = 1;
         break;
#endif
#if defined(__DRA_DECODE_SUPPORT__)
      case MEDIA_FORMAT_DRA:
         if (( freq == 32000 || freq == 44100 || freq == 48000 ) && (channelNum == 2))
         {
            *len = 8;
         }
         break;
#endif
#if defined(WAV_CODEC)
      case MEDIA_FORMAT_PCM:
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_WAV:
         *len = freq*channelNum*2/100;
         break;
#endif
#if defined(AAC_DECODE)
      case MEDIA_FORMAT_AAC:
      case MEDIA_FORMAT_MP4_AAC:
         *len = 16;
         break;
      case MEDIA_FORMAT_AAC_PLUS:
         if (channelNum == 1)
         {
            *len = 29;
         }
         else
         {
            *len = 39;
         }
         break;
      case MEDIA_FORMAT_AAC_PLUS_V2:
         *len = 33;
         break;
#endif
#if defined(BSAC_DECODE)
      case MEDIA_FORMAT_BSAC:
      case MEDIA_FORMAT_MP4_BSAC:
         if (channelNum == 1) 
         {
            *len = 7 + 9*subframeNum;
         }
         else 
         {
            *len = 7 + 13*subframeNum;
         }
         break;
#endif
      default:
         *len = 0;
   }
   return MEDIA_SUCCESS;
}

#if defined(AAC_DECODE)

static const kal_uint8 AAC_Mono_SilData[9] = { 0x01, 0x40, 0x20, 0x07, 0xF6, 0x00, 0x00, 0x00, 0x00 };
static const kal_uint8 AAC_Stereo_SilData[9] = { 0x21, 0x00, 0x49, 0x90, 0x02, 0x19, 0x00, 0x23, 0x80 };
static const kal_uint8 AAC_Plus_Mono_SilData[22] = {
   0x00, 0xD0, 0x30, 0x83, 0xE2, 0x5B, 0x66, 0x25, 
   0x77, 0xC4, 0x5A, 0xB7, 0x14, 0x05, 0xD0, 0x40, 
   0x00, 0x00, 0x00, 0x03, 0x80, 0x38
};
static const kal_uint8 AAC_Plus_Stereo_SilData[32] = {
   0x21, 0x19, 0x53, 0x40, 0x7C, 0xCB, 0x6C, 0xA4, 
   0xA1, 0x08, 0x9A, 0x03, 0xE6, 0x5B, 0x65, 0x25, 
   0x08, 0x45, 0xB3, 0x75, 0x60, 0x5D, 0x42, 0x00, 
   0x00, 0x00, 0x01, 0xC6, 0x00, 0x0C, 0x03, 0x80
};
static const kal_uint8 AAC_PS_Mono_SilData[26] = {
   0x00, 0xD0, 0x33, 0x03, 0xE7, 0x5B, 0x88, 0x39, 0x7C, 0xFF, 
   0xFC, 0x5B, 0x77, 0x78, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 
   0x01, 0xC2, 0x54, 0x10, 0x00, 0x38
};

Media_Status  Media_GetSilencePattern_AAC(Media_Format format, kal_uint32 channelNum, kal_uint32 freq, kal_uint32 subframeNum, kal_uint8 *pattern)
{
   kal_uint32 freqIndex = 0;
   kal_uint32 silLen = 0;
   switch (freq) 
   {
      case 8000:
         freqIndex = 11;
         break;
      case 11025:
         freqIndex = 10;
         break;
      case 12000:
         freqIndex = 9;
         break;
      case 16000:
         freqIndex = 8;
         break;
      case 22050:
         freqIndex = 7;
         break;
      case 24000:
         freqIndex = 6;
         break;
      case 32000:
         freqIndex = 5;
         break;
      case 44100:
         freqIndex = 4;
         break;
      case 48000:
         freqIndex = 3;
         break;
      default:
         return MEDIA_UNSUPPORTED_FREQ;
   }

   memcpy(pattern, AAC_Header, 7);

   switch (format) 
   {
      case MEDIA_FORMAT_AAC:
      case MEDIA_FORMAT_MP4_AAC:
         silLen = 16;
         if (channelNum == 1)
         {
            memcpy(pattern+7, AAC_Mono_SilData, 9);
         } 
         else
         {
            memcpy(pattern+7, AAC_Stereo_SilData, 9);
         }
         break;
      case MEDIA_FORMAT_AAC_PLUS:
         if (channelNum == 1) 
         {
            silLen = 29;
            memcpy(pattern+7, AAC_Plus_Mono_SilData, 22);
         }
         else
         {
            silLen = 39;
            memcpy(pattern+7, AAC_Plus_Stereo_SilData, 32);
         }
         break;
      case MEDIA_FORMAT_AAC_PLUS_V2:
         {
            silLen = 33;
            memcpy(pattern+7, AAC_PS_Mono_SilData, 26);
         }
         break;
      default:
         return MEDIA_UNSUPPORTED_TYPE;
   }
   
   // Update AAC ADTS header
   pattern[2] |= (freqIndex<<2);
   pattern[3] |= (channelNum<<6) | (silLen>>11);
   pattern[4] = (silLen>>3)&0xFF;
   pattern[5] |= (silLen & 0x07) << 5;
   return MEDIA_SUCCESS;
}
#endif

#if defined(BSAC_DECODE)

static const kal_uint8 BSAC_Mono_SilData[9] = { 0x01, 0x20, 0x05, 0x01, 0x08, 0x00, 0x00, 0x00, 0x00 };
static const kal_uint8 BSAC_Stereo_SilData[13] = {
   0x01, 0xA0, 0x05, 0x01, 0x01, 0x08, 0x00, 0x00, 0x00, 0x00, 
   0x00, 0x00, 0x00
};

Media_Status  Media_GetSilencePattern_BSAC(Media_Format format, kal_uint32 channelNum, kal_uint32 freq, kal_uint32 subframeNum, kal_uint8 *pattern)
{
   kal_uint32 silLen = 0;
   kal_int32 I;
   kal_uint8 *dest;
   dest = pattern + 7;
   if (channelNum == 1)
   {
      for (I=subframeNum-1; I>=0; I--) 
      {
         memcpy(dest, BSAC_Mono_SilData, 9);
         dest += 9;
      }
      silLen = 7 + 9*subframeNum;
   }
   else
   {
      for (I=subframeNum-1; I>=0; I--)
      {
         memcpy(dest, BSAC_Stereo_SilData, 13);
         dest += 13;
      }
      silLen = 7 + 13*subframeNum;
   }
   return MEDIA_SUCCESS;
}
#endif

#if defined(__DRA_DECODE_SUPPORT__)

#if 0 // file
/* under construction !*/
#else // streaming
static const kal_uint8 DRA_SilData[8] = { 0x7F, 0xFF, 0x00, 0x58, 0x03, 0xA0, 0x00, 0x1F};
#endif

Media_Status Media_GetSilencePattern_DRA(Media_Format format, kal_uint32 channelNum, kal_uint32 freq, kal_uint32 subframeNum, kal_uint8 *pattern)
{
   memcpy(pattern, DRA_SilData, 8);
   if (channelNum == 2)
   {
      pattern[4] |= 0x10;
   }
   else
   {
      return MEDIA_UNSUPPORTED_CHANNEL;
   }
         
   if (freq == 32000)
   {
      pattern[3] |= 0x3;
   }
   else if (freq == 44100)
   {
      pattern[3] |= 0x3;
      pattern[4] |= 0x80;
   }
   else if (freq == 48000)
   {
      pattern[3] |= 0x4;
   }   
   else
   {
      return MEDIA_UNSUPPORTED_FREQ;
   } 
   return MEDIA_SUCCESS;
}
#endif

Media_Status  Media_GetSilencePattern(Media_Format format, kal_uint32 channelNum, kal_uint32 freq, kal_uint32 subframeNum, kal_uint8 *pattern)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_SILENCE_PATTERN, format, channelNum, freq, subframeNum,pattern,0);
   switch (format) 
   {
#if defined(__COOK_DECODE__)
      case MEDIA_FORMAT_COOK:
         pattern[0] = 0xFF; pattern[1] = 0x25; pattern[2] = 0x37; pattern[3] = 0xFF;  
         break;
#endif
#if defined(AMR_CODEC) || defined(AMRWB_DECODE)
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_AMR_WB:
      case MEDIA_FORMAT_MP4_AMR:
      case MEDIA_FORMAT_MP4_AMR_WB:
         pattern[0] = 0x7C;
         break;
#endif
#if defined(__DRA_DECODE_SUPPORT__)
      case MEDIA_FORMAT_DRA:
         return Media_GetSilencePattern_DRA(format,channelNum,freq,subframeNum,pattern);
#endif
#if defined(WAV_CODEC)
      case MEDIA_FORMAT_PCM:
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_WAV:
         memset(pattern, 0, freq*channelNum*2/100);
         break;
#endif
#if defined(AAC_DECODE)
      case MEDIA_FORMAT_AAC:
      case MEDIA_FORMAT_MP4_AAC:
      case MEDIA_FORMAT_AAC_PLUS:
      case MEDIA_FORMAT_AAC_PLUS_V2:
         return Media_GetSilencePattern_AAC(format,channelNum,freq,subframeNum,pattern);
#endif
#if defined(BSAC_DECODE)
      case MEDIA_FORMAT_BSAC:
      case MEDIA_FORMAT_MP4_BSAC:
         return Media_GetSilencePattern_BSAC(format,channelNum,freq,subframeNum,pattern);
#endif
      default:
         return MEDIA_UNSUPPORTED_TYPE;
   }
   return MEDIA_SUCCESS;
}


kal_bool Media_IsFormatSupported(Media_Format uFormat, kal_uint32 channelNum, kal_uint32 freq)
{
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_IS_FORMAT_SUPPORT, uFormat, channelNum, freq, 0,0,0);
   switch( uFormat ) 
   {
      case MEDIA_FORMAT_UNKNOWN:
         break;
#if defined(AMR_CODEC)
      case MEDIA_FORMAT_AMR:
      case MEDIA_FORMAT_MP4_AMR:
      {
         if(channelNum == 1 && freq == 8000)
         {
            return KAL_TRUE;
         }
      }
#endif
#if defined(AMRWB_DECODE)
      case MEDIA_FORMAT_AMR_WB:
      case MEDIA_FORMAT_MP4_AMR_WB:    
      {
         if(channelNum == 1 && freq == 16000)
         {
            return KAL_TRUE;
         }
      }          
#endif
#if defined(AAC_DECODE)      
      case MEDIA_FORMAT_AAC:
      case MEDIA_FORMAT_AAC_PLUS:
      case MEDIA_FORMAT_AAC_PLUS_V2:
      case MEDIA_FORMAT_MP4_AAC: 
      {
         if((channelNum == 1 || channelNum == 2)&& 
            (   freq == 8000  || freq == 11025 || freq == 12000 
             || freq == 16000 || freq == 22050 || freq == 24000 
             || freq == 32000 || freq == 44100 || freq == 48000 
             || freq == 64000 || freq == 88200 || freq == 96000))
         {
            return KAL_TRUE;
         }
      }
#endif
#if defined(__DRA_DECODE_SUPPORT__)
      case MEDIA_FORMAT_DRA:
#endif
#if defined(__COOK_DECODE__)
      case MEDIA_FORMAT_COOK:
#endif
#if defined(DAF_DECODE)
      case MEDIA_FORMAT_DAF:
#endif
#ifdef MUSICAM_DECODE
      case MEDIA_FORMAT_MUSICAM:
#endif
#if defined(WAV_CODEC)
      case MEDIA_FORMAT_PCM:
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:      
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_WAV_16K:
#endif
      {
         if((channelNum == 1 || channelNum == 2)&& 
            (   freq == 8000  || freq == 11025 || freq == 12000 
             || freq == 16000 || freq == 22050 || freq == 24000 
             || freq == 32000 || freq == 44100 || freq == 48000))
         {
            return KAL_TRUE;
         }
      }
      default:
         break;
   }
   return KAL_FALSE;
}


kal_uint32 Media_GetPlaybackPrebufferFrameNum(Media_Format uFormat)
{
#if (!defined(MT6268)&&!defined(MT6236)&&!defined(MT6236B)) 
   switch( uFormat ) 
   {
      case MEDIA_FORMAT_AAC:
      case MEDIA_FORMAT_AAC_PLUS:      	
      case MEDIA_FORMAT_AAC_PLUS_V2:       	
      case MEDIA_FORMAT_MP4_AAC:         	
        return 260;
        
      default:
        break;
   }
#endif
   return 60;
}

kal_bool Media_IsSeekable(STFSAL *pstFSAL, Media_Format uFormat)
{
   switch( uFormat ) 
   {
#if defined(AAC_DECODE)
      case MEDIA_FORMAT_AAC:
      case MEDIA_FORMAT_AAC_PLUS:      	
      case MEDIA_FORMAT_AAC_PLUS_V2:       	
      case MEDIA_FORMAT_MP4_AAC:    
         if(AAC_IsADIF(pstFSAL))
         {
            return KAL_FALSE;
         }
         else
         {
            return KAL_TRUE;
         }        
#endif
#if defined(__APE_DECODE__)
      case MEDIA_FORMAT_APE:    
         return APE_IsSeekable(pstFSAL);
#endif
      case MEDIA_FORMAT_GSM_FR:
      case MEDIA_FORMAT_GSM_HR:
      case MEDIA_FORMAT_GSM_EFR:
      case MEDIA_FORMAT_VRD:
      case MEDIA_FORMAT_VRSI:
      case MEDIA_FORMAT_VOIPEVL:
      case MEDIA_FORMAT_UNKNOWN: 
#if defined(MIDFILE_PLAY_SUPPORT)
      case MEDIA_FORMAT_SMF: 
#endif
         return KAL_FALSE;
        
      default:
         break;
   }
   return KAL_TRUE;
}

kal_bool Media_IsPauseable(STFSAL *pstFSAL, Media_Format uFormat)
{
   if(uFormat == MEDIA_FORMAT_SMF)
   {
      return KAL_TRUE;
   }
   else
   {
      return Media_IsSeekable(pstFSAL, uFormat);
   }
}

kal_uint32 Media_GetAudioPlaybackRingBufferMinSize(Media_Format uFormat)
{
#if defined(MT6276) 
   switch( uFormat ) 
   {
      case MEDIA_FORMAT_GSM_FR:
      case MEDIA_FORMAT_GSM_HR:
      case MEDIA_FORMAT_GSM_EFR:
         return 8192;
      default:
         return 0;
   }
#else
   switch( uFormat ) 
   {
      case MEDIA_FORMAT_DAF:
      case MEDIA_FORMAT_MUSICAM:
         return 4608;
      case MEDIA_FORMAT_PCM_8K:
      case MEDIA_FORMAT_PCM_16K:
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_WAV_16K:
      case MEDIA_FORMAT_PCM:
         return 4096; //3760
      default:
         return 2048;
   }
#endif
}

const kal_uint16 awb_byte_rate[9]={824,1106, 1581,1781,1981,2281,2481,2881,2981};
const kal_uint16 amr_byte_rate[8]={1660,1387,1081,1006,911,802,700,646};

kal_uint32 Media_GetRecordFormatByteRate( Media_Format uFormat, Audio_Record_Mode uMode, void *param )
{
   kal_uint32 uByteRate = 16000;
   kal_uint32 uParam = (uint32)param;
   switch( uFormat ) 
   {
      case MEDIA_FORMAT_AMR:
      {
         if( uParam>=0x3 && uParam<=0xA )
         {
            uByteRate = amr_byte_rate[uParam-0x3];
         }
         else
         {
            uByteRate = amr_byte_rate[0];
         }
         break;
      }
      case MEDIA_FORMAT_AMR_WB:
      {
         if( uParam>=0x20 && uParam<=0x28 )
         {
            uByteRate = awb_byte_rate[uParam-0x20];
         }
         else
         {
            uByteRate = awb_byte_rate[8];
         }
         break;
      }
      case MEDIA_FORMAT_WAV:
         uByteRate = 16000;
         break;
      case MEDIA_FORMAT_WAV_ALAW:
      case MEDIA_FORMAT_WAV_ULAW:
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
         uByteRate = 8110;
         break;
      case MEDIA_FORMAT_WAV_DVI_ADPCM:
         uByteRate = 4055;
         break;
      case MEDIA_FORMAT_VORBIS:
         uByteRate = 5000;
         break;
      case MEDIA_FORMAT_DAF:
         uByteRate = 16000;
         break;
      default:
         break;
   }

#if defined( __FMRADIO_I2S_SUPPORT__ )
   if( uMode == AUDIO_RECORD_MODE_I2S || uMode == AUDIO_RECORD_MODE_FM )
#else
   if( uMode == AUDIO_RECORD_MODE_I2S )
#endif   
   {
      switch( uFormat ) 
      {
         case MEDIA_FORMAT_WAV:
         case MEDIA_FORMAT_WAV_ALAW:
         case MEDIA_FORMAT_WAV_ULAW:
         case MEDIA_FORMAT_WAV_DVI_ADPCM:
         case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
            uByteRate  = Media_I2S_INPUT_MODE_SR*2/4;
            break;
         case MEDIA_FORMAT_VORBIS:
            uByteRate = 16000;
         default:
            break;
      }
   }
   return uByteRate;
}


Media_Status  Media_GetRecordFormat( Audio_Record_Mode uMode, Audio_Record_Quality uQuality, Audio_Record_Format *pFormatStruct )
{
   pFormatStruct->uFormat = MEDIA_FORMAT_UNKNOWN;
   pFormatStruct->uByteRate = 0;

   switch( uMode ) 
   {
      case AUDIO_RECORD_MODE_SPEECH:
      {
         if(uQuality == AUDIO_RECORD_QUALITY_HIGH)
         {
            pFormatStruct->uFormat = AUDIO_RECORD_SPEECH_MODE_HIGH;
         }
         else
         {
            pFormatStruct->uFormat = AUDIO_RECORD_SPEECH_MODE_LOW;
         }
         break;   
      }
      case AUDIO_RECORD_MODE_FM:
      {
         if(uQuality == AUDIO_RECORD_QUALITY_HIGH)
         {
            pFormatStruct->uFormat = AUDIO_RECORD_FM_MODE_HIGH;
         }
         else
         {
            pFormatStruct->uFormat = AUDIO_RECORD_FM_MODE_LOW;
         }
         break;   
      }
      case AUDIO_RECORD_MODE_IDLE:
      {
         if(uQuality == AUDIO_RECORD_QUALITY_HIGH)
         {
            pFormatStruct->uFormat = AUDIO_RECORD_IDLE_MODE_HIGH;
         }
         else
         {
            pFormatStruct->uFormat = AUDIO_RECORD_IDLE_MODE_LOW;
         }
         break;   
      }
      case AUDIO_RECORD_MODE_I2S:
      {
         if(uQuality == AUDIO_RECORD_QUALITY_HIGH)
         {
            pFormatStruct->uFormat = AUDIO_RECORD_I2S_MODE_HIGH;
         }
         else
         {
            pFormatStruct->uFormat = AUDIO_RECORD_I2S_MODE_LOW;
         }
         break;   
      }
      default:
         break;
   }

   pFormatStruct->uByteRate = Media_GetRecordFormatByteRate( pFormatStruct->uFormat, uMode, NULL);
   switch( pFormatStruct->uFormat ) 
   {
      case MEDIA_FORMAT_AMR:
         kal_wstrcpy(pFormatStruct->pFileExtension, L".amr");
         break;
      case MEDIA_FORMAT_AMR_WB:
         kal_wstrcpy(pFormatStruct->pFileExtension, L".awb");
         break;
      case MEDIA_FORMAT_WAV:
      case MEDIA_FORMAT_WAV_ALAW:
      case MEDIA_FORMAT_WAV_ULAW:
      case MEDIA_FORMAT_WAV_DVI_ADPCM:
      case MEDIA_FORMAT_WAV_DVI_ADPCM_16K:
         kal_wstrcpy(pFormatStruct->pFileExtension, L".wav");
         break;
      case MEDIA_FORMAT_VORBIS:
         kal_wstrcpy(pFormatStruct->pFileExtension, L".ogg");
         break;
      default:
         return MEDIA_FAIL;
   }
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_GET_RECORD_FORMAT, uMode, uQuality, pFormatStruct->uFormat, pFormatStruct->uByteRate,0,0);
   return MEDIA_SUCCESS;
}




//-------------------------------------------
kal_bool Media_IsPlaybackOn( void )
{
   if ( -1 != AM_IsAudioPlaybackOn() )
      return KAL_TRUE;
   if ( AM_IsVMPlaybackOn() )
      return KAL_TRUE;

   return KAL_FALSE;
}

//-------------------------------------------


#if defined( __I2S_INPUT_MODE_SUPPORT__ )
// for FM usage
void I2SIN_TurnOnSpeaker(){
   AFE_TurnOnSpeaker(L1SP_AUDIO);
}

void I2SIN_TurnOffSpeaker(){
   AFE_TurnOffSpeaker(L1SP_AUDIO);
}

void I2SIN_MuteSpeaker( kal_bool mute ){
   //if(AFE_IsSpeakerMuted(L1SP_AUDIO)==KAL_TRUE && mute==KAL_FALSE) 
   //   return;
   AFE_MuteSpeaker( L1SP_AUDIO, mute );
}

void I2SIN_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index ){
   AFE_SetOutputVolume( L1SP_AUDIO, volume1, digital_gain_index );
}

void I2SIN_SetOutputDevice( kal_uint8 device ){
   AFE_SetOutputDevice( L1SP_AUDIO, device );
}
#endif
void Media_GetMaxMinRate(Media_Format eFormat, kal_int32* max, kal_int32* min)
{
   switch(eFormat){
      case MEDIA_FORMAT_SMF:
      case MEDIA_FORMAT_JTS:
         *max = 400*1000;
         *min =  25*1000;
         break;
      default:
         *max = 160*1000;
         *min =  50*1000;
         break;
   }
}
void Media_GetMMACapability(Media_Format eFormat, kal_uint8* concurrent)
{
   switch(eFormat){
      case MEDIA_FORMAT_SMF:
         *concurrent = MAX_MMA_PLAYERS_SMF;
         break;
      case MEDIA_FORMAT_IMELODY:
         *concurrent = MAX_MMA_PLAYERS_IMY;
         break;
      case MEDIA_FORMAT_JTS:
         *concurrent = MAX_MMA_PLAYERS_JTS;
         break;
      case MEDIA_FORMAT_WAV:
         *concurrent = MAX_MMA_PLAYERS_WAV;
         break;    
      default:
         *concurrent = MAX_MMA_PLAYERS_AUD;
         break;
   }
}
Media_Status Media_FastPassMode(void* hdl, Media_Format eFormat)
{
   switch(eFormat){
      case MEDIA_FORMAT_SMF:
      case MEDIA_FORMAT_JTS:
      case MEDIA_FORMAT_IMELODY:
      {
         Media_Handle *handle = (Media_Handle*)hdl;
         handle->appflag = true;
      }
         break;
      default:
         return MEDIA_FAIL;
   }
   return MEDIA_SUCCESS;
}

/**
	@return: mapping to "Media_Speech_Feature" to indicate the feature existing. 
*/
kal_uint32 Media_GetSpeechFeatureCapability(void)

{
	uint32 features = MEDIA_SPEECH_FEATURE_NONE;
	
#if defined(__DUAL_MIC_SUPPORT__) //DMNR in NB
	features |= MEDIA_SPEECH_FEATURE_NB_DMNR; 
	
#if defined(__AMRWB_LINK_SUPPORT__) //DMNR in WB
	features |= MEDIA_SPEECH_FEATURE_WB_DMNR; 
#endif //__AMRWB_LINK_SUPPORT__  (inside __DUAL_MIC_SUPPORT__)
#endif //__DUAL_MIC_SUPPORT__

#if defined(__AMRWB_LINK_SUPPORT__) //Speech phone call is WB
	features |= MEDIA_SPEECH_FEATURE_WB_LINK_SUPPORT;
#endif

	return features;
}

int my_log2(const unsigned int number, const unsigned int number_mantissa_size, const unsigned int log_mantissa_size)
{
	// cpower is chosen so that ((2^(cpower+1))-1)^2 will fit in an unsigned int
	unsigned int cpower = ((sizeof(unsigned int)*8)/2)-1;
	unsigned int one = 1 << cpower;
	unsigned int two = 2 << cpower;
   int l;
	unsigned int n;
   unsigned int mantissa_bit;

	// zero will mess up the algorithm below
	if ( number == 0 )
      return 0;

	l = cpower - number_mantissa_size; // number is actually number/(2^number_mantissa_size), so number_mantissa_size is subtracted from the log (it is done at the beginning to circumvent having to shift number_mantissa_size)
	n = number;

	// make sure one <= n < two (and administrer any shifts in l, l becomes floor(log(number)))
	while(n < one)
	{
		n <<= 1;
		--l;
	}
	while(n >= two)
	{
		n >>= 1;
		++l;
	}

	// now calculate some binary digits
	for( mantissa_bit = 0; mantissa_bit < log_mantissa_size; ++mantissa_bit)
	{
		l <<= 1u;		// make room for an extra bit (shifting a negative signed integer works perfectly!)
		n *= n;			// n_new = n_old^2 = (2^0.yxxx)^2 = 2^y.xxx
		n >>= cpower;	// normalize n to keep n from getting too large
		if ( n >= two )
		{	// apparently y (see the comment behind n *= n) was 1
			l |= 1;	// set the LSB to 1
			n >>= 1;	// divide by two, subtracting 1 from 1.xxx (n/2 = (2^-1)(2^1.xxx) = 2^0.xxx) to prepare for the next step
		}
	}

	return l;
}
