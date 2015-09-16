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
 *   ipc_api.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   IP Core public structure and interface definition.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                 HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __INC_IPC_API_H
#define __INC_IPC_API_H

#include "hif_ior.h"
#include "hif_mw_msgid.h"
#include "ipc_defs_public.h"
#include "ipc_enums.h"
#include "ipc_struct.h"
#include "ipc_filter_priority.h"

/*------------------------------------------------------------------------------
 * Data structure defintion.
 *----------------------------------------------------------------------------*/
typedef struct _ipc_io_request_t {
    struct _ipc_io_request_t    *next_request;
    qbm_gpd*                    first_gpd;
    qbm_gpd*                    last_gpd;
    kal_uint8                   ip_type; /**< Type of IP datagrams, see IPC_IP_TYPE_XXX defined for valid values. */
    kal_uint8                   qos_priority; /**< Priority, valid from 0~7. */
    kal_uint8                   reserved[2];
} ipc_io_request_t;

typedef struct _ipc_conf_t {
    module_type     module_id; /**< The module registering with IP CORE. */
    kal_uint32      netif_id; /**< An index to identify instance of a specific module. For example, if module_id is MOD_ETHERCORE, netif_id is 0, it reprents for eth0. */
    kal_uint32      features; /**< Each bit is set to enable an optional feature, see IPC_F_XXX for details. */

    void           *ul_reload_context; /**< Context to be passed in the callback function ipc_ul_reload_callback_t. */
    kal_bool        (*ipc_ul_reload_callback_t)(void *context); /**< Uplink reloading callback function. */

    void           *callback_context; /**< Context to be passed in the follow callback functions. */
    kal_bool        (*ipc_dlink_callback_t)(void *context, ipc_io_request_t *ior); /** Downlink callback function. */
} ipc_conf_t;

typedef struct _ipc_pkt_t {
    kal_bool    isGPD;      /**< KAL_TRUE : Describe GPD list (with head/tail), KAL_FALSE : Describe single data buffer (with pointer/length) */

    /* Used if isGPD == KAL_TRUE */
    qbm_gpd     *head;      /**< Head of GPD List. Used if isGPD == KAL_TRUE */
    qbm_gpd     *tail;      /**< Tail of GPD List. Used if isGPD == KAL_TRUE */

    /* Used if isGPD == KAL_FALSE */
    kal_uint8   *data;      /**< Data pointer of buffer. Used if isGPD == KAL_FALSE */
    kal_uint32  data_len;   /**< Data pointer of buffer. Used if isGPD == KAL_FALSE */

} ipc_pkt_t;

typedef struct _ipc_hdr_t {
    kal_uint8       ip_type;    /**< Type of IP datagrams, see IPC_IP_TYPE_XXX defined for valid values. Note that only one of IPv4/IPv6 can be selected and MIX type is NOT allowed */
    kal_uint8       *src_addr;  /**< Source IP Address, length of this pointer is decided by ip_type field */
    kal_uint8       *dst_addr;  /**< Destination IP Address, length of this pointer is decided by ip_type field */
    kal_uint16      src_port;   /**< Source Port Number */
    kal_uint16      dst_port;   /**< Destination Port Number */
    kal_uint8       dscp_tc;    /**< DSCP(IPv4) or Traffic Class(IPv6) field */
} ipc_hdr_t;

typedef void * ipc_handle_t;

typedef struct _ipc_filter_rules_t {
    kal_uint8       features; /**< Union of  to indicate which type of filter it is. */
    kal_uint16      priority; /**< Priority will affect the order of filter rules when performing filtering. */
    kal_uint32      valid_fields; /**< Union of IPC_FILTER_BY_XXX to indicate which fields in this structure are valid. */
    kal_uint32      netif_id; /**< Network interface ID to filter. */
    kal_uint32      pdn_id;   /**< [downlink filter ONLY] PDN ID to filter. */
    kal_uint8       ebi;      /**< [downlink filter ONLY] EBI/NSAPI to filter. */
    kal_uint8       ip_type;  /**< Type of IP traffic the filter to apply, see IPC_IP_TYPE_XXX defined for valid values. */
    kal_uint8       protocol; /**< The protocol used in the data portion of the IP datagram to filter. */

    kal_uint16      src_port; /**< Source port number to filter. */
    kal_uint16      dst_port; /**< Destination port number to filter. */

	union{
		kal_uint8 		addr8[4];
		kal_uint32 		addr32;
	}src_ipv4; /**< Source IPv4 address to filter. */
	union{
		kal_uint8 		addr8[4];
		kal_uint32 		addr32;
	}dst_ipv4; /**< Destination IPv4 address to filter. */

	union{
		kal_uint8 		addr8[16];
		kal_uint32 		addr32[4];
	}src_ipv6; /**< Source IPv6 address to filter. */
	union{
		kal_uint8 		addr8[16];
		kal_uint32 		addr32[4];
	}dst_ipv6; /**< Destination IPv6 address to filter. */

    kal_uint8       icmpv4_type;    /**< Type field of ICMPv4 header to filter. */
    kal_uint8       icmpv6_type;    /**< Type field of ICMPv6 header to filter. */
} ipc_filter_rules_t;

/*
 * Callback function to process the IP datagram filtered.
 *
 * @param   context [IN] A context specified while registering the filter.
 * @param   filter_id [IN] Corresponding registered filter ID.
 * @param   head_gpd [IN] Pointer head of the GPD list for the IP datagram filtered.
 * @param   tail_gpd [IN] Pointer tail of the GPD list for the IP datagram filtered.
 * @param   length [IN] Bytes of buffers used in the GPD list.
 */
typedef void (*ipc_filter_callback_t)(
        void       *context, 
        kal_int32   filter_id,
        qbm_gpd    *head_gpd, 
        qbm_gpd    *tail_gpd, 
        kal_uint32  length);

/*
 * Callback function with packet information to process the IP datagram filtered.
 *
 * @param   info_p [IN] Related information of filtered out GPDs.
 * @param   context [IN] A context specified while registering the filter.
 * @param   filter_id [IN] Corresponding registered filter ID.
 * @param   head_gpd [IN] Pointer head of the GPD list for the IP datagram filtered.
 * @param   tail_gpd [IN] Pointer tail of the GPD list for the IP datagram filtered.
 * @param   length [IN] Bytes of buffers used in the GPD list.
 */
