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
 * ephy_rf_custom_data.h
 *
 * Project:
 * --------
 * MT6290
 *
 * Description:
 * ------------
 * EL1 RF Custom Data
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef  _EPHY_RF_CUSTOM_DATA_H_
#define  _EPHY_RF_CUSTOM_DATA_H_

/*===============================================================================*/
#include "el1_rf_public.h"

/*===============================================================================*/
#define LTE_Band_PDATA_PR1(b)        PDATA_##b##_PR1
#define LTE_PDATA_PR1(b)             LTE_Band_PDATA_PR1(b)

#define LTE_Band_PDATA_PR2(b)        PDATA_##b##_PR2
#define LTE_PDATA_PR2(b)             LTE_Band_PDATA_PR2(b)

#define LTE_Band_PDATA_PR3(b)        PDATA_##b##_PR3
#define LTE_PDATA_PR3(b)             LTE_Band_PDATA_PR3(b)

#define LTE_Band_PDATA_PT1(b)        PDATA_##b##_PT1
#define LTE_PDATA_PT1(b)             LTE_Band_PDATA_PT1(b)

#define LTE_Band_PDATA_PT2(b)        PDATA_##b##_PT2
#define LTE_PDATA_PT2(b)             LTE_Band_PDATA_PT2(b)

#define LTE_Band_PDATA_PT3(b)        PDATA_##b##_PT3
#define LTE_PDATA_PT3(b)             LTE_Band_PDATA_PT3(b)

#define LTE_Band_PDATA_PR1_2(b)      PDATA_##b##_2_PR1
#define LTE_PDATA_PR1_2(b)           LTE_Band_PDATA_PR1_2(b)

#define LTE_Band_PDATA_PR2_2(b)      PDATA_##b##_2_PR2
#define LTE_PDATA_PR2_2(b)           LTE_Band_PDATA_PR2_2(b)

#define LTE_Band_PDATA_PR3_2(b)      PDATA_##b##_2_PR3
#define LTE_PDATA_PR3_2(b)           LTE_Band_PDATA_PR3_2(b)

#define LTE_Band_PDATA_PT1_2(b)      PDATA_##b##_2_PT1
#define LTE_PDATA_PT1_2(b)           LTE_Band_PDATA_PT1_2(b)

#define LTE_Band_PDATA_PT2_2(b)      PDATA_##b##_2_PT2
#define LTE_PDATA_PT2_2(b)           LTE_Band_PDATA_PT2_2(b)

#define LTE_Band_PDATA_PT3_2(b)      PDATA_##b##_2_PT3
#define LTE_PDATA_PT3_2(b)           LTE_Band_PDATA_PT3_2(b)

#define LTE_Band_PDATA_PR1_3(b)      PDATA_##b##_3_PR1
#define LTE_PDATA_PR1_3(b)           LTE_Band_PDATA_PR1_3(b)

#define LTE_Band_PDATA_PR2_3(b)      PDATA_##b##_3_PR2
#define LTE_PDATA_PR2_3(b)           LTE_Band_PDATA_PR2_3(b)

#define LTE_Band_PDATA_PR3_3(b)      PDATA_##b##_3_PR3
#define LTE_PDATA_PR3_3(b)           LTE_Band_PDATA_PR3_3(b)

#define LTE_Band_PDATA_PT1_3(b)      PDATA_##b##_3_PT1
#define LTE_PDATA_PT1_3(b)           LTE_Band_PDATA_PT1_3(b)

#define LTE_Band_PDATA_PT2_3(b)      PDATA_##b##_3_PT2
#define LTE_PDATA_PT2_3(b)           LTE_Band_PDATA_PT2_3(b)

#define LTE_Band_PDATA_PT3_3(b)      PDATA_##b##_3_PT3
#define LTE_PDATA_PT3_3(b)           LTE_Band_PDATA_PT3_3(b)

