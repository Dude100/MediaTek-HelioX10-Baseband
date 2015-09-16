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

#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "intrCtrl.h"
#include "string.h"
#include "hisr_config.h"
#include "kal_public_defs.h"
#include "reg_base.h"
#include "l1sm_public.h"

#include "kal_trace.h"
#include "l1sp_trc.h"
#include "l1audio.h"
#include "audio_def.h"
#include "media.h"
#include "l1audio_trace.h"
#include "ddload.h"
#include "am.h"
#include "afe.h"
#include "common_def.h"
//#include "speech_def.h"
#include "sal_def.h"
#include "sal_exp.h"
#if defined( __CENTRALIZED_SLEEP_MANAGER__ )
#include "RM_public.h"
#endif

#if defined(__SMART_PHONE_MODEM__)
#include "bgSnd.h" // for BGSND_INIT() 
#endif // defined(__SMART_PHONE_MODEM__)

#if defined(__CVSD_CODEC_SUPPORT__) 
#include "bt_sco_drv.h"
#endif

#if defined(MT6595)
#include "init.h" // for INT_SW_SecVersion
#endif

#include "mml1_rf_global.h"


#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )

#if defined(MT6280) || defined(MT6589) // smart phone modem, super dongle. 
#define  MAX_HISR_HANDLER        8 // 3g, pnw, vm, epl, bgsnd, record (for tranditional hosted dongle,  6 is enough, i.e. 3g, datacard, vm, epl)
#elif defined(MT6290)
#define  MAX_HISR_HANDLER        (9+4) // 3g, pnw, vm, epl, bgsnd(ul+dl), record (for tranditional hosted dongle,  6 is enough, i.e. 3g, datacard, vm, epl)
#elif defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571) || defined(MT6595) || defined(MT6752)
   #if defined(__VOLTE_SUPPORT__)
      #define  MAX_HISR_HANDLER       15 // 3g(ul+dl), pnw(ul+dl), DACA for bt (ul+dl), vm, epl, bgsnd(ul+dl), record, 4G AMR (ul+dl), 4G G-codec (ul+dl)
   #else //#if defined(__VOLTE_SUPPORT__)
      #define  MAX_HISR_HANDLER       12 // 3g, pnw, DACA for bt, vm, epl, bgsnd(ul+dl), record, cvsd
   #endif //#if defined(__VOLTE_SUPPORT__)
#else
	#error Need to check the HISR number for the new chip
#endif // by chip

#else // no 3g
#if defined(MT6280) || defined(MT6589) // smart phone modem, super dongle. 
#define  MAX_HISR_HANDLER        6 // pnw, vm, epl, bgsnd, record  (for tranditional hosted dongle,  4 is enough, i.e. datacard, vm, epl)
#elif defined(MT6290)
#define  MAX_HISR_HANDLER        7 // 3g, pnw, vm, epl, bgsnd(ul+dl), record (for tranditional hosted dongle,  5 is enough, i.e. datacard, vm, epl)
#elif defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571) || defined(MT6595) || defined(MT6752)
#define  MAX_HISR_HANDLER       10 // pnw, DACA for bt, vm, epl, bgsnd(ul+dl), record, cvsd

#else
	#error Need to check the HISR number for the new chip
#endif // by chip

#endif

uint32 SaveAndSetIRQMask( void );
void   RestoreIRQMask( uint32 );
void toneLoopbackRecInit( void );
extern void DisableIRQ(void);

#ifdef MTK_SLEEP_ENABLE
   #define  GET_SLEEP_HANDLE()   {  l1audio.sleep_handle=SleepDrv_GetHandle();       }
   #define  SLEEP_LOCK()         {  SleepDrv_SleepDisable( l1audio.sleep_handle );   }
   #define  SLEEP_UNLOCK()       {  SleepDrv_SleepEnable( l1audio.sleep_handle );    }
#else
   #define  GET_SLEEP_HANDLE()
   #define  SLEEP_LOCK()
   #define  SLEEP_UNLOCK()
#endif

extern uint32 L1I_GetTimeStamp( void );

#if (defined( __CENTRALIZED_SLEEP_MANAGER__ ) && defined(MTK_SLEEP_ENABLE) )
#if defined(__AUDIO_POWERON_RESET_DSP__)
   extern unsigned short  L1D_Audio_RestartDSP( void );
   extern void            L1D_Audio_NoNeedDSP( void );
   extern void AFE_Init_status(kal_bool flag);
#else
   extern kal_uint8  L1SM_IntGetHandle( void );
   extern void       L1SM_Multi_SW_WakeUp(void); 
   extern void       L1SM_IntSleepDisable( kal_uint8 handle );
   extern void       L1SM_IntSleepEnable( kal_uint8 handle );
   extern kal_uint8  L1D_MD2G_PWD_GetHandle( void );
   extern      void  L1D_MD2G_PWD_Disable( kal_uint8 handle );
   extern      void  L1D_MD2G_PWD_Enable( kal_uint8 handle );
