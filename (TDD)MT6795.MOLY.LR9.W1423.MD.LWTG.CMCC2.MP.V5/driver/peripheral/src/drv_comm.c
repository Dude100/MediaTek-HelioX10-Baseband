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
 *    drv_comm.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines driver common functions.
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "drv_comm.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "dma_sw.h"

#include "kal_trace.h"
#include "system_trc.h"
#include "init_trc_api.h"
#include "init.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"
#include "dcl_sim.h"
#include "ex_public.h"

//we encounter FOTA build error that fota.mak doesn't know where to find this bt header feil, but bt team comment thie header file is no longer needed.
//#if defined (__BTMODULE_MT6236__) || defined (__BTMODULE_MT6256__) || defined (__BTMODULE_MT6276__)
//#include "btif_sw.h"
//#endif

#include "bmt.h"
#include "eint.h"
#include "upll_ctrl.h"
#include "l1_interface.h"
#if defined(__DSP_FCORE4__)
#include "mdci.h"
#endif /* __DSP_FCORE4__ */
#if defined(MOTION_SENSOR_SUPPORT)
#include "motion_sensor.h"
#endif /* MOTION_SENSOR_SUPPORT */
#ifdef __SWDBG_SUPPORT__
#include "swdbg_sw.h"
#endif   /* __SWDBG_SUPPORT__ */

#ifdef __MTK_TARGET__
   //#include "syscomp_config.h"
#ifdef __MULTI_BOOT__
   #include "multiboot_config.h"
   //#include "fctycomp_config.h"
#ifdef __USB_ENABLE__
   //#include "usbmscomp_config.h"
#endif /* __USB_ENABLE__ */
#endif /* __MULTI_BOOT__ */
#endif /* __MTK_TARGET__ */
//#include    "pwic.h"
//#include "cs_fac_det.h"

#if defined(__RESOURCE_MANAGER__)
#include "rm.h"
#endif //__RESOURCE_MANAGER__

#include "us_timer.h"
#include "drv_hisr.h"

#ifdef DRV_SPI_SUPPORT
#include "spi.h"
#endif

#ifdef __HIF_CCCI_SUPPORT__
#include "ccci_if.h"
#endif

#if defined(__SMART_PHONE_MODEM__)
#include "ccci.h"



#if defined(DRV_EMIMPU)
extern void emimpu_init(void);
#endif /* DRV_EMIMPU */
#endif /* __SMART_PHONE_MODEM__ */
extern void DRVPDN_ini(void);
extern void DMA_Ini(void);
extern void WDT_init(void);
extern void custom_drv_init(void);
extern void EINT_SW_Debounce_Init(void);
extern void GCU_Disable_ReverseBit(void);
extern void USB2UART_init(void);
extern void Visual_Init(void);
//extern void che_hw_init(void);
extern void lpwr_init(void);
//#ifndef DRV_LCD_NOT_EXIST
//extern void lcd_system_init(void);
//#endif /*DRV_LCD_NOT_EXIST*/
#if !defined(DCL_MSDC_INTERFACE)
extern void MSDC_Initialize();
#if defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)
extern void MSDC_Initialize2();
#endif//defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)
#endif//!defined(DCL_MSDC_INTERFACE)

#ifdef __WIFI_SUPPORT__
extern void wndrv_HWinit(void);
#endif
extern void custom_drv_deinit(void);
#if defined(ISP_SUPPORT)
extern void CalInit(void);
#endif
#if defined(DRV_UART_SWITCHABLE_BETWEEN_PROCESSORS)
extern kal_uint8 UartPortOwnedByMD[3];
#endif // #if defined(DRV_UART_SWITCHABLE_BETWEEN_PROCESSORS)
extern kal_bool INT_QueryExceptionStatus(void);

/*
extern void GPTI_BusyWait(kal_uint16 len);
extern kal_uint16 Custom_Keypress_Period ;
*/
#ifdef __USB_COM_PORT_ENABLE__
extern Seriport_HANDLER_T USB2Uart_Drv_Handler;
#endif

/*lint -e552*/
boot_mode_type system_boot_mode = UNKNOWN_BOOT_MODE;
/*lint +e552*/
extern kal_uint16 INT_BootMode(void);
//extern kal_bool INT_USBBoot(void);

#ifdef IC_MODULE_TEST
   extern void IC_ModuleTest_Start(void);
#endif   /*IC_MODULE_TEST*/

#if defined(IC_BURNIN_TEST) || defined(DRV_MISC_GPT1_AS_OS_TICK)
extern void INT_Timer_Interrupt(void);
#endif //IC_BURNIN_TEST

typedef void (* MEMCPY_FUNC)(const void *srcaddr, void *dstaddr, kal_uint32 len);
#ifdef DRV_MISC_DMA_NO_MEMCPY
   void (* DRV_MEMCPY)(const void *srcaddr, void *dstaddr, kal_uint32 len);
#elif defined(DRV_MISC_DMA_MEMCPY)
   extern kal_bool DMA_memcpy(const void *src, const void *dst, kal_uint32 length);
   void (* DRV_MEMCPY_PTR)(const void *srcaddr, void *dstaddr, kal_uint32 len);
   void DRV_MEMCPY(const void *srcaddr, void *dstaddr, kal_uint32 len);
#endif   /**/

//#if defined(__IRDA_SUPPORT__) && !defined(__MEUT__) && !defined(__MEIT__)
/*TY adds this 2004/10/27*/
//extern UartDriver_strcut ircomm_uart_api;
//#endif

#if defined(__BTMTK__) && (defined(__BT_SPP_PROFILE__) || defined(__BT_HFG_PROFILE__))
extern Seriport_HANDLER_T  SPPA_Uart_Drv_Handler;
extern void bchs_host_controller_power_off(void);
#elif defined __CMUX_SUPPORT__
extern Seriport_HANDLER_T  CmuxUart_Drv_Handler;
#endif

#ifdef __SWDBG_SUPPORT__
extern kal_uint8 SWDBG_Profile;
#endif  /* _SWDBG_SUPPORT__ */

#ifdef  __BTMODULE_MT6601__
extern void BT_Radio_Shutdown(void);
#endif

#if (defined( DRV_MULTIPLE_SIM) && (!defined(DRV_2_SIM_CONTROLLER)))
extern void sim_MT6302_init(void);
#endif

#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_MISC_REG_DBG__)
#define DRV_MISC_WriteReg(addr,data)              DRV_DBG_WriteReg(addr,data)
#define DRV_MISC_Reg(addr)                        DRV_DBG_Reg(addr)
#define DRV_MISC_WriteReg32(addr,data)            DRV_DBG_WriteReg32(addr,data)
#define DRV_MISC_Reg32(addr)                      DRV_DBG_Reg32(addr)
#define DRV_MISC_WriteReg8(addr,data)             DRV_DBG_WriteReg8(addr,data)
#define DRV_MISC_Reg8(addr)                       DRV_DBG_Reg8(addr)
#define DRV_MISC_ClearBits(addr,data)             DRV_DBG_ClearBits(addr,data)
#define DRV_MISC_SetBits(addr,data)               DRV_DBG_SetBits(addr,data)
#define DRV_MISC_SetData(addr, bitmask, value)    DRV_DBG_SetData(addr, bitmask, value)
#define DRV_MISC_ClearBits32(addr,data)           DRV_DBG_ClearBits32(addr,data)
#define DRV_MISC_SetBits32(addr,data)             DRV_DBG_SetBits32(addr,data)
#define DRV_MISC_SetData32(addr, bitmask, value)  DRV_DBG_SetData32(addr, bitmask, value)
#define DRV_MISC_ClearBits8(addr,data)            DRV_DBG_ClearBits8(addr,data)
#define DRV_MISC_SetBits8(addr,data)              DRV_DBG_SetBits8(addr,data)
#define DRV_MISC_SetData8(addr, bitmask, value)   DRV_DBG_SetData8(addr, bitmask, value)
#else
#define DRV_MISC_WriteReg(addr,data)              DRV_WriteReg(addr,data)
#define DRV_MISC_Reg(addr)                        DRV_Reg(addr)
#define DRV_MISC_WriteReg32(addr,data)            DRV_WriteReg32(addr,data)
#define DRV_MISC_Reg32(addr)                      DRV_Reg32(addr)
#define DRV_MISC_WriteReg8(addr,data)             DRV_WriteReg8(addr,data)
#define DRV_MISC_Reg8(addr)                       DRV_Reg8(addr)
#define DRV_MISC_ClearBits(addr,data)             DRV_ClearBits(addr,data)
#define DRV_MISC_SetBits(addr,data)               DRV_SetBits(addr,data)
#define DRV_MISC_SetData(addr, bitmask, value)    DRV_SetData(addr, bitmask, value)
#define DRV_MISC_ClearBits32(addr,data)           DRV_ClearBits32(addr,data)
#define DRV_MISC_SetBits32(addr,data)             DRV_SetBits32(addr,data)
#define DRV_MISC_SetData32(addr, bitmask, value)  DRV_SetData32(addr, bitmask, value)
#define DRV_MISC_ClearBits8(addr,data)            DRV_ClearBits8(addr,data)
#define DRV_MISC_SetBits8(addr,data)              DRV_SetBits8(addr,data)
#define DRV_MISC_SetData8(addr, bitmask, value)   DRV_SetData8(addr, bitmask, value)
#endif //#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_MISC_REG_DBG__)

#ifdef __DRV_COMM_REG_DBG__
DRV_REG_DBG_STRUCT	DRV_REG_DBG_INFO_DATA;

static void drv_reg_dbg_trace(kal_uint8 write, kal_uint16 line, kal_uint32 addr, kal_uint32 value)
{
   DRV_REG_DBG_INFO_DATA.dbg_data[DRV_REG_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_COMM_REG_DBG_INFO_SIZE - 1)].write_flag = write;
   DRV_REG_DBG_INFO_DATA.dbg_data[DRV_REG_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_COMM_REG_DBG_INFO_SIZE - 1)].line_number = line;
   DRV_REG_DBG_INFO_DATA.dbg_data[DRV_REG_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_COMM_REG_DBG_INFO_SIZE - 1)].reg_addr = addr;
   DRV_REG_DBG_INFO_DATA.dbg_data[DRV_REG_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_COMM_REG_DBG_INFO_SIZE - 1)].reg_value = value;
   DRV_REG_DBG_INFO_DATA.dbg_data[DRV_REG_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_COMM_REG_DBG_INFO_SIZE - 1)].time_log = drv_get_current_time();
   DRV_REG_DBG_INFO_DATA.dbg_data_idx++;
}

void drv_reg_dbg_trace_write16(kal_uint16 line, kal_uint32 addr, kal_uint32 data)
{
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   ((*(volatile kal_uint16 *)(addr)) = (kal_uint16)(data));
   drv_reg_dbg_trace(1, line, addr, data);
   RestoreIRQMask(savedMask);
   return;
}

void drv_reg_dbg_trace_write32(kal_uint16 line, kal_uint32 addr, kal_uint32 data)
{
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   ((*(volatile kal_uint32 *)(addr)) = (kal_uint32)(data));
   drv_reg_dbg_trace(1, line, addr, data);
   RestoreIRQMask(savedMask);
   return;
}

void drv_reg_dbg_trace_write8(kal_uint16 line, kal_uint32 addr, kal_uint32 data)
{
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   ((*(volatile kal_uint8 *)(addr)) = (kal_uint8)(data));
   drv_reg_dbg_trace(1, line, addr, data);
   RestoreIRQMask(savedMask);
   return;
}

kal_uint16 drv_reg_dbg_trace_read16(kal_uint16 line, kal_uint32 addr)
{
   kal_uint16 value;
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   value = DRV_Reg(addr);
   drv_reg_dbg_trace(0, line, addr, value);
   RestoreIRQMask(savedMask);
   return value;
}

kal_uint32 drv_reg_dbg_trace_read32(kal_uint16 line, kal_uint32 addr)
{
   kal_uint32 value;
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   value = DRV_Reg32(addr);
   drv_reg_dbg_trace(0, line, addr, value);
   RestoreIRQMask(savedMask);
   return value;
}

kal_uint32 drv_reg_dbg_trace_read8(kal_uint16 line, kal_uint32 addr)
{
   kal_uint8 value;
   kal_uint32 savedMask;

   savedMask = SaveAndSetIRQMask();
   value = DRV_Reg8(addr);
   drv_reg_dbg_trace(0, line, addr, value);
   RestoreIRQMask(savedMask);
   return value;
}

#endif //__DRV_COMM_REG_DBG__

#if defined(__MTK_TARGET__)
/* bb reg dump setting */
EX_BBREG_DUMP drv_comm_dump;
const kal_uint32 drv_comm_dump_regions[] = {
  #if defined(MT6752)&&defined(__MD2__)
    CIRQ_base,                   0x049C, 4,     /* MDCIRQ */
    PLL_MIXEDSYS_base,           0x0800, 4,
    CONFIG_base,                 0x0600, 4,
    (INFRACFG_AO_BASE+0xF00),    0x0010, 4      /* PLL setting 0xA0001F00*/
  #else /* MT6752 && __MD2__*/
    #error "Unsupported Chip"
    //    0, 0, 0
  #endif/* MT6752 && __MD2__ */
};
#endif /* __MTK_TARGET__ */

