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
 * vm.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   VM recording/playback
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
#include "reg_base.h"
#include "l1audio_trace.h"
#include "string.h"
#include "kal_trace.h"               
#include "l1audio.h"
#include "audio_enum.h"
#include "l1audio_def.h"                     
#include "am.h" 
#include "media.h"
#include "afe.h"
#include "fc_def.h"
#include "exp_SphFasTypDef.h"
#include "l1audio_sph_trc.h"


#define VM_STATE_RECORD       0x1
#define VM_STATE_RECORD_PAUSE 0x2
#define VM_STATE_STOP         0x10 
#define VM_STATE_RECORD_STOP  0x20 // entering vmStop

/* ------------------------------------------------------------------------------ */
static struct{
   mediaControl   *ctrl;   
   uint16          type;
   int16          *vmBuf;    /* point to buffer for VM                              */   
   uint16         debug_info; /* 0  : vm (speech codec data) only                   */
                              /* b1 : record 1st set of UL-DL PCM buffer for SPE    */
                              /* b2 : record 2nd set of UL-DL PCM buffer for SPE    */ 
   uint8          state;
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   
#ifdef BGSND_ENABLE
   void (*sndOnHandler)(void *hdl); 
   void (*sndOffHandler)(void *hdl);
   void *sndHdl;
#endif     
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   
   
} vm;

#define VM_PCM_1ST_SET_RECORD_FLAG  0x1 
#define VM_PCM_2ND_SET_RECORD_FLAG  0x2
#define VM_APL_LOG_FLAG             0x4

/* ------------------------------------------------------------------------------ */

#define _EXTRA_LOG_FOR_BIT_TRUE_
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
extern kal_bool g_bNeedExtraLog;
#endif


__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI"))) 
SAC_SphRecordVmPar_t SAC_SphRecordVmPar;

extern kal_uint32 L1I_GetTimeStamp( void );


/* ------------------------------------------------------------------------------ */
static void vmRecMsgHandler(kal_uint16 msgOp, kal_uint32 msgData, void *userData)
{
   
   switch (msgOp) {
      case MSG_SAC2L1AUDIO_SPEECH_IDLE_RECORD_VM_START_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_CALL_RECORD_VM_START_ACK:
         #if !(defined(MT6573) || defined(MT6575) || defined(MT6577))
         ASSERT( FC_STATE_IDLE == vm.ctrl->fc_state);
         #endif
         vm.ctrl->fc_state = FC_STATE_RECORD;
         L1Audio_FC_SetWait(false);
         break;
      case MSG_SAC2L1AUDIO_SPEECH_IDLE_RECORD_VM_STOP_ACK:
	   case MSG_SAC2L1AUDIO_SPEECH_CALL_RECORD_VM_STOP_ACK:
         #if !(defined(MT6573) || defined(MT6575) || defined(MT6577))
         ASSERT( FC_STATE_RECORD == vm.ctrl->fc_state);
         #endif
         vm.ctrl->fc_state = FC_STATE_IDLE;
         L1Audio_FC_SetWait(false);
         break;
      case MSG_SAC2L1AUDIO_SPEECH_CALL_RECORD_VM_REQUEST_READ_DATA:
      case MSG_SAC2L1AUDIO_SPEECH_IDLE_RECORD_VM_REQUEST_READ_DATA:
      {
         SAS_SphOutputPar_t *vmBufPar = (SAS_SphOutputPar_t *)msgData;
         // Read data from shared buffer with FC.
         
         // Save to media buffer
         while( vmBufPar != NULL )
         {
            void *ptr;
            kal_uint16 *buf;
            kal_uint32 len;
            kal_int32 segment;
            
            Media_GetWriteBuffer(&buf ,&len);
            len = len << 1; // len in size of byte
            if( len >= vmBufPar->u4Len ){
               len = vmBufPar->u4Len;
            }
            {
               //Fill L1T here for VM
               kal_uint16* vmTime;
               kal_uint32 timeStamp;
               vmTime = (kal_uint16*)vmBufPar->pucBufPtr;
               vmTime += 2;//Jump 4 byte;
               timeStamp = L1I_GetTimeStamp();
			   /*
               #if defined(__DUAL_MIC_SUPPORT__)      
	            if(0 == SAC_SphRecordVmPar.u4AbfCal)
               #endif
               */
               {
               *vmTime++ = (uint16)(timeStamp & 0xFFFF);
               *vmTime = (uint16)(timeStamp>>16);
               }
            }
            memcpy( buf, vmBufPar->pucBufPtr, len );
            Media_WriteDataDone_NoWaiting( len >> 1 );
            segment = vmBufPar->u4Len - len;
            if( segment > 0 ){
               ptr = vmBufPar->pucBufPtr + len;
               Media_GetWriteBuffer(&buf ,&len);
               len = len << 1; // len in size of byte
               if( len > segment )
                  len = segment;
               memcpy( buf, ptr, len );
               Media_WriteDataDone_NoWaiting( len >> 1 );
            }
            vmBufPar = (SAS_SphOutputPar_t *)vmBufPar->pucNxtStrPtr;
         }
         // Notify FC to ack.
         mediaIncRecordTime();  //for update record time
         if(msgOp == MSG_SAC2L1AUDIO_SPEECH_CALL_RECORD_VM_REQUEST_READ_DATA)
            L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_CALL_RECORD_VM_REQUEST_READ_DATA_ACK, vm.ctrl->fc_aud_id, 0);
         else
            L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_IDLE_RECORD_VM_REQUEST_READ_DATA_ACK, vm.ctrl->fc_aud_id, 0);
         
         // Notify MED to empty media buffer
         mediaDataNotification();
         
         #if defined(__SMART_PHONE_MODEM__)         
         vmRecordHandler(msgOp, 4);
         #endif         

         break;
      }
      default:
         ASSERT(0);
   }
}

