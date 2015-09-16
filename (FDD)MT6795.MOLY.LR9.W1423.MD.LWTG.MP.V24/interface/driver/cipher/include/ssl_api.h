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
 *   ssl_api.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains function prototypes, constants for SSL API.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _SSL_API_H
#define _SSL_API_H

#include "ssl_consts.h"
#include "ssl_enums.h"
#include "ssl_structs.h"
#include "ssl_callback.h"

#include "kal_general_types.h"


/*****************************************************************************
 * <GROUP Protocol Methods>
 * FUNCTION
 *   sec_sslv2_client_method
 * DESCRIPTION
 *   Constructor for the SSLv2 SSL_METHOD structure for a dedicated client. 
 * PARAMETERS
 *   void.
 * RETURNS
 *   Constructor as a parameter to sec_ssl_ctx_new() to create a client side 
 *   SSL context be able to handle SSLv2 messges.
 * SEE ALSO
 *   sec_ssl_ctx_new
 *****************************************************************************/
extern const ssl_method *sec_sslv2_client_method(void);



/*****************************************************************************
 * <GROUP Protocol Methods>
 * FUNCTION
 *   sec_sslv3_client_method
 * DESCRIPTION
 *   Constructor for the SSLv3 SSL_METHOD structure for a dedicated client. 
 * PARAMETERS
 *   void.
 * RETURNS
 *   Constructor as a parameter to sec_ssl_ctx_new() to create a client side
 *   SSL context be able to handle SSLv3 messges.
 * SEE ALSO
 *   sec_ssl_ctx_new
 *****************************************************************************/
extern const ssl_method *sec_sslv3_client_method(void);



/*****************************************************************************
 * <GROUP Protocol Methods>
 * FUNCTION
 *   sec_tlsv1_client_method
 * DESCRIPTION
 *   Constructor for the TLSv1 SSL_METHOD structure for a dedicated client. 
 * PARAMETERS
 *   void.
 * RETURNS
 *   Constructor as a parameter to sec_ssl_ctx_new() to create a client side
 *   SSL context be able to handle TLSv1 messges.
 * SEE ALSO
 *   sec_ssl_ctx_new
 *****************************************************************************/
extern const ssl_method *sec_tlsv1_client_method(void);



/*****************************************************************************
 * <GROUP Protocol Methods>
 * FUNCTION
 *   sec_sslv23_client_method
 * DESCRIPTION
 *   Constructor for the SSLv2 and SSLv3 SSL_METHOD structure for a
 *   dedicated client. 
 * PARAMETERS
 *   void.
 * RETURNS
 *   Constructor as a parameter to sec_ssl_ctx_new() to create a client side
 *   SSL context be able to handle both SSLv2 and SSLv3 messges.
 * SEE ALSO
 *   sec_ssl_ctx_new
 *****************************************************************************/
extern const ssl_method *sec_sslv23_client_method(void);



/*****************************************************************************
 * <GROUP Protocol Methods>
 * FUNCTION
 *   sec_tlsv1_sslv3_client_method
 * DESCRIPTION
 *   Constructor for the TLSv1 and SSLv3 SSL_METHOD structure for a
 *   dedicated client. 
 * PARAMETERS
 *   void.
 * RETURNS
 *   Constructor as a parameter to sec_ssl_ctx_new() to create a client side
 *   SSL context be able to handle both TLSv1 and SSLv3 messges.
 * SEE ALSO
 *   sec_ssl_ctx_new
 *****************************************************************************/
extern const ssl_method *sec_tlsv1_sslv3_client_method(void);



/*****************************************************************************
 * <GROUP Protocol Methods>
 * FUNCTION
 *   sec_sslv2_server_method
 * DESCRIPTION
 *   Constructor for the SSLv2 SSL_METHOD structure for a dedicated server. 
 * PARAMETERS
 *   void.
 * RETURNS
 *   Constructor as a parameter to sec_ssl_ctx_new() to create a server side
 *   SSL context be able to handle SSLv2 messges.
 * SEE ALSO
 *   sec_ssl_ctx_new
 *****************************************************************************/
extern const ssl_method *sec_sslv2_server_method(void);



/*****************************************************************************
 * <GROUP Protocol Methods>
 * FUNCTION
 *   sec_sslv3_server_method
 * DESCRIPTION
 *   Constructor for the SSLv3 SSL_METHOD structure for a dedicated server.
 * PARAMETERS
 *   void.
 * RETURNS
 *   Constructor as a parameter to sec_ssl_ctx_new() to create a server side
 *   SSL context be able to handle SSLv3 messges.
 * SEE ALSO
 *   sec_ssl_ctx_new
 *****************************************************************************/
extern const ssl_method *sec_sslv3_server_method(void);



/*****************************************************************************
 * <GROUP Protocol Methods>
 * FUNCTION
 *   sec_tlsv1_server_method
 * DESCRIPTION
 *   Constructor for the TLSv1 SSL_METHOD structure for a dedicated server. 
 * PARAMETERS
 *   void.
 * RETURNS
 *   Constructor as a parameter to sec_ssl_ctx_new() to create a server side
 *   SSL context be able to handle TLSv1 messges.
 * SEE ALSO
 *   sec_ssl_ctx_new
 *****************************************************************************/
extern const ssl_method *sec_tlsv1_server_method(void);



/*****************************************************************************
 * <GROUP Protocol Methods>
 * FUNCTION
 *   sec_sslv23_server_method
 * DESCRIPTION
 *   Constructor for the SSLv2 and SSLv3 SSL_METHOD structure for a
 *   dedicated server. 
 * PARAMETERS
 *   void.
 * RETURNS
 *   Constructor as a parameter to sec_ssl_ctx_new() to create a server side
 *   SSL context be able to handle both SSLv2 and SSLv3 messges.
 * SEE ALSO
 *   sec_ssl_ctx_new
 *****************************************************************************/