#define LTE_Band_PDATA_PR1_BYPASS(b) PDATA_##b##_BYPASS_PR1
#define LTE_PDATA_PR1_BYPASS(b)      LTE_Band_PDATA_PR1_BYPASS(b)

#define LTE_Band_PDATA_PR2_BYPASS(b) PDATA_##b##_BYPASS_PR2
#define LTE_PDATA_PR2_BYPASS(b)      LTE_Band_PDATA_PR2_BYPASS(b)

#define LTE_Band_PDATA_PR3_BYPASS(b) PDATA_##b##_BYPASS_PR3
#define LTE_PDATA_PR3_BYPASS(b)      LTE_Band_PDATA_PR3_BYPASS(b)

#define LTE_Band_PDATA_PT1_BYPASS(b) PDATA_##b##_BYPASS_PT1
#define LTE_PDATA_PT1_BYPASS(b)      LTE_Band_PDATA_PT1_BYPASS(b)

#define LTE_Band_PDATA_PT2_BYPASS(b) PDATA_##b##_BYPASS_PT2
#define LTE_PDATA_PT2_BYPASS(b)      LTE_Band_PDATA_PT2_BYPASS(b)

#define LTE_Band_PDATA_PT3_BYPASS(b) PDATA_##b##_BYPASS_PT3
#define LTE_PDATA_PT3_BYPASS(b)      LTE_Band_PDATA_PT3_BYPASS(b)

#define LTE_Band_PDATA_TAS1(b)       PDATA_##b##_TAS1
#define LTE_PDATA_TAS1(b)            LTE_Band_PDATA_TAS1(b)

#define LTE_Band_PDATA_TAS2(b)       PDATA_##b##_TAS2
#define LTE_PDATA_TAS2(b)            LTE_Band_PDATA_TAS2(b)

#define LTE_Band_PDATA_TAS3(b)       PDATA_##b##_TAS3
#define LTE_PDATA_TAS3(b)            LTE_Band_PDATA_TAS3(b)

#define LTE_Band_PDATA_TAS4(b)       PDATA_##b##_TAS4
#define LTE_PDATA_TAS4(b)            LTE_Band_PDATA_TAS4(b)

#define LTE_Band_PDATA_TAS5(b)       PDATA_##b##_TAS5
#define LTE_PDATA_TAS5(b)            LTE_Band_PDATA_TAS5(b)

#define LTE_Band_PDATA_TAS6(b)       PDATA_##b##_TAS6
#define LTE_PDATA_TAS6(b)            LTE_Band_PDATA_TAS6(b)

#define LTE_Band_PDATA_TAS7(b)       PDATA_##b##_TAS7
#define LTE_PDATA_TAS7(b)            LTE_Band_PDATA_TAS7(b)

#define LTE_Band_RX_IO(b)            b##_RX_IO_SEL
#define LTE_RX_IO(b)                 LTE_Band_RX_IO(b)

#define LTE_Band_RXD_IO(b)           b##_RXD_IO_SEL
#define LTE_RXD_IO(b)                LTE_Band_RXD_IO(b)

#define LTE_Band_TX_IO(b)            b##_TX_IO_SEL
#define LTE_TX_IO(b)                 LTE_Band_TX_IO(b)

#define LTE_Band_RX_2_IO(b)          b##_2_RX_IO_SEL
#define LTE_RX_2_IO(b)               LTE_Band_RX_2_IO(b)

#define LTE_Band_RXD_2_IO(b)         b##_2_RXD_IO_SEL
#define LTE_RXD_2_IO(b)              LTE_Band_RXD_2_IO(b)

#define LTE_Band_TX_2_IO(b)          b##_2_TX_IO_SEL
#define LTE_TX_2_IO(b)               LTE_Band_TX_2_IO(b)

#define LTE_Band_RX_3_IO(b)          b##_3_RX_IO_SEL
#define LTE_RX_3_IO(b)               LTE_Band_RX_3_IO(b)

