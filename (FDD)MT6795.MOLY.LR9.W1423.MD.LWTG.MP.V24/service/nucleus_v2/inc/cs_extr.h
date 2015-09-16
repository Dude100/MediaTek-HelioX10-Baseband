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
*       cs_extr.h
*
*   COMPONENT
*
*       CS - Common Services
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
*   DEPENDENCIES
*
*       cs_defs.h                           Common service definitions
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

#include        "cs_defs.h"        /* Include CS definitions    */


/* Check to see if the file has been included already.  */

#ifndef CS_EXTR
#define CS_EXTR

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

#if (NU_PLUS_INLINING == NU_FALSE)

/* Use declared functions */
NU_VOID            CSC_Place_On_List(CS_NODE **head, CS_NODE *new_node);
NU_VOID            CSC_Priority_Place_On_List(CS_NODE **head, CS_NODE *new_node);
NU_VOID            CSC_Remove_From_List(CS_NODE **head, CS_NODE *node);

#else

/* Inlining enabled - use macros */
#define         CSC_Place_On_List(head, new_node);                           \
                if (*((CS_NODE **) (head)))                                  \
                {                                                            \
                    ((CS_NODE *) (new_node)) -> cs_previous=                 \
                            (*((CS_NODE **) (head))) -> cs_previous;         \
                    (((CS_NODE *) (new_node)) -> cs_previous) -> cs_next =   \
                            (CS_NODE *) (new_node);                          \
                    ((CS_NODE *) (new_node)) -> cs_next =                    \
                            (*((CS_NODE **) (head)));                        \
                    (((CS_NODE *) (new_node)) -> cs_next) -> cs_previous =   \
                            ((CS_NODE *) (new_node));                        \
                }                                                            \
                else                                                         \
                {                                                            \
                    (*((CS_NODE **) (head))) = ((CS_NODE *) (new_node));     \
                    ((CS_NODE *) (new_node)) -> cs_previous =                \
                            ((CS_NODE *) (new_node));                        \
                    ((CS_NODE *) (new_node)) -> cs_next =                    \
                            ((CS_NODE *) (new_node));                        \
                }

NU_VOID            CSC_Priority_Place_On_List(CS_NODE **head, CS_NODE *new_node);

#define         CSC_Remove_From_List(head, node);                            \
                if (((CS_NODE *) (node)) -> cs_previous ==                   \
                                            ((CS_NODE *) (node)))            \
                {                                                            \
                    (*((CS_NODE **) (head))) =  NU_NULL;                     \
                }                                                            \
                else                                                         \
                {                                                            \
                    (((CS_NODE *) (node)) -> cs_previous) -> cs_next =       \
                                         ((CS_NODE *) (node)) -> cs_next;    \
                    (((CS_NODE *) (node)) -> cs_next) -> cs_previous =       \
                                     ((CS_NODE *) (node)) -> cs_previous;    \
                    if (((CS_NODE *) (node)) == *((CS_NODE **) (head)))      \
                        *((CS_NODE **) (head)) =                             \
                            ((CS_NODE *) (node)) -> cs_next;                 \
                }

#endif  /* NU_PLUS_INLINING == NU_FALSE */

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif
