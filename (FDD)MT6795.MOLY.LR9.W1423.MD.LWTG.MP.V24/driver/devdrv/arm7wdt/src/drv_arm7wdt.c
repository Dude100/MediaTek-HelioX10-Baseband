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
 *    drv_arm7wdt.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This Module defines driver of the arm7wdt.
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
/* headers for driver */
#include "drv_features_wdt.h"
#include "drv_comm.h"
#if defined(MT6290) && defined(__ARM7EJ_S__)
#include "arm7wdt_reg.h"
#endif /* end of "defined(MT6290) && defined(__ARM7EJ_S__)" */
#include "intrCtrl.h"

/* headers for general */
#include "dcl.h"
#include "drv_hisr.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

#if !defined(DRV_RSTCTL_OFF)

#if defined(MT6290) && defined(__CR4__)

/*****************************************************************************
 *						 LISR/HISR/Callback Functions                        *
 *****************************************************************************/
void drv_arm7wdt_hisr(void) {
    // Need to discuss to trigger whole system watchdog reset or other solution.
    // In verification stage, we found that ARM7 cannot guarantee work fine after
    // software reset alone, due to bus may hang issue.
}

void drv_arm7wdt_lisr(void){
    IRQMask(MD_IRQID_A7WDT);

    // Activate HISR
////    drv_active_hisr(DRV_ARM7WDT_HISR_ID);
    IRQClearInt(MD_IRQID_A7WDT);
    IRQUnmask(MD_IRQID_A7WDT);
}

kal_bool drv_arm7wdt_lisr_register_flag = KAL_FALSE;
void drv_arm7wdt_register_lisr(void){
    if (drv_arm7wdt_lisr_register_flag){
        return;
    }
    IRQ_Register_LISR(MD_IRQID_A7WDT, drv_arm7wdt_lisr, "DRV_ARM7WDT_LISR");
    IRQSensitivity(MD_IRQID_A7WDT, KAL_TRUE); // It is pulse(edge) triggerd interrupt
    IRQUnmask(MD_IRQID_A7WDT);
    drv_arm7wdt_lisr_register_flag=KAL_TRUE;
}

void drv_arm7wdt_register_hisr(void){
////	DRV_Register_HISR(DRV_ARM7WDT_HISR_ID, drv_arm7wdt_hisr);
}

#elif defined(MT6290) && defined(__ARM7EJ_S__) // end of "defined(MT6290) && defined(__CR4__)"

/*****************************************************************************
 *              Porting for Moly Initialize Implementation                   *
 *****************************************************************************/
const kal_uint32 g_WATCHDOG_RESTART_REG   = ARM7WDT_RESTART_REG;
const kal_uint32 g_WATCHDOG_RESTART_VALUE = ARM7WDT_RESTART_KEY;
const kal_uint32 g_ABNORMAL_RST_REG       = ARM7WDT_INTERVAL_REG;
const kal_uint32 g_ABNORMAL_RST_VAL		  = WDT_RSTINTERVAL_VALUE;

kal_uint32 Get_WATCHDOG_BASE(void)
{
    return ARM7WDT_RESTART_REG;
}

kal_uint32 Get_WATCHDOG_RESTART_CMD(void)
{
    return ARM7WDT_RESTART_KEY;
}

void WDT_init(void)
{
    drv_arm7wdt_wdt_init();
}

kal_bool Is_WDT_Init(void) // for ex_item.c  
{
	if( (DRV_Reg32(ARM7WDT_INTERVAL_REG)&ARM7WDT_INTERVAL_MASK) == WDT_RSTINTERVAL_VALUE )
		return KAL_TRUE;
	else
		return KAL_FALSE;
}

/*****************************************************************************
 *                       Basic Driver Implementation                         *
 *****************************************************************************/

static void _arm7wdt_enableWdt(kal_uint32 wdtEnable, kal_uint32 wdtInterval)
{
    if (wdtEnable) {
        // Set watchdog interval
        DRV_WriteReg32(ARM7WDT_INTERVAL_REG, ((ARM7WDT_INTERVAL_KEY) | ((wdtInterval & ARM7WDT_INTERVAL_MASK) << ARM7WDT_INTERVAL_OFFSET) | (((DRV_Reg32(ARM7WDT_INTERVAL_REG)>>ARM7WDT_DURATION_OFFSET)&ARM7WDT_DURATION_MASK)<<ARM7WDT_DURATION_OFFSET)));
        // Load interval value into WDT counter
        DRV_WriteReg32(ARM7WDT_RESTART_REG, ARM7WDT_RESTART_KEY);
        // Enable watchdog and always set to interrupt mode
        DRV_WriteReg32(ARM7WDT_CONTROL_REG, (ARM7WDT_CONTROL_KEY) | DRV_Reg32(ARM7WDT_CONTROL_REG) | ARM7WDT_WDT_IRQEN_ENABLE | ARM7WDT_WDT_EN_ENABLE);
    } else { 
        // Just simply set WDTCR WDT_EN to disable
        DRV_WriteReg32(ARM7WDT_CONTROL_REG, (ARM7WDT_CONTROL_KEY) | (DRV_Reg32(ARM7WDT_CONTROL_REG) & (~ARM7WDT_WDT_EN_ENABLE)));
    }
}

