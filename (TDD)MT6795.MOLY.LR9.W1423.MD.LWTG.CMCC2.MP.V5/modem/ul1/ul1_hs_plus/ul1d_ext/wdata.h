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
 *	wdata.h
 *
 * Project:
 * --------
 * MT6268
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 *
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef  _UL1D_DATA_H_
#define  _UL1D_DATA_H_

/*===============================================================================*/
#include "kal_general_types.h"
#include "ul1d_cid.h"
/*===============================================================================*/

#if IS_URF_MT6162 || IS_URF_MT6162_DUAL
extern kal_int16 delay_LDO;
extern kal_int16 delay_DFMLDO;
extern kal_int16 delay_TXDFM;
extern kal_int16 delay_PLL;
#endif

extern kal_int16 max_rx_start_offset;
extern kal_int16 max_tx_start_offset;
extern kal_int16 max_txcal_start_offset;
extern kal_int16 min_rx_end_offset;
extern kal_int16 min_tx_end_offset;

extern kal_int16 max_rx_end_offset;
extern kal_int16 max_tx_end_offset;

extern kal_uint8 max_rx_end_reg_idx;
extern kal_int16 min_rx_off_evt_cancel_margin;

//Add for Support RXD and Dual Cell
extern kal_int16 max_rx_dc_reconfig_offset;
#if IS_URF_MT6167 || IS_URF_MT6166 || IS_URF_MT6169
extern kal_int16 UMTS_RX_DC_RECONFIG_TQ_TABLE[3];
#else
extern kal_int16 UMTS_RX_DC_RECONFIG_TQ_TABLE[2];
#endif

extern kal_int16  max_rxd_start_offset;
extern kal_int16  min_rxd_end_offset;
extern kal_int16  UMTS_RXD_START_TQ_TABLE[7];
extern kal_int16  UMTS_RXD_END_TQ_TABLE[5];
extern kal_uint32 rxd_support_mask;
extern kal_uint32 rx_diversity_always_on;
extern kal_uint32 pa_dirft_bitmap;
extern kal_uint16 mpr_backoff_by_service[2];
extern kal_bool is_rf_setting_by_nvram;

extern kal_uint16 max_offset;
extern kal_uint16 vm_offset;
extern kal_uint16 vbias_offset;
extern kal_uint16 dc2dc_offset;
extern kal_uint16 vga_offset;
#if IS_3G_MIPI_SUPPORT
extern kal_bool is_3g_mipi_enable;
#endif
#if IS_URF_MT6169
extern kal_uint32 tdac_threshold;
#endif
#if IS_3G_ET_SUPPORT
extern kal_bool is_3g_et_enable;
extern kal_uint32 etCwValueDumpAllTable[UL1_MIPI_ET_CW_NUM];
extern kal_uint32 etCwNum;
extern kal_uint32 etBsiPort;
extern kal_uint32 etUsid;
#endif


extern kal_uint8  pa_section;
extern kal_uint8  DC2DC[3/*pa_mode*/];
extern kal_uint8  VM_data[3/*pa_mode*/] ;

extern kal_int16  UMTS_RX_START_TQ_TABLE[9];
extern kal_int16  UMTS_RX_END_TQ_TABLE[5];

extern kal_int16  UMTS_TX_START_TQ_TABLE[7];
extern kal_int16  UMTS_TX_END_TQ_TABLE[3];


extern BPI_data_type  UMTS_PDATA_TABLE[][2][5];
extern BPI_data_type  UMTS_PDATA2_RX_TABLE[][5];


/*------------- Single Software Load for Multiple Components Compatible -------------*/
extern kal_uint8 ul1custom_debug_enable;
extern kal_uint8 ul1custom_gpio_set_nums;
extern kal_uint8 ul1custom_adc_set_nums;
extern kal_uint8 ul1custom_nvram_barcode_set_nums;
extern kal_uint8 ul1custom_gpio_nums_in_calc;
extern kal_uint8 ul1custom_ADC_nums_in_calc;
extern kal_uint8 ul1custom_nvram_barcode_nums_in_calc;
extern kal_uint8 ul1custom_first_index;
extern kal_uint8 ul1custom_second_index;
extern kal_uint8 ul1custom_third_index;
extern kal_uint8 ul1custom_first_index_base;
extern kal_uint8 ul1custom_gpio_num_of_detect_pins_in_use;
extern kal_uint8 ul1custom_adc_level_total;
extern kal_uint8 ul1custom_barcode_read_digit_num;
extern kal_uint8 ul1custom_barcode_digit_value_1;
extern kal_uint8 ul1custom_barcode_digit_value_2;
extern kal_uint8 ul1custom_barcode_digit_value_3;
extern kal_uint8 ul1custom_max_rf_support_band_num;
extern kal_uint8 ul1custom_adc_calibrate_enable;
extern kal_uint8 ul1custom_adc_bits;
extern kal_uint16 ul1custom_adc_meas_count_2_order;
extern kal_uint16 ul1custom_total_set_nums;
extern kal_uint32 ul1custom_adc_max_input_voltage;
/*------------- Single Software Load for Multiple Components Compatible -------------*/

extern const kal_bool ul1d_afc_vcxo_support;

#endif /* End of #ifndef _UL1D_DATA_H_ */

