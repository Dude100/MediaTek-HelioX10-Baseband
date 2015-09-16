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
 * l1audio_service.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   L1SP Task / L1Audio Service 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "reg_base.h"
#include "l1_interface.h"
#include "l1sm_public.h"
#include "intrCtrl.h"
#include "kal_trace.h"
#include "string.h"
#include "kal_public_defs.h"
#include "syscomp_config.h"
#include "l1audio_trace.h"
               
#include "l1audio.h"
#include "audio_enum.h"
#include "l1audio_def.h"
#include "fc_def.h"
#include "media.h"
#include "am.h"
#include "afe.h"
#include "mdci.h"
#include "exp_SphFasTypDef.h"
#include "l1sp_trc.h"
#include "us_timer.h"
#include "hisr_config.h"
#include "pcm4way.h"


#if defined( __UMTS_RAT__ )
#define  MAX_HISR_HANDLER        6
#else
#define  MAX_HISR_HANDLER        5
#endif

uint32 SaveAndSetIRQMask( void );
void   RestoreIRQMask( uint32 );
void toneLoopbackRecInit( void );
extern void DisableIRQ(void);

#ifdef MTK_SLEEP_ENABLE
#define  GET_SLEEP_HANDLE()   {  l1audio.sleep_handle=L1SM_GetHandle();       }
#define  SLEEP_LOCK()         {  L1SM_SleepDisable( l1audio.sleep_handle );   }
#define  SLEEP_UNLOCK()       {  L1SM_SleepEnable( l1audio.sleep_handle );    }
#else /* MTK_SLEEP_ENABLE */
#define  GET_SLEEP_HANDLE()
#define  SLEEP_LOCK()
#define  SLEEP_UNLOCK()
#endif /* MTK_SLEEP_ENABLE */

extern uint32 L1I_GetTimeStamp( void );
/* ------------------------------------------------------------------------------ */

static struct {
   uint32                 state;
   kal_eventgrpid         aud_events;
   kal_eventgrpid         audH_events;
   uint16                 media_flag;
   uint16                 d2c_itype;
   uint32                 d2c_l1FN;
   uint32                 retrieved_events;
   uint32                 retrievedH_events;
   uint32                 events_l1FN;
   kal_hisrid             hisr;
                          
   L1Audio_EventHandler   evHandler[MAX_AUDIO_FUNCTIONS];
   void                   *evData[MAX_AUDIO_FUNCTIONS];
   uint32                 id_flag;
   uint32                 event_flag;
   L1Audio_EventHandler   hisrHandler[MAX_HISR_HANDLER];
   uint16                 hisrMagicNo[MAX_HISR_HANDLER];
   void                   *hisrUserData[MAX_HISR_HANDLER];
   uint16                 hisrMagicFlag;
   uint8                  sleep_handle;
                          
   int8                   dsp_slow_idle_counter;
                          
   uint16                 debug_info[NUM_DEBUG_INFO];
                           
   uint16                 aud_id;
   MsgRingBuffer          msgQueue;
                          
   MsgIDHandler           msgIdHdl[MAX_CURRENCY_ID];
   kal_semid              sema;
   kal_semid              mdci_sema;
   kal_int32              mdciErrMsg;
   kal_bool               waiting;
   kal_bool               isTaskInitialize;
   AckMsgElement          ack;
   
   // For High Priority Task
   uint16                 audH_id;
   MsgRingBuffer          msgQueueH;
   
} l1audio;

#define AUDIO_BUFFER_INSTANCE_MAX 2

static struct {
   kal_bool fUsed[AUDIO_BUFFER_INSTANCE_MAX];
} audio_drv_mem_manager;

#ifdef L1D_TEST
kal_uint16 sphOnId;
kal_uint16 sphOffId;
kal_uint16 AudSys_Cosim_Id;
#endif
kal_uint32 g_type = 0;

/* ------------------------------------------------------------------------------ */

#define AUDIO_BUFFER_SIZE 5*1024
#define IPS_BUFFER_SIZE   1*1024

#define DSP_SHARE_SIZE 0x5000
__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI"))) 
   char DM_DSP_MEM[DSP_SHARE_SIZE];
__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI"))) 
   static FC_Buf Audio_Buffer_Header[AUDIO_BUFFER_INSTANCE_MAX];
#if __DRIVER_PRESERVE_DSP_SHARE_BUFFER__
__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI"))) 
   static kal_char Audio_Buffer[AUDIO_BUFFER_INSTANCE_MAX][AUDIO_BUFFER_SIZE];
#endif

extern kal_uint32 L1I_GetTimeStamp( void );

/****** Core for message ring buffer ******/

static void MsgQueue_Init( MsgRingBuffer *pQueue )
{
   pQueue->read = pQueue->write = 0;
}

static void MsgQueue_Get( MsgRingBuffer *pQueue, kal_uint32 *id, kal_uint32 *data )
{
   // Not NULL
   ASSERT( pQueue->read != pQueue->write );
   
   // Get value
   *id   = pQueue->queue[pQueue->read & (MSG_RB_SIZE-1)].msgID;
   *data = pQueue->queue[pQueue->read & (MSG_RB_SIZE-1)].msgData;
   pQueue->queue[pQueue->read & (MSG_RB_SIZE-1)].getTime = L1I_GetTimeStamp();
   pQueue->read++;
}

static void MsgQueue_Put( MsgRingBuffer *pQueue, kal_uint32 id, kal_uint32 data )
{
   // Not Full
   ASSERT( (pQueue->write - pQueue->read) < MSG_RB_SIZE );
   
   // Put value
   pQueue->queue[pQueue->write & (MSG_RB_SIZE-1)].msgID   = id;
   pQueue->queue[pQueue->write & (MSG_RB_SIZE-1)].msgData = data;
   pQueue->queue[pQueue->write & (MSG_RB_SIZE-1)].putTime = L1I_GetTimeStamp();
   pQueue->write++;
}


/****** Code for Dual MAC DSP, related to MDCI ******/

static void Mcu2Sac_send_message(
   kal_uint32 msgID,
   kal_uint32 msgData
)
{
   kal_uint32 i = 0;

   kal_take_sem( l1audio.mdci_sema, KAL_INFINITE_WAIT );

   l1audio.mdciErrMsg = mdci_mailbox_write_with_reserved(MDCI_AUDIO_CHANNEL_M2D, msgID, msgData);

   while( l1audio.mdciErrMsg != MDCI_SUCCESS ){
      kal_trace( TRACE_INFO, L1AUDIO_MDCI_M2D_MSG, msgID, msgID>>16, msgData, l1audio.msgQueue.read, l1audio.msgQueue.write, l1audio.mdciErrMsg );
      kal_brief_trace (TRACE_INFO, L1AUDIO_MDCI_ERR_MSG, l1audio.mdciErrMsg);

      ASSERT( i++ != 5 );
      kal_sleep_task(1);
      l1audio.mdciErrMsg = mdci_mailbox_write_with_reserved(MDCI_AUDIO_CHANNEL_M2D, msgID, msgData);
   }

   kal_trace( TRACE_INFO, L1AUDIO_MDCI_M2D_MSG, msgID, msgID>>16, msgData, l1audio.msgQueue.read, l1audio.msgQueue.write, l1audio.mdciErrMsg );

   kal_give_sem( l1audio.mdci_sema );
}

static void AudioH_SendMessageHandler( void *data )
{
   // Process all messages
   while (l1audio.msgQueueH.read != l1audio.msgQueueH.write) {
      kal_uint32 magID32, msgData32;
      
      // Get message
      MsgQueue_Get(&l1audio.msgQueueH, &magID32, &msgData32);
      
      Mcu2Sac_send_message(magID32, msgData32);
   }
}

void L1Audio_SetEventH( uint16 audio_id, void *data )
{
   l1audio.evData[audio_id] = data;
   kal_set_eg_events( l1audio.audH_events, 1 << audio_id, KAL_OR );
}

// Dummy function: MCU to SAC (Dual MAC DSP)
static void MCU2SAC_hisr(MDCI_BUFF_T *bufp)
{

}

// Move to higher
static void AHA_GetID( kal_uint32 msgID16, kal_uint32 msgData16, kal_uint32 msgData32 )
{
   // To keep the audio ID
   l1audio.ack.msgID16   = msgID16;
   l1audio.ack.msgData16 = msgData16;
   l1audio.ack.msgData32 = msgData32;
}

/* get the id of the MDIF mailbox buffer */
#define MDCI_MAILBOX_RESERVE(buff)   (((MDCI_BUFF_T *)(buff))->reserved)

static void AHA_DataRequest( kal_uint32 msgID16, kal_uint32 msgData16, kal_uint32 msgData32 );

