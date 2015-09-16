/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 * afe_6595.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  MT6595 chip dependent afe driver
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
 *
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#if defined(MT6595)

#include "afe.h"

void AFE_SetSamplingRate( uint32 freq )
{
   *AFE_AMCU_CON1 |= 0x0C00;  // turn off HW FIR

#if defined(EXT_DAC_SUPPORT) 
   switch (freq) {
      case 0x00: 
      case 0x20:
      case 0x40:     
         afe.ext_dac_freq = 32000;     
         break;
      case 0x11:
      case 0x21:  
      case 0x41:
         afe.ext_dac_freq = 44100;
         break;
      case 0x12: 
      case 0x22:  
      case 0x42: 
         afe.ext_dac_freq = 48000;
         break;
   }
#endif    
   
   afe.audio_fs = freq;
}

//=============================================================================================
//                 External Amplifier
//=============================================================================================
/*****************************************************************************
* FUNCTION
*  AFE_TurnOnExtAmplifier
*  AFE_TurnOffExtAmplifier
* DESCRIPTION
*   These two function are to turn on/off external amplifier individually
*****************************************************************************/
void AFE_TurnOnExtAmplifier( void )
{
   afe.gpio_lock = KAL_TRUE;
   AFE_SwitchExtAmplifier( true );
   afe.ext_op_on = KAL_TRUE;
}

void AFE_TurnOffExtAmplifier( void )
{
   AFE_SwitchExtAmplifier( false );
   afe.gpio_lock = KAL_FALSE;
   afe.ext_op_on = KAL_FALSE;
}

//=============================================================================================
//                  AFE Loop back
//=============================================================================================

/// Caller: Task
void AFE_TurnOnLoopback( void )
{   
   *AFE_PCM_CON0 |= 0x20000000;
   afe.loopback = KAL_TRUE;
   kal_brief_trace(TRACE_STATE, AFE_SWITCH_LOOPBACK, '+');
}

void AFE_TurnOffLoopback( void )
{	 
   *AFE_PCM_CON0 &= ~0x20000000;
   afe.loopback = KAL_FALSE;

   kal_brief_trace(TRACE_STATE, AFE_SWITCH_LOOPBACK, '-');
}

//=============================================================================================
//                  Audio/8K Clock Related
//=============================================================================================
void AFE_TurnOn8K( void )
{
#ifdef L1D_TEST
 extern  int  PollLoopbackMode(void);
   if( PollLoopbackMode() !=1 )
#endif
   {

#if defined(MT6595) && (APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K) && (APAUDSYS_DVT_RF2)
      *MD2GSYS_AFE_CK_SEL = 0x0; // clock source switch test
#endif
      
      // turn on clock gate
      *MD2GSYS_CG_CLR2 =  PDN_CON2_VAFE;

      // 1. config MDAFE_MCU_CON1, DSP DL/UL data rate 
      if( afe.voice8kMode == 0 )//narrow band, 4k mode;
         *AFE_MCU_CON1 = 0x0;
		else if ( afe.voice8kMode == 2 )
			*AFE_MCU_CON1 = 0x88;
      else // default is wide bank, 8k mode, 16k sampling rate
         *AFE_MCU_CON1 = 0x44;
         // *AFE_MCU_CON1 = 0x88;
         
      // 2. config MDAFE_VMCU_CON1
      *AFE_VMCU_CON1 = 0; // Fix value, may set it on init
      
      // 3. config MDAFE_PCM_CON0
      if( afe.voice8kMode == 0 )//narrow band, 4k mode;
      	*AFE_PCM_CON0 = 0x8400000A; // not turn on pcm 
      else if ( afe.voice8kMode == 2 )
			*AFE_PCM_CON0 = 0x8400800A;
      else // default is wide bank, 8k mode, 16k sampling rate
      	*AFE_PCM_CON0 = 0x8400400A;
      	
      // 4. config MDAFE_IRQ_CON1 for irq setting
      *AFE_IRQ_CON1 = 0x05; // Fix value, may set it on init
      
      // 5. config MDAFE_CONN0 for inteconnection
#if defined(MT6595) && (APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K) && (APAUDSYS_DVT_RF2) 
		*AFE_CONN0 = 0x54321010; // [REMIND] loopback!! 
#else
      *AFE_CONN0 = 0x54321076; // Fix value, may set it on init 
#endif      
      
      // 6. config MDAFE_VMCU_CON0 = 0x00000001 to open Voice IRQ
      *AFE_VMCU_CON = 0x1; 
      
      // 7. config MDAFE_MCU_CON0 = 0x00000001 to open whole AFE
      *AFE_MCU_CON0 = 0x1;
      
      // 8. config MDAFE_PCM_CON0 = MDAFE_PCM_CON0 | 0x00000001 open PCM interface
		*AFE_PCM_CON0 |= 0x1; 
      
      // AFE_SetRefVol(KAL_TRUE);

      L1Audio_Msg_AFE_Switch( L1AUDIO_Str_onoff(1), AFE_Switch_Name(0) );
   }
}


