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
 *   ft_msg_ul1rf.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Messages definition of UL1 RF category of FT Library
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

#ifndef __FT_MSG_UL1RF_H__
#define __FT_MSG_UL1RF_H__
#include "ft_msg_common.h"

/*******************************************************************************
*
*  Message structures defined for UL1 TST Interface
*
*******************************************************************************/
#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)

//type1: communicate with ul1tst module, and send the confirm without waiting!
//type2: communicate with u1ltst module, and wait their confirm, then send back to PC
//type3: invoke UL1D's API, then send confirm to PC side.
//type4: no operation, only get FT task's current status, and reply to PC side

typedef enum
{
    URF_TEST_CMD_TXACCESS = 0,
    URF_TEST_CMD_STOP = 1,
    URF_TEST_CMD_TX_DPCH = 2,
    URF_TEST_CMD_RX_DPCH = 3,
    URF_TEST_CMD_RSSI = 4,
    URF_TEST_CMD_RSCP = 5,
    URF_TEST_CMD_AFC = 6,
    URF_TEST_CMD_TX_PAAPC = 7,
    URF_TEST_CMD_GET_RFID = 8,
    URF_TEST_CMD_CONFIG_HWTPC = 9,
    URF_TEST_CMD_GET_PWR_DT_STEP = 10,
    URF_TEST_CMD_GET_PWR_DT_DAC = 11,
    URF_TEST_CMD_GET_PWR_DT_DEFAULT_THR = 12,
    URF_TEST_CMD_SET_IMMEDIATE_BSI = 13,
    URF_TEST_CMD_GET_IMMEDIATE_BSI = 14,
    URF_TEST_CMD_CONTINUOUS_RX = 15,
    URF_TEST_CMD_START_FHC = 16,
    URF_TEST_CMD_SET_TXDAC_DATA = 17,
    URF_TEST_CMD_GET_PWR_DET_MEASURE_RES = 18,
    URF_TEST_CMD_SET_PWR_CTRL_MODE = 19,
    URF_TEST_CMD_REPLACE_GAIN_TABLE_FOR_CAL = 20,
    URF_TEST_CMD_START_FHC_NO_WAIT = 21,
    URF_TEST_CMD_GET_FHC_RESULT = 22,
    URF_TEST_CMD_QUERY_TARGET_CAPABILITY = 23,
    URF_TEST_CMD_START_NSFT = 24,
    URF_TEST_CMD_GET_BIT_COUNT_FOR_SINGLE_ENDED_BER = 25,
    URF_TEST_CMD_NSFT_SET_ILPC_STEP = 26,
    URF_TEST_CMD_START_NSFT_EX = 27,
    URF_TEST_CMD_SET_PA_OCT_LEVEL_DATA = 28,
    URF_TEST_CMD_START_HSDPA_NSFT = 29,
    URF_TEST_CMD_START_HSUPA_NSFT = 30,
    URF_TEST_CMD_START_FHC_EX = 31,
    URF_TEST_CMD_GET_FHC_EX_RESULT = 32,
    URF_TEST_CMD_GET_CURRENT_LNA_MODE = 33,
    URF_TEST_CMD_SET_CAPID = 34,
    URF_TEST_CMD_GET_MAX_CAPID = 35,
    URF_TEST_CMD_AFC_EX = 36,
    URF_TEST_CMD_RSSI_RXD = 37,
    URF_TEST_CMD_GET_CURRENT_RXD_LNA_MODE = 38,
    URF_TEST_CMD_SET_RX_BANDWIDTH = 39,
    URF_TEST_CMD_SET_RX_ANTENNA = 40,
    URF_TEST_CMD_SET_TX_PA_DRIFT_COMPENSATION = 41,
    URF_TEST_CMD_SET_ICS_CELL_POWER = 42,
    URF_TEST_CMD_GET_RF_TEMP_BSI = 43,
    URF_TEST_CMD_GET_RF_CAPABILITY = 44,
    URF_TEST_CMD_START_NSFT_LIST_MODE  = 45,
    URF_TEST_CMD_SET_RF_MIPI_CODEWORD = 46,
    URF_TEST_CMD_GET_RF_MIPI_CODEWORD = 47,
    URF_TEST_CMD_GET_TEMPERATURE_INFO = 48,
    URF_TEST_CMD_RX_GAIN_SWEEP = 49,
    URF_TEST_CMD_END
} URfTestCmdType;
typedef struct
{
    kal_uint16  ul_uarfcn;      /* UL uarfcn range:????Read from NVRAM?? (9612 ~ 9888) */
    kal_uint16  dl_psc;         /* 0~511. */
    kal_uint16  signature;      /* 0~15, for single signature decision. */
    kal_uint8   pa_mode;        /* 0: High 1: Middle 2: Low */
    kal_int8    init_power;     /* Assume cpich_rscp=0, ul_interference=0. */
    kal_uint8   power_step;     /* Preamble power ramping step. 1 ~ 8dB */
    kal_uint8   max_retrans;    /* 1~64. */
    kal_uint16  dl_uarfcn;
    kal_uint8   asc;
} URfTestCmdTxAccess;
typedef struct
{
    kal_uint16  ul_freq;
    kal_int16   psc;        /* 0~511. */
    kal_uint32  sc_code;    /* Scrambling code #. 0 ~ 16777215 */
    kal_uint8   power_ctrl_mode;
    kal_uint8   pa_mode;
    kal_uint16  idx;
    kal_uint16  afc_dac;
    kal_uint8   dpcch_pwr;
    kal_uint8   dpdch_pwr;

    /* Below for UL1D_RF_Meta_SetTxInfo. */
    kal_bool    no_loop_ctrl;

    /* Below for setPaApcDac. */
    kal_uint8   rf_band;
    kal_uint8   vm1;
    kal_uint8   vm2;
    kal_uint16  dc2dc_dac;
    kal_uint16  vbias_dac;
    kal_bool    pwr_det;
    kal_uint16  apc_dac;
    kal_bool    pa_octlev_ctrl_used;
} URfTestCmdTxDPCh;

