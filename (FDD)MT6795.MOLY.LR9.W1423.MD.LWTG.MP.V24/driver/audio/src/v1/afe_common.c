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
 * afe2.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Audio Front End
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.20  $
 * $Modtime:   Aug 15 2005 14:00:06  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1audio/afe2.c-arc  $
 *
 * removed!
 * removed!
 * Merge K2 Speech DVT code.
 *
 * removed!
 * removed!
 * DVT test cases check in
 *
 * removed!
 * removed!
 * add 32k setting
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * remove unused code
 *
 * removed!
 * removed!
 * move register backup by chip
 *
 * removed!
 * removed!
 * remove unused afe code
 *
 * removed!
 * removed!
 * super dongle merge back
 * 1. pcm start volume
 * 2. fix src coefficient by DSP's request
 * 3. fix bgSnd timer name
 * 4. WB parameter position adding (80) [Rimind to ask 90]
 * 5. fix build warning
 * 6. when bt cordless mode fors
 * 7. add daca interface
 * 8. fix spc log typo
 *
 * removed!
 * removed!
 * DRC 2.0 gain range modification (final solution)
 *
 * removed!
 * removed!
 * DRC 2.0 bug fix (reference gain scope is incorrect)
 *
 * removed!
 * removed!
 * DRC 2.0 modification
 *
 * removed!
 * removed!
 * Remove DSP DL -1db due to SDM gain change (from MT6572 and after)
 *
 * removed!
 * removed!
 * Gain is not apply immediatly
 *
 * removed!
 * removed!
 * Gain is apply too late
 *
 * removed!
 * removed!
 * Set Mode Modification
 *
 * removed!
 * removed!
 * 1. Sidetone update
 * 
 * 2. digital gain setting (AGC, DL volume)
 * 
 * 3. FIX AFE setting to privent too many noise
 * 
 * 4. Fix PCM MSB, LSB mapping mismatch
 * 5. Turn on enhancement
 * 6. Add Acroustic loopback code
 * 
 * removed!
 * removed!
 * MT6589 phone call setting merge back
 * 
 * removed!
 * removed!
 * add compile option for analog AFE
 * 
 * removed!
 * removed!
 * Modify for MD2G wakeup by Audio.
 * 
 * removed!
 * removed!
 * Phase in PCMNWAY, param AM manager with 2 parameter, and recording.
 *
 * 06 08 2012 kh.hung
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 *    Rev 1.0   Dec 31 2004 11:29:16   BM
 * Initial revision.
 *
 *******************************************************************************/

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        INCLUDE FILES
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
#include "afe.h"

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        Global Variables
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
AFE_STRUCT_T afe;
const unsigned short default_bt_pcm_out_enh_ref_vol = 0x1000; // 0db

//=============================================================================================
//                  AFE Unit Test
//=============================================================================================
#if UNIT_TEST_AFE2
kal_uint16 digital_gain_ut[129];
float digital_gain_ut_diff[128];
kal_uint16 get_digital_gain(kal_int8 index)
{
   AFE_SetOutputVolume(0, 0, index);
   return afe.aud[0].digital_gain;
}
void afe2_unit_test( void )
{
   kal_int8 digital_gain_index;

   for(digital_gain_index=-128; digital_gain_index<=0; digital_gain_index++) {
      digital_gain_ut[digital_gain_index+128] = get_digital_gain(digital_gain_index);
   }

   /// python cmd: 20 * math.log10(0x8000/21.0) = 63.86dB
   ASSERT(digital_gain_ut[0] == 21);
   ASSERT(digital_gain_ut[128] == 0x8000);

   for(digital_gain_index=-128; digital_gain_index<=-1; digital_gain_index++) {
      digital_gain_ut_diff[digital_gain_index+128] =
         digital_gain_ut[digital_gain_index+128+1] * 1.0F /
         digital_gain_ut[digital_gain_index+128];
      /// perfect value is math.pow(10.0, 0.5/20.0) = 1.05925
      ASSERT(digital_gain_ut_diff[digital_gain_index+128] >= 1.035F);
      ASSERT(digital_gain_ut_diff[digital_gain_index+128] <= 1.084F);
   }

   /// shall assert here
   get_digital_gain(1);
}
#endif

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        AFE Internal Utility Functions
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

// static void _update_digital_gain(kal_int16 v_lowest, kal_int16 a_lowest);

/* ========================================================================= */
/*   AFE Event Handler                                                  */
/*   This function runs under the context of L1Audio Task                    */
/* ========================================================================= */
static void AFE_Event_Handler( void *data )
{
   ASSERT(!kal_if_hisr());
   
   AFE_Chip_Event_Handler(data);
}
void AFE_Init_status(kal_bool flag)
{
   afe.afe_init = flag;
}

