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
 *  gps_main.c
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
#include "kal_trace.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "dcl.h"
#include "gps_main.h"
#include "gps_init.h"
#include "gps_sm.h"
#include "gps_trc.h"
#include "kal_general_types.h"
#include "sysservice_msgid.h"
#include "tst_msgid.h"
#include "gps_msgid.h"
#include "nvram_msgid.h"
#ifdef UNIT_TEST
#include "gps_uart_hdlr.h"
#endif
        
#ifdef __GPS_SUPPORT__
extern void gps_tst_inject_string_handler( ilm_struct *ilm_ptr );
#endif
extern void gps_uart_state_reset(void);
#if defined(__AGPS_SUPPORT__)
extern void gps_agps_init(void);
extern void gps_agps_reset(void);
#endif
#if defined(__SMART_PHONE_MODEM__)
extern void gps_uart_state_init(void);
#endif

extern kal_bool gps_msg_hdlr(ilm_struct *ilm_ptr);
extern kal_uint8 gps_uart_port;

gps_context_struct gps_context;
gps_context_struct *gps_context_p = &gps_context;
gps_timer_table_struct gps_timer_table[MAX_NUM_OF_GPS_TIMER];

#ifdef UNIT_TEST
/* Klockwork issue fix 20120712
 * align buffer length used (256 bytes) in gps_uart_ready_to_read_ind() instead of GPS_UART_RAW_BUF_SIZE (30 bytes),
 * and avoid memory corruption in case long sentence received by tst_inject
 */
kal_uint8  gps_command_buffer[GPS_NMEA_BUFFER_SIZE+1];
kal_uint16 gps_command_bsize;
#endif

#if defined(__AGPS_SUPPORT__)
/* special flags to control (PMTK997, 6) in dual modem configuration load */
extern kal_bool is_another_AGPS_session_ongoing;
extern kal_bool is_loc_error_sent;
#endif /* __AGPS_SUPPORT__ */

static void gps_timer_expiry(ilm_struct *ilm_ptr);
static void gps_timer_expiry_callback(void *arg);

kal_bool GPS_TASK_INIT_OK = KAL_FALSE;
/*****************************************************************************
 * FUNCTION
 *  gps_main
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  ilm_ptr     [IN]     message data
 * RETURNS
 *  void
 *****************************************************************************/
void gps_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MSG_ID_TIMER_EXPIRY == ilm_ptr->msg_id)
    {
        gps_timer_expiry(ilm_ptr);
    }
#ifdef __GPS_SUPPORT__
    else if (MSG_ID_TST_INJECT_STRING == ilm_ptr->msg_id)
    {
        gps_tst_inject_string_handler( ilm_ptr );
    }
    else if (MSG_ID_RTC_GPS_TIME_CHANGE_IND == ilm_ptr->msg_id)
    {
        GPS_Adjust_RTC_Diff( ilm_ptr );
    }
    else if (MSG_ID_NVRAM_WRITE_CNF == ilm_ptr->msg_id)
    {
        gps_nvram_write_cnf_handler( ilm_ptr );
    }
    else if (MSG_ID_GPS_HOST_WAKE_UP_IND == ilm_ptr->msg_id)
    {
        gps_host_wake_up_ind_handler();
    }
#endif /*__GPS_SUPPORT__*/
#ifdef UNIT_TEST
    else if (MSG_ID_GPS_UT_SET_EVENT_IND == ilm_ptr->msg_id)
    {
        /* Viola 20110712
         * This message is used to verified "set-event" and "ret value" in UT
         */
        return;
    }
#endif
    else if (KAL_TRUE == gps_msg_hdlr(ilm_ptr))
    {
        return;
    }

}


/*****************************************************************************
 * FUNCTION
 *  gps_task_main
 * DESCRIPTION
 *  GPS task main
 * PARAMETERS
 *  task_entry_ptr      [IN]        task struct pointer 
 * RETURNS
 *  void
 *****************************************************************************/
void gps_task_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#if defined(__SMART_PHONE_MODEM__)
    gps_uart_state_init();
	{	
		DCL_HANDLE handle;
		UART_CTRL_OPEN_T data;	
		
	    data.u4OwenrId = MOD_GPS;
		handle = DclSerialPort_Open(gps_uart_port, 0);
		DclSerialPort_Control(handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*)&data); 	
	}
#endif

    while (1)
    {
        msg_receive_extq(&current_ilm);
        kal_set_active_module_id(current_ilm.dest_mod_id);

        gps_main((void*)&current_ilm);

        destroy_ilm(&current_ilm);
    }

}


/*****************************************************************************
 * FUNCTION
 *  gps_task_init
 * DESCRIPTION
 *  Init GPS task
 * PARAMETERS
 *  task_indx       [IN]    task index             
 * RETURNS
 *  KAL_BOOL
 *****************************************************************************/
