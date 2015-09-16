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
 *  psipeer_struct.h
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
 *  FILENAME : psipeer_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _PSIPEER_STRUCT_H
#define _PSIPEER_STRUCT_H

/* Suggest Add for RHR */
#include "rr_common_def.h"
#include "gprs_rlcmac_common_struct.h"
#include "gprs_rlcmac_peer_struct.h"
#include "gprs_rlcmac_dl_struct.h"
#include "nstd_gprsmobileiestruct_struct.h"
#include "meascell_struct.h"
#include "nstd_psi_ie_struct.h"

typedef struct {
    kal_uint8 pan_dec; /* PAN_DEC*/
    kal_uint8 pan_inc; /* PAN_INC*/
    kal_uint8 pan_max; /* PAN_MAX*/
} panstruct;

typedef struct {
    kal_uint8 egprs_pkt_channel_req; /* EGPRS PACKET CHANNEL REQUEST*/
    kal_uint8 bep_period; /* BEP_PERIOD*/
} egprs_params_struct;

typedef struct {
    kal_uint8 extension_len; /* EXTENSION LEN*/
    ispresent egprs_info_choice_tag;
    union {
        egprs_params_struct p_egprs_info;
    } egprs_info_choice_value;
    kal_uint8 pfc_feature_mode; /* PFC FEATURE MODE*/
    kal_uint8 DTM_support; /* DTM SUPPORT*/
    kal_uint8 bss_paging_coord; /* BSS PAGING COORDINATION*/
} extensionstruct;

typedef struct {
    kal_uint8 nmo; /* NMO*/
    kal_uint8 t3168; /* T3168*/
    kal_uint8 t3192; /* T3192*/
    kal_uint8 drx_timer_max; /* DRX_TIMER_MAX*/
    kal_uint8 access_burst_type; /* ACCESS_BURST_TYPE*/
    kal_uint8 control_ack_type; /* CONTROL_ACK_TYPE*/
    kal_uint8 bs_cv_max; /* BS_CV_MAX*/
    ispresent ch201_tag;
    union {
        panstruct ppanstruct;
    } ch201_value;
    ispresent ch202_tag;
    union {
        extensionstruct pextension;
    } ch202_value;
} gprscelloptionsstruct;

typedef struct {
    kal_uint8 perslvlseq[4];
} perchseqstruct;

typedef struct {
    kal_uint8 bspcc; /* BS_PCC_REL*/
    kal_uint8 bspbcch; /* BS_PBCCH_BLKS*/
    kal_uint8 bspag; /* BS_PAGE_BLKS_RES*/
    kal_uint8 bsprach; /* BS_PRACH_BLKS*/
} pccchorgparamstruct;

typedef struct {
    kal_uint8 mscr; /* 1*/
    kal_uint8 sgsnr; /* 1*/
} sgsnr_mscr_struct;

typedef struct {
    header_struct header; /* HEADERSTRUCT*/
    kal_uint8 msgtype; /* msgtype*/
    kal_uint8 pagemode; /* PAGE MODE*/
    kal_uint8 pbcchchangemark; /* PBCCH CHANGE MARK*/
    kal_uint8 psichangefield; /* PSI CHANGE FIELD*/
    kal_uint8 psi1repeatfield; /* PSI1 REPEAT FIELD*/
    kal_uint8 psicountlr; /* PSI COUNT LR*/
    ispresent ch204_tag;
    union {
        kal_uint8 ppsicount;
    } ch204_value;
    kal_uint8 measurementorder; /* MEASUREMENT ORDER*/
    gprscelloptionsstruct gprscelloptions; /* GPRS CELL OPTIONS*/
    prach_ctrl_params_struct prachcontrolparam; /* PRACH CONTROL PARAMETERS*/
    pccchorgparamstruct pccchorgparam; /* PRACH ORGANISATION PARAMETERS*/
    global_pwr_ctrl_params_struct globalpowerctlpar; /* GLOBAL POWER CONTROL PARAMETERS*/
    kal_uint8 psi_status_ind; /* PSI STATUS IND*/
    ispresent chnwrel_tag;
    union {
        sgsnr_mscr_struct psgsnr;
    } chnwrel_value;
} psi1msg;

typedef struct {
    kal_uint8 location_area_identification[5];
    kal_uint8 rac; /* ROUTING AREA CODE*/
    kal_uint16 cell_identity; /* CELL IDENTITY*/
} cellidentificationstruct;

