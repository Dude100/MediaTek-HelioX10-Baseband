/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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


/*****************************************************************************
 *
 * Filename:
 * ---------
 * ul1tst_msg.h
 *
 * Project:
 * --------
 *   MT6268 Project
 *
 * Description:
 * ------------
 *   ul1tst_msg.h
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef UL1TST_MSG_H
#define UL1TST_MSG_H

/*===============================================================================*/

#include "kal_general_types.h"
#include "nvram_data_items.h"

/*===============================================================================*/

//#ifdef MT6268T
typedef enum
{
   UL1TST_CMD_TXACCESS = 0   
   ,UL1TST_CMD_TX_DPCH
   ,UL1TST_CMD_RX_DPCH
   ,UL1TST_CMD_RSSI
   ,UL1TST_CMD_RSSI_RXD  /**< \breif R8 get both rx path RSSI */
   ,UL1TST_CMD_RSSI_CONT
   ,UL1TST_CMD_RSCP
   ,UL1TST_CMD_AFC      //anthony 0514
   ,UL1TST_CMD_MQC      //20081114 congo, add msg for mobile quick caliration
   ,UL1TST_CMD_NSFT 
   ,UL1TST_CMD_HSDPA_NSFT
   ,UL1TST_CMD_HSUPA_NSFT
   ,UL1TST_CMD_STOP 
   ,UL1TST_CMD_MQC_OCTLEV
   ,UL1TST_CMD_MQC_EXT  //rxd, gvgabb0
   ,UL1TST_CMD_AFC_EXT  //Add msg for DCXO to do multi-bin detection (ics_mode=CFE_MODE1)
   ,UL1TST_CMD_Reload_NVRAM
   ,UL1TST_CMD_ANT_MODE     /**< \brief R8 set rx path: 0:none 1:main 2:diversity: 3: both */
   ,UL1TST_CMD_PA_DRIFT_SWITCH  // PA drift compensation switch message
   ,UL1TST_CMD_RX_CELL_POWER    // configure the Rx cell power before cell search
   ,UL1TST_CMD_GET_RF_TEMP /*20*/      // Get the RF Temperature sensor reading (parameter:UL1TSTCmdGetRfTempSensor)
   ,UL1TST_CMD_GET_RF_CAPABILITY /*21*/  // Get the RF capability (no parameter)
   ,UL1TST_CMD_GET_MIPI_PA_CW_NUMBER /*22*/   
   ,UL1TST_CMD_LIST_MODE	//for list mode
   ,UL1TST_CMD_GET_RF_MIPI_CODEWORD /*24*/
   ,UL1TST_CMD_SET_RF_MIPI_CODEWORD /*25*/
   ,UL1TST_CMD_GET_RF_TEMP_INFO /*26*/
   ,UL1TST_CMD_RX_GAIN_SWEEP /* 27 */
   ,UL1TST_CMD_END
} UL1TSTCmdType;

typedef struct
{
    kal_uint16	 ul_uarfcn;		/* UL uarfcn range:????Read from NVRAM?? (9612 ~ 9888) */	
    kal_uint16  dl_uarfcn;
    kal_uint16	 dl_psc;		   /* 0~511. */
    kal_uint8   signature;	   /* 0~15, for single signature decision. */
    kal_uint8   pa_mode;	   /* 0: high 1: middle 2: low */
    kal_int8    init_power;	/* Assume cpich_rscp=0, ul_interference=0. */
    kal_uint8   power_step;   /* Preamble power ramping step. 1 ~ 8dB */	
    kal_uint8   max_retrans;	/* 1~64 */
    kal_uint8   asc;          /* 0~7 */
} UL1TSTCmdTxAccess;

