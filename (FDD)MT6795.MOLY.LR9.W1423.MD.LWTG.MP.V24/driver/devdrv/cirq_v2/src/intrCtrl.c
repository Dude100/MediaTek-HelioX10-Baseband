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


/*****************************************************************************
 *
 * Filename:
 * ---------
 *   intrCtrl.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   This Module defines the initialization of intrCtrl.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * Include header files
 *******************************************************************************/

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "drv_comm.h"
#include "drv_mdcirq.h"
#include "sync_data.h"
#include "toolchain_dep.h"


/*******************************************************************************
 * Define global data
 *******************************************************************************/

kal_uint32 irq_mask_caller;
kal_uint32 irq_unmask_caller;
kal_uint8 irq_mask_monitor_idx = NUM_IRQ_SOURCES;
kal_uint8 irq_unmask_monitor_idx = NUM_IRQ_SOURCES;

/*******************************************************************************
 * Declare import function prototype 
 *******************************************************************************/
extern kal_uint32 LockIRQ(void);
extern void RestoreIRQ(kal_uint32 irq);
extern kal_bool INT_QueryExceptionStatus(void);

/*************************************************************************
* FUNCTION
*  IRQDirectMaskAll
*
* DESCRIPTION
*  Mask all of the interrupts with direct indexing.
*
* IMPORTANT NOTICE
*  Reserved for system service only!
*  used while system error
*  such as fatal error, assertion failure and CPU triggered excetpion.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
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
#endif

#if !defined(__CIRQ_DESIGN_NEW__)

/*************************************************************************
* FUNCTION
*  FIQSel
*
* DESCRIPTION
*  Reserved for system service only!
*  Selection of FIQ.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void FIQSel(void)
{
	kal_uint32 fiq;

	fiq = DRV_Reg32(MDCIRQ_FIQCONR);
	DRV_WriteReg32(MDCIRQ_FIQCONR, fiq | MDCIRQ_FIQCONR_FIQ_SEL(0));
}

/*************************************************************************
* FUNCTION
*  FIQMask
*
* DESCRIPTION
*  Reserved for system service only!
*  Mask FIQ
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void FIQMask(void)
{
	kal_uint32 fiq;

	fiq = DRV_Reg32(MDCIRQ_FIQCONR);
	DRV_WriteReg32(MDCIRQ_FIQCONR, MDCIRQ_FIQCONR_FIQ_MASK | fiq);
}

/*************************************************************************
* FUNCTION
*  FIQUnmask
*
* DESCRIPTION
*  Reserved for system service only!
*  Unmask FIQ
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void FIQUnmask(void)
{
	kal_uint32 fiq;

	fiq = DRV_Reg32(MDCIRQ_FIQCONR);
	DRV_WriteReg32(MDCIRQ_FIQCONR, (~MDCIRQ_FIQCONR_FIQ_MASK) & fiq);
}

/*************************************************************************
* FUNCTION
*  FIQClearInt
*
* DESCRIPTION
*  Reserved for system service only!
*  Clear FIQ
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void FIQClearInt(void)
{
   //*FIQ_EOI = 0x0001;
}

/*************************************************************************
* FUNCTION
*  FIQSensitivity
*
* DESCRIPTION
*  Setting sensitivity of FIQ
*
* PARAMETERS
*  Either edge active low or level active low
*
* RETURNS
*
*************************************************************************/
void FIQSensitivity(kal_bool edge)
{
}

#endif   /* !defined(__CIRQ_DESIGN_NEW__) */



