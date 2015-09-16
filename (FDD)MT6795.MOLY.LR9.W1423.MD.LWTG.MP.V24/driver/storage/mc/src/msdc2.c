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
 *   msdc2.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   driver functons for MSDC controller
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/ 
#ifndef DRV_MSDC_OFF
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"  
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //MSBB change #include "app_ltlcom.h"       /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"
#include "stacklib.h"
#include "intrCtrl.h"
#include "reg_base.h"
#include "drvpdn.h"
#include "eint.h"
#include "drv_comm.h"
#include "msdc_reg_adap.h"
#include "fat_fs.h"
#include "dma_hw.h"
#include "dma_sw.h"
#include "drv_hisr.h"
#include "msdc_def.h"
#include "sd_def.h"
#if defined(__MSDC2_SD_MMC__)&&defined(__MSDC_SD_SDIO__)
#include "sdio_sw.h"
#endif
#if defined(__MSDC_MS__)
#include "ms_def.h"
#elif defined(__MSDC_MSPRO__)
#include "mspro_def.h"
#endif
#include "upll_ctrl.h"
//#include "gpio_hw.h"
//#include "gpio_sw.h"
//#include "sim_hw.h"
#ifdef __MULTI_BOOT__
#include "syscomp_config.h"
#include "multiboot_config.h"
#endif   /*__MULTI_BOOT__*/
//#include "sim_hw.h"

#if defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)


#ifdef __CLKG_DEFINE__
#ifdef DRVPDN_CON0
#error "__CLKG_DEFINE__ & DRVPDN_CON0 are all defined"
#else
#define DRVPDN_CON0		CG_CON0
#endif

#ifdef DRVPDN_CON1_SIM
#error "__CLKG_DEFINE__ & DRVPDN_CON1_SIM are all defined"
#else
#define DRVPDN_CON1_SIM	CG_CON1_SIM
#endif

#ifdef DRVPDN_CON0_MSDC2
#error "__CLKG_DEFINE__ & DRVPDN_CON0_MSDC2 are all defined"
#else
#define DRVPDN_CON0_MSDC2	CG_CON0_MSDC2
#endif

#ifdef DRVPDN_CON0_CLR
#error "__CLKG_DEFINE__ & DRVPDN_CON0_CLR are all defined"
#else
#define DRVPDN_CON0_CLR	CG_CLR0
#endif

#ifdef DRVPDN_CON0_SET
#error "__CLKG_DEFINE__ & DRVPDN_CON0_SET are all defined"
#else
#define DRVPDN_CON0_SET	CG_SET0
#endif
#endif




#pragma arm section zidata = "NONCACHEDZI",  rwdata = "NONCACHEDRW"
kal_uint32 MSDC_Sector2[128] = {0};
MSDC_HANDLE *msdc2_handle = &MSDC_Blk[SD_MSDC2];

#ifdef MSDC_CACHED_SUPPORT
kal_uint32	msdc_uncachedBuf2[MSDC_UNCACHED_BUF_SIZE/4];	
#endif
#pragma arm section zidata, rwdata