extern const ssl_method *sec_sslv23_server_method(void);



/*****************************************************************************
 * <GROUP Protocol Methods>
 * FUNCTION
 *   sec_tlsv1_sslv3_server_method
 * DESCRIPTION
 *   Constructor for the TLSv1 and SSLv3 SSL_METHOD structure for a
 *   dedicated server. 
 * PARAMETERS
 *   void.
 * RETURNS
 *   Constructor as a parameter to sec_ssl_ctx_new() to create a server side
 *   SSL context be able to handle both TLSv1 and SSLv3 messges.
 * SEE ALSO
 *   sec_ssl_ctx_new
 *****************************************************************************/
extern const ssl_method *sec_tlsv1_sslv3_server_method(void);



/*****************************************************************************
 * <GROUP SSL Context APIs>
 * FUNCTION
 *   sec_ssl_ctx_new
 * DESCRIPTION
 *   Crete a new SSL context object as framework for TLS/SSL enabled functions.
 * PARAMETERS
 *   method    : [IN] SSL context constructor such as
 *               sec_sslv3_client_method() or sec_sslv23_client_method(), etc.
 * RETURNS
 *   If an SSL context is created successfully, a pointer to the created
 *   SSL context is returned. Otherwise, NULL is returned if SSL context
 *   is not created.
 *****************************************************************************/
extern ssl_ctx*
sec_ssl_ctx_new(const ssl_method *method);



/*****************************************************************************
 * <GROUP SSL Context APIs>
 * FUNCTION
 *   sec_ssl_ctx_free
 * DESCRIPTION
 *   Free an allocated SSL context object.
 * PARAMETERS
 *   ctx  : [IN] pointer to SSL context to be freed.
 * RETURNS
 *   This function returns no diagnostic information.
 *****************************************************************************/
extern void sec_ssl_ctx_free(ssl_ctx *ctx);



/*****************************************************************************
 * <GROUP SSL Context APIs>
 * FUNCTION
 *   sec_ssl_ctx_set_prng
 * DESCRIPTION
 *   Set the pseudo-rnadom-number-generator provider (callback function)
 *   used by the context.
 * PARAMETERS
 *   ctx          : [IN] Pointer to SSL context.
 *   prng         : [IN] Pseudo-number-number-generator provider.
 * RETURN VALUES
 *   SEC_ERROR_NONE : Success.
 *   SEC_ERROR_PTR  : No valid pointer.
 *   SEC_ERROR_MEM  : Memory allocation failure.
 *****************************************************************************/
extern kal_int32
sec_ssl_ctx_set_prng(ssl_ctx *ctx, const sec_ssl_prng_generator prng);



/*****************************************************************************
 * <GROUP SSL Context APIs>
 * FUNCTION
 *   sec_ssl_ctx_set_cipher_list
 * DESCRIPTION
 *   Set list of available SSL ciphersuites.
 * PARAMETERS
 *   ctx       : [IN] Pointer to SSL context.
 *   ciphers   : [IN] List of ciphers.
 *   num       : [IN] Number of ciphers in the list.
 * EXAMPLE
 * <code>
 *  sec_cipher_enum ciphers[] =
 *                  {AES128_SHA, AES256-SHA, RC4_MD5, RC4_SHA, DES_CBC3_SHA};
 *  rc = sec_ssl_ctx_set_cipher_list(*globalCtx,
 *                                   ciphers,
 *                                   sizoef(ciphers) / sizoef(sec_cipher_enum));
 * </code>
 * RETURN VALUES
 *   1  : Success.
 *   0  : Fail.
 *****************************************************************************/
extern kal_int32
sec_ssl_ctx_set_cipher_list(ssl_ctx *ctx, const sec_cipher_enum ciphers[], 
                            const kal_int32 num);



/*****************************************************************************
 * <GROUP SSL Context APIs>
 * FUNCTION
 *   sec_ssl_ctx_set_default_passwd_cb
 * DESCRIPTION
 *   Set the default password callback called when loading/storing a PEM
 *   certificate with encryption.
 * PARAMETERS
 *   ctx      : [IN] Pointer to SSL context
 *   cb       : [IN] Callback function to hand back the password to be used
 *                   during decryption.
 *                   On invocation, a pointer to 'userdata' is provided.
 *                   The callback function must write the password into the
 *                   provided buffer 'buf'.
 * RETURNS
 *   This function returns no diagnostic information.
 * SEE ALSO
 *   sec_ssl_ctx_set_default_passwd_cb_userdata
 *****************************************************************************/
extern void
sec_ssl_ctx_set_default_passwd_cb(ssl_ctx *ctx, ssl_password_cb cb);



/*****************************************************************************
 * <GROUP SSL Context APIs>
 * FUNCTION
 *   sec_ssl_ctx_set_default_passwd_cb_userdata
 * DESCRIPTION
 *   Set a pointer to userdata which will be provided to the password callback
 *   on invocation.
 * PARAMETERS
 *   ctx     : [IN] Pointer to SSL context.
 *   u       : [IN] Ask for the password once, then keep it in memory and use
 *                  it several times. The password could be stored into  the
 *                  'userdata' and pem_passwd_cb() returns the password already
 *                  stored.
 * RETURNS
 *   This function returns no diagnostic information.
 * SEE ALSO
 *   sec_ssl_ctx_set_default_passwd_cb
 *****************************************************************************/
extern void
sec_ssl_ctx_set_default_passwd_cb_userdata(ssl_ctx *ctx, void *u);



