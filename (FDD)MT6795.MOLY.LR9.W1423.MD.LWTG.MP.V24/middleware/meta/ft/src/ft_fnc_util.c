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
 *   ft_fnc_util.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Factory testing function library (Category: Utility Commands)
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *              HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/*************************************************************************
* Include Statements for KAL
 *************************************************************************/
#include "ctrl_buff_pool.h"
#include "svc_sap.h"
#include "ft_msgid.h"
/**************************************************************************
 * HAL header
 *************************************************************************/
#include "dcl.h"
#include "device.h"
#include "drv_features.h"
#include "tst_def.h"
/**************************************************************************
 * FT header
 *************************************************************************/
#include "ft_msg.h"
#include "ft_private.h"
#include "ft_fnc_fat.h"
#include "ft_fnc_l1rf.h"
#include "ft_fnc_misc.h"
#include "ft_fnc_misc_ex.h"
#include "ft_fnc_wcdma.h"
#include "ft_fnc_lterf.h"
//20130206
#include "ft_fnc_tdscdma.h" 
kal_uint32 FT_UtilCheckFunctionSupported(kal_uint32 query_op_code);
/**************************************************************************
 * Custom header
 *************************************************************************/
#include "meta_customize.h"
#include "custom_equipment.h"

kal_uint32 FT_REQUIRED_META_DLL_MAIN_VER  =   6;
kal_uint32 FT_REQUIRED_META_DLL_MINOR_VER = 944;
kal_uint32 FT_REQUIRED_META_DLL_BUILD_NUM =   0;
kal_uint32 FT_REQUIRED_VERSION_UNKNOWN = 0xFFFFFFFF;
/*******************************************************************************
 *
 *  FAT functionality
 *
 *******************************************************************************/
/**
 * Get Path for requested size
 */
kal_int16 FT_GetAvailableDrive(kal_int32 size)
{
#if !defined(__LOW_COST_SUPPORT_ULC__)
    kal_int16 drv_letter       = -1;
    kal_int16 i                = 0;
    kal_uint32 dev[4]          = {FS_DRIVE_I_SYSTEM, FS_DRIVE_V_NORMAL, FS_DRIVE_V_REMOVABLE, FS_DRIVE_V_EXTERNAL};
    kal_wchar *pathname        = NULL;
    pathname = (kal_wchar*)get_ctrl_buffer(FT_FAT_MAX_FULLPATH);
    if(pathname)
    {
        for(i=0;i<4;i++)
        {
            drv_letter = FS_GetDrive(dev[i], 1, FS_NO_ALT_DRIVE);
            if(drv_letter > 0)
            {
                kal_wsprintf(pathname, "%c:\\", drv_letter);
                if(size < FT_GetDiskFreeSpace(pathname))
                {
                    break;
                }
            }
        }
    }
    else
    {
        ASSERT(0);
    }
    free_ctrl_buffer(pathname);
    return drv_letter;
#else // #if !defined(__LOW_COST_SUPPORT_ULC__)
    return -1;
#endif // #if defined(__LOW_COST_SUPPORT_ULC__)
}
/*************************************************************************
 * FUNCTION
 *  ft_get_ctrlbuf_max_size
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  0:    Could not target the maximal size
 *  else: maximal size supported.
 *
 * GLOBALS AFFECTED
 *
 *************************************************************************/
kal_uint32 ft_get_ctrlbuf_max_size( void )
{
	kal_int16   i=RPS_CREATED_CTRL_BUFF_POOLS-1;
	
	/* Total entries defined at adaptation\include\ctrl_buff_pool.h
	   RPS_CREATED_CTRL_BUFF_POOLS = 14
	   For each buffer associated with non-zero entries count, it should have been created,
	   and pool_id always non-zero. */
	while ( (ctrl_buff_pool_info_g[i].pool_id==0) && i )
	   i--;

	/* Somehow, if table corrupted, must return 0 */	   
	if ( i<0 )
	   return 0;
	   
   return (ctrl_buff_pool_info_g[i].size);
}