//=============================================================================================
//                  AFE Init
//=============================================================================================
/*****************************************************************************
* FUNCTION
*  AFE_Init
* DESCRIPTION
*   This function is to initialize the AFE module.
*
* PARAMETERS
*  None
* RETURNS
*  None
* CALLER
*  L1Audio_Task, L1Audio_ResetDevice
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void AFE_Init( void )
{
   static kal_bool afe_initialized = KAL_FALSE;
   int I;

   RB_INIT( afe.regq );

   afe.refresh          = KAL_FALSE;
#ifdef ANALOG_AFE_PATH_EXIST		
   afe.sp_flag          = 0;
   afe.fir_flag         = 0;		
   afe.mic_flag         = 0;
#else
	afe.pathWork_flag        =0;
	afe.digitOnly_mic_volume = DG_DL_Speech; // 0db
#endif // ANALOG_AFE_PATH_EXIST 
	afe.digitOnly_sphEnhRef_digital_gain = DG_DL_Speech; // 0db   
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   
   afe.ext_op_on        = KAL_FALSE;
   afe.ext_op_delay     = 0;
   // afe.mute             = KAL_FALSE;
   afe.loopback         = KAL_FALSE;
   afe.bt_flag          = KAL_FALSE;
   afe.audio_fs         = 0;  //32K

#if defined(EXT_DAC_SUPPORT)
   afe.ext_dac_i2s_on   = KAL_FALSE;
   afe.ext_dac_add_st   = KAL_FALSE;
   afe.ext_dac_aud_func = -1;
   afe.ext_dac_level_gain  = 0x8000;
   EXT_DAC_Init();   
#endif       

   for( I = 0; I < L1SP_MAX_AUDIO; I++ ) {
      afe.aud[I].out_dev      = 0;
      afe.aud[I].volume       = 0x77;
#if 0 // def ANALOG_AFE_PATH_EXIST		
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else 
		afe.aud[I].digitOnly_digital_gain = 4096; // 0db. 
#endif // ANALOG_AFE_PATH_EXIST
      afe.aud[I].mute         = KAL_FALSE;

   }
	
   afe.afe_state                 = AFE_STATE_OFF;
   afe.toneLoopbackRec           = KAL_FALSE;

   if (KAL_FALSE == afe_initialized) {
      afe.aud_id = L1Audio_GetAudioID();
      L1Audio_SetEventHandler( afe.aud_id, AFE_Event_Handler );
      afe_initialized = KAL_TRUE;      
   }
#if UNIT_TEST_AFE2
   {
      afe2_unit_test();
   }
#endif

#if (defined(MT6595) || defined(MT6752)) && (MDAFE_DVT_CASE1 || APAUDSYS_DVT_32K)
	afe.voice8kMode = 2;
#elif (defined(MT6595) || defined(MT6752)) && (MDAFE_DVT_CASE3 || APAUDSYS_DVT_8K) // 8k
	afe.voice8kMode = 0;
#else
	afe.voice8kMode = 1; // default value
#endif
   AFE_Chip_Init();
}

kal_uint8 AFE_GetAfeSate(void)
{
   return afe.afe_state;
}

#if 0 //def ANALOG_AFE_PATH_EXIST		
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

void SearchPathWorkingFlag(kal_int16 * v_lowest,kal_int16 * a_lowest)
{
	kal_int16 I;

	*v_lowest = -1; 
	*a_lowest = -1;

	/*
	if(afe.mute)
   {
      return;
   }   
   */

	for( I = L1SP_MAX_AUDIO; I >= 0; I-- ) {
		if(afe.pathWork_flag & (1<<I)){
			switch (I){
				case L1SP_KEYTONE:
				case L1SP_TONE:
				case L1SP_SPEECH:
		      case L1SP_SND_EFFECT:
		      case L1SP_VOICE:
				case L1SP_DAI:
		      case L1SP_LINEIN:
				{
			
					*v_lowest = I;
					break;
		      }
				case L1SP_AUDIO:
				{
		      	*a_lowest = I;
					break;
				}
			}
		}
   }
}
#endif 

void AFE_SetRefresh( void )
{
   afe.refresh = KAL_TRUE;
}

void AFE_DELAY(uint16 delay)
{
   kal_uint32 curr_frc, latest_us;

   curr_frc = ust_get_current_time();//unit: micro second (us)
   do{
      latest_us = ust_get_current_time();;
   }while(delay > ust_get_duration(curr_frc, latest_us));
}

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       Chapter: Digital/Analog Gain Related
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  Section: [Gain] Digital Gain Convert
//=============================================================================================

#if 0 //def ANALOG_AFE_PATH_EXIST
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //defined(__BT_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
   #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
