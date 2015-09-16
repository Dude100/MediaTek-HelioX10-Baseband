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
 *   tl1cal_ast.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The structure definition of TL1 AST calibration data
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------ 
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef TL1CAL_AST_H
#define TL1CAL_AST_H

#include "dcl.h"


#define AST_CAL_TEMP_SECTION 8
#define AST_CAL_UARFCN_SECTION 15

 /*****************************************************************************
* Constant    : TL1_CUSTOM_GPIO_MAX_NUM_OF_DEFINED_DETECT_PIN_NAME
* Group       : Real target, Internals, UL1D common operation
* Description : Constant to be used to determine the max number of GPIO
*               detection pin names defined so far at AP side GPIO driver
*****************************************************************************/
#define TL1_CUSTOM_GPIO_MAX_NUM_OF_DEFINED_DETECT_PIN_NAME  (3)

/* ------------------------------------------------------------------------- */
typedef struct
{
   kal_uint16  tempdacData[AST_CAL_TEMP_SECTION];
}ast_tl1cal_tempdacData_T; 

typedef struct
{
	 kal_uint16  initDac;
	 kal_uint16  slope;
}ast_tl1cal_afcData_T;

typedef struct
{
   kal_uint16 freqTable[AST_CAL_UARFCN_SECTION];
   kal_int16  compByFreq[3][AST_CAL_UARFCN_SECTION];
   kal_int16  compByTemp[3][AST_CAL_TEMP_SECTION];
}ast_tl1cal_pathlossData_T;

typedef struct
{
   kal_uint16 paData[3][4];
   kal_int16  paPower[3][4];
   kal_uint16 freqTable[AST_CAL_UARFCN_SECTION];
   kal_int16  compByFreq[3][AST_CAL_UARFCN_SECTION];
   kal_int16  compByTemp[3][AST_CAL_TEMP_SECTION]; 
   kal_uint16 paSwitch[2][2]; 
   kal_int16  maxPaPower;
   kal_uint16 maxPaData;
}ast_tl1cal_txdacData_T;

typedef struct
{
    /// first boot-up indicator 1: yes, 0: no (mcu power on ABB auto-cal when is_first_boot is 1)
    kal_uint16 is_first_boot;
    /// ABB calibration data
    kal_uint16 abbData[15];
}ast_tl1cal_abbData_T;

typedef struct
{
    /// CAP ID
    kal_uint32 capId;
}ast_tl1cal_capData_T;
typedef struct
{
    kal_int16 pdCompMidChannel[3];
    kal_int16 pdCompByFreq[AST_CAL_UARFCN_SECTION];
}ast_tl1cal_txPdData_T;



/*******************************************************************************
 * Type Definitions                                                            *
 *******************************************************************************/

/*****************************************************************************
* Typedef     : Tl1CustomDynamicInitDebug
* Group       : Real target, Internals, TL1D common operation
* Type        : structure
* Description : Internal typedef used by TL1CUSTOM GPIO detection HW setting
*               mechanism
*****************************************************************************/

typedef struct
{
   kal_uint16 combined_config_index;
   kal_uint8  first_config_index_base;
   kal_uint8  second_config_index_base;
   kal_uint8  third_config_index_base;

   kal_int32  gpio_get_pin_rpc_status;
   kal_uint32 gpio_return_pin_num[TL1_CUSTOM_GPIO_MAX_NUM_OF_DEFINED_DETECT_PIN_NAME];
   kal_uint32 gpio_pin_value[TL1_CUSTOM_GPIO_MAX_NUM_OF_DEFINED_DETECT_PIN_NAME];
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
   kal_uint16 custom_total_set_nums;

} Tl1CustomDynamicInitDebug;

#endif 	
