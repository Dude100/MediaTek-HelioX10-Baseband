/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 * Filename:
 * ---------
 *   drv_rstctl.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * Barry Hong
 *
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * 	Change WDT IRQ period from 16T bus clock to 1T 32K
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * 	<saved by Perforce>
 *
 * removed!
 * removed!
 * 	Stop call while system calling wdt reset
 *
 * removed!
 * removed!
 * 	clear wdt status while init
 *
 * removed!
 * removed!
 * 	Add accessing Top RGU retention data API for test
 *
 * removed!
 * removed!
 * 	Add whole system reset function to PSD1
 *
 * removed!
 * removed!
 * Change enum type RST_LTEL2 to original RST_L2COP
 *
 * removed!
 * removed!
 * 	Modify get_duration macro
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * 	[MT6595] RGU code merge
 *
 * removed!
 * removed!
 * 	Change Watch dog timer to 4 sec and enable IRQ mode in phone type
 *
 * removed!
 * removed!
 * 	ext_rst_b set low active as phone type request
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * 	change ext_rst polarity as high active as workaround solution
 *
 * removed!
 * removed!
 * 	For phone type request
 *
 * removed!
 * removed!
 * 	Delete waring message
 *
 * removed!
 * Fix CR: MOLY00033807 ; Dont reset APCLK after WDT
 *
 * removed!
 * removed!
 * Fraom wei-de phone project request. set EXT_RST default to high active
 *
 * removed!
 * removed!
 * .remove APCLK reset when USB call WD reset
 *
 * removed!
 * removed!
 * .*: update for USB suspend IT test
 *
 * removed!
 * removed!
 * .update 6290 WDT driver
 *
 * removed!
 * removed!
 * .*:
 * 1.Add drv_rstctl_wd_clrCnt API to clear WD CNT
 * 2.Modify drv_rstctl_wd_rst_set_bitmap for U2 suspend wakeup not reset APCLK request
 *
 * removed!
 * removed!
 * .change g_ABNORMAL_RST_VAL define to WDT_RSTINTERVAL_VALUE
 *
 * removed!
 * removed!
 * .remove fakeAPI
 *
 * removed!
 * removed!
 * MT7208 rename to MT6290.
 *
 * removed!
 * removed!
 * .merge TATAKA driver to MOLY
 ****************************************************************************/

#include "drv_features_wdt.h"
#include "drv_comm.h"

#include "rstctl_reg.h"
#include "drv_rstctl.h"
#include "intrCtrl.h"

#include "dcl.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#if !defined(DRV_RSTCTL_OFF)
#if defined(MT6290)

/*****************************************************************************
 *						 SYMBOL Definition                                   *
 *****************************************************************************/


/*****************************************************************************
 *						 Global/External Variable                            *
 *****************************************************************************/
const kal_uint32 g_WATCHDOG_RESTART_REG   = REG_MDRSTCTL_WDTRR;
const kal_uint32 g_WATCHDOG_RESTART_VALUE = RSTCTL_WDTRR_KEY;
const kal_uint32 g_ABNORMAL_RST_REG       = REG_MDRSTCTL_WDTIR;
const kal_uint32 g_ABNORMAL_RST_VAL		  = WDT_RSTINTERVAL_VALUE;


/*****************************************************************************
 *						 function declaration                                *
 *****************************************************************************/
//function declaration.



/*****************************************************************************
 *						 LISR/HISR/Callback Functions                        *
 *****************************************************************************/



/*****************************************************************************
 *						 Basic Driver Implementation						 *
 *****************************************************************************/

#define UT_DELAY_LOOP(n)                                                          \
do{                                                                               \
	volatile register kal_uint32 _delay_loop;                                     \
	for(_delay_loop = 0; _delay_loop < n; _delay_loop++) { ; }                    \
}while(0)

#define _RESET_ITEM_REGs(reg, item_r, waitLoopCnt)   do {    \
				DRV_WriteReg32(reg, 		   \
							 (item_r));\
				DRV_WriteReg32(REG_MDRSTCTL_SRCMR, RSTCTL_SRCMR_KEY_SWRST);\
				UT_DELAY_LOOP(waitLoopCnt);\
				DRV_WriteReg32(reg, 0);\
				DRV_WriteReg32(REG_MDRSTCTL_SRCMR, RSTCTL_SRCMR_KEY_SWRST);\
					} while(0)


void _rst_clrSwRstStatus(kal_uint32 reg, kal_uint32 statusMaskToClear)
{
	/* If status Mask == 0 -> clear ALL */
	statusMaskToClear = (statusMaskToClear)?statusMaskToClear:0xffffffff;
    DRV_WriteReg32(reg, statusMaskToClear);
}

void _rst_resetIP(kal_uint32 reg, kal_uint32 item_r, kal_uint32 waitLoopCnt)
{
	kal_uint32 rstStatus;
	kal_uint32 timeout_cnt=0;
	kal_uint32 sta_reg=0;

	/* Reset IP */
	_RESET_ITEM_REGs(reg, item_r,waitLoopCnt);

	/* Check the status and clear it */
	switch (reg)
	{
		case REG_MDRSTCTL_SRBER_MDON:
			sta_reg = (REG_MDRSTCTL_SRSTR_MDON);
			break;
		case REG_MDRSTCTL_SRBER_MDMCU:
			sta_reg = (REG_MDRSTCTL_SRSTR_MDMCU);
			break;
		case REG_MDRSTCTL_SRBER_MDINFRA:
			sta_reg = (REG_MDRSTCTL_SRSTR_MDINFRA);
			break;
		case REG_MDRSTCTL_SRBER_LTEL2:
			sta_reg = (REG_MDRSTCTL_SRSTR_LTEL2);
			break;
		case REG_MDRSTCTL_SRBER_MEMSYS:
			sta_reg = (REG_MDRSTCTL_SRSTR_MEMSYS);
			break;
		case REG_MDRSTCTL_SRBER_ARM7:
			sta_reg = (REG_MDRSTCTL_SRSTR_ARM7);
			break;
		case REG_MDRSTCTL_SRBER_APMCU:
			sta_reg = (REG_MDRSTCTL_SRSTR_APMCU);
			break;
		case REG_MDRSTCTL_SRBER_APPERI:
			sta_reg = (REG_MDRSTCTL_SRSTR_APPERI);
			break;
		case REG_MDRSTCTL_SRBER_SSUSB:
			sta_reg = (REG_MDRSTCTL_SRSTR_SSUSB);
			break;
		case REG_MDRSTCTL_SRBER_APON:
			sta_reg = (REG_MDRSTCTL_SRSTR_APON);
			break;
		default:
		    /*assert to avoid NULL pointer access*/
		    EXT_ASSERT(0, reg, item_r, waitLoopCnt);
			break;
	}

	rstStatus = (DRV_Reg32(sta_reg)&item_r);


	while((item_r != rstStatus) && timeout_cnt<10000)
	{
		rstStatus = DRV_Reg32(sta_reg);
		timeout_cnt++;
	};

	ASSERT(timeout_cnt<10000);
	ASSERT(item_r == rstStatus);

	_rst_clrSwRstStatus(sta_reg, item_r);

}


void _rst_enableWdt(kal_uint32 wdtEnable, kal_uint32 wdtInterval)
{
	if (wdtEnable)
    {
	    /* Set watchdog interval */
		DRV_WriteReg32(REG_MDRSTCTL_WDTIR,
		               ((RSTCTL_WDTIR_KEY)|
		               ((wdtInterval & RSTCTL_WDTIR_INTERVAL_MASK) << RSTCTL_WDTIR_INTERVAL_OFFSET)));

        /* Enable/disable watchdog */
        DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY) |((DRV_Reg32(REG_MDRSTCTL_WDTCR))|RSTCTL_WDTCR_WDT_EN));
	    DRV_WriteReg32(REG_MDRSTCTL_WDTRR,((RSTCTL_WDTRR_KEY)|0x1));

	} else
    {   /* Just simply set WDTCR for WDT disabling operation */
        DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY) |((DRV_Reg32(REG_MDRSTCTL_WDTCR))&(~RSTCTL_WDTCR_WDT_EN)));
    }
}

void _rst_clrWdStatus(kal_uint32 statusMaskToClear)
{
	/* If status Mask == 0 -> clear ALL */
	statusMaskToClear = (statusMaskToClear)?statusMaskToClear:0xffffffff;
    DRV_WriteReg32(REG_MDRSTCTL_WDTSR,(RSTCTL_WDTSR_KEY)|(statusMaskToClear & (RSTCTL_WDTSR_STATUS_MASK<<RSTCTL_WDTSR_STATUS_OFFSET)));
}

/**
*	@brief	Reset WDT related setting and variables
*/
static void _wdt_reinitWDT(void)
{
	_rst_enableWdt(0,	RSTCTL_WDTIR_INTERVAL_MASK); /* Disable WDT */	/* Let duration being maximum */

	_rst_clrWdStatus(0);				/* Clear ALL indication bits */
}

