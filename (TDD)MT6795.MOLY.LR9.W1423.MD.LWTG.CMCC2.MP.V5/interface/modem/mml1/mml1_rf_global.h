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
 *	mml1_rf_global.h
 *
 * Project:
 * --------
 * MT6290
 *
 * Description:
 * ------------
 * Multi-Mode RF Central global define
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
 *
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef  _MML1_RF_GLOBAL_H_
#define  _MML1_RF_GLOBAL_H_

/*===============================================================================*/

#include "kal_general_types.h"
#include "dcl.h"                 //DRDI usage
/*===============================================================================*/

#define LTE_RFD_MT6169RF_E1                      0x1
#define LTE_RFD_MT6169RF_E2                      0x2
#define LTE_RFD_MT6169RF_E3                      0x3

#define LTE_TARGET_SUPPORT_BAND_NUM              14
#define LTE_TARGET_MAX_SUPPORT_BAND_NUM          14

#define LTE_RFC_TXGA_NUM_CBW_CASE               (12)
#define LTE_RFC_TXGA_NUM_BANDWIDTH_CASE          (3)
#define LTE_RFC_TXGA_NUM_COMP_FILTER_TAP         (7)
#define LTE_RFC_TXGA_NUM_TEST_TONE               (6)
#define LTE_RFC_TXGA_NUM_SLOPE_RESULT           (LTE_RFC_TXGA_NUM_TEST_TONE - 1)

#define LTE_RFC_DETIQDCDNL_DETGAIN_TAB_SIZE     (16)
#define LTE_RFC_TXIQDCDNL_TXGAIN_TAB_SIZE       (30)
#define LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND   (LTE_TARGET_MAX_SUPPORT_BAND_NUM)
#define LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BANDWIDTH   (6)
#define LTE_RFC_CURRENT_NUM_OF_SUPPORTED_OTHER_RAT_BAND (6)

#define LTE_RFC_RXIQ_NUM_COMP_FILTER_TAP         (7)
#define LTE_RFC_RXIQ_NUM_TIA_CB_GAIN_STEPS       (4)
#define LTE_RFC_RXIQ_NUM_PGA_GAIN_STEPS          (6)

// Factory Mode Capability Multi-RAT Bitmap
#define MML1_NULL      0x00000000
#define MML1_GSM       0x00000001
#define MML1_WCDMA     0x00000002
#define MML1_TDSCDMA   0x00000004
#define MML1_FDDLTE    0x00000008
#define MML1_TDDLTE    0x00000010
#define MML1_CDMA2K    0x00000020

typedef struct
{
   kal_uint16 CBW;

   /* For frequency-domain compensation - only for LTE */
   kal_int16 txga_slope_result[LTE_RFC_TXGA_NUM_BANDWIDTH_CASE][LTE_RFC_TXGA_NUM_SLOPE_RESULT];

   /* Time-domain compensation filter tap */
   kal_int16  txga_comp_filter_tap[LTE_RFC_TXGA_NUM_CBW_CASE][LTE_RFC_TXGA_NUM_COMP_FILTER_TAP];
   kal_uint16 data_valid;

   /* For frequency-domain compensation - only for LTE */
   kal_int16 txga_tone_pwr[LTE_RFC_TXGA_NUM_BANDWIDTH_CASE][LTE_RFC_TXGA_NUM_TEST_TONE]; // in dB unit
   kal_uint16 txga_cal_freq[LTE_RFC_TXGA_NUM_BANDWIDTH_CASE][LTE_RFC_TXGA_NUM_TEST_TONE]; // in RB uint
   kal_uint16 rsv; // padding byets for 4-byte alignment
}RFC_TXGA_COMP_T;

typedef struct
{
	kal_int16 rxiq_gain_mismatch_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BANDWIDTH];
	kal_int16 rxiq_phase_mismatch_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BANDWIDTH];
	kal_int16 rxiq_filter_coef[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BANDWIDTH][LTE_RFC_RXIQ_NUM_COMP_FILTER_TAP]; /*Lagrange filter*/
}RFC_RXIQ_COMP_T;

