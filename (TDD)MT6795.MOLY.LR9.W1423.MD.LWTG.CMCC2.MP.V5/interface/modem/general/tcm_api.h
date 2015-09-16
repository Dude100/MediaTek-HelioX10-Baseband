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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * TCM_API.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file provides tcm functions for other modules to call
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _TCM_API_H
#define _TCM_API_H

//------------------------------ suggest Add ------------------------------
//#include "kal_non_specific_general_types.h"
#include "kal_general_types.h"
#include "mcd_l3_inc_gprs_struct.h"


/* Poying: Moved from tcm_qos_api.h */
typedef enum
{
    TCM_REQ_QOS = 0,
    TCM_MIN_QOS,
    TCM_NEG_QOS
} tcm_qos_type_enum;

/* Check tcm_qos_api.c for implementations. */
void tcm_qos_R99_to_R98( qos_struct *s, tcm_qos_type_enum qos_type );


/* Poying: Move to comply with MSBB. */
/* Check l4c2tcm_func.c for implementations. */
kal_bool l4ctcm_decode_sdu_size(kal_uint16 val, kal_uint16 *size_ptr);

#ifdef __REL6__
kal_bool l4ctcm_encode_bit_rate(kal_uint32 rate, kal_uint16 *val_ptr);
#else // #ifdef __REL6__
kal_bool l4ctcm_encode_bit_rate(kal_uint16 rate, kal_uint16 *val_ptr);
#endif // ~ #ifdef __REL6__

#ifdef __REL6__
kal_bool l4ctcm_decode_bit_rate(kal_uint16 val, kal_uint32 *rate_ptr);
#else // #ifdef __REL6__
kal_bool l4ctcm_decode_bit_rate(kal_uint16 val, kal_uint16 *rate_ptr);
#endif // ~ #ifdef __REL6__

kal_bool l4ctcm_decode_transfer_delay(kal_uint16 val, kal_uint16 *delay_ptr);


/* Check tcm_api.c for implementations. */
kal_bool tcm_pdp_decode_qos_transfer_delay(kal_uint16 val, kal_uint16 *delay_ptr);
kal_bool tcm_pdp_decode_qos_bit_rate(kal_uint16 val, kal_uint32 *rate_ptr);

/* 
 * Data account
 */
