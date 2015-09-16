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
 *   sd.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   driver functons for SD/MMC 
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/
#ifndef DRV_MSDC_OFF
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
//RHR ADD
#include "kal_general_types.h"
//#include "btif_sw.h"
#include "kal_public_api.h"
//#include "kal_internal_api.h"
#include "kal_debug.h"
#include "kal_public_defs.h"
//RHR REMOVE
/*
//MSBB remove #include "app_buff_alloc.h"
#include "intrCtrl.h"
#include "gpio_sw.h"
#include "init.h"
*/
//RHR
#include "drv_comm.h"
#include "msdc_reg_adap.h"
#include "msdc_def.h"
#include "sd_def.h"
#include "reg_base.h"
#include "upll_ctrl.h"

#if defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)
T_SDC_HANDLE	*gSD2 = &gSD_blk[SD_MSDC2];
extern MSDC_HANDLE *msdc2_handle;
extern kal_uint32 MSDC_Sector2[128];

extern kal_uint8 MSDC_GetIOCtrlParam(void);
extern kal_bool INT_USBBoot(void);
extern int MSDC_GetCustom(void);

/*************************************************************************
* FUNCTION
*  SD_Acmd42
*
* DESCRIPTION
*	connect/disconnect the 50K Ohm pull-up resistor on CD/DAT3
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*	
*
*************************************************************************/
SDC_CMD_STATUS SD_Acmd42_2(kal_bool connect)
{
	SDC_CMD_STATUS status;

	// send APP_CMD
	if((status = SD_Cmd55_2(gSD2->mRCA))!=NO_ERROR)
		return status;
	// send cmd6
	if((status = SD_Send_Cmd_2(SDC_CMD_ACMD42,connect))!=NO_ERROR)
		return status;
	//read R1
	if((status = SD_CheckStatus_2())!=NO_ERROR)
		return status;	

	gSD2->mCD_DAT3 = KAL_FALSE;	// pull-up resistor is disconnected for data trnasfer
	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_SetMMC40_4bit_high_speed
*
* DESCRIPTION
*	Check inserted card is SD or MMC
*
* PARAMETERS
*	
*
* RETURNS
*  SD_CARD or MMC_CARD
*
* GLOBALS AFFECTED
*	gMSDC_Handle
*
*************************************************************************/
SDC_CMD_STATUS SD_SetMMC40_bus_high_speed_2(void)
{
		kal_uint32 clock, hs;
	#ifdef DRV_MSDC_MT6225_SERIES
		/*use larger driving current. In mt6225 and mt6227D, IOCON is 32 bit register and DLT cannot be 0*/
		MSDC_LSD_WriteReg(MSDC_IOCON2,0x36);
		MSDC_SetIOCONRegDLT2();
	#else
		MSDC_LSD_WriteReg(MSDC_IOCON2,0x1B);
	#endif

		if(SD_SetBlength_2(512)!=NO_ERROR)			
			goto err;
		
		// read the EXT_CSD
		if(SD_SendEXTCSD_MMC40_2(MSDC_Sector2) != NO_ERROR)
			goto err;;

		// set high speed
		if(gSD2->mCSD.ext_csd->card_type & HS_52M)
		{
			// should be 52000
			//clock = 52000;
                        clock = msdc2_handle->msdc_clock / 2;
			hs = 1;
			//MSDC_LSD_WriteReg32(MSDC_IOCON,0x010002FF);
			MSDC_LSD_ClearBits32(MSDC_CFG2,MSDC_CFG_CRED);;
			
		}
		else if(gSD2->mCSD.ext_csd->card_type & HS_26M)
		{
			// should be 26000
			clock = 26000;
			hs = 1;
		}
		else
		{
			clock = 13000;
			hs = 0;
		}
		if(hs)
		{
			// select proper power class
			if(SD_Switch_MMC40_2(SET_BYTE,EXT_CSD_POW_CLASS_INDEX,
				(gSD2->mCSD.ext_csd->pwr_52_360&0xf) ,0) != NO_ERROR)
				goto err;
			
			// enable high speed (26M or 52M)
			if(SD_Switch_MMC40_2(SET_BYTE,EXT_CSD_HIGH_SPPED_INDEX,
				EXT_CSD_ENABLE_HIGH_SPEED,0) != NO_ERROR)
				goto err;

			// latch data at falling edge to cover the card driving capability
			// MSDC_LSD_SetBits32(MSDC_CFG2,MSDC_CFG_RED);			
		}
		
		msdc2_handle->msdc_clock = MSDC_CLOCK;
		MSDC_SetClock2(clock);
	
	#ifdef DRV_MSDC_MT6225_SERIES
		/*change DLT and set cmd latch at rising edge*/
		MSDC_LSD_WriteReg(MSDC_IOCON2,0x8036);
		MSDC_SetIOCONRegDLT2();
	#endif

		#if 0  // MSDC2 only support 1-bit data
/* under construction !*/
		#if defined(MMC40_USE_4BIT_BUS)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#elif defined(MMC40_USE_8BIT_BUS)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
		#endif
		
		if(SD_SendEXTCSD_MMC40_2(MSDC_Sector2) != NO_ERROR)
			goto err;;
				
		return NO_ERROR;
err:
		return ERR_MMC_BUS_HS_ERROR;
}
/*************************************************************************
* FUNCTION
*  SD_CheckSDorMMC
*
* DESCRIPTION
*	Check inserted card is SD or MMC
*
* PARAMETERS
*	
*
* RETURNS
*  SD_CARD or MMC_CARD
*
* GLOBALS AFFECTED
*	gMSDC_Handle
*
*************************************************************************/
T_MSDC_CARD SD_CheckSDorMMC_2()
{
	SDC_CMD_STATUS status; 

#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
	SD_Cmd8_2();
#endif
	if((status = SD_Acmd41_SD_2())==NO_ERROR)
		return msdc2_handle->mMSDC_type;	// SD_CARD
	else if((status = SD_Cmd1_MMC_2())==NO_ERROR)
		return msdc2_handle->mMSDC_type;	// MMC_CARD

	return UNKNOWN_CARD;
}
/*************************************************************************
* FUNCTION
*  SD_SetDefault
*
* DESCRIPTION
*	set default values to gSD
*
* PARAMETERS
*	
*
* RETURNS
*
* GLOBALS AFFECTED
*	gSD
*
*************************************************************************/
void SD_SetDefault_2(void)
{
	kal_mem_set(gSD2,0,sizeof(T_SDC_HANDLE));
	gSD2->mBKLength = 512;
	gSD2->mRCA = 0;
	gSD2->mInactive = KAL_FALSE;
	gSD2->mState = IDLE_STA;
	gSD2->bus_width = 1;
	gSD2->mCD_DAT3 = KAL_TRUE;
}

void SD_Use24M_Clock_2(void)
{
	if(msdc2_handle->mMSDC_type == SD_CARD || msdc2_handle->mMSDC_type == SD20_LCS_CARD
		|| msdc2_handle->mMSDC_type == SD20_HCS_CARD)
	{
		UPLL_Enable(UPLL_OWNER_MSDC2);
		MSDC_LSD_SetBits32(MSDC_CFG2, MSDC_CFG_CLKSRC);
		msdc2_handle->msdc_clock = MSDC_CLOCK_USB;
		MSDC_SetClock2(MSDC_SD_OP_CLOCK);
		gSD2->flags |= SD_FLAG_USE_USB_CLK;	
	}
}

void SD_Use13M_Clock_2(void)
{
	MSDC_LSD_ClearBits32(MSDC_CFG2, MSDC_CFG_CLKSRC);
	msdc2_handle->msdc_clock = MSDC_CLOCK;
	MSDC_SetClock2(MSDC_OP_CLOCK);
	gSD2->flags &= ~SD_FLAG_USE_USB_CLK;
}


/*************************************************************************
* FUNCTION
*  SD_Initialize
*
* DESCRIPTION
*	Initial SD controller and card
*
* PARAMETERS
*	
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
*************************************************************************/
SDC_CMD_STATUS SD_Initialize_2(void)
{
	kal_uint32 cid[4],csd[4],scr[4];
	kal_uint16 rca, iocon;
	SDC_CMD_STATUS status;

	if(msdc2_handle->mIsInitialized == KAL_TRUE)
	{
		return NO_ERROR;
	}
	// reset the events
	kal_set_eg_events(msdc2_handle->MSDC_Events, 0, KAL_AND);
	// reset msdc
	if(MSDC_Reg32(MSDC_CFG2) & MSDC_CFG_RST)
	{
		MSDC_LSD_ClearBits32(MSDC_CFG2, MSDC_CFG_RST);
	}
	else
	{
		RESET_MSDC2();
	}
	
	#if defined(DRV_MSDC_MT6225_SERIES)
	MSDC_LSD_SetBits32(MSDC_CFG2,MSDC_CFG_CRED);
	#endif
	
	// set the output driving capability from customization interface
	iocon = MSDC_SetData(MSDC_IOCON2, 0xff, MSDC_GetIOCtrlParam2());		
	// set pull up the data and cmd 
	BitFieldWrite32((kal_uint32*)MSDC_CFG2,(kal_uint32)2,MSDC_CFG_PRCFG0);
	BitFieldWrite32((kal_uint32*)MSDC_CFG2,(kal_uint32)2,MSDC_CFG_PRCFG1);
	BitFieldWrite32((kal_uint32*)MSDC_CFG2,(kal_uint32)2,MSDC_CFG_PRCFG2);	
	// set read timeout x5ms
	BitFieldWrite32((kal_uint32*)SDC_CFG2,(kal_uint32)40,SDC_CFG_DTOC);
	//set clock of serial clcok for initialization
	MSDC_LSD_ClearBits32(MSDC_CFG2, MSDC_CFG_CLKSRC);
	msdc2_handle->msdc_clock = MSDC_CLOCK;
	MSDC_SetClock2(MSDC_INI_CLOCK);	
	MSDC_LSD_ClearBits32(SDC_CFG2,SDC_CFG_MDLEN);
	// initial global sturctures
	SD_SetDefault_2();
		
	// send the card to IDLE state
	if((status = SD_Reset_2())!=NO_ERROR)
	{
		goto err;
	}

	// and validate the OCR  (CMD0,CMD1 or ADMD41)
	if(SD_CheckSDorMMC_2() == UNKNOWN_CARD)
	{
		status = ERR_STATUS;
		goto err;
	}

	// get CID(CMD2)
	if((status = SD_GetCID_2(cid))!=NO_ERROR)
	{
		goto err;
	}
	// get or set RCA(CMD3)
	if((status = SD_ValidateRCA_2(&rca))!=NO_ERROR)
	{
		goto err;
	}
	// get CSD and analysis the CSD(CMD9)
	if((status = SD_GetCSD_2(gSD2->mRCA,csd))!=NO_ERROR)
	{
		goto err;
	}		
	// Set driver stage register DSR to default value (0x0404)(CMD4)
	if(gSD2->mCSD.dsr_imp)
		if((status = SD_SetDSR_2())!=NO_ERROR)
		{
			//dbg_print("6\r\n");
			goto err;
		}
	
	if(MSDC_GetCustom() & MSDC2_WP)
	{
		if((MSDC_Reg(SDC_STA2) & SDC_STA_WP))
			gSD2->mWPEnabled = KAL_TRUE;
	}
	status = SD_SelectCard_2(gSD2->mRCA);
	if(status == CARD_IS_LOCKED)
		gSD2->mIsLocked = KAL_TRUE;

	#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
	if(gSD2->flags & SD_FLAG_SD_TYPE_CARD)
	#else
	if(msdc2_handle->mMSDC_type == SD_CARD)
	#endif
	{		
		SD_Use24M_Clock_2();
		MSDC_SetIOCONRegDLT2();
		if((status = SD_ReadSCR_2(scr))!=NO_ERROR)
		{
			goto err;
		}	
		#if 0 // MSDC2 only support 1-bit data
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
		
		#if !defined(__MSDC_TFLASH_DAT3_1BIT_HOT_PLUG__)
		if((status = SD_Acmd42_2(KAL_FALSE))!=NO_ERROR)
		{
			goto err;
		}
		#endif
		
		if(gSD2->flags & SD_FLAG_CMD6_SUPPORT)
		{
			status = SD_SelectHighSpeed_SD11_2();
			if(status == NO_ERROR)
			{
				gSD2->flags |= SD_FLAG_HS_ENABLED;
				MSDC_LSD_ClearBits32(MSDC_CFG2, MSDC_CFG_CLKSRC);
				msdc2_handle->msdc_clock = MSDC_CLOCK;
				MSDC_SetClock(26000);			
			}
		}
	}
	else
	{
		#if defined(MSDC_MMC40_SUPPORT)
		if(msdc2_handle->mMSDC_type == MMC_CARD && gSD2->mCSD.spec_ver >= 4)
		{
			msdc2_handle->mMSDC_type = MMC40_CARD;
			if((status = SD_SetMMC40_bus_high_speed_2())!= NO_ERROR)
				goto err;
		}	
		else
		#endif
		{
			SD_Use13M_Clock_2();
		}
	}
	status = SD_SetBlength_2(512);
err:	
	if(status != NO_ERROR)
	{
		tst_sys_trace("SD2 mount fail!");
		SD_SetDefault();
		msdc2_handle->mIsInitialized = KAL_FALSE;
	}
	else
	{
		tst_sys_trace("SD2 mount ok!");
		msdc2_handle->mIsInitialized = KAL_TRUE;
	}
	kal_set_eg_events(msdc2_handle->MSDC_Events, 0, KAL_AND);

	return status	;
}

static kal_uint32 power2(kal_uint32 num)
{
   return 1 << num;
}

/*************************************************************************
* FUNCTION
*  SD_AnalysisCSD
*
* DESCRIPTION
*	Analysis Card Specific Data and store in the member of gSD
*
* PARAMETERS
*	csd: input csd for analysis
* RETURNS
*
* GLOBALS AFFECTED
*	gSD
*
*************************************************************************/
void SD_AnalysisCSD_2(kal_uint32* csd)
{	
	kal_uint8 *ptr;
	kal_uint32 c_mult,c_size;
	
	ptr = (kal_uint8*)csd;
	c_mult = c_size = 0;
	// these offsets refer to the spec. of SD and MMC 
	GetBitFieldN((kal_uint8*)&gSD2->mCSD.csd_ver, ptr, 126,2);	
	GetBitFieldN((kal_uint8*)&gSD2->mCSD.tacc,ptr,112,8);
	GetBitFieldN((kal_uint8*)&gSD2->mCSD.nsac,ptr,104,8);
	GetBitFieldN((kal_uint8*)&gSD2->mCSD.tran_speed,ptr,96,8);
	GetBitFieldN((kal_uint8*)&gSD2->mCSD.ccc,ptr,84,12);
	GetBitFieldN((kal_uint8*)&gSD2->mCSD.r_blk_len,ptr,80,4);
	gSD2->mCSD.r_blk_len = power2(gSD2->mCSD.r_blk_len);
	GetBitFieldN((kal_uint8*)&gSD2->mCSD.r_blk_part,ptr,79,1);
	GetBitFieldN((kal_uint8*)&gSD2->mCSD.w_blk_misali,ptr,78,1);
	GetBitFieldN((kal_uint8*)&gSD2->mCSD.r_blk_misali,ptr,77,1);
	GetBitFieldN((kal_uint8*)&gSD2->mCSD.dsr_imp,ptr,76,1);
	GetBitFieldN((kal_uint8*)&gSD2->mCSD.w_blk_part,ptr,21,1);
	GetBitFieldN((kal_uint8*)&gSD2->mCSD.w_blk_len,ptr,22,4);
	gSD2->mCSD.w_blk_len = power2(gSD2->mCSD.w_blk_len);
	GetBitFieldN((kal_uint8*)&gSD2->mCSD.wp_grp_enable,ptr,31,1);
	// there are some difference of CSD between SD and MMC
	if(msdc2_handle->mMSDC_type == MMC_CARD)
	{
		GetBitFieldN((kal_uint8*)&gSD2->mCSD.spec_ver, ptr, 122,4);		
		GetBitFieldN((kal_uint8*)&gSD2->mCSD.erase_sec_size_mmc,ptr,42,5);
		gSD2->mCSD.erase_sec_size_mmc = (gSD2->mCSD.erase_sec_size_mmc+1)*gSD2->mCSD.w_blk_len; 
		GetBitFieldN((kal_uint8*)&gSD2->mCSD.erase_grp_size_mmc,ptr,37,5);
		gSD2->mCSD.erase_grp_size_mmc = (gSD2->mCSD.erase_grp_size_mmc+1)*gSD2->mCSD.erase_sec_size_mmc;
		GetBitFieldN((kal_uint8*)&gSD2->mCSD.wp_grp_size_mmc,ptr,32,5);		
		gSD2->mCSD.wp_grp_size_mmc = (gSD2->mCSD.wp_grp_size_mmc + 1)*gSD2->mCSD.erase_grp_size_mmc;	
	}
	else // SD_CARD
	{
		GetBitFieldN((kal_uint8*)&gSD2->mCSD.erase_sec_size_sd,ptr,39,7);
		gSD2->mCSD.erase_sec_size_sd += 1;
		GetBitFieldN((kal_uint8*)&gSD2->mCSD.wp_prg_size_sd,ptr,32,7);
		gSD2->mCSD.wp_prg_size_sd = (gSD2->mCSD.wp_prg_size_sd+1) * gSD2->mCSD.erase_sec_size_sd;
		GetBitFieldN((kal_uint8*)&gSD2->mCSD.erase_blk_en_sd,ptr,46,1);
	}
	
	#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
	if(msdc2_handle->mMSDC_type == SD20_HCS_CARD && gSD2->mCSD.csd_ver >= SD_CSD_VER_20)
	{
		GetBitFieldN((kal_uint8*)&c_size,ptr,48,22);
		gSD2->mBKNum = (c_size+1);
		gSD2->mCSD.capacity = (kal_uint64)gSD2->mBKNum*512*1024;
	}
	else
	#endif
	{
		GetBitFieldN((kal_uint8*)&c_mult,ptr,47,3);
		c_mult = power2(c_mult+2);
		GetBitFieldN((kal_uint8*)&c_size,ptr,62,12);
		gSD2->mBKNum = (c_size+1)*c_mult;
		gSD2->mCSD.capacity = (c_size+1)*c_mult*gSD2->mCSD.r_blk_len;
	}
	
}

/*************************************************************************
* FUNCTION
*  SD_AnalysisCID
*
* DESCRIPTION
*	Analysis Card Identificaton and store in the member of gSD
*
* PARAMETERS
*	cid: input of card ID for analysis
* RETURNS
*
* GLOBALS AFFECTED
*	gSD
*
*************************************************************************/
void SD_AnalysisCID_2(kal_uint32* cid)
{
	kal_uint8	i;
	kal_uint8* pcid;
	pcid = (kal_uint8*)cid;

	if(msdc2_handle->mMSDC_type == MMC_CARD)
	{
		GetBitFieldN((kal_uint8*)&gSD2->mCID.year,pcid,8,4);
		gSD2->mCID.year += 1997;
		GetBitFieldN((kal_uint8*)&gSD2->mCID.month,pcid,12,4);
		GetBitFieldN((kal_uint8*)&gSD2->mCID.psn,pcid,16,32);
		GetBitFieldN((kal_uint8*)&gSD2->mCID.prv,pcid,48,8);
		for(i=0;i<6;i++)
			gSD2->mCID.pnm[i] = *(pcid+7+i);
		GetBitFieldN((kal_uint8*)&gSD2->mCID.oid,pcid,104,16);
		GetBitFieldN((kal_uint8*)&gSD2->mCID.mid,pcid,120,8);
		
		// special case handling
		{
			kal_uint8 pnm[] = {0xFF,0xFF,0xFF,0xFF,0x36,0x31};
			if(gSD2->mCID.mid == 6 && gSD2->mCID.oid == 0 &&
				!kal_mem_cmp(gSD2->mCID.pnm,pnm,6))
			{
				gSD2->flags |= SD_FLAG_MMC_MRSW_FAIL;
			}
		}
	}
	else // SD_CARD
	{
		gSD2->mCID.mid = *(pcid+15);
		gSD2->mCID.oid = *(pcid+13) + 256*(*(pcid+14));
		for(i=0;i<5;i++)
			gSD2->mCID.pnm[i] = *(pcid+8+i);
		gSD2->mCID.prv = *(pcid+7);
		//gSD2->mCID.psn = *(kal_uint32*)(pcid+3);
		gSD->mCID.psn = (*(kal_uint32*)(pcid+4)<<8)|*(pcid+3);
		gSD2->mCID.month = (kal_uint8)GET_BIT(*(pcid+1),0,BIT_MASK_4);
		gSD2->mCID.year = GET_BIT(*(pcid+1),4,BIT_MASK_4)+16*GET_BIT(*(pcid+2),0,BIT_MASK_4) + 2000;
	}
}

/*************************************************************************
* FUNCTION
*  SD_AnalysisSCR
*
* DESCRIPTION
*	Analysis SD Card Configuration Register and store in the member of gSD
*
* PARAMETERS
*	scr: input of scr for analysis
* RETURNS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*	Only for SD card.
*
*************************************************************************/
void SD_AnalysisSCR_2(kal_uint32* scr)
{
	kal_uint8 *pscr;

	pscr = (kal_uint8*)scr;
	gSD2->mSCR.spec_ver = (kal_uint8)GET_BIT(*(pscr),0,BIT_MASK_4);
	if(gSD2->mSCR.spec_ver > SD_SPEC_101)
		gSD2->flags |= SD_FLAG_CMD6_SUPPORT;
	gSD2->mSCR.dat_after_erase = (kal_uint8)GET_BIT(*(pscr+1),7,BIT_MASK_1);
	gSD2->mSCR.security = (kal_uint8)GET_BIT(*(pscr+1),4,BIT_MASK_3);
	gSD2->mSCR.bus_width = (kal_uint8)GET_BIT(*(pscr+1),0,BIT_MASK_4);
}

/*************************************************************************
* FUNCTION
*  SD_WaitCmdRdyOrTo
*
* DESCRIPTION
*	Wait until command ready or timeout
*
* PARAMETERS
*	
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*	Interrupt driven and polling are both implemented
*
*************************************************************************/
SDC_CMD_STATUS SD_WaitCmdRdyOrTo_2(void)
{
	MSDC_START_TIMER2(MSDC_TIMEOUT_PERIOD_CMD);

	{
	volatile kal_uint16 sdc_cmdsta;
	kal_uint32 t1;

	t1 = drv_get_current_time();
	while(!(sdc_cmdsta = MSDC_Reg(SDC_CMDSTA2))
		&& MSDC_Check_Card_Present2() && !msdc2_handle->is_timeout)
	{
		if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_CMD*11)
			msdc2_handle->is_timeout = KAL_TRUE;
	}
	MSDC_STOP_TIMER2();
	MSDC_CLR_INT2();
	msdc2_handle->cmd_sta = sdc_cmdsta;
	if(sdc_cmdsta & SDC_CMDSTA_CMDTO)            
	{
		kal_prompt_trace(MOD_MSDC_HISR,"[MSDC]:cmd timeout");
		return ERR_CMD_TIMEOUT;
	}
	else if(sdc_cmdsta & SDC_CMDSTA_RSPCRCERR)   
	{
		kal_prompt_trace(MOD_MSDC_HISR,"[MSDC]:cmd crc");
		return ERR_CMD_RSPCRCERR;
	}
	else if(sdc_cmdsta & SDC_CMDSTA_CMDRDY)      
		return NO_ERROR;                                     	
	}
	if(msdc2_handle->is_timeout)
		return MSDC_GPT_TIMEOUT_ERR;
	
	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_WaitDatRdyOrTo_2
*
* DESCRIPTION
*	Wait until data ready or timeout
*
* PARAMETERS
*	
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*	Interrupt driven and polling are both implemented
*
*************************************************************************/
SDC_CMD_STATUS SD_WaitDatRdyOrTo_2(void)
{
	MSDC_START_TIMER2(MSDC_TIMEOUT_PERIOD_DAT);
	

	{
	volatile kal_uint16 sdc_datsta;	
	kal_uint32 t1;

	t1 = drv_get_current_time();
	while(!(sdc_datsta = MSDC_Reg(SDC_DATSTA2))
		&& MSDC_Check_Card_Present2() && !msdc2_handle->is_timeout)
	{
		if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT*11)
			msdc2_handle->is_timeout = KAL_TRUE;		
	};
	MSDC_STOP_TIMER2();
	MSDC_CLR_INT2();
	msdc2_handle->dat_sta = sdc_datsta;
	if(sdc_datsta & SDC_DATSTA_DATTO)              
	{
		kal_prompt_trace(MOD_MSDC_HISR,"[MSDC]:dat timeout");
		return ERR_DAT_TIMEOUT;                    
	}
	else if(sdc_datsta & SDC_DATSTA_DATCRCERR)     
	{
		kal_prompt_trace(MOD_MSDC_HISR,"[MSDC]:dat crc");
		return ERR_DAT_CRCERR;                     
	}
	else if(sdc_datsta & SDC_DATSTA_BLKDONE)       
		return NO_ERROR;                                     
	}
	if(msdc2_handle->is_timeout)
		return MSDC_GPT_TIMEOUT_ERR;
	
	return NO_ERROR;
}
/*************************************************************************
* FUNCTION
*  SD_WaitCardNotBusy_2
*
* DESCRIPTION
*	Wait until card is not busy (R1b)
*
* PARAMETERS
*	
* RETURNS
*	void
*
* GLOBALS AFFECTED
*	
* NOTE
*	Interrupt driven and polling are both implemented
*
*************************************************************************/

