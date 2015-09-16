#ifndef __CUST_CHL_INTERFACE_H__
#define __CUST_CHL_INTERFACE_H__

/*********************** Warning ***********************

!! Modify this file must remake sys_svc_sec module and custom module

*********************** Warning ************************/

#include "kal_public_defs.h"
#include "reg_base.h"


#define MAX_CUST_CHL_HASH_LEN                32
#define MAX_CUST_CHL_MAC_LEN                 32
#define MAX_CUST_CHL_SYM_KEY_LEN             32
#define MAX_CUST_CHL_SIG_LEN                 256
#define MAX_CUST_CHL_ASYM_KEY_LEN            256

#define CHE_RESULT_GUARD_PATTERN             0xFCFCFCFC
#define CHE_RESULT_GUARD_PATTERN_LEN         4

typedef enum
{ 
	CUST_CHL_ERROR_NONE                            = 0x0000,
	CUST_CHL_ERROR_NULL_PTR                        = 0x0001,
	CUST_CHL_ERROR_INVALID_ALG                     = 0x0002,
	CUST_CHL_ERROR_MD_NOT_FOUND                    = 0x0003,
	CUST_CHL_ERROR_NO_SUCH_KEY                     = 0x0004,
	CUST_CHL_ERROR_HEXIFY_FAILED                   = 0x0005,
	CUST_CHL_ERROR_UNHEXIFY_FAILED                 = 0x0006,
	CUST_CHL_ERROR_RESULT_GUARD_PATTERN_CORRUPTED  = 0x0007,
	
	CUST_CHL_ERROR_CHECK_RSA_PUB_FAILED            = 0x0100,
	CUST_CHL_ERROR_CHECK_RSA_PRIV_FAILED           = 0x0101,
	
	CUST_CHL_ERROR_READ_HRID_FAILED                = 0x0200,
	CUST_CHL_ERROR_GET_CUST_KEY_FAILED             = 0x0201,
  
	CUST_CHL_ERROR_VERIFY_MAC_FAILED               = 0x0300,
	CUST_CHL_ERROR_VERIFY_SIG_FAILED               = 0x0301,
	CUST_CHL_ERROR_CHECK_RSA_PUB_ENC_FAILED        = 0x0302,
	CUST_CHL_ERROR_CHECK_RSA_PRIV_ENC_FAILED       = 0x0303,
	CUST_CHL_ERROR_CHECK_RSA_PUB_DEC_FAILED        = 0x0304,
	CUST_CHL_ERROR_CHECK_RSA_PRIV_DEC_FAILED       = 0x0305,
		
	CUST_CHL_ERROR_UNDEFINED_FAILED                = 0x0800,
	
	CUST_CHL_ERROR_END                             = 0xFFFF,
	
} TYPE_CUST_CHL_ERROR;

typedef enum
{
	
	CUST_CHL_ALG_BEGIN              = 0x0000,
	
  /* hash*/
	CUST_CHL_ALG_SHA256             = 0x0001,
  
  /* cipher */
  CUST_CHL_ALG_RSA_PKCS1          = 0x1001,

  /* MAC */
	CUST_CHL_ALG_MAC_SHA256         = 0x2001,

  /* signature */
	CUST_CHL_ALG_RSA_PSS_SHA256     = 0x3001,

	CUST_CHL_ALG_END                = 0xFFFF
	
} TYPE_CUST_CHL_ALG;

typedef enum
{
	
  /* symmetric key */
  CUST_CHL_SYM_BEGIN         = 0x0000,
  CUST_TM_SHARED_KEY2        = 0x0001,
  CUST_CHL_SYM_END           = 0x7FFF,

  /* asymmetric key */
  CUST_CHL_ASYM_BEGIN        = 0x8000,
  CUST_TM_PUB_KEY1           = 0x8001,
  CUST_CHL_ASYM_END          = 0xFFFF
  
} TYPE_CUST_CHL_KEY;

