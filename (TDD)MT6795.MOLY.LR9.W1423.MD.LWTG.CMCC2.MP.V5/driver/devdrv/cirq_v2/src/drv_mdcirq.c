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
 *   drv_mdcirq.c
 *
 * Project:
 * --------
 *   TATAKA
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
 *
 * removed!
 * removed!
 * ROME Porting
 *
 * removed!
 * removed!
 * fix error setting
 *
 * removed!
 * removed!
 * remove compiling warning
 *
 * removed!
 * removed!
 * update for E2 FPGA
 *
 * removed!
 * removed!
 * add sleep mask setting
 *
 * removed!
 * removed!
 * MT6290E1_FristCall Branch sync back to MOLY Trunk
 *
 * removed!
 * removed!
 * LISR 2 HISR support, driver part
 *
 * removed!
 * removed!
 * MOLY LISR2HISR, Driver part
 *
 * removed!
 * removed!
 * fix build error in 128 pins support
 *
 * removed!
 * removed!
 * chip rename:MT7208 to MT6290
 *
 * removed!
 * removed!
 * fix atest_drv build failed because the multimode code merge
 ****************************************************************************/


/******************************************************************************
 * Include header files
 ******************************************************************************/

#include "kal_public_api.h"
#include "cache_sw.h"
#include "intrCtrl.h"
#include "drv_comm.h"
#include "drv_mdcirq.h"
#include "sync_data.h"
#include "devdrv_ls.h"
#if defined(__UNIFIED_ISR_LEVEL__)
#include "syscomp_config.h"
#include "hisr_config.h"
#endif /* __UNIFIED_ISR_LEVEL__ */


/******************************************************************************
 * Define global data
 ******************************************************************************/
kal_uint32 irq_mask_caller;
kal_uint32 irq_unmask_caller;
kal_uint8  irq_mask_monitor_idx = NUM_IRQ_SOURCES;
kal_uint8  irq_unmask_monitor_idx = NUM_IRQ_SOURCES;
kal_uint32 ISR_Routine_size;
kal_uint32 IRQMaskStatus[5];

#if defined(__UNIFIED_ISR_LEVEL__)
DEVDRV_LS_INTSRAM_ZI kal_uint32 drv_mdcirq_spl[MDCIRQ_TOTAL_PRI_LEVEL/32];
DEVDRV_LS_INTSRAM_RW kal_uint32 drv_mdcirq_spl_value = MDCIRQ_LOWEST_PRI;
#endif /* __UNIFIED_ISR_LEVEL__ */

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
#if defined(__UNIFIED_ISR_LEVEL__)
const kal_uint8 kalid2intrID[KAL_INTID_MAX+1] =
{
	KAL_INTID_2_CODE_MAPPNG
};
kal_hisrid intrID2hisrID[NUM_IRQ_SOURCES];   /* for SS ISR activate hisr */
kal_uint8  intrID2hisrEID[NUM_IRQ_SOURCES];  /* for debug only */
kal_uint8  irq_priority_list[NUM_IRQ_SOURCES];
#else /* __UNIFIED_ISR_LEVEL__ */
static const kal_uint8 irq_priority_list[] = 
{
    INTERRUPT_PRIORITY_LIST
};
#endif /* __UNIFIED_ISR_LEVEL__ */


/*****************************************************************************
 * External function/variables                                               *
 *****************************************************************************/
extern void       ReEnableIRQ(void);
extern void       RestoreIRQ(kal_uint32 irq);
extern void       (*ISRRoutine_Default)(void);
extern void       cp15_vector_interrupt_enable(void) ;
extern kal_bool   INT_QueryExceptionStatus(void);
extern kal_uint32 LockIRQ(void);

extern volatile void *ISRRoutines[];
extern volatile void *ISRRoutine_1;
extern volatile void *ISRRoutine_2;
#if defined(__UNIFIED_ISR_LEVEL__)
extern const hisr_intid_map   hisr_intid_g[];
extern const kal_uint32       total_hisr_intid_g;
extern const hisr_parameter_s hisr_info[];
extern const kal_uint32 total_hisr_g;
#endif /* __UNIFIED_ISR_LEVEL__ */

