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
 *  gps_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for local parameter declaration about GIS sap
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __GPS_STRUCT_H__
#define __GPS_STRUCT_H__

#ifdef __GPS_SUPPORT__
#include "dcl.h"
#endif

#include "gps2lcsp_enum.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "agps_md_interface.h"    

typedef enum
{
    MMI_GPS_ATE_EVENT_POWER_ON,
    MMI_GPS_ATE_EVENT_POWER_OFF,
    MMI_GPS_ATE_EVENT_COMMAND

} gps_ate_event_type_enum;

typedef struct
{
    LOCAL_PARA_HDR
    gps_ate_event_type_enum event;
    kal_uint16 cmd_length;
    kal_uint8 cmd_buf[256];
} gps_ate_test_req_struct;

typedef enum
{
    GPS_PARSER_P_VERSION = 0,
    GPS_PARSER_P_GPS_MODE_SWITCH_OK,
    GPS_PARSER_P_SYSTEM_START_OK,
    GPS_PARSER_P_INTERNAL_VERSION,
    GPS_PARSER_P_GPS_FIXED,
    GPS_PARSER_P_GPS_BT_VPORT_LOST,
    GPS_PARSER_P_GPS_BT_VPORT_CONN,
    GPS_PARSER_P_GPS_FIXED_AND_TIME_OK,
    GPS_PARSER_P_END
} gps_parser_p_info_enum;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_eventgrpid  event_id;
    module_type     module_id;
    kal_uint16             port; 
    kal_int16          mode; 
    kal_int32             *return_val;
}gps_uart_open_req_struct;

typedef struct 
{
    LOCAL_PARA_HDR
    kal_eventgrpid  event_id;
    module_type     module_id;
    kal_uint16             port; 
}gps_uart_read_req_struct;

typedef struct 
{
    LOCAL_PARA_HDR
    kal_eventgrpid  event_id;
    module_type     module_id;
    kal_uint16      port; 
    kal_bool        is_rawdata; 
    kal_char*       buffer; 
    kal_uint32      length; 
    kal_int16      cmd; 
    kal_int32             *return_val;
    kal_uint32            *return_written;
}gps_uart_write_req_struct;

typedef struct 
{
    LOCAL_PARA_HDR
    kal_eventgrpid  event_id;
    module_type     module_id;
    kal_uint16             port; 
    kal_int16             mode; /*mdi_gps_uart_work_mode_enum*/
}gps_uart_close_req_struct;

typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint16   port;
    kal_int16     type;   /*mdi_gps_parser_info_enum*/
    kal_char*    buffer; 
}gps_uart_nmea_location_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint32   length;
    kal_uint16   port;
    kal_char*    buffer; 
}gps_uart_nmea_sentence_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint16   port;
    module_type  module_id;
}gps_uart_raw_data_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint16   port;
}gps_uart_debug_raw_data_struct;

typedef struct
{            
    kal_int8      hour;
    kal_int8      minute;
    kal_int8      second;
    kal_int8      millisecond;
} gps_nmea_utc_time_struct;

typedef struct 
{
    kal_int8      year;
    kal_int8      month;
    kal_int8      day;
} gps_nmea_utc_date_struct;


typedef struct
{            
    gps_nmea_utc_time_struct    utc_time;
    gps_nmea_utc_date_struct    utc_date;
} gps_p_info_gps_fix_struct;


typedef struct
{            
    kal_uint16    port;
} gps_p_info_gps_vport_struct;



typedef union {
    gps_p_info_gps_fix_struct   gps_fix;
    gps_p_info_gps_vport_struct vport;
} gps_p_info_union;


typedef struct 
{
    LOCAL_PARA_HDR
    gps_parser_p_info_enum      type;
    gps_p_info_union            p_info;
}gps_uart_p_info_ind_struct;


#ifdef __GPS_SUPPORT__
typedef struct 
{
    LOCAL_PARA_HDR
    DCL_RTC_DATA_T previous_rtc;
    DCL_RTC_DATA_T new_rtc;
}rtc_gps_time_change_ind_struct;
#endif


typedef struct 
{
    LOCAL_PARA_HDR
    gps_error_code_enum error_code;
} gps_lct_op_error_struct;


typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint16  bitmap;
} gps_assist_bit_mask_ind_struct;

typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint16  port; /*set to GPS_DEFAULT_PORT*/
    kal_int16   prefer_gps_mode; /*mb ma*/
}gps_uart_open_switch_req_struct;

