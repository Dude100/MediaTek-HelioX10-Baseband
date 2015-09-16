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
 *    dcl_pmic6326_ccci_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for PMIC6326 CCCI
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#ifndef __DCL_PMU6326_CCCI_SW_H_STRUCT__
#define __DCL_PMU6326_CCCI_SW_H_STRUCT__

#include "dcl_pmic_features.h"

#if defined(PMIC_6326_CCCI_REG_API)

typedef enum
{
	PMIC6326_VSIM_ENABLE = 0,
	PMIC6326_VSIM_SET_AND_ENABLE = 1,
	PMIC6236_LOCK = 2,
	PMIC6326_UNLOCK = 3,
	PMIC6326_VSIM2_ENABLE = 4,
	PMIC6326_VSIM2_SET_AND_ENABLE = 5,
	PMIC6326_MAX
}pmic6326_ccci_op;

typedef enum
{
	PMIC6326_REQ = 0,		// Local side send request to remote side
	PMIC6326_RES = 1		// Remote side send response to local side
}pmic6326_ccci_type;

/*
    The CCCI message format (CCIF Mailbox port)
    | 4 bytes        | 4 bytes       | 4 bytes            | 4 bytes         |
      Magic number     Message ID      Logical channel      Reserved
                       PMIC msg                             PMIC msg info
*/

/*
    PMIC msg format
    (MSB)                                                      (LSB)
    |  1 byte        | 1 byte        | 1 byte        | 1 byte      |
       Param2          Param1          Type            Op
*/

/*
    PMIC msg info format
    (MSB)                                                (LSB)
    |  1 byte        | 1 byte        | 2 bytes               |
       Param2          Param1          Exec_time
*/



typedef struct
{
	kal_uint8	pmic6326_op;		// Operation
	kal_uint8	pmic6326_type;		// message type: Request or Response
	kal_uint8	pmic6326_param1;
	kal_uint8	pmic6326_param2;
}pmic6326_ccci_msg;

typedef struct
{
	kal_uint16	pmic6326_exec_time;		// Operation execution time (In ms)
	kal_uint8	pmic6326_param1;
	kal_uint8	pmic6326_param2;
}pmic6326_ccci_msg_info;

/*
    PMIC share memory
    (MSB)                                                   (LSB)
    |  1 byte        | 1 byte        | 1 byte        | 1 byte   |
       Param2          Param1          Type            Op
    |  1 byte        | 1 byte        | 2 bytes                  |
       Param2          Param1          Exec_time
*/

typedef struct
{
	pmic6326_ccci_msg ccci_msg;
	pmic6326_ccci_msg_info ccci_msg_info;
}pmic6326_share_mem_info;



// =======================================================================================
#define MAX_PMIC6326_CCCI_POLLING_PERIOD	1000

// Define to bypass PMIC CCCI driver
// This is only for debug purpose
// 1. Always return when upper layer call exported PMIC APIs
// 2. Boot phase parameter check and API check always return OK
//#define BY_PASS_PMIC_CCCI_DRIVER

// If NOT define __SMART_PHONE_MODEM__, it means we are MD standalone,
// so need to bypass communication with AP side (Ex: Get share memory info, Send CCCI command to AP)
#if (!defined(__SMART_PHONE_MODEM__))
#define BY_PASS_PMIC_CCCI_DRIVER
#endif // #if (!defined(__SMART_PHONE_MODEM__))

/*
typedef enum
{
	VSIM,
	VSIM2,
	PMU_LDO_BUCK_MAX,
	VFM,
	VMC,	
	VRF,
	VTCXO,
	V3GTX,
	V3GRX,
	VA,
	VIO,
	VRTC,
	VCAMA,
	VCAMD,
	VWIFI3V3,
	VWIFI2V8,
	VBT,
	VUSB,
	VGP,
	VGP2,
	VSDIO,
	VCORE,
	VCORE1,
	VCORE2,
	VM,
	VMEM,
	VRF18,
	VIBR		
}PMU_LDO_BUCK_LIST_ENUM;

typedef enum
{
	VPA1,
	PMU_VPA_MAX
}PMU_VPA_LIST_ENUM;

typedef enum
{
	CHR,
	PMU_CHR_MAX
}PMU_CHR_LIST_ENUM;

typedef enum
{
	SPK,
	SPKL,
	SPKR,
	PMU_SPK_MAX
}PMU_SPK_LIST_ENUM;

typedef enum
{
	PMU_ISINK_MAX
}PMU_ISINK_LIST_ENUM;

typedef enum
{
	BOOST1,
	BOOST2,
	PMU_BOOST_MAX
}PMU_BOOST_LIST_ENUM;

*/

#endif // #if defined(PMIC_6326_CCCI_REG_API)
#endif // #ifndef __DCL_PMU6326_CCCI_SW_H_STRUCT__



