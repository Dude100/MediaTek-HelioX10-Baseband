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
 *   ssl_enums.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains enums of SSL API.
 *
 * Author:
 * -------
 * -------
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _SSL_ENUMS_H
#define _SSL_ENUMS_H

#if 0 /* XXX, CODING NOTE DO NOT SHOW IN DOM DOCUMENTS! */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* CODING NOTE DO NOT SHOW IN DOM DOCUMENTS! */

/***************************************************************************
 * <GROUP Enums>
 *
 * Error code of SSL APIs.
 ***************************************************************************/
typedef enum {
    SEC_ERROR_FS                = -128, /* File system operation failed. */
    SEC_ERROR_NULL_PTR          = -127, /* No valid pointer to wrapper context. */

    SEC_ERROR_LOCAL_IDENTITY_REQUESTED = -256, /* Server requested for client certificate. */
    SEC_ERROR_NONE              =  0x0000,     /* No error. */
    SEC_ERROR_PTR               =  0x0001,     /* Null pointer. */
    SEC_ERROR_PARAM             =  0x0002,     /* Illegal parameter. */
    SEC_ERROR_BUFFER_SIZE       =  0x0003,     /* Buffer too small. */
    SEC_ERROR_WOULDBLOCK        = -0x0004,     /* I/O is blocking. */
    //SEC_ERROR_WOULDBLOCK      =  0x0004,
    SEC_ERROR_TIMEOUT           =  0x0005,     /* Timeout. */
    SEC_ERROR_BAD_LEN           =  0x0006,     /* Bad length. */
    SEC_ERROR_NOT_FOUND         =  0x0007,     /* Object not found. */
    SEC_ERROR_BAD_CTX           =  0x0008,     /* Bad context. */
    SEC_ERROR_BAD_IDX           =  0x0009,     /* Bad index. */
    SEC_ERROR_RANDOM            =  0x000A,     /* Entropy generation. */
    SEC_ERROR_MEM_UNDERRUN      =  0x000B,     /* Memory no enough. */
    SEC_ERROR_MEM_OVERRUN       =  0x000C,     /* Memory overrun. */
    SEC_ERROR_MEM_FREED         =  0x000D,     /* CIC_ERR_MEM_WAS_FREED */
    SEC_ERROR_MEM_NOT_OURS      =  0x000E,     /* Duplicate free.  */
    SEC_ERROR_MEM_ZERO          =  0x000F,     /* Freeing unallocated memory. */

    SEC_ERROR_BAD_DER_ENCODING  =  0x0218,     /* Bad DER encoding. */
    SEC_ERROR_INCOMPLETE_ID     =  0x1001,     /* The identity doesn't contain both a private key and a certificate */
    SEC_ERROR_SSL_BAD_SIDE      =  0x1002,     /* Incorrect connection side. */
    SEC_ERROR_SSL_OVERFLOW      =  0x1003,     /* A record exceeds the size of the read/write buffer. */
    SEC_ERROR_SSL_UNEXP_MSG     =  0x1004,     /* Received an unexpected messasge. */
    SEC_ERROR_SSL_BAD_MAC       =  0x1005,     /* The record MAC is incorrect. */
    SEC_ERROR_SSL_DECRYPT       =  0x1006,     /* Decrypting message failed. */
    SEC_ERROR_SSL_UNKNOWN_REC   =  0x1007,     /* Unknown record type. */
    SEC_ERROR_SSL_NEGOTIATION   =  0x1008,     /* Renegotiation failed. */
    SEC_ERROR_SSL_IO            = -0x1009,     /* I/O error. */
    SEC_ERROR_SSL_FATAL_ALERT   =  0x100A,     /* Fatal alert happened. */
    SEC_ERROR_SSL_PROTOCOL      =  0x100B,     /* SSL protocol error. */
    SEC_ERROR_SSL_RESUME_SESS   =  0x100C,     /* Peer is resuming a session with different parameters. */
    SEC_ERROR_SSL_BAD_FIN_MSG   =  0x100D,     /* Received bad "Finished" message. */
    SEC_ERROR_SSL_GRACE_CLOSED  =  0x100E,     /* SSL connection is closed with graceful manner. */
    SEC_ERROR_SSL_CLOSED        =  0x100F,     /* SSL connection is closed. */
    SEC_ERROR_SSL_BAD_CERT      =  0x1011,     /* Bad certificate. */
    SEC_ERROR_SSL_SESS_NOT_FOUND=  0x1013,     /* Session was not found in session DB. */
    SEC_ERROR_SSL_PROTOCOL_VER  =  0x1019,     /* Bad protocol version. */
    SEC_ERROR_SSL_NO_CERT       =  0x101E,     /* Peer sends no certificate */
    SEC_ERROR_SSL_NO_MATCHING_CERTS = 0x101F,  /* The certificate is not signed by trusted CA. */
    SEC_ERROR_SSL_CERT_VALIDATE_FAILED = 0x1020,   /* User's validation callback returns error. */
    SEC_ERROR_SSL_NULL_CB       =  0x1022,     /* Passed NULL callback. */
    SEC_ERROR_SSL_ENTROPY       =  0x1024,     /* The entropy fail to generate enough seeds. */
    SEC_ERROR_SSL_BAD_CONTEXT   =  0x102F,     /* Incorrect SSL context. */
    SEC_ERROR_SSL_HSHK_REQUIRED =  0x1030,     /* Handshake required for the operation. */
    SEC_ERROR_SSL_HSHK_REQUESTED=  0x1031,     /* Handshake request by peer. */
    SEC_ERROR_SSL_RENEGOTIATE_REFUSED = 0x1032,/* Rehandshake refused by peer. */
    SEC_ERROR_SSL_HSHK_COMPLETED      = 0x1033,/* Handshake already completed. */
    SEC_ERROR_SSL_READ_REQUIRED =  0x1035,     /* There is application data to be read before handshake. */
    SEC_ERROR_SSL_UNSUPP_PUBKEY =  0x1036,     /* Unsupported public key type. */
    SEC_ERROR_SSL_BAD_REC_LEN   =  0x1037,     /* Bad record length. */
    SEC_ERROR_SSL_NEEDS_CIPHER  =  0x1038,     /* No cipher suites provided. */
    SEC_ERROR_SSL_NEEDS_PRNG    =  0x103B,     /* No PRNG suite is installed. */
    SEC_ERROR_SSL_CERT_CHAIN_WARN = 0x103C,    /* There are warnings in the validation. */
    SEC_ERROR_SSL_TRUSTED_EXPIRED     = 0x103D,/* The certificate is expired. */
    SEC_ERROR_SSL_NO_TRUSTED_ISSUER   = 0x1046,/* No trusted issuer was found while verifing certificate. */
    SEC_ERROR_SSL_INVALID_CERT_CHAIN  = 0x1053,/* The certificate chain is invalid. */
    SEC_ERROR_SSL_COMPRESS_CALLBACK   = 0x1056,/* The compression callback returned an error.  */
    SEC_ERROR_SSL_COMPRESS_EX_MAX_LEN = 0x1057,/* The decompressed output is greater than 2^14 bytes. */
    SEC_ERROR_SSL_INTERNAL_TP_VALIDATE= 0x106B,/* Unexpected error in certificate chain validation. */

    SEC_ERROR_BAD_ENCODING      = 0x0221,      /* Bad encoding. */
    SEC_ERROR_BAD_PEM           = 0x0222,      /* Bad PEM encoding. */
    SEC_ERROR_NOT_IMPL          = 0x0FFE,      /* Feature not implemneted. */
    SEC_ERROR_INTERNAL          = 0x0FFF,      /* SSL library internal error. */
    SEC_ERROR_MEM               = 0xF001,      /* Memory error. */
    SEC_ERROR_UNKNOWN           = 0xFFFF       /* Other errors. */
} ssl_error_enum;



