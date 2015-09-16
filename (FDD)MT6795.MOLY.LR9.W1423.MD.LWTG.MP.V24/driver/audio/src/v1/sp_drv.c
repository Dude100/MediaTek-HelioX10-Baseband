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
 * l1sp.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   L1SP Interface 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "string.h"
#include "reg_base.h"
#include "custom_equipment.h" /* custom_cfg_audio_ec_range() */
#include "device.h" /* MAX_VOL_LEVEL,  in ps\l4\include */
#include "audcoeff_default.h"

#include "audio_def.h"
#include "l1audio.h"
#include "l1audio_trace.h"
#include "l1sp_trc.h"
#include "l1audio_sph_trc.h"

#include "media.h"
#include "sp_enhance.h"
#include "afe.h"
#include "am.h"
#include "vm.h"
#include "sal_def.h"
#include "sal_exp.h"

#include "mml1_rf_global.h"
#include "sp_drv.h"

#include "l4_ps_api.h" 
#include "ps_public_utility.h"

#if defined(__DATA_CARD_SPEECH__) || defined(__BT_SCO_CODEC_SUPPORT__)
#include "sp_daca.h"
#endif

#ifdef __TWOMICNR_SUPPORT__
#include "two_mic_NR_custom_if.h"
#endif

#if !defined(__SMART_PHONE_MODEM__)
#include "apAudSysConfig.h"
#else
#include "sidetone.h"
#endif

#if defined(__CVSD_CODEC_SUPPORT__) 
#include "bt_sco_drv.h"
#endif

#if defined(__VOLTE_SUPPORT__) 
#include "l1audio.h"
#endif

#define __BT_SUPPORT__

// for modem project, DONGLE product use
#if defined(MT6280)
//	#define DACA_SPE_ENABLE_INTERNAL
#endif

#include "audio_msgid.h"
#include "drv_sap.h"
/* ------------------------------------------------------------------------------ */
/*  Speech Interface                                                              */
/* ------------------------------------------------------------------------------ */

static struct {
   uint16   aud_id;
#if defined(__SMART_PHONE_MODEM__)   
   uint16   aud_id_network_status;
#endif   
   uint16   aud_id_codec_status; 
   // uint8    sph_mode; // move to sp_enhance
   // uint8    sph_level; // phase out
   uint16   sph_c_para[NUM_COMMON_PARAS];
   uint16   sph_m_para[NUM_MODE_PARAS];
   uint16   sph_v_para[NUM_VOL_PARAS]; // useless, should fine time to remove it  
	uint16   sph_m_paraWb[NUM_MODE_PARAS];
/* #if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
   int16    sph_dmnr_para[NUM_DMNR_PARAM];
#if defined(__AMRWB_LINK_SUPPORT__)
   int16    sph_wb_dmnr_para[NUM_WB_DMNR_PARAM];
#endif
	int16    sph_lspk_dmnr_para[NUM_DMNR_PARAM];
#if defined(__AMRWB_LINK_SUPPORT__)
   int16    sph_lspk_wb_dmnr_para[NUM_WB_DMNR_PARAM];
#endif
#endif     */

   uint8    mic_volume; //  [analog+digital gain]value corrently set to DSP&HW; when ANALOG_AFE_PATH_EXIST is NOT defined, this is 0

	// move to sp_enhance.c
   // uint16   spe_state; 
   // uint16   spe_app_mask;   //record the usage every application should have. Ex. phonecall should be turned on DMNR. please do not update the mask directly, please use function l1sp_updateSpeAppMask() to update
   // uint16   spe_usr_mask;   //record the usage user choose. Size is NUM_OF_SPH_FLAG. Please use function l1sp_updateSpeUsrMaskWithWholeValue() to update
   // uint16   spe_usr_sub_mask; // record the usage of enhancement sub feature. Sync with Sal_Enh_Dynamic_t definition.  Ex. phonecall should be turned on DMNR, but users can decide whether turn on or not.please do not update the mask directly, please use function l1sp_updateUsrSubMask() to update 

	// bool     spe_flag;   
   uint16   isULMute; // flag to keep the DSP UL MUTE states
   bool     isDLMute; // flag to keep the DSP DL MUTE states
   
   uint32   forcedUnmuteController;
   bool     isUlEnhResultMute;
	bool     isUlSourceMute;
   bool     codec_mute; 
   L1SP_L4C_Event_Mode   codec_mute_mode;
   bool     tch_state; // true: TCH on; false: TCH off
   uint8    state; // recording the network is 2G or 3G      


//#if defined(__BT_SUPPORT__)
   bool     bt_on; // include DSP BT path setting and AFE path switch
//#endif
#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
   bool     interRAT;
#endif

	// bool     isEnableNotchFilter; 
	// bool     is2In1Spk; // the variable only meaning for under isEnableNotchFilter==true. Ture for is 2-in-1 speaker; False for 3-in-1 speaker
	// bool     isMagiConOn; 
	
	void (*bgsOnHandler)(void); 
   void (*bgsOffHandler)(void); 
#if defined(__DATA_CARD_SPEECH__)
   void (*strmOnHandler)(void *); 
   void (*strmOffHandler)(void *);
   void (*strmHdl)(kal_uint32 event, void *param);
#endif      
   

   // uint16 sph_allVolumePara[3][7][4];
   // uint16 sph_selectedOutFirIndex;

#if defined(__ECALL_SUPPORT__)
   void (*pcm4wayOnHandler)(void *); 
   void (*pcm4wayOffHandler)(void *);
#endif
} l1sp;
kal_enhmutexid sp_mutex;
// static kal_bool lineon_flag = KAL_FALSE;  // line in--> phase out


// Line in related. Phase out
//extern void AFE_SetGainFastRamp(kal_bool enable);

#if defined(__BT_SUPPORT__)
bool L1SP_IsBluetoothOn( void )
{
	uint8 mode = SPE_GetSpeechMode();
   return (mode==SPH_MODE_BT_CORDLESS || mode==SPH_MODE_BT_EARPHONE || 
      mode==SPH_MODE_BT_CARKIT || mode==SPH_MODE_LINEIN_VIA_BT_CORDLESS);
}
#endif

//void L1SP_UpdateSpeechPara( uint16 sph_m_para[NUM_MODE_PARAS] )
void SP_SetSpeechPara( uint16 sph_m_para[NUM_MODE_PARAS] )

{
   memcpy(l1sp.sph_m_para, sph_m_para, NUM_MODE_PARAS*sizeof(uint16));
}

#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
static kal_uint16 L1SP_GetAudID(void)/*Be careful.Before Locking SleepMode, to access DSP sherrif tasks much time. So access DSP must be after SetFlag*/
{
   kal_uint16 aud_id;
   aud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( aud_id );
   return aud_id;
}
static void L1SP_FreeAudID(kal_uint16 aud_id)
{
   L1Audio_ClearFlag( aud_id );
   L1Audio_FreeAudioID( aud_id );
}
#endif
/*******************************************************************/
/*   The new interface for DSP speech enhancement function / Bluetooth */
/*******************************************************************/
void sp_setBtOn(bool on)
{
	l1sp.bt_on = on;
}

bool sp_getIsBtOn(void)
{
	return l1sp.bt_on;
}



//#if __RELOAD_DSP_COEFF__
void L1SP_Reload_SPE_Para( void )
{
   SPE_LoadSpeechPara(l1sp.sph_c_para, l1sp.sph_m_para, NULL, l1sp.sph_m_paraWb); // l1sp.sph_v_para no one use it.
}
// #endif

