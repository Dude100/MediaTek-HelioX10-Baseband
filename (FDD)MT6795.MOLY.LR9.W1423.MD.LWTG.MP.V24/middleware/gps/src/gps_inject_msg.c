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
 *  gps_inject_msg.c
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
#ifdef __GPS_SUPPORT__
#include <stdio.h>
#include "kal_trace.h"
#include "kal_public_api.h"
#include "tst_sap.h"
#include "dcl.h"
#include "gps_init.h"
#include "gps_uart.h"            /* uart APIs*/
#include "gps_main.h"
#include "string.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "gps_agps_process.h"
#ifdef __MNL_SUPPORT__
 #include "mtk_gps_type.h" //MODEM_DEV_TEST remove  MNL head
#endif

#include "gps_common.h"
#include "gps_trc.h"
        
#ifdef UNIT_TEST
extern kal_uint16 gps_command_bsize;
extern kal_uint8 *gps_command_buffer;
extern kal_bool g_gps_frame_sync_meas_req_by_ftime;
#if defined(__AGPS_SUPPORT__)
extern kal_uint8 area_event;
#endif
kal_bool is_initialization = KAL_FALSE;

#if defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__) || defined(__L1_GPS_REF_TIME_SUPPORT__)  
extern void gps_frame_sync_meas_req(mtk_gps_frame_sync_type_enum application_type); 
#endif
extern void gps_uart_enable_authentication(void);

#endif        
extern kal_uint8 gps_uart_port;
extern kal_uint8 gps_sleep_enable_flag;
extern kal_uint8 gps_power_saving_mode_flag;
extern kal_uint8 gps_power_saving_mode_type;
extern gps_context_struct *gps_context_p;//jiawang add for inject command to change uart baudrate
extern void gps_set_power_saving_mode(kal_uint8 mode);
extern void gps_send_check_id(void);
void gps_inject_frame_sync_power_on_handler(void);
void gps_inject_frame_sync_power_off_handler(void);
kal_uint32 frame_sync_power_on_time, frame_sync_power_off_time, frame_sync_test_count;    
kal_bool disable_stop_power_on_off_timer_flag =KAL_FALSE;

#ifdef __BEE_SUPPORT__
extern kal_int32 g_bEnableRandomBEE;
extern kal_int32 g_bRandomBEENumber;
extern void MTK_BEE_Enable_Eph_Update(void);
extern void MTK_BEE_Disable_Eph_Update(void);
#endif /* __BEE_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  gps_power_test_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_inject_power_test_handler(kal_char * inject_string)
{
    kal_uint32 power_flag;
	sscanf(inject_string, "%d", &power_flag); 
    if (1 == power_flag)
    {
        GPS_Init(NULL);
#ifndef __MNL_SUPPORT__
        kal_sleep_task(100);
        gps_send_check_id();
#endif
    }
    else
    {
        GPS_Shutdown();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gps_send_command_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_inject_send_command_handler(kal_char * inject_string)
{
    kal_uint8 checksum, inject_command[128]={0}, gps_command[128]={0};
    kal_uint32 i, length;
    sscanf(inject_string, "%s", (char *)&inject_command); 
    length = strlen((const char *)inject_command);
    checksum = 0;
    for (i = 0; i < length; i++)
    {
        checksum ^= inject_command[i];
        gps_command[i + 1] = inject_command[i];
    }
    gps_command[0] = '$';
    gps_command[length + 1] = '*'; 
    if((checksum >> 4) > 9)
    {
        gps_command[length + 2] = (checksum >> 4) - 10  + 'A' ;
    }
    else
    {
        gps_command[length + 2] = (checksum >> 4) + '0';
    }
    if((checksum & 0xf) > 9)
    {
        gps_command[length + 3] = (checksum & 0xf) - 10 + 'A'; 
    }
    else
    {
        gps_command[length + 3] = (checksum & 0xf) + '0';
    }
    gps_command[length + 4] = 0x0D;
    gps_command[length + 5] = 0x0A;

    kal_print_string_trace(MOD_GPS, TRACE_FUNC, "%s", gps_command);

#ifdef UNIT_TEST
    memcpy (&gps_command_buffer, &gps_command, length + 6);
    gps_command_bsize = length + 6;
#else
    GPS_UART_Write(gps_uart_port, gps_command, length + 6);
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  gps_rx_limit_test_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_inject_rx_limit_test_handler(kal_char * inject_string)
{
    kal_uint8 checksum, gps_command[256]={0};
    char command[]= "PMTK999,83,00,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82";
    kal_uint32 i, length, count;
    sscanf(inject_string, "%d", &count); 
    length = strlen((const char *)command);
    checksum = 0;
    for (i = 0; i < length; i++)
    {
        checksum ^= command[i];
        gps_command[i + 1] = command[i];
    }
    gps_command[0] = '$';
    gps_command[length + 1] = '*'; 
    if((checksum >> 4) > 9)
    {
        gps_command[length + 2] = (checksum >> 4) - 10 + 'A';
    }
    else
    {
        gps_command[length + 2] = (checksum >> 4) + '0';
    }
    if((checksum & 0xf) > 9)
    {
        gps_command[length + 3] = (checksum & 0xf) - 10 + 'A'; 
    }
    else
    {
        gps_command[length + 3] = (checksum & 0xf) + '0';
    }
    gps_command[length + 4] = 0x0D;
    gps_command[length + 5] = 0x0A;

    kal_print_string_trace(MOD_GPS, TRACE_FUNC, "%s", gps_command);
    
    for (i = 0; i < count; i++)
    {
        GPS_UART_Write(gps_uart_port, gps_command, length + 6);    
    }
}


/*****************************************************************************
 * FUNCTION
 *  gps_uart_change_baudrate_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_inject_uart_change_baudrate_handler(kal_char * inject_string)
{
    kal_uint8 checksum, gps_command[128]={0};
    kal_uint32 i, length, baudrate;

    sscanf(inject_string, "%d", &baudrate); 
    if (gps_context_p->gps_state == GPS_POWERON_STATE)
    {
            
        if (1 == baudrate)
        {
            sprintf((char *)gps_command, "$PMTK170,420C,0060*");
        }
        else if (2 == baudrate)
        {
            sprintf((char *)gps_command, "$PMTK170,420C,0360*");
        }
        else if (3 == baudrate)
        {
            sprintf((char *)gps_command, "$PMTK170,420C,0260*");
        }
        else if (4 == baudrate)
        {
            sprintf((char *)gps_command, "$PMTK170,420C,0160*");
        }
        else
        {
            //jiawang add for deal with the fatal error(When command ==invalid)
            GPS_TRACE((TRACE_GROUP_1, GPS_INJECT_CMD_TRC_UART_BAUDRATE_SETTING_INVALID));
            return;        
        }
    
    length = strlen((const char *)gps_command);

    checksum = 0;
    for (i = 1; i < length - 1; i++)
    {
        checksum ^= gps_command[i];        
    }

        if((checksum >> 4) > 9)
        {
            gps_command[length] = (checksum >> 4) - 10 + 'A';
        }
        else
        {
            gps_command[length] = (checksum >> 4) + '0';
        }
        if((checksum & 0xf) > 9)
        {
            gps_command[length + 1] = (checksum & 0xf) - 10 + 'A'; 
        }
        else
        {
            gps_command[length + 1] = (checksum & 0xf) + '0';
        }
        gps_command[length + 2] = 0x0D;
        gps_command[length + 3] = 0x0A;

        GPS_UART_Write(gps_uart_port, gps_command, length + 4); 
        kal_print_string_trace(MOD_GPS, TRACE_FUNC, "%s", gps_command);
        kal_sleep_task(10);
        
    if (1 == baudrate)
    {
        GPS_SetUART(UART_BAUD_115200, FC_NONE);
    }
    else if (2 == baudrate)
    {
        GPS_SetUART(UART_BAUD_230400, FC_NONE);
    }
    else if (3 == baudrate)
    {
        GPS_SetUART(UART_BAUD_460800, FC_NONE);
    }
    else if (4 == baudrate)
    {
        GPS_SetUART(UART_BAUD_921600, FC_NONE);
        }
        else
        {
            //jiawang add for deal with the fatal error(When command ==invalid)
            return;        
        }
    }
    else{
        GPS_TRACE((TRACE_GROUP_1, GPS_INJECT_CMD_TRC_GPS_OPEN_NOTIFY));
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  gps_set_misc_variable
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_inject_set_misc_variable(kal_char * inject_string)
{
    kal_uint32 variable, value;
    sscanf(inject_string, "%d,%d", &variable, &value); 
    if (1 == variable)
    {
        gps_sleep_enable_flag = value;
    }
    else if (2 == variable)
    {
        gps_power_saving_mode_flag = value;
    }
    else if (3 == variable)
    {
        gps_power_saving_mode_type = value;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gps_set_misc_variable
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_inject_set_power_saving_mode_handler(kal_char * inject_string)
{
    kal_int32 mode;
    sscanf(inject_string, "%d", &mode); 
#ifdef __MNL_SUPPORT__    
    gps_set_power_saving_mode(mode);    
#endif /* __MNL_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  gps_inject_frame_sync_power_on_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gps_inject_frame_sync_power_on_handler(void)
{
    GPS_TRACE((TRACE_GROUP_1, GPS_INJECT_CMD_TRC_GPS_POWER_ON_OFF_OPEN_GPS));
    GPS_Init(NULL);    
    gps_start_timer(GPS_POWER_ON_OFF_TIMER, frame_sync_power_on_time, (kal_timer_func_ptr)gps_inject_frame_sync_power_off_handler, 0);                 
    GPS_TRACE((TRACE_GROUP_1, GPS_INJECT_CMD_TRC_GPS_POWER_ON_OFF_COUNT,frame_sync_power_on_time));
}


/*****************************************************************************
 * FUNCTION
 *  gps_inject_frame_sync_power_off_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gps_inject_frame_sync_power_off_handler(void)
{
    if (frame_sync_test_count > 0)    
    {
        GPS_TRACE((TRACE_GROUP_1, GPS_INJECT_CMD_TRC_GPS_POWER_ON_OFF_CLOSE_GPS));
        if (frame_sync_test_count ==1){
            GPS_Shutdown(); 
         }
        else{
            disable_stop_power_on_off_timer_flag =KAL_TRUE;
            GPS_Shutdown(); 
            gps_start_timer(GPS_POWER_ON_OFF_TIMER, frame_sync_power_off_time, (kal_timer_func_ptr)gps_inject_frame_sync_power_on_handler, 0);                 
        }
        GPS_TRACE((TRACE_GROUP_1, GPS_INJECT_CMD_TRC_GPS_POWER_ON_OFF_COUNT,frame_sync_power_on_time));
        frame_sync_test_count--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gps_inject_frame_sync_test_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_inject_frame_sync_test_handler(kal_char * inject_string)
{
    sscanf(inject_string, " %d , %d , %d ", &frame_sync_test_count, &frame_sync_power_on_time, &frame_sync_power_off_time); 
    gps_inject_frame_sync_power_on_handler();// modify from power off handler to power on handler 
    
}


/*****************************************************************************
 * FUNCTION
 *  gps_inject_frame_sync_test_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_inject_bee_test_handler(kal_char * inject_string)
{
#ifdef __BEE_SUPPORT__	
    kal_uint32 mode;
    sscanf(inject_string, "%d", &mode); 
    if (0 == mode)
    {
        MTK_BEE_Disable_Eph_Update();
    }
    else
    {
        MTK_BEE_Enable_Eph_Update();        
    }
#endif /* __BEE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  gps_inject_frame_sync_test_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_inject_bee_radom_sv_test_handler(kal_char * inject_string)
{
#ifdef  __BEE_SUPPORT__
    kal_uint32 mode, value;
    sscanf(inject_string, "%d,%d", &mode, &value); 
    if (0 == mode)
    {
        g_bEnableRandomBEE = 0;
    }
    else
    {
        g_bEnableRandomBEE = 1;        
    }
    if (value < 4)
    {
        g_bRandomBEENumber = 4;
    }
    else
    {
        g_bRandomBEENumber = value;
    }
#endif /* __BEE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  gps_inject_set_pos_report_deley_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gps_inject_set_pos_report_deley_handler(kal_char * inject_string)
{
/* only support in AGPS */
#if defined(__AGPS_SUPPORT__)
    kal_uint32 enable, delay_count;
    sscanf(inject_string, "%d,%d", &enable, &delay_count); 
	if (enable)
	{
		gps_agps_set_pos_report_deley(KAL_TRUE, delay_count);
	}
	else
	{
		gps_agps_set_pos_report_deley(KAL_FALSE, delay_count);
	}
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gps_tst_inject_string_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gps_tst_inject_string_handler( ilm_struct *ilm_ptr )
{
    tst_module_string_inject_struct* tst_inject = (tst_module_string_inject_struct*)ilm_ptr->local_para_ptr;
    if (1 == tst_inject->index)
    {
        gps_inject_power_test_handler((kal_char *)tst_inject->string);
    }
    else if (2 == tst_inject->index)
    {
        gps_inject_send_command_handler((kal_char *)tst_inject->string);        
    }
    else if (3 == tst_inject->index)
    {
        gps_inject_rx_limit_test_handler((kal_char *)tst_inject->string);    
    }
    else if (4 == tst_inject->index)
    {
        gps_inject_uart_change_baudrate_handler((kal_char *)tst_inject->string);    
    }
    else if (5 == tst_inject->index)
    {
        gps_inject_set_misc_variable((kal_char *)tst_inject->string);    
    }
    else if (6 == tst_inject->index)
    {
        gps_inject_set_power_saving_mode_handler((kal_char *)tst_inject->string);
    }
    else if (7 == tst_inject->index)
    {
        gps_inject_frame_sync_test_handler((kal_char *)tst_inject->string);
    }
    else if (8 == tst_inject->index)
    {
        gps_inject_bee_test_handler((kal_char *)tst_inject->string);
    }
    else if (9 == tst_inject->index)
    {
        gps_inject_bee_radom_sv_test_handler((kal_char *)tst_inject->string);
    }
	else if (10 == tst_inject->index)
    {
        gps_inject_set_pos_report_deley_handler((kal_char *)tst_inject->string);
    }
#ifdef UNIT_TEST
    else if (11 == tst_inject->index)
    {
        if(is_initialization == KAL_FALSE)
        {
            gps_uart_state_init();
        }
    }
    else if (12 == tst_inject->index)
    {
        gps_inject_send_command_handler((kal_char *)tst_inject->string);
        gps_uart_ready_to_read_ind(NULL);
    }
    else if (13 == tst_inject->index)
	{
        if (tst_inject->string[0] == 1)
            gps_debug_info_enable();
		else if(tst_inject->string[0] == 2)
            gps_debug_info_disable();

        if (tst_inject->string[1] == 1)
            gps_power_saving_mode_enable();
		else if(tst_inject->string[1] == 2)
            gps_power_saving_mode_disable();		
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        if (tst_inject->string[3] == 1)
            gps_logging_agent_enable();
        else if(tst_inject->string[3] == 2)
		    gps_logging_agent_disable();

        if (tst_inject->string[4] == 1)
            gps_logging_catcher_enable();
        else if(tst_inject->string[4] == 2)
            gps_logging_catcher_disable();

        if (tst_inject->string[5] == 1)
            gps_nmea_eng_sentence_enable();
        else if(tst_inject->string[5] == 2)
            gps_nmea_eng_sentence_disable();
		
        if (tst_inject->string[6] == 1)
            gps_set_hotstill_debug_mode(KAL_TRUE); //enable
        else if (tst_inject->string[6] == 2)
            gps_set_hotstill_debug_mode(KAL_FALSE); //disable

        if (tst_inject->string[7] == 1)
		    gps_set_hotstill_shutdown_mode(KAL_TRUE); //shutdown
        else if (tst_inject->string[7] == 2)
            gps_set_hotstill_shutdown_mode(KAL_FALSE); //resume

        if (tst_inject->string[8] == 1)
	          gps_uart_enable_authentication(); //shutdown

    }
    else if (14 == tst_inject->index)
	{
        gps_common_nmea_info_struct nmea_ptr;
		
        gps_get_nmea_location(tst_inject->string[0], &nmea_ptr);
    }
#ifndef __SMART_PHONE_MODEM__  
    else if (15 == tst_inject->index)
	{
        kal_uint8 buffer[257];
		kal_uint32 readed;

        gps_uart_read_data_dbg(tst_inject->string[0], buffer, 256, &readed);
		
    }
#endif
#if defined(__AGPS_SUPPORT__)
    else if (16 == tst_inject->index) //verify gps_agps_set_history_pos & gps_agps_get_history_pos
    {
        gps_pos_result_struct history_pos; 
        kal_uint16 bitmap;
        if(tst_inject->string[0] == 0)
        {
            gps_pos_qop_struct qop;
            gps_agps_get_history_pos(&qop,&history_pos, &bitmap);
        }
        else
        {
            gps_agps_set_pos_struct qop;
            memcpy(&qop, tst_inject->string, sizeof(gps_agps_set_pos_struct));
            gps_agps_set_history_pos(&qop);
        }
    }
#endif

#if defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__) || defined(__L1_GPS_REF_TIME_SUPPORT__)
    else if (17 == tst_inject->index) //send a frame sync meas request to issue a frame pulse
    {
        switch(tst_inject->string[0])
        {
            case 1:
                g_gps_frame_sync_meas_req_by_ftime = KAL_TRUE;
                gps_frame_sync_meas_req(0);
                break;
            case 2:
                g_gps_frame_sync_meas_req_by_ftime = KAL_FALSE;
                gps_frame_sync_meas_req(1);
                break;
            case 3:
                if (tst_inject->string[1] == MTK_GPS_FS_WORK_MODE_AIDING)
                {
                    g_gps_frame_sync_maintain_phase = KAL_FALSE;
                }
                else
                {
                    g_gps_frame_sync_maintain_phase = KAL_TRUE;
                }
                gps_frame_sync_meas_req(GPS_FRAME_SYNC_TYPE3);
                break;
            default:
                break;
        }
    }
#endif
#ifndef __SMART_PHONE_MODEM__  
	else if (18 == tst_inject->index) //simulate MDI callback function: gps_uart_read_data_nmea
	{
	    kal_uint8 buffer[257];
		kal_uint32 readed;
		
		gps_uart_read_data_nmea(MOD_MMI, tst_inject->string[0], buffer, 256, &readed);
	}
#endif
	else if (19 == tst_inject->index)  //simulate MDI gps_uart_write_gps_cmd
	{
	    gps_uart_write_gps_cmd(0, tst_inject->string[0], NULL);
	}
#if defined(__AGPS_SUPPORT__)
	else if (20 == tst_inject->index)  //AREA Event: shape and direction
	{
	   area_event = tst_inject->string[0];	   
	}
#endif
	else if (21 == tst_inject->index)  //send from MMI to GPS, GPS_UART_OPEN_SWITCH_REQ
	{
	   gps_uart_clear_on_broad_gps_nvram();   
	}
#endif
}

#endif /* __GPS_SUPPORT__ */
