/*****************************************************************************
 *
 * Filename:
 * ---------
 * tl1fta_ast_struct.h
 *
 * Project:
 * --------
 *   Astroanut
 *
 * Description:
 * ------------
 *   TL1_FT message definition
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

#ifndef _TL1FTA_AST_STRUCT_H
#define _TL1FTA_AST_STRUCT_H

typedef struct _rfcal_reset_req_struct
{
    LOCAL_PARA_HDR 
    kal_uint8 mode; //0 for rfcal,1 for nsft
} rfcal_reset_req_struct;

typedef struct _rfcal_reset_cnf_struct
{
    LOCAL_PARA_HDR 
} rfcal_reset_cnf_struct;

typedef struct _rfcal_cs_req_struct
{
    LOCAL_PARA_HDR 
    kal_uint16 freq;
    kal_uint16 rf_gain;
    kal_uint16 afc_dac;
    kal_uint8 agc_mode;
    kal_uint8 bTracking;
    kal_bool isAGCCal;
} rfcal_cs_req_struct;

typedef struct _rfcal_cs_ind_struct
{
    LOCAL_PARA_HDR 
    kal_bool success; 
    kal_int16  rssi;
    kal_uint16 used_gain;
    kal_uint16 power;
} rfcal_cs_ind_struct;

typedef struct _rfcal_dch_req_struct
{
    LOCAL_PARA_HDR 
    kal_uint16  freq;
    kal_uint16  afc_dac;
    kal_uint16  apc_data;
    kal_uint8   pa_mode;

    kal_uint16  cap_id;
    kal_uint8   ts_bmp;//UL Timeslot bitmap
    kal_uint8   mod_bmp;//modulation(QPSK/16QAM) bitmap
	kal_uint8   powerfix;//0:tx power not fixed(default=0),1:fix tx power
	kal_int8    power;//tx power value
} rfcal_dch_req_struct;

typedef struct _rfcal_dch_cnf_struct
{
    LOCAL_PARA_HDR 
} rfcal_dch_cnf_struct;

typedef struct _rfcal_dch_rel_req_struct
{
    LOCAL_PARA_HDR 
} rfcal_dch_rel_req_struct;

typedef struct _rfcal_dch_rel_cnf_struct
{
    LOCAL_PARA_HDR 
} rfcal_dch_rel_cnf_struct;

#define TL1_BAND_SUPPORT_A    (1<<0)
#define TL1_BAND_SUPPORT_B    (1<<1)
#define TL1_BAND_SUPPORT_C    (1<<2)
#define TL1_BAND_SUPPORT_D    (1<<3)
#define TL1_BAND_SUPPORT_E    (1<<4)
#define TL1_BAND_SUPPORT_F    (1<<5)

#define TL1_CAPABILITY_FHC           (1<<0)    // fast handset calibration
#define TL1_CAPABILITY_NSFT          (1<<1)    // non-signalling final test.capability
#define TL1_CAPABILITY_COCRYSTAL     (1<<2)    // gsm/td use same crystal
#define TL1_CAPABILITY_COTEMP_CAL     (1<<3)    // gsm/td use same temp adc cal result
#define TL1_CAPABILITY_QUERY_EXTENSION (1<<4)  //support new capability query interface

#define  TL1D_RF_ID_MT6161    0x0001
#define  TL1D_RF_ID_MT6163    0x0002
#define  TL1D_RF_ID_MT6166    0x0003
#define  TL1D_RF_ID_MT6169    0x0004
#define  TL1D_RF_ID_MT6165    0x0005

#define  TL1D_BB_ID_AST1001    0x0001
#define  TL1D_BB_ID_AST2001    0x0002
#define  TL1D_BB_ID_AST3001_E1    0x0003
#define  TL1D_BB_ID_AST3001_E2    0x0004
#define  TL1D_BB_ID_AST3002_E1    0x0005

typedef struct _T_MsChipID
{
    kal_uint16 BB_chipID;
    kal_uint16 RF_chipID;
} T_MsChipID;
typedef struct _T_MsCapability
{
    kal_uint16 capability;
    kal_uint16 band_support;
} T_MsCapability;

// YH
/* DO NOT Modify the definition of T_FTA_CalibrationItem */
typedef  struct _T_MsCalibrationItem
{
    kal_uint32 is_capable      :1; /*<! the indicator to indicate if this item is supported by SW or HW */
    kal_uint32 is_mandatory    :1; /*<! the indicator to indicate if this item is mandatory to be calibrated */
    kal_uint32 parameters      :30; /*<! parameter to be carried to tool side */
} T_MsCalibrationItem;

// YH
/* DO NOT Modify the member order of UL1TSTCalibrationItemSet, Items must be added to the end  */
typedef struct _T_MsCalibrationItemSet
{
    T_MsCalibrationItem tadc_cal; /*<! TADC calibration capability */
    T_MsCalibrationItem multi_rat_tadc_bitmap; /*<! bit map of multi-rat TADC calibration */
    T_MsCalibrationItem multi_rat_afc_bitmap; /*<! bit map of multi-rat AFC calibration */
	T_MsCalibrationItem apc_cal;/*<! Added for CLPC, 0: OLPC, 1: CLPC */
	T_MsCalibrationItem temperature_info;
} T_MsCalibrationItemSet;

