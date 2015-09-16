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
 * sp_enhance.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   speech enhancement functions (moved from am.c)  
 *
 * Author:
 * -------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_public_api.h"
#include "kal_general_types.h"

#include "reg_base.h"

#include "l1audio.h"

#include "kal_trace.h"
#include "l1sp_trc.h"

#include "sp_enhance.h"
#include "sp_drv.h"
#include "am.h"
#include "media.h"
#include "afe.h"
#include "sidetone.h"

#include "ddload.h"


#ifdef __TWOMICNR_SUPPORT__
#include "two_mic_NR_custom_if.h" 
#endif

#if defined(__CVSD_CODEC_SUPPORT__) 
#include "bt_sco_drv.h"
#endif

#include "sal_def.h"
#include "sal_exp.h"

#if defined(__HQA_AUDIO__) && !(__HQA_AUDIO_SPEECH_ENHANCEMENT_COMMON__)
const unsigned short Speech_Common_Para[12] = 
{ 
     0,     0,     0,     0,    1,     0,     0,     0,     0,     0, 
     0,     0 
};
#else
#if defined(MT6280)
const unsigned short Speech_Common_Para[12] = 
{ 
     0,     0, 31000, 10752, 32769,     0,     0,     0,     0,     0, 
     0,     0 
};
#elif defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571) || defined(MT6595) || defined(MT6752)
const unsigned short Speech_Common_Para[12] = 
{ 
     0, 55997, 31000, 10752, 32769,     0,     0,     0,     0,     0, 
     0,     0 
};
#else
const unsigned short Speech_Common_Para[12] = 
{ 
     0, 55997, 31000, 10752,     0,     0,     0,     0,     0,     0, 
     0,     0 
};
#endif
#endif


// #define USE_AEC defined(AEC_ENABLE)

uint16 spe_table[SPH_MODE_UNDEFINED] = {
#if defined(__HQA_AUDIO__) && !(__HQA_AUDIO_AEC_NR_DRC__)
   0, 0, 0, 0, 0, 0, 0, 0, 
#elif defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571) || defined(MT6290) || defined(MT6595) || defined(MT6752)
   #if 1 //TDDNC_SUPPORT
	  	#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)//in FD216, DMNR's running depends on AP control
		  /* SPH_MODE_NORMAL */    SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_DMNR_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_SIDETONE + SPH_ENH_MASK_NOTCH_FILTER,
		#else
	     /* SPH_MODE_NORMAL */    SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_TDDNC_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_SIDETONE + SPH_ENH_MASK_NOTCH_FILTER,
	   #endif
		
      #if defined(AEC_ENABLE)           
      /* SPH_MODE_EARPHONE */    SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_TDDNC_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_SIDETONE,
      #else 
      /* SPH_MODE_EARPHONE */    SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_TDDNC_FLAG + SPH_ENH_MASK_SIDETONE,
      #endif  

#if SPE_LOUDSPK_DMNR // by chip patch 
      #if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
      /* SPH_MODE_LOUDSPK */     SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_DMNR_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_NOTCH_FILTER, // TDDNC v.s. DMNR is excluded
      #else
      /* SPH_MODE_LOUDSPK */     SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_TDDNC_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_NOTCH_FILTER, // TDDNC v.s. DMNR is excluded
		#endif
#else 
		/* SPH_MODE_LOUDSPK */     SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_TDDNC_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_NOTCH_FILTER, // TDDNC v.s. DMNR is excluded
#endif
      
      #if defined(AEC_ENABLE) // && defined(__BT_SUPPORT__)         
      /* SPH_MODE_BT_EARPHONE */ SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG,
      #else 
      /* SPH_MODE_BT_EARPHONE */ SPE_UL_NR_FLAG + SPE_DL_NR_FLAG,
      #endif
		
      /* SPH_MODE_BT_CORDLESS */ 0,
      
      /* SPH_MODE_BT_CARKIT */   SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG,

      /* SPH_MODE_AUX1 */        SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_TDDNC_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_NOTCH_FILTER,
      
      /* SPH_MODE_AUX2 */        0, 

		#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)//in FD216, DMNR's running depends on AP control
		  /* HAC */                 SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_DMNR_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_SIDETONE + SPH_ENH_MASK_NOTCH_FILTER,
		#else
		  /* HAC */                 SPE_AEC_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_TDDNC_FLAG + SPE_AGC_FLAG + SPH_ENH_MASK_SIDETONE + SPH_ENH_MASK_NOTCH_FILTER,
	   #endif
   #else
	  	#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
/* under construction !*/
		#else
/* under construction !*/
      #endif
/* under construction !*/
      #if defined(AEC_ENABLE)           
/* under construction !*/
      #else 
/* under construction !*/
      #endif  
/* under construction !*/
/* under construction !*/
		  #if SPE_LOUDSPK_DMNR // by chip patch 
            #if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)
/* under construction !*/
            #else
/* under construction !*/
      		  #endif
      #else 
/* under construction !*/
      #endif
/* under construction !*/
      #if defined(AEC_ENABLE) // && defined(__BT_SUPPORT__)         
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
   #endif
#endif
   /* Line-in Cordless */        0 
};   

typedef enum{
	L1SP_SPE_SUBMASK_BYMASK = 0,
	L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, // default true
	L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, // default true
	L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON,
	L1SP_SPE_SUBMASK_SKIP,
	L1SP_SPE_SUBMASK_BYMASK_SP1,
}L1SP_SPE_SUBMASK_VALUES; // for NvramValuesFlag

#define L1SP_ENH_DYNAMIC_NUM (10) //should equal to SAL_ENH_DYNAMIC_NUM// double check the consistence between sp_drv, and sal

L1SP_SPE_SUBMASK_VALUES spe_subMask_table[SPH_MODE_UNDEFINED][L1SP_ENH_DYNAMIC_NUM] = {
	/* SPH_MODE_NORMAL */  
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK },
	/* SPH_MODE_EARPHONE */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK },
	/* SPH_MODE_LOUDSPK */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_BYMASK_SP1,  // loudspeaker mode dmnr
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK },
	/* SPH_MODE_BT_EARPHONE */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK},
	/* SPH_MODE_BT_CORDLESS */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK},
	/* SPH_MODE_BT_CARKIT */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK},
	/* SPH_MODE_AUX1 --> use for magic con-call Lx*/ 
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK},
	/* SPH_MODE_AUX2 */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE},
	/* SPH_MODE_HAC like normal */  
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK},
	/* LINEIN ?  */
	{ L1SP_SPE_SUBMASK_SKIP, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE, 
	  L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE, 
	  L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON, 
	  L1SP_SPE_SUBMASK_BYMASK, 
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK,
	  L1SP_SPE_SUBMASK_SKIP,
	  L1SP_SPE_SUBMASK_BYMASK}
	//
};

/* ========================================================================= */
typedef enum{
	SPE_NVRAM_VALUES_FLAG_MODE = 0x1,
	SPE_NVRAM_VALUES_FLAG_IN_FIR = 0x2,
	SPE_NVRAM_VALUES_FLAG_OUT_FIR = 0x4,
	SPE_NVRAM_VALUES_FLAG_WB_MODE = 0x8,
	SPE_NVRAM_VALUES_FLAG_WB_IN_FIR = 0x10,
	SPE_NVRAM_VALUES_FLAG_WB_OUT_FIR = 0x20,
	// SPE_NVRAM_VALUES_FLAG_RECORD_MODE = 0x40, // useless in MOLY
	// SPE_NVRAM_VALUES_FLAG_RECORD_IN_FIR = 0x80, // useless in MOLY
	// SPE_NVRAM_VALUES_FLAG_VOLUME_PARAM = 0x100,
}SPE_INTERNAL_NVRAM_VALUES_FLAG; // for NvramValuesFlag

#define TOTAL_NUM_SPH_MODE (NUM_SPH_MODE+1) // new 1 for HAC
#define TOTAL_NUM_SPH_INPUT_FIR (NUM_SPH_INPUT_FIR+1) // new 1 for HAC
#define TOTAL_NUM_SPH_OUTPUT_FIR (NUM_SPH_OUTPUT_FIR+1)  // new 1 for HAC
typedef struct 
{
	uint8    sph_mode; 	
	bool		spe_flag; 
	bool     spe_isFweOn;
	
	uint16   spe_state; // record which enhancement is open 
	
   uint16   spe_app_mask;   //record the usage every application should have. Ex. phonecall should be turned on DMNR. please do not update the mask directly, please use function l1sp_updateSpeAppMask() to update
   uint16   spe_usr_mask;   //record the usage user choose. Size is NUM_OF_SPH_FLAG. Please use function l1sp_updateSpeUsrMaskWithWholeValue() to update
   uint16   spe_usr_sub_mask; // record the usage of enhancement sub feature. Sync with Sal_Enh_Dynamic_t definition.  Ex. phonecall should be turned on DMNR, but users can decide whether turn on or not.please do not update the mask directly, please use function l1sp_updateUsrSubMask() to update 

	//record the value from nvram whether is get or not, refer to SPE_INTERNAL_NVRAM_VALUES_FLAG
   uint16   setNvramValuesFlag; //bit 0 for sph_allModePara, bit 1 for sph_allInFirCoeff, bit 2 for sph_allOutFirCoeff, 
                                //bit 3 for sph_allWbModePara, bit 4 for sph_allWbInFirCoeff, bit 5 for sph_allWbOutFirCoeff
                                //bit 6 for recordModePara, bit 7 for recordInFirCoeff
                                //bit 8 for sph_allVolumePara is uesless now (phase out)
	// enhancement parameters 
	// --NB--
	uint16   sph_allModePara[TOTAL_NUM_SPH_MODE][NUM_MODE_PARAS];   
   int16    sph_allInFirCoeff[TOTAL_NUM_SPH_INPUT_FIR][NUM_FIR_COEFFS];
   int16    sph_allOutFirCoeff[TOTAL_NUM_SPH_OUTPUT_FIR][NUM_FIR_COEFFS];
	// --WB--
   uint16   sph_allWbModePara[TOTAL_NUM_SPH_MODE][NUM_MODE_PARAS];
   int16    sph_allWbInFirCoeff[TOTAL_NUM_SPH_INPUT_FIR][NUM_WB_FIR_COEFFS];
   int16    sph_allWbOutFirCoeff[TOTAL_NUM_SPH_OUTPUT_FIR][NUM_WB_FIR_COEFFS];
	// --DMNR--
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
	int16 	sph_dmnr_para[NUM_DMNR_PARAM];
#if defined(__AMRWB_LINK_SUPPORT__)
	int16 	sph_wb_dmnr_para[NUM_WB_DMNR_PARAM];
#endif
	int16 	sph_lspk_dmnr_para[NUM_DMNR_PARAM];
#if defined(__AMRWB_LINK_SUPPORT__)
	int16 	sph_lspk_wb_dmnr_para[NUM_WB_DMNR_PARAM];
#endif
#endif 
	uint16 sph_magicConParam[NUM_MODE_PARAS];
	uint16 sph_magicConWbParam[NUM_MODE_PARAS];

	bool     isEnableNotchFilter; 
	bool     is2In1Spk; // the variable only meaning for under isEnableNotchFilter==true. Ture for is 2-in-1 speaker; False for 3-in-1 speaker
	bool     isMagiConOn;

	bool     isHacModeNeeded; // if AP send Hac paramters and FIRs to MD, the flag will be set. 
	
} _SPE_T;

static _SPE_T gSpe;



/* ========================================================================= */
void l1sp_setAllSpeechModePara(kal_uint16 * speech_mode_para, kal_int16 length)
{
	ASSERT((NUM_SPH_MODE*NUM_MODE_PARAS) == length);
	
	memcpy(gSpe.sph_allModePara, speech_mode_para, 
		NUM_SPH_MODE*NUM_MODE_PARAS*sizeof(uint16));
	gSpe.setNvramValuesFlag |= SPE_NVRAM_VALUES_FLAG_MODE;
}

void spe_setHacSpeechModePara(kal_uint16 * modePara, kal_int16 length)
{
	ASSERT(NUM_MODE_PARAS == length);
	
	memcpy(gSpe.sph_allModePara[NUM_SPH_MODE], modePara, NUM_MODE_PARAS*sizeof(uint16));
}

uint16 *SPE_getAllSpeechModePara(void)
{
	return (uint16 *)gSpe.sph_allModePara;
}

void l1sp_setAllSpeechFirCoeff_InputOnly(kal_int16 *speech_input_FIR_coeffs, kal_int16 length)
{
	ASSERT((NUM_SPH_INPUT_FIR*NUM_FIR_COEFFS) == length);
	
	memcpy(gSpe.sph_allInFirCoeff, speech_input_FIR_coeffs, 
		NUM_SPH_INPUT_FIR*NUM_FIR_COEFFS*sizeof(int16));
	gSpe.setNvramValuesFlag |= SPE_NVRAM_VALUES_FLAG_IN_FIR;

}

void spe_setHacSpeechFirCoeff_InputOnly(kal_int16 *fIR_coeffs, kal_int16 length)
{
	ASSERT(NUM_FIR_COEFFS == length);
	
	memcpy(gSpe.sph_allInFirCoeff[NUM_SPH_INPUT_FIR], fIR_coeffs, NUM_FIR_COEFFS*sizeof(int16));
}

int16 *SPE_getAllSpeechFirCoeff_InputOnly(void)
{
	return (int16 *)gSpe.sph_allInFirCoeff;
}

void l1sp_setAllSpeechFirCoeff_OutputOnly(kal_int16 *speech_output_FIR_coeffs, kal_int16 length)
{
	ASSERT((NUM_SPH_OUTPUT_FIR*NUM_FIR_COEFFS) == length);
	
	memcpy(gSpe.sph_allOutFirCoeff, speech_output_FIR_coeffs,
		NUM_SPH_OUTPUT_FIR*NUM_FIR_COEFFS*sizeof(int16));
	gSpe.setNvramValuesFlag |= SPE_NVRAM_VALUES_FLAG_OUT_FIR;
}

void spe_setHacSpeechFirCoeff_OutputOnly(kal_int16 *fIR_coeffs, kal_int16 length)
{
	ASSERT(NUM_FIR_COEFFS == length);
	
	memcpy(gSpe.sph_allOutFirCoeff[NUM_SPH_OUTPUT_FIR], fIR_coeffs, NUM_FIR_COEFFS*sizeof(int16));
}


int16 *SPE_getAllSpeechFirCoeff_OutputOnly(void)
{
	return (int16 *)gSpe.sph_allOutFirCoeff;
}

//--------------- WB ----------------
void l1sp_setAllWbSpeechModePara(kal_uint16 * speech_mode_para, kal_int16 length)
{
	ASSERT((NUM_SPH_MODE*NUM_MODE_PARAS) == length);
	
	memcpy(gSpe.sph_allWbModePara, speech_mode_para, 
		NUM_SPH_MODE*NUM_MODE_PARAS*sizeof(uint16));
	gSpe.setNvramValuesFlag |= SPE_NVRAM_VALUES_FLAG_WB_MODE; // (1<<3) bit [3]

}

void spe_setHacWbSpeechModePara(kal_uint16 * modePara, kal_int16 length)
{
	ASSERT(NUM_MODE_PARAS == length);
	
	memcpy(gSpe.sph_allWbModePara[NUM_SPH_MODE], modePara, NUM_MODE_PARAS*sizeof(uint16));
}


kal_uint16 *SPE_getAllWbSpeechModePara(void)
{
	return (uint16 *)(gSpe.sph_allWbModePara);
}

void l1sp_setAllWbSpeechFirCoeff_InputOnly(
		kal_int16 *speech_input_FIR_coeffs, kal_int16 length)
{
	ASSERT((NUM_SPH_INPUT_FIR*NUM_WB_FIR_COEFFS) == length);
	memcpy(gSpe.sph_allWbInFirCoeff, speech_input_FIR_coeffs, 
		length*sizeof(int16));
	gSpe.setNvramValuesFlag |= SPE_NVRAM_VALUES_FLAG_WB_IN_FIR; // (1<<4) bit [4]
}

void spe_setHacWbSpeechFirCoeff_InputOnly(kal_int16 *fIR_coeffs, kal_int16 length)
{
	ASSERT(NUM_WB_FIR_COEFFS == length);
	
	memcpy(gSpe.sph_allWbInFirCoeff[NUM_SPH_INPUT_FIR], fIR_coeffs, NUM_WB_FIR_COEFFS*sizeof(int16));
}


kal_int16 *SPE_getAllWbSpeechFirCoeff_InputOnly(void)
{
	return (int16 *)gSpe.sph_allWbInFirCoeff;
}


void l1sp_setAllWbSpeechFirCoeff_OutputOnly(
		kal_int16 *speech_output_FIR_coeffs, kal_int16 length)
{
	ASSERT((NUM_SPH_OUTPUT_FIR*NUM_WB_FIR_COEFFS) == length);
	memcpy(gSpe.sph_allWbOutFirCoeff, speech_output_FIR_coeffs,
		length*sizeof(int16));
	gSpe.setNvramValuesFlag |= SPE_NVRAM_VALUES_FLAG_WB_OUT_FIR; // (1<<4) bit [4]
}

void spe_setHacWbSpeechFirCoeff_OutputOnly(kal_int16 *fIR_coeffs, kal_int16 length)
{
	ASSERT(NUM_WB_FIR_COEFFS == length);
	
	memcpy(gSpe.sph_allWbOutFirCoeff[NUM_SPH_OUTPUT_FIR], fIR_coeffs, NUM_WB_FIR_COEFFS*sizeof(int16));
}

kal_int16 *SPE_getAllWbSpeechFirCoeff_OutputOnly(void)
{
	return (int16 *)gSpe.sph_allWbOutFirCoeff;
}

//--------------- DMNR ----------------


#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	

/**
	Not support parameter rewirte under application begin runnning
*/
void L1SP_SetDMNRPara( const kal_int16 DMNR_para[NUM_DMNR_PARAM] )
{
	
	memcpy(&gSpe.sph_dmnr_para, DMNR_para, NUM_DMNR_PARAM*sizeof(uint16));
}

