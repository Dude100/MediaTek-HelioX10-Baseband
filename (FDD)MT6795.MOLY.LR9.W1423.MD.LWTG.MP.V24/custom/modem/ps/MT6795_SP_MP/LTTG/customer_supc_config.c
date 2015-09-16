
#include "kal_general_types.h"


#define MAX_SUPC_AUTH_TIMEOUT_NUM  3
#define SUPC_TEMPORAL_BLACKLIST_TIMEOUT_SEC  60
#define SUPC_PERMANENT_BLACKLIST_TIMEOUT_SEC  300
#define SUPC_IS_LOGOFF_NEEDED KAL_TRUE //default value

/*****************************************************************************
* FUNCTION
*   supc_auth_timeout_num
* DESCRIPTION
*   This function is used to define the max
*   timeout number of the authentication timer for SUPC
*
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint32 supc_auth_timeout_num(void)
{
   return (MAX_SUPC_AUTH_TIMEOUT_NUM );
}

/*****************************************************************************
* FUNCTION
*   supc_temporal_blacklist_timeout_sec 
* DESCRIPTION
*   This function is used to define the expired time of the 
*   temporal blacklist timer for SUPC
*
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 supc_temporal_blacklist_timeout_sec(void)
{
   return (SUPC_TEMPORAL_BLACKLIST_TIMEOUT_SEC);
}


/*****************************************************************************
* FUNCTION
*   supc_permanent_blacklist_timeout_sec 
* DESCRIPTION
*   This function is used to define the expired time of the 
*   permanent blacklist timer for SUPC
*
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint32 supc_permanent_blacklist_timeout_sec(void)
{
   return (SUPC_PERMANENT_BLACKLIST_TIMEOUT_SEC);
}

/*****************************************************************************
* FUNCTION
*   supc_is_logoff_needed
* DESCRIPTION
*   This function is used to indicate whether the supplicant sends
*   the EAPOL-Logoff packet when disconnects.
*
* PARAMETERS
*
* RETURNS
*  kal_bool
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_bool supc_is_logoff_needed(void)
{
   return (SUPC_IS_LOGOFF_NEEDED );
}
