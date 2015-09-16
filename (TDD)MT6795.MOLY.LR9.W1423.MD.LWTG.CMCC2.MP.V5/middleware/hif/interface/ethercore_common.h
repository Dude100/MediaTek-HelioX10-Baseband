/*!
 *  @file ethercore_common.h
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
 *  This file provides common definitions of ethercore
 */

#ifndef _ETHERCORE_COMMON_H
#define _ETHERCORE_COMMON_H

#include "kal_public_api.h"
#include "ethercore_struct.h"

#if !defined(__MTK_TARGET__) && defined(_MSC_VER) && (_MSC_VER >= 1500)
#pragma warning( disable : 4214 )
#endif

#define ETHC_ETHER_TYPE_IP          0x0800
#define ETHC_ETHER_TYPE_ARP         0x0806
#define ETHC_ETHER_TYPE_VLAN        0x8100
#define ETHC_ETHER_TYPE_IPV6        0x86dd

#define ETHC_SWAP16(_x)             ((_x & 0xff00) >> 8 | (_x & 0x00ff) << 8)
#define ETHC_SWAP32(_x)             ((_x & 0xff000000) >> 24 |  \
                                     (_x & 0x00ff0000) >> 8  |  \
                                     (_x & 0x0000ff00) << 8  |  \
                                     (_x & 0x000000ff) << 24)

#define ETHC_HTONS(_x)              ETHC_SWAP16(_x)
#define ETHC_HTONL(_x)              ETHC_SWAP32(_x)
#define ETHC_NTOHS(_x)              ETHC_SWAP16(_x)
#define ETHC_NTOHL(_x)              ETHC_SWAP32(_x)

#define ETHC_ETHER_ADDR_SIZE        6

typedef kal_uint8 ethc_mac_addr_t[ETHC_ETHER_ADDR_SIZE];


PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ethc_ether_header {
    ethc_mac_addr_t dst_mac;
    ethc_mac_addr_t src_mac;
    kal_uint16      ether_type;
} ethc_ether_header_t;
PRAGMA_END_PACK_STRUCT


PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ethc_vlan_tag {
    kal_uint16      tpid;               /* Tag Protocol Identifier */
    struct ethc_tci {   /* Tag Control Identifier */
        kal_uint16  pcp:3;              /* Priority Code Point */
        kal_uint16  cfi:1;              /* Canonical Format Indicator */
        kal_uint16  vid:12;             /* VLAN Identifier */
    } tci;
} ethc_vlan_tag_t;
PRAGMA_END_PACK_STRUCT


PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ethc_vlan_ether_header {
    ethc_mac_addr_t dst_mac;
    ethc_mac_addr_t src_mac;
    ethc_vlan_tag_t vlan_tag;
    kal_uint16      ether_type;
} ethc_vlan_ether_header_t;
PRAGMA_END_PACK_STRUCT


#define ETHC_ARP_HRD_ETHERNET           1
#define ETHC_ARP_HRD_IEEE802            6
#define ETHC_ARP_HRD_ARCNET             7
#define ETHC_ARP_HRD_FRAMERELAY         15
#define ETHC_ARP_HRD_ATM                16
#define ETHC_ARP_HRD_HDLC               17
#define ETHC_ARP_HRD_FIBRE_CHANNEL      18
#define ETHC_ARP_HRD_SERIAL_LINE        20

#define ETHC_ARP_PRO_IPV4               0x0800
#define ETHC_ARP_HLN_IEEE802_MAC        6
#define ETHC_ARP_PLN_IPV4               4

#define ETHC_ARP_OP_ARP_REQUEST         1
#define ETHC_ARP_OP_ARP_REPLY           2
#define ETHC_ARP_OP_ARP_RARP_REQUEST    3
#define ETHC_ARP_OP_ARP_RARP_REPLY      4
#define ETHC_ARP_OP_ARP_DRARP_REQUEST   5
#define ETHC_ARP_OP_ARP_DRARP_REPLY     6
#define ETHC_ARP_OP_ARP_DRARP_ERROR     7
#define ETHC_ARP_OP_ARP_INARP_REQUEST   8
#define ETHC_ARP_OP_ARP_INARP_REPLY     9

PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ethc_arp_packet {
    kal_uint16      arp_hrd;        /* hardware type */
    kal_uint16      arp_pro;        /* protocol type */
    kal_uint8       arp_hln;        /* hardware address length */
    kal_uint8       arp_pln;        /* protocol address length */
    kal_uint16      arp_op;         /* opcode */
    ethc_mac_addr_t arp_sha;        /* sender hardware address */
    kal_uint8       arp_spa[4];     /* sender protocol address */
    ethc_mac_addr_t arp_tha;        /* target hardware address */
    kal_uint8       arp_tpa[4];     /* target protocol address */
} ethc_arp_packet_t;
PRAGMA_END_PACK_STRUCT


/*!
 *  @brief ethc_device_instance_t describe register information of a
 *         generic ether device
 */
typedef struct _ethc_device_info {
    /*!
     *  @brief module id used to send ilm
     */
    module_type module_id;

    /*!
     *  @brief context to be passed in context function
     */
    void       *context;

    /*!
     *  @brief index the identify which network interface it is.
     */
    kal_uint32  netif_id;

    /*!
     *  @brief callback function to reload uplink buffers
     *         Running Level: TASK
     */
    kal_bool    (*ul_reload)(void *context);

    /*!
     *  @brief callback function to submit io request to ether device
     *         Running Level: TASK
     */
    void    (*tx_submit)(ethc_device_instance_t* instance, hif_io_request_t* ior);
} ethc_device_info_t;


/*!
 *  @brief  attach new ether device to ethercore
 *          Running Level: HISR/TASK
 *  @param  device_info ether device information used to register
 *  @return new instance of ether device if success, NULL if fail
 */
ethc_device_instance_t* ethc_device_attach(ethc_device_info_t* device_info);


/*!
 *  @brief  detach ether device from ethecore
 *          Running Level: HISR/TASK
 *  @param  instance  device instance obtained while attach 
 */
void ethc_device_detach(ethc_device_instance_t* instance);


/*!
 *  @brief  indicate received io request to ethecore
 *          Running Level: TASK
 *  @param  instance  device instance obtained while attach
 *  @param  ior io request list to be indicated
 */
void ethc_device_rx_complete(ethc_device_instance_t* instance, hif_io_request_t* ior);

/*!
 *  @brief  indicate the underlying device needs to reload UL buffers
 *          Running Level: TASK
 *  @param  instance  device instance obtained while attach
 */
void ethc_device_rx_need_reload(ethc_device_instance_t* instance);

void ethc_get_host_mac(kal_uint32 netid_if, kal_uint8* mac_addr);

#endif  // _ETHERCORE_COMMON_H

