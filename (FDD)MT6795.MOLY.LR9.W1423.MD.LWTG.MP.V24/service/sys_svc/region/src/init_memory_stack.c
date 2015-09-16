/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 *   init_memory_stack.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines the stack distribution, will be referenced in bootarm.s
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include <stdarg.h>
#include "init_memory_stack_int.h"
#include "init.h"
#include "cache_sw_int.h"
#include "cache_sw.h"
#include "cpu.h"
#if defined(__CR4__)
#include "mpu.h"
#endif

#if defined(__SMART_PHONE_MODEM__)
#include "ccci.h"
#endif /* __SMART_PHONE_MODEM__ */
#include "intrCtrl.h"
#if defined(__DEMAND_PAGING__)
#include "page.h"
#endif
#if defined(__RTL_SIMULATION_FOR_60QBIT__)
#include "ebm_if.h"
#endif   /* __RTL_SIMULATION_FOR_60QBIT__ */
#include "custom_scatstruct.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"


#ifdef __MTK_TARGET__

/*******************************************************************************
 * Define import global data
 *******************************************************************************/

#if (defined(_NAND_FLASH_BOOTING_) && !defined(__NFB_SINGLE_ROM__))

extern kal_uint32 Image$$SECONDARY_EXTSRAM_DSP_TX$$Base;
extern kal_uint32 Image$$SECONDARY_EXTSRAM_DSP_RX$$Base;
extern kal_uint32 Image$$SECONDARY_EXTSRAM_DSP_TX$$Length;
extern kal_uint32 Image$$SECONDARY_EXTSRAM_DSP_RX$$Length;
extern kal_uint32 Image$$SECONDARY_EXTSRAM_DSP_TX$$ZI$$Length;
extern kal_uint32 Image$$SECONDARY_EXTSRAM_DSP_RX$$ZI$$Length;

/* for INT_QueryBiggestPool */
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) || defined(__ARM9_DCACHEABLE__)
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI$$Base;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI$$ZI$$Limit;
#else /* __DYNAMIC_SWITCH_CACHEABILITY__ || __ARM9_DCACHEABLE__ */
extern kal_uint32 Image$$SECONDARY_EXTSRAM_LARGEPOOL_NORMAL$$Base;
extern kal_uint32 Image$$SECONDARY_EXTSRAM_LARGEPOOL_NORMAL$$ZI$$Limit;
#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ || __ARM9_DCACHEABLE__ */

#else /* (_NAND_FLASH_BOOTING && !__NFB_SINGLE_ROM__) */

/* for INT_QueryBiggestPool */

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) || defined(__ARM9_DCACHEABLE__)
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI$$Base;
extern kal_uint32 Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI$$ZI$$Limit;
#else /* __DYNAMIC_SWITCH_CACHEABILITY__ || __ARM9_DCACHEABLE__ */
extern kal_uint32 Image$$EXTSRAM_LARGEPOOL_NORMAL$$Base;
extern kal_uint32 Image$$EXTSRAM_LARGEPOOL_NORMAL$$ZI$$Limit;
#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ || __ARM9_DCACHEABLE__ */


extern kal_uint32 Image$$EXTSRAM_DSP_TX$$Base;
extern kal_uint32 Image$$EXTSRAM_DSP_RX$$Base;
extern kal_uint32 Image$$EXTSRAM_DSP_TX$$Length;
extern kal_uint32 Image$$EXTSRAM_DSP_RX$$Length;
extern kal_uint32 Image$$EXTSRAM_DSP_TX$$ZI$$Length;
extern kal_uint32 Image$$EXTSRAM_DSP_RX$$ZI$$Length;

#endif /* _NAND_FLASH_BOOTING || __NOR_FLASH_BOOTING__ || __EMMC_BOOTING__ */

extern kal_uint32 Image$$ROM$$Base;
extern kal_uint32 Image$$EXTSRAM$$Base;
extern kal_uint32 Image$$EXTSRAM$$ZI$$Limit;

