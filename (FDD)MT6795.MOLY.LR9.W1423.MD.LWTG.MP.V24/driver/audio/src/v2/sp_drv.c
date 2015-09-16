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
#include "string.h"
#include "kal_trace.h"
#include "l1audio_trace.h"
#include "custom_equipment.h"
#include "custom_equipment.h" /* custom_cfg_audio_ec_range() */
#include "device.h" /* MAX_VOL_LEVEL,  in ps\l4\include */
#include "audcoeff_default.h"

#include "l1audio.h"
#include "l1audio_def.h"
#include "fc_def.h"
#include "audio_enum.h"
#include "media.h"
#include "afe.h"
#include "am.h"
#include "l1sp_trc.h"
#include "l1audio_sph_trc.h"
#include "exp_SphFasTypDef.h"

#ifdef __SMART_PHONE_MODEM__
#include "audio_em_struct.h"
#endif //__SMART_PHONE_MODEM__

/* ------------------------------------------------------------------------------ */
/*  Speech Interface                                                              */
/* ------------------------------------------------------------------------------ */
typedef enum{
	L1SP_NVRAM_VALUES_FLAG_MODE = 0x1,
	L1SP_NVRAM_VALUES_FLAG_IN_FIR = 0x2,
	L1SP_NVRAM_VALUES_FLAG_OUT_FIR = 0x4,
	L1SP_NVRAM_VALUES_FLAG_WB_MODE = 0x8,
	L1SP_NVRAM_VALUES_FLAG_WB_IN_FIR = 0x10,
	L1SP_NVRAM_VALUES_FLAG_WB_OUT_FIR = 0x20,
	L1SP_NVRAM_VALUES_FLAG_RECORD_MODE = 0x40,
	L1SP_NVRAM_VALUES_FLAG_RECORD_IN_FIR = 0x80,
}L1SP_INTERNAL_NVRAM_VALUES_FLAG; // for NvramValuesFlag


static struct {
   uint16   aud_id;

   uint8    sph_mode;
   uint8    sph_level;
   uint16   *sph_c_para;//[NUM_COMMON_PARAS];
   uint16   *sph_m_para; //NB+WB, NB put first. then WB
#if defined(__DUAL_MIC_SUPPORT__)
   bool     dmnr_flag;
   uint16	*sph_dmnr_para;//[NUM_DMNR_PARAM]
#ifdef __AMRWB_LINK_SUPPORT__   
   uint16	*sph_wb_dmnr_para;
#endif   
#endif
   uint16   sph_v_para[NUM_VOL_PARAS];

   //value from nvram 
   uint16   setNvramValuesFlag; //bit 0 for sph_allModePara, bit 1 for sph_allInFirCoeff, bit 2 for sph_allOutFirCoeff, 
                                //bit 3 for sph_allWbModePara, bit 4 for sph_allWbInFirCoeff, bit 5 for sph_allWbOutFirCoeff
                                //bit 6 for recordModePara, bit 7 for recordInFirCoeff

   uint16   sph_allModePara[NUM_SPH_MODE][NUM_MODE_PARAS];   
   int16    sph_allInFirCoeff[NUM_SPH_INPUT_FIR][NUM_FIR_COEFFS];
   int16    sph_allOutFirCoeff[NUM_SPH_OUTPUT_FIR][NUM_FIR_COEFFS];
   uint16   sph_allVolumePara[3][7][4];
   uint16   sph_selectedOutFirIndex;
   
#if defined(__AMRWB_LINK_SUPPORT__)   || defined(__SMART_PHONE_MODEM__)
   //because smartphone always send the parameter to MD
   uint16	sph_allWbModePara[NUM_SPH_MODE][NUM_MODE_PARAS];
   int16    sph_allWbInFirCoeff[NUM_SPH_INPUT_FIR][NUM_WB_FIR_COEFFS];
   int16    sph_allWbOutFirCoeff[NUM_SPH_OUTPUT_FIR][NUM_WB_FIR_COEFFS];

#endif //__AMRWB_LINK_SUPPORT__ || __SMART_PHONE_MODEM__

#if defined(__HD_RECORD__) 
   uint16   recordModePara[NUM_RECORD_SPH_MODE][NUM_MODE_PARAS]; //actual size is [numOfRecordMode][NUM_MODE_PARAS]
   int16    recordInFirCoeff[NUM_RECORD_INPUT_FIR][NUM_WB_FIR_COEFFS]; //actual size in runtime is [numOfRecordInFir][NUM_WB_FIR_COEFFS]
#elif defined(__SMART_PHONE_MODEM__) //using hard coded size 
   uint16    recordModePara[SPC_MAX_NUM_RECORD_SPH_MODE][NUM_MODE_PARAS]; //actual size is [numOfRecordMode][NUM_MODE_PARAS]
   int16    recordInFirCoeff[SPC_MAX_NUM_RECORD_INPUT_FIR][NUM_WB_FIR_COEFFS]; //actual size in runtime is [numOfRecordInFir][NUM_WB_FIR_COEFFS]
#endif //defined(__HD_RECORD__) || defined(__SMART_PHONE_MODEM__)
#if defined(__HD_RECORD__) || defined(__SMART_PHONE_MODEM__)
   uint16 *recordModeFirMappingCh1;
#if defined(__STEREO_RECORD__) || defined(__SMART_PHONE_MODEM__)
   uint16 *recordModeFirMappingCh2;
#endif //defined(__STEREO_RECORD__) || defined(__SMART_PHONE_MODEM__)
   uint8  *recordModeDeviceMapping;
#endif //defined(__HD_RECORD__) || defined(__SMART_PHONE_MODEM__)
   int16	 numOfRecordMode;
   int16	 numOfRecordInFir;

   uint16   fc_aud_id;
   uint8    min_ec_level;
   uint8    max_ec_level;
   uint8    mic_volume;
   uint8    sph_dl_vol;
   
   uint16   spe_usr_mask;
   uint32   spe_usr_subFunc_mask; //use to control speech enhancement sub function.

   uint16   spe_app_mask;
   uint16   ul_spe_app_mask; //for UL SPE, check the mask when spe_app_mask[bit] is enable      
   uint16   dl_spe_app_mask; //for DL SPE, check the mask when spe_app_mask[bit] is enable  
   bool     spe_state;  // ec status
   bool     spe_flag;   //for UL/DL SPE

   bool     isULMute;
   bool     tch_state; // true: TCH on; false: TCH off
   bool     pcmplayback_flag; // only used in META taste function.
   bool     speech_loopback;  
   bool     speech_dmnr_loopback;  
   uint8    state;          
#if defined(__BT_SUPPORT__)
   bool     bt_on;
#endif
#if defined( __UMTS_RAT__ )
   bool     interRAT;
#endif
   void (*onHandler)(void *); 
   void (*offHandler)(void *); 

#ifdef BGSND_ENABLE
   void (*sndOnHandler)(void *hdl); 
   void (*sndOffHandler)(void *hdl);
   void *sndHdl;
#endif

  uint8    pre_mpara13_bit8;

#if defined(__DATA_CARD_SPEECH__)
   void (*strmOnHandler)(void *hdl); 
   void (*strmOffHandler)(void *hdl);
   void (*strmHdl)(kal_uint32 event, void *param);
#endif

#if defined(__ECALL_SUPPORT__)
   void (*pcm4wayOnHandler)(void *); 
   void (*pcm4wayOffHandler)(void *);
#endif
} l1sp;

static kal_bool lineon_flag = KAL_FALSE; 

#define SPH_BT_MODE_LINEAR 0
#define SPH_BT_MODE_SIGEXT 1 
#define SPH_BT_MODE_GAIN   2 


#ifdef L1D_TEST
const short g_ai2UntstBkfCofUlNb[45] = { 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 32767, 0 
};

//DL-NB
const short g_ai2UntstBkfCofDlNb[45] = { 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 32767, 0 
};

//UL-WB
const short g_ai2UntstBkfCofUlWb[90] = { 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 32767, 0 
};

//DL-WB
const short g_ai2UntstBkfCofDlWb[90] = { 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 32767, 0 
};
#endif

#ifdef L1D_TEST
const unsigned short Speech_Common_Para[12] = 
{ 
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0, 
     0,     0 
};
#else
const unsigned short Speech_Common_Para[12] = 
{ 
     0, 55997, 31000, 10752,     32769,     0,     0,     0,     0,     0, 
     0,     0 
};
#endif

/* SAC global structure definction*/

__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI")))
   SAC_SphModePar_t SAC_SphModePar;
__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI")))
   SAC_SphComPar_t  SAC_SphCommonPar;
__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI")))
   SAC_SphEnhancementPar_t SAC_SphEnhancementPar;
__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI")))
   SAC_Sph2GCallPar_t SAC_Sph2GCallPar;
__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI")))
   SAC_Sph3GCallPar_t SAC_Sph3GCallPar;
__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI")))
   SAC_SphBtCordlessPar_t SAC_SphBtCordlessPar;
#if defined(__BT_SUPPORT__)
__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI")))
   SAC_SphBluetoothPar_t SAC_SphBluetoothPar;
#endif

#if defined(__DUAL_MIC_SUPPORT__)
__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI")))
	 SAC_SphDMNRPar_t        SAC_SphDMNRPar;
__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI")))
   kal_uint16 sph_dmnr_par[NUM_DMNR_PARAM]; 
__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI")))
   kal_uint16 sph_wb_dmnr_par[NUM_WB_DMNR_PARAM];
#endif

__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI")))
   kal_int16 fir_ul_nb[45], fir_dl_nb[45];
__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI")))
   kal_int16 fir_ul_wb[90], fir_dl_wb[90];
__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI")))
   kal_uint16 sph_common_par[NUM_COMMON_PARAS];
__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI")))
   kal_uint16 sph_mode_par[NUM_MODE_PARAS*2]; //NB+WB

#ifdef L1D_TEST
__attribute__ ((section ("DMDSP_SHARE_AUDIO_RODATA"))) 
const short mode_Para_Unitest[32] = {
	0,221,0,30,-8185,31,400,44,4112,4325,3,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};
#endif


extern const unsigned short Speech_Normal_Mode_Para[16];
extern const unsigned short Speech_Vol_Para[4];
extern const signed short Sidetone_FIR[31];


void L1SP_DebugPrint16(uint16* ptr16, int len)
{
   int I;
   for(I=0; I+5<len; I+=5){
      kal_trace(TRACE_INFO, L1MCU2DSP_DEBUG_PRINT5, ptr16[I], ptr16[I+1], ptr16[I+2], ptr16[I+3], ptr16[I+4]); 
   }   
   switch(len%5){
   case 0:
      break;
   case 1:  
      kal_trace(TRACE_INFO, L1MCU2DSP_DEBUG_PRINT1, ptr16[I]); 
      break; 
   case 2:  
      kal_trace(TRACE_INFO, L1MCU2DSP_DEBUG_PRINT2, ptr16[I], ptr16[I+1]); 
      break;
   case 3:  
      kal_trace(TRACE_INFO, L1MCU2DSP_DEBUG_PRINT3, ptr16[I], ptr16[I+1], ptr16[I+2]); 
      break;
   case 4:  
      kal_trace(TRACE_INFO, L1MCU2DSP_DEBUG_PRINT4, ptr16[I], ptr16[I+1], ptr16[I+2], ptr16[I+3]); 
      break;                  
   }   
}

void L1SP_DebugPrint8(uint8* ptr8, int len)
{
   int I;
   for(I=0; I+5<len; I+=5){
      kal_trace(TRACE_INFO, L1MCU2DSP_DEBUG_PRINT5, ptr8[I], ptr8[I+1], ptr8[I+2], ptr8[I+3], ptr8[I+4]); 
   }   
   switch(len%5){
   case 0:
      break;
   case 1:  
      kal_trace(TRACE_INFO, L1MCU2DSP_DEBUG_PRINT1, ptr8[I]); 
      break; 
   case 2:  
      kal_trace(TRACE_INFO, L1MCU2DSP_DEBUG_PRINT2, ptr8[I], ptr8[I+1]); 
      break;
   case 3:  
      kal_trace(TRACE_INFO, L1MCU2DSP_DEBUG_PRINT3, ptr8[I], ptr8[I+1], ptr8[I+2]); 
      break;
   case 4:  
      kal_trace(TRACE_INFO, L1MCU2DSP_DEBUG_PRINT4, ptr8[I], ptr8[I+1], ptr8[I+2], ptr8[I+3]); 
      break;                  
   }   
}

void L1SP_DebugPrintCommonParas()
{
   kal_trace(TRACE_INFO, L1MCU2DSP_COMMONPAR);     
   L1SP_DebugPrint8((uint8 *)&SAC_SphCommonPar, sizeof(SAC_SphComPar_t));        
   kal_trace(TRACE_INFO, L1MCU2DSP_EMPCOM); 
   L1SP_DebugPrint16((uint16 *)SAC_SphCommonPar.pi2EMPCom, SAC_SphCommonPar.u4EMPComLen);   
   kal_trace(TRACE_INFO, L1MCU2DSP_SIDETONENB); 
   L1SP_DebugPrint16((uint16 *)SAC_SphCommonPar.pi2StFltCoef[0], SAC_SphCommonPar.au4StFltTap[0]);  
   kal_trace(TRACE_INFO, L1MCU2DSP_SIDETONEWB); 
   L1SP_DebugPrint16((uint16 *)SAC_SphCommonPar.pi2StFltCoef[1], SAC_SphCommonPar.au4StFltTap[1]);     
}

void L1SP_DebugPrintModeParas()
{
   kal_trace(TRACE_INFO, L1MCU2DSP_MODEPAR);            
   L1SP_DebugPrint8((uint8 *)&SAC_SphModePar, sizeof(SAC_SphModePar_t)); 

   kal_trace(TRACE_INFO, L1MCU2DSP_MODEPARANB); 
   L1SP_DebugPrint16((uint16 *)l1sp.sph_m_para , NUM_MODE_PARAS);

   kal_trace(TRACE_INFO, L1MCU2DSP_MODEPARAWB); 
   L1SP_DebugPrint16((uint16 *)&l1sp.sph_m_para[NUM_MODE_PARAS] , NUM_MODE_PARAS);
         
   kal_trace(TRACE_INFO, L1MCU2DSP_INFIRNB);  
   L1SP_DebugPrint16((uint16 *)fir_ul_nb, 45);  
   kal_trace(TRACE_INFO, L1MCU2DSP_OUTFIRNB);  
   L1SP_DebugPrint16((uint16 *)fir_dl_nb, 45);   
   
   kal_trace(TRACE_INFO, L1MCU2DSP_INFIRWB);  
   L1SP_DebugPrint16((uint16 *)fir_ul_wb, 90);  
   kal_trace(TRACE_INFO, L1MCU2DSP_OUTFIRWB);  
   L1SP_DebugPrint16((uint16 *)fir_dl_wb, 90);   
}

void L1SP_DebugPrintENHParas()
{
   int i;
   kal_prompt_trace(MOD_L1SP, "[MCU2DSP] ENHPar usr_msk=%x usr_sub_msk=%x app_msk=%x ul_app_msk=%x dl_app_msk=%x spe_state=%x spe_flag=%x",
                              l1sp.spe_usr_mask, l1sp.spe_usr_subFunc_mask, l1sp.spe_app_mask, l1sp.ul_spe_app_mask,
                              l1sp.dl_spe_app_mask, l1sp.spe_state, l1sp.spe_flag);                
   for( i = 0 ; i < SPH_ENH_MODE_NUM ; i++){
      kal_trace(TRACE_INFO, L1MCU2DSP_DEBUG_PRINT2, SAC_SphEnhancementPar.au4SwitchUl[i], SAC_SphEnhancementPar.au4SwitchDl[i]);
   }   
}

void L1SP_DebugPrintDMNRParas()
{
#ifdef __DUAL_MIC_SUPPORT__
   int i;
   L1SP_DebugPrint16((uint16 *)SAC_SphDMNRPar.pi2Par, SAC_SphDMNRPar.u4Len);    
#endif
}

