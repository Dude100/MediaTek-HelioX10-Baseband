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
 *    che_api.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Cipher/Hash Engine API.
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/*! \mainpage Cipher Hash Engine
 *  @author  Julie Yang
 *  @version 1.0
 *  @date    2007/06/14
 *
 * \section CHE CHE API Introduction
 *
 * This document is an introduction of MTK Cipher and Hash Engine API. There is an interface
 * between Application and Cipher/Hash engine. The interface layer includes four functions.
 * User and application can just use these four functions to set
 * cipher/hash condition, and trigger the process of the cipher/hash engine. Either the
 * bottom layer is hardware or software driver.\n\n
 *
 * CHE API also release four enum structures to define the setting parameters for AP using.
 * User can just use these structures to set cipher/hash conditions,
 * and trigger the process of the cipher/hash engine.\n
 *
 * The header file is in \\mcu\\applib\\misc\\include\\che_api.h\n
 *
 * The API is supported after 07A branch. \n
 *
 *
 */

/** @defgroup CHE Cipher/Hash Engine Interface
 *  @{
 */

/** @defgroup CHE Cipher/Hash Engine Interface
 *  @{
 */
#ifndef _CHE_API_H
#define _CHE_API_H

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "fsal.h"
//#include "md5.h"
//#include "sha1.h"
//#include "md4.h"

/* DOM-NOT_FOR_SDK-BEGIN */
/* DNS context structure */
typedef struct DES_CNXT_T
{
#if defined(__HW_CHE__)  
    kal_uint8 cheCKey[36];          /* des; 3des;convert_aes_128_key;convert_aes_192_key;convert_aes_256_key */
    kal_uint8 cheDataAddr[120];     /* che_hw_des;che_hw_aes;che_hw_hash */
#else /* defined(__HW_CHE__) */ 
    kal_uint8 cheLastBlock[16];     /* Last block used in counter mode (store the previous cipher text) */
    kal_uint8 cheLastReminder[16];  /* Last remainder block */
    kal_uint8 cheKeySchedule[128];  /* key schedule */
    kal_uint8 iv[64];               /* initial vector */
#endif /* defined(__HW_CHE__) */ 
}DES_CNXT;

/* AES context structure */
typedef struct AES_CNXT_T
{
#if defined(__HW_CHE__)  
    kal_uint8 cheCKey[36];          /* des; 3des;convert_aes_128_key;convert_aes_192_key;convert_aes_256_key */
    kal_uint8 cheDataAddr[120];     /* che_hw_des;che_hw_aes;che_hw_hash */
#else /* defined(__HW_CHE__) */ 
    kal_uint8 cheLastReminder[16];  /* Last remaining segment */
    kal_uint8 orgIV[64];            /* Initial vector */
#endif /* defined(__HW_CHE__) */ 
}AES_CNXT;

/* MD5 and SH1 structure */
typedef struct MD5_CNXT_T
{
#if defined(__HW_CHE__)  
    kal_uint8 cheDataAddr[120]; /* che_hw_des;che_hw_aes;che_hw_hash */
#else
    kal_uint8 *working_buffer; /* working buffer */
#endif
}MD5_CNXT, SHA1_CNXT;

/* structure used for MD5,SHA1, MAC_MD5, MAC_SHA1, MD4, DHM */
typedef struct CNXT_T
{
    kal_uint8 *working_buffer; /* working buffer */
}SW_MISC_CNXT;

/* RC4 structure */
typedef struct RC4_CNXT_T
{
    kal_uint32 x, y; /* the swap index */
    kal_uint8 keyStream[256]; /* key stream */
} RC4_CNXT;

/* used only for HW HASH ;che_hw_des;che_hw_aes;che_hw_hash */
typedef struct HASH_CNXT_T 
{
    kal_uint8 cheDataAddr[120]; /* Data address */
}HASH_CNXT;

/* RSA structure */
typedef struct RSA_CNXT_T
{
    /* RSA */
    kal_uint8 *modulusN; /* modulus N. N=P*Q. It is a prime number */
    kal_uint32 modulusNLen; /* the length of modulus N */
    kal_uint8 *pubExp; /* public exponent: E */
    kal_uint32 pubExpLen; /* the length of public exponent */
    kal_uint8 *privExpD; /* private exponent: D */
    kal_uint32 privExpDLen; /* the length of private exponent D */
    kal_uint8 *primeP; /* modulus P. It is a prime number */
    kal_uint32 primePLen; /* the length of P */
    kal_uint8 *primeQ; /* modulus Q. It is a prime number */
    kal_uint32 primeQLen; /* the length of Q */
    kal_uint8 *dModPm1; /* private exponent: DP */
    kal_uint32 dModPm1Len; /* the length of private exponent DP */
    kal_uint8 *dModQm1; /* private exponent: DQ */
    kal_uint32 dModQm1Len; /* the length of private exponent DQ */
    kal_uint8 *qInvModP; /* coefficient Integer: inverse Q */
    kal_uint32 qInvModPLen; /* the length of coefficient integer */
    kal_uint8 *hash;    /* Hash value used to verify the signature */
    kal_uint32 hashLen; /* Hash length */
    kal_bool rsaKeyFlag; /* RSA key flag */
}RSA_CNXT;

/* #define __CHE_RSA_GEN_KEY__ */

/** The structure STCHE is defined to record and maintain the context of CHE */
typedef struct STCHE_T 
{
    kal_uint32 cheLastLength; /* last block length */
    kal_uint8 *cheLastDstAddr; /* last destination address */
       
    kal_uint8 *cheWorkBuf;  /* pointe to a space used by each algorithm */
    kal_uint32 cheBufLen;   /* the length of cheWorkBuf. It depends on the encrypt algorithm */
    kal_uint32 cipher_type; /* cipher type */
    
    kal_uint8 *cheKey; /* key stream */
    kal_uint8 *cheIV; /* initial vector */
    kal_uint32 cheKeyLength; /* key stream length */
    kal_uint32 cheIVLength; /* initial vector length */

#if defined(__HW_CHE__) 
    kal_bool cheResetKeyFlag; /* Reset key flag */
    kal_bool cheResetIVFlag; /* Reset initial vector flag */
#endif /* defined(__HW_CHE__) */ 

    kal_bool cheFirstFlag; /* first block flag */
 } STCHE;

/* DOM-NOT_FOR_SDK-END */

/* CHE error cause */
typedef enum
{
    CHE_OK                    = 0,  /* success */
    CHE_ERROR                 = -1, /* error occurs */
    CHE_KEY_CHK_FAIL          = -2, /* public or private key check fail */
    CHE_INVALID_LENGTH        = -3, /* buffer length too small or too long */
    CHE_OPERATION_FAIL        = -4  /* che operation fails, such as cipher fail */
} che_result_error_enum;

/** CHE_TYPE define the cipher and hash function algorithm type */
typedef enum
{
    CHE_MD5 = 1, /* MD5 hash algorithm. The output length is fixed 16 bytes */
    CHE_SHA1, /* SHA1 hash algorithm. The output length is fixed 20 bytes */
    CHE_DES, /* DES block cipher algorithm. The CHE will do auto padding in DES type.
                The maximum padding length is 8 bytes */
    CHE_3DES, /* 3DES block cipher algorithm. The CHE will do auto padding in 3DES type.
                 The maximum padding length is 8 bytes */
    CHE_AES, /* AES block cipher algorithm. The CHE will do auto padding in AES(ECB, CBC) type.
                The maximum padding length is 16 bytes */

    CHE_MD4, /* MD4 hash algorithm. The output length is fixed 16 bytes */
    CHE_MAC_MD5, /* HMAC_MD5 hash algorithm. The output length is fixed 16 bytes */
    CHE_MAC_SHA1, /* HMAC_SHA1 hash algorithm. The output length is fixed 20 bytes */
    CHE_RC4, /* RC4 stream cipher algorithm. No padding */

    CHE_RSA, /* RSA asym cipher algorithm. */
    CHE_DH, /* Diffie Hellman cipher algorithm used to generate the key. No padding */
    CHE_MAC_SHA224, /* HMAC_SHA224 hash algorithm. The output length is fixed 28 bytes */
    CHE_MAC_SHA256, /* HMAC_SHA256 hash algorithm. The output length is fixed 32 bytes */
    CHE_SHA224, /* SHA 224 algorithm */
    CHE_SHA256 /* SHA 256 algorithm */
} CHE_TYPE;

