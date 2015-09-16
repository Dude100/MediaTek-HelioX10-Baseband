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
 *   dcm_service.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file provides dcm APIs to get device information 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __MTK_TARGET__
#if defined(MT6290) && defined(__ARM7EJ_S__)
#include "mpu_mtk_mmu_v2_int.h"
#else /* end of "defined(MT6290) && defined(__ARM7EJ_S__)" */
#include "cp15.h"
#endif /* end of else of "defined(MT6290) && defined(__ARM7EJ_S__)" */
#include "drv_comm.h"
#include "drv_dcm.h"
//#include "dcm_sw.h"
#include "intrCtrl.h"
#include "devdrv_ls.h"
#include "pll.h"
#include "sleepdrv_interface.h"
#include "sync_data.h"

volatile kal_uint32 dcm_mcubus_dcm_off = 0;

#if defined(MT6290) && defined(__ARM7EJ_S__)
__attribute__ ((section("COPRO_INTSRAM_RW")))
#else /* end of "defined(MT6290) && defined(__ARM7EJ_S__)" */
DEVDRV_LS_INTSRAM_ROCODE
#endif /* end of else of "defined(MT6290) && defined(__ARM7EJ_S__)" */
kal_int32 arm_enter_standby_mode(kal_int32 mode)
{

#if defined(MT6290) && defined(__ARM7EJ_S__)
    MCU_ENTER_POWER_SAVING_MODE();
#else  /* end of "defined(MT6290) && defined(__ARM7EJ_S__)" */
    cp15_enter_low_pwr_state();
#endif /* end of else of "defined(MT6290) && defined(__ARM7EJ_S__)" */
    return 0;
}

void DCM_Prerequisite(void)
{
}

void DCM_EMI2AXI_DCM_OFF(kal_uint32 off) __attribute__((weak, alias ("DCM_MCUBUS_DCM_OFF")));
void DCM_MCUBUS_DCM_OFF(kal_uint32 off) 
{
    kal_uint32 _savedMask;
    _savedMask = SaveAndSetIRQMask();
    if (0 != off) {
        dcm_mcubus_dcm_off++;
    }
    else {
        if (dcm_mcubus_dcm_off>0) 
            dcm_mcubus_dcm_off--;
    }
#if defined (DCM_ENABLE)
	if((0 != dcm_mcubus_dcm_off))
	{
		DRV_ClrReg32(MD_GLOBAL_CON1, 1UL<<25);
	}
	else
	{
		DRV_SetReg32(MD_GLOBAL_CON1, 1UL<<25);
	}
#endif //#if defined (DCM_ENABLE)
    RestoreIRQMask(_savedMask);
}

#endif //__MTK_TARGET__