/*****************************************************************************
 * Function Declaration                                                      *
 *****************************************************************************/
void drv_mdcirq_clr_all_swtr(void);
void IRQClearAllInt(void);
void IRQDirectMaskAll(void);
#if defined(__UNIFIED_ISR_LEVEL__)
void drv_mdcirq_spl_init(void);
#endif /* __UNIFIED_ISR_LEVEL__ */

/*****************************************************************************
 * Function Implementation - Low Layer                                       *
 *****************************************************************************/
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
#endif /* */

void drv_mdcirq_unmask_all(void)
{
    kal_int32 i;
    for(i = 0; i < NUM_IRQ_SOURCES/32; i++)
    {
        MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMCR_BASE, i, 0xFFFFFFFF);
    }
}

void drv_mdcirq_clr_all_swtr(void)
{
    kal_int32 i;
    for(i = 0; i < NUM_IRQ_SOURCES/32; i++)
    {
        MDCIRQ_WRITE_REG_INDEX(MDCIRQ_ISTR_BASE, i, 0);
    }
    Data_Sync_Barrier();
}

/* Reset as system default */
void drv_mdcirq_reset(void)
{
	kal_int32 i;

	/* Prepare the vector entry subroutine size */
	ISR_Routine_size = (kal_uint32)(&ISRRoutine_2) - (kal_uint32)(&ISRRoutine_1);

	/* Clear Status Registers */
	IRQClearAllInt();

	/* Mask All Interrupt Sources */
	IRQDirectMaskAll();

	/* Enable VIC Support, IDSET is disabled */
	DRV_WriteReg32(MDCIRQ_CTRL_REG, MDCIRQ_CTRL_REG_VIC_EN);
	
	/* Clear Software Trigger Interrupt*/
	drv_mdcirq_clr_all_swtr();
    cp15_vector_interrupt_enable();

	for(i = 0; i < NUM_IRQ_SOURCES; i++){
		/* Default Address is 0x0000_0018 (Traditional) */
		//DRV_WriteReg32(MDCIRQ_VEC_ADDR(i), 0x00000018);

		/* Set Vector Entry Address */
		DRV_WriteReg32(MDCIRQ_VEC_ADDR(i), ((kal_uint32)&ISRRoutines) + i*ISR_Routine_size);

		/* Interrupt Priorities Setting */
#if !defined(__UNIFIED_ISR_LEVEL__)
		DRV_WriteReg32(MDCIRQ_PRLV(i), ((kal_uint32)irq_priority_list[i]) );
#endif /* __UNIFIED_ISR_LEVEL__ */

	}
	
	/* Clear Priority Stack */
	for(i = 0; i < MDCIRQ_TOTAL_PRI_LEVEL; i++){
		DRV_WriteReg32(MDCIRQ_SW_PRIACK, 1);
	}
	
	/* Sensitivity */
    for(i = 0; i < NUM_IRQ_SOURCES/32; i++)
    {
        MDCIRQ_WRITE_REG_INDEX(MDCIRQ_ISENR_BASE, i, 0);
    }

    DRV_WriteReg32(MDCIRQ_DEFAULT_VEC_ADR, (kal_uint32)(&ISRRoutine_Default));

	/* Fast Interrupt Request(FIQ) Setting */
	DRV_WriteReg32(MDCIRQ_FIQCONR, MDCIRQ_FIQCONR_FIQ_MASK | \
	               MDCIRQ_FIQCONR_FIQ_SEL(0));

	/* Set Minimal Priority Level to Lowest Priority */
	DRV_WriteReg32_NPW(MDCIRQ_MIN_PRLV, MDCIRQ_LOWEST_PRI);
#if defined(__UNIFIED_ISR_LEVEL__)
	drv_mdcirq_spl_init();
#endif /* __UNIFIED_ISR_LEVEL__ */
    Data_Sync_Barrier();

}



/************************************************************************
 * Function Implementation - Upper Layer                                       *
 ************************************************************************/
