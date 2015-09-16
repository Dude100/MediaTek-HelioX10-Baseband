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
 *   dcl_f32k_clk.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *  This file defines the DCL common definitions for f32k_clk dcl interface.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef DCL_DEFINITION_STRUCT
#ifndef __DCL_F32K_CLK_H_STRUCT__
#define __DCL_F32K_CLK_H_STRUCT__

#include "dcl.h"

/*******************************************************************************
 * DCL_OPTIONS for F32K_CLK
 *******************************************************************************/
#define F32K_CLK_OPTIONS

 /*******************************************************************************
 * DCL_CONFIGURE_T for F32K_CLK
 *******************************************************************************/
#define F32K_CLK_CONFIGS

/*******************************************************************************
 * DCL_EVENT for F32K_CLK
 *******************************************************************************/
#define F32K_CLK_EVENTS 

/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/

typedef struct
{
    DCL_BOOLEAN f32k_is_xosc32;
}F32K_CLK_CTRL_F32K_IS_XOSC32_T;

typedef struct
{
    DCL_UINT16  eosc32_cali_val;
}F32K_CLK_CTRL_EOSC32_CALI_VAL_T;

#ifdef __BUILD_DOM__
/* The F32K_CLK Command Parameter Data Structure for Each Command in DCL_CTRL_DATA_T Enum of dcl.h */
typedef struct
{
    F32K_CLK_CTRL_F32K_IS_XOSC32_T    rF32kIsXOSC32; /* Data structure for F32K_CLK_CTRL_F32K_IS_XOSC32 */
    F32K_CLK_CTRL_EOSC32_CALI_VAL_T    rEosc32CaliVal;
}DCL_CTRL_F32K_CLK_DATA_T;
#else /* __BUILD_DOM__ */
#define F32K_CLK_CTRLS \
    F32K_CLK_CTRL_F32K_IS_XOSC32_T    rF32kIsXOSC32; \
    F32K_CLK_CTRL_EOSC32_CALI_VAL_T    rEosc32CaliVal;
#endif /* __BUILD_DOM__ */	

/*******************************************************************************
 * DCL_CTRL_CMD for F32K_CLK
 *******************************************************************************/
#ifdef __BUILD_DOM__
/* The F32K_CLK Command Values in DCL_CTRL_CMD_T Enum of dcl.h */
typedef enum {
    F32K_CLK_CMD_QUERY_IS_XOSC32K,      /* To query F32K is XOSC32K or not */
    F32K_CLK_CMD_EOSC32_TRIMMING,       /* To trimming EOSC32 and get ideal cali value */
    F32K_CLK_CMD_HW_INIT,               /* To init 32K HW setting */
} DCL_CTRL_F32K_CLK_CMD_T;
#else /* __BUILD_DOM__ */
#define F32K_CLK_CMDS \
    F32K_CLK_CMD_QUERY_IS_XOSC32K, \
    F32K_CLK_CMD_EOSC32_TRIMMING, \
    F32K_CLK_CMD_HW_INIT,
#endif /* __BUILD_DOM__ */


#endif // #ifndef __DCL_F32K_CLK_H_STRUCT__
#endif // #ifdef DCL_DEFINITION_STRUCT

#ifdef DCL_DEFINITION_PROTOTYPE
#ifndef __DCL_F32K_CLK_H_PROTOTYPE__
#define __DCL_F32K_CLK_H_PROTOTYPE__
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
*  Return the status of DclF32K_Initialize
*
* RETURN VALUES
*  STATUS_OK: Initialize Finished
*
*************************************************************************/
extern DCL_STATUS DclF32K_Initialize(void);
/*************************************************************************
* FUNCTION
*  DclF32K_Open
*
* DESCRIPTION
*  This function is to open the F32K_CLK module and return a handle
*
* PARAMETERS
*  dev: [IN] Only valid for DCL_F32K_CLK
*  flags: [IN] No sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  Return DCL_HANDLE of F32K_CLK
*
* RETURN VALUES
*  DCL_HANDLE_INVALID : Open failed
*  Other value : A valid handle
*
*************************************************************************/
extern DCL_HANDLE DclF32K_Open(DCL_DEV dev, DCL_FLAGS flags);
/*************************************************************************
* FUNCTION
*  DclF32K_Control
*
* DESCRIPTION
*  This function is to send command to control the F32K_CLK module.
*
* PARAMETERS
*  handle: [IN] The handle value returned from DclF32K_Open
*  cmd: [IN] A control command for RTC module
*           1. F32K_CLK_CMD_QUERY_IS_XOSC32K: To query clock source F32K is XOSC32K or not
*
*  data: The data of the control command
*           1. F32K_CLK_CMD_QUERY_IS_XOSC32K: pointer to a F32K_CLK_CTRL_F32K_IS_XOSC32_T structure
*
* RETURNS
*  Return the status of DclF32K_Control
*
* RETURN VALUES
*  STATUS_OK: Command is executed successfully.
*  STATUS_FAIL: Command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
extern DCL_STATUS DclF32K_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
/*************************************************************************
* FUNCTION
*  DclF32K_Close
*
* DESCRIPTION
*  This function is to close the F32K_CLK module.
*
* PARAMETERS
*  handle: [IN] The returned handle value of DclF32K_Open
*
* RETURNS
*  Return the status of DclF32K_Close
*
* RETURN VALUES
*  STATUS_OK
*
*************************************************************************/
extern DCL_STATUS DclF32K_Close(DCL_HANDLE handle);

#endif // #ifndef __DCL_F32K_CLK_H_PROTOTYPE__
#endif // #ifdef DCL_DEFINITION_PROTOTYPE
 
