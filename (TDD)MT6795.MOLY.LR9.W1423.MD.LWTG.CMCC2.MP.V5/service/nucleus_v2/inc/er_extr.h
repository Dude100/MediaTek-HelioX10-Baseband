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
*       er_extr.h
*
*   COMPONENT
*
*       ER - Error Management
*
*   DESCRIPTION
*
*       This file contains function prototypes of all functions
*       accessible to other components.
*
*   DATA STRUCTURES
*
*       None
*
*   MACROS
*
*       NU_CHECK
*       NU_ASSERT
*
*   DEPENDENCIES
*
*       nucleus.h                           System definitions
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

/* Include system definitions */
#include    "nucleus.h"

/* Check to see if the file has been included already */
#ifndef     ER_EXTR
#define     ER_EXTR

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* System error handling function definition.  */
ESAL_VOID        ERC_System_Error(ESAL_INT error_code);

/* Ensure that NU_ASSERT and NU_CHECK are not currently defined */
#ifdef      NU_ASSERT
#undef      NU_ASSERT
#endif

#ifdef      NU_CHECK
#undef      NU_CHECK
#endif

#if         (NU_DEBUG_ENABLE == NU_TRUE)

/* External function declarations */
ESAL_VOID        ERC_Assert(ESAL_CHAR *test, ESAL_CHAR *name, ESAL_UNSIGNED line);

/* Define macro for ASSERT */
#define     NU_ASSERT(test)                                             \
                        if ( !(test) )                                  \
                        {                                               \
                            ERC_Assert( #test, __FILE__, __LINE__ );    \
                        }                                               \
                        ((ESAL_VOID) 0)

/* Define macro for ASSERT2 */
#define     NU_ASSERT2(test)                                            \
                        if ( !(test) )                                  \
                        {                                               \
                            ERC_Assert( #test, __FILE__, __LINE__ );    \
                        }                                               \
                        ((ESAL_VOID) 0)

#else

/* Define macros for ASSERT and ASSERT2 as NU_VOID */
#define     NU_ASSERT(test)                 ((ESAL_VOID) 0)
#define     NU_ASSERT2(test)                ((ESAL_VOID) 0)

#endif  /* NU_DEBUG_ENABLE == NU_TRUE */

#if         (NU_ERROR_CHECKING == NU_TRUE)

/* Define macro for NU_CHECK with error checking enabled */
#define     NU_CHECK(test, statement)                                   \
                        NU_ASSERT2( test );                             \
                        if ( !(test) )                                  \
                        {                                               \
                            statement;                                  \
                        }                                               \
                        ((ESAL_VOID) 0)

#else

/* Define macro for NU_CHECK with error checking disabled */
#define     NU_CHECK(test, statement)       NU_ASSERT2( test )

#endif  /* NU_ERROR_CHECKING == NU_TRUE */

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif  /* !ER_EXTR */
