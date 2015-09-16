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
 *    drv_comm.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines driver common functions.
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "reg_base.h"
#include "config_hw.h"
#include "drv_comm.h"
#include "l1_interface.h"

kal_uint32 drv_get_current_time(void)
{
#if defined(DRV_MISC_TDMA_NO_TIME)
   ASSERT(0);
#endif   /*DRV_MISC_TDMA_NO_TIME*/

#if defined(DRV_MISC_TDMA_TIME_BASE)
   return (DRV_Reg32(TDMA_base+0x0230));
#elif defined(DRV_MISC_TDMA_TIME_BASE_8200)
	return (DRV_Reg32(0x82000230));
#elif defined(DRV_MISC_TDMA_TIME_BASE_8020)
	return (DRV_Reg32(0x80200230));
#elif defined(DRV_MISC_TDMA_TIME_BASE_8406)
	return (DRV_Reg32(0x84060230));
#elif defined(DRV_MISC_TDMA_L1_MACRO)
	return (HW_TDMA_GET_32KCNT());
#else
   return 0;
#endif
}

kal_uint32 drv_get_duration_tick(kal_uint32 previous_time, kal_uint32 current_time)
{
	kal_uint32 result=0;
#if defined(DRV_MISC_TDMA_NO_TIME)
   ASSERT(0);
#endif   /*DRV_MISC_TDMA_NO_TIME*/

	if (previous_time > current_time)
	{
//#if defined(DRV_MISC_TDMA_TIME_MAX_80000)
#if defined(DRV_MISC_TDMA_TIME_MAX_19BITS)
		result = 0x80000 - previous_time + current_time;
#elif defined(DRV_MISC_TDMA_TIME_MAX_24BITS)
      result = 0x1000000 - previous_time + current_time;
#endif
	}
	else
	{
		result = current_time - previous_time;
	}
	return result;
}

kal_uint32 drv_get_duration_ms(kal_uint32 previous_time)
{
	kal_uint32 result;
	kal_uint32 current_time;
	
	current_time = drv_get_current_time();
	result = drv_get_duration_tick(previous_time, current_time);
	result*=1000;
	result/=32768;
	return result;
}