#ifdef __DRV_COMM_INIT_DEINIT__
/*To get all customized data*/
void Drv_Customize_Init(void)
{
	DCL_HANDLE chr_usb_det_handle;

    chr_usb_det_handle = Dcl_Chr_Det_Open(DCL_CHR_USB_DET, FLAGS_NONE);
	Dcl_Chr_Det_Control(chr_usb_det_handle, CHR_DET_CMD_REGISTER_CHR_USB_EINT, NULL);
    Dcl_Chr_Det_Close(chr_usb_det_handle);
}

/*************************************************************************
* FUNCTION
*   Drv_query_boot_mode
*
* DESCRIPTION
*   Return boot mode.
*
* PARAMETERS
*
* RETURNS
*   FACTORY_BOOT, NORMAL_BOOT and USBMS_BOOT
*
* GLOBALS AFFECTED
*
*************************************************************************/
boot_mode_type Drv_query_boot_mode(void)
{

#ifdef __MULTI_BOOT__

#ifdef __USB_ENABLE__
	PW_CTRL_IS_USB_BOOT CtrlVal;
	DCL_HANDLE handle;
#endif /* __USB_ENABLE__ */

   if( INT_BootMode() == MTK_FACTORY_MODE )
      return FACTORY_BOOT;

#ifdef __USB_ENABLE__

	handle=DclPW_Open(DCL_PW, FLAGS_NONE);
	DclPW_Control(handle, PW_CMD_IS_USB_BOOT,(DCL_CTRL_DATA_T *)&CtrlVal);
	DclPW_Close(handle);
   if((kal_bool)CtrlVal.val == KAL_TRUE )
      return USBMS_BOOT;

#endif /* __USB_ENABLE__ */

#endif /* __MULTI_BOOT__ */

   return NORMAL_BOOT;
}

/*************************************************************************
* FUNCTION
*   Drv_PW_Init
*
* DESCRIPTION
*   PW initialization
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void Drv_PW_Init(void)
{
    
    //DclBMT_Initialize(); 
    
#ifndef __L1_STANDALONE__
   #ifdef PMIC_PRESENT
      print_bootup_trace_enter(SST_INIT_DRV1_PW);
			{
				DCL_HANDLE handle;
				Dcl_Chr_Det_Initialize();
				handle=DclPW_Open(DCL_PW, FLAGS_NONE);
				DclPW_Control(handle, PW_CMD_POWER_INIT, NULL);
				DclPW_Close(handle);
			}
      print_bootup_trace_exit(SST_INIT_DRV1_PW);
		
#if defined(DRV_BMT_HW_PRECC_WORKAROUND)
    {
        PW_CTRL_GET_POWERON_REASON CtrlVal;
        DCL_HANDLE pmu_handle;
        pmu_handle = DclPW_Open(DCL_PW, FLAGS_NONE);
        DclPW_Control(pmu_handle, PW_CMD_GET_POWERON_REASON, (DCL_CTRL_DATA_T *)&CtrlVal);
        if(CtrlVal.powerOnReason == CHRPWRON || CtrlVal.powerOnReason == USBPWRON_WDT ||
            CtrlVal.powerOnReason == USBPWRON)               
        {
       		// For Pre-cc 3.2~3.3V VCore Drop Issue
            DclPW_Control(pmu_handle, PW_CMD_POWERON, NULL);          
        }
        DclPW_Close(pmu_handle);  
    }    

#endif

#if defined(__DRV_NO_USB_CHARGER__)
    {
	   DCL_HANDLE handle;

	   handle=DclPW_Open(DCL_PW, FLAGS_NONE);
	   DclPW_Control(handle,PW_CMD_POWERON,NULL);
	   DclPW_Close(handle);
    }    
#endif

/*
	if(BMT.PWRon == PWRKEYPWRON)
		GPTI_BusyWait(Custom_Keypress_Period);
*/
   #else
      #ifdef __USB_ENABLE__
      {
			extern charger_usb_present_enum PW_is_charger_usb_present(void);

			switch (PW_is_charger_usb_present())
			{
			case CHARGER_PRESENT:
				break;
#if defined(__CHINA_CHARGER_STANDARD__)
			case CHARGER_PRESENT_NON:       //non-standard china charger
				break;
#endif
			case USB_PRESENT:
#if defined(DRV_PW_NONE_USB_POWER_ON)
				BMT.PWRon = CHRPWRON;
#else //#if defined(DRV_PW_NONE_USB_POWER_ON)
				BMT.PWRon = USBPWRON;
#endif //#if defined(DRV_PW_NONE_USB_POWER_ON)
				break;
			case NO_PRESENT:
				break;
         }
      }

      #endif   /*__USB_ENABLE__*/
	   handle=DclPW_Open(DCL_PW, FLAGS_NONE);
	   DclPW_Control(handle,PW_CMD_POWERON,NULL);
	   DclPW_Close(handle);
   #endif   /*PMIC_PRESENT*/
#else /*__L1_STANDALONE__*/
      {
	   DCL_HANDLE handle;

	   handle=DclPW_Open(DCL_PW, FLAGS_NONE);
	   DclPW_Control(handle,PW_CMD_POWERON,NULL);
	   DclPW_Close(handle);
      }
#endif   /*__L1_STANDALONE__*/
}

/*
* FUNCTION
*  Drv_Init_Phase1
*
* DESCRIPTION
*     This function is the NFB phase1 (Primary ROM) initial function for
*     all device drivers.
*     This function is called once to initialize the device driver.
*
* CALLS
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*
* NOTE XXX
*   All sub functions reference by this function should be placed on
*   Primary ROM for NFB projects. Or it cannot boot up because Drv_Init()
*   executed before Secondary ROM loaded.
*   Please make sure all sub-functions under custom.lib that referenced by
*   Drv_Init() list in NFB scatter file.
*/

