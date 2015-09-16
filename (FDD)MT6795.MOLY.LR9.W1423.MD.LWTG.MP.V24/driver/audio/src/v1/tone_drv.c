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
 *  Tone_Drv.c
 *
 * Project:
 * --------
 *  MTK Feature Phone
 *
 * Description:
 * ------------
 *  DTMF tone driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "dcl.h"
#include "reg_base.h"
#include "l1d_reg.h"
#include "common_def.h"
#include "l1audio.h"
#include "media.h"
#include "afe.h"
#include "am.h"
#include "speech_def.h"
#include "audio_def.h"
#include "afe_def.h"
#include "l1audio_trace.h"
#include "l1sp_trc.h"
#include "tone_drv.h"
#include "sal_exp.h"

#if defined(__CVSD_CODEC_SUPPORT__) 
#include "bt_sco_drv.h"
#endif

#pragma arm section code="SECONDARY_ROCODE"

typedef struct _st_DTMF_DSP
{
   kal_uint32        uGPT;
   const L1SP_Tones  *pToneList;
   const L1SP_QTMF   *pCurrQtmf;
   kal_uint16        uCurrentNode;
   DTMF_DSP_STATE    uState;
   kal_bool          fIsQTMF;
} st_DTMF_DSP;

typedef struct _st_tone
{
   const L1SP_Tones  *pToneList;
   const L1SP_QTMF   *pCurrQtmf;
   kal_uint16        uAudId;
   kal_uint16        amp;
   void              (*fpHandler)(void);
   //kal_bool          fDspToneRunning;
   //kal_bool          fMcuToneRunning;
   kal_bool          fToneRunning;
#ifdef ANALOG_AFE_PATH_EXIST   
   kal_uint8         volume1;
#endif   
   kal_int8          digital_gain_index;
   TONE_TYPE         type;    
   kal_bool          fIsQTMF;
} st_tone;

typedef struct _st_keytone
{
   L1SP_Tones        dtmf;
   kal_uint16        uAudId;
   kal_uint8         lock;
#ifdef ANALOG_AFE_PATH_EXIST   
   kal_uint8         volume1;
#endif   
   kal_int8          digital_gain_index;
   kal_uint32        gain;
   //kal_bool          fDspToneRunning;
   //kal_bool          fMcuToneRunning;
   kal_bool          fToneRunning;
   
   TONE_TYPE         type; 
   kal_bool          fIsQTMF;
} st_keytone;

static st_DTMF_DSP DTMF_DSP;
static st_tone     tone[TOTAL_TONE_NUM];
static st_keytone  keytone[TOTAL_TONE_NUM];


#define DSP_TONE_IDLE      0
#define DSP_TONE_START     1
#define DSP_TONE_RUNING    2
#define DSP_TONE_STOP      4

#define DSP_WAIT_TIME                  10 //ms
#define DSP_STOP_AND_WAIT_MAX_TICK     40 //tick
#define DSP_QTMF_FREQ(f1,f2,f3,f4)  {  SAL_KT2_FREQ1  = (f1);                    \
                                       SAL_KT2_FREQ2  = (f2);                    \
                                       SAL_KT1_FREQ1  = (DTMF_DSP.fIsQTMF)?(f3):0; \
                                       SAL_KT1_FREQ2  = (DTMF_DSP.fIsQTMF)?(f4):0; }

static void dtmf_dsp_PlayOn( void *data );
static void dtmf_dsp_PlayOff( void *data );

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MCU_DTMF_SUPPORT__) //&& !defined( MED_MODEM ) 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
#endif

static const L1SP_QTMF *dtmf_dsp_GetNextTone(const L1SP_Tones *ppToneList, const L1SP_QTMF *pCurrQTMF, kal_bool fIsQTMF)
{
   const L1SP_QTMF *pNextQTMF;
   if(fIsQTMF)
   {
      pNextQTMF = (L1SP_QTMF *)ppToneList + pCurrQTMF->next_tone;
   }
   else
   {
      pNextQTMF = (L1SP_QTMF *)(ppToneList + pCurrQTMF->next_tone);
   }
   return pNextQTMF;
}



