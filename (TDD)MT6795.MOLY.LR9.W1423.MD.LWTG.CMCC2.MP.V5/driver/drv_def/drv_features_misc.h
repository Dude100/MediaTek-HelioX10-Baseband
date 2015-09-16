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
 *    drv_features_miss.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for the MISC driver features
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __DRV_FEATURES_MISC_H__
#define __DRV_FEATURES_MISC_H__

#include "drv_features_chip_select.h"

#if defined(DRV_MISC_6205_SERIES)
   #define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_PDN_NO_SET_CLR
   #define DRV_MISC_TDMA_TIME_MAX_24BITS
   #define DRV_MISC_TDMA_TIME_BASE_8020
   #define DRV_MISC_WDT_TURN_OFF_PLL
#elif defined(DRV_MISC_6208_SERIES)
   #define DRV_MISC_PDN_NO_SET_CLR
   #define DRV_MISC_TDMA_TIME_MAX_24BITS
   #define DRV_MISC_TDMA_TIME_BASE_8020
   #define DRV_MISC_WDT_TURN_OFF_PLL
#elif defined(DRV_MISC_6205B_SERIES)
   #define DRV_MISC_DMA_NO_MEMCPY
   #define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_NO_TIME
   #define DRV_MISC_LOW_COST_PROJ
   #define DRV_MISC_WDT_TURN_OFF_PLL
#elif defined(DRV_MISC_6217_SERIES)
   #define DRV_MISC_DMA_MEMCPY
   #define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_TIME_BASE_8020
   #define DRV_MISC_TDMA_TIME_MAX_24BITS
   #define DRV_MISC_WDT_TURN_OFF_PLL
#elif defined(DRV_MISC_6218B_SERIES)
   #define DRV_MISC_DMA_MEMCPY
   #define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_NO_TIME
   #define DRV_MISC_WDT_TURN_OFF_PLL
#elif defined(DRV_MISC_6219_SERIES)
   #define DRV_MISC_DMA_MEMCPY
   #define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_TIME_MAX_19BITS
   #define DRV_MISC_TDMA_TIME_BASE_8020
   #define DRV_MISC_WDT_TURN_OFF_PLL
#elif defined(DRV_MISC_6238_SERIES)
   #define DRV_MISC_DMA_MEMCPY
   #define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_TIME_MAX_24BITS
   #define DRV_MISC_TDMA_TIME_BASE_8200
   // Support ZI, RW cache region
   //#define DRV_MISC_CACHE_REGION_SUPPORT
   #define DRV_MISC_LPWR_INTERNAL_REGION

   // HIGHER VIO to 2.96V for stable power off
   #define DRV_MISC_POWEROFF_VIO_2_96

#elif defined(DRV_MISC_6235_SERIES)
   #define DRV_MISC_DMA_MEMCPY
   #define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_TIME_MAX_24BITS
   #define DRV_MISC_TDMA_TIME_BASE_8200
   // Support ZI, RW cache region
   #define DRV_MISC_CACHE_REGION_SUPPORT

   // HIGHER VIO to 2.96V for stable power off
   #define DRV_MISC_POWEROFF_VIO_2_96

#elif defined(DRV_MISC_6268T_SERIES)
   #define DRV_MISC_DMA_MEMCPY
   #define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_TIME_BASE_8020
   #define DRV_MISC_TDMA_TIME_MAX_24BITS
   /*
     Indicate on MT6268T FPGA board, there is bug on FPGA H/W
     After write TDMA FM Start bit, need delay time to wait H/W state machine ready
     Or device will hang in wait_32k_start()
   */
   #define DRV_MISC_TDMA_FM_START_UNSTABLE
   /*
      Some platforms may have problem that VBAT channel always get lower value
      It may be
      1. H/W chip bug  or
      2. Platform layout problem
      Define to always return FIXED VBAT value
   */
   #define DRV_MISC_ADC_FIXED_VBAT_WA

#elif defined(DRV_MISC_6516_SERIES)
   #define DRV_MISC_DMA_MEMCPY
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_TIME_MAX_24BITS
   #define DRV_MISC_TDMA_TIME_BASE_8200
   #define __DRV_NO_USB_CHARGER__
