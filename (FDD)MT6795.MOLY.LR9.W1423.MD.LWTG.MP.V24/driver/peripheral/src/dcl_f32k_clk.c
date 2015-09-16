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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   dcl_f32k_clk.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  This Module defines DCL (Driver Common Layer) of the f32k_clk driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_features.h"
#include "drv_comm.h"
#include "dcl.h"
#include "f32k_clk_sw.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

#if defined(DCL_F32K_CLK_INTERFACE)
// Global variable for DCL F32K_CLK API usage
#define DCL_F32K_CLK_DEV_MAGIC_NUM		(0x40000000)
//#define MAX_DCL_F32K_CLK_HANDLE			2
kal_uint32 dcl_f32k_clk_handle_count = 0;

/*************************************************************************
* FUNCTION
*  DclF32K_Initialize
*
* DESCRIPTION
*  This function is to initialize F32K_CLK module
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/

DCL_STATUS DclF32K_Initialize(void)
{
    dcl_f32k_clk_handle_count = 0;
    
#if defined(DRV_F32K_INTERNAL_32K)
    F32K_XOSC32_EMB_setting();
#endif
    
    return STATUS_OK;
}

#if !defined(__MINI_BOOTLOADER__)

/*************************************************************************
* FUNCTION
*  DclF32K_Open
*
* DESCRIPTION
*  This function is to open the F32K_CLK module and return a handle
*
* PARAMETERS
*  dev: only valid for DCL_F32K_CLK
*  flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  DCL_HANDLE_INVALID: Open failed
*  Other value: A valid handle
*
*************************************************************************/

DCL_HANDLE DclF32K_Open(DCL_DEV dev, DCL_FLAGS flags)
{
    kal_uint32 handle;
    kal_uint32 savedMask;

    // Check device type
    if (dev != DCL_F32K_CLK)
    {
        ASSERT(0);
        return DCL_HANDLE_INVALID;		// Incorrecr device ID
    }

    savedMask = SaveAndSetIRQMask();
    dcl_f32k_clk_handle_count = 1;
    handle = (DCL_F32K_CLK_DEV_MAGIC_NUM | dcl_f32k_clk_handle_count);
    RestoreIRQMask(savedMask);

    return handle;
}

/*************************************************************************
* FUNCTION
*  DclF32K_ReadData
*
* DESCRIPTION
*  This function is not supported for the F32K_CLK module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclF32K_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclF32K_WriteData
*
* DESCRIPTION
*  This function is not supported for the F32K_CLK module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclF32K_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}
/*************************************************************************
* FUNCTION
*  DclF32K_Configure
*
* DESCRIPTION
*  This function is not supported for the F32K_CLK module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclF32K_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
    return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclF32K_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the F32K_CLK module.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclF32K_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
    return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclF32K_Control
*
* DESCRIPTION
*  This function is to send command to control the F32K_CLK module.
*
* PARAMETERS
*  handle: The handle value returned from DclF32K_Open
*  cmd: A control command for F32K_CLK module
*          1. F32K_CLK_CMD_QUERY_IS_XOSC32K: To query clock source F32K is XOSC32K or not
*  data: The data of the control command
*          1. F32K_CLK_CMD_QUERY_IS_XOSC32K: pointer to a F32K_CLK_CTRL_F32K_IS_XOSC32_T structure
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*  
*************************************************************************/
DCL_STATUS DclF32K_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
    DCL_STATUS return_status;

    // Check magic number
    if ((handle & DCL_F32K_CLK_DEV_MAGIC_NUM) != DCL_F32K_CLK_DEV_MAGIC_NUM)
    {
        ASSERT(0);
        return STATUS_INVALID_DCL_HANDLE;
    }

    // Error check
    if (dcl_f32k_clk_handle_count == 0){
        ASSERT(0);
        return STATUS_NOT_OPENED;
    }

    switch (cmd)
    {
        case F32K_CLK_CMD_QUERY_IS_XOSC32K:
        {
#if defined(DRV_F32K_INTERNAL_32K) || defined(DRV_F32K_SWITCH_32K)            
            F32K_CLK_CTRL_F32K_IS_XOSC32_T *prF32kIsXOSC32;
            prF32kIsXOSC32 = &(data->rF32kIsXOSC32);
            prF32kIsXOSC32->f32k_is_xosc32 = (DCL_BOOLEAN)F32K_Query_Is_XOSC32();
            return_status = STATUS_OK;
#else
            return_status = STATUS_UNSUPPORTED;
#endif            
        }
        break;

        case F32K_CLK_CMD_EOSC32_TRIMMING:
        {
#if defined(DRV_F32K_INTERNAL_32K)               
            F32K_CLK_CTRL_EOSC32_CALI_VAL_T *prEosc32CaliVal;
            prEosc32CaliVal = &(data->rEosc32CaliVal);
            prEosc32CaliVal->eosc32_cali_val = F32K_EOSC32_trimming();
            return_status = STATUS_OK;   
#else
            return_status = STATUS_UNSUPPORTED;
#endif             
        }
        break;

        case F32K_CLK_CMD_HW_INIT:
        {
#if defined(DRV_F32K_SWITCH_32K)
            F32K_Switch_32K_setting();
            return_status = STATUS_OK;
#else
            return_status = STATUS_UNSUPPORTED;            
#endif 
        }
        break;

        default:
            return_status = STATUS_INVALID_CMD;
    }

    return return_status;
}

/*************************************************************************
* FUNCTION
*  DclF32K_Close
*
* DESCRIPTION
*  This function is to close the F32K_CLK module.
*
* PARAMETERS
*  handle: the returned handle value of DclF32K_Open
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
DCL_STATUS DclF32K_Close(DCL_HANDLE handle)
{
	// Check magic number
	if ((handle & DCL_F32K_CLK_DEV_MAGIC_NUM) != DCL_F32K_CLK_DEV_MAGIC_NUM)
     {
		ASSERT(0);
		return STATUS_INVALID_DCL_HANDLE;
	}

	// Error check
	if (dcl_f32k_clk_handle_count == 0)
     {
		ASSERT(0);
		return STATUS_NOT_OPENED;
	}

	return STATUS_OK;
}

#endif // #if !defined(__MINI_BOOTLOADER__)

#else
DCL_STATUS DclF32K_Initialize(void)
{
	return STATUS_FAIL;
}

DCL_HANDLE DclF32K_Open(DCL_DEV dev, DCL_FLAGS flags)
{
   return DCL_HANDLE_INVALID;
}

DCL_STATUS DclF32K_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclF32K_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclF32K_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclF32K_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_FAIL;
}

DCL_STATUS DclF32K_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	return STATUS_FAIL;
}

DCL_STATUS DclF32K_Close(DCL_HANDLE handle)
{
	return STATUS_FAIL;
}

#endif
