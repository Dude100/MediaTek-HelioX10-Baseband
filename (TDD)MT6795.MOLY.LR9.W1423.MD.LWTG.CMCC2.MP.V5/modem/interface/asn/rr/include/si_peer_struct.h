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
 *  si_peer_struct.h
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
 *  FILENAME : si_peer_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _SI_PEER_STRUCT_H
#define _SI_PEER_STRUCT_H

/* Suggest Add for RHR */
#include "rr_spare_bit.h"
#include "nstd_spare_bit_struct.h"
#include "l3_inc_enums.h"
#ifdef __PS_SERVICE__
#include "psipeer_struct.h"
#endif

typedef struct {
    kal_uint8 mscr;
    kal_uint8 att;
    kal_uint8 bsagblksres;
    kal_uint8 ccchconf;
    kal_uint8 spare; /* version check req*/
    kal_uint8 cbq2;
    kal_uint8 bspamfrms;
    kal_uint8 t3212val;
} ctrl_chan_desc_struct;

typedef struct {
    kal_uint8 dtx_or_spare;
    kal_uint8 pwrc;
    kal_uint8 dtx;
    kal_uint8 radio_link_timeout;
} celloptions;

typedef struct {
    kal_uint8 cell_resel_hyst;
    kal_uint8 txpwr_max_cch;
    kal_uint8 acs;
    kal_uint8 neci;
    kal_uint8 rxlev_acc_min;
} cellselectionparams;

typedef struct {
    kal_uint8 maxretrans;
    kal_uint8 txint;
    kal_uint8 cellbaracc;
    kal_uint8 re;
    kal_uint8 accctrlclass_2;
    kal_uint8 ec;
    kal_uint16 accctrlclass_1;
} rachparams;

typedef struct {
    rr_spare_bit_enum ch1_tag;
    union {
        kal_uint8 nchpos;
    } ch1_value;
} si1restoct;

typedef struct {
    kal_uint8 cbq;
    kal_uint8 cellreseloffset;
    kal_uint8 tempoffset;
    kal_uint8 penaltytime;
} selectionparams;

typedef struct {
    kal_uint8 offset;
} pwroffset;

typedef struct {
    kal_uint8 racolor;
    kal_uint8 si13pos;
} gprsind;

typedef struct {
    rr_spare_bit_enum ch1_tag;
    union {
        selectionparams selparams;
    } ch1_value;
    rr_spare_bit_enum ch12_tag;
    union {
        pwroffset pwroff;
    } ch12_value;
    SPARE_BIT_TYPE si2terind;
    SPARE_BIT_TYPE earlyclassmark;
    rr_spare_bit_enum ch2_tag;
    union {
        kal_uint8 scheduling;
    } ch2_value;
    rr_spare_bit_enum ch3_tag;
    union {
        gprsind gprsindication;
    } ch3_value;
} si_3_rest_octet_struct;

typedef struct {
    is_present_enum ID_tag;
    union {
        kal_uint32 lsa_id;
        kal_uint16 short_lsa_id;
    } ID_value;
} lsa_identity_struct;

typedef struct {
    unsigned int no_lsa_id_info;
    unsigned int lsa_id_info_size;
    lsa_identity_struct *lsa_id_info;
} lsa_id_info_struct;

typedef struct {
    kal_uint16 mcc;
    kal_uint16 mnc;
} mcc_mnc_struct;

typedef struct {
    kal_uint8 prio_thr;
    kal_uint8 lsa_offset;
    is_present_enum MCC_tag;
    union {
        mcc_mnc_struct mcc_mnc;
    } MCC_value;
} lsa_params_struct;

typedef struct {
    rr_spare_bit_enum ch1_tag;
    union {
        lsa_params_struct lsapara;
    } ch1_value;
    rr_spare_bit_enum ch2_tag;
    union {
        kal_uint16 cellid;
    } ch2_value;
    rr_spare_bit_enum ch3_tag;
    union {
        lsa_id_info_struct lsaidinfo;
    } ch3_value;
} si_4_rest_octet_s_struct;