typedef struct
{
    kal_uint16  dl_freq;
    kal_int16   psc;        /* 0~511. */
    kal_uint8   ssc;        /* 0~15. */
    kal_int16   ovsf;       /* 0~sf-1. */
    kal_uint16  afc_dac;

    /* Below for RF_SetBBRxParams. */
    kal_bool    hwAGC;
    kal_uint8   mode;       /* 0: mode0, 1: mode1. */
    kal_int16   gain;       /* mode0. */
    kal_uint8   LNAmode;    /* mode1. 0: LNA low, 1: LNA mid, 2: LNA high. */
    kal_uint16  pga;        /* mode1. */
} URfTestCmdRxDPCh;
#define MAX_FREQ_LIST 36
typedef struct
{
    kal_uint8   num_freq;
    kal_uint16  dl_freq[ MAX_FREQ_LIST ];
    kal_uint8   temperature;

    /* Below for RF_SetBBRxParams. */
    kal_bool    hwAGC;
    kal_uint8   mode;       /* 0: mode0, 1: mode1. */
    kal_int16   gain;       /* mode0. */
    kal_uint8   LNAmode;    /* mode1. 0: LNA low, 1: LNA mid, 2: LNA high. */
    kal_uint16  pga;        /* mode1. */
} URfTestCmdRSSI;

typedef struct
{
    kal_uint8   num_freq;
    kal_uint16  dl_freq[ MAX_FREQ_LIST ];
    kal_uint8   temperature;

    /* Below for RF_SetBBRxParams. */
    kal_bool    hwAGC;
    kal_uint8   mode;       /* 0: mode0, 1: mode1. */
    kal_int16   gain;       /* mode0. */
    kal_uint8   LNAmode;    /* mode1. 0: LNA low, 1: LNA mid, 2: LNA high. */
    kal_uint16  pga;        /* mode1. */
} URfTestCmdRxGainSweep;

typedef struct
{
    kal_bool    pscan_before_cell_search;   /* True if UL1TST needs power scan before cell search/RSCP. */
    kal_uint16  dl_freq;    /* Specific dl_freq to do cell search. Valid if pscan_before_cell_search=F. */
    kal_uint8   sample_num_per_cell;
    kal_bool    read_sfn;   /* True if we need to do SFN measurement for the found cell. */

    /* Below for RF_SetBBRxParams. */
    kal_bool    hwAGC;
    kal_uint8   mode;       /* 0: mode0, 1: mode1. */
    kal_int16   gain;       /* mode0. */
    kal_uint8   LNAmode;    /* mode1. 0: LNA low, 1: LNA mid, 2: LNA high. */
    kal_uint16  pga;        /* mode1. */
} URfTestCmdRSCP;

