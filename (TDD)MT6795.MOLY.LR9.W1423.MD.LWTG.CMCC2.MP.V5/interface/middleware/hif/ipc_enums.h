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
 *   ipc_enums.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   IP Core public enumeration definition.
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __INC_IPC_ENUMS_H
#define __INC_IPC_ENUMS_H

/*------------------------------------------------------------------------------
 * Data structure defintion.
 *----------------------------------------------------------------------------*/
#define IPC_IP_TYPE_MIXED           0
#define IPC_IP_TYPE_IPV4            1
#define IPC_IP_TYPE_IPV6            2

/*
 * Network interface configuration
 */
#define IPC_F_DHCP4C                0x00000001 /* DHCPv4 Client */
#define IPC_F_LATENCY_CONCERN       0x00010000 /* Latency Concern Module */

#define IPC_INVALID_HANDLE          NULL

/*
 * Filter feature option
 */
#define IPC_FILTER_FEATURE_WC       (0x01 << 0)     /* Wild card filter: report matched to all packets */
#define IPC_FILTER_FEATURE_BWM      (0x01 << 1)     /* Bypass when matched filter: bypass the matched packets */

/*
 * Filter rule
 */
#define IPC_FILTER_BY_PROTOCOL      (0x0001 << 0)
#define IPC_FILTER_BY_SRC_PORT      (0x0001 << 1)
#define IPC_FILTER_BY_DST_PORT      (0x0001 << 2)
#define IPC_FILTER_BY_SRC_IPV4      (0x0001 << 3)
#define IPC_FILTER_BY_DST_IPV4      (0x0001 << 4)
#define IPC_FILTER_BY_SRC_IPV6      (0x0001 << 5)
#define IPC_FILTER_BY_DST_IPV6      (0x0001 << 6)
#define IPC_FILTER_BY_ICMPV4_TYPE   (0x0001 << 7)
#define IPC_FILTER_BY_ICMPV6_TYPE   (0x0001 << 8)
#define IPC_FILTER_BY_EBI           (0x0001 << 9)
#define IPC_FILTER_BY_PDN_ID        (0x0001 << 10)
#define IPC_FILTER_BY_NETIF_ID      (0x0001 << 11)

/*
 * Network interface ID.
 */
#define IPC_NETIF_ID_CCMNI_BEGIN      0x00000000
#define IPC_NETIF_ID_CCMNI_END        0x000000ff
#define IPC_NETIF_ID_ETH_BEGIN        0x00000100
#define IPC_NETIF_ID_ETH_END          0x000001ff
#define IPC_NETIF_ID_MBIM_BEGIN       0x00000200
#define IPC_NETIF_ID_MBIM_END         0x000002ff
#define IPC_NETIF_ID_PPP_BEGIN        0x00000300
#define IPC_NETIF_ID_PPP_END          0x000003ff

#endif /* __INC_IPC_ENUMS_H */