extern kal_uint32 SYS_Stack_Pool[];
extern kal_uint32 BOOT_SYS_Stack_End;
extern kal_char _stack_pattern_ptr[];

/*******************************************************************************
 * Define global data
 *******************************************************************************/

switch_stack_info_struct switch_stack_info_g[SWITCH_STACK_INFO_NUM];
kal_uint32 switch_stack_info_cnt_g = 0;

switch_stack_history_struct switch_stack_history_g[SWITCH_STACK_HISTORY_NUM];
kal_uint32 switch_stack_history_cur_g = 0;

static kal_uint32 SysMemoryInfo[(DUMP_REGION_COUNT
#if defined(__SMART_PHONE_MODEM__)
                                 + 1
#endif
#if defined(__KAL_STACK_ISOLATION__)
                                 + 1
#endif
                                 )* 2];


#if defined(__RTL_SIMULATION_FOR_60QBIT__)
static EBM_LOG_T init_ibus_log1, init_ibus_log2, init_dbus_log1, init_dbus_log2;
#endif   /* __RTL_SIMULATION_FOR_60QBIT__ */


/*******************************************************************************
 * Define import function prototype 
 *******************************************************************************/

extern void custom_get_EXTSRAM_size(kal_uint32 *);
extern void custom_get_MaxAvailableMemorySegment(kal_uint32 **start_ptr, kal_uint32 *available_length);
extern kal_uint32 INT_SwitchStackAndBranch(void *new_stack, kal_func_ptr func, kal_uint32 argc, void *argv);
extern kal_uint32 SaveAndSetIRQMask(void);
extern void RestoreIRQMask(kal_uint32 irq);
extern int INT_GetCurrentSP(void);
extern kal_uint32 custom_get_SysRam_Base(void);
kal_uint32 custom_get_SysRam_MaxSize(void);

#if !defined(__FUE__)

/*************************************************************************
* FUNCTION
*  INT_QueryBiggestPool
*
* DESCRIPTION
*  Query the biggest Pool, available for META mode only!
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_bool INT_QueryBiggestPool(kal_uint32 *availableSize, void **ptr)
{
#if defined (IC_BURNIN_TEST)

   *availableSize = 0;
   *ptr = 0;

   return KAL_TRUE;
#else   /* IC_BURNIN_TEST */

   boot_mode_type mode;
   kal_uint32  *start_ptr;
   kal_uint32  available_length;
      
   mode = kal_query_boot_mode();
   
   ASSERT(mode==FACTORY_BOOT);
 
   custom_get_MaxAvailableMemorySegment(&start_ptr, &available_length);
   
#if defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__)
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) || defined(__ARM9_DCACHEABLE__)
   *availableSize = ((kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI$$ZI$$Limit) -
                     (kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI$$Base;
   *ptr = &Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI$$Base;
#else /* __DYNAMIC_SWITCH_CACHEABILITY__ || __ARM9_DCACHEABLE__ */
   *availableSize = ((kal_uint32)&Image$$SECONDARY_EXTSRAM_LARGEPOOL_NORMAL$$ZI$$Limit) -
                     (kal_uint32)&Image$$SECONDARY_EXTSRAM_LARGEPOOL_NORMAL$$Base;
   *ptr = &Image$$SECONDARY_EXTSRAM_LARGEPOOL_NORMAL$$Base;
#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ || __ARM9_DCACHEABLE__ */	 
#else
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__) || defined(__ARM9_DCACHEABLE__)
   *availableSize = ((kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI$$ZI$$Limit) - 
                     (kal_uint32)&Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI$$Base;
   *ptr = &Image$$DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI$$Base;
#else /* __DYNAMIC_SWITCH_CACHEABILITY__ || __ARM9_DCACHEABLE__ */
   *availableSize = ((kal_uint32)&Image$$EXTSRAM_LARGEPOOL_NORMAL$$ZI$$Limit) - 
                     (kal_uint32)&Image$$EXTSRAM_LARGEPOOL_NORMAL$$Base;
   *ptr = &Image$$EXTSRAM_LARGEPOOL_NORMAL$$Base;
#endif /* __DYNAMIC_SWITCH_CACHEABILITY__ || __ARM9_DCACHEABLE__ */	 	 
#endif /* _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__ || __EMMC_BOOTING__ */

   if ( *availableSize < available_length )
   {
      *availableSize = available_length;
      *ptr = start_ptr;     
   }
   
   return KAL_TRUE;
   
#endif /* IC_BURNIN_TEST */
}

/*************************************************************************
* FUNCTION
*  INT_GetSystemStackStartEndAddress
*
* DESCRIPTION
*  Retrieve start address and end address of the system stack
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
void INT_GetSystemStackStartEndAddress(kal_uint32 *start, kal_uint32 *end)
{
   *start = (kal_uint32)SYS_Stack_Pool;
   *end   = BOOT_SYS_Stack_End;
}

/*************************************************************************
* FUNCTION
*  INT_RetrieveRemappedFlashBaseAddr
*
* DESCRIPTION
*  Retrieve start address and end address of the system stack
*  (remapped bank in ALICE support)
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 INT_RetrieveRemappedFlashBaseAddr(void)
{
#if defined(MT6290)
   return BASE_ADDR_SPI;
#endif /* end of MT6290 */
   return (kal_uint32)(&Image$$ROM$$Base) & 0xf0000000;
}

/*************************************************************************
* FUNCTION
*  INT_RetrieveFlashBaseAddr
*
* DESCRIPTION
*   This function returns flash base address to caller.
*  (raw bank in ALICE support)
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_uint32 INT_RetrieveFlashBaseAddr(void)
{
   return INT_RetrieveRemappedFlashBaseAddr();
}

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
/*************************************************************************
* FUNCTION
*  INT_LocateInNORFlash
*
* DESCRIPTION
*   This function returns whether the passed address is within flash bank.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
extern kal_uint32 custom_get_NORFLASH_ROMSpace(void);
kal_bool INT_LocateInNORFlash(kal_uint32 addr)
{
   kal_uint32 base = (kal_uint32)&Image$$ROM$$Base;
   kal_uint32 end = base + custom_get_NORFLASH_ROMSpace();

   if( ((addr >= base) && (addr < end)))
      return KAL_TRUE;
   else
      return KAL_FALSE;

}
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

/*************************************************************************
* FUNCTION
*  INT_RetrieveDSPTXRXBaseAddr
*
* DESCRIPTION
*   This function returns flash base address to caller.
*
* CALLS
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
kal_bool INT_RetrieveDSPTXRXBaseAddr(kal_uint32 *TX_Base, kal_uint32 *RX_Base,
                                     kal_uint32 *CS,
                                     kal_uint32 *TX_Size, kal_uint32 *RX_Size)
{

   kal_uint32     chipSelect;
   kal_uint32     region_sz;

#if defined(IC_BURNIN_TEST)

   *TX_Base = 0;
   *RX_Base = 0;
   return KAL_TRUE;

   
#else   /* IC_BURNIN_TEST */

   /* MT6280 goes here */
   *TX_Base = (kal_uint32)&Image$$EXTSRAM_DSP_TX$$Base;
   *RX_Base = (kal_uint32)&Image$$EXTSRAM_DSP_RX$$Base;
   
   region_sz = 4 * 1024;
   while (region_sz < ((kal_uint32)&Image$$EXTSRAM_DSP_TX$$Length
                      +(kal_uint32)&Image$$EXTSRAM_DSP_TX$$ZI$$Length))
   {
      region_sz = region_sz << 1;
   }
   *TX_Size = region_sz;

   region_sz = 4 * 1024;
   while (region_sz < ((kal_uint32)&Image$$EXTSRAM_DSP_RX$$Length
                      +(kal_uint32)&Image$$EXTSRAM_DSP_RX$$ZI$$Length))
   {
      region_sz = region_sz << 1;
   }
   *RX_Size = region_sz;