typedef struct
{
    // must align with qos_struct
    // Please see 3GPP TS24.008 Table 10.5.156 Quality of service information element for detail explaination

    kal_uint8 qos_length;   /* QOS identifer bit, this value must be 16, or the GPRS bearer will not accept */
    kal_uint8 unused1;      /* Unused Bit */
    
    kal_uint8 delay_class;
    /* 
      * Delay Class 
      * 001 Delay Class 1 
      * 010 Delay Class 2
      * 011 Delay Class 3
      * 100 Delay Class 4 (best effort)
      * ...
      */
    
    kal_uint8 reliability_class;
    /* 
      * Reliability Class 
      * 001 Interpreted as 010
      * 010 UnACK GTP, ACK LLC, ACK RLC, Protected Data
      * 011 UnACK GTP, UnACK LLC, ACK RLC, Protected Data
      * 100 UnACK GTP, UnACK LLC, UnACK RLC, Prottected Data
      * 101 UnACK GTP, UnACK LLC, UnACK RLC, Unprotected Data
      * ...
      */
    
    kal_uint8 peak_throughput;
    /* 
      * Peak Throughput
      * 0001 Up to 1000 octet/s
      * 0010 Up to 2000 octet/s
      * 0011 Up to 4000 octet/s
      * 0100 Up to 8000 octet/s
      * 0101 Up to 16000 octet/s
      * 0110 Up to 32000 octet/s
      * 0111 Up to 64000 octet/s
      * 1000 Up to 128000 octet/s
      * 1001 Up to 256000 octet/s
      * ...
      */
    
    kal_uint8 unused2;      /* Unused Bit */
    
    kal_uint8 precedence_class;
    /* 
      * Precedence Class
      * 001 High Priority
      * 010 Normal Priority
      * 011 Low Priority
      * ...
      */
    
    kal_uint8 unused3;      /* Unused Bit */
    
    kal_uint8 mean_throughput;
    /* 
      * Mean Throughput
      * 00001 Up to 100 octet/h
      * 00010 Up to 200 octet/h
      * 00011 Up to 500 octet/h
      * ...
      */
    
    kal_uint8 traffic_class;
    /* 
      * Traffic Class
      * 001 Conversational class
      * 010 Streaming class
      * 011 Interactive class
      * 100 Background class
      * ...
      */
    
    kal_uint8 delivery_order;
    /* 
      * Delivery Order
      * 01 With delivery order (yes)
      * 10 Without delivery order (no)
      * ...
      */
    
    kal_uint8 delivery_of_err_sdu;
    /* 
      * Delivery of erroneous SDUs
      * 001 No detect (-)
      * 010 Erroneous SDUs are delivered (yes)
      * 011 Erroneous SDUs are not delivered (no)
      * ...
      */
    
    kal_uint8 max_sdu_size;
    /* 
      * Maximum SDU Size
      * ...
      * 10010111 1502 octets
      * 10011000 1510 octets
      * 10011001 1520 octets
      * ...
      */

    kal_uint8 max_bitrate_up_lnk; // see 24.008 Table 10.5.156
    
    kal_uint8 max_bitrate_down_lnk; // see 24.008 Table 10.5.156
    
    kal_uint8 residual_bit_err_rate;
    /* 
      * Residual Bit Error Rate
      * 0001 5*10^-2
      * 0010 1*10^-2
      * 0011 5*10^-3
      * 0100 4*10^-3      
      * 0101 1*10^-3      
      * 0110 1*10^-4      
      * ...
      */
    
    kal_uint8 sdu_err_ratio;
    /* 
      * SDU Error Ratio
      * 0001 1*10^-2
      * 0010 7*10^-3
      * 0011 1*10^-3
      * 0100 1*10^-4     
      * 0101 1*10^-5      
      * 0110 1*10^-6      
      * ...
      */
    
    kal_uint8 transfer_delay; // see 24.008 Table 10.5.156
    
    kal_uint8 traffic_hndl_priority;
    /* 
      * Traffic Handling Priority
      * 01 Priority level 1
      * 10 Priority level 2
      * 11 Priority level 3
      * ...
      */
    
    kal_uint8 guarntd_bit_rate_up_lnk; // see 24.008 Table 10.5.156
    
    kal_uint8 guarntd_bit_rate_down_lnk; // see 24.008 Table 10.5.156
    
    kal_uint8 unused4; /* Unused Bit */
    
    kal_uint8 signalling_indication;
    /* 
      * Signaling Indication
      * 0 Not optimised for signalling traffic
      * 1 Optimised for signalling traffic
      * ...
      */
    
    kal_uint8 source_statistics_descriptor;
    /* 
      * Source Statistics Descriptor
      * 0000 Unknown
      * 0001 Speech
      * ...
      */
    
    kal_uint8 ext_max_bitrate_down_lnk; // see 24.008 Table 10.5.156
    
    kal_uint8 ext_guarntd_bit_rate_down_lnk; // see 24.008 Table 10.5.156
    
    kal_uint8 ext_max_bitrate_up_lnk; // see 24.008 Table 10.5.156
    
    kal_uint8 ext_guarntd_bit_rate_up_lnk; // see 24.008 Table 10.5.156
} nvram_editor_qos_struct;

//mtk04121
typedef struct {
    kal_uint8 qci;
    kal_uint8 unused1;
    kal_uint8 unused2;
    kal_uint8 unused3;
    kal_uint8 max_bitrate_up_lnk; // see 24.008 Table 10.5.156
    kal_uint8 max_bitrate_down_lnk; // see 24.008 Table 10.5.156
    kal_uint8 guarntd_bit_rate_up_lnk; // see 24.008 Table 10.5.156
    kal_uint8 guarntd_bit_rate_down_lnk; // see 24.008 Table 10.5.156
    kal_uint8 ext_max_bitrate_up_lnk; // see 24.008 Table 10.5.156
    kal_uint8 ext_max_bitrate_down_lnk; // see 24.008 Table 10.5.156
    kal_uint8 ext_guarntd_bit_rate_up_lnk; // see 24.008 Table 10.5.156
    kal_uint8 ext_guarntd_bit_rate_down_lnk; // see 24.008 Table 10.5.156
    kal_uint8 ext2_max_bitrate_up_lnk;
    kal_uint8 ext2_max_bitrate_down_lnk;
    kal_uint8 ext2_guarntd_bit_rate_up_lnk;
    kal_uint8 ext2_guarntd_bit_rate_down_lnk;
} nvram_editor_eps_qos_struct;


/* Poying: MSBB (MAUI_03028371). */
typedef struct
{
    nvram_editor_qos_struct req_qos;
    nvram_editor_qos_struct min_qos;
} tcm_ps_qos_profile_struct;


#endif // ~ #ifndef _TCM_API_H
