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
 *   uagps_cp_gps_struct.h
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
 * .
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
 * .
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
 * 
 *
 ****************************************************************************/

#ifndef _UAGPS_CP_GPS_STRUCT_H
#define _UAGPS_CP_GPS_STRUCT_H

#include "kal_public_api.h"
#include "gps2lcsp_struct.h"
#include "kal_general_types.h"
    
/**************************************************************
 * UAGPS_CP_GPS_SFN_GPS_TOW_DRIFT_TIME_REQ
 *
 * 
 ***************************************************************/
typedef struct
{
    LOCAL_PARA_HDR

    kal_int32             transaction_id; /* after the request GPS will return result with the same id to caller */
    
    kal_uint32            drift_time_threshold; // unit: microsecond

    kal_bool     is_utran_gps_ref_time_wanted;       /*Set to TRUE if UTRAN GPS ref time was required to be reported */  

} uagps_cp_gps_sfn_gps_tow_drift_time_req_struct;

/**************************************************************
 * UAGPS_CP_GPS_SFN_GPS_TOW_DRIFT_TIME_CNF
 *
 * 
 ***************************************************************/
typedef struct
{
    LOCAL_PARA_HDR

    kal_int32              transaction_id; /* after process the request GPS will send result with associated id to caller */

    kal_bool               drift_time_above_threshold; /* MUST fill this field to inform UAGPS_CP drift time calculation result */
    kal_uint32             drift_time_result; // unit: microsecond

    /* if for some condition measurement can not be completed, just set it to KAL_FALSE, but it should not occur ? */
    kal_bool               meas_result_valid;
    gps_meas_result_struct meas_result;

    kal_bool    utran_gps_ref_time_result_valid;
    utran_gps_ref_time_result_struct utran_gps_ref_time_result;

} uagps_cp_gps_sfn_gps_tow_drift_time_cnf_struct;

/**************************************************************
 * MSG_ID_UAGPS_CP_GPS_SFN_GPS_TOW_DRIFT_TIME_CANCEL_REQ
 *
 * 
 ***************************************************************/
typedef struct
{
    LOCAL_PARA_HDR

    kal_int32              transaction_id; /* send the id to GPS let it cancel the request */

} uagps_cp_gps_sfn_gps_tow_drift_time_cancel_req_struct;

/**************************************************************
 * UAGPS_CP_GPS_ASSIST_DATA_ENQUIRY_IND
 *
 * 
 ***************************************************************/
typedef struct
{
    LOCAL_PARA_HDR

    kal_uint16                   bitmap; // bitmap for requested assistance data type
    
} uagps_cp_gps_assist_data_enquiry_ind_struct;

//GPS AREA EVENT
#ifdef __AGPS_CONTROL_PLANE__
typedef struct
{
    kal_bool    sign_latitude;    /* true: SOUTH, false: NORTH */
    kal_uint32  latitude;         /* N1, encoded latitude */
    kal_uint32  longtitude;       /* N2, encoded longtitude with 2's complement */
    kal_bool    sign_altitude;    /* true: DEPTH, false: HEIGHT */
    kal_uint16  altitude;         /* no encoding, unit in meter */
} gps_pos_struct;

// MSG_ID_UAGPS_CP_GPS_POS_CHANGE_EVALUATION_REQ
typedef struct
{
    LOCAL_PARA_HDR
    kal_int32           transaction_id;     /* GPS will return result with the same id to caller for this request */
    gps_pos_struct      prev_pos; /* previous position for comparison */
    kal_uint32          rad;            /*unit is m*/
    kal_bool            is_utran_gps_ref_time_wanted;       /*Set to TRUE if UTRAN GPS ref time was required to be reported */  
} uagps_cp_gps_pos_change_evaluation_req_struct;

// MSG_ID_UAGPS_CP_GPS_POS_CHANGE_EVALUATION_RSP
typedef struct
{
    LOCAL_PARA_HDR

    kal_int32                                   transaction_id;     /* GPS will send result with associated id to caller */
    kal_bool                                    is_match;   /* is request match => MUST fill this field to inform UAGPS_CP position difference calculation result */
    gps_pos_result_struct                       pos_result; /* when is_match == KAL_TRUE, also necessary to carry this result */
    kal_bool                                    utran_gps_ref_time_result_valid;
    utran_gps_ref_time_result_struct            utran_gps_ref_time_result;
} uagps_cp_gps_pos_change_evaluation_rsp_struct;

// MSG_ID_UAGPS_CP_GPS_POS_CHANGE_EVALUATION_DEL_REQ
typedef struct
{
    LOCAL_PARA_HDR
    kal_int32      transaction_id;     /* send the id to GPS to let it delete the request */
} uagps_cp_gps_pos_change_evaluation_del_struct;
#endif /*__AGPS_CONTROL_PLANE__*/

#endif /* _UAGPS_CP_GPS_STRUCT_H */
