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
 *   isrentry.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the IRQ service routines for all IRQ sources
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
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files.
 *******************************************************************************/

#include "reg_base.h"
#include "isrentry.h"
#include "intrCtrl.h"
#include "drv_comm.h"
#include "dcl.h"
#include "drv_hisr.h"
#include "kal_internal_api.h"
#include "tst_lmu_hw.h"

#ifdef __SWDBG_SUPPORT__
#include "swdbg_hw.h"
#endif   /* __SWDBG_SUPPORT__ */
#include "emi_hw.h"
#include "emi_sw.h"

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "us_timer.h"
#if defined(MT6290) && defined(__ARM7EJ_S__)
#include "drv_arm7cirq.h"
#else /* defined(MT6290) && defined(__ARM7EJ_S__) */
#include "drv_mdcirq.h"
#endif /* else of "defined(MT6290) && defined(__ARM7EJ_S__)" */
#include "devdrv_ls.h"
//#include "drv_features.h"
#include "SST_intrCtrl.h"
//#include "fake_api.h"
//#include "cpu.h"

/*************************************************************************
 * Define function prototypes and data structures.
 *************************************************************************/

void isrCTIRQ1(void);
extern kal_uint32 LockIRQ(void);
extern void RestoreIRQ(kal_uint32 irq);
extern kal_uint32 DisableIRQ(void);
extern void ReEnableIRQ(void);
extern void FIQClearInt(void);
extern void SYS_ClearInt(kal_uint8 code);
extern void SYS_endIsr(kal_uint8 irq_idx); /* LTE Update */
extern void isrSysTimer(void);

#ifndef L1_NOT_PRESENT
extern void L1I_FrameInterrupt( void );
extern kal_bool  L1I_Querry_Compensate_KAL_Timer( void );
#endif /* !L1_NOT_PRESENT */


extern kal_uint32 SA_LoggingIndex;
extern kal_bool SLA_IsLmuLogging(void);
extern void SLA_LoggingLISR(kal_uint32 ID);
extern void SLA_HookLogging(void);

#if defined(__TP_SUPPORT_TIMING_CHECK__)
extern kal_uint32 Thread_Protect_State;
extern kal_uint32 TP_Exclude_Start_Time;
#endif

#if defined(DEBUG_KAL) && defined(DEBUG_TIMER) && defined(__CR4__)
extern kal_uint32 TimerHISR_State;
extern kal_uint32 TimerHISR_Exclude_Start_Time;
#endif

/*************************************************************************
 * Define imported global data.
 *************************************************************************/

#if !defined(__NUCLEUS_VERSION_2__)
extern kal_uint32  TCD_Interrupt_Count;
#endif /* !__NUCLEUS_VERSION_2__ */

#if defined(__NUCLEUS_VERSION_2__)
extern void *TCD_Current_Thread;
#endif

#if defined __MALMO_ASM_SWTR__
extern kal_uint32 ST_MALMO_ASM_ChangeContextID();
#endif /* __MALMO_ASM_SWTR */  

extern kal_char *wake_tm_name;

#if defined(__UNIFIED_ISR_LEVEL__)
extern kal_hisrid intrID2hisrID[NUM_IRQ_SOURCES];
//extern DRV_HISR_STRUCT DRV_HISR_TABLE[NUM_IRQ_SOURCES];
#endif /* __UNIFIED_ISR_LEVEL__ */


/*************************************************************************
 * Define global data.
 *************************************************************************/

static IntErrType FIQErrInfo;

#ifdef  IRQ_GPII_CODE
static kal_bool nIRQ_auto_unmask = KAL_TRUE;
static VOID_FUNC nIRQ_CallBack_Function;
#endif
#ifdef  IRQ_GPI_CODE
static kal_bool nFIQ_auto_unmask = KAL_TRUE;
static VOID_FUNC nFIQ_CallBack_Function;
#endif