/***************************************************************************
 * <GROUP Enums>
 *
 * SSL alert levels, Ref. RFC 4346, Section 7.2.
 ***************************************************************************/
typedef enum {
    SSL_AL_LEVEL_WARNING = 1, /* Warning alert. */
    SSL_AL_LEVEL_FATAL   = 2, /* Fatal alert, application MUST terminate the connection immediately. */
    SSL_AL_LEVEL_MAX   = 255
} ssl_alert_level;



/***************************************************************************
 * <GROUP Enums>
 *
 * SSL alert descriptions, Ref. RFC 4346, Section 7.2.2.
 ***************************************************************************/
typedef enum {
    SSL_AL_DESC_CLOSE_NOTIFY = 0,        /* Peer shuts down the connection. */
    SSL_AL_DESC_UNEXPECTED_MESSAGE = 10, /* Received an unexped mesage, always a fatal. */
    SSL_AL_DESC_BAD_RECORD_MAC = 20,     /* Bad MAC, always a fatal */
    SSL_AL_DESC_DECRYPTION_FAILED = 21,  /* Decryption failed, always a fatal. */
    SSL_AL_DESC_RECORD_OVERFLOW = 22,    /* Record size exceeds the limitation, always a fatal. */
    SSL_AL_DESC_DECOMPRESSION_FAILURE = 30,  /* Deccompression failed, always a fatal. */
    SSL_AL_DESC_HANDSHAKE_FAILURE = 40,      /* Handshake failed, fatal. */
    SSL_AL_DESC_NO_CERTIFICATE_reserved  = 41,  /* Response to a certification request if no appropriate certificate is available, SSLv3 only. */
    SSL_AL_DESC_BAD_CERTIFICATE = 42,   /* A certificate was corrupt, signatures that did not verify correctly. */
    SSL_AL_DESC_UNSUPPORTED_CERTIFICATE = 43, /* Unsupported certificate type. */
    SSL_AL_DESC_CERTIFICATE_REVOKED = 44,     /* Received a revoked certificate from peer. */
    SSL_AL_DESC_CERTIFICATE_EXPIRED = 45,     /* A certificate has expired or not yet valid */
    SSL_AL_DESC_CERTIFICATE_UNKNOWN = 46,  /* Some unspecificate issue in processing the certificate. */
    SSL_AL_DESC_ILLEGAL_PARAMETER = 47,  /* Illegal parameter in the message, always a fatal. */
    SSL_AL_DESC_UNKNOWN_CA = 48,      /* The certificate chain cannot be verified successfully due to untrusted CA, always a fatal. */
    SSL_AL_DESC_ACCESS_DENIED = 49, /* sender decided not to proceed with negotiation when access control was applied, always a fatal. */
    SSL_AL_DESC_DECODE_ERROR = 50,  /* The field in a message is incorrect, always a fatal. */
    SSL_AL_DESC_DECRYPT_ERROR = 51, /* a handshake cryptographic operation failed, including verify a signature, decrypt a key exchange, or validate a finished mesasge */
    SSL_AL_DESC_EXPORT_RESTRICTION_reserved = 60, /* A negotiation not in compliance with export restrictions was detected.  */
    SSL_AL_DESC_PROTOCOL_VERSION = 70,      /* The protocol version proposed by client is not supported by server side, always a fatal. */
    SSL_AL_DESC_INSUFFICIENT_SECURITY = 71, /* The server requires cphers more secure than those supported by the client, always a fatal. */
    SSL_AL_DESC_INTERNAL_ERROR = 80,  /* An internal error unrelated to the peer, always a fatal. */
    SSL_AL_DESC_USER_CANCELED = 90,   /* The handshake is canceled for some reason unrelated to a protocol failure, generally a warning. */
    SSL_AL_DESC_NO_RENEGOTIATION = 100, /* When peer suggest to renegotiate again but local rejects it, always a warning */
    SSL_AL_DESC_MAX = 255
} ssl_alert_desc;



