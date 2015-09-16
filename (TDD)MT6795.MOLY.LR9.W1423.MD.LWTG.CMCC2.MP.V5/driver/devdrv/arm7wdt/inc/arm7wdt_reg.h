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
 *    arm7wdt_reg.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This Module defines the register of the arm7wdt.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __ARM7WDT_REG_H__
#define __ARM7WDT_RRG_H__

#include <reg_base.h>

#if defined(MT6290) && defined(__ARM7EJ_S__)

// Global ARM7WDT Definition
#define ARM7WDT_BASE               (BASE_ADDR_ARM7WDT)
#define ARM7WDT_CONTROL_REG        (ARM7WDT_BASE + 0x00)      // RSTCTL_WDTCR
#define ARM7WDT_INTERVAL_REG       (ARM7WDT_BASE + 0x04)      // RSTCTL_WDTIR
#define ARM7WDT_RESTART_REG        (ARM7WDT_BASE + 0x08)      // RSTCTL_WDTRR
#define ARM7WDT_STATUS_REG         (ARM7WDT_BASE + 0x10)      // RSTCTL_WDTSR
#define ARM7WDT_THRESHOLD_REG      (ARM7WDT_BASE + 0x14)      // RSTCTL_WDTHR

// RSTCTL_WDTCR
#define ARM7WDT_CONTROL_KEY        (0x55 << 24)     // Key of RSTCTL_WDTCR
#define ARM7WDT_CONTROL_KEY_MASK   (0xFF << 24)     // Key Mask of RSTCTL_WDTCR
#define ARM7WDT_WDT_EN_ENABLE      (0x1 << 0)       // RSTCTL_WDTCR's WDT_EN
#define ARM7WDT_WDT_IRQEN_ENABLE   (0x1 << 3)       // RSTCTL_WDTCR's WDT_IRQEN
#define ARM7WDT_WDT_IRQEN_EN       (0x1)            // RSTCTL_WDTCR's WDT_IRQEN
#define ARM7WDT_WDT_SPD_UP_ENABLE  (0x1 << 15)      // RSTCTL_WDTCR's WDT_SPD_UP
#define ARM7WDT_WDT_EN_OFFSET      (0)
#define ARM7WDT_WDT_IRQEN_OFFSET   (3)
#define ARM7WDT_WDT_SPD_UP_OFFSET  (15)

// RSTCTL_WDTIR
#define ARM7WDT_INTERVAL_KEY       (0x67 << 24)     // Key of RSTCTL_WDTIR
#define ARM7WDT_INTERVAL_KEY_MASK  (0xFF << 24)     // Key Mask of RSTCTL_WDTIR
#define ARM7WDT_INTERVAL_MASK      (0xFFFF)         // RSTCTL_WDTIR's INTERVAL
#define ARM7WDT_INTERVAL_OFFSET    (0)              // RSTCTL_WDTIR's INTERVAL
#define ARM7WDT_DURATION_MASK      (0xFF)           // RSTCTL_WDTIR's DURATION (Not use in ARM7 Scenario)
#define ARM7WDT_DURATION_OFFSET    (16)             // RSTCTL_WDTIR's DURATION (Not use in ARM7 Scenario)

// RSTCTL_WDTRR
#define ARM7WDT_RESTART_KEY        (0x7208 << 16)   // Key of RSTCTL_WDTRR
#define ARM7WDT_RESTART_KEY_MASK   (0xFFFF << 16)   // Key Mask of RSTCTL_WDTRR