void L1SP_DebugPrintRecordVMParas()
{
   extern SAC_SphRecordVmPar_t SAC_SphRecordVmPar;
   kal_trace(TRACE_INFO, L1MCU2DSP_DEBUGINFO, SAC_SphCommonPar.pi2EMPCom[0], L1Audio_GetDebugInfo(VM_DEBUG_INFO));
   L1SP_DebugPrint8((uint8 *)&SAC_SphRecordVmPar, sizeof(SAC_SphRecordVmPar_t)); 
}


#if defined(__BT_SUPPORT__)
bool L1SP_IsBluetoothOn( void )
{
   return (l1sp.sph_mode==SPH_MODE_BT_CORDLESS || l1sp.sph_mode==SPH_MODE_BT_EARPHONE || 
      l1sp.sph_mode==SPH_MODE_BT_CARKIT || l1sp.sph_mode==SPH_MODE_LINEIN_VIA_BT_CORDLESS);
}
#endif

void L1SP_UpdateWbSpeechPara( uint16 sph_m_para[NUM_MODE_PARAS] )
{
   
#ifdef L1DTEST_
   SAC_SphModePar.pi2EMPMode = mode_Para_Unitest;
#else
   memcpy(&l1sp.sph_m_para[NUM_MODE_PARAS], sph_m_para, NUM_MODE_PARAS*sizeof(uint16));
#endif
   SAC_SphModePar.u4EMPModeLen = (kal_uint32)NUM_MODE_PARAS * 2;
   L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_SET_MODE, sizeof(SAC_SphModePar_t), (kal_uint32)&SAC_SphModePar, true);
	{//to printf para for debug  
	   kal_trace(TRACE_INFO, L1MCU2DSP_FUNC1);       
      L1SP_DebugPrintModeParas();   
   }         
}

void L1SP_UpdateSpeechPara( uint16 sph_m_para[NUM_MODE_PARAS] )
{   
#ifdef L1DTEST_
   SAC_SphModePar.pi2EMPMode = mode_Para_Unitest;
#else
   memcpy(l1sp.sph_m_para, sph_m_para, NUM_MODE_PARAS*sizeof(uint16));
#endif
   SAC_SphModePar.u4EMPModeLen = (kal_uint32)NUM_MODE_PARAS * 2;
   L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_SET_MODE, sizeof(SAC_SphModePar_t), (kal_uint32)&SAC_SphModePar, true);
	{//to printf para for debug      
	   kal_trace(TRACE_INFO, L1MCU2DSP_FUNC2);    
      L1SP_DebugPrintModeParas();   
   }            
}

void L1SP_PCMPlayback_SetFlag(void)
{
	 l1sp.pcmplayback_flag = true;
}

void L1SP_PCMPlayback_ClearFlag(void)
{
	 l1sp.pcmplayback_flag = false;
}

bool L1SP_PCMPlayback_CheckFlag(void)
{
	 return l1sp.pcmplayback_flag;
}

void l1sp_updateSpeAppMask(uint16 updateMaskBits, bool enable)
{
	if(enable)
		l1sp.spe_app_mask |= (updateMaskBits);
	else
		l1sp.spe_app_mask &= ~(updateMaskBits);

	kal_trace( TRACE_INFO, L1SP_UPDATE_SPE_APP_MASK, 0, l1sp.spe_app_mask, l1sp.spe_usr_mask, updateMaskBits, enable);
	
}

void l1sp_updateSpeUsrMask(uint16 updateFlags, bool enable)
{
	if(enable)
		l1sp.spe_usr_mask |= (updateFlags);
	else
		l1sp.spe_usr_mask &= ~(updateFlags);

	kal_trace( TRACE_INFO, L1SP_UPDATE_SPE_USR_MASK, 0, l1sp.spe_app_mask, l1sp.spe_usr_mask, updateFlags, enable);	
	
   if(l1sp.spe_state) // already turn on speech enhancement
      SetSpeechEnhancement(KAL_TRUE);
}
void l1sp_updateSpeUsrMaskWithWholeValue(uint16 newValue)
{
	kal_uint16 orgValue = l1sp.spe_usr_mask;

	l1sp.spe_usr_mask  = newValue;
	
	kal_trace( TRACE_INFO, L1SP_UPDATE_SPE_USR_MASK, 2, l1sp.spe_app_mask, l1sp.spe_usr_mask, newValue, orgValue);	
	
	if(l1sp.spe_state) // already turn on speech enhancement
      SetSpeechEnhancement(KAL_TRUE);
}

void l1sp_updateUlSpeAppMask(uint16 updateMaskBits, bool enable)
{
	if(enable)
		l1sp.ul_spe_app_mask |= (updateMaskBits);
	else
		l1sp.ul_spe_app_mask &= ~(updateMaskBits);

	kal_trace( TRACE_INFO, L1SP_UPDATE_SPE_APP_MASK, 1, l1sp.spe_app_mask, l1sp.spe_usr_mask, updateMaskBits, enable);
	
}

void l1sp_updateDlSpeAppMask(uint16 updateMaskBits, bool enable)
{
	if(enable)
		l1sp.dl_spe_app_mask |= (updateMaskBits);
	else
		l1sp.dl_spe_app_mask &= ~(updateMaskBits);

	kal_trace( TRACE_INFO, L1SP_UPDATE_SPE_APP_MASK, 2, l1sp.spe_app_mask, l1sp.spe_usr_mask, updateMaskBits, enable);
	
}

void SetSpeechEnhancementSubFeature(void)
{
	//FIXME:
	L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_ENHANCEMENT_SET_SUB_FEATURE, 0, l1sp.spe_usr_subFunc_mask);
}


void l1sp_updateSpeUsrSubFuncMaskWithWholeValue(uint32 newMaskValue)
{
	kal_uint32 orgMask = l1sp.spe_usr_subFunc_mask;

	// update 
	l1sp.spe_usr_subFunc_mask = newMaskValue;
	
	kal_trace( TRACE_INFO, L1SP_UPDATE_SPE_USR_MASK, 1, l1sp.spe_app_mask, l1sp.spe_usr_mask, newMaskValue, orgMask);	

	// Speech allows setting same value many time. 
	SetSpeechEnhancementSubFeature();	
}


#if defined(__HQA_AUDIO__)
void SetSpeechEnhancement( bool ec1 )
#else
void SetSpeechEnhancement( bool ec )
#endif
{
#ifndef L1D_TEST
   kal_uint32 i;

#if defined(__HQA_AUDIO__)
   kal_bool ec = KAL_FALSE; 
#endif

   //if( (!AM_IsSpeechOn() || !l1sp.spe_flag) && !AM_IsVoIPOn() && !l1sp.pcmplayback_flag)
   if( ((!AM_IsAmInSpeechState()) || (!l1sp.spe_flag)) && !l1sp.pcmplayback_flag)
      return;

   for( i = 0 ; i < SPH_ENH_MODE_NUM ; i++){
      kal_uint16 currentMask = 1<<i;
      if( ((l1sp.spe_usr_mask & currentMask) == 0) ||
          ((l1sp.spe_app_mask & currentMask) == 0)){
         SAC_SphEnhancementPar.au4SwitchUl[i] = 0;
         SAC_SphEnhancementPar.au4SwitchDl[i] = 0;
      } else {
         // UL enhancement
         if( (l1sp.ul_spe_app_mask & (currentMask)) == 0 ){
            SAC_SphEnhancementPar.au4SwitchUl[i] = 0;
         } else {
            SAC_SphEnhancementPar.au4SwitchUl[i] = ec;
         }

         // DL enhancement
		 if( (l1sp.dl_spe_app_mask & (currentMask)) == 0 ){
            SAC_SphEnhancementPar.au4SwitchDl[i] = 0;
         } else {
            SAC_SphEnhancementPar.au4SwitchDl[i] = ec;
         }
      }
   }

   if ( !(AFE_IsDualMic() && AFE_GetInputSource() == L1SP_MICROPHONE1 ) )
   {
      //only enable DMNR when dual mic 
      SAC_SphEnhancementPar.au4SwitchUl[SPH_ENH_MODE_DMNR] = KAL_FALSE;
      SAC_SphEnhancementPar.au4SwitchDl[SPH_ENH_MODE_DMNR] = KAL_FALSE;
   }

   //Only digital mic enable SW AGC
   /*
   if(AFE_GetInputSource() != L1SP_LNA_DIGITAL){
      SAC_SphEnhancementPar.au4SwitchUl[SPH_ENH_MODE_AGC] = false;
      SAC_SphEnhancementPar.au4SwitchDl[SPH_ENH_MODE_AGC] = false;
   }*/
   
   l1sp.spe_state = ec;
   L1Audio_PutMessageAndWait( MSG_L1AUDIO2FAS_SPEECH_ENHANCEMENT_SET_PAR, sizeof(SAC_SphEnhancementPar_t), (kal_uint32)&SAC_SphEnhancementPar, KAL_TRUE );
   if((l1sp.spe_app_mask & (SPH_ENH_MASK_SIDETONE)) != 0) {    
      if(l1sp.sph_mode==SPH_MODE_LOUDSPK){
         AFE_SetSidetone( false );
      } else {
         AFE_SetSidetone( true );
      }
   }
	{//to printf para for debug    
	   kal_trace(TRACE_INFO, L1MCU2DSP_FUNC3);      
      L1SP_DebugPrintENHParas();  
   }        
   SetSpeechEnhancementSubFeature();
#endif   
}

void L1SP_LoadCommonSpeechPara( uint16 c_para[NUM_COMMON_PARAS] )
{
   SAC_SphCommonPar.u4EMPComLen = 12;
#ifdef L1D_TEST
   SAC_SphCommonPar.pi2EMPCom = (kal_int16 *)Speech_Common_Para;
#else
   memcpy(l1sp.sph_c_para, c_para, NUM_COMMON_PARAS*sizeof(uint16));
#endif
   L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_CONFIG, sizeof(SAC_SphComPar_t), (kal_uint32)&SAC_SphCommonPar, true);
   SetSpeechEnhancement( true );
}


static void L1SP_SetMagicParaForDefault(void)
{
	//for DMNR
#if defined(__DUAL_MIC_SUPPORT__)	
	
	if(0 == l1sp.dmnr_flag) {
		//NB coefficient
		SAC_SphDMNRPar.u4Len = NUM_DMNR_PARAM;
		memset(&sph_dmnr_par[0], 0x55, NUM_DMNR_PARAM*sizeof(uint16));
		SAC_SphDMNRPar.pi2Par = &sph_dmnr_par[0];
		L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_DMNR_SET_PAR, sizeof(SAC_SphDMNRPar_t), (kal_uint32)&SAC_SphDMNRPar, true);

		//WB coefficient
		SAC_SphDMNRPar.u4Len = NUM_WB_DMNR_PARAM;
		memset(&sph_wb_dmnr_par[0], 0x55, NUM_WB_DMNR_PARAM*sizeof(uint16));
		SAC_SphDMNRPar.pi2Par = &sph_wb_dmnr_par[0];
		L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_DMNR_SET_PAR, sizeof(SAC_SphDMNRPar_t), (kal_uint32)&SAC_SphDMNRPar, true);
		
		l1sp.dmnr_flag = true;
	}

#endif 
}

#if defined(__DUAL_MIC_SUPPORT__)
void L1SP_SetABFPara( kal_int16 DMNR_para[NUM_DMNR_PARAM] )
{
   L1SP_SetDMNRPara(DMNR_para);
}

void L1SP_SetDMNRPara( kal_int16 DMNR_para[NUM_DMNR_PARAM] )
{
	L1SP_SetMagicParaForDefault();
	
   SAC_SphDMNRPar.u4Len = NUM_DMNR_PARAM;
   SAC_SphDMNRPar.pi2Par = (kal_uint16 *)l1sp.sph_dmnr_para;    
	memcpy(l1sp.sph_dmnr_para, DMNR_para, NUM_DMNR_PARAM*sizeof(uint16));
	L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_DMNR_SET_PAR, sizeof(SAC_SphDMNRPar_t), (kal_uint32)&SAC_SphDMNRPar, true);
	{//to printf para for debug         
	   kal_trace(TRACE_INFO, L1MCU2DSP_FUNC4); 
      L1SP_DebugPrintDMNRParas(); 
   }		
}
#if defined(__AMRWB_LINK_SUPPORT__)
void L1SP_SetWbDMNRPara( kal_int16 WB_DMNR_para[NUM_WB_DMNR_PARAM] )
{
   L1SP_SetMagicParaForDefault();
   
   SAC_SphDMNRPar.u4Len = NUM_WB_DMNR_PARAM;
   SAC_SphDMNRPar.pi2Par = (kal_uint16 *)l1sp.sph_wb_dmnr_para;
 	memcpy(l1sp.sph_wb_dmnr_para, WB_DMNR_para, NUM_WB_DMNR_PARAM*sizeof(uint16));
	L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_DMNR_SET_PAR, sizeof(SAC_SphDMNRPar_t), (kal_uint32)&SAC_SphDMNRPar, true);   
	{//to printf para for debug 
	   kal_trace(TRACE_INFO, L1MCU2DSP_FUNC5);        
      L1SP_DebugPrintDMNRParas();  
   }	 
}

#endif
#endif

kal_uint8 L1SP_GetSpeechMode( void )
{
    return l1sp.sph_mode;
}


void l1sp_getSpeechModeByIndex(uint8 mode, uint16 *modeParam)
{
	memcpy(modeParam, l1sp.sph_allModePara[mode], NUM_MODE_PARAS*sizeof(uint16));
}

void l1sp_setAllSpeechModePara(uint16 * speech_mode_para, int16 length)
{
	ASSERT((NUM_SPH_MODE*NUM_MODE_PARAS) == length);
	
	memcpy(l1sp.sph_allModePara, speech_mode_para, 
		NUM_SPH_MODE*NUM_MODE_PARAS*sizeof(uint16));
	l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_MODE;
}



void l1sp_setAllSpeechFirCoeff_InputOnly(int16 *speech_input_FIR_coeffs, int16 length)
{
	ASSERT((NUM_SPH_INPUT_FIR*NUM_FIR_COEFFS) == length);
	
	memcpy(l1sp.sph_allInFirCoeff, speech_input_FIR_coeffs, 
		NUM_SPH_INPUT_FIR*NUM_FIR_COEFFS*sizeof(int16));
	l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_IN_FIR;

}

void l1sp_setAllSpeechFirCoeff_OutputOnly(int16 *speech_output_FIR_coeffs, int16 length)
{
	ASSERT((NUM_SPH_INPUT_FIR*NUM_FIR_COEFFS) == length);
	
	memcpy(l1sp.sph_allOutFirCoeff, speech_output_FIR_coeffs,
		NUM_SPH_OUTPUT_FIR*NUM_FIR_COEFFS*sizeof(int16));
	l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_OUT_FIR;
}

void l1sp_setAllWbSpeechModePara(uint16 * speech_mode_para, int16 length)
{
#if defined(__AMRWB_LINK_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
	ASSERT((NUM_SPH_MODE*NUM_MODE_PARAS) == length);
	
	memcpy(l1sp.sph_allWbModePara, speech_mode_para, 
		NUM_SPH_MODE*NUM_MODE_PARAS*sizeof(uint16));
	l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_WB_MODE; // (1<<3) bit [3]
#endif //__AMRWB_LINK_SUPPORT__ || defined(__SMART_PHONE_MODEM__)
}


void l1sp_setAllWbSpeechFirCoeff_InputOnly(
		int16 *speech_input_FIR_coeffs, int16 length)
{
#if defined(__AMRWB_LINK_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
	ASSERT((NUM_SPH_INPUT_FIR*NUM_WB_FIR_COEFFS) == length);
	memcpy(l1sp.sph_allWbInFirCoeff, speech_input_FIR_coeffs, 
		length*sizeof(int16));
	l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_WB_IN_FIR; // (1<<4) bit [4]
#endif //__AMRWB_LINK_SUPPORT__ || defined(__SMART_PHONE_MODEM__)
}

