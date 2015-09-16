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
 *   intrCtrl.c
 *
 * Project:
 * --------
 *   Maui_Software
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
 * removed!
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

/*******************************************************************************
 * Option Check
 *******************************************************************************/
#if !defined(__CIRQ_MASK_REG_NR_1_NEW__) && !defined(__CIRQ_MASK_REG_NR_2_NEW__) && !defined(__CIRQ_MASK_REG_NR_3_NEW__) && !defined(__CIRQ_MASK_REG_NR_4_NEW__) && !defined(__CIRQ_MASK_REG_NR_5_NEW__)
  #error "Unsupported CIRQ register design"
#endif

/*******************************************************************************
 * Define global data
 *******************************************************************************/

/* install interrupt handler functions */

/* In normal load, irqLine should not be modified */
/* And it should be modifiable in SSDVT           */
#if defined(__SSDVT_TEST__) || defined(__IC_SLT__)
kal_uint8 irqLine[] = { IRQ_LINE_MAPPING_TABLE };
#else
const kal_uint8 irqLine[] = { IRQ_LINE_MAPPING_TABLE };
#endif

kal_uint8 IRQCode2Line[NUM_IRQ_SOURCES];

#if defined(__CEINT_IRQ_NEW__)
const kal_uint8 CEINT2CIRQCode[CEINT_NUMBER] = {CEINT_CODE_TABLE};
#endif /* defined(__CEINT_IRQ_NEW__) */

static IRQ_MASK_VALUE_T SleepModeMask;
static kal_uint8 SleepModeMaskCount=0;
static IRQ_MASK_VALUE_T CTIRQ1_2_MaskValue;

static kal_uint8 INTMaskCount[NUM_IRQ_SOURCES];

#if defined(__ENABLE_SW_TRIGGER_INTERRUPT__)
const kal_uint8 SW_Code_Handle2Code[SW_HANDLE_END-NUM_IRQ_SOURCES] = 
{
#define X_SW_HANDLE_CONST(a, b, c) c,
   #include "intrCtrl_SW_Handle.h"
#undef X_SW_HANDLE_CONST
};

kal_uint32 SW_INT_Counter[SW_HANDLE_END-NUM_IRQ_SOURCES];
#endif /* __ENABLE_SW_TRIGGER_INTERRUPT__ */

kal_uint32 IRQMaskStatus[5];

/* Monitor IRQ_WTIMER_CODE by default */
/* Plan to phase out by W12.32 */
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
void IRQDirectMaskAll(void)
{
   kal_uint32 savedmask;

   /* Lockout all interrupts */
   savedmask = LockIRQ();
// TODO: Fix LockIRQ usage on older chips only

#if defined(__CIRQ_MASK_REG_NR_1_NEW__)

   *IRQ_MASK_SET0 = 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)

   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)

   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_SET2 = 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)

   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_SET2 = 0xffffffff;
   *IRQ_MASK_SET3 = 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)

   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_SET2 = 0xffffffff;
   *IRQ_MASK_SET3 = 0xffffffff;
   *IRQ_MASK_SET4 = 0xffffffff;

#endif

   RestoreIRQ(savedmask);
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
    IRQMaskStatus[0] = *IRQ_MASK0;
#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
    IRQMaskStatus[0] = *IRQ_MASK0;
    IRQMaskStatus[1] = *IRQ_MASK1;
#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)
    IRQMaskStatus[0] = *IRQ_MASK0;
    IRQMaskStatus[1] = *IRQ_MASK1;
    IRQMaskStatus[2] = *IRQ_MASK2;
#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
    IRQMaskStatus[0] = *IRQ_MASK0;
    IRQMaskStatus[1] = *IRQ_MASK1;
    IRQMaskStatus[2] = *IRQ_MASK2;
    IRQMaskStatus[3] = *IRQ_MASK3;
#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
    IRQMaskStatus[0] = *IRQ_MASK0;
    IRQMaskStatus[1] = *IRQ_MASK1;
    IRQMaskStatus[2] = *IRQ_MASK2;
    IRQMaskStatus[3] = *IRQ_MASK3;
    IRQMaskStatus[4] = *IRQ_MASK4;
#else
#endif
    return;
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
#if defined(__CIRQ_MASK_REG_NR_1_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);

  *IRQ_EOIOH0= (1 << code);
      
#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);

   if (code < 32)
      *IRQ_EOIOH0= (1 << code);
   else
      *IRQ_EOIOH1 = (1 << (code - 32));
      
#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);

   if (code < 32)
      *IRQ_EOIOH0= (1 << code);
   else if (code < 64)
      *IRQ_EOIOH1 = (1 << (code - 32));
   else
      *IRQ_EOIOH2 = (1 << (code - 64));