const kal_uint16 digitOnly_quater_dB_tableForSpeech[296] = 
{
	10289, 9997, 9713, 9438, /* 8  ~ 7.25 dB*/
	9170, 8910, 8657, 8411, /* 7   ~ 6.25 dB*/
	8173, 7941, 7715, 7497, /* 6   ~ 5.25 dB*/
	7284, 7077, 6876, 6681, /* 5   ~ 4.25 dB*/
	6492, 6308, 6129, 5955, /* 4   ~ 3.25 dB*/
	5786, 5622, 5462, 5307, /* 3   ~ 2.25 dB*/
	5120, 5010, 4868, 4730, /* 2   ~ 1.25 dB*/    // uplink begin (2 db == 5120 == 0x1400)
	4596, 4465, 4339, 4216, /* 1   ~ 0.25 dB*/
	4096, 3980, 3867, 3757, /* 0   ~ -0.75   dB*/ //  downlink begin (0 db == 4096 == 0x1000) ==> chip newer then MT6572
	3645, 3547, 3446, 3349, /* -1  ~ -1.75   dB*/ // downlink begin (-1db == 3645 == 0xE3D) ==> Old chip MT6280 & MT6589 
	3254, 3161, 3072, 2984, /* -2  ~ -2.75   dB*/
	2900, 2817, 2738, 2660, /* -3  ~ -3.75   dB*/
	2584, 2511, 2440, 2371, /* -4  ~ -4.75   dB*/
	2303, 2238, 2175, 2113, /* -5  ~ -5.75   dB*/
	2053, 1995, 1938, 1883, /* -6  ~ -6.75   dB*/
	1830, 1778, 1727, 1678, /* -7  ~ -7.75   dB*/
	1631, 1584, 1539, 1496, /* -8  ~ -8.75   dB*/
	1453, 1412, 1372, 1333, /* -9  ~ -9.75   dB*/
	1295, 1259, 1223, 1188, /* -10 ~ -10.75  dB*/
	1154, 1122, 1090, 1059, /* -11 ~ -11.75  dB*/
	1029, 1000, 971 , 944 , /* -12 ~ -12.75  dB*/
	917 , 891 , 866 , 841 , /* -13 ~ -13.75  dB*/
	817 , 794 , 772 , 750 , /* -14 ~ -14.75  dB*/
	728 , 708 , 688 , 668 , /* -15 ~ -15.75  dB*/
	649 , 631 , 613 , 595 , /* -16 ~ -16.75  dB*/
	579 , 562 , 546 , 531 , /* -17 ~ -17.75  dB*/
	516 , 501 , 487 , 473 , /* -18 ~ -18.75  dB*/
	460 , 447 , 434 , 422 , /* -19 ~ -19.75  dB*/
	410 , 398 , 387 , 376 , /* -20 ~ -20.75  dB*/
	365 , 355 , 345 , 335 , /* -21 ~ -21.75  dB*/
	325 , 316 , 307 , 298 , /* -22 ~ -22.75  dB*/
	290 , 282 , 274 , 266 , /* -23 ~ -23.75  dB*/
	258 , 251 , 244 , 237 , /* -24 ~ -24.75  dB*/
	230 , 224 , 217 , 211 , /* -25 ~ -25.75  dB*/
	205 , 199 , 194 , 188 , /* -26 ~ -26.75  dB*/
	183 , 178 , 173 , 168 , /* -27 ~ -27.75  dB*/
	163 , 158 , 154 , 150 , /* -28 ~ -28.75  dB*/
	145 , 141 , 137 , 133 , /* -29 ~ -29.75  dB*/
	130 , 126 , 122 , 119 , /* -30 ~ -30.75  dB*/
	115 , 112 , 109 , 106 , /* -31 ~ -31.75  dB*/
	103 , 100 , 97  , 94  , /* -32 ~ -32.75  dB*/
	92  , 89  , 87  , 84  , /* -33 ~ -33.75  dB*/
	82  , 79  , 77  , 75  , /* -34 ~ -34.75  dB*/
	73  , 71  , 69  , 67  , /* -35 ~ -35.75  dB*/
	65  , 63  , 61  , 60  , /* -36 ~ -36.75  dB*/
	58  , 56  , 55  , 53  , /* -37 ~ -37.75  dB*/
	52  , 50  , 49  , 47  , /* -38 ~ -38.75  dB*/
	46  , 45  , 43  , 42  , /* -39 ~ -39.75  dB*/
	41  , 40  , 39  , 38  , /* -40 ~ -40.75  dB*/
	37  , 35  , 34  , 33  , /* -41 ~ -41.75  dB*/
	33  , 32  , 31  , 30  , /* -42 ~ -42.75  dB*/
	29  , 28  , 27  , 27  , /* -43 ~ -43.75  dB*/
	26  , 25  , 24  , 24  , /* -44 ~ -44.75  dB*/
	23  , 22  , 22  , 21  , /* -45 ~ -45.75  dB*/
	21  , 20  , 19  , 19  , /* -46 ~ -46.75  dB*/
	18  , 18  , 17  , 17  , /* -47 ~ -47.75  dB*/
	16  , 16  , 15  , 15  , /* -48 ~ -48.75  dB*/
	15  , 14  , 14  , 13  , /* -49 ~ -49.75  dB*/
	13  , 13  , 12  , 12  , /* -50 ~ -50.75  dB*/
	12  , 11  , 11  , 11  , /* -51 ~ -51.75  dB*/
	10  , 10  , 10  , 9   , /* -52 ~ -52.75  dB*/
	9   , 9   , 9   , 8   , /* -53 ~ -53.75  dB*/
	8   , 8   , 8   , 7   , /* -54 ~ -54.75  dB*/
	7   , 7   , 7   , 7   , /* -55 ~ -55.75  dB*/
	6   , 6   , 6   , 6   , /* -56 ~ -56.75  dB*/
	6   , 6   , 5   , 5   , /* -57 ~ -57.75  dB*/
	5   , 5   , 5   , 5   , /* -58 ~ -58.75  dB*/
	5   , 4   , 4   , 4   , /* -59 ~ -59.75  dB*/
	4   , 4   , 4   , 4   , /* -60 ~ -60.75  dB*/
	4   , 4   , 3   , 3   , /* -61 ~ -61.75  dB*/
	3   , 3   , 3   , 3   , /* -62 ~ -62.75  dB*/
	3   , 3   , 3   , 3   , /* -63 ~ -63.75  dB*/
	3   , 3   , 2   , 2   , /* -64 ~ -64.75  dB*/
	2   , 2   , 2   , 2   , /* -65 ~ -65.75  dB*/
};

