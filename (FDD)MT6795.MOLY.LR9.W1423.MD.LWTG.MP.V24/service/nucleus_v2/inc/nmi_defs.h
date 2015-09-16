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
*       nmi_defs.h
*
*   COMPONENT
*
*       Nucleus Middleware Initialization
*
*   DESCRIPTION
*
*       This file contains definitions used by Nucleus middleware
*       initialization functions
*
*   DATA STRUCTURES
*
*       NMI_MW_PRODUCT_DATA                 Middleware product data
*
*   DEPENDENCIES
*
*       None
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

#ifndef NMI_DEFS_H
#define NMI_DEFS_H

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Define an end-of-array marker for the Product Registry array */
#define     NMI_PRODUCT_REGISTRY_ARRAY_END  {NU_NULL, NU_NULL}

/* Define structure used to hold all the middleware initialization data */
typedef struct
{
    CS_NODE             mw_list_node;       /* Node for linked list */
    NMI_INIT_STATUS     mw_status;          /* Initialization status */
    NMI_MW_REG_DATA     *mw_reg_data_ptr;   /* Registration data filled in by MW */

} NMI_PRODUCT_DATA;

/* Define a product registry entry

   NOTE: The mw_id_ptr is used to ensure at compile time that the MW has
   actually provided the user with the <PRODUCT>_NMI_Id as required for
   MW to support NMI.  It has no other use within the NMI code */
typedef struct
{
    const NU_CHAR          **mw_id_ptr;        /* Pointer to NMI ID string */
    NMI_REG_FUNC_PTR    mw_reg_func_ptr;    /* Pointer to registration function  */
} NMI_PRODUCT_REGISTRY_ENTRY;

/* Defines for history logging */
typedef enum
{
    NMI_HISTORY_REGISTER_FAIL = -1,
    NMI_HISTORY_CALL_REGISTER = 0,
    NMI_HISTORY_REGISTER_OK,
    NMI_HISTORY_CALL_INIT,
    NMI_HISTORY_WAIT_FOR_INIT,
    NMI_HISTORY_WAIT_FOR_INIT_DONE,
    NMI_HISTORY_CALL_CLEANUP

} NMI_HISTORY;

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif  /* NMI_DEFS_H */
