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
/*
**   Includes
*/
#include "customer_mbim_config.h"
#include "mbim_defs.h"

/*
** Default timer value in seconds.
** (1) In MBIM_SIGNAL_STATE_REPORT_MODE_DEFAULT mode, if SignalStrengthInterval = 0 in MBIM_CID_SIGNAL_STATE we will use this value.
** (2) In MBIM_SIGNAL_STATE_REPORT_MODE_CUSTOM mode, we dont care SignalStrengthInterval in MBIM_CID_SIGNAL_STATE and just use this value.
** If you dont want to start a timer, set it to 0xffffffff
*/
#define MBIM_SIGNAL_STATE_REPORT_TIME 5

/*
** This is the difference in RSSI coded values that trigger a report.
** (1) In MBIM_SIGNAL_STATE_REPORT_MODE_DEFAULT mode, if RssiThreshold = 0 in MBIM_CID_SIGNAL_STATE we will use this value.
** (2) In MBIM_SIGNAL_STATE_REPORT_MODE_CUSTOM mode, we dont care RssiThreshold in MBIM_CID_SIGNAL_STATE and just use this value.
**
*/
#define MBIM_DEFAULT_RSSI_THRESHOLD 3

/*
** This is the difference in error rate coded values that trigger a report.
** (1) In MBIM_SIGNAL_STATE_REPORT_MODE_DEFAULT mode, if ErrorRateThreshold = 0 in MBIM_CID_SIGNAL_STATE we will use this value.
** (2) In MBIM_SIGNAL_STATE_REPORT_MODE_CUSTOM mode, we dont care ErrorRateThreshold in MBIM_CID_SIGNAL_STATE and just use this value.
*/
#define MBIM_DEFAULT_ERROR_RATE_THRESHOLD 1


/*****************************************************************************
* FUNCTION
*  custom_mbim_signal_state_report_mode
* DESCRIPTION
*   This function is used to get MBIM signal state report mode
*
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint8 custom_mbim_signal_state_report_mode (void)
{
  /* 
    ** For customer to define how to report signal state
    ** MBIM_SIGNAL_STATE_REPORT_MODE_DEFAULT: report signal state according to MBIM_CID_SIGNAL_STATE SET command.
    ** MBIM_SIGNAL_STATE_REPORT_MODE_CUSTOM: Customers can define report timer, RSSI threshold, error rate threshold.
    **
    */

   return (MBIM_SIGNAL_STATE_REPORT_MODE_DEFAULT);
}


/*****************************************************************************
* FUNCTION
*  custom_mbim_signal_state_report_time
* DESCRIPTION
*   This function is used to get default MBIM signal state report timer value 
*
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint32 custom_mbim_signal_state_report_time (void)
{
   return (MBIM_SIGNAL_STATE_REPORT_TIME);
}

/*****************************************************************************************
* FUNCTION
*   custom_mbim_mtk_vendor_cmd()
*
* DESCRIPTION
*   The function be invoked when receive MBIM_UUID_MTK_VENDOR_CMD/MBIM_CID_MTK_VENDOR_CMD
*   
* PARAMETERS
*   command_type        MBIM CID command type (0:query, 1:set)
*   request                   information_buffer from MBIM Host 
*   response                 information_buffer sent to MBIM Host 
*
* RETURNS
*   status      MBIM spec defined status code (mbim_status_code_enum in mbim_defs.h)
*   
******************************************************************************************/
kal_uint32 custom_mbim_mtk_vendor_cmd(kal_uint32 command_type, kal_uint8 *request, kal_uint8 *response)
{
    mbim_status_code_enum status;
    mbim_mtk_vendor_cmd_info_struct *req_ptr = (mbim_mtk_vendor_cmd_info_struct*)request;
    mbim_mtk_vendor_cmd_info_struct *rsp_ptr = (mbim_mtk_vendor_cmd_info_struct*)response;
    kal_uint32 VendorCmdType = 0;

    if (req_ptr != NULL)
    {
        VendorCmdType = req_ptr->VendorCmdType;
    }

    // Step1. Customize vendor defined procedure when receive specific MTK_VENDOR_CMD_TYPE
    //      MBIM_MTK_VENDOR_CMD_TYPE_X ->
    //      MBIM_MTK_VENDOR_CMD_TYPE_Y ->

    if (VendorCmdType == MBIM_MTK_VENDOR_CMD_TYPE_NONE)
    {
        // Vendor defined procedure
    }

    // Step2. Customize response information_buffer to MBIM host
    //      if no specific requirement, keep unchanged.

    rsp_ptr->VendorCmdType = VendorCmdType;
    rsp_ptr->VendorCmdOffset = 0;
    rsp_ptr->VendorCmdSize = 0;
    status = MBIM_STATUS_SUCCESS;

    return status;
}

/*****************************************************************************
* FUNCTION
*  custom_mbim_signal_state_default_rssi_threshold
* DESCRIPTION
*   This function is used to get default MBIM signal state default RSSI threshold
*
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint32 custom_mbim_signal_state_default_rssi_threshold (void)
{
   return (MBIM_DEFAULT_RSSI_THRESHOLD);
}


/*****************************************************************************
* FUNCTION
*  custom_mbim_signal_state_default_error_rate_threshold
* DESCRIPTION
*   This function is used to get default MBIM signal state default error rate threshold
*
* PARAMETERS
*
* RETURNS
*  kal_uint32
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint32 custom_mbim_signal_state_default_error_rate_threshold (void)
{
   return (MBIM_DEFAULT_ERROR_RATE_THRESHOLD);
}