typedef struct
{
   //kal_int16	dl_freq;
   kal_int16	ul_freq;
   kal_int16	psc;		        /* 0~511. */
   kal_uint32	sc_code;         /* Scrambling code #. 0 ~ 16777215 */
   kal_uint8   power_ctrl_mode;
   kal_uint8 	pa_mode;
   kal_uint16 	idx;
   kal_uint16	afc_dac;
   kal_uint8	dpcch_pwr;
   kal_uint8	dpdch_pwr;
	
   /* Below for UL1D_RF_Meta_SetTxInfo. */
   /* Below for setPaApcDac. */	
   kal_uint8 	rf_band;
   kal_uint8   vm1;
   kal_uint8   vm2;
   kal_uint16  dc2dc_dac;
   kal_uint16  vbias_dac;
   kal_bool    pwr_det;
   kal_uint16 	apc_dac;
   kal_uint16  pa_dac;		
} UL1TSTCmdTxDPCh;	//Anthony

typedef struct
{
	kal_int16	dl_freq;
	kal_int16	psc;	/* 0~511. */
	kal_uint8	ssc;	/* 0~15. */
	kal_int16	ovsf;	/* 0~sf-1. */
	kal_uint16	afc_dac;
	
	/* Below for RF_SetBBRxParams. */
	kal_bool 	hwAGC;
	kal_uint8	mode;		/* 0: mode0, 1: mode1. */
	kal_int16	gain;		/* mode0. */
	kal_uint8	LNAmode;	/* mode1. 0: LNA low, 1: LNA mid, 2: LNA high. */
	kal_uint16	pga;		/* mode1. */
} UL1TSTCmdRxDPCh;

//for list mode
#define MAX_LM_VALID_FREQ 50
typedef struct
{
   /* common parameters */
   kal_bool   afc_dac_valid;
   kal_uint16	afc_dac;
   kal_uint8  loopbackType;//0: no loopback, 1: loopback type 1, 2: loopback type 2
   kal_uint8  frame_shift;//default=0, depends on Test Machine
   kal_uint8  rmc_type;//1: 12.2k, 2: 64k, 3: 144k, 4: 384k
   kal_uint8  ctfc[4];//8960=0,1,2,3; cmu200=0,2,1,3
   kal_uint8  bit_pattern;//0: single ended ber disable, 1: all one, 2: all zero
   /* DL parameters */
   kal_int16	dl_freq[MAX_LM_VALID_FREQ];
   kal_int16	dl_psc;/* 0~511. */
   kal_int16	dl_ovsf;//RMC12.2k: <128, but test set not allow all ovsf,
	                 //RMC12.2k default ovsf=9
   /* UL parameters */
   kal_int16	ul_freq[MAX_LM_VALID_FREQ];
   kal_uint16	ul_tfci;
   kal_uint32	ul_sc_code;	/* Scrambling code #. 0 ~ 16777215 */
   kal_bool   iq_pwr_valid;//valid dpcch, dpdch power
   kal_uint8	dpcch_pwr;//default 8, depends on testing requirement
   kal_uint8	dpdch_pwr;//default 15, depends on testing requirement

   /* common parameters */
   kal_uint8	valid_freq; //valid count of dl/ul freq.
   kal_uint16   test_item[MAX_LM_VALID_FREQ]; //bit0:reserved. bit1:single end BER. bit2:RSSI measure. bit3:reserved. bit4:reserved. bit5:ILPC_ABC. bit6:ILPC_EF. bit7:ILPC_GH.	
   /* the time settings, unit = frame */
   kal_uint16   full_test_time;//the total time of one freq.
   kal_uint8    ready_time; // for first sync after TX transmit
   kal_uint8	sync_time; //the time of sync, from cs_start to LBK is 26 frame
   kal_uint8    retrial; //just for first sync
   kal_uint16	test_time; //the time of test for max&min TX power tests
   kal_uint16   rx_rssi_start_time[3]; //RSSI start time for 3 LNA mode
   kal_uint8    rx_rssi_duration[3];
   kal_uint16   rx_ber_start_time; //BER start time
   kal_uint8    rx_ber_duration;
   kal_uint16	ILPC_ABC_time; //the time of ILPC ABC
   kal_uint16	ILPC_EF_time; //the time of ILPC EF
   kal_uint16	ILPC_GH_time; //the time of ILPC GH
   kal_uint16	transition_time; //the limitation of UE state machine is 4 frame at least
} UL1TSTCmdLISTMODE;

