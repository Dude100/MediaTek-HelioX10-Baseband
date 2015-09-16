/*******************************************************************************
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
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *   el1_drdi.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Dynamic Radio-setting Dedicated Image.
 *   The structure definition of EL1 DRDI data
 *
 * Author:
 * -------
 * -------
 *
 *=============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *-----------------------------------------------------------------------------
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *-----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *=============================================================================
 ******************************************************************************/
#ifndef _EL1_DRDI_H_
#define _EL1_DRDI_H_

/*============================================================================*/

#include "kal_general_types.h"
#include "el1_rf_public.h"
#include "dcl.h"        //SmartPhone Project's CommonModemImage need this

/*============================================================================*/


/*****************************************************************************
* Constant    : EL1_CUSTOM_MAX_RF_BPI_EVENT_NUM
* Group       : Real target, Internal, EL1D common operation
* Description : Constant to be used for record the maximum 4G BPI event
*               support numbers currently in use
*****************************************************************************/
#define EL1_CUSTOM_MAX_RF_BPI_EVENT_NUM      (6)

/*****************************************************************************
* Constant    : EL1_CUSTOM_MAX_RF_SUPPORT_BAND_NUM
* Group       : Real target, Internal, EL1D common operation
* Description : Constant to be used for record the maximum 4G RF band
*               support numbers currently in use
*****************************************************************************/
#define EL1_CUSTOM_MAX_RF_SUPPORT_BAND_NUM   (LTE_TARGET_MAX_SUPPORT_BAND_NUM)   //MT6290 support 14 bands

/*****************************************************************************
* Constant    : EL1_CUSTOM_MAX_RF_SPLIT_NUM
* Group       : Real target, Internal, EL1D common operation
* Description : Constant to be used for record how many bands need to split
*****************************************************************************/
#define EL1_CUSTOM_MAX_RF_SPLIT_BAND          LTE_ERF_SPLIT_BAND

/*****************************************************************************
* Constant    : EL1_CUSTOM_MAX_RF_MAX_SPLIT_PART
* Group       : Real target, Internal, EL1D common operation
* Description : Constant to be used for record how many splitting parts each band
*****************************************************************************/
#define EL1_CUSTOM_MAX_RF_MAX_SPLIT_PART      LTE_ERF_MAX_SPLIT_PART

/*****************************************************************************
* Constant    : EL1_CUSTOM_MAX_RF_SPLIT_NUM
* Group       : Real target, Internal, EL1D common operation
* Description : Constant to be used for record the splitting band settings
*               support numbers currently in use
*****************************************************************************/
#define EL1_CUSTOM_MAX_RF_SPLIT_NUM           LTE_ERF_SPLIT_NUM

/*****************************************************************************
* Constant    : EL1_CUSTOM_MIPI_BYPASS_MAX_SUPPORT_BAND_NUM (MIPI BYPASS DRDI)
* Group       : Real target, Internal, EL1D common operation
* Description : Constant to be used to determine the max number of bands
*               supported by MIPI bypass feature
*****************************************************************************/
#define EL1_CUSTOM_MIPI_BYPASS_MAX_SUPPORT_BAND_NUM   LTE_MIPI_BYPASS_MAX_SUPPORT_BAND_NUM

/*****************************************************************************
* Constant    : EL1_CUSTOM_GPIO_MAX_NUM_OF_DEFINED_DETECT_PIN_NAME
* Group       : Real target, Internals, UL1D common operation
* Description : Constant to be used to determine the max number of GPIO
*               detection pin names defined so far at AP side GPIO driver
*****************************************************************************/
#define EL1_CUSTOM_GPIO_MAX_NUM_OF_DEFINED_DETECT_PIN_NAME  (3)


/*****************************************************************************
* Constant    : EL1_CUSTOM_NULL_ACTION_ID
*               EL1_CUSTOM_GPIO_DETECTION_ID
*               EL1_CUSTOM_ADC_DETECTION_ID
*               EL1_CUSTOM_BARCODE_DETECTION_ID
* Group       : Real target, Internals, EL1D common operation
* Description : Constant to be used to define the value to be used in
*               enumeration Ul1CustomActionId
*****************************************************************************/
#define EL1_CUSTOM_NULL_ACTION_ID         (0)
#define EL1_CUSTOM_GPIO_DETECTION_ID      (1)
#define EL1_CUSTOM_ADC_DETECTION_ID       (2)
#define EL1_CUSTOM_BARCODE_DETECTION_ID   (3)


