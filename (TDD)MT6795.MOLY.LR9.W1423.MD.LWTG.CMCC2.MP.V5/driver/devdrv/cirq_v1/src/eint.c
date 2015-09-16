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
 *   eint.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description: 
 * ------------
 *   This files define external interrupt management
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
 * removed!
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

/*************************************************************************
 * Included header files
 *************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "reg_base.h"
#include "intrCtrl.h"
#include "eint.h"
#include "dcl.h"
#include "drv_hisr.h"

#include "Eint_internal.h"
#include "kal_internal_api.h"

/*************************************************************************
 * Define global variables
 *************************************************************************/

#if defined(__EINT_SW_DEBOUNCE_V2__)
/* eint_hisr_activated_mask is mask of EINTs that trigger EINT IRQ and with */
/* SW de-bounce mechanism. Bits of eint_hisr_activated_mask is set in       */
/* EINT_LISR and cleared in EINT_HISR_Entry. It is used for LISR to tell    */
/* HISR which EINT(s) trigger interrupt and need to perform SW debounce      */
/* mechanism. When accessing this variable, be aware of race condition issue. */
static kal_uint32 eint_hisr_activated_mask = 0;

#if (EINT_TOTAL_CHANNEL > 32)
  #error "Mask of EINT exceeds 32 bits. Be sure to extend the eint_hisr_activated_mask."
#endif

#endif /* __EINT_SW_DEBOUNCE_V2__ */

eint_func EINT_FUNC;
static EINT_SW_DEBOUNCE_STRUCT eint_sw_debounce[EINT_MAX_CHANNEL];
static kal_uint8 *eint_sw_debounce_time_delay = NULL;

#if defined(__DEINT_DRIVER__)

kal_uint32      deint_enabled_mask = 0;     /* Used to record which DEINTs has registered. When one DEINT registers, this is */
                                            /* used to check whether is there already on DEINT reigsters to the same CINT. */
const kal_uint8 CINT2IRQCode[CINT_NUMBER] = {CINT_CODE_TABLE};    /* this array map cint index (0, 1, 2, ...) to real IRQ code */    
kal_uint8       CINT2DEINT[CINT_NUMBER];    /* Multipe DEINT may trigger CINT, but only one can be mapped to CINT */
                                            /* This array record which DEINT map to CINT during DEINT registraton */

#endif /* defined(__DEINT_DRIVER__) */

kal_uint32 eint_mask_caller;
kal_uint32 eint_unmask_caller;
kal_uint8 eint_mask_monitor_idx = EINT_TOTAL_CHANNEL;
kal_uint8 eint_unmask_monitor_idx = EINT_TOTAL_CHANNEL;

/* Variables to sources that triggers EINT interrupt */
kal_uint8 eint_trigger_src_log[EINT_TRIGGER_SRC_LOG_MAX] = {0x0};
kal_uint8 eint_trigger_src_ptr = 0;

/*************************************************************************
 * Define function prototpye
 *************************************************************************/
