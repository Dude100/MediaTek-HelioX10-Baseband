/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 * nvram_ul1def.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file provides a fuction for NVRAM Task to get UL1 default value
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
  *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "nvram_enums.h"

#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)

#ifdef __MTK_TARGET__

#include "kal_public_defs.h" //MSBB change #include "stack_config.h"

#if defined (__UL1_PLATFORM__)
#include "common_nvram_editor_data_item.h"
#include "ul1d_rf_public.h"
#endif

#include "nvram_interface.h"
#include "hal_ul1_def.h"

// Fix NVRAM RHR activity side-effect
#include "nvram_editor_data_item.h"

/* UL1 calibration data defination */
#include "ul1d_rf_public.h"
#include "ul1cal.h"
#include "l1cal.h"

#include "nvram_data_items.h"
#include "nvram_main.h"

#include "ul1_nvram_def.h"
#include "ul1d_rf_cid.h"

#define UNUSED(x)                      (void)x

#define countof(x)                  ((sizeof(x))/(sizeof(*x)))

extern kal_uint8 UL1D_RF_CalDataGetBand(UMTSBand rf_band_in_question, kal_bool nvram_init);
// Start for ADAPT IOT AMR workaround
// This modification is temp solution for Link error, the long term solution should be provided by CSD
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
static kal_bool UL1_IS_ADAPT_IOT_CUSTOMIZATION = KAL_FALSE;
#endif
// End for ADAPT IOT AMR workaround
void nvram_init_uL1_AfcData(void)
{
   kal_bool error_no;
   extern kal_int16 afc_dac_default;
   extern kal_uint32 afc_inv_slope;

   l1cal_afcData_T *afc = (l1cal_afcData_T *)get_ctrl_buffer( sizeof( l1cal_afcData_T ) );

   /* Get RF customization data from NVRAM (customer's input) */
   error_no = nvram_external_read_data(NVRAM_EF_L1_AFCDATA_LID, 1, (kal_uint8 *)afc, NVRAM_EF_L1_AFCDATA_SIZE);

   #if IS_3G_MML1_AFC_TADC_SUPPORT
   error_no = nvram_external_read_data(NVRAM_EF_UL1_AFCDAC_LID, 1, (kal_uint8 *)afc, NVRAM_EF_UL1_AFCDAC_SIZE);
   #endif

   ASSERT(error_no == KAL_TRUE);
   afc_dac_default = afc->dacValue;
   afc_inv_slope = afc->slopeInv;
   free_ctrl_buffer( afc );
}

void nvram_init_uL1_RF_customInputData(void)
{
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)

   /********************************************************/
   /* MT6573 3G RF Customization for Modem Bin Update Tool */
   /********************************************************/

   kal_bool error_no;
   U_sUl1dRfCustomInputData *ul1_rf_custom_input_data_buffer = (U_sUl1dRfCustomInputData *)get_ctrl_buffer( sizeof( U_sUl1dRfCustomInputData ) );

   /* Get RF customization data from NVRAM (customer's input) */
   error_no = nvram_external_read_data(NVRAM_EF_UL1_3G_RF_PARAMETER_LID, 1, (kal_uint8 *)ul1_rf_custom_input_data_buffer, NVRAM_EF_UL1_3G_RF_PARAMETER_SIZE);
   ASSERT(error_no == KAL_TRUE);
   kal_mem_cpy(&UMTS_RF_CUSTOM_INPUT_DATA, ul1_rf_custom_input_data_buffer, sizeof(U_sUl1dRfCustomInputData));
   free_ctrl_buffer( ul1_rf_custom_input_data_buffer );


   /* For user modifying its RF customized band setting via NVRAM editor
    *
    * Update band indicator from NVRAM here so that whether user modifies band
    * setting from NVRAM editor or by Modem Bin Update tool or by having
    * makefile band setting compile option changed/load rebuilt we can
    * have latest user input band setting at this stage
    *
    * In band setting modified by makefile band setting compile option changed
    * /load rebuilt case the NVRAM file of RF customized setting and UL1D run-time
    * data defined in wdata.c must be updated by user so that no whether user
    * downloads load with/without format NVRAM, it should be OK
    *
    * Even user modifies band setting via NVRAM editor and does not re-calibrate,
    * other bands without calibration data results still have default value to
    * be used to make phone not to suffer performance assertions at all
    */
#if defined (__UL1_HS_PLUS_PLATFORM__)
   ul1d_BandInfo[0] = UMTS_RF_CUSTOM_INPUT_DATA.umtsBandIndicator.HB1;
   ul1d_BandInfo[1] = UMTS_RF_CUSTOM_INPUT_DATA.umtsBandIndicator.HB2;
   ul1d_BandInfo[2] = UMTS_RF_CUSTOM_INPUT_DATA.umtsBandIndicator.HB3;
   ul1d_BandInfo[3] = UMTS_RF_CUSTOM_INPUT_DATA.umtsBandIndicator.LB1;
   ul1d_BandInfo[4] = UMTS_RF_CUSTOM_INPUT_DATA.umtsBandIndicator.LB2;    
#else
   rxHighBand1Indicator = UMTS_RF_CUSTOM_INPUT_DATA.umtsBandIndicator.HB1;
   rxHighBand2Indicator = UMTS_RF_CUSTOM_INPUT_DATA.umtsBandIndicator.HB2;
   rxLowBand1Indicator = UMTS_RF_CUSTOM_INPUT_DATA.umtsBandIndicator.LB1;
   #if IS_RF_MT6162
   rxLowBand2Indicator = UMTS_RF_CUSTOM_INPUT_DATA.umtsBandIndicator.LB2;    
   #endif
#endif

// Start for ADAPT IOT AMR workaround
   {
      kal_uint8 buffer[NVRAM_EF_UL1_IOT_CUSTOMIZATION_SIZE];
      nvram_external_read_data(NVRAM_EF_UL1_IOT_CUSTOMIZATION_LID, 1, buffer, NVRAM_EF_UL1_IOT_CUSTOMIZATION_SIZE);
      UL1_IS_ADAPT_IOT_CUSTOMIZATION = (kal_bool)(buffer[0]);
   }
// End for ADAPT IOT AMR workaround

#endif
}

#if defined (__UL1_PLATFORM__)
void nvram_init_uL1_rfCustomizationData(void)
{
   kal_uint8 selector;
   kal_uint16 pdu_length;
   kal_uint16 n;
   kal_bool error_no;
   kal_uint8 *rf_data_pdu_ptr, *srcForCopy, *dst;
   nvram_ef_ul1_rf_custom_data_struct *src;

   /* Get RF customization data selector value from NVRAM (customer's input) */
   pdu_length = NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_SIZE;
   rf_data_pdu_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
   error_no = nvram_external_read_data(NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_LID, 1, rf_data_pdu_ptr, pdu_length);
   ASSERT(error_no == KAL_TRUE);
   selector = *rf_data_pdu_ptr;
   free_ctrl_buffer(rf_data_pdu_ptr);

   /* Get RF customization data from NVRAM (customer's input) */
   pdu_length = NVRAM_EF_UL1_RF_CUSTOM_DATA_SIZE;
   rf_data_pdu_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
   error_no = nvram_external_read_data(NVRAM_EF_UL1_RF_CUSTOM_DATA_LID, selector, rf_data_pdu_ptr, pdu_length);
   ASSERT(error_no == KAL_TRUE);

   /* Copy to UL1 run-time data */
   src = (nvram_ef_ul1_rf_custom_data_struct*)rf_data_pdu_ptr;

   max_rx_start_offset = src->maxRxStartOffset;
   max_tx_start_offset = src->maxTxStartOffset;
   min_rx_end_offset = src->minRxEndOffset;
   min_tx_end_offset = src->minTxEndOffset;
   max_offset = src->maxOffset;
   vm_offset = src->vmOffset;
   vbias_offset = src->vbiasOffset;
   dc2dc_offset = src->dc2dcOffset;
   vga_offset = src->vgaOffset;
   pa_section = src->paSection;

   srcForCopy = (kal_uint8*)(src->umtsRxStartTqTable);
   dst = (kal_uint8*)(UMTS_RX_START_TQ_TABLE);

   if(dst==0)  return;
   for(n=(sizeof(kal_int16)*UMTS_RF_RX_START_TIMING_ARRAY_LENGTH); n>0; n--)
   {
      *dst++ = *srcForCopy++;
   }

   srcForCopy = (kal_uint8*)(src->umtsRxEndTqTable);
   dst = (kal_uint8*)(UMTS_RX_END_TQ_TABLE);

   if(dst==0)  return;
   for(n=(sizeof(kal_int16)*UMTS_RF_RX_END_TIMING_ARRAY_LENGTH); n>0; n--)
   {
      *dst++ = *srcForCopy++;
   }

   srcForCopy = (kal_uint8*)(src->umtsTxStartTqTable);
   dst = (kal_uint8*)(UMTS_TX_START_TQ_TABLE);

   if(dst==0)  return;
   for(n=(sizeof(kal_int16)*UMTS_RF_TX_START_TIMING_ARRAY_LENGTH); n>0; n--)
   {
      *dst++ = *srcForCopy++;
   }

   srcForCopy = (kal_uint8*)(src->umtsTxEndTqTable);
   dst = (kal_uint8*)(UMTS_TX_END_TQ_TABLE);

   if(dst==0)  return;
   for(n=(sizeof(kal_int16)*UMTS_RF_TX_END_TIMING_ARRAY_LENGTH); n>0; n--)
   {
      *dst++ = *srcForCopy++;
   }

   srcForCopy = (kal_uint8*)(src->umtsPdataTable);
   dst = (kal_uint8*)UMTS_PDATA_TABLE;

   if(dst==0)  return;
   for(n=(sizeof(kal_int16)*(UMTS_RF_BPI_DATA_TABLE_NUM_OF_BANDS*UMTS_RF_BPI_DATA_TABLE_NUM_OF_WINDOWS*UMTS_RF_BPI_DATA_TABLE_NUM_OF_EVENTS)); n>0; n--)
   {
      *dst++ = *srcForCopy++;
   }

   srcForCopy = (kal_uint8*)(src->DC2DC);
   dst = (kal_uint8*)(DC2DC);

   if(dst==0)  return;
   for(n=(sizeof(kal_uint8)*UMTS_RF_MAX_PA_SECTIONS); n>0; n--)
   {
      *dst++ = *srcForCopy++;
   }

   srcForCopy = (kal_uint8*)(src->VM_data);
   dst = (kal_uint8*)(VM_data);

   if(dst==0)  return;
   for( n=(sizeof(kal_uint8)*UMTS_RF_MAX_PA_SECTIONS); n>0; n--)
   {
      *dst++ = *srcForCopy++;
   }

   rxHighBand1Indicator = src->HB1;
   rxHighBand2Indicator = src->HB2;
   rxLowBand1Indicator = src->LB1;
#if IS_RF_MT6162
   rxLowBand2Indicator = src->LB2;
#endif

   free_ctrl_buffer(rf_data_pdu_ptr);
}

