/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *   fc_def.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Header file of Dual MAC DSP related definition
 *
 * Author:
 * -------
 * -------
 *============================================================================
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


#ifndef _FC_DEF_DOT_H_
#define _FC_DEF_DOT_H_


#include "l1audio.h"
/* ---------- Definition of structure ---------- */

#define __DRIVER_PRESERVE_DSP_SHARE_BUFFER__ 1

#if defined(MT6573) || defined(MT6575) || defined(MT6577)
#define MSG_RB_SIZE     64
#else
#define MSG_RB_SIZE     32
#endif

#define MAX_CURRENCY_ID 10

typedef struct {
   kal_uint32  msgID;
   kal_uint32  msgData;
   kal_uint32  putTime;
   kal_uint32  getTime;
} MsgElement;

typedef struct {
   kal_uint16  msgID16;
   kal_uint16  msgData16;
   kal_uint32  msgData32;
} AckMsgElement;

typedef struct {
   kal_uint32 read;
   kal_uint32 write;
   MsgElement queue[MSG_RB_SIZE];
} MsgRingBuffer;

typedef enum {
   MEDIA_OPERATE_PLAYBACK,
   MEDIA_OPERATE_RECORD
} Media_Operation;

typedef struct {
   Media_Operation   operation;
   Media_Format      format;
} Media_Action_Param;


typedef  void  (*L1Audio_MsgIDHandler)(kal_uint16 msgOp, kal_uint32 msgData, void *userData);
typedef  void  (*L1Audio_SphMsgHandler)(kal_uint16 msgOp, kal_uint32 msgData, void *userData);

typedef struct {
   kal_bool              isUsed;
   kal_uint16            aud_id;
   kal_uint32            *userData;
   L1Audio_MsgIDHandler  userMsgHandler;
} MsgIDHandler;

typedef enum {
   FC_MEDIA_FORMAT_DAF,
   FC_MEDIA_FORMAT_AAC,
   FC_MEDIA_FORMAT_PCM,
   FC_MEDIA_FORMAT_I2S,
   FC_MEDIA_FORMAT_QTMF,
   FC_MEDIA_FORMAT_MELODY,
   FC_MEDIA_FORMAT_VM,
   FC_MEDIA_FORMAT_WAV,
   FC_MEDIA_FORMAT_AMR,
   FC_MEDIA_FORMAT_AWB,
   FC_MEDIA_FORMAT_AWB_PLUS,
   FC_MEDIA_FORMAT_MUSICAM,
   FC_MEDIA_FORMAT_AAC_PLUS,
   FC_MEDIA_FORMAT_AAC_PLUS_V2,
   FC_MEDIA_FORMAT_BSAC,
   FC_MEDIA_FORMAT_WMA
} FC_Media_Format;

typedef struct {
   kal_uint32      freq1;
   kal_uint32      freq2;
   kal_uint32      freq3;
   kal_uint32      freq4;
   kal_int32       msDur;
} AUD_TONE_INFO;

typedef enum {
   FC_STATE_IDLE,
   FC_STATE_PLAY,
   FC_STATE_RECORD
} FC_State;

// Buffer Structure
typedef struct{
   kal_uint8  *pBuf;
   kal_uint32 uBufLength;
   kal_uint8  *pWrite;
   kal_uint8  *pRead;
   kal_uint32 uTime;
   kal_uint32 uSamplingFreq;
   kal_uint32 uChannelNum;
   kal_uint32 uOutputDevice;
} FC_Buf;

typedef enum{
   eAUD_OUTDEV_NONE = 0,
   eAUD_OUTDEV_DAC = 0x0001,
   eAUD_OUTDEV_I2S = 0x0002,
   eAUD_OUTDEV_BT = 0x0004,
   eAUD_OUTDEV_MCU = 0x0008  
}AUD_OUTDEV_T;


typedef enum
{
   eAUD_INDEV_SINGLE_MIC,
   eAUD_INDEV_DUAL_MIC,
   eAUD_INDEV_SINGLE_DIGITAL_MIC,
   eAUD_INDEV_DUAL_DIGITAL_MIC,
   eAUD_INDEV_I2S,
   eAUD_INDEV_BT
}AUD_INDEV_T;