void AFE_TurnOff8K( void )
{

   // i.	close PCM interface
   *AFE_PCM_CON0 &= ~0x1;

	AFE_DELAY(125);
	
   // ii.close 8k IRQ
   *AFE_VMCU_CON = 0x0;
   
   // iii.	close whole AFE
   *AFE_MCU_CON0  = 0;   

   *MD2GSYS_CG_SET2 = PDN_CON2_VAFE;
   
	L1Audio_Msg_AFE_Switch( L1AUDIO_Str_onoff(0), AFE_Switch_Name(0) );
}


/*
void AFE_TurnOnAudioClock( kal_uint8 clock )
{
   kal_uint16 SampleRate = 0;
   // afe.aClk_off_request = KAL_FALSE;   
   // AFE_SetRefVol(KAL_TRUE);

   switch (clock) {
      case ASP_FS_8K:
         SampleRate = 0;     
         break;
      case ASP_FS_11K:
         SampleRate = 1;     
         break;               
      case ASP_FS_12K: 
         SampleRate = 2;     
         break;         
      case ASP_FS_16K:
         SampleRate = 4;     
         break;            
      case ASP_FS_22K:
         SampleRate = 5;     
         break;        
      case ASP_FS_24K:  
         SampleRate = 6;     
         break;             
      case ASP_FS_32K:     
         SampleRate = 8;     
         break;        
      case ASP_FS_44K:
         SampleRate = 9;     
         break;                       
      case ASP_FS_48K: 
         SampleRate = 10;     
         break;
   }
   //SampleRate = (clock&3) + 8; //8: 32kHz, 9: 44kHz, 10: 48kHz
   *AFE_AMCU_CON1 = (SampleRate<<6);

	// TODO:
   // *MD2GSYS_CG_CLR2 = PDN_CON2_AAFE;
   *AFE_AMCU_CON0 |= 0x0001;
}

void AFE_TurnOffAudioClock( void )
{
   afe.aClk_off_request = KAL_TRUE;    
}


// For hardware equalizer
// The coefficient can be written into register only when the power is on
void AFE_TurnOnAudioPower( void )
{
   *MD2GSYS_CG_CLR2 = PDN_CON2_AAFE;
}

void AFE_TurnOffAudioPower( void )
{
   *MD2GSYS_CG_SET2 = PDN_CON2_AAFE;
}
*/

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
#endif

//=============================================================================================
//                  Output Volume Releated Functions
//=============================================================================================
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
#if defined(EXT_DAC_SUPPORT) 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
      #if defined(TV_OUT_SUPPORT)   
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
      #if defined(TV_OUT_SUPPORT)            
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
/* under construction !*/
/* under construction !*/
#if defined(EXT_DAC_SUPPORT)  
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
         #if defined(TV_OUT_SUPPORT)
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
#else


#endif //ANALOG_AFE_PATH_EXIST
//=============================================================================================
//                  Section: [AFE Feature] ABB Registers Backup/Store (for 65nm projects)
//=============================================================================================

void _AfeRegisterBackupByChip(void)
{
#if __RELOAD_HW_COEFF__
   
	 afe.regbak.VMCU_CON  = *AFE_VMCU_CON;        
	 afe.regbak.VMCU_CON1 = *AFE_VMCU_CON1;       
	 afe.regbak.PCM_CON0  = *AFE_PCM_CON0;        
	 afe.regbak.AMCU_CON0 = *AFE_AMCU_CON0;       
	 afe.regbak.AMCU_CON1 = *AFE_AMCU_CON1;       
	 afe.regbak.IRQ_CON1  = *AFE_IRQ_CON1;        
	 afe.regbak.MCU_CON0  = *AFE_MCU_CON0;        
	 afe.regbak.MCU_CON1  = *AFE_MCU_CON1;        
	 afe.regbak.CONN0     = *AFE_CONN0;           
   
#endif
}

void _AfeRegisterStoreByChip(void)
{
#if __RELOAD_HW_COEFF__
   
	 *AFE_VMCU_CON  =  afe.regbak.VMCU_CON;        
	 *AFE_VMCU_CON1 =  afe.regbak.VMCU_CON1;       
	 *AFE_PCM_CON0  =  afe.regbak.PCM_CON0;        
	 *AFE_AMCU_CON0 =  afe.regbak.AMCU_CON0;       
	 *AFE_AMCU_CON1 =  afe.regbak.AMCU_CON1;       
	 *AFE_IRQ_CON1  =  afe.regbak.IRQ_CON1;        
	 *AFE_MCU_CON0  =  afe.regbak.MCU_CON0;        
	 *AFE_MCU_CON1  =  afe.regbak.MCU_CON1;        
	 *AFE_CONN0     =  afe.regbak.CONN0;           
    
#endif
}

