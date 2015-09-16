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
 * Add 77 compile options.
 *
 * 06 14 2012 kh.hung
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Integration change.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 *
 *******************************************************************************/

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        INCLUDE FILES
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "reg_base.h"
#include "kal_trace.h"
#include "l1audio_trace.h"
#include "l1audio.h"
#include "l1sp_trc.h"
#include "audio_def.h"
#include "afe_def.h"
#include "afe.h"
#include "am.h"

#include "dcl.h"
#include "us_timer.h"

#include "audio_enum.h"
#include "exp_SphFasTypDef.h"
#include "fc_def.h"

//#if defined(__BT_SUPPORT__)
//#include "bt_api.h"
//#endif

#if defined(__GAIN_TABLE_SUPPORT__)
#include "aud_defs.h"
#endif

#if defined(EXT_DAC_SUPPORT)
// mcu\media\audio\include
#include "aud_defs.h"  
// mcu\ps\l4\include
#include "device.h"
#endif

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        DEFINITIONS
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  Chip Specific Setting of MT6573/MT6575/MT6577
//=============================================================================================
#define AUD_LSBUF_L_PWUP            (0x1<<2)
#define AUD_LSBUF_R_PWUP            (0x1<<3)
#define AUDADCL_INPUT_SEL_MASK      (0x7 << 12)
#define AUDADCL_INPUT_SEL_AIN1      (0x1 << 12)
#define AUDADCL_INPUT_SEL_AIN2      (0x2 << 12)
#define AUDADCL_INPUT_SEL_AIN3      (0x3 << 12)
#define AUDADCL_INPUT_SEL_L_PRE_AMP (0x4 << 12)
#define AUDADCL_INPUT_SEL_L_LSB_AMP (0x5 << 12)
#define AUDADCR_INPUT_SEL_MASK      (0x7 << 8)
#define AUDADCR_INPUT_SEL_AIN1      (0x1 << 8)
#define AUDADCR_INPUT_SEL_AIN2      (0x2 << 8)
#define AUDADCR_INPUT_SEL_AIN3      (0x3 << 8)
#define AUDADCR_INPUT_SEL_R_PRE_AMP (0x4 << 8)
#define AUDADCR_INPUT_SEL_R_LSB_AMP (0x5 << 8)

#if defined(MT6573) || defined(MT6575) || defined(MT6577)
   #define AFE_DL_SRC2  (volatile uint32 *)(0xD0000108)
   #define DL2_MUTE_CH1_ON   (0x1<<3)
   #define DL2_MUTE_CH2_ON   (0x1<<4)
   #define AFE_DL_SRC1  (volatile uint32 *)(0xD0000100)
   #define DL1_SRC_ON        (0x1<<0)
#endif
   
#if defined(__HQA_AUDIO__) && !(__HQA_AUDIO_HARDWARE_AGC__)
   #define AGC_ENABLE_FLAG 0
#else
   #define AGC_ENABLE_FLAG 0
#endif

#if defined(MT6575) || defined(MT6577) 
   #define CLKSQ_EN ((volatile uint16*)0xC0007020) 
#endif

#define AGC_MIN_GAIN                      0xA
#define TRANSPARENT_SIDETONE_GAIN_OFFSET  11
#define TRANSPARENT_AGC_GAIN_OFFSET       (33)
#define MAX_PGA_GAIN                      AGC_MIN_GAIN+30
#define VAPDN_DAC_BIT                     0x4
#define MICSEL                            (0x1)

//=============================================================================================
//                  FM Ratio Recording Volume
//=============================================================================================
#define FM_RADIO_RECORDING_VOLUME   5

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        DEFINITION OF DATA TYPES
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  DelayCmd
//=============================================================================================
typedef struct {
   volatile uint16*  addr;
   uint16            val;
} DelayCmd;

//=============================================================================================
//                  RegBackup
//=============================================================================================
typedef struct {
   kal_uint16     VMCU_CON;
   kal_uint16     VDB_CON;
   kal_uint16     VLB_CON;
   kal_uint16     AMCU_CON0;
   kal_uint16     AMCU_CON1;
   kal_uint16     EDI_CON;
   kal_uint16     AMCU_CON2;
   kal_uint16     VAGC_CON0;
   kal_uint16     DAC_TEST;
   kal_uint16     VMCU_CON1;
   kal_uint16     VMCU_CON2;
   kal_uint16     VAGC_CON1;
   kal_uint16     VAGC_CON2;
   kal_uint16     VAGC_CON3;
   kal_uint16     VAGC_CON4;
   kal_uint16     VAGC_CON5;
   kal_uint16     VAGC_CON6;
#if defined(__DUAL_MIC_SUPPORT__)
   kal_uint16     VAGC2_CON0;
   kal_uint16     VAGC2_CON1;
   kal_uint16     VAGC2_CON2;
   kal_uint16     VAGC2_CON3;
   kal_uint16     VAGC2_CON4;
   kal_uint16     VAGC2_CON5;
   kal_uint16     VAGC2_CON6;
#endif
} RegBackup;

//=============================================================================================
//                  afe
//=============================================================================================
struct {
#if defined(__GAIN_TABLE_SUPPORT__)
   kal_uint32  mic_total_gain;
   kal_uint32  dual_path_loud_spk_gain;
#endif
   /// Speaker usage flag
   /// bit n : aud function n
   /// [Set|Clear] by AFE_Turn[On|Off]Speaker
   kal_uint16  sp_flag;
   /// FIR filter usage flag
   /// bin n: aud function n
   /// [Set|Clear] by AFE_Turn[On|Off]FIR
   kal_uint16  fir_flag;
   /// Microphone usage flag
   /// bin n: aud function n
   /// [Set|Clear] by AFE_Turn[On|Off]Microphone
   kal_uint16  mic_flag;
   /// L1SP_LNA_0, L1SP_LNA_1, or L1SP_LNA_FMRR
   kal_uint8      mic_src;
   kal_uint8      mic_volume;
   kal_bool       mic_mute;
   kal_bool       accessory_flag;
   kal_uint8      sidetone_volume;   
   kal_bool       sidetone_disable;  /// sidetone disable flag
   kal_bool       is_use_refmic_in_idle;
   
   struct   {
      /// L1SP_SPEAKER1, L1SP_SPEAKER2, or L1SP_LOUDSPEAKER
      /// Set by AFE_SetOutputDevice
#if defined(__GAIN_TABLE_SUPPORT__)
      kal_uint32  total_gain;
#endif
      kal_uint8   out_dev;
      kal_uint8   volume;
      kal_int8    digital_gain_index;
      kal_uint16  digital_gain;
      kal_uint8   digital_gain_level;/// digital gain level
      kal_bool    mute;
   } aud[L1SP_MAX_AUDIO];
   kal_uint16     aud_id;
   kal_uint8      Pre_OutDev; //0: voice out, 1: audio out
   kal_int16      Pre_aFunc;
   kal_uint8      Pre_InSrc; //0: voice src, 1: audio src, 2: line-in
   /// for controlling external amplifier
   kal_bool       gpio_lock;
   kal_bool       ext_op_on;
   kal_bool       mute;  /// for mute AFE
   kal_bool       refresh;
   kal_bool       loopback; 
   kal_bool       v8k_off_request;
   kal_bool       aClk_off_request;
   kal_bool       agc_reset_flag; //set as TRUE when turn on microphone. After updated AGC set it as false.
   kal_bool       st2mono;
   kal_bool       st2mono_flag;
   kal_bool       dual_mic_on;
   kal_uint16     a_digi_gain;
   kal_uint16     tone_digi_gain;
   kal_uint16     v_digi_gain;
   kal_uint16     mic_digi_gain;    
   kal_uint32     tune_gain_gpt;
   kal_int16      tune_gain_ctrl;
   kal_bool       tune_gain_gpt_on;
   kal_bool       tune_gain_ctrl_enable;
   kal_bool       tune_gain_ctrl_enable2;  
   kal_bool       afe_OnOff;
   kal_bool       speech_off_flag;
   kal_bool       is_use_refmic_in_loudspk;
   RINGBUFFER_T(DelayCmd,4)  regq;

#if defined(EXT_DAC_SUPPORT) 
   /// for controlling external DAC 
   kal_bool       ext_dac_i2s_on;
   kal_bool       ext_dac_add_st;
   kal_bool       ext_dac_mute;
   kal_int8       ext_dac_aud_func;
   kal_uint8      ext_dac_aud_vol; 
   kal_uint16     ext_dac_freq;   
   kal_uint16     ext_dac_level_gain;               
#endif    
   kal_int16      ext_op_delay; 
   kal_bool       toneLoopbackRec;
   kal_bool       bPowerDown;
   kal_bool       Audio_close_delay_expired;
} afe;

//=============================================================================================
//                  Global Variables
//=============================================================================================

   uint16 audio_con1_bk; 
   uint16 audio_con2_bk;
   kal_bool tune_gain_gpt_init = KAL_FALSE;
//=============================================================================================
//                  External Variables and Functions
//=============================================================================================
extern const uint16 Ext_op_on_delay;
extern const uint16 Ext_op_off_delay;
extern boot_mode_type stack_query_boot_mode(void);

#if defined(EXT_DAC_SUPPORT)  
   extern kal_uint8 aud_get_volume_gain(kal_uint8 mode, kal_uint8 type, kal_uint8 level);
   extern void aud_get_melody_volume_setting(kal_uint8 mode, kal_uint8 *MaxAnalogGain, kal_uint8 *step);
   extern kal_bool audio_tv_cable_in;
#endif 

#if defined( NEW_BLOCK_FILTER_SUPPORT )
   extern volatile kal_uint16 *g_Compen_Blk_Flt;
#endif

#if defined(__BT_SUPPORT__)
   extern const unsigned short default_bt_pcm_out_vol;
#endif

//=============================================================================================
//                  Declaration Of Prototypes
//=============================================================================================
kal_uint32 SaveAndSetIRQMask(void);
void RestoreIRQMask(kal_uint32);
static void _update_digital_gain(kal_int16 v_lowest, kal_int16 a_lowest); 
void AFE_SetRefresh( void );
void AFE_SetOutputVolume( kal_uint8 aud_func, kal_uint8 volume1, kal_int8 digital_gain_index );
static void AFE_Event_Handler( void *data );
static void UpdateMicGain( kal_uint8 mic_vol );
#if defined(__DSP_CHIP_DUALMAC__)
__attribute__ ((section ("DMDSP_SHARE_AUDIO_ZI"))) 
SPH_AGC_t SPH_AGC;
#endif

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        Special Configurations for Specific Usage
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                            Configuration
//=============================================================================================
//#define __AFE_DEBUG__
#define UNIT_TEST_AFE2 0

//=============================================================================================
//                  Debug Usage
//=============================================================================================
#ifdef __AFE_DEBUG__
   #define afe_prompt_trace  kal_prompt_trace
#else
   #define afe_prompt_trace(...) 
#endif

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
static void SearchSpkFlag( kal_int16 *v_lowest, kal_int16 *a_lowest )
{
   kal_int16 I, val;
   
   if(afe.mute)
   {
      *v_lowest = -1; 
      *a_lowest = -1;  
      return;
   }   
   
   for( I = L1SP_MAX_AUDIO; I >= 0; I-- ) {
      if( afe.sp_flag & (1<<I) ) {
         val = (kal_uint16)afe.aud[I].out_dev;
         if( val & (L1SP_BUFFER_0|L1SP_BUFFER_1) )
            *v_lowest = I;
         if( val & L1SP_BUFFER_ST )
            *a_lowest = I;
      }
   }
   
   // move _update_digital_gain here for APM 
   _update_digital_gain(*v_lowest, *a_lowest); 
   if (!kal_if_lisr())
      kal_trace(TRACE_STATE, AFE_DIGI_GAIN, afe.v_digi_gain, afe.a_digi_gain);
}

static void _apply_mic_setting(kal_int16 a_lowest, kal_int16 v_lowest)
{
   if ( afe.mic_src==L1SP_LNA_FMRR ){
      *AUDIO_CON21 &= ~0x700;
      *AUDIO_CON22 &= ~0x700;
      *AUDIO_CON23 = (*AUDIO_CON23 & ~(AUDADCL_INPUT_SEL_MASK | AUDADCR_INPUT_SEL_MASK)) |
                         (AUDADCR_INPUT_SEL_R_LSB_AMP | AUDADCL_INPUT_SEL_L_LSB_AMP);
      *AUDIO_CON5  |= 1;      //Level shift buffer set line left
      *AUDIO_CON6  |= 0x2000; //Level shift buffer set line right
   }
   else
   if( afe.mic_src==L1SP_LNA_1 ) {                  /* Headset Mode */
      /* Switch input source to headset microphone */
      *AUDIO_CON21 = (*AUDIO_CON21 & 0xF8FF) | (3<<8);
      *AUDIO_CON22 = (*AUDIO_CON22 & 0xF8FF) | (3<<8);
      *AUDIO_CON23 = (*AUDIO_CON23 & ~(AUDADCL_INPUT_SEL_MASK | AUDADCR_INPUT_SEL_MASK)) |
                         (AUDADCR_INPUT_SEL_R_PRE_AMP | AUDADCL_INPUT_SEL_L_PRE_AMP);
   }
   else {                                                /* Normal Mode */
      //LNA_0 and DIGITAL_MIC                                                /* Normal Mode */
      /* Switch input source to normal microphone */
      if(afe.is_use_refmic_in_loudspk & (( (a_lowest >= 0) && 
        (afe.aud[a_lowest].out_dev & L1SP_BUFFER_EXT) ) ||
        ( (v_lowest >= 0) && (afe.aud[v_lowest].out_dev & L1SP_BUFFER_EXT) )) )
      {
         *AUDIO_CON21 = (*AUDIO_CON21 & 0xF8FF) | (2<<8);
         *AUDIO_CON22 = (*AUDIO_CON22 & 0xF8FF) | (1<<8);
      }else
      {
         *AUDIO_CON21 = (*AUDIO_CON21 & 0xF8FF) | (1<<8);
         *AUDIO_CON22 = (*AUDIO_CON22 & 0xF8FF) | (2<<8);
      }
      *AUDIO_CON23 = (*AUDIO_CON23 & ~(AUDADCL_INPUT_SEL_MASK | AUDADCR_INPUT_SEL_MASK)) |
                         (AUDADCR_INPUT_SEL_R_PRE_AMP | AUDADCL_INPUT_SEL_L_PRE_AMP);
   }
}