typedef struct
{
    kal_int16    dl_freq;     /* Specific dl_freq to do cell search. Valid if pscan_before_cell_search=F. */
    kal_int16    afc_dac;
    /* Below for RF_SetBBRxParams. */
    kal_bool     hwAGC;
    kal_uint8    mode;        /* 0: mode0, 1: mode1. */
    kal_int16    gain;        /* mode0. */
    kal_uint8    LNAmode;     /* mode1. 0: LNA low, 1: LNA mid, 2: LNA high. */
    kal_uint16   pga;         /* mode1. */
} URfTestCmdAFC;

typedef struct
{
    kal_int8     m_cRfBand;
    kal_uint16   m_u2Idx;
    kal_uint8    m_ucPaMode;
    kal_uint8    m_ucVm1;
    kal_uint8    m_ucVm2;
    kal_uint16   m_u2DC2DC_Dac;
    kal_uint16   m_u2Vbias_Dac;
    kal_uint16   m_u2ApcDac;

}UL1D_RF_TX_PA_APC_REQ_T;

typedef struct
{
    //should be exactly the same as META_HWTPC_FRAME_INFO in ul1d_rf_general.h
    kal_uint8 tpc_step;
    kal_uint8 itp;
    kal_uint8 rpp;
    kal_uint8 fmt_idx;
    kal_uint8 dl_frame_type;
    kal_uint16 slot_mask;
    kal_int8   tpc_cmd[15];
    kal_uint8  beta_c;
    kal_uint8  beta_d;

}UL1D_RF_HWTPC_FRAME_INFO;
typedef struct
{
    kal_uint8 pc_algo;
    kal_uint8 tpc_used_frame; // specify the frame number
    kal_int16 p_ini;

    UL1D_RF_HWTPC_FRAME_INFO frame_info[8];

}UL1D_RF_HWTPC_CONFIG_REQ_T;

typedef struct
{
    kal_uint8 rf_band;

}UL1D_RF_GET_PWR_THR_REQ_T;

typedef struct
{
    kal_bool      no_loop_ctrl;
    kal_uint16    afc_dac;
    kal_bool      pwr_det;
    kal_uint8     power_ctrl_mode;
    kal_uint8     vm1[10][3];
    kal_uint8     vm2[10][3];
    kal_uint16    dc2dc_dac[10][3];
    kal_uint16    vbias_dac[10][3];
    kal_bool      init_tx_onoff;
    kal_bool      ready_tx_onoff;
    kal_uint8     init_pa_mode;
    kal_uint8     ready_pa_mode;
    kal_uint16    init_pa_gain;
    kal_uint16    ready_pa_gain;
    kal_uint16    init_vga_dac_tpc_idx;
    kal_uint16    ready_vga_dac_tpc_idx;
    kal_uint8     temperature;
    kal_bool      hwAGC;
    kal_int16     gain_init;
    kal_bool      init_condition;
    kal_uint8     step_duration;
    kal_uint8     ready_duration;
    kal_uint8     retune_duration;
    kal_uint8     gain_stable_time;
    kal_uint16    max_vga_dac;
    kal_uint16    min_vga_dac;
    kal_uint16    jump_vga_dac;
    kal_uint8     freq_count;
    kal_uint8     pwr_count;
    kal_uint8     freq_start_idx;
    kal_uint8     pwr_start_idx;
    kal_uint8     odd_record;
    kal_uint8     pa_gain_start_idx;
    kal_uint8     pd_gain_start_idx;
    kal_uint8     dl_band[40];
    kal_uint8     ul_band[40];
    kal_uint16    dl_freq[40];
    kal_uint16    ul_freq[40];
    kal_uint8     pa_mode[40];
    kal_uint16    vga_dac_tpc_idx[40];
    kal_uint16    pa_gain[40];
    kal_uint8     pd_gain[40];
}UL1D_RF_FHC_REQ_T;

