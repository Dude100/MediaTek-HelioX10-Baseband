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
 *   mmu_arm11.h
 *
 * Project:
 * --------
 *   Device Test
 *
 * Description:
 * ------------
 *   Header file for ARM11 MMU.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MMU_ARM11_INT_H__
#define __MMU_ARM11_INT_H__

//#define SET_NCNB_TO_NCB

#include "kal_general_types.h"
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
    
/******************************************************************
 * Define enums
 ******************************************************************/
#define SET_SMALLEST_TO_CPT
/* page table descriptor attribute */
enum 
{
    FIRST_LEVEL_FAULT = 0x0,
    FIRST_LEVEL_COARSE_PAGE = 0x1,
    FIRST_LEVEL_SECTION = 0x2,
    FIRST_LEVEL_SUPER_SECTION = 0x40002,
    SECOND_LEVEL_FAULT = 0x0,
    SECOND_LEVEL_LARGE_PAGE = 0x1,
    SECOND_LEVEL_SMALL_PAGE = 0x2
};

/* TEX */
enum
{
    TEX0 = 0x0,
#if defined(SET_NCNB_TO_NCB)
    TEX1 = 0x1,
#else
    TEX1 = 0x0,
#endif
    TEX2 = 0x2,
    TEX3 = 0x3,
    TEX4 = 0x4,
    TEX5 = 0x5,
    TEX6 = 0x6,
    TEX7 = 0x7
};

/* access permission 
   APX<<5 | AP[1:0] */
enum
{
    PRIV_READ_ONLY =  (0x1<<5) | 0x1,
    PRIV_READ_WRITE = (0x0<<5) | 0x1,
    USER_READ_ONLY =  (0x0<<5) | 0x2,
    USER_READ_WRITE = (0x0<<5) | 0x3
};

/* domain access control */
enum
{
    DOMAIN_NO_ACCESS = 0,
    DOMAIN_CLIENT = 1,
    DOMAIN_RESERVED = 2,
    DOMAIN_MANAGER = 3
};

/* domains */
enum
{
    DOMAIN00 = 0,
    DOMAIN01 = 1,
    DOMAIN02 = 2,
    DOMAIN03 = 3,
    DOMAIN04 = 4,
    DOMAIN05 = 5,
    DOMAIN06 = 6,
    DOMAIN07 = 7,
    DOMAIN08 = 8,
    DOMAIN09 = 9,
    DOMAIN10 = 10,
    DOMAIN11 = 11,
    DOMAIN12 = 12,
    DOMAIN13 = 13,
    DOMAIN14 = 14,
    DOMAIN15 = 15
};

/* page size */
enum 
{
    PAGE_SIZE_4KB = 4 * 1024,
    PAGE_SIZE_4KB_SHIFT = 12,
    PAGE_SIZE_4KB_MASK = 0x00000FFF,
    PAGE_SIZE_64KB = 64 * 1024,
    PAGE_SIZE_64KB_SHIFT = 16,
    PAGE_SIZE_64KB_MASK = 0x0000FFFF,
    PAGE_SIZE_1MB = 1 * 1024 * 1024,
    PAGE_SIZE_1MB_SHIFT = 20,
    PAGE_SIZE_1MB_MASK = 0x000FFFFF,
    PAGE_SIZE_16MB = 16 * 1024 * 1024,
    PAGE_SIZE_16MB_SHIFT = 24,
    PAGE_SIZE_16MB_MASK = 0x00FFFFFF,
    PAGE_SIZE_NUM = 4,
    SMALLEST_PAGE_SIZE = PAGE_SIZE_4KB,
    SMALLEST_PAGE_SIZE_SHIFT = PAGE_SIZE_4KB_SHIFT,
    SMALLEST_PAGE_SIZE_MASK = PAGE_SIZE_4KB_MASK
};

/* page table size */
enum 
{
    CPT_SIZE = 256 * 4,    /* coarse page table size */
    SMALLEST_PAGE_TABLE_SIZE = CPT_SIZE
};

/* Execution Never */
enum
{
    EXECUTABLE=0,
    NON_EXECUTABLE=1
};

/* Non Global */
enum
{
    GLOBAL = 0,
    NON_GLOBAL = 1
};

/* Shareable */
enum
{
    SHARED = 1,
    NON_SHARED = 0
};

/* Non Secure */
enum
{
    SECURE = 0,
    NON_SECURE = 1
};