/* Phase out, 
void L1SP_Init_PCMPlayback(uint8 sph_mode, bool bDigitalGain, uint16 digital_gain)
{
	 unsigned short Speech_Normal_Mode_Para[16] = DEFAULT_SPEECH_NORMAL_MODE_PARA;
   unsigned short Speech_Earphone_Mode_Para[16] = DEFAULT_SPEECH_EARPHONE_MODE_PARA;
   unsigned short Speech_Loudspeaker_Mode_Para[16] = DEFAULT_SPEECH_LOUDSPK_MODE_PARA;
	 
	 switch(sph_mode) {
	 case SPH_MODE_NORMAL:
	     if(bDigitalGain == true) {
	        Speech_Normal_Mode_Para[7] = digital_gain;
	     }
	 	  L1SP_SetSpeechMode(SPH_MODE_NORMAL, Speech_Normal_Mode_Para);
	 		break;
	 case SPH_MODE_EARPHONE:
	     if(bDigitalGain == true) {
	        Speech_Earphone_Mode_Para[7] = digital_gain;
	     }
	 	  L1SP_SetSpeechMode(SPH_MODE_EARPHONE, Speech_Earphone_Mode_Para);
	 	  break;
	 case SPH_MODE_LOUDSPK: 
	     if(bDigitalGain == true) {
	        Speech_Loudspeaker_Mode_Para[7] = digital_gain;
	     }
	 	  L1SP_SetSpeechMode(SPH_MODE_LOUDSPK, Speech_Loudspeaker_Mode_Para);
	 	  break;
	 default:
	 	  break;
	 } 
}

void L1SP_EnableStrmPcmSPE(void)
{
	 l1sp.pcmplayback_flag = true;
}

void L1SP_DisableStrmPcmSPE(void)
{
	 l1sp.pcmplayback_flag = false;
}

bool L1SP_CheckStrmPcmSPE(void)
{
	 return l1sp.pcmplayback_flag;
}

*/


#if defined(__VOLTE_SUPPORT__)
void ltecsr_set_jbm_para(uint16 c_para[NUM_COMMON_PARAS]);
#endif
void L1SP_LoadCommonSpeechPara( uint16 c_para[NUM_COMMON_PARAS] )
{
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif    
#if defined(__VOLTE_SUPPORT__)
   ltecsr_set_jbm_para(c_para);  //temporary solution for Field Trial
#endif
   memcpy(l1sp.sph_c_para, c_para, NUM_COMMON_PARAS*sizeof(uint16));
   SetSpeechEnhancement( true );
   
   // Some common parameters are used in non-speech function
   // Force to load common parameter
   SPE_LoadSpeechPara(l1sp.sph_c_para, NULL, NULL, NULL);
	
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1SP_FreeAudID(aud_id);
#endif
}

uint16 *Sp_GetCommonSpeechPara(void)
{
	return l1sp.sph_c_para;
}



uint16 *Sp_GetSpeechPara(void)
{
	return l1sp.sph_m_para;
}


void SP_SetWbSpeechPara( kal_uint16 m_para[NUM_MODE_PARAS] )
{
   memcpy( l1sp.sph_m_paraWb, m_para, NUM_MODE_PARAS*sizeof(uint16));
}

uint16 *Sp_GetWbSpeechPara(void)
{
	return l1sp.sph_m_paraWb;
}





kal_uint8 L1SP_GetSpeechMode( void )
{
    return SPE_GetSpeechMode();
}



/**
	@index: [Input] Identify which LID is going to provide
	@buffer: [Output] Buffer with the contain the result
	@len: [Input] Length of the output buffer
*/
void L1SP_GetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX index, void *buffer, uint16 len)
{
	switch(index)
	{
// #if WB_SPE_SUPPORT
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_INPUT_FIR:
	{
		ASSERT(len == (NUM_SPH_INPUT_FIR * NUM_WB_FIR_COEFFS));
		// memcpy(buffer, l1sp.sph_allWbInFirCoeff, sizeof(kal_uint16) * NUM_SPH_INPUT_FIR * NUM_WB_FIR_COEFFS);
		memcpy(buffer, SPE_getAllWbSpeechFirCoeff_InputOnly(), sizeof(kal_uint16) * NUM_SPH_INPUT_FIR * NUM_WB_FIR_COEFFS);
	}
		break;
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_OUTPUT_FIR:
	{
		ASSERT(len == (NUM_SPH_OUTPUT_FIR * NUM_WB_FIR_COEFFS));
		// memcpy(buffer, l1sp.sph_allWbOutFirCoeff, sizeof(kal_uint16) * NUM_SPH_OUTPUT_FIR * NUM_WB_FIR_COEFFS);
		memcpy(buffer, SPE_getAllWbSpeechFirCoeff_OutputOnly(), sizeof(kal_uint16) * NUM_SPH_OUTPUT_FIR * NUM_WB_FIR_COEFFS);
	}
		break;
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_MODE_PARAM:
	{
		ASSERT(len == (NUM_SPH_MODE * NUM_MODE_PARAS));
		// memcpy(buffer, l1sp.sph_allWbModePara,  sizeof(kal_uint16) * NUM_SPH_MODE * NUM_MODE_PARAS);
		memcpy(buffer, SPE_getAllWbSpeechModePara(),  sizeof(kal_uint16) * NUM_SPH_MODE * NUM_MODE_PARAS);
	}
		break;
// #endif // WB_SPE_SUPPORT
	default:
		ASSERT(0); 
	}
}
/**
	MED can put all nvram structure to AUD via this function. Audio/Speech driver will parsing the LID by itself. 
	
	@index: [Input] Identify which LID is used to parsing the buffer
	@buffer: [Input] Buffer with the contain from nvram
	@len: [Input] Length of the input buffer
*/
void L1SP_SetNvramInfoByIndex(L1SP_NVRAM_INFO_INDEX index, uint8* buffer, uint16 len)
{
	switch(index)
	{
	case L1SP_NVRAM_INFO_INDEX_UNDEF:		

		break;
	case L1SP_NVRAM_INFO_INDEX_PARAM:
	{
		int16 bufCur=0;

		//NB input FIR
		l1sp_setAllSpeechFirCoeff_InputOnly((int16 *)(buffer + bufCur), 6 * NUM_FIR_COEFFS);
        bufCur += (sizeof(kal_uint16)* 6 * NUM_FIR_COEFFS);

		//NB output FIR
		l1sp_setAllSpeechFirCoeff_OutputOnly((int16 *)(buffer + bufCur), 6 * NUM_FIR_COEFFS);
        bufCur += (sizeof(kal_uint16)* 6 * NUM_FIR_COEFFS);

		//selected FIR
		// kal_mem_cpy(&(l1sp.sph_selectedOutFirIndex), (buffer + bufCur), sizeof(kal_uint16));
		bufCur += sizeof(kal_uint16);
		
		//common
		{
		uint16 *data = (uint16 *)(buffer + bufCur);
		L1SP_LoadCommonSpeechPara(data); //common paramter will copy into l1sp.sph_c_para in this function
		bufCur += sizeof(kal_uint16) * 12; //hardcoding size
		}

		//mode parameter
		l1sp_setAllSpeechModePara((uint16 *)(buffer + bufCur), ( NUM_SPH_MODE * 16));
		bufCur += (sizeof(kal_uint16)* NUM_SPH_MODE * 16);

		// kal_mem_cpy(l1sp.sph_allVolumePara, (buffer + bufCur), (sizeof(kal_uint16)*3*7*4));
		// l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_VOLUME_PARAM;
		
		/*		
	    	kal_uint16 Media_Playback_Maximum_Swing;
    		kal_int16 Melody_FIR_Coeff_Tbl[25];
	    	kal_int16 audio_compensation_coeff[3][45];
		*/
	}
		break;
		
// #if WB_SPE_SUPPORT
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_INPUT_FIR:
	{
		// memcpy(l1sp.sph_allWbInFirCoeff, buffer, sizeof(kal_uint16) * NUM_SPH_INPUT_FIR * NUM_WB_FIR_COEFFS);		
		//l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_WB_IN_FIR; // (1<<4) bit [4]
		l1sp_setAllWbSpeechFirCoeff_InputOnly((kal_int16 *)buffer, NUM_SPH_INPUT_FIR * NUM_WB_FIR_COEFFS);
	}
		break;
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_OUTPUT_FIR:
	{
		// memcpy(l1sp.sph_allWbOutFirCoeff, buffer, sizeof(kal_uint16) * NUM_SPH_OUTPUT_FIR * NUM_WB_FIR_COEFFS);
		// l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_WB_OUT_FIR; // (1<<5) bit [5]
		l1sp_setAllWbSpeechFirCoeff_OutputOnly((kal_int16 *)buffer, NUM_SPH_OUTPUT_FIR * NUM_WB_FIR_COEFFS);
	}
		break;
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_MODE_PARAM:
	{
		// memcpy(l1sp.sph_allWbModePara, buffer, sizeof(kal_uint16) * NUM_SPH_MODE * NUM_MODE_PARAS);
		// 	l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_WB_MODE; // (1<<3) bit [3]
		l1sp_setAllWbSpeechModePara((kal_uint16 *)buffer, NUM_SPH_MODE * NUM_MODE_PARAS);
	}
		break;
// #endif

	default:
		ASSERT(0); 
	}
		
}



