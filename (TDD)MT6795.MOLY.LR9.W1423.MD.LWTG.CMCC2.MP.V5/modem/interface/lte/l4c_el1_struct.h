/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   l4c_el1_struct.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   message and common structure definition between L4C and EL1 modules.
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * 	Disable band 40 if band40 PA is broken
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 ****************************************************************************/


#ifndef  _L4C_EL1_STRUCT_H_
#define  _L4C_EL1_STRUCT_H_

#include "kal_general_types.h"
#include "kal_public_defs.h"

/* MSG_ID_EL1_LTE_MAX_TX_PWR_RED_REQ */
typedef struct
{
    LOCAL_PARA_HDR

    kal_uint8   op;    // 1: for all band, 3,5: only for band, 4: reset
    kal_uint8   band;  // 1~64
    kal_uint8   para1; // 0~255, unit: 1/8 dB, (0~32 dB)
    kal_uint8   para2; // reserved
    kal_uint8   para3; // reserved
} el1_lte_max_tx_pwr_red_req_struct;


typedef enum
{
    EL1_EM_TST_CMD_FORCE_TX_PWR,
    EL1_EM_TST_CMD_END
} EL1_EM_TSTCmdType;

typedef struct
{
    kal_bool                    on;
    kal_bool                    duplex_mode;
    kal_uint8                   band;
    kal_uint8                   ul_bandwidth;
    kal_uint16                  ul_freq;
    kal_uint8                   tdd_cfg;
    kal_uint8                   tdd_sp_sf_cfg;
    kal_uint8                   vrb_start;
    kal_uint8                   vrb_len;
    kal_uint8                   mcs;
    kal_int16                   tx_power;
} EL1_EM_TSTCmd_ForceTxPwr_T;

typedef union
{
    EL1_EM_TSTCmd_ForceTxPwr_T  forceTxPwr;
} EL1_EM_TSTCmdParam;


/* MSG_ID_L4C_EL1_EM_TST_CONTROL_REQ */
typedef struct
{
    LOCAL_PARA_HDR

    kal_uint8                   src_id;
    EL1_EM_TSTCmdType           type;
    EL1_EM_TSTCmdParam          param;
} l4c_el1_em_tst_control_req_struct;


/* MSG_ID_L4C_EL1_EM_TST_CONTROL_CNF */
typedef struct
{
    LOCAL_PARA_HDR

    kal_uint8                   src_id;
    kal_bool                    success;
} l4c_el1_em_tst_control_cnf_struct;


/* MSG_ID_L4CEL1_B3_INFO_REQ */
typedef struct
{
    LOCAL_PARA_HDR

    kal_uint8                   type;  // 0: Off, 1: TCH, 2: BCCH
    kal_uint8                   index; // frequency index
                                       // 0:1850-1860 
                                       // 1:1860-1870
                                       // 2:1870-1875
                                       // 3:1875-1880
                                       // 4:1845-1850
    kal_uint16                  arfcn; // GSM arfcn
    kal_int16                   rssi;  // GSM rssi
    kal_uint8                   src;   // Sourcd id
} l4cel1_b3_info_req_struct;


/* MSG_ID_L4CEL1_B3_INFO_CNF */
typedef struct
{
    LOCAL_PARA_HDR

    kal_uint8                   result;// 1: success, 0: error
    kal_uint8                   src;   // Sourcd id
} l4cel1_b3_info_cnf_struct;

/* MSG_ID_L4CEL1_DISABLE_BAND_IND */
typedef struct
{
    LOCAL_PARA_HDR

	kal_uint8                   band;
} l4cel1_disable_band_ind_struct;
#endif