/* FSR status */
enum
{
    FSR_STATUS_MASK = 0x0000040f,
    FSR_STATUS_ALIGMENT = 0x1,
    FSR_STATUS_TLB_MISS = 0x0,
    FSR_STATUS_ICACHE_OP_ERR = 0x4,
    FSR_STATUS_EXT_ABT_TRAN_1 = 0xc,
    FSR_STATUS_EXT_ABT_TRAN_2 = 0xe,
    FSR_STATUS_TRAN_SEC = 0x5,
    FSR_STATUS_TRAN_PAGE = 0x7,
    FSR_STATUS_ABF_SEC = 0x3,
    FSR_STATUS_ABF_PAGE = 0x6,
    FSR_STATUS_DOMAIN_SEC = 0x9,
    FSR_STATUS_DOMAIN_PAGE = 0xb,
    FSR_STATUS_PERM_SEC = 0xd,
    FSR_STATUS_PERM_PAGE = 0xf,
    FSR_STATUS_PRECISE_EXT_ABT = 0x8,
    FSR_STATUS_IMPRECISE_EXT_ABT = 0x406
};

/* page table option */
enum 
{
    DEF_PAGE_TABLE = 0,
    CUST_PAGE_TABLE = 1
};

typedef struct MMU_PAGE_CONFIG_STRUCT
{
   kal_uint8  permission;
   kal_uint8  cacheable;
   kal_uint8  bufferable;	 	 
   kal_uint8  domain;
   kal_uint8  exe_never;
   kal_uint8  tex;
   kal_uint8  non_global;
   kal_uint8  shared;
   kal_uint8  non_secure;
}MMU_PAGE_CONFIG_T, *MMU_PAGE_CONFIG_PTR;

typedef struct MMU_PAGE_TABLE_INFO_STRCUT
{
   kal_uint32 *cust_page_tbl;
   kal_uint32 *cust_fpt_pool;
   kal_uint32 cust_fpt_pool_size;
   kal_uint32 *cust_cpt_pool;
   kal_uint32 cust_cpt_pool_size;
}MMU_PAGE_TABLE_INFO_T, *MMU_PAGE_TABLE_INFO_PTR;

typedef struct MMU_REGION_INFO_STRCUT
{
   kal_uint32 addr;
   kal_uint32 len;
   MMU_PAGE_CONFIG_T pagc;
} MMU_REGION_INFO_T;

/******************************************************************
 * Define constants
 ******************************************************************/
/* Maximum TLB lockdown entries */
#define MAX_TLB_LOCKDOWN_COUNT 8

/* page table base address mask */
#define CPT_BASE_MASK 0xFFFFFC00


/* domain mask. */
#define DOMAIN_MASK    0xFFFFFE1F
#define DOMAIN_SHIFT    5

#define FIRST_LEVEL_SUPERSECTION_AP_MASK    0xFFFF73FF
#define FIRST_LEVEL_SUPERSECTION_AP_SHIFT    10

#define FIRST_LEVEL_SUPERSECTION_CB_MASK    0xFFFFFFF3
#define FIRST_LEVEL_SUPERSECTION_C_MASK     0xFFFFFFF7
#define FIRST_LEVEL_SUPERSECTION_B_MASK     0xFFFFFFFB
#define FIRST_LEVEL_SUPERSECTION_C_SHIFT    3
#define FIRST_LEVEL_SUPERSECTION_B_SHIFT    2

#define FIRST_LEVEL_SUPERSECTION_XN_MASK    0xFFFFFFEF
#define FIRST_LEVEL_SUPERSECTION_XN_SHIFT   4

#define FIRST_LEVEL_SUPERSECTION_TEX_MASK    0xFFFF8FFF
#define FIRST_LEVEL_SUPERSECTION_TEX_SHIFT   12

#define FIRST_LEVEL_SUPERSECTION_SHARED_MASK    0xFFFEFFFF
#define FIRST_LEVEL_SUPERSECTION_SHARED_SHIFT   16

#define FIRST_LEVEL_SUPERSECTION_NON_GLOBAL_MASK    0xFFFDFFFF
#define FIRST_LEVEL_SUPERSECTION_NON_GLOBAL_SHIFT   17

#define FIRST_LEVEL_SUPERSECTION_NON_SECURE_MASK    0xFFF7FFFF
#define FIRST_LEVEL_SUPERSECTION_NON_SECURE_SHIFT   19

#define FIRST_LEVEL_SECTION_AP_MASK    0xFFFF73FF
#define FIRST_LEVEL_SECTION_AP_SHIFT    10

#define FIRST_LEVEL_SECTION_CB_MASK    0xFFFFFFF3
#define FIRST_LEVEL_SECTION_C_MASK     0xFFFFFFF7
#define FIRST_LEVEL_SECTION_B_MASK     0xFFFFFFFB
#define FIRST_LEVEL_SECTION_C_SHIFT    3
#define FIRST_LEVEL_SECTION_B_SHIFT    2

#define FIRST_LEVEL_SECTION_XN_MASK    0xFFFFFFEF
#define FIRST_LEVEL_SECTION_XN_SHIFT   4

#define FIRST_LEVEL_SECTION_TEX_MASK    0xFFFF8FFF
#define FIRST_LEVEL_SECTION_TEX_SHIFT   12

