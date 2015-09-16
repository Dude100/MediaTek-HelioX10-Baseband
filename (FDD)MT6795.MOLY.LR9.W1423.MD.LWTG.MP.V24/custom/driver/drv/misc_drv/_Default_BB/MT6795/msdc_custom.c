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
 *    msdc_custom.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements msdc customer support
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
 ****************************************************************************/
#include "drv_comm.h"
#include "msdc_def.h"

// it only apply to the SD card io control
static const msdc_io_ctrl_struct msdc_io_ctrl_sd_custom = 
{
	MSDC_ODC_8MA,	// driving capacity of CMD/BS and SCLK
	MSDC_ODC_8MA,	// driving capacity of data lines
	MSDC_ODC_SLEW_FAST, // slew rate of CMD/BS and SCLK
	MSDC_ODC_SLEW_FAST // slew rate of data lines
};

#if defined(__MSDC_SD_MMC__) && defined(__MSDC2_SD_MMC__)&& !defined(__MSDC_SD_SDIO__)
static  const kal_uint32 msdc_custom = (MSDC_HOT_PLUG|MSDC_WP|MSDC2_HOT_PLUG|MSDC2_WP);
#elif defined(__MSDC_SD_SDIO__) && defined(__MSDC2_SD_MMC__)
static  const kal_uint32 msdc_custom = (MSDC2_HOT_PLUG|MSDC2_WP|MSDC_SDIO4_SD1);
#elif defined(__MSDC_SD_MMC__) && defined(__MSDC2_SD_SDIO__)
static  const kal_uint32 msdc_custom = (MSDC_HOT_PLUG|MSDC_WP|MSDC_SD4_SDIO1);
#else
static const kal_uint32 msdc_custom = (MSDC_HOT_PLUG|MSDC_WP|MSDC2_HOT_PLUG|MSDC2_WP);
#endif
 
kal_uint8 MSDC_GetIOCtrlParam(void)
{
	kal_uint8 reg = 0;
	
	reg = (msdc_io_ctrl_sd_custom.dat_slew << 7) | (msdc_io_ctrl_sd_custom.cmd_clk_slew << 6) 
			|(msdc_io_ctrl_sd_custom.dat_odc<<3)|(msdc_io_ctrl_sd_custom.cmd_clk_odc);
	return reg;
}

/*
	We provide this API because that memory card's layout affect the signal,
	customer can use this API to tuning the suitable DLT when their layout did need.
	In addition to solve the bad layout, we can also try to set a higher clk and tuning the DLT here,
	so that we can run in high CLK stablely.
	
*/
kal_int8 MSDC_GetDLTFromOPCLK(kal_uint32 opClk, kal_uint8 *setRED)
{
	*setRED = 0;
	
	if(1000 > opClk) //this means we use a CLK < 1Mhz, should be used to initialize a card
		return 0xf0;
	switch(opClk){
		case 45500:	//45.5 MHz CLK, this should be only used on MT6268 with second CLK source
			*setRED = 1;
			return 2;
			break;
		case 22750:	//22.75 MHz CLK, this should be only used on MT6268 with second CLK source
			return 4;
			break;
		case 30500:	//30.5 MHz CLK, this should be only used on MT6268 with first CLK source
			return 4;
		case 15250:	//15.25 MHz CLK, this should be only used on MT6268 with first CLK source
			return 4;
			break;
		default:		//deafult return a non-zero value
			return 1;
			break;
	}
		
}


#if defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)

static const msdc_io_ctrl_struct msdc_io_ctrl_sd_custom2 = 
{
	MSDC_ODC_8MA,	// driving capacity of CMD/BS and SCLK
	MSDC_ODC_8MA,	// driving capacity of data lines
	MSDC_ODC_SLEW_FAST, // slew rate of CMD/BS and SCLK
	MSDC_ODC_SLEW_FAST // slew rate of data lines
};

kal_uint8 MSDC_GetIOCtrlParam2(void)
{
	kal_uint8 reg = 0;
	
	reg = (msdc_io_ctrl_sd_custom2.dat_slew << 7) | (msdc_io_ctrl_sd_custom2.cmd_clk_slew << 6) 
			|(msdc_io_ctrl_sd_custom2.dat_odc<<3)|(msdc_io_ctrl_sd_custom2.cmd_clk_odc);
	return reg;
}
#endif // __MSDC2_SD_MMC__

kal_uint32 MSDC_GetCustom(void)
{
	return msdc_custom;
}
