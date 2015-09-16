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
 *   page.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file for demand paging.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PAGE_H__
#define __PAGE_H__

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "custom_demp.h"

/* replacement algorithm FIFO is obsolete */
//#define __DEMAND_PAGING_FIFO__

/* replacement algorithm LRU is obsolete */
//#define __DEMAND_PAGING_LRU__

#define __DEMAND_PAGING_LRU2Q__


/*******************************************************************************
 * Define constants.
 *******************************************************************************/
// TODO: Need define flash page size for future use
#if defined(__ARM11_MMU__)
#if defined(__EMMC_BOOTING__)
#define PAGE_CLUSTER 3  /* 2KB ^ PAGE_CLUSTER = 8KB */
#else /* __EMMC_BOOTING__ */
#define PAGE_CLUSTER 2  /* 2KB ^ PAGE_CLUSTER = 4KB */
#endif /* __EMMC_BOOTING__ */
#else /* __ARM11_MMU__ */
#define PAGE_CLUSTER 1  /* 2KB ^ PAGE_CLUSTER = 2KB */
#endif /* __ARM11_MMU__ */

#define PAGE_SHIFT_2K 11
#define DEMP_LOG_MAX 2000
#define DEMP_LRU2Q_BALANCE_THRESHOLD 64
#define NR_TLB (((1 << PAGE_SHIFT_2K) << (PAGE_CLUSTER - 1)) >> SMALLEST_PAGE_SIZE_SHIFT)
#define NR_CACHE (((1 << PAGE_SHIFT_2K) << (PAGE_CLUSTER - 1)) >> 5)

/* index definition */
#define ACC_IDX 0
#define MAX_IDX 1

/* users of demand paging lock service */
typedef enum
{
  DEMP_LOCK_NAND,
  DEMP_LOCK_EMMC,
  DEMP_LOCK_AUDIO,
  DEMP_LOCK_VIDEO,

  /* end of lock user list */
  DEMP_LOCK_USER_NUM,

  /* share ID */
  DEMP_LOCK_AUDIO_VIDEO = DEMP_LOCK_USER_NUM,
} demp_lock_user;

/* max page lock size */
#if defined(MT6276) || defined(MT6256) || defined(MT6255)
enum
{
  NAND_MAX_LOCK_SIZE     = 0xFFFFFFFF, /* no limitation */
  EMMC_MAX_LOCK_SIZE     = 0xFFFFFFFF, /* no limitation */
  
  /* audio */
#if defined(WT600K)
  AUDIO_MAX_LOCK_SIZE    = 850 * 1024,    /* 850KB */
#else /* WT600K */
  AUDIO_MAX_LOCK_SIZE    = 300 * 1024,    /* 300KB */
#endif /* WT600K */
  
  /* video */
#if defined (__RM_DEC_SUPPORT__)
  VIDEO_MAX_LOCK_SIZE    = 830 * 1024,    /* 830KB */
#else /* __RM_DEC_SUPPORT__ */
  VIDEO_MAX_LOCK_SIZE    = 250 * 1024,    /* 250KB */
#endif /* __RM_DEC_SUPPORT__ */

  /* end of max lock size list */
#if defined (WT600K)  

#if defined (__RM_DEC_SUPPORT__)
  TOTAL_MAX_LOCK_SIZE    = 1680 * 1024     /* 1680KB (additional demp pool size for lock) */
#else /* __RM_DEC_SUPPORT__ */
  TOTAL_MAX_LOCK_SIZE    = 1100 * 1024      /* 1100KB (additional demp pool size for lock) */
#endif /* __RM_DEC_SUPPORT__ */ 

#else /* WT600K */

#if defined (__RM_DEC_SUPPORT__)
  TOTAL_MAX_LOCK_SIZE    = 1130 * 1024     /* 1130KB (additional demp pool size for lock) */
#else /* __RM_DEC_SUPPORT__ */
  TOTAL_MAX_LOCK_SIZE    = 550 * 1024      /* 400KB (additional demp pool size for lock) */
#endif /* __RM_DEC_SUPPORT__ */ 

#endif /* WT600K */
};
#else
enum
{
  NAND_MAX_LOCK_SIZE     = 0xFFFFFFFF, /* no limitation */
  EMMC_MAX_LOCK_SIZE     = 0xFFFFFFFF, /* no limitation */
  