#endif // defined(__AUDIO_POWERON_RESET_DSP__)
#endif //(defined( __CENTRALIZED_SLEEP_MANAGER__ ) && defined(MTK_SLEEP_ENABLE) )

/* ------------------------------------------------------------------------------ */

static struct {
   uint32               sleppModeLocker;
   uint32               dspUser;
   kal_eventgrpid       aud_events;
   uint16               media_flag;
   uint16               d2c_itype;
   uint32               d2c_l1FN;
   uint32               retrieved_events;
   uint32               events_l1FN;
   kal_hisrid           hisr;

   L1Audio_EventHandler evHandler[MAX_AUDIO_FUNCTIONS];
   void                 *evData[MAX_AUDIO_FUNCTIONS];
   uint32               id_flag;
   uint32               event_flag;
   L1Audio_EventHandler hisrHandler[MAX_HISR_HANDLER];
   uint16               hisrMagicNo[MAX_HISR_HANDLER];
   void                 *hisrUserData[MAX_HISR_HANDLER];
   uint16               hisrMagicFlag;
   uint8                sleep_handle;
   int8                 dsp_slow_idle_counter;

   uint16               debug_info[NUM_DEBUG_INFO];

   kal_uint8            md2g_pdn_handle;
   kal_uint8            l1sm_handle;
   kal_uint8            audio_cpd_count;
   kal_semid            sema;

	bool                 isD2MIntAvalibaleUnderSleep; // does Dsp to MCU interrupt can trigger under MCU sleep
} l1audio;

/* ------------------------------------------------------------------------------ */
extern void L1D_DSP_EnableDspSlowIdle( void );
int8 L1Audio_Disable_DSPSlowIdle(void)
{
   uint32 savedMask;
   int8    dis_check_counter;

   savedMask = SaveAndSetIRQMask();
   l1audio.dsp_slow_idle_counter++;
   dis_check_counter = l1audio.dsp_slow_idle_counter;

   DP_SLOW_IDLE_CTRL = 0xFFFF;
   RestoreIRQMask( savedMask );

   return dis_check_counter;
}

int8 L1Audio_Enable_DSPSlowIdle(void)
{
   uint32 savedMask;
   int8    en_check_counter;

   savedMask = SaveAndSetIRQMask();
   l1audio.dsp_slow_idle_counter--;
   en_check_counter = l1audio.dsp_slow_idle_counter;

   if ( l1audio.dsp_slow_idle_counter == 0 )
       L1D_DSP_EnableDspSlowIdle();

   RestoreIRQMask( savedMask );
   ASSERT( en_check_counter >= 0 );

   return en_check_counter;
}

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

   ASSERT( (l1audio.sleppModeLocker & (1 << I)) == 0 );
   ASSERT_REBOOT( I < MAX_AUDIO_FUNCTIONS );
   return (uint16)I;
}

void L1Audio_FreeAudioID( uint16 aud_id )
{
   uint32 savedMask;
   uint32 retrieved_events;
   kal_retrieve_eg_events(l1audio.aud_events,(1<<aud_id),KAL_OR_CONSUME,&retrieved_events,0);
   ASSERT( (l1audio.sleppModeLocker & (1 << aud_id)) == 0 );
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
   /* Activate L1Audio Task */
   kal_set_eg_events( l1audio.aud_events, 1 << audio_id, KAL_OR );
}

void L1Audio_LSetEvent( uint16 audio_id, void *data )
{
   uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   l1audio.evData[audio_id] = data;
   l1audio.event_flag |= (1 << audio_id);
   RestoreIRQMask( savedMask );

   /* Activate L1Audio HISR */
   kal_activate_hisr( l1audio.hisr );
}

bool L1Audio_CheckFlag( uint16 audio_id )
{
   ASSERT( l1audio.id_flag & (1 << audio_id) );
   if( l1audio.sleppModeLocker & (1 << audio_id) )
      return true;
   return false;
}

#if defined( __CENTRALIZED_SLEEP_MANAGER__ )

static void Audio_Wake_DSP(uint16 audio_id, kal_bool flag)
{
   if (!kal_if_hisr() && !kal_if_lisr())
      kal_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_MD2G_PWR_CTRL, audio_id, flag);
   else
      kal_dev_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_MD2G_PWR_CTRL, audio_id, flag);
      
   if(flag)
   {
      RM_Resource_Control (RM_MODEM_DSP_1, flag);

#if defined(MTK_SLEEP_ENABLE)
   #if defined(__AUDIO_POWERON_RESET_DSP__)
      AFE_RegisterStore();                               //restore AFE register
      {
         unsigned short DSP_status;     
         DSP_status = L1D_Audio_RestartDSP();
         ASSERT(!DSP_status);
      }
   #else
      L1SM_IntSleepDisable( l1audio.l1sm_handle );
      L1SM_Multi_SW_WakeUp();
      L1D_MD2G_PWD_Disable(l1audio.md2g_pdn_handle);
      L1SM_IntSleepEnable( l1audio.l1sm_handle );
   #endif
#endif
      l1audio.audio_cpd_count++;
   } else {
#if defined(MTK_SLEEP_ENABLE)
   #if defined(__AUDIO_POWERON_RESET_DSP__)
      L1D_Audio_NoNeedDSP();
      AFE_RegisterBackup();                         //Backup AFE register
   #else
      L1D_MD2G_PWD_Enable(l1audio.md2g_pdn_handle);
   #endif
#endif
      RM_Resource_Control (RM_MODEM_DSP_1, flag);
      l1audio.audio_cpd_count--;
   }
   if (!kal_if_hisr() && !kal_if_lisr())
      kal_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_MD2G_PWR_CTRL_DONE, audio_id, flag);
   else
      kal_dev_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_MD2G_PWR_CTRL_DONE, audio_id, flag);
}
#endif //( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))

