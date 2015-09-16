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
 * Filename:
 * ---------
 *  mpal2rr_struct.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


#ifndef _MPAL2RR_STRUCT_H
#define _MPAL2RR_STRUCT_H

/*Evelyn: Remove redundant header and file */
#include "rr_mpal_interface.h"
#include "kal_general_types.h"
#include "l3_inc_enums.h"
#include "mph_cs_def.h"


typedef struct {
    kal_int16 c_value;             /* Austin 040413: report c_value in dbm, instead of rxlev */
    kal_uint8 is_bl_var_valid;
    kal_uint16 bl_var;
    kal_uint16 bit_count[4];
    kal_uint16 bit_error_count[4];
} ch_quality_rep_struct;

typedef struct {
    kal_uint8 time_slot;
    kal_uint8 cs;
    kal_uint8 is_bad_block;    
    channel_type_enum ch_type;
/* End Claire 041118 change : Modify  dl_radio_blk_struct : To be removed later */  
    kal_uint8 is_data_buffer;
#ifdef MCD_PACK_UNPACK
		kal_uint8 data[75];
#else
    kal_uint8 *data;
#endif
 
  #ifdef __EGPRS_MODE__
    kal_int32 meanBep;               /* Mean_BEP(block), no meaning if not in EGPRS mode*/
    kal_int32 cvBep;                 /* CV_BEP(block), no meaning if not in EGPRS mode */
    kal_uint8 header[6];
#ifdef MCD_PACK_UNPACK
	kal_uint8 data2[75];
#else
    kal_uint8 *data2;
#endif
    kal_uint8 is_data_valid;
    kal_uint8 is_data2_valid;

#ifdef __GERAN_FANR__
    kal_uint8 is_pan_valid;
    kal_uint8 pan[4];
#endif

  #endif
    
} dl_radio_blk_struct;

typedef struct{
    kal_uint32 frame_no;
    kal_uint8 rrbp_txed;
    kal_uint8 is_usf_detected;// bitmap of usf detected
    kal_uint8 ctrl_blks_free_in_q;
    kal_uint8 no_data_txed[MAX_TBF_NUM];
    kal_uint8 is_alloc_exhausted;  
#ifdef __PS_HO__
    kal_bool  is_before_handover;
#endif /* end of __PS_HO__ */    
#ifdef __GERAN_FANR__
    kal_uint8 time_slot;
#endif
}ready_to_send_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 scan_id;
    kal_bool bcch_list_valid;
    kal_int16 power_sum_in_quarter_dbm[MPH_MAX_POWER_SCAN_RESULTS_LEN]; /* Defined in mph_cs_msg.h */
} mpal_rr_search_rf_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint16 arfcn;
    kal_uint8 result;
    kal_uint8 bsic;
    kal_int32 frame_offset;
    kal_int32 ebit_offset;
} mpal_rr_bsic_sync_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    rr_block_monitor_enum block_ind;  /* ref. to mph_block_monitor_enum */
    kal_uint8 tc;
    kal_uint32 frame_no;
    kal_uint16 arfcn;    
    channel_type_enum channel_type;
    kal_uint8 data[23];
    kal_int16 c_value;          /* Austin 040413: report c_value in dbm, instead of rxlev */
    kal_bool is_serving; /* Only for check NBCCH or BCCH*/
#ifdef __SMART_PAGING_IN_IDLE__
    kal_int16 serving_power_in_quarter_dbm;
#endif /* __SMART_PAGING_IN_IDLE__ */
} mpal_rr_data_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8  req_id;  /*sequence number for RR to know the ._cnf received is old or new*/
    kal_uint32 frame_number;
    kal_uint16 rach_data;
} mpal_rr_rach_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 t0;
    
#ifdef __BLIND_HANDOVER__
    /* Elly20080228, report the frame offset and ebit offset to RR in case that the blind handover is executed
     * and RR has no timing information to report the OTD to NW if requested. */
    kal_int32  target_frame_offset;
    kal_int32  target_ebit_offset;
#endif /* end of __BLIND_HANDOVER__ */

} mpal_rr_handover_success_ind_struct;

typedef struct {
    LOCAL_PARA_HDR    
    handover_fail_cause_enum error_cause;

} mpal_rr_handover_fail_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 current_dch;
    kal_uint8 is_freq_in_one_band;
    kal_uint8 starting_time_expired;
} mpal_rr_frequency_redefinition_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 ext_meas_freq_list_len;
    kal_uint8 dtx_used;
    kal_uint8 list_ref;
    kal_uint16 arfcn[64];
    kal_int16 rlac_in_quarter_dbm[64];
} mpal_rr_extended_meas_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_int16 rla_in_quarter_dbm;
    kal_uint8 timing_advanced;  /* TY: used for AGPS, report packet TA in PTM */