  /* audio && Total size*/
#if defined(WT600K)
  AUDIO_MAX_LOCK_SIZE    = 720 * 1024,    /* 720KB */
  VIDEO_MAX_LOCK_SIZE    = 0,
  TOTAL_MAX_LOCK_SIZE    = 720 * 1024
#elif defined(WT300K) /* WT300K */
  AUDIO_MAX_LOCK_SIZE    = 320 * 1024,    /* 320KB */
  VIDEO_MAX_LOCK_SIZE    = 0,
  TOTAL_MAX_LOCK_SIZE    = 320 * 1024
#elif defined(WT300K) /* WT150K */
  AUDIO_MAX_LOCK_SIZE    = 210 * 1024,    /* 210KB */
  VIDEO_MAX_LOCK_SIZE    = 0,
  TOTAL_MAX_LOCK_SIZE    = 210 * 1024
#else
  AUDIO_MAX_LOCK_SIZE    = 170 * 1024,    /* 170KB */  
  VIDEO_MAX_LOCK_SIZE    = 0,
  TOTAL_MAX_LOCK_SIZE    = 170 * 1024
#endif /* WT600K */ 
};
#endif
/*******************************************************************************
 * Define data structures.
 *******************************************************************************/

/* NFB Demand Paging */
typedef struct _demp_ninfo_t
{
    kal_uint32 npage_shift; /* NAND page shift */
    kal_uint32 begin_addr[DEMP_BIN_NUM];   /* begin address in the memory */
    kal_uint32 end_addr[DEMP_BIN_NUM];   /* end address in the memory */
    kal_uint32 block[DEMP_BIN_NUM];   /* starting block in the NAND flash */
    kal_uint32 blk_page_nr;    /* block number */
    kal_uint16* img_tbl[DEMP_BIN_NUM];    /* image table */
} demp_ninfo_t;

typedef struct _demp_page_t
{
    kal_uint32 va;  /* virtual address */
    kal_uint32 pa;  /* physical address */

#if defined(__DEMAND_PAGING_FIFO__)

    kal_uint32 lock;    /* page lock */

#elif defined(__DEMAND_PAGING_LRU__)    /* __DEMAND_PAGING_FIFO__ */

    struct _demp_page_t *next, *prev;
    struct _demp_page_t *next_lru, *prev_lru;
    kal_uint32 owner;

#elif defined(__DEMAND_PAGING_LRU2Q__)  /* __DEMAND_PAGING_FIFO__ */

    struct _demp_page_t *next, *prev;
    kal_uint8 lock_count[DEMP_LOCK_USER_NUM];

#endif  /* __DEMAND_PAGING_FIFO__ */

#if defined(__DEMAND_PAGING_DEBUG__)
    kal_uint32 swapout; /* number of swap out */
    kal_uint32 swapin;  /* number of swap in */
#endif  /* __DEMAND_PAGING_DEBUG__ */
} demp_page_t;

typedef struct _demp_log_t
{
    kal_uint32 cur_task;
    kal_uint32 time;
    kal_uint32 fault_addr;
    kal_uint16 swap_out;
    kal_uint16 error_type;
    kal_uint32 nandr_du;    /* duration of NAND Flash read */
} demp_log_t;

