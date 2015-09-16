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
 *   drv_arm7cirq.c
 *
 * Project:
 * --------
 *   Moly
 *
 * Description:
 * ------------
 *   Low level interrupt controller driver
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 ****************************************************************************/


/******************************************************************************
 * Include header files
 ******************************************************************************/

#include "kal_public_api.h"
#include "cache_sw.h"
#include "intrCtrl.h"
#include "drv_comm.h"
#include "drv_arm7cirq.h"
#include "sync_data.h"
#include "devdrv_ls.h"


/******************************************************************************
 * Define global data
 ******************************************************************************/
kal_uint32 irq_mask_caller;
kal_uint32 irq_unmask_caller;
kal_uint8  irq_mask_monitor_idx = NUM_IRQ_SOURCES;
kal_uint8  irq_unmask_monitor_idx = NUM_IRQ_SOURCES;
kal_uint32 IRQMaskStatus;

#if defined(__ENABLE_SW_TRIGGER_INTERRUPT__)
    kal_uint32 SW_INT_Counter[NUM_IRQ_SOURCES];
    const kal_uint8 SW_Code_Handle2Code[NUM_IRQ_SOURCES] = 
    {
       #define X_SW_HANDLE_CONST(a, b, c) c,
           #include "intrCtrl_SW_Handle.h"
       #undef X_SW_HANDLE_CONST
    };
#endif /* __ENABLE_SW_TRIGGER_INTERRUPT__ */


static kal_uint8 SleepModeMaskCount=0;
static IRQ_MASK_VALUE_T SleepModeMask;
static IRQ_MASK_VALUE_T CTIRQ1_2_MaskValue;
static kal_uint8 INTMaskCount[NUM_IRQ_SOURCES];
static const kal_uint8 irq_priority_list[] = 
{
    INTERRUPT_PRIORITY_LIST
};


/*****************************************************************************
 * External function/variables                                               *
 *****************************************************************************/
extern void       ReEnableIRQ(void);
extern void       RestoreIRQ(kal_uint32 irq);
extern kal_bool   INT_QueryExceptionStatus(void);
extern kal_uint32 LockIRQ(void);



/*****************************************************************************
 * Function Declaration                                                      *
 *****************************************************************************/
void IRQClearAllInt(void);
void IRQDirectMaskAll(void);



/*****************************************************************************
 * Function Implementation - Low Layer                                       *
 *****************************************************************************/
void drv_arm7cirq_set_nested_interrupt_mode(kal_uint32 enable)
{
    if(enable)
    {
        DRV_WriteReg32(ARM7CIRQ_CTRL_REG, ARM7CIRQ_CTRL_REG_NESTED_INT_EN);
    }
    else
    {
        DRV_WriteReg32(ARM7CIRQ_CTRL_REG, 0);
    }
    Data_Sync_Barrier();
}

/* Reset as system default */
void drv_arm7cirq_reset(void)
{
    kal_int32 i;

    // Sensitivity: default is all pulse trigger
    DRV_WriteReg32(ARM7CIRQ_ISENR3100_REG, 0x00000000);

    // Clear Status Registers: if it is pulse trigger, the status is write one clear
    DRV_WriteReg32(ARM7CIRQ_ISAR3100_REG, 0xFFFFFFFF);

    // Clear Priority ACK Stack
    for( i = 0; i < ARM7CIRQ_TOTAL_PRI_LEVEL; i++ ){
        DRV_WriteReg32(ARM7CIRQ_SW_PRIACK_REG, 1);
    }

    // Mask All Interrupt Sources (default)
    DRV_WriteReg32(ARM7CIRQ_IMKR3100_REG, 0xFFFFFFFF);

    // Clear Software Trigger Interrupt
    DRV_WriteReg32(ARM7CIRQ_ISTR3100_REG, 0);

    // Fast Interrupt Request(FIQ) Setting
    DRV_WriteReg32(ARM7CIRQ_FIQCONR_REG, ARM7CIRQ_FIQCONR_FIQ_MASK | \
                       ARM7CIRQ_FIQCONR_FIQ_SEL(0));

    // Enable Nested Interrupt
    drv_arm7cirq_set_nested_interrupt_mode(ARM7CIRQ_CTRL_REG_NESTED_INT_EN);

    // Set Minimal Priority Level to Highest Priority
    // DRV_WriteReg32(ARM7CIRQ_MIN_PRLV_REG, ARM7CIRQ_HIGHEST_PRI); // in CSR, default is ARM7CIRQ_HIGHEST_PRI
    DRV_WriteReg32(ARM7CIRQ_MIN_PRLV_REG, ARM7CIRQ_LOWEST_PRI); // for temporory use, user can define it in the future

    for( i = 0; i < MAX_ISR_NUM; i++ ){
        // Set Interrupt Priority
        DRV_WriteReg32(ARM7CIRQ_PRLV_REG(i), 0x0000000F/*i&ARM7CIRQ_LOWEST_PRI*/ );
    }

    Data_Sync_Barrier(); // nothing to do in ARM7
}



