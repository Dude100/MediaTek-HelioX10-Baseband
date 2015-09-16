/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	el1_rf_public.h
 *
 * Project:
 * --------
 *   MT7206RF
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 *
 *
 *******************************************************************************/

/*===============================================================================================*/

#ifndef EL1_RF_PUBLIC_H
#define EL1_RF_PUBLIC_H

/*******************************************************************************
** Includes
*******************************************************************************/
#include "el1_rf_cid.h"
#include "mml1_rf_global.h"
#include "lte_custom_mipi.h"
#include "el1_meta_if.h"

/*******************************************************************************
** Setting for specific RF
*******************************************************************************/
#if IS_EL1_RF_MT6169
#include "el1_rf_public_mt6169.h"
#else
   #error "Should define at least a kind of RF being used."
#endif

/*******************************************************************************
** Constants
*******************************************************************************/
#define LTE_BIT_MASK_BUFFER_SIZE               (64/32) // support 64 band at max
#define CAL_TEMP_SECTION_LTE                        8
#define CAL_EARFCN_SECTION_LTE                     21
#define CAL_DL_EARFCN_SECTION_LTE                  15
#define LNA_MODE_NUM                                6

#define LTE_SPEC_SUPPORT_BAND_NUM                  25
#define LTE_AUGMENTED_BAND_ARRAY_NUM               (LTE_TARGET_MAX_SUPPORT_BAND_NUM+1)

#define LTE_PA_HIGH_MODE                           (0)
#define LTE_PA_MID_MODE                            (1)
#define LTE_PA_LOW_MODE                            (2)
#define LTE_MAX_NUM_PA_CONTROL_LEVEL               (8)
#define LTE_PRF_THR_SIGNED_BIT_SHIFT              (14)
#define LTE_PRF_THR_INTEGER_BIT_SHIFT              (8)
#define LTE_POWER_CLASS                            (3)
#define LTE_FREQ_IN_RB_INTEGER_BIT_SHIFT           (5)
#define LTE_PA_SECTION_MAX_THRESHOLD               (6)
#define RESOURCE_BLOCK_SPAN_IN_HZ             (180000)
#define LTE_PA_SECTION_ADDITIONAL_CNTRL_NUM        (7)
#define LTE_PA_CPL_GAIN_SLOPE_RESOLUTION_FACTOR (1024)

#define TEMP_COMPENSATE_STEP                       (4) // i.e. 0.125 dB = 4/32 dB


#define LTE_RFC_NUM_OF_CAL_CODE_FOR_POC            (6)
#define LTE_RFC_NUM_OF_CAL_CODE_FOR_RUNTIME_CAL    (3)
#define LTE_RFC_MAX_NUM_OF_CAL_CODE                (8)

#define LTE_RFC_RXIQ_CAL_CODE                      (0)
#define LTE_RFC_RXDCOC_CAL_CODE                    (1)
#define LTE_RFC_DETIQDC_DNL_CAL_CODE               (2)
#define LTE_RFC_TXRC_CAL_CODE                      (3)
#define LTE_RFC_TXGA_CAL_CODE                      (4)
#define LTE_RFC_TXIQDC_DNL_CAL_CODE                (5)
#define LTE_RFC_CAL_CODE_NONE                      (0)

#if (LTE_RFC_NUM_OF_CAL_CODE_FOR_POC > LTE_RFC_MAX_NUM_OF_CAL_CODE)  || (LTE_RFC_NUM_OF_CAL_CODE_FOR_RUNTIME_CAL > LTE_RFC_MAX_NUM_OF_CAL_CODE)
#error "Number of cal. code exceeds its maximum value"
#endif

#define LTE_RFC_RXDCOC_BAND_DIMENSION              (3)
#define LTE_RFC_RXDCOC_PATH_NUM                    (2)
#define LTE_RFC_RXDCOC_BW_NUM                      (6)
#define LTE_RFC_RXDCOC_LNA_NUM                     (7)
#define LTE_RFC_RXDCOC_GAIN_STEPS_NUM             (32)

#define LTE_MAX_SUPPORT_BAND_NUM                  (45)
#define LTE_ERF_SPLIT_BAND                          5 //How many bands need to split? Band28/Band41/Reserved
#define LTE_ERF_MAX_SPLIT_PART                      3 //Split to at most 3 parts
                                                      //The 1st data are stored in ERF_RX_(P/S)DATABASE and ERF_TX_(P/S)DATABASE
                                                      //The 2nd and 3rd data are stored in ERF_SPLIT_RFDATABASE
#define LTE_ERF_TX_BYPASS_PATH_NUM                  1 //How many TX bypass path will be used for each band
#define LTE_ERF_SPLIT_TABLE_SIZE                   (LTE_ERF_MAX_SPLIT_PART+LTE_ERF_TX_BYPASS_PATH_NUM-1)
#define LTE_ERF_SPLIT_NUM                          (LTE_ERF_SPLIT_BAND*LTE_ERF_SPLIT_TABLE_SIZE)

//Transmit Antenna Selection Feature
#define LTE_ERF_TAS_SET_NUM                         7 //How many selection sets for each band
#define LTE_ERF_TAS_BAND_NUM                       (LTE_TARGET_MAX_SUPPORT_BAND_NUM)
#define LTE_ERF_TAS_TOTAL_NUM                      (LTE_ERF_TAS_BAND_NUM*LTE_ERF_TAS_SET_NUM)

#define LTE_EL1_ENB_SM                              1    //          Enable of antenna-switch metric function
#define LTE_EL1_TAS_N_MS_J_HYS                      4    //MS,       Hysteresis duration control for leaving normal state
#define LTE_EL1_TAS_N_MS_SM_FADEOUT                 1600 //MS,       The timer duration for antenna-switching metric fadeout protection
#define LTE_EL1_TAS_PHI_BOUND                       8    //dB,       Up/low bound for applying antenna-switching metric as threshold
#define LTE_EL1_TAS_PHI_01_DEFAULT                  0    //dB,       Antenna-switching metric default value from ant. 0 to ant. 1
#define LTE_EL1_TAS_PHI_10_DEFAULT                  0    //dB,       Antenna-switching metric default value from ant. 1 to ant. 0
#define LTE_EL1_ENB_DB                              1    //          Enable of dynamic barrier control function
#define LTE_EL1_TAS_DELTA_DB_FAIL_STEP_RSRP         4    //dB,       The increased amount for RSRP barrier for a fail pre-switch
#define LTE_EL1_TAS_DELTA_DB_FAIL_STEP_TXP          2    //dB,       The increased amount for TX power barrier for a fail pre-switch
#define LTE_EL1_TAS_N_MS_DB_RELAX                   128  //MS,       The timer duration to relax the dynamic barrier
#define LTE_EL1_TAS_DELTA_DB_TO_STEP                1    //dB,       RSRP/TXP: The decreased barrier when per timer is reached
#define LTE_EL1_TAS_DELTA_DB_BOUND_RSRP             9    //dB,       The upper bound of the extra-threshold Delta_RSRP_DB
#define LTE_EL1_TAS_DELTA_DB_BOUND_TXP              6    //dB,       The upper bound of the extra-threshold Delta_TXP_DB
#define LTE_EL1_TAS_RSRP_DIFF_THD                   4    //dB,       RSRP difference threshold to trigger TAS, defined as the RSRP value difference from diversity to main antennas
#define LTE_EL1_TAS_RSRP_DIFF_THD_TXP               4
#define LTE_EL1_TAS_RSRP_DIFF_THD_CB                0
#define LTE_EL1_RSRP_THD_CONNECT_EN                 1    //          RSRP_diff_thd_xxx are connected or not
#define LTE_EL1_TAS_RSRP_CB_DROP_THD                -6   //dB,       RSRP drop threshold to trigger TAS when check back, defined as the RSRP value difference from current value to its previous one
#define LTE_EL1_TAS_TXP_CB_INC_THD                  8    //dB,       Transmit power (TXP) increase threshold to trigger TAS when check back, defined as the TXP value difference from current value to its previous one
#define LTE_EL1_TAS_N_MS_CB                         16   //MS,       The look/check back period (for RSRP and TXP change monitoring), using measurement slot (MS) as the unit
#define LTE_EL1_TAS_HTP_LEVEL                       -3   //dB,       The high transmit power (HTP) level, defined as the ratio (in dB) to UE's maximum transmit power
#define LTE_EL1_TAS_HTP_RATIO_THD                   50   //%,        A HTP is recognized when the percentage using TXP (within a measurement slot) greater than HTP_level is higher than the ratio threshold
#define LTE_EL1_TAS_TXP_INC_THD_SB                  4    //dB,       TXP increase threshold when switch to the diversity antenna, for which exceeding the threshold would be recognized as a fail antenna switch
#define LTE_EL1_TAS_N_MS_SB                         16   //MS,       The monitoring duration for switch-back check, using measurement slot (MS) as the unit