/*******************************************************************************
 *
 *  FT task check if function exist
 *
 *******************************************************************************/
kal_uint8  FT_UTIL_SendCnf(const FT_UTILITY_COMMAND_CNF  *cnf, peer_buff_struct *p_peer_buff) {

    ilm_struct   ilm_ptr;
    FT_UTILITY_COMMAND_CNF  *ptrMsg;

    FT_ALLOC_MSG(&ilm_ptr, sizeof(FT_UTILITY_COMMAND_CNF));

    // if ptrMsg != NULL
    ptrMsg = (FT_UTILITY_COMMAND_CNF *)ilm_ptr.local_para_ptr;

    // assign primitive id
    ptrMsg->header.ft_msg_id = FT_UTILITY_COMMAND_CNF_ID;

    // assign return structure
    ptrMsg->type = cnf->type;
    ptrMsg->result = cnf->result;
    ptrMsg->status = cnf->status;

    // assign peer buffer
    if( NULL != p_peer_buff ) {
        ilm_ptr.peer_buff_ptr = p_peer_buff;
    }

    FT_SEND_MSG_TO_PC(&ilm_ptr);
    return 0;
}
void ft_util_check_if_ulc_support(FT_UTILITY_COMMAND_CNF  *cnf)
{
#if defined(__LOW_COST_SUPPORT_ULC__)
    cnf->status = FT_CNF_OK;
#else
    cnf->status = FT_CNF_FAIL;
#endif
}
void ft_util_watch_dog_start(FT_UTILITY_COMMAND_REQ  *req, FT_UTILITY_COMMAND_CNF  *cnf,peer_buff_struct *peer_buff_ret)
{
    DCL_HANDLE dcl_wdt_handle;
    WDT_CTRL_SET_VALUE_T interval;
    WDT_CTRL_ENABLE_T enable;
    dcl_wdt_handle = DclWDT_Open(DCL_WDT, FLAGS_NONE);
    // set interval
    interval.u2Value = req->cmd.WatchDog.interval;
    DclWDT_Control(dcl_wdt_handle, WDT_CMD_SET_VALUE, (DCL_CTRL_DATA_T*)&interval);
    // send confirm first
    cnf->status = FT_CNF_OK;
    FT_UTIL_SendCnf(cnf,peer_buff_ret);
    kal_sleep_task(50);
    // disable all interrupt mask
    SaveAndSetIRQMask();
    // restart timer
    DclWDT_Control(dcl_wdt_handle, WDT_CMD_RESTART, 0);
    // enable watch dog count down
    enable.fgEnable = DCL_TRUE;
    DclWDT_Control(dcl_wdt_handle, WDT_CMD_ENABLE, (DCL_CTRL_DATA_T*)&enable);
    DclWDT_Close(dcl_wdt_handle);
    Custom_META_USBVirtualComDisconnect();
    while(1);
}

kal_int8 ft_util_check_if_func_exist(const FT_UTILITY_COMMAND_REQ  *req, FT_UTILITY_COMMAND_CNF  *cnf)
{
    kal_uint32  query_ft_msg_id = req->cmd.CheckIfFuncExist.query_ft_msg_id;
    kal_uint32  query_op_code = req->cmd.CheckIfFuncExist.query_op_code;
    cnf->status = FT_CNF_FAIL;
    switch(query_ft_msg_id) {
        case FT_REG_READ_ID:
        case FT_REG_WRITE_ID:
        case FT_IS_ALIVE_REQ_ID:
        case FT_POWER_OFF_REQ_ID:
        case FT_NVRAM_GET_DISK_INFO_REQ_ID:
        case FT_NVRAM_RESET_REQ_ID:
        case FT_NVRAM_LOCK_REQ_ID:
        case FT_NVRAM_READ_REQ_ID:
        case FT_NVRAM_WRITE_REQ_ID:
        case FT_VER_INFO_REQ_ID:
        case FT_ADC_GETMEADATA_ID:
        {
            cnf->status = FT_CNF_OK;
            break;
        }
#if !defined(__LTE_SM__)        
        case FT_RF_TEST_REQ_ID:
        {
            cnf->status = FT_L1RfCheckFunctionSuppported(query_op_code);
            break;
        }
#endif // #if !defined(__LTE_SM__)
#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
        case FT_URF_TEST_REQ_ID:
        {
            if(KAL_TRUE == UL1_IS_3G_FDD_EXIST())  //20130206
            {
            cnf->status = FT_UL1RfCheckFunctionSuppported(query_op_code);
            }
            else
            {
                cnf->status = FT_CNF_FAIL;
            }
            break;
        }
#endif // #if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
        case FT_FAT_OPERATION_ID:
            if( FT_FAT_OP_OPEN<=query_op_code && FT_FAT_OP_END>query_op_code ) {
                cnf->status = FT_CNF_OK;
            }
            break;
        case FT_UTILITY_COMMAND_REQ_ID:
        {
            cnf->status = FT_UtilCheckFunctionSupported(query_op_code);
            break;
        }
        case FT_MISC_CMD_REQ_ID:
        {
            cnf->status = FT_MiscCheckFunctionSupported(query_op_code);
            break;
        }
        case FT_MISC_EX_CMD_REQ_ID:
        {
            cnf->status = FT_MiscExCheckFunctionSupported(query_op_code);
            break;
        }
#if defined(__LTE_RAT__)&&defined(__TSTM_ENABLE__)
        case FT_ERF_TEST_REQ_ID:
        {
            FT_ErfCheckFunctionSupported(query_op_code);            
            return 1; // does not reply message immediately
        }
#endif // #if defined(__LTE_RAT__)&&defined(__TSTM_ENABLE__)
        default:
            cnf->status = FT_CNF_FAIL;
            break;
    }

    // assign return structure
    cnf->result.CheckIfFuncExist.query_ft_msg_id = query_ft_msg_id;
    cnf->result.CheckIfFuncExist.query_op_code = query_op_code;
    return 0;
}
#ifdef __NVRAM_SECRET_DATA__

void ft_util_get_target_nv_sec_on_flag(FT_UTILITY_COMMAND_CNF  *cnf)
{
    kal_uint8 key[256]; // at most 256 bytes
    kal_int32 real_key_len;

    real_key_len =  custom_nvram_get_database_key(key, sizeof(key));


    cnf->result.m_bNVSecOn = (real_key_len>0)? true: false;
    cnf->status = FT_CNF_OK;
}

#endif
void ft_util_check_if_isp_support(FT_UTILITY_COMMAND_CNF  *cnf) {
    /*
#if defined(ISP_SUPPORT) //&& !defined(YUV_SENSOR_SUPPORT)
cnf->status = FT_CNF_OK;
#else
cnf->status = FT_CNF_FAIL;
#endif
*/
    if(custom_ft_util_check_if_isp_support())
        cnf->status = FT_CNF_OK;
    else
        cnf->status = FT_CNF_FAIL;
}

