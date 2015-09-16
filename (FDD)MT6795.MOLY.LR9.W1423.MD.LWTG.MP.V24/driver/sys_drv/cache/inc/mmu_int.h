/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   mmu.h
 *
 * Project:
 * --------
 *   Device Test
 *
 * Description:
 * ------------
 *   Header file for MMU.
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

#ifndef __MMU_INT_H__
#define __MMU_INT_H__

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)

#include "kal_general_types.h"

#if defined(__ARM9_MMU__)
#include "mmu_arm9_int.h"
#endif /* __ARM9_MMU__ */

#if defined(__ARM11_MMU__)
#include "mmu_arm11_int.h"
#endif /* __ARM11_MMU__ */

/* user level domain access permission */
enum
{
    ORIGINAL_ACCESS = 0,	
    NO_ACCESS = 1,
    FULL_ACCESS = 2
};

/* user level access permission */
enum
{
    PRIV_RO = 0,
    PRIV_RW = 1,
    USER_RO = 2,
    USER_RW = 3
};

/* user level cacheable and bufferable */
enum
{
    CACHEABLE_BUFFERABLE,
    NONCACHEABLE_BUFFERABLE,
    CACHEABLE_NONBUFFERABLE,
    NONCACHEABLE_NONBUFFERABLE    
};


kal_uint32 MMU_Init(void);
kal_uint32 MMU_InitSecondaryMAUI(void);	
kal_uint32 customized_mmu_init(MMU_PAGE_TABLE_INFO_PTR pinfo, MMU_REGION_INFO_T *cust_region);
kal_uint32 customized_mmu_deinit(void);   
kal_uint32 dynamic_switch_mmu_permission(kal_uint32 addr, kal_uint32 len, kal_uint32 permission);
kal_uint32 dynamic_switch_mmu_dmpermission(kal_uint32 addr, kal_uint32 len, kal_uint32 dm_permission);
kal_uint32 dynamic_switch_mmu_permission_cb(kal_uint32 addr, kal_uint32 len, kal_uint32 permission, kal_uint32 c);
kal_int32 mmu_set_page_config(kal_uint32 vaddr, kal_uint32 paddr, kal_uint32 len, MMU_PAGE_CONFIG_PTR pagc);
kal_int32 mmu_get_page_config(kal_uint32 vaddr, kal_uint32 *paddr, kal_uint32 *psize, MMU_PAGE_CONFIG_PTR pagc);

#endif /* __ARM9_MMU__ || __ARM11_MMU__ */

#endif  /* __MMU_INT_H__ */