// function predeclaration
void MSDC_DMAInit2(void);
void MSDC_INT_Init2(void);
void MSDC_DMA_Callback2(void);
extern void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
extern boot_mode_type stack_query_boot_mode(void); 
extern kal_bool INT_USBBoot(void);
extern kal_uint32 MSDC_GetCustom(void);
/*************************************************************************
* FUNCTION
*  MSDC_SetClock
*
* DESCRIPTION
*
* PARAMETERS
*	clock: the desired operating clock rate in the unit of kHz
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void MSDC_SetClock2(kal_uint32 clock)
{
	kal_uint32 cfg;

	if(clock == 0)
		return;
	MSDC_LSD_ClearBits32(SDC_CFG2,SDC_CFG_SIEN);
	cfg = ((msdc2_handle->msdc_clock+clock-1)/clock);
	if(cfg <=2 )
	{		
		cfg = 0;
		msdc2_handle->op_clock = msdc2_handle->msdc_clock/2;
	}
	else
	{
		cfg = (cfg >> 2) + (cfg&3 != 0);	
		msdc2_handle->op_clock = msdc2_handle->msdc_clock/(4*cfg);
	}
	BitFieldWrite32((kal_uint32*)MSDC_CFG2,(kal_uint32)cfg,MSDC_CFG_SCLKF);
	MSDC_LSD_SetBits32(SDC_CFG2,SDC_CFG_SIEN);
	
}
/*************************************************************************
* FUNCTION
*  MSDC_Check_Card_Present2
*
* DESCRIPTION
*	c
*
* PARAMETERS
*	ON: turn on power saving or not
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
kal_bool MSDC_Check_Card_Present2(void)
{
#if !defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
	return msdc2_handle->mIsPresent;
#else
	return KAL_TRUE;
#endif
}
/*************************************************************************
* FUNCTION
*  MSDC_PDNControl
*
* DESCRIPTION
*	Enable power saving or not.
*
* PARAMETERS
*	ON: turn on power saving or not
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
void MSDC_PDNControl2(kal_bool ON)
{
	msdc2_handle->mIsPWDown = ON;
	if(ON)
	{	// OFF		
		MSDC_CLR_INT2();
		MSDC_CLR_INT2();
		#if defined(MSDC_USE_USB_CLK) && defined(__MSDC2_SD_MMC__)
		if(gSD_blk[SD_MSDC2].flags & SD_FLAG_USE_USB_CLK)
			UPLL_Disable(UPLL_OWNER_MSDC2);
		#endif
		DRVPDN_Enable(DRVPDN_CON0,DRVPDN_CON0_MSDC2,PDN_MSDC2);		
	}
	else
	{	// ON
		DRVPDN_Disable(DRVPDN_CON0,DRVPDN_CON0_MSDC2,PDN_MSDC2);
		#if defined(MSDC_USE_USB_CLK) && defined(__MSDC2_SD_MMC__)
		if(gSD_blk[SD_MSDC2].flags & SD_FLAG_USE_USB_CLK)
			UPLL_Enable(UPLL_OWNER_MSDC2);		
		#endif
	}
}
/*************************************************************************
* FUNCTION
*  MSDC_TimeOutHandler2
*
* DESCRIPTION
*	Callback function of gpt timer, and launched while MSDC busy for a while

*
* PARAMETERS
*	
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
void MSDC_TimeOutHandler2(void *parameter)
{
	tst_sys_trace("MSDC_TimeOutHandler2");
	msdc2_handle->is_timeout = KAL_TRUE;
	#if defined(__MSDC_MS__)||defined(__MSDC_MSPRO__)
	kal_set_eg_events(msdc2_handle->MSDC_Events,
				(EVENT_MSIFIRQ|EVENT_DMAIRQ|EVENT_MSRDYIRQ),
				KAL_OR);	
	#else
	kal_set_eg_events(msdc2_handle->MSDC_Events,
				(EVENT_SDCMDIRQ|EVENT_SDDATIRQ|EVENT_SDMCIRQ|EVENT_SDR1BIRQ|EVENT_DMAIRQ),
				KAL_OR);	
	#endif	
}


/*************************************************************************
* FUNCTION
*  MSDC_GetCardStatus
*
* DESCRIPTION
*	Check currently card is present or not.
*
* PARAMETERS
*	
*
* RETURNS
*
* GLOBALS AFFECTED
*	msdc_eint_state
*
*
*************************************************************************/
int MSDC_GetCardStatus2(void * DriveData, int AckType)
{
	MSDC_HANDLE *msdc = (MSDC_HANDLE *)DriveData;;

	// a debounce mechanism 
    if(kal_query_systemInit() == KAL_FALSE)
    {
        kal_sleep_task(100);        
    }    
	ENTER_CRITICAL();
	msdc->send_ilm = KAL_TRUE;
	EXIT_CRITICAL();
	
	
	if(!msdc->mIsPresent)
		MSDC_PDNControl2(KAL_TRUE);
	return 0;
}