void ft_util_check_if_smart_phone_modem_supported(FT_UTILITY_COMMAND_CNF *cnf)
{
#if defined(__SMART_PHONE_MODEM__)
    cnf->status = FT_CNF_OK;
#else
    cnf->status = FT_CNF_FAIL;
#endif
}
void ft_util_query_rtc(FT_UTILITY_COMMAND_CNF  *cnf)
{
    // HAL modification
    //RTC_GetTime(&cnf->result.rtc);
    DCL_HANDLE rtc_handle;
    RTC_CTRL_GET_TIME_T rtc_cmd_data3; // New Declaration
    cnf->status = FT_CNF_OK;
    rtc_handle = DclRTC_Open(DCL_RTC, FLAGS_NONE);
    if(DclRTC_Control(rtc_handle, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *)&rtc_cmd_data3) != STATUS_OK)
    {
        cnf->status = FT_CNF_FAIL;
    }
    cnf->result.rtc.rtc_year = rtc_cmd_data3.u1Year;
    cnf->result.rtc.rtc_wday = rtc_cmd_data3.u1WDay;
    cnf->result.rtc.rtc_mon = rtc_cmd_data3.u1Mon;
    cnf->result.rtc.rtc_day = rtc_cmd_data3.u1Day;
    cnf->result.rtc.rtc_hour = rtc_cmd_data3.u1Hour;
    cnf->result.rtc.rtc_min = rtc_cmd_data3.u1Min;
    cnf->result.rtc.rtc_sec = rtc_cmd_data3.u1Sec;
    DclRTC_Close(rtc_handle);
}
void ft_util_query_itc_pcl(FT_UTILITY_COMMAND_CNF  *cnf) {
    cnf->result.rf_pcl = L1D_RF_GetITC_PCL();
    cnf->status = FT_CNF_OK;
}
void ft_util_query_pmic_id(FT_UTILITY_COMMAND_CNF  *cnf)
{
    cnf->result.pmic_id = FT_MT6326;
    cnf->status = FT_CNF_OK;
}

void ft_util_set_led_light_level(FT_UTILITY_COMMAND_REQ  *req, FT_UTILITY_COMMAND_CNF  *cnf)
{
    kal_uint8   level=0;
    level=req->cmd.LEDLevel.led_light_level;
#if(!defined(__L1_STANDALONE__))
    if(custom_cfg_gpio_set_level(GPIO_DEV_LED_KEY,level))
        cnf->status = FT_CNF_OK;
    else
        cnf->status = FT_CNF_FAIL;
#endif
}
void ft_util_set_vibrator_onoff(FT_UTILITY_COMMAND_REQ  *req, FT_UTILITY_COMMAND_CNF  *cnf)
{
    kal_uint8   onoff=0;
    onoff=req->cmd.VibrOnOff.onoff;
#if(!defined(__L1_STANDALONE__))
    if(custom_cfg_gpio_set_level(GPIO_DEV_VIBRATOR,onoff))
        cnf->status = FT_CNF_OK;
    else
        cnf->status = FT_CNF_FAIL;
#endif
}
void ft_util_set_lcd_light_level(FT_UTILITY_COMMAND_REQ  *req, FT_UTILITY_COMMAND_CNF  *cnf)
{
    kal_uint8   level=0;
    kal_uint8 led_type;
#if(!defined(__L1_STANDALONE__))
    level=req->cmd.LCDLevel.lcd_light_level;
    led_type = req->cmd.LCDLevel.lcd_type;
    if(level>5) level = 5;
    if(led_type==0)
    {
        if(custom_cfg_gpio_set_level(GPIO_DEV_LED_MAINLCD,level))
            cnf->status = FT_CNF_OK;
        else
            cnf->status = FT_CNF_FAIL;
    }
    else if(led_type==1)
    {
        if(custom_cfg_gpio_set_level(GPIO_DEV_LED_SUBLCD,level))
            cnf->status = FT_CNF_OK;
        else
            cnf->status = FT_CNF_FAIL;

    }
#endif
}
void ft_util_check_vers(FT_UTILITY_COMMAND_REQ  *req, FT_UTILITY_COMMAND_CNF  *cnf, peer_buff_struct **pp_peer_buff_ret)
{
    META_UTIL_CHECK_TARGET_VER_CNF_T *p_dt = NULL;
    kal_uint16  pdu_length = 0;

    // allocate peer buffer
    *pp_peer_buff_ret = construct_peer_buff(sizeof(META_UTIL_CHECK_TARGET_VER_CNF_T), 0, 0, TD_CTRL);

    p_dt = (META_UTIL_CHECK_TARGET_VER_CNF_T *)get_peer_buff_pdu(*pp_peer_buff_ret, &pdu_length);
    kal_mem_set(p_dt, 0, sizeof(META_UTIL_CHECK_TARGET_VER_CNF_T));
    p_dt->m_bCheckPass = KAL_TRUE;

    if(req->cmd.m_rCheckMetaVerReq.m_eVerType == META_VERSION_META_DLL_UTIL_VER ||
            req->cmd.m_rCheckMetaVerReq.m_eVerType == META_VERSION_USER_DEFINE)
    {
        // checkin
        // main version first, if >, pass the check!, if < fail,
        // if main version is the same, check minor version
        // if minor version the same, check build number

        if(req->cmd.m_rCheckMetaVerReq.m_u4MainVersion < FT_REQUIRED_META_DLL_MAIN_VER)
        {
            p_dt->m_bCheckPass = KAL_FALSE;
        }
        else if(req->cmd.m_rCheckMetaVerReq.m_u4MainVersion == FT_REQUIRED_META_DLL_MAIN_VER)
        {
            if(req->cmd.m_rCheckMetaVerReq.m_u4MinorVersion < FT_REQUIRED_META_DLL_MINOR_VER)
            {
                p_dt->m_bCheckPass = KAL_FALSE;
            }
            else if(req->cmd.m_rCheckMetaVerReq.m_u4MinorVersion == FT_REQUIRED_META_DLL_MINOR_VER)
            {
                if(req->cmd.m_rCheckMetaVerReq.m_u4BuildNum < FT_REQUIRED_META_DLL_BUILD_NUM)
                    p_dt->m_bCheckPass = KAL_FALSE;
            }
        }
        // assign the target version information
        p_dt->m_u4TargetMainVersion = FT_REQUIRED_META_DLL_MAIN_VER;
        p_dt->m_u4TargetMinorVersion = FT_REQUIRED_META_DLL_MINOR_VER;
        p_dt->m_u4TargetBuildNum = FT_REQUIRED_META_DLL_BUILD_NUM;
    }
    else // other type version check // so far, none, just assign version info to 0xFFFFFFFF
    {
        // in this case: version check pass
        p_dt->m_u4TargetMainVersion = FT_REQUIRED_VERSION_UNKNOWN;
        p_dt->m_u4TargetMinorVersion = FT_REQUIRED_VERSION_UNKNOWN;
        p_dt->m_u4TargetBuildNum = FT_REQUIRED_VERSION_UNKNOWN;
    }
    cnf->status = FT_CNF_OK;
}
void ft_util_set_check_paras(FT_UTILITY_COMMAND_REQ  *req, FT_UTILITY_COMMAND_CNF  *cnf)
{
    cnf->status = FT_CNF_OK;
}
void ft_util_reboot_to_normal_mode(FT_UTILITY_COMMAND_REQ  *req, FT_UTILITY_COMMAND_CNF *cnf)
{
    DCL_HANDLE handle;
    handle=DclPW_Open(DCL_PW, FLAGS_NONE);
    /* RCT_PDN2 bit1: make sure the the next boot is IDLE (normal mode) */
    DclPW_Control(handle,PW_CMD_SET_SWITCH_TO_IDLE,NULL);
    DclPW_Close(handle);
    // enable watchdog timer
    ft_util_watch_dog_start(req, cnf, NULL);
}
void ft_util_get_vpa_voltage_list(const FT_UTILITY_COMMAND_REQ *req, FT_UTILITY_COMMAND_CNF *cnf, peer_buff_struct **peer_buff_ret)
{
    DCL_HANDLE handle;
    PMU_CTRL_VPA_GET_VOLTAGE_LIST voltageList;
    handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
    if(DclPMU_Control(handle, VPA_GET_VOLTAGE_LIST, (DCL_CTRL_DATA_T *)&voltageList) != STATUS_OK)
    {
        cnf->status = FT_CNF_FAIL;
    }
    else
    {
        cnf->status = FT_CNF_OK;
    }
    DclPMU_Close(handle);
    if(cnf->status == FT_CNF_OK)
    {
        if( NULL != (*peer_buff_ret=construct_peer_buff(sizeof(FtUtilCmdCnfVpaVoltageList), 0, 0, TD_CTRL)) )
        {
            kal_uint32 i;
            FtUtilCmdCnfVpaVoltageList * pdu_ptr = get_peer_buff_pdu( *peer_buff_ret, &((*peer_buff_ret)->pdu_len) );
            if(pdu_ptr != NULL)
            {
                kal_mem_set(pdu_ptr, 0, sizeof(FtUtilCmdCnfVpaVoltageList));
                for(i=0;i<voltageList.number;i++)
                {
                    /******************************************************
                     * if the voltage is valid, pass the information to PC
                     *****************************************************/
                    if(voltageList.pVoltageList[i] != PMU_VOLT_INVALID)
                    {
                        pdu_ptr->voltageList[pdu_ptr->validNumber]   = voltageList.pVoltageList[i];
                        pdu_ptr->registerValue[pdu_ptr->validNumber] = i;
                        pdu_ptr->validNumber++;
                    }
                }
            }
            else
            {
                ASSERT(pdu_ptr);
            }
        }
        else
        {
            ASSERT(0);
        }
    }
}

