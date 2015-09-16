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
 * pcm4way.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   PCM4WAY/PCM2WAY interface 
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
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_trace.h"
#include "l1sp_trc.h"
#include "string.h"

#include "l1audio.h"                      
#include "audio_enum.h"
#include "l1audio_def.h"
#include "am.h"
#include "fc_def.h"
#include "pcm4way.h"
#include "exp_SphFasTypDef.h"
#include "media.h"

#define DSP_PCM_EX_LEN 160
#define PCM4WAY_STATE 4
#define PCM2WAY_STATE 2

__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI"))) 
SAC_SphP2WPar_t SAC_SphP2WPar;

__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI"))) 
SAC_SphP4WPar_t SAC_SphP4WPar;

static struct{
   void (*hdlr)(void);
   uint32 state; 
   uint16 fc_aud_id;
   uint16 aud_id;
   uint16 updateULDL;
   SAS_PCM4Way_ExchangeUlData_t pcm4wayUlData;
   SAS_PCM4Way_ExchangeDlData_t pcm4wayDlData;
   SAS_PCM2Way_ExchangeUlData_t pcm2wayUlData;
   SAS_PCM2Way_ExchangeDlData_t pcm2wayDlData;
   uint8 pcm4wayServiceType;
   uint8 pcm2wayServiceType;
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   
#ifdef BGSND_ENABLE
   void (*sndOnHandler)(void *hdl); 
   void (*sndOffHandler)(void *hdl);
   void *sndHdl;
#endif     
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   
   
}pcmEx; 

static void pcmExMsgHandler(kal_uint16 msgOp, kal_uint32 msgData, void *userData)
{
   switch (msgOp) {
      case MSG_SAC2L1AUDIO_SPEECH_CALLPCM4WAY_OPEN_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_CALLPCM2WAY_OPEN_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_IDLEPCM4WAY_START_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_IDLEPCM2WAY_START_ACK:
         L1Audio_FC_SetWait(false);
         break;
      case MSG_SAC2L1AUDIO_SPEECH_CALLPCM4WAY_CLOSE_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_CALLPCM2WAY_CLOSE_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_IDLEPCM4WAY_STOP_ACK:
      case MSG_SAC2L1AUDIO_SPEECH_IDLEPCM2WAY_STOP_ACK:
         L1Audio_FC_SetWait(false);
         break;
      case MSG_SAC2L1AUDIO_SPEECH_PCM4WAY_REQUEST_EXCHANGE_UL_DATA:
         {
            SAS_PCM4Way_ExchangeUlData_t *sas_pcmdata = (SAS_PCM4Way_ExchangeUlData_t *)msgData;
            pcmEx.pcm4wayUlData.pucOutputUlBufPtr = sas_pcmdata->pucOutputUlBufPtr;
            pcmEx.pcm4wayUlData.pucInputUlBufPtr  = sas_pcmdata->pucInputUlBufPtr;
            pcmEx.pcm4wayUlData.u4Len             = sas_pcmdata->u4Len>>1;
            pcmEx.updateULDL |= UPDATE_UL;
            if(pcmEx.pcm4wayServiceType == PCM_SERVICE_REALTIME){
               pcmEx.hdlr();
               pcmEx.updateULDL &= ~UPDATE_UL;
            }
            L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_PCM4WAY_REQUEST_EXCHANGE_UL_DATA_ACK, pcmEx.fc_aud_id, 0);
            break;
         }
      case MSG_SAC2L1AUDIO_SPEECH_PCM4WAY_REQUEST_EXCHANGE_DL_DATA:
         {
            SAS_PCM4Way_ExchangeDlData_t *sas_pcmdata = (SAS_PCM4Way_ExchangeDlData_t *)msgData;
            pcmEx.pcm4wayDlData.pucOutputDlBufPtr = sas_pcmdata->pucOutputDlBufPtr;
            pcmEx.pcm4wayDlData.pucInputDlBufPtr  = sas_pcmdata->pucInputDlBufPtr;
            pcmEx.pcm4wayDlData.u4Len             = sas_pcmdata->u4Len>>1;
            pcmEx.pcm4wayDlData.u4BFI             = sas_pcmdata->u4BFI;
            pcmEx.updateULDL |= UPDATE_DL;
            pcmEx.hdlr();
            pcmEx.updateULDL &= ~UPDATE_DL;
            if(pcmEx.pcm4wayServiceType != PCM_SERVICE_REALTIME)
               pcmEx.updateULDL &= ~UPDATE_UL;
            L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_PCM4WAY_REQUEST_EXCHANGE_DL_DATA_ACK, pcmEx.fc_aud_id, 0);
            break;
         }
      case MSG_SAC2L1AUDIO_SPEECH_PCM2WAY_REQUEST_EXCHANGE_UL_DATA:
         {
            SAS_PCM2Way_ExchangeUlData_t* sas_pcmdata = (SAS_PCM2Way_ExchangeUlData_t *)msgData;
            pcmEx.pcm2wayUlData.pucOutputUlBufPtr  = sas_pcmdata->pucOutputUlBufPtr;
            pcmEx.pcm2wayUlData.u4Len            = sas_pcmdata->u4Len>>1;
            pcmEx.updateULDL |= UPDATE_UL;
            if(pcmEx.pcm2wayServiceType == PCM_SERVICE_REALTIME){
               pcmEx.hdlr();
               pcmEx.updateULDL &= ~UPDATE_UL;
            }
            L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_PCM2WAY_REQUEST_EXCHANGE_UL_DATA_ACK, pcmEx.fc_aud_id, 0);
            break;
         }
      case MSG_SAC2L1AUDIO_SPEECH_PCM2WAY_REQUEST_EXCHANGE_DL_DATA:
         {
            SAS_PCM2Way_ExchangeDlData_t* sas_pcmdata = (SAS_PCM2Way_ExchangeDlData_t *)msgData;
            pcmEx.pcm2wayDlData.pucInputDlBufPtr   = sas_pcmdata->pucInputDlBufPtr;
            pcmEx.pcm2wayDlData.u4Len            = sas_pcmdata->u4Len>>1;
            pcmEx.updateULDL |= UPDATE_DL;
            pcmEx.hdlr();
            pcmEx.updateULDL &= ~UPDATE_DL;
            if(pcmEx.pcm2wayServiceType != PCM_SERVICE_REALTIME)
               pcmEx.updateULDL &= ~UPDATE_UL;
            L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_PCM2WAY_REQUEST_EXCHANGE_DL_DATA_ACK, pcmEx.fc_aud_id, 0);
            break;
         }
      default:
         ASSERT(0);
   }
   
   
}

