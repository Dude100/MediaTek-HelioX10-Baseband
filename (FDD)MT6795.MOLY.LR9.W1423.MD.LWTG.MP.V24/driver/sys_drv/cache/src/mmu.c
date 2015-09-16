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
 *   mmu.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the functionality of Code and Data cache.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************************
 * README
 * Test platform after revision
 * [1] NOR Flash boot without remap , MT6229_EVB
 * [2] NAND Flash boot , MT6228_EVB
 * [3] NOR Flash boot with remap , MT6225 + Single Bank NOR Flash , for example CRYSTAL25 V3 SB
 ********************************************************************************************/


/*******************************************************************************
 * Include header files.
 *******************************************************************************/

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "reg_base.h"
#include "cache_sw_int.h"
#include "cache_sw.h"
#include "init.h"
#include "cp15.h"
#include "mmu_int.h"
#include "mmu.h"
//#include "dma_hw.h"
#include "page.h"
#include "emi_hw.h"
#include "swtr.h"
#include "custom_scatstruct.h"

#include "NAND_MTD.h"

#include "kal_general_types.h"
#include "string.h"
#include "config_hw.h"
    
#ifdef __MTK_TARGET__

/*******************************************************************************
 * Define const.
 *******************************************************************************/

/*******************************************************************************
 * Define import global data.
 *******************************************************************************/


/*******************************************************************************
 * Define import functions.
 *******************************************************************************/

extern void RestoreIRQMask(kal_uint32 ret);
extern kal_uint32 SaveAndSetIRQMask(void);
extern void custom_get_MaxAvailableMemorySegment(kal_uint32 **Return_begin_addr, kal_uint32 *Return_segment_size);
extern kal_uint32 custom_get_INTSRAMCODE_Base();
extern kal_uint32 custom_get_INTSRAMDATA_Base();


/*******************************************************************************
 * Define global data.
 *******************************************************************************/

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
/* Top level page table */
#ifdef __MTK_TARGET__
__attribute__ ((aligned (16 * 1024), section ("PAGETABLE"), zero_init)) kal_uint32 page_tbl[4096];
#else /* __MTK_TARGET__ */
__align(16 * 1024) kal_uint32 page_tbl[4096];
#endif /* __MTK_TARGET__ */

/* temp page table */
#ifdef __MTK_TARGET__
__attribute__ ((aligned (16 * 1024), section ("TMPPAGETABLE"), zero_init)) kal_uint32 tmp_page_tbl[4096];
#else /* __MTK_TARGET__ */
__align(16 * 1024) kal_uint32 tmp_page_tbl[4096];
#endif /* __MTK_TARGET__ */

/* Second Level Page Table Pointers */
#if defined(__ARM9_MMU__)
// ARM9-only Fine Page Table
#ifdef __MTK_TARGET__
__attribute__ ((zero_init, section ("NONCACHEDZI"))) 
#endif /* __MTK_TARGET__ */
kal_uint32 *fpt_pool, fpt_pool_indx, fpt_pool_size;
#endif /* __ARM9_MMU__ */

#ifdef __MTK_TARGET__
// Coarse Page Table
__attribute__ ((zero_init, section ("NONCACHEDZI"))) 
#endif /* __MTK_TARGET__ */
kal_uint32 *cpt_pool, cpt_pool_indx, cpt_pool_size;
#ifdef __MTK_TARGET__
__attribute__ ((zero_init, section ("NONCACHEDZI"))) 
#endif /* __MTK_TARGET__ */
kal_uint32 *cust_page_tbl;

// TLB Lockdown Counter (Prevent TLB overflow)
kal_uint32 tlb_lockdown_count=0;
#endif  /* __ARM9_MMU__ || __ARM11_MMU__ */

/*************************************************************************
* FUNCTION
*  alloc_ptbl
*
* DESCRIPTION
*  This function allocates memory for page table.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  size   -   page table size
*
* RETURNS
*  memory address for the page table
*
*************************************************************************/
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
kal_uint32 alloc_ptbl(kal_uint32 size)
{
   kal_uint32 addr;

   addr = 0;

   if (size == CPT_SIZE) {
      if ((cpt_pool_indx + size) > cpt_pool_size) {
         /* out-of-memory */
         cpt_pool_indx += size;
         addr =(kal_uint32)(NULL);
      } else {
         addr = (kal_uint32)((kal_uint8 *)cpt_pool + cpt_pool_indx);
         cpt_pool_indx += size;
      }
   } 
#if defined(__ARM9_MMU__)
   else if (size == FPT_SIZE) {
      if ((fpt_pool_indx + size) > fpt_pool_size) {
         /* out-of-memory */
         fpt_pool_indx += size;
         //addr = NULL;
         addr = 0;  //fix compiler error of 6589 k2 md2
      } else {
         addr = (kal_uint32)((kal_uint8 *)fpt_pool + fpt_pool_indx);
         fpt_pool_indx += size;
      }
   }
#endif /* __ARM9_MMU__ */
   else {
      ASSERT(0);
   }

   return addr;
}

#endif  /* __ARM9_MMU__ */

/*************************************************************************
* FUNCTION
*  check_cptbl_pool
*
* DESCRIPTION
*  This function checks if the coarse page table pool is exhausted.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  none
*
* RETURNS
*  
*
*************************************************************************/
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
kal_uint32 check_cptbl_pool()
{
   if (cpt_pool_indx > cpt_pool_size) {
      return cpt_pool_indx - cpt_pool_size;
   } else {
      return 0;
   }
}
#endif  /* __ARM9_MMU__ || __ARM11_MMU__ */

/*************************************************************************
* FUNCTION
*  check_fptbl_pool
*
* DESCRIPTION
*  This function checks if the fine page table pool is exhausted.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  none
*
* RETURNS
*  
*
*************************************************************************/
#if defined(__ARM9_MMU__)
kal_uint32 check_fptbl_pool()
{
   if (fpt_pool_indx > fpt_pool_size) {
      return fpt_pool_indx - fpt_pool_size;
   } else {
      return 0;
   }
}
#endif  /* __ARM9_MMU__ */

/*************************************************************************
* FUNCTION
*  mk_pte
*
* DESCRIPTION
*  This function makes a page table entry according to specification.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  page_tbl   -   page table
*  vaddr      -   virtual address for the entry
*  paddr      -   physical address for the entry
*  size       -   page size
*  ap         -   access permission
*  c          -   cacheable
*  b          -   bufferable
*  d          -   domain
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
kal_int32 mk_pte(kal_uint32 vaddr, kal_uint32 paddr, kal_uint32 size, const MMU_PAGE_CONFIG_PTR pagc, kal_uint32 cust)
{
   kal_uint32 tbl, *tbl_ptr, indx;
   kal_int32 i;
   kal_uint32 *pt;

   (cust == DEF_PAGE_TABLE)? (pt = page_tbl): (pt = cust_page_tbl);

   tbl = 0;
   tbl_ptr = NULL;
   indx = 0;
   i = 0;

   switch (size) {
      
#if defined(__ARM9_MMU__)
      case PAGE_SIZE_1KB:
         if (!is_fptd(pt[vaddr >> PAGE_SIZE_1MB_SHIFT])) {
            /* create one fine page and one page table entry */
            tbl = alloc_ptbl(FPT_SIZE);
            //if (tbl == NULL) {
            if (!tbl) {  //fix compiler error of 6589 k2 md2
               return -1;
            }
            mk_fpt(tbl);
      
            pt[vaddr >> PAGE_SIZE_1MB_SHIFT] = mk_fptd(tbl, pagc);
         }

         tbl_ptr = (kal_uint32 *)(pt[vaddr >> PAGE_SIZE_1MB_SHIFT] & FPT_BASE_MASK);     
         tbl_ptr[(vaddr & 0x000ffc00) >> PAGE_SIZE_1KB_SHIFT] = mk_tpd(paddr, pagc);

         break;
#endif /* __ARM9_MMU__ */

      case PAGE_SIZE_4KB:
         if (!is_cptd(pt[vaddr >> PAGE_SIZE_1MB_SHIFT])) {
            /* create one coarse page and one page table entry */
            tbl = alloc_ptbl(CPT_SIZE);
            if (tbl == (kal_uint32)(NULL)) {
               return -1;
            }
            mk_cpt(tbl);
            pt[vaddr >> PAGE_SIZE_1MB_SHIFT] = mk_cptd(tbl, pagc);
         }

         tbl_ptr = (kal_uint32 *)(pt[vaddr >> PAGE_SIZE_1MB_SHIFT] & CPT_BASE_MASK); 
         tbl_ptr[(vaddr & 0x000ff000) >> PAGE_SIZE_4KB_SHIFT] = mk_spd(paddr, pagc);
     
         break;

      case PAGE_SIZE_64KB:
         if (!is_cptd(pt[vaddr >> PAGE_SIZE_1MB_SHIFT])) {
            /* create one coarse page and one page table entry */
            tbl = alloc_ptbl(CPT_SIZE);
            if (tbl == (kal_uint32)(NULL)) {
               return -1;
            }
            mk_cpt(tbl);

            pt[vaddr >> PAGE_SIZE_1MB_SHIFT] = mk_cptd(tbl, pagc);
         }

         tbl_ptr = (kal_uint32 *)(pt[vaddr >> PAGE_SIZE_1MB_SHIFT] & CPT_BASE_MASK); 

         indx = (vaddr & 0x000ff000) >> PAGE_SIZE_4KB_SHIFT;
         for (i = 16; i != 0; i--) {
            tbl_ptr[indx + i - 1] = mk_lpd(paddr, pagc);
         }

         break;

      case PAGE_SIZE_1MB:
         pt[vaddr >> PAGE_SIZE_1MB_SHIFT] = mk_sd(paddr, pagc);
      
         break;

#if defined(__ARM11_MMU__)
      case PAGE_SIZE_16MB:
         indx = (vaddr & (~PAGE_SIZE_16MB_MASK)) >> PAGE_SIZE_1MB_SHIFT;
         for (i=16; i != 0; i--) {
            pt[indx + i - 1] = mk_ssd(paddr, pagc);
         }
      
         break;
#endif /* __ARM11_MMU__ */

      default:
         ASSERT(0);
         break;
   }

   return 0;
}

#endif  /* __ARM9_MMU__ || __ARM11_MMU__ */



/*************************************************************************
* FUNCTION
*  config_customized_pt
*
* DESCRIPTION
*  This function makes page table for the specified region.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  vaddr    -   virtual address of the region
*  paddr    -   physical address of the region
*  lenght   -   length of the region (in bytes)
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
kal_int32 config_customized_pt( MMU_PAGE_TABLE_INFO_PTR pinfo)
{
   cust_page_tbl = pinfo->cust_page_tbl;
#if defined(__ARM9_MMU__)
   fpt_pool = pinfo->cust_fpt_pool;
   fpt_pool_size = pinfo->cust_fpt_pool_size;
   fpt_pool_indx = 0;
#endif
   cpt_pool = pinfo->cust_cpt_pool;
   cpt_pool_size = pinfo->cust_cpt_pool_size;
   cpt_pool_indx = 0;  

   return 0;
}
#endif  /* __ARM9_MMU__ || __ARM11_MMU__ */

/*************************************************************************
* FUNCTION
*  mk_pt
*
* DESCRIPTION
*  This function makes page table for the specified region.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  vaddr    -   virtual address of the region
*  paddr    -   physical address of the region
*  lenght   -   length of the region (in bytes)
*
* RETURNS
*  0 for success; -1 for failure
*
*************************************************************************/

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)

kal_int32 mk_pt(kal_uint32 vaddr, kal_uint32 paddr, kal_uint32 len, const MMU_PAGE_CONFIG_PTR pagc, kal_uint32 cust)
{
   kal_uint32 s;
   kal_uint32 *pt;
   kal_uint32 i;
   MMU_PAGE_CONFIG_T temp_pag;
   kal_uint32 temp_vaddr;
   kal_uint32 temp_paddr;
   kal_uint32 sec_pg_baddr;      
   kal_uint32 sec_pg_idx;  
   kal_uint32 sec_pg;

   (cust == DEF_PAGE_TABLE)? (pt = page_tbl): (pt = cust_page_tbl);
   
   if(len != 0 && (vaddr & SMALLEST_PAGE_SIZE_MASK) != 0)
   {
      len += (vaddr&SMALLEST_PAGE_SIZE_MASK);
      vaddr &= ~SMALLEST_PAGE_SIZE_MASK;
      paddr &= ~SMALLEST_PAGE_SIZE_MASK;
   }
   
   while (len > 0) {
      /* try to find a best-fit page size */
#if defined(__ARM11_MMU__)
      if (len >= PAGE_SIZE_16MB && (vaddr & PAGE_SIZE_16MB_MASK) == 0) {
         s = PAGE_SIZE_16MB;
      } else 
#endif /* __ARM11_MMU__ */
      if (len >= PAGE_SIZE_1MB && (vaddr & PAGE_SIZE_1MB_MASK) == 0) {
         s = PAGE_SIZE_1MB;
      } else if ((len + (vaddr & PAGE_SIZE_1MB_MASK)) & ~PAGE_SIZE_1MB_MASK) {
         /*
          * The target space will be just ended at 1MB boundary.
          * Thus the remaining length needs not to be considered.
          * Once one kind of pages is selected, we can use this kind of pages
          * for the remaining space.
          */
         if ((vaddr & PAGE_SIZE_64KB_MASK) == 0) {
            s = PAGE_SIZE_64KB;
         } else if ((vaddr & PAGE_SIZE_4KB_MASK) == 0) {
            s = PAGE_SIZE_4KB;
         } else {
            s = SMALLEST_PAGE_SIZE;
         }
      } else if (len >= PAGE_SIZE_64KB && (len & PAGE_SIZE_4KB_MASK) == 0 && (vaddr & PAGE_SIZE_64KB_MASK) == 0) {
         /*
          * A coarse page table can manage either 64KB large page or 4KB small page.
          * Thus the remaining length only needs to be multiple of 4KB.
          * We can use 4KB small page to manage the remaining space.
          * But the start address must be 64KB aligned.
          */
         s = PAGE_SIZE_64KB;
      } else if ((len & PAGE_SIZE_4KB_MASK) == 0 && (vaddr & PAGE_SIZE_4KB_MASK) == 0) {
         /*
          * A coarse page table cannot manage 1KB tiny page.
          * Thus the remaining length must be multiple of 4KB.
          * We cannot manage 1KB small page for the remaining space.
          */
         s = PAGE_SIZE_4KB;
      } else {
         s = SMALLEST_PAGE_SIZE;
      }
#if defined(__ARM9_MMU__)
      if (is_fptd(pt[vaddr >> PAGE_SIZE_1MB_SHIFT]) && (s != PAGE_SIZE_1KB))
      {
         s = PAGE_SIZE_1KB;
      } else 
#endif
      if (is_cptd(pt[vaddr >> PAGE_SIZE_1MB_SHIFT]))
      {
         if(((s != PAGE_SIZE_4KB) && (s != PAGE_SIZE_64KB)))
      {
         s = PAGE_SIZE_4KB;
      }

         sec_pg_baddr = cptd_tba(pt[vaddr >> PAGE_SIZE_1MB_SHIFT]);
         sec_pg_idx = (vaddr & FIRST_LEVEL_COARSE_L2PT_INDEX_RETRIEVE)>>FIRST_LEVEL_COARSE_L2PT_INDEX_SHIFT;
         sec_pg = *(volatile kal_uint32*)(sec_pg_baddr + sec_pg_idx*4);

         if(is_lpd(sec_pg) && (s == PAGE_SIZE_4KB))
         {
            /*
              * split the large page(64KB) into small pages(4KB)
           */         
            temp_vaddr = vaddr & ~PAGE_SIZE_64KB_MASK;
            temp_paddr = paddr & ~PAGE_SIZE_64KB_MASK;
         
            get_lpd_conf(sec_pg, (MMU_PAGE_CONFIG_PTR)&temp_pag);
            SET_DOMAIN(pagc->domain, (MMU_PAGE_CONFIG_PTR)&temp_pag);
            for(i=0; i<PAGE_SIZE_64KB; i+=s)
            {
               mk_pte(temp_vaddr+i, temp_paddr+i, s, &temp_pag, cust);
            }            
    }    
      }
      else if (is_sd(pt[vaddr >> PAGE_SIZE_1MB_SHIFT]) && (s != PAGE_SIZE_1MB))
      {
         /*
           * split the section into smaller pages
      */
         temp_vaddr = vaddr & ~PAGE_SIZE_1MB_MASK;
         temp_paddr = paddr & ~PAGE_SIZE_1MB_MASK;
      
         get_sd_conf(pt[vaddr >> PAGE_SIZE_1MB_SHIFT], (MMU_PAGE_CONFIG_PTR)&temp_pag);
         SET_DOMAIN(pagc->domain, (MMU_PAGE_CONFIG_PTR)&temp_pag);
         for(i=0; i<PAGE_SIZE_1MB; i+=s)
         {
            mk_pte(temp_vaddr+i, temp_paddr+i, s, &temp_pag, cust);
         }
      }
#if defined(__ARM11_MMU__)
      else if (is_ssd(pt[vaddr >> PAGE_SIZE_1MB_SHIFT]) && (s != PAGE_SIZE_16MB))
      {
         /*
          * split the super section into section
    */
         temp_vaddr = vaddr & ~PAGE_SIZE_16MB_MASK;
         temp_paddr = paddr & ~PAGE_SIZE_16MB_MASK;
      
         get_ssd_conf(pt[vaddr >> PAGE_SIZE_1MB_SHIFT], (MMU_PAGE_CONFIG_PTR)&temp_pag);
         SET_DOMAIN(pagc->domain, (MMU_PAGE_CONFIG_PTR)&temp_pag);
         for(i=0; i<PAGE_SIZE_16MB; i+=PAGE_SIZE_1MB)
         {
            mk_pte(temp_vaddr+i, temp_paddr+i, PAGE_SIZE_1MB, &temp_pag, cust);
         }
         /*
          * split the section into smaller pages
          */
         temp_vaddr = vaddr & ~PAGE_SIZE_1MB_MASK;
         temp_paddr = paddr & ~PAGE_SIZE_1MB_MASK;
         
         for(i=0; i<PAGE_SIZE_1MB; i+=s)
         {
            mk_pte(temp_vaddr+i, temp_paddr+i, s, &temp_pag, cust);
         }
      }
#endif /* __ARM11_MMU__ */
      
      /* make a page table entry */
      if (mk_pte(vaddr, paddr, s, pagc, cust) == -1) {
         return -1;
      }

      /* cotinue to process */
      vaddr += s;
      paddr += s;
      if (s >= len) {
         len = 0;
      } else {
         len = ((len / s) - 1) * s + (len % s);
      }
   }

   return 0;
}

#endif  /* __ARM9_MMU__ || __ARM11_MMU__ */

/*************************************************************************
* FUNCTION
*  mk_tmp_pt
*
* DESCRIPTION
*  This function makes a temporary page table for initialization stage.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  0
*
*************************************************************************/
#if (defined(__ARM9_MMU__) || defined(__ARM11_MMU__) ) && !defined(__FUE__)
kal_uint32 mk_tmp_pt()
{
   kal_uint32 *ptr;
   const kal_uint32 MAP_SIZE = 0x10000000, ONE_MB = 0x100000;
   kal_uint32 addr; 
   kal_int32 i;
   MMU_PAGE_CONFIG_T pagc;

   if(cp15_is_dcache_enabled()) {  
      cp15_clean_dcache();
     cp15_drain_write_buffer();  
      cp15_disable_dcache();  
   }
   if(cp15_is_icache_enabled()) {
      cp15_disable_icache();   
   }
   cp15_disable_mmu();   
   cp15_disable_alignment_fault();
#if defined(__ARM9_MMU__)
   cp15_disable_rom_protect();
#endif /* __ARM9_MMU__ */

   /* use System RAM as the temporary page table */
   ptr = (kal_uint32 *)tmp_page_tbl;
  
#if defined(_SIMULATION)
   if(tmp_page_tbl[0] != 0) 
   {
      /* 
       * NoteXXX: Speed up for Co-SIM.
       *          The page table should be pre-created and loaded into the 
       *          simulation environment first. No need to create it at run
       *          time.
       */
   } else
#endif  /* _SIMULATION */
   {
   /* make page table */
   EXE_RW_CB((MMU_PAGE_CONFIG_PTR)&pagc);
   for (i = 4095; i >= 0; i--) {
      ptr[i] = mk_sd(i << 20, (MMU_PAGE_CONFIG_PTR)&pagc);
   }

   /* configure ITCM as READ_WRITE */
   EXE_RW_TCM((MMU_PAGE_CONFIG_PTR)&pagc);
   addr = custom_get_INTSRAMCODE_Base();
   ptr[addr>>PAGE_SIZE_1MB_SHIFT] = mk_sd(addr, (MMU_PAGE_CONFIG_PTR)&pagc);

   /* configure DTCM as READ_WRITE */
   DEFAULT_RW_TCM((MMU_PAGE_CONFIG_PTR)&pagc);
   addr = custom_get_INTSRAMDATA_Base();
   ptr[addr>>PAGE_SIZE_1MB_SHIFT] = mk_sd(addr, (MMU_PAGE_CONFIG_PTR)&pagc);

   DEFAULT_RW_CB((MMU_PAGE_CONFIG_PTR)&pagc);
   /* map virtual address of the cached region to physical memory address */
   for (addr = CREG_OFFSET, i = (0<<PAGE_SIZE_1MB_SHIFT); i < MAP_SIZE; i += ONE_MB)
   {
      ptr[(MAP2CREGVA(addr + i)) >> PAGE_SIZE_1MB_SHIFT] = mk_sd(i, (MMU_PAGE_CONFIG_PTR)&pagc);
   }
   }

#if defined(IC_BURNIN_TEST) && ( defined(MT6268) || defined(MT6276) || defined(MT6573) || defined(MT6575) || defined(MT6577))
   //Only memory bank 0 can be accessed. set bank 1, 2 and 3 to non-access region
   DEFAULT_RW_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
   SET_DOMAIN(NO_ACCESS,(MMU_PAGE_CONFIG_PTR)&pagc);
   
   for (i = 0x3FF; i >= 0x100; i--) {
      ptr[i] = mk_sd(i << 20, (MMU_PAGE_CONFIG_PTR)&pagc);
   }      
   cp15_write_domain_access(NO_ACCESS, DOMAIN_NO_ACCESS);
#endif /* IC_BURNIN_TEST && MT6268 */
 
   /* set translation table base */
   cp15_write_tbbr((kal_uint32)ptr);
  
   /* set domain 0 access control */
   cp15_write_domain_access(DOMAIN00, DOMAIN_CLIENT);

   /* enable I-Cache for speed-up region init. */
#if defined(__ARM11_MMU__)
   cp15_disable_ap_subpage();
#endif /* __ARM11_MMU__ */
   cp15_invalidate_icache();   
   cp15_enable_icache();  
   /* enable MMU */
   cp15_enable_mmu();

   return 0;
}
#endif  /* (__ARM9_MMU__ || __ARM11_MMU__) && !__FUE__ */


/*************************************************************************
* FUNCTION
*  customized_mmu_init
*
* DESCRIPTION
*  
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  0
*
*************************************************************************/
#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)
kal_uint32 customized_mmu_init(MMU_PAGE_TABLE_INFO_PTR pinfo, MMU_REGION_INFO_T *cust_region)
{
   kal_uint32 ret = 0;
   kal_uint32 *ptr;
   kal_uint32 addr;
   kal_uint32 len = 0;  
   kal_int32 i = 0; 
   MMU_PAGE_CONFIG_T pagc, pagc2;

   if(cp15_is_dcache_enabled()) {  
      cp15_clean_dcache();
      cp15_drain_write_buffer();   
      cp15_disable_dcache();  
   }
   if(cp15_is_icache_enabled()) {
      cp15_disable_icache();   
   }
   cp15_disable_mmu();
   
   for(i = 0; i < 4096; i++) {
      pinfo->cust_page_tbl[i] = 0;
   }   
#if defined(__ARM9_MMU__)
   for(i = 0; i < pinfo->cust_fpt_pool_size/4; i++) {
      pinfo->cust_fpt_pool[i] = 0;
   }
#endif /* __ARM9_MMU__ */

   for(i = 0; i < pinfo->cust_cpt_pool_size/4; i++) {
      pinfo->cust_cpt_pool[i] = 0;
   }

   ptr = (kal_uint32 *)pinfo->cust_page_tbl;
   config_customized_pt(pinfo);

   while (ret == 0 && (cust_region->addr != 0 || cust_region->len != 0)) {
      if (cust_region->len == 0) {
         cust_region++;
         continue;
      }
      addr = cust_region->addr + cust_region->len;
      ROUNDUP_4KB(addr);
      ROUNDDOWN_4KB(cust_region->addr);
      cust_region->len = len = addr - cust_region->addr;
      ret = mk_pt(cust_region->addr, cust_region->addr, len, (MMU_PAGE_CONFIG_PTR)&(cust_region->pagc), CUST_PAGE_TABLE);
      cust_region++;
   }
   if (ret == -1) {
      ASSERT(0);
   }
  
   DEFAULT_REGISTER_RW_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
   DEFAULT_REGISTER_RO_NCNB((MMU_PAGE_CONFIG_PTR)&pagc2);

#define X_REGISTER_REGION_NCNB_CONST(a,b,c,d,e)   if(e==0)\
                                                     mk_pt(((b)>>20)<<20, ((c)>>20)<<20, (((d)+1024*1024-1)>>20)<<20, (MMU_PAGE_CONFIG_PTR)&pagc, CUST_PAGE_TABLE);\
                                                  else\
                                                     mk_pt(((b)>>20)<<20, ((c)>>20)<<20, (((d)+1024*1024-1)>>20)<<20, (MMU_PAGE_CONFIG_PTR)&pagc2, CUST_PAGE_TABLE);
#define X_REGISTER_REGION_NCB_CONST(a,b,c,d,e) 
   #include "reg_region.h"
#undef X_REGISTER_REGION_NCNB_CONST
#undef X_REGISTER_REGION_NCB_CONST

   /* configure registers as READ_WRITE and non-cached but bufferable region */
   DEFAULT_REGISTER_RW_NCB((MMU_PAGE_CONFIG_PTR)&pagc);
   DEFAULT_REGISTER_RO_NCNB((MMU_PAGE_CONFIG_PTR)&pagc2);

#define X_REGISTER_REGION_NCNB_CONST(a,b,c,d,e) 
#define X_REGISTER_REGION_NCB_CONST(a,b,c,d,e)    if(e==0)\
                                                     mk_pt(((b)>>20)<<20, ((c)>>20)<<20, (((d)+1024*1024-1)>>20)<<20, (MMU_PAGE_CONFIG_PTR)&pagc, CUST_PAGE_TABLE);\
                                                  else\
                                                    mk_pt(((b)>>20)<<20, ((c)>>20)<<20, (((d)+1024*1024-1)>>20)<<20, (MMU_PAGE_CONFIG_PTR)&pagc2, CUST_PAGE_TABLE);
   #include "reg_region.h"
#undef X_REGISTER_REGION_NCNB_CONST
#undef X_REGISTER_REGION_NCB_CONST

   /* set translation table base */
   cp15_write_tbbr((kal_uint32)ptr);
  
   /* set domain 0 access control to client access. */
   cp15_write_domain_access(DOMAIN00, DOMAIN_CLIENT);

   /* set domain 1 access control to no access.  */
   cp15_write_domain_access(DOMAIN01, DOMAIN_NO_ACCESS);

   /* set domain 2 access control to manager access.  */
   cp15_write_domain_access(DOMAIN02, DOMAIN_MANAGER);

#if defined(__ARM9_MMU__)
   /* enable ROM protect */
   cp15_enable_rom_protect();
#endif /* __ARM9_MMU__*/

#if !defined(__UNALIGNED_ACCESS_SUPPORT__)
   /* enable alignment fault */
   cp15_enable_alignment_fault();
#endif /* __UNALIGNED_ACCESS__ */

#if defined(__ARM11_MMU__)
   cp15_enable_unaligned_access();
   cp15_enable_branch_prediction();
   cp15_disable_ap_subpage();   
#endif /* __ARM11_MMU__ */

   /* enable I-Cache. */
   cp15_enable_icache();
  
   /* enable D-Cache. */
   cp15_enable_dcache();
  
   /* enable MMU */
   cp15_enable_mmu();

   return 0;
}

#endif  /* __ARM9_MMU__ || __ARM11_MMU__ */



/*************************************************************************
* FUNCTION
*  customized_mmu_deinit
*
* DESCRIPTION
*  
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  0
*
*************************************************************************/

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)

kal_uint32 customized_mmu_deinit(void)
{   
   if(cp15_is_dcache_enabled()) {  
      cp15_clean_dcache();
      cp15_drain_write_buffer();  
      cp15_disable_dcache();  
   }
   if(cp15_is_icache_enabled()) {
      cp15_disable_icache();   
   }
   cp15_disable_mmu();

   return 0;
}

#endif  /* __ARM9_MMU__ || __ARM11_MMU__ */

/*************************************************************************
* FUNCTION
*  LockdownTLB
*
* DESCRIPTION
*  This is used to Lockdown TLB in the preserved area.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
*
* RETURNS
*  0
*
*************************************************************************/

#if defined(__ARM9_MMU__) || defined(__ARM11_MMU__)

kal_uint32 LockdownTLB(kal_uint32 addr)
{
   kal_uint32 saved;

   /* disable IRQ */
   saved = SaveAndSetIRQMask();
   ASSERT(tlb_lockdown_count < MAX_TLB_LOCKDOWN_COUNT);
   cp15_lockdown_TLB_entry(addr);
   tlb_lockdown_count++;
   /* restore IRQ */
   RestoreIRQMask(saved);

   return 0;
}

#endif  /* __ARM9_MMU__ || __ARM11_MMU__ */


/*************************************************************************
* FUNCTION
*  dynamic_switch_mmu_dmpermission
*
* DESCRIPTION
*  This is used to dynamically change a region's pt domain permission.
*  [NOTE] This API is for System Service internal use.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr
*  len
*  dm_permission
*
* RETURNS
*  0
*
*************************************************************************/

#if (defined(__ARM9_MMU__) || defined(__ARM11_MMU__)) && !defined(__FUE__)

kal_uint32 dynamic_switch_mmu_dmpermission(kal_uint32 addr, kal_uint32 len, kal_uint32 dm_permission)
{
   kal_uint32 ret = 0;    
   kal_uint32 config_addr;
   kal_uint32 pg;  
   kal_uint32 irqmask;
   kal_uint32 config_pg_addr;
   MMU_PAGE_CONFIG_T pagc_ext;

   ASSERT(ORIGINAL_ACCESS == dm_permission || NO_ACCESS == dm_permission || FULL_ACCESS == dm_permission);

   SET_DOMAIN(dm_permission, (MMU_PAGE_CONFIG_PTR)&pagc_ext);

   config_addr = addr;
   while(config_addr < addr+len) {
      irqmask = SaveAndSetIRQMask();
    {
         pg = page_tbl[(config_addr>>PAGE_SIZE_1MB_SHIFT)];
         set_fld_domain(pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
         // ATTENTION: Can't use physical address to write because it's configure as RO
         //config_pg_addr = (kal_uint32)(MAP2CREGPA(&page_tbl[(config_addr>>PAGE_SIZE_1MB_SHIFT)]));
         config_pg_addr = (kal_uint32)(&page_tbl[(config_addr>>PAGE_SIZE_1MB_SHIFT)]);
         {
             *(volatile kal_uint32*)config_pg_addr =  pg;
             cp15_clean_dcache_single(config_pg_addr);
         }       
         cp15_drain_write_buffer();
         cp15_invalidate_tlb_single(config_addr);
      }
      RestoreIRQMask(irqmask);
      
      config_addr+=PAGE_SIZE_1MB;
    }

   return ret;
}

kal_int32 mmu_set_page_config(kal_uint32 vaddr, kal_uint32 paddr, kal_uint32 len, MMU_PAGE_CONFIG_PTR pagc)
{
   kal_uint32 ret = 0;    
   kal_uint32 irqmask;
   kal_uint32 *org_pt_pool;
   kal_uint32 isDCacheEnable;

   isDCacheEnable = cp15_is_dcache_enabled();
   irqmask = SaveAndSetIRQMask();
   cp15_disable_mmu();
   
#if defined(__ARM9_MMU__)
   fpt_pool = (kal_uint32 *)MAP2CREGPA(fpt_pool);
#endif /* __ARM9_MMU__ */
   cpt_pool = (kal_uint32 *)MAP2CREGPA(cpt_pool);

   org_pt_pool = cust_page_tbl;
   cust_page_tbl = (kal_uint32 *)MAP2CREGPA(page_tbl);
   
   if(paddr==0xFFFFFFFF)
       mk_pt(vaddr, MAP2CREGPA(vaddr), len, pagc, CUST_PAGE_TABLE);
   else
       mk_pt(vaddr, paddr, len, pagc, CUST_PAGE_TABLE);
   
   cp15_drain_write_buffer();
   cp15_invalidate_tlb();
   
   cust_page_tbl = org_pt_pool;
   
#if defined(__ARM9_MMU__)
   fpt_pool = (kal_uint32 *)MAP2CREGVA(fpt_pool);
#endif /* __ARM9_MMU__ */
   cpt_pool = (kal_uint32 *)MAP2CREGVA(cpt_pool);  

   cp15_enable_mmu();
   RestoreIRQMask(irqmask);
   if(isDCacheEnable)
   {
       cp15_enable_dcache();
   }
   return ret;
}

kal_int32 mmu_get_page_config(kal_uint32 vaddr, kal_uint32 *paddr, kal_uint32 *psize, MMU_PAGE_CONFIG_PTR pagc)
{
#if defined(__ARM11_MMU__)
   kal_uint32 ret = 0;    
   kal_uint32 irqmask;
   kal_uint32 *tbl_ptr;
   kal_uint32 *pt = page_tbl;
   kal_uint32 value;

   if(pagc==NULL) return -1;

   memset(pagc, 0, sizeof(*pagc));

   irqmask = SaveAndSetIRQMask();

   if (is_cptd(pt[vaddr >> PAGE_SIZE_1MB_SHIFT]))
   {
     value = pt[vaddr >> PAGE_SIZE_1MB_SHIFT];
     pagc->domain = (value & ~DOMAIN_MASK)>>DOMAIN_SHIFT;
     pagc->non_secure = (value & ~FIRST_LEVEL_COARSE_PAGE_NON_SECURE_MASK)>>FIRST_LEVEL_COARSE_PAGE_NON_SECURE_SHIFT;

     tbl_ptr = (kal_uint32 *)(value & CPT_BASE_MASK);
     value = tbl_ptr[(vaddr & 0x000ff000) >> PAGE_SIZE_4KB_SHIFT];

     pagc->permission = (value & ~SECOND_LEVEL_LARGE_AP_MASK)>>SECOND_LEVEL_LARGE_AP_SHIFT;
     pagc->cacheable = (value & ~SECOND_LEVEL_LARGE_C_MASK)>>SECOND_LEVEL_LARGE_C_SHIFT;
     pagc->bufferable = (value & ~SECOND_LEVEL_LARGE_B_MASK)>>SECOND_LEVEL_LARGE_B_SHIFT;
     pagc->tex = (value & ~SECOND_LEVEL_LARGE_TEX_MASK)>>SECOND_LEVEL_LARGE_TEX_SHIFT;
     pagc->non_global = (value & ~SECOND_LEVEL_SMALL_NON_GLOBAL_MASK)>>SECOND_LEVEL_SMALL_NON_GLOBAL_SHIFT;
     pagc->shared = (value & ~SECOND_LEVEL_SMALL_SHARED_MASK)>>SECOND_LEVEL_SMALL_SHARED_SHIFT;

     if((value&0x00000002)==0x00000002)
     {
           pagc->exe_never = (value & ~SECOND_LEVEL_SMALL_XN_MASK)>>SECOND_LEVEL_SMALL_XN_SHIFT;
     }
     else
     {
           pagc->exe_never = (value & ~SECOND_LEVEL_LARGE_XN_MASK)>>SECOND_LEVEL_LARGE_XN_SHIFT;
     }

     if(paddr)
     {
         if((value&0x00000002)==0x00000002)
             *paddr = value & 0xfffff000;
     else
             *paddr = value & 0xffff0000;
     }
     if(psize)
     {
       if((value&0x00000002)==0x00000002)
             *psize = PAGE_SIZE_4KB;
       else
             *psize = PAGE_SIZE_64KB;
     }
   }
   else if((pt[vaddr >> PAGE_SIZE_1MB_SHIFT]&0x00000003)==FIRST_LEVEL_SECTION)
   {
     value = pt[vaddr >> PAGE_SIZE_1MB_SHIFT];

     pagc->permission = (value & ~FIRST_LEVEL_SECTION_AP_MASK)>>FIRST_LEVEL_SECTION_AP_SHIFT;
     pagc->domain = (value & ~DOMAIN_MASK)>>DOMAIN_SHIFT;
     pagc->cacheable = (value & ~FIRST_LEVEL_SECTION_C_MASK)>>FIRST_LEVEL_SECTION_C_SHIFT;
     pagc->bufferable = (value & ~FIRST_LEVEL_SECTION_B_MASK)>>FIRST_LEVEL_SECTION_B_SHIFT;
     pagc->tex = (value & ~FIRST_LEVEL_SECTION_TEX_MASK)>>FIRST_LEVEL_SECTION_TEX_SHIFT;
     pagc->exe_never = (value & ~FIRST_LEVEL_SECTION_XN_MASK)>>FIRST_LEVEL_SECTION_XN_SHIFT;
     pagc->non_global = (value & ~FIRST_LEVEL_SECTION_NON_GLOBAL_MASK)>>FIRST_LEVEL_SECTION_NON_GLOBAL_SHIFT;
     pagc->shared = (value & ~FIRST_LEVEL_SECTION_SHARED_MASK)>>FIRST_LEVEL_SECTION_SHARED_SHIFT;
     pagc->non_secure = (value & ~FIRST_LEVEL_SECTION_NON_SECURE_MASK)>>FIRST_LEVEL_SECTION_NON_SECURE_SHIFT;

     if(paddr)
     {
       if(value&0x00040000)
         *paddr = value & 0xff000000;
       else
         *paddr = value & 0xfff00000;
     }
     if(psize)
     {
       if(value&0x00040000)
         *psize = PAGE_SIZE_16MB;
       else
         *psize = PAGE_SIZE_1MB;
     }
   }
   else
   {
       ret = -1;
   }
   RestoreIRQMask(irqmask);

   return ret;
#else
   return -1;
#endif /* __ARM11_MMU__ */
}

#endif  /* (__ARM9_MMU__ || __ARM11_MMU__ ) && !__FUE__ */


/*************************************************************************
* FUNCTION
*  dynamic_switch_mmu_permission
*
* DESCRIPTION
*  This is used to dynamically change a region's pt ap permission. Note this function must use to switch 
*  pt with the same region at initiallize stage.
*  [NOTE] This API is for System Service internal use.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr
*  len
*  permission
*
* RETURNS
*  0
*
*************************************************************************/

#if (defined(__ARM9_MMU__) || defined(__ARM11_MMU__)) && !defined(__FUE__)

kal_uint32 dynamic_switch_mmu_permission(kal_uint32 addr, kal_uint32 len, kal_uint32 permission)
{
   kal_uint32 ret = 0;    
   kal_uint32 config_addr = 0;
   kal_uint32 pg_len = 0;          
   kal_uint32 sec_pg_baddr = 0;      
   kal_uint32 sec_pg_idx = 0;        
   kal_uint32 irqmask = 0;
   kal_int32 i;
   kal_uint32 config_pg_addr, pg, sec_pg;
   MMU_PAGE_CONFIG_T pagc_ext={0};

   ASSERT(PRIV_RO == permission || PRIV_RW == permission);

   SET_PERMISSION(permission, (MMU_PAGE_CONFIG_PTR)&pagc_ext);

   config_addr = addr;
   while(config_addr < addr+len) 
   {
      pg = page_tbl[(config_addr>>PAGE_SIZE_1MB_SHIFT)];

#if defined(__ARM11_MMU__)
      if(is_ssd(pg)) 
      {
         irqmask = SaveAndSetIRQMask();
         {
            set_ssd_ap(pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
            
            // ATTENTION: Can't use physical address to write because it's configure as RO
            //config_pg_addr = MAP2CREGPA(&(page_tbl[((config_addr & ~PAGE_SIZE_16MB_MASK)>>PAGE_SIZE_1MB_SHIFT)]));       
            config_pg_addr = (kal_uint32)&(page_tbl[((config_addr & ~PAGE_SIZE_16MB_MASK)>>PAGE_SIZE_1MB_SHIFT)]);
            {
               for(i=0; i<16; i++)
               {
                  *(volatile kal_uint32*)config_pg_addr =  pg;
                  cp15_clean_dcache_single(config_pg_addr);
          
                  config_pg_addr += 4;   
               }
               cp15_drain_write_buffer(); // also act as Data Synchronization Barrier
               cp15_invalidate_tlb_single(config_addr); // invalidate tlb for config address, not it's pte address
            }
         }
         RestoreIRQMask(irqmask);
        
         pg_len = PAGE_SIZE_16MB;
      } else
#endif /* __ARM11_MMU__ */
      if(is_sd(pg)) 
      {
          irqmask = SaveAndSetIRQMask();
      {
            set_sd_ap(pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
            
            // ATTENTION: Can't use physical address to write because it's configure as RO
            //config_pg_addr = MAP2CREGPA(&(page_tbl[(config_addr>>PAGE_SIZE_1MB_SHIFT)]));
            config_pg_addr = (kal_uint32)&(page_tbl[(config_addr>>PAGE_SIZE_1MB_SHIFT)]);
            {
               *(volatile kal_uint32*)config_pg_addr =  pg;
               cp15_clean_dcache_single(config_pg_addr);
            }
            cp15_drain_write_buffer(); // also act as Data Synchronization Barrier
            cp15_invalidate_tlb_single(config_addr); // invalidate tlb for config address, not it's pte address
         }
         RestoreIRQMask(irqmask);
        
         pg_len = PAGE_SIZE_1MB;
      } 
      else if(is_cptd(pg)) 
      {   
         sec_pg_baddr = cptd_tba(pg);
         sec_pg_idx = get_sec_pg_cp_idx(config_addr);
         
         // ATTENTION: Can't use physical address to write because it's configure as RO
         config_pg_addr = MAP2CREGVA(sec_pg_baddr + sec_pg_idx*4);
         sec_pg = *(volatile kal_uint32*)(config_pg_addr);

         if(is_lpd(sec_pg)) 
         {
            irqmask = SaveAndSetIRQMask();
         {          
               set_lpd_ap(sec_pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
               for(i=0; i<16; i++)
               {
                *(volatile kal_uint32*)(config_pg_addr) =  sec_pg;                
                  cp15_clean_dcache_single(config_pg_addr);
                  
                  config_pg_addr += 4;
               }
               cp15_drain_write_buffer(); // also act as Data Synchronization Barrier
               cp15_invalidate_tlb_single(config_addr); // invalidate tlb for config address, not it's pte address
            }
            RestoreIRQMask(irqmask);
           
            pg_len = PAGE_SIZE_64KB;               
         } 
         else if(is_spd(sec_pg)) 
         {
            irqmask = SaveAndSetIRQMask();
         {          
               set_spd_ap(sec_pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
               {
                 *(volatile kal_uint32*)(config_pg_addr) =  sec_pg;                 
                   cp15_clean_dcache_single(config_pg_addr);
               }
               cp15_drain_write_buffer(); // also act as Data Synchronization Barrier
               cp15_invalidate_tlb_single(config_addr); // invalidate tlb for config address, not it's pte address
            }
            RestoreIRQMask(irqmask);
         
            pg_len = PAGE_SIZE_4KB;              
         } 
         else 
         {
            ASSERT(0);
         }    
      }
#if defined(__ARM9_MMU__)
      else if(is_fptd(pg)) 
      {         
         sec_pg_baddr = cptd_tba(pg);
         sec_pg_idx = get_sec_pg_fp_idx(config_addr);
         
         // ATTENTION: Can't use physical address to write because it's configure as RO
         config_pg_addr = MAP2CREGVA(sec_pg_baddr + sec_pg_idx*4);
         sec_pg = *(volatile kal_uint32*)(config_pg_addr);

         if(is_lpd(sec_pg)) 
         {
            irqmask = SaveAndSetIRQMask();
         {          
               set_lpd_ap(sec_pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
               for(i=0; i<64; i++)
               {
                 *(volatile kal_uint32*)(config_pg_addr) =  sec_pg;                 
                   cp15_clean_dcache_single(config_pg_addr);
                   
                   config_pg_addr += 4;
               }
               cp15_drain_write_buffer(); // also act as Data Synchronization Barrier
               cp15_invalidate_tlb_single(config_addr); // invalidate tlb for config address, not it's pte address
            }
            RestoreIRQMask(irqmask);
          
            pg_len = PAGE_SIZE_64KB;               
         } 
         else if(is_spd(sec_pg)) 
         {
            irqmask = SaveAndSetIRQMask();
         {          
               set_spd_ap(sec_pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
               for(i=0; i<4; i++) 
               {
                 *(volatile kal_uint32*)(config_pg_addr) =  sec_pg;                 
                   cp15_drain_write_buffer();
                   cp15_invalidate_tlb_single(config_pg_addr);
                   
                   config_pg_addr += 4;
               }
               cp15_drain_write_buffer(); // also act as Data Synchronization Barrier
               cp15_invalidate_tlb_single(config_addr); // invalidate tlb for config address, not it's pte address
            }
            RestoreIRQMask(irqmask);
         
            pg_len = PAGE_SIZE_4KB;              
         } 
         else if(is_tpd(sec_pg)) 
         {
            irqmask = SaveAndSetIRQMask();
            {         
               set_tpd_ap(sec_pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
               {
                 *(volatile kal_uint32*)(config_pg_addr) =  sec_pg;                 
                   cp15_clean_dcache_single(config_pg_addr);
               }
               cp15_drain_write_buffer(); // also act as Data Synchronization Barrier
               cp15_invalidate_tlb_single(config_addr); // invalidate tlb for config address, not it's pte address
            }
            RestoreIRQMask(irqmask);
                       
            pg_len = PAGE_SIZE_1KB;              
         } 
         else 
         {
            ASSERT(0);
         }    
          
      }
#endif /* __ARM9_MMU__ */
      else 
      {
         ASSERT(0);
      }                 
      config_addr+=pg_len;
    }

   return ret;
}

#endif  /* (__ARM9_MMU__ || __ARM11_MMU__) && !__FUE__ */



/*************************************************************************
* FUNCTION
*  dynamic_switch_mmu_permission_cb
*
* DESCRIPTION
*  This is used to dynamically change a region's pt ap permission including cacheable/bufferable setting. 
*  Note this function must use to switch pt with the same region at initiallize stage.
*  [NOTE] This API is for System Service internal use.
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr
*  len
*  permission
*
* RETURNS
*  0
*
*************************************************************************/

#if (defined(__ARM9_MMU__) || defined(__ARM11_MMU__)) && !defined(__FUE__)

kal_uint32 dynamic_switch_mmu_permission_cb(kal_uint32 addr, kal_uint32 len, kal_uint32 permission, kal_uint32 c)
{
   kal_uint32 ret = 0;    
   kal_uint32 config_addr = 0;
   kal_uint32 pg_len = 0;          
   kal_uint32 sec_pg_baddr = 0;      
   kal_uint32 sec_pg_idx = 0;        
   kal_uint32 irqmask = 0;
   kal_int32 i;
   kal_uint32 config_pg_addr, pg, sec_pg;
   MMU_PAGE_CONFIG_T pagc_ext={0};

   ASSERT(PRIV_RO == permission || PRIV_RW == permission);
   ASSERT(CACHEABLE_BUFFERABLE == c || NONCACHEABLE_BUFFERABLE == c || CACHEABLE_NONBUFFERABLE == c || NONCACHEABLE_NONBUFFERABLE == c);

   SET_PERMISSION(permission, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
   SET_CACHEABLE(c, (MMU_PAGE_CONFIG_PTR)&pagc_ext);

   config_addr = addr;
   while(config_addr < addr+len) 
   {
      pg = page_tbl[(config_addr>>PAGE_SIZE_1MB_SHIFT)];

#if defined(__ARM11_MMU__)
      if(is_ssd(pg)) 
      {
         irqmask = SaveAndSetIRQMask();
         {
            set_ssd_ap(pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
            set_ssd_cb(pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
            
            // ATTENTION: Can't use physical address to write because it's configure as RO
            //config_pg_addr = MAP2CREGPA(&(page_tbl[((config_addr & ~PAGE_SIZE_16MB_MASK)>>PAGE_SIZE_1MB_SHIFT)]));
            config_pg_addr = (kal_uint32)&(page_tbl[((config_addr & ~PAGE_SIZE_16MB_MASK)>>PAGE_SIZE_1MB_SHIFT)]);
            {
               for(i=0; i<16; i++)
               {
                  *(volatile kal_uint32*)config_pg_addr =  pg;
                  cp15_clean_dcache_single(config_pg_addr);
          
                  config_pg_addr += 4;          
               }
               cp15_drain_write_buffer(); // also act as Data Synchronization Barrier
               cp15_invalidate_tlb_single(config_addr); // invalidate tlb for config address, not it's pte address
            }
         }
         RestoreIRQMask(irqmask);
        
         pg_len = PAGE_SIZE_16MB;
      } else
#endif /* __ARM11_MMU__ */
      if(is_sd(pg)) 
      {
         irqmask = SaveAndSetIRQMask();
         {
            set_sd_ap(pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
            set_sd_cb(pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
            
            // ATTENTION: Can't use physical address to write because it's configure as RO
            //config_pg_addr = MAP2CREGPA(&(page_tbl[(config_addr>>PAGE_SIZE_1MB_SHIFT)]));
            config_pg_addr = (kal_uint32)&(page_tbl[(config_addr>>PAGE_SIZE_1MB_SHIFT)]);
            {
               *(volatile kal_uint32*)config_pg_addr =  pg;
               cp15_clean_dcache_single(config_pg_addr);
            }
            cp15_drain_write_buffer(); // also act as Data Synchronization Barrier
            cp15_invalidate_tlb_single(config_addr); // invalidate tlb for config address, not it's pte address
         }
         RestoreIRQMask(irqmask);
        
         pg_len = PAGE_SIZE_1MB;          
      } 
      else if(is_cptd(pg)) 
      {  
         sec_pg_baddr = cptd_tba(pg);
         sec_pg_idx = get_sec_pg_cp_idx(config_addr);
         
         // ATTENTION: Can't use physical address to write because it's configure as RO
         config_pg_addr = MAP2CREGVA(sec_pg_baddr + sec_pg_idx*4);
         sec_pg = *(volatile kal_uint32*)(config_pg_addr);

         if(is_lpd(sec_pg)) 
         {
            irqmask = SaveAndSetIRQMask();
            {                                     
               set_lpd_ap(sec_pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
               set_lpd_cb(sec_pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
               for(i=0; i < 16; i++) 
               {
                  *(volatile kal_uint32*)(config_pg_addr) =  sec_pg;                
                  cp15_clean_dcache_single(config_pg_addr);
          
              config_pg_addr += 4;
               }
               cp15_drain_write_buffer(); // also act as Data Synchronization Barrier
               cp15_invalidate_tlb_single(config_addr); // invalidate tlb for config address, not it's pte address
            }
            RestoreIRQMask(irqmask);
           
            pg_len = PAGE_SIZE_64KB;               
         } 
         else if(is_spd(sec_pg)) 
         {
            irqmask = SaveAndSetIRQMask();
            {         
               set_spd_ap(sec_pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
               set_spd_cb(sec_pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
               {
                  *(volatile kal_uint32*)(config_pg_addr) =  sec_pg;                
                  cp15_clean_dcache_single(config_pg_addr);
               }
               cp15_drain_write_buffer(); // also act as Data Synchronization Barrier
               cp15_invalidate_tlb_single(config_addr); // invalidate tlb for config address, not it's pte address
            }
            RestoreIRQMask(irqmask);
         
            pg_len = PAGE_SIZE_4KB;              
         } 
         else 
         {
            ASSERT(0);
         }              
      }
#if defined(__ARM9_MMU__)
      else if(is_fptd(pg)) 
      {         
         sec_pg_baddr = cptd_tba(pg);
         sec_pg_idx = get_sec_pg_fp_idx(config_addr);
         
         // ATTENTION: Can't use physical address to write because it's configure as RO
         config_pg_addr = MAP2CREGVA(sec_pg_baddr + sec_pg_idx*4);
         sec_pg = *(volatile kal_uint32*)(config_pg_addr);

         if(is_lpd(sec_pg)) 
         {
            irqmask = SaveAndSetIRQMask();
            {         
               set_lpd_ap(sec_pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
               set_lpd_cb(sec_pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
               for(i=0; i<64; i++)
               {
                  *(volatile kal_uint32*)(config_pg_addr) =  sec_pg;                
                  cp15_clean_dcache_single(config_pg_addr);
                   
                  config_pg_addr += 4;
               }
               cp15_drain_write_buffer(); // also act as Data Synchronization Barrier
               cp15_invalidate_tlb_single(config_addr); // invalidate tlb for config address, not it's pte address
            }
            RestoreIRQMask(irqmask);
          
            pg_len = PAGE_SIZE_64KB;               
         } 
         else if(is_spd(sec_pg)) 
         {
            irqmask = SaveAndSetIRQMask();
            {         
               set_spd_ap(sec_pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
               set_spd_cb(sec_pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
               config_pg_addr = sec_pg_baddr + sec_pg_idx*4;                                 
               for(i=0; i<4; i++) 
               {
                  *(volatile kal_uint32*)(config_pg_addr) =  sec_pg;                
                  cp15_clean_dcache_single(config_pg_addr);
                  
                  config_pg_addr += 4;
               }
               cp15_drain_write_buffer(); // also act as Data Synchronization Barrier
               cp15_invalidate_tlb_single(config_addr); // invalidate tlb for config address, not it's pte address
            }
            RestoreIRQMask(irqmask);
         
            pg_len = PAGE_SIZE_4KB;              
         } 
         else if(is_tpd(sec_pg)) 
         {
            irqmask = SaveAndSetIRQMask();
            {         
               set_tpd_ap(sec_pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
               set_tpd_cb(sec_pg, (MMU_PAGE_CONFIG_PTR)&pagc_ext);
               {
                *(volatile kal_uint32*)(config_pg_addr) =  sec_pg;                
                  cp15_clean_dcache_single(config_pg_addr);
               }
               cp15_drain_write_buffer(); // also act as Data Synchronization Barrier
               cp15_invalidate_tlb_single(config_addr); // invalidate tlb for config address, not it's pte address
            }
            RestoreIRQMask(irqmask);
                       
            pg_len = PAGE_SIZE_1KB;              
         } 
         else 
         {
            ASSERT(0);
         }    
          
      }
#endif /* __ARM9_MMU__ */
      else 
      {
         ASSERT(0);
      }                 
      config_addr+=pg_len;
    }

   return ret;
}

#endif  /* (__ARM9_MMU__ || __ARM11_MMU__) && !__FUE__ */


/*************************************************************************
* FUNCTION
*  MMU_Init
*
* DESCRIPTION
*  
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr
*  len
*  permission
*
* RETURNS
*  0
*
*************************************************************************/

#if (defined(__ARM9_MMU__) || defined(__ARM11_MMU__) ) && !defined(__FUE__)

kal_uint32 MMU_Init(void)
{
   EXTSRAM_REGION_INFO_T *regionp;
   kal_uint32 ret, addr, len;
   kal_uint32 itcm_base_addr, dtcm_base_addr;
   MMU_PAGE_CONFIG_T pagc, pagc2;
   kal_uint32 rom_start_addr = custom_get_1st_ROM_ROMBase();
   kal_uint32 rom_len = custom_get_1st_ROM_ROMLength();

#if defined(__FOTA_DM__) && !defined(_NAND_FLASH_BOOTING_) && !defined(__EMMC_BOOTING__)
   /* [TEMP] SHK: Query FOTA's update page space, which adjacent to FAT on current design. Kirk and Claudia will co-work to 
                          provide me another query function on W08.37. */
   kal_uint32 fat_start_addr = (FOTA_GetPackageStorageBase() | INT_RetrieveFlashBaseAddr());
   kal_uint32 fat_len = (FOTA_GetPackageStorageSize() + custom_get_fat_len());
#else /* !__FOTA_DM__ && !_NAND_FLASH_BOOTING_ && !__EMMC_BOOTING__ */
   kal_uint32 fat_start_addr = custom_get_FAT_StartAddr();
   kal_uint32 fat_len = custom_get_FAT_Length();
#endif /* __FOTA_DM__ && !_NAND_FLASH_BOOTING_ && !__EMMC_BOOTING__ */
   
   kal_uint32 ram_start_addr = custom_get_1st_ROM_RAMBase();

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
   #if defined(__DSP_FCORE4__)
   kal_uint32 sec_rom_start_addr = custom_get_DSP_ROM_ROMBase();
   #else /* __SV5_DEV__ */
   kal_uint32 sec_rom_start_addr = custom_get_2nd_ROM_ROMBase();
   #endif /* __SV5_DEV__*/
   kal_uint32 sec_rom_end_addr = custom_get_2nd_ROM_LoadEnd();
#endif  /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */


   /*
    * Create page tables.
    */

   /* make the EXTSRAM info table */
   custom_mk_ram_info();
   itcm_base_addr = custom_get_INTSRAMCODE_Base();
   dtcm_base_addr = custom_get_INTSRAMDATA_Base();

   /* get fpt pool */
#if defined(__ARM9_MMU__)
   custom_query_fpt_pool(&fpt_pool, &fpt_pool_size);
#if !defined(IC_BURNIN_TEST)
   fpt_pool = (kal_uint32 *)MAP2CREGPA(fpt_pool);
#endif
#endif /* __ARM9_MMU__ */

   /* get cpt pool */
   custom_query_cpt_pool(&cpt_pool, &cpt_pool_size);
#if !defined(IC_BURNIN_TEST)
   cpt_pool = (kal_uint32 *)MAP2CREGPA(cpt_pool);
#endif

#if defined(_SIMULATION)
   if (page_tbl[0] != 0) 
   {
      /* 
       * NoteXXX: Speed up for Co-SIM.
       *          The page table should be pre-created and loaded into the 
       *          simulation environment first. No need to create it at run
       *          time.
       */
   } else
#endif   /* _SIMULATION */
   {
   /* make the default page table */
   mk_def_pt(page_tbl);

   /*
    * NoteXXX: We will use 1MB section, 64KB large page, 4KB small page, 
    *          or 1KB tiny page to manage one memory space.
    *
    *          Page table usage should be predictable.
    *          i.e., how many fine page tables and how many coarse page tables
    *
    *          There is one guideline when configuring page tables:
    *              not allow to abandon configured page tables
    *          If we have already used one 64KB large page (one fine page table is allocated and set), 
    *          we cannot use 1KB tiny page in the same 1MB memory space.
    *          If we have already used one 4KB small page (one fine page table is allocated and set), 
    *          we cannot use 1KB tiny page in the same 1MB memory space.
    *
    *          If the page table is located in the cached region, we should not modify it after
    *          enabling cache. This is because any request of page-table walk from MMU is always 
    *          submitted to the AHB, not to CACHE/TCM.
    *          
    */

   ret = 0;
   do {

      /*************************
       * RO-Code/Data Config
       *************************/

#if defined(MT6276) || defined(MT6573) || defined(MT6575) || defined(MT6577)
      /* configure Vecotr Table as READ_ONLY and cached region */
      addr = 0x100;
      ROUNDUP_4KB(addr);
      len = addr;

      DEFAULT_RO_CB((MMU_PAGE_CONFIG_PTR)&pagc);
      ret = mk_pt(0, 0, len, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);     
      if (ret == -1) {
         break;
      }
#endif /* MT6276 */

      /********************************************************************
       * NoteXXX:
       * The reason of +0x4 at rom end address is due to ADS compiler defect.
       * For more detailed information, you could kindly consult Shock.
       ********************************************************************/
    
      /* configure ROM as READ_ONLY and cached region */
      addr = rom_start_addr + rom_len + 0x4;
      ROUNDUP_4KB(addr);
      len = addr - rom_start_addr;

      DEFAULT_RO_CB((MMU_PAGE_CONFIG_PTR)&pagc);
      ret = mk_pt(rom_start_addr, rom_start_addr, len, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);     
      if (ret == -1) {
         break;
      }

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
      /* configure SECONDARY ROM as READ_ONLY and cached region */
      addr = sec_rom_end_addr + 0x4 + MAX_NAND_DATA_SIZE;
      ROUNDUP_4KB(addr);
      len = addr;
      addr = sec_rom_start_addr;
      ROUNDDOWN_4KB(addr);
      len = len - addr;     

      DEFAULT_RO_CB((MMU_PAGE_CONFIG_PTR)&pagc);
      ret = mk_pt(addr, addr, len, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
      if (ret == -1) {
         break;
      }
#endif  /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */


      /*************************
       * Ext.Ram Config
       *************************/

      /* configure cached RAM as READ_WRITE and cached region */
      custom_query_cached_extsram_region(&regionp);
      while (ret == 0 && (regionp->addr != 0 || regionp->len != 0)) {
         if (regionp->len == 0) {
            regionp++;
            continue;
         }
         addr = regionp->addr + regionp->len + 0x4;
         ROUNDUP_4KB(addr);
         ROUNDDOWN_4KB(regionp->addr);
         regionp->len = len = addr - regionp->addr;

         DEFAULT_RW_CB((MMU_PAGE_CONFIG_PTR)&pagc);
         ret = mk_pt(regionp->addr, MAP2CREGPA(regionp->addr), len, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
         if (ret != -1) {
            /* configure the mapped physical addresses as READ_ONLY and non-cached region */

            DEFAULT_RO_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
            ret = mk_pt(MAP2CREGPA(regionp->addr), MAP2CREGPA(regionp->addr), len, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
         }
         regionp++;
      }
      if (ret == -1) {
         break;
      }


      /* configure cached RAM CODE as READ and cached region */
      custom_query_cached_extsram_code_region(&regionp);
      while (ret == 0 && (regionp->addr != 0 || regionp->len != 0)) {
         if (regionp->len == 0) {
            regionp++;
            continue;
         }
         addr = regionp->addr + regionp->len;
         ROUNDUP_4KB(addr);
         ROUNDDOWN_4KB(regionp->addr);
         regionp->len = len = addr - regionp->addr;

         DEFAULT_RO_CB((MMU_PAGE_CONFIG_PTR)&pagc);
         ret = mk_pt(regionp->addr, MAP2CREGPA(regionp->addr), len, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
         if (ret != -1) {
            /* configure the mapped physical addresses as READ_ONLY and non-cached region */

            DEFAULT_RO_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
            ret = mk_pt(MAP2CREGPA(regionp->addr), MAP2CREGPA(regionp->addr), len, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
         }
         regionp++;
      }
      if (ret == -1) {
         break;
      }


      /* config DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE region as NC. */
      custom_query_dynamic_cached_extsram_default_nc_region(&regionp);
      while (ret == 0 && (regionp->addr != 0 || regionp->len != 0)) {
         if (regionp->len == 0) {
            regionp++;
            continue;
         }
         addr = regionp->addr + regionp->len + 0x4;
         ROUNDUP_4KB(addr);
         ROUNDDOWN_4KB(regionp->addr);
         regionp->len = len = addr - regionp->addr;

         DEFAULT_RW_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
#if !defined(MT6573) && defined(__ARM11_MMU__) && !defined(__ARM11_DISABLE_SO_MIGRATION__)
         pagc.tex = 1;
#endif /* MT6276 && !__ARM11_DISABLE_SO_MIGRATION__ */
         ret = mk_pt(regionp->addr, regionp->addr, len, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
         if (ret != -1)
         {
            /* configure the mapped physical addresses as READ_WRITE and cached region */

            DEFAULT_RW_CB((MMU_PAGE_CONFIG_PTR)&pagc);
            ret = mk_pt(MAP2CREGVA(regionp->addr), regionp->addr, len, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);     
         }
       
         regionp++;
      }
      if (ret == -1) {
         break;
      }

      /* config DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE region as C. */
      custom_query_dynamic_cached_extsram_default_c_region(&regionp);
      while (ret == 0 && (regionp->addr != 0 || regionp->len != 0)) {
         if (regionp->len == 0) {
            regionp++;
            continue;
         }
         addr = regionp->addr + regionp->len + 0x4;
         ROUNDUP_4KB(addr);
         ROUNDDOWN_4KB(regionp->addr);
         regionp->len = len = addr - regionp->addr;

         DEFAULT_RW_CB((MMU_PAGE_CONFIG_PTR)&pagc);
         ret = mk_pt(regionp->addr, MAP2CREGPA(regionp->addr), len, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
         if (ret != -1)
         {
            /* configure the mapped physical addresses as READ_WRITE and cached region */

            DEFAULT_RW_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
#if !defined(MT6573) && defined(__ARM11_MMU__) && !defined(__ARM11_DISABLE_SO_MIGRATION__)
            pagc.tex = 1;
#endif /* MT6276 && !__ARM11_DISABLE_SO_MIGRATION__ */
            ret = mk_pt(MAP2CREGPA(regionp->addr), MAP2CREGPA(regionp->addr), len, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);     
         }
       
         regionp++;
      }
      if (ret == -1) {
         break;
      }

      /* configure non-cached RAM as READ_WRITE and non-cached region */
      custom_query_noncached_extsram_region(&regionp);
      while (ret == 0 && (regionp->addr != 0 || regionp->len != 0)) {
         if (regionp->len == 0) {
            regionp++;
            continue;
         }
         addr = regionp->addr + regionp->len + 0x4;
         ROUNDUP_4KB(addr);
         ROUNDDOWN_4KB(regionp->addr);
         regionp->len = len = addr - regionp->addr;

         DEFAULT_RW_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
#if !defined(MT6573) && defined(__ARM11_MMU__) && !defined(__ARM11_DISABLE_SO_MIGRATION__)
         pagc.tex = 1;
#endif /* MT6276 && !__ARM11_DISABLE_SO_MIGRATION__ */
        ret = mk_pt(regionp->addr, regionp->addr, len, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
         regionp++;
      }
      if (ret == -1) {
         break;
      }

      /* configure non-cached code as READ_ONLY and non-cached region */
      custom_query_noncached_extsram_ro_region(&regionp);
      while (ret == 0 && (regionp->addr != 0 || regionp->len != 0)) {
         if (regionp->len == 0) {
            regionp++;
            continue;
         }
         addr = regionp->addr + regionp->len;
         ROUNDUP_4KB(addr);
         ROUNDDOWN_4KB(regionp->addr);
         regionp->len = len = addr - regionp->addr;

         DEFAULT_RO_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
#if !defined(MT6573) && defined(__ARM11_MMU__) && !defined(__ARM11_DISABLE_SO_MIGRATION__)
         pagc.tex = 1;
#endif /* MT6276 && !__ARM11_DISABLE_SO_MIGRATION__ */
        ret = mk_pt(regionp->addr, regionp->addr, len, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
         regionp++;
      }
      if (ret == -1) {
         break;
      }

      /*
       * Note:  CCT used in the factory mode may also use the remaining memory space as buffer. 
       */
         custom_get_MaxAvailableMemorySegment((kal_uint32 **)&addr, &len);

         DEFAULT_RW_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
#if !defined(MT6573) && defined(__ARM11_MMU__) && !defined(__ARM11_DISABLE_SO_MIGRATION__)
         pagc.tex = 1;
#endif /* MT6276 && !__ARM11_DISABLE_SO_MIGRATION__ */
         ret = mk_pt(addr, addr, len, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);             

      if (ret == -1) {
         break;
      }


      /*************************
       * Multiple ROM Support Config (including load region of some bins)
       *************************/

      custom_query_multi_rom_load_region(&regionp);
      while (ret == 0 && (regionp->addr != 0 || regionp->len != 0)) {
         if (regionp->len == 0) {
            regionp++;
            continue;
         }
         addr = regionp->addr + regionp->len + 4;
         ROUNDUP_4KB(addr);
         ROUNDDOWN_4KB(regionp->addr);
         regionp->len = len = addr - regionp->addr;

         DEFAULT_RO_CB((MMU_PAGE_CONFIG_PTR)&pagc);
        ret = mk_pt(regionp->addr, regionp->addr, len, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
         regionp++;
      }
      if (ret == -1) {
         break;
      }     
   } while (0);


   /*************************
    * Page Table Creation Fault Handling
    *************************/

   if (ret == -1) {
      /* remake page table due to failure */

      /* configure ROM as READ_ONLY and cached region */

      DEFAULT_RO_CB((MMU_PAGE_CONFIG_PTR)&pagc);
      mk_pt(rom_start_addr, rom_start_addr, fat_start_addr - rom_start_addr, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);

      /* configure RAM as READ_WRITE and non-cached region */
      custom_get_EXTSRAM_size(&len);

      DEFAULT_RW_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
      mk_pt(ram_start_addr, ram_start_addr, len, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
      mk_pt(ram_start_addr | CREG_OFFSET, ram_start_addr, len, &pagc, DEF_PAGE_TABLE);

      /* configure ITCM DTCM as READ_WRITE and non-cached region */
      DEFAULT_RW_TCM((MMU_PAGE_CONFIG_PTR)&pagc);
      ret = mk_pt(itcm_base_addr, itcm_base_addr, 0x100000, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);    
   }


   /*************************
    * FAT Config
    *************************/

#if !defined(_NAND_FLASH_BOOTING_) && !defined(__FS_SYSDRV_ON_NAND__) && !defined(__EMMC_BOOTING__)
   /* configure FAT as READ_WRITE and non-cached region */
   addr = fat_start_addr + fat_len + 0x4;
   ROUNDUP_4KB(addr);
   ROUNDDOWN_4KB(fat_start_addr);
   fat_len = addr - fat_start_addr;
   /*Basic load test/SLT  for SF/NOR flash*/
#if (defined(__MAUI_BASIC__) && defined( __NOR_FLASH_HARDWARE_TEST__))  || defined(IC_MODULE_TEST) || defined(IC_BURNIN_TEST) 
   DEFAULT_RW_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
   mk_pt(fat_start_addr-0x1000, fat_start_addr-0x1000, fat_len+0x1000, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
#else
   DEFAULT_RW_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
   mk_pt(fat_start_addr, fat_start_addr, fat_len, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
#endif //defined(__MAUI_BASIC__) && defined( __NOR_FLASH_HARDWARE_TEST__)
#endif  /* ! _NAND_FLASH_BOOTING_ && !__FS_SYSDRV_ON_NAND__ && !__EMMC_BOOTING__ */


   /*************************
    * Int.Ram Config
    *************************/

   /* always configure ITCM and DTCM regions as 1MB regions since TCM regions will be locked in the MMU TLB */
   /* configure ITCM as READ_ONLY and non-cached region */

         
#if defined(IC_BURNIN_TEST) || defined(IC_MODULE_TEST)
   /* need to write ITCM in IC btmt */
   EXE_RW_TCM((MMU_PAGE_CONFIG_PTR)&pagc);
   ret = mk_pt(itcm_base_addr, itcm_base_addr, 0x100000, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);   
#else
   DEFAULT_RO_TCM((MMU_PAGE_CONFIG_PTR)&pagc);
   ret = mk_pt(itcm_base_addr, itcm_base_addr, 0x100000, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);   
#endif
   /* configure DTCM as READ_WRITE and non-cached region */
   DEFAULT_RW_TCM((MMU_PAGE_CONFIG_PTR)&pagc);
   ret = mk_pt(dtcm_base_addr, dtcm_base_addr, 0x100000, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);   


   /*************************
    * Sys.Ram Config
    *************************/

   /* configure System RAM as READ_WRITE and non-cached region and configure the mapped physical addresses as READ_WRITE and cached region. */
   /* don't need to care the exact size because system RAM is for multimedia function only */
   if(INT_QuerySystemRAMInfo(&addr, &len)!=-1)
   {
   DEFAULT_RW_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
#if !defined(MT6573) && defined(__ARM11_MMU__) && !defined(__ARM11_DISABLE_SO_MIGRATION__)
   pagc.tex = 1;
#endif /* MT6276 && !__ARM11_DISABLE_SO_MIGRATION__ */
   ret = mk_pt(addr, addr, 0x100000, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
         
   DEFAULT_RW_CB((MMU_PAGE_CONFIG_PTR)&pagc);
   ret = mk_pt(MAP2CREGVA_SYS(addr), addr, 0x100000, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);     
   }

#if defined(MT6573) || defined(MT6575) || defined(MT6577)
   /* configure CCCI FS shared buffer as READ_WRITE */
   DEFAULT_RW_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
   ret = mk_pt(0x02000000, 0x02000000, 0x100000, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);

#if defined(MT6573)
   /* configure L2ITCM as READ_WRITE and non-cached region */
   DEFAULT_RO_CB((MMU_PAGE_CONFIG_PTR)&pagc);
   ret = mk_pt(0x58000000, 0x58000000, 0x12000, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
#elif defined(MT6575) || defined(MT6577)
   /* configure L2ITCM as READ_WRITE and non-cached region */
   DEFAULT_RO_CB((MMU_PAGE_CONFIG_PTR)&pagc);
   ret = mk_pt(0x58000000, 0x58000000, 0x15000, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
#endif /* MT6573 */
   
   /* configure L2DTCM as READ_WRITE and non-cached region */
   DEFAULT_RW_CB((MMU_PAGE_CONFIG_PTR)&pagc);
   ret = mk_pt(0x58012000, 0x58012000, 0x6000, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
   
#if defined(MT6573)
   /* configure FLEXL2 as READ_WRITE */
   DEFAULT_RW_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
   ret = mk_pt(0x90000000, 0x90000000, 0x20000, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
   
   /* configure MM SRAM as READ_WRITE */
   DEFAULT_RW_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
   ret = mk_pt(0x40000000, 0x40000000, 0x44000, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
#endif /* MT6573 */
   
#if defined(__SMARTPHONE_GPRS_ONLY__)
   /* configure FCore execution view as READ_ONLY and NCNB region */
   DEFAULT_RO_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
   ret = mk_pt(0x00700000, 0x00700000, 0x300000, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
#else /* __SMARTPHONE_GPRS_ONLY__ */
#if defined(MT6573) && defined(__UMTS_TDD128_MODE__)
   /* configure FCore execution view as READ_ONLY and NCNB region */
   DEFAULT_RO_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
   ret = mk_pt(0x00f00000, 0x00f00000, 0x300000, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
#else
   /* configure FCore execution view as READ_ONLY and NCNB region */
   DEFAULT_RO_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
   ret = mk_pt(0x01300000, 0x01300000, 0x300000, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
#endif /* __UMTS_TDD128_MODE__ */
#endif /* __SMARTPHONE_GPRS_ONLY__ */

   /* configure FCore FlexL2 as READ_ONLY and cached region */
   DEFAULT_RO_CB((MMU_PAGE_CONFIG_PTR)&pagc);
   ret = mk_pt(0x08000000, 0xF0000000, 0x10000, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
   /* configure FCore L1 as READ_ONLY and cached region */
   DEFAULT_RO_CB((MMU_PAGE_CONFIG_PTR)&pagc);
   ret = mk_pt(0x75000000, 0xE0000000, 0x400000, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
#endif /* MT6573 */

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
    DEFAULT_RO_CB((MMU_PAGE_CONFIG_PTR)&pagc);
    ret = mk_pt(custom_get_SINGLEBANKCODE_and_VectorTable_Base(), custom_get_SINGLEBANKCODE_and_VectorTable_Base(), custom_get_SINGLEBANKCODE_End()-custom_get_SINGLEBANKCODE_and_VectorTable_Base(), (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
#endif  /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

   /*************************
    * APB Config
    *************************/

   /* configure registers as READ_WRITE and non-cached and non-bufferable region */
   DEFAULT_REGISTER_RW_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
   DEFAULT_REGISTER_RO_NCNB((MMU_PAGE_CONFIG_PTR)&pagc2);

#define X_REGISTER_REGION_NCNB_CONST(a,b,c,d,e)   if(e==0)\
                                                     mk_pt(((b)>>12)<<12, ((c)>>12)<<12, (((d)+(1<<12)-1)>>12)<<12, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);\
                                                  else\
                                                     mk_pt(((b)>>12)<<12, ((c)>>12)<<12, (((d)+(1<<12)-1)>>12)<<12, (MMU_PAGE_CONFIG_PTR)&pagc2, DEF_PAGE_TABLE);
#define X_REGISTER_REGION_NCB_CONST(a,b,c,d,e) 
   #include "reg_region.h"
#undef X_REGISTER_REGION_NCNB_CONST
#undef X_REGISTER_REGION_NCB_CONST

   /* configure registers as READ_WRITE and non-cached but bufferable region */
   DEFAULT_REGISTER_RW_NCB((MMU_PAGE_CONFIG_PTR)&pagc);
   DEFAULT_REGISTER_RO_NCB((MMU_PAGE_CONFIG_PTR)&pagc2);

#define X_REGISTER_REGION_NCNB_CONST(a,b,c,d,e) 
#define X_REGISTER_REGION_NCB_CONST(a,b,c,d,e)    if(e==0)\
                                                     mk_pt(((b)>>12)<<12, ((c)>>12)<<12, (((d)+(1<<12)-1)>>12)<<12, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);\
                                                  else\
                                                     mk_pt(((b)>>12)<<12, ((c)>>12)<<12, (((d)+(1<<12)-1)>>12)<<12, (MMU_PAGE_CONFIG_PTR)&pagc2, DEF_PAGE_TABLE);
   #include "reg_region.h"
#undef X_REGISTER_REGION_NCNB_CONST
#undef X_REGISTER_REGION_NCB_CONST


   /*************************
    * Other Exception Config on MAUI
    *************************/

   DEFAULT_RW_NCNB((MMU_PAGE_CONFIG_PTR)&pagc);
   /* for DCM test. hardcode here since L1 always test this addr.  */
   // This is legacy code for EMI dummy read (in order to make sure EMI is wake up)
   // Need to confirm with DCM owner about his EMI_DUMMY_READ macro
   //mk_pt(0x28000000, 0x28000000, 0x100000, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);

#if defined(IC_BURNIN_TEST) || defined(IC_MODULE_TEST)
#if defined(MT6236) || defined(MT6236B)
   // SYSROM test
   mk_pt(0x48000000, 0x48000000, 0x100000, (MMU_PAGE_CONFIG_PTR)&pagc, DEF_PAGE_TABLE);
#endif /* defined(MT6236) || defined(MT6236B) */
#endif

   }

   /* SHK: We must flush write buffer here to prevent previously pt write to cache only before enabling MMU. */
   /* Enable DCache.  Inv D-Cache in advance since we might have enabled d-cache with dirty at customized_mmu_init in another addr space (ex: FOTA). */
   if(cp15_is_dcache_enabled()) {  
      cp15_clean_dcache();
      cp15_drain_write_buffer();  
      cp15_invalidate_dcache();    
   }

   /*
    * Enable ICache, DCache, and MMU.
    */

   /* disable MMU temporarily */
   cp15_disable_mmu();

   /* set domain 0 access control to client access. */
   cp15_write_domain_access(DOMAIN00, DOMAIN_CLIENT);

   /* set domain 1 access control to no access.  */
   cp15_write_domain_access(DOMAIN01, DOMAIN_NO_ACCESS);

   /* set domain 2 access control to manager access.  */
   cp15_write_domain_access(DOMAIN02, DOMAIN_MANAGER);
  
#if defined(__ARM9_MMU__)
   /* enable ROM protect */
   cp15_enable_rom_protect();
#endif /* __ARM9_MMU__ */

#if !defined(__UNALIGNED_ACCESS_SUPPORT__)
   /* enable alignment fault */
   cp15_enable_alignment_fault();
#endif /* __UNALIGNED_ACCESS__ */

#if defined(__ARM11_MMU__)
   cp15_enable_unaligned_access();
   cp15_disable_ap_subpage();
   cp15_enable_branch_prediction();
//   cp15_switch_cache2RR();
#endif /* __ARM11_MMU__ */
   /* set translation table base */
   cp15_write_tbbr(
#if !defined(IC_BURNIN_TEST)   
   (kal_uint32)MAP2CREGPA(page_tbl)
#else
   /* Ken: The page table is put into SYSRAM instead of EMI in burning test, */
   /*         because no EXTRAM in MT6236 OLT  */
   (kal_uint32)page_tbl
#endif
   );

   /* enable MMU */
   cp15_enable_mmu();

   /* Enable I-Cache. Inv I-Cache in advance to prevent CODE_PATCH_CODE differing from Ext.Ram and I-Cache. */   
   if(cp15_is_icache_enabled()) {
   cp15_invalidate_icache();   
   }   
   cp15_enable_icache();

   cp15_enable_dcache();

   /*************************
    * TLB-Lock Config
    *************************/

   /* Ken: Shock will do experiment to decide if TLB lockdown is necessary
    * for the vector table and TCM in MT6276.
    */
#if !defined(MT6573) && !defined(MT6575) && !defined(MT6577)
   /*
    * lockdown the vector table and TCM for performance requirement
    * [NOTE] TCM lockdown is not only for performance purpose but also for SW DCM,
    * which the code should be placed in TCM while the DRAM is in self-refresh status.
    * Page table walk is not allowed.
    */
   LockdownTLB(0x00);

   LockdownTLB(itcm_base_addr);
   LockdownTLB(dtcm_base_addr);
#endif /* !MT6276 */

   /* TLB lockdown for SW DCM, which page table walk is not allowed */
#if defined(SW_DCM)
   /* Due to MT6235/38 E2 support EMI 13MHZ, TLB lookup may cause 60qbit error in idletask. */
   LockdownTLB((kal_uint32)EMI_base);
   LockdownTLB((kal_uint32)MCUCLK_CON);
   #if defined(MT6255)
   LockdownTLB((kal_uint32)PLL_base);
   #endif /* MT6255 */
#endif /* SW_DCM */

   /* convert pools' addresses back to virtual address */
#if defined(__ARM9_MMU__)
   fpt_pool = (kal_uint32 *)MAP2CREGVA(fpt_pool);
#endif /* __ARM9_MMU__ */
   cpt_pool = (kal_uint32 *)MAP2CREGVA(cpt_pool);

  return 0;
}

#endif  /* (__ARM9_MMU__ || __ARM11_MMU__ ) && !__FUE__ */


/*************************************************************************
* FUNCTION
*  MMU_InitSecondaryMAUI
*
* DESCRIPTION
*  
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  addr
*  len
*  permission
*
* RETURNS
*  0
*
*************************************************************************/

#if (defined(__ARM9_MMU__) || defined(__ARM11_MMU__)) && !defined(__FUE__)

#if defined(_NAND_FLASH_BOOTING_) || defined(__NOR_FLASH_BOOTING__) || defined(__EMMC_BOOTING__)

kal_uint32 MMU_InitSecondaryMAUI(void)
{
   kal_uint32 addr, tbl, demp_bin;
   MMU_PAGE_CONFIG_T pagc;

   /* eliminate compile warning */
   addr = tbl = 0;

#if defined(__DEMAND_PAGING__)
#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)

   /* initliaze page table for demand paging regions */
   for (demp_bin = 0; demp_bin < demp_bin_num(); demp_bin++) {
      for (addr = demp_begin(demp_bin); addr < demp_end(demp_bin); addr += 0x100000) {
         /* allocate a smallest page table & initialize default setting */
         tbl = alloc_ptbl(SMALLEST_PAGE_TABLE_SIZE);
         if (tbl == NULL) {
            EXT_ASSERT(0, 0, 0, 0);
            break;
         }
         mk_smallest_pt(tbl);

         /* set the page table entry */
         SET_DOMAIN(ORIGINAL_ACCESS, (MMU_PAGE_CONFIG_PTR)&pagc);
         page_tbl[addr >> PAGE_SIZE_1MB_SHIFT] = mk_smallest_ptd(MAP2CREGPA(tbl), (MMU_PAGE_CONFIG_PTR)&pagc);

         /* clean cache */
         cp15_clean_dcache_single((kal_uint32)&(page_tbl[addr >> PAGE_SIZE_1MB_SHIFT]));
      }

      /* drain write buffer */
      cp15_drain_write_buffer();
   }

#endif  /* _NAND_FLASH_BOOTING_ || __EMMC_BOOTING__ */
#endif /* __DEMAND_PAGING__ */

   return 0;
}

#endif /* _NAND_FLASH_BOOTING_ || __NOR_FLASH_BOOTING__ || __EMMC_BOOTING__ */

#endif  /* (__ARM9_MMU__ || __ARM11_MMU__) && !__FUE__ */

#endif /* __MTK_TARGET__ */