/*****************************************************************************
 * Function Implementation - Upper Layer                                       *
 *****************************************************************************/

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
   
   ARM7CIRQ_SETMASK_BIT(code);
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
   
   ARM7CIRQ_CLRMASK_BIT(code);
   Data_Sync_Barrier();

   RestoreIRQ(savedMask);
}


/*************************************************************************
* FUNCTION
*  IRQMaskAll
*
* DESCRIPTION
*  Mask all of the interrupts
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void IRQMaskAll(void)
{
    kal_int32 savedmask;
    
    savedmask = LockIRQ();
    DRV_WriteReg32(ARM7CIRQ_IMKR3100_REG, 0xFFFFFFFF);
    Data_Sync_Barrier();
    RestoreIRQ(savedmask);
}

/*************************************************************************
* FUNCTION
*  IRQMask_Status
*
* DESCRIPTION
*  query the interrupt code status
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 IRQMask_Status(kal_uint8 code)
{
    return (DRV_Reg32(ARM7CIRQ_IMKR3100_REG) & (0x1 << code));
}



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
void IRQDirectMaskAll(void)
{
    IRQMaskAll();
}

/*************************************************************************
* FUNCTION
*  IRQ_SaveMaskStatus
*
* DESCRIPTION
*  Save the current IRQ MASK status when exception
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void IRQ_SaveMaskStatus(void)
{
    IRQMaskStatus = DRV_Reg32(ARM7CIRQ_IMKR3100_REG);
    return;
}



/*************************************************************************
* FUNCTION
*  IRQClearAllInt
*
* DESCRIPTION
*  Clear all of the interrupts with direct indexing.
*
* IMPORTANT NOTICE
*  Reserved for system service only!
*  This is special API for system service only; used on system 
*  initialization stage!
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void IRQClearAllInt(void)
{
    DRV_WriteReg32(ARM7CIRQ_ISAR3100_REG, 0xFFFFFFFF);
    Data_Sync_Barrier();
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
*  IRQClearInt
*
* DESCRIPTION
*  Clear IRQ with plain format interrupt status
*
* PARAMETERS
*  Plain format interrupt status
*
* RETURNS
*
*************************************************************************/
void IRQClearInt(kal_uint8 code)
{
   kal_uint32 savedmask;
   
    /* Lockout all interrupts */
   savedmask = LockIRQ();

   DRV_WriteReg32(ARM7CIRQ_ISAR3100_REG, (0x1 << code));
   Data_Sync_Barrier();
   RestoreIRQ(savedmask);
}

/*************************************************************************
* FUNCTION
*  SetMaskValue
*
* DESCRIPTION
*  Use internally, setting data structure of IRQ_MASK_VALUE
*
* PARAMETERS
*  
*
* RETURNS
*
*************************************************************************/
void SetMaskValue(IRQ_MASK_VALUE_T *val, kal_uint8 code)
{
   ASSERT(code<NUM_IRQ_SOURCES);

   val->irq_mask0 &= ~(1 << code);
}