#if defined(__AMRWB_LINK_SUPPORT__)
/**
	Not support parameter rewirte under application begin runnning
*/
void L1SP_SetWbDMNRPara( const kal_int16 WB_DMNR_para[NUM_WB_DMNR_PARAM] )
{
	memcpy(&gSpe.sph_wb_dmnr_para, WB_DMNR_para, NUM_WB_DMNR_PARAM*sizeof(uint16));
}
#endif //__AMRWB_LINK_SUPPORT__

/**
	Not support parameter rewirte under application begin runnning
*/
void L1SP_SetLSpkDMNRPara( const kal_int16 LSpk_DMNR_para[NUM_DMNR_PARAM] )
{	
	memcpy(&gSpe.sph_lspk_dmnr_para, LSpk_DMNR_para, NUM_DMNR_PARAM*sizeof(uint16));
}

#if defined(__AMRWB_LINK_SUPPORT__)

/**
	Not support parameter rewirte under application begin runnning
*/
void L1SP_SetLSpkWbDMNRPara( const kal_int16 LSpk_Wb_DMNR_para[NUM_WB_DMNR_PARAM] )
{
	memcpy(&gSpe.sph_lspk_wb_dmnr_para, LSpk_Wb_DMNR_para, NUM_WB_DMNR_PARAM*sizeof(uint16));
}
#endif //__AMRWB_LINK_SUPPORT__

#endif //__DUAL_MIC_SUPPORT__ || defined(__SMART_PHONE_MODEM__)	


//--------------- MagiCon (Loudspeaker mode)  ---------------------

bool spe_isSpeFweOn(void)
{
	return gSpe.spe_isFweOn;
}

void spe_setMagiConParam(uint16 *nbParam, uint16 *wbParam)
{
	memcpy(gSpe.sph_magicConParam, nbParam, sizeof(kal_uint16) * NUM_MODE_PARAS);
	memcpy(gSpe.sph_magicConWbParam, wbParam, sizeof(kal_uint16) * NUM_MODE_PARAS);
	gSpe.isMagiConOn = true;
	gSpe.spe_isFweOn = true;
}

//--------------- New Modes ---------------------

void spe_setHacModeNeeded(bool isNeed)
{
	gSpe.isHacModeNeeded = isNeed;
}

//--------------- viberation speaker ----------------

void spe_setNotchFilterParam(int16 *param, bool is2In1Spk)
{
	AM_SetNotchFilterParam(param);
	gSpe.isEnableNotchFilter = true;
	gSpe.is2In1Spk = is2In1Spk;
}


/* ========================================================================= */

uint16 l1sp_GetSpeState(void)
{
	return gSpe.spe_state;
}

uint8 SPE_GetSpeechMode(void)
{
	return gSpe.sph_mode;
}

/**
	Use currect information inside gSpe to decide the mode paramters. 
	@m_para: nb para result
	@m_para_wb: wb para result
*/
void spe_chooseSpeechModeParam(uint16 m_para[NUM_MODE_PARAS], uint16 m_para_wb[NUM_MODE_PARAS])
{

	switch(gSpe.sph_mode) 
	{
		case SPH_MODE_HAC:
			ASSERT(true == gSpe.isHacModeNeeded);
		case SPH_MODE_NORMAL:
		case SPH_MODE_EARPHONE:
		case SPH_MODE_BT_EARPHONE:			
		case SPH_MODE_BT_CORDLESS:
		case SPH_MODE_BT_CARKIT:
		case SPH_MODE_AUX1:
		case SPH_MODE_AUX2:
			memcpy(m_para, gSpe.sph_allModePara[gSpe.sph_mode], sizeof(uint16)*NUM_MODE_PARAS);
			memcpy(m_para_wb, gSpe.sph_allWbModePara[gSpe.sph_mode], sizeof(uint16)*NUM_MODE_PARAS);
			break;
		case SPH_MODE_LOUDSPK:
			if(true == gSpe.isMagiConOn) {				
				if((gSpe.spe_usr_sub_mask & (1<<SAL_ENH_DYNAMIC_DMNR_HF_MUX))!=0) { // magiConference is on
					memcpy(m_para, gSpe.sph_magicConParam, sizeof(uint16)*NUM_MODE_PARAS);
					memcpy(m_para_wb, gSpe.sph_magicConWbParam, sizeof(uint16)*NUM_MODE_PARAS);
				} else { // HF DMNR
					memcpy(m_para, gSpe.sph_allModePara[gSpe.sph_mode], sizeof(uint16)*NUM_MODE_PARAS);
					memcpy(m_para_wb, gSpe.sph_allWbModePara[gSpe.sph_mode], sizeof(uint16)*NUM_MODE_PARAS);
				}
			} else { // normal HF DMNR
				memcpy(m_para, gSpe.sph_allModePara[gSpe.sph_mode], sizeof(uint16)*NUM_MODE_PARAS);
				memcpy(m_para_wb, gSpe.sph_allWbModePara[gSpe.sph_mode], sizeof(uint16)*NUM_MODE_PARAS);
			}
			break;
		default: 
			ASSERT(0);
	}
		
		
}


void spe_setSpeechMode( uint8 afterSalDevMode, uint8 after_sph_mode)
{   
	kal_bool preIsBt;
	kal_bool afterIsBt;
	kal_bool isSpeechOn; 
	kal_bool isPcmRoutOn;
	kal_bool isAmInSpeechState;
	uint16 m_para[NUM_MODE_PARAS];
	uint16 m_paraWb[NUM_MODE_PARAS];
	
	uint8 prev_sph_mode = gSpe.sph_mode;
	
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   // kal_uint16 aud_id = L1SP_GetAudID();
   kal_uint16 aud_id = L1Audio_GetAudioID();
   L1Audio_SetFlag( aud_id );
#endif   

	//------------------------------------------------------
	// DEV and SPH mode choice / fix for special cases
	//------------------------------------------------------
#ifdef SPH_CHIP_BACK_MODE_FIX_TO_NORMAL
	afterSalDevMode = SAL_DEV_NORMAL;
   after_sph_mode = SPH_MODE_NORMAL; // force setting to normal mode
#endif

#if defined(__ENABLE_SPEECH_DVT__)
    extern kal_bool Is_Sph_DVT_BT_Mode_NB(void);
    extern kal_bool Is_Sph_DVT_BT_Mode_WB(void);
    if (Is_Sph_DVT_BT_Mode_NB())
    {
        AFE_SetVoice8KMode(0);
        afterSalDevMode = SAL_DEV_BT_EARPHONE_NB;
        after_sph_mode = SPH_MODE_BT_EARPHONE;
    }
    else if (Is_Sph_DVT_BT_Mode_WB())
    {
        AFE_SetVoice8KMode(1);
        afterSalDevMode = SAL_DEV_BT_EARPHONE_WB;
        after_sph_mode = SPH_MODE_BT_EARPHONE;
    }
#endif // defined(__ENABLE_SPEECH_DVT__)

   kal_trace(TRACE_INFO, L1SP_PHONE_CALL, 4, prev_sph_mode, afterSalDevMode);
	kal_trace( TRACE_INFO, L1SP_CHANGE_ENH_MODE, prev_sph_mode, after_sph_mode, gSpe.sph_mode); 

	//------------------------------------------------------
	// Turn off process
	//------------------------------------------------------
	preIsBt = ( (SPH_MODE_BT_EARPHONE==prev_sph_mode) || 
		(SPH_MODE_BT_CORDLESS==prev_sph_mode) ||
		(SPH_MODE_BT_CARKIT==prev_sph_mode) );
	afterIsBt = ( (SPH_MODE_BT_EARPHONE==after_sph_mode) || 
		(SPH_MODE_BT_CORDLESS==after_sph_mode) ||	
		(SPH_MODE_BT_CARKIT==after_sph_mode) );
	isSpeechOn = AM_IsSpeechOn();
	isPcmRoutOn = AM_IsVoIPOn();
	isAmInSpeechState = AM_IsAmInSpeechState();

#if defined(__CVSD_CODEC_SUPPORT__) 
   if( (prev_sph_mode != after_sph_mode) && BT_SCO_IS_SPEECH_ON() )
   {
      BT_SCO_SPEECH_OFF();
   }
#endif
	
	// Always turn off the enhancement first in order to feed the parameter to DSP in the run time(under call)
	// beacuse enhancement only get the parameter under enable state machine
	SetSpeechEnhancement( false );
	

   if(preIsBt != afterIsBt){ // need off on speech , due to speech buffer changes between VBI and DAI
   	// turn off DSP app
   	if(true == isAmInSpeechState){
			if(true == isSpeechOn) {
				AM_SpeechOff(1); // turn off 8k and speech off

			} else if (true == isPcmRoutOn){
				AM_PcmRouter_Off();
			} else { // cordless mode / speech 
				
				// if( prev_sph_mode == SPH_MODE_BT_CORDLESS ) {
			  	// 	AM_BTCordlessOff();
		   	// } else {		   		
					ASSERT(0); // Do not handle here. Please handle it on application
					// AM_PCM_EX_Off(AM_PCMEX_TYPE type,uint32 p2exData)
		   	// }
				
			}
   	}
			
		if(sp_getIsBtOn()) // if(l1sp.bt_on)
		{
			AM_BluetoothOff();
			sp_setBtOn(false);//l1sp.bt_on = false;
		}
   }

	//------------------------------------------------------
	// Changing
	//------------------------------------------------------
	
	// Begin apply the new device and enhancement parameter
	if((SPH_MODE_BT_EARPHONE==after_sph_mode) || 
		(SPH_MODE_BT_CARKIT==after_sph_mode)) {
		// get sampling rate information from AFE information
		if(0== AFE_GetVoice8KMode()) { // NB
			SAL_Set_Device(SAL_DEV_BT_EARPHONE_NB);
		} else { //WB
			SAL_Set_Device(SAL_DEV_BT_EARPHONE_WB);
		}
	} else {
		SAL_Set_Device(afterSalDevMode);
	}
	
	gSpe.sph_mode = after_sph_mode;		
	
	// memcpy(l1sp.sph_m_para, m_paras, NUM_MODE_PARAS*sizeof(uint16));
	spe_chooseSpeechModeParam(m_para, m_paraWb);
	SP_SetSpeechPara(m_para);
	SP_SetWbSpeechPara(m_paraWb);
	kal_trace(TRACE_INFO, L1SP_MODE_VALUE, m_para[0], m_para[1], m_para[2], m_para[3], m_para[4], m_para[5], m_para[6], m_para[7], m_para[8], m_para[9], m_para[10], m_para[11], m_para[12], m_para[13], m_para[14], m_para[15]);
	kal_trace(TRACE_INFO, L1SP_MODE_VALUE, m_paraWb[0], m_paraWb[1], m_paraWb[2], m_paraWb[3], m_paraWb[4], m_paraWb[5], m_paraWb[6], m_paraWb[7], m_paraWb[8], m_paraWb[9], m_paraWb[10], m_paraWb[11], m_paraWb[12], m_paraWb[13], m_paraWb[14], m_paraWb[15]);

	//------------------------------------------------------
	// Turn on
	//------------------------------------------------------
	if(preIsBt != afterIsBt){ // need off on speech, due to speech buffer changes between VBI and DAI
		
		if(afterIsBt)
		{
			if ((after_sph_mode==SPH_MODE_BT_CORDLESS || after_sph_mode==SPH_MODE_LINEIN_VIA_BT_CORDLESS)) 
         {
         	AM_BluetoothOn(1);
			} else {
				AM_BluetoothOn(2);
			}
			
			sp_setBtOn(true); // l1sp.bt_on = true;
		}

		if(true == isAmInSpeechState){
			if(true == isSpeechOn) {				
			   uint32 rat = AM_GetNetworkRate();			
				// [REMIND]L1SP_STATE_xx can mapping to RAT_2G_MODE using "index -1"
				ASSERT(L1SP_STATE_IDLE != L1SP_GetState());
				ASSERT( 
#if defined(__VOLTE_SUPPORT__) 
  				       RAT_4G_MODE == rat || 
#endif  				 
                   RAT_3G_MODE == rat || RAT_2G_MODE == rat            
  				       );
				AM_SpeechOn(rat, 1); 
				
			} else if (true == isPcmRoutOn){
				AM_PcmRouter_On();
			} else { // cordless mode / speech 
				
				// if( after_sph_mode == SPH_MODE_BT_CORDLESS ) {
			  	// 	AM_BTCordlessOn();
		   	// } else {		   		
					ASSERT(0); // Do not handle here. Please handle it on application
					// AM_PCM_EX_Off(AM_PCMEX_TYPE type,uint32 p2exData)
		   	// }
				
			}
   	}
   }
	
   kal_trace( TRACE_INFO, L1SP_SET_MODE, gSpe.sph_mode, -1, 0 );
   SetSpeechEnhancement( true );

#if defined(__CVSD_CODEC_SUPPORT__) 
   if( (SPH_MODE_BT_EARPHONE==after_sph_mode) || (SPH_MODE_BT_CARKIT==after_sph_mode) )
   {
      if(isSpeechOn && !BT_SCO_IS_SPEECH_ON())
      {
         kal_bool is_WB = AFE_GetVoice8KMode() == 1 ? KAL_TRUE : KAL_FALSE;
         BT_SCO_SPEECH_ON(is_WB);
      }
   }
#endif

	//------------------------------------------------------
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
   L1Audio_ClearFlag( aud_id );
   L1Audio_FreeAudioID( aud_id );
#endif   	

}


