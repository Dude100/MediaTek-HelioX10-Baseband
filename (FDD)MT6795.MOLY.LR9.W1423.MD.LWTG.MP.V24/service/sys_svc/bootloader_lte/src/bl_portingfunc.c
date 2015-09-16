/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   BL_portingfuncs.c
 *
 * Project:
 * --------
 *   BootLoader
 *
 * Description:
 * ------------
 *   This Module defines misc common functions that referenced by
 *   shared (usually customization) source file between MAUI and BootLoader
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "init.h"
#include "emi_hw.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "bl_sectiondef.h"
#include "bl_common.h"

#if defined(__MINI_BOOTLOADER__)
#include "cache_sw_int.h"
#endif /* __MINI_BOOTLOADER__ */

/*************************************************************************
* FUNCTION
*  INT_DisableCacheOnEMI
*
* DESCRIPTION
*  This is specific function for flash driver only.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
__interncode__ void INT_DisableCacheOnEMI(void)
{
   /* DO-NOTHING (legacy function) */

}

__interncode__ kal_uint32 SaveAndSetIRQMask(void)
{
   /* DO-NOTHING at boot loader stage */
   return 0x0;
}

__interncode__ void RestoreIRQMask(kal_uint32 x)
{
   /* DO-NOTHING at boot loader stage */
   return;
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
__interncode__ void IRQUnmask(kal_uint8 code)
{
   /* do nothing */
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
__interncode__ void IRQMask(kal_uint8 code)
{
   /* do nothing */
}

kal_uint32 CheckIRQLock(void)
{
   return 0;
}

#ifdef __TST_MODULE__
void kal_prompt_trace(module_type mod_id, const char *fmt,...)
{
}
#endif /* __TST_MODULE__ */

kal_bool kal_query_systemInit(void)
{
   return KAL_TRUE;
}

kal_uint32 kal_get_current_task_priority(void)
{
   return 0;
}

module_type stack_int_get_active_module_id( void )
{
   return (module_type)0;
}

kal_uint32 INT_GetSysStaByCmd(INIT_SYSCMD_CODE cmd_val, void *data_p)
{
   return 0;
}

kal_bool INT_QueryExceptionStatus(void)
{
   return KAL_FALSE;
}

#if defined(__KAL_ASSERT_LEVEL4__)
void INT_ExceptionSaveCpuReg(void) {}
#endif /* __KAL_ASSERT_LEVEL4__ */

#if defined(DEBUG_KAL)
void kal_assert_fail(char* expr, char* file, kal_uint32 line,
                     kal_bool isext, kal_uint32 ex1, kal_uint32 ex2, kal_uint32 ex3,
                     ASSERT_DUMP_PARAM_T *dump_param)
{
   kal_uint32 i;
   do {
      BL_PRINT( LOG_CRIT, "assert fail (%s) at %s line %d with ext( %x , %x , %x )\n\r", expr, file, line, ex1, ex2, ex3);
      for(i = 0xFFFFF; i > 0; i--) ;
   }while(1);
}

void kal_assert_fail_line(
#if !defined(__KAL_ASSERT_SHRINKING__)
    char* expr, char* file, 
#endif /* __KAL_ASSERT_SHRINKING__ */
    kal_uint32 line)
{
#if defined(__KAL_ASSERT_SHRINKING__)
   char *expr=NULL, *file=NULL; 
#endif /* __KAL_ASSERT_SHRINKING__ */
   kal_uint32 link_register;
   kal_uint32 i;
   /* 
    * NoteXXX: retrieve link register before any function call
    *
    */

#if defined(__ARMCC_VERSION)
#if defined(__RVCT__)
   link_register = __return_address();
#else
   __asm {
      mov link_register, lr;
   }
#endif /*__RVCT__*/
#elif defined(__GNUC__)
   link_register = (kal_uint32)__builtin_return_address(0);
#endif

   do {
      if(file)
          BL_PRINT( LOG_CRIT, "assert fail (%s) at %s line %d\n\r", expr, file, line);
      else
          BL_PRINT( LOG_CRIT, "assert fail at %x line %d\n\r", link_register, line);

      for(i = 0xFFFFF; i > 0; i--) ;
   }while(1);
}

void kal_assert_fail_ext(
#if !defined(__KAL_ASSERT_SHRINKING__)
    char* expr, char* file, 
#endif /* __KAL_ASSERT_SHRINKING__ */
    kal_uint32 line, kal_uint32 ex1, kal_uint32 ex2, kal_uint32 ex3)
{
#if defined(__KAL_ASSERT_SHRINKING__)
   char *expr=NULL, *file=NULL; 
#endif /* __KAL_ASSERT_SHRINKING__ */
   kal_uint32 link_register;
   kal_uint32 i;
   /* 
    * NoteXXX: retrieve link register before any function call
    *
    */
    
#if defined(__ARMCC_VERSION)    
#if defined(__RVCT__)
   link_register = __return_address();
#else
   __asm {
      mov link_register, lr;
   }
#endif /*__RVCT__*/
#elif defined(__GNUC__)
   link_register = (kal_uint32)__builtin_return_address(0);
#endif

   do {
      if(file)
          BL_PRINT( LOG_CRIT, "assert fail (%s) at %s line %d with ext( %x, %x, %x )\n\r", expr, file, line, ex1, ex2, ex3);
      else
          BL_PRINT( LOG_CRIT, "assert fail at %x line %d with ext( %x, %x, %x )\n\r", link_register, line, ex1, ex2, ex3);
          
      for(i = 0xFFFFF; i > 0; i--) ;
   }while(1);
}

void kal_assert_fail_dump(
#if !defined(__KAL_ASSERT_SHRINKING__)
    char* expr, char* file, 
#endif /* __KAL_ASSERT_SHRINKING__ */
    kal_uint32 line, kal_uint32 ex1, kal_uint32 ex2, kal_uint32 ex3, ASSERT_DUMP_PARAM_T *dump_param)
{
#if defined(__KAL_ASSERT_SHRINKING__)
   char *expr=NULL, *file=NULL; 
#endif /* __KAL_ASSERT_SHRINKING__ */
   kal_uint32 link_register;
   kal_uint32 i;
   /* 
    * NoteXXX: retrieve link register before any function call
    *
    */

#if defined(__ARMCC_VERSION)    
#if defined(__RVCT__)
   link_register = __return_address();
#else
   __asm {
      mov link_register, lr;
   }
#endif /*__RVCT__*/
#elif defined(__GNUC__)
   link_register = (kal_uint32)__builtin_return_address(0);
#endif

   do {
      if(file)
          BL_PRINT( LOG_CRIT, "assert fail (%s) at %s line %d with ext( %x, %x, %x )\n\r", expr, file, line, ex1, ex2, ex3);
      else
          BL_PRINT( LOG_CRIT, "assert fail at %x line %d with ext( %x, %x, %x )\n\r", link_register, line, ex1, ex2, ex3);
          
      for(i = 0xFFFFF; i > 0; i--) ;
   }while(1);
}

#else /* DEBUG_KAL */
void kal_assert_fail(void)
{
   kal_uint32 link_register;
   kal_uint32 i;
   /* 
    * NoteXXX: retrieve link register before any function call
    *
    */
    
#if defined(__ARMCC_VERSION)
#if defined(__RVCT__)
   link_register = __return_address();
#else
   __asm {
      mov link_register, lr;
   }
#endif /*__RVCT__*/
#elif defined(__GNUC__)
   link_register = __builtin_return_address(0);
#endif

   do {
      BL_PRINT( LOG_CRIT, "assert fail at %x\n\r", link_register);
      for(i = 0xFFFFF; i > 0; i--) ;
   }while(1);
}
#endif /* DEBUG_KAL */

void kal_assert_fail_native(char* expr, char* file, kal_uint32 line)
{
   kal_uint32 i;

   do {
      BL_PRINT( LOG_CRIT, "assert fail (%s) at %s line %d\n\r", expr, file, line);
      for(i = 0xFFFFF; i > 0; i--) ;
   }while(1);
}

