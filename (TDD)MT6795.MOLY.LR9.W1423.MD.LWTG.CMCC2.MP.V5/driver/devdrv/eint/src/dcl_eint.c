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

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "eint.h"
#include "dcl.h"
#include "drv_hisr.h"

#include "Eint_internal.h"
#include "kal_internal_api.h"
#include "eint_sw.h"
#include "cpu.h"
#include "drvpdn.h"

#if defined(MT6290) || defined(MT6595) || (defined (MT6752) && defined (__MD1__))

eint_func EINT_FUNC;
//dedicated_eint_func DEINT_FUNC;
static EINT_SW_DEBOUNCE_STRUCT eint_sw_debounce[EINT_MAX_CHANNEL];
//static EINT_SW_DEBOUNCE_STRUCT deint_sw_debounce[DEDICATED_EINT_TOTAL_CHANNEL];
#ifndef ATEST_DRV_ENABLE
static kal_uint8 *eint_sw_debounce_time_delay = NULL;
#else
kal_uint8 *eint_sw_debounce_time_delay = NULL;
#endif
//static kal_uint8 deint_sw_debounce_time_delay[DEDICATED_EINT_TOTAL_CHANNEL] = {0};

/* Variables to sources that triggers EINT interrupt */
kal_uint8 eint_trigger_src_log[EINT_TRIGGER_SRC_LOG_MAX] = {0x0};
kal_uint8 eint_trigger_src_ptr = 0;

extern kal_uint32 eint_is_dedicated;
extern kal_uint32 eint_is_dedicated_map[EINT_MAX_CHANNEL];

//extern kal_uint32 LockIRQ(void);
//extern void RestoreIRQ(kal_uint32 irq);

extern kal_uint32 SaveAndSetIRQMask(void);
extern void RESTOREIRQMASK(kal_uint32 irq);
extern void BTMT_EINT_HANDLER(kal_uint32* status);
//extern kal_uint32 DisableIRQ(void);
//kal_uint32 DEINT_Get_IRQ_ID(kal_uint8 deintno);
//void DEINT_Registration(kal_uint8 deintno,void (reg_hisr)(void));

void DEINT0_LISR();
void DEINT1_LISR();
void DEINT2_LISR();
void DEINT3_LISR();
/*************************************************************************
* FUNCTION
*  EINT_Mask
*
* DESCRIPTION
*   This function implements mask of dedicated external interrupt source
*
* CALLS
*
* PARAMETERS
*  eintno         - external interrupt vector number
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EINT_Mask(kal_uint8 eintno)
{
	if (eint_is_dedicated & (1 << eintno))
	{
		eint_set_l1_eint_enable(eint_is_dedicated_map[eintno], EINT_DISABLE);
		switch(eint_is_dedicated_map[eintno])
		{
			case DEDICATED_EINT0:
				IRQMask(DEDICATED_EINT_IRQ0);
				break;
			case DEDICATED_EINT1:
				IRQMask(DEDICATED_EINT_IRQ1);
				break;
			case DEDICATED_EINT2:
				IRQMask(DEDICATED_EINT_IRQ2);
				break;
			case DEDICATED_EINT3:
				IRQMask(DEDICATED_EINT_IRQ3);
				break;
			default:
				return;
		}
	}
	else
	{
		eint_set_irqen(eintno,EINT_DISABLE);
	}
}
/*
static void eint_udelay(kal_uint32 usdelay)
{
	kal_uint32 clock_count,event_count1,event_count2,delay_count;

	event_count1 = event_count2 = 0;

	clock_count = usdelay*(CPU_FREQUENCY_MHZ);
	cpu_event_counter_get_cycle(event_count1);
	

	while(1)
	{
		cpu_event_counter_get_cycle(event_count2);
		delay_count = cpu_event_get_duration(event_count1,event_count2);
		if(delay_count >= clock_count)
		{
			break;
		}
	}
}
*/
kal_uint32 EINT_Get_Mask_Bits(void)
{
	kal_uint32 mask_bit_value;
	kal_uint32 index, deint_en;
	
	mask_bit_value = eint_get_irqen();

	//add deint mask
	for(index=0;index<EINT_TOTAL_CHANNEL;index++)
	{
		if (eint_is_dedicated & (1 << index))
		{
			deint_en = eint_get_l1_irqen(eint_is_dedicated_map[index]);
			mask_bit_value |= (deint_en << index);
		}
	}

	return ~mask_bit_value;
}

void EINT_Set_Mask_all(kal_uint32 mask_bits)
{
	kal_uint32 index;

	for(index=0;index<EINT_TOTAL_CHANNEL;index++)
	{
		if ((eint_is_dedicated & (1 << index)) && (mask_bits & (1<< index)))
		{
			eint_set_l1_eint_enable(eint_is_dedicated_map[index], EINT_DISABLE);
			mask_bits &= (~(1<< index));
		}
	}
	eint_set_mask_all(mask_bits);
}

void EINT_Set_UnMask_all(kal_uint32 unmask_bits)
{
	kal_uint32 index;

	for(index=0;index<EINT_TOTAL_CHANNEL;index++)
	{
		if ((eint_is_dedicated & (1 << index)) && (unmask_bits & (1<< index)))
		{
			eint_set_l1_eint_enable(eint_is_dedicated_map[index], EINT_ENABLE);
			unmask_bits &= (~(1<< index));
		}
	}
	eint_set_unmask_all(unmask_bits);
}

/*************************************************************************
* FUNCTION
*  EINT_UnMask
*
* DESCRIPTION
*   This function implements Unmask of dedicated external interrupt source
*
* CALLS
*
* PARAMETERS
*  eintno         - external interrupt vector number
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EINT_UnMask(kal_uint8 eintno)
{
	if (eint_is_dedicated & (1 << eintno))
	{
		switch(eint_is_dedicated_map[eintno])
		{
			case DEDICATED_EINT0:
			{
				eint_set_l1_eint_enable(DEDICATED_EINT0, EINT_ENABLE);
				IRQUnmask(DEDICATED_EINT_IRQ0);
				break;
			}
			case DEDICATED_EINT1:
			{
				eint_set_l1_eint_enable(DEDICATED_EINT1, EINT_ENABLE);
				IRQUnmask(DEDICATED_EINT_IRQ1);
				break;
			}
			case DEDICATED_EINT2:
			{
				eint_set_l1_eint_enable(DEDICATED_EINT2, EINT_ENABLE);
				IRQUnmask(DEDICATED_EINT_IRQ2);
				break;
			}
			case DEDICATED_EINT3:
			{
				eint_set_l1_eint_enable(DEDICATED_EINT3, EINT_ENABLE);
				IRQUnmask(DEDICATED_EINT_IRQ3);
				break;
			}
			default:
				return;
		}

	}
	else
	{
		eint_set_irqen(eintno,EINT_ENABLE);
	}
}

/*************************************************************************
* FUNCTION
*  DEINT_Mask
*
* DESCRIPTION
*   This function implements mask of dedicated external interrupt source
*
* CALLS
*
* PARAMETERS
*  deintno         - external interrupt vector number
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
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

/*************************************************************************
* FUNCTION
*  EINT_HISR_Entry
*
* DESCRIPTION
*  This function implements main external interrupt HISR registered in
*  global ISR jump table, eint_hisr_func.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EINT_HISR_Entry(void)
{
   kal_uint8 index;

   for(index=0;index<EINT_TOTAL_CHANNEL;index++)
   {
      if ( !(eint_is_dedicated & (1 << index)) && (EINT_FUNC.eint_active[index] == KAL_TRUE) 
	  	&& (EINT_FUNC.eint_func[index]) ) 
   	  {

         EINT_FUNC.eint_active[index] = KAL_FALSE;

         eint_trigger_src_log[eint_trigger_src_ptr] = index;
         eint_trigger_src_ptr = (eint_trigger_src_ptr + 1) % EINT_TRIGGER_SRC_LOG_MAX;

         EINT_FUNC.eint_func[index]();

         if (EINT_FUNC.eint_auto_umask[index] == KAL_TRUE) 
         {

            EINT_UnMask(index);
         }
      }
   }
}

/*************************************************************************
* FUNCTION
*  DEINT_HISR_Entry
*
* DESCRIPTION
*  This function implements main dedicated external interrupt HISR registered in
*  global ISR jump table, eint_hisr_func.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void DEINT_HISR_Entry(void)
{
   kal_uint8 index;

   for(index=0;index<EINT_TOTAL_CHANNEL;index++)
   {
	if (eint_is_dedicated & (1 << index))
	{
		if ( (EINT_FUNC.eint_active[index] == KAL_TRUE) && (EINT_FUNC.eint_func[index]) ) 
	   	  {

	         EINT_FUNC.eint_active[index] = KAL_FALSE;

	         EINT_FUNC.eint_func[index]();

	         if (EINT_FUNC.eint_auto_umask[index] == KAL_TRUE) 
	         {
	            EINT_UnMask(index);
	         }
	      }
	}
   }
}


/*************************************************************************
* FUNCTION
*  EINT_Internal_LISR_Handler
*
* DESCRIPTION
*   Internal function of External Interrupt Service Routine
*
* CALLS
*
* PARAMETERS
*  The value of EINT_STA
*
* RETURNS
*  If the original LISR flow should be bypassed
*
*************************************************************************/
kal_bool EINT_Internal_LISR_Handler(kal_uint32* status)
{
    kal_bool retval = KAL_FALSE;

#if defined(__AST_EINT__) && defined(__AST_TL1_TDD__)
    AST_EINT_HANDLER(status);
#endif

#if defined(IC_BURNIN_TEST) || defined(IC_MODULE_TEST)
    BTMT_EINT_HANDLER(status);
#endif

    return retval;
}
extern kal_uint32 eint_src_map[EINT_MAX_CHANNEL];
/*************************************************************************
* FUNCTION
*  Register_EINT
*
* DESCRIPTION
*   This function implements registration of external interrupts
*
* CALLS
*
* PARAMETERS
*  eintno            -     External interrupt vector number
*  Dbounce_En        -     Debounce control enable
*  ACT_Polarity      -     Interrupt polarity
*  reg_hisr          -     Registered hisr
*  auto_umask        -     A flag instruct the systerm to do unmask after
*                          invoking the registered HISR
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
 *************************************************************************/