typedef struct {
    kal_uint8 att; /* ATTACH/DETACH ALLOWED*/
    ispresent ch205_tag;
    union {
        kal_uint8 pt3212;
    } ch205_value;
    kal_uint8 neci; /* HALF RATE SUPPORT*/
    kal_uint8 pwrc; /* POWER CONTROL INDICATOR*/
    kal_uint8 dtx; /* DTX INDICATOR*/
    kal_uint8 radiolink_timeout; /* TIMER FOR RR CONNECTION*/
    kal_uint8 bs_agblks_res; /* BLOCKS RESERVED FOR ACCESS
       GRANT*/
    kal_uint8 ccch_conf; /* CHANNELS CONFIGURATION FOR
       CCCH*/
    kal_uint8 bs_pa_mfrms; /* NO OF 51 M-FRAMES BETWEEN
       PAGING*/
    kal_uint8 max_retrans; /* MAX NO OF RETRANSMISSIONS*/
    kal_uint8 tx_integer; /* NO OF SLOTS TO SPREAD TX*/
    kal_uint8 ec; /* EMERGENCY CALL ALLOWED*/
    kal_uint8 ms_tx_pwr; /* MAXIMUM TX POWER LEVEL*/
    ispresent ch206_tag;
    union {
        extensionstruct pextension;
    } ch206_value;
} nongprscelloption;

typedef struct {
    kal_uint8 rfl_number; /* RFL NUMBER*/
    kal_uint8 no_rfl_contents;
    kal_uint8 rfl_contents_size;
    kal_uint8 *rfl_contents; /* RFL CONTENTS*/
} reffreqstruct;

typedef struct {
    unsigned int no_reffreqlist;
    unsigned int reffreqlist_size;
    reffreqstruct *reffreqlist;
} reffreqliststruct;

typedef struct {
    unsigned int no_cellalloc;
    unsigned int cellalloc_size;
    kal_uint8 *cellalloc;
} cellallocationliststruct;

typedef struct {
    kal_uint8 manumber; /* MANUMBER*/
    gprsmobileiestruct gprsmobileie; /* GPRSMOBILEIESTRUCT*/
} gprsmobileallocationsstruct;

typedef struct {
    unsigned int no_gprsmobile;
    unsigned int gprsmobile_size;
    gprsmobileallocationsstruct *gprsmobile;
} gprsmobileallocationsliststruct;

typedef struct {
    kal_uint16 arfcn; /* ARFCN */
    kal_uint8 timeslotalloc; /* TIMESLOT ALLOC*/
} nonhoppingpcccchstruct;

typedef struct {
    unsigned int no_nh;
    unsigned int nh_size;
    nonhoppingpcccchstruct *nh;
} nonhoppingpccchlist;

typedef struct {
    kal_uint8 maio; /* MAIO*/
    kal_uint8 timeslotallocn; /* TIMESLOT ALLOCN*/
} hoppingpccchstruct;

typedef struct {
    unsigned int no_h;
    unsigned int h_size;
    hoppingpccchstruct *h;
} hoppingpccchlist;

typedef struct {
    kal_uint8 manumber; /* MA NUMBER */
    hoppingpccchlist hoppingpccch; /* HOPPING PCCCH LIST*/
} mahoppingpccchlist;

typedef struct {
    kal_uint8 tsc; /* TSC*/
    ispresent ch210_tag;
    union {
        nonhoppingpccchlist anonhopping;
        mahoppingpccchlist pnonhopping;
    } ch210_value;
} pccchstruct;

typedef struct {
    unsigned int no_pccchlist;
    unsigned int pccchlist_size;
    pccchstruct *pccchlist;
} pccchdesliststruct;

typedef struct {
    header_struct header; /* HEADER STRUCT*/
    kal_uint8 msgtype; /* msgtype */
    kal_uint8 pagemode; /* PAGE MODE*/
    kal_uint8 psi2changemark; /* PSI2 CHANGE MARK*/
    kal_uint8 psi2index; /* PSI2 INDEX*/
    kal_uint8 psi2count; /* PSI2 COUNT*/
    ispresent ch211_tag;
    union {
        cellidentificationstruct p_cell_identification;
    } ch211_value;
    ispresent ch212_tag;
    union {
        nongprscelloption p_non_gprscell_options;
    } ch212_value;
    reffreqliststruct ref_freqlst;
    cellallocationliststruct cell_allocation;
    gprsmobileallocationsliststruct gprs_mobile_allocations;
    pccchdesliststruct pccch_des;
} psi2msg;