/**
	Only use when MODEM do not have analog device, ie. ANALOG_AFE_PATH_EXIST is NOT defined

	@digitalGainQDb: input digital gain value in dB. 4 step/1db. 
	  for example: digitalGainDb=1  --> 0.25 dB; digitalGainDb=FFF4(-12) --> -3dB
	@isDL: true for downlink, false for uplink
	@return: value set to dsp
	  
*/
kal_uint16 _digitOnly_convert_digital_gain_forSpeech(kal_int16 digitalGainQDb, kal_bool isDl)
{
	kal_int16 idx = (-digitalGainQDb);

	if(isDl){
#if defined(MT6589)		
		idx += 36; // begin from -1 db 
#else // data card chip should begin from 0
		idx += 32; // begin from 0 db 
#endif
	} else {
		// for UL. useless now
	}
	
	return digitOnly_quater_dB_tableForSpeech[idx];
	
}

void _digitOnly_update_digital_gain(kal_int16 v_lowest, kal_int16 a_lowest)
{
#if defined(__BT_SUPPORT__) // DSP_BT_SUPPORT
   if(AM_IsBluetoothOn()) // for the case of bluetooth use
   {
   	// don't care audio function 

		// speech function
      if( afe.aud[L1SP_VOICE].mute == KAL_TRUE || afe.aud[L1SP_SPEECH].mute == KAL_TRUE ) {
         AM_DSP_SetSpeechDigitalGain(0); //*DP_VOL_OUT_PCM = 0;
         AM_DSP_SetSpeechEnhRefDigitalGain(default_bt_pcm_out_enh_ref_vol); // truly 0db in DSP
      }
      else
      {
			AM_DSP_SetSpeechDigitalGain(default_bt_pcm_out_vol);
         AM_DSP_SetSpeechEnhRefDigitalGain(default_bt_pcm_out_enh_ref_vol); // truly 0db in DSP
      }

		// don't care line-in function, which is phase out
      return;
   }
#endif //defined(__BT_SUPPORT__) // DSP_BT_SUPPORT

   if (v_lowest >= 0) {
      if (a_lowest >= 0) // Voice Amp ON && Audio Amp ON
      {
         ASSERT(0); // should not have audio function
         // AM_DSP_SetAudioDigitalGain(afe.aud[a_lowest].digitOnly_digital_gain );
      } 
      else  //Voice Amp ON && Audio Amp OFF
      {
      	if(KAL_TRUE == afe.aud[v_lowest].mute){
				AM_DSP_SetSpeechDigitalGain(0);
				AM_DSP_SetSpeechEnhRefDigitalGain(DG_DL_Speech); // default is 0db from ap side
      	} else {
	         AM_DSP_SetSpeechDigitalGain(afe.aud[v_lowest].digitOnly_digital_gain );
				AM_DSP_SetSpeechEnhRefDigitalGain(afe.digitOnly_sphEnhRef_digital_gain);
      	}
      }
   } 
   else if (a_lowest >= 0)   // Voice Amp OFF && Audio Amp ON
   {
      ASSERT(0); // should not have audio function

		// AM_DSP_SetAudioDigitalGain(afe.aud[a_lowest].digitOnly_digital_gain );
   } 
   else  // Voice Amp OFF && Audio Amp OFF; Restore the values to default value (for Bluetooth)
   {
       AM_DSP_SetSpeechDigitalGain(DG_DL_Speech); //*DP_VOL_OUT_PCM = DG_DL_Speech;
       AM_DSP_SetSpeechEnhRefDigitalGain(DG_DL_Speech); // default is 0db from ap side
       AM_DSP_SetAudioDigitalGain(DG_DAF); // *DP_DigiGain_Setting = DG_DAF;
   }
	
   if (!kal_if_lisr())
		kal_trace(TRACE_STATE, AFE_DIGI_GAIN, AM_DSP_GetSpeechDigitalGain(), AM_DSP_GetAudioDigitalGain(), AM_GetSpeechEnhRefDigitalGain());
}