void _rst_setWdTarget(kal_uint32 targetMask)
{
//	switch (targetMask)
//	{
//		case RST_SDCTL:
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDON, DRV_Reg32(REG_MDRSTCTL_WDTER_MDON)|(1<<0));
//			break;
//		default:
//			break:
//	}
}
/**
 *	@brief	Procedure for software triggered reset process
 *	This procedure triggers software watchdog reset and wait for its completeness
 *    Note: It needs less than 1T(32k) (eaxtly 1T-2*bus clock period) to do reset after WDTSR changes
 */
void _rst_swWdReset(void)
{
	/* Always clear indication bits before reset */
	DRV_WriteReg32(REG_MDRSTCTL_WDTSR,(RSTCTL_WDTSR_KEY)|(RSTCTL_WDTSR_STATUS_MASK<<RSTCTL_WDTSR_STATUS_OFFSET));

    //set MDTER bit
    DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDON, 0x81FFFEFF);    //before 0816  0xBFFFFFFF
    DRV_WriteReg32(REG_MDRSTCTL_WDTER_ARM7, 0x00000007);
    DRV_WriteReg32(REG_MDRSTCTL_WDTER_LTEL2, 0x00000001);
    DRV_WriteReg32(REG_MDRSTCTL_WDTER_MEMSYS, 0x8000000F);  //before 0816 0x8000003F
    DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDINFRA, 0x80000003);
    DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDMCU, 0x800002DF);   //before 0816 0x800000FF
    //set APTER bit
    DRV_WriteReg32(REG_MDRSTCTL_WDTER_APON, DRV_Reg32(REG_MDRSTCTL_WDTER_APON)|0x003FFBFC);     //before 0816 0x8000000F
    DRV_WriteReg32(REG_MDRSTCTL_WDTER_SSUSB, 0x00000001);
    DRV_WriteReg32(REG_MDRSTCTL_WDTER_APPERI, 0x800DDFFF);  //for RSTCTL ver70 remove aptzctl
    DRV_WriteReg32(REG_MDRSTCTL_WDTER_APMCU, 0x80000007);

	/* Trigger watchdog reset immediately : We use software reset */
	DRV_WriteReg32(REG_MDRSTCTL_SRCMR_SWDT, RSTCTL_SRCMR_KEY_SWDT);
	DRV_Reg32(REG_MDRSTCTL_SRCMR_SWDT);	/* Read the value of RSTCTL_SRCMR back to make sure the previous write operation is done */
	while ((DRV_Reg32(REG_MDRSTCTL_WDTSR) & (RSTCTL_WDTSR_STATUS_MASK<<RSTCTL_WDTSR_STATUS_OFFSET)) == 0);

    /*If irq_en not set, just while(1) to wait reset happen */
    if(!(DRV_Reg32(REG_MDRSTCTL_WDTCR) & RSTCTL_WDTCR_WDT_IRQEN))
        while(1);
}

void _rst_restartWDT()
{
	/* Simply reload watchdog counter */
	DRV_WriteReg32(REG_MDRSTCTL_WDTRR, (RSTCTL_WDTRR_KEY|0x1));
}

void drv_rstctl_sw_wd_reset(kal_uint32 wdTarget)
{
	/* Disable WD and clear indicators*/
	_wdt_reinitWDT();

	/**< Step 2 : configure WDT register to start counting */
	_rst_setWdTarget(wdTarget);
	_rst_enableWdt(1, WDT_RSTINTERVAL_VALUE); /* Maximum interval to watchdog timeout */
	_rst_restartWDT();	/* Kick watchdog to prevent from timeout */
	_rst_swWdReset();	/* To trigger software watchdog reset */

	/* Disable WD and clear indicators*/
	_wdt_reinitWDT();
}

void drv_rstctl_wd_reset(wdt_irq_e irq_en, rst_target_e wdTarget, kal_uint32 wdtInterval)
{

	/* Disable WD and clear indicators*/
	//_wdt_reinitWDT();
	_rst_clrWdStatus(0);
    DRV_WriteReg32(REG_MDRSTCTL_WDTSR,(RSTCTL_WDTSR_KEY)|0x1F);

	/**< Step 2 : configure WDT register to start counting */
	if (wdTarget == RST_MDALL)
	{
		//set MDTER bit
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDON, 0x81FFFEFF);  	//before 0816  0xBFFFFFFF
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_ARM7, 0x00000007);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_LTEL2, 0x00000001);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MEMSYS, 0x8000000F);	//before 0816 0x8000003F
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDINFRA, 0x80000003);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDMCU, 0x800002DF);  	//before 0816 0x800000FF
		//set APTER bit
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APON, DRV_Reg32(REG_MDRSTCTL_WDTER_APON)|0x003FFBFC);		//before 0816 0x8000000F
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_SSUSB, 0x00000001);
			DRV_WriteReg32(REG_MDRSTCTL_WDTER_APPERI, 0x800DDFFF);	//for RSTCTL ver70 remove aptzctl
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APMCU, 0x80000007);
	}
	if (wdTarget == RST_MDALL_WO_USB)
	{
		//set MDTER bit
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDON, 0x81FFFEFF);  	//before 0816  0xBFFFFFFF
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_ARM7, 0x00000007);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_LTEL2, 0x00000001);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MEMSYS, 0x8000000F);	//before 0816 0x8000003F
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDINFRA, 0x80000003);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDMCU, 0x800002DF);  	//before 0816 0x800000FF
		//set APTER bit
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APON, 0xC3FFBF4);		//before 0816 0x8000000F
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APPERI, 0x800DDFDF);	//for RSTCTL ver70 remove aptzctl
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APMCU, 0x80000007);
	}
	else if (wdTarget == RST_APALL)
	{
		//set MDTER bit
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDON, 0x81FFFEFF); 		//before 0816 0xBFFFFFFF
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_ARM7, 0x00000007);
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_LTEL2, 0x00000001);
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_MEMSYS, 0x8000000F);	//before 0816 0x8000003F
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDINFRA, 0x80000003);
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDMCU, 0x800002DF);		//before 0816 0x800000FF

		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDON, 0x81FFFEFF); 		//before 0816 0xBFFFFFFF
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_ARM7, 0x00000007);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_LTEL2, 0x00000001);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MEMSYS, 0x8000000F);	//before 0816 0x8000003F
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDINFRA, 0x8000000F);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDMCU, 0x800000DF);		//before 0816 0x800000FF


		//set APTER bit
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_APON, DRV_Reg32(REG_MDRSTCTL_WDTER_APON)|0x003FFBFC);		//before 0816 0x8000000F
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_SSUSB, 0x00000001);
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_APPERI, 0x800DDFFF);	//for RSTCTL ver70 remove aptzctl
//			DRV_WriteReg32(REG_MDRSTCTL_WDTER_APMCU, 0x80000007);

		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APON, 0x0C3FFFFC); 	//before 0816 0x8000000F
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_SSUSB, 0x00000001);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APPERI, 0x800FFFFF);	//for RSTCTL ver70 remove aptzctl
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APMCU, 0x80000007);


	}
	else
	{
		_rst_setWdTarget(wdTarget);
	}

    if (irq_en == WDT_IRQ_ONLY)
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY)|(0x8));
	else
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY)|(DRV_Reg32(REG_MDRSTCTL_WDTCR)&0x8001));

	if (0 != wdtInterval)
	{
		_rst_enableWdt(1, wdtInterval); /* Maximum interval to watchdog timeout */
		//_rst_restartWDT();	/* Kick watchdog to prevent from timeout */ //already done in _rst_enableWdt
	}
	else
	{
		_rst_swWdReset();	/* To trigger software watchdog reset */
	}

	/* Disable WD and clear indicators*/
	//_wdt_reinitWDT();
}

void drv_rstctl_wd_rst_set_bitmap(kal_uint8 type)
{
	//if (cp15_get_cpu_id() == CPU_CORTEX_R4_ID)
	if (type == 0) //U3
	{
		//set MDTER bit
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDON, 0x81BFFEFF);		//before 0816 0xBFFFFFFF
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_ARM7, 0x00000007);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_LTEL2, 0x00000001);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MEMSYS, 0x8000000F);	//before 0816 0x8000003F
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDINFRA, 0x80000003);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDMCU, 0x800002DF);		//before 0816 0x800000FF

		//set APTER bit
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_SSUSB, 0x00000000);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APON, 0xC3FFBF4); 	//don't reset APCLK
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APPERI, 0x800DDFFF);	//for RSTCTL ver70 remove aptzctl include USB
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APMCU, 0x80000007);
	}
	else if (type == 1) //U2
    {
		//set MDTER bit
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDON, 0x81BFFEFF);		//before 0816 0xBFFFFFFF
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_ARM7, 0x00000007);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_LTEL2, 0x00000001);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MEMSYS, 0x8000000F);	//before 0816 0x8000003F
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDINFRA, 0x80000003);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_MDMCU, 0x800002DF);		//before 0816 0x800000FF

		//set APTER bit
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_SSUSB, 0x00000001);
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APON, 0xC3FFBF4);     //don't reset APCLK
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APPERI, 0x800DDFDF);	//for RSTCTL ver70 remove aptzctl
		DRV_WriteReg32(REG_MDRSTCTL_WDTER_APMCU, 0x80000007);
	}
	else
	{
    }
}