/**
	@device: device using in speech. pleae refer to 
		#define  L1SP_BUFFER_0        0x01    // NOTE: Don't use buffer definition directly
		#define  L1SP_BUFFER_1        0x02    //       Use speaker definition below
		#define  L1SP_BUFFER_ST       0x04
		#define  L1SP_BUFFER_EXT      0x08
		#define  L1SP_BUFFER_EXT_G    0x10
		#define  L1SP_STEREO2MONO     0x20     // Do not use this term for speaker definition
		#define  L1SP_BUFFER_ST_M     (L1SP_BUFFER_ST|L1SP_STEREO2MONO)
		#define  L1SP_EXT_DAC_BUF0    0x40 
		#define  L1SP_EXT_DAC_BUF1    0x80
	Phase-out function without using
*/
void L1SP_SetOutputDevice( uint8 device )
{
#if 0 //def ANALOG_AFE_PATH_EXIST
/* under construction !*/
/* under construction !*/
#endif // #ifdef ANALOG_AFE_PATH_EXIST
}

/**
	@return: device using in speech.
	Phase-out function without using
*/
uint8 L1SP_GetOutputDevice(void)
{
   return 0; //l1sp.output_dev;
}

/**
	Function is used when MODEM side has PGA gain & DSP digital gain control 
	i.e. ANALOG_AFE_PATH_EXIST is defined
	
	@volume1: MMI(EM) value from 0 to 256	
	@digital_gain_index:unit is 0.5 db. Value from 0 to -64db (seems option)
*/
void L1SP_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
#if 0 // ANALOG_AFE_PATH_EXIST  
/* under construction !*/
/* under construction !*/
#endif
}

#if 0 //defined(__GAIN_TABLE_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifndef ANALOG_AFE_PATH_EXIST  // ONLY exist digital path and hw
void l1sp_digiOnly_SetOutputVolume(int16 digitalGain)
{
	AFE_DigitalOnly_SetDigitalGain( L1SP_SPEECH, digitalGain );
}
#endif

