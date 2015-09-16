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
*       esal_ge_mem_defs.h
*
*   COMPONENT
*
*       ESAL - Embedded Software Abstraction Layer
*
*   DESCRIPTION
*
*       This file contains generic defines, structures, data types, etc
*       related to memory
*
*   DATA STRUCTURES
*
*       ESAL_GE_MEM_REGION
*
*   DEPENDENCIES
*
*       esal_co_mem_defs.h                  Embedded Software
*                                           Abstraction Layer core
*                                           defines related to memory
*       esal_pr_mem_defs.h                  Embedded Software
*                                           Abstraction Layer processor
*                                           defines related to memory
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
***********************************************************************/

#ifndef         ESAL_GE_MEM_DEFS_H
#define         ESAL_GE_MEM_DEFS_H

/* Include all required header files */
//#include        "esal_pr_mem_defs.h"
//#include        "esal_co_mem_defs.h"

/* Define memory common read/write macros */
#define         ESAL_GE_MEM_READ8(addr)         *(volatile ESAL_UINT8 *)(addr)
#define         ESAL_GE_MEM_READ16(addr)        *(volatile ESAL_UINT16 *)(addr)
#define         ESAL_GE_MEM_READ32(addr)        *(volatile ESAL_UINT32 *)(addr)
#define         ESAL_GE_MEM_WRITE8(addr,data)   *(volatile ESAL_UINT8 *)(addr) = (ESAL_UINT8)(data)
#define         ESAL_GE_MEM_WRITE16(addr,data)  *(volatile ESAL_UINT16 *)(addr) = (ESAL_UINT16)(data)
#define         ESAL_GE_MEM_WRITE32(addr,data)  *(volatile ESAL_UINT32 *)(addr) = (ESAL_UINT32)(data)

#if             (ESAL_TS_64BIT_SUPPORT == ESAL_TRUE)

#define         ESAL_GE_MEM_READ64(addr)        *(volatile ESAL_UINT64 *)(addr)
#define         ESAL_GE_MEM_WRITE64(addr,data)  *(volatile ESAL_UINT64 *)(addr) = (ESAL_UINT64)(data)

#endif          /* ESAL_TS_64BIT_SUPPORT == ESAL_TRUE */

/* Defines for big endian and little endian */
#define         ESAL_BIG_ENDIAN                 0
#define         ESAL_LITTLE_ENDIAN              1

/* Defines used for common memory sizes */
#define         ESAL_GE_MEM_1K                  1024UL
#define         ESAL_GE_MEM_2K                  (ESAL_GE_MEM_1K * 2UL)
#define         ESAL_GE_MEM_4K                  (ESAL_GE_MEM_1K * 4UL)
#define         ESAL_GE_MEM_8K                  (ESAL_GE_MEM_1K * 8UL)
#define         ESAL_GE_MEM_16K                 (ESAL_GE_MEM_1K * 16UL)
#define         ESAL_GE_MEM_32K                 (ESAL_GE_MEM_1K * 32UL)
#define         ESAL_GE_MEM_64K                 (ESAL_GE_MEM_1K * 64UL)
#define         ESAL_GE_MEM_128K                (ESAL_GE_MEM_1K * 128UL)
#define         ESAL_GE_MEM_256K                (ESAL_GE_MEM_1K * 256UL)
#define         ESAL_GE_MEM_512K                (ESAL_GE_MEM_1K * 512UL)
#define         ESAL_GE_MEM_1M                  (ESAL_GE_MEM_1K * 1024UL)
#define         ESAL_GE_MEM_2M                  (ESAL_GE_MEM_1M * 2UL)
#define         ESAL_GE_MEM_4M                  (ESAL_GE_MEM_1M * 4UL)
#define         ESAL_GE_MEM_8M                  (ESAL_GE_MEM_1M * 8UL)
#define         ESAL_GE_MEM_16M                 (ESAL_GE_MEM_1M * 16UL)
#define         ESAL_GE_MEM_32M                 (ESAL_GE_MEM_1M * 32UL)
#define         ESAL_GE_MEM_64M                 (ESAL_GE_MEM_1M * 64UL)
#define         ESAL_GE_MEM_128M                (ESAL_GE_MEM_1M * 128UL)
#define         ESAL_GE_MEM_256M                (ESAL_GE_MEM_1M * 256UL)
#define         ESAL_GE_MEM_512M                (ESAL_GE_MEM_1M * 512UL)
#define         ESAL_GE_MEM_1G                  (ESAL_GE_MEM_1M * 1024UL)
#define         ESAL_GE_MEM_2G                  (ESAL_GE_MEM_1G * 2UL)
#define         ESAL_GE_MEM_3G                  (ESAL_GE_MEM_1G * 3UL)
#define         ESAL_GE_MEM_4G                  (ESAL_GE_MEM_1G * 4UL)

