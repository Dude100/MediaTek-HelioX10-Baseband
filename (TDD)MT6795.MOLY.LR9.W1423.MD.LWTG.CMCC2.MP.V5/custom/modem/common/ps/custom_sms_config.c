/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * custom_sms_config.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for sms customization functions, 
 *   custom can use these functions to config parameters. 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
**   Includes
*/
#include "kal_general_types.h"

// for Smart Phone (ex: Windows Mobile/Android) project default value
#define CNMI_PARA_MODE  1
#define CNMI_PARA_MT  2
#define CNMI_PARA_BM  2
#define CNMI_PARA_DS  1
/* For AT+CNMI <mode> parameter, the value should be (0-3) */
/* For AT+CNMI <mt> parameter, the value should be (0-3) */
/* For AT+CNMI <bm> parameter, the value should be (0,2, or 3) */
/* For AT+CNMI <ds> parameter, the value should be (0 or 1) */

/* 0xFFFF means default check all the service tables */
#define SERVICE_TABLE_BITMAP 0xFFFF

#define SMS_FORMAT_PDU_MODE  0
#define SMS_FORMAT_TEXT_MODE 1

/*Disable MT SMS and STK send SMS*/
#ifdef __DISABLE_SMS__
#define SMS_DISABLE  1    
#else
#define SMS_DISABLE  0
#endif

/*****************************************************************************
* FUNCTION
*   sms_cnmi_para_mode 
* DESCRIPTION
*   This function is used to define the spec 27.005 section 3.4.1 
*   AT+CNMI <mode> parameter, the value sholud be (0-3)
*
* PARAMETERS
*
* RETURNS
*   kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint8 sms_cnmi_para_mode(void)
{
   return (CNMI_PARA_MODE);
}


/*****************************************************************************
* FUNCTION
*   sms_cnmi_para_mt
* DESCRIPTION
*   This function is used to define the spec 27.005 section 3.4.1 
*   AT+CNMI <mt> parameter, the value sholud be (0-3)
*
* PARAMETERS
*
* RETURNS
*   kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint8 sms_cnmi_para_mt(void)
{
   return (CNMI_PARA_MT);
}


/*****************************************************************************
* FUNCTION
*   sms_cnmi_para_bm
* DESCRIPTION
*   This function is used to define the spec 27.005 section 3.4.1 
*   AT+CNMI <bm> parameter, the value sholud be (0,2, or 3)
*
* PARAMETERS
*
* RETURNS
*   kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint8 sms_cnmi_para_bm(void)
{
   return (CNMI_PARA_BM);
}


/*****************************************************************************
* FUNCTION
*   sms_cnmi_para_ds
* DESCRIPTION
*   This function is used to define the spec 27.005 section 3.4.1 
*   AT+CNMI <ds> parameter, the value sholud be (0 or 1)
*
* PARAMETERS
*
* RETURNS
*   kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint8 sms_cnmi_para_ds(void)
{
   return (CNMI_PARA_DS);
}

/*****************************************************************************
* FUNCTION
*   sms_check_sim_service_table
* DESCRIPTION
*   This function is used to config if the SIM file need to check service table 
*   1: It will check service table, 0: It will not check service table
*
*            +---------+---------+---------------+---------+
*            |  BIT16  |  BIT15  | ... |  BIT 1  |  BIT 0  |
*            +---------+---------+---------------+---------+
*
*   BIT  0: Efsmss
*   BIT  1: EFsmsp
*   BIT  2: EFcbmi
*   BIT  3: EFcbmid
*   BIT  4: EFcbmir 
*   BIT  5: EFext6          (R4 file)
*   BIT  6: EFmbdn          (R4 file)
*   BIT  7: EFmbi           (R4 file)
*   BIT  8: EFmwis          (R4 file)
*   BIT  9: EFext1
*   BIT 10: EFmailbox_num   (CPHS file)
*   BIT 11: EFsms
*
* PARAMETERS
*
* RETURNS
*   kal_uint16
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint16 sms_check_sim_service_table(void)
{
   return (SERVICE_TABLE_BITMAP);
}

/*****************************************************************************
* FUNCTION
*   custom_sms_is_disabled 
* DESCRIPTION
*   This function is used to get the value of SMS disable. 
*   0: SMS works normally
*   1: "MT SMS" and "STK send SMS" are disbaled 
*
* PARAMETERS
*
* RETURNS
*   kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint8 custom_sms_is_disabled(void)
{
   return (SMS_DISABLE);
}


/*****************************************************************************
* FUNCTION
*   sms_message_format
* DESCRIPTION
*   This function is used to define the default value to 
*   message format AT+CMGF. (PDU mode or TEXT mode)
*
* PARAMETERS
*
* RETURNS
*   kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint8 sms_message_format(void)
{
    return (SMS_FORMAT_PDU_MODE);
}

/*------------------------------------------------------------- 
 * meet 3GPP 27.005 +CNMI NOTE 5 define:
 * NOTE 5: If AT command interface is acting as the only display device, 
 *         the ME must support storing of class 0 messages and messages 
 *         in the message waiting indication group (discard message); refer table 2)
 *
 *-------------------------------------------------------------*/
kal_bool custom_sms_store_class0_mwd(void)
{
#ifdef __SP_RIL_SUPPORT__
    return KAL_FALSE;
#else
    return KAL_TRUE;
#endif
}
