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
 *   dcm.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides APIs to get device information 
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __MTK_TARGET__

#include <string.h>
#include "kal_general_types.h"
#include "cp15.h"
#include "dormant_mode.h"
#include "SST_sla.h"
#include "bus_drv.h"
#include "us_timer.h"
#include "config_hw.h"
#include "drv_bus_err.h"
#include "drv_comm.h"
#include "ccci_if.h"
#include "ex_mem_manager_public.h"


#if defined(__MCU_DORMANT_MODE__)

#define DORMANT_TOP_HEAD      (0xDADA0000UL)
#define DORMANT_2ND_WFI_IN    (DORMANT_TOP_HEAD|0x00000001)
#define DORMANT_2ND_WFI_OUT   (DORMANT_TOP_HEAD|0x00000002)

/* To get 3G RTR time, turn-on this option definition in dormant_service.c and cortexr4-dormantMode_gcc.S */
//#define MODEM_3G_RTR_TIME_CHECK 1

__DOR_TCM_BSS__ __attribute__((aligned(8))) volatile kal_uint32 dormant_mode_storage[DORMANT_TCM_STORAGE_SIZE>>2];

/*
 * Following variables are expected to locate on EMI space.
 */
/* variable to keep information of dormant mode entry and exit procedure */
__DOR_NONCACHED_BSS__ __attribute__((aligned(8))) volatile kal_uint32 dormant_tcm_storage[DORMANT_EMI_STORAGE_SIZE>>2];
__DOR_NONCACHED_BSS__ __attribute__((aligned(8))) volatile kal_uint32 dormant_mode_stack_pool[DORMANT_STACK_SIZE>>2];
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_reset_frc;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_leave_frc;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_enter_frc;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_standby_frc;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_abort_frc;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_reset_count;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_abort_count;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_restore_begin;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_tcm_restore_begin;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_mode_stack;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_dma0_status;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_dma1_status;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_ctrl_backup;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_coproc_acc_ctrl;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_power_on_reset_handler;
#if defined(MODEM_3G_RTR_TIME_CHECK)
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_reset_rtr;
#endif /* MODEM_3G_RTR_TIME_CHECK */



#if defined(MT6290)||defined(MT6595)||defined(MT6752)
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_cache_flush_start_frc;
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_cache_flush_end_frc;
#endif /* MT6290||defined(MT6595) */

#if defined(MT6290)
__DOR_NONCACHED_DATA__ __attribute__((aligned(8))) volatile kal_uint32 dormant_emi_code_storage[DORMANT_TCM_CODE_SIZE>>2];
__DOR_NONCACHED_DATA__ volatile kal_uint32 dormant_reset_end_frc;
#endif /* MT6290 */

volatile kal_uint32 dormant_dummy_wb_variable;

/* variable to keep chip dependent register definition. */
const kal_uint32 dormant_status_reg = (kal_uint32)DORMANT_RM_PWR_STA;
const kal_uint32 dormant_power_ack_mask = (kal_uint32)DORMANT_RM_PWR_STA_ARM_PWR_ACK;
const kal_uint32 dormant_frc_val = (kal_uint32)DORMANT_FRC_VAL_R;
#if defined(MODEM_3G_RTR_TIME_CHECK)
const kal_uint32 dormant_rtr_val = (kal_uint32)WCDMA_TIMER_BASE;
#endif /* MODEM_3G_RTR_TIME_CHECK */
const kal_uint32 dormant_alc_reg = (kal_uint32)DORMANT_ALC_CON;

#if defined(MT6290)
const kal_uint32 dormant_tcm_code_start = DORMANT_TCM_CODE_START_ADDR;
const kal_uint32 dormant_tcm_code_end = DORMANT_TCM_CODE_END_ADDR;
const kal_uint32 md_bus_err_ctl_addr = MD_DEC_ERR_CTL;
const kal_uint32 md_bus_err_ctl_value = MD_DEC_ERR_CTL_INI_VAL;
const kal_uint32 md_bus_err_type_addr = MD_DEC_ERR_TYPE;
const kal_uint32 md_bus_err_type_value = MD_DEC_ERR_TYPE_RESET;
#else
const kal_uint32 dormant_remapping_val = (kal_uint32)DORMANT_MD_REMAPPING_CON;
#endif /* MT6290 */

#if defined(__HIF_CLDMA_SUPPORT__)
    #define IFDEF_HIFCLDMA(x) x
#else /* __HIF_CLDMA_SUPPORT__ */
    #define IFDEF_HIFCLDMA(x)
#endif /* __HIF_CLDMA_SUPPORT__ */

IFDEF_HIFCLDMA(__DOR_NONCACHED_DATA__ kal_uint32 dormant_dbg_ptr);
IFDEF_HIFCLDMA(__DOR_NONCACHED_DATA__ kal_uint32 dormant_dbg_ptr_size;);

#if defined(MT6290) && !(defined(__SMART_PHONE_MODEM__)&&defined(__CCCIFS_SUPPORT__)&&defined(__X_BOOTING__)) /* 90 !SP */
extern void dormant_tcm_reset_entry(void);
#endif /* MT6290 && !SmartPhone */