typedef struct {
    rr_spare_bit_enum ch1_tag;
    union {
        selectionparams selparams;
    } ch1_value;
    rr_spare_bit_enum ch2_tag;
    union {
        pwroffset pwroff;
    } ch2_value;
    rr_spare_bit_enum ch3_tag;
    union {
        gprsind gprsindication;
    } ch3_value;
    rr_spare_bit_enum ch4_tag;
    union {
        kal_uint8 ibreak;
        si_4_rest_octet_s_struct si4_s;
    } ch4_value;
} si4restoct;

typedef struct {
    kal_uint8 maio;
    kal_uint8 hsn;
} maio;

typedef struct {
    kal_uint8 spare;
    kal_uint16 arfcn;
} arfcn_choice;

typedef struct {
    kal_uint8 chan_type;
    kal_uint8 tn;
    kal_uint8 tsc;
    is_present_enum h_tag;
    union {
        maio maioandhsn;
        arfcn_choice arfcn;
    } h_value;
} channeldesc;

typedef struct {
    kal_uint8 restruct;
    kal_uint8 nln;
    kal_uint8 callprio;
    kal_uint8 nlnstatus;
} pchinf;

typedef struct {
    rr_spare_bit_enum ch1_tag;
    union {
        pchinf pchinfo;
    } ch1_value;
    rr_spare_bit_enum ch2_tag;
    union {
        kal_uint8 vbsopts;
    } ch2_value;
} si6restoct;

typedef struct {
    unsigned int no_rfl_number;
    unsigned int rfl_number_size;
    kal_uint8 *rfl_number;
} rfl_number_struct;

typedef struct {
    is_present_enum ch1_tag;
    union {
        rfl_number_struct rfl_number;
    } ch1_value;
} rfl_number_list_struct;

typedef struct {
    kal_uint8 ma_length;
    kal_uint8 no_ma_bitmap;
    kal_uint8 ma_bitmap_size;
    kal_uint8 *ma_bitmap;
} ma_struct;

typedef struct {
    unsigned int no_arfcn_index;
    unsigned int arfcn_index_size;
    kal_uint8 *arfcn_index;
} arfcn_index_list1_struct;

typedef struct {
    is_present_enum ch1_tag;
    union {
        arfcn_index_list1_struct arfcn_index_list_struct;
    } ch1_value;
} si_arfcn_index_list_struct;

typedef struct {
    kal_uint8 hsn;
    is_present_enum ch1_tag;
    union {
        rfl_number_list_struct rfl_number_list;
    } ch1_value;
    is_present_enum ch2_tag;
    union {
        ma_struct ma_lengh_and_bitmap;
        si_arfcn_index_list_struct arfcn_index_list;
    } ch2_value;
} gprsmoballocstruct;

typedef struct {
    is_present_enum pbcchcarr_tag;
    union {
        kal_uint16 arfcn;
    } pbcchcarr_value;
} sinonhopppbcchcarr;

typedef struct {
    is_present_enum ch228_tag;
    union {
        kal_uint8 maio;
        sinonhopppbcchcarr nonhoppcarr;
    } ch228_value;
} sibcchcarstruct;

typedef struct {
    kal_uint8 pb; /* pb*/
    kal_uint8 tsc; /* TSC*/
    kal_uint8 tn; /* TN*/
    sibcchcarstruct bcchcar; /* BCCHCARSTRUCT*/
} sipbcchdescstruct;

typedef struct {
    kal_uint8 psi1_rep_per; /* PSI1 REPEAT PERIOD*/
    sipbcchdescstruct pbcch; /* PBCCHDESCSTRUCT*/
} sippbcchstruct;

#ifdef __PS_SERVICE__
typedef struct {
    kal_uint8 bcch_chg_mark; /* BCCH CHG MARK*/
    kal_uint8 sichgfield; /* SI CHG FIELD*/
    is_present_enum ch229_tag;
    union {
        psimsgstruct ppsi13;
    } ch229_value;
    is_present_enum ch230_tag;
    union {
        apbcchstruct apbcch;
        sippbcchstruct ppbcch;
    } ch230_value;
    rr_spare_bit_enum ch1_tag;
    union {
        kal_uint8 sgsnr;
    } ch1_value;
} si13restoct;
#endif

typedef struct {
    kal_uint8 format_id;
    kal_uint8 spare;
    kal_uint8 ca_arfcn_1;
    kal_uint8 ca_arfcn_2[15];
} CELL_CH_DESC_BITMAP0;

