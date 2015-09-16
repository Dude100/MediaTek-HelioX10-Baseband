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
 *   sdio_drv.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   driver of for SDIO card
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
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/#include "drv_features.h"
#include "drv_features.h"
#ifndef DRV_MSDC_OFF
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "drv_comm.h"  
#include "reg_base.h"
#include "msdc_reg_adap.h"
//#include "app_buff_alloc.h"
#include "msdc_def.h"
#include "sd_def.h"
#include "sdio_def.h"
#include "intrCtrl.h"  
#include "sdio_sw.h"
#include "cache_sw.h"
#include "init.h"
#include "dma_hw.h"
#include "drv_trc.h"
#include "kal_debug.h"
/*RHR*/
#include "drvpdn.h"
/*RHR*/

#ifdef __CLKG_DEFINE__
#ifdef DRVPDN_CON1
#error "__CLKG_DEFINE__ & DRVPDN_CON1 are all defined"
#else
#define DRVPDN_CON1		CG_CON1
#endif

#ifdef DRVPDN_CON1_SIM
#error "__CLKG_DEFINE__ & DRVPDN_CON1_SIM are all defined"
#else
#define DRVPDN_CON1_SIM	CG_CON1_SIM
#endif

#ifdef DRVPDN_CON1_MSDC
#error "__CLKG_DEFINE__ & DRVPDN_CON1_MSDC are all defined"
#else
#define DRVPDN_CON1_MSDC	CG_CON1_MSDC
#endif

#ifdef DRVPDN_CON1_CLR
#error "__CLKG_DEFINE__ & DRVPDN_CON1_CLR are all defined"
#else
#define DRVPDN_CON1_CLR	CG_CLR1
#endif

#ifdef DRVPDN_CON1_SET
#error "__CLKG_DEFINE__ & DRVPDN_CON1_SET are all defined"
#else
#define DRVPDN_CON1_SET	CG_SET1
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

 
#if defined(__MSDC_SD_MMC__)&&defined(__MSDC_SD_SDIO__)

#if defined(DRV_MSDC_MT6225_SERIES)
#define DRV_MSDC_DATA_LATCH_TIMING
#endif 

#pragma arm section zidata = "NONCACHEDZI",  rwdata = "NONCACHEDRW"  // doublelo modify for DMA non-cached issue
 kal_uint32 sdio_uncachedU32;
 kal_uint32 mcudma_flag=128;// mcu:<128byte ; dma:>=128byte
 kal_uint32 forcemcu=0; // 1:forcemcu
#pragma arm section zidata, rwdata

#ifdef DCL_MSDC_INTERFACE
#include "dcl.h"
SDC_CMD_STATUS SDIO_Initialize(void);
void SDIO_get_CCCR(kal_uint8 *buf, kal_uint32 bufLen);
void SDIO_get_FBR(kal_uint8 *buf, kal_uint32 bufLen);

SDIODriver_t sdio_driver_MTK1 = {
	(DCL_SDIO_REG_WR)SDIO_Register_Write,
	(DCL_SDIO_REG_WR_ISR)SDIO_Register_Write_isr,
	(DCL_SDIO_DATA_WR)SDIO_Data_Write,
	(DCL_SDIO_REG_RD)SDIO_Register_Read,
	(DCL_SDIO_DATA_RD)SDIO_Data_Read,
	(DCL_SDIO_CHECK_INTR)SDIO_check_IO_Int,
	(DCL_SDIO_ENABLE_INTR)SDIO_enable_IO_Int,
	(DCL_SDIO_INIT)SDIO_Initialize,
	(DCL_SDIO_ABORT)SDIO_abort_IO,
	(DCL_SDIO_SW_RST)SDIO_SW_reset,
	(DCL_SDIO_QRY_BLOCK_SIZE)SDIO_query_BLK_size,
    (DCL_SDIO_SET_BLOCK_SIZE)SDIO_configure_BLK_size,
    (DCL_SDIO_GET_BLOCK_SIZE)SDIO_get_BLK_size,
	(DCL_SDIO_ENABLE_IO)SDIO_enable_IO,
	(DCL_SDIO_SET_BUS_WIDTH)SDIO_configure_bus,
	(DCL_SDIO_GET_CCCR)SDIO_get_CCCR,
	(DCL_SDIO_GET_FBR)SDIO_get_FBR,
    (DCL_SDIO_CMD52_READ )SDIO_cmd52_read,
    (DCL_SDIO_CMD52_WRITE)SDIO_cmd52_write,
    (DCL_SDIO_CMD52_WRITE_READ)SDIO_cmd52_write_read,
    (DCL_SDIO_CMD53_READ )SDIO_cmd53_read,
    (DCL_SDIO_CMD53_WRITE)SDIO_cmd53_write,
	(DCL_SDIO_int_registration)SDIO_int_registration,
    (DCL_SDIO_MCUDMA_READ)SDIO_mcudma_read,
    (DCL_SDIO_MCUDMA_WRITE)SDIO_mcudma_write,
        (DCL_SDIO_CLKPADRED_READ)SDIO_clkpadred_read,
        (DCL_SDIO_CLKPADRED_WRITE)SDIO_clkpadred_write,
        (DCL_SDIO_FORCEMCU_READ)SDIO_forcemcu_read,
        (DCL_SDIO_FORCEMCU_WRITE)SDIO_forcemcu_write,
        (DCL_SDIO_GETCLK)SDIO_getclk,
        (DCL_SDIO_SETCLK)SDIO_setclk
};
#endif
__align(4) kal_uint8 sdio_cccr_reg[SDIO_CCCR_SIZE];
__align(4) kal_uint8 sdio_fbr_reg[SDIO_FBR_SIZE];
__align(4) kal_uint8 sdio_tuple[SDIO_MAX_FUCN_ID][SDIO_TUPLE_SIZE];
sdio_dcb_struct gSDIO;
kal_mutexid sdio_mutex; 

void sdio_dummyFunction(void)
{
	/*this function is to make source insight more visible since the usage of "__align" is out of the capability of source insight's parser*/
}
DCL_SDC_CMD_STATUS SDIO_cmd52_write_read_func(rw_dir_enum rwcmd, kal_bool rawcmd, DCL_SDIO_function_id_enum function, DCL_UINT32 addr, DCL_UINT8 wdata, DCL_UINT8 *rdata, DCL_UINT8 *r5resp)
{
    SDC_CMD_STATUS status;
    cmd52_config_struct cmd52;
   
    SDIO_dispatch_IO(SDIO_FUCN_0);
    cmd52.rw = rwcmd;
    cmd52.func = function;
    cmd52.raw = rawcmd;
    cmd52.stop = KAL_FALSE;
    cmd52.adrs = addr;
    cmd52.data = wdata;
    status = SDIO_Cmd52(&cmd52);
    if(r5resp)
        *r5resp = gSDIO.resp;
    if(rdata)
        *rdata = cmd52.data;
    SDIO_resume_IO(SDIO_FUCN_0); 
    return status;
}
DCL_SDC_CMD_STATUS SDIO_cmd52_read(DCL_SDIO_function_id_enum function, DCL_UINT32 addr, DCL_UINT8 *rdata, DCL_UINT8 *r5resp)
{   
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    return SDIO_cmd52_write_read_func(SDIO_READ,KAL_FALSE,function,addr,0,rdata,r5resp);
#endif
}


DCL_SDC_CMD_STATUS SDIO_cmd52_write(DCL_SDIO_function_id_enum function, DCL_UINT32 addr, DCL_UINT8 wdata, DCL_UINT8 *r5resp)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    return SDIO_cmd52_write_read_func(SDIO_WRITE,KAL_FALSE,function,addr,wdata,0,r5resp);
#endif
}

DCL_SDC_CMD_STATUS SDIO_cmd52_write_read(DCL_SDIO_function_id_enum function, DCL_UINT32 addr, DCL_UINT8 wdata, DCL_UINT8 *rdata, DCL_UINT8 *r5resp)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    return SDIO_cmd52_write_read_func(SDIO_WRITE,KAL_TRUE,function,addr,wdata,rdata,r5resp);
#endif
}

DCL_SDC_CMD_STATUS SDIO_cmd53_read_write_func(rw_dir_enum rwcmd, DCL_SDIO_function_id_enum function, DCL_UINT32 addr, DCL_UINT32 data, DCL_SDIO_cmd53_op_enum op, DCL_UINT32 count, DCL_BOOL block, DCL_UINT8 *r5resp)
{
    SDC_CMD_STATUS status;
    cmd53_config_struct cmd53;

    SDIO_dispatch_IO(function);
    cmd53.rw = rwcmd;
    cmd53.func = function;
    cmd53.block = block;
    cmd53.buffer = data;
    cmd53.count = count;
    cmd53.op = op;
    cmd53.adrs = (kal_uint32)addr;
    status = SDIO_Cmd53(&cmd53);
    if(r5resp)
        *r5resp = gSDIO.resp;
    SDIO_resume_IO(function);
    return status;            
}


DCL_SDC_CMD_STATUS SDIO_cmd53_read(DCL_SDIO_function_id_enum function, DCL_UINT32 addr, DCL_UINT32 data, DCL_SDIO_cmd53_op_enum op, DCL_UINT32 count, DCL_BOOL block, DCL_UINT8 *r5resp)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    return SDIO_cmd53_read_write_func(SDIO_READ, function, addr, data, op, count, block, r5resp);
#endif
}


DCL_SDC_CMD_STATUS SDIO_cmd53_write(DCL_SDIO_function_id_enum function, DCL_UINT32 addr, DCL_UINT32 data, DCL_SDIO_cmd53_op_enum op, DCL_UINT32 count, DCL_BOOL block, DCL_UINT8 *r5resp)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    return SDIO_cmd53_read_write_func(SDIO_WRITE, function, addr, data, op, count, block, r5resp);
#endif
}

DCL_SDC_CMD_STATUS SDIO_mcudma_read(DCL_UINT32 *rdata)
{   
    SDIO_dispatch_IO(SDIO_FUCN_0);
    *rdata = mcudma_flag;
    SDIO_resume_IO(SDIO_FUCN_0);
    return NO_ERROR;
}

DCL_SDC_CMD_STATUS SDIO_mcudma_write(DCL_UINT32 wdata)
{
    SDC_CMD_STATUS status=NO_ERROR;
   
    SDIO_dispatch_IO(SDIO_FUCN_0);
    mcudma_flag = wdata;
    SDIO_resume_IO(SDIO_FUCN_0); 
    return status;
}


DCL_SDC_CMD_STATUS SDIO_clkpadred_read(DCL_UINT32 *rdata)
{   
    SDIO_dispatch_IO(SDIO_FUCN_0);
    *rdata = 1&(MSDC_Reg32(MSDC_CLKACB_CFG)>>7);
    SDIO_resume_IO(SDIO_FUCN_0);
    return NO_ERROR;
}

DCL_SDC_CMD_STATUS SDIO_clkpadred_write(DCL_UINT32 wdata)
{
    SDC_CMD_STATUS status=NO_ERROR;
   
    SDIO_dispatch_IO(SDIO_FUCN_0);
    if(wdata & 1)
    {
        MSDC_SetBits32(MSDC_CLKACB_CFG, MSDC_CLKACB_CFG_CLKPAD_RED);
    }
    else
    {
        MSDC_ClearBits32(MSDC_CLKACB_CFG, MSDC_CLKACB_CFG_CLKPAD_RED);
    }
    SDIO_resume_IO(SDIO_FUCN_0); 
    return status;
}

DCL_SDC_CMD_STATUS SDIO_forcemcu_read(DCL_UINT32 *rdata)
{   
    SDIO_dispatch_IO(SDIO_FUCN_0);
    *rdata = forcemcu;
    SDIO_resume_IO(SDIO_FUCN_0);
    return NO_ERROR;
}

