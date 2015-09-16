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
 *   spc_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   modem load speach control driver
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_trace.h"
#include "string.h"
#include "fsal.h"

#include "l1audio.h"
#include "audio_enum.h"
#include "l1audio_def.h"
#include "am.h"
#include "fc_def.h"
#include "afe.h"
#include "media.h"
#include "ccci.h"
#include "l1sp_trc.h"
#include "audio_em_struct.h"
#include "pcm4way.h"
#include "ctm_drv.h"

//-----------------------------------------------------------------------------
// Configurations
//-----------------------------------------------------------------------------

#ifdef __SMART_PHONE_MODEM__

#define __MT6573_PLATFORM__

//-----------------------------------------------------------------------------
// Constant definitions
//-----------------------------------------------------------------------------

#define CCCI_MSG_QUEUE_SZ  32

#define MSG_TYPE_MASK  (0xfU << 28)
#define MSG_FUNC_MASK  (0xfU << 24)
#define MSG_PARAM_MASK (0xffffffU << 0)


#define SND_PCM_BUFFER_SIZE         (2048*1)
#define AP_BGS_BUF_SIZE             (1024*8)
#define RESERVE_BUF_SIZE            ((SND_PCM_BUFFER_SIZE*3) >> 2)

#define SPC_PCMWAY_USAGE (0)
#define SPC_RECORD_USAGE (1)
#define SPC_BKGSND_USAGE (2)

unsigned short g_spc_usage;
#define SET_SPC_USAGE(a)   (g_spc_usage |= (1 << (a)))
#define RESET_SPC_USAGE(a) (g_spc_usage &= (~(1 << (a))))
#define IS_SPC_USED(a)     ((g_spc_usage & (1 << (a))) != 0)

#define MAX_SIZE_OF_PCM_SE_BUF 	160
#define MAX_SIZE_OF_PCM_SPK_BUF 320 //max = 16*20
#define MAX_SIZE_OF_PCM_MIC_BUF 642 //max = 320*2 +2(agc use)
#define MAX_SIZE_OF_PCM_SD_BUF 	160

//-----------------------------------------------------------------------------
// Global variable definition
//-----------------------------------------------------------------------------
/* digital gain of DL speech */
unsigned short g_Digi_DL_Speech;
/* digital gain of uplink speech */
unsigned short g_Digi_Microphone;
/* FM record volume*/
unsigned short g_FM_Record_Volume;    
/* user mode : normal mode, earphone mode, loud speaker mode */
unsigned short g_Bluetooth_Sync_Type;
unsigned short g_Bluetooth_Sync_Length;
unsigned short g_bt_pcm_in_vol;
unsigned short g_bt_pcm_out_vol;
unsigned short g_uMicbiasVolt;
/* Feature should be enable for smart phone*/
// bit 0: __HD_RECORD__
// bit 1: __STEREO_RECORD__
unsigned short g_Spc_FeatureList;

extern uint32 L1I_GetTimeStamp( void );

//-----------------------------------------------------------------------------
// Extern Global Variable
//-----------------------------------------------------------------------------
extern kal_uint16 sph_common_par[NUM_COMMON_PARAS];

//-----------------------------------------------------------------------------
// Type definitions
//-----------------------------------------------------------------------------

typedef struct _SMP_MESSAGE_T_
{
    kal_uint32 message_type;
    kal_uint32 message_data;
    kal_uint32 putTime;
    kal_uint32 getTime;
} SMP_MESSAGE_T;

typedef struct _SMP_MESSAGE_DATA_T_
{
    kal_uint8  message_group;
    kal_uint8  message_function;
    kal_uint32 message_param;
} SMP_MESSAGE_DATA_T;

typedef struct _SMP_MESSAGE_CHANGE_DEV_PARAM_T_
{
    kal_uint32  input_volume;
    kal_uint32  output_volume;
    kal_uint32  sidetone_volume;
    kal_uint32  input_device;
    kal_uint32  output_device;
    kal_uint32  speech_mode;
} SMP_MESSAGE_CHANGE_DEV_PARAM_T;

typedef struct spcBufInfoStruct 
{
   uint16 syncWord;
   uint16 type;
   uint16 length;
} spcBufInfo;

typedef struct _SMP_SPC_T_
{
   RINGBUFFER_T(SMP_MESSAGE_T, CCCI_MSG_QUEUE_SZ)   ccciq;

   MHdl                 *snd_hdl;
   MHdl                 *vm_pcm_playback_Handle;

   /* The buffer pointer for CCCI shared buffer */
   uint16               smp_audio_id;
   uint32               read;
   uint32               write;
   uint32               md_share_buf_size; // The size of MD share buffer, in size of Byte
   uint32               ap_share_buf_size; // The size of AP share buffer, in size of Byte
   uint8                *md_share_buf;     // The base of MD share buffer
   uint8                *ap_share_buf;     // The base of AP share buffer
   uint8                sph_ul_vol;
   uint8                RAT_Mode;
   uint8                pcmSpk_waiting;       //PCM2WAY, PCM4WAY speaker data waiting flag
   uint8                pcmMic_waiting;       //PCM2WAY, PCM4WAY microphone data waiting flag
   uint8                record_data_waiting;       //PCM2WAY, PCM4WAY waiting flag

   //uint8                has_wb_mode_para;
   //uint8                has_wb_dlfir_para;
   //uint8                has_wb_ulfir_para;

   kal_uint32           gain_tbl_internal_gain;
   kal_uint32           gain_tbl_internal_mic_gain;

} SMP_SPC_T;

typedef enum {
  P2W_PROC_SOURCE_UNDEF = 0,
  P2W_PROC_SOURCE_NORMAL,
  P2W_PROC_SOURCE_CALIBRATION,
  P2W_PROC_SOURCE_VM_CALIBRAION,
}P2W_PROC_SOURCE;


typedef struct _SPC_RECORD_INFO_T 
{
   uint8 format; //0 undefined, 1: pcm, 2:VM
   uint8 sampleRateIndex; //0: 8k, 1: 16k
   uint8 channelNum; //0: undefined; 1: mono; 2: stereo
} SPC_RECORD_INFO_T;

typedef struct _SPC_SPE_INFO_T
{
	uint8 infoState; //0: unused, 1: under setting, 2: finish setting 
	uint8 isMaskChange; // bit[0] for spe_usr_mask, bit[1] for spe_usr_subFunc_mask[0:15], bit[2] for spe_usr_subFunc_mask[16:31]
	uint16 spe_usr_mask;
	uint32 spe_usr_subFunc_mask;
	
} SPC_SPE_INFO_T;
//-----------------------------------------------------------------------------
// Static variables
//-----------------------------------------------------------------------------

SMP_SPC_T rSmpSpc;
SMP_MESSAGE_CHANGE_DEV_PARAM_T rChgDevPara;

// For VM and PCM playback (8k Hz)
__attribute__((aligned (4))) static kal_uint8 strmBuffer[16384];

// For VM and PCM playback (8k Hz)
// __align(4) static kal_uint8 strmBuffer[16384];

#ifndef __MT6573_PLATFORM__

#define SHM_BUF_SZ  (8*1024*2)

kal_uint8 au1SharedBuff[SHM_BUF_SZ];
kal_uint8 * pu4MDBufAddr;

#endif

//-----------------------------------------------------------------------------
// Imported functions
//-----------------------------------------------------------------------------
uint32 SaveAndSetIRQMask( void );
void   RestoreIRQMask( uint32 );

//-----------------------------------------------------------------------------
// External variables
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Static functions
//-----------------------------------------------------------------------------

//==================================================================================================

static uint8 pcm_buffer_ind;
static P2W_PROC_SOURCE pcm2way_proc_source; //0: undefine. 1: normal pcm2way 2: calibration pcm2way 3: vm clibration
static int8 smp_pcm2way_type;
static P2W_Format rec_play_format;
static uint32 mic_bufsize, spk_bufsize, sd_bufsize, se_bufsize; //unit is 8-bit
static uint16 PCM_SE_BUF[MAX_SIZE_OF_PCM_SE_BUF];
static uint16 PCM_SPK_BUF[MAX_SIZE_OF_PCM_SPK_BUF]; 
static uint16 PCM_MIC_BUF[MAX_SIZE_OF_PCM_MIC_BUF]; 
static uint16 PCM_SD_BUF[MAX_SIZE_OF_PCM_SD_BUF];

//kal_int16 SPH_UL_FIR_COEFF[6][45];
//kal_int16 SPH_DL_FIR_COEFF[6][45];
kal_uint16 SPH_VOL_PAR[3][7][4];
//kal_uint16 SPH_MODE_PAR[8][16];

extern unsigned short WB_Speech_Normal_Mode_Para[16];
extern signed short WB_Speech_Output_FIR_Coeff[6][90];
extern signed short WB_Speech_Input_FIR_Coeff[6][90];

static uint16 smp_RecordModeFirMappingCh1[SPC_MAX_NUM_RECORD_SPH_MODE];
static uint16 smp_RecordModeFirMappingCh2[SPC_MAX_NUM_RECORD_SPH_MODE];
static uint8 smp_RecordModeDeviceMapping[SPC_MAX_NUM_RECORD_SPH_MODE];

static SPC_RECORD_INFO_T spcRecordInfo;
static SPC_SPE_INFO_T spcSpeInfo;

static kal_uint32 gNum_drop_frame = 5; // default drop 5 frames


void INVALID_MSG(kal_uint32 u4Msg)
{
    kal_prompt_trace(MOD_L1SP, "INVALID MSG (%x)", u4Msg);
}

kal_uint32 _MessagePacking(kal_uint8  message_group, kal_uint8  message_function,
                                   kal_uint32 message_param)
{
    kal_uint32 u4Message;

    u4Message = ((kal_uint32)(message_group & 0xf) << 28) |
                ((kal_uint32)(message_function & 0xf) << 24) |
                ((kal_uint32)(message_param & 0xffffff) << 0) ;
                
    return u4Message;
}

static void _L1Audio_SmpMsgLog(SMP_MESSAGE_T * prMsg, kal_uint16 state)
{
   AUD_CCCI_MSG_TYPE_T eMsgType;
   
   ASSERT( prMsg != NULL);
   
   eMsgType = (AUD_CCCI_MSG_TYPE_T)((prMsg->message_data & MSG_TYPE_MASK) >> 28);
   
   switch (eMsgType)
   {
      case MSG_TYPE_VOLUME_CTRL:
      case MSG_TYPE_SET_DEVICE:
      case MSG_TYPE_SPEECH_CTRL:
      case MSG_TYPE_DATA_TRANSFER_CTRL:
      case MSG_TYPE_OTHER_API_HANDLER:
      case MSG_TYPE_ACK_FROM_AP:
      {
         kal_uint16 eFunc;
         eFunc = ((prMsg->message_data & MSG_FUNC_MASK) >> 24);
         if(state == 1)
         {
            if(!kal_if_hisr())
               kal_trace(TRACE_INFO, L1AUDIO_PROCESS_COMMAND, prMsg->message_data, prMsg->message_type, prMsg->message_type, eMsgType, eMsgType, eFunc, eFunc + eMsgType * 0x10);
            else
               kal_dev_trace(TRACE_INFO, L1AUDIO_PROCESS_COMMAND, prMsg->message_data, prMsg->message_type, prMsg->message_type, eMsgType, eMsgType, eFunc, eFunc + eMsgType * 0x10);
         }
         if(state == 0)
         {
            if(!kal_if_hisr())
               kal_trace(TRACE_INFO, L1AUDIO_RECEIVE_COMMAND, prMsg->message_data, prMsg->message_type, prMsg->message_type, eMsgType, eMsgType, eFunc, eFunc + eMsgType * 0x10);
            else
               kal_dev_trace(TRACE_INFO, L1AUDIO_RECEIVE_COMMAND, prMsg->message_data, prMsg->message_type, prMsg->message_type, eMsgType, eMsgType, eFunc, eFunc + eMsgType * 0x10);
         }
         
         break;
      }
      case MSG_TYPE_NOTIFICATION:
      {
         kal_uint16 eNotify;
         kal_uint32 offset, length;
         offset   = (prMsg->message_data<<6)>>19;
         length   = (prMsg->message_data<<19)>>19;
         eNotify = ((prMsg->message_data & (0x3U << 26)) >> 26);
         if(state == 1)
         {
            if(!kal_if_hisr())
               kal_trace(TRACE_INFO, L1AUDIO_PEOCESS_DATA_NOTIFY, prMsg->message_data, prMsg->message_type, prMsg->message_type, eMsgType, eMsgType, eNotify, + eMsgType * 0x10, offset, length);
            else
               kal_dev_trace(TRACE_INFO, L1AUDIO_PEOCESS_DATA_NOTIFY, prMsg->message_data, prMsg->message_type, prMsg->message_type, eMsgType, eMsgType, eNotify, eNotify+ eMsgType * 0x10, offset, length);
         }
         if(state == 0)
         {
            if(!kal_if_hisr())
               kal_trace(TRACE_INFO, L1AUDIO_RECEIVE_DATA_NOTIFY, prMsg->message_data, prMsg->message_type, prMsg->message_type, eMsgType, eMsgType, eNotify, eNotify+ eMsgType * 0x10, offset, length);
            else
               kal_dev_trace(TRACE_INFO, L1AUDIO_RECEIVE_DATA_NOTIFY, prMsg->message_data, prMsg->message_type, prMsg->message_type, eMsgType, eMsgType, eNotify, eNotify+ eMsgType * 0x10, offset, length);
         }
      }
      break;
    default:
        break;
    }


}

void L1Audio_SMP_MsgQueueInit(void)
{
    kal_uint32 u4SavedMask;

    u4SavedMask = SaveAndSetIRQMask();
    
    rSmpSpc.ccciq.read = 0;
    rSmpSpc.ccciq.write = 0;
    kal_mem_set ((void *)rSmpSpc.ccciq.queue , 0, CCCI_MSG_QUEUE_SZ*sizeof(SMP_MESSAGE_T));
    
    RestoreIRQMask(u4SavedMask);
}

void L1Audio_SMP_MsgQueueGet(SMP_MESSAGE_T * prSmpMsg)
{
    kal_uint32 u4SavedMask;

    ASSERT( rSmpSpc.ccciq.read != rSmpSpc.ccciq.write );
    ASSERT( prSmpMsg != NULL);

    u4SavedMask = SaveAndSetIRQMask();
    
    prSmpMsg->message_type = rSmpSpc.ccciq.queue[rSmpSpc.ccciq.read & (CCCI_MSG_QUEUE_SZ-1)].message_type;
    prSmpMsg->message_data = rSmpSpc.ccciq.queue[rSmpSpc.ccciq.read & (CCCI_MSG_QUEUE_SZ-1)].message_data;
    rSmpSpc.ccciq.queue[rSmpSpc.ccciq.read & (CCCI_MSG_QUEUE_SZ-1)].getTime = L1I_GetTimeStamp();
    rSmpSpc.ccciq.read++;

    RestoreIRQMask(u4SavedMask);
    _L1Audio_SmpMsgLog(prSmpMsg, 1);    
}