void l1sp_setAllWbSpeechFirCoeff_OutputOnly(
		int16 *speech_output_FIR_coeffs, int16 length)
{
#if defined(__AMRWB_LINK_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
	ASSERT((NUM_SPH_OUTPUT_FIR*NUM_WB_FIR_COEFFS) == length);
	memcpy(l1sp.sph_allWbOutFirCoeff, speech_output_FIR_coeffs,
		length*sizeof(int16));
	l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_WB_OUT_FIR; // (1<<4) bit [4]
#endif //__AMRWB_LINK_SUPPORT__ || defined(__SMART_PHONE_MODEM__)
}

//=============================================================================

#if defined(__HD_RECORD__)
extern const short HD_RECORD_MODE_FIR_MAPPING_CH1[NUM_RECORD_SPH_MODE];
#if defined(__STEREO_RECORD__)
extern const short HD_RECORD_MODE_FIR_MAPPING_CH2[NUM_RECORD_SPH_MODE];
#endif
extern const short HD_RECORD_MODE_DEVICE_MAPPING[NUM_RECORD_SPH_MODE];
#endif

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
		//kal_mem_cpy(l1sp.sph_allInFirCoeff, (buffer + bufCur), (sizeof(kal_uint16)* 6 * NUM_FIR_COEFFS));
		//l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_IN_FIR; // (1<<1) bit [1]
		l1sp_setAllSpeechFirCoeff_InputOnly((int16 *)(buffer + bufCur), 6 * NUM_FIR_COEFFS);
        bufCur += (sizeof(kal_uint16) * 6 *NUM_FIR_COEFFS);

		//NB output FIR
        //kal_mem_cpy(l1sp.sph_allOutFirCoeff, (buffer + bufCur) , (sizeof(kal_uint16)* 6 * NUM_FIR_COEFFS));
		//l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_OUT_FIR; // (1<<2) bit [2]
		l1sp_setAllSpeechFirCoeff_OutputOnly((int16 *)(buffer + bufCur), 6 * NUM_FIR_COEFFS);
		bufCur += (sizeof(kal_uint16) * 6 *NUM_FIR_COEFFS);

		//selected FIR
		kal_mem_cpy(&(l1sp.sph_selectedOutFirIndex), (buffer + bufCur), sizeof(kal_uint16));
		bufCur += sizeof(kal_uint16);
		
		//common
		{
		//kal_mem_cpy(l1sp.sph_c_para, (buffer + bufCur) , (sizeof(kal_uint16)* 12));
		uint16 *data = (uint16 *)(buffer + bufCur);
		L1SP_LoadCommonSpeechPara(data);
		bufCur += sizeof(kal_uint16) * 12; //hardcoding size
		}
		
		//mode parameter
		//kal_mem_cpy(l1sp.sph_allModePara, (buffer + bufCur) , (sizeof(kal_uint16)* NUM_SPH_MODE * 16));
		//l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_MODE; // (1<<0) bit [0]
		l1sp_setAllSpeechModePara((uint16 *)(buffer + bufCur), NUM_SPH_MODE * 16);
		bufCur += (sizeof(kal_uint16)* NUM_SPH_MODE * 16);

		//volume level
		kal_mem_cpy(l1sp.sph_allVolumePara, (buffer + bufCur), (sizeof(kal_uint16)*3*7*4));
		//l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_VOLUME_PARAM;
		
		/*
	    	kal_uint16 Media_Playback_Maximum_Swing;
    		kal_int16 Melody_FIR_Coeff_Tbl[25];
	    	kal_int16 audio_compensation_coeff[3][45];
		*/
	}
		break;
		
#if defined(__AMRWB_LINK_SUPPORT__)
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_INPUT_FIR:
	{
 		int16 *datas = (int16 *)(buffer);
		l1sp_setAllWbSpeechFirCoeff_InputOnly(datas, len>>1);
	}
		break;
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_OUTPUT_FIR:
	{
		int16 *datas = (int16 *)(buffer);
		l1sp_setAllWbSpeechFirCoeff_OutputOnly(datas, len>>1);
		
	}
		break;
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_MODE_PARAM:
	{
		uint16 *datas = (uint16 *)(buffer);
		l1sp_setAllWbSpeechModePara(datas, len>>1);
	}
		break;
#endif

#if defined(__HD_RECORD__)
	case L1SP_NVRAM_INFO_INDEX_HD_RECORD:
	{
		int16 bufCur=0, secLen;


		//enhancment mode 
		//secLen = NUM_RECORD_SPH_MODE*NUM_MODE_PARAS*sizeof(uint16);
		//memcpy(l1sp.recordModePara, (buffer + bufCur), secLen);
		l1sp_setAllRecordModePara((uint16 *)(buffer + bufCur), NUM_RECORD_SPH_MODE*NUM_MODE_PARAS,
			NUM_RECORD_SPH_MODE);		
		bufCur += secLen;

		//input fir
		//secLen = NUM_RECORD_INPUT_FIR*NUM_WB_FIR_COEFFS*sizeof(int16);
		//memcpy(l1sp.recordInFirCoeff, (buffer + bufCur), secLen);
		l1sp_setAllRecordInFirCoeff((int16 *)(buffer + bufCur), NUM_RECORD_INPUT_FIR*NUM_WB_FIR_COEFFS, 
			NUM_RECORD_INPUT_FIR);
		bufCur += secLen;
		
#ifndef __SMART_PHONE_MODEM__ //initial the value when value comes from nvram
   		l1sp_setRecordModeFirMappingCh1((uint16 *)HD_RECORD_MODE_FIR_MAPPING_CH1, NUM_RECORD_SPH_MODE, NUM_RECORD_SPH_MODE);
#if defined(__STEREO_RECORD__)
		l1sp_setRecordModeFirMappingCh2((uint16 *)HD_RECORD_MODE_FIR_MAPPING_CH2, NUM_RECORD_SPH_MODE, NUM_RECORD_SPH_MODE);
#endif //defined(__STEREO_RECORD__)
		l1sp_setRecordModeDeviceMapping((uint8 *)HD_RECORD_MODE_DEVICE_MAPPING, NUM_RECORD_SPH_MODE, NUM_RECORD_SPH_MODE);
#endif
		
	}
		break;
#endif //__HD_RECORD__	

	default:
		ASSERT(0); 
	}
		
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
#if defined(__AMRWB_LINK_SUPPORT__)
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_INPUT_FIR:
	{
		ASSERT(len == (NUM_SPH_INPUT_FIR * NUM_WB_FIR_COEFFS));
		memcpy(buffer, l1sp.sph_allWbInFirCoeff, sizeof(kal_uint16) * NUM_SPH_INPUT_FIR * NUM_WB_FIR_COEFFS);
	}
		break;
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_OUTPUT_FIR:
	{
		ASSERT(len == (NUM_SPH_OUTPUT_FIR * NUM_WB_FIR_COEFFS));
		memcpy(buffer, l1sp.sph_allWbOutFirCoeff, sizeof(kal_uint16) * NUM_SPH_OUTPUT_FIR * NUM_WB_FIR_COEFFS);
	}
		break;
	case L1SP_NVRAM_INFO_INDEX_WB_SPEECH_MODE_PARAM:
	{
		ASSERT(len == (NUM_SPH_MODE * NUM_MODE_PARAS));
		memcpy(l1sp.sph_allWbModePara, buffer, sizeof(kal_uint16) * NUM_SPH_MODE * NUM_MODE_PARAS);
	}
		break;
#endif	
	default:
		ASSERT(0); 
	}
}

//=============================================================================

#if defined(__HD_RECORD__) || defined(__SMART_PHONE_MODEM__)
void l1sp_setAllRecordModePara(uint16 *record_mod_paras, int16 length, int16 numOfParaSet)
{
	ASSERT(length == (numOfParaSet*NUM_MODE_PARAS));
	
	memcpy(l1sp.recordModePara, record_mod_paras, numOfParaSet*NUM_MODE_PARAS*sizeof(uint16));	
	l1sp.numOfRecordMode = numOfParaSet;
	l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_RECORD_MODE; // (1<<3) bit [6]
		
}
#endif // __HD_RECORD__ || __SMART_PHONE_MODEM__

int16 l1sp_getNumOfRecordMode(void)
{
	//default return value is 0 if "__HD_RECORD__" and "smart_phone" is not open. 
	return l1sp.numOfRecordMode;
}

#if defined(__HD_RECORD__) || defined(__SMART_PHONE_MODEM__)
void l1sp_setAllRecordInFirCoeff(int16 *record_input_fir_coeffs, int16 length, int16 numOfFirSet)
{
	ASSERT(length == (numOfFirSet * NUM_WB_FIR_COEFFS));
	
	memcpy(l1sp.recordInFirCoeff, record_input_fir_coeffs, numOfFirSet*NUM_WB_FIR_COEFFS*sizeof(int16));	
	l1sp.numOfRecordInFir= numOfFirSet;
	l1sp.setNvramValuesFlag |= L1SP_NVRAM_VALUES_FLAG_RECORD_IN_FIR; // (1<<4) bit [7]
	
}
#endif




/**
	@firIndex: [input] index of speech record input FIR. it should be >=0 && < l1sp.numOfRecordInFir
	@recordInFirCoeff: [output] resout of speech record input FIR. (recordInFirCoeff[NUM_WB_FIR_COEFFS)

void l1sp_GetRecordInFirCoeffByIndex(kal_int16 firIndex, kal_int16 *recordInFirCoeff)
{
#if defined(__HD_RECORD__) || defined(__SMART_PHONE_MODEM__)
	memcpy(recordInFirCoeff, l1sp.recordInFirCoeff, NUM_WB_FIR_COEFFS*sizeof(kal_int16));
#else
	recordInFirCoeff = NULL;
#endif //defined(__HD_RECORD__) || defined(__SMART_PHONE_MODEM__)
}
*/


#if defined(__HD_RECORD__) || defined(__SMART_PHONE_MODEM__)
void l1sp_setRecordModeFirMappingCh1(uint16 *mappingTable, int16 length, int16 numOfRecordMode)
{
	ASSERT(numOfRecordMode == l1sp.numOfRecordMode);
	ASSERT(length == l1sp.numOfRecordMode);
	
	//memcpy(l1sp.recordModeFirMapping, mappingTable, numOfRecordMode*sizeof(uint16));
	l1sp.recordModeFirMappingCh1 = mappingTable;
}

#if defined(__STEREO_RECORD__) || defined(__SMART_PHONE_MODEM__)
void l1sp_setRecordModeFirMappingCh2(uint16 *mappingTable, int16 length, int16 numOfRecordMode)
{
	ASSERT(numOfRecordMode == l1sp.numOfRecordMode);
	ASSERT(length == l1sp.numOfRecordMode);
	
	//memcpy(l1sp.recordModeFirMapping, mappingTable, numOfRecordMode*sizeof(uint16));
	l1sp.recordModeFirMappingCh2 = mappingTable;
}
#endif //defined(__STEREO_RECORD__) || defined(__SMART_PHONE_MODEM__)

void l1sp_setRecordModeDeviceMapping(uint8 *mappingTable, int16 length, int16 numOfRecordMode)
{
	ASSERT(numOfRecordMode == l1sp.numOfRecordMode);
	ASSERT(length == l1sp.numOfRecordMode);
	
	l1sp.recordModeDeviceMapping = mappingTable;
}
#endif //defined(__HD_RECORD__) || defined(__SMART_PHONE_MODEM__)

//=============================================================================

/**
	user: maybe META
	(realted to customer folder)
	@return: number of enhancement mode sets, include speech used(in-call) and HD record used (when compile optin opened)
*/
int16 L1SP_GetNumOfAllEnhancementMode()
{
#if defined(__SMART_PHONE_MODEM__)
	return 8;
#else
	return (8 
#if defined(__HD_RECORD__)
		+ NUM_RECORD_SPH_MODE
#endif
	);
#endif
}

//=============================================================================

/**
	user: maybe META
	(related to customer folder)
	For example, if you want to query wb input fir numbers, please invoke L1SP_GetNumOfAllFir(1,0) to get the result.
	
	@isWideBand: 0 is narrow band (8k), >0 is wide band(16k)
	@isOutputFir: 0 is for input FIR, >0 is for output FIR 
	@return: number of FIR sets. includes speech used(in-call), recording used (when compile option opened)
*/
kal_int16 L1SP_GetNumOfAllFir(kal_uint8 isWideBand, kal_uint8 isOutputFir)
{
	if(isWideBand == 0) { //NB
		if(isOutputFir)
			return NUM_SPH_OUTPUT_FIR;
		else
			return NUM_SPH_INPUT_FIR;
	}else{ //WB
		if(isOutputFir) {
			return NUM_SPH_OUTPUT_FIR;
		} else {
			return (NUM_SPH_INPUT_FIR
#if defined(__HD_RECORD__)
					+ NUM_RECORD_INPUT_FIR
#endif 
			);
		}

	}
}

//=============================================================================

#if defined(__HD_RECORD__)
extern const short HD_RECORD_MODE_CATEGORY[NUM_RECORD_SPH_MODE];
#endif

/**
	user: should be META only
	(realted to customer folder)

	@inputBufLength: [Input] the length of result buffer provided by caller. 
	  The value of "inputBufLength" and "1 * @return" should be equal, because category is a 1D array.
	@categoryResult: [Output] An array indicate which tab(category) the enhancement belongs to. 
	  0 for "in-call", 1 for "voice-record", 2 for "vedio-record". For example: categoryResult[0] = 0, categoryResult[1] = 0 ....	  
	@return: number of all enhancement mode sets, when <= 0, it means some error occur when function execution
*/
int16 L1SP_GetAllEnhancementModeCategory(int16 inputBufLength, int16 *categoryResult)

{
	int16 i;
	int16 result1[8];
	int16 numofEnhMode = L1SP_GetNumOfAllEnhancementMode();
	
	//error handling when buffer size is too small
	if(inputBufLength < (numofEnhMode*1)){
		return -1;
	}
	
	for(i=0; i<8; i++) {
		result1[i] = 0;
	}
		
	memcpy(categoryResult, result1, 8 * sizeof(int16));

#if defined(__HD_RECORD__) && (! defined(__SMART_PHONE_MODEM__))

	if(NUM_RECORD_SPH_MODE > 0)
		memcpy(&categoryResult[8], HD_RECORD_MODE_CATEGORY, NUM_RECORD_SPH_MODE*sizeof(int16));
	
#endif

	return numofEnhMode;
}

//=============================================================================

#define QUOTE(x) #x
#define SPEECH_MODE_NAME_NORMAL QUOTE(Normal Mode)
#define SPEECH_MODE_NAME_EARPHONE QUOTE(Earphone Mode)
#define SPEECH_MODE_NAME_LOUDSPK QUOTE(Loud Speaker Mode)
#define SPEECH_MODE_NAME_BT_EARPHONE QUOTE(BlueTooth Earphone Mode)
#define SPEECH_MODE_NAME_BT_CORDLESS QUOTE(BuleTooth Cordless Mode)
#define SPEECH_MODE_NAME_BT_CARKIT QUOTE(BT Carkit Mode)
#define SPEECH_MODE_NAME_AUX1 QUOTE(AUX1 Mode)
#define SPEECH_MODE_NAME_AUX2 QUOTE(AUX2 Mode)

#if defined(__HD_RECORD__)
extern const char HD_RECORD_MODE_NAMES[NUM_RECORD_SPH_MODE][LEN_OF_ENHANCEMENT_MODE_NAME];
#endif //__HD_RECORD__
/**
	user: should be META only
	(realted to customer folder)

	@inputBufLength: [Input] the length of result buffer provided by caller. 
	  The value of "inputBufLength" and "@return * LEN_OF_ENHANCEMENT_MODE_NAME" should be equal. 	
	@nameResult: [Output] An array of names for different enhancement modes
	  (for every record, the max length is LEN_OF_ENHANCEMENT_MODE_NAME, i.e. 30) 
	@return: number of all enhancement mode sets, when <= 0, it means some error occur when function execution
*/
int16 L1SP_GetAllEnhancementModeName(int16 inputBufLength, char *nameResult)

