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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    drv_features_adc.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for the ADC driver features
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef __DRV_FEATURES_ADC_H__
#define __DRV_FEATURES_ADC_H__

/**************** ADC ******************/
#include "drv_features_chip_select.h"

#if defined(DRV_ADC_6205_SERIES)
   #define DRV_ADC_LIMIT_REG
   #define DRV_ADC_OLD_FUNC
   #define DRV_ADC_NO_IMM
   
#elif defined(DRV_ADC_6205B_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_MAX_CH_5
   #define ADC_MAX_CHANNEL 5
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   
#elif defined(DRV_ADC_6208_SERIES)
   #define DRV_ADC_LIMIT_REG
   /* for adc_pwrdown_enable() */
   #define DRV_ADC_6208_PWRDOWN
   #define DRV_ADC_NO_IMM
   
#elif defined(DRV_ADC_6217_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_MAX_CH_7
   #define ADC_MAX_CHANNEL 7
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   
#elif defined(DRV_ADC_6218B_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_MAX_CH_7
   #define ADC_MAX_CHANNEL 7
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_F

#elif defined(DRV_ADC_6223_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS2
   #define DRV_ADC_TDMA_EN_REG_POS1
   #define DRV_ADC_MAX_CH_7
   #define ADC_MAX_CHANNEL 7
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_0
      
#elif defined(DRV_ADC_6225_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS1
   #define DRV_ADC_MAX_CH_7
   #define ADC_MAX_CHANNEL 7
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_0
   
#elif defined(DRV_ADC_6226_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS1
   #define DRV_ADC_MAX_CH_7
   #define ADC_MAX_CHANNEL 7
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_F
   
#elif defined(DRV_ADC_6228_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_MAX_CH_7
   #define ADC_MAX_CHANNEL 7
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_X
    
#elif defined(DRV_ADC_6229_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS2
   #define DRV_ADC_TDMA_EN_REG_POS1
   #define DRV_ADC_MAX_CH_7
   #define ADC_MAX_CHANNEL 7
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_X
      
#elif defined(DRV_ADC_6235_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS2
   #define DRV_ADC_TDMA_EN_REG_POS1
   #define DRV_ADC_MAX_CH_7
   #define ADC_MAX_CHANNEL 7
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_0

#elif defined(DRV_ADC_6238_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS2
   #define DRV_ADC_TDMA_EN_REG_POS1
   #define DRV_ADC_MAX_CH_7
   #define ADC_MAX_CHANNEL 7
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_0

#elif defined(DRV_ADC_6268_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS2
   #define DRV_ADC_TDMA_EN_REG_POS1
   #define DRV_ADC_MAX_CH_9
   #define ADC_MAX_CHANNEL 9
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_0
   /*
      Indicate we do NOT need to configure ADC related TDMA settings
      in ADC_Init()
      This will overwrite DRV_AUX_AC_CON_DEF_XXX defines
      MT6268A does NOT have 0x8050XXXX address for AUX_ADC to configure default settings
   */
   #define DRV_ADC_NO_ADC_DEF_CONFIG
  
   /*
      MT6268A ADC Sync mode issue temp workaround
   */
   #define __CHARGER_WITH_IMMEDIMATE_ADC__
   
   #define __DRV_ADC_PMIC_TURN_ON_MEASURE_DELAY__
   
#elif defined(DRV_ADC_6252_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS2
   #define DRV_ADC_TDMA_EN_REG_POS1
   #define DRV_ADC_MAX_CH_6
   #define ADC_MAX_CHANNEL 6
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_0
   #define DRV_ADC_NO_ADC_DEF_CONFIG
   /*
      ADC S/W reset: Use BIT7, the bit is used as TEST_DACMON in MT6205B
      Write 1: Reset AuxADC module, after 1 tick, AuxADC module is reset
      Write 0: Back to normal mode
      From MT6229, TEST_DACMON feature is gone
      The S/W reset design is from MT6253T
   */
   #define DRV_ADC_SW_RESET
   /*
     Indicate TEST_DACMON feature is NOT support
   */
   #define DRV_ADC_NO_TEST_DACMON
   #define DRV_ADC_CALIBRATION_EFUSE // For ADC Efuse
 
   #define DRV_DISABLE_SAP_ID