#ifdef UNIT_TEST
    kal_uint32 meas_ind_ms_diff;
#endif /* UNIT_TEST */
} mpal_rr_serv_idle_meas_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_int16 rlac_full_in_quarter_dbm;
    kal_int16 rlac_sub_in_quarter_dbm;
    kal_uint8 rxqual_full_avg;
    kal_uint8 rxqual_sub_avg;
    kal_uint8 dtx_used;
    kal_int16 current_tx_power_in_dbm;  /* Maruco20100423, to show the tx power level in engineering mode */
#ifdef __R99__
    kal_int8   mean_bep;
    kal_int8   cv_bep;
    kal_int32  rxlev_val;
    kal_int8   nbr_rcdv_blocks;
#endif /* __R99__ */
#if defined (__AMR_SUPPORT__) || defined (__AMRWB_LINK_SUPPORT__)
   kal_bool amr_info_valid;
   kal_bool  dl_dtx;  /* Maruco20100423, to show DL DTX is on/off in engineering mode */
   kal_uint8 cmr_cmc_cmiu_cmid;
   kal_uint8 c_i;
   kal_uint16 icm;
   kal_uint16 acs;
#endif /* __AMR_SUPPORT__ || __AMRWB_LINK_SUPPORT__*/
} mpal_rr_serv_dedi_meas_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 list_ref;
    kal_uint8 list_len;
    kal_uint16 arfcn_list[33];
    kal_int16 rla_in_quarter_dbm[33];
#if defined(__UMTS_RAT__) || defined(__LTE_RAT__)
    /* Elly20081003, Indicates the following 4 idle frames are for GSM or other RAT. */
    kal_uint8 is_occupied_by_other_rat;
#endif /* defined(__UMTS_RAT__) || defined(__LTE_RAT__) */
} mpal_rr_neighbor_meas_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
#if defined (__PS_SERVICE__) && defined (__PKT_EXT_MEAS__)
    kal_uint8 is_for_extended_meas;
#endif /*(__PS_SERVICE__) && (__PKT_EXT_MEAS__)*/
    kal_uint16 arfcn;
    kal_uint8 bsic_valid;
    kal_uint8 bsic;
    kal_uint8 burst_access_id;
    kal_int32 frame_offset;
    kal_int32 ebit_offset;
    kal_uint8 is_for_manual_list;
} mpal_rr_neighbor_bsic_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint16 arfcn;
    kal_uint8 bsic_valid;
    kal_uint8 bsic;
    kal_uint8 burst_access_id;
    kal_int32 frame_offset;
    kal_int32 ebit_offset;
} mpal_rr_cell_bsic_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 list_ref;
    kal_uint8 list_len;
    kal_uint16 arfcn_list[33];
    kal_int16 nc_meas_in_qdbm[33];
} mpal_rr_nc_measurement_ind_struct;

#ifdef __PKT_EXT_MEAS__
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 list_len;
    kal_uint16 arfcn_list[32];
    kal_uint8 ext_meas_in_rxlev[32];
} mpal_rr_pkt_ext_measurement_ind_struct;
#endif /*__PKT_EXT_MEAS__*/

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 carrier_ref;
    kal_uint8 valid_meas_ts;
    kal_int16 ss_sample[8];
    kal_uint8 int_meas_freq;
    kal_uint32 frame_number;
} mpal_rr_int_measurement_ind_struct;

typedef struct{
    LOCAL_PARA_HDR
    kal_bool is_all_tbf_rel;
    kal_uint8 ul_tbf_bitmap;
    kal_uint8 dl_tbf_bitmap;
}mpal_rr_pdtch_disconn_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 transition_id_ul[MAX_TBF_NUM];
    kal_uint8 transition_id_dl[MAX_TBF_NUM];
    kal_uint8 ul_tbf_bitmap;
    kal_uint8 dl_tbf_bitmap;	
} mpal_rr_pdtch_connect_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint32 frame_no;
    kal_uint16 arfcn;
    ch_quality_rep_struct ch_qual_rep;
    kal_uint8 no_dl_radio_blks;
    //kal_uint8 dl_radio_blks_size;
    dl_radio_blk_struct dl_radio_blks[4];
  #ifdef __EGPRS_MODE__
    kal_uint8 out_of_mem;
    kal_uint16 dsp_vq[MAX_TBF_NUM];    	
  #endif

    kal_uint8 is_ul_blk_conflict; /* only used in G2.0+ */
    kal_uint8 is_rts_info_valid;
    ready_to_send_ind_struct rts_info;
    kal_uint8 dl_mTBFtid[MAX_TBF_NUM];
    
#ifdef __MONITOR_PAGE_DURING_TRANSFER__
   /* Provide next pch frame number for MAC to enhance ps performance during PS transfer*/
    kal_uint32 next_pch_fn;