#if defined(MT6290)
   chipSelect = (*TX_Base&0x38000000) >> 27;
   ASSERT(chipSelect<8);
#else /* MT6290 */
   chipSelect = (*TX_Base&0xF8000000) >> 27;
   ASSERT(chipSelect<2);
#endif /* MT6290 */

   *CS = chipSelect;

   return KAL_TRUE;

#endif /* IC_BURNIN_TEST */   
}

#endif /* !__FUE__ */

/*************************************************************************
* FUNCTION
*  INT_GetSysMemoryInfo
*
* DESCRIPTION
*  This API is design for TST/TR/Catcher to do exception handling.
*
* PARAMETERS
*
* RETURNS
*
*************************************************************************/
#if !defined(__FUE__)
void INT_GetSysMemoryInfo( kal_uint32 **info, kal_uint16* count )
{
   kal_uint32 var_index = 0, count_sys_num = 0;
#if defined(__SMART_PHONE_MODEM__)      
   kal_uint32 share_startaddr = 0, share_endaddr = 0 , share_len = 0;
#endif /* __SMART_PHONE_MODEM__ */
#if defined(__KAL_STACK_ISOLATION__)
   kal_uint32 stack_addr = 0, stack_len = 0;
#endif /* __KAL_STACK_ISOLATION__ */

    /* get regions to be dumped from scatter struct */
    var_index = custom_query_dump_region((EXTSRAM_REGION_INFO_T*)SysMemoryInfo);

    /* misc */
#if defined(__SMART_PHONE_MODEM__)
   ccci_CalculateShareMem(&share_startaddr, &share_endaddr , &share_len);
   SysMemoryInfo[var_index++] = share_startaddr;
   SysMemoryInfo[var_index++] = share_len;   
#endif  /* __SMART_PHONE_MODEM__ */

#if defined(__KAL_STACK_ISOLATION__) && !defined(__FUE__) && !defined(__UBL__)
   kal_query_stack_space(&stack_addr, &stack_len);
   SysMemoryInfo[var_index++] = stack_addr;
   SysMemoryInfo[var_index++] = stack_len;
#endif /* __KAL_STACK_ISOLATION__ */

    /* calculate the number of regions to be dumped */
   *info  = (kal_uint32*)SysMemoryInfo;
   *count = var_index / 2;
   count_sys_num = sizeof(SysMemoryInfo) / sizeof(kal_uint32) / 2;
   if (*count > count_sys_num) {
      ASSERT(0);
   }
}
#endif /* !__FUE__ */


