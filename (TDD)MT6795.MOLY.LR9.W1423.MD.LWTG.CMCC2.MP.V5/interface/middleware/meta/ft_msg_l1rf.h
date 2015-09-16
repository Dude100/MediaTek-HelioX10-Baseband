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
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   ft_msg_l1rf.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Messages definition of L1RF category of FT Library
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *              HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *==============================================================================
 *******************************************************************************/

#ifndef __FT_MSG_L1RF_H__
#define __FT_MSG_L1RF_H__
#include "ft_msg_common.h"
#include "mph_types.h"
#include "l1tst_public.h"
#include "l1cal.h"
#include "l1_option.h"  // L! compile option header
/*******************************************************************************
*
*  Data structures used in Message Definition
*
*******************************************************************************/
typedef enum
{
     FT_RF_PWR_STATE_UNKNOWN = -1,
     FT_RF_PWR_STATE_ON,
     FT_RF_PWR_STATE_OFF,
}ft_rf_power_state_enum;


typedef enum
{
    RF_TEST_CMD_PM = 0,
    RF_TEST_CMD_AFC = 1,
    RF_TEST_CMD_NB_TX = 2,
    RF_TEST_CMD_CONTINUOUS_RX = 3,
    RF_TEST_CMD_CONTINUOUS_TX = 4,
    RF_TEST_CMD_SET_BB_TX_CFG = 5,
    RF_TEST_CMD_BAND_SEL = 6,
    RF_TEST_CMD_STOP = 7,
    RF_TEST_CMD_MULTISLOT_TX = 8,
    RF_TEST_CMD_SET_RAMPAPCLVL = 9,
    RF_TEST_CMD_SET_AFCDACVALUE = 10,
    RF_TEST_CMD_SET_BBTXCFG2 = 11,
    RF_TEST_CMD_GET_BBTXCFG2 = 12,
    RF_TEST_CMD_SET_CRYSTAL_CFG = 13,
    RF_TEST_CMD_BBTX_AUTOCAL = 14,
    RF_TEST_CMD_QUERY_MS_CAPABILITY = 15,
    RF_TEST_CMD_SET_RAMPTABLE = 16,
    RF_TEST_CMD_SET_AFC_SINWAVE_DETECTION = 17,
    RF_TEST_CMD_MULTISLOT_TX_EX = 18,
    RF_TEST_CMD_EPSK_SET_RAMPAPCLVL = 19,
    RF_TEST_CMD_GET_RFID = 20,
    RF_TEST_CMD_SET_IMMEDIATE_BSI = 21,
    RF_TEST_CMD_GET_IMMEDIATE_BSI = 22,
    RF_TEST_CMD_SET_SPECIALCOEF = 23,
    RF_TEST_CMD_CONTINUOUS_TX_EX = 24,
    RF_TEST_CMD_SET_BBTXCFG3 = 25,
    RF_TEST_CMD_GET_BBTXCFG3 = 26,
    RF_TEST_CMD_IF_TWO_APC_DC_OFFSET_SUPPORT = 27,
    RF_TEST_CMD_CONTINUOUS_TX_EX2 = 28,
    RF_TEST_CMD_QUERY_MS_CAPABILITY_EX = 29,
    RF_TEST_CMD_GET_AFCDACVALUE_AT_RTX_OFFSET_CAL = 30,
    RF_TEST_CMD_SET_BBTXCFG4 = 31,
    RF_TEST_CMD_GET_BBTXCFG4 = 32,
    RF_TEST_CMD_SET_BBTXCFG5 = 33,
    RF_TEST_CMD_GET_BBTXCFG5 = 34,
    RF_TEST_CMD_CALIBRATE_32K = 35,
    RF_TEST_CMD_QUERY_MS_CAPABILITY_EX2 = 36,
    RF_TEST_CMD_START_FDT_DL = 37,    // including AFC and RX pathloss: downlink
    RF_TEST_CMD_START_FDT_UL = 38,    // APC calibration :uplink
    RF_TEST_CMD_EPSK_SET_RAMPTABLE = 39,
    RF_TEST_CMD_GET_AFC_DAC_OFFSET = 40,
    RF_TEST_CMD_SET_AFC_DAC_OFFSET = 41,
    RF_TEST_CMD_SET_BBTXCFG6 = 42,
    RF_TEST_CMD_GET_BBTXCFG6 = 43,
    RF_TEST_CMD_GET_FDT_RESULT = 44,
    RF_TEST_CMD_START_FDT_DL_NOT_WAIT_RESULT = 45,
    RF_TEST_CMD_NSFT_CHANGE_SETTING = 46,
    RF_TEST_CMD_NSFT_START = 47,
    RF_TEST_CMD_NSFT_STOP = 48,
    RF_TEST_CMD_NSFT_CHANGE_POWER = 49,
    RF_TEST_CMD_NSFT_START_EPSK_TX = 50,
    RF_TEST_CMD_OE_PATTERN_READY = 51,
    RF_TEST_CMD_POWER_ON = 52,
    RF_TEST_CMD_POWER_OFF = 53,
    RF_TEST_CMD_QUERY_POWER_STATE_IN_FT = 54,
    RF_TEST_CMD_AFC_TYPE_QUERY_READY = 55,
    RF_TEST_CMD_SET_TX_POWER_ROLLBACK_GMSK = 56,
    RF_TEST_CMD_SET_TX_POWER_ROLLBACK_EPSK = 57,
    RF_TEST_CMD_SET_TX_POWER_ROLLBACK_TABLE_GMSK = 58,
    RF_TEST_CMD_SET_TX_POWER_ROLLBACK_TABLE_EPSK = 59,
    RF_TEST_CMD_GET_SPECIALCOEF = 60,
    RF_TEST_CMD_NSFT_CONFIG_SBER = 61,
    RF_TEST_CMD_NSFT_GET_SBER = 62,
    RF_TEST_CMD_NSFT_START_RXLEV = 63,
    RF_TEST_CMD_NSFT_GET_RXLEV = 64,
    RF_TEST_CMD_NSFT_GET_RXQUAL = 65,
    RF_TEST_CMD_IF_PM = 66,
    RF_TEST_CMD_GET_TXPC_PD_VALUE_BY_PCL_GMSK = 67,
    RF_TEST_CMD_GET_TXPC_PD_VALUE_BY_PCL_EPSK = 68,
    RF_TEST_CMD_GET_TXPC_PD_VALUE_GMSK = 69,
    RF_TEST_CMD_GET_TXPC_PD_VALUE_EPSK = 70,
    RF_TEST_CMD_GET_TXPC_SUBBAND_GMSK = 71,
    RF_TEST_CMD_GET_TXPC_SUBBAND_EPSK = 72,
    RF_TEST_CMD_GET_TXPC_TEMPERATURE = 73,
    RF_TEST_CMD_QUERY_MS_CAPABILITY_EX3 = 74,
    RF_TEST_CMD_SET_DCXO_POWER_MODE = 75,
    RF_TEST_CMD_START_FDT_DL_NOT_WAIT_RESULT_EX = 76,
    RF_TEST_CMD_GET_FDT_RESULT_EX = 77,
    RF_TEST_CMD_SET_EDGE_TX_OCT_PA_SPECIAL_COEF = 78,
    RF_TEST_CMD_TXPC_CL_RESET_PD_DATA = 79,         /**< \brief reset TX power control close loop pd value */
    RF_TEST_CMD_START_FDT_DL_BIG = 80,
    RF_TEST_CMD_START_FDT_UL_BIG = 81,
    RF_TEST_CMD_GET_FDT_RESULT_BIG = 82,
    RF_TEST_CMD_START_FDT_DL_NOT_WAIT_RESULT_BIG = 83,
    RF_TEST_CMD_START_FDT_DL_NOT_WAIT_RESULT_EX_BIG = 84,
    RF_TEST_CMD_GET_FDT_RESULT_EX_BIG = 85,
    RF_TEST_CMD_MULTISLOT_TX_WITH_AUXADC_READ = 86, /**< \brief TX RF on and read AuxADC at same time for CoTsx */
    RF_TEST_CMD_GAIN_RF_TX = 87,                    /**< \brief EDGE TX gain rf cal */
    RF_TEST_CMD_QUERY_GAIN_RF_NUM = 88,             /**< \brief Query gain rf target support number (max: 20)*/
    RF_TEST_CMD_GET_BB_POWER_LIST = 89,             /**< \brief Get BB power list from target */
    RF_TEST_CMD_CHECK_IF_FUNC_EXIST = 90,           /**< \brief Reserved for 2G command support query in target */
    RF_TEST_CMD_GET_TEMPERATURE_INFO = 91,          /**< \brief Get Temperature info (dac, temp_idx, temp) */
    RF_TEST_CMD_SET_DT_PATH_FLAG = 92,              /**< \brief Set L1 flag to use second path */
    RF_TEST_CMD_END
} RfTestCmdType;