static void dtmf_dsp_SetTimer(kal_uint32 uMsec, void(*fpCallback)( void *pData ))
{
   kal_uint16 uDur = uMsec / 10;
   if(uDur)
   {
      SGPT_CTRL_START_T start;
      start.u2Tick = uDur;
      start.pfCallback = fpCallback;
      start.vPara = NULL;
      DclSGPT_Control( DTMF_DSP.uGPT, SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
   }
}

static void dtmf_dsp_StopTimer()
{
   DclSGPT_Control(DTMF_DSP.uGPT ,SGPT_CMD_STOP, 0);
}

static void dtmf_dsp_TurnOffDSP(kal_uint32 arg1, void* arg2)
{
   
   if(DTMF_DSP.uState != DTMF_DSP_STATE_ENDING)
   {
      return;
   }
   if(keytone[DSP_TONE].fToneRunning)
   {
      AM_KeyToneOff();
      SAL_KT_ATT_GAIN = 0;
      keytone[DSP_TONE].fToneRunning = KAL_FALSE;
      L1Audio_ClearFlag( keytone[DSP_TONE].uAudId );
   }
   else if(tone[DSP_TONE].fToneRunning)
   {
      AM_ToneOff();
      SAL_KT_ATT_GAIN = 0;
      tone[DSP_TONE].fToneRunning = KAL_FALSE;
      L1Audio_ClearFlag( tone[DSP_TONE].uAudId );
   }
   DTMF_DSP.uState = DTMF_DSP_STATE_IDLE;

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
#endif
}

static void dtmf_dsp_end( void *fWait )
{
   if(DTMF_DSP.uState == DTMF_DSP_STATE_IDLE)
   {
      return;
   }
   dtmf_dsp_StopTimer();
   if(SAL_KT1_FSM == DSP_TONE_RUNING)
   {
      SAL_KT1_FSM = DSP_TONE_STOP;
   }
   if(SAL_KT2_FSM == DSP_TONE_RUNING)
   {
      SAL_KT2_FSM = DSP_TONE_STOP;
   }
   if(SAL_KT1_FSM != DSP_TONE_IDLE || SAL_KT2_FSM != DSP_TONE_IDLE)
   {
      dtmf_dsp_SetTimer( DSP_WAIT_TIME, dtmf_dsp_end);
   }
   else
   {
      DTMF_DSP.uState = DTMF_DSP_STATE_ENDING;
   }

   if(fWait) //in task, stop and wait
   {  
      kal_int32 I =0;
      while(DTMF_DSP.uState != DTMF_DSP_STATE_ENDING && DTMF_DSP.uState != DTMF_DSP_STATE_IDLE )
      {
         kal_uint16 TONE_CTRL1, TONE_CTRL2;
         TONE_CTRL1 = SAL_KT1_FSM;
         TONE_CTRL2 = SAL_KT2_FSM;
         kal_sleep_task(1);
         //kal_prompt_trace(MOD_L1SP,"dtmf_dsp_end, TONE_CTRL1[%d]: %d, TONE_CTRL2[%d]: %d", (kal_uint32)DSP_TONE_CTRL1, TONE_CTRL1, (kal_uint32)DSP_TONE_CTRL2, TONE_CTRL2 );
         ASSERT(I < DSP_STOP_AND_WAIT_MAX_TICK);
         I++;
      }
      dtmf_dsp_TurnOffDSP(NULL, NULL);
   }
   else if(DTMF_DSP.uState == DTMF_DSP_STATE_ENDING) // in timer isr
   {
      L1Audio_InProcCall(dtmf_dsp_TurnOffDSP, NULL, NULL);
   }
}

static void dtmf_dsp_PlayOn( void *data )
{
   kal_prompt_trace(MOD_L1SP, "[dtmf_dsp_PlayOn] Enter");
   if(DTMF_DSP.uState == DTMF_DSP_STATE_IDLE)
   {
      return;
   }
   DTMF_DSP.pCurrQtmf = dtmf_dsp_GetNextTone( DTMF_DSP.pToneList, DTMF_DSP.pCurrQtmf, DTMF_DSP.fIsQTMF);
   if(SAL_KT1_FSM == DSP_TONE_IDLE && SAL_KT2_FSM == DSP_TONE_IDLE)
   {
      kal_prompt_trace(MOD_L1SP, "[dtmf_dsp_PlayOn] 1");
      DSP_QTMF_FREQ( DTMF_DSP.pCurrQtmf->freq1, DTMF_DSP.pCurrQtmf->freq2, DTMF_DSP.pCurrQtmf->freq3, DTMF_DSP.pCurrQtmf->freq4 );
      SAL_KT1_FSM = DSP_TONE_START;
      SAL_KT2_FSM = DSP_TONE_START;
      dtmf_dsp_SetTimer( DTMF_DSP.pCurrQtmf->on_duration, dtmf_dsp_PlayOff);
   }
   else
   {  kal_prompt_trace(MOD_L1SP, "[dtmf_dsp_PlayOn] 2");
      dtmf_dsp_SetTimer( DSP_WAIT_TIME, dtmf_dsp_PlayOn);
   }
   kal_prompt_trace(MOD_L1SP, "[dtmf_dsp_PlayOn] Leave");
}

static void dtmf_dsp_PlayOff( void *data )
{
   kal_prompt_trace(MOD_L1SP, "[dtmf_dsp_PlayOff] Enter");
   if(DTMF_DSP.uState == DTMF_DSP_STATE_IDLE)
   {
      return;
   }
   if(SAL_KT1_FSM == DSP_TONE_RUNING && SAL_KT2_FSM == DSP_TONE_RUNING)
   {
      SAL_KT1_FSM = DSP_TONE_STOP;
      SAL_KT2_FSM = DSP_TONE_STOP;
      if(DTMF_DSP.pCurrQtmf->off_duration)
      {
         kal_prompt_trace(MOD_L1SP, "[dtmf_dsp_PlayOff] 1");
         dtmf_dsp_SetTimer( DTMF_DSP.pCurrQtmf->off_duration, dtmf_dsp_PlayOn);
         DTMF_DSP.uCurrentNode = DTMF_DSP.pCurrQtmf->next_tone;
      }
      else
      {
         kal_prompt_trace(MOD_L1SP, "[dtmf_dsp_PlayOff] 2");
         dtmf_dsp_SetTimer( DSP_WAIT_TIME, dtmf_dsp_end);
      }
   }
   else
   {
      dtmf_dsp_SetTimer( DSP_WAIT_TIME, dtmf_dsp_PlayOff);
   }
   kal_prompt_trace(MOD_L1SP, "[dtmf_dsp_PlayOff] Leave");
}

static void dtmf_dsp_Start()
{
   kal_prompt_trace(MOD_L1SP, "[dtmf_dsp_Start] Enter");
   dtmf_dsp_StopTimer();
   ASSERT(DTMF_DSP.uState == DTMF_DSP_STATE_IDLE);
   DTMF_DSP.uState = DTMF_DSP_STATE_PLAYING;
   DTMF_DSP.uCurrentNode = 0;
   DSP_QTMF_FREQ( DTMF_DSP.pCurrQtmf->freq1, DTMF_DSP.pCurrQtmf->freq2, DTMF_DSP.pCurrQtmf->freq3, DTMF_DSP.pCurrQtmf->freq4 );
   SAL_KT1_FSM = DSP_TONE_START;
   SAL_KT2_FSM = DSP_TONE_START;
   dtmf_dsp_SetTimer( DTMF_DSP.pCurrQtmf->on_duration, dtmf_dsp_PlayOff);
   kal_prompt_trace(MOD_L1SP, "[dtmf_dsp_Start] Leave");
}


static void DTMF_DSP_Play( const L1SP_Tones *pToneList, kal_bool fIsQtmf, kal_bool fIsKeytone )
{
#if 1
   kal_prompt_trace(MOD_L1SP, "[DTMF_DSP_Play] Enter");
   KT_StopAndWait();
   TONE_StopAndWait();
   DTMF_DSP.fIsQTMF = fIsQtmf;
   DTMF_DSP.pCurrQtmf = (const L1SP_QTMF *)pToneList;
   if(fIsKeytone)
   {
      L1Audio_SetFlag( keytone[DSP_TONE].uAudId );
   }
   else
   {
      L1Audio_SetFlag( tone[DSP_TONE].uAudId );
      if( AM_IsSpeechOn() ) //only apply on tone
      {
         SAL_KT_ATT_GAIN = 0x4000;
      }
   }   

#if defined(__BT_SUPPORT__)
   if( L1SP_IsBluetoothOn() )
   {
      SAL_KT1_AMP = (TONE_INIT_AMP >> 2);               /* degrade bluetooth tone volume by 12dB */
      SAL_KT2_AMP = (TONE_INIT_AMP >> 2);               /* degrade bluetooth tone volume by 12dB */
     // *DP_VSBT_CTRL |= 0x1;                               // output to both BT and voice DAC
   }
   else
#endif
   {
      SAL_KT1_AMP = tone[DSP_TONE].amp;
      SAL_KT2_AMP = tone[DSP_TONE].amp;
   }
   if(fIsKeytone)
   {
      keytone[DSP_TONE].fToneRunning = KAL_TRUE;
      AM_KeyToneOn();
   }
   else
   {
      tone[DSP_TONE].fToneRunning = KAL_TRUE;
      AM_ToneOn();
   }
   dtmf_dsp_Start();
   kal_prompt_trace(MOD_L1SP, "[DTMF_DSP_Play] Leave");
#else
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
#if defined(__BT_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
}

static void DTMF_DSP_Stop( kal_bool fWait)
{
   dtmf_dsp_end( (void*)fWait );
}

void toneInit( uint16 uAudId, uint16 id_num )
{
   ASSERT( id_num < TOTAL_TONE_NUM );

   tone[id_num].type = id_num;

   if(id_num == DSP_TONE)
   {
      DTMF_DSP.uGPT = DclSGPT_Open( DCL_GPT_CB ,0 );
      tone[DSP_TONE].uAudId  = uAudId;
      tone[DSP_TONE].amp = TONE_INIT_AMP;
      SAL_KT_ATT_GAIN      = 0;
      SAL_KT1_FSM = 0;
      SAL_KT2_FSM = 0;
#ifdef ANALOG_AFE_PATH_EXIST	
      AFE_TurnOnFIR( L1SP_TONE );
#endif   
   }
   else
   {
      tone[id_num].uAudId  = uAudId;
      tone[id_num].amp = TONE_INIT_AMP;
   }
/*   DTMF_DSP.uGPT = DclSGPT_Open( DCL_GPT_CB ,0 );
   tone.uAudId  = uAudId;
   tone.amp = TONE_INIT_AMP;
   SAL_KT_ATT_GAIN      = 0;
   SAL_KT1_FSM = 0;
   SAL_KT2_FSM = 0;
#ifdef ANALOG_AFE_PATH_EXIST	
   AFE_TurnOnFIR( L1SP_TONE );
#endif   */
}

void ktInit( uint16 uAudId, uint16 id_num )
{
   ASSERT( id_num < TOTAL_TONE_NUM );

   keytone[id_num].type = id_num;

   if(id_num == DSP_TONE)
   {
      keytone[DSP_TONE].uAudId = uAudId;
      keytone[DSP_TONE].lock   = 0;
#ifdef ANALOG_AFE_PATH_EXIST    
      keytone[DSP_TONE].volume1 = 160;
#endif   
      keytone[DSP_TONE].gain = 0;
      keytone[DSP_TONE].digital_gain_index = 0;
      SAL_KT2_AMP  = KT_INIT_AMP;
#ifdef ANALOG_AFE_PATH_EXIST	   
      AFE_TurnOnFIR( L1SP_KEYTONE );
#endif
   }
   else
   {
      keytone[id_num].uAudId = uAudId;
      keytone[id_num].lock   = 0;
#ifdef ANALOG_AFE_PATH_EXIST    
      keytone[id_num].volume1 = 160;
#endif   
      keytone[id_num].gain = 0;
      keytone[id_num].digital_gain_index = 0;
   }
/*   keytone.uAudId = uAudId;
   keytone.lock   = 0;
#ifdef ANALOG_AFE_PATH_EXIST    
   keytone.volume1 = 160;
#endif   
   keytone.gain = 0;
   keytone.digital_gain_index = 0;
   SAL_KT2_AMP  = KT_INIT_AMP;
#ifdef ANALOG_AFE_PATH_EXIST	   
   AFE_TurnOnFIR( L1SP_KEYTONE );
#endif   */
}

void ktLock( void )
{
   kal_uint32 savedMask;
   ASSERT( keytone[DSP_TONE].lock < DTMF_KEYTONE_LOCK_MAX_COUNT );
   savedMask = SaveAndSetIRQMask();
   keytone[DSP_TONE].lock++;
   RestoreIRQMask(savedMask);
}

void ktUnlock( void )
{
   uint32 savedMask;
   ASSERT( keytone[DSP_TONE].lock > 0 );
   savedMask = SaveAndSetIRQMask();
   keytone[DSP_TONE].lock--;
   RestoreIRQMask(savedMask);
}

void TONE_SetOutputDevice( uint8 device )
{
   //DTMF_MCU_StopAndWait();
#ifdef ANALOG_AFE_PATH_EXIST      
   AFE_SetOutputDevice( L1SP_TONE, device );
#endif   
}

void TONE_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{  
#ifdef ANALOG_AFE_PATH_EXIST    
   tone[DSP_TONE].volume1 = volume1;
#endif   
   tone[DSP_TONE].digital_gain_index = digital_gain_index;
}

void TONE_SetOutputGainControl( uint32 gain )
{
#if defined(__GAIN_TABLE_SUPPORT__)
   //AFE_SetOutputGainControl( L1SP_TONE, gain );
#endif
}

kal_bool TONE_DspPlayable(void)
{
   kal_uint8 uVolume;
   kal_int8 iDigiGainIndex;

   if(/*AM_IsAVsyncOn() || AM_IsDAIMode() ||*/ AM_IsAudioPlaybackOn() != -1)
      return KAL_FALSE;
   if(tone[DSP_TONE].fToneRunning || keytone[DSP_TONE].fToneRunning )
      return KAL_FALSE;
   if(keytone[DSP_TONE].lock)
      return KAL_FALSE;

#ifdef ANALOG_AFE_PATH_EXIST		      
   AFE_GetOutputVolume(L1SP_TONE, &uVolume, &iDigiGainIndex); 
#else   
   AFE_DigitalOnly_GetOutputVolume(L1SP_TONE, &iDigiGainIndex );	
#endif   
#ifdef ANALOG_AFE_PATH_EXIST		      
   if(0 == uVolume || tone[DSP_TONE].volume1 == 0)
      return KAL_FALSE;
#endif            

   return KAL_TRUE;
}

void TONE_Play( const L1SP_Tones *pToneList, TONE_TYPE type)
{
   ASSERT( type < TOTAL_TONE_NUM );

#if defined(__AUDIO_NOT_SUPPORTED__)
   return;
#endif

#ifndef __VOLTE_SUPPORT__
   return;
#endif //#ifndef __VOLTE_SUPPORT__


//   if(AM_IsAfeOn()) return;
   kal_trace( TRACE_INFO, TONEPLAY, 0);

   if(type == DSP_TONE)
   {
#ifdef ANALOG_AFE_PATH_EXIST		
      AFE_SetOutputVolume( L1SP_TONE, tone[DSP_TONE].volume1, tone[DSP_TONE].digital_gain_index );
#else
      AFE_DigitalOnly_SetDigitalGain( L1SP_TONE, tone[DSP_TONE].digital_gain_index );    
#endif   
   
      kal_trace( TRACE_INFO, TONEPLAY, 1);
      if(!TONE_DspPlayable())
      {
         kal_trace( TRACE_INFO, TONEPLAY, 2);
         return;
      }
      DTMF_DSP.fIsQTMF = KAL_FALSE;
      tone[DSP_TONE].fIsQTMF = KAL_FALSE;
      DTMF_DSP.uCurrentNode = 0;
      DTMF_DSP.pToneList = pToneList;
      tone[DSP_TONE].fToneRunning = KAL_TRUE;
      DTMF_DSP_Play((const L1SP_Tones *)pToneList, tone[DSP_TONE].fIsQTMF/*DTMF_DSP.fIsQTMF*/, KAL_FALSE);
      kal_trace( TRACE_INFO, TONEPLAY, 3);
   }
   else
   {
      tone[type].fIsQTMF = KAL_FALSE;
       
      //tone[type].type = type;

      kal_trace( TRACE_INFO, TONEPLAY, 5);
      tone[type].fToneRunning = KAL_TRUE;
      DTMF_MCU_Play((const L1SP_Tones *)pToneList, tone[type].fIsQTMF/*DTMF_DSP.fIsQTMF*/, KAL_FALSE);

     //AM_ToneOn();

      kal_trace( TRACE_INFO, TONEPLAY, 6);
   }


#if 0
/* under construction !*/
#ifdef ANALOG_AFE_PATH_EXIST		
/* under construction !*/
#else
/* under construction !*/
#endif   
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
#endif /*#if 0*/
}

void TONE_PlayQTMF( const L1SP_QTMF *pToneList )
{
   //DTMF_DSP.fIsQTMF = KAL_TRUE;
   //TONE_Play((const L1SP_Tones *)pToneList);
}


void TONE_Stop( TONE_TYPE type )
{
#ifndef __VOLTE_SUPPORT__
   return;
#endif //#ifndef __VOLTE_SUPPORT__

   kal_trace( TRACE_INFO, TONESTOP);

   if(type == DSP_TONE)
   {
      if(tone[DSP_TONE].fToneRunning)
      {
         DTMF_DSP_Stop(KAL_FALSE);
      }
   }
   else
   {
      if(tone[type].fToneRunning)
      {
         DTMF_MCU_Stop(KAL_FALSE);
         tone[type].fToneRunning = KAL_FALSE;
      }
   }
/*   if(tone.fDspToneRunning)
   {
      DTMF_DSP_Stop(KAL_FALSE);
   }
   else if(tone.fMcuToneRunning)
   {
      DTMF_MCU_Stop(KAL_FALSE);
      tone.fMcuToneRunning = KAL_FALSE;
   }*/
}

void TONE_StopAndWait( void )
{
#ifndef __VOLTE_SUPPORT__
   return;
#endif //#ifndef __VOLTE_SUPPORT__

   if(!tone[DSP_TONE].fToneRunning)
   {
      return;
   }
   AM_FlushQFunction();
   DTMF_DSP_Stop(KAL_TRUE);
}

void TONE_SetAmplitude( int16 amp )
{
   //tone.amp = (uint16)amp;
   tone[DSP_TONE].amp = (uint16)amp;
}

void TONE_SetFIR( bool enable )
{
   if( enable )
   {
#ifdef ANALOG_AFE_PATH_EXIST		      
      AFE_TurnOnFIR( L1SP_TONE );
#endif      
   }
   else
   {
#ifdef ANALOG_AFE_PATH_EXIST		      
      AFE_TurnOffFIR( L1SP_TONE );
#endif      
   }
}

void TONE_SetHandler( void (*fpHandler)(void), TONE_TYPE type )
{
   //tone.fpHandler = fpHandler; //callback when tone stop done
   tone[type].fpHandler = fpHandler; //callback when tone stop done
}

kal_bool KT_DspPlayable(void)
{
   kal_uint8 uVolume;
   kal_int8 iDigiGainIndex;

   if(/*AM_IsAVsyncOn() || AM_IsDAIMode() || */AM_IsAudioPlaybackOn() != -1)   
      return KAL_FALSE;
   if(tone[DSP_TONE].fToneRunning || keytone[DSP_TONE].fToneRunning )
      return KAL_FALSE;
   if(keytone[DSP_TONE].lock)
      return KAL_FALSE;

#ifdef ANALOG_AFE_PATH_EXIST		      
   AFE_GetOutputVolume(L1SP_KEYTONE, &uVolume, &iDigiGainIndex); 
#else   
   AFE_DigitalOnly_GetOutputVolume(L1SP_KEYTONE, &iDigiGainIndex );	
#endif      

#ifdef ANALOG_AFE_PATH_EXIST
   if(0 == uVolume || keytone[DSP_TONE].volume1 == 0)
      return KAL_FALSE;
#endif            

   return KAL_TRUE;
}

void KT_SetOutputDevice( uint8 device )
{
#ifndef __VOLTE_SUPPORT__
   return;
#endif //#ifndef __VOLTE_SUPPORT__

   KT_StopAndWait();
   if(DTMF_MCU_IsKeytonePlaying() && device != AFE_GetOutputDevice(L1SP_KEYTONE))
   {
      DTMF_MCU_StopAndWait();
   }
#ifdef ANALOG_AFE_PATH_EXIST      
   AFE_SetOutputDevice( L1SP_KEYTONE, device);
#endif   
}

void KT_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
#ifdef ANALOG_AFE_PATH_EXIST
   keytone[DSP_TONE].volume1 = volume1;
#endif   
   keytone[DSP_TONE].digital_gain_index = digital_gain_index;
}

