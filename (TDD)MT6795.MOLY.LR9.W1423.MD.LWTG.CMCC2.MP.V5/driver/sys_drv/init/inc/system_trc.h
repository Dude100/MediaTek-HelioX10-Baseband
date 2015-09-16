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
 *   system_trc.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines the index trace of system module.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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

#ifndef _SYSTEM_TRACE_H
#define _SYSTEM_TRACE_H

#ifndef GEN_FOR_PC
#include "kal_public_defs.h" //MSBB change  #include "stack_config.h"
#endif /* GEN_FOR_PC */

#include "kal_trace.h"

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "system_trc_gen.h"
#endif /* TST Trace Defintion */
#endif

#define SYSTRACE_GROUP_INIT TRACE_GROUP_1
#define SYSTRACE_GROUP_DEMP TRACE_GROUP_2
#define SYSTRACE_GROUP_MMV1 TRACE_GROUP_3
#define SYSTRACE_GROUP_MMV2 TRACE_GROUP_4
#define SYSTRACE_GROUP_KAL_TIMER TRACE_GROUP_5
#define SYSTRACE_GROUP_RTOS TRACE_GROUP_6
#define SYSTRACE_GROUP_KALOTHER TRACE_GROUP_7

BEGIN_TRACE_MAP(MOD_SYSTEM)

    /* 1. Boot-up Trace */

    /* Cache */
    TRC_MSG(SST_INIT_L1CACHE_ENTER, "Enter L1-cache init")
    TRC_MSG(SST_INIT_L1CACHE_EXIT, "Exit L1-cache init")
    TRC_MSG(SST_INIT_MMU_ENTER, "Enter MMU init")
    TRC_MSG(SST_INIT_MMU_EXIT, "Exit MMU init")
    TRC_MSG(SST_INIT_MPU_ENTER, "Enter MPU init")
    TRC_MSG(SST_INIT_MPU_EXIT, "Exit MPU init")
    TRC_MSG(SST_INIT_L2CACHE_ENTER, "Enter L2-cache init")
    TRC_MSG(SST_INIT_L2CACHE_EXIT, "Exit L2-cache init")    
	
    /* Application_Initialize */	
    TRC_MSG(SST_INIT_APPINIT_START, "Starting Application_Initialize()")

    TRC_MSG(SST_INIT_CLIB1_ENTER, "Enter C library basic init")
    TRC_MSG(SST_INIT_CLIB1_EXIT, "Exit C library basic init")
    TRC_MSG(SST_INIT_CCCI_ENTER, "Enter CCCI init")
    TRC_MSG(SST_INIT_CCCI_EXIT, "Exit CCCI init")
    TRC_MSG(SST_INIT_CCCIHS1_ENTER, "Enter CCCI handshake phase1 init")
    TRC_MSG(SST_INIT_CCCIHS1_EXIT, "Exit CCCI handshake phase1 init")    
    TRC_MSG(SST_INIT_MDCIHS1_ENTER, "Enter MDCI handshake phase1 init")
    TRC_MSG(SST_INIT_MDCIHS1_EXIT, "Exit MDCI handshake phase1 init")
    TRC_MSG(SST_INIT_BOOTMODE_ENTER, "Enter Boot Mode variable setting")
    TRC_MSG(SST_INIT_BOOTMODE_EXIT, "Exit Boot Mode variable setting ... [ duration: %d ms ]")
    TRC_MSG(SST_INIT_SYSTEMINIT_ENTER, "Enter system intialization")
    TRC_MSG(SST_INIT_SYSTEMINIT_EXIT, "Exit system intialization ... [ duration: %d ms ]")
    TRC_MSG(SST_INIT_NVRAM_ENTER, "Enter NVRAM init")
    TRC_MSG(SST_INIT_NVRAM_EXIT, "Exit NVRAM init ... [ duration: %d ms ]")

    /* HWDInitialization */
    TRC_MSG(SST_INIT_USC_ENTER, "Enter ARM us counter init")
    TRC_MSG(SST_INIT_USC_EXIT, "Exit ARM us counter init ... [ duration: %d ms ]")
    TRC_MSG(SST_INIT_OSTD_ENTER, "Enter ARM OS Timer Sleep Mode init")
    TRC_MSG(SST_INIT_OSTD_EXIT, "Exit ARM OS Timer Sleep Mode init ... [ duration: %d ms ]")
    TRC_MSG(SST_INIT_L1SM_ENTER, "Enter L1SM init")
    TRC_MSG(SST_INIT_L1SM_EXIT, "Exit L1SM init ... [ duration: %d ms ]")
    TRC_MSG(SST_INIT_UL1SM_ENTER, "Enter UL1SM init")
    TRC_MSG(SST_INIT_UL1SM_EXIT, "Exit UL1SM init ... [ duration: %d ms ]")
    TRC_MSG(SST_INIT_EL1SM_ENTER, "Enter EL1SM init")
    TRC_MSG(SST_INIT_EL1SM_EXIT, "Exit EL1SM init ... [ duration: %d ms ]")
    TRC_MSG(SST_INIT_HWDIVIDER_ENTER, "Enter HW divider init")
    TRC_MSG(SST_INIT_HWDIVIDER_EXIT, "Exit HW divider init ... [ duration: %d ms ]")
    TRC_MSG(SST_INIT_IDMALOAD_ENTER, "Enter load DSP via iDMA")
    TRC_MSG(SST_INIT_IDMALOAD_EXIT, "Exit load DSP via iDMA ... [ duration: %d ms ]")
    TRC_MSG(SST_INIT_NFIRESET_ENTER, "Enter NFI reset")
    TRC_MSG(SST_INIT_NFIRESET_EXIT, "Exit NFI reset ... [ duration: %d ms ]")

    /* Driver Init Phase 1 */
    TRC_MSG(SST_INIT_DRV1_START, "Starting driver init phase1")
        TRC_MSG(SST_INIT_DRV1_TTY_ENTER, "    Enter TTY init")
        TRC_MSG(SST_INIT_DRV1_TTY_EXIT, "    Exit TTY init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_DRVHISR_ENTER, "    Enter driver HISR init")
        TRC_MSG(SST_INIT_DRV1_DRVHISR_EXIT, "    Exit driver HISR init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_MDCIHW_ENTER, "    Enter MDCI HW init")
        TRC_MSG(SST_INIT_DRV1_MDCIHW_EXIT, "    Exit MDCI HW init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_CCCI_ENTER, "    Enter CCCI init")
        TRC_MSG(SST_INIT_DRV1_CCCI_EXIT, "    Exit CCCI init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_EMIMPU_ENTER, "    Enter EMIMPU init")
        TRC_MSG(SST_INIT_DRV1_EMIMPU_EXIT, "    Exit EMIMPU init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_LPWR_ENTER, "    Enter low power init")
        TRC_MSG(SST_INIT_DRV1_LPWR_EXIT, "    Exit low power init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_DRVPDN_ENTER, "    Enter power down control init")
        TRC_MSG(SST_INIT_DRV1_DRVPDN_EXIT, "    Exit power down control init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_PWM_ENTER, "    Enter power management init")
        TRC_MSG(SST_INIT_DRV1_PWM_EXIT, "    Exit power management init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_CUSTOM_ENTER, "    Enter customized driver init")
        TRC_MSG(SST_INIT_DRV1_CUSTOM_EXIT, "    Exit customized driver init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_GPT3_ENTER, "    Enter GPT3 init")
        TRC_MSG(SST_INIT_DRV1_GPT3_EXIT, "    Exit GPT3 init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_VISUAL_ENTER, "    Enter visual init")
        TRC_MSG(SST_INIT_DRV1_VISUAL_EXIT, "    Exit visual init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_GPTI_ENTER, "    Enter GPTI init")
        TRC_MSG(SST_INIT_DRV1_GPTI_EXIT, "    Exit GPTI init ... [ duration: %d ms ]")        
        TRC_MSG(SST_INIT_DRV1_WDT_ENTER, "    Enter WDT init")
        TRC_MSG(SST_INIT_DRV1_WDT_EXIT, "    Exit WDT init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_DMA_ENTER, "    Enter DMA init")
        TRC_MSG(SST_INIT_DRV1_DMA_EXIT, "    Exit DMA init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_XOSC_ENTER, "    Enter XOSC set")
        TRC_MSG(SST_INIT_DRV1_XOSC_EXIT, "    Exit XOSC set ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_ADC_ENTER, "    Enter ADC init") 
        TRC_MSG(SST_INIT_DRV1_ADC_EXIT, "    Exit ADC init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_CSFACDET_ENTER, "    Enter customized factory mode detection init") 
        TRC_MSG(SST_INIT_DRV1_CSFACDET_EXIT, "    Exit customized factory mode detection init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_ACCDET_ENTER, "    Enter ACCDET init")
        TRC_MSG(SST_INIT_DRV1_ACCDET_EXIT, "    Exit ACCDET init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_LCD_ENTER, "    Enter LCD init")
        TRC_MSG(SST_INIT_DRV1_LCD_EXIT, "    Exit LCD init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_RTCHW_ENTER, "    Enter RTC HW init")
        TRC_MSG(SST_INIT_DRV1_RTCHW_EXIT, "    Exit RTC HW init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_PMIC_ENTER, "    Enter PMIC init")
        TRC_MSG(SST_INIT_DRV1_PMIC_EXIT, "    Exit PMIC init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_PW_ENTER, "    Enter power ON init")
        TRC_MSG(SST_INIT_DRV1_PW_EXIT, "    Exit power ON init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_DMAVFIFO_ENTER, "    Enter DMA VFIFO init")
        TRC_MSG(SST_INIT_DRV1_DMAVFIFO_EXIT, "    Exit DMA VFIFO init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_UART1_ENTER, "    Enter UART1 init")
        TRC_MSG(SST_INIT_DRV1_UART1_EXIT, "    Exit UART1 init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_UART2_ENTER, "    Enter UART2 init")
        TRC_MSG(SST_INIT_DRV1_UART2_EXIT, "    Exit UART2 init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV1_UART3_ENTER, "    Enter UART3 init")
        TRC_MSG(SST_INIT_DRV1_UART3_EXIT, "    Exit UART3 init ... [ duration: %d ms ]")
    TRC_MSG(SST_INIT_DRV1_OK, "Driver init phase1 ... [ OK ]")

    TRC_MSG(SST_INIT_PREFOTA_ENTER, "Enter FOTA preparation")
    TRC_MSG(SST_INIT_PREFOTA_EXIT, "Exit FOTA preparation ... [ duration: %d ms ]")
    TRC_MSG(SST_INIT_THIRDROM_ENTER, "Enter third ROM init")
    TRC_MSG(SST_INIT_THIRDROM_EXIT, "Exit third ROM init ... [ duration: %d ms ]")    
    TRC_MSG(SST_INIT_LOADSECMAUI_ENTER, "Enter Load Secondary MAUI")	
    TRC_MSG(SST_INIT_LOADSECMAUI_EXIT, "Exit Load Secondary MAUI ... [ duration: %d ms ]")    
    TRC_MSG(SST_INIT_DEMP_ENTER, "Enter demand paging init")
    TRC_MSG(SST_INIT_DEMP_EXIT, "Exit demand paging init")

    /* Power Init */
    TRC_MSG(SST_PW_POWERINIT_FACTOR_PWRKEY, "PW_PowerInit: factor: PWRKEY: %d")
    TRC_MSG(SST_PW_POWERINIT_FACTOR_CHRIN, "PW_PowerInit: factor: CHRIN: %d")
    TRC_MSG(SST_PW_POWERINIT_FACTOR_USBIN, "PW_PowerInit: factor: USBIN: %d")
    TRC_MSG(SST_PW_POWERINIT_FACTOR_RTCALARM, "PW_PowerInit: factor: RTC_ALARM: %d")
    TRC_MSG(SST_PW_POWERINIT_FACTOR_WDT, "PW_PowerInit: factor: WDT: %d")
    TRC_MSG(SST_PW_POWERINIT_FACTOR_NORMAL_RST, "PW_PowerInit: factor: NORMAL_RST_FG: %d")
    TRC_MSG(SST_PW_POWERINIT_FACTOR_CHR_PWRON_FG, "PW_PowerInit: factor: CHR_PWRON_FG: %d")
    TRC_MSG(SST_PW_POWERINIT_FACTOR_USBMS_PWRON_FG, "PW_PowerInit: factor: USBMS_PWRON_FG: %d")
    TRC_MSG(SST_PW_POWERINIT_FACTOR_RTC_PWRON_FG, "PW_PowerInit: factor: RTC_PWRON_FG: %d")
    TRC_MSG(SST_PW_POWERINIT_FACTOR_PRECHR_PWRON_FG, "PW_PowerInit: factor: PRECHR_PWRON_FG: %d")
    TRC_MSG(SST_PW_POWERINIT_FACTOR_FC2IDLE_FG, "PW_PowerInit: factor: SWITCH2IDLE_FG: %d")
    TRC_MSG(SST_PW_POWERINIT_FACTOR_FC2CHR_FG, "PW_PowerInit: factor: SWITCH2CHR_FG: %d")
    TRC_MSG(SST_PW_POWERINIT_FACTOR_FC2USB_FG, "PW_PowerInit: factor: SWITCH2USB_FG: %d")
    TRC_MSG(SST_PW_POWERINIT_PWRON_REASON, "PW_PowerInit: BMT.PWRon: %d")
    TRC_MSG(SST_PW_POWERINIT_ABNORMAL_PWRON, "PW_PowerInit: Abnormal power on")
    TRC_MSG(SST_PW_POWERINIT_META_PWRON, "PW_PowerInit: META power on")

    /* Driver Init Phase 2 */
    TRC_MSG(SST_INIT_DRV2_START, "Starting driver init phase2")
        TRC_MSG(SST_INIT_DRV2_USB2UART_ENTER, "    Enter USB2UART init")
        TRC_MSG(SST_INIT_DRV2_USB2UART_EXIT, "    Exit USB2UART init ... [ duration: %d ms ]")        
        TRC_MSG(SST_INIT_DRV2_KBD_ENTER, "    Enter keypad init")
        TRC_MSG(SST_INIT_DRV2_KBD_EXIT, "    Exit keypad init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV2_RTCSW_ENTER, "    Enter RTC SW init")
        TRC_MSG(SST_INIT_DRV2_RTCSW_EXIT, "    Exit RTC SW init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV2_SIM_ENTER, "    Enter SIM init")
        TRC_MSG(SST_INIT_DRV2_SIM_EXIT, "    Exit SIM init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV2_SIMMT6302_ENTER, "    Enter SIM MT6302 init")
        TRC_MSG(SST_INIT_DRV2_SIMMT6302_EXIT, "    Exit SIM MT6302 init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV2_MSDC_ENTER, "    Enter MSDC init")
        TRC_MSG(SST_INIT_DRV2_MSDC_EXIT, "    Exit MSDC init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV2_MSDC2_ENTER, "    Enter MSDC2 init")
        TRC_MSG(SST_INIT_DRV2_MSDC2_EXIT, "    Exit MSDC2 init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV2_EINTSWDBNC_ENTER, "    Enter EINT SW Debounce init")       
        TRC_MSG(SST_INIT_DRV2_EINTSWDBNC_EXIT, "    Exit EINT SW Debounce init ... [ duration: %d ms ]")               
        TRC_MSG(SST_INIT_DRV2_SWDBG_ENTER, "    Enter SWDBG init")
        TRC_MSG(SST_INIT_DRV2_SWDBG_EXIT, "    Exit SWDBG init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV2_CHE_ENTER, "    Enter cipher/hash engine init")       
        TRC_MSG(SST_INIT_DRV2_CHE_EXIT, "    Exit cipher/hash engine init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV2_IMGSENS_ENTER, "    Enter ISP/Camera init")
        TRC_MSG(SST_INIT_DRV2_IMGSENS_EXIT, "    Exit ISP/Camera init ... [ duration: %d ms ]")        
        TRC_MSG(SST_INIT_DRV2_CIS_ENTER, "    Enter Power ON CIS")
        TRC_MSG(SST_INIT_DRV2_CIS_EXIT, "    Exit Power ON CIS ... [ duration: %d ms ]")        
        TRC_MSG(SST_INIT_DRV2_MSENS_ENTER, "    Enter motion sensor init")
        TRC_MSG(SST_INIT_DRV2_MSENS_EXIT, "    Exit motion sensor init ... [ duration: %d ms ]")        
        TRC_MSG(SST_INIT_DRV2_WN_ENTER, "    Enter WLAN network init")
        TRC_MSG(SST_INIT_DRV2_WN_EXIT, "    Exit WLAN network init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV2_I2C_ENTER, "    Enter I2C init")
        TRC_MSG(SST_INIT_DRV2_I2C_EXIT, "    Init I2C init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV2_ICC_ENTER, "    Enter ICC init")
        TRC_MSG(SST_INIT_DRV2_ICC_EXIT, "    Exit ICC ... [ duration: %d ms ]")        
        TRC_MSG(SST_INIT_DRV2_BTIF_ENTER, "    Enter BTIF init")
        TRC_MSG(SST_INIT_DRV2_BTIF_EXIT, "    Exit BTIF init ... [ duration: %d ms ]")   
        TRC_MSG(SST_INIT_DRV2_ADC_ENTER, "    Enter ADC init")
        TRC_MSG(SST_INIT_DRV2_ADC_EXIT, "    Exit ADC init ... [ duration: %d ms ]")
        TRC_MSG(SST_INIT_DRV2_PFC_ENTER, "    Enter PFC init")
        TRC_MSG(SST_INIT_DRV2_PFC_EXIT, "    Exit PFC init ... [ duration: %d ms ]")
    TRC_MSG(SST_INIT_DRV2_OK, "Driver init phase2 ... [ OK ]")
       
    TRC_MSG(SST_INIT_RESINIT_ENTER, "Enter resource initialization")
    TRC_MSG(SST_INIT_RESINIT_EXIT, "Exit resource initialization ... [ duration: %d ms ]")    
    TRC_MSG(SST_INIT_CHECKMSGID_ENTER, "Enter message ID check")
    TRC_MSG(SST_INIT_CHECKMSGID_EXIT, "Check message ID check ... [ duration: %d ms ]")
    TRC_MSG(SST_INIT_CLIB2_ENTER, "Enter C library init")
    TRC_MSG(SST_INIT_CLIB2_EXIT, "Exit C library init ... [ duration: %d ms ]")
	
    TRC_MSG(SST_INIT_DMDSP1_ENTER, "Enter Dual MAC DSP init")
    TRC_MSG(SST_INIT_DMDSP1_EXIT, "Exit Dual MAC DSP init ... [ duration: %d ms ]")
    TRC_MSG(SST_INIT_CCCIHS2_ENTER, "Enter CCCI handshake phase2 init")
    TRC_MSG(SST_INIT_CCCIHS2_EXIT, "Exit CCCI handshake phase2 init ... [ duration: %d ms ]")
    TRC_MSG(SST_INIT_MDCIHS2_ENTER, "Enter MDCI handshake phase2 init")
    TRC_MSG(SST_INIT_MDCIHS2_EXIT, "Exit MDCI handshake phase2 init ... [ duration: %d ms ]")
    TRC_MSG(SST_INIT_DMDSP2_ENTER, "Enter Dual MAC DSP exception init")
    TRC_MSG(SST_INIT_DMDSP2_EXIT, "Exit Dual MAC DSP exception init ... [ duration: %d ms ]")
    TRC_MSG(SST_INIT_RTFINIT_ENTER, "Enter file system init")
    TRC_MSG(SST_INIT_RTFINIT_EXIT, "Exit file system init ... [ duration: %d ms ]")
    TRC_MSG(SST_INIT_RTFSANITY_ENTER, "Enter file system sanity check")
    TRC_MSG(SST_INIT_RTFSANITY_EXIT, "Exit file system sanity check ... [ duration: %d ms ]")

    TRC_MSG(SST_INIT_TASKINIT, "Starting task init")
    TRC_MSG(SST_INIT_TASKINIT_INDX_ENTER, "    Enter task init - %Mtask_indx_type")    
    TRC_MSG(SST_INIT_TASKINIT_INDX_EXIT, "    Exit task init - %Mtask_indx_type ... [ duration: %d ms ]")

    TRC_MSG(SST_INIT_APPINIT_OK, "Application_Initialize() ... [ OK ]")    

    /* 2. Demand Paging Trace */
    TRC_MSG(DEMP_PAGE_FAULT_ENTER, "[DEMP] Enter do_page_fault(), task:%Mtask_indx_type, prio:%d, ERROR_TYPE:%d, fault addr:0x%X, FSR:0x%X, nested count:%d +++++++")

    TRC_MSG(DEMP_ERR_CODE, "[DEMP] Return error code: %d")

    TRC_MSG(DEMP_PAGE_ALLOC_ENTER, "[DEMP] Enter page allocation")
    TRC_MSG(DEMP_PAGE_ALLOC_EXIT, "[DEMP] Exit page allocation, page VA:0x%X, page PA:0x%X, balance count:%d")
    TRC_MSG(DEMP_PAGE_SWAPOUT_ENTER, "[DEMP] Enter page swap-out, page VA:0x%X, fault addr:0x%X")
    TRC_MSG(DEMP_PAGE_SWAPOUT_EXIT, "[DEMP] Exit page swap-out")
    TRC_MSG(DEMP_PAGE_SWAPIN_ENTER, "[DEMP] Enter page swap-in, page VA:0x%X, fault addr:0x%X, prio:%d")
	
    TRC_MSG(DEMP_PAGE_LOCK_TAKEN, "[DEMP] MTD lock is taken by %Mtask_indx_type, lock count:%d")
    TRC_MSG(DEMP_PAGE_LOCK_AVAILABLE, "[DEMP] MTD lock is available")
    TRC_MSG(DEMP_PAGE_GET_LOCK, "[DEMP] %Mtask_indx_type gets MTD lock, prio:%d")
    TRC_MSG(DEMP_PAGE_FREE_LOCK, "[DEMP] %Mtask_indx_type frees MTD lock, prio:%d")
	
    TRC_MSG(DEMP_PAGE_SWAPIN_EXIT, "[DEMP] Exit page swap-in, page VA:0x%X, fault addr:0x%X, prio:%d")
    TRC_MSG(DEMP_PTABLE_UPDATE_ENTER, "[DEMP] Enter page table update, smallest_pd addr:0x%X, smallest_pd value:0x%X")
    TRC_MSG(DEMP_PTABLE_UPDATE_EXIT, "[DEMP] Exit page table update, smallest_pd addr:0x%X, smallest_pd value:0x%X")
    TRC_MSG(DEMP_PAGE_FAULT_EXIT, "[DEMP] Exit do_page_fault(), task:%Mtask_indx_type, prio:%d, ERROR_TYPE:%d, fault addr:0x%X, FSR:0x%X -------------------------------------")
	
    TRC_MSG(DEMP_LOCK_ENTER, "[DEMP][LOCK] Enter demp_lock_pages(), user:%Mdemp_lock_user, addr:0x%X, len:0x%X >>>>>>>>>>>>")
    TRC_MSG(DEMP_LOCK, "[DEMP] Lock page:0x%X")
    TRC_MSG(DEMP_LOCK_EXIT, "[DEMP][LOCK] Exit demp_lock_pages(), user:%Mdemp_lock_user, addr:0x%X, len:0x%X <<<<<<<<<<<<")

    TRC_MSG(DEMP_UNLOCK_ENTER, "[DEMP][LOCK] Enter demp_unlock_pages(), user:%Mdemp_lock_user, addr:0x%X, len:0x%X >>>>>>>>>>>>")
    TRC_MSG(DEMP_UNLOCK, "[DEMP] Unlock page:0x%X")
    TRC_MSG(DEMP_UNLOCK_EXIT, "[DEMP][LOCK] Exit demp_unlock_pages(), user:%Mdemp_lock_user, addr:0x%X, len:0x%X <<<<<<<<<<<<")
    
    TRC_MSG(SYSMEM_ALLOC_FORMAT, "[KAL] sys_mem_alloc(%u, %x)")
    TRC_MSG(ADM_CREATE2_FORMAT, "[KAL] adm_create2(%x, %u, %d/%d/%d..., %x, %d)=%x")
    TRC_MSG(ADM_DELETE_FORMAT, "[KAL] adm_delete(%x)=%x")
    TRC_MSG(ADM_ALLOC_FORMAT, "[KAL] adm_alloc(%x, %u, %u, %u, %s, %d)=%x")
    TRC_MSG(ADM_FREE_FORMAT, "[KAL] adm_free(%x, %x)")
    TRC_MSG(FLMM_ALLOC_FORMAT, "[KAL] flmm_alloc(%x)=%x/%x~%x")
    TRC_MSG(FLMM_FREE_FORMAT, "[KAL] flmm_free(%x), virtual=%x~%x")
    TRC_MSG(SLMM_DROP_FORMAT, "[KAL] slmm_drop(%x, %x~%x))")
    
    TRC_MSG(PROFILE_CPUUSAGE_FORMAT, "[KAL] CPU Usage: %d percent")
    
    /* Thread Protect Trace */
    TRC_MSG(TP_OVER_200QB, "[Thread Protect] Over 200QB warning: thread: %x, taker address: %x, giver address: %x, duration: %d")

    /*Event scheduler trace*/
    TRC_MSG(EVSHED_CREATE, "[evshed]evshed_create. task %d es 0x%x st 0x%x module %d fuzz %d max_delay_tick %d name %c %c %c %c %c %c %c %c")
    TRC_MSG(EVSHED_SET_EVENT, "[evshed]set_event task %d es 0x%x st 0x%x eid 0x%x hf 0x%x, tick %d")
    TRC_MSG(EVSHED_SET_INDEX, "[evshed] set_index, task %d es 0x%x st 0x%x, index %d")
    TRC_MSG(EVSHED_GET_INDEX, "[evshed] get_index, task %d st 0x%x, index %d")
    TRC_MSG(EVSHED_CANCEL_EVENT, "[evshed] cancel_event, task %d es 0x%x st 0x%x, eid 0x%x")
    TRC_MSG(EVSHED_SUSPEND, "[evshed]suspend, task %d es 0x%x st 0x%x")
    TRC_MSG(EVSHED_RESUME, "[evshed]resume, task %d es 0x%x st 0x%x")
    TRC_MSG(EVSHED_HANDLER, "[evshed]handler task %d es 0x%x st 0x%x eid 0x%x hf 0x%x")
    TRC_MSG(EVSHED_DEL, "[evshed]delete_all, task %d es 0x%x st 0x%x")
    TRC_MSG(EVSHED_SET_ALIGN, "[evshed] set_aligned_timer, task %d st 0x%x max_delay %d")
    TRC_MSG(EVSHED_UNSET_ALIGN, "[evshed]unset_aligned, task %d st 0x%x")

    /* DCM debug trace */
    TRC_MSG(DCM_COUNTER, "[DCM] DCM_CNT:%d")
    TRC_MSG(DCM_ACTIVE_CYCLES, "[DCM] HW_DCM_CYCLES:%d")
#if defined(MT6256) || defined(MT6255)
    TRC_MSG(DCM_LP_AUDIO_COUNTER, "[DCM] LP_AUDIO_CNT:%d")
    TRC_MSG(DCM_PDN_STATUS, "[DCM] MCU_PDN0:%x, MCU_PDN1:%x, MCU_PDN2:%x")
    TRC_MSG(DCM_MD2G_STATUS, "[DCM] MD2G_CG0:%x, MD2G_CG2:%x, MD2G_CG4:%x")
    TRC_MSG(DCM_MM_STATUS, "[DCM] MM_CG0:%x")
    TRC_MSG(DCM_PLL_STATUS, "[DCM] PLL_CON8:%x")
#endif
#if defined (MT6280) 
    TRC_MSG(DCM_MD_NONPWR_LPM_CON, "[DCM] MD npnpwr LPM_CON:%x")
    TRC_MSG(DCM_MD_NONPWR_LPM_STATUS, "[DCM] MD nonpwr LPM_TTL_TIME/L2H/HIDUR:%x, %x, %x")
    TRC_MSG(DCM_MD_PWR_LPM_CON, "[DCM] MD pwr LPM_CON:%x")
    TRC_MSG(DCM_MD_PWR_LPM_STATUS, "[DCM] MD pwr LPM_TTL_TIME/L2H/HIDUR:%x, %x, %x")
    TRC_MSG(DCM_AP_NONPWR_LPM_CON, "[DCM] AP npnpwr LPM_CON:%x")
    TRC_MSG(DCM_AP_NONPWR_LPM_STATUS, "[DCM] AP nonpwr LPM_TTL_TIME/L2H/HIDUR:%x, %x, %x")
    TRC_MSG(DCM_AP_PWR_LPM_CON, "[DCM] AP pwr LPM_CON:%x")
    TRC_MSG(DCM_AP_PWR_LPM_STATUS, "[DCM] AP pwr LPM_TTL_TIME/L2H/HIDUR:%x, %x, %x")
#endif

END_TRACE_MAP(MOD_SYSTEM)
#endif /* _TST_TRACE_H */


