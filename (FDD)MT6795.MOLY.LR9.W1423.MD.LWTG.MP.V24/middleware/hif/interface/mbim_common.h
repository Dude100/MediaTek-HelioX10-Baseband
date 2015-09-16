#ifndef _MBIM_COMMON_H
#define _MBIM_COMMON_H

#include "kal_public_api.h"

#if !defined(__MTK_TARGET__) && defined(_MSC_VER) && (_MSC_VER >= 1500)
#pragma warning( disable : 4214 )
#endif


void mbim_get_host_mac(kal_uint32 netid_if, kal_uint8* mac_addr);
#endif  // _ETHERCORE_COMMON_H