#elif defined(DRV_ADC_6250_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS2
   #define DRV_ADC_TDMA_EN_REG_POS1
   #define DRV_ADC_MAX_CH_12
   #define ADC_MAX_CHANNEL 12
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_0
   #define DRV_ADC_NO_ADC_DEF_CONFIG
   /*
	 ADC S/W reset: Use BIT7, the bit is used as TEST_DACMON in MT6205B
	 Write 1: Reset AuxADC module, after 1 tick, AuxADC module is reset
	 Write 0: Back to normal mode
	 From MT6229, TEST_DACMON feature is gone
	 The S/W reset design is from MT6253T
     */
   #define DRV_ADC_SW_RESET
   /*
	     Indicate TEST_DACMON feature is NOT support
      */
   #define DRV_ADC_NO_TEST_DACMON
  	
   #define DRV_DISABLE_SAP_ID

   #define DRV_ADC_DELAY_FOR_ADCCAP // make sure the capacitance is fully charge

   #define DRV_ADC_NO_PUWAIT_EN		//	it will affect 2GTx when it enable
   #define DRV_ADC_SAMPLE_10bIT	
   #define DRV_ADC_CALIBRATION_EFUSE // For ADC Efuse	
   #define DRV_DIE_TO_DIE_INTERFACE
   #define DRV_MISC_ADC_MEASURE_REMOVE_IRQMASK
   
   #define DRV_ADC_BUSYBIT_ASSERT_CHECK
  // #define __CHARGER_WITH_IMMEDIMATE_ADC__
   #define DRV_ADC_WAKE_UP_TDMA_TIMER
   #define __DRV_ADC_SYNC_META__
   #define DRV_ADC_SW_RESET_CHECK_FOR_BUSY_BIT
#elif defined(DRV_ADC_6253_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS2
   #define DRV_ADC_TDMA_EN_REG_POS1
   #define DRV_ADC_MAX_CH_6
   #define ADC_MAX_CHANNEL 6
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_0
   #define DRV_ADC_NO_ADC_DEF_CONFIG
   /*
      ADC S/W reset: Use BIT7, the bit is used as TEST_DACMON in MT6205B
      Write 1: Reset AuxADC module, after 1 tick, AuxADC module is reset
      Write 0: Back to normal mode
      From MT6229, TEST_DACMON feature is gone
      The S/W reset design is from MT6253T
   */
   #define DRV_ADC_SW_RESET
   /*
     Indicate TEST_DACMON feature is NOT support
   */
   #define DRV_ADC_NO_TEST_DACMON

#elif defined(DRV_ADC_MT6516_AP_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS2
   #define DRV_ADC_TDMA_EN_REG_POS1
   #define DRV_ADC_MAX_CH_9
   #define ADC_MAX_CHANNEL 9
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_0
   /*
      Indicate we do NOT need to configure ADC related TDMA settings
      in ADC_Init()
      This will overwrite DRV_AUX_AC_CON_DEF_XXX defines
      MT6268A does NOT have 0x8050XXXX address for AUX_ADC to configure default settings
   */
   #define DRV_ADC_NO_ADC_DEF_CONFIG

   /*
      Indicate there is ADC background detection mechanism V1
   */
   #define DRV_ADC_BACKGROUND_DET_REG_V1

   /*
      Indicate ADC CG/PDN control is at CON0
   */
   #define ADC_CG_PDN_CON0   

#elif defined(DRV_ADC_6236_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS2
   #define DRV_ADC_TDMA_EN_REG_POS1
   #define DRV_ADC_MAX_CH_8 //The difference with MT6253
   #define ADC_MAX_CHANNEL 8
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_0
   #define DRV_ADC_NO_ADC_DEF_CONFIG
   /*
      ADC S/W reset: Use BIT7, the bit is used as TEST_DACMON in MT6205B
      Write 1: Reset AuxADC module, after 1 tick, AuxADC module is reset
      Write 0: Back to normal mode
      From MT6229, TEST_DACMON feature is gone
      The S/W reset design is from MT6253T
   */
   #define DRV_ADC_SW_RESET
   /*
     Indicate TEST_DACMON feature is NOT support
   */
   #define DRV_ADC_NO_TEST_DACMON
    /*
	For 6236 E2, E3 ADC Parameter Change
    */
	#define DRV_ADC_VCHARGE_FACTOR_OVERWRITE
	 