/**********************************************************
Description : dormant mode init
Input       : Non
Output      : Non
***********************************************************/
void dormant_mode_init(void)
{
    /* init dormant mode stack */
    dormant_mode_stack_pool[0] = 0x43415453;
    dormant_mode_stack_pool[1] = 0x444E454B;

    /* set stack start address - 8 byte aligned address */
    dormant_mode_stack = (kal_uint32)&dormant_mode_stack_pool[(DORMANT_STACK_SIZE>>2)-2];

#if defined(MT6290)
    /* Backup for Bootrom */
    memcpy((void *)dormant_emi_code_storage, (void *)DORMANT_TCM_CODE_START_ADDR, DORMANT_TCM_CODE_SIZE);
#endif /* MT6290 */
	IFDEF_HIFCLDMA(EMM_DirInfo_Query(EMM_DIRECT_WRITE_DORMANT, &dormant_dbg_ptr, &dormant_dbg_ptr_size));
}

/**********************************************************
Description : dormant reset interwork procedure
Input       : Non
Output      : Non
***********************************************************/
void dormant_mode_reset_interwork(void)
{
    /* Hand-crafted ARM interworking */
    arm_dormant_reset_handler();
}

/**********************************************************
Description : trigger dormant mode procedure
Input       : Non
Output      : Non
***********************************************************/
__DOR_TCM_LOCAL_FUNC__ void dormant_mode_activate(void)
{
    kal_uint32 orig_reset = 0;
    SLA_CustomLogging("DOR", SA_start);
#if defined(MT6290)
    /* MT6290 reset on thumb mode and bootrom keeps it */
    DRV_WriteReg32(BOOT_VECTOR_ENABLE, BOOT_VECTOR_ENABLE_VAL);
    #if defined(__SMART_PHONE_MODEM__) && defined(__CCCIFS_SUPPORT__) && defined(__X_BOOTING__) /* 90 SP */
    DRV_WriteReg32(DORMANT_BOOT_JUMP_ADDR, ((kal_uint32)dormant_mode_reset_interwork) | 0x01);
    #else /* MT6290 && !SP */    
    DRV_WriteReg32(DORMANT_BOOT_JUMP_ADDR, ((kal_uint32)dormant_tcm_reset_entry) | 0x01);
    #endif /* MT6290 && !SP */
#elif defined(MT6595)||defined(MT6752)  /* MT6290 */
    DRV_WriteReg32(BOOT_VECTOR_KEY, BOOT_VECTOR_KEY_VAL);
    DRV_WriteReg32(DORMANT_BOOT_JUMP_ADDR, ((kal_uint32)dormant_mode_reset_interwork) | 0x01);
    DRV_WriteReg32(BOOT_VECTOR_ENABLE, BOOT_VECTOR_ENABLE_VAL);
    DRV_SetReg32(MD_GLOBAL_CON2, 1UL<<10);
#else
    #error "Dormant: unsupported Chip"
#endif /* MT6290 */ 

    dormant_enter_frc = ust_get_current_time();

    enter_dormant_mode();

    /* Use TOPSM timer directly */
    dormant_leave_frc = DRV_Reg32(dormant_frc_val);
#if defined(MT6595)||defined(MT6752)
    DRV_ClrReg32(MD_GLOBAL_CON2, 1UL<<10);
#endif /* MT6595 */

#if 1 /* the dormant flow will guarantee the ALC's FRC is ready, can be removed ? */
    /* Dormant sleep */
    {
        /* wait until ALC update or retry exhausted */
        kal_uint32 retry_cnt = 0xff;
        volatile kal_uint32 topsm_frc, alc_frc;

        do {
            topsm_frc = DRV_Reg32(dormant_frc_val);
            alc_frc = ust_get_current_time();

            retry_cnt--;
        } while ((topsm_frc != alc_frc) && retry_cnt);
    }
#endif /* 0 */

    IFDEF_HIFCLDMA(DRV_WriteReg32(dormant_dbg_ptr, DORMANT_2ND_WFI_IN));
    cp15_enter_low_pwr_state();
    IFDEF_HIFCLDMA(DRV_WriteReg32(dormant_dbg_ptr, DORMANT_2ND_WFI_OUT));

#if defined(MT6290)
    DRV_WriteReg32(BOOT_VECTOR_ENABLE, BOOT_VECTOR_DISABLE_VAL);
#elif defined(MT6595)||defined(MT6752)  /* MT6290 */
    DRV_WriteReg32(BOOT_VECTOR_KEY, BOOT_VECTOR_KEY_VAL);
#else
    #error "Dormant: unsupported Chip"
#endif /* MT6290 */ 
    DRV_WriteReg32(DORMANT_BOOT_JUMP_ADDR, orig_reset);

    SLA_CustomLogging("DOR", SA_stop);

    return ;
}

/**********************************************************
Description : mark a flag to indicate that entry to dormant mode is abort
Input       : Non
Output      : Non
***********************************************************/
__DOR_TCM_LOCAL_FUNC__ void dormant_mode_abort_entry(void)
{
    SLA_CustomLogging("dab", SA_label);
}

/**********************************************************
Description : mark a flag to indicate that dormant mode reset is abort
Input       : Non
Output      : Non
***********************************************************/
__DOR_TCM_LOCAL_FUNC__ void dormant_mode_abort_reset(void)
{
#ifndef ATEST_DRV_ENABLE
    SLA_CustomLogging("dra", SA_label);
#endif
}

#else /* !__MCU_DORMANT_MODE__ */

/**********************************************************
Description : dormant mode init
Input       : Non
Output      : Non
***********************************************************/
void dormant_mode_init(void)
{
    /* do nothing */
}

/**********************************************************
Description : trigger dormant mode procedure
Input       : Non
Output      : Non
***********************************************************/
void dormant_mode_activate(void)
{
    /* do nothing */
}

#endif /* __MCU_DORMANT_MODE__ */

#endif /* __MTK_TARGET__ */