#endif /* #if defined (__UL1_PLATFORM__) */

/*****************************************************************************
 * FUNCTION
 *  nvram_send_uL1_cal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_send_uL1_cal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   /**
    *    file_idx should be the first L1 element in the logical data item ID enum
    *    Currently, L1 calibration data element is as following:
    *    NVRAM_EF_L1_AGCPATHLOSS_LID, NVRAM_EF_L1_RAMPTABLE_GSM900_LID,
    *    NVRAM_EF_L1_RAMPTABLE_DCS1800_LID, NVRAM_EF_L1_RAMPTABLE_PCS1900_LID, 
    *    NVRAM_EF_L1_AFCDATA_LID, VRAM_EF_L1_L1SPFC_LID, 
    */

    nvram_lid_enum file_idx;
    nvram_ltable_entry_struct *ldi;
    peer_buff_struct *peer_buf_ptr;
    kal_uint8 *pdu_ptr;
    kal_uint16 pdu_length;
    nvram_read_req_struct *local_data;

    /* Move the calling to nvram_init_uL1_rfCustomizationData() to nvram_special_service() */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_data = (nvram_read_req_struct*) construct_local_para(sizeof(nvram_read_req_struct), TD_CTRL);

    for (file_idx = NVRAM_EF_UL1_START; file_idx <= NVRAM_EF_UL1_END; file_idx++)
    {
        if (!NVRAM_IS_LID_VALID(file_idx))
        {
            continue;
        }
        
        switch(file_idx)
        {
            case NVRAM_EF_UL1_TEMP_DAC_LID:
            case NVRAM_EF_UL1_PATHLOSS_BAND1_LID:
            case NVRAM_EF_UL1_PATHLOSS_BAND2_LID:
            case NVRAM_EF_UL1_PATHLOSS_BAND3_LID:
            case NVRAM_EF_UL1_PATHLOSS_BAND4_LID:
            case NVRAM_EF_UL1_PATHLOSS_BAND5_LID:
            //case NVRAM_EF_UL1_PATHLOSS_BAND6_LID:
            case NVRAM_EF_UL1_PATHLOSS_BAND7_LID:
            case NVRAM_EF_UL1_PATHLOSS_BAND8_LID:
            case NVRAM_EF_UL1_PATHLOSS_BAND9_LID:
            case NVRAM_EF_UL1_PATHLOSS_BAND10_LID:
            case NVRAM_EF_UL1_PATHLOSS_BAND11_LID:
            case NVRAM_EF_UL1_PATHLOSS_BAND19_LID:
            case NVRAM_EF_UL1_TXDAC_BAND1_LID:
            case NVRAM_EF_UL1_TXDAC_BAND2_LID:
            case NVRAM_EF_UL1_TXDAC_BAND3_LID:
            case NVRAM_EF_UL1_TXDAC_BAND4_LID:
            case NVRAM_EF_UL1_TXDAC_BAND5_LID:
            //case NVRAM_EF_UL1_TXDAC_BAND6_LID:
            case NVRAM_EF_UL1_TXDAC_BAND7_LID:
            case NVRAM_EF_UL1_TXDAC_BAND8_LID:
            case NVRAM_EF_UL1_TXDAC_BAND9_LID:
            case NVRAM_EF_UL1_TXDAC_BAND10_LID:
            case NVRAM_EF_UL1_TXDAC_BAND11_LID:
            case NVRAM_EF_UL1_TXDAC_BAND19_LID:
            {
                nvram_util_get_data_item(&ldi, file_idx);
        
                local_data->access_id = 0;
                local_data->file_idx = file_idx;
                local_data->para = 1;
        
                pdu_length = ldi->size;
                peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
                ASSERT(peer_buf_ptr != NULL);
        
                pdu_ptr = get_peer_buff_pdu(peer_buf_ptr, &pdu_length);
                ASSERT(pdu_ptr != NULL);
        
            #ifdef __MULTI_BOOT__
                if (FACTORY_BOOT == kal_query_boot_mode())
                {        
                    nvram_read_confirm(MOD_FT, nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length), local_data, ldi->size, peer_buf_ptr);
                }
                else
            #endif /* __MULTI_BOOT__ */   
                {
                    nvram_read_confirm(MOD_UL1, nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length), local_data, ldi->size, peer_buf_ptr);
                }
                break;
            }
        }
    }

#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
    /* PA 8-level contrl */
    for (file_idx = NVRAM_EF_UL1_TXPAOCTLEV_START; file_idx <= NVRAM_EF_UL1_TXPAOCTLEV_END; file_idx++)
    {
        if (!NVRAM_IS_LID_VALID(file_idx))
        {
            continue;
        }
        
        switch(file_idx)
        {
            case NVRAM_EF_UL1_TXPAOCTLEV_BAND1_LID:
            case NVRAM_EF_UL1_TXPAOCTLEV_BAND2_LID:
            case NVRAM_EF_UL1_TXPAOCTLEV_BAND3_LID:
            case NVRAM_EF_UL1_TXPAOCTLEV_BAND4_LID:
            case NVRAM_EF_UL1_TXPAOCTLEV_BAND5_LID:
            //case NVRAM_EF_UL1_TXPAOCTLEV_BAND6_LID:
            case NVRAM_EF_UL1_TXPAOCTLEV_BAND7_LID:
            case NVRAM_EF_UL1_TXPAOCTLEV_BAND8_LID:
            case NVRAM_EF_UL1_TXPAOCTLEV_BAND9_LID:
            case NVRAM_EF_UL1_TXPAOCTLEV_BAND10_LID:
            case NVRAM_EF_UL1_TXPAOCTLEV_BAND11_LID:
            case NVRAM_EF_UL1_TXPAOCTLEV_BAND19_LID:
            {
                nvram_util_get_data_item(&ldi, file_idx);
        
                local_data->access_id = 0;
                local_data->file_idx = file_idx;
                local_data->para = 1;
        
                pdu_length = ldi->size;
                peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
                ASSERT(peer_buf_ptr != NULL);
        
                pdu_ptr = get_peer_buff_pdu(peer_buf_ptr, &pdu_length);
                ASSERT(pdu_ptr != NULL);
        
            #ifdef __MULTI_BOOT__
                if (FACTORY_BOOT == kal_query_boot_mode())
                {        
                    nvram_read_confirm(MOD_FT, nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length), local_data, ldi->size, peer_buf_ptr);
                }
                else
            #endif /* __MULTI_BOOT__ */   
                {
                    nvram_read_confirm(MOD_UL1, nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length), local_data, ldi->size, peer_buf_ptr);
                }
                break;
            }
        }
    }
    /* End of PA 8-level contrl */
#endif // #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)

#if defined(__UMTS_R8__) //Jay
    for (file_idx = NVRAM_EF_UL1_PATHLOSS2_START; file_idx <= NVRAM_EF_UL1_PATHLOSS2_END; file_idx++)
    {
       if (!NVRAM_IS_LID_VALID(file_idx))
       {
          continue;
       }
        
       switch(file_idx)
       {
          case NVRAM_EF_UL1_PATHLOSS2_BAND1_LID:
          case NVRAM_EF_UL1_PATHLOSS2_BAND2_LID:
          case NVRAM_EF_UL1_PATHLOSS2_BAND3_LID:
          case NVRAM_EF_UL1_PATHLOSS2_BAND4_LID:
          case NVRAM_EF_UL1_PATHLOSS2_BAND5_LID:
          //case NVRAM_EF_UL1_PATHLOSS2_BAND6_LID:
          case NVRAM_EF_UL1_PATHLOSS2_BAND7_LID:
          case NVRAM_EF_UL1_PATHLOSS2_BAND8_LID:
          case NVRAM_EF_UL1_PATHLOSS2_BAND9_LID:
          case NVRAM_EF_UL1_PATHLOSS2_BAND10_LID:
          case NVRAM_EF_UL1_PATHLOSS2_BAND11_LID:
          case NVRAM_EF_UL1_PATHLOSS2_BAND19_LID:
          {
              nvram_util_get_data_item(&ldi, file_idx);

              local_data->access_id = 0;
              local_data->file_idx = file_idx;
              local_data->para = 1;
          
              pdu_length = ldi->size;
              peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
              ASSERT(peer_buf_ptr != NULL);
          
              pdu_ptr = get_peer_buff_pdu(peer_buf_ptr, &pdu_length);
              ASSERT(pdu_ptr != NULL);
          
          #ifdef __MULTI_BOOT__
              if (FACTORY_BOOT == kal_query_boot_mode())
              {        
                  nvram_read_confirm(MOD_FT, nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length), local_data, ldi->size, peer_buf_ptr);
              }
              else
          #endif /* __MULTI_BOOT__ */
              {
                  nvram_read_confirm(MOD_UL1, nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length), local_data, ldi->size, peer_buf_ptr);
              }
              break;
          }         
       }
    }

    // add by wilson for PA drift compensation

    for (file_idx = NVRAM_EF_UL1_TXPADRIFTCOMP_START; file_idx <= NVRAM_EF_UL1_TXPADRIFTCOMP_END; file_idx++)
    {
       if (!NVRAM_IS_LID_VALID(file_idx))
       {
          continue;
       }
        
       switch(file_idx)
       {
          case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND1_LID:
          case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND2_LID:
          case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND3_LID:
          case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND4_LID:
          case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND5_LID:
          //case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND6_LID:
          case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND7_LID:
          case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND8_LID:
          case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND9_LID:
          case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND10_LID:
          case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND11_LID:
          case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND19_LID:
          {
              nvram_util_get_data_item(&ldi, file_idx);

              local_data->access_id = 0;
              local_data->file_idx = file_idx;
              local_data->para = 1;
          
              pdu_length = ldi->size;
              peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
              ASSERT(peer_buf_ptr != NULL);
          
              pdu_ptr = get_peer_buff_pdu(peer_buf_ptr, &pdu_length);
              ASSERT(pdu_ptr != NULL);
          
          #ifdef __MULTI_BOOT__
              if (FACTORY_BOOT == kal_query_boot_mode())
              {        
                  nvram_read_confirm(MOD_FT, nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length), local_data, ldi->size, peer_buf_ptr);
              }
              else
          #endif /* __MULTI_BOOT__ */
              {
                  nvram_read_confirm(MOD_UL1, nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length), local_data, ldi->size, peer_buf_ptr);
              }
              break;
          }         
       }
    }
#endif

    /** Tx PRACH TM Compensation */
    for (file_idx = NVRAM_EF_UL1_TXPRACHTMCOMP_START; file_idx <= NVRAM_EF_UL1_TXPRACHTMCOMP_END; file_idx++)
    {
        if (!NVRAM_IS_LID_VALID(file_idx))
        {
            continue;
        }
        
        switch(file_idx)
        {
            case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND1_LID:
            case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND2_LID:
            case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND3_LID:
            case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND4_LID:
            case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND5_LID:
            //case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND6_LID:
            case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND7_LID:
            case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND8_LID:
            case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND9_LID:
            case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND10_LID:
            case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND11_LID:
            case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND19_LID:
            {
                nvram_util_get_data_item(&ldi, file_idx);
        
                local_data->access_id = 0;
                local_data->file_idx = file_idx;
                local_data->para = 1;
        
                pdu_length = ldi->size;
                peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
                ASSERT(peer_buf_ptr != NULL);
        
                pdu_ptr = get_peer_buff_pdu(peer_buf_ptr, &pdu_length);
                ASSERT(pdu_ptr != NULL);
        
            #ifdef __MULTI_BOOT__
                if (FACTORY_BOOT == kal_query_boot_mode())
                {        
                    nvram_read_confirm(MOD_FT, nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length), local_data, ldi->size, peer_buf_ptr);
                }
                else
            #endif /* __MULTI_BOOT__ */   
                {
                    nvram_read_confirm(MOD_UL1, nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length), local_data, ldi->size, peer_buf_ptr);
                }
                break;
            }
        }
    }


    /** AFCDAC */
    for (file_idx = NVRAM_EF_UL1_AFCDAC_START; file_idx <= NVRAM_EF_UL1_AFCDAC_END; file_idx++)
    {
            if (!NVRAM_IS_LID_VALID(file_idx))
            {
                continue;
            }

            switch(file_idx)
            {
                case NVRAM_EF_UL1_AFCDAC_LID:
                {
                    nvram_util_get_data_item(&ldi, file_idx);

                    local_data->access_id = 0;
                    local_data->file_idx = file_idx;
                    local_data->para = 1;

                    pdu_length = ldi->size;
                    peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
                    ASSERT(peer_buf_ptr != NULL);

                    pdu_ptr = get_peer_buff_pdu(peer_buf_ptr, &pdu_length);
                    ASSERT(pdu_ptr != NULL);

            #ifdef __MULTI_BOOT__
                    if (FACTORY_BOOT == kal_query_boot_mode())
                    {
                        nvram_read_confirm(MOD_FT, nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length), local_data, ldi->size, peer_buf_ptr);
                    }
                    else
            #endif /* __MULTI_BOOT__ */
                    {
                        nvram_read_confirm(MOD_UL1, nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length), local_data, ldi->size, peer_buf_ptr);
                    }
                    break;
             }
        }
    }

    /** AFCCAP */
    for (file_idx = NVRAM_EF_UL1_AFCCAP_START; file_idx <= NVRAM_EF_UL1_AFCCAP_END; file_idx++)
    {
            if (!NVRAM_IS_LID_VALID(file_idx))
            {
                continue;
            }

            switch(file_idx)
            {
                case NVRAM_EF_UL1_AFCCAP_LID:
                {
                    nvram_util_get_data_item(&ldi, file_idx);

                    local_data->access_id = 0;
                    local_data->file_idx = file_idx;
                    local_data->para = 1;

                    pdu_length = ldi->size;
                    peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
                    ASSERT(peer_buf_ptr != NULL);

                    pdu_ptr = get_peer_buff_pdu(peer_buf_ptr, &pdu_length);
                    ASSERT(pdu_ptr != NULL);

             #ifdef __MULTI_BOOT__
                    if (FACTORY_BOOT == kal_query_boot_mode())
                    {
                        nvram_read_confirm(MOD_FT, nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length), local_data, ldi->size, peer_buf_ptr);
                    }
                    else
             #endif /* __MULTI_BOOT__ */
                    {
                        nvram_read_confirm(MOD_UL1, nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length), local_data, ldi->size, peer_buf_ptr);
                    }
                    break;
             }
        }
    }

    /** Tx Power Offset */
    for (file_idx = NVRAM_EF_UL1_TXPOWEROFFSET_START; file_idx <= NVRAM_EF_UL1_TXPOWEROFFSET_END; file_idx++)
    {
        if (!NVRAM_IS_LID_VALID(file_idx))
        {
            continue;
        }
        
        switch(file_idx)
        {
            /* Tx power offset table */
            case NVRAM_EF_UL1_TXPOWEROFFSET_BAND1_LID:
            case NVRAM_EF_UL1_TXPOWEROFFSET_BAND2_LID:
            case NVRAM_EF_UL1_TXPOWEROFFSET_BAND3_LID:
            case NVRAM_EF_UL1_TXPOWEROFFSET_BAND4_LID:
            case NVRAM_EF_UL1_TXPOWEROFFSET_BAND5_LID:
            //case NVRAM_EF_UL1_TXPOWEROFFSET_BAND6_LID:
            case NVRAM_EF_UL1_TXPOWEROFFSET_BAND7_LID:
            case NVRAM_EF_UL1_TXPOWEROFFSET_BAND8_LID:
            case NVRAM_EF_UL1_TXPOWEROFFSET_BAND9_LID:
            case NVRAM_EF_UL1_TXPOWEROFFSET_BAND10_LID:
            case NVRAM_EF_UL1_TXPOWEROFFSET_BAND11_LID:
            case NVRAM_EF_UL1_TXPOWEROFFSET_BAND19_LID:
            {
                nvram_util_get_data_item(&ldi, file_idx);
        
                local_data->access_id = 0;
                local_data->file_idx = file_idx;
                local_data->para = 1;
        
                pdu_length = ldi->size;
                peer_buf_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
                ASSERT(peer_buf_ptr != NULL);
        
                pdu_ptr = get_peer_buff_pdu(peer_buf_ptr, &pdu_length);
                ASSERT(pdu_ptr != NULL);
        
#ifdef __MULTI_BOOT__
                if (FACTORY_BOOT == kal_query_boot_mode())
                {        
                    nvram_read_confirm(MOD_FT, nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length), local_data, ldi->size, peer_buf_ptr);
                }
                else
#endif /* __MULTI_BOOT__ */   
                {
                    nvram_read_confirm(MOD_UL1, nvram_read_data_item(ldi, 1, 1, pdu_ptr, pdu_length), local_data, ldi->size, peer_buf_ptr);
                }
                break;
            }
        }
    }

    free_local_para((local_para_struct*) local_data);

}   /* end of nvram_send_L1_cal function */