typedef struct {
    kal_uint8 cellbaracess; /* CELL BAR ACCESS 2*/
    kal_uint8 excacc; /* EXC_ACC*/
    kal_uint8 gprsmin; /* GPRS_RXLEV_ACCESS_MIN*/
    kal_uint8 gprscch; /* GPRS MS TXPWR MAX CCH*/
    ispresent ch213_tag;
    union {
        hcs_struct phcs;
    } ch213_value;
    kal_uint8 multi_band_reporting; /* MULTI BAND REPORTING*/
} sercellparastruct;

typedef struct {
    kal_uint8 gprscellhys; /* GPRS CELL RESELECT HYSTERESIS*/
    kal_uint8 chyst; /* C31 HYST*/
    kal_uint8 cqual; /* C32 QUAL*/
    kal_uint8 randomaccretry; /* RANDOM ACCESS RETRY*/
    ispresent ch214_tag;
    union {
        kal_uint8 ptresel;
    } ch214_value;
    ispresent ch215_tag;
    union {
        kal_uint8 prahys;
    } ch215_value;
} gencellparastruct;

typedef struct {
    header_struct header; /* HEADERSTRUCT*/
    kal_uint8 msgtype; /* msgtype */
    kal_uint8 pagemode; /* PAGE MODE*/
    kal_uint8 psi3chmark; /* PSI3 CHANGE MARK*/
    kal_uint8 psi3biscount; /* PSI3 BSI COUNT*/
    sercellparastruct sercellpara; /* SERVING CELL PARAMETERS*/
    gencellparastruct gencellpara; /* GENERAL CELL SELECTION PARAMETER*/
    unsigned int no_neighcellpara;
    unsigned int neighcellpara_size;
    neighcellparastruct *neighcellpara;
} psi3msg;

typedef struct {
    kal_uint8 manumber; /* MA_NUMBER*/
    kal_uint8 maio; /* MAIO*/
} chgrpstruct;

typedef struct {
    ispresent ch222_tag;
    union {
        kal_uint16 arfcn;
        chgrpstruct pchgrp;
    } ch222_value;
    kal_uint8 timeslotalloc; /* TIMESLOT ALLOCATION*/
} channelgroupstruct;

typedef struct {
    header_struct header; /* HEADERSTRUCT*/
    kal_uint8 msgtype; /* MSGTYPE */
    kal_uint8 pagemode; /* PAGE MODE*/
    kal_uint8 psi4chmark; /* PSI CHANGE MARK*/
    kal_uint8 psi4index; /* PSI4_INDEX*/
    kal_uint8 psi4count; /* PSI4_COUNT*/
    channelgroupstruct chgrp;
    unsigned int no_chlist;
    unsigned int chlist_size;
    channelgroupstruct *chlist;
} psi4msg;

typedef struct {
    kal_uint8 nw_ctrl_order; /* NETWORK CONTROL ORDER*/
    ispresent nc_list_choice_tag;
    union {
        nc_list_struct p_nc_list;
    } nc_list_choice_value;
} nc_meas_para_struct;

typedef struct {
    header_struct header; /* HEADERSTRUCT*/
    kal_uint8 msgtype; /* MSGTYPE */
    kal_uint8 pagemode; /* PAGE MODE*/
    kal_uint8 psi5chmark; /* PSI CHANGE MARK*/
    kal_uint8 psi5index; /* PSI5_INDEX*/
    kal_uint8 psi5count; /* PSI5_COUNT*/
    ispresent nc_meas_choice_tag;
    union {
        nc_meas_para_struct p_nc_meas_params;
    } nc_meas_choice_value;
    ispresent ext_meas_choice_tag;
    union {
        ext_meas_params_struct p_extmeas_params;
    } ext_meas_choice_value;
} psi5msg;

typedef struct {
    kal_uint8 si13chgmark; /* SI13 CHG MARK*/
    gprsmobileiestruct gprsmoballocation; /* GPRS MOBILE ALLOC IE rr_gprs_mobile_alloc_peer_struct*/
} psimsgstruct;

typedef struct {
    add_enum ch228_tag;
    union {
        kal_uint16 arfcn;
        kal_uint8 maio;
    } ch228_value;
} bcchcarstruct;