void SetSpeechEnhancement( bool ec )
{

	// For hosted dongle, speech enhancment is not existing by default. 
	// For RNDIS, speech is useless, so don't care.
	// For super dongle, speech is useful. 
	// As the result, condition is: (chip list) && (data card case without spe enable)
#if (defined(MT6280) || defined(MT6290)) && (defined(__DATA_CARD_SPEECH__) && !defined(DACA_SPE_ENABLE_INTERNAL))
   return; 
#endif // (defined(MT6280)) && (defined(__DATA_CARD_SPEECH__) && !defined(DACA_SPE_ENABLE_INTERNAL))

#if defined(SPH_CHIP_BACK_PHONECALL_USE)
	return;
#endif // SPH_CHIP_BACK_PHONECALL_USE

	// speech is not working. 
   if ((!AM_IsAmInSpeechState()) || (!gSpe.spe_flag)) 
      return;

	//speech mode is not in definition.
   ASSERT(gSpe.sph_mode<SPH_MODE_UNDEFINED);

   kal_trace( TRACE_INFO, L1SP_APPLY_MODE, (ec)?1:0, gSpe.sph_mode, -1, 0 ); 
   if( ec ) {
      uint16 next_state, keep_on_state, on_state, off_state;  
		uint8 i;
		
		// Update Usr Sub Mask to DSP ENH Dynamic control, 
		// [Remind] 1. ignore SAL_ENH_DYNAMIC_MUTE_UL, because DSP using same sherif to control
		// [Remind] 2. SAL_ENH_DYNAMIC_DMNR_HF_MUX(bit6)'s definition is different from AP and DSP, so driver skip it. 
		ASSERT(SAL_ENH_DYNAMIC_NUM<=L1SP_ENH_DYNAMIC_NUM);
		for(i=SAL_ENH_DYNAMIC_DMNR_MUX; i<SAL_ENH_DYNAMIC_NUM ; i++){
			L1SP_SPE_SUBMASK_VALUES subMask = spe_subMask_table[gSpe.sph_mode][i]; 

			// bit wise update the sub mask (dynamic control for SPE)
			switch(subMask){
				case L1SP_SPE_SUBMASK_BYMASK:
					SAL_ENH_Dynamic_Ctrl(((gSpe.spe_usr_sub_mask & (1<<i))!=0), i);
					break;
				case L1SP_SPE_SUBMASK_BYMASK_SP1: // only for loud speaker DMNR
					if(true == gSpe.isMagiConOn) {
						SAL_ENH_Dynamic_Ctrl( ((gSpe.spe_usr_sub_mask & (1<<SAL_ENH_DYNAMIC_DMNR_HF_MUX))!=0) ,i);
					} else {
						SAL_ENH_Dynamic_Ctrl(false ,i);
					}
					break;
				case L1SP_SPE_SUBMASK_DONT_CARE_NO_STATE_MACHINE: // default true
				case L1SP_SPE_SUBMASK_DONT_CARE_NO_EM_VALUE:
				case L1SP_SPE_SUBMASK_SKIP_DEFAULT_ON:
					SAL_ENH_Dynamic_Ctrl(true, i);
					break;
				case L1SP_SPE_SUBMASK_SKIP:
					break;
			}
			kal_trace( TRACE_INFO, L1SP_SET_ENHANCEMENT_SUB_MASK, i, subMask);
			//SAL_ENH_Dynamic_Ctrl(((gSpe.spe_usr_sub_mask & (1<<i))!=0), i);
		}

		if(true == gSpe.spe_isFweOn) {
			SAL_ENH_Dynamic_Ctrl(true, SAL_ENH_DYNAMIC_DMNR_HF_MUX); 
		} else {
			SAL_ENH_Dynamic_Ctrl(false, SAL_ENH_DYNAMIC_DMNR_HF_MUX); 
		}
	
      next_state = spe_table[gSpe.sph_mode];
	  // using gSpe.spe_mask to control the open/close of speech enhancment. 
      for(i=0; i< NUM_OF_SPH_FLAG; i++) {
	     uint16 tempMaskBit = (1<<i);
	     if((
	        ((gSpe.spe_app_mask & tempMaskBit) == 0 ) || 
	        ((gSpe.spe_usr_mask & tempMaskBit) == 0 ) 
	        )&& (next_state & tempMaskBit))
         {
            next_state -=tempMaskBit;
         }
	  }

      switch( gSpe.sph_mode ) {
			case SPH_MODE_NORMAL:
			case SPH_MODE_HAC:
				if(true == gSpe.isEnableNotchFilter){ // when ap turn ON notch filter
					if(true == gSpe.is2In1Spk) { // check speaker choise on NORMAL mode
						next_state &= (~SPH_ENH_MASK_NOTCH_FILTER);
					}
				}
			case SPH_MODE_LOUDSPK:
				if(false == gSpe.isEnableNotchFilter){ // when ap do NOT turn on notch filter under normal mode & loud speaker mode
					next_state &= (~SPH_ENH_MASK_NOTCH_FILTER);
				}
				
				if(SPH_MODE_LOUDSPK == gSpe.sph_mode) {
					if(true == SPE_AgcInfo_IsNxpPaOn()) { // when NXP is On, turn DMNR off and support TDDNC(in next expression). 
						next_state |= SPH_ENH_MASK_ECHO_REF; 
#ifdef MDAFE_2IN_1OUT
						next_state &= (~SPE_DMNR_FLAG);
#endif 
					}					
				}
// #if TDDNC_SUPPORT				
				if(0==(next_state&SPE_DMNR_FLAG)) { // when DMNR is off, use TDDNC
					next_state |= SPE_TDDNC_FLAG;
				}
// #endif				
				break;

//      #if defined(__BT_SUPPORT__)     
         case SPH_MODE_BT_EARPHONE:
         case SPH_MODE_BT_CORDLESS:
         case SPH_MODE_BT_CARKIT:
            ASSERT( AM_IsBluetoothOn() );
            break;
//      #endif       
         default:
            break;         	
      }

		// dynamic download when turn on speech enhancement
		if(0 == gSpe.spe_state){
	 
#if defined(AEC_ENABLE)
#if defined(SPH_CHIP_BACK_PHONECALL_USE)
			// do not download speech enhancment
#else 

#if DSP_DYNAMDOWNLOAD_TDNC_DMNR_EXOR
      if(next_state&SPE_DMNR_FLAG)
      {  // DMNR
      	 if(gSpe.sph_mode == SPH_MODE_LOUDSPK)
      	 {
				    DSP_DynamicDownload( DDID_SPH_TCH_2 );   
			   } 
			   else 
			   {
				   DSP_DynamicDownload( DDID_SPH_TCH_1 );   
			   }      	 	 
      }
      else //  TDDNC
      {
         DSP_DynamicDownload( DDID_SPH_TCH_3 );       	 
      }

#elif SPE_LOUDSPK_DMNR
			if(gSpe.sph_mode == SPH_MODE_LOUDSPK){
				DSP_DynamicDownload( DDID_SPH_TCH_2 );   
			} else {
				DSP_DynamicDownload( DDID_SPH_TCH_1 );   
			}
#else
			DSP_DynamicDownload( DDID_NOISE_REDUCTION );   
#endif

#endif // SPH_CHIP_BACK_PHONECALL_USE
#endif //  defined(AEC_ENABLE)
      }

      keep_on_state = next_state & gSpe.spe_state; 
      on_state = next_state - keep_on_state; 
      off_state = gSpe.spe_state - keep_on_state;

      kal_trace( TRACE_INFO, L1SP_SET_ENHANCEMENT, keep_on_state, on_state, off_state);
   
      if(off_state != 0) 
         SPE_TurnOffProcess(off_state);   

    
      if(next_state != 0)
      {
      	uint16 *c_param = Sp_GetCommonSpeechPara();
			uint16 *m_param = Sp_GetSpeechPara();
			uint16 *m_param_wb = Sp_GetWbSpeechPara();
         kal_trace( TRACE_INFO, L1SP_SPEECH_ENHANCEMENT, next_state,
            *m_param, *(m_param+1), *c_param, *(c_param+11));// l1sp.sph_c_para[0], l1sp.sph_c_para[1] );

			// reload the parameters
         if(next_state & (SPE_AEC_FLAG + SPE_EES_FLAG + SPE_UL_NR_FLAG + SPE_DL_NR_FLAG + SPE_TDDNC_FLAG))
				SPE_LoadSpeechPara(c_param, m_param, NULL, m_param_wb); // l1sp.sph_v_para seems no one use it

#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
			if(next_state & SPE_DMNR_FLAG)
			{
				if(SPH_MODE_LOUDSPK == gSpe.sph_mode) { // load the loud speaker mode DMNR parameter
					SPE_LoadDmnrCoeffs(gSpe.sph_lspk_dmnr_para);
#if defined(__AMRWB_LINK_SUPPORT__)
					SPE_LoadWbDmnrCoeffs(gSpe.sph_lspk_wb_dmnr_para);
#endif //__AMRWB_LINK_SUPPORT__

				} else {				
			 		SPE_LoadDmnrCoeffs(gSpe.sph_dmnr_para);	
#if defined(__AMRWB_LINK_SUPPORT__)
					SPE_LoadWbDmnrCoeffs(gSpe.sph_wb_dmnr_para);
#endif //__AMRWB_LINK_SUPPORT__
				}

		 	}
#endif //__DUAL_MIC_SUPPORT__ || defined(__SMART_PHONE_MODEM__)	

         if(on_state != 0) 
            SPE_TurnOnProcess(on_state);

#if defined(__SMART_PHONE_MODEM__) // using software sidetone
			if(SPH_ENH_MASK_SIDETONE & on_state) {
				SIDETONE_TurnSwSidetoneOn(true);
			}
#endif // !defined(SMART_PHONE_HW_SIDETONE_SUPPORT)

			// notch filter for 3-in 1 speaker
			if( SPH_ENH_MASK_NOTCH_FILTER& on_state ) {
				//reload the coefficient
				AM_DSP_WriteNotchFilterParam();
				
				// turn on 
				SAL_NotchFilter_Enable(true , false);
			}
			
      }
      gSpe.spe_state = next_state;
      SPE_Clear_DLL_Entry(gSpe.spe_state);
   }
   else {
      if(gSpe.spe_state != 0)
      {
         SPE_TurnOffProcess(gSpe.spe_state);  

#if defined(__SMART_PHONE_MODEM__) // using software sidetone			
			if(SPH_ENH_MASK_SIDETONE & gSpe.spe_state) {
				SIDETONE_TurnSwSidetoneOn(false);
			}
#endif // !defined(SMART_PHONE_HW_SIDETONE_SUPPORT)		

			if(SPH_ENH_MASK_NOTCH_FILTER& gSpe.spe_state) {
				// turn off 
				SAL_NotchFilter_Enable(false , false);
			}
			
         gSpe.spe_state = 0;
         SPE_Clear_DLL_Entry(0);
      }
#ifdef __TWOMICNR_SUPPORT__
      if ( gSpe.sph_mode == SPH_MODE_LOUDSPK || gSpe.sph_mode == SPH_MODE_NORMAL )
      {
         Two_Mic_NR_chip_Sleep();
         kal_trace(TRACE_STATE, L1SP_2MIC_SLEEP);
      }
      else{
         Two_Mic_NR_chip_exit_Bypass_mode();
         kal_trace(TRACE_STATE, L1SP_2MIC_EXIT_BYPASS);
      }
#endif
#if defined(__TC01_VOICE_ENGINE__)
      VC_Stop();
      VS_Stop();
#endif
   }

#if 0
/* under construction !*/
/* under construction !*/
#if !USE_AEC
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
#endif	
}