extern kal_bool isL1AudioMainInitilized( void );
void L1Audio_SMP_MsgQueuePut(SMP_MESSAGE_T * prSmpMsg)
{    
    kal_uint32 u4SavedMask;
    _L1Audio_SmpMsgLog(prSmpMsg, 0);
    // Not Full
    ASSERT( (rSmpSpc.ccciq.write - rSmpSpc.ccciq.read) < CCCI_MSG_QUEUE_SZ );
    ASSERT( prSmpMsg != NULL);

    u4SavedMask = SaveAndSetIRQMask();
    
    rSmpSpc.ccciq.queue[rSmpSpc.ccciq.write & (CCCI_MSG_QUEUE_SZ-1)].message_type = prSmpMsg->message_type;
    rSmpSpc.ccciq.queue[rSmpSpc.ccciq.write & (CCCI_MSG_QUEUE_SZ-1)].message_data = prSmpMsg->message_data;
    rSmpSpc.ccciq.queue[rSmpSpc.ccciq.write & (CCCI_MSG_QUEUE_SZ-1)].putTime = L1I_GetTimeStamp();
    rSmpSpc.ccciq.write++;

    RestoreIRQMask(u4SavedMask);

   //prevent Modem side from processing A2M message before L1AudioMain is initialized, 
   //and just put A2M message into queue to wait the initilization of L1AudioMain      
    if( L1Audio_IsTaskInitilized() )
    	L1Audio_SetEvent(rSmpSpc.smp_audio_id, (void *)0 );
    
}

#ifdef __MT6573_PLATFORM__

#ifndef __L1_STANDALONE__

#if defined(__WM_MODEM__) || defined(__ANDROID_MODEM__)

void spc_A2M_hisr(CCCI_BUFF_T *bufp)
{
   kal_uint32 ccciMsg;
   SMP_MESSAGE_T rSmpMsg;

   /* confirm the channel buffer type */
   if (!CCCI_IS_MAILBOX(bufp)) {
       ASSERT(0);
   }

   /* get the mailbox id */
   ccciMsg = CCCI_MAILBOX_ID(bufp);

   rSmpMsg.message_type = SPC_ID_AUDIO_A2M_CCCI;
   rSmpMsg.message_data = ccciMsg;
   L1Audio_SMP_MsgQueuePut(&rSmpMsg);
}

void spc_M2A_hisr(CCCI_BUFF_T *bufp)
{

}

#endif

#endif

#endif  /* __MT6573_PLATFORM__ */


kal_bool SMP_IsFeatureSupport_HdRecord(void)
{
	return (g_Spc_FeatureList & 0x1)!=0;
}


short mode_Para_Unitest_spc[16] = {
   96,   221,  16388,     30,   57351,     31,   400,     0,
  4112,	4325,      11,        0,       0,      0,     0,  8192
};

void L1SP_SetSpeechMode_Adaptation( uint8 mode )
{
   uint8 fir_mode;
   
   int16 totalModeNum;

   //because Smart phone only has 8 speech mode, which is different from l1audio.h's definition. 
   //As the result, we need to mapping the mode into the correct one. 
   totalModeNum = (SPH_MODE_UNDEFINED-1) + l1sp_getNumOfRecordMode();
   if (mode >= totalModeNum) {
      ASSERT(0);
   }
   // if( mode >= SPH_MODE_BT_EARPHONE && mode < SPH_MODE_UNDEFINED )
   //   fir_mode = 3; // set as BT FIR, others set as 0: normal, 1: earphone, 2: handfree
   // else 
   //   fir_mode = mode;

#if defined(ADAPT_MODEM_META)
   L1SP_SetSidetoneVolume(acoustic_data.volume_gain[0][VOL_TYPE_SID][acoustic_data.volume[0][VOL_TYPE_SID]]);
#endif

   //L1SP_Write_Audio_Coefficients( SPH_UL_FIR_COEFF[fir_mode], SPH_DL_FIR_COEFF[fir_mode] );
   

   //if(rSmpSpc.has_wb_dlfir_para && rSmpSpc.has_wb_ulfir_para)
   //   L1SP_Write_WB_Audio_Coefficients( WB_SPH_UL_FIR_COEFF[fir_mode], WB_SPH_DL_FIR_COEFF[fir_mode] );
   //if(rSmpSpc.has_wb_mode_para)
   //   L1SP_SetWbSpeechPara( WB_SPH_MODE_PAR[mode] );

   
   //L1SP_SetSpeechMode(mode, SPH_MODE_PAR[mode]);

   // [REMIND] Because Smart phone only has 8 speech mode, which is different from l1audio.h's definition. 
   //As the result, we need to mapping the mode into the correct one. 
   if(mode < (SPH_MODE_UNDEFINED-1)) // index of scene inside the device mode. 
      L1SP_SetSpeechEnhanceAndFir(mode, SPH_ENH_AND_FIR_UPDATE_TYPE_ALL);
   else { //index in HD recording. 
   	  if(SMP_IsFeatureSupport_HdRecord()) {
	   	  L1SP_SetSpeechEnhanceAndFir((mode+1), SPH_ENH_AND_FIR_UPDATE_TYPE_ALL);
   	  } else {
   	      ASSERT(0); //AP did not set hd record but use the mode index!! 
   	  }
   	}
   
   L1SP_SetMicrophoneVolume( rSmpSpc.sph_ul_vol );
}


/**
	This function will send message to AP side.
	When message send fail, it will retry 3 times. 
	Finally the function will return a value to indicate the message sending is okey or not. 
	
	@return: <0 is message send fail with 3 times retry. 0 is message send successfully.
*/
static kal_int32 spc_M2A_send_message(kal_uint32 msg)
{
#if defined(__SMART_PHONE_MODEM__)

#ifdef __MT6573_PLATFORM__
#if defined(__WM_MODEM__) || defined(__ANDROID_MODEM__)

   kal_uint32 ret, i = 0;
   kal_int32 result = 0;

   ret = ccci_mailbox_write(CCCI_PCM_CHANNEL, msg);   
   kal_trace(TRACE_INFO, L1AUDIO_SEND_M2A_MESSAGE, msg);
   
   while( ret != CCCI_SUCCESS ){
      kal_trace(TRACE_INFO, L1AUDIO_SEND_M2A_MESSAGE_FAIL, msg, ret);
	  
      //ASSERT( i++ != 5 );
      if(i == 3) {
         result = -1;
		 break;
      }
      i++;
      kal_sleep_task(1);
      ret = ccci_mailbox_write(CCCI_PCM_CHANNEL, msg);
   }

   return result;
#endif /* defined(__WM_MODEM__) || defined(__ANDROID_MODEM__) */   
#else

   CLI_SendMsg(msg);
   return 0;
   
#endif

#endif
}

// To handle the 4 way buffer
void spc_pcm4way_handler( void )
{
    SMP_MESSAGE_T rMsg;
    SMP_MESSAGE_DATA_T rMsgData;
    
    if( rSmpSpc.pcmSpk_waiting == KAL_TRUE 
		&& rSmpSpc.pcmMic_waiting == KAL_TRUE){		   
       kal_trace( TRACE_INFO, L1AUDIO_SPC_M2A_DROP, 0);
       return;
    }
    rMsg.message_type = SPC_ID_AUDIO_STRM_PCM4WAY_DATA;
    rMsgData.message_group    = 0;
    rMsgData.message_function = 0;
    rMsgData.message_param    = 0;  

    rMsg.message_data = _MessagePacking(rMsgData.message_group, rMsgData.message_function,
                                        rMsgData.message_param);

   // SE buffer
   if (pcm_buffer_ind & 0x01) {
      PCM4WAY_PutToSE((const uint16*)PCM_SE_BUF);
   }

   // Speaker buffer
   if (pcm_buffer_ind & 0x02) {
      PCM4WAY_PutToSpk((const uint16*)PCM_SPK_BUF);
   }

   // Microphone buffer
   if (pcm_buffer_ind & 0x04) {
      PCM4WAY_GetFromMic((uint16*)PCM_MIC_BUF);
   }

   // SD buffer
   if (pcm_buffer_ind & 0x08) {
      PCM4WAY_GetFromSD((uint16*)PCM_SD_BUF);
   }

   // Transfer to l1audio task
   // Send notification and request
   L1Audio_SMP_MsgQueuePut(&rMsg);
   rSmpSpc.pcmSpk_waiting = KAL_TRUE;
   rSmpSpc.pcmMic_waiting = KAL_TRUE;
}

void spc_pcm2way_handler( void )
{
    SMP_MESSAGE_T rMsg;
    SMP_MESSAGE_DATA_T rMsgData;

    if( rSmpSpc.pcmSpk_waiting == KAL_TRUE 
		&& rSmpSpc.pcmMic_waiting == KAL_TRUE){
		 kal_trace( TRACE_INFO, L1AUDIO_SPC_M2A_DROP, 1);
       return;
    }
    rMsg.message_type = SPC_ID_AUDIO_STRM_PCM4WAY_DATA;
    rMsgData.message_group    = 0;
    rMsgData.message_function = 0;
    rMsgData.message_param    = 0;  

    rMsg.message_data = _MessagePacking(rMsgData.message_group, rMsgData.message_function,
                                        rMsgData.message_param);

   // Speaker buffer
   if (pcm_buffer_ind & 0x02) {
      PCM2WAY_PutToSpk((const uint16*)PCM_SPK_BUF);
   }

   // Microphone buffer
   if (pcm_buffer_ind & 0x04) {
      PCM2WAY_GetFromMic((uint16*)PCM_MIC_BUF);
   }

   // Transfer to l1audio task
   // Send notification and request
   L1Audio_SMP_MsgQueuePut(&rMsg);
   rSmpSpc.pcmSpk_waiting = KAL_TRUE;
   rSmpSpc.pcmMic_waiting = KAL_TRUE;
}

void spc_RequestBgsData(void)
{
    SMP_MESSAGE_T rMsg;
    SMP_MESSAGE_DATA_T rMsgData;

    rMsg.message_type = SPC_ID_AUDIO_STRM_BGSND_DATA_REQUEST;
    rMsgData.message_group    = 0;
    rMsgData.message_function = 0;
    rMsgData.message_param    = 0; 
    //Dummmy message here, in L1Audio_SMP_MsgHandler will give correct message
    rMsg.message_data = _MessagePacking(rMsgData.message_group, rMsgData.message_function,
                                        rMsgData.message_param);

    // Transfer to l1audio task
    // Send notification and request
    L1Audio_SMP_MsgQueuePut(&rMsg);
}

void spc_RequestPcmData(void)
{
    SMP_MESSAGE_T rMsg;
    SMP_MESSAGE_DATA_T rMsgData;

    rMsg.message_type = SPC_ID_AUDIO_STRM_PCM_DATA_REQUEST;
    rMsgData.message_group    = 0;
    rMsgData.message_function = 0;
    rMsgData.message_param    = 0;  

    rMsg.message_data = _MessagePacking(rMsgData.message_group, rMsgData.message_function,
                                        rMsgData.message_param);

    // Transfer to l1audio task
    // Send notification and request
    L1Audio_SMP_MsgQueuePut(&rMsg);
}


/**
	@param: to choose use which buffer 
	@type: only using when param==0x6 (pcm2way cases), whithout speech on
*/
void PCMWAY_Start(kal_uint32 param, kal_uint32 type)
{
   // Bit0 : SE buffer
   // Bit1 : Speaker Buffer
   // Bit2 : Microphone Buffer
   // Bit3 : SD Buffer
   pcm_buffer_ind = param & 0x0F;
   ASSERT(pcm_buffer_ind != 0);
   
   memset( (kal_uint8 *)PCM_SE_BUF, 0, MAX_SIZE_OF_PCM_SE_BUF*sizeof(uint16) );
   memset( (kal_uint8 *)PCM_SPK_BUF, 0, MAX_SIZE_OF_PCM_SPK_BUF*sizeof(uint16) );
   memset( (kal_uint8 *)PCM_MIC_BUF, 0, MAX_SIZE_OF_PCM_MIC_BUF*sizeof(uint16) );
   memset( (kal_uint8 *)PCM_SD_BUF, 0, MAX_SIZE_OF_PCM_SD_BUF*sizeof(uint16) );

   rSmpSpc.pcmSpk_waiting = KAL_FALSE;
   rSmpSpc.pcmMic_waiting = KAL_FALSE;
   if( param == 0x6 ){ // only speaker and microphone buffer enable
      if( AM_IsSpeechOn() ){
	  	 smp_pcm2way_type = P2W_APP_TYPE_UNDER_CALL;
         //PCM2WAY_Start(spc_pcm2way_handler, 0);
      }
      else {
	  	if(P2W_APP_TYPE_REC_ONLY_CAL == type || P2W_APP_TYPE_REC_PLAY_CAL == type){
			smp_pcm2way_type = type;
	  	} else {
	  		smp_pcm2way_type = P2W_APP_TYPE_VOIP;
	  	}
         //PCM2WAY_Start(spc_pcm2way_handler, 2);
      }
	  PCM2WAY_Start(spc_pcm2way_handler, smp_pcm2way_type);
   }
   else if ( (param & 0x09) ) {
      PCM4WAY_Start(spc_pcm4way_handler, 0);  //FIXME
   } else {
      smp_pcm2way_type = P2W_APP_TYPE_VOIP;
      PCM2WAY_Start(spc_pcm2way_handler, smp_pcm2way_type);
   }
}

// To disable the 4 way buffer
void PCMWAY_Stop(void)
{
   ASSERT(pcm_buffer_ind != 0);
   
   if( pcm_buffer_ind == 0x6 ){ // only speaker and microphone buffer enable
      ASSERT(smp_pcm2way_type != -1);
	  
      if( AM_IsSpeechOn() )
         PCM2WAY_Stop(smp_pcm2way_type);
      else
         PCM2WAY_Stop(smp_pcm2way_type);//2);
      smp_pcm2way_type = -1;
   }
   else if ( (pcm_buffer_ind & 0x09) ) {
      PCM4WAY_Stop(0);
   } else {
      ASSERT(smp_pcm2way_type != -1);
	  
      PCM2WAY_Stop(smp_pcm2way_type);
	  smp_pcm2way_type = -1;
   }
}

// For VM and PCM record (8k Hz)
void strm_record_event_handler( Media_Event event )
{

}


// FIXME

//static kal_bool fgWavWB = KAL_TRUE;

static void pcm2way_dmnrRecordOnlyStart(P2W_Format format)
{
	kal_uint32 tempU2MicBufSize, tempU2SpkBufSize;
    sd_bufsize = se_bufsize = 0;
       
    rec_play_format = (P2W_Format)format;
    PCM2WAY_QueryBufSize(rec_play_format, &tempU2MicBufSize, &tempU2SpkBufSize);
    mic_bufsize = tempU2MicBufSize << 1;
    spk_bufsize = tempU2SpkBufSize << 1;
    PCM2Way_SetFormat(rec_play_format);

    PCMWAY_Start(0x6, P2W_APP_TYPE_REC_ONLY_CAL); //type 3 is record only in pcm2way
    SET_SPC_USAGE(SPC_PCMWAY_USAGE);
}

static void pcm2way_dmnrRecordOnlyStop(void)
{
	if(IS_SPC_USED(SPC_PCMWAY_USAGE)){  
       PCMWAY_Stop();
       RESET_SPC_USAGE(SPC_PCMWAY_USAGE);
    }else{
       // kal_prompt_trace(MOD_L1SP, "illegal A2P message");
       kal_trace( TRACE_INFO, L1AUDIO_SPC_A2M_ILLEGAL, 0);
    }

    if(rec_play_format != P2W_FORMAT_NORMAL)
       PCM2Way_SetFormat(P2W_FORMAT_NORMAL);		 
	
    mic_bufsize = spk_bufsize = 0;
	rec_play_format = 0;
}

extern void CTM_EnableDebugLog( kal_bool bEnable );