/*** MIPI BYPASS Feature ***/
#define  LTE_MIPI_BYPASS_MAX_SUPPORT_BAND_NUM      (5)

#if IS_4G_TX_POWER_OFFSET_SUPPORT
#define TPO_4G_TABLE_NUM                            2
#define TPO_4G_BIT_NUM_FOR_TABLE_0                  4
#define TPO_4G_BIT_NUM_FOR_TABLE_1                  5
#endif

/*===============================================================================*/

#define LTE_BAND_RAMP_DATA(b)                    b##_RampData
#define LTE_RAMP_DATA(b)                         LTE_BAND_RAMP_DATA(b)

#define LTE_BAND_PA_OCT_LEVEL_DATA(b)            b##_PaOctLevData
#define LTE_PA_OCT_LEVEL_DATA(b)                 LTE_BAND_PA_OCT_LEVEL_DATA(b)

#define LTE_BAND_RSSI_GAIN_TABLE(b)              b##_RSSIGainTbl
#define LTE_RSSI_GAIN_TABLE(b)                   LTE_BAND_RSSI_GAIN_TABLE(b)

#define LTE_BAND_ET_VIN_LUT(b)                   b##_EtVinLutData
#define LTE_ET_VIN_LUT(b)                        LTE_BAND_ET_VIN_LUT(b)

#define LTE_BAND_MIPI_RX_EVENT(b)                b##_MIPI_RX_EVENT
#define LTE_MIPI_RX_EVENT(b)                     LTE_BAND_MIPI_RX_EVENT(b)

#define LTE_BAND_MIPI_RX_DATA(b)                 b##_MIPI_RX_DATA
#define LTE_MIPI_RX_DATA(b)                      LTE_BAND_MIPI_RX_DATA(b)

#define LTE_BAND_MIPI_TX_EVENT(b)                b##_MIPI_TX_EVENT
#define LTE_MIPI_TX_EVENT(b)                     LTE_BAND_MIPI_TX_EVENT(b)

#define LTE_BAND_MIPI_TX_DATA(b)                 b##_MIPI_TX_DATA
#define LTE_MIPI_TX_DATA(b)                      LTE_BAND_MIPI_TX_DATA(b)

#define LTE_BAND_MIPI_TPC_EVENT(b)               b##_MIPI_TPC_EVENT
#define LTE_MIPI_TPC_EVENT(b)                    LTE_BAND_MIPI_TPC_EVENT(b)

#define LTE_BAND_MIPI_TPC_DATA(b)                b##_MIPI_TPC_DATA
#define LTE_MIPI_TPC_DATA(b)                     LTE_BAND_MIPI_TPC_DATA(b)

#define LTE_BAND_MIPI_PA_SECTION_DATA(b)         b##_MIPI_PA_SECTION_DATA
#define LTE_MIPI_PA_SECTION_DATA(b)              LTE_BAND_MIPI_PA_SECTION_DATA(b)

#define LTE_BAND_MIPI_BYPASS_TX_EVENT(b)         b##_MIPI_BYPASS_TX_EVENT
#define LTE_MIPI_BYPASS_TX_EVENT(b)              LTE_BAND_MIPI_BYPASS_TX_EVENT(b)

#define LTE_BAND_MIPI_BYPASS_TX_DATA(b)          b##_MIPI_BYPASS_TX_DATA
#define LTE_MIPI_BYPASS_TX_DATA(b)               LTE_BAND_MIPI_BYPASS_TX_DATA(b)

#define LTE_BAND_MIPI_BYPASS_TPC_EVENT(b)        b##_MIPI_BYPASS_TPC_EVENT
#define LTE_MIPI_BYPASS_TPC_EVENT(b)             LTE_BAND_MIPI_BYPASS_TPC_EVENT(b)

#define LTE_BAND_MIPI_BYPASS_TPC_DATA(b)         b##_MIPI_BYPASS_TPC_DATA
#define LTE_MIPI_BYPASS_TPC_DATA(b)              LTE_BAND_MIPI_BYPASS_TPC_DATA(b)

#define LTE_BAND_MIPI_BYPASS_PA_SECTION_DATA(b)  b##_MIPI_BYPASS_PA_SECTION_DATA
#define LTE_MIPI_BYPASS_PA_SECTION_DATA(b)       LTE_BAND_MIPI_BYPASS_PA_SECTION_DATA(b)

#define LTE_BAND_ET_TX_EVENT(b)                  b##_ET_TX_EVENT
#define LTE_ET_TX_EVENT(b)                       LTE_BAND_ET_TX_EVENT(b)

#define LTE_BAND_ET_TX_DATA(b)                   b##_ET_TX_DATA
#define LTE_ET_TX_DATA(b)                        LTE_BAND_ET_TX_DATA(b)

#define LTE_BAND_ET_TPC_EVENT(b)                 b##_ET_TPC_EVENT
#define LTE_ET_TPC_EVENT(b)                      LTE_BAND_ET_TPC_EVENT(b)

#define LTE_BAND_ET_TPC_DATA(b)                  b##_ET_TPC_DATA
#define LTE_ET_TPC_DATA(b)                       LTE_BAND_ET_TPC_DATA(b)

#define LTE_BAND_ET_TPC_SECTION_DATA(b)          b##_ET_TPC_SECTION_DATA
#define LTE_ET_TPC_SECTION_DATA(b)               LTE_BAND_ET_TPC_SECTION_DATA(b)

#define LTE_BAND_ET_LOOKUP_VPA_EVENT(b)          b##_ET_LOOKUP_VPA_EVENT
#define LTE_ET_LOOKUP_VPA_EVENT(b)               LTE_BAND_ET_LOOKUP_VPA_EVENT(b)

#define LTE_BAND_ET_LOOKUP_VPA_DATA(b)           b##_ET_LOOKUP_VPA_DATA
#define LTE_ET_LOOKUP_VPA_DATA(b)                LTE_BAND_ET_LOOKUP_VPA_DATA(b)

#define LTE_BAND_ET_LOOKUP_VPA_SECTION_DATA(b)   b##_ET_LOOKUP_VPA_SECTION_DATA
#define LTE_ET_LOOKUP_VPA_SECTION_DATA(b)        LTE_BAND_ET_LOOKUP_VPA_SECTION_DATA(b)

