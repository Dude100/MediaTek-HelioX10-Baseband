
#ifndef CUSTOM_SEC_KEY_H
#define CUSTOM_SEC_KEY_H


#include "kal_general_types.h"
#include "cust_chl_interface.h"

#define CUST_SEC_KEY_STRUCT_VER             1
#define CUST_SEC_KEY_STRUCT_MAGIC           "CUST_KEY"
#define CUST_SEC_MAX_PUB_KEY_LEN            2

typedef struct
{
	
	  /* a unique magic pattern to identify SEC_KEY_ST structure */
  	kal_char  m_magic[8];
	  
	  /* version of SEC_KEY_ST structure */
  	kal_uint32 m_sec_key_st_ver;

    t_cust_chl_asym_key  key[CUST_SEC_MAX_PUB_KEY_LEN];  

} CUST_SEC_KEY_ST;

#endif /* CUSTOM_SEC_KEY_H */