typedef struct
{
    kal_bool      no_loop_ctrl;
    kal_uint16    afc_dac;
    kal_bool      pwr_det;
    kal_uint8     power_ctrl_mode;
    kal_uint8     vm1[10][3];
    kal_uint8     vm2[10][3];
    kal_uint16    dc2dc_dac[10][3];
    kal_uint16    vbias_dac[10][3];
    kal_bool      init_tx_onoff;
    kal_bool      ready_tx_onoff;
    kal_uint8     init_pa_mode;
    kal_uint8     ready_pa_mode;
    kal_uint16    init_pa_gain;
    kal_uint16    ready_pa_gain;
    kal_uint16    init_vga_dac_tpc_idx;
    kal_uint16    ready_vga_dac_tpc_idx;
    kal_uint8     temperature;
    kal_bool      hwAGC;
    kal_int16     gain_init;
    kal_bool      init_condition;
    kal_uint8     step_duration;
    kal_uint8     ready_duration;
    kal_uint8     retune_duration;
    kal_uint8     gain_stable_time;
    kal_uint16    max_vga_dac;
    kal_uint16    min_vga_dac;
    kal_uint16    jump_vga_dac;
    kal_uint8     freq_count;
    kal_uint8     pwr_count;
    kal_uint8     freq_start_idx;
    kal_uint8     pwr_start_idx;
    kal_uint8     odd_record;
    kal_uint8     pa_gain_start_idx;
    kal_uint8     pd_gain_start_idx;
    kal_uint8     dl_band[40];
    kal_uint8     ul_band[40];
    kal_uint16    dl_freq[40];
    kal_uint16    ul_freq[40];
    kal_uint8     pa_mode[40];
    kal_uint16    vga_dac_tpc_idx[40];
    kal_uint16    pa_gain[40];
    kal_uint8     pd_gain[40];
    kal_uint8     pa_section[40];
    kal_uint16    lna_gain[40];
}UL1D_RF_FHC_EX_REQ_T;

typedef struct
{
    kal_bool        ok;
    kal_uint8       freq_count;
    kal_uint8       pwr_count;
    kal_uint8       freq_start_idx;
    kal_uint8       pwr_start_idx;
    kal_int16       rssi[400];
    kal_uint16      pwr_det_value[40];
}UL1D_RF_FHC_CNF_T;

typedef struct
{
    kal_bool     ok;
    kal_uint8    freq_count;
    kal_uint8    pwr_count;
    kal_uint8    freq_start_idx;
    kal_uint8    pwr_start_idx;
    kal_uint8    rx_lna_mode[400];
    kal_int16    rssi[400];
    kal_uint16   pwr_det_value[40][3];
    /**V R8 new features */
    kal_int16    Gbb_Offset[400];   /**< \brief TX Gbb power compensation */
    kal_uint8    rxd_lna_mode[400]; /**< \brief Rx diversity path lna mode */
    kal_int16    rxd_rssi[400];     /**< \brief Rx diversity path RSSI */    
}UL1D_RF_FHC_EX_CNF_T;

typedef struct
{

   kal_bool      b_afc_dac_valid;
   kal_uint16    u2_afc_dac;
   kal_uint8     u1_loopbackType;
   kal_uint8     u1_frame_shift;
   kal_uint8     u1_rmc_type;
   kal_uint8     u1_ctfc[4];
   kal_uint8     u1_bit_pattern;

   kal_int16     i2_dl_freq;
   kal_int16     i2_dl_psc;
   kal_int16     i2_dl_ovsf;

   kal_int16     i2_ul_freq;
   kal_uint16    u2_ul_tfci;
   kal_uint32    u4_ul_sc_code;
   kal_bool      b_iq_pwr_valid;
   kal_uint8     u1_dpcch_pwr;
   kal_uint8     u1_dpdch_pwr;

}UL1D_RF_NSFT_REQ_T;
/**
 * NSFT List Mode command parameter
 */
typedef struct
{
   kal_bool   afc_dac_valid;
   kal_uint16	afc_dac;
   kal_uint8  loopbackType;
   kal_uint8  frame_shift;
   kal_uint8  rmc_type;
   kal_uint8  ctfc[4];
   kal_uint8  bit_pattern;
   /* DL parameters */
   kal_int16	dl_freq[50];
   kal_int16	dl_psc;
   kal_int16	dl_ovsf;
   /* UL parameters */
   kal_int16	ul_freq[50];
   kal_uint16	ul_tfci;
   kal_uint32	ul_sc_code;
   kal_bool   iq_pwr_valid;
   kal_uint8	dpcch_pwr;
   kal_uint8	dpdch_pwr;
   /* common parameters */
   kal_uint8	valid_freq;
   kal_uint16   test_item[50];
   /* the time settings, unit = frame */
   kal_uint16   full_test_time;
   kal_uint8    ready_time;
   kal_uint8	sync_time;
   kal_uint8	retrial;   
   kal_uint16	test_time;
   kal_uint16   rx_rssi_start_time[3];
   kal_uint8    rx_rssi_duration[3];
   kal_uint16   rx_ber_start_time;
   kal_uint8    rx_ber_duration;
   kal_uint16	ILPC_ABC_time;
   kal_uint16	ILPC_EF_time;
   kal_uint16	ILPC_GH_time;
   kal_uint16	transition_time;
} URfNsftListModeReq;
/**
 * HSPA command parameter
 */