// To handle the message from SAC to MCU
static void SAC2MCU_hisr(MDCI_BUFF_T *bufp)
{
   kal_uint32 msgID, msgData;
   kal_uint32 msg16;

   /* confirm the channel buffer type */
   if (!MDCI_IS_MAILBOX(bufp)) {
       ASSERT(0);
   }

   /* get the mailbox id and reserved data */
   msgID = MDCI_MAILBOX_ID(bufp);
   msgData = MDCI_MAILBOX_RESERVE(bufp);

   /* Put message to queue and activate l1audio task */
   kal_dev_trace( TRACE_INFO, L1AUDIO_MDCI_D2M_MSG, msgID, msgID>>16, msgData, l1audio.msgQueue.read, l1audio.msgQueue.write );
   MsgQueue_Put(&l1audio.msgQueue, msgID, msgData);

   msg16 = msgID>>16;
   if (msg16 == MSG_SAC2L1AUDIO_AUDIO_DATA_REQUEST) {
      // Data request
      AHA_DataRequest( msg16, (msgID << 16) >> 16, msgData );
   }

   msg16 = msgID>>16;
   if( (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_GET_ID_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_AUDIO_GET_ID_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_SET_MODE_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_ENHANCEMENT_SET_PAR_ACK) ||      
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_CONFIG_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_2G_CALL_ON_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_2G_CALL_OFF_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_3G_CALL_ON_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_3G_CALL_OFF_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_CALLPCM4WAY_OPEN_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_IDLEPCM4WAY_START_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_CALLPCM4WAY_CLOSE_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_IDLEPCM4WAY_STOP_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_CALLPCM2WAY_OPEN_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_CALLPCM2WAY_CLOSE_ACK) ||       
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_IDLEPCM2WAY_START_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_IDLEPCM2WAY_STOP_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_IDLE_PLAY_START_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_CALL_RECORD_VM_START_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_CALL_RECORD_VM_STOP_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_IDLE_RECORD_VM_START_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_IDLE_RECORD_VM_STOP_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_IDLE_PLAY_STOP_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_IDLE_PLAY_START_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_FREE_ID_ACK) || 
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_IDLE_RECORD_PCM_START_ACK)  ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_CALL_RECORD_PCM_START_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_IDLE_RECORD_PCM_STOP_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_CALL_RECORD_PCM_STOP_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_DMNR_SET_PAR_ACK) ||  
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_CODEC_LBK_OPEN_ACK) ||   
       (msg16 ==  MSG_SAC2L1AUDIO_SPEECH_CODEC_LBK_CLOSE_ACK) ||                                          
       (msg16 ==  MSG_SAC2L1AUDIO_AUDIO_GET_ID_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_AUDIO_PLAYBACK_ON_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_AUDIO_PLAYBACK_OFF_ACK) ||
       (msg16 ==  MSG_SAC2L1AUDIO_AUDIO_FREE_ID_ACK))
   {
      l1audio.waiting = false;
   } 

   if ((msg16 == MSG_SAC2L1AUDIO_SPEECH_GET_ID_ACK) ||
       (msg16 == MSG_SAC2L1AUDIO_AUDIO_GET_ID_ACK) )
   {
         AHA_GetID( msg16, (msgID << 16) >> 16, msgData ); 
   }

   L1Audio_SetEvent( l1audio.aud_id, (void *)0 );
}

/****** Code for Message Handling ******/
static kal_uint32 aha_FindExistAudioIndex( kal_uint16 aud_id )
{
   kal_uint32 I;
   
   for (I = 0; I < MAX_CURRENCY_ID; I++) {
      if ( ( l1audio.msgIdHdl[I].isUsed == true ) && (l1audio.msgIdHdl[I].aud_id == aud_id) ) {
         break;
      }
   }

   return I;
}

static void AHA_FreeID( kal_uint32 msgID16, kal_uint32 msgData16, kal_uint32 msgData32 )
{

}

static void AHA_OnOff( kal_uint32 msgID16, kal_uint32 msgData16, kal_uint32 msgData32 )
{
   kal_uint32 I;
   void *userData;
   
   // Find out the position of audio ID
   I = aha_FindExistAudioIndex( msgData16 );

   if (I != MAX_CURRENCY_ID)
   {
      ASSERT( I != MAX_CURRENCY_ID );
      
      // Execute the user handler
      userData = l1audio.msgIdHdl[I].userData;
      l1audio.msgIdHdl[I].userMsgHandler(msgID16, msgData32, userData);
      
      // To clear waiting flag, and then MED task could be executed.
      if (msgID16 == MSG_SAC2L1AUDIO_AUDIO_PLAYBACK_OFF_ACK) {
      	  if ( Tone_KT_CheckWait(msgData16) )
      	     l1audio.waiting = false;
      }
   }
}

static void AHA_WriteData( kal_uint32 msgID16, kal_uint32 msgData16, kal_uint32 msgData32 )
{
   kal_uint32 I;
   void *userData;
   
   // Find out the position of audio ID
   I = aha_FindExistAudioIndex( msgData16 );
   //ASSERT( I != MAX_CURRENCY_ID );
   
   if (I < MAX_CURRENCY_ID)
   {	
   // Execute the user handler
   userData = l1audio.msgIdHdl[I].userData;
   l1audio.msgIdHdl[I].userMsgHandler(msgID16, msgData32, userData);
   }
}

static void AHA_DataRequest( kal_uint32 msgID16, kal_uint32 msgData16, kal_uint32 msgData32 )
{
   kal_uint32 I;
   void *userData;
   
   // Find out the position of audio ID
   I = aha_FindExistAudioIndex( msgData16 );
   
   // Execute the user handler
   if (I < MAX_CURRENCY_ID)
   {	
      userData = l1audio.msgIdHdl[I].userData;
      l1audio.msgIdHdl[I].userMsgHandler(msgID16, msgData32, userData);
   }
}

static void AHA_DataNotify( kal_uint32 msgID16, kal_uint32 msgData16, kal_uint32 msgData32 )
{
   kal_uint32 I;
   void *userData;
   
   // Find out the position of audio ID
   I = aha_FindExistAudioIndex( msgData16 );
   
   if (I < MAX_CURRENCY_ID)
   {
      // Execute the user handler
      userData = l1audio.msgIdHdl[I].userData;
      l1audio.msgIdHdl[I].userMsgHandler(msgID16, msgData32, userData);
   }
}

static void AHA_SetDevice( kal_uint32 msgID16, kal_uint32 msgData16, kal_uint32 msgData32 )
{
   kal_uint32 I;
   void *userData;
   
   // Find out the position of audio ID
   I = aha_FindExistAudioIndex( msgData16 );
   
   if (I < MAX_CURRENCY_ID)
   {	
      // Execute the user handler
      userData = l1audio.msgIdHdl[I].userData;
      l1audio.msgIdHdl[I].userMsgHandler(msgID16, msgData32, userData);
   }
}

static void AHA_SetPlayRate( kal_uint32 msgID16, kal_uint32 msgData16, kal_uint32 msgData32 )
{
   // To clear waiting flag, and then MED task could be executed.
   l1audio.waiting = false;
}

static void AHA_AVSyncInit( kal_uint32 msgID16, kal_uint32 msgData16, kal_uint32 msgData32 )
{
   // To clear waiting flag, and then MED task could be executed.
   l1audio.waiting = false;
}

static void AHA_AVSyncNotify( kal_uint32 msgID16, kal_uint32 msgData16, kal_uint32 msgData32 )
{
   L1Audio_PutMessage(MSG_L1AUDIO2FAS_AUDIO_AVSYNC_NOTIFY_ACK, msgData16, 0);
}