void drv_rstctl_sw_reset(rst_target_e targetIP)
{
	kal_uint32 timeout_cnt=0;  //for RST_MEMORY only

	switch (targetIP)
	{
		/* Only valid for MDARM */
		case RST_SDCTL:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_SDCTL_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDGDMA:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_MDGDMA_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_USIM0:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_USIM0_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_USIM1:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_USIM1_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDUART:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_MDUART_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_SUART0:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_SUART0_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_SUART1:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_SUART1_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDGPTM:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_MDGPTM_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDMISC:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_MDMISC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDCIRQ:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_MDCIRQ_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_LED:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_LED_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_I2C:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_I2C_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_SDCTL_CIS:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_SDCTL_CIS_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_DBGSYS:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_DBGSYS_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_DBGCV:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_DBGCV_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_DBGSIB:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_DBGSIB_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_GPIOMUX:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_GPIOMUX_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APTOPSM:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_APTOPSM_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDTOPSM:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_MDTOPSM_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APOST:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_APOST_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDOST:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_MDOST_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDCFGCTL:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_MDCFGCTL_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_DRAMC_AO:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_DRAMC_AO_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_EMI_AO:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, RSTCTL_SRBER_EMI_AO_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_ARM7_HRST:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_ARM7, RSTCTL_SRBER_ARM7_HRST_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_ARM7_SRST:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_ARM7, RSTCTL_SRBER_ARM7_SRST_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CAIF:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_ARM7, RSTCTL_SRBER_CAIF_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_ARM7SYS:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_ARM7, RSTCTL_SRBER_ARM7SYS_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_L2COP:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_LTEL2, RSTCTL_SRBER_LTEL2_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MEMSYS:
			{
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MEMSYS, (RSTCTL_SRBER_DRAMC_RST|RSTCTL_SRBER_EMI_RST|RSTCTL_SRBER_CPHY_RST|RSTCTL_SRBER_DDRPHY_COMB0_RST));
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDON, (RSTCTL_SRBER_DRAMC_AO_RST|RSTCTL_SRBER_EMI_AO_RST));
			DRV_WriteReg32(REG_MDRSTCTL_SRCMR, RSTCTL_SRCMR_KEY_SWRST);
			UT_DELAY_LOOP(_RST_DURATION_LOOP_DEFAULT_VALUE);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MEMSYS, 0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDON, 0);
			DRV_WriteReg32(REG_MDRSTCTL_SRCMR, RSTCTL_SRCMR_KEY_SWRST);

			while((((RSTCTL_SRBER_DRAMC_RST|RSTCTL_SRBER_EMI_RST|RSTCTL_SRBER_CPHY_RST|RSTCTL_SRBER_DDRPHY_COMB0_RST) != DRV_Reg32(REG_MDRSTCTL_SRSTR_MEMSYS))||\
			        ((RSTCTL_SRBER_DRAMC_AO_RST|RSTCTL_SRBER_EMI_AO_RST) != DRV_Reg32(REG_MDRSTCTL_SRSTR_MDON))) && timeout_cnt<10000)
			{
				timeout_cnt++;
			};

			ASSERT(((RSTCTL_SRBER_DRAMC_RST|RSTCTL_SRBER_EMI_RST|RSTCTL_SRBER_CPHY_RST|RSTCTL_SRBER_DDRPHY_COMB0_RST) == DRV_Reg32(REG_MDRSTCTL_SRSTR_MEMSYS))&&\
			        ((RSTCTL_SRBER_DRAMC_AO_RST|RSTCTL_SRBER_EMI_AO_RST) == DRV_Reg32(REG_MDRSTCTL_SRSTR_MDON)));

			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_MEMSYS, (RSTCTL_SRBER_DRAMC_RST|RSTCTL_SRBER_EMI_RST|RSTCTL_SRBER_CPHY_RST|RSTCTL_SRBER_DDRPHY_COMB0_RST));
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_MDON, (RSTCTL_SRBER_DRAMC_AO_RST|RSTCTL_SRBER_EMI_AO_RST));

/*
			_rst_resetIP(REG_MDRSTCTL_SRBER_MEMSYS, (RSTCTL_SRBER_DRAMC_RST|RSTCTL_SRBER_EMI_RST|RSTCTL_SRBER_CPHY_RST|\
			  RSTCTL_SRBER_DDRPHY_COMB0_RST), _RST_DURATION_LOOP_DEFAULT_VALUE);
			_rst_resetIP(REG_MDRSTCTL_SRBER_MDON, (RSTCTL_SRBER_DRAMC_AO_RST|RSTCTL_SRBER_EMI_AO_RST), _RST_DURATION_LOOP_DEFAULT_VALUE);
*/
			  break;}
		case RST_MDINFRA_MISC:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDINFRA, RSTCTL_SRBER_MDINFRA_MISC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDINFRA_BUSMON:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDINFRA, RSTCTL_SRBER_MDINFRA_BUSMON_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_ABM:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDINFRA, RSTCTL_SRBER_ABM_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CR4:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDMCU, RSTCTL_SRBER_CR4_DBG_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CR4_NRESET:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDMCU, RSTCTL_SRBER_CR4_NRESET_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CR4_BUSMON:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDMCU, RSTCTL_SRBER_CR4_BUSMON_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_ALC:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDMCU, RSTCTL_SRBER_ALC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PF:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDMCU, RSTCTL_SRBER_PF_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PCMON_FIFO:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDMCU, RSTCTL_SRBER_PCMON_FIFO_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PCMON_REG:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_MDMCU, RSTCTL_SRBER_PCMON_REG_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_AP_RSTMD:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_AP_RSTMD_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDCLK:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_MDCLK_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APCLK:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_APCLK_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_EFUSE:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_EFUSE_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MML1:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, (RSTCTL_SRBER_MML1_RST|RSTCTL_SRBER_MML1OFF_RST), _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MML1OFF:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_MML1OFF_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_TDD:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_TDD_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_2G3G:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_2G3G_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_2G3G_DSP:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_2G3G_DSP_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_EXT_RST:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_EXT_RST_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_BSICTL:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_BSICTL, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_RFIC1_BSISPI:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_RFIC1_BSISPI, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_RFIC2_BSISPI:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_RFIC2_BSISPI, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PMIC_BSISPI:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_PMIC_BSISPI, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MIPI0_BSISPI:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_MIPI0_BSISPI, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MIPI1_BSISPI:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_MIPI1_BSISPI, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_IDC:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_IDC, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MML1_BPICTRL:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_MML1_BPICTRL, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MML1_PERISYS_MISC:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_MML1_PERISYS_MISC, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MML1_PERI_MBIST_CONFIG:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_MML1_PERI_MBIST_CONFIG, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_AUXADC:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_AUXADC, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MML1_PERISYS_XRESET:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_MML1_PERISYS_XRESET, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MIXEDSYS:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_MIXEDSYS, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_SSUSB:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_SSUSB, RSTCTL_SRBER_SSUSB_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APUART:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_APUART_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APCCIF:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_APCCIF_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CLDMA:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_CLDMA_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_NFI:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_NFI_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_SPI:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_SF_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_USB:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_USB_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_IPSEC:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_IPSEC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_HIF0:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_HIF0_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_PFC:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_PFC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_NLI:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_NLI_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MSDC0P:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_MSDC0P_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MSDC1P:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_MSDC1P_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APGPTM:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_APGPTM_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APGDMA:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_APGDMA_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_APINFRA_BUSMON:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_AP_BUSMON_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_AP_MISC:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_AP_MISC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_ETHER_NIC:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_ETHER_NIC_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_TRACE:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APPERI, RSTCTL_SRBER_TRACE_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CA7_DBG:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APMCU, RSTCTL_SRBER_CA7_DBG_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CA7_NRESET:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APMCU, RSTCTL_SRBER_CA7_NRESET_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_CA7_BUSMON:
			{_rst_resetIP(REG_MDRSTCTL_SRBER_APMCU, RSTCTL_SRBER_CA7_BUSMON_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);break;}
		case RST_MDALL:
			//set MDTER bit