#endif /*end of __MONITOR_PAGE_DURING_TRANSFER__*/

#ifndef __MTK_TARGET__
    kal_uint8 pack_data[23];
#endif

} mpal_rr_transfer_data_ind_struct;


#if (!defined(__MTK_TARGET__)) && (defined (__GERAN_RTTI__) || defined(__GERAN_FANR__))
#include "mph_cnst.h"
#include "mph_types.h"
#include "mph_cs_def.h"
#include "mph_cs_msg.h"
#include "mph_ps_def.h"
#include "mph_ps_msg.h"

typedef struct {
    LOCAL_PARA_HDR
    mphp_packet_downlink_struct ptr_pkt_dl;
    mph_rx_multislot_data_struct rx_data[4];
}mpal_rr_transfer_data_notice_ind_struct;
#endif

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 is_successful;
} mpal_rr_ccch_rrbp_cnf_struct;


typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 is_successful;
} mpal_rr_deactivate_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_bool success;
} mpal_rr_set_rat_service_cnf_struct;

#ifdef __PS_SERVICE__
#ifdef __PS_HO__
typedef struct {
    LOCAL_PARA_HDR
    handover_fail_cause_enum error_cause;
    /* In blind PS handover, MPAL fills them with the timing info of BLIND_PS_HANDOVER_BSIC_IND from L1.
      * In normal PS handover, MPAL fills them with the stored timing info of PS_HANDOVER_REQ from RR */
    kal_uint32 frame_offset; 
    kal_uint32 ebit_offset;
} mpal_rr_ps_handover_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 ul_tbf_bitmap;
    kal_uint8 ul_transition_id[MAX_TBF_NUM];
    kal_uint8 dl_tbf_bitmap;
    kal_uint8 dl_transition_id[MAX_TBF_NUM];
} mpal_rr_ps_handover_reconnect_cnf_struct;
#endif /* end of __PS_HO__ */
#endif /* end of __PS_SERVICE__ */

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 pch_data[23];
} mpal_rr_detect_paging_block_callback_req_struct;

/******************************************************************************/
/*                       Multi-mode Standby GSM inter-RAT process                          */
/******************************************************************************/

#if defined(__UMTS_RAT__) || defined(__LTE_RAT__)
#include "gas_eas_enums.h"

#define STANDBY_GSM_MEAS_MAX_CELL_NUM (32)

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 list_ref;
    kal_uint8 list_len;
    kal_int16 arfcn_list[STANDBY_GSM_MEAS_MAX_CELL_NUM];
    kal_int16 rla_in_quarter_dbm[STANDBY_GSM_MEAS_MAX_CELL_NUM];
    kal_uint32 bsic_reconfirm_para;
#ifdef UNIT_TEST
    kal_uint32 time_stamp;
#endif /* UNIT_TEST */
    kal_bool is_not_all_arfcn_measured;
} mpal_rr_standby_gsm_meas_ind_struct;

#if defined(__23G_PRI_RESEL_SUPPORT__) || defined(__LTE_RAT__)
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 list_ref;
    kal_uint8 list_len;
    kal_int16 arfcn_list[STANDBY_GSM_MEAS_MAX_CELL_NUM];
    kal_int16 rla_in_quarter_dbm[STANDBY_GSM_MEAS_MAX_CELL_NUM];
#ifdef UNIT_TEST
    kal_uint32 time_stamp;
#endif /* UNIT_TEST */    
} mpal_rr_standby_gsm_prio_meas_ind_struct;
#endif /* defined(__23G_PRI_RESEL_SUPPORT__) || || defined(__LTE_RAT__) */

typedef struct {
    LOCAL_PARA_HDR
    kal_uint16 arfcn;
    kal_bool bsic_valid;
    kal_uint8 bsic;
    kal_uint32 frame_offset;
    kal_uint32 ebit_offset;
    kal_uint32 time_stamp;
} mpal_rr_standby_gsm_bsic_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
#ifdef __PS_HO__
    kal_bool is_ps_handover;
#endif /* end of __PS_HO__ */
} mpal_rr_inter_rat_handover_cnf_struct;

#ifdef __LTE_RAT__
typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 scan_id;
    kal_uint16 arfcn;
    kal_int16 power_sum_in_quarter_dbm;
} mpal_rr_standby_gsm_report_cgi_search_rf_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 bsic_tid;
    kal_uint16 arfcn;
    kal_bool bsic_valid;
    kal_int8 bsic;
    kal_int32 frame_offset;
    kal_int32 ebit_offset;
} mpal_rr_standby_gsm_report_cgi_bsic_ind_struct;
#endif /* __LTE_RAT__ */
#endif /* defined(__UMTS_RAT__) || defined(__LTE_RAT__) */

#endif /* _MPAL2RR_STRUCT_H */
