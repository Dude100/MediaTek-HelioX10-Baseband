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
#if defined(MT6223) || defined(MT6223P) || defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)

   *PREFETCH_CON = 0;

#endif

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

__interncode__ void WDT_Restart2(void)
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

/* Porting function for LCD drivers */
#if defined(__LCD_DRIVER_IN_BL__)

#include "Drv_comm.h"
#include "drv_hisr.h"


/*************************************************************************
* FUNCTION
*  kal_activate_hisr
*
* DESCRIPTION
*   This routine activate a hisr.
*
* PARAMETERS
*  ext_hisr_id    -  kal_hisrid (Id of the created hisr)
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void kal_activate_hisr(kal_hisrid ext_hisr_id)
{
   /* do nothing */
}

/*************************************************************************
* FUNCTION
*  IRQClearInt
*
* DESCRIPTION
*  Clear IRQ with plain format interrupt status
*
* PARAMETERS
*  Plain format interrupt status
*
* RETURNS
*
*************************************************************************/
void IRQClearInt(kal_uint8 code)
{
   /* do nothing */
}

/*************************************************************************
* FUNCTION
*  IRQSensitivity
*
* DESCRIPTION
*  Setting sensitivity of IRQ
*
* PARAMETERS
*  code: IRQ number to be set
*  edge: either edge active low or level active low
*
* RETURNS
*
*************************************************************************/
void IRQSensitivity(kal_uint8 code, kal_bool edge)
{
   /* do nothing */
}

/* APIs IsrEntry.c */
/*************************************************************************
* FUNCTION
*  IRQ_Register_LISR
*
* DESCRIPTION
*   This function implement method to register IRQ's LISR.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  irqvector   -  vector number to register
*  reg_lisr    -  register LISR's handler
*  description -  LISR's description pointer to be saved.
*     Remember, the routine won't duplicate the description,
*     therefore, caller shouldn't free the description.
*
* RETURNS
*
*************************************************************************/
void IRQ_Register_LISR(kal_uint32 code, void (*reg_lisr)(void), char* description)
{
   /* do nothing */
}

/* APIs in drv_hisr.c */
/*************************************************************************
* FUNCTION
*  DRV_Register_HISR
*
* DESCRIPTION
*  register a call back function for DRV HISR
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void DRV_Register_HISR(DRV_HISR_ID hisr_id, VOID_FUNCTION hisr_func)
{
   /* do nothing */
}




#endif /* __LCD_DRIVER_IN_BL__ */

kal_uint32 CheckIRQLock(void)
{
   return 0;
}

#ifdef __TST_MODULE__
void kal_prompt_trace(module_type mod_id, const char *fmt,...)
{
}
#endif /* __TST_MODULE__ */

#if defined(__MINI_BOOTLOADER__)
/*************************************************************************
* FUNCTION
*  query_is_noncached_ram
*
* DESCRIPTION
*  This function used to query if the memory is non-cacheable.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*  len - the length of the memory.
*
* RETURNS
*
*************************************************************************/
kal_int32 query_is_noncached_ram(kal_uint32 addr, kal_uint32 len)
{
#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__MTK_MMU__))
    return ((((kal_uint32)(addr) & CREG_OFFSET) ^ CREG_OFFSET) != 0);   
#else
    return 1;
#endif
}    

/*************************************************************************
* FUNCTION
*  query_is_cached_ram
*
* DESCRIPTION
*  This function used to query if the memory is cacheable.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr - the address to be queried
*  len - the length of the memory.
*
* RETURNS
*
*************************************************************************/
kal_int32 query_is_cached_ram(kal_uint32 addr, kal_uint32 len)
{
#if defined(__MTK_TARGET__) && (defined(__ARM9_MMU__) || defined(__ARM11_MMU__) || defined(__MTK_MMU__))
   return ((((kal_uint32)(addr) & CREG_OFFSET) ^ CREG_OFFSET) == 0);
#else
    return 0;
#endif
}

#endif /* __MINI_BOOTLOADER__ */

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

/* make lpwr.c happy */
void L1SM_UnIRQSleepEnable( kal_uint8 handle ) { }
void L1SM_SleepEnable( kal_uint8 handle ) { }
void L1SM_UnIRQSleepDisable( kal_uint8 handle ) { }
kal_uint8 L1SM_GetHandle( void )
{
   return 0;
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

void kal_assert_fail(
#if !defined(__KAL_ASSERT_LEVEL0__)
		char* expr, char* file, kal_uint32 line, kal_bool isext, kal_uint32 ex1, kal_uint32 ex2, kal_uint32 ex3, ASSERT_DUMP_PARAM_T *dump_param
#endif /* !__KAL_ASSERT_LEVEL0__ */
)
#if !defined(__KAL_ASSERT_LEVEL0__)
{
   kal_uint32 i;
   do {
      dbg_print("assert fail (%s) at %s line %d with ext( %x , %x , %x )\n\r", expr, file, line, ex1, ex2, ex3);
      for(i = 0xFFFFF; i > 0; i--) ;
   }while(1);
}
#else /* !__KAL_ASSERT_LEVEL0__ */
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
   link_register = (kal_uint32)__builtin_return_address(0);
#endif

   do {
      dbg_print("assert fail at %x\n\r", link_register);
      for(i = 0xFFFFF; i > 0; i--) ;
   }while(1);
}