typedef struct
{
	kal_int16 txiq_gain_mismatch_comp;
	kal_int16 txiq_phase_mismatch_comp;
	kal_int16 txiq_real_dc_comp;
	kal_int16 txiq_image_dc_comp;
}RFC_TXIQ_COMP_T;

typedef struct
{
   kal_uint32  poc_data_status;

   /* Band number storage of calibration data band index */
   kal_uint32 band_idx_to_band_num_table[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND];

   /*RX IQ Gain, phase mismatch for each band*/
   RFC_RXIQ_COMP_T rx1iq_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND];
   RFC_RXIQ_COMP_T rx2iq_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND];

   /*RX DCOC for each band*/
   kal_int16  rx1iq_re_dc[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_RXIQ_NUM_TIA_CB_GAIN_STEPS][LTE_RFC_RXIQ_NUM_PGA_GAIN_STEPS];
   kal_int16  rx1iq_im_dc[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_RXIQ_NUM_TIA_CB_GAIN_STEPS][LTE_RFC_RXIQ_NUM_PGA_GAIN_STEPS];
   kal_int16  rx2iq_re_dc[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_RXIQ_NUM_TIA_CB_GAIN_STEPS][LTE_RFC_RXIQ_NUM_PGA_GAIN_STEPS];
   kal_int16  rx2iq_im_dc[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_RXIQ_NUM_TIA_CB_GAIN_STEPS][LTE_RFC_RXIQ_NUM_PGA_GAIN_STEPS];

   /*DET IQ Gain,phase mismatch & DC for each band*/
   kal_int16  detiq_gain_mismatch_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_DETIQDCDNL_DETGAIN_TAB_SIZE];
   kal_int16  detiq_phase_mismatch_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_DETIQDCDNL_DETGAIN_TAB_SIZE];
   kal_int16  detiq_real_dc_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_DETIQDCDNL_DETGAIN_TAB_SIZE];
   kal_int16  detiq_image_dc_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_DETIQDCDNL_DETGAIN_TAB_SIZE];

   /* DET DNL (FE + PGA gain) for each band */
   kal_int16   det_gain_table[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_DETIQDCDNL_DETGAIN_TAB_SIZE];

   /* tx_rcf_csel[0]: C_SEL for C value = b11, tx_rcf_csel[0]: C_SEL for C value = b00 */
   kal_int16 tx_rcf_csel[2];

   /*TX IQ Gain, phase mismatch & DC for each band*/
   RFC_TXIQ_COMP_T txiq_gain_phase_dc_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_TXIQDCDNL_TXGAIN_TAB_SIZE];

   /* TX DNL for each band */
   kal_int16 tx_gain_table[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][LTE_RFC_TXIQDCDNL_TXGAIN_TAB_SIZE];

   /* TX GA compensation data for each band */
   RFC_TXGA_COMP_T tx_ga_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND];

   /* det_coarse_dcoc[0]: RF CW data for TXDET_CDCOC_I1_M, TXDET_CDCOC_Q1_M, TXDET_CDCOC_I2_M, TXDET_CDCOC_Q2_M */
   /* det_coarse_dcoc[1]: RF CW data for TXDET_CDCOC_I3_M, TXDET_CDCOC_Q3_M, TXDET_CDCOC_I4_M, TXDET_CDCOC_Q4_M */
   /* CW address is included in the data */
   kal_uint32 det_coarse_dcoc[2];

   /* DET FE DNL for each band
    * det_fe_gain_table[][0]: DET FE Middle gain mode, det_fe_gain_table[][0]: DET FE Low gain mode
    */
   kal_uint32  det_fe_gain_table[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND];

   /* Only for 3G - 5th gain step of Tx IQ imbalance calibration result for each band */
   kal_int32 txiq_gain_mismatch_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND];
   kal_int32 txiq_phase_mismatch_comp[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND];

}RFC_DATABASE_T;