{
	int16 totalModeNum; 
	
	char result[(8
#if defined(__HD_RECORD__)
		+NUM_RECORD_SPH_MODE
#endif //__HD_RECORD__
		)][LEN_OF_ENHANCEMENT_MODE_NAME];

	totalModeNum = L1SP_GetNumOfAllEnhancementMode();

	//erro handling when result buffer size is too small
	if(inputBufLength < (totalModeNum*LEN_OF_ENHANCEMENT_MODE_NAME)){
		return -1;
	}
	
	{
		char temp[LEN_OF_ENHANCEMENT_MODE_NAME] = SPEECH_MODE_NAME_NORMAL;
		memcpy(result[0], temp, LEN_OF_ENHANCEMENT_MODE_NAME*sizeof(char));
	}
	{
		char temp[LEN_OF_ENHANCEMENT_MODE_NAME] = SPEECH_MODE_NAME_EARPHONE;
		memcpy(result[1], temp, LEN_OF_ENHANCEMENT_MODE_NAME*sizeof(char));
	}
	{
		char temp[LEN_OF_ENHANCEMENT_MODE_NAME] = SPEECH_MODE_NAME_LOUDSPK;
		memcpy(result[2], temp, LEN_OF_ENHANCEMENT_MODE_NAME*sizeof(char));
	}
	{
		char temp[LEN_OF_ENHANCEMENT_MODE_NAME] = SPEECH_MODE_NAME_BT_EARPHONE;
		memcpy(result[3], temp, LEN_OF_ENHANCEMENT_MODE_NAME*sizeof(char));
	}
	{
		char temp[LEN_OF_ENHANCEMENT_MODE_NAME] = SPEECH_MODE_NAME_BT_CORDLESS;
		memcpy(result[4], temp, LEN_OF_ENHANCEMENT_MODE_NAME*sizeof(char));
	}
	{
		char temp[LEN_OF_ENHANCEMENT_MODE_NAME] = SPEECH_MODE_NAME_BT_CARKIT;
		memcpy(result[5], temp, LEN_OF_ENHANCEMENT_MODE_NAME*sizeof(char));
	}
	{
		char temp[LEN_OF_ENHANCEMENT_MODE_NAME] = SPEECH_MODE_NAME_AUX1;
		memcpy(result[6], temp, LEN_OF_ENHANCEMENT_MODE_NAME*sizeof(char));
	}
	{
		char temp[LEN_OF_ENHANCEMENT_MODE_NAME] = SPEECH_MODE_NAME_AUX2;
		memcpy(result[7], temp, LEN_OF_ENHANCEMENT_MODE_NAME*sizeof(char));
	}

#if defined(__HD_RECORD__)
	if(NUM_RECORD_SPH_MODE > 0)
		memcpy(result[8], HD_RECORD_MODE_NAMES, NUM_RECORD_SPH_MODE*LEN_OF_ENHANCEMENT_MODE_NAME*sizeof(char));
#endif

	memcpy(nameResult, result, totalModeNum*LEN_OF_ENHANCEMENT_MODE_NAME*sizeof(char));
		
	return totalModeNum;
}

//=============================================================================
#ifdef __HD_RECORD__
extern const char HD_RECORD_MODE_CATEGORY_NAME[NUM_RECORD_SPH_MODE_CATEGORY][LEN_OF_ENHANCEMENT_CATEGORY_NAME];
#endif

/**
	user: should be META only
	(realted to customer folder)

	@inputBufLength: [Input] the length of result buffer provided by caller. 
	  The value of "inputBufLength" and "@return * LEN_OF_ENHANCEMENT_CATEGORY_NAME" should be equal. 	
	@categoryName: [Output] An array indicate each tab's name. For example, 
	                        tab 0 is named "in-call"; tab 1 is named "voice-record"; Tab 2 is named "video-record"
	                        The max length of name is LEN_OF_ENHANCEMENT_CATEGORY_NAME, i.e. 20. 
	@return: number of enhancement categories, when <= 0, it means some error occur when function execution

*/
int16 L1SP_GetAllEnhancementCategoryName(int16 inputBufLength, char *categoryName)
{
	char result[(1
#if defined(__HD_RECORD__)		
		+NUM_RECORD_SPH_MODE_CATEGORY
#endif //__HD_RECORD__
		)][LEN_OF_ENHANCEMENT_CATEGORY_NAME];

	int16 catgNum = L1SP_GetNumOfAllEnhancementCategory();
	
	//error handling when result buffer is too small
	if(inputBufLength < (catgNum*LEN_OF_ENHANCEMENT_CATEGORY_NAME)){
		return -1;
	}
	
	{
		char temp[LEN_OF_ENHANCEMENT_CATEGORY_NAME] = "In-call";
		memcpy(result[0], temp, LEN_OF_ENHANCEMENT_CATEGORY_NAME*sizeof(char));
	}

#if defined(__HD_RECORD__)
	memcpy(result[1], HD_RECORD_MODE_CATEGORY_NAME, NUM_RECORD_SPH_MODE_CATEGORY*LEN_OF_ENHANCEMENT_CATEGORY_NAME*sizeof(char));
#endif

	memcpy(categoryName, result, catgNum*LEN_OF_ENHANCEMENT_CATEGORY_NAME*sizeof(char));	

	return catgNum;
}

//=============================================================================

/**
	user: should be META only
	(realted to customer folder)
	
	@return: number of all enhancement category
*/
int16 L1SP_GetNumOfAllEnhancementCategory(void)
{
		return ( 1 
#if defined(__HD_RECORD__)
		+ NUM_RECORD_SPH_MODE_CATEGORY
#endif  //__HD_RECORD__
		);
}

//=============================================================================

/**
	user: should be META only
	(realted to customer folder)
		
	@inputBufLength: [Input] the length of result buffer provided by caller. 
	  The value of "inputBufLength" and "@return * 1" should be equal, because number of param is a 1D array. 	
	@paramNumOfCatg: [Output] An array indicate the number of enhancement mode parameters in each tab's (i.e. category). 
	  For example, category 0 has 32 parameters in each mode; category 1 has 16 parameters in each mode
	@return:  number of enhancement categories, when <= 0, it means some error occur when function execution
	
*/
int16 L1SP_GetNumOfAllEnhancementCategoryParam(int16 inputBufLength, int16 *paramNumOfCatg)
{
	int16 i;
	int16 totalResultNum = L1SP_GetNumOfAllEnhancementCategory();

	//error handling
	if(inputBufLength < (totalResultNum*1)){
		return -1;
	}

	//others
#ifdef __AMRWB_LINK_SUPPORT__
	paramNumOfCatg[0] = NUM_MODE_PARAS*2;
#else //NB only
	paramNumOfCatg[0] = NUM_MODE_PARAS;
#endif //__AMRWB_LINK_SUPPORT__

	for(i=1; i< totalResultNum; i++) {
		paramNumOfCatg[i] = NUM_MODE_PARAS;
	}

	return totalResultNum;
	

}

//=============================================================================

static void l1sp_getFirMappingByScene(const uint32 scene, 
	uint8 *devMode, uint8 *enhMode,
	uint8 *inFir, uint8 *outFir)
{
	uint8 tempDevMode = 0xff; 
	uint8 tempEnhMode = 0xff;
	uint8 tempInFir = 0xff; 
	uint8 tempOutFir = 0xff;
	
	switch(scene) {
	case SPH_ENH_AND_FIR_SCENE_NORMAL:
		tempDevMode = SPH_MODE_NORMAL;
		tempEnhMode = SPH_MODE_NORMAL;
		tempInFir = SPH_FIR_COEFF_NORMAL;
#if defined(__SMART_PHONE_MODEM__)
		tempOutFir = SPH_FIR_COEFF_NORMAL;
#else
		tempOutFir = l1sp.sph_selectedOutFirIndex; //using enginerning mode's setting for the FIR index
#endif
		
		break;
	case SPH_ENH_AND_FIR_SCENE_EARPHONE:
	case SPH_ENH_AND_FIR_SCENE_LOUDSPK:
		tempDevMode = scene;
		tempEnhMode = scene;
		tempInFir = scene;
		tempOutFir = scene;
		break;	
#if defined(__BT_SUPPORT__)		
	case SPH_ENH_AND_FIR_SCENE_BT_EARPHONE:
	case SPH_ENH_AND_FIR_SCENE_BT_CORDLESS:
	case SPH_ENH_AND_FIR_SCENE_BT_CARKIT:
		tempDevMode = scene;
		tempEnhMode = scene;
		tempInFir = SPH_FIR_COEFF_BT; 
		tempOutFir = SPH_FIR_COEFF_BT;
		break;
#endif
	case SPH_ENH_AND_FIR_SCENE_AUX1:
		tempDevMode = SPH_MODE_AUX1; //scene
		tempEnhMode = SPH_MODE_AUX1; //scene
		tempInFir = SPH_FIR_COEFF_VOIP_NORMAL;
		tempOutFir = SPH_FIR_COEFF_VOIP_NORMAL;
		break;
	case SPH_ENH_AND_FIR_SCENE_AUX2:
		tempDevMode = SPH_MODE_AUX2;
		tempEnhMode = SPH_MODE_AUX2;
		tempInFir = SPH_FIR_COEFF_VOIP_HANDFREE;
		tempOutFir = SPH_FIR_COEFF_VOIP_HANDFREE;
		break;
#ifndef __SMART_PHONE_MODEM__
	case SPH_ENH_AND_FIR_SCENE_LINEIN_VIA_BT_CORDLESS:
		tempDevMode = SPH_MODE_LINEIN_VIA_BT_CORDLESS;
		tempEnhMode = SPH_MODE_LINEIN_VIA_BT_CORDLESS;
		tempInFir = SPH_FIR_COEFF_BT; 
		tempOutFir = SPH_FIR_COEFF_BT;
		break;

	//VOIP related
	case SPH_ENH_AND_FIR_SCENE_VOIP_NORMAL:
		tempDevMode = SPH_MODE_AUX1;
		tempEnhMode = SPH_MODE_AUX1;
		tempInFir = SPH_FIR_COEFF_VOIP_NORMAL;
		tempOutFir = SPH_FIR_COEFF_VOIP_NORMAL;
		break;
	case SPH_ENH_AND_FIR_SCENE_VOIP_LOADSPK:
		tempDevMode = SPH_MODE_AUX2;
		tempEnhMode = SPH_MODE_AUX2;
		tempInFir = SPH_FIR_COEFF_VOIP_HANDFREE;
		tempOutFir = SPH_FIR_COEFF_VOIP_HANDFREE;
		break;
		
	//CTM related
	case SPH_ENH_AND_FIR_SCENE_CTM_BAUDOT:		
	case SPH_ENH_AND_FIR_SCENE_CTM_DIRECT:
		tempDevMode = l1sp.sph_mode; 
		tempEnhMode = l1sp.sph_mode;
		//use default	
		break;

	//CTM HCO
	case SPH_ENH_AND_FIR_SCENE_CTM_HCO_NORMAL: // using Eng Mode's selected_FIR_output_index to decide which is 		
		tempDevMode = SPH_MODE_NORMAL;
		tempEnhMode = SPH_MODE_NORMAL;
#if defined(__SMART_PHONE_MODEM__)
		tempOutFir = SPH_FIR_COEFF_NORMAL;
#else		
		tempOutFir = l1sp.sph_selectedOutFirIndex;
#endif
		break;
	case SPH_ENH_AND_FIR_SCENE_CTM_HCO_EARPHONE:
		tempDevMode = SPH_MODE_EARPHONE;
		tempEnhMode = SPH_MODE_EARPHONE;
		tempOutFir = SPH_FIR_COEFF_HEADSET; 	
		break;
	case SPH_ENH_AND_FIR_SCENE_CTM_HCO_LOUDSPK:
		tempDevMode = SPH_MODE_LOUDSPK;
		tempEnhMode = SPH_MODE_LOUDSPK;
		tempOutFir = SPH_FIR_COEFF_HANDFREE;
		break;
	case SPH_ENH_AND_FIR_SCENE_CTM_HCO_BT:
		tempDevMode = SPH_MODE_BT_EARPHONE;
		tempEnhMode = SPH_MODE_BT_EARPHONE;
		tempOutFir = SPH_FIR_COEFF_BT;
		break;
	case SPH_ENH_AND_FIR_SCENE_CTM_HCO_VOIP_NORMAL:
		tempDevMode = SPH_MODE_AUX1;
		tempEnhMode = SPH_MODE_AUX1;
		tempOutFir = SPH_FIR_COEFF_VOIP_NORMAL;
		break;
	case SPH_ENH_AND_FIR_SCENE_CTM_HCO_VOIP_LOUDSPK:
		tempDevMode = SPH_MODE_AUX2;
		tempEnhMode = SPH_MODE_AUX2;
		tempOutFir = SPH_FIR_COEFF_VOIP_HANDFREE;
		break;

	//CTM VCO
	case SPH_ENH_AND_FIR_SCENE_CTM_VCO_NORMAL:
		tempDevMode = SPH_MODE_NORMAL;
		tempEnhMode = SPH_MODE_NORMAL;
		tempInFir = SPH_FIR_COEFF_NORMAL;
		break;
	case SPH_ENH_AND_FIR_SCENE_CTM_VCO_EARPHONE:
		tempDevMode = SPH_MODE_EARPHONE;
		tempEnhMode = SPH_MODE_EARPHONE;
		tempInFir = SPH_FIR_COEFF_HEADSET;	
		break;
	case SPH_ENH_AND_FIR_SCENE_CTM_VCO_LOUDSPK:
		tempDevMode = SPH_MODE_LOUDSPK;
		tempEnhMode = SPH_MODE_LOUDSPK;
		tempInFir = SPH_FIR_COEFF_HANDFREE;
		break;
	case SPH_ENH_AND_FIR_SCENE_CTM_VCO_BT:
		tempDevMode = SPH_MODE_BT_EARPHONE;
		tempEnhMode = SPH_MODE_BT_EARPHONE;
		tempInFir = SPH_FIR_COEFF_BT;
		break;
	case SPH_ENH_AND_FIR_SCENE_CTM_VCO_VOIP_NORMAL:
		tempDevMode = SPH_MODE_AUX1;
		tempEnhMode = SPH_MODE_AUX1;
		tempInFir = SPH_FIR_COEFF_VOIP_NORMAL;
		break;
	case SPH_ENH_AND_FIR_SCENE_CTM_VCO_VOIP_LOUDSPK:
		tempDevMode = SPH_MODE_AUX2;
		tempEnhMode = SPH_MODE_AUX2;
		tempInFir = SPH_FIR_COEFF_VOIP_HANDFREE;
		break;
		

#endif //NOT __SMART_PHONE_MODEM__		
	default:
	{
#if defined(__HD_RECORD__) && (!defined(__SMART_PHONE_MODEM__)) //Only for feature phone use
		if(scene>SPH_ENH_AND_FIR_SCENE_CTM_VCO_VOIP_LOUDSPK && l1sp.numOfRecordMode>0){					
			tempEnhMode = (scene-SPH_ENH_AND_FIR_SCENE_INCALL_END)-1;
			tempDevMode = l1sp.recordModeDeviceMapping[tempEnhMode];
			tempInFir = l1sp.recordModeFirMappingCh1[tempEnhMode];
#if defined(__STEREO_RECORD__)
			tempOutFir = l1sp.recordModeFirMappingCh2[tempEnhMode];
#else
			tempOutFir = l1sp.sph_mode; //use original setting
#endif //__STEREO_RECORD__

		} else 

#endif //defined(__HD_RECORD__) && (!defined(__SMART_PHONE_MODEM__))
		{
			ASSERT(0);
		}
	}
	}
	
	*devMode = tempDevMode;
	*enhMode = tempEnhMode;
	*inFir = tempInFir;
	*outFir = tempOutFir;
	
}

static uint16 l1sp_InternalInWbFirs[NUM_WB_FIR_COEFFS];
static uint16 l1sp_InternalOutWbFirs[NUM_WB_FIR_COEFFS];

