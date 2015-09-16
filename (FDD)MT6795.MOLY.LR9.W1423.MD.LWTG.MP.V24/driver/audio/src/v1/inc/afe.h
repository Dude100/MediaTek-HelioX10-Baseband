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
 *	afe.c
 *
 * Project:
 * --------
 *   MAUI
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
 * $Revision:   1.21  $
 * $Modtime:   Jul 08 2005 16:31:52  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/l1audio/afe.h-arc  $
 *
 * removed!
 * removed!
 * Merge K2 Speech DVT code.
 *
 * removed!
 * removed!
 * [K2] 6752 chip option adding
 *
 * removed!
 * removed!
 * fix NXP and DMNR concurrency setting error
 *
 * removed!
 * removed!
 * DVT test cases check in
 *
 * removed!
 * removed!
 * [ROME] add DVT setting
 *
 * removed!
 * removed!
 * Merging	//MOLY/Development_BRANCHES/MT6595E1_BRING_UP_DEV/mcu/driver/audio/...
 * to //MOLY/TRUNK/MOLY/mcu/driver/audio/...
 *
 * removed!
 * removed!
 * Fix bug, MDAFE hw register is 32 bit instead of 16 bit
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
 * add MT6592/MT6571 chip options
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
 * DRC 2.0 modification
 *
 * removed!
 * removed!
 * Fix Build error for MT6290
 *
 * removed!
 * removed!
 * Fix Build Error
 *
 * removed!
 * removed!
 * MT6572 bring up
 *
 * removed!
 * removed!
 * wbBT
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
 * Chip Rename to MT6589
 * Remove unused AFE functions
 * Phase in phone call usage
 * 
 * removed!
 * removed!
 * add compile option for analog AFE
 * 
 * removed!
 * removed!
 * 83 phone call prepare, warning removal
 * 
 * removed!
 * removed!
 * Modify for MD2G wakeup by Audio.
 * 
 * 08 17 2012 kh.hung
 * removed!
 * Remove l1d_reg.h.
 * 
 * removed!
 * removed!
 * Fix build warning.
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
#ifndef AFE_H
#define AFE_H

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        Chapter:  INCLUDE FILES
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "reg_base.h"
#include "kal_trace.h"
#include "l1audio_trace.h"
#include "l1sp_trc.h"
#include "audcoeff_default.h"
#include "afe_def.h"
#include "dcl.h"
#include "us_timer.h"
#include "speech_def.h"

#if defined(__BT_SUPPORT__)
   #include "bt_api.h"
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
||                        Chapter: Data Types and Structures
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  Section: Enum Multiple Die
//=============================================================================================
typedef enum
{
   AFE_DIE2DIE_NONE,
   AFE_DIE2DIE_DOWNLINK,
   AFE_DIE2DIE_UPLINK
}AFE_DIE2DIE_T;

//=============================================================================================
//                  Section: Enum AFE_STATE_T
//=============================================================================================
typedef enum
{
   AFE_STATE_OFF = 0,
   AFE_STATE_ON,
   AFE_STATE_IDLE_OFF,
   AFE_STATE_CLASS_D_OFF,
   AFE_STATE_MAX
}  AFE_STATE_T;


//=============================================================================================
//                  Section: Structure DelayCmd
//=============================================================================================
typedef struct {
   volatile uint16*  addr;
   uint16            val;
} DelayCmd;

//=============================================================================================
//                  Section: Structure RegBackup
//=============================================================================================
typedef struct {
#if (defined(MT6595) || defined(MT6752))
   kal_uint32     VMCU_CON;
   kal_uint32     VMCU_CON1;
   kal_uint32     PCM_CON0;
   kal_uint32     AMCU_CON0;
   kal_uint32     AMCU_CON1;
   kal_uint32     IRQ_CON1;
   kal_uint32     MCU_CON0;
   kal_uint32     MCU_CON1;
   kal_uint32     CONN0;
      
#elif (defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6290))
   kal_uint16     VMCU_CON;
   kal_uint16     VDB_CON;
   kal_uint16     VLB_CON;
   kal_uint16     AMCU_CON0;
   kal_uint16     AMCU_CON1;
   kal_uint16     EDI_CON;
   kal_uint16     AMCU_CON2;
   kal_uint16     DAC_TEST;
   kal_uint16     VMCU_CON1;
   kal_uint16     VMCU_CON2;
#else 
	#error Please add the register needs to backup and implement function _AfeRegisterBackupByChip() and _AfeRegisterStoreByChip() by chip
#endif 
} RegBackup;

//=============================================================================================
//                  Section: Structure AFE_STRUCT_T (afe main structure)
//=============================================================================================
typedef struct {

#ifdef ANALOG_AFE_PATH_EXIST
   /// Speaker usage flag
   /// bit n : aud function n
   /// [Set|Clear] by AFE_Turn[On|Off]Speaker
   kal_uint16     sp_flag;
   /// FIR filter usage flag
   /// bin n: aud function n
   /// [Set|Clear] by AFE_Turn[On|Off]FIR
   kal_uint16     fir_flag;			
   /// Microphone usage flag
   /// bin n: aud function n
   /// [Set|Clear] by AFE_Turn[On|Off]Microphone
   kal_uint16     mic_flag;
#else
	/// AFE Work usage flag (means 8k/path)
   /// bin n: aud function n
   /// [Set|Clear] by AFE_Turn[On|Off]PathWork
	kal_uint16     pathWork_flag;
#endif // ANALOG_AFE_PATH_EXIST
 

#ifndef ANALOG_AFE_PATH_EXIST	// only digital path
	kal_int16      digitOnly_mic_volume; // actural value to DSP sw "AGC" gain!!
#endif

#if 0 // def ANALOG_AFE_PATH_EXIST	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
   
   struct   {
      /// L1SP_SPEAKER1, L1SP_SPEAKER2, or L1SP_LOUDSPEAKER
      /// Set by AFE_SetOutputDevice

      kal_uint8   out_dev;
      kal_uint8   volume;
#if 0 // def ANALOG_AFE_PATH_EXIST
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else      
		kal_int16   digitOnly_digital_gain; // actural value to DSP 
#endif // ANALOG_AFE_PATH_EXIST      
      kal_bool    mute;
   } aud[L1SP_MAX_AUDIO];
   kal_uint16     aud_id;
	kal_int16      digitOnly_sphEnhRef_digital_gain;
	
   // kal_uint8      Pre_OutDev; //0: voice out, 1: audio out
   // kal_int16      Pre_aFunc;
   // kal_uint8      Pre_InSrc; //0: voice src, 1: audio src, 2: line-in
   /// for controlling external amplifier
   kal_bool       gpio_lock;
   kal_bool       ext_op_on;
   // kal_bool       mute;  /// for mute AFE
   kal_bool       refresh;
   kal_bool       loopback; 
   // kal_bool       v8k_off_request;
   // kal_bool       aClk_off_request;
   // kal_bool       audioplay;
   // kal_bool       aClk_on_request; 
   kal_bool       bt_flag;
   // kal_bool       dis_idleOff_delay;
   // kal_bool       afe_hw_mute; // not hw existing
   // kal_bool       afe_event_handler_hw_mute; // [remove] not hw existing
   // kal_bool       afe_audio_clk_hw_mute;
   kal_bool       afe_init;
   kal_uint8      voice8kMode;
   kal_uint32     audio_fs;
   RINGBUFFER_T(DelayCmd,8)  regq;
   // kal_uint16     class_d_gain;
   AFE_STATE_T    afe_state; 

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

#if 0 // defined(__ACCDET_HYBRID_SOLUTION_SUPPORT__)
/* under construction !*/
/* under construction !*/
#endif

#if __RELOAD_HW_COEFF__
   //for 65nm clock gating, digital AFE register backup
   RegBackup      regbak;
#endif
   
   // kal_bool       Audio_close_delay_expired;

   // kal_bool       audio_clk_ena;
   // kal_bool       voice_clk_ena;

   // kal_bool       audio_dl_ena; // analog audio downlink path enable
   // kal_bool       voice_dl_ena; // analog voice downlink path enable
   // kal_bool       voice_ul_ena;

#if __CTIRQ_SLEEP_PLATFORM__
   kal_timerid    timer;
#endif
} AFE_STRUCT_T;

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        Chapter: Special Configurations for Specific Usage
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                   Section: Debug and Unit Test Configuration
//=============================================================================================
//#define __AFE_DEBUG__
#define UNIT_TEST_AFE2 0
#ifdef __AFE_DEBUG__
   #define afe_prompt_trace  kal_prompt_trace

static kal_char * _aszAfeState[] =
{
   "AFE_STATE_OFF",
   "AFE_STATE_ON",
   "AFE_STATE_IDLE_OFF",
   "AFE_STATE_CLASS_D_OFF"
};