typedef enum
{
   MML1_RF_2G      = 0x0001,
   MML1_RF_3G_FDD  = 0x0002,
   MML1_RF_3G_TDD  = 0x0004,
   MML1_RF_LTE     = 0x0008,
}MML1_RF_RAT_T;

typedef enum
{
   MML1_RF_MT6169  = 0x0001,
   MML1_RF_MT6166  = 0x0002,
   MML1_RF_MT6165  = 0x0003,
   MML1_RF_MAX     = 0xFFFE,
}MML1_RF_CHIP_T;

typedef enum
{
   MML1_RF_RFIC1   = 0x0001,
   MML1_RF_RFIC2   = 0x0002,
}MML1_RF_RFIC_INFO_T;

/*******************************************************************************
 * DRDI parameters for MML1 driver                                             *
 * Define compile options, data structure, and MACRO for MML1 DRDI             *
 *******************************************************************************/

/****** DRDI of MML1: COMPILE OPTIONS ******/
/* new method to check barcode digits */
#define MML1_RF_DRDI_BARCODE_DET                      0

/* GPIO/ADC CCCI common interface */
#define MML1_RF_DRDI_CCCI_GPIOADC_COMMON_IF_SUPPORT   1

/****** DRDI of MML1: PARAMETERS ******/
/* max number of GPIO detection pin names defined so far at AP side GPIO driver */
#define MML1_RF_DRDI_GPIO_MAX_DETECT_PIN_NUM       (3)  

/* length of GPIO detection pin name in use, set to the maximum string length *
 *(including null-terminated character) among the GPIO pin names in use       */
#define MML1_RF_DRDI_GPIO_PIN_NAME_STRING_LENGTH   (34)

/* Constant to be used to determine the length of ADC detection channel name in use */
#define MML1_RF_DRDI_ADC_CH_NAME_STRING_LENGTH     (33)

/* Constant to be used to define the value to be used in enumeration Mml1CustomActionId */
#define MML1_CUSTOM_NULL_ACTION_ID         (0)
#define MML1_CUSTOM_GPIO_DETECTION_ID      (1)
#define MML1_CUSTOM_ADC_DETECTION_ID       (2)
#define MML1_CUSTOM_BARCODE_DETECTION_ID   (3)


/****** DRDI of MML1: DATA STRUCTURE DEFINITION ******/
/* Internal typedef used by MML1 Custom action function prototype */
typedef kal_uint16 (*Mml1CustomFunction)(void *usrDataPtr);

/* Internal typedef used by MML1 Custom action ID constant value */
typedef enum
{
   MML1_CUSTOM_NULL_ACTION       = MML1_CUSTOM_NULL_ACTION_ID,
   MML1_CUSTOM_BASE_PROC_ACTION  = MML1_CUSTOM_NULL_ACTION_ID,
   MML1_CUSTOM_GPIO_DETECTION    = MML1_CUSTOM_GPIO_DETECTION_ID,
   MML1_CUSTOM_ADC_DETECTION     = MML1_CUSTOM_ADC_DETECTION_ID,
   MML1_CUSTOM_BARCODE_DETECTION = MML1_CUSTOM_BARCODE_DETECTION_ID,
   MML1_CUSTOM_MAX_PROC_ACTIONS
} Mml1CustomActionId;


/*****************************************************************************************
* Macro       : M_Mml1CustomExecuteAction
* Group       : Real target, Internals, MML1 common operation
* Parameter   : \aCTIONiDNone = Identifies the action to execute
*               \uSRdATApTR = pointer to user input data for action function
* Returns     : Nothing
* Description : Generic function to run any action for MML1 Custom mechanism
*****************************************************************************************/
#define M_Mml1CustomExecuteAction(aCTIONiD, uSRdATApTR, rESULTpTR)  \
        {                                                \
           ASSERT( (((aCTIONiD) - MML1_CUSTOM_BASE_PROC_ACTION) < MML1_CUSTOM_MAX_PROC_ACTIONS) );  \
           if( (mml1CustomActionTable[(aCTIONiD) - MML1_CUSTOM_BASE_PROC_ACTION] != NULL) )  \
           {  \
              *(rESULTpTR) += mml1CustomActionTable[(aCTIONiD) - MML1_CUSTOM_BASE_PROC_ACTION](uSRdATApTR);  \
           }  \
        }