#define FIRST_LEVEL_SECTION_SHARED_MASK    0xFFFEFFFF
#define FIRST_LEVEL_SECTION_SHARED_SHIFT   16

#define FIRST_LEVEL_SECTION_NON_GLOBAL_MASK    0xFFFDFFFF
#define FIRST_LEVEL_SECTION_NON_GLOBAL_SHIFT   17

#define FIRST_LEVEL_SECTION_NON_SECURE_MASK    0xFFF7FFFF
#define FIRST_LEVEL_SECTION_NON_SECURE_SHIFT   19

#define FIRST_LEVEL_COARSE_PAGE_NON_SECURE_MASK    0xFFFFFFF7
#define FIRST_LEVEL_COARSE_PAGE_NON_SECURE_SHIFT   4

#define SECOND_LEVEL_LARGE_AP_MASK    0xFFFFFDCF
#define SECOND_LEVEL_LARGE_AP_SHIFT   4

#define SECOND_LEVEL_LARGE_CB_MASK    0xFFFFFFF3
#define SECOND_LEVEL_LARGE_C_MASK     0xFFFFFFF7
#define SECOND_LEVEL_LARGE_B_MASK     0xFFFFFFFB
#define SECOND_LEVEL_LARGE_C_SHIFT    3
#define SECOND_LEVEL_LARGE_B_SHIFT    2

#define SECOND_LEVEL_LARGE_TEX_MASK    0xFFFF8FFF
#define SECOND_LEVEL_LARGE_TEX_SHIFT   12

#define SECOND_LEVEL_LARGE_SHARED_MASK    0xFFFFFBFF
#define SECOND_LEVEL_LARGE_SHARED_SHIFT   10

#define SECOND_LEVEL_LARGE_NON_GLOBAL_MASK    0xFFFFF7FF
#define SECOND_LEVEL_LARGE_NON_GLOBAL_SHIFT   11

#define SECOND_LEVEL_LARGE_XN_MASK    0xFFFF7FFF
#define SECOND_LEVEL_LARGE_XN_SHIFT   15

#define SECOND_LEVEL_SMALL_AP_MASK    0xFFFFFDCF
#define SECOND_LEVEL_SMALL_AP_SHIFT   4

#define SECOND_LEVEL_SMALL_CB_MASK    0xFFFFFFF3
#define SECOND_LEVEL_SMALL_C_SHIFT    3
#define SECOND_LEVEL_SMALL_B_SHIFT    2

#define SECOND_LEVEL_SMALL_TEX_MASK    0xFFFFFE3F
#define SECOND_LEVEL_SMALL_TEX_SHIFT   6

#define SECOND_LEVEL_SMALL_SHARED_MASK    0xFFFFFBFF
#define SECOND_LEVEL_SMALL_SHARED_SHIFT   10

#define SECOND_LEVEL_SMALL_NON_GLOBAL_MASK    0xFFFFF7FF
#define SECOND_LEVEL_SMALL_NON_GLOBAL_SHIFT   11

#define SECOND_LEVEL_SMALL_XN_MASK    0xFFFFFFFE
#define SECOND_LEVEL_SMALL_XN_SHIFT   0

#define FIRST_LEVEL_COARSE_L2PT_INDEX_RETRIEVE    0x000FF000
#define FIRST_LEVEL_COARSE_L2PT_INDEX_SHIFT    12


/*
 * Define macros.
 */

#define mk_smallest_pt mk_cpt
#define mk_smallest_ptd mk_cptd
#define is_smallest_ptd is_cptd
#define smallest_td_tba cptd_tba
#define is_smallest_pd is_spd
#define mk_smallest_pd mk_spd
#define FIRST_LEVEL_SMALLEST_L2PT_INDEX_RETRIEVE    FIRST_LEVEL_COARSE_L2PT_INDEX_RETRIEVE
#define FIRST_LEVEL_SMALLEST_L2PT_INDEX_SHIFT    FIRST_LEVEL_COARSE_L2PT_INDEX_SHIFT


#define set_fld_domain(pg, conf) pg = ((pg) & DOMAIN_MASK)  | ((conf)->domain<<DOMAIN_SHIFT);

#define set_ssd_ap(pg, conf) pg = (((pg) & FIRST_LEVEL_SUPERSECTION_AP_MASK) | ((conf)->permission<<FIRST_LEVEL_SUPERSECTION_AP_SHIFT))

#define set_ssd_cb(pg, conf) pg = (((pg) & (FIRST_LEVEL_SUPERSECTION_CB_MASK&FIRST_LEVEL_SUPERSECTION_TEX_MASK)) | ((conf)->cacheable<<FIRST_LEVEL_SUPERSECTION_C_SHIFT) | ((conf)->bufferable<<FIRST_LEVEL_SUPERSECTION_B_SHIFT) | ((conf)->tex<<FIRST_LEVEL_SUPERSECTION_TEX_SHIFT))