void Drv_Init_Phase1(void)
{
#if defined(DRV_GPT_GPT3)
   DCL_HANDLE gpt_handle;
#endif //defined(DRV_GPT_GPT3)
#ifndef DRV_RTC_NOT_EXIST
   DCL_HANDLE rtc_handler;
#endif //#ifndef DRV_RTC_NOT_EXIST

	DCL_HANDLE uart_handle;
   UART_CTRL_INIT_T data_init;
   extern Seriport_HANDLER_T Uart_Drv_Handler;

#if defined(__MTK_TARGET__)
   /* register bb reg dump */
   drv_comm_dump.regions = (kal_uint32*)drv_comm_dump_regions;
   drv_comm_dump.num = sizeof(drv_comm_dump_regions) / (sizeof(kal_uint32) * 3);
   drv_comm_dump.bbreg_dump_callback = NULL;
   EX_REGISTER_BBREG_DUMP(&drv_comm_dump);
#endif /* __MTK_TARGET__ */

#ifdef __USB_COM_PORT_ENABLE__
   DCL_HANDLE  usb_dcl_handle;
   DCL_BOOL dcl_data;
   kal_bool b_is_dl_mode;

   usb_dcl_handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);
   DclUSB_DRV_Control(usb_dcl_handle, USB_DRV_CMD_USBDL_UPDATE_USB_DL_MODE, NULL);
   DclUSB_DRV_Control(usb_dcl_handle, USB_DRV_CMD_USBDL_IS_USB_DL_MODE, (DCL_CTRL_DATA_T  *)&dcl_data);
   b_is_dl_mode = (kal_bool)dcl_data;
   if(b_is_dl_mode == KAL_TRUE)
   {
      UPLL_Enable(UPLL_OWNER_USB);
   }
   DclUSB_DRV_Close(usb_dcl_handle);
#endif //__USB_COM_PORT_ENABLE__

#if defined(__CC_IRQ_EXIST__)
extern void cc_irq_init();
    cc_irq_init();
#endif

#if defined(__HW_US_TIMER_SUPPORT__ )
   USC_Start();
#endif

#ifdef __BACKUP_DOWNLOAD_RESTORE_WITHOUT_BATTERY__
	if (INT_GetSysStaByCmd(CHK_USB_META_WO_BAT, NULL)==KAL_TRUE)
	{

		DCL_HANDLE handle;
		DclPMU_Initialize();
		handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
		DclPMU_Control(handle, CHR_SET_CHARGE_WITHOUT_BATTERY, NULL);
		DclPMU_Close(handle);

	}
#endif //#ifdef __BACKUP_DOWNLOAD_RESTORE_WITHOUT_BATTERY__

   print_bootup_trace_enter(SST_INIT_DRV1_DRVHISR);
   drv_hisr_init();
   print_bootup_trace_exit(SST_INIT_DRV1_DRVHISR);

#if defined(__DSP_FCORE4__)
   print_bootup_trace_enter(SST_INIT_DRV1_MDCIHW);
   mdci_hw_init(1,0x0);
   print_bootup_trace_exit(SST_INIT_DRV1_MDCIHW);
#endif

#ifdef __HIF_CCCI_SUPPORT__
   print_bootup_trace_enter(SST_INIT_DRV1_CCCI);
   lte_ccci_hal_init();
   print_bootup_trace_exit(SST_INIT_DRV1_CCCI);
#endif

#if defined(__SMART_PHONE_MODEM__)
#if defined(__UPS_SUPPORT__)

   uart_handle =  DclSerialPort_Open(uart_port_ccmni1_ccci, 0);
   DclSerialPort_RegisterCallback(uart_handle, &CCCI_Uart_Drv_Handler);

   uart_handle =  DclSerialPort_Open(uart_port_ccmni2_ccci, 0);
   DclSerialPort_RegisterCallback(uart_handle, &CCCI_Uart_Drv_Handler);

   uart_handle =  DclSerialPort_Open(uart_port_ccmni3_ccci, 0);
   DclSerialPort_RegisterCallback(uart_handle, &CCCI_Uart_Drv_Handler);

#endif /* __UPS_SUPPORT__ */
#endif /* __SMART_PHONE_MODEM__ */

#if defined(DRV_EMIMPU)
   print_bootup_trace_enter(SST_INIT_DRV1_EMIMPU);
   emimpu_init();
   print_bootup_trace_exit(SST_INIT_DRV1_EMIMPU);
#endif /* DRV_EMIMPU */

   print_bootup_trace_enter(SST_INIT_DRV1_PWM);
   DclPWM_Initialize();
   print_bootup_trace_exit(SST_INIT_DRV1_PWM);

   /*To get all customized data*/
   print_bootup_trace_enter(SST_INIT_DRV1_CUSTOM);

   DclSADC_Initialize();

   Drv_Customize_Init();
   custom_drv_init();

   print_bootup_trace_exit(SST_INIT_DRV1_CUSTOM);

   #if defined(DRV_GPT_GPT3)
   print_bootup_trace_enter(SST_INIT_DRV1_GPT3);
   /*turn on gpt3 to count powen on period*/
  DclFGPT_Initialize();
	gpt_handle=DclFGPT_Open(DCL_GPT_FreeRUN3,0);
	DclFGPT_Control(gpt_handle,FGPT_CMD_START,0);
	DclFGPT_Close(gpt_handle);

   print_bootup_trace_exit(SST_INIT_DRV1_GPT3);
   #endif

   #if defined(MULTI_MEDIA_EXIST)
      print_bootup_trace_enter(SST_INIT_DRV1_VISUAL);
      Visual_Init();
      print_bootup_trace_exit(SST_INIT_DRV1_VISUAL);
   #endif /* defined(MULTI_MEDIA_EXIST)*/

#if defined(DRV_TIMING_DEBUG) && defined(DRV_GPT_6218B_GPT3_TIMING_DEBUG)
   DRV_MISC_WriteReg(0x8010001c,1);
   DRV_MISC_WriteReg(0x80100024,0x04);
   //DRV_WriteReg(0x80100024,1); // (1/16K)
#endif

   #ifdef DRV_MISC_DMA_NO_MEMCPY
      DRV_MEMCPY = (MEMCPY_FUNC)0x48000150;
   #elif defined(DRV_MISC_DMA_MEMCPY)
      DRV_MEMCPY_PTR = (MEMCPY_FUNC)0x48000134;
   #endif

   print_bootup_trace_enter(SST_INIT_DRV1_GPTI);
   DclSGPT_Initialize();
   print_bootup_trace_exit(SST_INIT_DRV1_GPTI);

   print_bootup_trace_enter(SST_INIT_DRV1_WDT);
   WDT_init();
   print_bootup_trace_exit(SST_INIT_DRV1_WDT);

   print_bootup_trace_enter(SST_INIT_DRV1_DMA);
   DMA_Ini();
   print_bootup_trace_exit(SST_INIT_DRV1_DMA);

   {
       // F32K HW init
       DCL_HANDLE F32K_handle;
       F32K_handle = DclF32K_Open(DCL_F32K_CLK, FLAGS_NONE);
       DclF32K_Control(F32K_handle, F32K_CLK_CMD_HW_INIT, (DCL_CTRL_DATA_T *)NULL);
       DclF32K_Close(F32K_handle);
   }