#endif // #ifdef ANALOG_AFE_PATH_EXIST

//=============================================================================================
//                  Section: [Gain] Digital Gain Setting  (Set/Get/Mute)
//=============================================================================================
#if 0 // def ANALOG_AFE_PATH_EXIST
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__BT_SUPPORT__) // FIXME: DSP_BT_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if defined(EXT_DAC_SUPPORT)
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
   #if defined(__BT_SUPPORT__) // FIXME: DSP_BT_SUPPORT
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
#else
/**
	@aud_func: 
	@digitalGainQdB: input digital gain value in quarter dB, i.e. 4 step/1db. 
	  for example: digitalGainDb=1  --> 0.25 dB; digitalGainDb=FFF4(-12) --> -3dB
*/
void AFE_DigitalOnly_SetDigitalGain(kal_uint8 aud_func, kal_int16 digitalGainQdB)
{	
   kal_trace(TRACE_STATE, AFE_SET_GIDI_GAIN, aud_func, digitalGainQdB);
	ASSERT((digitalGainQdB)<=0 && (digitalGainQdB>=-256)); // value frome -64 db to 0 db
	
	if ((L1SP_AUDIO != aud_func)
		&& (L1SP_DAI != aud_func)
		&&(L1SP_LINEIN != aud_func)) {
		afe.aud[aud_func].digitOnly_digital_gain = _digitOnly_convert_digital_gain_forSpeech(digitalGainQdB, true); 
	} else {
		// do nothing		
	}
	
	L1Audio_SetEvent(afe.aud_id, NULL);
}

#endif

/**

	@digitalGainQdB: input digital gain value in quarter dB, i.e. 4 step/1db. 
	  for example: digitalGainDb=1  --> 0.25 dB; digitalGainDb=FFF4(-12) --> -3dB
*/
void AFE_DigitalOnly_SetEnhRefDigitalGain(kal_int16 refDigitalGainQdB)
{
	kal_trace(TRACE_STATE, AFE_SET_SPH_REF_GIDI_GAIN, refDigitalGainQdB);
	ASSERT((refDigitalGainQdB)<=0 && (refDigitalGainQdB>=-28)); // value from -7 db to 0 db
	
	afe.digitOnly_sphEnhRef_digital_gain = _digitOnly_convert_digital_gain_forSpeech(refDigitalGainQdB, true);
	
	L1Audio_SetEvent(afe.aud_id, NULL);
}

//=============================================================================================
//                  Section: [Gain] Analog Gain Related
//=============================================================================================
#if 0
/* under construction !*/
/* under construction !*/
#if __AFE_ANALOG_GAIN_UPPER_BOUND__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

/****************************************************************************
[REMOVE]
* FUNCTION
*  AFE_GetNVRAMDigitalGainSupport
* DESCRIPTION
*  This function return if support digital setting from NVRAM data
*
* PARAMETERS
*  None
* RETURNS
*  KAL_TRUE   - Support digital gain ==> when __NVRAM_AFE_DIGITAL_GAIN_SUPPORT__ defined, but the option is removed! 
*  KAL_FALSE  - Not support digital gain
* CALLER
*  Task
*****************************************************************************/
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
#endif 

#if 0 //def ANALOG_AFE_PATH_EXIST
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // ANALOG_AFE_PATH_EXIST

//=============================================================================================
//                  Section: [Gain] __GAIN_TABLE_SUPPORT__ Specific Functions ==> REMOVE
//=============================================================================================


//=============================================================================================
//                  Section: [Gain] Device Gain (Mute/Output Volume)
//=============================================================================================
#if 0 //def ANALOG_AFE_PATH_EXIST
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

void AFE_DigitalOnly_SetMicrophoneVolume( kal_uint8 mic_volume )
{
	kal_brief_trace(TRACE_STATE, AFE_SET_MIC_VOLUME, mic_volume);
	ASSERT((mic_volume)>=0 && (mic_volume<=120)); // range is 0~ 30 dB
	
	// if((mic_volume)<=0 && (mic_volume>=-256)){
	afe.digitOnly_mic_volume = (mic_volume>>2); // 4 is 1 db 
	//} else {

	//}
	
	// AFE_SetRefresh(); 
	L1Audio_SetEvent(afe.aud_id, NULL);
}
#endif 

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
#endif

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
#endif

void AFE_MuteSpeaker( kal_uint8 aud_func, kal_bool mute )
{
   afe.aud[aud_func].mute = mute;
   kal_trace(TRACE_STATE, AFE_MUTE_SPEAKER, aud_func, mute);
   AFE_SetRefresh();
}