//=============================================================================================
//                  VAPDN Related
//=============================================================================================
/*
void AFE_SetRefVol(kal_bool fgEnable)
{
   // Both AFE_Event_Handler & AFE Manager will call this function, 
   // so need to add critical section protection
}
*/
//=============================================================================================
//                  Chip Specific AFE Init
//=============================================================================================
void AFE_Chip_Init( void )
{  
	// [Tips] The following sherif is used under SW sidetone only. 
	// It will initial value is zero when DSP chip init, so we don't need to clean it. 
   //*DP_SIDETONE_VOL  = 0;

   *AFE_VMCU_CON      = 0;
	*AFE_VMCU_CON1		 = 0;

   *AFE_AMCU_CON0     = 0;
   *AFE_AMCU_CON1     = 0;

	*AFE_MCU_CON0      = 0;
	*AFE_MCU_CON1      = 0x44; // default using 16k mode
	*AFE_IRQ_CON1      = 0x05; // default using DSP voice IRQ
	*AFE_PCM_CON0      = 0x8400400A; // default using 16k mode, 16 pin
	*AFE_CONN0         = 0x54321076;
	
   AFE_Initialize();         // Set AFE_VAC_CON0::VCALI (chip dependent) and AFE_VMCU_CON1
   // AFE_SetRefVol(KAL_TRUE);
   
   // *DSP_AGC_CTRL    = 0xB82A;
   
}

/* ========================================================================= */
/*   AFE Chip Event Handler                                                  */
/*   This function runs under the context of L1Audio Task                    */
/* ========================================================================= */
void AFE_Chip_Event_Handler( void *data )
{
	kal_int16 v_lowest, a_lowest;

#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
	//Be careful.Before Locking SleepMode, to access DSP sherrif tasks much time. So access DSP must be after SetFlag
	// because the event will happen whenever AP call related function 
	L1Audio_SetFlag( afe.aud_id );
#endif 

	SearchPathWorkingFlag(&v_lowest, &a_lowest);
	_digitOnly_update_digital_gain(v_lowest, a_lowest);

	// mic digital gain related
	/* no hw mute exit, so remove it
	if(afe.mic_mute){ 
		// AM_DSP_SetSpeechUplinkSwAgcGain(); AM_DSP_SetSpeechUplinkDigitalGain(0);
	}else {
	*/
	if(AM_IsBluetoothOn()) { // for the case of bluetooth use
		AM_DSP_SetSpeechUplinkSwAgcGain(0); // make agc gain as 0 under bt mode
	} else {
		AM_DSP_SetSpeechUplinkSwAgcGain(afe.digitOnly_mic_volume);
	}
	/*
	}
	*/

#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
	L1Audio_ClearFlag( afe.aud_id );
#endif

}

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        AFE Manager 
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
/* ========================================================================= */
/*   AFE Manager                                                             */
/*   This function runs under the context of L1 ISR                          */
/* ========================================================================= */
void AFE_Manager( void )
{   
   DelayCmd dc;
   if( afe.ext_op_delay != 0 ) {
      if( afe.ext_op_delay > 0 ) {
         if( --afe.ext_op_delay == 0 ) {
            AFE_SwitchExtAmplifier( true );
            afe.ext_op_on = KAL_TRUE;
         }
      }
      else { /* afe.ext_op_delay < 0 */
         if( ++afe.ext_op_delay == 0 ) {
            AFE_SwitchExtAmplifier( false );
            afe.ext_op_on = KAL_FALSE;
         }
      }
   }
   
   if( !RB_EMPTY( afe.regq ) ) {
      RB_GET( afe.regq, dc );
      *dc.addr = dc.val;
   }

   if( afe.refresh )
   {
      afe.refresh = KAL_FALSE;
      L1Audio_LSetEvent(afe.aud_id, NULL);
   }
   /*
   if(afe.v8k_off_request)
   {
      *MD2GSYS_CG_SET2 = PDN_CON2_VAFE;
      *AFE_VMCU_CON  &= ~0x0001;
      afe.v8k_off_request = KAL_FALSE;
		L1Audio_Msg_AFE_Switch( L1AUDIO_Str_onoff(0), AFE_Switch_Name(0) );
   }

   if(afe.aClk_off_request)
   {
      *MD2GSYS_CG_SET2 = PDN_CON2_AAFE;
      *AFE_AMCU_CON0  &= ~0x0001;
      afe.aClk_off_request = KAL_FALSE;
   }
	 */
}

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        AFE Feature or Chip Sepcific Functions
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

/**
	@return: 0 == narrow band, 4k mode; 1 == wide band, 8k mode; 2 == extra wide band, 16k mode;
*/
kal_uint8 AFE_GetVoice8KMode(void)
{
	return afe.voice8kMode;
}


/**
	@mode: 0 == narrow band, 4k mode; 1 == wide band, 8k mode; 2 == extra wide band, 16k mode;
*/
void AFE_SetVoice8KMode(kal_uint8 mode)
{
   afe.voice8kMode = mode;
}

#endif //#if defined(MT6593)