/*************************************************************************
* FUNCTION
*  IRQMask
*
* DESCRIPTION
*  Mask certain interrupt source.
*
* PARAMETERS
*  Interrupt source to be masked, it is indexed via IRQCode2Line.
*
* RETURNS
*
*************************************************************************/
void IRQMask(kal_uint8 code)
{

   kal_uint32 savedMask;

   /* get the return address */
   if (code == irq_mask_monitor_idx)
   {
      GET_RETURN_ADDRESS(irq_mask_caller);
   }
   
   /*
    * [Important]
    * IRQ mask will be valid around 2T ~ 3T after register is written. 
    * To ensure IRQ is turned off thoroughly, I bit must be disabled in 
    * advanced; otherwise, IRQ may be triggered unexpectedly.
    */
   savedMask = LockIRQ();
   
   MDCIRQ_WrSetRegBit_Vector_NPW(MDCIRQ_IMSR_BASE, code);
   Data_Sync_Barrier();

   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  IRQUnmask
*
* DESCRIPTION
*  Unmask certain interrupt source.
*
* PARAMETERS
*  Interrupt source to be unmasked, it is indexed via IRQCode2Line.
*
* RETURNS
*
*************************************************************************/
void IRQUnmask(kal_uint8 code)
{
   kal_uint32 savedMask;

   // No IRQ unmasking allowed if exception handler is running
   if(INT_QueryExceptionStatus()==KAL_TRUE)
   {
      return;
   }

   /* get the return address */
   if (code == irq_unmask_monitor_idx)
   {
      GET_RETURN_ADDRESS(irq_unmask_caller);
   }
   
   savedMask = LockIRQ();
   
   MDCIRQ_WrClrRegBit_Vector_NPW(MDCIRQ_IMCR_BASE, code);
   Data_Sync_Barrier();

   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  IRQ_Status
*
* DESCRIPTION
*  query the value of interrupt status register
*
* PARAMETERS
*
* RETURNS
*  current highest priority
*
*************************************************************************/
kal_uint32 LS_INTSRAM_ROCODE IRQ_Status(void)
{
      return DRV_Reg32(MDCIRQ_INTID_CURR);
}


/*************************************************************************
* FUNCTION
*  FIQ_isValid
*
* DESCRIPTION
*  query if the FIQ is valide
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 FIQ_isValid(void)
{
   return 0xFFFFFFFFU;
}


/*************************************************************************
* FUNCTION
*  CTIRQ1_2_MaskAll
*
* DESCRIPTION
*  Mask all of the interrupts except CTIRQ1 and CTIRQ2.

* IMPORTANT NOTICE
*  This is specific for L1, and must be used in paired with 
*  CTIRQ1_2_MaskAll().
*
* PARAMETERS
*
* RETURNS
*  Current interrupt mask value.
*
*************************************************************************/
void CTIRQ1_2_MaskAll(IRQ_MASK_VALUE_T *val)
{
	/* LTE Remove..  TBC... */
}

/*************************************************************************
* FUNCTION
*  CTIRQ1_2_Restore
*
* DESCRIPTION
*  Restore interrupt mask saved by CTIRQ1_2_MaskAll().

* IMPORTANT NOTICE
*  This is specific for L1, and must be used in paired with 
*  CTIRQ1_2_MaskAll().
*
* PARAMETERS
*  Interrupt mask to be restored
*
* RETURNS
*
*************************************************************************/
void CTIRQ1_2_Restore(IRQ_MASK_VALUE_T *val)
{
   /* LTE Remove..  TBC... */
}


/*************************************************************************
* FUNCTION
*  SetINTMask
*
* DESCRIPTION
*  This function mask interrupt line and returned special pattern.
*
* PARAMETERS
*  code : Interrupt source of interrupt controller
*
* RETURNS
*  
*  
*************************************************************************/
void SetINTMask(kal_uint8 code)
{
   kal_uint32 savedMask;

    /*
    * [Important]
    * IRQ mask will be valid around 2T ~ 3T after register is written. 
    * To ensure IRQ is turned off thoroughly, I bit must be disabled in 
    * advanced; otherwise, IRQ may be triggered unexpectedly.
    */
   
   savedMask = LockIRQ();
   
   MDCIRQ_WrSetRegBit_Vector_NPW(MDCIRQ_IMSR_BASE, code);
   Data_Sync_Barrier();

   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  RestoreINTMask
*
* DESCRIPTION
*  This function unmask interrupt line and .
*
* PARAMETERS
*  code : Interrupt source of interrupt controller
*
* RETURNS
*  none
*  
*************************************************************************/
void RestoreINTMask(kal_uint8 code)
{
   kal_uint32 savedMask;
  
   savedMask = LockIRQ();
   
   MDCIRQ_WrClrRegBit_Vector(MDCIRQ_IMCR_BASE, code);
   Data_Sync_Barrier();

   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  IRQ_SetSWRegister
*
* DESCRIPTION
*  This function set SW interrupt register
*
* PARAMETERS
*  code : Interrupt source of interrupt controller
*
* RETURNS
*  none
*  
*************************************************************************/
void IRQ_SetSWRegister(kal_uint8 code)
{
   kal_uint32 savedMask;

   ASSERT(code<NUM_IRQ_SOURCES);
   savedMask = LockIRQ();
   MDCIRQ_SetRegBit_Vector(MDCIRQ_ISTR_BASE, code);
   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  IRQ_ResetSWRegister
*
* DESCRIPTION
*  This function reset SW interrupt register
*
* PARAMETERS
*  code : Interrupt source of interrupt controller
*
* RETURNS
*  none
*  
*************************************************************************/
void IRQ_ResetSWRegister(kal_uint8 code)
{
   kal_uint32 savedMask;

   ASSERT(code<NUM_IRQ_SOURCES);
   savedMask = LockIRQ();
   MDCIRQ_ClrRegBit_Vector(MDCIRQ_ISTR_BASE, code);
   RestoreIRQ(savedMask);
}

#if defined(__ENABLE_SW_TRIGGER_INTERRUPT__)

/*************************************************************************
* FUNCTION
*  Activate_LISR
*
* DESCRIPTION
*  This function activate SW interrupt lisr
*
* PARAMETERS
*  handle : handler of software trigger interrupt 
*
* RETURNS
*  none
*  
*************************************************************************/
void Activate_LISR(SW_CODE_HANDLE handle)
{
   kal_uint32 savedMask;
   
   /*ASSERT(handle >= NUM_IRQ_SOURCES);
   handle = handle - NUM_IRQ_SOURCES;
   ASSERT(handle < (SW_HANDLE_END - NUM_IRQ_SOURCES));*/ /* LTE Remove */

   savedMask = LockIRQ();
   
   SW_INT_Counter[handle]++;
   if(SW_INT_Counter[handle]==1){
      //IRQ_SetSWRegister(SW_Code_Handle2Code[handle]);  /* LTE Remove */
      IRQ_SetSWRegister(handle);
   }
   
   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  Deactivate_LISR
*
* DESCRIPTION
*  This function deactivate SW interrupt lisr
*
* PARAMETERS
*  handle : handler of software trigger interrupt 
*
* RETURNS
*  none
*  
*************************************************************************/
void Deactivate_LISR(SW_CODE_HANDLE handle)
{
   kal_uint32 savedMask;

   /*ASSERT(handle >= NUM_IRQ_SOURCES);
   handle = handle - NUM_IRQ_SOURCES;
   ASSERT(handle < (SW_HANDLE_END - NUM_IRQ_SOURCES));*/  /* LTE Remove */

   savedMask = LockIRQ();

   SW_INT_Counter[handle]--;
   if(SW_INT_Counter[handle]==0){
      //IRQ_ResetSWRegister(SW_Code_Handle2Code[handle]);  /* LTE Remove */
      IRQ_ResetSWRegister(handle);
   }
   
   RestoreIRQ(savedMask);

}

//#define MEASURE_ISR_PERIOD_ENABLE 1
#ifdef MEASURE_ISR_PERIOD_ENABLE
/*************************************************************************
* FUNCTION
*  Measure_ISR_Period
*
* DESCRIPTION
*  This function measure the ISR execution time
*  It is invoked in task context, and the exceution time must include
*  the LISR, and the HISR is depend on the LISR designed. 
*  This function will corrupt interrupt status, do NOT use this function in 
*  normal release version
*
* PARAMETERS
*  Interrupt source to be measured.
*  User must provide the interrupt source disable function
*
* RETURNS
*  Return the ISR execution time (PMUTick counts)
*  
*************************************************************************/
#include "cpu.h"
extern void ReEnableIRQ(void);
kal_uint32 Measure_ISR_Period(kal_uint8 code, void (*dis_irq)(void*), void *param)
{
   kal_uint32 savedMask;
   kal_uint32 t_start, t_end, duration;
   kal_uint32 i, delay;

   /* disable original hardware interrupt source */
   if(NULL != dis_irq)
   {
      dis_irq(param);
   }

   /* only enable (code) number interrupt */
   savedMask = LockIRQ();
   IRQMaskAll();
   
   MDCIRQ_SetRegBit_Vector(MDCIRQ_IMCR_BASE, code);
   MDCIRQ_SetRegBit_Vector_NPW(MDCIRQ_ISAR6332, code);
   Data_Sync_Barrier();

   /* software trigger interrupt */
   for(i = 0; i < 1; i++)
   {
      LockIRQ();
      MDCIRQ_SetRegBit_Vector(MDCIRQ_ISAR6332, code);
      MDCIRQ_SetRegBit_Vector_NPW(MDCIRQ_ISTR_BASE, code);
      Data_Sync_Barrier();
      for(delay = 0; delay < 100; delay++);
      cpu_event_counter_get_cycle(t_start);
      //RestoreIRQ(savedMask);
      ReEnableIRQ();
      cpu_event_counter_get_cycle(t_end);
      while(DRV_Reg32(MDCIRQ_IMSR3100)!=0);
   }
   RestoreIRQ(savedMask);
   duration = cpu_event_get_duration(t_start, t_end);
   return duration;
   //return (kal_uint32) CPU_PMUTICK2US(duration);

}
#endif /* end of MEASURE_ISR_PERIOD_ENABLE */

#endif /* end of __ENABLE_SW_TRIGGER_INTERRUPT__ */

