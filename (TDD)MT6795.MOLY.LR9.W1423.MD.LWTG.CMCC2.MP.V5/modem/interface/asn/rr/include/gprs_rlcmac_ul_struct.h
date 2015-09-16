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
 *  gprs_rlcmac_ul_struct.h
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


/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************
 *  FILENAME : gprs_rlcmac_ul_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _GPRS_RLCMAC_UL_STRUCT_H
#define _GPRS_RLCMAC_UL_STRUCT_H

/*Evelyn: Remove redundant header and file */
#include "kal_general_types.h"
#include "rr_common_def.h"
#include "gprs_rlcmac_common_struct.h"
#include "nstd_pkt_meas_report_struct.h"

typedef struct {
    kal_uint16 uarfcn; /* UARFCN*/
    kal_uint8 diversity; /* DIVERSITY*/
    ispresent bandwidth_fdd_tag;
    union {
        kal_uint8 p_bw_fdd;
    } bandwidth_fdd_value;
    kal_uint16 scrambling_code; /* SCRAMBLING CODE*/
} utran_fdd_struct;

typedef struct {
    kal_uint16 uarfcn; /* UARFCN*/
    kal_uint8 diversity; /* DIVERSITY*/
    ispresent bandwidth_tdd_tag;
    union {
        kal_uint8 p_bw_tdd;
    } bandwidth_tdd_value;
    kal_uint16 cell_parameter; /* CELL PARAMETER*/
    kal_uint8 sctd; /* Sync Case TSTD*/
} utran_tdd_struct;

typedef struct {
    ispresent utran_fdd_tag;
    union {
        utran_fdd_struct p_utran_fdd;
    } utran_fdd_value;
    ispresent utran_tdd_tag;
    union {
        utran_tdd_struct p_utran_tdd;
    } utran_tdd_value;    
} add_3G_r99_struct;

typedef struct {
    ul_ctrl_header_struct header; /* HEADER STRUCT*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint32 tlli; /* TLLI*/
    kal_uint16 arfcn; /* ARFCN*/
    kal_uint8 bsic; /* BSIC*/
    kal_uint8 cause; /* CAUSE*/
    ispresent add_3G_r99_choice_tag;
    union {
        add_3G_r99_struct p_add_3G_r99;
    } add_3G_r99_choice_value;
} pkt_cell_change_failure_msg;

typedef struct {
    ispresent i_level_choice0_tag;
    union {
        kal_uint8 p_leveln0;
    } i_level_choice0_value;
    ispresent i_level_choice1_tag;
    union {
        kal_uint8 p_leveln1;
    } i_level_choice1_value;
    ispresent i_level_choice2_tag;
    union {
        kal_uint8 p_leveln2;
    } i_level_choice2_value;
    ispresent i_level_choice3_tag;
    union {
        kal_uint8 p_leveln3;
    } i_level_choice3_value;
    ispresent i_level_choice4_tag;
    union {
        kal_uint8 p_leveln4;
    } i_level_choice4_value;
    ispresent i_level_choice5_tag;
    union {
        kal_uint8 p_leveln5;
    } i_level_choice5_value;
    ispresent i_level_choice6_tag;
    union {
        kal_uint8 p_leveln6;
    } i_level_choice6_value;
    ispresent i_level_choice7_tag;
    union {
        kal_uint8 p_leveln7;
    } i_level_choice7_value;
} level_struct;

typedef struct {
    level_struct interf_level_struct[8];
} interference_level_struct;

typedef struct {
    kal_uint8 ext_report_type; /* EXT REPORTING TYPE*/
    ispresent ext_report_choice_tag;
    union {
        level_struct p_ext_meas_report;
    } ext_report_choice_value;
    kal_uint8 no_freq_bisc2;
    kal_uint8 freq_bisc2_size;
    freq_bisc_struct *freq_bisc2; /* FREQ BISC */
} ext_meas_report_struct;

#ifdef __R99__
typedef struct {
    kal_uint8 ba_used; /* BA_USED*/
    kal_uint8 umts_ba_used; /* 3*/
} ba_used_struct;

typedef struct {
    ispresent psi3chng_mark_choice_tag;
    union {
        ba_used_struct a_psi3chng_mark;
        kal_uint8 p_psi3chng_mark;
    } psi3chng_mark_choice_value;
    kal_uint8 pmo_used; /* PMO_USED*/
} pmo_used_struct;

typedef struct {
    ispresent pmo_used_choice_tag;
    union {
        pmo_used_struct p_pmo_used;
    } pmo_used_choice_value;
    ispresent umts_meas_rp_choice_tag;
/*    
    union {
    } umts_meas_rp_choice_value;
*/    
} pmr_add_r99_struct;

typedef struct {
    kal_uint8 rxlev_serving_cell; 
    ispresent interf_choice_tag;
    union {
        kal_uint8 p_interf_serving_cell;
    } interf_choice_value;
} serving_cell_data_struct;

typedef struct {
    kal_uint8 bcch_freq_ncell; 
    kal_uint8 bsic; 
    kal_uint8 rxlev; 
} rp_bsic_struct;

typedef struct {
    ispresent reporting_quantity_choice_tag;
    union {
        kal_uint8 p_reporting_quantity;
    } reporting_quantity_choice_value;
} reporting_quantity_struct;

typedef struct {
    ispresent invalid_bsic_choice_tag;
    union {
        rp_bsic_struct p_invalid_bsic;
    } invalid_bsic_choice_value;
} invalid_bsic_struct;

typedef struct {
    kal_uint8 nc_mode; 
    ispresent psi3_chng_mark_choice_tag;
    union {
        ba_used_struct a_psi3_chng_mark;
        kal_uint8 p_psi3_chng_mark;
    } psi3_chng_mark_choice_value;
    kal_uint8 pmo_used; 
    kal_uint8 bsic_seen; 
    kal_uint8 scale; 
    ispresent serving_cell_data_choice_tag;
    union {
        serving_cell_data_struct p_serving_cell_data;
    } serving_cell_data_choice_value;
    kal_uint8 no_repeated_invalid_bsic;
    kal_uint8 repeated_invalid_bsic_size;
    invalid_bsic_struct *repeated_invalid_bsic; 
    kal_uint8 no_reporting_quantity;
    kal_uint8 reporting_quantity_size;	    
    ispresent bitmap_reporting_choice_tag;
    union {
        reporting_quantity_struct *p_bitmap_reporting;
    } bitmap_reporting_choice_value;
} enh_nc_meas_rep_struct;

#ifdef __UMTS_RAT__
typedef struct {
   kal_uint8 cell_index;
   kal_uint8 rep_quan;
} umts_cell_rep_struct;

typedef struct {
    kal_uint8 num_umts_cell; /* FREQUENCY N*/
	ispresent umts_cell_reporting_choice_tag;
	umts_cell_rep_struct *u_cell_reporting;
} umts_meas_rep_struct;
#endif

#endif

typedef struct {
    ul_ctrl_header_struct header; /* HEADER STRUCT*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint32 tlli; /* TLLI*/
    ispresent psi5chng_mark_choice_tag;
    union {
        kal_uint8 p_psi5chng_mark;
    } psi5chng_mark_choice_value;
    ispresent nc_meas_report_choice_tag;
    union {
        nc_meas_rep_struct a_nc_meas_report;
        ext_meas_report_struct p_ext_meas_report;
    } nc_meas_report_choice_value;
    ispresent umts_meas_report_choice_tag;
#ifdef __UMTS_RAT__
    union {
        umts_meas_rep_struct u_umts_meas_report;
    }nc_umts_meas_report_choice_value;
#endif
#ifdef __R99__
    ispresent r99_choice_tag;
    union {
        pmr_add_r99_struct p_r99_choice;
    } r99_choice_value;
#endif
} pkt_meas_report_struct;

#ifdef __R99__
typedef struct {
    ul_ctrl_header_struct header; 
    kal_uint8 msgtype; 
    kal_uint32 tlli; 
    enh_nc_meas_rep_struct enh_nc_meas_rep; 
} pkt_enh_meas_report_struct;
#endif

typedef struct {
    kal_uint8 peak_thru_class; /* PEAK THRUPUT CLASS*/
    kal_uint8 radio_priority; /* RADIO PRIORITY*/
    kal_uint8 rlc_mode; /* RLC MODE*/
    kal_uint8 llc_pdu_type; /* LLC PDU TYPE*/
    kal_uint16 rlc_octet_count; /* RLC OCTET COUNT*/
} ch_request_desc_struct;

typedef struct {
    ispresent ilevel_choice_tag;
    union {
        kal_uint8 p_ilevel_tn;
    } ilevel_choice_value;
} ilevel_tn_struct;

typedef struct {
    kal_uint8 c_value; /* C-VALUE*/
    kal_uint8 rx_qual; /* RXQUAL*/
    kal_uint8 sign_var; /* SIGN-VAR*/
    ilevel_tn_struct i_level_tn_value[8];
} ch_quality_report_struct;

typedef struct {
    ul_ctrl_header_struct header; /* HEADER STRUCT*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint8 dn_lnk_tfi; /* DOWN LINK TFI*/
    ack_nack_desc_struct ack_nack2; /* ACKNACKDESCSTRUCT*/
    ispresent ch_req_desc_choice_tag;
    union {
        ch_request_desc_struct p_ch_req_desc;
    } ch_req_desc_choice_value;
    ch_quality_report_struct ch_qua_report; /* ch_quality_report_struct*/
} pkt_dn_link_ack_nack;