/*************************************************************************
* FUNCTION
*  MSDC_Config_INS_WP
*
* DESCRIPTION
* 	Configure the pull up or pull down status for INS and WP pin
*
* PARAMETERS
*	1. ins: MSDC_IOCTRL_PULL_DOWN, MSDC_IOCTRL_PULL_UP
*	2. wp: MSDC_IOCTRL_PULL_DOWN, MSDC_IOCTRL_PULL_UP
*
* RETURNS
*
* GLOBALS AFFECTED
*
* NOTE
*	1. MT6219 can not be configured to PULL up or down. They are all pulled up by IO.
*	2. MT6218B and MT6217, WP is configured with data lines.
*************************************************************************/
void MSDC_Config_INS_WP2(msdc_ioctrl_enum ins, msdc_ioctrl_enum wp)
{
	kal_uint32 msdc_cfg,iocon;
		
	msdc2_handle->ins_level = ins;
	//#if defined(MT6218B) || defined(MT6217)
	// INS use PRCFG3, WP use PRCFG0
	MSDC_SetData32(MSDC_CFG2,  MSDC_CFG_PRCFG0, (wp << 22));
	MSDC_SetData32(MSDC_IOCON2,  MSDC_IOCON_PRCFG3, (ins << 8));
}
/*************************************************************************
* FUNCTION
*  MSDC_Initialize
*
* DESCRIPTION
*	Initialize the MS/SD host controller, called only once at drv_init
*
* PARAMETERS*	
*
* RETURNS
*  1: initailized failed 
*  0: successful
*
* GLOBALS AFFECTED
*	gMSDC_Handle
*
*************************************************************************/
void MSDC_Initialize2(void)
{	

	// turn on the power of controler
	DRVPDN_Disable(DRVPDN_CON0,DRVPDN_CON0_MSDC2,PDN_MSDC2);
#if defined(__MSDC_MS__)
	MSDC_LSD_ClearBits32(MSDC_CFG2, MSDC_CFG_MSDC);
	msdc2_handle->mMSDC_type = MS_CARD;
#elif defined(__MSDC_MSPRO__)
	MSDC_LSD_ClearBits32(MSDC_CFG2, MSDC_CFG_MSDC);
	msdc2_handle->mMSDC_type = MSPRO_CARD;	
	FS_MspDrvAll = FS_MspDrv;
#elif (defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__))
	MSDC_LSD_SetBits32(MSDC_CFG2, MSDC_CFG_MSDC)	;
	msdc2_handle->mMSDC_type = SD_CARD;
#endif		
	msdc2_handle->msdc_clock = MSDC_CLOCK;

	if(msdc2_handle->gpt_handle == 0)
		MSDC_GPTI_GetHandle(&msdc2_handle->gpt_handle);
	#if !defined(__MSDC_TFLASH_DAT3_1BIT_HOT_PLUG__)
	MSDC_Config_INS_WP2(MSDC_IOCTRL_PULL_UP,MSDC_IOCTRL_PULL_UP);
	#else
	MSDC_Config_INS_WP2(MSDC_IOCTRL_PULL_DOWN,MSDC_IOCTRL_PULL_UP);
	// first time if card is present, no card insertion interrupt generated
	msdc2_handle->mIsPresent = KAL_TRUE; 
	#endif
	// turn on the power of memory card
	MSDC_LSD_SetBits32(MSDC_CFG2,MSDC_CFG_VDDPD);
	MSDC_SET_FIFO2(1);
	
	if(MSDC_GetCustom() & MSDC2_HOT_PLUG)
	{
		// enable card detection
		MSDC_WriteReg32(MSDC_PS2, MSDC_PS_CDEN|MSDC_PS_PIEN0|MSDC_PS_POEN0);
		if(MSDC_Reg(MSDC_PS2) & MSDC_PS_PIN0)
		{
			if(msdc2_handle->ins_level == MSDC_IOCTRL_PULL_UP)
				msdc2_handle->mIsPresent = KAL_FALSE;	
			else
				msdc2_handle->mIsPresent = KAL_TRUE;	
		}
		else
		{
			if(msdc2_handle->ins_level == MSDC_IOCTRL_PULL_UP)
				msdc2_handle->mIsPresent = KAL_TRUE;
			else
				msdc2_handle->mIsPresent = KAL_FALSE;	
		}
		MSDC_LSD_SetBits32(MSDC_CFG2, MSDC_CFG_PINEN);
	}
	else
	{
		msdc2_handle->mIsPresent = KAL_TRUE;
	}
					
	#ifdef MSDC_INT
	MSDC_INT_Init2();	
	#endif	// end of MSDC_INT
	#ifdef MSDC_DMA
	MSDC_DMAInit2();
	#endif	
	#ifdef __MULTI_BOOT__
	if(stack_query_boot_mode() != NORMAL_BOOT)
		msdc2_handle->send_ilm = KAL_FALSE;
	else
		msdc2_handle->send_ilm = KAL_TRUE;
	#else
		msdc2_handle->send_ilm = KAL_FALSE;
	#endif
		
	DRVPDN_Enable(DRVPDN_CON0,DRVPDN_CON0_MSDC2,PDN_MSDC2);	
}

void MSDC_SetIOCONRegDLT2(void)
{
	kal_uint32 factor;
	
	/*set DLT field according to SCLKF seeting*/
	factor = msdc2_handle->msdc_clock/msdc2_handle->op_clock;
	BitFieldWrite32((kal_uint32*)MSDC_IOCON2,(kal_uint32)(factor/2),MSDC_IOCON_DLT);
}

/*************************************************************************
* FUNCTION
*  MSDC_GetMediaChanged
*
* DESCRIPTION
*	Check if the media is changed, and clear the status after function call
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
/*! combined to MSDC_GetMediaChanged(), and removed in HAL [20101203 Samuel]
kal_bool MSDC_GetMediaChanged2(void* id)
{	
	kal_bool ret;

	ENTER_CRITICAL();
	msdc2_handle = (MSDC_HANDLE *)id;		
	ret = (msdc2_handle->mIsChanged )?(KAL_TRUE):(KAL_FALSE);
	msdc2_handle->mIsChanged = KAL_FALSE;	
	EXIT_CRITICAL();
		
	return ret; 
}
*/

#ifdef MSDC_DMA 
extern kal_uint8 DMA_GetChannel(DMA_Master DMA_CODE);
/*************************************************************************
* FUNCTION
*  MSDC_DMAInit
*
* DESCRIPTION
*	Initialize MSDC's DMA
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/
void MSDC_DMAInit2(void)
{	
	msdc2_handle->msdc_dmaport = DMA_GetChannel(DMA_MSDC2);
	msdc2_handle->msdc_menu.TMOD.burst_mode = KAL_TRUE;
	msdc2_handle->msdc_menu.TMOD.cycle = 0x4;
	msdc2_handle->msdc_menu.master = DMA_MSDC2;
	msdc2_handle->msdc_menu.addr = NULL;
	msdc2_handle->msdc_input.type = DMA_HWRX;
	msdc2_handle->msdc_input.size = DMA_LONG;
	msdc2_handle->msdc_input.count = 0;
	msdc2_handle->msdc_input.menu = &msdc2_handle->msdc_menu;
}

/*************************************************************************
* FUNCTION
*  MSDC_DMATransfer
*
* DESCRIPTION
*	MSDC using DAM for data transfer 
*
* PARAMETERS
*	adrs: data buffer
*	count: bytes to be transfered
*	isTx: ture for move data from MSDC to data buffer and vise versa
*
* RETURNS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/
void MSDC_DMATransferFirst2(kal_uint32 adrs,kal_uint32 count, kal_bool isTx)
{
	kal_uint32 total_count;
	kal_bool is_aligned, is_poll;

	DMA_Stop(msdc2_handle->msdc_dmaport);	

#ifdef MSDC_CACHED_SUPPORT
	if (KAL_TRUE == msdc2_handle->isCachedBuf){
		msdc2_handle->msdc_menu.addr = (kal_uint32)msdc_uncachedBuf2;
		msdc2_handle->cachedBufCopyPtr = adrs;
	}
	else
#endif	
	msdc2_handle->msdc_menu.addr = adrs;
	
	
	if(isTx)
	{
		msdc2_handle->timeout_period = (50 + (count>>5));
		msdc2_handle->msdc_input.type = DMA_HWTX;		
		if(count <= MSDC_WRITE_THD_POLL)
		{
			msdc2_handle->msdc_input.callback = NULL;
			is_poll = KAL_TRUE;			
		}
		else
		{
			msdc2_handle->msdc_input.callback = MSDC_DMA_Callback2;
			is_poll = KAL_FALSE;
		}
	}
	else
	{
	   msdc2_handle->timeout_period = (50 + (count>>7));
		msdc2_handle->msdc_input.type = DMA_HWRX;	
		if(count <= MSDC_READ_THD_POLL)
		{
			msdc2_handle->msdc_input.callback = NULL;
			is_poll = KAL_TRUE;
		}
		else
		{
			msdc2_handle->msdc_input.callback = MSDC_DMA_Callback2;
			is_poll = KAL_FALSE;
		}
	}

	if(kal_query_systemInit() == KAL_TRUE 
#ifdef  __TST_WRITE_TO_FILE_ONLY__	/*error recording: considering error recording additionally*/
		|| (KAL_TRUE == INT_QueryExceptionStatus())