kal_uint16 PCM4WAY_QueryBuffer(void)
{
   return pcmEx.updateULDL;
}

//************** PCM 4-WAY *******************
void PCM4WAY_SetServiceType( PCM_Service_Type type )
{
// kal_prompt_trace(MOD_L1SP, "pcm4way service type = %d", type);
   if(type >= PCM_SERVICE_UNKNOWN)
      type = PCM_SERVICE_NORMAL;
   pcmEx.pcm4wayServiceType = type;
}


#define UL_DATA_SELECT_VIA_ENH     (1<<0)  
#define UL_USE_D2M_PATH            (1<<1)
#define UL_USE_M2D_PATH            (1<<2)
#define DL_DATA_SELECT_VIA_ENH     (1<<0)  
#define DL_USE_D2M_PATH            (1<<1)
#define DL_USE_M2D_PATH            (1<<2)

void Extended_PCM4WAY_Start(void (*pcm4way_hdlr)(void), uint32 type, uint32 cfgUL, uint32 cfgDL)
{
   pcmEx.aud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( pcmEx.aud_id );
   pcmEx.fc_aud_id = L1Audio_FC_HookHandler( 0, pcmExMsgHandler, 1, 0 );
   pcmEx.hdlr = pcm4way_hdlr;
   if( type == 0 )
      SAC_SphP4WPar.u4Ctm = 1;
   else
      SAC_SphP4WPar.u4Ctm = 0;
   SAC_SphP4WPar.bWb = 0;//NB   
   
   SAC_SphP4WPar.u4CfgUl = cfgUL;
   SAC_SphP4WPar.u4CfgDl = cfgDL;
   
   if(AM_IsSpeechOn())
      L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_CALLPCM4WAY_OPEN, pcmEx.fc_aud_id, (uint32)&SAC_SphP4WPar, KAL_TRUE );
   else
      L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_IDLEPCM4WAY_START, pcmEx.fc_aud_id, (uint32)&SAC_SphP4WPar, KAL_TRUE );
   AM_PCM_EX_On(0);
   pcmEx.state = PCM4WAY_STATE;
}

