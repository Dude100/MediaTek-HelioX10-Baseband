/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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
 *   mpu_mtk_mmu_v2.h
 *
 * Project:
 * --------
 *   MOLY Software
 *
 * Description:
 * ------------
 *   Header file for MTK MMU V2
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MPU_MTK_MMU_V2_INT_H__
#define __MPU_MTK_MMU_V2_INT_H__

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "cache_hw_int.h"
#include "cache_sw_int.h"
    
#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

#if defined(__MTK_MMU_V2__)
/******************************************************************
 * Define enums
 ******************************************************************/
/* Region size enum */
typedef enum RGN_SIZE_T
{
    RGN_SIZE_64KB  = 15,  // (default)
    RGN_SIZE_128KB = 16,
    RGN_SIZE_256KB = 17,
    RGN_SIZE_512KB = 18,
    RGN_SIZE_1MB   = 19,
    RGN_SIZE_2MB   = 20,
    RGN_SIZE_4MB   = 21,
    RGN_SIZE_8MB   = 22,
    RGN_SIZE_16MB  = 23,
    RGN_SIZE_32MB  = 24,
}RGN_SIZE_TYPE;

/* Region access permission setting */
typedef enum PROT_REGION_ATTRIBUTE_T
{
    //Permission control
    MPU_NO_ACCESS  = 0x00000000,
    MPU_WO         = 0x00000040,
    MPU_RO         = 0x00000080,  // (default)
    MPU_RW         = 0x000000C0,
} PROT_REGION_ATTRIBUTE_TYPE;

/* Region cacheability setting */
typedef enum CACHE_REGION_T
{
    // Cacheability control
    MPU_NON_CACHEABLE = 0x00000000,  // (default)
    MPU_CACHEABLE     = 0x00000040,
} CACHE_REGION_TYPE;

/******************************************************************
 * Define constants
 ******************************************************************/
/* Max MPU regions number*/
/* MTK MMU V2 has 8 regions */
#define MPU_REGION_NUM                8
#define MPU_REGION_MAX_SIZE_TYPE      RGN_SIZE_32MB
#define MPU_REGION_MIN_SIZE_TYPE      RGN_SIZE_64KB

#define MPU_REGION_SP_KERNEL         (MPU_REGION_NUM -1)    /* Stack Protect in KERN Mode */
#define MPU_REGION_SP_USER           (MPU_REGION_NUM -2)    /* Stack Protect in User Mode */

#define MPU_DUMP_MAGIC               (kal_uint32)(0x4D505500) // "MPU"

/******************************************************************
 * Define macros
 ******************************************************************/
#define ENABLE_MPU() DRV_WriteReg32(ARM7CACHE_CONTROL_REG, (DRV_Reg32(ARM7CACHE_CONTROL_REG) | 0x00000002) )
/* [Attention] In MTK6290 ARM7, default memory access is RO so should carefully deal with DISABLE_MPU */
#define DISABLE_MPU()  DRV_WriteReg32(ARM7CACHE_CONTROL_REG, (DRV_Reg32(ARM7CACHE_CONTROL_REG) & (~0x00000002)) )
#define IS_MPU_ENABLED() ((DRV_Reg32(ARM7CACHE_CONTROL_REG) & 0x00000002) >> 1)

#define ENABLE_CACHE() DRV_WriteReg32(ARM7CACHE_CONTROL_REG, (DRV_Reg32(ARM7CACHE_CONTROL_REG) | 0x00000001) )
#define DISABLE_CACHE()  DRV_WriteReg32(ARM7CACHE_CONTROL_REG, (DRV_Reg32(ARM7CACHE_CONTROL_REG) & (~0x00000001)) )
#define IS_CACHE_ENABLED() (DRV_Reg32(ARM7CACHE_CONTROL_REG) & 0x00000001)

#define SET_MPU_PROT_REGION( _region_num, _base, _size_type, _attribute_type, _en ) \
        DRV_WriteReg32( ARM7CACHE_MPU_PROT_REG( _region_num ), ((_base) | (_attribute_type) | ((_size_type-MPU_REGION_MIN_SIZE_TYPE)<<1) | (_en)) )

#define SET_MPU_CACHE_REGION( _region_num, _base, _size_type, _attribute_type, _en ) \
        DRV_WriteReg32( ARM7CACHE_MCU_CACHE_REG( _region_num ), ((_base) | (_attribute_type) | ((_size_type-MPU_REGION_MIN_SIZE_TYPE)<<1) | (_en)) )

#define GET_MPU_PROT_REGION_ADDR(_region_num) (DRV_Reg32(ARM7CACHE_MPU_PROT_REG( _region_num )) & 0xFFFF0000)
#define GET_MPU_PROT_REGION_ATTRI(_region_num) (DRV_Reg32(ARM7CACHE_MPU_PROT_REG( _region_num )) & 0x000000C0)
#define GET_MPU_PROT_REGION_SIZE_TYPE(_region_num) (((DRV_Reg32(ARM7CACHE_MPU_PROT_REG( _region_num )) & 0x0000001E) >> 1) + MPU_REGION_MIN_SIZE_TYPE)
#define GET_MPU_PROT_REGION_ENABLE(_region_num) (DRV_Reg32(ARM7CACHE_MPU_PROT_REG( _region_num )) & 0x00000001)

#define GET_MPU_CACHE_REGION_ADDR(_region_num) (DRV_Reg32(ARM7CACHE_MCU_CACHE_REG( _region_num )) & 0xFFFF0000)
#define GET_MPU_CACHE_REGION_CEN(_region_num) (DRV_Reg32(ARM7CACHE_MCU_CACHE_REG( _region_num )) & 0x00000040)
#define GET_MPU_CACHE_REGION_SIZE_TYPE(_region_num) (((DRV_Reg32(ARM7CACHE_MCU_CACHE_REG( _region_num )) & 0x0000001E) >> 1) + MPU_REGION_MIN_SIZE_TYPE)
#define GET_MPU_CACHE_REGION_ENABLE(_region_num) (DRV_Reg32(ARM7CACHE_MCU_CACHE_REG( _region_num )) & 0x00000001)

/*******************************************************************************
 * Define macros: for ARM7L1C special functions
 *   1. MCU_ENTER_POWER_SAVING_MODE: A bit of MTK-based WFI implemented in L1C
 *   2. ENABLE_DSP_INTERRUPTS: A bit for mask/unmask 3 DSP interrupts
 ******************************************************************************/
#define MCU_ENTER_POWER_SAVING_MODE() (DRV_WriteReg32(ARM7CACHE_MISC_REG, DRV_Reg32(ARM7CACHE_MISC_REG) | 0x1))
#define ENABLE_DSP_INTERRUPTS() (DRV_WriteReg32(ARM7CACHE_MISC_REG, DRV_Reg32(ARM7CACHE_MISC_REG) | 0x8))
#define DISABLE_DSP_INTERRUPTS() (DRV_WriteReg32(ARM7CACHE_MISC_REG, DRV_Reg32(ARM7CACHE_MISC_REG) & (~0x8)))

#if 0 //def __STACK_ALIGN_MPU__
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
#else  /* else of __STACK_ALIGN_MPU__ */
#define CPU_SET_STACK_MPU_PROTECT(region_num, stk_bndy)
#define CPU_SAVE_STACK_MPU_PROTECT(region_num, mpu_set)
#define CPU_RESTORE_STACK_MPU_PROTECT(mpu_set)
#endif /* end of "else of __STACK_ALIGN_MPU__" */

/******************************************************************
 * Define date structures
 ******************************************************************/
/* MPU setting for one protection region */
typedef struct PROT_REGION_SETTING_T
{
   kal_uint32                 addr;                /* Region base address */
   RGN_SIZE_TYPE              size;                /* Region range (size type) */
   kal_uint32                 rgn_no;              /* Region number */
   PROT_REGION_ATTRIBUTE_TYPE attribute;           /* Region attrubute */
   kal_uint32                 enable;              /* Region Enable/Disable */
} PROT_REGION_SETTING_TYPE;

/* MPU setting for one cache region */
typedef struct CACHE_REGION_SETTING_T
{
   kal_uint32                 addr;                /* Region base address */
   RGN_SIZE_TYPE              size;                /* Region range (size type) */
   kal_uint32                 rgn_no;              /* Region number */
   CACHE_REGION_TYPE          cen;                 /* Region attrubute */
   kal_uint32                 enable;              /* Region Enable/Disable */
} CACHE_REGION_SETTING_TYPE;

/* MPU Setting Dump Data Structure */
typedef struct MPU_REGION_T
{
    kal_uint32            Region_Base_Address;
    kal_uint32            Region_Size;
    kal_uint32            Region_Access_Control;  
    kal_uint32            Region_Enable;
} _MPU_REGION;
typedef struct MPU_DUMP_T
{
    kal_uint32            magic_pattern;                /* Magic pattern to check if this dump data is valid */    
    _MPU_REGION           prot_region[MPU_REGION_NUM];  /* Setting for each protection region */
    _MPU_REGION           cache_region[MPU_REGION_NUM]; /* Setting for each cache region */
} MPU_DUMP;

/******************************************************************
 * Export Function Prototypes
 ******************************************************************/
extern void MpuPreInit(void);
extern void MPU_Init(void);
extern void mpu_clear_all_regions(void);
extern kal_bool mpu_dump(MPU_DUMP * mpu_dump_output);
extern kal_bool mpu_get_prot_region(kal_uint32 index, PROT_REGION_SETTING_TYPE * region_setting);
extern kal_bool mpu_get_cache_region(kal_uint32 index, CACHE_REGION_SETTING_TYPE * region_setting);
extern void mpu_set_prot_region_primitive(kal_uint32 index, kal_uint32 addr, RGN_SIZE_TYPE region_size, PROT_REGION_ATTRIBUTE_TYPE attribute, kal_uint32 enable);
extern void mpu_set_cache_region_primitive(kal_uint32 index, kal_uint32 addr, RGN_SIZE_TYPE region_size, CACHE_REGION_TYPE cen, kal_uint32 enable);

extern void CACHE_FREE_RUN_CYCLE_COUNTER_INIT(void);
extern void CACHE_FREE_RUN_CYCLE_COUNTER_START(void);
extern void CACHE_FREE_RUN_CYCLE_COUNTER_PAUSE(void);
extern void CACHE_FREE_RUN_CYCLE_COUNTER_RESET(void);
extern kal_uint32 CACHE_FREE_RUN_CYCLE_COUNTER_GET_CYCLE(void);

#endif /* __MTK_MMU_V2_ */
#if defined(__cplusplus)
} // extern "C"
#endif /* __cplusplus */
#endif  /* __MPU_MTK_MMU_V2_INT_H__ */