#elif defined(DRV_MISC_MT6516_SERIES)
   #define DRV_MISC_DMA_MEMCPY
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_TIME_MAX_24BITS
   #define DRV_MISC_TDMA_TIME_BASE_8200
   #define __DRV_NO_USB_CHARGER__
   #define __DRV_NO_CABLE_DETECTION__
   #define __DRV_NO_CHARGER__
   #define DRV_MISC_TDMA_PDN0
   /*
      TMDA base address of MT6516 is moved to CG0
   */
   #define DRV_MISC_TDMA_BASE_CG0
#elif defined(DRV_MISC_MT6516_AP_SERIES)
   #define DRV_MISC_DMA_MEMCPY
   //#define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_TIME_MAX_24BITS
   #define DRV_MISC_TDMA_TIME_BASE_8200
   #define __DRV_NO_USB_CHARGER__
   /*
      TMDA base address of MT6516 is moved to CG0
   */
   #define DRV_MISC_TDMA_BASE_CG0
#elif defined(DRV_MISC_6268A_SERIES)
   //#define DRV_MISC_DMA_MEMCPY
   #define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_TIME_BASE_8406
   #define DRV_MISC_TDMA_TIME_MAX_24BITS
   /*
      Indicate the clock base is 15.36 MHz
   */
   #define DRV_MISC_CLOCK_BASE_1536
   /*
      TTTTTTT
      MT6268A does NOT have 0x8000XXXX PLL setting when reset
   */
   #define DRV_MISC_RESET_NO_SET_PLL
   /*
      MT6268A has ADC Channel0 H/W bug
      When voltage is higher than 1.5V, we can NOT measure corrsponding ADC value
      There is no linear mathematical model to workaround it when voltage is higher tha 1.5V
      The impact:
          1. Power on will always check as pre-charge state
          2. When measuring power, the VBAT is always under normal value (VBAT connect to CH0)
   */
//   #define DRV_MISC_ADC_CH0_BUG_WA
   /*
      When VBAT is connect to ADC CH0, we force to return fixed VBAT voltage
      This is because the VBAT is NOT correct due to ADC CHO H/W bug
   */
//   #define DRV_MISC_ADC_FIXED_VBAT_WA
   /*
      Remove IRQ mask when performing ADC measurement
      ADC measurement are performed in HISR context(Timer hisr), except l1_adc_XXX APIs
      l1_adc_XXX is NOT used for a long time, and may not be enabled again
      When this feature is enabled, we add assert in l1_adc_XXX
   */
   #define DRV_MISC_ADC_MEASURE_REMOVE_IRQMASK

   /*
      MT6268A use 26MHz clock source to calibrate 32K
   */
   #define DRV_MISC_USE_26MHZ_SRC_CALIBRATE_32KHZ_CLOCK

   #define DRV_MISC_32KHZ_CALI_SM_WC


#elif defined(DRV_MISC_6270A_SERIES)
   //#define DRV_MISC_DMA_MEMCPY
   #define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   //#define DRV_MISC_TDMA_TIME_BASE_8406
   //#define DRV_MISC_TDMA_TIME_MAX_24BITS
   /*
      Indicate the clock base is 15.36 MHz
   */
   #define DRV_MISC_CLOCK_BASE_1536
   /*
      TTTTTTT
      MT6268A does NOT have 0x8000XXXX PLL setting when reset
   */
   #define DRV_MISC_RESET_NO_SET_PLL
   /*
      MT6268A has ADC Channel0 H/W bug
      When voltage is higher than 1.5V, we can NOT measure corrsponding ADC value
      There is no linear mathematical model to workaround it when voltage is higher tha 1.5V
      The impact:
          1. Power on will always check as pre-charge state
          2. When measuring power, the VBAT is always under normal value (VBAT connect to CH0)
   */
//   #define DRV_MISC_ADC_CH0_BUG_WA
   /*
      When VBAT is connect to ADC CH0, we force to return fixed VBAT voltage
      This is because the VBAT is NOT correct due to ADC CHO H/W bug
   */