static void AFE_SetRefVol(kal_bool fgEnable)
{
   return;
}

static void AVolumeRampDown() 
{ 
   kal_int32 I;
   kal_int16 i2Gain;
   kal_uint16 OrgValue1, OrgValue2;

   i2Gain = (kal_int16)(*AUDIO_CON1 & ~0xFFC0);
   OrgValue1 = *AUDIO_CON1;
   OrgValue2 = *AUDIO_CON2;
    
    for (I=i2Gain; I<=0x2c; I++)
    {
      *AUDIO_CON1 = (I) | (OrgValue1 & 0xFFC0);
      *AUDIO_CON2 = (I) | (OrgValue2 & 0xFFC0);
    }
   i2Gain = (kal_int16)((*AUDIO_CON1 & 0x3F00)>>8);
   for (I=i2Gain; I<=0x2c; I++)
   {
      *AUDIO_CON1 = (I<<8) | (OrgValue1 & 0xC0FF);
   }
}


static void AFE_DELAY(uint16 delay)
{
   kal_uint32 curr_frc, latest_us;

   curr_frc = ust_get_current_time();//unit: micro second (us)
   do{
      latest_us = ust_get_current_time();
   }while(delay > ust_get_duration(curr_frc, latest_us));
}


//=============================================================================================
//                  Digital Gain Convert
//=============================================================================================
/*****************************************************************************
* FUNCTION
*  AFE_SetOutputVolume
* DESCRIPTION
*   This function is to set the output volume of an audio function.
*
* PARAMETERS
*  aud_func - the audio function
*  volume - range is from 0 to 255
* RETURNS
*  None
* GLOBALS AFFECTED
*  None
*****************************************************************************/
/// the value of the table is in 1.15 fixed-point
/// -64 dB = 20 log x => x = math.pow(10.0, -64.0/20) * 0x8000
static const kal_uint16 digital_gain_8db_table[8] = {
     21, /// -64 dB
     52, /// -56 dB
    130, /// -48 dB
    328, /// -40 dB
    823, /// -32 dB
   2068, /// -24 dB
   5193, /// -16 dB
  13045  ///  -8 dB
};

/// the value of the table is in 1.14 fixed-point
/// 0.5 dB = 20 log x => x = math.pow(10.0, 0.5/20) * 0x4000
static const kal_uint16 digital_gain_halfdb_table[15] = {
  17355, /// 0.5 dB
  18383, /// 1.0 dB
  19472, /// 1.5 dB
  20626, /// 2.0 dB
  21848, /// 2.5 dB
  23143, /// 3.0 dB
  24514, /// 3.5 dB
  25967, /// 4.0 dB
  27506, /// 4.5 dB
  29135, /// 5.0 dB
  30862, /// 5.5 dB
  32690, /// 6.0 dB
  34627, /// 6.5 dB
  36679, /// 7.0 dB
  38853  /// 7.5 dB
};
#if defined(__GAIN_TABLE_SUPPORT__)
static const kal_uint16 digital_gain_4db_table[17] = 
{
   32767,   /* 0     dB */
   20675,   /* -4    dB */
   13044,   /* -8    dB */
   8231,    /* -12   dB */
   5193,    /* -16   dB */
   3277,    /* -20   dB */
   2068,    /* -24   dB */
   1305 ,   /* -28   dB */
   823,     /* -32   dB */
   519,     /* -36   dB */
   328,     /* -40   dB */
   207,     /* -44   dB */
   130,     /* -48   dB */
   82,      /* -52   dB */
   52,      /* -56   dB */
   33,      /* -60   dB */
   21       /* -64   dB */
};

/// digital_gain_index: 0:0dB, -1:-0.5dB, ..., -128:-64dB
static const kal_uint16 digital_gain_table[17] = 
{
   32767,   /* 0     dB */
   31838,   /* -0.25 dB */
   30934,   /* -0.5  dB */
   30057,   /* -0.75 dB */
   29204,   /* -1    dB */
   28375,   /* -1.25 dB */
   27570,   /* -1.5  dB */
   26788,   /* -1.75 dB */
   26028,   /* -2    dB */
   25290,   /* -2.25 dB */
   24572,   /* -2.5  dB */
   23875,   /* -2.75 dB */
   23197,   /* -3    dB */
   22539,   /* -3.25 dB */
   21900,   /* -3.5  dB */
   21278,   /* -3.75 dB */
   20675    /* -4    dB */
};
#endif
kal_uint16 _converted_digital_gain(kal_int8 digital_gain_index)
{
   kal_int8 converted_gain_index;
   kal_uint16 digital_gain; /// 1.15 fixed-point
   
   /// Uncomment the following to make sure MMI code is ready.
   ///ASSERT(digital_gain_index <= 0);
   converted_gain_index = digital_gain_index;
   if (0 == converted_gain_index) {
      digital_gain = 0x8000; /// 0 dB, special case
   } else {
      converted_gain_index = digital_gain_index + 128;
      /// Uncomment the following to make sure MMI code is ready.
      ///ASSERT(converted_gain_index >= 0);
      /// converted_gain_index: 0:-64dB, 1:-63.5dB, 127:-0.5dB
      digital_gain = digital_gain_8db_table[converted_gain_index>>4];
      if ((converted_gain_index&0x0F) > 0) {
         digital_gain = ((kal_uint32)digital_gain * digital_gain_halfdb_table[(converted_gain_index&0x0F)-1]) >> 14;
      }
   }
   return digital_gain;      
}

//=============================================================================================
//                  Sidetone Gain
//=============================================================================================
static const kal_uint16 SideToneTable[] = {
   32767, 26027, 20674, 16422, 13044, 10361, 8230, 6537,       /* 2 dB per step */
    5193,  4125,  3276,  2602,  2066,  1641, 1304, 1035,
     822,   653,   519,   412,   327,   260,  206,  164
};

static void UpdateSidetone( kal_int8 vol )
{
   kal_int8 J;
   kal_uint32 R;
   kal_uint16 sidetone_vol;

   if(afe.sidetone_disable || afe.sidetone_volume == 0) {
      L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_SIDETONE, 0, (kal_uint32)NULL );
      return;
   }
   sidetone_vol = afe.sidetone_volume;

   {
      kal_int16 i;
      kal_uint8  agc_ul_gain, pga_ul_gain = 0;
      if( afe.mic_src == L1SP_LNA_DIGITAL ){
         if( afe.mic_volume > TRANSPARENT_AGC_GAIN_OFFSET)
            agc_ul_gain = afe.mic_volume - TRANSPARENT_AGC_GAIN_OFFSET;
         else
            agc_ul_gain = 0;
      } 
      else {
         agc_ul_gain = 0;
         if(!AGC_ENABLE_FLAG)
         {
            pga_ul_gain = AGC_MIN_GAIN;
            i = afe.mic_volume - TRANSPARENT_SIDETONE_GAIN_OFFSET;
            i = i - pga_ul_gain;
            if(i>3)
            {
               for(; i > 3; i-=6)
               {
                  pga_ul_gain += 6;
               }
            }
            if(pga_ul_gain > MAX_PGA_GAIN)
               pga_ul_gain = MAX_PGA_GAIN;

            if(afe.mic_volume < pga_ul_gain)
               agc_ul_gain = 0;
            else
               agc_ul_gain = afe.mic_volume - pga_ul_gain;
         }
      }
      i = agc_ul_gain;
      i = i << 3;
      sidetone_vol += i;

      kal_prompt_trace(MOD_L1SP,"sidetone %d %d", afe.sidetone_volume, sidetone_vol);
      if(sidetone_vol > 255 )
      sidetone_vol = 255;            
}

   R = (kal_uint32)(sidetone_vol & 0xF);
   // vol = vol + 8 - (kal_int8)(sidetone_vol >> 4);
   vol = vol + 1 - (kal_int8)(sidetone_vol >> 4);
   
   if( vol < 0 )
      vol = 0;
   J = ( vol == 0 )? 0: vol-1;
   L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_ENABLE_SIDETONE, 0, 0 );
   L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_SIDETONE, (kal_uint16)(((kal_uint32)SideToneTable[vol]*(16-R) + (kal_uint32)SideToneTable[J]*R) >> 4), (kal_uint32)NULL );
}

//=============================================================================================
//                 Update VGain / AGain
//=============================================================================================

static void UpdateVGain( kal_uint8 aud_func )
{
   kal_uint16 vol = afe.aud[aud_func].volume;
   kal_uint16 amp_gain = (vol>>2);
   
   amp_gain = 0x3F - (uint8)(vol>>2);
   if(amp_gain > 44)
      amp_gain =44;//101101~111110 not used
 #if defined(MT6575) || defined(MT6577)
   *AUDIO_CON1 = (kal_uint16)((0xc << 8) | (*AUDIO_CON1 & 0xC0FF)); //fixed 2db   
   *AUDIO_CON1 = (kal_uint16)((amp_gain << 0) | (*AUDIO_CON1 & 0xFFC0));
 #else
   *AUDIO_CON1 = (kal_uint16)((amp_gain << 8) | (*AUDIO_CON1 & 0xC0FF));
 #endif
   if( afe.mic_src == L1SP_LNA_FMRR )
      afe.mic_volume = FM_RADIO_RECORDING_VOLUME;
   UpdateMicGain(afe.mic_volume);
   
   if( (aud_func == L1SP_SPEECH) )
   {
      if(afe.tune_gain_ctrl_enable) 
      	//After chip 76, 4 for 1dB
      	UpdateSidetone( (kal_int8)(vol >> 3) );
   }
   else
      L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_SIDETONE, 0, (kal_uint32)NULL );
}

static void UpdateAGain( kal_uint8 aud_func )
{
   const kal_uint16 vol = afe.aud[aud_func].volume;
   kal_uint16 amp_gain; 

   amp_gain = 0x3F - (uint8)(vol>>2);
   if(amp_gain > 44)
      amp_gain =44;//101101~111110 not used
   //Do not update HP Gain since AP will control.

   if( (aud_func == L1SP_SPEECH) )
   {
      if(afe.tune_gain_ctrl_enable)
      	//After chip 76, 4 for 1dB
      	UpdateSidetone( (kal_int8)(vol >> 3) );
   }
   else
      L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_SIDETONE, 0, (kal_uint32)NULL );
}

static void _update_digital_gain_imp(kal_int16 aud_func)
{
   kal_uint16 digital_gain = afe.aud[aud_func].digital_gain;
   kal_uint32 level_gain;

   level_gain = ((uint32)afe.aud[aud_func].digital_gain_level * 0x8000) / 100;
   switch (aud_func) {
      /// Speech
      case L1SP_SPEECH:
      case L1SP_SND_EFFECT:
      case L1SP_VOICE:
         if( (afe.aud[aud_func].mute == KAL_TRUE) || (afe.aud[aud_func].volume == 0) ){
            if(afe.v_digi_gain!=0) 
            {
               afe.v_digi_gain = 0;
               L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_DL_VOLUME, afe.v_digi_gain, 128 );
            }
         }
         else
         {
            kal_uint16 dsp_gain; 
            dsp_gain = ((((kal_uint32)DG_DL_Speech * digital_gain) >> 15) * level_gain) >> 15;
            if(afe.v_digi_gain!=dsp_gain)
            {
               afe.v_digi_gain = dsp_gain;
               L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_DL_VOLUME, afe.v_digi_gain, 128 );
            }

         }
         break;
      case L1SP_KEYTONE:
      case L1SP_TONE:
      case L1SP_AUDIO:   // Audio (DAF, AAC, WMA, WAV), MIDI, multi-channel wave, tone
         {
            kal_uint16 dsp_gain;
         #if defined(__BT_SUPPORT__)
            if( afe.aud[aud_func].mute == KAL_TRUE )
               dsp_gain = 0;
            else
         #endif
               dsp_gain = ((((kal_uint32) DG_DAF * digital_gain) >> 15) * level_gain) >> 15;

            if(afe.a_digi_gain!=dsp_gain)
            {
               afe.a_digi_gain = dsp_gain;
               L1Audio_PutMessage(MSG_L1AUDIO2FAS_AUDIO_SET_OUTPUT_VOLUME, dsp_gain, (kal_uint32)NULL);
            }
         }
         break;
      
      case L1SP_DAI:   // not really an audio function
         break;
      
      case L1SP_LINEIN:   // can't apply digital gain
         break;
      default:
         ASSERT(0);
   }
}