typedef void (*ipc_filter_with_info_callback_t)(
        ipc_filter_info_t       *info_p,
        void                    *context, 
        kal_int32                filter_id,
        qbm_gpd                 *head_gpd, 
        qbm_gpd                 *tail_gpd, 
        kal_uint32               length);

/*
 * Callback function to notify IP CORE notification.
 *
 * @param   param [IN] Parameter to notify registered module.
 */
typedef void (*ipc_ntfy_callback_t)(ipc_ntfy_param_t *param);

/*------------------------------------------------------------------------------
 * Helper Macro.
 *----------------------------------------------------------------------------*/
/*
 * IPv4/IPv6 common.
 */
#define IPC_NE_GET_1B(_buf) \
            ((kal_uint8)*((kal_uint8 *)(_buf)))
#define IPC_NE_SET_1B(_buf, _value) \
            do { \
                *((kal_uint8 *)(_buf)) = (kal_uint8)(_value); \
            } while (0)

#ifndef IPC_ON_BIG_ENDIAN_PLATFORM /* little-endian platform */
    #define IPC_NE_GET_2B(_buf) \
            ( (((kal_uint16)*((kal_uint8 *)(_buf) + 0)) << 8) | \
              (((kal_uint16)*((kal_uint8 *)(_buf) + 1)) << 0) )
    
    #define IPC_NE_SET_2B(_buf, _value) \
            do { \
                *((kal_uint8 *)(_buf) + 0) = (kal_uint8)((_value) >> 8); \
                *((kal_uint8 *)(_buf) + 1) = (kal_uint8)((_value) >> 0); \
            } while (0)

    #define IPC_NE_GET_4B(_buf) \
            ( (((kal_uint32)*((kal_uint8 *)(_buf) + 0)) << 24) | \
              (((kal_uint32)*((kal_uint8 *)(_buf) + 1)) << 16) | \
              (((kal_uint32)*((kal_uint8 *)(_buf) + 2)) << 8) | \
              (((kal_uint32)*((kal_uint8 *)(_buf) + 3)) << 0) )

    #define IPC_NE_SET_4B(_buf, _value) \
            do { \
                *((kal_uint8 *)(_buf) + 0) = (kal_uint8)((_value) >> 24); \
                *((kal_uint8 *)(_buf) + 1) = (kal_uint8)((_value) >> 16); \
                *((kal_uint8 *)(_buf) + 2) = (kal_uint8)((_value) >> 8); \
                *((kal_uint8 *)(_buf) + 3) = (kal_uint8)((_value) >> 0); \
            } while (0)

    #define IPC_H2N_2B(_value) \
            (((kal_uint16)(_value) >> 8) | (((kal_uint16)(_value) & 0xff) << 8))

#else /* big-endian platform */
    #define IPC_NE_GET_2B(_buf) \
        ( (((kal_uint16)*((kal_uint8 *)(_buf) + 0)) << 0) | \
          (((kal_uint16)*((kal_uint8 *)(_buf) + 1)) << 8) )
    
    #define IPC_NE_SET_2B(_buf, _value) \
        do { \
            *((kal_uint8 *)(_buf) + 0) = (kal_uint8)((_value) >> 0); \
            *((kal_uint8 *)(_buf) + 1) = (kal_uint8)((_value) >> 8); \
        } while (0)

    #define IPC_NE_GET_4B(_buf) \
        ( (((kal_uint32)*((kal_uint8 *)(_buf) + 0)) << 0) | \
          (((kal_uint32)*((kal_uint8 *)(_buf) + 1)) << 8) | \
          (((kal_uint32)*((kal_uint8 *)(_buf) + 2)) << 16) | \
          (((kal_uint32)*((kal_uint8 *)(_buf) + 3)) << 24) )
    
    #define IPC_NE_SET_4B(_buf, _value) \
            do { \
                *((kal_uint8 *)(_buf) + 0) = (kal_uint8)((_value) >> 0); \
                *((kal_uint8 *)(_buf) + 1) = (kal_uint8)((_value) >> 8); \
                *((kal_uint8 *)(_buf) + 2) = (kal_uint8)((_value) >> 16); \
                *((kal_uint8 *)(_buf) + 3) = (kal_uint8)((_value) >> 24); \
            } while (0)

    #define IPC_H2N_2B(_value) \
            ((kal_uint16)(_value))
#endif

#define IPC_HDR_IS_V4(_ip_hdr) \
        (0x40 == (*((kal_uint8 *)(_ip_hdr)) & 0xf0))

#define IPC_HDR_IS_V6(_ip_hdr) \
        (0x60 == (*((kal_uint8 *)(_ip_hdr)) & 0xf0))


#define IPC_CP_ADDR(_dst, _src, _len) \
        kal_mem_cpy((_dst), (_src), (_len))

#define IPC_EQ_ADDR(_addr1, _addr2, _len) \
        (0 == kal_mem_cmp((_addr1), (_addr2), (_len)))

#define IPC_EQ_2BYTE(_ptr1, _ptr2) \
        (   ((*(kal_uint8 *)(_ptr1)) == (*((kal_uint8 *)(_ptr2)))) && \
            ((*((kal_uint8 *)(_ptr1) + 1)) == (*(((kal_uint8 *)(_ptr2) + 1))))    )

#define IPC_EQ_1BYTE(_ptr1, _ptr2) \
        ((*(kal_uint8 *)(_ptr1)) == (*((kal_uint8 *)(_ptr2))))


/*
 * IANA IP Protocol Numbers.
 * Ref: http://www.iana.org/assignments/protocol-numbers/protocol-numbers.xml
 */
#define IPC_HDR_PROT_IPV6_HOP           0 /* IPv6 Hop-by-Hop Option */
#define IPC_HDR_PROT_ICMP               1 /* Internet Control Message */
#define IPC_HDR_PROT_IPV4_ENC           4 /* IPv4 encapsulation */
#define IPC_HDR_PROT_TCP                6 /* Transmission Control */
#define IPC_HDR_PROT_UDP                17 /* User Datagram */
#define IPC_HDR_PROT_IPV6_ENC           41 /* IPv6 encapsulation */
#define IPC_HDR_PROT_IPV6_ROUTE         43 /* Routing Header for IPv6 */
#define IPC_HDR_PROT_IPV6_FRAG          44 /* Fragment Header for IPv6 */
#define IPC_HDR_PROT_ESP                50 /* Encap Security Payload */
#define IPC_HDR_PROT_AH                 51 /* Authentication Header */
#define IPC_HDR_PROT_ICMPV6             58 /* ICMP for IPv6 */
#define IPC_HDR_PROT_IPV6_NONEXT        59 /* No Next Header for IPv6 */
#define IPC_HDR_PROT_IPV6_DEST          60 /* Destination Options for IPv6 */

/*
 * IPv4.
 */
#define IPC_HDR_V4_ADDR_SIZE        (4)
#define IPC_HDR_V4_HEADER_SIZE      (20)

#define IPC_HDR_V4_GET_IHL(_ip_header) \
        ((IPC_NE_GET_1B(_ip_header) & 0x0f) << 2)

#define IPC_HDR_V4_SET_IHL(_ip_header, _ihl) \
        do { \
            IPC_NE_SET_1B(_ip_header, (IPC_NE_GET_1B(_ip_header) & 0xF0) | (((kal_uint8)(_ihl)>>2) & 0x0F)); \
        } while (0)

#define IPC_HDR_V4_GET_DSCP(_ip_header) \
        (IPC_NE_GET_1B(((kal_uint8*)(_ip_header)) + 1)>> 2)

#define IPC_HDR_V4_SET_DSCP(_ip_header, _dscp) \
        do { \
            IPC_NE_SET_1B(((kal_uint8*)(_ip_header)) + 1, (IPC_NE_GET_1B(((kal_uint8*)(_ip_header)) + 1) & 0xFC) | ((kal_uint8)(_dscp) << 2)); \
        } while (0)

#define IPC_HDR_V4_RESET_VER_IHL_DSCP_ECN(_ip_header) \
        do { \
            IPC_NE_SET_1B(_ip_header, 0x45); \
            IPC_NE_SET_1B(((kal_uint8 *)(_ip_header)) + 1, 0x00); \
        } while (0)

#define IPC_HDR_V4_GET_TOTAL_LENGTH(_ip_header) \
        IPC_NE_GET_2B(((kal_uint8 *)(_ip_header)) + 2)

#define IPC_HDR_V4_SET_TOTAL_LENGTH(_ip_header, _length) \
        do { \
            IPC_NE_SET_2B(((kal_uint8 *)(_ip_header)) + 2, _length); \
        } while (0)

#define IPC_HDR_V4_GET_IDENTITY(_ip_header) \
        IPC_NE_GET_2B(((kal_uint8 *)(_ip_header)) + 4)

#define IPC_HDR_V4_SET_IDENTITY(_ip_header, _id) \
        do { \
            IPC_NE_SET_2B(((kal_uint8 *)(_ip_header)) + 4, _id); \
        } while (0)

#define IPC_HDR_V4_GET_FLAGS(_ip_header) \
        ((*(((kal_uint8 *)(_ip_header) + 6))) >> 5)

#define IPC_HDR_V4_SET_FLAGS(_ip_header, _flags) \
        do { \
            IPC_NE_SET_1B(((kal_uint8*)(_ip_header)) + 6, (IPC_NE_GET_1B(((kal_uint8*)(_ip_header)) + 6) & 0x1F) | ((kal_uint8)(_flags) << 5));\
        } while (0)

#define IPC_HDR_V4_IS_MF(_ip_header) \
        (IPC_HDR_V4_GET_FLAGS(_ip_header) & 0x04)

#define IPC_HDR_V4_GET_FRAG_OFFSET(_ip_header) \
        (IPC_NE_GET_2B(((kal_uint8 *)(_ip_header)) + 6) & 0x1fff)

#define IPC_HDR_V4_SET_FRAG_OFFSET(_ip_header, _offset) \
        do { \
        IPC_NE_SET_2B((((kal_uint8 *)(_ip_header)) + 6), \
                       ((IPC_NE_GET_2B(((kal_uint8 *)(_ip_header)) + 6) & 0xe000) | \
                         ((kal_uint16)(_offset) & 0x1fff)) ); \
        } while (0)

#define IPC_HDR_V4_IS_FRAG(_ip_header) \
        (IPC_HDR_V4_IS_MF(_ip_header) || (0 != IPC_HDR_V4_GET_FRAG_OFFSET(_ip_header)))

#define IPC_HDR_V4_GET_TTL(_ip_header) \
        IPC_NE_GET_1B(((kal_uint8 *)(_ip_header)) + 8)

#define IPC_HDR_V4_SET_TTL(_ip_header, _ttl) \
        do { \
            IPC_NE_SET_1B(((kal_uint8 *)(_ip_header)) + 8, (kal_uint8)(_ttl)); \
        } while (0)

#define IPC_HDR_V4_GET_PROTOCOL(_ip_header) \
        IPC_NE_GET_1B(((kal_uint8 *)(_ip_header)) + 9)

#define IPC_HDR_V4_SET_PROTOCOL(_ip_header, _protocol) \
        do { \
            IPC_NE_SET_1B(((kal_uint8 *)(_ip_header)) + 9, (kal_uint8)(_protocol)); \
        } while (0)

#define IPC_HDR_V4_EQ_PROTOCOL(_ip_header, _protocol)   \
        (IPC_HDR_V4_GET_PROTOCOL(_ip_header) == (_protocol))

#define IPC_HDR_V4_GET_HEADER_CHECKSUM(_ip_header) \
        IPC_NE_GET_2B((kal_uint8 *)(_ip_header) + 10)

#define IPC_HDR_V4_SET_HEADER_CHECKSUM(_ip_header, _checksum) \
        do { \
            IPC_NE_SET_2B((kal_uint8 *)(_ip_header) + 10, _checksum); \
        } while (0)

#define IPC_HDR_V4_GET_SRC_ADDR(_ip_header) \
        ((kal_uint8 *)(_ip_header) + 12)

#define IPC_HDR_V4_SET_SRC_ADDR(_ip_header, _src_ip_addr) \
        do { \
            IPC_CP_V4_ADDR(IPC_HDR_V4_GET_SRC_ADDR(_ip_header), _src_ip_addr); \
        } while (0)

#define IPC_HDR_V4_GET_DST_ADDR(_ip_header) \
        ((kal_uint8 *)(_ip_header) + 16)

#define IPC_HDR_V4_SET_DST_ADDR(_ip_header, _dst_ip_addr) \
        do { \
            IPC_CP_V4_ADDR(IPC_HDR_V4_GET_DST_ADDR(_ip_header), _dst_ip_addr); \
        } while (0)

#define IPC_HDR_V4_GET_NHPTR(_ip_header) \
        ((kal_uint8 *)(_ip_header) + IPC_HDR_V4_GET_IHL(_ip_header))

#define IPC_CP_V4_ADDR(_dst, _src) \
        do { \
        IPC_CP_ADDR(_dst, _src, IPC_HDR_V4_ADDR_SIZE); \
        } while (0)

#define IPC_EQ_V4_ADDR(_addr1, _addr2) \
        IPC_EQ_ADDR(_addr1, _addr2, IPC_HDR_V4_ADDR_SIZE)

#define IPC_IS_V4_CLASSA_ADDR(_addr) \
        ( 0x00 == (*((kal_uint8 *)(_addr)) & 0xf0) )

#define IPC_IS_V4_CLASSB_ADDR(_addr) \
        ( 0x80 == (*((kal_uint8 *)(_addr)) & 0xf0) )

#define IPC_IS_V4_CLASSC_ADDR(_addr) \
        ( 0xc0 == (*((kal_uint8 *)(_addr)) & 0xf0) )

#define IPC_IS_V4_CLASSD_ADDR(_addr) \
        ( 0xe0 == (*((kal_uint8 *)(_addr)) & 0xf0) )

#define IPC_IS_V4_UNSPECIFIED_ADDR(_addr) \
        ( 0 == *((kal_uint8*)(_addr)) && \
          0 == *((kal_uint8*)(_addr)+1) && \
          0 == *((kal_uint8*)(_addr)+2) && \
          0 == *((kal_uint8*)(_addr)+3) )

/*
 * IPv6.
 */
#define IPC_HDR_V6_ADDR_SIZE        (16)
#define IPC_HDR_V6_HEADER_SIZE      (40)
#define IPC_HDR_V6_MAX_HOP          (255)

#define IPC_HDR_V6_LENGTH_OFFSET    (4)
#define IPC_HDR_V6_NH_TYPE_OFFSET   (6)
#define IPC_HDR_V6_HOP_LIMIT_OFFSET (7)
#define IPC_HDR_V6_SRC_ADDR_OFFSET  (8)
#define IPC_HDR_V6_DST_ADDR_OFFSET  (24)

#define IPC_HDR_V6_GET_TC(_ip_header) \
        ((IPC_NE_GET_2B(_ip_header) >> 4) & 0xff)

#define IPC_HDR_V6_SET_TC(_ip_header, _tc) \
        do { \
            IPC_NE_SET_2B(_ip_header, \
                          ((IPC_NE_GET_2B(_ip_header) & 0xf00f) | (((kal_uint16)(_tc) & 0xff) << 4))); \
        } while (0)

#define IPC_HDR_V6_GET_FLOW_LABEL(_ip_header) \
        (IPC_NE_GET_4B(_ip_header) & 0xfffff)

#define IPC_HDR_V6_SET_FLOW_LABEL(_ip_header, _flow_label) \
        do { \
        IPC_NE_SET_4B(_ip_header, \
                      ((IPC_NE_GET_4B(_ip_header) & 0xfff00000) | ((kal_uint32)(_flow_label) & 0xfffff))); \
        } while (0)

#define IPC_HDR_V6_RESET_VER_TC_FL(_ip_header) \
        do { \
            kal_mem_set((kal_uint8 *)(_ip_header), 0, 4); \
            *((kal_uint8 *)(_ip_header)) |= 0x60; \
        } while (0)

#define IPC_HDR_V6_GET_LENGTH(_ip_header) \
        IPC_NE_GET_2B((kal_uint8 *)(_ip_header) + IPC_HDR_V6_LENGTH_OFFSET)

#define IPC_HDR_V6_SET_LENGTH(_ip_header, _length) \
        do { \
            IPC_NE_SET_2B((kal_uint8 *)(_ip_header) + IPC_HDR_V6_LENGTH_OFFSET, _length); \
        } while (0)

#define IPC_HDR_V6_GET_NH_TYPE(_ip_header) \
        IPC_NE_GET_1B(((kal_uint8 *)(_ip_header)) + IPC_HDR_V6_NH_TYPE_OFFSET)

#define IPC_HDR_V6_SET_NH_TYPE(_ip_header, _type) \
        do { \
            IPC_NE_SET_1B(((kal_uint8 *)(_ip_header)) + IPC_HDR_V6_NH_TYPE_OFFSET, (kal_uint8)(_type)); \
        } while (0)

#define IPC_HDR_V6_GET_HOP_LIMIT(_ip_header) \
        IPC_NE_GET_1B((kal_uint8 *)(_ip_header) + IPC_HDR_V6_HOP_LIMIT_OFFSET)

#define IPC_HDR_V6_SET_HOP_LIMIT(_ip_header, _hop_limit) \
        do { \
            IPC_NE_SET_1B(((kal_uint8 *)(_ip_header)) + IPC_HDR_V6_HOP_LIMIT_OFFSET, (kal_uint8)(_hop_limit)); \
        } while (0)

#define IPC_HDR_V6_GET_SRC_ADDR(_ip_header) \
        ((kal_uint8 *)(_ip_header) + IPC_HDR_V6_SRC_ADDR_OFFSET)

#define IPC_HDR_V6_SET_SRC_ADDR(_ip_header, _src_ip_addr) \
        do { \
            IPC_CP_V6_ADDR(IPC_HDR_V6_GET_SRC_ADDR(_ip_header), _src_ip_addr); \
        } while (0)

#define IPC_HDR_V6_GET_DST_ADDR(_ip_header) \
        ((kal_uint8 *)(_ip_header) + IPC_HDR_V6_DST_ADDR_OFFSET)

#define IPC_HDR_V6_SET_DST_ADDR(_ip_header, _dst_ip_addr) \
        do { \
            IPC_CP_V6_ADDR(IPC_HDR_V6_GET_DST_ADDR(_ip_header), _dst_ip_addr); \
        } while (0)

#define IPC_HDR_V6_GET_NHPTR(_ip_header) \
        ((kal_uint8 *)(_ip_header) + IPC_HDR_V6_HEADER_SIZE)

#define IPC_HDR_V6_SET_DST_SOL_MCST_ADDR(_ip_header, _dst_ip_addr) \
        do { \
            *(IPC_HDR_V6_GET_DST_ADDR(_ip_header)) = 0xff; \
            *(IPC_HDR_V6_GET_DST_ADDR(_ip_header) + 1) = 0x02; \
            kal_mem_set(IPC_HDR_V6_GET_DST_ADDR(_ip_header) + 2, 0, 9); \
            *(IPC_HDR_V6_GET_DST_ADDR(_ip_header) + 11) = 0x01; \
            *(IPC_HDR_V6_GET_DST_ADDR(_ip_header) + 12) = 0xff; \
            kal_mem_cpy(IPC_HDR_V6_GET_DST_ADDR(_ip_header) + 13, (kal_uint8 *)(_dst_ip_addr) + 13, 3); \
        } while (0)

#define IPC_HDR_V6EXT_GET_NH_TYPE(_ext_header) \
        IPC_NE_GET_1B(_ext_header)

#define IPC_HDR_V6EXT_GET_HDR_EXT_LEN(_ext_header) \
        ((IPC_NE_GET_1B(((kal_uint8*)(_ext_header))+1) + 1) << 3)

#define IPC_IS_V6_LINK_LOCAL_ADDR(_addr) \
        (   (0xfe == IPC_NE_GET_1B(_addr)) && \
            (0x80 == IPC_NE_GET_1B(((kal_uint8*)(_addr)) + 1)))

#define IPC_IS_V6_GLOBAL_ADDR(_addr) \
        ( 0x20 == (IPC_NE_GET_1B(_addr) & 0xe0) )

#define IPC_IS_V6_UNSPECIFIED_ADDR(_addr) \
        ( 0x00 == *((kal_uint8 *)(_addr)) && \
          0x00 == *((kal_uint8 *)(_addr) +  1) && \
          0x00 == *((kal_uint8 *)(_addr) +  2) && \
          0x00 == *((kal_uint8 *)(_addr) +  3) && \
          0x00 == *((kal_uint8 *)(_addr) +  4) && \
          0x00 == *((kal_uint8 *)(_addr) +  5) && \
          0x00 == *((kal_uint8 *)(_addr) +  6) && \
          0x00 == *((kal_uint8 *)(_addr) +  7) && \
          0x00 == *((kal_uint8 *)(_addr) +  8) && \
          0x00 == *((kal_uint8 *)(_addr) +  9) && \
          0x00 == *((kal_uint8 *)(_addr) + 10) && \
          0x00 == *((kal_uint8 *)(_addr) + 11) && \
          0x00 == *((kal_uint8 *)(_addr) + 12) && \
          0x00 == *((kal_uint8 *)(_addr) + 13) && \
          0x00 == *((kal_uint8 *)(_addr) + 14) && \
          0x00 == *((kal_uint8 *)(_addr) + 15))

#define IPC_IS_V6_MCST_ADDR(_addr) \
        ( 0xff == IPC_NE_GET_1B(_addr) )

#define IPC_CP_V6_ADDR(_dst, _src) \
        IPC_CP_ADDR(_dst, _src, IPC_HDR_V6_ADDR_SIZE)

#define IPC_EQ_V6_ADDR(_addr1, _addr2) \
        IPC_EQ_ADDR(_addr1, _addr2, IPC_HDR_V6_ADDR_SIZE)

/*
 * UDP.
 */
#define IPC_HDR_UDP_HEADER_SIZE     (8)

#define IPC_HDR_UDP_GET_SRC_PORT(_udp) \
        IPC_NE_GET_2B(_udp)

#define IPC_HDR_UDP_SET_SRC_PORT(_udp, _src_port) \
        IPC_NE_SET_2B((kal_uint8 *)(_udp), _src_port)

#define IPC_HDR_UDP_EQ_SRC_PORT(_udp, _src_port)    \
        (IPC_HDR_UDP_GET_SRC_PORT(_udp) == (_src_port))

#define IPC_HDR_UDP_GET_DST_PORT(_udp) \
        IPC_NE_GET_2B((kal_uint8 *)(_udp) + 2)

#define IPC_HDR_UDP_SET_DST_PORT(_udp, _dst_port) \
        IPC_NE_SET_2B((kal_uint8 *)(_udp) + 2, _dst_port)

#define IPC_HDR_UDP_EQ_DST_PORT(_udp, _dst_port)    \
        (IPC_HDR_UDP_GET_DST_PORT(_udp) == (_dst_port))

#define IPC_HDR_UDP_GET_LENGTH(_udp) \
        IPC_NE_GET_2B((kal_uint8 *)(_udp) + 4)

#define IPC_HDR_UDP_SET_LENGTH(_udp, _length) \
        IPC_NE_SET_2B((kal_uint8 *)(_udp) + 4, _length)

#define IPC_HDR_UDP_GET_CHECKSUM(_udp) \
        IPC_NE_GET_2B((kal_uint8 *)(_udp) + 6)

#define IPC_HDR_UDP_SET_CHECKSUM(_udp, _checksum) \
        IPC_NE_SET_2B((kal_uint8 *)(_udp) + 6, _checksum)

/*
 * TCP.
 */
#define IPC_HDR_TCP_FLAG_FIN    0x01
#define IPC_HDR_TCP_FLAG_SYN    0x02
#define IPC_HDR_TCP_FLAG_RST    0x04    // Reset
#define IPC_HDR_TCP_FLAG_PUSH   0x08
#define IPC_HDR_TCP_FLAG_ACK    0x10
#define IPC_HDR_TCP_FLAG_URG    0x20    // Urgent
#define IPC_HDR_TCP_FLAG_ECE    0x40    // ECN Echo
#define IPC_HDR_TCP_FLAG_CWR    0x80    // Congestion Window Reduced
#define IPC_HDR_TCP_FLAG_NS     0x100   // ECN-nonce concealment protection (added to header by RFC 3540)


#define IPC_HDR_TCP_HEADER_SIZE     (20)

#define IPC_HDR_TCP_GET_SRC_PORT(_tcp) \
        IPC_NE_GET_2B(_tcp)

#define IPC_HDR_TCP_SET_SRC_PORT(_tcp, _src_port) \
        IPC_NE_SET_2B(_tcp, _src_port)

#define IPC_HDR_TCP_EQ_SRC_PORT(_tcp, _src_port)    \
        (IPC_HDR_TCP_GET_SRC_PORT(_tcp) == (_src_port))