typedef struct
{
   /* common parameters */
   kal_bool   afc_dac_valid;
   kal_uint16	afc_dac;
   kal_uint8  loopbackType;//0: no loopback, 1: loopback type 1, 2: loopback type 2
   kal_uint8  frame_shift;//default=0, depends on Test Machine
   kal_uint8  rmc_type;//1: 12.2k, 2: 64k, 3: 144k, 4: 384k
   kal_uint8  ctfc[4];//8960=0,1,2,3; cmu200=0,2,1,3
   kal_uint8  bit_pattern;//0: single ended ber disable, 1: all one, 2: all zero
   /* DL parameters */
   kal_int16	dl_freq;
	 kal_int16	dl_psc;/* 0~511. */
	 kal_int16	dl_ovsf;//RMC12.2k: <128, but test set not allow all ovsf,
	                 //RMC12.2k default ovsf=9
	 /* UL parameters */
   kal_int16	ul_freq;
   kal_uint16	ul_tfci;
	 kal_uint32	ul_sc_code;	/* Scrambling code #. 0 ~ 16777215 */
	 kal_bool   iq_pwr_valid;//valid dpcch, dpdch power
	 kal_uint8	dpcch_pwr;//default 8, depends on testing requirement
	 kal_uint8	dpdch_pwr;//default 15, depends on testing requirement

	 kal_uint8   subtest; // for DPA/UPA use
} UL1TSTCmdNSFT;

#define MAX_FREQ_LIST 36
typedef struct
{
	kal_uint8	num_freq;
	kal_int16	dl_freq[ MAX_FREQ_LIST ];
	kal_uint8   temperature;
	
	/* Below for RF_SetBBRxParams. */
	kal_bool 	hwAGC;
	kal_uint8	mode;		/* 0: mode0, 1: mode1. */
	kal_int16	gain;		/* mode0. */
	kal_uint8	LNAmode;	/* mode1. 0: LNA low, 1: LNA mid, 2: LNA high. */
	kal_uint16	pga;		/* mode1. */
	
	kal_bool rssi_continue;
} UL1TSTCmdRSSI;

typedef struct
{
	kal_bool	pscan_before_cell_search;	/* True if UL1TST needs power scan before cell search/RSCP. */
	kal_int16	dl_freq;	/* Specific dl_freq to do cell search. Valid if pscan_before_cell_search=F. */
	kal_uint8	sample_num_per_cell;
	kal_bool	read_sfn;	/* True if we need to do SFN measurement for the found cell. */
	
	/* Below for RF_SetBBRxParams. */
	kal_bool 	hwAGC;
	kal_uint8	mode;		/* 0: mode0, 1: mode1. */
	kal_int16	gain;		/* mode0. */
	kal_uint8	LNAmode;	/* mode1. 0: LNA low, 1: LNA mid, 2: LNA high. */
	kal_uint16	pga;		/* mode1. */
} UL1TSTCmdRSCP;

typedef struct
{
// kal_bool	pscan_before_cell_search;      /* True if UL1TST needs power scan before cell search/RSCP. */
   kal_int16	dl_freq;	               /* Specific dl_freq to do cell search. Valid if pscan_before_cell_search=F. */
// kal_uint8	sample_num_per_cell;
// kal_bool	read_sfn;                      /* True if we need to do SFN measurement for the found cell. */
	
   kal_int16   afc_dac;

   /* Below for RF_SetBBRxParams. */
   kal_bool 	hwAGC;
   kal_uint8	mode;		               /* 0: mode0, 1: mode1. */
   kal_int16	gain;		               /* mode0. */
   kal_uint8	LNAmode;	               /* mode1. 0: LNA low, 1: LNA mid, 2: LNA high. */
   kal_uint16	pga;                	   /* mode1. */
} UL1TSTCmdAFC;

//20081115 congo, add MQC cmd
#define MAX_MQC_FREQ_COUNT 40
#define MAX_MQC_PWR_COUNT  40
#define MAX_CAL_BAND       10
#define MAX_MQC_RSSI_COUNT 400

