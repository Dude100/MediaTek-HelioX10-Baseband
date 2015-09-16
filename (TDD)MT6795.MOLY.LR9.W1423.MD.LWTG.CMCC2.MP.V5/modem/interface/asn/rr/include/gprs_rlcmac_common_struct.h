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
 *  gprs_rlcmac_common_struct.h
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
 *  FILENAME : gprs_rlcmac_common_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _GPRS_RLCMAC_COMMON_STRUCT_H
#define _GPRS_RLCMAC_COMMON_STRUCT_H

/*Evelyn: Remove redundant header and file */
#include "kal_general_types.h"
#include "rr_common_def.h"

typedef struct {
    kal_uint8 payloadtype;
    kal_uint8 spare;
    kal_uint8 retry;
} ul_ctrl_header_struct;

typedef struct {
    kal_uint8 rrbp; /* RELATIVE REVERSE BLOCK PERIOD*/
    kal_uint8 s_or_p; /* SUPPLEMENTARY AND POLLING BIT*/
    kal_uint8 usf; /* UPLINK STATE FLAG*/
} data_blk_hdr_struct;

typedef struct {
    kal_uint8 pr; /* power reduction*/
    kal_uint8 tfi; /* power reduction*/
    kal_uint8 dir; /* direction bit*/
} third_octet_struct;

typedef struct {
    kal_uint8 rrbp; /* RELATIVE REVERSE BLOCK PERIOD*/
    kal_uint8 s_or_p; /* SUPPLEMENTARY AND POLLING BIT*/
    kal_uint8 usf; /* UPLINK STATE FLAG*/
    kal_uint8 rbsn; /* RBSN*/
    kal_uint8 rti; /* radio transaction identifier*/
    kal_uint8 fs; /* final segment bit*/
    ispresent third_octet_choice_tag;
    union {
        third_octet_struct pthird_octet_choice;
    } third_octet_choice_value;
} ctrl_blk_hdr_struct;

typedef struct {
    pay_load_type_enum pay_load_tag;
    union {
        data_blk_hdr_struct data_blk_hdr;
        data_blk_hdr_struct ctrl_blk_hdr1;
        ctrl_blk_hdr_struct ctrl_blk_hdr2;
    } pay_load_value;
} header_struct;

typedef struct {
    kal_uint8 final_ack_indication; /* FINAL ACK INDICATION*/
    kal_uint8 starting_sequence_number; /* STARTING SEQUENCE NUMBER*/
    kal_uint8 rxd_blk_bitmap[8];
} ack_nack_desc_struct;

#ifdef __EGPRS_MODE__
typedef struct egprsack_nack_description_struct{
    kal_uint8  final_ack_indication;
    kal_uint16  begin_window;
    kal_uint16  end_window;
    kal_uint16  start_seq_no;
    kal_uint8  is_compressed;
    kal_uint8  color_code;
    kal_uint8  c_bitmap_length;
    kal_uint8 c_bitmap[16];
    kal_uint8   uc_bitmap_length;
    kal_uint8 uc_bitmap[40];
} egprsack_nack_description_struct;
#endif

/* Austin 040406: support PSI status */
typedef struct {
    ispresent tfi_choice_tag;
    union {
        kal_uint8 ul_tfi;
        kal_uint8 dl_tfi;
    } tfi_choice_value;
} global_tfistruct;
#endif 