#if (IS_3G_MIPI_NVRAM_FULL_SUPPORT)
void nvram_init_uL1_mipiTxData(void)
{
   kal_bool error_no;
   nvram_lid_enum lid;
   kal_uint32 tableIdx;
      
   ul1mipi_txData_T *ul1_rf_mipi_tx_data_buffer = (ul1mipi_txData_T *)get_ctrl_buffer(sizeof(ul1mipi_txData_T));

   for (lid = NVRAM_EF_UL1_MIPI_TX_DATA_START; lid <= NVRAM_EF_UL1_MIPI_TX_DATA_END; lid++)
   {
       error_no = nvram_external_read_data(lid, 1, (kal_uint8 *)ul1_rf_mipi_tx_data_buffer, sizeof(ul1mipi_txData_T));
       ASSERT(error_no == KAL_TRUE);

       tableIdx = UMTSBand1 + (lid - NVRAM_EF_UL1_MIPI_TX_DATA_START);
       kal_mem_cpy(UMTS_MIPI_TX_DATA_TABLE[tableIdx], ul1_rf_mipi_tx_data_buffer, sizeof(ul1mipi_txData_T));
   }
   free_ctrl_buffer(ul1_rf_mipi_tx_data_buffer);

}

void nvram_init_uL1_mipiTxEvent(void)
{
   kal_bool error_no;
   nvram_lid_enum lid;
   kal_uint32 tableIdx;
      
   ul1mipi_txEvent_T *ul1_rf_mipi_tx_event_buffer = (ul1mipi_txEvent_T *)get_ctrl_buffer(sizeof(ul1mipi_txEvent_T));

   for (lid = NVRAM_EF_UL1_MIPI_TX_EVENT_START; lid <= NVRAM_EF_UL1_MIPI_TX_EVENT_END; lid++)
   {
       error_no = nvram_external_read_data(lid, 1, (kal_uint8 *)ul1_rf_mipi_tx_event_buffer, sizeof(ul1mipi_txEvent_T));
       ASSERT(error_no == KAL_TRUE);

       tableIdx = UMTSBand1 + (lid - NVRAM_EF_UL1_MIPI_TX_EVENT_START);
       kal_mem_cpy(UMTS_MIPI_TX_EVENT_TABLE[tableIdx], ul1_rf_mipi_tx_event_buffer, sizeof(ul1mipi_txEvent_T));
   }
   free_ctrl_buffer(ul1_rf_mipi_tx_event_buffer);

}

void nvram_init_uL1_mipiRxData(void)
{
   kal_bool error_no;
   nvram_lid_enum lid;
   kal_uint32 tableIdx;
      
   ul1mipi_rxData_T *ul1_rf_mipi_rx_data_buffer = (ul1mipi_rxData_T *)get_ctrl_buffer(sizeof(ul1mipi_rxData_T));

   for (lid = NVRAM_EF_UL1_MIPI_RX_DATA_START; lid <= NVRAM_EF_UL1_MIPI_RX_DATA_END; lid++)
   {
       error_no = nvram_external_read_data(lid, 1, (kal_uint8 *)ul1_rf_mipi_rx_data_buffer, sizeof(ul1mipi_rxData_T));
       ASSERT(error_no == KAL_TRUE);

       tableIdx = UMTSBand1 + (lid - NVRAM_EF_UL1_MIPI_RX_DATA_START);
       kal_mem_cpy(UMTS_MIPI_RX_DATA_TABLE[tableIdx], ul1_rf_mipi_rx_data_buffer, sizeof(ul1mipi_rxData_T));
   }
   free_ctrl_buffer(ul1_rf_mipi_rx_data_buffer);

}

void nvram_init_uL1_mipiRxEvent(void)
{
   kal_bool error_no;
   nvram_lid_enum lid;
   kal_uint32 tableIdx;
      
   ul1mipi_rxEvent_T *ul1_rf_mipi_rx_event_buffer = (ul1mipi_rxEvent_T *)get_ctrl_buffer(sizeof(ul1mipi_rxEvent_T));

   for (lid = NVRAM_EF_UL1_MIPI_RX_EVENT_START; lid <= NVRAM_EF_UL1_MIPI_RX_EVENT_END; lid++)
   {
       error_no = nvram_external_read_data(lid, 1, (kal_uint8 *)ul1_rf_mipi_rx_event_buffer, sizeof(ul1mipi_rxEvent_T));
       ASSERT(error_no == KAL_TRUE);

       tableIdx = UMTSBand1 + (lid - NVRAM_EF_UL1_MIPI_RX_EVENT_START);
       kal_mem_cpy(UMTS_MIPI_RX_EVENT_TABLE[tableIdx], ul1_rf_mipi_rx_event_buffer, sizeof(ul1mipi_rxEvent_T));
   }
   free_ctrl_buffer(ul1_rf_mipi_rx_event_buffer);

}

void nvram_init_uL1_mipiAsmIso(void)
{
   kal_bool error_no;
   nvram_lid_enum lid;
   kal_uint32 tableIdx;
      
   ul1mipi_asmIsoData_T *ul1_rf_mipi_asm_iso_buffer = (ul1mipi_asmIsoData_T *)get_ctrl_buffer(sizeof(ul1mipi_asmIsoData_T));

   for (lid = NVRAM_EF_UL1_MIPI_ASM_ISOLATION_START; lid <= NVRAM_EF_UL1_MIPI_ASM_ISOLATION_END; lid++)
   {
       error_no = nvram_external_read_data(lid, 1, (kal_uint8 *)ul1_rf_mipi_asm_iso_buffer, sizeof(ul1mipi_asmIsoData_T));
       ASSERT(error_no == KAL_TRUE);

       tableIdx = UMTSBand1 + (lid - NVRAM_EF_UL1_MIPI_ASM_ISOLATION_START);
       kal_mem_cpy(UMTS_MIPI_ASM_ISOLATION_DATA_TABLE[tableIdx], ul1_rf_mipi_asm_iso_buffer, sizeof(ul1mipi_asmIsoData_T));
   }
   free_ctrl_buffer(ul1_rf_mipi_asm_iso_buffer);

}

void nvram_init_uL1_mipiInitCw(void)
{
   kal_bool error_no;

   ul1mipi_initCwData_T *ul1_rf_mipi_init_buffer = (ul1mipi_initCwData_T *)get_ctrl_buffer(sizeof(ul1mipi_initCwData_T));

   error_no = nvram_external_read_data(NVRAM_EF_UL1_MIPI_INIT_CW_LID, 1, (kal_uint8 *)ul1_rf_mipi_init_buffer, sizeof(ul1mipi_initCwData_T));
   ASSERT(error_no == KAL_TRUE);

   kal_mem_cpy(UMTS_MIPI_INITIAL_CW, ul1_rf_mipi_init_buffer, sizeof(ul1mipi_initCwData_T));
   free_ctrl_buffer(ul1_rf_mipi_init_buffer);
}