/**
	new interface to replace L1SP_SetSpeechMode(), L1SP_Write_Audio_Coefficients(), 
	L1SP_Write_WB_Audio_Coefficients() in the same time. 

	if you want to use personal configuration, you can use original interfaces. 

	@scene: [Input] scenario for different enhancement and fir combination. Please refer to "SPH_ENH_AND_FIR_SCENE"
	@updatedCoeff: [Input] Please refer to "SPH_ENH_AND_FIR_UPDATE_TYPE"
*/
void L1SP_SetSpeechEnhanceAndFir(kal_uint32 scene, kal_uint32 updatedCoeff)
{
	uint8 modeIndex = 0;
	uint8 inFirIndex = 0;
	uint8 outOrIn2FirIndex = 0;
	uint8 devModeIndex = 0;

	//speech mode
//----------------- original scenario ---------------	
#ifdef __SMART_PHONE_MODEM__
	if(scene<SPH_MODE_UNDEFINED)
#else //feature phone
	if(scene <= SPH_ENH_AND_FIR_SCENE_CTM_VCO_VOIP_LOUDSPK)
#endif //__SMART_PHONE_MODEM__
	{ 
		//keeping the original scenario
		l1sp_getFirMappingByScene(scene, &devModeIndex, &modeIndex, 
			&inFirIndex, &outOrIn2FirIndex);

#if defined(__AMRWB_LINK_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
		//speech mode
		if((SPH_ENH_AND_FIR_UPDATE_TYPE_ALL == updatedCoeff) 
			|| (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_WB_ENH_MODE)!=0){
			if(l1sp.setNvramValuesFlag & L1SP_NVRAM_VALUES_FLAG_WB_MODE)//(l1sp.has_all_wb_sph_m_para)
				L1SP_SetWbSpeechPara(l1sp.sph_allWbModePara[modeIndex]);
		}
#endif //defined(__AMRWB_LINK_SUPPORT__)  || defined(__SMART_PHONE_MODEM__)

		if((SPH_ENH_AND_FIR_UPDATE_TYPE_ALL == updatedCoeff) 
			|| (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_NB_ENH_MODE)!=0){
			L1SP_SetSpeechMode(devModeIndex, l1sp.sph_allModePara[modeIndex]);
		}

		// Write NB FIR
		if((SPH_ENH_AND_FIR_UPDATE_TYPE_ALL == updatedCoeff) 
			|| (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_NB_FIR)!=0){
			//L1SP_Write_Audio_Coefficients(l1sp.sph_allInFirCoeff[inFirIndex],
				//l1sp.sph_allOutFirCoeff[outOrIn2FirIndex]);
			L1SP_Write_Audio_Coefficients_ByFirIndex(inFirIndex, outOrIn2FirIndex);
		}

#if defined(__AMRWB_LINK_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
		if((SPH_ENH_AND_FIR_UPDATE_TYPE_ALL == updatedCoeff) 
			|| (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_WB_FIR)!=0){
			if((l1sp.setNvramValuesFlag & L1SP_NVRAM_VALUES_FLAG_WB_IN_FIR)
				&& (l1sp.setNvramValuesFlag & L1SP_NVRAM_VALUES_FLAG_WB_OUT_FIR)) {
				//(l1sp.has_all_wb_sph_in_FIR_coeffs && l1sp.has_all_wb_sph_out_FIR_coeffs) {
				L1SP_Write_WB_Audio_Coefficients(l1sp.sph_allWbInFirCoeff[inFirIndex],
					l1sp.sph_allWbOutFirCoeff[outOrIn2FirIndex]);
			}
		}
#endif //defined(__AMRWB_LINK_SUPPORT__)  || defined(__SMART_PHONE_MODEM__)
	}

//----------------- recording scenario ---------------
#if defined(__SMART_PHONE_MODEM__) || defined(__HD_RECORD__)

#if defined(__SMART_PHONE_MODEM__) 
	else if (scene>=SPH_MODE_UNDEFINED && scene <= (SPH_MODE_UNDEFINED + l1sp.numOfRecordMode))
#elif defined(__HD_RECORD__) //feature phone
	else if (scene>SPH_ENH_AND_FIR_SCENE_CTM_VCO_VOIP_LOUDSPK && scene < (SPH_ENH_AND_FIR_SCENE_CTM_VCO_VOIP_LOUDSPK + l1sp.numOfRecordMode))
#endif
	{
		uint16 emDebugInfo = L1Audio_GetDebugInfo(AMR_REC_DEBUG_INFO);

		//get the mode params		
#if defined(__SMART_PHONE_MODEM__)
		modeIndex = scene - SPH_MODE_UNDEFINED;
		devModeIndex = l1sp.recordModeDeviceMapping[modeIndex];	
		
		outOrIn2FirIndex = 0xff; 
		if(l1sp.recordModeFirMappingCh1 == NULL) {
			inFirIndex = 0xff;
		} else {			
			inFirIndex = l1sp.recordModeFirMappingCh1[modeIndex];
#if defined(__DUAL_MIC_SUPPORT__)
			outOrIn2FirIndex = l1sp.recordModeFirMappingCh2[modeIndex];
#endif
		}
#else //only for feature phone usage
		l1sp_getFirMappingByScene(scene, &devModeIndex, &modeIndex, 
			&inFirIndex, &outOrIn2FirIndex);
#endif //__SMART_PHONE_MODEM__

		//update the enhancement paramters
		if(emDebugInfo&0x1) { //when debug info parameter2 bit0 = 1, using NB normal mode parameter
			modeIndex = SPH_MODE_NORMAL;
			devModeIndex = SPH_MODE_NORMAL;
			if((SPH_ENH_AND_FIR_UPDATE_TYPE_ALL == updatedCoeff) 
				|| (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_WB_ENH_MODE)!=0){
				L1SP_SetWbSpeechPara(l1sp.sph_allModePara[SPH_MODE_NORMAL]); // REMIND: "NB" paramter
			}
			
			if((SPH_ENH_AND_FIR_UPDATE_TYPE_ALL == updatedCoeff) 
				|| (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_NB_ENH_MODE)!=0) {
				L1SP_SetSpeechMode(SPH_MODE_NORMAL, l1sp.sph_allModePara[SPH_MODE_NORMAL]);
			}
		} else {
			if((SPH_ENH_AND_FIR_UPDATE_TYPE_ALL == updatedCoeff) 
				|| (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_WB_ENH_MODE)!=0){
				L1SP_SetWbSpeechPara(l1sp.recordModePara[modeIndex]); 
			}
			if((SPH_ENH_AND_FIR_UPDATE_TYPE_ALL == updatedCoeff) 
				|| (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_NB_ENH_MODE)!=0) {
				L1SP_SetSpeechMode(devModeIndex, l1sp.recordModePara[modeIndex]); //Send mode parameter to DSP. 
			}
		}
				

		// Write NB FIR
		//for recording, DSP only use WB FIR, the parameters just keep safe. by using "all pass fir"
		if((SPH_ENH_AND_FIR_UPDATE_TYPE_ALL == updatedCoeff) 
			|| (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_NB_FIR)!=0) {
			uint8 finalIndex1, finalIndex2; 
			
			finalIndex1 = 0xff;
			finalIndex2 = 0xff;
			
			L1SP_Write_Audio_Coefficients_ByFirIndex(finalIndex1, finalIndex2);
		}

		// Write WB FIR		
		if((SPH_ENH_AND_FIR_UPDATE_TYPE_ALL == updatedCoeff) 
			|| (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_WB_FIR)!=0){
			int16 *inFirs;
			int16 *outFirs;

			//first mic
			if(inFirIndex == 0xff || inFirIndex >= l1sp.numOfRecordInFir) {
				inFirs = l1sp_InternalInWbFirs;
				memset(inFirs, 0, (NUM_WB_FIR_COEFFS)*sizeof(int16));
				inFirs[0] = 0x7fff;
			} else {
				inFirs = l1sp.recordInFirCoeff[inFirIndex];
			}

			// 2nd mic
			if(outOrIn2FirIndex == 0xff || outOrIn2FirIndex>= l1sp.numOfRecordInFir) {
				outFirs = l1sp_InternalOutWbFirs;
				memset(outFirs, 0, (NUM_WB_FIR_COEFFS)*sizeof(int16));
				outFirs[0] = 0x7fff;
			} else  {
				outFirs = l1sp.recordInFirCoeff[outOrIn2FirIndex];
			}

			L1SP_Write_WB_Audio_Coefficients(inFirs, outFirs);

		}		
		
	}
#endif //defined(__SMART_PHONE_MODEM__) || defined(__HD_RECORD__)

//---------------------- undefined cases --------------------
	else {

		kal_trace ( TRACE_INFO, L1SP_USELESS_SET, 0, scene, 0, 0);
	}
	kal_trace( TRACE_INFO, L1SP_SET_ENH_FIR, scene, modeIndex, inFirIndex, outOrIn2FirIndex, l1sp.spe_app_mask);
	
}

//=============================================================================

void L1SP_SetWbSpeechPara( uint16 m_para[NUM_MODE_PARAS] )
{
   memcpy( &(l1sp.sph_m_para[NUM_MODE_PARAS]), m_para, NUM_MODE_PARAS*sizeof(uint16));
   kal_trace( TRACE_INFO, L1SP_WB_SPEECH_ENHANCEMENT, m_para[0], m_para[1], m_para[2], m_para[3]);
}

kal_bool setCommonPara = KAL_FALSE;
uint16 commonPara_0 = 0;

void L1SP_SetSpeechMode( uint8 mode, uint16 m_para[NUM_MODE_PARAS] )
{
   uint8 prev_sph_mode = l1sp.sph_mode;

   if( prev_sph_mode != mode && ( AM_IsSpeechOn() || AM_IsVMPlaybackOn() ) )
   {
      TONE_StopAndWait();
      KT_StopAndWait();
   }
   l1sp.sph_mode = mode;

#if defined(__BT_SUPPORT__)
   if((l1sp.bt_on) && (prev_sph_mode != mode))
   {
      AM_BluetoothOff();
      l1sp.bt_on = false;
   }
#endif
   
#ifdef L1D_TEST
   SAC_SphModePar.pi2EMPMode = (kal_int16 *)mode_Para_Unitest;
#else
   memcpy(l1sp.sph_m_para, m_para, NUM_MODE_PARAS*sizeof(uint16));
#endif
#if defined(__BT_SUPPORT__)
   if( (mode == SPH_MODE_BT_EARPHONE) || (mode==SPH_MODE_BT_CORDLESS) || 
      (mode==SPH_MODE_BT_CARKIT) || (mode==SPH_MODE_LINEIN_VIA_BT_CORDLESS) )
   {
      SAC_SphBluetoothPar.u4BtMod  = SPH_BT_MODE_LINEAR;
      SAC_SphBluetoothPar.u4BtDgUl = 0x1000; //0dB
      SAC_SphBluetoothPar.u4BtDgDl = 0x1000; //0dB
      SAC_SphBluetoothPar.u4BitRev = 0;
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_BT_CONFIG, sizeof(SAC_SphBluetoothPar_t), (kal_uint32)&SAC_SphBluetoothPar);
      if( mode==SPH_MODE_BT_CORDLESS )
         AM_BluetoothOn(1);
      else
         AM_BluetoothOn(0);
      l1sp.bt_on = true;
   }
#endif
   SAC_SphModePar.u4EMPModeLen = NUM_MODE_PARAS * 2;
   SAC_SphModePar.u4DevMode = l1sp.sph_mode;
   SAC_SphModePar.u4VbiBndCfg = SPH_FIX_DEV_BAND_WB;//for VBI, fix WB
   SAC_SphModePar.u4DaiBndCfg = SPH_FIX_DEV_BAND_NB;
   L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_SET_MODE, sizeof(SAC_SphModePar_t), (kal_uint32)&SAC_SphModePar, true);
   SetSpeechEnhancement( true );
   kal_trace( TRACE_INFO, L1SP_SET_MODE, l1sp.sph_mode, l1sp.sph_level, l1sp.mic_volume );
   if(setCommonPara)
      SAC_SphCommonPar.pi2EMPCom[0] = commonPara_0;
   L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_CONFIG, sizeof(SAC_SphComPar_t), (kal_uint32)&SAC_SphCommonPar, true);
   
   {//to printf para for debug      
      kal_trace(TRACE_INFO, L1MCU2DSP_FUNC6);    
      L1SP_DebugPrintModeParas();   
   }
}

void L1SP_SetOutputDevice( uint8 device )
{
   AFE_SetOutputDevice( L1SP_SPEECH, device );   
}

void L1SP_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
   l1sp.sph_dl_vol = volume1;
   AFE_SetOutputVolume( L1SP_SPEECH, volume1, digital_gain_index );   
}

#if defined(__GAIN_TABLE_SUPPORT__)
void L1SP_SetOutputGainControl( uint32 gain )
{
   //l1sp.sph_dl_vol = volume1;//Need take care here
   AFE_SetOutputGainControl( L1SP_SPEECH, gain );
}
#endif

void L1SP_SetSpeechVolumeLevel( kal_uint8 level, kal_uint16 v_para[NUM_VOL_PARAS] )
{
   if( level<MAX_VOL_LEVEL ) {
      l1sp.sph_level = level;
      memcpy(l1sp.sph_v_para, v_para, NUM_VOL_PARAS*sizeof(uint16));
      kal_trace( TRACE_INFO, L1SP_SET_MODE, l1sp.sph_mode, l1sp.sph_level, l1sp.mic_volume );
      SetSpeechEnhancement( true );
   }
}

/**
	this function is to replace L1SP_SetSpeechVolumeLevel()
	
	@level: [input] speech volume level for speech
	@v_paraIndex: [input] volume paramter (saving in nvram) index
*/
void L1SP_SetSpeechVolumeLevelByIndex(kal_uint8 level, kal_uint8 v_paraIndex)
{
	L1SP_SetSpeechVolumeLevel(level, l1sp.sph_allVolumePara[v_paraIndex][level]);
}


void L1SP_SetInputSource( uint8 src )
{
   AFE_SetInputSource( src );
}

uint8 L1SP_GetInputSource( void )
{
   return AFE_GetInputSource();
}

void L1SP_SetMicrophoneVolume( uint8 mic_volume )
{
   if( mic_volume == 0 )// special case when mic_volume = 0, mute microphone
      AFE_MuteMicrophone( KAL_TRUE );
   else if( !l1sp.isULMute )
      AFE_MuteMicrophone( KAL_FALSE );

   kal_trace( TRACE_INFO, L1SP_SET_MIC_VOL, mic_volume, l1sp.sph_m_para[4]);	
   {
      if(mic_volume > 8)
         mic_volume -= 8;//down 2 dB
      else
         mic_volume = 0;
   }
   kal_trace( TRACE_INFO, L1SP_ADAPT_MIC_VOL, mic_volume);

   AFE_SetMicrophoneVolume( mic_volume );
   l1sp.mic_volume = mic_volume;
   
   SetSpeechEnhancement( true );
}

#if defined(__GAIN_TABLE_SUPPORT__)
void L1SP_SetMicGainControl( uint32 mic_gain )
{
   //kal_trace( TRACE_INFO, L1SP_SET_MIC_VOL, mic_volume, l1sp.sph_m_para[4]);
   kal_uint32 mic_volume = mic_gain >> 26;
   kal_trace( TRACE_INFO, L1SP_SET_MIC_GAIN_CONTROL, mic_gain);
   if( (l1sp.sph_m_para[4] & 0x2000) ){
      if(mic_volume >= 10)
         mic_volume -= 10;//down 10 dB
      else
         mic_volume = 0;
   }
   mic_gain = (mic_gain & 0x03FFFFFF) | (mic_volume << 26);
   //kal_trace( TRACE_INFO, L1SP_ADAPT_MIC_VOL, mic_volume);	
   kal_trace( TRACE_INFO, L1SP_ADAPT_MIC_GAIN_CONTROL, mic_gain);

   AFE_SetMicGainControl( mic_gain );
   
   SetSpeechEnhancement( true );
}
#endif

uint8 L1SP_GetMicrophoneVolume( void )
{
   return AFE_GetMicrophoneVolume();
}

void L1SP_SetSidetoneVolume( uint8 sidetone )
{
   AFE_SetSidetoneVolume( sidetone );
}

uint8 L1SP_GetSidetoneVolume( void )
{
   return AFE_GetSidetoneVolume();
}