/* Check if architecture uses reverse bit-ordering (most-significant bit is bit 0
   instead of bit 31) */
#ifdef ESAL_AR_REVERSE_BIT_ORDERING

/* Macro used to make a 32-bit value with the specified bit set (reverse ordering) */
#define         ESAL_GE_MEM_32BIT_SET(bit_num)      (1UL<<(31-bit_num))

/* Macro used to make a 32-bit value with the specified bit clear (reverse ordering) */
#define         ESAL_GE_MEM_32BIT_CLEAR(bit_num)    ~(1UL<<(31-bit_num))

/* Macro used to get the value of the bits starting at start_bit up to
   end_bit (reverse ordering) */
#define         ESAL_GE_MEM_32BIT_VAL_GET(value,start_bit,end_bit)                              \
                    (ESAL_UINT32)(((ESAL_UINT32)(value) &                                                 \
                              (ESAL_GE_MEM_32BIT_SET(31-start_bit) - 1 +                        \
                               ESAL_GE_MEM_32BIT_SET(31-start_bit))) >>                         \
                              (31-end_bit))

/* Macro used to test if the specified bit number is set
   (returns ESAL_TRUE if set / ESAL_FALSE if not set) (reverse ordering) */
#define         ESAL_GE_MEM_32BIT_TEST(value,bit_num)                                           \
                    (((ESAL_UINT32)(value) & ESAL_GE_MEM_32BIT_SET(31-bit_num)) ? ESAL_TRUE : ESAL_FALSE)

#else

/* Macro used to make a 32-bit value with the specified bit set */
#define         ESAL_GE_MEM_32BIT_SET(bit_num)      (1UL<<(bit_num))

/* Macro used to make a 32-bit value with the specified bit clear */
#define         ESAL_GE_MEM_32BIT_CLEAR(bit_num)    ~(1UL<<(bit_num))

/* Macro used to get the value of the bits starting from start_bit up to
   end_bit */
#define         ESAL_GE_MEM_32BIT_VAL_GET(value,start_bit,end_bit)                              \
                    (ESAL_UINT32)(((ESAL_UINT32)(value) &                                                 \
                              (ESAL_GE_MEM_32BIT_SET(end_bit) - 1 +                             \
                               ESAL_GE_MEM_32BIT_SET(end_bit))) >>                              \
                              (start_bit))

/* Macro used to test if the specified bit number is set
   (returns ESAL_TRUE if set / ESAL_FALSE if not set) */
#define         ESAL_GE_MEM_32BIT_TEST(value,bit_num)                                           \
                    (((ESAL_UINT32)(value) & ESAL_GE_MEM_32BIT_SET(bit_num)) ? ESAL_TRUE : ESAL_FALSE)

#endif  /* ESAL_AR_REVERSE_BIT_ORDERING */

/* Macro used to test if the specified bit mask is set within the given value
   (returns ESAL_TRUE if entire bit mask is set / ESAL_FALSE if entire bitmask not set) */
