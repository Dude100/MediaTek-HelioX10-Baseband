/*!
 *  @file nmu_util.h
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
 *  This file provides utility interface of nmu ( network management unit )
 */

#ifndef _NMU_UTIL_H
#define _NMU_UTIL_H


/*!
 *  @brief  set ethernet interface up
 *  @param  eth_id ethernet interface id
 */
void nmu_set_eth_up(kal_uint8 eth_id);


/*
 *  @brief  set ethernet interface down
 *  @param  eth_id ethernet interface id
 */
void nmu_set_eth_down(kal_uint8 eth_id);


/*
 *  @brief  check if ethernet interface is up or not
 *  @param  eth_id ethernet interface id
 *  @return KAL_TRUE if ethernet interface is up, KAL_FALSE if it's down
 *          attribute is set
 */
kal_bool nmu_check_eth_up(kal_uint8 eth_id);


/*
 *  @brief  set host mac address of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  mac_address mac address to be written
 */
void nmu_set_host_mac(kal_uint8 eth_id, void* mac_address);


/*
 *  @brief  get host mac address of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  mac_address mac address to be read
 */
void nmu_get_host_mac(kal_uint8 eth_id, void* mac_address);


/*
 *  @brief  set gateway mac address of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  mac_address mac address to be written
 */
void nmu_set_gateway_mac(kal_uint8 eth_id, void* mac_address);


/*
 *  @brief  get gateway mac address of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  mac_address mac address to be read
 */
void nmu_get_gateway_mac(kal_uint8 eth_id, void* mac_address);


/*
 *  @brief  set transmit packet counts of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  value value to be written
 */
void nmu_set_eth_tx_pkt_cnt(kal_uint8 eth_id, kal_uint32 value);


/*
 *  @brief  add transmit packet counts of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  value value to be added
 */
void nmu_add_eth_tx_pkt_cnt(kal_uint8 eth_id, kal_uint32 value);


/*
 *  @brief  get transmit packet counts of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  value value to be read
 */
void nmu_get_eth_tx_pkt_cnt(kal_uint8 eth_id, kal_uint32* value);


/*
 *  @brief  set receive packet counts of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  value value to be written
 */
void nmu_set_eth_rx_pkt_cnt(kal_uint8 eth_id, kal_uint32 value);


/*
 *  @brief  add receive packet counts of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  value value to be added
 */
void nmu_add_eth_rx_pkt_cnt(kal_uint8 eth_id, kal_uint32 value);


/*
 *  @brief  get receive packet counts of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  value value to be read
 */
void nmu_get_eth_rx_pkt_cnt(kal_uint8 eth_id, kal_uint32* value);


/*
 *  @brief  set transmit packet bytes of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  value value to be written
 */
void nmu_set_eth_tx_byte_cnt(kal_uint8 eth_id, kal_uint32 value);


/*
 *  @brief  add transmit packet bytes of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  value value to be added
 */
void nmu_add_eth_tx_byte_cnt(kal_uint8 eth_id, kal_uint32 value);


/*
 *  @brief  get transmit packet bytes of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  value value to be read
 */
void nmu_get_eth_tx_byte_cnt(kal_uint8 eth_id, kal_uint32* value);


/*
 *  @brief  set receive packet bytes of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  value value to be written
 */
void nmu_set_eth_rx_byte_cnt(kal_uint8 eth_id, kal_uint32 value);


/*
 *  @brief  add receive packet bytes of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  value value to be added
 */
void nmu_add_eth_rx_byte_cnt(kal_uint8 eth_id, kal_uint32 value);


/*
 *  @brief  get receive packet bytes of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  value value to be read
 */
void nmu_get_eth_rx_byte_cnt(kal_uint8 eth_id, kal_uint32* value);


/*
 *  @brief  set transmit dropped packet counts of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  value value to be written
 */
void nmu_set_eth_tx_drop_pkt_cnt(kal_uint8 eth_id, kal_uint32 value);


/*
 *  @brief  add transmit dropped packet counts of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  value value to be added
 */
void nmu_add_eth_tx_drop_pkt_cnt(kal_uint8 eth_id, kal_uint32 value);


/*
 *  @brief  get transmit dropped packet counts of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  value value to be read
 */
void nmu_get_eth_tx_drop_pkt_cnt(kal_uint8 eth_id, kal_uint32* value);


/*
 *  @brief  set receive dropped packet counts of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  value value to be written
 */
void nmu_set_eth_rx_drop_pkt_cnt(kal_uint8 eth_id, kal_uint32 value);