SDC_CMD_STATUS SD_WaitCardNotBusy_2(void)
{
	kal_uint32 t1;

	t1 = drv_get_current_time();
	MSDC_START_TIMER2(MSDC_TIMEOUT_PERIOD_DAT);
#ifdef MSDC_USE_INT
	{
	kal_uint32 	flags = 0;
	if(!msdc2_handle->mIsPresent)
		return;
	kal_retrieve_eg_events(msdc2_handle->MSDC_Events,EVENT_SDR1BIRQ,KAL_AND_CONSUME,&flags,KAL_SUSPEND);				
	}
#else	
	{
	while(SD_IS_R1B_BUSY_2 && MSDC_Check_Card_Present2() && !msdc2_handle->is_timeout)
	{
		if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT*11)
			msdc2_handle->is_timeout = KAL_TRUE;
	};
	MSDC_CLR_INT2();
	MSDC_STOP_TIMER2();
	}
#endif

	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_CheckStatus_2
*
* DESCRIPTION
*	Check command status
*
* PARAMETERS
*	
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_CheckStatus_2()
{
	kal_uint32 status;

	MSDC_LSD_ReadReg32(SDC_RESP02,&status);
	if(status & SDC_CSTA_MASK)
		ASSERT(0);
	if((status & SDC_CSTA_MASK)==0 )
		return NO_ERROR;
	if(status &SDC_CARD_IS_LOCKED)
		return CARD_IS_LOCKED;

	return ERR_STATUS;
}

