/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 * Filename:
 * ---------
 *   lte_meta_tool.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *	 LTE test mode specific definitions for synchronizing with HOST tool
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * Perform carrier search and MIB receiving in META TX PUSCH mode.
 *
 * removed!
 * removed!
 * add bypass/filter mode switch command.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * [MT6290]MIPI PA control interface by meta.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * force pa mode in tx calibration
 *
 * 11 04 2013 ms.lin
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * .
 *
 * 10 03 2013 ms.lin
 * removed!
 * 	.
 *
 * removed!
 * Add LTE META capability API.
 *
 * 08 27 2013 ms.lin
 * removed!
 * 	Support RF capability query
 *
 * removed!
 * removed!
 * .
 *
 * 06 05 2013 ms.lin
 * removed!
 * .
 *
 * 05 15 2013 ms.lin
 * removed!
 * .
 *
 ****************************************************************************/

#ifndef LTE_META_TOOL_H
#define LTE_META_TOOL_H

#include "kal_general_types.h"
#include "ft_msg_common.h"

/*******************define******************/
#define TOOL_NOT_SUPPORT 2
#define TOOL_CNF_OK   1
#define TOOL_CNF_FAIL 0

#define ERF_BAND_MAP_SIZE 2 //support 2*32 bands at maximum, need to align LTE_BIT_MASK_BUFFER_SIZE

#define MAX_FHC_BAND_NUM 10
#define MAX_FHC_RX_FREQ_NUM 22
#define MAX_FHC_TX_FREQ_NUM 22
#define MAX_PWR_STEP_NUM 27
#define MAX_NSFT_LIST_TX_BAND_NUM 10
#define MAX_NSFT_LIST_TX_FREQ_NUM 13

/*********************RF calibration structure*********************/

typedef enum
{
	ERF_TEST_CMD_START_PUSCH_TX = 0, 
	ERF_TEST_CMD_START_PUCCH_TX = 1,
	ERF_TEST_CMD_START_PRACH_TX = 2,
	ERF_TEST_CMD_START_SRS_TX = 3,
	ERF_TEST_CMD_START_MIX_RX = 4,
	ERF_TEST_CMD_GET_MIX_RX_RPT = 5,
	ERF_TEST_CMD_RESET_COUNTER = 6,
	ERF_TEST_CMD_STOP_TEST_MODE = 7,
	ERF_TEST_CMD_SET_TX_TPC_SETTING = 8,
	ERF_TEST_CMD_GET_TX_TPC_SETTING = 9,
	ERF_TEST_CMD_GET_RF_CAPABILITY = 10,
	ERF_TEST_CMD_START_AFC_SINGLE_TONE_TX = 11,
	ERF_TEST_CMD_SET_AFC_SETTING = 12,
	ERF_TEST_CMD_GET_AFC_SETTING = 13,
	ERF_TEST_CMD_START_TPC_SINGLE_TONE_TX = 14,
	ERF_TEST_CMD_SET_TPC_PA_GAIN = 15,
	ERF_TEST_CMD_GET_POWER_DETECTOR_VALUE = 16,
	ERF_TEST_CMD_START_RSSI = 17,
	ERF_TEST_CMD_GET_RSSI_SETTING = 18,
	ERF_TEST_CMD_SET_RSSI_SETTING = 19,
	ERF_TEST_CMD_START_FHC = 20,
	ERF_TEST_CMD_CHECK_IF_FUNC_EXIST = 21,
	ERF_TEST_CMD_GET_RF_TEMP = 22,
	ERF_TEST_CMD_GET_TADC_SETTING = 23,
	ERF_TEST_CMD_SET_TADC_SETTING = 24,
	ERF_TEST_CMD_START_NSFT_LIST = 25, 
	ERF_TEST_CMD_START_CONT_RX = 26,
	ERF_TEST_CMD_SET_RF_MIPI_CODEWORD = 27,
	ERF_TEST_CMD_GET_RF_MIPI_CODEWORD = 28, 
	ERF_TEST_CMD_GET_TEMPERATURE_INFO = 29,
	ERF_TEST_CMD_SET_PATH_FLAG = 31,//30 is used
	ERF_TEST_CMD_END
}ERfTestCmdType;