#ifndef DRV_RTC_NOT_EXIST
   // need to set XOSC earlier
   print_bootup_trace_enter(SST_INIT_DRV1_XOSC);
	rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
   DclRTC_Control(rtc_handler, RTC_CMD_SETXOSC, (DCL_CTRL_DATA_T *)NULL);
   print_bootup_trace_exit(SST_INIT_DRV1_XOSC);
#endif /*DRV_RTC_NOT_EXIST*/
   print_bootup_trace_enter(SST_INIT_DRV1_ADC);
   DclHADC_Initialize( );
   print_bootup_trace_exit(SST_INIT_DRV1_ADC);

#ifdef __CS_FAC_DET__
   print_bootup_trace_enter(SST_INIT_DRV1_CSFACDET);
   cs_fac_det = cs_fac_det_get_interface();
   cs_fac_det->drv_init();
   print_bootup_trace_exit(SST_INIT_DRV1_CSFACDET);
#endif // #ifdef __CS_FAC_DET__

#ifdef  __DRV_EXT_ACCESSORY_DETECTION__
#ifdef   __USB_COM_PORT_ENABLE__
   usb_dcl_handle = DclUSB_DRV_Open(DCL_USB, FLAGS_NONE);
   DclUSB_DRV_Control(usb_dcl_handle, USB_DRV_CMD_USBDL_IS_USB_DL_MODE, (DCL_CTRL_DATA_T  *)&dcl_data);
   b_is_dl_mode = (kal_bool)dcl_data;
   DclUSB_DRV_Close(usb_dcl_handle);

   if(b_is_dl_mode == KAL_FALSE)
#endif
   {
        print_bootup_trace_enter(SST_INIT_DRV1_EXTACCDET);
   	aux_ext_acc_det = aux_custom_get_ext_accessory_det();
   	aux_ext_acc_det->drv_init();
        print_bootup_trace_exit(SST_INIT_DRV1_EXTACCDET);
   }
#endif // #ifdef  __DRV_EXT_ACCESSORY_DETECTION__


//#endif //#if defined(__ACCDET_SUPPORT__)

#if defined(__RESOURCE_MANAGER__)
   print_bootup_trace_enter(SST_INIT_DRV1_RM);
   RMInit();
   print_bootup_trace_exit(SST_INIT_DRV1_RM);
#endif //__RESOURCE_MANAGER__

//#ifndef DRV_LCD_NOT_EXIST
//   print_bootup_trace_enter(SST_INIT_DRV1_LCD);
//   lcd_system_init();
//   print_bootup_trace_exit(SST_INIT_DRV1_LCD);
//#endif /*DRV_LCD_NOT_EXIST*/
#ifndef DRV_RTC_NOT_EXIST
#ifdef DRV_RTC_HW_CALI
   print_bootup_trace_enter(SST_INIT_DRV1_RTCHW);
   DclRTC_Control(rtc_handler, RTC_CMD_HW_INIT, (DCL_CTRL_DATA_T *)NULL);
   print_bootup_trace_exit(SST_INIT_DRV1_RTCHW);
#endif
#endif /*DRV_RTC_NOT_EXIST*/
	DclPW_Initialize();

    DclPMU_Initialize();

    Drv_PW_Init();

	/* update the system boot mode */
/*lint -e552*/
	system_boot_mode = Drv_query_boot_mode();
/*lint +e552*/
      print_boot_mode();

#ifdef __DMA_UART_VIRTUAL_FIFO__
//        print_bootup_trace_enter(SST_INIT_DRV1_DMAVFIFO);
//	DMA_Vfifo_init();
 //       print_bootup_trace_exit(SST_INIT_DRV1_DMAVFIFO);
#if defined(__MD_STANDALONE__)
// This is to configure AP side VFIFO ALT register, to avoid un-init AP side DMA setting
// conflict MD side setting
// This is only used in MD DVT load, when both side are ready, we shouldn't overwrite AP side setting via back door
	// Hack DMA channel 13 (VFIFO channel) in AP side in order to avoid conflict
	*(volatile kal_uint32 *)(0xF0022000 + 0xD40) = 0x3F;
	// Hack DMA channel 14 (VFIFO channel) in AP side in order to avoid conflict
	*(volatile kal_uint32 *)(0xF0022000 + 0xE40) = 0x3F;
#endif // #if defined(__MD_STANDALONE__)

#endif
#if  0
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
   #ifdef __UART3_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
#endif
#if 1
 print_bootup_trace_enter(SST_INIT_DRV1_UART1);

   data_init.u4Flag = KAL_FALSE;

   uart_handle =  DclSerialPort_Open(uart_port1, 0);
   DclSerialPort_DrvRegisterCb(uart_handle, &Uart_Drv_Handler);
   DclSerialPort_DrvAttach(uart_handle);

   // Initialization

   DclSerialPort_Control(uart_handle,SIO_CMD_INIT,&data_init);
   print_bootup_trace_exit(SST_INIT_DRV1_UART1);

#if !defined(DRV_MD_1_UART)

   // Register the callback function
   print_bootup_trace_enter(SST_INIT_DRV1_UART2);

   uart_handle =  DclSerialPort_Open(uart_port2, 0);
   DclSerialPort_DrvRegisterCb(uart_handle, &Uart_Drv_Handler);
   DclSerialPort_DrvAttach(uart_handle);

   // Initialization
   DclSerialPort_Control(uart_handle,SIO_CMD_INIT,&data_init);
   print_bootup_trace_exit(SST_INIT_DRV1_UART2);
#endif
   #ifdef __UART3_SUPPORT__
    print_bootup_trace_enter(SST_INIT_DRV1_UART3);
   // Register the callback function
   uart_handle =  DclSerialPort_Open(uart_port3, 0);
   DclSerialPort_DrvRegisterCb(uart_handle, &Uart_Drv_Handler);
   DclSerialPort_DrvAttach(uart_handle);
   DclSerialPort_Control(uart_handle,SIO_CMD_INIT,(DCL_CTRL_DATA_T *)&data_init);
   print_bootup_trace_exit(SST_INIT_DRV1_UART3);
   #endif
#endif
}