void L1SP_MuteMicrophone( bool mute )
{
   //AFE_MuteMicrophone( mute ); // do not use AFE_MuteMicrophone for speech enhancement
   AM_MuteULSpeech( mute );
   l1sp.isULMute = mute;
}

void L1SP_MuteSpeaker( bool mute )
{
   AFE_MuteSpeaker( L1SP_SPEECH, mute );
}

bool L1SP_IsMicrophoneMuted( void )
{
   return AM_IsULSpeechMuted();
}

extern void CSR_SP3G_Callback( SP3G_Event event, void *data );
extern void vt_SP3G_Callback( kal_uint8 event, void *data );

#if defined( __UMTS_RAT__ )
void L1SP_3G_Request(void)
{  
   if(l1sp.state ==  L1SP_STATE_3G_SPEECH_ON)
   {
      CSR_SP3G_Callback(SP3G_CODEC_READY, (void*)SP3G_Rab_Id());
      return;
   }
}
#endif

void L1SP_SetState(uint8 state)
{
#if defined( __UMTS_RAT__ )
   if( ( l1sp.state == L1SP_STATE_3G_SPEECH_ON && state == L1SP_STATE_2G_SPEECH_ON ) ||
      ( l1sp.state == L1SP_STATE_2G_SPEECH_ON && state == L1SP_STATE_3G_SPEECH_ON ) )
      l1sp.interRAT = true;
#endif
   l1sp.state = state; 
   L1Audio_Msg_Speech_State(L1Audio_Speech_State(state));
}

uint8 L1SP_GetState( void )
{
   return l1sp.state; 
}

void L1SP_Send2GSpeechOn(void)
{
   L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_2G_CALL_ON, l1sp.fc_aud_id, (kal_uint32)&SAC_Sph2GCallPar, KAL_TRUE );
   L1SP_MuteMicrophone( l1sp.isULMute );
}
void L1SP_Send2GSpeechOff(void)
{
   L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_2G_CALL_OFF, l1sp.fc_aud_id, 0, KAL_TRUE );
}

void L1SP_Send3GSpeechOn(void)
{
   //SAC_Sph3GCallPar updated in sp3g_speech_init
   L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_3G_CALL_ON, l1sp.fc_aud_id, (kal_uint32)&SAC_Sph3GCallPar, KAL_TRUE );
   L1SP_MuteMicrophone( l1sp.isULMute );
}
void L1SP_Send3GSpeechOff(void)
{
   L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_3G_CALL_OFF, l1sp.fc_aud_id, 0, KAL_TRUE );
}

extern SAC_SphHandoverPar_t SAC_SphHandoverPar;
extern uint8  sp3g_codec_mode;
static void L1SP_InterRAT_Handler( void *data )
{
#if defined( __UMTS_RAT__ )
   if( l1sp.state == L1SP_STATE_2G_SPEECH_CLOSING || l1sp.state == L1SP_STATE_3G_SPEECH_CLOSING )
      return;
   if(data == 0){// G2W
      AM_InterRAT_G2W();
      L1SP_SetState( L1SP_STATE_3G_SPEECH_ON );
   } else {      //W2G
      AM_InterRAT_W2G();
      L1SP_SetState( L1SP_STATE_2G_SPEECH_ON );
   }
#endif   
}

extern void sp3gMsgHandler(kal_uint16 msgOp, kal_uint32 msgData, void *userData);
void l1spMsgHandler(kal_uint16 msgOp, kal_uint32 msgData, void *userData)
{
   if(msgOp == MSG_SAC2L1AUDIO_SPEECH_BT_CORDLESS_ON_ACK || msgOp == MSG_SAC2L1AUDIO_SPEECH_BT_CORDLESS_OFF_ACK)
   {
   	  L1Audio_FC_SetWait( KAL_FALSE );
      return;
   }
#if defined( __UMTS_RAT__ )
   sp3gMsgHandler(msgOp, msgData, userData);
#endif
}

void L1SP_Cordless_On( void )
{
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   
#if !(defined(MT6573) || defined(MT6575) || defined(MT6577))
   TONE_StopAndWait();
   KT_StopAndWait();
#endif

#ifdef BGSND_ENABLE
   if (l1sp.sndOffHandler != NULL)
      l1sp.sndOffHandler( l1sp.sndHdl );
#endif
/*workaround for SPEECH DSP MAIN/AUX Mode Task in FCORE*/   
   
   l1sp.aud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( l1sp.aud_id );     /* To lock sleep mode */
   l1sp.fc_aud_id = L1Audio_FC_HookHandler( 0, l1spMsgHandler, 1, 0 );
   SAC_SphBtCordlessPar.u4Wb = 0;
   L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_BT_CORDLESS_ON, l1sp.fc_aud_id, (kal_uint32)&SAC_SphBtCordlessPar, KAL_TRUE);
   AM_BTCordlessOn();
}

void L1SP_Cordless_Off( void )
{
   L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_BT_CORDLESS_OFF, l1sp.fc_aud_id, 0, KAL_TRUE);
   L1Audio_FC_UnHookHandler(l1sp.fc_aud_id, 1);
   L1Audio_ClearFlag( l1sp.aud_id );
   L1Audio_FreeAudioID( l1sp.aud_id );
   AM_BTCordlessOff();
}

kal_bool L1SP_IsSpeechOn( void )
{
    return (AM_IsSpeechOn());
}

bool voc_flag = false;

static uint16 *voc_rb_base = NULL;

static void VOC_Handler(Media_Event event)
{
   return;
}

void L1SP_Speech_On( uint8 RAT_Mode )
{
   kal_uint32 module_id = MOD_L1AUDIO_SPH_SRV;

#if !defined(__SMART_PHONE_MODEM__) && !defined(__L1_STANDALONE__) && defined(__AUDIO_COMPONENT_SUPPORT__) && !defined( MED_MODEM )
   MixerOut_Stop_Immediate();
#endif
   if( AM_IsSpeechOn() )
      return;

   // KH 20101026 temp solution: Stop keytone/tone before speech on. DSP limitation.
#if !(defined(MT6573) || defined(MT6575) || defined(MT6577))
   TONE_StopAndWait();
   KT_StopAndWait();
#endif

#ifdef BGSND_ENABLE
   if (l1sp.sndOffHandler != NULL)
      l1sp.sndOffHandler( l1sp.sndHdl );
#endif
      
   l1sp_updateSpeAppMask(0xffff, true);
   AFE_SetDigitalGain(L1SP_SPEECH, 100);

   l1sp.aud_id = L1Audio_GetAudioID();
   L1Audio_SetEventHandler(l1sp.aud_id, L1SP_InterRAT_Handler);
   L1Audio_SetFlag( l1sp.aud_id );     /* To lock sleep mode */

#ifndef L1D_TEST
   L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_DL_VOLUME, DG_DL_Speech, 128 );
   L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_UL_VOLUME, DG_Microphone, 128 );
#endif

   l1sp.fc_aud_id = L1Audio_FC_HookHandler( (void *)RAT_Mode, l1spMsgHandler, 1, 0 );

#if defined( __UMTS_RAT__ )
#ifdef __VIDEO_CALL_SUPPORT__
   if( RAT_Mode == RAT_3G324M_MODE )
      sp3g_speech_init( RAT_3G324M_MODE );
   else
#endif
      //In Dual mode, allow 2G/3G capability at initialization stage  for InterRAT HO
      //if 3G324M, there is no InterRAT
      sp3g_speech_init( RAT_3G_MODE );

   if( SP3G_Rab_State() && RAT_Mode != RAT_3G324M_MODE ){
      RAT_Mode = RAT_3G_MODE;
   }else if ( l1sp.tch_state ){
      
      RAT_Mode = RAT_2G_MODE;
      SAC_Sph2GCallPar.u4CodModUl = AM_GetSpeechMode();
      SAC_Sph2GCallPar.u4CodModDl = SAC_Sph2GCallPar.u4CodModUl;
   }
   l1sp.interRAT = false;
#endif

   AM_SpeechOn(RAT_Mode);
   AFE_TurnOnSpeaker(L1SP_SPEECH);
   SetSpeechEnhancement( true );
   switch(RAT_Mode)
   {
      case RAT_2G_MODE:
         L1SP_SetState(L1SP_STATE_2G_SPEECH_ON);     
         break;
#if defined( __UMTS_RAT__ )
      case RAT_3G_MODE: 
         L1SP_SetState(L1SP_STATE_3G_SPEECH_ON);
         CSR_SP3G_Callback(SP3G_CODEC_READY, (void*)SP3G_Rab_Id());
         break;
#ifdef __VIDEO_CALL_SUPPORT__
      case RAT_3G324M_MODE: 
         L1SP_SetState(L1SP_STATE_3G324M_SPEECH_ON);
         vt_SP3G_Callback( (kal_uint8)SP3G_CODEC_READY, (void*)0 );
         break;
#endif
#endif
      default: 
         ASSERT(false);
   }

#if defined(__DATA_CARD_SPEECH__)
   if (l1sp.strmOnHandler != NULL)
      l1sp.strmOnHandler( NULL );
#endif

#ifdef BGSND_ENABLE
   if (l1sp.sndOnHandler != NULL)
      l1sp.sndOnHandler( l1sp.sndHdl );
#endif

   if(l1sp.onHandler != NULL)
      l1sp.onHandler( (void *)l1sp.state );

#if defined(__ECALL_SUPPORT__)
   if (l1sp.pcm4wayOnHandler != NULL)
      l1sp.pcm4wayOnHandler( (void *)0);
#endif

#ifndef __L1_STANDALONE__ // avoid link error
   if(!tst_trace_check_ps_filter_off(TRACE_GROUP_VM, &module_id, 0x2))
   {
      voc_rb_base = (uint16 *)get_ctrl_buffer(1024);
      Media_SetBuffer(voc_rb_base, 1024);
      Media_Record(MEDIA_FORMAT_GSM_EFR, VOC_Handler, (void*)0);
      voc_flag = true;
   }
#endif
}

void L1SP_Register_Service(void (*onHandler)(void *), void (*offHandler)(void *))
{
   l1sp.onHandler = onHandler;   
   l1sp.offHandler = offHandler;
}

void L1SP_UnRegister_Service( void )
{
   l1sp.onHandler = NULL;   
   l1sp.offHandler = NULL;
}

#ifdef BGSND_ENABLE
void L1SP_Register_SndService(
   void (*onHandler)(void *hdl),
   void (*offHandler)(void *hdl),
   void *hdl)
{
   l1sp.sndOnHandler  = onHandler;
   l1sp.sndOffHandler = offHandler;
   l1sp.sndHdl        = hdl;
}

void L1SP_UnRegister_SndService( void )
{
   l1sp.sndOnHandler  = NULL;
   l1sp.sndOffHandler = NULL;
}
#endif

#if defined(__DATA_CARD_SPEECH__)
void L1SP_Register_Strm_Handler(
   void (*onHandler)(void *hdl),
   void (*offHandler)(void *hdl),
   void (*hdl)(kal_uint32 event, void *param))
{
   l1sp.strmOnHandler  = onHandler;
   l1sp.strmOffHandler = offHandler;
   l1sp.strmHdl        = hdl;
}

void L1SP_UnRegister_Strm_Handler( void )
{
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
#ifndef __L1_STANDALONE__ // avoid link error
   kal_uint32 module_id = MOD_L1AUDIO_SPH_SRV;		
   if(!tst_trace_check_ps_filter_off(TRACE_GROUP_VM, &module_id, 0x2) && voc_flag)
   {
	  if( voc_rb_base != NULL )
	  {
		 free_ctrl_buffer(voc_rb_base);
		 voc_rb_base = NULL;
	  }
	  Media_Stop();
	  voc_flag = false;
   }
#endif

   if( !AM_IsSpeechOn() )
      return;

#if defined(__ECALL_SUPPORT__)
   if (l1sp.pcm4wayOffHandler != NULL)
      l1sp.pcm4wayOffHandler( (void *)0 );
#endif

#if defined(__DATA_CARD_SPEECH__)
   if (l1sp.strmOffHandler != NULL)
      l1sp.strmOffHandler( NULL );
#endif

   if(l1sp.offHandler != NULL)
      l1sp.offHandler( (void *)l1sp.state );

   SetSpeechEnhancement( false );

#if defined( __UMTS_RAT__ )
   {
      uint8 state;
      state = l1sp.state;
      if(l1sp.state == L1SP_STATE_2G_SPEECH_ON)
         L1SP_SetState(L1SP_STATE_2G_SPEECH_CLOSING);
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
            CSR_SP3G_Callback(SP3G_CODEC_CLOSED, (void*)SP3G_Rab_Id());
      }
   }
#endif
   AM_SpeechOff();
   if( l1sp.fc_aud_id != 0xFFFF ){
      L1Audio_FC_UnHookHandler(l1sp.fc_aud_id, 1);
      l1sp.fc_aud_id = 0xFFFF;
   }
   L1SP_SetState( L1SP_STATE_IDLE );
   
   L1Audio_ClearFlag( l1sp.aud_id );
   L1Audio_FreeAudioID( l1sp.aud_id );
}

void L1SP_Set_DAI_Mode( uint8 mode )
{
	//this feature is phased out
  //AM_SetDAIMode( mode );
}

void L1SP_SetAfeLoopback( bool enable )
{
   if( enable ){
      AFE_TurnOnLoopback();
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_ECHO_LOOP_TEST_START, 0, (kal_uint32)NULL);
      
   }
   else{
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_ECHO_LOOP_TEST_STOP, 0, (kal_uint32)NULL);
      AFE_TurnOffLoopback();
   }
}

/*for MIC2 loopback*/
void L1SP_SetAfeLoopback2( bool enable )
{
   if( enable ){
      AFE_TurnOnLoopback();
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_ECHO_LOOP_TEST_START, 1, (kal_uint32)NULL);
   }
   else{
      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_ECHO_LOOP_TEST_STOP, 1, (kal_uint32)NULL);
      AFE_TurnOffLoopback();
   }
}

kal_bool L1SP_GetAfeLoopbackStatus( void )
{
   return AFE_GetLoopbackStatus();
}

void L1SP_SetFIR( bool enable )
{
   if( enable ){
      AFE_TurnOnFIR( L1SP_SPEECH );
      AFE_TurnOnFIR( L1SP_VOICE );
   }else{
      AFE_TurnOffFIR( L1SP_SPEECH );
      AFE_TurnOffFIR( L1SP_VOICE );
   }
}

void L1SP_Write_Audio_Coefficients( const int16 in_coeff[45], const int16 out_coeff[45] )
{
   memcpy( fir_ul_nb, in_coeff, sizeof(int16)*45 );
   memcpy( fir_dl_nb, out_coeff, sizeof(int16)*45 );
   SAC_SphModePar.pi2BlkFltCoefUl[0] = fir_ul_nb;
   SAC_SphModePar.pi2BlkFltCoefDl[0] = fir_dl_nb;
   SAC_SphModePar.au4BlkFltTapUl[0] = 45;
   SAC_SphModePar.au4BlkFltTapDl[0] = 45;
   L1Audio_PutMessageAndWait( MSG_L1AUDIO2FAS_SPEECH_SET_MODE, sizeof(SAC_SphModePar_t), (kal_uint32)&SAC_SphModePar, true );
	{//to printf para for debug        
	   kal_trace(TRACE_INFO, L1MCU2DSP_FUNC7); 
      L1SP_DebugPrintModeParas();  
   }   
}

void L1SP_Write_Audio_Coefficients_ByFirIndex( const uint8 inOrOut2FirIndex, 
	const uint8 outFirIndex)
{

	int16 inOrOut2Coeff[NUM_FIR_COEFFS];
	int16 outCoeff[NUM_FIR_COEFFS];
		
	if(inOrOut2FirIndex == 0xff) {
		inOrOut2Coeff[0] = 0x7fff;
		memset(&inOrOut2Coeff[1], 0, (NUM_FIR_COEFFS-1)*sizeof(int16));
	} else {
		memcpy(inOrOut2Coeff, l1sp.sph_allInFirCoeff[inOrOut2FirIndex], (NUM_FIR_COEFFS)*sizeof(int16));		
	}

	if(outFirIndex == 0xff) {
		outCoeff[0] = 0x7fff;
		memset(&outCoeff[1], 0, (NUM_FIR_COEFFS-1)*sizeof(int16));
	} else {
		memcpy(outCoeff, l1sp.sph_allOutFirCoeff[outFirIndex], (NUM_FIR_COEFFS)*sizeof(int16));		
	}

	L1SP_Write_Audio_Coefficients( inOrOut2Coeff, outCoeff );

	
}