typedef enum
{
	ERF_TEST_RFID_NULL   = 0,
	ERF_TEST_RFID_MT6169 = 1,
	ERF_TEST_RFID_END    = 0xFFFF

}ERfTestRfId;

typedef enum
{
	ERF_TEST_PARAMS_TEMP_DAC_SRC_NULL   = 0,
	ERF_TEST_PARAMS_TEMP_DAC_SRC_AUXADC = 1,
	ERF_TEST_PARAMS_TEMP_DAC_SRC_BSI    = 2,
	ERF_TEST_PARAMS_TEMP_DAC_SRC_END    = 0xFFFF

}ERfTestParamsTempDacSrc;

typedef struct
{
	kal_uint8 band;
	kal_uint8 duplexMode;/* 0:tdd, 1:fdd */
	kal_uint8 tddConfig; 
	kal_uint8 tddSfConfig;
	kal_uint16 ulFrequency; /* range: 7280~26900 (100KHz unit) */
	kal_uint16 cellId;
	kal_int16 afcdac;
	kal_uint8 ulBandwidth; /* 0:6, 1:15, 2:25, 3:50, 4:75, 5:100RB */
	kal_uint8 vrbStart;
	kal_uint8 vrbLength;
	kal_uint8 mcsMode;
	kal_uint8 txPwrMode;//0:use txPowerValue, 1: use HW register
	kal_int16 txPowerValue;/*S(8,8)*/
	kal_uint8 networkSelection; /* 0~31 */
	kal_uint8 txCloseLoopDisbl;
	kal_uint8 amprEnbl;
	kal_int16 bbBackoff;/*S(8,8)*/
	kal_uint8 rfGain;
	kal_uint8 paMode; /* 0:high, 1:middle, 2:low */
	kal_uint8 paVcc;
	kal_uint8 vm0;
	kal_uint8 vm1;
	kal_uint8 enableCsr;
	kal_uint16 dlFrequency;
}ERfTestCmdPuschTx;

typedef struct
{
	kal_uint8 band;																																		
	kal_uint8 duplexMode;/*0:tdd, 1:fdd */																																		
	kal_uint8 tddConfig; 																																		
	kal_uint8 tddSfConfig;																																		
	kal_uint16 ulFrequency;/* range: 7280~26900 (100KHz unit) */																																		
	kal_uint16 cellId;																																		
	kal_int16 afcdac;																																		
	kal_uint8 ulBandwidth; /*0:6, 1:15, 2:25, 3:50, 4:75, 5:100RB */																																		
	kal_uint8 format; /*0:1, 1:1a, 2:1b, 3:2, 4:2_cpack, 5:2a, 6:2b */																																		
	kal_int16 txPowerValue;/*S(8,8)*/
	kal_uint8 networkSelection; /* 0~31 */
	kal_uint8 txCloseLoopDisbl;
	kal_uint8 amprEnbl;
}ERfTestCmdPucchTx;

typedef struct
{
	kal_uint8 band;
	kal_uint16 ulFrequency;/* range: 7280~26900 (100KHz unit) */
	kal_uint16 cellId;
	kal_int16 afcdac;
	kal_uint8 configIndex; /* 0:fdd time mask, 1:tdd time mask, 2:fdd evm, 3:tdd evm*/
	kal_int16 txPowerValue;/*S(8,8)*/
	kal_uint8 networkSelection; /* 0~31 */
	kal_uint8 txCloseLoopDisbl;
	kal_uint8 amprEnbl;
}ERfTestCmdPrachTx;

typedef struct
{
	kal_uint8 band;
	kal_uint8 duplexMode; /*0:tdd, 1:fdd */
	kal_uint16 ulFrequency;/* range: 7280~26900 (100KHz unit) */
	kal_uint16 cellId;
	kal_int16 afcdac;
	kal_uint8 tddCsSrsBwCfg; /*range: 0, 2, 5, 7*/
	kal_int16 txPowerValue;/*S(8,8)*/
	kal_uint8 networkSelection; /* 0~31 */
	kal_uint8 txCloseLoopDisbl;
	kal_uint8 amprEnbl;
}ERfTestCmdSrsTx;

