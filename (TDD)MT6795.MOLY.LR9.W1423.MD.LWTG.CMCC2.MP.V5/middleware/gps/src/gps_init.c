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
 *  gps_init.c
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
#include "kal_public_defs.h"
#include "kal_public_api.h"

#include "dcl.h"
#include "eint.h"
#include "nvram_struct.h"           /* for NVRAM read/write */
#include "gps_struct.h"
#include "gps_uart.h"
#include "gps_main.h"
#include "gps_trc.h"
#include "string.h"                       
#include "sleepdrv_interface.h"                    

#ifdef __MNL_SUPPORT__
#include "mtk_gps_type.h" //MODEM_DEV_TEST remove  MNL head
#endif
 
#include "kal_general_types.h"
//#include "nvram_editor_data_item.h"
#include "nvram_data_items.h"
#include "nvram_interface.h"
#include "drvsignals.h"
#include "nvram_msgid.h"
#include "gps_msgid.h"
//#include "mnl_msgid.h"
#include "drv_sap.h"
        
typedef struct {
	unsigned char num_poweronGPS;
	unsigned char pol_poweronGPS;
	unsigned char num_standbyGPS;
	unsigned char pol_standbyGPS;
	unsigned char num_syncGPS;
	unsigned char mode_syncGPS;
	unsigned char num_lpoclk;
	unsigned char mode_lpoclk;
	unsigned char num_urxd;
	unsigned char num_utxd;
	unsigned char num_ucts;
	unsigned char num_urts;	
} sGPIO4GPS;

extern gps_context_struct *gps_context_p;
extern kal_uint32 gpsPowerOnTime;
extern kal_uint32 gpsPowerOffTime;
extern kal_uint32 gpsDataStartTime;
extern kal_uint32 gpsDataRXTime;
extern kal_uint32 gpsFixTime;
extern kal_bool disable_stop_power_on_off_timer_flag;


extern void GPS_AssignGpioPins(sGPIO4GPS *gpio);
extern kal_uint8 GPS_AssignEintPins(void);
extern void GPS_EINT_Handler(void);
extern void GPS_SetupGPIO(char val, unsigned char pin);
extern void GPS_InitGPIO(char val, unsigned char pin);
extern void GPS_WriteGPIO(char val, unsigned char pin);
extern void GPS_SetToGPIOMode(kal_uint8 pin);
extern void GPS_PowerOn(kal_uint8 polGPS, kal_uint8 numGPS);
extern void GPS_PowerOff(kal_uint8 polGPS, kal_uint8 numGPS);
extern kal_uint32 L1I_GetTimeStamp( void );

#ifdef __MNL_SUPPORT__

#include "mtk_gps.h"
#include "mtk_gps_task.h"

extern void mtk_gps_time_modification (DCL_RTC_DATA_T *new_tSysTime, DCL_RTC_DATA_T *pre_tSysTime, kal_int32 first_time_flag);
extern void mtk_gps_shutdown(void);

extern mtk_gps_task_struct *mtk_gps_context_p;
extern kal_uint8 mtk_gps_sleep_handle;
extern kal_eventgrpid gps_init_eventgrpid;
extern kal_bool gps_first_power_on_flag;
        
void GPS_MNL_Init(void);
void GPS_MNL_Shutdown(void);

nvram_ef_mnl_setting_data_struct mnl_nvram;

static sGPIO4GPS gpio;
#endif  /* __MNL_SUPPORT__ */

#define THIS_YEAR_LEAP_SECS  (14)
#define SECS_IN_WEEK         (604800)
kal_uint8 gps_eint_channel;
kal_uint8 gps_eint_debounce_enable;
#if defined(__SMART_PHONE_MODEM__)
kal_uint8 gps_uart_port = uart_port_gps_ccci;
#else
kal_uint8 gps_uart_port = uart_port2;
#endif
kal_uint8 mnl_port = 0;
kal_uint32 gps_uart_baudrate = 0;
kal_uint8 gps_urxd_mode = 1;
kal_uint8 gps_utxd_mode = 1;
kal_uint8 gps_urts_mode = 2;
kal_uint8 gps_ucts_mode = 2;
kal_uint8 gps_sleep_handle;

nvram_ef_gps_setting_data_struct gps_nvram;
kal_uint8 gps_send_utc_information_flag = 1;
kal_uint32 gps_tow_rms = 6000;
kal_uint32 gps_nvram_write_send_flag = 1;
kal_uint32 gps_nvram_write_cnf_flag = 1;

void (* Init_Callback) (kal_bool);
/*****************************************************************************
 * FUNCTION
 *  GPS_SetupGpioPins
 * DESCRIPTION
 *  Setup GPIO pins
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/    
#ifndef __SMART_PHONE_MODEM__
void GPS_SetupGpioPins(void)
{
    static kal_uint8 is_1st_init = 1;

    if (is_1st_init)
    {
        is_1st_init = 0;
        GPS_AssignGpioPins(&gpio);
        gps_eint_channel = GPS_AssignEintPins();
        if(gps_eint_channel != 0xff)
        {
            gps_eint_debounce_enable = 1;
            #if defined(MT6228) || defined(MT6229) || defined(MT6230)
                switch (gps_eint_channel)
                {
                    case 4:
                    case 5:
                    case 6:
                    case 7:
                        gps_eint_debounce_enable = 0;
                        break;            
                }
            #endif
            /* Register GPS_EINT_HISR handler */
            EINT_Registration( gps_eint_channel, 
                               KAL_FALSE,     /* DbounceEn */
                               KAL_TRUE,    /* ACTPolarity */
                               GPS_EINT_Handler,
                               KAL_FALSE      /* AutoUnmask */ );
            /* set new debounce value */
            #if defined (__MTK_TARGET__)
                EINTaddr(gps_eint_channel) |= (1 | EINT_CON_DEBOUNCE_EN);   
            #endif
            /* Set Software debounce time 0 */
            EINT_SW_Debounce_Modify(gps_eint_channel, 0);   
        }
    }

    // Set UART pins
    GPS_SetupGPIO(gps_urxd_mode, gpio.num_urxd);
    GPS_SetupGPIO(gps_utxd_mode, gpio.num_utxd);
    if (gpio.num_ucts != 0xFF)
    {
	GPS_SetupGPIO(gps_ucts_mode, gpio.num_ucts);
	GPS_SetupGPIO(gps_urts_mode, gpio.num_urts);
    }  
    if (gps_eint_channel != 0xFF)
    {
        EINT_Mask(gps_eint_channel);
    }  
}
#endif /* NOT__SMART_PHONE_MODEM__ */

/*****************************************************************************
 * FUNCTION
 *  gps_utc_to_gpstime
 * DESCRIPTION
 *  Convert UTC to GPS time format
 * PARAMETERS
 *  year           [IN]         
 *  mon            [IN]        
 *  day            [IN]         
 *  hour           [IN]  
 *  min            [IN]         
 *  sec            [IN]        
 *  wn             [OUT]         
 *  tow            [OUT] 
 * RETURNS
 *  void
 *****************************************************************************/    