typedef enum {
    MS_GSM = 0
    ,MS_GPRS
    ,MS_EGPRS_RX_ONLY
    ,MS_EGPRS_FULL_FUNCTION
} MS_CAPABILITY_E;

typedef struct
{
  ARFCN               arfcn;
  kal_int8            sampleNoPerFrame;
  /* Resoultion can be up to RSSI_RESOLUTION_BITS bits*/
  Gain                gain;
  kal_int16           frames;
} RfTestCmdPm;

typedef struct
{
   ARFCN              arfcn;
   kal_int16          dacValue;
   /* Resoultion can be up to RSSI_RESOLUTION_BITS bits*/
   Gain               gain;
   kal_int16          testNumber;
} RfTestCmdAfc;

typedef struct
{
   ARFCN           arfcn;
   BSIC          bsic;
   kal_int8      bitmask;
   Power           txPowerLev;
   kal_int16       frames;
   kal_int16     dacValue;
   APCTxPattern  burstTypeNB;
} RfTestCmdNbTx;

typedef struct
{
   ARFCN           arfcn;
   /* Resoultion can be up to RSSI_RESOLUTION_BITS bits*/
   Gain          gain;
   kal_bool      onOff;
} RfTestCmdContRx;

typedef struct
{
   ARFCN            arfcn;
   ContTxPattern  pattern;
   kal_bool       onOff;
} RfTestCmdContTx;

