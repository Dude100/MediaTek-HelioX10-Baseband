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
*       plus_cfg.h
*
*   COMPONENT
*
*       Nucleus PLUS Configuration Settings
*
*   DESCRIPTION
*
*       This file contains Nucleus PLUS configuration settings,
*       compile-time options, etc
*
*   DATA STRUCTURES
*
*       None
*
*   DEPENDENCIES
*
*       None
*
**============================================================================
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

/* Check to see if this file has been included already.  */

#ifndef PLUS_CFG
#define PLUS_CFG

#ifdef          __cplusplus

/* C declarations in C++     */
extern          "C" {

#endif

/* DEFINE:      NU_ERROR_CHECKING
   DEFAULT:     NU_TRUE
   DESCRIPTION: Error checking code is included for all applicable Nucleus PLUS API calls
                when this define is set to NU_TRUE.  Setting this define to NU_FALSE will
                cause Nucleus PLUS API calls to skip / bypass error checking code.
   NOTE:        The Nucleus PLUS library and application must be rebuilt after changing
                this define.            */
#ifndef         NU_ERROR_CHECKING
#define         NU_ERROR_CHECKING                   NU_TRUE
#endif

/* DEFINE:      NU_PLUS_INLINING
   DEFAULT:     NU_FALSE
   DESCRIPTION: Frequently used Nucleus PLUS code is inlined (using macros) when this
                define is set to NU_TRUE.  Setting this define to NU_FALSE results in no
                inlining (using macros) - actual function declarations are called in
                this case.
   NOTE:        The Nucleus PLUS library, Nucleus Middleware Initialization library,
                and application must be rebuilt after changing
                this define.            */
#ifndef         NU_PLUS_INLINING
#define         NU_PLUS_INLINING                    NU_FALSE
#endif

/* DEFINE:      NU_STACK_CHECKING
   DEFAULT:     NU_FALSE
   DESCRIPTION: Stack checking code is included for all Nucleus PLUS API calls when this
                define is set to NU_TRUE.  Setting this define to NU_FALSE will turn-off
                stack checking code.
   NOTE:        If NU_STACK_FILL is enabled below (NU_TRUE), an additional check for
                stack overflow will occur in the scheduler using the stack fill pattern.
   NOTE:        The Nucleus PLUS library and application must be rebuilt after changing
                this define.            */
#ifndef         NU_STACK_CHECKING
#define         NU_STACK_CHECKING                   NU_FALSE
#endif

/* DEFINE:      NU_STACK_FILL
   DEFAULT:     NU_FALSE
   DESCRIPTION: Stack fill code is included for all Nucleus PLUS API calls when this
                define is set to NU_TRUE.  Setting this define to NU_FALSE will turn-off
                stack fill code.
   NOTE:        The fill pattern used is defined by NU_STACK_FILL_PATTERN found within
                this file
   NOTE:        The Nucleus PLUS library and application must be rebuilt after changing
                this define.            */
#ifndef         NU_STACK_FILL
#define         NU_STACK_FILL                       NU_FALSE
#endif

/* DEFINE:      NU_DEBUG_ENABLE
   DEFAULT:     NU_FALSE
   DESCRIPTION: Setting NU_DEBUG_ENABLE to NU_TRUE includes additional debugging services
                (NU_ASSERT / NU_CHECK).  With NU_DEBUG_ENABLE set to NU_FALSE, these services
                are not compiled as part of the Nucleus PLUS library.
   NOTE:        The Nucleus PLUS library and application must be rebuilt after changing
                this define.            */
#ifndef         NU_DEBUG_ENABLE
#define         NU_DEBUG_ENABLE                     NU_FALSE
#endif

/* DEFINE:      NU_HISTORY_LOGGING
   DEFAULT:     NU_FALSE
   DESCRIPTION: History logging code is included for all applicable Nucleus PLUS API calls
                when this define is set to NU_TRUE.  Setting this define to NU_FALSE will
                cause history logging to be disabled.
   NOTE:        The Nucleus PLUS library and application must be rebuilt after changing
                this define.            */
#ifndef         NU_HISTORY_LOGGING
#define         NU_HISTORY_LOGGING                  NU_FALSE
#endif

/* DEFINE:      NU_GLOBAL_INT_LOCKING
   DEFAULT:     NU_FALSE
   DESCRIPTION: Global interrupt locking is allowed (interrupt lock-out controlled at
                global level instead of thread / task level) when this define is set
                to NU_TRUE.  Interrupts are controlled at thread / task level if this
                define is set to NU_FALSE (interrupts not controlled at global level)
   NOTE:        Nucleus PLUS library and application must be rebuilt after changing
                this define.            */
#ifndef         NU_GLOBAL_INT_LOCKING
//#define         NU_GLOBAL_INT_LOCKING               NU_TRUE
#define         NU_GLOBAL_INT_LOCKING               NU_FALSE
#endif

/* DEFINE:      NU_MIN_RAM_ENABLED
   DEFAULT:     NU_FALSE
   DESCRIPTION: This define is used to minimize the use of RAM by Nucleus PLUS.  The
                trade-off for minimizing RAM usage is a decrease in speed / performance.
                Setting this define to NU_TRUE will reduce RAM usage.
   NOTE:        The Nucleus PLUS library and application must be rebuilt after changing
                this define.            */
#ifndef         NU_MIN_RAM_ENABLED
#define         NU_MIN_RAM_ENABLED                  NU_FALSE
#endif

/* DEFINE:      NU_NMI_SUPPORT_ENABLED
   DEFAULT:     NU_TRUE
   DESCRIPTION: This define is used to enable / disable the Nucleus Middleware
                Initialization support.  The default setting of NU_TRUE enables
                NMI support.  Setting this to NU_FALSE will disable this support.
   NOTE:        The Nucleus PLUS library and application must be rebuilt after changing
                this define.
   NOTE:        This setting can be changed to NU_FALSE if not using Nucleus Middleware
                or an application does not want to utilize the automatic initialization
                for the Nucleus Middleware.  The result will be a smaller footprint
                for Nucleus PLUS. */
#ifndef         NU_NMI_SUPPORT_ENABLED
#define         NU_NMI_SUPPORT_ENABLED              NU_FALSE
#endif

/* DEFINE:      NU_ZC_INITIALIZATION
   DEFAULT:     NU_FALSE
   DESCRIPTION: This define is used to determine if the Zero Copy component is to be
                initialized when Nucleus PLUS starts up or not.  When this define is
                set to NU_TRUE the Zero Copy component is initialized.  When this
                define is set to NU_FALSE the Zero Copy component is not automatically
                initialized at startup.
   NOTE:        The Nucleus PLUS library and application must be rebuilt after
                changing this define.            */
#ifndef         NU_ZC_INITIALIZATION
#define         NU_ZC_INITIALIZATION                NU_FALSE
#endif

/* DEFINE:      NU_ZC_NUM_OBJECTS
   DEFAULT:     200
   DESCRIPTION: This define is used by Nucleus PLUS to initialize the Zero Copy
                component when NU_ZC_INITIALIZATION is set to NU_TRUE (above).
   NOTE:        The number of Zero Copy objects necessary for an application is totally
                dependent on the application's use of the Zero Copy software.
   NOTE:        The Nucleus PLUS library and application must be rebuilt after
                changing this define.            */
#ifndef         NU_ZC_NUM_OBJECTS
#define         NU_ZC_NUM_OBJECTS                   200
#endif

/* DEFINE:      NU_ZC_<SERVICE>_INCLUDED
   DEFAULT:     NU_TRUE
   DESCRIPTION: These defines are used to configure which zero copy services are
                available to applications.  The default settings (NU_TRUE) will include
                all zero copy services within the Nucleus PLUS library.  Changing any
                setting to NU_FALSE will cause this zero copy service to be excluded
                from the library.
   NOTE:        Certain zero copy services cannot be disabled.  These include:
                initialization, creating a buffer, deleting a buffer, inserting data in
                a buffer, and getting the optimal segment / offset address.
   NOTE:        The benefit of setting unused services to be excluded will be a savings
                in code space in the final application's executable image.
   NOTE:        The Nucleus PLUS library and application must be rebuilt after
                changing this define.            */
#ifndef         NU_ZC_BUF_INSERT_INCLUDED
#define         NU_ZC_BUF_INSERT_INCLUDED           NU_TRUE
#endif
#ifndef         NU_ZC_BUF_SPLIT_INCLUDED
#define         NU_ZC_BUF_SPLIT_INCLUDED            NU_TRUE
#endif
#ifndef         NU_ZC_BUF_DUPLICATE_INCLUDED
#define         NU_ZC_BUF_DUPLICATE_INCLUDED        NU_TRUE
#endif
#ifndef         NU_ZC_DATA_COPY_INSERT_INCLUDED
#define         NU_ZC_DATA_COPY_INSERT_INCLUDED     NU_TRUE
#endif
#ifndef         NU_ZC_DATA_REMOVE_INCLUDED
#define         NU_ZC_DATA_REMOVE_INCLUDED          NU_TRUE
#endif
#ifndef         NU_ZC_BUF_LEN_GET_INCLUDED
#define         NU_ZC_BUF_LEN_GET_INCLUDED          NU_TRUE
#endif
#ifndef         NU_ZC_DATA_COPY_GET_INCLUDED
#define         NU_ZC_DATA_COPY_GET_INCLUDED        NU_TRUE
#endif
#ifndef         NU_ZC_SEG_NEXT_GET_INCLUDED
#define         NU_ZC_SEG_NEXT_GET_INCLUDED         NU_TRUE
#endif
#ifndef         NU_ZC_SEG_PREV_GET_INCLUDED
#define         NU_ZC_SEG_PREV_GET_INCLUDED         NU_TRUE
#endif
#ifndef         NU_ZC_SEG_DATA_GET_INCLUDED
#define         NU_ZC_SEG_DATA_GET_INCLUDED         NU_TRUE
#endif
#ifndef         NU_ZC_SEG_LEN_GET_INCLUDED
#define         NU_ZC_SEG_LEN_GET_INCLUDED          NU_TRUE
#endif

/* DEFINE:      NU_POSIX_INCLUDED
   DEFAULT:     NU_FALSE
   DESCRIPTION: POSIX specific code changes are compiled into Nucleus PLUS when this
                define is set to NU_TRUE.  These POSIX related items will not be included
                when set to NU_FALSE.
   NOTE:        The Nucleus Posix software is required to utilize this option.
                The Nucleus PLUS library and application must be rebuilt after changing
                this define.            */
#ifndef         NU_POSIX_INCLUDED
#define         NU_POSIX_INCLUDED                   NU_FALSE
#endif

/* DEFINE:      NU_UIPLUS_INCLUDED
   DEFAULT:     NU_FALSE
   DESCRIPTION: Nucleus uiPLUS specific code changes are compiled into Nucleus PLUS when this
                define is set to NU_TRUE.  These uiPLUS related items will not be included
                when set to NU_FALSE.
   NOTE:        The Nucleus uiPLUS software is required to utilize this option.
                The Nucleus PLUS library and application must be rebuilt after changing
                this define.            */
#ifndef         NU_UIPLUS_INCLUDED
#define         NU_UIPLUS_INCLUDED                  NU_FALSE
#endif

/* DEFINE:      NU_SUPERV_USER_MODE
   DEFAULT:     NU_FALSE
   DESCRIPTION: This define is used to enable Nucleus PLUS to execute with
                supervisor / user mode switching while using Module Support for
                Nucleus PLUS.  Setting this define to NU_TRUE includes code to perform
                this function.
   NOTE:        Module Support for Nucleus PLUS software is required to utilize
                this option.
                The Nucleus PLUS library and application must be rebuilt after changing
                this define.            */
#ifndef         NU_SUPERV_USER_MODE
#define         NU_SUPERV_USER_MODE                 NU_FALSE
#endif

/* DEFINE:      NU_MODULE_SUPPORT
   DEFAULT:     NU_FALSE
   DESCRIPTION: This define is used to enable the Module Support for Nucleus PLUS API
                to work.  Setting this define to NU_TRUE includes code to perform
                this function.
   NOTE:        Module Support for Nucleus PLUS software is required to utilize
                this option.
                The Nucleus PLUS library and application must be rebuilt after changing
                this define.            */
#ifndef         NU_MODULE_SUPPORT
#define         NU_MODULE_SUPPORT                   NU_FALSE
#endif

/* DEFINE:      NU_MMU_MODE
   DEFAULT:     NU_FALSE
   DESCRIPTION: This define is used to specify that the MMU on the target will be used
                Setting this define to NU_TRUE includes code to perform this function.
   NOTE:        Module Support for Nucleus PLUS software is required to utilize
                this option. NU_MMU_MODE and NU_MPU_MODE are mutually exclusive.
                The Nucleus PLUS library and application must be rebuilt after changing
                this define.            */
#ifndef         NU_MMU_MODE
#define         NU_MMU_MODE                         NU_FALSE
#endif

/* DEFINE:      NU_MPU_MODE
   DEFAULT:     NU_FALSE
   DESCRIPTION: This define is used to specify that the MPU on the target will be used
                Setting this define to NU_TRUE includes code to perform this function.
   NOTE:        Module Support for Nucleus PLUS software is required to utilize
                this option. NU_MMU_MODE and NU_MPU_MODE are mutually exclusive.
                The Nucleus PLUS library and application must be rebuilt after changing
                this define.            */
#ifndef         NU_MPU_MODE
#define         NU_MPU_MODE                         NU_FALSE
#endif

/* DEFINE:      NU_PLUS_OBJECT_LISTS_INCLUDE
   DEFAULT:     NU_FALSE
   DESCRIPTION: This define is used to include ALL of the Nucleus PLUS created object lists
                within the executable image of Nucleus PLUS.  Setting this define to NU_TRUE
                will explicitly include each of the object list pointers during
                initialization.  Setting this define to NU_FALSE will only include the
                object lists required for the given application.
   NOTE:        This define may need to be set to NU_TRUE to allow kernel awareness to
                correctly function on certain third party debuggers.. Some kernel aware
                debuggers are not able to display any list of OS objects unless all lists are
                in the image.
   NOTE:        The Nucleus PLUS library and application must be rebuilt after changing
                this define.            */
#ifndef         NU_PLUS_OBJECT_LISTS_INCLUDE
#define         NU_PLUS_OBJECT_LISTS_INCLUDE        NU_FALSE
#endif

/* Define the number of Nucleus PLUS ticks that will occur every second.
   By default, the PLUS timer generates an interrupt every 10ms causing the
   PLUS System Clock to tick 100 times in one second */
#ifndef         NU_PLUS_TICKS_PER_SEC
#define         NU_PLUS_TICKS_PER_SEC               100
#endif

/* Define the minimum stack size accepted when creating a task or HISR */
#ifndef         NU_MIN_STACK_SIZE
#define         NU_MIN_STACK_SIZE                   (ESAL_GE_STK_MAX_FRAME_SIZE * 2)
#endif

/* Define size of Nucleus Timer HISR stack and priority of Nucleus Timer HISR (0-2) */
#ifndef         NU_TIMER_HISR_STACK_SIZE
#define         NU_TIMER_HISR_STACK_SIZE            (NU_MIN_STACK_SIZE * 2)
#endif
#ifndef         NU_TIMER_HISR_PRIORITY
#define         NU_TIMER_HISR_PRIORITY              2
#endif

/* Define the stack fill pattern used when NU_STACK_FILL (defined above) is set to NU_TRUE */
#ifndef         NU_STACK_FILL_PATTERN
#define         NU_STACK_FILL_PATTERN               0xA5
#endif

/* DEFINE:      NU_AGENT_ENABLE
   DEFAULT:     NU_FALSE
   DESCRIPTION: This define is used to specify that the Nucleus Agent will be used.
                Setting this define to NU_TRUE will include code to support operation
                of the Nucleus Agent. */
#ifndef         NU_AGENT_ENABLE
#define         NU_AGENT_ENABLE                     NU_FALSE
#endif


/**********************************/
/* TEST CONFIGURATION SETTINGS    */
/**********************************/

/* DEFINE:      NU_TIME_TEST1MIN_ENABLE
   DEFAULT:     NU_FALSE
   DESCRIPTION: This define is used to perform the minimum code / data size tests that are
                part of the Nucleus PLUS timing test.  Setting this define to NU_TRUE will
                allow the minimal sized PLUS code and data to be built.
   NOTE:        The Nucleus PLUS library and timing test must be rebuilt after changing
                this define.            */
#ifndef         NU_TIME_TEST1MIN_ENABLE
#define         NU_TIME_TEST1MIN_ENABLE             NU_FALSE
#endif

/* DEFINE:      NU_TIME_TEST1MAX_ENABLE
   DEFAULT:     NU_FALSE
   DESCRIPTION: This define is used to perform the maximum code / data size tests that are
                part of the Nucleus PLUS timing test.  Setting this define to NU_TRUE will
                allow the maximum sized PLUS code and data to be built.
   NOTE:        The Nucleus PLUS library and timing test must be rebuilt after changing
                this define.            */
#ifndef         NU_TIME_TEST1MAX_ENABLE
#define         NU_TIME_TEST1MAX_ENABLE             NU_FALSE
#endif

/* DEFINE:      NU_TIME_TEST2_ENABLE
   DEFAULT:     NU_FALSE
   DESCRIPTION: This define is used to include code used for the Nucleus PLUS timing
                test #2.  Setting this define to NU_TRUE will include the necessary
                timing related code.
   NOTE:        The Nucleus PLUS library and timing test must be rebuilt after changing
                this define.            */
#ifndef         NU_TIME_TEST2_ENABLE
#define         NU_TIME_TEST2_ENABLE                NU_FALSE
#endif

/* DEFINE:      NU_TIME_TEST3_ENABLE
   DEFAULT:     NU_FALSE
   DESCRIPTION: This define is used to include code used for the Nucleus PLUS timing
                test #3.  Setting this define to NU_TRUE will include the necessary
                timing related code.
   NOTE:        The Nucleus PLUS library and timing test must be rebuilt after changing
                this define.            */
#ifndef         NU_TIME_TEST3_ENABLE
#define         NU_TIME_TEST3_ENABLE                NU_FALSE
#endif

/* DEFINE:      NU_LV_ENABLE
   DEFAULT:     NU_FALSE
   DESCRIPTION: Setting NU_LV_ENABLE to NU_TRUE builds Nucleus PLUS as a limited version.
   NOTE:        The Nucleus PLUS library and application must be rebuilt after
                changing this define.            */
#ifndef         NU_LV_ENABLE
#define         NU_LV_ENABLE                        NU_FALSE
#endif

#ifdef          __cplusplus

/* End of C declarations */
}

#endif  /* __cplusplus */

#endif  /* !PLUS_CFG */
