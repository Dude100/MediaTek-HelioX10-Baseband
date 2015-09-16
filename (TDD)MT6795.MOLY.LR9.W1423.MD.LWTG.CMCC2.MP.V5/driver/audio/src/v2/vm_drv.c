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
 * vm_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   VM Decoder Driver
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

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "fsal.h"
#include "string.h"
                    
#include "l1audio.h"
#include "audio_enum.h"
#include "l1audio_def.h"
#include "am.h"
#include "fc_def.h"
#include "media.h"
#include "l1sp_trc.h"
#include "afe.h"
#include "exp_SphFasTypDef.h"

#define VM_STATE_IDLE          0
#define VM_STATE_PLAY          3
#define VM_STATE_PLAY_PAUSE    4
#define VM_STATE_STOP          5

#define LoadDWORD( dw, p )   (dw) = (*(p+3)<<24) | (*(p+2)<<16) | (*(p+1)<<8) |(*p);  (p) += sizeof(uint32);


/* ------------------------------------------------------------------------------ */

typedef struct vm_internal{
   MHdl           mh;
   STFSAL         *pstFSAL;
   Media_Event    end_status;

   uint8          state;
   uint16         control;    /* control word for FR/HR/EFR                         */
                              /* bit  0-1:   Channel usage(bit0:UL,bit1:DL)         */
                              /* bit  2-5:   UL Speech mode(0->FR, 1->HR, 2->EFR)   */
                              /* bit  6-9:   DL Speech mode(0->FR, 1->HR, 2->EFR)   */
                              /* bit  10:    DP_TX_TCH_S0_0 data bit 1              */
                              /* bit 11-15:  DP_RX_TCH_S0_0 data bit 1-5            */

                              /* control word for AMR                               */
                              /* bit  0-1:   Channel usage(bit0:UL,bit1:DL)         */
                              /* bit  2-5:   UL Speech mode(0->FR, 1->HR, 2->EFR)   */
                              /* bit  6-9:   DL Speech mode(0->FR, 1->HR, 2->EFR)   */
                              /* bit 10-11:  DP_TX_TCH_S0_0 data bit 0-1            */
                              /* bit 12-15:  DP_RX_TCH_S0_0 data bit 1-3,5          */
   uint32         param;
} vmMediaHdl;

/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   
#ifdef BGSND_ENABLE
   void (*vm_drv_sndOnHandler)(void *hdl); 
   void (*vm_drv_sndOffHandler)(void *hdl);
   void *vm_drv_sndHdl;
#endif     
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   

__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI")))
   SAC_SphPlayPar_t SAC_SphPlayPar;


#if defined(MED_NOT_PRESENT) || defined( MED_MODEM )
kal_int32 autGetBytes(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 uLen, kal_uint8 *pbBuf)
{
    return 0;    
}
#endif

Media_Status vmWriteFrame(MHdl *hdl, kal_bool bBool)
{
   return MEDIA_SUCCESS;
}

static kal_bool vmSeek( vmMediaHdl *ihdl)
{
   return KAL_TRUE;
}

static void vmMsgHandler(kal_uint16 msgOp, kal_uint32 msgData, void *userData)
{
   MHdl *hdl = (MHdl *) userData;
   vmMediaHdl *ihdl = (vmMediaHdl *)userData;
   
   switch (msgOp) {
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
         hdl->current_time += 20;
         // Notify MED to refill media buffer
         if ( (hdl->eof) && (hdl->GetDataCount((MHdl*)hdl) == 0) ) {
            ihdl->end_status = MEDIA_END;
            mhdlException( (MHdl*)ihdl, MEDIA_END );
         } else
            #if defined(__SMART_PHONE_MODEM__)
            spc_RequestPcmData();
            #else
            mhdlDataRequest((MHdl*)ihdl, ihdl->end_status);
            #endif
         break;
      }
      case MSG_SAC2L1AUDIO_SPEECH_IDLE_PLAY_VM_FAIL:
         L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_IDLE_PLAY_VM_FAIL_ACK, ihdl->mh.fc_aud_id, 0);
         mhdlException( (MHdl*)ihdl, MEDIA_ERROR );
         break;
      default:
         ASSERT(0);
   }
}