typedef struct
{
   /* Tx part settings */

   /* Below for UL1D_RF_Meta_SetTxInfo. */
   kal_bool     no_loop_ctrl;
   kal_uint16   afc_dac;
   /* Below for setPaApcDac. */	
   //for 3 PA mode, 0:H, 1:M, 2:L
   //Add Tx band
   kal_bool     pwr_det;//0 off/manual mode, 1 on/auto mode
   //kal_uint16 pwr_det_threshold;
   kal_uint8    power_ctrl_mode;//1: HW->O3, 2: SW->59D, Smarti
   kal_uint8    vm1[MAX_CAL_BAND][3];      //PA param
   kal_uint8    vm2[MAX_CAL_BAND][3];      //PA param
   kal_uint16   dc2dc_dac[MAX_CAL_BAND][3];//PA param
   kal_uint16   vbias_dac[MAX_CAL_BAND][3];//PA param
   kal_bool     init_tx_onoff;             //0:off, 1:on
   kal_bool     ready_tx_onoff;            //0:off, 1:on
   kal_uint8    init_pa_mode;		
   kal_uint8    ready_pa_mode;		
   kal_uint16   init_pa_gain;		
   kal_uint16   ready_pa_gain;		
   kal_uint16   init_vga_dac_tpc_idx;		
   kal_uint16   ready_vga_dac_tpc_idx;		

   /* Rx part settings */

   /* Below for RF_SetBBRxParams. */
   // For high gain cal. @ high power: replace gain table
   kal_uint8    temperature;
   kal_bool 	hwAGC;       //0:SW gain mode, 1:HW AGC. AGC must on for RSSI measure. HW limit
   kal_int16	gain_init;		/* for HW mode */

   /* Mobile Quick Calibration settings */
	
   /* general settings */
   kal_bool     init_condition; //0: max_pwr, 1:min_pwr
   kal_uint8    step_duration;  //in slot
   kal_uint8    ready_duration; //in slot
   kal_uint8    retune_duration; //in slot
   kal_uint8    gain_stable_time; //in slot
   kal_uint16   max_vga_dac;
   kal_uint16   min_vga_dac;
   kal_uint16   jump_vga_dac;	

   /* freq-pwr table */
   kal_uint8	freq_count;
   kal_uint8	pwr_count;
   kal_uint8    freq_start_idx;
   kal_uint8    pwr_start_idx;
   kal_uint8    odd_record;  /*for Anritsu8820, only odd step (1,3,5...start from 1) is for measurement.  */
	
   kal_uint8    pa_gain_start_idx; // for O3 TPC
   kal_uint8    pd_gain_start_idx; // for O3 TPC

   kal_uint8    dl_band[MAX_MQC_FREQ_COUNT]; //1:band1, 2:band2, 3:band3, 5:band5
   kal_uint8    ul_band[MAX_MQC_FREQ_COUNT]; //1:band1, 2:band2, 3:band3, 5:band5
   kal_uint16   dl_freq[MAX_MQC_FREQ_COUNT]; //in uarfcn
   kal_uint16   ul_freq[MAX_MQC_FREQ_COUNT]; //in uarfcn
   kal_uint8    pa_mode[MAX_MQC_PWR_COUNT];		
   kal_uint16   vga_dac_tpc_idx[MAX_MQC_PWR_COUNT];//power_ctrl_mode=HW, tpc_idx. Vice versa.

   kal_uint16   pa_gain[MAX_MQC_PWR_COUNT]; // for O3 TPC
   kal_uint8    pd_gain[MAX_MQC_FREQ_COUNT]; // for O3 TPC
   kal_uint8    pa_section[MAX_MQC_PWR_COUNT];
   //kal_uint16   dl_meta_gain[MAX_MQC_RSSI_COUNT];
   kal_uint16   dl_meta_gain[MAX_MQC_PWR_COUNT];

} UL1TSTCmdMQC;

typedef struct
{
   kal_uint32          lid;      // the lid is needed to update run-time value
   kal_uint32          eg_ptr;   // the event group pointer used to notify runt-time update finish
} UL1TSTCmdReloadNVRAM;

typedef struct
{
    kal_uint16 measure_count;    /*<! specify the measurement count UL1D will do the measurement measure_count times */
} UL1TSTCmdGetRfTempSensor;