/***************************************************************************
 * <GROUP Enums>
 *
 * Inicating encoding of certificates passed to SSL APIs.
 ***************************************************************************/
typedef enum {
    SEC_SSL_FILETYPE_PEM, /* PEM encoding */
    SEC_SSL_FILETYPE_ASN1 /* DER encoding */
} ssl_filetype_enum;


#if 0 /* CODING NOTE DO NOT SHOW IN DOM DOCUMENTS! */
/* under construction !*/
#endif /* CODING NOTE DO NOT SHOW IN DOM DOCUMENTS! */

/***************************************************************************
 * <GROUP Enums>
 *
 * Client authentication modes to be used in the SSL context,
 * Ref. sec_ssl_ctx_set_client_auth_modes().
 ***************************************************************************/
typedef enum {
    RSA_SIGN_CLIENTSIDE   = 0, /* RSA client side */
    RSA_SIGN_SERVERSIDE   = 1, /* RSA server side */
    DSS_SIGN_CLIENTSIDE   = 2, /* DSS(DSA) cient side */
    DSS_SIGN_SERVERSIDE   = 3, /* DSS(DSA) server side */
    CLIENT_AUTH_MODE_END  = 0xff,
    SERVER_AUTH_MODE_END  = CLIENT_AUTH_MODE_END,
    SEC_AUTH_MODE_END     = CLIENT_AUTH_MODE_END
} ssl_auth_mode_enum;


#if 0 /* CODING NOTE DO NOT SHOW IN DOM DOCUMENTS! */
/* under construction !*/
/* under construction !*/
#endif /* CODING NOTE DO NOT SHOW IN DOM DOCUMENTS! */

/***************************************************************************
 * <GROUP Enums>
 *
 * Supported ciphersuites to be specified in sec_ssl_ctx_set_cipher_list().
 ***************************************************************************/