Media_Event vmMFProcess( MHdl *hdl, Media_Event event )
{
   vmMediaHdl *ihdl = (vmMediaHdl *) hdl;
   uint32 buf_len;
   int32 get_len, total_len;
   uint8  *pBuf;

   ASSERT(ihdl != NULL);

   kal_trace( TRACE_GROUP_AUD_PROCESS, L1AUDIO_PROCESS, hdl->mediaType );

   switch(event)
   {
      case MEDIA_END:
      case MEDIA_ERROR:
         kal_trace( TRACE_ERROR, L1AUDIO_MCU_ERROR );
         if( hdl->state == VM_STATE_PLAY ) {
            L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_IDLE_PLAY_STOP, ihdl->mh.fc_aud_id, 0, KAL_TRUE );
            L1Audio_FC_UnHookHandler(ihdl->mh.fc_aud_id, 1);
            AM_VMPlaybackOff(ihdl->param);
            mhdlAllowSleep( hdl );            
         }
         hdl->state = VM_STATE_IDLE;
         return event;
      case MEDIA_DATA_REQUEST:
         total_len = hdl->GetFreeSpace(hdl);
         total_len &= 0xFFFFFFFE;

         while (total_len > 0) {
            hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);
            get_len = autGetBytes(hdl, ihdl->pstFSAL, buf_len, pBuf);
            if (get_len < 0) {
               kal_trace( TRACE_ERROR, L1AUDIO_MCU_ERROR );
               return MEDIA_ERROR;
            } else if (get_len < buf_len) {
               hdl->eof = true;
               hdl->WriteDataDone( hdl, get_len );
               break;
            } else {
               hdl->WriteDataDone( hdl, get_len );
               total_len -= get_len;
            }
         }

         hdl->waiting = KAL_FALSE;
         return MEDIA_NONE;
      default:
         ASSERT(0); // should never reach here
   }
   return MEDIA_NONE;
}

static Media_Status vmMFPlayFile( MHdl *hdl )
{
   vmMediaHdl *ihdl = (vmMediaHdl *)hdl;
   Media_Status ret = MEDIA_SUCCESS;
   
   TONE_StopAndWait();
   KT_StopAndWait();


   // Initialize for repeat play
   if (hdl->start_time || hdl->current_time) {
      hdl->rbInfo.read = 0;
      hdl->rbInfo.write = 0;
      hdl->eof = false;
      ihdl->control = 0;
      ihdl->end_status = MEDIA_NONE;
      hdl->current_time = hdl->start_time;
   }
   hdl->LastRingBufferRead = 0;

   if (vmSeek(ihdl) == KAL_FALSE) {
      return MEDIA_SEEK_FAIL;
   }

   {
      uint32 buf_len=0;
      int32 get_len;
      uint8  *pBuf=NULL;
      FC_Buf *fcBufHdr;
      /*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/  
#if !(defined(MT6573) || defined(MT6575) || defined(MT6577))
      TONE_StopAndWait();
      KT_StopAndWait();
#endif

#ifdef BGSND_ENABLE
      if (vm_drv_sndOffHandler != NULL)
         vm_drv_sndOffHandler( vm_drv_sndHdl );
#endif
      /*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/ 
      
      hdl->GetWriteBuffer(hdl, &pBuf, &buf_len);
      buf_len &= 0xFFFFFFFE;
      get_len = autGetBytes(hdl, ihdl->pstFSAL, buf_len, pBuf);
      if (get_len < 0) {
         return MEDIA_READ_FAIL;
      } else if (get_len < buf_len) {
         hdl->eof = true;
      }
      hdl->WriteDataDone( hdl, get_len );
      
      mhdlDisallowSleep( hdl );      
      
      if(hdl->rbInfo.param==NULL)
      {
         hdl->rbInfo.param = (void *)L1Audio_FC_GetAudioBufferHeader();
      }
      L1Audio_FC_WriteBufferToDSP( &hdl->rbInfo );
      fcBufHdr = (FC_Buf *)hdl->rbInfo.param;
      SAC_SphPlayPar.pucRingBuf   = fcBufHdr->pBuf;
      SAC_SphPlayPar.u4RingBufLen = fcBufHdr->uBufLength;
      SAC_SphPlayPar.pucWritePtr  = fcBufHdr->pWrite;
      SAC_SphPlayPar.u4PlyMod     = 0;
      ihdl->mh.fc_aud_id = L1Audio_FC_HookHandler( (void *)ihdl, vmMsgHandler, 1, 0 );
      L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_IDLE_PLAY_START, ihdl->mh.fc_aud_id, (kal_uint32)&SAC_SphPlayPar, KAL_TRUE );
   }

   ret = vmWriteFrame(hdl, false);
   if (ret == MEDIA_SUCCESS) {
      /* Set Digital Gain for Voice Memo */
      AFE_SetDigitalGain( L1SP_VOICE, 100 );
      
      AM_VMPlaybackOn( ihdl->control, ihdl->param );

      ihdl->end_status = MEDIA_NONE;
      hdl->state = VM_STATE_PLAY;
   }
   kal_trace( TRACE_FUNC, L1AUDIO_PLAY_FILE, hdl->mediaType );

   return ret;
}