typedef struct
{
   kal_bool      b_afc_dac_valid;
   kal_uint16    u2_afc_dac;
   kal_uint8     u1_loopbackType;
   kal_uint8     u1_frame_shift;
   kal_uint8     u1_rmc_type;
   kal_uint8     u1_ctfc[4];
   kal_uint8     u1_bit_pattern;

   kal_int16     i2_dl_freq;
   kal_int16     i2_dl_psc;
   kal_int16     i2_dl_ovsf;

   kal_int16     i2_ul_freq;
   kal_uint16    u2_ul_tfci;
   kal_uint32    u4_ul_sc_code;
   kal_bool      b_iq_pwr_valid;
   kal_uint8     u1_dpcch_pwr;
   kal_uint8     u1_dpdch_pwr;
   kal_uint8     subTest;
}URfTestCmdHspaNsft;

typedef struct
{
    kal_uint16 measure_count;
} URfTestCmdGetRfTempSensor;

typedef struct
{
    kal_bool    bDataValid;
    kal_uint32  u4TotalBits;
    kal_uint32  u4ErrorBits;
}UL1D_RF_NSFT_BET_BIT_CNT_FOR_BER_CNF_T;


typedef struct
{
    kal_bool    ok;
    kal_uint8   num_freq;
    kal_int16   dl_freq[ MAX_FREQ_LIST ];
    kal_int32   rssi[ MAX_FREQ_LIST ];
} URfTestResultRSSI;

// R8 both rx path RSSI result
typedef struct
{
	kal_bool	ok;
	kal_uint8	num_freq;
	kal_int16	dl_freq[ MAX_FREQ_LIST ];
	kal_int32	rssi[ MAX_FREQ_LIST ];	
	kal_int32	rssi_rxd[ MAX_FREQ_LIST ];	
} URfTestResultRSSIRxD;

typedef struct
{
    kal_bool    ok;
    kal_uint8   num_freq;
    kal_int16   dl_freq[ MAX_FREQ_LIST ];
    kal_int32   inband_pow[ MAX_FREQ_LIST ];
} URfTestResultRxGainSweep;

typedef struct
{
    kal_uint16  psc;        /* Primary scrambling code */
    kal_int32   tm;         /* Cell frame boundary offset to LST */
    kal_int16   off;        /* Cell frame number offset to LST */
    kal_bool    sttd;       /* True for STTD used. */
    kal_uint8   sample_num;
    kal_int16   rscp_sum;
    kal_int16   freq_error;
} URfTest_cpich_result_T;
#define MAX_NUM_MEAS_CELL 32
typedef struct
{
    kal_bool        ok;
    kal_uint8       num_cell;
    URfTest_cpich_result_T  cpich_result[ MAX_NUM_MEAS_CELL ];
} URfTestResultRSCP;

typedef struct
{
    kal_bool       ok;
    kal_uint16     psc;
    kal_int32      tm;
    kal_bool       sttd;
    kal_uint8      rscp_sum;
    kal_int16      freq_error;

}URfTestResultAFC;

typedef struct
{
    kal_bool       ok;
    kal_uint16     psc;
    kal_int32      tm;
    kal_bool       sttd;
    kal_uint8      rscp_sum;
    kal_int32      freq_error;
}URfTestResultAFC_Ex;

typedef struct
{
    kal_bool    ok;
    kal_uint32  ber;    /* Spec requirement=10^-3. We will count 10^5 frames(100 times spec requirement) for BER calculation. Only count for the only TRCh for DPDCh. */
} URfTestResultRxDPCh;

typedef struct
{
    kal_uint32 m_u4Rfid;
}URfTestResultRFID;

typedef struct
{
    kal_uint8 m_u1Result;

}URfTestResultPwrDtStep;

typedef struct
{
    kal_uint16 m_u2Result;

}URfTestResultPwrDtDac;

typedef struct
{
    kal_uint8 m_u1Result;

}URfTestResultPwrDtDefaultThr;

typedef struct
{
    kal_bool      ok;
    kal_int8      m_i1CurGainTableState;

}URfTestResultReplaceGainTable;