void Record_Start(kal_uint32 param)
{
#if defined(__CTM_SUPPORT__)
   if ((param & 0xFFF) == 3) {
      CTM_EnableDebugLog( KAL_TRUE );
   } else
#endif
   if ((param & 0xFFF) == 2) {
   	  //rewrite the function to use pcm2way recording for DMNR calibration   	  
	  ASSERT(!AM_IsSpeechOn());
	  /*
      // VM Record      
      Media_SetBuffer ( (uint16 *)strmBuffer, sizeof(strmBuffer)/sizeof(uint16) );
      //Media_SetRBThreshold(MEDIA_RB_DEFAULT_THRESHOLD);
      Media_Record( MEDIA_FORMAT_GSM_HR, strm_record_event_handler, NULL );//HR --> 8k DMNR VM
       */
      //pcm2way for calibration record only on 	  
      pcm2way_proc_source = P2W_PROC_SOURCE_VM_CALIBRAION;
      pcm2way_dmnrRecordOnlyStart(P2W_FORMAT_CAL);
   }else if ((param & 0xFFF) == 1) {
      // VM Record
      rSmpSpc.record_data_waiting = KAL_FALSE;      
      Media_SetBuffer ( (uint16 *)strmBuffer, sizeof(strmBuffer)/sizeof(uint16) );

	  spcRecordInfo.format = 2;
      Media_Record( MEDIA_FORMAT_GSM_FR, strm_record_event_handler, NULL );
   } else if ( (param & 0xFFF) == 0 ){ 
      // PCM Record      
      kal_uint32 sampleRate, channelNumIndex; 
	  
      rSmpSpc.record_data_waiting = KAL_FALSE;
      Media_SetBuffer ( (uint16 *) strmBuffer, sizeof(strmBuffer)/sizeof(uint16) );
      //Media_SetRBThreshold(MEDIA_RB_DEFAULT_THRESHOLD * 2);

      spcRecordInfo.format = 1;
	  sampleRate = ((param >> 12)& 0xF);
	  channelNumIndex = param >> 16;

	  spcRecordInfo.channelNum = channelNumIndex + 1;
	  spcRecordInfo.sampleRateIndex = sampleRate;
	  wavSetDropFrame(gNum_drop_frame);
	  
      if( sampleRate == 0 ) //8k, should use when phone call
      {
         // un supported recording samping rate (8k) in DSP
		 if(channelNumIndex == 0) // mono
         	Media_Record( MEDIA_FORMAT_WAV_DVI_ADPCM, strm_record_event_handler, NULL );
		 else { //stereo
		 	//Media_Record( MEDIA_FORMAT_WAV_DVI_ADPCM, strm_record_event_handler, NULL );
		 }
      }   
	  else if ( sampleRate == 1 ) //16k 
      {
		 if(channelNumIndex == 0) // mono
         	Media_Record( MEDIA_FORMAT_WAV_DVI_ADPCM_16K, strm_record_event_handler, NULL );
		 else { //should be 1, stereo
		 	Media_Record( MEDIA_FORMAT_PCM_16K_STEREO, strm_record_event_handler, NULL );
		 }		
      }
      else
         ASSERT(0);
   } else {
      ASSERT(0);
   }
}

void Record_Stop(kal_uint32 param)
{
#if defined(__CTM_SUPPORT__)
   if ((param & 0xFFF) == 3) {
      CTM_EnableDebugLog( KAL_FALSE );
   } else
#endif
   if (P2W_PROC_SOURCE_VM_CALIBRAION == pcm2way_proc_source){
   	  pcm2way_dmnrRecordOnlyStop();
      pcm2way_proc_source = P2W_PROC_SOURCE_UNDEF;
   } else {
      Media_Stop();
   }
}

void strm_playback_event_handler( MHdl *handle, Media_Event event )
{

}

void Playback_Start(kal_uint32 param)
{
   if (param == 0) {
      // PCM Playback
      Media_PCM_Stream_Param strm_pcm_param;
      FC_Buf * prFcBuf;
      
      strm_pcm_param.isStereo      = false;
      strm_pcm_param.bitPerSample  = 16;
      strm_pcm_param.sampleFreq    = 16000;

      prFcBuf = L1Audio_FC_GetAudioBufferHeader();
      
      rSmpSpc.vm_pcm_playback_Handle = PCM_Strm_Open(strm_playback_event_handler, (void *) &strm_pcm_param);
      rSmpSpc.vm_pcm_playback_Handle->SetBuffer(rSmpSpc.vm_pcm_playback_Handle, prFcBuf->pBuf, prFcBuf->uBufLength);

      // KH: should fill buffer here
      rSmpSpc.vm_pcm_playback_Handle->Play(rSmpSpc.vm_pcm_playback_Handle);
   } else if (param == 1) {
      // VM Playback
      STFSAL *hdlSTFSAL = NULL;
      Media_VM_PCM_Param vm_param;
      FC_Buf * prFcBuf;

      // FIXME testing
      vm_param.mediaType = MEDIA_FORMAT_GSM_FR;
      vm_param.vmParam   = 0; // MEDIA_VMP_AS_SPEECH; // FIXME

      prFcBuf = L1Audio_FC_GetAudioBufferHeader();

      rSmpSpc.vm_pcm_playback_Handle = VM_Open(strm_playback_event_handler, hdlSTFSAL, &vm_param);
      rSmpSpc.vm_pcm_playback_Handle->SetBuffer(rSmpSpc.vm_pcm_playback_Handle, prFcBuf->pBuf, prFcBuf->uBufLength);

      // KH: should fill buffer here
      rSmpSpc.vm_pcm_playback_Handle->Play(rSmpSpc.vm_pcm_playback_Handle);
   } else {
      ASSERT(0);
   }

}

void Playback_Stop(void)
{
   rSmpSpc.vm_pcm_playback_Handle->Stop(rSmpSpc.vm_pcm_playback_Handle);
   rSmpSpc.vm_pcm_playback_Handle->Close(rSmpSpc.vm_pcm_playback_Handle);
}

void spc_Data_Transfer_Control(kal_uint32 ccciMsg)
{
   kal_uint32 funcType, param;

   funcType = (ccciMsg<<4)>>28;
   param    = (ccciMsg<<12)>>12;

   switch (funcType) {
      case 0: {//NB case only in current status 
         //mic_bufsize = spk_bufsize = sd_bufsize = se_bufsize = 160 << 1;
		 kal_uint32 typeForPcm2way = P2W_APP_TYPE_UNDER_CALL;

		 pcm2way_proc_source = P2W_PROC_SOURCE_NORMAL;
		 
		 if(param== 0x6){
		 	//NB, query the buffer size (unit is uint16)
		 	kal_uint32 tempU2MicBufSize, tempU2SpkBufSize;
		 	PCM2WAY_QueryBufSize(P2W_FORMAT_NORMAL, &tempU2MicBufSize, &tempU2SpkBufSize);
			mic_bufsize = tempU2MicBufSize << 1;
			spk_bufsize = tempU2SpkBufSize << 1;
			sd_bufsize = 0;
			se_bufsize = 0;
		 } else {
		 	mic_bufsize = spk_bufsize = sd_bufsize = se_bufsize = 160 << 1;
		 }
		 
         PCMWAY_Start(param, typeForPcm2way);
         SET_SPC_USAGE(SPC_PCMWAY_USAGE);
         
         spc_M2A_send_message( ccciMsg | 0x80000000 );
         break;
      }
      case 1:
         if(IS_SPC_USED(SPC_PCMWAY_USAGE)){            
            PCMWAY_Stop();
            RESET_SPC_USAGE(SPC_PCMWAY_USAGE);
         }else{
            // kal_prompt_trace(MOD_L1SP, "illegal A2P message");
            kal_trace( TRACE_INFO, L1AUDIO_SPC_A2M_ILLEGAL, ccciMsg);
         }

		 
         pcm2way_proc_source = P2W_PROC_SOURCE_UNDEF;
         spc_M2A_send_message( ccciMsg | 0x80000000 );
         break;
      case 2:
         Playback_Start(param);
         break;
      case 3:
         Playback_Stop();
         break;
      case 4:
         Record_Start(param);
         SET_SPC_USAGE(SPC_RECORD_USAGE);
         
         spc_M2A_send_message( ccciMsg | 0x80000000 );
         break;
      case 5:
         if(IS_SPC_USED(SPC_RECORD_USAGE)){  
            Record_Stop(param);
            RESET_SPC_USAGE(SPC_RECORD_USAGE);
         }else{
            // kal_prompt_trace(MOD_L1SP, "illegal A2P message");  
            kal_trace( TRACE_INFO, L1AUDIO_SPC_A2M_ILLEGAL, ccciMsg);
         }

         spc_M2A_send_message( ccciMsg | 0x80000000 );
         break;
      case 6: { //pcm2way for calibration record play on 
      	 kal_uint32 tempU2MicBufSize, tempU2SpkBufSize;

		 pcm2way_proc_source = P2W_PROC_SOURCE_CALIBRATION;
		 
         sd_bufsize = se_bufsize = 0;
       
         rec_play_format = (P2W_Format)param;
         PCM2WAY_QueryBufSize(rec_play_format, &tempU2MicBufSize, &tempU2SpkBufSize);
         mic_bufsize = tempU2MicBufSize << 1;
         spk_bufsize = tempU2SpkBufSize << 1;
         PCM2Way_SetFormat(rec_play_format);

         PCMWAY_Start(0x6, P2W_APP_TYPE_REC_PLAY_CAL); //type 4 is record play in pcm2way
         SET_SPC_USAGE(SPC_PCMWAY_USAGE);
         
         spc_M2A_send_message( ccciMsg | 0x80000000 );
         break;
      }
      case 7:  //pcm2way for calibration record play off
         if(IS_SPC_USED(SPC_PCMWAY_USAGE)){  
            PCMWAY_Stop();
            RESET_SPC_USAGE(SPC_PCMWAY_USAGE);
         }else{
            // kal_prompt_trace(MOD_L1SP, "illegal A2P message");
            kal_trace( TRACE_INFO, L1AUDIO_SPC_A2M_ILLEGAL, ccciMsg);
         }

         if(rec_play_format != P2W_FORMAT_NORMAL)
    	      PCM2Way_SetFormat(P2W_FORMAT_NORMAL);
    	 mic_bufsize = spk_bufsize = 0;
		 rec_play_format = 0;

		 pcm2way_proc_source = P2W_PROC_SOURCE_UNDEF;
		 
         spc_M2A_send_message( ccciMsg | 0x80000000 );
         break;             
	  case 8: { //pcm2way for calibration record only on 
	  
         pcm2way_proc_source = P2W_PROC_SOURCE_CALIBRATION;
         pcm2way_dmnrRecordOnlyStart((P2W_Format)param);
         spc_M2A_send_message( ccciMsg | 0x80000000 );
         break;
	  }
	  case 9: //pcm2way for calibration record only off

		 pcm2way_dmnrRecordOnlyStop();
		 pcm2way_proc_source = P2W_PROC_SOURCE_UNDEF;
		 
       spc_M2A_send_message( ccciMsg | 0x80000000 );
	  	 break;
	  case 10:
	   
	    if(!AM_IsRecordOn()){//avoid change value during recording
	      gNum_drop_frame = param;
	      kal_prompt_trace(MOD_L1SP, "[DEBUG] set drop_frame =%x", param);
	    }else{
	      kal_prompt_trace(MOD_L1SP, "[DEBUG] skip set drop_frame =%x", param);
	    }
	    spc_M2A_send_message( ccciMsg | 0x80000000 );
	    break; 
      default:
         INVALID_MSG(funcType);
         //ASSERT(0);
   }
}

/* Buffer Control for Write (to MD buffer) */
static void spc_WriteWordToMDBuffer(uint32 *writePos, uint16 data)
{
   uint8  *bSrcPtr;
   uint16 *wSrcPtr;
   uint32 cachePos;

   cachePos = *writePos;
   bSrcPtr = rSmpSpc.md_share_buf;
   bSrcPtr += cachePos;
   wSrcPtr = (uint16 *)bSrcPtr;
   *wSrcPtr = data;

   cachePos += 2;
   if (cachePos >= rSmpSpc.md_share_buf_size)
      cachePos = 0;
   *writePos = cachePos;
}

static void spc_WriteMDBufferSegment(uint32 length)
{
   uint8 *bDestPtr;
   uint16 *wSrcPtr;
   uint32 wLen, bLen;

   bDestPtr = rSmpSpc.md_share_buf;
   bDestPtr += rSmpSpc.write;

   /* Process the first segment of media bufer */
   Media_GetReadBuffer(&wSrcPtr, &wLen);
   bLen = wLen<<1;
   if (bLen > length)
      bLen = length;
   memcpy(bDestPtr, wSrcPtr, bLen*sizeof(uint8));
   Media_ReadDataDone(bLen>>1);
   bDestPtr += bLen;

   /* Process the second segment of media bufer */
   bLen = length - bLen;
   if (bLen > 0) {
      Media_GetReadBuffer(&wSrcPtr, &wLen);
      memcpy(bDestPtr, wSrcPtr, bLen*sizeof(uint8));
      Media_ReadDataDone(bLen>>1);
   }

   /* Update the write pointer */
   rSmpSpc.write += length;
   if (rSmpSpc.write >= rSmpSpc.md_share_buf_size) {
      rSmpSpc.write -= rSmpSpc.md_share_buf_size;
   }
}

kal_int16 ai2DataBuf__[640];

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
#endif 

static void spc_RecordWriteMDBufferSegment(kal_uint8 * pu1SrcAddr, uint32 length)
{
   uint8 *bDestPtr;
   uint16 *wSrcPtr;
   uint32 wLen, bLen;
   uint32 u4DataCnt = 0;

   bDestPtr = rSmpSpc.md_share_buf;
   bDestPtr += rSmpSpc.write;
   
   memcpy(bDestPtr, pu1SrcAddr, length*sizeof(uint8));

   /* Update the write pointer */
   rSmpSpc.write += length;
   if (rSmpSpc.write >= rSmpSpc.md_share_buf_size) {
      rSmpSpc.write -= rSmpSpc.md_share_buf_size;
   }
}

/* Return the offset and length */
void spc_RecordWriteToMDBuffer(uint32 *length, uint16 bufType)
{
   uint32 freeLength, segment;
   uint32 u4DataCnt;
   kal_uint8 * pu1SrcAddr;

   /* Get the free space */
   if (rSmpSpc.write >= rSmpSpc.read)
      freeLength = rSmpSpc.md_share_buf_size + rSmpSpc.read - rSmpSpc.write - 1;
   else
      freeLength = rSmpSpc.read - rSmpSpc.write - 1;

   kal_prompt_trace(MOD_L1SP, "[r,w] = (%x)(%x)", rSmpSpc.read, rSmpSpc.write);  

   /* Exclude the overhead of sync word, data type, and length */
   freeLength = freeLength & ~0x01;
   if (freeLength < 6) {
      *length = 0;
      return;
   }

   freeLength -= 6;
   if ( freeLength >= (*length) )
      freeLength = (*length);
   *length = freeLength;

   /* Write sync word, data type, and length */
   spc_WriteWordToMDBuffer(&rSmpSpc.write, 0x2A2A);
   spc_WriteWordToMDBuffer(&rSmpSpc.write, bufType);
   spc_WriteWordToMDBuffer(&rSmpSpc.write, freeLength);

   /* Get Data */   
   u4DataCnt = (spcRecordInfo.sampleRateIndex) ? 320: 160; //spcRecordInfo.sampleRateIndex 0==> 8k, 1==> 16k  
   u4DataCnt = u4DataCnt << (spcRecordInfo.channelNum); // mono or stereo. 
   /*
#if defined(__DUAL_MIC_SUPPORT__) && defined(__HQA_AUDIO__)
   if (AFE_IsDualMic())
   {
     u4DataCnt = u4DataCnt << 1;
   }
#endif
   */

   if(spcRecordInfo.channelNum>1 && AFE_GetInputSource()== L1SP_MICROPHONE2) {
		// when "stereo record" with input source is headphone mic 
		wavGetRecordData(ai2DataBuf__, u4DataCnt, KAL_TRUE, KAL_TRUE);
   } else {
		wavGetRecordData(ai2DataBuf__, u4DataCnt, KAL_FALSE, KAL_FALSE);
   }

   
   pu1SrcAddr =  (uint8 *)ai2DataBuf__;

   /* Process the first segemnt */
   segment = rSmpSpc.md_share_buf_size - rSmpSpc.write;
   if (segment > freeLength )
      segment = freeLength;
   spc_RecordWriteMDBufferSegment(pu1SrcAddr, segment);

   // 
   pu1SrcAddr += segment; 

   /* Process the second segemnt */
   segment = freeLength - segment;
   if (segment > 0 ) {
      spc_RecordWriteMDBufferSegment(pu1SrcAddr, segment);
   }
}

