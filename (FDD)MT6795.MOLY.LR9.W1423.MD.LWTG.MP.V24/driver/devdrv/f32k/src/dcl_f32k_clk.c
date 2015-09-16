/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   dcl_f32k_clk.c
 *
 * Project:
 * --------
 *   MT6290
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * Barry Hong
 *   
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * .remove fakeAPI
 ****************************************************************************/


#include "drv_comm.h"
#include "intrCtrl.h"
#include "drv_f32k_clk.h"
#include "dcl_f32k_clk.h"


#include "dcl.h"
#include "drv_hisr.h"
#include "kal_general_types.h"
#include "kal_public_api.h"


#if !defined(DRV_F32K_OFF)

/*****************************************************************************
 *						 SYMBOL Definition                                   *
 *****************************************************************************/

/*****************************************************************************
 *						 Global/External Variable                            *
 *****************************************************************************/


/*****************************************************************************
 *						 function declaration                                *
 *****************************************************************************/



/*****************************************************************************
 *						 LISR/HISR/Callback Functions                        *
 *****************************************************************************/


/*****************************************************************************
 *						 Basic Driver Implementation						 *
 *****************************************************************************/

#if defined(DCL_F32K_CLK_INTERFACE)


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
    return STATUS_OK;
}


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
    return DCL_HANDLE_NONE;
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
	return STATUS_OK;
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
	return STATUS_OK;
}

#else

DCL_STATUS DclF32K_Initialize(void)
{
	return STATUS_FAIL;
}


DCL_HANDLE DclF32K_Open(DCL_DEV dev, DCL_FLAGS flags)
{
   return DCL_HANDLE_INVALID;
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


#else /*!defined(DRV_F32K_OFF)*/

#endif /*!defined(DRV_F32K_OFF)*/