void EINT_HISR_Entry(void);
void EINT_TIMER_CALLBACK(void *data);
extern kal_uint32 DisableIRQ(void);
extern void RestoreIRQ(kal_uint32 irq);
extern kal_uint32 LockIRQ(void);
extern void BTMT_EINT_HANDLER(kal_uint32* status);

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
void EINT_Registration(kal_uint8 eintno, kal_bool Dbounce_En, kal_bool ACT_Polarity, \
                       void (reg_hisr)(void), kal_bool auto_umask)
{
   kal_uint32 savedMask;
   volatile kal_uint16 count;

   /* If EINT Number is out of range, get return address and send it to exception handler */
   if(eintno >= EINT_TOTAL_CHANNEL)
   {
       kal_uint32 retaddr;

       GET_RETURN_ADDRESS(retaddr);
       kal_fatal_error_handler(KAL_ERROR_DRV_EINT_INVALID_INDEX, retaddr);
   }
   
   IRQ_Register_LISR(IRQ_EIT_CODE, EINT_LISR, "EINT handler");

   /* Save and set MCU's I,F bits to disable interrupts */
   savedMask = LockIRQ();

   /* Set external interrupt polarity */
   if (ACT_Polarity) 
      EINTaddr(eintno) |= EINT_CON_HIGHLEVEL;
   else
      EINTaddr(eintno) &= ~(EINT_CON_HIGHLEVEL);

#if defined(__CIRQ_DESIGN_NEW__)
#if defined(__EINT_MD_DOMAIN_0__)
   *EINT_D0EN |= (1 << eintno);
#elif defined(__EINT_MD_DOMAIN_1__)
   *EINT_D1EN |= (1 << eintno);
#elif defined(__EINT_MD_DOMAIN_2__)
   /* Set domain as MD (domain 2) */
   *EINT_D2EN |= (1 << eintno);
#else
   #error "Unsupported EINT domain design"     
#endif
#endif

   /*
    * NoteXXX: Only EINT 0 ~ (EINT_MAX_CHANNLE - 1) support level trigger.
    *          The de-bounce time is only for level trigger EINT.
    */
    if ( EINT_CheckHWDebounce(eintno) ) {
      /* Set external interrupt debounce control enable or not */
      if (Dbounce_En) {
         /* check if debounce is enabled */
         if (EINTaddr(eintno) & EINT_CON_DEBOUNCE_EN) {
            /* debounce value is already set; NOP */
         } else {
            EINTaddr(eintno) |= (EINT_CON_DEBOUNCE | EINT_CON_DEBOUNCE_EN);
         }
      }
      else
      {
         /*disable debounce */
         EINTaddr(eintno) &= ~(EINT_CON_DEBOUNCE_EN);
      }
   }

   /* Register external interrupt's HISR */
   EINT_FUNC.eint_func[eintno] = reg_hisr;
   EINT_FUNC.eint_active[eintno] = KAL_FALSE;
   EINT_FUNC.eint_auto_umask[eintno] = auto_umask;

   /* register HISR */
   DRV_Register_HISR(DRV_EINT_HISR_ID, EINT_HISR_Entry);
   
   /* Restore previous MCU's I,F bits setting */
   RestoreIRQ(savedMask);

   /*
    * XXX!!!. Hardware bug
    *    - must wait for 32khz/1 sec to write mask register, will be
    *    fixed in future.
    */
   for (count=0; count<250; count++) ;  /*250:52M*/

   savedMask = LockIRQ();

   *EINT_INTACK = EINT_INTACK_EINT(eintno);
   EINT_UnMask(eintno);

   RestoreIRQ(savedMask);

   /* Set external interrupt is level sensitive */
   IRQSensitivity( IRQ_EIT_CODE, LEVEL_SENSITIVE );

   /* Enable external interrupt */
   IRQUnmask( IRQ_EIT_CODE );
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

#if defined (__EINT_SW_DEBOUNCE_V2__)
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
   kal_uint32 savedMask;
   kal_uint32 activatedMask;
   kal_uint32 cpsr_bak;

   /* Disable interrupt before accessing eint_hisr_activated_mask */
   savedMask = LockIRQ();
   activatedMask = eint_hisr_activated_mask;
   eint_hisr_activated_mask = 0;
   RestoreIRQ(savedMask);
   
   /* First part, check whether any EINT SW debounce flag is set in LISR */
   for(index = 0; index < EINT_TOTAL_CHANNEL; index++)
   {
       /* if an EINT with SW-Debounce triggered interrupt */
       if(activatedMask & (1 << index))
       {
           if(eint_sw_debounce[index].eint_sw_debounce_handle != 0x7f)
           {
               DclSGPT_Control(eint_sw_debounce[index].eint_sw_debounce_handle,SGPT_CMD_STOP,0);
               DclSGPT_Close(&(eint_sw_debounce[index].eint_sw_debounce_handle));
           }

           /* Start a period of SW De-Bounce */
           if(KAL_FALSE == eint_sw_debounce[index].eint_intr_allow)
           {
               SGPT_CTRL_START_T start;

               eint_sw_debounce[index].eint_sw_debounce_handle=DclSGPT_Open(DCL_GPT_CB,0);

               start.u2Tick=eint_sw_debounce_time_delay[index];
               start.pfCallback=EINT_TIMER_CALLBACK;
               start.vPara=&eint_sw_debounce[index];
               DclSGPT_Control(eint_sw_debounce[index].eint_sw_debounce_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
           }
           /* A period of SW De-Bounce times out. Enable HISR */
           else
           {
               eint_sw_debounce[index].eint_intr_allow = KAL_FALSE;
               EINT_FUNC.eint_active[index] = KAL_TRUE;
           }
       }
   }    

   for(index=0;index<EINT_TOTAL_CHANNEL;index++)
   {
      if ( (EINT_FUNC.eint_active[index] == KAL_TRUE) && (EINT_FUNC.eint_func[index]) ) 
      {
         /* eint_sw_debounce[index].eint_intr_allow may be modified in LISR */
         /* disable interrupt to protect this variable */
         cpsr_bak = LockIRQ();
         EINT_FUNC.eint_active[index] = KAL_FALSE;
         RestoreIRQ(cpsr_bak);

         eint_trigger_src_log[eint_trigger_src_ptr] = index;
         eint_trigger_src_ptr = (eint_trigger_src_ptr + 1) % EINT_TRIGGER_SRC_LOG_MAX;

         EINT_FUNC.eint_func[index]();

         if (EINT_FUNC.eint_auto_umask[index] == KAL_TRUE) 
         {
            EINT_UnMask(index);
         }
      }
   }

#if defined(IRQ_EOI2)
	*IRQ_EOI2 = IRQCode2Line[IRQ_EIT_CODE];
#else
	*IRQ_EOI = (1 << IRQCode2Line[IRQ_EIT_CODE]);
#endif	

}

#else /* __EINT_SW_DEBOUNCE_V2__ */

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
      if ( (EINT_FUNC.eint_active[index] == KAL_TRUE) && (EINT_FUNC.eint_func[index]) ) 
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

#if defined(IRQ_EOI2)
	*IRQ_EOI2 = IRQCode2Line[IRQ_EIT_CODE];
#else
	*IRQ_EOI = (1 << IRQCode2Line[IRQ_EIT_CODE]);
#endif	

}