void l1sp_digiOnly_SetEnhRefOutputVolume(int16 digitalRefGain)
{
	AFE_DigitalOnly_SetEnhRefDigitalGain(digitalRefGain);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/**
	this function is to replace L1SP_SetSpeechVolumeLevel()
	
	@level: [input] speech volume level for speech
	@v_paraIndex: [input] volume paramter (saving in nvram) index
*/
void L1SP_SetSpeechVolumeLevelByIndex(kal_uint8 level, kal_uint8 v_paraIndex)
{
//  phase out. 
// 	L1SP_SetSpeechVolumeLevel(level, l1sp.sph_allVolumePara[v_paraIndex][level]);
}

/**
	Phase out function without using
	@src: microhpone source for speech, plese refer to
		#define  L1SP_LNA_0           0
		#define  L1SP_LNA_1           1
		#define  L1SP_LNA_DIGITAL     2
		#define  L1SP_LNA_FMRR        3
	
*/
void L1SP_SetInputSource( uint8 src )
{
#if 0 //def ANALOG_AFE_PATH_EXIST    
/* under construction !*/
#endif
}

/**
	Phase out function without using
	@return: microphone source for speech
*/
uint8 L1SP_GetInputSource( void )
{
	return 0; // AFE_GetInputSource();
}



/**
	@mic_volume: MMI(EM) value. Including Analog & digital gain
*/
void L1SP_SetMicrophoneVolume( uint8 mic_volume )
{


}

#ifndef ANALOG_AFE_PATH_EXIST  // ONLY exist digital path and hw
void l1sp_digiOnly_SetMicrophoneVolume(int16 digitalGain)
{
	AFE_DigitalOnly_SetMicrophoneVolume(digitalGain);
}
#endif

#if 0 // defined(__GAIN_TABLE_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

uint8 L1SP_GetMicrophoneVolume( void )
{
   return 0;
}

/**
	Phase out function without using
	@sidetone: value from EM, which is 0~255. 
*/
void L1SP_SetSidetoneVolume( uint8 sidetone )
{
	// keep API header to avoid link error
}

/**
	Phase out function without using
	@return: value from EM, which is 0~255. 
*/
uint8 L1SP_GetSidetoneVolume( void )
{
	// keep API header to avoid link error, 
	return 0;
}
void SP_MuteUlEnhResult(bool mute)
{
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
			kal_uint16 aud_id = L1SP_GetAudID();
#endif  
	l1sp.isUlEnhResultMute = mute;
	AM_Mute_UL_EnhResult_Speech(mute);

#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1SP_FreeAudID(aud_id);
#endif 

}

void SP_MuteUlSource(bool mute)
{
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
			kal_uint16 aud_id = L1SP_GetAudID();
#endif  
	l1sp.isUlSourceMute = mute;
	AM_Mute_UL_Source_Speech(mute);

#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1SP_FreeAudID(aud_id);
#endif 

}


void SP_MuteController() // central controll, and placed between L1Audio_SetFlag and L1Audio_ClearFlag
{
   //return; returning at this point will be equal to disable this feature
   kal_trace(TRACE_INFO, L1SP_MUTE_CONTROL_STATUS, 2, l1sp.isULMute, l1sp.isDLMute, l1sp.codec_mute, l1sp.forcedUnmuteController);
   //DL 
   if(l1sp.forcedUnmuteController){
      AM_Mute_DL_8K_Speech(l1sp.isDLMute); 
      AM_Mute_DL_Speech_Traffic(false);  
   
      //UL
      AM_Mute_UL_Codec_Speech(0 != l1sp.isULMute);            
   }else{
      AM_Mute_DL_8K_Speech(l1sp.isDLMute);
      AM_Mute_DL_Speech_Traffic(l1sp.codec_mute);  
   
      //UL
      if(l1sp.codec_mute){
         AM_Mute_UL_Codec_Speech(true);         
      }else{      
         AM_Mute_UL_Codec_Speech(0 != l1sp.isULMute);     
      }
   }
}
void SP_MuteUlFromDiffPos(bool mute, SP_MIC_MUTE_POS pos)
{
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
		kal_uint16 aud_id = L1SP_GetAudID();
#endif   

	if(mute) 
		l1sp.isULMute |= pos; 
	else 
		l1sp.isULMute &= (~pos);

	// AM_Mute_UL_Codec_Speech( 0 != l1sp.isULMute );
	SP_MuteController();
	
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1SP_FreeAudID(aud_id);
#endif      	
}

/**
	For MED use ONLY!!! 
	other function please use void SP_MuteUlFromDiffPos(bool mute, SP_MIC_MUTE_POS pos)
*/
void L1SP_MuteMicrophone( bool mute )
{	
   
   //AFE_MuteMicrophone( mute ); // do not use AFE_MuteMicrophone for speech enhancement
   // AM_MuteULSpeech( mute );
   // l1sp.isULMute = mute;
   SP_MuteUlFromDiffPos(mute, SP_MIC_MUTE_POS_FROM_MED);
}

void L1SP_MuteSpeaker( bool mute )
{
#ifdef ANALOG_AFE_PATH_EXIST
   AFE_MuteSpeaker( L1SP_SPEECH, mute );
#else

#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif      
	//AM_MuteDLSpeech( mute );
   l1sp.isDLMute = mute;
   SP_MuteController();
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1SP_FreeAudID(aud_id);
#endif      
	
#endif
}

bool SP_IsSpeakerMute(void)
{
        return (l1sp.isDLMute!=0);
}

bool SP_IsMicMute(void)
{
	return (l1sp.isULMute!=0);
}

/**
	For MED use ONLY!!! 
	other function please use SP_IsMicMute() instead
*/
bool L1SP_IsMicrophoneMuted( void )
{
	return (l1sp.isULMute&SP_MIC_MUTE_POS_FROM_MED)!=0; 
   // return AM_IsULSpeechMuted();
}

//extern void CSR_SP3G_Callback( SP3G_Event event, void *data );
extern void vt_SP3G_Callback( kal_uint8 event, void *data );
extern void CSR_Codec_Ready(int rab_id);
extern void CSR_Codec_Close(int rab_id);

#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )

void L1SP_3G_Request(void)
{  
   if(l1sp.state ==  L1SP_STATE_3G_SPEECH_ON)
   {
      CSR_Codec_Ready(SP3G_Rab_Id());
      return;
   }
}
#endif

void L1SP_SetState(uint8 state)
{
#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
   if(( l1sp.state == L1SP_STATE_2G_SPEECH_ON && state == L1SP_STATE_3G_SPEECH_ON ) ||
      ( l1sp.state == L1SP_STATE_2G_SPEECH_ON && state == L1SP_STATE_4G_SPEECH_ON ) ||
      ( l1sp.state == L1SP_STATE_3G_SPEECH_ON && state == L1SP_STATE_2G_SPEECH_ON ) ||
      ( l1sp.state == L1SP_STATE_3G_SPEECH_ON && state == L1SP_STATE_4G_SPEECH_ON ) ||      
      ( l1sp.state == L1SP_STATE_4G_SPEECH_ON && state == L1SP_STATE_2G_SPEECH_ON ) ||
      ( l1sp.state == L1SP_STATE_4G_SPEECH_ON && state == L1SP_STATE_3G_SPEECH_ON ) )
      l1sp.interRAT = true;
#endif
   l1sp.state = state; 
   L1Audio_Msg_Speech_State(L1Audio_Speech_State(state));
}

uint8 L1SP_GetState( void )
{
   return l1sp.state; 
}


kal_bool L1SP_IsSpeechOn( void )
{
    return (AM_IsSpeechOn());
}

bool voc_flag = false;


void L1SP_Speech_On( uint8 RAT_Mode )
{
   kal_uint32 module_id = MOD_L1AUDIO_SPH_SRV;
   kal_uint32 voc_ptn = TVCI_CREATE_FILE;
   kal_uint32 *voc_ptn_ptr = &voc_ptn;
   
   kal_trace(TRACE_INFO, L1SP_PHONE_CALL, 0, RAT_Mode, -1);
	
   if( AM_IsSpeechOn() )
   {
#if defined(__CVSD_CODEC_SUPPORT__) 
      if((L1SP_GetSpeechMode() == SPH_MODE_BT_EARPHONE || L1SP_GetSpeechMode() == SPH_MODE_BT_CARKIT) && !BT_SCO_IS_SPEECH_ON())
      {
         kal_bool is_WB = AFE_GetVoice8KMode() == 1 ? KAL_TRUE : KAL_FALSE;
         BT_SCO_SPEECH_ON(is_WB);
      }
#endif
      return;
   }

#if (!defined(__SMART_PHONE_MODEM__)) && (!defined(__DATA_CARD_SPEECH__))
   ApAudSys_config();
#endif // defined(__SMART_PHONE_MODEM__)

   // for phone call used. 
   l1sp.aud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( l1sp.aud_id );     /* To lock sleep mode */

   SP_MuteController();
	//Check the mute status, this should always unmute. 
	ASSERT(SAL_Mute_Check(SAL_MUTE_DL_8K)==0);
	
#if !defined(__SMART_PHONE_MODEM__)
	// this two function is useless under smart phone, remove it to reduce process time
   TONE_StopAndWait();
   KT_StopAndWait();
#endif
   
   spe_updateSpeAppMask(0xff, true);

#ifdef ANALOG_AFE_PATH_EXIST
   AFE_SetDigitalGain(L1SP_SPEECH, 100);
#else

#endif

#if defined(__VOLTE_SUPPORT__)
	sp4g_speech_init( RAT_4G_MODE );
#endif

#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
#ifdef __VIDEO_CALL_SUPPORT__
   if( RAT_Mode == RAT_3G324M_MODE )
      sp3g_speech_init( RAT_3G324M_MODE );
   else
#endif
      //In Dual mode, allow 2G/3G capability at initialization stage  for InterRAT HO
      //if 3G324M, there is no InterRAT
      sp3g_speech_init( RAT_3G_MODE );
   L1Audio_Msg_SP(0);
     
	// choose the mode is 2g /3g
#if defined(__VOLTE_SUPPORT__)
   if( SP4G_Rab_State()){
      RAT_Mode = RAT_4G_MODE;
   }else 
#endif
   if( SP3G_Rab_State() && RAT_Mode != RAT_3G324M_MODE ){
      RAT_Mode = RAT_3G_MODE;
   }else if ( l1sp.tch_state ){
      RAT_Mode = RAT_2G_MODE;
   }else if(RAT_Mode != RAT_3G324M_MODE ){
   	  RAT_Mode = RAT_2G_MODE;
   }
   l1sp.interRAT = false;
   
   kal_trace(TRACE_INFO, L1SP_PHONE_CALL, 1, SP3G_Rab_State(), -1);
#endif
   
   kal_trace(TRACE_INFO, L1SP_PHONE_CALL, 2,  l1sp.tch_state, RAT_Mode);
   
   L1Audio_Msg_SP(1);
   AM_SpeechOn(RAT_Mode, 0);
   L1Audio_Msg_SP(2);



   switch(RAT_Mode)
   {
      case RAT_2G_MODE:
#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )      	
         kal_take_enh_mutex( sp_mutex );           
         if( SP3G_Rab_State()){
		         void SP3G_Rab_Est_sub();
		         SP3G_Rab_Est_sub();              	
         }else
#endif         	
         {
      	   AM_SetDSP2GReset(true);
           L1SP_SetState(L1SP_STATE_2G_SPEECH_ON);           	
         }
#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )      	         
         kal_give_enh_mutex(sp_mutex);
   #if !defined(__L1_STANDALONE__)
         #if !defined( __UMTS_TDD128_MODE__ )
         {
            if(query_ps_conf_test_mode()==PS_CONF_TEST_FTA)
               SP3G_SetDTX(false);
            else
               SP3G_SetDTX(true);
         }
         #endif  
   #endif             
#endif         	         
 
         break;
#if defined( __UMTS_RAT__ ) || defined( __UMTS_TDD128_MODE__ )
      case RAT_3G_MODE: 
         L1SP_SetState(L1SP_STATE_3G_SPEECH_ON);
         CSR_Codec_Ready(SP3G_Rab_Id());
#if !defined(__L1_STANDALONE__)
    #if !defined( __UMTS_TDD128_MODE__ )
         {
            if(query_ps_conf_test_mode()==PS_CONF_TEST_FTA)
               SP3G_SetDTX(false);
            else
               SP3G_SetDTX(true);
         }
    #endif
#endif         
         break;
#ifdef __VIDEO_CALL_SUPPORT__
      case RAT_3G324M_MODE: 
         L1SP_SetState(L1SP_STATE_3G324M_SPEECH_ON);
         vt_SP3G_Callback( (kal_uint8)SP3G_CODEC_READY, (void*)0 );
         break;
#endif
#endif
#if defined(__VOLTE_SUPPORT__)
      case RAT_4G_MODE: 
         L1SP_SetState(L1SP_STATE_4G_SPEECH_ON);
         PSR_SP4G_Callback(SP4G_CODEC_READY, (void*)SP4G_Rab_Id());              
         break;
#endif
      default: 
         ASSERT(false);
   }
   kal_trace(TRACE_INFO, L1SP_PHONE_CALL, 3, -1, -1);

#ifndef __L1_STANDALONE__ // avoid link error
   if(!tst_trace_check_ps_filter_off(TRACE_GROUP_VM, &module_id, 0x2))
   {
      tst_vc_response(TVCI_VM_LOGGING, (const kal_uint8*)voc_ptn_ptr, 4);
      VMREC_Start(NULL, 0, true);
      voc_flag = true;
   }
#endif

	//always unmute DSP uplink when speech on (This is to keep the mute definition)
	SP_MuteUlEnhResult(false); 

   SetSpeechEnhancement( true );

	//always unmute DSP uplink when speech on (This is to keep the mute definition)
	SP_MuteUlFromDiffPos(false, SP_MIC_MUTE_POS_FROM_ALL); 
	L1SP_MuteSpeaker(false);

	
// for phone call usage   
#if !DATA_CARD_DISABLE_INTERNAL
#if defined(__DATA_CARD_SPEECH__)
   if (l1sp.strmOnHandler != NULL)
      l1sp.strmOnHandler( NULL );
#endif
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

#if defined(__ECALL_SUPPORT__)
   if (l1sp.pcm4wayOnHandler != NULL)
      l1sp.pcm4wayOnHandler( (void *)0);
#endif

#if defined(__CVSD_CODEC_SUPPORT__) 
   if(L1SP_GetSpeechMode() == SPH_MODE_BT_EARPHONE || L1SP_GetSpeechMode() == SPH_MODE_BT_CARKIT)
   {
      kal_bool is_WB = AFE_GetVoice8KMode() == 1 ? KAL_TRUE : KAL_FALSE;
      BT_SCO_SPEECH_ON(is_WB);
   }
#endif
  L1Audio_Msg_SP(4);

}


#if defined(__DATA_CARD_SPEECH__)
void L1SP_Register_Strm_Handler(
   void (*onHandler)(void *hdl),
   void (*offHandler)(void *hdl),
   void (*hdl)(kal_uint32 event, void *param))
{
   l1sp.strmOnHandler  = onHandler;
   l1sp.strmOffHandler = offHandler;
   l1sp.strmHdl        = hdl;
   //For MOLY00004781, sometimes auto script hit that register handler later than speech on. In this case, we let daca run.
   if( AM_IsSpeechOn() ){
      l1sp.strmOnHandler(NULL);
   }
}

void L1SP_UnRegister_Strm_Handler( void )
{
   if(AM_IsDataCardOn() && (l1sp.strmOffHandler != NULL)){
      /* Normal     Case: PLUGIN(RegisterHandler)-->SpeechOn(OnHandler)-->SpeechOff(OffHandler) -->PLUGOUT(UnRegisterHandler)
         Unexpected Case: PLUGIN(RegisterHandler)-->SpeechOn(OnHandler)-->PLUGOUT(UnRegisterHandler), registerHandler again -->SpeechOff(OffHandler)     */      
      DACA_Stop(DACA_APP_TYPE_ACTIVE_UL_DL_WB);   
   }
   l1sp.strmOnHandler  = NULL;
   l1sp.strmOffHandler = NULL;
}
#endif

#if defined(__ECALL_SUPPORT__)
void L1SP_Register_Pcm4WayService(void (*onHandler)(void *), void (*offHandler)(void *))
{
   l1sp.pcm4wayOnHandler = onHandler; 
   l1sp.pcm4wayOffHandler = offHandler;
}

void L1SP_UnRegister_Pcm4Way_Service( void )
{
   l1sp.pcm4wayOnHandler = NULL; 
   l1sp.pcm4wayOffHandler = NULL;
}
#endif

void L1SP_Speech_Off( void )
{
   kal_uint32 voc_ptn = TVCI_CLOSE_FILE;
   kal_uint32 *voc_ptn_ptr = &voc_ptn;

#if defined(__CVSD_CODEC_SUPPORT__) 
   if(BT_SCO_IS_SPEECH_ON())
   {
      BT_SCO_SPEECH_OFF();
   }
#endif
  
   if( !AM_IsSpeechOn() )
      return;

	// mute DL to prevent sound pushes to hardware buffer then causes noise. Sync with the end of speech unumte
	L1SP_MuteSpeaker(true);
		
#if !DATA_CARD_DISABLE_INTERNAL      
//FIXME: for phone call usage
#if defined(__DATA_CARD_SPEECH__)
   if (l1sp.strmOffHandler != NULL)
      l1sp.strmOffHandler( NULL );
#endif
#endif

#if defined(__ECALL_SUPPORT__)
   if (l1sp.pcm4wayOffHandler != NULL)
      l1sp.pcm4wayOffHandler( (void *)0 );
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

   SetSpeechEnhancement( false );

   #ifndef __L1_STANDALONE__ // avoid link error
   // kal_uint32 module_id = MOD_L1AUDIO_SPH_SRV;	   
   // if(!tst_trace_check_ps_filter_off(TRACE_GROUP_VM, &module_id, 0x2) && voc_flag)
   if(voc_flag)
   {
      tst_vc_response(TVCI_VM_LOGGING, (const kal_uint8*)voc_ptn_ptr, 4);
	  VMREC_Stop(true);
	  voc_flag = false;
   }
	#endif

   AM_SpeechOff(0);

#if defined(__VOLTE_SUPPORT__)
   {
      uint8 state;
      state = l1sp.state;
      
      if(l1sp.state == L1SP_STATE_4G_SPEECH_ON || l1sp.interRAT ){
         L1SP_SetState(L1SP_STATE_4G_SPEECH_CLOSING);
      }
      sp4g_speech_close();
         
      /* only these cases should wait state, if only 2G happen, then return to idle */
      if( state == L1SP_STATE_4G_SPEECH_ON || l1sp.interRAT
      ){
            PSR_SP4G_Callback(SP4G_CODEC_CLOSED, (void*)SP4G_Rab_Id());
      }
   }
#endif

#if defined( __UMTS_RAT__ )
   {
      uint8 state;
      state = l1sp.state;
      
      if(l1sp.state == L1SP_STATE_3G_SPEECH_ON || l1sp.interRAT
#ifdef __VIDEO_CALL_SUPPORT__
          || l1sp.state == L1SP_STATE_3G324M_SPEECH_ON
#endif
      ){
         L1SP_SetState(L1SP_STATE_3G_SPEECH_CLOSING);
      }
      sp3g_speech_close();
         
    /* only these cases should wait state, if only 2G happen, then return to idle */
      if( state == L1SP_STATE_3G_SPEECH_ON || l1sp.interRAT
#ifdef __VIDEO_CALL_SUPPORT__
          || state == L1SP_STATE_3G324M_SPEECH_ON
#endif
      ){
         //uint32 waitTime;
#ifdef __VIDEO_CALL_SUPPORT__
         if( state == L1SP_STATE_3G324M_SPEECH_ON )
            vt_SP3G_Callback( (kal_uint8)SP3G_CODEC_CLOSED, (void*)0);
         else
#endif
            CSR_Codec_Close(SP3G_Rab_Id());
         /*
         for(waitTime = 0 ; ; waitTime ++)
         {     
            if(l1sp.state == L1SP_STATE_3G_SPEECH_CLOSED)
               break;
            ASSERT(waitTime < 20);     
            kal_sleep_task(1);
         }*/
      }
   }
#endif
   L1SP_SetState( L1SP_STATE_IDLE );

#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   VIBR_Vibration_Activate();
#endif

	//always unmute DSP uplink after speech off to keep the mute definition
	SP_MuteUlEnhResult(false);
	SP_MuteUlFromDiffPos(false, SP_MIC_MUTE_POS_FROM_ALL); 
	L1SP_MuteSpeaker(false);
	
   L1Audio_ClearFlag( l1sp.aud_id );
   L1Audio_FreeAudioID( l1sp.aud_id );
}

void L1SP_Set_DAI_Mode( uint8 mode )
{
	//this feature is phased out
}

void L1SP_SetAfeLoopback( bool enable )
{
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif         
   if( enable )
      AFE_TurnOnLoopback();
   else
      AFE_TurnOffLoopback();
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1SP_FreeAudID(aud_id);
#endif      
}

void L1SP_SetFIR( bool enable )
{
   if( enable ){
		
#ifdef ANALOG_AFE_PATH_EXIST		
      AFE_TurnOnFIR( L1SP_SPEECH );
      AFE_TurnOnFIR( L1SP_VOICE );
#endif // ANALOG_AFE_PATH_EXIST		

   }else{
   
#ifdef ANALOG_AFE_PATH_EXIST   
      AFE_TurnOffFIR( L1SP_SPEECH );
      AFE_TurnOffFIR( L1SP_VOICE );
#endif //ANALOG_AFE_PATH_EXIST

   }
}


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
/* under construction !*/
#endif   
/* under construction !*/
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
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
#endif





void L1SP_LoadSpeechPara( void ) 
{
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif   
   SPE_LoadSpeechPara(l1sp.sph_c_para, l1sp.sph_m_para, NULL, l1sp.sph_m_paraWb);  //l1sp.sph_v_para seems no one use it
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1SP_FreeAudID(aud_id);
#endif      
}

extern void spc_send_network_status_notify(void);

void l1sp_CodecStatusNotification(uint16 data)
{
   if(kal_if_lisr())
	   L1Audio_LSetEvent(l1sp.aud_id_codec_status, (void *)data);
	else
	   L1Audio_SetEvent(l1sp.aud_id_codec_status, (void *)data);
}

void l1sp_NetworkStatusNotification(void)
{
#if defined(__SMART_PHONE_MODEM__)     
   if(kal_if_lisr())
	   L1Audio_LSetEvent(l1sp.aud_id_network_status, NULL);
	else
	   L1Audio_SetEvent(l1sp.aud_id_network_status, NULL);
#endif	   
}

//AUDIO task
void l1sp_send_codec_status_notify(void *data)//to L4C
{
#if !defined(__L1_STANDALONE__)    
	 uint16 codec = (uint16) data;
	 L1SP_L4C_Codec l4c_codec = L1SP_L4C_NONE;
	 
	 switch(codec){
	    case 0:
	      l4c_codec = L1SP_L4C_GSM_FR;
	      break;
	    case 1:
	      l4c_codec = L1SP_L4C_GSM_HR;
	      break;
	    case 2:
	      l4c_codec = L1SP_L4C_GSM_EFR;
	      break;
	    default:
	      if(codec >= 0x3 && codec <= 0xA ){
	         l4c_codec = L1SP_L4C_AMR_NB;
	      }else if(codec >= 0x20 && codec <= 0x28 ){ 
	         l4c_codec = L1SP_L4C_AMR_WB;
	      }
	      break;
	 }
	 kal_trace(TRACE_INFO, L1SP_L4C_SEND_CODEC, codec, l4c_codec);

	 l4c_report_voice_codec(l4c_codec);
#endif	 
}

void L1SP_Init( void )
{
   l1sp.tch_state = KAL_FALSE;   


#if (!defined(__SMART_PHONE_MODEM__)) && (!defined(__DATA_CARD_SPEECH__))
	ApAudSys_config();
#endif

   SP_SetForcedUnMuteController(L1SP_FORCEDUNMUTE_ALL, false);

   memset(&l1sp.sph_c_para, 0, NUM_COMMON_PARAS*sizeof(uint16));
   memset(&l1sp.sph_m_para, 0, NUM_MODE_PARAS*sizeof(uint16));
   memset(&l1sp.sph_v_para, 0, NUM_VOL_PARAS*sizeof(uint16));
	memset(&l1sp.sph_m_paraWb, 0, NUM_MODE_PARAS*sizeof(uint16));
   


#ifdef ANALOG_AFE_PATH_EXIST
   l1sp.mic_volume = AFE_GetMicrophoneVolume(); // get initial value
#else
	l1sp.mic_volume = 0;
#endif

//#if defined(__BT_SUPPORT__)   
   l1sp.bt_on = false;
//#endif

#if defined( __UMTS_RAT__ )
   sp3g_init();
   l1sp.interRAT = false;
#endif
#if defined(__VOLTE_SUPPORT__)
   sp4g_init();
#endif
   SPE_Init();
   // l1sp.spe_flag = true;
   l1sp.isDLMute = l1sp.isULMute = false;
   l1sp.codec_mute = true;
   l1sp.codec_mute_mode = L1SP_L4C_EVENT_NONE;
   // l1sp.spe_state = 0;
   
   //default set the DMNR on
   // l1sp.spe_app_mask = 0xffff;
   // l1sp.spe_usr_mask = 0xffBf; // default turn dual mic off 
	// TODO: loud speaker mode DMNR
	// l1sp.spe_usr_sub_mask = 0x003E; // default value to turn on , sync with Sal_Enh_Dynamic_t bit wise definition
	
#if 0 // ANALOG_AFE_PATH_EXIST  
/* under construction !*/
/* under construction !*/
#endif
   // l1sp.pcmplayback_flag = KAL_FALSE; phase out
   // l1sp.isEnableNotchFilter = false;

   
#if defined(__DATA_CARD_SPEECH__)
   l1sp.strmOnHandler  = NULL;
   l1sp.strmOffHandler = NULL;
   l1sp.strmHdl = NULL;
#endif      
#if defined(__ECALL_SUPPORT__)
   l1sp.pcm4wayOnHandler = NULL; 
   l1sp.pcm4wayOffHandler = NULL;
#endif
   L1SP_SetState(L1SP_STATE_IDLE);
#if defined(__SMART_PHONE_MODEM__)   
	l1sp.aud_id_network_status = L1Audio_GetAudioID();
	L1Audio_SetEventHandler(l1sp.aud_id_network_status, (L1Audio_EventHandler)spc_send_network_status_notify);  
#endif	
	l1sp.aud_id_codec_status = L1Audio_GetAudioID();
	L1Audio_SetEventHandler(l1sp.aud_id_codec_status, (L1Audio_EventHandler)l1sp_send_codec_status_notify);  
   //memset(l1sp.sph_allVolumePara, 0, 3*7*4*sizeof(uint16));   
   // l1sp.sph_selectedOutFirIndex = 0;
}
kal_bool L1SP_TCH_State( void )
{
   return l1sp.tch_state;
}

extern kal_uint32 SP3G_GetCodecMode(void);
extern kal_uint32 SP4G_GetCodecMode(void);

// This is invoked by 2G L1D(LISR)
void L1SP_TCH_Notify( bool bOn )
{
#if defined(_SWITCH_AFE_CLK_)      
   uint16 L1D_GetRF(uint16 mode);
   uint16 RF_2G = L1D_GetRF(MML1_RF_2G);
   L1Audio_Msg_L1D_GetRF(RF_2G);
#endif   
   if( !bOn ){ // for 2G->3G handover, mute speech in case Speech_Off command too late to avoid noise
      L1Audio_Msg_TCH_NOTIFY(L1AUDIO_Str_onoff(0), L1Audio_Speech_State(l1sp.state));
      l1sp.tch_state = KAL_FALSE;
#if defined(_SWITCH_AFE_CLK_)               
      if( 2 == RF_2G){ //return :   1 -> RF1,  2-> RF2
         *MD2GSYS_AFE_CK_SEL = 0x0;         
      }
#endif      
      //mute speech
#if defined(__VOLTE_SUPPORT__)
      if( SP4G_Rab_State() && l1sp.state != L1SP_STATE_4G_SPEECH_ON && l1sp.state != L1SP_STATE_IDLE){//2G->4G fail case, TCH will be off
         SP4G_Reset();
         AM_InterRAT_2G_to_4G(SP4G_GetCodecMode());         
         L1SP_SetState( L1SP_STATE_4G_SPEECH_ON );
      }else     
#endif                     
#if defined( __UMTS_RAT__ )      
      if( SP3G_Rab_State() && l1sp.state != L1SP_STATE_3G_SPEECH_ON && l1sp.state != L1SP_STATE_IDLE){//3G->2G fail case, TCH will be off
         SP3G_Reset();
         AM_InterRAT_2G_to_3G(SP3G_GetCodecMode());        
         L1SP_SetState( L1SP_STATE_3G_SPEECH_ON );
      }
#endif      
      //else if( l1sp.state == L1SP_STATE_2G_SPEECH_ON ) 
         // in case speech off first then TCH off notify.(2G only. If in 3G, then don't care)
         //*DP_SC_MUTE |= 0x0002;
   }
   else{
      L1Audio_Msg_TCH_NOTIFY(L1AUDIO_Str_onoff(1), L1Audio_Speech_State(l1sp.state));
      l1sp.tch_state = KAL_TRUE;
#if defined(_SWITCH_AFE_CLK_)         
      if( 2 == RF_2G){ //return :   1 -> RF1,  2-> RF2
         *MD2GSYS_AFE_CK_SEL = 0x1;
      }
#endif      
      //*DP_SC_MUTE &= ~0x0002;
#if defined(__VOLTE_SUPPORT__)
      if( l1sp.state == L1SP_STATE_4G_SPEECH_ON ){//4G->2G HO
         AM_InterRAT_4G_to_2G();
         L1SP_SetState( L1SP_STATE_2G_SPEECH_ON );
      }else 
#endif               
#if defined( __UMTS_RAT__ )      
      if( l1sp.state == L1SP_STATE_3G_SPEECH_ON ){//3G->2G HO
         AM_InterRAT_3G_to_2G();         
         L1SP_SetState( L1SP_STATE_2G_SPEECH_ON );
      }
#endif      
   }

}

void L1SP_SpeechLoopBackEnable(kal_bool fgEnable)
{
	 SAL_LBK_Codec(fgEnable);
}

//-----------------------------------------------------------------------------
// Line in related. Phase out
/* 

void LINEIN_SetOutputDevice( uint8 device )
{
   AFE_SetOutputDevice( L1SP_LINEIN, device );
}

void LINEIN_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
   AFE_SetOutputVolume( L1SP_LINEIN, volume1, digital_gain_index );
}

void LINEIN_Open()
{

   if (!lineon_flag){
      ktLock();
#ifdef ANALOG_AFE_PATH_EXIST	      
      AFE_TurnOnSpeaker(L1SP_LINEIN);
#endif      
      lineon_flag = KAL_TRUE;
   }
}

void LINEIN_Close()
{
   if(lineon_flag){
#if defined(MT6252H) || defined(MT6252)
      AFE_SetGainFastRamp(KAL_TRUE);    
#endif

#ifdef ANALOG_AFE_PATH_EXIST	
      AFE_TurnOffSpeaker(L1SP_LINEIN);
#endif      

#if defined(MT6252H) || defined(MT6252)
      kal_sleep_task(3);
      AFE_SetGainFastRamp(KAL_FALSE);    
#endif

      ktUnlock();
      lineon_flag = KAL_FALSE;
   }
#if defined(__VIBRATION_SPEAKER_SUPPORT__)
   VIBR_Vibration_Activate();
#endif
}

void LINEIN_MuteSpeaker( bool mute )
{
   AFE_MuteSpeaker( L1SP_LINEIN, mute );
}

#if 0 // defined(__GAIN_TABLE_SUPPORT__)
void LINEIN_SetOutputGainControl( kal_uint32 gain ){
}

void LINEIN_SetOutputGainControlDualPath( kal_uint32 ext_amp_gain ){
}
#endif
*/
//-----------------------------------------------------------------------------

void ABF_SetAcousticLoopback( kal_bool loopback )
{
   return;
}
kal_bool ABF_GetAcousticLoopbackStatus( void )
{
   return KAL_FALSE;
}


/* Just for Factory Usage */
void L1SP_AcousticLoopbackOn (void)
{
//#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )      
//   AcousticLoopbackOn();
//#endif   
}

/* Just for Factory Usage */
void L1SP_AcousticLoopbackOff (void)
{
//#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )         
//   AcousticLoopbackOff();
//#endif   
}

/* Just for Factory Usage */
void L1SP_AcousticLoopbackSpeechMode(kal_uint8 u1Mode)
{
//#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )   
//   AcousticLoopbackSpeechMode(u1Mode);
//#endif       
}

/* Just for Factory Usage */
kal_bool L1SP_AcousticLoopbackStatus(void)
{
//#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )
//   AcousticLoopbackStatus();
//#endif

   return KAL_FALSE;
}

/* Just for Factory Usage */
void L1SP_AcousticLoopbackBypassMode(kal_uint8 u1Mode)
{
//#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )   
//   AcousticLoopbackBypassMode(u1Mode);
//#endif    
}

/* Just for Factory Usage */
void L1SP_AcousticLoopbackLength (kal_uint32 u4Length)
{
//#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )   
//   AcousticLoopbackLength(u4Length);
//#endif   
}

void L1SP_MutePCMOuputPort ( kal_bool fMute )
{

}

//-----------------------------------------------------------------------------


bool SP_is_codec_mute()
{
	 return l1sp.codec_mute;
}

void SP_L4C_SetEvent(L1SP_L4C_Event event, L1SP_L4C_Event_Mode mode)
{
   ilm_SP_L4C_SET_EVENT_t *local_para;
   kal_prompt_trace(MOD_L1SP, "[SP_L4C_SetEvent] Enter");
   local_para = (ilm_SP_L4C_SET_EVENT_t *) construct_local_para( sizeof(ilm_SP_L4C_SET_EVENT_t), TD_CTRL );
   local_para->event = event;
   local_para->mode  = mode;
   msg_send6(MOD_L1SP, MOD_MED, AUDIO_SAP, MSG_ID_AUDIO_M2M_SP_L4C_SET_EVENT, (local_para_struct *)local_para, NULL);
   kal_prompt_trace(MOD_L1SP, "[SP_L4C_SetEvent] Leave");
}


void SP_L4C_SetEvent_Execute(L1SP_L4C_Event event, L1SP_L4C_Event_Mode mode)
{
   kal_trace(TRACE_INFO, L1SP_L4C_EVENT, event, mode, l1sp.codec_mute_mode);
   kal_trace(TRACE_INFO, L1SP_MUTE_CONTROL_STATUS, 0, l1sp.isULMute, l1sp.isDLMute, l1sp.codec_mute, l1sp.forcedUnmuteController);
   
   ASSERT( L1SP_L4C_EVENT_NONE == l1sp.codec_mute_mode || mode == l1sp.codec_mute_mode );
   
   switch(event){
   case L1SP_L4C_ESPEECH_0:
      ASSERT(!l1sp.codec_mute);
      l1sp.codec_mute = true;
      l1sp.codec_mute_mode = L1SP_L4C_EVENT_NONE;
      break;   
   case L1SP_L4C_ESPEECH_1:
      ASSERT(l1sp.codec_mute);
      l1sp.codec_mute = false;
      l1sp.codec_mute_mode = mode;
      break;      
   default:
      ASSERT(0);   
   }

   {   
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif      
   SP_MuteController();
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1SP_FreeAudID(aud_id);
#endif  
   kal_trace(TRACE_INFO, L1SP_MUTE_CONTROL_STATUS, 1, l1sp.isULMute, l1sp.isDLMute, l1sp.codec_mute, l1sp.forcedUnmuteController);
   }
}

void SP_SetForcedUnMuteController(L1SP_FORCEDUNMUTE_BITMASK mask, bool b)
{
   kal_trace(TRACE_INFO, L1SP_FORCED_UNMUTE_CONTROLLER, l1sp.forcedUnmuteController, mask, b); 
   if(b){  
      l1sp.forcedUnmuteController |= mask;
   }else{
      l1sp.forcedUnmuteController &= (~mask);
   }
   kal_trace(TRACE_INFO, L1SP_FORCED_UNMUTE_CONTROLLER_1, l1sp.forcedUnmuteController); 
   
   {
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   kal_uint16 aud_id = L1SP_GetAudID();
#endif      
   SP_MuteController();
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1SP_FreeAudID(aud_id);
#endif     
   }
}

#if defined(__VOLTE_SUPPORT__)
static const L1SP_Tones tone_call_waiting[]           =  {  { 440,   0, 200, 100,   1 },
                                                            { 440,   0, 200,3500,   0 }   };        

extern void spc_BgSndConfig(kal_uint8 ulGainLevel, kal_uint8 dlGainLevel);
int spc_ul_gain = 7;
int spc_dl_gain = 7;
#endif
void SpeechDVT(int item){
#if defined(__VOLTE_SUPPORT__)
   switch(item){
   case 0:  
      spc_ul_gain --;    
      if(spc_ul_gain<0)spc_ul_gain = 0;
      spc_BgSndConfig(spc_ul_gain, spc_dl_gain);
      break;
   case 1:      
      spc_ul_gain ++;
      if(spc_ul_gain>7)spc_ul_gain = 7;
      spc_BgSndConfig(spc_ul_gain, spc_dl_gain);         
      break;      
   case 2:      
      spc_dl_gain --;    
      if(spc_dl_gain<0)spc_dl_gain = 0;
      spc_BgSndConfig(spc_ul_gain, spc_dl_gain);         
      break;
   case 3:      
      spc_dl_gain ++;   
      if(spc_dl_gain>7)spc_dl_gain = 7;       
      spc_BgSndConfig(spc_ul_gain, spc_dl_gain);         
      break;    
              
   case 6:
      L1SP_Speech_On(RAT_2G_MODE);
      break;
   case 7:
      L1SP_Speech_Off();
      break;

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
#endif /*#if 0*/

    case 57:
      SP4G_PSR_DL_KT_Play(300, 1300, 20000);   
      break;
    case 58:
      SP4G_PSR_DL_KT_Stop();
      break;                
    case 67:
      SP4G_PSR_UL_KT_Play(1000, 0, 20000);   
      break;
    case 68:
      SP4G_PSR_UL_KT_Stop();
      break;   
    case 69:
      KT_SetOutputVolume(100,4096*2);
      break;                   
    case 71:
      {
         SP4G_PSR_UL_Tone_Play( tone_call_waiting );  
      }
      break;
    case 72:
      {
         SP4G_PSR_UL_Tone_Stop( );  
      }
      break;  
    case 73:
      {
         SP4G_PSR_DL_Tone_Play( tone_call_waiting );  
      }
      break;
    case 74:
      {
         SP4G_PSR_DL_Tone_Stop( );  
      }
      break;        
   }
#endif   
}

#if defined(__VOLTE_SUPPORT__)  
#include "l1sp_el2_struct.h"
#if defined(__MCU_DTMF_SUPPORT__)       
void volte_Tone_bgSnd_closeHandler(void);//BGSND HISR to MED  ToDO
void volte_KT_bgSnd_closeHandler(void);//BGSND HISR to MED  ToDO
void volte_BGSND_ULHdr(void);
uint32 VolteToneGetID();
void VolteToneSetID(uint32 u32val);
bool VolteToneGetUsed();
void VolteToneSetUsed(bool bval);
#endif //#if defined(__MCU_DTMF_SUPPORT__)       
#endif //#if defined(__VOLTE_SUPPORT__)

void SP_M2M_Handler(ilm_struct *ilm_ptr)
{
   switch (ilm_ptr->msg_id) {
      case MSG_ID_AUDIO_M2M_SP_L4C_SET_EVENT:
      {
	  	   ilm_SP_L4C_SET_EVENT_t *local_para;
         local_para = (ilm_SP_L4C_SET_EVENT_t *)(ilm_ptr->local_para_ptr);
         SP_L4C_SetEvent_Execute(local_para->event, local_para->mode);
      }
      break;                 
#if defined(__VOLTE_SUPPORT__)
      case MSG_ID_AUDIO_M2M_VOLTE_MAC_TIMING_INFO:
      {
         sub_SP4G_emac_timing_update(ilm_ptr->local_para_ptr);
      }
      break;                 
#if defined(__MCU_DTMF_SUPPORT__)       
      case MSG_ID_AUDIO_M2M_VOLTE_KT_BGSND_CLOSE:
      {
         void volte_KT_BgSndClose(void);
         volte_KT_BgSndClose();
      }
      break;  
      case MSG_ID_AUDIO_M2M_VOLTE_TONE_BGSND_CLOSE:
      {
         void volte_Tone_BgSndClose(void);
         volte_Tone_BgSndClose();
      }
      break;             
      case MSG_ID_AUDIO_M2M_VOLTE_DL_KT_PLAY:
      {
         //SP4G_PSR_DL_KT_Play(5000, 8000, 100000);
         ilm_PSR_DL_KT_t *local_para;
         local_para = (ilm_PSR_DL_KT_t *)(ilm_ptr->local_para_ptr);
         KT_Play(local_para->freq1, local_para->freq2, local_para->duration, DSP_TONE);
      }
      break;
      case MSG_ID_AUDIO_M2M_VOLTE_DL_KT_STOP:      
      {
         //SP4G_PSR_DL_KT_Stop();
		 KT_Stop(DSP_TONE);
      }     
      break;  
      case MSG_ID_AUDIO_M2M_VOLTE_UL_KT_PLAY:
      {
         //SP4G_PSR_UL_KT_Play(5000, 8000, 100000);
         ilm_PSR_DL_KT_t *local_para;
         local_para = (ilm_PSR_DL_KT_t *)(ilm_ptr->local_para_ptr);
         if( KAL_FALSE == VolteToneGetUsed() ){	
            KT_Play(local_para->freq1, local_para->freq2, local_para->duration, MCU_TONE);
            VolteToneSetID( EXT_BGSND_Start(volte_KT_bgSnd_closeHandler, NULL, volte_BGSND_ULHdr, 7, 7) );
            VolteToneSetUsed(KAL_TRUE);
         }else{
            kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_UL_KT_Play] Skip");	   
         }
      }         
      break;
      case MSG_ID_AUDIO_M2M_VOLTE_UL_KT_STOP:      
      {
         //SP4G_PSR_UL_KT_Stop();
         if( KAL_TRUE == VolteToneGetUsed() ){ 
            EXT_BGSND_Flush( VolteToneGetID() );  
            KT_Stop(MCU_TONE);	   
         }else{
            kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_UL_KT_Stop] Skip");		 
         }
      }         
      break;   
      case MSG_ID_AUDIO_M2M_VOLTE_DL_TONE_PLAY:      
      {
         //SP4G_PSR_DL_Tone_Play( tone_call_waiting );
         ilm_PSR_DL_TONE_t *local_para;
         local_para = (ilm_PSR_DL_TONE_t *)(ilm_ptr->local_para_ptr);
		 TONE_Play(local_para->pToneList, DSP_TONE);
      }         
      break;   
      case MSG_ID_AUDIO_M2M_VOLTE_DL_TONE_STOP:      
      {
         //SP4G_PSR_DL_Tone_Stop();
		 TONE_Stop(DSP_TONE);
      }         
      break;   
      case MSG_ID_AUDIO_M2M_VOLTE_UL_TONE_PLAY:      
      {
         //SP4G_PSR_UL_Tone_Play( tone_call_waiting );
         ilm_PSR_DL_TONE_t *local_para;
         local_para = (ilm_PSR_DL_TONE_t *)(ilm_ptr->local_para_ptr);
         if( KAL_FALSE == VolteToneGetUsed() ){    
            TONE_Play(local_para->pToneList, MCU_TONE);
            VolteToneSetID( EXT_BGSND_Start(volte_Tone_bgSnd_closeHandler, NULL, volte_BGSND_ULHdr, 7, 7) );
            VolteToneSetUsed(KAL_TRUE);
         }else{
            kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_UL_Tone_Play] Skip"); 	  
         }
      }         
      break;   
      case MSG_ID_AUDIO_M2M_VOLTE_UL_TONE_STOP:      
      {
         //SP4G_PSR_UL_Tone_Stop();
         if( KAL_TRUE == VolteToneGetUsed() ){	
            EXT_BGSND_Flush( VolteToneGetID() ); 
            TONE_Stop(MCU_TONE);	  
         }else{
            kal_prompt_trace(MOD_L1SP, "[SP4G_PSR_UL_Tone_Stop] Skip"); 	   
         }
      }         
      break;   
#endif //#if defined(__MCU_DTMF_SUPPORT__)
#endif //#if defined(__VOLTE_SUPPORT__)
      default:
      {
         kal_prompt_trace(MOD_L1SP, "SP_M2M_Handler skip command: %x", ilm_ptr->msg_id);
         break;
      }
   }
}