void spe_write_Audio_Coefficients_ByFirIndex( const uint8 inFirIndex, 
	const uint8 outOrIn2FirIndex)
{
	kal_uint16 aud_id;
	int16 inCoeff[NUM_FIR_COEFFS];
	int16 outOrIn2Coeff[NUM_FIR_COEFFS];
		
	if(inFirIndex == 0xff) {
		inCoeff[0] = 0x7fff;
		memset(&inCoeff[1], 0, (NUM_FIR_COEFFS-1)*sizeof(int16));
	} else {
		memcpy(inCoeff, gSpe.sph_allInFirCoeff[inFirIndex], (NUM_FIR_COEFFS)*sizeof(int16));		
	}

	if(outOrIn2FirIndex == 0xff) {
		outOrIn2Coeff[0] = 0x7fff;
		memset(&outOrIn2Coeff[1], 0, (NUM_FIR_COEFFS-1)*sizeof(int16));
	} else {
		memcpy(outOrIn2Coeff, gSpe.sph_allOutFirCoeff[outOrIn2FirIndex], (NUM_FIR_COEFFS)*sizeof(int16));		
	}

	// l1sp_Write_Audio_Coefficients( inCoeff, outOrIn2Coeff );
#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))
	aud_id = L1Audio_GetAudioID();
	L1Audio_SetFlag( aud_id );
#endif   

   AM_WriteFirCoeffs( inCoeff, outOrIn2Coeff );

#if ( defined( __CENTRALIZED_SLEEP_MANAGER__ )&& defined( MTK_SLEEP_ENABLE ))   
	L1Audio_ClearFlag( aud_id );
	L1Audio_FreeAudioID( aud_id );   
#endif 
	
}