void gps_utc_to_gpstime(kal_uint32  year,   // i  - Year
                        kal_uint8   mon,    // i  - Month: 1 ~ 12
                        kal_uint8   day,    // i  - Day: 1 ~ 31
                        kal_uint8   hour,   // i  - Hour: 0 ~ 23
                        kal_uint8   min,    // i  - Min: 0 ~ 59
                        kal_uint8   sec,    // i  - Sec
                        kal_int32*  wn,     // o  - GPS Week Number
                        double*     tow)    // o  - GPS Time of Week
{

#ifndef __MNL_SUPPORT__

   kal_int32 iYearsElapsed;     // Years since 1980.
   kal_int32 iDaysElapsed;      // Days elapsed since Jan 5/Jan 6, 1980.
   kal_int32 iLeapDays;         // Leap days since Jan 5/Jan 6, 1980.
   kal_int32 i;
   // Number of days into the year at the start of each month (ignoring leap years).
   kal_uint16 doy[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

   iYearsElapsed = year - 1980;

   i = 0;
   iLeapDays = 0;
   while (i <= iYearsElapsed)
   {
      if ((i % 100) == 20)
      {
         if ((i % 400) == 20)
         {
            iLeapDays++;
         }
      }
      else if ((i % 4) == 0)
      {
         iLeapDays++;
      }
      i++;
   }

   /*  iLeapDays = iYearsElapsed / 4 + 1; */
   if ((iYearsElapsed % 100) == 20)
   {
      if (((iYearsElapsed % 400) == 20) && (mon <= 2))
      {
         iLeapDays--;
      }
   }
   else if (((iYearsElapsed % 4) == 0) && (mon <= 2))
   {
      iLeapDays--;
   }
   iDaysElapsed = iYearsElapsed * 365 + doy[mon - 1] + day + iLeapDays - 6;

   // Convert time to GPS weeks and seconds
   *wn = iDaysElapsed / 7;
   *tow = (double)(iDaysElapsed % 7) * 86400 + hour * 3600 + min * 60 + sec;

#endif  /* NOT __MNL_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  gps_set_nvram_gps_time
 * DESCRIPTION
 *  Sending gps time to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/ 
void gps_set_nvram_gps_time(void)
{

    nvram_write_req_struct* req;
    kal_uint8* pdu_ptr;
    kal_uint16 len;
    peer_buff_struct * peer_buff_ptr; 

    req = (nvram_write_req_struct*)construct_local_para(sizeof(nvram_write_req_struct), TD_RESET);
    req->file_idx = NVRAM_EF_GPS_SETTING_DATA_LID;
    req->para = 1;
    req->access_id = MOD_GPS;
    peer_buff_ptr = construct_peer_buff(NVRAM_EF_GPS_SETTING_DATA_SIZE, 0, 0, TD_CTRL);
    
    pdu_ptr = get_peer_buff_pdu(peer_buff_ptr, &len);
    kal_mem_cpy(pdu_ptr, &gps_nvram, NVRAM_EF_GPS_SETTING_DATA_SIZE);
    

    msg_send6(  MOD_GPS,
                MOD_NVRAM,
                GPS_MNL_SAP,
                MSG_ID_NVRAM_WRITE_REQ,
                (local_para_struct*)req,
                peer_buff_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  gps_clear_nvram_data
 * DESCRIPTION
 *  Clear NVRAM data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/ 
void gps_clear_nvram_data(void)
{
    /* Set GPS time invalid to NVRAM */            
    gps_nvram.gps_time_valid_flag = 0;
    gps_nvram.gps_clock_drift_valid_flag = 0;
    gps_nvram_write_send_flag = 0;
    if (1 == gps_nvram_write_cnf_flag)
    {
        gps_nvram_write_send_flag = 1;
        gps_nvram_write_cnf_flag = 0;            
        gps_set_nvram_gps_time();
    }
}


/*****************************************************************************
 * FUNCTION
 *  GPS_UTC_Init
 * DESCRIPTION
 *  Sending UTC time to GPS module for hot start 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/ 
void GPS_UTC_Init(void)
{
#if defined(__SMART_PHONE_MODEM__)

#else

    kal_uint8 checksum, gps_command[255]={0};
    kal_int32 i, length, gps_wn, gsm_wn, diff_wn, age_tow;
    double gps_tow, gsm_tow, diff_tow;
    RTC_CTRL_GET_TIME_T gsm_time;
    RTC_CTRL_IS_MS_FIRSTPOWERON_T rtc_cmd_data;    
    /* handler for RTC Module */
    DCL_HANDLE rtc_handler; // It could be a global variable or a local variable
    static kal_uint8 first_poweron_flag = 1;
    
    /* Open a RTC handler to perform further operations */
	rtc_handler = DclRTC_Open(DCL_RTC, FLAGS_NONE);
    /* To check if RTC is the first poweron state */
#if defined (__MTK_TARGET__)
    DclRTC_Control(rtc_handler, RTC_CMD_IS_MS_FIRSTPOWERON, (DCL_CTRL_DATA_T *)&rtc_cmd_data);
    if ((KAL_TRUE == (kal_bool)rtc_cmd_data.fgMSFirstPowerOn) &&
        (1 == first_poweron_flag))
    {
        GPS_TRACE((TRACE_GROUP_5, GPS_RTC_TRC_FIRST_POWERON));
        first_poweron_flag = 0;
        /* Set GPS time invalid to NVRAM */            
        gps_clear_nvram_data();
    }
#else  /* NOT __MTK_TARGET__ */
    gps_nvram.gps_time_valid_flag = 0;
#endif  /* __MTK_TARGET__ */
    
    /* Utilize the time difference to calcuate the accurate UTC time */           
    if (1 != gps_nvram.gps_time_valid_flag ||
        0 == gps_send_utc_information_flag)
    {
        GPS_TRACE((TRACE_GROUP_5, GPS_RTC_TRC_UTC_INVALID_TIME));
        return;
    }

    /* Get GSM current RTC time */    
    //RTC_GetTime(&gsm_time);
    DclRTC_Control(rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *)&gsm_time);

    GPS_TRACE((TRACE_GROUP_5, GPS_RTC_TRC_GSM_CURRENT_TIME,
               gsm_time.u1Year + 2000,
               gsm_time.u1Mon, 
               gsm_time.u1Day, 
               gsm_time.u1Hour,
               gsm_time.u1Min, 
               gsm_time.u1Sec));

    /* Convert GSM current RTC time to the data format of GPS time */ 
    gsm_wn = gsm_tow = 0 ;
    gps_utc_to_gpstime(gsm_time.u1Year + 2000,
                       gsm_time.u1Mon,
                       gsm_time.u1Day,
                       gsm_time.u1Hour,
                       gsm_time.u1Min,
                       gsm_time.u1Sec,
                       &gsm_wn,
                       &gsm_tow);

    GPS_TRACE((TRACE_GROUP_5, GPS_RTC_TRC_GSM_CURRENT_GPS_TIME,
               gsm_wn,
               gsm_tow));    

    diff_wn = gps_nvram.gps_diff_wn;
    diff_tow = gps_nvram.gps_diff_tow;

    GPS_TRACE((TRACE_GROUP_5, GPS_RTC_TRC_DIFF_CURRENT_GPS_TIME,
               diff_wn,
               diff_tow)); 
    
    /* Utilize the time difference to calcuate the accurate UTC time */        
    gps_wn = gsm_wn + diff_wn;
    gps_tow = gsm_tow + diff_tow;    
    
    /* We must compensate leaps seconds to get correct GPS time*/    
    gps_tow += THIS_YEAR_LEAP_SECS;

    /* We must check the limit of correct GPS time*/    
    if ((gps_wn < 0) ||
        (gps_tow + SECS_IN_WEEK < 0) ||
        (gps_tow - SECS_IN_WEEK > SECS_IN_WEEK))
    {
        GPS_TRACE((TRACE_GROUP_5, GPS_RTC_TRC_UTC_INVALID_TIME));
        return;
    }

    /* We must check the limit of correct GPS time*/    
    if (gps_tow >= SECS_IN_WEEK)
    {
        gps_wn += 1;
        gps_tow -= SECS_IN_WEEK;
    }
    else if(gps_tow < 0)
    {
        gps_wn -= 1;
        gps_tow += SECS_IN_WEEK;
    }

    GPS_TRACE((TRACE_GROUP_5, GPS_RTC_TRC_GPS_CURRENT_GPS_TIME,
               gps_wn,
               gps_tow)); 
    
    /* Utilize the time difference to calcuate the accurate UTC time */           
    sprintf((char *)gps_command, "$PMTK712,%d,%f,%d*", gps_wn, gps_tow, gps_tow_rms);
    
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
    // If we use GSM gpio as 32k source, we need to send UTC time to GPS module
#ifndef __MNL_SUPPORT__
    if(gpio.num_lpoclk != 0xFF)
    {
        kal_print_string_trace(MOD_GPS, TRACE_FUNC, "gps_command=%s", gps_command);       
#ifdef UNIT_TEST
        {
           gps_ut_write_data_ind_struct *local_ptr;
           
           local_ptr = (gps_ut_write_data_ind_struct *)construct_local_para(sizeof(gps_ut_write_data_ind_struct), TD_RESET);
           memcpy(&local_ptr->data_buffer, &gps_command, length + 4);
           
           gps_send_msg(MSG_ID_GPS_UT_WRITE_DATA_IND, MOD_GPS, local_ptr);
        }
#else
        GPS_UART_Write(gps_uart_port, gps_command, length + 4);  
#endif
    }
#endif  /* NOT __MNL_SUPPORT__ */
    
    /* Check the age of clock drift */
    kal_print_string_trace(MOD_GPS, TRACE_FUNC, "gps_clock_drift_wn=%d, gps_clock_drift_tow=%f, gps_clock_drift_age=%d", gps_nvram.gps_clock_drift_wn, gps_nvram.gps_clock_drift_tow ,gps_nvram.gps_clock_drift_age);
    /* Utilize the time difference to calcuate the accurate UTC time */           
    if (1 != gps_nvram.gps_clock_drift_valid_flag)
    {
        GPS_TRACE((TRACE_GROUP_5, GPS_RTC_TRC_UTC_INVALID_TIME));
        return;
    }
    if (gps_wn - gps_nvram.gps_clock_drift_wn >= 0 &&
        gps_wn - gps_nvram.gps_clock_drift_wn <= 1)
    {
        age_tow = (gps_wn - gps_nvram.gps_clock_drift_wn) * SECS_IN_WEEK +
                  gps_tow - gps_nvram.gps_clock_drift_tow  + 0.5 +
                  gps_nvram.gps_clock_drift_age;
        if ((age_tow >= SECS_IN_WEEK) ||
            (age_tow < 0))
        {
                GPS_TRACE((TRACE_FUNC, GPS_UTC_TRC_AGE_TOW_RANGE)); 
            return;
        }   
    }
    else
    {
         kal_print_string_trace(MOD_GPS, TRACE_FUNC, "gps_clock_drift_wn=%d, gps_clock_drift_tow=%f, gps_clock_drift_age=%d", gps_nvram.gps_clock_drift_wn, gps_nvram.gps_clock_drift_tow ,gps_nvram.gps_clock_drift_age);
         return;
    }
    sprintf((char *)gps_command, "$PMTK714,%0.3f,0,%d*", gps_nvram.gps_clock_drift, age_tow);
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

    kal_print_string_trace(MOD_GPS, TRACE_FUNC, "gps_command=%s", gps_command);       
    
#ifdef UNIT_TEST
    {
       gps_ut_write_data_ind_struct *local_ptr;
               
       local_ptr = (gps_ut_write_data_ind_struct *)construct_local_para(sizeof(gps_ut_write_data_ind_struct), TD_RESET);
       memcpy(&local_ptr->data_buffer, &gps_command, length + 4);
               
       gps_send_msg(MSG_ID_GPS_UT_WRITE_DATA_IND, MOD_GPS, local_ptr);
    }
#else
    GPS_UART_Write(gps_uart_port, gps_command, length + 4);      
#endif    
#endif /* __SMART_PHONE_MODEM__ */
}


/*****************************************************************************
 * FUNCTION
 *  GPS_Calibrate_RTC
 * DESCRIPTION
 *  Calibrate GSM RTC by GPS NMEA information
 * PARAMETERS
 *  year           [IN]         
 *  mon            [IN]        
 *  day            [IN]         
 *  hour           [IN]  
 *  min            [IN]         
 *  sec            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/   
void GPS_Calibrate_RTC(kal_uint8  year,   // i  - Year
                       kal_uint8  mon,    // i  - Month: 1 ~ 12
                       kal_uint8  day,    // i  - Day: 1 ~ 31
                       kal_uint8  hour,   // i  - Hour: 0 ~ 23
                       kal_uint8  min,    // i  - Min: 0 ~ 59
                       kal_uint8  sec)    // i  - Sec: 0 ~ 60
{

#ifndef __MNL_SUPPORT__

    RTC_CTRL_GET_TIME_T gsm_time;
    /* handler for RTC Module */
    DCL_HANDLE rtc_handler; // It could be a global variable or a local variable
    kal_int32 gps_wn, gsm_wn, diff_wn;
    double gps_tow, gsm_tow, diff_tow;
    
    /* Open a RTC handler to perform further operations */
	rtc_handler = DclRTC_Open(DCL_RTC, FLAGS_NONE);
    /* Get GSM current RTC time */    
    //RTC_GetTime(&gsm_time);
    DclRTC_Control(rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *)&gsm_time);

    GPS_TRACE((TRACE_GROUP_5, GPS_RTC_TRC_CALIBRATE_RTC));        
    GPS_TRACE((TRACE_GROUP_5, GPS_RTC_TRC_GSM_CURRENT_TIME,
               gsm_time.u1Year + 2000,
               gsm_time.u1Mon, 
               gsm_time.u1Day, 
               gsm_time.u1Hour,
               gsm_time.u1Min, 
               gsm_time.u1Sec));

    /* Convert GSM current RTC time to the data format of GPS time */    
    gsm_wn = gsm_tow = 0 ;    
    gps_utc_to_gpstime(gsm_time.u1Year + 2000,
                       gsm_time.u1Mon,  
                       gsm_time.u1Day,  
                       gsm_time.u1Hour, 
                       gsm_time.u1Min,  
                       gsm_time.u1Sec,
                       &gsm_wn,
                       &gsm_tow);


    GPS_TRACE((TRACE_GROUP_5, GPS_RTC_TRC_GSM_CURRENT_TIME,
               gsm_wn,
               gsm_tow));

    GPS_TRACE((TRACE_GROUP_5, GPS_RTC_TRC_GPS_CURRENT_TIME,
               year + 2000,
               mon, 
               day, 
               hour,
               min, 
               sec));

    /* Convert GPS current UTC time to the data format of GPS time */    
    gps_utc_to_gpstime(year + 2000,
                       mon,
                       day,
                       hour,
                       min,
                       sec,
                       &gps_wn,
                       &gps_tow);

    GPS_TRACE((TRACE_GROUP_5, GPS_RTC_TRC_GPS_CURRENT_GPS_TIME,
               gsm_wn,
               gsm_tow));

    /* Calculate time difference between GSM and GPS */        
    diff_wn = gps_wn - gsm_wn;
    diff_tow = gps_tow - gsm_tow; 
   
    GPS_TRACE((TRACE_GROUP_5, GPS_RTC_TRC_DIFF_CURRENT_GPS_TIME,
               diff_wn,
               diff_tow));

    gps_nvram.gps_time_valid_flag = 1;
    gps_nvram.gps_diff_wn = diff_wn;
    gps_nvram.gps_diff_tow = diff_tow;

    /* Set the flag to check if we send to NVRAM */            
    gps_nvram_write_send_flag = 0;
        
    /* Save the time difference to NVRAM */        
    if (1 == gps_nvram_write_cnf_flag)
    {
        gps_nvram_write_send_flag = 1;        
        gps_nvram_write_cnf_flag = 0;        
        gps_set_nvram_gps_time();
    }   
     /* GPS Fix Time */        
    gpsFixTime = L1I_GetTimeStamp();

#endif  /* NOT __MNL_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  GPS_Calibrate_Clock_Drift
 * DESCRIPTION
 *  Calibrate GSM Clock Drift by GPS NMEA information
 * PARAMETERS
 *  year           [IN]         
 *  mon            [IN]            
 * RETURNS
 *  void
 *****************************************************************************/   
void GPS_Calibrate_Clock_Drift(double clock_drift, kal_uint32 age)   
{
    kal_int32 gps_wn, gsm_wn, diff_wn;
    double gps_tow, gsm_tow, diff_tow;
    RTC_CTRL_GET_TIME_T gsm_time;
    /* handler for RTC Module */
    DCL_HANDLE rtc_handler; // It could be a global variable or a local variable

    /* Utilize the time difference to calcuate the accurate UTC time */           
    if (1 != gps_nvram.gps_time_valid_flag)        
    {
        GPS_TRACE((TRACE_FUNC,GPS_UTC_TRC_CALIBRATE_CLOCK_DRIFT_FAIL));
        return;
    }

    /* Open a RTC handler to perform further operations */
	rtc_handler = DclRTC_Open(DCL_RTC, FLAGS_NONE);
    /* Get GSM current RTC time */    
    //RTC_GetTime(&gsm_time);
    DclRTC_Control(rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *)&gsm_time);

    GPS_TRACE((TRACE_GROUP_5, GPS_RTC_TRC_GSM_CURRENT_TIME,
               gsm_time.u1Year + 2000,
               gsm_time.u1Mon,  
               gsm_time.u1Day,  
               gsm_time.u1Hour, 
               gsm_time.u1Min,  
               gsm_time.u1Sec));

    /* Convert GSM current RTC time to the data format of GPS time */  
    gsm_wn = gsm_tow = 0 ;          
    gps_utc_to_gpstime(gsm_time.u1Year + 2000,
                       gsm_time.u1Mon,  
                       gsm_time.u1Day,  
                       gsm_time.u1Hour, 
                       gsm_time.u1Min,  
                       gsm_time.u1Sec,
                       &gsm_wn,
                       &gsm_tow);

    GPS_TRACE((TRACE_GROUP_5, GPS_RTC_TRC_GSM_CURRENT_GPS_TIME,
               gsm_wn,
               gsm_tow));    

    diff_wn = gps_nvram.gps_diff_wn;
    diff_tow = gps_nvram.gps_diff_tow;

    GPS_TRACE((TRACE_GROUP_5, GPS_RTC_TRC_DIFF_CURRENT_GPS_TIME,
               diff_wn,
               diff_tow)); 
    
    /* Utilize the time difference to calcuate the accurate UTC time */        
    gps_wn = gsm_wn + diff_wn;
    gps_tow = gsm_tow + diff_tow;    
    
    /* We must compensate leaps seconds to get correct GPS time*/    
    gps_tow += THIS_YEAR_LEAP_SECS;

    /* We must check the limit of correct GPS time*/    
    if ((gps_wn < 0) ||
        (gps_tow + SECS_IN_WEEK < 0) ||
        (gps_tow - SECS_IN_WEEK > SECS_IN_WEEK))
    {
        GPS_TRACE((TRACE_GROUP_5, GPS_RTC_TRC_UTC_INVALID_TIME));
        return;
    }

    /* We must check the limit of correct GPS time*/    
    if (gps_tow >= SECS_IN_WEEK)
    {
        gps_wn += 1;
        gps_tow -= SECS_IN_WEEK;
    }
    else if(gps_tow < 0)
    {
        gps_wn -= 1;
        gps_tow += SECS_IN_WEEK;
    }

    GPS_TRACE((TRACE_GROUP_5, GPS_RTC_TRC_GPS_CURRENT_GPS_TIME,
               gps_wn,
               gps_tow)); 
    
    /* Save clock drift to NVRAM */
    gps_nvram.gps_clock_drift_valid_flag = 1;
    gps_nvram.gps_clock_drift = clock_drift;
    gps_nvram.gps_clock_drift_age = age;
    gps_nvram.gps_clock_drift_wn = gps_wn;
    gps_nvram.gps_clock_drift_tow = gps_tow;

    kal_print_string_trace(MOD_GPS, TRACE_FUNC, "clock_drift=%f, age=%d, gps_wn=%d, gps_tow=%f", clock_drift, age, gps_wn, gps_tow);
    /* Set the flag to check if we send to NVRAM */            
    gps_nvram_write_send_flag = 0;
        
    /* Save the time difference to NVRAM */        
    if (1 == gps_nvram_write_cnf_flag)
    {
        gps_nvram_write_send_flag = 1;        
        gps_nvram_write_cnf_flag = 0;        
        gps_set_nvram_gps_time();
    }   
}


