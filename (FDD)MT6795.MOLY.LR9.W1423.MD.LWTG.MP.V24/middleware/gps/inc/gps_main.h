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
 *  gps_main.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GPS task
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifndef _GPS_MAIN_H_
#define _GPS_MAIN_H_

#include "kal_public_api.h"
#include "kal_general_types.h"
        
#define GPS_AGPS_POS_REQ_TIMER_MAX 3 
#define GPS_AGPS_MEAS_REQ_TIMER_MAX 3 

typedef enum
{
    GPS_SLEEP_MODE_TIMER = 0,
    GPS_UART_RING_BUFFER_EXP_TIMER,
    GPS_UART_POWER_ON_CHECK_VERSION_TIMER,
    GPS_UART_POWER_ON_CHECK_CHIP_ID_TIMER,
    GPS_UART_ENABLE_DEBUG_INFO_TIMER,
    GPS_UART_AUTHENTICATION_TIMER,
    GPS_UART_SWITCH_MODE_TIMER,
    GPS_AGPS_ASSIST_CMD_WRITE_TIMER,
    GPS_AGPS_ASSIST_CMD_WRITE_EXP_TIMER,
    GPS_AGPS_QUERY_TIMER,
    GPS_AGPS_POS_REQ_BASE_TIME,
    GPS_AGPS_POS_REQ_TIME_END = GPS_AGPS_POS_REQ_BASE_TIME + GPS_AGPS_POS_REQ_TIMER_MAX - 1,
    GPS_AGPS_MEAS_REQ_BASE_TIME,
    GPS_AGPS_MEAS_REQ_TIME_END =GPS_AGPS_MEAS_REQ_BASE_TIME + GPS_AGPS_MEAS_REQ_TIMER_MAX - 1,
    GPS_FRAME_SYNC_REQ_TIMER,
    GPS_UART_NMEA_SIMULATE_TIMER,
    GPS_POWER_ON_OFF_TIMER,
    MAX_NUM_OF_GPS_TIMER
} gps_timer_enum;

typedef struct
{
    eventid event_id;
    kal_timer_func_ptr callback_func;
    void       *arg;
    kal_uint32 *timer_id_ptr;
    kal_bool   is_restart;
} gps_timer_table_struct;

typedef enum
{
    GPS_POWERON_STATE = 0,
    GPS_POWEROFF_STATE,
    GPS_STATE_TOTAL
} gps_state_enum;

typedef struct
{
    gps_state_enum gps_state;
    event_scheduler *event_scheduler_ptr;
} gps_context_struct;

extern void gps_start_timer(kal_uint8 timer_id, kal_uint32 period, kal_timer_func_ptr timer_expiry, void *arg);
extern void gps_stop_timer(kal_uint8 timer_id);

#endif /* _GPS_MAIN_H_ */


