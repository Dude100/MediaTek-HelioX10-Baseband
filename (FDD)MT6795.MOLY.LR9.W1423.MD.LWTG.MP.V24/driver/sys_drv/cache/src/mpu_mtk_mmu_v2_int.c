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
 *   mpu_mtk_mmu_v2_int.c
 *
 * Project:
 * --------
 *   MOLY Software
 *
 * Description:
 * ------------
 *   This Module defines the functional of MTK MMU V2 MPU
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/*******************************************************************************
 * Whole file is wrapped in following macros 
 *******************************************************************************/
#if defined(__MTK_MMU_V2__)

/*******************************************************************************
 * Include header files.
 *******************************************************************************/
#include "kal_public_api.h"
#include "mpu.h"
#include "custom_scatstruct.h"
//#include "custom_EMI_release.h"     //For EMI_EXTSRAM_SIZE
#include "cache_sw_int.h"
#if !defined(__FUE__) && !defined(__UBL__)
#include "intrCtrl.h"
#endif /* !__FUE__ && !__UBL__ */

/*******************************************************************************
 * Define import functions and variables
 *******************************************************************************/

 /*******************************************************************************
 * Define global data.
 *******************************************************************************/
#if !defined(__FUE__) && !defined(__UBL__)
/* mpu_prot_region_record: Record MPU protection region usage, 
 * mpu_prot_region_record[x]==1 indicates protection region #x is in use */
static kal_uint32 mpu_prot_region_record __attribute__ ((section("COPRO_INTSRAM_RW")));
/* mpu_cache_region_record: Record MPU cache region usage, 
 * mpu_cache_region_record[x]==1 indicates cache region #x is in use */
static kal_uint32 mpu_cache_region_record __attribute__ ((section("COPRO_INTSRAM_RW")));

MPU_DUMP ARM_MPU_SETTING;
#endif /* !__FUE__ && !__UBL__ */


/*************************************************************************
* FUNCTION
*  mpu_check_prot_region_no_overlap / mpu_check_cache_region_no_overlap
*  -- Private
*
* DESCRIPTION
*  This function check if one mpu region is overlapping with existed region
*  If run overlapped, returns fail
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  kal_uint32 base_addr       The region base address
*  RGN_SIZE_TYPE size_type         The region size type
*
* RETURNS
*  KAL_TRUE:  for no overlap
*  KAL_FALSE: for overlap
*
*************************************************************************/
kal_bool mpu_check_prot_region_no_overlap(kal_uint32 rgn_num, kal_uint32 base_addr, RGN_SIZE_TYPE size_type)
{
    kal_uint32 region_record;
    kal_uint32 i;

    region_record = mpu_prot_region_record;
    for (i = 0; i < MPU_REGION_NUM; i++) {
        if ((region_record & 0x1) && (i != rgn_num)) {
            region_record >>= 1;
            // check overlap or not
            if( !((base_addr >= (GET_MPU_PROT_REGION_ADDR(i) + (1<<(GET_MPU_PROT_REGION_SIZE_TYPE(i)+1)))) || 
                ((base_addr + (1<<(size_type+1))) <= GET_MPU_PROT_REGION_ADDR(i))) ) {
                ASSERT(0);
                return KAL_FALSE;
            }
        } else {
            break;
        } // end if-else
    } // end for

    return KAL_TRUE;
}