#if IS_4G_TX_POWER_OFFSET_SUPPORT
#define LTE_BAND_TX_POWER_OFFSET_DATA(b)         b##_TX_POWER_OFFSET_DATA
#define LTE_TX_POWER_OFFSET_DATA(b)              LTE_BAND_TX_POWER_OFFSET_DATA(b)
#endif

/*===============================================================================*/

//Utility for RF customization
#define MICROSECOND_TO_26M(x)                      ((kal_int32)((x)*26))
#define GET_16L(_x)                                ((kal_uint16)((_x)&0xFFFF))
#define GET_16H(_x)                                ((kal_uint16)((_x)>>16))

/*******************************************************************************
** Typedefs
*******************************************************************************/
typedef enum
{
   LTE_BandNone = 0,
   LTE_Band1    = 1,
   LTE_Band2    = 2,
   LTE_Band3    = 3,
   LTE_Band4    = 4,
   LTE_Band5    = 5,
   LTE_Band6    = 6,
   LTE_Band7    = 7,
   LTE_Band8    = 8,
   LTE_Band9    = 9,
   LTE_Band10   = 10,
   LTE_Band11   = 11,
   LTE_Band12   = 12,
   LTE_Band13   = 13,
   LTE_Band14   = 14,
   LTE_Band15   = 15,
   LTE_Band16   = 16,
   LTE_Band17   = 17,
   LTE_Band18   = 18,
   LTE_Band19   = 19,
   LTE_Band20   = 20,
   LTE_Band21   = 21,
   LTE_Band22   = 22,
   LTE_Band23   = 23,
   LTE_Band24   = 24,
   LTE_Band25   = 25,
   LTE_Band26   = 26,
   LTE_Band27   = 27,
   LTE_Band28   = 28,
   LTE_Band29   = 29,
   LTE_Band30   = 30,
   LTE_Band31   = 31,
   LTE_Band32   = 32,
   LTE_Band33   = 33,
   LTE_Band34   = 34,
   LTE_Band35   = 35,
   LTE_Band36   = 36,
   LTE_Band37   = 37,
   LTE_Band38   = 38,
   LTE_Band39   = 39,
   LTE_Band40   = 40,
   LTE_Band41   = 41,
   LTE_Bandcount,
   LTE_BandMax  = 0xFFFE
}  LTE_Band;

typedef  struct
{
	kal_int16 start;
	kal_int16 end;
} LTE_sHYSTERESISDATA;

// note : the vm1/vm2 config in LTE is through BPI, so it must have associated BPI pin number define in lte_custom_rf.h
typedef  struct
{
   kal_uint8  pa_mode;   //  2 bits
   kal_int16  prf;       //  ?? bits
   kal_uint8  dc2dc_lvl; //  5 bits
   kal_uint8  vm1;       //  1 bit
   kal_uint8  vm2;       //  1 bit
   kal_uint16 vbias_dac; // 10 bits
   kal_uint16 pa_gain;   //  9 bits
} LTE_sPMULEVHANDLE;

typedef struct
{
   kal_int16 coupler_loss;
   kal_uint16 subband_max_earfcn[CAL_EARFCN_SECTION_LTE];
   kal_int16  pa_compensate_value[CAL_EARFCN_SECTION_LTE][CAL_TEMP_SECTION_LTE];
   kal_int16  pd_compensate_value[CAL_EARFCN_SECTION_LTE][CAL_TEMP_SECTION_LTE];
} LTE_sTXPOWERDATA;

typedef  struct
{
   LTE_Band            band_ind;
   kal_uint8             cal_room_temp_idx;
   LTE_sHYSTERESISDATA   tx_hysteresis[2];
   LTE_sTXPOWERDATA  pa_mode[3];  //0:PA high mode, 1:PA mid mode, 2:PA low mode (use 0&1 if only 2 mode)
} LTE_sRAMPDATA;

// note : the pa_phase_compensation is not used now, just keep it for future expand
typedef  struct
{
   LTE_Band          band_ind;
   kal_uint8         octlev_num_section; // real number of sections, 8 is maximum
   kal_int16         max_pwr;// TODO: maximum power considering power backoff, unit 1/10 dB
   LTE_sPMULEVHANDLE   pmu_level_handle[8];
} LTE_sPAOCTLVLSETTING;

typedef struct
{
	kal_int16	lna_mode[LNA_MODE_NUM]; //loss of mode 0~5; resolution 1/32

} LTE_RSSIGainOffsetTable;

typedef struct
{
	LTE_RSSIGainOffsetTable gain_of_dl_freq[CAL_DL_EARFCN_SECTION_LTE];
} LTE_RSSITempOffsetTable;

typedef struct
{
	LTE_Band bandIndex;
	kal_uint16	dlMainFrequency[CAL_DL_EARFCN_SECTION_LTE];
	kal_uint16	dlDiversityFrequency[CAL_DL_EARFCN_SECTION_LTE];
	LTE_RSSITempOffsetTable  pathlossMainData[CAL_TEMP_SECTION_LTE];
	LTE_RSSITempOffsetTable  pathlossDiversityData[CAL_TEMP_SECTION_LTE];
}LTE_RSSIBandGainTable ;

typedef struct
{
	kal_uint8     capid;       /* 0 ~ 255 */
	kal_uint16    afcdac;     /* 0 ~ 8191 */
	kal_int32     slopeInv;
}LTE_FreqAdjustTable;

typedef struct
{
	kal_uint16 dc2dc_setting[2];
	kal_uint16 vm10;
	kal_uint16 vbias_dac;

}TxUPC_PA_Config;

typedef struct
{
   kal_int32 pa_gain_temp_comp[CAL_TEMP_SECTION_LTE][CAL_EARFCN_SECTION_LTE][3];
   kal_int32 pa_gain_temp_comp_slope[CAL_TEMP_SECTION_LTE][CAL_EARFCN_SECTION_LTE - 1][3];
   kal_int32 cpl_gain_temp_comp[CAL_TEMP_SECTION_LTE][CAL_EARFCN_SECTION_LTE][3];
   kal_int32 cpl_gain_temp_comp_slope[CAL_TEMP_SECTION_LTE][CAL_EARFCN_SECTION_LTE - 1][3];

}TxUPC_TEMPERATURE_Comp;

typedef struct
{
   kal_uint32 pa_gain_temp_comp_tbl_addr;
   kal_uint32 pa_gain_temp_comp_slope_tbl_addr;
   kal_uint32 cpl_gain_temp_comp_tbl_addr;
   kal_uint32 cpl_gain_temp_comp_slope_tbl_addr;

}TxUPC_TEMPERATURE_CompTbl_Addr;

/* The following structure must be configured through L1 to DSP each time:
   1. Carrier frequency change
   2. Dedicated mode with temperature change
*/

