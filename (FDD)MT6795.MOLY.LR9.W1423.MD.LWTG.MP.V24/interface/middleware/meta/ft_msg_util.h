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
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   ft_msg_util.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Messages definition of UTIL category of FT Library
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                 HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __FT_MSG_UTIL_H__
#define __FT_MSG_UTIL_H__
#include "ft_msg_common.h"

/*******************************************************************************
*
*  Message structures defined for utility command 
*
*******************************************************************************/

typedef enum {
FT_UTILCMD_CHECK_IF_FUNC_EXIST = 0
    ,FT_UTILCMD_CHECK_IF_ISP_SUPPORT
    ,FT_UTILCMD_QUERY_BT_MODULE_ID
    ,FT_UTILCMD_ENABLE_WATCHDOG_TIMER
    ,FT_UTILCMD_CHECK_IF_ACOUSTIC16_SUPPORT
    ,FT_UTILCMD_CHECK_IF_AUDIOPARAM45_SUPPORT
    ,FT_UTILCMD_CHECK_IF_LOW_COST_SINGLE_BANK_FLASH
    ,FT_UTILCMD_QUERY_PMIC_ID
    ,FT_UTILCMD_BT_POWER_ON
    ,FT_UTILCMD_LED_LIGHT_LEVEL
    ,FT_UTILCMD_VIBRATOR_ONOFF
    ,FT_UTILCMD_QUERY_LOCAL_TIME
    ,FT_UTILCMD_CHECK_IF_WIFI_ALC_SUPPORT
    ,FT_UTILCMD_RF_ITC_PCL
    ,FT_UTILCMD_CHECK_IF_DRC_SUPPORT
    ,FT_UTILCMD_CHECK_IF_BT_POWERON
    ,FT_UTILCMD_MAIN_SUB_LCD_LIGHT_LEVEL
    ,FT_UTILCMD_CHECK_IF_ULC_FAT_SUPPORT
    ,FT_UTILCMD_CHECK_IF_SMART_PHONE_MODEM_SUPPORT
    ,FT_UTILCMD_CHECK_TARGET_META_REQUIRED_VERS
    ,FT_UTILCMD_SET_TARGET_CHECK_PARAS
    //-------------- check if target need to perform NVRAM read/write security check
    ,FT_UTILCMD_CHECK_IF_TARGET_NV_SEC_ON
    ,FT_UTILCMD_REBOOT_TO_NORMAL_MODE // reboot target to normal mode
    ,FT_UTILCMD_QUERY_BT_WIFI_SINGLE_ANTENNA_CAP
    ,FT_UTILCMD_SET_ANTENNA_PATH_TO_BT
    ,FT_UTILCMD_SET_ANTENNA_PATH_TO_WIFI
    ,FT_UTILCMD_QUERY_TARGET_OPTION_INFO
    ,FT_UTILCMD_QUERY_LIMITED_STATE
    ,FT_UTILCMD_QUERY_VPA_VOLTAGE_LIST
    ,FT_UTILCMD_QUERY_DRIVE_AVAILABLE_FOR_FILE_SIZE
    ,FT_UTILCMD_QUERY_MAX_CTRL_BUFFER_SIZE
    ,FT_UTILCMD_QUERY_ADC_MODULE_SUPPORT
    ,FT_UTILCMD_QUERY_RTC_MODULE_SUPPORT
    ,FT_UTILCMD_QUERY_META_MODE_TRACE
    ,FT_UTILCMD_ENABLE_META_MODE_TRACE    
    ,FT_UTILCMD_END
} FtUtilCmdType;

typedef struct {
    kal_uint32        query_ft_msg_id;
    kal_uint32        query_op_code;
} FtUtilCheckIfFuncExist;

typedef struct {
    kal_uint8        led_light_level;
} FtLEDLevel;

typedef struct {
    kal_uint8        lcd_type;
    kal_uint8        lcd_light_level;
} FtLCDLevel;

typedef struct {
    kal_uint8        onoff;
} FtVibratorOnOff;

typedef struct {
    kal_uint16        interval;
} FtWatchDog;


typedef enum 
{
    META_VERSION_USER_DEFINE
   ,META_VERSION_META_DLL_UTIL_VER
   ,META_VERSION_TYPE_END
}META_VERSION_TYPE;

typedef struct 
{
    META_VERSION_TYPE   m_eVerType;
    kal_bool            b_AssertWhenVerCheckFail;  
    kal_uint32          m_u4MainVersion;  
    kal_uint32          m_u4MinorVersion; 
    kal_uint32          m_u4BuildNum;     
}META_UTIL_CHECK_TARGET_VER_REQ_T;


typedef struct 
{ 
    kal_bool    m_bCheckPass;
    kal_uint32  m_u4TargetMainVersion;  
    kal_uint32  m_u4TargetMinorVersion;
    kal_uint32  m_u4TargetBuildNum;   
}META_UTIL_CHECK_TARGET_VER_CNF_T;  // store in peer buffer  for backward compaibility

typedef struct 
{
    kal_bool   b_TargetAssertCheckFlag;
    kal_bool   b_SetCurRecvMsgTimes;
    kal_uint8  m_u1CurRecvMsgTimes;  
}META_UTIL_SET_ASSERT_CHECK_PARAs_REQ_T;


typedef union {
    FtUtilCheckIfFuncExist                  CheckIfFuncExist;
    FtWatchDog                              WatchDog;
    FtLEDLevel                              LEDLevel;
    FtLCDLevel                              LCDLevel;
    FtVibratorOnOff                         VibrOnOff;
    META_UTIL_CHECK_TARGET_VER_REQ_T        m_rCheckMetaVerReq;
    META_UTIL_SET_ASSERT_CHECK_PARAs_REQ_T  m_rSetPwrOffParasReq;
    kal_uint32                              dummy;        // extend alignment to 4 bytes
    kal_uint32                              requestedFileSize;
    kal_uint8                               trace_mode;
} FtUtilCmdReq_U;

typedef struct 
{
    kal_uint8        rtc_sec;    /* seconds after the minute   - [0,59]  */
    kal_uint8        rtc_min;    /* minutes after the hour     - [0,59]  */
    kal_uint8        rtc_hour;   /* hours after the midnight   - [0,23]  */
    kal_uint8        rtc_day;    /* day of the month           - [1,31]  */
    kal_uint8        rtc_mon;    /* months                        - [1,12] */
    kal_uint8        rtc_wday;   /* days in a week               - [1,7] */
    kal_uint8        rtc_year;   /* years                      - [0,127] */
} FtRtc;

#define META_LIPTON_OPTION_ON   0x00000001
#define META_TC01_OPTION_ON     0x00000002
#define META_AST_TD_OPTION_ON   0x00000004
typedef union {
    FtUtilCheckIfFuncExist  CheckIfFuncExist;
    kal_uint8               bt_module_id;
    kal_uint8               pmic_id;
    FtRtc                   rtc;
    kal_uint32              rf_pcl;
    kal_bool                m_bNVSecOn;
    kal_bool                m_bBTWiFiSingleAntenna;
    kal_uint32              m_u4TargetOptionInfo;
    kal_uint32              dummy;// extend alignment to 4 bytes
    kal_uint32              m_u4LimitedStateIndicator;
    kal_int16               driveLetter;
    kal_uint32              maxControlBufferSize;
    kal_uint8               module_support;
    kal_uint8               trace_mode;    
} FtUtilCmdCnf_U;

typedef struct
{
    /// number of elements in the list
    kal_uint32 validNumber;
    /// voltage list (unit: micro volt 10^-6)
    kal_uint32 voltageList[255];
    /// register value of each voltageList
    kal_uint32 registerValue[255];
}FtUtilCmdCnfVpaVoltageList;

typedef struct {
    FT_H            header;
    FtUtilCmdType   type;
    FtUtilCmdReq_U  cmd;
} FT_UTILITY_COMMAND_REQ;

typedef struct {
    FT_H            header;
    FtUtilCmdType   type;
    FtUtilCmdCnf_U  result;
    kal_uint32      status;
} FT_UTILITY_COMMAND_CNF;

#endif // #ifndef __FT_MSG_UTIL_H__