#if !defined(__FUE__)
/*************************************************************************
* FUNCTION
*  INT_SwitchStackToRun
*
* DESCRIPTION
*  Switch current stack pointer to new_stack and then run func(...).
*
* CALLS
*      INT_SwitchStackAndBranch
*
* PARAMETERS
*      stack_start    the start address of the new stack (NOT a pointer of start address)
*      stack_size     the size of the stack
*      func           the pointer of function which want to run
*      argc           the number of arguments of func
*      ...            the arguments of func
*
* RETURNS
*      The reture value of func
*
*************************************************************************/
kal_uint32 INT_SwitchStackToRun(void *stack_start, kal_uint32 stack_size, kal_func_ptr func, kal_uint32 argc, ...)
{
   #define NO_AVAILABLE 0xffff
   
   kal_uint32 i, available = NO_AVAILABLE;
   kal_taskid task_self_id = kal_get_current_task();
   kal_uint32 irq;
   kal_uint32 *stack_ptr;
   kal_uint32 ret;
   va_list    argv;
#ifdef __STACK_ALIGN_MPU__
#if defined(__CR4__)
   REGION_SETTING_TYPE ori_mpu;
#elif defined(__MTK_MMU_V2__)
   PROT_REGION_SETTING_TYPE ori_mpu;
#else /* __MTK_MMU_V2__ */
   #error "No CPU version select. Need to specify CPU version in project 6290 for MDSYS."
#endif /* else */
#endif /* end of __STACK_ALIGN_MPU__ */


   /*********** Step 1: Align The Stack **************************************/

   /* check whether the stack start address is N-byte alignment or not */
   if ((kal_uint32)stack_start & KAL_TASK_STACK_ALIGNMASK) {
      /* we need to adjust the stack size since we will adjust the stack start address */
      stack_size -= (KAL_TASK_STACK_ALIGN - ((kal_uint32)stack_start & KAL_TASK_STACK_ALIGNMASK));

      /* insure that the stack start address is N-byte alignment */
      stack_start = (void *)(((kal_uint32)stack_start & (~KAL_TASK_STACK_ALIGNMASK)) + KAL_TASK_STACK_ALIGN);
   }

   /* insure that the stack size is multiple of 8 bytes */
   stack_size &= ~7;


   /*********** Step 2: Guarantee Not Overlap ********************************/

   irq = SaveAndSetIRQMask(); /* begin of critical section */

   /* check the stack not overlap with previous stacks */
   for (i = 0; i < switch_stack_info_cnt_g; i++)
   {
      if (switch_stack_info_g[i].stack_start)
      {
      	
         if ((kal_uint32)stack_start < (kal_uint32)switch_stack_info_g[i].stack_end
            && (kal_uint32)stack_start + stack_size > (kal_uint32)switch_stack_info_g[i].stack_start)
         {
            #define SWITCH_STACK_OVERLAP 0
            EXT_ASSERT(SWITCH_STACK_OVERLAP,
                       (kal_uint32)stack_start,
                       (kal_uint32)switch_stack_info_g[i].stack_start,
                       (kal_uint32)switch_stack_info_g[i].stack_end);
         }
      }
      else if (available == NO_AVAILABLE)
      {
      	 /* mark it an available slot */
         available = i;
      }
   }
   
   /* if no available slot, increase the count of slots */
   if (available == NO_AVAILABLE)
   {
      if (switch_stack_info_cnt_g < SWITCH_STACK_INFO_NUM)
      {
         available = switch_stack_info_cnt_g;
         switch_stack_info_cnt_g++;
      }
      else
      {
         #define SWITCH_STACK_NO_MORE_SLOT 0
         EXT_ASSERT(SWITCH_STACK_NO_MORE_SLOT,
                    (kal_uint32)switch_stack_info_cnt_g, 0, 0);
      }
   }

   /* fill the info of the stack */
   switch_stack_info_g[available].stack_start = stack_start;
   switch_stack_info_g[available].stack_end   = (void *)( (kal_uint32) stack_start + stack_size);

   switch_stack_history_g[switch_stack_history_cur_g].state       = STACK_ALLOCATED;
   switch_stack_history_g[switch_stack_history_cur_g].stack_start = stack_start;
   switch_stack_history_g[switch_stack_history_cur_g].stack_end   = (void *)( (kal_uint32) stack_start + stack_size);
   switch_stack_history_g[switch_stack_history_cur_g].old_sp      = (void *)INT_GetCurrentSP();
   switch_stack_history_g[switch_stack_history_cur_g].task_id     = task_self_id;

   switch_stack_history_cur_g++;
   if (switch_stack_history_cur_g == SWITCH_STACK_HISTORY_NUM)
      switch_stack_history_cur_g = 0;

   RestoreIRQMask(irq);       /* end of critical section */


   /*********** Step 3: Fill Guard Pattern ***********************************/

   /* fill the guard pattern in the start of the stack */
   stack_ptr = (kal_uint32*)stack_start;
   *stack_ptr = *((kal_uint32*)_stack_pattern_ptr);
   *(stack_ptr+1) = *((kal_uint32*)&_stack_pattern_ptr[4]);
   
   /* fill the guard pattern in the end of the stack */
   stack_ptr = (kal_uint32*)stack_start+(stack_size>>2)-2;
   *stack_ptr = *((kal_uint32*)_stack_pattern_ptr);
   *(stack_ptr+1) = *((kal_uint32*)&_stack_pattern_ptr[4]);


   /*********** Step 4: Call Assembly Function *******************************/

   /* set MPU protect region */
#ifdef __STACK_ALIGN_MPU__
   ori_mpu.rgn_no = MPU_REGION_SP_USER;

   CPU_SAVE_STACK_MPU_PROTECT(MPU_REGION_SP_USER, &ori_mpu);
   CPU_SET_STACK_MPU_PROTECT(MPU_REGION_SP_USER, stack_start);
#endif

   /* call the assembly function to switch stack and branch func(...) */   
   va_start(argv, argc);
   /* 
    * NoteXXX: va_list definition different between ADS 1.2 , RVCT 2.2 (ADS ABI) 
    * and RVCT 2.2 (Not ADS ABI) , RVCT 3.1
    * __RVCT__ is defined for RVCT 2.2 , RVCT 3.1
    * __APCS_ADSABI is defined for RVCT 2.2 (ADS ABI)
    */
#if defined(__RVCT__) || defined(__GNUC__) && !defined(__APCS_ADSABI)
   ret = INT_SwitchStackAndBranch(stack_ptr, func, argc, (void *)(argv.__ap));
#else 
   ret = INT_SwitchStackAndBranch(stack_ptr, func, argc, (void *)(argv[0]));
#endif
   va_end(argv);

   /* restore MPU protect region, TC_TCB/TC_HCB have the same base class */
#ifdef __STACK_ALIGN_MPU__
   CPU_RESTORE_STACK_MPU_PROTECT(&ori_mpu);
#endif


   /*********** Step 5: Check Guard Pattern **********************************/

   /* check the guard pattern of the start */
   stack_ptr = (kal_uint32*)stack_start;
   if ( (*stack_ptr != *((kal_uint32*)_stack_pattern_ptr)) || 
        (*(stack_ptr+1) != *((kal_uint32*)&_stack_pattern_ptr[4])) ) {
            #define SWITCH_STACK_CORRUPTED 0
            EXT_ASSERT(SWITCH_STACK_CORRUPTED,
                       (kal_uint32)stack_ptr,
                       (kal_uint32)stack_start,
                       (kal_uint32)stack_size);
        }

   /* check the guard pattern of the end */
   stack_ptr = (kal_uint32*)(kal_uint32*)stack_start+(stack_size>>2)-2;
   if ( (*stack_ptr != *((kal_uint32*)_stack_pattern_ptr)) || 
        (*(stack_ptr+1) != *((kal_uint32*)&_stack_pattern_ptr[4])) ) {
            #define SWITCH_STACK_OVERFLOW 0
            EXT_ASSERT(SWITCH_STACK_OVERFLOW,
                       (kal_uint32)stack_ptr,
                       (kal_uint32)stack_start,
                       (kal_uint32)stack_size);
        }

   irq = SaveAndSetIRQMask(); /* begin of critical section */

   /* clear the stack info */
   switch_stack_info_g[available].stack_start = 0;
   while (switch_stack_info_cnt_g && !(switch_stack_info_g[switch_stack_info_cnt_g-1].stack_start))
      switch_stack_info_cnt_g--;

   i = switch_stack_history_cur_g;
   do
   {
      if (i == 0)
         i = SWITCH_STACK_HISTORY_NUM - 1;
      else
         i--;

      if (switch_stack_history_g[i].stack_start == stack_start
          && switch_stack_history_g[i].state == STACK_ALLOCATED)
      {
         switch_stack_history_g[i].state = STACK_FREED;
         break;
      }
   } while (i != switch_stack_history_cur_g);

   RestoreIRQMask(irq);       /* end of critical section */


   /* return the return value of func(...) */
   return ret;
}
#endif /* !__FUE__ */

