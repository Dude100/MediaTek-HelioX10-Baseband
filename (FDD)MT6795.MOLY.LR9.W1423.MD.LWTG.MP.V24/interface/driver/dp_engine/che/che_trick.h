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
 *    che_trick.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   CHE Trick define.
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

#ifndef __CHE_TRICK_H__
#define __CHE_TRICK_H__

#define TRICK_CHE_MD5                     1 
#define TRICK_CHE_SHA224                 1
#define TRICK_CHE_SHA256                 1
#define TRICK_CHE_SHA1                    1
#define TRICK_CHE_DES                     1
#define TRICK_CHE_3DES                    1
#define TRICK_CHE_AES                     1
#define TRICK_CHE_MD4                     1
#define TRICK_CHE_MAC_MD5                 1
#define TRICK_CHE_MAC_SHA1                1
#define TRICK_CHE_MAC_SHA224                1
#define TRICK_CHE_MAC_SHA256                1
#define TRICK_CHE_RC4                     1
#define TRICK_CHE_RSA                     1
#define TRICK_CHE_DH                      1
#define TRICK_CHE_GEN_KEY                  1
#define TRICK_CHE_SET_KEY                  1
#define TRICK_CHE_SET_RC4_KEY                 1
#define TRICK_CHE_GET_KEY                  1
#define TRICK_CHE_DEL_KEY                  1
#define TRICK_CHE_GEN_RSA_KEY              1
#define TRICK_CHE_DEL_RSA_KEY              1
#define TRICK_CHE_SET_RSA_N                1                 
#define TRICK_CHE_SET_RSA_E                1             
#define TRICK_CHE_SET_RSA_D                1             
#define TRICK_CHE_SET_RSA_P                1             
#define TRICK_CHE_SET_RSA_Q                1             
#define TRICK_CHE_SET_RSA_dModPm1          1  
#define TRICK_CHE_SET_RSA_dModQm1          1  
#define TRICK_CHE_SET_RSA_qInvModP         1  
#define TRICK_CHE_SET_DH_P                 1 
#define TRICK_CHE_SET_DH_G                 1 
#define TRICK_CHE_SET_DH_SELF_PUBLIC       1 
#define TRICK_CHE_SET_DH_PEER_PUBLIC       1 
#define TRICK_CHE_SET_DH_PRIVATE           1 
#define TRICK_CHE_GET_DH_SELF_PUBLIC_LEN   1
#define TRICK_CHE_GET_DH_PRIVATE_LEN       1
#define TRICK_CHE_GET_DH_SECRET_LEN        1
#define TRICK_CHE_GET_DH_SELF_PUBLIC       1
#define TRICK_CHE_GET_DH_PRIVATE           1
#define TRICK_CHE_GET_DH_SECRET            1
#define TRICK_CHE_GET_RSA_N                     1
#define TRICK_CHE_GET_RSA_N_LEN             1
#define TRICK_CHE_GET_RSA_E                     1
#define TRICK_CHE_GET_RSA_E_LEN             1
#define TRICK_CHE_GET_RSA_D                     1
#define TRICK_CHE_GET_RSA_D_LEN             1
#define TRICK_CHE_GET_RSA_P                     1
#define TRICK_CHE_GET_RSA_P_LEN             1
#define TRICK_CHE_GET_RSA_Q                     1
#define TRICK_CHE_GET_RSA_Q_LEN             1
#define TRICK_CHE_GET_RSA_dModPm1        1
#define TRICK_CHE_GET_RSA_dModPm1_LEN   1
#define TRICK_CHE_GET_RSA_dModQm1           1
#define TRICK_CHE_GET_RSA_dModQm1_LEN   1
#define TRICK_CHE_GET_RSA_qInvModP            1
#define TRICK_CHE_GET_RSA_qInvModP_LEN     1

/* check it before execute key action functions */
extern void checkCHEKeyActionPerFix(STCHE *che_context, kal_uint8 *key);

/* execute GEN_KEY action */
extern void run_CHE_GEN_KEY_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute SET_KEY action */
extern void run_CHE_SET_KEY_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute SET_RC4_KEY action */
extern void run_CHE_SET_RC4_KEY_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute GET_KEY action */
extern void run_CHE_GET_KEY_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute DEL_KEY action */
extern void run_CHE_DEL_KEY_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