typedef struct {
    kal_uint8 nchpos;
} nch_position_struct;

typedef struct {
    rr_spare_bit_enum nch_present_tag;
    union {
        nch_position_struct nch_position;
    } nch_present_value;
} si_1_rest_octet_struct;

typedef struct {
    kal_uint8 l2pseudo_length;
    kal_uint8 skip_ind;
    kal_uint8 rr_mgmt_proto_disc;
    kal_uint8 si_type1msg_type;
    CELL_CH_DESC_BITMAP0 cell_ch_desc;
    rachparams rach_ctrl_params;
    si_1_rest_octet_struct si1rest_octets;
} si_1_struct;

typedef struct {
    kal_uint8 bitmap_1;
    kal_uint8 ext_ind;
    kal_uint8 ba_ind;
    kal_uint8 bitmap_2;
    kal_uint8 bitmap_3[15];
} neigh_cells_desc1_struct;

typedef struct {
    kal_uint8 bitmap_1;
    kal_uint8 multiband_reporting;
    kal_uint8 ba_ind;
    kal_uint8 bitmap_2;
    kal_uint8 bitmap_3[15];
} neigh_cells_desc2_struct;

typedef struct {
    kal_uint8 l2pseudo_length;
    kal_uint8 skip_ind;
    kal_uint8 rr_mgmt_proto_disc;
    kal_uint8 si_type2msg_type;
    neigh_cells_desc1_struct bcch_freq_list;
    kal_uint8 ncc_permitted;
    rachparams rach_ctrl_params;
} si_2_struct;

typedef struct {
    kal_uint8 rest_octet; /* TBD*/
} si_2bis_rest_octets_struct;

typedef struct {
    kal_uint8 l2pseudo_length;
    kal_uint8 skip_ind;
    kal_uint8 rr_mgmt_proto_disc;
    kal_uint8 si_type2bis_msg_type;
    neigh_cells_desc1_struct extbcch_freq_list;
    rachparams rach_ctrl_params;
    si_2bis_rest_octets_struct si2bis_rest_octets;
} si_2bis_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct {
    kal_uint8 mcc2;
    kal_uint8 mcc1;
    kal_uint8 mnc3;
    kal_uint8 mcc3;
    kal_uint8 mnc2;
    kal_uint8 mnc1;
} PLMN;

typedef struct {
    PLMN plmn;
    kal_uint16 la_code;
} LAI;

typedef struct {
    kal_uint8 l2pseudo_length;
    kal_uint8 skip_ind;
    kal_uint8 rr_mgmt_proto_disc;
    kal_uint8 si_type3msg_type;
    kal_uint16 cell_identity;
    LAI lai;
    ctrl_chan_desc_struct ctrl_ch_desc;
    celloptions cell_options;
    cellselectionparams cell_sel_params;
    rachparams rach_ctrl_params;
    si_3_rest_octet_struct si3rest_octets;
} si_3_struct;

typedef struct {
    kal_uint8 l2pseudo_length;
    kal_uint8 skip_ind;
    kal_uint8 rr_mgmt_proto_disc;
    kal_uint8 si_type4msg_type;
    LAI lai;
    cellselectionparams cell_sel_params;
    rachparams rach_ctrl_params;
} si_4_part1of4_struct;

typedef struct {
    kal_uint8 cbch_ch_descP;
    channeldesc cbch_ch_desc;
} si_4_part2of4_struct;

typedef struct {
    kal_uint8 macP;
    kal_uint32 mac;
} si_4_part3of4_struct;

typedef struct {
    si4restoct si4rest_octet;
} si_4_part4of4_struct;

typedef struct {
    si_4_part1of4_struct si4part1of4;
    si_4_part2of4_struct si4part2of4;
    si_4_part3of4_struct si4part3of4;
    si_4_part4of4_struct si4part4of4;
} si_4_struct;

typedef struct {
    kal_uint8 l2pseudo_length;
    kal_uint8 skip_ind;
    kal_uint8 rr_mgmt_proto_disc;
    kal_uint8 si_type5msg_type;
    neigh_cells_desc1_struct bcch_freq_list;
} si_5_struct;