DCL_SDC_CMD_STATUS SDIO_forcemcu_write(DCL_UINT32 wdata)
{
    SDC_CMD_STATUS status=NO_ERROR;
   
    SDIO_dispatch_IO(SDIO_FUCN_0);
    forcemcu = wdata;
    SDIO_resume_IO(SDIO_FUCN_0); 
    return status;
}

DCL_SDC_CMD_STATUS SDIO_getclk(DCL_UINT32 *rdata)
{   
    SDIO_dispatch_IO(SDIO_FUCN_0);
    *rdata = gMSDC_Handle->op_clock ;
    SDIO_resume_IO(SDIO_FUCN_0);
    return NO_ERROR;
}

DCL_SDC_CMD_STATUS SDIO_setclk(DCL_UINT32 wdata)//KHZ
{
	msdc_clk_setting cs,cs2;
	DCL_UINT32 temp1,temp2;
	SDC_CMD_STATUS status=ERR_ERRORS;

    SDIO_dispatch_IO(SDIO_FUCN_0);
    temp1=0;temp2=0x0fffffff;
    cs2.cardClk = 0;
	for (cs.sclkf = 0; cs.sclkf < MSDC_SCLKF_NUM; cs.sclkf ++)
	{
		for (cs.clksrc = 0; cs.clksrc < MSDC_CLKSRC_NUM; cs.clksrc ++)
		{
			cs.cardClk = gMsdcClksrcRate[cs.clksrc] / DIV_SCLKF(cs.sclkf);
			if(wdata >= cs.cardClk)
			{
    			temp1 = wdata - cs.cardClk;
    			if (temp1 <= temp2)
    			{
                    temp2 = temp1;
                    cs2.cardClk = cs.cardClk;
                    cs2.clksrc = cs.clksrc;
                    cs2.sclkf = cs.sclkf;
                    if(temp1 == 0)
                        goto SDIO_setclk_return;
    			}
			}
		}
	}

SDIO_setclk_return:
    if(cs2.cardClk)
    {
        MSDC_LSD_ClearBits32(SDC_CFG,SDC_CFG_SIEN);
    	BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)cs2.sclkf,MSDC_CFG_SCLKF);
    	BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)cs2.clksrc,MSDC_CFG_CLKSRC);
    	MSDC_LSD_SetBits32(SDC_CFG,SDC_CFG_SIEN);
    	gMSDC_Handle->op_clock = cs2.cardClk;
    	status = NO_ERROR;
    }
    SDIO_resume_IO(SDIO_FUCN_0);
    return status;
}


#ifdef __MSDC_CD_EINT__
void SDIO_EINT_Registration()
{
    cardDetectionEINTPolarity = KAL_TRUE; // default pull high
    MSDC_debounceTime = 30;

    EINT_Mask(MSDC_EINT_NO);
    EINT_Registration(MSDC_EINT_NO, KAL_TRUE, cardDetectionEINTPolarity, SDIO_HISR_Entry, KAL_TRUE); //PMU_CHR_EINT_PIN=8
    EINT_SW_Debounce_Modify(MSDC_EINT_NO, MSDC_debounceTime);    // 32768Hz
    EINT_UnMask(MSDC_EINT_NO);

}
#endif
/*************************************************************************
* FUNCTION
*  SDIO_Initialize
*
* DESCRIPTION
*	SDIO Intialization function
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
extern kal_uint8 MSDC_GetIOCtrlParam(void);
SDC_CMD_STATUS SDIO_Initialize(void)
{	
	kal_uint16 rca;
   #if !defined(DRV_MSDC_DATA_LATCH_TIMING)
	kal_uint16 iocon;
   #else
	kal_uint32 iocon;
   #endif
	SDC_CMD_STATUS status;
	kal_uint32 flags;	
	kal_uint32 retry_count = 0;
	kal_uint32 count=0;	   
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    MSDC_PDNControl(KAL_FALSE);//guilin
	TurnOnMSDC();	
	#ifdef MSDC_INT
	kal_retrieve_eg_events(gMSDC_Handle->MSDC_Events,
			(EVENT_SDCMDIRQ|EVENT_SDDATIRQ|EVENT_SDMCIRQ|EVENT_SDR1BIRQ|EVENT_DMAIRQ|EVENT_PINIRQ),
			KAL_OR_CONSUME,&flags,KAL_NO_SUSPEND);
	#else
	/*check if the card is present*/
	if(MSDC_Reg(MSDC_PS) & MSDC_PS_PIN0)
	{  /*card not present (1)*/
		gMSDC_Handle->mIsPresent = KAL_FALSE;
	}
	else
	{  /*card present (0)*/
		gMSDC_Handle->mIsPresent = KAL_TRUE;
	}
	#endif
#ifdef __MSDC_NOT_SUPPORT_HOT_PLUG__
    gMSDC_Handle->mIsPresent = KAL_TRUE;
#endif
   /*create mutex*/
   sdio_mutex = kal_create_mutex("MutexSDIO");

	/* reset msdc*/
	RESET_MSDC();//MSDC_SetBits32(MSDC_CFG, MSDC_CFG_RST);

   /*Driving current*/
	//MSDC_WriteReg32(MSDC_IOCON,0xC3);
	//MSDC_WriteReg32(MSDC_IOCON,0xdb);

   /* set the output driving capability from customization interface*/
   #if !defined(DRV_MSDC_DATA_LATCH_TIMING)
	MSDC_SetData(MSDC_IOCON, 0xff, MSDC_GetIOCtrlParam());
   #else /* !defined(DRV_MSDC_DATA_LATCH_TIMING) */

	iocon = 0;
	iocon |= MSDC_GetIOCtrlParam();
	 #ifdef MCU_208M
	    iocon |= 0x08000000;
   #elif defined(MCU_78M)
      iocon |= 0x04000000;
   #elif defined(MCU_52M)
      iocon |= 0x02000000;
   #endif

	MSDC_SetData32(MSDC_IOCON, 0xff0000ff, iocon);
   
   #if defined(MCU_52M)
   	BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)1, MSDC_CFG_CRED);
   #endif
   #endif /* !defined(DRV_MSDC_DATA_LATCH_TIMING) */
#if !defined(DRV_MSDC_REG_V3) // guilin
	/*set pull up in CMD/DAT line configuration*/	
	BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)2,MSDC_CFG_PRCFG1);
	BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)2,MSDC_CFG_PRCFG2);
#endif // guilin
	/*set write timeout=(40+1)*65536*(1/serial clock)*/
	BitFieldWrite32((kal_uint32*)SDC_CFG,(kal_uint32)255,SDC_CFG_DTOC);	
	/*set write timeout=(40+1)*65536*(1/serial clock)*/
	BitFieldWrite32((kal_uint32*)SDC_CFG,(kal_uint32)15,SDC_CFG_WDOD);		

 	/* disable 4-bit*/
	MSDC_ClearBits32(SDC_CFG,SDC_CFG_MDLEN);	   		
	/* enable serila clock 104/8=13MHz*/	
	//BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)FREQ_1BY8,MSDC_CFG_SCLKF);			
	/* enable serila clock 104/255*4=100KHz*/	
	//MSDC_Reg32(MSDC_CFG)|= 0x8; 
	MSDC_ClearBits32(SDC_CFG,SDC_CFG_SIEN);
	#ifdef MCU_208M
		BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)32,MSDC_CFG_SCLKF);	
	#else
	BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)32,MSDC_CFG_SCLKF);		
	#endif

	gMSDC_Handle->msdc_clock = MSDC_CLOCK;
	MSDC_SetClock(MSDC_INI_CLOCK);
#if !defined(DRV_MSDC_LATCH_MT6276_SERIES)
	MSDC_SetIOCONRegDLT();
#endif	
	MSDC_SetBits32(SDC_CFG,SDC_CFG_SIEN);
	/* config the sdio controller*/
	/* enable SDIO mode*/
	MSDC_SetBits32(SDC_CFG, SDC_CFG_SDIO);
	/* enable 74 SD clk by s/w */
	 MSDC_SetBits32(MSDC_CFG, 0x80);
	/* enable SDIO interrupt*/
	MSDC_WriteReg32(SDIO_CFG, 1); 		
	{
		kal_uint32 i;
		for(i=0;i<100000;i++);
	}	
	
	/* stop SD clk by s/w */
	 MSDC_ClearBits32(MSDC_CFG, 0x80);

	/*SDIO initialization CMD*/
   status = SDIO_Cmd5(0);
	SDIO_STATUS_CHECK;
   #ifdef _SDIO_DEBUG_
	dbg_print("write CMD5(0) %d\r\n", status);						
	dbg_print("card OCR %d\r\n", gSDIO.ocr);						
	#endif
	do 
	{	
	   retry_count++;
	   if(gSDIO.ocr & 0x8000)
	   {					      
	   	if((status = SDIO_Cmd5(0x8000))!=NO_ERROR)	   	
	   	{
	   	   #ifdef _SDIO_DEBUG_
	   		dbg_print("card deny OCR \r\n");													   	
	   		#endif
	   		
	   	}	
	   	else	   				
	   	{
	   	   #ifdef _SDIO_DEBUG_
	   		dbg_print("card accept OCR \r\n");							   		
	   	#endif	
	   	}	
	   	
	   	gSDIO.ocr_valid = KAL_TRUE;	
	   }
	   else 
	   {	   
	      #ifdef _SDIO_DEBUG_
	      dbg_print("card not match OCR \r\n");												  
	      dbg_print("uses card's OCR \r\n");												  
	      #endif												  
	      if((status = SDIO_Cmd5(gSDIO.ocr))!=NO_ERROR)	   	
	      {
	         #ifdef _SDIO_DEBUG_
	   		dbg_print("card deny OCR \r\n");													   			   			   	
	   		#endif	
	   	}	
	   	else	   	
	   	{
	   	   #ifdef _SDIO_DEBUG_
	   		dbg_print("card accept OCR \r\n");							   	
	   		#endif	
	   	}	
	   	
	   	gSDIO.ocr_valid = KAL_TRUE;	
	   }
	   if(retry_count>=100)
	      goto err;
	}while(gSDIO.io_ready!=KAL_TRUE);	
	MSDC_ClearBits32(SDC_CFG,SDC_CFG_SIEN);			
	#ifdef MCU_208M
	 BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)4,MSDC_CFG_SCLKF);		  
	#elif defined(MCU_78M)   
   BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)FREQ_1BY8,MSDC_CFG_SCLKF);		   	
   #else
   BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)FREQ_1BY4,MSDC_CFG_SCLKF);		   	
   #endif   /*MCU_208M*/

   BitFieldWrite32((kal_uint32*)MSDC_CFG,1,MSDC_CFG_CLKSRC);		   	
   BitFieldWrite32((kal_uint32*)MSDC_CFG,1,MSDC_CFG_SCLKF);		   	
	SD_Use24M_Clock();
	//SD_Use45M_Clock();
#if !defined(DRV_MSDC_LATCH_MT6276_SERIES)
	MSDC_SetIOCONRegDLT();