/*****************************************************************************
* Typedef     : El1CustomDynamicInitUmtsBpiData
* Group       : Real target, Internals, EL1D common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               4G BPI data
*****************************************************************************/
typedef struct
{
   /* User input to notify the band of the data to be modified */
   LTE_Band   bandToModify;

   /* ASM logics */
   kal_uint32 asmLogics[EL1_CUSTOM_MAX_RF_BPI_EVENT_NUM];

} El1CustomDynamicInitLteBpiData;


/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteRxLnaPortTxPath
* Group       : Real target, Internals, EL1D common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               for Rx LNA port and Tx path setting
*****************************************************************************/
typedef struct
{
   /* User input to notify the band of the data to be modified */
   LTE_Band   bandToModify;

   /* LNA port selection */
   kal_uint8  lnaPortNum;

   /* RXD LNA port selection */
   kal_uint8  lnaPortNum2;

   /* TX output path selection */
   kal_uint8  txOutputSel; 

} El1CustomDynamicInitLteRxLnaPortTxPath;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteSplitBandInd
* Group       : Real target, Internals, EL1D common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               4G band spliting indicator
*****************************************************************************/
typedef struct
{
   /* User input to notify the band of the data to be modified */
   LTE_Band   bandToModify;

   /* Number of splitting bands */
   kal_uint16 SplitNum;

   /* The end DL frequency */
   kal_uint16 SplitBandEndDL[LTE_ERF_MAX_SPLIT_PART];

   /* The end UL frequency */
   kal_uint16 SplitBandEndUL[LTE_ERF_MAX_SPLIT_PART];

   /* The real HW power difference between bypass path and filter path */
   kal_int16  PowerCompensation;

   /* The expected power difference between bypass path and filter path */
   kal_int16  CouplerCompensation;
} El1CustomDynamicInitLteSplitBandInd;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteRfData
* Group       : Real target, Internals, EL1D common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               4G BPI data / Rx LNA port and Tx path setting
*****************************************************************************/
typedef struct
{
   /* User input to notify the band of the data to be modified */
   LTE_Band   bandToModify;

   /* ASM logics */
   kal_uint32 asmLogics[EL1_CUSTOM_MAX_RF_BPI_EVENT_NUM];

   /* LNA port selection */
   kal_uint8  lnaPortNum;

   /* RXD LNA port selection */
   kal_uint8  lnaPortNum2;

   /* TX output path selection */
   kal_uint8  txOutputSel; 

} El1CustomDynamicInitLteSplitRfData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteMipiBypassInfo (MIPI BYPASS DRDI)
* Group       : Real target, Internals, EL1D common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               Bands and TX power compensation info for MIPI bypass feature
*****************************************************************************/
typedef struct
{
   /* User input to notify the band of the data to be modified */
   LTE_Band   bandToModify;

   /* The real HW power difference between bypass path and filter path */
   kal_int16  PowerCompensation;

   /* The expected power difference between bypass path and filter path */
   kal_int16  CouplerCompensation;

} El1CustomDynamicInitLteMipiBypassInfo;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteTASParameter (TAS DRDI)
* Group       : Real target, Internals, EL1D common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               Transmit Antenna Selection settings
*****************************************************************************/
typedef struct
{
   /* Band indicator */
   ERF_TAS_BAND_IND_T TASBandInd;

   /* BPI logic settings */
   kal_uint32         TASRfDatabase[LTE_ERF_TAS_TOTAL_NUM];

} El1CustomDynamicInitLteTASParameter;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteTxRampData
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE Tx Ramp data
*****************************************************************************/
typedef struct
{
   /* LTE TX Ramp data array */
   LTE_sRAMPDATA *TxRampData[EL1_CUSTOM_MAX_RF_SUPPORT_BAND_NUM];

} El1CustomDynamicInitLteTxRampData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteTxPaOctLvlData
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE Tx PA oct-level data
*****************************************************************************/
typedef struct
{
   /* LTE TX oct-level data array */
   LTE_sPAOCTLVLSETTING *TxPaOctLvl[EL1_CUSTOM_MAX_RF_SUPPORT_BAND_NUM];

} El1CustomDynamicInitLteTxPaOctLvlData;

/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteRxPathLossData
* Group       : Real target, Internals, EL1 common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE Rx path loss data
*****************************************************************************/
typedef struct
{
   /* LTE TX Ramp data array */
   LTE_RSSIBandGainTable *RxPathLoss[EL1_CUSTOM_MAX_RF_SUPPORT_BAND_NUM];

} El1CustomDynamicInitLteRxPathLossData;


/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteTempDac
* Group       : Real target, Internals, EL1D common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE temperature DAC data
*****************************************************************************/
typedef struct
{
   /* LTE Temperature DAC */
   LTE_TemperatureDac_T *TempDac;

} El1CustomDynamicInitLteTempDac;