typedef enum {
    /* SSLv2, SSLv3, TLSv1 cipher suites */
    NULL_MD5                = 0,  /* 0x0001, TLS_RSA_WITH_NULL_MD5 */
    EXP_RC4_MD5             = 1,  /* 0x0003, TLS_RSA_EXPORT_WITH_RC4_40_MD5 */
    RC4_MD5                 = 2,  /* 0x0004, TLS_RSA_WITH_RC4_128_MD5 */
    RC4_SHA                 = 3,  /* 0x0005, TLS_RSA_WITH_RC4_128_SHA, TLS Profile MUST */
    EXP_DES_CBC_SHA         = 4,  /* 0x0008, TLS_RSA_EXPORT_WITH_DES40_CBC_SHA */
    DES_CBC_SHA             = 5,  /* 0x0009, TLS_RSA_WITH_DES_CBC_SHA */
    DES_CBC3_SHA            = 6,  /* 0x000A, TLS_RSA_WITH_3DES_EDE_CBC_SHA, TLS Profile MUST */
    EXP_EDH_DSS_DES_CBC_SHA = 7,  /* 0x0011, TLS_DHE_DSS_EXPORT_WITH_DES40_CBC_SHA */
    EDH_DSS_CBC_SHA         = 8,  /* 0x0012, TLS_DHE_DSS_WITH_DES_CBC_SHA */
    EDH_DSS_DES_CBC3_SHA    = 9,  /* 0x0013, TLS_DHE_DSS_WITH_3DES_EDE_CBC_SHA */
    EXP_EDH_RSA_DES_CBC_SHA = 10, /* 0x0014, TLS_DHE_RSA_EXPORT_WITH_DES40_CBC_SHA */
    EDH_RSA_DES_CBC_SHA     = 11, /* 0x0015, TLS_DHE_RSA_WITH_DES_CBC_SHA */
    EDH_RSA_DES_CBC3_SHA    = 12, /* 0x0016, TLS_DHE_RSA_WITH_3DES_EDE_CBC_SHA */
    EXP_ADH_RC4_MD5         = 13, /* 0x0017, TLS_DH_anon_EXPORT_WITH_RC4_40_MD5 */
    ADH_RC4_MD5             = 14, /* 0x0018, TLS_DH_anon_WITH_RC4_128_MD5 */
    EXP_ADH_DES_CBC_SHA     = 15, /* 0x0019, TLS_DH_anon_EXPORT_WITH_DES40_CBC_SHA */
    ADH_DES_CBC_SHA         = 16, /* 0x001A, TLS_DH_anon_WITH_DES_CBC_SHA */
    ADH_DES_CBC3_SHA        = 17, /* 0x001B, TLS_DH_anon_WITH_3DES_EDE_CBC_SHA */

    /* AES ciphersuites from RFC 3268, extending TLS v1.0 */
    AES128_SHA              = 18, /* 0x002F, TLS_RSA_WITH_AES_128_CBC_SHA */
    AES256_SHA              = 19, /* 0x0035, TLS_RSA_WITH_AES_256_CBC_SHA */

    /* Additional Extport 1024 and other ciphersuites */
    EXP1024_DES_CBC_SHA     = 20, /* 0x0062, TLS_RSA_EXPORT1024_WITH_DES_CBC_SHA */
    EXP1024_RC4_SHA         = 21, /* 0x0064, TLS_RSA_EXPORT1024_WITH_RC4_56_SHA */
    DHE_DSS_RC4_SHA         = 22, /* 0x0066, TLS_DHE_DSS_WITH_RC4_128_SHA */

    /* ECDH */
    ECDH_SECT163K1_RC4_SHA  = 23, /* 0xC002 in RFC 4492, TLS_ECDH_ECDSA_WITH_RC4_128_SHA */
    ECDH_SECT163K1_NULL_SHA = 24, /* 0xC001 in RFC 4492, TLS_ECDH_ECDSA_WITH_NULL_SHA */

    /* PSK */    
    PSK_AES128_SHA          = 25, /* 0x008C in RFC 4279, TLS_PSK_WITH_AES_128_CBC_SHA */
    PSK_DES_CBC3_SHA        = 26, /* 0x008B in RFC 4279, TLS_PSK_WITH_3DES_EDE_CBC_SHA */
    SEC_TOTAL_CIPHER_NUM
} sec_cipher_enum;


/***************************************************************************
 * <GROUP Enums>
 *
 * SSL protocol versions, Ref. sec_cipher_info_struct(). 
 ***************************************************************************/
typedef enum
{
    SSL_VERSION_UNKNOWN = 0,
    SSL_VERSION_SSLV2,  /* SSLv2 */
    SSL_VERSION_SSLV3,  /* SSLv3 */
    SSL_VERSION_TLSV1,  /* TLSv1 */
    SSL_VERSION_DTLSV1  /* DTLSv1 */
} sec_proto_ver_enum;


/***************************************************************************
 * <GROUP Enums>
 *
 * SSL encryption algorithms, Ref. sec_cipher_info_struct().
 ***************************************************************************/