#if defined(MT6290) && defined(__ARM7EJ_S__)
DEVDRV_LS_COPRO_INTSRAM_ZI irqlisr_entry lisr_dispatch_tbl[NUM_IRQ_SOURCES];
DEVDRV_LS_COPRO_INTSRAM_ZI void       *processing_lisr;
DEVDRV_LS_COPRO_INTSRAM_RW kal_uint16 processing_irqx = IRQ_NOT_LISR_CONTEXT;
DEVDRV_LS_COPRO_INTSRAM_ZI kal_uint32 processing_irqlr;
DEVDRV_LS_COPRO_INTSRAM_ZI kal_uint32 processing_fiqlr;
DEVDRV_LS_COPRO_INTSRAM_ZI kal_uint32 processing_irqCnt;
#else /* defined(MT6290) && defined(__ARM7EJ_S__) */
DEVDRV_LS_INTSRAM_ZI irqlisr_entry lisr_dispatch_tbl[NUM_IRQ_SOURCES];
DEVDRV_LS_INTSRAM_ZI void       *processing_lisr;
DEVDRV_LS_INTSRAM_RW kal_uint16 processing_irqx = IRQ_NOT_LISR_CONTEXT;
DEVDRV_LS_INTSRAM_ZI kal_uint32 processing_irqlr;
DEVDRV_LS_INTSRAM_ZI kal_uint32 processing_fiqlr;
DEVDRV_LS_INTSRAM_ZI kal_uint32 processing_irqCnt;
#endif /* else of "defined(MT6290) && defined(__ARM7EJ_S__)" */

#if defined(__WAKEUP_IRQ_DEBUG__)
wkup_intr_log_t wkup_intr_log_buf[WKUP_LOG_BUF_MAX];
kal_uint32 wkup_intr_log_indx = WKUP_LOG_BUF_MAX;
wkup_timer_log_t wkup_timer_log_buf[WKUP_LOG_BUF_MAX];
kal_uint32 wkup_timer_log_indx = WKUP_LOG_BUF_MAX;
#endif  /* __WAKEUP_IRQ_DEBUG__ */

#ifdef __DEMAND_PAGING_PERFORMANCE_PROFILING__
extern void demp_preempt_time_start();
#endif

/* to measure time */
#define LISR_MEASURE_TIME 1
#if defined(LISR_MEASURE_TIME)
#if defined(__CR4__)
#include "cp15_int.h"
#elif defined(__MTK_MMU_V2__)
#include "mpu_mtk_mmu_v2_int.h"
#endif
#define IFDEF_LISR_MEASURE_TIME(x) x
kal_uint32 lisr_enter_time[NUM_IRQ_SOURCES];
kal_uint32 lisr_leave_time[NUM_IRQ_SOURCES];
#else
#define IFDEF_LISR_MEASURE_TIME(x)
#endif /* LISR_MEASURE_TIME */


/*************************************************************************
* FUNCTION
*  IRQ_LISR_Init
*
* DESCRIPTION
*   This function implement IRQ's LISR (Low-level Interrupt Service Routine)
*  Table initialization.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void IRQ_LISR_Init()
{
#if !defined(__UNIFIED_ISR_LEVEL__)
   kal_uint32 i;
   for (i = NUM_IRQ_SOURCES; i != 0; i--) {
      IRQ_Register_LISR(i - 1, IRQ_Default_LISR, "NULL handler");
   }
#endif /* __UNIFIED_ISR_LEVEL__ */

   /* Set CTIRQ1 handler */
#if !defined(L1_NOT_PRESENT) && !defined(ATEST_DRV_ENVIRON)
   IRQ_Register_LISR(IRQ_CTIRQ1_CODE, isrCTIRQ1,"CTIRQ1");
#endif/* L1_NOT_PRESENT */
   /* Set system timer handler */

#if !defined(__EVENT_BASED_TIMER__)
   IRQ_Register_LISR(IRQ_SYS_TIMER_CODE, isrSysTimer,"SysTimer");
#endif /* __EVENT_BASED_TIMER__ */
}