void L1Audio_SetFlag( uint16 audio_id )
{
   uint32 savedMask;
   if (!kal_if_hisr() && !kal_if_lisr())
      kal_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_SETFLAG_A,audio_id,l1audio.dspUser);
   else
      kal_dev_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_SETFLAG_A,audio_id,l1audio.dspUser);

   kal_take_sem( l1audio.sema, KAL_INFINITE_WAIT );
   ASSERT( l1audio.id_flag & (1 << audio_id) );
   ASSERT( (l1audio.sleppModeLocker & (1 << audio_id)) == 0 );
	ASSERT( (l1audio.dspUser & (1 << audio_id)) == 0 );
	
   if( l1audio.dspUser == 0 ) {
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
      Audio_Wake_DSP(audio_id, KAL_TRUE);
#endif
   }

	if (false == l1audio.isD2MIntAvalibaleUnderSleep && l1audio.sleppModeLocker == 0) {
      	SLEEP_LOCK();
	}

   savedMask = SaveAndSetIRQMask();
	if (false == l1audio.isD2MIntAvalibaleUnderSleep) {
	   l1audio.sleppModeLocker |= (1 << audio_id);	
	}
   l1audio.dspUser |= (1 << audio_id);
   RestoreIRQMask( savedMask );
   kal_give_sem( l1audio.sema ); 
}

void L1Audio_ClearFlag( uint16 audio_id )
{
   uint32 savedMask;
   if (!kal_if_hisr() && !kal_if_lisr())  
      kal_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_CLEARFLAG_A,audio_id,l1audio.dspUser);
   else
      kal_dev_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_CLEARFLAG_A,audio_id,l1audio.dspUser);

	kal_take_sem( l1audio.sema, KAL_INFINITE_WAIT );
   ASSERT( l1audio.id_flag & (1 << audio_id) );
	ASSERT( l1audio.dspUser & (1 << audio_id) );
	if (false == l1audio.isD2MIntAvalibaleUnderSleep) {
   	ASSERT( l1audio.sleppModeLocker & (1 << audio_id) );
	}

   savedMask = SaveAndSetIRQMask();
	if (false == l1audio.isD2MIntAvalibaleUnderSleep) {
	   l1audio.sleppModeLocker &= ~(1 << audio_id);
	}
   l1audio.dspUser &= ~(1 << audio_id);
   RestoreIRQMask( savedMask );

	if((false == l1audio.isD2MIntAvalibaleUnderSleep) && (l1audio.sleppModeLocker == 0) ) {
      SLEEP_UNLOCK();
   }
	
   if( l1audio.dspUser == 0 ) {      
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
      Audio_Wake_DSP(audio_id, KAL_FALSE);
#endif
   }
   kal_give_sem( l1audio.sema ); 
}

void L1Audio_SetFlag_MD2G( uint16 audio_id )
{
   uint32 savedMask;
   if (!kal_if_hisr() && !kal_if_lisr())
      kal_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_SETFLAG_MD2G_A,audio_id,l1audio.dspUser);
   else
      kal_dev_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_SETFLAG_MD2G_A,audio_id,l1audio.dspUser);

   kal_take_sem( l1audio.sema, KAL_INFINITE_WAIT );
   ASSERT( l1audio.id_flag & (1 << audio_id) );
   ASSERT( (l1audio.dspUser & (1 << audio_id)) == 0 );

   if( l1audio.dspUser == 0 ) {
#if defined( __CENTRALIZED_SLEEP_MANAGER__ )
      Audio_Wake_DSP(audio_id,KAL_TRUE);
#endif
   }

   savedMask = SaveAndSetIRQMask();
   l1audio.dspUser |= (1 << audio_id);
   RestoreIRQMask( savedMask );
   kal_give_sem( l1audio.sema ); 
}