typedef struct 
{
    kal_uint16 rf_band_idx;
    kal_uint16 power_level_num;
    kal_uint16 code_word_num;
}
UL1TSTCmdSetMipiCodeWord;

typedef struct 
{
	kal_uint8	num_freq;
	kal_int16	dl_freq[ MAX_FREQ_LIST ];
	kal_uint8   temperature;
	
	/* Below for RF_SetBBRxParams. */
	kal_bool 	hwAGC;
	kal_uint8	mode;		/* 0: mode0, 1: mode1. */
	kal_int16	gain;		/* mode0. */
	kal_uint8	LNAmode;	/* mode1. 0: LNA low, 1: LNA mid, 2: LNA high. */
	kal_uint16	pga;		/* mode1. */
	
	kal_bool rssi_continue;	
}
UL1TSTCmdRxGainSweep;

typedef union
{
   UL1TSTCmdTxAccess   txaccess;
   UL1TSTCmdTxDPCh     txdpch;	//Anthony
   UL1TSTCmdRxDPCh     rxdpch;
   UL1TSTCmdRSSI       rssi;
   UL1TSTCmdRSCP       rscp;	
   UL1TSTCmdAFC        afc;    //anthony 0514
   UL1TSTCmdMQC	       mqc;	
   UL1TSTCmdNSFT       nsft;
   UL1TSTCmdLISTMODE   listmode; //for list mode
   UL1TSTCmdReloadNVRAM reload;
   UL1TSTCmdGetRfTempSensor rfTemperature;  /*<! UL1TST_CMD_GET_RF_TEMP */
   kal_uint8           is_PaDrift;   // PA drfit compensation switch message
   kal_uint8           rxdMode;      /**< \brief R8 set rx path: 0:none 1:main 2:diversity: 3: both */
   kal_int32           rx_cell_power;// configure the Rx cell power before cell search. uints:qdbm
   kal_uint8           mipi_rf_band;
   UL1TSTCmdSetMipiCodeWord setMipiPaCwParam;
   UL1TSTCmdRxGainSweep rx_gain_sweep;      
} UL1TSTCmdParam;

//Result
typedef struct
{
	kal_bool	ok;
	kal_uint8	num_freq;
	kal_int16	dl_freq[ MAX_FREQ_LIST ];
	kal_int32	rssi[ MAX_FREQ_LIST ];	
} UL1TSTResultRSSI;

// R8 get both rx path RSSI result
typedef struct
{
   kal_bool    ok;
   kal_uint8   num_freq;
   kal_int16   dl_freq[ MAX_FREQ_LIST ];
   kal_int32   rssi[ MAX_FREQ_LIST ];
   kal_int32   rssi_rxd[ MAX_FREQ_LIST ];
} UL1TSTResultRSSIRxD;

typedef struct
{	
	kal_uint16	psc;		/* Primary scrambling code */
	kal_int32	tm;		/* Cell frame boundary offset to LST */
	kal_int16	off;		/* Cell frame number offset to LST */	
	kal_bool	sttd; 		/* True for STTD used. */
	kal_uint8	sample_num;
	kal_int16	rscp_sum;   //kal_uint8	rscp_sum;
	kal_int16 freq_error;	//anthony 0514	
} UL1TST_cpich_result_T;

#define MAX_NUM_MEAS_CELL 32
typedef struct
{
    kal_bool                ok;
	kal_uint8               num_cell;
	UL1TST_cpich_result_T   cpich_result[ MAX_NUM_MEAS_CELL ];	
} UL1TSTResultRSCP;

typedef struct
{
    kal_bool     ok;
    kal_uint16   psc;       /* Primary scrambling code */
    kal_int32    tm;		    /* Cell frame boundary offset to LST */
    kal_bool     sttd;      /* True for STTD used. */
    kal_uint8    rscp_sum;
    kal_int16    freq_error;
} UL1TSTResultAFC;
   