/*************************************************************************
* FUNCTION
*  IRQ_Register_LISR
*
* DESCRIPTION
*   This function implement method to register IRQ's LISR.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  irqvector   -  vector number to register
*  reg_lisr    -  register LISR's handler
*  description -  LISR's description pointer to be saved.
*     Remember, the routine won't duplicate the description,
*     therefore, caller shouldn't free the description.
*
* RETURNS
*
*************************************************************************/
void IRQ_Register_LISR_2(kal_uint32 irqvector, void (*reg_lisr)(kal_uint32), char* description)
//void IRQ_Register_LISR(kal_uint32 irqvector, void (*reg_lisr)(kal_uint32), char* description)
{
   kal_uint32 savedMask;

   savedMask = LockIRQ();
   lisr_dispatch_tbl[irqvector].vector = irqvector;
   lisr_dispatch_tbl[irqvector].lisr_handler = reg_lisr;
   lisr_dispatch_tbl[irqvector].description = description;
   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  IRQ_Retrieve_LISR
*
* DESCRIPTION
*   This function implement to retrieve register LISR handler
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void* IRQ_Retrieve_LISR(kal_uint32 vector)
{
   return(void*)(lisr_dispatch_tbl[vector].lisr_handler);
}

/*************************************************************************
* FUNCTION
*  IRQ_Default_LISR
*
* DESCRIPTION
*   This function implement default IRQ' LISR
*
* CALLS
*
* CALL BY
*  IRQ_LISR_Init()
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void IRQ_Default_LISR(void)
{
   kal_fatal_error_handler(KAL_ERROR_NON_REGISTERED_LISR, (kal_uint32)processing_irqx);
}

#if !defined(__SSDVT_TEST__)
/*************************************************************************
* FUNCTION
*  INT_FIQ_Lisr
*
* DESCRIPTION
*   This function implement FIQ handler
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void INT_FIQ_Lisr(void)
{
   kal_uint8  FIQ_Enter=1;
   
   if (KAL_FALSE == SLA_IsLmuLogging())
   {
      LMU_Write_ISR_CSM(0xaaaa0fff);
   }
   if (SA_LoggingIndex != 0)
   {
      SLA_LoggingLISR(0xaaaa0fff);
   }

     FIQErrInfo.fiqSelect = FIQ_isValid();
     FIQErrInfo.irqReturnAddr = processing_irqlr;
     FIQErrInfo.fiqReturnAddr = processing_fiqlr;

   if (KAL_FALSE == SLA_IsLmuLogging())
   {
      LMU_Write_ISR_END_CSM(0xaaaaaaaa);
   }
   if (SA_LoggingIndex != 0)
   {
      SLA_LoggingLISR(0xaaaaaaaa);
   }
     
   EXT_ASSERT(FIQ_Enter==0, FIQErrInfo.fiqSelect, FIQErrInfo.fiqReturnAddr, FIQErrInfo.irqReturnAddr);
}
#else
void INT_FIQ_Lisr(void)
{
    /* SSDVT FIQ isr */
    FIQ_C_ISR();
}
#endif


void INT_Timer_Interrupt(void)
{
    Kal_Timer_Interrupt();
}

//#if defined(__LTE_SM__)