/*************************************************************************
* FUNCTION
*  SD_Send_Cmd_2
*
* DESCRIPTION
*	to launch the command packet to the card
*
* PARAMETERS
*	1. cmd: the content of SDC_CMD register
*	2. arg: the argument(if the command need no argument, fill it with 0)
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*	1. Check if controller is available  before launch any commands 
*	2. Maybe add check if card is busy (R1b)
*************************************************************************/
SDC_CMD_STATUS SD_Send_Cmd_2(kal_uint32 cmd, kal_uint32 arg)
{
	SDC_CMD_STATUS status;
	kal_uint32 t1;

	t1 = drv_get_current_time();
	MSDC_START_TIMER2(MSDC_TIMEOUT_PERIOD_CMD);
	// check the controller is ready (stop transaction will fail)
	if(cmd != SDC_CMD_CMD12)		
	{
		while(SD_IS_SDC_BUSY_2 && MSDC_Check_Card_Present2() && !msdc2_handle->is_timeout)
		{
			if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT*11)
				msdc2_handle->is_timeout = KAL_TRUE;
		}
	}
	else
	{
		while(SD_IS_CMD_BUSY_2 && MSDC_Check_Card_Present2() && !msdc2_handle->is_timeout)
		{
			if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT*11)
				msdc2_handle->is_timeout = KAL_TRUE;
		}
	}
	MSDC_STOP_TIMER2();
	if(msdc2_handle->is_timeout)
		return MSDC_GPT_TIMEOUT_ERR;
	
	MSDC_CLR_INT2();
	// fill out the argument
	MSDC_LSD_WriteReg32(SDC_ARG2,arg);
	// launch the command
	MSDC_LSD_WriteReg32(SDC_CMD2,cmd);
	if((status = SD_WaitCmdRdyOrTo_2())!=NO_ERROR)
		return status; 

	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_Reset