#endif /* __EINT_SW_DEBOUNCE_V2__ */

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

#if defined(IC_BURNIN_TEST) || defined(IC_MODULE_TEST) || defined(__IC_SLT__)
    BTMT_EINT_HANDLER(status);
#endif

    return retval;
}

#if defined (__EINT_SW_DEBOUNCE_V2__)

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
   kal_uint32 status;
   kal_uint8  index;
   kal_uint8  enable_hisr = KAL_FALSE;

#if defined(__CIRQ_DESIGN_NEW__)
#if defined(__EINT_MD_DOMAIN_0__)
   status = (*EINT_STATUS) & (*EINT_D0EN);
#elif defined(__EINT_MD_DOMAIN_1__)
   status = (*EINT_STATUS) & (*EINT_D1EN);
#elif defined(__EINT_MD_DOMAIN_2__)
   status = (*EINT_STATUS) & (*EINT_D2EN);
#endif
#else
   status = *EINT_STATUS;
#endif

   status &= ~(*EINT_MASK);

   if (EINT_Internal_LISR_Handler(&status))
   {
      return;
   }

   // for conventional external interrupt!
   for(index=0;index<EINT_TOTAL_CHANNEL;index++)
   {
      if ( EINT_CheckHWDebounce(index) )
      {      
         if (status & EINT_STATUS_EINT(index)) 
         {
            EINT_Mask(index);			
            *EINT_INTACK = EINT_INTACK_EINT(index);

            /* Activate HISR to handle SW de-bounce */
            if (eint_sw_debounce_time_delay[index] > 0) 
            {
                /* Error condition: one EINT is triggered, and it is triggered agagin before it is processed in HISR */
                /* Because this EINT is masked in LISR, and unmasked in HISR. It shouldn't be triggered agagin before it is unmask */
                /* Possible condition that causes this assertion: EINT is unmasked abnormally. */
                ASSERT((eint_hisr_activated_mask & (1 << index)) == 0);
                eint_hisr_activated_mask |= (1 << index);
            }
            else
            {
                EINT_FUNC.eint_active[index] = KAL_TRUE;
            }
            /* ENT_HISR_Entry should be enabled, no matter to process HW de-boucne, or call call back function */
            enable_hisr = KAL_TRUE;         
         }
      }
      else
      {
         if (status & EINT_STATUS_EINT(index)) 
         {
             EINT_Mask(index);			 
             *EINT_INTACK = EINT_INTACK_EINT(index);

             EINT_FUNC.eint_active[index] = KAL_TRUE;         
             enable_hisr = KAL_TRUE;		 
         }
      }
   }
   
   if (KAL_TRUE == enable_hisr)
   {
       drv_active_hisr(DRV_EINT_HISR_ID);
   }
}