typedef struct _demp_stats_t
{
    kal_uint32 rom_begin[DEMP_BIN_NUM];
    kal_uint32 rom_end[DEMP_BIN_NUM];
    kal_uint32 page_cluster;
    kal_uint32 page_pool_size;
    kal_uint32 nr_swapout;
    kal_uint32 nr_swapin;
    kal_uint32 nr_fault;
    kal_uint32 nr_nandaccess;
    kal_uint32 fault_penalty;
    demp_log_t log[DEMP_LOG_MAX];
    kal_uint32 log_indx;
} demp_stats_t;
/*Demand Paging Evaluation Enhance*/
#ifdef __DEMAND_PAGING_PERFORMANCE_PROFILING__
// KeTing: To support change demand page pool on the fly
#define DEMP_PAGE_POOL_MAX_SIZE TOTAL_MAX_LOCK_SIZE + (5 * 1024 * 1024)
// support swaptime rank & number
#define SWAPTIMERANK 100
#define SWAPTIMERANKNUM 7
#define TASKNAMELEN 8
#define HISTORYNUM 8

typedef struct _demp_eval_pool
{
    kal_uint32 totalFaultTime;
    kal_uint32 nfbTime;
    kal_uint32 lastAccessAddr[HISTORYNUM];
    kal_uint16 totalFaultCount;
    kal_uint16 nfbCount;
    kal_char   Owner[TASKNAMELEN];

} demp_eval_pool;

typedef struct _demp_eval_time
{
    kal_uint32 preemptTimeStart;
    kal_uint32 preemptTime;
    kal_uint32 faultCountPerTask;
    kal_uint8   status;
    kal_char    Owner[TASKNAMELEN];
}demp_eval_time;

#endif

#ifdef __DEMAND_PAGING__
    #define DEMAND_PAGING_STACK_OVERHEAD 276
#else
    #define DEMAND_PAGING_STACK_OVERHEAD 0
#endif

typedef kal_int32 (*demp_pt)(kal_uint8 demp_bin, kal_uint32, kal_uint32);
/*******************************************************************************
 * Define macros.
 *******************************************************************************/

#define DEMP_ADDR_ALIGN_PAGE(a) (((a) >> PAGE_SHIFT_2K + (PAGE_CLUSTER - 1)) << PAGE_SHIFT_2K + (PAGE_CLUSTER - 1))

/*
 * demand paging dependent macros.
 */

#if defined(__DEMAND_PAGING__) && defined(__MTK_TARGET__) && !defined(__FUE__) && !defined(__UBL__)

#define set_demp_npage_shift(s)  \
        do {    \
            demp_ninfo.npage_shift = (s);    \
        } while (0)

#define set_demp_begin(i, addr) \
        do {    \
            demp_ninfo.begin_addr[i] = (addr); \
        } while (0)

#define set_demp_end(i, addr) \
        do {    \
            demp_ninfo.end_addr[i] = (addr); \
        } while (0)

#define set_demp_block(i, b)   \
        do {    \
            demp_ninfo.block[i] = (b);   \
        } while (0)

#define set_demp_blk_page_nr(n)   \
        do {    \
            demp_ninfo.blk_page_nr = (n);   \
        } while (0)

#define demp_npage_shift() demp_ninfo.npage_shift

#define demp_begin(i) demp_ninfo.begin_addr[i]

#define demp_end(i) demp_ninfo.end_addr[i]

#define demp_block(i) demp_ninfo.block[i]

#define demp_blk_page_nr() demp_ninfo.blk_page_nr

#define demp_img_tbl(i) demp_ninfo.img_tbl[i]

#define demp_bin_num() DEMP_BIN_NUM

#if !defined(__FOTA_DM__)

#define demp_init()   \
        do {    \
            extern void demp_initial();   \
            demp_initial();    \
        } while (0)


#else /* __FOTA_DM__ */

#define set_demp_load_info(i, a, b, c, d, e) \
        do{    \
            set_demp_block(i, a); \
            fota_mapping_tbl_pge = b; \
            fota_mapping_tbl_ptr = c; \
            fota_mapping_tbl_len = d; \
            fota_nfb_fgal        = e; \
        } while (0)

#define demp_init() \
     do { \
           extern void demp_FUE_initial(); \
           demp_FUE_initial(); \
     } while (0)


#endif /* !__FOTA_DM__ */

