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
 *   l1tst_public.h
 *
 * Project:
 * --------
 *   MTK6208
 *
 * Description:
 * ------------
 *   L1 test mode public interface
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "l1_types_public.h"
#include "l1_option.h"
#include "mph_types.h"
#include "kal_general_types.h"
#include "l1_kal.h"

#ifndef l1tst_public_h
#define l1tst_public_h
#define MS_CAPABILITY_GSM               0x00000001
#define MS_CAPABILITY_GPRS              0x00000002
#define MS_CAPABILITY_EDGE_RX           0x00000004
#define MS_CAPABILITY_EDGE_8PSK_TX      0x00000008
#define MS_CAPABILITY_8PM               0x00000010
#define MS_CAPABILITY_FHC               0x00000020
#define MS_CAPABILITY_LC                0x00000040
#define MS_CAPABILITY_NSFT              0x00000080
#define MS_CAPABILITY_TCVCXO            0x00000100
#define MS_CAPABILITY_TXPC_CL_GMSK      0x00000200
#define MS_CAPABILITY_TXPC_OL           0x00000400
#define MS_CAPABILITY_TXPC_CL_TEMP      0x00000800
#define MS_CAPABILITY_TXPC_CL_EPSK      0x00001000
#define MS_CAPABILITY_LNAMODE           0x00002000
#define MS_CAPABILITY_TXPC_AUX_TEMP_ADC 0x00004000
#define MS_CAPABILITY_TXPC_BSI_TEMP_ADC 0x00008000

#define MS_BAND_SUPPORT_GSM400          0x00000001
#define MS_BAND_SUPPORT_GSM850          0x00000002
#define MS_BAND_SUPPORT_GSM900          0x00000004
#define MS_BAND_SUPPORT_DCS1800         0x00000008
#define MS_BAND_SUPPORT_PCS1900         0x00000010

#if MD_DRV_IS_FHC_SUPPORT
#define FHC_PRE_CAPID_SEARCH_NUM        9
#define FHC_MAX_CAPID_SEARCH_NUM       (7 + FHC_PRE_CAPID_SEARCH_NUM)
#endif

#define CAL_RX_LNA_MODE_HIGH            0x0001
#define CAL_RX_LNA_MODE_MID             0x0002
#define CAL_RX_LNA_MODE_LOW             0x0004

#define CAL_TXPC_OL                     0x0001
#define CAL_TXPC_CL_GMSK                0x0002
#define CAL_TXPC_CL_EPSK                0x0004
#define CAL_TXPC_CL_TEMP                0x0008

typedef enum
{
   CONT_TX_ALL_ZEROS
  ,CONT_TX_ALL_ONES
  ,CONT_TX_ALTERNATE_BITS
  ,CONT_TX_PSEUDO_RANDOM
  ,CONT_TX_PATTERN_WITHOUT_TSC
} ContTxPattern;

typedef enum
{
   AB_TX_RANDOM_WITH_SYNC_SEQ
  ,NB_TX_ALL_ZEROS_WITHOUT_TSC
  ,NB_TX_ALL_ONES_WITHOUT_TSC
  ,NB_TX_ALTER_BITS_WITHOUT_TSC
  ,NB_TX_RANDOM_WITH_TSC
  ,NB_TX_PATTERN_WITHOUT_TSC
  ,NB_TX_FIXED_RANDOM_WITH_TSC
  ,NB_TX_FIXED_ALL_ZEROS_WITH_TSC
  ,NB_TX_FIXED_ALTER_BITS_WITH_TSC
  ,NB_TX_FIXED_ALL_ONES_WITH_TSC
  ,NB_TX_FIXED_OE_PATTERN_WITH_TSC
} APCTxPattern;

typedef enum
{
   AFC_2_SEC
  ,AFC_33_SEC
} AfcCalType;

typedef enum
{
   AFC_DAC_RANGE_1023
  ,AFC_DAC_RANGE_8191
} AfcCalDacRange;

typedef enum
{
   Band400  = 0x0
  ,Band850  = 0x1
  ,Band900  = 0x2
  ,Band1800 = 0x4
  ,Band1900 = 0x8 
} BandBitMap;

