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

/*******************************************************************************
 * Filename:
 * ---------
 *   bl_wdt.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   Reset controller driver
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * 	<saved by Perforce>
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * .
 ****************************************************************************/

#include "kal_general_types.h"
#include "reg_base.h"
#include "bl_drv_common.h"
#include "bl_wdt.h"

#ifdef MT6290_S00
#include "drv_bsi.h"
#endif

#define BASE_RSTCTL     (BASE_ADDR_MDRSTCTL)

#define REG_RSTCTL_WDTCR	(BASE_RSTCTL + 0x100)
#define REG_RSTCTL_WDTIR	(BASE_RSTCTL + 0x104)
#define REG_RSTCTL_WDTRR	(BASE_RSTCTL + 0x108)

#define REG_RSTCTL_WDTER_MDON	(BASE_RSTCTL + 0x10C)
#define REG_RSTCTL_WDTER_MDMCU	(BASE_RSTCTL + 0x110)
#define REG_RSTCTL_WDTER_MDINFR	(BASE_RSTCTL + 0x114)
#define REG_RSTCTL_WDTER_LTEL2	(BASE_RSTCTL + 0x118)
#define REG_RSTCTL_WDTER_MEMSYS	(BASE_RSTCTL + 0x11C)
#define REG_RSTCTL_WDTER_ARM7	(BASE_RSTCTL + 0x120)
#define REG_RSTCTL_WDTER_APMCU	(BASE_RSTCTL + 0x124)
#define REG_RSTCTL_WDTER_ARPERI	(BASE_RSTCTL + 0x128)
#define REG_RSTCTL_WDTER_SSUSB	(BASE_RSTCTL + 0x12C)
#define REG_RSTCTL_WDTER_APON	(BASE_RSTCTL + 0x130)
#define REG_RSTCTL_SRSTR_APPERI	(BASE_RSTCTL + 0x158)
#define REG_RSTCTL_RESET_UNLOCK	(BASE_RSTCTL + 0x168)
#define REG_RSTCTL_SRCMR	(BASE_RSTCTL + 0x300)
#define REG_RSTCTL_SRBER_APPERI	(BASE_RSTCTL + 0x324)

#define REG_RSTCTL_WDTSR	(BASE_RSTCTL + 0x134)
#define REG_RSTCTL_WDTHR	(BASE_RSTCTL + 0x138)

#define RST_CTRL_WDT_EN		(0x1)
#define RST_CTRL_WDT_IRQEN	(0x8)
#define RST_STATE_AP_SWR		(0x10)
#define RST_STATE_AP_SWDT 		(0x08)
#define RST_STATE_AP_HWDT		(0x04)
#define RST_STATE_MD_SWDT		(0x02)
#define RST_STATE_MD_HWDT		(0x01)
#define RST_STATE_CLEAR		(0x1F)

#define RST_MD_CNT_RST			(0x40)
#define RST_AP_CNT_RST			(0x80)

#define RST_MD_WDT_CNT_MASK				(0x0F00)
#define RST_AP_WDT_CNT_MASK				(0xF000)
#define RST_MD_WDT_CNT_SHIFT_BITS		(8)
#define RST_AP_WDT_CNT_SHIFT_BITS		(12)

#define RST_MD_WDT_THR_MASK				(0x0F)
#define RST_AP_WDT_THR_MASK				(0xF0)
#define RST_MD_WDT_THR_SHIFT_BITS		(0)
#define RST_AP_WDT_THR_SHIFT_BITS		(4)

#define RST_NFI_SWRST_BIT					(0x08)
#define RST_SWRST_EN_BIT					(0x1)

#define RST_KEY_CONTROL	(0x55000000)
#define RST_KEY_INTV		(0x67000000)
#define RST_KEY_RESTART	(0x72080000)
#define RST_KEY_WDTSR		(0x76620000)
#define RST_KEY_WDTHR		(0x38850000)
#define RST_KEY_SRCMR           (0x25930000)

#ifdef __X_BOOTING__
extern void drv_rstctl_ext_rst_pin_init();
#endif

void bl_wdt_init()
{
#ifdef __X_BOOTING__
    //Enable reset nodification to AP through pin 
    drv_rstctl_ext_rst_pin_init();
#endif

    //Enable WDT
    DRV_WriteReg32(REG_RSTCTL_WDTCR, RST_KEY_CONTROL |(DRV_Reg32(REG_RSTCTL_WDTCR)|0x1));

    bl_wdt_restart();
}

void bl_wdt_restart()
{
    DRV_WriteReg32(REG_RSTCTL_WDTRR, RST_KEY_RESTART | 0x1);
}

void bl_wdt_disable()
{
    DRV_WriteReg32(REG_RSTCTL_WDTCR,  RST_KEY_CONTROL);
}

void bl_wdt_unlock_ap_rst()
{
    kal_uint32 val;
    
    //unlock AP reset
    val = DRV_Reg32(REG_RSTCTL_RESET_UNLOCK);
    DRV_WriteReg32(REG_RSTCTL_RESET_UNLOCK, val | 0x1);
}

void bl_wdt_intr_enable()
{
    kal_uint32 val;

    //Enable wdt interrupt mode
    val = DRV_Reg32(REG_RSTCTL_WDTCR) | RST_KEY_CONTROL |RST_CTRL_WDT_IRQEN;
    DRV_WriteReg32(REG_RSTCTL_WDTCR, val);
}

void bl_wdt_force_reset(kal_uint32 interval)
{
#ifdef MT6290_S00
    //For 6290E1, VCTCXO1 is depends on SRCLCKEN.
    //The reset value of SRCLCKEN will cause MT6339 turn off VCRCXO1
    //Disable this feature before reset
    drv_bsi_pmic6339_reg_write(0x21, (drv_bsi_pmic6339_reg_read(0x21) & ~(0x2)));
#endif

    // Set watchdog interval
    DRV_WriteReg32(REG_RSTCTL_WDTIR, RST_KEY_INTV|interval);    

    //Enable WDT
    DRV_WriteReg32(REG_RSTCTL_WDTCR, RST_KEY_CONTROL |(DRV_Reg32(REG_RSTCTL_WDTCR)|0x1));

    // Simply reload watchdog counter 
    DRV_WriteReg32(REG_RSTCTL_WDTRR, RST_KEY_RESTART|0x1);
}

void bl_wdt_clear_ap_cnt()
{
    DRV_WriteReg32(REG_RSTCTL_WDTSR, RST_KEY_WDTSR | RST_AP_CNT_RST);
}
