/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *
 * Filename:
 * ---------
 * custom_recovery_timer.c
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *   This file is used to define the recovery timer configuration.
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

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "custom_recovery_timer.h"

/*************************************************************************
* Time unit definition. Please do not change !!
*************************************************************************/
#define RECOVERY_TICKS_20_SEC    (KAL_TICKS_5_SEC+KAL_TICKS_5_SEC+KAL_TICKS_5_SEC+KAL_TICKS_5_SEC)
#define RECOVERY_TICKS_30_SEC    (KAL_TICKS_30_SEC)
#define RECOVERY_TICKS_1_MIN     (KAL_TICKS_1_MIN)
#define RECOVERY_TICKS_2_MIN     (KAL_TICKS_1_MIN + KAL_TICKS_1_MIN)


/*************************************************************************
* Recovery timer interval
*************************************************************************/

const kal_uint32 RECOVERY_TIMER_INTERVAL[MAX_RECOVERY_TIMER_NUM] =
{
  RECOVERY_TICKS_20_SEC, RECOVERY_TICKS_20_SEC, RECOVERY_TICKS_20_SEC,
  RECOVERY_TICKS_20_SEC, RECOVERY_TICKS_20_SEC, RECOVERY_TICKS_20_SEC,
  RECOVERY_TICKS_30_SEC, RECOVERY_TICKS_30_SEC, RECOVERY_TICKS_30_SEC,
  RECOVERY_TICKS_30_SEC, RECOVERY_TICKS_30_SEC, RECOVERY_TICKS_30_SEC,
  RECOVERY_TICKS_1_MIN,  RECOVERY_TICKS_1_MIN,  RECOVERY_TICKS_1_MIN, 
  RECOVERY_TICKS_1_MIN,  RECOVERY_TICKS_1_MIN,  RECOVERY_TICKS_1_MIN,
  RECOVERY_TICKS_2_MIN
 };


/*****************************************************************************
* FUNCTION
*  mm_get_max_recovery_timer_num
* DESCRIPTION
*   This function is used to get the maximum recovery timer number
*
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/
kal_uint8 mm_get_max_recovery_timer_num(void)
{
   return (MAX_RECOVERY_TIMER_NUM);
}  