typedef struct {
   kal_int8         TxTrimI;
   kal_int8         TxTrimQ;
   kal_int8         TxOffsetI;
   kal_int8         TxOffsetQ;
} RfTestCmdSetBBTXCfg;

typedef struct {
   kal_int8         TxTrimI;
   kal_int8         TxTrimQ;
   kal_int8         TxOffsetI;
   kal_int8         TxOffsetQ;
   kal_int8         TxCalbias;
   kal_int8         TxIQSwap;
   kal_int8         TxCMV;
   kal_int8         TxGain;
   kal_int8         TxCalrcsel;
} RfTestCmdSetBBTXCfg2;

typedef struct {
    ARFCN           arfcn;
    BSIC            bsic;
    kal_int8        timeSlotmask;
    Power           powerLev[4];
    CodingScheme    cs[4];
    TimingAdvance   ta;
    kal_int32       frames;
    kal_int16       dacValue;
} RfTestCmdMultiSlotTX;

typedef struct {
    kal_int32       rf_band;
    kal_int32       power_level;
    kal_int32       apc_dac;
} RfTestCmdSetRampApcLevel;

typedef struct {
    kal_int16       dacValue;
} RfTestCmdSetAfcDacValue;

typedef struct {
    kal_int32       cap_id;
} RfTestCmdSetCrystalCfg;

typedef struct {
    kal_int32       rf_band;
} RfTestCmdSetRampTable;

typedef struct {
    kal_bool        is_sinwave;
} RfTestCmdSetAfcSinWave;

typedef struct {
    kal_uint32      bsi_data;
} RfTestCmdSetBSI;

typedef struct {
    kal_uint32      bsi_addr;
} RfTestCmdGetBSI;

typedef struct {
   kal_int8         TxTrimI;
   kal_int8         TxTrimQ;
   kal_int8         TxOffsetI;
   kal_int8         TxOffsetQ;
   kal_int8         TxCalbias;
   kal_int8         TxIQSwap;
   kal_int8         TxCMV;
   kal_int8         TxGain;
   kal_int8         TxCalrcsel;
   kal_int8         TxPhasesel;
} RfTestCmdSetBBTXCfg3;

typedef struct
{
    kal_int8    TxTrimI;
    kal_int8    TxTrimQ;
    kal_int8      TxOffsetI;
    kal_int8      TxOffsetQ;
    kal_int8      TxCalbias;
    kal_int8      TxIQSwap;
    kal_int8      TxCMV;
    kal_int8      TxGain;
    kal_int8      TxCalrcsel;
    kal_int8      TxPhasesel;
    kal_int8    TxCoarseI;
    kal_int8    TxCoarseQ;

}RfTestCmdSetBBTXCfg4;

typedef struct {
    ARFCN           arfcn;
    BSIC            bsic;
    kal_int8        timeSlotmask;
    Power           powerLev[4];
    CodingScheme    cs[4];
    TimingAdvance   ta;
    kal_int32       frames;
    kal_int16       dacValue;
    APCTxPattern    pattern;
    kal_uint16      pattern_data;
} RfTestCmdMultiSlotTXEx;

typedef struct {
    ARFCN           arfcn;
    ContTxPattern   pattern;
    kal_uint16      pattern_data;
    kal_bool        onOff;
    kal_uint16      modtype;
} RfTestCmdContTxEx;

typedef struct {
    ARFCN           arfcn;
    ContTxPattern   pattern;
    kal_uint16      pattern_data;
    kal_bool        onOff;
    kal_uint16      modtype;
    Power           powerLev;
} RfTestCmdContTxEx2;

typedef struct{
    FrequencyBand   band;
    ARFCN           BCH_ARFCN;
    ARFCN           TCH_ARFCN;
    Gain                BCH_gain;
    Gain                TCH_gain;
    TSC             tsc;
    TimeSlot            TCH_slot;
    Power           tx_power_level;
    kal_bool            is_EPSK_tx;
      CodingScheme        epsk_cs;
}RfTestCmdNSFTParam;

typedef struct{
    Power tx_power_level;
}RfTestCmdNSFTPowerChangeParam;
// ***************************************** //
// FDT Calibration
// ***************************************** //
#define FT_MAX_STEP_CNT 50
#define FT_MAX_STEP_EX_CNT 100

typedef struct
{
   FrequencyBand     band;
   ARFCN             arfcn;
   kal_int16         dac_value[33];
   Gain              gain;
   kal_int16         repeat_cnt; // repetitive test counts (frames) for each AFC DAC value
   kal_bool          capid_cal;  // capid calibration ctrl
   kal_bool          linear_cal; // 33 stages calibration ctrl
   //kal_int8        capid_min;  // min value for capid range when capid_cal is True; capid when capid_cal is False
   //kal_int8        capid_max;  // max value for capid range
   kal_int32         capid_min;  // min value for capid range when capid_cal is True; capid when capid_cal is False
   kal_int32         capid_max;  // max value for capid range
} RFTestCmdDSSAfc;

typedef struct
{
   FrequencyBand     band;
   ARFCN             arfcn;
   Gain              gain[6];    // gain for rx slot 0/1/2/3/4/5
   kal_int16         repeat_cnt; // repetitive test counts (frames) for each ARFCN value
 //kal_int16         dac_value;  // Use InitDacValue from AFC calibration when dacValue = 0 (or -1)
} RFTestCmdDSSPL;

typedef struct
{
   kal_bool          afc_cal;
   kal_bool          pl_cal;      // Control whether Path loss calibration is needed or not
   kal_int8          sync_sb_num; // the SB frame numbers needed for sync process before path loss calibration
   kal_int16         power;       // the power level expected to measure from test set
   RFTestCmdDSSAfc   AfcDSS;
   kal_int8          step_cnt;
   RFTestCmdDSSPL    PathLossDSS[FT_MAX_STEP_CNT-2];
} RFTestCmdDTS;

typedef struct
{
   kal_bool                     afc_cal;
   kal_bool                     pl_cal;
   kal_int8                     sync_sb_num;
   kal_int16                    power;
   RFTestCmdDSSAfc              AfcDSS;
   kal_int8                     step_cnt;
   RFTestCmdDSSPL               PathLossDSS[FT_MAX_STEP_EX_CNT-2];
}RFTestCmdDTSBig;

/* [LPM CAL] */
typedef struct
{
   kal_bool          afc_cal;
   kal_bool          pl_cal;      // Control whether Path loss calibration is needed or not
   kal_int8          sync_sb_num; // the SB frame numbers needed for sync process before path loss calibration
   kal_int16         power;       // the power level expected to measure from test set
   RFTestCmdDSSAfc   AfcDSS;
   kal_int8          step_cnt;
   RFTestCmdDSSPL    PathLossDSS[FT_MAX_STEP_CNT-2];
   kal_int16         lpm_sb_num;
} RFTestCmdDTS_Ex;

typedef struct
{
    kal_bool                     afc_cal;
    kal_bool                     pl_cal;
    kal_int8                     sync_sb_num;
    kal_int16                    power;
    RFTestCmdDSSAfc              AfcDSS;
    kal_int8                     step_cnt;
    RFTestCmdDSSPL               PathLossDSS[FT_MAX_STEP_EX_CNT-2];
    kal_int16                    lpm_sb_num;
}RFTestCmdDTS_Big_Ex;

typedef struct
{
   FrequencyBand     band;
   ARFCN             arfcn;
   kal_int8          timeslot_per_frame;
   kal_int8          apc_dac_pcl_sel;               // 1: apc_dac, 0: apc_pcl
   kal_int16         apc_dac_pcl_value[4];
   //kal_uint8         pa_vbias_val;
   kal_uint8                pa_vbias_val[4];
   kal_uint8                is_low_pcl[4];

   CodingScheme      cs[4];
   kal_int32         repeat_cnt;
   kal_int16         afc_dac_value;
   kal_int8          tsc;
   APCTxPattern      pattern;
   kal_uint16        pattern_data;
} RfTestCmdUSSApc;

typedef struct
{
 //kal_bool          pa_vbias_cal; // Control whether PA need to calibrate different Vbias value when APC DAC is used
   kal_int8          step_cnt;
   kal_int16         high_apc_dcoffset[FrequencyBandCount];
 //  kal_int32         lowest_power[FrequencyBandCount];
   RfTestCmdUSSApc   ApcUSS[FT_MAX_STEP_CNT];
}RfTestCmdUTS;

typedef struct
{

   kal_int8                 step_cnt;
   kal_int16                high_apc_dcoffset[FrequencyBandCount];
   RfTestCmdUSSApc          ApcUSS[FT_MAX_STEP_EX_CNT];
}RfTestCmdUTSBig;

typedef struct
{
    //kal_int32   rf_band;
    kal_int16  afc_offset[FrequencyBandCount];

}RF_SET_AFC_DAC_OFFSET_REQ_T;

typedef struct
{
    kal_int32  band;
    sTX_POWER_ROLLBACK PowerRollbackTable;
}RfTestCmdSetPowerRollbackTable;

/**
 * The RfTestCmdIrPm is used for IRR w coeffiecient calibration
 * The command is analogous to RfTestCmdPm, except the m_IfFlag
 */
typedef struct
{
    /// power scan input parameter
    RfTestCmdPm   m_Pm;
    /// if_flag for the power scan (to override the if setting in power scan, the original interface is not changed)
    kal_int8      m_IfFlag;
}RfTestCmdIrPm;

typedef struct
{
    FrequencyBand band;
    Power pcl;
}RfTestCmdTXPC;
// ***************************************** //

// R8 edge new feature
typedef struct 
{
    unsigned char                rf_band;
    unsigned short               pa_gain[16];
}RfTestCmdSetEdgeTxOctPACoef;

typedef struct 
{
    kal_uint8     rf_band;
    kal_int8      cTxAdc_State;
    kal_int8      is_EPSK;    
}RfTestCmdResetPdData;

typedef struct{
    ARFCN                arfcn;          // absolute radio frequency channel number
    BSIC                 bsic;           // training sequence
    CodingScheme         cs;             // coding scheme for each time slot, MCS1~9 is only valid for EPSK function 
    TimingAdvance        ta;             // time advance
    kal_int32            frames;         // the number of frames should transmit
    kal_int16            dacValue;       // AFC DAC value
    APCTxPattern         pattern;        // Tx pattern is only valid for EPSK function  
    kal_uint16           pattern_data;   // if NB_TX_PATTERN_WITHOUT_TSC==pattern, user can input any 16bits value as pattern.
    kal_uint16           pa_gain;        // pa gain from ini file
    kal_uint16           pa_vbias;       // pa vbias from ini file
    kal_uint8            rf_gain_index;  // gain rf index
}Rf_GainRfTx_Req;