#if defined(__UNIFIED_ISR_LEVEL__)
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
#endif
/*************************************************************************
* FUNCTION
*  drv_mdcirq_spi_init
*
* DESCRIPTION
*  SPL array init
*
* PARAMETERS
*
* RETURNS
*  
*************************************************************************/
void drv_mdcirq_spl_init(void)
{
	kal_uint32 i, j;
	kal_uint16 intID;

	memset(intrID2hisrEID, INVALID_ISR_ID, sizeof(intrID2hisrEID));
	memset(irq_priority_list, MDCIRQ_LOWEST_PRI, sizeof(irq_priority_list));

	for(i = 1; i < total_hisr_intid_g; i++)/* all kalid<->hisrEID mapping */
	{
		intID = kalid2intrID[hisr_intid_g[i].int_id]; /* kalid<->intrID mapping */
		if( intID != INVALID_ISR_ID )
		{
			intrID2hisrEID[intID] = hisr_intid_g[i].hisr_id;/* intrID<->hisrEID mapping*/
			for(j = 0; j < total_hisr_g; j++)
			{
				if(hisr_info[j].index == intrID2hisrEID[intID])
				{
					irq_priority_list[intID] = hisr_info[j].priority; /* intrID<->intr/hisr priority mapping */
				}
			}
		}
	}

	/* Set Interrupt Priority */
	for(i = 0; i < NUM_IRQ_SOURCES; i++)
	{
		DRV_WriteReg32(MDCIRQ_PRLV(i), ((kal_uint32)irq_priority_list[i]) );
	}
}
/* The GetHighestSPL is for 64 priority level, use the GuardArray to check
   the total priority level at build timen */
DEVDRV_LS_SHOULD_NOT_USED_RODATA kal_uint8 GetHighestSPL_GuardArray[64-MDCIRQ_TOTAL_PRI_LEVEL];
/*************************************************************************
* FUNCTION
*  drv_mdcirq_getHighestSPL
*
* DESCRIPTION
*  Return the highest SPL priority in the pending list
*
* PARAMETERS
*
* RETURNS
*  
*************************************************************************/
static kal_uint32 drv_mdcirq_getHighestSPL(void)
{
    kal_uint32 spl;
    if(drv_mdcirq_spl[0])
    {
        spl = __builtin_ctz(drv_mdcirq_spl[0]);
    }
    else if(drv_mdcirq_spl[1])
    {
        spl = __builtin_ctz(drv_mdcirq_spl[1]) + 32;
    }
    else
    {
        spl = MDCIRQ_LOWEST_PRI;
    }
    return spl;
}

/*************************************************************************
* FUNCTION
*  AddSPL
*
* DESCRIPTION
*  Add a SPL value into pending list
*
* PARAMETERS
*  spl: SPL priority value
* RETURNS
*  
*************************************************************************/
void AddSPL(kal_uint32 hisr_priority)
{
    kal_uint32 spl_idx;
    kal_uint32 spl_offset;
	kal_uint32 spl = hisr_priority -1;

    ASSERT(spl<MDCIRQ_TOTAL_PRI_LEVEL);
    spl_idx = spl >> 5;
    spl_offset = spl % 32;

    drv_mdcirq_spl[spl_idx] |= 1<<spl_offset;
    
    if( spl < drv_mdcirq_spl_value )
    {
        DRV_WriteReg32_NPW(MDCIRQ_MIN_PRLV, spl);
        drv_mdcirq_spl_value = spl;
    }
}

/*************************************************************************
* FUNCTION
*  RemoveSPL
*
* DESCRIPTION
*  Remove a SPL value from pending list and set the highest SPL value
*  in the pending list
*
* PARAMETERS
*  hisr: hisr id
* RETURNS
*  
*************************************************************************/
void RemoveSPL(kal_uint32 hisr_priority)
{
    kal_uint32 pri = hisr_priority - 1; /* pri = HISR_Pri[hisr]; */
    kal_uint32 spl_idx;
    kal_uint32 spl_offset;
    kal_uint32 spl;

    ASSERT(pri<MDCIRQ_TOTAL_PRI_LEVEL);
    spl_idx = pri >> 5;
    spl_offset = pri % 32;
    ASSERT( (drv_mdcirq_spl[spl_idx]&(1<<spl_offset)) );//should remove the existed SPL

    /* Clear SPL Priority */
    drv_mdcirq_spl[spl_idx] &= ~(1<<spl_offset);

    /* Get the highest SPL Priority */
    spl = drv_mdcirq_getHighestSPL();
    drv_mdcirq_spl_value = spl;
    DRV_WriteReg32(MDCIRQ_MIN_PRLV, spl);
}
#endif /* __UNIFIED_ISR_LEVEL__ */


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
    kal_int32 i, savedmask;
    
    savedmask = LockIRQ();
    for(i = 0; i < NUM_IRQ_SOURCES/32; i++)
    {
        MDCIRQ_WRITE_REG_INDEX_NPW(MDCIRQ_IMSR_BASE, i, 0xFFFFFFFF);
    }
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
    return (MDCIRQ_READ_REG_INDEX(MDCIRQ_IMKR_BASE, code/32) & (1<<(code%32)));
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
#if defined(__CIRQ_MASK_REG_NR_1_NEW__)
    IRQMaskStatus[0] = DRV_Reg32(MDCIRQ_IMKR3100);