#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);

   if (code < 32)
      *IRQ_EOIOH0= (1 << code);
   else if(code < 64)
      *IRQ_EOIOH1 = (1 << (code - 32));
   else if (code < 96)
      *IRQ_EOIOH2 = (1 << (code - 64));
   else
      *IRQ_EOIOH3 = (1 << (code - 96));
      
#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);

   if (code < 32)
      *IRQ_EOIOH0= (1 << code);
   else if (code < 64)
      *IRQ_EOIOH1 = (1 << (code - 32));
   else if (code < 96)
      *IRQ_EOIOH2 = (1 << (code - 64));
   else if (code < 128)
      *IRQ_EOIOH3 = (1 << (code - 96));
   else
      *IRQ_EOIOH4 = (1 << (code - 128));
      
#endif 
}

/*************************************************************************
* FUNCTION
*  SYS_ClearInt2
*
* DESCRIPTION
*  Reserved for system service only!
*  Clear IRQ with binary coded interrupt status
*  It is trapped while Interrupt is disabled!
*
* PARAMETERS
*  Binary coded interrupt status
*
* RETURNS
*
*************************************************************************/
void SYS_ClearInt2(kal_uint8 irq_idx)
{
   *IRQ_EOI2 = irq_idx;
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
#if defined(__CIRQ_MASK_REG_NR_1_NEW__)

   *IRQ_EOIOH0= 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)

   *IRQ_EOIOH0= 0xffffffff;
   *IRQ_EOIOH1= 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)

   *IRQ_EOIOH0= 0xffffffff;
   *IRQ_EOIOH1= 0xffffffff;
   *IRQ_EOIOH2= 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)

   *IRQ_EOIOH0= 0xffffffff;
   *IRQ_EOIOH1= 0xffffffff;
   *IRQ_EOIOH2= 0xffffffff;
   *IRQ_EOIOH3= 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)

   *IRQ_EOIOH0= 0xffffffff;
   *IRQ_EOIOH1= 0xffffffff;
   *IRQ_EOIOH2= 0xffffffff;
   *IRQ_EOIOH3= 0xffffffff;
   *IRQ_EOIOH4= 0xffffffff;

#endif
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
   kal_uint8 line;
   kal_uint32 savedmask;
   
   line = IRQCode2Line[code];

   /* Lockout all interrupts */
   savedmask = LockIRQ();   

#if defined(__CIRQ_MASK_REG_NR_1_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
  *IRQ_EOIOH0 = (1 << line);

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_EOIOH0 = (1 << line);
   else
      *IRQ_EOIOH1 = (1 << (line - 32));

#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_EOIOH0 = (1 << line);
   else if (line < 32)
      *IRQ_EOIOH1 = (1 << (line - 32));
   else 
      *IRQ_EOIOH2 = (1 << (line - 64));

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_EOIOH0 = (1 << line);
   else if(line < 64)
      *IRQ_EOIOH1 = (1 << (line - 32));
   else if (line < 96)
      *IRQ_EOIOH2 = (1 << (line - 64));
   else
      *IRQ_EOIOH3 = (1 << (line - 96));

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_EOIOH0 = (1 << line);
   else if (line < 64)
      *IRQ_EOIOH1 = (1 << (line - 32));
   else if (line < 96)
      *IRQ_EOIOH2 = (1 << (line - 64));
   else if (line < 128)
      *IRQ_EOIOH3 = (1 << (line - 96));
   else
      *IRQ_EOIOH4 = (1 << (line - 128));

#endif 

   RestoreIRQ(savedmask);
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
   kal_uint8 line;
   kal_uint32 savedMask;

   /* get the return address */
   if (code == irq_mask_monitor_idx)
   {
      GET_RETURN_ADDRESS(irq_mask_caller);
   }
   
   line = IRQCode2Line[code];

   /*
    * [Important]
    * IRQ mask will be valid around 2T ~ 3T after register is written. 
    * To ensure IRQ is turned off thoroughly, I bit must be disabled in 
    * advanced; otherwise, IRQ may be triggered unexpectedly.
    */
   savedMask = LockIRQ();
   
   ASSERT(INTMaskCount[line]==0 || INTMaskCount[line]==255);
   
   INTMaskCount[line] = 255;
    
#if defined(__CIRQ_MASK_REG_NR_1_NEW__)
    
   ASSERT(code<NUM_IRQ_SOURCES);
  *IRQ_MASK_SET0= (1 << line);

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
    
   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_SET0= (1 << line);
   else
      *IRQ_MASK_SET1 = (1 << (line - 32));