bool PcmSink_IsAudioRuning()
{
   return false;   
}

void KT_SetOutputGainControl( uint32 gain )
{
#if defined(__GAIN_TABLE_SUPPORT__)
   //keytone.gain = gain;
   keytone[DSP_TONE].gain = gain;
   AFE_SetOutputGainControl(L1SP_KEYTONE, gain);
#endif
}

void KT_Play( kal_uint16 freq1, kal_uint16 freq2, kal_uint16 duration, TONE_TYPE type) //duration in msec
{
#ifndef __VOLTE_SUPPORT__
   return;
#endif //#ifndef __VOLTE_SUPPORT__

   kal_trace( TRACE_INFO, KTPLAY, 0);
#if defined(KEYTONE_DEBUG)   
   Keytone_Debug_Entry(freq1, freq2);
   return;
#endif   
#if defined(__AUDIO_NOT_SUPPORTED__)
   return;
#endif


   if(type == DSP_TONE)
   {
      kal_trace( TRACE_INFO, KTPLAY, 1);
#ifdef ANALOG_AFE_PATH_EXIST		
      AFE_SetOutputVolume( L1SP_KEYTONE, keytone[DSP_TONE].volume1, keytone[DSP_TONE].digital_gain_index );
#else
      AFE_DigitalOnly_SetDigitalGain( L1SP_KEYTONE, keytone[DSP_TONE].digital_gain_index );  
#endif	   

      if(!KT_DspPlayable())
      {
         kal_trace( TRACE_INFO, KTPLAY, 2);
         return;
      }

      keytone[DSP_TONE].dtmf.freq1 = freq1;
      keytone[DSP_TONE].dtmf.freq2 = freq2;
      keytone[DSP_TONE].dtmf.on_duration = duration;
      keytone[DSP_TONE].dtmf.off_duration = 0;
      //keytone[DSP_TONE].type = type;
      kal_trace( TRACE_INFO, KTPLAY, 3);

      DTMF_DSP_Play((const L1SP_Tones *)&keytone[DSP_TONE].dtmf, KAL_FALSE, KAL_TRUE);
      kal_trace( TRACE_INFO, KTPLAY, 4);
   }
   else
   {
#if defined(__MCU_DTMF_SUPPORT__) //&& !defined( MED_MODEM ) 
      if(PcmSink_IsAudioRuning() || DTMF_MCU_IsTonePlaying() /*|| AM_IsAfeOn()*/)
      {  
         return; //disable keytone during audio playback
      }
#endif  //defined(__MCU_DTMF_SUPPORT__) //&& !defined( MED_MODEM ) 
       
      kal_trace( TRACE_INFO, KTPLAY, 5);
      keytone[type].dtmf.freq1 = freq1;
      keytone[type].dtmf.freq2 = freq2;
      keytone[type].dtmf.on_duration = duration;
      keytone[type].dtmf.off_duration = 0;
      //keytone[DSP_TONE].type = type;

      kal_trace( TRACE_INFO, KTPLAY, 6);
      keytone[type].fToneRunning = KAL_TRUE;
      DTMF_MCU_Play((const L1SP_Tones *)&keytone[type].dtmf, KAL_FALSE, KAL_TRUE);

      kal_trace( TRACE_INFO, KTPLAY, 7);
   }

#if 0
#if defined(__MCU_DTMF_SUPPORT__) //&& !defined( MED_MODEM ) 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  //defined(__MCU_DTMF_SUPPORT__) //&& !defined( MED_MODEM ) 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef ANALOG_AFE_PATH_EXIST		
/* under construction !*/
#else
/* under construction !*/
#endif	   
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
#endif /*#if 1*/
}

