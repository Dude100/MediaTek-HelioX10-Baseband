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
 *   cache_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the functionality of L1 and L2 cache.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _CACHE_HW_H
#define _CACHE_HW_H

#if defined(MT6250) 

/* Cache control registers */
#define L1CACHE_BASE    (0xA0530000)
#define CACHE_CON       ((volatile kal_uint16 *)(L1CACHE_BASE+0x0000))
#define CACHE_OP        ((volatile kal_uint32 *)(L1CACHE_BASE+0x0004))
#define CACHE_HCNT0L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0008))
#define CACHE_HCNT0U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x000C))
#define CACHE_CCNT0L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0010))
#define CACHE_CCNT0U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0014))
#define CACHE_HCNT1L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0018))
#define CACHE_HCNT1U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x001C))
#define CACHE_CCNT1L    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0020))
#define CACHE_CCNT1U    ((volatile kal_uint32 *)(L1CACHE_BASE+0x0024))

/* MPU region registers */
#define MPU_CHANNEL_EN  ((volatile kal_uint32 *)(L1CACHE_BASE+0x002C))

#define MPU_BASE        (0xA0540000)
#define MPU_PROT0       ((volatile kal_uint32 *)(MPU_BASE+0x0000))
#define MPU_PROT1       ((volatile kal_uint32 *)(MPU_BASE+0x0004))
#define MPU_PROT2       ((volatile kal_uint32 *)(MPU_BASE+0x0008))
#define MPU_PROT3       ((volatile kal_uint32 *)(MPU_BASE+0x000C))
#define MPU_PROT4       ((volatile kal_uint32 *)(MPU_BASE+0x0010))
#define MPU_PROT5       ((volatile kal_uint32 *)(MPU_BASE+0x0014))
#define MPU_PROT6       ((volatile kal_uint32 *)(MPU_BASE+0x0018))
#define MPU_PROT7       ((volatile kal_uint32 *)(MPU_BASE+0x001C))
#define MPU_PROT8       ((volatile kal_uint32 *)(MPU_BASE+0x0020))
#define MPU_PROT9       ((volatile kal_uint32 *)(MPU_BASE+0x0024))
#define MPU_PROT10      ((volatile kal_uint32 *)(MPU_BASE+0x0028))
#define MPU_PROT11      ((volatile kal_uint32 *)(MPU_BASE+0x002C))
#define MPU_PROT12      ((volatile kal_uint32 *)(MPU_BASE+0x0030))
#define MPU_PROT13      ((volatile kal_uint32 *)(MPU_BASE+0x0034))
#define MPU_PROT14      ((volatile kal_uint32 *)(MPU_BASE+0x0038))
#define MPU_PROT15      ((volatile kal_uint32 *)(MPU_BASE+0x003C))

#define MPU_PROT0_END       ((volatile kal_uint32 *)(MPU_BASE+0x0040))
#define MPU_PROT1_END       ((volatile kal_uint32 *)(MPU_BASE+0x0044))
#define MPU_PROT2_END       ((volatile kal_uint32 *)(MPU_BASE+0x0048))
#define MPU_PROT3_END       ((volatile kal_uint32 *)(MPU_BASE+0x004C))
#define MPU_PROT4_END       ((volatile kal_uint32 *)(MPU_BASE+0x0050))
#define MPU_PROT5_END       ((volatile kal_uint32 *)(MPU_BASE+0x0054))
#define MPU_PROT6_END       ((volatile kal_uint32 *)(MPU_BASE+0x0058))
#define MPU_PROT7_END       ((volatile kal_uint32 *)(MPU_BASE+0x005C))
#define MPU_PROT8_END       ((volatile kal_uint32 *)(MPU_BASE+0x0060))
#define MPU_PROT9_END       ((volatile kal_uint32 *)(MPU_BASE+0x0064))
#define MPU_PROT10_END      ((volatile kal_uint32 *)(MPU_BASE+0x0068))
#define MPU_PROT11_END      ((volatile kal_uint32 *)(MPU_BASE+0x006C))
#define MPU_PROT12_END      ((volatile kal_uint32 *)(MPU_BASE+0x0070))
#define MPU_PROT13_END      ((volatile kal_uint32 *)(MPU_BASE+0x0074))
#define MPU_PROT14_END      ((volatile kal_uint32 *)(MPU_BASE+0x0078))
#define MPU_PROT15_END      ((volatile kal_uint32 *)(MPU_BASE+0x007C))