static void spe_getFirMappingByScene(const uint32 scene, 
	uint8 *devMode, uint8 *enhMode,
	uint8 *inFir, uint8 *outFir)
{
	uint8 tempDevMode = 0xff; 
	uint8 tempEnhMode = 0xff;
	uint8 tempInFir = 0xff; 
	uint8 tempOutFir = 0xff;
	
	switch(scene) {
	case SPH_ENH_AND_FIR_SCENE_NORMAL:
		tempDevMode = SAL_DEV_NORMAL; // SPH_MODE_NORMAL;
		tempEnhMode = SPH_MODE_NORMAL;
		tempInFir = SPH_FIR_COEFF_NORMAL;
		tempOutFir = SPH_FIR_COEFF_NORMAL;
		
		break;
	case SPH_ENH_AND_FIR_SCENE_EARPHONE:
	case SPH_ENH_AND_FIR_SCENE_LOUDSPK:
		tempDevMode = scene; // SAL_DEV_EARPHONE or SAL_DEV_LOUDSPK
		tempEnhMode = scene;
		tempInFir = scene;
		tempOutFir = scene;
		break;	
// #if defined(__BT_SUPPORT__)		
	case SPH_ENH_AND_FIR_SCENE_BT_EARPHONE:	
	case SPH_ENH_AND_FIR_SCENE_BT_CARKIT:
		tempDevMode = SAL_DEV_BT_EARPHONE_NB; //scene;
		tempEnhMode = scene;
		tempInFir = SPH_FIR_COEFF_BT; 
		tempOutFir = SPH_FIR_COEFF_BT;
		break;

	case SPH_ENH_AND_FIR_SCENE_BT_CORDLESS:		
#if defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6290) || defined(MT6592) || defined(MT6571) || defined(MT6595) || defined(MT6752)// hw did not support
		ASSERT(0);
#else 
		tempDevMode = SAL_DEV_BT_CORDLESS; //scene;
		tempEnhMode = scene;
		tempInFir = SPH_FIR_COEFF_BT; 
		tempOutFir = SPH_FIR_COEFF_BT;
#endif		
		break;
//#endif
	case SPH_ENH_AND_FIR_SCENE_AUX1: // AUX is use to  loud speaker mode
		tempDevMode = SAL_DEV_LOUDSPK; //scene
		tempEnhMode = SPH_MODE_AUX1; //scene
		tempInFir = SPH_FIR_COEFF_HANDFREE;
		tempOutFir = SPH_FIR_COEFF_HANDFREE;
		break;
	case SPH_ENH_AND_FIR_SCENE_AUX2:
		tempDevMode = SPH_MODE_NORMAL;
		tempEnhMode = SPH_MODE_AUX2;
		tempInFir = SPH_FIR_COEFF_NORMAL;
		tempOutFir = SPH_FIR_COEFF_NORMAL;
		break;
		
	case SPH_ENH_AND_FIR_SCENE_HAC:
		ASSERT(true == gSpe.isHacModeNeeded); // is AP did not set the mode parameter. assert it directly! 
		
		tempDevMode = SPH_MODE_NORMAL;
		tempEnhMode = SPH_MODE_HAC;
		tempInFir = SPH_FIR_COEFF_HAC;
		tempOutFir = SPH_FIR_COEFF_HAC;
		break;

	default:
		{
			ASSERT(0);
		}

	}
	
	*devMode = tempDevMode;
	*enhMode = tempEnhMode;
	*inFir = tempInFir;
	*outFir = tempOutFir;
	
}

/**
	new interface to replace L1SP_SetSpeechMode(), L1SP_Write_Audio_Coefficients(), 
	L1SP_Write_WB_Audio_Coefficients() in the same time. 

	if you want to use personal configuration, you can use original interfaces. 

	@scene: [Input] scenario for different enhancement and fir combination. 
*/
void L1SP_SetSpeechEnhanceAndFir(uint32 scene, uint32 updatedCoeff)

{
	uint8 modeIndex = 0;
	uint8 inFirIndex = 0;
	uint8 outFirIndex = 0;
	uint8 devModeIndex = 0; 


	//speech mode
//----------------- original scenario ---------------
	if(scene <SPH_MODE_UNDEFINED)
	{ //keeping the original scenario

		spe_getFirMappingByScene(scene, &devModeIndex, &modeIndex, 
			&inFirIndex, &outFirIndex);

// #ifdef WB_SPE_SUPPORT 
		if((updatedCoeff == 0) || (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_WB_FIR)!=0){
			if((gSpe.setNvramValuesFlag & SPE_NVRAM_VALUES_FLAG_WB_IN_FIR)
				&& (gSpe.setNvramValuesFlag & SPE_NVRAM_VALUES_FLAG_WB_OUT_FIR)) {

				AM_WriteWbFirCoeffs(gSpe.sph_allWbInFirCoeff[inFirIndex],
					gSpe.sph_allWbOutFirCoeff[outFirIndex]);
			}
		}
// #endif	
	
		// Write NB FIR
		// this function needs to after WB Fir Coeffs are set. Because BKF enable is in this function
		if((updatedCoeff == 0) || (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_NB_FIR)!=0)
			spe_write_Audio_Coefficients_ByFirIndex(inFirIndex, outFirIndex); 
	
		//speech mode
		/* combine the enhancment setting into one function
		if((updatedCoeff == 0) || (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_WB_ENH_MODE)!=0){
			if(gSpe.setNvramValuesFlag & SPE_NVRAM_VALUES_FLAG_WB_MODE)//(l1sp.has_all_wb_sph_m_para)
				SP_SetWbSpeechPara(gSpe.sph_allWbModePara[modeIndex]); //l1sp_SetWbSpeechPara(gSpe.sph_allWbModePara[modeIndex]);
		}
		*/

		if((updatedCoeff == 0) 
			|| (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_NB_ENH_MODE)!=0
			|| (updatedCoeff&SPH_ENH_AND_FIR_UPDATE_TYPE_WB_ENH_MODE)!=0)
			spe_setSpeechMode(devModeIndex, modeIndex); // spe_setSpeechMode(devModeIndex, modeIndex, gSpe.sph_allModePara[modeIndex]);
	

	}
//---------------------- undefined cases --------------------
	else { // undefined cases. 
		kal_trace ( TRACE_INFO, L1SP_USELESS_SET, scene, 0, 0);
	}
	
	//kal_trace( TRACE_INFO, L1SP_SET_ENH_FIR, scene, modeIndex, inFirIndex, outFirIndex, l1sp.spe_usr_mask, l1sp.spe_app_mask);
	kal_trace( TRACE_INFO, L1SP_SET_ENH_FIR, scene, modeIndex, inFirIndex, outFirIndex, 0,0);
	
}

// ----------------------------------------------------------------------------
// speech parameter loading
// ----------------------------------------------------------------------------
extern kal_bool setCommonPara;
extern uint16 commonPara_0;

void SPE_LoadSpeechPara( uint16 c_para[NUM_COMMON_PARAS], uint16 m_para[NUM_MODE_PARAS],uint16 v_para[NUM_VOL_PARAS],
	uint16 m_paraWb[NUM_MODE_PARAS])
{
   uint16 *para;
   volatile uint16* dsp_ptr;
   int I;

   if(c_para)
   {
      para = c_para;      
      dsp_ptr = SAL_CommonPar_GetBuf();
      for(I = SAL_PARAMETERLEN_COMMON; --I >= 0 ; )
         *dsp_ptr++ = *para++;
   }

   if(setCommonPara)
   {
      dsp_ptr = SAL_CommonPar_GetBuf();
      *dsp_ptr = commonPara_0;
   } 

   if(m_para)
   {
      para = m_para;      
      dsp_ptr = SAL_ModePar_GetBuf_NB();       
      for(I = SAL_PARAMETERLEN_MODE_NB; --I >= 0 ; )
         *dsp_ptr++ = *para++; 


   }
	
#if defined(__AMRWB_LINK_SUPPORT__)
	if(m_paraWb)
	{
		para = m_paraWb;      
      dsp_ptr = SAL_ModePar_GetBuf_WB();       
      for(I = SAL_PARAMETERLEN_MODE_WB; --I >= 0 ; )
         *dsp_ptr++ = *para++; 

	}
#endif		

}


/**
	The whole function is workable when "defined(__DUAL_MIC_SUPPORT__)"
*/
void SPE_LoadDmnrCoeffs(kal_int16 dmnr_para[NUM_DMNR_PARAM])
{
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	

	int i;
	volatile uint16* dsp_ptr;

	dsp_ptr = SAL_DMNR_GetFltCoefAddr_NB();


	for( i = 0; i<SAL_FLTCOEFLEN_DMNR_NB; i++) {
		*dsp_ptr++ = dmnr_para[i];
	}

#endif //__DUAL_MIC_SUPPORT__ || defined(__SMART_PHONE_MODEM__)	
}


/**
	The whole function is workable when "defined(__DUAL_MIC_SUPPORT__) &&  defined(__AMRWB_LINK_SUPPORT__)"
*/
void SPE_LoadWbDmnrCoeffs(kal_int16 wb_dmnr_para[NUM_WB_DMNR_PARAM])
{
#if (defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	) &&  defined(__AMRWB_LINK_SUPPORT__)

	int i;
	volatile uint16* dsp_ptr;
		
	dsp_ptr = SAL_DMNR_GetFltCoefAddr_WB();
	
	for( i = 0; i<SAL_FLTCOEFLEN_DMNR_WB; i++) {
		*dsp_ptr++ = wb_dmnr_para[i];
	}
	
#endif //(__DUAL_MIC_SUPPORT__|| defined(__SMART_PHONE_MODEM__)	) &&  __AMRWB_LINK_SUPPORT__
}

// ----------------------------------------------------------------------------
// enhancement control
// ----------------------------------------------------------------------------

void spe_updateSpeAppMask(uint8 updateFlags, bool enable)
{
	if(enable)
		gSpe.spe_app_mask |= (updateFlags);
	else
		gSpe.spe_app_mask &= ~(updateFlags);

	kal_trace( TRACE_INFO, L1SP_UPDATE_SPE_MASKS, 2, gSpe.spe_app_mask, gSpe.spe_usr_mask, gSpe.spe_usr_sub_mask, updateFlags, enable);	
}

