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
 *   intrCtrl.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Common type and structure definition for MediaTek GSM/GPRS software
 *
 * Author:
 * -------
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
 * removed!
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

#ifndef _INTRCTRL_H
#define _INTRCTRL_H

/*******************************************************************************
 * Include header files
 *******************************************************************************/
#include "kal_general_types.h"

/*******************************************************************************
 * Single Core Platforms
 *******************************************************************************/
#if defined(MT6575)
   #include "intrCtrl_MT6575.h"
#endif

#if defined(TK6280)
   #include "intrCtrl_TK6280.h" 
#endif

#if defined(MT6280)
   #include "intrCtrl_MT6280.h" 
#endif

#if defined(MT6290)
#if defined(__CR4__)
   #include "intrCtrl_MT6290.h"
#elif defined(__ARM7EJ_S__)
   #include "intrCtrl_MT6290_ARM7.h"
#else
   #error "No CPU version select. Need to specify CPU version in project 6290 MDSYS."
#endif
#endif

#if defined(MT6595)
#if defined(__CR4__)
   #include "intrCtrl_MT6595.h"
#elif defined(__ARM7EJ_S__)
   #include "intrCtrl_MT6595_ARM7.h"
#else
   #error "No CPU version select. Need to specify CPU version in project 6595 MDSYS."
#endif
#endif /*MT6595*/

#if defined(MT6577)
   #include "intrCtrl_MT6577.h"
#endif

#if defined(MT6752)
   #if defined(__MD1__)
      #if defined(__CR4__)
      #include "intrCtrl_MT6752.h"      
      #elif defined(__ARM7EJ_S__)
      #include "intrCtrl_MT6752_ARM7.h"
      #endif //CR4
   #elif defined(__MD2__)
   #include "intrCtrl_MT6752_MD2.h"
   extern kal_uint8 IRQCode2Line[NUM_IRQ_SOURCES];
   #else
   #error "No CPU version select."
   #endif//MD1
#endif //MT6752
/*******************************************************************************
 * Declarations and Definitions
 *******************************************************************************/
 
#define EDGE_SENSITIVE           KAL_TRUE
#define LEVEL_SENSITIVE          KAL_FALSE

#define IRQ_NOT_LISR_CONTEXT     (0xFFFF)

#if defined(__CIRQ_MASK_REG_NR_1_NEW__) || defined(__CIRQ_MASK_REG_NR_2_NEW__) || defined(__CIRQ_MASK_REG_NR_3_NEW__) || defined(__CIRQ_MASK_REG_NR_4_NEW__) || defined(__CIRQ_MASK_REG_NR_5_NEW__)
#define __CIRQ_DESIGN_NEW__
#endif

typedef struct IRQ_MASK_VALUE_STRUCT
{
#if defined(__CIRQ_MASK_REG_NR_1_NEW__)
   kal_uint32 irq_mask0;
#elif defined(__CIRQ_MASK_REG_NR_2_NEW__)
   kal_uint32 irq_mask0;
   kal_uint32 irq_mask1;
#elif defined(__CIRQ_MASK_REG_NR_3_NEW__)
   kal_uint32 irq_mask0;
   kal_uint32 irq_mask1;
   kal_uint32 irq_mask2;
#elif defined(__CIRQ_MASK_REG_NR_4_NEW__)
   kal_uint32 irq_mask0;
   kal_uint32 irq_mask1;
   kal_uint32 irq_mask2;
   kal_uint32 irq_mask3;
#elif defined(__CIRQ_MASK_REG_NR_5_NEW__)
   kal_uint32 irq_mask0;
   kal_uint32 irq_mask1;
   kal_uint32 irq_mask2;
   kal_uint32 irq_mask3;
   kal_uint32 irq_mask4;
#elif defined(__CIRQ_MASK_REG_NR_2__)
   kal_uint32 irq_maskl;
   kal_uint32 irq_maskh;
#elif defined(__CIRQ_MASK_REG_NR_3__)
   kal_uint32 irq_maskl;
   kal_uint32 irq_maskm;
   kal_uint32 irq_maskh;
#else
   kal_uint32 irq_maskl;
   kal_uint32 irq_maskh;
#endif
} IRQ_MASK_VALUE_T;

#if defined(__UNIFIED_ISR_LEVEL__)
typedef kal_uint32 IRQ_MASK_VALUE_T2[(NUM_IRQ_SOURCES+31)/32] ;
#endif /* __UNIFIED_ISR_LEVEL__ */

/* To enable SW Trigger Interrupt for new BB chips
   Need to modify 3 files
   1. add a file intrCtrl_MTxxxx_SW_Handler.h
   2. add an entry on intrCtrl_SW_Handler.h 
   3. modify IRQ_SetSWRegister & IRQ_ResetSWRegister to support BB Chips on intrCtrl.c  */
#if defined(__ENABLE_SW_TRIGGER_INTERRUPT__)
typedef enum 
{
#define X_SW_HANDLE_CONST(a, b, c) a=(b),
   #include "intrCtrl_SW_Handle.h"
#undef X_SW_HANDLE_CONST
   SW_HANDLE_END
}SW_CODE_HANDLE;

extern void Activate_LISR(SW_CODE_HANDLE code);
extern void Deactivate_LISR(SW_CODE_HANDLE code);