#endif
	)
	{
		msdc2_handle->msdc_input.callback = NULL;
		is_poll = KAL_TRUE;
	}	

#ifndef MSDC_CACHED_SUPPORT
	if(adrs%4 == 0)
	{
		is_aligned = KAL_TRUE;
		total_count = count;
	}
	else
	{
		is_aligned = KAL_FALSE;
		total_count = count<<2;
	}
#else
	if(adrs%4 == 0 || KAL_TRUE == msdc2_handle->isCachedBuf)
	{
		is_aligned = KAL_TRUE;
		total_count = count;
	}
	else
	{
		is_aligned = KAL_FALSE;
		total_count = count<<2;
	}
#endif
	msdc2_handle->total_count = total_count;
	msdc2_handle->is_poll = is_poll;
	msdc2_handle->is_aligned = is_aligned;
	{
		if(is_aligned)
		{
			#if defined(USE_DMA_BURST)
			MSDC_SET_FIFO2(4);
			#else
			msdc2_handle->msdc_menu.TMOD.burst_mode = KAL_FALSE;
			#endif
#ifdef MSDC_CACHED_SUPPORT
			if(KAL_TRUE == msdc2_handle->isCachedBuf)
				msdc2_handle->msdc_input.count = (total_count > MSDC_UNCACHED_TRASNFER_SIZE)?(MSDC_UNCACHED_TRASNFER_SIZE):(total_count);
			else 
#endif			
			msdc2_handle->msdc_input.count = (total_count > 65024)?(65024):(total_count);
#ifdef MSDC_CACHED_SUPPORT
	if(KAL_TRUE == msdc2_handle->isCachedBuf){ 
		/*have do memory copy stuff here*/
		if(DMA_HWTX == msdc2_handle->msdc_input.type){
			/*copy from upper application buffer*/
			kal_mem_cpy(msdc_uncachedBuf2, (void *)msdc2_handle->cachedBufCopyPtr, 4 * msdc2_handle->msdc_input.count);
			msdc2_handle->cachedBufCopyPtr += msdc2_handle->msdc_input.count * 4;
		}
	}
#endif	
			msdc2_handle->msdc_input.size = DMA_LONG;		
			DMA_Config_B2W(msdc2_handle->msdc_dmaport,&msdc2_handle->msdc_input,KAL_TRUE,KAL_FALSE);
			msdc2_handle->msdc_menu.addr += msdc2_handle->msdc_input.count*4;
		}
		else
		{
#ifdef MSDC_CACHED_SUPPORT
			if(KAL_TRUE == msdc2_handle->isCachedBuf)
				ASSERT(0);
#endif		
			#if defined(USE_DMA_BURST)
			MSDC_SET_FIFO2(1);
			#else
			
			msdc2_handle->msdc_menu.TMOD.burst_mode = KAL_TRUE;
			#endif
			msdc2_handle->msdc_input.count = (total_count > 65024)?(65024):(total_count);
			msdc2_handle->msdc_input.size = DMA_BYTE;
			DMA_Config_B2W(msdc2_handle->msdc_dmaport,&msdc2_handle->msdc_input,KAL_TRUE,KAL_TRUE);
			msdc2_handle->msdc_menu.addr += msdc2_handle->msdc_input.count;
		}
		
	}
}
kal_uint32 MSDC_DMATransferFinal2(void)
{
	kal_uint32 total_count = msdc2_handle->total_count, t1;
	kal_bool is_poll = msdc2_handle->is_poll;
	kal_bool is_aligned = msdc2_handle->is_aligned;

	t1 = drv_get_current_time();
	if(msdc2_handle->timeout_period > MSDC_TIMEOUT_PERIOD_DAT)
		msdc2_handle->timeout_period = MSDC_TIMEOUT_PERIOD_DAT;
	MSDC_START_TIMER2(msdc2_handle->timeout_period);
	if(is_poll)
	{
		while(IS_MSDC_DMA_RUN(msdc2_handle->msdc_dmaport) && MSDC_Check_Card_Present2() && !msdc2_handle->is_timeout)
		{
			if(drv_get_duration_ms(t1) > MSDC_TIMEOUT_PERIOD_DAT*11)
				msdc2_handle->is_timeout = KAL_TRUE;
		}
	}
	else
	{
		kal_uint32 flags;
		kal_retrieve_eg_events(msdc2_handle->MSDC_Events,(EVENT_DMAIRQ),KAL_OR_CONSUME,&flags,KAL_SUSPEND);				
	}				
	MSDC_STOP_TIMER2();
	if(IS_MSDC_DMA_RUN(msdc2_handle->msdc_dmaport) && msdc2_handle->is_timeout)
		return MSDC_GPT_TIMEOUT_ERR;
	
	total_count -= msdc2_handle->msdc_input.count;
	if(total_count == 0){
#ifdef MSDC_CACHED_SUPPORT
	if(KAL_TRUE == msdc2_handle->isCachedBuf){
		if(DMA_HWRX == msdc2_handle->msdc_input.type){
			/*copy to upper application's buffer*/
			kal_mem_cpy((void *)msdc2_handle->cachedBufCopyPtr, msdc_uncachedBuf2, 4 * msdc2_handle->msdc_input.count);
		}
	}
#endif					
		return MSDC_NOERROR;
	}
	
#ifdef MSDC_CACHED_SUPPORT
	if(KAL_TRUE == msdc2_handle->isCachedBuf){
		/*have do memory copy stuff here*/
		if(DMA_HWTX == msdc2_handle->msdc_input.type){
			/*copy from upper application buffer*/
			kal_mem_cpy(msdc_uncachedBuf2, (void *)msdc2_handle->cachedBufCopyPtr, 4 * msdc2_handle->msdc_input.count);
		}
		else{
			/*copy to upper application's buffer*/
			kal_mem_cpy((void *)msdc2_handle->cachedBufCopyPtr, msdc_uncachedBuf2, 4 * msdc2_handle->msdc_input.count);
		}
		msdc2_handle->cachedBufCopyPtr += msdc2_handle->msdc_input.count * 4;
	}
#endif		
	while(1)
	{
		if(is_aligned)
		{
			#if defined(USE_DMA_BURST)
			MSDC_SET_FIFO(4);
			#else
			msdc2_handle->msdc_menu.TMOD.burst_mode = KAL_FALSE;
			#endif
#ifdef MSDC_CACHED_SUPPORT
			if(KAL_TRUE == msdc2_handle->isCachedBuf)
				msdc2_handle->msdc_input.count = (total_count > MSDC_UNCACHED_TRASNFER_SIZE)?(MSDC_UNCACHED_TRASNFER_SIZE):(total_count);
			else 
#endif						
			msdc2_handle->msdc_input.count = (total_count > 65024)?(65024):(total_count);
			msdc2_handle->msdc_input.size = DMA_LONG;		
			DMA_Config_B2W(msdc2_handle->msdc_dmaport,&msdc2_handle->msdc_input,KAL_TRUE,KAL_FALSE);
#ifdef MSDC_CACHED_SUPPORT
			/*we don't need to increase the addr when encounter cached buffer, since we only have a fix size uncached buffer to use*/
			if(KAL_FALSE == msdc2_handle->isCachedBuf)
#endif			
			{
				msdc2_handle->msdc_menu.addr += msdc2_handle->msdc_input.count*4;
			}
			msdc2_handle->timeout_period = 1 + (msdc2_handle->msdc_input.count>>7);
		}
		else
		{
#ifdef MSDC_CACHED_SUPPORT
			if(KAL_TRUE == msdc2_handle->isCachedBuf)
				ASSERT(0);
#endif			
			#if defined(USE_DMA_BURST)
			MSDC_SET_FIFO(1);
			#else
			msdc2_handle->msdc_menu.TMOD.burst_mode = KAL_TRUE;
			#endif
			msdc2_handle->msdc_input.count = (total_count > 65024)?(65024):(total_count);
			msdc2_handle->msdc_input.size = DMA_BYTE;
			DMA_Config_B2W(msdc2_handle->msdc_dmaport,&msdc2_handle->msdc_input,KAL_TRUE,KAL_TRUE);
			msdc2_handle->msdc_menu.addr += msdc2_handle->msdc_input.count;
			msdc2_handle->timeout_period = 1 + (msdc2_handle->msdc_input.count>>9);
		}
		
		// wait until running bit clr
		if(msdc2_handle->msdc_input.type == DMA_HWTX)
			msdc2_handle->timeout_period <<= 2 ;
		if(msdc2_handle->mMSDC_type == MMC_CARD)
			msdc2_handle->timeout_period <<= 1;
		
		t1 = drv_get_current_time();
		MSDC_START_TIMER2(msdc2_handle->timeout_period);
		if(is_poll)
		{
			while(IS_MSDC_DMA_RUN(msdc2_handle->msdc_dmaport) && MSDC_Check_Card_Present2() && !msdc2_handle->is_timeout)
			{
				if(drv_get_duration_ms(t1) > msdc2_handle->timeout_period*11)
					msdc2_handle->is_timeout = KAL_TRUE;				
			}
		}
		else
		{
			kal_uint32 flags;
			kal_retrieve_eg_events(msdc2_handle->MSDC_Events,(EVENT_DMAIRQ),KAL_OR_CONSUME,&flags,KAL_SUSPEND);				
		}				
		MSDC_STOP_TIMER2();
		if(IS_MSDC_DMA_RUN(msdc2_handle->msdc_dmaport) && msdc2_handle->is_timeout)
			return MSDC_GPT_TIMEOUT_ERR;
		total_count -= msdc2_handle->msdc_input.count;
		if(total_count == 0)
			break;		
#ifdef MSDC_CACHED_SUPPORT
	if(KAL_TRUE == msdc2_handle->isCachedBuf){ 
		/*have do memory copy stuff here*/
		if(DMA_HWTX == msdc2_handle->msdc_input.type){
			/*copy from upper application buffer*/
			kal_mem_cpy(msdc_uncachedBuf2, (void *)msdc2_handle->cachedBufCopyPtr, 4 * msdc2_handle->msdc_input.count);
		}
		else{
			/*copy to upper application's buffer*/
			kal_mem_cpy((void *)msdc2_handle->cachedBufCopyPtr, msdc_uncachedBuf2, 4 * msdc2_handle->msdc_input.count);
		}
		msdc2_handle->cachedBufCopyPtr += msdc2_handle->msdc_input.count * 4;
	}
#endif				
	}

#ifdef MSDC_CACHED_SUPPORT
	if(KAL_TRUE == msdc2_handle->isCachedBuf){
		if(DMA_HWRX == msdc2_handle->msdc_input.type){
			/*copy to upper application's buffer*/
			kal_mem_cpy((void *)msdc2_handle->cachedBufCopyPtr, msdc_uncachedBuf2, 4 * msdc2_handle->msdc_input.count);
		}
	}
#endif
	return MSDC_NOERROR;
}


#endif // DMA

#ifdef MSDC_INT
/*************************************************************************
* FUNCTION
*  MSDC_INT_Init
*
* DESCRIPTION
*	Initialize MSDC's interrupt
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/
void MSDC_INT_Init2(void)
{
	
   msdc2_handle->MSDC_Events = kal_create_event_group("MSDC2");
   DRV_Register_HISR(DRV_MSDC2_HISR_ID, MSDC_HISR_Entry2);
   IRQ_Register_LISR(IRQ_MSDC2_CODE, MSDC_LISR2,"MSDC_LISR2");
   IRQSensitivity(IRQ_MSDC2_CODE,LEVEL_SENSITIVE);
   IRQUnmask(IRQ_MSDC2_CODE);
   
	// enable MSDC interrupt
	MSDC_CLR_INT();	
	#if !defined(MSDC_USE_INT)
	MSDC_DISABLE_INT2();// (active)turn off other interrupt event except pin interrupt		
	#else
	MSDC_ENABLE_INT2();// (deactive)
	#endif
	
}
void MSDC_LISR2(void)
{
	IRQMask(IRQ_MSDC2_CODE);
	drv_active_hisr(DRV_MSDC2_HISR_ID);
} 
/*************************************************************************
* FUNCTION
*  MSDC_HISR_Entry
*
* DESCRIPTION
*	Set corresponding enevt and wake up waiting task.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/
void MSDC_HISR_Entry2(void)
{
	kal_uint16 msdc_int = 0;

#if defined(__MSDC_MS__)||defined(__MSDC_MSPRO__)
	kal_uint16 msc_sta;

	FS_MspDrvAll = FS_MspDrv;
	TurnOnMSDC2();
	msc_sta = MSDC_Reg(MSC_STA2);
	if(msc_sta & MSC_STA_SIF)
		kal_set_eg_events(msdc2_handle->MSDC_Events,EVENT_MSIFIRQ,KAL_OR);
	else
		kal_set_eg_events(msdc2_handle->MSDC_Events,EVENT_MSRDYIRQ,KAL_OR);

	msdc_int = MSDC_Reg(MSDC_INTR);
	if(msdc_int & MSDC_INT_PINIRQ)
	{
		msdc2_handle->mIsInitialized = KAL_FALSE;	
		msdc2_handle->mIsChanged = KAL_TRUE;		
		kal_set_eg_events(msdc2_handle->MSDC_Events,
			(EVENT_MSIFIRQ|EVENT_DMAIRQ|EVENT_MSRDYIRQ),
			KAL_OR);								
		if(MSDC_Reg(MSDC_PS2) & MSDC_PS_PIN0)
		{
			if(msdc2_handle->ins_level == MSDC_IOCTRL_PULL_UP)
				msdc2_handle->mIsPresent = KAL_FALSE;	
			else
				msdc2_handle->mIsPresent = KAL_TRUE;	
		}
		else
		{
			if(msdc2_handle->ins_level == MSDC_IOCTRL_PULL_UP)
				msdc2_handle->mIsPresent = KAL_TRUE;
			else
				msdc2_handle->mIsPresent = KAL_FALSE;	
		}
		if(msdc2_handle->mIsPresent == KAL_FALSE)
		{			
			MSDC_CLR_FIFO2();
			MSDC_CLR_INT2();
			MSDC_CLR_INT2();
			DMA_Stop(msdc2_handle->msdc_dmaport);		
		}
		#if !defined(FMT_NOT_PRESENT)
			MSDC_SendCardInd(MOD_FMT, SD_MSDC2);		
		#endif		
	}
#else // sd/mmc start here
	TurnOnMSDC2();		
	msdc_int = MSDC_Reg(MSDC_INTR2);
   #if defined(__MSDC2_SD_MMC__)&&defined(__MSDC_SD_SDIO__)
	/*SDIO*/
	if(msdc_int & MSDC_INT_SDIOIRQ)
	{	    
      SDIO_HISR_Entry();		   		 
	} 
	#endif 	

	if(msdc_int & MSDC_INT_PINIRQ)
	{
		msdc2_handle->mIsInitialized = KAL_FALSE;				
		msdc2_handle->mIsChanged = KAL_TRUE;				
		if(MSDC_Reg(MSDC_PS2) & MSDC_PS_PIN0)
		{
			if(msdc2_handle->ins_level == MSDC_IOCTRL_PULL_UP)
				msdc2_handle->mIsPresent = KAL_FALSE;	
			else
				msdc2_handle->mIsPresent = KAL_TRUE;	
		}
		else
		{
			if(msdc2_handle->ins_level == MSDC_IOCTRL_PULL_UP)
				msdc2_handle->mIsPresent = KAL_TRUE;
			else
				msdc2_handle->mIsPresent = KAL_FALSE;	
		}
		if(msdc2_handle->mIsPresent == KAL_FALSE)
		{
			MSDC_CLR_FIFO2();
			MSDC_CLR_INT2();
			MSDC_CLR_INT2();
			DMA_Stop(msdc2_handle->msdc_dmaport);		
		}	
		#if !defined(FMT_NOT_PRESENT)
			MSDC_SendCardInd(MOD_FMT, SD_MSDC2);		
		#endif
	}	
	#endif // MSDC_MS
	IRQUnmask(IRQ_MSDC2_CODE);				
}
/*************************************************************************
* FUNCTION
*  MSDC_DMA_Callback
*
* DESCRIPTION
*	Call back while DMA has done the data transfer.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/
void MSDC_DMA_Callback2(void)
{
	kal_set_eg_events(msdc2_handle->MSDC_Events,EVENT_DMAIRQ,KAL_OR);			
}

#endif //end of MSDC_INT
#endif // end of  (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__)) && defined(__MSDC2_SD_MMC__)

#endif //DRV_MSDC_OFF