typedef struct
{
   kal_uint32      capability;
   kal_uint32      band_support;
   kal_uint32      rxd_band_support;   
   kal_uint32      padrift_band_support;
}FT_UMTS_MsCapabilityEx;

typedef struct
{
    kal_bool   ok;
    kal_uint8  link_status;
}FT_UMTS_NSFTLinkStatusReport;

typedef struct 
{
    kal_bool    ok;    /*<! ok indicator */
    kal_uint32  sum;   /*<! the sum of measure_count times of temp sensor result */
} URfTestResultGetRfTempSensor;

typedef struct
{
    kal_bool   ok;
    kal_uint8  link_status;
} URfNsftListModeCnf;

typedef struct
{
    kal_uint16 rf_band_idx;
    kal_uint16 power_level_num;
    kal_uint16 code_word_num;
} URfTestCmdSetMIPICodeWord;

typedef struct
{
    kal_uint8  status;
    kal_uint16 power_level_num;
    kal_uint16 code_word_num;
} URfTestResultGetMIPICodeWord;

typedef struct
{
    kal_int16 status;
    kal_int16 tadc_dac;
    kal_int16 temperature;
    kal_int16 temp_idx;
} URfTestResultRfTemperatureInfo;

typedef union
{
    kal_uint8                   m_u1RfBand;
    kal_uint8                   m_u1PwrCtrlMode;
    kal_uint8                   m_u1TableType;  // 1: special table for calibration, 2: normal table
    kal_uint8                   m_u1ILPCStep;
    kal_uint16                  m_u2TxPclIndex;
    kal_uint16                  rf_band_idx;
    /* PA drift compensation */
    kal_uint8                   is_PaDrift; /*R8< \brief the parameter to UL1 for PA drift compensation setting (1: turn on, 0: turn off) */
    /* R8 RF tool */
    kal_uint8                   is_5mhz;
    kal_uint8                   is_main;
    kal_uint32                  m_rBSIData;
    kal_uint32                  m_rBSIAddr;
    /* DCXO development */
    kal_uint32                  m_u4CapId;
    URfTestCmdAFC               afc;
    URfTestCmdRSCP              rscp;
    URfTestCmdTxDPCh            txdpch;
    URfTestCmdRxDPCh            rxdpch;
    URfTestCmdTxAccess          txaccess;
    URfTestCmdSetMIPICodeWord   set_mipi_cw_param;
    URfTestCmdGetRfTempSensor   rfTemperature;
    UL1D_RF_TX_PA_APC_REQ_T     m_rTxPaApc;
    UL1D_RF_GET_PWR_THR_REQ_T   m_rGetPwrThr;
    kal_int32                   m_i4IcsCellPower; /**< \brief pass cell power to UL1 to choose the best initial gain for ICS */
} URfTestCmdParam;

typedef union
{
    kal_bool                                 ok;
    kal_uint8                                currentLnaMode;
    kal_uint16                               m_u2PwrDetResult;
    kal_uint32                               bsi_data;
    kal_uint32                               m_u4MaxCapId;
    FT_UMTS_MsCapabilityEx                   m_rTargetCapability;
    FT_UMTS_NSFTLinkStatusReport             m_rNSFTLinkStatusReport;
    URfNsftListModeCnf                       m_rNSFTListModeLinkStatusReport;
    UL1D_RF_NSFT_BET_BIT_CNT_FOR_BER_CNF_T   m_rNSFTBERResult;
    URfTestResultAFC                         afc;
    URfTestResultRFID                        rfid;
    URfTestResultAFC_Ex                      afc_ex;
    URfTestResultRxDPCh                      rx_dpch;
    URfTestResultPwrDtDac                    pwr_dt_dac;
    URfTestResultPwrDtStep                   pwr_dt_step;
    URfTestResultGetRfTempSensor             rfTemperature;
    URfTestResultGetMIPICodeWord             get_mipi_cw_param;
    URfTestResultPwrDtDefaultThr             pwr_dt_default_thr;
    URfTestResultReplaceGainTable            replace_gain_table;
    URfTestResultRfTemperatureInfo           rfTemperatureInfo;    
} URfTestResultParam;

typedef struct
{
    FT_H               header;
    URfTestCmdType     type;
    URfTestCmdParam    param;
} ft_urf_test_req_T;

typedef struct
{
    FT_H               header;
    URfTestCmdType     type;
    URfTestResultParam param;
} ft_urf_test_cnf_T;

#endif  // #if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)

#endif // #ifndef __FT_MSG_UL1RF_H__