/* CHE_OPERATION_MODE define the cipher function mode. For hash function, it could be set CHE_MODE_NULL */
typedef enum
{
    CHE_MODE_NULL = 0, /* null mode. This mode is used when there is no mode operation */
    CHE_ECB, /* AES/DES ECB mode */
    CHE_CBC, /* AES/DES CBC mode */
    CHE_CTR, /* AES CTR(counter) mode */
    CHE_F8, /* AES F8 mode */

    CHE_SKIP, /* RC4 Skip mode */
    CHE_KEY_WRAP, /* AES key wrap mode */
    CHE_KEY_UNWRAP /* AES key unwrap mode */

} CHE_OPERATION_MODE;

/* che_rsa_padding_mode_enum define the RSA padding mode. */
typedef enum
{
    CHE_RSA_MODE_NULL = 0, /* null mode. This mode is used when there is no padding */
    CHE_RSA_PKCS1_V15, /* RSA PKCS#1 v1.5 padding mode  */
    CHE_RSA_PKCS1_V21,
    CHE_RSA_MODE_TOTAL
} che_rsa_padding_mode_enum;

/* CHE_ACTION define this CHE process should run hash, encipher or decipher */
typedef enum
{
    CHE_HASH, /* generate hash value */
    CHE_ENC, /* encryption data */
    CHE_DEC, /* decryption data */
    CHE_MAC_HASH, /* generate HMAC value */

    DH_INIT, /* initialize the Diffie-Hellman */
    DH_MAKE_PARAMS, /* Suppose A=G^a mod p. generate discrete logarithms(a) and A */
    DH_MAKE_PUBLIC, /* Suppose A=G^a mod p. generate discrete logarithms(a) and A */
    DH_CALC_SECRET, /* Suppose B=G^b mod p. Calculate the shared secret (G^b)^a mod P */
    DH_FREE /* finialize the Diffie-Hellman */
} CHE_ACTION;

/* CHE_KEY_ACTION define the CHE Key process. The life cycle of input key buffer should
 * be maintained until che_deinit except RSA.
 */
typedef enum
{
    CHE_GEN_KEY, /* generate the key exclude asynmetry and RC4 algirhtm */
    CHE_SET_KEY, /* set the key exclude asynmetry and RC4 algirhtm */
    CHE_GET_KEY, /* get the key exclude asynmetry and RC4 algirhtm*/
    CHE_DEL_KEY, /* delete the key exclude asynmetry and RC4 algirhtm */

    CHE_SET_RC4_KEY, /* set the RC4 key */

#if defined(__CHE_RSA_GEN_KEY__)
    CHE_GEN_RSA_KEY, /* generate RSA key for hardware */
    CHE_DEL_RSA_KEY, /* delete the RSA key for hardward */
#endif /* defined(__CHE_RSA_GEN_KEY__) */ 
    CHE_SET_RSA_N, /* set the RSA modulus N. N=P*Q. N is prime number. 
                      The input N is a binary data */
    CHE_SET_RSA_E, /* set the RSA public exponent: E. 
                      The input E is a binary data */
    CHE_SET_RSA_D, /* set the RSA private exponent: D. 
                      The input D is a binary data */
    CHE_SET_RSA_P, /* set the RSA modulus P(CRT format). 
                      The input P is a binary data */
    CHE_SET_RSA_Q, /* set the RSA modulus Q(CRT format). 
                      The input Q is the binary data */
    CHE_SET_RSA_dModPm1, /* set the RSA private exponent(CRT format): DP. 
                            The input DP is a binary data */
    CHE_SET_RSA_dModQm1, /* set the RSA private exponent(CRT format): DQ. 
                            The input DQ is a binary data */
    CHE_SET_RSA_qInvModP, /* set the coefficient Integer(CRT format): inverse Q. 
                             The input InvQ is a binary data */

    CHE_SET_DH_P, /* set the DH modulus: P. The input P is a binary data. */
    CHE_SET_DH_G, /* set the DH prime root: G. The input G is a binary data */
    CHE_SET_DH_SELF_PUBLIC, /* set the self public value. G^X mod P. The input is a binary data. */
    CHE_SET_DH_PEER_PUBLIC, /* set the peer public value. G^Y mod P. The input is a binary data. */
    CHE_SET_DH_PRIVATE, /* set the discrete logarithms(private key): X. 
                           The input X is a binary data. */

    CHE_GET_DH_SELF_PUBLIC_LEN, /* get the self public length */
    CHE_GET_DH_PRIVATE_LEN, /* get the discrete logarithm length */
    CHE_GET_DH_SECRET_LEN, /* get the secret length */

    CHE_GET_DH_SELF_PUBLIC, /* get self public value */
    CHE_GET_DH_PRIVATE, /* get the discrete logarithm */
    CHE_GET_DH_SECRET, /* get the shared key,i.e. key. key = GY^X mod P */

    CHE_GET_RSA_N, /* get the RSA modulus N. N=P*Q. N is prime number. The output N is binary data */
    CHE_GET_RSA_E, /* get the RSA public exponent: E. The output E is a binary data */
    CHE_GET_RSA_D, /* get the RSA private exponent: D. The output D is a binary data */
    CHE_GET_RSA_P, /* get the RSA modulus P(CRT format). The output P is a binary data */
    CHE_GET_RSA_Q, /* get the RSA modulus Q(CRT format). The output Q is the binary data */
    CHE_GET_RSA_dModPm1, /* get the RSA private exponent(CRT format): DP. The output DP is a binary data */
    CHE_GET_RSA_dModQm1, /* get the RSA private exponent(CRT format): DQ. The output DQ is a binary data */
    CHE_GET_RSA_qInvModP, /* get the coefficient Integer(CRT format): inverse Q. The output InvQ is a binary data */

    CHE_GET_RSA_N_LEN, /* get the RSA modulus N. N=P*Q. N is prime number. The output N is binary data */
    CHE_GET_RSA_E_LEN, /* get the RSA public exponent: E. The output E is a binary data */
    CHE_GET_RSA_D_LEN, /* get the RSA private exponent: D. The output D is a binary data */
    CHE_GET_RSA_P_LEN, /* get the RSA modulus P(CRT format). The output P is a binary data */
    CHE_GET_RSA_Q_LEN, /* get the RSA modulus Q(CRT format). The output Q is the binary data */
    CHE_GET_RSA_dModPm1_LEN, /* get the RSA private exponent(CRT format): DP. The output DP is a binary data */
    CHE_GET_RSA_dModQm1_LEN, /* get the RSA private exponent(CRT format): DQ. The output DQ is a binary data */
    CHE_GET_RSA_qInvModP_LEN /* get the coefficient Integer(CRT format): inverse Q. The output InvQ is a binary data */

} CHE_KEY_ACTION;

#include "che_trick.h"

        
/*****************************************************************************
 * FUNCTION
 *  che_init
 * DESCRIPTION
 *  Initialize the CHE_CONTEXT data structure created from AP
 * PARAMETERS
 *  che_context  : [IN]   CHE context
 *  type         : [IN]   CHE type (CHE_TYPE)
 * RETURN VALUES
 *  void
 * SEE ALSO
 *  che_deinit
 * EXAMPLE
 * <code>
 * STCHE context;
 * che_init(&context, CHE_SHA1);
 * </code>
 *****************************************************************************/
extern void che_init(STCHE *che_context, kal_uint32 type);

/*****************************************************************************
 * FUNCTION
 *  che_deinit
 * DESCRIPTION
 *  Deinitialize the CHE_CONTEXT
 * PARAMETERS
 *  che_context  : [IN]   CHE context
 * RETURN VALUES
 *  void
 * SEE ALSO
 *  che_init
 * EXAMPLE
 * <code>
 * STCHE context;
 * che_init(&context, CHE_SHA1);
 * ...
 * che_deinit(&context);
 * </code>
 *****************************************************************************/
extern void che_deinit(STCHE *che_context);