typedef struct
{
// bool              ok;
   uint32            capability;
   uint32            band_support;
} MsCapabilityEx;

// MS Capability
typedef  struct
{
   unsigned short    support_gsm        :1;
   unsigned short    support_gprs       :1;
   unsigned short    support_edge_rx    :1;
   unsigned short    support_epsk_tx    :1;
   unsigned short    support_8pm        :1;
   unsigned short    support_fhc        :1;
   unsigned short    support_nsft       :1;
   unsigned short    band_gsm400        :1;
   unsigned short    band_gsm850        :1;
   unsigned short    band_gsm900        :1;
   unsigned short    band_dcs1800       :1;
   unsigned short    band_pcs1900       :1;
   unsigned short    ps_epsk_tx_disable :1;   /* Set as bit-1 when __EPSK_TX_SW_SWITCH_OFF__ is defined. */
   unsigned short    reserved0          :3;
} MsCapability;

// Factory Mode Calibration Item
typedef  struct
{
   unsigned short    is_capable      :1;
   unsigned short    is_mandatory    :1;
   unsigned short    parameters      :14;
} FacModCalItm;

typedef struct
{
   FacModCalItm      cap_id;
   FacModCalItm      afc;
   FacModCalItm      rx_pathloss;
   FacModCalItm      tx_pcl;
   FacModCalItm      tx_subband;
   FacModCalItm      trx_offset;
   FacModCalItm      tx_iq;
   FacModCalItm      tx_fb_dac;
   FacModCalItm      tx_slope_skew;
   FacModCalItm      w_coef;
   FacModCalItm      txpc;
   FacModCalItm      temp_adc;
   FacModCalItm      remove_32k_xo;
   FacModCalItm      co_crystal;
   FacModCalItm      high_lna_sp;
   FacModCalItm      mid_lna_sp;
   FacModCalItm      low_lna_sp;
   FacModCalItm      bat_temp_comp;
   FacModCalItm      dts_gain_cmb;
   FacModCalItm      uts_band_cmb;
   FacModCalItm      co_temp_adc;
   FacModCalItm      adjustable_lna_mode_pathloss;
   FacModCalItm      gain_rf_cal;
   FacModCalItm      bypass_check_fixafc_nvram;
   FacModCalItm      multi_rat_tadc_bitmap;
   FacModCalItm      multi_rat_afc_bitmap;
   FacModCalItm      adjustable_lna_mode_pathloss_v2;   
   FacModCalItm      temperature_info;
   FacModCalItm      dt_coexistence_info;
} FacModCal;

typedef struct
{
   uint16            cap_itm_offset;
   uint16            fmc_itm_offset;
   MsCapability      cap_itm;
   FacModCal         fmc_itm;
} MsCapabilityExV2;

#if MD_DRV_IS_FHC_SUPPORT
typedef struct
{
   FrequencyBand     band;
   ARFCN             arfcn;
   int16             dac_value[33];
   Gain              gain;
   int16             repeat_cnt; // repetitive test counts (frames) for each AFC DAC value
   bool              capid_cal;  // capid calibration ctrl
   bool              linear_cal; // 33 stages calibration ctrl
   int32             capid_min;  // min value for capid range
   int32             capid_max;  // max value for capid range
} DSSAfc; 

typedef struct
{
   FrequencyBand     band;
   ARFCN             arfcn;
   Gain              gain[6];    // gain for rx slot 0/1/2/3/4/5
   int16             repeat_cnt; // repetitive test counts (frames) for each ARFCN value
} DSSPL; 