#define         ESAL_GE_MEM_32BIT_MASK_TEST(value,bit_mask)                                     \
                    (((ESAL_UINT32)(value) & (bit_mask)) == (bit_mask) ? ESAL_TRUE : ESAL_FALSE)

/* Define for size of 4 unsigned longs */
#define         ESAL_GE_MEM_4_X_32BIT_SIZE      (ESAL_UINT32)(sizeof(ESAL_UINT32) << 2)

/* Define for size of 1 unsigned long */
#define         ESAL_GE_MEM_1_X_32BIT_SIZE      (ESAL_UINT32)(sizeof(ESAL_UINT32))

/* Define macros used to align pointers / check for alignment based on data pointer size */
#if (ESAL_TS_DATA_PTR_SIZE <= 16)

/* Macro used to check if a value is aligned to the required boundary.
   Returns ESAL_TRUE if aligned; ESAL_FALSE if not aligned
   NOTE:  The required alignment must be a power of 2 (2, 4, 8, 16, 32, etc) */
#define         ESAL_GE_MEM_ALIGNED_CHECK(value, req_align)                             \
                        (((ESAL_UINT16)(value) & ((ESAL_UINT16)(req_align) - (ESAL_UINT16)1)) == (ESAL_UINT16)0)

/* Macro used to align a data pointer to next address that meets the specified
   required alignment.
   NOTE:  The required alignment must be a power of 2 (2, 4, 8, 16, 32, etc)
   NOTE:  The next aligned address will be returned regardless of whether the
          data pointer is already aligned. */
#define         ESAL_GE_MEM_PTR_ALIGN(ptr_addr, req_align)                              \
                        (ESAL_VOID *)(((ESAL_UINT16)(ptr_addr) & (ESAL_UINT16)(~((req_align) - 1))) +  \
                                  (ESAL_UINT16)(req_align))

#elif (ESAL_TS_DATA_PTR_SIZE <= 32)

/* Macro used to check if a value is aligned to the required boundary.
   Returns ESAL_TRUE if aligned; ESAL_FALSE if not aligned
   NOTE:  The required alignment must be a power of 2 (2, 4, 8, 16, 32, etc) */
#define         ESAL_GE_MEM_ALIGNED_CHECK(value, req_align)                             \
                        (((ESAL_UINT32)(value) & ((ESAL_UINT32)(req_align) - (ESAL_UINT32)1)) == (ESAL_UINT32)0)

/* Macro used to align a data pointer to next address that meets the specified
   required alignment.
   NOTE:  The required alignment must be a power of 2 (2, 4, 8, 16, 32, etc)
   NOTE:  The next aligned address will be returned regardless of whether the
          data pointer is already aligned. */
#define         ESAL_GE_MEM_PTR_ALIGN(ptr_addr, req_align)                              \
                        (ESAL_VOID *)(((ESAL_UINT32)(ptr_addr) & (ESAL_UINT32)(~((req_align) - 1))) +  \
                                  (ESAL_UINT32)(req_align))

#elif (ESAL_TS_DATA_PTR_SIZE <= 64)

#if (ESAL_TS_64BIT_SUPPORT == ESAL_TRUE)

/* Macro used to check if a value is aligned to the required boundary.
   Returns ESAL_TRUE if aligned; ESAL_FALSE if not aligned
   NOTE:  The required alignment must be a power of 2 (2, 4, 8, 16, 32, etc) */
#define         ESAL_GE_MEM_ALIGNED_CHECK(value, req_align)                             \
                        (((ESAL_UINT64)(value) & ((ESAL_UINT64)(req_align) - (ESAL_UINT64)1)) == (ESAL_UINT64)0)

/* Macro used to align a data pointer to next address that meets the specified
   required alignment.
   NOTE:  The required alignment must be a power of 2 (2, 4, 8, 16, 32, etc)
   NOTE:  The next aligned address will be returned regardless of whether the
          data pointer is already aligned. */