//			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDON, 0x003DF69F); //don't reset LED/GPIO/SUART0/SUART1 when AP reset MD
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDON, 0x0029F69F); //don't reset LED/GPIO/SUART0/SUART1/APTOPSM/APOST when AP reset MD
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_ARM7, 0x00000007);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_LTEL2, 0x00000001);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDINFRA, 0x0000000B);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDMCU, 0x000000DF);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_SSUSB, 0x00000001);  //reset U3 when AP reset MD
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_APPERI, 0x00080130);  //reset trace,PFC,U2 and SPI when AP reset MD
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_APON, 0x000003E0);  //reset LTEPHY,TDD,2G3G,2G3GDSP when AP reset MD
			_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_AP_RSTMD_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDON, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_ARM7, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_LTEL2, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDINFRA, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDMCU, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_SSUSB, 0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_APPERI, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_APON, 0x0);
			_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_AP_RSTMD_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_MDON, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_ARM7, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_LTEL2, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_MDINFRA, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_MDMCU, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_SSUSB, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_APPERI, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_APON, 0);
			break;
		case RST_MDALL_WO_SPI:
			//set MDTER bit
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDON, 0x0029F69F);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_ARM7, 0x00000007);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_LTEL2, 0x00000001);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDINFRA, 0x0000000B);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDMCU, 0x000000DF);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_SSUSB, 0x00000001);  //reset U3 when AP reset MD
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_APPERI, 0x00080120);  //reset trace,PFC and U2 when AP reset MD
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_APON, 0x000003E0);  //reset LTEPHY,TDD,2G3G,2G3GDSP when AP reset MD
			_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_AP_RSTMD_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDON, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_ARM7, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_LTEL2, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDINFRA, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_MDMCU, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_SSUSB, 0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_APPERI, 0x0);
			DRV_WriteReg32(REG_MDRSTCTL_SRBER_APON, 0x0);
			_rst_resetIP(REG_MDRSTCTL_SRBER_APON, RSTCTL_SRBER_AP_RSTMD_RST, _RST_DURATION_LOOP_DEFAULT_VALUE);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_MDON, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_ARM7, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_LTEL2, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_MDINFRA, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_MDMCU, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_SSUSB, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_APPERI, 0);
			_rst_clrSwRstStatus(REG_MDRSTCTL_SRSTR_APON, 0);
            break;
		default:
			ASSERT(0);
	}
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_getSta
*
* DESCRIPTION
*  This function is used to get wdt status
*
* PARAMETERS
*	none
*
* RETURN VALUES
*  bit[15:12]:AP WDT CNT : AP wd reset increase one. can be reset by disable WDT
*  bit[11:8]:MD WDT CNT : MD wd reset increase one. can be reset by disable WDT
*  bit[4]:AP reset MD indicator
*  bit[3]:AP sw WD reset indicator
*  bit[2]:AP hw WD reset indicator
*  bit[1]:MD sw WD reset indicator
*  bit[0]:MD hw WD reset indicator
*************************************************************************/
void drv_rstctl_wd_disable(void)
{
	_rst_enableWdt(0,	RSTCTL_WDTIR_INTERVAL_MASK);
}

kal_uint32 drv_rstctl_wd_getSta(void)
{
	kal_uint32 wdt_sta;
	wdt_sta = DRV_Reg32(REG_MDRSTCTL_WDTSR);
	//_rst_clrWdStatus(0);
	return wdt_sta;
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrCnt
*
* DESCRIPTION
*  This function is used to clear wdt cnt
*
* PARAMETERS
*	cntMaskToClear
*   0: clear both AP/MD WD Cnt
*   MD_WDCNT_CLR: clear MD WD Cnt
*   AP_WDCNT_CLR: clear AP WD Cnt
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_clrCnt(kal_uint32 cntMaskToClear)
{
	/* If cnt Mask == 0 -> clear ALL */
	cntMaskToClear = (cntMaskToClear)?cntMaskToClear:0x3;
    DRV_WriteReg32(REG_MDRSTCTL_WDTSR,(RSTCTL_WDTSR_KEY)|((cntMaskToClear & RSTCTL_WDTSR_CNT_CLR_MASK)<<RSTCTL_WDTSR_CNT_CLR_OFFSET));
}


/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrSta
*
* DESCRIPTION
*  This function is used to clear wdt status
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_clrSta(void)
{
	_rst_clrWdStatus(0);
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_extrst_setCfg
*
* DESCRIPTION
*  This function is used to config EXT_RST
*
* PARAMETERS
*	rstctl_ext_cfg_t ext_cfg
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_extrst_setCfg(rstctl_ext_cfg_t ext_cfg)
{
	DRV_WriteReg32(REG_MDRSTCTL_WDTER_APON, (DRV_Reg32(REG_MDRSTCTL_WDTER_APON) & 0xFFFFFBFF)|(ext_cfg.EXT_RST_EA <<10)); //enable/disable EXT_RST
	DRV_WriteReg32(REG_MDRSTCTL_EXTRST, (DRV_Reg32(REG_MDRSTCTL_EXTRST)|RSTCTL_EXTRST_KEY)); 								//clear status
	DRV_WriteReg32(REG_MDRSTCTL_EXTRST, ((DRV_Reg32(REG_MDRSTCTL_EXTRST) & 0xFFFFFFFC)|RSTCTL_EXTRST_KEY|(ext_cfg.MD_POL << 0)|(ext_cfg.PAD_OUT_EA << 1)));	//set POL and OE
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_extrst_getSta
*
* DESCRIPTION
*  This function is used to get EXT_RST status
*
* PARAMETERS
*	1: ext rst assert
*	0: ext rst de-assert
* RETURN VALUES
*	none
*************************************************************************/
kal_bool drv_rstctl_extrst_getSta(void)
{
	if (DRV_Reg32(REG_MDRSTCTL_EXTRST) & (1<<15))
	{
		DRV_WriteReg32(REG_MDRSTCTL_EXTRST, (DRV_Reg32(REG_MDRSTCTL_EXTRST)|RSTCTL_EXTRST_KEY));		//clear status
		return KAL_TRUE;
	}
	else
	{
		DRV_WriteReg32(REG_MDRSTCTL_EXTRST, (DRV_Reg32(REG_MDRSTCTL_EXTRST)|RSTCTL_EXTRST_KEY));		//clear status
		return KAL_FALSE;
	}
}


kal_uint16 drv_rstctl_wd_getInterval(void)
{
	return (kal_uint16)(0xFFFF & DRV_Reg32(REG_MDRSTCTL_WDTIR));
}

void drv_rstctl_restartWDT(void)
{
	_rst_restartWDT();
}

void drv_rstctl_wdt_setInterval(kal_uint32 wdtInterval)
{
	/* Set watchdog interval */
	DRV_WriteReg32(REG_MDRSTCTL_WDTIR,
				   ((RSTCTL_WDTIR_KEY)|
				   ((wdtInterval & RSTCTL_WDTIR_INTERVAL_MASK) << RSTCTL_WDTIR_INTERVAL_OFFSET)));
}

void drv_rstctl_wdt_enable(kal_bool en)
{
	if (en == KAL_TRUE)
	{
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY) |((DRV_Reg32(REG_MDRSTCTL_WDTCR))|RSTCTL_WDTCR_WDT_EN));
		/*Reload wdt interval*/
		DRV_WriteReg32(REG_MDRSTCTL_WDTRR,((RSTCTL_WDTRR_KEY)|0x1));
	}
	else
	{
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY) |((DRV_Reg32(REG_MDRSTCTL_WDTCR))&(~RSTCTL_WDTCR_WDT_EN)));
	}
}

void drv_rstctl_wdt_abnReset(void)
{
	SaveAndSetIRQMask();
	drv_rstctl_wdt_setInterval(1);
	_rst_restartWDT();
	drv_rstctl_wdt_enable(KAL_TRUE);
	while(1);
}

void drv_rstctl_wdt_enableInterrupt(kal_bool enable)
{
	if (enable == KAL_TRUE)
	{
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR,(RSTCTL_WDTCR_KEY)|((DRV_Reg32(REG_MDRSTCTL_WDTCR)) | RSTCTL_WDTCR_WDT_IRQEN));
	}
	else
	{
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR,(RSTCTL_WDTCR_KEY)|((DRV_Reg32(REG_MDRSTCTL_WDTCR)) & (~RSTCTL_WDTCR_WDT_IRQEN)));
	}
}


void drv_rstctl_wdt_enableDebugMode(kal_bool enable)
{
	if (enable==KAL_TRUE)
	{
		IRQUnmask(MD_IRQID_MD_WDT);
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY) | ((DRV_Reg32(REG_MDRSTCTL_WDTCR))| (RSTCTL_WDTCR_WDT_EN | RSTCTL_WDTCR_WDT_IRQEN)));
	}
	else
	{
		IRQMask(MD_IRQID_MD_WDT);
		DRV_WriteReg32(REG_MDRSTCTL_WDTCR, (RSTCTL_WDTCR_KEY) | ((DRV_Reg32(REG_MDRSTCTL_WDTCR)) & ~(RSTCTL_WDTCR_WDT_EN | RSTCTL_WDTCR_WDT_IRQEN)));
	}
}