typedef struct{
   kal_uint32 fc_format;
   kal_uint16 fc_aud_id;
   kal_uint8  fc_state;
   kal_uint8  fc_operation;
   FC_Buf     *pBufInfo;
} FC_Drv_Info;


/* ---------- Definition of Message ---------- */
// DSP_Version should be sync with DSDP code, if not match=> assert
#define DSP_VERSION  2


/* ---------- Interface ---------- */
kal_uint16 L1Audio_FC_HookHandler( void *userData, L1Audio_MsgIDHandler userHandler, kal_uint16 type, kal_uint16 msg16 );
void L1Audio_FC_UnHookHandler( kal_uint16 aud_id, kal_uint16 type );
void L1Audio_FC_UnHookHandler_WithoutWaitingSend( kal_uint16 aud_id, kal_uint16 type );
void L1Audio_FC_UnHookHandler_WithoutWaitingClear( kal_uint16 aud_id, kal_uint16 type );
void L1Audio_FC_AudioPlaybackOn( kal_uint16  aud_id, AUD_RB_INFO *info );
void L1Audio_FC_AudioPlaybackOn_Component( kal_uint16 aud_id, void *ihdl, FC_Drv_Info *pDrvInfo );
void L1Audio_FC_AudioPlaybackOff( kal_uint16 aud_id );
void L1Audio_FC_RecordOn( kal_uint16 dedicated, kal_uint16 size, void *data, L1Audio_MsgIDHandler userHandler );
void L1Audio_FC_RecordOff( kal_bool dedicated );
void L1Audio_FC_TonePlaybackOn( kal_uint16 aud_id, AUD_TONE_INFO *info );
void L1Audio_FC_TonePlaybackOff( kal_uint16 aud_id );
void L1Audio_FC_SetPlayRate( kal_uint16 aud_id, kal_uint32 rate );
void L1Audio_FC_AudioWriteData( kal_uint16 aud_id, AUD_RB_INFO *info );
void L1Audio_FC_AudioDataRequestAck( kal_uint16 aud_id, AUD_RB_INFO *info );
void L1Audio_FC_AudioDataRequestAck_Component( kal_uint16 aud_id, FC_Buf *pBufHdr );
void L1Audio_FC_AudioDataNotifyAck( kal_uint16 aud_id );
void L1Audio_FC_AudioDataNotifyAck_Component( kal_uint16 aud_id, FC_Buf *pBufInfo );
void L1Audio_FC_SetWait( kal_bool wait );
void L1Audio_PutMessage( kal_uint16 msgID16, kal_uint16 msgData16, kal_uint32 msgData32);
void L1Audio_PutMessageAndWait( kal_uint16 msgID16, kal_uint16 msgData16, kal_uint32 msgData32, kal_bool waiting );

FC_Buf *L1Audio_FC_GetAudioBufferHeader( void );
void L1Audio_FC_ReleaseAudioBufferHeader( FC_Buf **pBufHeader );
void L1Audio_FC_ResetAudioBufferHeader(FC_Buf *pBufHeader);
kal_uint32 L1Audio_FC_WriteBufferToDSP(AUD_RB_INFO *rbInfo);
kal_uint32 L1Audio_FC_WriteBufferToDSP_Component(void *hdl, FC_Drv_Info *pDrvInfo);
kal_uint32 L1Audio_FC_ReadBufferFromDSP_Component(void *hdl, FC_Buf *pBufInfo);
void L1Audio_FC_UpdateDspReadPointer(AUD_RB_INFO *rbInfo, kal_uint32 mag32);
void L1Audio_FC_UpdateDspReadPointer_Component(FC_Buf *fc_BufHdr, kal_uint32 mag32);
void L1Audio_FC_UpdateDspWritePointer_Component(FC_Buf *fc_BufHdr, kal_uint32 mag32);
void L1Audio_FC_AudioDataRequestAck( kal_uint16 aud_id, AUD_RB_INFO *info );

kal_uint32 FC_GetDspFreeSpace(FC_Buf *fc_BufHdr);
kal_uint32 FC_GetDspDataCount(void *pBufHdr);

// For AV sync
FC_Buf *L1Audio_FC_QueryBufInfo( void );

#endif