static void _update_digital_gain(kal_int16 v_lowest, kal_int16 a_lowest)
{
#if defined(__BT_SUPPORT__)
   if(AM_IsBluetoothOn()) // for the case of bluetooth use
   {
      if( afe.aud[L1SP_AUDIO].mute == KAL_TRUE )
      {
         if(afe.a_digi_gain!=0)
         {
            afe.a_digi_gain = 0;
            L1Audio_PutMessage(MSG_L1AUDIO2FAS_AUDIO_SET_OUTPUT_VOLUME, 0, (kal_uint32)NULL);
         }
      }
      else
      {
      #if defined(__GAIN_TABLE_SUPPORT__)
         kal_uint32 level_gain;
         kal_uint16 dsp_gain;

         level_gain = ((uint32)afe.aud[L1SP_AUDIO].digital_gain_level * 0x8000) / 100;
         dsp_gain = ((((kal_uint32) DG_DAF * afe.aud[L1SP_AUDIO].digital_gain) >> 15) * level_gain) >> 15;
         if(afe.a_digi_gain!=dsp_gain)
         {
            afe.a_digi_gain=dsp_gain;
            L1Audio_PutMessage(MSG_L1AUDIO2FAS_AUDIO_SET_OUTPUT_VOLUME, afe.a_digi_gain, (kal_uint32)NULL);
         }
      #else
         if(afe.a_digi_gain!=DG_DAF)
         {
            afe.a_digi_gain = DG_DAF;
            L1Audio_PutMessage(MSG_L1AUDIO2FAS_AUDIO_SET_OUTPUT_VOLUME, DG_DAF, (kal_uint32)NULL);
         }
      #endif
      }

      if( afe.aud[L1SP_VOICE].mute == KAL_TRUE || afe.aud[L1SP_SPEECH].mute == KAL_TRUE )
      {
         if(afe.v_digi_gain!=0)
         {
            afe.v_digi_gain = 0;
            L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_DL_VOLUME, afe.v_digi_gain, 128 );
         }
      }
      else
      {
      #if defined(__GAIN_TABLE_SUPPORT__)
         kal_uint16 dsp_gain;
         dsp_gain = (((kal_uint32)DG_DL_Speech * afe.aud[L1SP_SPEECH].digital_gain) >> 15);
         if(afe.v_digi_gain!=dsp_gain)
         { 
            afe.v_digi_gain = dsp_gain;
            L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_DL_VOLUME, afe.v_digi_gain, 128 );
         }
      #else
         if(afe.v_digi_gain!=DG_DL_Speech) 
         {
            afe.v_digi_gain = DG_DL_Speech;
            L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_DL_VOLUME, DG_DL_Speech, 128 );
         }
      #endif
      }

      if(afe.mic_digi_gain!=DG_Microphone)
      {
         afe.mic_digi_gain = DG_Microphone;
         L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_UL_VOLUME, DG_Microphone, 128 );
      }
      return;
   }
#endif //defined(__BT_SUPPORT__)

   if (v_lowest >= 0) {
      if (a_lowest >= 0) // Voice Amp ON && Audio Amp ON
      {
         _update_digital_gain_imp(v_lowest);
         _update_digital_gain_imp(a_lowest);
      } 
      else  //Voice Amp ON && Audio Amp OFF
      {
         _update_digital_gain_imp(v_lowest);
      }
   } 
   else if (a_lowest >= 0)   // Voice Amp OFF && Audio Amp ON
   {
      _update_digital_gain_imp(a_lowest);
   } 
   else  // Voice Amp OFF && Audio Amp OFF; Restore the values to default value (for Bluetooth)
   {
      if(afe.v_digi_gain!=DG_DL_Speech) 
      {
         afe.v_digi_gain = DG_DL_Speech;
         L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_DL_VOLUME, DG_DL_Speech, 128 );
      }
    #if defined(EXT_DAC_SUPPORT)
      if(afe.ext_dac_aud_func == -1)
    #endif
      if(afe.a_digi_gain!=DG_DAF)
      {
         afe.a_digi_gain = DG_DAF;
         L1Audio_PutMessage(MSG_L1AUDIO2FAS_AUDIO_SET_OUTPUT_VOLUME, DG_DAF, (kal_uint32)NULL);
      }
   }
}

//=============================================================================================
//                  VAPDN Related
//=============================================================================================
static void UpdateVAPDN(kal_uint8 device)
{
   if( afe.mic_mute||afe.mic_flag==0 ||afe.mute ) {
      *AUDIO_CON21 &= ~0x1000;
      *AUDIO_CON22 &= ~0x1000;
      *AUDIO_CON23 &= ~0x8800;
      *AUDIO_CON31 &= ~0x8000;
   #if defined(MT6573_S00) // On MT6573E1, keep VMIC on for AP side TV out detection
      afe.accessory_flag = KAL_TRUE;
   #endif
      if( afe.accessory_flag )
      {
      #if !(defined(MT6575)  || defined(MT6577))
         *VMIC_CON0   |= 0x0001;
      #else
         *AUDIO_CON34 |= 0x8000;
      #endif
      }
      else
      {
      #if !(defined(MT6575)  || defined(MT6577))
         *VMIC_CON0   &= ~0x0001;
      #else 
         *AUDIO_CON34 &= ~0x8000;
      #endif
      }
      return;
   }
   *AUDIO_CON31 |= 0x8000;
   
 #if !(defined(MT6575)  || defined(MT6577))
   *VMIC_CON0   |= 0x0001;
 #else 
   *AUDIO_CON34 |= 0x8000;
 #endif
   if (afe.dual_mic_on)
   {
      if(afe.mic_src == L1SP_LNA_DIGITAL){
         L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_UL_DEVICE, eAUD_INDEV_DUAL_DIGITAL_MIC, (kal_uint32)NULL );
         *AUDIO_CON24 |= MICSEL;          
      #if defined(MT6575) || defined(MT6577)
         *AUDIO_CON33 |= 0x0042;
      #endif  
  
         *AUDIO_CON31 |= 0x8000;
      }else{
         L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_UL_DEVICE, eAUD_INDEV_DUAL_MIC, (kal_uint32)NULL );
         *AUDIO_CON24 &= ~MICSEL;
      #if defined(MT6575) || defined(MT6577)
         *AUDIO_CON33 &= ~0x0042;
      #endif
      
         if( afe.mic_src == L1SP_LNA_FMRR ){
            *AUDIO_CON21 &= ~0x1000;
            *AUDIO_CON22 &= ~0x1000;
         }else{
            *AUDIO_CON21 |= 0x1000;
            *AUDIO_CON22 |= 0x1000;
         }
         *AUDIO_CON23 |= 0x8800;
         *AUDIO_CON31 |= 0x8000;
      }
   }
   else
   {
      if(afe.mic_src == L1SP_LNA_DIGITAL){
         L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_UL_DEVICE, eAUD_INDEV_SINGLE_DIGITAL_MIC, (kal_uint32)NULL );
         *AUDIO_CON24 |= MICSEL;

         #if defined(MT6575) || defined(MT6577)
         *AUDIO_CON33 |= 0x0042;
         #endif  

         *AUDIO_CON31 |= 0x8000;
      }else{
         L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_UL_DEVICE, eAUD_INDEV_SINGLE_MIC, (kal_uint32)NULL );
         *AUDIO_CON24 &= ~MICSEL;

      #if defined(MT6575) || defined(MT6577)
         *AUDIO_CON33 &= ~0x0042;
      #endif
          
         if( afe.mic_src == L1SP_LNA_FMRR ){
            *AUDIO_CON21 &= ~0x1000;
            *AUDIO_CON22 &= ~0x1000;
         }else{
            *AUDIO_CON21 |= 0x1000;
            *AUDIO_CON22 |= 0x1000;
         }
         *AUDIO_CON31 |= 0x8000;
         *AUDIO_CON23 |= 0x8000;
      }
   }
}

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        AFE Feature or Chip Sepcific Functions
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/


//=============================================================================================
//                  DUAL MAC DSP Specific Functions 
//=============================================================================================
extern const unsigned char Digital_Mic1_Phase;
extern const unsigned char Digital_Mic2_Phase;
extern const unsigned char Digital_Mic_Clock_Selection;

kal_bool AFE_IsSpeakerMuted( kal_uint8 aud_func)
{
   return afe.aud[aud_func].mute;
}

kal_uint16 AFE_GetAudioDigiGain( kal_bool isAPM)
{
   return afe.a_digi_gain;;
}

static void UpdateMicGain( kal_uint8 mic_vol )
{
   kal_uint8  agc_ul_gain, pga_ul_gain = 0;
   kal_int16  i;
   //UL PGA and AGC digital gain update
   if( afe.mic_src == L1SP_LNA_DIGITAL ){
      if( afe.mic_volume > TRANSPARENT_AGC_GAIN_OFFSET)
         agc_ul_gain = afe.mic_volume - TRANSPARENT_AGC_GAIN_OFFSET;
      else
         agc_ul_gain = 0;
   } else {
      if(AGC_ENABLE_FLAG){
         agc_ul_gain = afe.mic_volume;
      }else{
         pga_ul_gain = AGC_MIN_GAIN;
         i = afe.mic_volume - TRANSPARENT_SIDETONE_GAIN_OFFSET;
         i = i - pga_ul_gain;
         if(i>3){
            for(; i > 3; i-=6){
               pga_ul_gain += 6;
            }
         }
         if(pga_ul_gain > MAX_PGA_GAIN)
            pga_ul_gain = MAX_PGA_GAIN;
         
         if(afe.mic_volume < pga_ul_gain)
            agc_ul_gain = 0;
         else
            agc_ul_gain = afe.mic_volume - pga_ul_gain;
      }
   }
   *AUDIO_CON20 = (*AUDIO_CON20 & 0xC0C0) | ((kal_uint16)afe.mic_volume << 8) | afe.mic_volume;

   if( SPH_AGC.u4AGC_MAX_PGA_GAIN_CH1 != agc_ul_gain || afe.agc_reset_flag == KAL_TRUE ){
      SPH_AGC.u4AGC_MAX_PGA_GAIN_CH1 = agc_ul_gain;
      SPH_AGC.u4AGC_MAX_PGA_GAIN_CH2 = agc_ul_gain;

      if(AGC_ENABLE_FLAG){
         SPH_AGC.u4AGC_MIN_PGA_GAIN_CH1 = AGC_MIN_GAIN;
         SPH_AGC.u4AGC_MIN_PGA_GAIN_CH2 = AGC_MIN_GAIN;
      }else{
         SPH_AGC.u4AGC_MIN_PGA_GAIN_CH1 = pga_ul_gain;
         SPH_AGC.u4AGC_MIN_PGA_GAIN_CH2 = pga_ul_gain;
      }

      if(AGC_ENABLE_FLAG){
         L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_UL_IIR, KAL_TRUE, (kal_uint32)NULL );
      }else{
         L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_UL_IIR, KAL_FALSE, (kal_uint32)NULL );
      }

      L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_SET_AGC, AGC_ENABLE_FLAG, (kal_uint32)&SPH_AGC);

      afe.agc_reset_flag = KAL_FALSE;
   }
}

void AFE_SetDualMic(kal_bool On)
{
   afe.dual_mic_on = On;
   L1Audio_SetDebugInfoN(STEREO_RECORD_INFO, afe.dual_mic_on);
}

kal_bool AFE_IsDualMic(void)
{
   return afe.dual_mic_on;
}

static void AFE_AUDIO_CON9_CTRL(void)
{
   if( (*AUDIO_CON9&0x0003)!=0x0003 ) 
   {
      *AUDIO_CON9 = 0x52;
      AFE_DELAY(1);
      *AUDIO_CON9 |= 0x1;
      AFE_DELAY(1);
   }
}

void Tune_Gain_On( void *data )
{
   afe.tune_gain_ctrl = 0;
   afe.tune_gain_ctrl_enable= KAL_TRUE;
   afe.tune_gain_gpt_on = KAL_FALSE;   
   L1Audio_SetEvent(afe.aud_id, NULL);
}

void AFE_SetUseRefMICInLoudSpk(kal_bool On)
{
   afe.is_use_refmic_in_loudspk = On;
}

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        AFE General Interface Functions
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
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
   afe.mic_src          = 0;
   afe.sidetone_volume  = 127;
   afe.sp_flag          = 0;
   afe.fir_flag         = 0;
   afe.mic_flag         = 0;
   afe.mic_volume       = 7;
   afe.mic_mute         = KAL_FALSE;
   afe.sidetone_disable = KAL_FALSE;
   afe.accessory_flag   = KAL_FALSE;
   afe.ext_op_on        = KAL_FALSE;
   afe.ext_op_delay     = 0;
   afe.mute             = KAL_FALSE;
   afe.loopback         = KAL_FALSE;
   afe.agc_reset_flag   = KAL_FALSE;
 #if defined(__DUAL_MIC_SUPPORT__)
   afe.dual_mic_on      = KAL_TRUE;
 #else
   afe.dual_mic_on      = KAL_FALSE;
 #endif
   afe.a_digi_gain      = 0x7FFF;
   afe.tone_digi_gain   = 0x7FFF; 
   afe.st2mono_flag     = KAL_FALSE; 
   afe.v_digi_gain      = 0x7FFF;
   afe.mic_digi_gain    = 0x7FFF;
   afe.is_use_refmic_in_loudspk = KAL_FALSE;   

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
      afe.aud[I].digital_gain = 0x8000;  // (in 1.15 fixed-point) 0 dB
      afe.aud[I].digital_gain_index = 0;
      afe.aud[I].digital_gain_level = 100;
      afe.aud[I].mute         = KAL_FALSE;
#if defined(__GAIN_TABLE_SUPPORT__)
      afe.aud[I].total_gain   = 0;
#endif
   }
#if defined(__GAIN_TABLE_SUPPORT__)
   afe.mic_total_gain = 0x0;
   afe.dual_path_loud_spk_gain = 0x0;