/*************************************************************************
* FUNCTION
*  IRQSensitivity
*
* DESCRIPTION
*  Setting sensitivity of IRQ
*
* PARAMETERS
*  code: IRQ number to be set
*  edge: either edge active low or level active low
*
* RETURNS
*
*************************************************************************/
void IRQSensitivity(kal_uint8 code, kal_bool edge)
{
   if( KAL_TRUE == edge )
   {
        DRV_WriteReg32(ARM7CIRQ_ISENR3100_REG, DRV_Reg32(ARM7CIRQ_ISENR3100_REG) & (~(0x1 << code)));
   } 
   else 
   {
        DRV_WriteReg32(ARM7CIRQ_ISENR3100_REG, DRV_Reg32(ARM7CIRQ_ISENR3100_REG) | (0x1 << code));
   }
}

/*************************************************************************
* FUNCTION
*  SYS_endIsr
*
* DESCRIPTION
*  Notify the CIRQ current ISR is finished!
*
* PARAMETERS
*  Binary coded interrupt status
*
* RETURNS
*
*************************************************************************/

void DEVDRV_LS_COPRO_INTSRAM_ROCODE SYS_endIsr(kal_uint8 irq_idx)
{
    DRV_WriteReg32(ARM7CIRQ_SW_PRIACK_REG, 1);
    Data_Sync_Barrier();
}


/*************************************************************************
* FUNCTION
*  SYS_ClearInt
*
* DESCRIPTION
*  Reserved for system service only!
*  Clear IRQ with plain format interrupt status
*  It is trapped while Interrupt is disabled!
*
* PARAMETERS
*  Plain format interrupt status
*
* RETURNS
*
*************************************************************************/
void SYS_ClearInt(kal_uint8 code)
{
   ASSERT(code < MAX_ISR_NUM);
   DRV_WriteReg32(ARM7CIRQ_ISAR3100_REG, (0x1 << code));
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
   DRV_WriteReg32(ARM7CIRQ_ISTR3100_REG, DRV_Reg32(ARM7CIRQ_ISTR3100_REG) | (0x1 << code));
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
   DRV_WriteReg32(ARM7CIRQ_ISTR3100_REG, DRV_Reg32(ARM7CIRQ_ISTR3100_REG) & (~(0x1 << code)));
   RestoreIRQ(savedMask);
}



/*************************************************************************
* FUNCTION
*  SleepMode_MaskAll
*
* DESCRIPTION
*  This function is used to mask all interrupt source except the wakeup interrupts

* IMPORTANT NOTICE
*  This is specific for L1, and must be used in paired with 
*  SleepMode_RestoreAll().
*
* PARAMETERS
*  A space for saving previous interrupt mask
*
* RETURNS
*
*************************************************************************/
void SleepMode_MaskAll(IRQ_MASK_VALUE_T *val)
{
    kal_uint32 savedMask;

    savedMask = LockIRQ();
#if defined(__CIRQ_MASK_REG_NR_1_NEW__)
    val->irq_mask0 = ARM7CIRQ_READ_REG_INDEX(ARM7CIRQ_IMKR3100_REG, 0);
    ARM7CIRQ_WRITE_REG_INDEX(ARM7CIRQ_IMSR3100_REG, 0, 0xffffffff);
    ARM7CIRQ_WRITE_REG_INDEX(ARM7CIRQ_IMCR3100_REG, 0, ~(val->irq_mask0 | SleepModeMask.irq_mask0));
#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)

#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)

#endif
   
#ifdef IRQ_RTR_SLT_CODE
   ASSERT(SleepModeMaskCount==0 || SleepModeMaskCount==2 || SleepModeMaskCount==3);
#else   
   ASSERT(SleepModeMaskCount==0 || SleepModeMaskCount==2 );
#endif

   SleepModeMaskCount = 1;
   RestoreIRQ(savedMask);
}