#define set_sd_ap(pg, conf) pg = (((pg) & FIRST_LEVEL_SECTION_AP_MASK) | ((conf)->permission<<FIRST_LEVEL_SECTION_AP_SHIFT))

#define set_sd_cb(pg, conf) pg = (((pg) & (FIRST_LEVEL_SECTION_CB_MASK&FIRST_LEVEL_SECTION_TEX_MASK)) | ((conf)->cacheable<<FIRST_LEVEL_SECTION_C_SHIFT) | ((conf)->bufferable<<FIRST_LEVEL_SECTION_B_SHIFT) | ((conf)->tex<<FIRST_LEVEL_SECTION_TEX_SHIFT))

#define set_lpd_ap(pg, conf) pg = (((pg) & SECOND_LEVEL_LARGE_AP_MASK) | ((conf)->permission<<SECOND_LEVEL_LARGE_AP_SHIFT))

#define set_lpd_cb(pg, conf) pg = (((pg) & (SECOND_LEVEL_LARGE_CB_MASK&SECOND_LEVEL_LARGE_TEX_MASK)) | ((conf)->cacheable<<SECOND_LEVEL_LARGE_C_SHIFT) | ((conf)->bufferable<<SECOND_LEVEL_LARGE_B_SHIFT) | ((conf)->tex<<SECOND_LEVEL_LARGE_TEX_SHIFT))

#define set_spd_ap(pg, conf) pg = (((pg) & SECOND_LEVEL_SMALL_AP_MASK) | ((conf)->permission<<SECOND_LEVEL_SMALL_AP_SHIFT))

#define set_spd_cb(pg, conf) pg = (((pg) & (SECOND_LEVEL_SMALL_CB_MASK&SECOND_LEVEL_SMALL_TEX_MASK)) | ((conf)->cacheable<<SECOND_LEVEL_SMALL_C_SHIFT) | ((conf)->bufferable<<SECOND_LEVEL_SMALL_B_SHIFT) | ((conf)->tex<<SECOND_LEVEL_SMALL_TEX_SHIFT))

#define get_sec_pg_cp_idx(addr) ((addr)&FIRST_LEVEL_COARSE_L2PT_INDEX_RETRIEVE)>>FIRST_LEVEL_COARSE_L2PT_INDEX_SHIFT

#define get_lpd_conf(pg, conf) do{ \
                               (conf)->permission = ((pg)&(~SECOND_LEVEL_LARGE_AP_MASK))>>SECOND_LEVEL_LARGE_AP_SHIFT;\
                               (conf)->cacheable = ((pg)&(~SECOND_LEVEL_LARGE_C_MASK))>>SECOND_LEVEL_LARGE_C_SHIFT;\
                               (conf)->bufferable = ((pg)&(~SECOND_LEVEL_LARGE_B_MASK))>>SECOND_LEVEL_LARGE_B_SHIFT;\
                               (conf)->exe_never = ((pg)&(~SECOND_LEVEL_LARGE_XN_MASK))>>SECOND_LEVEL_LARGE_XN_SHIFT;\
                               (conf)->tex = ((pg)&(~SECOND_LEVEL_LARGE_TEX_MASK))>>SECOND_LEVEL_LARGE_TEX_SHIFT;\
                               (conf)->non_global = ((pg)&(~SECOND_LEVEL_LARGE_NON_GLOBAL_MASK))>>SECOND_LEVEL_LARGE_NON_GLOBAL_SHIFT;\
                               (conf)->shared = ((pg)&(~SECOND_LEVEL_LARGE_SHARED_MASK))>>SECOND_LEVEL_LARGE_SHARED_SHIFT;\
                               }while(0)

#define get_sd_conf(pg, conf)  do{ \
                               (conf)->permission = ((pg)&(~FIRST_LEVEL_SECTION_AP_MASK))>>FIRST_LEVEL_SECTION_AP_SHIFT;\
                               (conf)->cacheable = ((pg)&(~FIRST_LEVEL_SECTION_C_MASK))>>FIRST_LEVEL_SECTION_C_SHIFT;\
                               (conf)->bufferable = ((pg)&(~FIRST_LEVEL_SECTION_B_MASK))>>FIRST_LEVEL_SECTION_B_SHIFT;\
                               (conf)->domain = ((pg)&(~DOMAIN_MASK))>>DOMAIN_SHIFT;\
                               (conf)->exe_never = ((pg)&(~FIRST_LEVEL_SECTION_XN_MASK))>>FIRST_LEVEL_SECTION_XN_SHIFT;\
                               (conf)->tex = ((pg)&(~FIRST_LEVEL_SECTION_TEX_MASK))>>FIRST_LEVEL_SECTION_TEX_SHIFT;\
                               (conf)->non_global = ((pg)&(~FIRST_LEVEL_SECTION_NON_GLOBAL_MASK))>>FIRST_LEVEL_SECTION_NON_GLOBAL_SHIFT;\
                               (conf)->shared = ((pg)&(~FIRST_LEVEL_SECTION_SHARED_MASK))>>FIRST_LEVEL_SECTION_SHARED_SHIFT;\
                               (conf)->non_secure = ((pg)&(~FIRST_LEVEL_SECTION_NON_SECURE_MASK))>>FIRST_LEVEL_SECTION_NON_SECURE_SHIFT;\
                               }while(0)

#define get_ssd_conf(pg, conf) do{ \
                               (conf)->permission = ((pg)&(~FIRST_LEVEL_SUPERSECTION_AP_MASK))>>FIRST_LEVEL_SUPERSECTION_AP_SHIFT;\
                               (conf)->cacheable = ((pg)&(~FIRST_LEVEL_SUPERSECTION_C_MASK))>>FIRST_LEVEL_SUPERSECTION_C_SHIFT;\
                               (conf)->bufferable = ((pg)&(~FIRST_LEVEL_SUPERSECTION_B_MASK))>>FIRST_LEVEL_SUPERSECTION_B_SHIFT;\
                               (conf)->exe_never = ((pg)&(~FIRST_LEVEL_SUPERSECTION_XN_MASK))>>FIRST_LEVEL_SUPERSECTION_XN_SHIFT;\
                               (conf)->tex = ((pg)&(~FIRST_LEVEL_SUPERSECTION_TEX_MASK))>>FIRST_LEVEL_SUPERSECTION_TEX_SHIFT;\
                               (conf)->non_global = ((pg)&(~FIRST_LEVEL_SUPERSECTION_NON_GLOBAL_MASK))>>FIRST_LEVEL_SUPERSECTION_NON_GLOBAL_SHIFT;\
                               (conf)->shared = ((pg)&(~FIRST_LEVEL_SUPERSECTION_SHARED_MASK))>>FIRST_LEVEL_SUPERSECTION_SHARED_SHIFT;\
                               (conf)->non_secure = ((pg)&(~FIRST_LEVEL_SUPERSECTION_NON_SECURE_MASK))>>FIRST_LEVEL_SUPERSECTION_NON_SECURE_SHIFT;\
                               }while(0)

#define SET_DOMAIN(dom, conf) (conf)->domain = dom;

#define SET_CACHEABLE(c, conf)         do{ \
                                       if((c)==CACHEABLE_BUFFERABLE){ \
                                          (conf)->cacheable = PAGE_CACHEABLE;\
                                          (conf)->bufferable = PAGE_BUFFERABLE;\
                                          (conf)->tex = TEX0;\
                                       }else if((c)==NONCACHEABLE_BUFFERABLE){\
                                          (conf)->cacheable = PAGE_NO_CACHE;\
                                          (conf)->bufferable = PAGE_BUFFERABLE;\
                                          (conf)->tex = TEX0;\
                                       }else if((c)==CACHEABLE_NONBUFFERABLE){\
                                          (conf)->cacheable = PAGE_CACHEABLE;\
                                          (conf)->bufferable = PAGE_NO_CACHE;\
                                          (conf)->tex = TEX0;\
                                       }else if((c)==NONCACHEABLE_NONBUFFERABLE){\
                                          (conf)->cacheable = PAGE_NO_CACHE;\
                                          (conf)->bufferable = PAGE_NO_CACHE;\
                                          (conf)->tex = TEX1;\
                                       }else{\
                                          ASSERT(0);\
                                       }\
                                       }while(0)

#define SET_PERMISSION(perm, conf)     do{ \
                                       if((perm)==PRIV_RO){ \
                                          (conf)->permission = PRIV_READ_ONLY;\
                                       }else if((perm)==PRIV_RW){\
                                          (conf)->permission = PRIV_READ_WRITE;\
                                       }else if((perm)==USER_RO){\
                                          (conf)->permission = USER_READ_ONLY;\
                                       }else if((perm)==USER_RW){\
                                          (conf)->permission = USER_READ_WRITE;\
                                       }else{\
                                          ASSERT(0);\
                                       }\
                                       }while(0)

#define USER_RW_NCNB(conf)        do{ \
                                  (conf)->permission = USER_READ_WRITE;\
                                  (conf)->domain = DOMAIN00;\
                                  (conf)->cacheable = PAGE_NO_CACHE;\
                                  (conf)->bufferable = PAGE_NO_CACHE;\
                                  (conf)->exe_never = EXECUTABLE;\
                                  (conf)->tex = TEX1;\
                                  (conf)->non_global = NON_GLOBAL;\
                                  (conf)->shared = NON_SHARED;\
                                  (conf)->non_secure = SECURE;\
                                  }while(0)