#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)
    
   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_SET0= (1 << line);
   else if (line < 64)
      *IRQ_MASK_SET1 = (1 << (line - 32));
   else
      *IRQ_MASK_SET2 = (1 << (line - 64));

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
    
   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_SET0= (1 << line);
   else if(line < 64)
      *IRQ_MASK_SET1 = (1 << (line - 32));
   else if(line < 96)
      *IRQ_MASK_SET2 = (1 << (line - 64));
   else
      *IRQ_MASK_SET3 = (1 << (line - 96));

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
    
   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_SET0= (1 << line);
   else if (line < 64)
      *IRQ_MASK_SET1 = (1 << (line - 32));
   else if (line < 96)
      *IRQ_MASK_SET2 = (1 << (line - 64));
   else if (line < 128)
      *IRQ_MASK_SET3 = (1 << (line - 96));
   else
      *IRQ_MASK_SET4 = (1 << (line - 128));

#endif

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
   kal_uint8 idx;

   for (idx=0;idx<NUM_IRQ_SOURCES;idx++) 
      IRQMask(idx);
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
   kal_uint8 line;
   line = IRQCode2Line[code];

#if defined(__CIRQ_MASK_REG_NR_1_NEW__)
   return (*IRQ_MASK0 & (1<<line));
#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
   if (line < 32)
      return (*IRQ_MASK0 & (1<<line));
   else
      return (*IRQ_MASK1 & (1<<(line - 32)));
#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)
   if (line < 32)
      return (*IRQ_MASK0 & (1<<line));
   else if (line < 64)
      return (*IRQ_MASK1 & (1<<(line - 32)));
   else
      return (*IRQ_MASK2 & (1<<(line - 64)));
#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
   if (line < 32)
      return (*IRQ_MASK0 & (1<<line));
   else if (line < 64)
      return (*IRQ_MASK1 & (1<<(line - 32)));
   else if (line < 96)
      return (*IRQ_MASK2 & (1<<(line - 64)));
   else
      return (*IRQ_MASK3 & (1<<(line - 96)));
#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
   if (line < 32)
      return (*IRQ_MASK0 & (1<<line));
   else if (line < 64)
      return (*IRQ_MASK1 & (1<<(line - 32)));
   else if (line < 96)
      return (*IRQ_MASK2 & (1<<(line - 64)));
   else if (line < 128)
      return (*IRQ_MASK3 & (1<<(line - 96)));
   else
      return (*IRQ_MASK4 & (1<<(line - 128)));
#else
    return 0;      
#endif
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
   kal_uint8 line;
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
   
   line = IRQCode2Line[code];
   
   savedMask = LockIRQ();
   
   ASSERT(INTMaskCount[line]==0 || INTMaskCount[line]==255);
   
   INTMaskCount[line]= 0;

#if defined(__CIRQ_MASK_REG_NR_1_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
  *IRQ_MASK_CLR0 = (1 << line);

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_CLR0 = (1 << line);
   else
      *IRQ_MASK_CLR1 = (1 << (line - 32));

#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_CLR0 = (1 << line);
   else if(line < 64)
      *IRQ_MASK_CLR1 = (1 << (line - 32));
   else      
      *IRQ_MASK_CLR2 = (1 << (line - 64));

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_CLR0 = (1 << line);
   else if(line < 64)
      *IRQ_MASK_CLR1 = (1 << (line - 32));
   else if (line < 96)
      *IRQ_MASK_CLR2 = (1 << (line - 64));
   else
	*IRQ_MASK_CLR3 = (1 << (line - 96));

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_CLR0 = (1 << line);
   else if (line < 64)
      *IRQ_MASK_CLR1 = (1 << (line - 32));
   else if (line < 96)
      *IRQ_MASK_CLR2 = (1 << (line - 64));
   else if (line < 128)
      *IRQ_MASK_CLR3 = (1 << (line - 96));
   else
      *IRQ_MASK_CLR4 = (1 << (line - 128));

#endif

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
*
*************************************************************************/
#if defined(__MTK_TARGET__)
__attribute__ ((section ("INTSRAM_ROCODE"))) kal_uint32 IRQ_Status(void)
#else
kal_uint32 IRQ_Status(void)
#endif
{
   kal_uint32 irqx;

   irqx = *IRQ_STA2;               
   
   if ( (irqx&0x100) == 0x100 )
      return -1;
   else 
      return (irqx&0xff);

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
   kal_uint32 fiqx;

#ifdef __CIRQ_DESIGN_NEW__      
   fiqx = *FIQ_STA2;

   if ( (fiqx&0x100) == 0x100 )
      return -1;
   else 
      return (fiqx&0xff);

#else
   fiqx = *FIQ_SEL;
   return (fiqx&0x3f);

#endif

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
     kal_uint32 savedMask;

   if (val == NULL)
      ASSERT(0);
      
   savedMask = LockIRQ();

#if defined(TK6280)
   val->irq_maskl = *IRQ_MASKL;
   val->irq_maskh = *IRQ_MASKH;
   *IRQ_MASKL = val->irq_maskl | CTIRQ1_2_MaskValue.irq_maskl;
   *IRQ_MASKH = val->irq_maskh | CTIRQ1_2_MaskValue.irq_maskh;

#elif defined(__CIRQ_MASK_REG_NR_1_NEW__)
   val->irq_mask0 = *IRQ_MASK0;
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0 | CTIRQ1_2_MaskValue.irq_mask0);

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
   val->irq_mask0 = *IRQ_MASK0;
   val->irq_mask1 = *IRQ_MASK1;
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0 | CTIRQ1_2_MaskValue.irq_mask0);
   *IRQ_MASK_CLR1 = ~(val->irq_mask1 | CTIRQ1_2_MaskValue.irq_mask1);