#endif /* !__KAL_ASSERT_LEVEL0__ */

#if !defined(__KAL_ASSERT_LEVEL0__)

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
          dbg_print("assert fail (%s) at %s line %d\n\r", expr, file, line);
      else
          dbg_print("assert fail at %x line %d\n\r", link_register, line);

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
          dbg_print("assert fail (%s) at %s line %d with ext( %x, %x, %x )\n\r", expr, file, line, ex1, ex2, ex3);
      else
          dbg_print("assert fail at %x line %d with ext( %x, %x, %x )\n\r", link_register, line, ex1, ex2, ex3);
          
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
          dbg_print("assert fail (%s) at %s line %d with ext( %x, %x, %x )\n\r", expr, file, line, ex1, ex2, ex3);
      else
          dbg_print("assert fail at %x line %d with ext( %x, %x, %x )\n\r", link_register, line, ex1, ex2, ex3);
          
      for(i = 0xFFFFF; i > 0; i--) ;
   }while(1);
}

void kal_assert_fail_specific(
#if !defined(__KAL_ASSERT_SHRINKING__)
    char* expr, char* file, 
#endif /* __KAL_ASSERT_SHRINKING__ */
    kal_uint32 line, assert_specific_key key, ...)
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
   link_register = __builtin_return_address(0);
#endif

   do {
      if(file)
          dbg_print("assert fail (%s) at %s line %d\n\r", expr, file, line);
      else
          dbg_print("assert fail at %x line %d\n\r", link_register, line);
          
      for(i = 0xFFFFF; i > 0; i--) ;
   }while(1);
}

void kal_assert_fail_specific_ext(
#if !defined(__KAL_ASSERT_SHRINKING__)
    char* expr, char* file, 
#endif /* __KAL_ASSERT_SHRINKING__ */
    kal_uint32 line, kal_uint32 ex1, kal_uint32 ex2, kal_uint32 ex3, assert_specific_key key, ...)
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
   link_register = __builtin_return_address(0);
#endif

   do {
      if(file)
          dbg_print("assert fail (%s) at %s line %d with ext( %x, %x, %x )\n\r", expr, file, line, ex1, ex2, ex3);
      else
          dbg_print("assert fail at %x line %d with ext( %x, %x, %x )\n\r", link_register, line, ex1, ex2, ex3);
          
      for(i = 0xFFFFF; i > 0; i--) ;
   }while(1);
}

#endif /* !__KAL_ASSERT_LEVEL0__ */

void kal_assert_fail_native(char* expr, char* file, kal_uint32 line)
{
   kal_uint32 i;

   do {
      dbg_print("assert fail (%s) at %s line %d\n\r", expr, file, line);
      for(i = 0xFFFFF; i > 0; i--) ;
   }while(1);
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if defined(MT6516)
/* ------------------------------------------- Experiment Use For MT6516 Module Test ----------- */

void single_Page_Read(void)
{
   while(1);
}

void get_MTD_lock(void)
{
   while(1);
}

void MTD_MountDevice(void)
{
   while(1);
}

void free_MTD_lock(void)
{
   while(1);
}

void MTD_ShutDown(void)
{
   while(1);
}

void samsung_twoPlane_Program(void)
{
   while(1);
}

void Mtd_para(void)
{
   while(1);
}

void MTD_CE_Interleave_CacheProgram(void)
{
   while(1);
}

void MTD_CE_Interleave_Program(void)
{
   while(1);
}

void MTD_CacheProgram(void)
{
   while(1);
}

void MTD_Program(void)
{
   while(1);
}

void MTD_Read(void)
{
   while(1);
}

void MTD_Erase(void)
{
   while(1);
}

void MTD_MarkBlockBad(void)
{
   while(1);
}

void MTD_CheckBlockBad(void)
{
   while(1);
}

void MTD_NAND_Reset(void)
{
   while(1);
}

void use_interrupt(void)
{
   while(1);
}

#endif //defined(MT6516)

#ifdef __MINI_BOOTLOADER__

kal_int32 CBR_ReadRecord(kal_uint32 cbrIdx, kal_uint16 type, kal_uint8 *pData, kal_uint32 length, const void *pDpArg)
{
   return 0;
}

#endif

