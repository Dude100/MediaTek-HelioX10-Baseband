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
 * ul1_nvram_editor.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file contains `vendor' defined logical data items stored in NVRAM.
 *    These logical data items are used in object code of Protocol Stack software.
 *
 *    As for customizable logical data items, they are defined in nvram_user_config.c
 *
 * Author:
 * -------
 * 
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __UL1_NVRAM_EDITOR_H__
#define __UL1_NVRAM_EDITOR_H__
#ifndef NVRAM_NOT_PRESENT

/* In case of that not to build this file in 2G projects or 3G TDD projects */
#if defined (__MTK_UL1_FDD__)

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

/*
 *   Include Headers
 */
 
/*
 *   NVRAM Basic Headers
 */
#include "nvram_data_items.h"

/*
 *   User Headers
 */
#include "ul1_nvram_def.h"


#ifdef GEN_FOR_PC
BEGIN_NVRAM_DATA 
 
 
#if defined (__UL1_PLATFORM__)


/*
 *   Bit Level Description Language
 */


LID_BIT VER_LID(NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_LID)
    nvram_ef_ul1_rf_custpack_data_select_struct * NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_TOTAL
    {
        ul1_rf_custpack_data_selector:""
        {
        };
    };

LID_BIT VER_LID(NVRAM_EF_UL1_RF_CUSTOM_DATA_LID)
    nvram_ef_ul1_rf_custom_data_struct * NVRAM_EF_UL1_RF_CUSTOM_DATA_TOTAL
    {
        /* Timing advance and postpone of RF window */
        maxRxStartOffset:""
        {
        };
        maxTxStartOffset:""
        {
        };
        minRxEndOffset:""
        {
        };
        minTxEndOffset:""
        {
        };

        /* Timing of PA control */    
        maxOffset:""
        {
        };
        vmOffset:""
        {
        };
        vbiasOffset:""
        {
        };
        dc2dcOffset:""
        {
        };
        vgaOffset:""
        {
        };

        /* PA section usage */
        paSection:""
        {
        };

        /* RF T/RX timing offset table */
        umtsRxStartTqTable:""
        {
        };
        umtsRxEndTqTable:""
        {
        };
        umtsTxStartTqTable:""
        {
        };
        umtsTxEndTqTable:""
        {
        };

        /* BPI data allocation */
        umtsPdataTable:""
        {
        };

        /* DC2DC level and VM setting table */
        DC2DC:""
        {
        };
        VM_data:""
        {
        };

        /* RF Hign-band and Low-band receivers configurations */
        HB1:""
        {
        };
        HB2:""
        {
        };
        LB1:""
        {
        };
#if defined (MT6162_RF) // MT6162 has two low band receivers
        LB2:""
        {
        };
#endif
    };

#endif /* #if defined (__UL1_PLATFORM__) */

#if (defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)) 
 

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_3G_RF_PARAMETER_LID)
     U_sUl1dRfCustomInputData * NVRAM_EF_UL1_3G_RF_PARAMETER_TOTAL
     {
        startPattern:"#U_0x1234ABCD_L_0x1234ABCD"
        {
        };
        structVersion:""
        {
        };
        rfType:""
        {
        };
        isDataUpdate:"#U_1_L_1"
        {
        };
        umtsRfPaControlTimingOffset:""
        {
        };
        umtsRfPaControlTimingOffset.maxOffset:"#U_65535"
        {
        };
        umtsRfPaControlTimingOffset.vmOffset:"#U_65535"
        {
        };
        umtsRfPaControlTimingOffset.vbiasOffset:"#U_65535"
        {
        };
        umtsRfPaControlTimingOffset.dc2dcOffset:"#U_65535"
        {
        };
        umtsRfPaControlTimingOffset.vgaOffset:"#U_65535"
        {
        };
        umtsBsiBpiTiming:""
        {
        };
        umtsBsiBpiTiming.xTC_PR1:"#U_32767"
        {
        };
        umtsBsiBpiTiming.xTC_PR2:"#U_32767"
        {
        };
        umtsBsiBpiTiming.xTC_PR2B:"#U_32767"
        {
        };
        umtsBsiBpiTiming.xTC_PR3:"#U_32767"
        {
        };
        umtsBsiBpiTiming.xTC_PR3A:"#U_32767"
        {
        };
        umtsBsiBpiTiming.xTC_PT1:"#U_32767"
        {
        };
        umtsBsiBpiTiming.xTC_PT2:"#U_32767"
        {
        };
        umtsBsiBpiTiming.xTC_PT2B:"#U_32767"
        {
        };
        umtsBsiBpiTiming.xTC_PT3:"#U_32767"
        {
        };
        umtsBsiBpiTiming.xTC_PT3A:"#U_32767"
        {
        };
        umtsPdata:""
        {
        };
        umtsBandIndicator:""
        {
        };
        umtsRxLnaPortSel:""
        {
        };
        umtsTxPathSel:""
        {
        };
        xPMU_PA_CONTROL:""
        {
        };
        endPattern:"#U_0xABCD1234_L_0xABCD1234"
        {
        };
     };

#endif /* #if (defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)) */

#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__) 
LID_BIT VER_LID(NVRAM_EF_UL1_IOT_CUSTOMIZATION_LID)
     U_sUl1IotCustomSupportStruct *NVRAM_EF_UL1_IOT_CUSTOMIZATION_TOTAL
     {
         ADAPT_Customized:""
         {
         };
         reserved1:""
         {
         };
         reserved2:""
         {
         };
         reserved3:""
         {
         };
     };
#endif /* #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__) */

#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__) 
LID_BIT VER_LID(NVRAM_EF_UL1_HSPA_CATEGORY_LID)
   nvram_ef_ul1_hspa_category_struct * NVRAM_EF_UL1_HSPA_CATEGORY_TOTAL
   {
      dpa_cat:""
      {
      };
      upa_cat:""
      {
      };
   };
#endif /* #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__) */
     
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__) 
LID_BIT VER_LID(NVRAM_EF_UL1_CUSTOM_DYNAMIC_INIT_DEBUG_LID)
     Ul1CustomDynamicInitDebug * NVRAM_EF_UL1_CUSTOM_DYNAMIC_INIT_DEBUG_TOTAL
     {
        combined_config_index:""
        {
        };
        first_config_index_base:""
        {
        };
        second_config_index_base:""
        {
        };
        third_config_index_base:""
        {
        };
        gpio_get_pin_rpc_status:""
        {
        };
        gpio_return_pin_num:""
        {
        };
        gpio_pin_value:""
        {
        };
        gpio_combined_pin_value:""
        {
        };
        adc_get_ch_num_rpc_status:""
        {
        };
        adc_dcl_handle_status:""
        {
        };
        adc_cal_dcl_handle_status:""
        {
        };
        adc_get_ch_num:""
        {
        };
        adc_dac_read_result:""
        {
        };
        adc_volt_translate_result:""
        {
        };
        adc_volt_level:""
        {
        };
        barcode_lid_read_status:""
        {
        };
        barcode_digit_read_result:""
        {
        };
        umts_tempdac_lid_write_status:""
        {
        };
        umts_txrampdata_lid_write_status:""
        {
        };
        umts_txpaoctlvl_lid_write_status:""
        {
        };
        umts_rxpathloss_lid_write_status:""
        {
        };
        umts_rf_params_lid_write_status:""
        {
        };
        custom_dynamic_init_result_params:""
        {
        };
     };
#endif /* #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__) */

/* TX PRACH TM Comp.  (for MT6572,MT6582) */
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND1_LID)
     ul1cal_txPrachTmCompData_T *NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND2_LID)
     ul1cal_txPrachTmCompData_T *NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND3_LID)
     ul1cal_txPrachTmCompData_T *NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND4_LID)
     ul1cal_txPrachTmCompData_T *NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND5_LID)
     ul1cal_txPrachTmCompData_T *NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL
     {
     
     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND6_LID)
     ul1cal_txPrachTmCompData_T *NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND7_LID)
     ul1cal_txPrachTmCompData_T *NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND8_LID)
     ul1cal_txPrachTmCompData_T *NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL
     {

     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND9_LID)
     ul1cal_txPrachTmCompData_T *NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL
     {
     
     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND10_LID)
     ul1cal_txPrachTmCompData_T *NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL
     {
     
     };
     
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND11_LID)
     ul1cal_txPrachTmCompData_T *NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL
     {
     
     };
     
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPRACHTMCOMP_BAND19_LID)
     ul1cal_txPrachTmCompData_T *NVRAM_EF_UL1_TXPRACHTMCOMP_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_AFCDAC_LID)
     ul1cal_afcDacData_T *NVRAM_EF_UL1_AFCDAC_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_AFCCAP_LID)
     ul1cal_afcCapData_T *NVRAM_EF_UL1_AFCCAP_TOTAL
     {
     
     };

#if (IS_3G_MIPI_SUPPORT)
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_TPC_HIGHBAND1_LID)
     ul1mipi_tpcData_T *NVRAM_EF_UL1_MIPI_TPC_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_TPC_HIGHBAND2_LID)
     ul1mipi_tpcData_T *NVRAM_EF_UL1_MIPI_TPC_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_TPC_HIGHBAND3_LID)
     ul1mipi_tpcData_T *NVRAM_EF_UL1_MIPI_TPC_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_TPC_LOWBAND1_LID)
     ul1mipi_tpcData_T *NVRAM_EF_UL1_MIPI_TPC_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_TPC_LOWBAND2_LID)
     ul1mipi_tpcData_T *NVRAM_EF_UL1_MIPI_TPC_BAND_TOTAL
     {
     
     };
#endif

#if (IS_3G_ET_NVRAM_SUPPORT)
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_ET_HIGHBAND1_LID)
     ul1mipi_etData_T *NVRAM_EF_UL1_MIPI_ET_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_ET_HIGHBAND2_LID)
     ul1mipi_etData_T *NVRAM_EF_UL1_MIPI_ET_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_ET_HIGHBAND3_LID)
     ul1mipi_etData_T *NVRAM_EF_UL1_MIPI_ET_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_ET_LOWBAND1_LID)
     ul1mipi_etData_T *NVRAM_EF_UL1_MIPI_ET_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_ET_LOWBAND2_LID)
     ul1mipi_etData_T *NVRAM_EF_UL1_MIPI_ET_BAND_TOTAL
     {
     
     };
#endif/*IS_3G_ET_NVRAM_SUPPORT*/

#if (IS_3G_MIPI_NVRAM_FULL_SUPPORT)
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_RX_EVENT_HIGHBAND1_LID)
     ul1mipi_rxEvent_T *NVRAM_EF_UL1_MIPI_RX_EVT_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_RX_EVENT_HIGHBAND2_LID)
     ul1mipi_rxEvent_T *NVRAM_EF_UL1_MIPI_RX_EVT_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_RX_EVENT_HIGHBAND3_LID)
     ul1mipi_rxEvent_T *NVRAM_EF_UL1_MIPI_RX_EVT_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_RX_EVENT_LOWBAND1_LID)
     ul1mipi_rxEvent_T *NVRAM_EF_UL1_MIPI_RX_EVT_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_RX_EVENT_LOWBAND2_LID)
     ul1mipi_rxEvent_T *NVRAM_EF_UL1_MIPI_RX_EVT_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_RX_DATA_HIGHBAND1_LID)
     ul1mipi_rxData_T *NVRAM_EF_UL1_MIPI_RX_DATA_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_RX_DATA_HIGHBAND2_LID)
     ul1mipi_rxData_T *NVRAM_EF_UL1_MIPI_RX_DATA_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_RX_DATA_HIGHBAND3_LID)
     ul1mipi_rxData_T *NVRAM_EF_UL1_MIPI_RX_DATA_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_RX_DATA_LOWBAND1_LID)
     ul1mipi_rxData_T *NVRAM_EF_UL1_MIPI_RX_DATA_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_RX_DATA_LOWBAND2_LID)
     ul1mipi_rxData_T *NVRAM_EF_UL1_MIPI_RX_DATA_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_TX_EVENT_HIGHBAND1_LID)
     ul1mipi_txEvent_T *NVRAM_EF_UL1_MIPI_TX_EVT_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_TX_EVENT_HIGHBAND2_LID)
     ul1mipi_txEvent_T *NVRAM_EF_UL1_MIPI_TX_EVT_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_TX_EVENT_HIGHBAND3_LID)
     ul1mipi_txEvent_T *NVRAM_EF_UL1_MIPI_TX_EVT_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_TX_EVENT_LOWBAND1_LID)
     ul1mipi_txEvent_T *NVRAM_EF_UL1_MIPI_TX_EVT_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_TX_EVENT_LOWBAND2_LID)
     ul1mipi_txEvent_T *NVRAM_EF_UL1_MIPI_TX_EVT_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_TX_DATA_HIGHBAND1_LID)
     ul1mipi_txData_T *NVRAM_EF_UL1_MIPI_TX_DATA_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_TX_DATA_HIGHBAND2_LID)
     ul1mipi_txData_T *NVRAM_EF_UL1_MIPI_TX_DATA_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_TX_DATA_HIGHBAND3_LID)
     ul1mipi_txData_T *NVRAM_EF_UL1_MIPI_TX_DATA_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_TX_DATA_LOWBAND1_LID)
     ul1mipi_txData_T *NVRAM_EF_UL1_MIPI_TX_DATA_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_TX_DATA_LOWBAND2_LID)
     ul1mipi_txData_T *NVRAM_EF_UL1_MIPI_TX_DATA_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_ASM_ISOLATION_HIGHBAND1_LID)
     ul1mipi_asmIsoData_T *NVRAM_EF_UL1_MIPI_ASM_ISOLATION_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_ASM_ISOLATION_HIGHBAND2_LID)
     ul1mipi_asmIsoData_T *NVRAM_EF_UL1_MIPI_ASM_ISOLATION_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_ASM_ISOLATION_HIGHBAND3_LID)
     ul1mipi_asmIsoData_T *NVRAM_EF_UL1_MIPI_ASM_ISOLATION_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_ASM_ISOLATION_LOWBAND1_LID)
     ul1mipi_asmIsoData_T *NVRAM_EF_UL1_MIPI_ASM_ISOLATION_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_ASM_ISOLATION_LOWBAND2_LID)
     ul1mipi_asmIsoData_T *NVRAM_EF_UL1_MIPI_ASM_ISOLATION_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_INIT_CW_LID)
     ul1mipi_initCwData_T *NVRAM_EF_UL1_MIPI_INIT_CW_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_SLEEP_CW_LID)
     ul1mipi_sleepCwData_T *NVRAM_EF_UL1_MIPI_SLEEP_CW_TOTAL
     {
     
     };
#if (IS_3G_ET_NVRAM_SUPPORT)
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_ET_ON_CW_LID)
     ul1mipi_etOnCwData_T *NVRAM_EF_UL1_MIPI_ET_ON_CW_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_MIPI_ET_OFF_CW_LID)
     ul1mipi_etOffCwData_T *NVRAM_EF_UL1_MIPI_ET_OFF_CW_TOTAL
     {
     
     };
#endif/*IS_3G_ET_NVRAM_SUPPORT*/

#if (IS_3G_VPA_SEL_BY_BAND_SUPPORT)
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_VPA_SRC_SEL_HIGHBAND1_LID)
     ul1vpa_sel_T *NVRAM_EF_UL1_VPA_SRC_SEL_BAND_TOTAL
     {
     
     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_VPA_SRC_SEL_HIGHBAND2_LID)
     ul1vpa_sel_T *NVRAM_EF_UL1_VPA_SRC_SEL_BAND_TOTAL
     {
     
     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_VPA_SRC_SEL_HIGHBAND3_LID)
     ul1vpa_sel_T *NVRAM_EF_UL1_VPA_SRC_SEL_BAND_TOTAL
     {
     
     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_VPA_SRC_SEL_LOWBAND1_LID)
     ul1vpa_sel_T *NVRAM_EF_UL1_VPA_SRC_SEL_BAND_TOTAL
     {
     
     };
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_VPA_SRC_SEL_LOWBAND2_LID)
     ul1vpa_sel_T *NVRAM_EF_UL1_VPA_SRC_SEL_BAND_TOTAL
     {
     
     };
#endif/*IS_3G_VPA_SEL_BY_BAND_SUPPORT*/


#endif/*IS_3G_MIPI_NVRAM_FULL_SUPPORT*/


#if (IS_3G_TAS_NVRAM_SUPPORT)
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TAS_RF_LID)
     U_sUl1dRfTasData *NVRAM_EF_UL1_TAS_RF_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TAS_CUSTOM_LID)
     UMTS_TAS_Configuration_T *NVRAM_EF_UL1_TAS_CUSTOM_TOTAL
     {
     
     };
#endif/*IS_3G_TAS_NVRAM_SUPPORT*/



#if defined(__TX_POWER_OFFSET_SUPPORT__)
LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPOWEROFFSET_BAND1_LID)
     ul1cal_txPowerOffsetData_T *NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPOWEROFFSET_BAND2_LID)
     ul1cal_txPowerOffsetData_T *NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPOWEROFFSET_BAND3_LID)
     ul1cal_txPowerOffsetData_T *NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPOWEROFFSET_BAND4_LID)
     ul1cal_txPowerOffsetData_T *NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPOWEROFFSET_BAND5_LID)
     ul1cal_txPowerOffsetData_T *NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPOWEROFFSET_BAND6_LID)
     ul1cal_txPowerOffsetData_T *NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPOWEROFFSET_BAND7_LID)
     ul1cal_txPowerOffsetData_T *NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPOWEROFFSET_BAND8_LID)
     ul1cal_txPowerOffsetData_T *NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPOWEROFFSET_BAND9_LID)
     ul1cal_txPowerOffsetData_T *NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPOWEROFFSET_BAND10_LID)
     ul1cal_txPowerOffsetData_T *NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPOWEROFFSET_BAND11_LID)
     ul1cal_txPowerOffsetData_T *NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL
     {
     
     };

LID_BIT MULTIPLE_LID VER_LID(NVRAM_EF_UL1_TXPOWEROFFSET_BAND19_LID)
     ul1cal_txPowerOffsetData_T *NVRAM_EF_UL1_TXPOWEROFFSET_BAND_TOTAL
     {
     
     };
#endif   /* __TX_POWER_OFFSET_SUPPORT__ */

END_NVRAM_DATA

#endif  /* GEN_FOR_PC */
#endif  /* __MTK_UL1_FDD__ */
#endif  /* !NVRAM_NOT_PRESENT */
#endif  /* __UL1_NVRAM_EDITOR_H__ */