// YH
/* DO NOT Modify the member order of T_FTA_CapabilityItemSet, Items must be added to the end  */
typedef struct _T_MsCapabilityItemSet
{
    kal_uint32 reserved;
} T_MsCapabilityItemSet;

// YH
typedef struct _T_MsResultGetRfCapability
{
    kal_uint32 capability_item_offset;//8
    kal_uint32 calibration_item_offset;//12
    T_MsCapabilityItemSet capability_items;
    T_MsCalibrationItemSet calibration_items;
} T_MsResultGetRfCapability;

typedef struct _rfcal_getinfo_req_struct
{
    LOCAL_PARA_HDR 
} rfcal_getinfo_req_struct;
typedef struct _rfcal_getinfo_cnf_struct
{
    LOCAL_PARA_HDR 
    T_MsChipID id;
    T_MsCapability cap;
    kal_uint16 pa_stage;
    T_MsResultGetRfCapability cap_ex;

} rfcal_getinfo_cnf_struct;

typedef struct _rfcal_get_pd_req_struct
{
    LOCAL_PARA_HDR 
} rfcal_get_pd_req_struct;

typedef struct _rfcal_get_pd_cnf_struct
{
    LOCAL_PARA_HDR 
	kal_int16  PdPower;
} rfcal_get_pd_cnf_struct;
typedef struct _rfcal_abbreg_ind_struct
{
    LOCAL_PARA_HDR 
    kal_uint8  isWrite;
    kal_uint16 val;
}rfcal_abbreg_ind_struct;

typedef struct _rfcal_abbreg_req_struct
{
    LOCAL_PARA_HDR 
    kal_uint8  isWrite;
    kal_uint16 addr;
    kal_uint16 val;
} rfcal_abbreg_req_struct;

typedef struct _nsft_set_para_req_struct
{
    LOCAL_PARA_HDR 
    kal_bool bAfcdacValid;
    kal_uint16 afc_dac;
}nsft_set_para_req_struct;

typedef struct _nsft_set_para_cnf_struct
{
    LOCAL_PARA_HDR 
}nsft_set_para_cnf_struct;


typedef struct _rftest_rxtx_req_struct
{
    LOCAL_PARA_HDR 
    kal_bool bRx;
    kal_bool bOn;
    kal_uint16 uarfcn;
}rftest_rxtx_req_struct;

typedef struct _rftest_rxtx_cnf_struct
{
    LOCAL_PARA_HDR 
    kal_bool bRx;
}rftest_rxtx_cnf_struct;

typedef struct _fhc_start_req_struct
{
    LOCAL_PARA_HDR 
    kal_uint8    freq_num;// frequency pointer num,1~30
    kal_uint16    freq_list[30];// frequency pointer list 
    kal_uint8    apc_step_num;//power step number(s) for APC cal,1~3
    kal_uint16    apc_data_list[12];//APC Dac
    kal_uint8    pa_mode_list[12];//PA MODE
    kal_uint8    agc_step_num;//  power step number(s) for AGC cal,1~3
    kal_uint8    agc_mode_list[3];//AGC MODE
    kal_uint8    agc_freq_retune_num;//agc freq retune subframe number
    kal_uint8    apc_freq_retune_num;//apc freq retune subframe number    
}fhc_start_req_struct;

typedef struct _fhc_start_ex_req_struct
{
    LOCAL_PARA_HDR 
    kal_uint8    freq_num;// frequency pointer num,1~40
    kal_uint16    freq_list[40];// frequency pointer list 
    kal_uint8    pow_step_num;//power step number(s) for APC cal,1~12
    kal_int8    pow_list[12];//power list
    kal_uint8    agc_step_num;//  power step number(s) for AGC cal,1~9
    kal_uint8    agc_mode_list[9];//AGC MODE
    kal_uint16    rf_gain[9];
    kal_uint8    agc_freq_retune_num;//agc freq retune subframe number
    kal_uint8    apc_freq_retune_num;//apc freq retune subframe number    
}fhc_start_ex_req_struct;

typedef struct _fhc_start_cnf_struct
{
    LOCAL_PARA_HDR 
}fhc_start_cnf_struct;

typedef struct _fhc_finish_ind_struct
{
    LOCAL_PARA_HDR 
    kal_uint8 nRssi;//rssi result num
    kal_int16 rssi_list[30*3];
}fhc_finish_ind_struct;

typedef struct _fhc_finish_ex_ind_struct
{
    LOCAL_PARA_HDR 
    kal_uint8 nRssi;//rssi result num
    kal_int16 rssi_list[40*9];
}fhc_finish_ex_ind_struct;

typedef struct _fhc_finish_ex2_ind_struct
{
    LOCAL_PARA_HDR
    kal_uint8 nRssi;//rssi result num
    kal_uint8 npdresult;
    kal_int16 rssi_list[40*9];
    kal_int16 pdresult_list[40*9];
}fhc_finish_ex2_ind_struct;
typedef struct _slt_module_test_req_struct
{
    LOCAL_PARA_HDR 
}slt_module_test_req_struct;

#endif