/*****************************************************************************
 * <GROUP SSL Context APIs>
 * FUNCTION
 *   sec_ssl_ctx_use_privatekey_file
 * DESCRIPTION
 *   Adds the first private key found in 'file' to 'ctx'.
 * PARAMETERS
 *   ctx       : [IN] Pointer to SSL context.
 *   file      : [IN] File storing the private key to be loaded.
 *   type      : [IN] SEC_SSL_FILETYPE_PEM, or SEC_SSL_FILETYPE_ASN1.
 * RETURN VALUES
 *   SEC_ERROR_NONE     : Success.
 *   SEC_ERROR_NULL_PTR : Invalid NULL argument is passed in.
 *   SEC_ERROR_FS       : File access error.
 *   otherwise          : other internal errors.
 *****************************************************************************/
extern kal_int32
sec_ssl_ctx_use_privatekey_file(ssl_ctx *ctx, const kal_wchar *file,
                                ssl_filetype_enum type);

    
    
/*****************************************************************************
 * <GROUP SSL Context APIs>
 * FUNCTION
 *   sec_ssl_ctx_use_certificate_file
 * DESCRIPTION
 *   Loads the first certificate stored in file into ctx.
 * PARAMETERS
 *   ctx          : [IN] Pointer to SSL context.
 *   file         : [IN] File storing the private key to be loaded.
 *   type         : [IN] SEC_SSL_FILETYPE_PEM, or SEC_SSL_FILETYPE_ASN1.
 * RETURN VALUES
 *   SEC_ERROR_NONE     : Success.
 *   SEC_ERROR_NULL_PTR : Invalid NULL argument is passed in.
 *   SEC_ERROR_FS       : File access error.
 *   otherwise          : Other internal errors.
 *****************************************************************************/
extern kal_int32
sec_ssl_ctx_use_certificate_file(ssl_ctx *ctx, const kal_wchar *file,
                                 ssl_filetype_enum type);



/*****************************************************************************
 * <GROUP SSL Context APIs>
 * FUNCTION
 *   sec_ssl_ctx_load_verify_locations
 * DESCRIPTION
 *   Set default locations for trusted CA certificate.
 * PARAMETERS
 *   ctx      : [IN] Pointer to SSL context.
 *   ca_file  : [IN] If ca_file is not NULL, it points to a file of CA
 *                   certificates in PEM format. The file can contain several
 *                   CA certificates identified by -----BEGIN CERTIFICATE-----
 *                   and -----END CERTIFICATE-----.
 *   ca_path  : [IN] If ca_path is not NULL, it points to a directory
 *                   containing CA certificates in PEM format. The files each
 *                   contain one CA certificate. The files are lookedup by the
 *                   CA subject name hash value.
 * RETURN VALUES
 *   SEC_ERROR_NONE     : Success.
 *   SEC_ERROR_NULL_PTR : Invalid NULL argument is passed in.
 *   SEC_ERROR_FS       : File access error.
 *   otherwise          : Other internal errors.
 *****************************************************************************/
extern kal_int32
sec_ssl_ctx_load_verify_locations(ssl_ctx *ctx,
                                  const kal_wchar *ca_file,
                                  const kal_wchar *ca_path);


/*****************************************************************************
 * <GROUP SSL Context APIs>
 * FUNCTION
 *   sec_ssl_ctx_set_client_auth_modes
 * DESCRIPTION
 *   Set client authentication mode.
 * PARAMETERS
 *   ctx    : [IN] Pointer to SSL context.
 *   modes  : [IN] Client authentication modes,
 *                        ended with CLIENT_AUTH_MODE_END.
 * RETURN VALUES
 *   SEC_ERROR_NONE             :  Success.
 *   SEC_ERROR_PTR              :  No pointer is passed to internal SSL library.
 *   SEC_ERROR_SSL_NEEDS_CIPHER :  No client authentication mode is provided.
 *   SEC_ERROR_SSL_BAD_SIDE     :  Incorrect side for authentication modes.
 *****************************************************************************/
extern kal_int32
sec_ssl_ctx_set_client_auth_modes(ssl_ctx *ctx,
                                  const ssl_auth_mode_enum modes[]);


/*****************************************************************************
 * <GROUP SSL Context APIs>
 * FUNCTION
 *   sec_ssl_ctx_set_io_funcs
 * DESCRIPTION
 *   Set I/O functions to the SSL context.
 * PARAMETERS
 *   ctx          : [IN] Pointer to SSL context.
 *   read_cb      : [IN] Read callback to retrieve data to be processed by SSL
 *                       library.
 *   write_cb     : [IN] Write callback to write SSL library processed data.
 *
 * RETURN VALUES
 *   SEC_ERROR_NONE      : Success.
 *   SEC_ERROR_NULL_PTR  : Passed invalid SSL context argument.
 *   SEC_ERROR_PTR       : No pointer is passed to internal SSL library.
 *****************************************************************************/
extern kal_int32
sec_ssl_ctx_set_io_funcs(ssl_ctx *ctx,
                         const sec_ssl_read_cb read_cb,
                         const sec_ssl_write_cb write_cb);



/*****************************************************************************
 * <GROUP SSL Context APIs>
 * FUNCTION
 *   sec_ssl_ctx_set_alert_func
 * DESCRIPTION
 *   Set callback function to be invoked while received alert from peer.
 * PARAMETERS
 *   ctx      : [IN] Pointer to SSL context.
 *   alert_cb : [IN] Application's alert callback to be invoked by SSL library.
 *
 * RETURN VALUES
 *   This function returns no diagnostic information.
 *****************************************************************************/
extern void
sec_ssl_ctx_set_alert_func(ssl_ctx *ctx, const sec_ssl_alert_func alert_cb);



/*****************************************************************************
 * <GROUP SSL Context APIs>
 * FUNCTION
 *   sec_ssl_ctx_set_cert_verify_callback
 * DESCRIPTION
 *   Set certificate verification callback on validating the peer certificate.
 * PARAMETERS
 *   ctx     : [IN] Pointer to SSL context.
 *   cert_cb : [IN] Read callback to retrieve data to be processed by SSL
 *                  library.
 *   arg     : [IN] Write callback to write SSL library processed data.
 * RETURN VALUES
 *   This function returns no diagnostic information.
 *****************************************************************************/
extern void
sec_ssl_ctx_set_cert_verify_callback(ssl_ctx *ctx,
                                     const sec_ssl_cert_verify_callback cert_cb,
                                     void *arg);



/*****************************************************************************
 * <GROUP SSL Context APIs>
 * FUNCTION
 *   sec_ssl_ctx_set_new_ssl_option
 * DESCRIPTION
 *   Set parameters for creating SSL connection context.
 *
 *   Because some additional parameters need to be configured before creatig a
 *   connection context from global context, this function has to be called
 *   before calling sec_ssl_new() to set the required options.
 * PARAMETERS
 *   ctx             : [IN] Pointer to SSL context.
 *   def_readbuf_len : [IN] Default size (bytes) of the buffer to read SSL
 *                          record, if zero is set to this argument, use
 *                          default 4096 bytes.
 *   max_readbuf_len : [IN] Max size (bytes) of the buffer to read SSL record
 *                          if zero is set to this argument, use default 32768
 *                          bytes.
 *   write_frag_len  : [IN] Max size of the data record passed to
 *                          sec_ssl_write(). If zero is set to this argument,
 *                          use default 4096 bytes.
 *   peer            : [IN] For client side applications, this is optional
 *                          containing the session key passed to
 *                          ssl_GetSessionFunc().
 *                          For server side, this contains the session id to be
 *                          used for non-resumed sessions.
 *   io_ref          : [IN] I/O callback reference.
 *   alert_ref       : [IN] Alert callback reference.
 * RETURN VALUES
 *   SEC_ERROR_NONE     : success
 *   SEC_ERROR_NULL_PTR : Passed null SSL context pointer
 *****************************************************************************/
extern kal_int32
sec_ssl_ctx_set_new_ssl_option(ssl_ctx *ctx,
                               const kal_uint16 def_readbuf_len,
                               const kal_uint16 max_readbuf_len,
                               const kal_uint16 write_frag_len,
                               const sec_sess_rec peer,
                               void *const io_ref,
                               void *const alert_ref);



/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_new
 * DESCRIPTION
 *   Create SSL connection context.
 * PARAMETERS
 *   ctx  : [IN] pointer to SSL connection context.
 * RETURNS
 *   Return a pointer to allocated SSL connection context on success,
 *   otherwise, return NULL.
 *****************************************************************************/
extern ssl_conn* sec_ssl_new(ssl_ctx *ctx);



/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_free
 * DESCRIPTION
 *   Free SSL connection context.
 *
 *   <i> Note: </i>
 *   You should call sec_ssl_shutdown() before calling this function.
 * PARAMETERS
 *   ssl  : [IN] Pointer to SSL connection context.
 * RETURNS
 *   This function returns no diagnostic information.
 *****************************************************************************/
extern void sec_ssl_free(ssl_conn *ssl);



/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_disable_client_auth
 * DESCRIPTION
 *   In normal case, if application does not set local identiy and server
 *   sends client authentication request, handshake process will return 
 *   SEC_ERROR_LOCAL_IDENTITY_REQUESTED.
 * 
 *   If application would like to proceed without setting client authentication
 *   while receiving client authentication, call this API to skip the check
 *   in the library.
 * PARAMETERS
 *   ssl : [IN] Pointer to SSL connection context.
 * RETURN VALUES
 *   1   :  Success.
 *   0   :  Fail.
 *****************************************************************************/
extern kal_int32 sec_ssl_disable_client_auth(ssl_conn *ssl);


/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_ocsp_stapling
 * DESCRIPTION
 *   Set OCSP stapling attributes. Note that this API is only available when
 *   __OCSP_SUPPORT__ is defined.
 * PARAMETERS
 *   ssl : [IN] Pointer to SSL connection context.
 *   use_ocsp : [IN] enable OCSP stapling or not
 *   must_pass : [IN] Must pass OCSP stapling
 * RETURNS
 *   1   :  Success.
 *   0   :  Fail.
 *****************************************************************************/
extern kal_int32
sec_ssl_ocsp_stapling(ssl_conn *ssl, kal_bool use_ocsp, kal_bool must_pass);


/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_is_ocsp_stapling_verified
 * DESCRIPTION
 *   Get the OCSP stapling verification result.
 *   Note that this API is only available when __OCSP_SUPPORT__ is defined.
 * PARAMETERS
 *   ssl : [IN] Pointer to SSL connection context.
 * RETURNS
 *   KAL_TRUE   :  Success.
 *   KAL_FALSE  :  Fail.
 *****************************************************************************/
extern kal_bool sec_ssl_is_ocsp_stapling_verified(ssl_conn *ssl);


/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_invalidate_session_entry
 * DESCRIPTION
 *   Invalidate the session cache of the connection
 * PARAMETERS
 *   ssl : [IN] Pointer to SSL connection context.
 * RETURNS
 *   void
 *****************************************************************************/
extern void sec_ssl_invalidate_session_entry(ssl_conn *ssl);


