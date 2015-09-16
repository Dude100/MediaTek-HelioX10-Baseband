/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	mml1_custom_drdi.c
 *
 * Project:
 * --------
 *  MOLY
 *
 * Description:
 * ------------
 *  Dynamic Radio-setting Dedicated Image.
 *  RF parameters data input file
 *
 * Author:
 * -------
 *	  
 *
 *******************************************************************************/

#ifdef __MTK_TARGET__

/*******************************************************************************
 * Includes                                                                    *
 *******************************************************************************/
#include "mml1_custom_drdi.h"


/*******************************************************************************
 * Global Data                                                                 *
 *******************************************************************************/

/* Look up table from action id to action function           
 * See the enum #Mml1CustomFunction for members of the table */
const Mml1CustomFunction mml1CustomActionTable[MML1_CUSTOM_MAX_PROC_ACTIONS] =
{
    NULL,
 
#if MML1_CUSTOM_GPIO_ENABLE
    MML1_RF_DRDI_CUSTOM_DynamicInitByGPIO,
#else
    NULL, /* Null action */
#endif
 
#if MML1_CUSTOM_ADC_ENABLE
    MML1_RF_DRDI_CUSTOM_DynamicInitByADC,
#else
    NULL, /* Null action */
#endif
 
#if MML1_CUSTOM_BARCODE_ENABLE
    MML1_RF_DRDI_CUSTOM_DynamicInitByBarcode
#else
    NULL  /* Null action */
#endif
};


/*****************************************
 * AuxADC voltage to level look-up table *
 *****************************************/
kal_uint32 mml1_custom_adc_volt_to_lvl[/*number of supported ADC levels*/][2] =
{
   /* Upper Bound */                  /* Lower Bound */
   {MML1_CUSTOM_ADC_LVL0,               0},
 
   /* Don't remove the above line: insert your new added level setting definition
    * bellow or delete the unused level bellow */
 
   {MML1_CUSTOM_ADC_LVL1,               MML1_CUSTOM_ADC_LVL0},
   {MML1_CUSTOM_ADC_LVL2,               MML1_CUSTOM_ADC_LVL1},
 
   /* Insert your new added level setting definition above or
    * delete the unused level above, and then change lower bound
    * EL1_CUSTOM_ADC_LVL6 below to the last upper bound in the above lines */
 
   {MML1_CUSTOM_ADC_MAX_INPUT_VOLTAGE,  MML1_CUSTOM_ADC_LVL2}  // MT6795 internal SP use 3 DRDI set ,HW layout is 0; 0.9; 1.8 V, choose total 4 ADC level for range allocation.
};
 

/*****************************************
 * Barcode digits array                  *
 *****************************************/
kal_char mml1_custom_barcode_digits[MML1_CUSTOM_BARCODE_NUMS_IN_CALC] =
{
   '8', //Set 0, ex; for MURATA_SP7T
#if 0
/* under construction !*/
/* under construction !*/
#endif
};


/*******************************************************************************
 * Global Functions                                                            *
 *******************************************************************************/

/**
 * @brief get GPIO pin port number
 *
 * for Feature phone/data-card GPIO Pin number access
 * NOT Recommend to modify
 *
 * @param gpio_pin buffer to save the GPIO pin number
 * @return None
 */
void MML1_CUSTOM_GPIO_NON_SMART_PHONE_PIN_ACCESS(kal_int16 *gpio_pin)
{
   /*PS: If link error happens, PLEASE check if codegen(DWS) generates the following variables */
#if (!MML1_CUSTOM_SMART_PHONE_ENABLE)
#if (MML1_CUSTOM_GPIO_ENABLE)
#if   (MML1_CUSTOM_GPIO_NUM_OF_DETECT_PINS_IN_USE == 0x1)
   // extern const char is from gpio_var.c (codegen)
   extern const char GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN;
   gpio_pin[0] = GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN;
   gpio_pin[1] = -1;
   gpio_pin[2] = -1;
#elif (MML1_CUSTOM_GPIO_NUM_OF_DETECT_PINS_IN_USE == 0x2)
   extern const char GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN;
   extern const char GPIO_FDD_BAND_SUPPORT_DETECT_2ND_PIN;
   gpio_pin[0] = GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN;
   gpio_pin[1] = GPIO_FDD_BAND_SUPPORT_DETECT_2ND_PIN;
   gpio_pin[2] = -1;	
#elif (MML1_CUSTOM_GPIO_NUM_OF_DETECT_PINS_IN_USE == 0x3)
   extern const char GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN;
   extern const char GPIO_FDD_BAND_SUPPORT_DETECT_2ND_PIN;
   extern const char GPIO_FDD_BAND_SUPPORT_DETECT_3RD_PIN;
   gpio_pin[0] = GPIO_FDD_BAND_SUPPORT_DETECT_1ST_PIN;
   gpio_pin[1] = GPIO_FDD_BAND_SUPPORT_DETECT_2ND_PIN;
   gpio_pin[2] = GPIO_FDD_BAND_SUPPORT_DETECT_3RD_PIN;	
#endif
#endif
#endif // (!MML1_CUSTOM_SMART_PHONE_ENABLE)		
}