/*****************************************************************************
 * FUNCTION
 *  GPS_Adjust_RTC_Diff
 * DESCRIPTION
 *  Adjust the difference according user modificatione
 * PARAMETERS
 *  void       
 * RETURNS
 *  status
 *****************************************************************************/   
void GPS_Adjust_RTC_Diff(ilm_struct *ilm_ptr)
{
#if defined(__SMART_PHONE_MODEM__)

#else


#ifdef __MNL_SUPPORT__

    rtc_gps_time_change_ind_struct *local_p;    
    static kal_uint8 first_poweron_flag = 1;
    RTC_CTRL_IS_MS_FIRSTPOWERON_T rtc_cmd_data;
    /* handler for RTC Module */
    DCL_HANDLE rtc_handler; // It could be a global variable or a local variable

    
    GPS_TRACE((TRACE_GROUP_5, GPS_RTC_TRC_ADJUST_RTC_DIFF));        
    local_p = (rtc_gps_time_change_ind_struct *)ilm_ptr->local_para_ptr;

    /* Open a RTC handler to perform further operations */
	rtc_handler = DclRTC_Open(DCL_RTC, FLAGS_NONE);
    /* To check if RTC is the first poweron state */
#if defined (__MTK_TARGET__)
    DclRTC_Control(rtc_handler, RTC_CMD_IS_MS_FIRSTPOWERON, (DCL_CTRL_DATA_T *)&rtc_cmd_data);
    if ((KAL_TRUE == (kal_bool)rtc_cmd_data.fgMSFirstPowerOn) &&
        (1 == first_poweron_flag))
    {
        mtk_gps_time_modification(&local_p->new_rtc, &local_p->previous_rtc, 1);
        first_poweron_flag = 0;
    }
    else
    {
        mtk_gps_time_modification(&local_p->new_rtc, &local_p->previous_rtc, 0);
    }
#else
    mtk_gps_time_modification(&local_p->new_rtc, &local_p->previous_rtc, 0);
#endif  /* __MTK_TARGET__ */
    
    
#else /* NOT __MNL_SUPPORT__ */

    rtc_gps_time_change_ind_struct *local_p; 
    kal_int32 previous_wn, new_wn;
    double previous_tow, new_tow;

    if (0 == gps_nvram.gps_time_valid_flag)
    {
        return;
    }
    GPS_TRACE((TRACE_GROUP_5, GPS_RTC_TRC_ADJUST_RTC_DIFF));        
    local_p = (rtc_gps_time_change_ind_struct *)ilm_ptr->local_para_ptr;
    GPS_TRACE((TRACE_FUNC, GPS_RTC_TRC_PREVIOUS_RTC,
    local_p->previous_rtc.u1Year + 2000,
    local_p->previous_rtc.u1Mon,  
    local_p->previous_rtc.u1Day,  
    local_p->previous_rtc.u1Hour, 
    local_p->previous_rtc.u1Min,  
    local_p->previous_rtc.u1Sec));

    /* Convert GSM previous RTC time to the data format of GPS time */    
    gps_utc_to_gpstime(local_p->previous_rtc.u1Year + 2000,
                       local_p->previous_rtc.u1Mon,  
                       local_p->previous_rtc.u1Day,  
                       local_p->previous_rtc.u1Hour, 
                       local_p->previous_rtc.u1Min,  
                       local_p->previous_rtc.u1Sec,
                       &previous_wn,
                       &previous_tow);
           
    GPS_TRACE((TRACE_FUNC, GPS_RTC_TRC_NEW_RTC,
    local_p->new_rtc.u1Year + 2000,
    local_p->new_rtc.u1Mon,  
    local_p->new_rtc.u1Day,  
    local_p->new_rtc.u1Hour, 
    local_p->new_rtc.u1Min,  
    local_p->new_rtc.u1Sec));

    /* Convert GSM previous RTC time to the data format of GPS time */    
    gps_utc_to_gpstime(local_p->new_rtc.u1Year + 2000,
                       local_p->new_rtc.u1Mon,  
                       local_p->new_rtc.u1Day,  
                       local_p->new_rtc.u1Hour, 
                       local_p->new_rtc.u1Min,  
                       local_p->new_rtc.u1Sec,
                       &new_wn,
                       &new_tow);
   
    gps_nvram.gps_diff_wn += previous_wn - new_wn;
    gps_nvram.gps_diff_tow += previous_tow - new_tow;    

    /* Set the flag to check if we send to NVRAM */            
    gps_nvram_write_send_flag = 0;
        
    /* Save the time difference to NVRAM */ 
    if (1 == gps_nvram_write_cnf_flag)
    {
        gps_nvram_write_send_flag = 1;        
        gps_nvram_write_cnf_flag = 0;              
        gps_set_nvram_gps_time();
    }      

#endif  /* __MNL_SUPPORT__ */

#endif /* __SMART_PHONE_MODEM__ */
}


