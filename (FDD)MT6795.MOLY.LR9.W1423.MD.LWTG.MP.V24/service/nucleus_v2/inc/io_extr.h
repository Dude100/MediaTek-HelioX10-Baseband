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
*       io_extr.h
*
*   COMPONENT
*
*       IO - Input/Output Driver Management
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
*       io_defs.h                           I/O Driver Management consts
*       tc_defs.h                           Thread control constants
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

#include        "io_defs.h"        /* Include IO constants      */
#include        "tc_defs.h"        /* Thread control constants  */


/* Check to see if the file has been included already.  */

#ifndef IO_EXTR
#define IO_EXTR

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* Error checking functions.  */

NU_STATE          IOCE_Create_Driver(NU_DRIVER *driver, NU_CHAR *name,
                    NU_VOID (*driver_entry)(NU_DRIVER *, NU_DRIVER_REQUEST *));
NU_STATE          IOCE_Delete_Driver(NU_DRIVER *driver);
NU_STATE          IOCE_Request_Driver(NU_DRIVER *driver,
                                                NU_DRIVER_REQUEST *request);
NU_STATE          IOCE_Resume_Driver(NU_TASK *task);
NU_STATE          IOCE_Suspend_Driver(NU_VOID (*terminate_routine)(NU_VOID *),
                                      NU_VOID *information, NU_UNSIGNED timeout);


/* Core processing functions.  */

NU_STATE          IOC_Create_Driver(NU_DRIVER *driver, NU_CHAR *name,
                    NU_VOID (*driver_entry)(NU_DRIVER *, NU_DRIVER_REQUEST *));
NU_STATE          IOC_Delete_Driver(NU_DRIVER *driver);
NU_STATE          IOC_Request_Driver(NU_DRIVER *driver,
                                                NU_DRIVER_REQUEST *request);
NU_STATE          IOC_Resume_Driver(NU_TASK *task);
NU_STATE          IOC_Suspend_Driver(NU_VOID (*terminate_routine)(NU_VOID *),
                                        NU_VOID *information, NU_UNSIGNED timeout);


/* Information retrieval functions.  */

NU_UNSIGNED        IOF_Established_Drivers(NU_VOID);
NU_UNSIGNED        IOF_Driver_Pointers(NU_DRIVER **pointer_list,
                                                NU_UNSIGNED maximum_pointers);

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif
