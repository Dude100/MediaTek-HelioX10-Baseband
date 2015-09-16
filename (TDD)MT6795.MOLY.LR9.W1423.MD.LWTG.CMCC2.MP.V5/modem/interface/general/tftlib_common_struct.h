/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   tftlib_common_struct.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   TFT library common structure
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * [TFTLIB] Check-in related changes
 *
 * removed!
 * removed!
 * [MT6290][TFTLIB] update TFT parameter list with new structure
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * [Joe] TFTLIB part is check in done.
 ****************************************************************************/


#ifndef TFTLIB_COMMON_STRUCT_H_
#define TFTLIB_COMMON_STRUCT_H_


#include "kal_general_types.h"
#include "tftlib_common_enum.h"


/*struct declaration */


/* IPv4 remote address and subnet mask struct (WORD(4-byte) array, used by UPCM only) */      
typedef struct
{
    kal_uint32 addr;
    kal_uint32 mask;
}remote_v4addr_struct;


/* IPv6 remote address and subnet mask struct (WORD(4-byte) array, used by UPCM only) */
typedef struct 
{
    kal_uint32 addr[4]; 
    kal_uint32 mask[4];
}remote_v6addr_struct;


/* Packet filter struct for SM/ESM, TCM, L4C, & UPCM */
typedef struct 
{
    pf_own_entity_enum  pf_own_entity;  // Indicate UE or NW owns this PF            
    kal_uint8           id;             // Packet filter index
    kal_uint8           precedence;     // Packet filter evaluation precedence index
    pf_direction_enum   direction;      // Direction of the packet filter

    kal_uint32          bitmap;         // Used to indicate which of the following field exist
    
    union
    {
        remote_v4addr_struct v4;
        remote_v6addr_struct v6;
    }remote_addr;                       // Remote address and subnet mask (WORD(4-byte) array, used by UPCM only)

    kal_uint8           remote_addr_and_mask[MAX_REMOTE_ADDR_AND_MASK_LEN]; /* ----------------- Remote address and subnet mask (byte array) ----------------*
                                                                             *                                                                               *
                                                                             * IPv4: addr =  0 ~  3                                                          *    
                                                                             *       mask =  4 ~  7                                                          *
                                                                             * <NOTE1: Length of IPv4 addr + mask = IPV4_REMOTE_ADDR_AND_MASK_LEN(8)>        *
                                                                             *                                                                               *
                                                                             * IPv6: addr =  0 ~ 15                                                          *
                                                                             *       mask = 16 ~ 31                                                          *
                                                                             * <NOTE2: Length of IPv6 addr + mask = IPV6_REMOTE_ADDR_AND_MASK_LEN(32)>       *
                                                                             *                                                                               *
                                                                             *                                                                               *
                                                                             * <NOTE3: MAX_REMOTE_ADDR_AND_MASK_LEN is set as IPV6_REMOTE_ADDR_AND_MASK_LEN> *
                                                                             *                                                                               *
                                                                             * ------------------------------------------------------------------------------*
                                                                             */
                                                                             
    kal_uint8           protocol_nxt_hdr;   // Protocol number (IPv4) / Next header (IPv6)

    kal_uint16          local_port_low;     // Single local port / Local port range (low)
    kal_uint16          local_port_high;    //       (N/A)       / Local port range (high)
    
    kal_uint16          remote_port_low;    // Single remote port / Remote port range (low)
    kal_uint16          remote_port_high;   //       (N/A)        / Remote port range (high)

    kal_uint32          spi;                // IPsec security parameter index
    
    kal_uint8           tos;                // Type of service (IPv4) / Traffic class (IPv6)
    kal_uint8           tos_msk;            // Type of service mask (IPv4) / Traffic class mask (IPv6)
    
    kal_uint32          flow_label;         // Flow label (IPv6)
}pkt_filter_struct;


/* PDP/EPS bearer context deactivation list for SM/ESM */
typedef struct {
    kal_uint8   deact_num;                              // Number of deactivated bearer due to packet filter conflict
    kal_uint8   deact_list[TFTLIB_MAX_BEARER_CTXT_NUM]; // Deactivated bearer context list
} tft_deact_bearer_list_struct;


/* Packet filter action struct for UPCM */
typedef struct 
{
    kal_uint8           bearer_id;  // EPS bearer ID/NSAPI where the packet filter belongs to
    pkt_filter_act_enum action;     // Update action for the packet filter
    pkt_filter_struct   pkt_filter; // Content of the new packet filter
} pkt_filter_act_struct;


/* Packet filter action list struct for TCM, UPCM */
typedef struct 
{
    kal_uint8               pkt_filter_num;                             // Number of packet filters to be update in the following list
    pkt_filter_act_struct   pkt_filter_list[MAX_PACKET_FILTER_NUM * 2]; // List of packet filters to be update and each with specific EPS bearer ID/NSAPI & action
} pkt_filter_act_list_struct;


/* TFT PDU struct for SM/ESM, TCM */
typedef struct {
    kal_uint8 length;   // length of the TFT raw data
    kal_uint8 *data;    // TFT raw data
} tft_pdu_struct;


typedef struct {
    kal_uint8   auth_token_len;                                             // length of authorization token
    kal_uint8   auth_token[MAX_AUTHORIZATION_TOKEN_LEN];                    // authorization token
    kal_uint8   flow_id_num;                                                // number of flow identifiers
    kal_uint8   flow_id_list[MAX_FLOW_IDENTIFIER_NUM][FLOW_IDENTIFIER_LEN]; /* flow identifier list 
                                                                             * (NOTE: an authtoken can follow one or more flow identifiers,
                                                                             *        and each flow identifier is FLOW_IDENTIFIER_LEN (4 byte) long)
                                                                             */
} tft_authtoken_flowid_struct;


typedef struct {
    kal_uint8   linked_pf_id_num;                           // Number of linked packet filter IDs carried in linked_pf_id_list[]
    kal_uint8   linked_pf_id_list[MAX_PACKET_FILTER_NUM];   /* Linked packet filter ID list
                                                             * (NOTE1: Used to indicate to NW the change for which service applies to)
                                                             * (NOTE2: Will appear when, 1. GBR changes, 2. TFT operation = 'Add packet filters to existing TFT')
                                                             */
                                                             
    kal_uint8                       authtoken_flowid_num;                            // Number of authtoken_flowid group in authtoken_flowid_list[]
    tft_authtoken_flowid_struct     authtoken_flowid_list[MAX_AUTHTOKEN_FLOWID_NUM]; // Authorization and flow identifier group list

} tft_parameter_list_struct;

/* TFT struct for SM/ESM, TCM, L4C */
typedef struct {
    kal_uint8                   cid;                                    // context id
    kal_bool                    est_wo_tft;                             // indicate whether TFT is established without TFT
    tft_operation_enum          tft_opcode;                             // TFT operation code
    kal_bool                    ebit;                                   // Indicate whether parameter list exists
    kal_uint8                   pf_num;                                 // Number of packet filter carried in pf_list[]
    pkt_filter_struct           pf_list[MAX_PACKET_FILTER_NUM];         // Packet filter list
    tft_parameter_list_struct   parameter_list;                         // Parameter list
    
} tft_info_struct;



#endif /* TFTLIB_COMMON_STRUCT_H_ */