#define USER_RW_CB(conf)          do{ \
                                  (conf)->permission = USER_READ_WRITE;\
                                  (conf)->domain = DOMAIN00;\
                                  (conf)->cacheable = PAGE_CACHEABLE;\
                                  (conf)->bufferable = PAGE_BUFFERABLE;\
                                  (conf)->exe_never = EXECUTABLE;\
                                  (conf)->tex = TEX0;\
                                  (conf)->non_global = NON_GLOBAL;\
                                  (conf)->shared = NON_SHARED;\
                                  (conf)->non_secure = SECURE;\
                                  }while(0)

#define DEFAULT_RO_CB(conf)       do{ \
                                  (conf)->permission = PRIV_READ_ONLY;\
                                  (conf)->domain = DOMAIN00;\
                                  (conf)->cacheable = PAGE_CACHEABLE;\
                                  (conf)->bufferable = PAGE_BUFFERABLE;\
                                  (conf)->exe_never = EXECUTABLE;\
                                  (conf)->tex = TEX0;\
                                  (conf)->non_global = NON_GLOBAL;\
                                  (conf)->shared = NON_SHARED;\
                                  (conf)->non_secure = SECURE;\
                                  }while(0)

#define DEFAULT_RO_CNB(conf)      do{ \
                                  (conf)->permission = PRIV_READ_ONLY;\
                                  (conf)->domain = DOMAIN00;\
                                  (conf)->cacheable = PAGE_CACHEABLE;\
                                  (conf)->bufferable = PAGE_NO_CACHE;\
                                  (conf)->exe_never = EXECUTABLE;\
                                  (conf)->tex = TEX0;\
                                  (conf)->non_global = NON_GLOBAL;\
                                  (conf)->shared = NON_SHARED;\
                                  (conf)->non_secure = SECURE;\
                                  }while(0)


#define DEFAULT_RO_NCNB(conf)     do{ \
                                  (conf)->permission = PRIV_READ_ONLY;\
                                  (conf)->domain = DOMAIN00;\
                                  (conf)->cacheable = PAGE_NO_CACHE;\
                                  (conf)->bufferable = PAGE_NO_CACHE;\
                                  (conf)->exe_never = EXECUTABLE;\
                                  (conf)->tex = TEX1;\
                                  (conf)->non_global = NON_GLOBAL;\
                                  (conf)->shared = NON_SHARED;\
                                  (conf)->non_secure = SECURE;\
                                  }while(0)

#define DEFAULT_RW_CB(conf)       do{ \
                                  (conf)->permission = PRIV_READ_WRITE;\
                                  (conf)->domain = DOMAIN00;\
                                  (conf)->cacheable = PAGE_CACHEABLE;\
                                  (conf)->bufferable = PAGE_BUFFERABLE;\
                                  (conf)->exe_never = EXECUTABLE;\
                                  (conf)->tex = TEX0;\
                                  (conf)->non_global = NON_GLOBAL;\
                                  (conf)->shared = NON_SHARED;\
                                  (conf)->non_secure = SECURE;\
                                  }while(0)

#define EXE_RW_CB(conf)           do{ \
                                  (conf)->permission = PRIV_READ_WRITE;\
                                  (conf)->domain = DOMAIN00;\
                                  (conf)->cacheable = PAGE_CACHEABLE;\
                                  (conf)->bufferable = PAGE_BUFFERABLE;\
                                  (conf)->exe_never = EXECUTABLE;\
                                  (conf)->tex = TEX0;\
                                  (conf)->non_global = NON_GLOBAL;\
                                  (conf)->shared = NON_SHARED;\
                                  (conf)->non_secure = SECURE;\
                                  }while(0)

#define DEFAULT_RW_NCB(conf)      do{ \
                                  (conf)->permission = PRIV_READ_WRITE;\
                                  (conf)->domain = DOMAIN00;\
                                  (conf)->cacheable = PAGE_NO_CACHE;\
                                  (conf)->bufferable = PAGE_CACHEABLE;\
                                  (conf)->exe_never = EXECUTABLE;\
                                  (conf)->tex = TEX0;\
                                  (conf)->non_global = NON_GLOBAL;\
                                  (conf)->shared = NON_SHARED;\
                                  (conf)->non_secure = SECURE;\
                                  }while(0)

#define EXE_RW_NCB(conf)          do{ \
                                  (conf)->permission = PRIV_READ_WRITE;\
                                  (conf)->domain = DOMAIN00;\
                                  (conf)->cacheable = PAGE_NO_CACHE;\
                                  (conf)->bufferable = PAGE_CACHEABLE;\
                                  (conf)->exe_never = EXECUTABLE;\
                                  (conf)->tex = TEX0;\
                                  (conf)->non_global = NON_GLOBAL;\
                                  (conf)->shared = NON_SHARED;\
                                  (conf)->non_secure = SECURE;\
                                  }while(0)