/*
* FUNCTION
*  Drv_Init_Phase2
*
* DESCRIPTION
*     This function is the NFB phase2 (Secondary ROM) initial function for
*     all device drivers.
*     This function is called once to initialize the device driver.
*
* CALLS
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*
* NOTE XXX
*   All sub functions reference by this function should be placed on
*   Secondary ROM for NFB projects.
*/
void Drv_Init_Phase2(void)
{
	DCL_HANDLE uart_handle;
#ifdef __USB_COM_PORT_ENABLE__
	DCL_CTRL_DATA_T data;
#endif   /*__USB_COM_PORT_ENABLE__*/
#ifndef DRV_RTC_NOT_EXIST
   DCL_HANDLE rtc_handler;
#endif /*DRV_RTC_NOT_EXIST*/

#if defined(IC_BURNIN_TEST) || defined(DRV_MISC_GPT1_AS_OS_TICK)
   /*AB: Enable GPT1 for OS tick in the burn-in test load*/
   extern void GPT_init(kal_uint8 timerNum, void (*GPT_Callback)(void));
   extern void GPT_ResetTimer(kal_uint8 timerNum,kal_uint16 countValue,kal_bool autoReload);
   extern void GPT_Start(kal_uint8 timerNum);
   GPT_init(1, INT_Timer_Interrupt);
   GPT_ResetTimer(1, 4, KAL_TRUE);
   GPT_Start(1);
#endif //IC_BURNIN_TEST


//#ifdef __SWDBG_SUPPORT__

//   UART_Register(uart_port_swdbg, UART_TYPE, (UartDriver_strcut *)&swdbgdrv);

//#endif   /* __SWDBG_SUPPORT__ */

#ifdef __USB_COM_PORT_ENABLE__
   print_bootup_trace_enter(SST_INIT_DRV2_USB2UART);
   uart_handle =  DclSerialPort_Open(uart_port_usb, 0);
   DclSerialPort_RegisterCallback(uart_handle, &USB2Uart_Drv_Handler);
#if defined(__USB_MULTIPLE_COMPORT_SUPPORT__)
   uart_handle =  DclSerialPort_Open(uart_port_usb2, 0);
   DclSerialPort_RegisterCallback(uart_handle, &USB2Uart_Drv_Handler);
   #if defined (__USB_MODEM_CARD_SUPPORT__)
   uart_handle =  DclSerialPort_Open(uart_port_usb3, 0);
   DclSerialPort_RegisterCallback(uart_handle, &USB2Uart_Drv_Handler);
   uart_handle =  DclSerialPort_Open(uart_port_usb4, 0);
   DclSerialPort_RegisterCallback(uart_handle, &USB2Uart_Drv_Handler);
   uart_handle =  DclSerialPort_Open(uart_port_usb5, 0);
   DclSerialPort_RegisterCallback(uart_handle, &USB2Uart_Drv_Handler);
   #endif
#endif
   DclSerialPort_Control(uart_handle,SIO_CMD_INIT,&data);// Initialization
   print_bootup_trace_exit(SST_INIT_DRV2_USB2UART);
#endif   /*__USB_COM_PORT_ENABLE__*/

//#if defined(__IRDA_SUPPORT__) && !defined(__MEUT__) && !defined(__MEIT__)
   /*TY adds this 2004/10/27*/
   /* Register UART API */
  // UART_Register(uart_port_irda, IRDA_TYPE, &ircomm_uart_api);
//#endif
#if defined(__BTMTK__) && (defined(__BT_SPP_PROFILE__) || defined(__BT_HFG_PROFILE__))
{
   kal_uint16 i;
   for(i = (kal_uint16)start_of_virtual_port; i < (kal_uint16)end_of_virtual_port + 1; i++)
   {
      uart_handle =  DclSerialPort_Open((DCL_DEV)i, 0);
      DclSerialPort_RegisterCallback(uart_handle, &SPPA_Uart_Drv_Handler);
   }
}
#elif defined __CMUX_SUPPORT__
{
   kal_uint16 i;
   for(i = (kal_uint16)start_of_virtual_port; i < (kal_uint16)end_of_virtual_port + 1; i++)
   {
      uart_handle =  DclSerialPort_Open((DCL_DEV)i, 0);
      DclSerialPort_RegisterCallback(uart_handle, &CmuxUart_Drv_Handler);
   }
}
#endif
#ifndef DRV_KBD_NOT_EXIST
   print_bootup_trace_enter(SST_INIT_DRV2_KBD);
   DclSKBD_Initialize();
   print_bootup_trace_exit(SST_INIT_DRV2_KBD);
#endif /*DRV_KBD_NOT_EXIST*/
#ifndef DRV_RTC_NOT_EXIST
   print_bootup_trace_enter(SST_INIT_DRV2_RTCSW);
	rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);
	DclRTC_Control(rtc_handler, RTC_CMD_INIT_TC_AL_INTR, (DCL_CTRL_DATA_T *)NULL);
   print_bootup_trace_exit(SST_INIT_DRV2_RTCSW);
#endif /*DRV_RTC_NOT_EXIST*/

#ifdef __SIM_DRV_MULTI_DRV_ARCH__
   print_bootup_trace_enter(SST_INIT_DRV2_SIM);
   DclSIM_Initialize();
   print_bootup_trace_exit(SST_INIT_DRV2_SIM);
#endif

#if (defined( DRV_MULTIPLE_SIM) && (!defined(DRV_2_SIM_CONTROLLER)))
   print_bootup_trace_enter(SST_INIT_DRV2_SIMMT6302);
   sim_MT6302_init();
   print_bootup_trace_exit(SST_INIT_DRV2_SIMMT6302);
 #endif

#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined (__MSDC_MSPRO__))
   print_bootup_trace_enter(SST_INIT_DRV2_MSDC);
#if !defined(DCL_MSDC_INTERFACE)
   MSDC_Initialize();
#else
   DclSD_Initialize();
#endif//!defined(DCL_MSDC_INTERFACE)
   print_bootup_trace_exit(SST_INIT_DRV2_MSDC);
#if defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)
   print_bootup_trace_enter(SST_INIT_DRV2_MSDC2);
#if !defined(DCL_MSDC_INTERFACE)
   MSDC_Initialize2();
#endif//!defined(DCL_MSDC_INTERFACE)
   print_bootup_trace_exit(SST_INIT_DRV2_MSDC2);
#endif//defined(__MSDC2_SD_MMC__) || defined(__MSDC2_SD_SDIO__)
#endif//(defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined (__MSDC_MSPRO__))