//   #define DRV_MISC_ADC_FIXED_VBAT_WA
   /*
      Remove IRQ mask when performing ADC measurement
      ADC measurement are performed in HISR context(Timer hisr), except l1_adc_XXX APIs
      l1_adc_XXX is NOT used for a long time, and may not be enabled again
      When this feature is enabled, we add assert in l1_adc_XXX
   */
   #define DRV_MISC_ADC_MEASURE_REMOVE_IRQMASK

   /*
      MT6268A use 26MHz clock source to calibrate 32K
   */
   #define DRV_MISC_USE_26MHZ_SRC_CALIBRATE_32KHZ_CLOCK

   #define DRV_MISC_32KHZ_CALI_SM_WC

#ifdef __GPT_AS_OS_TICK__
   /* Use GPT1 as the OS tick. */
   #define DRV_MISC_GPT1_AS_OS_TICK
#endif //__GPT_AS_OS_TICK__

#elif defined(DRV_MISC_6253T_SERIES)
   #define DRV_MISC_DMA_MEMCPY
   #define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_TIME_MAX_24BITS
   #define DRV_MISC_TDMA_TIME_BASE_8200
   // Support ZI, RW cache region
   #define DRV_MISC_CACHE_REGION_SUPPORT

   /*
     Define to force return PWRKEY power on
     This should only be enabled at DVT phase (Before driver ready) to avoiding block other tests
   */
//   #define DRV_MISC_PWIC_FORCE_RETURN_PWRKEY_POWERON

   /*
     Define to ignore ADC run state check (This is only for debug purpose, need to remove after fix)
   */
//   #define DRV_MISC_IGNORE_ADC_RUN_STATUS_CHECK

   /*
     Define to add ADC_GetData to internal RAM (This is only for debug purpose!!!!!Need to remove after fix)
   */
   #define DRV_MISC_ADD_ADC_GETDATA_TO_INTERNAL_RAM

   #define DRV_MISC_32KHZ_CALI_SM_WC

   /*
      Remove IRQ mask when performing ADC measurement
      ADC measurement are performed in HISR context(Timer hisr), except l1_adc_XXX APIs
      l1_adc_XXX is NOT used for a long time, and may not be enabled again
      When this feature is enabled, we add assert in l1_adc_XXX
   */
   #define DRV_MISC_ADC_MEASURE_REMOVE_IRQMASK
#elif defined(DRV_MISC_6253_SERIES)
   #define DRV_MISC_DMA_MEMCPY
   #define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_TIME_MAX_24BITS
   #define DRV_MISC_TDMA_TIME_BASE_8200
   // Support ZI, RW cache region
   #define DRV_MISC_CACHE_REGION_SUPPORT

   /*
     Define to force return PWRKEY power on
     This should only be enabled at DVT phase (Before driver ready) to avoiding block other tests
   */
//   #define DRV_MISC_PWIC_FORCE_RETURN_PWRKEY_POWERON

   /*
     Define to ignore ADC run state check (This is only for debug purpose, need to remove after fix)
   */
//   #define DRV_MISC_IGNORE_ADC_RUN_STATUS_CHECK

   /*
     Define to add ADC_GetData to internal RAM (This is only for debug purpose!!!!!Need to remove after fix)
   */
   #define DRV_MISC_ADD_ADC_GETDATA_TO_INTERNAL_RAM

   #define DRV_MISC_32KHZ_CALI_SM_WC

   /*
      Remove IRQ mask when performing ADC measurement
      ADC measurement are performed in HISR context(Timer hisr), except l1_adc_XXX APIs
      l1_adc_XXX is NOT used for a long time, and may not be enabled again
      When this feature is enabled, we add assert in l1_adc_XXX
   */
   #define DRV_MISC_ADC_MEASURE_REMOVE_IRQMASK

   /*
      MT6253 PMU related ADC channels start from 0, MT6253T PMU related ADC channels start from 3
   */
   #define DRV_MISC_PMU_ADC_CHANNEL_FROM_0

#elif defined(DRV_MISC_6253EL_SERIES)
   #define DRV_MISC_DMA_MEMCPY
   //#define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_TIME_MAX_24BITS
   #define DRV_MISC_TDMA_TIME_BASE_8200
   // Support ZI, RW cache region
   #define DRV_MISC_CACHE_REGION_SUPPORT

   /*
     Define to force return PWRKEY power on
     This should only be enabled at DVT phase (Before driver ready) to avoiding block other tests
   */
   //#define DRV_MISC_PWIC_FORCE_RETURN_PWRKEY_POWERON

   /*
     Define to ignore ADC run state check (This is only for debug purpose, need to remove after fix)
   */