/*
 *  @brief  add receive dropped packet counts of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  value value to be added
 */
void nmu_add_eth_rx_drop_pkt_cnt(kal_uint8 eth_id, kal_uint32 value);


/*
 *  @brief  get receive dropped packet counts of ethernet interface
 *  @param  eth_id ethernet interface id
 *  @param  value value to be read
 */
void nmu_get_eth_rx_drop_pkt_cnt(kal_uint8 eth_id, kal_uint32* value);


/*
 *  @brief  set ipv4 instance IPv4 up
 *  @param  ip_id ip instance id
 */
void nmu_set_ip4_up(kal_uint8 ip_id);


/*
 *  @brief  set ip instance IPv4 down
 *  @param  ip_id ip instance id
 */
void nmu_set_ip4_down(kal_uint8 ip_id);


/*
 *  @brief  check ip instance IPv4 is up or not
 *  @param  ip_id ip instance id
 *  @return KAL_TRUE if IPv4 is up, KAL_FALSE if not
 */
kal_bool nmu_check_ip4_up(kal_uint8 ip_id);


/*
 *  @brief  set IPv4 address of ip instance
 *  @param  ip_id ip instance id
 *  @param  ip_address IPv4 address to be written
 */
void nmu_set_ip4_ip(kal_uint8 ip_id, void* ip_address);


/*
 *  @brief  get IPv4 address of ip instance
 *  @param  ip_id ip instance id
 *  @param  ip_address IPv4 address to be read
 */
void nmu_get_ip4_ip(kal_uint8 ip_id, void* ip_address);


/*
 *  @brief  set IPv4 netmask of ip instance
 *  @param  ip_id ip instance id
 *  @param  mask IPv4 netmask to be written
 */
void nmu_set_ip4_mask(kal_uint8 ip_id, void* mask);


/*
 *  @brief  set IPv4 netmask of ip instance
 *  @param  ip_id ip instance id
 *  @param  mask IPv4 netmask to be written
 */
void nmu_get_ip4_mask(kal_uint8 ip_id, void* mask);


/*
 *  @brief  set IPv4 gateway address of ip instance
 *  @param  ip_id ip instance id
 *  @param  gateway IPv4 address to be written
 */
void nmu_set_ip4_gateway(kal_uint8 ip_id, void* gateway);


/*
 *  @brief  get IPv4 gateway address of ip instance
 *  @param  ip_id ip instance id
 *  @param  gateway IPv4 address to be read
 */
void nmu_get_ip4_gateway(kal_uint8 ip_id, void* gateway);


/*
 *  @brief  set IPv4 mtu size of ip instance
 *  @param  ip_id ip instance id
 *  @param  mtu_size mtu size to be written
 */
void nmu_set_ip4_mtu_size(kal_uint8 ip_id, kal_uint16 mtu_size);


/*
 *  @brief  get IPv4 mtu size of ip instance
 *  @param  ip_id ip instance id
 *  @param  mtu_size mtu size to be read
 */
void nmu_get_ip4_mtu_size(kal_uint8 ip_id, kal_uint16* mtu_size);


/*
 *  @brief  set total number of IPv4 DNS servers of ip instance
 *  @param  ip_id ip instance id
 *  @param  dns_num total number to be written
 */
void nmu_set_ip4_dns_num(kal_uint8 ip_id, kal_uint8 dns_num);


/*
 *  @brief  get total number of IPv4 DNS servers of ip instance
 *  @param  ip_id ip instance id
 *  @param  dns_num total number to be read
 */
void nmu_get_ip4_dns_num(kal_uint8 ip_id, kal_uint8* dns_num);


/*
 *  @brief  set DNS server IPv4 address of ip instance
 *  @param  ip_id ip instance id
 *  @param  dns_id dns server no
 *  @param  dns IPv4 address to be written
 */
void nmu_set_ip4_dns(kal_uint8 ip_id, kal_uint8 dns_id, void* dns);


/*
 *  @brief  get DNS server IPv4 address of ip instance
 *  @param  ip_id ip instance id
 *  @param  dns_id dns server no
 *  @param  dns IPv4 address to be read
 */
void nmu_get_ip4_dns(kal_uint8 ip_id, kal_uint8 dns_id, void* dns);


/*
 *  @brief  set ip instance IPv6 up
 *  @param  ip_id ip instance id
 */
void nmu_set_ip6_up(kal_uint8 ip_id);