typedef struct 
{
    LOCAL_PARA_HDR
    kal_uint16  port; /*set to GPS_DEFAULT_PORT*/
}gps_uart_close_switch_req_struct;

#ifdef __GPS_SUPPORT__
typedef enum
{
    GPS_AREA_SHAPE_CIRCLE,
    GPS_AREA_SHAPE_RECTANGLE,
    GPS_AREA_SHAPE_END
} gps_area_shape_enum;

typedef enum
{
    GPS_AREA_DIRECTION_ENTER,
    GPS_AREA_DIRECTION_LEAVE,
    GPS_AREA_DIRECTION_END
} gps_area_direction_enum;

typedef struct
{
    kal_uint32      latitude;
    kal_uint32      longtitude;
    kal_int8    north_south;    /*N for North and S for South*/
    kal_int8    west_east;      /*W for West and E for East*/
    kal_uint32      rad;            /*unit is m*/
} gps_area_shape_circle_struct;

typedef struct
{
    kal_uint32      latitude1;
    kal_uint32      longtitude1;
    kal_int8    north_south1;   /*N for North and S for South*/
    kal_int8    west_east1;     /*W for West and E for East*/
    kal_uint32      latitude2;
    kal_uint32      longtitude2;
    kal_int8    north_south2;   /*N for North and S for South*/
    kal_int8    west_east2;     /*W for West and E for East*/
} gps_area_shape_rectangle_struct;



// MSG_ID_GPS_AREA_EVENT_ADD_REQ
typedef struct
{
    LOCAL_PARA_HDR

    kal_int32                   transaction_id;     /* after add the request GPS will return result with the same id to caller */
    gps_area_shape_enum         shape;              /*the shape of request*/
    kal_bool                    is_continue_report; /*if GPS should send MSG once or continue*/
    gps_area_direction_enum     direction;          /*start send MSG after enter or leave*/
    union {
        gps_area_shape_circle_struct    circle;
        gps_area_shape_rectangle_struct    rectangle;
    } choice;
} gps_area_event_add_req_struct;

// MSG_ID_GPS_AREA_EVENT_ADD_RSP
typedef struct
{
    LOCAL_PARA_HDR

    kal_int32       transaction_id;     /* after process the request GPS will send result with associated id to caller */
//    kal_bool        is_match;   /* is request match, MUST fill this field to inform UAGPS_CP position difference calculation result */
    kal_bool        is_add_ok;  /*MMI_FALSE when too many request*/
#ifdef __AGPS_SUPPORT__
//    gps_pos_result_struct   pos_result; /* when is_match == KAL_TRUE, also necessary to carry this result */

//    kal_bool    utran_gps_ref_time_result_valid;
//    utran_gps_ref_time_result_struct utran_gps_ref_time_result;
#endif
} gps_area_event_add_rsp_struct;

// MSG_ID_GPS_AREA_EVENT_ADD_RSP
typedef struct
{
    LOCAL_PARA_HDR

    kal_int32       transaction_id;     /* after process the request GPS will send result with associated id to caller */
    kal_uint32      latitude;
    kal_uint32      longtitude;
    kal_int8        north_south;    /*N for North and S for South*/
    kal_int8        east_west;      /*W for West and E for East*/
    
} gps_area_event_happen_ind_struct;

// MSG_ID_GPS_AREA_EVENT_DEL_REQ
typedef struct
{
    LOCAL_PARA_HDR

    kal_int32      transaction_id;     /* send the id to GPS let it delete the request */

} gps_area_event_del_req_struct;
#endif /*__GPS_SUPPORT__*/

#ifdef UNIT_TEST

// MSG_ID_GPS_UT_SET_EVENT_IND
typedef struct
{
    LOCAL_PARA_HDR
    kal_eventgrpid   event_id; 
    kal_uint32       events;
    kal_uint8        operation;
    kal_int32        ret_address;
    kal_int32        ret_value;

} gps_ut_set_event_ind_struct;

// MSG_ID_GPS_UT_WRITE_DATA_IND
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8  data_buffer[100];
 
} gps_ut_write_data_ind_struct;


// MSG_ID_GPS_UT_LBS_HEADER_IND
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32      version; //use AGPS_MD_INTERFACE_VERSION
    agps_md_type    type;    //refer to agps_md_type
    kal_uint8       len;
} gps_ut_lbs_header_ind_struct;
 

#endif

#endif /*__GPS_STRUCT_H__*/

