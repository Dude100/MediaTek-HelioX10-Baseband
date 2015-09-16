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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2003
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *  gps_sap.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GIS SAP
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "module_msg_range.h"

#ifndef GPS_MSGID_H
#define GPS_MSGID_H

MODULE_MSG_BEGIN( MSG_ID_GPS_MSG_CODE_BEGIN )
MSG_ID_GPS_UART_OPEN_REQ,
MSG_ID_GPS_UART_READ_REQ,
MSG_ID_GPS_UART_WRITE_REQ,
MSG_ID_GPS_UART_CLOSE_REQ,
MSG_ID_GPS_UART_OPEN_SWITCH_REQ,
MSG_ID_GPS_UART_CLOSE_SWITCH_REQ,

MSG_ID_GPS_POS_GAD_CNF,
MSG_ID_GPS_LCSP_MSG_CODE_BEGIN = MSG_ID_GPS_POS_GAD_CNF,
MSG_ID_GPS_LCSP_MEAS_GAD_CNF,
MSG_ID_GPS_LCSP_ASSIST_DATA_CNF,
MSG_ID_GPS_LCSP_MSG_CODE_END = MSG_ID_GPS_LCSP_ASSIST_DATA_CNF,
MSG_ID_GPS_POS_GAD_REQ,
MSG_ID_GPS_LCSP_MEAS_GAD_REQ,
MSG_ID_GPS_LCSP_ASSIST_DATA_REQ,
MSG_ID_GPS_LCSP_ABORT_REQ,
MSG_ID_GPS_LCSP_AGPS_RESTART_IND,

/* RTC -> GPS */
MSG_ID_RTC_GPS_TIME_CHANGE_IND,
/* GPS EINT HISR -> GPS */
MSG_ID_GPS_HOST_WAKE_UP_IND,

MSG_ID_UAGPS_CP_GPS_ASSIST_DATA_ENQUIRY_IND,
MSG_ID_UAGPS_CP_GPS_SFN_GPS_TOW_DRIFT_TIME_REQ,
MSG_ID_UAGPS_CP_GPS_SFN_GPS_TOW_DRIFT_TIME_CNF,
MSG_ID_UAGPS_CP_GPS_SFN_GPS_TOW_DRIFT_TIME_CANCEL_REQ,
MSG_ID_GPS_AREA_EVENT_ADD_RSP,
MSG_ID_GPS_AREA_EVENT_ADD_REQ,
MSG_ID_GPS_AREA_EVENT_DEL_REQ,
MSG_ID_GPS_AREA_EVENT_HAPPEN_IND,
MSG_ID_UAGPS_CP_GPS_POS_CHANGE_EVALUATION_REQ,
MSG_ID_UAGPS_CP_GPS_POS_CHANGE_EVALUATION_RSP,
MSG_ID_UAGPS_CP_GPS_POS_CHANGE_EVALUATION_DEL,

/* LCSP -> GNSS Task */
MSG_ID_LCSP_GNSS_OPEN_REQ,
MSG_ID_LCSP_GNSS_CLOSE_REQ,
MSG_ID_LCSP_GNSS_COMMON_ASSIST_DATA_REQ,
MSG_ID_LCSP_GNSS_GENERIC_ASSIST_DATA_REQ,
MSG_ID_LCSP_GNSS_POS_REQ,
MSG_ID_LCSP_GNSS_MEAS_REQ,
MSG_ID_LCSP_GNSS_ABORT_REQ,
MSG_ID_LCSP_GNSS_RESET_UE_STORED_POS_INFO,

/* GNSS Task -> LCSP */
MSG_ID_LCSP_GNSS_COMMON_ASSIST_DATA_CNF,
MSG_ID_LCSP_GNSS_GENERIC_ASSIST_DATA_CNF,
MSG_ID_LCSP_GNSS_POS_CNF,
MSG_ID_LCSP_GNSS_MEAS_CNF,
MSG_ID_LCSP_GNSS_ADDITIONAL_ASSIST_DATA_REQ,


/*LBS -> L4C*/
//MSG_ID_LBS_MOLR_BEGIN_REQ,
//MSG_ID_LBS_MOLR_END_REQ,
//MSG_ID_L4C_SERVICE_STATE_REQ,
//MSG_ID_L4C_ROAMING_STATE_REQ,
//MSG_ID_L4C_DATA_CONN_STATE_REQ,

/*GPS-> LBS*/
MSG_ID_LBS_GNSS_PMTK_IND,
MSG_ID_LBS_GNSS_GPS_CLOSE_REQ,
MSG_ID_LBS_GNSS_GPS_OPEN_REQ,
MSG_ID_LBS_GNSS_AGNSS_RESTART_IND,


/*LBS->GPS*/
MSG_ID_LBS_GNSS_PMTK_REQ,


/*LBS -> ATCI*/
//MSG_ID_LBSAP_DATA_SEND_REQ,

#ifdef UNIT_TEST
/* GPS -> GPS */
MSG_ID_GPS_UT_SET_EVENT_IND,
MSG_ID_GPS_UT_WRITE_DATA_IND,
#endif

MODULE_MSG_END( MSG_ID_GPS_MSG_CODE_TAIL )

MODULE_MSG_BEGIN( MSG_ID_LBS_CODE_BEGIN )
    /*L4C -> LBS*/
    MSG_ID_LBS_MTLR_BEGIN_IND,
    MSG_ID_LBS_MTLR_BEGIN_RES_RSP,
    /* AERQ, AERP, AECL not used now*/
    MSG_ID_LBS_AERQ_BEGIN_IND,
    MSG_ID_LBS_AERQ_BEGIN_RES_RSP,
    MSG_ID_LBS_AERP_BEGIN_RSP,
    MSG_ID_LBS_AERP_END_RSP,
    MSG_ID_LBS_AECL_BEGIN_IND,
    MSG_ID_LBS_AECL_BEGIN_RES_RSP,
    MSG_ID_LBS_MOLR_BEGIN_RSP,
    MSG_ID_LBS_MOLR_END_RSP,
    MSG_ID_AGPS_RESET_POSITIONING_IND,
    MSG_ID_AGPS_CP_START_IND,
    MSG_ID_AGPS_CP_END_IND,
    MSG_ID_L4C_LBS_SERVICE_STATE_RSP,
    MSG_ID_L4C_LBS_ROAMING_STATE_RSP,
    MSG_ID_L4C_LBS_DATA_CONN_STATE_RSP,
    MSG_ID_L4C_LBS_CURRENT_RAT_RSP,
#ifdef UNIT_TEST
    /* LBS -> LBS */
    MSG_ID_GPS_UT_LBS_HEADER_IND,
    
#endif

MODULE_MSG_END( MSG_ID_LBS_CODE_TAIL )


#endif //GPS_MSGID_H