void KT_Stop( TONE_TYPE type )
{
#ifndef __VOLTE_SUPPORT__
   return;
#endif //#ifndef __VOLTE_SUPPORT__

   kal_trace( TRACE_INFO, KTSTOP);

   if(type == DSP_TONE)
   {
      if(keytone[DSP_TONE].fToneRunning)
      {
         DTMF_DSP_Stop(KAL_FALSE);
      }
   }
   else
   {
      if(keytone[type].fToneRunning)
      {
         DTMF_MCU_Stop(KAL_TRUE);
         keytone[type].fToneRunning = KAL_FALSE;
      }      
   }
   return;

/*   if(keytone.fDspToneRunning)
   {
      DTMF_DSP_Stop(KAL_FALSE);
   }else
   if(keytone.fMcuToneRunning)
   {
      DTMF_MCU_Stop(KAL_TRUE);
      keytone.fMcuToneRunning = KAL_FALSE;
   }      
   return;*/
}

void KT_StopAndWait()
{
   kal_int32 I;

#ifndef __VOLTE_SUPPORT__
   return;
#endif //#ifndef __VOLTE_SUPPORT__

   //if(!keytone.fDspToneRunning)
   if(!keytone[DSP_TONE].fToneRunning)
   {
      return;
   }
   AM_FlushQFunction();
   DTMF_DSP_Stop(KAL_TRUE);
}