void L1Audio_ClearFlag_MD2G( uint16 audio_id )
{
   uint32 savedMask;
   if (!kal_if_hisr() && !kal_if_lisr())  
      kal_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_CLEARFLAG_MD2G_A,audio_id,l1audio.dspUser);
   else
      kal_dev_trace( TRACE_GROUP_AUD_MD2GCTRL, L1AUDIO_CLEARFLAG_MD2G_A,audio_id,l1audio.dspUser);
      
   kal_take_sem( l1audio.sema, KAL_INFINITE_WAIT );
   ASSERT( l1audio.id_flag & (1 << audio_id) );
   ASSERT( l1audio.dspUser & (1 << audio_id) );

   savedMask = SaveAndSetIRQMask();
   l1audio.dspUser &= ~(1 << audio_id);
   RestoreIRQMask( savedMask );
   
   if(l1audio.dspUser == 0 ) {
#if defined( __CENTRALIZED_SLEEP_MANAGER__ )
      Audio_Wake_DSP(audio_id,KAL_FALSE);
#endif
   }
   kal_give_sem( l1audio.sema ); 
}


void L1Audio_AllowSleep( kal_uint16 audio_id )
{
   uint32 savedMask;

   ASSERT( l1audio.id_flag & (1 << audio_id) );
   ASSERT( l1audio.sleppModeLocker & (1 << audio_id) );

   savedMask = SaveAndSetIRQMask();
   l1audio.sleppModeLocker &= ~(1 << audio_id);
   RestoreIRQMask( savedMask );

   if( l1audio.sleppModeLocker == 0)
      SLEEP_UNLOCK();
}

void L1Audio_DisallowSleep( kal_uint16 audio_id )
{
   uint32 savedMask;

   ASSERT( l1audio.id_flag & (1 << audio_id) );
   ASSERT( l1audio.sleppModeLocker & (1 << audio_id) );

   savedMask = SaveAndSetIRQMask();
   l1audio.sleppModeLocker |= (1 << audio_id);
   RestoreIRQMask( savedMask );

   if(l1audio.sleppModeLocker)
      SLEEP_LOCK();
}

/* ------------------------------------------------------------------------------ */
/*  L1Audio HISR                                                                  */
/* ------------------------------------------------------------------------------ */

void L1Audio_HISR( void )
{
   uint32 savedMask;
   int32  I;

   L1Audio_Disable_DSPSlowIdle();

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

   // To restore slow idle ctrl for DSP
   L1Audio_Enable_DSPSlowIdle();
}


void L1Audio_TrigD2CHisr(uint16 magicNo)
{
	int32 I;
	   for( I = 0; I < MAX_HISR_HANDLER; I++ ) {
      if( magicNo == l1audio.hisrMagicNo[I] ) {
         l1audio.hisrMagicFlag |= (1<<I);
         kal_activate_hisr(l1audio.hisr);
         return; 
      }
   }
	
}