void EINT_Registration(kal_uint8 eintno, kal_bool Dbounce_En, kal_bool ACT_Polarity, void (reg_hisr)(void), kal_bool auto_umask)
{
//	PDN_CLR(PDN_GPIO);
	kal_uint32 savedMask;

	/* If EINT Number is out of range, get return address and send it to exception handler */
	if(eintno >= EINT_TOTAL_CHANNEL)
	{
	   kal_uint32 retaddr;
	   
	   GET_RETURN_ADDRESS(retaddr);
	   kal_fatal_error_handler(KAL_ERROR_DRV_EINT_INVALID_INDEX, retaddr);
	}
   
	/*disable eint interrupt*/
	eint_set_irqen(eintno, EINT_DISABLE);

	/*register LISR*/
	/*dispatch for dedicated eint*/
	if (eint_is_dedicated & (1<<eintno))
	{
		switch(eint_is_dedicated_map[eintno])
		{
			case DEDICATED_EINT0:
			{
				eint_set_l1_eint_enable(DEDICATED_EINT0, EINT_DISABLE);
				IRQ_Register_LISR(DEDICATED_EINT_IRQ0, DEINT0_LISR, "DEINT0 handler");
			}
			break;
			case DEDICATED_EINT1:
			{
				eint_set_l1_eint_enable(DEDICATED_EINT1, EINT_DISABLE);
				IRQ_Register_LISR(DEDICATED_EINT_IRQ1, DEINT1_LISR, "DEINT1 handler");
			}
			break;
			case DEDICATED_EINT2:
			{
				eint_set_l1_eint_enable(DEDICATED_EINT2, EINT_DISABLE);
				IRQ_Register_LISR(DEDICATED_EINT_IRQ2, DEINT2_LISR, "DEINT2 handler");
			}
			break;
			case DEDICATED_EINT3:
			{
				eint_set_l1_eint_enable(DEDICATED_EINT3, EINT_DISABLE);
				IRQ_Register_LISR(DEDICATED_EINT_IRQ3, DEINT3_LISR, "DEINT3 handler");
			}
			break;
			default:
			break;
		}
	}
	else
	{
		IRQ_Register_LISR(IRQ_EIT_CODE, EINT_LISR, "EINT handler");
	}

   /* Save and set MCU's I,F bits to disable interrupts */
//   savedMask = LockIRQ();

   /* Set external interrupt polarity */
   EINT_Set_Polarity(eintno,ACT_Polarity);
#if !defined(MT6290)
   gpio_set_eint_src(eintno,eint_src_map[eintno]);
#endif
   if (Dbounce_En)
   {
   	 //eint_set_debounce_duration(eintno,EINT_DB_DUR_DEFAULT);
	 eint_set_debounce_enable(eintno,EINT_ENABLE);
   }
   else
   {
     /*disable debounce */
     eint_set_debounce_enable(eintno,EINT_DISABLE);
   }

   /* Save and set MCU's I,F bits to disable interrupts */
   savedMask = SaveAndSetIRQMask();

   /* Register external interrupt's HISR */
   EINT_FUNC.eint_func[eintno] = reg_hisr;
   EINT_FUNC.eint_active[eintno] = KAL_FALSE;
   EINT_FUNC.eint_auto_umask[eintno] = auto_umask;

	if (eint_is_dedicated & (1<<eintno))
	{
		/* register HISR */
		DRV_Register_HISR(DRV_DEINT_HISR_ID, DEINT_HISR_Entry);
		EINT_L2_ACK(eintno);
		EINT_UnMask(eintno);
		RestoreIRQMask(savedMask);
	}
	else
	{
		/* register HISR */
		DRV_Register_HISR(DRV_EINT_HISR_ID, EINT_HISR_Entry);
		EINT_L2_ACK(eintno);
		EINT_UnMask(eintno);
		IRQSensitivity( IRQ_EIT_CODE, LEVEL_SENSITIVE );
		/* Enable external interrupt */
		IRQUnmask( IRQ_EIT_CODE );
		RestoreIRQMask(savedMask);
	}
}


void EINT_Registration_and_mask(kal_uint8 eintno, kal_bool Dbounce_En, kal_bool ACT_Polarity, void (reg_hisr)(void), kal_bool auto_umask)
{
//	PDN_CLR(PDN_GPIO);
	kal_uint32 savedMask;

	/* If EINT Number is out of range, get return address and send it to exception handler */
	if(eintno >= EINT_TOTAL_CHANNEL)
	{
	   kal_uint32 retaddr;
	   
	   GET_RETURN_ADDRESS(retaddr);
	   kal_fatal_error_handler(KAL_ERROR_DRV_EINT_INVALID_INDEX, retaddr);
	}
   
	/*disable eint interrupt*/
	eint_set_irqen(eintno, EINT_DISABLE);

	/*register LISR*/
	/*dispatch for dedicated eint*/
	if (eint_is_dedicated & (1<<eintno))
	{
		switch(eint_is_dedicated_map[eintno])
		{
			case DEDICATED_EINT0:
			{
				eint_set_l1_eint_enable(DEDICATED_EINT0, EINT_DISABLE);
				IRQ_Register_LISR(DEDICATED_EINT_IRQ0, DEINT0_LISR, "DEINT0 handler");
			}
			break;
			case DEDICATED_EINT1:
			{
				eint_set_l1_eint_enable(DEDICATED_EINT1, EINT_DISABLE);
				IRQ_Register_LISR(DEDICATED_EINT_IRQ1, DEINT1_LISR, "DEINT1 handler");
			}
			break;
			case DEDICATED_EINT2:
			{
				eint_set_l1_eint_enable(DEDICATED_EINT2, EINT_DISABLE);
				IRQ_Register_LISR(DEDICATED_EINT_IRQ2, DEINT2_LISR, "DEINT2 handler");
			}
			break;
			case DEDICATED_EINT3:
			{
				eint_set_l1_eint_enable(DEDICATED_EINT3, EINT_DISABLE);
				IRQ_Register_LISR(DEDICATED_EINT_IRQ3, DEINT3_LISR, "DEINT3 handler");
			}
			break;
			default:
			break;
		}
	}
	else
	{
		IRQ_Register_LISR(IRQ_EIT_CODE, EINT_LISR, "EINT handler");
	}

   /* Save and set MCU's I,F bits to disable interrupts */
//   savedMask = LockIRQ();

   /* Set external interrupt polarity */
   EINT_Set_Polarity(eintno,ACT_Polarity);
#if !defined(MT6290)
	  gpio_set_eint_src(eintno,eint_src_map[eintno]);
#endif

   if (Dbounce_En)
   {
   	 //eint_set_debounce_duration(eintno,EINT_DB_DUR_DEFAULT);
	 eint_set_debounce_enable(eintno,EINT_ENABLE);
   }
   else
   {
     /*disable debounce */
     eint_set_debounce_enable(eintno,EINT_DISABLE);
   }

   /* Save and set MCU's I,F bits to disable interrupts */
   savedMask = SaveAndSetIRQMask();

   /* Register external interrupt's HISR */
   EINT_FUNC.eint_func[eintno] = reg_hisr;
   EINT_FUNC.eint_active[eintno] = KAL_FALSE;
   EINT_FUNC.eint_auto_umask[eintno] = auto_umask;

	if (eint_is_dedicated & (1<<eintno))
	{
		/* register HISR */
		DRV_Register_HISR(DRV_DEINT_HISR_ID, DEINT_HISR_Entry);
		EINT_L2_ACK(eintno);
		//EINT_UnMask(eintno);
		RestoreIRQMask(savedMask);
	}
	else
	{
		/* register HISR */
		DRV_Register_HISR(DRV_EINT_HISR_ID, EINT_HISR_Entry);
		EINT_L2_ACK(eintno);
		//EINT_UnMask(eintno);
		IRQSensitivity( IRQ_EIT_CODE, LEVEL_SENSITIVE );
		/* Enable external interrupt */
		IRQUnmask( IRQ_EIT_CODE );
		RestoreIRQMask(savedMask);
	}
}