#else /* __EINT_SW_DEBOUNCE_V2__ */

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
   kal_uint32 status;

#if defined(__CIRQ_DESIGN_NEW__)
#if defined(__EINT_MD_DOMAIN_0__)
   status = (*EINT_STATUS) & (*EINT_D0EN);
#elif defined(__EINT_MD_DOMAIN_1__)
   status = (*EINT_STATUS) & (*EINT_D1EN);
#elif defined(__EINT_MD_DOMAIN_2__)
   status = (*EINT_STATUS) & (*EINT_D2EN);
#endif
#else
   status = *EINT_STATUS;
#endif

   if (EINT_Internal_LISR_Handler(&status))
   {
      return;
   }

   // for conventional external interrupt!
   for(index=0;index<EINT_TOTAL_CHANNEL;index++)
   {
      if ( EINT_CheckHWDebounce(index) )
      {
         if (status & EINT_STATUS_EINT(index)) 
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
               ASSERT(EINT_FUNC.eint_func[index]!=NULL);
               if ( EINT_FUNC.eint_func[index] )
               {
                  EINT_FUNC.eint_active[index] = KAL_TRUE;

                  drv_active_hisr(DRV_EINT_HISR_ID);
               }
            }
            *EINT_INTACK = EINT_INTACK_EINT(index);
         }
      }
      else
      {
         if (status & EINT_STATUS_EINT(index)) 
         {
            EINT_Mask(index);
            ASSERT(EINT_FUNC.eint_func[index]!=NULL);
            if ( EINT_FUNC.eint_func[index] )
            { 
               EINT_FUNC.eint_active[index] = KAL_TRUE;

               drv_active_hisr(DRV_EINT_HISR_ID);
            }
            *EINT_INTACK = EINT_INTACK_EINT(index);
         }
      }
   }
}

#endif /* __EINT_SW_DEBOUNCE_V2__ */

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
            ((EINT_CheckNotHWDebounce(index)) || !(EINTaddr(index) & EINT_CON_DEBOUNCE_EN)) )
      {
         status |= (0x1 << index);;
      }
   }

   return status;
}

