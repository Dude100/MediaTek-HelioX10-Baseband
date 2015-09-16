/*!
 *  @file ipcore_udph.h
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
 *  This file provides UDP Header definitions of ipcore
 */

#ifndef _IPCORE_UDPH_H
#define _IPCORE_UDPH_H

#include "kal_public_api.h"

PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_udp_header {
    kal_uint16      udp_src_port;           // udp source port
    kal_uint16      udp_dst_port;           // udp destination port
    kal_uint16      udp_len;                // udp length
    kal_uint16      udp_sum;                // udp checksum
} ipc_udp_header_t;
PRAGMA_END_PACK_STRUCT



static INLINE kal_uint16 ipc_udp_cksum(ipc_udp_header_t* pUdp, kal_uint16 len, ipc_ip4_addr_t* ip_src, ipc_ip4_addr_t* ip_dst)
{
    kal_uint32 cksum    = 0;
    kal_uint16 word     = 0;
    kal_uint16 i        = 0;

    for (i=0; i< ((len+1)&~1); i=i+2)
    {
        if ( i == (len -1) )
        {
            word = ( (((kal_uint8*)pUdp)[i] << 8 ) & 0xff00 ) + 0x00;
        } else {
            word = ( (((kal_uint8*)pUdp)[i] << 8 ) & 0xff00 ) + (((kal_uint8*)pUdp)[i+1] & 0xff);
        }
        cksum = cksum + word;
    }

    for (i=0; i<sizeof(ipc_ip4_addr_t); i=i+2)
    {
        word = ( (((kal_uint8*)ip_src)[i] << 8 ) & 0xff00 ) + (((kal_uint8*)ip_src)[i+1] & 0xff);
        cksum = cksum + word;
    }

    for (i=0; i<sizeof(ipc_ip4_addr_t); i=i+2)
    {
        word = ( (((kal_uint8*)ip_dst)[i] << 8 ) & 0xff00 ) + (((kal_uint8*)ip_dst)[i+1] & 0xff);
        cksum = cksum + word;
    }

    cksum = cksum + IPC_IPPROTO_UDP +len;

    while ( cksum >> 16 )
        cksum = ( cksum & 0xffff ) + ( cksum >> 16 );

    return (kal_uint16)~cksum;
}


#endif  // _IPCORE_UDPH_H