#endif
   
 #if defined(MT6575) || defined(MT6577)
   *WR_PATH0    |= 0x7fa0;
   *AUDIO_CON10  = 0x1A1;
   *AUDIO_CON0   = 0x4203; //0x4000; //0;
   *AUDIO_CON4   = 0x0404;
   *AUDIO_CON6   = (*AUDIO_CON6 & ~0x0FFF) | 0x0a44; //0x0533;
   *AUDIO_CON17  = 0x0008;
   *AUDIO_CON7   = (*AUDIO_CON7 & ~0xc03f) | 0x003f; //0x0030; //disable HP amp startup mode, audio bias adjustment 1 
   *AUDIO_CON8   = 0x0000; //0x7000; // disable short circuit protection 
   *AUDIO_CON10  = 0x01A1;
 #elif defined(MT6573)
   *WR_PATH0   |= 0x7fa0;
   *AUDIO_CON10 = 0x20; // zero padding off 
   *AUDIO_CON0  = 0x4203; //0x4000; //0;
   *AUDIO_CON4  = 0x1818;
   *AUDIO_CON6  = 0x1B;
   *AUDIO_CON7  = 0x400; //DRTZ 0; disable HP amp startup mode
   *AUDIO_CON8  = 0x7000; // disable short circuit protection
 #endif
   *AUDIO_CON25 = 0;
   *AUDIO_CON26 = 0;
   *AUDIO_CON27 = 0;
   *AUDIO_CON28 = 0;

 #if defined(MT6573)
   *AUDIO_CON29 = 0x1150;
   *AUDIO_CON30 = 0x150;
   *AUDIO_CON31 = 0x8000;
 #elif defined(MT6575) || defined(MT6577)
   *AUDIO_CON29 = 0x1154; 
   *AUDIO_CON30 = 0x154; 
   *AUDIO_CON31 = 0x8000;
 #endif
   
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
   afe.v8k_off_request           = KAL_FALSE;
   afe.aClk_off_request          = KAL_FALSE;
   afe.toneLoopbackRec           = KAL_FALSE;
   
   afe.bPowerDown = KAL_TRUE;

#if defined(__DATA_CARD_SPEECH__)
   *VAUDN_CON0 &= ~0x1;
   *VAUDP_CON0 &= ~0x1;
   *VAUDP_CON2 &= ~0x100;
   *VAUDP_CON1 = 0x0000;
#endif

   afe.Audio_close_delay_expired = KAL_FALSE;
   afe.Pre_OutDev = 0;
   afe.Pre_aFunc  = -1;

   if(!tune_gain_gpt_init)
   {
      afe.tune_gain_gpt = DclSGPT_Open( DCL_GPT_CB, 0);
      tune_gain_gpt_init = KAL_TRUE;
   }
   afe.tune_gain_gpt_on = KAL_FALSE; 
   afe.tune_gain_ctrl = 0;
   afe.tune_gain_ctrl_enable = KAL_TRUE;
   afe.tune_gain_ctrl_enable2 = KAL_FALSE;  
   afe.afe_OnOff = KAL_FALSE;
}

//=============================================================================================
//                  Audio/8K Clock Related
//=============================================================================================
void AFE_TurnOn8K( void )
{
}

void AFE_TurnOff8K( void )
{
   afe.v8k_off_request = KAL_TRUE;
}

void AFE_TurnOff8K_Direct( void )
{
}

void AFE_TurnOnAudioClock( kal_uint8 clock )
{
}

void AFE_TurnOffAudioClock( void )
{
}

// For hardware equalizer
// The coefficient can be written into register only when the power is on
void AFE_TurnOnAudioPower( void )
{
}

void AFE_TurnOffAudioPower( void )
{
}

//=============================================================================================
//                  Wavetable Data Transfer Unit DMA
//=============================================================================================
void AFE_TurnOnWTDMA( void )
{
}

void AFE_TurnOffWTDMA( void )
{
}

//=============================================================================================
//                  Speaker Functions
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
void AFE_TurnOnSpeaker( kal_uint8 aud_func )
{
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();    /* Disable interrupt to prevent race condition */  
   afe.sp_flag |= (1<<aud_func);
   RestoreIRQMask(savedMask);
   if(!L1Audio_CheckFlag(afe.aud_id))
      L1Audio_SetFlag(afe.aud_id);
   AFE_SetRefresh();
   L1Audio_Msg_AFE_TurnSpk( L1AUDIO_Str_onoff(1), L1AUDIO_Func_Name(aud_func) );
}

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
void AFE_TurnOffSpeaker( kal_uint8 aud_func )
{
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();    /* Disable interrupt to prevent race condition */
   afe.sp_flag &= ~(1<<aud_func);
   RestoreIRQMask(savedMask);
   if(!L1Audio_CheckFlag(afe.aud_id))
      L1Audio_SetFlag(afe.aud_id);
   AFE_SetRefresh();
   L1Audio_Msg_AFE_TurnSpk( L1AUDIO_Str_onoff(0), L1AUDIO_Func_Name(aud_func) );
}


void AFE_FastCloseSpk(void)
{
}

//=============================================================================================
//                  Microphone Functions
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
void AFE_TurnOnMicrophone( kal_uint8 aud_func )
{
   kal_uint32 savedMask;

   /// Disable interrupt to prevent race condition
   savedMask = SaveAndSetIRQMask();
   afe.mic_flag |= (1<<aud_func);
   RestoreIRQMask(savedMask);
   afe.agc_reset_flag = KAL_TRUE;
   AFE_SetRefresh();

   ///Currently, when video recording, video LISR will call Media_Record.
   ///ASSERT(!kal_if_hisr());
   ///kal_trace(TRACE_STATE, AFE_SWITCH_MIC, '+', aud_func);
   L1Audio_Msg_AFE_TurnMIC( L1AUDIO_Str_onoff(1), L1AUDIO_Func_Name(aud_func) );
}

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
void AFE_TurnOffMicrophone( kal_uint8 aud_func )
{
   kal_uint32 savedMask;

   /// Disable interrupt to prevent race condition
   savedMask = SaveAndSetIRQMask();
   afe.mic_flag &= ~(1<<aud_func);
   RestoreIRQMask(savedMask);

   AFE_SetRefresh();

   ///Currently, when video recording, video LISR will call Media_Record.
   ///ASSERT(!kal_if_hisr());
   ///kal_trace(TRACE_STATE, AFE_SWITCH_MIC, '-', aud_func);
   L1Audio_Msg_AFE_TurnMIC( L1AUDIO_Str_onoff(0), L1AUDIO_Func_Name(aud_func) );
}

kal_bool AFE_IsMicrophoneOn( kal_uint8 aud_func )
{
   return (kal_bool)((afe.mic_flag & (1<<aud_func)) != 0);
}


void AFE_SetUseRefMICInIdle(kal_bool On)
{
   afe.is_use_refmic_in_idle = On;   
}

//=============================================================================================
//                  BT Functions
//=============================================================================================
void AFE_TurnOnBluetooth( kal_uint16 param )
{
}

void AFE_TurnOffBluetooth( void )
{
}

//=============================================================================================
//                  DAI Related Functions
//=============================================================================================
void AFE_TurnOnDAI( void )
{
}

void AFE_TurnOffDAI( void )
{
}

//=============================================================================================
//                  External DAC Interface Related Functions
//=============================================================================================
/// External DAC Interface / fmt: 1 = I2S, 0 = EIAJ / cycle: 32 or 16
void AFE_TurnOnEDI( kal_uint16 dir, kal_uint16 fmt, kal_uint16 cycle )
{   
}

void AFE_TurnOffEDI( void )
{
}

kal_bool AFE_IsEDIOn( void )
{
   return KAL_FALSE;
}

//=============================================================================================
//                  MicBias Functions (for accessory detection use)
//=============================================================================================
/*****************************************************************************
* FUNCTION
*  AFE_TurnOnMicBias , AFE_TurnOffMicBias
*       : Add for accessory detection use
* CALLER
*  AUX_EINT_HISR
*****************************************************************************/
kal_uint8 AFE_TurnOnMicBias( void )
{
   if( afe.accessory_flag == KAL_TRUE )
      return 0;
   afe.accessory_flag = KAL_TRUE;
   AFE_SetRefresh();

   L1Audio_Msg_AFE_Switch( L1AUDIO_Str_onoff(1), AFE_Switch_Name(4) );

   return (afe.mic_src==L1SP_LNA_1);
}

void AFE_TurnOffMicBias(void)
{
   if( afe.accessory_flag == KAL_FALSE )
      return;
   
   afe.accessory_flag = KAL_FALSE;
   AFE_SetRefresh();

   L1Audio_Msg_AFE_Switch( L1AUDIO_Str_onoff(0), AFE_Switch_Name(4) );
}

//=============================================================================================
//                  FIR Functions
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

//=============================================================================================
//                  Input/Output Source/Device Related
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
   ASSERT(!kal_if_hisr());
   kal_brief_trace(TRACE_STATE, AFE_SET_OUTPUT_DEVICE, aud_func, device);
}


kal_uint8 AFE_GetOutputDevice( kal_uint8 aud_func )
{
   return afe.aud[aud_func].out_dev;
}

void AFE_SetInputSource( kal_uint8 src )
{
   if( (src == L1SP_LNA_0 && L1SP_MICROPHONE1 == L1SP_LNA_DIGITAL) || src == L1SP_LNA_DIGITAL ){
      src = L1SP_LNA_DIGITAL;
      L1Audio_PutMessage( MSG_L1AUDIO2FAS_HW_DIGITAL_MIC_CLOCK_PHASE_CH1, Digital_Mic1_Phase, (kal_uint32)NULL );
      L1Audio_PutMessage( MSG_L1AUDIO2FAS_HW_DIGITAL_MIC_CLOCK_PHASE_CH2, Digital_Mic2_Phase, (kal_uint32)NULL );
      L1Audio_PutMessage( MSG_L1AUDIO2FAS_HW_DIGITAL_MIC_INPUT_SAMPLING_RATE, Digital_Mic_Clock_Selection, (kal_uint32)NULL );
      kal_prompt_trace(MOD_L1SP, "DMIC set CH1_Phase %d, CH2_Phase %d, clock sel %d", Digital_Mic1_Phase, Digital_Mic2_Phase, Digital_Mic_Clock_Selection);
   }
   afe.mic_src = src;
   AFE_SetRefresh();
   ASSERT(!kal_if_hisr());
   kal_brief_trace(TRACE_STATE, AFE_SET_INPUT_SRC, src);
}

kal_uint8 AFE_GetInputSource( void )
{
   return afe.mic_src;
}

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
void AFE_EnableToneLoopBackFlag( kal_bool param )
{
   if(param)
      afe.toneLoopbackRec = KAL_TRUE;
   else
      afe.toneLoopbackRec = KAL_FALSE;
}

/// Caller: Task
void AFE_TurnOnLoopback( void )
{
   afe.loopback = KAL_TRUE;
   kal_brief_trace(TRACE_STATE, AFE_SWITCH_LOOPBACK, '+');
}

void AFE_TurnOffLoopback( void )
{
   afe.loopback = KAL_FALSE;
   kal_brief_trace(TRACE_STATE, AFE_SWITCH_LOOPBACK, '-');
}

kal_bool AFE_GetLoopbackStatus( void )
{
   return afe.loopback;
}

//=============================================================================================
//                  Unclassfified Interface Functions
//=============================================================================================

void AFE_SetRefresh( void )
{
   if (kal_if_lisr())
      L1Audio_LSetEvent(afe.aud_id, NULL);
   else
      L1Audio_SetEvent(afe.aud_id, NULL);
}

void AFE_SetSidetone( kal_bool ec )
{
   afe.sidetone_disable = (kal_bool)(ec == KAL_FALSE);
   AFE_SetRefresh();
}

void AFE_SetSamplingRate( uint32 freq )
{
}