/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_connect
 * DESCRIPTION
 *   Perform SSL handshake for client side.
 *
 *   Application should call this API repeatedly until the the return error
 *   code is not WOULD_BLOCK.
 *   On error, call sec_ssl_get_error() to find out the reason.
 * PARAMETERS
 *   ssl : [IN] Pointer to SSL connection context.
 * RETURN VALUES
 *   1    : The TLS/SSL handshake was successfully complete, a TLS/SSL
 *          connection has been established.
 *   0    : The TLS/SSL handshake was not successful but was shut down
 *          controlled and by the specifications of the TLS/SSL protocol.
 *   <0   : The TLS/SSL handshake was not successful, because a fatal error
 *          occurred either at the protocol level or a connection failure
 *          occurred. The shutdown was not clean.
 *****************************************************************************/
extern kal_int32 sec_ssl_connect(ssl_conn *ssl);



/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_accept
 * DESCRIPTION
 *   Perform SSL handshake for server side.
 *
 *   Application should call this API repeatedly until the the return error
 *   code is not WOULD_BLOCK.
 *   On error, call sec_ssl_get_error() to find out the reason.
 * PARAMETERS
 *   ssl  : [IN] Pointer to SSL connection context.
 * RETURN VALUES
 *   1    : The TLS/SSL handshake was successfully complete, a TLS/SSL
 *          connection has been established.
 *   0    : The TLS/SSL handshake was not successful but was shut down
 *          controlled and by the specifications of the TLS/SSL protocol.
 *   <0   : The TLS/SSL handshake was not successful, because a fatal error
 *          occurred either at the protocol level or a connection failure
 *          occurred. The shutdown was not clean.
 *****************************************************************************/
extern kal_int32 sec_ssl_accept(ssl_conn *ssl);



/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_renegotiate
 * DESCRIPTION
 *   Requests a renegotiation of the handshake.
 *   Server side: cause data tobe transferred across the connection using the
 *                I/O write callback.
 *   Client side: does not transfer any data.
 *
 *   After requesting renegotiation, sec_ssl_do_handshake() must be called 
 *   to correctly process the renegotiation procedure.
 * PARAMETERS
 *   ssl   : [IN] Pointer to SSL connection context.
 * RETURN VALUES
 *   1     : Success.
 *   0     : SSL error, call sec_ssl_get_error() to find out the reason.
 *   -1    : Invalid ssl pointer.
 * SEE ALSO
 *   sec_ssl_do_handshake
 *****************************************************************************/
extern kal_int32 sec_ssl_renegotiate(ssl_conn *ssl);



/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_do_handshake
 * DESCRIPTION
 *   Perform SSL rehandshake.
 *
 *   Application should call this API repeatedly until the the return error
 *   code is not WOULD_BLOCK.
 *   On error, call sec_ssl_get_error() to find out the reason.
 * PARAMETERS
 *   ssl   : [IN] Pointer to SSL connection context.
 * RETURN VALUES
 *   1    : The TLS/SSL handshake was successfully complete, a TLS/SSL
 *          connection has been established.
 *   0    : The TLS/SSL handshake was not successful but was shut down
 *          controlled and by the specifications of the TLS/SSL protocol.
 *   <0   : The TLS/SSL handshake was not successful, because a fatal error
 *          occurred either at the protocol level or a connection failure
 *          occurred. The shutdown was not clean.
 * SEE ALSO
 *   sec_ssl_renegotiate
 *****************************************************************************/
extern kal_int32 sec_ssl_do_handshake(ssl_conn *ssl);


/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_session_reused
 * DESCRIPTION
 *   To know whether the session is resumed.
 *
 *  During the negotiation, a client can propose to reuse a session.
 *  The server then looks up the session in its cache. If both client and
 *  server agree on the session, it will be reused and a flag is being set
 *  that can be queried by the application.
 * PARAMETERS
 *   ssl             : [IN] pointer to SSL connection context.
 * RETURN VALUES
 *   1   : Session is resumed.
 *   0   : Session is not resumed.
 *   -1  : Error cases, use sec_ssl_get_error() to find out the reason.
 *****************************************************************************/
extern kal_int32 sec_ssl_session_reused(ssl_conn *ssl);



/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_session_established
 * DESCRIPTION
 *   To know whether the session is established.
 * PARAMETERS
 *   ssl     : [IN] pointer to SSL connection context.
 * RETURN VALUES
 *   1   : Session is established.
 *   0   : Session is not estbalished.
 *****************************************************************************/
extern kal_int32 sec_ssl_session_established(ssl_conn *ssl);



/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_get_master_secret
 * DESCRIPTION
 *   To retrieve the negotiated master secret
 *
 *   Gets the negotiated master secret for the connection context after
 *   handshake completed, this
 * PARAMETERS
 *   ssl            : [IN]  pointer to SSL connection context
 *   secret_buf_len : [IN]  size of buffer provided for storing returned P.M.S.
 *   secret         : [OUT] pointer to buffer for storing returned P.M.S.
 *   secret_len     : [OUT] length of returned P.M.S.
 * RETURN VALUES
 *  SEC_ERROR_NULL_PTR          : NULL SSL context pointer.
 *  SEC_ERROR_NONE              : Success.
 *  SEC_ERROR_PTR               : NULL pointer was passed to internal library.
 *  SEC_ERROR_BAD_LEN           : Secret_buf_len is too small to return secret.
 *  SEC_ERROR_SSL_HSHK_REQUIRED : Handshake must be performed fist.
 * SEE ALSO
 *   sec_ssl_get_client_random, sec_ssl_get_server_random
 *****************************************************************************/
extern kal_int32
sec_ssl_get_master_secret(ssl_conn *ssl,
                          kal_uint16 secret_buf_len,
                          kal_uint8 *secret,
                          kal_uint16* secret_len);