kal_bool AFE_IsSpeakerMuted( kal_uint8 aud_func)
{
   return afe.aud[aud_func].mute;
}

#ifdef ANALOG_AFE_PATH_EXIST

void  AFE_GetOutputVolume( kal_uint8 aud_func, kal_uint8 *volume1, kal_int8 *digital_gain_index )
{
   *volume1 = afe.aud[aud_func].volume;
   *digital_gain_index = afe.aud[aud_func].digital_gain_index;
}
#else 
void AFE_DigitalOnly_GetOutputVolume(kal_uint8 aud_func, kal_uint8 *vol)
{
	*vol = afe.aud[aud_func].digitOnly_digital_gain;
}

#endif // ANALOG_AFE_PATH_EXIST

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       Chapter: Path/Device Control
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  Section: [Path] Speaker Functions
//=============================================================================================

/*****************************************************************************
* FUNCTION
*  AFE_TurnSpeakerOn
* DESCRIPTION
*   This function is to turn on the speaker of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#ifdef ANALOG_AFE_PATH_EXIST
void AFE_TurnOnSpeaker( kal_uint8 aud_func )
{
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();    /* Disable interrupt to prevent race condition */  
   afe.sp_flag |= (1<<aud_func);
   RestoreIRQMask(savedMask);
   AFE_SetRefresh();
   L1Audio_Msg_AFE_TurnSpk( L1AUDIO_Str_onoff(1), L1AUDIO_Func_Name(aud_func) );
}
#endif
/*****************************************************************************
* FUNCTION
*  AFE_TurnSpeakerOff
* DESCRIPTION
*   This function is to turn off the speaker of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task, L1Audio_HISR(via AM_AudioPlaybackOff)
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#ifdef ANALOG_AFE_PATH_EXIST
void AFE_TurnOffSpeaker( kal_uint8 aud_func )
{
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();    /* Disable interrupt to prevent race condition */
   afe.sp_flag &= ~(1<<aud_func);
   RestoreIRQMask(savedMask);
   AFE_SetRefresh();
   L1Audio_Msg_AFE_TurnSpk( L1AUDIO_Str_onoff(0), L1AUDIO_Func_Name(aud_func) );
}



#endif