typedef struct
{
    kal_bool     ok;
    kal_uint16   psc;		    /* Primary scrambling code */
    kal_int32    tm;		    /* Cell frame boundary offset to LST */
    kal_bool     sttd; 	        /* True for STTD used. */
    kal_uint8    rscp_sum;
    kal_int32    freq_error;
} UL1TSTResultAFC_EXT;

typedef struct
{
   kal_bool      ok;
   kal_uint32    ber;	      /* Spec requirement=10^-3. We will count 10^5 frames(100 times spec requirement) for BER calculation. Only count for the only TRCh for DPDCh. */
} UL1TSTResultRxDPCh;

typedef struct
{
    kal_bool    ok;
    kal_uint8   link_status;
} UL1TSTResultNSFT;

#define MAX_MQC_RSSI_COUNT 400
typedef struct
{
   kal_bool   ok;
   /* freq-pwr table */
   kal_uint8  freq_count;
   kal_uint8  pwr_count;
   kal_uint8  freq_start_idx;
   kal_uint8  pwr_start_idx;
   kal_uint8  rx_lna_mode[MAX_MQC_RSSI_COUNT]; // 0: high, 1: middle, 2: low
   kal_int16  rssi[MAX_MQC_RSSI_COUNT];	
   kal_uint8  rxd_lna_mode[MAX_MQC_RSSI_COUNT]; // 0: high, 1: middle, 2: low
   kal_int16  rssi_rxd[MAX_MQC_RSSI_COUNT];
   kal_uint16 pwr_det_value[MAX_MQC_FREQ_COUNT][3];
   kal_int16  mqc_tx_gvgabb0_report[MAX_MQC_RSSI_COUNT];
   /*  {pd_meas-PA_high, pd_meas-PA_mid, pd_meas-PA_low}, //freq-1
    *  {pd_meas-PA_high, pd_meas-PA_mid, pd_meas-PA_low}, //freq-2
    *  ...
    *  {pd_meas-PA_high, pd_meas-PA_mid, pd_meas-PA_low}, //freq-freq_count
    */
} UL1TSTResultMQCOctLev;

typedef struct
{
   kal_bool   ok;
   /* freq-pwr table */
   kal_uint8  freq_count;
   kal_uint8  pwr_count;
   kal_uint8  freq_start_idx;
   kal_uint8  pwr_start_idx;
   kal_int16  rssi[MAX_MQC_RSSI_COUNT];	
   kal_uint16 pwr_det_value[MAX_MQC_FREQ_COUNT];
   /*  {RSSI-1, RSSI-2, ... , RSSI-pwrcount}, //freq-1
    *  {RSSI-1, RSSI-2, ... , RSSI-pwrcount}, //freq-2
    *  ...
    *  {RSSI-1, RSSI-2, ... , RSSI-pwrcount}, //freq-freq_count
    *  Same for power detector.
    */
} UL1TSTResultMQC;

typedef struct
{
	kal_bool	ok;
	kal_uint8	num_freq;
	kal_int16	dl_freq[ MAX_FREQ_LIST ];
	kal_int32	inband_pow[ MAX_FREQ_LIST ];
} UL1TSTResultInbandPow;

//for list mode
typedef struct
{
   kal_uint8 status;
   kal_uint8 current_idx;
   kal_int16  total_bits[MAX_LM_VALID_FREQ][2];//0:real ber test. 1:debug before ber test
   kal_int16  error_bits[MAX_LM_VALID_FREQ][2];
   kal_int16  rssi[MAX_LM_VALID_FREQ][3];//RSSI at 3 LNA mode
   kal_int8  lnamode[3];
} UL1TSTResultListMode;

typedef struct
{
    kal_bool    ok;    /*<! ok indicator */
    kal_uint32  sum;   /*<! the sum of measure_count times of temp sensor result */
} UL1TSTResultGetRfTempSensor;

/* DO NOT Modify the definition of UL1TSTCalibrationItem */
typedef  struct
{
    kal_uint32 is_capable:1;      /*<! the indicator to indicate if this item is supported by SW or HW */
    kal_uint32 is_mandatory:1;    /*<! the indicator to indicate if this item is mandatory to be calibrated */
    kal_uint32 parameters:30;      /*<! parameter to be carried to tool side */
} UL1TSTCalibrationItem;