#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
    IRQMaskStatus[0] = DRV_Reg32(MDCIRQ_IMKR3100);
    IRQMaskStatus[1] = DRV_Reg32(MDCIRQ_IMKR6332);
#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)
    IRQMaskStatus[0] = DRV_Reg32(MDCIRQ_IMKR3100);
    IRQMaskStatus[1] = DRV_Reg32(MDCIRQ_IMKR6332);
    IRQMaskStatus[2] = DRV_Reg32(MDCIRQ_IMKR9564);
#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
    IRQMaskStatus[0] = DRV_Reg32(MDCIRQ_IMKR3100);
    IRQMaskStatus[1] = DRV_Reg32(MDCIRQ_IMKR6332);
    IRQMaskStatus[2] = DRV_Reg32(MDCIRQ_IMKR9564);
    IRQMaskStatus[3] = DRV_Reg32(MDCIRQ_IMKR12796);
#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
    IRQMaskStatus[0] = DRV_Reg32(MDCIRQ_IMKR3100);
    IRQMaskStatus[1] = DRV_Reg32(MDCIRQ_IMKR6332);
    IRQMaskStatus[2] = DRV_Reg32(MDCIRQ_IMKR9564);
    IRQMaskStatus[3] = DRV_Reg32(MDCIRQ_IMKR12796);
    IRQMaskStatus[4] = DRV_Reg32(MDCIRQ_IMKR159128);
#else
#endif
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
    kal_int32 i;
    for(i = 0; i < NUM_IRQ_SOURCES/32; i++)
    {
        MDCIRQ_WRITE_REG_INDEX(MDCIRQ_ISAR_BASE, i, 0xFFFFFFFF);
    }
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

   MDCIRQ_WrClrRegBit_Vector_NPW(MDCIRQ_ISAR_BASE, code);
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

#if defined(__CIRQ_MASK_REG_NR_1_NEW__)
   val->irq_mask0 &= ~(1 << code);

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
   if (code < 32)
      val->irq_mask0 &= ~(1 << code);
   else
      val->irq_mask1 &= ~(1 << (code - 32));

#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)
   if (code < 32)
      val->irq_mask0 &= ~(1 << code);
   else if (code < 64)
      val->irq_mask1 &= ~(1 << (code - 32));
   else
      val->irq_mask2 &= ~(1 << (code - 64));

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
   if (code < 32)
      val->irq_mask0 &= ~(1 << code);
   else if (code < 64)
      val->irq_mask1 &= ~(1 << (code - 32));
   else if (code < 96)
      val->irq_mask2 &= ~(1 << (code - 64));
   else
      val->irq_mask3 &= ~(1 << (code - 96));

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
   if (code < 32)
      val->irq_mask0 &= ~(1 << code);
   else if (code < 64)
      val->irq_mask1 &= ~(1 << (code - 32));
   else if (code < 96)
      val->irq_mask2 &= ~(1 << (code - 64));
   else if (code < 128)
      val->irq_mask3 &= ~(1 << (code - 96));
   else
      val->irq_mask4 &= ~(1 << (code - 128));