/* We default use RSA as our asymmetric key */
typedef struct t_cust_chl_hash_u
{
	kal_uint32  m_len;	
	kal_uint8   m_u8[MAX_CUST_CHL_HASH_LEN];

} t_cust_chl_hash_u;

/* We default use sha256 HMAC*/
typedef struct t_cust_chl_mac_u
{
	kal_uint32  m_len;	
	kal_uint8   m_u8[MAX_CUST_CHL_MAC_LEN];

} t_cust_chl_mac_u;

typedef struct t_cust_chl_sym_key
{
	
	kal_uint32  m_key_len;
	kal_uint8   m_key[MAX_CUST_CHL_SYM_KEY_LEN];

} t_cust_chl_sym_key;


/* We default use RSA as our asymmetric key */
typedef struct t_cust_chl_asym_key
{
	
	kal_uint32  m_E_D_len;
	kal_uint32  m_N_len;
	kal_uint8   m_E_D_key[MAX_CUST_CHL_ASYM_KEY_LEN];  // exponent : E => public key, D => private key
	kal_uint8   m_N_key[MAX_CUST_CHL_ASYM_KEY_LEN];    // modulo

} t_cust_chl_asym_key;



/*****************************************************************************
 * FUNCTION
 *  CustCHL_Get_Sym_Key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_type            [IN]   (reference to enum TYPE_CUST_CHL_KEY)         
 *  key                 [OUT]  (Symmetric key)      
 * RETURNS
    0 : successfully 
    otherwise : failure (reference to enum TYPE_CUST_CHL_ERROR for error code)
 *****************************************************************************/
extern kal_uint32 CustCHL_Get_Sym_Key(TYPE_CUST_CHL_KEY key_type, t_cust_chl_sym_key * key);


/*****************************************************************************
 * FUNCTION
 *  CustCHL_Get_Asym_Key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  key_type            [IN]    (reference to enum TYPE_CUST_CHL_KEY)         
 *  key                 [OUT]   (RSA key)     
 * RETURNS
    0 : successfully 
    otherwise : failure (reference to enum TYPE_CUST_CHL_ERROR for error code)
 *****************************************************************************/
extern kal_uint32 CustCHL_Get_Asym_Key(TYPE_CUST_CHL_KEY key_type, t_cust_chl_asym_key * key);


/*****************************************************************************
 * FUNCTION
 *  CustCHL_RSA_PKCS1_Encrypt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  alg_type            [IN]    (reference to enum TYPE_CUST_CHL_ALG)
 *  mode                [IN]    (0 : with public key encrypt, 1 : with private key encrypt)
 *  input_len           [IN]    (length of plaintext)
 *  input               [IN]    (plaintext) 
 *  output              [OUT]   (cipher)
 *  key                 [IN]    (RSA public/private key)
 * RETURNS
    0 : successfully 
    otherwise : failure (reference to enum TYPE_CUST_CHL_ERROR for error code)
 *****************************************************************************/
extern kal_uint32 CustCHL_RSA_PKCS1_Encrypt(TYPE_CUST_CHL_ALG alg_type,
			                                        kal_uint32 mode,
			                                        kal_uint32 input_len,
			                                        kal_uint8 * input, 
			                                        kal_uint8 * output,
			                                        t_cust_chl_asym_key * key);


/*****************************************************************************
 * FUNCTION
 *  CustCHL_RSA_PKCS1_Decrypt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  alg_type            [IN]    (reference to enum TYPE_CUST_CHL_ALG)
 *  mode                [IN]    (0 : with public key decrypt, 1 : with private key decrypt)
 *  input               [IN]    (cipher)
 *  output_len          [OUT]   (length of decrypted data) 
 *  output              [OUT]   (decrypted data)
 *  key                 [IN]    (RSA public/private key)
 * RETURNS
    0 : successfully 
    otherwise : failure (reference to enum TYPE_CUST_CHL_ERROR for error code)
 *****************************************************************************/                               
