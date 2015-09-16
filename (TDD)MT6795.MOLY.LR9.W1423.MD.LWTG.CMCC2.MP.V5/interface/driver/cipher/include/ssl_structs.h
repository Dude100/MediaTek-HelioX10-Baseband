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
 *   ssl_structs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains structs of SSL API.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _SSL_STRUCTS_H
#define _SSL_STRUCTS_H

#include "kal_general_types.h"
#include "ssl_consts.h"
#include "ssl_enums.h"
 
/* SSL context, created by sec_ssl_ctx_new() and its properties can be
 * customized by other SSL context APIs.
 * The members in the structure is used by SSL library internally,
 * so application should not understand the detail in the structure.
 */
typedef struct ssl_ctx ssl_ctx;


/* SSL connection context, created by sec_ssl_new() and its properties can be
 * customized by other SSL connection context APIs.
 * The members in the structure is used by SSL library internally,
 * so application should not understand the detail in the structure.
 */
typedef struct ssl_conn ssl_conn;


/***************************************************************************
 * <GROUP Structures>
 *
 * Data structure holding a certificate in DER.
 * Ref. sec_ssl_get_peer_certificate(), sec_ssl_extract_cert().
 ***************************************************************************/
typedef struct 
{
    kal_uint32 length;  /* The size of the certificate in bytes. */
    kal_uint8* data;    /* Data of the certficate in DER format. */
} sec_cert_struct;


/***************************************************************************
 * <GROUP Structures>
 *
 * This is a structure passed to the certificate varify callback set by
 * sec_ssl_ctx_set_cert_verify_callback().
 * Ref. sec_ssl_cert_verify_callback().
 ***************************************************************************/
typedef struct sec_x509_store_ctx
{
    ssl_conn *conn_ctx;  /* SSL connection of the SSL connection. */
    sec_cert_struct **cert_chain; /* Certificate chain sent from peer. */
    kal_uint32 warnings[SEC_MAX_CERT_CHAIN_LEN]; /* Warning list of each cert in cert_chain. */
    kal_int32 error; /* Certificate validation result. */
} sec_x509_store_ctx;


/***************************************************************************
 * <GROUP Structures>
 *
 * Data structure holding session record
 ***************************************************************************/
typedef struct {
    kal_uint32 length; /* Size of session record in data field. */
    kal_uint8 *data;   /* Session record. */
} sec_sess_rec;


/***************************************************************************
 * <GROUP Structures>
 *
 * Collection of data structure holding a negotiated ciphersuite.
 * Ref. sec_ssl_get_curr_cipher_info().
 ***************************************************************************/
typedef struct
{
    sec_proto_ver_enum        version;  /* SSL version. */
    sec_bulk_enc_algo_enum    enc_alg;  /* Bulk encryption algorithm. */
    sec_key_xchg_algo_enum    key_alg;  /* Key exchange algorithm. */
    sec_auth_algo_enum        auth_alg; /* Authentication  algorithm. */
    sec_hash_algo_enum        hash_alg; /* Hash algorithm. */
} sec_cipher_info_struct;


/***************************************************************************
 * Collection of data structure holding a negotiated ciphersuite.
 * Dummy definition for SSL context constructors.
 * Ref. sec_ssl_ctx_new().
 ***************************************************************************/
typedef kal_uint8 ssl_method;


/***************************************************************************
 * <GROUP Structures>
 *
 * Data structure holding certificate types for client authentication.
 * Ref. sec_ssl_get_certreq_auth_names().
 ***************************************************************************/
typedef struct
{
    kal_uint8 len; /* Number of effective auth types in types field. */
    kal_uint8 types[SEC_MAX_CERT_TYPES]; /* Certificate types in certificate
request from server. */
} sec_cert_types;


/***************************************************************************
 * <GROUP Structures>
 *
 * Data structure holding authority names for client authentication.
 * Ref. sec_ssl_get_certreq_auth_names().
 ***************************************************************************/
typedef struct 
{
    kal_uint16 len; /* number of bytes in name field */
    kal_uint8* name; /* auth names in certificate request from server */
} sec_auth_names;


#endif /* !_OSSL_SSL_STRUCTS_H */