void FT_UtilityCommand(ilm_struct *ptrMsg) {

    FT_UTILITY_COMMAND_REQ  *p_req=(FT_UTILITY_COMMAND_REQ *)ptrMsg->local_para_ptr;
    FT_UTILITY_COMMAND_CNF  cnf;
    peer_buff_struct        *peer_buff_ret = NULL;

    kal_mem_set(&cnf, '\0', sizeof(cnf));
    cnf.type = p_req->type;
    cnf.status = FT_CNF_FAIL;
    peer_buff_ret = NULL;

    switch(p_req->type) {
        case FT_UTILCMD_CHECK_IF_FUNC_EXIST:
            if(ft_util_check_if_func_exist(p_req, &cnf))
            {
                 return;
            }
            break;
        case FT_UTILCMD_CHECK_IF_ISP_SUPPORT:
            ft_util_check_if_isp_support(&cnf);
            break;
        case FT_UTILCMD_ENABLE_WATCHDOG_TIMER:
            ft_util_watch_dog_start(p_req, &cnf,peer_buff_ret);
            break;
        case FT_UTILCMD_CHECK_IF_ACOUSTIC16_SUPPORT:
            cnf.status = FT_CNF_OK;
            break;
        case FT_UTILCMD_CHECK_IF_LOW_COST_SINGLE_BANK_FLASH:
#ifdef _LOW_COST_SINGLE_BANK_FLASH_
            cnf.status = FT_CNF_OK;
#endif
            break;
        case FT_UTILCMD_QUERY_PMIC_ID:
            ft_util_query_pmic_id(&cnf);
            break;
        case FT_UTILCMD_LED_LIGHT_LEVEL:
            ft_util_set_led_light_level(p_req,&cnf);
            break;
        case FT_UTILCMD_VIBRATOR_ONOFF:
            ft_util_set_vibrator_onoff(p_req,&cnf);
            break;
        case FT_UTILCMD_QUERY_LOCAL_TIME:
            ft_util_query_rtc(&cnf);
            break;
#if !defined(__LTE_SM__)            
        case FT_UTILCMD_RF_ITC_PCL:
            ft_util_query_itc_pcl(&cnf);
            break;
#endif // #if !defined(__LTE_SM__)
        case FT_UTILCMD_CHECK_IF_DRC_SUPPORT:
#if defined(DRC_ENABLED)
            cnf.status = FT_CNF_OK;
#endif
            break;
        case FT_UTILCMD_MAIN_SUB_LCD_LIGHT_LEVEL:
            ft_util_set_lcd_light_level(p_req, &cnf);
            break;
        case FT_UTILCMD_CHECK_IF_ULC_FAT_SUPPORT:
            ft_util_check_if_ulc_support(&cnf);
            break;
        case FT_UTILCMD_CHECK_IF_SMART_PHONE_MODEM_SUPPORT:
            ft_util_check_if_smart_phone_modem_supported(&cnf);
            break;
        case FT_UTILCMD_CHECK_TARGET_META_REQUIRED_VERS:
            ft_util_check_vers(p_req,&cnf,&peer_buff_ret);
            break;
        case FT_UTILCMD_SET_TARGET_CHECK_PARAS:
            ft_util_set_check_paras(p_req,&cnf);
            break;
        case FT_UTILCMD_CHECK_IF_TARGET_NV_SEC_ON:
#ifdef __NVRAM_SECRET_DATA__
            ft_util_get_target_nv_sec_on_flag(&cnf);
#else
            cnf.result.m_bNVSecOn = KAL_FALSE;
            cnf.status = FT_CNF_OK;
#endif
            break;
        case FT_UTILCMD_REBOOT_TO_NORMAL_MODE:
            ft_util_reboot_to_normal_mode(p_req, &cnf);
            break;
        case FT_UTILCMD_QUERY_TARGET_OPTION_INFO:
        {
            cnf.result.m_u4TargetOptionInfo = 0; // reset to 0
#ifdef LIPTON_BB
            cnf.result.m_u4TargetOptionInfo |= META_LIPTON_OPTION_ON;  // 0x00000001
#endif // #ifdef LIPTON_BB
#ifdef __TC01__
            cnf.result.m_u4TargetOptionInfo |= META_TC01_OPTION_ON;  // 0x00000002 
#endif // #ifdef __TC01__
#if defined(__UMTS_TDD128_MODE__) && defined(__AST_TL1_TDD__)
            if(KAL_TRUE == tl1_is_tdd_hw_exist())  //20130206
            {
            cnf.result.m_u4TargetOptionInfo |= META_AST_TD_OPTION_ON;  // 0x00000004
            }
#endif // #if defined(__UMTS_TDD128_MODE__) && defined(__AST_TL1_TDD__)
            cnf.status = FT_CNF_OK;

            break;
        }
#ifdef __TOOL_ACCESS_CTRL__
        case FT_UTILCMD_QUERY_LIMITED_STATE:
        {
            // query the limited state indicator
            cnf.result.m_u4LimitedStateIndicator = INT_GetMetaModeSrc();
            cnf.status = FT_CNF_OK;
            break;
        }
#endif // #ifdef __TOOL_ACCESS_CTRL__
        case FT_UTILCMD_QUERY_VPA_VOLTAGE_LIST:
        {
            ft_util_get_vpa_voltage_list(p_req, &cnf, &peer_buff_ret);
            break;
        }
        case FT_UTILCMD_QUERY_DRIVE_AVAILABLE_FOR_FILE_SIZE:
        {
            cnf.status = FT_CNF_OK;
            cnf.result.driveLetter = FT_GetAvailableDrive(p_req->cmd.requestedFileSize);
            break;
        }
        case FT_UTILCMD_QUERY_MAX_CTRL_BUFFER_SIZE:
        {
            cnf.status = FT_CNF_OK;
            /*
             * prevent from customization error
             */
            if(ft_get_ctrlbuf_max_size() <= Custom_META_ControlBufferSize())
            {
                cnf.result.maxControlBufferSize = ft_get_ctrlbuf_max_size();
            }
            else
            {
                /*
                 * Keep the original performance
                 */
                if(Custom_META_ControlBufferSize() < 2048)
                {
                    cnf.result.maxControlBufferSize = 2048;
                }
                else
                {
                    cnf.result.maxControlBufferSize = Custom_META_ControlBufferSize();
                }
            }
            break;
        }
        case FT_UTILCMD_QUERY_ADC_MODULE_SUPPORT:
        {
            cnf.status = FT_CNF_OK;
#if defined(DRV_ADC_NOT_EXIST)||defined(DRV_ADC_OFF)
            cnf.result.module_support = KAL_FALSE;
#else
            cnf.result.module_support = KAL_TRUE;
#endif // #if defined(DRV_ADC_NOT_EXIST)||defined(DRV_ADC_OFF)
            break;
        }
        case FT_UTILCMD_QUERY_RTC_MODULE_SUPPORT:
        {
            cnf.status = FT_CNF_OK;
#if defined(DRV_RTC_OFF)||defined(DRV_RTC_NOT_EXIST)
            cnf.result.module_support = KAL_FALSE;
#else
            cnf.result.module_support = KAL_TRUE;
#endif // #if defined(DRV_RTC_NOT_EXIST)||defined(DRV_RTC_OFF)
            break;
        }
        case FT_UTILCMD_QUERY_META_MODE_TRACE:
        {
#if defined(__TST_META_MODE_TRACE_ENABLE__)
            cnf.result.trace_mode = tst_get_meta_mode_trace_enable();
            cnf.status = FT_CNF_OK;
#else
            cnf.status = FT_CNF_FAIL;
#endif // #if defined(__TST_META_MODE_TRACE_ENABLE__)           
            break;
        }
        case FT_UTILCMD_ENABLE_META_MODE_TRACE:
        {
#if defined(__TST_META_MODE_TRACE_ENABLE__)
            if(tst_set_meta_mode_trace_enable(p_req->cmd.trace_mode))
            {            	
                cnf.status = FT_CNF_OK;
            }
            else
#endif // #if defined(__TST_META_MODE_TRACE_ENABLE__)            	
            {
                cnf.status = FT_CNF_FAIL;
            }
            break;
        }        
        default:
            break;
    }
    FT_UTIL_SendCnf(&cnf, peer_buff_ret);
}
kal_uint32 FT_UtilCheckFunctionSupported(kal_uint32 query_op_code)
{
    kal_uint32 cnf_code;
    if( FT_UTILCMD_END > query_op_code )
    {
        switch(query_op_code)
        {
            // obsolete
            case FT_UTILCMD_BT_POWER_ON:
                cnf_code = FT_CNF_FAIL;
                break;
            case FT_UTILCMD_QUERY_BT_WIFI_SINGLE_ANTENNA_CAP:
            case FT_UTILCMD_SET_ANTENNA_PATH_TO_BT:
            case FT_UTILCMD_SET_ANTENNA_PATH_TO_WIFI:
                cnf_code = FT_CNF_FAIL;
                break;
#if !defined(__TOOL_ACCESS_CTRL__)
            case FT_UTILCMD_QUERY_LIMITED_STATE:
            {
                cnf_code = FT_CNF_FAIL;
                break;
            }
#endif // #if !defined(__TOOL_ACCESS_CTRL__)
#if !defined(__TST_META_MODE_TRACE_ENABLE__)
            case FT_UTILCMD_QUERY_META_MODE_TRACE:
            case FT_UTILCMD_ENABLE_META_MODE_TRACE:
            {
                cnf_code = FT_CNF_FAIL;
                break;
            }
#endif // #if !defined(__TST_META_MODE_TRACE_ENABLE__)
#if defined(__LTE_SM__)
            case FT_UTILCMD_RF_ITC_PCL:
            {
                cnf_code = FT_CNF_FAIL;
                break;            	
            }
#endif // #if defined(__LTE_SM__)
            default:
                cnf_code = FT_CNF_OK;
                break;
        }
    }
    else
    {
        cnf_code = FT_CNF_FAIL;
    }
    return cnf_code;
}