/*****************************************************************************
 * DESCRIPTION
 * API used to set, get, delete, generate the key value.
 * If user uses this API to get the key, CHE only stores the pointer of the key.
 * Thus, the key has to be kept until the che_deinit is called. There is only 
 * One exception, in the RSA, we will allocate another space to store the key.
 * Thus, user doesn't have to care if they can release the buffer of key.
 * PARAMETERS 
 *    che_context : [IN]        che context
 *    key_act :     [IN]        key action (CHE_KEY_ACTION)
 *    key :         [IN/OUT]    key stream
 *    key_ley :     [IN]        key stream length
 * EXAMPLE
 *    <code>
 *    STCHE che_context;
 *    che_init(&che_context, CHE_MAC_MD5);
 *    che_key_action(&che_context, CHE_SET_KEY,  (kal_uint8 *) key, key_len);
 *    </code>
 *****************************************************************************/
#define che_key_action(che_context, key_act, key, key_len)                 \
                                                                           \
   ((void)TRICK_##key_act, run_##key_act##_process(che_context, key, key_len))
                                                                                                                
/*****************************************************************************
 * FUNCTION
 *  che_set_iv
 * DESCRIPTION
 *  Set initial vector for CBC or CTR or AES_F8 mode. CHE only stores the pointer address.
 *  The iv buffer should be kept by the user until the first block is computed.
 *  To avoid confusion, user can keep the buffer until the che_deinit is called.
 * PARAMETERS
 *  che_context  : [IN]   CHE context
 *  iv           : [IN]   initial vector. 
 *                        the input has to be 4-byte alignment on ARM platform
 *  iv_len       : [IN]   initial vector length
 * RETURN VALUES
 *  void
 * EXAMPLE
 * <code>
 * STCHE context;
 * che_init(&context, CHE_AES);
 *  che_set_iv(&che_context, iv, 16);
 * ...
 * che_deinit(&context);
 * </code>
 *****************************************************************************/
extern void che_set_iv(STCHE *che_context, kal_uint8 *iv, kal_uint32 iv_len);


/*****************************************************************************
 * DESCRIPTION
 *    API used to execute cipher and hash process function.
 *    Since using Marco to reduce linkage code size, please pass the "type" parameter 
 *    as the constant announced in CHE_TYPE enum. It doesn't allow passing variable.
 *    The dest buffer size should be refer to the RFC standard specification.
 *    The DES/AES in CBC/ECB mode will do the auto padding if application uses the CHE's auto padding, 
 *    the destination buffer address has to be at least source_length + 1 DES block size(8 bytes) . 
 *    Otherwise, there will be a memory corruption. If application doesn't want to use auto padding,
 *    it cannot set the last_block to "TRUE". That is to say, as long as the last_block is not set to
 *    TRUE, there will no auto padding. The auto padding CHE uses is PKCS#1 v15. This padding is standard 
 *    padding used in PCKS#5.
 *    P.S. The input and output buffer should be different buffer. Don't use the same buffer.
 *
 * PARAMETERS 
 *    che_context   : [IN]        che context
 *    type          : [IN]        che type (CHE_TYPE)
 *    mode          : [IN]        che operation mode (CHE_OPERATION_MODE)
 *    act           : [IN]        che action (CHE_ACTION)
 *    source        : [IN]        source input data buffer (it has to be 4-byte alignment for DES and AES)
 *    dest          : [OUT]       destination buffer (it has to be 4-byte alignment for DES)
 *    source_length : [IN]        source input buffer length
 *    final         : [IN]        KAL_TRUE: do the standard auto padding(PKCS#5). 
 *                                KAL_FLASE: don't do the standard auto padding(PKCS#5).
 *                                If user wants the auto padding, s/he has to set the final to TRUE in its final block
 *                                operation. On the contrary, if s/he doesn't want the auto padding, please do not set 
 *                                final to TRUE.
 * RETURN VALUES
 *    KAL_TRUE  : CHE process successful
 *    KAL_FLASE : CHE process fail
 * SEE ALSO
 *  che_process_from_file
 * EXAMPLE
 *    Symmetry Block Cipher Examples:
 *
 *    1. DES Encryption (CBC mode):
 *    The input, initial vector and destination address have to be in 4-byte alignment.
 *
 *    With auto padding:
 *    <code>
 *    STCHE che_context;
 *    che_init(&che_context, CHE_DES);
 *    che_key_action(&che_context, CHE_SET_KEY, key, key_length);
 *    che_set_iv(&che_context, init_vector, vec_length);
 *    che_process(&che_context, CHE_DES, CHE_CBC , CHE_ENC, src_buffer, dst_buffer, src_len, KAL_FALSE);
 *    ...
 *    //if the last segmemnt in source buffer is intended to be processed and we want to use the auto padding,
 *    //we set final to TRUE
 *    che_process(&che_context, CHE_DES, CHE_CBC , CHE_ENC, src_buffer, dst_buffer, src_len, KAL_TRUE);
 *    // do other operation
 *    ...
 *    //Deinitialize when all cipher operation is finish
 *    che_deinit(&che_context);
 *    </code>
 *    
 *    Without auto padding:
 *    <code>
 *    STCHE che_context;
 *    che_init(&che_context, CHE_DES);
 *    che_key_action(&che_context, CHE_SET_KEY, key, key_length);
 *    che_set_iv(&che_context, init_vector, vec_length);
 *    che_process(&che_context, CHE_DES, CHE_CBC , CHE_ENC, src_buffer, dst_buffer, src_len, KAL_FALSE);
 *    ...
 *    //if the last segmemnt in source buffer is intended to be processed and we don't want the auto padding,
 *    //we set final to FALSE
 *    che_process(&che_context, CHE_DES, CHE_CBC , CHE_ENC, src_buffer, dst_buffer, src_len, KAL_FALSE); 
 *    // do other operation
 *    ...
 *    //Deinitialize when all cipher operation is finish
 *    che_deinit(&che_context);
 *    </code>
 *    2. DES Encryption (ECB mode):
 *    With auto padding:
 *    <code>
 *    STCHE che_context;
 *    che_init(&che_context, CHE_DES);
 *    che_key_action(&che_context, CHE_SET_KEY, key, key_length);
 *    che_process(&che_context, CHE_DES, CHE_ECB , CHE_ENC, src_buffer, dst_buffer, src_len, KAL_FALSE);
 *    ...
 *    //if the last segmemnt in source buffer is intended to be processed and we want to use the auto padding,
 *    //we set final to TRUE
 *    che_process(&che_context, CHE_DES, CHE_ECB , CHE_ENC, src_buffer, dst_buffer, src_len, KAL_TRUE);
 *    // do other operation
 *    ...
 *    //Deinitialize when all cipher operation is finish
 *    che_deinit(&che_context);
 *    </code>
 *
 *    Without auto padding:
 *    <code>
 *    STCHE che_context;
 *    che_init(&che_context, CHE_DES);
 *    che_key_action(&che_context, CHE_SET_KEY, key, key_length);
 *    che_process(&che_context, CHE_DES, CHE_ECB , CHE_ENC, src_buffer, dst_buffer, src_len, KAL_FALSE);
 *    ...
 *    //if the last segmemnt in source buffer is intended to be processed and we don't want to use the 
 *    //auto padding, we set final to TRUE
 *    che_process(&che_context, CHE_DES, CHE_ECB , CHE_ENC, src_buffer, dst_buffer, src_len, KAL_FALSE);
 *    // do other operation
 *    ...
 *    //Deinitialize when all cipher operation is finish
 *    che_deinit(&che_context);
 *    </code>
 *    3. AES Encryption (Counter mode):
 *    Because this mode doesn't need padding, we don't care the "final" parameter in this mode. 
 *    Its input data can not in block boundary size.
 *    <code>
 *    STCHE che_cntx;
 *    che_init(&che_cntx, CHE_AES);
 *    che_key_action(&che_cntx, CHE_SET_KEY, key, 16);
 *    che_set_iv(&che_cntx, iv, 16);
 *    che_process(&che_cntx, CHE_AES, CHE_CTR, CHE_ENC, src_data, dst_data, src_len, KAL_TRUE);
 *    // do other operation
 *    ...
 *    //Deinitialize when all cipher operation is finish
 *    che_deinit(&che_cntx);
 *    </code>
 *
 *    4. AES Encryption (Key WRAP mode):
 *    The input data has to be in multiple of 64 bits block size. 
 *    Because this mode doesn't need padding, we don't care the "final" parameter in this mode. 
 *    Because one more block is generated for checking in KEY WRAP mode,
 *    the input and output buffer should be different one in KEY_WRAP and KEY_UNWRAP mode.
 *    <code>
 *    STCHE che_cntx;
 *    che_init(&che_cntx, CHE_AES);
 *    che_key_action(&che_cntx, CHE_SET_KEY, key, 16);
 *    che_set_iv(&che_cntx, iv, 16);
 *    che_process(&che_cntx, CHE_AES, CHE_KEY_WRAP, CHE_ENC, src_data, dst_data, src_len, KAL_TRUE);
 *    // do other operation
 *    ...
 *    //Deinitialize when all cipher operation is finish
 *    che_deinit(&che_cntx);
 *    </code>
 *
 *    5. AES Encryption (CBC mode):
 *    The input and initial vector address have to be in 4-byte alignment.
 *
 *    With auto padding:
 *    <code>
 *    STCHE che_cntx;
 *    che_init(&che_cntx, CHE_AES);
 *    che_key_action(&che_cntx, CHE_SET_KEY, key, 16);
 *    che_set_iv(&che_cntx, iv, 16);
 *    che_process(&che_cntx, CHE_AES, CHE_CBC, CHE_ENC, src_data, dst_data, src_len, KAL_FALSE);
 *    //final block
 *    che_process(&che_cntx, CHE_AES, CHE_CBC, CHE_ENC, src_data, dst_data, src_len, KAL_TRUE);
 *    // do other operation
 *    ...
 *    //Deinitialize when all cipher operation is finish
 *    che_deinit(&che_cntx);
 *    </code>
 *
 *    Without auto padding:
 *    <code>
 *    STCHE che_cntx;
 *    che_init(&che_cntx, CHE_AES);
 *    che_key_action(&che_cntx, CHE_SET_KEY, key, 16);
 *    che_set_iv(&che_cntx, iv, 16);
 *    che_process(&che_cntx, CHE_AES, CHE_CBC, CHE_ENC, src_data, dst_data, src_len, KAL_FALSE);
 *    // final block
 *    che_process(&che_cntx, CHE_AES, CHE_CBC, CHE_ENC, src_data, dst_data, src_len, KAL_FALSE);
 *    // do other operation
 *    ...
 *    //Deinitialize when all cipher operation is finish
 *    che_deinit(&che_cntx);
 *    </code>
 *    6. AES Encryption (ECB mode):
 *    The input address have to be in 4-byte alignment.
 *
 *    With auto padding:
 *    <code>
 *    STCHE che_cntx;
 *    che_init(&che_cntx, CHE_AES);
 *    che_key_action(&che_cntx, CHE_SET_KEY, key, 16);
 *    che_process(&che_cntx, CHE_AES, CHE_ECB, CHE_ENC, src_data, dst_data, src_len, KAL_FALSE);
 *    //final block
 *    che_process(&che_cntx, CHE_AES, CHE_ECB, CHE_ENC, src_data, dst_data, src_len, KAL_TRUE);
 *    // do other operation
 *    ...
 *    //Deinitialize when all cipher operation is finish
 *    che_deinit(&che_cntx);
 *    </code>    
 *
 *    Without auto padding:
 *    <code>
 *    STCHE che_cntx;
 *    che_init(&che_cntx, CHE_AES);
 *    che_key_action(&che_cntx, CHE_SET_KEY, key, 16);
 *    che_process(&che_cntx, CHE_AES, CHE_ECB, CHE_ENC, src_data, dst_data, src_len, KAL_FALSE);
 *    //final block
 *    che_process(&che_cntx, CHE_AES, CHE_ECB, CHE_ENC, src_data, dst_data, src_len, KAL_FALSE);
 *    // do other operation
 *    ...
 *    //Deinitialize when all cipher operation is finish
 *    che_deinit(&che_cntx);
 *    </code>    
 *  
 *    Symmetry Stream Cipher Example:
 *
 *    1. RC4 Encryption:
 *    Because this mode doesn't need padding, we don't care the "final" parameter in this mode. 
 *
 *    Use default RC4 mode:
 *    <code>
 *    STCHE che_ctx;
 *    che_init(&che_ctx, CHE_RC4);    
 *    che_key_action(&che_ctx, CHE_SET_KEY, (kal_uint8 *)key, key_len);
 *    che_process(&che_ctx, CHE_RC4, CHE_MODE_NULL, CHE_ENC, (kal_uint8 *)input, 
 *              (kal_uint8 *)output, (kal_int32)input_size, KAL_TRUE);
 *    // do other operation
 *    ...
 *    //Deinitialize when all cipher operation is finish
 *    che_deinit(&che_ctx);
 *    </code>
 *
 *    Use CHE_SKIP mode:
 *    skip the first 256 byts key data because first 256 bytes are not random enough.
 *    <code>
 *    STCHE che_ctx;
 *    che_init(&che_ctx, CHE_RC4);    
 *    che_key_action(&che_ctx, CHE_SET_KEY, (kal_uint8 *)key, key_len);
 *    che_process(&che_ctx, CHE_RC4, CHE_SKIP, CHE_ENC, (kal_uint8 *)input, 
 *              (kal_uint8 *)output, (kal_int32)input_size, KAL_TRUE);
 *    // do other operation
 *    ...
 *    //Deinitialize when all cipher operation is finish
 *    che_deinit(&che_ctx);
 *    </code>
 *
 *    Hash Operation:
 *
 *    1. MD5 Hash generation:
 *    we have to set the final block to TRUE for hash operation. The mode field is useless for hash algorithm.
 *    HASH doesn't have any mode options. Thus, we set it to CHE_MODE_NULL.
 *
 *    <code>
 *    STCHE che_context;
 *    kal_uint8 digest[16];
 *    che_init(&che_context, CHE_MD5); 
 *    che_process(&che_context,CHE_MD5,CHE_MODE_NULL,CHE_HASH,(kal_uint8*)input,digest,input_len, KAL_FALSE);
 *    ...
 *    che_process(&che_context,CHE_MD5,CHE_MODE_NULL,CHE_HASH,(kal_uint8*)input,digest,input_len, KAL_TRUE);
 *    // do other operation
 *    ...
 *    //Deinitialize when all hash operation is finish
 *    che_deinit(&che_context);
 *    </code>
 *
 *    2. SHA1 Hash generation:
 *    we have to set the final block to TRUE for hash operation. The mode field is useless for hash algorithm.
 *    HASH doesn't have any mode options. Thus, we set it to CHE_MODE_NULL.
 *
 *    <code>
 *    STCHE che_context;
 *    kal_uint8 digest[20];
 *    che_init(&che_context, CHE_SHA1); 
 *    che_process(&che_context,CHE_SHA1,CHE_MODE_NULL,CHE_HASH,(kal_uint8*)input,digest,input_len, KAL_FALSE);
 *    ...
 *    che_process(&che_context,CHE_SHA1,CHE_MODE_NULL,CHE_HASH,(kal_uint8*)input,digest,input_len, KAL_TRUE);
 *    che_deinit(&che_context);
 *    // do other operation
 *    ...
 *    //Deinitialize when all hash operation is finish
 *    </code>    
 *
 *    3. HMAC MD5 generation:
 *    we have to set the final block to TRUE for HMAC operation because HMAC doesn't have padding consideartion for last block. 
 *    The mode field is useless for HMAC algorithm. HMAC doesn't have any mode options. Thus, we set it to CHE_MODE_NULL.
 *
 *    <code>
 *    STCHE che_context;
 *    kal_uint8 digest[16];
 *    che_init(&che_context, CHE_MAC_MD5);
 *    che_key_action(&che_context, CHE_SET_KEY,  (kal_uint8 *) key, key_len);
 *    che_process(&che_context, CHE_MAC_MD5, CHE_MODE_NULL, CHE_HASH, (kal_uint8 *) input, digest, input_len, KAL_FALSE);
 *    ...
 *    che_process(&che_context, CHE_MAC_MD5, CHE_MODE_NULL, CHE_HASH, (kal_uint8 *) input, digest, input_len, KAL_TRUE);    
 *    // do other operation
 *    ...
 *    //Deinitialize when all hash operation is finish
 *    che_deinit(&che_context);
 *    </code>
 *
 *    4. SHA2 Hash generation:
 *    we have to set the final block to TRUE for hash operation. The mode field is useless for hash algorithm.
 *    HASH doesn't have any mode options. Thus, we set it to CHE_MODE_NULL.
 *
 *    <code>
 *    STCHE che_context;
 *    kal_uint8 digest[32];
 *    che_init(&che_context, CHE_SHA256);
 *    che_process(&che_context, CHE_SHA256, CHE_MODE_NULL, CHE_HASH, (kal_uint8 *) input, digest, input_len, KAL_FALSE);
 *    ...
 *    che_process(&che_context, CHE_SHA256, CHE_MODE_NULL, CHE_HASH, (kal_uint8 *) input, digest, input_len, KAL_TRUE);    
 *    // do other operation
 *    ...
 *    //Deinitialize when all hash operation is finish
 *    che_deinit(&che_context);
 *    </code>
 *
 *    Public Key or Key Agreement:
 *
 *    1. Diffie-Hellman: 
 *    The source and dest parameter is useless for DH. 
 *    The output data is get through che_key_action.
 *    <code>
 *    STCHE che_ctx_dh;
 *    kal_uint32 dh_secret_len;
 *    kal_uint8 *dh_secret_key = NULL;
 *
 *    che_init(&che_ctx_dh, CHE_DH);
 *    che_process(&che_ctx_dh, CHE_DH, CHE_MODE_NULL, DH_INIT, NULL, NULL, 0, KAL_TRUE);
 *    // set the p and g. p and g must in binary format
 *    che_key_action(&che_ctx_dh, CHE_SET_DH_P, (kal_uint8*) P, P_Len);
 *    che_key_action(&che_ctx_dh, CHE_SET_DH_G, G, G_Len);
 *    // Compute self public B = (g^b mod p) and private (b)
 *    che_process(&che_ctx_dh, CHE_DH, CHE_MODE_NULL, DH_MAKE_PARAMS, NULL, NULL, 0, KAL_TRUE);
 *    // Set the peer public key (A) in binary format
 *    che_key_action(&che_ctx_dh, CHE_SET_DH_PEER_PUBLIC, (kal_uint8*)peer_public, peer_public_len);
 *    // calculate the shared secret: K
 *    che_process(&che_ctx_dh, CHE_DH, CHE_MODE_NULL, DH_CALC_SECRET, NULL, NULL, 0, KAL_TRUE);
 *    //get the shared secret key
 *    che_key_action(&che_ctx_dh, CHE_GET_DH_SECRET_LEN, (void*)&dh_secret_len, sizeof(int));
 *    dh_secret_key = malloc(dh_secret_len);
 *    che_key_action(&che_ctx_dh, CHE_GET_DH_SECRET, (kal_uint8*) dh_secret_key, dh_secret_len);
 *    //call deinit when all operations are finish
 *    che_process(&che_ctx_dh, CHE_DH, CHE_MODE_NULL, DH_FREE, NULL, NULL, 0, KAL_TRUE);
 *    che_deinit(&che_ctx_dh);
 *    </code>
 *****************************************************************************/
#define che_process(che_context, type, mode, act, source, dest, source_length, final)                       \
                                                                                                                 \
   ((void)TRICK_##type, run_##type##_process(che_context, type, mode, act, source, dest, source_length, final, 0))
                                                                                                                
/*****************************************************************************
 * DESCRIPTION
 *    API used to do the CHE computation. The input message is from the "file".
 *    The usage is the same as che_process except the source of input data.
 *    For detail algorithm usage, please also take the reference of "che_process"
 * PARAMETERS 
 *    che_context    : [IN]        che context
 *    type           : [IN]        che type (CHE_TYPE)
 *    mode           : [IN]        che operation mode (CHE_OPERATION_MODE)
 *    act            : [IN]        che action (CHE_ACTION)
 *    pstFSAL        : [IN]        source file handler
 *    dest          : [OUT]       destination buffer (it has to be 4-byte alignment for DES)
 * RETURN VALUES
 *    KAL_TRUE  : CHE process successful
 *    KAL_FLASE : CHE process fail
 * SEE ALSO
 *  che_process
 * EXAMPLE
 *    1. DES Encryption (CBC mode):
 *    The initial vector and destination address have to be in 4-byte alignment.
 *   
 *    <code>
 *    STFSAL pstFSAL;
 *    kal_uint8 pbBuf[512];
 *    STCHE che_str;
 *    che_init(&che_str, CHE_DES); 
 *    che_key_action(&che_str, CHE_SET_KEY, key, key_length);
 *    che_set_iv(&che_str, init_vector, vec_length);
 *    FSAL_Open(&pstFSAL, body_data_filepath, FSAL_READ);
 *    FSAL_SetBuffer(&pstFSAL, 512, pbBuf);
 *    if (che_process_from_file(&che_str, CHE_DES, CHE_CBC, CHE_ENC,
 *                              &pstFSAL, dst_buf) == KAL_FALSE)
 *    {
 *        FSAL_Close(&pstFSAL);
 *        che_deinit(&che_str);
 *        return ERROR;
 *    }
 *    ...
 *    FSAL_Close(&pstFSAL);
 *    // do other operations
 *    ...
 *    //Deinitialize when all operations are finish
 *    che_deinit(&che_str);
 *    </code>
 *    
 *    2. DES Encryption (ECB mode):
 *    <code>
 *    STFSAL pstFSAL;
 *    kal_uint8 pbBuf[512];
 *    STCHE che_str;
 *    che_init(&che_str, CHE_DES); 
 *    che_key_action(&che_str, CHE_SET_KEY, key, key_length);
 *    FSAL_Open(&pstFSAL, body_data_filepath, FSAL_READ);
 *    FSAL_SetBuffer(&pstFSAL, 512, pbBuf);
 *    if (che_process_from_file(&che_str, CHE_DES, CHE_ECB, CHE_ENC,
 *                              &pstFSAL, dst_buf) == KAL_FALSE)
 *    {
 *        FSAL_Close(&pstFSAL);
 *        che_deinit(&che_str);
 *        return ERROR;
 *    }
 *    ...
 *    FSAL_Close(&pstFSAL);
 *    // do other operations
 *    ...
 *    //Deinitialize when all operations are finish
 *    che_deinit(&che_str);
 *    </code>
 *
 *    3. AES Encryption (CBC mode):
 *    <code>
 *    STFSAL pstFSAL;
 *    kal_uint8 pbBuf[512];
 *    STCHE che_str;
 *    che_init(&che_str, CHE_AES); 
 *    che_key_action(&che_str, CHE_SET_KEY, key, key_length);
 *    che_set_iv(&che_str, init_vector, vec_length);
 *    FSAL_Open(&pstFSAL, body_data_filepath, FSAL_READ);
 *    FSAL_SetBuffer(&pstFSAL, 512, pbBuf);
 *    if (che_process_from_file(&che_str, CHE_AES, CHE_CBC, CHE_ENC,
 *                              &pstFSAL, dst_buf) == KAL_FALSE)
 *    {
 *        FSAL_Close(&pstFSAL);
 *        che_deinit(&che_str);
 *        return ERROR;
 *    }
 *    ...
 *    FSAL_Close(&pstFSAL);
 *    // do other operations
 *    ...
 *    //Deinitialize when all operations are finish
 *    che_deinit(&che_str);
 *    </code>
 *
 *    4. MD5 Hash generation:
 *    <code>
 *    STFSAL pstFSAL;
 *    kal_uint8 pbBuf[512];
 *    STCHE che_str;
 *    kal_uint8 digest[16];
 *    che_init(&che_str, CHE_MD5); 
 *    FSAL_Open(&pstFSAL, body_data_filepath, FSAL_READ);
 *    FSAL_SetBuffer(&pstFSAL, 512, pbBuf);
 *    if (che_process_from_file(&che_str, CHE_MD5, CHE_MODE_NULL, CHE_HASH,
 *                              &pstFSAL, digest) == KAL_FALSE)
 *    {
 *        FSAL_Close(&pstFSAL);
 *        che_deinit(&che_str);
 *        return ERROR;
 *    }
 *    ...
 *    FSAL_Close(&pstFSAL);
 *    // do other operations
 *    ...
 *    //Deinitialize when all operations are finish
 *    che_deinit(&che_str);
 *    </code>
 *
 *    5. HMAC MD5 generation:
 *    <code>
 *    STFSAL pstFSAL;
 *    kal_uint8 pbBuf[512];
 *    STCHE che_str;
 *    kal_uint8 digest[16];
 *    che_init(&che_str, CHE_MAC_MD5); 
 *    che_key_action(&che_context, CHE_SET_KEY,  (kal_uint8 *) key, key_len);
 *    FSAL_Open(&pstFSAL, body_data_filepath, FSAL_READ);
 *    FSAL_SetBuffer(&pstFSAL, 512, pbBuf);
 *    if (che_process_from_file(&che_str, CHE_MAC_MD5, CHE_MODE_NULL, CHE_HASH,
 *                              &pstFSAL, digest) == KAL_FALSE)
 *    {
 *        FSAL_Close(&pstFSAL);
 *        che_deinit(&che_str);
 *        return ERROR;
 *    }
 *    ...
 *    FSAL_Close(&pstFSAL);
 *    // do other operations
 *    ...
 *    //Deinitialize when all operations are finish
 *    che_deinit(&che_str);
 *    </code>
 *   
 *    6. Diffie-Hellman: (key = (G^Y)^X mod P)
 *    get the discrete logarithms (X) and compute self public value (G^X mod P)
 *    <code>
 *    STFSAL pstFSAL;
 *    kal_uint8 pbBuf[512];
 *    STCHE che_str;
 *    che_init(&che_str, CHE_DH);
 *    che_process(&che_ctx_dh, CHE_DH, CHE_MODE_NULL, DH_INIT, NULL, NULL, 0, KAL_TRUE);
 *    // set the P and G that P and G must in binary format
 *    che_key_action(&che_ctx_dh, CHE_SET_DH_P, (kal_uint8*) P, P_Len);
 *    che_key_action(&che_ctx_dh, CHE_SET_DH_G, G, G_Len);
 *    // make self public (G^X mod P) and private (X)
 *    che_process(&che_ctx_dh, CHE_DH, CHE_MODE_NULL, DH_MAKE_PARAMS, NULL, NULL, 0, KAL_TRUE);
 *    // get the self public
 *    che_key_action(&che_ctx_dh, CHE_GET_DH_SELF_PUBLIC_LEN, (void*)&self_public_len, sizeof(int));
 *    // get the self public
 *    *self_private = malloc(self_private_len);
 *    che_key_action(&che_ctx_dh, CHE_GET_DH_PRIVATE, (kal_uint8*) (*priv)->v, dh_private_len);
 *    FSAL_Open(&pstFSAL, body_data_filepath, FSAL_READ);
 *    FSAL_SetBuffer(&pstFSAL, 512, pbBuf);
 *    if (che_process_from_file(&che_str, CHE_MD5, CHE_MODE_NULL, CHE_ENC,
 *                              &pstFSAL, digest) == KAL_FALSE)
 *    {
 *        FSAL_Close(&pstFSAL);
 *        che_deinit(&che_str);
 *        return ERROR;
 *    }
 *    ...
 *    FSAL_Close(&pstFSAL);
 *    // do other operations
 *    ...
 *    //Deinitialize when all operations are finish
 *    che_deinit(&che_str);
 *    </code>
 *****************************************************************************/
#define che_process_from_file(che_context, type, mode, act, pstFSAL, dest)                                      \
                                                                                                                \
   ((void)TRICK_##type, run_##type##_process(che_context, type, mode, act, 0, dest, 0, 0, pstFSAL))                    

/*****************************************************************************
 * FUNCTION
 *  che_duplicate
 * DESCRIPTION
 *  Duplicate the CHE structure and current content. 
 *  This API only supports CHE_MD5, CHE_SHA1, CHE_MD4, CHE_MAC_MD5, CHE_MAC_SHA1.
 *  The situation application may encounter and wish to use this API:
 *                   packet1
 *  Step 1: A ------------------------->  B  (B receives packet1 and generates the hash value)
 *                   packet2
 *  Step 2: A ------------------------->  B  (B receives another packet2 and generates the hash value again)
 *  
 *  In this case, application may wish the result of step 2 is the continue of step 1. 
 *  To fulfill user's need, we provide this API for user to store the temporary CHE cotext for
 *  later use.
 * PARAMETERS
 *  src_che_context  : [IN]   source CHE context
 *  dst_che_context  : [IN]   destination CHE context 
 *                       
 * RETURN VALUES
 *  KAL_TRUE : success
 *  KAL_FALSE : fail
 * EXAMPLE
 * <code>
 * STCHE dst_context;
 * che_duplicate(&dst_context, &src_context);
 * </code>
 *****************************************************************************/
extern kal_bool che_duplicate(STCHE *src_che_context, STCHE *dst_che_context);

/*****************************************************************************
 * FUNCTION
 *  che_rsa_generate_key
 * DESCRIPTION
 *  genereate RSA key by public exponent (e).
 * PARAMETERS
 *  ctx      : [IN]     CHE context
 *  nbits   : [IN]   number of bits in the modulus
 *  exponent :[IN] public exponent value
 *  f_rng       :[IN] random number generator function
 *  p_rng      :[IN] input parameter for random number generator function
 *                       
 * RETURN VALUES
 *  CHE_OK : success
 *  CHE_ERROR : parameter error
 *  CHE_OPERATION_FAIL : algorithm operation is failed
 * EXAMPLE
 * <code>
 *     kal_int32 ret;
 *     STCHE * che_ctx;
 *     //initialize
 *     che_init(&che_ctx, CHE_RSA);
 *     ret = che_rsa_generate_key(&che_ctx, 1024, 37, random_gen_func_p, random_para);
 *     if (ret == CHE_OK)
 *     {
 *         // generate key successfully
 *         // can get key from che_ctx
 *         
 *     }
 * </code>
 *****************************************************************************/
extern kal_int32 che_rsa_generate_key( STCHE *ctx, kal_int32 nbits, kal_int32 exponent,  kal_int32 (*f_rng)(void *), void *p_rng);

/*****************************************************************************
 * FUNCTION
 *  che_rsa_public_encrypt
 * DESCRIPTION
 *  This API is used when we want to use public key to encrypt the data.
 *  Application can specify the way of padding based PKCS#1 standard.
 *  If application doesn't want to do the padding, s/he can set the padding to 
 *  CHE_RSA_MODE_NULL.
 *
 *  Based on PKCS#1v1.5 standard, the smallest padding size is 11 bytes.
 *  Thus, the destination buffer should be:
 *  Destination_buffer_len = input_data_len + 11(smallest padding data)
 *  In addition, the output buffer size is equal to the size of N.
 *  If the input data length is too large or destination buffer is too small,
 *  the error cause will be returned. The output buffer length will be checked only
 *  If the passed in length is not 0. If it is 0, this means user doesn't want to check
 *  the destination buffer length.
 *  The input and output buffer can be the same one.
 *
 *  RSA valid public key length:
 *  128 bits < Modulus (N) < 4096 bits
 *  2 bits < public exponent (E) < 64  bits
 * PARAMETERS
 *  ctx      : [IN]     CHE context
 *  src      : [IN]     source buffer
 *  src_len  : [IN]     source buffer length (the length sould < length of N)
 *  dst      : [OUT]    destination buffer (must pass in)
 *  dst_len  : [IN/OUT] encrypted destination length. If user pass in non zero value,
 *                      CHE will do the destination buffer length check. If the length
 *                      smaller than the length of N. The error is returned. However,
 *                      If user pass in value 0, che will not do the length checking.
 *  padding  : [IN]     the way of padding. Currently we only support PKCS#1v1.5 padding.
 *                      If user doesn't want any padding, s/he can pass in CHE_RSA_MODE_NULL.
 *                      Please take reference of the enum che_rsa_padding_mode_enum
 *                       
 * RETURN VALUES
 *  take the reference of che_result_error_enum.
 *  CHE_OK : success
 *  CHE_ERROR : parameter error
 *  CHE_KEY_CHK_FAIL : input key is not correct
 *  CHE_INVALID_LENGTH : the input data length is too large or 
 *                       destination buffer is too small
 *  CHE_OPERATION_FAIL : algorithm operation is failed
 * SEE ALSO
 *  che_rsa_private_decrypt
 * EXAMPLE
 *  (a). Encrypt the data by public key without padding
 *     <code>
 *     STCHE * che_ctx;
 *     //initialize
 *     che_init(&che_ctx, CHE_RSA);
 *     //Set modulus: N
 *     che_key_action(&che_ctx, CHE_SET_RSA_N, modulusN, n_len);
 *     //Set public Exponent: E
 *     che_key_action(&che_ctx, CHE_SET_RSA_E, pubExp, e_len);
 *     //Encrypt Data by the public key
 *     che_rsa_public_encrypt(&che_ctx, src, src_len, dst, &dst_len, CHE_RSA_MODE_NULL);
 *     // do other operation
 *     ...
 *     //Deinitialize when all RSA operation is finish
 *     che_deinit(&che_ctx);
 *     </code>
 *
 *  (b). Encrypt the data by public key with PKCS#1v1.5 padding
 *     <code>
 *     STCHE * che_ctx;
 *     //initialize
 *     che_init(&che_ctx, CHE_RSA);
 *     //Set modulus: N
 *     che_key_action(&che_ctx, CHE_SET_RSA_N, modulusN, n_len);
 *     //Set public Exponent: E
 *     che_key_action(&che_ctx, CHE_SET_RSA_E, pubExp, e_len);
 *     //Encrypt Data by the public key
 *     che_rsa_public_encrypt(&che_ctx, src, src_len, dst, &dst_len, CHE_RSA_PKCS1_V15);
 *     // do other operation
 *     ...
 *     //Deinitialize when all RSA operation is finish
 *     che_deinit(&che_ctx);
 *     </code>
 *****************************************************************************/
extern kal_int32 che_rsa_public_encrypt(STCHE *ctx, kal_uint8 *src, kal_uint32 src_len, kal_uint8 *dst, kal_uint32 *dst_len, che_rsa_padding_mode_enum padding);

/*****************************************************************************
 * FUNCTION
 *  che_rsa_private_encrypt
 * DESCRIPTION
 *  This API is used when we want to use private key to encrypt the data.
 *  Application can specify the way of padding based PKCS#1 standard.
 *  If users don't want to do the padding, they can set the padding to 
 *  CHE_RSA_MODE_NULL.
 *
 *  Based on PKCS#1v1.5 standard, the smallest padding size is 11 bytes.
 *  Thus, the destination buffer should be:
 *  Destination_buffer_len = input_data_len + 11(smallest padding data)
 *  In addition, the output buffer size is equal to the size of N.
 *  If the input data length is too large or destination buffer is too small,
 *  the error cause will be returned. The output buffer length will be checked only
 *  If the passed in length is not 0. If it is 0, this means user doesn't want to check
 *  the destination buffer length.
 *  The input and output buffer can be the same one.
 *
 * PARAMETERS
 *  ctx      : [IN]     CHE context
 *  src      : [IN]     source buffer
 *  src_len  : [IN]     source buffer length (the length sould < length of N)
 *  dst      : [OUT]    destination buffer (must pass in)
 *  dst_len  : [IN/OUT] encrypted destination length. If user pass in non zero value,
 *                      CHE will do the destination buffer length check. If the length
 *                      smaller than the length of N. The error is returned. However,
 *                      If user pass in value 0, che will not do the length checking.
 *  padding  : [IN]     the way of padding. Currently we only support PKCS#1v1.5 padding.
 *                      If users don't want any padding, they can pass in CHE_RSA_MODE_NULL.
 *                      (che_rsa_padding_mode_enum)
 *                       
 * RETURN VALUES
 *  take the reference of che_result_error_enum.
 *  CHE_OK : success
 *  CHE_ERROR : parameter error
 *  CHE_KEY_CHK_FAIL : input key is not correct
 *  CHE_INVALID_LENGTH : the input data length is too large or 
 *                       destination buffer is too small
 *  CHE_OPERATION_FAIL : algorithm operation is failed
 * SEE ALSO
 *  che_rsa_public_decrypt
 * EXAMPLE
 *  (a). Encrypt the data by private key without padding
 *   We set the mode to CHE_RSA_MODE_NULL to indicate that we don't 
 *   encode the input data with any padding method
 *     <code>
 *     STCHE che_ctx;
 *     //initialize
 *     che_init(&che_ctx, CHE_RSA);
 *     //Set modulus: N
 *     che_key_action(&che_ctx, CHE_SET_RSA_N, modulusN, n_len);
 *     //Set private key: D
 *     che_key_action(&che_ctx, CHE_SET_RSA_D, privD, d_len);
 *     //Encrypt Data by the private key
 *     che_rsa_private_encrypt(&che_ctx, src, src_len, dst, &dst_len, CHE_RSA_MODE_NULL);
 *     // do other operation
 *     ...
 *     //Deinitialize when all RSA operation is finish
 *     che_deinit(&che_ctx);
 *     </code>
 *
 *  (b). Encrypt the data by private key with PKCS#1v1.5 padding
 *     <code>
 *     STCHE che_ctx;
 *     //initialize
 *     che_init(&che_ctx, CHE_RSA);
 *     //Set modulus: N
 *     che_key_action(&che_ctx, CHE_SET_RSA_N, modulusN, n_len);
 *     //Set private key: D
 *     che_key_action(&che_ctx, CHE_SET_RSA_D, privD, d_len);
 *     //Encrypt Data by the private key
 *     che_rsa_private_encrypt(&che_ctx, src, src_len, dst, &dst_len, CHE_RSA_PKCS1_V15);
 *     // do other operation
 *     ...
 *     //Deinitialize when all RSA operation is finish
 *     che_deinit(&che_ctx);
 *     </code>
 *
 *   (c). Encryption the data by the private key (CRT format) with PKCS1#v15 padding
 *    <code>
 *     STCHE che_ctx;
 *    // initialize
 *    che_init(&che_ctx, CHE_RSA);
 *    // set modulus: N
 *    che_key_action(&che_ctx, CHE_SET_RSA_N, modulusN, n_len);
 *    // set P for private key checking
 *    che_key_action(&che_ctx, CHE_SET_RSA_P, (kal_uint8 *)primeP, P_len);
 *    // set Q for private key checking
 *    che_key_action(&che_ctx, CHE_SET_RSA_Q, (kal_uint8 *)primeQ, q_len);
 *    // Set private exponent: d mod (p-1)
 *    che_key_action(&che_ctx, CHE_SET_RSA_dModPm1, dModPm1, dp_len);
 *    // Set private exponent: d mod (q-1)
 *    che_key_action(&che_ctx, CHE_SET_RSA_dModQm1, dModQm1, 32);
 *    // Set coefficient Integer: inverse of q mod p
 *    che_key_action(&che_ctx, CHE_SET_RSA_qInvModP, qInvModP, 32);
 *    //Encrypt Data by the private key
 *    che_rsa_private_encrypt(&che_ctx, src, src_len, dst, &dst_len, CHE_RSA_PKCS1_V15);
 *    // do other operation
 *    ...
 *    //Deinitialize when all RSA operation is finish
 *    che_deinit(&che_ctx);
 *    </code>
 *****************************************************************************/
extern kal_int32 che_rsa_private_encrypt(STCHE *ctx, kal_uint8 *src, kal_uint32 src_len, kal_uint8 *dst, kal_uint32 *dst_len, che_rsa_padding_mode_enum padding);

/*****************************************************************************
 * FUNCTION
 *  che_rsa_public_decrypt
 * DESCRIPTION
 *  This API is used when we want to use public key to decrypt the data.
 *  Application can specify the way of padding based PCKS#1 standard.
 *  If users don't want to do the padding, they can set the padding to 
 *  CHE_RSA_MODE_NULL.
 *  If the input data is too large (> size of N), the error will be returned.
 *  If the input data is too small ( < smallest padding length(11)), 
 *  the error will be returned as well. 
 *  The input and output buffer can be the same one.
 *
 *  RSA valid public key length:
 *  128 bits < Modulus (N) < 4096 bits
 *  2 bits < public exponent (E) < 64  bits
 * PARAMETERS
 *  ctx      : [IN]     CHE context
 *  src      : [IN]     source buffer
 *  src_len  : [IN]     source buffer length (the length sould < length of N)
 *  dst      : [OUT]    destination buffer (must pass in)
 *  dst_len  : [IN/OUT] encrypted destination length. If user pass in non zero value,
 *                      CHE will do the destination buffer length check. If the length
 *                      smaller than the length of N. The error is returned. However,
 *                      If user pass in value 0, che will not do the length checking.
 *  padding  : [IN]     the way of padding. Currently we only support PKCS#1v1.5 padding.
 *                      If users don't want any padding, they can pass in CHE_RSA_MODE_NULL.
 *                      (che_rsa_padding_mode_enum)
 *                       
 * RETURN VALUES
 *  take the reference of che_result_error_enum.
 *  CHE_OK : success
 *  CHE_ERROR : parameter error
 *  CHE_KEY_CHK_FAIL : input key is not correct
 *  CHE_INVALID_LENGTH : input data is too small or too long
 *  CHE_OPERATION_FAIL : algorithm operation is failed
 * SEE ALSO
 *  che_rsa_private_encrypt
 * EXAMPLE
 *  (a). Decrypt the data by public key without padding
 *     <code>
 *     STCHE che_ctx;
 *     //initialize
 *     che_init(&che_ctx, CHE_RSA);
 *     //Set modulus: N
 *     che_key_action(&che_ctx, CHE_SET_RSA_N, modulusN, n_len);
 *     //Set public Exponent: E
 *     che_key_action(&che_ctx, CHE_SET_RSA_E, pubExp, e_len);
 *     //Decrypt Data by the public key
 *     che_rsa_public_decrypt(&che_ctx, src, src_len, dst, &dst_len, CHE_RSA_MODE_NULL);
 *     // do other operation
 *     ...
 *     //Deinitialize when all RSA operation is finish
 *     che_deinit(&che_ctx);
 *     </code>
 *
 *  (b). Decrypt the data by public key with PKCS#1v1.5 padding
 *     <code>
 *     STCHE che_ctx;
 *     //initialize
 *     che_init(&che_ctx, CHE_RSA);
 *     //Set modulus: N
 *     che_key_action(&che_ctx, CHE_SET_RSA_N, modulusN, n_len);
 *     //Set public Exponent: E
 *     che_key_action(&che_ctx, CHE_SET_RSA_E, pubExp, e_len);
 *     //Decrypt Data by the public key
 *     che_rsa_public_decrypt(&che_ctx, src, src_len, dst, &dst_len, CHE_RSA_PKCS1_V15);
 *     // do other operation
 *     ...
 *     //Deinitialize when all RSA operation is finish
 *     che_deinit(&che_ctx);
 *     </code>
 *****************************************************************************/
extern kal_int32 che_rsa_public_decrypt(STCHE *ctx, kal_uint8 *src, kal_uint32 src_len, kal_uint8 *dst, kal_uint32 *dst_len, che_rsa_padding_mode_enum padding);

/*****************************************************************************
 * FUNCTION
 *  che_rsa_private_decrypt
 * DESCRIPTION
 *  This API is used when we want to use private key to decrypt the data.
 *  Application can specify the way of padding based PCKS#1 standard.
 *  If users don't want to do the padding, they can set the padding to 
 *  CHE_RSA_MODE_NULL.
 *
 *  If the input data is too large (> size of N), the error will be returned.
 *  If the input data is too small ( < smallest padding length(11)), 
 *  the error will be returned as well. 
 *  The input and output buffer can be the same one.
 *
 * PARAMETERS
 *  ctx      : [IN]     CHE context
 *  src      : [IN]     source buffer
 *  src_len  : [IN]     source buffer length (the length sould < length of N)
 *  dst      : [OUT]    destination buffer (must pass in)
 *  dst_len  : [IN/OUT] encrypted destination length. If user pass in non zero value,
 *                      CHE will do the destination buffer length check. If the length
 *                      smaller than the length of N. The error is returned. However,
 *                      If user pass in value 0, che will not do the length checking.
 *  padding  : [IN]     the way of padding. Currently we only support PKCS#1v1.5 padding.
 *                      If users don't want any padding, they can pass in CHE_RSA_MODE_NULL.
 *                      (che_rsa_padding_mode_enum)
 *                       
 * RETURN VALUES
 *  take the reference of che_result_error_enum.
 *  CHE_OK : success
 *  CHE_ERROR : parameter error
 *  CHE_KEY_CHK_FAIL : input key is not correct
 *  CHE_INVALID_LENGTH : input data is too small or too long
 *  CHE_OPERATION_FAIL : algorithm operation is failed
 * SEE ALSO
 *  che_rsa_public_encrypt
 * EXAMPLE
 *  (a). Decrypt the data by private key without padding
 *   We set the mode to CHE_RSA_MODE_NULL to indicate that we don't encode the input data with any padding method
 *     <code>
 *     STCHE che_ctx;
 *     //initialize
 *     che_init(&che_ctx, CHE_RSA);
 *     //Set modulus: N
 *     che_key_action(&che_ctx, CHE_SET_RSA_N, modulusN, n_len);
 *     //Set private key: D
 *     che_key_action(&che_ctx, CHE_SET_RSA_D, privD, d_len);
 *     //Decrypt Data by the private key
 *     che_rsa_private_decrypt(&che_ctx, src, src_len, dst, &dst_len, CHE_RSA_MODE_NULL);
 *     // do other operation
 *     ...
 *     //Deinitialize when all RSA operation is finish
 *     che_deinit(&che_ctx);
 *     </code>
 *
 *  (b). Decrypt the data by private key with PKCS#1v1.5 padding
 *     <code>
 *     STCHE che_ctx;
 *     //initialize
 *     che_init(&che_ctx, CHE_RSA);
 *     //Set modulus: N
 *     che_key_action(&che_ctx, CHE_SET_RSA_N, modulusN, n_len);
 *     //Set private key: D
 *     che_key_action(&che_ctx, CHE_SET_RSA_D, privD, d_len);
 *     //decrypt Data by the private key
 *     che_rsa_private_decrypt(&che_ctx, src, src_len, dst, &dst_len, CHE_RSA_PKCS1_V15);
 *     // do other operation
 *     ...
 *     //Deinitialize when all RSA operation is finish
 *     che_deinit(&che_ctx);
 *     </code>
 *
 *  (c). Decrypt the data by private key (CRT format) with PKCS#1v1.5 padding
 *     <code>
 *     STCHE che_ctx;
 *     //initialize
 *     che_init(&che_ctx, CHE_RSA);
 *     // set modulus: N
 *     che_key_action(&che_ctx, CHE_SET_RSA_N, modulusN, n_len);
 *     // set P for private key checking
 *     che_key_action(&che_ctx, CHE_SET_RSA_P, (kal_uint8 *)primeP, P_len);
 *     // set Q for private key checking
 *     che_key_action(&che_ctx, CHE_SET_RSA_Q, (kal_uint8 *)primeQ, q_len);
 *     // Set private exponent: d mod (p-1)
 *     che_key_action(&che_ctx, CHE_SET_RSA_dModPm1, dModPm1, dp_len);
 *     // Set private exponent: d mod (q-1)
 *     che_key_action(&che_ctx, CHE_SET_RSA_dModQm1, dModQm1, 32);
 *     // Set coefficient Integer: inverse of q mod p
 *     che_key_action(&che_ctx, CHE_SET_RSA_qInvModP, qInvModP, 32);
 *     //decrypt Data by the private key
 *     che_rsa_private_decrypt(&che_ctx, src, src_len, dst, &dst_len, CHE_RSA_PKCS1_V15);
 *     // do other operation
 *     ...
 *     //Deinitialize when all RSA operation is finish
 *     che_deinit(&che_ctx);
 *     </code>
 *****************************************************************************/
extern kal_int32 che_rsa_private_decrypt(STCHE *ctx, kal_uint8 *src, kal_uint32 src_len, kal_uint8 *dst, kal_uint32 *dst_len, che_rsa_padding_mode_enum padding);

#endif /* _CHE_API_H */ 

/*
 * ! \page page3 Reference
 * 
 * 1) FEDERAL INFORMATION PROCESSING STANDARDS PUBLICATION U.S. DEPARTMENT OF COMMERCE/national Institute of Standards and Technology 46-3 : DATA ENCRYPTION STANDARD (DES)\n
 * 2) FEDERAL INFORMATION  PROCESSING STANDARDS PUBLICATION 197 : ADVANCED ENCRYPTION STANDARD (AES)\n
 * 3) FEDERAL INFORMATION  PROCESSING STANDARDS PUBLICATION 180-2 SECURE HASH STANDARD (SHA)\n
 * 4) MIT Laboratory for Computer Science and RSA Data Security, Inc. : The MD5 Message-Digest Algorithm\n
 * 
 */