#endif
   
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
      MDCIRQ_ClrRegBit_Vector(MDCIRQ_ISENR_BASE, code);
   } 
   else 
   {
      MDCIRQ_SetRegBit_Vector(MDCIRQ_ISENR_BASE, code);
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

void DEVDRV_LS_INTSRAM_ROCODE SYS_endIsr(kal_uint8 irq_idx)
{
    DRV_WriteReg32_NPW(MDCIRQ_SW_PRIACK, 1);
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
   ASSERT(code < NUM_IRQ_SOURCES);
   MDCIRQ_WrClrRegBit_Vector(MDCIRQ_ISAR_BASE, code);
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

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)

#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)
    val->irq_mask0 = MDCIRQ_READ_REG_INDEX(MDCIRQ_IMKR_BASE, 0);
    val->irq_mask1 = MDCIRQ_READ_REG_INDEX(MDCIRQ_IMKR_BASE, 1);
    val->irq_mask2 = MDCIRQ_READ_REG_INDEX(MDCIRQ_IMKR_BASE, 2);
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMSR_BASE, 0, 0xFFFFFFFF);
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMSR_BASE, 1, 0xFFFFFFFF);
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMSR_BASE, 2, 0xFFFFFFFF);
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMCR_BASE, 0, ~(val->irq_mask0 | SleepModeMask.irq_mask0));
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMCR_BASE, 1, ~(val->irq_mask1 | SleepModeMask.irq_mask1));
    MDCIRQ_WRITE_REG_INDEX_NPW(MDCIRQ_IMCR_BASE, 2, ~(val->irq_mask2 | SleepModeMask.irq_mask2));

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
    val->irq_mask0 = MDCIRQ_READ_REG_INDEX(MDCIRQ_IMKR_BASE, 0);
    val->irq_mask1 = MDCIRQ_READ_REG_INDEX(MDCIRQ_IMKR_BASE, 1);
    val->irq_mask2 = MDCIRQ_READ_REG_INDEX(MDCIRQ_IMKR_BASE, 2);
    val->irq_mask3 = MDCIRQ_READ_REG_INDEX(MDCIRQ_IMKR_BASE, 3);
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMSR_BASE, 0, 0xFFFFFFFF);
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMSR_BASE, 1, 0xFFFFFFFF);
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMSR_BASE, 2, 0xFFFFFFFF);
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMSR_BASE, 3, 0xFFFFFFFF);
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMCR_BASE, 0, ~(val->irq_mask0 | SleepModeMask.irq_mask0));
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMCR_BASE, 1, ~(val->irq_mask1 | SleepModeMask.irq_mask1));
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMCR_BASE, 2, ~(val->irq_mask2 | SleepModeMask.irq_mask2));
    MDCIRQ_WRITE_REG_INDEX_NPW(MDCIRQ_IMCR_BASE, 3, ~(val->irq_mask3 | SleepModeMask.irq_mask3));

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

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)

#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMSR_BASE, 0, 0xFFFFFFFF);
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMSR_BASE, 1, 0xFFFFFFFF);
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMSR_BASE, 2, 0xFFFFFFFF);
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMCR_BASE, 0, ~(val->irq_mask0));
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMCR_BASE, 1, ~(val->irq_mask1));
    MDCIRQ_WRITE_REG_INDEX_NPW(MDCIRQ_IMCR_BASE, 2, ~(val->irq_mask2));

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMSR_BASE, 0, 0xFFFFFFFF);
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMSR_BASE, 1, 0xFFFFFFFF);
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMSR_BASE, 2, 0xFFFFFFFF);
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMSR_BASE, 3, 0xFFFFFFFF);
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMCR_BASE, 0, ~(val->irq_mask0));
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMCR_BASE, 1, ~(val->irq_mask1));
    MDCIRQ_WRITE_REG_INDEX(MDCIRQ_IMCR_BASE, 2, ~(val->irq_mask2));
    MDCIRQ_WRITE_REG_INDEX_NPW(MDCIRQ_IMCR_BASE, 3, ~(val->irq_mask3));
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
   SleepModeMask.irq_mask0 = 0xffffffff;
   SleepModeMask.irq_mask1 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask0 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask1 = 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)
   SleepModeMask.irq_mask0 = 0xffffffff;
   SleepModeMask.irq_mask1 = 0xffffffff;
   SleepModeMask.irq_mask2 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask0 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask1 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask2 = 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
   SleepModeMask.irq_mask0 = 0xffffffff;
   SleepModeMask.irq_mask1 = 0xffffffff;
   SleepModeMask.irq_mask2 = 0xffffffff;
   SleepModeMask.irq_mask3 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask0 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask1 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask2 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask3 = 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
   SleepModeMask.irq_mask0 = 0xffffffff;
   SleepModeMask.irq_mask1 = 0xffffffff;
   SleepModeMask.irq_mask2 = 0xffffffff;
   SleepModeMask.irq_mask3 = 0xffffffff;
   SleepModeMask.irq_mask4 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask0 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask1 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask2 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask3 = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_mask4 = 0xffffffff;
#endif

#if defined(IRQ_RTR_SLT_CODE)&&(MDCIRQ_128_64_VERSION==1)
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_RTR_SLT_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_AI_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_PI_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_SEARCHER_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_TFCI_0_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_TFCI_1_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_RXBRP_CC0_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_RXBRP_CC1_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_RXBRP_CCB_CODE);
#endif


#if defined(IRQ_WTIMER_CODE)&&(MDCIRQ_128_64_VERSION==1)
   SetMaskValue(&SleepModeMask,IRQ_WTIMER_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_WTIMER_CODE);
#endif

#ifdef IRQ_OSTIMER_ARM_CODE
   SetMaskValue(&SleepModeMask,IRQ_OSTIMER_ARM_CODE);
#endif

#if defined(ATEST_DRV_ENABLE)&&defined(IRQ_RTC_CODE)
    SetMaskValue(&SleepModeMask,IRQ_RTC_CODE);
#endif

#if defined(IRQ_TDMA_CODE)&&(MDCIRQ_128_64_VERSION==1)
   SetMaskValue(&SleepModeMask,IRQ_TDMA_CODE);
#endif

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
   ASSERT(handle < NUM_IRQ_SOURCES);

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
   ASSERT(handle < NUM_IRQ_SOURCES);

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

   drv_mdcirq_reset();

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

//#define MDCIRQ_CHECK_SENSITIVITY
#ifdef MDCIRQ_CHECK_SENSITIVITY
extern void dbg_print(char *fmt,...);

/* Check sensitivity && mask */
#define SENSITIVITY_NA      (0xFF)
#define SENSITIVITY_LEVEL   ((kal_uint8)LEVEL_SENSITIVE)
#define SENSITIVITY_EDGE    ((kal_uint8)EDGE_SENSITIVE)

/* enum to string */
#define SENSITIVITY_STRING(v) (((v)==SENSITIVITY_LEVEL)? \
                                  ("Level"):(((v)==SENSITIVITY_EDGE)? \
                                            ("Pulse"):("NA")))