extern void run_CHE_GET_RSA_N_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);
extern void run_CHE_GET_RSA_N_LEN_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);
extern void run_CHE_GET_RSA_E_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);
extern void run_CHE_GET_RSA_E_LEN_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);
extern void run_CHE_GET_RSA_D_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);
extern void run_CHE_GET_RSA_D_LEN_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);
extern void run_CHE_GET_RSA_P_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);
extern void run_CHE_GET_RSA_P_LEN_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);
extern void run_CHE_GET_RSA_Q_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);
extern void run_CHE_GET_RSA_Q_LEN_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);
extern void run_CHE_GET_RSA_dModPm1_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);
extern void run_CHE_GET_RSA_dModPm1_LEN_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);
extern void run_CHE_GET_RSA_dModQm1_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);
extern void run_CHE_GET_RSA_dModQm1_LEN_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);
extern void run_CHE_GET_RSA_qInvModP_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);
extern void run_CHE_GET_RSA_qInvModP_LEN_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute GEN_RSA_KEY action */
extern void run_CHE_GEN_RSA_KEY_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);
      
/* execute DEL_RSA_KEY action */
extern void run_CHE_DEL_RSA_KEY_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute SET_RSA_N key action */
extern void run_CHE_SET_RSA_N_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute SET_RSA_E key action */
extern void run_CHE_SET_RSA_E_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute SET_RSA_D key action */
extern void run_CHE_SET_RSA_D_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute SET_RSA_P key action */
extern void run_CHE_SET_RSA_P_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);
  
/* execute SET_RSA_Q key action */
extern void run_CHE_SET_RSA_Q_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute SET_RSA_dModPm1 key action */
extern void run_CHE_SET_RSA_dModPm1_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute SET_RSA_dModQm1 key action */
extern void run_CHE_SET_RSA_dModQm1_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute SET_RSA_qInvModP key action */
extern void run_CHE_SET_RSA_qInvModP_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute SET_DH_P key action */
extern void run_CHE_SET_DH_P_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute SET_DH_G key action */
extern void run_CHE_SET_DH_G_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute SET_DH_SELF key action */
extern void run_CHE_SET_DH_SELF_PUBLIC_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute SET_DH_PEER_PUBLIC key action */
extern void run_CHE_SET_DH_PEER_PUBLIC_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute SET_DH_PRIVATE key action */
extern void run_CHE_SET_DH_PRIVATE_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);
   
/* execute GET_DH_SELF_PUBLIC_LEN key action */
extern void run_CHE_GET_DH_SELF_PUBLIC_LEN_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute GET_DH_SELF_PUBLIC key action */
extern void run_CHE_GET_DH_SELF_PUBLIC_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute GET_DH_PRIVATE_LEN action */
extern void run_CHE_GET_DH_PRIVATE_LEN_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute CHE_GET_DH_PRIVATE key action */
extern void run_CHE_GET_DH_PRIVATE_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute CHE_GET_DH_SECRET_LEN action */
extern void run_CHE_GET_DH_SECRET_LEN_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* execute CHE_GET_DH_SECRET key action */
extern void run_CHE_GET_DH_SECRET_process(STCHE *che_context, kal_uint8 *key, kal_int32 key_len);

/* check it before execute cipher/hash functions */
extern void checkCHEProcessPerFix(STCHE *che_context);

/* check it after execute cipher/hash functions */
extern void checkCHEProcessPostfix(STCHE *che_context, kal_bool last_block);

/* execute DES cipher function */
extern kal_bool run_CHE_DES_process(
                    STCHE *che_context,
                    CHE_TYPE type,
                    CHE_OPERATION_MODE mode,
                    CHE_ACTION act,
                    kal_uint8 *source,
                    kal_uint8 *dest,
                    kal_uint32 source_length,
                    kal_bool last_block,
                    STFSAL *pstFSAL);

/* execute 3DES cipher function */
extern kal_bool run_CHE_3DES_process(
                    STCHE *che_context,
                    CHE_TYPE type,
                    CHE_OPERATION_MODE mode,
                    CHE_ACTION act,
                    kal_uint8 *source,
                    kal_uint8 *dest,
                    kal_uint32 source_length,
                    kal_bool last_block,
                    STFSAL *pstFSAL);

/* execute AES cipher function */
extern kal_bool run_CHE_AES_process(
                    STCHE *che_context,
                    CHE_TYPE type,
                    CHE_OPERATION_MODE mode,
                    CHE_ACTION act,
                    kal_uint8 *source,
                    kal_uint8 *dest,
                    kal_uint32 source_length,
                    kal_bool last_block,
                    STFSAL *pstFSAL);