#define         ESAL_GE_MEM_PTR_ALIGN(ptr_addr, req_align)                              \
                        (ESAL_VOID *)(((ESAL_UINT64)(ptr_addr) & (ESAL_UINT64)(~((req_align) - 1))) +  \
                                  (ESAL_UINT64)(req_align))

#else

/* Generate error - toolset doesn't support 64-bit operations */
#error          Toolset does not support 64-bit operations (esal_ts_cfg.h)

#endif  /* ESAL_TS_64BIT_SUPPORT == ESAL_TRUE */

#endif  /* ESAL_TS_DATA_PTR_SIZE <= 16 */

/* Define error value for memory related functions */
#define         ESAL_GE_MEM_ERROR                       0xFFFFFFFFUL

/* Define values for memory access types */
#define         ESAL_INST                               0x00000001UL
#define         ESAL_DATA                               0x00000002UL
#define         ESAL_INST_AND_DATA                      (ESAL_INST|ESAL_DATA)

/* Define enumerated type for cache types */
typedef enum
{
    ESAL_NOCACHE,
    ESAL_WRITEBACK,
    ESAL_WRITETHROUGH

} ESAL_GE_CACHE_TYPE;

/* Define enumerated type for memory types */
typedef enum
{
    ESAL_ROM,
    ESAL_RAM,
    ESAL_MEM_MAPPED,
    ESAL_IO_MAPPED,
    ESAL_SHARED_RAM

} ESAL_GE_MEMORY_TYPE;

/* Define generic structure used to define memory region */
typedef struct
{
    ESAL_VOID                    *physical_start_addr;
    ESAL_VOID                    *virtual_start_addr;
    ESAL_UINT32                  size;
    ESAL_GE_CACHE_TYPE      cache_type;
    ESAL_GE_MEMORY_TYPE     mem_type;
    ESAL_UINT32                  access_type;

} ESAL_GE_MEM_REGION;

/* Externally accessible global data */
//extern  const   ESAL_GE_MEM_REGION      ESAL_DP_MEM_Region_Data[ESAL_DP_MEM_NUM_REGIONS];

/* Define memory clear */
#define        ESAL_GE_MEM_Clear(x,y)   ESAL_GE_MEM_Set(x,0,y)

/* Define all memory related function prototypes */
ESAL_VOID            *ESAL_GE_MEM_Initialize(ESAL_VOID);
ESAL_VOID            ESAL_GE_MEM_Set(ESAL_VOID *start, ESAL_INT value, ESAL_INT size);
ESAL_VOID            *ESAL_GE_MEM_Copy(ESAL_VOID *dst, const ESAL_VOID *src, ESAL_UINT32 size);
ESAL_UINT32          ESAL_GE_MEM_Remaining_Size_Get(ESAL_VOID *start_addr);
ESAL_VOID            *ESAL_GE_MEM_Next_Match_Find(ESAL_VOID                *start_addr,
                                             ESAL_GE_CACHE_TYPE  cache_type,
                                             ESAL_GE_MEMORY_TYPE mem_type,
                                             ESAL_UINT32              access_type);
ESAL_VOID            *ESAL_CO_MEM_Cache_Enable(ESAL_VOID *avail_mem);
ESAL_VOID            *ESAL_TS_MEM_First_Avail_Get(ESAL_VOID);
ESAL_VOID            ESAL_TS_MEM_BSS_Clear(ESAL_VOID);
ESAL_VOID            ESAL_TS_MEM_ROM_To_RAM_Copy(ESAL_VOID);
ESAL_VOID            ESAL_PR_MEM_Initialize(ESAL_VOID);
ESAL_VOID            *ESAL_PR_MEM_Cache_Enable(ESAL_VOID *avail_mem);

/* Define core cache memory macros to do nothing if cache is not available */
#if (ESAL_CO_CACHE_AVAILABLE == ESAL_FALSE)