// To handle speech message
static void Sac2Mcu_Speech_MsgHandler(
   kal_uint32 msgID16,
   kal_uint32 msgData16,
   kal_uint32 msgData32
)
{
   kal_trace(TRACE_INFO, L1AUDIO_MDCI_PROCESS_D2M_MSG, msgID16, msgID16, msgData16, msgData32);
   switch (msgID16) {
      case MSG_SAC2L1AUDIO_QUERY_DSP_VERSION_ACK:
         ASSERT(DSP_VERSION == msgData32);
         break;
      case MSG_SAC2L1AUDIO_SPEECH_GET_ID_ACK:
         AHA_GetID( msgID16, msgData16, msgData32 );
         break;
      case MSG_SAC2L1AUDIO_SPEECH_FREE_ID_ACK:
         AHA_FreeID( msgID16, msgData16, msgData32 );
         break;
      case MSG_SAC2L1AUDIO_SPEECH_CONFIG_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_SET_MODE_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_ENHANCEMENT_SET_PAR_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_2G_CALL_ON_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_2G_CALL_OFF_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_MLBK_OPEN_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_MLBK_CLOSE_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_SLBK_OPEN_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_SLBK_CLOSE_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_CODEC_LBK_OPEN_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_CODEC_LBK_CLOSE_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_GET_TIME_ON_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_GET_TIME_OFF_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_DMNR_SET_PAR_ACK:         
         break;

#ifdef L1D_TEST
      case MSG_SAC2L1AUDIO_SPEECH_MLBK_RESULT:
         {
            extern void L1DTest_SetSpeechStatusResult( uint8 ok );
            L1DTest_SetSpeechStatusResult( (uint8)msgData16 );
         }
         //add to L1 message
         break;
#endif
      case MSG_SAC2L1AUDIO_SET_M2D_MEM_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_MUTE_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_UNMUTE_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_ENABLE_SIDETONE_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_DISABLE_SIDETONE_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_HANDOVER_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_BT_CONFIG_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_SET_UL_VOLUME_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_SET_DL_VOLUME_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_SET_SIDETONE_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_UPDATE_UL_CODEC_RATE_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_UPDATE_DL_CODEC_RATE_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_ECHO_LOOP_TEST_START_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_ECHO_LOOP_TEST_STOP_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_CTM_NOTIFY_ON_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_CTM_NOTIFY_OFF_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_CTM_CONFIG_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_SET_UL_DEVICE_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_SET_DL_DEVICE_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_BKG_SOUND_SET_DLGAIN_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_BKG_SOUND_SET_ULGAIN_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_DL_GAIN_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_UL_GAIN_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_ENABLE_DTX_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_DISABLE_DTX_ACK: 
      case MSG_SAC2L1AUDIO_SPEECH_SET_AGC_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_SET_UL_IIR_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_MUTE_UPLINK_BY_FRAME_ACK:
	  case MSG_SAC2L1AUDIO_SPEECH_ENHANCEMENT_SET_SUB_FEATURE_ACK:
         break;
      default:
      {
         int32 I;
         void *userData;
         ASSERT( msgData16 <= MAX_CURRENCY_ID );
         I = aha_FindExistAudioIndex( msgData16 );
   
         if (I < MAX_CURRENCY_ID)
         {
            // Execute the user handler
            userData = l1audio.msgIdHdl[I].userData;
            if (l1audio.msgIdHdl[I].userMsgHandler)
            {
                l1audio.msgIdHdl[I].userMsgHandler(msgID16, msgData32, userData);
            }    
         }
      }
   }
}

// To handle audio message
static void Sac2Mcu_Audio_MsgHandler(
   kal_uint32 msgID16,
   kal_uint32 msgData16,
   kal_uint32 msgData32
)
{
   kal_trace(TRACE_INFO, L1AUDIO_MDCI_PROCESS_D2M_MSG, msgID16, msgID16, msgData16, msgData32);
   switch (msgID16) {
      case MSG_SAC2L1AUDIO_AUDIO_GET_ID_ACK:
         AHA_GetID( msgID16, msgData16, msgData32 );
         break;
      case MSG_SAC2L1AUDIO_AUDIO_FREE_ID_ACK:
         AHA_FreeID( msgID16, msgData16, msgData32 );
         break;
      case MSG_SAC2L1AUDIO_AUDIO_PLAYBACK_ON_ACK:
      case MSG_SAC2L1AUDIO_AUDIO_PLAYBACK_OFF_ACK:
      case MSG_SAC2L1AUDIO_AUDIO_RECORD_ON_ACK:
      case MSG_SAC2L1AUDIO_AUDIO_RECORD_OFF_ACK:
      case MSG_SAC2L1AUDIO_AUDIO_TONE_PLAYBACK_ON_ACK:
         AHA_OnOff( msgID16, msgData16, msgData32 );
         break;
      case MSG_SAC2L1AUDIO_AUDIO_WRITE_DATA_ACK:
         AHA_WriteData( msgID16, msgData16, msgData32 );
         break;
      case MSG_SAC2L1AUDIO_AUDIO_DATA_REQUEST:
         break;
      case MSG_SAC2L1AUDIO_AUDIO_DATA_NOTIFICATION:
         AHA_DataNotify( msgID16, msgData16, msgData32 );
         break;
      case MSG_SAC2L1AUDIO_AUDIO_SET_OUTPUT_DEVICE_ACK:
         AHA_SetDevice(msgID16, msgData16, msgData32);
         break;
      case MSG_SAC2L1AUDIO_AUDIO_SET_OUTPUT_VOLUME_ACK:
      case MSG_SAC2L1AUDIO_AUDIO_SET_INPUT_DEVICE_ACK:
      case MSG_SAC2L1AUDIO_AUDIO_SET_INPUT_VOLUME_ACK:
      case MSG_SAC2L1AUDIO_AUDIO_SET_STEREO2MONO_ACK:
      case MSG_SAC2L1AUDIO_AUDIO_SET_TONE_VOLUME_ACK: 
         break;
      case MSG_SAC2L1AUDIO_AUDIO_SET_PLAY_RATE_ACK:
         AHA_SetPlayRate( msgID16, msgData16, msgData32 );
         break;
      case MSG_SAC2L1AUDIO_AUDIO_AVSYNC_INITIALIZE_ACK:
         AHA_AVSyncInit( msgID16, msgData16, msgData32 );
         break;
      case MSG_SAC2L1AUDIO_AUDIO_AVSYNC_SET_INTERVAL_ACK:
         break;
      case MSG_SAC2L1AUDIO_AUDIO_AVSYNC_NOTIFY:
         AHA_AVSyncNotify( msgID16, msgData16, msgData32 );
         break;
      case MSG_SAC2L1AUDIO_HW_I2S_IN_CLOCK_MODE_ACK:
         break;
      default:
         // No such message
         ASSERT(0);
   }
}

#ifdef L1D_TEST
void AudSysCosimHandler(
   kal_uint32 msgID16,
   kal_uint32 msgData16,
   kal_uint32 msgData32
)
{
   extern void L1D_AudSys_Callback( kal_uint32 msgID16, kal_uint32 msgData16 );
   switch (msgID16) {
      case MDCIMSG_FAS2L1D_COSIM_IRQ_TEST_ACK:
      case MDCIMSG_FAS2L1D_COSIM_MEMIF_TEST_ACK:
      case MDCIMSG_FAS2L1D_COSIM_DLSRC_TEST_ACK:
      case MDCIMSG_FAS2L1D_COSIM_ULSRC_TEST_ACK:
         
         L1D_AudSys_Callback( msgID16, msgData16 );
         break;
      default:
         break;
   }
}
#endif

void l1audio_MsgHandlerV2( void *data )
{
   kal_bool print_log = KAL_FALSE;
   if(l1audio.msgQueue.read != l1audio.msgQueue.write){
      print_log = KAL_TRUE;
      kal_trace(TRACE_INFO, L1AUDIO_ENTER_MSG_HANDLER);
   }
   // Process all messages
   while (l1audio.msgQueue.read != l1audio.msgQueue.write) {
      kal_uint32 magID32, msgID16, msgData16, msgData32;
 
      // Get message
      MsgQueue_Get(&l1audio.msgQueue, &magID32, &msgData32);
      
      // Separate message into fields
      msgID16   = magID32 >> 16;
      msgData16 = (magID32<<16)>>16;

      // Distinguish the direction and message type between MCU and Dual MAC DSP
      switch (msgID16 & 0xF000) {
         case MDCIMSG_L1AUDIO2FAS_SPEECH_BASE:
         case MDCIMSG_L1AUDIO2FAS_AUDIO_BASE:
         case MDCIMSG_L1AUDIO2FAS_HW_BASE:
            // 20100604 KH erase
            //Mcu2Sac_send_message(magID32, msgData32);
            break;
         case MDCIMSG_SAC2L1AUDIO_SPEECH_BASE:
            Sac2Mcu_Speech_MsgHandler(msgID16, msgData16, msgData32);
            break;
         case MDCIMSG_SAC2L1AUDIO_AUDIO_BASE:
            Sac2Mcu_Audio_MsgHandler(msgID16, msgData16, msgData32);
            break;
         case MDCIMSG_SAC2L1AUDIO_HW_BASE:
            break;
#ifdef L1D_TEST
         case MDCIMSG_L1D2FAS_COSIM_BASE:
            // 20100604 KH erase
            //Mcu2Sac_send_message(magID32, msgData32);
            break;
         case MDCIMSG_FAS2L1D_COSIM_BASE:
            AudSysCosimHandler( msgID16, msgData16, msgData32 );
            break;
#endif
         default:
            // Undefined message category
            ASSERT(0);
      }
   }
   if( print_log == KAL_TRUE)
      kal_trace(TRACE_INFO, L1AUDIO_ENTER_MSG_HANDLER);
}