void L1SP_D2C_LISR( uint16 itype )
{
	uint32 sph_int = 0;
	bool dsp_ok = false;
	bool from_sph;

   l1audio.d2c_itype = itype;
   l1audio.d2c_l1FN = L1I_GetTimeStamp();
   L1Audio_Msg_DSP_INT( itype );

   if(itype == D2C_DSP_DEAD_INT_ID){
#ifndef  L1D_TEST
      ASSERT_DUMP_PARAM_T dump_param;
      dump_param.addr[0] = (kal_uint32)(DPRAM_CPU_base +0x0A0*2);
      dump_param.len[0]  = 70*2;
      dump_param.addr[1] = (kal_uint32)(DPRAM2_CPU_base+0x130*2);
      dump_param.len[1]  = 180*2;
      dump_param.addr[2] = 0;    //End of dump param
      EXT_ASSERT_DUMP(0, 0x20060622, 0, 0, &dump_param);
#else
      extern void  L1DTest_AssertFail(void);
      L1DTest_AssertFail();
#endif
   }

   from_sph = SAL_DSPINT_Resolve(itype, &sph_int);//the itype should be the real one sent directly from DSP

	L1Audio_Msg_DSP_D2C_SPEECH_INT(L1AUDIO_Str_Bool(from_sph), sph_int);
	
	if(from_sph) {
		
		kal_int16 i;
		for( i=1; i< SAL_DSPINT_PRIO_MAX; i++) {
			if(sph_int & (1 << i)) {
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
				#endif /*#if 0*/
					L1Audio_TrigD2CHisr(DP_D2C_INT_MAPPING_BASIC+i); // please reference to 
				#if 0
/* under construction !*/
				#endif /*#if 0*/
	         dsp_ok |= true;
			}
		}
		/*
		// original mapping
      if(sph_int & SAL_DSPINT_ID_REC_VM){ // vm record
	  		L1Audio_TrigD2CHisr(DP_D2C_VM_REC_INT);
         dsp_ok |= true;
      }

		if(sph_int & SAL_DSPINT_ID_REC_PCM){ // pcm record
	  		L1Audio_TrigD2CHisr(DP_D2C_PCM_REC_INT);
         dsp_ok |= true;
      }
	  
      if(sph_int & SAL_DSPINT_ID_PNW_DL){ // pnw
			 L1Audio_TrigD2CHisr(DP_D2C_PCM_EX_DL); // DP_D2C_PCM_EX_DL, pcmNway
         dsp_ok |= true;
      }
      if(sph_int & SAL_DSPINT_ID_DACA_DL){ // data card
         L1Audio_TrigD2CHisr(DP_D2C_DACA_REQ_DL); // data card
         dsp_ok |= true;
      }
      if(sph_int & SAL_DSPINT_ID_3G_DL){ // 3g dl
         //L1SP_D2C_LISR(DP_D2C_3G_DONE_DL);//Don't trigger LISR here. 3G driver will trigger HISR by it's timing
         dsp_ok |= true;
      }
      if(sph_int & SAL_DSPINT_ID_BGS){ // background sound
         L1Audio_TrigD2CHisr(D2C_SOUND_EFFECT_INT_ID); // background sound, SND_EFFECT_MAGIC_NO
         dsp_ok |= true;
      }
      if(sph_int & SAL_DSPINT_ID_AVBT){ //AVBT
         L1Audio_TrigD2CHisr(D2C_AUDIO_VIA_BT_ID);
         dsp_ok |= true;
      }

      if(sph_int & SAL_DSPINT_ID_REC_EPL){
         L1Audio_TrigD2CHisr(DP_D2C_VMEPL_REC_INT); // call record pcm, call record vm
         dsp_ok |= true;
      }
      if(sph_int & SAL_DSPINT_ID_PNW_UL){
         L1Audio_TrigD2CHisr(DP_D2C_PCM_EX_UL); // pcmnway ul
         dsp_ok |= true;
      }
      if(sph_int & SAL_DSPINT_ID_DACA_UL){
         L1Audio_TrigD2CHisr(DP_D2C_DACA_REQ_UL); // data card
         dsp_ok |= true;
      }
      if(sph_int & SAL_DSPINT_ID_3G_UL){
         L1Audio_TrigD2CHisr(DP_D2C_3G_DONE_UL); // 3g
         dsp_ok |= true;
      }
	 */
	 
      if(0 != sph_int){//After DSP send D2C and turn on bit in DP_D2C_SPEECH_UL_INT, but  MCU doesnt  receive D2C. Handover causes VBIReset which will clean DP_D2C_SPEECH_UL_INT
         if (!dsp_ok) {
            extern void L1D_WIN_DisableAllEvents(uint16 except_irq_mask);
            DisableIRQ();
            L1D_WIN_DisableAllEvents( 0 ); /* disable all TDMA events */
            ASSERT_REBOOT(0);
         }
      }else{
	   	L1Audio_Msg_DSP_D2C_SPEECH_INT_SKIP(sph_int);
      }
	  
	// if(from_sph)  
		return;
   } 

   l1audio.media_flag = itype;
   kal_activate_hisr(l1audio.hisr);
}