#if defined(__CIRQ_DESIGN_NEW__) || defined(__CIRQ_HW_V3__)
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
// MTK02782 add 20110316 {
void EINT_Set_HW_Debounce(kal_uint8 eintno, kal_uint32 ms)
{
   kal_uint8  prescaler;
   kal_uint32 cnt;
   volatile kal_uint16 count;

   if(ms == 0)
   {
       /* set to one 32KHz clock cycle */
       prescaler = EINT_CON_PRESCALER_32KHZ;
       cnt = 1;
   }
   else if(ms <= 62)
   {
       prescaler = EINT_CON_PRESCALER_32KHZ;
       cnt = (ms << 5) + ms;
   }
   else if(ms <= 125)
   {
       prescaler = EINT_CON_PRESCALER_16KHZ;
       cnt = (ms << 4) + (ms >> 1);
   }
   else if(ms <= 250)
   {
       prescaler = EINT_CON_PRESCALER_8KHZ;
       cnt = (ms << 3) + (ms >> 2);
   }
   else if(ms <= 500)
   {
       prescaler = EINT_CON_PRESCALER_4KHZ;
       cnt = (ms << 2) + (ms >> 3);
   }
   else if(ms <= 1000)
   {
       prescaler = EINT_CON_PRESCALER_2KHZ;
       cnt = (ms << 1) + (ms >> 4);
   }
   else if(ms <= 2000)
   {
       prescaler = EINT_CON_PRESCALER_1KHZ;
       cnt = ms + (ms >> 5);
   }
   else if(ms <= 4000)
   {
       prescaler = EINT_CON_PRESCALER_512HZ;
       cnt = (ms >> 1) + (ms >> 6);
   }
   else if(ms <= 8000)
   {
       prescaler = EINT_CON_PRESCALER_256HZ;
       cnt = (ms >> 2) + (ms >> 7);
   }
   else
   {
      /* set to maximum prescaler/count */
       prescaler = EINT_CON_PRESCALER_256HZ;
       cnt = EINT_CON_DEBOUNCE;
   }

   if( cnt > EINT_CON_DEBOUNCE)
   {
       cnt = EINT_CON_DEBOUNCE;
   }
   
   /* clear original debounce value */
   EINTaddr(eintno) &= ~EINT_CON_DEBOUNCE;

   /* mask eint before modifying debounce value */
   EINT_Mask(eintno);

   /* clear prescaler value */
   EINTaddr(eintno) &= ~EINT_CON_PRESCALER_MASK;

   /* disable HW debounce */
   EINTaddr(eintno) &= ~EINT_CON_DEBOUNCE_EN;

   /* wait for 5T 32khz  */
   for (count=0; count<1250; count++) ;  /*250:52M*/

   /* set new debounce value and enable debounce control circuit */
   EINTaddr(eintno) |= (cnt | EINT_CON_DEBOUNCE_EN | (EINT_CON_PRESCALER_MASK&(prescaler<<EINT_CON_PRESCALER_OFFSET)));
   
   /* unmask eint after modifying debounce value */
   EINT_UnMask(eintno);
}
// } MTK02782 add 20110316 

#else
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

   if(ms == 0)
   {
      /* set to one 32KHz clock cycle */
      cnt = 1;
   }
   else if(ms <= 62)
   {
      /* calculate cnt value based on 32KHz clock cycles */
      cnt = ms << 5;
   }
   else
   {
      /* set to maximum count */
       cnt = EINT_CON_DEBOUNCE;
   }

   /* clear original debounce value */
   EINTaddr(eintno) &= ~EINT_CON_DEBOUNCE;

   /* set new debounce value */
   EINTaddr(eintno) |= (cnt | EINT_CON_DEBOUNCE_EN);
}
#endif

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
   kal_uint32 savedMask;
   volatile kal_uint32 count;

   /* Save and set MCU's I,F bits to disable interrupts */
   savedMask = LockIRQ();

   /* Set external interrupt polarity */
   if (ACT_Polarity) 
      EINTaddr(eintno) |= EINT_CON_HIGHLEVEL;
   else
      EINTaddr(eintno) &= ~(EINT_CON_HIGHLEVEL);

   for (count=0; count<250; count++) ;  /*250:52M*/

   *EINT_INTACK = EINT_INTACK_EINT(eintno);

#if defined(IRQ_EOI2)
   *IRQ_EOI2 = IRQCode2Line[IRQ_EIT_CODE];
#else   
   *IRQ_EOI = (1 << IRQCode2Line[IRQ_EIT_CODE]);
#endif
   
   /* Restore previous MCU's I,F bits setting */
   RestoreIRQ(savedMask);
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
   if ( EINT_CheckNotHWDebounce(eintno) ){
      /* not support level trigger */
      return 1;
   }
   /* Save and set MCU's I,F bits to disable interrupts */
   savedMask = LockIRQ();