/*************************************************************************
* FUNCTION
*  EXTRA_EINT_Registration
*
* DESCRIPTION
*   This function implements registration of external interrupts
*
* CALLS
*
* PARAMETERS
*  eintno            -     External interrupt vector number
*  ACT_Polarity      -     Interrupt polarity
*  reg_hisr          -     Registered hisr
*  auto_umask        -     A flag instruct the systerm to do unmask after
*                          invoking the registered HISR
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EXTRA_EINT_Registration(kal_uint8 eintno, kal_bool ACT_Polarity, void (reg_hisr)(void), \
                             kal_bool auto_umask)
{
   ASSERT((eintno < EINT_TOTAL_CHANNEL) && EINT_CheckNotHWDebounce(eintno) );

   EINT_Registration(eintno, KAL_FALSE, ACT_Polarity, reg_hisr, auto_umask);
}

/*************************************************************************
* FUNCTION
*  EINT_Query_HW_Debounce
*
* DESCRIPTION
*   This function dedicates to query the hardware debounce status
*   interrupts.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*   The hardware debounce disabled indicator bitmask
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 EINT_Query_HW_Debounce(void)
{
   kal_uint8 index;
   kal_uint32 status = 0x0;

   for (index = 0; index < EINT_TOTAL_CHANNEL; index++)
   {
      if ( (EINT_FUNC.eint_func[index]) && 
            ((EINT_CheckNotHWDebounce(index)) || !eint_get_debounce_enable(index)) )
      {
         status |= (0x1 << index);;
      }
   }

   return status;
}

/*************************************************************************
* FUNCTION
*  EINT_Set_HW_Debounce
*
* DESCRIPTION
*   This function dedicates to set the hardware debounce time of external 
*   interrupts.
*
* CALLS
*
* PARAMETERS
*   eintno   -   External interrupt vector number
*   ms       -   hardware debounce time (in milli second)
*
* RETURNS
*   No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EINT_Set_HW_Debounce(kal_uint8 eintno, kal_uint32 ms)
{
   kal_uint32 cnt;

   eint_set_debounce_enable(eintno,EINT_DISABLE);

   if(ms == 0)
   {
      /* set to one 32KHz clock cycle */
      cnt = 1;
   }
   else if(ms <= 500)
   {
      /* calculate cnt value based on 32KHz clock cycles */
#ifdef __FPGA__
      cnt = (ms*1000)/31;
#else
      cnt = ms << 5;
#endif
   }
   else
   {
      /* set to maximum count */
       cnt = EINT_DB_DUR_MAX;
   }

   eint_set_debounce_duration(eintno,cnt);
   eint_set_debounce_enable(eintno,EINT_ENABLE);
}

/*************************************************************************
* FUNCTION
*  EINT_Set_HW_Debounce_32KCycle
*
* DESCRIPTION
*   This function dedicates to set the hardware debounce time of external 
*   interrupts.
*
* CALLS
*
* PARAMETERS
*   eintno   -   External interrupt vector number
*   count_of_32kcycle       -   hardware debounce time (unit is 32k cycle)
*
* RETURNS
*   No return
*
* GLOBALS AFFECTED
*
*************************************************************************/

void EINT_Set_HW_Debounce_32KCycle(kal_uint8 eintno, kal_uint32 count_of_32kcycle)
{
   eint_set_debounce_enable(eintno,EINT_DISABLE);

   eint_set_debounce_duration(eintno,count_of_32kcycle);

   eint_set_debounce_enable(eintno,EINT_ENABLE);
}


/*************************************************************************
*  @brief  set the debounce enable parameter of the eint
*  @param  eintno        :  the eint index to be set
*  @param  debounce_en :	the debounce enable value to set, it should be 0~1
*				  		0: enable debounce function
*				  		1: disable debounce function
*  @return No return
*************************************************************************/
void EINT_Set_HW_Debounce_Enable(kal_uint8 eintno, kal_uint32 debounce_en)
{
	eint_set_debounce_enable(eintno,debounce_en);
//	eint_udelay(60);
}

/*************************************************************************
* FUNCTION
*  EINT_Set_Polarity
*
* DESCRIPTION
*   This function sets the polarity of external interrupts
*
* CALLS
*
* PARAMETERS
*  eintno            -     External interrupt vector number
*  ACT_Polarity      -     Interrupt polarity
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EINT_Set_Polarity(kal_uint8 eintno, kal_bool ACT_Polarity)
{
//   kal_uint32 savedMask;
   kal_uint32 debounce_en;

   /*disable EINT interrupt*/
   //EINT_Mask(eintno);

   /* Set external interrupt polarity */
   debounce_en = eint_get_debounce_enable(eintno);
   eint_set_debounce_enable(eintno, EINT_DISABLE);

//   savedMask = SaveAndSetIRQMask();   
   eint_set_pol(eintno,ACT_Polarity);
   
   eint_set_debounce_enable(eintno, debounce_en);

   EINT_L2_ACK(eintno);
   
   /*enable EINT interrupt*/
   //EINT_UnMask(eintno);
}