static void vocRecMsgHandler(kal_uint16 msgOp, kal_uint32 msgData, void *userData)
{
   switch(msgOp){
      case MSG_SAC2L1AUDIO_SPEECH_IDLE_RECORD_VM_START_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_CALL_RECORD_VM_START_ACK:
         #if !(defined(MT6573) || defined(MT6575) || defined(MT6577))
            ASSERT( FC_STATE_IDLE == vm.ctrl->fc_state);
         #endif
         vm.ctrl->fc_state = FC_STATE_RECORD;
         L1Audio_FC_SetWait(false);
         break;		 
      case MSG_SAC2L1AUDIO_SPEECH_IDLE_RECORD_VM_STOP_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_CALL_RECORD_VM_STOP_ACK:
         #if !(defined(MT6573) || defined(MT6575) || defined(MT6577))
            ASSERT( FC_STATE_RECORD == vm.ctrl->fc_state);
         #endif
         vm.ctrl->fc_state = FC_STATE_IDLE;
         L1Audio_FC_SetWait(false);
         break;
      case MSG_SAC2L1AUDIO_SPEECH_CALL_RECORD_VM_REQUEST_READ_DATA:
      case MSG_SAC2L1AUDIO_SPEECH_IDLE_RECORD_VM_REQUEST_READ_DATA:
      {
         SAS_SphOutputPar_t *vmBufPar = (SAS_SphOutputPar_t *)msgData;
         while(vmBufPar != NULL)
         {
            kal_uint8 *vmBuf = vmBufPar->pucBufPtr;
            kal_uint32 vmLen = vmBufPar->u4Len;
				
            kal_uint16* vmTime;
            kal_uint32 timeStamp;

            vmTime = (kal_uint16*)vmBufPar->pucBufPtr;
            vmTime += 2;
            timeStamp = L1I_GetTimeStamp();
            *vmTime++ = (uint16)(timeStamp & 0xFFFF);
            *vmTime = (uint16)(timeStamp>>16);

            kal_trace(TRACE_GROUP_VM, RECORD_LENGTH, vmLen);
            while(vmLen > 1000)
            {
               tst_vc_response(TVCI_VM_LOGGING, (const kal_uint8*)vmBuf, 1000);
               vmBuf += 1000;
               vmLen -= 1000;
            }
            tst_vc_response(TVCI_VM_LOGGING, (const kal_uint8*)vmBuf, vmLen);
            
            vmBufPar = (SAS_SphOutputPar_t *)vmBufPar->pucNxtStrPtr;
         }

         if(msgOp == MSG_SAC2L1AUDIO_SPEECH_CALL_RECORD_VM_REQUEST_READ_DATA)
            L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_CALL_RECORD_VM_REQUEST_READ_DATA_ACK, vm.ctrl->fc_aud_id, 0);
		 else
            L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_IDLE_RECORD_VM_REQUEST_READ_DATA_ACK, vm.ctrl->fc_aud_id, 0);
				 
         break;
      }
      default:
         ASSERT(0);
   }
}

extern void SP3G_Start_VM( void ); 
extern void SP3G_Stop_VM( void ); 
extern bool SP3G_VM_Status( void ); 