/*
 *  @brief  set ip instance IPv6 down
 *  @param  ip_id ip instance id
 */
void nmu_set_ip6_down(kal_uint8 ip_id);


/*
 *  @brief  check ip instance IPv6 is up or not
 *  @param  ip_id ip instance id
 *  @return KAL_TRUE if IPv6 is up, KAL_FALSE if not
 */
kal_bool nmu_check_ip6_up(kal_uint8 ip_id);


/*
 *  @brief  set IPv6 mtu size of ip instance
 *  @param  ip_id ip instance id
 *  @param  mtu_size mtu size to be written
 */
void nmu_set_ip6_mtu_size(kal_uint8 ip_id, kal_uint32 mtu_size);


/*
 *  @brief  get IPv6 mtu size of ip instance
 *  @param  ip_id ip instance id
 *  @param  mtu_size mtu size to be read
 */
void nmu_get_ip6_mtu_size(kal_uint8 ip_id, kal_uint32* mtu_size);


/*
 *  @brief  set IPv6 prefix length of ip instance
 *  @param  ip_id ip instance id
 *  @param  prefix_len prefix length to be written
 */
void nmu_set_ip6_prefix_len(kal_uint8 ip_id, kal_uint8 prefix_len);


/*
 *  @brief  get IPv6 prefix length of ip instance
 *  @param  ip_id ip instance id
 *  @param  prefix_len prefix length to be read
 */
void nmu_get_ip6_prefix_len(kal_uint8 ip_id, kal_uint8* prefix_len);


/*
 *  @brief  set IPv6 prefix of ip instance
 *  @param  ip_id ip instance id
 *  @param  prefix_len prefix to be written
 */
void nmu_set_ip6_prefix(kal_uint8 ip_id, void* prefix);


/*
 *  @brief  get IPv6 prefix of ip instance
 *  @param  ip_id ip instance id
 *  @param  prefix_len prefix to be read
 */
void nmu_get_ip6_prefix(kal_uint8 ip_id, void* prefix);


/*
 *  @brief  set IPv6 interface identifier length of ip instance
 *  @param  ip_id ip instance id
 *  @param  iid_len interface identifier length to be written
 */
void nmu_set_ip6_iid_len(kal_uint8 ip_id, kal_uint8 iid_len);


/*
 *  @brief  get IPv6 interface identifier length of ip instance
 *  @param  ip_id ip instance id
 *  @param  iid_len interface identifier length to be read
 */
void nmu_get_ip6_iid_len(kal_uint8 ip_id, kal_uint8* iid_len);


/*
 *  @brief  set IPv6 interface identifier of ip instance
 *  @param  ip_id ip instance id
 *  @param  iid_len interface identifier to be written
 */
void nmu_set_ip6_iid(kal_uint8 ip_id, void* iid);


/*
 *  @brief  get IPv6 interface identifier of ip instance
 *  @param  ip_id ip instance id
 *  @param  iid_len interface identifier to be read
 */
void nmu_get_ip6_iid(kal_uint8 ip_id, void* iid);


/*
 *  @brief  set total number of IPv6 DNS servers of ip instance
 *  @param  ip_id ip instance id
 *  @param  dns_num total number to be written
 */
void nmu_set_ip6_dns_num(kal_uint8 ip_id, kal_uint8 dns_num);


/*
 *  @brief  get total number of IPv6 DNS servers of ip instance
 *  @param  ip_id ip instance id
 *  @param  dns_num total number to be read
 */
void nmu_get_ip6_dns_num(kal_uint8 ip_id, kal_uint8* dns_num);


/*
 *  @brief  set DNS server IPv6 address of ip instance
 *  @param  ip_id ip instance id
 *  @param  dns_id dns server no
 *  @param  dns IPv6 address to be written
 */
void nmu_set_ip6_dns(kal_uint8 ip_id, kal_uint8 dns_id, void* dns);


/*
 *  @brief  get DNS server IPv6 address of ip instance
 *  @param  ip_id ip instance id
 *  @param  dns_id dns server no
 *  @param  dns IPv6 address to be read
 */
void nmu_get_ip6_dns(kal_uint8 ip_id, kal_uint8 dns_id, void* dns);


/*
 *  @brief  set fake netmask and gateway through real ip address
 *  @param  ip_id ip instance id
 *  @param  ip_address IPv4 address used to calculated fake netmask and gateway
 */
void nmu_set_ip4_fake_mask_and_gateway(kal_uint8 ip_id, void *ip_address);


#endif  // _NMU_UTIL_H