#define DEFAULT_RW_NCNB(conf)     do{ \
                                  (conf)->permission = PRIV_READ_WRITE;\
                                  (conf)->domain = DOMAIN00;\
                                  (conf)->cacheable = PAGE_NO_CACHE;\
                                  (conf)->bufferable = PAGE_NO_CACHE;\
                                  (conf)->exe_never = EXECUTABLE;\
                                  (conf)->tex = TEX1;\
                                  (conf)->non_global = NON_GLOBAL;\
                                  (conf)->shared = NON_SHARED;\
                                  (conf)->non_secure = SECURE;\
                                  }while(0)

#define EXE_RW_NCNB(conf)         do{ \
                                  (conf)->permission = PRIV_READ_WRITE;\
                                  (conf)->domain = DOMAIN00;\
                                  (conf)->cacheable = PAGE_NO_CACHE;\
                                  (conf)->bufferable = PAGE_NO_CACHE;\
                                  (conf)->exe_never = EXECUTABLE;\
                                  (conf)->tex = TEX1;\
                                  (conf)->non_global = NON_GLOBAL;\
                                  (conf)->shared = NON_SHARED;\
                                  (conf)->non_secure = SECURE;\
                                  }while(0)

#define DEFAULT_RO_TCM(conf)      do{ \
                                  (conf)->permission = PRIV_READ_ONLY;\
                                  (conf)->domain = DOMAIN00;\
                                  (conf)->cacheable = PAGE_CACHEABLE;\
                                  (conf)->bufferable = PAGE_BUFFERABLE;\
                                  (conf)->exe_never = EXECUTABLE;\
                                  (conf)->tex = TEX0;\
                                  (conf)->non_global = NON_GLOBAL;\
                                  (conf)->shared = NON_SHARED;\
                                  (conf)->non_secure = SECURE;\
                                  }while(0)

#define DEFAULT_RW_TCM(conf)      do{ \
                                  (conf)->permission = PRIV_READ_WRITE;\
                                  (conf)->domain = DOMAIN00;\
                                  (conf)->cacheable = PAGE_CACHEABLE;\
                                  (conf)->bufferable = PAGE_BUFFERABLE;\
                                  (conf)->exe_never = NON_EXECUTABLE;\
                                  (conf)->tex = TEX0;\
                                  (conf)->non_global = NON_GLOBAL;\
                                  (conf)->shared = NON_SHARED;\
                                  (conf)->non_secure = SECURE;\
                                  }while(0)

#define EXE_RW_TCM(conf)          do{ \
                                  (conf)->permission = PRIV_READ_WRITE;\
                                  (conf)->domain = DOMAIN00;\
                                  (conf)->cacheable = PAGE_CACHEABLE;\
                                  (conf)->bufferable = PAGE_BUFFERABLE;\
                                  (conf)->exe_never = EXECUTABLE;\
                                  (conf)->tex = TEX0;\
                                  (conf)->non_global = NON_GLOBAL;\
                                  (conf)->shared = NON_SHARED;\
                                  (conf)->non_secure = SECURE;\
                                  }while(0)

#define DEFAULT_REGISTER_RW_NCNB(conf)     do{ \
                                           (conf)->permission = PRIV_READ_WRITE;\
                                           (conf)->domain = DOMAIN00;\
                                           (conf)->cacheable = PAGE_NO_CACHE;\
                                           (conf)->bufferable = PAGE_NO_CACHE;\
                                           (conf)->exe_never = NON_EXECUTABLE;\
                                           (conf)->tex = TEX0;\
                                           (conf)->non_global = NON_GLOBAL;\
                                           (conf)->shared = NON_SHARED;\
                                           (conf)->non_secure = SECURE;\
                                           }while(0)

#define DEFAULT_REGISTER_RW_NCB(conf)      do{ \
                                           (conf)->permission = PRIV_READ_WRITE;\
                                           (conf)->domain = DOMAIN00;\
                                           (conf)->cacheable = PAGE_NO_CACHE;\
                                           (conf)->bufferable = PAGE_CACHEABLE;\
                                           (conf)->exe_never = NON_EXECUTABLE;\
                                           (conf)->tex = TEX0;\
                                           (conf)->non_global = NON_GLOBAL;\
                                           (conf)->shared = NON_SHARED;\
                                           (conf)->non_secure = SECURE;\
                                           }while(0)

#define DEFAULT_REGISTER_RO_NCNB(conf)     do{ \
                                           (conf)->permission = PRIV_READ_ONLY;\
                                           (conf)->domain = DOMAIN00;\
                                           (conf)->cacheable = PAGE_NO_CACHE;\
                                           (conf)->bufferable = PAGE_NO_CACHE;\
                                           (conf)->exe_never = NON_EXECUTABLE;\
                                           (conf)->tex = TEX0;\
                                           (conf)->non_global = NON_GLOBAL;\
                                           (conf)->shared = NON_SHARED;\
                                           (conf)->non_secure = SECURE;\
                                           }while(0)

#define DEFAULT_REGISTER_RO_NCB(conf)      do{ \
                                           (conf)->permission = PRIV_READ_ONLY;\
                                           (conf)->domain = DOMAIN00;\
                                           (conf)->cacheable = PAGE_NO_CACHE;\
                                           (conf)->bufferable = PAGE_CACHEABLE;\
                                           (conf)->exe_never = NON_EXECUTABLE;\
                                           (conf)->tex = TEX0;\
                                           (conf)->non_global = NON_GLOBAL;\
                                           (conf)->shared = NON_SHARED;\
                                           (conf)->non_secure = SECURE;\
                                           }while(0)

/* make super section descriptor */
#define mk_ssd(addr, conf) (((addr) & 0xff000000) | (((conf)->permission) << 10) | \
                           (((conf)->exe_never) << 4)| \
                           (((conf)->tex) << 12) | (((conf)->cacheable) << 3) | \
                           (((conf)->bufferable) << 2)| (((conf)->shared) << 16) | \
                           (((conf)->non_global) << 17) | (((conf)->non_secure) << 19) | \
                           FIRST_LEVEL_SUPER_SECTION)

/* make section descriptor */
#define mk_sd(addr, conf)  (((addr) & 0xfff00000) | (((conf)->permission) << 10) | \
                           (((conf)->domain) << 5) | (((conf)->exe_never) << 4)| \
                           (((conf)->tex) << 12) | (((conf)->cacheable) << 3) | \
                           (((conf)->bufferable) << 2)| (((conf)->shared) << 16) | \
                           (((conf)->non_global) << 17) | (((conf)->non_secure) << 19) | \
                           FIRST_LEVEL_SECTION)

/* make coarse page table descriptor */
#define mk_cptd(addr, conf) (((addr) & 0xfffffc00) | (((conf)->domain) << 5) | \
                            (((conf)->non_secure) << 3) | FIRST_LEVEL_COARSE_PAGE)

/* make large page descripter */
#define mk_lpd(addr, conf) (((addr) & 0xffff0000) |(((conf)->permission) << 4) | \
                           (((conf)->cacheable) << 3) | (((conf)->bufferable) << 2) | \
                           (((conf)->tex) << 12) | (((conf)->exe_never) << 15) | \
                           (((conf)->non_global) << 11) | (((conf)->shared) << 10) | \
                           SECOND_LEVEL_LARGE_PAGE)

/* make small page descripter */
#define mk_spd(addr, conf) (((addr) & 0xfffff000) | (((conf)->permission) << 4) | \
                           (((conf)->cacheable) << 3) | (((conf)->bufferable) << 2) | \
                           (((conf)->tex) << 6) | (((conf)->exe_never) << 0) | \
                           (((conf)->non_global) << 11) | (((conf)->shared) << 10) | \
                           SECOND_LEVEL_SMALL_PAGE)

/* determin if super section descripter */
#define is_ssd(d) (((d) & 0x00040003) == FIRST_LEVEL_SUPER_SECTION)

/* determin if section descripter */
#define is_sd(d) (((d) & 0x00040003) == FIRST_LEVEL_SECTION)

/* determin if coarse page table descripter */
#define is_cptd(d) (((d) & 0x00000003) == FIRST_LEVEL_COARSE_PAGE)

/* determin if large page descripter */
#define is_lpd(d) (((d) & 0x00000003) == SECOND_LEVEL_LARGE_PAGE)

/* determin if small page descripter */
#define is_spd(d) (((d) & 0x00000002) == SECOND_LEVEL_SMALL_PAGE)

/* get the table base address from the coarse page table descriptor */
#define cptd_tba(addr) ((addr) & 0xfffffc00)

/* make default page table */
#define mk_def_pt(tbl) \
        do {    \
            kal_int32 i;   \
            kal_uint32 *tbl_ptr = (kal_uint32 *)(tbl);  \
            for (i = 4095; i >= 0; i--) {   \
                tbl_ptr[i] = FIRST_LEVEL_FAULT; \
            }   \
        } while (0)

/* make coarse page table */
#define mk_cpt(tbl) \
        do {    \
            kal_uint32 i;   \
            kal_uint32 *tbl_ptr = (kal_uint32 *)(tbl);    \
            for (i = 0; i < 256; i++) {   \
               tbl_ptr[i] = SECOND_LEVEL_FAULT; \
            }   \
        } while (0)



#endif  /* __MMU_ARM11_INT_H__ */