/*****************************************************************************
* FUNCTION
*  AFE_GetPathUsage
* DESCRIPTION
*  This function is to get current AFE buffer usage in each mode
*
* PARAMETERS
*  u1AudFunc  - L1SP_KEYTONE/L1SP_TONE/L1SP_SPEECH/L1SP_SND_EFFECT/L1SP_AUDIO/..
*  ePhoneMode - Phone mode
*  epBuffer   - AFE buffer type
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_GetPathUsage(kal_uint8 u1AudFunc, PHONE_MODE_T ePhoneMode, AFE_BUFFER_T *peBuffer)
{
    ASSERT(peBuffer != NULL);
    ASSERT(ePhoneMode < PHONE_MODE_MAX);

    {
        switch (ePhoneMode)
        {
        case PHONE_MODE_HANDSET:
            if (L1SP_SPEAKER1 & (L1SP_BUFFER_0|L1SP_BUFFER_1))
            {
               *peBuffer =  AFE_BUFFER_VOICE;
            }
            else if (L1SP_SPEAKER1 & L1SP_BUFFER_ST)
            {
                *peBuffer =  AFE_BUFFER_AUDIO;
            }
            else
            {
                *peBuffer = AFE_BUFFER_NONE;
            }
            break;
        case PHONE_MODE_HEADSET:
            if (L1SP_SPEAKER2 & (L1SP_BUFFER_0|L1SP_BUFFER_1))
            {
               *peBuffer =  AFE_BUFFER_VOICE;
            }
            else if (L1SP_SPEAKER2 & L1SP_BUFFER_ST)
            {
                *peBuffer =  AFE_BUFFER_AUDIO;
            }
            else
            {
                *peBuffer = AFE_BUFFER_NONE;
            }
            break;
        case PHONE_MODE_HANDFREE:
            if (L1SP_LOUD_SPEAKER & (L1SP_BUFFER_0|L1SP_BUFFER_1))
            {
               *peBuffer =  AFE_BUFFER_VOICE;
            }
            else if (L1SP_LOUD_SPEAKER & L1SP_BUFFER_ST)
            {
                *peBuffer =  AFE_BUFFER_AUDIO;
            }
            else
            {
                *peBuffer = AFE_BUFFER_NONE;
            }
            break;
        case PHONE_MODE_BT_EARPHONE:
            *peBuffer = AFE_BUFFER_NONE;
            break;
        default:
            break;

        }
    }
}

/*****************************************************************************
* FUNCTION
*  AFE_GetPGAGainInfo
* DESCRIPTION
*  Get PGA gain information
*
* PARAMETERS
*  eBuffer       - AFE buffer type
*  pi2MaxGain    - Maximum gain in dB (ex. 22 means +22dB)
*  pu2Step       - Gain step in dB (ex. 2 means +2dB)
*  pu2TotalLevel - Totoal gain level (ex. 16 means there are 16 levels could 
*                  be applied)
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_GetPGAGainInfo(AFE_BUFFER_T eBuffer, kal_int16 *pi2MaxGain, 
                        kal_uint16 *pu2Step, kal_uint16 *pu2TotalLevel)
{

    ASSERT((pi2MaxGain != NULL) && (pu2Step != NULL) && (pu2TotalLevel != NULL));
    ASSERT(eBuffer < AFE_BUFFER_MAX);

   *pu2TotalLevel = 41;
    
    switch(eBuffer)
    {
      case AFE_BUFFER_NONE:
         *pi2MaxGain = 0;
         *pu2Step = 0;
         break;
      case AFE_BUFFER_AUDIO:
         *pi2MaxGain = 8;
         *pu2Step = 1;
         break;
      case AFE_BUFFER_VOICE:
         *pi2MaxGain = 8;
         *pu2Step = 1;
         break;
      case AFE_BUFFER_MIC:
         *pi2MaxGain = 48;
         *pu2Step = 2;
         *pu2TotalLevel = 32;
         break;
      default:
         break;
    }
}


/*****************************************************************************
* FUNCTION
*  AFE_GetNVRAMDigitalGainSupport
* DESCRIPTION
*  This function return if support digital setting from NVRAM data
*
* PARAMETERS
*  None
* RETURNS
*  KAL_TRUE   - Support digital gain
*  KAL_FALSE  - Not support digital gain
* CALLER
*  Task
*****************************************************************************/
kal_bool AFE_GetNVRAMDigitalGainSupport(void)
{
#ifdef __NVRAM_AFE_DIGITAL_GAIN_SUPPORT__
   return KAL_TRUE;
#else
   return KAL_FALSE;
#endif
}

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                         AFE Gain Related Interface Functions
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
//=============================================================================================
//                  Output Volume Releated Functions
//=============================================================================================
void AFE_SetOutputVolume( kal_uint8 aud_func, kal_uint8 volume1, kal_int8 digital_gain_index )
{  
   kal_uint8 digital_gain_index1 = digital_gain_index;
   kal_uint8 volume = volume1;

   afe.aud[aud_func].volume = volume;
   afe.aud[aud_func].digital_gain_index = digital_gain_index1;
   afe.aud[aud_func].digital_gain = _converted_digital_gain(digital_gain_index1);

#if defined(EXT_DAC_SUPPORT) 
   // Note : extrenal DAC is used as earphone or TV-out only 
   // case 1 : play amr with melody volume (7-level case)  
   if(aud_func == L1SP_VOICE && (afe.aud[L1SP_VOICE].out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1)))
   {
      kal_uint32 i, type;
      if(!(afe.aud[L1SP_VOICE].out_dev & L1SP_BUFFER_EXT) && (volume1 != 0)) // for play both case : apply AFE gain is OK 
      {
      #if defined(TV_OUT_SUPPORT)   
         if(audio_tv_cable_in)
            type = AUD_VOLUME_TVO;
         else 
      #endif    
            type = AUD_VOLUME_MEDIA;    
         for(i = 0 ; i < AUD_MAX_VOLUME_LEVEL ; i ++)
         {
            // find the closest level
            if(aud_get_volume_gain(VOL_HEADSET, type, i) > volume1) 
               break;
         }
         if(i > 0) i--;
         afe.aud[aud_func].volume = aud_get_volume_gain(VOL_HEADSET, AUD_VOLUME_SPH, i); // apply speech volume       
      }    
   }
   
   // case 2 : play Audio both on earphone and LoudSpk 
   if(aud_func == L1SP_AUDIO && (afe.aud[L1SP_AUDIO].out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1)))
   {
      if((afe.aud[L1SP_AUDIO].out_dev & L1SP_BUFFER_EXT) && (volume1 != 0)) // play both 
      {
         kal_uint32 i, type;
         for(i = 0 ; i < AUD_MAX_VOLUME_LEVEL ; i ++)
         {              
            //  find the closest level 
            if(aud_get_volume_gain(VOL_NORMAL, AUD_VOLUME_MEDIA, i) > volume1)
               break;            
         }          
         if(i > 0) i--;
      #if defined(TV_OUT_SUPPORT)            
         if(audio_tv_cable_in)
            type = AUD_VOLUME_TVO;
         else 
      #endif    
            type = AUD_VOLUME_MEDIA;    
         afe.ext_dac_aud_vol = aud_get_volume_gain(VOL_HEADSET, type, i);         
      }
      else 
         afe.ext_dac_aud_vol = volume1;  
   }
   
   if(afe.ext_dac_i2s_on)
   { 
      if(((SND_SRC_MAP>>aud_func*2)&3) == SRC_AUDIO_DAC) 
      {            
         EXT_DAC_SetVolume(afe.aud[aud_func].out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1), afe.ext_dac_aud_vol);  
      }
   }
#endif
   
   AFE_SetRefresh();
   if(kal_if_hisr())
      kal_dev_trace(TRACE_STATE, AFE_SET_OUTPUT_VOLUME, aud_func, volume1, digital_gain_index);
   else
      kal_brief_trace(TRACE_STATE, AFE_SET_OUTPUT_VOLUME, aud_func, volume1, digital_gain_index);
}

/*****************************************************************************
* FUNCTION
*  AFE_SetLevelVolume
* DESCRIPTION
*   This function is to set the proper analog gain and digital gain 
*   based on a MaxAnalogGain and the desired (step * 0.5* level)dB attenuation. 
* 
* PARAMETERS
*  aud_func - the audio function
*  MaxAnalogGain - the maximum volume without any attenuation 
*  step - attenuation step quantity , 0.5dB unit   
*  level - the multiplier of attenuation step; 
*          so the total attenuation is (step * 0.5* level)dB  
*
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void AFE_SetLevelVolume(kal_uint8 aud_func, kal_uint8 MaxAnalogGain, kal_uint8 step, kal_uint8 level)
{
   uint8 vol_step, vol_step_unit;
   uint8 a_gain, a_atten, d_atten;
   
   kal_trace(TRACE_STATE, AFE_SET_LEVEL_VOLUME, aud_func, MaxAnalogGain, step, level);
#if defined(EXT_DAC_SUPPORT)  
   {
      uint8 out_dev;
      out_dev = afe.aud[aud_func].out_dev; 
      // Note : extrenal DAC is used as earphone or TV-out only 
      // case 1 : play amr with melody volume (7-level case)  
      if(aud_func == L1SP_VOICE && (out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1)))
      {
         if(!(out_dev & L1SP_BUFFER_EXT)) // for play both case : apply AFE gain is OK 
         {
            // use AFE gain 
            aud_get_melody_volume_setting(VOL_NORMAL, &MaxAnalogGain, &step);
         }
      }

      // case 2 : play Audio both on earphone and LoudSpk 
      if(aud_func == L1SP_AUDIO && (out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1)))
      {
         uint8 ext_dac_max_vol, ext_dac_step;
         if(afe.aud[L1SP_AUDIO].out_dev & L1SP_BUFFER_EXT) // play both 
         {
         #if defined(TV_OUT_SUPPORT)
            if(audio_tv_cable_in)
               aud_get_melody_volume_setting(VOL_TV_OUT, &ext_dac_max_vol, &ext_dac_step);
            else 
         #endif    
               aud_get_melody_volume_setting(VOL_HEADSET,&ext_dac_max_vol, &ext_dac_step);
         }
         else 
         {
            ext_dac_max_vol = MaxAnalogGain;  
            ext_dac_step = step;
         }
         a_gain = ext_dac_max_vol / L1SP_EXT_DAC_STEP;

         a_atten = (ext_dac_step * level) / L1SP_EXT_DAC_STEP_UNIT; 
         d_atten = (ext_dac_step * level) % L1SP_EXT_DAC_STEP_UNIT; 
         ASSERT(d_atten == 0); // For current EXT_DAC interface, this must be 0.
         
         if(a_gain >= a_atten)  
            a_gain -= a_atten;
         else 
         {
            a_atten -= a_gain;
            a_gain = 0;
            d_atten += a_atten * L1SP_EXT_DAC_STEP_UNIT;
            if(d_atten > 128)
               d_atten = 128;
         }
         afe.ext_dac_aud_vol = a_gain * L1SP_EXT_DAC_STEP;  

         if(afe.ext_dac_i2s_on)                        
            EXT_DAC_SetVolume(out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1), afe.ext_dac_aud_vol);
      }
   }
#endif 

   vol_step = 4;   
   vol_step_unit = 2; // 1dB = 2 * 0.5dB
   
   a_gain = MaxAnalogGain / vol_step;

   a_atten = (step * level) / vol_step_unit; 
   d_atten = (step * level) % vol_step_unit; 

   if(a_gain >= a_atten)  
      a_gain -= a_atten;
   else 
   {
      a_atten -= a_gain;
      a_gain = 0;
      d_atten += a_atten * vol_step_unit;
      if(d_atten > 128)
         d_atten = 128;
   }

   afe.aud[aud_func].volume = a_gain * vol_step + 1; // plus 1 to avoid volume == 0 (this will turn off speaker) 
   afe.aud[aud_func].digital_gain_index = 0 - d_atten; 
   afe.aud[aud_func].digital_gain = _converted_digital_gain( 0-d_atten);       

   //if( (afe.aud[aud_func].out_dev & (L1SP_BUFFER_0|L1SP_BUFFER_1)) || (afe.aud[aud_func].out_dev & (L1SP_BUFFER_ST|L1SP_BUFFER_EXT)) ) //Use digital gain to compesate the analog gain
   {
      kal_int8 digital_gain_index;
      kal_uint8 volume;

      volume = afe.aud[aud_func].volume;
      digital_gain_index = afe.aud[aud_func].digital_gain_index;
       
      if(volume<68) //lower bound is 68
      { 
         kal_int16 tmp_gain_index;
         tmp_gain_index = (kal_int16)digital_gain_index;
         tmp_gain_index -= (((68-volume)>>2)<<1);
   
         if(tmp_gain_index>-128)
            digital_gain_index = (kal_int8)tmp_gain_index;
         else
            digital_gain_index = -128;
   
         afe.aud[aud_func].volume = volume;
         afe.aud[aud_func].digital_gain_index = digital_gain_index;
         afe.aud[aud_func].digital_gain = _converted_digital_gain(digital_gain_index);
       }
   }

   AFE_SetRefresh();
}  

void  AFE_GetOutputVolume( kal_uint8 aud_func, kal_uint8 *volume1, kal_int8 *digital_gain_index )
{
   *volume1 = afe.aud[aud_func].volume;
   *digital_gain_index = afe.aud[aud_func].digital_gain_index;
}

/*****************************************************************************
* FUNCTION
*  AFE_Mute
* DESCRIPTION
*   This function is to mute both microphone and speaker.
*
* PARAMETERS
*  mute - true : mute ; false : unmute ¡@¡@
* RETURNS
*  None
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void AFE_Mute( kal_bool mute )
{
   afe.mute = mute;
   AFE_SetRefresh();
}

void AFE_MuteSpeaker( kal_uint8 aud_func, kal_bool mute )
{
   afe.aud[aud_func].mute = mute;
   kal_trace(TRACE_STATE, AFE_MUTE_SPEAKER, aud_func, mute);
   AFE_SetRefresh();
}

//=============================================================================================
//                  Digital Gain Level Functions
//=============================================================================================
void AFE_SetDigitalGain( kal_uint8 aud_func, kal_uint8 level )
{
   ASSERT(level<=100);
   kal_trace(TRACE_STATE, AFE_SET_GIDI_GAIN, aud_func, level);
#if defined(__BT_SUPPORT__)
   if(AM_IsBluetoothOn()) {
      /// for the case of bluetooth use 
      return;
   }
#endif
   afe.aud[aud_func].digital_gain_level = level;
#if defined(EXT_DAC_SUPPORT)
   if( aud_func == L1SP_AUDIO )
      afe.ext_dac_level_gain = ((kal_uint32)level * 0x8000) / 100;
#endif
   AFE_SetRefresh();
}

kal_uint16 AFE_GetDigiGain()
{
   kal_uint16 gain;
   //only return voice digital gain   
   gain = afe.v_digi_gain;
   gain = ( gain >= 0x1000 )? 0x7FFF : (gain << 3);
   
   return gain;
}

//=============================================================================================
//                  Microphone Gain Functions
//=============================================================================================
/*****************************************************************************
* FUNCTION
*  AFE_MuteMicrophone
* DESCRIPTION
*   This function is to mute the microphone.
*
* PARAMETERS
*  mute - true : mute ; false : unmute ¡@¡@
* RETURNS
*  None
* GLOBALS AFFECTED
*  None
*****************************************************************************/
void AFE_SetMicrophoneVolume( kal_uint8 mic_volume )
{
   afe.mic_volume = mic_volume >> 2; /* Totally 6 bits for VUPG control */
   AFE_SetRefresh();
   ASSERT(!kal_if_hisr());
   kal_brief_trace(TRACE_STATE, AFE_SET_MIC_VOLUME, mic_volume);
}

kal_uint8 AFE_GetMicrophoneVolume( void )
{
   return afe.mic_volume << 2;  /* Totally 6 bits for VUPG control */
}

void AFE_MuteMicrophone( kal_bool mute )
{
   afe.mic_mute = mute;
   AFE_SetRefresh();
}

kal_bool AFE_IsMicrophoneMuted( void )
{
   return afe.mic_mute;
}

//=============================================================================================
//                  Sidetone Gain Functions
//=============================================================================================
void AFE_SetSidetoneVolume( kal_uint8 sidetone_volume )
{
   afe.sidetone_volume   = sidetone_volume;

   AFE_SetRefresh();
   ASSERT(!kal_if_hisr());
   kal_brief_trace(TRACE_STATE, AFE_SET_SIDETONE_VOLUME, sidetone_volume);
}

