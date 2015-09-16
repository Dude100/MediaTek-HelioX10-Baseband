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
 *    upll_ctrl.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  This file implements upll control functions
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#include "kal_non_specific_general_types.h"
//#include "kal_release.h"
#include "kal_public_api.h"
#include "init.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "config_hw.h"
#include "upll_ctrl.h"
#include "usb_drv.h"
#include "drvpdn.h"
#include "kal_public_api.h"



/* Record all upll enable owners */
kal_uint32 g_upll_owner = 0;


/*
* FUNCTION                                                            
*	UPLL_Enable
*
* DESCRIPTION                                                           
*   	This function is to enable UPLL
*
* CALLS  
*	It is called to enable UPLL
*
* PARAMETERS
*	owner = UPLL owner
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/

void UPLL_Enable(UPLL_OWNER owner)
{
#if  (defined(DRV_UPLL_V1)||defined(DRV_UPLL_V2)||defined(DRV_UPLL_V3)||defined(DRV_UPLL_V4)||defined(DRV_UPLL_V5)||defined(DRV_UPLL_V6)||defined(DRV_UPLL_V7)||defined(DRV_UPLL_V8) || defined(DRV_USB_UPLL_MT50_SERIES))

	kal_uint32 savedMask;

	if(owner >= UPLL_OWNER_MAX)
		EXT_ASSERT(0, (kal_uint32)owner, g_upll_owner, 0);

	savedMask = SaveAndSetIRQMask();   

	if(g_upll_owner == 0)
	{
#if defined(DRV_UPLL_V1)
		USB_DRV_SetBits(DRVPDN_CON0_CLR , DRVPDN_CON0_UPLL);
#elif defined(DRV_UPLL_V2)
		/* hardware issue */
		USB_PDNDisable(USB_PDN_OWNER_UPLL);
		USB_DRV_SetBits(DRVPDN_CON0_CLR , DRVPDN_CON0_UPLL);
#elif defined(DRV_UPLL_V3)
		/* select UPLL clock source from PLL */
		USB_DRV_SetBits(PLL , 0x0040);
#elif defined(DRV_UPLL_V4)
		USB_DRV_ClearBits(DRVPDN_CON0 , DRVPDN_CON0_PLL2);
		/* disable USB clock from external clock */
		USB_DRV_ClearBits(CLK_CON , 0x4000);
		USB_DRV_SetBits(PLLSEL , 0x0008);
#elif defined(DRV_UPLL_V5)
		USB_DRV_SetBits(PLL , 0x0040);
#elif defined(DRV_UPLL_V6)
		USB_DRV_SetBits(PDN_CON , 0x0010);
#elif defined(DRV_UPLL_V7)
		USB_DRV_SetBits(UPLL_CON1, 0x0002);
#elif defined(DRV_UPLL_V8)
		USB_DRV_SetBits(GPLL_CON0, 0x0080);
#elif defined(DRV_USB_UPLL_MT50_SERIES)
	if (SW_SEC_0 == INT_SW_SecVersion()) 
	{
		PDN_CLR(PDN_USB_48M);
	}
#endif

	}
	g_upll_owner |= 1<<(kal_uint32)owner;
	RestoreIRQMask(savedMask);
#endif

}

/*
* FUNCTION                                                            
*	UPLL_Disable
*
* DESCRIPTION                                                           
*   	This function is to disable UPLL
*
* CALLS  
*	It is called to disable UPLL
*
* PARAMETERS
*	owner = UPLL owner
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void UPLL_Disable(UPLL_OWNER owner)
{
#if  (defined(DRV_UPLL_V1)||defined(DRV_UPLL_V2)||defined(DRV_UPLL_V3)||defined(DRV_UPLL_V4)||defined(DRV_UPLL_V5)||defined(DRV_UPLL_V6)||defined(DRV_UPLL_V7)||defined(DRV_UPLL_V8)|| defined(DRV_USB_UPLL_MT50_SERIES))

	kal_uint32 savedMask;
   
	if(owner >= UPLL_OWNER_MAX)
		EXT_ASSERT(0, (kal_uint32)owner, g_upll_owner, 0);

	savedMask = SaveAndSetIRQMask();   
	g_upll_owner &= ~(1<<(kal_uint32)owner);
	if(g_upll_owner == 0)
	{
#if defined(DRV_UPLL_V1)
		USB_DRV_SetBits(DRVPDN_CON0_SET , DRVPDN_CON0_UPLL);	
#elif defined(DRV_UPLL_V2)
		/* hardware issue */
		USB_PDNEnable(USB_PDN_OWNER_UPLL);
		USB_DRV_SetBits(DRVPDN_CON0_SET , DRVPDN_CON0_UPLL);	
#elif defined(DRV_UPLL_V3)
		/* select UPLL clock source bypassed PLL  */
		USB_DRV_ClearBits(PLL , 0x0040);
#elif defined(DRV_UPLL_V4)
//		DRV_Reg(DRVPDN_CON0) |= (DRVPDN_CON0_PLL2);
#elif defined(DRV_UPLL_V5)

#elif defined(DRV_UPLL_V6)
//    DRV_Reg(PDN_CON)&= ~(0x0010);  // set this bit will also clear MPLL
#elif defined(DRV_UPLL_V7)
//    DRV_Reg(UPLL_CON1)&= ~(0x0002);
#elif defined(DRV_UPLL_V8)
	USB_DRV_ClearBits(GPLL_CON0, 0x0080);
#elif defined(DRV_USB_UPLL_MT50_SERIES)
	if (SW_SEC_0 == INT_SW_SecVersion()) 
	{
		PDN_SET(PDN_USB_48M);
	}		
#endif
	}
	RestoreIRQMask(savedMask);
#endif

}