#endif				
				
	MSDC_SetBits32(SDC_CFG,SDC_CFG_SIEN);   
	status = SD_ValidateRCA(&rca);
	SDIO_STATUS_CHECK;
	#ifdef _SDIO_DEBUG_
	dbg_print("CMD7 select card \r\n");								
	dbg_print("CMD3 request RCA \r\n");
	#endif
	
	status = SD_SelectCard(rca);
	SDIO_STATUS_CHECK;
	
	/* get parameters*/
	/*read CCCR, FBR, CIS tuple*/	
	status=SDIO_read_CCCR();
	SDIO_STATUS_CHECK;
   status=SDIO_read_capacity();   
   SDIO_STATUS_CHECK;
   status=SDIO_read_power_control();
   SDIO_STATUS_CHECK;
	
	#if 1/*support 4-bits*/
	/*enable multiple block interrupt */
	if(!(SDIO_support_LSC()))	
	{	
#ifndef DRV_MSDC_USING_2ND
	   if(SDIO_support_S4MI()){
	      status=SDIO_enable_E4MI(KAL_TRUE);   
	   	SDIO_STATUS_CHECK;
	   }

       if(gMSDC_Handle->trySingleLine == KAL_FALSE) //guilin
    	   status=SDIO_configure_bus(BIT_4W);	   
	   else
           status=SDIO_configure_bus(BIT_1W);      
	   SDIO_STATUS_CHECK;

	   /* enable serila clock 104/8=13MHz*/	
	   //BitFieldWrite32((kal_uint32*)MSDC_CFG,(kal_uint32)FREQ_1BY8,MSDC_CFG_SCLKF);    	   
#else
		 //MSDC2 only support 1-bit Mode
		 status=SDIO_configure_bus(BIT_1W);
		SDIO_STATUS_CHECK;
#endif	      
	}
	else/*low speed card*/
	{
#ifndef DRV_MSDC_USING_2ND		
	   if(SDIO_support_4BLS()){
	      status=SDIO_configure_bus(BIT_4W);	      
	      SDIO_STATUS_CHECK;
	   }
#else
		//MSDC2 only support 1-bit Mode
#endif	      
	}    
	#else
/* under construction !*/
	#endif  
	status=SDIO_read_CIS(SDIO_FUCN_0);
	SDIO_STATUS_CHECK;
   /*enable I/O function*/
	for(count=SDIO_FUCN_1;count<SDIO_MAX_FUCN_ID;count++)
	{	   
	   kal_uint32 retry=0;
	   kal_bool ready;
	   for(retry=0;retry<100;retry++) 
	   {
	      status=SDIO_enable_IO(count, KAL_TRUE);
	      SDIO_STATUS_CHECK;
	      status = SDIO_check_IO_ready(count, &ready);
	      SDIO_STATUS_CHECK;
	      if(ready==KAL_TRUE)
	         break;
	   }   	   
	   status=SDIO_read_FBR(count);	 
	   SDIO_STATUS_CHECK;
	   for(retry=0;retry<100;retry++)   	   
	   {
	      status=SDIO_read_CIS(count);	   
	      if(status==NO_ERROR)
	         break;
	   }   
	   
	}      
	if(SDIO_support_MPS()){
	   status=SDIO_enable_MPS(KAL_TRUE);
	   SDIO_STATUS_CHECK;
	}
	   
	status=SDIO_read_CCCR();   
	SDIO_STATUS_CHECK;
	/* for Sandisk SDIO WIFI card*/   
#if 0//guilin test #ifdef __MSDC_BASIC_LOAD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	

err:
	if(status != NO_ERROR)
	{
		tst_sys_trace("sdio_initialize error \r\n");
		kal_prompt_trace(MOD_MSDC_HISR,"sdio_initialize error");
		kal_mem_set(gSD,0,sizeof(gSD));
		gMSDC_Handle->mIsInitialized = KAL_FALSE;
	}
	else
	{
		tst_sys_trace("sdio_initialize ok \r\n");
		kal_prompt_trace(MOD_MSDC_HISR,"sdio_initialize ok");
		gMSDC_Handle->mIsInitialized = KAL_TRUE;
   
	return status;
}

/*SDIO commnad set*/
/*************************************************************************
* FUNCTION
*  SD_StopTrans
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
*	Use polling to check write command completely
*************************************************************************/
SDC_CMD_STATUS SD_StopTrans_poll(void)
{
	SDC_CMD_STATUS status;

	if((status = SD_Send_Cmd_poll(SDC_CMD_CMD12,SDC_NO_ARG))!=NO_ERROR)
		return status;
	/*Read R1b*/
	if((status = SD_CheckStatus())!=NO_ERROR)
		return status;


#ifdef SD_STOP_SLOW
		//while(MSDC_Reg(SDC_STA) & SDC_STA_R1BSY);
		//do{
		//SD_GetStatus(gSD->mRCA,(kal_uint32*)&status);
			//}while((status & R1_CUR_STATE) >> 9 !=  TRAN_STA);
#endif

	return NO_ERROR;
}
/*************************************************************************
* FUNCTION
*  SDIO_WaitCardNotBusy
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
/*R1b*/
void SDIO_WaitCardNotBusy(void)
{
	while( MSDC_Reg(SDC_STA) & SDC_STA_R1BSY);
}
/*************************************************************************
* FUNCTION
*  SD_WaitCmdRdyOrTo_poll
*
* DESCRIPTION
*	write command completely
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
SDC_CMD_STATUS SD_WaitCmdRdyOrTo_poll(void)
{
	kal_uint16 sdc_cmdsta = 0;
	kal_uint32 counter = 0;
	
	while(MSDC_Reg(SDC_STA)&0x2){};
   #if 1
	do{
		sdc_cmdsta = MSDC_Reg(SDC_CMDSTA);
		if(sdc_cmdsta & SDC_CMDSTA_CMDTO)
			return ERR_CMD_TIMEOUT;
		else if(sdc_cmdsta & SDC_CMDSTA_RSPCRCERR)
			return ERR_CMD_RSPCRCERR;
		else if(sdc_cmdsta & SDC_CMDSTA_CMDRDY)
			break;
	}while(counter++ < 10000);
   #endif
	if (counter >= 10000)
	{
		return ERR_NORESP;
	}

	return NO_ERROR;
}
/*************************************************************************
* FUNCTION
*  SD_WaitCmdRdyOrTo_poll
*
* DESCRIPTION
*	write command completely
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
SDC_CMD_STATUS SD_Send_Cmd_poll(kal_uint32 cmd, kal_uint32 arg)
{
	SDC_CMD_STATUS status;
	volatile kal_uint16 sdc_cmdsta,sdc_datsta;
//    kal_prompt_trace(MOD_MSDC_HISR,"[%s %d]cmd=%d(0x%x) arg=0x%x",__FUNCTION__,__LINE__,cmd&0x03f,cmd,arg);
	/*check the controller is ready (stop transaction will fail)*/
	//if( != SDC_CMD_CMD12)
	if(!(SDC_CMD_STOP&cmd))
		while(SD_IS_SDC_BUSY && gMSDC_Handle->mIsPresent);
	else
		while(SD_IS_CMD_BUSY && gMSDC_Handle->mIsPresent);

    sdc_cmdsta = MSDC_Reg(SDC_CMDSTA);
    sdc_datsta = MSDC_Reg(SDC_DATSTA);

	/* fill out the argument*/
	MSDC_WriteReg32(SDC_ARG,arg);
	/* launch the command*/
	MSDC_WriteReg32(SDC_CMD,cmd);
	if((status = SD_WaitCmdRdyOrTo_poll())!=NO_ERROR){
//        kal_prompt_trace(MOD_MSDC_HISR,"[%s %d]cmd=%d(0x%x) arg=0x%x status=0x%x",__FUNCTION__,__LINE__,cmd&0x03f,cmd,arg,status);
		return status;
}
	return NO_ERROR;
}
/*************************************************************************
* FUNCTION
*  SDIO_Cmd53
*
* DESCRIPTION
*	IO_RW_DIRECT command
*
* PARAMETERS
*  command 53 structrue
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
kal_uint8 debug_flag = 0;
SDC_CMD_STATUS SDIO_Cmd53(cmd53_config_struct *p)
{
	SDC_CMD_STATUS status;
	kal_uint32 arg;
	kal_uint32 cmd;
	kal_uint32 *ptr = (kal_uint32 *) p->buffer;	

//guilin	ASSERT(p->adrs < 0x20000 && p->count < 0x200);   
   #ifdef MSDC_DMA      
   /*
   if (INT_QueryIsCachedRAM(ptr, p->count))
   {
      EXT_ASSERT(0, (kal_uint32)ptr, p->count, 0);
   }
*/
#ifdef MSDC_CACHED_SUPPORT
	/*tell buffer type each time this function called*/
	if (INT_QueryIsCachedRAM(ptr, p->count)){
		gMSDC_Handle->isCachedBuf = KAL_TRUE;
   }
	else
		gMSDC_Handle->isCachedBuf = KAL_FALSE;
#endif
   
   #endif /* MSDC_DMA */
#ifndef DRV_MSDC_USING_2ND
   IRQMask(IRQ_MSDC_CODE);      
#else
  IRQMask(IRQ_MSDC2_CODE);
#endif
    MSDC_CLR_FIFO(); // guilin
	
	arg = (p->rw << 31)|(p->func << 28)|(p->block << 27)|(p->op << 26)|(p->adrs << 9)|(p->count);
	cmd = SDC_CMD_CMD53 | (p->rw << 13);
	if(p->block)
	{
		cmd |= (2 << 11);	// multi-block
		BitFieldWrite32((kal_uint32*)SDC_CFG,gSDIO.block_size[1],SDC_CFG_BLKLEN);
	}
	else
	{
		cmd |= (1 << 11);	// single-block
		BitFieldWrite32((kal_uint32*)SDC_CFG,p->count,SDC_CFG_BLKLEN);
	}

	// send cmd53	   
   //if(p->rw == SDIO_WRITE)
   if(0)/*R1b*/
   {
      cmd &= ~0x380;
      cmd |= 0x380;
   }   
   else/*R1*/
   {
       cmd &= ~0x380;
      cmd |= 0x80;      
   }      
   #ifdef MSDC_DMA      
    if ((forcemcu==0)&&(p->block ==1 || (p->block ==0 && p->count >= mcudma_flag) )) // guilin
	{
      kal_uint32 total_size=0;

	   EnableMSDC_DMA();   
      if(p->block)		
			total_size = (p->count*gSDIO.block_size[p->func]);				
		else
		   total_size =p->count;
		total_size=total_size>>2;	
			
   	if(p->rw == SDIO_READ)
      	MSDC_DMATransferFirst((kal_uint32)ptr,total_size,KAL_FALSE);
      else
   		MSDC_DMATransferFirst((kal_uint32)ptr,total_size,KAL_TRUE);
   }
   #endif /* MSDC_DMA */

  	if((status = SD_Send_Cmd_poll(cmd, arg))!=NO_ERROR)
	{ 
	   goto ERROR_EXIT;		
	}		
	MSDC_LSD_ReadReg32(SDC_RESP0,&status);	
	status = (status & 0xff00)>>8;
	gSDIO.resp = status;   			
    if(gSDIO.resp & 0xcf)//guilin
    {
        status = gSDIO.resp;
        goto ERROR_EXIT;
    }
	/* start data transfer*/
	if(p->rw == SDIO_READ)
	{
        kal_uint32 i;
        #ifdef MSDC_DMA
      if ((forcemcu==0)&&(p->block ==1 || (p->block ==0 && p->count >= mcudma_flag) )) // guilin
      {
		status = MSDC_DMATransferFinal();
		/*check DMA*/
		if(status != NO_ERROR)	   
		   goto ERROR_EXIT;
		/*check Data ready*/   
		if((status=SDIO_WaitDatRdyOrTo())!=NO_ERROR)
         goto ERROR_EXIT;	
	   
      DisableMSDC_DMA();
 	   MSDC_CLR_FIFO();	   
        }
      else
      #endif/*MSDC_DMA*/
		if(p->block)
		{
			kal_uint32 total;

			total = (p->count*gSDIO.block_size[p->func]+3)>>2;
			for(i=0;i< total;)
			{			      
				if(!MSDC_IS_FIFO_EMPTY)
				{
					*(ptr+i) = MSDC_Reg32(MSDC_DAT);
					i++;
					if(i%((gSDIO.block_size[p->func]+3) >> 2)==0)
				{
					debug_flag = 1;
					if((status=SDIO_WaitDatRdyOrTo())!=NO_ERROR)
					   goto ERROR_EXIT;					
				}
			}
		}
		}
		else
		{
			for(i=0;i< (p->count+3)>>2;)
			{			      
				if(!MSDC_IS_FIFO_EMPTY)
				{
					*(ptr+i) = MSDC_Reg32(MSDC_DAT);
					i++;
					if((i%((p->count+3)>> 2)==0)&&(i!=0))
				{
					debug_flag = 1;
					if((status=SDIO_WaitDatRdyOrTo())!=NO_ERROR)
					   goto ERROR_EXIT;					
				}
			}
		}
		}
	}
	else
	{	// SDIO_WRITE
        kal_uint32 i;     
        #ifdef MSDC_DMA 
       if ((forcemcu==0)&&(p->block ==1 || (p->block ==0 && p->count >= mcudma_flag) )) // guilin
       {
		status = MSDC_DMATransferFinal();
		/*check DMA*/
		if(status != NO_ERROR)	   
		   goto ERROR_EXIT;
		/*check Data ready*/   
		if((status=SDIO_WaitDatRdyOrTo())!=NO_ERROR)
         goto ERROR_EXIT;	
	   
      DisableMSDC_DMA();
	   MSDC_CLR_FIFO();	   	         
        }
        else
        #endif/*MSDC_DMA*/ 
		if(p->block)
		{
			kal_uint32 total;

			total = (p->count*gSDIO.block_size[p->func]+3)>>2;
			for(i=0;i< total;)
			{			      			      
				if(!MSDC_IS_FIFO_FULL)
				{
					MSDC_WriteReg32(MSDC_DAT, *(ptr+i));
					i++;
					if(i%((gSDIO.block_size[p->func]+3) >> 2)==0)
				{
					debug_flag = 1;
					if((status=SDIO_WaitDatRdyOrTo())!=NO_ERROR)
					   goto ERROR_EXIT;					
				}
				}				
			}
		}
		else
		{
			for(i=0;i< (p->count+3)>>2;)
			{			   
				if(!MSDC_IS_FIFO_FULL)
				{
					MSDC_WriteReg32(MSDC_DAT, *(ptr+i));
					i++;
					if(i%((p->count+3) >> 2)==0)
				{
					debug_flag = 1;
					if((status=SDIO_WaitDatRdyOrTo())!=NO_ERROR)
					   goto ERROR_EXIT;						     
				}
			}
		   }
		}
	}   
	//SD_StopTrans_poll();
	/*Blue modify for Inno SDIO card*/