#define    ESAL_CO_MEM_CACHE_ALL_INVALIDATE()
#define    ESAL_CO_MEM_ICACHE_ALL_INVALIDATE()
#define    ESAL_CO_MEM_DCACHE_ALL_INVALIDATE()
#define    ESAL_CO_MEM_ICACHE_INVALIDATE(addr, size)          (ESAL_VOID)((ESAL_UINT32)addr + size)
#define    ESAL_CO_MEM_DCACHE_INVALIDATE(addr, size)          (ESAL_VOID)((ESAL_UINT32)addr + size)
#define    ESAL_CO_MEM_DCACHE_ALL_FLUSH_INVAL()
#define    ESAL_CO_MEM_DCACHE_FLUSH_INVAL(addr, size)         (ESAL_VOID)((ESAL_UINT32)addr + size)

#endif /* ESAL_CO_CACHE_AVAILABLE == ESAL_FALSE */

/* Define processor cache memory macros to do nothing if cache is not available */
#if (ESAL_PR_CACHE_AVAILABLE == ESAL_FALSE)

#define    ESAL_PR_MEM_CACHE_ALL_INVALIDATE()
#define    ESAL_PR_MEM_ICACHE_ALL_INVALIDATE()
#define    ESAL_PR_MEM_DCACHE_ALL_INVALIDATE()
#define    ESAL_PR_MEM_ICACHE_INVALIDATE(addr, size)          (ESAL_VOID)((ESAL_UINT32)addr + size)
#define    ESAL_PR_MEM_DCACHE_INVALIDATE(addr, size)          (ESAL_VOID)((ESAL_UINT32)addr + size)
#define    ESAL_PR_MEM_DCACHE_ALL_FLUSH_INVAL()
#define    ESAL_PR_MEM_DCACHE_FLUSH_INVAL(addr, size)         (ESAL_VOID)((ESAL_UINT32)addr + size)

#endif /* ESAL_PR_CACHE_AVAILABLE == ESAL_FALSE */

/* Generic defines used for cache related routines */
#define         ESAL_GE_MEM_CACHE_ALL_INVALIDATE()                \
                    ESAL_CO_MEM_CACHE_ALL_INVALIDATE();           \
                    ESAL_PR_MEM_CACHE_ALL_INVALIDATE()

#define         ESAL_GE_MEM_ICACHE_ALL_INVALIDATE()               \
                    ESAL_CO_MEM_ICACHE_ALL_INVALIDATE();          \
                    ESAL_PR_MEM_ICACHE_ALL_INVALIDATE()

#define         ESAL_GE_MEM_DCACHE_ALL_INVALIDATE()               \
                    ESAL_CO_MEM_DCACHE_ALL_INVALIDATE();          \
                    ESAL_PR_MEM_DCACHE_ALL_INVALIDATE()

#define         ESAL_GE_MEM_ICACHE_INVALIDATE(addr, size)         \
                    ESAL_CO_MEM_ICACHE_INVALIDATE(addr, size);    \
                    ESAL_PR_MEM_ICACHE_INVALIDATE(addr, size)

#define         ESAL_GE_MEM_DCACHE_INVALIDATE(addr, size)         \
                    ESAL_CO_MEM_DCACHE_INVALIDATE(addr, size);    \
                    ESAL_PR_MEM_DCACHE_INVALIDATE(addr, size)

#define         ESAL_GE_MEM_DCACHE_ALL_FLUSH_INVAL()              \
                    ESAL_CO_MEM_DCACHE_ALL_FLUSH_INVAL();         \
                    ESAL_PR_MEM_DCACHE_ALL_FLUSH_INVAL()

#define         ESAL_GE_MEM_DCACHE_FLUSH_INVAL(addr, size)        \
                    ESAL_CO_MEM_DCACHE_FLUSH_INVAL(addr, size);   \
                    ESAL_PR_MEM_DCACHE_FLUSH_INVAL(addr, size)

#endif  /* ESAL_GE_MEM_DEFS_H */