extern kal_uint32 CustCHL_RSA_PKCS1_Decrypt(TYPE_CUST_CHL_ALG alg_type,
                                              kal_uint32 mode,
			                                        kal_uint8 * input, 
			                                        kal_uint32 * output_len,
			                                        kal_uint8 * output,
			                                        t_cust_chl_asym_key * key);   

/*****************************************************************************
 * FUNCTION
 *  CustCHL_Calculate_Hash
 * DESCRIPTION
 *  
 * PARAMETERS
 *  alg_type            [IN]    (reference to enum TYPE_CUST_CHL_ALG)
 *  data                [IN]    (data to be calculated)
 *  data_len            [IN]    (length of data)
 *  hash_u              [OUT]   (hash) 
 * RETURNS
    0 : successfully 
    otherwise : failure (reference to enum TYPE_CUST_CHL_ERROR for error code)
 *****************************************************************************/   
extern kal_uint32 CustCHL_Calculate_Hash(TYPE_CUST_CHL_ALG alg_type,
                                           kal_uint8 * data, 
                                           kal_uint32 data_len, 
                                           t_cust_chl_hash_u * hash_u);

/*****************************************************************************
 * FUNCTION
 *  CustCHL_Verify_PSS_Signature
 * DESCRIPTION
 *  
 * PARAMETERS
 *  alg_type            [IN]    (reference to enum TYPE_CUST_CHL_ALG)
 *  data                [IN]    (original data)
 *  data_len            [IN]    (length of data)
 *  sig                 [IN]    (signature) 
 *  key                 [IN]    (RSA public key) 
 * RETURNS
    0 : successfully 
    otherwise : failure (reference to enum TYPE_CUST_CHL_ERROR for error code)
 *****************************************************************************/ 
extern kal_uint32 CustCHL_Verify_PSS_Signature(TYPE_CUST_CHL_ALG alg_type,
                                                 kal_uint8 * data, 
                                                 kal_uint32 data_len,
                                                 kal_uint8 * sig,
                                                 t_cust_chl_asym_key * key);

/*****************************************************************************
 * FUNCTION
 *  CustCHL_Verify_MAC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  alg_type            [IN]    (reference to enum TYPE_CUST_CHL_ALG)
 *  data                [IN]    (original data)
 *  data_len            [IN]    (length of data)
 *  mac                 [IN]    (hmac) 
 *  key                 [IN]    (Symmetric key) 
 *  key_len             [IN]    (length of key) 
 * RETURNS
    0 : successfully 
    otherwise : failure (reference to enum TYPE_CUST_CHL_ERROR for error code)
 *****************************************************************************/                                         
extern kal_uint32 CustCHL_Verify_MAC(TYPE_CUST_CHL_ALG alg_type,
                              kal_uint8 * data, 
                              kal_uint32 data_len,
                              kal_uint8 * mac,
                              kal_uint8 * key, 
                              kal_uint32 key_len) ;                                         
                               


/*****************************************************************************
 * FUNCTION
 *  CustCHL_Calculate_MAC
 * DESCRIPTION
 *  
 * PARAMETERS
 *  alg_type            [IN]    (reference to enum TYPE_CUST_CHL_ALG)
 *  data                [IN]    (original data)
 *  data_len            [IN]    (length of data)
 *  key                 [IN]    (Symmetric key) 
 *  key_len             [IN]    (length of key) 
 *  mac_u               [OUT]   (output MAC)
 * RETURNS
    0 : successfully 
    otherwise : failure (reference to enum TYPE_CUST_CHL_ERROR for error code)
 *****************************************************************************/   
extern kal_uint32 CustCHL_Calculate_MAC(TYPE_CUST_CHL_ALG alg_type,
                                 kal_uint8 * data, 
                                 kal_uint32 data_len,
                                 kal_uint8 * key, 
                                 kal_uint32 key_len,
                                 t_cust_chl_mac_u * mac_u);

#endif /* __CUST_CHL_INTERFACE_H__ */