/* DO NOT Modify the member order of UL1TSTCalibrationItemSet, Items must be added to the end  */
typedef struct
{
    UL1TSTCalibrationItem tadc_cal; /*<! TADC calibration capability */
    UL1TSTCalibrationItem multi_rat_tadc_bitmap; /*<! bit map of multi-rat TADC calibration */
    UL1TSTCalibrationItem multi_rat_afc_bitmap; /*<! bit map of multi-rat AFC calibration */
    UL1TSTCalibrationItem mipi_pa_level_and_cw_num; /*<! Number of MIPI PA CW */
	UL1TSTCalibrationItem temperature_info;
    UL1TSTCalibrationItem list_mode_support; /*<! [5] Target support list mode API; is_capable (0: not supported, 1: supported) */
} UL1TSTCalibrationItemSet;

/* DO NOT Modify the member order of UL1TSTCalibrationItemSet, Items must be added to the end  */
typedef struct
{
    kal_uint32 mipi_pa_band_support; /*<! band support bit map of MIPI PA */
	kal_uint32 ue_capability_ext1;   /*<! 0x00000001 : support RX gain sweep */
} UL1TSTCapabilityItemSet;

//(this part is put into peer buffer)
typedef struct
{
    kal_uint32 capability_item_offset; /*!< the offset value of the starting address of UL1TSTCapabilityItemSet in UL1TSTRfCapability */
    kal_uint32 calibration_item_offset; /*!< the offset value of the starting address of UL1TSTCalibrationItemSet in UL1TSTRfCapability */
    UL1TSTCapabilityItemSet capabilityItems;
    UL1TSTCalibrationItemSet calibrationItems;
} UL1TSTResultGetRfCapability;

typedef struct
{
    kal_bool    ok;      /*<! ok indicator */
    kal_uint32  cwNum;   /*<! the Number of MIPI PA CWt */
} UL1TSTResultGetMipiCwNum;

typedef struct 
{
    kal_uint8  status;
    kal_uint16 power_level_num;
    kal_uint16 code_word_num;
}
UL1TSTResultGetMipiCodeWord;

typedef struct
{
   kal_bool ok;
}
UL1TSTResultSetMipiCodeWord;

typedef struct
{
   kal_int16 status;
   kal_int16 tadc_dac;
   kal_int16 temperature;
   kal_int16 temp_idx;
}
UL1TSTResultTemperatureInfo;

typedef union
{
   kal_bool                ok;
   UL1TSTResultRSSI        rssi;
   UL1TSTResultRSSIRxD     rssi_rxd; /**< \breif R8 get both rx path RSSI */
   UL1TSTResultRSCP        rscp;
   UL1TSTResultRxDPCh      rx_dpch;   
   UL1TSTResultAFC         afc;
   UL1TSTResultAFC_EXT     afc_ext;
   UL1TSTResultNSFT        nsft;
   UL1TSTResultMQC         mqc;
   UL1TSTResultMQCOctLev   mqc_octlev;
   UL1TSTResultGetRfTempSensor rfTemperature;
   UL1TSTResultGetMipiCwNum    mipiPaCwNum;
   UL1TSTResultGetMipiCodeWord mipiPaGetCwData;
   UL1TSTResultSetMipiCodeWord mipiPaSetCwData;
   UL1TSTResultTemperatureInfo temperature_info;
   UL1TSTResultInbandPow   inband_pow;
} UL1TSTResultParam;

typedef struct
{
   //kal_uint8       ref_count; // part of LOCAL_PARA_HDR
   //kal_uint16      msg_len;   // part of LOCAL_PARA_HDR
   LOCAL_PARA_HDR
   UL1TSTCmdType   type;
   UL1TSTCmdParam  param;
} ft_ul1tst_req_T;

typedef struct
{
   //kal_uint8         ref_count; // part of LOCAL_PARA_HDR
   //kal_uint16        msg_len;   // part of LOCAL_PARA_HDR
   LOCAL_PARA_HDR
   UL1TSTCmdType     type;
   UL1TSTResultParam param;
} ul1tst_ft_cnf_T;

//#endif
#endif