/*************************************************************************
* FUNCTION
*  EINT_Set_Sensitivity
*
* DESCRIPTION
*   This function dedicates to set the sensitivity of external 
*   interrupts.
*
* CALLS
*
* PARAMETERS
*   eintno   -   External interrupt vector number
*   sens     -   EDGE_SENSITIVE or LEVEL_SENSITIVE
*
* RETURNS
*   0 for success; 1 for failure
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32 EINT_Set_Sensitivity(kal_uint8 eintno, kal_bool sens)
{
	kal_uint32 savedMask;

	/* Save and set MCU's I,F bits to disable interrupts */
	savedMask = SaveAndSetIRQMask();

	if (eint_is_dedicated & (1<<eintno))
	{
		switch(eint_is_dedicated_map[eintno])
		{
			case DEDICATED_EINT0:
			{
				IRQSensitivity( DEDICATED_EINT_IRQ0, sens);
			}
			break;
			
			case DEDICATED_EINT1:
			{
				IRQSensitivity( DEDICATED_EINT_IRQ1, sens );
			}
			break;
			
			case DEDICATED_EINT2:
			{
				IRQSensitivity( DEDICATED_EINT_IRQ2, sens );
			}
			break;
			
			case DEDICATED_EINT3:
			{
				IRQSensitivity( DEDICATED_EINT_IRQ3, sens );
			}
			break;
			
			default:
			break;
		}		
	}

	if(sens == EDGE_SENSITIVE)
	{
		  sens = EINT_EDGE_SENSITIVITY;
	}
	else if(sens == LEVEL_SENSITIVE)
	{
		  sens = EINT_LEVEL_SENSITIVITY;
	}

	eint_set_type(eintno, sens);

	/* Restore previous MCU's I,F bits setting */
	RestoreIRQMask(savedMask);

	return 0;
}


/*************************************************************************
* FUNCTION
*  EINT_TIMER_CALLBACK
*
* DESCRIPTION
*   This function implements main external interrupt LISR registered in
*  global ISR jump table.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void EINT_TIMER_CALLBACK(void *data)
{
   EINT_SW_DEBOUNCE_STRUCT *sw_debounce = (EINT_SW_DEBOUNCE_STRUCT *)data;

   IRQMask(IRQ_EIT_CODE);

   if(sw_debounce->eint_sw_debounce_handle != 0x7f)
   {
      DclSGPT_Control(sw_debounce->eint_sw_debounce_handle,SGPT_CMD_STOP,0);
      DclSGPT_Close(&(sw_debounce->eint_sw_debounce_handle));
   }
	//EINT_PRINT("\tEINT_TIMER_CALLBACK, sw_debounce->eint_no = %d",sw_debounce->eint_no);
   sw_debounce->eint_intr_allow = (sw_debounce->eint_intr_allow == KAL_TRUE)? KAL_FALSE: KAL_TRUE;

   /*
    * This timer is to avoid if interrupt status is changed but 
    * sw_debounce->eint_intr_allow is still in KAL_TRUE state
    * because of no interrupt
    */
   if (sw_debounce->eint_intr_allow) 
   {
      SGPT_CTRL_START_T start;

      start.u2Tick= eint_sw_debounce_time_delay[sw_debounce->eint_no];

      start.pfCallback=EINT_TIMER_CALLBACK;
      start.vPara=data;
      sw_debounce->eint_sw_debounce_handle=DclSGPT_Open(DCL_GPT_CB,0);
      DclSGPT_Control(sw_debounce->eint_sw_debounce_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
   }
   IRQUnmask(IRQ_EIT_CODE);
   EINT_UnMask(sw_debounce->eint_no);
}

/*************************************************************************
* FUNCTION
*  EINT_TIMER_CALLBACK
*
* DESCRIPTION
*   This function implements main external interrupt LISR registered in
*  global ISR jump table.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void DEINT_TIMER_CALLBACK(void *data)
{
   EINT_SW_DEBOUNCE_STRUCT *sw_debounce = (EINT_SW_DEBOUNCE_STRUCT *)data;

   EINT_Mask(sw_debounce->eint_no);

   if(sw_debounce->eint_sw_debounce_handle != 0x7f)
   {
      DclSGPT_Control(sw_debounce->eint_sw_debounce_handle,SGPT_CMD_STOP,0);
      DclSGPT_Close(&(sw_debounce->eint_sw_debounce_handle));
   }

   sw_debounce->eint_intr_allow = (sw_debounce->eint_intr_allow == KAL_TRUE)? KAL_FALSE: KAL_TRUE;

   /*
    * This timer is to avoid if interrupt status is changed but 
    * sw_debounce->eint_intr_allow is still in KAL_TRUE state
    * because of no interrupt
    */
   if (sw_debounce->eint_intr_allow) 
   {
      SGPT_CTRL_START_T start;

      start.u2Tick= eint_sw_debounce_time_delay[sw_debounce->eint_no];

      start.pfCallback=DEINT_TIMER_CALLBACK;
      start.vPara=data;
      sw_debounce->eint_sw_debounce_handle=DclSGPT_Open(DCL_GPT_CB,0);
      DclSGPT_Control(sw_debounce->eint_sw_debounce_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
   }
   EINT_UnMask(sw_debounce->eint_no);
}

