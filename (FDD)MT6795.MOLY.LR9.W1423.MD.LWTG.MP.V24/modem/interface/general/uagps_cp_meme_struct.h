/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   uagps_cp_meme_struct.h
 *
 * Project:
 * --------
 *   AGPS
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log:$
 * 
 * removed!
 * removed!
 * 20120928_MOLY00004236_Adeline_Remove_stack_ltlcom.h_AGPS.xls.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * ULCS RHR
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * add to source control recursely
 *
 ****************************************************************************/

#ifndef _UAGPS_CP_MEME_STRUCT_H
#define _UAGPS_CP_MEME_STRUCT_H
#include "kal_public_api.h"
#include "kal_general_types.h"

#define ACTIVE_SET_CELL_NUM 8

typedef enum
{
    RRC_STATE_INACTIVE, 
    RRC_STATE_IDLE, 
    RRC_STATE_CELL_DCH, 
    RRC_STATE_CELL_FACH,
    RRC_STATE_CELL_PCH,
    RRC_STATE_URA_PCH
} rrc_state_enum;

typedef enum
{
    RRC_MESSAGE_TYPE_MEASUREMENT_REPORT, 
    RRC_MESSAGE_TYPE_MEASUREMENT_CONTROL_FAILURE
} rrc_message_type;

typedef enum
{
    RRC_MESSAGE_REPORT_RLC_AM, 
    RRC_MESSAGE_REPORT_RLC_UM
} rrc_message_report_rlc_type;

/**************************************************************
 * UAGPS_CP_MEME_MOVE_TO_STATE_IND
 *
 * 
 ***************************************************************/
typedef struct
{
    LOCAL_PARA_HDR

    rrc_state_enum rrc_state;

    /* Fill these parameters to update the active set information if and only if the new state is CELL_DCH state */
    kal_uint16 uarfcn;
    kal_uint8 numOfCell;
    kal_uint16 phyCellId[ACTIVE_SET_CELL_NUM];

} uagps_cp_meme_move_to_state_ind_struct;

/**************************************************************
 * UAGPS_CP_MEME_POSITIONING_DATA_IND
 *
 * data in pdu buffer by ASN encoded format
 ***************************************************************/
typedef struct
{
    LOCAL_PARA_HDR

    kal_uint16 transaction_id;

} uagps_cp_meme_positioning_data_ind_struct;

/**************************************************************
 * UAGPS_CP_MEME_RELEASE_MEASUREMENT_IND
 *
 * 
 ***************************************************************/
typedef struct
{
    LOCAL_PARA_HDR

    kal_uint16 transaction_id;

} uagps_cp_meme_release_measurement_ind_struct;

/**************************************************************
 * UAGPS_CP_MEME_POSITIONING_DATA_REQ
 *
 * 
 ***************************************************************/
typedef struct
{
    LOCAL_PARA_HDR

    kal_uint16 transaction_id;
    //RRC_MeasurementValidity validity_state; // use ASN decoded type
    rrc_message_type message_type;
    kal_uint8 *message_pdu; // Measurement report or Measurement control failure

    rrc_message_report_rlc_type rlc_type;

} uagps_cp_meme_positioning_data_req_struct;

/**************************************************************
 * UAGPS_CP_MEME_RELEASE_MEASUREMENT_REQ
 *
 * 
 ***************************************************************/
typedef struct
{
    LOCAL_PARA_HDR

    kal_uint16 transaction_id;

} uagps_cp_meme_release_measurement_req_struct;

typedef struct
{
    LOCAL_PARA_HDR

    kal_uint16 transaction_id;
    kal_bool isSent;
} uagps_cp_meme_measurement_report_cnf_struct;

#endif /* _UAGPS_CP_MEME_STRUCT_H */
