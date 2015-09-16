/*!
 *  @file nmu.h
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
 *  This file provides interface of nmu ( network management unit )
 */

#ifndef _NMU_H
#define _NMU_H


/*!
 *  @brief nmu_entry_e enumberate all information entry support in nmu
 */
typedef enum _nmu_entry_e {
    NMU_MTU_SIZE,           /* Maximal transmission unit in bytes.
                               Default value is 1500. */
    NMU_UL_SPEED,           /* Uplink speed in unit of bps. */
    NMU_DL_SPEED,           /* Downlink speed in unit of bps. */

    NMU_ETH0_UP,
    NMU_ETH0_HOST_MAC,
    NMU_ETH0_GATEWAY_MAC,
    NMU_ETH0_TX_PKT_CNT,
    NMU_ETH0_RX_PKT_CNT,
    NMU_ETH0_TX_BYTE_CNT,
    NMU_ETH0_RX_BYTE_CNT,
    NMU_ETH0_TX_DROP_PKT_CNT,
    NMU_ETH0_RX_DROP_PKT_CNT,

    NMU_ETH1_UP,
    NMU_ETH1_HOST_MAC,
    NMU_ETH1_GATEWAY_MAC,
    NMU_ETH1_TX_PKT_CNT,
    NMU_ETH1_RX_PKT_CNT,
    NMU_ETH1_TX_BYTE_CNT,
    NMU_ETH1_RX_BYTE_CNT,
    NMU_ETH1_TX_DROP_PKT_CNT,
    NMU_ETH1_RX_DROP_PKT_CNT,

    NMU_ETH2_UP,
    NMU_ETH2_HOST_MAC,
    NMU_ETH2_GATEWAY_MAC,
    NMU_ETH2_TX_PKT_CNT,
    NMU_ETH2_RX_PKT_CNT,
    NMU_ETH2_TX_BYTE_CNT,
    NMU_ETH2_RX_BYTE_CNT,
    NMU_ETH2_TX_DROP_PKT_CNT,
    NMU_ETH2_RX_DROP_PKT_CNT,

    NMU_ETH3_UP,
    NMU_ETH3_HOST_MAC,
    NMU_ETH3_GATEWAY_MAC,
    NMU_ETH3_TX_PKT_CNT,
    NMU_ETH3_RX_PKT_CNT,
    NMU_ETH3_TX_BYTE_CNT,
    NMU_ETH3_RX_BYTE_CNT,
    NMU_ETH3_TX_DROP_PKT_CNT,
    NMU_ETH3_RX_DROP_PKT_CNT,

    NMU_IP0_UP,
    NMU_IP0_ADDR,
    NMU_IP0_MASK,
    NMU_IP0_GATEWAY,
    NMU_IP0_MTU_SIZE,
    NMU_IP0_DNS_NUM,
    NMU_IP0_DNS1,
    NMU_IP0_DNS2,

    NMU_IP0_IP6_UP,
    NMU_IP0_IP6_PREFIX,
    NMU_IP0_IP6_PREFIX_LEN,
    NMU_IP0_IP6_IID,
    NMU_IP0_IP6_IID_LEN,
    NMU_IP0_IP6_MTU_SIZE,
    NMU_IP0_IP6_DNS_NUM,
    NMU_IP0_IP6_DNS1,
    NMU_IP0_IP6_DNS2,

    NMU_IP1_UP,
    NMU_IP1_ADDR,
    NMU_IP1_MASK,
    NMU_IP1_GATEWAY,
    NMU_IP1_MTU_SIZE,
    NMU_IP1_DNS_NUM,
    NMU_IP1_DNS1,
    NMU_IP1_DNS2,

    NMU_IP1_IP6_UP,
    NMU_IP1_IP6_PREFIX,
    NMU_IP1_IP6_PREFIX_LEN,
    NMU_IP1_IP6_IID,
    NMU_IP1_IP6_IID_LEN,
    NMU_IP1_IP6_MTU_SIZE,
    NMU_IP1_IP6_DNS_NUM,
    NMU_IP1_IP6_DNS1,
    NMU_IP1_IP6_DNS2,

    NMU_IP2_UP,
    NMU_IP2_ADDR,
    NMU_IP2_MASK,
    NMU_IP2_GATEWAY,
    NMU_IP2_MTU_SIZE,
    NMU_IP2_DNS_NUM,
    NMU_IP2_DNS1,
    NMU_IP2_DNS2,

    NMU_IP2_IP6_UP,
    NMU_IP2_IP6_PREFIX,
    NMU_IP2_IP6_PREFIX_LEN,
    NMU_IP2_IP6_IID,
    NMU_IP2_IP6_IID_LEN,
    NMU_IP2_IP6_MTU_SIZE,
    NMU_IP2_IP6_DNS_NUM,
    NMU_IP2_IP6_DNS1,
    NMU_IP2_IP6_DNS2,

    NMU_IP3_UP,
    NMU_IP3_ADDR,
    NMU_IP3_MASK,
    NMU_IP3_GATEWAY,
    NMU_IP3_MTU_SIZE,
    NMU_IP3_DNS_NUM,
    NMU_IP3_DNS1,
    NMU_IP3_DNS2,

    NMU_IP3_IP6_UP,
    NMU_IP3_IP6_PREFIX,
    NMU_IP3_IP6_PREFIX_LEN,
    NMU_IP3_IP6_IID,
    NMU_IP3_IP6_IID_LEN,
    NMU_IP3_IP6_MTU_SIZE,
    NMU_IP3_IP6_DNS_NUM,
    NMU_IP3_IP6_DNS1,
    NMU_IP3_IP6_DNS2,

    /* always be the last line */
    NMU_MAX_ENTRY,
} nmu_entry_e;

typedef kal_uint8                   nmu_eth_addr_t[6];
typedef kal_uint32                  nmu_in_addr_t;
typedef kal_uint32                  nmu_in6_addr_t[4];
typedef kal_uint8                   nmu_status_t;
typedef kal_uint32                  nmu_stat_t;

/*!
 *  @brief nmu_nvram_table_t is a collection of network information stored
 *                           in nvram
 */
typedef struct _nmu_nvram_table {
    kal_uint32              make_compiler_happy;
    nmu_eth_addr_t          eth0_host_mac;

} nmu_nvram_table_t;

/*!
 *  @brief  nmu init function
 */
void nmu_init(void);


/*!
 *  @brief  write entry value to nmu
 *  @param  entry entry enum value
 *  @param  len   the length to write
 *  @param  data  pointer to the start address of entry data
 *  @return KAL_TRUE if success, KAL_FALSE if entry not exist, or Read Only
 *          attribute is set
 */
kal_bool nmu_set_property(nmu_entry_e entry, kal_uint32 len, void* data);


/*!
 *  @brief  read entry value from nmu
 *  @param  entry entry enum value
 *  @param  len   the length to read
 *  @param  data  pointer to the start address of entry data
 *  @return KAL_TRUE if success, KAL_FALSE if entry not exist, or
 *          data buffer is not big enough
 */
kal_bool nmu_get_property(nmu_entry_e entry, kal_uint32 len, void* data);


#endif  // _NMU_H

