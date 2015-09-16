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
 *  nstd_mobile_alloc_peer_struct.h
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
 *  FILENAME : nstd_mobile_alloc_peer_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _NSTD_MOBILE_ALLOC_PEER_STRUCT_H
#define _NSTD_MOBILE_ALLOC_PEER_STRUCT_H

/*Evelyn: Remove redundant header and file */
#include "kal_general_types.h"
#include "rr_common_def.h"

typedef struct {
    kal_uint8 ma_length; /* MA*/
    /* Simon 20060907: for Columbia EDGE FT: MA length 43 => 5 bits are not enough */
    //kal_uint32 ma_bitmap_bits:5;
    kal_uint8 ma_bitmap_bits;
    kal_uint32 ma_bitmap; /* MA BITMAP*/
    /* Lanslo 20060909: for Columbia EDGE FT => MAX MA length = 1 to 64 bits (MA_LENGTH field is 6 bits)*/
    kal_uint32 ma_bitmap_2; /* MA BITMAP 2 */
} ma_bitmap_struct;

typedef struct {
    unsigned int no_fld;
    unsigned int fld_size;
    kal_uint8 *fld;
} arfcn_list_struct;

typedef struct {
    kal_uint8 arfcn_index; /* ARFCN INDEX*/
    ispresent arfcn_index_list_choice_tag;
    union {
        arfcn_list_struct p_arfcn_index_list;
    } arfcn_index_list_choice_value;
} arfcn_index_list_struct;

typedef struct {
    unsigned int no_field;
    unsigned int field_size;
    kal_uint8 *field;
} rr_rfl_num_list_peer_struct;

typedef struct {
    kal_uint8 rfl_num; /* RFL NUMBER*/
    ispresent rfl_num_list_choice_tag;
    union {
        rr_rfl_num_list_peer_struct p_rfl_num_list;
    } rfl_num_list_choice_value;
} rfl_list_struct;

typedef struct {
    kal_uint8 hsn; /* HSN*/
    ispresent rfl_num_list_choice_tag;
    union {
        rfl_list_struct p_rfl_num_list;
    } rfl_num_list_choice_value;
    ispresent ma_arfcn_choice_tag;
    union {
        ma_bitmap_struct a_ma_length_bitmap;
        arfcn_index_list_struct p_arfcn_index_list;
    } ma_arfcn_choice_value;
} rr_gprs_mobile_alloc_peer_struct;

typedef struct {
    kal_uint8 maio; /* MAIO*/
    kal_uint8 hsn; /* HSN*/
    kal_uint8 ma_freq_list_length; /* LENGTH OF MA FREQUENCY LIST*/
    kal_uint8 no_ma_freq_list_contents;
    kal_uint8 ma_freq_list_contents_size;
    kal_uint8 *ma_freq_list_contents; /* MA FREQ LIST CONTENT*/
} direct_encode2struct;
#endif 