kal_uint8 AFE_GetSidetoneVolume( void )
{
   return afe.sidetone_volume;
}

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        AFE Feature Specific Interface Functions
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  __GAIN_TABLE_SUPPORT__ Specific Functions
//=============================================================================================
#if defined(__GAIN_TABLE_SUPPORT__)
/*****************************************************************************
* FUNCTION
*  AFE_SetOutputGainControl
* DESCRIPTION
*  This function set detail gain value to internal analog gain, digital gain, external amp gain
*
* PARAMETERS
*  aud_func    - audio function
*  total_gain  - containes analog gain[26:31](6 bits), digital gain[18:25](8 bits), external amp gain[0:17](18bits)
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_SetOutputGainControl(uint8 aud_func, uint32 total_gain)
{
   kal_uint16 digi_gain;
   kal_uint8 gain_index;
   afe.aud[aud_func].total_gain = total_gain;
   afe.aud[aud_func].volume = (uint8)( (0x3F - (total_gain >> 26)) << 2);
   gain_index = (kal_uint8)((total_gain << 6) >> 24);

   { 
      kal_uint8 digital_gain_index;
      kal_uint8 volume;

      volume = afe.aud[aud_func].volume;
      digital_gain_index = gain_index;
       
      if(volume<68) //lower bound is 68
      { 
         kal_uint16 tmp_gain_index;
         tmp_gain_index = (kal_uint16)digital_gain_index;
         tmp_gain_index += (((68-volume)>>2)<<2); //unit is 0.25db
   
         if(tmp_gain_index<256)
            digital_gain_index = (kal_uint8)tmp_gain_index;
         else
            digital_gain_index = 255;

         gain_index = digital_gain_index;
      }
   }
   
   digi_gain = digital_gain_4db_table[gain_index >> 4];// * digital_gain_quadb_table[gain_index & 0xF];
   if((gain_index & 0xF) > 0){
      digi_gain = ((kal_uint32)digi_gain * digital_gain_table[(gain_index&0x0F)]) >> 15;
   }
   afe.aud[aud_func].digital_gain = digi_gain;
   //kal_prompt_trace(MOD_L1SP, "afe set gain control func %d dev %x sp_flag %x",aud_func, afe.aud[aud_func].out_dev, afe.sp_flag);
   //kal_prompt_trace(MOD_L1SP, "AFE set func %d gain_ctrl Ana %d Dig %d(%d) Ext %x", aud_func, total_gain >> 26, gain_index, digi_gain, total_gain & 0x3FFFF);
   kal_trace(TRACE_STATE, AFE_SET_OUTPUT_GAIN_CONTROL, aud_func, total_gain >> 26, gain_index, digi_gain, total_gain & 0x3FFFF);
   AFE_SetRefresh();
}

/*****************************************************************************
* FUNCTION
*  AFE_SetMicGainControl
* DESCRIPTION
*  This function set detail gain value to mic :internal analog gain, digital gain, external device gain
*
* PARAMETERS
*  mic_gain  - containes analog gain[26:31], digital gain[18:25], external amp gain[0:17]
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_SetMicGainControl(uint32 total_gain)
{
   kal_uint16 digi_gain;
   kal_uint8 gain_index;
   afe.mic_total_gain = total_gain;
   afe.mic_volume = (uint8)(total_gain >> 26);

   gain_index = (kal_uint8)((total_gain << 6) >> 24);
   digi_gain = digital_gain_4db_table[gain_index >> 4];// * digital_gain_quadb_table[gain_index & 0xF];
   if((gain_index & 0xF) > 0){
      digi_gain = ((kal_uint32)digi_gain * digital_gain_table[(gain_index&0x0F)]) >> 15;
   }
   afe.mic_digi_gain = ( digi_gain * DG_Microphone ) >> 15; 
   L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_UL_VOLUME, afe.mic_digi_gain, 128 );
   kal_trace(TRACE_STATE, AFE_SET_MIC_GAIN_CONTROL, total_gain >> 26, gain_index, digi_gain );
   AFE_SetRefresh();
}


/*****************************************************************************
* FUNCTION
*  AFE_GetAllPathUsage
* DESCRIPTION
*  This function is to get current AFE buffer usage in each mode
*
* PARAMETERS
*  u1AudFunc[in]  - AUD_VOLUME_CTN = 0, tone
*   AUD_VOLUME_KEY,              1: keytone 
*   AUD_VOLUME_MIC,              2: microphone 
*   AUD_VOLUME_FMR,              3: FM Radio 
*   AUD_VOLUME_SPH,              4: Speech 
*   AUD_VOLUME_SID,              5: Side-tone 
*   AUD_VOLUME_MEDIA,            6: Multi-Media 
*   AUD_VOLUME_TVO,              7: TV-OUT 
*
*  u1Path[in] -  AUD_PATH_RECEIVER,          -speaker
*                AUD_PATH_HEADSET,           -Headset
*                AUD_PATH_SPEAKER,           -Loudspeaker
*                AUD_DUAL                    -headset and loudspeaker
*
*  epBuffer[out]   - AFE buffer type
*  pu2TotalLevel[out] - total level number of epBuffer
*  digigain[out]   - true: support digital gain
*                    false: not support
*  ext_dac[out]    - NULL
*                    L1SP_EXT_DAC_BUF0
*                    L1SP_EXT_DAC_BUF1
*  ctrl_point[out] - numbers of control point of ext_dac
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_GetAllPathUsage(aud_volume_enum u1AudFunc, aud_path_enum u1Path,
                        AFE_BUFFER_T *peBuffer, kal_uint16 *pu2TotalLevel,
                        kal_bool *digital_gain,
                        kal_uint8 *ext_dac, kal_uint16 *ctrl_point)
{
   #define AFE_BUFFER_AUD_GAINLEVEL   45
   #define AFE_BUFFER_VOICE_GAINLEVEL 45
   #define AFE_BUFFER_MIC_GAINLEVEL   64
   if(u1AudFunc == AUD_VOLUME_SID){
      *peBuffer = AFE_BUFFER_NONE;
      *pu2TotalLevel = 0;
      *digital_gain = KAL_FALSE;
      *ctrl_point = 0;
      *ext_dac = 0;
      return;
   }
   switch (u1Path) {
      case AUD_PATH_RECEIVER:
         if(u1AudFunc == AUD_VOLUME_KEY || u1AudFunc == AUD_VOLUME_CTN || u1AudFunc == AUD_VOLUME_SPH){
            *peBuffer = AFE_BUFFER_VOICE;
            *pu2TotalLevel = AFE_BUFFER_VOICE_GAINLEVEL;
            *digital_gain = KAL_TRUE;

         } else  if (u1AudFunc == AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_MIC;
            *pu2TotalLevel = AFE_BUFFER_MIC_GAINLEVEL;
            *digital_gain = KAL_TRUE;
         }
         else{
            *peBuffer = AFE_BUFFER_NONE;
            *pu2TotalLevel = 0;
            *digital_gain = KAL_FALSE;
         }
         *ext_dac = 0;
         *ctrl_point = 0;
         break;      

      case AUD_PATH_HEADSET:
      case AUD_PATH_DUAL:
#if defined(LG_EXT_AMP_SUPPORT)
         if(u1AudFunc == AUD_VOLUME_SPH || u1AudFunc == AUD_VOLUME_CTN){
            *peBuffer = AFE_BUFFER_VOICE;
            *pu2TotalLevel = AFE_BUFFER_VOICE_GAINLEVEL;
            *digital_gain = KAL_TRUE;
            *ctrl_point = EXT_DAC_Volume_Ctrl_Point(u1AudFunc,u1Path);
            if(*ctrl_point > 0)
               *ext_dac = L1SP_SPEAKER2 & (L1SP_EXT_DAC_BUF0 | L1SP_EXT_DAC_BUF1);
         } else
#endif
         if(u1AudFunc != AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_AUDIO;
            *pu2TotalLevel = AFE_BUFFER_AUD_GAINLEVEL;
            if(u1AudFunc != AUD_VOLUME_FMR)
               *digital_gain = KAL_TRUE;
            else
               *digital_gain = KAL_FALSE;
#if defined(LG_EXT_AMP_SUPPORT)
            *ctrl_point = EXT_DAC_Volume_Ctrl_Point(u1AudFunc,u1Path);
#else
            *ctrl_point = 0;
#endif
            if(*ctrl_point > 0)
               *ext_dac = L1SP_SPEAKER2 & (L1SP_EXT_DAC_BUF0 | L1SP_EXT_DAC_BUF1);
         } else if (u1AudFunc == AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_MIC;
            *pu2TotalLevel = AFE_BUFFER_MIC_GAINLEVEL;
            *digital_gain = KAL_TRUE;
            *ctrl_point = 0;
            *ext_dac = 0;
         }
         break;              
      case AUD_PATH_SPEAKER:
#if defined(LG_EXT_AMP_SUPPORT)
         if(u1AudFunc == AUD_VOLUME_SPH  || u1AudFunc == AUD_VOLUME_CTN){
            *peBuffer = AFE_BUFFER_VOICE;
            *pu2TotalLevel = AFE_BUFFER_VOICE_GAINLEVEL;
            *digital_gain = KAL_TRUE;
            *ctrl_point = EXT_DAC_Volume_Ctrl_Point(u1AudFunc,u1Path);
            if(*ctrl_point > 0)
               *ext_dac = L1SP_LOUD_SPEAKER & (L1SP_EXT_DAC_BUF0 | L1SP_EXT_DAC_BUF1);
         } else
#endif
         if(u1AudFunc != AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_AUDIO;
            *pu2TotalLevel = AFE_BUFFER_AUD_GAINLEVEL;
            if(u1AudFunc != AUD_VOLUME_FMR)
               *digital_gain = KAL_TRUE;
            else
               *digital_gain = KAL_FALSE;
#if defined(LG_EXT_AMP_SUPPORT)
            *ctrl_point = EXT_DAC_Volume_Ctrl_Point(u1AudFunc,u1Path);
#else
            *ctrl_point = 0;
#endif
            if(*ctrl_point > 0)
               *ext_dac = L1SP_LOUD_SPEAKER & (L1SP_EXT_DAC_BUF0 | L1SP_EXT_DAC_BUF1);
         } else if (u1AudFunc == AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_MIC;
            *pu2TotalLevel = AFE_BUFFER_MIC_GAINLEVEL;
            *digital_gain = KAL_TRUE;
            *ctrl_point = 0;
            *ext_dac = 0;
         }
         break;
      case AUD_PATH_BT:
         if(u1AudFunc != AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_NONE;
            *pu2TotalLevel = 0;
            *digital_gain = KAL_TRUE;
            *ctrl_point = 0;
            *ext_dac = 0;
         } else if (u1AudFunc == AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_NONE;
            *pu2TotalLevel = 0;
            *digital_gain = KAL_TRUE;
            *ctrl_point = 0;
            *ext_dac = 0;
         }
         break;         
      case AUD_PATH_UNKNOWN:
         //only for FM microphone setting
         if(u1AudFunc == AUD_VOLUME_MIC){
            *peBuffer = AFE_BUFFER_MIC;
            *pu2TotalLevel = AFE_BUFFER_MIC_GAINLEVEL;
            *digital_gain = KAL_TRUE;
            *ctrl_point = 0;
            *ext_dac = 0;
         }
         break;
      default:
         ASSERT(0);
   }
}

/*****************************************************************************
* FUNCTION
*  AFE_GetExtPGAInfo
* DESCRIPTION
*  This function is to get info of external DAC or AMP
*
* PARAMETERS
*  ext_dac[in] - L1SP_EXT_DAC_BUF0
*                L1SP_EXT_DAC_BUF1
*  ctrl_point[in]   - index of control pointer 0~
*  total_level[out] - numbers of level of this ext_dac
*  bit_number[out]  - numbers of bits of this ext_dac
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_GetExtPGAInfo(kal_uint8 ext_dac, kal_uint16 ctrl_point, kal_uint8* total_level, kal_uint8* bit_number)
{
#if defined(LG_EXT_AMP_SUPPORT)
   EXT_DAC_GetCtrlPointBitLevel(ext_dac, ctrl_point, total_level, bit_number);
#else
   total_level = 0;
   bit_number = 0;
#endif
}

/*****************************************************************************
* FUNCTION
*  AFE_GetExtPGAInfo
* DESCRIPTION
*  This function is to get info of external DAC or AMP
*
* PARAMETERS
*  ext_dac[in] - L1SP_EXT_DAC_BUF0
*                L1SP_EXT_DAC_BUF1
*  ctrl_point[in]   - index of control pointer 0~
*  total_level[in]  - numbers of level of this ext_dac to be copied
*  gain_map[out]    - the array to store actual gain of this control_point, ex:gain_map[0]=-65, gain_map[1]=-55
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_GetExtPGAGainMap(kal_uint8 ext_dac, kal_uint16 ctrl_point, kal_uint8 total_level, kal_int8* gain_map)
{
#if defined(LG_EXT_AMP_SUPPORT)
   EXT_DAC_GetCtrlPointGainMap(ext_dac, ctrl_point, gain_map);
#endif
}

/*****************************************************************************
* FUNCTION
*  AFE_GetPGAGainMap
* DESCRIPTION
*  This function is to get gain map of AFE buffer
*
* PARAMETERS
*  eBuffer[in] - AFE buffer type
*  u2TotalLevel[in] - numbers of level of this afe_buffer to be copied
*  gain_map[out]    - the array to store actual gain of AFE buffer
* RETURNS
*  None
* CALLER
*  Task
*****************************************************************************/
void AFE_GetPGAGainMap(AFE_BUFFER_T eBuffer, kal_uint16 u2TotalLevel, kal_int8 *pPGA_Map)
{
   kal_uint32 i = 0;
   switch (eBuffer) {
      case AFE_BUFFER_AUDIO:
         for( i = 0 ; i < u2TotalLevel ; i++ )
            pPGA_Map[i] = 12 - i ;
         break;
      case AFE_BUFFER_VOICE:
         for( i = 0 ; i < u2TotalLevel ; i++ )
            pPGA_Map[i] = 12 - i;
         break;
      case AFE_BUFFER_MIC:
         for( i = 0 ; i < u2TotalLevel ; i++ )
            pPGA_Map[i] = -14 + i;
         break;
      default:
         break;
   }
}