/***********************************************************
 * Data Structure Definition                               *
 ***********************************************************/
/* data structure used for GPIO read API */
typedef struct
{
   kal_int32  gpio_get_pin_rpc_status;
   kal_int16  gpio_return_pin_num[MML1_RF_DRDI_GPIO_MAX_DETECT_PIN_NUM];
   kal_uint32 gpio_pin_value[MML1_RF_DRDI_GPIO_MAX_DETECT_PIN_NUM];
   kal_uint32 gpio_combined_pin_value;                                  
}Mml1RfDrdiGpioResult;

/* data structure for GPIO detestion HW setting mechanism */
typedef struct
{
   /* Null-terminated string to record the GPIO *
    * pin name for detection HW settings        */
   kal_char    gpioPinNameString[MML1_RF_DRDI_GPIO_PIN_NAME_STRING_LENGTH];

   /* Record the detected GPIO detection pin number */
   kal_uint32  gpioPinNum;

   /* Record the GPIO detection pin value of the corresponding *
    * GPIO pin number (mapped by GPIO pin name)                */
   kal_uint32  gpioReadPinValue;
} Mml1RfDrdiGpioGetPinValueInfo;

/* data structure used for ADC read API */
typedef struct
{
   /* ADC input parameters */
   kal_uint16 adcMeasCountOrder;
   kal_uint32 adcMaxVolt;
   kal_uint16 adcBit;

   kal_int32  adc_get_ch_num_rpc_status;
   DCL_STATUS adc_dcl_handle_status;
   kal_uint32 adc_get_ch_num;
   kal_uint32 adc_dac_read_result;
   kal_uint32 adc_volt_translate_result;  // uV
}Mml1RfDrdiAdcResult;

/* data structure used for BARCODE read API */
typedef struct
{
   //input params
   kal_uint8  barcode_read_digit_num;
   kal_uint8  barcode_digit_value_2;
   kal_uint8  barcode_digit_value_3;   
   kal_uint8  barcode_num_in_calc;
   kal_char  *barcode_digits;

   //result
   kal_bool   barcode_lid_read_status;
   kal_uint8  barcode_digit_read_result;
   kal_uint8  barcode_asm_digit_no;
}Mml1RfDrdiBarcodeResult;