typedef struct
{
   kal_uint16 subband_count; // indicate the number of subbnad segment in use
   kal_int16  fpa_carr;      // transfer to RB unit, (fc-fcenter,ob)/1.8; (S.9.5)

   kal_uint16 pa_gain_common[8];                         // (U.6.5) 0: PA low mode, 1: PA mid mode, 2: PA high mode
   kal_int16  cpl_gain_common[3];                        // (S.6.5) 0: PA low mode, 1: PA mid mode, 2: PA high mode
   kal_int16  subband_freq[CAL_EARFCN_SECTION_LTE];          // transfer to RB unit, (fc-fcenter,ob)/1.8; (S.9.5)
   kal_int16  pa_gain_value[8][CAL_EARFCN_SECTION_LTE];      // normalized PA gain of each subband segment; (S.3.5)
   kal_int16  pa_gain_slope[8][CAL_EARFCN_SECTION_LTE - 1];  // slope for interpolation; (S.0.10)
   kal_int16  cpl_gain_value[3][CAL_EARFCN_SECTION_LTE];     // normalized coupler gain of each subband segment; (S.6.5)
   kal_int16  cpl_gain_slope[3][CAL_EARFCN_SECTION_LTE - 1]; // slope for interpolation; (S.0.10)

   kal_uint16 octlev_num_section;  // number of sections, 8 is maximum
   kal_int16  mg_to_hg_max_th;     // (S.6.8)
   kal_int16  hg_to_mg_min_th;     // (S.6.8)
   kal_int16  lg_to_mg_max_th;     // (S.6.8)
   kal_int16  mg_to_lg_min_th;     // (S.6.8)
   kal_int16  pa_vcc_thr_prf[8];   // (S.6.8)
   kal_uint16 pa_vcc_idx_th_lb[3]; // 0: PA low mode, 1: PA mid mode, 2: PA high mode
   kal_uint16 pa_vcc_idx_th_hb[3]; // 0: PA low mode, 1: PA mid mode, 2: PA high mode

   TxUPC_PA_Config pa_ctrl_config[8];

   TxUPC_TEMPERATURE_CompTbl_Addr temp_comp_tbl_addr;

} TxUPC_SW_Config;

typedef struct
{
	kal_uint16 dl_freq_path0[CAL_DL_EARFCN_SECTION_LTE];
	kal_uint16 dl_freq_path1[CAL_DL_EARFCN_SECTION_LTE];
	kal_int16 lna_mode_path0[CAL_TEMP_SECTION_LTE][CAL_DL_EARFCN_SECTION_LTE][LNA_MODE_NUM];
	kal_int16 lna_mode_path1[CAL_TEMP_SECTION_LTE][CAL_DL_EARFCN_SECTION_LTE][LNA_MODE_NUM];

}LNA_SW_Config;

typedef struct
{
	kal_uint16     capid;       /* 0 ~ 255 */
	kal_uint16    afcdac;     /* 0 ~ 8191 */
	kal_int32     slopeInv;
}FreqAdj_SW_Config;

/*********************Power on calibraion****************/

typedef struct
{
    kal_uint16 freq; // Carrier frequency, Unit: 100kHz, ex: 881MHz => 0x226A
}RfcRxIQParam;

typedef struct
{
    kal_uint16 freq; // Carrier frequency, Unit: 100kHz, ex: 881MHz => 0x226A
}RfcRxDCOCParam;

typedef struct
{
    kal_uint16 freq; // Carrier frequency, Unit: 100kHz, ex: 881MHz => 0x226A
}RfcDetIQDCDNLParam;

typedef struct
{
    kal_uint16 freq; // Carrier frequency, Unit: 100kHz, ex: 881MHz => 0x226A
}RfcTxIQDCDNLParam;

typedef struct
{
    kal_uint16 freq; // Carrier frequency, Unit: 100kHz, ex: 881MHz => 0x226A
}RfcTxGaParam;

typedef struct
{
    RfcRxIQParam       rx_iq_param[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][2];
    RfcRxDCOCParam     rx_dcoc_param[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][2];
    RfcDetIQDCDNLParam det_iqdcdnl_param[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][2];
    RfcTxIQDCDNLParam  tx_iqdcdnl_param[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][2];
    RfcTxGaParam       tx_ga_param[LTE_RFC_CURRENT_NUM_OF_SUPPORTED_BAND][2];
    kal_int32          other_rat_param[1024];
}RfcParam;

typedef struct
{
    kal_uint16 PocDataStatusDaddrl;
    kal_uint16 PocDataStatusDaddrh;
    kal_uint16 DetCdcocDaddrl;
    kal_uint16 DetCdcocDaddrh;
    kal_uint16 Rx1IqCompDaddrl;
    kal_uint16 Rx1IqCompDaddrh;
    kal_uint16 Rx2IqCompDaddrl;
    kal_uint16 Rx2IqCompDaddrh;
    kal_uint16 Rx1IqReDcocDaddrl;
    kal_uint16 Rx1IqReDcocDaddrh;
    kal_uint16 Rx1IqImDcocDaddrl;
    kal_uint16 Rx1IqImDcocDaddrh;
    kal_uint16 Rx2IqReDcocDaddrl;
    kal_uint16 Rx2IqReDcocDaddrh;
    kal_uint16 Rx2IqImDcocDaddrl;
    kal_uint16 Rx2IqImDcocDaddrh;
    kal_uint16 DetIqGainCompDaddrl;
    kal_uint16 DetIqGainCompDaddrh;
    kal_uint16 DetIqPhaseCompDaddrl;
    kal_uint16 DetIqPhaseCompDaddrh;
    kal_uint16 DetIqReDcCompDaddrl;
    kal_uint16 DetIqReDcCompDaddrh;
    kal_uint16 DetIqImDcCompDaddrl;
    kal_uint16 DetIqImDcCompDaddrh;
    kal_uint16 DetFeGainDaddrl;
    kal_uint16 DetFeGainDaddrh;
    kal_uint16 DetDnlDaddrl;
    kal_uint16 DetDnlDaddrh;
    kal_uint16 TxIqGainPhaseDcCompDaddrl;
    kal_uint16 TxIqGainPhaseDcCompDaddrh;
    kal_uint16 TxDnlDaddrl;
    kal_uint16 TxDnlDaddrh;
    kal_uint16 TxRcfCselDaddrl;
    kal_uint16 TxRcfCselDaddrh;
    kal_uint16 TxGaCompDaddrl;
    kal_uint16 TxGaCompDaddrh;
    kal_uint16 TxIqGainCompDaddrl;
    kal_uint16 TxIqGainCompDaddrh;
    kal_uint16 TxIqPhaseCompDaddrl;
    kal_uint16 TxIqPhaseCompDaddrh;
    //kal_uint16 EtCompParamDaddrl;
    //kal_uint16 EtCompParamDaddrh;
}RfcResultAddrInd;

typedef struct
{
   kal_uint16 DramAddrl;
   kal_uint16 DramAddrh;
}RfcDramAddrInd;

typedef struct
{
   kal_uint32 rxdcoc[LTE_RFC_RXDCOC_GAIN_STEPS_NUM];
}LTE_DCOC_BYLNA_T;

typedef struct
{
   LTE_DCOC_BYLNA_T rxLna[LTE_RFC_RXDCOC_LNA_NUM];
}LTE_DCOC_BYBW_T;

typedef struct
{
   LTE_DCOC_BYBW_T rxBw[LTE_RFC_RXDCOC_BW_NUM];
}LTE_DCOC_BYPATH_T;

typedef struct
{
   LTE_DCOC_BYPATH_T rxPath[LTE_RFC_RXDCOC_PATH_NUM];
}RXDCOC_TABLE_T;

#define LTE_RFC_ET_NUM_CAT       (5)   /*number of categories*/
#define LTE_RFC_ET_NUM_CBW       (6)   /*number of channel bandwidth*/
#define LTE_RFC_ET_NUM_VIN       (33)  /*number of Vin entries -1*/
#define LTE_RFC_ET_NUM_SUBBNAD   (8)   /*number of subbands per band*/
#define LTE_RFC_ET_NUM_BAND      (14)  /*number of supported bands*/
#define LTE_RFC_ET_NUM_BAND_PER_CAT (9)/*number of supported bands per category*/
//typedef struct
//{
//   kal_uint16 VinVpaLut[LTE_RFC_ET_NUM_VIN];
//   kal_uint16 VinPmLut [LTE_RFC_ET_NUM_VIN];
//   kal_uint16 VinAmLut [LTE_RFC_ET_NUM_VIN];
//} LTE_RfcEtVinLutPerSubBand_T;