typedef union
{
  RfTestCmdPm         pm;
  RfTestCmdAfc        afc;
  RfTestCmdNbTx       nbTx;
  RfTestCmdContRx     contRx;
  RfTestCmdContTx     contTx;
  RfTestCmdSetBBTXCfg setBBTXCfg;
  kal_bool            selectPCS1900;
  kal_int8            dummy;
  RfTestCmdMultiSlotTX  msTx;
  RfTestCmdSetRampApcLevel  setRampApcLevel;
  RfTestCmdSetAfcDacValue   setAfcDacValue;
  RfTestCmdSetBBTXCfg2      BBTxCfg2;
  RfTestCmdSetCrystalCfg    setCrystalCfg;
  RfTestCmdSetRampTable     setRampTable;
  RfTestCmdSetAfcSinWave    setAfcSinWave;
  RfTestCmdSetBSI           SetBSI;
  RfTestCmdGetBSI           GetBSI;
  RfTestCmdSetBBTXCfg3      BBTxCfg3;
  RfTestCmdMultiSlotTXEx    msTxEx;
  RfTestCmdContTxEx         contTxEx;
  RfTestCmdContTxEx2        contTxEx2;
  RfTestCmdSetBBTXCfg4   BBTxCfg4;
  RF_SET_AFC_DAC_OFFSET_REQ_T     set_afc_offset_req;
  RfTestCmdNSFTParam        NSFT_start;
  RfTestCmdNSFTPowerChangeParam  NSFT_change_power;
  RfTestCmdSetPowerRollbackTable      PowerRollbackTable;
  kal_uint32                m_u4NSFTSBERTestCount;
  /// for L1TST_ReportRXQual input
  kal_uint16                m_u2NSFTRxQualBerDecile;
  /// for SOC2 IRR W PM
  RfTestCmdIrPm             m_IrPm;
  RfTestCmdTXPC         txpc_req;
  /// for L1TST_TXPC_CL_GetSubband input
  kal_uint8                 band;
  /* [LPM CAL] */
  /// for DCXO FPM/LPM control (1 FPM, 0 LPM)
  kal_uint8                 dcxoMode;
  /// R8 edge new feature
  RfTestCmdSetEdgeTxOctPACoef setTxOctPaCoef;
  RfTestCmdResetPdData      resetTxPcPdData;
  /// gain rf tx
  Rf_GainRfTx_Req           gainRfTx;
  kal_uint8                 path_flag;
} RfTestCmdParam;




/* ---------------------------------- */
typedef struct
{
   /* Resoultion can be up to RSSI_RESOLUTION_BITS bits*/
   kal_int32            power;
   /* Resoultion can be up to RSSI_RESOLUTION_BITS*2 bits*/
   kal_int32            deviation;
   /* Resoultion can be up to RSSI_RESOLUTION_BITS bits*/
   Gain                 usedGain;
   kal_int32            ok;
   kal_int32            iOffset;
   kal_int32            qOffset;
   kal_int32            validSamples;
} RfTestResultPm;

typedef struct
{
   kal_int16              fcb_ok_number;
   kal_int32              freqOffset;
   kal_int32              deviation;
   kal_int32              ok;
} RfTestResultAfc;

typedef struct {
    kal_bool                ok;
    RfTestCmdSetBBTXCfg2    bbtx_cfg;
} RfTestResultGetBBTXCfg2;

typedef struct {
    kal_uint32      GSM400;
    kal_uint32      GSM850;
    kal_uint32      GSM900;
    kal_uint32      DCS1800;
    kal_uint32      PCS1900;
} RfTestResultBandSupport;

typedef struct {
    kal_bool                    ok;
    MS_CAPABILITY_E             capability;
    RfTestResultBandSupport     band_support;
} RfTestResultMsCapability;
/*
#define MS_CAPABILITY_GSM           0x00000001
#define MS_CAPABILITY_GPRS          0x00000002
#define MS_CAPABILITY_EDGE_RX       0x00000004
#define MS_CAPABILITY_EDGE_8PSK_TX  0x00000008
#define MS_CAPABILITY_8PM           0x00000010

#define MS_BAND_SUPPORT_GSM400      0x00000001
#define MS_BAND_SUPPORT_GSM850      0x00000002
#define MS_BAND_SUPPORT_GSM900      0x00000004
#define MS_BAND_SUPPORT_DCS1800     0x00000008
#define MS_BAND_SUPPORT_PCS1900     0x00000010
*/

typedef struct
{
    kal_uint32      capability;
    kal_uint32      band_support;
}RfResultMsCapabilityEx;

typedef struct {
    kal_bool        ok;
    kal_uint32      capability;
    kal_uint32      band_support;
} RfTestResultMsCapabilityEx;

typedef struct {
    kal_bool                ok;
    kal_uint32              id;
} RfTestResultGetRFID;

typedef struct {
    kal_bool        ok;
    kal_uint32      bsi_data;
} RfTestResultGetBSI;

typedef struct {
    kal_bool                ok;
    RfTestCmdSetBBTXCfg3    bbtx_cfg;
} RfTestResultGetBBTXCfg3;

typedef struct
{
    kal_bool              ok;
    RfTestCmdSetBBTXCfg4    bbtx_cfg;
}RfTestResultGetBBTXCfg4;

typedef struct {
    kal_bool        ok;
    kal_int16       dacValue;
} RfGetAfcDacValueAtRTXOffsetCal;

typedef struct
{
    kal_bool        ok;
    kal_int32      calibra_result_32k;
}RfTestResult32kCalibration;