typedef struct
{
   bool              afc_cal;
   bool              pl_cal;
   int8              sync_sb_num;  // the SB frame numbers needed for sync process before path loss calibration
   int8              step_cnt;
   int16             power;        // the power level expected to measure from test set
   DSSAfc            AfcDSS;
   DSSPL             PathLossDSS[L1_MAX_DTS_STEP_CNT-2];
   int16             lpm_sb_num;   // the SB frame numbers for DCXO LPM calibration
} DTSParam;
/*
typedef struct
{
   AfcParams        *afc_params;
   Report           *report;
} DTSMParams;
*/
typedef struct
{
// DTSMParams        params;
   intx              path_loss_cnt;
   intx              freq_offset;
   intx              capid_freq_offset_min;
   intx              capid_freq_offset[FHC_MAX_CAPID_SEARCH_NUM];
   int32             capid_search_order[FHC_MAX_CAPID_SEARCH_NUM];
   int32             capid;
   int32             capid_high;
   int32             capid_low;   
   int32             capid_best;
   int16             afc_dac;
   int16             arfcn;
   int16             capid_cnt;
   int16             repeat_index;
   int8              state;
   int8              capid_index;
   int8              capid_okay_cnt;
   int8              afc_dac_index;
   int8              sb_okay_cnt;
   uint8             sb_fail_cnt;
   uint8             fb_fail_cnt;
   bool              pl_started;
   bool              rst_dts_idx_at_pl_cal_started;
   bool              pre_capid_cal_ok[FHC_PRE_CAPID_SEARCH_NUM];
} sDTSM;

typedef struct
{
   FrequencyBand     band;
   ARFCN             arfcn;
   int8              timeslot_per_frame;
   int8              apc_dac_pcl_sel;      // 2: gain step index, 1: apc_dac, 0: apc_pcl
   int16             apc_dac_pcl_value[4];
// uint8             pa_vbias_val;
   uint8             pa_vbias_val[4];
   uint8             is_low_pcl[4];
   CodingScheme      cs[4];
   int32             repeat_cnt;
   int16             afc_dac_value;
   int8              tsc;
   APCTxPattern      pattern;
   uint16            pattern_data;
} USSApc;

typedef struct
{
   int8              step_cnt;
   int16             high_apc_dcoffset[FrequencyBandCount];
   USSApc            ApcUSS[L1_MAX_UTS_STEP_CNT];   
} UTSParam;
#endif
/* Functions provided by l1tst_cfg.c */
void L1TST_Init(void);
void L1TST_Stop(void);
void L1TST_SelectFrequencyBand1900( bool selected );
void L1TST_SetBBTXCfg( const sBBTXCfg *param );
void L1TST_GetBBTXCfg( sBBTXCfg *param );
intx L1TST_GetBBTXVer(void);
int  L1TST_GetCrystalCapRange(void);
uint32 L1TST_GetBandSupport(void);
uint16 L1TST_Get_EPSK_TX_Support(void);
uint16 L1TST_Get_TCVCXO_Support(void);

void L1TST_RF_SetRampApcLevel( int rf_band, int power_level, int apc_dac );
bool L1TST_CheckAvailableBands( FrequencyBand band );
bool L1TST_CheckAvailableARFCNs( ARFCN arfcn );
void L1TST_MsCapability( MsCapabilityEx *msCapabilityEx );
void L1TST_MsCapabilityV2( MsCapabilityExV2 *ms_cap );
void L1TST_TXPC_CL_GetAllADC( void *buff, int8 is_EPSK );
void L1TST_TXPC_CL_GetAllTEMP( void *buff, int8 is_EPSK );
void L1TST_TXPC_CL_GetSubband( int rf_band, void *buff, int8 is_EPSK );
uint16 L1TST_TXPC_CL_GetOneADC( int rf_band, int power_level, int8 is_EPSK );
uint16 L1TST_TXPC_GetTemperature( void );
#if MD_DRV_IS_FHC_SUPPORT
void L1TST_StartDTSCal( DTSParam *dtsData );
void L1TST_StartUTSCal( UTSParam *utsData );
sDTSM* L1TST_FHCLog(void);
#endif

#if MD_DRV_IS_NSFT_SUPPORT
void L1TST_StartNSFTProc( FrequencyBand band, ARFCN BCh_arfcn, ARFCN TCh_arfcn, 
                          Gain BCh_gain, Gain TCh_gain, TSC tsc, TimeSlot TCh_slot, 
                          Power txPowerLev, bool IS_EPSK_TX, CodingScheme epsk_cs);