#define LTE_Band_RXD_3_IO(b)         b##_3_RXD_IO_SEL
#define LTE_RXD_3_IO(b)              LTE_Band_RXD_3_IO(b)

#define LTE_Band_TX_3_IO(b)          b##_3_TX_IO_SEL
#define LTE_TX_3_IO(b)               LTE_Band_TX_3_IO(b)

#define LTE_Band_RX_BYPASS_IO(b)     b##_BYPASS_RX_IO_SEL
#define LTE_RX_BYPASS_IO(b)          LTE_Band_RX_BYPASS_IO(b)

#define LTE_Band_RXD_BYPASS_IO(b)    b##_BYPASS_RXD_IO_SEL
#define LTE_RXD_BYPASS_IO(b)         LTE_Band_RXD_BYPASS_IO(b)

#define LTE_Band_TX_BYPASS_IO(b)     b##_BYPASS_TX_IO_SEL
#define LTE_TX_BYPASS_IO(b)          LTE_Band_TX_BYPASS_IO(b)

#define LTE_Band_MPR_QPSK1(b)        b##_MPR_QPSK1
#define LTE_MPR_QPSK1(b)             LTE_Band_MPR_QPSK1(b)

#define LTE_Band_MPR_16QAM0(b)       b##_MPR_16QAM0
#define LTE_MPR_16QAM0(b)            LTE_Band_MPR_16QAM0(b)

#define LTE_Band_MPR_16QAM1(b)       b##_MPR_16QAM1
#define LTE_MPR_16QAM1(b)            LTE_Band_MPR_16QAM1(b)

#define LTE_Band_DELTA_TC0(b)        b##_DELTA_TC0
#define LTE_DELTA_TC0(b)             LTE_Band_DELTA_TC0(b)

#define LTE_Band_DELTA_TC1(b)        b##_DELTA_TC1
#define LTE_DELTA_TC1(b)             LTE_Band_DELTA_TC1(b)

#define LTE_Band_AMPR_NS(b)          b##_AMPR_NS
#define LTE_AMPR_NS(b)               LTE_Band_AMPR_NS(b)

#define LTE_Band_AMPR_NS_DEF(b)      b##_AMPR_NS_DEF
#define LTE_AMPR_NS_DEF(b)           LTE_Band_AMPR_NS_DEF(b)

/* Transmit Antenna Selection feature usage */
#define LTE_TAS_BPI_PIN_GEN(var1, var2, var3) ( (LTE_TAS_PIN1==LTE_TAS_PIN_NULL?0:(var1<<LTE_TAS_PIN1))|\
                                                (LTE_TAS_PIN2==LTE_TAS_PIN_NULL?0:(var2<<LTE_TAS_PIN2))|\
                                                (LTE_TAS_PIN3==LTE_TAS_PIN_NULL?0:(var3<<LTE_TAS_PIN3)) )

/* DSDA Dual Talk feature usage */
#if defined(__DCS_TX_NOTCH_SWITCH_SUPPORT__)
   #define IS_DSDA_PROVIDE_RX_STATUS_TO_GSM_ENABLE   1
#else
   #define IS_DSDA_PROVIDE_RX_STATUS_TO_GSM_ENABLE   0
#endif

#if defined(__LTE_TX_PATH_SWITCH_SUPPORT__)
   #define IS_DSDA_LTE_TX_FILTER_PATH_SWITCH_ENABLE   1
#else
   #define IS_DSDA_LTE_TX_FILTER_PATH_SWITCH_ENABLE   0
#endif

typedef struct
{
   kal_int16 fsr0;
   kal_int16 fsr1;
   kal_int16 fsr2;
   kal_int16 tsr0;
   kal_int16 tsr2;
   kal_int16 sr2g;
   kal_int16 sr2s;
   kal_int16 sr2f;
}ERF_RXON_BSIOFFSET_T;

typedef struct
{
   kal_int16 fsr3;
   kal_int16 tsr3;
}ERF_RXOFF_BSIOFFSET_T;