/*************************************************************************
* FUNCTION
*  isrCTIRQ1, isrCTIRQ1_USBPowerOn
*
* DESCRIPTION
*   This function implement CTIRQ1 LISR
*
* CALLS
*
* CALL BY
*  IRQ_LISR_Init()
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#if defined(MT6290) && defined(__ARM7EJ_S__)
void DEVDRV_LS_COPRO_INTSRAM_ROCODE isrCTIRQ1(void)
#else /* defined(MT6290) && defined(__ARM7EJ_S__) */
void DEVDRV_LS_INTSRAM_ROCODE isrCTIRQ1(void)
#endif /* else of "defined(MT6290) && defined(__ARM7EJ_S__)" */
{
   /* set EMI arbitrator to hard mode for GMC before running the hard real-time app */
#if defined(__DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__)
   EMI_Set_GMCBW_HardMode();
#endif  /* __DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__ */

#ifndef L1_NOT_PRESENT
   L1I_FrameInterrupt();
#endif /* !L1_NOT_PRESENT */

   /* restore EMI arbitrator to soft mode for GMC before running the hard real-time app */
#if defined(__DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__)
   EMI_Set_GMCBW_SoftMode();
#endif  /* __DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__ */

/* For MT6268 2G/3G or 2G Single project: timer interrupt is moved to l1csm.c for Dual/Single OS Tick mechanism  */
#if !defined(__NEW_OS_TICK__) && !defined(__CENTRALIZED_SLEEP_MANAGER__)
   Kal_Timer_Interrupt();

/* RTOS tick compensation by L1 */
#ifndef L1_NOT_PRESENT
   if (L1I_Querry_Compensate_KAL_Timer()==KAL_TRUE)
   Kal_Timer_Interrupt();
#endif /* !L1_NOT_PRESENT */

#elif defined(__MAUI_BASIC__) && !defined(__CENTRALIZED_SLEEP_MANAGER__)

   Kal_Timer_Interrupt();

#endif   /* !__NEW_OS_TICK__ */

   /*KTEST: start timer tick in target full load if not event based timer!*/
#if defined(__KTEST__) && !defined(__MAUI_BASIC__) && !defined(__CENTRALIZED_SLEEP_MANAGER__)
   Kal_Timer_Interrupt();
#endif/*__KTEST__*/

#ifdef FIQ
   FIQClearInt();
#endif
}

/* isrCTIRQ1 would not be trapped because L1 task is disabled in USB boot mode; */
/* This is specific for USB boot mode, would be registered in initialize(). */
#ifdef __USB_ENABLE__
void isrCTIRQ1_USBPowerOn(void)
{
   Kal_Timer_Interrupt();
}
#endif   /*__USB_ENABLE__*/

//#endif /* !defined(__LTE_SM__) */


