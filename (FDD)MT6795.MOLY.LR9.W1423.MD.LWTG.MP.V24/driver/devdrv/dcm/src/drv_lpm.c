/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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
 *   drv_lpm.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file implements the LowPowerMonitor(LPM) and DCM relative debug function
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_public_api.h"
#include "drv_dcm.h"

#if defined(__MTK_INTERNAL__) && defined (DCM_LPM_ENABLE)
#include "drv_comm.h"
#include "drvpdn.h"
#include "pll.h"
#include "devdrv_trace.h"

#define DBG_L1_LPM_ENABLE (1UL<<0)
#define DBG_L2_LPM_ENABLE (1UL<<1)

#define LPM_REG_CLR_SET(addr, clr_val, set_val)       \
do{                                                   \
	kal_uint32 tmp;                                   \
	tmp = (DRV_Reg32(addr) & (~(clr_val)))|(set_val); \
    DRV_WriteReg32((addr), (tmp));                    \
}while(0)
static void DCM_Trace(void);

static volatile kal_uint32 dbg_lpm_enable = DBG_L1_LPM_ENABLE | DBG_L2_LPM_ENABLE;

void lpm_init(void)
{
#if 1 /*TBC...*/
	{
		LPM_REG_CLR_SET(PLL_CLKSW_FDIV2, 0xF<<0, 4<<0);
		DRV_SetReg32(PLL_CLKSW_FDIV6, 0x04);
		DRV_SetReg32(PLL_CLKSW_FDIV6, 0x0100);
		DRV_ClrReg32(PLL_CLKSW_FDIV6, 0x0100);
	}
	PDN_CLR(PDN_LPM);
#endif
    /* It is disabled for low power(TOPSM) requirement. */
    kal_set_timer(kal_create_timer("DCM_Timer"), 
                 (kal_timer_func_ptr)DCM_Trace,
                 NULL, 
                 KAL_TICKS_5_SEC, 
                 KAL_TICKS_5_SEC);    
}

static void DCM_Trace(void)
{
    static kal_uint32 src_sel;
	int timeout = 0;

	if (dbg_lpm_enable & DBG_L1_LPM_ENABLE) {
        DRV_ClrReg32(MD_L1_LPM_CON0, 1UL<<2);         //Stop L1 LPM

		kal_dev_trace(DRIVER_GROUP_SYSTEM, LPM_L1,
				      DRV_Reg32(MD_L1_LPM_CON0),
					  DRV_Reg32(MD_L1_LPM_STATUS0), 
					  DRV_Reg32(MD_L1_LPM_STATUS1),
					  DRV_Reg32(MD_L1_LPM_STATUS2));
	
		src_sel = (DRV_Reg32(MD_L1_LPM_CON0) & (0x0f<<4)) >> 4;
		src_sel = ((src_sel+1) & 0x0f) << 4;
#if 1 //32k
		DRV_WriteReg32(MD_L1_LPM_CON0, 2|0); //assert reset
		for(timeout=500; timeout>0; timeout--) {
			if (DRV_Reg32(MD_L1_LPM_STATUS0) == 0) {
				DRV_WriteReg32(MD_L1_LPM_CON0, 2|1); //deassert reset
				break;
			}
		}
		timeout = 0;
#else //pll
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

		//debug only
		LPM_REG_CLR_SET(MD_L1_LPM_CON0, (0xffff<<16), timeout<<16);

		LPM_REG_CLR_SET(MD_L1_LPM_CON0, (0xf<<4), (src_sel));
		DRV_SetReg32_NPW(MD_L1_LPM_CON0, 1<<2);
	}

	if (dbg_lpm_enable & DBG_L2_LPM_ENABLE) {
		DRV_ClrReg32(MD_L2_LPM_CON0, 1<<2); //Stop L2 LPM

		kal_dev_trace(DRIVER_GROUP_SYSTEM, LPM_L2,
				      DRV_Reg32(MD_L2_LPM_CON0),
					  DRV_Reg32(MD_L2_LPM_STATUS0), 
					  DRV_Reg32(MD_L2_LPM_STATUS1), 
					  DRV_Reg32(MD_L2_LPM_STATUS2));
	
		src_sel = (DRV_Reg32(MD_L2_LPM_CON0) & (0x0f<<4)) >> 4;
		src_sel = ((src_sel+1) & 0x0f) << 4;
#if 1 //32k
		DRV_WriteReg32(MD_L2_LPM_CON0, 2|0); //assert reset
		for(timeout=500; timeout>0; timeout--) {
			if (DRV_Reg32(MD_L2_LPM_STATUS0) == 0) {
				DRV_WriteReg32(MD_L2_LPM_CON0, 2|1); //deassert reset
				break;
			}
		}
		timeout = 0;
#else
/* under construction !*/
/* under construction !*/
#endif
		//debug only
		LPM_REG_CLR_SET(MD_L2_LPM_CON0, (0xffff<<16), timeout<<16);

		LPM_REG_CLR_SET(MD_L2_LPM_CON0, (0xf<<4), (src_sel)); //idle source
		DRV_SetReg32_NPW(MD_L2_LPM_CON0, (1UL<<2));
	}
}
#endif /* __MTK_INTERNAL__ && DCM_LPM_ENABLE */