#define IPC_HDR_TCP_GET_DST_PORT(_tcp) \
        IPC_NE_GET_2B((kal_uint8 *)(_tcp) + 2)

#define IPC_HDR_TCP_SET_DST_PORT(_tcp, _dst_port) \
        IPC_NE_SET_2B((kal_uint8 *)(_tcp) + 2, _dst_port)

#define IPC_HDR_TCP_EQ_DST_PORT(_tcp, _dst_port)    \
        (IPC_HDR_TCP_GET_DST_PORT(_tcp) == (_dst_port))

#define IPC_HDR_TCP_GET_SEQ_NUM(_tcp) \
        IPC_NE_GET_4B((kal_uint8 *)(_tcp) + 4)

#define IPC_HDR_TCP_SET_SEQ_NUM(_tcp, _seq_num) \
        IPC_NE_SET_4B((kal_uint8 *)(_tcp) + 4, _seq_num)

#define IPC_HDR_TCP_EQ_SEQ_NUM(_tcp, _seq_num)    \
        (IPC_HDR_TCP_GET_SEQ_NUM(_tcp) == (_seq_num))

#define IPC_HDR_TCP_GET_ACK_NUM(_tcp) \
        IPC_NE_GET_4B((kal_uint8 *)(_tcp) + 8)

#define IPC_HDR_TCP_SET_ACK_NUM(_tcp, _ack_num) \
        IPC_NE_SET_4B((kal_uint8 *)(_tcp) + 8, _ack_num)

#define IPC_HDR_TCP_EQ_ACK_NUM(_tcp, _ack_num)    \
        (IPC_HDR_TCP_GET_ACK_NUM(_tcp) == (_ack_num))

#define IPC_HDR_TCP_GET_OFFSET(_tcp) \
        ((IPC_NE_GET_1B((kal_uint8 *)(_tcp) + 12) & 0xF0) >> 2)

#define IPC_HDR_TCP_SET_OFFSET(_tcp, _offset) \
        do { \
            IPC_NE_SET_1B((kal_uint8 *)(_tcp) + 12, (IPC_NE_GET_1B((kal_uint8 *)(_tcp) + 12) & 0x0F) | ((((kal_uint8)(_offset)>>2)<<4) & 0xF0)); \
        } while (0)

#define IPC_HDR_TCP_GET_RESERVED(_tcp) \
        ((IPC_NE_GET_1B((kal_uint8 *)(_tcp) + 12) >> 1) & 0x07)

#define IPC_HDR_TCP_SET_RESERVED(_tcp, _reserved) \
        do { \
            IPC_NE_SET_1B((kal_uint8 *)(_tcp) + 12, (IPC_NE_GET_1B((kal_uint8 *)(_tcp) + 12) & 0xF1) | (((kal_uint8)(_reserved) << 1) & 0x0E)); \
        } while (0)

#define IPC_HDR_TCP_GET_FLAGS(_tcp) \
        (IPC_NE_GET_2B((kal_uint8 *)(_tcp) + 12) & 0x01FF)

#define IPC_HDR_TCP_SET_FLAGS(_tcp, _flags) \
        do { \
            IPC_NE_SET_2B((kal_uint8 *)(_tcp) + 12, (IPC_NE_GET_2B((kal_uint8 *)(_tcp) + 12) & 0xFE00) | ((_flags) & 0x01FF)); \
        } while (0)

#define IPC_HDR_TCP_GET_WINDOW(_tcp) \
        IPC_NE_GET_2B((kal_uint8 *)(_tcp) + 14)

#define IPC_HDR_TCP_SET_WINDOW(_tcp, _window) \
        IPC_NE_SET_2B((kal_uint8 *)(_tcp) + 14, _window)

#define IPC_HDR_TCP_GET_CHECKSUM(_tcp) \
        IPC_NE_GET_2B((kal_uint8 *)(_tcp) + 16)

#define IPC_HDR_TCP_SET_CHECKSUM(_tcp, _checksum) \
        IPC_NE_SET_2B((kal_uint8 *)(_tcp) + 16, _checksum)

#define IPC_HDR_TCP_GET_URGENT_PTR(_tcp) \
        IPC_NE_GET_2B((kal_uint8 *)(_tcp) + 18)

#define IPC_HDR_TCP_SET_URGENT_PTR(_tcp, _urp) \
        IPC_NE_SET_2B((kal_uint8 *)(_tcp) + 18, _urp)
/*
 * ICMP.
 */
#define IPC_HDR_ICMP_HEADER_SIZE     (8)

#define IPC_HDR_ICMP_GET_TYPE(_icmp) \
        IPC_NE_GET_1B(_icmp)

#define IPC_HDR_ICMP_SET_TYPE(_icmp, _type) \
        IPC_NE_SET_1B(_icmp, _type)

#define IPC_HDR_ICMP_EQ_TYPE(_icmp, _type)  \
        (IPC_HDR_ICMP_GET_TYPE(_icmp) == (_type))

#define IPC_HDR_ICMP_GET_CODE(_icmp) \
        IPC_NE_GET_1B((kal_uint8 *)(_icmp) + 1)

#define IPC_HDR_ICMP_SET_CODE(_icmp, _code) \
        IPC_NE_SET_1B((kal_uint8 *)(_icmp) + 1, (_code))

#define IPC_HDR_ICMP_EQ_CODE(_icmp, _code)  \
        (IPC_HDR_ICMP_GET_CODE(_icmp) == (_code))

#define IPC_HDR_ICMP_GET_CHECKSUM(_icmp) \
        IPC_NE_GET_2B((kal_uint8 *)(_icmp) + 2)

#define IPC_HDR_ICMP_SET_CHECKSUM(_icmp, _checksum) \
        IPC_NE_SET_2B((kal_uint8 *)(_icmp) + 2, _checksum)


/*
 * Ports.
 */
#define IPC_PORT_BOOTPS (67)
#define IPC_PORT_BOOTPC (68)

/*------------------------------------------------------------------------------
 * Public fucntions.
 *----------------------------------------------------------------------------*/
/*!
 * Allow HIF side module, such as ethercore or ppp, to register callback functions, 
 * callback context, and module id for a network interface.
 *
 * @param   config [IN] The information required to regerster a network interface.
 * @param   handle [OUT] Caller allocated space to store a handle to the network interface attached.
 *                       It returns a IPC_INVALID_HANDLE if failed.
 *
 * @return KAL_TRUE if successful, KAL_FALSE otherwise.
 */