void L1Audio_ActivateHisrHandler(kal_uint16 magic_no, void *userData)
{
   uint32 I, uMask32;
   uMask32 = SaveAndSetIRQMask();
   for( I = 0; I < MAX_HISR_HANDLER; I++ ) {
      if( magic_no == l1audio.hisrMagicNo[I] ) {
         l1audio.hisrMagicFlag |= (1<<I);
         l1audio.hisrUserData[I] = userData;
      }
   }
   RestoreIRQMask( uMask32 );
   if(l1audio.hisrMagicFlag != 0)
      kal_activate_hisr(l1audio.hisr);
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

/* ------------------------------------------------------------------------------ */
/*  Debug functions used to verify the data written to DSP                        */
/* ------------------------------------------------------------------------------ */
#if VERIFY_DATA_TO_DSP
#include   "fat_fs.h"
kal_uint8  bDSPBuffer[8192];
kal_uint16 uDSPBufferRead;
kal_uint16 uDSPBufferWrite;
kal_uint32 uDSPBufferSize;
kal_uint16 fname[12] = { 'E', ':', '\\', 'D', 'A', 'T', 'A', '.', 'D', 'A', 'T', 0x00 };
FS_HANDLE  fs_handle = 0;

void VERIFY_DATA_TO_DSP_START( void )
{
   if( fs_handle )
      FS_Close( fs_handle );
   fs_handle = FS_Open( (const kal_wchar*)fname, FS_CREATE_ALWAYS );
   ASSERT( fs_handle > 0 );
   uDSPBufferSize = 8192;
   uDSPBufferRead = 0;
   uDSPBufferWrite = 0;
}

void VERIFY_DATA_TO_DSP_RESUME( void )
{
   kal_uint32 uFileSize;
   kal_int32  ret;
   fs_handle = FS_Open( (const kal_wchar*)fname, FS_READ_WRITE|FS_CREATE );
   ASSERT( fs_handle > 0 );
   if(FS_GetFileSize(fs_handle, &uFileSize) < 0)
     ASSERT(0);
   if(FS_Seek(fs_handle, uFileSize, FS_FILE_BEGIN) < 0)
     ASSERT(0);
   uDSPBufferSize = 8192;
}

void VERIFY_DATA_TO_DSP_STOP( void )
{
   if( fs_handle )
   {
      if (FS_Close( fs_handle ) != 0)
         ASSERT(0);
      fs_handle = 0;
   }
}

void VERIFY_DATA_TO_DSP_WRITE_DATA( const kal_uint16 *buf, int32 len )
{
   kal_uint32 uDSPBufferFree;
   if( uDSPBufferWrite < uDSPBufferRead )
   {  /// DDDDWxxxxxxxRDD
      uDSPBufferFree = uDSPBufferRead - uDSPBufferWrite - 1;
      ASSERT( len*2 <= uDSPBufferFree );
      memcpy(bDSPBuffer+uDSPBufferWrite, buf, len*2);
      uDSPBufferWrite += len*2;
   }
   else
   {  /// xxxRDDDDDDWxxxx
      kal_uint32 free_1, free_2, write_count;
      free_1 = uDSPBufferSize - uDSPBufferWrite;
      free_2 = uDSPBufferRead - 1;
      uDSPBufferFree = free_1 + free_2;
      ASSERT( len*2 <= uDSPBufferFree );
      write_count = ( len*2 > free_1 )? free_1 : len*2;
      memcpy(bDSPBuffer+uDSPBufferWrite, buf, write_count);
      uDSPBufferWrite += write_count;
      if( uDSPBufferWrite==uDSPBufferSize )
         uDSPBufferWrite = 0;
      write_count = len*2 - write_count;
      if( write_count )
         memcpy(bDSPBuffer+uDSPBufferWrite, buf, write_count);
      uDSPBufferWrite += write_count;
   }
}

void VERIFY_DATA_TO_DSP_SAVE_DATA( void )
{
   if( fs_handle != 0 && uDSPBufferRead != uDSPBufferWrite )
   {
      kal_uint32 uDSPBufferUsed;
      kal_uint32 uDataSaved;
      if( uDSPBufferRead < uDSPBufferWrite )
      {  /// xxxRDDDDDDWxxxx
         uDSPBufferUsed = uDSPBufferWrite - uDSPBufferRead;
         FS_Write( fs_handle, bDSPBuffer+uDSPBufferRead, uDSPBufferUsed, &uDataSaved );
         ASSERT( uDSPBufferUsed == uDataSaved );
         uDSPBufferRead += uDataSaved;
      }
      else
      {  /// DDDDWxxxxxxxRDD
         kal_uint32 used_1, used_2, write_count;
         used_1 = uDSPBufferSize - uDSPBufferRead;
         FS_Write( fs_handle, bDSPBuffer+uDSPBufferRead, used_1, &uDataSaved );
         ASSERT( used_1 == uDataSaved );
         used_2 = uDSPBufferWrite;
         FS_Write( fs_handle, bDSPBuffer, used_2, &uDataSaved );
         ASSERT( used_2 == uDataSaved );
         uDSPBufferRead = uDataSaved;
      }
   }
}
#endif

/* ------------------------------------------------------------------------------ */
/*  L1Audio Task                                                                  */
/* ------------------------------------------------------------------------------ */

extern unsigned short L1D_Audio_ChkDspInitDone();

#ifdef __DHL_MODULE__
void tst_dummy_callback(const kal_uint8* pData, kal_uint32 nLen){
}	
#endif

#if defined(__VOLTE_SUPPORT__)
kal_enhmutexid sp_handover_mutex; //just for 4G and 4G
kal_enhmutexid sp4g_dl_mutex;
kal_enhmutexid sp4g_ul_mutex;
uint32 g_retrieved_events;
#endif

void L1Audio_Task(unsigned argc, void *argv)
{
   uint32 retrieved_events;
   uint32 I;
   kal_uint16 initaud_id;

#ifdef __DHL_MODULE__
   tst_vc_register_channel(TVCI_VM_LOGGING, tst_dummy_callback);
#endif


#if defined(__VOLTE_SUPPORT__)
   sp_handover_mutex = kal_create_enh_mutex( "SP_HANDOVER_ENH_MUTEX" );
   sp4g_dl_mutex = kal_create_enh_mutex( "SP4G_DL_MUTEX" );
   sp4g_ul_mutex = kal_create_enh_mutex( "SP4G_UL_MUTEX" );
#endif
   l1audio.aud_events = kal_create_event_group("L1Audio");
   l1audio.hisr = kal_init_hisr(L1AUDIO_HISR);

   GET_SLEEP_HANDLE();
   
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ ) && defined(MTK_SLEEP_ENABLE) && !defined(__AUDIO_POWERON_RESET_DSP__) )
   l1audio.md2g_pdn_handle = L1D_MD2G_PWD_GetHandle();
   l1audio.l1sm_handle = L1SM_IntGetHandle();
#endif

#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
   {
   extern kal_enhmutexid sp_mutex;
   sp_mutex = kal_create_enh_mutex( "SP_MUTEX" );
   }  
#endif   

#if defined(MT6595)
	l1audio.isD2MIntAvalibaleUnderSleep = ((INT_SW_SecVersion()) > SW_SEC_0);