#if defined(__CIRQ_DESIGN_NEW__)
   if (sens == EDGE_SENSITIVE) {
      *EINT_SENS_CLR = (1 << eintno);
   } else if (sens == LEVEL_SENSITIVE) {
      *EINT_SENS_SET = (1 << eintno);
   }
#else
   if (sens == EDGE_SENSITIVE) {
      *EINT_SENS &= ~(1 << eintno);
   } else if (sens == LEVEL_SENSITIVE) {
      *EINT_SENS |= (1 << eintno);
   }
#endif

   /* Restore previous MCU's I,F bits setting */
   RestoreIRQ(savedMask);

   return 0;
}


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
   /* get the return address */
   if (eintno == eint_mask_monitor_idx)
   {
      GET_RETURN_ADDRESS(eint_mask_caller);
   }
   *EINT_MASK_SET = (0x0001 << eintno);
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
   /* get the return address */
   if (eintno == eint_unmask_monitor_idx)
   {
      GET_RETURN_ADDRESS(eint_unmask_caller);
   }
   *EINT_MASK_CLR = (0x0001 << eintno);

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
   savedMask = LockIRQ();

   /* save EINT mask */
   eint_mask = *EINT_MASK;

   /* mask EINT */
   EINT_Mask(eintno);

   /* un-lockout interrupt */
   RestoreIRQ(savedMask);

   /* clear unnecessary bits */
   eint_mask = eint_mask & (0x0001 << eintno);

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
   savedMask = LockIRQ();

   /*
    * NoteXXX: The external interrup should already be masked here (via the
    *          EINT_SaveAndMask() call). Only need to change the EINT_MASK 
    *          when the external interrupt is originally un-masked.
    */
   if (val == 0) {
       EINT_UnMask(eintno);
   }
   
   /* un-lockout interrupt */
   RestoreIRQ(savedMask);
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
   savedMask = LockIRQ();

   /* save EINT mask */
   eint_mask = *EINT_MASK;

   /* mask EINT */
   *EINT_MASK_SET = eint_new_mask;

   /* un-lockout interrupt */
   RestoreIRQ(savedMask);

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
   kal_uint32 RTC_Count1, RTC_Count2;
   
#if !defined(__HW_US_TIMER_SUPPORT__)   
   RTC_Count1 = *(volatile kal_uint32 *)(TDMA_base + 0x230);
   do{
      RTC_Count2 = *(volatile kal_uint32 *)(TDMA_base + 0x230);
   }while( (RTC_Count2 - RTC_Count1) < 2);
#endif

   /* lockout interrupt */   
   savedMask = LockIRQ();

   /*
    * NoteXXX: The external interrupt should already be masked here (via the
    *          EINT_SaveAndMask() call). Only need to change the EINT_MASK 
    *          when the external interrupt is originally un-masked.
    */
   *EINT_MASK_SET = 0xffffffff;
   *EINT_MASK_CLR = ~(val);
   
   /* un-lockout interrupt */
   RestoreIRQ(savedMask);
}

#if defined(__EINT_SW_DEBOUNCE_V2__)
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

   /* IRQ need not be masked since EINT_TIMER_CALLBACK has no race condition problem with EINT_HISRY_Entry and EINT_LISR */
   //IRQMask(IRQ_EIT_CODE);

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

      start.pfCallback=EINT_TIMER_CALLBACK;
      start.vPara=data;
      sw_debounce->eint_sw_debounce_handle=DclSGPT_Open(DCL_GPT_CB,0);
      DclSGPT_Control(sw_debounce->eint_sw_debounce_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);
   }
   //IRQUnmask(IRQ_EIT_CODE);
   EINT_UnMask(sw_debounce->eint_no);
}

#else /* #if defined(__EINT_SW_DEBOUNCE_V2__) */

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