typedef struct
{
   //LTE_RfcEtVinLutPerSubBand_T RfcEtVinLutPerSubBand[LTE_RFC_ET_NUM_SUBBNAD];
   kal_uint16 VinVpaLut[LTE_RFC_ET_NUM_SUBBNAD][LTE_RFC_ET_NUM_VIN];
   kal_uint16 VinPmLut [LTE_RFC_ET_NUM_SUBBNAD][LTE_RFC_ET_NUM_VIN];
   kal_uint16 VinAmLut [LTE_RFC_ET_NUM_SUBBNAD][LTE_RFC_ET_NUM_VIN];
} LTE_RfcEtVinLutPerBand_T;

typedef struct
{
   kal_uint16    PathDelay[LTE_RFC_ET_NUM_CAT][LTE_RFC_ET_NUM_CBW];
   kal_uint16    CatMap[LTE_RFC_ET_NUM_CAT][LTE_RFC_ET_NUM_BAND_PER_CAT];
   kal_uint16    SubBandFreq[24][LTE_RFC_ET_NUM_SUBBNAD];
   LTE_Band      Bands[LTE_RFC_ET_NUM_BAND];
} LTE_RfcEtCompParam_T;
typedef struct
{
   kal_uint32 band_support_num;
   kal_uint16 band_mapping[LTE_TARGET_MAX_SUPPORT_BAND_NUM];
   kal_uint16 band_hml_define_rx0[LTE_TARGET_MAX_SUPPORT_BAND_NUM];
   kal_uint16 band_hml_define_rx1[LTE_TARGET_MAX_SUPPORT_BAND_NUM];
}RFC_RXBAND_PATH_MAP_T;

typedef struct
{
   kal_uint16 LteTempDac[CAL_TEMP_SECTION_LTE];
} LTE_TemperatureDac_T;

typedef struct
{
   LTE_Band   bandIdx;
   kal_uint16 mpr_QPSK1;
   kal_uint16 mpr_16QAM0;
   kal_uint16 mpr_16QAM1;
   kal_uint16 delta_Tc0;
   kal_uint16 delta_Tc1;
} LTE_MPRAdjust_T;

typedef struct
{
   kal_uint16 ampr_ns03_3;
   kal_uint16 ampr_ns03_5;
   kal_uint16 ampr_ns03_10;
   kal_uint16 ampr_ns03_15;
   kal_uint16 ampr_ns03_20;
} LTE_AMPR_NS03_T;

typedef struct
{
   kal_uint16 ampr_ns04_5;
   kal_uint16 ampr_ns04_10_A;
   kal_uint16 ampr_ns04_10_B;
   kal_uint16 ampr_ns04_10_C;
   kal_uint16 ampr_ns04_15_A;
   kal_uint16 ampr_ns04_15_B;
   kal_uint16 ampr_ns04_15_C;
   kal_uint16 ampr_ns04_20_A;
   kal_uint16 ampr_ns04_20_B;
   kal_uint16 ampr_ns04_20_C;
} LTE_AMPR_NS04_T;

typedef struct
{
   kal_uint16 ampr_ns05_10_15_20;
} LTE_AMPR_NS05_T;

typedef struct
{
   kal_uint16 ampr_ns07_10_A0;
   kal_uint16 ampr_ns07_10_A1;
   kal_uint16 ampr_ns07_10_B0;
   kal_uint16 ampr_ns07_10_B1;
   kal_uint16 ampr_ns07_10_C;
} LTE_AMPR_NS07_T;

typedef struct
{
   kal_uint16 ampr_ns08_10_15;
} LTE_AMPR_NS08_T;

typedef struct
{
   kal_uint16 ampr_ns09_10_15_0;
   kal_uint16 ampr_ns09_10_15_1;
} LTE_AMPR_NS09_T;

typedef struct
{
   kal_uint16 ampr_ns10_15_A;
   kal_uint16 ampr_ns10_20_A;
} LTE_AMPR_NS10_T;

typedef struct
{
   kal_uint16 ampr_ns11_3_A;
   kal_uint16 ampr_ns11_3_B;
   kal_uint16 ampr_ns11_5_A;
   kal_uint16 ampr_ns11_5_B0;
   kal_uint16 ampr_ns11_5_C;
   kal_uint16 ampr_ns11_10_A;
   kal_uint16 ampr_ns11_15_A0;
   kal_uint16 ampr_ns11_15_A1_0;
   kal_uint16 ampr_ns11_15_A1_1;
   kal_uint16 ampr_ns11_15_A2_1;
   kal_uint16 ampr_ns11_15_A3;
   kal_uint16 ampr_ns11_15_B0;
   kal_uint16 ampr_ns11_15_B1_0;
   kal_uint16 ampr_ns11_15_B2;
   kal_uint16 ampr_ns11_15_B3;
   kal_uint16 ampr_ns11_20_A0;
   kal_uint16 ampr_ns11_20_A1_0;
   kal_uint16 ampr_ns11_20_A1_1;
   kal_uint16 ampr_ns11_20_A2_1;
   kal_uint16 ampr_ns11_20_A3;
} LTE_AMPR_NS11_T;

typedef struct
{
   kal_uint16 ampr_ns12_1_A0;
   kal_uint16 ampr_ns12_1_A1;
   kal_uint16 ampr_ns12_1_B;
   kal_uint16 ampr_ns12_3_A0;
   kal_uint16 ampr_ns12_3_A1;
   kal_uint16 ampr_ns12_3_B;
   kal_uint16 ampr_ns12_5_A0;
   kal_uint16 ampr_ns12_5_A1;
   kal_uint16 ampr_ns12_5_B;
   kal_uint16 ampr_ns13_5_A0;
   kal_uint16 ampr_ns13_5_A1;
   kal_uint16 ampr_ns14_10_A0;
   kal_uint16 ampr_ns14_10_A1;
   kal_uint16 ampr_ns14_15_A0;
   kal_uint16 ampr_ns14_15_A1;
} LTE_AMPR_NS12_13_14_T;

typedef struct
{
   kal_uint16 ampr_ns15_H0_1_C;
   kal_uint16 ampr_ns15_H0_3_A;
   kal_uint16 ampr_ns15_H0_3_B;
   kal_uint16 ampr_ns15_H0_3_C;
   kal_uint16 ampr_ns15_H0_5_A;
   kal_uint16 ampr_ns15_H0_5_B;
   kal_uint16 ampr_ns15_H0_5_C;
   kal_uint16 ampr_ns15_H0_10_A;
   kal_uint16 ampr_ns15_H0_10_B;
   kal_uint16 ampr_ns15_H0_10_C;
   kal_uint16 ampr_ns15_H0_15_A;
   kal_uint16 ampr_ns15_H0_15_B;
   kal_uint16 ampr_ns15_H0_15_C;
   kal_uint16 ampr_ns15_H1_5_C;
   kal_uint16 ampr_ns15_H1_10_A;
   kal_uint16 ampr_ns15_H1_10_B;
   kal_uint16 ampr_ns15_H1_10_C;
   kal_uint16 ampr_ns15_H1_15_A;
   kal_uint16 ampr_ns15_H1_15_B;
   kal_uint16 ampr_ns15_H1_15_C;
} LTE_AMPR_NS15_T;