/*****************************************************************************
* Typedef     : El1CustomDynamicInitLteTxPrachTmCompData
* Group       : Real target, Internals, EL1D common operation
* Type        : structure
* Description : Internal typedef used by EL1 Custom dynamic initialization data
*               LTE Tx PRACH TM comp. data
*****************************************************************************/
//// LTE didn't support PRACM TM compensation
//typedef struct
//{
//   /* LTE TX PRACH TM comp data array */
//   U_sPARACHTMCOMPDATA *TxPrachTmComp[EL1_CUSTOM_MAX_RF_SUPPORT_BAND_NUM];
//
//} El1CustomDynamicInitLteTxPrachTmCompData;


/*****************************************************************************
* Typedef     : El1CustomFunction
* Group       : Real target, Internals, EL1 common operation
* Type        : Function pointer
* Description : Internal typedef used by EL1 Custom action function prototype
*****************************************************************************/
typedef void (*El1CustomFunction)(void *usrDataPtr);

/*****************************************************************************
* Typedef     : El1CustomActionId
* Group       : Real target, Internals, EL1 common operation
* Type        : Enumeration
* Description : Internal typedef used by EL1 Custom action ID constant value
*****************************************************************************/
typedef enum
{
   EL1_CUSTOM_NULL_ACTION       = EL1_CUSTOM_NULL_ACTION_ID,
   EL1_CUSTOM_BASE_PROC_ACTION  = EL1_CUSTOM_NULL_ACTION_ID,
   EL1_CUSTOM_GPIO_DETECTION    = EL1_CUSTOM_GPIO_DETECTION_ID,
   EL1_CUSTOM_ADC_DETECTION     = EL1_CUSTOM_ADC_DETECTION_ID,
   EL1_CUSTOM_BARCODE_DETECTION = EL1_CUSTOM_BARCODE_DETECTION_ID,
   EL1_CUSTOM_MAX_PROC_ACTIONS
} El1CustomActionId;


/*****************************************************************************
* Typedef     : El1CustomDynamicInitResultRFParams
* Group       : Real target, Internals, EL1 common operation
* Type        : Enumeration
* Description : Internal typedef used by EL1 Custom Dynamic init debug
*****************************************************************************/
typedef struct
{
   /* RF Hign-band and Low-band indicator */
   LTE_Band           lteBandInd[LTE_AUGMENTED_BAND_ARRAY_NUM];

   /* BPI data allocation */
   ERF_RX_PDATABASE_T lteRxPdata[LTE_TARGET_MAX_SUPPORT_BAND_NUM];
   ERF_TX_PDATABASE_T lteTxPdata[LTE_TARGET_MAX_SUPPORT_BAND_NUM];

   /* RX, RXD LNA port / TX output path selection */
   ERF_IOBASE_T       lteIoBase[LTE_TARGET_MAX_SUPPORT_BAND_NUM];


   /* PA Drift Compensation (On/Off Switch Mask) */
   //kal_uint32 umtsPADriftCompensation;

} El1CustomDynamicInitResultRFParams;


/*****************************************************************************
* Typedef     : El1CustomDynamicInitDebug
* Group       : Real target, Internals, EL1 common operation
* Type        : Enumeration
* Description : Internal typedef used by EL1 Custom Dynamic init debug
*****************************************************************************/
typedef struct
{
   kal_uint16 combined_config_index;
   kal_uint8  first_config_index_base;
   kal_uint8  second_config_index_base;
   kal_uint8  third_config_index_base;

   kal_int32  gpio_get_pin_rpc_status;
   kal_uint32 gpio_return_pin_num[EL1_CUSTOM_GPIO_MAX_NUM_OF_DEFINED_DETECT_PIN_NAME];
   kal_uint32 gpio_pin_value[EL1_CUSTOM_GPIO_MAX_NUM_OF_DEFINED_DETECT_PIN_NAME];
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

   kal_bool   lte_rf_band_support_lid_write_status;
   kal_bool   lte_rf_bpi_rx_data_lid_write_status;
   kal_bool   lte_rf_bpi_tx_data_lid_write_status;
   kal_bool   lte_rf_io_base_lid_write_status;
   kal_bool   lte_txrampdata_lid_write_status;
   kal_bool   lte_txpaoctlvl_lid_write_status;
   kal_bool   lte_rxpathloss_lid_write_status;   
   kal_bool   lte_tempdac_lid_write_status;
   kal_bool   lte_mipienable_lid_write_status;
   //kal_bool   lte_txprachtmcomp_lid_write_status;
   kal_bool   lte_mipi_bypass_enable_lid_write_status; //MIPI BYPASS DRDI
   kal_bool   lte_mpradjtbl_lid_write_status;
   kal_bool   lte_ampradjtbl_lid_write_status;

   El1CustomDynamicInitResultRFParams custom_dynamic_init_result_params;

   kal_uint8  custom_debug_enable;
   kal_uint16 custom_total_set_nums;
} El1CustomDynamicInitDebug;