void L1SP_Write_WB_Audio_Coefficients( const int16 in_coeff[90], const int16 out_coeff[90] )
{
   memcpy( fir_ul_wb, in_coeff, sizeof(int16)*90 );
   memcpy( fir_dl_wb, out_coeff, sizeof(int16)*90 );
   SAC_SphModePar.pi2BlkFltCoefUl[1] = fir_ul_wb;
   SAC_SphModePar.pi2BlkFltCoefDl[1] = fir_dl_wb;
   SAC_SphModePar.au4BlkFltTapUl[1] = 90;
   SAC_SphModePar.au4BlkFltTapDl[1] = 90;
   
   kal_trace( TRACE_INFO, L1SP_WB_FILTER_COEFF, in_coeff[0], in_coeff[1], in_coeff[2], out_coeff[0], out_coeff[1], out_coeff[2]);
   L1Audio_PutMessageAndWait( MSG_L1AUDIO2FAS_SPEECH_SET_MODE, sizeof(SAC_SphModePar_t), (kal_uint32)&SAC_SphModePar, true );
	{//to printf para for debug        
	   kal_trace(TRACE_INFO, L1MCU2DSP_FUNC8); 
      L1SP_DebugPrintModeParas();   
   }      
}

void L1SP_EnableSpeechEnhancement( bool enable )
{
   if(enable)
   {
      l1sp.spe_flag = true;
      SetSpeechEnhancement(true);
   }
   else 
   {
      SetSpeechEnhancement(false);
      l1sp.spe_flag = false;
   }      
}

void L1SP_LoadSpeechPara( void ) 
{
#ifdef L1D_TEST
   memcpy( fir_ul_nb, g_ai2UntstBkfCofUlNb, sizeof(int16)*45 );
   memcpy( fir_dl_nb, g_ai2UntstBkfCofDlNb, sizeof(int16)*45 );
   SAC_SphModePar.pi2BlkFltCoefUl[0] = fir_ul_nb;
   SAC_SphModePar.pi2BlkFltCoefDl[0] = fir_dl_nb;
   memcpy( fir_ul_wb, g_ai2UntstBkfCofUlWb, sizeof(int16)*90 );
   memcpy( fir_dl_wb, g_ai2UntstBkfCofDlWb, sizeof(int16)*90 );
   SAC_SphModePar.pi2BlkFltCoefUl[1] = fir_ul_wb;
   SAC_SphModePar.pi2BlkFltCoefDl[1] = fir_dl_wb;
   SAC_SphModePar.pi2EMPMode = (kal_int16 *)mode_Para_Unitest;
#endif
   L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_CONFIG, sizeof(SAC_SphComPar_t), (kal_uint32)&SAC_SphCommonPar, true);
   L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_SET_MODE, sizeof(SAC_SphModePar_t), (kal_uint32)&SAC_SphModePar, true);
   {//to printf para for debug    
      kal_trace(TRACE_INFO, L1MCU2DSP_FUNC9);     
      L1SP_DebugPrintCommonParas();        
      L1SP_DebugPrintModeParas();   
   }   
}

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

void L1SP_SetDualMicNR( kal_bool enable )
{
#if defined(__DUAL_MIC_SUPPORT__)
   kal_trace( TRACE_INFO, L1SP_ENABLE_DUAL_MIC_NR, enable );
   /*
   if(enable)
      l1sp.spe_app_mask |= (1<< SPH_ENH_MODE_DMNR);
   else
      l1sp.spe_app_mask &= ~(1<< SPH_ENH_MODE_DMNR);
      */
   l1sp_updateSpeUsrMask((1<< SPH_ENH_MODE_DMNR), enable);
	/* move the following code to l1sp_updateSpeUsrMask() for centrol control
   if(l1sp.spe_state) // already turn on speech enhancement
      SetSpeechEnhancement(KAL_TRUE);
      */
#endif
}


void L1SP_Init( void )
{
   l1sp.sph_mode = SPH_MODE_UNDEFINED;
   
#ifndef __L1_STANDALONE__
   custom_cfg_audio_ec_range( &l1sp.min_ec_level, &l1sp.max_ec_level );
#else
   l1sp.min_ec_level = 1;
   l1sp.max_ec_level = 6;
#endif
   
   l1sp.sph_c_para = &sph_common_par[0];
   l1sp.sph_m_para = &sph_mode_par[0];
#if defined(__DUAL_MIC_SUPPORT__)
	 l1sp.dmnr_flag = false;
   l1sp.sph_dmnr_para    = &sph_dmnr_par[0];
#ifdef __AMRWB_LINK_SUPPORT__   
   l1sp.sph_wb_dmnr_para = &sph_wb_dmnr_par[0];
#endif
#endif 
   
   memset(l1sp.sph_c_para, 0, NUM_COMMON_PARAS*sizeof(uint16));
   memset(l1sp.sph_m_para, 0, NUM_MODE_PARAS*sizeof(uint16));
   memset(&l1sp.sph_v_para, 0, NUM_VOL_PARAS*sizeof(uint16));
   l1sp.mic_volume = AFE_GetMicrophoneVolume(); // get initial value

   memset(&SAC_SphModePar, 0, sizeof(SAC_SphModePar_t));
   memset(&SAC_SphCommonPar, 0, sizeof(SAC_SphComPar_t));
#if defined(__DUAL_MIC_SUPPORT__)
   memset(&SAC_SphDMNRPar, 0, sizeof(SAC_SphDMNRPar_t));
#endif 

   l1sp.setNvramValuesFlag = 0; //flag reset

   memset(l1sp.sph_allModePara, 0, NUM_SPH_MODE*NUM_MODE_PARAS*sizeof(uint16));

   memset(l1sp.sph_allInFirCoeff, 0, NUM_SPH_INPUT_FIR*NUM_FIR_COEFFS*sizeof(int16));
   memset(l1sp.sph_allOutFirCoeff, 0, NUM_SPH_OUTPUT_FIR*NUM_FIR_COEFFS*sizeof(int16));
   memset(l1sp.sph_allVolumePara, 0, 3*7*4*sizeof(uint16));
   
   l1sp.sph_selectedOutFirIndex = 0;
#if defined(__AMRWB_LINK_SUPPORT__)   
   memset(l1sp.sph_allWbModePara, 0, NUM_SPH_MODE*NUM_MODE_PARAS*sizeof(uint16));
   memset(l1sp.sph_allWbInFirCoeff, 0, NUM_SPH_INPUT_FIR*NUM_WB_FIR_COEFFS*sizeof(int16));
   memset(l1sp.sph_allWbOutFirCoeff, 0, NUM_SPH_OUTPUT_FIR*NUM_WB_FIR_COEFFS*sizeof(int16));
#endif //(__AMRWB_LINK_SUPPORT__)     

   //HD reocd related
#if defined(__HD_RECORD__) 
   memset(l1sp.recordModePara, 0, NUM_RECORD_SPH_MODE*NUM_MODE_PARAS*sizeof(int16));
   memset(l1sp.recordInFirCoeff, 0, NUM_RECORD_INPUT_FIR*NUM_FIR_COEFFS*sizeof(int16));
#elif defined(__SMART_PHONE_MODEM__)
   memset(l1sp.recordModePara, 0, SPC_MAX_NUM_RECORD_SPH_MODE*NUM_MODE_PARAS*sizeof(int16));
   memset(l1sp.recordInFirCoeff, 0, SPC_MAX_NUM_RECORD_INPUT_FIR*NUM_WB_FIR_COEFFS*sizeof(int16));
#endif //defined(__HD_RECORD__) || defined(__SMART_PHONE_MODEM__)
   l1sp.numOfRecordMode = 0;
   l1sp.numOfRecordInFir = 0;   
#if defined(__HD_RECORD__) || defined(__SMART_PHONE_MODEM__)
   l1sp.recordModeFirMappingCh1 = NULL;
#if defined(__STEREO_RECORD__) || defined(__SMART_PHONE_MODEM__)
   l1sp.recordModeFirMappingCh2 = NULL;
#endif //defined(__STEREO_RECORD__) || defined(__SMART_PHONE_MODEM__)
   l1sp.recordModeDeviceMapping = NULL;
#endif // defined(__HD_RECORD__) || defined(__SMART_PHONE_MODEM__)
   //END HD reocd related

#ifdef L1D_TEST
   SAC_SphModePar.pi2EMPMode = (kal_int16 *)mode_Para_Unitest;
#else
   SAC_SphModePar.pi2EMPMode = (kal_int16 *)l1sp.sph_m_para;
#endif
   SAC_SphModePar.u4EMPModeLen = NUM_MODE_PARAS * 2;
   SAC_SphModePar.pi2BlkFltCoefUl[0] = (kal_int16 *)fir_ul_nb;
   SAC_SphModePar.pi2BlkFltCoefDl[0] = (kal_int16 *)fir_dl_nb;
   SAC_SphModePar.au4BlkFltTapUl[0] = 45;
   SAC_SphModePar.au4BlkFltTapDl[0] = 45;
   SAC_SphModePar.pi2BlkFltCoefUl[1] = (kal_int16 *)fir_ul_wb;
   SAC_SphModePar.pi2BlkFltCoefDl[1] = (kal_int16 *)fir_dl_wb;
   SAC_SphModePar.au4BlkFltTapUl[1] = 90;
   SAC_SphModePar.au4BlkFltTapDl[1] = 90;
#ifdef L1D_TEST
   SAC_SphCommonPar.pi2EMPCom = (kal_int16 *)Speech_Common_Para;
#else
   SAC_SphCommonPar.pi2EMPCom = (kal_int16 *)l1sp.sph_c_para;
#endif
   SAC_SphCommonPar.u4EMPComLen = 12;
   SAC_SphCommonPar.pi2StFltCoef[0] =  (kal_int16 *)Sidetone_FIR;
   SAC_SphCommonPar.au4StFltTap[0] = 31;
   SAC_SphCommonPar.pi2StFltCoef[1] =  (kal_int16 *)Sidetone_FIR;
   SAC_SphCommonPar.au4StFltTap[1] = 31;
   
#if defined(__BT_SUPPORT__)   
   l1sp.bt_on = false;
#endif

#if defined( __UMTS_RAT__ )
   sp3g_init();
   l1sp.interRAT = false;
#endif

   l1sp.spe_flag = true;
   l1sp.spe_usr_mask  = 0xFFFF;
   l1sp.spe_usr_subFunc_mask = 0xFFFFFFFF;
   
   l1sp.spe_app_mask  = 0xFFFF;
   l1sp.ul_spe_app_mask  = 0xFFFF;
   l1sp.dl_spe_app_mask  = 0xFFFF;
	
   l1sp.isULMute = false;
   l1sp.spe_state = false;
   l1sp.sph_dl_vol = 128;
   l1sp.pcmplayback_flag = false;
   l1sp.speech_dmnr_loopback = KAL_FALSE;   
   l1sp.speech_loopback = KAL_FALSE;
   l1sp.fc_aud_id  = 0xFFFF;
   
   l1sp.onHandler = NULL;
   l1sp.offHandler = NULL;
   L1SP_SetState(L1SP_STATE_IDLE);

#ifdef BGSND_ENABLE
   l1sp.sndOnHandler  = NULL;
   l1sp.sndOffHandler = NULL;
#endif
#if defined(__DATA_CARD_SPEECH__)
   l1sp.strmOnHandler  = NULL;
   l1sp.strmOffHandler = NULL;
   l1sp.strmHdl = NULL;
#endif
#if defined(__ECALL_SUPPORT__)
   l1sp.pcm4wayOnHandler = NULL; 
   l1sp.pcm4wayOffHandler = NULL;
#endif

}
kal_bool L1SP_TCH_State( void )
{
   return l1sp.tch_state;
}

//0: G2W, 1: W2G
void L1SP_InterRATHO(uint16 handover)
{
   if(!AM_IsSpeechOn())
      return;
   L1Audio_LSetEvent(l1sp.aud_id, (void *)handover);
}

// run under l1 LISR context
void L1SP_TCH_Notify( bool bOn )
{
#if defined( __UMTS_RAT__ )
   if( !bOn ){ // for 2G->3G handover, mute speech in case Speech_Off command too late to avoid noise
      L1Audio_Msg_TCH_NOTIFY(L1AUDIO_Str_onoff(0), L1Audio_Speech_State(l1sp.state));
      l1sp.tch_state = KAL_FALSE;
      
      if( SP3G_Rab_State() && l1sp.state != L1SP_STATE_3G_SPEECH_ON && l1sp.state != L1SP_STATE_IDLE){//3G->2G fail case, TCH will be off
         L1SP_InterRATHO(0);
         SP3G_Reset();
      }
   }
   else{
      L1Audio_Msg_TCH_NOTIFY(L1AUDIO_Str_onoff(1), L1Audio_Speech_State(l1sp.state));
      l1sp.tch_state = KAL_TRUE;
      if( l1sp.state == L1SP_STATE_3G_SPEECH_ON ){//3G->2G HO
         L1SP_InterRATHO(1);
      }
   }
#endif
}
void L1SP_SetULAGC( bool ec )
{
   kal_uint16 i;
   for( i = 0 ; i < SPH_ENH_MODE_NUM ; i++){
      SAC_SphEnhancementPar.au4SwitchUl[i] = false;
      SAC_SphEnhancementPar.au4SwitchDl[i] = false;
   }


   if(((l1sp.spe_app_mask & SPH_ENH_MASK_AGC)!=0) && ((l1sp.spe_app_mask & SPH_ENH_MASK_AGC)!=0)) {
      SAC_SphEnhancementPar.au4SwitchUl[SPH_ENH_MODE_AGC] = ec;
   } else {
      SAC_SphEnhancementPar.au4SwitchUl[SPH_ENH_MODE_AGC] = false;
   }
   L1Audio_PutMessageAndWait( MSG_L1AUDIO2FAS_SPEECH_ENHANCEMENT_SET_PAR, sizeof(SAC_SphEnhancementPar_t), (kal_uint32)&SAC_SphEnhancementPar, KAL_TRUE );
	{//to printf para for debug         
	   kal_trace(TRACE_INFO, L1MCU2DSP_FUNC10); 
      L1SP_DebugPrintENHParas();  
   }      
}

void SPE_SetULNR( bool ec )
{
#ifndef __HD_RECORD__
   /*
   膀セ琌DMNR柑繷北NDCbit
   0: ボ穦酚speech 家把计砞﹚
   1: ボ穦ㄏノ箇砞NDC把计舱 (NDC穎皌DMNR惠璶ノ)
	 パ魁家Αぃ穦秨DMNR  ぃ惠璶穎皌NDCê碭箇砞舱
	 ┮璶р硂bit睲Θ0	家ぐ或把计  и碞ㄏノぐ或妓把计矪瞶noise
	 
	 REMIND!! should be use when __HD_RECORD__ is NOT defined for speech recording applications 
   */

#if defined(__SMART_PHONE_MODEM__)
   if(!SMP_IsFeatureSupport_HdRecord()) 
#endif //  defined(__SMART_PHONE_MODEM__) 	
   {
      kal_uint16 i;
      if( !l1sp.spe_flag )
          return;   
      /*
      for( i = 0 ; i < SPH_ENH_MODE_NUM ; i++){
         SAC_SphEnhancementPar.au4SwitchUl[i] = false;
         SAC_SphEnhancementPar.au4SwitchDl[i] = false;
      }
      */
      if(ec){//When recordingset bit8 of para13 into 0
         l1sp.pre_mpara13_bit8 = (l1sp.sph_m_para[13]&0x80) >> 7;   
         l1sp.sph_m_para[13] &= (~0x80);
      }else{//When finish recording, recover it
         l1sp.sph_m_para[13] |= l1sp.pre_mpara13_bit8;
      }
      L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_SET_MODE, sizeof(SAC_SphModePar_t), (kal_uint32)&SAC_SphModePar, true);  
   }