// To handle message in l1audio task
static void l1audio_MsgHandler( void *data )
{
   // Process all messages
   while (l1audio.msgQueue.read != l1audio.msgQueue.write) {
      kal_uint32 magID32, msgID16, msgData16, msgData32;
      
      // Get message
      MsgQueue_Get(&l1audio.msgQueue, &magID32, &msgData32);
      
      // Separate message into fields
      msgID16   = magID32 >> 16;
      msgData16 = (magID32<<16)>>16;
      
      // Distinguish the direction and message type between MCU and Dual MAC DSP
      switch (msgID16 & 0xF000) {
         case MDCIMSG_L1AUDIO2FAS_SPEECH_BASE:
         case MDCIMSG_L1AUDIO2FAS_HW_BASE:
         case MDCIMSG_L1AUDIO2FAS_AUDIO_BASE:
            break;
         case MDCIMSG_SAC2L1AUDIO_SPEECH_BASE:
            Sac2Mcu_Speech_MsgHandler(msgID16, msgData16, msgData32);
            break;
         case MDCIMSG_SAC2L1AUDIO_AUDIO_BASE:
            Sac2Mcu_Audio_MsgHandler(msgID16, msgData16, msgData32);
            break;
         case MDCIMSG_SAC2L1AUDIO_HW_BASE:
            break;
#ifdef L1D_TEST
         case MDCIMSG_L1D2FAS_COSIM_BASE:
            break;
         case MDCIMSG_FAS2L1D_COSIM_BASE:
            AudSysCosimHandler( msgID16, msgData16, msgData32 );
            break;
#endif
         default:
            // Undefined message category
            ASSERT(0);
      }
   }
}

void L1Audio_PutMessage( kal_uint16 msgID16, kal_uint16 msgData16, kal_uint32 msgData32)
{
   kal_uint32 savedMask;
   kal_uint32 msgID;
   
   msgID = (msgID16<<16) | msgData16;
   
   // Disable to avoid race condition between task and HISR
   savedMask = SaveAndSetIRQMask();
   MsgQueue_Put(&l1audio.msgQueueH, msgID, msgData32);
   RestoreIRQMask( savedMask );

   L1Audio_SetEventH( l1audio.audH_id, (void *)0 );
}

void L1Audio_PutMessageAndWait( kal_uint16 msgID16, kal_uint16 msgData16, kal_uint32 msgData32, kal_bool waiting )
{
   kal_uint16 I;
   kal_take_sem( l1audio.sema, KAL_INFINITE_WAIT );
   
   if( waiting )
      l1audio.waiting = true;
   L1Audio_PutMessage(msgID16, msgData16, msgData32);
#ifndef L1D_TEST
   if( waiting ){
      // Waiting for acknowledge
      for (I = 0; ; I++) {
         if (l1audio.waiting == false)
            break;
         
         ASSERT_REBOOT( I < 120 );
         kal_sleep_task( 1 );
      }
   }
#endif
   kal_give_sem( l1audio.sema );
}


extern SAC_SphEnhancementPar_t SAC_SphEnhancementPar;
#ifdef L1D_TEST
static void l1audio_sphOnHandler( void *data  )
{
   uint32 i;
   
   L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_DL_VOLUME, 0x1000, 128 );
   L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_UL_VOLUME, 0x1000, 128 );
   L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_SIDETONE, 0x200, 0);
   //Force using specific setting by Wego's request
   
   L1SP_LoadSpeechPara();
   SAC_SphEnhancementPar.au4SwitchUl[SPH_ENH_MODE_BKF] = 1;
   SAC_SphEnhancementPar.au4SwitchDl[SPH_ENH_MODE_BKF] = 1;
   SAC_SphEnhancementPar.au4SwitchUl[SPH_ENH_MODE_AEC] = 0;
   SAC_SphEnhancementPar.au4SwitchDl[SPH_ENH_MODE_AEC] = 0;
   SAC_SphEnhancementPar.au4SwitchUl[SPH_ENH_MODE_NDC] = 0;
   SAC_SphEnhancementPar.au4SwitchDl[SPH_ENH_MODE_NDC] = 0;
   SAC_SphEnhancementPar.au4SwitchUl[SPH_ENH_MODE_DMNR] = 0;
   SAC_SphEnhancementPar.au4SwitchDl[SPH_ENH_MODE_DMNR] = 0;
   SAC_SphEnhancementPar.au4SwitchUl[SPH_ENH_MODE_DGA] = 1;
   SAC_SphEnhancementPar.au4SwitchDl[SPH_ENH_MODE_DGA] = 1;
   SAC_SphEnhancementPar.au4SwitchUl[SPH_ENH_MODE_PLC] = 0;
   SAC_SphEnhancementPar.au4SwitchDl[SPH_ENH_MODE_PLC] = 0;

   L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_DISABLE_SIDETONE, 0, 0 );
   L1Audio_PutMessageAndWait( MSG_L1AUDIO2FAS_SPEECH_ENHANCEMENT_SET_PAR, sizeof(SAC_SphEnhancementPar_t), (kal_uint32)&SAC_SphEnhancementPar, KAL_TRUE );
   L1Audio_PutMessageAndWait( MSG_L1AUDIO2FAS_SPEECH_MLBK_OPEN, (kal_uint16)(kal_uint32)data, 0, KAL_TRUE);
   
   L1SP_Speech_On(RAT_2G_MODE);
}
static void  l1audio_sphOffHandler( void *data  )
{
   L1Audio_PutMessageAndWait( MSG_L1AUDIO2FAS_SPEECH_MLBK_CLOSE, 0, 0, KAL_TRUE );
   L1SP_Speech_Off();
}

static void l1audio_AudSysCosimHandler( void *data )
{
   L1Audio_PutMessage( (kal_uint32)data, 0, 0 );
}
#endif
/****** API for Media Task ******/

// To get audio ID and hook message handle
kal_uint16 L1Audio_FC_HookHandler( void *userData, L1Audio_MsgIDHandler userHandler, kal_uint16 type, kal_uint16 msg16 )
{
   kal_uint16 aud_id;
   int32 I;
   kal_take_sem( l1audio.sema, KAL_INFINITE_WAIT );
   
   l1audio.waiting = true;
   if(type == 0){
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_AUDIO_GET_ID, msg16>>8, msg16&0xFF);
   }else{
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_GET_ID, 0, 0);
   }
      
#ifdef L1D_TEST
   l1audio.waiting = false;
   aud_id = 0; //assume only one function work in L1D_TEST
#else
   // Waiting for acknowledge
   for (I = 0; ; I++) {
      if (l1audio.waiting == false)
         break;
      
      ASSERT_REBOOT( I < 120 );
      kal_sleep_task( 1 );
   }
   if(type == 0){
      ASSERT( MSG_SAC2L1AUDIO_AUDIO_GET_ID_ACK == l1audio.ack.msgID16 );
   }else{
      ASSERT( MSG_SAC2L1AUDIO_SPEECH_GET_ID_ACK == l1audio.ack.msgID16 );
   }
   aud_id = l1audio.ack.msgData16;
#endif
   // Check whether the audio ID is existed
   I = aha_FindExistAudioIndex(aud_id);
   ASSERT( I == MAX_CURRENCY_ID );
   
   // Set the entry
   for (I = 0; I < MAX_CURRENCY_ID; I++) {
      if ( l1audio.msgIdHdl[I].isUsed == false ) {
         l1audio.msgIdHdl[I].isUsed = true;
         l1audio.msgIdHdl[I].aud_id = aud_id;
         l1audio.msgIdHdl[I].userData = userData;
         l1audio.msgIdHdl[I].userMsgHandler = userHandler;
         break;
      }
   }
   ASSERT( I != MAX_CURRENCY_ID );
   
   kal_give_sem( l1audio.sema );
   
   return aud_id;
}

// To unhook message handler and free audio ID
void L1Audio_FC_UnHookHandler( kal_uint16 aud_id, kal_uint16 type )
{
   kal_uint32 I, idx;
   
   kal_take_sem( l1audio.sema, KAL_INFINITE_WAIT );
   
   // Find out the position of audio ID, and then clear
   idx = aha_FindExistAudioIndex(aud_id);
   ASSERT( idx != MAX_CURRENCY_ID );
   
#ifdef L1D_TEST
   if(type ==0)
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_AUDIO_FREE_ID, aud_id, 0);
   else
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_FREE_ID, aud_id, 0);
#else
   l1audio.waiting = true;
   if(type ==0)
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_AUDIO_FREE_ID, aud_id, 0);
   else
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_FREE_ID, aud_id, 0);
   // Waiting for acknowledge
   for (I = 0; ; I++) {
      if (l1audio.waiting == false)
         break;
      
      ASSERT_REBOOT( I < 120 );
      kal_sleep_task( 1 );
   }