void L1TST_NSFTProc_ChangeChannel ( FrequencyBand band, ARFCN BCh_arfcn, ARFCN TCh_arfcn, 
                                    Gain BCh_gain, Gain TCh_gain, TSC tsc, TimeSlot TCh_slot, 
                                    Power txPowerLev, bool IS_EPSK_TX, CodingScheme epsk_cs);
void L1TST_NSFTProc_ChangePower( Power txPowerLev);
void L1TST_StopNSFTProc( void );
void L1TST_SetupSingleEndBERData( uint32 tst_cnt );
void L1TST_ReportSingleEndBERDone( uint32* seBER_SUM, uint32* curr_cnt );
void L1TST_SetupRXLEVData( void );
void L1TST_ReportRXLEV( uint16 *RXLEV );
void L1TST_ReportRXQual( uint16 BER_PERMILLAGE, uint8 *RXQual );
#endif

/* Functions provided by l1tst_pm.c */
void L1TST_PowerScan(ARFCN arfcn, int8 sampleNoPerFrame, Gain gain, int16 frames);
#if MD_DRV_IS_W_CANCELLATION_SUPPORT
void L1TST_IR_PowerScan( ARFCN  arfcn, int8 sampleNoPerFrame, Gain gain, int16 frames, int8 if_flag );
#endif

/* Functions provided by l1tst_fcb.c */
void L1TST_FCBControl(ARFCN arfcn, int16 dacValue, Gain gain);
intx L1TST_FCBGetFreqOffset(void);

/* Functions provided by l1tst_nbtx.c */
void L1TST_NormalBurstTx(ARFCN  arfcn, BSIC bsic, int8 bitmask,
                         Power txPowerLev, int16 frames, int16 dacValue, APCTxPattern pattern);

/* Functions provided by l1tst_cont.c */
void L1TST_ContinuousTx(ARFCN arfcn, ContTxPattern pattern,uint16 patternData, bool onOff, uint16 modtype, Power PowerLev);
void L1TST_ContinuousRx(ARFCN arfcn, Gain gain, bool onOff);

/* Functions provided by l1tst_pdtch.c */
#if (MD_DRV_IS_GPRS || MD_DRV_IS_MULTISLOT_TX_SUPPORT)
void L1TST_MultiSlotTx( ARFCN  arfcn, BSIC bsic, int8 timeSlotmask, Power powerLev[4],
                        CodingScheme cs[4], TimingAdvance ta, int32 frames, int16 dacValue,
                        bool isEgprs, APCTxPattern pattern, uint16 patternData );
#endif

#if MD_DRV_IS_TX_GAIN_RF_CALIBRATION_SUPPORT
void L1TST_TxGainRFSetting(ARFCN  arfcn, BSIC bsic, CodingScheme cs, TimingAdvance ta, 
                           int32 frames, int16 dacValue, bool isEgprs, APCTxPattern pattern, 
                           uint16 patternData,  uint16 paGain, uint16 paVbias, uint16 rfGainIndex );
uint8 L1TST_Query_Grf_Number( void );
int16* L1TST_Query_Baseband_Power( void );
#endif

/* Functions provided by l1tst_afc.c */
void L1TST_SetAfcDacValue( int16 dacValue );
uint16 L1TST_GetAfcDacValueAtTRXOffsetCalibration(void);
void L1TST_SetAFcData( int16 calibrated_dac_default, intx calibrated_int_slope );
void L1TST_SetDcxoPowerMode(kal_uint8 mode);

#if MD_DRV_IS_EPSK_TX_SUPPORT
void L1TST_RF_SetRampApcLevelEPSK( int rf_band, int power_level, int apc_dac );
#endif

typedef void (*CalibraHandlerCallback)(kal_int32 u4Result);
bool L1TST_Begin32KCalibration( CalibraHandlerCallback cb );
void L1TST_Get32KCalibrationResult( kal_uint32 fmResult );

void L1TST_UpdateCalibrationData( kal_uint32 cal_lid );
uint16 L1TST_Query_L1D_Mode( void );

#endif