/**
 * @brief get ADC pin port number
 *
 * for Feature phone/data-card ADC Pin number access
 * NOT Recommend to modify
 *
 * @param adc_channel_num variable to save ADC channel number
 * @return None
 */
void MML1_CUSTOM_ADC_PIN_ACCESS(kal_uint16 *adc_channel_num)
{
   /*PS: If link error happens, PLEASE check if codegen(DWS) generates the following variables */
#if (!MML1_CUSTOM_SMART_PHONE_ENABLE)
#if (MML1_CUSTOM_ADC_ENABLE)
   // extern const char is from adc_var.c (codegen)
   extern const char ADC_FDD_RF_PARAMS_DYNAMIC_CUSTOM_CH;
   adc_channel_num[0] = ADC_FDD_RF_PARAMS_DYNAMIC_CUSTOM_CH;
#else
   adc_channel_num[0] = 0xFFFF;
#endif
#endif
}

/**
 * @brief get ADC custom parameters
 * NOT Recommend to modify
 */
void MML1_CUSTOM_ADC_PARAM(kal_uint16 *adcMeasCountOrder, kal_uint32 *adcMaxVolt, kal_uint16 *adcBit)
{
   *adcMeasCountOrder = MML1_CUSTOM_ADC_MEAS_COUNT_2_ORDER;
   *adcMaxVolt        = MML1_CUSTOM_ADC_MAX_INPUT_VOLTAGE;
   *adcBit            = MML1_CUSTOM_ADC_BITS;
}

/**
 * @brief Get MML1 Custom parameters
 * 
 * This function is used to save all custom parameters about GPIO, ADC,
 * and Barcode Setting.
 * NOT Recommend to modify.
 * 
 * @param drdiCustomParam Input data structure to save all custom parameters
 */
void MML1_CUSTOM_GET_CUSTOM_PARAM(Mml1RfDrdiCustomParam *drdiCustomParam)
{
   // DO NOT MODIFY THIS FUNCTION !!!!!!
   drdiCustomParam->mml1_custom_debug_enable                    = MML1_CUSTOM_DEBUG_ENABLE;
   drdiCustomParam->mml1_custom_gpio_set_nums                   = MML1_CUSTOM_GPIO_SET_NUMS;            
   drdiCustomParam->mml1_custom_adc_set_nums                    = MML1_CUSTOM_ADC_SET_NUMS;             
   drdiCustomParam->mml1_custom_nvram_barcode_set_nums          = MML1_CUSTOM_BARCODE_SET_NUMS;   
   drdiCustomParam->mml1_custom_gpio_nums_in_calc               = MML1_CUSTOM_GPIO_NUMS_IN_CALC;
   drdiCustomParam->mml1_custom_ADC_nums_in_calc                = MML1_CUSTOM_ADC_NUMS_IN_CALC;
   drdiCustomParam->mml1_custom_barcode_nums_in_calc            = MML1_CUSTOM_BARCODE_NUMS_IN_CALC;
   drdiCustomParam->mml1_custom_first_index                     = MML1_CUSTOM_FIRST_INDEX;
   drdiCustomParam->mml1_custom_second_index                    = MML1_CUSTOM_SECOND_INDEX;
   drdiCustomParam->mml1_custom_third_index                     = MML1_CUSTOM_THIRD_INDEX;
   drdiCustomParam->mml1_custom_first_index_base                = MML1_CUSTOM_FIRST_INDEX_BASE;
   drdiCustomParam->mml1_custom_gpio_num_of_detect_pins_in_use  = MML1_CUSTOM_GPIO_NUM_OF_DETECT_PINS_IN_USE;
   drdiCustomParam->mml1_custom_adc_level_total                 = MML1_CUSTOM_ADC_LEVEL_TOTAL;
   drdiCustomParam->mml1_custom_barcode_read_digit_num          = MML1_CUSTOM_BARCODE_READ_DIGIT_NUM;
   drdiCustomParam->mml1_custom_barcode_digit_value_1           = MML1_CUSTOM_BARCODE_DIGIT_VALUE_1;
   drdiCustomParam->mml1_custom_barcode_digit_value_2           = MML1_CUSTOM_BARCODE_DIGIT_VALUE_2;
   drdiCustomParam->mml1_custom_barcode_digit_value_3           = MML1_CUSTOM_BARCODE_DIGIT_VALUE_3;
   drdiCustomParam->mml1_custom_adc_calibrate_enable            = MML1_CUSTOM_ADC_CALIBRATE_ENABLE;
   drdiCustomParam->mml1_custom_adc_bits                        = MML1_CUSTOM_ADC_BITS;
   drdiCustomParam->mml1_custom_adc_meas_count_2_order          = MML1_CUSTOM_ADC_MEAS_COUNT_2_ORDER;
   drdiCustomParam->mml1_custom_total_set_nums                  = MML1_CUSTOM_TOTAL_SET_NUMS;
   drdiCustomParam->mml1_custom_adc_max_input_voltage           = MML1_CUSTOM_ADC_MAX_INPUT_VOLTAGE;
}

#endif /* #ifdef __MTK_TARGET__ */

/* END OF FILE */