#endif
   
   l1audio.msgIdHdl[idx].isUsed = false;
   
   kal_give_sem( l1audio.sema );
}

// To unhook message handler and free audio ID
void L1Audio_FC_UnHookHandler_WithoutWaitingSend( kal_uint16 aud_id, kal_uint16 type )
{
   kal_uint32 idx;
   
   kal_take_sem( l1audio.sema, KAL_INFINITE_WAIT );
   
   // Find out the position of audio ID, and then clear
   idx = aha_FindExistAudioIndex(aud_id);
   ASSERT( idx != MAX_CURRENCY_ID );
   
   if(type ==0)
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_AUDIO_FREE_ID, aud_id, 0);
   else
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_FREE_ID, aud_id, 0);
   
   kal_give_sem( l1audio.sema );
}

void L1Audio_FC_UnHookHandler_WithoutWaitingClear( kal_uint16 aud_id, kal_uint16 type )
{
   kal_uint32 idx;
   
   kal_take_sem( l1audio.sema, KAL_INFINITE_WAIT );
   
   // Find out the position of audio ID, and then clear
   idx = aha_FindExistAudioIndex(aud_id);
   ASSERT( idx != MAX_CURRENCY_ID );
   
   l1audio.msgIdHdl[idx].isUsed = false;
   
   kal_give_sem( l1audio.sema );
}

void L1Audio_FC_AudioPlaybackOn( kal_uint16 aud_id, AUD_RB_INFO *info )
{
   kal_uint32 I;
   
   L1Audio_FC_WriteBufferToDSP(info);
   
   kal_take_sem( l1audio.sema, KAL_INFINITE_WAIT );
   
   l1audio.waiting = true;
   L1Audio_PutMessage(MSG_L1AUDIO2FAS_AUDIO_PLAYBACK_ON, aud_id, (kal_uint32)info->param);

   // Waiting for acknowledge
   for (I = 0; ; I++) {
      if (l1audio.waiting == false)
         break;
      
      ASSERT_REBOOT( I < 120 );
      kal_sleep_task( 1 );
   }
   
   kal_give_sem( l1audio.sema );
}

void L1Audio_FC_MIDIPlaybackOn( kal_uint16 aud_id, AUD_RB_INFO *info )
{
   kal_uint32 I;
   
   
   kal_take_sem( l1audio.sema, KAL_INFINITE_WAIT );
   
   l1audio.waiting = true;
   L1Audio_PutMessage(MSG_L1AUDIO2FAS_AUDIO_PLAYBACK_ON, aud_id, (kal_uint32)info->param);

   // Waiting for acknowledge
   for (I = 0; ; I++) {
      if (l1audio.waiting == false)
         break;
      
      ASSERT_REBOOT( I < 120 );
      kal_sleep_task( 1 );
   }
   
   kal_give_sem( l1audio.sema );
}

#if !defined(__SMART_PHONE_MODEM__) && !defined(__L1_STANDALONE__) && !defined(MED_MODEM)
void L1Audio_FC_AudioPlaybackOn_Component( kal_uint16 aud_id, void *ihdl, FC_Drv_Info *pDrvInfo )
{
   L1Audio_FC_WriteBufferToDSP_Component(ihdl, pDrvInfo);
   L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_AUDIO_PLAYBACK_ON, aud_id, (kal_uint32)pDrvInfo->pBufInfo, KAL_TRUE);
}
#endif

void L1Audio_FC_AudioPlaybackOff( kal_uint16 aud_id )
{
   L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_AUDIO_PLAYBACK_OFF, aud_id, 0, KAL_TRUE);
}

//void L1Audio_FC_RecordOn( kal_uint16 aud_id, FC_Media_Format format )
void L1Audio_FC_RecordOn( kal_uint16 dedicated, kal_uint16 size, void *data, L1Audio_MsgIDHandler userHandler )
{
   kal_uint32 I;
   
   kal_take_sem( l1audio.sema, KAL_INFINITE_WAIT );
   if( dedicated )
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_CALL_RECORD_PCM_START, size, (kal_uint32)data);
   else
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_IDLE_RECORD_PCM_START, size, (kal_uint32)data);

   // Waiting for acknowledge
   for (I = 0; ; I++) {
      if (l1audio.waiting == false)
         break;
      
      ASSERT_REBOOT( I < 120 );
      kal_sleep_task( 1 );
   }
   
   for (I = 0; I < MAX_CURRENCY_ID; I++) {
      if ( l1audio.msgIdHdl[I].isUsed == false ) {
         l1audio.msgIdHdl[I].isUsed = true;
         l1audio.msgIdHdl[I].aud_id = 0;  // JY: To Do
         l1audio.msgIdHdl[I].userMsgHandler = userHandler;
         break;
      }
   }
   
   kal_give_sem( l1audio.sema );
}

//void L1Audio_FC_RecordOff( kal_uint16 aud_id )
void L1Audio_FC_RecordOff( kal_bool dedicated )
{
   kal_uint32 I;
   
   kal_take_sem( l1audio.sema, KAL_INFINITE_WAIT );
   
   l1audio.msgIdHdl[0].isUsed = false;
   
   l1audio.waiting = true;
   if( dedicated )
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_CALL_RECORD_PCM_STOP, 0, 0);
   else
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_IDLE_RECORD_PCM_STOP, 0, 0);

   // Waiting for acknowledge
   for (I = 0; ; I++) {
      if (l1audio.waiting == false)
         break;
      
      ASSERT_REBOOT( I < 120 );
      kal_sleep_task( 1 );
   }
   
   kal_give_sem( l1audio.sema );
}

void L1Audio_FC_TonePlaybackOn( kal_uint16 aud_id, AUD_TONE_INFO *info )
{
   L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_AUDIO_PLAYBACK_ON, aud_id, (kal_uint32)info, true);
}

void L1Audio_FC_SetWait( kal_bool wait )
{
   l1audio.waiting = wait;
}

void L1Audio_FC_TonePlaybackOff( kal_uint16 aud_id )
{
   L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_AUDIO_PLAYBACK_OFF, aud_id, 0, true);
}

void L1Audio_FC_AudioWriteData( kal_uint16 aud_id, AUD_RB_INFO *info )
{
   L1Audio_PutMessage(MSG_L1AUDIO2FAS_AUDIO_WRITE_DATA, aud_id, (kal_uint32)info);
}

void L1Audio_FC_AudioDataRequestAck( kal_uint16 aud_id, AUD_RB_INFO *info )
{
   FC_Buf *pBufHdr = (FC_Buf *)(info->param);
   
   L1Audio_PutMessage(MSG_L1AUDIO2FAS_AUDIO_DATA_REQUEST_ACK, aud_id, (kal_uint32)pBufHdr->pWrite);
}

void L1Audio_FC_AudioDataRequestAck_Component( kal_uint16 aud_id, FC_Buf *pBufHdr )
{   
   L1Audio_PutMessage(MSG_L1AUDIO2FAS_AUDIO_DATA_REQUEST_ACK, aud_id, (kal_uint32)pBufHdr->pWrite);
}

void L1Audio_FC_AudioDataNotifyAck( kal_uint16 aud_id )
{
   L1Audio_PutMessage(MSG_L1AUDIO2FAS_AUDIO_DATA_NOTIFICATION_ACK, aud_id, 0);
}

void L1Audio_FC_AudioDataNotifyAck_Component( kal_uint16 aud_id, FC_Buf *pBufInfo )
{
   L1Audio_PutMessage(MSG_L1AUDIO2FAS_AUDIO_DATA_NOTIFICATION_ACK, aud_id, (kal_uint32)pBufInfo->pRead);
}

void L1Audio_FC_SetPlayRate( kal_uint16 aud_id, kal_uint32 rate )
{
   L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_AUDIO_SET_PLAY_RATE, aud_id, rate, true);
}

//---- Audio Buffer Memory Management for Dual MAC DSP ----
void Audio_Drv_MM_Init(void)
{
   int I;
   
   for (I=0; I<AUDIO_BUFFER_INSTANCE_MAX; I++) {
      audio_drv_mem_manager.fUsed[I] = false;
   }
}

#if __DRIVER_PRESERVE_DSP_SHARE_BUFFER__
// KH 20100408
// Copy to another share
FC_Buf *L1Audio_FC_GetAudioBufferHeader( void )
{
   int I;
   
   for (I=0; I<AUDIO_BUFFER_INSTANCE_MAX; I++) {
      if (audio_drv_mem_manager.fUsed[I] == false)
         break;
   }
   ASSERT(I<AUDIO_BUFFER_INSTANCE_MAX);

   audio_drv_mem_manager.fUsed[I] = true;
   Audio_Buffer_Header[I].pBuf = (void *)Audio_Buffer[I];
   Audio_Buffer_Header[I].uBufLength = AUDIO_BUFFER_SIZE;
   Audio_Buffer_Header[I].pWrite = (void *)Audio_Buffer[I];
   Audio_Buffer_Header[I].pRead = (void *)Audio_Buffer[I];

   return &Audio_Buffer_Header[I];
}