/*
* FUNCTION
*	drv_rstctl_WdtConfig
*
* DESCRIPTION
*   	This function is to configure WDT only called in drv_rstctl_wdt_init
*
* CALLS
*
* PARAMETERS
*	extpol: KAL_TRUE, polarity = 1
*	        FASLE, polarity = 0
*	exten: KAL_TRUE, generate an external watchdog reset signal when couter=0
*	    KAL_FALSE, not generate an external watchdog reset signal when couter=0
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void drv_rstctl_WdtConfig(IO_level extpol, kal_bool exten)
{
    //	kal_uint32 tmp = DRV_Reg32(REG_MDRSTCTL_WDTCR);
    //	tmp |= (RSTCTL_WDTCR_KEY);
    //	tmp &= ~RSTCTL_WDTCR_WDT_EN;
    //	DRV_WriteReg32(REG_MDRSTCTL_WDTCR, tmp);

    /*
        MD WDTER APON[10] is the mux to choose this ext_rst pin controlled by AP setting (0) or MD setting (1)
        And It also controll the reset signal generating or not
      */
    if (exten == KAL_TRUE)
    {
        DRV_WriteReg32(REG_MDRSTCTL_EXTRST, RSTCTL_EXTRST_KEY|EXT_WDT_STS|EXTRST_OE|(extpol << POLARITY_OFFSET));
        DRV_WriteReg32(REG_MDRSTCTL_WDTER_APON, DRV_Reg32(REG_MDRSTCTL_WDTER_APON) | (1<<10));
    }
    else
    {
        DRV_WriteReg32(REG_MDRSTCTL_EXTRST, RSTCTL_EXTRST_KEY|EXT_WDT_STS);
        DRV_WriteReg32(REG_MDRSTCTL_WDTER_APON, DRV_Reg32(REG_MDRSTCTL_WDTER_APON) & ~(1<<10));
    }
}

/*
* FUNCTION
*	drv_rstctl_ext_rst_pin_init
*
* DESCRIPTION
*   	This function is to set ext_rst pin status
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*    None
*
* NOTE
*   In MT6290 phone type product, default is input pin and pull low
*   Because this pin also affects the sdio_int_pin and  it would always trigger sdio interrupt if in default state
*   so we need to set it as default high and low active
*/
void drv_rstctl_ext_rst_pin_init(void)
{
    drv_rstctl_WdtConfig(io_low, KAL_TRUE);
}

/*
* FUNCTION
*	drv_rstctl_wdt_init
*
* DESCRIPTION
*   	This function is to initialize the WDT module
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   None
*/
void drv_rstctl_wdt_init(void)
{
	//WDT_RST = (DRV_WDT_Reg(WDT_STATUS) & WDT_STATUS_BITMASK)?(KAL_TRUE):(KAL_FALSE);
#if !defined(ATEST_ENABLE)
	drv_rstctl_wd_clrSta();
#endif
	drv_rstctl_wdt_setInterval(WDT_RSTINTERVAL_VALUE);
	drv_rstctl_ext_rst_pin_init();

#if defined(DRV_WDT_IRQ_MODE)
	drv_rstctl_wdt_enableInterrupt(KAL_TRUE);
	//IRQSensitivity(MD_IRQID_MD_WDT, KAL_TRUE);
	//IRQUnmask(MD_IRQID_MD_WDT);
#endif
}

/*
* FUNCTION
*	WDT_init
*
* DESCRIPTION
*   	This function is to initialize the WDT module
*
* CALLS
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   None
*/
void WDT_init(void)
{
	drv_rstctl_wdt_init();
}

kal_uint32 Get_WATCHDOG_BASE()
{
	return REG_MDRSTCTL_WDTRR;
}
kal_uint32 Get_WATCHDOG_RESTART_CMD()
{
	return (RSTCTL_WDTRR_KEY | 0x1);
}

kal_bool Is_WDT_Init()// for ex_item.c
{
	if( DRV_Reg32(REG_MDRSTCTL_WDTIR) == WDT_RSTINTERVAL_VALUE )
		return KAL_TRUE;
	else
		return KAL_FALSE;
}



void drv_rstctl_wdt_reset(void)
{
#if defined(DRV_WDT_RESET_PKEY_RELEASE)
	kal_uint16 powerkey_status;

	#if defined(__USB_ENABLE__)

	DCL_BOOL dcl_data = DCL_TRUE;
	DCL_HANDLE	usb_dcl_handle;

	usb_dcl_handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);

	DclUSB_DRV_Control(usb_dcl_handle, USB_DRV_CMD_PDN_ENABLE, (DCL_CTRL_DATA_T  *)&dcl_data);
	DclUSB_DRV_Close(usb_dcl_handle);

	//	 USB_PDNmode(KAl_TRUE);

	#endif //#if defined(__USB_ENABLE__)

	#ifdef PMIC_PRESENT

	if (BMT.PWRon != CHRPWRON)
	{
		switch(Pwrkey_Position)
		{
			case low_key:
				powerkey_status= DRV_Reg32(KP_LOW_KEY);
				break;
		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
			case high_key:
				powerkey_status= DRV_Reg32(KP_HI_KEY);
				break;
			default:
				ASSERT(0);
				break;
		}
		if(WdtPowerKey_Pressed())
		{
			TargetReset = 1;
		}
		else
		{
			/*lint -e(534)*/SaveAndSetIRQMask();

			drv_rstctl_wdt_setInterval(1);
			_rst_restartWDT();
			drv_rstctl_wdt_enable(KAL_TRUE);
			while(1);
		}
	}
	else
	{
		/*lint -e(534)*/SaveAndSetIRQMask();

		drv_rstctl_wdt_setInterval(1);
		_rst_restartWDT();
		drv_rstctl_wdt_enable(KAL_TRUE);
		while(1);
	}
	#else /*PMIC_PRESENT*/
		  /*lint -e(534)*/SaveAndSetIRQMask();

		drv_rstctl_wdt_setInterval(1);
		_rst_restartWDT();
		drv_rstctl_wdt_enable(KAL_TRUE);
		while(1);
	#endif   /*PMIC_PRESENT*/
#else /*!DRV_WDT_RESET_PKEY_RELEASE*/

	kal_uint16 index;
#if defined(DRV_RTC_REG_COMM)
	DCL_HANDLE rtc_handler;
	RTC_CTRL_CONFIG_PDN_BIT_T rtc_cmd_data8;
#endif /*DRV_RTC_REG_COMM*/
	/*lint -e(534)*/SaveAndSetIRQMask();

	for(index=0;index<1000;index++);
#if defined(DRV_RTC_REG_COMM)
	//RTC_Set_PDN_bits(rtc_pdn2 ,DRV_COMM_REG2_NORMAL_RESET);
	rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
	rtc_cmd_data8.PDNIndex = DCL_RTC_PDN2;
	rtc_cmd_data8.fgConfigBit = DRV_COMM_REG2_NORMAL_RESET;
	DclRTC_Control(rtc_handler, RTC_CMD_SET_PDN_BITS, (DCL_CTRL_DATA_T *)&rtc_cmd_data8); // New API with CMD & DATA
#endif   /*DRV_RTC_REG_COMM*/
	#if !defined(DRV_WDT_SWRST)
	drv_rstctl_wdt_setInterval(1);
	_rst_restartWDT();
	drv_rstctl_wdt_enable(KAL_TRUE);
	while(1);
	#else
		#if defined(DRV_MISC_WDT_TURN_OFF_PLL)
	DRV_WriteReg32(0x80000108, 0);
		#endif // #if defined(DRV_MISC_WDT_TURN_OFF_PLL)
	_rst_swWdReset();	/* To trigger software watchdog reset */
	while(1);
	#endif
#endif   /*!DRV_WDT_RESET_PKEY_RELEASE*/

}

#elif defined(MT6595) || (defined(MT6752) && defined(__MD1__))

#define RST_USE_US_DELAY
#include "kal_debug.h"

/*****************************************************************************
 *						 SYMBOL Definition                                   *
 *****************************************************************************/

/*32K 1T=30.5us*/
#ifdef RST_USE_US_DELAY
#include "us_timer.h"
#define RSTCTL_DURATION_LOOP_DEFAULT_VALUE (31)
#define MY_UST_GET_DUR(prev, cur) (((cur) >= (prev))? (((cur) - (prev))): ((USCNT_WRAP - (prev) + (cur))))
#define UT_DELAY_LOOP(us)   \
        do {    \
            kal_uint32 t1, t2;         \
            if ((us) == 0) {    \
                break;  \
            }   \
            t1 = ust_get_current_time();    \
            do {    \
                t2 = ust_get_current_time();    \
                if (MY_UST_GET_DUR(t1, t2) >= (us)) { break; } \
            	else { continue; }   \
            } while (1);    \
        } while (0)
#else
#define RSTCTL_DURATION_LOOP_DEFAULT_VALUE (0x100)
#define UT_DELAY_LOOP(n)                                                          \
do{                                                                               \
	volatile register kal_uint32 _delay_loop;                                     \
	for(_delay_loop = 0; _delay_loop < n; _delay_loop++) { ; }                    \
}while(0)
#endif

#define TOP_RGU_MODE_ADDR   (TOPRGU_BASE+0x0)
#define TOP_RGU_SW_WDT_ADDR (TOPRGU_BASE+0x14)
#define TOP_RGU_RETAIN_ADDR (TOPRGU_BASE+0x20)

/*****************************************************************************
 *						 Global/External Variable                            *
 *****************************************************************************/
const kal_uint32 g_WATCHDOG_RESTART_REG   = REG_WDT_MD_RESTART;
const kal_uint32 g_WATCHDOG_RESTART_VALUE = RSTCTL_RESTART_TIMER_KEY;
const kal_uint32 g_ABNORMAL_RST_REG       = REG_WDT_MD_LENGTH;
const kal_uint32 g_ABNORMAL_RST_VAL		  = WDT_RSTINTERVAL_VALUE;