#ifdef __MNL_SUPPORT__

#define __DSP_DOWNLOAD_SUPPORT__
#ifdef __DSP_DOWNLOAD_SUPPORT__
#include "fs_errcode.h"
#include "fs_type.h"
#include "fs_func.h"

#define DSP_BIN_MAX_SIZE (65536)
int iDSPDrvLetter;    
WCHAR DSPFilename[32];
kal_uint8 dsp_buffer[DSP_BIN_MAX_SIZE];
static FS_HANDLE hDSPHandle = -1;  /* nonvol file handle */

#endif /* __DSP_DOWNLOAD_SUPPORT__ */

void GPS_Register_RTC(void)
{
    DCL_HANDLE rtc_handler;
    DCL_STATUS rtc_status;
    RTC_CTRL_REGISTER_MODULE_ILM_INFO_T prRegisterILM;

    rtc_handler = DclRTC_Open(DCL_RTC, FLAGS_NONE);
    prRegisterILM.dest_mod_id = MOD_GPS;
    prRegisterILM.sap_id = RTC_GPS_SAP;
    prRegisterILM.msg_id = MSG_ID_RTC_GPS_TIME_CHANGE_IND;
    prRegisterILM.fgRegisterILM = DCL_FALSE;
    rtc_status = DclRTC_Control(rtc_handler, RTC_CMD_REGISTER_MODULE_TO_SEND_RTCTIME, (DCL_CTRL_DATA_T *)&prRegisterILM);
    DclRTC_Close(rtc_handler);
}
#ifdef __GPS_MT3326__