/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_get_client_random
 * DESCRIPTION
 *   To retrieve the selected random number by local
 *
 *   Gets the random field which was encoded in the "client_hello" handshake
 *   message. This function is intended for applications to derive key material
 *   used in EAP-TLS or similar protocols.
 * PARAMETERS
 *   ssl           : [IN]  Pointer to SSL connection context.
 *   rand_buf_len  : [IN]  Size of buffer provided for storing returned random.
 *   rand_buf      : [OUT] Pointer to buffer for storing returned random.
 *   rand_len      : [OUT] Length of returned random.
 * RETURN VALUES
 *   SEC_ERROR_NULL_PTR          : NULL SSL context pointer.
 *   SEC_ERROR_NONE              : Success.
 *   SEC_ERROR_PTR               : NULL pointer was passed to internal library.
 *   SEC_ERROR_BAD_LEN           : Secret_buf_len is too small to return secret.
 *   SEC_ERROR_SSL_HSHK_REQUIRED : Handshake must be performed fist.
 *   SEC_ERROR_SSL_PROTOCOL_VER  : Protocol version is smaller than TLS v1.0.
 * SEE ALSO
 *   sec_ssl_get_server_random, sec_ssl_get_master_secret
 *****************************************************************************/
extern kal_int32
sec_ssl_get_client_random(ssl_conn *ssl,
                          kal_uint16 rand_buf_len,
                          kal_uint8 *rand_buf,
                          kal_uint16* rand_len);



/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_get_server_random
 * DESCRIPTION
 *   To retrieve the selected random number by the remote side
 *
 *   Gets the random field which was encoded in the "server_hello" handshake
 *   message. This function is intended for applications to derive key material
 *   used in EAP-TLS or similar protocols.
 * PARAMETERS
 *   ssl           : [IN]  Pointer to SSL connection context.
 *   rand_buf_len  : [IN]  Size of buffer provided for storing returned random.
 *   rand_buf      : [OUT] Pointer to buffer for storing returned random.
 *   rand_len      : [OUT] Length of returned random.
 * RETURN VALUES
 *   SEC_ERROR_NULL_PTR          : NULL SSL context pointer.
 *   SEC_ERROR_NONE              : Success.
 *   SEC_ERROR_PTR               : NULL pointer was passed to internal library.
 *   SEC_ERROR_BAD_LEN           : Secret_buf_len is too small to return secret.
 *   SEC_ERROR_SSL_HSHK_REQUIRED : Handshake must be performed fist.
 *   SEC_ERROR_SSL_PROTOCOL_VER  : Protocol version is smaller than TLS v1.0.
 * SEE ALSO
 *   sec_ssl_get_client_random, sec_ssl_get_master_secret
 *****************************************************************************/
extern kal_int32
sec_ssl_get_server_random(ssl_conn *ssl,
                          kal_uint16 rand_buf_len,
                          kal_uint8 *rand_buf,
                          kal_uint16* rand_len);



/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_check_peer_cert_cname
 * DESCRIPTION
 *   To check the Common Name from received peer certificate
 * PARAMETERS
 *   ssl     : [IN] pointer to SSL connection context.
 *   cname   : [IN] string of destination srever name,
 *                  or set to NULL to disable this function.
 * RETURN VALUES
 *   SEC_ERROR_NULL_PTR : NULL SSL context pointer.
 *   SEC_ERROR_NONE     : Success.
 *****************************************************************************/
extern kal_int32
sec_ssl_check_peer_cert_cname(ssl_conn *const ssl, const kal_char *const cname);



/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_read
 * DESCRIPTION
 *   Read data from SSL connection.
 *
 *   sec_ssl_read() works based on the SSL/TLS records. The data are received
 *   in records (with a maximum record size of 16kB for SSLv3/TLSv1).
 *   Only when a record has been completely received, it can be processed
 *   (decryption and check of integrity). Therefore data that was not retrieved
 *   at the last call of sec_ssl_read() can still be buffered inside the SSL
 *   layer and will be retrieved on the next call to sec_ssl_read().
 *   If num is higher than the number of bytes buffered, sec_ssl_read() will
 *   return with the bytes buffered.
 * PARAMETERS
 *   ssl  : [IN] pointer to SSL connection context.
 *   buf  : [IN] buffer to put decrypted application data.
 *   num  : [IN] size of buf in bytes.
 * RETURN VALUES
 *   >=0  : Operation successfully, return the bytes actually read from
 *          SSL connection.
 *   -1   : Not successful, error occured or action must be taken by the
 *          calling process, call sec_ssl_get_error() to get the reason.
 *   -2   : Not successful, connection closed.
 *****************************************************************************/
extern kal_int32 sec_ssl_read(ssl_conn *ssl, void *buf, kal_int32 num);



/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_write
 * DESCRIPTION
 *   Write data to SSL connection.
 *
 *   sec_ssl_write() will only return with success, when the complete contents
 *   of buf of length num has been written.
 * PARAMETERS
 *   ssl   : [IN] Pointer to SSL connection context
 *   buf   : [IN] Buffer holding application data to be encrypted
 *   num   : [IN] Size of buf in bytes
 * RETURN VALUES
 *   >0 : Operation successfully, return the bytes actually read from
 *        SSL connection.
 *   0  : Not successful, connection closed.
 *   -1 : Not successful, error occured or action must be taken by the
 *        calling process, call sec_ssl_get_error() to get the reason.
 *****************************************************************************/
extern kal_int32 sec_ssl_write(ssl_conn *ssl, const void* buf, kal_int32 num);



/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_want_read
 * DESCRIPTION
 *   Probe the staus of the ssl reading buffer.
 *
 *   There are data in the SSL buffer ready for read to the application buffer.
 *   For socket applications, the encrypted application data might has been
 *   read from socket receiving buffer to SSL read buffer, application can use
 *   this API to probe the SSL buffer state.
 * PARAMETERS
 *   ssl           : [IN] pointer to SSL connection context
 * RETURN VALUES
 *  1    : There are data in the SSL buffer to be read for SSL application.
 *  0    : No data to be read.
 *  -1   : Error occured, call sec_ssl_get_error() to get the reason.
 *****************************************************************************/