#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)

   val->irq_mask0 = *IRQ_MASK0;
   val->irq_mask1 = *IRQ_MASK1;
   val->irq_mask2 = *IRQ_MASK2;
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_SET2 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0 | CTIRQ1_2_MaskValue.irq_mask0);
   *IRQ_MASK_CLR1 = ~(val->irq_mask1 | CTIRQ1_2_MaskValue.irq_mask1);
   *IRQ_MASK_CLR2 = ~(val->irq_mask2 | CTIRQ1_2_MaskValue.irq_mask2);

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
   val->irq_mask0 = *IRQ_MASK0;
   val->irq_mask1 = *IRQ_MASK1;
   val->irq_mask2 = *IRQ_MASK2;
   val->irq_mask3 = *IRQ_MASK3;
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_SET2 = 0xffffffff;
   *IRQ_MASK_SET3 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0 | CTIRQ1_2_MaskValue.irq_mask0);
   *IRQ_MASK_CLR1 = ~(val->irq_mask1 | CTIRQ1_2_MaskValue.irq_mask1);
   *IRQ_MASK_CLR2 = ~(val->irq_mask2 | CTIRQ1_2_MaskValue.irq_mask2);
   *IRQ_MASK_CLR3 = ~(val->irq_mask3 | CTIRQ1_2_MaskValue.irq_mask3);

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
   val->irq_mask0 = *IRQ_MASK0;
   val->irq_mask1 = *IRQ_MASK1;
   val->irq_mask2 = *IRQ_MASK2;
   val->irq_mask3 = *IRQ_MASK3;
   val->irq_mask4 = *IRQ_MASK4;
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_SET2 = 0xffffffff;
   *IRQ_MASK_SET3 = 0xffffffff;
   *IRQ_MASK_SET4 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0 | CTIRQ1_2_MaskValue.irq_mask0);
   *IRQ_MASK_CLR1 = ~(val->irq_mask1 | CTIRQ1_2_MaskValue.irq_mask1);
   *IRQ_MASK_CLR2 = ~(val->irq_mask2 | CTIRQ1_2_MaskValue.irq_mask2);
   *IRQ_MASK_CLR3 = ~(val->irq_mask3 | CTIRQ1_2_MaskValue.irq_mask3);
   *IRQ_MASK_CLR4 = ~(val->irq_mask4 | CTIRQ1_2_MaskValue.irq_mask4);

#endif
      
   RestoreIRQ(savedMask);
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
   kal_uint32 savedMask;

   savedMask = LockIRQ();

#if defined(__CIRQ_MASK_REG_NR_1_NEW__)
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0);

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0);
   *IRQ_MASK_CLR1 = ~(val->irq_mask1);

#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_SET2 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0);
   *IRQ_MASK_CLR1 = ~(val->irq_mask1);
   *IRQ_MASK_CLR2 = ~(val->irq_mask2);

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_SET2 = 0xffffffff;
   *IRQ_MASK_SET3 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0);
   *IRQ_MASK_CLR1 = ~(val->irq_mask1);
   *IRQ_MASK_CLR2 = ~(val->irq_mask2);
   *IRQ_MASK_CLR3 = ~(val->irq_mask3);

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_SET2 = 0xffffffff;
   *IRQ_MASK_SET3 = 0xffffffff;
   *IRQ_MASK_SET4 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0);
   *IRQ_MASK_CLR1 = ~(val->irq_mask1);
   *IRQ_MASK_CLR2 = ~(val->irq_mask2);
   *IRQ_MASK_CLR3 = ~(val->irq_mask3);
   *IRQ_MASK_CLR4 = ~(val->irq_mask4);