//   #define DRV_MISC_IGNORE_ADC_RUN_STATUS_CHECK

   /*
     Define to add ADC_GetData to internal RAM (This is only for debug purpose!!!!!Need to remove after fix)
   */
   #define DRV_MISC_ADD_ADC_GETDATA_TO_INTERNAL_RAM

   #define DRV_MISC_32KHZ_CALI_SM_WC

   /*
      Remove IRQ mask when performing ADC measurement
      ADC measurement are performed in HISR context(Timer hisr), except l1_adc_XXX APIs
      l1_adc_XXX is NOT used for a long time, and may not be enabled again
      When this feature is enabled, we add assert in l1_adc_XXX
   */
   #define DRV_MISC_ADC_MEASURE_REMOVE_IRQMASK

   /*
      MT6253 PMU related ADC channels start from 0, MT6253T PMU related ADC channels start from 3
   */
   #define DRV_MISC_PMU_ADC_CHANNEL_FROM_0
   #define DRV_MISC_ADC_FIXED_VBAT_WA

#elif defined(DRV_MISC_6236_SERIES)
   #define DRV_MISC_DMA_MEMCPY
   #define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_TIME_MAX_24BITS
   #define DRV_MISC_TDMA_TIME_BASE
   // Support ZI, RW cache region
   #define DRV_MISC_CACHE_REGION_SUPPORT

   /*
      Remove IRQ mask when performing ADC measurement
      ADC measurement are performed in HISR context(Timer hisr), except l1_adc_XXX APIs
      l1_adc_XXX is NOT used for a long time, and may not be enabled again
      When this feature is enabled, we add assert in l1_adc_XXX
   */
   #define DRV_MISC_ADC_MEASURE_REMOVE_IRQMASK

   /*
      MT6236 PMU related ADC channels start from 0, MT6253T PMU related ADC channels start from 3
   */
   #define DRV_MISC_PMU_ADC_CHANNEL_FROM_0

#elif defined(DRV_MISC_6255_SERIES)
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_TIME_MAX_24BITS
   #define DRV_MISC_TDMA_TIME_BASE

   // DVT phase development purpose only: Force to boot into IDLE
   //#define DRV_MISC_PWIC_FORCE_RETURN_PWRKEY_POWERON

#elif defined(DRV_MISC_6276_SERIES)
   //#define DRV_MISC_DMA_MEMCPY
   //#define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_L1_MACRO
   #define DRV_MISC_TDMA_TIME_MAX_32BITS
   /*
      Indicate the clock base is 15.36 MHz
   */
   #define DRV_MISC_CLOCK_BASE_1536
   /*
      Remove IRQ mask when performing ADC measurement
      ADC measurement are performed in HISR context(Timer hisr), except l1_adc_XXX APIs
      l1_adc_XXX is NOT used for a long time, and may not be enabled again
      When this feature is enabled, we add assert in l1_adc_XXX
   */
   #define DRV_MISC_ADC_MEASURE_REMOVE_IRQMASK

   /*
      MT6268A use 26MHz clock source to calibrate 32K
   */
   //#define DRV_MISC_USE_26MHZ_SRC_CALIBRATE_32KHZ_CLOCK

   //#define DRV_MISC_32KHZ_CALI_SM_WC

   // DVT phase development purpose only: Force to boot into IDLE
   //#define DRV_MISC_PWIC_FORCE_RETURN_PWRKEY_POWERON


#elif defined(DRV_MISC_6251_SERIES)
   #define DRV_MISC_DMA_MEMCPY
   //#define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_TIME_MAX_24BITS
   #define DRV_MISC_TDMA_TIME_BASE
   // Support ZI, RW cache region
   #define DRV_MISC_CACHE_REGION_SUPPORT

   /*
      Remove IRQ mask when performing ADC measurement
      ADC measurement are performed in HISR context(Timer hisr), except l1_adc_XXX APIs
      l1_adc_XXX is NOT used for a long time, and may not be enabled again
      When this feature is enabled, we add assert in l1_adc_XXX
   */
   #define DRV_MISC_ADC_MEASURE_REMOVE_IRQMASK

   /*
      MT6236 PMU related ADC channels start from 0, MT6253T PMU related ADC channels start from 3
   */
   #define DRV_MISC_PMU_ADC_CHANNEL_FROM_0

   // DVT phase development purpose only: Force to boot into IDLE
   //#define DRV_MISC_PWIC_FORCE_RETURN_PWRKEY_POWERON