/*************************************************************************
* FUNCTION
*  INT_QuerySystemRAMInfo
*
* DESCRIPTION
*  This function gets the start address and lenght of system RAM.
*
* CALLS
*
* PARAMETERS
*  addr   -   pointer to store start address of system RAM
*  len    -   pointer to sttore length of system RAM
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
kal_int32 INT_QuerySystemRAMInfo(kal_uint32 *addr, kal_uint32 *len)
{
   *addr = custom_get_SysRam_Base();
   *len = custom_get_SysRam_MaxSize();
   if(*len == 0)
   {
       return -1;
   }
   else
   {
       return 0;     
   }
}

/*************************************************************************
* FUNCTION
*  INT_QueryOnDemandROMInfo
*
* DESCRIPTION
*  This function gets the start address and lenght of NFB OnDemand ROM.
*
* CALLS
*
* PARAMETERS
*  addr   -   pointer to store start address of OnDemand ROM
*  len    -   pointer to sttore length of OnDemand ROM
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
kal_int32 INT_QueryOnDemandROMInfo(kal_uint32 *addr, kal_uint32 *len)
{
#if defined(__DEMAND_PAGING__)
   *addr = demp_begin(DEMP_MAIN);
   *len  = demp_end(DEMP_MAIN) - demp_begin(DEMP_MAIN);
   return  0;
#else  /* __DEMAND_PAGING__ */
   return -1;