#else
	l1audio.isD2MIntAvalibaleUnderSleep = false;
#endif

   l1audio.sleppModeLocker        = 0;
   l1audio.dspUser  = 0;
   l1audio.dsp_slow_idle_counter = 0;
   l1audio.event_flag   = 0;
   l1audio.id_flag      = 0;
   l1audio.media_flag   = 0;
   l1audio.sema = kal_create_sem( "Aud_Sema", 1 );  

   l1audio.hisrMagicFlag = 0;
   for( I = 0; I < MAX_HISR_HANDLER; I++ )
      l1audio.hisrMagicNo[I] = 0;

	// wait for DSP init done
	while( 0 == L1D_Audio_ChkDspInitDone()){
		kal_sleep_task(1);
	}
	
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   initaud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( initaud_id );
#endif   
   DSP_DynamicDownload_Init();

   AM_Init();
   AFE_Init();
#if defined(__AUDIO_POWERON_RESET_DSP__)
   {
      uint32 _savedMask;
      _savedMask = SaveAndSetIRQMask();
      AFE_Init_status(KAL_TRUE);
      AFE_RegisterBackup();
      RestoreIRQMask(_savedMask);
   }
#endif

   L1SP_Init();

#if defined(__VOLTE_SUPPORT__)
#if defined(MT6276)
   ktInit( L1Audio_GetAudioID(), 0 );
   toneInit( L1Audio_GetAudioID(), 0 );
#else //#if defined(MT6276)
   for( I = 0; I < TOTAL_TONE_NUM; I++ )
   {
      ktInit( L1Audio_GetAudioID(), I );
      toneInit( L1Audio_GetAudioID(), I );
   }
#endif //#if defined(MT6276)
#endif //#if defined(__VOLTE_SUPPORT__)

   // mediaInit( L1Audio_GetAudioID() );

//    toneLoopbackRecInit(); // remove legency file and function

#if defined(__SMART_PHONE_MODEM__)
   EXT_BGSND_init();
#endif
	
#ifdef __CTM_SUPPORT__
   l1ctm_init();
#endif

#if defined(__DATA_CARD_SPEECH__)
   SP_Strm_Init();
#endif
   memset( &(l1audio.debug_info), 0, sizeof(l1audio.debug_info) );

#ifdef ANALOG_AFE_PATH_EXIST
   AFE_TurnOnFIR( L1SP_SPEECH );
   AFE_TurnOnFIR( L1SP_VOICE );
#endif // ANALOG_AFE_PATH_EXIST

#if defined(__CVSD_CODEC_SUPPORT__) 
   BT_SCO_Init();
#endif

#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1Audio_ClearFlag( initaud_id );
   L1Audio_FreeAudioID( initaud_id );
#endif

#if defined(MT6595) && (MDAFE_DVT_CASE1 || MDAFE_DVT_CASE2 || MDAFE_DVT_CASE3 || APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K)
		kal_sleep_task(3);
		L1SP_Speech_On(1);
#endif
#if defined(MT6752) && (MDAFE_DVT_CASE1 || MDAFE_DVT_CASE2 || MDAFE_DVT_CASE3 || APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K)
        kal_prompt_trace(MOD_L1SP, "DVT speechOn");
		kal_sleep_task(3);
		L1SP_Speech_On(0);
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
      // if( (l1audio.sleppModeLocker == 0))
      //   SLEEP_UNLOCK();
   }
}

uint32 L1Audio_GetEventGroup( void )
{
   uint32 retrieved_events;
   kal_retrieve_eg_events( l1audio.aud_events, 0xFFFF, KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND );
   return retrieved_events;
}

void L1Audio_ExeEventHandler( uint32 event )
{
   ASSERT_REBOOT( event < MAX_AUDIO_FUNCTIONS );
   l1audio.evHandler[event]( l1audio.evData[event] );
}

void L1Audio_ResetDevice(void)
{
   AFE_Init();
}
/* ------------------------------------------------------------------------------ */

static char *_get_next_arg(char **ppstring)
{
   char *pstring = *ppstring, *pstring_t;
   kal_uint8 ch;

   if( *pstring=='\0' )
      return NULL;

   while(1)
   { // find start
      ch = *pstring;
      if( ch!=' ' && ch!='\t' )
         break;
      pstring++;
   }

   pstring_t = pstring;

   while(1)
   {
      ch = *pstring;
      if( ch=='\0' )
         break;
      else if( ch==' ' || ch=='\t' )
      {
         *pstring = '\0';
         pstring++;
         break;
      }
      pstring++;
   }

   *ppstring = (char *)pstring;

   return pstring_t;
}

static void dispatcher(char **ppstring, int (*entry_main)(int argc, char **argv))
{
   int argc = 0;
   char *argv[16];

   while(1)
   {
      char *args = _get_next_arg( ppstring );

      if( args==NULL )
      {
         entry_main( argc, argv );
         break;
      }
      else if( strcmp( args, "|" )==0 )
      {
         argv[argc] = NULL;
         entry_main( argc, argv );
         argc = 0;
      }
      else
         argv[argc++] = args;
   }
}