/*
void l1sp_updateSpeUsrMask(uint8 updateFlags, bool enable)
{
	if(enable)
		gSpe.spe_usr_mask |= (updateFlags);
	else
		gSpe.spe_usr_mask &= ~(updateFlags);

	kal_trace( TRACE_INFO, L1SP_UPDATE_SPE_MASKS, 2, gSpe.spe_app_mask, gSpe.spe_usr_mask, gSpe.spe_usr_sub_mask, updateFlags, enable);	
}
*/
void spe_updateSpeUsrMaskWithWholeValue(uint16 newValue)
{
	kal_uint16 orgValue = gSpe.spe_usr_mask;

	gSpe.spe_usr_mask  = newValue;
	
	kal_trace( TRACE_INFO, L1SP_UPDATE_SPE_MASKS, 3, gSpe.spe_app_mask, gSpe.spe_usr_mask, gSpe.spe_usr_sub_mask, newValue, orgValue);	
	
	if(gSpe.spe_state) {// already turn on speech enhancement
      SetSpeechEnhancement(KAL_TRUE);
	}
		
}

/**
	@newValue: 
	typedef enum{
                // ==> SAL_ENH_DYNAMIC_MUTE_UL, bit 0. Please DO NOT use it
		SPE_DYNAMIC_MASK_DMNR = 0x1, // ==> SAL_ENH_DYNAMIC_DMNR_MUX, bit 1
		SPE_DYNAMIC_MASK_VCE  = 0x2, // ==> SAL_ENH_DYNAMIC_VCE_MUX, bit 2
		SPE_DYNAMIC_MASK_BWE  = 0x4, // ==> SAL_ENH_DYNAMIC_BWE_MUX, bit 3
		SPE_DYNAMIC_MASK_DLNR  = 0x8, // ==> SAL_ENH_DYNAMIC_DLNR_MUX, bit 4  
		SPE_DYNAMIC_MASK_ULNR  = 0x10, // ==> SAL_ENH_DYNAMIC_DLNR_MUX, bit 5
		SPE_DYNAMIC_MASK_LSPK_DMNR  = 0x20, // ==> SAL_ENH_DYNAMIC_SIDEKEYCTRL_DGAIN_MUX, bit 6
		SPE_DYNAMIC_MASK_SIDEKEYCTRL_DGAIN = 0x40, // ==> SAL_ENH_DYNAMIC_SIDEKEYCTRL_DGAIN_MUX, bit 7
		SPE_DYNAMIC_MASK_DLNR_INIT_CTRL = 0x80, // ==> SAL_ENH_DYNAMIC_DL_NR_INIT_CTRL_MUX, bit 8
		SPE_DYNAMIC_MASK_AEC = 0x100, // ==> SAL_ENH_DYNAMIC_AEC_MUX, bit 9
	}SPE_SUB_MASK_T;
	
*/
void spe_updateSpeUsrSubMaskWithWholeValue(uint16 newValue)
{
	kal_uint16 orgValue = gSpe.spe_usr_sub_mask;

	gSpe.spe_usr_sub_mask  = (newValue<<1);
	
	kal_trace( TRACE_INFO, L1SP_UPDATE_SPE_MASKS, 4, gSpe.spe_app_mask, gSpe.spe_usr_mask, gSpe.spe_usr_sub_mask, newValue, orgValue);	
	
	if(gSpe.spe_state) {// already turn on speech enhancement

		// switch between HF DMNR and MagiConference,  mode parameter needs to re
		if(((orgValue ^ gSpe.spe_usr_sub_mask)&(1<<SAL_ENH_DYNAMIC_DMNR_HF_MUX)) != 0) {
			uint16 m_para[NUM_MODE_PARAS];
			uint16 m_paraWb[NUM_MODE_PARAS];
			
			SetSpeechEnhancement(KAL_FALSE); 
			
			spe_chooseSpeechModeParam(m_para, m_paraWb);
			SP_SetSpeechPara(m_para);
			SP_SetWbSpeechPara(m_paraWb);			
			kal_trace(TRACE_INFO, L1SP_MODE_VALUE, m_para[0], m_para[1], m_para[2], m_para[3], m_para[4], m_para[5], m_para[6], m_para[7], m_para[8], m_para[9], m_para[10], m_para[11], m_para[12], m_para[13], m_para[14], m_para[15]);
			kal_trace(TRACE_INFO, L1SP_MODE_VALUE, m_paraWb[0], m_paraWb[1], m_paraWb[2], m_paraWb[3], m_paraWb[4], m_paraWb[5], m_paraWb[6], m_paraWb[7], m_paraWb[8], m_paraWb[9], m_paraWb[10], m_paraWb[11], m_paraWb[12], m_paraWb[13], m_paraWb[14], m_paraWb[15]);
		}
      SetSpeechEnhancement(KAL_TRUE);
	}
}

void L1SP_EnableSpeechEnhancement( bool enable )
{
   if(enable)
   {
      gSpe.spe_flag = true;
      SetSpeechEnhancement(true);
   }
   else 
   {
      SetSpeechEnhancement(false);
      gSpe.spe_flag = false;
   }    
}


/* ========================================================================= */
#define SPE_INTERNALPAR_INDEX_AGC   0 
#define SPE_INTERNALPAR_INDEX_MAX   SAL_PARAMETERLEN_INTERNAL  // 16

#define _write_enh_internalPar_( enhIndex, value )  \
{  \
   volatile uint16 *addr;  \
   addr = SAL_ENH_GetInternalParAddr(); \
   *(addr+enhIndex) = value; \
}

typedef struct 
{
	uint16 delayAndSwitch4Dsp;
	
	// NXP related inforamtion.
	uint16    nxpPaMicIndex; 	
	bool     isNxpPaOn;
	
	
} _SPE_AGC_INFO_T;

static _SPE_AGC_INFO_T speAgcInfo;

void SPE_SetAgcInfo(bool isNxpOn, uint16 nxpPaMicIndex, uint16 delayAndSwitch4Dsp)
{
	speAgcInfo.isNxpPaOn = isNxpOn;
	speAgcInfo.nxpPaMicIndex = nxpPaMicIndex;
	speAgcInfo.delayAndSwitch4Dsp = delayAndSwitch4Dsp;
}

bool SPE_AgcInfo_IsNxpPaOn(void)
{
	return speAgcInfo.isNxpPaOn;
}

void spe_AGC_config(bool isOn, bool isEchoRefOn)
{
	
	Sal_AGC_Config_t cfg;
	memset(&cfg, 0, sizeof(Sal_AGC_Config_t));

	kal_trace(TRACE_INFO, SPE_AGC_CONFIG_INFO, isOn, AM_DSP_GetSpeechUplinkDigitalGain(), 
		speAgcInfo.isNxpPaOn, speAgcInfo.nxpPaMicIndex, speAgcInfo.delayAndSwitch4Dsp,
		isEchoRefOn);
	
	if(isOn) { // turn on 
		_write_enh_internalPar_(SPE_INTERNALPAR_INDEX_AGC, speAgcInfo.delayAndSwitch4Dsp)
		
		cfg.main_switch = true;
		cfg.gain_switch = true;
		cfg.hpiir_switch = true;
		cfg.vad_switch = true;
		cfg.init_req = true;

		cfg.cosim = false;
		
		SAL_AGC1_Config(&cfg);
		SAL_AGC2_Config(&cfg);
		SAL_AGC3_Config(&cfg);
		SAL_AGC4_Config(&cfg);
		
		if(speAgcInfo.isNxpPaOn && isEchoRefOn){
			cfg.main_switch = false;
			cfg.gain_switch = false;
			cfg.hpiir_switch = false;
			cfg.vad_switch = false;
			cfg.init_req = false;

			cfg.cosim = false;

			switch(speAgcInfo.nxpPaMicIndex){
				case 0x1: 
					SAL_AGC1_Config(&cfg);
					break;
				case 0x2:
					SAL_AGC2_Config(&cfg);
					break;					
				case 0x4:
					SAL_AGC3_Config(&cfg);
					break;					
				case 0x8:
					SAL_AGC4_Config(&cfg);
					break;
				default:
					
					ASSERT(0);
			}
			
		}
	} else { // turn off
		
		cfg.main_switch = false;
		cfg.gain_switch = false;
		cfg.hpiir_switch = false;
		cfg.vad_switch = false;
		cfg.init_req = false;

		cfg.cosim = false;
		
		SAL_AGC1_Config(&cfg);
		SAL_AGC2_Config(&cfg);
		SAL_AGC3_Config(&cfg);
		SAL_AGC4_Config(&cfg);
	}
}

/* ========================================================================= */
extern const unsigned short Speech_Normal_Mode_Para[16];
#ifdef __AMRWB_LINK_SUPPORT__
extern const unsigned short WB_Speech_Normal_Mode_Para[16];
#endif 

extern const unsigned short Speech_Vol_Para[4];

