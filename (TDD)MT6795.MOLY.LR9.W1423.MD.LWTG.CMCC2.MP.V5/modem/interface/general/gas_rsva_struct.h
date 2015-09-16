/*******************************************************************************
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *    gas_rsva_struct.h
 *
 * Project:
 * --------
 *    Gemini(WG+G)
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 ******************************************************************************/
#ifndef _GAS_RSVA_STRUCT_H_
#define _GAS_RSVA_STRUCT_H_

/* RHR suggest Add */
#include "l3_inc_enums.h"
#include "kal_general_types.h"

#if defined(__GEMINI__) && defined(__UMTS_RAT__) && defined(__GSM_RAT__)

/*----------------------------------------------------------------------------*/
/*                             GAS (MPAL) to RSVA (RSVAG)                     */
/*----------------------------------------------------------------------------*/

typedef struct {    
    LOCAL_PARA_HDR
    gas_freq_scan_type_enum freq_scan_type;
    kal_bool is_full_band;
    kal_uint8 sid; /* session id */
}gas_rsvag_frequency_scan_start_req_struct;

typedef struct {
    LOCAL_PARA_HDR
    gas_freq_scan_stop_cause_enum cause;
    
    /* preemption session id, only used when cause=GAS_FREQ_SCAN_PREEMPTED */
    kal_uint8 preempt_sid;
}gas_rsvag_frequency_scan_stop_req_struct;

/*----------------------------------------------------------------------------*/
/*                              RSVA (RSVAG) to GAS (MPAL)                    */
/*----------------------------------------------------------------------------*/

typedef struct {
    LOCAL_PARA_HDR
    gas_freq_scan_result_enum result;
    kal_uint8 sid; /* session id */
}rsvag_gas_frequency_scan_start_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 preempt_sid; /* preemption session id */
}rsvag_gas_frequency_scan_preempt_ind_struct;

#endif
#endif