void l1audio_console(kal_uint8 index, kal_char *string)
{
   int (*entry_main)(int argc, char **argv);
   char *pstring = (char *)string;

   entry_main = NULL;
   switch(index)
   {
      case 99: /* VoRTP unit test */
      {
         break;
      }
      default:
         break;
   }
   if( entry_main!=NULL )
      dispatcher(&pstring, entry_main);
}


void l1audio_console_handler(kal_char *string)
{
   //(void)string; //just for integrating MCU TONE
   int ii=atoi(string);
   kal_prompt_trace(MOD_L1SP, "l1audio_console_handler %d", ii);

#if defined(__VOLTE_SUPPORT__)
   (void)string;
   if(strcmp(string, "DTXON")==0) {
      void SP4G_SetDTX(kal_bool on);
      kal_prompt_trace(MOD_L1SP, "l1audio_console_handler DTX ON");
      SP4G_SetDTX(KAL_TRUE);
   }
   else if(strcmp(string, "DTXOFF")==0) {
      void SP4G_SetDTX(kal_bool on);
      kal_prompt_trace(MOD_L1SP, "l1audio_console_handler DTX OFF");
      SP4G_SetDTX(KAL_FALSE);
   }
   else
#endif //#if defined(__VOLTE_SUPPORT__)
   {
      void SpeechDVT(int ii);
      SpeechDVT(ii);
   }

/*
   (void)string;
	if(strcmp(string, "speechOn")==0){
		L1SP_Speech_On(0);
	} else if(strcmp(string, "speechOff")==0) {
		L1SP_Speech_Off();
	} else if(strcmp(string, "get2gRF")==0) {
		uint16 L1D_GetRF(uint16 mode);
	   uint16 RF_2G = L1D_GetRF(MML1_RF_2G);
	   L1Audio_Msg_L1D_GetRF(RF_2G);
	}
#if defined(__ENABLE_SPEECH_DVT__)
        extern void Speech_DVT_Test_Main(kal_char *string);
        Speech_DVT_Test_Main(string);
#endif // defined(__ENABLE_SPEECH_DVT__)*/
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
      audio_alloc_aud_mem           = (fp_audio_alloc_aud_mem)  func->alloc_mem;
      audio_alloc_aud_mem_cacheable = (fp_audio_alloc_aud_mem)  func->alloc_mem_cacheable;
      audio_free_aud_mem            = (fp_audio_free_aud_mem)   func->free_mem;
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
#ifndef MED_NOT_PRESENT
   send_proc_call_req2(MOD_L1SP, func, func_arg1, func_arg2);
#endif
}

void L1Audio_InProcCall(in_proc_call_type func, kal_uint32 func_arg1, void* func_arg2)
{
//#ifndef MED_NOT_PRESENT
   send_proc_call_req(MOD_L1SP, func, func_arg1, func_arg2);
//#endif
}

void aud_set_volume_internal(kal_uint8 audio_mode){
   audio_set_path_vol(audio_mode);
}

kal_uint8 aud_get_mode_internal(void){
  return audio_get_active_mode();
}

/*
kal_bool aud_get_meta_file(kal_wchar *filename, aud_info_struct *aud_info_p){
  return audio_get_meta_file(filename, aud_info_p);
}

kal_bool aud_get_meta_array(kal_char *ptr, kal_uint32 size, aud_info_struct *aud_info_p){
  return audio_get_meta_array(ptr, size, aud_info_p);
}
*/
//[BT] A2DP, phase out
/*
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
*/

#if defined(__SMART_PHONE_MODEM__)
#include "task_config.h"
#include "ccci.h"

extern void SpcIO_A2M_hisr(CCCI_BUFF_T *bufp);
extern void SpcIO_M2A_hisr(CCCI_BUFF_T *bufp);
extern void SpcIO_Init(void);
#endif

/***********************************************************/
/* Export to MED/AUDL task                                 */
/***********************************************************/

kal_bool SP_Drv_Init_Bootup(void)
{
#if defined (__SMART_PHONE_MODEM__)
   kal_int32 ret;
   ret = ccci_owner_init(CCCI_PCM_CHANNEL_ACK, kal_get_task_by_moduleID(MOD_MED), SpcIO_A2M_hisr);
   if (ret != CCCI_SUCCESS) {
       ASSERT(0);
   }
   ret = ccci_owner_init(CCCI_PCM_CHANNEL, kal_get_task_by_moduleID(MOD_MED), SpcIO_M2A_hisr);
   if (ret != CCCI_SUCCESS) {
       ASSERT(0);
   }
#endif

   return KAL_TRUE;
}

kal_bool SP_Drv_Init_Task(void)
{
#if defined (__SMART_PHONE_MODEM__)
   SpcIO_Init();
#endif
   
   return KAL_TRUE;
}