#elif defined(DRV_MISC_6252_SERIES)
   #define DRV_MISC_DMA_MEMCPY
   //#define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_TIME_MAX_24BITS
   #define DRV_MISC_TDMA_TIME_BASE_8200
   // Support ZI, RW cache region
   #define DRV_MISC_CACHE_REGION_SUPPORT

   /*
     Define to force return PWRKEY power on
     This should only be enabled at DVT phase (Before driver ready) to avoiding block other tests
   */
   //#define DRV_MISC_PWIC_FORCE_RETURN_PWRKEY_POWERON

   /*
     Define to ignore ADC run state check (This is only for debug purpose, need to remove after fix)
   */
//   #define DRV_MISC_IGNORE_ADC_RUN_STATUS_CHECK

   /*
     Define to add ADC_GetData to internal RAM (This is only for debug purpose!!!!!Need to remove after fix)
   */
   #define DRV_MISC_ADD_ADC_GETDATA_TO_INTERNAL_RAM

   #define DRV_MISC_32KHZ_CALI_SM_WC

   /*
      Remove IRQ mask when performing ADC measurement
      ADC measurement are performed in HISR context(Timer hisr), except l1_adc_XXX APIs
      l1_adc_XXX is NOT used for a long time, and may not be enabled again
      When this feature is enabled, we add assert in l1_adc_XXX
   */
   #define DRV_MISC_ADC_MEASURE_REMOVE_IRQMASK

   /*
      MT6253 PMU related ADC channels start from 0, MT6253T PMU related ADC channels start from 3
   */
   #define DRV_MISC_PMU_ADC_CHANNEL_FROM_0

#elif defined(DRV_MISC_6573_SERIES)
   //#define DRV_MISC_DMA_MEMCPY
   //#define DRV_MISC_CHR_CTRL_GPIO
   #define DRV_MISC_TDMA_32K_CALI
   #define DRV_MISC_TDMA_L1_MACRO
   #define DRV_MISC_TDMA_TIME_MAX_32BITS
   /*
      Indicate the clock base is 15.36 MHz
   */
   #define DRV_MISC_CLOCK_BASE_1536
   /*
      Remove IRQ mask when performing ADC measurement
      ADC measurement are performed in HISR context(Timer hisr), except l1_adc_XXX APIs
      l1_adc_XXX is NOT used for a long time, and may not be enabled again
      When this feature is enabled, we add assert in l1_adc_XXX
   */
   #define DRV_MISC_ADC_MEASURE_REMOVE_IRQMASK

   /*
      MT6268A use 26MHz clock source to calibrate 32K
   */
   //#define DRV_MISC_USE_26MHZ_SRC_CALIBRATE_32KHZ_CLOCK

   //#define DRV_MISC_32KHZ_CALI_SM_WC

   // DVT phase development purpose only: Force to boot into IDLE
   //#define DRV_MISC_PWIC_FORCE_RETURN_PWRKEY_POWERON

   #define __DRV_NO_USB_CHARGER__
   #define __DRV_NO_CABLE_DETECTION__
   #define __DRV_NO_CHARGER__

#elif defined(DRV_MISC_6280_SERIES)
   #define DRV_MISC_TDMA_L1_MACRO
   #define DRV_MISC_TDMA_TIME_MAX_32BITS
#elif defined(DRV_MISC_6290_SERIES)
   #ifdef __LTE_SM__
       //#define DRV_MISC_TDMA_NO_TIME
   #endif /* end of __LTE_SM__ */
   #define DRV_EMIMPU
   #define DRV_MISC_TOPSM_32K_RTC
#elif defined(DRV_MISC_6595_SERIES)
   #define DRV_MISC_TOPSM_32K_RTC
#endif

#endif   /*End __DRV_FEATURES_MISC_H__*/