#define GPS_HW_CHECK_TIMES 5

void GPS_MNL_HW_Check(void)
{
    DCL_HANDLE handle;
    kal_uint8 status;    
    UART_CTRL_OPEN_T data;
    UART_CTRL_POWERON_T data2;
    UART_CTRL_PUT_BYTES_T data3;
    UART_CTRL_GET_BYTES_T data4;
    UART_CTRL_CLOSE_T data5;
	
	//  for 3326,  need to use query command 
    char gps_query_cmd[] = {0x04, 0x24, 0x0b, 0x00, 0x08, 0xff, 0x19, 0x00, 0xe5, 0x0d, 0x0a};
    char gps_query_ack[] = {0x04, 0x24, 0x0b, 0x00, 0x1d, 0xff, 0x01, 0xaa, 0x42, 0x0d, 0x0a};
    char gps_query_buf[32];
    kal_uint32 i, j;
    for (i = 0; i < GPS_HW_CHECK_TIMES; i++)
    {
        /* Power on GPS module */
        GPS_PowerOn(gpio.pol_poweronGPS, gpio.num_poweronGPS);	       
        if (gpio.num_syncGPS != 0xFF)	   // set gps sync pin
        {
            GPS_SetupGPIO(gpio.mode_syncGPS, gpio.num_syncGPS);
        }	
       
        if (gpio.num_lpoclk != 0xFF)	   // set lpo clk pin
        {
            GPS_SetupGPIO(gpio.mode_lpoclk, gpio.num_lpoclk);
        }              
        
        // We must wait for 200 ms to let DSP hardware ready
        kal_sleep_task(44);     
            
        data2.bFlag_Poweron = DCL_TRUE;
	      handle = DclSerialPort_Open(gps_uart_port, 0);
	      DclSerialPort_Control(handle, UART_CMD_POWER_ON, (DCL_CTRL_DATA_T*)&data2);	
	                    	
	      data.u4OwenrId = MOD_MNL;
	      handle = DclSerialPort_Open(gps_uart_port, 0);
   	    DclSerialPort_Control(handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*)&data);
   	        		
		    GPS_SetUART(UART_BAUD_38400, FC_NONE);
        gps_uart_baudrate = UART_BAUD_38400;
        
        data3.u4OwenrId = MOD_MNL;
	      data3.u2Length = sizeof(gps_query_cmd);
	      data3.puBuffaddr = (DCL_UINT8 *)gps_query_cmd;
	      handle = DclSerialPort_Open(gps_uart_port, 0);
	      DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data3);
	      
        kal_sleep_task(2);            
        
        data4.u4OwenrId = MOD_MNL;
	      data4.u2Length = 32;
	      data4.puBuffaddr = (DCL_UINT8 *)gps_query_buf;
	      data4.pustatus = &status;	        
	      handle = DclSerialPort_Open(gps_uart_port, 0);
	      DclSerialPort_Control(handle, SIO_CMD_GET_BYTES, (DCL_CTRL_DATA_T*)&data4);
	        
        if (!strncmp(gps_query_ack, gps_query_buf, sizeof(gps_query_ack)))
        {
            GPS_TRACE((TRACE_FUNC, GPS_TRC_MNL_HW_CHECK_SIZE,data4.u2RetSize));
            for (j = 0; j < data4.u2RetSize; j++)
            {
                GPS_TRACE((TRACE_FUNC, GPS_TRC_MNL_HW_CHECK_DATA,gps_query_buf[j]));
            }
            GPS_TRACE((TRACE_FUNC, GPS_TRC_MNL_HW_CHECK_OK));
            break;
        }    
		if (i != (GPS_HW_CHECK_TIMES - 1))
		{
        /* Power off GPS module */
        GPS_PowerOff(gpio.pol_poweronGPS, gpio.num_poweronGPS);              
        
        data5.u4OwenrId = MOD_MNL;
	    handle = DclSerialPort_Open(gps_uart_port, 0);
	    DclSerialPort_Control(handle, SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*)&data5);

        data2.bFlag_Poweron = DCL_FALSE;
	    handle = DclSerialPort_Open(gps_uart_port, 0);
	    DclSerialPort_Control(handle, UART_CMD_POWER_ON, (DCL_CTRL_DATA_T*)&data2);	        
		}
        GPS_TRACE((TRACE_FUNC, GPS_TRC_MNL_HW_CHECK_SIZE,data4.u2RetSize));
        for (j = 0; j < data4.u2RetSize; j++)
        {
            GPS_TRACE((TRACE_FUNC, GPS_TRC_MNL_HW_CHECK_DATA,gps_query_buf[j]));
        }    
        GPS_TRACE((TRACE_FUNC, GPS_TRC_MNL_HW_CHECK_FAIL)); 
    }
}

