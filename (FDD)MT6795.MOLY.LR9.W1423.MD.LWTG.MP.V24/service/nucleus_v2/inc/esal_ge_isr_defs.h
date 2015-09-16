/***********************************************************************
*
*            Copyright 1993 Mentor Graphics Corporation
*                         All Rights Reserved.
*
* THIS WORK CONTAINS TRADE SECRET AND PROPRIETARY INFORMATION WHICH IS
* THE PROPERTY OF MENTOR GRAPHICS CORPORATION OR ITS LICENSORS AND IS
* SUBJECT TO LICENSE TERMS.
*
************************************************************************

************************************************************************
*
*   FILE NAME
*
*       esal_ge_isr_defs.h
*
*   COMPONENT
*
*       ESAL - Embedded Software Abstraction Layer
*
*   DESCRIPTION
*
*       This file contains generic defines, structures, data types, etc
*       related to interrupt servicing
*
*   DATA STRUCTURES
*
*       None
*
*   DEPENDENCIES
*
*       esal_ar_isr_defs.h                  Embedded Software
*                                           Abstraction Layer architecture
*                                           interrupt servicing defines
*       esal_dp_isr_defs.h                  Embedded Software
*                                           Abstraction Layer development
*                                           platform interrupt servicing
*                                           defines
*       esal_pr_isr_defs.h                  Embedded Software
*                                           Abstraction Layer processor
*                                           interrupt servicing defines
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
***********************************************************************/

#ifndef         ESAL_GE_ISR_DEFS_H
#define         ESAL_GE_ISR_DEFS_H

/* Include all required header files */
#include        "esal_ar_isr_defs.h"
//#include        "esal_pr_isr_defs.h"
//#include        "esal_dp_isr_defs.h"

/* Define all externally accessible, interrupt related function prototypes */
ESAL_VOID            ESAL_GE_ISR_Initialize(ESAL_VOID (*default_isr)(ESAL_INT),
                                       ESAL_VOID (*default_except)(ESAL_INT, ESAL_VOID *),
                                       ESAL_VOID **(*os_isr_entry)(ESAL_INT, ESAL_VOID *),
                                       ESAL_VOID (*os_nested_isr_entry)(ESAL_INT));
ESAL_VOID            ESAL_AR_ISR_Initialize(ESAL_VOID);
ESAL_VOID            ESAL_AR_ISR_Vector_Table_Install(ESAL_VOID);
ESAL_VOID            ESAL_DP_ISR_Initialize(ESAL_VOID);
ESAL_VOID            ESAL_PR_ISR_Initialize(ESAL_VOID);

/* Externally referenced global data */
extern ESAL_VOID     **(*ESAL_GE_ISR_OS_Entry)(ESAL_INT vector, ESAL_VOID *stack_ptr);
extern ESAL_VOID     (*ESAL_GE_ISR_OS_Nested_Entry)(ESAL_INT vector);
extern ESAL_UINT      ESAL_GE_ISR_Executing;
extern ESAL_VOID isrC_Main(ESAL_UINT);

/* Define macro used to return back to the OS after interrupt handling.  If the OS
   must be returned to instead of returning to the point of interrupt, this macro
   will perform this operation based on the architectural requirements.
   NOTE:  Some architectures require a "return from interrupt" to be execute in
          order for the execution state to be restored when returning to the
          OS.  This is configured in esal_ar_cfg.h */
#if (ESAL_AR_ISR_RTI_MANDATORY == ESAL_FALSE)

/* No special requirements for this architecture - simply expand this macro into
   a function call */
#define         ESAL_GE_ISR_OS_RETURN(os_return_func_ptr)                                   \
                        os_return_func_ptr()

#else

/* Define function prototype for architecture specific return from ISR function */
ESAL_VOID            ESAL_AR_ISR_Return(ESAL_VOID (*)(ESAL_VOID));

/* This architecture must return to the OS using "return from interrupt" or equivalent
   method - expand this macro to call ESAL service to perform this function */
#define         ESAL_GE_ISR_OS_RETURN(os_return_func_ptr)                                   \
                        ESAL_AR_ISR_Return(os_return_func_ptr)

#endif  /* ESAL_AR_ISR_RTI_MANDATORY == ESAL_FALSE */

/* Define macro used to determine if within interrupt service routine */
#ifndef         ESAL_GE_ISR_EXECUTING
#define         ESAL_GE_ISR_EXECUTING()                     ESAL_GE_ISR_Executing
#endif          /* !ESAL_GE_ISR_EXECUTING */

/* Define macros used to identify start / end of interrupt service routine */
#ifndef         ESAL_GE_ISR_START
//#define         ESAL_GE_ISR_START()                         ESAL_GE_ISR_Executing = ESAL_TRUE
#define         ESAL_GE_ISR_START()                         ESAL_GE_ISR_Executing++
#endif          /* !ESAL_GE_ISR_START */
#ifndef         ESAL_GE_ISR_END
#if 0
/* under construction !*/
/* under construction !*/
#endif
#define         ESAL_GE_ISR_END()                           ESAL_GE_ISR_Executing--
#endif          /* !ESAL_GE_ISR_END */

#define         ESAL_GE_ISR_NESTED_START()                         ESAL_GE_ISR_Executing++
#define         ESAL_GE_ISR_NESTED_END()                           ESAL_GE_ISR_Executing--

/* Define macros to get / set / execute interrupt service routine for ESAL interrupt vectors */
//#define         ESAL_GE_ISR_HANDLER_GET(num)                (ESAL_GE_ISR_Interrupt_Handler[(num)])
//#define         ESAL_GE_ISR_HANDLER_SET(num,ptr)            ESAL_GE_ISR_Interrupt_Handler[(num)]=(ptr)
#define         ESAL_GE_ISR_HANDLER_EXECUTE(num)            isrC_Main(num)

/* Define macros for get / set exception handlers for ESAL exception vectors */
//#define         ESAL_GE_EXCEPT_HANDLER_SET(num,ptr)         ESAL_GE_ISR_Exception_Handler[(num)]=(ptr)
//#define         ESAL_GE_EXCEPT_HANDLER_GET(num)             (ESAL_GE_ISR_Exception_Handler[(num)])

/* Define macros to get / set data associated with each interrupt service routine vector */
//#define         ESAL_GE_ISR_VECTOR_DATA_GET(vector)         ESAL_GE_ISR_Interrupt_Vector_Data[(vector)]
//#define         ESAL_GE_ISR_VECTOR_DATA_SET(vector,data)    ESAL_GE_ISR_Interrupt_Vector_Data[(vector)]=(data)

/* Define macros for get / set data associated with each exception vector */
//#define         ESAL_GE_EXCEPT_VECTOR_DATA_GET(vector)      ESAL_GE_ISR_Exception_Vector_Data[(vector)]
//#define         ESAL_GE_EXCEPT_VECTOR_DATA_SET(vector,data) ESAL_GE_ISR_Exception_Vector_Data[(vector)]=(data)

#endif  /* ESAL_GE_ISR_DEFS_H */