/*************************************************************************
* FUNCTION
*   EINT_LISR
*
* DESCRIPTION
*   Entry function of External Interrupt Service Routine
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTE
*
*************************************************************************/
void EINT_LISR(void)
{
   kal_uint8 index;
   kal_uint32 status,mask_bits;

   status = EINT_L2_STA();
   
   if (EINT_Internal_LISR_Handler(&status))
   {
      return;
   }

   // for conventional external interrupt!
   for(index=0;index<EINT_TOTAL_CHANNEL;index++)
   {
   	  //EINT_PRINT("\tEINT triggered!");
      if ( EINT_CheckHWDebounce(index) )
      {
      	 mask_bits = EINT_Get_Mask_Bits();
         if (status & EINT_STATUS_EINT(index) && !BU_G_BIT(mask_bits, index)) 
         {
            if(eint_sw_debounce[index].eint_sw_debounce_handle != 0x7f)
            {
               DclSGPT_Control(eint_sw_debounce[index].eint_sw_debounce_handle,SGPT_CMD_STOP,0);
               DclSGPT_Close(&(eint_sw_debounce[index].eint_sw_debounce_handle));
            }
            if ( (eint_sw_debounce[index].eint_intr_allow == KAL_FALSE) && 
                 (eint_sw_debounce_time_delay[index] > 0) 
               )
            {
               SGPT_CTRL_START_T start;
			   //EINT_PRINT("\tstart timer, eint_sw_debounce_time_delay[%d] = %d",index,eint_sw_debounce_time_delay[index]);
               eint_sw_debounce[index].eint_sw_debounce_handle=DclSGPT_Open(DCL_GPT_CB,0);

               start.u2Tick=eint_sw_debounce_time_delay[index];
               start.pfCallback=EINT_TIMER_CALLBACK;
               start.vPara=&eint_sw_debounce[index];
               DclSGPT_Control(eint_sw_debounce[index].eint_sw_debounce_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);

               EINT_Mask(index);
            }
            else
            {
               eint_sw_debounce[index].eint_intr_allow = KAL_FALSE;
               // disable interrupt
               EINT_Mask(index);
                //EINT_PRINT("\tEINT trigger HISR");
               ASSERT(EINT_FUNC.eint_func[index]!=NULL);
               if ( EINT_FUNC.eint_func[index] )
               {
                  EINT_FUNC.eint_active[index] = KAL_TRUE;

                  drv_active_hisr(DRV_EINT_HISR_ID);
               }
            }
            EINT_L2_ACK(index);
         }
      }
      else
      {
	     mask_bits = EINT_Get_Mask_Bits();
         if (status & EINT_STATUS_EINT(index)  && !BU_G_BIT(mask_bits, index)) 
         {
            EINT_Mask(index);
            ASSERT(EINT_FUNC.eint_func[index]!=NULL);
            if ( EINT_FUNC.eint_func[index] )
            { 
               EINT_FUNC.eint_active[index] = KAL_TRUE;

               drv_active_hisr(DRV_EINT_HISR_ID);
            }
            EINT_L2_ACK(index);
         }
      }
   }
}

void DEINT_Process(kal_uint8 deintno)
{
	kal_uint8 eintno;

	eintno = gpio_get_l1_eint_src(deintno);

	if ( EINT_CheckHWDebounce(eintno) )
	{
	  if(eint_sw_debounce[eintno].eint_sw_debounce_handle != 0x7f)
	  {
	     DclSGPT_Control(eint_sw_debounce[eintno].eint_sw_debounce_handle,SGPT_CMD_STOP,0);
	     DclSGPT_Close(&(eint_sw_debounce[eintno].eint_sw_debounce_handle));
	  }
	  if ( (eint_sw_debounce[eintno].eint_intr_allow == KAL_FALSE) && 
	       (eint_sw_debounce_time_delay[eintno] > 0) 
	     )
	  {
	     SGPT_CTRL_START_T start;
		 //EINT_PRINT("\tDEINT start timer, eint_sw_debounce_time_delay[index] = %d",eint_sw_debounce_time_delay[deintno]);
	     eint_sw_debounce[eintno].eint_sw_debounce_handle=DclSGPT_Open(DCL_GPT_CB,0);

	     start.u2Tick=eint_sw_debounce_time_delay[eintno];
	     start.pfCallback=DEINT_TIMER_CALLBACK;
	     start.vPara=&eint_sw_debounce[eintno];
	     DclSGPT_Control(eint_sw_debounce[eintno].eint_sw_debounce_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);

	     EINT_Mask(eintno);
	  }
	  else
	  {
	     eint_sw_debounce[eintno].eint_intr_allow = KAL_FALSE;
	     // disable interrupt
	     //EINT_PRINT("\tDEINT trigger HISR");
	     EINT_Mask(eintno);
	     ASSERT(EINT_FUNC.eint_func[eintno]!=NULL);
	     if ( EINT_FUNC.eint_func[eintno] )
	     {
	        EINT_FUNC.eint_active[eintno] = KAL_TRUE;

	        drv_active_hisr(DRV_DEINT_HISR_ID);
	     }
	  }
	}
	else
	{
	    EINT_Mask(eintno);
	    ASSERT(EINT_FUNC.eint_func[eintno]!=NULL);
	    if ( EINT_FUNC.eint_func[eintno] )
	    { 
	       EINT_FUNC.eint_active[eintno] = KAL_TRUE;

	       drv_active_hisr(DRV_DEINT_HISR_ID);
	    }
	}
}

/*************************************************************************
* FUNCTION
*   DEINT0_LISR
*
* DESCRIPTION
*   Entry function of Dedicated External Interrupt 0 Service Routine
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTE
*
*************************************************************************/
//void DEINT_LISR(void)
void DEINT0_LISR(void)
{
	DEINT_Process(DEDICATED_EINT0);
}

/*************************************************************************
* FUNCTION
*   DEINT1_LISR
*
* DESCRIPTION
*   Entry function of Dedicated External Interrupt 1 Service Routine
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTE
*
*************************************************************************/
//void DEINT_LISR(void)
void DEINT1_LISR(void)
{
	DEINT_Process(DEDICATED_EINT1);
}

/*************************************************************************
* FUNCTION
*   DEINT2_LISR
*
* DESCRIPTION
*   Entry function of Dedicated External Interrupt 2 Service Routine
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTE
*
*************************************************************************/
//void DEINT_LISR(void)
void DEINT2_LISR(void)
{
	DEINT_Process(DEDICATED_EINT2);
}

/*************************************************************************
* FUNCTION
*   DEINT3_LISR
*
* DESCRIPTION
*   Entry function of Dedicated External Interrupt 3 Service Routine
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTE
*
*************************************************************************/
//void DEINT_LISR(void)
void DEINT3_LISR(void)
{
	DEINT_Process(DEDICATED_EINT3);
}