kal_bool mpu_check_cache_region_no_overlap(kal_uint32 rgn_num, kal_uint32 base_addr, RGN_SIZE_TYPE size_type)
{
    kal_uint32 region_record;
    kal_uint32 i;

    region_record = mpu_cache_region_record;
    for (i = 0; i < MPU_REGION_NUM; i++) {
        if ((region_record & 0x1) && (i != rgn_num)) {
            region_record >>= 1;
            // check overlap or not
            if( !((base_addr >= (GET_MPU_CACHE_REGION_ADDR(i) + (1<<(GET_MPU_CACHE_REGION_SIZE_TYPE(i)+1)))) || 
                ((base_addr + (1<<(size_type+1))) <= GET_MPU_CACHE_REGION_ADDR(i))) ) {
                ASSERT(0);
                return KAL_FALSE;
            }
        } else {
            break;
        } // end if-else
    } // end for

    return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  mpu_set_prot_region_primitive / mpu_set_cache_region_primitive
*
* DESCRIPTION
*  This function setup one protect / cache region in MTK MMU V2 Cache
*
* NOTE
*  This function is designed for bootloader use
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  kal_uint32 index                                 Region index
*  kal_uint32 addr                                  Region base address
*  RGN_SIZE_TYPE region_size                        Region size
*  
*  PROT_REGION_ATTRIBUTE_TYPE attribute             Region attribute setting or
*  CACHE_REGION_TYPE cen                            Region attribute setting
*
*  kal_uint32 enable                    Enable this region: 0=>disable / Others=>enable
*
* RETURNS
*  None
*
*************************************************************************/
void mpu_set_prot_region_primitive(kal_uint32 index, kal_uint32 addr, RGN_SIZE_TYPE region_size, PROT_REGION_ATTRIBUTE_TYPE attribute, kal_uint32 enable)
{
    kal_uint32 en;
    /* 
     * NOTE: Input Constraint
     * 1. index < MPU_REGION_NUM (for MT6290_ARM7 MAX region = 8 )
     * 2. addr aligned with size (ex: a 64KB region must start at 64KB aligned address)
     *
     */
    ASSERT(index < MPU_REGION_NUM);
    ASSERT((addr&((1<<(region_size+1))-1))==0);
    mpu_check_prot_region_no_overlap(index, addr, region_size); // need to solve global variable in INTSRAM then can open

    en = (enable==0)?0:1;
    
    /* Start configure MPU regions */
    SET_MPU_PROT_REGION(index, addr, region_size, attribute, en);
}

void mpu_set_cache_region_primitive(kal_uint32 index, kal_uint32 addr, RGN_SIZE_TYPE region_size, CACHE_REGION_TYPE cen, kal_uint32 enable)
{
    kal_uint32 en;
    /* 
     * NOTE: Input Constraint
     * 1. index < MPU_REGION_NUM (for MT6290_ARM7 MAX region = 8 )
     * 2. addr aligned with size (ex: a 64KB region must start at 64KB aligned address)
     *
     */
    ASSERT(index < MPU_REGION_NUM);
    ASSERT((addr&((1<<(region_size+1))-1))==0);
    mpu_check_cache_region_no_overlap(index, addr, region_size);
    
    en = (enable==0)?0:1;
    
    /* Start configure MPU regions */
    SET_MPU_CACHE_REGION(index, addr, region_size, cen, en);
}

/*************************************************************************
* FUNCTION
*  mpu_clear_all_regions
*  -- Public
*
* DESCRIPTION
*  This function reset all region settings to zero
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
* RETURNS
*  None
*
*************************************************************************/
void mpu_clear_all_regions(void)
{
    kal_uint32 i;

    mpu_prot_region_record = 0;  // in TCM
    mpu_cache_region_record = 0; // in TCM
    
    for(i=0;i<MPU_REGION_NUM;i++)
    {
        mpu_set_prot_region_primitive(i, 0, RGN_SIZE_64KB, MPU_RO, 0);
        mpu_set_cache_region_primitive(i, 0, RGN_SIZE_64KB, MPU_NON_CACHEABLE, 0);      
    }

    return;
}

#if !defined(__FUE__) && !defined(__UBL__)
/*************************************************************************
* FUNCTION
*  mpu_dump
*  -- Public
*
* DESCRIPTION
*  This function dump current ARM mpu settings
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  MPU_DUMP * mpu_dump_output       The buffer for mpu settings dump
*
* RETURNS
*  KAL_TRUE:  for success
*  KAL_FALSE: for failure  
*
*************************************************************************/
kal_bool mpu_dump(MPU_DUMP * mpu_dump_output)
{
    kal_uint32 i;
    volatile MPU_DUMP * internal_dump_ptr;
    
    internal_dump_ptr = (volatile MPU_DUMP *)mpu_dump_output;
    for(i=0;i<MPU_REGION_NUM;i++)
    {
        // dump protection region i
        internal_dump_ptr->prot_region[i].Region_Base_Address = GET_MPU_PROT_REGION_ADDR(i);  
        internal_dump_ptr->prot_region[i].Region_Size = GET_MPU_PROT_REGION_SIZE_TYPE(i); 
        internal_dump_ptr->prot_region[i].Region_Access_Control = GET_MPU_PROT_REGION_ATTRI(i); 
        internal_dump_ptr->prot_region[i].Region_Enable = GET_MPU_PROT_REGION_ENABLE(i); 

        // dump cache region i
        internal_dump_ptr->cache_region[i].Region_Base_Address = GET_MPU_CACHE_REGION_ADDR(i);  
        internal_dump_ptr->cache_region[i].Region_Size = GET_MPU_CACHE_REGION_SIZE_TYPE(i); 
        internal_dump_ptr->cache_region[i].Region_Access_Control = GET_MPU_CACHE_REGION_CEN(i); 
        internal_dump_ptr->cache_region[i].Region_Enable = GET_MPU_CACHE_REGION_ENABLE(i); 
    }
    internal_dump_ptr->magic_pattern = MPU_DUMP_MAGIC;
    return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  mpu_setup_prot_region / mpu_setup_cache_region
*  -- Private
*
* DESCRIPTION
*  This function setup one protection / cache region by MPU_SETTING to MTK MMU V2 Cache
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  PROT_/CACHE_REGION_SETTING_TYPE * region_setting       The region setting values
*
* RETURNS
*  KAL_TRUE:  for success
*  KAL_FALSE: for failure  
*
*************************************************************************/
static kal_bool mpu_setup_prot_region(const PROT_REGION_SETTING_TYPE * region_setting)
{
    kal_uint32 interruptMask;

    /* Parameter Checking */
    if(region_setting->rgn_no >= MPU_REGION_NUM)
    {
        /* Incorrect region number */
        ASSERT(0);
    }
    if(region_setting->size > MPU_REGION_MAX_SIZE_TYPE || region_setting->size < MPU_REGION_MIN_SIZE_TYPE)
    {
        /* Incorrect region size */
        ASSERT(0);
    } 
    mpu_check_prot_region_no_overlap(region_setting->rgn_no, region_setting->addr, region_setting->size);
    
    interruptMask = SaveAndSetIRQMask();
    /* Start configure MPU region */
    SET_MPU_PROT_REGION(region_setting->rgn_no, region_setting->addr, region_setting->size, region_setting->attribute, region_setting->enable);
    RestoreIRQMask(interruptMask);
    
    return KAL_TRUE;
}

static kal_bool mpu_setup_cache_region(const CACHE_REGION_SETTING_TYPE * region_setting)
{
    kal_uint32 interruptMask;

    /* Parameter Checking */
    if(region_setting->rgn_no >= MPU_REGION_NUM)
    {
        /* Incorrect region number */
        ASSERT(0);
    }
    if(region_setting->size > MPU_REGION_MAX_SIZE_TYPE || region_setting->size < MPU_REGION_MIN_SIZE_TYPE)
    {
        /* Incorrect region size */
        ASSERT(0);
    } 
    mpu_check_cache_region_no_overlap(region_setting->rgn_no, region_setting->addr, region_setting->size);
    
    interruptMask = SaveAndSetIRQMask();
    /* Start configure MPU region */
    SET_MPU_CACHE_REGION(region_setting->rgn_no, region_setting->addr, region_setting->size, region_setting->cen, region_setting->enable);
    RestoreIRQMask(interruptMask);
    
    return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  mpu_get_prot_region / mpu_get_cache_region
*  -- Public
*
* DESCRIPTION
*  This function get one protect / cache region setting by protect / cache region number
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  kal_uint32 region_idx                                   The region index
*  PROT_/CACHE REGION_SETTING_TYPE * region_setting        The region setting values
*
* RETURNS
*  KAL_TRUE:  for success
*  KAL_FALSE: for failure  
*
*************************************************************************/
kal_bool mpu_get_prot_region(kal_uint32 index, PROT_REGION_SETTING_TYPE * region_setting)
{
    /* Parameter Checking */
    if(index >= MPU_REGION_NUM)
    {
        /* Incorrect region number */
        ASSERT(0);
    }

    region_setting->addr = GET_MPU_PROT_REGION_ADDR(index);
    region_setting->size = GET_MPU_PROT_REGION_SIZE_TYPE(index);
    region_setting->attribute = GET_MPU_PROT_REGION_ATTRI(index); 
    region_setting->enable = GET_MPU_PROT_REGION_ENABLE(index);
    
    return KAL_TRUE;
}

kal_bool mpu_get_cache_region(kal_uint32 index, CACHE_REGION_SETTING_TYPE * region_setting)
{
    /* Parameter Checking */
    if(index >= MPU_REGION_NUM)
    {
        /* Incorrect region number */
        ASSERT(0);
    }

    region_setting->addr = GET_MPU_CACHE_REGION_ADDR(index);
    region_setting->size = GET_MPU_CACHE_REGION_SIZE_TYPE(index);
    region_setting->cen = GET_MPU_CACHE_REGION_CEN(index); 
    region_setting->enable = GET_MPU_CACHE_REGION_ENABLE(index);
    
    return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  mpu_get_free_prot_region / mpu_get_free_cache_region
*  -- Private
*
* DESCRIPTION
*  This function registers one mpu region for using
*  If run out of mpu regions, returns fail
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  kal_uint32 * region       The registered region number
*
* RETURNS
*  KAL_TRUE:  for success
*  KAL_FALSE: for failure  
*
*************************************************************************/
kal_bool mpu_get_free_prot_region(kal_uint32 * region)
{
    kal_uint32 region_record;
    kal_uint32 interrupt;
    kal_uint32 i;

    /* Check global region record, try to find one free region */
    interrupt = SaveAndSetIRQMask();
    region_record = mpu_prot_region_record;
    for (i = 0; i < MPU_REGION_NUM; i++) {
        if (region_record & 0x1) {
            region_record >>= 1;
        } else {
            break;
        } // end if-else
    } // end for

    /* if no free region is available, returns fail */
    if (i >= MPU_REGION_NUM) {
        RestoreIRQMask(interrupt);
        return KAL_FALSE;
    }
    
    *region = i;
    mpu_prot_region_record |= (0x1<<i);
    RestoreIRQMask(interrupt);
    return KAL_TRUE;
}

kal_bool mpu_get_free_cache_region(kal_uint32 * region)
{
    kal_uint32 region_record;
    kal_uint32 interrupt;
    kal_uint32 i;

    /* Check global region record, try to find one free region */
    interrupt = SaveAndSetIRQMask();
    region_record = mpu_cache_region_record;
    for (i = 0; i < MPU_REGION_NUM; i++) {
        if (region_record & 0x1) {
            region_record >>= 1;
        } else {
            break;
        } // end if-else
    } // end for

    /* if no free region is available, returns fail */
    if (i >= MPU_REGION_NUM) {
        RestoreIRQMask(interrupt);
        return KAL_FALSE;
    }
    
    *region = i;
    mpu_cache_region_record |= (0x1<<i);
    RestoreIRQMask(interrupt);
    return KAL_TRUE;
}

/*************************************************************************
* FUNCTION
*  mpu_make_prot_region / mpu_make_cache_region
*  -- Private
*
* DESCRIPTION
*  This function setup one region by definining the address, size, acctribute/cen etc..
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  kal_uint32 base_addr                   Region base address, must align with size
*  RGN_SIZE_TYPE region_size              Region size
*  REGION_ATTRIBUTE_TYPE attribute        Region attribute
*
* RETURNS
*  KAL_TRUE:  for success
*  KAL_FALSE: for failure  
*
*************************************************************************/
static kal_bool mpu_make_prot_region(kal_uint32 base_addr, RGN_SIZE_TYPE region_size, PROT_REGION_ATTRIBUTE_TYPE attribute)
{
    PROT_REGION_SETTING_TYPE region_setting = {0};
    kal_uint32 addr_mask;

    /* 1. Get one free channel */
    if ( mpu_get_free_prot_region(&(region_setting.rgn_no)) != KAL_TRUE) {
        /* get free region fail */
        ASSERT(0);
    }

    /* 2. Check base address align with size */
    addr_mask = (1 << (region_size + 1)) - 1;
    if (base_addr & addr_mask) {
        /* Base address does not align with region size */
        ASSERT(0);
    }

    /* 3. Prepare PROT_REGION_SETTING_TYPE by input parameters */
    region_setting.addr = base_addr;
    region_setting.size = region_size;
    region_setting.attribute = attribute;
    region_setting.enable = 1;
    
    /* 4. Call mpu_setup_prot_region to set in MTK_MMU_V2 Cache */
    return mpu_setup_prot_region(&region_setting);
}

static kal_bool mpu_make_cache_region(kal_uint32 base_addr, RGN_SIZE_TYPE region_size, CACHE_REGION_TYPE cen)
{
    CACHE_REGION_SETTING_TYPE region_setting = {0};
    kal_uint32 addr_mask;

    /* 1. Get one free channel */
    if ( mpu_get_free_cache_region(&(region_setting.rgn_no)) != KAL_TRUE) {
        /* get free region fail */
        ASSERT(0);
    }

    /* 2. Check base address align with size */
    addr_mask = (1 << (region_size + 1)) - 1;
    if (base_addr & addr_mask) {
        /* Base address does not align with region size */
        ASSERT(0);
    }

    /* 3. Prepare CACHE_REGION_SETTING_TYPE by input parameters */
    region_setting.addr = base_addr;
    region_setting.size = region_size;
    region_setting.cen = cen;
    region_setting.enable = 1;
    
    /* 4. Call mpu_setup_cache_region to set in MTK_MMU_V2 Cache */
    return mpu_setup_cache_region(&region_setting);
}


/*************************************************************************
* FUNCTION
*  mpu_reset_last_prot_region / mpu_reset_last_cache_region
*  -- Private
*
* DESCRIPTION
*  This function free and reset last allocated region
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  NONE
*
* RETURNS
*  NONE
*
*************************************************************************/
void mpu_reset_last_prot_region(void)
{
    kal_uint32 i;
    kal_uint32 region_record = mpu_prot_region_record;
    
    if (region_record == 0) {
        return;  
    } else {
        for (i = 0; i < MPU_REGION_NUM; i++) {
            if (region_record & 0x1) {
                region_record >>= 1;
            } else {
                mpu_prot_region_record &= ~((kal_uint32)(1<<(i-1)));
                break;
            } // end if-else
        }// end for
    } // end if-else
    return;
}

void mpu_reset_last_cache_region(void)
{
    kal_uint32 i;
    kal_uint32 region_record = mpu_cache_region_record;
    
    if (region_record == 0) {
        return;  
    } else {
        for (i = 0; i < MPU_REGION_NUM; i++) {
            if (region_record & 0x1) {
                region_record >>= 1;
            } else {
                mpu_cache_region_record &= ~((kal_uint32)(1<<(i-1)));
                break;
            } // end if-else
        } // end for
    } // endif-else
    return;
}

/*************************************************************************
* FUNCTION
*  mpu_auto_make_prot_region / mpu_auto_make_cache_region
*  -- Private
*
* DESCRIPTION
*  This function setup one region by definining the address, size, acctribute/cen etc..
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  kal_uint32 base_addr                   Region base address, must align with size
*  kal_uint32 length                      Region size
*  
*  PROT_REGION_ATTRIBUTE_TYPE attribute   Region attribute setting or
*  CACHE_REGION_TYPE cen                  Region attribute setting
*
*  kal_uint32 mode                        0: find a region smaller/equal than target
*                                      else: find a region larger/equal than target
*
* RETURNS
*  kal_uint32: Final region upper-bound
*
*************************************************************************/
kal_uint32 mpu_auto_make_prot_region(kal_uint32 base_addr, kal_uint32 length, PROT_REGION_ATTRIBUTE_TYPE attribute, kal_uint32 mode)
{
    kal_uint32 final_addr=0, temp_length;
    RGN_SIZE_TYPE final_len;
    kal_uint32 i, k;

    /**************************** 
     * mode  0: Fit smaller/equal
     * mode!=1: Fit larger/equal
     ****************************/

    for (k = MPU_REGION_MIN_SIZE_TYPE; k <= MPU_REGION_MAX_SIZE_TYPE; k++) {
        i = (1<<(k+1));
        temp_length = (base_addr & (i-1)) + length;
        if (i == temp_length) {
            final_len = k;
            final_addr = base_addr & ~(i-1);
            break;
        } else if (i > temp_length) {
            if (mode == 0) {
                if (k == MPU_REGION_MIN_SIZE_TYPE) {
                    // MPU auto make failed, find no suitable region
                    // length is too small to find a smaller region size
                    ASSERT(0);
                } else {
                    final_len = k-1;
                }
            } else { // mode != 0
                final_len = k;
            }
            final_addr = base_addr & ~(i-1);
            break;
        } else if (k == MPU_REGION_MAX_SIZE_TYPE) {
            if (mode == 0) {
                final_len = k;
                final_addr = base_addr & ~(i-1);          
            } else {
                // MPU auto make failed, find no suitable region
                // length is too large to find a larger region size
                ASSERT(0);
            }
        } // end if-else
    } // end for

    // Setup region
    mpu_make_prot_region(final_addr, final_len, attribute);
    
    return (final_addr + ((0x1<<(final_len+1))-1));
}

kal_uint32 mpu_auto_make_cache_region(kal_uint32 base_addr, kal_uint32 length, CACHE_REGION_TYPE attribute, kal_uint32 mode)
{
    kal_uint32 final_addr=0, temp_length;
    RGN_SIZE_TYPE final_len;
    kal_uint32 i, k;

    /**************************** 
     * mode  0: Fit smaller/equal
     * mode!=1: Fit larger/equal
     ****************************/

    for (k = MPU_REGION_MIN_SIZE_TYPE; k <= MPU_REGION_MAX_SIZE_TYPE; k++) {
        i = (1<<(k+1));
        temp_length = (base_addr & (i-1)) + length;
        if (i == temp_length) {
            final_len = k;
            final_addr = base_addr & ~(i-1);
            break;
        } else if (i > temp_length) {
            if (mode == 0) {
                if (k == MPU_REGION_MIN_SIZE_TYPE) {
                    // MPU auto make failed, find no suitable region
                    // length is too small to find a smaller region size
                    ASSERT(0);
                } else {
                    final_len = k-1;
                }
            } else { // mode != 0
                final_len = k;
            }
            final_addr = base_addr & ~(i-1);
            break;
        } else if (k == MPU_REGION_MAX_SIZE_TYPE) {
            if (mode == 0) {
                final_len = k;
                final_addr = base_addr & ~(i-1);          
            } else {
                // MPU auto make failed, find no suitable region
                // length is too large to find a larger region size
                ASSERT(0);
            }
        } // end if-else
    } // end for
    
    // Setup region
    mpu_make_cache_region(final_addr, final_len, attribute);
    
    return (final_addr + ((0x1<<(final_len+1))-1));
}

/*************************************************************************
* FUNCTION
*  MpuPreInit
*  -- Public
*
* DESCRIPTION
*  This function used to pre-configure the MPU settings and enable Cache
*  for speed-up region init process
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
* RETURNS
*  None
*
*************************************************************************/
void MpuPreInit(void)
{
    // Since DSPTXRX is always at the end of all link section,
    // getting DSPTXRX base adding with its size is the total usage of memory size in run time
    kal_uint32 RAM_MAX_USAGE_SIZE = MAP2CREGVA(custom_get_DSPTXRX_Base()) + custom_get_DSPTXRX_MaxSize();
    // because of CR4 VRAM (next memory section user of ARM7 section in whole 6290 sections) is 1MB align
    kal_uint32 RAM_1MB_ALIGN_SIZE = (RAM_MAX_USAGE_SIZE&0xFFFFF) ? 
                                    ((RAM_MAX_USAGE_SIZE&(~0xFFFFF))+0x100000) : RAM_MAX_USAGE_SIZE;
    kal_uint32 temp_idx, temp_base_addr, temp_size, region_size, i;
    RGN_SIZE_TYPE temp_rgn_size_type;


    // NOTE: these code should be put in default R+W+ memory region!! ex: TCM in ARM7

    if (IS_CACHE_ENABLED()) {
        MTKL1CACHE_CleanAllCacheLines();
        MTKL1CACHE_InvalidAllCacheLines();
        DISABLE_CACHE();
    }
    // In MT6290 ARM7, should not disable MPU in run time,
    // or system stack write may cause data abort
    // It's because ARM7 default memory access policy is RO
    // However, since clear all region is only use in bootarm.S, all R/W (data/stack) is in TCM
    // Then, this time is okay to disable
    DISABLE_MPU();
    // clear all mpu regions (make them back to all zero)
    mpu_clear_all_regions();
	
    /*
     * MPU Region Setup of MT6290_ARM7
     * ============================================================================================
     * A: [RAM, Cacheable, R/W]      Base = 0x00000000  Size = RAM_1MB_ALIGN_SIZE  =>  R+W+, Cached
     * B: [RAM, Non-Cacheable, R/W]  Base = 0x40000000  Size = RAM_1MB_ALIGN_SIZE  =>  R+W+
     * ============================================================================================
     * PS. May use up to (MPU_REGION_NUM/2)'s region for A, B uses another half of MPUs.
     *     MCUs is needed only by A. No MPU/MCU covered space is R+W-, Non-Cached
     */
    temp_size = RAM_1MB_ALIGN_SIZE;
    temp_base_addr = 0;
    temp_idx = 0;
    temp_rgn_size_type = MPU_REGION_MAX_SIZE_TYPE;
    do {
        if ( temp_idx >= (MPU_REGION_NUM>>1)) {
            ASSERT(0); // ARM7 RAM usage is too big and there is not enough MPU regions to protect
        } // end if
        for (; temp_rgn_size_type >= MPU_REGION_MIN_SIZE_TYPE; temp_rgn_size_type--) {
            region_size = (0x1<<(temp_rgn_size_type+1));
            if (region_size <= temp_size) {
                // Set a region for A
                mpu_set_prot_region_primitive(  temp_idx, temp_base_addr, temp_rgn_size_type, MPU_RW,        1);
                mpu_set_cache_region_primitive( temp_idx, temp_base_addr, temp_rgn_size_type, MPU_CACHEABLE, 1);
                // Set a region for B
                mpu_set_prot_region_primitive(  temp_idx+(MPU_REGION_NUM>>1), MAP2CREGPA(temp_base_addr), temp_rgn_size_type, MPU_RW, 1);
                temp_base_addr += region_size;
                temp_size -= region_size;
                temp_idx++;
                break;
            } else {
                if (temp_rgn_size_type == MPU_REGION_MIN_SIZE_TYPE) {
                    ASSERT(0); // segment is too small to protect by ARM7 MPU region (< 64KB)  
                }
            } // end if-else
        } // end for
    } while (temp_size != 0);

    // Clear unused regions
    for (i = temp_idx; i < (MPU_REGION_NUM>>1); i++) {
        mpu_set_prot_region_primitive(i, 0, RGN_SIZE_64KB, MPU_RO, 0);
        mpu_set_prot_region_primitive(i+(MPU_REGION_NUM>>1), 0, RGN_SIZE_64KB, MPU_RO, 0);
    }
    for (i = temp_idx; i < MPU_REGION_NUM; i++) {
        mpu_set_cache_region_primitive(i, 0, RGN_SIZE_64KB, MPU_NON_CACHEABLE, 0);
    }

    // Enable MPU
    ENABLE_MPU();

    // Enable Cache
    ENABLE_CACHE();
    
    return;
}

/*************************************************************************
* FUNCTION
*  Mpu_Init
*  -- Public
*
* DESCRIPTION
*  This function sets the MPU to final version
*
* CALLS
*
* CALL BY
*
* PARAMETERS
*  None
* RETURNS
*  None
*
*************************************************************************/
void MPU_Init(void)
{
    kal_uint32 ROM_Base   = custom_get_1st_ROM_ROMBase();
    // kal_uint32 ROM_Length = custom_get_1st_ROM_ROMLength(); // we use RAM_Base as ROM_Length 1MB_ALIGN
    kal_uint32 RAM_Base   = custom_get_1st_ROM_RAMBase(); // == ROM_1MB_ALIGN_SIZE from ROM_Length
    // Since DSPTXRX is always at the end of all link section,
    // getting DSPTXRX base adding with its size is the total usage of memory size in run time
    kal_uint32 MEM_MAX_USAGE_SIZE = MAP2CREGVA(custom_get_DSPTXRX_Base()) + custom_get_DSPTXRX_MaxSize();
    // because of CR4 VRAM (next memory section user of ARM7 section in whole 6290 sections) is 1MB align
    kal_uint32 MEM_MAX_USAGE_1MB_ALIGN_SIZE = (MEM_MAX_USAGE_SIZE&0xFFFFF) ?
                                              ((MEM_MAX_USAGE_SIZE&(~0xFFFFF))+0x100000) : MEM_MAX_USAGE_SIZE;
    kal_uint32 RAM_Length = MEM_MAX_USAGE_1MB_ALIGN_SIZE - RAM_Base;
    kal_uint32 temp_rgn_num, temp_base_addr, temp_size, region_size, i, k;
    RGN_SIZE_TYPE temp_rgn_size_type;


    // NOTE: these code should be put in default executable memory region!! ex: TCM in ARM7

    if (IS_CACHE_ENABLED()) {
        MTKL1CACHE_CleanAllCacheLines();
        MTKL1CACHE_InvalidAllCacheLines();
        DISABLE_CACHE();
    }
    // In MT6290 ARM7, should not disable MPU in run time,
    // or system stack write may cause data abort
    // It's because ARM7 default memory access policy is RO
    // However, since clear all region is only use in bootarm.S, all R/W (data/stack) is in TCM
    // Then, this time is okay to disable
    DISABLE_MPU();
    // clear all mpu regions (make them back to all zero)
    mpu_clear_all_regions();

#ifndef DISABLE_MPU_RO_PROTECT
    /*
     * MPU Region Setup of MT6290_ARM7
     * =================================================================================================
     * A: [ROM, Cacheable, R]        Base = ROM_Base (0x00000000)  Size = RAM_Base    =>  (R+W-,) Cached
     * B: [RAM, Cacheable, R/W]      Base = RAM_Base               Size = RAM_Length  =>  R+W+, Cached
     * C: [RAM, Non-Cacheable, R/W]  Base = MAP2CREGPA(RAM_Base)   Size = RAM_Length  =>  R+W+
     * =================================================================================================
     * PS. May use up to (MPU_REGION_NUM/2)'s region for B, C uses another half of MPUs.
     *     MCUs is needed by A and B. No MPU/MCU covered space is R+W-(so, A don't need), Non-Cached
     */

    // call auto management of region creation
    // Set a region for A
    mpu_auto_make_cache_region( ROM_Base, RAM_Base, MPU_CACHEABLE, 0);

    temp_size = RAM_Length;
    temp_base_addr = RAM_Base;
#else /* end of "ifndef DISABLE_MPU_RO_PROTECT" */        
    /*
     * MPU Region Setup of MT6290_ARM7
     * =================================================================================================================
     * A: [RAM, Cacheable, R/W]      Base = ROM_Base (0x00000000)  Size = MEM_MAX_USAGE_1MB_ALIGN_SIZE  =>  R+W+, Cached
     * B: [RAM, Non-Cacheable, R/W]  Base = MAP2CREGPA(ROM_Base)   Size = MEM_MAX_USAGE_1MB_ALIGN_SIZE  =>  R+W+
     * =================================================================================================================
     * PS. May use up to (MPU_REGION_NUM/2)'s region for A, B uses another half of MPUs.
     *     MCUs is needed only by A. No MPU/MCU covered space is R+W-, Non-Cached
     */

    temp_size = MEM_MAX_USAGE_1MB_ALIGN_SIZE;
    temp_base_addr = ROM_Base;
#endif /* end of "ifdef DISABLE_MPU_RO_PROTECT" */

    temp_rgn_num = 0;
    while (temp_size != 0) {

        // check if the unused region is still enough
        if ( temp_rgn_num >= (MPU_REGION_NUM>>1)) {
            ASSERT(0); // ARM7 RAM usage is too big and there is not enough MPU regions to protect
        } // end if

        // find a begin region size with which base address aligned
        k = temp_base_addr;
        for (i = 0; ((k%2) == 0) && (i < (MPU_REGION_MAX_SIZE_TYPE+1)); i++, k=k>>1);
        if (i < (MPU_REGION_MIN_SIZE_TYPE+1)) {
            ASSERT(0); // the base_address is too small to align with the smallest MPU size
        }
        temp_rgn_size_type = i-1;
        // find a region size in which length size fit
        for (; temp_rgn_size_type >= MPU_REGION_MIN_SIZE_TYPE; temp_rgn_size_type--) {
            region_size = (0x1<<(temp_rgn_size_type+1));
            if (region_size <= temp_size) {

                // call auto management of region creation
                // Set a region for B
                mpu_auto_make_prot_region( temp_base_addr, region_size, MPU_RW, 0);
                temp_rgn_num++;
                mpu_auto_make_cache_region( temp_base_addr, region_size, MPU_CACHEABLE, 0);
                // Set a region for C
                mpu_auto_make_prot_region( MAP2CREGPA(temp_base_addr), region_size, MPU_RW, 0);

                // update for finding next region
                temp_base_addr += region_size;
                temp_size -= region_size; 

                break;
            } else {
                if (temp_rgn_size_type == MPU_REGION_MIN_SIZE_TYPE) {
                    ASSERT(0); // length size is too small to protect by ARM7 MPU region (< 64KB)  
                }
            } // end if-else
        } // end for
    } // end while       

    // Enable MPU
    ENABLE_MPU();

    // Enable Cache
    ENABLE_CACHE();
    
    // Start L1C Free-Run Cycle Counter
    CACHE_FREE_RUN_CYCLE_COUNTER_INIT();
    CACHE_FREE_RUN_CYCLE_COUNTER_START();

    // Dump final MPU settings for debug
    mpu_dump(&ARM_MPU_SETTING);
    
    return;
}
#endif /* !defined(__FUE__) && !defined(__UBL__) */

/*******************************************************
* CACHE_FREE_RUN_CYCLE_COUNTER_INIT() - Public
*   Initialize cache free-run cycle counter (disable and reset)
********************************************************/
void CACHE_FREE_RUN_CYCLE_COUNTER_INIT(void)
{
    DRV_WriteReg32(ARM7CACHE_CONTROL_REG, (DRV_Reg32(ARM7CACHE_CONTROL_REG) & (~0x00000100)));
    DRV_WriteReg32(ARM7CACHE_CONTROL_REG, (DRV_Reg32(ARM7CACHE_CONTROL_REG) | 0x00000200));
    DRV_WriteReg32(ARM7CACHE_CONTROL_REG, (DRV_Reg32(ARM7CACHE_CONTROL_REG) & (~0x00000200)));
}

/*******************************************************
* CACHE_FREE_RUN_CYCLE_COUNTER_START() - Public
*   Start cache free-run cycle counter counting
********************************************************/
void CACHE_FREE_RUN_CYCLE_COUNTER_START(void)
{
    DRV_WriteReg32(ARM7CACHE_CONTROL_REG, (DRV_Reg32(ARM7CACHE_CONTROL_REG) | 0x00000100));
}

/*******************************************************
* CACHE_FREE_RUN_CYCLE_COUNTER_PAUSE() - Public
*   Pause cache free-run cycle counter
********************************************************/
void CACHE_FREE_RUN_CYCLE_COUNTER_PAUSE(void)
{
    DRV_WriteReg32(ARM7CACHE_CONTROL_REG, (DRV_Reg32(ARM7CACHE_CONTROL_REG) & (~0x00000100)));
}

/*******************************************************
* CACHE_FREE_RUN_CYCLE_COUNTER_RESET() - Public
*   Reset cache free-run cycle counter
********************************************************/
void CACHE_FREE_RUN_CYCLE_COUNTER_RESET(void)
{
    DRV_WriteReg32(ARM7CACHE_CONTROL_REG, (DRV_Reg32(ARM7CACHE_CONTROL_REG) | 0x00000200));
    DRV_WriteReg32(ARM7CACHE_CONTROL_REG, (DRV_Reg32(ARM7CACHE_CONTROL_REG) & (~0x00000200)));
}

/*******************************************************
* CACHE_FREE_RUN_CYCLE_COUNTER_GET_CYCLE(kal_uint32 *cyc_count) - Public
*   Return current cache free-run cycle counter value
********************************************************/
kal_uint32 CACHE_FREE_RUN_CYCLE_COUNTER_GET_CYCLE(void)
{
    return DRV_Reg32(ARM7CACHE_CYCLE_CNTR_REG);
}

#endif /* __MTK_MMU_V2__ */
/*******************************************************************************
 * Whole file wrapper END
 *******************************************************************************/