/* data structure to save custom parameters of MML1 custom folder (DO NOT MODIFY) */
typedef struct
{
   kal_uint8  mml1_custom_debug_enable;                   //= MML1_CUSTOM_DEBUG_ENABLE;
   kal_uint8  mml1_custom_gpio_set_nums;                  //= MML1_CUSTOM_GPIO_SET_NUMS;            
   kal_uint8  mml1_custom_adc_set_nums;                   //= MML1_CUSTOM_ADC_SET_NUMS;             
   kal_uint8  mml1_custom_nvram_barcode_set_nums;         //= MML1_CUSTOM_BARCODE_SET_NUMS;   
   kal_uint8  mml1_custom_gpio_nums_in_calc;              //= MML1_CUSTOM_GPIO_NUMS_IN_CALC;
   kal_uint8  mml1_custom_ADC_nums_in_calc;               //= MML1_CUSTOM_ADC_NUMS_IN_CALC;
   kal_uint8  mml1_custom_barcode_nums_in_calc;           //= MML1_CUSTOM_BARCODE_NUMS_IN_CALC;
   kal_uint8  mml1_custom_first_index;                    //= MML1_CUSTOM_FIRST_INDEX;
   kal_uint8  mml1_custom_second_index;                   //= MML1_CUSTOM_SECOND_INDEX;
   kal_uint8  mml1_custom_third_index;                    //= MML1_CUSTOM_THIRD_INDEX;
   kal_uint8  mml1_custom_first_index_base;               //= MML1_CUSTOM_FIRST_INDEX_BASE;
   kal_uint8  mml1_custom_gpio_num_of_detect_pins_in_use; //= MML1_CUSTOM_GPIO_NUM_OF_DETECT_PINS_IN_USE;
   kal_uint8  mml1_custom_adc_level_total;                //= MML1_CUSTOM_ADC_LEVEL_TOTAL;
   kal_uint8  mml1_custom_barcode_read_digit_num;         //= MML1_CUSTOM_BARCODE_READ_DIGIT_NUM;
   kal_uint8  mml1_custom_barcode_digit_value_1;          //= MML1_CUSTOM_BARCODE_DIGIT_VALUE_1;
   kal_uint8  mml1_custom_barcode_digit_value_2;          //= MML1_CUSTOM_BARCODE_DIGIT_VALUE_2;
   kal_uint8  mml1_custom_barcode_digit_value_3;          //= MML1_CUSTOM_BARCODE_DIGIT_VALUE_3;
   kal_uint8  mml1_custom_adc_calibrate_enable;           //= MML1_CUSTOM_ADC_CALIBRATE_ENABLE;
   kal_uint8  mml1_custom_adc_bits;                       //= MML1_CUSTOM_ADC_BITS;
   kal_uint16 mml1_custom_adc_meas_count_2_order;         //= MML1_CUSTOM_ADC_MEAS_COUNT_2_ORDER;
   kal_uint16 mml1_custom_total_set_nums;                 //= MML1_CUSTOM_TOTAL_SET_NUMS;
   kal_uint32 mml1_custom_adc_max_input_voltage;          //= MML1_CUSTOM_ADC_MAX_INPUT_VOLTAGE;
}Mml1RfDrdiCustomParam;

/* data structure to record GPIO, ADC, and Barcode debug information */
typedef struct
{
   kal_uint16 combined_config_index;
   kal_uint8  first_config_index_base;
   kal_uint8  second_config_index_base;
   kal_uint8  third_config_index_base;
   
   kal_int32  gpio_get_pin_rpc_status;
   kal_uint32 gpio_return_pin_num[MML1_RF_DRDI_GPIO_MAX_DETECT_PIN_NUM];
   kal_uint32 gpio_pin_value[MML1_RF_DRDI_GPIO_MAX_DETECT_PIN_NUM];
   kal_uint32 gpio_combined_pin_value;
   kal_int32  adc_get_ch_num_rpc_status;
   DCL_STATUS adc_dcl_handle_status;
   DCL_STATUS adc_cal_dcl_handle_status;
   kal_uint32 adc_get_ch_num;
   kal_uint32 adc_dac_read_result;
   kal_uint32 adc_volt_translate_result;
   kal_uint8  adc_volt_level;
   kal_bool   barcode_lid_read_status;
   kal_uint8  barcode_digit_read_result;
}Mml1RfDidiDynamicInitDebug;

/* data structure to collect all info by MML1 */
typedef struct
{
   /* Configuration index used for indexing the configuration sets to be modified
    * (passing through the index calculating function MML1_CUSTOM_DynamicInitConfigIdxCalc()
    * for all mechanisms in use and get the result stored in this global variable) */
   kal_uint16 mml1_custom_CombinedConfigIdx;

   /* Configuration index Bases used for calculating the combined index for indexing
    * configuration sets to be modified in the case of combined detections
    * First index base is either 1 or 0 so decide it at pre-compile time */
   kal_uint16 mml1_custom_FirstIdxBase;
   kal_uint16 mml1_custom_SecondIdxBase;
   kal_uint16 mml1_custom_ThirdIdxBase;

   /* ADC, GPIO, and Barcode debug info. */
   Mml1RfDidiDynamicInitDebug   mml1_dyn_init_dbg_info;

   /* parameters from mml1_custom_drdi.h *
    * This structure will be updated by MML1_CUSTOM_GET_CUSTOM_PARAM */
   Mml1RfDrdiCustomParam        mml1_custom_param;
} Mml1RfDrdiDynamicInitParam;

