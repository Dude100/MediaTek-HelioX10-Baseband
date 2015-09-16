/*!
 *  @file ndpc_struct.h
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
 *  This file provides structure definition of ndpc ( NDP Client )
 */

#ifndef _NDPC_STRUCT_H
#define _NDPC_STRUCT_H

/*!
 *  @brief ndpc_cause_e enumerate possible cause of NDP Client
 *  @param NDPC_CAUSE_MIN                   pseudo state
 *  @param NDPC_CAUSE_SUCCESS               success
 *  @param NDPC_CAUSE_NO_INSTANCE           no instance available
 *  @param NDPC_CAUSE_INVALID_PARAMETER     parameter is invalid
 *  @param NDPC_CAUSE_MAX                   pseudo state
 */
typedef enum _ndpc_cause {
    NDPC_CAUSE_MIN                                  = 0,
    NDPC_CAUSE_SUCCESS                              = 1,
    NDPC_CAUSE_NO_INSTANCE                          = 2,
    NDPC_CAUSE_INVALID_PARAMETER                    = 3,
    NDPC_CAUSE_INVALID_STATE                        = 4,
    NDPC_CAUSE_MAX                                  = 5,
} ndpc_cause_e;


/*!
 *  @brief ndpc_link_layer_type_e enumerate possible link layer type of
 *         NDP Client
 *  @param NDPC_LINK_MIN                    pseudo state
 *  @param NDPC_LINK_ETHERNET               ethernet type
 *  @param NDPC_LINK_MAX                    pseudo state
 */
typedef enum _ndpc_link_layer_type {
    NDPC_LINK_MIN                                   = 0,
    NDPC_LINK_ETHERNET                              = 1,
    NDPC_LINK_MAX                                   = 2,
} ndpc_link_layer_type_e;


#define NDPC_MAX_LINK_ADDRESS_SIZE                  8
/*!
 *  @brief ndpc_activagte_req_struct describe activate request information
 *         of NDP Client
 */
typedef struct _ndpc_activate_req_struct {
    /*!
     *  @brief ILM local parameter header
     */
    LOCAL_PARA_HDR
    /*!
     *  @brief ip instance identifier
     */
    kal_uint8       ip_id;
    /*!
     *  @brief link layer type
     */
    ndpc_link_layer_type_e      link_layer_type;
    /*!
     *  @brief link layer address
     */
    kal_uint8                   link_layer_address[NDPC_MAX_LINK_ADDRESS_SIZE];
} ndpc_activate_req_struct;


/*!
 *  @brief ndpc_activate_rsp_struct describe activate response information
 *         of NDP Client
 */
typedef struct _ndpc_activate_rsp_struct {
    /*!
     *  @brief ILM local parameter header
     */
    LOCAL_PARA_HDR
    /*!
     *  @brief ip instance identifier
     */
    kal_uint8       ip_id;
    /*!
     *  @brief NDP Client instance identifier
     */
    kal_uint8       ndp_id;
    /*!
     *  @brief response cause
     */
    ndpc_cause_e    cause;
} ndpc_activate_rsp_struct;


/*!
 *  @brief ndpc_deactivate_req_struct describe deactivate request information
 *         of NDP Client
 */
typedef struct _ndpc_deactivate_req_struct {
    /*!
     *  @brief ILM local parameter header
     */
    LOCAL_PARA_HDR
    /*!
     *  @brief ip instance identifier
     */
    kal_uint8       ip_id;
    /*!
     *  @brief NDP Client instance identifier
     */
    kal_uint8       ndp_id;
} ndpc_deactivate_req_struct;


/*!
 *  @brief ndpc_deactivate_rsp_struct describe deactivate response information
 *         of NDP Client
 */
typedef struct _ndpc_deactivate_rsp_struct {
    /*!
     *  @brief ILM local parameter header
     */
    LOCAL_PARA_HDR
    /*!
     *  @brief ip instance identifier
     */
    kal_uint8       ip_id;
    /*!
     *  @brief NDP Client instance identifier
     */
    kal_uint8       ndp_id;
    /*!
     *  @brief response cause
     */
    ndpc_cause_e    cause;
} ndpc_deactivate_rsp_struct;


/*!
 *  @brief ndpc_packet_req_struct describe packet request information
 *         of NDP Client
 */
typedef struct _ndpc_packet_req_struct {
    /*!
     *  @brief ILM local parameter header
     */
    LOCAL_PARA_HDR
    /*!
     *  @brief ip instance identifier
     */
    kal_uint8       ip_id;
    /*!
     *  @brief NDP Client instance identifier
     */
    kal_uint8       ndp_id;
    /*!
     *  @brief request gpd packet buffer
     */
    void*           gpd;
} ndpc_packet_req_struct;


/*!
 *  @brief ndpc_packet_ind_struct describe packet indicate information
 *         of NDP Client
 */
typedef struct _ndpc_packet_ind_struct {
    /*!
     *  @brief ILM local parameter header
     */
    LOCAL_PARA_HDR
    /*!
     *  @brief ip instance identifier
     */
    kal_uint8       ip_id;
    /*!
     *  @brief NDP Client instance identifier
     */
    kal_uint8       ndp_id;
    /*!
     *  @brief indicate gpd packet buffer
     */
    void*           gpd;
} ndpc_packet_ind_struct;


/*!
 *  @brief ndpc_ip_up_ind_struct describe ip up indicate information
 *         of NDP Client
 */
typedef struct _ndpc_ip_up_ind_struct {
    /*!
     *  @brief ILM local parameter header
     */
    LOCAL_PARA_HDR
    /*!
     *  @brief ip instance identifier
     */
    kal_uint8       ip_id;
    /*!
     *  @brief NDP Client instance identifier
     */
    kal_uint8       ndp_id;
} ndpc_ip_up_ind_struct;


/*!
 *  @brief ndpc_ip_down_ind_struct describe ip down indicate information
 *         of NDP Client
 */
typedef struct _ndpc_ip_down_ind_struct {
    /*!
     *  @brief ILM local parameter header
     */
    LOCAL_PARA_HDR
    /*!
     *  @brief ip instance identifier
     */
    kal_uint8       ip_id;
    /*!
     *  @brief NDP Client instance identifier
     */
    kal_uint8       ndp_id;
} ndpc_ip_down_ind_struct;


#endif  // _NDPC_STRUCT_H