typedef struct
{
   kal_uint16 ampr_ns16_L0_3_A;
   kal_uint16 ampr_ns16_L0_3_B;
   kal_uint16 ampr_ns16_L0_5_A;
   kal_uint16 ampr_ns16_L0_5_B;
   kal_uint16 ampr_ns16_L0_5_C;
   kal_uint16 ampr_ns16_L0_5_D;
   kal_uint16 ampr_ns16_L0_10_A;
   kal_uint16 ampr_ns16_L0_10_B0;
   kal_uint16 ampr_ns16_L0_10_B1;
   kal_uint16 ampr_ns16_L0_10_D;
   kal_uint16 ampr_ns16_L0_10_E;
   kal_uint16 ampr_ns16_L1_5_A;
   kal_uint16 ampr_ns16_L1_5_B;
   kal_uint16 ampr_ns16_L1_5_C;
   kal_uint16 ampr_ns16_L1_10_A0;
   kal_uint16 ampr_ns16_L1_10_A1;
   kal_uint16 ampr_ns16_L1_10_C;
   kal_uint16 ampr_ns16_L1_10_D;
   kal_uint16 ampr_ns16_L1_10_E;
   kal_uint16 ampr_ns16_L2_10_A;
   kal_uint16 ampr_ns16_L2_10_B;
   kal_uint16 ampr_ns16_L2_10_C;
   kal_uint16 ampr_ns16_L2_10_D;
} LTE_AMPR_NS16_T;

typedef struct
{
   kal_uint16 ampr_ns18_5;
   kal_uint16 ampr_ns18_10_15_20;
} LTE_AMPR_NS18_T;

typedef struct
{
   kal_uint16 ampr_ns19_10_B;
   kal_uint16 ampr_ns19_15_A0;
   kal_uint16 ampr_ns19_15_A1;
   kal_uint16 ampr_ns19_15_B;
   kal_uint16 ampr_ns19_20_A0;
   kal_uint16 ampr_ns19_20_A1;
   kal_uint16 ampr_ns19_20_B;
} LTE_AMPR_NS19_T;

typedef struct
{
   kal_uint16 ampr_ns20_5_A;
   kal_uint16 ampr_ns20_5_B0_0;
   kal_uint16 ampr_ns20_5_B0_1;
   kal_uint16 ampr_ns20_5_B1;
   kal_uint16 ampr_ns20_10_A0;
   kal_uint16 ampr_ns20_10_A1_0;
   kal_uint16 ampr_ns20_10_A1_1;
   kal_uint16 ampr_ns20_10_A2;
   kal_uint16 ampr_ns20_10_B0;
   kal_uint16 ampr_ns20_10_B1;
   kal_uint16 ampr_ns20_15_A0_0;
   kal_uint16 ampr_ns20_15_A0_1;
   kal_uint16 ampr_ns20_15_A1_0;
   kal_uint16 ampr_ns20_15_A1_1;
   kal_uint16 ampr_ns20_15_A2;
   kal_uint16 ampr_ns20_15_A3;
   kal_uint16 ampr_ns20_20_A0;
   kal_uint16 ampr_ns20_20_A1_0;
   kal_uint16 ampr_ns20_20_A1_1;
   kal_uint16 ampr_ns20_20_A2;
   kal_uint16 ampr_ns20_20_A3;
   kal_uint16 ampr_ns20_20_A4;
   kal_uint16 ampr_ns20_20_A5;
} LTE_AMPR_NS20_T;

typedef struct
{
   kal_uint16 ampr_ns21_10_A0;
   kal_uint16 ampr_ns21_10_A1;
   kal_uint16 ampr_ns21_10_B0;
   kal_uint16 ampr_ns21_10_B1;
} LTE_AMPR_NS21_T;

typedef union
{
   kal_uint16               ampr_raw[24];
   LTE_AMPR_NS03_T          ampr_ns03;
   LTE_AMPR_NS04_T          ampr_ns04;
   LTE_AMPR_NS05_T          ampr_ns05;
   LTE_AMPR_NS07_T          ampr_ns07;
   LTE_AMPR_NS08_T          ampr_ns08;
   LTE_AMPR_NS09_T          ampr_ns09;
   LTE_AMPR_NS10_T          ampr_ns10;
   LTE_AMPR_NS11_T          ampr_ns11;
   LTE_AMPR_NS12_13_14_T    ampr_ns12_13_14;
   LTE_AMPR_NS15_T          ampr_ns15;
   LTE_AMPR_NS16_T          ampr_ns16;
   LTE_AMPR_NS18_T          ampr_ns18;
   LTE_AMPR_NS19_T          ampr_ns19;
   LTE_AMPR_NS20_T          ampr_ns20;
   LTE_AMPR_NS21_T          ampr_ns21;
} LTE_AMPR_ALL_T;

typedef struct
{
   LTE_Band         bandIdx;
   kal_uint16       amprIdx;
   LTE_AMPR_ALL_T   amprData;
} LTE_AMPRAdjust_T;

typedef struct
{
   kal_uint16 data_h;
   kal_uint16 data_L;
}PDATA_SET_T;

typedef struct
{
   PDATA_SET_T pr0;
   PDATA_SET_T pr1;
   PDATA_SET_T pr2;
   PDATA_SET_T pr3;
   PDATA_SET_T pr3b;
   PDATA_SET_T pr3c;
}ERF_RX_PDATA_T;

typedef struct
{
   PDATA_SET_T pt0;
   PDATA_SET_T pt1;
   PDATA_SET_T pt2;
   PDATA_SET_T pt3;
}ERF_TX_PDATA_T;

typedef struct
{
   kal_int16 fpr0;
   kal_int16 fpr1;
   kal_int16 fpr2;
   kal_int16 tpr0;
   kal_int16 tpr1;
   kal_int16 tpr2;
}ERF_RXON_BPIOFFSET_T;

typedef struct
{
   kal_int16 fpt0;
   kal_int16 fpt1;
   kal_int16 fpt2;
   kal_int16 fpr3b;
   kal_int16 tpt0;
   kal_int16 tpt1;
   kal_int16 tpt2;
   kal_int16 tpr3b;
}ERF_TXON_BPIOFFSET_T;

typedef struct
{
   kal_int16 fpr3;
   kal_int16 tpr3;
   kal_int16 fpr3c;
   kal_int16 tpr3c;
}ERF_RXOFF_BPIOFFSET_T;

typedef struct
{
   kal_int16 fpt3;
   kal_int16 tpt3;
}ERF_TXOFF_BPIOFFSET_T;

typedef struct
{
   PDATA_SET_T pr0;
   PDATA_SET_T pr1;
   PDATA_SET_T pr2;
   PDATA_SET_T pr3;
   PDATA_SET_T pr3b;
   PDATA_SET_T pr3c;
   PDATA_SET_T pt0;
   PDATA_SET_T pt1;
   PDATA_SET_T pt2;
   PDATA_SET_T pt3;
   kal_uint16  rxio;
   kal_uint16  txio;
}ERF_SPLIT_RFDATA_T;

typedef struct
{
   LTE_Band bandIdx;
   ERF_RX_PDATA_T RxPdata;
}ERF_RX_PDATABASE_T;

typedef struct
{
   LTE_Band bandIdx;
   ERF_TX_PDATA_T TxPdata;
}ERF_TX_PDATABASE_T;

typedef struct
{
   kal_uint16 Band;
   kal_uint16 SplitNum;
   kal_uint16 SplitBandEndDL[LTE_ERF_MAX_SPLIT_PART];
   kal_uint16 SplitBandEndUL[LTE_ERF_MAX_SPLIT_PART];
   kal_int16  PowerCompensation;
   kal_int16  CouplerCompensation;
}ERF_SPLIT_BAND_IND_T;

typedef struct
{
   LTE_Band bandIdx;
   ERF_SPLIT_RFDATA_T SplitRFdata;
}ERF_SPLIT_RFDATABASE_T;

typedef struct
{
   kal_uint16 TASEna;
   kal_uint16 TASWithTestSimEna;
   kal_uint16 TASMask_H;
   kal_uint16 TASMask_L;
   kal_uint16 TASInitAnt;
   kal_uint16 ForceAntEna;
   kal_uint16 ForceAntIndex;
   LTE_Band   TASBand[LTE_ERF_TAS_BAND_NUM];
}ERF_TAS_BAND_IND_T;