#define demp_query_remaining_lock_quota(x) (demp_lock_count[x][1] - demp_lock_count[x][0])

#else   /* __DEMAND_PAGING__ && MTK_TARGET && !__FUE__ && !__UBL__ */

#define set_demp_npage_shift(s)
#define set_demp_begin(i, addr)
#define set_demp_end(i, addr)
#define set_demp_block(i, b)
#define set_demp_blk_page_nr(n)
#define demp_npage_shift() 0
#define demp_begin(i) 0
#define demp_end(i) 0
#define demp_block(i) 0
#define demp_blk_page_nr() 1
#define demp_img_tbl(i) ((kal_uint16 *)0)
#define demp_init()
#define demp_query_remaining_lock_quota(x) 0

#if defined(__FOTA_DM__)
#define set_demp_load_info(a, b, c, d, e) 0
#endif /* __FOTA_DM__ */

#endif  /* __DEMAND_PAGING__ && !__FUE__ && !__UBL__ */

#define demp_lock_page(a)   \
        do {    \
            extern kal_int32 do_page_lock(kal_uint32 addr); \
            do_page_lock(a);    \
        } while (0)

#define demp_unlock_page(a) \
        do {    \
            extern kal_int32 do_page_unlock(kal_uint32 addr);   \
            do_page_unlock(a);  \
        } while (0)

#define demp_lock_pages(x, a, l) \
        do {    \
            extern kal_int32 do_pages_lock(demp_lock_user user, kal_uint32 addr, kal_uint32 length); \
            do_pages_lock(x, a, l); \
        } while (0)

#define demp_unlock_pages(x, a, l)   \
        do {    \
            extern kal_int32 do_pages_unlock(demp_lock_user user, kal_uint32 addr, kal_uint32 length); \
            do_pages_unlock(x, a, l); \
        } while (0)

#if defined(__ARM11_MMU__)

#define invalidate_cache_per_page(va) cp15_invalidate_idcache_region_ext(va, va + (NR_TLB << SMALLEST_PAGE_SIZE_SHIFT));

#elif defined(__ARM9_MMU__)

#define invalidate_cache_per_page(va)

#endif
/*
 * relacement algorithm dependent macros.
 */

#if defined(__DEMAND_PAGING_FIFO__)

/* no need to maintain FIFO anymore */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

#elif defined(__DEMAND_PAGING_LRU__)   /* __DEMAND_PAGING_FIFO__ */

/* no need to maintain LRU anymore */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

#elif defined(__DEMAND_PAGING_LRU2Q__)  /* __DEMAND_PAGING_FIFO__ */

#if defined (__DEMAND_PAGING_PERFORMANCE_PROFILING__)

//#error Before enabling DP profiling, please add the following code to tst_inject_string_hdlr

// To enable the DP size injection, you should add the following code to tst_inject_string_hdlr
// This function is at the file mcu\ps\l4\l4c\src\common\l4c_tst.c
/* Here is the start of the code body
#if defined(__DEMAND_PAGING_PERFORMANCE_PROFILING__) && defined (__MTK_TARGET__)
    // KeTing: For demand paging test to modify the page pool size on the fly
    else if (strcmp((char*)msg_ptr->string, "dp_pool_size") == 0)
    {
      extern void do_page_pool_size_change(kal_uint32 sizeInMegaByte);
      do_page_pool_size_change(msg_ptr->index);
      kal_prompt_trace(MOD_L4C, "The demand page pool size is changed to %d MB!", msg_ptr->index);
    }
#endif
 Here is the end of the code body */

