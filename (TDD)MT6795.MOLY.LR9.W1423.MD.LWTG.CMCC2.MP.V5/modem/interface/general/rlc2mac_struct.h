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

/******************************************************************************
 * Filename:
 * ---------
 *	rlc2mac_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 * -------
 *
 *=============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *=============================================================================
 ******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _RLC2MAC_STRUCT_H
#define _RLC2MAC_STRUCT_H

/*Evelyn: Remove redundant header and file */
#include "rr_common_def.h"
#include "rlcmac_struct.h"
#include "kal_general_types.h"
#include "gprs_rlcmac_common_struct.h"

/* Evelyn 20090415: Merge R6 */
typedef struct multiple_res_req_struct rlc_mac_res_req_struct;

typedef struct tbf_rel_struct rlc_mac_tbf_rel_req_struct;

typedef struct {
    kal_uint8 payload_type;
    kal_uint8 cv;
    kal_uint8 stall_ind;
    kal_uint8 retry;
    kal_uint8 spare;
    kal_uint8 pfi_ind;
    kal_uint8 tfi;
    kal_uint8 tlli_ind;
    kal_uint8 bsn;
    kal_uint8 extn;
} ul_header_struct;

typedef struct {
    ul_header_struct gprs_hdr;
} ul_block_header_struct;

typedef struct {
    //ul_block_header_struct ulheader;
    kal_uint8 cs;
   #ifndef __MTK_TARGET__
    kal_uint8 data1[75];
    #else
    kal_uint8 *data1;
    #endif
    #ifdef __EGPRS_MODE__
    #ifndef __MTK_TARGET__
    kal_uint8 data2[75];
    #else
    kal_uint8 *data2;
    #endif
    kal_uint8 header[6];
    /* Claire 041208 change : Fill UL data header, blockDataPS1,  blockDataPS2 fields */
    kal_uint8 blockDataPS1;    // punturing scheme for EGPRS in the first RLC data block of one block
    kal_uint8 blockDataPS2;    // punturing scheme for EGPRS in the second RLC data block of one block
    #endif

    #ifdef __GERAN_FANR__
    kal_uint8 pan[4];
    #endif

} ul_data_block_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_uint8 res_req_blk;
    kal_uint8 no_rlc_mac_res_req;
    kal_uint8 rlc_mac_res_req_size;
    rlc_mac_res_req_struct *rlc_mac_res_req;
    kal_uint16 no_ul_blks;
    /* Evelyn 20090905: Modify for High multislot class */
    ul_data_block_struct ul_blks[MAX_TX_TIMESLOTS*2];
/* Evelyn 20090415: Merge R6 */
    #ifdef __MTBF__
    kal_uint8 ul_pfi;
    #endif
} rlc_mac_ul_data_ind_struct;

typedef struct {
    LOCAL_PARA_HDR
    ack_nack_desc_struct ack_nack_res;
    #ifdef __EGPRS_MODE__
    egprsack_nack_description_struct egprs_ack_nac_res;
    #endif
/* Evelyn 20090415: Merge R6 */
    #ifdef __MTBF__
    kal_uint8 dl_pfi;
    #endif
} rlc_mac_ack_res_struct;
#endif