void nvram_init_uL1_mipiSleepCw(void)
{
   kal_bool error_no;
      
   ul1mipi_sleepCwData_T *ul1_rf_mipi_sleep_buffer = (ul1mipi_sleepCwData_T *)get_ctrl_buffer(sizeof(ul1mipi_sleepCwData_T));

   error_no = nvram_external_read_data(NVRAM_EF_UL1_MIPI_SLEEP_CW_LID, 1, (kal_uint8 *)ul1_rf_mipi_sleep_buffer, sizeof(ul1mipi_sleepCwData_T));
   ASSERT(error_no == KAL_TRUE);

   kal_mem_cpy(UMTS_MIPI_SLEEP_CW, ul1_rf_mipi_sleep_buffer, sizeof(ul1mipi_sleepCwData_T));
   free_ctrl_buffer(ul1_rf_mipi_sleep_buffer);
}

#endif/*IS_3G_MIPI_NVRAM_FULL_SUPPORT*/



#if (IS_3G_MIPI_SUPPORT)
void nvram_init_uL1_mipiData(void)
{
   kal_bool error_no;
   nvram_lid_enum lid;
   kal_uint32 tableIdx;
      
   ul1mipi_tpcData_T *ul1_rf_mipi_data_buffer = (ul1mipi_tpcData_T *)get_ctrl_buffer(sizeof(ul1mipi_tpcData_T));

   for (lid = NVRAM_EF_UL1_MIPI_TPC_START; lid <= NVRAM_EF_UL1_MIPI_TPC_END; lid++)
   {
       error_no = nvram_external_read_data(lid, 1, (kal_uint8 *)ul1_rf_mipi_data_buffer, sizeof(ul1mipi_tpcData_T));
       ASSERT(error_no == KAL_TRUE);

       tableIdx = UMTSBand1 + (lid - NVRAM_EF_UL1_MIPI_TPC_START);
       kal_mem_cpy(UMTS_MIPI_TPC_TABLE[tableIdx], ul1_rf_mipi_data_buffer, sizeof(ul1mipi_tpcData_T));
   }
   free_ctrl_buffer(ul1_rf_mipi_data_buffer);
    
#if (IS_3G_MIPI_NVRAM_FULL_SUPPORT)
   nvram_init_uL1_mipiTxData();
   nvram_init_uL1_mipiTxEvent();
   nvram_init_uL1_mipiRxData();
   nvram_init_uL1_mipiRxEvent();
   nvram_init_uL1_mipiAsmIso();
   nvram_init_uL1_mipiInitCw();
   nvram_init_uL1_mipiSleepCw();
#endif/*IS_3G_MIPI_NVRAM_FULL_SUPPORT*/

}
#endif

#if (IS_3G_ET_NVRAM_SUPPORT)
#if (IS_3G_MIPI_NVRAM_FULL_SUPPORT)
void nvram_init_uL1_mipiEtOnCw(void)
{
   kal_bool error_no;

   ul1mipi_etOnCwData_T *ul1_rf_mipi_et_on_buffer = (ul1mipi_etOnCwData_T *)get_ctrl_buffer(sizeof(ul1mipi_etOnCwData_T));

   error_no = nvram_external_read_data(NVRAM_EF_UL1_MIPI_ET_ON_CW_LID, 1, (kal_uint8 *)ul1_rf_mipi_et_on_buffer, sizeof(ul1mipi_etOnCwData_T));
   ASSERT(error_no == KAL_TRUE);

   kal_mem_cpy(UMTS_MIPI_ET_ON_STATIC_CW, ul1_rf_mipi_et_on_buffer, sizeof(ul1mipi_etOnCwData_T));
   free_ctrl_buffer(ul1_rf_mipi_et_on_buffer);
}

void nvram_init_uL1_mipiEtOffCw(void)
{
   kal_bool error_no;
      
   ul1mipi_etOffCwData_T *ul1_rf_mipi_et_off_buffer = (ul1mipi_etOffCwData_T *)get_ctrl_buffer(sizeof(ul1mipi_etOffCwData_T));

   error_no = nvram_external_read_data(NVRAM_EF_UL1_MIPI_ET_OFF_CW_LID, 1, (kal_uint8 *)ul1_rf_mipi_et_off_buffer, sizeof(ul1mipi_etOffCwData_T));
   ASSERT(error_no == KAL_TRUE);

   kal_mem_cpy(UMTS_MIPI_ET_OFF_STATIC_CW, ul1_rf_mipi_et_off_buffer, sizeof(ul1mipi_etOffCwData_T));
   free_ctrl_buffer(ul1_rf_mipi_et_off_buffer);
}
#if (IS_3G_VPA_SEL_BY_BAND_SUPPORT)
void nvram_init_uL1_vpaSrcSel(void)
{
  kal_bool error_no;
  nvram_lid_enum lid;
  kal_uint32 tableIdx;

  ul1vpa_sel_T *ul1_rf_vpa_src_sel_buffer = (ul1vpa_sel_T *)get_ctrl_buffer(sizeof(ul1vpa_sel_T));

  for (lid = NVRAM_EF_UL1_VPA_SRC_SEL_START; lid <= NVRAM_EF_UL1_VPA_SRC_SEL_END; lid++)
  {
      error_no = nvram_external_read_data(lid, 1, (kal_uint8 *)ul1_rf_vpa_src_sel_buffer, sizeof(ul1vpa_sel_T));
      ASSERT(error_no == KAL_TRUE);
  
      tableIdx = UMTSBand1 + (lid - NVRAM_EF_UL1_VPA_SRC_SEL_START);
      kal_mem_cpy(&UMTS_VPA_SRC_SEL_TABLE[tableIdx], ul1_rf_vpa_src_sel_buffer, sizeof(ul1vpa_sel_T));
  }
  free_ctrl_buffer(ul1_rf_vpa_src_sel_buffer);
}
#endif/*IS_3G_VPA_SEL_BY_BAND_SUPPORT*/

#endif/*IS_3G_MIPI_NVRAM_FULL_SUPPORT*/


void nvram_init_uL1_etData(void)
{
   kal_bool error_no;
   nvram_lid_enum lid;
   kal_uint32 tableIdx;
      
   ul1mipi_etData_T *ul1_rf_mipi_data_buffer = (ul1mipi_etData_T *)get_ctrl_buffer(sizeof(ul1mipi_etData_T));

   for (lid = NVRAM_EF_UL1_MIPI_ET_START; lid <= NVRAM_EF_UL1_MIPI_ET_END; lid++)
   {
       error_no = nvram_external_read_data(lid, 1, (kal_uint8 *)ul1_rf_mipi_data_buffer, sizeof(ul1mipi_etData_T));
       ASSERT(error_no == KAL_TRUE);

       tableIdx = UMTSBand1 + (lid - NVRAM_EF_UL1_MIPI_ET_START);
       kal_mem_cpy(UMTS_MIPI_ET_TABLE[tableIdx], ul1_rf_mipi_data_buffer, sizeof(ul1mipi_etData_T));
   }
   free_ctrl_buffer(ul1_rf_mipi_data_buffer);

#if (IS_3G_MIPI_NVRAM_FULL_SUPPORT)
   nvram_init_uL1_mipiEtOnCw();
   nvram_init_uL1_mipiEtOffCw();
#if (IS_3G_VPA_SEL_BY_BAND_SUPPORT)
   nvram_init_uL1_vpaSrcSel();
#endif/*IS_3G_VPA_SEL_BY_BAND_SUPPORT*/

#endif/*IS_3G_MIPI_NVRAM_FULL_SUPPORT*/

}
#endif/*IS_3G_ET_NVRAM_SUPPORT*/

#if (IS_3G_TAS_NVRAM_SUPPORT)
void nvram_init_uL1_tasRf(void)
{
   kal_bool error_no;
      
   U_sUl1dRfTasData *ul1_tas_rf_buffer = (U_sUl1dRfTasData *)get_ctrl_buffer(sizeof(U_sUl1dRfTasData));

   error_no = nvram_external_read_data(NVRAM_EF_UL1_TAS_RF_LID, 1, (kal_uint8 *)ul1_tas_rf_buffer, sizeof(U_sUl1dRfTasData));
   ASSERT(error_no == KAL_TRUE);

   kal_mem_cpy(&UMTS_TAS_RF_TABLE, ul1_tas_rf_buffer, sizeof(U_sUl1dRfTasData));
   free_ctrl_buffer(ul1_tas_rf_buffer);
}

void nvram_init_uL1_tasCustom(void)
{
   kal_bool error_no;
      
   U_sUl1dRfTasData *ul1_tas_custom_buffer = (UMTS_TAS_Configuration_T *)get_ctrl_buffer(sizeof(UMTS_TAS_Configuration_T));

   error_no = nvram_external_read_data(NVRAM_EF_UL1_TAS_CUSTOM_LID, 1, (kal_uint8 *)ul1_tas_custom_buffer, sizeof(UMTS_TAS_Configuration_T));
   ASSERT(error_no == KAL_TRUE);

   kal_mem_cpy(&UMTS_TAS_Configuration_Table, ul1_tas_custom_buffer, sizeof(UMTS_TAS_Configuration_T));
   free_ctrl_buffer(ul1_tas_custom_buffer);
}