typedef struct
{
   kal_int16 fst0;
   kal_int16 fst1;
   kal_int16 fst2;
   kal_int16 tst2;
   kal_int16 st2s;
   kal_int16 st2f;
}ERF_TXON_BSIOFFSET_T;

typedef struct
{
   kal_int16 fst3;
   kal_int16 tst3;
}ERF_TXOFF_BSIOFFSET_T;

typedef struct      
{                   
   kal_int16 stx1;  
   kal_int16 stx3;  
   kal_int16 srx1;  
   kal_int16 srx3;  
}ERF_SXCTRL_OFFSET_T;

typedef struct
{
   kal_int16 stpc0;  
   kal_int16 stpc1;
   kal_int16 sptpc0;
   kal_int16 sptpc1;
   kal_int16 smtpc0;
   kal_int16 smtpc1;
   kal_int16 ptpc0;
   kal_int16 ptpc1;                     
}ERF_TPC_OFFSET_T;

/*===============================================================================*/

extern ERF_RXON_BSIOFFSET_T   ERF_RXON_BSIOFFSET_TABLE;
extern ERF_RXOFF_BSIOFFSET_T  ERF_RXOFF_BSIOFFSET_TABLE;
extern ERF_TXON_BSIOFFSET_T   ERF_TXON_BSIOFFSET_TABLE;
extern ERF_TXOFF_BSIOFFSET_T  ERF_TXOFF_BSIOFFSET_TABLE;
extern ERF_SXCTRL_OFFSET_T ERF_SXCTRL_OFFSET_TABLE;
extern ERF_TPC_OFFSET_T    ERF_TPC_OFFSET_TABLE;


/* DRDI feature usage */
extern const ERF_RX_PDATABASE_T ERF_RX_PDATABASE_BandNone;
extern const ERF_TX_PDATABASE_T ERF_TX_PDATABASE_BandNone;
extern const ERF_IOBASE_T       ERF_RF_IOBASE_BandNone; 

/******************************************************************************
 * Dynamic Radio-setting Dedicated Image
 *
 * Description: extern global variables for EPHY calculation
 ******************************************************************************/
extern kal_uint16 LTE_DRDI_STATUS;
extern kal_uint8  el1_custom_debug_enable;
extern kal_uint8  el1_custom_gpio_set_nums;
extern kal_uint8  el1_custom_adc_set_nums;
extern kal_uint8  el1_custom_nvram_barcode_set_nums;
extern kal_uint8  el1_custom_gpio_nums_in_calc;
extern kal_uint8  el1_custom_ADC_nums_in_calc;
extern kal_uint8  el1_custom_barcode_nums_in_calc;
extern kal_uint8  el1_custom_first_index;
extern kal_uint8  el1_custom_second_index;
extern kal_uint8  el1_custom_third_index;
extern kal_uint8  el1_custom_first_index_base;
extern kal_uint8  el1_custom_gpio_num_of_detect_pins_in_use;
extern kal_uint8  el1_custom_adc_level_total;
extern kal_uint8  el1_custom_barcode_read_digit_num;
extern kal_uint8  el1_custom_barcode_digit_value_1;
extern kal_uint8  el1_custom_barcode_digit_value_2;
extern kal_uint8  el1_custom_barcode_digit_value_3;
extern kal_uint8  el1_custom_max_rf_support_band_num;
extern kal_uint8  el1_custom_adc_calibrate_enable;
extern kal_uint8  el1_custom_adc_bits;
extern kal_uint16 el1_custom_adc_meas_count_2_order;
extern kal_uint16 el1_custom_total_set_nums;
extern kal_uint32 el1_custom_adc_max_input_voltage;
extern kal_uint16 DISABLE_BAND_INFO_ENABLE;
/*------------- Dynamic Radio-setting Dedicated Image -------------*/


#endif //_EPHY_RF_CUSTOM_DATA_H_
