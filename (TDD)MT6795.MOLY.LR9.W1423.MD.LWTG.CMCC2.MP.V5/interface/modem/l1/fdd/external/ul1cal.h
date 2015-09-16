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
 *   ul1cal.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   The structure definition of UL1 calibration data
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
#ifndef UL1CAL_H
#define UL1CAL_H

/*===============================================================================*/

#include "kal_general_types.h"
#include "ul1d_rf_public.h"
#include "dcl.h"        //SmartPhone Project's CommonModemImage need this
#include "ul1d_rf_cid.h"

/*===============================================================================*/

/* ------------------------------------------------------------------------- */
typedef struct
{
   kal_uint16 tempdacData[8];
}ul1cal_tempdacData_T; 

typedef struct
{
   U_sTEMPAGCOFFSET  pathlossData[CAL_TEMP_SECTION]; 
}ul1cal_pathlossData_T;

typedef struct
{
   U_sRAMPDATA txdacData; 
}ul1cal_txdacData_T;

/* PA 8-level control (MT6276, MT6573) */
typedef struct
{
   U_sPAOCTLVLSETTING txPaOctLevData; 
}ul1cal_txPaOctLevData_T;

typedef struct
{
   U_sPARACHTMCOMPDATA txPrachTmCompData;
}ul1cal_txPrachTmCompData_T;

#if defined (__TX_POWER_OFFSET_SUPPORT__)
typedef struct
{
   U_sTXPOWEROFFSETDATA txPowerOffsetData;
}ul1cal_txPowerOffsetData_T;
#endif /* IS_3G_TX_POWER_OFFSET_SUPPORT */

typedef struct
{
   U_sAFCDACDATA afcDacData;
}ul1cal_afcDacData_T;

typedef struct
{
   U_sAFCCAPDATA afcCapData;
}ul1cal_afcCapData_T;

#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__) 

typedef struct
{
   U_sUl1dRfCustomInputData umtsRfCustomInput;
}ul1cal_umtsRfCustomInput_T;

#endif

#if defined (__UMTS_R8__)
typedef struct
{
   U_sAGCOFFSETRXD  pathlossData; 
}ul1cal_pathlossRxdData_T;

typedef struct
{
   U_sPADRIFTSETTING txPaDriftCompData; 
}ul1cal_txPaDriftCompData_T;

#endif

#if (IS_3G_MIPI_SUPPORT)
typedef UL1_UMTS_MIPI_TPC_T ul1mipi_tpcData_T;
#endif


#if (IS_3G_ET_NVRAM_SUPPORT)
typedef UL1_UMTS_MIPI_ET_T ul1mipi_etData_T;
#endif

#if (IS_3G_MIPI_NVRAM_FULL_SUPPORT)
typedef struct
{
   UL1_MIPI_DATA_SUBBAND_TABLE_T mipiTxData[UL1_MIPI_TX_DATA_NUM]; 
}ul1mipi_txData_T;

typedef struct
{
   UL1_MIPI_DATA_TABLE_T mipiAsmIsoData[MIPI_MAX_ASM_ISOLATION_IMM_BSI_CW_NUM]; 
}ul1mipi_asmIsoData_T;

typedef struct
{
   UL1_MIPI_EVENT_TABLE_T mipiTxEvent[UL1_MIPI_TX_EVENT_NUM]; 
}ul1mipi_txEvent_T;

typedef struct
{
   UL1_MIPI_DATA_SUBBAND_TABLE_T mipiRxData[UL1_MIPI_RX_DATA_NUM]; 
}ul1mipi_rxData_T;

typedef struct
{
   UL1_MIPI_EVENT_TABLE_T mipiRxEvent[UL1_MIPI_RX_EVENT_NUM]; 
}ul1mipi_rxEvent_T;

typedef struct
{
   UL1_MIPI_DATA_TABLE_T mipiInitData[MIPI_MAX_INITIAL_IMM_BSI_CW_NUM]; 
}ul1mipi_initCwData_T;

typedef struct
{
   UL1_MIPI_DATA_TABLE_T mipiSleepData[MIPI_MAX_SLEEP_IMM_BSI_CW_NUM]; 
}ul1mipi_sleepCwData_T;

#if (IS_3G_ET_NVRAM_SUPPORT)
typedef struct
{
   UL1_MIPI_DATA_TABLE_T mipiEtOnData[ET_MAX_ON_IMM_BSI_CW_NUM]; 
}ul1mipi_etOnCwData_T;