void SPE_Init( void )
{
#ifdef SPH_CHIP_BACK_PHONECALL_USE
	gSpe.sph_mode = SPH_MODE_NORMAL;
#else
   gSpe.sph_mode = SPH_MODE_UNDEFINED;
#endif
	gSpe.spe_flag = true;
	gSpe.spe_isFweOn = false;

	gSpe.spe_state = 0;

	//default set the DMNR on
   gSpe.spe_app_mask = 0xffff;
   gSpe.spe_usr_mask = 0xffBf; // default turn dual mic off 
	gSpe.spe_usr_sub_mask = 0x023E; // default value to turn on , [bit6]HF DMNR is default off. [bit7] DRC2.0 is default off. sync with Sal_Enh_Dynamic_t bit wise definition

	gSpe.setNvramValuesFlag = 0;
   memset(gSpe.sph_allModePara, 0, TOTAL_NUM_SPH_MODE*NUM_MODE_PARAS*sizeof(uint16));
   memset(gSpe.sph_allInFirCoeff, 0, TOTAL_NUM_SPH_INPUT_FIR*NUM_FIR_COEFFS*sizeof(int16));
   memset(gSpe.sph_allOutFirCoeff, 0, TOTAL_NUM_SPH_OUTPUT_FIR*NUM_FIR_COEFFS*sizeof(int16));

#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
	memset(&gSpe.sph_dmnr_para, 0, NUM_DMNR_PARAM*sizeof(uint16));
	memset(&gSpe.sph_lspk_dmnr_para, 0, NUM_DMNR_PARAM*sizeof(uint16));

#ifdef __AMRWB_LINK_SUPPORT__   
	memset(&gSpe.sph_wb_dmnr_para, 0, NUM_WB_DMNR_PARAM*sizeof(uint16));
	memset(&gSpe.sph_lspk_wb_dmnr_para, 0, NUM_WB_DMNR_PARAM*sizeof(uint16));
#endif
#endif 

	gSpe.isMagiConOn = false;
	memset(gSpe.sph_magicConParam, 0, NUM_MODE_PARAS*sizeof(uint16));
	memset(gSpe.sph_magicConWbParam, 0, NUM_MODE_PARAS*sizeof(uint16));


	// viberation speaker
	gSpe.isEnableNotchFilter = false;
	gSpe.is2In1Spk = false;


	// init the AGC as off in every channal
	_write_enh_internalPar_(SPE_INTERNALPAR_INDEX_AGC, 0)
	spe_AGC_config(false, false); 
	
#ifdef __AMRWB_LINK_SUPPORT__
	SPE_LoadSpeechPara((uint16 *)Speech_Common_Para, (uint16 *)Speech_Normal_Mode_Para, (uint16 *)Speech_Vol_Para, (uint16 *)WB_Speech_Normal_Mode_Para );
#else
   SPE_LoadSpeechPara((uint16 *)Speech_Common_Para, (uint16 *)Speech_Normal_Mode_Para, (uint16 *)Speech_Vol_Para, NULL );
#endif
}


/* ========================================================================= */
/* ========================================================================= */
/*   EC/AEC/EES control Functions                                            */
/* ========================================================================= */
#define  FLAG_EC_SUPP         1
#define  FLAG_DDL_UL_ENTRY    2
#define  FLAG_DDL_DL_ENTRY    4

#define  SPE_IDLE_STATE       0  /* MCU: 0 -> 1 */ 
#define  SPE_READY_STATE      1  /* DSP: 1 -> 2 */    
#define  SPE_WORKING_STATE    2  /* MCU: 2 -> 3 */ 
#define  SPE_STOP_STATE       3  /* DSP: 3 -> 0 */  


#define _wait_for_ready_( enh_mod )  \
{  \
   uint32 I;  \
   for( I = 0; ; I++ ) {  \
      if( SAL_ENH_IsReady(enh_mod))  \
         break;  \
      ASSERT_REBOOT( I < 20 );  \
      kal_sleep_task( 2 );  \
   }  \
}

#define _wait_for_idle_( enh_mod )  \
{  \
   uint32 I;  \
   for( I = 0; ; I++ ) {  \
      if( SAL_ENH_IsIdle(enh_mod))  \
         break;  \
      ASSERT_REBOOT( I < 20 );  \
      kal_sleep_task( 2 );  \
   }  \
}


void SPE_TurnOnProcess(uint16 on_state)
{
	kal_trace( TRACE_INFO, L1SP_ENHANCE_ON_OFF, 1, on_state);

	
	if(on_state & (SPE_AGC_FLAG)){ 
		// [REMIND], DMNR Calibration need AGC. When following setting modify, please don't forget the code in am.c
		spe_AGC_config(true, 0!=(on_state & SPH_ENH_MASK_ECHO_REF));
	}

   if(on_state & (SPE_AEC_FLAG + SPE_EES_FLAG + SPE_UL_NR_FLAG))
   	  SAL_ENH_SetULPath(true);
   
   if(on_state & (SPE_DL_NR_FLAG + SPE_AEC_FLAG))
   	 SAL_ENH_SetDLPath(true);


   if(on_state & SPE_UL_NR_FLAG)
   		SAL_ENH_SetInit(SAL_ENH_NR_UL);
   if(on_state & SPE_DL_NR_FLAG)
   		SAL_ENH_SetInit(SAL_ENH_NR_DL);

#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
	//REMIND: DMNR should enable before AEC, because it's part of AEC, 
	//AEC will do DMNR initialization when DMNR control is set	
	//DMNR will run, base on AEC is running!!!
	if(on_state & SPE_DMNR_FLAG){ 
		SAL_ENH_SetInit(SAL_ENH_DMNR);
	}
#endif

   if(on_state & ( SPE_AEC_FLAG + SPE_EES_FLAG))
   {
      switch(on_state & ( SPE_AEC_FLAG + SPE_EES_FLAG))
      {
         case SPE_AEC_FLAG:          
		 	SAL_ENH_SetInit(SAL_ENH_AEC);
            _wait_for_ready_(SAL_ENH_AEC);
            break;
         case SPE_EES_FLAG:          
		 	SAL_ENH_SetInit(SAL_ENH_AEC);
            _wait_for_ready_(SAL_ENH_AEC);
            break;
         // case SPE_ES_FLAG: 
         //   break;
         default: 
            ASSERT(false);    
      }   
   }

// #if TDDNC_SUPPORT
   if(on_state & SPE_TDDNC_FLAG){
   	SAL_ENH_SetInit(SAL_ENH_TDNC);
    _wait_for_ready_(SAL_ENH_TDNC);
   }
// #endif    
   
   if(on_state & SPE_UL_NR_FLAG)
   	_wait_for_ready_(SAL_ENH_NR_UL);
   if(on_state & SPE_DL_NR_FLAG)
   	_wait_for_ready_(SAL_ENH_NR_DL);

#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
	   //REMIND: DMNR depends on the running of AEC
	   if(on_state & SPE_DMNR_FLAG){ 
   	_wait_for_ready_(SAL_ENH_DMNR);
	   }
#endif
     
}


void SPE_TurnOffProcess(uint16 off_state)
{
   kal_trace( TRACE_INFO, L1SP_ENHANCE_ON_OFF, 0, off_state);
   if(off_state & SPE_UL_NR_FLAG)
   	SAL_ENH_SetOff(SAL_ENH_NR_UL);
   if(off_state & SPE_DL_NR_FLAG)
   	SAL_ENH_SetOff(SAL_ENH_NR_DL);

#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
	//REMIND: DMNR should disable before AEC, because it's part of AEC
	if(off_state & SPE_DMNR_FLAG){
	SAL_ENH_SetOff(SAL_ENH_DMNR);
	}
#endif

   if(off_state & (SPE_AEC_FLAG + SPE_EES_FLAG))
   { 
      switch(off_state & (SPE_AEC_FLAG + SPE_EES_FLAG))//MT6280, ES V.S. (EES V.S. AEC)
      {
         case SPE_AEC_FLAG:          
			SAL_ENH_SetOff(SAL_ENH_AEC);
			_wait_for_idle_(SAL_ENH_AEC);
            break;
         case SPE_EES_FLAG: 
			SAL_ENH_SetOff(SAL_ENH_AEC);
			_wait_for_idle_(SAL_ENH_AEC);
            break;
         default: 
            ASSERT(false);    
      }
   }                      
       
// #if TDDNC_SUPPORT
   if(off_state & SPE_TDDNC_FLAG){
	  SAL_ENH_SetOff(SAL_ENH_TDNC);
      _wait_for_idle_(SAL_ENH_TDNC);
   }
// #endif 
                                             
   if(off_state & SPE_UL_NR_FLAG)
	_wait_for_idle_(SAL_ENH_NR_UL);
   if(off_state & SPE_DL_NR_FLAG)
	_wait_for_idle_(SAL_ENH_NR_DL);
   
#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
	//REMIND: DMNR should disable before AEC, because it's part of AEC
	if(off_state & SPE_DMNR_FLAG){
	_wait_for_idle_(SAL_ENH_DMNR);
	}
#endif

	if(off_state & SPE_AGC_FLAG){
		spe_AGC_config(false, false);
	}
	
}

void SPE_Clear_DLL_Entry(uint16 cur_state)
{
   if(!(cur_state & (SPE_AEC_FLAG + SPE_EES_FLAG + SPE_UL_NR_FLAG)))
   	SAL_ENH_SetULPath(false);
   
   if(!(cur_state & (SPE_DL_NR_FLAG + SPE_AEC_FLAG)))
   	SAL_ENH_SetDLPath(false);
}