typedef struct
{
	kal_uint8 mode;//0: DL Rx, 1: Tx-Rx, 2: Pseudo Tx-Rx

	/*Common parameters*/
	kal_uint8 measCnt;//range 0~10
	kal_uint8 measBandwidth;//0: 6 RB, 1: 15 RB, 2: 25 RB, 3: 50 RB, 4: 75 RB, 5: 100 RB
	kal_int16 afcdac;
	kal_uint16 dlFrequency;//range: 7280~26900 (100KHz unit)
	kal_uint8 band;//range 1~40
	kal_uint8 duplexMode;//0:tdd, 1:fdd
	kal_uint8 tddConfig;//range 0~7
	kal_uint8 tddSfConfig;//range 0~8
	kal_uint8 bandwidth;//(UL BW) 0: 6 RB, 1: 15 RB, 2: 25 RB, 3: 50 RB, 4: 75 RB, 5: 100 RB
	kal_uint8 rxPath0Enbl;
	kal_uint8 rxPath1Enbl;

	/*Tx-Rx & Pseudo Tx-Rx only*/
	kal_uint16 ulFrequency;//range: 7280~26900 (100KHz unit)
	kal_int16 txPowerValue;/*S(8,8)*/

	/*Pseudo Tx-Rx only*/
	kal_uint8 vrbStart;
	kal_uint8 vrbLength;
	kal_uint8 mcsMode;	
	
}ERfTestCmdMixRx;

typedef struct
{
	kal_uint8 measRptCnt;//range 0~10
	kal_int16 rssiPath0[10];//final format is TODO
	kal_int16 rssiPath1[10];//final format is TODO
	kal_int16 rsrpPath0[10];//final format is TODO
	kal_int16 rsrpPath1[10];//final format is TODO
	kal_int16 rsrqPath0[10];//final format is TODO
	kal_int16 rsrqPath1[10];//final format is TODO

	kal_uint32 crcOK_cnt;
	kal_uint32 crcNG_cnt;
}ERfTestCmdGetMixRxRpt;

typedef struct
{
	/* PA Control */
	kal_uint8 paControlLevel; /* 2~8 */
	kal_uint8 calRoomTempIdx;
	kal_int16 hysteresisStart0;
	kal_int16 hysteresisEnd0;
	kal_int16 hysteresisStart1;
	kal_int16 hysteresisEnd1;
	kal_uint8 paMode[8]; /* 0:high, 1:middle, 2:low */
	kal_int16 pRf[8];
	kal_uint16 paGain[8];
	kal_uint8 dc2dcLevel[8]; /* voltage map by chip, TODO */
	kal_uint16 vBiasDac[8]; 
	kal_uint8 vm0[8];
	kal_uint8 vm1[8];
	/* TX Compensation */
	kal_uint16 ulFrequency[21];//100kHz unit
	kal_int16 paGainHigh[8][21];
	kal_int16 paGainMiddle[8][21];
	kal_int16 paGainLow[8][21];
	kal_int16 couplerLossHigh;
	kal_int16 couplerLossMiddle;
	kal_int16 couplerLossLow;
	kal_int16 powerDetectorHigh[8][21];
	kal_int16 powerDetectorMiddle[8][21];
	kal_int16 powerDetectorLow[8][21];
}ERfTestCmdGetSetTpcSetting;

/* the strict ordering MUST be kept */
typedef struct 
{
	/*Struct should be 4 bytes alignment*/
	kal_uint32 supportBandMap[ERF_BAND_MAP_SIZE];     /*eg. Map[1]=0x3, it means we support band32, band33        */
	kal_uint32 supportMipiBandMap[ERF_BAND_MAP_SIZE]; /*eg. Map[1]=0x3, it means we support MIPI at band32, band33*/
	kal_uint32 supportCoexistenceBandMap[ERF_BAND_MAP_SIZE]; /*eg. Map[1]=0x3, it means we need to check wifi co-existence at band32, band33*/

}ErfCapabilityItemSet;

/* DO NOT modify this structure */
typedef struct
{
	kal_uint32 is_capable  : 1;
	kal_uint32 is_mandatory: 1;
	kal_uint32 parameter   :30;

}ErfCalibrationItem;