#if 0
/* under construction !*/
/* under construction !*/
#endif
	  /*Blue modify for Innofidi SDIO card. Innofidi SDIO card has issue on this command, when 1) block mode read, 2)limited block counts, 3) no timeout occur, we skill this command*/
	if((p->block) && (SDIO_READ == p->rw) && (p->count < 0x200) && (KAL_FALSE == gMSDC_Handle->is_timeout)){
	  	/*do nothing*/
	}
	else{
        	SDIO_stop();
  	}

#ifndef DRV_MSDC_USING_2ND
	IRQUnmask(IRQ_MSDC_CODE);
#else
	IRQUnmask(IRQ_MSDC2_CODE);
#endif
    RESET_MSDC(); // guilin
    MSDC_CLR_FIFO(); // guilin

	return NO_ERROR;
	ERROR_EXIT:
   {  
      kal_uint32 tmp;
      #ifdef MSDC_DMA
      DisableMSDC_DMA();
      #endif
      if(p->block)
	      SD_StopTrans_poll();
        SDIO_stop();
		MSDC_LSD_ReadReg32(SDC_CMDSTA,&tmp);
		MSDC_LSD_ReadReg32(SDC_DATSTA,&tmp);
		MSDC_CLR_FIFO();
#ifndef DRV_MSDC_USING_2ND
      IRQUnmask(IRQ_MSDC_CODE);
#else
    IRQUnmask(IRQ_MSDC2_CODE);
#endif
   	return status;
   }
}

/*SDIO_Cmd53_poll*/
SDC_CMD_STATUS SDIO_Cmd53_isr(cmd53_config_struct *p)
{
	SDC_CMD_STATUS status;
	kal_uint32 arg;
	kal_uint32 cmd,i;
	kal_uint32 *ptr = (kal_uint32 *) p->buffer;	

	ASSERT(p->adrs < 0x20000 && p->count < 0x200);      
	arg = (p->rw << 31)|(p->func << 28)|(p->block << 27)|(p->op << 26)|(p->adrs << 9)|(p->count);
	cmd = SDC_CMD_CMD53 | (p->rw << 13);
	if(p->block)
	{
		cmd |= (2 << 11);	// multi-block
		BitFieldWrite32((kal_uint32*)SDC_CFG,gSDIO.block_size[1],SDC_CFG_BLKLEN);
	}
	else
	{
		cmd |= (1 << 11);	// single-block
		BitFieldWrite32((kal_uint32*)SDC_CFG,p->count,SDC_CFG_BLKLEN);
	}

	// send cmd53	   
   //if(p->rw == SDIO_WRITE)
   if(0)/*R1b*/
   {
      cmd &= ~0x380;
      cmd |= 0x380;
   }   
   else/*R1*/
   {
       cmd &= ~0x380;
      cmd |= 0x80;      
   }      
	if((status = SD_Send_Cmd_poll(cmd, arg))!=NO_ERROR)
	{ 
	   goto ERROR_EXIT;		
	}		
	MSDC_LSD_ReadReg32(SDC_RESP0,&status);	
	status = (status & 0xff00)>>8;
	gSDIO.resp = status;   			
	/* start data transfer*/
	if(p->rw == SDIO_READ)
	{

		if(p->block)
		{
			kal_uint32 total;

			total = (p->count*gSDIO.block_size[p->func]+3)>>2;
			for(i=0;i< total;)
			{
			      
				if(!MSDC_IS_FIFO_EMPTY)
				{
					*(ptr+i) = MSDC_Reg32(MSDC_DAT);
					i++;
					if(i%((gSDIO.block_size[p->func]+3) >> 2)==0)
				{
					debug_flag = 1;
					if((status=SDIO_WaitDatRdyOrTo())!=NO_ERROR)
					   goto ERROR_EXIT;					
				}
			}
				
			}
		}
		else
		{
			for(i=0;i< (p->count+3)>>2;)
			{			      
				if(!MSDC_IS_FIFO_EMPTY)
				{
					*(ptr+i) = MSDC_Reg32(MSDC_DAT);
					i++;
					if(i%((p->count+3)>> 2)==0)
				{
					debug_flag = 1;
					if((status=SDIO_WaitDatRdyOrTo())!=NO_ERROR)
					   goto ERROR_EXIT;					
				}
			}

		}

		}
	}
	else
	{	// SDIO_WRITE
		if(p->block)
		{
			kal_uint32 total;

			total = (p->count*gSDIO.block_size[p->func]+3)>>2;
			for(i=0;i< total;)
			{			      			      
				if(!MSDC_IS_FIFO_FULL)
				{
					MSDC_WriteReg32(MSDC_DAT, *(ptr+i));
					i++;
					if(i%((gSDIO.block_size[p->func]+3) >> 2)==0)
				{
					debug_flag = 1;
					if((status=SDIO_WaitDatRdyOrTo())!=NO_ERROR)
					   goto ERROR_EXIT;					
				}
				}
				

			}
		}
		else
		{
			for(i=0;i< (p->count+3)>>2;)
			{			   
				if(!MSDC_IS_FIFO_FULL)
				{
					MSDC_WriteReg32(MSDC_DAT, *(ptr+i));
					i++;
					if(i%((p->count+3) >> 2)==0)
				{
					debug_flag = 1;
					if((status=SDIO_WaitDatRdyOrTo())!=NO_ERROR)
					   goto ERROR_EXIT;						     
				}
			}

		}

		}
	}   	

	/*Blue modify for Inno SDIO card*/
	if((p->block) && (MSDC_Reg(SDC_STA) & SDC_STA_DATBUSY) )
	  SD_StopTrans_poll();
   SDIO_stop();	
	return NO_ERROR;
	ERROR_EXIT:
   {  
      kal_uint32 tmp;      
      #ifdef MSDC_DMA  
      DisableMSDC_DMA();
      #endif
      if(p->block)
	      SD_StopTrans_poll();
      SDIO_stop();
		MSDC_LSD_ReadReg32(SDC_CMDSTA,&tmp);
		MSDC_LSD_ReadReg32(SDC_DATSTA,&tmp);
		MSDC_CLR_FIFO();    
   	return status;
   }
}
/*************************************************************************
* FUNCTION
*  SDIO_Cmd52
*
* DESCRIPTION
*	IO_RW_DIRECT command
*
* PARAMETERS
*  command 52 structrue
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
/* refer to the IO_RW_DIRECT command (CMD52) in SDIO 1.1 chapter 5.1*/
SDC_CMD_STATUS SDIO_Cmd52(cmd52_config_struct *p)
{
	SDC_CMD_STATUS status;
	kal_uint32 arg = 0;
	kal_uint32 cmd;	
   
#ifndef DRV_MSDC_USING_2ND
   IRQMask(IRQ_MSDC_CODE);
#else
	IRQMask(IRQ_MSDC2_CODE);
#endif

	if(p->rw == SDIO_WRITE)
	{
		arg |= (IO_ARG_RW_FLAG|p->data);
	}
	arg |= ((p->raw << 27)|(p->func << 28)|(p->adrs <<9));

	cmd = SDC_CMD_CMD52 ;
	if(p->stop)
		cmd |= SDC_CMD_STOP;
      
   if(p->stop)
    //if(0)
    {
      cmd &= ~0x380;
      cmd |= 0x380;
   }   
   #if 1
   else
   {
      cmd &= ~0x380;
      cmd |= 0x80;      
   }    
   #endif
	if((status = SD_Send_Cmd_poll(cmd, arg))!=NO_ERROR)
		goto ERROR_EXIT;         		
	while(MSDC_Reg(SDC_STA) & SDC_STA_R1BSY);	
	MSDC_LSD_ReadReg32(SDC_RESP0,&status);
	if((p->rw == SDIO_READ)||((p->rw==SDIO_WRITE)&&(p->raw==KAL_TRUE)) ) // guilin
	{
		p->data = status & 0xff;
	}
	status = (status & 0xff00)>>8;
	gSDIO.state = (status & 0x30)>>4;	
	gSDIO.resp = status;	
    if(gSDIO.resp & R5_ERROR_CHECK)//guilin
    {
        status = gSDIO.resp;
        goto ERROR_EXIT;
    }
#ifndef DRV_MSDC_USING_2ND
	IRQUnmask(IRQ_MSDC_CODE);   
#else
	IRQUnmask(IRQ_MSDC2_CODE);
#endif

   return NO_ERROR;   
   ERROR_EXIT:
   {
      kal_uint32 tmp;
		MSDC_LSD_ReadReg32(SDC_CMDSTA,&tmp);
		MSDC_CLR_FIFO();
#ifndef DRV_MSDC_USING_2ND
      IRQUnmask(IRQ_MSDC_CODE);	   
#else
		IRQUnmask(IRQ_MSDC2_CODE);
#endif
   	return status;
   }	
	
	
}
SDC_CMD_STATUS SDIO_Cmd52_isr(cmd52_config_struct *p)
{
	SDC_CMD_STATUS status;
	kal_uint32 arg = 0;
	kal_uint32 cmd;

	if(p->rw == SDIO_WRITE)
	{
		arg |= (IO_ARG_RW_FLAG|p->data);
	}
	arg |= ((p->raw << 27)|(p->func << 28)|(p->adrs <<9));

	cmd = SDC_CMD_CMD52 ;
	if(p->stop)
		cmd |= SDC_CMD_STOP;
	   if(p->stop)
    //if(0)
    {
      cmd &= ~0x380;
      cmd |= 0x380;
   }   
   #if 1
   else
   {
      cmd &= ~0x380;
      cmd |= 0x80;      
   }    
   #endif	
	if((status = SD_Send_Cmd_poll(cmd, arg))!=NO_ERROR)		
		goto ERROR_EXIT;	
   while(MSDC_Reg(SDC_STA) & SDC_STA_R1BSY);
	MSDC_LSD_ReadReg32(SDC_RESP0,&status);
	if(p->rw == SDIO_READ)
	{
		p->data = status & 0xff;
	}
	status = (status & 0xff00)>>8;
	gSDIO.state = (status & 0x30)>>4;	
	gSDIO.resp = status;   
	return NO_ERROR;   
	/*error handle*/
   ERROR_EXIT:
   {  
      kal_uint32 tmp;  
		MSDC_LSD_ReadReg32(SDC_CMDSTA,&tmp);
		MSDC_CLR_FIFO();      
   	return status;
   }		

}   