//=============================================================================================
//                  Section: [Path] Microphone Functions
//=============================================================================================
/*****************************************************************************
* FUNCTION
*  AFE_TurnMicrophoneOn
* DESCRIPTION
*   This function is to turn on the microphone of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#ifdef ANALOG_AFE_PATH_EXIST
void AFE_TurnOnMicrophone( kal_uint8 aud_func )
{
   kal_uint32 savedMask;
   savedMask = SaveAndSetIRQMask();    // Disable interrupt to prevent race condition
   afe.mic_flag |= (1<<aud_func);
   RestoreIRQMask(savedMask);
#if defined(__DUAL_MIC_SUPPORT__)
   *DP2_DUALMIC_CTRL |= 1;
#endif

   AFE_SetRefresh();

   ///Currently, when video recording, video LISR will call Media_Record.
   L1Audio_Msg_AFE_TurnMIC( L1AUDIO_Str_onoff(1), L1AUDIO_Func_Name(aud_func) );
}
#endif 

/*****************************************************************************
* FUNCTION
*  AFE_TurnOffMicrophone
* DESCRIPTION
*   This function is to turn off the microphone of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#ifdef ANALOG_AFE_PATH_EXIST

void AFE_TurnOffMicrophone( kal_uint8 aud_func )
{
   kal_uint32 savedMask;
   /// Disable interrupt to prevent race condition
   savedMask = SaveAndSetIRQMask();
   afe.mic_flag &= ~(1<<aud_func);
   RestoreIRQMask(savedMask);
   
   AFE_SetRefresh();

   ///Currently, when video recording, video LISR will call Media_Record.
   L1Audio_Msg_AFE_TurnMIC( L1AUDIO_Str_onoff(0), L1AUDIO_Func_Name(aud_func) );
}

kal_bool AFE_IsMicrophoneOn( kal_uint8 aud_func )
{
   return (kal_bool)((afe.mic_flag & (1<<aud_func)) != 0);
}
#endif 

//=============================================================================================
//                  Section: [Path] AFE Path Use Functions (when no Analog path existing)
//=============================================================================================
/*****************************************************************************
* FUNCTION
*   AFE_TurnOnPathWork
* DESCRIPTION
*   This function is to turn on the working path of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#ifndef ANALOG_AFE_PATH_EXIST // suing when analog path is NOT exiting

void AFE_TurnOnPathWork( kal_uint8 aud_func )
{
	kal_uint32 savedMask;
	savedMask = SaveAndSetIRQMask(); 	// Disable interrupt to prevent race condition
	afe.pathWork_flag|= (1<<aud_func);
	RestoreIRQMask(savedMask);

	// AFE_SetRefresh();
	L1Audio_SetEvent(afe.aud_id, NULL);

	///Currently, when video recording, video LISR will call Media_Record.
	L1Audio_Msg_AFE_TurnPath( L1AUDIO_Str_onoff(1), L1AUDIO_Func_Name(aud_func) );
}
#endif


/*****************************************************************************
* FUNCTION
*  AFE_TurnOffPathWork
* DESCRIPTION
*   This function is to turn off the working path of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#ifndef ANALOG_AFE_PATH_EXIST // suing when analog path is NOT exiting
void AFE_TurnOffPathWork( kal_uint8 aud_func )
{
   kal_uint32 savedMask;
   /// Disable interrupt to prevent race condition
   savedMask = SaveAndSetIRQMask();
   afe.pathWork_flag &= ~(1<<aud_func);
   RestoreIRQMask(savedMask);
   
   // AFE_SetRefresh();
	L1Audio_SetEvent(afe.aud_id, NULL);
	
   ///Currently, when video recording, video LISR will call Media_Record.
   L1Audio_Msg_AFE_TurnPath( L1AUDIO_Str_onoff(0), L1AUDIO_Func_Name(aud_func) );
}
#endif


//=============================================================================================
//                  Section: [Path] BT Functions
//=============================================================================================
void AFE_SetBtFlag(kal_bool on)
{
	afe.bt_flag = on;
}

//void AFE_TurnOnPcm( kal_uint16 param )
//{
//   *AFE_VDB_CON    |= (0x0010 | param );
//   *AFE_VMCU_CON1  &= ~0x0001;//vbtdai data is sent to dai module
//}
//void AFE_TurnOffPcm( kal_uint16 param )
//{
//   *AFE_VDB_CON    &= ~0x0018;
//   *AFE_VMCU_CON1  |= 0x0001;//vdl data is sent to dai module
//}

//=============================================================================================
//                  Section: [Path] DAI Related Functions
//=============================================================================================
void AFE_TurnOnDAI( void )
{
	 ASSERT(0);//it shouldn't be used
   //*AFE_VDB_CON |= 0x0020;
   //L1Audio_Msg_AFE_Switch( L1AUDIO_Str_onoff(1), AFE_Switch_Name(1) );
}

void AFE_TurnOffDAI( void )
{
	 ASSERT(0);//it shouldn't be used
   //*AFE_VDB_CON &= ~0x0020;
   //L1Audio_Msg_AFE_Switch( L1AUDIO_Str_onoff(0), AFE_Switch_Name(1) );
}

/*
//=============================================================================================
//                  Section: [Path] External DAC Interface Related Functions
//=============================================================================================
/// External DAC Interface / fmt: 1 = I2S, 0 = EIAJ / cycle: 32 or 16
void AFE_TurnOnEDI( kal_uint16 dir, kal_uint16 fmt, kal_uint16 cycle )
{   
   kal_bool slave_mode = (kal_bool)Media_I2S_SLAVE_MODE;
   kal_uint16 en2 = 0;
   ASSERT( fmt < 2 );
   ASSERT( cycle == 16 || cycle == 32 );
   if(dir)
   {
      // DSP workaround for I2S HW issue, audio clock 8K->16K
      *AFE_VAM_SET &= ~0x07;
      *AFE_VAM_SET |= 0x02;
      *AFE_VDB_CON &= ~0x0040;
   }
   else
   {
      *AFE_VDB_CON |= 0x0040;
   }
   *AFE_EDI_CON = ( (en2<<15) | (dir<<8) | (slave_mode<<7) | ((cycle-1)<<2) | (fmt<<1) | 1);
   kal_trace( TRACE_STATE, AFE_SET_EDI, dir, cycle, fmt );
}

void AFE_TurnOffEDI( void )
{
   *AFE_EDI_CON &= ~0x8001;
   *AFE_VDB_CON &= ~0x0040;
   // DSP workaround for I2S HW issue, audio clock 16K->8K
   *AFE_VAM_SET &= ~0x07;
   *AFE_VAM_SET |= 0x05;
}


kal_bool AFE_IsEDIOn( void )
{
   if (*AFE_VDB_CON & 0x0040)
      return KAL_TRUE;
   else
      return KAL_FALSE;
}
*/