#endif /* __DEMAND_PAGING__ */
}

#if defined(__RTL_SIMULATION_FOR_60QBIT__)
/*************************************************************************
* FUNCTION
*  profile_INT_SwitchStackToRun_before
*
* DESCRIPTION
*  The function profile the critical path 1 of IRQ-lock code within the
*  function INT_SwitchStackToRun.
*  Notex: This function is only used for profiling the IRQ-lock code in
*         a new project's pre-silicon stage. It is not used on real target.
*
* PARAMETERS
*  none
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
kal_int32 profile_INT_SwitchStackToRun_before(void)
{
   void *stack_start;
   kal_uint32 stack_size;
   kal_uint32 irq;
   kal_uint32 i, available = NO_AVAILABLE;
   kal_taskid task_self_id;

   /* set some data to trigger the longest path of the program */

   stack_start = (void *)10;
   stack_size = 5;
   switch_stack_info_cnt_g = SWITCH_STACK_INFO_NUM - 1;
   switch_stack_history_cur_g = SWITCH_STACK_HISTORY_NUM - 1;
   task_self_id = kal_get_task_self_id();

   for (i = 0; i < SWITCH_STACK_INFO_NUM; i++) {
      switch_stack_info_g[i].stack_start = (void *)((kal_uint32)stack_start + 2 * stack_size);
      switch_stack_info_g[i].stack_end = (void *)((kal_uint32)stack_start + stack_size);
   }
   
   /* extract the critical path of the IRQ-lock program in INT_SwitchStackToRun() */

   EBM_INIT();

   EBM_START();

   irq = SaveAndSetIRQMask(); /* begin of critical section */

   /* check the stack not overlap with previous stacks */
   for (i = 0; i < switch_stack_info_cnt_g; i++)
   {
      if (switch_stack_info_g[i].stack_start)
      {
      	
         if ((kal_uint32)stack_start < (kal_uint32)switch_stack_info_g[i].stack_end
            && (kal_uint32)stack_start + stack_size > (kal_uint32)switch_stack_info_g[i].stack_start)
         {
            #define SWITCH_STACK_OVERLAP 0
            EXT_ASSERT(SWITCH_STACK_OVERLAP,
                       (kal_uint32)stack_start,
                       (kal_uint32)switch_stack_info_g[i].stack_start,
                       (kal_uint32)switch_stack_info_g[i].stack_end);
         }
      }
      else if (available == NO_AVAILABLE)
      {
      	 /* mark it an available slot */
         available = i;
      }
   }
   
   /* if no available slot, increase the count of slots */
   if (available == NO_AVAILABLE)
   {
      if (switch_stack_info_cnt_g < SWITCH_STACK_INFO_NUM)
      {
         available = switch_stack_info_cnt_g;
         switch_stack_info_cnt_g++;
      }
      else
      {
         #define SWITCH_STACK_NO_MORE_SLOT 0
         EXT_ASSERT(SWITCH_STACK_NO_MORE_SLOT,
                    (kal_uint32)switch_stack_info_cnt_g, 0, 0);
      }
   }

   /* fill the info of the stack */
   switch_stack_info_g[available].stack_start = stack_start;
   switch_stack_info_g[available].stack_end   = (void *)( (kal_uint32) stack_start + stack_size);

   switch_stack_history_g[switch_stack_history_cur_g].state       = STACK_ALLOCATED;
   switch_stack_history_g[switch_stack_history_cur_g].stack_start = stack_start;
   switch_stack_history_g[switch_stack_history_cur_g].stack_end   = (void *)( (kal_uint32) stack_start + stack_size);
   switch_stack_history_g[switch_stack_history_cur_g].old_sp      = (void *)INT_GetCurrentSP();
   switch_stack_history_g[switch_stack_history_cur_g].task_id     = task_self_id;

   switch_stack_history_cur_g++;
   if (switch_stack_history_cur_g == SWITCH_STACK_HISTORY_NUM)
      switch_stack_history_cur_g = 0;

   RestoreIRQMask(irq);       /* end of critical section */

   EBM_PAUSE();
   EBM_GET_MCU_IBUS_LOG(&init_ibus_log1);
   EBM_GET_MCU_DBUS_LOG(&init_dbus_log1);

   EBM_STOP();

   return 0;
}

/*************************************************************************
* FUNCTION
*  profile_INT_SwitchStackToRun_after
*
* DESCRIPTION
*  The function profile the critical path 2 of IRQ-lock code within the
*  function INT_SwitchStackToRun.
*  Notex: This function is only used for profiling the IRQ-lock code in
*         a new project's pre-silicon stage. It is not used on real target.
*
* PARAMETERS
*  none
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
kal_int32 profile_INT_SwitchStackToRun_after(void)
{
   kal_uint32 irq;
   kal_uint32 i, available;
   void *stack_start;

   /* set some data to trigger the longest path of the program */

   available = 0;
   switch_stack_info_cnt_g = SWITCH_STACK_INFO_NUM - 1;
   switch_stack_history_cur_g = 0;
   stack_start = (void *)10;

   for (i = 0; i < SWITCH_STACK_INFO_NUM; i++) {
      switch_stack_info_g[i].stack_start = (void *)0;
      switch_stack_info_g[i].stack_end = (void *)0;
   }

   for (i = 1; i < SWITCH_STACK_HISTORY_NUM; i++) {
      switch_stack_history_g[i].stack_start = (void *)0;
      switch_stack_history_g[i].state = STACK_ALLOCATED;
   }
   switch_stack_history_g[0].stack_start = stack_start;
   switch_stack_history_g[0].state = STACK_ALLOCATED;

   /* extract the critical path of the IRQ-lock program in INT_SwitchStackToRun() */

   EBM_INIT();

   EBM_START();

   irq = SaveAndSetIRQMask(); /* begin of critical section */

   /* clear the stack info */
   switch_stack_info_g[available].stack_start = 0;
   while (switch_stack_info_cnt_g && !(switch_stack_info_g[switch_stack_info_cnt_g-1].stack_start))
      switch_stack_info_cnt_g--;

   i = switch_stack_history_cur_g;
   do
   {
      if (i == 0)
         i = SWITCH_STACK_HISTORY_NUM - 1;
      else
         i--;

      if (switch_stack_history_g[i].stack_start == stack_start
          && switch_stack_history_g[i].state == STACK_ALLOCATED)
      {
         switch_stack_history_g[i].state = STACK_FREED;
         break;
      }
   } while (i != switch_stack_history_cur_g);

   RestoreIRQMask(irq);       /* end of critical section */

   EBM_PAUSE();
   EBM_GET_MCU_IBUS_LOG(&init_ibus_log2);
   EBM_GET_MCU_DBUS_LOG(&init_dbus_log2);

   EBM_STOP();

   return 0;
}
#endif  /* __RTL_SIMULATION_FOR_60QBIT__ */

#endif  /* __MTK_TARGET__ */