typedef struct {
    kal_uint8 pb; /* pb*/
    kal_uint8 tsc; /* TSC*/
    kal_uint8 tn; /* TN*/
    bcchcarstruct bcchcar; /* BCCHCARSTRUCT*/
} pbcchdescstruct;

typedef struct {
    kal_uint8 alpha;
    kal_uint8 tavgw;
    kal_uint8 tavgt;
    kal_uint8 pcmeaschan;
    kal_uint8 navgi;
} pwrcontparastruct;

typedef struct {
    kal_uint8 rac; /* RAC*/
    kal_uint8 spgc_ccch_sup; /* SPGC CCCH SUP*/
    kal_uint8 priacc_thr; /* PRIORITY ACC THR*/
    kal_uint8 nwcontrolord; /* NW CONTROL ORDER*/
    gprscelloptionsstruct gprscellopt; /* GPRS CELL OPTIONS*/
    pwrcontparastruct powconpara; /* PWRCONPARASTRUCT*/
} apbcchstruct;

typedef struct {
    kal_uint8 psi1_rep_per; /* PSI1 REPEAT PERIOD*/
    pbcchdescstruct pbcch; /* PBCCHDESCSTRUCT*/
} ppbcchstruct;

typedef struct {
    header_struct header; /* HEADERSTRUCT*/
    kal_uint8 msgtype; /* MSGTYPE */
    kal_uint8 pagemode; /* PAGE MODE*/
    kal_uint8 bcch_chg_mark; /* BCCH CHG MARK*/
    kal_uint8 sichgfield; /* SI CHG FIELD*/
    ispresent ch229_tag;
    union {
        psimsgstruct ppsi13;
    } ch229_value;
    ispresent ch230_tag;
    union {
        apbcchstruct apbcch;
        ppbcchstruct ppbcch;
    } ch230_value;
    ispresent sgsnr_choice_tag;
    union {
        kal_uint8 psgsnr;
    } sgsnr_choice_value;
} psi13msg;

typedef struct {
    kal_uint8 psixct;
    kal_uint8 no_instbitmap;
    kal_uint8 instbitmap_size;
    kal_uint8 *instbitmap;
} psixstruct;

typedef struct {
    kal_uint8 messagtype;
    kal_uint8 psixchmk; /* PSIX CHANGE MARK*/
    ispresent ch231_tag;
    union {
        psixstruct psix;
    } ch231_value;
} psimsgliststruct1;

typedef struct {
    unsigned int no_psimsg;
    unsigned int psimsg_size;
    psimsgliststruct1 *psimsg;
    kal_uint8 addmsgtype; /* ADDTIONAL MSG TYPE*/
} psimsgliststruct;

typedef struct {
    unsigned int no_mesgtype;
    unsigned int mesgtype_size;
    kal_uint8 *mesgtype;
    kal_uint8 addmsgtype; /* ADDITIONAL MSG TYPE*/
} unpsimsgliststruct;

typedef struct {
    header_struct header; /* HEADERSTRUCT*/
    kal_uint8 msgtype; /* MSGTYPE */
    kal_uint8 messtype; /* MESSAGE TYPE*/
    global_tfistruct globaltfi; /* GLOBALTFI*/
    kal_uint8 pbcchchmk; /* PBCCH CHANGE MARK*/
    unsigned int no_rpsimsglist;
    unsigned int rpsimsglist_size;
    psimsgliststruct *rpsimsglist;
    unpsimsgliststruct unpsimsglist; /* UNPSIMSGLST STRUCT*/
} pktpsistatus;

typedef struct {
    header_struct header; /* HEADER STRUCT*/
    kal_uint8 msgtype; /* MSG TYPE*/
    kal_uint8 pagemode; /* PAGE MODE*/
    kal_uint8 psi3chmk; /* PS3 CH MARK*/
    kal_uint8 psi3bisind; /* PSI3 BIS INDEX*/
    kal_uint8 psi3biscnt; /* PSI3 BIS COUNT*/
    unsigned int no_neighcellpara1;
    unsigned int neighcellpara1_size;
    neighcellparastruct *neighcellpara1;
    unsigned int no_neighcellpara2;
    unsigned int neighcellpara2_size;
    neighcellpara2struct *neighcellpara2;
} psi3bismsg;
#endif 