/*******************************************************************************
** DRDI for MIPI Custom Setting
*******************************************************************************/
// ENUM of MIPI enable/disable for DRDI
typedef enum
{
   LTE_DRDI_MIPI_DISABLE = 0,
   LTE_DRDI_MIPI_ENABLE  = 1
}EL1_DRDI_MIPI_SETTING_T;

// ENUM of MIPI BYPASS enable/disable for DRDI, MIPI BYPASS DRDI
typedef enum
{
   LTE_DRDI_MIPI_BYPASS_DISABLE = 0,
   LTE_DRDI_MIPI_BYPASS_ENABLE  = 1
}EL1_DRDI_MIPI_BYPASS_SETTING_T;

//Structure to save DRDI of MIPI custom setting
typedef struct
{
   EL1_DRDI_MIPI_SETTING_T           LteMipiEnable;
   LTE_MIPI_EVENT_TABLE_T          **RxEventTable;   /* LTE MIPI Rx EVENT Table                 */
   LTE_MIPI_DATA_SUBBAND_TABLE_T   **RxDataTable;    /* LTE MIPI Rx DATA Table                  */
   LTE_MIPI_EVENT_TABLE_T          **TxEventTable;   /* LTE MIPI Tx EVENT Table                 */
   LTE_MIPI_DATA_SUBBAND_TABLE_T   **TxDataTable;    /* LTE MIPI Tx DATA Table                  */
   LTE_MIPI_EVENT_TABLE_T          **TpcEventTable;  /* LTE MIPI Tpc EVENT Table                */
   LTE_MIPI_DATA_TABLE_T           **TpcDataTable;   /* LTE MIPI Tpc DATA Table                 */
   LTE_MIPI_TPC_SECTION_TABLE_T    **PaTpcSecData;   /* LTE MIPI PA Tpc Section DATA Table      */
   LTE_MIPI_IMM_DATA_TABLE_T        *InitialCW;      /* LTE MIPI Initial CW                     */
   LTE_MIPI_IMM_DATA_TABLE_T        *SleepCW;        /* LTE MIPI Sleep CW                       */
   LTE_MIPI_IMM_DATA_TABLE_T        *AsmIsolateCW;   /* LTE MIPI AsmIsolate CW                  */
   kal_uint32                       *RxEventSize;    /* LTE MIPI Rx EVENT Size Table            */
   kal_uint32                       *RxDataSize;     /* LTE MIPI Rx DATA Size Table             */
   kal_uint32                       *TxEventSize;    /* LTE MIPI Tx EVENT Size Table            */
   kal_uint32                       *TxDataSize;     /* LTE MIPI Tx DATA Size Table             */
   kal_uint32                       *TpcEventSize;   /* LTE MIPI Tpc EVENT Size Table           */
   kal_uint32                       *PaTpcSecSize;   /* LTE MIPI PA Tpc Section DATA Size Table */
} El1CustomDynamicInitLteMipiEventData;

//Structure to save DRDI of MIPI bypass setting, MIPI BYPASS DRDI
typedef struct
{
   EL1_DRDI_MIPI_BYPASS_SETTING_T    LteMipiBypassEnable;
   LTE_MIPI_EVENT_TABLE_T          **BypassTxEventTable;   /* LTE MIPI Bypass Tx EVENT Table                 */
   LTE_MIPI_DATA_SUBBAND_TABLE_T   **BypassTxDataTable;    /* LTE MIPI Bypass Tx DATA Table                  */
   LTE_MIPI_EVENT_TABLE_T          **BypassTpcEventTable;  /* LTE MIPI Bypass Tpc EVENT Table                */
   LTE_MIPI_DATA_TABLE_T           **BypassTpcDataTable;   /* LTE MIPI Bypass Tpc DATA Table                 */
   LTE_MIPI_TPC_SECTION_TABLE_T    **BypassPaTpcSecData;   /* LTE MIPI Bypass PA Tpc Section DATA Table      */
   kal_uint32                       *BypassTxEventSize;    /* LTE MIPI Bypass Tx EVENT Size Table            */
   kal_uint32                       *BypassTxDataSize;     /* LTE MIPI Bypass Tx DATA Size Table             */
   kal_uint32                       *BypassTpcEventSize;   /* LTE MIPI Bypass Tpc EVENT Size Table           */
   kal_uint32                       *BypassPaTpcSecSize;   /* LTE MIPI Bypass PA Tpc Section DATA Size Table */
} El1CustomDynamicInitLteMipiBypassEventData;

#endif 	/* _EL1_DRDI_H_ */