/*************************************************************************
* FUNCTION
*  isrC_Main
*
* DESCRIPTION
*   This function implement IRQ's LISR main dispatch routine
*
* CALLS
*
* CALL BY
*  INT_IRQ_Parse()
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#if !defined(__SSDVT_TEST__)
#if defined(MT6290) && defined(__ARM7EJ_S__)
void DEVDRV_LS_COPRO_INTSRAM_ROCODE isrC_Main(kal_uint32 irqx)
#else /* defined(MT6290) && defined(__ARM7EJ_S__) */
void DEVDRV_LS_INTSRAM_ROCODE isrC_Main(kal_uint32 irqx)
#endif /* else of "defined(MT6290) && defined(__ARM7EJ_S__)" */
{
#if defined(__UNIFIED_ISR_LEVEL__)
//   kal_hisr processing_ehisrid;
   kal_hisrid processing_hisrid;
#else /* __UNIFIED_ISR_LEVEL__ */
   void       *processing_lisr_backup;
   kal_uint16 processing_irqx_backup;

   processing_lisr_backup = processing_lisr;
   processing_irqx_backup = processing_irqx;
#endif /* __UNIFIED_ISR_LEVEL__ */

   processing_irqx = irqx;
   processing_lisr = (void*)lisr_dispatch_tbl[irqx].lisr_handler;
   processing_irqCnt++;
   
#if defined __MALMO_ASM_SWTR__
	ST_MALMO_ASM_ChangeContextID();
#endif /* __MALMO_ASM_SWTR */  
   
   if (KAL_FALSE == SLA_IsLmuLogging())
   {
      LMU_Write_ISR_CSM(0xaaaa0000 | ((kal_uint32)processing_irqx));
   }
   if (SA_LoggingIndex != 0)
   {
      SLA_LoggingLISR(0xaaaa0000 | ((kal_uint32)processing_irqx));
   }

   CPU_SET_CONTEXT_ID(0xaaaa0000 | ((kal_uint32)processing_irqx));

#ifdef __SWDBG_SUPPORT__
   *SWDBG_MPCON = ((irqx + 0x100) << 16) | 0x8000;
#endif   /* __SWDBG_SUPPORT__ */

#ifdef __WAKEUP_IRQ_DEBUG__
   if (wkup_intr_log_indx != WKUP_LOG_BUF_MAX) {
      wkup_intr_log_buf[wkup_intr_log_indx].irq = processing_irqx;
      wkup_intr_log_indx++;
      if (wkup_intr_log_indx == WKUP_LOG_BUF_MAX) {
         wkup_intr_log_indx = 0;
      }
   }
   if (wkup_timer_log_indx != WKUP_LOG_BUF_MAX) {
      if (wake_tm_name != NULL) {
         wkup_timer_log_buf[wkup_timer_log_indx].timer_name = wake_tm_name;
         wake_tm_name = NULL;
         wkup_timer_log_indx++;
         if (wkup_timer_log_indx == WKUP_LOG_BUF_MAX) {
            wkup_timer_log_indx = 0;
         }
      }
   }
#endif  /* __WAKEUP_IRQ_DEBUG__ */

#if defined(DEBUG_KAL) && defined(DEBUG_TIMER) && defined(__CR4__)
   if(TimerHISR_State == 1)
   {
       GET_CURRENT_TIME(TimerHISR_Exclude_Start_Time);
       TimerHISR_State = 2;
   }
#endif

#if defined(__TP_SUPPORT_TIMING_CHECK__)
   if(Thread_Protect_State==1)
   {
       Thread_Protect_State=2;
       TP_Exclude_Start_Time = ust_get_current_time();
   }
#endif

#ifdef __DEMAND_PAGING_PERFORMANCE_PROFILING__   
   demp_preempt_time_start();
#endif

#if defined(__UNIFIED_ISR_LEVEL__)
//   processing_ehisrid = intrID2hisrEID[irqx];
//   ASSERT(0xFF != processing_ehisrid);
//   processing_hisrid = hisrid_g[processing_ehisrid];
   if(DRV_ERROR_HISR != DRV_HISR_TABLE[irqx].hisr_func)
   {
	   drv_active_hisr(irqx);
   }
   else
   {
      processing_hisrid = intrID2hisrID[irqx];
//      ASSERT(NULL != processing_hisrid);
      EXT_ASSERT(NULL != processing_hisrid, irqx, processing_irqCnt, (kal_uint32)processing_lisr);
      kal_activate_hisr(processing_hisrid);
   }
   /* no nested interrupt */
   processing_lisr = NULL;
   processing_irqx = IRQ_NOT_LISR_CONTEXT;
#else  /* __UNIFIED_ISR_LEVEL__ */
   ReEnableIRQ();
#if defined(__CR4__)
   IFDEF_LISR_MEASURE_TIME(CP15_PMU_GET_CYCLE_CNT(lisr_enter_time[irqx]));
#elif defined(__MTK_MMU_V2__)
   IFDEF_LISR_MEASURE_TIME(lisr_enter_time[irqx]=CACHE_FREE_RUN_CYCLE_COUNTER_GET_CYCLE());
#endif
   lisr_dispatch_tbl[irqx].lisr_handler(irqx);
#if defined(__CR4__)
   IFDEF_LISR_MEASURE_TIME(CP15_PMU_GET_CYCLE_CNT(lisr_leave_time[irqx]));
#elif defined(__MTK_MMU_V2__)
   IFDEF_LISR_MEASURE_TIME(lisr_leave_time[irqx]=CACHE_FREE_RUN_CYCLE_COUNTER_GET_CYCLE());
#endif
   DisableIRQ();
   processing_irqx = processing_irqx_backup;
   processing_lisr = processing_lisr_backup; 
#endif /* __UNIFIED_ISR_LEVEL__ */
   
   if (KAL_FALSE == SLA_IsLmuLogging())
   {
      LMU_Write_ISR_END_CSM(0xaaaaaaaa);
   }
   if (SA_LoggingIndex != 0)
   {
      SLA_LoggingLISR(0xaaaaaaaa);
   }
   CPU_SET_CONTEXT_ID(0xaaaaaaaa);

   #if defined __MALMO_ASM_SWTR__
	ST_MALMO_ASM_ChangeContextID();
   #endif /* __MALMO_ASM_SWTR */  
   
   /* Binary-coded IRQ idx */
   SYS_endIsr((kal_uint8)irqx);

}