#define MDCIRQ_CHECK_MSG(strbuf, len, formatStr, args...) \
do{                                                       \
    kal_snprintf(strbuf, len, formatStr, ##args);         \
    dbg_print("%s", strbuf);                              \
    /*usbc_core_printf("%s", victest_printbuff);*/        \
}while(0)

extern void* IRQ_Retrieve_LISR(kal_uint32 vector);

static kal_uint32 mask[NUM_IRQ_SOURCES/32];
static kal_uint32 sensitivity[NUM_IRQ_SOURCES/32];
static kal_bool   drv_mdcirq_check_init = KAL_FALSE;
static kal_char   log_buf[128];
extern irqlisr_entry lisr_dispatch_tbl[NUM_IRQ_SOURCES];;

kal_bool drv_mdcirq_ip_enable_table[NUM_IRQ_SOURCES] = {KAL_FALSE};
kal_uint8 const drv_mdcirq_ip_sensitivity[NUM_IRQ_SOURCES] = \
{
    /*  0 ~ 15 */
    SENSITIVITY_NA,
    SENSITIVITY_EDGE,
    SENSITIVITY_LEVEL,
    SENSITIVITY_LEVEL,
    SENSITIVITY_EDGE,
    SENSITIVITY_EDGE,
    SENSITIVITY_EDGE,
    SENSITIVITY_EDGE,
    SENSITIVITY_LEVEL,
    SENSITIVITY_EDGE,
    SENSITIVITY_EDGE,
    SENSITIVITY_LEVEL,
    SENSITIVITY_LEVEL,
    SENSITIVITY_LEVEL,
    SENSITIVITY_LEVEL,
    SENSITIVITY_LEVEL,
    /* 16 ~ 31 */
    SENSITIVITY_LEVEL,
    SENSITIVITY_LEVEL,
    SENSITIVITY_LEVEL,
    SENSITIVITY_LEVEL,
    SENSITIVITY_EDGE,
    SENSITIVITY_EDGE,
    SENSITIVITY_EDGE,
    SENSITIVITY_EDGE,
    SENSITIVITY_EDGE,
    SENSITIVITY_EDGE,
    SENSITIVITY_EDGE,
    SENSITIVITY_LEVEL,
    SENSITIVITY_LEVEL,
    SENSITIVITY_EDGE,
    SENSITIVITY_EDGE,
    SENSITIVITY_LEVEL,
    /* 32 ~ 47 */
    SENSITIVITY_LEVEL,
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
    SENSITIVITY_LEVEL,
    SENSITIVITY_LEVEL,
    SENSITIVITY_LEVEL,
    SENSITIVITY_NA,
    SENSITIVITY_NA,
    /* 48 ~ 63 */
    SENSITIVITY_NA,
    SENSITIVITY_NA,
    SENSITIVITY_LEVEL,
    SENSITIVITY_NA,
    SENSITIVITY_NA,
    SENSITIVITY_NA,
    SENSITIVITY_NA,
    SENSITIVITY_NA,
    SENSITIVITY_NA,
    SENSITIVITY_NA,
    SENSITIVITY_NA,
    SENSITIVITY_NA,
    SENSITIVITY_NA,
    SENSITIVITY_NA,
    SENSITIVITY_NA,
    SENSITIVITY_NA
};

static void drv_mdcirq_dump_driver_status(void)
{
    kal_uint32 i;

    for(i = 0; i < NUM_IRQ_SOURCES; i++)
    {
        if( (SENSITIVITY_NA == drv_mdcirq_ip_sensitivity[i]) || (IRQ_Default_LISR == IRQ_Retrieve_LISR(i)) )
        {
            continue;
        }

        /* CIRQ is initialed, this driver is ready in tataka */
        if( MDCIRQ_ISENR_PULSE == MDCIRQ_GetRegBit_Vector((kal_uint32)sensitivity, i) )
        {
            MDCIRQ_CHECK_MSG(log_buf, sizeof(log_buf), "[%d]Get:Pulse, Expect: %s\n\r", i, SENSITIVITY_STRING(drv_mdcirq_ip_sensitivity[i]));
            if( SENSITIVITY_EDGE != drv_mdcirq_ip_sensitivity[i] )
            {
                MDCIRQ_CHECK_MSG(log_buf, sizeof(log_buf), "==> \t%d: Sensitivity Error\n\r", i);
            }
        }
        else
        {
            MDCIRQ_CHECK_MSG(log_buf, sizeof(log_buf), "[%d]Get:Level, Expect: %s\n\r", i, SENSITIVITY_STRING(drv_mdcirq_ip_sensitivity[i]));
            if( SENSITIVITY_LEVEL != drv_mdcirq_ip_sensitivity[i] )
            {
                MDCIRQ_CHECK_MSG(log_buf, sizeof(log_buf), "\t%d: Sensitivity Error\n\r", i);
            }
        }
    }
}


void drv_mdcirq_check_driver_status(void)
{
    kal_uint32 i;
    kal_uint32 const irq_div_32 = NUM_IRQ_SOURCES/32;

    if(KAL_FALSE == drv_mdcirq_check_init)
    {
        drv_mdcirq_check_init = KAL_TRUE;
        for(i = 0; i < irq_div_32; i++)
        {
            mask[i]        = DRV_Reg32(MDCIRQ_IMKR_BASE + (0x4*i));
            sensitivity[i] = DRV_Reg32(MDCIRQ_ISENR_BASE + (0x4*i));
        }
        drv_mdcirq_dump_driver_status();
    }
}
#endif /* end of MDCIRQ_CHECK_SENSITIVITY */