/* the strict ordering MUST be kept */
typedef struct
{
	/*Struct should be 4 bytes alignment*/
	ErfCalibrationItem tadc_cal;                 /*TADC calibration item                                 */
	ErfCalibrationItem multi_rat_tadc_bitmap;    /*bit map of multi-rat TADC calibration                 */
	ErfCalibrationItem multi_rat_afc_bitmap;     /*bit map of multi-rat AFC calibration                  */
	ErfCalibrationItem pd_temp_comp;             /*Target support PD temperature compensation            */
	ErfCalibrationItem mipi_pa_level_and_cw_num; /*MIPI PA power level and codeword number for each level*/
	ErfCalibrationItem temperature_info;         /*Temperature info. API                                 */
	ErfCalibrationItem et_module_support;        /*support ET module or not                              */
	ErfCalibrationItem tool_usage_setting_support; /* Supporty set tool usage or not                       */
	ErfCalibrationItem thermal_sensor_type;      /*Report thermal sensor type (internal or external)     */
	ErfCalibrationItem cap_id_calibration;       /*CAP ID calibration item                               */
	ErfCalibrationItem enable_csr;               /* Enable CSR/MIB in Meta TX PUSCH mode                 */

}ErfCalibrationItemSet;

/* the strict ordering MUST be kept calibrationItems & capabilityItems are variable part*/
typedef struct
{
	/*Struct should be 4 bytes alignment*/
	kal_uint32 rfId;                      /*Please use enmeration "ERfId"*/
	kal_uint32 capability_item_offset;    /*Erf capability item offset (byte unit) from structure begin */
	kal_uint32 calibration_item_offset;   /*Erf calibration item offset (byte unit) from structure begin*/
	ErfCapabilityItemSet  capabilityItems;
	ErfCalibrationItemSet calibrationItems;

}ERfTestResultRfCapability;

typedef struct
{
	kal_uint8 duplexMode;/* 0:tdd, 1:fdd */
	kal_uint8 band; 
	kal_uint16 ulFrequency;/* range: 0~65535 (100KHz unit) */
	kal_uint8 capid;    /* 0 ~ 255 */
	kal_int16 afcdac;  /* 0 ~ 8191 */
	kal_uint8 afcDataType ; /* 0: calibration data, 1: interface */
	kal_int16 txPowerValue;/*S(8,8),  x dB * 256.0 */
}ERfTestCmdAfcSingleToneTx;

typedef struct
{
	kal_uint8     capid;       /* 0 ~ 255 */
	kal_uint16    afcdac;     /* 0 ~ 8191 */
	kal_int32     slopeInv;  
}ERfFreqAdjustTable;

typedef struct
{
	kal_uint8 duplexMode;/* 0:tdd, 1:fdd */
	kal_uint8 band;
	kal_uint16 ulFrequency;/* range: 0~65535 (100KHz unit) */
	kal_uint8 bandwidth;//(UL BW) 0: 6 RB, 1: 15 RB, 2: 25 RB, 3: 50 RB, 4: 75 RB, 5: 100 RB
	kal_int16 ulFrequencyOffset;/* range: -32768~32767 */
	kal_int16 afcdac;
	kal_uint8 afcDataType ; /* 0: calibration data, 1: interface */
	kal_int16 txPowerValue;/*S(8,8), x dB * 256.0 */
	kal_uint8 txCloseLoopDisbl;
	kal_uint8 paMode;
}ERfTestCmdTpcSingleToneTx;

typedef struct
{
	kal_uint8   band; /* 1~40 */
	kal_int16 	txPaGain[8]; /* resolution 1/32 */
}ERfTestCmdSetTpcPaGain;

typedef struct
{
	kal_uint8 	duplexMode;/* 0:tdd, 1:fdd */
	kal_uint8	band; /* 1~40 */
	kal_uint8   num_freq; /* 1~36 */
	kal_uint16  dl_freq[36];  
	kal_uint8   temperatureIndex; /* 0~7 */
	kal_int16   gain1; /* resolution 1/32 */
	kal_int16   gain2; /* resolution 1/32 */
}ERfTestCmdRSSI;