/* Return the offset and length */
void spc_VMWriteToMDBuffer(uint32 *length, uint16 bufType, uint16 type, kal_uint8 *bufPtr )
{
   uint32 freeLength, segment;
   kal_uint8 *bufPtr2 = NULL;

   /* Get the free space */
   if (rSmpSpc.write >= rSmpSpc.read)
      freeLength = rSmpSpc.md_share_buf_size + rSmpSpc.read - rSmpSpc.write - 1;
   else
      freeLength = rSmpSpc.read - rSmpSpc.write - 1;

   /* Exclude the overhead of sync word, data type, and length */
   freeLength = freeLength & ~0x01;
   if (freeLength < 6) {
      *length = 0;
      return;
   }

   freeLength -= 6;
   if ( freeLength >= (*length) )
      freeLength = (*length);
   *length = freeLength;

   /* Write sync word, data type, and length */
   spc_WriteWordToMDBuffer(&rSmpSpc.write, 0x2A2A);
   spc_WriteWordToMDBuffer(&rSmpSpc.write, bufType);
   spc_WriteWordToMDBuffer(&rSmpSpc.write, freeLength);

   /* Process the first segemnt */
   segment = rSmpSpc.md_share_buf_size - rSmpSpc.write;
   if (segment > freeLength )
      segment = freeLength;
   if( type == 0)
      spc_WriteMDBufferSegment(segment);
   else{
      memcpy( rSmpSpc.md_share_buf + rSmpSpc.write, bufPtr, segment );
      rSmpSpc.write += segment;
      if (rSmpSpc.write >= rSmpSpc.md_share_buf_size) {
         rSmpSpc.write -= rSmpSpc.md_share_buf_size;
      }
      bufPtr2 = bufPtr + segment;
   }

   /* Process the second segemnt */
   segment = freeLength - segment;
   if (segment > 0 ) {
      if( type == 0)
         spc_WriteMDBufferSegment(segment);
      else{
         memcpy( rSmpSpc.md_share_buf, bufPtr2, segment );
         rSmpSpc.write += segment;
         if (rSmpSpc.write >= rSmpSpc.md_share_buf_size) {
            rSmpSpc.write -= rSmpSpc.md_share_buf_size;
         }
      }
   }
}

void spc_CTMWriteToMDBuffer( kal_uint8 *ptr, kal_uint32 length, kal_bool sendMsg )
{
   static kal_uint16 ctm_debugCount = 0, ctm_MDBufferOffset;
   
   if( ctm_debugCount == 0 )
      ctm_MDBufferOffset = rSmpSpc.write;
   ctm_debugCount += length;
   spc_VMWriteToMDBuffer(&length, 0x0004, 1, ptr);
   if( ctm_debugCount == 1280 && sendMsg == KAL_TRUE ){
      uint32 ccciMsg = 0;
      //send message
      ccciMsg = 0x94000000 | (ctm_MDBufferOffset<<13) | ( ctm_debugCount + 6 * 4 );
      spc_M2A_send_message(ccciMsg);
      rSmpSpc.read = rSmpSpc.write;
      ctm_debugCount = 0;
   } else if( sendMsg == KAL_TRUE ){
      ctm_debugCount = 0; //reset count
   }
}

void vmRecordHandler(kal_uint16 msgOp, kal_uint16 u2Type)
{
    uint32 dataCount, offset;
    if(rSmpSpc.record_data_waiting){
      kal_trace( TRACE_INFO, L1AUDIO_SPC_M2A_DROP, 2);
      return;    
   }

    mediaHandler( (void *)MEDIA_DATA_NOTIFICATION );
    dataCount = (uint32) mediaGetDataCount();
    dataCount = dataCount<<1;   // in byte
    offset = rSmpSpc.write;

    if (dataCount != 0) {
       uint32 ccciMsg = 0;

       spc_VMWriteToMDBuffer(&dataCount, 0x0004, 0, NULL);
       ccciMsg = 0x94000000 | (offset<<13) | (dataCount+6);

       spc_M2A_send_message(ccciMsg);
       rSmpSpc.read = rSmpSpc.write;  // KH test
       rSmpSpc.record_data_waiting = KAL_TRUE;       
    }
}

void wavRecordHandler(kal_uint16 msgOp, kal_uint16 u2Type)
{
    uint32 dataCount, offset;

    if(rSmpSpc.record_data_waiting){
      wavSkip1FrameData();      
      kal_trace( TRACE_INFO, L1AUDIO_SPC_M2A_DROP, 3);
      return;    
   }

	dataCount = (spcRecordInfo.sampleRateIndex) ? 320: 160; //spcRecordInfo.sampleRateIndex 0==> 8k, 1==> 16k  
	dataCount = dataCount << spcRecordInfo.channelNum; // mono or stereo. & in byte

	kal_prompt_trace(MOD_L1SP, "[temp] dataCount: %d, spcRecordInfo.sampleRateIndex=%d, spcRecordInfo.channelNum=%d",
				dataCount, spcRecordInfo.sampleRateIndex, spcRecordInfo.channelNum);
    /*
#if defined(__DUAL_MIC_SUPPORT__) && defined(__HQA_AUDIO__)
    if (AFE_IsDualMic())
    {
        dataCount = dataCount << 1;      
    }
#endif
     
    dataCount = dataCount<<1;   // in byte
    */
    offset = rSmpSpc.write;

    
    if (dataCount != 0) {
        uint32 ccciMsg = 0;
        if( (msgOp == MSG_SAC2L1AUDIO_SPEECH_IDLE_RECORD_PCM_REQUEST_READ_DATA) ||
            (msgOp == MSG_SAC2L1AUDIO_SPEECH_CALL_RECORD_PCM_REQUEST_READ_DATA))
            
        {
            spc_RecordWriteToMDBuffer(&dataCount, 0x0005);
            ccciMsg = 0x94000000 | (offset<<13) | (dataCount+6);
        }
        else if((msgOp == MSG_SAC2L1AUDIO_SPEECH_IDLE_RECORD_VM_REQUEST_READ_DATA) ||
                (msgOp == MSG_SAC2L1AUDIO_SPEECH_CALL_RECORD_VM_REQUEST_READ_DATA))
        {
            spc_VMWriteToMDBuffer(&dataCount, 0x0004, 0, NULL);                  
            ccciMsg = 0x94000000 | (offset<<13) | (dataCount+6);
        }
        
        spc_M2A_send_message(ccciMsg);
        
        rSmpSpc.read = rSmpSpc.write;  // KH test
    }

    rSmpSpc.record_data_waiting = KAL_TRUE;
}

/**
	@return: result of existing compile option related to speech function
		bit 0: __DUAL_MIC_SUPPORT__
		bit 1: __AMRWB_LINK_SUPPORT__
		bit 2 ~ 15: reserve for future use
*/
static kal_uint16 spc_QueryMdCapability(void)
{
	kal_uint16 result = 0;

	// bit 0
	#if defined(__DUAL_MIC_SUPPORT__) 
	result |= (1<<0);
	#endif // __DUAL_MIC_SUPPORT__

	// bit 1
	#if defined(__AMRWB_LINK_SUPPORT__)
	result |= (1<<1);
	#endif // __AMRWB_LINK_SUPPORT__

	// bit 2 (for future use)
	//
	
	return result;
}

void spc_Volume_Control(kal_uint32 ccciMsg)
{
   kal_uint32 funcType, param;

   funcType = (ccciMsg<<4)>>28;
   param    = (ccciMsg<<8)>>8;

   switch (funcType) {
      case 0:
         {
#if defined(ADAPT_MODEM_META)
            L1SP_SetOutputVolume( acoustic_data.volume_gain[0][VOL_TYPE_SPH][acoustic_data.volume[0][VOL_TYPE_SPH]], 0 );
#else
            int32 dBValue;
            uint8 level, vol;
            int8  digiGain;
            // param is 0~-99dB, Q23.1 format
            dBValue = -(((int32)(param<<8))>>8);
            level = (uint8)(dBValue & 0xFF);
            //The MaxAnalog Gain should be read from NVRAM
            AFE_SetLevelVolume( L1SP_SPEECH, 255, 1, level );
            AFE_GetOutputVolume( L1SP_SPEECH, &vol, &digiGain );
            L1SP_SetOutputVolume( vol, digiGain );
#endif
         }
         break;
      case 1:
         {
#if defined(ADAPT_MODEM_META)
            L1SP_SetMicrophoneVolume( acoustic_data.volume_gain[0][VOL_TYPE_MIC][acoustic_data.volume[0][VOL_TYPE_MIC]] );
#else
            int32 dBValue;
            uint8 gain;

            dBValue = ((int32)(param<<8))>>8; // unit -0.5 dB
            dBValue = (-dBValue) >> 1;        // unit 1 dB
            dBValue = dBValue << 2;           // mapping to the API L1SP_SetMicrophoneVolume input
            if( dBValue > 255 )
               dBValue = 255;
            gain = 255 - dBValue;
            rSmpSpc.sph_ul_vol = gain;
            L1SP_SetMicrophoneVolume( gain );
#endif
         }
         break;
      case 2:
         L1SP_MuteMicrophone( (bool)param );
         break;
      case 3:
         {
            int32 dBValue;
            uint8 gain;

            dBValue = -(((int32)(param<<8))>>8); // unit 0.5 dB
            /* in L1SP_SetSidetoneVolume API every value 16 means 2dB
               dBVlaue= dBValue/4 * 16 = dBValue * 4               */
            dBValue = dBValue << 2;              // mapping to L1SP_SetSidetoneVolume interface
            if( dBValue > 255 )
               dBValue = 255;
            gain = 255 - dBValue;
            L1SP_SetSidetoneVolume( gain );
         }
         break;
      case 4:
         rSmpSpc.gain_tbl_internal_gain = param;

#if defined(__GAIN_TABLE_SUPPORT__)    
         {        
            uint32 total_gain = 0;
            //total_gain  - containes analog gain[26:31](6 bits), digital gain[18:25](8 bits), external amp gain[0:17](18bits)
            total_gain = ((rSmpSpc.gain_tbl_internal_gain & 0x3FFF) << 18);
            AFE_SetOutputGainControl(L1SP_SPEECH, total_gain);
         }   
#endif     
         break;         
      case 5:
         rSmpSpc.gain_tbl_internal_mic_gain = param;

#if defined(__GAIN_TABLE_SUPPORT__)  
         { 
            uint32 total_gain = 0;
            //total_gain  - containes analog gain[26:31](6 bits), digital gain[18:25](8 bits), external amp gain[0:17](18bits)
            total_gain = ((rSmpSpc.gain_tbl_internal_mic_gain & 0x3FFF) << 18);             
            AFE_SetMicGainControl(L1SP_SPEECH, total_gain);          
         }
#endif        
         break;         
         
      case 6:
         L1SP_MuteSpeaker( (bool)param );
         break;

      default:
         INVALID_MSG(funcType);
         //ASSERT(0);
   }
}

void spc_Set_Device(kal_uint32 ccciMsg)
{
   kal_uint32 funcType, param;

   funcType = (ccciMsg<<4)>>28;
   param    = (ccciMsg<<16)>>16;

   switch (funcType) {
      case 0:
         {
            uint8 device = 0;

            if (param == 0) {
               //device = L1SP_SPEAKER1;
               device = L1SP_BUFFER_0;
            } else if (param == 1) {
               //device = L1SP_SPEAKER2;
               device = L1SP_BUFFER_ST;
            } else if (param == 2) {
               device = L1SP_BUFFER_ST | L1SP_BUFFER_EXT | L1SP_BUFFER_ST_M;
            } else if (param == 3){
               // BT Output. The speaker should be turned off
               device = 0;
            } else {
               INVALID_MSG(param);
            }

            L1SP_SetOutputDevice(device);
            Media_SetOutputDevice(device);
            AFE_SetOutputDevice( L1SP_LINEIN, device );
         }
         break;
      case 1:
         {
            uint8 device = 0;

            if (param == 0) {
               device = L1SP_LNA_FMRR;
               AFE_SetDualMic(KAL_FALSE);
            } else if (param == 1) {
               device = L1SP_MICROPHONE1;
               AFE_SetDualMic(KAL_FALSE);
            } else if (param == 2) {
               device = L1SP_MICROPHONE2;
               AFE_SetDualMic(KAL_FALSE);
            } else if (param == 3){
               // BT Iutput. The microphone should be turned off
               device = 0;
               AFE_SetDualMic(KAL_FALSE);
            } else if (param == 4){             
               device = L1SP_LNA_DIGITAL;
               AFE_SetDualMic(KAL_FALSE);
            } else if (param == 5){             
               device = L1SP_MICROPHONE1;
               AFE_SetDualMic(KAL_TRUE);
            } else if (param == 6){             
               device = L1SP_LNA_DIGITAL;
               AFE_SetDualMic(KAL_TRUE);               
            } else {
               INVALID_MSG(param);
            }

            L1SP_SetInputSource( device );
         }
         break;
      case 2:
         {
            if (param == 0) {
               AFE_TurnOffMicBias();
            }else
               AFE_TurnOnMicBias();
         }
         break;
      case 4:
         {
            switch ( param ) {
            case 0: 	
               AFE_SetUseRefMICInLoudSpk(KAL_FALSE);
               break;
            case 1:
               AFE_SetUseRefMICInLoudSpk(KAL_TRUE);
               break;
            case 2:
            	 AFE_SetUseRefMICInIdle(KAL_FALSE);
            	 break;   
            case 3:
            	 AFE_SetUseRefMICInIdle(KAL_TRUE);
            	 break;               	 
            }   
         }
         break;         
         
      default:
         INVALID_MSG(funcType);
   }
}