#else    /* __SSDVT_TEST__ */
void isrC_Main(void)
{
extern void CM_isrC_Main();
    CM_isrC_Main();
}
#endif    /* __SSDVT_TEST__ */

void No_Context_Switch()
{
   if (KAL_FALSE == SLA_IsLmuLogging())
   {
      LMU_Write_ISR_END_RESUME_CSM(0xbbbbbbbb);
   }
   if (SA_LoggingIndex != 0)
   {
      SLA_LoggingLISR(0xbbbbbbbb);
      CPU_SET_CONTEXT_ID(0xbbbbbbbb);
   }
        
#if defined(__NUCLEUS_VERSION_2__)
    if( SA_LoggingIndex != 0 ) 
    {
	    SLA_HookLogging();
    }
    LMU_Write_Task_CSM((unsigned int)TCD_Current_Thread);
#endif   
}

/*************************************************************************
* FUNCTION
*  isrSysTimer
*
* DESCRIPTION
*   This function implement CTIRQ1 LISR
*
* CALLS
*
* CALL BY
*  IRQ_LISR_Init()
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void isrSysTimer(void)
{
   /* set EMI arbitrator to hard mode for GMC before running the hard real-time app */
#if defined(__DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__)
   EMI_Set_GMCBW_HardMode();
#endif  /* __DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__ */

#if !defined(__LTE_SM__)
#ifndef L1_NOT_PRESENT
   L1I_FrameInterrupt();
#endif /* !L1_NOT_PRESENT */
#endif /* !defined(__LTE_SM__) */

   /* restore EMI arbitrator to soft mode for GMC before running the hard real-time app */
#if defined(__DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__)
   EMI_Set_GMCBW_SoftMode();
#endif  /* __DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__ */

/* For MT6268 2G/3G or 2G Single project: timer interrupt is moved to l1csm.c for Dual/Single OS Tick mechanism  */
#if !defined(__NEW_OS_TICK__) && !defined(__CENTRALIZED_SLEEP_MANAGER__)
   Kal_Timer_Interrupt();

#elif (defined(__MAUI_BASIC__)||defined(__LTE_SM__)) && !defined(__CENTRALIZED_SLEEP_MANAGER__)

   Kal_Timer_Interrupt();

   /*KTEST: start timer tick in target full load if not event based timer!*/
#elif defined(__KTEST__) && !defined(__MAUI_BASIC__) && !defined(__CENTRALIZED_SLEEP_MANAGER__) && defined(__NEW_OS_TICK__)

   Kal_Timer_Interrupt();

#endif   /* !__NEW_OS_TICK__ */

#if defined(MT6290) && defined(__ARM7EJ_S__)
   // need to clear pulse interrupt by driver ISR when using arm7cirq
   IRQClearInt(ARM7_IRQID_MDGPTM4);
#endif /* end of "defined(MT6290) && defined(__ARM7EJ_S__)" */

#ifdef FIQ
   FIQClearInt();
#endif
}