#else 
//jiawang modify for mt3336 power ON flow
void GPS_MNL_HW_Check(void)
{
        DCL_HANDLE handle;
        UART_CTRL_OPEN_T data;
        UART_CTRL_POWERON_T data2;

    {
        /* Power on GPS module */
        GPS_PowerOn(gpio.pol_poweronGPS, gpio.num_poweronGPS);	       
        if (gpio.num_syncGPS != 0xFF)   // set gps sync pin
        {
            GPS_SetupGPIO(gpio.mode_syncGPS, gpio.num_syncGPS);
        }	
        
       if (gpio.num_lpoclk != 0xFF)   // set lpo clk pin
        {
            GPS_SetupGPIO(gpio.mode_lpoclk, gpio.num_lpoclk);
        }                
        
        GPS_TRACE((TRACE_FUNC, GPS_TRC_MNL_HW_CHECK_32K_CLOCK,gpio.mode_lpoclk,gpio.num_lpoclk)); 
        // We must wait for 200 ms to let DSP hardware ready
        kal_sleep_task(44);  
            
        data2.bFlag_Poweron = DCL_TRUE;
        handle = DclSerialPort_Open(gps_uart_port, 0);
        DclSerialPort_Control(handle, UART_CMD_POWER_ON, (DCL_CTRL_DATA_T*)&data2);	
        data.u4OwenrId = MOD_MNL;
        handle = DclSerialPort_Open(gps_uart_port, 0);
        DclSerialPort_Control(handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*)&data);

        GPS_SetUART(UART_BAUD_115200, FC_NONE);
        gps_uart_baudrate = UART_BAUD_115200;//3336 Init_bandrate = 115200

    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  GPS_MNL_Init
 * DESCRIPTION
 *  Power on GPS module 
 * PARAMETERS
 *  void       
 * RETURNS
 *  status
 *****************************************************************************/  
void GPS_MNL_Init(void)
{    
    static kal_uint8 is_1st_init = 1;
    GPS_TRACE((TRACE_FUNC, GPS_TRC_MNL_INIT_GPS_STATUS,gps_context_p->gps_state));
    if (gps_context_p->gps_state != GPS_POWERON_STATE)
    {
        extern void Virtual_UART_Init(void);/*  20110809*/
        GPS_TRACE((TRACE_FUNC, GPS_TRC_MNL_INIT));
        if (is_1st_init)
        {
            is_1st_init = 0;
            mtk_gps_sleep_handle = SleepDrv_GetHandle();            
            GPS_Register_RTC();
            gps_first_power_on_flag = KAL_FALSE;
        }
		  Virtual_UART_Init();/*reset Ringbuff each time UART OPEN 20110809*/

		
        /* Step 1: read data from NVRAM */
        {
            nvram_external_read_data( NVRAM_EF_MNL_SETTING_DATA_LID, 1, (kal_uint8 *)&mnl_nvram, NVRAM_EF_MNL_SETTING_DATA_SIZE);
        }
        /* Step 2: setup GPIO */
        {
            GPS_SetupGpioPins();
        }
        /* Step 3: turn on GPS power */
        {
            GPS_MNL_HW_Check();                                      	             		
            SleepDrv_SleepDisable(mtk_gps_sleep_handle);    
            mtk_gps_context_p->gps_state = MNL_POWERON;
            gps_context_p->gps_state = GPS_POWERON_STATE;                 
            // MNL init   
            {
                mtk_init_cfg init_cfg;
                mtk_int32 init_status;

                memset(&init_cfg, 0x00, sizeof(mtk_init_cfg));
                init_cfg.if_type = MTK_IF_UART_NO_HW_FLOW_CTRL;	                // UART without HW flow control
                init_cfg.pps_mode = MTK_PPS_DISABLE;            // PPS disabled
                init_cfg.pps_duty = 100;                        // pps_duty (100ms high)
                init_cfg.if_link_spd = 921600;                  // normal UART baudrate 921600bps
                init_cfg.fix_interval = 1000;                   // 1Hz update rate
                init_cfg.datum = MTK_DATUM_WGS84;               // WGS84 datum
                
                #ifdef __GPS_MT3326__
                    init_cfg.if_init_spd = 38400;                       // initial UART baudrate 38400bps
                    init_cfg.Lat = 90.0;                                // initial latitude (degree)
                    init_cfg.Lon = 0.0;                                 // initial longitude (degree)                
                    init_cfg.agps_mode = MTK_AGPS_MODE_AUTO;            //MTK_AGPS_MODE_AUTO;
                    init_cfg.opmode = MTK_INITCFG_OPMODE_2D_FIRSTFIX;   // 2D first fix
                    init_cfg.elev_mask = 5;                             // elevation mask 5 degrees
                    init_cfg.sbas_prn = 0;                              // automatic selection of SBAS satellites
                    init_cfg.sbas_test_mode = MTK_GPS_FALSE;            // SBAS integrity mode        
                    init_cfg.internal_LNA = mnl_nvram.nvram_ef_mnl_setting_data[0]; // Use internal LNA or not, 0:not use, 1:use internal_LNA == Int_LNA_Config
                #else
                    init_cfg.Int_LNA_Config = mnl_nvram.nvram_ef_mnl_setting_data[0]; // Use internal LNA or not, 0:not use, 1:use
                #endif
                
                if (mnl_nvram.nvram_ef_mnl_setting_data[1] == 1)       // 0.5ppm TCXO
                {
                    #ifdef  __GPS_MT3326__
                        init_cfg.hw_TCXO_ppb = 500;         // 0336
                    #else
                        init_cfg.hw_Clock_Drift = 500;      //3326
                    #endif
                }
                else if (mnl_nvram.nvram_ef_mnl_setting_data[1] == 2)  // 2.0ppm TCXO
                {

                    #ifdef  __GPS_MT3326__
                        init_cfg.hw_TCXO_ppb = 2000;         // 0336
                    #else
                        init_cfg.hw_Clock_Drift = 2000;      //3326
                    #endif
                }
                else  // 2.5ppm TCXO
                {
                     
                    #ifdef  __GPS_MT3326__
                        init_cfg.hw_TCXO_ppb = 2500;         // 0336
                    #else
                        init_cfg.hw_Clock_Drift = 2500;      //3326
                    #endif
                }

                init_cfg.dgps_mode = (mtk_gps_dgps_mode)mnl_nvram.nvram_ef_mnl_setting_data[2];	// SBAS mode, default: off
                                
                if(0 == mnl_nvram.nvram_ef_mnl_setting_data[3]) // 16.368MHz TCXO  
                {  
                    #ifdef  __GPS_MT3326__
                        init_cfg.hw_TCXO_Hz= 16368000;         // not 3326 
                    #else
                        init_cfg.hw_Clock_Freq = 16368000;     // 3326
                    #endif
                    init_cfg.u1ClockType = 0x00;                                // USE TXCO 16.368MHz                                
                }
                else if(1 == mnl_nvram.nvram_ef_mnl_setting_data[3])
                {
                    #ifdef  __GPS_MT3326__
                        init_cfg.hw_TCXO_Hz = 26000000 + mnl_nvram.nvram_ef_mnl_setting_data[4] * 10;     // 3326
                    #else
                        init_cfg.hw_Clock_Freq= 26000000 + mnl_nvram.nvram_ef_mnl_setting_data[4] * 10;         // not 3326
                    #endif
                    init_cfg.u1ClockType = 0xFE; // xtal wide-range architecture                
                }
                else if(2 == mnl_nvram.nvram_ef_mnl_setting_data[3])
                {
                    #ifdef __GPS_MT3326__
                        init_cfg.hw_TCXO_Hz = 26000000 - mnl_nvram.nvram_ef_mnl_setting_data[4] * 10;    // 3326
                    #else
                        init_cfg.hw_Clock_Freq= 26000000 - mnl_nvram.nvram_ef_mnl_setting_data[4] * 10;        // not 3326
                    #endif
                    init_cfg.u1ClockType = 0xFE; // xtal wide-range architecture                
                }  

                #ifdef __GPS_MT3326__
                    #if defined(__L1_GPS_AUTO_TIMING_SYNC_SUPPORT__) || defined(__L1_GPS_REF_TIME_SUPPORT__)     
                        init_cfg.fgFrameAiding = MTK_GPS_TRUE; // mnl_nvram.nvram_ef_mnl_setting_data[5]; //MTK_GPS_FALSE; // default not use frame sync aiding
                    #else                                          
                        init_cfg.fgFrameAiding = MTK_GPS_FALSE; // mnl_nvram.nvram_ef_mnl_setting_data[5]; //MTK_GPS_FALSE; // default not use frame sync aiding
                    #endif   
                #endif

#ifdef __DSP_DOWNLOAD_SUPPORT__
                
                iDSPDrvLetter = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, 0);             
                if (iDSPDrvLetter > 0)
                {
                    kal_wsprintf(DSPFilename, "%c:\\gps_dsp.bin", iDSPDrvLetter);
                    hDSPHandle = FS_Open(DSPFilename, FS_READ_WRITE | FS_CREATE);
                    if (hDSPHandle >= 0)
                    {
                        kal_uint32 nRead;
                        int result;
                        
                        result = FS_Read(hDSPHandle, dsp_buffer, DSP_BIN_MAX_SIZE, &nRead);
                        if (result == 0)
                        {
                            init_cfg.reservedx = nRead;
                            init_cfg.reservedy = (void*)dsp_buffer;
                            GPS_TRACE((TRACE_FUNC, GPS_TRC_READ_GPS_DSP_BIN_SECCUSS));
                        }
                        else
                        {
                            GPS_TRACE((TRACE_FUNC, GPS_TRC_READ_GPS_DSP_BIN_FAIL));
                        }
                        FS_Close(hDSPHandle);
                        hDSPHandle = -1;                                        
                        
                    }
                    else
                    {
                        GPS_TRACE((TRACE_FUNC, GPS_TRC_READ_GPS_DSP_BIN_FAIL));
                    }                            
                }    
#endif /* __DSP_DOWNLOAD_SUPPORT__ */

                init_status = mtk_gps_init(MTK_GPS_START_DEFAULT, &init_cfg);
                #if __GPS_MT3326__
                    if (MTK_GPS_SUCCESS == init_status)                
                #else            
                    if (MNL_INIT_SUCCESS == init_status)
                #endif
                {                    
                    gps_uart_baudrate = UART_BAUD_921600;
                    SleepDrv_SleepEnable(mtk_gps_sleep_handle);  
                    if (gps_eint_channel != 0xFF)
                    {
                        EINT_UnMask(gps_eint_channel);
                    }
                    gpsPowerOnTime = L1I_GetTimeStamp();
                    gpsDataStartTime = L1I_GetTimeStamp();
                    gpsDataRXTime = L1I_GetTimeStamp();
                    GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_DISABLE_SLEEP,
                               gpsPowerOnTime));    
                    mtk_gps_context_p->gps_state = MNL_RUNNING;    
                    if (Init_Callback != NULL)
                    {
                        (* Init_Callback)(KAL_TRUE);
                    }
                    GPS_TRACE((TRACE_FUNC, GPS_TRC_MNL_INIT_OK));
                }
                else
                {
                    GPS_MNL_Shutdown();
                    if (Init_Callback != NULL)
                    {
                        (* Init_Callback)(KAL_FALSE);
                    }
                    GPS_TRACE((TRACE_FUNC, GPS_TRC_MNL_INIT_FAIL));
                }
            }                  
            kal_set_eg_events(gps_init_eventgrpid, GPS_INIT_FINISH_EVENT, KAL_OR);
        }
    }
}
#endif /* __MNL_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  GPS_Init
 * DESCRIPTION
 *  Power on GPS module 
 * PARAMETERS
 *  void       
 * RETURNS
 *  status
 *****************************************************************************/   
