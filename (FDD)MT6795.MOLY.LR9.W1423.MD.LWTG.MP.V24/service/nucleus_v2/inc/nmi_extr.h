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
*       nmi_extr.h
*
*   COMPONENT
*
*       Nucleus Middleware Initialization
*
*   DESCRIPTION
*
*       This file contains externally accessible components of the
*       Nucleus Middleware Initialization component
*
*   DATA STRUCTURES
*
*       NMI_MW_REG_DATA                     Middleware
*                                           registration data
*
*   DEPENDENCIES
*
*       nucleus.h                           System header file
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

#ifndef     NMI_EXTR_H
#define     NMI_EXTR_H

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Include required header files */
#include    "nucleus.h"

/* Define compile time symbol indicating NMI support is linked into image.
   This is always set to NU_TRUE. NMI_SUPPORT is not defined prior to PLUS 2.0 */
#define NMI_SUPPORT             NU_TRUE

/* Define Middleware initialization status in increasing ‘completeness?
   These are documented in "Middleware Initialization for Nucleus PLUS" */
typedef enum
{
        NMI_INVALID_OPERATION = -1,
        NMI_INIT_FAILED,
        NMI_INIT_NOT_IN_REGISTRY,
        NMI_INIT_REGISTERED,
        NMI_INIT_IN_PROGRESS,
        NMI_INIT_COMPLETE,
        NMI_INIT_CLEANUP_COMPLETE

} NMI_INIT_STATUS;

/* Define signature of MW initialization callback
   Arguments:   NU_MEMORY_POOL*     memory pool
                NU_MEMORY_POOL*     uncached memory pool
                NU_VOID*               middleware callback parameter
                NU_VOID*               unused */
typedef NU_VOID            (*NMI_INIT_CB_PTR)      (NU_MEMORY_POOL*, NU_MEMORY_POOL*, NU_VOID**, NU_VOID*);

/* Define signature of MW cleanup callback
   Arguments:   NU_VOID*               middleware callback parameter
                NU_VOID*               unused */
typedef NU_VOID            (*NMI_CLEANUP_CB_PTR)   (NU_VOID**, NU_VOID*);

/* Define MW registration data structure filled in by MW registration function */
typedef struct
{
    /* Middleware fills in this data */
    const NU_CHAR*         mw_id_ptr;              /* MW ID (static product-specific string) */
    const NU_CHAR*         mw_ver_ptr;             /* MW version (static product-specific string) */
    NU_VOID*               mw_cb_param;            /* (optional) MW callback parameter passed to callbacks */
    NMI_INIT_CB_PTR     mw_init_cb_ptr;         /* MW initialization callback */
    NMI_CLEANUP_CB_PTR  mw_cleanup_cb_ptr;      /* (optional) MW cleanup callback */
} NMI_MW_REG_DATA;

/* Define signature of MW registration function
   Arguments:   NMI_MW_REG_DATA*    registration data */
typedef NMI_INIT_STATUS (*NMI_REG_FUNC_PTR)     (NMI_MW_REG_DATA*);

/* Error checking functions.  */

extern  NMI_INIT_STATUS NMIE_Init_Status_Get    (const NU_CHAR* mw_id_ptr);
extern  NMI_INIT_STATUS NMIE_Init_Status_Set    (const NU_CHAR* mw_id_ptr, NMI_INIT_STATUS mw_status);
extern  NMI_INIT_STATUS NMIE_Wait_For_Init      (const NU_CHAR* mw_id_ptr, NU_UNSIGNED timeout_ticks);
extern  NMI_INIT_STATUS NMIE_Cleanup_Invoke     (const NU_CHAR* mw_id_ptr);

/* Define externally available functions */

extern  NU_VOID            NMI_Initialize          (NU_MEMORY_POOL *mem_pool, NU_MEMORY_POOL *uncached_mem_pool);
extern  NMI_INIT_STATUS NMI_Init_Status_Get     (const NU_CHAR* mw_id_ptr);
extern  NMI_INIT_STATUS NMI_Init_Status_Set     (const NU_CHAR* mw_id_ptr, NMI_INIT_STATUS mw_status);
extern  NMI_INIT_STATUS NMI_Wait_For_Init       (const NU_CHAR* mw_id_ptr, NU_UNSIGNED timeout_ticks);
extern  NMI_INIT_STATUS NMI_Cleanup_Invoke      (const NU_CHAR* mw_id_ptr);

/* Include MW initialization definitions and MW NMI IDs
   o MW init definitions can be used to determine if MW init will be attempted
   o MW IDs are used as arguments to the NMI API */
//#include    "nmi_cfg.h"

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif  /* NMI_EXTR_H */
