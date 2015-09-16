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
 * speech_def.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  This file defines all the speech registers used in audio module.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef __SPEECH_DEF_H
#define __SPEECH_DEF_H

#include "kal_public_api.h"
#include "audio_dsp_d2c_def.h"
#include "common_def.h"

#if defined(MT6280)
   #include "dpram_6280.h"
#elif defined(MT6589)
	#include "dpram_6589.h"
#elif defined(MT6572)
	#include "dpram_6572.h"
#elif defined(MT6582)
	#include "dpram_6582.h"	
#elif defined(MT6290)
	#include "dpram_6290.h"		
#elif defined(MT6592)
	#include "dpram_6592.h"	
#elif defined(MT6571)
	#include "dpram_6571.h"	
#elif defined(MT6595)
	#include "dpram_6595.h"	
#elif defined(MT6752)
	#include "dpram_6752.h"				
#else 
	#error Need DSP guys give the dpram_xxxx.h file
#endif

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       Feature Definitions
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

#define NEW_SPH_SHERIF_STRUCT (defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6290) || defined(MT6592) || defined(MT6571) || defined(MT6595) || defined(MT6752)) 
   
#if defined(__DUAL_TALK_MODEM_SUPPORT__)  
   //In 6252 W+C project, L1Audio is the only module to use BT. In this project, no BT task won't be invoked, so we add by myself to use the setMode(BT_Earphone)
   #define __BT_SUPPORT__
#endif

//=============================================================================================
//                  HQA relative setting
//=============================================================================================
//#define __HQA_AUDIO__
#if defined(__HQA_AUDIO__)
   #define __HQA_AUDIO_SPEECH_ENHANCEMENT_COMMON__ 0
   #define __HQA_AUDIO_AEC_NR_DRC__ 0
   #define __HQA_AUDIO_HARDWARE_AGC__ 0
#endif

//=============================================================================================
//                  Others
//=============================================================================================
#define NEW_BLOCK_FILTER_SUPPORT

// #define DSP_16K_SIDETONE_SUPPORT ( defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582)) // no one use, phase out

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        SPEECH SHERIF BASE ADDRESS
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
   #define DP_SP_CODEC_CTRL_base(a)             (DPRAM2_base(DP2_SP_CODEC_CTRL_BASE)           +(a))     //cache-based DSP has no DPRAM
   #define DP_SP_AUDIO_INTERFACE_CTRL_base(a)   (DPRAM2_base(DP2_SP_AUDIO_INTERFACE_CTRL_BASE) +(a))
   #define DP_SP_KT_CTRL_base(a)                (DPRAM2_base(DP2_SP_KT_CTRL_BASE)              +(a))
   #define DP_SP_8kPCM_CTRL_base(a)             (DPRAM2_base(DP2_SP_8kPCM_CTRL_BASE)           +(a))
   #define DP_SP_VM_CTRL_base(a)                (DPRAM2_base(DP2_SP_VM_CTRL_BASE)              +(a))
   #define DP_SP_CTM_base(a)                    (DPRAM2_base(DP2_SP_CTM_BASE)                  +(a))
   #define DP_SP_AEC_CTRL_base(a)               (DPRAM2_base(DP2_SP_AEC_CTRL_BASE)             +(a))
   #define DP_SP_VR_CTRL_base(a)                (DPRAM2_base(DP2_SP_VR_CTRL_BASE)              +(a))
   #define DP_SP_AUDIO_CTRL_base(a)             (DPRAM2_base(DP2_SP_AUDIO_CTRL_BASE)           +(a))
   #define DP_SP_AUDIO_ENHANCE_base(a)          (DPRAM2_base(DP2_SP_AUDIO_ENHANCE_BASE)        +(a))
   #define DP_SP_Reserve_base(a)                (DPRAM2_base(DP2_Reserve_BASE)                 +(a))
   #define DP_AWB_8K_base(a)                    (DPRAM2_base(DP2_AWB_8K_BASE)                  +(a))
   #define DP_EPL_BND_base(a)                   (DPRAM2_base(DP2_EPL_BND_BASE)                 +(a))
   #define DP_AWB_LINK_EXTEND_base(a)           (DPRAM2_base(DP2_AWB_LINK_EXTEND_BASE)         +(a))
   #define DP_SP_SPEECH_OTHER_base(a)           (DPRAM2_base(DP_SPEECH_OTHER_BASE)             +(a))
   #define DP_SP_SPEECH_RESERVED_base(a)        (DPRAM2_base(DP_SPEECH_RESERVED_BASE)          +(a))

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        SPEECH DSP Control
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  SPEECH Control Filed
//=============================================================================================
//   #define DP_SC_FLAGS           DPRAM2_base(DP_SC_ADDR)            /* speech coder enabling flag [0]            */
                                                                    /* speech decoder enable flag [1]            */
                                                                    /* speech coder reset flag [4]               */
                                                                    /* speech decoder reset flag [5]             */
                                                                    /* 1'st speech coder flag [6]                */
                                                                    /* 1'st speech decoder flag [7]              */
                                                                    /* noise suppression enabling flag [8]       */
                                                                    /* VBI PCM read reset flag [9]               */
                                                                    /* VBI PCM write reset flag [10]             */
                                                                    /* Voice Memo - Record [11]                  */
                                                                    /* Voice Memo - Playback [13:12]             */
                                                                    /* AMR Rate Control [14]                     */
                                                                    /* AMR Handover Flag [15]                    */
//   #define DP_DEL_PCM_R          DPRAM2_base(DP2_DEL_PCM_R)         /* delay for the VBI PCM read                */
//   #define DP_DEL_PCM_W          DPRAM2_base(DP2_DEL_PCM_W)         /* delay for the start of speech decoder     */
//   #define DP_MARGIN_VBIPCM_W    DPRAM2_base(DP2_MARGIN_PCM_W)      /* margin for the VBI PCM write [7:0]        */
                                                                    /* SID detection threshold LOW [9:8]         */
                                                                    /* SID detection threshold High [15:10]      */
//   #define DP_SC_MODE            DPRAM2_base(DP2_SC_MODE)           /* CODEC type for speech decoder [7:0]       */
                                                                    /* CODEC type for speech coder [15:8]        */
//   #define DP_SC_VAD             DPRAM2_base(DP2_SC_VAD)            /* VAD: FR, HR, EFR, AMR1m AMR2              */
//   #define DP_SC_MUTE            DPRAM2_base(DP2_SC_MUTE)           /* speech coder muting flag [0]              */
                                                                    /* speech decoder muting flag [1]            */
                                                                    /* Nsync reset mode [4]                      */
                                                                    /* Nsync followed by ETSI/Stepmind [5]       */
                                                                    /* Nsync reset value only used in MCU [15:8] */
//   #define DP_NSYNC_NOT_ETSI_C   DPRAM2_base(DP2_Nsync_Not_ETSI_C)  //? Daniel
//   #define DP_SC_EVLUATE_DELAY   DPRAM2_base(SPH_DEL_O)             /* DSP evaluate speech delay offset while MCU extend frame  */ //?Daniel
//   #define DP_Offset_Count       DPRAM2_base(DP2_Offset_Count)      /* Quater bits offset for Handover           */
//   #define DP_NSYNC_VALUE        DPRAM2_base(DP2_Nsync_value)       /* Bsync value used in a handover            */

//=============================================================================================
//                  Audio control field  (Use Speech base)
//=============================================================================================
//   #define DP_VOL_OUT_PCM          DPRAM2_base(SPH_DL_VOL)                     /* gain on PCM output                        */
//   #define DP_AUDIO_PAR            DP_SP_AUDIO_INTERFACE_CTRL_base(1)          /* input filtering flag [0]                  */
                                                                               /* output filtring flag [1]                  */
                                                                               /* PCM samples must be sent to DAI port for BT connection [2] */
                                                                               /* PCM2WAY wb/nb Switch (0:NB/1:WB) [3]               */
                                                                               /* 16k Switch (0:DSP/1:HW) [4]               */
                                                                               /* DAI mode 0 [8]                            */
                                                                               /* DAI mode 1 [9]                            */
                                                                               /* DAI mode 2 [10]                           */
                                                                               /* DAI mode 3 [11]                           */
                                                                               /* BT cordless mode [12]                     */
                                                                               /* BT earphone mode [13]                     */
                                                                               /* speech mode [15]                          */
//   #define DP_AFI_COEF_ADD         DPRAM2_base(SPH_PM_ADDR_BKF_FLT_COEF_UL_NB) /* address of input audio filter             */
//   #define DP_VOL_IN_PCM           DP_SP_AUDIO_INTERFACE_CTRL_base(5)          /* gain on PCM input                         */
//   #define DP_SIDETONE_VOL         DP_SP_AUDIO_INTERFACE_CTRL_base(6)          /* gain on side-tone                         */
//#if NEW_SPH_SHERIF_STRUCT
//   #define DP_AFI_NB_UL_COEF_ADD   DPRAM2_base(SPH_PM_ADDR_BKF_FLT_COEF_UL_NB)
//   #define DP_AFI_NB_DL_COEF_ADD   DPRAM2_base(SPH_PM_ADDR_BKF_FLT_COEF_DL_NB)
//   #define DP_AFI_WB_UL_COEF_ADD   DPRAM2_base(SPH_PM_ADDR_BKF_FLT_COEF_UL_WB)	
//   #define DP_AFI_WB_DL_COEF_ADD   DPRAM2_base(SPH_PM_ADDR_BKF_FLT_COEF_DL_WB)
//   #define DP_SIDETONE_FLT_ADDR    DPRAM2_base(SPH_PM_ADDR_ST_FLT_COEF)
//   #define DP_SRC_FLT_ADDR         DPRAM2_base(SPH_PM_ADDR_SRC_FLT_COEF)
//#endif


//=============================================================================================
//                  Keytone & Tone
//=============================================================================================
   #define DSP_TONE_CTRL1        (*DPRAM2_base(KEYTONE1_CTRL))      //(*DP_SP_KT_CTRL_base(0))
   #define DSP_TONE_CTRL2        (*DPRAM2_base(KEYTONE2_CTRL))
   #define DSP_TONE_FORCE_KT_8K  (*DPRAM2_base(DP_ASP_FORCE_KT_8K))   //(*DP_SP_KT_CTRL_base(2))
   #define DSP_TONE_F1A          (*DPRAM2_base(KEYTONE1_FREQ))
   #define DSP_TONE_F1B          (*DPRAM2_base( (KEYTONE1_FREQ+1) ) )
   #define DSP_TONE_AMP1         (*DPRAM2_base( (KEYTONE1_FREQ+2) ) )
   #define DSP_TONE_F2A          (*DPRAM2_base(KEYTONE2_FREQ))
   #define DSP_TONE_F2B          (*DPRAM2_base( (KEYTONE2_FREQ+1) ) )
   #define DSP_TONE_AMP2         (*DPRAM2_base( (KEYTONE2_FREQ+2) ) )
   #define DP_KT_ATT             (*DPRAM2_base(DP_KEYTONE_ATT_GAIN))  //(*DP_SP_KT_CTRL_base(9))

//=============================================================================================
//                  Voice Memo
//=============================================================================================
//   #define DSP_SD1_VM_0          DPRAM2_base(SPH_AP_SD_DATA_HDR)        /* SID indicator [2:1] & TAF[3] & BFI[5]     */
//   #define DSP_SD1_VM_1          DPRAM2_base(SPH_AP_SD_DATA_HB)         /* information bits d[15:0]                  */
//   #define DSP_SD1_VM_17         DPRAM2_base(SPH_AP_SD_DATA_HB+16)      /* information bits d[275:260]               */
//   #define DSP_SD2_VM_0          DPRAM2_base(SPH_AP_SE_DATA_HDR)        /* SP flag [1]                               */
//   #define DSP_SD2_VM_1          DPRAM2_base(SPH_AP_SE_DATA_HB)         /* information bits d[15:0]                  */
//   #define DSP_SD2_VM_17         DPRAM2_base(SPH_AP_SE_DATA_HB+16)      /* information bits d[275:260]               */
//   #define DSP_RX_TCH_S(m, n)    ((DPRAMADDR)(DP_SP_VM_CTRL_base(0)+(m*16+n)))
//#if NEW_SPH_SHERIF_STRUCT
//   #define DSP_TX_TCH_S(m, n)    ((DPRAMADDR)(DP_SP_VM_CTRL_base(32)+(m*16+n)))
//   #define DSP_SC_TCH_MODE       DPRAM2_base(DP_Encoder_Used_Mode)
//   #define DSP_SD_TCH_MODE       DPRAM2_base(DP_Decoder_Used_Mode)
//   #define DSP_VM_DBG_INFO       DPRAM2_base(DP_VM_DBG_INFO)
//   #define DSP_EPL_UL_ADDR1      (*DPRAM2_base(DP_PCM_REC_PTR1))
//   #define DSP_EPL_UL_ADDR2      (*DPRAM2_base(DP_PCM_REC_PTR2))
//   #define DSP_EPL_DL_ADDR1      (*DPRAM2_base(DP_PCM_REC_PTR3))
//   #define DSP_EPL_DL_ADDR2      (*DPRAM2_base(DP_PCM_REC_PTR4))
//#else
//   #define DSP_TX_TCH_S(m, n)    ((DPRAMADDR)(DP_SP_VM_CTRL_base(18)+(m*16+n)))
//   #define DSP_SC_TCH_MODE       DP_SP_VM_CTRL_base(0x23)
//   #define DSP_SD_TCH_MODE       DP_SP_VM_CTRL_base(0x11)
//#endif
//   #define DSP_TX_TCH_S0_0       DPRAM2_base(SPH_2G_SE_DATA_HDR)
//   #define DSP_RX_TCH_S0_0       DPRAM2_base(SPH_2G_SD_DATA_HDR)        //DP_SP_VM_CTRL_base(0x0)


//=============================================================================================
//                  PCM  (Use Speech base)
//=============================================================================================
//   #define DSP_PCM_REC_CTRL      DPRAM2_base(DP_ASP_WAV_REC_CTRL)       //DP_SP_8kPCM_CTRL_base(0)
//   #define DSP_PCM_REC_ADDR      DPRAM2_base(DP_8kPCM_MIC_REC_IDX)      //DP_SP_8kPCM_CTRL_base(1)
//   #define DSP_PCM_REC_LEN       DPRAM2_base(DP_8kPCM_MIC_REC_LEN)      //DP_SP_8kPCM_CTRL_base(2)
//   #define DSP_PCM_REC_ADDR2     DPRAM2_base(DP_8kPCM_SPK_REC_IDX)      //DP_SP_8kPCM_CTRL_base(3)
//   #define DSP_PCM_REC_LEN2      DPRAM2_base(DP_8kPCM_SPK_REC_LEN)      //DP_SP_8kPCM_CTRL_base(4)
//   #if defined(MT6280)
//   #define DSP_PCM_REC_ENA       DPRAM2_base(DP_UL_DL_PCM_REC_ENA)      //DP_SP_8kPCM_CTRL_base(5)
//   #else
//   #define DSP_PCM_REC_ENA		 DPRAM2_base(SPH_PCM_REC_CTRL)			//DP_SP_8kPCM_CTRL_base(5)
//   #endif

//   #define DSP_PCM_DGAIN         DPRAM2_base(AUDIO_ASP_WAV_OUT_GAIN)    //DP_SP_AUDIO_INTERFACE_CTRL_base(7)

//=============================================================================================
//                  AMR-WB playback control  (Use Speech base)
//=============================================================================================
//   #define DSP_SD1_AWB_VM_0      DPRAM2_base(DP_SD1_AWB_VM_0)    /* TX_Type [7:0] SE codec mode [15:8]    */
//   #define DSP_SD1_AWB_VM_1      DPRAM2_base(DP_SD1_AWB_VM_0+1)  /* information bits d[15:0]              */
//   #define DSP_SD2_AWB_VM_0      DPRAM2_base(DP_SD2_AWB_VM_0)    /* TX_Type [7:0] SE codec mode [15:8]    */
//   #define DSP_SD2_AWB_VM_1      DPRAM2_base(DP_SD2_AWB_VM_0+1)  /* information bits d[15:0]              */
//   #define DSP_SD2_AWB_VM_18     DPRAM2_base(DP_SD2_AWB_VM_18)   /* information bits d[303:288]           */
//   #define DSP_AWB_SE_CTRL       DPRAM2_base(DP_AWB_SE_CTRL)
//   #define DSP_AWB_SD_CTRL       DPRAM2_base(DP_AWB_SD_CTRL)