void Extended_PCM4WAY_Stop(uint32 type)
{
   //ASSERT_REBOOT(type==1 || type==2);
   if(AM_IsSpeechOn())
      L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_CALLPCM4WAY_CLOSE, pcmEx.fc_aud_id, 0, KAL_TRUE );
   else
      L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_IDLEPCM4WAY_STOP, pcmEx.fc_aud_id, 0, KAL_TRUE );

   SAC_SphP4WPar.u4CfgUl= UL_USE_M2D_PATH | UL_USE_D2M_PATH | UL_DATA_SELECT_VIA_ENH;
   SAC_SphP4WPar.u4CfgDl= DL_USE_M2D_PATH | DL_USE_D2M_PATH ;
   
   L1Audio_FC_UnHookHandler(pcmEx.fc_aud_id, 1);
   AM_PCM_EX_Off(type);

   L1Audio_ClearFlag( pcmEx.aud_id );
   L1Audio_FreeAudioID( pcmEx.aud_id );
   pcmEx.hdlr = NULL;
   pcmEx.state = 0;	
}

void PCM4WAY_Start(void (*pcm4way_hdlr)(void), uint32 type)
{
   Extended_PCM4WAY_Start(pcm4way_hdlr, type, 
                          (UL_USE_M2D_PATH | UL_USE_D2M_PATH | UL_DATA_SELECT_VIA_ENH), 
                          (DL_USE_M2D_PATH | DL_USE_D2M_PATH ));
}

void PCM4WAY_Stop(uint32 type)
{
	 Extended_PCM4WAY_Stop(type);
}

////////////////////////////////////////////////////////////////////////////////

void PCM4WAY_GetFromMic(uint16 *ul_buf)
{
   uint32 I;
   uint16* ptr = (uint16 *)pcmEx.pcm4wayUlData.pucOutputUlBufPtr;
   if( L1SP_IsMicrophoneMuted() ){
      for( I = pcmEx.pcm4wayUlData.u4Len; I > 0; I-- )
         *ul_buf++ = 0;
   } else {
      for( I = pcmEx.pcm4wayUlData.u4Len; I > 0; I-- )    
          *ul_buf++ = *ptr++;
   }
}
  
void PCM4WAY_PutToSE(const uint16 *ul_data)  
{
   uint32 I;

   uint16* ptr = (uint16 *)pcmEx.pcm4wayUlData.pucInputUlBufPtr;
   for( I = pcmEx.pcm4wayUlData.u4Len ; I > 0; I-- )
      *ptr++ = *ul_data++;
}

void PCM4WAY_FillSE(uint16 value)  
{
   uint32 I;
   uint16* ptr = (uint16 *)pcmEx.pcm4wayUlData.pucInputUlBufPtr;
   for( I = pcmEx.pcm4wayUlData.u4Len ; I > 0; I-- )
      *ptr++ = value;
}

void PCM4WAY_GetFromSD(uint16 *dl_buf)
{
   uint32 I;

   uint16* ptr = (uint16 *)pcmEx.pcm4wayDlData.pucOutputDlBufPtr;
   for( I = pcmEx.pcm4wayDlData.u4Len; I > 0; I-- )
      *dl_buf++ = *ptr++;
}

kal_uint16 PCM4WAY_GetBFI( void )
{
   return (kal_uint16)pcmEx.pcm4wayDlData.u4BFI;
}

void PCM4WAY_PutToSpk(const uint16 *dl_data)
{
   uint32 I;
   
   uint16* ptr = (uint16 *)pcmEx.pcm4wayDlData.pucInputDlBufPtr;
   for( I = pcmEx.pcm4wayDlData.u4Len ; I > 0; I-- )
      *ptr++ = *dl_data++;
}

void PCM4WAY_FillSpk(uint16 value)  
{
   uint32 I;
   uint16* ptr = (uint16 *)pcmEx.pcm4wayDlData.pucInputDlBufPtr;
   for( I = pcmEx.pcm4wayDlData.u4Len ; I > 0; I-- )
      *ptr++ = value;
}

//************** PCM 2-WAY *******************