//=============================================================================================
//                  Section: [Path] MicBias Functions (for accessory detection use)  ==> REMOVE
//=============================================================================================
#if 0 // def ANALOG_AFE_PATH_EXIST
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #ifdef ANALOG_AFE_PATH_EXIST
//=============================================================================================
//                  Section: [Path] Input/Output Source/Device Related
//=============================================================================================
/*****************************************************************************
* FUNCTION
*  AFE_SetOutputDevice
* DESCRIPTION
*   This function is to set the output device of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
*  device - be L1SP_SPEAKER1, L1SP_SPEAKER2, or L1SP_LOUDSPEAKER
* RETURNS
*  None
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#ifdef ANALOG_AFE_PATH_EXIST
void AFE_SetOutputDevice( kal_uint8 aud_func, kal_uint8 device )
{
#if defined(EXT_DAC_SUPPORT)   
   if(device & (L1SP_EXT_DAC_BUF0 | L1SP_EXT_DAC_BUF1))
   {
      if(!(device & L1SP_BUFFER_ST))
      {
         switch((SND_SRC_MAP>>aud_func*2)&3) 
         { 
            case SRC_AUDIO_DAC:
               afe.ext_dac_add_st = KAL_TRUE;
            case SRC_VOICE_DAC:   
            case SRC_EXT_INPUT:
               device |= L1SP_BUFFER_ST;
               break;
         }
      }
      else
         afe.ext_dac_add_st = KAL_FALSE;
   }
#endif

   afe.aud[aud_func].out_dev = device;   
   AFE_SetRefresh();
   if (!kal_if_hisr() && !kal_if_lisr())
      kal_brief_trace(TRACE_STATE, AFE_SET_OUTPUT_DEVICE, aud_func, device);
}
#endif

kal_uint8 AFE_GetOutputDevice( kal_uint8 aud_func )
{
   return afe.aud[aud_func].out_dev;
}

#if 0
/* under construction !*/
/* under construction !*/
#if __AFE_DIGITAL_MIC_SUPPORT__
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
#endif

#ifdef ANALOG_AFE_PATH_EXIST

kal_bool AFE_IsAudioLoudSpk( void )
{
   if(afe.aud[L1SP_AUDIO].out_dev & L1SP_BUFFER_EXT)
      return KAL_TRUE;
   else 
      return KAL_FALSE;
}

kal_bool AFE_IsAudioEarphone( void )
{
   if(afe.aud[L1SP_AUDIO].out_dev & L1SP_BUFFER_ST) //earphone
      return KAL_TRUE;
   else 
      return KAL_FALSE;
}
#endif // ANALOG_AFE_PATH_EXIST

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       Chapter: Audio/Speech Rleated Features
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  Section: [AUD/SPH] FIR Functions
//=============================================================================================
/*****************************************************************************
* FUNCTION
*  AFE_TurnOnFIR
* DESCRIPTION
*   This function is to turn on the FIR filter of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#ifdef ANALOG_AFE_PATH_EXIST
void AFE_TurnOnFIR( kal_uint8 aud_func )
{
   kal_uint32 savedMask;
   /// Disable interrupt to prevent race condition
   savedMask = SaveAndSetIRQMask();
   afe.fir_flag |= (1<<aud_func);
   RestoreIRQMask(savedMask);

   AFE_SetRefresh();
   ASSERT(!kal_if_hisr());
   kal_brief_trace(TRACE_STATE, AFE_SWITCH_FIR, '+', aud_func);
}
#endif // ANALOG_AFE_PATH_EXIST

/*****************************************************************************
* FUNCTION
*  AFE_TurnFirOff
* DESCRIPTION
*   This function is to turn off the FIR filter of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
* RETURNS
*  None
* CALLER
*  Task
* GLOBALS AFFECTED
*  None
*****************************************************************************/
#ifdef ANALOG_AFE_PATH_EXIST
void AFE_TurnOffFIR( kal_uint8 aud_func )
{
   kal_uint32 savedMask;
   /// Disable interrupt to prevent race condition
   savedMask = SaveAndSetIRQMask();
   afe.fir_flag &= ~(1<<aud_func);
   RestoreIRQMask(savedMask);

   AFE_SetRefresh();
   ASSERT(!kal_if_hisr());
   kal_brief_trace(TRACE_STATE, AFE_SWITCH_FIR, '-', aud_func);
}

kal_bool AFE_IsFIROn( kal_uint8 aud_func )
{
   return (kal_bool)((afe.fir_flag & (1<<aud_func)) != 0);
}
#endif // ANALOG_AFE_PATH_EXIST
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
#endif

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       Chapter: AFE Related Features
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  Section: [AFE Feature] ABB Registers Backup/Store (for 65nm projects)
//=============================================================================================
void AFE_RegisterBackup(void)
{
#if __RELOAD_HW_COEFF__
   L1Audio_Msg_AFE_RegBackup( L1AUDIO_Str_Bool(1) );
   
   _AfeRegisterBackupByChip();
#endif
}

void AFE_RegisterStore(void)
{
#if __RELOAD_HW_COEFF__
   L1Audio_Msg_AFE_RegBackup( L1AUDIO_Str_Bool(0) );
   
   _AfeRegisterStoreByChip();
#endif
}

//=============================================================================================
//                  Section: [AFE Feature] AFE Loop back
//=============================================================================================
void AFE_EnableToneLoopBackFlag( kal_bool param )
{
   if(param)
      afe.toneLoopbackRec = KAL_TRUE;
   else
      afe.toneLoopbackRec = KAL_FALSE;
}

kal_bool AFE_GetLoopbackStatus( void )
{
   return afe.loopback;
}