extern kal_int32 sec_ssl_want_read(ssl_conn *ssl);



/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *  sec_ssl_want_write
 * DESCRIPTION
 *  Probe the staus of the ssl writing buffer.
 * 
 *  There are data in the SSL buffer that must be written to the underlying
 *  layer in order to complete the actual ssl_*() operation.
 * PARAMETERS
 *  ssl  : [IN] Pointer to SSL connection context.
 * RETURN VALUES
 *  1    : There are data in the SSL buffer to be written to complete the
 *         SSL_* operation.
 *  0    : No data to be written.
 *  -1   : Error occured, call sec_ssl_get_error() to get the reason.
 *****************************************************************************/
extern kal_int32 sec_ssl_want_write(ssl_conn *ssl);



/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_shutdown
 * DESCRIPTION
 *   Shutdown the SSL connection by sending a 'close notify' alert to peer.
 * PARAMETERS
 *   ssl  : [IN] Pointer to SSL connection context.
 * RETURN VALUES
 *   1    : the SSL shutdown was successfully completed
 *   0    : the shutdown process is not yet finished, call it one more time.
 *   -1   : shutdown failed because a fatal error occured.
 *****************************************************************************/
extern kal_int32 sec_ssl_shutdown(ssl_conn *ssl);



/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_get_error
 * DESCRIPTION
 *   Get last SSL error cause.
 *
 *   sec_ssl_get_error() returns a result code for a preceding call to
 *   ssl_connect(), ssl_accept(), ssl_do_handshake(), ssl_read(), ssl_peek(),
 *   or ssl_write() on ssl. The value returned by that TLS/SSL I/O function
 *   must be passed to sec_ssl_get_error() in parameter ret.
 * PARAMETERS
 *   ssl       : [IN] Pointer to SSL connection context.
 *   ret       : [IN] Currently not used.
 * RETURN VALUES
 *   !=        : 0 last eror
 *   0         : Not valid ssl pointer
 * EXAMPLE
 * <code>
 *  ret = sec_ssl_connect(ssl_conn);
 *  if (ret != 1)
 *      err = sec_ssl_get_error(ssl_conn, ret);
 * </code>
 *****************************************************************************/
extern kal_int32 sec_ssl_get_error(const ssl_conn *ssl, kal_int32 ret);




/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_get_curr_cipher_info
 * DESCRIPTION
 *   Get the negotiated cipher infomation.
 *   The information contains: 
 *    - Protocol version,
 *    - Encryption algorithm,
 *    - Key exchange algorithm,
 *    - Authentication algorithm,
 *    - Hash algorithm.
 * PARAMETERS
 *   ssl         : [IN]  Connection context
 *   cipher_info : [OUT] Structure containing the info of negotiated ciphersuite
 * RETURN VALUES
 *   SEC_ERROR_NONE              : Success, the cert is copied to buf, with the
 *                                 length returned from buflen.
 *   SEC_ERROR_NULL_PTR          : NULL pointer is passed.
 *   SEC_ERROR_SSL_HSHK_REQUIRED : Handshake must be completed first.
 *   SEC_ERROR_PTR               : SSL internal connection context points to
 *                                 NULL.
 *   SEC_ERROR_BUFFER_SIZE       : Given destination buffer is too small, the
 *                                 required size is returned in the buflen
 *                                 argument.
 *****************************************************************************/
extern kal_int32
sec_ssl_get_curr_cipher_info(const ssl_conn *ssl, 
                             sec_cipher_info_struct *cipher_info);



/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_cipher_get_version
 * DESCRIPTION
 *   Get the negotiated SSL/TLS version.
 * PARAMETERS
 *   ssl         : [IN]  Connection context
 * RETURNS
 *   SSL protocol version represented in sec_proto_ver_enum.
 *****************************************************************************/
extern sec_proto_ver_enum sec_ssl_cipher_get_version(const ssl_conn *ssl);



/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_get_ciphersuite
 * DESCRIPTION
 *   Get the negotiated ciphersuite.
 * PARAMETERS
 *   ssl         : [IN]  Connection context
 *   cipher      : [OUT] Returning cipher suite enum of negotiated ciphersuite
 *
 * RETURN VALUES
 *   SEC_ERROR_NONE              : Success, the cert information is extracted.
 *   SEC_ERROR_NULL_PTR          : NULL pointer is passed in the argument.
 *   SEC_ERROR_SSL_HSHK_REQUIRED : Handshake must be completed first.
 *   SEC_ERROR_PTR               : SSL internal connection context points to
 *                                 NULL.
 *****************************************************************************/
extern kal_int32
sec_ssl_get_ciphersuite(const ssl_conn *ssl, sec_ciphersuites_enum *cipher);



/*****************************************************************************
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_get_peer_certificate
 * DESCRIPTION
 *   Get the certificate of current session.
 * PARAMETERS
 *   ssl     : [IN]  Connection context
 *   cert    : [OUT] Buffer to return certificate of current session
 * RETURN VALUES
 *   SEC_ERROR_NONE              : Success, the cert information is extracted.
 *   SEC_ERROR_NULL_PTR          : NULL pointer is passed in the argument.
 *   SEC_ERROR_SSL_HSHK_REQUIRED : Handshake must be completed first.
 *   SEC_ERROR_PTR               : SSL internal connection context points to
 *                                 NULL.
 *****************************************************************************/
extern kal_int32
sec_ssl_get_peer_certificate(ssl_conn *const ssl, sec_cert_struct *cert);



