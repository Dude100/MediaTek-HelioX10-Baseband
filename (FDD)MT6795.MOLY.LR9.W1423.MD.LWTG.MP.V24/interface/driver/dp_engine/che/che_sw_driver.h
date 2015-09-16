/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    che_sw_driver.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Cipher/Hash Engine software driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *============================================================================
 ****************************************************************************/

#ifndef _CHE_SW_Driver_H
#define _CHE_SW_Driver_H

#include "che_api.h"


#if !defined(__CHE_WIN32_STANDALONE__)

#define malloc get_ctrl_buffer
#define free   free_ctrl_buffer
#endif /* !defined(__CHE_WIN32_STANDALONE__) */

#include "kal_public_api.h"
#include "kal_general_types.h"

extern kal_bool che_sw_des(
                    STCHE *che_context,
                    CHE_TYPE type,
                    CHE_OPERATION_MODE mode,
                    CHE_ACTION act,
                    kal_uint8 *data_src,
                    kal_uint8 *data_dst,
                    kal_int32 length,
                    kal_bool last_block);
                        
extern kal_bool che_sw_aes(
                    STCHE *che_context,
                    CHE_OPERATION_MODE mode,
                    CHE_ACTION act,
                    kal_uint8 *data_src,
                    kal_uint8 *encryptedData,
                    kal_int32 length,
                    kal_bool last_block);

extern kal_bool che_sw_md5(
                    STCHE *che_context,
                    kal_uint8 *data_src,
                    kal_uint8 *data_dst,
                    kal_int32 length,
                    kal_bool last_block);

extern kal_bool che_sw_sha_1(
                    STCHE *che_context,
                    kal_uint8 *data_src,
                    kal_uint8 *data_dst,
                    kal_int32 length,
                    kal_bool last_block);

extern kal_bool che_sw_rc4(
                    STCHE *che_context,
                    CHE_OPERATION_MODE mode,
                    kal_uint8 *data_src,
                    kal_uint8 *data_dst,
                    kal_uint32 length,
                    kal_bool last_block);

extern kal_bool che_sw_md4(
                    STCHE *che_context,
                    kal_uint8 *data_src,
                    kal_uint8 *data_dst,
                    kal_int32 length,
                    kal_bool last_block);

extern kal_bool che_sw_mac(
                    CHE_TYPE type, 
                    STCHE *che_context,
                    kal_uint8 *data_src,
                    kal_uint8 *data_dst,
                    kal_int32 length,
                    kal_bool last_block);

extern kal_bool che_sw_rsa_key_from_string(
                    STCHE *che_context,
                    CHE_ACTION act,
                    kal_uint8 *data_src,
                    kal_uint8 *data_dst,
                    kal_int32 length,
                    kal_bool last_block);

extern kal_bool che_sw_dh(
                    STCHE *che_context,
                    CHE_ACTION act,
                    kal_uint8 *data_src,
                    kal_uint8 *data_dst,
                    kal_int32 length,
                    kal_bool last_block);

extern kal_int32 che_sw_rsa_generate_key( STCHE *ctx, kal_int32 nbits, kal_int32 exponent, 
                                                                                         kal_int32 (*f_rng)(void *), void *p_rng );
extern kal_int32 che_sw_rsa_public_key_cipher( 
                    STCHE *ctx,
                    kal_uint8 *src,
                    kal_uint32 src_len,
                    kal_uint8 *dst,
                    kal_uint32 *dst_len,
                    che_rsa_padding_mode_enum padding,
                    kal_bool encrypt);

extern kal_int32 che_sw_rsa_private_key_cipher( 
                    STCHE *ctx,
                    kal_uint8 *src,
                    kal_uint32 src_len,
                    kal_uint8 *dst,
                    kal_uint32 *dst_len,
                    che_rsa_padding_mode_enum padding,
                    kal_bool encrypt);

#if !defined(__CHE_NO_SHA256__)

extern kal_bool che_sw_sha_256(
	                STCHE *che_context,
	                kal_uint8 *data_src,
	                kal_uint8 *data_dst,
	                kal_int32 length,
	                kal_bool last_block);

extern kal_bool che_sw_sha_224(
	                STCHE *che_context,
	                kal_uint8 *data_src,
	                kal_uint8 *data_dst,
	                kal_int32 length,
	                kal_bool last_block);

#endif
#endif /* _CHE_SW_Driver_H */ 