void L1Audio_FC_ReleaseAudioBufferHeader( FC_Buf **pBufHeader )
{
   int I;
   
   for (I=0; I<AUDIO_BUFFER_INSTANCE_MAX; I++) {
      if (*pBufHeader == &Audio_Buffer_Header[I])
         break;
   }
   ASSERT(I<AUDIO_BUFFER_INSTANCE_MAX);
   Audio_Buffer_Header[I].uTime = 0;
   
   *pBufHeader = NULL;
   audio_drv_mem_manager.fUsed[I] = false;
}

FC_Buf *L1Audio_FC_QueryBufInfo( void )
{
   int I;
   
   for (I=0; I<AUDIO_BUFFER_INSTANCE_MAX; I++) {
      if (audio_drv_mem_manager.fUsed[I] == true)
         break;
   }
   if (I==AUDIO_BUFFER_INSTANCE_MAX) {
     I = 0;
   }

   return &Audio_Buffer_Header[I];
}

void L1Audio_FC_ResetAudioBufferHeader(FC_Buf *pBufHeader)
{
   pBufHeader->pWrite = pBufHeader->pRead = pBufHeader->pBuf;
}


kal_uint32 FC_GetDspFreeSpace(FC_Buf *fc_BufHdr)
{
   kal_uint32 ufreeLen;
   
   // To get the free space
   if ( fc_BufHdr->pRead > fc_BufHdr->pWrite ) {
      ufreeLen = (kal_uint32)fc_BufHdr->pRead - (kal_uint32)fc_BufHdr->pWrite - 1;
   } else if (fc_BufHdr->pRead == fc_BufHdr->pBuf) {
      ufreeLen = ((kal_uint32)fc_BufHdr->pBuf + fc_BufHdr->uBufLength) - (kal_uint32)fc_BufHdr->pWrite - 1;
   } else {
      ufreeLen = ((kal_uint32)fc_BufHdr->pBuf + fc_BufHdr->uBufLength) - (kal_uint32)fc_BufHdr->pWrite;
   }

   ASSERT( ufreeLen <= fc_BufHdr->uBufLength );
   
   return ufreeLen;
}

kal_uint32 FC_GetDspDataCount( void *pBufHdr )
{
   kal_uint32 uDataLen;
   FC_Buf *fc_BufHdr = (FC_Buf *)pBufHdr;
   
   // To get the data count
   if ( fc_BufHdr->pWrite >= fc_BufHdr->pRead )
      uDataLen = fc_BufHdr->pWrite - fc_BufHdr->pRead;
   else
      uDataLen = fc_BufHdr->uBufLength + fc_BufHdr->pWrite - fc_BufHdr->pRead;
   ASSERT( uDataLen < fc_BufHdr->uBufLength );
   
   return uDataLen;
}

static kal_uint32 L1Audio_FC_WriteBuffer_DspSegment( FC_Buf *fc_BufHdr, kal_uint8 *pDataBuf, kal_uint32 uDataLen)
{
   kal_uint8 *pFreeBuf;
   kal_uint32 ufreeLen, uFillLen;

   // To get the free space
   ufreeLen = FC_GetDspFreeSpace(fc_BufHdr);
   pFreeBuf = fc_BufHdr->pWrite;
   
   if (ufreeLen > uDataLen)
      uFillLen = uDataLen;
   else
      uFillLen = ufreeLen;
   // Force to word
   uFillLen &= ~0x1;
   
   memcpy(pFreeBuf, pDataBuf, uFillLen*sizeof(kal_uint8));
   fc_BufHdr->pWrite += uFillLen;
   if ((kal_uint32)fc_BufHdr->pWrite == ((kal_uint32)fc_BufHdr->pBuf + fc_BufHdr->uBufLength))
      fc_BufHdr->pWrite = fc_BufHdr->pBuf;
      
   return uFillLen;
}

static kal_uint32 L1Audio_FC_WriteBuffer_MedSegment(AUD_RB_INFO *rbInfo)
{
   kal_uint8 *pDataBuf;
   kal_uint32 uDataLen, uConsumedLen, uTotalConsume;
   
   // To get the data amount
   if ( rbInfo->write >= rbInfo->read )
      uDataLen = rbInfo->write - rbInfo->read;
   else
      uDataLen = rbInfo->rb_size - rbInfo->read;
   // Force to word
   uDataLen &= ~0x1;
   ASSERT( uDataLen < rbInfo->rb_size );
   pDataBuf = (kal_uint8 *)&rbInfo->rb_base[rbInfo->read];
   
   // Write to DSP segment 1
   uTotalConsume = uConsumedLen = L1Audio_FC_WriteBuffer_DspSegment( (FC_Buf *)rbInfo->param, pDataBuf, uDataLen);
   uDataLen -= uConsumedLen;
   pDataBuf += uConsumedLen;
   rbInfo->read += uConsumedLen;
   if (rbInfo->read == rbInfo->rb_size)
      rbInfo->read = 0;
   
   // Write to DSP segment 2
   uConsumedLen = L1Audio_FC_WriteBuffer_DspSegment( (FC_Buf *)rbInfo->param, pDataBuf, uDataLen);
   uTotalConsume += uConsumedLen;
   rbInfo->read += uConsumedLen;
   if (rbInfo->read == rbInfo->rb_size)
      rbInfo->read = 0;
   
   return uTotalConsume;
}

kal_uint32 L1Audio_FC_WriteBufferToDSP(AUD_RB_INFO *rbInfo)
{   
   kal_uint32 consume1, consume2;
   
   consume1 = L1Audio_FC_WriteBuffer_MedSegment(rbInfo);
   consume2 = L1Audio_FC_WriteBuffer_MedSegment(rbInfo);
   
   return (consume1 + consume2);
}

//----

void L1Audio_FC_UpdateDspReadPointer(AUD_RB_INFO *rbInfo, kal_uint32 mag32)
{
   FC_Buf *fc_BufHdr = (FC_Buf *)rbInfo->param;
   kal_uint32 uFreeOri, uFreeAfter;
//   kal_uint8 *pReadOri = fc_BufHdr->pRead;
   
   uFreeOri = FC_GetDspFreeSpace( fc_BufHdr );
   fc_BufHdr->pRead = (kal_uint8 *)mag32;
   uFreeAfter = FC_GetDspFreeSpace( fc_BufHdr );
   ASSERT(uFreeOri <= uFreeAfter);
}

#endif


/* ------------------------------------------------------------------------------ */

kal_bool L1Audio_CheckAudioID( kal_uint16 audio_id )
{
   if( l1audio.id_flag & (1 << audio_id) )
      return true;
   return false;
}

uint16 L1Audio_GetAudioID( void )
{
   uint32 I;
   uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   for( I = 0; I < MAX_AUDIO_FUNCTIONS; I++ ) {
      if( (l1audio.id_flag & (1<<I)) == 0 ) {
         l1audio.id_flag |= (1<<I);
         break;
      }
   }
   RestoreIRQMask( savedMask );

   ASSERT( (l1audio.state & (1 << I)) == 0 );
   ASSERT_REBOOT( I < MAX_AUDIO_FUNCTIONS );
   return (uint16)I;
}

void L1Audio_FreeAudioID( uint16 aud_id )
{
   uint32 savedMask;
   uint32 retrieved_events;
   kal_retrieve_eg_events(l1audio.aud_events,(1<<aud_id),KAL_OR_CONSUME,&retrieved_events,0);
   ASSERT( (l1audio.state & (1 << aud_id)) == 0 );
   ASSERT( l1audio.id_flag & (1<<aud_id) );
   savedMask = SaveAndSetIRQMask();
   l1audio.id_flag &= ~(1<<aud_id);
   l1audio.retrieved_events &= ~(1<<aud_id);
   RestoreIRQMask( savedMask );
}

void L1Audio_SetEventHandler( uint16 audio_id, L1Audio_EventHandler handler )
{
   l1audio.evHandler[audio_id] = handler;
}

void L1Audio_SetEvent( uint16 audio_id, void *data )
{
   l1audio.evData[audio_id] = data;
   kal_set_eg_events( l1audio.aud_events, 1 << audio_id, KAL_OR );      /* Activate L1Audio Task */
}

void L1Audio_LSetEvent( uint16 audio_id, void *data )
{
   uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   l1audio.evData[audio_id] = data;
   l1audio.event_flag |= (1 << audio_id);
   RestoreIRQMask( savedMask );
   kal_activate_hisr( l1audio.hisr );                                   /* Activate L1Audio HISR */
}