void vmSpeechOnHandler( void *state ) 
{
#if defined(__WCDMA_RAT__)
   SP3G_Start_VM();
#endif
   L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_CALL_RECORD_VM_START, vm.ctrl->fc_aud_id, (kal_uint32)&SAC_SphRecordVmPar, KAL_TRUE );
   AM_VMRecordOn( (uint16)vm.type );
}

void vmSpeechOffHandler( void *state ) 
{
   if( vm.state == VM_STATE_RECORD_PAUSE )
      return;
#if defined(__WCDMA_RAT__)
   SP3G_Stop_VM();
#endif
   L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_CALL_RECORD_VM_STOP, vm.ctrl->fc_aud_id, (kal_uint32)&SAC_SphRecordVmPar, KAL_TRUE );
   AM_VMRecordOff();
}

void vmRecord( mediaControl *ctrl, uint16 type )
{
   kal_uint32 module_id = MOD_L1AUDIO_SPH_SRV;

   vm.ctrl = ctrl;
   vm.type = type;
   vm.state = VM_STATE_RECORD;

   if( AM_IsSpeechOn() ) {
      vm.debug_info = L1Audio_GetDebugInfo(VM_DEBUG_INFO);

	  if(!tst_trace_check_ps_filter_off(TRACE_GROUP_EPL, &module_id, 0X2))
         vm.debug_info = 0x3;
		  
      SAC_SphRecordVmPar.u4RecCodUl = SAC_SphRecordVmPar.u4RecCodDl = type;
      SAC_SphRecordVmPar.u4VmStr   = 0;
      SAC_SphRecordVmPar.u4Dtx     = 1;
      //SAC_SphRecordVmPar.u4AbfCal  = 0;
      if(vm.debug_info & (VM_PCM_1ST_SET_RECORD_FLAG + VM_PCM_2ND_SET_RECORD_FLAG))
      {
         SAC_SphRecordVmPar.u4VmStr |= (1 << 2); // bit0: Hbit, bit1: Sout, bit2: Epl, bit3: FWLA, bit: ABF
      }
      else if( (vm.debug_info & VM_APL_LOG_FLAG) != 0 )
      {
         SAC_SphRecordVmPar.u4VmStr |= (1 << 5); //APL
      }
      
#if defined(__UMTS_RAT__)
      SP3G_Start_VM();
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
      g_bNeedExtraLog = KAL_TRUE;
#endif
#endif
      if(!tst_trace_check_ps_filter_off(TRACE_GROUP_VM, &module_id, 0x2))
         vm.ctrl->fc_aud_id = L1Audio_FC_HookHandler( (void *)0, vocRecMsgHandler, 1, 0 );
      else
         vm.ctrl->fc_aud_id = L1Audio_FC_HookHandler( (void *)0, vmRecMsgHandler, 1, 0 );
      L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_CALL_RECORD_VM_START, vm.ctrl->fc_aud_id, (kal_uint32)&SAC_SphRecordVmPar, KAL_TRUE );
      AM_VMRecordOn( (uint16)type );
      L1SP_Register_Service(vmSpeechOnHandler, vmSpeechOffHandler);
   }
   else {
      SAC_SphRecordVmPar.u4VmStr   = 0;
      SAC_SphRecordVmPar.u4Dtx     = 1;
	  /*
#if defined(__DUAL_MIC_SUPPORT__)
      if((L1Audio_GetDebugInfo(STEREO_RECORD_INFO) & 1)){
         if(type == 0){
             type = 0xb;   // WB codec
         }         
	      SAC_SphRecordVmPar.u4AbfCal  = 1; 
	      L1SP_SetULAGC(true);
	   } else {         
	      SAC_SphRecordVmPar.u4AbfCal  = 0; 	   
	   }
	   SAC_SphRecordVmPar.u4RecCodUl = type; 
#else
*/
      SAC_SphRecordVmPar.u4RecCodUl = type;
      //SAC_SphRecordVmPar.u4AbfCal  = 0;
//#endif	      
      vm.ctrl->fc_aud_id = L1Audio_FC_HookHandler( (void *)0, vmRecMsgHandler, 1, 0 );
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/
#if !(defined(MT6573) || defined(MT6575) || defined(MT6577)) 
      TONE_StopAndWait();
      KT_StopAndWait();
#endif
#ifdef BGSND_ENABLE
      if (vm.sndOffHandler != NULL)
         vm.sndOffHandler( vm.sndHdl );
#endif   
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/
      
      L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_IDLE_RECORD_VM_START, vm.ctrl->fc_aud_id, (kal_uint32)&SAC_SphRecordVmPar, KAL_TRUE );
      AM_VMRecordOn( (uint16)type );
   }
}