/* Data structure for IPC RPC API input/output */
#ifdef __MTK_TARGET__
PRAGMA_BEGIN_PACK_STRUCT
#endif
typedef struct
{
   /**
    * reqMask: provide request of GPIO/ADC GetPin/Value
    * [0]: 1: get GPIO pin number
    * [1]: 1: get GPIO pin value
    * [2]: reserved
    * [3]: reserved
    * [4]: 1: get ADC channel number
    * [5]: 1: get ADC channel measurement result
    * [6]: reserved
    * [7]: reserved
    */
   kal_uint8  reqMask;

   /* Indicate valid GPIO pin */
   kal_uint8  gpioValidPinMask; //Example: gpioValidPinMask = 0x07=0b 0000 0111

   /* GPIO/ADC input parameters */
   //reqMask[0]
   kal_uint8  gpioPinName[MML1_RF_DRDI_GPIO_MAX_DETECT_PIN_NUM][MML1_RF_DRDI_GPIO_PIN_NAME_STRING_LENGTH]; //[3][34]

   //reqMask[1]
   kal_uint32 gpioPinNum[MML1_RF_DRDI_GPIO_MAX_DETECT_PIN_NUM];  //[3]

   //reqMask[4]
   kal_uint8  adcChName[MML1_RF_DRDI_ADC_CH_NAME_STRING_LENGTH]; //[33]

   //reqMask[5]
   kal_uint32 adcChNum;
   kal_uint32 adcChMeasCount;
}Mml1RfDrdiIpcRpcGpioAdcInput;
#ifdef __MTK_TARGET__
PRAGMA_END_PACK_STRUCT
#endif

/* Data structure for IPC RPC API output */
#ifdef __MTK_TARGET__
PRAGMA_BEGIN_PACK_STRUCT
#endif
typedef struct
{
   /* GPIO/ADC output parameters */
   //reqMask[0]
   kal_uint32 gpioPinNum[MML1_RF_DRDI_GPIO_MAX_DETECT_PIN_NUM];   //[3]

   //reqMask[1]
   kal_uint32 gpioPinValue[MML1_RF_DRDI_GPIO_MAX_DETECT_PIN_NUM]; //[3]

   //reqMask[4]
   kal_uint32 adcChNum;

   //reqMask[5]
   kal_uint32 adcChMeasSum;
}Mml1RfDrdiIpcRpcGpioAdcOutput;
#ifdef __MTK_TARGET__
PRAGMA_END_PACK_STRUCT
#endif

/***********************************************************
 * Extern Variables                                        *
 ***********************************************************/
extern const Mml1CustomFunction mml1CustomActionTable[MML1_CUSTOM_MAX_PROC_ACTIONS];
extern kal_uint32               mml1_custom_adc_volt_to_lvl[][2];   //@ mml1_custom_drdi.c
extern kal_char                 mml1_custom_barcode_digits[];       //@ mml1_custom_drdi.c

/******** END of DRDI parameters for MML1 driver *******************************/

/*******************************************************************************
** Global data for RF customization                                           **
*******************************************************************************/
extern kal_uint32 MML1_CLK_EN_TABLE[4];

/*===============================================================================*/

#if defined(__MTK_TARGET__) || defined(__LTE_L1SIM__)

void MML1_RF_POWER_ON(kal_uint32 is_wake_up, MML1_RF_RAT_T rat_type);
void MML1_RF_POWER_OFF(MML1_RF_RAT_T rat_type);
void MML1_RF_NOTIFY_CALIBRATION_DONE(RFC_DATABASE_T* pRfcDataBase);

void MML1_RF_NOTIFY_POC_DONE(MML1_RF_RAT_T rat_type);
kal_uint32 MML1_RF_QUERY_POC_PENDING_LIST(MML1_RF_RAT_T rat_type);
kal_uint32 MML1_RF_QUERY_CHIP_VERSION(void);

//For 3G TDD query MML1 RF Init status
kal_bool MML1_RF_Init_Done_Check(void);