typedef struct
{
   UL1_MIPI_DATA_TABLE_T mipiEtOffData[ET_MAX_OFF_IMM_BSI_CW_NUM]; 
}ul1mipi_etOffCwData_T;

#endif/*IS_3G_ET_NVRAM_SUPPORT*/

#if (IS_3G_VPA_SEL_BY_BAND_SUPPORT)

typedef struct
{
   UMTS_VPA_SOURCE_TYPE vpaSel;
}
ul1vpa_sel_T;

#endif/*IS_3G_VPA_SEL_BY_BAND_SUPPORT*/

#endif/*IS_3G_MIPI_NVRAM_FULL_SUPPORT*/

/*------------- Single Software Load for Multiple Components Compatible -------------*/
/*****************************************************************************
* Constant    : UL1CUSTOM_MAX_RF_BPI_EVENT_NUM
* Group       : Real target, Internal, UL1D common operation
* Description : Constant to be used for record the maximum 3G BPI event
*               support numbers currently in use
*****************************************************************************/
#define UL1CUSTOM_MAX_RF_BPI_EVENT_NUM  (15)          //MT6280 Changes to 15

/*****************************************************************************
* Constant    : UL1CUSTOM_MAX_RF_SUPPORT_BAND_NUM
* Group       : Real target, Internal, UL1D common operation
* Description : Constant to be used for record the maximum 3G RF band
*               support numbers currently in use
*****************************************************************************/
#define UL1CUSTOM_MAX_RF_SUPPORT_BAND_NUM  (5)          //MT6280 Changes to 5

/*****************************************************************************
* Constant    : UL1CUSTOM_GPIO_MAX_NUM_OF_DEFINED_DETECT_PIN_NAME
* Group       : Real target, Internal, UL1D common operation
* Description : Constant to be used determine the max number of GPIO
*               detection pin names defined so far at AP side GPIO driver
*****************************************************************************/
#define UL1CUSTOM_GPIO_MAX_NUM_OF_DEFINED_DETECT_PIN_NAME (3)

/*****************************************************************************
* Constant    : UL1CUSTOM_NULL_ACTION
*               UL1CUSTOM_GPIO_DETECTION_ID
*               UL1CUSTOM_ADC_DETECTION_ID
*               UL1CUSTOM_NVRAM_BARCODE_DETECTION_ID
* Group       : Real target, Internals, UL1D common operation
* Description : Constant to be used to define the value to be used in
*               enumeration Ul1CustomActionId
*****************************************************************************/
#define UL1CUSTOM_NULL_ACTION                (0)
#define UL1CUSTOM_GPIO_DETECTION_ID          (1)
#define UL1CUSTOM_ADC_DETECTION_ID           (2)
#define UL1CUSTOM_NVRAM_BARCODE_DETECTION_ID (3)

/*****************************************************************************
* Typedef     : Ul1CustomFunction
* Group       : Real target, Internals, UL1D common operation
* Type        : Function pointer
* Description : Internal typedef used by UL1 Custom action function prototype
*****************************************************************************/
typedef void (*Ul1CustomFunction)(void *usrDataPtr);

/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitLnaPortTxPath
* Group       : Real target, Internals, UL1D common operation
* Type        : structure
* Description : Internal typedef used by UL1 Custom dynamic initialization data
*               for LNA port and Tx path setting
*****************************************************************************/
typedef struct
{
   /* User input to notify the band of the data to be modified */
   kal_uint32 bandToModify;

   /* LNA port selection */
   kal_uint8  lnaPortNum;

   /* TX output path selection */
   kal_uint8  txOutputSel; 

   /* RXD LNA port selection */
#if IS_URF_ORION_HPLUS || IS_URF_MT6167 || IS_URF_MT6166 || IS_URF_MT6169
   kal_uint8  lnaPortNum2;
#endif

} Ul1CustomDynamicInitLnaPortTxPath;

/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitUmtsBpiData
* Group       : Real target, Internals, UL1D common operation
* Type        : structure
* Description : Internal typedef used by UL1 Custom dynamic initialization data
*               3G BPI data
*****************************************************************************/
typedef struct
{
   /* User input to notify the band of the data to be modified */
   kal_uint32 bandToModify;

   /* ASM logics */
#if IS_URF_MT6167 || IS_URF_MT6166 || IS_URF_MT6169
   /* In MT6290 serious, the ASM logic had extend to Int32*/
   kal_uint32 asmLogics[UL1CUSTOM_MAX_RF_BPI_EVENT_NUM];
#else
   kal_uint16 asmLogics[UL1CUSTOM_MAX_RF_BPI_EVENT_NUM];
#endif

   /* PA enable control bits */
//   kal_uint8 paEnables[UL1CUSTOM_MAX_RF_BPI_EVENT_NUM];

} Ul1CustomDynamicInitUmtsBpiData;