kal_bool gps_task_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gps_context_p->gps_state = GPS_POWEROFF_STATE; 
    
    gps_context_p->event_scheduler_ptr = evshed_create("GPS base timer", MOD_GPS, 0, 0 );

    for(i = 0; i < MAX_NUM_OF_GPS_TIMER; i++)
    {
        kal_mem_set(&(gps_timer_table[i]), 0, sizeof(gps_timer_table_struct));
    }

    GPS_TASK_INIT_OK = KAL_TRUE;

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  gps_task_reset
 * DESCRIPTION
 *  Reset GPS task
 * PARAMETERS
 *  task_indx       [IN]    task index             
 * RETURNS
 *  KAL_BOOL
 *****************************************************************************/
kal_bool gps_task_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GPS_TRACE((TRACE_GROUP_1, GPS_UART_TRC_GPS_TASK_RESET));

    gps_context_p->gps_state = GPS_POWEROFF_STATE; 
    
    GPS_TASK_INIT_OK = KAL_TRUE;

    evshed_delete_all_events(gps_context_p->event_scheduler_ptr);

    for(i = 0; i < MAX_NUM_OF_GPS_TIMER; i++)
    {
       gps_timer_table[i].event_id = NULL;

       if (gps_timer_table[i].timer_id_ptr != NULL)
       {
           free_ctrl_buffer(gps_timer_table[i].timer_id_ptr);
           gps_timer_table[i].timer_id_ptr = NULL;
       }
       if (gps_timer_table[i].arg != NULL)
       {
           free_ctrl_buffer(gps_timer_table[i].arg);
           gps_timer_table[i].arg = NULL;
       }
       gps_timer_table[i].is_restart = KAL_FALSE;
    }
    
    gps_uart_state_reset();
#if defined(__AGPS_SUPPORT__)
    gps_agps_reset();

    /* reset (PMTK997, 6) related flags */
    is_another_AGPS_session_ongoing = KAL_FALSE;
    is_loc_error_sent = KAL_FALSE;
#endif

#ifdef UNIT_TEST
    gps_command_bsize = 0;
#endif
    
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  gps_task_init_ok
 * DESCRIPTION
 *  Init GPS task
 * PARAMETERS
 *  none            
 * RETURNS
 *  KAL_BOOL
 *****************************************************************************/