/*************************************************************************
* FUNCTION
*  get_wkup_intr_log_buf
*
* DESCRIPTION
*  This function gets the wakeup logging buffer's address, current index, 
*  and max count.
*  NoteXXX: An IRQ may wake up the system and break the sleep mode.
*           When the debugging option is enabled, all interrupts are
*           logged. User can check all IRQ numbers in the logging 
*           buffer to see which IRQ wakes up the system.
*
* PARAMETERS
*  buf    -   pointer to buffer address
*  indx   -   pointer to buffer index
*  max    -   pointer to buffer max count
*
* RETURNS
*  0 if the IRQ logging buffer exists; otherwise, -1
*
*************************************************************************/
kal_int32 get_wkup_intr_log_buf(wkup_intr_log_t **buf, kal_uint32 *indx, kal_uint32 *max)
{
#if defined(__WAKEUP_IRQ_DEBUG__)

   *buf = (wkup_intr_log_t *)wkup_intr_log_buf;
   *indx = wkup_intr_log_indx;
   *max = WKUP_LOG_BUF_MAX;
    
   return 0;

#endif  /* __WAKEUP_IRQ_DEBUG__ */

   return -1;
}

/*************************************************************************
* FUNCTION
*  get_wkup_timer_log_buf
*
* DESCRIPTION
*  This function gets the wakeup logging buffer's address, current index, 
*  and max count.
*
* PARAMETERS
*  buf    -   pointer to buffer address
*  indx   -   pointer to buffer index
*  max    -   pointer to buffer max count
*
* RETURNS
*  0 if the IRQ logging buffer exists; otherwise, -1
*
*************************************************************************/
kal_int32 get_wkup_timer_log_buf(wkup_timer_log_t **buf, kal_uint32 *indx, kal_uint32 *max)
{
#if defined(__WAKEUP_IRQ_DEBUG__)

   /* 
    * NonteXXX: No need to disable IRQ before accessing wake_tm_name.
    *           get_wkup_timer_log_buf is called by L1 LISR.
    *           wake_tm_name is also updated in L1 LISR.
    */
   if (wake_tm_name != NULL) {
      wkup_timer_log_buf[wkup_timer_log_indx].timer_name = wake_tm_name;
      wake_tm_name = NULL;
      wkup_timer_log_indx++;
      if (wkup_timer_log_indx == WKUP_LOG_BUF_MAX) {
         wkup_timer_log_indx = 0;
      }
   }

   *buf = (wkup_timer_log_t *)wkup_timer_log_buf;
   *indx = wkup_timer_log_indx;
   *max = WKUP_LOG_BUF_MAX;
    
   return 0;

#endif  /* __WAKEUP_IRQ_DEBUG__ */

   return -1;
}

/*************************************************************************
* FUNCTION
*  enable_wkup_log
*
* DESCRIPTION
*  This function enables wakeup logging.
*
* PARAMETERS
*  None
*
* RETURNS
*  0 if the IRQ logging buffer exists; otherwise, -1
*
*************************************************************************/
kal_int32 enable_wkup_log(void)
{
#if defined(__WAKEUP_IRQ_DEBUG__)

   wkup_intr_log_indx = 0;
   wkup_timer_log_indx = 0;

   return 0;

#endif  /* __WAKEUP_IRQ_DEBUG__ */

   return -1;
}

/*************************************************************************
* FUNCTION
*  IRQ_Current_LISR()
*
* DESCRIPTION
*  This function returns IRQ code of current executing LISR.
*
* PARAMETERS
*  None
*
* RETURNS
*  IRQ code if current context is LISR.
*  Otherwise, IRQ_NOT_LISR_CONTEXT (-1)
*
*************************************************************************/
kal_uint16 IRQ_Current_LISR()
{
    kal_uint32 current_irq;
 
    /* When nested interrupt happens, processing_irqx of preempted IRQ will be modified to new IRQ, */
    /* but it will be restored to the original one before context switch to the preempted IRQ.      */
    /* Therefore, no need to protect it with LockIRQ and RestoreIRQ.                                */
    current_irq = processing_irqx;
     
    if(IRQ_NOT_LISR_CONTEXT == current_irq)
    {
        return IRQ_NOT_LISR_CONTEXT;
    }
    else
    {
        return (kal_uint16)current_irq;
    }
}