//=============================================================================================
//                  Audio control field (Use Speech base)
//=============================================================================================
//   #define DSP_AUDIO_CTRL2       DPRAM2_base(DP_AUDIO_CTRL2)
//   #define DSP_AUDIO_FLEXI_CTRL  DPRAM2_base(DP_AUDIO_FLEXI_CTRL)

//=============================================================================================
//                  EC / AEC / EES / DMNR Control Registers
//=============================================================================================
   //#define DP_EC_SUPP            DPRAM2_base(DP2_EC_SUPP)
//   #define DP_ES_Time_Const      DPRAM2_base(DP2_ES_Time_Const)
//   #define DP_ES_Vol_Const       DPRAM2_base(DP2_ES_Vol_Const)
   //#define DP_AEC_CONTROL        DPRAM2_base(DP_AEC_CTRL)
   //#define DP_AEC2_CONTROL       DPRAM2_base(DP_EES_CTRL)
   //#define DP_EES_CONTROL        DPRAM2_base(DP_EES_CTRL)
   //#define DP_DMNR_CONTROL       DPRAM2_base(DP_DMNR_CTRL) // bit[0:1] dmnr state machine
                                                     // bit[4] calibraion control,  
                                                     // bit[5] DMNR NB coef set
                                                     // bit[6] DMNR WB coef set
//   #define DP_AEC_8K_CTRL        DPRAM2_base(DP_AEC_CONTROL_WORD)

//=============================================================================================
//                  Gain/Coeff/Compensation
//=============================================================================================
   #define DP_DigiGain_Setting               DPRAM2_base(AUDIO_ASP_WAV_OUT_GAIN)

//=============================================================================================
//                  Uplink Comfort noise
//=============================================================================================
//   #define DSP_UL_COMFORT_NOISE_THRESHOLD   (DPRAM2_base(DP_UL_COMFORT_NOISE_THRESHOLD))
//   #define DSP_UL_COMFORT_NOISE_SHIFT       (DPRAM2_base(DP_UL_COMFORT_NOISE_SHIFT))

//=============================================================================================
//                  NR Control
//=============================================================================================
   //#define DSP_UL_NR_CTRL                   DPRAM2_base(DP_NR_CTRL) 
   //#define DSP_DL_NR_CTRL                   DPRAM2_base(DP_DL_NR_CTRL)
   //#define DP_SPE_DL_DLL_ENTRY              DPRAM2_base(SPH_ENH_DL_CTRL)

//=============================================================================================
//                  TDNC Control
//=============================================================================================
//#if TDDNC_SUPPORT
//#define DP_TDDNC_CTRL           DPRAM2_base(DP_AEC_CTRL)
//#endif

//=============================================================================================
//                  Enhanced Audio Control Field
//=============================================================================================
//   #define DP_SBSD_CTRL                     DPRAM2_base(DP_TEST_SIM_SBSD_CTRL)
//   #define E_CTRL_HRFR                      DPRAM2_base(DP_ENHANCED_AUDIO_CTRL)
//   #define E_CTRL_AMREFR                    DP_SP_AUDIO_CTRL_base(4) //could be removed from MT6280, wayne
//   #define E_CTRL_HO                        DPRAM2_base(SPH_SCH_IMPROVE_CTRL)
//   #define DP_DEBUG_ASSERT_CTRL             (DPRAM2_base(DEBUG_ASSERT_CTRL)) //why here? wayne

//=============================================================================================
//                  Uplink WB AMR in TCH buffer
//=============================================================================================
//#if NEW_SPH_SHERIF_STRUCT
 //  #define DP_AWB_TX_TCH_S00(n)         DPRAM2_base(SPH_2G_SE_DATA_HDR+(n))
 //  #define DP_AWB_SC_TCH_MODE           DPRAM2_base(DP_Encoder_Used_Mode)
//#endif