//Fror 3G TDD Query POR CW Table
kal_uint32 MML1_RF_Query_PowerOnCW_Num(void);
kal_uint32 MML1_RF_Query_PowerOffCW_Num(void);
void MML1_RF_Set_PowerOnCW_Table(kal_uint32 *PowerOnTable);
void MML1_RF_Set_PowerOffCW_Table(kal_uint32 *PowerOffTable);

//RF dependant function
kal_uint32 MML1_RF_MEASURE_TEMPER_DAC(void);

//PMIC API for all RAT
void MML1_RF_VRF18_ModeSet(kal_bool isHWMode);
void MML1_RF_VRF18_SrcSel(kal_uint32 srcIdx);
void MML1_RF_VRF18_Enable(kal_bool vrf18_en);
void MML1_RF_VRF18_FPWM_STATUS(kal_uint32 *bitmap);
void MML1_RF_VRF18_FPWMSwitch(kal_bool isFPWM);
void MML1_RF_VRF18_FPWMSwitched_ByRAT(MML1_RF_RAT_T rat_type, kal_bool isFPWM);
void MML1_RF_VPA_VOSEL_CWGen( kal_uint8 dc2dc_lvl, kal_uint32 *dc2dc_cw );
void MML1_RF_VPA_VOSEL(kal_uint32 volt);
void MML1_RF_VPA_FPWMSwitch(kal_bool isFPWM);
void MML1_RF_VPA_Enable(MML1_RF_RAT_T rat_type, kal_bool vpa_en);
void MML1_RF_VMIPI_ModeSet(kal_bool isHWMode);
void MML1_RF_VMIPI_SrcSel(kal_uint32 srcIdx);
void MML1_RF_VMIPI_Enable(kal_bool vmipi_en);

// Multi-rat share bit information
kal_uint32 MML1_RF_GetMultiRatRfSharingBitmap( MML1_RF_CHIP_T mml1_rfid );

//MIPI
void MML1_MIPI_POWER_ON(MML1_RF_RAT_T rat_type);
void MML1_MIPI_POWER_OFF(MML1_RF_RAT_T rat_type);
kal_uint32 MML1_MIPI_Gen_Data(kal_uint32 *pData, kal_uint16 mipi_data_seq, MML1_RF_RAT_T rat_type);
kal_uint16 mml1_add_parity_bit(kal_uint16 data);

//DRDI
void MML1_RF_DRDI_GetConfig_GPIO_MD(Mml1RfDrdiGpioResult *gpioResult);
void MML1_RF_DRDI_GetConfig_GPIO_CCCI(Mml1RfDrdiGpioResult *gpioResult, kal_uint8 numOfDetectPins);
void MML1_RF_DRDI_GetConfig_ADC_MD(Mml1RfDrdiAdcResult *adcResult);
void MML1_RF_DRDI_GetConfig_ADC_CCCI(Mml1RfDrdiAdcResult *adcResult);
void MML1_RF_DRDI_GetConfig_BARCODE(Mml1RfDrdiBarcodeResult *barcodeResult);
kal_uint16 MML1_RF_DRDI_CUSTOM_DynamicInitByGPIO(void *data);
kal_uint16 MML1_RF_DRDI_CUSTOM_DynamicInitByADC(void *data);
kal_uint16 MML1_RF_DRDI_CUSTOM_DynamicInitByBarcode(void *data);
kal_bool MML1_RF_DRDI_CUSTOM_IsDynamicInitEnable(void);
Mml1RfDrdiDynamicInitParam* MML1_RF_DRDI_Dynamic_GetParamAddr(MML1_RF_RAT_T rat_type);

//Dynamic Co-Clock Control by AP
void MML1_RF_ENTER_FLIGHTMODE_ENTRYPOINT(void);
void MML1_RF_LEAVE_FLIGHTMODE_ENTRYPOINT(void);

//Debug Trace
void MML1_RF_EL1_DBG_ENTRY(void);
void MML1_RF_DUMP_BSILOGGER( MML1_RF_RAT_T rat_type );
void MML1_RF_DUMP_RFCW( MML1_RF_RAT_T rat_type );