void drv_arm7wdt_setInterval(kal_uint16 wdtInterval)
{
    // Set interval
    DRV_WriteReg32(ARM7WDT_INTERVAL_REG, ((ARM7WDT_INTERVAL_KEY) | ((wdtInterval & ARM7WDT_INTERVAL_MASK) << ARM7WDT_INTERVAL_OFFSET) | (((DRV_Reg32(ARM7WDT_INTERVAL_REG)>>ARM7WDT_DURATION_OFFSET)&ARM7WDT_DURATION_MASK)<<ARM7WDT_DURATION_OFFSET)));
}

void drv_arm7wdt_wdt_init(void)
{
    drv_arm7wdt_setInterval(WDT_RSTINTERVAL_VALUE);
    // In ARM7, always use interrupt mode and no software watchdog reset
    drv_arm7wdt_enableInterrupt(KAL_TRUE);
    // ARM7_WDT_Interrupt is connected to MDCIRQ not ARM7CIRQ, so no need to init
}

void drv_arm7wdt_restartWDT(void)
{
    // Load interval value into WDT counter
    DRV_WriteReg32(ARM7WDT_RESTART_REG, ARM7WDT_RESTART_KEY);
}

void drv_arm7wdt_abnReset(void)
{
    SaveAndSetIRQMask();
    drv_arm7wdt_setInterval(1);
    drv_arm7wdt_restartWDT();
    drv_arm7wdt_enable(KAL_TRUE);
    while(1);
}

void drv_arm7wdt_reset(void)
{
    SaveAndSetIRQMask();
    drv_arm7wdt_setInterval(1);
    drv_arm7wdt_restartWDT();
    drv_arm7wdt_enable(KAL_TRUE);
    while(1);
}

void drv_arm7wdt_enable(kal_bool en)
{
    if (en == KAL_TRUE) {
        DRV_WriteReg32(ARM7WDT_CONTROL_REG, (ARM7WDT_CONTROL_KEY) | (DRV_Reg32(ARM7WDT_CONTROL_REG) | ARM7WDT_WDT_EN_ENABLE));
    } else {
        DRV_WriteReg32(ARM7WDT_CONTROL_REG, (ARM7WDT_CONTROL_KEY) | (DRV_Reg32(ARM7WDT_CONTROL_REG) & (~ARM7WDT_WDT_EN_ENABLE)));        }
}

void drv_arm7wdt_disable(void)
{
    _arm7wdt_enableWdt(0, ARM7WDT_INTERVAL_MASK);
}

kal_uint16 drv_arm7wdt_getInterval(void)
{
    return (kal_uint16)(ARM7WDT_INTERVAL_MASK & DRV_Reg32(ARM7WDT_INTERVAL_REG));
}

void drv_arm7wdt_enableInterrupt(kal_bool enable)
{
    if (enable == KAL_TRUE) {
        DRV_WriteReg32(ARM7WDT_CONTROL_REG, (ARM7WDT_CONTROL_KEY) | DRV_Reg32(ARM7WDT_CONTROL_REG) | ARM7WDT_WDT_IRQEN_ENABLE);
    } else {
        // ARM7WDT do not support non-interrupt mode
        ASSERT(0);
    }
}

void drv_arm7wdt_enableDebugMode(kal_bool enable)
{
    if (enable==KAL_TRUE) {
        DRV_WriteReg32(ARM7WDT_CONTROL_REG, (ARM7WDT_CONTROL_KEY) | DRV_Reg32(ARM7WDT_CONTROL_REG) | ARM7WDT_WDT_IRQEN_ENABLE | ARM7WDT_WDT_EN_ENABLE);
    } else {
        // ARM7WDT do not support non-interrupt mode
        ASSERT(0);
    }
}

/*************************************************************************
* FUNCTION
*  drv_arm7wdt_getStatus
*
* DESCRIPTION
*  This function is used to get arm7 wdt status
*
* PARAMETERS
*  none
*
* RETURN VALUES
*  bit[2]:ARM7 hw WD reset indicator
*************************************************************************/
kal_uint32 drv_arm7wdt_getStatus(void)
{
    kal_uint32 wdt_sta;
    wdt_sta = (DRV_Reg32(ARM7WDT_STATUS_REG) >> ARM7WDT_HWDT_OFFSET) & ARM7WDT_HWDT_MASK;
    return wdt_sta;
}

kal_uint32 drv_arm7wdt_getWdtCnt(void)
{
    kal_uint32 wdt_sta;
    wdt_sta = (DRV_Reg32(ARM7WDT_STATUS_REG) >> ARM7WDT_WDT_CNT_OFFSET) & ARM7WDT_WDT_CNT_MASK;
    return wdt_sta;
}

/*************************************************************************
* FUNCTION
*  drv_arm7wdt_clrStatus
*
* DESCRIPTION
*  This function is used to clear arm7 wdt status
*
* PARAMETERS
*  none
*
* RETURN VALUES
*  none
*************************************************************************/
void drv_arm7wdt_clrStatus(void)
{
    DRV_WriteReg32(ARM7WDT_STATUS_REG, (ARM7WDT_STATUS_KEY) | ARM7WDT_HWDT_CLEAR);
}

void drv_arm7wdt_clrWdtCnt(void)
{
    DRV_WriteReg32(ARM7WDT_STATUS_REG, (ARM7WDT_STATUS_KEY) | ARM7WDT_WDT_CNT_CLEAR);
}

#endif /* end of "defined(MT6290) && defined(__ARM7EJ_S__)" */

#endif /* end of "!defined(DRV_RSTCTL_OFF)" */