kal_bool 
ipc_attach(
    ipc_conf_t             *config,
    ipc_handle_t           *handle);

/*!
 * Detach the network interface.
 *
 * @param   handle [IN] Handle to the network interface to detach.
 *
 * @return KAL_TRUE if successful, KAL_FALSE otherwise.
 */
kal_bool 
ipc_detach(
    ipc_handle_t           handle);

/*!
 * Send a list of IP datagrams to wireless network.
 *
 * @param   handle [IN] Handle to the network interface attached.
 * @param   ior [IN] It wraps up a set of uplink GPD to send. 
 *
 * @return KAL_TRUE if successful, KAL_FALSE otherwise.
 */
kal_bool 
ipc_uplink(
    ipc_handle_t            handle,
    ipc_io_request_t       *ior);

/*!
 * Retrieve index of a set of IPv4/IPv6 addresses.
 *
 * @param   handle [IN] Handle to the network interface attached.
 *
 * @return Non-negtive value as a valid index, netgative value for an invalid one (e.g. before session established.).
 */
kal_int32 
ipc_get_ip_id(
    ipc_handle_t            handle);

/*!
 * Force reloading buffers for the network interface to receive uplink traffic.
 *
 * @param   handle [IN] Handle to the network interface attached.
 */
void 
ipc_need_ul_reload(
    ipc_handle_t            handle);

/*!
 * Check if any network interfaces need uplink reload retry, 
 * if so, send an ILM to IPCORE to do uplink reload.
 */
void ipc_check_ul_reload_retry(void);

/*!
 * Manually notify the HIF network interface link/IP status changed. (This API does NOT change IP Core internal FSM !)
 *
 * @param   netif_id [IN] The network interface ID.
 * @param   ip_type [IN] Type of the PDN, IPC_IP_TYPE_IPV4, IPC_IP_TYPE_IPV6, or IPC_IP_TYPE_MIXED.
 * @param   link_update[IN] KAL_TRUE if an IP session is established/deactived and link status is changed. KAL_FALSE if an IP information is updated for an activated IP session.
 * @param   link_up [IN] (If link_update is KAL_TRUE) KAL_TRUE if an IP session is established, KAL_FALSE if an IP session is deactived ;
                                    (If link_update is KAL_FALSE) KAL_TRUE if new IP information is available, KAL_FALSE if original IP information is obsoleted
 */
void ipc_notify_link_change(kal_uint32 netif_id, kal_uint8 ip_type, kal_bool link_update, kal_bool is_up);

/*!
 * Install callback function and filtering rules for uplink traffic.
 *
 * @param   rules [IN] Rules to filter of uplink IP datagrams.
 * @param   callback_func [IN] Callback function for a uplink IP datagram matched the rules.
 * @param   callback_context [IN] Context to pass in the callback function.
 *
 * @return Zero or postive value as filter ID if registration succeeded, negative value if it failed.
 */
kal_int32 
ipc_register_ul_filter_cbk(
    ipc_filter_rules_t     *rules,
    ipc_filter_callback_t   callback_func,
    void                   *callback_context);

/*!
 * Install callback function and filtering rules for downlink traffic.
 *
 * @param   rules [IN] Rules to filter of downlink IP datagrams.
 * @param   callback_func [IN] Callback function for a downlink IP datagram matched the rules.
 * @param   callback_context [IN] Context to pass in the callback function.
 *
 * @return Zero or postive value as filter ID if registration succeeded, negative value if it failed.
 */
kal_int32 
ipc_register_dl_filter_cbk(
    ipc_filter_rules_t     *rules,
    ipc_filter_callback_t   callback_func,
    void                   *callback_context);

/*!
 * Install module ID and filtering rules for uplink traffic.
 *
 * @param   rules [IN] Rules to filter of uplink IP datagrams.
 * @param   callback_module [IN] Destination module of the MSG MSG_ID_IPCORE_UL_PACKET_FILTERED_REQ for a uplink IP datagram matched the rules.
 * @param   callback_context [IN] Context to pass in the callback function.
 *
 * @return Zero or postive value as filter ID if registration succeeded, negative value if it failed.
 */
kal_int32 
ipc_register_ul_filter_msg(
    ipc_filter_rules_t     *rules,
    module_type             callback_module,
    void                   *callback_context);

/*!
 * Install module ID and filtering rules for downlink traffic.
 *
 * @param   rules [IN] Rules to filter of downlink IP datagrams.
 * @param   callback_module [IN] Destination module of the MSG MSG_ID_IPCORE_DL_PACKET_FILTERED_REQ for a downlink IP datagram matched the rules.
 * @param   callback_context [IN] Context to pass in the callback function.
 *
 * @return Zero or postive value as filter ID if registration succeeded, negative value if it failed.
 */
kal_int32 
ipc_register_dl_filter_msg(
    ipc_filter_rules_t     *rules,
    module_type             callback_module,
    void                   *callback_context);

/*!
 * Install callback function and filtering rules for uplink traffic. (callback function with information as parameter)
 *
 * @param   rules [IN] Rules to filter of uplink IP datagrams.
 * @param   callback_func [IN] Callback function for a uplink IP datagram matched the rules (with information as parameter).
 * @param   callback_context [IN] Context to pass in the callback function.
 *
 * @return Zero or postive value as filter ID if registration succeeded, negative value if it failed.
 */
kal_int32 
ipc_register_ul_filter_with_info_cbk(
    ipc_filter_rules_t                  *rules,
    ipc_filter_with_info_callback_t     callback_func,
    void                                *callback_context);

/*!
 * Install callback function and filtering rules for downlink traffic. (callback function with information as parameter)
 *
 * @param   rules [IN] Rules to filter of downlink IP datagrams.
 * @param   callback_func [IN] Callback function for a downlink IP datagram matched the rules (with information as parameter).
 * @param   callback_context [IN] Context to pass in the callback function.
 *
 * @return Zero or postive value as filter ID if registration succeeded, negative value if it failed.
 */
kal_int32 
ipc_register_dl_filter_with_info_cbk(
    ipc_filter_rules_t                  *rules,
    ipc_filter_with_info_callback_t     callback_func,
    void                                *callback_context);