void spc_Speech_Control(kal_uint32 ccciMsg)
{
   kal_uint32 funcType, param;

   funcType = (ccciMsg<<4)>>28;
   param    = (ccciMsg<<12)>>12;

   switch (funcType) {
      case 0:
         {
            kal_uint8 u1Mode;
            u1Mode = (kal_uint8)param;
            ASSERT(u1Mode <= RAT_3G324M_MODE);
#if defined(__UMTS_RAT__)
            if( u1Mode != RAT_3G324M_MODE )
               u1Mode = RAT_3G_MODE; // Force initial 3G
#else
            u1Mode = RAT_2G_MODE;
#endif
            L1SP_Speech_On( u1Mode );
            rSmpSpc.RAT_Mode = u1Mode;
            spc_M2A_send_message( ccciMsg | 0x80000000 );
         }   
         break;
      case 1:
         L1SP_Speech_Off();
         spc_M2A_send_message( ccciMsg | 0x80000000 );
         break;
      case 2:
         L1SP_Set_DAI_Mode( (uint8)param );
         break;
      case 3:
			// 0: afe loopback (A/D1 => D/A1, A/D2 => D/A2) off
			// 1: afe loopback (A/D1 => D/A1, A/D2 => D/A2) on
			// 2: afe loopback (A/D1 => D/A2, A/D2 => D/A1) off
			// 3: afe loopback (A/D1 => D/A2, A/D2 => D/A1) on
			// 4: afe loopback (A/D1 => D/A1+2, A/D2 => D/A1+2) off
			// 5: afe loopback (A/D1 => D/A1+2, A/D2 => D/A1+2) on
         if( param == 1 || param == 3 || param == 5){
            if( L1SP_GetState() == L1SP_STATE_IDLE ){
				
			   uint16 modeValue[NUM_MODE_PARAS];
			   l1sp_getSpeechModeByIndex(SPH_MODE_NORMAL, modeValue);
			   
               if(L1SP_GetAfeLoopbackStatus()){
                  //kal_prompt_trace(MOD_L1SP, "illegal AFELOOPBACK open");
                  return;  
               }               
               //L1SP_SetSpeechMode(SPH_MODE_NORMAL, SPH_MODE_PAR[0]); 
               L1SP_SetSpeechMode(SPH_MODE_NORMAL, modeValue);
               //L1SP_SetOutputDevice(L1SP_SPEAKER1);
               //L1SP_SetOutputVolume(208, 0);
               //L1SP_SetMicrophoneVolume(136);
               //L1SP_SetInputSource(L1SP_MICROPHONE1);
               L1SP_Speech_On( RAT_2G_MODE );
            }
            if( param == 1 )
               L1SP_SetAfeLoopback( true );
            else if( param == 3 )
               L1SP_SetAfeLoopback2( true );
				else if(param == 5) {
					L1SP_SetAfeLoopback( true );
					L1SP_SetAfeLoopback2( true );
				}
				
         } else {
            if( L1SP_GetState() != L1SP_STATE_IDLE ){
               if(!L1SP_GetAfeLoopbackStatus()){
                  return;  
               }
               
               if( param == 0 )
                  L1SP_SetAfeLoopback( false );
               else if( param == 2 )
                  L1SP_SetAfeLoopback2( false );
					else if(param == 4) {
						L1SP_SetAfeLoopback( false );
						L1SP_SetAfeLoopback2( false );
					}
               L1SP_Speech_Off();
            }
         }
         spc_M2A_send_message( ccciMsg | 0x80000000 );
         break;
        
      case 4: 
           L1SP_SetSpeechMode_Adaptation( (uint8)param );
           spc_M2A_send_message( ccciMsg | 0x80000000 );
         break;
         
      case 5: //Factory mode receiver test, turn on speaker and enable sinewave
         if( (bool)param ){
            if( L1SP_GetState() == L1SP_STATE_IDLE ){
			   uint16 modeValue[NUM_MODE_PARAS];
			   l1sp_getSpeechModeByIndex(SPH_MODE_NORMAL, modeValue);
			   
               L1SP_SetOutputDevice(L1SP_SPEAKER1);
               L1SP_SetOutputVolume(208, 0);
               //L1SP_SetSpeechMode(SPH_MODE_NORMAL, SPH_MODE_PAR[0]);
               L1SP_SetSpeechMode(SPH_MODE_NORMAL, modeValue);
               L1SP_Speech_On( RAT_2G_MODE );
            }
         } else {
            if( L1SP_GetState() != L1SP_STATE_IDLE ){
               L1SP_Speech_Off();
            }
         }
         spc_M2A_send_message( ccciMsg | 0x80000000 ); 
         break;
      case 6:
			{
				uint8 enhanceControl = param&0xf;
         	if(enhanceControl>1) {
					uint16 maskData = (param >> 4); 
					
					if(enhanceControl == 2) {
						if(spcSpeInfo.infoState == 0) {
							spcSpeInfo.infoState = 1;
							spcSpeInfo.isMaskChange = 0;
						}
						
						if(maskData != spcSpeInfo.spe_usr_mask) {
							spcSpeInfo.isMaskChange |= 0x1;
						}
						
						spcSpeInfo.spe_usr_mask = maskData;
						
					} else if (enhanceControl == 3) { //spe_usr_subFunc_mask[0:15]
						if(spcSpeInfo.infoState == 0) {
							spcSpeInfo.infoState = 1;
							spcSpeInfo.isMaskChange = 0;
						}

						if(maskData != (spcSpeInfo.spe_usr_subFunc_mask & 0xFFFF)) {
							spcSpeInfo.isMaskChange |= 0x2;
						}	
						spcSpeInfo.spe_usr_subFunc_mask = ((spcSpeInfo.spe_usr_subFunc_mask & 0xFFFF0000)|maskData);
						
					} else if (enhanceControl == 4) { //update spe_usr_subFunc_mask[16:31]
						if(spcSpeInfo.infoState == 0) {
							spcSpeInfo.infoState = 1;
							spcSpeInfo.isMaskChange = 0;
						}

						if(maskData != (spcSpeInfo.spe_usr_subFunc_mask >> 16)) {
							spcSpeInfo.isMaskChange |= 0x4;
						}
						spcSpeInfo.spe_usr_subFunc_mask = ((spcSpeInfo.spe_usr_subFunc_mask & 0xFFFF)|(maskData<<16));
						
					} else if (enhanceControl == 5) {
						if(spcSpeInfo.infoState == 1) {
							spcSpeInfo.infoState = 2;
							
							if(spcSpeInfo.isMaskChange&0x1) {
								l1sp_updateSpeUsrMaskWithWholeValue(spcSpeInfo.spe_usr_mask);
							}
							if(spcSpeInfo.isMaskChange&0x6) {
								l1sp_updateSpeUsrSubFuncMaskWithWholeValue(spcSpeInfo.spe_usr_subFunc_mask);
							}

							// reset
							spcSpeInfo.isMaskChange = 0;
							spcSpeInfo.infoState = 0;
						} // else ignore the message due to nothing is updated. 
					}

      	   } else {
         	   if( (bool)param ){
            	   SetSpeechEnhancement(true);
	            } else {
   	            SetSpeechEnhancement(false);
      	      }
				}
         }
			spc_M2A_send_message( ccciMsg | 0x80000000 );     
         break;
      case 7:
         if( (bool)param ){
            L1SP_EnableSpeechEnhancement(true);
         } else {
            L1SP_EnableSpeechEnhancement(false);
         }            
         spc_M2A_send_message( ccciMsg | 0x80000000 );         
         break;
      case 8:
			// 0: acoustic loopback (without DMNR) off
			// 1: acoustic loopback (without DMNR) on
			// 2: acoustic loopback (with	  DMNR) off
			// 3: acoustic loopback (with	  DMNR) on
         switch( param ){
         	case 0x0:                    		
            ABF_SetAcousticLoopback(false);
            L1SP_SetDualMicNR(true);
            break;            
         	case 0x1:         	
         		L1SP_SetDualMicNR(false);   	
         		ABF_SetAcousticLoopback(true);
            break;       
			    case 0x2:          			                    					   
				    ABF_SetAcousticLoopback(false);
				    L1SP_SetDualMicNR(true);
				    break;				
				  case 0x3:		
				  	L1SP_SetDualMicNR(true);   	
			      ABF_SetAcousticLoopback(true);
				    break;
         }     
         spc_M2A_send_message( ccciMsg | 0x80000000 );
         break;     
      case 9: //Query the compile option in the modem side. 
         {
		 	kal_uint16 cap;
		 	cap = spc_QueryMdCapability();
			spc_M2A_send_message(0xA9000000 | cap);//( ccciMsg | 0x80000000 | cap);
         }
         break;
	  case 10: //set the feature enable in the modem side
	     {
		 	g_Spc_FeatureList = (kal_uint16) param;
			spc_M2A_send_message(0xAa000000 | param);//( ccciMsg | 0x80000000 | param);
	     }
	     break;
		case 11:
			{
				l1sp_DebugPrint();
			}
			break;
      default:
         INVALID_MSG(funcType);
   }
}

void spc_Change_Device(kal_uint32 ccciMsg)  // FIXME
{
    SMP_MESSAGE_CHANGE_DEV_PARAM_T * prChgDevPara;
    kal_uint32 u4Offset;

#ifdef __MT6573_PLATFORM__
    u4Offset = (ccciMsg & (0x1fff<<13)) >> 13;
    kal_mem_cpy((kal_uint8 *)&rChgDevPara,(kal_uint8 *) (rSmpSpc.ap_share_buf + u4Offset), sizeof (SMP_MESSAGE_CHANGE_DEV_PARAM_T));
    prChgDevPara = &rChgDevPara;
#else
    prChgDevPara = &rChgDevPara;
#endif    

    kal_prompt_trace(MOD_L1SP, "[ChangeDevice] ccciMsg = %x, offset = %x", ccciMsg, u4Offset);
    kal_prompt_trace(MOD_L1SP, "[ChangeDevice] input_volume = %x, output_volume = %x, sidetone_volume = %x ", 
                               prChgDevPara->input_volume, prChgDevPara->output_volume, prChgDevPara->sidetone_volume);
    
    kal_prompt_trace(MOD_L1SP, "[ChangeDevice] output_device = %x, input_device = %x, speech_mode = %x ", 
                               prChgDevPara->output_device, prChgDevPara->input_device, prChgDevPara->speech_mode);
    
    L1SP_Speech_Off();
    
    spc_Volume_Control(_MessagePacking(MSG_TYPE_VOLUME_CTRL, MSG_VOL_CTRL_OUTPUT_VOL, prChgDevPara->output_volume));    
    spc_Volume_Control(_MessagePacking(MSG_TYPE_VOLUME_CTRL, MSG_VOL_MICROPHONE_VOL , prChgDevPara->input_volume));    
    spc_Volume_Control(_MessagePacking(MSG_TYPE_VOLUME_CTRL, MSG_VOL_SIDETONE_VOL   , prChgDevPara->sidetone_volume));    
    
    spc_Set_Device(_MessagePacking(MSG_TYPE_SET_DEVICE, MSG_DEV_OUTPUT_DEV , prChgDevPara->output_device));    
    spc_Set_Device(_MessagePacking(MSG_TYPE_SET_DEVICE, MSG_DEV_INPUT_DEV  , prChgDevPara->input_device)); 

    L1SP_SetSpeechMode_Adaptation( (uint8)prChgDevPara->speech_mode ); 
    L1SP_Speech_On( rSmpSpc.RAT_Mode );  
    
    spc_M2A_send_message( ccciMsg | 0xc0000000 );
}


Media_Handle *snd_hdl=NULL;
Snd_Param *snd_param;
#ifdef SND_APPLY_MCU_GAIN
int8 snd_level = 100;
#endif
uint8  snd_play_flag = 0;
uint8  snd_repeats = 0;

static void snd_ut_event_handler( Media_Handle *handle, Media_Event event )
{

}

#ifdef __CTM_SUPPORT__
#define CTM_BUFFER_SIZE 16384
__attribute__((aligned (4))) uint8 ctmTempBuf[CTM_BUFFER_SIZE];

static void ctm_Callback(L1Ctm_Event event, void *param)
{
   switch (event)
   {
      case CTM_MO_SUCCESS:
      case CTM_MO_FAIL:
      case CTM_MT_DETECTED:
      case CTM_CHAR_SENT:
         break;
      case CTM_CHAR_RECEIVED:
         break;
      default:
         break;
   }
}
#endif

void spc_AP1_handler(kal_uint32 ccciMsg)
{
   kal_uint32 funcType, param;

   funcType = (ccciMsg<<4)>>28;

   switch (funcType) {

#ifdef __CTM_SUPPORT__
      case 0:
         {
            if (L1Ctm_GetMemReq() > CTM_BUFFER_SIZE)
               ASSERT(0);
            param    = (ccciMsg<<8)>>8;
            // param = 0: DIRECT_MODE,
            // param = 1: BAUDOT_MODE
            L1Ctm_Open( param, ctm_Callback, ctmTempBuf, CTM_BUFFER_SIZE, NULL);
            spc_M2A_send_message( ccciMsg | 0x80000000 );
         }
         break;
      case 1:
         L1Ctm_Close();
         spc_M2A_send_message( ccciMsg | 0x80000000 );
         break;
      case 2:
         L1Ctm_StartNegotiation();
         break;
#endif
#ifndef __L1_STANDALONE__
      case 3:
         {
         		if(L1SP_IsSpeechOn()){ 
            	snd_hdl = SND_Open(snd_ut_event_handler, &snd_param);

            	//SND assign snd_param
            	//snd_param->pstFSAL = &snd_file;
            	snd_param->repeats = snd_repeats; // not necessary, default 1 
            	SND_SetOutputDevice( L1SP_BUFFER_0 );

            	//SND Config UL/DL Mixer
            	SND_ConfigULMixer(snd_hdl, KAL_TRUE, 7);
            	SND_ConfigDLMixer(snd_hdl, KAL_TRUE, 7);

            	#ifdef SND_APPLY_MCU_GAIN
            	SND_SetLevel(snd_hdl, 7);
            	#endif
            	SND_Play(snd_hdl);
            
            	SET_SPC_USAGE(SPC_BKGSND_USAGE);
            } else {
            	kal_trace( TRACE_INFO, L1AUDIO_SPC_A2M_ILLEGAL, ccciMsg);
            }
            spc_M2A_send_message( ccciMsg | 0x80000000 );
         }
         break;
      case 4:
         {
            if(IS_SPC_USED(SPC_BKGSND_USAGE)){ 
               ASSERT(snd_hdl != NULL);
               SND_Stop(snd_hdl);
               if( SND_IsRunning(snd_hdl) )
                  return;
               SND_Close(snd_hdl);            
               RESET_SPC_USAGE(SPC_BKGSND_USAGE);
               snd_hdl = NULL;
            }else{
               //kal_prompt_trace(MOD_L1SP, "illegal A2P message");  
               kal_trace( TRACE_INFO, L1AUDIO_SPC_A2M_ILLEGAL, ccciMsg);
            }            

            spc_M2A_send_message( ccciMsg | 0x80000000 );
         }
         break;
#endif
      case 5:
         {
            int32 gainUL, gainDL;
            uint8 ULlevel, DLlevel;
            
            param  = (ccciMsg<<8)>>8;
            gainUL = (int32)(param<<8)>>20;
            gainUL = gainUL/12;
            gainDL = (int32)(param<<20)>>20;
            gainDL = gainDL/12;

            if (gainUL > 0) {
               ULlevel = 7;
            } else if (gainUL < -7)
               ULlevel = 0;
            else
               ULlevel = 7+gainUL;

            if (gainDL > 0) {
               DLlevel = 7;
            } else if (gainDL < -7)
               DLlevel = 0;
            else
               DLlevel = 7+gainDL;
            //ASSERT(snd_hdl != NULL);
            if(snd_hdl == NULL){					
					kal_trace( TRACE_INFO, L1AUDIO_SPC_A2M_ILLEGAL, ccciMsg);
            } else {
            	SND_ConfigULMixer(snd_hdl, KAL_TRUE, ULlevel);
            	SND_ConfigDLMixer(snd_hdl, KAL_TRUE, DLlevel);
            }
         }
         break;
      default:
         ASSERT(0);
   }
}

static uint16 spc_ReadWordFromAPBuffer(uint32 *readPos);

/**
	@return the processed length in the unit of 8-bit
*/
kal_uint32 spc_GetAPBufferInfo(uint32 *offset, spcBufInfo *info)
{
   info->syncWord = spc_ReadWordFromAPBuffer(offset);
   info->type     = spc_ReadWordFromAPBuffer(offset);
   info->length   = spc_ReadWordFromAPBuffer(offset);

   return 6;
}

static void pcm4Way_ProcessWriteSegment(kal_uint16 *wSrcPtr, uint32 segment)
{
   uint8 *bDestPtr;

   bDestPtr = rSmpSpc.md_share_buf;
   bDestPtr += rSmpSpc.write;
   memcpy(bDestPtr, wSrcPtr, segment*sizeof(uint8));

   rSmpSpc.write += segment;
   if (rSmpSpc.write >= rSmpSpc.md_share_buf_size)
      rSmpSpc.write = 0;
}