void GPS_Init(void (* callback)(kal_bool))
{
#if defined(__SMART_PHONE_MODEM__)

    DCL_HANDLE handle;
    UART_CTRL_PUT_BYTES_T data3;
    kal_char g_gps_cmd_power_on[] = "$PMTK997,1*29\x0d\x0a";
    
    data3.u4OwenrId = MOD_GPS;
	  data3.u2Length = sizeof(g_gps_cmd_power_on);
	  data3.puBuffaddr = (DCL_UINT8 *)g_gps_cmd_power_on;
	  handle = DclSerialPort_Open(gps_uart_port, 0);
	  DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data3);  
	                  
#else

#ifdef __MNL_SUPPORT__

    msg_send4(  MOD_GPS,
                MOD_MNL,
                GPS_MNL_SAP,
                MSG_ID_GPS_MNL_INIT_REQ);
    
    Init_Callback = callback;    
    /* Modify gps init to non-blocking mode */
    //kal_retrieve_eg_events(gps_init_eventgrpid, GPS_INIT_FINISH_EVENT, KAL_OR_CONSUME,
    //                       &event_group, KAL_SUSPEND);
    
#else /* NOT __MNL_SUPPORT__ */

    DCL_HANDLE handle;
    UART_CTRL_OPEN_T data;
    UART_CTRL_POWERON_T data2;	
            
    static kal_uint8 is_1st_init = 1;
    if (gps_context_p->gps_state != GPS_POWERON_STATE)
    {
        if (is_1st_init)
        {
            is_1st_init = 0;
            gps_sleep_handle = SleepDrv_GetHandle();
        }
        /* Step 1: setup GPIO */
        {
            GPS_SetupGpioPins();
        }
        /* Step 2: turn on GPS power */
        {
                          	             		
            /* Power on GPS module */
            GPS_PowerOn(gpio.pol_poweronGPS, gpio.num_poweronGPS);	            
            if (gpio.num_standbyGPS != 0xFF)   // set standby pin (no standby)
            {
                GPS_WriteGPIO(1 - gpio.pol_standbyGPS, gpio.num_standbyGPS);    // set ouput high
            }
            if (gpio.num_lpoclk != 0xFF)	   // set lpo clk pin
            {
                GPS_SetupGPIO(gpio.mode_lpoclk, gpio.num_lpoclk);
            }	
	        
            /* We must wait for 1 frame time to let UART RX hardware of GPS chip stable */
            kal_sleep_task(1);     
            
	        data2.bFlag_Poweron = DCL_TRUE;
	        handle = DclSerialPort_Open(gps_uart_port, 0);
	        DclSerialPort_Control(handle, UART_CMD_POWER_ON, (DCL_CTRL_DATA_T*)&data2);	
                        
	        data.u4OwenrId = MOD_GPS;
	        handle = DclSerialPort_Open(gps_uart_port, 0);
   	        DclSerialPort_Control(handle, SIO_CMD_OPEN, (DCL_CTRL_DATA_T*)&data);
   	        
   	        GPS_SetUART(UART_BAUD_115200, FC_NONE);
            gps_uart_baudrate = UART_BAUD_115200;
            
            if (gps_eint_channel != 0xFF)
            {
                EINT_UnMask(gps_eint_channel);
            }
            SleepDrv_SleepDisable(gps_sleep_handle);        
            gpsPowerOnTime = L1I_GetTimeStamp();
            gpsDataStartTime = L1I_GetTimeStamp();
            gpsDataRXTime = L1I_GetTimeStamp();
            GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_DISABLE_SLEEP,
                       gpsPowerOnTime));    
            	        
        }
        /* Step 3: read RTC information to GPS module */
        nvram_external_read_data(NVRAM_EF_GPS_SETTING_DATA_LID, 1, (kal_uint8 *)&gps_nvram, NVRAM_EF_GPS_SETTING_DATA_SIZE);
        
        gps_context_p->gps_state = GPS_POWERON_STATE;   

        if (callback != NULL)
        {
            (* callback)(KAL_TRUE);
        }   
        
    }

#endif /* __MNL_SUPPORT__ */

#endif /* __SMART_PHONE_MODEM__ */
}


/*****************************************************************************
 * FUNCTION
 *  GPS_StopTimer
 * DESCRIPTION
 *  Stop all GPS timer
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/ 
void GPS_StopTimer(void)
{
#ifdef __MNL_SUPPORT__
    mtk_gps_stop_timer(MTK_GPS_SLEEP_MODE_TIMER);
#endif
    // We need to close some gps module related timers
    gps_stop_timer(GPS_SLEEP_MODE_TIMER); 
    gps_stop_timer(GPS_UART_RING_BUFFER_EXP_TIMER); 
    gps_stop_timer(GPS_UART_POWER_ON_CHECK_VERSION_TIMER); 
    gps_stop_timer(GPS_UART_POWER_ON_CHECK_CHIP_ID_TIMER);     
    gps_stop_timer(GPS_UART_ENABLE_DEBUG_INFO_TIMER);     
    gps_stop_timer(GPS_UART_AUTHENTICATION_TIMER);  
    if(disable_stop_power_on_off_timer_flag == KAL_FALSE )
    {
        gps_stop_timer(GPS_POWER_ON_OFF_TIMER); 
    }
    GPS_TRACE((TRACE_FUNC, GPS_TRC_GPS_STOP_TIMER));
}


#ifdef __MNL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  GPS_MNL_Shutdown
 * DESCRIPTION
 *  Power off GPS module
 * PARAMETERS
 *  void       
 * RETURNS
 *  status
 *****************************************************************************/ 
void GPS_MNL_Shutdown(void)
{
    DCL_HANDLE handle;
	UART_CTRL_CLOSE_T data;
	UART_CTRL_POWERON_T data2;	
	
	GPS_StopTimer();        
    GPS_TRACE((TRACE_FUNC, GPS_TRC_MNL_SHUTDOWN_GPS_STATUS,gps_context_p->gps_state));
    if (gps_context_p->gps_state != GPS_POWEROFF_STATE)
    {
        GPS_TRACE((TRACE_FUNC, GPS_TRC_MNL_SHUTDOWN));
        gps_context_p->gps_state = GPS_POWEROFF_STATE; 
        mtk_gps_context_p->gps_state = MNL_POWEROFF;
        disable_stop_power_on_off_timer_flag = KAL_FALSE;
        

        #if 1//Hiki, call mtk_gps_update_gps_data to instead of mtk_gps_shutdown
        mtk_gps_update_gps_data();
        #else
/* under construction !*/
        #endif

        // set all IO pin to GPIO output mode & pull low     
        if(gpio.num_syncGPS != 0xFF)
        {
            GPS_InitGPIO(1, gpio.num_syncGPS);		// set direction (output)
            //GPS_SetupGPIO(0, gpio.num_syncGPS);	// set to gpio mode
            GPS_SetToGPIOMode(gpio.num_syncGPS);
            GPS_WriteGPIO(0, gpio.num_syncGPS);		// set ouput low
        }   
        
        GPS_InitGPIO(1, gpio.num_urxd);			// set direction (output)
        //GPS_SetupGPIO(0, gpio.num_urxd);		// set to gpio mode
        GPS_SetToGPIOMode(gpio.num_urxd);
        GPS_WriteGPIO(0, gpio.num_urxd);		// set ouput low
        
        GPS_InitGPIO(1, gpio.num_utxd);			// set direction (output)
        //GPS_SetupGPIO(0, gpio.num_utxd);		// set to gpio mode
        GPS_SetToGPIOMode(gpio.num_utxd);
        GPS_WriteGPIO(0, gpio.num_utxd);		// set ouput low    
        
        if(gpio.num_ucts != 0xFF)
        {
            GPS_InitGPIO(1, gpio.num_ucts);		// set direction (output)
            //GPS_SetupGPIO(0, gpio.num_ucts);		// set to gpio mode
            GPS_SetToGPIOMode(gpio.num_ucts);
            GPS_WriteGPIO(0, gpio.num_ucts);		// set ouput low
        
            GPS_InitGPIO(1, gpio.num_urts);		// set direction (output)
            //GPS_SetupGPIO(0, gpio.num_urts);		// set to gpio mode
            GPS_SetToGPIOMode(gpio.num_urts);
            GPS_WriteGPIO(0, gpio.num_urts);		// set ouput low
        }        
            
        {
            int n=500000;
            while (n) n--;
        }
        /* Power off GPS module */
        GPS_PowerOff(gpio.pol_poweronGPS, gpio.num_poweronGPS);    

	    data.u4OwenrId = MOD_MNL;
	    handle = DclSerialPort_Open(gps_uart_port, 0);
	    DclSerialPort_Control(handle, SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*)&data);

        data2.bFlag_Poweron = DCL_FALSE;
	    handle = DclSerialPort_Open(gps_uart_port, 0);
	    DclSerialPort_Control(handle, UART_CMD_POWER_ON, (DCL_CTRL_DATA_T*)&data2);	
	        
	    SleepDrv_SleepEnable(mtk_gps_sleep_handle);  
        if (gps_eint_channel != 0xFF)
        {
            EINT_Mask(gps_eint_channel);       
        }
        gpsPowerOffTime = L1I_GetTimeStamp();
        GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_ENABLE_SLEEP,
                   gpsPowerOffTime));               
        gps_context_p->gps_state = GPS_POWEROFF_STATE; 
        mtk_gps_context_p->gps_state = MNL_POWEROFF;  
        kal_set_eg_events(gps_init_eventgrpid, GPS_SHUTDOWN_FINISH_EVENT, KAL_OR);
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  GPS_Shutdown
 * DESCRIPTION
 *  Power off GPS module
 * PARAMETERS
 *  void       
 * RETURNS
 *  status
 *****************************************************************************/   
void GPS_Shutdown(void)
{
#if defined(__SMART_PHONE_MODEM__)

		DCL_HANDLE handle;
		UART_CTRL_PUT_BYTES_T data3;
    kal_char g_gps_cmd_power_off[] = "$PMTK997,0*28\x0d\x0a";
    
    data3.u4OwenrId = MOD_GPS;
	  data3.u2Length = sizeof(g_gps_cmd_power_off);
	  data3.puBuffaddr = (DCL_UINT8 *)g_gps_cmd_power_off;
	  handle = DclSerialPort_Open(gps_uart_port, 0);
	  DclSerialPort_Control(handle, SIO_CMD_PUT_BYTES, (DCL_CTRL_DATA_T*)&data3);  
            
#else

#ifdef __MNL_SUPPORT__
    
    msg_send4(  MOD_GPS,
                MOD_MNL,
                GPS_MNL_SAP,
                MSG_ID_GPS_MNL_INIT_REQ);

    /* Modify gps shutdown to non-blocking mode */
    //kal_retrieve_eg_events(gps_init_eventgrpid, GPS_SHUTDOWN_FINISH_EVENT, KAL_OR_CONSUME,
    //                       &event_group, KAL_SUSPEND);
#else /* NOT __MNL_SUPPORT__ */   

    DCL_HANDLE handle;
	UART_CTRL_CLOSE_T data;
	UART_CTRL_POWERON_T data2;
	
	GPS_StopTimer();
    if (gps_context_p->gps_state != GPS_POWEROFF_STATE)
    {
        // set all IO pin to GPIO output mode & pull low   
        if(gpio.num_standbyGPS != 0xFF)
        {
            GPS_InitGPIO(1, gpio.num_standbyGPS);	// set direction (output)
            //GPS_SetupGPIO(0, gpio.num_standbyGPS);	// set to gpio mode
            GPS_SetToGPIOMode(gpio.num_standbyGPS);
            GPS_WriteGPIO(0, gpio.num_standbyGPS);	// set ouput low
        }           
        GPS_InitGPIO(1, gpio.num_urxd);			// set direction (output)
        //GPS_SetupGPIO(0, gpio.num_urxd);		// set to gpio mode
        GPS_SetToGPIOMode(gpio.num_urxd);
        GPS_WriteGPIO(0, gpio.num_urxd);		// set ouput low
        
        GPS_InitGPIO(1, gpio.num_utxd);			// set direction (output)
        //GPS_SetupGPIO(0, gpio.num_utxd);		// set to gpio mode
        GPS_SetToGPIOMode(gpio.num_utxd);
        GPS_WriteGPIO(0, gpio.num_utxd);		// set ouput low    
        
        if(gpio.num_ucts != 0xFF)
        {
            GPS_InitGPIO(1, gpio.num_ucts);		// set direction (output)
            //GPS_SetupGPIO(0, gpio.num_ucts);		// set to gpio mode
            GPS_SetToGPIOMode(gpio.num_ucts);
            GPS_WriteGPIO(0, gpio.num_ucts);		// set ouput low
        
            GPS_InitGPIO(1, gpio.num_urts);		// set direction (output)
            //GPS_SetupGPIO(0, gpio.num_urts);		// set to gpio mode
            GPS_SetToGPIOMode(gpio.num_urts);
            GPS_WriteGPIO(0, gpio.num_urts);		// set ouput low
        }
        
        if(gpio.num_lpoclk != 0xFF)
        {
            GPS_InitGPIO(1, gpio.num_lpoclk);		// set direction (output)
            //GPS_SetupGPIO(0, gpio.num_lpoclk);	// set to gpio mode
            GPS_SetToGPIOMode(gpio.num_lpoclk);
            GPS_WriteGPIO(0, gpio.num_lpoclk);		// set ouput low
        }
            
        {
            int n=500000;
            while (n) n--;
        }
        /* Power off GPS module */
        GPS_PowerOff(gpio.pol_poweronGPS, gpio.num_poweronGPS);    
        
	    data.u4OwenrId = MOD_GPS;
	    handle = DclSerialPort_Open(gps_uart_port, 0);
	    DclSerialPort_Control(handle, SIO_CMD_CLOSE, (DCL_CTRL_DATA_T*)&data);
	    
        data2.bFlag_Poweron = DCL_FALSE;
	    handle = DclSerialPort_Open(gps_uart_port, 0);
	    DclSerialPort_Control(handle, UART_CMD_POWER_ON, (DCL_CTRL_DATA_T*)&data2);	
	        
        SleepDrv_SleepEnable(gps_sleep_handle); 
        if (gps_eint_channel != 0xFF)
        {
            EINT_Mask(gps_eint_channel);       
        }
        gpsPowerOffTime = L1I_GetTimeStamp();
        GPS_TRACE((TRACE_GROUP_4, GPS_SLEEP_TRC_ENABLE_SLEEP,
                   gpsPowerOffTime));               
        gps_context_p->gps_state = GPS_POWEROFF_STATE; 
    }    

#endif /* __MNL_SUPPORT__ */ 

#endif /* __SMART_PHONE_MODEM__ */

}


/*****************************************************************************
 * FUNCTION
 *  gps_nvram_write_cnf_handler
 * DESCRIPTION
 *  Complete the action after we get the confirm of NVRAM writing
 * PARAMETERS
 *  void       
 * RETURNS
 *  status
 *****************************************************************************/   
void gps_nvram_write_cnf_handler(ilm_struct *ilm_ptr)
{
    nvram_write_cnf_struct *cnf;
    cnf = (nvram_write_cnf_struct *)(ilm_ptr->local_para_ptr);
    if (0 == cnf->result)
    {
        gps_nvram_write_cnf_flag = 1;
        if (0 == gps_nvram_write_send_flag)
        {
            gps_nvram_write_send_flag = 1;
            gps_nvram_write_cnf_flag = 0;
            gps_set_nvram_gps_time();
        }
    }
}
#endif /* __GPS_SUPPORT__ */