#define demp_page_list_full_set_init()  \
        do {  \
            /* KeTing: To support change pool size on the fly, init the full set of control blocks */  \
            kal_uint32 max = DEMP_PAGE_POOL_MAX_SIZE >> (PAGE_SHIFT_2K + (PAGE_CLUSTER - 1));  \
            for (i = total; i < max; i++) {  \
                (demp_page_list + i)->pa = (kal_uint32)((demp_page_list + i - 1)->pa + (1 << (PAGE_SHIFT_2K + (PAGE_CLUSTER - 1)))); \
                (demp_page_list + i)->next = (demp_page_list + i + 1);  \
                (demp_page_list + i)->prev = (demp_page_list + i - 1);  \
                for (j = 0; j < DEMP_LOCK_USER_NUM; j++) {   \
                    (demp_page_list + i)->lock_count[j] = 0;  \
                } \
            }  \
            (demp_page_list + i - 1)->next = (demp_page_list + total);  \
            (demp_page_list + total)->prev = (demp_page_list + i - 1);  \
        } while (0)
#else
#define demp_page_list_full_set_init()
#endif

#define demp_page_list_init()   \
        do {    \
            kal_uint32 i, j, total;   \
            total = demp_page_pool_size >> (PAGE_SHIFT_2K + (PAGE_CLUSTER - 1));   \
            demp_page_list->pa = (kal_uint32)demp_page_pool;    \
            demp_page_list->next = demp_page_list + 1;  \
            for (i = 1; i < total; i++) {   \
                (demp_page_list + i)->pa = (kal_uint32)((demp_page_list + i - 1)->pa + (1 << (PAGE_SHIFT_2K + (PAGE_CLUSTER - 1)))); \
                (demp_page_list + i)->next = (demp_page_list + i + 1);  \
                (demp_page_list + i)->prev = (demp_page_list + i - 1);  \
                for (j = 0; j < DEMP_LOCK_USER_NUM; j++) {   \
                    (demp_page_list + i)->lock_count[j] = 0;  \
                } \
            }   \
            (demp_page_list + i - 1)->next = demp_page_list;    \
            demp_page_list->prev = demp_page_list + i - 1;  \
            demp_active_head.next = demp_active_head.prev = NULL; \
            demp_inactive_head.next = demp_page_list;  \
            demp_inactive_head.prev = NULL;    \
            demp_lock_head.next = demp_lock_head.prev = NULL; \
            demp_page_list_full_set_init();  \
        } while (0)

#define demp_page_alloc(p, a, flag)  \
        do {    \
            kal_uint32 pa;    \
            kal_uint32 *d;  \
            extern kal_bool is_anyone_lock(demp_page_t *page); \
            if (demp_inactive_head.next == NULL) {  \
                (p) = NULL; \
            } else {    \
                d = smallest_pd_alloc(DEMP_ADDR_ALIGN_PAGE((a)));    \
                pa = *(d) & ~SMALLEST_PAGE_SIZE_MASK;   \
                if (pa != 0) {   \
                    demp_page_search(pa, (p));   \
                    if ((p)->va == DEMP_ADDR_ALIGN_PAGE((a))) {    \
                        if (((p)->next == NULL) && ((p)->prev == NULL)) {   \
                            flag = KAL_TRUE;  \
                        } \
                        else if (is_anyone_lock(p) == KAL_TRUE) { \
                        	  ASSERT(0); \
                        } \
                        else{ \
                            break;	\
                        } \
                    }   \
                }   \
                (p) = demp_inactive_head.next;  \
            }   \
        } while (0)

#define demp_page_is_inuse(p) (((p) == NULL)? 1: 0)