#endif/*IS_3G_TAS_NVRAM_SUPPORT*/

#endif /* __MTK_TARGET__ */ 


/*****************************************************************************
 * FUNCTION
 *  nvram_get_L1_default_value_to_write
 * DESCRIPTION
 *  
 * PARAMETERS
 *  lid         [IN]        
 *  buffer      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MTK_TARGET__

#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)

   /********************************************************/
   /* MT6573 3G RF Customization for Modem Bin Update Tool */
   /********************************************************/
const kal_uint16 UL_BAND_MIN_UARFCN[] = {0, 9612, 9262, 937, 1312, 4132, 4162, 2012, 2712, 8762, 2887, 3487, 3617, 3792, 3892, 0, 0, 0, 0, 312, 4287, 462, 4437};
const kal_uint16 UL_BAND_MAX_UARFCN[] = {0, 9888, 9538, 1288, 1513, 4233, 4188, 2338, 2863, 8912, 3163, 3562, 3678, 3818, 3918, 0, 0, 0, 0, 363, 4413, 512, 4813};
const kal_uint16 UL_BAND_MIN_UARFCN_ADDITIONAL[] = {0, 0, 12, 0, 1662, 782, 812, 2362, 0, 0, 3187, 0, 3707, 3842, 3942, 0, 0, 0, 0, 387, 0, 0, 0};
const kal_uint16 UL_BAND_MAX_UARFCN_ADDITIONAL[] = {0, 0, 287, 0, 1862, 862, 837, 2687, 0, 0, 3462, 0, 3767, 3867, 3967, 0, 0, 0, 0, 437, 0, 0, 0};
kal_uint8 band_to_bandInd_map_table[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void nvram_sort_uL1_band_bandind_mapping(kal_uint8 band_indicator)
{
    kal_uint8 table_index;

    if ( band_indicator > UMTSBandNone )
    {
       table_index = RF_GET_CAL_DATA_ARRAY_BAND_IDX((UMTSBand)band_indicator, KAL_FALSE);
       band_to_bandInd_map_table[band_indicator] = table_index;
    }
}


#endif /* #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__) */

#endif /* __MTK_TARGET__ */

void nvram_get_uL1_default_value_to_write(nvram_lid_enum lid, kal_uint8 *buffer, kal_uint16 buffer_size)
{
#ifdef __MTK_TARGET__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//chliu
    UMTSBand uband = UMTSBandNone;
    kal_uint8 index_select;
    ul1cal_tempdacData_T  *tempdac;
    ul1cal_pathlossData_T *pathloss;
    ul1cal_txdacData_T    *txdac;
/* end of chliu */
    ul1cal_txPrachTmCompData_T *txPrachTmComp;
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
    ul1cal_txPaOctLevData_T *pacoctlev_handle;
#endif // #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)

#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)

   /* Do not need to get band indicator prior to get UL1 default value if user
    * modifies setting by Modem Bin Update Tool, since in MT6573/MT6276 3G RF
    * customization scenario the band indicator in run-time directly modified
    * by customer via Modem Bin Update tool or via ul1d_custom_rf.h
    */
#if defined (__UL1_HS_PLUS_PLATFORM__)
   ul1d_BandInfo[0] = UMTS_RF_CUSTOM_INPUT_DATA.umtsBandIndicator.HB1;
   ul1d_BandInfo[1] = UMTS_RF_CUSTOM_INPUT_DATA.umtsBandIndicator.HB2;
   ul1d_BandInfo[2] = UMTS_RF_CUSTOM_INPUT_DATA.umtsBandIndicator.HB3;
   ul1d_BandInfo[3] = UMTS_RF_CUSTOM_INPUT_DATA.umtsBandIndicator.LB1;
   ul1d_BandInfo[4] = UMTS_RF_CUSTOM_INPUT_DATA.umtsBandIndicator.LB2;    
#else
   rxHighBand1Indicator = UMTS_RF_CUSTOM_INPUT_DATA.umtsBandIndicator.HB1;
   rxHighBand2Indicator = UMTS_RF_CUSTOM_INPUT_DATA.umtsBandIndicator.HB2;
   rxLowBand1Indicator = UMTS_RF_CUSTOM_INPUT_DATA.umtsBandIndicator.LB1;
   #if IS_RF_MT6162
   rxLowBand2Indicator = UMTS_RF_CUSTOM_INPUT_DATA.umtsBandIndicator.LB2;
   #endif
#endif


#if defined (__UL1_HS_PLUS_PLATFORM__)
   /* Produce band to band indicator mapping array */
   nvram_sort_uL1_band_bandind_mapping(ul1d_BandInfo[0]);
   nvram_sort_uL1_band_bandind_mapping(ul1d_BandInfo[1]);
   nvram_sort_uL1_band_bandind_mapping(ul1d_BandInfo[2]);
   nvram_sort_uL1_band_bandind_mapping(ul1d_BandInfo[3]);
   nvram_sort_uL1_band_bandind_mapping(ul1d_BandInfo[4]);
#else
   nvram_sort_uL1_band_bandind_mapping(rxHighBand1Indicator);
   nvram_sort_uL1_band_bandind_mapping(rxHighBand2Indicator);
   nvram_sort_uL1_band_bandind_mapping(rxLowBand1Indicator);
   #if IS_RF_MT6162
   nvram_sort_uL1_band_bandind_mapping(rxLowBand2Indicator);
   #endif
#endif

#endif /* #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (lid)
    {
//chliu
        case NVRAM_EF_UL1_TEMP_DAC_LID:
            #if 0
/* under construction !*/
/* under construction !*/
            #else
            kal_mem_cpy(buffer, U_TEMP_DAC, sizeof(ul1cal_tempdacData_T));            
            UNUSED(tempdac);
            #endif
            break;
        case NVRAM_EF_UL1_PATHLOSS_BAND1_LID:
        case NVRAM_EF_UL1_PATHLOSS_BAND2_LID:
        case NVRAM_EF_UL1_PATHLOSS_BAND3_LID:
        case NVRAM_EF_UL1_PATHLOSS_BAND4_LID:
        case NVRAM_EF_UL1_PATHLOSS_BAND5_LID:
        case NVRAM_EF_UL1_PATHLOSS_BAND6_LID:
        case NVRAM_EF_UL1_PATHLOSS_BAND7_LID:
        case NVRAM_EF_UL1_PATHLOSS_BAND8_LID:
        case NVRAM_EF_UL1_PATHLOSS_BAND9_LID:
        case NVRAM_EF_UL1_PATHLOSS_BAND10_LID:
        case NVRAM_EF_UL1_PATHLOSS_BAND11_LID:
        case NVRAM_EF_UL1_PATHLOSS_BAND19_LID:
            {
               pathloss = (ul1cal_pathlossData_T*) buffer;
               uband = UMTSBand1 + (lid - NVRAM_EF_UL1_PATHLOSS_BAND1_LID);

               index_select = band_to_bandInd_map_table[uband];



               if (U_AGC_PATHLOSS_TABLE[index_select] != 0)
               {
               	#ifdef __UMTS_R8__
                  UL1D_RF_SetDefaultCalDataDetection(index_select);
                #endif
                  kal_mem_cpy(buffer, U_AGC_PATHLOSS_TABLE[index_select], sizeof(ul1cal_pathlossData_T));
                  UNUSED(pathloss);
               }
            }
            break;
        case NVRAM_EF_UL1_TXDAC_BAND1_LID:
        case NVRAM_EF_UL1_TXDAC_BAND2_LID:
        case NVRAM_EF_UL1_TXDAC_BAND3_LID:
        case NVRAM_EF_UL1_TXDAC_BAND4_LID:
        case NVRAM_EF_UL1_TXDAC_BAND5_LID:
        case NVRAM_EF_UL1_TXDAC_BAND6_LID:
        case NVRAM_EF_UL1_TXDAC_BAND7_LID:
        case NVRAM_EF_UL1_TXDAC_BAND8_LID:
        case NVRAM_EF_UL1_TXDAC_BAND9_LID:
        case NVRAM_EF_UL1_TXDAC_BAND10_LID:
        case NVRAM_EF_UL1_TXDAC_BAND11_LID:
        case NVRAM_EF_UL1_TXDAC_BAND19_LID:
            {
               txdac = (ul1cal_txdacData_T*) buffer;
               uband = UMTSBand1 + (lid - NVRAM_EF_UL1_TXDAC_BAND1_LID);

               index_select = band_to_bandInd_map_table[uband];
               if (UMTS_RampData[index_select] != 0)
               {
                  kal_mem_cpy(buffer, UMTS_RampData[index_select], sizeof(U_sRAMPDATA));
                  UNUSED(txdac);
               }
            }
            break;
/* end of chliu */
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
        /* PA 8-level control */
        case NVRAM_EF_UL1_TXPAOCTLEV_BAND1_LID:
        case NVRAM_EF_UL1_TXPAOCTLEV_BAND2_LID:
        case NVRAM_EF_UL1_TXPAOCTLEV_BAND3_LID:
        case NVRAM_EF_UL1_TXPAOCTLEV_BAND4_LID:
        case NVRAM_EF_UL1_TXPAOCTLEV_BAND5_LID:
        case NVRAM_EF_UL1_TXPAOCTLEV_BAND6_LID:
        case NVRAM_EF_UL1_TXPAOCTLEV_BAND7_LID:
        case NVRAM_EF_UL1_TXPAOCTLEV_BAND8_LID:
        case NVRAM_EF_UL1_TXPAOCTLEV_BAND9_LID:
        case NVRAM_EF_UL1_TXPAOCTLEV_BAND10_LID:
        case NVRAM_EF_UL1_TXPAOCTLEV_BAND11_LID:
        case NVRAM_EF_UL1_TXPAOCTLEV_BAND19_LID:
            {
               pacoctlev_handle = (ul1cal_txPaOctLevData_T*) buffer;
               uband = UMTSBand1 + (lid - NVRAM_EF_UL1_TXPAOCTLEV_BAND1_LID);         
               index_select = RF_GET_CAL_DATA_ARRAY_BAND_IDX(uband, KAL_TRUE);

               if (U_PA_OCTLEV_TABLE[index_select] != 0)
               {
                   kal_mem_cpy(buffer, U_PA_OCTLEV_TABLE[index_select], sizeof(U_sPAOCTLVLSETTING));
                   UNUSED(pacoctlev_handle);
               }
            }
            break;
        /* End of PA 8-level control */
        case NVRAM_EF_UL1_3G_RF_PARAMETER_LID:
            kal_mem_cpy(buffer, &UMTS_RF_CUSTOM_INPUT_DATA, sizeof(U_sUl1dRfCustomInputData));            
            break;
#endif // #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)

#if defined(__UMTS_R8__) //add by Jay
        case NVRAM_EF_UL1_PATHLOSS2_BAND1_LID:
        case NVRAM_EF_UL1_PATHLOSS2_BAND2_LID:
        case NVRAM_EF_UL1_PATHLOSS2_BAND3_LID:
        case NVRAM_EF_UL1_PATHLOSS2_BAND4_LID:
        case NVRAM_EF_UL1_PATHLOSS2_BAND5_LID:
        case NVRAM_EF_UL1_PATHLOSS2_BAND6_LID:
        case NVRAM_EF_UL1_PATHLOSS2_BAND7_LID:
        case NVRAM_EF_UL1_PATHLOSS2_BAND8_LID:
        case NVRAM_EF_UL1_PATHLOSS2_BAND9_LID:
        case NVRAM_EF_UL1_PATHLOSS2_BAND10_LID:
        case NVRAM_EF_UL1_PATHLOSS2_BAND11_LID:
        case NVRAM_EF_UL1_PATHLOSS2_BAND19_LID:
            {
               uband = UMTSBand1 + (lid - NVRAM_EF_UL1_PATHLOSS2_BAND1_LID);
               index_select = band_to_bandInd_map_table[uband];
               if (U_AGC_PATHLOSS_RXD_TABLE[index_select] != 0)
               {
                  kal_mem_cpy(buffer, U_AGC_PATHLOSS_RXD_TABLE[index_select], sizeof(ul1cal_pathlossRxdData_T));
               }
            }
            break;
   //add by wilson for pa drift compensation
        case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND1_LID:
        case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND2_LID:
        case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND3_LID:
        case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND4_LID:
        case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND5_LID:
        case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND6_LID:
        case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND7_LID:
        case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND8_LID:
        case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND9_LID:
        case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND10_LID:
        case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND11_LID:
        case NVRAM_EF_UL1_TXPADRIFTCOMP_BAND19_LID:
            {
               uband = UMTSBand1 + (lid - NVRAM_EF_UL1_TXPADRIFTCOMP_BAND1_LID);
               index_select = band_to_bandInd_map_table[uband];
               if (U_PA_DRIFT_TABLE[index_select] != 0)
               {
                  kal_mem_cpy(buffer, U_PA_DRIFT_TABLE[index_select], sizeof(ul1cal_txPaDriftCompData_T));
               }
            }
            break;
#endif //defined(__UMTS_R8__)

        /** Tx PRACH TM Compensation */
        case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND1_LID:
        case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND2_LID:
        case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND3_LID:
        case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND4_LID:
        case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND5_LID:
        case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND6_LID:
        case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND7_LID:
        case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND8_LID:
        case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND9_LID:
        case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND10_LID:
        case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND11_LID:
        case NVRAM_EF_UL1_TXPRACHTMCOMP_BAND19_LID:
            {
               txPrachTmComp = (ul1cal_txPrachTmCompData_T*) buffer;
               uband = UMTSBand1 + (lid - NVRAM_EF_UL1_TXPRACHTMCOMP_BAND1_LID);

               index_select = band_to_bandInd_map_table[uband];
               if (U_PA_RACH_COMP_TABLE[index_select] != 0)
               {
                  kal_mem_cpy(buffer, U_PA_RACH_COMP_TABLE[index_select], sizeof(ul1cal_txPrachTmCompData_T));
                  UNUSED(txPrachTmComp);
               }
            }
            break;

        case NVRAM_EF_UL1_AFCDAC_LID:
            {
               kal_mem_cpy(buffer, &U_AFC_DAC, sizeof(ul1cal_afcDacData_T));
            }
            break;

        case NVRAM_EF_UL1_AFCCAP_LID:
            {
               kal_mem_cpy(buffer, &U_AFC_CAP, sizeof(ul1cal_afcCapData_T));
            }
            break;

#if (IS_3G_MIPI_SUPPORT)
        case NVRAM_EF_UL1_MIPI_TPC_HIGHBAND1_LID:
        case NVRAM_EF_UL1_MIPI_TPC_HIGHBAND2_LID:
        case NVRAM_EF_UL1_MIPI_TPC_HIGHBAND3_LID:
        case NVRAM_EF_UL1_MIPI_TPC_LOWBAND1_LID:
        case NVRAM_EF_UL1_MIPI_TPC_LOWBAND2_LID:
            {
               index_select = UMTSBand1 + (lid - NVRAM_EF_UL1_MIPI_TPC_HIGHBAND1_LID);
               if (UMTS_MIPI_TPC_TABLE[index_select] != 0)
               {
                  kal_mem_cpy(buffer, UMTS_MIPI_TPC_TABLE[index_select], sizeof(ul1mipi_tpcData_T));            
               }
            }
            break;
#endif
#if (IS_3G_ET_NVRAM_SUPPORT)
        case NVRAM_EF_UL1_MIPI_ET_HIGHBAND1_LID:
        case NVRAM_EF_UL1_MIPI_ET_HIGHBAND2_LID:
        case NVRAM_EF_UL1_MIPI_ET_HIGHBAND3_LID:
        case NVRAM_EF_UL1_MIPI_ET_LOWBAND1_LID:
        case NVRAM_EF_UL1_MIPI_ET_LOWBAND2_LID:
            {
               index_select = UMTSBand1 + (lid - NVRAM_EF_UL1_MIPI_ET_HIGHBAND1_LID);
               if (UMTS_MIPI_ET_TABLE[index_select] != 0)
               {
                  kal_mem_cpy(buffer, UMTS_MIPI_ET_TABLE[index_select], sizeof(ul1mipi_etData_T));
               }
            }
            break;
#endif/*IS_3G_ET_NVRAM_SUPPORT*/

#if (IS_3G_MIPI_NVRAM_FULL_SUPPORT)
        case NVRAM_EF_UL1_MIPI_RX_EVENT_HIGHBAND1_LID:
        case NVRAM_EF_UL1_MIPI_RX_EVENT_HIGHBAND2_LID:
        case NVRAM_EF_UL1_MIPI_RX_EVENT_HIGHBAND3_LID:
        case NVRAM_EF_UL1_MIPI_RX_EVENT_LOWBAND1_LID:
        case NVRAM_EF_UL1_MIPI_RX_EVENT_LOWBAND2_LID:
            {
               index_select = UMTSBand1 + (lid - NVRAM_EF_UL1_MIPI_RX_EVENT_HIGHBAND1_LID);
               if (UMTS_MIPI_RX_EVENT_TABLE[index_select] != 0)
               {
                  kal_mem_cpy(buffer, UMTS_MIPI_RX_EVENT_TABLE[index_select], sizeof(ul1mipi_rxEvent_T));
               }
            }
            break;
        case NVRAM_EF_UL1_MIPI_RX_DATA_HIGHBAND1_LID:
        case NVRAM_EF_UL1_MIPI_RX_DATA_HIGHBAND2_LID:
        case NVRAM_EF_UL1_MIPI_RX_DATA_HIGHBAND3_LID:
        case NVRAM_EF_UL1_MIPI_RX_DATA_LOWBAND1_LID:
        case NVRAM_EF_UL1_MIPI_RX_DATA_LOWBAND2_LID:
            {
               index_select = UMTSBand1 + (lid - NVRAM_EF_UL1_MIPI_RX_DATA_HIGHBAND1_LID);
               if (UMTS_MIPI_RX_DATA_TABLE[index_select] != 0)
               {
                  kal_mem_cpy(buffer, UMTS_MIPI_RX_DATA_TABLE[index_select], sizeof(ul1mipi_rxData_T));
               }
            }
            break;
        case NVRAM_EF_UL1_MIPI_TX_EVENT_HIGHBAND1_LID:
        case NVRAM_EF_UL1_MIPI_TX_EVENT_HIGHBAND2_LID:
        case NVRAM_EF_UL1_MIPI_TX_EVENT_HIGHBAND3_LID:
        case NVRAM_EF_UL1_MIPI_TX_EVENT_LOWBAND1_LID:
        case NVRAM_EF_UL1_MIPI_TX_EVENT_LOWBAND2_LID:
            {
               index_select = UMTSBand1 + (lid - NVRAM_EF_UL1_MIPI_TX_EVENT_HIGHBAND1_LID);
               if (UMTS_MIPI_TX_EVENT_TABLE[index_select] != 0)
               {
                  kal_mem_cpy(buffer, UMTS_MIPI_TX_EVENT_TABLE[index_select], sizeof(ul1mipi_txEvent_T));
               }
            }
            break;
        case NVRAM_EF_UL1_MIPI_TX_DATA_HIGHBAND1_LID:
        case NVRAM_EF_UL1_MIPI_TX_DATA_HIGHBAND2_LID:
        case NVRAM_EF_UL1_MIPI_TX_DATA_HIGHBAND3_LID:
        case NVRAM_EF_UL1_MIPI_TX_DATA_LOWBAND1_LID:
        case NVRAM_EF_UL1_MIPI_TX_DATA_LOWBAND2_LID:
            {
               index_select = UMTSBand1 + (lid - NVRAM_EF_UL1_MIPI_TX_DATA_HIGHBAND1_LID);
               if (UMTS_MIPI_TX_DATA_TABLE[index_select] != 0)
               {
                  kal_mem_cpy(buffer, UMTS_MIPI_TX_DATA_TABLE[index_select], sizeof(ul1mipi_txData_T));
               }
            }
            break;
        case NVRAM_EF_UL1_MIPI_ASM_ISOLATION_HIGHBAND1_LID:
        case NVRAM_EF_UL1_MIPI_ASM_ISOLATION_HIGHBAND2_LID:
        case NVRAM_EF_UL1_MIPI_ASM_ISOLATION_HIGHBAND3_LID:
        case NVRAM_EF_UL1_MIPI_ASM_ISOLATION_LOWBAND1_LID:
        case NVRAM_EF_UL1_MIPI_ASM_ISOLATION_LOWBAND2_LID:
            {
               index_select = UMTSBand1 + (lid - NVRAM_EF_UL1_MIPI_ASM_ISOLATION_HIGHBAND1_LID);
               if (UMTS_MIPI_ASM_ISOLATION_DATA_TABLE[index_select] != 0)
               {
                  kal_mem_cpy(buffer, UMTS_MIPI_ASM_ISOLATION_DATA_TABLE[index_select], sizeof(ul1mipi_asmIsoData_T));
               }
            }
            break;
        case NVRAM_EF_UL1_MIPI_INIT_CW_LID:
            {
               kal_mem_cpy(buffer, UMTS_MIPI_INITIAL_CW, sizeof(ul1mipi_initCwData_T));
            }
            break;
        case NVRAM_EF_UL1_MIPI_SLEEP_CW_LID:
            {
               kal_mem_cpy(buffer, UMTS_MIPI_SLEEP_CW, sizeof(ul1mipi_sleepCwData_T));
            }
            break;
#if (IS_3G_ET_NVRAM_SUPPORT)
        case NVRAM_EF_UL1_MIPI_ET_ON_CW_LID:
            {
               kal_mem_cpy(buffer, UMTS_MIPI_ET_ON_STATIC_CW, sizeof(ul1mipi_etOnCwData_T));
            }
            break;
        case NVRAM_EF_UL1_MIPI_ET_OFF_CW_LID:
            {
               kal_mem_cpy(buffer, UMTS_MIPI_ET_OFF_STATIC_CW, sizeof(ul1mipi_etOffCwData_T));
            }
            break;
#endif/*IS_3G_ET_NVRAM_SUPPORT*/

#if (IS_3G_VPA_SEL_BY_BAND_SUPPORT)
case NVRAM_EF_UL1_VPA_SRC_SEL_HIGHBAND1_LID:
case NVRAM_EF_UL1_VPA_SRC_SEL_HIGHBAND2_LID:
case NVRAM_EF_UL1_VPA_SRC_SEL_HIGHBAND3_LID:
case NVRAM_EF_UL1_VPA_SRC_SEL_LOWBAND1_LID:
case NVRAM_EF_UL1_VPA_SRC_SEL_LOWBAND2_LID:
    {
       index_select = UMTSBand1 + (lid - NVRAM_EF_UL1_VPA_SRC_SEL_HIGHBAND1_LID);
       if (UMTS_VPA_SRC_SEL_TABLE[index_select] != 0)
       {
          kal_mem_cpy(buffer, &UMTS_VPA_SRC_SEL_TABLE[index_select], sizeof(ul1vpa_sel_T));
       }
    }
    break;
#endif/*IS_3G_VPA_SEL_BY_BAND_SUPPORT*/

#endif/*IS_3G_MIPI_NVRAM_FULL_SUPPORT*/

#if IS_3G_TX_POWER_OFFSET_SUPPORT
         /* Tx power offset table 1 */
         case NVRAM_EF_UL1_TXPOWEROFFSET_BAND1_LID:
         case NVRAM_EF_UL1_TXPOWEROFFSET_BAND2_LID:
         case NVRAM_EF_UL1_TXPOWEROFFSET_BAND3_LID:
         case NVRAM_EF_UL1_TXPOWEROFFSET_BAND4_LID:
         case NVRAM_EF_UL1_TXPOWEROFFSET_BAND5_LID:
         case NVRAM_EF_UL1_TXPOWEROFFSET_BAND6_LID:
         case NVRAM_EF_UL1_TXPOWEROFFSET_BAND7_LID:
         case NVRAM_EF_UL1_TXPOWEROFFSET_BAND8_LID:
         case NVRAM_EF_UL1_TXPOWEROFFSET_BAND9_LID:
         case NVRAM_EF_UL1_TXPOWEROFFSET_BAND10_LID:
         case NVRAM_EF_UL1_TXPOWEROFFSET_BAND11_LID:
         case NVRAM_EF_UL1_TXPOWEROFFSET_BAND19_LID:
            {
               uband = UMTSBand1 + (lid - NVRAM_EF_UL1_TXPOWEROFFSET_BAND1_LID);
               index_select = band_to_bandInd_map_table[uband];
               if (U_TX_POWER_OFFSET_TABLE[index_select] != 0)
               {
                  kal_mem_cpy(buffer, U_TX_POWER_OFFSET_TABLE[index_select], sizeof(ul1cal_txPowerOffsetData_T));
               }
            }
            break;
#endif /* IS_3G_TX_POWER_OFFSET_SUPPORT */
#if (IS_3G_TAS_NVRAM_SUPPORT)
        case NVRAM_EF_UL1_TAS_RF_LID:
            {
               kal_mem_cpy(buffer, &UMTS_TAS_RF_TABLE, sizeof(U_sUl1dRfTasData));
            }
            break;
            
        case NVRAM_EF_UL1_TAS_CUSTOM_LID:
            {
               kal_mem_cpy(buffer, &UMTS_TAS_Configuration_Table, sizeof(UMTS_TAS_Configuration_T));
            }
            break;
#endif/*IS_3G_TAS_NVRAM_SUPPORT*/

        default:
            ASSERT(KAL_FALSE);
            break;
    }
#endif /* #ifdef __MTK_TARGET__ */
}



#endif /* __UMTS_RAT__ && __MTK_UL1_FDD__ */