// ****************************** //
// FDT Calibration
// ****************************** //
typedef struct
{
   kal_int32         power[FT_MAX_STEP_CNT-2];
   kal_int16         valid_sample[FT_MAX_STEP_CNT-2];
   kal_bool          ok;
} RfTestResultDSSPL;

typedef struct
{
   kal_int32         power[FT_MAX_STEP_EX_CNT-2];
   kal_int16         valid_sample[FT_MAX_STEP_EX_CNT-2];
   kal_bool          ok;
} RfTestResultDSSPLBig;

typedef struct
{
   kal_int32         freq_offset[33];   // only valid when 33 stage calibration is ON
   kal_int32         deviation[33];     // only valid when 33 stage calibration is ON
   kal_int16         fcb_ok_number[33];
   //kal_int8        capid;             // only valid when capid calibration is ON
   kal_int32         capid;             // only valid when capid calibration is ON
   kal_int16         init_dac_value;    // only valid when 33 stage calibration is OFF
   kal_int32         slope;             // only valid when 33 stage calibration is OFF
   kal_bool          ok;
} RfTestResultDSSAfc;
/* [LPM CAL] */
typedef struct
{
    kal_int32 cload_freq_offset;
    kal_bool  ok;
    kal_bool  is_perform_cal;
} RfTestResultDSSLpm;
#if  IS_FHC_SUPPORT == 1
typedef struct
{
     kal_int32              path_loss_cnt;
   kal_int32              freq_offset;
   kal_int32              capid_freq_offset_min;
   kal_int32              capid_freq_offset[FHC_MAX_CAPID_SEARCH_NUM];      // 16
   kal_int32              capid_search_order[FHC_MAX_CAPID_SEARCH_NUM];     // 16
   kal_int32              capid;
   kal_int32              capid_high;
   kal_int32              capid_low;
   kal_int32              capid_best;
   kal_int16              afc_dac;
   kal_int16              arfcn;
   kal_int16              capid_cnt;
   kal_int16              repeat_index;
   kal_int8               state;
   kal_int8               capid_index;
   kal_int8               capid_okay_cnt;
   kal_int8               afc_dac_index;
   kal_int8               sb_okay_cnt;
   kal_uint8              sb_fail_cnt;
   kal_uint8              fb_fail_cnt;
   kal_bool               pl_started;
   kal_bool               pre_capid_cal_ok[FHC_PRE_CAPID_SEARCH_NUM];   // FHC_PRE_CAPID_SEARCH_NUM
}RfTestResultDtsmInfo;
#else
typedef struct
{
     kal_int32              path_loss_cnt;
       kal_int32              freq_offset;
       kal_int32              capid_freq_offset_min;
       kal_int32              capid_freq_offset[16];        //FHC_MAX_CAPID_SEARCH_NUM
       kal_int32              capid_search_order[16];       //FHC_MAX_CAPID_SEARCH_NUM
       kal_int32              capid;
       kal_int32              capid_high;
       kal_int32              capid_low;
       kal_int32              capid_best;
       kal_int16              afc_dac;
       kal_int16              arfcn;
       kal_int16              capid_cnt;
       kal_int16              repeat_index;
       kal_int8               state;
       kal_int8               capid_index;
       kal_int8               capid_okay_cnt;
       kal_int8               afc_dac_index;
       kal_int8               sb_okay_cnt;
       kal_uint8              sb_fail_cnt;
       kal_uint8              fb_fail_cnt;
       kal_bool               pl_started;
       kal_bool               pre_capid_cal_ok[9];  // FHC_PRE_CAPID_SEARCH_NUM
}RfTestResultDtsmInfo;
#endif

typedef enum  {
    DTS_RESULT_READY = 0,       // DTS results is ready to get back
    DTS_RESULT_NOT_READY,       // DTS result is still in progress and not ready to get back
    DTS_RESULT_NOT_REQUESTED,   // Haven't called the META_Rf_StartFdtDL() in advance.
    DTS_FATAL_ERROR
}RF_DTS_GET_RESULT_STATUS;
typedef struct
{
   RfTestResultDSSPL              PLResult;
   RfTestResultDSSAfc             AfcResult;
   RfTestResultDtsmInfo           m_rDtsmInfo;  // for L1 debug use, will print in META Tool's test report.
} RfTestResultDTS;