typedef enum
{
    SEC_ENC_ALGO_UNKNOWN,
    SEC_ENC_ALGO_NULL,      /* NULL */

    SEC_ENC_ALGO_DES_40,    /* DES 40 */
    SEC_ENC_ALGO_DES,       /* DES(56) */
    SEC_ENC_ALGO_3DES,      /* 3DES */

    SEC_ENC_ALGO_RC5,       /* RC5 */
    SEC_ENC_ALGO_RC5_56,    /* RC5_56 */

    SEC_ENC_ALGO_AES_128,   /* AES_128 */
    SEC_ENC_ALGO_AES_192,   /* AES_192,  new for OpenSSL */
    SEC_ENC_ALGO_AES_256,   /* AES_256 */

    SEC_ENC_ALGO_ARC4_40,   /* RC4_40 */
    SEC_ENC_ALGO_ARC4_56,   /* RC4_56, new for OpenSSL */
    SEC_ENC_ALGO_ARC4_64,   /* RC4_64, new for OpenSSL */
    SEC_ENC_ALGO_ARC4_128,  /* RC4_128 */

    SEC_ENC_ALGO_ARC2_40,   /* RC2_40 */
    SEC_ENC_ALGO_ARC2_56,   /* RC2_56, new for OpenSSL */
    SEC_ENC_ALGO_ARC2_64,   /* RC4_64 */
    SEC_ENC_ALGO_ARC2_128   /* RC2_128 */
} sec_bulk_enc_algo_enum;



/***************************************************************************
 * <GROUP Enums>
 *
 * SSL key exchange algorithms, Ref. sec_cipher_info_struct().
 ***************************************************************************/
typedef enum
{
    SEC_KEY_ALGO_UNKNOWN,
    SEC_KEY_ALGO_RSA,         /* RSA */
    SEC_KEY_ALGO_RSA_EXPORT,  /* RSA_EXPORT */
    SEC_KEY_ALGO_DH,          /* DH */
    SEC_KEY_ALGO_DH_EXPORT,   /* DH_EXPORT */
    SEC_KEY_ALGO_DHE,         /* DH */
    SEC_KEY_ALGO_DHE_EXPORT,  /* DH_EXPORT */
    SEC_KEY_ALGO_ECDH,        /* ECDH */
    SEC_KEY_ALGO_ECDHE,       /* ECDHE */
    SEC_KEY_ALGO_ECMQV,       /* ECMQV */
    SEC_KEY_ALGO_DSA,         /* DSA */
    SEC_KEY_ALGO_PSK,         /* PSK */
    SEC_KEY_ALGO_DHE_PSK,     /* DHE_PSK */
    SEC_KEY_ALGO_RSA_PSK,     /* RSA_PSK */
    SEC_KEY_ALGO_MAX          
} sec_key_xchg_algo_enum;



/***************************************************************************
 * <GROUP Enums>
 *
 * SSL server authentication algorithms, Ref. sec_cipher_info_struct().
 ***************************************************************************/
typedef enum
{
    SEC_AUTH_ALGO_UNKNOWN,
    SEC_AUTH_ALGO_ANON,      /* ANON */
    SEC_AUTH_ALGO_RSA,       /* RSA */
    SEC_AUTH_ALGO_DSS,       /* DSS */
    SEC_AUTH_ALGO_ECDSA,     /* ECDSA */
    SEC_AUTH_ALGO_PSK        /* PSK */
} sec_auth_algo_enum;



/***************************************************************************
 * <GROUP Enums>
 *
 * SSL message digest algorithms, Ref. sec_cipher_info_struct().
 ***************************************************************************/
typedef enum
{
    SEC_HASH_UNKNOWN,
    SEC_HASH_MD2,      /* MD2 */
    SEC_HASH_MD4,      /* MD4 */
    SEC_HASH_MD5,      /* MD5 */
    SEC_HASH_SHA1,     /* SHA1 */
    SEC_HASH_SHA224,   /* SHA224 */
    SEC_HASH_SHA256,   /* SHA256 */
    SEC_HASH_SHA384,   /* SHA384 */
    SEC_HASH_SHA512    /* SHA512 */
} sec_hash_algo_enum;



/***************************************************************************
 * <GROUP Enums>
 *
 * Random number generator, Ref. sec_ssl_ctx_set_prng().
 ***************************************************************************/
typedef enum {
    SEC_SSL_ANSIPRNG   /* ANSI PRNG */
} sec_ssl_prng_generator;



/***************************************************************************
 * <GROUP Enums>
 *
 * Ciphersuites, combination of authentication, key exchange, encryption,
 * and hash algorithms.
 ***************************************************************************/