/*************************************************************************
* FUNCTION
*  EINT_SaveAndMask
*
* DESCRIPTION
*  This function saves and masks the specified external interrupt
*
* PARAMETERS
*  eintno   -   external interrupt vector number
*
* RETURNS
*  original mask
*
*************************************************************************/
kal_uint32 EINT_SaveAndMask(kal_uint8 eintno)
{
   kal_uint32 savedMask, eint_mask;


   /* lockout interrupt */
   savedMask = SaveAndSetIRQMask();

   /* save EINT mask */
   eint_mask = EINT_Get_Mask_Bits();

   /* mask EINT */
   EINT_Mask(eintno);

   /* clear unnecessary bits */
   eint_mask = eint_mask & (0x0001 << eintno);

   /* un-lockout interrupt */
   RestoreIRQMask(savedMask);

   return eint_mask;
}


/*************************************************************************
* FUNCTION
*  EINT_RestoreMask
*
* DESCRIPTION
*  This function restores the MASK of the specified external interrupt
*
* PARAMETERS
*  val   -   value to restore
*
* RETURNS
*  No return
*
*************************************************************************/
void EINT_RestoreMask(kal_uint8 eintno, kal_uint32 val)
{
   kal_uint32 savedMask;


   /* lockout interrupt */   
   savedMask = SaveAndSetIRQMask();

   /*
    * NoteXXX: The external interrup should already be masked here (via the
    *          EINT_SaveAndMask() call). Only need to change the EINT_MASK 
    *          when the external interrupt is originally un-masked.
    */
   if (val == 0)
   {
       EINT_UnMask(eintno);
   }
   
   /* un-lockout interrupt */
   RestoreIRQMask(savedMask);
}

/*************************************************************************
* FUNCTION
*   EINT_SW_Debounce_Init
*
* DESCRIPTION
*   Initialize debounce time
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTE
*
*************************************************************************/
void EINT_SW_Debounce_Init(void)
{
   kal_uint8 index;

   for (index = 0; index < EINT_TOTAL_CHANNEL; index++)
   {
      eint_sw_debounce[index].eint_sw_debounce_handle = 0x7f;
      if( EINT_CheckHWDebounce(index) )
      {
         eint_sw_debounce[index].eint_intr_allow = KAL_FALSE;
         eint_sw_debounce[index].eint_no = index;
      }
   }

   #ifndef ATEST_DRV_ENABLE
	eint_sw_debounce_time_delay = custom_config_eint_sw_debounce_time_delay();
   #endif
}

/*************************************************************************
* FUNCTION
*   EINT_SW_Debounce_Modify
*
* DESCRIPTION
*   Setting debounce time
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*  No return
*
* GLOBALS AFFECTE
*
*************************************************************************/
kal_int32 EINT_SW_Debounce_Modify(kal_uint8 eintno, kal_uint8 debounce_time)
{
   kal_uint32 savedMask;
   
   if ( EINT_CheckNotHWDebounce(eintno))
      return -1;

   if(NULL == eint_sw_debounce_time_delay)
   {
       eint_sw_debounce_time_delay = custom_config_eint_sw_debounce_time_delay();
   }
   
   savedMask = SaveAndSetIRQMask();      
   eint_sw_debounce_time_delay[eintno] = debounce_time;
   RestoreIRQMask(savedMask);
   
   return 1;
}

/*************************************************************************
* FUNCTION
*  EINT_SaveAndMaskAll
*
* DESCRIPTION
*  This function saves and masks the specified external interrupt
*
* PARAMETERS
*  eintno   -   external interrupt vector number
*
* RETURNS
*  original mask
*
*************************************************************************/
kal_uint32 EINT_SaveAndMaskAll(void)
{
   kal_uint32 savedMask, eint_mask, eint_new_mask;

#if (EINT_TOTAL_CHANNEL < 32)
      eint_new_mask = (1<<EINT_TOTAL_CHANNEL)-1;
#else
      eint_new_mask = 0xffffffff;
#endif

   /* lockout interrupt */
   savedMask = SaveAndSetIRQMask();

   /* save EINT mask */
   eint_mask = EINT_Get_Mask_Bits();

   /* mask EINT */
   EINT_Set_Mask_all(eint_new_mask);

   /* un-lockout interrupt */
   RestoreIRQMask(savedMask);

   return eint_mask;
}



/*************************************************************************
* FUNCTION
*  EINT_RestoreMaskAll
*
* DESCRIPTION
*  This function restores the MASK of the specified external interrupt
*
* PARAMETERS
*  val   -   value to restore
*
* RETURNS
*  No return
*
*************************************************************************/
void EINT_RestoreMaskAll(kal_uint32 val)
{
   kal_uint32 savedMask;
#if 0 
/* under construction !*/
/* under construction !*/
#if !defined(__HW_US_TIMER_SUPPORT__)   
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

   /* lockout interrupt */   
   savedMask = SaveAndSetIRQMask();

   /*
    * NoteXXX: The external interrupt should already be masked here (via the
    *          EINT_SaveAndMask() call). Only need to change the EINT_MASK 
    *          when the external interrupt is originally un-masked.
    */
   EINT_Set_Mask_all(0xffffffff);
   EINT_Set_UnMask_all(~val);
   
   /* un-lockout interrupt */
   RestoreIRQMask(savedMask);
}



/*************************************************************************
* FUNCTION
*  EINT_SetSWRegister
*
* DESCRIPTION
*  This function set EINT SW interrupt register
*
* PARAMETERS
*
* RETURNS
*  none
*  
*************************************************************************/
void EINT_SetSWRegister(kal_uint8 eintno)
{
	//MT6290 not support this register
}

/*************************************************************************
* FUNCTION
*  EINT_ResetSWRegister
*
* DESCRIPTION
*  This function set EINT SW interrupt register
*
* PARAMETERS
*
* RETURNS
*  none
*  
*************************************************************************/
void EINT_ResetSWRegister(kal_uint8 eintno)
{
   //MT6290 not support this register
}

