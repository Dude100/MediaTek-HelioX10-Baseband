/*!
 *  @file dhcp4c_struct.h
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
 *  This file provides structure definition of dhcp4c ( DHCPv4 Client )
 */

#ifndef _DHCP4C_STRUCT_H
#define _DHCP4C_STRUCT_H


/*!
 *  @brief dhcp4c_cause_e enumerate possible cause of DHCPv4 Client
 *  @param DHCP4C_CAUSE_MIN                 pseudo state
 *  @param DHCP4C_CAUSE_SUCCESS             success
 *  @param DHCP4C_CAUSE_NO_INSTANCE         no instance available
 *  @param DHCP4C_CAUSE_INVALID_PARAMETER   parameter is invalid
 *  @param DHCP4C_CAUSE_INVALID_STATE       not allow in this state
 *  @param DHCP4C_CAUSE_MAX                 pseudo state
 */
typedef enum _dhcp4c_cause {
    DHCP4C_CAUSE_MIN                                = 0,
    DHCP4C_CAUSE_SUCCESS                            = 1,
    DHCP4C_CAUSE_NO_INSTANCE                        = 2,
    DHCP4C_CAUSE_INVALID_PARAMETER                  = 3,
    DHCP4C_CAUSE_INVALID_STATE                      = 4,
    DHCP4C_CAUSE_MAX                                = 5,
} dhcp4c_cause_e;


/*!
 *  @brief dhcp4c_hardware_address_type_e enumerate possible hardward address
 *         type of DHCPv4 Client
 *  @param DHCP4C_HTYPE_MIN                 pseudo state
 *  @param DHCP4C_HTYPE_ETHERNET            ethernet type
 *  @param DHCP4C_HTYPE_MAX                 pseudo state
 */
typedef enum _dhcp4c_hardware_address_type {
    DHCP4C_HTYPE_MIN                                = 0,
    DHCP4C_HTYPE_ETHERNET                           = 1,
    DHCP4C_HTYPE_MAX                                = 2,
} dhcp4c_hardware_address_type_e;


#define DHCP4C_MAX_HARDWARE_ADDRESS_SIZE            16
/*!
 *  @brief dhcp4c_activagte_req_struct describe activate request information
 *         of DHCPv4 Client
 */
typedef struct _dhcp4c_activate_req_struct {
    /*!
     *  @brief ILM local parameter header
     */
    LOCAL_PARA_HDR
    /*!
     *  @brief ip instance identifier
     */
    kal_uint8       ip_id;
    /*!
     *  @brief hardware address type
     */
    dhcp4c_hardware_address_type_e  hardware_address_type;
    /*!
     *  @brief hardware address
     */
    kal_uint8       hardware_address[DHCP4C_MAX_HARDWARE_ADDRESS_SIZE];
} dhcp4c_activate_req_struct;


/*!
 *  @brief dhcp4c_activate_rsp_struct describe activate response information
 *         of DHCPv4 Client
 */
typedef struct _dhcp4c_activate_rsp_struct {
    /*!
     *  @brief ILM local parameter header
     */
    LOCAL_PARA_HDR
    /*!
     *  @brief ip instance identifier
     */
    kal_uint8       ip_id;
    /*!
     *  @brief DHCPv4 Client instance identifier
     */
    kal_uint8       dhcp_id;
    /*!
     *  @brief response cause
     */
    dhcp4c_cause_e  cause;
} dhcp4c_activate_rsp_struct;


/*!
 *  @brief dhcp4c_deactivate_req_struct describe deactivate request information
 *         of DHCPv4 Client
 */
typedef struct _dhcp4c_deactivate_req_struct {
    /*!
     *  @brief ILM local parameter header
     */
    LOCAL_PARA_HDR
    /*!
     *  @brief ip instance identifier
     */
    kal_uint8       ip_id;
    /*!
     *  @brief DHCPv4 Client instance identifier
     */
    kal_uint8       dhcp_id;
} dhcp4c_deactivate_req_struct;


/*!
 *  @brief dhcp4c_deactivate_rsp_struct describe deactivate response information
 *         of DHCPv4 Client
 */
typedef struct _dhcp4c_deactivate_rsp_struct {
    /*!
     *  @brief ILM local parameter header
     */
    LOCAL_PARA_HDR
    /*!
     *  @brief ip instance identifier
     */
    kal_uint8       ip_id;
    /*!
     *  @brief DHCPv4 Client instance identifier
     */
    kal_uint8       dhcp_id;
    /*!
     *  @brief response cause
     */
    dhcp4c_cause_e  cause;
} dhcp4c_deactivate_rsp_struct;


/*!
 *  @brief dhcp4c_packet_req_struct describe packet request information
 *         of DHCPv4 Client
 */
typedef struct _dhcp4c_packet_req_struct {
    /*!
     *  @brief ILM local parameter header
     */
    LOCAL_PARA_HDR
    /*!
     *  @brief ip instance identifier
     */
    kal_uint8       ip_id;
    /*!
     *  @brief DHCPv4 Client instance identifier
     */
    kal_uint8       dhcp_id;
    /*!
     *  @brief request gpd packet buffer
     */
    void*           gpd;
} dhcp4c_packet_req_struct;


/*!
 *  @brief dhcp4c_packet_ind_struct describe packet indicate information
 *         of DHCPv4 Client
 */
typedef struct _dhcp4c_packet_ind_struct {
    /*!
     *  @brief ILM local parameter header
     */
    LOCAL_PARA_HDR
    /*!
     *  @brief ip instance identifier
     */
    kal_uint8       ip_id;
    /*!
     *  @brief DHCPv4 Client instance identifier
     */
    kal_uint8       dhcp_id;
    /*!
     *  @brief indicate gpd packet buffer
     */
    void*           gpd;
} dhcp4c_packet_ind_struct;


/*!
 *  @brief dhcp4c_ip_up_ind_struct describe ip up indicate information
 *         of DHCPv4 Client
 */
typedef struct _dhcp4c_ip_up_ind_struct {
    /*!
     *  @brief ILM local parameter header
     */
    LOCAL_PARA_HDR
    /*!
     *  @brief ip instance identifier
     */
    kal_uint8       ip_id;
    /*!
     *  @brief DHCPv4 Client instance identifier
     */
    kal_uint8       dhcp_id;
} dhcp4c_ip_up_ind_struct;


/*!
 *  @brief dhcp4c_ip_down_ind_struct describe ip down indicate information
 *         of DHCPv4 Client
 */
typedef struct _dhcp4c_ip_down_ind_struct {
    /*!
     *  @brief ILM local parameter header
     */
    LOCAL_PARA_HDR
    /*!
     *  @brief ip instance identifier
     */
    kal_uint8       ip_id;
    /*!
     *  @brief DHCPv4 Client instance identifier
     */
    kal_uint8       dhcp_id;
} dhcp4c_ip_down_ind_struct;


#endif  // _DHCP4C_STRUCT_H