typedef enum {
    SEC_CIPHER_NULL_WITH_NULL_NULL                = 0x0000, /* (NULL, NULL, NULL)*/
                                                                                                            
    SEC_CIPHER_RSA_WITH_NULL_MD5                  = 0x0001, /* (RSA, NULL, MD5) */
    SEC_CIPHER_RSA_WITH_NULL_SHA                  = 0x0002, /* (RSA, NULL, SHA) */
    SEC_CIPHER_RSA_EXPORT_WITH_RC4_40_MD5         = 0x0003, /* (RSA_EXPORT, RC4_40), MD5, TLS 1.0 */
    SEC_CIPHER_RSA_WITH_RC4_128_MD5               = 0x0004, /* (RSA, RC4_128, MD5) */
    SEC_CIPHER_RSA_WITH_RC4_128_SHA               = 0x0005, /* (RSA, RC4_128, SHA) */
    SEC_CIPHER_RSA_EXPORT_WITH_RC2_CBC_40_MD5     = 0x0006, /* (RSA_EXPORT, RC2_CBC_40, MD5), TLS 1.0 */
    SEC_CIPHER_RSA_WITH_IDEA_CBC_SHA              = 0x0007, /* (RSA, IDEA_CBC, SHA) */
    SEC_CIPHER_RSA_EXPORT_WITH_DES40_CBC_SHA      = 0x0008, /* (RSA_EXPORT, DES40_CBC, SHA), TLS 1.0 */
    SEC_CIPHER_RSA_WITH_DES_CBC_SHA               = 0x0009, /* (RSA, DES_CBC, SHA) */
    SEC_CIPHER_RSA_WITH_3DES_EDE_CBC_SHA          = 0x000A, /* (RSA, 3DES_EDE_CBC, SHA) */
                                                                                                            
    SEC_CIPHER_DH_DSS_EXPORT_WITH_DES40_CBC_SHA   = 0x000B, /* (DH_DSS_EXPORT, DES40_CBC, SHA), TLS 1.0 */
    SEC_CIPHER_DH_DSS_WITH_DES_CBC_SHA            = 0x000C, /* (DH_DSS, DES_CBC, SHA) */
    SEC_CIPHER_DH_DSS_WITH_3DES_EDE_CBC_SHA       = 0x000D, /* (DH_DSS, 3DES_EDE_CBC, SHA) */
    SEC_CIPHER_DH_RSA_EXPORT_WITH_DES40_CBC_SHA   = 0x000E, /* (DH_RSA_EXPORT, DES40_CBC, SHA), TLS 1.0 */
    SEC_CIPHER_DH_RSA_WITH_DES_CBC_SHA            = 0x000F, /* (DH_RSA, DES_CBC, SHA) */
    SEC_CIPHER_DH_RSA_WITH_3DES_EDE_CBC_SHA       = 0x0010, /* (DH_RSA, 3DES_EDE_CBC, SHA) */
    SEC_CIPHER_DHE_DSS_EXPORT_WITH_DES40_CBC_SHA  = 0x0011, /* (DHE_DSS_EXPORT, DES40_CBC, SHA), TLS 1.0 */
    SEC_CIPHER_DHE_DSS_WITH_DES_CBC_SHA           = 0x0012, /* (DHE_DSS, DES_CBCi, SHA) */
    SEC_CIPHER_DHE_DSS_WITH_3DES_EDE_CBC_SHA      = 0x0013, /* (DHE_DSS, 3DES_EDE_CBC, SHA) */
    SEC_CIPHER_DHE_RSA_EXPORT_WITH_DES40_CBC_SHA  = 0x0014, /* (DHE_RSA_EXPORT, DES40_CBC, SHA), TLS 1.0 */
    SEC_CIPHER_DHE_RSA_WITH_DES_CBC_SHA           = 0x0015, /* (DHE_RSA, DES_CBCi, SHA) */
    SEC_CIPHER_DHE_RSA_WITH_3DES_EDE_CBC_SHA      = 0x0016, /* (DHE_RSA, 3DES_EDE_CBC, SHA) */
                                                                                                         
    SEC_CIPHER_DH_anon_EXPORT_WITH_RC4_40_MD5     = 0x0017, /* (DH_anon_EXPORT, RC4_40, MD5), TLS 1.0 */
    SEC_CIPHER_DH_anon_WITH_RC4_128_MD5           = 0x0018, /* (DH_anon, RC4_128, MD5) */
    SEC_CIPHER_DH_anon_EXPORT_WITH_DES40_CBC_SHA  = 0x0019, /* (DH_anon, DES40_CBC, SHA), TLS 1.0 */
    SEC_CIPHER_DH_anon_WITH_DES_CBC_SHA           = 0x001A, /* (DH_anon, DES_CBC, SHA) */
    SEC_CIPHER_DH_anon_WITH_3DES_EDE_CBC_SHA      = 0x001B, /* (DH_anon, DES_CBC, SHA) */
                                                                                                         
    SEC_CIPHER_KRB5_WITH_DES_CBC_SHA              = 0x001E, /* (Kerberos, DES_CBC, SHA) */
    SEC_CIPHER_KRB5_WITH_3DES_EDE_CBC_SHA         = 0x001F, /* (Kerberos, 3DES_EDE_CBC, SHA) */
    SEC_CIPHER_KRB5_WITH_RC4_128_SHA              = 0x0020, /* (Kerberos, RC4_128, SHA) */
    SEC_CIPHER_KRB5_WITH_IDEA_CBC_SHA             = 0x0021, /* (Kerberos, IDEA_CBC, SHA) */
    SEC_CIPHER_KRB5_WITH_DES_CBC_MD5              = 0x0022, /* (Kerberos, DES_CBC, MD5) */
    SEC_CIPHER_KRB5_WITH_3DES_EDE_CBC_MD5         = 0x0023, /* (Kerberos, 3DES_EDE_CBC, MD5) */
    SEC_CIPHER_KRB5_WITH_RC4_128_MD5              = 0x0024, /* (Kerberos, RC4_128, MD5) */
    SEC_CIPHER_KRB5_WITH_IDEA_CBC_MD5             = 0x0025, /* (Kerberos, IDEA_CBC, MD5) */
                                                                                                         
    SEC_CIPHER_KRB5_EXPORT_WITH_DES_CBC_40_SHA    = 0x0026, /* (Kerberos, DES_CBC_40, SHA), MUST NOT */
    SEC_CIPHER_KRB5_EXPORT_WITH_RC2_CBC_40_SHA    = 0x0027, /* (Kerberos, RC2_CBC_40, SHA),  MUST NOT */
    SEC_CIPHER_KRB5_EXPORT_WITH_RC4_40_SHA        = 0x0028, /* (Kerberos, RC4_40, SHA), MUST NOT */
    SEC_CIPHER_KRB5_EXPORT_WITH_DES_CBC_40_MD5    = 0x0029, /* (Kerberos, DES_DBC_40, MD5), MUST NOT */
    SEC_CIPHER_KRB5_EXPORT_WITH_RC2_CBC_40_MD5    = 0x002A, /* (Kerberos, RC2_CBC_40, MD5),  MUST NOT */
    SEC_CIPHER_KRB5_EXPORT_WITH_RC4_40_MD5        = 0x002B, /* (Kerberos, RC4_40, MD5),  MUST NOT */

    SEC_CIPHER_RSA_WITH_AES_128_CBC_SHA           = 0x002F, /* (RSA, AES_128_CBC, SHA) */
    SEC_CIPHER_DH_DSS_WITH_AES_128_CBC_SHA        = 0x0030, /* (DH_DSS, AES_128_CBC, SHA) */
    SEC_CIPHER_DH_RSA_WITH_AES_128_CBC_SHA        = 0x0031, /* (DH_RSA, AES_128_CBC, SHA) */
    SEC_CIPHER_DHE_DSS_WITH_AES_128_CBC_SHA       = 0x0032, /* (DHE_DSS, AES_128_CBC, SHA)  */
    SEC_CIPHER_DHE_RSA_WITH_AES_128_CBC_SHA       = 0x0033, /* (DHE_RSA, AES_128_CBC, SHA) */
    SEC_CIPHER_DH_anon_WITH_AES_128_CBC_SHA       = 0x0034, /* (DH_anon, AES_128_CBC, SHA) */
    SEC_CIPHER_RSA_WITH_AES_256_CBC_SHA           = 0x0035, /* (RSA, AES_256_CBC, SHA) */
    SEC_CIPHER_DH_DSS_WITH_AES_256_CBC_SHA        = 0x0036, /* (DH_DSS, AES_256_CBC, SHA) */
    SEC_CIPHER_DH_RSA_WITH_AES_256_CBC_SHA        = 0x0037, /* (DHE_RSA, AES_256_CBC, SHA) */
    SEC_CIPHER_DHE_DSS_WITH_AES_256_CBC_SHA       = 0x0038, /* (DHE_RSA, AES_256_CBC, SHA) */
    SEC_CIPHER_DHE_RSA_WITH_AES_256_CBC_SHA       = 0x0039, /* (DH_anon, AES_256_CBC, SHA) */
    SEC_CIPHER_DH_anon_WITH_AES_256_CBC_SHA       = 0x003A, /* (DH_anon, AES_256_CBC, SHA) */
    SEC_CIPHER_UNKNOWN                            = 0xFFFF
} sec_ciphersuites_enum;