/*************************************************************************
* FUNCTION
*  EINT_Set_OwnerShip
*
* DESCRIPTION
*   This function sets the ownership of external interrupts
*
* CALLS
*
* PARAMETERS
*  eintno            -     External interrupt vector number
*  ownership      -     0: MD ownership, 1: AP ownerhship
*
* RETURNS
*  0 for success; -1 for failure
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_int32 EINT_Set_OwnerShip(kal_uint8 eintno, kal_uint8 ownership)
{
	eint_set_ownership(eintno,ownership);
	return EINT_OK;
}

/*************************************************************************
* FUNCTION
*  EINT_Set_Source_GPIO
*
* DESCRIPTION
*  This function set the signal of source GPIO as input signal of the specified external interrupt
*   
* PARAMETERS
*  eintno   -   External interrupt vector number
*  gpiono  -   the GPIO number to be set as source of the specified external interrupt.
                    
*
* RETURNS
*  No return
*
*************************************************************************/

kal_int32 EINT_Set_Source_GPIO(kal_uint8 eintno, kal_uint8 gpiono)
{
	if(gpio_set_eint_src(eintno,gpiono) != EINT_OK)
	{
		return EINT_FAIL;
	}

	return EINT_OK;
}

/*************************************************************************
* FUNCTION
*  EINT_Set_Dedicated_Eint
*
* DESCRIPTION
*  This function set the specified external interrupt as L1 IRQ, not shared irq.
*   
* PARAMETERS
*  Deintno   -  L1 external interrupt ID 0~3
*  eintno   -   External interrupt vector number
                    
*
* RETURNS
*  No return
*
*************************************************************************/
 kal_int32 EINT_Set_Dedicated_Eint(kal_uint8 Deintno, kal_uint8 eintno)
{
	if(gpio_set_l1_eint(Deintno,eintno,EINT_ENABLE) != EINT_OK)
	{
		return EINT_FAIL;
	}

	return EINT_OK;
}

 /*************************************************************************
* FUNCTION
*  DEINT_UnMask
*
* DESCRIPTION
*   This function implements Unmask of dedicated external interrupt source
*
* CALLS
*
* PARAMETERS
*  deintno         - external interrupt vector number
*
* RETURNS
*  No return
*
* GLOBALS AFFECTED
*
*************************************************************************/
void DEINT_Registration(kal_uint8 deintno,void (reg_hisr)(void))
{
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
#endif
}
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
#else
/*************************************/
/* just use to fix build error for unsupport project*/
/*************************************/
void EINT_Mask(kal_uint8 eintno) {	}
kal_uint32 EINT_Get_Mask_Bits(void) {	return 0;}
void EINT_Set_Mask_all(kal_uint32 mask_bits) {	}
void EINT_Set_UnMask_all(kal_uint32 unmask_bits) {}
void EINT_UnMask(kal_uint8 eintno) {}
void EINT_HISR_Entry(void) { }
void DEINT_HISR_Entry(void) {}
kal_bool EINT_Internal_LISR_Handler(kal_uint32* status) { return KAL_FALSE;}
void EINT_Registration(kal_uint8 eintno, kal_bool Dbounce_En, kal_bool ACT_Polarity, void (reg_hisr)(void), kal_bool auto_umask) {}
void EINT_Registration_and_mask(kal_uint8 eintno, kal_bool Dbounce_En, kal_bool ACT_Polarity, void (reg_hisr)(void), kal_bool auto_umask) {}
void EXTRA_EINT_Registration(kal_uint8 eintno, kal_bool ACT_Polarity, void (reg_hisr)(void),  kal_bool auto_umask) {  }
kal_uint32 EINT_Query_HW_Debounce(void) { return 0;}
void EINT_Set_HW_Debounce(kal_uint8 eintno, kal_uint32 ms) { }
void EINT_Set_HW_Debounce_32KCycle(kal_uint8 eintno, kal_uint32 count_of_32kcycle) {   }
void EINT_Set_HW_Debounce_Enable(kal_uint8 eintno, kal_uint32 debounce_en) {	}
void EINT_Set_Polarity(kal_uint8 eintno, kal_bool ACT_Polarity)  {}
kal_uint32 EINT_Set_Sensitivity(kal_uint8 eintno, kal_bool sens){	return 0;}
void EINT_TIMER_CALLBACK(void *data) { }
void DEINT_TIMER_CALLBACK(void *data) {  }
void EINT_LISR(void) {  }
void DEINT_Process(kal_uint8 deintno) {}
void DEINT0_LISR(void) {}
void DEINT1_LISR(void) {}
void DEINT2_LISR(void) {}
void DEINT3_LISR(void) {}
kal_uint32 EINT_SaveAndMask(kal_uint8 eintno) {  return 0;}
void EINT_RestoreMask(kal_uint8 eintno, kal_uint32 val) {   }
void EINT_SW_Debounce_Init(void) {}
kal_int32 EINT_SW_Debounce_Modify(kal_uint8 eintno, kal_uint8 debounce_time) { return 1;}
kal_uint32 EINT_SaveAndMaskAll(void) {  return 0;}
void EINT_RestoreMaskAll(kal_uint32 val) {  }
void EINT_SetSWRegister(kal_uint8 eintno) {}
void EINT_ResetSWRegister(kal_uint8 eintno) {}
kal_int32 EINT_Set_OwnerShip(kal_uint8 eintno, kal_uint8 ownership) {		return 0;}
kal_int32 EINT_Set_Source_GPIO(kal_uint8 eintno, kal_uint8 gpiono) {	return 0;}
 kal_int32 EINT_Set_Dedicated_Eint(kal_uint8 Deintno, kal_uint8 eintno) {	return 0;}
void DEINT_Registration(kal_uint8 deintno,void (reg_hisr)(void)) {}

#endif