/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitUmtsTxRampData
* Group       : Real target, Internals, UL1D common operation
* Type        : structure
* Description : Internal typedef used by UL1 Custom dynamic initialization data
*               3G Tx Ramp data
*****************************************************************************/
typedef struct
{
   /* 3G TX Ramp data array */
   U_sRAMPDATA *TxRampData[UL1CUSTOM_MAX_RF_SUPPORT_BAND_NUM];

} Ul1CustomDynamicInitUmtsTxRampData;

/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitUmtsTxPaOctLvlData
* Group       : Real target, Internals, UL1D common operation
* Type        : structure
* Description : Internal typedef used by UL1 Custom dynamic initialization data
*               3G Tx PA oct-level data
*****************************************************************************/
typedef struct
{
   /* 3G TX Ramp data array */
   U_sPAOCTLVLSETTING *TxPaOctLvl[UL1CUSTOM_MAX_RF_SUPPORT_BAND_NUM];

} Ul1CustomDynamicInitUmtsTxPaOctLvlData;

/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitUmtsRxPathLossData
* Group       : Real target, Internals, UL1D common operation
* Type        : structure
* Description : Internal typedef used by UL1 Custom dynamic initialization data
*               3G Rx path loss data
*****************************************************************************/
typedef struct
{
   /* 3G TX Ramp data array */
   U_sTEMPAGCOFFSET *RxPathLoss[UL1CUSTOM_MAX_RF_SUPPORT_BAND_NUM];

} Ul1CustomDynamicInitUmtsRxPathLossData;

/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitUmtsTxPrachTmCompData
* Group       : Real target, Internals, UL1D common operation
* Type        : structure
* Description : Internal typedef used by UL1 Custom dynamic initialization data
*               3G Tx PRACH TM comp. data
*****************************************************************************/
typedef struct
{
   /* 3G TX PRACH TM comp data array */
   U_sPARACHTMCOMPDATA *TxPrachTmComp[UL1CUSTOM_MAX_RF_SUPPORT_BAND_NUM];

} Ul1CustomDynamicInitUmtsTxPrachTmCompData;

/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitUmtsTempDac
* Group       : Real target, Internals, UL1D common operation
* Type        : structure
* Description : Internal typedef used by UL1 Custom dynamic initialization data
*               3G temperature DAC data
*****************************************************************************/
typedef struct
{
   /* 3G Temperature DAC */
   kal_uint16 *UTempDac;

} Ul1CustomDynamicInitUmtsTempDac;

/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitUmtsAfcDac
* Group       : Real target, Internals, UL1D common operation
* Type        : structure
* Description : Internal typedef used by UL1 Custom dynamic initialization data
*               3G temperature DAC data
*****************************************************************************/
typedef struct
{
   /* 3G AFC DAC */
   U_sAFCDACDATA *UAfcDac;

} Ul1CustomDynamicInitUmtsAfcDac;

/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitUmtsAfcCap
* Group       : Real target, Internals, UL1D common operation
* Type        : structure
* Description : Internal typedef used by UL1 Custom dynamic initialization data
*               3G temperature DAC data
*****************************************************************************/
typedef struct
{
   /* 3G AFC CAP */
   U_sAFCCAPDATA *UAfcCap;

} Ul1CustomDynamicInitUmtsAfcCap;

#if IS_3G_TX_POWER_OFFSET_SUPPORT
/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitUmtsTxPowerOffsetData
* Group       : Real target, Internals, UL1D common operation
* Type        : structure
* Description : Internal typedef used by UL1 Custom dynamic initialization data
*               3G Tx Power Offset data
*****************************************************************************/
typedef struct
{
   /* 3G TX Power Offset comp data array */
   U_sTXPOWEROFFSETDATA *TxPowerOffset[UL1CUSTOM_MAX_RF_SUPPORT_BAND_NUM];

} Ul1CustomDynamicInitUmtsTxPowerOffsetData;
#endif // IS_3G_TX_POWER_OFFSET_SUPPORT