// For speech qury RF path
kal_uint16 MML1_RF_Get_RFIC_Info(MML1_RF_RAT_T mode);
kal_uint32 MML1_RF_Get_RAT_Info(void);

//Register MD CCCI callback function for Tx Power Offset
void MML1_RF_Register_TxPowerOffsetInfo_CallbackFunction( MML1_RF_RAT_T rat_type );
#else //For MoDis Build Plz add the same NULL function in the following
////////////////////////////////////////////////////////////////
// For Modis build defined the Interface API as NULL function //
////////////////////////////////////////////////////////////////

#define MML1_RF_POWER_ON()
#define MML1_RF_POWER_OFF()
#define MML1_RF_NOTIFY_CALIBRATION_DONE()

#define MML1_RF_NOTIFY_POC_DONE()
#define MML1_RF_QUERY_POC_PENDING_LIST()       0
#define MML1_RF_QUERY_CHIP_VERSION()           0

//For 3G TDD query MML1 RF Init status
#define MML1_RF_Init_Done_Check()              0

//Fror 3G TDD Query POR CW Table
#define MML1_RF_Query_PowerOnCW_Num()          0
#define MML1_RF_Query_PowerOffCW_Num()         0
#define MML1_RF_Set_PowerOnCW_Table()
#define MML1_RF_Set_PowerOffCW_Table()

//RF dependant function
#define MML1_RF_MEASURE_TEMPER_DAC()           0

//PMIC API for all RAT
#define MML1_RF_VRF18_ModeSet()
#define MML1_RF_VRF18_SrcSel()
#define MML1_RF_VRF18_Enable()
#define MML1_RF_VRF18_FPWM_STATUS()
#define MML1_RF_VRF18_FPWMSwitch()
#define MML1_RF_VRF18_FPWMSwitched_ByRAT()
#define MML1_RF_VPA_VOSEL_CWGen()
#define MML1_RF_VPA_VOSEL()
#define MML1_RF_VPA_FPWMSwitch()
#define MML1_RF_VPA_Enable()
#define MML1_RF_VMIPI_ModeSet()
#define MML1_RF_VMIPI_SrcSel()
#define MML1_RF_VMIPI_Enable()

//MIPI
#define MML1_MIPI_POWER_ON()
#define MML1_MIPI_POWER_OFF()
#define MML1_MIPI_Gen_Data()
#define mml1_add_parity_bit()

//DRDI
#define MML1_RF_DRDI_GetConfig_GPIO_MD()            0
#define MML1_RF_DRDI_GetConfig_GPIO_CCCI()          0
#define MML1_RF_DRDI_GetConfig_ADC_MD()             0
#define MML1_RF_DRDI_GetConfig_ADC_CCCI()           0
#define MML1_RF_DRDI_GetConfig_BARCODE()            0
#define MML1_RF_DRDI_CUSTOM_DynamicInitByGPIO()     0
#define MML1_RF_DRDI_CUSTOM_DynamicInitByADC()      0
#define MML1_RF_DRDI_CUSTOM_DynamicInitByBarcode()  0
#define MML1_RF_DRDI_CUSTOM_IsDynamicInitEnable()   0
#define MML1_RF_DRDI_Dynamic_GetParamAddr()         0

//Dynamic Co-Clock Control by AP
#define MML1_RF_ENTER_FLIGHTMODE_ENTRYPOINT()
#define MML1_RF_LEAVE_FLIGHTMODE_ENTRYPOINT()

//Debug Trace
#define MML1_RF_EL1_DBG_ENTRY()
#define MML1_RF_DUMP_BSILOGGER()
#define MML1_RF_DUMP_RFCW()

// For speech qury RF path
#define MML1_RF_Get_RFIC_Info()                1
#define MML1_RF_Get_RAT_Info()                 0

//Register MD CCCI callback function for Tx Power Offset
#define MML1_RF_Register_TxPowerOffsetInfo_CallbackFunction()
#endif


#endif /* End of #ifndef _MML1_RF_PUBLIC_H_ */