*
* DESCRIPTION
*	reset all cards to idle state
*
* PARAMETERS
*	1. cmd: the content of SDC_CMD register
*	2. arg: the argument(if the command need no argument, fill it with 0)
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_Reset_2(void)
{
	SDC_CMD_STATUS status;

	status = SD_Send_Cmd_2(SDC_CMD_CMD0,SDC_NO_ARG);
	gSD2->mState = IDLE_STA;

	return status;
}

/*************************************************************************
* FUNCTION
*  SD_Cmd55_2
*
* DESCRIPTION
*	APP_CMD: inidicate to the card that the next command is an application specified command
*			rather than a standard command
*
* PARAMETERS
*	rca: relative card address
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_Cmd55_2(kal_uint16 rca)
{
	SDC_CMD_STATUS status;

	if((status = SD_Send_Cmd_2(SDC_CMD_CMD55,(kal_uint32)rca<<16))!=NO_ERROR)
		return status;
	//read R1
	if((status = SD_CheckStatus_2())!=NO_ERROR)
		return status;
	//check APP_CMD bit in status register
	MSDC_LSD_ReadReg32(SDC_RESP02,&status);
	if(status & SDC_CSTA_MASK)
		ASSERT(0);
	if(!(status & R1_APP_CMD_5))
		return ERR_APPCMD_FAILED;

	return NO_ERROR;	
}
/*************************************************************************
* FUNCTION
*  SD_Cmd8
*
* DESCRIPTION
*	1. Sends SD Memory Card interface conditions for support larger than 2G cards
*	2. check if the card is compliant to SD2.0 or higher
*	3. only performed while at IDLE state.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*	gSD2->mIsCMD8
*
*************************************************************************/
void SD_Cmd8_2(void)
{
	kal_uint32 resp;

	if(SD_Send_Cmd_2(SDC_CMD_CMD8,SDC_CMD8_ARG)!=NO_ERROR)
	{
		SD_Reset_2();
		gSD2->mCMD8Resp = SD_CMD8_RESP_NORESP;
		return;
	}
	MSDC_LSD_ReadReg32(SDC_RESP02,&resp);
	if(resp == SDC_CMD8_ARG)
		gSD2->mCMD8Resp = SD_CMD8_RESP_VALID;
	else
		gSD2->mCMD8Resp = SD_CMD8_RESP_INVALID;
}

/*************************************************************************
* FUNCTION
*  SD_Cmd1_MMC
*
* DESCRIPTION
*	 asks all cards in idle state to send their OCR in the response on the CMD line
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*	only works for MMC
*
*************************************************************************/
SDC_CMD_STATUS SD_Cmd1_MMC_2(void)
{
	SDC_CMD_STATUS status;
	kal_uint32 _ocr, ocr_i, t1, t2;

	#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
	if(gSD2->mCMD8Resp == SD_CMD8_RESP_INVALID)
		return ERR_CMD8_INVALID;
	ocr_i = (SDC_OCR_DEFAULT|MMC_HIGH_DESITY_CHECK_BIT);
	#else
	ocr_i = SDC_OCR_DEFAULT;
	#endif

	if(msdc2_handle->is_init_timeout == KAL_TRUE)
		return ERR_R3_OCR_BUSY;
	t2 = drv_get_current_time();
	do{
		t1 = drv_get_current_time();
		MSDC_START_TIMER2(MSDC_TIMEOUT_PERIOD_DAT);
		while((MSDC_IS_BUSY2)
			&& MSDC_Check_Card_Present2() && !msdc2_handle->is_timeout)
		{
			if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT*11)
				msdc2_handle->is_timeout = KAL_TRUE;
		};
		MSDC_STOP_TIMER2();		
		if(msdc2_handle->is_timeout)
			return MSDC_GPT_TIMEOUT_ERR;		
		MSDC_LSD_WriteReg32(SDC_ARG2,ocr_i);
		MSDC_LSD_WriteReg32(SDC_CMD2,SDC_CMD_CMD1);
		if((status = SD_WaitCmdRdyOrTo_2())  != NO_ERROR)
		{
			return status;
		}		
		MSDC_LSD_ReadReg32(SDC_RESP02, &_ocr);
		if((_ocr & SDC_OCR_DEFAULT) == 0)
			return ERR_OCR_NOT_SUPPORT;
		if(!msdc2_handle->mIsPresent)
			return MSDC_CARD_NOT_PRESENT;
		
		if(!(_ocr&SDC_OCR_BUSY))		
		{
			if(drv_get_duration_ms(t2) > MSDC_TIMEOUT_PERIOD_INI)
			{
				msdc2_handle->is_init_timeout = KAL_TRUE;			
				break;
			}					
			if((kal_query_systemInit() == KAL_TRUE) 
#ifdef  __TST_WRITE_TO_FILE_ONLY__ 			/*error recording: considering error recording additionally*/
				|| (KAL_TRUE == INT_QueryExceptionStatus())
#endif
			)
				MSDC_GPTI_BusyWait(30);
			else
				kal_sleep_task(7);
				
		}
		else
			break;		
	}while(1);

	if(msdc2_handle->is_init_timeout)
		return ERR_CMD_TIMEOUT;

	#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
	if((_ocr & MMC_HIGH_DESITY_CHECK_MSK) == MMC_HIGH_DESITY_CHECK_BIT)
	{
		gSD2->flags |= SD_FLAG_HCS_SUPPORT;
		msdc2_handle->mMSDC_type = MMC42_CARD;
		tst_sys_trace("MMC4.2 or higher");
	}
	else
	#endif
	msdc2_handle->mMSDC_type = MMC_CARD;
	gSD2->mInactive = KAL_FALSE;
	gSD2->mSDC_ocr = _ocr;
	gSD2->mState = READY_STA;
	
	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_Acmd41_SD
*
* DESCRIPTION
*	asks all cards in idle state to send their OCR in the response on the CMD line
*	OCR: Operation Condition Register
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*	only works for SD
*
*************************************************************************/
SDC_CMD_STATUS SD_Acmd41_SD_2(void)
{

	SDC_CMD_STATUS		status;
	kal_uint32			_ocr = 0, ocr_i, t1, t2;
	
#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)	
	if(gSD2->mCMD8Resp == SD_CMD8_RESP_NORESP)
		ocr_i = SDC_OCR_DEFAULT;
	else if(gSD2->mCMD8Resp == SD_CMD8_RESP_VALID)
		ocr_i = (SDC_OCR_DEFAULT|SD_ACMD41_HCS);
	else if(gSD2->mCMD8Resp == SD_CMD8_RESP_INVALID)
		return ERR_CMD8_INVALID;	
#else	
	ocr_i = SDC_OCR_DEFAULT;
#endif	

	msdc2_handle->is_init_timeout = KAL_FALSE;
	t2 = drv_get_current_time();
	do{
		t1 = drv_get_current_time();		
		MSDC_START_TIMER2(MSDC_TIMEOUT_PERIOD_CMD);
		while((MSDC_IS_BUSY2)
			&& MSDC_Check_Card_Present2() && !msdc2_handle->is_timeout)
		{
			if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_CMD*11)
				msdc2_handle->is_timeout = KAL_TRUE;			
		};
		MSDC_STOP_TIMER2();
		if(msdc2_handle->is_timeout)
			return MSDC_GPT_TIMEOUT_ERR;		
		status=SD_Cmd55_2(SDC_RCA_DEFAULT);
		if(status != NO_ERROR)
		{
			return status;
		}
		MSDC_START_TIMER2(MSDC_TIMEOUT_PERIOD_CMD);
		t1 = drv_get_current_time();
		while((MSDC_IS_BUSY2)
			&& MSDC_Check_Card_Present2() && !msdc2_handle->is_timeout)
		{
			if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_CMD*11)
				msdc2_handle->is_timeout = KAL_TRUE;			
		};
		MSDC_STOP_TIMER2();
		if(msdc2_handle->is_timeout)
			return MSDC_GPT_TIMEOUT_ERR;		
		MSDC_LSD_WriteReg32(SDC_ARG2,ocr_i);
		MSDC_LSD_WriteReg32(SDC_CMD2,SDC_CMD_CMD41_SD);
		if((status = SD_WaitCmdRdyOrTo_2())  != NO_ERROR)
		{
			return status;
		}		
		MSDC_LSD_ReadReg32(SDC_RESP02, &_ocr);
		if((_ocr & SDC_OCR_DEFAULT) == 0)
			return ERR_OCR_NOT_SUPPORT;
		if(!msdc2_handle->mIsPresent)
			return ERR_CARD_NOT_PRESENT;	
		if(!(_ocr&SDC_OCR_BUSY))		
		{
			if(drv_get_duration_ms(t2) > MSDC_TIMEOUT_PERIOD_INI)
			{
				#ifdef DRV_LSD
				LSD_ASSERT(0, __LINE__);
				#endif
				msdc2_handle->is_init_timeout = KAL_TRUE;			
				break;
			}					
			if((kal_query_systemInit() == KAL_TRUE) 
#ifdef  __TST_WRITE_TO_FILE_ONLY__ 			/*error recording: considering error recording additionally*/
				|| (KAL_TRUE == INT_QueryExceptionStatus())
#endif
			)
				MSDC_GPTI_BusyWait(30);
			else
				kal_sleep_task(7);
		}
		else
			break;		
	}
	while(1);

	if(msdc2_handle->is_init_timeout)
		return ERR_R3_OCR_BUSY;

	gSD2->mInactive = KAL_FALSE;
	gSD2->mSDC_ocr = _ocr;
	#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
	gSD2->flags |= SD_FLAG_SD_TYPE_CARD;	
	if(_ocr & SD_ACMD41_HCS)
	{
		gSD2->flags |= SD_FLAG_HCS_SUPPORT;
		msdc2_handle->mMSDC_type = SD20_HCS_CARD;
		tst_sys_trace("SD2.0 or higher");
	}
	else if(gSD2->mCMD8Resp == SD_CMD8_RESP_VALID)
		msdc2_handle->mMSDC_type = SD20_LCS_CARD;
	else
	#endif
		msdc2_handle->mMSDC_type = SD_CARD;
	gSD2->mState = READY_STA;

	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_GetCID
*
* DESCRIPTION
*	Read Card Identification.
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*	
*
*************************************************************************/