#if (IS_3G_MIPI_SUPPORT)
typedef struct
{
   MIPI_Setting                   mipiSetting;
   UL1_MIPI_DATA_TABLE_T          *initTable_p;
   UL1_MIPI_DATA_TABLE_T          *sleepTable_p;
   UL1_MIPI_EVENT_TABLE_T         **rxEventTable_p;
   UL1_MIPI_DATA_SUBBAND_TABLE_T  **rxDataTable_p;
   UL1_MIPI_EVENT_TABLE_T         **txEventTable_p;
   UL1_MIPI_DATA_SUBBAND_TABLE_T  **txDataTable_p;
   UL1_UMTS_MIPI_TPC_T            **tpcTable_p;
   UL1_MIPI_DATA_TABLE_T          **asmIsoTable_p;
#if (IS_3G_ET_SUPPORT)
   UL1_UMTS_MIPI_ET_T             **etTable_p;
   UL1_MIPI_DATA_TABLE_T          *etOnStaticCwTable_p;
   UL1_MIPI_DATA_TABLE_T          *etOffStaticCwTable_p;
   funcptr                        fVpa2EtCw_p;
#endif/*IS_3G_ET_SUPPORT*/
}Ul1CustomDynamicInitMipiData;
#endif
/*****************************************************************************
* Typedef     : Ul1CustomActionId
* Group       : Real target, Internals, UL1D common operation
* Type        : Enumeration
* Description : Internal typedef used by UL1 Custom action ID constant value
*****************************************************************************/
typedef enum
{
   UL1CUSTOM_NULL_ACTION_ID = UL1CUSTOM_NULL_ACTION,
   UL1CUSTOM_BASE_PROC_ACTION_ID = UL1CUSTOM_NULL_ACTION_ID,
   UL1CUSTOM_GPIO_DETECTION = UL1CUSTOM_GPIO_DETECTION_ID,
   UL1CUSTOM_ADC_DETECTION = UL1CUSTOM_ADC_DETECTION_ID,
   UL1CUSTOM_NVRAM_BARCODE_DETECTION = UL1CUSTOM_NVRAM_BARCODE_DETECTION_ID,
   UL1CUSTOM_MAX_PROC_ACTIONS

} Ul1CustomActionId;

/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitResultRFParams
* Group       : Real target, Internals, UL1D common operation
* Type        : Enumeration
* Description : Internal typedef used by UL1 Custom Dynamic init debug
*****************************************************************************/
typedef struct
{
   /* BPI data allocation */
   U_sUl1dRfBpiData umtsPdata;

   /* RF Hign-band and Low-band indicator */
   U_sUl1dRfBandIndicator umtsBandIndicator;

   /* RX LNA port selection */
   U_sUl1dRfRxLnaPortSel umtsRxLnaPortSel;

   /* TX output path selection */
   U_sUl1dRfTxPathSel umtsTxPathSel;

#if IS_URF_ORION_HPLUS || IS_URF_MT6167 || IS_URF_MT6166 || IS_URF_MT6169
   /* RXd Path Setting (Main/Diversity on off Switch) */
   U_sUl1dRxdPathSetting   umtsRxdPathSetting;

   /* PA Drift Compensation (On/Off Switch Mask) */
   kal_uint32 umtsPADriftCompensation;
#endif   
   

} Ul1CustomDynamicInitResultRFParams;

/*****************************************************************************
* Typedef     : Ul1CustomDynamicInitDebug
* Group       : Real target, Internals, UL1D common operation
* Type        : Enumeration
* Description : Internal typedef used by UL1 Custom Dynamic init debug
*****************************************************************************/
typedef struct
{
   kal_uint16 combined_config_index;
   kal_uint8  first_config_index_base;
   kal_uint8  second_config_index_base;
   kal_uint8  third_config_index_base;
   kal_int32  gpio_get_pin_rpc_status;
   kal_uint32  gpio_return_pin_num[UL1CUSTOM_GPIO_MAX_NUM_OF_DEFINED_DETECT_PIN_NAME];
   kal_uint32 gpio_pin_value[UL1CUSTOM_GPIO_MAX_NUM_OF_DEFINED_DETECT_PIN_NAME];
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
   kal_bool   umts_tempdac_lid_write_status;
   kal_bool   umts_txrampdata_lid_write_status;
   kal_bool   umts_txpaoctlvl_lid_write_status;
   kal_bool   umts_rxpathloss_lid_write_status;   
   kal_bool   umts_txprachtmcomp_lid_write_status;
   kal_bool   umts_rf_params_lid_write_status;
   Ul1CustomDynamicInitResultRFParams custom_dynamic_init_result_params;   
#if IS_3G_TX_POWER_OFFSET_SUPPORT
   kal_bool   umts_txpoweroffset_lid_write_status;
#endif // IS_3G_TX_POWER_OFFSET_SUPPORT

} Ul1CustomDynamicInitDebug;
/*------------- Single Software Load for Multiple Components Compatible -------------*/


#endif 	