typedef struct
{
   PDATA_SET_T pdata_tas;
}ERF_TAS_RFDATA_T;

typedef struct
{
   ERF_TAS_BAND_IND_T TASBandInd;
   ERF_TAS_RFDATA_T   TASRfDatabase[LTE_ERF_TAS_TOTAL_NUM];
}EL1_TAS_PARAMETER;

typedef struct
{
   kal_int16 ENB_SM;                  //                               Enable of antenna-switch metric function
   kal_int16 N_MS_j_hys;              //                         MS,   Hysteresis duration control for leaving normal state
   kal_int16 N_MS_SM_fadeout;         //                         MS,   The timer duration for antenna-switching metric fadeout protection
   kal_int16 PHI_bound;               //                         dB,   Up/low bound for applying antenna-switching metric as threshold
   kal_int16 PHI_01_default;          //                         dB,   Antenna-switching metric default value from ant. 0 to ant. 1
   kal_int16 PHI_10_default;          //                         dB,   Antenna-switching metric default value from ant. 1 to ant. 0
   kal_int16 ENB_DB;                  //                               Enable of dynamic barrier control function
   kal_int16 DELTA_DB_fail_step_RSRP; //                         dB,   The increased amount for RSRP barrier for a fail pre-switch
   kal_int16 DELTA_DB_fail_step_TXP;  //                         dB,   The increased amount for TX power barrier for a fail pre-switch
   kal_int16 N_MS_DB_relax;           //                         MS,   The timer duration to relax the dynamic barrier
   kal_int16 DELTA_DB_TO_step;        //                         dB,   RSRP/TXP: The decreased barrier when per timer is reached
   kal_int16 DELTA_DB_bound_RSRP;     //                         dB,   The upper bound of the extra-threshold Delta_RSRP_DB
   kal_int16 DELTA_DB_bound_TXP;      //                         dB,   The upper bound of the extra-threshold Delta_TXP_DB

   //        Naming for customer,       Naming for MTK internal, Unit, Description
   kal_int16 RSRP_diff_thd;           //RSRP_diff_thd_PO,        dB,   RSRP difference threshold to trigger TAS, defined as the RSRP value difference from diversity to main antennas
   kal_int16 RSRP_diff_thd_TXP;
   kal_int16 RSRP_diff_thd_CB;
   kal_int16 RSRP_thd_connect_EN;     //                               RSRP_diff_thd_xxx are connected or not
   kal_int16 RSRP_cb_drop_thd;        //RSRP_CB_thd,             dB,   RSRP drop threshold to trigger TAS when check back, defined as the RSRP value difference from current value to its previous one
   kal_int16 TXP_cb_inc_thd;          //TXP_CB_thd,              dB,   Transmit power (TXP) increase threshold to trigger TAS when check back, defined as the TXP value difference from current value to its previous one
   kal_int16 nMS_cb;                  //N_MS_CB,                 MS,   The look/check back period (for RSRP and TXP change monitoring), using measurement slot (MS) as the unit
   kal_int16 HTP_level;               //M_THP,                   dB,   The high transmit power (HTP) level, defined as the ratio (in dB) to UE's maximum transmit power
   kal_int16 HTP_ratio_thd;           //HTP_thd,                 %,    A HTP is recognized when the percentage using TXP (within a measurement slot) greater than HTP_level is higher than the ratio threshold
   kal_int16 TXP_inc_thd_sb;          //TPC_inc_thd1,            dB,   TXP increase threshold when switch to the diversity antenna, for which exceeding the threshold would be recognized as a fail antenna switch
   kal_int16 nMS_sb;                  //N_MS_SB,                 MS,   The monitoring duration for switch-back check, using measurement slot (MS) as the unit
}EL1_TAS_OTHER;

typedef struct
{
   LTE_Band bandIdx;
   kal_uint8 rxio;
   kal_uint8 rxdio;
   kal_uint8 txio;
}ERF_IOBASE_T;

/* Single ANT Feature */
typedef struct
{
   kal_uint8 rf_rx_path0_en;
   kal_uint8 rf_rx_path1_en;
}ERf_RX_PATH_CONFIG_T;

//MIPI PA data structure through meta 
typedef struct //MIPI table
{
   kal_uint32 pa_data[LTE_MIPI_TPC_SECTION_NUM][LTE_MIPI_TPC_SECTION_DATA_NUM];
}ERfTestCmdMipiPaData;

#if IS_4G_TX_POWER_OFFSET_SUPPORT
typedef struct
{
   kal_uint16  TPO_enable;          /* Enable Tx power offset */
   kal_uint16  TPO_meta_enable;     /* The main purpose of "meta_tx_power_offset_enable" is to disable power offset during calibration */
   kal_uint32  TPO_table_on_mask;   /* Turn on offset table. ex:set bit0=1 to apply offset in table 0  */
   kal_uint32  TPO_bit_number_for_4G_table[TPO_4G_TABLE_NUM];
}ERf_POWER_OFFSET_SETTING;

/* LTE RF parameter for custom*/
typedef struct
{
   ERf_POWER_OFFSET_SETTING   tx_power_offset_setting;
}ERf_TPO_SETTING;

typedef struct 
{
   kal_int16  subband_power_offset_dB[CAL_EARFCN_SECTION_LTE];  /* unit for custom to input: 1/8 dB -> value '8' = 1 dB */ 
}ERf_TXPOWEROFFSETTABLE;

typedef struct 
{
   LTE_Band	 band_ind;
   ERf_TXPOWEROFFSETTABLE  table[TPO_4G_TABLE_NUM];
}ERf_TXPOWEROFFSETDATA;
#endif /* IS_4G_TX_POWER_OFFSET_SUPPORT */

/*******************************************************************************
** Global data for RF customization and META Factory Calibration
*******************************************************************************/
extern LTE_sRAMPDATA LTE_BandNone_RampData;
extern LTE_sRAMPDATA LTE_Band1_RampData;
extern LTE_sRAMPDATA LTE_Band2_RampData;
extern LTE_sRAMPDATA LTE_Band3_RampData;
extern LTE_sRAMPDATA LTE_Band4_RampData;
extern LTE_sRAMPDATA LTE_Band5_RampData;
extern LTE_sRAMPDATA LTE_Band6_RampData;
extern LTE_sRAMPDATA LTE_Band7_RampData;
extern LTE_sRAMPDATA LTE_Band8_RampData;
extern LTE_sRAMPDATA LTE_Band9_RampData;
extern LTE_sRAMPDATA LTE_Band11_RampData;
extern LTE_sRAMPDATA LTE_Band12_RampData;
extern LTE_sRAMPDATA LTE_Band13_RampData;
extern LTE_sRAMPDATA LTE_Band14_RampData;
extern LTE_sRAMPDATA LTE_Band17_RampData;
extern LTE_sRAMPDATA LTE_Band18_RampData;
extern LTE_sRAMPDATA LTE_Band19_RampData;
extern LTE_sRAMPDATA LTE_Band20_RampData;
extern LTE_sRAMPDATA LTE_Band21_RampData;
extern LTE_sRAMPDATA LTE_Band26_RampData;
extern LTE_sRAMPDATA LTE_Band28_RampData;
extern LTE_sRAMPDATA LTE_Band34_RampData;
extern LTE_sRAMPDATA LTE_Band38_RampData;
extern LTE_sRAMPDATA LTE_Band39_RampData;
extern LTE_sRAMPDATA LTE_Band40_RampData;
extern LTE_sRAMPDATA LTE_Band41_RampData;