/**
	@return: the total length writ to buffer, in unit of 8bit
*/
static kal_uint32 pcm4Way_ProcessWriteBlock(kal_uint16 *wSrcPtr, kal_uint32 bufType, kal_uint32 size)
{
   uint32 segment;

   spc_WriteWordToMDBuffer(&rSmpSpc.write, 0x2A2A);
   spc_WriteWordToMDBuffer(&rSmpSpc.write, bufType);
   spc_WriteWordToMDBuffer(&rSmpSpc.write, size);

   // Process the first segment
   segment = rSmpSpc.md_share_buf_size - rSmpSpc.write;
   if (segment > size)
      segment = size;
   pcm4Way_ProcessWriteSegment(wSrcPtr, segment);
   wSrcPtr += (segment>>1);

   // Process the second segment
   segment = size - segment;
   if (segment > 0) {
      pcm4Way_ProcessWriteSegment(wSrcPtr, segment);
   }

   return (size + 6);
}

void pcm4Way_ReadFromAPBuffer(uint16 *wDestPtr, uint32 offset, uint32 length)
{
   uint32 segment;
   uint8  *bSrcPtr;

   bSrcPtr = rSmpSpc.ap_share_buf;
   bSrcPtr += offset;

   segment = rSmpSpc.ap_share_buf_size - offset;
   if (segment > length)
      segment = length;
   memcpy(wDestPtr, bSrcPtr, segment*sizeof(uint8));
   wDestPtr += (segment>>1);

   segment = length - segment;
   if (segment > 0) {
      bSrcPtr = rSmpSpc.ap_share_buf;
      memcpy(wDestPtr, bSrcPtr, segment*sizeof(uint8));
   }
}

/*
	@return: the length of read block
*/
static kal_uint32 pcm4Way_ProcessReadBlock(kal_uint32 *offset, kal_uint32 length)
{
   spcBufInfo info;
   uint16 *buf;
   kal_uint32 actualBufLength, processedLength;

   // To check the information
   processedLength = 0;
   processedLength = spc_GetAPBufferInfo(offset, &info);
   //FIXME: when end call, &info is empty, the assertion will always happen. 
   //So tempery remove it to handle this case. but some noise may comes out 
   //ASSERT(info.syncWord == 0xA2A2);
   //ASSERT( (info.type == 0x0000) || (info.type == 0x0001) );
   //ASSERT(info.length == 320);   
   if(info.length != spk_bufsize)
      info.length = spk_bufsize;
   //ASSERT( length >= (info.length + processedLength) );
   //END FIXME:
   
   // Copy the data from AP to Modem
   if (info.type == 0) {
	  actualBufLength = se_bufsize;
      buf = PCM_SE_BUF;
   } else {
	  actualBufLength = spk_bufsize;
      buf = PCM_SPK_BUF;
   }
   pcm4Way_ReadFromAPBuffer(buf, *offset, info.length);
   //*offset = (*offset) + 320;
   *offset = (*offset) + actualBufLength;
   processedLength += actualBufLength;
   if ( (*offset) >= rSmpSpc.ap_share_buf_size )
      *offset = (*offset) - rSmpSpc.ap_share_buf_size;

   return processedLength;
}

// Get SE / Speaker
void PCM4Way_ReadData(kal_uint32 offset, kal_uint32 length)
{
	kal_uint32 tempReadBlockSize;
	
   // Process the first block (SD or Speaker buffer)
   //pcm4Way_ProcessReadBlock(&offset, length-6);
   tempReadBlockSize = pcm4Way_ProcessReadBlock(&offset, length);

   // If there is another buffer, process the second block (SD or Speaker buffer)
   /*
   if (length > 326) {
      pcm4Way_ProcessReadBlock(&offset, length-326);
   }*/
   if (length > tempReadBlockSize) {
      pcm4Way_ProcessReadBlock(&offset, length-tempReadBlockSize);
   }
}

// Send Microphone and SD to AP side
void PCM4Way_WriteData( void )
{
   uint32 length, offset, tempProcessLength;

   // Data Request for SE / Speaker
   //spc_M2A_send_message(0x80000000 | 0x140);  // 320 bytes
   if(P2W_PROC_SOURCE_NORMAL == pcm2way_proc_source
   	|| P2W_PROC_SOURCE_CALIBRATION == pcm2way_proc_source) {
      kal_int32 sendMsgResult;
      sendMsgResult = spc_M2A_send_message(0x80000000 | spk_bufsize);

	  if(sendMsgResult<0){ //clean waiting flag of speaker to prevent message blocking
	     kal_prompt_trace(MOD_L1SP, "Fail to req spk data 0x80000000 when PCM4Way_WriteData()");
	     rSmpSpc.pcmSpk_waiting = KAL_FALSE;
	  }
   }
   
   offset = rSmpSpc.write;
   length = 0;
   // Microphone
   if (pcm_buffer_ind & 0x04) {
      tempProcessLength = pcm4Way_ProcessWriteBlock(PCM_MIC_BUF, 0x2, mic_bufsize);
      //length += (mic_bufsize+6);
      length += tempProcessLength;
   }
   // SD
   if (pcm_buffer_ind & 0x08) {
      tempProcessLength = pcm4Way_ProcessWriteBlock(PCM_SD_BUF, 0x3, sd_bufsize);
      //length += (sd_bufsize+6);
      length += tempProcessLength;
   }

   // Data Notification for SD / Microphone
   {
      kal_uint32 ccciMsg;

      if (P2W_PROC_SOURCE_VM_CALIBRAION == pcm2way_proc_source) {
         ccciMsg = 0x94000000 | (offset<<13) | (length);
		 spc_M2A_send_message( ccciMsg );
	  } else {
	     kal_int32 sendMsgResult;
		 
      	 ccciMsg = 0x90000000 | (offset<<13) | (length);
		 sendMsgResult = spc_M2A_send_message( ccciMsg );

		 if(sendMsgResult<0){ //clean waiting flag of speaker to prevent message blocking
		    kal_prompt_trace(MOD_L1SP, "Fail to send mic data 0x90000000 when PCM4Way_WriteData()");
		    rSmpSpc.pcmMic_waiting = KAL_FALSE;
		 }
	  }
   } 
}

static void spc_BGSReadAPBufferSegment(MHdl *hdl, uint8 *bSrcPtr, uint32 length)
{
   uint8 *bDestPtr;
   uint32 bLen, segment;
   uint8 * pbSrc;
   uint8 * pbDest;

   pbSrc = (uint8 *)bSrcPtr;

   SND_RBGetWriteBuffer(SND_RBGetInfo(snd_hdl), &pbDest, &bLen);
   
   bDestPtr = (uint8 *)pbDest;
   
   if (length > bLen)
      segment = bLen;
   else
      segment = length;
   memcpy(bDestPtr, pbSrc, segment*sizeof(uint8));

   SND_RBWriteDataDone(SND_RBGetInfo(snd_hdl), segment);
   
   pbSrc += segment;

   segment = length - segment;
   if (segment > 0) {
      SND_RBGetWriteBuffer(SND_RBGetInfo(snd_hdl), &pbDest, &bLen);
      bDestPtr = (uint8 *)pbDest;
      
      if (segment > bLen)
         segment = bLen;

      memcpy(bDestPtr, pbSrc, segment*sizeof(uint8));
      SND_RBWriteDataDone(SND_RBGetInfo(snd_hdl), segment);
   }
}

void spc_BGSReadFromAPBuffer(MHdl *hdl, uint32 offset, uint32 length)
{
   uint32 segment;
   uint8 * bSrcPtr;

   bSrcPtr = rSmpSpc.ap_share_buf;
   bSrcPtr += offset;

   segment = rSmpSpc.ap_share_buf_size - offset;
   if (segment > length)
      segment = length;
   ASSERT(hdl != NULL);
   spc_BGSReadAPBufferSegment(hdl, bSrcPtr, segment);

   segment = length - segment;
   if (segment > 0) {
      bSrcPtr = rSmpSpc.ap_share_buf;
      spc_BGSReadAPBufferSegment(hdl, bSrcPtr, segment);
   }

   SND_SetWaitFlag(snd_hdl, KAL_FALSE);
}

void spc_BGSOffAck( void )
{
   SMP_MESSAGE_T rSmpMsg;
   rSmpMsg.message_type = SPC_ID_AUDIO_A2M_CCCI;
   rSmpMsg.message_data = 0x44000000;//Background sound off
   L1Audio_SMP_MsgQueuePut(&rSmpMsg);
}

/* Buffer Control for Read (from AP buffer) */
static uint16 spc_ReadWordFromAPBuffer(uint32 *readPos)
{
   uint8  *bSrcPtr;
   uint16 *wSrcPtr;
   uint32 cachePos;

   cachePos = *readPos;
   bSrcPtr = (uint8  *)(rSmpSpc.ap_share_buf);
   bSrcPtr += cachePos;
   wSrcPtr = (uint16 *)bSrcPtr;

   cachePos += 2;
   if (cachePos >= rSmpSpc.ap_share_buf_size)
      cachePos = 0;
   *readPos = cachePos;

   return (*wSrcPtr);
}

// For Application: CTM and Background Sound
#ifdef __CTM_SUPPORT__
void CTM_TxPutText(kal_uint32 offset, kal_uint32 length)
{
   spcBufInfo info;
   uint8 *bSrcPtr;
   uint32 segment;
   uint32 ctm_buf_len;

   // To check the information
   spc_GetAPBufferInfo(&offset, &info);
   ASSERT(info.syncWord == 0xA2A2);
   ASSERT(info.type == 0x0007);
   ASSERT(info.length == (length-6));

   // Process the first segment
   segment = rSmpSpc.ap_share_buf_size - offset;
   if (segment > info.length)
      segment = info.length;
   bSrcPtr = (uint8  *)(rSmpSpc.ap_share_buf);
   bSrcPtr += offset;
   L1Ctm_TxPutText(bSrcPtr, segment, &ctm_buf_len);
   // KH: currently, I don't handle the case of data overflow
   ASSERT(ctm_buf_len > 0);

   segment = info.length - segment;
   if (segment > 0) {
      bSrcPtr = rSmpSpc.ap_share_buf;
      L1Ctm_TxPutText(bSrcPtr, segment, &ctm_buf_len);
      // KH: currently, I don't handle the case of data overflow
      ASSERT(ctm_buf_len > 0);
   }
}
#endif

// Write the data to the buffer of background sound
void BG_SND_PutData(kal_uint32 offset, kal_uint32 length)
{
   spcBufInfo info;
   //sndMediaHandleInternal *ihdl;
   static kal_int32 i4Cnt = 0;

   // To check the information
   spc_GetAPBufferInfo(&offset, &info);
   kal_prompt_trace(MOD_L1SP, "BGS_PutData (%d) offset(%x) len(%d) info.len(%d)", i4Cnt, offset, length, info.length);
   ASSERT(info.syncWord == 0xA2A2);
   ASSERT(info.type == 0x0006);

   i4Cnt++;
   
   // Copy the data from AP to Modem
   spc_BGSReadFromAPBuffer((MHdl *)snd_hdl, offset, info.length);
   SND_SetWaitFlag(snd_hdl, KAL_FALSE);
}

static void spc_PBReadAPBufferSegment(MHdl *hdl, uint8 *bSrcPtr, uint32 length)
{
   uint8 *bDestPtr;
   uint32 bLen, segment1, segment2;

   hdl->GetWriteBuffer(hdl, &bDestPtr, &bLen);

   // force to odd
   bLen &= (~0x1);
   
   if (length > bLen)
      segment1 = bLen;
   else
      segment1 = length;
   memcpy(bDestPtr, bSrcPtr, segment1*sizeof(uint8));
   hdl->WriteDataDone(hdl, segment1);

   bSrcPtr += segment1;

   segment2 = length - segment1;
   if (segment2 > 0) {
      hdl->GetWriteBuffer(hdl, &bDestPtr, &bLen);

      // force to odd
      bLen &= (~0x1);

      if (segment2 > bLen)
         segment2 = bLen;

      memcpy(bDestPtr, bSrcPtr, segment2*sizeof(uint8));
      hdl->WriteDataDone(hdl, segment2);
   }

   // check
   if ((segment2 + segment1) != length)
   {
        kal_prompt_trace(MOD_L1SP, "ERROR SEG [%d + %d] ==> [%d]", segment1, segment2, length);
   }

   kal_prompt_trace(MOD_L1SP, "SEG [%d + %d] ==> [%d]", segment1, segment2, length);
   
}

void spc_PBReadFromAPBuffer(MHdl *hdl, uint32 offset, uint32 length)
{
   uint32 segment;
   uint8  *bSrcPtr;

   bSrcPtr = rSmpSpc.ap_share_buf;
   bSrcPtr += offset;

   segment = rSmpSpc.ap_share_buf_size - offset;
   if (segment > length)
      segment = length;
   ASSERT(hdl != NULL);
   spc_PBReadAPBufferSegment(hdl, bSrcPtr, segment);

   segment = length - segment;
   if (segment > 0) {
      bSrcPtr = rSmpSpc.ap_share_buf;
      spc_PBReadAPBufferSegment(hdl, bSrcPtr, segment);
   }

   hdl->waiting = false;
}

void Playback_PutData(kal_uint32 offset, kal_uint32 length)
{
   spcBufInfo info;

   kal_prompt_trace(MOD_L1SP, "PlayBack offset[%d] len[%d]", offset, length);

   // To check the information
   spc_GetAPBufferInfo(&offset, &info);
   ASSERT(info.syncWord == 0xA2A2);
   ASSERT( (info.type == 0x0004) || (info.type == 0x0005) );
   ASSERT(info.length == (length-6));

   // Copy the data from AP to Modem
   spc_PBReadFromAPBuffer(rSmpSpc.vm_pcm_playback_Handle, offset, info.length);
}

void spc_AckFromAP(kal_uint32 ccciMsg)
{
   kal_uint32 funcType;

   funcType = (ccciMsg<<4)>>30;
   
   switch (funcType) {
      case 0:
         // ack for PCM_DataNotify
         rSmpSpc.pcmSpk_waiting = KAL_FALSE;
         rSmpSpc.pcmMic_waiting = KAL_FALSE;
         break;
      case 1://pcm
         // ack for Record_DataNotify (VM or PCM)
         //Media_ClearWaitingFlag();
         
         if(IS_SPC_USED(SPC_RECORD_USAGE) 
		 	&& IS_SPC_USED(SPC_PCMWAY_USAGE) 
		 	&& P2W_PROC_SOURCE_VM_CALIBRAION == pcm2way_proc_source){
		 	//When DMNR calibration, VM is message between AP & MD, 
		 	//but MD uses pcm2way for the calibration. 
		 	rSmpSpc.pcmSpk_waiting = KAL_FALSE;
            rSmpSpc.pcmMic_waiting = KAL_FALSE;

         } else {
            rSmpSpc.record_data_waiting = KAL_FALSE;
         }
         break;
         
#ifdef __CTM_SUPPORT__
      case 2:
         // ack for CTM_RxGetText
         break;
#endif
      default:
         break;
   }
}