kal_bool gps_task_init_ok(void)
{
    return GPS_TASK_INIT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  gps_create
 * DESCRIPTION
 *  Create GPS task
 * PARAMETERS
 *  handle      [IN]     handle
 * RETURNS
 *  KAL_BOOL
 *****************************************************************************/
kal_bool gps_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct gps_handler_info = 
    {
        gps_task_main,  /* task entry function */
        gps_task_init,  /* task initialization function */
        gps_task_reset  /* task reset handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*)&gps_handler_info;

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gps_timer_expiry
 * DESCRIPTION
 * 
 * PARAMETERS
 *  ilm_ptr                
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_timer_expiry(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    evshed_timer_handler(gps_context_p->event_scheduler_ptr);

}
/*****************************************************************************
 * FUNCTION
 *  gps_timer_expiry_callback
 * DESCRIPTION
 *  timer exiry callback
 * PARAMETERS
 *  arg     [IN]   callback function parameter   
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_timer_expiry_callback(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32* timer_id_ptr = NULL;
    kal_uint32  timer_id = 0;

    /* copy timer_id value to a local variable from the reference address to avoid
     * if timer_id_ptr has been deallocated during restart timer action
     */
    timer_id_ptr = (kal_uint32*)arg;
    timer_id = *timer_id_ptr; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((kal_uint32) timer_id < (kal_uint32) MAX_NUM_OF_GPS_TIMER)
    {
        /* besides checking timer_id range, we should also check if this timer is started,
         * else ignore it for unexpected scenarios
         */
        if (gps_timer_table[timer_id].event_id != NULL)
        {
            GPS_TRACE((TRACE_GROUP_4, GPS_TIMER_TRC_TIMEOUT_ID, timer_id));
            gps_timer_table[timer_id].event_id = NULL;
    
            /* ctrl buffer deallocation is not straightforward here, because
             * if we put all handlings of ctrl buffer deallocation at gps_timer_expiray_callback(),
             * there are possible issues happended in either case:
             * (1) arg/timer id is freed before invoking callback function
             *     - arg will missing in either one-shot or restart timer scenarios
             * (2) arg/timer id is freed after invoking callback function
             *     - previous arg/timer id buffer will cause memory leak,
             *       meanwhile new allocated buffer will be freed unexpectedly if this is a timer restart scenario
             * Therefore we handle buffer deallocate of timer restart case in gps_start_timer(),
             * and handle buffer deallocation of one-shot timer expiry case in gps_timer_expiry_callback()
             */
            
            /* reset flag before callback */
            gps_timer_table[timer_id].is_restart = KAL_FALSE;
            
            (gps_timer_table[timer_id].callback_func) (gps_timer_table[timer_id].arg);
    
            /* release buffer if it is not timer restart case; as for timer restart case,
             * gps_start_timer() will cover deallocation affairs
             */
            if (gps_timer_table[timer_id].is_restart == KAL_FALSE)
            {
                if (gps_timer_table[timer_id].timer_id_ptr != NULL)
                {   
                    free_ctrl_buffer(gps_timer_table[timer_id].timer_id_ptr);
                    gps_timer_table[timer_id].timer_id_ptr = NULL;
                }
                if (gps_timer_table[timer_id].arg != NULL)
                {
                    free_ctrl_buffer(gps_timer_table[timer_id].arg);
                    gps_timer_table[timer_id].arg = NULL;
                }
            }
        }
        else
        {
            GPS_TRACE((TRACE_GROUP_2, GPS_TIMER_TRC_IGNORE_TIMEOUT_ID, timer_id));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  gps_start_timer
 * DESCRIPTION
 *  start timer
 * PARAMETERS
 *  timer_id            [IN]      timer id  
 *  period              [IN]       period 
 *  timer_expiry        [IN]    delay time in ticks    
 *  arg                 [IN]      callback function parameter      
 * RETURNS
 *  void
 *****************************************************************************/
void gps_start_timer(kal_uint8 timer_id, kal_uint32 period, kal_timer_func_ptr timer_expiry, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 temp = kal_milli_secs_to_ticks(period);    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* check if any buffer is not released yet before allocate new one (timer restart),
     * also record this is a timer restart case or not
     */

    GPS_TRACE((TRACE_GROUP_2, GPS_TIMER_TRC_START_TIMER_ID, timer_id));

    gps_timer_table[timer_id].is_restart = KAL_FALSE;

    if (gps_timer_table[timer_id].timer_id_ptr != NULL)
    {
        free_ctrl_buffer(gps_timer_table[timer_id].timer_id_ptr);
        gps_timer_table[timer_id].timer_id_ptr = NULL;
        gps_timer_table[timer_id].is_restart = KAL_TRUE;
    }
    /* user should be aware that previous arg data will be lost after restart timer directly,
     * and is not allowed to manipulate previous arg buffer address */
    if (gps_timer_table[timer_id].arg != NULL)
    {
        free_ctrl_buffer(gps_timer_table[timer_id].arg);
        gps_timer_table[timer_id].arg = NULL;
        gps_timer_table[timer_id].is_restart = KAL_TRUE;
    }

    gps_timer_table[timer_id].timer_id_ptr = get_ctrl_buffer(sizeof(kal_uint32));
    kal_mem_set(gps_timer_table[timer_id].timer_id_ptr, 0, sizeof(kal_uint32));

    *(gps_timer_table[timer_id].timer_id_ptr) = (kal_uint32)timer_id;

    gps_timer_table[timer_id].callback_func = timer_expiry;
    gps_timer_table[timer_id].arg = arg;
    gps_timer_table[timer_id].event_id = evshed_set_event(
                                            gps_context_p->event_scheduler_ptr,
                                            (kal_timer_func_ptr) gps_timer_expiry_callback,
                                            (void*)gps_timer_table[timer_id].timer_id_ptr,
                                            temp /** KAL_TICKS_10_MSEC */ );
}


/*****************************************************************************
 * FUNCTION
 *  gps_stop_timer
 * DESCRIPTION
 *  stop timer
 * PARAMETERS
 *  timer_id        [IN]    timer id    
 * RETURNS
 *  void
 *****************************************************************************/
void gps_stop_timer(kal_uint8 timer_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    GPS_TRACE((TRACE_GROUP_2, GPS_TIMER_TRC_STOP_TIMER_ID, timer_id));

    if (gps_timer_table[timer_id].event_id != NULL)
    {
        evshed_cancel_event(gps_context_p->event_scheduler_ptr, &(gps_timer_table[timer_id].event_id));
        gps_timer_table[timer_id].event_id = NULL;

        gps_timer_table[timer_id].is_restart = KAL_FALSE;

        /* release timer id and arg buffer */
        if (gps_timer_table[timer_id].timer_id_ptr != NULL)
        {
            free_ctrl_buffer(gps_timer_table[timer_id].timer_id_ptr);
            gps_timer_table[timer_id].timer_id_ptr = NULL;
        }        
        if (gps_timer_table[timer_id].arg != NULL)
        {
            free_ctrl_buffer(gps_timer_table[timer_id].arg);
            gps_timer_table[timer_id].arg = NULL;
        }
    }
    else
    {
        GPS_TRACE((TRACE_GROUP_2, GPS_TIMER_TRC_ALREADY_STOP_TIMER_ID, timer_id));
    }
}