typedef struct
{
	kal_uint8  duplexMode;/* 0:tdd, 1:fdd */
	kal_uint8   band; /* 1~40 */
	kal_uint16  dl_freq;
	kal_uint8   bandwidth;//(DL BW) 0: 6 RB, 1: 15 RB, 2: 25 RB, 3: 50 RB, 4: 75 RB, 5: 100 RB
	kal_uint16 gain1; /* main path, resolution 1/32 */
	kal_uint16 gain2;  /* rx diversity path, resolution 1/32 */
} ERfTestCmdContRx;

typedef struct
{
	kal_uint8   num_freq;
	kal_int16   dl_freq[36];
	kal_int16   rssi[36]; /* resolution 1/32 */
	kal_uint8   lna_mode[36]; /* 0 ~ 5 */
	kal_int16   rssi_rxd[36]; /* resolution 1/32 */
	kal_uint8   lna_mode_rxd[36]; /* 0 ~ 5 */
}ERfTestResultRSSI;

typedef struct
{
	kal_int16  lna_mode[6]; //loss of mode 0~5; resolution 1/32
}ERfRSSIGainOffsetTable;

typedef struct
{
	ERfRSSIGainOffsetTable gain_of_dl_freq[15];
}ERfRSSITempOffsetTable;

typedef struct
{
	kal_uint16 dlMainFrequency[15];
	kal_uint16 dlDiversityFrequency[15];
	ERfRSSITempOffsetTable  pathlossMainData[8];
	ERfRSSITempOffsetTable  pathlossDiversityData[8];
}ERfRSSIBandGainTable;

typedef struct 
{
	
    kal_uint32      result;    // 1: support 0: not support
    kal_uint32      query_op_code;  // query op code
}ERfCheckIfFuncExist;

typedef struct
{
    kal_uint16 data[8];
} ERfTadcSetting; 

typedef struct
{
    kal_uint16 measure_count;
} ERfTestCmdGetRfTemp;

typedef struct 
{
    kal_uint16 rf_band_idx;
    kal_uint16 power_level_num;
    kal_uint16 code_word_num;
}ERfTestCmdSetMIPICodeWord;

typedef struct 
{
    kal_uint8  mipi_rf_band;
}ERfTestCmdGetMIPICodeWord;

typedef union
{
	ERfTestCmdPuschTx puschTxParam;
	ERfTestCmdPucchTx pucchTxParam;
	ERfTestCmdPrachTx prachTxParam;
	ERfTestCmdSrsTx srsTxParam;
	ERfTestCmdMixRx mixRxParam;
	kal_uint8 tpcSettingBandIndex;
	ERfTestCmdRSSI rssiRxParam;
	ERfTestCmdContRx contRxParam;
	ERfTestCmdAfcSingleToneTx afcSingleToneTxParam;
	ERfTestCmdTpcSingleToneTx tpcSingleToneTxParam;
	ERfTestCmdSetTpcPaGain tpcPaGainSetting;
	kal_uint8 rxRSSITableBandIndex;
	ERfTestCmdType query_op_code;
	ERfTestCmdGetRfTemp getRfTemp;
	ERfTestCmdSetMIPICodeWord setMipiCodeWord;
	ERfTestCmdGetMIPICodeWord getMipiCodeWord;
}ERfTestCmdParam;

typedef struct
{
    kal_bool   ok;
    kal_uint32 sum;
} ERfTestResultRfTemperature;

typedef struct
{
    kal_uint32	result;
    kal_uint8	l1cStatus;
} ERfTestCmdGeneralResult;

typedef struct 
{
    kal_uint8  status;
    kal_uint16 power_level_num;
    kal_uint16 code_word_num;
}ERfTestResultGetMIPICodeWord;

typedef struct
{
    kal_int16 status;
    kal_int16 tadc_dac;
    kal_int16 temperature;
    kal_int16 temp_idx;
}ERfTestResultRfTemperatureInfo;

typedef enum
{
    ERF_GTI_STATUS_SUCCESS        = 0,
    ERF_GTI_STATUS_INTERPO_FAIL   = 1,
    ERF_GTI_STATUS_TEMP_OVERFLOW  = 2,
    ERF_GTI_STATUS_TEMP_UNDERFLOW = 3
}ERfTestGetTempInfoStatus;