/* for SDIO*/
/*************************************************************************
* FUNCTION
*  SDIO_Cmd5
*
* DESCRIPTION
*	SDIO initialization command
*
* PARAMETERS
*
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	it is similar to the operation of ACMD41 for SD memory cards.
*
*************************************************************************/
SDC_CMD_STATUS SDIO_Cmd5(kal_uint32 ocr)
{
	SDC_CMD_STATUS status;     
   
	if((status = SD_Send_Cmd_poll(SDC_CMD_CMD5,ocr))!=NO_ERROR)	
		return status;

#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
	/*we use different flag to distinguish SD and MMC, we have to set this flag to enable high density support*/
	gSD->flags |= SD_FLAG_SD_TYPE_CARD;
#endif	
	/*read R4*/
	MSDC_LSD_ReadReg32(SDC_RESP0,&status);
	gSDIO.ocr = status &0xFFFFFF;
	status >>= 24;
	gSDIO.num_func = (kal_uint8)(status & 0x70) >> 4;	
	gSDIO.mem_present = ((status & 0x08) != 0) ;	
	gSDIO.io_ready = ((status & SDIO_R4_CARD_READY)!=0);
	#ifdef _SDIO_DEBUG_
	dbg_print("card function number %d\r\n", gSDIO.num_func);							
	dbg_print("memory card present %d\r\n", gSDIO.mem_present);						
	dbg_print("card ready %d\r\n", gSDIO.io_ready);	
	#endif
	return NO_ERROR;
}

void SDIO_dispatch_IO(SDIO_function_id_enum function)   
{
   /*single function*/   
   kal_take_mutex(sdio_mutex);    
   /*multiple function*/
   /*not support now*/
}

void SDIO_resume_IO(SDIO_function_id_enum function)   
{
   /*single function*/   
   kal_give_mutex(sdio_mutex);    
   /*multiple function*/
   /*not support now*/
   
}
/*************************************************************************
* FUNCTION
*  SDIO_read_CIS
*
* DESCRIPTION
*	This function is to read function's CIS
*
* PARAMETERS
*  function: function id
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	This function is only user for SDIO bus driver
*
*************************************************************************/
SDC_CMD_STATUS SDIO_read_CIS(SDIO_function_id_enum function)
{
   kal_uint32 i=0, j=0;
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;      
   ASSERT(function<8);          
   /* read all configuration register of CCCR*/
   while(1)
   {
	   cmd52.rw = SDIO_READ;
	   cmd52.func = SDIO_FUCN_0;
	   cmd52.raw = KAL_FALSE;
	   cmd52.stop = KAL_FALSE;
	   if(function==0)
	      cmd52.adrs =(kal_uint32)((sdio_cccr_reg[11]<<16)|(sdio_cccr_reg[10]<<8)|
	                                      (sdio_cccr_reg[9])+i);
	   else 
	      cmd52.adrs =(kal_uint32)((sdio_fbr_reg[11]<<16)|(sdio_fbr_reg[10]<<8)|
	                                      (sdio_fbr_reg[9])+i);
	   cmd52.data = 0;
	   if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	      return status;
	   sdio_tuple[function][i]=cmd52.data;
	   i++;
	   if(cmd52.data==CISTPL_NULL||cmd52.data==CISTPL_END)
	      return NO_ERROR;
	   else
	   {
	      kal_uint32 tuple_size=0;
	      cmd52.rw = SDIO_READ;	      
	      cmd52.raw = KAL_FALSE;
	      cmd52.stop = KAL_FALSE;
	      cmd52.adrs++;
	      if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	         return status;
	      sdio_tuple[function][i]=cmd52.data;	      
	      tuple_size=cmd52.data;
	      i++;
	      for(j=0;j<tuple_size;j++)
	      {
	         cmd52.adrs++;
	         if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	            return status;
	         sdio_tuple[function][i]=cmd52.data;	      
	         i++;
	      }      
	   }         
	}   
}
/*************************************************************************
* FUNCTION
*  SDIO_read_CCCR_ver
*
* DESCRIPTION
*	This function is to read card's CCCR version 
*
* PARAMETERS
*  *version
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/   
/*read SDIO CCCR version*/
SDC_CMD_STATUS SDIO_read_CCCR_ver(kal_uint8 *version)
{
   SDC_CMD_STATUS status=NO_ERROR;
      
   #if 1
   *version=sdio_cccr_reg[0]&SDIO_CCCR_VERISON_MASK;	   
   #else  
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	return status;
	
}