#if 0 /* XXX, CODING NOTE DO NOT SHOW IN DOM DOCUMENTS! */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* CODING NOTE DO NOT SHOW IN DOM DOCUMENTS! */

/***************************************************************************
 * <GROUP Enums>
 *
 * Warnings of the certificate chain after validation
 ***************************************************************************/
typedef enum {
    SEC_CERT_WARN_NONE                 = 0x00000000, /* Validation successfully. */
    SEC_CERT_WARN_CHAIN                = 0x00000001, /* The server responded with a chain of certificates rather than a single certificate.  Don't care. */
    SEC_CERT_WARN_BCONST_NOT_CRITICAL  = 0x00000002, /* Basic Constraints field is present but marked as non-critical. */

    SEC_CERT_WARN_UNKNOWN_CRITICAL_EXT = 0x00000008, /* Unknown critical extension in the certificate. */
    SEC_CERT_WARN_VALIDITY             = 0x00000010, /* A certificate was expired, or not yet invalid. */
    SEC_CERT_WARN_NO_KEY_USAGE         = 0x00000020, /* There is no key usage in one of the certificate in the chain. */
    SEC_CERT_WARN_KEY_MISUSE           = 0x00000040, /* One of the certificates in the chain is used not according to its key usage field. */
    SEC_CERT_WARN_BCONST_FAIL          = 0x00000100, /* One of the CA certificates in the chain does not have the CA bit set in its basic constraints extension */
    SEC_CERT_WARN_NO_TRUSTED_CERTS     = 0x00000200, /* There were no trusted certificates for this chain. */
    SEC_CERT_WARN_INVALID_SIGNATURE    = 0x00000400, /* Invalid signature. */
    SEC_CERT_WARN_INTERNAL             = 0x00000800, /* An error occured while processing a cert. */
    SEC_CERT_WARN_TRUSTED_KEY_MISUSE   = 0x00010000, /* Trusted certificate is a server certificate, not a CA certificate. */
    SEC_CERT_WARN_TRUSTED_EXPIRED      = 0x00020000, /* The chosen trusted cert has expired. */
    SEC_CERT_WARN_CORRUPTED_CERT       = 0x00040000, /* Certificate is corrupted. */
    SEC_CERT_WARN_TRUSTED_NO_KEY_USAGE = 0x00080000, /* Trusted certificate cannot might be not a CA certificate. */
    SEC_CERT_WARN_NO_CERT_HASH         = 0x00100000, /* Hash is not present in the certificate. */

    SEC_CERT_WARN_BAD_CERT             = 0x00200000, /* The certificate cannot be decode successfully. */
    SEC_CERT_WARN_BAD_CRL              = 0x00400000, /* Error in CRL fields. */
    SEC_CERT_WARN_CRL_EXPIRY           = 0x00800000, /* The CRL has invalid date. */
    SEC_CERT_WARN_CERT_PURPOSE         = 0x01000000, /* The certificate cannot be used for the specified purpose. */
    SEC_CERT_WARN_INVALID_KEY_USAGE    = 0x02000000, /* Key usage does not include CRL signing. */
    SEC_CERT_WARN_UNRECOGINZED_CRL_EXT = 0x04000000, /* Unhandled critical CRL extension. */
    SEC_CERT_WARN_PROXY_CERT           = 0x08000000, /* Error in validating proxy certificate. */
    SEC_CERT_WARN_INVALID_EXT          = 0x10000000, /* Invalid or inconsistent certificate extension. */
    SEC_CERT_WARN_POLICY               = 0x20000000, /* No explicit policy. */

    SEC_CERT_WARN_BAD_DOMAIN           = 0x40000000, /* Checking domain name failed. */

    SEC_CERT_WARN_BCONST_FAIL_NC       = 0x00000102, /* SEC_CERT_WARN_BCONST_FAIL | SEC_CERT_WARN_BCONST_NOT_CRITICAL.
                                                        Error in checking basic constraints */

    SEC_CERT_WARN_WEAK_SECURITY_MASK   = 0x00000021, /* SEC_CERT_WARN_NO_KEY_USAGE | SEC_CERT_WARN_CHAIN.
                                                        Low security level could expose the connection under attack. */

    SEC_CERT_WARN_MISCONFIG_MASK       = 0x001B0112, /* SEC_CERT_WARN_NO_CERT_HASH | SEC_CERT_WARN_TRUSTED_NO_KEY_USAGE |
                                                        SEC_CERT_WARN_TRUSTED_EXPIRED | SEC_CERT_WARN_TRUSTED_KEY_MISUSE |
                                                        SEC_CERT_WARN_BCONST_FAIL | SEC_CERT_WARN_VALIDITY |
                                                        SEC_CERT_WARN_BCONST_NOT_CRITICAL. Probably a misconfiguration. */

    SEC_CERT_WARN_ATTACK_MASK          = 0x00000148, /* SEC_CERT_WARN_BCONST_FAIL | SEC_CERT_WARN_KEY_MISUSE |
                                                        SEC_CERT_WARN_UNKNOWN_CRITICAL_EXT. Probably a attack. */

    SEC_CERT_WARN_AUTH_FAILED_MASK     = 0x00040E00 /* SEC_CERT_WARN_CORRUPTED_CERT | SEC_CERT_WARN_NO_TRUSTED_CERTS |
                                                        SEC_CERT_WARN_INVALID_SIGNATURE | SEC_CERT_WARN_INTERNAL.
                                                        Authentication failed. */
} sec_cert_warn_enum;


#endif /* !_SSL_ENUMS_H */