typedef struct {
    kal_uint8 l2pseudo_length;
    kal_uint8 skip_ind;
    kal_uint8 rr_mgmt_proto_disc;
    kal_uint8 si_type5bis_msg_type;
    neigh_cells_desc1_struct extbcch_freq_list;
} si_5bis_struct;

typedef struct {
    kal_uint8 l2pseudo_length;
    kal_uint8 skip_ind;
    kal_uint8 rr_mgmt_proto_disc;
    kal_uint8 si_type5ter_msg_type;
    neigh_cells_desc2_struct extbcch_freq_list;
} si_5ter_struct;

typedef struct {
    kal_uint8 l2pseudo_length;
    kal_uint8 skip_ind;
    kal_uint8 rr_mgmt_proto_disc;
    kal_uint8 si_type6msg_type;
    kal_uint16 cell_identity;
    LAI lai;
    celloptions cell_options;
    kal_uint8 ncc_permitted;
    si6restoct si6rest_octets;
} si_6_struct;

typedef struct {
    kal_uint8 l2pseudo_length;
    kal_uint8 skip_ind;
    kal_uint8 rr_mgmt_proto_disc;
    kal_uint8 si_type7msg_type;
    si4restoct si7rest_octets;
} si_7_struct;

typedef struct {
    kal_uint8 l2pseudo_length;
    kal_uint8 skip_ind;
    kal_uint8 rr_mgmt_proto_disc;
    kal_uint8 si_type8msg_type;
    si4restoct si8rest_octets;
} si_8_struct;

typedef struct {
    kal_uint8 l2pseudo_length;
    kal_uint8 skip_ind;
    kal_uint8 rr_mgmt_proto_disc;
    kal_uint8 si_type9msg_type;
    rachparams rach_ctrl_params;
} si_9_part1of2_struct;

#ifdef __PS_SERVICE__
typedef struct {
    kal_uint8 l2pseudo_length;
    kal_uint8 skip_ind;
    kal_uint8 rr_mgmt_proto_disc;
    kal_uint8 si_type13msg_type;
    rr_spare_bit_enum ch1_tag;
    union {
        si13restoct si13rest_octets;
    } ch1_value;
} si_13_struct;
#endif

typedef struct {
    kal_uint8 l2pseudo_length;
    kal_uint8 skip_ind;
    kal_uint8 rr_mgmt_proto_disc;
    kal_uint8 si_type16msg_type;
    lsa_params_struct si16rest_octets;
} si_16_struct;

typedef struct {
    kal_uint8 l2pseudo_length;
    kal_uint8 skip_ind;
    kal_uint8 rr_mgmt_proto_disc;
    kal_uint8 si_type17msg_type;
    lsa_params_struct si17rest_octets;
} si_17_struct;

typedef struct {
    kal_uint8 non_gsm_proto_disc;
    kal_uint8 nrof_container_octets;
    kal_uint8 no_container;
    kal_uint8 container_size;
    kal_uint8 *container; /* nrof_container_octets */
} si_non_gsm_msg_struct;

typedef struct {
    kal_uint8 no_non_gsm_msg;
    kal_uint8 non_gsm_msg_size;
    si_non_gsm_msg_struct *non_gsm_msg; /* nrof_container_octets */
} SI18_REST_OCTETS;

typedef struct {
    kal_uint8 l2pseudo_length;
    kal_uint8 skip_ind;
    kal_uint8 rr_mgmt_proto_disc;
    kal_uint8 si_type13msg_type;
    SI18_REST_OCTETS si18rest_octets;
} si_18_struct;

typedef struct {
    kal_uint8 spare[20];
} SI_19_REST_OCTETS;

typedef struct {
    kal_uint8 l2pseudo_length;
    kal_uint8 skip_ind;
    kal_uint8 rr_mgmt_proto_disc;
    kal_uint8 si_type19msg_type;
    SI_19_REST_OCTETS si19rest_octets;
} si_19_struct;

typedef struct {
    kal_uint8 l2pseudo_length;
    kal_uint8 skip_ind;
    kal_uint8 rr_mgmt_proto_disc;
    kal_uint8 si_type20msg_type;
    SI18_REST_OCTETS si20rest_octets;
} si_20_struct;
#endif 