void spc_Notification(kal_uint32 ccciMsg)
{
   kal_uint32 funcType, offset, length;

   funcType = (ccciMsg<<4)>>30;
   offset   = (ccciMsg<<6)>>19;
   length   = (ccciMsg<<19)>>19;

   switch (funcType) {
      case 0:
         // Get the SE/Speaker buffer from application
         if(!IS_SPC_USED(SPC_PCMWAY_USAGE)){
            // kal_prompt_trace(MOD_L1SP, "illegal A2P message");          
            kal_trace( TRACE_INFO, L1AUDIO_SPC_A2M_ILLEGAL, ccciMsg);
            return;  
         }  
         
         PCM4Way_ReadData(offset, length);
         rSmpSpc.pcmSpk_waiting = KAL_FALSE;
         rSmpSpc.pcmMic_waiting = KAL_FALSE;
         break;
      case 1:
         // Get the VM or PCM data from application
         break;
      case 2:
         if(!IS_SPC_USED(SPC_BKGSND_USAGE)){
            // kal_prompt_trace(MOD_L1SP, "illegal A2P message");
            kal_trace( TRACE_INFO, L1AUDIO_SPC_A2M_ILLEGAL, ccciMsg);
            return;  
         }
         
         BG_SND_PutData(offset, length);
         #if 1
         {
            kal_uint32 ccciMsg;
            uint32 bLen;
            
            if(snd_hdl == NULL) return;  

            bLen = SND_RBGetFreeSpace(SND_RBGetInfo(snd_hdl));

            kal_prompt_trace(MOD_L1SP, "BGS_DataSize(%d)After Receive AP Data", SND_PCM_BUFFER_SIZE - bLen - 1);

            if (bLen > SND_PCM_BUFFER_SIZE - RESERVE_BUF_SIZE)
            {        
               kal_sleep_task(1);
               if (bLen > ((rSmpSpc.md_share_buf_size>>1) - 8))       
                   bLen = (rSmpSpc.md_share_buf_size>>1) - 8;
                
               bLen &= ~0x1; //make sure the size is even
               ccciMsg = 0x82000000 | bLen;
               //if(length == 6) // which means AP side return size is zero, so wait a tick to run again.
               spc_M2A_send_message( ccciMsg );
               SND_SetWaitFlag(snd_hdl, KAL_TRUE);
            }    
         }
         #endif
         break;
#ifdef __CTM_SUPPORT__
      case 3:
         CTM_TxPutText(offset, length);
         break;
#endif
      default:
         INVALID_MSG(funcType);
   }
}


void spc_DebugPrint(uint16* ptr16, int len)
{
   int I;
   for(I=0; I+5<len; I+=5){
      kal_trace(TRACE_INFO, L1AP2MCU_DEBUG_PRINT5, ptr16[I], ptr16[I+1], ptr16[I+2], ptr16[I+3], ptr16[I+4]); 
   }   
   switch(len%5){
   case 0:
      break;
   case 1:  
      kal_trace(TRACE_INFO, L1AP2MCU_DEBUG_PRINT1, ptr16[I]); 
      break; 
   case 2:  
      kal_trace(TRACE_INFO, L1AP2MCU_DEBUG_PRINT2, ptr16[I], ptr16[I+1]); 
      break;
   case 3:  
      kal_trace(TRACE_INFO, L1AP2MCU_DEBUG_PRINT3, ptr16[I], ptr16[I+1], ptr16[I+2]); 
      break;
   case 4:  
      kal_trace(TRACE_INFO, L1AP2MCU_DEBUG_PRINT4, ptr16[I], ptr16[I+1], ptr16[I+2], ptr16[I+3]); 
      break;                  
   }   
}
   
static void spc_ReceiveEMParameter( kal_uint32 ccciMsg )
{
   int I, J;
   uint16* ptr16;     
   spcBufInfo info;
   uint8 *bSrcPtr, *bDstPtr;
   uint32 offset, length;
   uint32 segment;
   kal_uint32 funcType;
   
   offset   = (ccciMsg<<6)>>19;
   length   = (ccciMsg<<19)>>19;
   length = length - 6;
   // To check the information
   spc_GetAPBufferInfo(&offset, &info);
   ASSERT(info.syncWord == 0xA2A2);
   ASSERT((info.type & 0xF) == 0x0007); //just use the bit[0:3] to inidicate the type. 
   ASSERT(info.length == length);
   kal_dev_trace( TRACE_INFO, L1AUDIO_CUSTOM_PARAM, info.length, sizeof(AUDIO_CUSTOM_PARAM_STRUCT), 0);
   bSrcPtr = (uint8 *)rSmpSpc.ap_share_buf;
   bSrcPtr += offset;
   segment = rSmpSpc.ap_share_buf_size - offset;
   if (segment > info.length)
      segment = info.length;
   
   funcType = (ccciMsg<<4)>>30;
   if(funcType == 1){
      AUDIO_CUSTOM_PARAM_STRUCT *audio_par;
      audio_par = (AUDIO_CUSTOM_PARAM_STRUCT *)get_ctrl_buffer( sizeof(AUDIO_CUSTOM_PARAM_STRUCT) );
      bDstPtr = (uint8 *)audio_par;
      
      memcpy(bDstPtr, bSrcPtr, segment*sizeof(uint8));
      bDstPtr += segment;
      segment = length - segment;
      if (segment > 0) {
         bSrcPtr = rSmpSpc.ap_share_buf;
         memcpy(bDstPtr , bSrcPtr, segment*sizeof(uint8));
      }
      /* copy to global variable */
      memcpy(sph_common_par , audio_par->speech_common_para, sizeof(uint16) * 12);
      //memcpy(SPH_MODE_PAR , audio_par->speech_mode_para, sizeof(uint16) * 8 * 16);
      l1sp_setAllSpeechModePara((uint16 *)(audio_par->speech_mode_para), 8 * 16);
      memcpy(SPH_VOL_PAR , audio_par->speech_volume_para, sizeof(uint16) * 4);
      //memcpy(SPH_UL_FIR_COEFF , audio_par->sph_in_fir, sizeof(uint16) * 6 * 45);
      //memcpy(SPH_DL_FIR_COEFF , audio_par->sph_out_fir, sizeof(uint16) * 6 * 45);
      l1sp_setAllSpeechFirCoeff_InputOnly((int16 *)(audio_par->sph_in_fir), 6 * 45);
      l1sp_setAllSpeechFirCoeff_OutputOnly((int16 *)(audio_par->sph_out_fir), 6 * 45);
      
      L1Audio_SetDebugInfo(audio_par->debug_info);
      
      g_Digi_DL_Speech        = audio_par->Digi_DL_Speech;
      /* digital gain of uplink speech */
      g_Digi_Microphone       = audio_par->Digi_Microphone;
      /* FM record volume*/
      g_FM_Record_Volume      = audio_par->FM_Record_Volume;
      /* user mode : normal mode, earphone mode, loud speaker mode */
      g_Bluetooth_Sync_Type   = audio_par->Bluetooth_Sync_Type;
      g_Bluetooth_Sync_Length = audio_par->Bluetooth_Sync_Length;
      g_bt_pcm_in_vol         = audio_par->bt_pcm_in_vol;
      g_bt_pcm_out_vol        = audio_par->bt_pcm_out_vol;
      g_uMicbiasVolt          = audio_par->uMicbiasVolt;
      
      {//to printf para for debug         
         ptr16 = audio_par->speech_common_para;
         kal_trace(TRACE_INFO,  L1AP2MCU_COMMONPAR);
         spc_DebugPrint(ptr16, 12);
         
         ptr16 = (uint16*)audio_par->speech_mode_para;
         kal_trace(TRACE_INFO,  L1AP2MCU_MODEPARANB);
         for(I=0; I<8; I++){
            kal_trace(TRACE_INFO,  L1AP2MCU_DEBUG_PRINT0, I);
            spc_DebugPrint(&ptr16[I*16], 16);
         }
         
         ptr16 = audio_par->speech_volume_para;
         kal_trace(TRACE_INFO,  L1AP2MCU_VOLPARA);
         spc_DebugPrint(ptr16, 4);
         
         ptr16 = (uint16*)audio_par->sph_in_fir;
         kal_trace(TRACE_INFO,  L1AP2MCU_INFIRNB);
         for(I=0; I<6; I++){
            kal_trace(TRACE_INFO,  L1AP2MCU_DEBUG_PRINT0, I);
            spc_DebugPrint(&ptr16[I*45], 45);
         }         

         ptr16 = (uint16*)audio_par->sph_out_fir;
         kal_trace(TRACE_INFO,  L1AP2MCU_OUTFIRNB);
         for(I=0; I<6; I++){
            kal_trace(TRACE_INFO,  L1AP2MCU_DEBUG_PRINT0, I);
            spc_DebugPrint(&ptr16[I*45], 45);
         }              
         
         ptr16 = audio_par->debug_info;
         kal_trace(TRACE_INFO,  L1AP2MCU_DEBUGINFO);
         spc_DebugPrint(ptr16, NUM_DEBUG_INFO);
         
         kal_trace(TRACE_INFO,  L1AP2MCU_EMP1, audio_par->Digi_DL_Speech);      
         kal_trace(TRACE_INFO,  L1AP2MCU_EMP2, audio_par->Digi_Microphone);      
         kal_trace(TRACE_INFO,  L1AP2MCU_EMP3, audio_par->FM_Record_Volume);      
         kal_trace(TRACE_INFO,  L1AP2MCU_EMP4, audio_par->Bluetooth_Sync_Type);      
         kal_trace(TRACE_INFO,  L1AP2MCU_EMP5, audio_par->Bluetooth_Sync_Length);      
         kal_trace(TRACE_INFO,  L1AP2MCU_EMP6, audio_par->bt_pcm_in_vol);  
         kal_trace(TRACE_INFO,  L1AP2MCU_EMP7, audio_par->bt_pcm_out_vol);      
         kal_trace(TRACE_INFO,  L1AP2MCU_EMP8, audio_par->uMicbiasVolt);           
      }
      
      if( g_uMicbiasVolt == 1900 )
         g_uMicbiasVolt = 0;
      else if( g_uMicbiasVolt == 2000 )
         g_uMicbiasVolt = 1;
      else if( g_uMicbiasVolt == 2100 )
         g_uMicbiasVolt = 2;
      else if( g_uMicbiasVolt == 2200 )
         g_uMicbiasVolt = 3;
      else
         g_uMicbiasVolt = 0;
      //AFE_ReCalibrate();
      free_ctrl_buffer( audio_par );
      L1SP_LoadSpeechPara();
   } 

   else if(funcType == 3) {// "WB parameters" or "HD record paramters"
		int16 subFuncType;
		subFuncType = info.type >> 4; // just get 

		if(0 == subFuncType) {
			AUDIO_CUSTOM_WB_PARAM_STRUCT *audio_par;
			audio_par = (AUDIO_CUSTOM_WB_PARAM_STRUCT *)strmBuffer;//re-use strmBuffer
			bDstPtr = (uint8 *)audio_par;

			memcpy(bDstPtr, bSrcPtr, segment*sizeof(uint8));
			bDstPtr += segment;
			segment = length - segment;
			if (segment > 0) {
			 bSrcPtr = rSmpSpc.ap_share_buf;
			 memcpy(bDstPtr , bSrcPtr, segment*sizeof(uint8));
			}

			//rSmpSpc.has_wb_mode_para = KAL_TRUE;
			//memcpy(WB_SPH_MODE_PAR , audio_par->speech_mode_wb_para, sizeof(uint16) * 8 * 16);
			l1sp_setAllWbSpeechModePara((uint16 *)audio_par->speech_mode_wb_para, 8 * 16 );

   		{//to printf para for debug         
   			ptr16 = (uint16*)audio_par->speech_mode_wb_para;
            kal_trace(TRACE_INFO,  L1AP2MCU_MODEPARAWB);
            for(I=0; I<8; I++){
               kal_trace(TRACE_INFO,  L1AP2MCU_DEBUG_PRINT0, I);
               spc_DebugPrint(&ptr16[I*16], 16);
            }
         }
			
			if( audio_par->input_out_fir_flag == 0 ){//input
			   l1sp_setAllWbSpeechFirCoeff_InputOnly((int16 *)(audio_par->sph_wb_fir),  6 * 90);
   			{//to printf para for debug         
      			ptr16 = (uint16*)audio_par->sph_wb_fir;
               kal_trace(TRACE_INFO,  L1AP2MCU_INFIRWB);
               for(I=0; I<6; I++){
                  kal_trace(TRACE_INFO,  L1AP2MCU_DEBUG_PRINT0, I);
                  spc_DebugPrint(&ptr16[I*90], 90);
               }  
            }				 
			}else if( audio_par->input_out_fir_flag == 1 ){//output
			   l1sp_setAllWbSpeechFirCoeff_OutputOnly((int16 *)(audio_par->sph_wb_fir), 6 * 90);
   			{//to printf para for debug         
      			ptr16 = (uint16*)audio_par->sph_wb_fir;
               kal_trace(TRACE_INFO,  L1AP2MCU_OUTFIRWB);
               for(I=0; I<6; I++){
                  kal_trace(TRACE_INFO,  L1AP2MCU_DEBUG_PRINT0, I);
                  spc_DebugPrint(&ptr16[I*90], 90);
               }  
            }
         }else{
            ASSERT(0);
         }

		}else if(1 == subFuncType) {
			AUDIO_HD_RECORD_PARAM_STRUCT *recPar;
			kal_bool isParamOk; 
			uint16 tempRecModeNum, tempRecFirNum;			
			
			recPar = (AUDIO_HD_RECORD_PARAM_STRUCT *)strmBuffer;

			bDstPtr = (uint8 *)recPar;			
			memcpy(bDstPtr, bSrcPtr, segment*sizeof(uint8));
			bDstPtr += segment;
			segment = length - segment;
			if (segment > 0) {
				bSrcPtr = rSmpSpc.ap_share_buf;
				memcpy(bDstPtr , bSrcPtr, segment*sizeof(uint8));
			}

			isParamOk = KAL_TRUE;
			tempRecModeNum = recPar->hd_rec_mode_num;
			tempRecFirNum = recPar->hd_rec_fir_num;
			
			if(tempRecModeNum > SPC_MAX_NUM_RECORD_SPH_MODE ) {
				//too many
				kal_trace( TRACE_INFO, L1AUDIO_CUSTOM_PARAM, SPC_MAX_NUM_RECORD_SPH_MODE, tempRecModeNum, 1 );
				isParamOk = KAL_FALSE;
			} else {			    
				l1sp_setAllRecordModePara((uint16 *)recPar->hd_rec_speech_mode_para, 
					tempRecModeNum*NUM_MODE_PARAS, tempRecModeNum);
			}
			
			if(tempRecFirNum > SPC_MAX_NUM_RECORD_INPUT_FIR){
				//too many
				kal_trace( TRACE_INFO, L1AUDIO_CUSTOM_PARAM, SPC_MAX_NUM_RECORD_INPUT_FIR, tempRecFirNum, 2 );
				isParamOk = KAL_FALSE;
			} else {
				l1sp_setAllRecordInFirCoeff((int16 *)recPar->hd_rec_fir,
					tempRecFirNum*NUM_WB_FIR_COEFFS, tempRecFirNum);
				
			}

			if(isParamOk) {
				memcpy(smp_RecordModeFirMappingCh1, recPar->hd_rec_map_to_fir_for_ch1, tempRecModeNum*sizeof(uint16));
				l1sp_setRecordModeFirMappingCh1(smp_RecordModeFirMappingCh1, tempRecModeNum,
					tempRecModeNum );

				memcpy(smp_RecordModeFirMappingCh2, recPar->hd_rec_map_to_fir_for_ch2, tempRecModeNum*sizeof(uint16));
				l1sp_setRecordModeFirMappingCh2(smp_RecordModeFirMappingCh2, tempRecModeNum,
					tempRecModeNum );
				
				memcpy(smp_RecordModeDeviceMapping, recPar->hd_rec_map_to_device_mode, tempRecModeNum*sizeof(uint8));
				l1sp_setRecordModeDeviceMapping(smp_RecordModeDeviceMapping, tempRecModeNum,
					tempRecModeNum );
			} else {
				kal_trace( TRACE_INFO, L1AUDIO_CUSTOM_PARAM, tempRecModeNum, tempRecFirNum, 3 );
			}
	
		}
   }
   else if(funcType == 2) {// DMNR parameters   
		
      AUDIO_CUSTOM_DMNR_PARAM_STRUCT *audio_par;
	  kal_int32 i;
	  kal_int32 paramNum = 1;
	  kal_int32 totalProcessByte = 0;
	  
/*#ifdef __DUAL_MIC_SUPPORT__
	  kal_bool isWbSupport = KAL_FALSE;

#ifdef __AMRWB_LINK_SUPPORT__
	  isWbSupport = KAL_TRUE;
	  paramNum = 2;
#endif //__AMRWB_LINK_SUPPORT__

	  kal_prompt_trace(MOD_L1SP, "info's length(%d) in byte", info.length);
	  if(KAL_FALSE == isWbSupport ){
//NB only
		ASSERT((NUM_DMNR_PARAM<<1) == info.length);
	  } else { //NB + WB
	  	
	  	ASSERT(((NUM_DMNR_PARAM+NUM_WB_DMNR_PARAM) <<1) == info.length);
	  }
#endif //__DUAL_MIC_SUPPORT__*/
      
      if((NUM_DMNR_PARAM<<1) == info.length){
         paramNum = 1;
      }else if(((NUM_DMNR_PARAM+NUM_WB_DMNR_PARAM) <<1) == info.length){
         paramNum = 2;
      }else{
         ASSERT(0);
      }
      
      audio_par = (AUDIO_CUSTOM_DMNR_PARAM_STRUCT *)strmBuffer;//re-use strmBuffer
      bDstPtr = (uint8 *)audio_par;
      /*
      memcpy(bDstPtr, bSrcPtr, segment*sizeof(uint8));
      bDstPtr += segment;
      segment = length - segment;
      if (segment > 0) {
         bSrcPtr = rSmpSpc.ap_share_buf;
         memcpy(bDstPtr , bSrcPtr, segment*sizeof(uint8));
      }
	  */

	  //proc narrow band
	  for(i=0; i<paramNum; i++) {
	  	kal_uint32 currenParamLength; 
		if(i==0){
			//bDstPtr = (uint8 *)audio_par->DMNR_para;
			currenParamLength = (NUM_DMNR_PARAM<<1);
		}else if(i==1){
			//bDstPtr = (uint8 *)audio_par->WB_DMNR_para;
			currenParamLength = (NUM_WB_DMNR_PARAM<<1);
		}
		
		if(segment > currenParamLength) {
			memcpy(bDstPtr, bSrcPtr, currenParamLength*sizeof(uint8));
			bDstPtr += currenParamLength;
			bSrcPtr += currenParamLength;
			segment -= currenParamLength;
			totalProcessByte += currenParamLength;
		} else {
		    kal_uint32 dmnrSubSegment =0;
			
		  	memcpy(bDstPtr, bSrcPtr, segment*sizeof(uint8));
			bDstPtr += segment;
			bSrcPtr = rSmpSpc.ap_share_buf;
			totalProcessByte += segment;
			dmnrSubSegment = (currenParamLength - segment);
			
			segment = length - totalProcessByte; 
			
			if ( dmnrSubSegment > 0) {
			 	memcpy(bDstPtr , bSrcPtr, dmnrSubSegment*sizeof(uint8));
				bSrcPtr += dmnrSubSegment; 
				bDstPtr += dmnrSubSegment;
				segment -= dmnrSubSegment;
				totalProcessByte += dmnrSubSegment;
			}
		}
	  }
#ifdef __DUAL_MIC_SUPPORT__
      L1SP_SetDMNRPara((kal_int16*)audio_par->DMNR_para);
		{//to printf para for debug         
			ptr16 = audio_par->DMNR_para;
         kal_trace(TRACE_INFO,  L1AP2MCU_DMNRPARANB);
         spc_DebugPrint(ptr16, NUM_DMNR_PARAM);
      }	                  
//	  if(KAL_TRUE == isWbSupport) {
#ifdef __AMRWB_LINK_SUPPORT__
      if(paramNum == 1)
         ASSERT(0);
	  	L1SP_SetWbDMNRPara((kal_int16*)audio_par->WB_DMNR_para);
		{//to printf para for debug         
			ptr16 = audio_par->WB_DMNR_para;
         kal_trace(TRACE_INFO,  L1AP2MCU_DMNRPARAWB);
         spc_DebugPrint(ptr16, NUM_WB_DMNR_PARAM);
      }		  	
#endif
//	  }
#endif
   }
}

