/*!
 *  @file ipcore_icmph.h
 *  @author Roger Huang <chaomin.haung@mediatek.com>
 *  @version 1.0
 *  @section LICENSE
 *
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
 *  @section DESCRIPTION
 *  This file provides ICMP Header definitions of ipcore
 */

#ifndef _IPCORE_ICMPH_H
#define _IPCORE_ICMPH_H

#include "kal_public_api.h"

#define IPC_ICMP_ECHO_REPLY             0       /* Echo Reply               */
#define IPC_ICMP_ECHO_REQUEST           8       /* Echo Request             */


#define IPC_ICMP6_ECHO_REQUEST          128     /* echo request             */
#define IPC_ICMP6_ECHO_REPLY            129     /* echo reply               */
#define IPC_ICMP6_NDP_ROUTER_SOLICIT    133     /* router solicitation      */
#define IPC_ICMP6_NDP_ROUTER_ADVERT     134     /* router advertisment      */
#define IPC_ICMP6_NDP_NEIGHBOR_SOLICIT  135     /* neighbor solicitation    */
#define IPC_ICMP6_NDP_NEIGHBOR_ADVERT   136     /* neighbor advertisment    */
#define IPC_ICMP6_NDP_REDIRECT          137     /* redirect                 */

#define IPC_ICMP6_NDP_OPT_SOURCE_LINKADDR       1
#define IPC_ICMP6_NDP_OPT_TARGET_LINKADDR       2
#define IPC_ICMP6_NDP_OPT_PREFIX_INFORMATION    3
#define IPC_ICMP6_NDP_OPT_REDIRECTED_HEADER     4
#define IPC_ICMP6_NDP_OPT_MTU                   5
#define IPC_ICMP6_NDP_OPT_RDNSS                 25


PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_icmp_header {
    kal_uint8   icmp_type;      // type field
    kal_uint8   icmp_code;      // code field
    kal_uint16  icmp_cksum;     // checksum field
    union {
        kal_uint32  icmp_un_data32[1];  // type-specific field
        kal_uint16  icmp_un_data16[2];  // type-specific field
        kal_uint8   icmp_un_data8[4];   // type-specific field
   } icmp_dataun;
} ipc_icmp_header_t;
PRAGMA_END_PACK_STRUCT


PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_icmp_echo_header {
    kal_uint8   icmp_type;      // type field
    kal_uint8   icmp_code;      // code field
    kal_uint16  icmp_cksum;     // checksum field
    kal_uint16  icmp_id;        // identifier
    kal_uint16  icmp_seq;       // sequence
} ipc_icmp_echo_header_t;
PRAGMA_END_PACK_STRUCT


PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_icmp6_header {
    kal_uint8   icmp6_type;     // type field
    kal_uint8   icmp6_code;     // code field
    kal_uint16  icmp6_cksum;    // checksum field
    union {
        kal_uint32  icmp6_un_data32[1]; // type-specific field
        kal_uint16  icmp6_un_data16[2]; // type-specific field
        kal_uint8   icmp6_un_data8[4];  // type-specific field
   } icmp6_dataun;
} ipc_icmp6_header_t;
PRAGMA_END_PACK_STRUCT


PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_icmp6_echo_header {
    kal_uint8   icmp6_type;     // type field
    kal_uint8   icmp6_code;     // code field
    kal_uint16  icmp6_cksum;    // checksum field
    kal_uint16  icmp6_id;       // identifier
    kal_uint16  icmp6_seq;      // sequence
} ipc_icmp6_echo_header_t;
PRAGMA_END_PACK_STRUCT


/* router solicitation */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_ndp_router_solicit {
    kal_uint8   icmp6_type;         // type field
    kal_uint8   icmp6_code;         // code field
    kal_uint16  icmp6_cksum;        // checksum field
    kal_uint32  reserve;            // reserved
    /* could be followed by options */
} ipc_ndp_router_solicit_t;
PRAGMA_END_PACK_STRUCT


/* router advertisement */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_ndp_router_advert {
    kal_uint8   icmp6_type;         // type field
    kal_uint8   icmp6_code;         // code field
    kal_uint16  icmp6_cksum;        // checksum field
    kal_uint8   hop_limit;          // hop limit
    kal_uint8   reserve:6,
                is_other_stateful:1,// other stateful configuraiton flag
                is_managed_addr:1;  // managed address configuration flag
    kal_uint16  router_lifetime;    // router life time
    kal_uint32  reachable_time;     // reachable time
    kal_uint32  retransmit_time;    // retransmit timer
    /* could be followed by options */
} ipc_ndp_router_advert_t;
PRAGMA_END_PACK_STRUCT


/* neighbor solicitation */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_ndp_neighbor_solicit {
    kal_uint8       icmp6_type;         // type field
    kal_uint8       icmp6_code;         // code field
    kal_uint16      icmp6_cksum;        // checksum field
    kal_uint32      reserve;            // reserved
    ipc_ip6_addr_t  target_addr;        // target address
    /* could be followed by options */
} ipc_ndp_neighbor_solicit_t;
PRAGMA_END_PACK_STRUCT