#ifdef IC_MODULE_TEST
   IC_ModuleTest_Start();
#endif   /*IC_MODULE_TEST*/

   print_bootup_trace_enter(SST_INIT_DRV2_EINTSWDBNC);
   EINT_SW_Debounce_Init();
   print_bootup_trace_exit(SST_INIT_DRV2_EINTSWDBNC);
#ifdef MT6218B/*only 6218B has this */
   GCU_Disable_ReverseBit();
#endif
#ifdef __SWDBG_SUPPORT__

   /* initialize SWDBG */
   print_bootup_trace_enter(SST_INIT_DRV2_SWDBG);
   swdbg_init();
   print_bootup_trace_exit(SST_INIT_DRV2_SWDBG);

#endif   /* __SWDBG_SUPPORT__ */


 	/* ISP/Camera initialize */
#if defined(ISP_SUPPORT)
    print_bootup_trace(SST_INIT_DRV2_CIS_ENTER);
 	CalInit();
 	print_bootup_trace(SST_INIT_DRV2_CIS_EXIT);
#endif

#ifdef __WIFI_SUPPORT__
   print_bootup_trace_enter(SST_INIT_DRV2_WN);
   wndrv_HWinit();
   print_bootup_trace_exit(SST_INIT_DRV2_WN);
#endif

//#if (defined(_USE_SCCB_V2_DRIVER_))
#if defined(DRV_I2C_25_SERIES)
   print_bootup_trace_enter(SST_INIT_DRV2_I2C);
   DclSI2C_Initialize();
   print_bootup_trace_exit(SST_INIT_DRV2_I2C);
#endif

// PXS is init at phase2 because it is external devices
// Currently, do NOT think it should be put in phase1
#if defined(__PXS_ENABLE__) && !defined(IC_MODULE_TEST) && !defined(IC_BURNIN_TEST)
   DclPXS_Initialize();
#endif // #if defined(__PXS_ENABLE__) && !defined(IC_MODULE_TEST) && !defined(IC_BURNIN_TEST)


#ifdef CAS_SMD_SUPPORT
   print_bootup_trace_enter(SST_INIT_DRV2_ICC);
	DalIccInit();
   print_bootup_trace_exit(SST_INIT_DRV2_ICC);
#endif

#if 0 // Init BTIF_HWInit_VFIFO(); in bluetooth module
#if defined(__BTMODULE_MT6236__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(__BTMODULE_MT6256__) || defined(__BTMODULE_MT6276__)
/* under construction !*/
#endif
/* under construction !*/
#endif // 0

#ifdef DRV_SPI_SUPPORT
    spi_init();
#endif
#if defined(__TOUCH_PANEL_CAPACITY__)
   DclSTS_Initialize();
#endif

#if defined(MOTION_SENSOR_SUPPORT)
   print_bootup_trace_enter(SST_INIT_DRV2_MSENS);
   motion_sensor_init();
   print_bootup_trace_exit(SST_INIT_DRV2_MSENS);
#endif

}

/*
* FUNCTION
*  Drv_Deinit
*
* DESCRIPTION
*     This function is the deinitial function for all device drivers.
*     This function is called once to deinitialize the device driver.
*
* CALLS
*
* PARAMETERS
*  None
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*   external_global
*/
void Drv_Deinit(void)
{
   /* Don't do driver deinit when still in system initialization stage.
      Otherwise it may cause problem in NFI booting. */
   if (KAL_FALSE == kal_query_systemInit())
   {
      custom_drv_deinit();
#ifdef  __BTMODULE_MT6601__
      BT_Radio_Shutdown();
#endif
   }


}

#endif //__DRV_COMM_INIT_DEINIT__

#if defined(DRV_MISC_DMA_MEMCPY)
void DRV_MEMCPY(const void *srcaddr, void *dstaddr, kal_uint32 len)
{
   if (!DMA_memcpy(srcaddr,dstaddr,len))
      DRV_MEMCPY_PTR(srcaddr,dstaddr,len);
}
#endif   /*DRV_MISC_DMA_MEMCPY*/


kal_bool Drv_WriteReg(kal_uint32 addr, kal_uint16 data)
{
   if (addr < 0x70000000)
      return KAL_FALSE;

   DRV_MISC_WriteReg(addr,data);
   return KAL_TRUE;
}

kal_bool Drv_ReadReg(kal_uint32 addr, kal_uint16 *data)
{
   if (addr < 0x70000000)
      return KAL_FALSE;

   *data = DRV_MISC_Reg(addr);
   return KAL_TRUE;
}

kal_uint32 drv_get_current_time(void)
{

#if defined(DRV_MISC_TDMA_NO_TIME)
   ASSERT(0);
#endif   /*DRV_MISC_TDMA_NO_TIME*/

#if defined(DRV_MISC_TDMA_TIME_BASE)
   return (DRV_MISC_Reg32(TDMA_base+0x0230));
#elif defined(DRV_MISC_TDMA_TIME_BASE_8200)
    return (DRV_MISC_Reg32(0x82000230));
#elif defined(DRV_MISC_TDMA_TIME_BASE_8020)
    return (DRV_MISC_Reg32(0x80200230));
#elif defined(DRV_MISC_TDMA_TIME_BASE_8406)
    return (DRV_MISC_Reg32(0x84060230));
#elif defined(DRV_MISC_TDMA_L1_MACRO)
    return (HW_TDMA_GET_32KCNT());
#elif defined(DRV_MISC_TOPSM_32K_RTC) /* Get 32K ticks */
    return DRV_MISC_Reg32(BASE_ADDR_MDTOPSM+0x0104);
#else
   return 0;
#endif

}



kal_uint32 drv_get_duration_tick(kal_uint32 previous_time, kal_uint32 current_time)
{
	kal_uint32 result=0;
#if defined(DRV_MISC_TDMA_NO_TIME)
   ASSERT(0);
#endif   /*DRV_MISC_TDMA_NO_TIME*/

	if (previous_time > current_time)
	{
//#if defined(DRV_MISC_TDMA_TIME_MAX_80000)
#if defined(DRV_MISC_TDMA_TIME_MAX_19BITS)
		result = 0x80000 - previous_time + current_time;
#elif defined(DRV_MISC_TDMA_TIME_MAX_24BITS)
      result = 0x1000000 - previous_time + current_time;
#elif defined(DRV_MISC_TDMA_TIME_MAX_32BITS)
      result = 0xFFFFFFFF - previous_time + current_time + 1;
#endif
	}
	else
	{
		result = current_time - previous_time;
	}
	return result;
}