/* function type has two type :                                     */
/* one is 2 bits, another is 4 bits                                 */
/* If 2bits,it means data transfer, following  13 + 13 bits are     */
/* address offset and length                                        */
static void spc_Misc_Control(kal_uint32 ccciMsg)
{
   kal_uint32 funcType;

   funcType = (ccciMsg<<4)>>30;

   if( funcType == 1 || funcType == 3 || funcType == 2){
      spc_ReceiveEMParameter( ccciMsg );
      spc_M2A_send_message( ccciMsg | 0x80000000 );
   } else {
      funcType = (ccciMsg<<4)>>28;
      switch (funcType) {
         case 0:
            //AM_MetaMode_EnableBTPcmClock(); To Do
            break;
         default:
            ASSERT(0);
      }
   }
}

void spc_AP_Command_Handler(kal_uint32 ccciMsg)
{
   kal_uint32 msgType;

   /* Convert CCCI message to SPC message */
   // bit31 ~ bit28: message type
   // bit27 ~ bit24: function type
   // bit23 ~ bit12: offset (buffer)
   // bit11 ~ bit0 : length (buffer)
   // bit15 ~ bit0 : paramter
   msgType  = ccciMsg>>28;

   switch (msgType) {
      case 0:
         spc_Volume_Control(ccciMsg);
         break;
      case 1:
         spc_Set_Device(ccciMsg);
         break;        
      case 2:
         spc_Speech_Control(ccciMsg);
         break;

      case 3:
         spc_Data_Transfer_Control(ccciMsg);
         break;                         
                    
      case 4:
         spc_AP1_handler(ccciMsg);
         break;

      case 5:
         spc_Notification(ccciMsg);
         break;

      case 6:
         spc_AckFromAP(ccciMsg);
         break;

      case 7:
         spc_Misc_Control(ccciMsg);
         break;
      case MSG_TYPE_CHANGE_DEV: 
         spc_Change_Device(ccciMsg);
         break;
      default:
         INVALID_MSG(msgType);
   }
   //spc_print_msg(1, ccciMsg);
   kal_prompt_trace(MOD_L1SP,"A2M %x done", ccciMsg);
}

void L1Audio_SMP_MsgHandler(void *idata)
{
   // Process all messages
   while (!RB_EMPTY(rSmpSpc.ccciq)) 
   {
      SMP_MESSAGE_T  rMsg;
      void *dummydata;

      // excute messages from DSP first
      l1audio_MsgHandlerV2(dummydata);  
      
      // Get message
      L1Audio_SMP_MsgQueueGet(&rMsg);
      
      switch (rMsg.message_type)
      {
      case SPC_ID_AUDIO_A2M_CCCI:
          spc_AP_Command_Handler(rMsg.message_data);
          break;
      case SPC_ID_AUDIO_STRM_PCM4WAY_DATA:
         PCM4Way_WriteData();
         break;
          

      case SPC_ID_AUDIO_STRM_BGSND_DATA_REQUEST:
         {
            kal_uint32 ccciMsg;
            uint32 bLen;
            
            if(snd_hdl == NULL) return;
   
            if(SND_GetWaitFlag(snd_hdl))
               return;
   
            bLen = SND_RBGetFreeSpace(SND_RBGetInfo(snd_hdl));
            
            kal_prompt_trace(MOD_L1SP, "BGS_DataSize(%d)When Request Data", SND_PCM_BUFFER_SIZE - bLen);

            if (bLen > SND_PCM_BUFFER_SIZE - RESERVE_BUF_SIZE)
            {
               if (bLen > ((rSmpSpc.md_share_buf_size>>1) - 8))
                  bLen = (rSmpSpc.md_share_buf_size>>1) - 8;
               
               bLen &= ~0x1; //make sure the size is even
               ccciMsg = 0x82000000 | bLen;
               spc_M2A_send_message( ccciMsg );
   
               SND_SetWaitFlag(snd_hdl, KAL_TRUE);
            }
         }
         break;
       
      case SPC_ID_AUDIO_STRM_PCM_DATA_REQUEST:
      case SPC_ID_AUDIO_STRM_VM_DATA_REQUEST:
         {
            kal_uint32 ccciMsg;
            uint32 bLen;
            
            if(rSmpSpc.vm_pcm_playback_Handle == NULL) return;
            rSmpSpc.vm_pcm_playback_Handle->handler(rSmpSpc.vm_pcm_playback_Handle, rSmpSpc.vm_pcm_playback_Handle->data);
            bLen = rSmpSpc.vm_pcm_playback_Handle->GetFreeSpace(rSmpSpc.vm_pcm_playback_Handle);
            if (bLen > ((rSmpSpc.md_share_buf_size>>1) - 8))
               bLen = (rSmpSpc.md_share_buf_size>>1) - 8;
            bLen &= ~0x1; //make sure the size is even
            ccciMsg = 0x81000000 | bLen;
            spc_M2A_send_message( ccciMsg );
         }
         break;
      case SPC_ID_SPEECH_CUSTOM_DATA_REQUEST:
         spc_M2A_send_message( 0x84000000 );
         break;
#if defined(SP_UNIT_TEST)
      case SPC_ID_AUDIO_STRM_PCM_DATA_REQUEST:
         pcm_strm_play_handler( l1audio.vm_pcm_playback_Handle, l1audio.vm_pcm_playback_Handle->data );
         break;

      case SPC_ID_TST_INJECT_STRING:
         {
            tst_module_string_inject_struct *tst_inject = (tst_module_string_inject_struct*) ilm_ptr->local_para_ptr;
            ASSERT(tst_inject != NULL);

            l1audio_unit_test(tst_inject->index, (kal_char *)tst_inject->string);
         }
         break;
#endif

      default:
         INVALID_MSG(rMsg.message_type);
      }
   }
}

void L1Audio_SMP_Init(kal_uint16 u2AudId)
{
    rSmpSpc.smp_audio_id = u2AudId;

    L1Audio_SetEventHandler(rSmpSpc.smp_audio_id, L1Audio_SMP_MsgHandler );
    
}

void SMP_SPC_Init(void)
{
   SMP_MESSAGE_T rMsg;
   g_spc_usage = 0;
   
   spcSpeInfo.infoState = 0;
	spcSpeInfo.isMaskChange = 0;
   spcSpeInfo.spe_usr_mask = 0xFFFF;
   spcSpeInfo.spe_usr_subFunc_mask = 0x1;
   
#ifdef __MT6573_PLATFORM__

   rSmpSpc.ap_share_buf = (uint8 *)ccci_query_sharemem_addr(CCCI_PCM_CHANNEL, &rSmpSpc.ap_share_buf_size);

   rSmpSpc.ap_share_buf_size >>= 1;
   rSmpSpc.md_share_buf = (uint8 *)rSmpSpc.ap_share_buf + rSmpSpc.ap_share_buf_size;
   rSmpSpc.md_share_buf_size = rSmpSpc.ap_share_buf_size;

   kal_prompt_trace(MOD_L1SP,"ap_share_buf[%x], Size[%x]", rSmpSpc.ap_share_buf, rSmpSpc.ap_share_buf_size);

#else  /* __MT6573_PLATFORM__ */

   rSmpSpc.ap_share_buf = au1SharedBuff;
   rSmpSpc.ap_share_buf_size = SHM_BUF_SZ/2;
   rSmpSpc.md_share_buf = (uint8 *)rSmpSpc.ap_share_buf + rSmpSpc.ap_share_buf_size;
   rSmpSpc.md_share_buf_size = SHM_BUF_SZ/2;
   pu4MDBufAddr = rSmpSpc.md_share_buf;

#endif

   rSmpSpc.RAT_Mode = 0;
   rSmpSpc.pcmSpk_waiting = KAL_FALSE;
   rSmpSpc.pcmMic_waiting = KAL_FALSE;
   rSmpSpc.record_data_waiting = KAL_FALSE;
   
   //rSmpSpc.has_wb_mode_para  = KAL_FALSE; 
   //rSmpSpc.has_wb_ulfir_para = KAL_FALSE;
   //rSmpSpc.has_wb_dlfir_para = KAL_FALSE;
   
#ifdef __AMRWB_LINK_SUPPORT__
   l1sp_setAllWbSpeechModePara((uint16 *)WB_Speech_Normal_Mode_Para, 8 * 16 );
   l1sp_setAllWbSpeechFirCoeff_InputOnly((int16 *)WB_Speech_Input_FIR_Coeff,  6 * 90);
   l1sp_setAllWbSpeechFirCoeff_OutputOnly((int16 *)WB_Speech_Output_FIR_Coeff, 6 * 90);
#endif

   L1SP_SetFIR( KAL_TRUE );
   L1SP_LoadSpeechPara();
   
   //Request custom data, especially sometimes MODEM reset.
   rMsg.message_type = SPC_ID_SPEECH_CUSTOM_DATA_REQUEST;
   rMsg.message_data = _MessagePacking(0, 0, 0); 
   // Send notification and request
   L1Audio_SMP_MsgQueuePut(&rMsg);
   
   //trigger Modem side to process A2M message after L1AudioMain is initialized    
   L1Audio_SetEvent(rSmpSpc.smp_audio_id, (void *)0 );
}

#endif  /* __SMART_PHONE_MODEM__ */

#define REG_READ32(Reg)                    (*((volatile kal_uint32*)(Reg)))
#define REG_WRITE32(Reg, Value)	           (*((volatile kal_uint32*)(Reg)) = (Value))

kal_int32 REG_Dump(kal_uint32 u4SrcAddress, kal_uint32 u4Length)
{
    kal_uint32 u4SrcAddr = u4SrcAddress;
    kal_uint32 u4Len = u4Length;
    kal_uint32 u4Idx;

    if (u4Len == 0)
    {
        return 0;
    }
    if (u4Len > 0x1000)
    {
        u4Len = 0x1000;
    }

    // DW alignment
    u4SrcAddr &= 0xFFFFFFFC; 

    for (u4Idx = 0; u4Idx < u4Len; u4Idx += 16)
    {
        kal_prompt_trace(MOD_L1SP, "%x | %x  %x  %x  %x"
            , (u4SrcAddr + u4Idx)
            , REG_READ32(u4SrcAddr + u4Idx + 0)
            , REG_READ32(u4SrcAddr + u4Idx + 4)
            , REG_READ32(u4SrcAddr + u4Idx + 8)
            , REG_READ32(u4SrcAddr + u4Idx + 12));
    }

    return u4Len;
}

void AssertREGDump(void)
{
    kal_prompt_trace(MOD_L1SP, "================================");
    REG_Dump((uint32)PLL_CON2, 4);
    kal_prompt_trace(MOD_L1SP, "================================");
    REG_Dump((uint32)AUDIO_CON0, 0x100);
    kal_prompt_trace(MOD_L1SP, "================================");
#if defined(MT6573)    
    REG_Dump((uint32)VAUDN_CON0, 0x100);
    kal_prompt_trace(MOD_L1SP, "================================");
#endif // defined(MT6573)    
    // REG_Dump(0xd0000000, 0x400);
    REG_Dump((uint32)AUDIOSYS_SD_base, 0x400);
    kal_prompt_trace(MOD_L1SP, "================================");
}