#elif defined(DRV_ADC_6256_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS2
   #define DRV_ADC_TDMA_EN_REG_POS1
   #define DRV_ADC_MAX_CH_13
   #define ADC_MAX_CHANNEL 13
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_0
   #define DRV_ADC_NO_ADC_DEF_CONFIG
   #define DRV_ADC_DELAY_FOR_ADCCAP	// make sure the capacitance is fully charge
   /*
      ADC S/W reset: Use BIT7, the bit is used as TEST_DACMON in MT6205B
      Write 1: Reset AuxADC module, after 1 tick, AuxADC module is reset
      Write 0: Back to normal mode
      From MT6229, TEST_DACMON feature is gone
      The S/W reset design is from MT6253T
   */
   #define DRV_ADC_SW_RESET
   /*
     Indicate TEST_DACMON feature is NOT support
   */
   #define DRV_ADC_NO_TEST_DACMON
   #define DRV_ADC_NO_PUWAIT_EN		//	it will affect 2GTx when it enable
   #define DRV_ADC_SAMPLE_12bIT	
   #define DRV_ADC_CALIBRATION_EFUSE // For ADC Efuse	 

#elif defined(DRV_ADC_6276_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS2
   #define DRV_ADC_TDMA_EN_REG_POS1
   #define DRV_ADC_MAX_CH_13
   #define ADC_MAX_CHANNEL 13
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_0
   #define DRV_ADC_NO_ADC_DEF_CONFIG
   /*
      ADC S/W reset: Use BIT7, the bit is used as TEST_DACMON in MT6205B
      Write 1: Reset AuxADC module, after 1 tick, AuxADC module is reset
      Write 0: Back to normal mode
      From MT6229, TEST_DACMON feature is gone
      The S/W reset design is from MT6253T
   */
   #define DRV_ADC_SW_RESET
   /*
     Indicate TEST_DACMON feature is NOT support
   */
   #define DRV_ADC_NO_TEST_DACMON 
   
   /*
      MT6268A ADC Sync mode issue temp workaround
   */
   #define __CHARGER_WITH_IMMEDIMATE_ADC__

   /* To adjust bias current to 1.5 times than original to avoid current issue  */	
   #define DRV_ADC_BIAS_CURRENT_ENLARGE   
   #define DRV_ADC_VCHARGER_EXTEND_READING	// extend adc read period for VCHARGER
   #define DRV_ADC_SAMPLE_12bIT

#elif defined(DRV_ADC_6251_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS2
   #define DRV_ADC_TDMA_EN_REG_POS1
   #define DRV_ADC_MAX_CH_13
   #define ADC_MAX_CHANNEL 13
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_0
   #define DRV_ADC_NO_ADC_DEF_CONFIG
   /*
      ADC S/W reset: Use BIT7, the bit is used as TEST_DACMON in MT6205B
      Write 1: Reset AuxADC module, after 1 tick, AuxADC module is reset
      Write 0: Back to normal mode
      From MT6229, TEST_DACMON feature is gone
      The S/W reset design is from MT6253T
   */
   #define DRV_ADC_SW_RESET
   /*
     Indicate TEST_DACMON feature is NOT support
   */
   #define DRV_ADC_NO_TEST_DACMON

   /* ADC_VBAT channel use factor = 3 inside PMU, this define for NVRAM ADC setting*/
   #define __DRV_ADC_VBAT_FACTOR_3__

   #define DRV_ADC_SAMPLE_12bIT
#elif defined(DRV_ADC_6573_SERIES)
    #define DRV_ADC_BASIC_REG
    #define DRV_ADC_MAX_CH_13
    #define ADC_MAX_CHANNEL 13
    #define DRV_ADC_FULL_FUNC
    #define DRV_ADC_TDMA_TIME
    #define DRV_ADC_IMM
    #define DRV_ADC_MODEM_SIDE // For Modem Side Measure RF_TEMP
    #define __CHARGER_WITH_IMMEDIMATE_ADC__
    #define DRV_ADC_SAMPLE_12bIT