#endif // NOT __HD_RECORD__
	{//to printf para for debug         
	   kal_trace(TRACE_INFO, L1MCU2DSP_FUNC11); 
      L1SP_DebugPrintENHParas();  
   }       
}

void L1SP_SpeechLoopBackEnable(kal_bool fgEnable)
{
   if(fgEnable)
      L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_CODEC_LBK_OPEN, (kal_uint16)fgEnable, 0, KAL_TRUE);
   else
      L1Audio_PutMessageAndWait(MSG_L1AUDIO2FAS_SPEECH_CODEC_LBK_CLOSE, (kal_uint16)fgEnable, 0, KAL_TRUE);
   l1sp.speech_loopback = fgEnable;
}

void L1SP_SetAcousticLoopback( kal_bool loopback )
{
   if(loopback){
      if(L1SP_GetAcousticLoopbackStatus()){
         return;
      }        
      L1SP_Speech_On(RAT_2G_MODE);
      L1SP_SpeechLoopBackEnable(KAL_TRUE);
   } else {
      if(!L1SP_GetAcousticLoopbackStatus()){
         return;
      }
      L1SP_SpeechLoopBackEnable(KAL_FALSE);
      L1SP_Speech_Off(); 
   }
}

kal_bool L1SP_GetAcousticLoopbackStatus( void )
{
   return l1sp.speech_loopback;
}




/* Just for Factory Usage */
void L1SP_AcousticLoopbackOn (void)
{
#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )       
   AcousticLoopbackOn();
#endif   
}

/* Just for Factory Usage */
void L1SP_AcousticLoopbackOff (void)
{
#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )          
   AcousticLoopbackOff();
#endif   
}

/* Just for Factory Usage */
void L1SP_AcousticLoopbackSpeechMode (kal_uint8 u1Mode)
{
#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )    
   AcousticLoopbackSpeechMode(u1Mode);
#endif    
}

/* Just for Factory Usage */
kal_bool L1SP_AcousticLoopbackStatus(void)
{
#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )    
   AcousticLoopbackStatus();
#endif    
}

/* Just for Factory Usage */
void L1SP_AcousticLoopbackBypassMode (kal_uint8 u1Mode)
{
#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )    
   AcousticLoopbackBypassMode(u1Mode);
#endif     
}

/* Just for Factory Usage */
void L1SP_AcousticLoopbackLength (kal_uint32 u4Length)
{
#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ )    
   AcousticLoopbackLength(u4Length);
#endif   
}

//#if defined( __ACOUSTIC_LOOPBACK_SUPPORT__ ) || defined( __DUAL_MIC_SUPPORT__ )
#include "pcm4way.h"

#define FRAME_BUF_NO (32)
#define NB_FRAME_SIZE   (160)
static uint16 PCM_UL_BUF[FRAME_BUF_NO][NB_FRAME_SIZE];
static uint16 PCM_DL_BUF[FRAME_BUF_NO][NB_FRAME_SIZE];
static uint32 DELAY = 12;
static uint32 UL_tmp_w, UL_tmp_r;
static uint32 DL_tmp_w, DL_tmp_r;

void AcousticLoopback_PCM4WAY_HisrHdl()
{
   uint32 I;
   int16 *buf1, *buf2;
#if 1
   kal_uint16 buffer_state;
   
   buffer_state = PCM4WAY_QueryBuffer();

   if( buffer_state & UPDATE_UL )
#endif
   {
      if( (UL_tmp_w - UL_tmp_r) < FRAME_BUF_NO ){        
         PCM4WAY_GetFromMic((uint16*)PCM_UL_BUF[UL_tmp_w & (FRAME_BUF_NO - 1)]);
         kal_prompt_trace(L1SP_DMNR_LOOPBACK_FROM_MIC, 
                          PCM_UL_BUF[UL_tmp_w & (FRAME_BUF_NO - 1)][0],
                          PCM_UL_BUF[UL_tmp_w & (FRAME_BUF_NO - 1)][1],
                          PCM_UL_BUF[UL_tmp_w & (FRAME_BUF_NO - 1)][2],
                          PCM_UL_BUF[UL_tmp_w & (FRAME_BUF_NO - 1)][3]);         
         UL_tmp_w++;            
      }else{
         kal_trace( TRACE_INFO, L1SP_DMNR_LOOPBACK_SKIP_MIC); 
      }

      if( (UL_tmp_w - UL_tmp_r) >= DELAY ){
         PCM4WAY_PutToSE(PCM_UL_BUF[UL_tmp_r & (FRAME_BUF_NO - 1)]);   
         kal_trace( TRACE_INFO, L1SP_DMNR_LOOPBACK_TO_SE, 
                          PCM_UL_BUF[UL_tmp_r & (FRAME_BUF_NO - 1)][0],
                          PCM_UL_BUF[UL_tmp_r & (FRAME_BUF_NO - 1)][1],
                          PCM_UL_BUF[UL_tmp_r & (FRAME_BUF_NO - 1)][2],
                          PCM_UL_BUF[UL_tmp_r & (FRAME_BUF_NO - 1)][3]);               
         UL_tmp_r++;
      }else{
         kal_trace( TRACE_INFO, L1SP_DMNR_LOOPBACK_FILL_SE); 
         PCM4WAY_FillSE(0);
      }
   }
#if 1
   if( buffer_state & UPDATE_DL )
#endif
   {
      if( (DL_tmp_w - DL_tmp_r) < FRAME_BUF_NO ){        
         PCM4WAY_GetFromSD((uint16*)PCM_DL_BUF[DL_tmp_w & (FRAME_BUF_NO - 1)]);
         kal_trace( TRACE_INFO, L1SP_DMNR_LOOPBACK_FROM_SD, 
                          PCM_DL_BUF[DL_tmp_w & (FRAME_BUF_NO - 1)][0],
                          PCM_DL_BUF[DL_tmp_w & (FRAME_BUF_NO - 1)][1],
                          PCM_DL_BUF[DL_tmp_w & (FRAME_BUF_NO - 1)][2],
                          PCM_DL_BUF[DL_tmp_w & (FRAME_BUF_NO - 1)][3]);
         DL_tmp_w++;            
      }else{
         kal_trace( TRACE_INFO, L1SP_DMNR_LOOPBACK_SKIP_SD); 
      }

      if( (DL_tmp_w - DL_tmp_r) >= DELAY ){
         PCM4WAY_PutToSpk(PCM_DL_BUF[DL_tmp_r & (FRAME_BUF_NO - 1)]);  
         kal_trace( TRACE_INFO, L1SP_DMNR_LOOPBACK_TO_SPK, 
                          PCM_DL_BUF[DL_tmp_r & (FRAME_BUF_NO - 1)][0],
                          PCM_DL_BUF[DL_tmp_r & (FRAME_BUF_NO - 1)][1],
                          PCM_DL_BUF[DL_tmp_r & (FRAME_BUF_NO - 1)][2],
                          PCM_DL_BUF[DL_tmp_r & (FRAME_BUF_NO - 1)][3]);         
         DL_tmp_r++;          
      }else{
         kal_trace( TRACE_INFO, L1SP_DMNR_LOOPBACK_FILL_SPK); 
         PCM4WAY_FillSpk(0);
      }
   }
   kal_trace( TRACE_INFO, L1SP_DMNR_LOOPBACK_UL_DL_INDEX, UL_tmp_w, UL_tmp_r, DL_tmp_w, DL_tmp_r);
}


void ABF_SetAcousticLoopback( kal_bool loopback)
{
   if(loopback){
      if(ABF_GetAcousticLoopbackStatus()){
         kal_trace( TRACE_INFO,  L1SP_DMNR_LOOPBACK_ILLEGAL_OPEN);
         return;
      }
   	
   	//AFE_SetDualMic(KAL_TRUE);
   	//L1SP_SetInputSource(L1SP_MICROPHONE1);
   	
      UL_tmp_w = UL_tmp_r = DL_tmp_w = DL_tmp_r = 0;
      {
         int32 I;
         for( I = 0; FRAME_BUF_NO > I; I++ ){
            memset(PCM_UL_BUF, 0, sizeof(uint16)*NB_FRAME_SIZE);
            memset(PCM_DL_BUF, 0, sizeof(uint16)*NB_FRAME_SIZE);
         }         
      }
      //L1SP_EnableDLSpeechEnhancement(false);  
      //l1sp_updateSpeAppMask(0xffff, true);
	   //l1sp_updateDlSpeAppMask(0xffff, false);
      //SetSpeechEnhancement(true);
	  
      L1SP_Speech_On(RAT_2G_MODE);
      L1SP_SpeechLoopBackEnable(KAL_TRUE);
      PCM4WAY_Start(AcousticLoopback_PCM4WAY_HisrHdl, 1);
      l1sp.speech_dmnr_loopback = KAL_TRUE;
   } else {
      if(!ABF_GetAcousticLoopbackStatus()){
         kal_trace( TRACE_INFO,  L1SP_DMNR_LOOPBACK_ILLEGAL_CLOSE);
         return;
      }

      PCM4WAY_Stop(0);
      L1SP_SpeechLoopBackEnable(KAL_FALSE);
     
      L1SP_Speech_Off();
      //L1SP_EnableDLSpeechEnhancement(true);      
      //l1sp_updateSpeAppMask(0xffff, true);
	   //l1sp_updateDlSpeAppMask(0xffff, true);
      //SetSpeechEnhancement(true);
      l1sp.speech_dmnr_loopback = KAL_FALSE;
   }
}

kal_bool ABF_GetAcousticLoopbackStatus( void )
{
   return l1sp.speech_dmnr_loopback;
}
//#endif

#if defined(__SMART_PHONE_MODEM__)
void l1sp_DebugPrint(void)
{

	kal_int16 myloop;

	// common paramter
	for(myloop = 0; myloop<3; myloop++) { //number is NUM_COMMON_PARAS
		kal_trace( TRACE_INFO,  L1SP_DEBUG_COMMON_PARAM,
			myloop*4+0, sph_common_par[myloop*4+0],
			myloop*4+1, sph_common_par[myloop*4+1],
			myloop*4+2, sph_common_par[myloop*4+2],
			myloop*4+3, sph_common_par[myloop*4+3] );
	}

	// enhancement mode parameter
	for(myloop = 0; myloop<8; myloop++) { //number is NUM_MODE_PARAS*2 == 16*2
		kal_trace(TRACE_INFO, L1SP_DEBUG_ENH_MODE_PARAM,
		  myloop*4+0, sph_mode_par[myloop*4+0],
		  myloop*4+1, sph_mode_par[myloop*4+1],
		  myloop*4+2, sph_mode_par[myloop*4+2],
		  myloop*4+3, sph_mode_par[myloop*4+3] );
	}

	//enhancement switch
	for(myloop = 0; myloop<2; myloop++) {
		kal_trace(TRACE_INFO, L1SP_DEBUG_ENH_UL_SWITCH,
		  myloop*4+0, SAC_SphEnhancementPar.au4SwitchUl[myloop*4+0],
		  myloop*4+1, SAC_SphEnhancementPar.au4SwitchUl[myloop*4+1],
		  myloop*4+2, SAC_SphEnhancementPar.au4SwitchUl[myloop*4+2],
		  myloop*4+3, SAC_SphEnhancementPar.au4SwitchUl[myloop*4+3] );
		kal_trace(TRACE_INFO, L1SP_DEBUG_ENH_DL_SWITCH,
		  myloop*4+0, SAC_SphEnhancementPar.au4SwitchDl[myloop*4+0],
		  myloop*4+1, SAC_SphEnhancementPar.au4SwitchDl[myloop*4+1],
		  myloop*4+2, SAC_SphEnhancementPar.au4SwitchDl[myloop*4+2],
		  myloop*4+3, SAC_SphEnhancementPar.au4SwitchDl[myloop*4+3] );
	}

	// DMNR clibration
#if defined(__DUAL_MIC_SUPPORT__)	
	for(myloop = 0; myloop<11; myloop++) {
		kal_trace(TRACE_INFO, L1SP_DEBUG_DMNR_CAL,
		  myloop*4+0, sph_dmnr_par[myloop*4+0],
		  myloop*4+1, sph_dmnr_par[myloop*4+1],
		  myloop*4+2, sph_dmnr_par[myloop*4+2],
		  myloop*4+3, sph_dmnr_par[myloop*4+3] );
	}

	for(myloop = 0; myloop<19; myloop++) {
		kal_trace(TRACE_INFO, L1SP_DEBUG_WB_DMNR_CAL,
		  myloop*4+0, sph_wb_dmnr_par[myloop*4+0],
		  myloop*4+1, sph_wb_dmnr_par[myloop*4+1],
		  myloop*4+2, sph_wb_dmnr_par[myloop*4+2],
		  myloop*4+3, sph_wb_dmnr_par[myloop*4+3] );
	}
#endif // __DUAL_MIC_SUPPORT__

	// FIR
	for(myloop = 0; myloop<5; myloop++) { //number is 45
		kal_trace(TRACE_INFO, L1SP_DEBUG_UL_FIR,
		  myloop*9+0, fir_ul_nb[myloop*9+0], myloop*9+1, fir_ul_nb[myloop*9+1],
		  myloop*9+2, fir_ul_nb[myloop*9+2], myloop*9+3, fir_ul_nb[myloop*9+3], 
		  myloop*9+4, fir_ul_nb[myloop*9+4], myloop*9+5, fir_ul_nb[myloop*9+5],
		  myloop*9+6, fir_ul_nb[myloop*9+6], myloop*9+7, fir_ul_nb[myloop*9+7],
		  myloop*9+8, fir_ul_nb[myloop*9+8]
		  );
	} 

	for(myloop = 0; myloop<5; myloop++) { //number is 45
		kal_trace(TRACE_INFO, L1SP_DEBUG_DL_FIR,
		  myloop*9+0, fir_dl_nb[myloop*9+0], myloop*9+1, fir_dl_nb[myloop*9+1],
		  myloop*9+2, fir_ul_nb[myloop*9+2], myloop*9+3, fir_dl_nb[myloop*9+3], 
		  myloop*9+4, fir_dl_nb[myloop*9+4], myloop*9+5, fir_dl_nb[myloop*9+5],
		  myloop*9+6, fir_dl_nb[myloop*9+6], myloop*9+7, fir_dl_nb[myloop*9+7],
		  myloop*9+8, fir_dl_nb[myloop*9+8]
		  );
	}

	for(myloop = 0; myloop<10; myloop++) { //number is 90
		kal_trace(TRACE_INFO, L1SP_DEBUG_UL_WB_FIR,
		  myloop*9+0, fir_ul_wb[myloop*9+0], myloop*9+1, fir_ul_wb[myloop*9+1],
		  myloop*9+2, fir_ul_wb[myloop*9+2], myloop*9+3, fir_ul_wb[myloop*9+3], 
		  myloop*9+4, fir_ul_wb[myloop*9+4], myloop*9+5, fir_ul_wb[myloop*9+5],
		  myloop*9+6, fir_ul_wb[myloop*9+6], myloop*9+7, fir_ul_wb[myloop*9+7],
		  myloop*9+8, fir_ul_wb[myloop*9+8]
		  );
	}

	for(myloop = 0; myloop<10; myloop++) { //number is 90
		kal_trace(TRACE_INFO, L1SP_DEBUG_DL_WB_FIR,
		  myloop*9+0, fir_dl_wb[myloop*9+0], myloop*9+1, fir_dl_wb[myloop*9+1],
		  myloop*9+2, fir_dl_wb[myloop*9+2], myloop*9+3, fir_dl_wb[myloop*9+3], 
		  myloop*9+4, fir_dl_wb[myloop*9+4], myloop*9+5, fir_dl_wb[myloop*9+5],
		  myloop*9+6, fir_dl_wb[myloop*9+6], myloop*9+7, fir_dl_wb[myloop*9+7],
		  myloop*9+8, fir_dl_wb[myloop*9+8]
		  );
	}
}
#endif