// RSTCTL_WDTSR
#define ARM7WDT_STATUS_KEY         (0x7662 << 16)   // Key of RSTCTL_WDTSR
#define ARM7WDT_STATUS_KEY_MASK    (0xFFFF << 16)   // Key Mask of RSTCTL_WDTSR
#define ARM7WDT_HWDT_CLEAR         (0x1 <<  2)      // RSTCTL_WDTSR's A7_WDT
#define ARM7WDT_SWDT_CLEAR         (0x1 <<  3)      // RSTCTL_WDTSR's A7_SWDT (Not use in ARM7 Scenario)
#define ARM7WDT_WDT_CNT_CLEAR      (0xF << 12)      // RSTCTL_WDTSR's A7_WDT_CNT
#define ARM7WDT_HWDT_MASK          (0x1)            // RSTCTL_WDTSR's A7_WDT
#define ARM7WDT_SWDT_MASK          (0x1)            // RSTCTL_WDTSR's A7_SWDT (Not use in ARM7 Scenario)
#define ARM7WDT_WDT_CNT_MASK       (0xF)            // RSTCTL_WDTSR's A7_WDT_CNT
#define ARM7WDT_HWDT_OFFSET        (2)              // RSTCTL_WDTSR's A7_WDT
#define ARM7WDT_SWDT_OFFSET        (3)              // RSTCTL_WDTSR's A7_SWDT (Not use in ARM7 Scenario)
#define ARM7WDT_WDT_CNT_OFFSET     (12)             // RSTCTL_WDTSR's A7_WDT_CNT

// RSTCTL_WDTHR
#define ARM7WDT_THRESHOLD_KEY      (0x3885 << 16)   // Key of RSTCTL_WDTHR
#define ARM7WDT_THRESHOLD_KEY_MASK (0xFFFF << 16)   // Key Mask of RSTCTL_WDTHR
#define ARM7WDT_WDT_THR_L_DEFAULT  (0x3)
#define ARM7WDT_WDT_THR_H_DEFAULT  (0x5)
#define ARM7WDT_WDT_THR_L_MASK     (0xF)
#define ARM7WDT_WDT_THR_H_MASK     (0xF)
#define ARM7WDT_WDT_THR_L_OFFSET   (0)
#define ARM7WDT_WDT_THR_H_OFFSET   (4)

typedef enum
{
    WDT_RESET,                    // (Not use in ARM7 Scenario)
    WDT_IRQ_ONLY,
} arm7wdt_irq_e;

#define WDT_RSTINTERVAL_VALUE	   (0xFFA)

// New Moly Porting APIs
extern kal_uint32 Get_WATCHDOG_BASE(void);         // for Moly Application_Initialize usage
extern kal_uint32 Get_WATCHDOG_RESTART_CMD(void);  // for Moly Application_Initialize usage
extern void WDT_init(void);
extern kal_bool Is_WDT_Init(void);
extern void drv_arm7wdt_setInterval(kal_uint16 wdtInterval);
extern void drv_arm7wdt_wdt_init(void);
extern void drv_arm7wdt_restartWDT(void);
extern void drv_arm7wdt_abnReset(void);
extern void drv_arm7wdt_reset(void);
extern void drv_arm7wdt_enable(kal_bool en);
extern kal_uint16 drv_arm7wdt_getInterval(void);
extern void drv_arm7wdt_enableInterrupt(kal_bool enable);
extern void drv_arm7wdt_enableDebugMode(kal_bool enable);

/************ Nucleus schedule for WDT restart ************/
extern const kal_uint32 g_WATCHDOG_RESTART_REG;
extern const kal_uint32 g_WATCHDOG_RESTART_VALUE;
extern const kal_uint32 g_ABNORMAL_RST_REG;
extern const kal_uint32 g_ABNORMAL_RST_VAL;
/**********************************************************/

// Original HVT APIs
extern void drv_arm7wdt_disable(void);
extern kal_uint32 drv_arm7wdt_getStatus(void);     // get HWDT status
extern kal_uint32 drv_arm7wdt_getWdtCnt(void);
extern void drv_arm7wdt_clrStatus(void);           // clear HWDT status
extern void drv_arm7wdt_clrWdtCnt(void);

#endif /* end of "defined(MT6290) && defined(__ARM7EJ_S__)" */

#endif /* end of __ARM7WDT_REG_H__ */