#else
   #define afe_prompt_trace(...) 
#endif

#if (defined(MT6595) || defined(MT6752))
//#define MDAFE_DVT_CASE1 1
//#define MDAFE_DVT_CASE2 1
//#define MDAFE_DVT_CASE3 1

//#define APAUDSYS_DVT_8K 1
//#define APAUDSYS_DVT_16K 1
//#define APAUDSYS_DVT_32K 1

//#define USE_ASRC 1

//#define APAUDSYS_DVT_RF2 1
#endif
/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        Chapter: Definitions by Features (Common Feature for all chips)
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

#if defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6290) || defined(MT6592) || defined(MT6571)
#define MDAFE_2IN_1OUT
#else
#define MDAFE_6IN_2OUT
#endif

//=============================================================================================
//                  Section: Feature Power Down Control Registers Settings
//=============================================================================================
   #define PDN_CON2_VAFE       0x0100
#if defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6290) || defined(MT6592) || defined(MT6571) || defined(MT6595) || defined(MT6752)
   #define PDN_CON2_AAFE       PDN_CON2_VAFE
#else
   // #define PDN_CON2_AAFE       0x1000
   #error Please define it for new chip
#endif
// #define CG_CON2_MIXED       0x0200

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        Chapter: Definitions by Features (Feature for specific chips)
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/


/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        Chapter: DEFINITION OF DATA TYPES
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  Section: Macros
//=============================================================================================
#define AFE_READ16(Reg)                        (*((volatile kal_uint16*)(Reg)))
#define AFE_WRITE16(Reg, Value)                 (*((volatile kal_uint16*)(Reg)) = (Value))
#define AFE_SET_BIT(Reg, Bit)                  AFE_WRITE16(Reg, AFE_READ16(Reg) | (Bit))
#define AFE_CLR_BIT(Reg, Bit)                  AFE_WRITE16(Reg, AFE_READ16(Reg) & (~(Bit)))

//=============================================================================================
//                  Section: External Variables and Functions
//=============================================================================================
extern AFE_STRUCT_T afe;
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
   
extern const unsigned char  L1SP_SPEAKER1;
extern const unsigned char  L1SP_SPEAKER2;
extern const unsigned char  L1SP_LOUD_SPEAKER;

extern const kal_uint16 digital_gain_table[17];

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        Chapter: Function Prototypes
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
kal_uint32 SaveAndSetIRQMask(void);
void RestoreIRQMask(kal_uint32);

void AFE_Init( void );
#if 0 // def ANALOG_AFE_PATH_EXIST	
/* under construction !*/
#else
void SearchPathWorkingFlag( kal_int16 *v_lowest, kal_int16 *a_lowest );
#endif

void AFE_SetRefresh( void );
void AFE_DELAY(uint16 delay);

void AFE_Chip_Event_Handler( void *data );
void AFE_Manager( void );
 
// void AFE_SetRefVol(kal_bool fgEnable);
#if 0
/* under construction !*/
#endif

void AFE_Chip_Init( void );

#ifdef ANALOG_AFE_PATH_EXIST	
kal_uint16 _converted_digital_gain(kal_int8 digital_gain_index);
#else
kal_uint16 _digitOnly_convert_digital_gain(kal_int16 digitalGainDb);
void _digitOnly_update_digital_gain(kal_int16 v_lowest, kal_int16 a_lowest);
#endif

void AFE_SwitchExtAmplifier(kal_bool enable);
// void AFE_DisableAmp(void);
void AFE_Initialize(void);
void AFE_RegisterStore(void);
// void AFE_DC_Calibration_WriteBack(void);
void _AfeRegisterBackupByChip(void);
void _AfeRegisterStoreByChip(void);

void AFE_SetRefresh( void );

// void AFE_TurnOffAudioClock( void );
// void AFE_TurnOnEDI( kal_uint16 dir, kal_uint16 fmt, kal_uint16 cycle );
// void AFE_TurnOffEDI( void );

//void AFE_TurnOnPcm( kal_uint16 param );
//void AFE_TurnOffPcm( kal_uint16 param );
void AFE_TurnOnLoopback( void );
void AFE_TurnOffLoopback( void );
kal_uint8 AFE_GetOutputDevice( kal_uint8 aud_func );

void AFE_SetBtFlag(kal_bool on);

kal_uint8 AFE_GetVoice8KMode(void);
void AFE_SetVoice8KMode(kal_uint8 mode);
#endif //AFE_H