//=============================================================================================
//                  Sound Effect   (Use Speech base)
//=============================================================================================
//   #define DSP_SOUND_EFFECT_ADDR            DPRAM2_base(DP_BGS_ADDR)
//   #define DSP_SOUND_EFFECT_LEN             DPRAM2_base(DP_BGS_LEN)
//   #define DSP_SOUND_EFFECT_CTRL            DPRAM2_base(DP_BGS_CTRL)
//   #define DSP_SOUND_EFFECT_SPH_STATE       DPRAM2_base(DP_BGS_MIX)
//   #define DSP_SOUND_EFFECT_UL_GAIN         DPRAM2_base(DP_BGS_UL_GAIN)
//   #define DSP_SOUND_EFFECT_DL_GAIN         DPRAM2_base(DP_BGS_DL_GAIN) 
//   #define DSP_DEAD_INTERRUPT               DPRAM2_base(DP_DSP_DEAD_INT)
//   #define DSP_UP_DOWN_SAMP_CTRL            DPRAM2_base(DP_UP_DOWN_SAMPL_CTRL)

//=============================================================================================
//                  CTM
//=============================================================================================
//#if NEW_SPH_SHERIF_STRUCT
//   #define DSP_P4W_UL_D2M_PTR             (*DPRAM2_base(DP_PNW_PTR_UL1))
//   #define DSP_P4W_UL_M2D_PTR             (*DPRAM2_base(DP_PNW_PTR_UL2))
//   #define DSP_P4W_DL_D2M_PTR             (*DPRAM2_base(DP_PNW_PTR_DL1))
//   #define DSP_P4W_DL_M2D_PTR             (*DPRAM2_base(DP_PNW_PTR_DL2))   
      
//   #define DSP_P2W_UL_D2M_PTR             (*DPRAM2_base(DP_PNW_PTR_UL1))
//   #define DSP_P2W_DL_M2D_PTR             (*DPRAM2_base(DP_PNW_PTR_DL1))         
   
//   #define DSP_PNW_UL_CTRL                (*DPRAM2_base(DP_PNW_CTRL_UL))
//   #define DSP_PNW_DL_CTRL                (*DPRAM2_base(DP_PNW_CTRL_DL))
//   #define DSP_PNW_UL_LEN                 (*DPRAM2_base(DP_PNW_LEN_UL))
//   #define DSP_PNW_DL_LEN                 (*DPRAM2_base(DP_PNW_LEN_DL))   
//#else
//   #define DP_PCM_EX_CTRL                   (*DPRAM2_base(DP_PNW_PTR_DL1))
//   #define DP_PCM_EX_PTR                    (*DPRAM2_base(DP_PNW_CTRL_DL))
//   #define DP_PCM_EX_UL_LEN                 (*DPRAM2_base(DP_CTM_CTRL))
//   #define DP_PCM_EX_DL_LEN                 (*DPRAM2_base(DP_CTM_BFI_FACCH_REPORT))
//#endif   
   //#define DP_CTM_CODEC_CTRL                (*DPRAM2_base(DP_CTM_CTRL))    // 4 LSBs for DSP CTM state
   #define DP_CTM_COSIM_CONTROL             (*DPRAM2_base(DP_CTM_COSIM_CTRL))
   //#define DP_BFI_FACCH_REPORT              (*DPRAM2_base(DP_PNW_CTRL_UL))
   //#define DP_CTM_AMRCODEBOOK_GAIN_LIMIT    (*DPRAM2_base(DP_PNW_LEN_UL))
   //#define DP_CTM_AMRCODEBOOK_GAIN_UPDATE   (*DPRAM2_base(DP_PNW_LEN_DL))

//=============================================================================================
//                  8K limiter control
//=============================================================================================
//   #define DP_8K_LIMITER_CTRL               DPRAM2_base(DP2_8k_SP_CTRL) //DPRAM2_base(0x01DB)
//   #define DP_SCR_CTRL                      DPRAM2_base(DP2_8k_SP_CTRL) //DPRAM2_base(0x01DB)