/*****************************************************************************
* FUNCTION
*  AFE_GetOutputGainControl
* DESCRIPTION
*  This function get detail gain value to internal analog gain, digital gain, external amp gain
*
* PARAMETERS
*  aud_func    - audio function
* RETURNS
*  total_gain  - containes analog gain[26:31](6 bits), digital gain[18:25](8 bits), external amp gain[0:17](18bits)
* CALLER
*  Task
*****************************************************************************/
kal_uint32 AFE_GetOutputGainControl(kal_uint8 aud_func)
{
   return afe.aud[aud_func].total_gain;
}

void AFE_SetOutputGainControlDualPath( kal_uint8 aud_func, kal_uint32 ext_amp_gain )
{
#if defined(LG_EXT_AMP_SUPPORT) 
   afe.dual_path_loud_spk_gain = (ext_amp_gain & 0x3FFFF);
   kal_trace(TRACE_STATE, AFE_SET_DUAL_PATH_GAIN, afe.dual_path_loud_spk_gain);
#endif
}

#endif // __GAIN_TABLE_SUPPORT__

//=============================================================================================
//                  ABB Registers Backup/Store (for 65nm projects)
//=============================================================================================
void AFE_RegisterBackup(void)
{
}

void AFE_RegisterStore(void)
{
}

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        AFE Event Handler 
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
static void AFE_Switch_VoiceDAC_VoiceAMP(kal_int16 v_lowest, kal_int16 a_lowest)
{
  #if defined(MT6575) || defined(MT6577)
   if( (*AUDIO_CON3&0x1f0) != 0x0160 )
  #else
   if( (*AUDIO_CON3&0x1f0) != 0x0140 )
  #endif
   {
   #if defined(MT6575) || defined(MT6577)
      *AUDIO_CON0 = 0x4203;
   #else
      *AUDIO_CON0 = 0x4303;
   #endif
      if(v_lowest==L1SP_SPEECH)
      {
         L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_DISABLE_SIDETONE, 0, 0 ); 
         L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_SIDETONE, 0, (kal_uint32)NULL ); 
      }
   #if defined(MT6575) || defined(MT6577)
      *AUDIO_CON1 = (*AUDIO_CON1 & ~0x003f) | 0x002c;
      *AUDIO_CON5 = 0x2000;
      *AUDIO_CON3 = 0x160;
      AFE_AUDIO_CON9_CTRL();
      *AUDIO_CON5 = 0x4400;
   #elif defined(MT6573)
      *AUDIO_CON1 |= 0x3F00;
      *AUDIO_CON5 = 0x2000;
      *AUDIO_CON3 = 0x140;
      AFE_AUDIO_CON9_CTRL();
      *AUDIO_CON5 = 0x4000; // select HSMUX as DAC
   #endif

      if(v_lowest==L1SP_SPEECH)
      {
         SGPT_CTRL_START_T start;
         if(afe.tune_gain_gpt_on==KAL_TRUE)
         {
            DclSGPT_Control( afe.tune_gain_gpt, SGPT_CMD_STOP, 0);
            afe.tune_gain_gpt_on = KAL_FALSE;
         }
         start.u2Tick = 23; //230ms
         start.pfCallback = Tune_Gain_On;
         start.vPara = 0;
         DclSGPT_Control(afe.tune_gain_gpt, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start); 
         afe.tune_gain_gpt_on = KAL_TRUE;
         afe.tune_gain_ctrl = 50;
         afe.tune_gain_ctrl_enable = KAL_FALSE;
      }
      else
      {
         afe.tune_gain_ctrl = 0;
         afe.tune_gain_ctrl_enable = KAL_TRUE;
      }

      afe.afe_OnOff = KAL_TRUE;
   }

 #if defined(MT6575) || defined(MT6577)
   if( (*AUDIO_CON5&0x4400) != 0x4400 ) 
 #elif defined(MT6573)
   if( (*AUDIO_CON5&0x4000) != 0x4000 )
 #endif
   {
      *AUDIO_CON5 = 0x4000;
   }
}

static void AFE_Switch_AudDAC_VoiceAMP(kal_int16 v_lowest, kal_int16 a_lowest)
{
  #if defined(MT6575) || defined(MT6577)
   if( (*AUDIO_CON3&0x1f0) != 0x0160 )
  #else
   if( (*AUDIO_CON3&0x1f0) != 0x0140 )
  #endif
   {
   #if defined(MT6575) || defined(MT6577)
      *AUDIO_CON0 = 0x4203;
   #else
      *AUDIO_CON0 = 0x4303;
   #endif
      if(v_lowest==L1SP_SPEECH)
      {
         L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_DISABLE_SIDETONE, 0, 0 ); 
         L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_SIDETONE, 0, (kal_uint32)NULL ); 
      }
   #if defined(MT6575) || defined(MT6577)
      *AUDIO_CON1 = (*AUDIO_CON1 & ~0x003f) | 0x002c;
      *AUDIO_CON5 = 0x2000;
      *AUDIO_CON3 = 0x160;
      AFE_AUDIO_CON9_CTRL();
      *AUDIO_CON5 = 0x4400;
   #elif defined(MT6573)
      *AUDIO_CON1 |= 0x3F00;
      *AUDIO_CON5 = 0x2000;
      *AUDIO_CON3 = 0x140;
      AFE_AUDIO_CON9_CTRL();
      *AUDIO_CON5 = 0x4000; // select HSMUX as DAC
   #endif

      if(v_lowest==L1SP_SPEECH)
      {
         SGPT_CTRL_START_T start;
         if(afe.tune_gain_gpt_on==KAL_TRUE)
         {
            DclSGPT_Control( afe.tune_gain_gpt, SGPT_CMD_STOP, 0);
            afe.tune_gain_gpt_on = KAL_FALSE;
         }
         start.u2Tick = 23; //230ms
         start.pfCallback = Tune_Gain_On;
         start.vPara = 0;
         DclSGPT_Control(afe.tune_gain_gpt, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start); 
         afe.tune_gain_gpt_on = KAL_TRUE;
         afe.tune_gain_ctrl = 50;
         afe.tune_gain_ctrl_enable = KAL_FALSE;
      }
      else
      {
         afe.tune_gain_ctrl = 0;
         afe.tune_gain_ctrl_enable = KAL_TRUE;
      }

      afe.afe_OnOff = KAL_TRUE;
   }

 #if defined(MT6575) || defined(MT6577)
   if( (*AUDIO_CON5&0x4400) != 0x4400 ) 
 #elif defined(MT6573)
   if( (*AUDIO_CON5&0x4000) != 0x4000 )
 #endif
   {
      *AUDIO_CON5 = 0x4000;
   }
}

static void AFE_Switch_ExtDAC_VoiceAMP(kal_int16 v_lowest, kal_int16 a_lowest)
{
   AFE_AUDIO_CON9_CTRL();
   *AUDIO_CON3 &= ~0x2; // Enable Aud Bias
   /// Voice-Amp1 does not need input from audio DAC,
   /// also Audio Amp is not used, turn them off.
   if( a_lowest < 0 ){
      *AUDIO_CON3 &= ~0x330; // turn off audio Buffer an DAC
   }
}

static void AFE_Switch_VoiceDAC_AudAMP(kal_int16 v_lowest, kal_int16 a_lowest)
{
   if( (*AUDIO_CON3&0x1f0) != 0x01b0 )
   {
      *AUDIO_CON0 = 0x4203; 
      audio_con1_bk = *AUDIO_CON1;  
      audio_con2_bk = *AUDIO_CON2;
      if(a_lowest==L1SP_SPEECH)
      {
         L1Audio_PutMessage(MSG_L1AUDIO2FAS_SPEECH_DISABLE_SIDETONE, 0, 0 ); 
         L1Audio_PutMessage( MSG_L1AUDIO2FAS_SPEECH_SET_SIDETONE, 0, (kal_uint32)NULL ); 
      } 
   #if defined(MT6575) || defined(MT6577)
      *AUDIO_CON1 = (*AUDIO_CON1 & ~0x003f) | 0x002c;
      *AUDIO_CON2 = 0x002c;
   #else
      *AUDIO_CON1 = 0x3f3f;
      *AUDIO_CON2 = 0x003f;
   #endif
      *AUDIO_CON5 = 0x2000;
      *AUDIO_CON3 = 0x0040;
      *AUDIO_CON8 = 0x7010;
   #if defined(MT6575) || defined(MT6577)
      *AUDIO_CON17 |= 0x1000;
   #endif
      *AUDIO_CON5 = 0x2220;
      AFE_DELAY(30);
      *AUDIO_CON3 = 0x01f0;
      *AUDIO_CON8 = 0x7000;
   #if defined(MT6575) || defined(MT6577)
      *AUDIO_CON17 &= ~0x1000;
   #endif
      *AUDIO_CON3 = 0x01b0;
      *AUDIO_CON5 = 0x0220;
      AFE_AUDIO_CON9_CTRL();
     *AUDIO_CON5 = 0x0440;

      if(a_lowest==L1SP_SPEECH)
      {
         SGPT_CTRL_START_T start;
         if(afe.tune_gain_gpt_on==KAL_TRUE)
         {
            DclSGPT_Control( afe.tune_gain_gpt, SGPT_CMD_STOP, 0);
            afe.tune_gain_gpt_on = KAL_FALSE;
         }
         start.u2Tick = 23; //230ms
         start.pfCallback = Tune_Gain_On;
         start.vPara = 0;
         DclSGPT_Control(afe.tune_gain_gpt, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start); 
         afe.tune_gain_gpt_on = KAL_TRUE;
         afe.tune_gain_ctrl = 50; 
         afe.tune_gain_ctrl_enable = KAL_FALSE;
         afe.tune_gain_ctrl_enable2 = KAL_TRUE;  
      }
      else
      {
         afe.tune_gain_ctrl = 0;
         afe.tune_gain_ctrl_enable = KAL_TRUE;
         afe.tune_gain_ctrl_enable2 = KAL_TRUE;  
      }

      afe.afe_OnOff = KAL_TRUE;
   }

   if(afe.tune_gain_ctrl_enable2)
   {
   #if defined(MT6575) || defined(MT6577)
      if( (*AUDIO_CON1&0xFF)==0x2C )
   #else   
      if( (*AUDIO_CON1&0xFF)==0x3F )
   #endif
      {
         *AUDIO_CON1 = audio_con1_bk; 
      }

   #if defined(MT6575) || defined(MT6577)
      if( (*AUDIO_CON2&0xFF)==0x2C )
   #else  
      if( (*AUDIO_CON2&0xFF)==0x3F )
   #endif
      {
         *AUDIO_CON2 = audio_con2_bk;
      }
      afe.tune_gain_ctrl_enable2 = KAL_FALSE;
   }

   if( (*AUDIO_CON5&0x0440) != 0x0440 )
   {
      *AUDIO_CON5 = 0x0440;
   }
}


static void AFE_Switch_AudDAC_AudAMP(kal_int16 v_lowest, kal_int16 a_lowest)
{
   if( afe.aud[a_lowest].out_dev&L1SP_STEREO2MONO )
   {
      if( (afe.st2mono_flag==KAL_FALSE) || ((afe.st2mono_flag==KAL_TRUE) && (afe.st2mono==KAL_FALSE)) )
         L1Audio_PutMessage( MSG_L1AUDIO2FAS_AUDIO_SET_STEREO2MONO, 1, 0);
      afe.st2mono = KAL_TRUE;
   }
   else
   {
      if( (afe.st2mono_flag==KAL_FALSE) || ((afe.st2mono_flag==KAL_TRUE) && (afe.st2mono==KAL_TRUE)) )
         L1Audio_PutMessage( MSG_L1AUDIO2FAS_AUDIO_SET_STEREO2MONO, 0, 0);
      afe.st2mono = KAL_FALSE;
   }

   afe.st2mono_flag = KAL_TRUE;
         
   if( (*AUDIO_CON3&0x1f0) != 0x01b0 )
   {
   #if !defined(__SMART_PHONE_MODEM__)
    #if defined(MT6575) || defined(MT6577)
      *AUDIO_CON1 = (*AUDIO_CON1 & ~0x003f) | 0x002c;
      *AUDIO_CON2 = 0x002c;
    #else
      *AUDIO_CON1 = 0x3f3f;
      *AUDIO_CON2 = 0x003f;
    #endif
   #endif
      *AUDIO_CON5 = 0x2000;
      *AUDIO_CON3 = 0x0040;
      *AUDIO_CON8 = 0x7010;
   #if defined(MT6575) || defined(MT6577)
      *AUDIO_CON17 |= 0x1000;
   #endif
      *AUDIO_CON5 = 0x2220;
      AFE_DELAY(30);

      *AUDIO_CON3 = 0x01f0;
      *AUDIO_CON8 = 0x7000;
   #if defined(MT6575) || defined(MT6577)
      *AUDIO_CON17 &= ~0x1000;
   #endif
      *AUDIO_CON3 = 0x01b0;
      *AUDIO_CON5 = 0x0220;
      AFE_AUDIO_CON9_CTRL();
      *AUDIO_CON5 = 0x0440;
       AFE_DELAY(10);
   }

   if( (*AUDIO_CON5&0x0440) != 0x0440 )
   {
      *AUDIO_CON5 = 0x0440;
   }
}