void PCM2WAY_SetServiceType( PCM_Service_Type type )
{
   kal_trace( TRACE_INFO, PCM2WAY_SET_SERVICE_TYPE, type);
   if(type >= PCM_SERVICE_UNKNOWN)
      type = PCM_SERVICE_NORMAL;
   pcmEx.pcm2wayServiceType = type;
}

/**

@type: please refer to P2W_App_Type. 
	0 for pcm4way CTM, 
	1 for pcm2way Voice, 
	2 for pcm2way Voip, 
 	3 for pcm2Way record only(calibration used), 
 	4 for pcm2Way record&playback(calibration used)
*/
void Extended_PCM2WAY_Start(void (*pcm2way_hdlr)(void), uint32 type, uint32 cfgUL, uint32 cfgDL)
{
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   
#if !(defined(MT6573) || defined(MT6575) || defined(MT6577))
   TONE_StopAndWait();
   KT_StopAndWait();
#endif

#ifdef BGSND_ENABLE
   if ((!AM_IsSpeechOn()) && (pcmEx.sndOffHandler != NULL))
      pcmEx.sndOffHandler( pcmEx.sndHdl );
#endif
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   
      
   pcmEx.aud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( pcmEx.aud_id );
   pcmEx.fc_aud_id = L1Audio_FC_HookHandler( 0, pcmExMsgHandler, 1, 0 );
   pcmEx.hdlr = pcm2way_hdlr;
   if(type == P2W_APP_TYPE_REC_ONLY_CAL){
   		//check to ensure calling PCM2Way_SetFormat() before PCM2WAY_Start()
   		ASSERT(SAC_SphP2WPar.u4Format == SPH_P2W_ENH_CAL);   
		L1SP_SetULAGC(true);
   } else if(type == P2W_APP_TYPE_REC_PLAY_CAL){
   		//check to ensure calling PCM2Way_SetFormat() before PCM2WAY_Start()
   		ASSERT(SAC_SphP2WPar.u4Format == SPH_P2W_ENH_CAL); 
		L1SP_SetULAGC(true);
   } else { //default usage for original code 
   		SAC_SphP2WPar.bWb = 0; 
   }
   SAC_SphP2WPar.u4CfgUl = cfgUL;
   SAC_SphP2WPar.u4CfgDl = cfgDL;
   //SAC_SphP2WPar.bWb    = 0; //update when calling PCM2Way_SetFormat.
   //SAC_SphP2WPar.u4Format  = 0;
   L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_MUTE_UPLINK_BY_FRAME, 0, (kal_uint32)MUTE_UL_FRAME_SIZE);
   if(AM_IsSpeechOn()){
   	  L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_CALLPCM2WAY_OPEN, pcmEx.fc_aud_id, (uint32)&SAC_SphP2WPar, KAL_TRUE );
   } else {
   	  L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_IDLEPCM2WAY_START, pcmEx.fc_aud_id, (uint32)&SAC_SphP2WPar, KAL_TRUE );
   }
   AM_PCM_EX_On(type); //choose the hardware open decision
   pcmEx.state = PCM2WAY_STATE;
}

void PCM2Way_SetFormat(uint32 format) //for caller, it's WB or NB
{
   //SAC_SphP2WPar.u4Format = format;	
   if(format == P2W_FORMAT_CAL){
   		SAC_SphP2WPar.bWb = 0; //NB
   		SAC_SphP2WPar.u4Format = SPH_P2W_ENH_CAL;
    	//L1SP_SetULAGC(true);  
   } else if (format == P2W_FORMAT_WB_CAL ) {
   		SAC_SphP2WPar.bWb = 1; //WB
   		SAC_SphP2WPar.u4Format = SPH_P2W_ENH_CAL;
   		//L1SP_SetULAGC(true);
   } else { //default using narrow band 
   		SAC_SphP2WPar.u4Format = format;
   		SAC_SphP2WPar.bWb = 0;
   }
}