#elif defined(DRV_ADC_6575_SERIES)
    #define DRV_ADC_BASIC_REG
    #define DRV_ADC_MAX_CH_13
    #define ADC_MAX_CHANNEL 13
    #define DRV_ADC_FULL_FUNC
    #define DRV_ADC_TDMA_TIME
    #define DRV_ADC_IMM
    #define DRV_ADC_MODEM_SIDE // For Modem Side Measure RF_TEMP
    #define __CHARGER_WITH_IMMEDIMATE_ADC__
 	#define DRV_ADC_SET_CLR
	
    #define DRV_ADC_SAMPLE_12bIT
	#define ADC_CPU_TEMP_SENSOR_USE
	#define DRV_ADC_CALIBRATION_EFUSE
	#define DRV_ADC_GET_CHANNEL_NUMBER_FROM_AP
	#define DRV_ADC_RFTMP_CHANNEL_NUMBER	3
	#define DRV_ADC_EVB_RFTMP_CHANNEL_NUMBER	2
	
#elif defined(DRV_ADC_6255_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS2
   #define DRV_ADC_TDMA_EN_REG_POS1
   #define DRV_ADC_MAX_CH_13
   #define ADC_MAX_CHANNEL 13
   #define DRV_ADC_FULL_FUNC
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_0
   #define DRV_ADC_NO_ADC_DEF_CONFIG
   #define DRV_ADC_DELAY_FOR_ADCCAP	// make sure the capacitance is fully charge
	   /*
		  ADC S/W reset: Use BIT7, the bit is used as TEST_DACMON in MT6205B
		  Write 1: Reset AuxADC module, after 1 tick, AuxADC module is reset
		  Write 0: Back to normal mode
		  From MT6229, TEST_DACMON feature is gone
		  The S/W reset design is from MT6253T
	   */
   #define DRV_ADC_SW_RESET
	   /*
		 Indicate TEST_DACMON feature is NOT support
	   */
   #define DRV_ADC_NO_TEST_DACMON
   #define DRV_ADC_NO_PUWAIT_EN		//	it will affect 2GTx when it enable
   #define DRV_ADC_SAMPLE_12bIT	
   #define DRV_ADC_CALIBRATION_EFUSE

#elif defined(DRV_ADC_6280_SERIES)
#define DRV_ADC_NOT_EXIST
#if !defined(DRV_ADC_MAX_CH_1)
#define DRV_ADC_MAX_CH_1
#define ADC_MAX_CHANNEL 1
#define DRV_ADC_TDMA_TIME
#endif

#elif defined(DRV_AUXADC_MT6290_SERIES)
   #define DRV_ADC_BASIC_REG
   #define DRV_ADC_TDMA_EVENT_REG_POS2
   #define DRV_ADC_TDMA_EN_REG_POS1
   #define DRV_ADC_MAX_CH_6
   #define ADC_MAX_CHANNEL 6
   #define DRV_ADC_TDMA_TIME
   #define DRV_ADC_IMM
   #define DRV_AUX_AC_CON_DEF_0
   #define DRV_ADC_NO_ADC_DEF_CONFIG
   /*
      ADC S/W reset: Use BIT7, the bit is used as TEST_DACMON in MT6205B
      Write 1: Reset AuxADC module, after 1 tick, AuxADC module is reset
      Write 0: Back to normal mode
      From MT6229, TEST_DACMON feature is gone
      The S/W reset design is from MT6253T
   */
   #define DRV_ADC_SW_RESET
   /*
     Indicate TEST_DACMON feature is NOT support
   */
   #define DRV_ADC_NO_TEST_DACMON

   /* ADC_VBAT channel use factor = 3 inside PMU, this define for NVRAM ADC setting*/
   #define __DRV_ADC_VBAT_FACTOR_3__

   #define DRV_ADC_SAMPLE_12bIT


#elif defined(DRV_ADC_NOT_EXIST)
#if !defined(DRV_ADC_MAX_CH_1)
#define DRV_ADC_MAX_CH_1
#define ADC_MAX_CHANNEL 1
#define DRV_ADC_TDMA_TIME
#endif

#endif // ADC series

//#ifdef __MEUT__
#define DCL_ADC_INTERFACE
//#endif

/* Only open the AUXADC feature in smart phone project */
#if !defined(__SMART_PHONE_MODEM__) || !defined(__X_BOOTING__)
#define DRV_ADC_OFF
#endif

#endif /*End __DRV_FEATURES_ADC_H__*/