typedef struct
{
   RfTestResultDSSPLBig           PLResult;
   RfTestResultDSSAfc             AfcResult;
   RfTestResultDtsmInfo           m_rDtsmInfo;  // for L1 debug use, will print in META Tool's test report.
} RfTestResultDTSBig;


/* [LPM CAL] */
typedef struct
{
   RfTestResultDSSPL              PLResult;
   RfTestResultDSSAfc             AfcResult;
   RfTestResultDtsmInfo           m_rDtsmInfo;
   /* crystal low power mode calibration result (for 32k removal) */
   RfTestResultDSSLpm             LpmResult;
} RfTestResultDTS_Ex;

typedef struct
{
   RfTestResultDSSPLBig           PLResult;
   RfTestResultDSSAfc             AfcResult;
   RfTestResultDtsmInfo           m_rDtsmInfo;
   /* crystal low power mode calibration result (for 32k removal) */
   RfTestResultDSSLpm             LpmResult;
} RfTestResultDTS_Big_Ex;

typedef struct
{
     kal_int16        afc_offset[FrequencyBandCount];
     kal_bool                  ok;
}RfGetAfcOffsetResult;

typedef struct
{
    kal_uint32        m_u4NSFTSBER;
    kal_uint32        m_u4NSFTSBERCurrentCount;
}RfNSFTSBERResult;
// local
typedef struct
{
    kal_bool         ok;
    kal_uint16       m_u2PDValue;
}RfTestResultPDValue;

// peer
typedef struct
{
    kal_uint16       data[16];
} RfTestResultTXPCPD;

typedef struct
{
    kal_uint16       data[8];
} RfTestResultTXPCPDTemp;

typedef struct
{
    /// calibrated flag
    kal_int8               is_calibrated;
    /// closed-loop target value by PCL
    RfTestResultTXPCPD     adc[FrequencyBandCount];
    /// temperature compensation interval
    kal_int16              temperature;
    /// closed-loop target value by temperature compensation
    RfTestResultTXPCPDTemp temp[FrequencyBandCount];
}RfTestResultTXPCAllPD;

typedef struct{
    kal_int16 status;
    kal_int16 tadc_dac;
    kal_int16 temperature;
    kal_int16 temp_idx;
} RfTestResultRfTemperatureInfo;

// ****************************** //

typedef union
{
    kal_bool                       ok;
    kal_int8                       m_i1RfPwrState_FT;
    kal_int16                      m_sBBPowerArrary[20];   /// META_Rf_QueryBBPowerList_r output
    kal_uint8                      m_u1NSFTRxQual;         /// L1TST_ReportRXQual output
    kal_uint8                      m_ucNumOfGainRf;        /// META_Rf_QueryNumOfGainRf_r output
    kal_uint16                     m_u2NSFTRxLevel;        /// L1TST_ReportRXLEV output
    kal_uint16                     temperature;            /// L1TST_TXPC_GetTemperature output: RF_TEST_CMD_GET_TXPC_TEMPERATURE
    kal_uint16                     m_txpc_subband_compensation[11];   /// L1TST_TXPC_CL_GetSubband output   
    RF_DTS_GET_RESULT_STATUS       dts_get_result_status;
    RfGetAfcOffsetResult           afc_result;
    RfGetAfcDacValueAtRTXOffsetCal GetAfcDacValueAtRTXOffsetCal;
    RfNSFTSBERResult               m_rNSFTSBER;   
    RfTestResultPm                 pm;
    RfTestResultAfc                afc;
    RfTestResultGetBSI             GetBSI;
    RfTestResultGetRFID            rfid;
    RfTestResultPDValue            txpc_cnf;
    RfTestResultGetBBTXCfg2        BBTxCfg2;
    RfTestResultGetBBTXCfg3        BBTxCfg3;
    RfTestResultGetBBTXCfg4        BBTxCfg4;    
    RfTestResultMsCapability       ms_capability;    
    RfTestResultMsCapabilityEx     ms_capability_ex;
    RfTestResult32kCalibration     calibration_32k;
    RfTestResultRfTemperatureInfo  rfTemperatureInfo;  
} RfTestResultParam;

/*******************************************************************************
*
*  Message structures defined for L1TST Interface
*
*******************************************************************************/
typedef struct
{
  FT_H              header;
  RfTestCmdType     type;
  RfTestCmdParam    param;
} ft_rf_test_req_T;

typedef struct
{
  FT_H               header;
  RfTestCmdType      type;
  RfTestResultParam  param;
} ft_rf_test_cnf_T;


#endif // #ifndef __FT_MSG_L1RF_H__