/*************************************************************************
* FUNCTION
*  SleepMode_RestoreAll
*
* DESCRIPTION
*  This function is used to restore the previous interrupt 
*  mask according the input parameter
*
* IMPORTANT NOTICE
*  This is specific for L1, and must be used in paired with 
*  SleepMode_MaskAll().
*
* PARAMETERS
*  A space for saving previous interrupt mask
*
* RETURNS
*
*************************************************************************/
void SleepMode_RestoreAll(IRQ_MASK_VALUE_T *val)
{
   kal_uint32 savedMask;

   savedMask = LockIRQ();

   if(SleepModeMaskCount == 1)
   {
#if defined(__CIRQ_MASK_REG_NR_1_NEW__)
    ARM7CIRQ_WRITE_REG_INDEX(ARM7CIRQ_IMSR3100_REG, 0, 0xFFFFFFFF);
    ARM7CIRQ_WRITE_REG_INDEX(ARM7CIRQ_IMCR3100_REG, 0, ~(val->irq_mask0));
#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)

#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)

#endif
   }

#ifdef IRQ_RTR_SLT_CODE
   ASSERT( SleepModeMaskCount == 1 || SleepModeMaskCount == 2);
#else
   ASSERT( SleepModeMaskCount == 1);
#endif

   SleepModeMaskCount++;
   RestoreIRQ(savedMask);

}

/*************************************************************************
* FUNCTION
*  MaskValueInit
*
* DESCRIPTION
*  Initialize Global data
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*************************************************************************/
void MaskValueInit()
{
#if defined(__CIRQ_MASK_REG_NR_1_NEW__)
   SleepModeMask.irq_mask0 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask0 = 0xffffffff;   
#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)

#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)

#endif

/*////
#ifdef IRQ_WTIMER_CODE
   SetMaskValue(&SleepModeMask,IRQ_WTIMER_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_WTIMER_CODE);
#endif
*/////

#ifdef IRQ_OSTIMER_ARM_CODE
   SetMaskValue(&SleepModeMask,IRQ_OSTIMER_ARM_CODE);
#endif

/*////
#ifdef ATEST_DRV_ENABLE
    SetMaskValue(&SleepModeMask,MD_IRQID_RTC);
#endif
*/////

/*////#ifdef IRQ_TDMA_CODE
   SetMaskValue(&SleepModeMask,IRQ_TDMA_CODE);
#endif
*/////
//   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_CTIRQ1_CODE);
//   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_CTIRQ2_CODE);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* end of MEASURE_ISR_PERIOD_ENABLE */
#endif /* end of __ENABLE_SW_TRIGGER_INTERRUPT__ */

/*************************************************************************
* FUNCTION
*  initINTR
*
* DESCRIPTION
*  Interrupt initialization
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void initINTR(void)
{
   kal_uint8 idx;

   drv_arm7cirq_reset();

   kal_mem_set(INTMaskCount, 0, sizeof(INTMaskCount));

   MaskValueInit();

#if defined(__ENABLE_SW_TRIGGER_INTERRUPT__)
   /* Initialize SW Interrupt Counter*/
   for(idx=0; idx < NUM_IRQ_SOURCES; idx++)
   {
      SW_INT_Counter[idx]=0;
   }
#endif
}

//#define ARM7CIRQ_CHECK_SENSITIVITY
#ifdef ARM7CIRQ_CHECK_SENSITIVITY
extern void dbg_print(char *fmt,...);

/* Check sensitivity && mask */
#define SENSITIVITY_NA      (0xFF)
#define SENSITIVITY_LEVEL   ((kal_uint8)LEVEL_SENSITIVE)
#define SENSITIVITY_EDGE    ((kal_uint8)EDGE_SENSITIVE)

/* enum to string */
#define SENSITIVITY_STRING(v) (((v)==SENSITIVITY_LEVEL)? \
                                  ("Level"):(((v)==SENSITIVITY_EDGE)? \
                                            ("Pulse"):("NA")))