static void AFE_Switch_VoiceAmp(kal_int16 v_lowest, kal_int16 a_lowest)
{
   /// If there exists an aud function (v_lowest) which wants to output through
   /// Voice Amp-0 or Voice Amp-1
   afe.Pre_InSrc = (SND_SRC_MAP>>v_lowest*2)&3;
   
   switch(afe.Pre_InSrc) {
      /// determine the source for the aud function v_lowest
      case SRC_VOICE_DAC:
         afe_prompt_trace( MOD_L1SP, "v(%x) a(%x) , SRC_VOICE_DAC ", v_lowest, a_lowest);
         AFE_Switch_VoiceDAC_VoiceAMP(v_lowest, a_lowest);
         break;
      case SRC_AUDIO_DAC:
         afe_prompt_trace( MOD_L1SP, "v(%x) a(%x) , SRC_AUDIO_DAC ", v_lowest, a_lowest);
         AFE_Switch_AudDAC_VoiceAMP(v_lowest, a_lowest);
         break;
      case SRC_EXT_INPUT:
         afe_prompt_trace( MOD_L1SP, "v(%x) a(%x) , SRC_EXT_INPUT ", v_lowest, a_lowest);
         AFE_Switch_ExtDAC_VoiceAMP(v_lowest, a_lowest);
         break;
   }

   AFE_AUDIO_CON9_CTRL();
   UpdateVGain( v_lowest );

   UpdateVAPDN(afe.aud[v_lowest].out_dev);
   kal_trace(TRACE_STATE, AFE_GAIN, *AUDIO_CON1, *AUDIO_CON2, *AUDIO_CON20);
}

static void AFE_Switch_AudAmp(kal_int16 v_lowest, kal_int16 a_lowest)
{
   /// If there is no aud function which wants to output through
   /// Voice Amp-0 or Voice Amp-1. But there is aud function which
   /// wants to output through Audio Amp.
   afe.Pre_InSrc = (SND_SRC_MAP>>a_lowest*2)&3;
      
   switch(afe.Pre_InSrc) {
      case SRC_VOICE_DAC:
         afe_prompt_trace( MOD_L1SP, "v(%x) a(%x) , SRC_VOICE_DAC ", v_lowest, a_lowest);
         AFE_Switch_VoiceDAC_AudAMP(v_lowest, a_lowest);
         break;
      case SRC_AUDIO_DAC:
         afe_prompt_trace( MOD_L1SP, "v(%x) a(%x), SRC_AUDIO_DAC ", v_lowest, a_lowest);
         AFE_Switch_AudDAC_AudAMP(v_lowest, a_lowest);
         break;
      case SRC_EXT_INPUT:
         afe_prompt_trace( MOD_L1SP, "v(%x) a(%x) , SRC_EXT_INPUT ", v_lowest, a_lowest);
         break;
   }
   AFE_AUDIO_CON9_CTRL();
   UpdateAGain( a_lowest );
   /// The turn-on of the audio amplifier should be delayed because the DAC needs some time to stabilize
   UpdateVAPDN( 0); // update Mic only
   if( afe.mic_flag && !afe.mic_mute && !afe.mute) {
   /* Normal recording */
      if( afe.mic_src == L1SP_LNA_FMRR )
         afe.mic_volume = FM_RADIO_RECORDING_VOLUME;
         UpdateMicGain(afe.mic_volume);
   }

   AFE_SetRefVol(KAL_TRUE);

   kal_trace(TRACE_STATE, AFE_GAIN, *AUDIO_CON1, *AUDIO_CON2, *AUDIO_CON20);
}

static void AFE_Switch_No_VoiceAudAmp()
{
   /// If there is no aud function which wants to output through
   /// Voice Amp-0 or Voice Amp-1 or Audio Amp.
   /// Update MIC volume here for the scenario that microphone is turned on with no speaker on 
   if( afe.mic_flag && !afe.mic_mute && !afe.mute) 
   {
      if( afe.mic_src==L1SP_LNA_FMRR ) { /* FM Radio Recording */
         *AUDIO_CON3 = *AUDIO_CON3 | AUD_LSBUF_L_PWUP | AUD_LSBUF_R_PWUP;
         if( afe.mic_src == L1SP_LNA_FMRR )
            afe.mic_volume = FM_RADIO_RECORDING_VOLUME;
         UpdateMicGain(afe.mic_volume);
      }else {
         UpdateMicGain(afe.mic_volume);
      }
   }
   UpdateVAPDN( 0 );

   afe.st2mono_flag = KAL_FALSE;

   if(afe.Audio_close_delay_expired)
   {
      afe.Audio_close_delay_expired = KAL_FALSE;
      if(afe.afe_OnOff)
      {
         if(afe.tune_gain_gpt_on==KAL_TRUE)
         {
            DclSGPT_Control( afe.tune_gain_gpt, SGPT_CMD_STOP, 0);
            afe.tune_gain_gpt_on = KAL_FALSE;
         }
         afe.afe_OnOff = KAL_FALSE;
         afe.tune_gain_ctrl = 0;
         afe.tune_gain_ctrl_enable = KAL_TRUE;

         audio_con1_bk = *AUDIO_CON1;
         audio_con2_bk = *AUDIO_CON2;
         *AUDIO_CON0 = 0x4000; 
         AVolumeRampDown(); 
         *AUDIO_CON5 = 0; //0x2220; //0x0220; 
         *AUDIO_CON9 &= ~0x03; //0; 
         *AUDIO_CON3 &= ~0x1F0;
         *AUDIO_CON0 = 0x4203;
         *AUDIO_CON3 |= 0x2;

         if( (*AUDIO_CON1&0xFF)==0x2C )
         {
            *AUDIO_CON1 = audio_con1_bk; 
         }

         if( (*AUDIO_CON2&0xFF)==0x2C )
         {
            *AUDIO_CON2 = audio_con2_bk; 
         }
      }
   }
}

/* ========================================================================= */
/*   AFE Event Handler                                                       */
/*   This function runs under the context of L1Audio Task                    */
/* ========================================================================= */
static void AFE_Event_Handler( void *data )
{
#if defined(__DATA_CARD_SPEECH__)
   return;
   //Data card don't need open analog device
#endif

 #if defined(MT6573) 
   *PLL_CON2 |= 0x20 ;
 #endif
 #if !defined(__L1_STANDALONE__) && !defined(L1D_TEST)
   AUDSYS_CLR_BIT(AFE_DL_SRC2, DL2_MUTE_CH1_ON);
   AUDSYS_CLR_BIT(AFE_DL_SRC2, DL2_MUTE_CH2_ON);
   AUDSYS_SET_BIT(AFE_DL_SRC1, DL1_SRC_ON);  // Force turn on SDM
 #endif

   ASSERT(!kal_if_hisr()); 

   {
      kal_int16 v_lowest = -1, a_lowest = -1;

      if( afe.sp_flag ) {
         /// v_lowest: the highest priority aud function which outputs through
         ///           Voice Amp-0 or Voice Amp-1
         /// a_lowest: the highest priority aud function which outputs through
         ///           Audio Amp
         SearchSpkFlag( &v_lowest, &a_lowest );
      }
      L1Audio_Msg_AFE_SpkSelect( v_lowest, a_lowest, afe.fir_flag, afe.mic_flag, afe.mic_volume );

   #if defined(EXT_DAC_SUPPORT)
      if(a_lowest != -1 && !afe.ext_dac_mute && (afe.aud[a_lowest].out_dev & (L1SP_EXT_DAC_BUF0 | L1SP_EXT_DAC_BUF1)))
      {
         if(afe.ext_dac_aud_func != a_lowest)
         {
            kal_uint8 out_spk;  
            
            afe.ext_dac_aud_func = a_lowest;                   
            out_spk = afe.aud[a_lowest].out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1);       
            
            switch((SND_SRC_MAP>>a_lowest*2)&3) 
            {            
               case SRC_AUDIO_DAC:
                  EXT_DAC_SetPlaybackFreq(afe.ext_dac_freq);
                  EXT_DAC_TurnOnSpeaker(EXT_DAC_I2S , out_spk );    
                  AFE_TurnOnEDI(0, 1, L1SP_EXT_DAC_I2S_BCLK_SCALE >> 1); 
                  EXT_DAC_SetVolume(out_spk , afe.ext_dac_aud_vol);
                  afe.ext_dac_i2s_on = KAL_TRUE;
                  if(afe.ext_dac_add_st)
                     a_lowest = -1;  // Turn Off Audio Stereo Buffer When using EXT_DAC only    
                  break;
               case SRC_VOICE_DAC:   
               case SRC_EXT_INPUT:
                  EXT_DAC_TurnOnSpeaker(EXT_DAC_LINEIN , out_spk); 
                  EXT_DAC_FixedLineInGain(out_spk);
                  break;
            }
         }
         else 
         {
            if(((SND_SRC_MAP>>a_lowest*2)&3) == SRC_AUDIO_DAC && afe.ext_dac_add_st)
               a_lowest = -1;
         }
         if(afe.ext_dac_aud_func == L1SP_AUDIO)
         {
            afe.a_digi_gain = ((kal_uint32) DG_DAF * afe.ext_dac_level_gain) >> 15;
            L1Audio_PutMessage(MSG_L1AUDIO2FAS_AUDIO_SET_OUTPUT_VOLUME, afe.a_digi_gain, (kal_uint32)NULL);
         }
      }  
      else 
      {
         if(afe.ext_dac_aud_func != -1)
         {
            kal_uint8 out_spk;  
            out_spk = afe.aud[afe.ext_dac_aud_func].out_dev & (L1SP_EXT_DAC_BUF0|L1SP_EXT_DAC_BUF1);
            afe.ext_dac_aud_func = -1; 
            if(afe.ext_dac_i2s_on)
            {           
               AFE_TurnOffEDI(); 
               afe.ext_dac_i2s_on = KAL_FALSE;             
            }                        
            EXT_DAC_TurnOffSpeaker(out_spk);
         }   
      }
      
   #endif

      if(v_lowest >=0 && a_lowest >=0 ){// only allow a path output
         if(v_lowest <= a_lowest)
            a_lowest = -1;
         else
            v_lowest = -1;
      }

      if( v_lowest >= 0 || a_lowest >=0 || (afe.mic_flag && !afe.mic_mute && !afe.mute))
      { 
         afe.bPowerDown = KAL_FALSE;
       #if defined(MT6573)
         if( (*VAUDN_CON0&0x0001) != 0x0001 )
       #endif
         {
         #if defined(MT6575) || defined(MT6577)
            *AUDIO_LDO2   = (*AUDIO_LDO2 & ~0x0002) | 0x0011;
            *AUDIO_LDO2  |= 0x0002; //for uplink
            *CLKSQ_EN    |= 0x0001;
            *AUDIO_LDO0  |= 0x1000;
            *AUDIO_LDO1  |= 0x1000;
            *AUDIO_LDO0  |= 0x0030; //for uplink
            *AUDIO_LDO1  |= 0x2010; //for uplink
            *AUDIO_GLB0   = (*AUDIO_GLB0 & ~0x0c00) | 0x0800;
            *AUDIO_GLB0   = (*AUDIO_GLB0 & ~0x3000) | 0x2000;
            *AUDIO_NCP1  &= ~0x0e00; 
            *AUDIO_NCP0   = (*AUDIO_NCP0 & ~0x01ff) | 0x102b; //for uplink
            *AUDIO_GLB0   = (*AUDIO_GLB0 & ~0x0030) | 0x0020;
            *AUDIO_REG1  |= 0x0001;
            *AUDIO_GLB0  &= ~0x0001;
            *AUDIO_CON14 |= 0x00c0;
         #elif defined(MT6573)
            *VAUDN_CON0 = 0x0001 ;
            *VAUDP_CON0 = 0x0001 ;
            *VAUDP_CON1 = 0x0000 ;
            *VAUDP_CON2 = 0x012B ;
            *VM25_CON0 = 0x0001 ;
            *PLL_CON2 |= 0x20;// turn on AFE
         #endif //defined(MT6575)  || defined(MT6577)
         }
      }
      if(a_lowest >=0 || v_lowest >=0)
      {
         if(v_lowest>=0)
         {
            afe.Pre_OutDev = 0;
         }
         else
         {
            afe.Pre_OutDev = 1;
            afe.Pre_aFunc = a_lowest;
         }
      }
      //==================================================================================================
      if( v_lowest >= 0 ) {
         AFE_Switch_VoiceAmp(v_lowest, a_lowest);
      }
      //==================================================================================================
      else if( a_lowest >= 0 ) {
         AFE_Switch_AudAmp(v_lowest, a_lowest);
      }
      //==================================================================================================
      else {
         AFE_Switch_No_VoiceAudAmp();
      }
      afe.bPowerDown = KAL_TRUE;
      if( !afe.gpio_lock ) {
         if( ( (a_lowest >= 0) && (afe.aud[a_lowest].out_dev & L1SP_BUFFER_EXT) ) ||
             ( (v_lowest >= 0) && (afe.aud[v_lowest].out_dev & L1SP_BUFFER_EXT) ) ) {
            /// Turn on the external amplifier
            if (Ext_op_on_delay == 0) {
               AFE_SwitchExtAmplifier( true );
               afe.ext_op_on = KAL_TRUE;
               /// Reset the ext_op_delay timer to indicate the completion of current operation
               afe.ext_op_delay = 0;
            } else {
               /// The latest command will replace the un-executed command
               afe.ext_op_delay = (int16)Ext_op_on_delay;
            }
         } else {
            /// Turn off the external amplifier
            if (Ext_op_off_delay == 0) {
               AFE_SwitchExtAmplifier( false );
               afe.ext_op_on = KAL_FALSE;
               /// Reset the ext_op_delay timer to indicate the completion of current operation
               afe.ext_op_delay = 0;
            } else {
               /// The latest command will replace the un-executed command
               afe.ext_op_delay = -(int16)Ext_op_off_delay;
            }
         }
      }
      _apply_mic_setting(a_lowest, v_lowest);
   }
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
   
   if(afe.ext_op_delay == 0 && RB_EMPTY( afe.regq )){
      if(L1Audio_CheckFlag(afe.aud_id))
         L1Audio_ClearFlag(afe.aud_id);
   }
}

