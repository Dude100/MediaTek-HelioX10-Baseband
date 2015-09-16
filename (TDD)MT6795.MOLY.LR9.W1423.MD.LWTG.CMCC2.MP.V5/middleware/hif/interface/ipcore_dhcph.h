/*!
 *  @file ipcore_dhcph.h
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
 *  This file provides DHCP Header definitions of ipcore
 */

#ifndef _IPCORE_DHCPH_H
#define _IPCORE_DHCPH_H

#include "kal_public_api.h"

#define IPC_BP_CHADDR_LEN           16
#define IPC_BP_SNAME_LEN            64
#define IPC_BP_FILE_LEN             128
//#define IPC_BP_VEND_LEN             312+32

#define IPC_BP_BOOT_REQUEST         1
#define IPC_BP_BOOT_REPLY           2

#define IPC_BP_HTYPE_ETHERNET       1
#define IPC_BP_HTYPE_EXP_ETHERNET   2
#define IPC_BP_HTYPE_AX25           3
#define IPC_BP_HTYPE_PRONET         4
#define IPC_BP_HTYPE_CHAOS          5
#define IPC_BP_HTYPE_IEEE802        6
#define IPC_BP_HTYPE_ARCNET         7

#define IPC_BP_MAGIC_COOKIE         {0x63, 0x82, 0x53, 0x63}

#define IPC_BP_OPTION_PAD                                   0
#define IPC_BP_OPTION_SUBNET_MASK                           1
#define IPC_BP_OPTION_ROUTER                                3
#define IPC_BP_OPTION_DOMAIN_NAME_SERVER                    6
#define IPC_BP_OPTION_HOST_NAME                             12
#define IPC_BP_OPTION_INTERFACE_MTU                         26
#define IPC_BP_OPTION_REQUESTED_IP_ADDRESS                  50
#define IPC_BP_OPTION_IP_ADDRESS_LEASE_TIME                 51
#define IPC_BP_OPTION_DHCP_MESSAGE_TYPE                     53
#define IPC_BP_OPTION_SERVER_IDENTIFIER                     54
#define IPC_BP_OPTION_PARAMETER_REQUEST_LIST                55
#define IPC_BP_OPTION_MAXIMUM_DHCP_MESSAGE_SIZE             57
#define IPC_BP_OPTION_RENEWAL_TIME_VALUE                    58
#define IPC_BP_OPTION_REBINDING_TIME_VALUE                  59
#define IPC_BP_OPTION_VENDOR_CLASS_IDENTIFIER               60
#define IPC_BP_OPTION_CLIENT_IDENTIFIER                     61
#define IPC_BP_OPTION_CLIENT_FULLY_QUALIFIED_DOMAIN_NAME    81
#define IPC_BP_OPTION_END                                   255

#define IPC_BP_DHCP_MESSAGE_TYPE_DHCP_DISCOVER              1
#define IPC_BP_DHCP_MESSAGE_TYPE_DHCP_OFFER                 2
#define IPC_BP_DHCP_MESSAGE_TYPE_DHCP_REQUEST               3
#define IPC_BP_DHCP_MESSAGE_TYPE_DHCP_DECLINE               4
#define IPC_BP_DHCP_MESSAGE_TYPE_DHCP_ACK                   5
#define IPC_BP_DHCP_MESSAGE_TYPE_DHCP_NAK                   6
#define IPC_BP_DHCP_MESSAGE_TYPE_DHCP_RELEASE               7
#define IPC_BP_DHCP_MESSAGE_TYPE_DHCP_INFORM                8


PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_bootp_header {
    kal_uint8       bp_op;                  // packet opcode type
    kal_uint8       bp_htype;               // hardware addr type
    kal_uint8       bp_hlen;                // hardware addr length
    kal_uint8       bp_hops;                // gateway hops
    kal_uint32      bp_xid;                 // transaction ID
    kal_uint16      bp_secs;                // seconds since boot began
    kal_uint16      bp_flags;               // RFC1532 broadcazst, etc
    ipc_ip4_addr_t  bp_ciaddr;              // client IP address
    ipc_ip4_addr_t  bp_yiaddr;              // your IP address
    ipc_ip4_addr_t  bp_siaddr;              // server IP address
    ipc_ip4_addr_t  bp_giaddr;              // gateway IP address
    kal_uint8       bp_chaddr[IPC_BP_CHADDR_LEN];   // client hardware address
    kal_uint8       bp_sname[IPC_BP_SNAME_LEN];     // server host name
    kal_uint8       bp_file[IPC_BP_FILE_LEN];       // boot file name
} ipc_bootp_header_t;
PRAGMA_END_PACK_STRUCT

PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_bp_option_dhcp_message_type {
    kal_uint8           code;
    kal_uint8           len;
    kal_uint8           type;
} ipc_bp_option_dhcp_message_type_t;
PRAGMA_END_PACK_STRUCT

PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_bp_option_requested_ip_address {
    kal_uint8           code;
    kal_uint8           len;
    ipc_ip4_addr_t      address;
} ipc_bp_option_requested_ip_address_t;
PRAGMA_END_PACK_STRUCT

PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_bp_option_server_identifier {
    kal_uint8           code;
    kal_uint8           len;
    ipc_ip4_addr_t      address;
} ipc_bp_option_server_identifier_t;
PRAGMA_END_PACK_STRUCT

PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_bp_option_ip_address_lease_time {
    kal_uint8           code;
    kal_uint8           len;
    kal_uint32          lease_time;
} ipc_bp_option_ip_address_lease_time_t;
PRAGMA_END_PACK_STRUCT

PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_bp_option_maximum_dhcp_message_size {
    kal_uint8           code;
    kal_uint8           len;
    kal_uint16          length;
} ipc_bp_option_maximum_dhcp_message_size_t;
PRAGMA_END_PACK_STRUCT

PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_bp_option_subnet_mask {
    kal_uint8           code;
    kal_uint8           len;
    ipc_ip4_addr_t      subnet_mask;
} ipc_bp_option_subnet_mask_t;
PRAGMA_END_PACK_STRUCT

PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_bp_option_router {
    kal_uint8           code;
    kal_uint8           len;
    ipc_ip4_addr_t      address;
} ipc_bp_option_router_t;
PRAGMA_END_PACK_STRUCT

PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_bp_option_domain_name_server {
    kal_uint8           code;
    kal_uint8           len;
    ipc_ip4_addr_t      address;
} ipc_bp_option_domain_name_server_t;
PRAGMA_END_PACK_STRUCT

PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_bp_option_renewal_time_value {
    kal_uint8           code;
    kal_uint8           len;
    kal_uint32          t1_interval;
} ipc_bp_option_renewal_time_value_t;
PRAGMA_END_PACK_STRUCT

PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_bp_option_rebinding_time_value {
    kal_uint8           code;
    kal_uint8           len;
    kal_uint32          t2_interval;
} ipc_bp_option_rebinding_time_value_t;
PRAGMA_END_PACK_STRUCT

PRAGMA_BEGIN_PACK_STRUCT
typedef struct _ipc_bp_option_interface_mtu {
    kal_uint8           code;
    kal_uint8           len;
    kal_uint16          mtu;
} ipc_bp_option_interface_mtu_t;
PRAGMA_END_PACK_STRUCT

#endif  // _IPCORE_DHCPH_H