extern LTE_sPAOCTLVLSETTING LTE_BandNone_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band1_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band2_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band3_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band4_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band5_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band6_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band7_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band8_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band9_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band11_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band12_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band13_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band14_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band17_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band18_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band19_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band20_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band21_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band26_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band28_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band34_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band38_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band39_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band40_PaOctLevData;
extern LTE_sPAOCTLVLSETTING LTE_Band41_PaOctLevData;

extern LTE_RSSIBandGainTable LTE_BandNone_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band1_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band2_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band3_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band4_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band5_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band6_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band7_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band8_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band9_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band11_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band12_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band13_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band14_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band17_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band18_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band19_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band20_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band21_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band26_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band28_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band34_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band38_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band39_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band40_RSSIGainTbl;
extern LTE_RSSIBandGainTable LTE_Band41_RSSIGainTbl;

extern LTE_FreqAdjustTable FreqAdjustTbl;

extern LTE_Band lteBandIndArray[];
extern LTE_sPAOCTLVLSETTING*   LTE_PaOctLevTable[];
extern LTE_sRAMPDATA*          LTE_RampData[];
extern LTE_RSSIBandGainTable*  LTE_RSSIGainTbl[];
extern LTE_FreqAdjustTable*    LTE_FreqAdjustTbl[];
//extern kal_uint16 LTE_TEMP_DAC[CAL_TEMP_SECTION_LTE];
extern LTE_TemperatureDac_T* LTE_TEMP_DAC;

extern kal_uint8 num_pa_mode;
extern kal_uint8 num_hysteresis;

extern RfcDramAddrInd g_rfc_EtVinLutAddr[LTE_TARGET_MAX_SUPPORT_BAND_NUM];
extern LTE_RfcEtVinLutPerBand_T* LTE_EtVinLutTbl[LTE_AUGMENTED_BAND_ARRAY_NUM];
extern RfcDramAddrInd g_rfc_EtCompParamAddr;
extern LTE_RfcEtCompParam_T* LTE_EtCompParamTbl;
extern LTE_RfcEtVinLutPerBand_T LTE_BandNone_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band1_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band2_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band3_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band4_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band5_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band6_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band7_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band8_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band9_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band11_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band12_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band13_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band14_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band17_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band18_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band19_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band20_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band21_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band26_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band28_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band34_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band38_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band39_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band40_EtVinLutData;
extern LTE_RfcEtVinLutPerBand_T LTE_Band41_EtVinLutData;
extern LTE_RfcEtCompParam_T LTE_EtCompParam;

extern LTE_Band lteBandIndArray[LTE_AUGMENTED_BAND_ARRAY_NUM];
extern ERF_RX_PDATABASE_T ERF_RX_PDATABASE[LTE_TARGET_MAX_SUPPORT_BAND_NUM];
extern ERF_TX_PDATABASE_T ERF_TX_PDATABASE[LTE_TARGET_MAX_SUPPORT_BAND_NUM];
extern ERF_RXON_BPIOFFSET_T ERF_RXON_BPIOFFSET;
extern ERF_TXON_BPIOFFSET_T ERF_TXON_BPIOFFSET;
extern ERF_RXOFF_BPIOFFSET_T ERF_RXOFF_BPIOFFSET;
extern ERF_TXOFF_BPIOFFSET_T ERF_TXOFF_BPIOFFSET;
extern ERF_IOBASE_T ERF_RF_IOBASE[LTE_TARGET_MAX_SUPPORT_BAND_NUM];
extern LTE_MPRAdjust_T LTE_MPRAdjustTbl[LTE_TARGET_MAX_SUPPORT_BAND_NUM];
extern LTE_AMPRAdjust_T LTE_AMPRAdjustTbl[LTE_TARGET_MAX_SUPPORT_BAND_NUM];
extern kal_uint16 TPC_Compen_Err_UboundTbl[LTE_MAX_SUPPORT_BAND_NUM];
extern ERF_SPLIT_RFDATABASE_T ERF_SPLIT_RFDATABASE[LTE_ERF_SPLIT_NUM];
extern const LTE_MPRAdjust_T LTE_MPRAdjustTbl_All[];
extern const LTE_AMPRAdjust_T LTE_AMPRAdjustTbl_All[];

/*** MIPI BYPASS FEATURE ***/
extern kal_uint16 LTE_MIPI_BYPASS_FEATURE_ENABLE;
extern LTE_Band LTE_MIPI_BYPASS_BandIndArray[LTE_MIPI_BYPASS_MAX_SUPPORT_BAND_NUM];
extern kal_int16 LTE_MIPI_BYPASS_PowerCompArray[LTE_MIPI_BYPASS_MAX_SUPPORT_BAND_NUM];
extern kal_int16 LTE_MIPI_BYPASS_CouplerCompArray[LTE_MIPI_BYPASS_MAX_SUPPORT_BAND_NUM];
extern LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_BYPASS_TX_EVENT_TABLE[];
extern LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_BYPASS_TPC_EVENT_TABLE[];
extern LTE_MIPI_TPC_SECTION_TABLE_T*  LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA[];

//MIPI ENABLE
extern kal_uint16 LTE_MIPI_ENABLE;
extern LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_RX_EVENT_TABLE[];
extern LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_TX_EVENT_TABLE[];
extern LTE_MIPI_EVENT_TABLE_T*  LTE_MIPI_TPC_EVENT_TABLE[];
extern LTE_MIPI_TPC_SECTION_TABLE_T*  LTE_MIPI_PA_TPC_SECTION_DATA[];
extern LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_RX_DATA_TABLE[];
extern LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_TX_DATA_TABLE[];
extern LTE_MIPI_DATA_SUBBAND_TABLE_T*  LTE_MIPI_BYPASS_TX_DATA_TABLE[];

extern kal_uint32  LTE_MIPI_RX_EVENT_SIZE_TABLE[];
extern kal_uint32  LTE_MIPI_TX_EVENT_SIZE_TABLE[];
extern kal_uint32  LTE_MIPI_TPC_EVENT_SIZE_TABLE[];
extern kal_uint32  LTE_MIPI_PA_TPC_SECTION_DATA_SIZE[];
extern kal_uint32  LTE_MIPI_RX_DATA_SIZE_TABLE[];
extern kal_uint32  LTE_MIPI_TX_DATA_SIZE_TABLE[];
extern kal_uint32  LTE_MIPI_BYPASS_TX_DATA_SIZE_TABLE[];
extern kal_uint32  LTE_MIPI_BYPASS_TX_EVENT_SIZE_TABLE[];
extern kal_uint32  LTE_MIPI_BYPASS_TPC_EVENT_SIZE_TABLE[];
extern kal_uint32  LTE_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE[];

//DRDI Enable
extern kal_uint16 LTE_DRDI_STATUS;

//Single ANT Feature
extern ERf_RX_PATH_CONFIG_T LTE_RF_RX_PATH_CONFIG_DEFAULT;

//Transmint Antenna Selection Feature
extern EL1_TAS_PARAMETER EL1_TAS_PARAMETER_TABLE;
extern EL1_TAS_OTHER     EL1_TAS_OTHER_TABLE;

#if IS_4G_TX_POWER_OFFSET_SUPPORT
/* TX power offset feature */
extern ERf_TPO_SETTING LTE_TPO_CUSTOM_INPUT_DATA;
extern ERf_TXPOWEROFFSETDATA* LTE_TX_POWER_OFFSET_TABLE[];
extern kal_uint32 LTE_TX_POWER_OFFSET_SIZE_TABLE[];
#endif

void ephy_chk_pwron_cal_data();
#endif /* End of #ifndef EL1_RF_PUBLIC_H */