bool L1Audio_CheckFlag( uint16 audio_id )      /* return true if error happens */
{
   if( l1audio.state & (1 << audio_id) )
      return true;
   return false;
}

void L1Audio_DisallowSleep( kal_uint16 audio_id )
{
   SLEEP_LOCK();
}

void L1Audio_AllowSleep( kal_uint16 audio_id )
{
   SLEEP_UNLOCK();
}

void L1Audio_SetFlag( uint16 audio_id )
{
   uint32 savedMask;

   ASSERT( l1audio.id_flag & (1 << audio_id) );
   ASSERT( (l1audio.state & (1 << audio_id)) == 0 );
   
   savedMask = SaveAndSetIRQMask();
   l1audio.state |= (1 << audio_id);
   RestoreIRQMask( savedMask );
}

void L1Audio_ClearFlag( uint16 audio_id )
{
   uint32 savedMask;

   ASSERT( l1audio.id_flag & (1 << audio_id) );
   ASSERT( l1audio.state & (1 << audio_id) );

   savedMask = SaveAndSetIRQMask();
   l1audio.state &= ~(1 << audio_id);
   RestoreIRQMask( savedMask );
}

/* ------------------------------------------------------------------------------ */
/*  L1Audio HISR                                                                  */
/* ------------------------------------------------------------------------------ */

void L1Audio_HISR( void )
{
   uint32 savedMask;
   int32  I;

   if( l1audio.hisrMagicFlag ) {
      for( I = 0; I < MAX_HISR_HANDLER; I++ ) {
         if( l1audio.hisrMagicFlag & (1<<I) ) {
            savedMask = SaveAndSetIRQMask();
            l1audio.hisrMagicFlag &= ~(1<<I);
            RestoreIRQMask( savedMask );
            l1audio.hisrHandler[I]( l1audio.hisrUserData[I] );
         }
      }
   }

   if( l1audio.event_flag ) {
      int16 I;
      for( I = 0; I < MAX_AUDIO_FUNCTIONS; I++ ) {
         if( l1audio.event_flag & (1<<I) ) {
            savedMask = SaveAndSetIRQMask();
            l1audio.event_flag &= ~(1<<I);
            RestoreIRQMask( savedMask );
            L1Audio_SetEvent( I, l1audio.evData[I] );
         }
      }
   }
}

void L1SP_D2C_LISR( uint16 itype )
{

}

void L1Audio_HookHisrHandler( kal_uint16 magic_no, L1Audio_EventHandler handler, void *userData )
{
   int32 I;
   for( I = 0; I < MAX_HISR_HANDLER; I++ ) {
      if( l1audio.hisrMagicNo[I] == 0 ) {
         l1audio.hisrMagicNo[I] = magic_no;
         l1audio.hisrHandler[I] = handler;
         l1audio.hisrUserData[I] = userData;
         break;
      }
   }
   ASSERT_REBOOT( I != MAX_HISR_HANDLER );
}

void L1Audio_UnhookHisrHandler( kal_uint16 magic_no )
{
   int32 I;
   for( I = 0; I < MAX_HISR_HANDLER; I++ ) {
      if( l1audio.hisrMagicNo[I] == magic_no ) {
         l1audio.hisrMagicNo[I] = 0;
         break;
      }
   }
   ASSERT_REBOOT( I != MAX_HISR_HANDLER );
}

void L1Audio_SetDebugInfo( kal_uint16 debug_info[NUM_DEBUG_INFO])
{
   memcpy(l1audio.debug_info, debug_info, NUM_DEBUG_INFO*sizeof(uint16));
}

void L1Audio_SetDebugInfoN( kal_uint16 index, kal_uint16 debug_info )
{
   l1audio.debug_info[index] = debug_info;
}

kal_uint16 L1Audio_GetDebugInfo( kal_uint8 index )
{
   ASSERT( index < NUM_DEBUG_INFO );
   return l1audio.debug_info[index];   
}
#ifdef __SMART_PHONE_MODEM__

extern kal_eventgrpid  aud_events;
extern kal_uint32      kal_state;
extern kal_uint32      id_flag;

#endif

/* ------------------------------------------------------------------------------ */
/*  L1Audio Task                                                                  */
/* ------------------------------------------------------------------------------ */
void L1Audio_Task(unsigned argc, void *argv)
{
   uint32 retrieved_events;
   uint32 I;

   l1audio.hisrMagicFlag = 0;
   
   for( I = 0; I < MAX_HISR_HANDLER; I++ )
      l1audio.hisrMagicNo[I] = 0;

   Audio_Drv_MM_Init();

   AM_Init();

   /// AFE_Init will invoke L1Audio_GetAudioID
   /// and expect to get the id 0 to make sure
   /// it has the highest priority in the event group
   AFE_Init();

   L1SP_Init();

   ktInit( L1Audio_GetAudioID() );
   toneInit( L1Audio_GetAudioID() );
   mediaInit( L1Audio_GetAudioID() );
   PCMNWAY_Init();

   toneLoopbackRecInit();

#ifdef __CTM_SUPPORT__
   l1ctm_init();
#endif

   memset( &(l1audio.debug_info), 0, sizeof(l1audio.debug_info) );
   AFE_TurnOnFIR( L1SP_SPEECH );
   AFE_TurnOnFIR( L1SP_VOICE );

   {
      /* Get a audio ID for handling message in l1audio task */
      l1audio.aud_id = L1Audio_GetAudioID();
      L1Audio_SetEventHandler( l1audio.aud_id, l1audio_MsgHandler );
#ifdef L1D_TEST
      sphOnId = L1Audio_GetAudioID();
      L1Audio_SetEventHandler( sphOnId, l1audio_sphOnHandler );
      sphOffId = L1Audio_GetAudioID();
      L1Audio_SetEventHandler( sphOffId, l1audio_sphOffHandler );
      AudSys_Cosim_Id = L1Audio_GetAudioID();
      L1Audio_SetEventHandler( AudSys_Cosim_Id, l1audio_AudSysCosimHandler );
#endif
      
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_QUERY_DSP_VERSION, 0, 0);
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SET_M2D_MEM, DSP_SHARE_SIZE, (kal_uint32)DM_DSP_MEM);
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_SET_SIDETONE, 0x200, (kal_uint32)NULL );
      L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_DL_VOLUME, 0x1000, 128 );
      L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_UL_VOLUME, 0x1000, 128 );

      #if defined(__HQA_AUDIO__) 
      L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_UL_IIR, KAL_FALSE, (kal_uint32)NULL );  
      #else
      L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_UL_IIR, KAL_TRUE, (kal_uint32)NULL );  
      #endif
      
   }

#ifdef __SMART_PHONE_MODEM__
	 //this flag prevents Modem side from processing A2M message before L1AudioMain is initialized, 
	 //and just put A2M message into queue to wait the initilization of L1AudioMain  
   l1audio.isTaskInitialize = true;
   SMP_SPC_Init();
#endif
   while( 1 ) {
#if VERIFY_DATA_TO_DSP
      VERIFY_DATA_TO_DSP_SAVE_DATA();
#endif
      kal_retrieve_eg_events(l1audio.aud_events,0xFFFF,KAL_OR_CONSUME,&retrieved_events,KAL_SUSPEND);
      l1audio.retrieved_events = retrieved_events;
      l1audio.events_l1FN = L1I_GetTimeStamp();
      for( I = 0; I < MAX_AUDIO_FUNCTIONS; I++ ) {
         if ( l1audio.retrieved_events & (1<<I) ) {
            l1audio.evHandler[I]( l1audio.evData[I] );
         }
      }
   }
}

