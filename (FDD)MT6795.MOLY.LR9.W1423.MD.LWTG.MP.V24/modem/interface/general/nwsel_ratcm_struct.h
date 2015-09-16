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
 *   nwsel_ratcm_struct.h
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 * This file define the interface structure used by NWSEL_RATCM SAP
 *
 * Author:
 * -------
 * -------
 *
 ******************************************************************************/

#ifndef NWSEL_RATCM_STRUCT_H
#define NWSEL_RATCM_STRUCT_H

#include "l3_inc_enums.h"
#include "mcd_l3_inc_struct.h"
#include "l3_inc_local.h"
#include "as2nas_struct.h"
#include "mcd_l3_inc_gprs_struct.h"
#include "ps_public_enum.h"
#include "rsvas_enum.h"
#include "kal_public_defs.h"

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 eq_plmn_count;
    plmn_id_struct eq_plmn_id[MAX_NUM_EQ_PLMN]; /* The eq_plmn_id[0] should be RPLMN */
} nwsel_ratcm_eq_plmn_list_update_req_struct;

/* abstrated from mm_ratcm_regn_status_req */
#ifdef __REL8__
typedef struct {
    LOCAL_PARA_HDR  
    kal_uint8 r_eq_plmn_count;
    plmn_id_struct r_eq_plmn_id[MAX_NUM_EQ_PLMN];
} nwsel_ratcm_rplmn_eq_plmn_list_update_req_struct;
#endif

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 plmn_id_count;
    plmn_id_struct plmn_id[MAX_NUM_HPLMN]; //MAX_NUM_HPLMN: 4
} nwsel_ratcm_hplmn_info_update_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    rat_enum rat;
} nwsel_ratcm_signal_appear_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    rat_enum rat;
} nwsel_ratcm_cell_change_finish_ind_struct;

typedef struct {
    LOCAL_PARA_HDR  
    rat_enum rat_info;
} nwsel_ratcm_plmn_loss_info_update_req_struct;
#endif /* NWSEL_RATCM_STRUCT_H */
