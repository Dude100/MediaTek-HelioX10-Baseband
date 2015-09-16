/*!
 *  @file ipcore_iph.h
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
 *  This file provides IP Header definitions of ipcore
 */

#ifndef _IPCORE_IPH_H
#define _IPCORE_IPH_H

#include "kal_public_api.h"

#if !defined(__MTK_TARGET__) && defined(_MSC_VER) && (_MSC_VER >= 1500)
#pragma warning( disable : 4214 )
#endif

#define IPC_IP4_VERSION         4
#define IPC_IP6_VERSION         6

#define IPC_IPPROTO_HOPOPTS     0       /* IP6 hop-by-hop options */
#define IPC_IPPROTO_ICMP        1       /* ICMP */
#define IPC_IPPROTO_TCP         6       /* TCP */
#define IPC_IPPROTO_UDP         17      /* UDP */
#define IPC_IPPROTO_ROUTING     43      /* IP6 routing header */
#define IPC_IPPROTO_FRAGMENT    44      /* IP6 fragmentation header */
#define IPC_IPPROTO_ESP         50      /* IP6 Encap Sec. Payload */
#define IPC_IPPROTO_AH          51      /* IP6 Auth Header */
#define IPC_IPPROTO_ICMP6       58      /* ICMP6 */
#define IPC_IPPROTO_NONE        59      /* IP6 no next header */
#define IPC_IPPROTO_DSTOPTS     60      /* IP6 destination option */

#define IPC_IPPORT_BOOTPS       67      /* Bootstrap Protocol Server */
#define IPC_IPPORT_BOOTPC       68      /* Bootstrap Protocol Client */

#define IPC_EUI64_GBIT          0x01
#define IPC_EUI64_UBIT          0x02

#define IPC_IP6_IS_ADDR_UNSPECIFIED(_addr)  \
    ((*(const kal_uint32 *)(const void *)(&(_addr)->s6_addr8[0]) == 0) &&   \
     (*(const kal_uint32 *)(const void *)(&(_addr)->s6_addr8[4]) == 0) &&   \
     (*(const kal_uint32 *)(const void *)(&(_addr)->s6_addr8[8]) == 0) &&   \
     (*(const kal_uint32 *)(const void *)(&(_addr)->s6_addr8[12]) == 0))

#define IPC_SWAP16(_x)          ((_x & 0xff00) >> 8 | (_x & 0x00ff) << 8)
#define IPC_SWAP32(_x)          ((_x & 0xff000000) >> 24 |  \
                                 (_x & 0x00ff0000) >> 8  |  \
                                 (_x & 0x0000ff00) << 8  |  \
                                 (_x & 0x000000ff) << 24)

#define IPC_HTONS(_x)           IPC_SWAP16(_x)
#define IPC_HTONL(_x)           IPC_SWAP32(_x)
#define IPC_NTOHS(_x)           IPC_SWAP16(_x)
#define IPC_NTOHL(_x)           IPC_SWAP32(_x)


PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_ieee_802_addr {
    kal_uint8   addr[6];
} ipc_ieee_802_addr_t;
PRAGMA_END_PACK_STRUCT


PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_ip4_addr {
    union {
        kal_uint8   _u4_addr8[4];
        kal_uint16  _u4_addr16[2];
        kal_uint32  _u4_addr32;
    } _u4_addr;
} ipc_ip4_addr_t;
PRAGMA_END_PACK_STRUCT
#define s4_addr8  _u4_addr._u4_addr8
#define s4_addr16 _u4_addr._u4_addr16
#define s4_addr32 _u4_addr._u4_addr32


PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_ip6_addr {
    union {
        kal_uint8   _u6_addr8[16];
        kal_uint16  _u6_addr16[8];
        kal_uint32  _u6_addr32[4];
    } _u6_addr;
} ipc_ip6_addr_t;
PRAGMA_END_PACK_STRUCT
#define s6_addr8  _u6_addr._u6_addr8
#define s6_addr16 _u6_addr._u6_addr16
#define s6_addr32 _u6_addr._u6_addr32


PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_ip4_header {
    kal_uint8       ip_hl:4,    // header length
                    ip_ver:4;   // version
    kal_uint8       ip_tos;     // type of service
    kal_uint16      ip_len;     // total length
    kal_uint16      ip_id;      // identification
    kal_uint16      ip_off;     // fragment offset field
    kal_uint8       ip_ttl;     // time to live
    kal_uint8       ip_pro;     // protocol
    kal_uint16      ip_sum;     // checksum
    ipc_ip4_addr_t  ip_src;     // source address
    ipc_ip4_addr_t  ip_dst;     // destination address
} ipc_ip4_header_t;
PRAGMA_END_PACK_STRUCT


PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_ip6_header {
    union {
        kal_uint8   ip6_ver;                // 4 bits version
        kal_uint32  ip6_flow;               // 20 bits of flow-ID
    } ip6_un;
    kal_uint16      ip6_plen;               // payload length
    kal_uint8       ip6_nxt;                // next header
    kal_uint8       ip6_hlim;               // hop limit
    ipc_ip6_addr_t  ip6_src;                // source address
    ipc_ip6_addr_t  ip6_dst;                // destionation address
} ipc_ip6_header_t;
PRAGMA_END_PACK_STRUCT
#define IPC_IP6_VERSION_OFFSET      4
#define ip6_verion                  ip6_un.ip6_ver
#define ip6_flow                    ip6_un.ip6_flow


static INLINE void ipc_eui64_to_link_local(ipc_ip6_addr_t* dst)
{
    /* Link Local Prefix */
    dst->s6_addr8[0]    = 0xFE;
    dst->s6_addr8[1]    = 0x80;
    /* Admin Subnet */
    dst->s6_addr8[2]    = 0x00;
    dst->s6_addr8[3]    = 0x00;
    dst->s6_addr8[4]    = 0x00;
    dst->s6_addr8[5]    = 0x00;
    dst->s6_addr8[6]    = 0x00;
    dst->s6_addr8[7]    = 0x00;
}


static INLINE void ipc_mac_to_eui64(ipc_ieee_802_addr_t* src, ipc_ip6_addr_t* dst)
{
    /* Link Local Prefix */
    dst->s6_addr8[0]    = 0x00;
    dst->s6_addr8[1]    = 0x00;
    /* Admin Subnet */
    dst->s6_addr8[2]    = 0x00;
    dst->s6_addr8[3]    = 0x00;
    dst->s6_addr8[4]    = 0x00;
    dst->s6_addr8[5]    = 0x00;
    dst->s6_addr8[6]    = 0x00;
    dst->s6_addr8[7]    = 0x00;
    /* Interface ID */
    dst->s6_addr8[8]    = src->addr[0];
    dst->s6_addr8[8]   &= ~IPC_EUI64_GBIT;
    dst->s6_addr8[8]   |= IPC_EUI64_UBIT;
    dst->s6_addr8[9]    = src->addr[1];
    dst->s6_addr8[10]   = src->addr[2];
    dst->s6_addr8[11]   = 0xff;
    dst->s6_addr8[12]   = 0xfe;
    dst->s6_addr8[13]   = src->addr[3];
    dst->s6_addr8[14]   = src->addr[4];
    dst->s6_addr8[15]   = src->addr[5];
}


static INLINE void ipc_eui64_to_mac(ipc_ip6_addr_t* src, ipc_ieee_802_addr_t* dst)
{
    dst->addr[0]    = src->s6_addr8[8];
    dst->addr[0]   &= ~IPC_EUI64_UBIT;
    dst->addr[1]    = src->s6_addr8[9];
    dst->addr[2]    = src->s6_addr8[10];
    dst->addr[3]    = src->s6_addr8[13];
    dst->addr[4]    = src->s6_addr8[14];
    dst->addr[5]    = src->s6_addr8[15];
}


static INLINE void ipc_find_ipv4_data_header(ipc_ip4_header_t* pIp, kal_uint32* offset)
{
    *offset = pIp->ip_hl*4;
}