SDC_CMD_STATUS SDIO_stop(void)
{
   SDC_CMD_STATUS status=NO_ERROR;
         
   cmd52_config_struct cmd52;   
   cmd52.rw = SDIO_WRITE;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_TRUE;
	cmd52.adrs = 6;
	cmd52.data = 1;
	status = SDIO_Cmd52(&cmd52);	   
	/*wait card is not busy*/	
   SDIO_WaitCardNotBusy();		
	return status;	
}
SDC_CMD_STATUS SDIO_WaitDatRdyOrTo(void)
{
	// maybe have to add a timer
	register kal_uint16 sdc_datsta = 0;

	int counter = 0;
	//while(MSDC_Reg(SDC_STA)&0x4){};
	do{
		sdc_datsta = MSDC_Reg(SDC_DATSTA);

		/*Blue modify for Inno SDIO card, in SDIO, this data timeout is legal*/
		if((0 == MSDC_Reg(DMA_RLCT(gMSDC_Handle->msdc_dmaport))) && (0x3 == sdc_datsta))
			sdc_datsta = 0x1;
		
		if(sdc_datsta & SDC_DATSTA_DATTO)
			return ERR_DAT_TIMEOUT;
		else if(sdc_datsta & SDC_DATSTA_DATCRCERR)
			return ERR_DAT_CRCERR;
		else if(sdc_datsta & SDC_DATSTA_BLKDONE)
			break;
	}while(1);//(counter++  < 1000);

	if (counter >= 1000)
		return ERR_NORESP;
	return NO_ERROR;
}
/*************************************************************************
* FUNCTION
*  SDIO_read_SDIO_ver
*
* DESCRIPTION
*	This function is to read card's SDIO version 
*
* PARAMETERS
*  *version
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/   
/*read SDIO spec version*/
SDC_CMD_STATUS SDIO_read_SDIO_ver(kal_uint8 *version)
{
   SDC_CMD_STATUS status=NO_ERROR;
   
   #if 1
   *version=sdio_cccr_reg[0]&SDIO_VERISON_MASK>>SDIO_VERISON_SHIFT;	
   #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	return status;
	
}   
/*************************************************************************
* FUNCTION
*  SDIO_read_SD_ver
*
* DESCRIPTION
*	This function is to read card's SD version 
*
* PARAMETERS
*  *version
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*
*************************************************************************/
/*read SD spec version*/
SDC_CMD_STATUS SDIO_read_SD_ver(kal_uint8 *version)
{
   SDC_CMD_STATUS status=NO_ERROR;
   
   #if 1
   *version=sdio_cccr_reg[1]&SDIO_SD_VERISON_MASK;	
   #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	return status;
}   
/*************************************************************************
* FUNCTION
*  SDIO_read_CCCR
*
* DESCRIPTION
*	This function is to read card CCCR
*
* PARAMETERS
*  *version
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	only used for SDIO bus driver
*************************************************************************/
SDC_CMD_STATUS SDIO_read_CCCR(void)
{
   #if 1
   kal_uint32 i;
    SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;      
   cmd52.rw = SDIO_READ;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	for(i=0;i<SDIO_CCCR_SIZE;i++)
	{
	   cmd52.adrs =i;
	   status = SDIO_Cmd52(&cmd52);	
	   if(status != NO_ERROR)
	        return status;
	   sdio_cccr_reg[i]=cmd52.data;	   
	}   
   #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	return status;
}
/*************************************************************************
* FUNCTION
*  SDIO_read_FBR
*
* DESCRIPTION
*	This function is to read card FBR
*
* PARAMETERS
*  function: function id
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	only used for SDIO bus driver
*************************************************************************/
SDC_CMD_STATUS SDIO_read_FBR(SDIO_function_id_enum function)
{
   #if 1  /*to cover 5911 issue*/ 
   SDC_CMD_STATUS status;   
   cmd52_config_struct cmd52;   
   kal_uint32 i=0;
      
   cmd52.rw = SDIO_READ;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;	
	cmd52.data = 0;
	for(i=0;i<SDIO_FBR_SIZE;i++)
	{
	   cmd52.adrs = 0x100*function+i;
	   status=SDIO_Cmd52(&cmd52);
	   sdio_fbr_reg[i] = cmd52.data;	
	}   
	
	return status;	
   #else 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
}
/*************************************************************************
* FUNCTION
*  SDIO_read_power_control
*
* DESCRIPTION
*	This function is to read card's power control
*
* PARAMETERS
*  None
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	only used for SDIO bus driver
*************************************************************************/
SDC_CMD_STATUS SDIO_read_power_control(void)
{
   SDC_CMD_STATUS status;   
   cmd52_config_struct cmd52;   
      
   cmd52.rw = SDIO_READ;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 0x12;
	cmd52.data = 0;
	status=SDIO_Cmd52(&cmd52);
	gSDIO.power_control = cmd52.data;	
	return status;	
}
/*************************************************************************
* FUNCTION
*  SDIO_support_MPS
*
* DESCRIPTION
*	This function is to query card's power control
*
* PARAMETERS
*  None
*
* RETURNS
*  support or not
*
* GLOBALS AFFECTED
*	only used for SDIO bus driver
*************************************************************************/
kal_bool SDIO_support_MPS(void)
{
     return ((gSDIO.power_control&0x1));   
}   
/*************************************************************************
* FUNCTION
*  SDIO_enable_MPS
*
* DESCRIPTION
*	This function is to enable card's power control
*
* PARAMETERS
*  enable: enable or disable
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	only used for SDIO bus driver
*************************************************************************/
SDC_CMD_STATUS SDIO_enable_MPS(kal_bool enable)
{
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
      
   cmd52.rw = SDIO_WRITE;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 0x12;
	if(enable)
	   cmd52.data |= 0x2;
	else
	   cmd52.data &= ~0x2;
	   
	status=SDIO_Cmd52(&cmd52);	   
	if(enable)   	
	   gSDIO.power_control |= 0x2;
	else
	   gSDIO.power_control &= ~0x2;   
		
	return status;	
}   
/*************************************************************************
* FUNCTION
*  SDIO_read_capacity
*
* DESCRIPTION
*	This function is to read card's capacity
*
* PARAMETERS
*  enable: None
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	only used for SDIO bus driver
*************************************************************************/
SDC_CMD_STATUS SDIO_read_capacity(void)
{
   SDC_CMD_STATUS status=NO_ERROR;
   #if 1
   gSDIO.capability = sdio_cccr_reg[8];
   #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	return status;	
}      
/*************************************************************************
* FUNCTION
*  SDIO_support_SDC
*
* DESCRIPTION
*	This function is to query if card can support SDC
*
* PARAMETERS
*  None
*
* RETURNS
*  support or not
*
* GLOBALS AFFECTED
*	
*************************************************************************/
/*query card capacity*/
kal_bool SDIO_support_SDC(void)
{   
   return ((gSDIO.capability&0x1));   
}   
/*************************************************************************
* FUNCTION
*  SDIO_support_SMB
*
* DESCRIPTION
*	This function is to query if card can support Multiple Block
*
* PARAMETERS
*  None
*
* RETURNS
*  support or not
*
* GLOBALS AFFECTED
*	
*************************************************************************/
kal_bool SDIO_support_SMB(void)
{   
   return ((gSDIO.capability&0x2)>>1);   
}   
/*************************************************************************
* FUNCTION
*  SDIO_support_SRW
*
* DESCRIPTION
*	This function is to query if card can support Suspend/Resume
*
* PARAMETERS
*  None
*
* RETURNS
*  support or not
*
* GLOBALS AFFECTED
*	
*************************************************************************/
kal_bool SDIO_support_SRW(void)
{   
   return ((gSDIO.capability&0x4)>>2);   
}   
/*************************************************************************
* FUNCTION
*  SDIO_support_SBS
*
* DESCRIPTION
*	This function is to query if card can support Read/Wait
*
* PARAMETERS
*  None
*
* RETURNS
*  support or not
*
* GLOBALS AFFECTED
*	
*************************************************************************/
kal_bool SDIO_support_SBS(void)
{   
   return ((gSDIO.capability&0x8)>>3);   
}   
/*************************************************************************
* FUNCTION
*  SDIO_support_S4MI
*
* DESCRIPTION
*	This function is to query if card can support interrupt during multiple block
*
* PARAMETERS
*  None
*
* RETURNS
*  support or not
*
* GLOBALS AFFECTED
*	
*************************************************************************/
kal_bool SDIO_support_S4MI(void)
{   
   return ((gSDIO.capability&0x10)>>4);   
}   
/*************************************************************************
* FUNCTION
*  SDIO_enable_E4MI
*
* DESCRIPTION
*	This function is to enable interrupt during multiple block
*
* PARAMETERS
*  None
*
* RETURNS
*  support or not
*
* GLOBALS AFFECTED
*	only used for SDIO bus driver
*************************************************************************/
SDC_CMD_STATUS SDIO_enable_E4MI(kal_bool enable)
{
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   kal_uint8 temp_data; 
   
   if(!SDIO_support_S4MI())
      return SDIO_4MI_NOT_SUPPORT;
   
   cmd52.rw = SDIO_WRITE;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 8;
	if(enable)
	{
	   cmd52.data = 0x20;
	   temp_data=0x20;
	}   
	else
	{
	   cmd52.data = 0;
	   temp_data=0;
	}   
	if((status = SDIO_Cmd52(&cmd52))==NO_ERROR)
	{
	   /*double check*/
	   cmd52.rw = SDIO_READ;   
	   status = SDIO_Cmd52(&cmd52);	      
	   if((cmd52.data&0x20)!=temp_data)	   
	      ASSERT(0);	   
	          
	   if(enable)
	      gSDIO.capability|=0x20;	   
	   else
	     gSDIO.capability&=~0x20;	       	   	   	   
	}   	
	
	return status;		      
}   
/*************************************************************************
* FUNCTION
*  SDIO_enable_E4MI
*
* DESCRIPTION
*	This function is to query if card is a low speed card
*
* PARAMETERS
*  None
*
* RETURNS
*  support or not
*
* GLOBALS AFFECTED
*	
*************************************************************************/
kal_bool SDIO_support_LSC(void)
{   
   return ((gSDIO.capability&0x40)>>6);   
}   
/*************************************************************************
* FUNCTION
*  SDIO_support_4BLS
*
* DESCRIPTION
*	This function is to query if card can support 4-bits in low speed card
*
* PARAMETERS
*  None
*
* RETURNS
*  support or not
*
* GLOBALS AFFECTED
*	
*************************************************************************/
kal_bool SDIO_support_4BLS(void)
{   
   return ((gSDIO.capability&0x80)>>7);   
}
/*************************************************************************
* FUNCTION
*  SDIO_configure_bus
*
* DESCRIPTION
*	This function is to configure bus width
*
* PARAMETERS
*  bus: bus width
*
* RETURNS
*  bus
*
* GLOBALS AFFECTED
*	
*************************************************************************/
SDC_CMD_STATUS SDIO_configure_bus(SD_BITWIDTH bus)
{   
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
   
	cmd52.rw = SDIO_READ;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 7;
	if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	{	   
	   return status;	   
	}   
	cmd52.data &= ~0x3;
	cmd52.data |= (bus|0x80);/*also disable card detection*/
	cmd52.rw = SDIO_WRITE;
	if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	{	 
	   return status;
	}   
	gSDIO.bit_width=bus;
	if(bus==BIT_4W)	
	   MSDC_SetBits32(SDC_CFG,SDC_CFG_MDLEN);	        
	
	return NO_ERROR;
}
/*************************************************************************
* FUNCTION
*  SDIO_enable_IO
*
* DESCRIPTION
*	This function is to enable function
*
* PARAMETERS
*  function: function id
*  enable: enable or disable
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
SDC_CMD_STATUS SDIO_enable_IO(SDIO_function_id_enum function, kal_bool enable)
{   
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
   SDIO_dispatch_IO(SDIO_FUCN_0);
	cmd52.rw = SDIO_READ;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 2;
	if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	{
	   SDIO_resume_IO(SDIO_FUCN_0); 
	   return status;	   
	}   
	if(enable)   	
	   cmd52.data |= (function<<1);	
	else   	
	   cmd52.data &= ~(function<<1);	 
		
	cmd52.rw = SDIO_WRITE;
	if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	{
	   SDIO_resume_IO(SDIO_FUCN_0); 
	   return status;
	}   
   SDIO_resume_IO(SDIO_FUCN_0); 
	return NO_ERROR;
}
/*************************************************************************
* FUNCTION
*  SDIO_check_IO_ready
*
* DESCRIPTION
*	This function is to check function status
*
* PARAMETERS
*  function: function id
*  *ready: ready or not
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
SDC_CMD_STATUS SDIO_check_IO_ready(SDIO_function_id_enum function, kal_bool *ready)
{   
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
   SDIO_dispatch_IO(SDIO_FUCN_0);
	cmd52.rw = SDIO_READ;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 3;
	status = SDIO_Cmd52(&cmd52);	   
	*ready=(cmd52.data&(1<<function))>>function;		   	   		
	SDIO_resume_IO(SDIO_FUCN_0); 
	return status;
}
/*************************************************************************
* FUNCTION
*  SDIO_enable_IO_Int
*
* DESCRIPTION
*	This function is to configure function interrupt enable
*
* PARAMETERS
*  function: function id
*  enable: enable or diable
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
SDC_CMD_STATUS SDIO_enable_IO_Int(SDIO_function_id_enum function, kal_bool enable)
{   
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
   SDIO_dispatch_IO(SDIO_FUCN_0);
	cmd52.rw = SDIO_READ;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 4;
	if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	{
	   SDIO_resume_IO(SDIO_FUCN_0); 
	   return status;	   
	}	   
	if(enable)   	
	   cmd52.data |= (1<<function);	
	else   	
	   cmd52.data &= ~(1<<function);	 
		
	cmd52.rw = SDIO_WRITE;
		
	status = SDIO_Cmd52(&cmd52);	      	   	   		
	SDIO_resume_IO(SDIO_FUCN_0); 
	return status;
}
/*************************************************************************
* FUNCTION
*  SDIO_int_registration
*
* DESCRIPTION
*	This function is to register interrupt handler
*
* PARAMETERS
*  function: function id
*  func: interrupt handler
* RETURNS
*  None
*
* GLOBALS AFFECTED
*	
*************************************************************************/
void SDIO_int_registration(SDIO_function_id_enum function, void (func)(void))
{   
   gSDIO.callback[function]=func;
}   
/*************************************************************************
* FUNCTION
*  SDIO_HISR_Entry
*
* DESCRIPTION
*	This function is to handle SDIO interrupt
*
* PARAMETERS
*  None 
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*	
*************************************************************************/
SDC_CMD_STATUS int_status;
void SDIO_HISR_Entry(void)
{
   
   cmd52_config_struct cmd52;
   cmd53_config_struct cmd53;
   kal_uint8 uvalue[4];
   kal_uint32 count;   
   if(gSDIO.state!=CMD&&gSDIO.state!=TRN)		      
   {
      #ifdef MSDC_INT
		kal_set_eg_events(gMSDC_Handle->MSDC_Events,EVENT_SDMCIRQ,KAL_OR);		      		
		#endif
	}	
   else
   {   
      #if 1
	   cmd52.rw = SDIO_READ;
	   cmd52.func = 0;
	   cmd52.raw = KAL_FALSE;
	   cmd52.stop = KAL_FALSE;
	   cmd52.adrs = 5;
	   
	   if((int_status = SDIO_Cmd52_isr(&cmd52))==NO_ERROR)	
	   { 
	    //kalDevRegWrite//HAL_MCR_WR(prAdapter, MCR_WHLPCR, WHLPCR_INT_EN_CLR);
	    uvalue[0]=2;
	    uvalue[1]=0;
	    uvalue[2]=0;
	    uvalue[3]=0;
	    cmd53.adrs = 0x04;
	    cmd53.block = KAL_FALSE;
	    cmd53.buffer=(kal_uint32)&uvalue[0];
	    cmd53.count =4;
	    cmd53.func=DCL_SDIO_FUCN_1;
	    cmd53.op=DCL_SDIO_FIX;
	    cmd53.rw=SDIO_WRITE;
	    SDIO_Cmd53_isr(&cmd53);
	    
//guilin         for(count=SDIO_FUCN_1;count<SDIO_MAX_FUCN_ID;count++)	
//guilin         {
//guilin            if(cmd52.data&(1<<count))
//guilin               gSDIO.callback[count]();
//guilin         }
      }
      else
      {
        /*dbg_print("int read failed\r\n");*/
      }    
      #endif        
   }            
}   

/*************************************************************************
* FUNCTION
*  SDIO_check_IO_Int
*
* DESCRIPTION
*	This function is to check interrupt status
*
* PARAMETERS
*  function: function id
*  *pending: interrupt status 
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/  
SDC_CMD_STATUS SDIO_check_IO_Int(SDIO_function_id_enum function, kal_bool *pending)
{   
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
   SDIO_dispatch_IO(SDIO_FUCN_0);
	cmd52.rw = SDIO_READ;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 5;
	status = SDIO_Cmd52(&cmd52);	
	*pending=(cmd52.data&(1<<function))>>function;		   	   		
	SDIO_resume_IO(SDIO_FUCN_0); 
	return status;
}
/*************************************************************************
* FUNCTION
*  SDIO_configure_BLK_size
*
* DESCRIPTION
*	This function is to configure block size
*
* PARAMETERS
*  function: function id
*  size: block size
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/
SDC_CMD_STATUS SDIO_configure_BLK_size(SDIO_function_id_enum function, kal_uint32 size)
{   
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
   SDIO_dispatch_IO(SDIO_FUCN_0);
	cmd52.rw = SDIO_WRITE;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 0x10+0x100*function;
	cmd52.data = size&0xff;
	status = SDIO_Cmd52(&cmd52);	   
   if(size>=256)
   {
	   cmd52.adrs = 0x11+0x100*function;
	   cmd52.data = (size&0xff00)>>8;    
	   status = SDIO_Cmd52(&cmd52);	   
	}   
   if(status==NO_ERROR)					   
   {
	   gSDIO.block_size[function]=size;   	   		
	   /*set block length as size*/
	   BitFieldWrite32((kal_uint32*)SDC_CFG,(kal_uint32)size,SDC_CFG_BLKLEN);
	}   
    SDIO_resume_IO(SDIO_FUCN_0); 
    return status;
}