void vmStop( void )
{
   if(AM_IsSpeechOn())
      L1SP_UnRegister_Service();

   switch(vm.state) {
      case VM_STATE_RECORD_PAUSE:
         break;
      case VM_STATE_RECORD:
      case VM_STATE_RECORD_STOP:
         if(AM_IsSpeechOn())
            L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_CALL_RECORD_VM_STOP, vm.ctrl->fc_aud_id, 0, KAL_TRUE );
         else
            L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_IDLE_RECORD_VM_STOP, vm.ctrl->fc_aud_id, 0, KAL_TRUE );
         L1Audio_FC_UnHookHandler(vm.ctrl->fc_aud_id, 1);
         AM_VMRecordOff();
#if defined(__WCDMA_RAT__)
         if(SP3G_VM_Status())
            SP3G_Stop_VM();
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
         g_bNeedExtraLog = KAL_FALSE;
#endif
#endif
	/*
#if defined(__DUAL_MIC_SUPPORT__)
         if(SAC_SphRecordVmPar.u4AbfCal == 1) 
	         L1SP_SetULAGC(false);
#endif
	*/
         break;
      default:
         ASSERT(KAL_FALSE);
   }

   if( vm.vmBuf != NULL ){
      free_ctrl_buffer( vm.vmBuf );
      vm.vmBuf = NULL;
   }

   vm.state = VM_STATE_STOP;
}

void vmPause(mediaControl *ctrl)
{
   switch(vm.state) {
      case VM_STATE_RECORD:
#if defined(__UMTS_RAT__)
         if(SP3G_VM_Status())
            SP3G_Stop_VM();
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
         g_bNeedExtraLog = KAL_FALSE;
#endif
#endif
         if(AM_IsSpeechOn()){
            L1SP_UnRegister_Service();
            L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_CALL_RECORD_VM_STOP, vm.ctrl->fc_aud_id, 0, KAL_TRUE );
         }
         else
            L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_IDLE_RECORD_VM_STOP, vm.ctrl->fc_aud_id, 0, KAL_TRUE );
         L1Audio_FC_UnHookHandler( vm.ctrl->fc_aud_id, 1 );
         AM_VMRecordOff();
         vm.state = VM_STATE_RECORD_PAUSE;
         break;
      default:
         ASSERT(KAL_FALSE);
   }
}

void vmResume(mediaControl *ctrl)
{
   switch(vm.state) {
      case VM_STATE_RECORD_PAUSE:
#if defined(__UMTS_RAT__)
         SP3G_Start_VM();
#if defined(_EXTRA_LOG_FOR_BIT_TRUE_)
         g_bNeedExtraLog = KAL_TRUE;
#endif
#endif
         vm.ctrl->fc_aud_id = L1Audio_FC_HookHandler( (void *)0, vmRecMsgHandler, 1, 0 );
         if(AM_IsSpeechOn()){
            L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_CALL_RECORD_VM_START, vm.ctrl->fc_aud_id, (kal_uint32)&SAC_SphRecordVmPar, KAL_TRUE );
            L1SP_Register_Service(vmSpeechOnHandler, vmSpeechOffHandler);
         }
         else{
            /*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/            
            #if !(defined(MT6573) || defined(MT6575) || defined(MT6577))
            TONE_StopAndWait();
            KT_StopAndWait();
            #endif
            #ifdef BGSND_ENABLE
            if (vm.sndOffHandler != NULL)
               vm.sndOffHandler( vm.sndHdl );
            #endif            
            /*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/
            
            L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_IDLE_RECORD_VM_START, vm.ctrl->fc_aud_id, (kal_uint32)&SAC_SphRecordVmPar, KAL_TRUE );
         }
         AM_VMRecordOn( (uint16)vm.type );
         vm.state = VM_STATE_RECORD;
         break;
      default:
         ASSERT(KAL_FALSE);
   }
}

/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   
#ifdef BGSND_ENABLE
void vm_Register_SndService(
   void (*onHandler)(void *hdl),
   void (*offHandler)(void *hdl),
   void *hdl)
{
   vm.sndOnHandler  = onHandler;
   vm.sndOffHandler = offHandler;
   vm.sndHdl        = hdl;
}

void vm_UnRegister_SndService( void )
{
   vm.sndOnHandler  = NULL;
   vm.sndOffHandler = NULL;
}
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   
#endif