kal_uint32 drv_get_duration_ms(kal_uint32 previous_time)
{
	kal_uint32 result;
	kal_uint32 current_time;
   kal_uint64 temp_value;

	current_time = drv_get_current_time();
	result = drv_get_duration_tick(previous_time, current_time);
   /* X ms = result x 1000/32K = (result x 125)>>12 */
   temp_value = (kal_uint64)(((kal_uint64) result)*125);
	result = (kal_uint32)(temp_value>>12);
	return result;
}

#ifdef DRV_TIMING_DEBUG
DRV_DBG_STRUCT  DRV_DBG_INFO_DATA;

kal_uint32 drv_get_gpt_current_time(void)
{
   //0x80100020, enable!!
   #if defined(DRV_GPT_GPT3)
	return (DRV_MISC_Reg32(0x80100020));
	#else /*DRV_GPT_GPT3*/
	return (DRV_MISC_Reg32(0x80200230));
	#endif   /*DRV_GPT_GPT3*/
}

kal_uint32 drv_get_gpt_duration_tick(kal_uint32 previous_time)
{
   #if defined(DRV_GPT_GPT3)
   kal_uint32 current_time = DRV_MISC_Reg32(0x80100020);
	kal_uint32 result;

	if (previous_time > current_time)
	{
		result = 0x10000 - previous_time + current_time;
	}
	else
	{
		result = current_time - previous_time;
	}
	return result;
	#else /*DRV_GPT_GPT3*/
	kal_uint32 current_time = DRV_MISC_Reg32(0x80200230);
	kal_uint32 result;
	if (previous_time > current_time)
	{
		result = 0x80000 - previous_time + current_time;
	}
	else
	{
		result = current_time - previous_time;
	}
	return result;
	#endif   /*DRV_GPT_GPT3*/
}

kal_uint32 drv_get_gpt_duration_ms(kal_uint32 previous_time)
{
   #if defined(DRV_GPT_GPT3)
	kal_uint32 result;
	result = drv_get_duration_tick(previous_time);
	return result;
	#else /*DRV_GPT_GPT3*/
	kal_uint32 result;
	result = drv_get_duration_tick(previous_time);
	result*=1000;
	result/=32768;
	return result;
	#endif   /*DRV_GPT_GPT3*/
}
#endif  /*DRV_TIMING_DEBUG*/

#ifdef DRV_MEMORY_TRACE_DEBUG
DRV_DBG_STRUCT DRV_DBG_INFO_DATA;
/*drv_dbg_trace(NAND_READ_START,drv_get_current_time(),0,0);*/
void drv_dbg_trace(kal_uint16 index, kal_uint32 time, kal_uint32 data1, kal_uint32 data2)
{
   kal_uint32        savedMask;
   savedMask = SaveAndSetIRQMask();
   {
      DRV_DBG_INFO_DATA.dbg_data[DRV_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_DBG_INFO_SIZE-1)].tag = index;
      DRV_DBG_INFO_DATA.dbg_data[DRV_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_DBG_INFO_SIZE-1)].time = time;
      DRV_DBG_INFO_DATA.dbg_data[DRV_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_DBG_INFO_SIZE-1)].data1 = data1;
      DRV_DBG_INFO_DATA.dbg_data[DRV_DBG_INFO_DATA.dbg_data_idx&(MAX_DRV_DBG_INFO_SIZE-1)].data2 = data2;
      DRV_DBG_INFO_DATA.dbg_data_idx++;
   }
   RestoreIRQMask(savedMask);
}
#endif   /*DRV_MEMORY_TRACE_DEBUG*/

/*************************************************************************
   APIs for driver debugging
*************************************************************************/
#if defined(__TST_MODULE__)
#if (!defined(MTK_KAL_MNT))&&(!defined(KAL_ON_OSCAR))&&(!defined(MCD_DLL_EXPORT))&&(!defined(L1_SIM))&&(!defined(__FUE__))
void drv_trace0(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type)
{
   if (INT_QueryExceptionStatus())
      return;
   if(kal_if_lisr() == KAL_TRUE)
      return;
   if(kal_if_hisr())
   {
     kal_dev_trace(trc_class, msg_index, arg_type);
   }
   else
   {
     kal_trace(trc_class, msg_index, arg_type);
   }
}

void drv_trace1(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type, kal_uint32 data1)
{
   if (INT_QueryExceptionStatus())
      return;
   if(kal_if_lisr() == KAL_TRUE)
      return;
   if(kal_if_hisr())
   {
     kal_dev_trace(trc_class, msg_index, arg_type, data1);
   }
   else
   {
     kal_trace(trc_class, msg_index, arg_type, data1);
   }
}

void drv_trace2(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type, kal_uint32 data1, kal_uint32 data2)
{
   if (INT_QueryExceptionStatus())
      return;
   if(kal_if_lisr() == KAL_TRUE)
      return;
   if(kal_if_hisr())
   {
     kal_dev_trace(trc_class, msg_index, arg_type, data1, data2);
   }
   else
   {
     kal_trace(trc_class, msg_index, arg_type, data1, data2);
   }
}

void drv_trace4(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type, kal_uint32 data1, kal_uint32 data2, kal_uint32 data3, kal_uint32 data4)
{
   if (INT_QueryExceptionStatus())
      return;
   if(kal_if_lisr() == KAL_TRUE)
      return;
   if(kal_if_hisr())
   {
     kal_dev_trace(trc_class, msg_index, arg_type, data1, data2, data3, data4);
   }
   else
   {
     kal_trace(trc_class, msg_index, arg_type, data1, data2, data3, data4);
   }
}

void drv_trace8(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type, kal_uint32 data1, kal_uint32 data2, kal_uint32 data3, kal_uint32 data4,
                kal_uint32 data5, kal_uint32 data6, kal_uint32 data7, kal_uint32 data8)
{
   if (INT_QueryExceptionStatus())
      return;
   if(kal_if_lisr() == KAL_TRUE)
      return;
   if(kal_if_hisr())
   {
     kal_dev_trace(trc_class, msg_index, arg_type, data1, data2, data3, data4, data5, data6, data7, data8);
   }
   else
   {
     kal_trace(trc_class, msg_index, arg_type, data1, data2, data3, data4, data5, data6, data7, data8);
   }
}
#endif /* (!defined(MTK_KAL_MNT))&&(!defined(KAL_ON_OSCAR))&&(!defined(MCD_DLL_EXPORT))&&(!defined(L1_SIM))*/
#endif // #if defined(__TST_MODULE__)

kal_uint8 drv_dummy_return(void)
{
   return 0;
}