SDC_CMD_STATUS SDIO_get_BLK_size(SDIO_function_id_enum function, kal_uint32 *size)
{   
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   kal_uint32 temp,temp1;

   SDIO_dispatch_IO(SDIO_FUCN_0);

   temp = MSDC_Reg32(SDC_CFG)&SDC_CFG_BLKLEN;
   
	cmd52.rw = SDIO_READ;
	cmd52.func = 0;//function;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 0x10+0x100*function;
	status = SDIO_Cmd52(&cmd52);	
    if(status==NO_ERROR)
    {
        temp1 = cmd52.data;
    }
    else
    {
        goto SDIO_get_BLK_size_exit;
    }
	cmd52.adrs = 0x11+0x100*function;
	status = SDIO_Cmd52(&cmd52);	
    if(status==NO_ERROR)
    {
        temp1 |= (kal_uint32)cmd52.data <<8;
    }
    else
    {
        goto SDIO_get_BLK_size_exit;
    }

    if(temp == temp1 && temp ==gSDIO.block_size[function])
    {
	   *size = temp;   	   		
	}
	else
	{
        *size = temp1;
        status = ERR_INVALID_BKLENGTH; // error
        kal_prompt_trace(MOD_MSDC_HISR,"ERROR,block=%d %d %d",temp,temp1,gSDIO.block_size[function]);
	}

SDIO_get_BLK_size_exit:

	SDIO_resume_IO(SDIO_FUCN_0); 
	return status;
}
/*************************************************************************
* FUNCTION
*  SDIO_query_BLK_size
*
* DESCRIPTION
*	This function is to query function's maximum block size
*
* PARAMETERS
*  function: function id
*
* RETURNS
*  size: block size
*
* GLOBALS AFFECTED
*	
*************************************************************************/
kal_uint32 SDIO_query_BLK_size(SDIO_function_id_enum function)
{
   kal_uint32 max_block_size;
   kal_uint32 i;
   for(i=0;i<SDIO_TUPLE_SIZE;i++) 
   {      
      if(sdio_tuple[function][i]==0x22)
      {
         if(function==SDIO_FUCN_0)   
            max_block_size=(sdio_tuple[function][i+3])|(sdio_tuple[function][i+4]<<8);
         else
            max_block_size=(sdio_tuple[function][i+14])|(sdio_tuple[function][i+15]<<8);   
         return   max_block_size;         
      }  
   }
   return 0;         
}  
/*************************************************************************
* FUNCTION
*  SDIO_query_IO_id
*
* DESCRIPTION
*	This function is to query application function id
*
* PARAMETERS
*  ap: application type
*
* RETURNS
*  function: function id
*
* GLOBALS AFFECTED
*	
*************************************************************************/ 
SDIO_function_id_enum SDIO_query_IO_id(SDIO_interface_code_enum ap)
{
   switch(ap)
   {
      case SDIO_INTERFACE_NULL:        
      break;      
      case SDIO_INTERFACE_UART:
      break;
      case SDIO_INTERFACE_A_BT:
      break;
      case SDIO_INTERFACE_B_BT:
      break;
      case SDIO_INTERFACE_GPS:
      break;
      case SDIO_INTERFACE_CAMERA:
      break;
      case SDIO_INTERFACE_PHS:
      break;
      case SDIO_INTERFACE_WLAN:
         return 1;
      break;
      default:
      break;
   }   
   return 0;
}   
/*************************************************************************
* FUNCTION
*  SDIO_SW_reset
*
* DESCRIPTION
*	This function is to reset all I/O function
*
* PARAMETERS
*  None
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/ 
SDC_CMD_STATUS SDIO_SW_reset(void)
{
   cmd52_config_struct cmd52;
   SDC_CMD_STATUS status;
      
   /*use CMD52 to reset card*/	   
	cmd52.rw = SDIO_WRITE;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 6;
	cmd52.data = 0xff;
	status=SDIO_Cmd52(&cmd52);	   	
	return status; 
}   
/*************************************************************************
* FUNCTION
*  SDIO_abort_IO
*
* DESCRIPTION
*	This function is to abort function
*
* PARAMETERS
*  function:function id
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	
*************************************************************************/ 
SDC_CMD_STATUS SDIO_abort_IO(SDIO_function_id_enum function)
{   
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
   SDIO_dispatch_IO(SDIO_FUCN_0);
	cmd52.rw = SDIO_WRITE;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 6;
	cmd52.data = function&0x7;						
	status = SDIO_Cmd52(&cmd52);  			   	   		
	SDIO_resume_IO(SDIO_FUCN_0); 
	return status;
}
/*Function for WiFi */
/*************************************************************************
* FUNCTION
*  SDIO_Register_Write
*
* DESCRIPTION
*	This function is to write register
*
* PARAMETERS
*  function:function id
*  addr: address
*  data: write data
*  op: fixed or incrementing address
* RETURNS
*  success or not
*
* GLOBALS AFFECTED
*	
*************************************************************************/ 
/*Write Register*/
kal_bool SDIO_Register_Write(SDIO_function_id_enum function, 
                             kal_uint32 addr, 
                             kal_uint32 data,
                             cmd53_op_enum op)
{

	kal_uint32 tmp = data;
   cmd53_config_struct cmd53;
   
   SDIO_dispatch_IO(function);
	sdio_uncachedU32 = data;
	cmd53.rw = SDIO_WRITE;
	cmd53.func = function;
	cmd53.block = KAL_FALSE;
	cmd53.buffer = (kal_uint32)&sdio_uncachedU32;
	cmd53.count = 4;
	cmd53.op = op; 
	cmd53.adrs = (kal_uint32)addr;
	if((SDIO_Cmd53(&cmd53)!=NO_ERROR))
	{
	   SDIO_resume_IO(function);
	   return KAL_FALSE;   	   
	}   
	else   
	{
	   SDIO_resume_IO(function);
	   return KAL_TRUE;   	      
	}   	   
}                                                         
kal_bool SDIO_Register_Write_isr(SDIO_function_id_enum function, 
                                 kal_uint32 addr, 
                                 kal_uint32 data,
                                 cmd53_op_enum op)
{

	kal_uint32 tmp = data;
        cmd53_config_struct cmd53;
      
	cmd53.rw = SDIO_WRITE;
	cmd53.func = function;
	cmd53.block = KAL_FALSE;
	cmd53.buffer = (kal_uint32)&tmp;
	cmd53.count = 4;
	cmd53.op = op; 
	cmd53.adrs = (kal_uint32)addr;
	if((SDIO_Cmd53_isr(&cmd53)!=NO_ERROR))
	{	   
	   return KAL_FALSE;   	   
	}   
	else   
	{
	   return KAL_TRUE;   	      
	}   	   
}                                                         
/*Write Data */   
/*************************************************************************
* FUNCTION
*  SDIO_Data_Write
*
* DESCRIPTION
*	This function is to write memory
*
* PARAMETERS
*  function:function id
*  addr: address
*  data: write data
*  op: fixed or incrementing address
*  count: transfer count
*  block: block/byte mode 
*
* RETURNS
*  success or not
*
* GLOBALS AFFECTED
*	
*************************************************************************/                           
kal_bool SDIO_Data_Write(SDIO_function_id_enum function, 
                             kal_uint32 addr, 
                             kal_uint8  *data,
                             cmd53_op_enum op,
                             kal_uint32 count,
                             kal_bool block)
{
   cmd53_config_struct cmd53;
   //kal_uint32 size, i;
   //kal_uint32 sdio_buffer[256];
   
   SDIO_dispatch_IO(function);
   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif 
 	cmd53.rw = SDIO_WRITE;
	cmd53.func = function;
	cmd53.block = block;
	cmd53.buffer = (kal_uint32)data;//(kal_uint32)&sdio_buffer[0];
	cmd53.count = count;
	cmd53.op = op; 
	cmd53.adrs = (kal_uint32)addr;
	if((SDIO_Cmd53(&cmd53)!=NO_ERROR))
	{
	   SDIO_resume_IO(function);
	   return KAL_FALSE;   	   
	}   
	else   
	{
	   SDIO_resume_IO(function);
	   return KAL_TRUE;   
	}   
}
/*************************************************************************
* FUNCTION
*  SDIO_Register_Read
*
* DESCRIPTION
*	This function is to Read register
*
* PARAMETERS
*  function:function id
*  addr: address
*  data: write data
*  op: fixed or incrementing address
*
* RETURNS
*  success or not
*
* GLOBALS AFFECTED
*	
*************************************************************************/                                                        
/*Read Register*/
kal_bool SDIO_Register_Read(SDIO_function_id_enum function, 
                             kal_uint32 addr, 
                             kal_uint32 *data,
                             cmd53_op_enum op)
{
   cmd53_config_struct cmd53;
   
   SDIO_dispatch_IO(function);
	cmd53.rw = SDIO_READ;
	cmd53.func = function;
	cmd53.block = KAL_FALSE;
	cmd53.buffer = (kal_uint32) &sdio_uncachedU32;
	cmd53.count = 4;
	cmd53.op = op;;
	cmd53.adrs = (kal_uint32)addr;
	if((SDIO_Cmd53(&cmd53)!=NO_ERROR))	
	{
	   SDIO_resume_IO(function);
	   return KAL_FALSE;   	   
	}   
	else   
	{
	   *data = sdio_uncachedU32  ;
	   SDIO_resume_IO(function);
	   return KAL_TRUE;   	      
	}   
}
/*************************************************************************
* FUNCTION
*  SDIO_Register_Read_poll
*
* DESCRIPTION
*	This function is to Read register by SDIO bus driver
*
* PARAMETERS
*  function:function id
*  addr: address
*  data: write data
*  op: fixed or incrementing address
*
* RETURNS
*  success or not
*
* GLOBALS AFFECTED
*	only for SDIO bus driver
*************************************************************************/
kal_bool SDIO_Register_Read_poll(SDIO_function_id_enum function, 
                             kal_uint32 addr, 
                             kal_uint32 *data,
                             cmd53_op_enum op)
{
   cmd53_config_struct cmd53;
   
	cmd53.rw = SDIO_READ;
	cmd53.func = function;
	cmd53.block = KAL_FALSE;
	cmd53.buffer = (kal_uint32)data;
	cmd53.count = 4;
	cmd53.op = op;;
	cmd53.adrs = (kal_uint32)addr;
	if((SDIO_Cmd53_isr(&cmd53)!=NO_ERROR))	
	{
	   return KAL_FALSE;   	   
	}   
	else   
	{
	   return KAL_TRUE;   	      
	}   
}
/*************************************************************************
* FUNCTION
*  SDIO_Data_Read
*
* DESCRIPTION
*	This function is to read memory
*
* PARAMETERS
*  function:function id
*  addr: address
*  data: write data
*  op: fixed or incrementing address
*  count: transfer count
*  block: block/byte mode 
*
* RETURNS
*  success or not
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool SDIO_Data_Read(SDIO_function_id_enum function, 
                             kal_uint32 addr, 
                             kal_uint8  *data,
                             cmd53_op_enum op,
                             kal_uint32 count,
                             kal_bool block)
{
   cmd53_config_struct cmd53;
   SDIO_dispatch_IO(function);
   cmd53.rw = SDIO_READ;
	cmd53.func = function;
	cmd53.block = block;
	cmd53.buffer = (kal_uint32)data;
	cmd53.count = count;
	cmd53.op = op;
	cmd53.adrs = (kal_uint32)addr;
	if((SDIO_Cmd53(&cmd53)!=NO_ERROR))
	{
	   SDIO_resume_IO(function);
	   return KAL_FALSE;   	   
	}   
	else   
	{
	   SDIO_resume_IO(function);
	   return KAL_TRUE;   	  	   
	}      
}                                
   
void SDIO_get_CCCR(kal_uint8 *buf, kal_uint32 bufLen)
{
	if(bufLen < SDIO_CCCR_SIZE)
		ASSERT(0);
	if(NULL == buf)
		ASSERT(0);

	kal_mem_cpy(buf, sdio_cccr_reg, SDIO_CCCR_SIZE);
}      

void SDIO_get_FBR(kal_uint8 *buf, kal_uint32 bufLen)
{
	if(bufLen < SDIO_FBR_SIZE)
		ASSERT(0);
	if(NULL == buf)
		ASSERT(0);

	kal_mem_cpy(buf, sdio_fbr_reg, SDIO_FBR_SIZE);
}                                
   
/*not support in MT6228 and MT6229*/
#ifdef __SDIO_SRW_SRW__
/*************************************************************************
* FUNCTION
*  SDIO_suspend_IO
*
* DESCRIPTION
*	This function is to suspend function
*
* PARAMETERS
*  bus_status: bus status
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
*************************************************************************/
SDC_CMD_STATUS SDIO_suspend_IO(SDIO_bus_status_enum *bus_status)
{
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
	cmd52.rw = SDIO_WRITE;
	cmd52.func = 0;
	cmd52.raw = KAL_TRUE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 0xc;
	cmd52.data = 1;						
	if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	   return status;	   	
	*bus_status=(cmd52.data&0x2)>>1;
			   	   		
	return NO_ERROR;      
}   

