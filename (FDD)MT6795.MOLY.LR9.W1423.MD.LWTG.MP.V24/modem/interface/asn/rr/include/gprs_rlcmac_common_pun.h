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
 *  gprs_rlcmac_common_pun.h
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
 *  FILENAME : gprs_rlcmac_common_pun.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifdef MTK_PEER 
#define IMP __declspec(dllimport) 
#else 
#define IMP 
#endif 
#ifndef _GPRS_RLCMAC_COMMON_PUN_H
#define _GPRS_RLCMAC_COMMON_PUN_H

/*Evelyn: Remove redundant header and file */
#include "kal_general_types.h"

#define ul_ctrl_header_struct_size(x) 1
IMP unsigned int ul_ctrl_header_struct_bits(void *);
IMP void ul_ctrl_header_struct_alloc(void *);
IMP void ul_ctrl_header_struct_dealloc(void *);
IMP unsigned int ul_ctrl_header_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ul_ctrl_header_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define data_blk_hdr_struct_size(x) 1
IMP unsigned int data_blk_hdr_struct_bits(void *);
IMP void data_blk_hdr_struct_alloc(void *);
IMP void data_blk_hdr_struct_dealloc(void *);
IMP unsigned int data_blk_hdr_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int data_blk_hdr_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define third_octet_struct_size(x) 1
IMP unsigned int third_octet_struct_bits(void *);
IMP void third_octet_struct_alloc(void *);
IMP void third_octet_struct_dealloc(void *);
IMP unsigned int third_octet_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int third_octet_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ctrl_blk_hdr_struct_bits(void *);
IMP void ctrl_blk_hdr_struct_alloc(void *);
IMP void ctrl_blk_hdr_struct_dealloc(void *);
IMP unsigned int ctrl_blk_hdr_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ctrl_blk_hdr_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int header_struct_bits(void *);
IMP void header_struct_alloc(void *);
IMP void header_struct_dealloc(void *);
IMP unsigned int header_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int header_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define ack_nack_desc_struct_size(x) 9
IMP unsigned int ack_nack_desc_struct_bits(void *);
IMP void ack_nack_desc_struct_alloc(void *);
IMP void ack_nack_desc_struct_dealloc(void *);
IMP unsigned int ack_nack_desc_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ack_nack_desc_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

/* Claire 041224 change : Move code from nstd_egprs_ack_pun.c to gprs_rlcmac_common_rest.c */
IMP unsigned int egprsack_nack_description_struct_bits(void *);
IMP void egprsack_nack_description_struct_alloc(void *);
IMP void egprsack_nack_description_struct_dealloc(void *);
IMP unsigned int egprsack_nack_description_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int egprsack_nack_description_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#endif 