void KT_SetAmplitude( int16 amp )
{
   SAL_KT2_AMP   = amp;
}

void KT_SetFIR( bool enable )
{
   if( enable )
   {
#ifdef ANALOG_AFE_PATH_EXIST	      
      AFE_TurnOnFIR( L1SP_KEYTONE );
#endif
   }
   else
   {
#ifdef ANALOG_AFE_PATH_EXIST	            
      AFE_TurnOffFIR( L1SP_KEYTONE);
#endif      
   }
}

kal_bool KT_IsPlayable(void)
{
   kal_uint8 uVolume;
   kal_int8 iDigiGainIndex;
   if(keytone[DSP_TONE].fToneRunning)//(dtmf_dsp_DspToneCase())
   {
      return KT_DspPlayable();
   }
   else
   {
#if defined(__MCU_DTMF_SUPPORT__) //&& !defined( MED_MODEM )    	
      if(PcmSink_IsAudioRuning() || tone[DSP_TONE].fToneRunning || keytone[DSP_TONE].fToneRunning)
      {  
         return KAL_FALSE; //disable keytone during audio playback
      }
#endif      
      AFE_GetOutputVolume(L1SP_KEYTONE, &uVolume, &iDigiGainIndex); 
#ifdef ANALOG_AFE_PATH_EXIST      
      if(0 == uVolume || keytone[DSP_TONE].volume1 == 0)
      {
         return KAL_FALSE;
      }         
#endif
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
#if defined(__MCU_DTMF_SUPPORT__) //&& !defined( MED_MODEM )    	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif      
/* under construction !*/
#ifdef ANALOG_AFE_PATH_EXIST      
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif
}

#pragma arm section