/*************************************************************************
* FUNCTION
*  SDIO_select_IO
*
* DESCRIPTION
*	This function is to resume function
*
* PARAMETERS
*  bus_status: bus status
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
*************************************************************************/
SDC_CMD_STATUS SDIO_select_IO(SDIO_function_id_enum function, kal_bool *resume_data)
{
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
	cmd52.rw = SDIO_WRITE;
	cmd52.func = 0;
	cmd52.raw = KAL_TRUE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 0xd;
	cmd52.data = function&0xf;						
	if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	   return status;	   	
	*resume_data=(cmd52.data&0x80)>>7;
			   	   		
	return NO_ERROR;         
}
/*************************************************************************
* FUNCTION
*  SDIO_check_IO_exec
*
* DESCRIPTION
*	This function is to check function execution status
*
* PARAMETERS
*  execute_status: execute status
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
*************************************************************************/   
SDC_CMD_STATUS SDIO_check_IO_exec(SDIO_function_id_enum function, kal_bool *execution)
{
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
	cmd52.rw = SDIO_READ;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 0xe;
	if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	   return status;	   			
	if(function!=SDIO_FUCN_MEM)		 
	   *execution=(cmd52.data&(1<<function))>>function ;									   	   		
	else
	   *execution=cmd52.data&0x1;									   	   		
	   
	return NO_ERROR;         
}
/*************************************************************************
* FUNCTION
*  SDIO_check_IO_ready_flag
*
* DESCRIPTION
*	This function is to check function execution status
*
* PARAMETERS
*  bus_status: bus status
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
*************************************************************************/
SDC_CMD_STATUS SDIO_check_IO_ready_flag(SDIO_function_id_enum function, kal_bool *ready)
{
   SDC_CMD_STATUS status;
   cmd52_config_struct cmd52;
   
	cmd52.rw = SDIO_READ;
	cmd52.func = 0;
	cmd52.raw = KAL_FALSE;
	cmd52.stop = KAL_FALSE;
	cmd52.adrs = 0xf;
	if((status = SDIO_Cmd52(&cmd52))!=NO_ERROR)
	   return status;	   			
	if(function!=SDIO_FUCN_MEM)		 
	   *ready=(cmd52.data&(1<<function))>>function ;									   	   		
	else
	   *ready=cmd52.data&0x1;									   	   		
	   
	return NO_ERROR;         
}
#endif

#ifdef DRV_MSDC_HW_CONTENTION
extern kal_semid dclMsdcArb;
#endif



/*here is the interface for device driver, since SDIO should share the same HW resouce with SD card*/
SDC_CMD_STATUS SDIO_Initialize_al()
{
	kal_uint32 retAddr;
	SDC_CMD_STATUS status;

#if defined(__RVCT__)
        /* RVCT doesn't support inline assemlber; bypass temporarily */
        retAddr = 0;
#else   /* __RVCT__ */
        /* get the return address */
        __asm {
            MOV retAddr,lr
        }
#endif  /* __RVCT__ */
	
#ifdef DRV_MSDC_HW_CONTENTION
	if(NULL == dclMsdcArb)
		ASSERT(0);
	if(kal_query_systemInit()== KAL_FALSE){
		/*must gain resource here */
		kal_take_sem(dclMsdcArb, 1);
		SD_setArbRetAddr(retAddr);
		SD_setArbThdId((kal_uint32)kal_get_current_thread_ID());
	}
#endif

	/*switch related control*/
#ifdef DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH
	MSDC_backupHwSetting();
	MSDC_Switch_SDIO(SD_SDIO);
#endif
	drv_trace0(TRACE_GROUP_9, MSDC_SDIO_API_INIT);

	 status = SDIO_Initialize();

	drv_trace1(TRACE_GROUP_9, MSDC_SDIO_API_INIT_END, status);

	/*release arbitor*/
#ifdef DRV_MSDC_HW_CONTENTION
	if(KAL_FALSE == kal_query_systemInit()){
		/*when the semaphore is returned, we set thdId to zero, but not retAddr, we can know that it is released from here*/
		SD_setArbThdId(NULL);		
		kal_give_sem(dclMsdcArb);
	}
#endif

	return status;
}

SDC_CMD_STATUS SDIO_configure_BLK_size_al(SDIO_function_id_enum function, kal_uint32 size)
{
	SDC_CMD_STATUS status;
	kal_uint32 retAddr;

#if defined(__RVCT__)
        /* RVCT doesn't support inline assemlber; bypass temporarily */
        retAddr = 0;
#else   /* __RVCT__ */
        /* get the return address */
        __asm {
            MOV retAddr,lr
        }
#endif  /* __RVCT__ */
	
#ifdef DRV_MSDC_HW_CONTENTION
	if(NULL == dclMsdcArb)
		ASSERT(0);
	if(kal_query_systemInit()== KAL_FALSE){
		/*must gain resource here */
		kal_take_sem(dclMsdcArb, 1);
		SD_setArbRetAddr(retAddr);
		SD_setArbThdId((kal_uint32)kal_get_current_thread_ID());
	}
#endif

	/*switch related control*/
#ifdef DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH
	MSDC_backupHwSetting();
	MSDC_Switch_SDIO(SD_SDIO);
#endif

	/*do original job*/
	status = SDIO_configure_BLK_size(function, size);

	drv_trace4(TRACE_GROUP_9, MSDC_SDIO_API_SET_BLK_SIZE, function, size, status, 0);

	/*release arbitor*/
#ifdef DRV_MSDC_HW_CONTENTION
	if(KAL_FALSE == kal_query_systemInit()){
		/*when the semaphore is returned, we set thdId to zero, but not retAddr, we can know that it is released from here*/
		SD_setArbThdId(NULL);		
		kal_give_sem(dclMsdcArb);
	}
#endif

	return status;
}

SDC_CMD_STATUS SDIO_Cmd52_al(cmd52_config_struct *p)
{
	SDC_CMD_STATUS status;
	kal_uint32 retAddr;

#if defined(__RVCT__)
        /* RVCT doesn't support inline assemlber; bypass temporarily */
        retAddr = 0;
#else   /* __RVCT__ */
        /* get the return address */
        __asm {
            MOV retAddr,lr
        }
#endif  /* __RVCT__ */
	
#ifdef DRV_MSDC_HW_CONTENTION
	if(NULL == dclMsdcArb)
		ASSERT(0);
	if(kal_query_systemInit()== KAL_FALSE){
		/*must gain resource here */
		kal_take_sem(dclMsdcArb, 1);
		SD_setArbRetAddr(retAddr);
		SD_setArbThdId((kal_uint32)kal_get_current_thread_ID());
	}
#endif

	/*switch related control*/
#ifdef DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH
	MSDC_backupHwSetting();
	MSDC_Switch_SDIO(SD_SDIO);
#endif

	drv_trace8(TRACE_GROUP_9, MSDC_SDIO_API_CMD52, p->rw, p->func, p->raw, p->stop, p->data, p->adrs,
		0, MSDC_Reg32(MSDC_CFG));

	status = SDIO_Cmd52(p);

	drv_trace2(TRACE_GROUP_9, MSDC_SDIO_API_CMD52_END, status, MSDC_Reg32(SDC_RESP0));
	/*release arbitor*/
#ifdef DRV_MSDC_HW_CONTENTION
	if(KAL_FALSE == kal_query_systemInit()){
		/*when the semaphore is returned, we set thdId to zero, but not retAddr, we can know that it is released from here*/
		SD_setArbThdId(NULL);		
		kal_give_sem(dclMsdcArb);
	}
#endif

	return status;
}

kal_bool SDIO_Data_Read_al
(
	SDIO_function_id_enum function, 
	kal_uint32 addr, 
	kal_uint8  *data,
	cmd53_op_enum op,
	kal_uint32 count,
	kal_bool block
)
{
	kal_bool status;
	kal_uint32 retAddr;
	kal_uint32 time1, time2;

#if defined(__RVCT__)
        /* RVCT doesn't support inline assemlber; bypass temporarily */
        retAddr = 0;
#else   /* __RVCT__ */
        /* get the return address */
        __asm {
            MOV retAddr,lr
        }
#endif  /* __RVCT__ */
	
#ifdef DRV_MSDC_HW_CONTENTION
	if(NULL == dclMsdcArb)
		ASSERT(0);
	if(kal_query_systemInit()== KAL_FALSE){
		/*must gain resource here before calling ReadSectors*/
		kal_take_sem(dclMsdcArb, 1);
		SD_setArbRetAddr(retAddr);
		SD_setArbThdId((kal_uint32)kal_get_current_thread_ID());
	}
#endif

	/*switch related control*/
#ifdef DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH
	MSDC_backupHwSetting();
	MSDC_Switch_SDIO(SD_SDIO);
#endif

	drv_trace8(TRACE_GROUP_9, MSDC_SDIO_API_DREAD, function, addr, (kal_uint32)data, op, count, 
		block, 0, MSDC_Reg32(MSDC_CFG));

	time1 = drv_get_current_time();

	status = SDIO_Data_Read(function, addr, data, op, count, block);

	time2 = drv_get_current_time();
	drv_trace4(TRACE_GROUP_9, MSDC_SDIO_API_DREAD_END, status, (double)(count*32768)/(time2-time1), MSDC_Reg32(MSDC_IOCON), MSDC_Reg32(SDC_CFG));

	/*release arbitor*/
#ifdef DRV_MSDC_HW_CONTENTION
	if(KAL_FALSE == kal_query_systemInit()){
		/*when the semaphore is returned, we set thdId to zero, but not retAddr, we can know that it is released from here*/
		SD_setArbThdId(NULL);		
		kal_give_sem(dclMsdcArb);
	}
#endif

	return status;
}
#endif

#endif //DRV_MSDC_OFF