#if defined (MT6752) && defined (__MD2__)
extern const kal_uint8 SW_Code_Handle2Code[SW_HANDLE_END-NUM_IRQ_SOURCES];
extern kal_uint32 SW_INT_Counter[SW_HANDLE_END-NUM_IRQ_SOURCES];
#else
extern const kal_uint8 SW_Code_Handle2Code[NUM_IRQ_SOURCES];
extern kal_uint32 SW_INT_Counter[NUM_IRQ_SOURCES];
#endif

/* Use to translate the mapping between software handler to hardware interrupt code */
#define SW_code_handle2code(a)  (a)


#endif /* __ENABLE_SW_TRIGGER_INTERRUPT__ */


extern kal_uint32 SaveAndSetIRQMask(void);
extern void RestoreIRQMask(kal_uint32);

extern void IRQClearInt(kal_uint8);
extern void IRQMask(kal_uint8);
extern void IRQMaskAll(void);
extern void IRQUnmask(kal_uint8);
extern void CTIRQ1_2_MaskAll(IRQ_MASK_VALUE_T *val);
extern void CTIRQ1_2_Restore(IRQ_MASK_VALUE_T *val);
extern void IRQSensitivity(kal_uint8, kal_bool);
extern void FIQSensitivity(kal_bool);
extern void initINTR(void);
extern kal_uint16 INT_BootMode(void);
extern kal_uint32 IRQMask_Status(kal_uint8 code);
extern kal_uint32 IRQ_Status(void);
extern kal_uint32 FIQ_isValid(void);

#if defined(__UNIFIED_ISR_LEVEL__)
/*#define IRQ_Register_LISR(code, lisr, description) \
do{                                                \
	if(code){;}                                    \
	if(NULL==lisr){;}                              \
	if(description){;}                             \
}while(0)*/
#include "syscomp_config.h"
extern const hisr_intid_map hisr_intid_g[];
extern const kal_uint32 total_hisr_intid_g;
extern const kal_uint8 kalid2intrID[KAL_INTID_MAX+1];
extern kal_hisrid intrID2hisrID[];
#define IRQ_Register_LISR(code, lisr, description)                        \
do{                                                                       \
	kal_uint32 i, _kal_intid;                                             \
	for(i = 1; i < total_hisr_intid_g; i++)                               \
	{                                                                     \
		_kal_intid = hisr_intid_g[i].int_id;                              \
		if((_kal_intid<KAL_INTID_MAX) && (kalid2intrID[_kal_intid] == code))  \
		{                                                                 \
			intrID2hisrID[code] = kal_init_hisr(hisr_intid_g[i].hisr_id); \
			break;                                                        \
		}                                                                 \
	}                                                                     \
	ASSERT(i < total_hisr_intid_g);                                       \
}while(0)
#else
#define IRQ_Register_LISR(code, lisr, description) \
    IRQ_Register_LISR_2(code, (void*)lisr, description)
extern void IRQ_Register_LISR_2(kal_uint32 code, void (*reg_lisr)(kal_uint32 vector), char* description);
//extern void IRQ_Register_LISR(kal_uint32 code, void (*reg_lisr)(kal_uint32 vector), char* description);
#endif


extern kal_uint32 CheckIRQLock(void);
extern kal_uint16 IRQ_Current_LISR(void);

extern void SetINTMask(kal_uint8 code);
extern void RestoreINTMask(kal_uint8 code);

/* Hardware register write during interrupts disabled */
#define REG_WRITE(reg_addr, value)  { \
   kal_uint32 _savedMask; \
   _savedMask = SaveAndSetIRQMask(); \
   *(volatile kal_uint16*)(reg_addr) = (kal_uint16)(value); \
   RestoreIRQMask(_savedMask); \
}

/* Hardware register read during interrupts disabled */
#define REG_READ(reg_addr, value) { \
   kal_uint32 _savedMask; \
   _savedMask = SaveAndSetIRQMask(); \
   (kal_uint16)(value) = *(volatile kal_uint16*)(reg_addr); \
   RestoreIRQMask(_savedMask); \
}


/***********************************
NOTE: 
1. below API is only for L2 logging, please not use
2. if you want to use, please confirm with CIRQ owner first
***********************************/
#define __IRQ_LOCK_WITHOUT_CHECK__

#if defined(__L2_LOGGING_IRQ_LOC__)
#if defined(__IRQ_LOCK_WITHOUT_CHECK__) && defined(__MD1__)
#define LOCK_CPU_INTERRUPT(oldmask, newmask)                                   \
do{                                                                            \
    __asm__ __volatile__                                                       \
    (                                                                          \
       "MRS      %0,CPSR\r\n"                                                  \
       "ORR      %1,%0,0xC0\r\n"                                               \
       "MSR      CPSR_c, %1\r\n"                                               \
       :"=r"(oldmask), "=r"(newmask)                                           \
       :"1"(newmask)                                                           \
       :"memory"                                                               \
    );                                                                         \
}while(0)

#define UNLOCK_CPU_INTERRUPT(oldmask)                                          \
do{                                                                            \
    __asm__ __volatile__                                                       \
    (                                                                          \
       "MSR      CPSR_c, %0\r\n"                                               \
       :                                                                       \
       :"r"(oldmask)                                                           \
       :"memory"                                                               \
    );                                                                         \
}while(0)

#else

#define LOCK_CPU_INTERRUPT(oldmask, newmask) \
do{ \
	oldmask = SaveAndSetIRQMask(); \
}while(0);

#define UNLOCK_CPU_INTERRUPT(oldmask) \
do{ \
	RestoreIRQMask(oldmask); \
}while(0);

#endif
#endif


#endif /* _INTRCTRL_H */