//=============================================================================================
//                  SBC Support Definition
//=============================================================================================
//   #define DP_SB_CTRL                       (*DPRAM2_base(D2_SBC_control))
//   #define DP_SB_WRITE                      (*DPRAM2_base(D2_SBC_DSP_W_PTR))
//   #define DP_SB_READ                       (*DPRAM2_base(D2_SBC_MCU_R_PTR))
//   #define DP_SB_PARAM                      (*DPRAM2_base(D2_SBC_parameter))
//   #define DP_SB_BASE                       (*DPRAM2_base(D2_SBC_Base_address))
//   #define DP_SB_LENGTH                     (*DPRAM2_base(D2_SBC_buffer_length))

//=============================================================================================
//                  3G Speech Sherif Address
//=============================================================================================
//   #if defined(MT6280)
//   #define DP_3G_UL_SC_MODE                 (DPRAM2_base(DP_3G_SC_Type))
//   #define DP_3G_DL_SD_MODE                 (DPRAM2_base(DP_3G_SD_Type)) 
//   #define DP_3G_STATE                      (DPRAM2_base(DP_3G_mode)) 
//   #else
//   #define DP_3G_UL_SC_MODE                 (DPRAM2_base(SPH_3G_SE_RATE_UPDATE))
//   #define DP_3G_DL_SD_MODE                 (DPRAM2_base(SPH_3G_SD_RATE_UPDATE)) 
//   #define DP_3G_STATE						(DPRAM2_base(SPH_3G_CTRL)) 
//   #endif
//   #define DP_3G_UL_TX_TYPE                 (DPRAM2_base(DP_3G_TX_VM_0)) 
//   #define DP_3G_UL_TX_ADDR                 (DPRAM2_base(SPH_3G_SE_DATA_HB)) 
//   #define DP_3G_DL_RX_TYPE                 (DPRAM2_base(DP_3G_RX_VM_0))
//   #define DP_3G_DL_RX_ADDR                 (DPRAM2_base(SPH_3G_SD_DATA_HB)) 
//#if NEW_SPH_SHERIF_STRUCT  
//   #define DP_3G_UL_TX_MODE_REPORT          (*DPRAM2_base(DP_Encoder_Used_Mode))
//   #define DP_3G_DL_RX_MODE_REPORT          (*DPRAM2_base(DP_Decoder_Used_Mode))
//   #define DP_SPH_3G_SYNC                   (*DPRAM2_base(DP_SPH_3G_SYNC_FLAG))
//#endif
//=============================================================================================
//                  DSP Speech Control
//=============================================================================================
//   #define DSP_SPEECH_DEBUG_MODE            (DPRAM2_base(DP2_SPEECH_DEBUG_MODE))


//=============================================================================================
//                  BlueTooth Mode Control Field (Sign-extension / linear / gain mode)
//=============================================================================================
//   #define DP_BT_PATCH_CTRL                  DPRAM2_base(SPH_BT_CTRL)
//   #define DP_BT_MODE_CTRL                   DPRAM2_base(SPH_BT_MODE)

//=============================================================================================
//                  To indicate CSD channel types
//=============================================================================================
   #define DSP_TCH_S0_FLAGS                 DPRAM2_base(DP_TCH_S0_FLAGS)
//=============================================================================================
//                  DataCard Interface
//=============================================================================================
//   #define DSP_DACA_CTRL                     (*DPRAM2_base(DP_DACA_CTRL))
//   #define DSP_DACA_PTR_UL                   (*DPRAM2_base(DP_DACA_PTR_UL))
//   #define DSP_DACA_PTR_DL                   (*DPRAM2_base(DP_DACA_PTR_DL))
//   #define DSP_DACA_LEN                      (*DPRAM2_base(DP_DACA_LEN))
//=============================================================================================
//                  Others
//=============================================================================================
//#if defined(MT6280)
//	#define SPH_BAND_PAGE (5)
//   #define SPH_BAND_ADDR (0x2FBF)
//#elif defined(MT6589)
//	#define SPH_BAND_PAGE (5)
//   #define SPH_BAND_ADDR (0x32F1)
//#else 
//	#error new DSP band information address is required for new CHIPSET
//#endif