static Media_Status vmMFResumeFile( MHdl *hdl )
{
   return MEDIA_UNSUPPORTED_OPERATION;
}


static Media_Status vmMFPause( MHdl *hdl )
{
   return MEDIA_UNSUPPORTED_OPERATION;
}


static Media_Status vmMFStop( MHdl *hdl )
{
   vmMediaHdl *ihdl = (vmMediaHdl *)hdl;

   switch (hdl->state) {
      case VM_STATE_IDLE:
      case VM_STATE_PLAY_PAUSE:
         return MEDIA_SUCCESS;
      case VM_STATE_PLAY:
         L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_IDLE_PLAY_STOP, ihdl->mh.fc_aud_id, 0, KAL_TRUE );
         L1Audio_FC_UnHookHandler(ihdl->mh.fc_aud_id, 1);
         AM_VMPlaybackOff(ihdl->param);
         mhdlAllowSleep( hdl );         
         break;
      default:
         ASSERT(0);
   }

   ihdl->end_status = MEDIA_TERMINATED;
   hdl->state = VM_STATE_IDLE;
   kal_trace( TRACE_FUNC, L1AUDIO_STOP, hdl->mediaType );

   return MEDIA_SUCCESS;
}

static Media_Status vmMFClose( MHdl *hdl )
{
   ASSERT( (hdl != 0) && (hdl->state != VM_STATE_PLAY) );
   if(hdl->rbInfo.param)
   {
      L1Audio_FC_ReleaseAudioBufferHeader( (FC_Buf **) &hdl->rbInfo.param );
      hdl->rbInfo.param = NULL;
   }
   mhdlFinalize( hdl, 0 );

   free_ctrl_buffer( hdl );
   kal_trace( TRACE_FUNC, L1AUDIO_CLOSE, hdl->mediaType );

   return MEDIA_SUCCESS;
}


MHdl *VM_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param)
{
   MHdl *hdl;
   vmMediaHdl *ihdl;
   Media_VM_PCM_Param *vm_param = (Media_VM_PCM_Param *) param;

   ihdl = (vmMediaHdl*)get_ctrl_buffer( sizeof(vmMediaHdl) );
   memset(ihdl, 0, sizeof(vmMediaHdl));
   hdl = (MHdl *) ihdl;
   mhdlInitEx( hdl,  0, NULL );
   hdl = (MHdl *) ihdl;

   hdl->handler   = handler;
   ihdl->pstFSAL  = pstFSAL;

   hdl->mediaType = vm_param->mediaType;
#if IS_EV_BOARD
   ihdl->param  = (uint32)MEDIA_VMP_AS_SPEECH;
#else
   ihdl->param  = vm_param->vmParam;
#endif

   hdl->state     = VM_STATE_IDLE;
   hdl->Close     = vmMFClose;
   hdl->Pause     = vmMFPause;
   hdl->Stop      = vmMFStop;
   hdl->Process   = vmMFProcess;
   hdl->Play      = vmMFPlayFile;
   hdl->Resume    = vmMFResumeFile;

   kal_trace( TRACE_FUNC, L1AUDIO_OPEN_FILE, hdl->mediaType );

   return hdl;
}

Media_Status VM_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param )
{
   return MEDIA_BAD_COMMAND;
}

/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   
#ifdef BGSND_ENABLE
void VMDrv_Register_SndService(
   void (*onHandler)(void *hdl),
   void (*offHandler)(void *hdl),
   void *hdl)
{
   vm_drv_sndOnHandler  = onHandler;
   vm_drv_sndOffHandler = offHandler;
   vm_drv_sndHdl        = hdl;
}

void VMDrv_UnRegister_SndService( void )
{
   vm_drv_sndOnHandler  = NULL;
   vm_drv_sndOffHandler = NULL;
}
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   
#endif