#define ARM7CIRQ_CHECK_MSG(strbuf, len, formatStr, args...) \
do{                                                       \
    kal_snprintf(strbuf, len, formatStr, ##args);         \
    dbg_print("%s", strbuf);                              \
    /*usbc_core_printf("%s", victest_printbuff);*/        \
}while(0)

extern void* IRQ_Retrieve_LISR(kal_uint32 vector);

static kal_uint32 mask[MAX_ISR_NUM/32];
static kal_uint32 sensitivity[MAX_ISR_NUM/32];
static kal_bool   drv_arm7cirq_check_init = KAL_FALSE;
static kal_char   log_buf[128];
extern irqlisr_entry lisr_dispatch_tbl[NUM_IRQ_SOURCES];;

kal_bool drv_arm7cirq_ip_enable_table[MAX_ISR_NUM] = {KAL_FALSE};
kal_uint8 const drv_arm7cirq_ip_sensitivity[MAX_ISR_NUM] = \
{
    /*  0 ~ 15 */
    SENSITIVITY_EDGE,
    SENSITIVITY_EDGE,
    SENSITIVITY_LEVEL,
    SENSITIVITY_EDGE,
    SENSITIVITY_EDGE,
    SENSITIVITY_EDGE,
    SENSITIVITY_EDGE,
    SENSITIVITY_EDGE,
    SENSITIVITY_EDGE,
    SENSITIVITY_EDGE,
    SENSITIVITY_EDGE,
    SENSITIVITY_LEVEL,
    SENSITIVITY_LEVEL,
    SENSITIVITY_LEVEL,
    SENSITIVITY_LEVEL,
    SENSITIVITY_EDGE,
    /* 16 ~ 31 */
    SENSITIVITY_LEVEL,
    SENSITIVITY_LEVEL,
    SENSITIVITY_LEVEL,
    SENSITIVITY_LEVEL,
    SENSITIVITY_LEVEL,
    SENSITIVITY_EDGE,
    SENSITIVITY_EDGE,
    SENSITIVITY_LEVEL,
    SENSITIVITY_LEVEL,
    SENSITIVITY_LEVEL,
    SENSITIVITY_EDGE,
    SENSITIVITY_NA,
    SENSITIVITY_LEVEL,
    SENSITIVITY_NA,
    SENSITIVITY_NA,
    SENSITIVITY_NA,
};

static void drv_arm7cirq_dump_driver_status(void)
{
    kal_uint32 i;

    for(i = 0; i < MAX_ISR_NUM; i++)
    {
        if( (SENSITIVITY_NA == drv_arm7cirq_ip_sensitivity[i]) || (IRQ_Default_LISR == IRQ_Retrieve_LISR(i)) )
        {
            continue;
        }

        /* CIRQ is initialed, this driver is ready in tataka */
        if( 0 == ARM7CIRQ_GetRegBit_Vector((kal_uint32)sensitivity, i) )
        {
            ARM7CIRQ_CHECK_MSG(log_buf, sizeof(log_buf), "[%d]Get:Pulse, Expect: %s\n\r", i, SENSITIVITY_STRING(drv_arm7cirq_ip_sensitivity[i]));
            if( SENSITIVITY_EDGE != drv_arm7cirq_ip_sensitivity[i] )
            {
                ARM7CIRQ_CHECK_MSG(log_buf, sizeof(log_buf), "==> \t%d: Sensitivity Error\n\r", i);
            }
        }
        else
        {
            ARM7CIRQ_CHECK_MSG(log_buf, sizeof(log_buf), "[%d]Get:Level, Expect: %s\n\r", i, SENSITIVITY_STRING(drv_arm7cirq_ip_sensitivity[i]));
            if( SENSITIVITY_LEVEL != drv_arm7cirq_ip_sensitivity[i] )
            {
                ARM7CIRQ_CHECK_MSG(log_buf, sizeof(log_buf), "\t%d: Sensitivity Error\n\r", i);
            }
        }
    }
}


void drv_arm7cirq_check_driver_status(void)
{
    kal_uint32 i;
    kal_uint32 const irq_div_32 = MAX_ISR_NUM/32;

    if(KAL_FALSE == drv_arm7cirq_check_init)
    {
        drv_arm7cirq_check_init = KAL_TRUE;
        for(i = 0; i < irq_div_32; i++)
        {
            mask[i]        = DRV_Reg32(ARM7CIRQ_IMKR3100_REG + (0x4*i));
            sensitivity[i] = DRV_Reg32(ARM7CIRQ_ISENR3100_REG + (0x4*i));
        }
        drv_arm7cirq_dump_driver_status();
    }
}

#endif /* end of ARM7CIRQ_CHECK_SENSITIVITY */