#endif
      
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
   val->irq_mask0 = *IRQ_MASK0;
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0 | SleepModeMask.irq_mask0);

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
   val->irq_mask0 = *IRQ_MASK0;
   val->irq_mask1 = *IRQ_MASK1;
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0 | SleepModeMask.irq_mask0);
   *IRQ_MASK_CLR1 = ~(val->irq_mask1 | SleepModeMask.irq_mask1);

#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)
   val->irq_mask0 = *IRQ_MASK0;
   val->irq_mask1 = *IRQ_MASK1;
   val->irq_mask2 = *IRQ_MASK2;
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_SET2 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0 | SleepModeMask.irq_mask0);
   *IRQ_MASK_CLR1 = ~(val->irq_mask1 | SleepModeMask.irq_mask1);
   *IRQ_MASK_CLR2 = ~(val->irq_mask2 | SleepModeMask.irq_mask2);

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
   val->irq_mask0 = *IRQ_MASK0;
   val->irq_mask1 = *IRQ_MASK1;
   val->irq_mask2 = *IRQ_MASK2;
   val->irq_mask3 = *IRQ_MASK3;
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_SET2 = 0xffffffff;
   *IRQ_MASK_SET3 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0 | SleepModeMask.irq_mask0);
   *IRQ_MASK_CLR1 = ~(val->irq_mask1 | SleepModeMask.irq_mask1);
   *IRQ_MASK_CLR2 = ~(val->irq_mask2 | SleepModeMask.irq_mask2);
   *IRQ_MASK_CLR3 = ~(val->irq_mask3 | SleepModeMask.irq_mask3);

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
   val->irq_mask0 = *IRQ_MASK0;
   val->irq_mask1 = *IRQ_MASK1;
   val->irq_mask2 = *IRQ_MASK2;
   val->irq_mask3 = *IRQ_MASK3;
   val->irq_mask4 = *IRQ_MASK4;
   *IRQ_MASK_SET0 = 0xffffffff;
   *IRQ_MASK_SET1 = 0xffffffff;
   *IRQ_MASK_SET2 = 0xffffffff;
   *IRQ_MASK_SET3 = 0xffffffff;
   *IRQ_MASK_SET4 = 0xffffffff;
   *IRQ_MASK_CLR0 = ~(val->irq_mask0 | SleepModeMask.irq_mask0);
   *IRQ_MASK_CLR1 = ~(val->irq_mask1 | SleepModeMask.irq_mask1);
   *IRQ_MASK_CLR2 = ~(val->irq_mask2 | SleepModeMask.irq_mask2);
   *IRQ_MASK_CLR3 = ~(val->irq_mask3 | SleepModeMask.irq_mask3);
   *IRQ_MASK_CLR4 = ~(val->irq_mask4 | SleepModeMask.irq_mask4);

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
      *IRQ_MASK_SET0 = 0xffffffff;
      *IRQ_MASK_CLR0 = ~(val->irq_mask0);

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
      *IRQ_MASK_SET0 = 0xffffffff;
      *IRQ_MASK_SET1 = 0xffffffff;
      *IRQ_MASK_CLR0 = ~(val->irq_mask0);
      *IRQ_MASK_CLR1 = ~(val->irq_mask1);

#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)
      *IRQ_MASK_SET0 = 0xffffffff;
      *IRQ_MASK_SET1 = 0xffffffff;
      *IRQ_MASK_SET2 = 0xffffffff;
      *IRQ_MASK_CLR0 = ~(val->irq_mask0);
      *IRQ_MASK_CLR1 = ~(val->irq_mask1);
      *IRQ_MASK_CLR2 = ~(val->irq_mask2);

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
      *IRQ_MASK_SET0 = 0xffffffff;
      *IRQ_MASK_SET1 = 0xffffffff;
      *IRQ_MASK_SET2 = 0xffffffff;
      *IRQ_MASK_SET3 = 0xffffffff;
      *IRQ_MASK_CLR0 = ~(val->irq_mask0);
      *IRQ_MASK_CLR1 = ~(val->irq_mask1);
      *IRQ_MASK_CLR2 = ~(val->irq_mask2);
      *IRQ_MASK_CLR3 = ~(val->irq_mask3);

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
      *IRQ_MASK_SET0 = 0xffffffff;
      *IRQ_MASK_SET1 = 0xffffffff;
      *IRQ_MASK_SET2 = 0xffffffff;
      *IRQ_MASK_SET3 = 0xffffffff;
      *IRQ_MASK_SET4 = 0xffffffff;
      *IRQ_MASK_CLR0 = ~(val->irq_mask0);
      *IRQ_MASK_CLR1 = ~(val->irq_mask1);
      *IRQ_MASK_CLR2 = ~(val->irq_mask2);
      *IRQ_MASK_CLR3 = ~(val->irq_mask3);
      *IRQ_MASK_CLR4 = ~(val->irq_mask4);

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
   kal_uint8 line;

   line = IRQCode2Line[code];

