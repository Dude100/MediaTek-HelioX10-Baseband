/******************************************************************************* 
*  Copyright Statement: 
*  -------------------- 
*  This software is protected by Copyright and the information contained 
*  herein is confidential. The software may not be copied and the information 
*  contained herein may not be used or disclosed except with the written 
*  permission of MediaTek Inc. (C) 2001 
* 
*******************************************************************************/ 
 
/******************************************************************************* 
 * 
 * Filename: 
 * --------- 
 *   cp15.s 
 * 
 * Project: 
 * -------- 
 *   MAUI 
 * 
 * Description: 
 * ------------ 
 *   This files implements coprocessor(CP15) control. 
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
 *------------------------------------------------------------------------------ 
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================ 
 ****************************************************************************/ 
#if defined(__ARM9_MMU__)
      #include "cp15_drv_region_gcc.inc"
      #include "arm9_cp15_gcc.inc"
      
#elif defined(__ARM11_MMU__)
      #include "arm11_cp15_gcc.inc"
      
#elif defined(__CR4__)
      #include "asm_def.h"
      #include "cp15_drv_region_gcc.inc"
      #include "cr4_cp15_gcc.inc"
      
#else
      @ Empty CP15
      
#endif

    .end 