/*****************************************************************************
 *						 function declaration                                *
 *****************************************************************************/




/*****************************************************************************
 *						 LISR/HISR/Callback Functions                        *
 *****************************************************************************/



/*****************************************************************************
 *						 Basic Driver Implementation						 *
 *****************************************************************************/

/**
 *	@brief	Procedure for software triggered reset process
 *	This procedure triggers software watchdog reset and wait for its completeness
 */
static void _rst_swWdReset(void)
{
	drv_rstctl_sw_reset(RST_MD_SWRST);

	UT_DELAY_LOOP(RSTCTL_DURATION_LOOP_DEFAULT_VALUE);/*At lease one 32K clock period*/

    /*If irq_en not set, just while(1) to wait reset happen */
    if(!(DRV_Reg32(REG_WDT_MD_MODE) & (0x1 <<RSTCTL_IRQ_MODE_BIT)))
        while(1);
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_ws_wdReset
*
* DESCRIPTION
*  This function is used to control top rgu to make whole system reset
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_ws_wdReset(void)
{
    DRV_WriteReg32(TOP_RGU_MODE_ADDR, 0x22000000);
    DRV_WriteReg32(TOP_RGU_SW_WDT_ADDR, 0x1209);
    while(1);
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_top_retn_data
*
* DESCRIPTION
*  This function is used to read/write retention data
*
* PARAMETERS
*	bRead: 1: read data
*           0: write data
*    pData:
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_top_retn_data(kal_bool bRead, kal_uint32 *pData)
{
    if(pData == NULL)
        return;

    if(bRead == KAL_TRUE)
    {
        *pData =  DRV_Reg32(TOP_RGU_RETAIN_ADDR);
    }
    else
    {
        DRV_WriteReg32(TOP_RGU_RETAIN_ADDR, *pData);
    }

}

/*************************************************************************
* FUNCTION
*  drv_rstctl_A7_unlock
*
* DESCRIPTION
*  This function is used to unlock ARM7 hrst
*
* PARAMETERS
*	lock:   RST_A7_LOCK:
*            RST_A7_UNLOCK:
*
* RETURN VALUES
*	none
*
*************************************************************************/
void drv_rstctl_A7_unlock(rst_a7_lock_e lock)
{
    kal_uint32 regVal;

#ifdef SW_RST_READ_STATUS_SHITF_8
    regVal = (DRV_Reg32(REG_WDT_SW_GRP0_RST) >> 8);
#else
    regVal = DRV_Reg32(REG_WDT_SW_GRP0_RST);
#endif
    if(lock == RST_A7_UNLOCK)
        regVal = regVal | (0x1 << RSTCTL_A7_RSTUNLOCK_BIT) ;
    else
        regVal = regVal & ~(0x1 << RSTCTL_A7_RSTUNLOCK_BIT);

    DRV_WriteReg32(REG_WDT_SW_GRP0_RST,(RSTCTL_GRP0_RST_KEY | regVal));
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_sw_reset
*
* DESCRIPTION
*  This function is used to do SW ARM7 reset
*
* PARAMETERS
*	assert: 1: set reset assert
*            0: set reset de-assert
*    targetIP: only support RST_A7_CCIF/RST_A7_SRST/RST_A7_HRST/RST_A7_SYS
*
* RETURN VALUES
*	none
*
* NOTE: Please set assert at least one 32K cycle
*************************************************************************/
void drv_rstctl_sw_A7_reset(rst_a7_asrt_e asrt, rst_target_e targetIP)
{
    kal_uint32 rstVal;
    kal_uint32 regVal;

#ifdef SW_RST_READ_STATUS_SHITF_8
    regVal = (DRV_Reg32(REG_WDT_SW_GRP0_RST) >> 8);
#else
    regVal = DRV_Reg32(REG_WDT_SW_GRP0_RST);
#endif

    switch(targetIP)
    {
        case RST_CAIF:
            rstVal = 0x1 << RSTCTL_A7_CCIF_BIT;
            break;
        case RST_ARM7_SRST:
            rstVal = 0x1 << RSTCTL_A7_SRST_BIT;
            break;
        case RST_ARM7_HRST:
            rstVal = (0x1 << RSTCTL_A7_HRST_BIT);
            break;
        case RST_ARM7SYS:
            rstVal = (0x1 << RSTCTL_A7_HRST_BIT) | \
                     (0x1 << RSTCTL_A7_SRST_BIT) | (0x1 << RSTCTL_A7_CCIF_BIT);
            break;
        default:
            //dbg_print("targetIP=%d, Not ARM7!!", targetIP);
            return;
    }

    if(asrt == RST_A7_ASSERT)
        regVal = regVal | rstVal;
    else
        regVal = regVal & ~(rstVal);

    DRV_WriteReg32(REG_WDT_SW_GRP0_RST,(RSTCTL_GRP0_RST_KEY | regVal));
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_sw_reset
*
* DESCRIPTION
*  This function is used to do SW reset
*
* PARAMETERS
*	targetIP: sw module defined in RGU
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_sw_reset(rst_target_e targetIP)
{
    kal_uint32 regAddr;
    kal_uint32 rstKey;
    kal_uint32 rstBit;
    kal_uint32 regVal;
    kal_uint8 bA7Rst = 0;

    if(targetIP == RST_MD_SWRST || targetIP == RST_MDALL)
    {
        DRV_WriteReg32(REG_WDT_MD_SWRST, RSTCTL_MDSYS_SWRST_KEY);
        return;
    }

    switch(targetIP)
    {
        case RST_2GDSP:
            regAddr = REG_WDT_SW_DSP_RSTN;
            rstKey = RSTCTL_DSP_RST_KEY;
            rstBit = RSTCTL_2GDSP_BIT;
            break;
        case RST_CLDMA:
            regAddr = REG_WDT_SW_GRP0_RST;
            rstKey = RSTCTL_GRP0_RST_KEY;
            rstBit = RSTCTL_CLDMA_BIT;
            break;
        case RST_PCMON_REG:
            regAddr = REG_WDT_SW_GRP0_RST;
            rstKey = RSTCTL_GRP0_RST_KEY;
            rstBit = RSTCTL_PCMON_REG_BIT;
            break;
        case RST_PCMON_FIFO:
            regAddr = REG_WDT_SW_GRP0_RST;
            rstKey = RSTCTL_GRP0_RST_KEY;
            rstBit = RSTCTL_PCMON_FIFO_BIT;
            break;
        case RST_L2COP:
            regAddr = REG_WDT_SW_GRP0_RST;
            rstKey = RSTCTL_GRP0_RST_KEY;
            rstBit = RSTCTL_LTEL2_BIT;
            break;
        case RST_CAIF:
        case RST_ARM7_SRST:
        case RST_ARM7_HRST:
        case RST_ARM7SYS:
            regAddr = REG_WDT_SW_GRP0_RST;
            rstKey = RSTCTL_GRP0_RST_KEY;
            bA7Rst = 1;
            break;
        case RST_MML1STS:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_MML1STS_BIT;
            break;
        case RST_MML1_PERISYS_XRESET:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_XRESET_BIT;
            break;
        case RST_MML1_PERI_MBIST_CONFIG:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_MML1_PERI_MBIST_BIT;
            break;
        case RST_MML1_PERISYS_MISC:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_MML1_PERI_MISC_BIT;
            break;
        case RST_MML1_BPICTRL:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_MML1_BPICTRL_BIT;
            break;
        case RST_IDC:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_IDC_BIT;
            break;
        case RST_MIPI1_BSISPI:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_MIPI1_BSISPI_BIT;
            break;
        case RST_MIPI0_BSISPI:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_MIPI0_BSISPI_BIT;
            break;
        case RST_PMIC_BSISPI:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_PMIC_BSISPI_BIT;
            break;
        case RST_RFIC2_BSISPI:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_RFIC2_BSISPI_BIT;
            break;
        case RST_RFIC1_BSISPI:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_RFIC1_BSISPI_BIT;
            break;
        case RST_PF_BSICTRL:
            regAddr = REG_WDT_SW_GRP1_RST;
            rstKey = RSTCTL_GRP1_RST_KEY;
            rstBit = RSTCTL_PF_BSICTRL_BIT;
            break;
        default:
            //dbg_print("targetIP=%d, Out of range!!", targetIP);
            return;
    }
#ifdef SW_RST_READ_STATUS_SHITF_8
    if(regAddr == RSTCTL_GRP1_RST_KEY || regAddr == RSTCTL_GRP0_RST_KEY)
    {
        regVal = (DRV_Reg32(regAddr) >> 8);
    }
    else
    {
        regVal = DRV_Reg32(regAddr);
    }
#else
    regVal = DRV_Reg32(regAddr);
#endif

    if(bA7Rst)
        drv_rstctl_sw_A7_reset(RST_A7_ASSERT, targetIP);
    else
        DRV_WriteReg32(regAddr, (rstKey | (regVal | (0x1 << rstBit))));

    UT_DELAY_LOOP(RSTCTL_DURATION_LOOP_DEFAULT_VALUE);/*At lease one 32K clock period*/

    if(bA7Rst)
        drv_rstctl_sw_A7_reset(RST_A7_DEASSERT, targetIP);
    else
        DRV_WriteReg32(regAddr, rstKey | (regVal & ~(0x1 << rstBit)));

}


/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_reset
*
* DESCRIPTION
*  This function is used to config wd timer and start
*
* PARAMETERS
*    irq_en: wd reset issued irq istead of reset
*    wdtInterval: watchdog timerout period, unit as 512*T32K=15.6ms
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_reset(wdt_irq_e irq_en, rst_target_e wdTarget, kal_uint32 wdtInterval)
{
    /*1. disable wdt*/
    DRV_WriteReg32(REG_WDT_MD_MODE, RSTCTL_MD_MODE_KEY | (DRV_Reg32(REG_WDT_MD_MODE) & ~(0x1 << RSTCTL_WDT_EN_BIT)) );

    /*2. config timer period*/
    if(wdtInterval > RSTCTL_MAX_PERIOD_NUM)
    {
        //dbg_print("wdtInterval=0x%x, Out of range!! Auto down scale to Max value", wdtInterval);
        wdtInterval = RSTCTL_MAX_PERIOD_NUM;
    }

    if(0 != wdtInterval)
    {
        DRV_WriteReg32(REG_WDT_MD_LENGTH, RSTCTL_MD_LENGTH_KEY | (wdtInterval << RSTCTL_TIMEOUT_BIT));
        /*3. reload period*/

        DRV_WriteReg32(REG_WDT_MD_RESTART, RSTCTL_RESTART_TIMER_KEY);
        UT_DELAY_LOOP(RSTCTL_DURATION_LOOP_DEFAULT_VALUE);/*At lease one 32K clock period*/
    }

    /*4. set irq mode*/
    if (irq_en == WDT_IRQ_ONLY)
	{
		DRV_WriteReg32(REG_WDT_MD_MODE,(RSTCTL_MD_MODE_KEY)|((DRV_Reg32(REG_WDT_MD_MODE)) | (0x1 <<RSTCTL_IRQ_MODE_BIT)));
	}
	else
	{
		DRV_WriteReg32(REG_WDT_MD_MODE,(RSTCTL_MD_MODE_KEY)|((DRV_Reg32(REG_WDT_MD_MODE)) & (~(0x1 <<RSTCTL_IRQ_MODE_BIT))));
	}
    /*5. enable wdt*/
    if(0 != wdtInterval)
    {
        DRV_WriteReg32(REG_WDT_MD_MODE, RSTCTL_MD_MODE_KEY | (DRV_Reg32(REG_WDT_MD_MODE) | (0x1 << RSTCTL_WDT_EN_BIT )) );
    }
    else
    {
        drv_rstctl_sw_reset(RST_MD_SWRST);
    }
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_getSta
*
* DESCRIPTION
*  This function is used to get wdt status
*
* PARAMETERS
*	none
*
* RETURN VALUES
*    wdt_sta_e: no reset, sw reset, wd timer reset, sw and wd timer reset
*
*************************************************************************/
kal_uint32 drv_rstctl_wd_getSta(void)
{
    kal_uint32 sta;

    sta = DRV_Reg32(REG_WDT_MD_STA);

    return sta;
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_kick
*
* DESCRIPTION
*  This function is used to retart wd tiemr
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_kick(void)
{
    DRV_WriteReg32(REG_WDT_MD_RESTART, RSTCTL_RESTART_TIMER_KEY);
    UT_DELAY_LOOP(RSTCTL_DURATION_LOOP_DEFAULT_VALUE);/*At lease one 32K clock period*/
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_retn_flag_set
*
* DESCRIPTION
*  This function is used to set retention flag
*
* PARAMETERS
*	flag: rst_retn_flag_e
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_retn_flag_set(rst_retn_flag_e flag)
{
    DRV_WriteReg32(REG_WDT_RETN_SET, RSTCTL_RETN_FLAG_SET_KEY | flag);
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_retn_flag_set
*
* DESCRIPTION
*  This function is used to get retention flag
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	retetion flag value
*************************************************************************/
kal_uint16 drv_rstctl_retn_flag_get(void)
{
    return DRV_Reg32(REG_WDT_RETN_FLAG);
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_retn_flag_set
*
* DESCRIPTION
*  This function is used to clear retention flag
*
* PARAMETERS
*	flag: rst_retn_flag_e
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_retn_flag_clr(rst_retn_flag_e flag)
{
    DRV_WriteReg32(REG_WDT_RETN_CLR, RSTCTL_RETN_FLAG_SET_KEY | flag);
}


/*************************************************************************
* FUNCTION
*  drv_rstctl_retn_data
*
* DESCRIPTION
*  This function is used to read/write retention data
*
* PARAMETERS
*	bRead: 1: read data
*           0: write data
*    pData:
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_retn_data(kal_bool bRead, kal_uint32 *pData)
{
    if(pData == NULL)
        return;

    if(bRead == KAL_TRUE)
    {
        *pData =  DRV_Reg32(REG_WDT_RETN_DAT0);
    }
    else
    {
        DRV_WriteReg32(REG_WDT_RETN_DAT0, *pData);
    }

}

/*************************************************************************
*              Following is used by WDT DCL (Driver Common Layer)        *
*************************************************************************/

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_disable
*
* DESCRIPTION
*  This function is used to disable wd timer
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_disable(void)
{
	DRV_WriteReg32(REG_WDT_MD_MODE, RSTCTL_MD_MODE_KEY | (DRV_Reg32(REG_WDT_MD_MODE) & ~(0x1 << RSTCTL_WDT_EN_BIT)) );
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrSta
*
* DESCRIPTION
*  This function is used to clear wdt status
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_clrSta(void)
{
	/*Just write wdt_md_mode register to clear status*/
	DRV_WriteReg32(REG_WDT_MD_MODE, RSTCTL_MD_MODE_KEY | (DRV_Reg32(REG_WDT_MD_MODE))  );
}


/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrSta
*
* DESCRIPTION
*  This function is used to get wd timer interval(uint:512*T(32k))
*
* PARAMETERS
*	none
*
* RETURN VALUES
*	none
*************************************************************************/
kal_uint16 drv_rstctl_wd_getInterval(void)
{
	return (kal_uint16)(DRV_Reg32(REG_WDT_MD_LENGTH) >> RSTCTL_TIMEOUT_BIT);
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_kick
*
* DESCRIPTION
*  This function is used to retart wd tiemr
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_restartWDT(void)
{
	drv_rstctl_wd_kick();
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_setInterval
*
* DESCRIPTION
*  This function is used to set wd tiemr
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
* NOTE
*    Need to restart wdt timer to apply this value
*************************************************************************/
void drv_rstctl_wdt_setInterval(kal_uint32 wdtInterval)
{
	/* Set watchdog interval */
	DRV_WriteReg32(REG_WDT_MD_LENGTH, RSTCTL_MD_LENGTH_KEY | (wdtInterval << RSTCTL_TIMEOUT_BIT));
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_enable
*
* DESCRIPTION
*  This function is used to on/off wd timer
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
* NOTE
*    Need to restart wdt timer to apply this value
*************************************************************************/
void drv_rstctl_wdt_enable(kal_bool en)
{
	if (en == KAL_TRUE)
	{
		DRV_WriteReg32(REG_WDT_MD_MODE, RSTCTL_MD_MODE_KEY | (DRV_Reg32(REG_WDT_MD_MODE) | (0x1 << RSTCTL_WDT_EN_BIT )) );
		/*Reload wdt interval*/
		drv_rstctl_wd_kick();
	}
	else
	{
		drv_rstctl_wd_disable();
	}
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_abnReset
*
* DESCRIPTION
*  This function is used to do abnormal reset
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
void drv_rstctl_wdt_abnReset(void)
{
	SaveAndSetIRQMask();
	drv_rstctl_wd_reset(WDT_IRQ_ONLY, RST_TARGET_MAX, 1);
	while(1);
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_enableInterrupt
*
* DESCRIPTION
*  This function is used to on/off irq mode
*       reset or trigger interrupt while watchdog timout happening
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
void drv_rstctl_wdt_enableInterrupt(kal_bool enable)
{
	if (enable == KAL_TRUE)
	{
		DRV_WriteReg32(REG_WDT_MD_MODE,(RSTCTL_MD_MODE_KEY)|((DRV_Reg32(REG_WDT_MD_MODE)) | (0x1 <<RSTCTL_IRQ_MODE_BIT)));
	}
	else
	{
		DRV_WriteReg32(REG_WDT_MD_MODE,(RSTCTL_MD_MODE_KEY)|((DRV_Reg32(REG_WDT_MD_MODE)) & (~(0x1 <<RSTCTL_IRQ_MODE_BIT))));
	}

	UT_DELAY_LOOP(RSTCTL_DURATION_LOOP_DEFAULT_VALUE);/*At lease one 32K clock period*/
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_32k_irq_pulse
*
* DESCRIPTION
*  This function is used to on/off 32k interrupt pulse mode
*
*
* PARAMETERS
*    enable 32k interrupt pulse mode (TRUE) or 16T bus clock mode (FALSE)
*
* RETURN VALUES
*	none
*
*************************************************************************/
void drv_rstctl_wdt_32k_irq_pulse(kal_bool enable)
{
	if (enable == KAL_FALSE)
	{
		DRV_WriteReg32(REG_WDT_MD_MODE,(RSTCTL_MD_MODE_KEY)|((DRV_Reg32(REG_WDT_MD_MODE)) | (0x1 <<RSTCTL_SEL_32K_BIT)));
	}
	else
	{
		DRV_WriteReg32(REG_WDT_MD_MODE,(RSTCTL_MD_MODE_KEY)|((DRV_Reg32(REG_WDT_MD_MODE)) & (~(0x1 <<RSTCTL_SEL_32K_BIT))));
	}

	UT_DELAY_LOOP(RSTCTL_DURATION_LOOP_DEFAULT_VALUE);/*At lease one 32K clock period*/
}


/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_init
*
* DESCRIPTION
*  This function is to initialize the WDT module
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
void drv_rstctl_wdt_init(void)
{
    kal_uint32 reg_val;

	//WDT_RST = (DRV_WDT_Reg(WDT_STATUS) & WDT_STATUS_BITMASK)?(KAL_TRUE):(KAL_FALSE);
	drv_rstctl_wdt_setInterval(WDT_RSTINTERVAL_VALUE);

	reg_val = DRV_Reg32(REG_WDT_MD_MODE);

	//Set 32K pulse
    reg_val &= (~(0x1 <<RSTCTL_SEL_32K_BIT));

#if defined(DRV_WDT_IRQ_MODE)
	reg_val |= (0x1 << RSTCTL_IRQ_MODE_BIT);
	//IRQSensitivity(MD_IRQID_MD_WDT, KAL_TRUE);
	//IRQUnmask(MD_IRQID_MD_WDT);
#endif

    DRV_WriteReg32(REG_WDT_MD_MODE,(RSTCTL_MD_MODE_KEY)| reg_val);
    UT_DELAY_LOOP(RSTCTL_DURATION_LOOP_DEFAULT_VALUE);/*At lease one 32K clock period*/
}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_reset
*
* DESCRIPTION
*  This function is to do wdt reset
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
void drv_rstctl_wdt_reset(void)
{
#if defined(DRV_WDT_RESET_PKEY_RELEASE)
	kal_uint16 powerkey_status;

	#if defined(__USB_ENABLE__)

	DCL_BOOL dcl_data = DCL_TRUE;
	DCL_HANDLE	usb_dcl_handle;

	usb_dcl_handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);

	DclUSB_DRV_Control(usb_dcl_handle, USB_DRV_CMD_PDN_ENABLE, (DCL_CTRL_DATA_T  *)&dcl_data);
	DclUSB_DRV_Close(usb_dcl_handle);

	//	 USB_PDNmode(KAl_TRUE);

	#endif //#if defined(__USB_ENABLE__)

	#ifdef PMIC_PRESENT

	if (BMT.PWRon != CHRPWRON)
	{
		switch(Pwrkey_Position)
		{
			case low_key:
				powerkey_status= DRV_Reg32(KP_LOW_KEY);
				break;
		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
			case high_key:
				powerkey_status= DRV_Reg32(KP_HI_KEY);
				break;
			default:
				ASSERT(0);
				break;
		}
		if(WdtPowerKey_Pressed())
		{
			TargetReset = 1;
		}
		else
		{
			/*lint -e(534)*/SaveAndSetIRQMask();

			drv_rstctl_wdt_setInterval(1);
			drv_rstctl_wd_kick();
			drv_rstctl_wdt_enable(KAL_TRUE);
			while(1);
		}
	}
	else
	{
		/*lint -e(534)*/SaveAndSetIRQMask();

		drv_rstctl_wdt_setInterval(1);
		drv_rstctl_wd_kick();
		drv_rstctl_wdt_enable(KAL_TRUE);
		while(1);
	}
	#else /*PMIC_PRESENT*/
		  /*lint -e(534)*/SaveAndSetIRQMask();

		drv_rstctl_wdt_setInterval(1);
		drv_rstctl_wd_kick();
		drv_rstctl_wdt_enable(KAL_TRUE);
		while(1);
	#endif   /*PMIC_PRESENT*/
#else /*!DRV_WDT_RESET_PKEY_RELEASE*/

	kal_uint16 index;
#if defined(DRV_RTC_REG_COMM)
	DCL_HANDLE rtc_handler;
	RTC_CTRL_CONFIG_PDN_BIT_T rtc_cmd_data8;
#endif /*DRV_RTC_REG_COMM*/
	/*lint -e(534)*/SaveAndSetIRQMask();

	for(index=0;index<1000;index++);
#if defined(DRV_RTC_REG_COMM)
	//RTC_Set_PDN_bits(rtc_pdn2 ,DRV_COMM_REG2_NORMAL_RESET);
	rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
	rtc_cmd_data8.PDNIndex = DCL_RTC_PDN2;
	rtc_cmd_data8.fgConfigBit = DRV_COMM_REG2_NORMAL_RESET;
	DclRTC_Control(rtc_handler, RTC_CMD_SET_PDN_BITS, (DCL_CTRL_DATA_T *)&rtc_cmd_data8); // New API with CMD & DATA
#endif   /*DRV_RTC_REG_COMM*/
#if !defined(DRV_WDT_SWRST)
	drv_rstctl_wdt_setInterval(1);
	drv_rstctl_wd_kick();
	drv_rstctl_wdt_enable(KAL_TRUE);
	while(1);
#else
	#if defined(DRV_MISC_WDT_TURN_OFF_PLL)
	DRV_WriteReg32(0x80000108, 0);
	#endif // #if defined(DRV_MISC_WDT_TURN_OFF_PLL)
	_rst_swWdReset();	/* To trigger software watchdog reset */
	while(1);
	#endif
#endif   /*!DRV_WDT_RESET_PKEY_RELEASE*/

}

/*Legacy part for DCL*/
/*************************************************************************
* FUNCTION
*  drv_rstctl_wd_clrCnt
*
* DESCRIPTION
*  This function is used to clear wdt cnt
*
* PARAMETERS
*	cntMaskToClear
*   0: clear both AP/MD WD Cnt
*   MD_WDCNT_CLR: clear MD WD Cnt
*   AP_WDCNT_CLR: clear AP WD Cnt
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wd_clrCnt(kal_uint32 cntMaskToClear)
{

}

/*************************************************************************
* FUNCTION
*  drv_rstctl_wdt_enableDebugMode
*
* DESCRIPTION
*  This function is used to on/off debug mode
*
* PARAMETERS
*	cntMaskToClear
*   0: clear both AP/MD WD Cnt
*   MD_WDCNT_CLR: clear MD WD Cnt
*   AP_WDCNT_CLR: clear AP WD Cnt
*
* RETURN VALUES
*	none
*************************************************************************/
void drv_rstctl_wdt_enableDebugMode(kal_bool enable)
{

}



/*************************************************************************
*              Following is used by system init                          *
*************************************************************************/
/*************************************************************************
* FUNCTION
*  WDT_init
*
* DESCRIPTION
*  This function is to initialize the WDT module
*
* PARAMETERS
*    none
*
* RETURN VALUES
*	none
*
*************************************************************************/
void WDT_init(void)
{
	drv_rstctl_wdt_init();
}

/*************************************************************************
* FUNCTION
*  Get_WATCHDOG_BASE
*
* DESCRIPTION
*  This function is to get restart wd timer base address
*
* PARAMETERS
*    none
*
* RETURN VALUES
*    wd timer kick base address
*
*************************************************************************/
kal_uint32 Get_WATCHDOG_BASE()
{
	return (REG_WDT_MD_RESTART);
}

/*************************************************************************
* FUNCTION
*  Get_WATCHDOG_RESTART_CMD
*
* DESCRIPTION
*  This function is to get restart wd timer key
*
* PARAMETERS
*    none
*
* RETURN VALUES
*    wd timer kick command key
*
*************************************************************************/
kal_uint32 Get_WATCHDOG_RESTART_CMD()
{
	return (RSTCTL_RESTART_TIMER_KEY);
}

/*************************************************************************
* FUNCTION
*  Is_WDT_Init
*
* DESCRIPTION
*  Check WD timer is set to system default value already or not
*
* PARAMETERS
*    none
*
* RETURN VALUES
*     TRUE: already set
*    FALSE: not yet
*
*************************************************************************/
kal_bool Is_WDT_Init()// for ex_item.c
{
	if( drv_rstctl_wd_getInterval() == WDT_RSTINTERVAL_VALUE )
		return KAL_TRUE;
	else
		return KAL_FALSE;
}

#else
#error Not support rstctrl in this chip type
#endif /*MT6290*/


#else /*!defined(DRV_RSTCTL_OFF)*/

#endif /*!defined(DRV_RSTCTL_OFF)*/