#if defined(__CIRQ_MASK_REG_NR_1_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (edge != KAL_FALSE) 
   {
      /* it is an edge sensitive interrupt */
     *IRQ_SENS_CLR0 = (1 << line);
   } 
   else 
   {
      /* level sensitive interrupt */
     *IRQ_SENS_SET0 = (1 << line);
   }

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (edge != KAL_FALSE) 
   {
      /* it is an edge sensitive interrupt */
      if (line < 32)
         *IRQ_SENS_CLR0 = (1 << line);
      else
         *IRQ_SENS_CLR1 = (1 << (line - 32));
   } 
   else 
   {
      /* level sensitive interrupt */
      if (line < 32)
         *IRQ_SENS_SET0 = (1 << line);
      else
         *IRQ_SENS_SET1 = (1 << (line - 32));
   }

#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (edge != KAL_FALSE) 
   {
      /* it is an edge sensitive interrupt */
      if (line < 32)
         *IRQ_SENS_CLR0 = (1 << line);
      else if (line < 64)
         *IRQ_SENS_CLR1 = (1 << (line - 32));
      else
         *IRQ_SENS_CLR2 = (1 << (line - 64)); 
   } 
   else 
   {
      /* level sensitive interrupt */
      if (line < 32)
         *IRQ_SENS_SET0 = (1 << line);
      else if (line < 64)
         *IRQ_SENS_SET1 = (1 << (line - 32));
      else
         *IRQ_SENS_SET2 = (1 << (line - 64));
   }

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (edge != KAL_FALSE) 
   {
      /* it is an edge sensitive interrupt */
      if (line < 32)
         *IRQ_SENS_CLR0 = (1 << line);
      else if(line < 64)
         *IRQ_SENS_CLR1 = (1 << (line - 32));
      else if (line < 96)
         *IRQ_SENS_CLR2 = (1 << (line - 64));
      else
         *IRQ_SENS_CLR3 = (1 << (line - 96));
   } 
   else 
   {
      /* level sensitive interrupt */
      if (line < 32)
         *IRQ_SENS_SET0 = (1 << line);
      else if(line < 64)
         *IRQ_SENS_SET1 = (1 << (line - 32));
      else if (line < 96)
         *IRQ_SENS_SET2 = (1 << (line - 64));
      else
         *IRQ_SENS_SET3 = (1 << (line - 96));
   }

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (edge != KAL_FALSE) 
   {
      /* it is an edge sensitive interrupt */
      if (line < 32)
         *IRQ_SENS_CLR0 = (1 << line);
      else if (line < 64)
         *IRQ_SENS_CLR1 = (1 << (line - 32));
      else if (line < 96)
         *IRQ_SENS_CLR2 = (1 << (line - 64));
      else if (line < 128)
         *IRQ_SENS_CLR3 = (1 << (line - 96));
      else
         *IRQ_SENS_CLR4 = (1 << (line - 128));
   } 
   else 
   {
      /* level sensitive interrupt */
      if (line < 32)
         *IRQ_SENS_SET0 = (1 << line);
      else if(line < 64)
         *IRQ_SENS_SET1 = (1 << (line - 32));
      else if (line < 96)
         *IRQ_SENS_SET2 = (1 << (line - 64));
      else if (line < 128)
         *IRQ_SENS_SET3 = (1 << (line - 96));
      else
         *IRQ_SENS_SET4 = (1 << (line - 128));
   }

#endif 
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
   kal_uint8 line;

   line = IRQCode2Line[code];
   ASSERT(code<NUM_IRQ_SOURCES);

#if defined(__CIRQ_MASK_REG_NR_1_NEW__)
   val->irq_mask0 &= ~(1 << line);

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
   if (line < 32)
      val->irq_mask0 &= ~(1 << line);
   else
      val->irq_mask1 &= ~(1 << (line - 32));

#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)
   if (line < 32)
      val->irq_mask0 &= ~(1 << line);
   else if (line < 64)
      val->irq_mask1 &= ~(1 << (line - 32));
   else
      val->irq_mask2 &= ~(1 << (line - 64));

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
   if (line < 32)
      val->irq_mask0 &= ~(1 << line);
   else if (line < 64)
      val->irq_mask1 &= ~(1 << (line - 32));
   else if (line < 96)
      val->irq_mask2 &= ~(1 << (line - 64));
   else
      val->irq_mask3 &= ~(1 << (line - 96));

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
   if (line < 32)
      val->irq_mask0 &= ~(1 << line);
   else if (line < 64)
      val->irq_mask1 &= ~(1 << (line - 32));
   else if (line < 96)
      val->irq_mask2 &= ~(1 << (line - 64));
   else if (line < 128)
      val->irq_mask3 &= ~(1 << (line - 96));
   else
      val->irq_mask4 &= ~(1 << (line - 128));

#endif
   
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
#if defined(TK6280)
   SleepModeMask.irq_maskl = 0xffffffff;
   SleepModeMask.irq_maskh = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_maskl = 0xffffffff;
   CTIRQ1_2_MaskValue.irq_maskh = 0xffffffff;

#elif defined(__CIRQ_MASK_REG_NR_1_NEW__)
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

#ifdef IRQ_RTR_SLT_CODE
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

#ifdef IRQ_WTIMER_CODE
   SetMaskValue(&SleepModeMask,IRQ_WTIMER_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_WTIMER_CODE);
#endif

#ifdef IRQ_OSTIMER_ARM_CODE
   SetMaskValue(&SleepModeMask,IRQ_OSTIMER_ARM_CODE);
#endif

#ifdef IRQ_TDMA_CODE
   SetMaskValue(&SleepModeMask,IRQ_TDMA_CODE);
#endif

   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_CTIRQ1_CODE);
   SetMaskValue(&CTIRQ1_2_MaskValue,IRQ_CTIRQ2_CODE);
}

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

   /* determine the mapping between interrupt code and line */
   for (idx=0;idx<NUM_IRQ_SOURCES;idx++) 
      IRQCode2Line[irqLine[idx]] = idx;

   MaskValueInit();

   kal_mem_set(INTMaskCount, 0, sizeof(INTMaskCount));

   /* mask all interrupt events */
   IRQDirectMaskAll();

   /* assign IRQ Selection Registers */
   IRQSel();
   
   /* clear all pending interrupts */
   IRQClearAllInt();

#if defined(__ENABLE_SW_TRIGGER_INTERRUPT__)
   /* Initialize SW Interrupt Counter*/
   for(idx=0;idx<SW_HANDLE_END- NUM_IRQ_SOURCES;idx++)
   {
      SW_INT_Counter[idx]=0;
   }
#endif
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
   kal_uint8 line;
   kal_uint32 savedMask;

   line = IRQCode2Line[code];

   /*
    * [Important]
    * IRQ mask will be valid around 2T ~ 3T after register is written. 
    * To ensure IRQ is turned off thoroughly, I bit must be disabled in 
    * advanced; otherwise, IRQ may be triggered unexpectedly.
    */
   
   savedMask = LockIRQ();
   
   ASSERT(INTMaskCount[line]<254); 
    
   if(++INTMaskCount[line]==1)
   {
#if defined(__CIRQ_MASK_REG_NR_1_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   *IRQ_MASK_SET0 = (1 << line);
   
#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_SET0 = (1 << line);
   else
      *IRQ_MASK_SET1 = (1 << (line - 32));

#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_SET0 = (1 << line);
   else if (line < 64)
      *IRQ_MASK_SET1 = (1 << (line - 32));
   else
      *IRQ_MASK_SET2 = (1 << (line - 64));
   
#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_SET0 = (1 << line);
   else if(line < 64)
      *IRQ_MASK_SET1 = (1 << (line - 32));
   else if (line < 96)
      *IRQ_MASK_SET2 = (1 << (line - 64));
   else
      *IRQ_MASK_SET3 = (1 << (line - 96));
   
#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_SET0 = (1 << line);
   else if (line < 64)
      *IRQ_MASK_SET1 = (1 << (line - 32));
   else if (line < 96)
      *IRQ_MASK_SET2 = (1 << (line - 64));
   else if (line < 128)
      *IRQ_MASK_SET3 = (1 << (line - 96));
   else
      *IRQ_MASK_SET4 = (1 << (line - 128));
   
#endif
   }
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
   kal_uint8 line;
   kal_uint32 savedMask;

   line = IRQCode2Line[code];
   
   savedMask = LockIRQ();
   
   ASSERT(INTMaskCount[line]>0 && INTMaskCount[line]<255); 

   if(--INTMaskCount[line] == 0)
   {
#if defined(__CIRQ_MASK_REG_NR_1_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   *IRQ_MASK_CLR0 = (1 << line);
	
#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_CLR0 = (1 << line);
   else
      *IRQ_MASK_CLR1 = (1 << (line - 32));

#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_CLR0 = (1 << line);
   else if (line < 64)
      *IRQ_MASK_CLR1 = (1 << (line - 32));
   else
      *IRQ_MASK_CLR2 = (1 << (line - 64));
	
#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_CLR0 = (1 << line);
   else if (line < 64)
      *IRQ_MASK_CLR1 = (1 << (line - 32));
   else if (line < 96)
      *IRQ_MASK_CLR2 = (1 << (line - 64));
   else
      *IRQ_MASK_CLR3 = (1 << (line - 96));
	
#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)

   ASSERT(code<NUM_IRQ_SOURCES);
   if (line < 32)
      *IRQ_MASK_CLR0 = (1 << line);
   else if (line < 64)
      *IRQ_MASK_CLR1 = (1 << (line - 32));
   else if (line < 96)
      *IRQ_MASK_CLR2 = (1 << (line - 64));
   else if (line < 128)
      *IRQ_MASK_CLR3 = (1 << (line - 96));
   else
      *IRQ_MASK_CLR4 = (1 << (line - 128));
	
#endif
   }
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
   
   savedMask = LockIRQ();

   ASSERT(code<NUM_IRQ_SOURCES);
   