/* Austin 040406: support PSI status */
typedef struct {
    kal_uint8 psix_msgtype; /* PSI MSG TYPE */
    kal_uint8 psix_chng_mark; /* PSI CHANGE MARK */
    ispresent instance_bitmap_tag;
    kal_uint8 psix_count;  /* PSIX_COUNT */
    kal_uint16 instance_bitmap;
} psi_msg_struct;

typedef struct {
    unsigned int no_psi_msg;
    psi_msg_struct psi_msg_list[10];   /* Rel99: PSI2, 3, 3bis, 4, 5, 3ter, 3qualter, 6, 7, 8 */
    kal_uint8 additional_msg_type;
} psi_msg_list_struct;

typedef struct {
    kal_uint8 psix_msgtype; /* PSI MSG TYPE */
} unknown_psi_msg_struct;

typedef struct {
    unsigned int no_unknown_psi_msg;
    unknown_psi_msg_struct unknown_psi_msg_list[1]; /* not realy used now */
    kal_uint8 additional_msg_type;
} unknown_psi_msg_list_struct;

typedef struct {
    ul_ctrl_header_struct header; /* HEADER STRUCT*/
    kal_uint8 msgtype; /* MSG TYPE*/
    global_tfistruct global_tfi; /* GLOBAL TFI */
    kal_uint8 pbcch_chng_mark;  /* PBCCH CHANGE MARK */
    psi_msg_list_struct psi_msg_list;
    unknown_psi_msg_list_struct unknown_psi_msg_list;
} pkt_psi_status_struct;


#ifdef __GERAN_R4__
typedef struct
{
    kal_uint16 arfcn; /* ARFCN*/
    kal_uint8 bsic; /* BSIC*/
}cell_2g_struct;

typedef struct
{
    ispresent cell_2G_choice_tag;
    cell_2g_struct cell_2g;
    ispresent cell_3G_r6_choice_tag;
    add_3G_r99_struct cell_3g;
    kal_uint8 cell_rep_quan;
}ccn_target_cell_struct;

typedef struct
{
   ul_ctrl_header_struct  header;
   kal_uint8 msgtype;       
   global_tfistruct global_tfi;
   ccn_target_cell_struct ccn_target_cell;
   kal_bool ba_or_psi3_used;
   kal_bool ba_used;
   kal_uint8 psi3_change_mark;
   kal_uint8 pmo_used;
   kal_uint8 pccn_sending; /* It re-send or not*/ 
   nc_meas_rep_struct  ccn_measurement_report;      /* This struct is identical to the NC Measurement Report struct 
        specified in the PACKET MEASUREMENT REPORT message with the exception that the NC_MODE parameter 
        is not part of the struct. We will skip nc_mode in encode function*/
#ifdef __UMTS_RAT__
   ispresent umts_meas_report_choice_tag;
   
   ispresent umts_ba_used_tag;
   kal_bool umts_ba_used;
    union {
        umts_meas_rep_struct u_umts_meas_report;
    }nc_umts_meas_report_choice_value;
#endif
} pkt_cell_change_notification_struct;

/*Byron: 2006/06/29: For Packet SI Status*/
typedef struct {
    kal_uint8 six_msgtype; /* SI MSG TYPE */
    kal_uint8 mess_rec; /* message received type */
    ispresent instance_bitmap_tag;
    kal_uint8 six_change_mark; /*SIX change mark*/
    kal_uint8 six_count;  /* SIX_COUNT */
    kal_uint16 instance_bitmap;
} si_msg_struct;

typedef struct {
    kal_uint8 no_si_msg;
#ifdef __GERAN_R6__
    si_msg_struct si_msg_list[10];   /* haizhoou 2010.06.24 for SI2n will be added under R6*/
#else
    si_msg_struct si_msg_list[9];
#endif
    kal_uint8 additional_msg_type;
} si_msg_list_struct;

typedef struct {
    kal_uint8 six_msgtype; /* SI MSG TYPE */
} unknown_si_msg_struct;

typedef struct {
    kal_uint8 no_unknown_si_msg;
    unknown_si_msg_struct unknown_si_msg_list[1]; /* not realy used now */
    kal_uint8 additional_msg_type;
} unknown_si_msg_list_struct;

typedef struct {
    ul_ctrl_header_struct header; /* HEADER STRUCT*/
    kal_uint8 msgtype; /* MSG TYPE*/
    global_tfistruct global_tfi; /* GLOBAL TFI */
    kal_uint8 bcch_chng_mark;  /* PBCCH CHANGE MARK */
    si_msg_list_struct si_msg_list;
    unknown_si_msg_list_struct unknown_si_msg_list;
} pkt_si_status_struct;

#endif

#endif 