/* ------------------------------------------------------------------------------ */
/*  L1Audio High Priority Task                                                                  */
/* ------------------------------------------------------------------------------ */
void AudioHigh_Task(unsigned argc, void *argv)
{
   uint32 retrieved_events;
   uint32 I;
   kal_int32 ret;

#ifdef __SMART_PHONE_MODEM__

   l1audio.aud_events = aud_events; 
   //kal_create_event_group("L1Audio");
   l1audio.hisr = kal_init_hisr(L1AUDIO_HISR);

   GET_SLEEP_HANDLE();

   l1audio.state        = kal_state;
   l1audio.dsp_slow_idle_counter = 0;
   l1audio.event_flag   = 0;
   l1audio.id_flag      = id_flag;
   l1audio.media_flag   = 0;

#else

   l1audio.aud_events = kal_create_event_group("L1Audio");
   l1audio.hisr = kal_init_hisr(L1AUDIO_HISR);

   GET_SLEEP_HANDLE();

   l1audio.state        = 0;
   l1audio.dsp_slow_idle_counter = 0;
   l1audio.event_flag   = 0;
   l1audio.id_flag      = 0;
   l1audio.media_flag   = 0;
#endif  /* __SMART_PHONE_MODEM__ */

   MsgQueue_Init(&l1audio.msgQueue);

   l1audio.audH_events = kal_create_event_group("AudioH_Event");
   MsgQueue_Init(&l1audio.msgQueueH);
   l1audio.audH_id = L1Audio_GetAudioID();
   L1Audio_SetEventHandler( l1audio.audH_id, AudioH_SendMessageHandler );
   
   /* Get semaphore to avoid race condition */              
   l1audio.sema = kal_create_sem( "Aud_Sema", 1 );          
   l1audio.mdci_sema = kal_create_sem( "Aud_MDCI_Sema", 1 );
   ret = mdci_init(MDCI_AUDIO_CHANNEL_D2M, SAC2MCU_hisr);
   if (ret != MDCI_SUCCESS) {
       ASSERT(0);
   }

   /* Initialize the channel for sendinf message from Modem to AP. Callback is dummy function */
   ret = mdci_init(MDCI_AUDIO_CHANNEL_M2D, MCU2SAC_hisr);
   if (ret != MDCI_SUCCESS) {
       ASSERT(0);
   }

   while( 1 ) {
      kal_retrieve_eg_events(l1audio.audH_events,0xFFFF,KAL_OR_CONSUME,&retrieved_events,KAL_SUSPEND);
      l1audio.retrievedH_events = retrieved_events;
      l1audio.events_l1FN = L1I_GetTimeStamp();
      for( I = 0; I < MAX_AUDIO_FUNCTIONS; I++ ) {
         if ( l1audio.retrievedH_events & (1<<I) ) {
            l1audio.evHandler[I]( l1audio.evData[I] );
         }
      }
   }
}

/*************************************************************************
* FUNCTION
*  audh_create
*
* DESCRIPTION
*  This function implements audio high priority task entity's create handler.
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
static void audh_main(task_entry_struct * task_entry_ptr)
{
   kal_set_active_module_id(MOD_AUDH);
   
   AudioHigh_Task( 0, 0 );
}

kal_bool audh_create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct audh_handler_info =
   {
      audh_main,     /* task entry function */
      NULL,          /* task initialization function */
      NULL           /* task reset handler */
   };

   *handle = (comptask_handler_struct *)&audh_handler_info;
   return KAL_TRUE;
}

//------------------------------------

uint32 L1Audio_GetEventGroup( void )
{
   uint32 retrieved_events;
   kal_retrieve_eg_events( l1audio.aud_events, 0xFFFF, KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND );
   return retrieved_events;
}

void L1Audio_ExeEventHandler( uint32 event )
{
   ASSERT( event < MAX_AUDIO_FUNCTIONS );
   l1audio.evHandler[event]( l1audio.evData[event] );
}

void L1Audio_ResetDevice(void)
{
   AFE_Init();
}
#ifdef __SMART_PHONE_MODEM__  
kal_bool L1Audio_IsTaskInitilized( void )
{
   return l1audio.isTaskInitialize;
}
#endif
/* ------------------------------------------------------------------------------ */


#ifdef L1D_TEST
void L1Audio_L1ActiveHISR(uint16 on, uint32 type)
{
   if(on > 0)
      L1Audio_LSetEvent(sphOnId, (void *)type);
   else
      L1Audio_LSetEvent(sphOffId, 0);
}

void L1Audio_AudSysActiveHISR(uint16 msgId)
{
   L1Audio_LSetEvent(AudSys_Cosim_Id, (void *)msgId);
}
#endif

void l1audio_console_handler(kal_char *string)
{
    (void)string;
}


/* ----------------------------------------------------------------------------- */
/*  Function ptr prototype [HAL rule]                                            */
/* ----------------------------------------------------------------------------- */
//[MED]

static fp_audio_alloc_aud_mem      audio_alloc_aud_mem = NULL;
static fp_audio_alloc_aud_mem      audio_alloc_aud_mem_cacheable= NULL;
static fp_audio_free_aud_mem       audio_free_aud_mem = NULL;
static fp_send_proc_call_req       send_proc_call_req = NULL;
static fp_send_proc_call_req       send_proc_call_req2 = NULL;
static fp_audio_set_path_volume    audio_set_path_vol = NULL;
static fp_audio_get_active_mode    audio_get_active_mode = NULL;
static fp_get_meta_data_file       audio_get_meta_file = NULL;
static fp_get_meta_data_array      audio_get_meta_array = NULL;

void Audio_MedFuncReg(Media_Func_Reg_Type *func){
	    audio_alloc_aud_mem           = (fp_audio_alloc_aud_mem)func->alloc_mem;
	 	  audio_alloc_aud_mem_cacheable = (fp_audio_alloc_aud_mem)func->alloc_mem_cacheable;
	 	  audio_free_aud_mem            = (fp_audio_free_aud_mem) func->free_mem;	 
	 	  audio_set_path_vol            = (fp_audio_set_path_volume)func->set_path_volume;
	 	  audio_get_active_mode         = (fp_audio_get_active_mode)func->get_active_mode;
	 	  send_proc_call_req            = (fp_send_proc_call_req)   func->send_proc_call;
	 	  send_proc_call_req2           = (fp_send_proc_call_req)   func->send_proc_call2;
	 	  audio_get_meta_file           = (fp_get_meta_data_file)   func->get_meta_file;
	 	  audio_get_meta_array          = (fp_get_meta_data_array)  func->get_meta_array;	 	  
}

void *audio_alloc_ext_mem(kal_int32 size, char* file_p, long line_p){
	 void *ptr = NULL; 	 	 
   
	 if (size == 0){
        return NULL;
     }    
	 ptr = (void*) audio_alloc_aud_mem(size,file_p,line_p);
	 if(ptr){
        memset(ptr, 0, size);
	 }
	 kal_wap_trace(MOD_L1SP, TRACE_INFO, "[AUD][MEM] get buffer from: %s, %d", file_p, line_p);
	 return ptr;
}

void *audio_alloc_ext_mem_cacheable(kal_int32 size, char* file_p, long line_p){
	 void *ptr = NULL; 	 	 
	 
	 if (size == 0){
        return NULL;
   } 
	 ptr = (void*) audio_alloc_aud_mem_cacheable(size,file_p,line_p);
	 if(ptr){
        memset(ptr, 0, size);
	 }
	 kal_wap_trace(MOD_L1SP, TRACE_INFO, "[AUD][MEM] get buffer from: %s, %d", file_p, line_p);
	 return ptr;
}

void audio_free_ext_mem(void **ptr, char* file_p, long line_p){
	 audio_free_aud_mem(ptr,file_p,line_p);
	 kal_wap_trace(MOD_L1SP, TRACE_INFO, "[AUD][MEM] free buffer from: %s, %d", file_p, line_p);
}

void L1Audio_InProcCall2(in_proc_call_type func, kal_uint32 func_arg1, void* func_arg2)
{

}

void L1Audio_InProcCall(in_proc_call_type func, kal_uint32 func_arg1, void* func_arg2)
{

}

void aud_set_volume_internal(kal_uint8 audio_mode){
	 audio_set_path_vol(audio_mode);
}

kal_uint8 aud_get_mode_internal(void){
	return audio_get_active_mode();
}

//[BT]
static fp_a2dp_set_br_from_qos_init   set_br_from_qos_init = NULL;
static fp_a2dp_set_br_from_qos        set_br_from_qos = NULL;

void Audio_BTFuncReg(BT_Func_Reg_Type *func){
	    set_br_from_qos_init           = (fp_a2dp_set_br_from_qos_init)func->a2dp_set_br_init;
	 	  set_br_from_qos                = (fp_a2dp_set_br_from_qos)     func->a2dp_set_br;
}

void a2dp_set_br_init_internal(kal_uint32 bit_rate_cur){
	 set_br_from_qos_init(bit_rate_cur);
}

kal_uint32 a2dp_set_br_internal(kal_uint8 qos, kal_uint32 bit_rate_prev, kal_uint32 (*SetCodecBitRate)(kal_uint32)){
	 return set_br_from_qos(qos, bit_rate_prev, (*SetCodecBitRate));
}


/***********************************************************/
/* Export to MED/AUDL task                                 */
/***********************************************************/

#if defined(__SMART_PHONE_MODEM__)
extern void spc_AP_Command_Handler(kal_uint32 ccciMsg);
#endif

void SpcIO_Msg_Handler_inAudL(ilm_struct *ilm_ptr)
{
#if defined(__SMART_PHONE_MODEM__)
   spc_AP_Command_Handler( ilm_ptr->msg_id );
#endif
}

kal_bool SP_Drv_Init_Bootup(void)
{
   return KAL_TRUE;
}

kal_bool SP_Drv_Init_Task(void)
{
   return KAL_TRUE;
}