/* move pages from active q to inactive q when inactive q is empty */
#define demp_lru2q_balance(mutex, enter_critical, leave_critical)   \
        do {    \
            kal_int32 i, j;    \
            demp_page_t *p; \
            kal_uint32 *d;  \
            (mutex) = enter_critical();   \
            if (demp_inactive_head.next == NULL) {  \
                for (i = DEMP_LRU2Q_BALANCE_THRESHOLD; i != 0; i--) {   \
                    p = demp_active_head.next;  \
                    if (p == NULL) {    \
                    	  if (demp_inactive_head.next == NULL) { \
                    	      ASSERT(0); \
                    	  } \
                        break;  \
                    } else {    \
                        if ((p)->next == (p)) {   \
                    	  	  demp_active_head.next = NULL;    \
                        }    \
                        else {    \
                            demp_active_head.next = p->next;    \
                            p->next->prev = p->prev;    \
                            p->prev->next = p->next;    \
                        }    \
                        d = smallest_pd_alloc(p->va); \
                        for (j = NR_TLB; j != 0; j--) { \
                            set_smallest_pd((kal_uint32)(d + j - 1), (*(d + j - 1)) & ~SMALLEST_PAGE_SIZE_MASK); \
                        }   \
                        cp15_drain_write_buffer(); \
                        if (demp_inactive_head.next == NULL) {  \
                            p->next = p;    \
                            p->prev = p;    \
                            demp_inactive_head.next = p;    \
                        } else {    \
                            p->next = demp_inactive_head.next;  \
                            p->prev = demp_inactive_head.next->prev;    \
                            demp_inactive_head.next->prev->next = p;    \
                            demp_inactive_head.next->prev = p;  \
                        }   \
                    }   \
                    leave_critical(mutex);    \
                    (mutex) = enter_critical();   \
                }   \
            }   \
            leave_critical(mutex);    \
        } while (0)

/* remove the page from either the inactive q or active q */
#define demp_page_set_inuse(p)   \
        do {    \
            if ((p)->next == (p)) {   \
                if (demp_inactive_head.next == (p)) {   \
                    demp_inactive_head.next = NULL; \
                } else if (demp_active_head.next == (p)) {  \
                    demp_active_head.next = NULL;   \
                } else {    \
                    ASSERT(0);  \
                }   \
            } else {    \
                if (demp_inactive_head.next == (p)) {   \
                    demp_inactive_head.next = (p)->next;    \
                } else if (demp_active_head.next == (p)) {  \
                    demp_active_head.next = (p)->next;    \
                }   \
                (p)->next->prev = (p)->prev;    \
                (p)->prev->next = (p)->next;    \
            }   \
            (p)->next = (p)->prev = NULL;  \
        } while (0)

#define demp_page_is_valid(p, a) ((p)->va != 0 && (p)->va != DEMP_ADDR_ALIGN_PAGE((a)))

#define demp_page_init(p)

#define demp_page_is_data_avail(p, a) ((p)->va == DEMP_ADDR_ALIGN_PAGE((a)))

/* add the page back to either the inactive q or active q */
#define demp_page_set_free(p, mutex, enter_critical, leave_critical) \
        do {    \
            demp_page_t *head;  \
            if ((p)->next != NULL) {    \
                ASSERT(0);  \
            }   \
            if ((p)->prev != NULL) {    \
                ASSERT(0);  \
            }   \
            if ((p)->va == 0) { \
                head = &demp_inactive_head; \
            } else {    \
                head = &demp_active_head; \
            }   \
            (mutex) = enter_critical(); \
            if (head->next == NULL) {  \
                (p)->next = (p);    \
                (p)->prev = (p);    \
                head->next = (p);    \
            } else {    \
                (p)->next = head->next;  \
                (p)->prev = head->next->prev;    \
                head->next->prev->next = (p);    \
                head->next->prev = (p);  \
            }   \
            leave_critical((mutex));    \
        } while (0)

#define demp_page_search(a, p) \
        do {    \
            kal_uint32 offset;  \
            offset = (kal_uint32)(a) - (kal_uint32)demp_page_pool;  \
            offset = offset >> (PAGE_SHIFT_2K + (PAGE_CLUSTER - 1));    \
            (p) = demp_page_list + offset;  \
        } while (0)

/* move the page to the lock q */
#define demp_page_set_lock(p)   \
        do {    \
            demp_page_set_inuse((p));   \
            if (demp_lock_head.next == NULL) {  \
                (p)->next = (p); \
                (p)->prev = (p); \
                demp_lock_head.next = (p);    \
            } else {    \
                (p)->next = demp_lock_head.next;  \
                (p)->prev = demp_lock_head.next->prev;    \
                demp_lock_head.next->prev->next = (p);    \
                demp_lock_head.next->prev = (p);  \
            }   \
        } while (0)

/* move the page from the lock q to active q */
#define demp_page_set_unlock(p) \
        do {    \
            if ((p)->next == (p)) {   \
                demp_lock_head.next = NULL; \
            } else {    \
                demp_lock_head.next = (p)->next;    \
                (p)->next->prev = (p)->prev;    \
                (p)->prev->next = (p)->next;    \
            }   \
            if (demp_active_head.next == NULL) {  \
                (p)->next = (p);    \
                (p)->prev = (p);    \
                demp_active_head.next = (p);    \
            } else {    \
                (p)->next = demp_active_head.next;  \
                (p)->prev = demp_active_head.next->prev;    \
                demp_active_head.next->prev->next = (p);    \
                demp_active_head.next->prev = (p);  \
            }   \
        } while (0)



#endif  /* __DEMAND_PAGING_FIFO__ */

#if defined(__DEMAND_PAGING_DEBUG_LOG__)

#define demp_trace(trace_class_enum, ...) \
       do{ \
           if(INT_Exception_Enter == 0) \
               kal_trace(trace_class_enum, __VA_ARGS__); \
       }while (0)	

#else  /* __DEMAND_PAGING_DEBUG_LOG__ */

#define demp_trace(trace_class_enum, ...)

#endif  /* __DEMAND_PAGING_DEBUG_LOG__ */

/*
 * debugging log dependent macros.
 */
#if defined(__DEMAND_PAGING_DEBUG__)

#include "SST_sla.h"
#define demp_swla_log_begin() SLA_CustomLogging("PF", SA_start)
#define demp_swla_log_end() SLA_CustomLogging("PF", SA_stop)

#define demp_log_begin  \
            extern kal_uint32 L1I_GetTimeStamp(void);   \
            kal_uint32 nr_frame = L1I_GetTimeStamp();   \
            kal_uint32 swap_out = 0, nandr_t1 = 0, nandr_t2 = 0;    \
            demp_swla_log_begin();


#define demp_log_swapout(p) \
        do {    \
            if (((p)->swapout + 1) != 0) {  \
                (p)->swapout++; \
            }   \
            if ((demp_stats.nr_swapout + 1) != 0) {  \
                demp_stats.nr_swapout++; \
            }   \
            swap_out = 1;   \
        } while (0)

#define demp_log_swapin(p) \
        do {    \
            if (((p)->swapin + 1) != 0) {   \
                (p)->swapin++; \
            }   \
            if ((demp_stats.nr_swapin + 1) != 0) {   \
                demp_stats.nr_swapin++; \
            }   \
        } while (0)

#define demp_log_nandr_1()  \
        do {    \
            extern kal_uint32 drv_get_current_time(void);   \
            nandr_t1 = drv_get_current_time();  \
        } while (0)

#define demp_log_nandr_2()  \
        do {    \
            extern kal_uint32 drv_get_current_time(void);   \
            nandr_t2 = drv_get_current_time();  \
            demp_stats.nr_nandaccess++;\
        } while (0)

#define demp_log(error_type, addr) \
        do {    \
            extern kal_uint32 drv_get_duration_tick(kal_uint32 previous_time, kal_uint32 current_time); \
            kal_uint8 *ptr; \
            kal_internal_taskid task = (kal_internal_taskid)kal_get_task_self_id();  \
            kal_uint32 indx = demp_stats.log_indx;  \
            demp_stats.log_indx++;  \
            if (demp_stats.log_indx == DEMP_LOG_MAX) {  \
                demp_stats.log_indx = 0;    \
            }   \
            if (task != NULL) {   \
                ptr = (kal_uint8 *)&(demp_stats.log[indx].cur_task); \
                *(ptr + 3) = *(task->task_name);  \
                *(ptr + 2) = *(task->task_name + 1);  \
                *(ptr + 1) = *(task->task_name + 2);  \
                *ptr = *(task->task_name + 3);  \
            }   \
            demp_stats.log[indx].time = nr_frame;   \
            demp_stats.log[indx].fault_addr = (kal_uint32)(addr);    \
            demp_stats.log[indx].swap_out = swap_out;  \
            demp_stats.log[indx].error_type = (error_type);  \
            demp_stats.log[indx].nandr_du = drv_get_duration_tick(nandr_t1, nandr_t2);  \
            if ((demp_stats.nr_fault + 1) != 0) {   \
                demp_stats.nr_fault++; \
            }   \
            demp_stats.fault_penalty += demp_stats.log[indx].nandr_du;  \
            demp_swla_log_end();    \
        } while (0)