/*!
 * Install module ID and filtering rules for uplink traffic. (callback function with information as parameter)
 *
 * @param   rules [IN] Rules to filter of uplink IP datagrams.
 * @param   callback_module [IN] Destination module of the MSG MSG_ID_IPCORE_UL_PACKET_FILTERED_WITH_INFO_REQ for a uplink IP datagram matched the rules.
 * @param   callback_context [IN] Context to pass in the callback function.
 *
 * @return Zero or postive value as filter ID if registration succeeded, negative value if it failed.
 */
kal_int32 
ipc_register_ul_filter_with_info_msg(
    ipc_filter_rules_t     *rules,
    module_type             callback_module,
    void                   *callback_context);

/*!
 * Install module ID and filtering rules for downlink traffic. (callback function with information as parameter)
 *
 * @param   rules [IN] Rules to filter of downlink IP datagrams.
 * @param   callback_module [IN] Destination module of the MSG MSG_ID_IPCORE_DL_PACKET_FILTERED_WITH_INFO_REQ for a downlink IP datagram matched the rules.
 * @param   callback_context [IN] Context to pass in the callback function.
 *
 * @return Zero or postive value as filter ID if registration succeeded, negative value if it failed.
 */
kal_int32 
ipc_register_dl_filter_with_info_msg(
    ipc_filter_rules_t     *rules,
    module_type             callback_module,
    void                   *callback_context);

/*!
 * Uninstall the filter for uplink traffic.
 *
 * @param   filter_id [IN] filter ID to unregister.
 */
void ipc_deregister_ul_filter(kal_int32 filter_id);

/*!
 * Uninstall the filter for donwlink traffic.
 *
 * @param   filter_id [IN] filter ID to unregister.
 */
void ipc_deregister_dl_filter(kal_int32 filter_id);

/*!
 * Copy buffers in the GPD list to the buffer prepared by caller.
 *
 * @param   dst_buffer [OUT] Destination buffer to copy to, which is prepared by caller.
 * @param   dst_max_len [IN] Size of the destination buffer prepared by caller in bytes.
 * @param   dst_len_copied [OUT] Number of bytes copied to the destination buffer.
 * @param   src_head_gpd [IN] Head of the GPD list with source buffers to copy from.
 * @param   src_tail_gpd [IN] Tail of the GPD list with source buffers to copy from.
 *
 * @return  KAL_TRUE if succeeded, KAL_FALSE otherwise.
 */
kal_bool ipc_gpd_copy(kal_uint8 *dst_buffer, kal_uint32 dst_max_len, kal_uint32 *dst_len_copied, qbm_gpd *src_head_gpd, qbm_gpd *src_tail_gpd);

/*!
 * Send datagram in buffer or GPD list to the wireless netowrk and selectively fill L4(UDP) and IP header on each of them.
 *
 * @param   pkt [IN] Datagram or GPD list to sent.
 * @param   hdr [IN] UDP/IP header information which will be filled to sent packet(s). NULL pointer means "No packet modification is needed"
 * @param   ebi [IN] EBI/NSAPI.
 *
 * @return  KAL_TRUE if succeeded, KAL_FALSE otherwise.
 */
kal_bool 
ipc_send_ul_pkt (
    ipc_pkt_t   *pkt,
    ipc_hdr_t   *hdr,
    kal_uint8   ebi);

/*!
 * Send datagram in buffer or GPD list to the wireless netowrk and selectively fill L4(UDP) and IP header on each of them.
 *
 * @param   pkt [IN] Datagram or GPD list to sent.
 * @param   hdr [IN] UDP/IP header information which will be filled to sent packet(s). NULL pointer means "No packet modification is needed"
 * @param   pdn [IN] PDN ID
 * @param   ip_type [IN] Type of IP datagrams, see IPC_IP_TYPE_XXX defined for valid values. Note that only one of IPv4/IPv6 can be selected and MIX type is NOT allowed.

 *
 * @return  KAL_TRUE if succeeded, KAL_FALSE otherwise.
 */
kal_bool
ipc_send_ul_pkt_by_pdn (
    ipc_pkt_t   *pkt,
    ipc_hdr_t   *hdr,
    kal_uint8   pdn,
    kal_uint8   ip_type);

/*!
 * Send datagram in buffer or GPD list to the netowrk interface and selectively fill L4(UDP) and IP header on each of them.
 *
 * @param   pkt [IN] Datagram or GPD list to sent.
 * @param   hdr [IN] UDP/IP header information which will be filled to sent packet(s). NULL pointer means "No packet modification is needed"
 * @param   netif_id [IN] Network interface ID.
 *
 * @return  KAL_TRUE if succeeded, KAL_FALSE otherwise.
 */
kal_bool
ipc_send_dl_pkt(
    ipc_pkt_t   *pkt,
    ipc_hdr_t   *hdr,
    kal_uint32  netif_id);

/*!
 * Register a notification.
 *
 * @param   callback_func [IN] Callback function pointer.
 * @param   callback_context [IN] Context to pass in the callback function.
 *
 * @return Zero or positive value as notification ID if registration succeeded, negative value otherwise.
 */
kal_int32 ipc_register_ntfy(
    ipc_ntfy_callback_t callback_func,
    void                *callback_context);

/*!
 * Uninstall the registered notification.
 *
 * @param   ntfy_id [IN] notification ID gotten from ipc_register_ntfy() to uninstall.
 */
void ipc_deregister_ntfy(kal_int32 ntfy_id);

/*!
 * Register link up indication handler
 *
 * @param   module_id [IN]  Module ID to handle ILM MSG_ID_IPCORE_LINK_UP_IND.
 *
 * @return  KAL_TRUE if succeeded, KAL_FALSE otherwise.
 */
kal_bool ipc_register_link_up_ind_handler(module_type module_id);

/*!
 * Uninstall the registered link up indication handler
 */
void ipc_deregister_link_up_ind_handler(void);

/*!
 * Register IP up indication handler
 *
 * @param   module_id [IN]  Module ID to handle ILM MSG_ID_IPCORE_IP_UP_IND.
 *
 * @return  KAL_TRUE if succeeded, KAL_FALSE otherwise.
 */
kal_bool ipc_register_ip_up_ind_handler(module_type module_id);

/*!
 * Uninstall the registered link up indication handler
 */
void ipc_deregister_ip_up_ind_handler(void);

#endif /* __INC_IPC_API_H */