// Get CID(CMD2)
SDC_CMD_STATUS SD_GetCID_2(kal_uint32 Cid[4])
{
	int i;
	SDC_CMD_STATUS status;

	if((status = SD_Send_Cmd_2(SDC_CMD_CMD2,SDC_NO_ARG))!=NO_ERROR)
		return status;
	//read R2
	for(i=0;i<4;i++)
		MSDC_LSD_ReadReg32((SDC_RESP02+i*sizeof(kal_uint32)), &Cid[i]);
	SD_AnalysisCID_2(Cid);
	gSD2->mState = IDENT_STA;
	
	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_ValidateRCA
*
* DESCRIPTION
*	assing or read RCA
*
* PARAMETERS
*	pRca: used for input or output RCA
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*	RCA is assinged to MMC card fixed to SDC_RCA_MMC(1)
*
*************************************************************************/

// assign or read RCA
SDC_CMD_STATUS SD_ValidateRCA_2(kal_uint16* pRca)
{
	SDC_CMD_STATUS status;
	kal_uint32 resp;
	kal_uint8  state;

	#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
	if(gSD2->flags & SD_FLAG_SD_TYPE_CARD )
	#else
	if(msdc2_handle->mMSDC_type == SD_CARD)
	#endif
	{
		//read RCA form card
		if((status = SD_Send_Cmd_2(SDC_CMD_CMD3_SD,SDC_NO_ARG))!=NO_ERROR)
			return status;
		//read R6
		MSDC_LSD_ReadReg32(SDC_RESP02, &resp);
		*pRca = resp >>  16;
		gSD2->mRCA =*pRca;
		
	}
	else
	{
		//assign RCA to card
		if((status = SD_Send_Cmd_2(SDC_CMD_CMD3_MMC,(kal_uint32)SDC_RCA_MMC<<16))!=NO_ERROR)
			return status;

		//read R1
		MSDC_LSD_ReadReg32(SDC_RESP02, &resp);
		SD_GetStatus_2(SDC_RCA_MMC,&resp);
		state = 0;
		GetBitFieldN((kal_uint8*)&state,(kal_uint8*)&resp,9,4);
		if(STBY_STA != state)
			return ERR_RCA_FAIL;		
		*pRca = gSD2->mRCA = SDC_RCA_MMC;			
	}

	gSD2->mState = STBY_STA;
	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_SetDSR
*
* DESCRIPTION
*	set default value to the DSR
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	SDC_DSR_DEFAULT(0x404)
*
*************************************************************************/
SDC_CMD_STATUS SD_SetDSR_2(void)
{
	return SD_Send_Cmd_2(SDC_CMD_CMD4,(kal_uint32)SDC_DSR_DEFAULT<<16);
}

/*************************************************************************
* FUNCTION
*  SD_SelectCard
*
* DESCRIPTION
*	select/deselect card
*
* PARAMETERS
*	rca: relative card address
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_SelectCard_2(kal_uint16 rca)
{
	SDC_CMD_STATUS status;

	if((status = SD_Send_Cmd_2(SDC_CMD_CMD7,(kal_uint32)rca<<16))!=NO_ERROR)
		return status;
		
	//read R1b
	if((status = SD_WaitCardNotBusy_2())!=NO_ERROR)	
		return status;
	if((status = SD_CheckStatus_2())!=NO_ERROR)
		return status;

	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_GetCSD
*
* DESCRIPTION
*	Get CSD from addressed card
*
* PARAMETERS
*	rca: relative card address
*	Csd: used for containing read CSD
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_GetCSD_2(kal_uint16 rca, kal_uint32 Csd[4])
{
	SDC_CMD_STATUS status;
	kal_uint32 i;

	if((status = SD_Send_Cmd_2(SDC_CMD_CMD9,(kal_uint32)rca<<16))!=NO_ERROR)
		return status;
	for(i=0;i<4;i++)
	{
		MSDC_LSD_ReadReg32((volatile kal_uint32 *)(SDC_RESP02+i*4), &Csd[i]);
	}
	SD_AnalysisCSD_2(Csd);

	return NO_ERROR;
}

// addressed send CID
SDC_CMD_STATUS SD_GetAddressedCID_2(kal_uint16 rca, kal_uint32 Cid[4])
{
	SDC_CMD_STATUS status;
	kal_uint32 i;

	if((status = SD_Send_Cmd_2(SDC_CMD_CMD10,(kal_uint32)rca<<16))!=NO_ERROR)
		return status;
	for(i=0;i<4;i++)
	{
		MSDC_LSD_ReadReg32((volatile kal_uint32 *)(SDC_RESP02+i*4), &Cid[i]);
	}
	return NO_ERROR;
}


/*************************************************************************
* FUNCTION
*  SD_StopTrans_2
*
* DESCRIPTION
*	Stop Muli-Block operation
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*	definition of SD_STOP_SLOW is used for some erroneous card
*************************************************************************/
SDC_CMD_STATUS SD_StopTrans_2(kal_bool isTx)
{
	SDC_CMD_STATUS status;
	kal_uint32 retry = 0;

	while(retry < 30)
	{
		if((status = SD_Send_Cmd_2(SDC_CMD_CMD12,SDC_NO_ARG))!=NO_ERROR)
		{
			retry ++;
		}
		else
		{
			break;
		}
	}
	if(retry >= 30)
	{
		return status;
	}
	if(isTx)
		SD_WaitCardNotBusy_2();
	

#ifdef SD_STOP_SLOW 	
		while(MSDC_Reg(SDC_STA2) & SDC_STA_R1BSY);
		do{	
		SD_GetStatus_2(gSD2->mRCA,(kal_uint32*)&status);
			}while((status & R1_CUR_STATE) >> 9 !=  TRAN_STA);
#endif

	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_GetStatus_2
*
* DESCRIPTION
*	addressed send status
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_GetStatus_2(kal_uint16 rca, kal_uint32* resp)
{
	SDC_CMD_STATUS status;

	if((status = SD_Send_Cmd_2(SDC_CMD_CMD13,(kal_uint32)rca <<16))!=NO_ERROR)
		return status;

	MSDC_LSD_ReadReg32(SDC_RESP02,resp);
	if((*resp) & SDC_CSTA_MASK)
		ASSERT(0);

	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_SetBlength_2
*
* DESCRIPTION
*	set block length
*
* PARAMETERS
*	BKLength: block length u want to set
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD2->mBKLength
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_SetBlength_2(kal_uint32 BKLength)
{
	SDC_CMD_STATUS status;

	// maximal value of block length is 2048
	if(BKLength > SDC_MAX_BKLENGTH)
		return ERR_INVALID_BKLENGTH;
	if(!gSD2->mCSD.r_blk_part && BKLength < gSD2->mCSD.max_r_blk_len )
		return ERR_INVALID_BKLENGTH;		
	if((status = SD_Send_Cmd_2(SDC_CMD_CMD16,BKLength))!=NO_ERROR)
		return status;
	//read R1
	status = SD_CheckStatus_2();		
	// 2. configure the controller
	gSD2->mBKLength = BKLength;
	BitFieldWrite32((kal_uint32*)SDC_CFG2,BKLength,SDC_CFG_BLKLEN);

	return NO_ERROR;
}


/*************************************************************************
* FUNCTION
*  SD_ReadSingleBlock
*
* DESCRIPTION
*	1. read a single block form data_adrs of card to the rxbuffer
*	2. the block length is set by set block length
*
* PARAMETERS
*	data_adrs: starting address to read
*	rxbuffer: as name
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	the size of rxbuffer should be 4*n (n : integer)
*
*************************************************************************/
SDC_CMD_STATUS SD_ReadSingleBlock_2(kal_uint32 data_adrs, kal_uint32* rxbuffer)
{
	kal_uint32 count;
	SDC_CMD_STATUS status;

	
	EnableMSDC_DMA2();
	count = MSDC_SD_BLOCK_SIZE;
	MSDC_DMATransferFirst2((kal_uint32)rxbuffer,count,KAL_FALSE);
	if((status = SD_Send_Cmd_2(SDC_CMD_CMD17,data_adrs))!=NO_ERROR)	
		goto ERR_Exit;
	if((status = SD_CheckStatus_2())!=NO_ERROR)
		goto ERR_Exit;
	status = MSDC_DMATransferFinal2();
	if(status != NO_ERROR)
	{
		goto ERR_Exit;			
	}		
	if((status = SD_WaitDatRdyOrTo_2())!=NO_ERROR)
		goto ERR_Exit;
	
	DisableMSDC_DMA2();
	MSDC_CLR_FIFO2();
	
	return NO_ERROR;
ERR_Exit:
	{
		kal_uint32 tmp;
		
		#ifdef MSDC_USE_INT
		kal_set_eg_events(msdc2_handle->MSDC_Events, 0, KAL_AND);
		#endif
		DisableMSDC_DMA2();
		RESET_MSDC2();

		// SD_StopTrans_2(KAL_FALSE);		
		SD_GetStatus_2(gSD2->mRCA,(kal_uint32*)&tmp);
		MSDC_LSD_ReadReg32(SDC_DATSTA2,&tmp);
		MSDC_CLR_FIFO2();		
		return status;
	}
	
}

/*************************************************************************
* FUNCTION
*  SD_ReadMultiBlock
*
* DESCRIPTION
*	read num of blocks into rxbuffer
*
* PARAMETERS
*	data_adrs: starting address to read
*	rxbuffer: as name
*	num: number of blocks to read
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_ReadMultiBlock_2(kal_uint32 data_adrs, kal_uint32* rxbuffer, kal_uint32 num)
{
	SDC_CMD_STATUS status;
	kal_uint32 j, count;
	#ifndef MSDC_DMA
	kal_uint32 i;	
	#endif

	EnableMSDC_DMA2();
	count = MSDC_SD_BLOCK_SIZE;	
	MSDC_DMATransferFirst2((kal_uint32)rxbuffer,count*num,KAL_FALSE);	
	#ifndef DRV_LSD
	if((status = SD_Send_Cmd_2(SDC_CMD_CMD18,data_adrs))!=NO_ERROR)
	#else
	LSD_HostSetBuffer((kal_uint8 *)rxbuffer);
	if((status = SD_Send_Cmd_2(SDC_CMD_CMD18|(num<<20) ,data_adrs))!=NO_ERROR)
	#endif
		goto ERR_Exit;
	if((status = SD_CheckStatus_2())!=NO_ERROR)
		goto ERR_Exit;	
	count = MSDC_SD_BLOCK_SIZE;	
	status = MSDC_DMATransferFinal2();
	if(status != NO_ERROR)
			goto ERR_Exit;	

	if((status = SD_WaitDatRdyOrTo_2())!=NO_ERROR)
		goto ERR_Exit;
	
	
	MSDC_CLR_INT2();
	DisableMSDC_DMA2();

	if(gSD2->flags & SD_FLAG_MMC_MRSW_FAIL)
	{
		kal_uint32 delay = 200;
		while(delay--);		
	}
	if((status = SD_StopTrans_2(KAL_FALSE))!=NO_ERROR)
	{
		//if((data_adrs/gSD2->mBKLength + j) < gSD2->mBKNum)			
			goto ERR_Exit;		
	}
	MSDC_CLR_FIFO2();			
	return NO_ERROR;
	
ERR_Exit:

	#ifdef MSDC_USE_INT	
	kal_set_eg_events(msdc2_handle->MSDC_Events, 0, KAL_AND);
	#endif
	DisableMSDC_DMA2();
	RESET_MSDC2();		
	SD_StopTrans_2(KAL_FALSE);		
	SD_GetStatus_2(gSD2->mRCA,(kal_uint32*)&j);
	MSDC_LSD_ReadReg32(SDC_DATSTA2,&j);
	MSDC_CLR_FIFO2();
	return status;
	
}

/*************************************************************************
* FUNCTION
*  SD_WriteSingleBlock
*
* DESCRIPTION
*	write a single block
*
* PARAMETERS
*	address: starting address to write
*	txbuffer: as name
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	block length is set by Set_Block_Length
*
*************************************************************************/
SDC_CMD_STATUS SD_WriteSingleBlock_2(kal_uint32 address, kal_uint32* txbuffer)
{
	SDC_CMD_STATUS status;
	kal_uint32 count;
	kal_uint32 *ptr;	
#if defined(MT6225)
	kal_bool is_aligned;
	ECO_VERSION eco;
	eco = INT_ecoVersion();	
#endif

	if(gSD2->mWPEnabled)
		return ERR_WRITE_PROTECT;
	EnableMSDC_DMA2();
	count = MSDC_SD_BLOCK_SIZE;
	
	#if defined(MT6225)
	if(eco <= ECO_E3)
	{
		is_aligned = ((kal_uint32)txbuffer%4 == 0); 
		if(is_aligned)
		{
			ptr = txbuffer;
		}
		else
		{
			kal_mem_cpy(MSDC_Sector2, txbuffer, 512);
			ptr = MSDC_Sector2;
		}
	}
	else
	{
		ptr = txbuffer;
	}
	#else
	ptr = txbuffer;
	#endif
	
	EnableMSDC_DMA2();
	count = MSDC_SD_BLOCK_SIZE;	
	MSDC_DMATransferFirst2((kal_uint32)ptr,count,KAL_TRUE);	
	if((status = SD_Send_Cmd_2(SDC_CMD_CMD24,address))!=NO_ERROR)
		goto ERR_Exit;
	if((status = SD_CheckStatus_2())!=NO_ERROR)
		goto ERR_Exit;
	status = MSDC_DMATransferFinal2();
	if(status != NO_ERROR)
		goto ERR_Exit;	
	if((status = SD_WaitCardNotBusy_2())!=NO_ERROR)	
		 goto ERR_Exit;	
	DisableMSDC_DMA2();
	if((status = SD_WaitDatRdyOrTo_2())!=NO_ERROR)
		goto ERR_Exit;
	

	return NO_ERROR;
ERR_Exit:
	{
		kal_uint32 tmp;
		
		#ifdef MSDC_USE_INT	
		kal_set_eg_events(msdc2_handle->MSDC_Events, 0, KAL_AND);
		#endif
		DisableMSDC_DMA2();
		RESET_MSDC2();
		SD_GetStatus_2(gSD2->mRCA,(kal_uint32*)&tmp);
		MSDC_LSD_ReadReg32(SDC_DATSTA2,&tmp);
		return status;
	}
	
}

/*************************************************************************
* FUNCTION
*	SD_WriteMultiBlock
*
* DESCRIPTION
*	write num blocks starting at address
*
* PARAMETERS
*	address: starting address to write
*	txbuffer: as name
*	num: number of blocks to write
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	block length is set by Set_Block_Length
*
*************************************************************************/
SDC_CMD_STATUS SD_WriteMultiBlock_2(kal_uint32 address, kal_uint32* txbuffer, kal_uint32 num)
{
	SDC_CMD_STATUS status;
	kal_uint32 count;
	kal_uint32 *ptr;
	#if defined(MT6225)
	kal_bool is_aligned, dma_issue;
	ECO_VERSION eco;
	eco = INT_ecoVersion();	
	if(eco <= ECO_E3) 
		dma_issue = KAL_TRUE;
	#endif
		
	if(gSD2->mWPEnabled)
		return ERR_WRITE_PROTECT;
	EnableMSDC_DMA2();	
	count = MSDC_SD_BLOCK_SIZE;	
	#if defined(MT6225)
	if(dma_issue)
	{
		is_aligned = ((kal_uint32)txbuffer%4 == 0); 
		if(is_aligned)
		{
			MSDC_DMATransferFirst2((kal_uint32)txbuffer,count*num,KAL_TRUE);	
		}
		else
		{
			kal_mem_cpy(MSDC_Sector2, txbuffer, 512);
			ptr = txbuffer;
			MSDC_DMATransferFirst2((kal_uint32)MSDC_Sector2,count,KAL_TRUE);
		}
	}
	else
	{
		MSDC_DMATransferFirst2((kal_uint32)txbuffer,count*num,KAL_TRUE);	
	}
	#elif defined(MSDC_MULTI_BLOCK_WRITE)
	MSDC_DMATransferFirst2((kal_uint32)txbuffer,count*num,KAL_TRUE);
	#else
	ptr = txbuffer;
	MSDC_DMATransferFirst2((kal_uint32)ptr,count,KAL_TRUE);
	#endif
	if((status = SD_Send_Cmd_2(SDC_CMD_CMD25,address))!=NO_ERROR)
		goto ERR_Exit;
	if((status = SD_CheckStatus_2())!=NO_ERROR)
		goto ERR_Exit;
	   
	#if defined(MT6225)
	if(dma_issue)
	{
		if(is_aligned)
		{
			status = MSDC_DMATransferFinal2();
			if(status != NO_ERROR)
				goto ERR_Exit;
			if((status = SD_WaitDatRdyOrTo_2())!=NO_ERROR)
				goto ERR_Exit;		
		}
		else
		{
			kal_uint32 j;
			
			for(j=0;j<num;j++)
			{
				if(msdc2_handle->mIsPresent  == KAL_FALSE)
				{
					status = ERR_CARD_NOT_PRESENT;
					goto ERR_Exit;		
				}
				if(j!=0)
				{
					kal_mem_cpy(MSDC_Sector2, ptr, 512);
					MSDC_DMATransferFirst2((kal_uint32)MSDC_Sector2,count,KAL_TRUE);
				}
				status = MSDC_DMATransferFinal2();
				ptr += MSDC_SD_BLOCK_SIZE; 
				if(status != NO_ERROR)
					goto ERR_Exit;		
				if((status = SD_WaitDatRdyOrTo_2())!=NO_ERROR)	
					goto ERR_Exit;
			}	
		}	
	}
	else
	{
		status = MSDC_DMATransferFinal2();
		if(status != NO_ERROR)
			goto ERR_Exit;
		if((status = SD_WaitDatRdyOrTo_2())!=NO_ERROR)
			goto ERR_Exit;		
	}
	#elif defined(MSDC_MULTI_BLOCK_WRITE)
		status = MSDC_DMATransferFinal2();
		if(status != NO_ERROR)
			goto ERR_Exit;
		if((status = SD_WaitDatRdyOrTo_2())!=NO_ERROR)
			goto ERR_Exit;			
	#else // not MT6225
	{
		kal_uint32 j;
		
		for(j=0;j<num;j++)
		{
			if(msdc2_handle->mIsPresent  == KAL_FALSE)
			{
				status = ERR_CARD_NOT_PRESENT;
				goto ERR_Exit;		
			}
			if(j!=0)
			{
				MSDC_DMATransferFirst2((kal_uint32)ptr,count,KAL_TRUE);
			}
			status = MSDC_DMATransferFinal2();
			ptr += MSDC_SD_BLOCK_SIZE; 
			if(status != NO_ERROR)
				goto ERR_Exit;		
			if((status = SD_WaitDatRdyOrTo_2())!=NO_ERROR)	
				goto ERR_Exit;
		}
	
	}	
	#endif // MT6225

	DisableMSDC_DMA2();
	if((status = SD_StopTrans_2(KAL_TRUE))!=NO_ERROR)
		goto ERR_Exit;
	
	MSDC_CLR_INT2();
	
	return NO_ERROR;
ERR_Exit:
	{
		kal_uint32 tmp;
		
		DisableMSDC_DMA2();
		RESET_MSDC2();
		SD_StopTrans_2(KAL_TRUE);		
		SD_GetStatus_2(gSD2->mRCA,(kal_uint32*)&tmp);
		MSDC_LSD_ReadReg32(SDC_DATSTA2,&tmp);
		return status;
	}
	
}
/*************************************************************************
* FUNCTION
*	SD_SetBusWidth
*
* DESCRIPTION
*	ACMD6: set the data width 00 for 1 bit, 10 for 4 bits
*
* PARAMETERS
*	width: indicate the bus width
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	Not every card support 4-bits bus
*	only for SD
*
*************************************************************************/
SDC_CMD_STATUS SD_SetBusWidth_2(SD_BITWIDTH width)
{
	SDC_CMD_STATUS status;

	// check if card support 4 bits bus
	if((width == BIT_4W) && !(gSD2->mSCR.bus_width&0x04))
		return ERR_NOT_SUPPORT_4BITS;
	// send APP_CMD
	if((status = SD_Cmd55_2(gSD2->mRCA))!=NO_ERROR)
		return status;
	// send cmd6
	if((status = SD_Send_Cmd_2(SDC_CMD_ACMD6,width))!=NO_ERROR)
		return status;
	//read R1
	if((status = SD_CheckStatus_2())!=NO_ERROR)
		return status;	
	// set the controler MDLEN to enalbe 4bits bus width
	MSDC_LSD_SetBits32(SDC_CFG2,SDC_CFG_MDLEN);
	gSD2->bus_width = 4;
	
	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*	SD_ReadSCR
*
* DESCRIPTION
*	ACMD51: read the SD Configuration Register(8bytes block read)
*
* PARAMETERS
*	scr: used for store SCR
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	Make sure the size of SCR is 8 bytes 
*
*************************************************************************/
SDC_CMD_STATUS SD_ReadSCR_2(kal_uint32* scr)
{
	SDC_CMD_STATUS status;
	kal_uint32 blklen,i, t1;

	ASSERT((kal_uint32)scr % 4  == 0);
	// save the original block length 
	blklen = gSD2->mBKLength;
	// set block length(MSDC_CFG2)
	if((status = SD_SetBlength_2(8))!=NO_ERROR)
		return status;
	// send APP_CMD
	if((status = SD_Cmd55_2(gSD2->mRCA))!=NO_ERROR)
		return status;
	// send command
	if((status = SD_Send_Cmd_2(SDC_CMD_ACMD51,SDC_NO_ARG))!=NO_ERROR)
		return status;
	//read R1
	if((status = SD_CheckStatus_2())!=NO_ERROR)
		return status;	
	// read data(8bytes)	
#ifndef DRV_LSD
	// failed to use DMA with burst mode
	t1 = drv_get_current_time();
	MSDC_START_TIMER2(MSDC_TIMEOUT_PERIOD_DAT);
	for(i=0;i<2;)
	{	
		if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT*11)
			msdc2_handle->is_timeout = KAL_TRUE;		
		if(!msdc2_handle->mIsPresent)
			return ERR_CARD_NOT_PRESENT;
		if(msdc2_handle->is_timeout)
			return MSDC_GPT_TIMEOUT_ERR;
		if(!MSDC_IS_FIFO_EMPTY2)
		{
			*(kal_uint32*)(scr+i) = MSDC_Reg32(MSDC_DAT2);
			i++;
		}
	}
#else
	LSD_readFIFO(scr ,2);
	
#endif
	MSDC_STOP_TIMER2();
	// analysis scr
	SD_AnalysisSCR(scr);
	// clean EVENT_SDDATIRQ
	#ifdef MSDC_USE_INT	
	kal_set_eg_events(msdc2_handle->MSDC_Events, 0, KAL_AND);
	#endif
	MSDC_CLR_FIFO2();
	return NO_ERROR;
	
}

/*************************************************************************
* FUNCTION
*	SD_SetPreEraseBlk
*
* DESCRIPTION
*	ACMD23: set the number of write blocksto be pre-erased before writing
*	used for faster multiple Block Write
*
* PARAMETERS
*	num: used for storing number of blocks during multi-block operation
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_SetPreEraseBlk_2(kal_uint32 num)
{
	SDC_CMD_STATUS status;

	//[22:0] number of blocks 
	num &= 0x003FFF;
	// send APP_CMD
	if((status = SD_Cmd55_2(gSD2->mRCA))!=NO_ERROR)
		return status;
	// send CMD23
	if((status = SD_Send_Cmd_2(SDC_CMD_ACMD23,num))!=NO_ERROR)
		return status;
	//read R1
	if((status = SD_CheckStatus_2())!=NO_ERROR)
		return status;	

	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*	SD_EraseCmdClass
*
* DESCRIPTION
*	groups of erase commands including CMD32 ~CMD38
*
* PARAMETERS
*	cmd: indicate which command to execute
*	address: starting address wiht write protection
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	CMD34~CMD37 are only for MMC
*
*************************************************************************/
SDC_CMD_STATUS SD_EraseCmdClass_2(kal_uint32 cmd ,kal_uint32 address)
{
	SDC_CMD_STATUS status;

	if(cmd != SDC_CMD_CMD38)
	{
		if((status = SD_Send_Cmd_2(cmd,address))!=NO_ERROR)
			return status;
	}
	else if((status = SD_Send_Cmd_2(cmd,SDC_NO_ARG))!=NO_ERROR)
			return status;

	//read R1
	if((status = SD_CheckStatus_2())!=NO_ERROR)
		return status;

	if(cmd == SDC_CMD_CMD38)
	{
		SD_WaitCardNotBusy_2();
		do{	
		SD_GetStatus_2(gSD2->mRCA,(kal_uint32*)&status);
		if(msdc2_handle->mIsPresent == KAL_FALSE)
			break;
			}while(CurState(status)!=  TRAN_STA);
	}
	
	return NO_ERROR;
}
/*************************************************************************
* FUNCTION
*	SD_Switch_MMC40
*
* DESCRIPTION
*	CMD6: set the command set or write to the EXT_CSD (for MMC4.0)
*
* PARAMETERS
*	access: access mode
*	index: index to EXT_CSD
*  value: value to write to EXT_CSD
*	set:	selected command set 
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_Switch_MMC40_2(kal_uint8 access, kal_uint8 index, kal_uint8 value, kal_uint8 set)
{
	SDC_CMD_STATUS status;
	kal_uint32 arg = 0;
	
	arg = (access<<24)|(index<<16)|(value<<8)|set;
	// send command
	if((status = SD_Send_Cmd_2(SDC_CMD_CMD6_MMC40,arg))!=NO_ERROR)
		return status;
	//read R1
	if((status = SD_CheckStatus_2())!=NO_ERROR)
		return status;

	return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*	SD_SendEXTCSD_MMC40
*
* DESCRIPTION
*	CMD8: read the content of EXT_CSD register
*
* PARAMETERS
*	kal: access mode
*	index: index to EXT_CSD
*  value: value to write to EXT_CSD
*	set:	selected command set 
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_SendEXTCSD_MMC40_2(kal_uint32* rxbuffer)
{
	SDC_CMD_STATUS status;
	kal_bool retry_4bit = KAL_FALSE;

start:
	// read the block	of 512 bytes (make sure the rxbuffer is 4 byte aligned)
	EnableMSDC_DMA2();
	MSDC_DMATransferFirst2((kal_uint32)rxbuffer,128,KAL_FALSE);		
#ifdef DRV_LSD
	LSD_HostSetBuffer((kal_uint8 *)rxbuffer);
#endif
	if((status = SD_Send_Cmd_2(SDC_CMD_CMD8_MMC40,SDC_NO_ARG))!=NO_ERROR)
		goto ERR_Exit;
	//read R1
	if((status = SD_CheckStatus_2())!=NO_ERROR)
		goto ERR_Exit;		
	// read the block	of 512 bytes (make sure the rxbuffer is 4 byte aligned)
	status = MSDC_DMATransferFinal2();	
	if(status != NO_ERROR)
		goto ERR_Exit;			
	if((status = SD_WaitDatRdyOrTo_2())!=NO_ERROR)
		goto ERR_Exit;
	
	DisableMSDC_DMA2();
	MSDC_CLR_FIFO2();	
	gSD2->mCSD.ext_csd = (T_EXT_CSD_MMC40 *)rxbuffer;
	return NO_ERROR;	
	
ERR_Exit:

	if(retry_4bit == KAL_FALSE)
	{
		retry_4bit = KAL_TRUE;
		MSDC_LSD_SetBits32(SDC_CFG2,SDC_CFG_MDLEN);
		gSD2->bus_width = 4;
		goto start;
	}
	MSDC_LSD_ClearBits32(SDC_CFG2,SDC_CFG_MDLEN);
	gSD2->bus_width = 1;
	DisableMSDC_DMA2();
	MSDC_CLR_FIFO2();	
	RESET_MSDC2();

	return status;
}

/*************************************************************************
* FUNCTION
*	SD_Switch_SD11
*
* DESCRIPTION
*	CMD6: switch command to query and select the specific functions. (SD1.1 or later)
* PARAMETERS
*	arg: argument
*	resp: buffer to contain the ther 64 bytes status information
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_Switch_SD11_2(kal_uint32 arg, T_SWITCH_STATUS* info)
{
	SDC_CMD_STATUS status = NO_ERROR;
	
	BitFieldWrite32((kal_uint32*)SDC_CFG2,SD_CMD6_RESP_LEN,SDC_CFG_BLKLEN);	
	EnableMSDC_DMA2();
	MSDC_DMATransferFirst2((kal_uint32)info,(SD_CMD6_RESP_LEN>>2),KAL_FALSE);	
	if((status = SD_Send_Cmd_2(SDC_CMD_CMD6_SD11,arg))!=NO_ERROR)
		goto exit;
	if((status = SD_CheckStatus_2())!=NO_ERROR)
		goto exit;
	status = MSDC_DMATransferFinal2();	
	
exit:	
	DisableMSDC_DMA2();	
	return status;
}

/*************************************************************************
* FUNCTION
*	SD_Switch_SD11
*
* DESCRIPTION
*	Enable the high speed interface to support up to 50M Hz clock 
*
* PARAMETERS
*	arg: argument
*	resp: buffer to contain the ther 64 bytes status information
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_SelectHighSpeed_SD11_2(void)
{
	SDC_CMD_STATUS status;
	T_SWITCH_STATUS *p = (T_SWITCH_STATUS*)MSDC_Sector2;
	
	if((status = SD_Switch_SD11(SD_CMD6_QUERY_HIGH_SPEED, p))!=NO_ERROR)
		return status;
	if(p->max_current == 0)
		return ERR_SD_HS_FAIL;
	if((p->group1_info & (1 << SD_FUNC_HIGH_SPEED)) && 
		(p->group1_result == SD_FUNC_HIGH_SPEED))
	{
		if((status = SD_Switch_SD11(SD_CMD6_SELECT_HIGH_SPEED, p))!=NO_ERROR)
				return status;
		if(p->max_current == 0)
			return ERR_SD_HS_FAIL;
		if(p->group1_result == SD_FUNC_HIGH_SPEED)
			gSD2->flags |= SD_FLAG_HS_SUPPORT;
	}	
	else
		return ERR_SD_HS_FAIL;


	return NO_ERROR;
}

kal_bool MSDC_ModuleTest_Report_2(void)
{
    return msdc2_handle->mIsInitialized;
}

#endif // defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)

#endif //DRV_MSDC_OFF