/* execute MD5 hash function */
extern kal_bool run_CHE_MD5_process(
                    STCHE *che_context,
                    CHE_TYPE type,
                    CHE_OPERATION_MODE mode,
                    CHE_ACTION act,
                    kal_uint8 *source,
                    kal_uint8 *dest,
                    kal_uint32 source_length,
                    kal_bool last_block,
                    STFSAL *pstFSAL);

/* execute SHA1 hash function */
extern kal_bool run_CHE_SHA1_process(
                    STCHE *che_context,
                    CHE_TYPE type,
                    CHE_OPERATION_MODE mode,
                    CHE_ACTION act,
                    kal_uint8 *source,
                    kal_uint8 *dest,
                    kal_uint32 source_length,
                    kal_bool last_block,
                    STFSAL *pstFSAL);

extern kal_bool run_CHE_SHA224_process(
            STCHE *che_context,
            CHE_TYPE type,
            CHE_OPERATION_MODE mode,
            CHE_ACTION act,
            kal_uint8 *source,
            kal_uint8 *dest,
            kal_uint32 source_length,
            kal_bool last_block,
            STFSAL *pstFSAL);

extern kal_bool run_CHE_SHA256_process(
            STCHE *che_context,
            CHE_TYPE type,
            CHE_OPERATION_MODE mode,
            CHE_ACTION act,
            kal_uint8 *source,
            kal_uint8 *dest,
            kal_uint32 source_length,
            kal_bool last_block,
            STFSAL *pstFSAL);

/* / execute RC4 cipher function */
extern kal_bool run_CHE_RC4_process(
                    STCHE *che_context,
                    CHE_TYPE type,
                    CHE_OPERATION_MODE mode,
                    CHE_ACTION act,
                    kal_uint8 *source,
                    kal_uint8 *dest,
                    kal_uint32 source_length,
                    kal_bool last_block,
                    STFSAL *pstFSAL);

/* execute MD4 hash function */
extern kal_bool run_CHE_MD4_process(
                    STCHE *che_context,
                    CHE_TYPE type,
                    CHE_OPERATION_MODE mode,
                    CHE_ACTION act,
                    kal_uint8 *source,
                    kal_uint8 *dest,
                    kal_uint32 source_length,
                    kal_bool last_block,
                    STFSAL *pstFSAL);

/* / execute MAC_MD5 hash function */
extern kal_bool run_CHE_MAC_MD5_process(
                    STCHE *che_context,
                    CHE_TYPE type,
                    CHE_OPERATION_MODE mode,
                    CHE_ACTION act,
                    kal_uint8 *source,
                    kal_uint8 *dest,
                    kal_uint32 source_length,
                    kal_bool last_block,
                    STFSAL *pstFSAL);
  
/* execute MAC_SHA1 hash function */
extern kal_bool run_CHE_MAC_SHA1_process(
                    STCHE *che_context,
                    CHE_TYPE type,
                    CHE_OPERATION_MODE mode,
                    CHE_ACTION act,
                    kal_uint8 *source,
                    kal_uint8 *dest,
                    kal_uint32 source_length,
                    kal_bool last_block,
                    STFSAL *pstFSAL);

extern kal_bool run_CHE_MAC_SHA256_process(
            STCHE *che_context,
            CHE_TYPE type,
            CHE_OPERATION_MODE mode,
            CHE_ACTION act,
            kal_uint8 *source,
            kal_uint8 *dest,
            kal_uint32 source_length,
            kal_bool last_block,
            STFSAL *pstFSAL);

extern kal_bool run_CHE_MAC_SHA224_process(
            STCHE *che_context,
            CHE_TYPE type,
            CHE_OPERATION_MODE mode,
            CHE_ACTION act,
            kal_uint8 *source,
            kal_uint8 *dest,
            kal_uint32 source_length,
            kal_bool last_block,
            STFSAL *pstFSAL);

/* execute DH cipher function */
extern kal_bool run_CHE_DH_process(
                    STCHE *che_context,
                    CHE_TYPE type,
                    CHE_OPERATION_MODE mode,
                    CHE_ACTION act,
                    kal_uint8 *source,
                    kal_uint8 *dest,
                    kal_uint32 source_length,
                    kal_bool last_block,
                    STFSAL *pstFSAL);
   
#endif /* __CHE_TRICK_H__ */ 