#define demp_nr_swapout()    demp_stats.nr_swapout

#define demp_nr_swapin()    demp_stats.nr_swapin

#define demp_nr_fault()    demp_stats.nr_fault

#define demp_fault_penalty()    demp_stats.fault_penalty

#define demp_nr_nandaccess()    demp_stats.nr_nandaccess

#define demp_debug_init()   \
        do {    \
            kal_uint32 i; \
            for(i = 0; i < DEMP_BIN_NUM; i++){ \
                demp_stats.rom_begin[i] = demp_ninfo.begin_addr[i];   \
                demp_stats.rom_end[i] = demp_ninfo.end_addr[i];   \
	} \
            demp_stats.page_cluster = PAGE_CLUSTER; \
            demp_stats.page_pool_size = demp_page_pool_size;   \
        } while (0)


#else   /* __DEMAND_PAGING_DEBUG__ */

#define demp_swla_log_begin()
#define demp_swla_log_end()
#define demp_log_begin
#define demp_log_swapout(p)
#define demp_log_swapin(p)
#define demp_log_nandr_1()
#define demp_log_nandr_2()
#define demp_log(error_type, addr)
#define demp_nr_swapout() 0
#define demp_nr_swapin() 0
#define demp_nr_fault() 0
#define demp_fault_penalty() 0
#define demp_nr_nandaccess() 0
#define demp_debug_init(page_pool_size)


#endif  /* __DEMAND_PAGING_DEBUG__ */


/*******************************************************************************
 * Define import global data.
 *******************************************************************************/

#if defined(__MTK_TARGET__) && defined(__DEMAND_PAGING__)
extern demp_ninfo_t demp_ninfo;
extern demp_page_t *demp_page_list;
extern kal_uint32 *demp_page_pool, demp_page_pool_size;
extern kal_uint32 demp_lock_count[][2];
extern kal_uint8 INT_Exception_Enter;
#endif

#ifdef __DEMAND_PAGING_PERFORMANCE_PROFILING__

extern demp_eval_pool dempPoolStats[];
extern demp_eval_time dempTaskInfo[];
extern kal_uint32 executionTime;
extern kal_uint32 executionTimeStart;
extern kal_uint32 worstFaultTime;
extern kal_uint32 swapTime[];
extern kal_bool dempProfiling;
extern kal_uint32 pageCluster;

#endif

#if defined(__DEMAND_PAGING_DEBUG__)
extern demp_stats_t demp_stats;
#endif  /* __DEMAND_PAGING_DEBUG__ */

#if defined(__DEMAND_PAGING_FIFO__)
extern demp_page_t *demp_search_page, *demp_end_page;
#endif  /* __DEMAND_PAGING_FIFO__ */

#if defined(__DEMAND_PAGING_LRU__)
extern demp_page_t demp_lru;
#endif  /* __DEMAND_PAGING_LRU__ */

#if defined(__DEMAND_PAGING_LRU2Q__)
extern demp_page_t demp_active_head, demp_inactive_head, demp_lock_head;
#endif  /* __DEMAND_PAGING_LRU2Q__ */

#if defined(__FOTA_DM__)
extern kal_uint32 fota_mapping_tbl_pge;
extern kal_uint32 fota_mapping_tbl_len;
extern kal_uint32 *fota_mapping_tbl_ptr;
extern void *fota_nfb_fgal;
#endif  /* __FOTA_DM__ */


#endif  /* __PAGE_H__ */
