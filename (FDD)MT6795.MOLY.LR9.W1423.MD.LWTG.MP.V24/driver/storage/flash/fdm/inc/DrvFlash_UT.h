/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *  DrvFlash_UT.C
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to configure NOR FDM unit test processure.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
Forbidden to use kal_internal_api.h and tst_ltlcom.h in modules other than KAL.

[Check-in branch]
MAUI
MSBB_II_DEV

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
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef DRVFLASH_UT_H
#define DRVFLASH_UT_H

//---------------------------------------------//
// Included Header Files                       //
//---------------------------------------------//

#if defined(__MTK_INTERNAL__)
#include "task_config.h"
#endif //__MTK_INTERNAL__

#include "kal_debug.h"

//---------------------------------------------//
// NOR FDM UT Test Item                        //
//---------------------------------------------//
typedef enum {
   NOR_FDM_UT_RW_STRESS = 0,
   NOR_FDM_UT_AUTO,
   NOR_FDM_UT_AUTO_16HR,
   NOR_FDM_UT_NORMAL_POWER_ON_OFF,
   NOR_FDM_UT_RANDOM_POWER_LOSS,
   NOR_FDM_UT_BUSY_POWER_LOSS,
   NOR_FDM_UT_CFI,
   NOR_FDM_UT_PROFILING,                
   NOR_FDM_UT_ATE,
   NOR_FDM_UT_BOOTROM,
   NOR_FDM_UT_OTP,
   NOR_FDM_UT_API,
   NOR_MTD_UT_MEMORY_SLT,
   NOR_MTD_UT_DEVICE_TEST
} NOR_FDM_UT_Code;

                                        
//----------------------------------------------//
// NOR FDM UT Test Variable Declaration         //
//----------------------------------------------//

extern kal_bool nor_fdm_dbg_enable; //declare in nor_test.c

//-------------------------------------------------------
// NOR Debug Trace Function/Macro
//-------------------------------------------------------

// NOR_TST_SYS_TRACE
// basic_log
// log_printf

extern void dbg_print(char *fmt,...);

// Define Catcher System Trace Macro for Internal Project
// Remove IDLER task trace due to kal_change_priority is deprecated. 
#if 0 //defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else // !__MTK_INTERNAL__
   #define NOR_TST_SYS_TRACE(str, ...)
#endif //__MTK_INTERNAL__


// Define UART Trace Macro
#if (defined(LOGGING) || ( defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) ))
   #define basic_log(str, ...) do{\
         kal_sprintf(dbg_text, str, ##__VA_ARGS__);\
         dbg_print(dbg_text);\
      }while(0)
#else
   #define basic_log(str, ...)
#endif // LOGGINE || (__NOR_FLASH_HARDWARE_TEST__ && __MAUI_BASIC__)

// Define UART Trace Macro in Basic Load
#if defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__)
   #define basic_printf  basic_log
   #define basic_print  dbg_print
#else
   #define basic_printf(str, ...)
   #define basic_print(str)
#endif // __NOR_FLASH_HARDWARE_TEST__ && __MAUI_BASIC__

// Define UART Trace Macro if LOGGING is defined
#if defined(LOGGING)
   #define log_printf  basic_log
#else //!LOGGING
   #define log_printf(str, ...)
#endif // LOGGING


#if defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__)
extern kal_uint32 (*LocateSector_ext)(NOR_FLASH_DRV_Data *, kal_uint32); //nor_test.c

typedef enum {
    BeforeErase=0,
    AfterErase=1,
    EraseSuspend=2,
    ProgramSuspend=3,
    BeforeProgram=4,
    AfterProgram=5
} Enum_disturb_stage;

extern kal_uint32 EraseDisturbCheck(NOR_FLASH_DRV_Data * D, kal_uint32 Block, kal_uint32 Range, kal_uint32 stage);

#endif //__NOR_FLASH_HARDWARE_TEST__  && __MAUI_BASIC__


//----------------------------------------------//
// MT6280 NOR FDM AUTO Test Macros         //
//----------------------------------------------//

//MT6280 has no RTC to do AUTO test count. Therefore, numeric counter is written to NV Register to record count.
#if defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__)

#if defined(__SERIAL_FLASH_EN__)

#if defined(MT6280)
#include "sfi_hw.h"
#define SF_COUNT_NVREG ((volatile kal_uint32*)(SFI_base + 0x0018))

#define SF_DAL_NVREG_COUNT_SET(a)   SFI_WriteReg32(SF_COUNT_NVREG, ((*SF_COUNT_NVREG) &0x0000FFFF |  ((a)<<16)))
#define SF_DAL_NVREG_COUNT_GET()   ( ((*SF_COUNT_NVREG) &(~0x0000FFFF))>>16 ) 

#define AutoTestCount 200
#endif

#else //defined(__SERIAL_FLASH_EN__)
#define SF_DAL_NVREG_COUNT_SET(...)
#define SF_DAL_NVREG_COUNT_GET()   0xFFFFFFFF
#define AutoTestCount              0xFFFFFFFF
#endif//defined(__SERIAL_FLASH_EN__)

#endif //__NOR_FLASH_HARDWARE_TEST__  && __MAUI_BASIC__


#endif   /* !DRVFLASH_UT_H */