/* neighbor advertisement */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_ndp_neighbor_advert {
    kal_uint8       icmp6_type;         // type field
    kal_uint8       icmp6_code;         // code field
    kal_uint16      icmp6_cksum;        // checksum field
    kal_uint32      reserve:29,
                    is_override:1,      // override flag
                    is_solicited:1,     // solicited flag
                    is_router:1;        // router flag
    ipc_ip6_addr_t  target_addr;        // target address
    /* could be followed by options */
} ipc_ndp_neighbor_advert_t;
PRAGMA_END_PACK_STRUCT


/* redirect */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_ndp_redirect {
    kal_uint8       icmp6_type;         // type field
    kal_uint8       icmp6_code;         // code field
    kal_uint16      icmp6_cksum;        // checksum field
    kal_uint32      reserve;            // reserved
    ipc_ip6_addr_t  target_addr;        // target address
    ipc_ip6_addr_t  dst_addr;           // destination address
    /* could be followed by options */
} ipc_ndp_redirect_t;
PRAGMA_END_PACK_STRUCT


/* Option Link-Layer Address */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_ndp_opt_link_layer_addr {
    kal_uint8               type;
    kal_uint8               len;        // len = 1 for ieee 802 address
    ipc_ieee_802_addr_t     addr;
} ipc_ndp_opt_link_layer_addr_t;
PRAGMA_END_PACK_STRUCT


/* Option Prefix Information */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_ndp_opt_prefix {
    kal_uint8       type;
    kal_uint8       len;                // len = 4
    kal_uint8       prefix_len;
    kal_uint8       reserve1:6,
                    is_on_link:1,
                    is_autonomous:1;
    kal_uint32      valid_lifetime;
    kal_uint32      preferred_lifetime;
    kal_uint32      reserve2;
    ipc_ip6_addr_t  prefix;
} ipc_ndp_opt_prefix_t;
PRAGMA_END_PACK_STRUCT


/* Option MTU */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_ndp_opt_mtu {
    kal_uint8       type;
    kal_uint8       len;                // len = 1
    kal_uint16      reserve;
    kal_uint32      mtu;
} ipc_ndp_opt_mtu_t;
PRAGMA_END_PACK_STRUCT


/* Option RDNSS */
PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_ndp_opt_rdnss {
    kal_uint8       type;
    kal_uint8       len;                // minimum 3
    kal_uint16      reserve;
    kal_uint32      life_time;
    ipc_ip6_addr_t  dns_addr;
} ipc_ndp_opt_rdnss_t;
PRAGMA_END_PACK_STRUCT

static INLINE kal_uint16 ipc_icmp_cksum(ipc_icmp_header_t* pIcmp, kal_uint16 len)
{
    kal_uint32 cksum    = 0;
    kal_uint16 word     = 0;
    kal_uint16 i        = 0;

    for ( i=0; i<((len+1)&~1); i+=2 )
    {
        if ( i == (len -1) )
        {
            word = ((((kal_uint8*)pIcmp)[i] << 8) & 0xff00) + 0x00 ;
        } else {
            word = ((((kal_uint8*)pIcmp)[i] << 8) & 0xff00) + (((kal_uint8*)pIcmp)[i+1] & 0xff) ;
        }
        cksum = cksum + word;
    }

    while ( cksum >> 16 )
        cksum = ( cksum & 0xffff ) + (cksum >> 16);

    return (kal_uint16)~cksum;
}


static INLINE kal_uint16 ipc_icmp6_cksum(ipc_ip6_addr_t* src, ipc_ip6_addr_t* dst, kal_uint32 len, kal_uint16* data)
{
    kal_uint32 chksum = 0;
    kal_uint32 i;
    union {
        kal_uint32 dword;
        kal_uint16 word[2];
        kal_uint8  byte[4];
    } tmp;

    for ( i=0; i<8; i++ )
    {
        chksum += src->s6_addr16[i];
    }

    for ( i=0; i<8; i++ )
    {
        chksum += dst->s6_addr16[i];
    }

    tmp.dword = IPC_NTOHL(len);
    chksum += tmp.word[0];
    chksum += tmp.word[1];

    tmp.dword = 0;
    tmp.byte[3] = IPC_IPPROTO_ICMP6;
    chksum += tmp.word[0];
    chksum += tmp.word[1];

    for ( i=0; i<(len & ~1); i+=2 )
    {
        chksum += *data++;
    }

    if ( len & 1 )
        chksum += *(kal_uint8*)data;

    while ( chksum > 0xffff )
    {
        chksum = ( chksum & 0xffff ) + (chksum >> 16);
    }

    chksum = ~chksum & 0xffff;

    return (kal_uint16)chksum;

}

#endif  // _IPCORE_ICMPH_H