static INLINE void ipc_find_ipv6_data_header(ipc_ip6_header_t* pIp6, kal_uint8* next_header, kal_uint32* offset)
{
    kal_uint8 header_ext_len    = 0;

    /* search all next header, and find the last one */
    *next_header = pIp6->ip6_nxt;
    *offset = sizeof(ipc_ip6_header_t);
    do {
        kal_bool is_exit = KAL_FALSE;

        switch ( *next_header )
        {
            case IPC_IPPROTO_HOPOPTS:
            case IPC_IPPROTO_ROUTING:
            case IPC_IPPROTO_DSTOPTS:
            {
                *next_header = *((kal_uint8*)pIp6 + *offset);
                header_ext_len = *((kal_uint8*)pIp6 + *offset+1);
                *offset = 8 * ( 1 + header_ext_len );
                break;
            }
            case IPC_IPPROTO_FRAGMENT:
            {
                *next_header = *((kal_uint8*)pIp6 + *offset);
                header_ext_len = 0;
                *offset = 8;
                break;
            }
            case IPC_IPPROTO_AH:
            {
                *next_header = *((kal_uint8*)pIp6 + *offset);
                header_ext_len = *((kal_uint8*)pIp6 + *offset+1);
                *offset = 4 * ( 2 + header_ext_len );
                break;
            }
            case IPC_IPPROTO_NONE:
            case IPC_IPPROTO_ESP:
            default:
            {
                is_exit = KAL_TRUE;
                break;
            }
        }

        if ( is_exit == KAL_TRUE ) break;

    } while (1);

}


static INLINE kal_uint16 ipc_ip4_cksum(ipc_ip4_header_t* pIp, kal_uint16 len)
{
    kal_uint32 cksum    = 0;
    kal_uint16 word     = 0;
    kal_uint32 i        = 0;

    for ( i=0; i<len; i+=2 )
    {
        word = ((((kal_uint8*)pIp)[i] << 8) & 0xff00) + (((kal_uint8*)pIp)[i+1] & 0xff) ;
        cksum = cksum + word;
    }

    while ( cksum >> 16 )
        cksum = ( cksum & 0xffff ) + (cksum >> 16);

    return (kal_uint16)~cksum;
}


#define IPC_MASK_IP_VER         (0xF0)
#define IPC_IPV4_VER            (0x40)
#define IPC_IPV6_VER            (0x60)
#define IPC_MIN_IPV4_HDR_LEN    (20)
#define IPC_MIN_IPV6_HDR_LEN    (40)
#define IPC_MIN_IP_HEADER_LEN   (40)

#define IPC_IS_IPV4_PACKET(n) \
            (((n) & IPC_MASK_IP_VER) == IPC_IPV4_VER)
#define IPC_IS_IPV6_PACKET(n) \
            (((n) & IPC_MASK_IP_VER) == IPC_IPV6_VER)
static INLINE kal_bool ipc_swap_ip_addr(kal_uint8 *ip_hdr)
{
    kal_uint32 tmp;

    if (IPC_IS_IPV4_PACKET(*ip_hdr)) {
        ipc_ip4_header_t *ipv4 = (ipc_ip4_header_t *)ip_hdr;

        tmp = ipv4->ip_src.s4_addr32;   
        ipv4->ip_src.s4_addr32 = ipv4->ip_dst.s4_addr32;
        ipv4->ip_dst.s4_addr32 = tmp;
    } else if (IPC_IS_IPV6_PACKET(*ip_hdr)) {
        ipc_ip6_header_t *ipv6 = (ipc_ip6_header_t *)ip_hdr;

        tmp = ipv6->ip6_src.s6_addr32[0];
        ipv6->ip6_src.s6_addr32[0] = ipv6->ip6_dst.s6_addr32[0];
        ipv6->ip6_dst.s6_addr32[0] = tmp;

        tmp = ipv6->ip6_src.s6_addr32[1];
        ipv6->ip6_src.s6_addr32[1] = ipv6->ip6_dst.s6_addr32[1];
        ipv6->ip6_dst.s6_addr32[1] = tmp;

        tmp = ipv6->ip6_src.s6_addr32[2];
        ipv6->ip6_src.s6_addr32[2] = ipv6->ip6_dst.s6_addr32[2];
        ipv6->ip6_dst.s6_addr32[2] = tmp;

        tmp = ipv6->ip6_src.s6_addr32[3];
        ipv6->ip6_src.s6_addr32[3] = ipv6->ip6_dst.s6_addr32[3];
        ipv6->ip6_dst.s6_addr32[3] = tmp;
    } else {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


#endif  // _IPCORE_IPH_H