#endif    /* __EINT_SW_DEBOUNCE_V2__ */

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

   eint_sw_debounce_time_delay = custom_config_eint_sw_debounce_time_delay();
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
   
   savedMask = DisableIRQ();      
   eint_sw_debounce_time_delay[eintno] = debounce_time;
   RestoreIRQ(savedMask);
   
   return 1;
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
#ifdef __CIRQ_DESIGN_NEW__
    *EINT_SOFT_SET = (1 << eintno);
#elif defined(EINT_SOFT)
    kal_uint32 savedMask = LockIRQ();
    *EINT_SOFT |= (1<<eintno);
    RestoreIRQ(savedMask);
#endif
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
#ifdef __CIRQ_DESIGN_NEW__
    *EINT_SOFT_CLR = (1 << eintno);
#elif defined(EINT_SOFT)
    kal_uint32 savedMask = LockIRQ();
    *EINT_SOFT &= ~(1<<eintno);
    RestoreIRQ(savedMask);
#endif
}

/*************************************************************************
* FUNCTION
*  EINT_AckInt
*
* DESCRIPTION
*  This function acks interrupt and clears status bit.
*
* PARAMETERS
*
* RETURNS
*  none
*
*************************************************************************/
void EINT_AckInt(kal_uint8 eintno)
{
    *EINT_INTACK = EINT_INTACK_EINT(eintno);
}

#if defined(__AST_TL1_TDD__) && defined(__CIRQ_DESIGN_NEW__)    /* EINT_D0EN is only designed in __CIRQ_DESIGN_NEW__ */
/*************************************************************************
* FUNCTION
*  EINT_Set_Domain
*
* DESCRIPTION
*  This function set EINT Domain 0 Register
*
* PARAMETERS
*
* RETURNS
*  none
*  
* GLOBALS AFFECTE
*
*************************************************************************/
void EINT_Set_Domain_Disable(kal_uint8 eintno)
{
    /*********************************************************************
      * This function is only used under MT6256E2 with AST configuration. The reason is
      * AST is connected to CINT originally, but there is a bug in MT6256E2 that interrupt 
      * from CINT cannot resume chip from sleep mode, and only EINT can do this.
      * Therefore, interrupt from AST will be connected to CIRQ (via CINT) and EINT to
      * resume chip from sleep mode when an interrupt is triggered. In this case, EINT
      * will triggered interrupt to CIRQ by EINT, which means there will be two sources
      * trigger interrut to CIRQ for the same event. To avoid this, we provide this API
      * to prevent EINT which is connected to AST from issuing interrupt to CIRQ and only 
      * CINT will trigger interrupt to CIRQ in this case.
      *******************************************************************/
    kal_uint32 savedMask, eint_en_mask;
	
    ASSERT(eintno < EINT_TOTAL_CHANNEL);

    savedMask = LockIRQ();

    eint_en_mask = *EINT_D0EN;
    eint_en_mask &= ~(1 << eintno);
    *EINT_D0EN = eint_en_mask;

    RestoreIRQ(savedMask);
}
#endif

#if defined(__DEINT_DRIVER__)

/*************************************************************************
* FUNCTION
*   DEINT_LISR
*
* DESCRIPTION
*   Callback function of all DEINT. This function calls corresponding
*   EINT callback function of current IRQ. Which callback function
*   should be called is based on processing_irqx
*
* CALLS
*   None
*
* PARAMETERS
*   None
*
* RETURNS
*   None
*
* GLOBALS AFFECT
*
*************************************************************************/
void DEINT_LISR()
{
    kal_uint32 deint_no, cint;
    kal_uint32 i;
    kal_uint16 currentIrq;
    
    /* Retrieve current IRQ line and translate to IRQ code */
    /* This is necessary because this LISR is shared by    */
    /* all CINT.                                           */
    currentIrq = IRQ_Current_LISR();
    
    /* Find which CINT maps to the current interrupt by    */
    /* scanning the CINT-to-IRQCode array                  */
    for(cint = 0; cint < CINT_NUMBER; cint++)
    {
        if(CINT2IRQCode[cint] == currentIrq)
        {
            break;
        }
    }
    
    /* If current IRQ is not from one of CINT, assert      */
    ASSERT(cint < CINT_NUMBER); 
    
    /* Find which one DEINT triggers interrupt. CINT2DEINT */
    /* is constructed when DEINT_Registration() is called  */
    deint_no = CINT2DEINT[cint];
    
    EINT_FUNC.eint_func[deint_no]();
    
    *EINT_INTACK = EINT_INTACK_EINT(deint_no);
}

/*************************************************************************
* FUNCTION
*   DEINT_Registration
*
* DESCRIPTION
*   This function returns CINT code of input DEINT number.
*
* CALLS
*   None
*
* PARAMETERS
*   deint_no - DEINT number
*   reg_lisr - Callback function pointer
*
* RETURNS
*   None
*
* GLOBALS AFFECT
*
*************************************************************************/
void DEINT_Registration(kal_uint8 deint_no, void (reg_lisr)(void))
{
    kal_uint32 cint, irqCode, savedMask;

    ASSERT(reg_lisr != NULL);
    ASSERT(deint_no < EINT_TOTAL_CHANNEL);  
    
    /* Find the corresponding CINT index (0, 1, 2, ...) of deint_no */  
    cint = DEINT_2_CINT(deint_no);
    
    /* Check if CINT is registered by another DEINT in the same group */
    /* Since EINT_STATUS doesn't assert when DEINT trigger interrupt, */
    /* if more than one DEINT register to the same CINT, it is        */
    /* impossible to know which DEINT triggers interrupt. So only one */
    /* DEINT in the same group can register.                          */
    ASSERT((deint_enabled_mask & DEINT_GROUP_MASK(cint)) == 0);


    /* Get corresponding IRQ code for LISR registration, and unmask */
    irqCode = (kal_uint32)CINT2IRQCode[cint];

    savedMask = LockIRQ();    
    /* set registered mask */
    deint_enabled_mask |= (1 << deint_no);
    
    /* Register DEINT_LISR() as IRQ callback function. Note that all CINT share the same LISR. */
    IRQ_Register_LISR(irqCode, DEINT_LISR, "DEINT handler");
    
    /* Register handler to EINT */
    EINT_FUNC.eint_func[deint_no] = reg_lisr;
    
    /* Store mapping of CINT and DEINT                                                   */
    /* When DEINT triggers, EINT_STATUS doesn't assert. DEINT_LISR() needs to write ACK. */
    /* But DEINT_LISR() cannot not know which DEINT triggers from EINT_STATUS. It is     */
    /* necessary to record which one DEINT maps to CINT.                                 */
    CINT2DEINT[cint] = deint_no;
    
    RestoreIRQ(savedMask);


    /* Set external interrupt as level sensitive */
    IRQSensitivity(irqCode, LEVEL_SENSITIVE);

    *EINT_INTACK = EINT_INTACK_EINT(deint_no);

    /* Enable external interrupt                                   */
    /* Note that DEINT use IRQ to mask interrupt instead of DEINT. */
    /* Behavior of masking IRQ is equivalent to masking DEINT      */
    /* becasue CINT map to only one DEINT.                         */
    IRQUnmask(irqCode);
}

/*************************************************************************
* FUNCTION
*   DEINT_Get_IRQ_Code
*
* DESCRIPTION
*   This function returns IRQ code of input DEINT number.
*
* CALLS
*   None
*
* PARAMETERS
*   deint_no - DEINT number
*
* RETURNS
*   CINT code
*
* GLOBALS AFFECT
*
*************************************************************************/
kal_uint16 DEINT_Get_IRQ_Code(kal_uint32 deint_no)
{
    kal_uint32 cint;
    
    ASSERT(deint_no < EINT_TOTAL_CHANNEL);
    
    /* Find the corresponding CINT index (0, 1, 2, ...) of deint_no */
    cint = DEINT_2_CINT(deint_no);
    
    /* Return the IRQ code of this CINT */
    return (kal_uint16)CINT2IRQCode[cint];
}

#endif /* defined(__DEINT_DRIVER__) */