/***************************************************************************** 
 * <GROUP SSL Connection APIs>
 * FUNCTION
 *   sec_ssl_get_certreq_auth_names
 * DESCRIPTION
 *   The auth name list sent from peer in a client certificate request message.
 * 
 *   For client authentication, the cert types and auth names and used to
 *   filter the local personal certificates meets the criteria to be used as
 *   local identity. If application encountered client authentication during
 *   handshake, it should call this API to extract the information in the
 *   received client authentication request.
 * 
 *  The authentication names in received client authentication request are
 *  returned from the auth_names parameter. The number of received auth names
 *  are returned from auth_name_cnt as output argument. If the total number of
 *  received auth names is larger than input auth_name_cnt, currently SSL
 *  library supports up to 32 client auth names.
 * PARAMETERS
 *   ssl           : [IN]     Connection context
 *   cert_types    : [OUT]    A list of certificate types of certificates
 *                            requested, stored in order of the server's
 *                            preference.
 *   auth_name_cnt : [IN/OUT] Number of entries in the certificate authorities.
 *                            a) As an input argument, which specifies the
 *                               size of "auth_names" array.
 *                            b) As an output argument, which return the number
 *                               of valid entries in the "auht_names" array.
 *   auth_names    : [OUT]    A list of the distinguished names of acceptable 
 *                            certificate authorities.
 * RETURN VALUES
 *   SEC_ERROR_NONE       : Success, the cert is copied to buf, with the
 *                          length returned from buflen.
 *   SEC_ERROR_NULL_PTR   : NULL pointer is passed.
 *   SEC_ERROR_PTR        : SSL internal connection context points to NULL.
 * Note that the pointers to auth_names are maintained in SSL wrapper.
 * The memory holding the data will freed while deleting the connection context.
 * So, application should be responsible for duplicating the data if necessary.
 *****************************************************************************/
extern kal_int32
sec_ssl_get_certreq_auth_names(ssl_conn * ssl,
                               sec_cert_types *cert_types,
                               kal_uint8 *auth_name_cnt,
                               sec_auth_names auth_names[]);



/*****************************************************************************
 * <GROUP Utility Functions>
 * FUNCTION
 *   sec_ssl_extract_cert
 * DESCRIPTION
 *   Extract the certificate in cert to user buffer.
 *
 *   For applications would like to extract a certificate stored in
 *   sec_cert structure to user buffer. Application should provide a buffer
 *   to store the extracted certificate. For the first time, application does
 *   not know the required buffer to extract the certificate, application can
 *   pass an NULL buffer and check the value in buf_len to allocate a block of
 *   memory with sufficient size.
 * PARAMETERS
 *   cert     : [IN] Source structure holding certificate to be extracted
 *   buf      : [IN] Buffer provided by user to hold the copied cert
 *   buflen   : [IN] Length of the given buffer, a argument for both
 *                   input and output.
 *                   1. For input, it specifies the size of buffer provided
 *                      by user
 *                   2. For ouptut:
 *                      a) in error of insufficient size, it returns  the
 *                         required size for extracting the certificate
 *                      b) in success case, it contains the size of the
 *                         extracted certificate
 * RETURN VALUES
 *   SEC_ERROR_NONE        : Success, the cert is copied to buf, with the
 *                           length returned from buflen.
 *   SEC_ERROR_NULL_PTR    : NULL pointer is passed.
 *   SEC_ERROR_PTR         : SSL internal connection context points to NULL.
 *   SEC_ERROR_BUFFER_SIZE : given destination buffer is too small, the required
 *                           size is returned in the buflen argument.
 *****************************************************************************/
extern kal_int32
sec_ssl_extract_cert(const sec_cert_struct *cert, kal_uint8 *buf, kal_uint32 *buflen);



/*****************************************************************************
 * <GROUP Utility Functions>
 * FUNCTION
 *   sec_ssl_log_plaintext
 * DESCRIPTION
 *   Enable/disable plaintext logging mechanism, default if off.
 *
 *   This API is used designed for debugging SSL/TLS applications.
 *   Because all applications over SSL/TLS send and receive encrypted data in
 *   the network, application can invoke this API to turn on the logging
 *   mechanism to check the plaintext content in the application layer.
 *
 *   For security consideration, This API will only be effective when the
 *   global compile __PRODUCTION_RELEASE__ is not defined.
 *
 *   As long as this API is invoked to turn on the logging mechanism, all data
 *   flow over SSL/TLS in the system will be logged.
 *
 *   The message will be logged as MSG_ID_APP_SSL_DATA_INPUT_MSG and
 *   MSG_ID_APP_SSL_DATA_OUTPUT_MSG to MOD_SOC.
 *
 *   Note:
 *     1. The ILMs only be sent when a successful SSL read()/write() is invoked.
 *     2. The ret field in the message is the number of data been read/write.
 *     3. The len field in the message is the peer buffer allocated for
 *        sending/recving data, if the buffer called in the API is too large
 *        (> 2048-peer_buff_struct), multiple messages will be sent in the log
 *     4. The mf field in the message indicates whether there are more fragments
 *        for this read/write operation
 *
 * PARAMETERS
 *   onoff    : [IN]  Switch on/off the plaintext logging mechanism.
 * RETURNS
 *   This function returns no diagnostic information.
 *****************************************************************************/
extern void sec_ssl_log_plaintext(const kal_bool onoff);



/*****************************************************************************
 * <GROUP Utility Functions>
 * FUNCTION
 *   sec_ssl_clear_library_error
 * DESCRIPTION
 *   Clear library error variable.
 * PARAMETERS
 *   void
 * RETURNS
 *   This function returns no diagnostic information.
 *****************************************************************************/
extern void sec_ssl_clear_library_error(void);

#endif /* !_SSL_API_H */