//#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
//   #define DSP_AGC_SW_GAIN1             DPRAM2_base(DP_AGC_SW_GAIN1) //(DPRAM2_base(0x1FE)), DMNR Calibration AGC 
//   #define DSP_AGC_SW_GAIN2             DPRAM2_base(DP_AGC_SW_GAIN2) //(DPRAM2_base(0x1FF)), DMNR Calibration AGC
//#endif


//#define COMPEN_BLOCK_FLT_PAR            DPRAM2_base(DP2_COMPEN_BLOCK_FILTER)
//#define COMPEN_BLOCK_FLT_PAR_PTR        g_Compen_Blk_Flt               // For Swtich between old/new usage

//#define DSP_SE_BUF_PTR                   (*DPRAM2_base(SPH_DM_ADDR_SE_PTR)) 
//#define DSP_SD_BUF_PTR                   (*DPRAM2_base(SPH_DM_ADDR_SD_PTR)) 

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        SPEECH DSP Control Including DM/PM Addr Define
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  DUAL MIC Control
//=============================================================================================
//#if defined(__DUAL_MIC_SUPPORT__) || defined(__SMART_PHONE_MODEM__)	
//#if defined(MT6280)
//   #define DUALMIC_MIC2_BUF_PTR      0x32A9
//#endif   
//   #define DSP_DUALMIC_CTRL          DPRAM2_base(DP2_DUALMIC_CTRL) //(DSP_DM_ADDR(0, (0x3DA6))) //DPRAM2_base(0x2E1) //Scott101018
//#endif


//=============================================================================================
//                  Speech Engineer Parameter
//=============================================================================================
//#if defined(MT6280) || defined(MT6589)
//   #define SPH_EMP_PAGE (5)
//   #define SPH_EMP_ADDR (0x2E80)
//#else
//   #error new DSP speech enhancement parameter address is required for new CHIPSET
//#endif

//#define DSP_CPARA_ADDR   (DSP_DM_ADDR(SPH_EMP_PAGE, SPH_EMP_ADDR))
//#define DSP_VPARA_ADDR   (DSP_DM_ADDR(SPH_EMP_PAGE, (SPH_EMP_ADDR+8)))
//#define DSP_MPARA_ADDR   (DSP_DM_ADDR(SPH_EMP_PAGE, (SPH_EMP_ADDR+12)))

//=============================================================================================
//                  DSP Internal memory access
//=============================================================================================
//#if defined(MT6280) || defined(MT6589)
//   #define DSP_IN_FIR_COEFF_IN_ADDR    0x0223 
//   #define DSP_OUT_FIR_COEFF_OUT_ADDR  0x0250 
//#else
//   #error new DSP FIR address is required for new CHIPSET
//#endif

//=============================================================================================
//#define DP_AUDIO_VIA_8KBT_CTRL              DPRAM2_base(DP2_AUDIO_VIA_BT_CTRL)
//#define DP_VSBT_CTRL                        DPRAM2_base(DP_VBI_SYNC_BT_Earphone_CTRL)
//   #define BT_AUDIO_PLAYBACK_SD_PAGE_NUM    5
//                  DSP AGC control
//=============================================================================================
   #define DSP_AGC_CTRL                    (DPRAM2_base(DP2_AGC_CTRL))
//   #define DSP_AGC_GAIN                    (DPRAM2_base(DP2_AGC_GAIN))

//=============================================================================================
//                  DSP Interrupt
//=============================================================================================
//#if NEW_SPH_SHERIF_STRUCT  
//   #define DSP_D2C_SPEECH_UL_INT            DPRAM2_base(DP_D2C_SPEECH_UL_INT)
//   #define DSP_D2C_SPEECH_DL_INT            DPRAM2_base(DP_D2C_SPEECH_DL_INT)   
//#endif  

//=============================================================================================
//                  Others
//=============================================================================================
//#if defined(MT6280) || defined(MT6589)
//   #define DSP_GSM_MODE    (DPRAM2_base(DP_GSM_MODE))
//#endif

//   #define DP2_3G_debug_info0 (*DPRAM_base(0x1B7))
//   #define DP2_3G_debug_info1 (*DPRAM_base(0x1B8))
//   #define DP2_3G_debug_info7 (*DPRAM_base(0x1BE))

#endif  //__SPEECH_DEF_H

