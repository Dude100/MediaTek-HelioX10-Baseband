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
 *   flash_sfi_release.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the SFI (serial flash interface) related setting.
 *
 * Author:
 * -------
 * -------
 *
 *   
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
Add common API:SFI_Dev_WorkingFrequencyQuery() to query SF Frequency
[Query time]
After MAUI TCT_Schedule() ready, each task is created.
[Use method]
1. Include header: mcu\interface\hal\storage\Flash_sfi_release.h
2. Call SFI_Dev_WorkingFrequencyQuery()
3. Return value of this function(enum):
   SFI_CLK_UNKNOWN = 0
   SFI_CLK_78MHZ   = 78
   SFI_CLK_104MHZ  = 104
   SFI_CLK_130MHZ  = 130
[Notice]
This function always exists, if the platform is not Serial Flash supported, return UNKNOWN .

[Check-in branches]
11B
11B.1132SP
MODEM_DEV

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
#ifndef __FLASH_SFI_RELEASE__
#define __FLASH_SFI_RELEASE__
#if defined(__SERIAL_FLASH_EN__) //This compile option only enables when SERIAL_FLASH_SUPPORT in make file is TRUE

#if defined(MT6250) || defined(MT6280)
#include "custom_sfi_clock.h"
#endif

#endif  /* __SERIAL_FLASH_EN__ */

/**
    * SFI clock rate for query.
    */
typedef enum sfi_clock_enum_t 
{
   SFI_CLK_UNKNOWN = 0,
   SFI_CLK_78MHZ   = 78,
   SFI_CLK_104MHZ  = 104,
   SFI_CLK_130MHZ  = 130
}sfi_clock_enum;

/**
    * SFI Voltage for query.
    */
typedef enum sfi_voltage_enum_t 
{
   SFI_Voltage_UNKNOWN = 0,
   SFI_Voltage_18      = 18,  //1.8V
   SFI_Voltage_30      = 30   //3.0V
}sfi_voltage_enum;


extern sfi_clock_enum SFI_Dev_WorkingFrequencyQuery(void);
extern sfi_voltage_enum SFI_Dev_WorkingVoltageQuery(void);

#endif /* __FLASH_SFI_RELEASE__ */