typedef union
{
	kal_uint32 result;
	ERfTestCmdGeneralResult generalResult;
	ERfTestCmdGetMixRxRpt mixRxRpt;
	ERfTestResultRfTemperature rfTemperature;
	ERfTestResultRfTemperatureInfo rfTemperatureInfo;
	kal_int16 txPowerDetectorValue;     /* resolution 1/32 */
	ERfCheckIfFuncExist  CheckIfFuncExist;
	ERfTestResultGetMIPICodeWord getMipiCodeWord;
}ERfTestResultParam;

typedef struct
{
  	FT_H header;
  	kal_uint32 type;
  	ERfTestCmdParam param;
}FT_ERF_TEST_REQ;

typedef struct
{
  	FT_H header;
  	kal_uint32 type;
  	ERfTestResultParam param;
}FT_ERF_TEST_CNF;

typedef struct
{
	kal_uint16 dl_freq;//100kHz unit
	kal_int16	rssi[MAX_PWR_STEP_NUM];
	kal_int16	rssi_rxd[MAX_PWR_STEP_NUM];
	kal_uint8	lna_mode[MAX_PWR_STEP_NUM];
	kal_uint8	lna_mode_rxd[MAX_PWR_STEP_NUM];
	kal_uint8	pwr_step_num;
}FHC_Rx_Freq_Rpt;

typedef struct
{
	kal_uint16 ul_freq;//100kHz unit
	kal_int16 txPowerDetectorValue[MAX_PWR_STEP_NUM];
	kal_uint8 pwr_step_num;
}FHC_Tx_Freq_Rpt;

typedef struct 
{
	kal_uint8 band_index;
	kal_uint8	tx_freq_num;
	kal_uint8	rx_freq_num;
	FHC_Tx_Freq_Rpt tx_freq_rpt[MAX_FHC_TX_FREQ_NUM];	
	FHC_Rx_Freq_Rpt rx_freq_rpt[MAX_FHC_RX_FREQ_NUM];	
}FHC_TRx_Band_Rpt;

typedef struct 
{
	kal_uint8 band_num;
	FHC_TRx_Band_Rpt band_rpt[MAX_FHC_BAND_NUM];
}FHC_Rx_Rpt;

typedef struct
{
	kal_uint16 ul_freq;//100kHz unit
	kal_uint8	ul_bw;//0(1.4M)~5(20M)
	kal_uint8	pwr_step_num;
	kal_int16	pwr_step_value[MAX_PWR_STEP_NUM];//S(8, 8)        
	kal_int16	pwr_step_pa_gain [MAX_PWR_STEP_NUM];
	kal_uint8	pwr_step_pa_gain_tbl_indx [MAX_PWR_STEP_NUM];
	kal_uint8	pwr_step_pa_mode [MAX_PWR_STEP_NUM];
}FHC_Tx_Freq_Param;

typedef struct
{
	kal_uint16 dl_freq;//100kHz unit
	kal_uint8	temperature_indx;
	kal_uint8	pwr_step_num;
	kal_int16	gain1[MAX_PWR_STEP_NUM];
	kal_int16	gain2[MAX_PWR_STEP_NUM];
}FHC_Rx_Freq_Param;

typedef struct
{
	kal_uint8 band_index;
	kal_uint8	freq_num;
	FHC_Tx_Freq_Param freq_param[MAX_FHC_TX_FREQ_NUM];	        
}FHC_Tx_Band_Param;

typedef struct
{
	kal_uint8 band_index;
	kal_uint8	freq_num;
	FHC_Rx_Freq_Param freq_param[MAX_FHC_RX_FREQ_NUM];	        
}FHC_Rx_Band_Param;

typedef struct
{
	kal_uint8 tx_to_rx_time;//ms unit
	kal_uint8 band_num;
	FHC_Rx_Band_Param band_param[MAX_FHC_BAND_NUM];
}FHC_Rx_Cfg;

typedef struct 
{
	kal_uint8  tx_step_width;//ms unit
	kal_uint8 band_num;
	FHC_Tx_Band_Param band_param[MAX_FHC_BAND_NUM];
	kal_int16	freq_offst;//range -32768~32767
	kal_int16	afc_dac;
	kal_uint8	afc_data_type;//0: calibration data, 1: from interface value
	kal_uint8	close_loop_disable;
}FHC_Tx_Cfg;