void Extended_PCM2WAY_Stop(uint32 type)
{
   ASSERT(type==0 || type==1 || type==2 || type==3 || type==4);
   if(AM_IsSpeechOn())
      L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_CALLPCM2WAY_CLOSE, pcmEx.fc_aud_id, 0, KAL_TRUE );
   else
   		L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_IDLEPCM2WAY_STOP, pcmEx.fc_aud_id, 0, KAL_TRUE );
   SAC_SphP2WPar.u4CfgUl= UL_DATA_SELECT_VIA_ENH;
   SAC_SphP2WPar.u4CfgDl= 0 ;
   L1Audio_FC_UnHookHandler(pcmEx.fc_aud_id, 1);
   AM_PCM_EX_Off(type);
   L1Audio_ClearFlag( pcmEx.aud_id );
   L1Audio_FreeAudioID( pcmEx.aud_id );
   if(SAC_SphP2WPar.u4Format == P2W_FORMAT_CAL 
   	|| SAC_SphP2WPar.u4Format == P2W_FORMAT_WB_CAL){
      L1SP_SetULAGC(false);  
   }
   PCM2Way_SetFormat(P2W_FORMAT_NORMAL);
   pcmEx.hdlr = NULL;
   pcmEx.state = 0;
}

void PCM2WAY_Start(void (*pcm2way_hdlr)(void), uint32 type)
{
   Extended_PCM2WAY_Start(pcm2way_hdlr, type, 
                          (UL_DATA_SELECT_VIA_ENH), 
                          (0));
}

void PCM2WAY_Stop(uint32 type)
{
	Extended_PCM2WAY_Stop(type);
}

void PCM2WAY_GetFromMic(uint16 *ul_buf)
{
   uint32 I;      

   uint16* ptr = (uint16 *)pcmEx.pcm2wayUlData.pucOutputUlBufPtr;
   if( L1SP_IsMicrophoneMuted() ){
      for( I = pcmEx.pcm2wayUlData.u4Len; I > 0; I-- )
         *ul_buf++ = 0;
   } else {
      for( I = pcmEx.pcm2wayUlData.u4Len; I > 0; I-- )    
          *ul_buf++ = *ptr++;
   }
} 

void PCM2WAY_PutToSpk(const uint16 *dl_data)
{
   uint32 I;
   
   uint16* ptr = (uint16 *)pcmEx.pcm2wayDlData.pucInputDlBufPtr;
   for( I = pcmEx.pcm2wayDlData.u4Len ; I > 0; I-- )
      *ptr++ = *dl_data++;
}


void PCM2WAY_FillSpk(uint16 value)
{
   uint32 I;
   uint16* ptr = (uint16 *)pcmEx.pcm2wayDlData.pucInputDlBufPtr;
   for( I = pcmEx.pcm2wayDlData.u4Len ; I > 0; I-- )
      *ptr++ = value;
}

void PCM2WAY_QueryBufSize(P2W_Format format, kal_uint32 *mic_bufsize, kal_uint32 *spk_bufsize)
{
   switch((kal_uint32)format){
      case P2W_FORMAT_NORMAL://SPH_P2W_UNDEF:
   	   *mic_bufsize = *spk_bufsize = 160;
   	   break;
      case P2W_FORMAT_VOIP://SPH_P2W_VOIP:
         *mic_bufsize = *spk_bufsize = 160;
         break;
      case P2W_FORMAT_CAL://SPH_P2W_ENH_CAL:
         *spk_bufsize = 160;
         *mic_bufsize = 322; //160*2 +2;
         break;
	  case P2W_FORMAT_WB_CAL://SPH_P2W_ENH_CAL for WB:
         *spk_bufsize = 320;
         *mic_bufsize = 642; //320*2 +2;
         break;
	  case P2W_FORMAT_WB_NORMAL:
	  	 *mic_bufsize = *spk_bufsize = 320;
		 break;
      default:
         ASSERT(0);
   }
}

void PCMNWAY_Init(void)
{
   memset( &pcmEx, 0, sizeof(pcmEx) );
   PCM2Way_SetFormat(P2W_FORMAT_NORMAL);
}

/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   
#ifdef BGSND_ENABLE
void PCMNWAY_Register_SndService(
   void (*onHandler)(void *hdl),
   void (*offHandler)(void *hdl),
   void *hdl)
{
   pcmEx.sndOnHandler  = onHandler;
   pcmEx.sndOffHandler = offHandler;
   pcmEx.sndHdl        = hdl;
}

void PCMNWAY_UnRegister_SndService( void )
{
   pcmEx.sndOnHandler  = NULL;
   pcmEx.sndOffHandler = NULL;
}
#endif
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   