#define MPU_CACHE0      ((volatile kal_uint32 *)(MPU_BASE+0x0000))
#define MPU_CACHE1      ((volatile kal_uint32 *)(MPU_BASE+0x0004))
#define MPU_CACHE2      ((volatile kal_uint32 *)(MPU_BASE+0x0008))
#define MPU_CACHE3      ((volatile kal_uint32 *)(MPU_BASE+0x000C))
#define MPU_CACHE4      ((volatile kal_uint32 *)(MPU_BASE+0x0010))
#define MPU_CACHE5      ((volatile kal_uint32 *)(MPU_BASE+0x0014))
#define MPU_CACHE6      ((volatile kal_uint32 *)(MPU_BASE+0x0018))
#define MPU_CACHE7      ((volatile kal_uint32 *)(MPU_BASE+0x001C))
#define MPU_CACHE8      ((volatile kal_uint32 *)(MPU_BASE+0x0020))
#define MPU_CACHE9      ((volatile kal_uint32 *)(MPU_BASE+0x0024))
#define MPU_CACHE10      ((volatile kal_uint32 *)(MPU_BASE+0x0028))
#define MPU_CACHE11      ((volatile kal_uint32 *)(MPU_BASE+0x002C))
#define MPU_CACHE12      ((volatile kal_uint32 *)(MPU_BASE+0x0030))
#define MPU_CACHE13      ((volatile kal_uint32 *)(MPU_BASE+0x0034))
#define MPU_CACHE14      ((volatile kal_uint32 *)(MPU_BASE+0x0038))
#define MPU_CACHE15      ((volatile kal_uint32 *)(MPU_BASE+0x003C))

/* Address remapping Registers */
#define REMAP_BASE      (0xA0531000)
#define NCREMAP_HI0     ((volatile kal_uint32 *)(REMAP_BASE+0x0000))
#define NCREMAP_LO0     ((volatile kal_uint32 *)(REMAP_BASE+0x0004))
#define NCREMAP_HI1     ((volatile kal_uint32 *)(REMAP_BASE+0x0008))
#define NCREMAP_LO1     ((volatile kal_uint32 *)(REMAP_BASE+0x000C))
#endif   /* MT6250 */

#if defined(MT6290) && defined(__ARM7EJ_S__)
#if defined(__MTK_MMU_V2__)

/* Cache Control Registers */
#define ARM7CACHE_BASE                             (BASE_ADDR_ARM7CACHE)
#define ARM7CACHE_CONTROL_REG                      (ARM7CACHE_BASE + 0x0000)       // CACHE_CON
#define ARM7CACHE_OPERATION_REG                    (ARM7CACHE_BASE + 0x0004)       // L1C_COP
#define ARM7CACHE_HIT_CNTR_REG                     (ARM7CACHE_BASE + 0x0008)       // L1C_HIT_CNTR
#define ARM7CACHE_ACC_CNTR_REG                     (ARM7CACHE_BASE + 0x000C)       // L1C_ACC_CNTR
#define ARM7CACHE_MISS_CNTR_REG                    (ARM7CACHE_BASE + 0x0010)       // L1C_MISS_CNTR
#define ARM7CACHE_WBK_FILL_CYCLE_CNTR_REG          (ARM7CACHE_BASE + 0x0014)       // L1C_WBK_FILL_CNTR
#define ARM7CACHE_TCM_CNTR_REG                     (ARM7CACHE_BASE + 0x0018)       // L1C_TCM_CNTR
#define ARM7CACHE_CYCLE_CNTR_REG                   (ARM7CACHE_BASE + 0x001C)       // L1C_CYCLE_CNTR
#define ARM7CACHE_MISC_REG                         (ARM7CACHE_BASE + 0x0020)       // L1C_MISC_REG
/* MPU Region Registers */
#define ARM7CACHE_MPU_BASE                         (BASE_ADDR_ARM7CACHE_MPU)
#define ARM7CACHE_MPU_PROT_REG(n)                  (ARM7CACHE_MPU_BASE + (n << 2)) // L1C_MPU_PROT(n)
/* MCU Region Registers */
#define ARM7CACHE_MCU_BASE                         (BASE_ADDR_ARM7CACHE_MCU)
#define ARM7CACHE_MCU_CACHE_REG(n)                 (ARM7CACHE_MCU_BASE + (n << 2)) // L1C_MPU_CACHE(n)

#endif /* __MTK_MMU_V2__ */
#endif /* end of "defined(MT6290) && defined(__ARM7EJ_S__)" */

#endif /* _CACHE_HW_H */