typedef struct 
{
    kal_uint8 phy_cell_id;//no used for single tone?
    kal_uint8 fdd_band_start_index; 
    kal_uint8 fdd_band_end_index;
    kal_uint8 tdd_band_start_index;
    kal_uint8 tdd_band_end_index;
    kal_uint8 fdd_to_tdd_switch_time;//ms unit
    kal_uint8 tdd_to_fdd_switch_time;//ms unit
    kal_uint8 tdd_tx_rx_switch_time;//ms unit
    kal_uint8 freq_switch_time;//ms unit
    kal_uint8 band_switch_time;//ms unit
    FHC_Tx_Cfg txCmd;
    FHC_Rx_Cfg rxCmd;
}FHC_Cmd;

typedef struct
{
	kal_uint8	pwr_step_num;//0~8;
	kal_int16	pwr_step_tx_power[8];//S(8,8)
	kal_uint8 pwr_step_VRB_strt [8];
	kal_uint8	pwr_step_VRB_len [8];
} NSFT_List_Tx_Specify_Pwr_Param;

typedef struct
{	
	kal_int16	start_power; //S(8,8)
	kal_int16	pwr_step_value; //S(8,8)
	kal_uint8	pwr_step_num;

	kal_uint8	pwr_step_VRB_strt_p1; //start VRB for the first period
	kal_uint8	pwr_step_VRB_len_p1;
	kal_uint8	pwr_step_VRB_strt_p2; //start VRB for the second period
	kal_uint8	pwr_step_VRB_len_p2;

	kal_uint8	step_for_change_tx_VRB; //0: Tx VRB will be changed to p2 at step 0

} NSFT_List_Tx_Specify_Step_Param;

typedef struct 
{
	kal_uint16 ul_freq;//100kHz unit
	kal_uint8	ul_bw;//0(1.4M)~5(20M)
	kal_uint8	pwr_step_MCS_mode; //0:QPSK, 1:16QAM, 2:64QAM
	kal_bool cmd_type; 	//0: NSFT_List_Tx_Specify_Pwr_Param, 1: NSFT_List_Tx_Specify_Step_Param, 0xFF: invalid type
	union 
	{
		 NSFT_List_Tx_Specify_Pwr_Param specify_tx_pwr_cmd;
		 NSFT_List_Tx_Specify_Step_Param specify_pwr_step_cmd;	
	}nsft_list_pwr_step_cmd;
} NSFT_List_Tx_Freq_Param;

typedef struct
{
	kal_uint8 band_index;
	kal_uint8	freq_num;
	kal_uint16 dl_sync_freq;
	NSFT_List_Tx_Freq_Param freq_param[MAX_NSFT_LIST_TX_FREQ_NUM];	        
} NSFT_List_Tx_Band_Param;

typedef struct
{
	kal_uint8 fdd_tx_step_width;//ms unit
	kal_uint8 tdd_tx_step_width;//ms unit
	kal_uint8 band_num;
	NSFT_List_Tx_Band_Param band_param[MAX_NSFT_LIST_TX_BAND_NUM];
	kal_int16	freq_offst;//range -32768~32767
	kal_int16	afc_dac;
	kal_uint8	afc_data_type;//0: calibration data, 1: from interface value
	kal_uint8	close_loop_disable;
}NSFT_List_Tx_Cfg;

typedef struct NSFT_List_Cmd 
{
	kal_uint8 phy_cell_id;//no used for single tone?
	kal_uint8 fdd_band_start_index;//0xFF if there is no FDD band.
	kal_uint8 fdd_band_end_index;//0xFF if there is no FDD band.
	kal_uint8 tdd_band_start_index;//0xFF if there is no TDD band.
	kal_uint8 tdd_band_end_index;//0xFF if there is no TDD band.
	kal_uint8 fdd_to_tdd_switch_time;//ms unit
	kal_uint8 fdd_freq_switch_time;//ms unit
	kal_uint8 tdd_freq_switch_time;//ms unit
	kal_uint8 fdd_band_switch_time;//ms unit
	kal_uint8 tdd_band_switch_time;//ms unit
	kal_uint16 fdd_dl_sync_time;//ms unit
	kal_uint16 tdd_dl_sync_time;//ms unit	
	NSFT_List_Tx_Cfg txCmd;
}NSFT_List_Cmd;

#endif
 

 