#if defined(__CIRQ_MASK_REG_NR_1_NEW__)
   *IRQ_SOFT_SET0 = (1 << code);

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
   if (code < 32)
      *IRQ_SOFT_SET0 = (1 << code);
   else if(code < 64)
      *IRQ_SOFT_SET1 = (1 << (code - 32));

#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)
   if (code < 32)
      *IRQ_SOFT_SET0 = (1 << code);
   else if(code < 64)
      *IRQ_SOFT_SET1 = (1 << (code - 32));
   else
      *IRQ_SOFT_SET2 = (1 << (code - 64));

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
   if (code < 32)
      *IRQ_SOFT_SET0 = (1 << code);
   else if(code < 64)
      *IRQ_SOFT_SET1 = (1 << (code - 32));
   else if (code < 96)
      *IRQ_SOFT_SET2 = (1 << (code - 64));
   else
     *IRQ_SOFT_SET3 = (1 << (code - 96));

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
   if (code < 32)
      *IRQ_SOFT_SET0 = (1 << code);
   else if(code < 64)
      *IRQ_SOFT_SET1 = (1 << (code - 32));
   else if (code < 96)
      *IRQ_SOFT_SET2 = (1 << (code - 64));
   else if (code < 128)
     *IRQ_SOFT_SET3 = (1 << (code - 96));
   else
     *IRQ_SOFT_SET4 = (1 << (code - 128));

#endif

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
   
   savedMask = LockIRQ();

   ASSERT(code<NUM_IRQ_SOURCES);

#if defined(__CIRQ_MASK_REG_NR_1_NEW__)
   *IRQ_SOFT_CLR0 = (1 << code);

#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
   if (code < 32)
      *IRQ_SOFT_CLR0 = (1 << code);
   else if(code < 64)
      *IRQ_SOFT_CLR1 = (1 << (code - 32));

#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)
   if (code < 32)
      *IRQ_SOFT_CLR0 = (1 << code);
   else if(code < 64)
      *IRQ_SOFT_CLR1 = (1 << (code - 32));
   else
      *IRQ_SOFT_CLR2 = (1 << (code - 64));

#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
   if (code < 32)
      *IRQ_SOFT_CLR0 = (1 << code);
   else if(code < 64)
      *IRQ_SOFT_CLR1 = (1 << (code - 32));
   else if (code < 96)
      *IRQ_SOFT_CLR2 = (1 << (code - 64));
   else
     *IRQ_SOFT_CLR3 = (1 << (code - 96));

#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
   if (code < 32)
      *IRQ_SOFT_CLR0 = (1 << code);
   else if(code < 64)
      *IRQ_SOFT_CLR1 = (1 << (code - 32));
   else if (code < 96)
      *IRQ_SOFT_CLR2 = (1 << (code - 64));
   else if (code < 128)
     *IRQ_SOFT_CLR3 = (1 << (code - 96));
   else
     *IRQ_SOFT_CLR4 = (1 << (code - 128));

#endif
      
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
   
   ASSERT(handle >= NUM_IRQ_SOURCES);
   handle = handle - NUM_IRQ_SOURCES;
   ASSERT(handle < (SW_HANDLE_END - NUM_IRQ_SOURCES));

   savedMask = LockIRQ();
   
   SW_INT_Counter[handle]++;
   if(SW_INT_Counter[handle]==1)
      IRQ_SetSWRegister(SW_Code_Handle2Code[handle]);
   
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

   ASSERT(handle >= NUM_IRQ_SOURCES);
   handle = handle - NUM_IRQ_SOURCES;
   ASSERT(handle < (SW_HANDLE_END - NUM_IRQ_SOURCES));

   savedMask = LockIRQ();

   SW_INT_Counter[handle]--;
   if(SW_INT_Counter[handle]==0)
      IRQ_ResetSWRegister(SW_Code_Handle2Code[handle]);
   
   RestoreIRQ(savedMask);

}

#endif /* __ENABLE_SW_TRIGGER_INTERRUPT__ */

