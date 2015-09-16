/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * nvram_gen_util.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for generating NVRAM information.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef NVRAM_NOT_PRESENT
/*
 * Include
 */
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <sys/io.h>

#include "nvram_auto_gen.h"
#if defined(__MMI_FMI__)
#include "nvram_user_defs.h"
#endif
#include "nvram_defs.h" /* NVRAM_MSP_ALIGNMENT_REMAINDER */
#include "custom_nvram_cat.h"
#include "custom_nvram_config.h"  /* __NVRAM_VENDOR_SUPPORT__ */
#include "nvram_editor_data_item.h"
#ifdef __NVRAM_PSEUDO_MERGE__
#include "nvram_pseudo_merge.h"
#endif

#include "nvram_internal.h"

#include "custom_nvram_int_config.h"

kal_uint32 custpack_total_to_verify = 0;

#ifdef __NVRAM_VENDOR_SUPPORT__
kal_uint32 nvram_vendor_reserve_size = NVRAM_MAX_VENDOR_LID_SIZE;
#endif

#ifdef __NVRAM_OTP__
kal_uint32 otp_total_to_verify = 0;
kal_uint32 otp_size_to_verify = 0;
#endif

kal_uint32 secupack_total_to_verify = 0;
kal_uint32 secupack_size_to_verify = 0;
kal_uint16 secupack_idx = 0;

#if defined(__NVRAM_SECURE_DATA_STORAGE__)
kal_uint32 sds_total_to_verify = 0;
kal_uint32 sds_size_to_verify = 0;
#endif

kal_uint32 nvram_gen_backup_size = 0;
kal_uint32 nvram_gen_backup_total = 0;

boot_mode_type system_boot_mode;


nvram_ltable_entry_struct *logical_data_item_table;
kal_uint32 nvram_gen_total_lid;

/* Fake free_ilm */
void free_int_ilm(ilm_struct *ilm_ptr, kal_char* file_name, kal_uint32 line)
{
}

#define IS_POWER_OF_2(v) ((v & (v - 1)) == 0)


ltable_entry_struct logical_data_item_table_internal[] =
{
    {
        NVRAM_EF_SYS_LID,
        NVRAM_EF_SYS_TOTAL,
        NVRAM_EF_SYS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_INTERNAL,
        NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE,
        "MT00",
        VER(NVRAM_EF_SYS_LID)
    },
#ifdef __NVRAM_SUPPORT_CUSTPACK__
    {
        NVRAM_EF_CUSTPACK_VERNO_LID,
        NVRAM_EF_CUSTPACK_VERNO_TOTAL,
        NVRAM_EF_CUSTPACK_VERNO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_INTERNAL,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_WRITEPROTECT,
        "MT02",
        VER(NVRAM_EF_CUSTPACK_VERNO_LID)
    },
#endif
#ifdef __SECURE_RO_ENABLE__    
    {
        NVRAM_EF_SECUPACK_VERNO_LID,
        NVRAM_EF_SECUPACK_VERNO_TOTAL,
        NVRAM_EF_SECUPACK_VERNO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_INTERNAL,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_WRITEPROTECT,
        "MT02",
        VER(NVRAM_EF_SECUPACK_VERNO_LID)
    },
#endif    
#ifdef __NVRAM_UNIT_TEST__
    {
        NVRAM_EF_NVRAM_UNIT_TEST_LID,
        NVRAM_EF_NVRAM_UNIT_TEST_TOTAL,
        NVRAM_EF_NVRAM_UNIT_TEST_SIZE,
        NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
#ifdef __SECURE_DATA_STORAGE__
        NVRAM_CATEGORY_INTERNAL,
#else
        NVRAM_CATEGORY_USER,
#endif
        NVRAM_ATTR_AVERAGE,
        "NV00",
        VER(NVRAM_EF_NVRAM_UNIT_TEST_LID)
    },
#endif
};

/*****************************************************************************
* FUNCTION
*  nvram_gen_assign_entry
* DESCRIPTION
*  construct table
* PARAMETERS
*  position    [IN]
*  ldi         [IN]
* RETURNS
*  none
*****************************************************************************/
void nvram_gen_assign_entry(nvram_ltable_entry_struct* ldi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 value;
    kal_uint32 section_size;
    
    kal_uint32 tbl_idx = 0, entry_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*  Step 1:  Adjust attr / Category
        Step 2:  Verify
        Step 3:  Statistics */
    
    //Tool check begin: nvram_pre_gen.pl check if it is same as nvram_assign_table_entry() and nvram_gen_assign_entry() 
    //***************************************************************************
    // Adjust Attr/Category I
    //     Do not need multiple attribute if nvram saved on nor flash
    //***************************************************************************
#if !defined(_NAND_FLASH_BOOTING_) && !defined(__FS_SYSDRV_ON_NAND__)
    if (ldi->LID != NVRAM_EF_SYS_LID)
    {
         NVRAM_TURNOFF_ATTR_MULTIPLE(ldi->attr);
    }
#endif

    //***************************************************************************
    // Adjust Attr/Category II
    //     MULTIPLE / BACKUP_RAW / BACKUP_FAT  are mutually exclusive
    //***************************************************************************
    if (NVRAM_IS_CATEGORY_CALIBRAT(ldi->category))
    {
    #if defined(__NVRAM_BACKUP_DISK_FAT__)
        ldi->attr &= ~NVRAM_ATTR_MULTIPLE;
        ldi->attr &= ~NVRAM_ATTR_BACKUP_RAW;
        ldi->attr |= NVRAM_ATTR_BACKUP_FAT;
    #elif defined(__NVRAM_BACKUP_DISK_RAW__)
        ldi->attr &= ~NVRAM_ATTR_MULTIPLE;
        ldi->attr |= NVRAM_ATTR_BACKUP_RAW;
        ldi->attr &= ~NVRAM_ATTR_BACKUP_FAT;
    #else
        #if !defined(__LOW_COST_SUPPORT_COMMON__) && !defined(__CCCIFS_SUPPORT__)
        ldi->attr |= NVRAM_ATTR_MULTIPLE;
        #endif
        ldi->attr &= ~NVRAM_ATTR_BACKUP_RAW;
        ldi->attr &= ~NVRAM_ATTR_BACKUP_FAT;
    #endif
    }

    //***************************************************************************
    // Adjust Attr/Category III
    //     Just apply to smartphone
    //     1: When AP side clean boot, nvram will reset all lid
    //     2: When Modern side restore factory, nvram only reset data item in NVD_DATA
    //        and don't care about data item in folder A & B
    //     3: So, turn off NVRAM_CATEGORY_FACTORY
    //***************************************************************************
#if defined(__CCCIFS_SUPPORT__)
    if (NVRAM_IS_CATEGORY_CALIBRAT(ldi->category))
    {
        NVRAM_TURNOFF_ATTR_FACTOY_RESET(ldi->attr);
    }
    if (NVRAM_IS_CATEGORY_IMPORTANT(ldi->category) || NVRAM_IS_CATEGORY_IMPORTANT_L4(ldi->category))
    {
        NVRAM_TURNOFF_ATTR_FACTOY_RESET(ldi->attr);
        ldi->attr |= NVRAM_ATTR_COMMITTED;
        ldi->attr |= NVRAM_ATTR_AUTO_RECOVER;
    }
#endif

    //***************************************************************************
    // Adjust Attr/Category IV
    //       OTP category cannot use with many attribute together. Because it cannot be reset
    //       OTP category also cannot use with other category together.
    //***************************************************************************
#ifdef __NVRAM_OTP__
    if (NVRAM_IS_CATEGORY_OTP(ldi->category))
    {
        //ldi->category = NVRAM_CATEGORY_OTP;
        ldi->attr &= ~(NVRAM_ATTR_WRITEPROTECT);
        ldi->attr &= ~(NVRAM_ATTR_MULTIPLE);
        ldi->attr &= ~(NVRAM_ATTR_MSP);
        ldi->attr &= ~(NVRAM_ATTR_SW_VERNO_RESET);
        ldi->attr &= ~(NVRAM_ATTR_FACTORY_RESET);
    }
#endif

    //***************************************************************************
    // Adjust Attr/Category V
    //      Add pseudo merge attribute
    //***************************************************************************
    /* Record data item will be restored (end) */
#ifdef __NVRAM_PSEUDO_MERGE__
    if (!NVRAM_IS_CATEGORY_INTERNAL(ldi->category) &&
        !NVRAM_IS_CATEGORY_SECUPACK(ldi->category) &&
        !NVRAM_IS_CATEGORY_IMPORTANT(ldi->category) &&
        !NVRAM_IS_CATEGORY_CALIBRAT(ldi->category) &&
    #ifdef __NVRAM_CUSTOM_SENSITIVE__
        !NVRAM_IS_CATEGORY_CUSTOM_SENSITIVE(ldi->category) &&
    #endif
    #ifdef __NVRAM_CUSTOM_DISK__
        !NVRAM_IS_CATEGORY_CUSTOM_DISK(ldi->category) &&
    #endif
          ((ldi->size + NVRAM_CHKSUM_SIZE) * ldi->total_records < NVRAM_CLUSTER_SIZE))
    {
        ldi->attr |= NVRAM_ATTR_PACKAGE;
    }

    if (NVRAM_IS_ATTR_PACKAGE(ldi->attr))
    {
        ldi->description = NULL;
        ldi->attr &= ~ (NVRAM_ATTR_MULTIPLE);
        ldi->attr &= ~ (NVRAM_ATTR_MSP);
    }
#endif

    //***************************************************************************
    // Adjust Attr/Category V
    //      Add multiple attribute with msp together
    //***************************************************************************
    if (ldi->attr & NVRAM_ATTR_MSP)
    {
    #ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
        /* we support msp with pseudo merge too, but do not turn on multiple in this case */
        if (!(ldi->attr & NVRAM_ATTR_PACKAGE))
        {
            ldi->attr |= NVRAM_ATTR_MULTIPLE;
        }
    #else
        ldi->attr &= ~(NVRAM_ATTR_MSP);
    #endif
    }

    //***************************************************************************
    // Adjust Attr/Category VI
    //      Add MSP, confidential, multiple with secupack item
    //***************************************************************************

    if (NVRAM_IS_CATEGORY_SECUPACK(ldi->category))
    {
    #ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
        ldi->attr |= NVRAM_ATTR_MSP;
    #endif
        ldi->attr |= NVRAM_ATTR_CONFIDENTIAL;
        ldi->attr |= NVRAM_ATTR_MULTIPLE;
    }

    //***************************************************************************
    // Adjust Attr/Category VII
    //      Add MSP, confidential, multiple with custom sensitve data
    //***************************************************************************

#ifdef __NVRAM_CUSTOM_SENSITIVE__
    if (NVRAM_IS_CATEGORY_CUSTOM_SENSITIVE(ldi->category))
    {
    #ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
        ldi->attr |= NVRAM_ATTR_MSP;
    #endif
        ldi->attr |= NVRAM_ATTR_CONFIDENTIAL;
        ldi->attr |= NVRAM_ATTR_MULTIPLE;
    }
#endif

    //***************************************************************************
    // Adjust Attr/Category VIII
    //      remove all attribute if the data is in custom disk
    //***************************************************************************
#ifdef __NVRAM_CUSTOM_DISK__
    if (NVRAM_IS_CATEGORY_CUSTOM_DISK(ldi->category))
    {
        ldi->attr = NVRAM_ATTR_AVERAGE;
    }
#endif

    //***************************************************************************
    // Adjust Attr/Category X
    //      1. Compress the data in MT table and it is in custpack
    //      2. Compress the default value of the data not in MT table
    //         and its default value is not zero default or ff default
	// coppress function had phaseout
    //***************************************************************************

    //***************************************************************************
    // Adjust Attr/Category XI
    //      Put Internal, Calibration, Important data into SDS
    //***************************************************************************
#if defined(__NVRAM_SECURE_DATA_STORAGE__)
    if (NVRAM_IS_CATEGORY_INTERNAL(ldi->category) ||
        NVRAM_IS_CATEGORY_CALIBRAT(ldi->category) ||
        NVRAM_IS_CATEGORY_IMPORTANT(ldi->category) ||
        NVRAM_IS_CATEGORY_IMPORTANT_L4(ldi->category))
    {
        ldi->category |= NVRAM_CATEGORY_BACKUP_SDS;
        ldi->attr |= NVRAM_ATTR_FACTORY_RESET;

        ldi->attr &= ~ NVRAM_ATTR_MULTIPLE;
        ldi->attr &= ~ NVRAM_ATTR_RING;
        ldi->attr &= ~ NVRAM_ATTR_PACKAGE;
        ldi->attr &= ~ NVRAM_ATTR_BACKUP_FAT;
        ldi->attr &= ~ NVRAM_ATTR_BACKUP_RAW;
    }
#endif
	//Tool check end: nvram_pre_gen.pl

    //***************************************************************************
    // Check I
    //     cannot put the data into two categories that are mutually exclusive
    //***************************************************************************

    value = (ldi->category &
             (NVRAM_CATEGORY_INTERNAL
             | NVRAM_CATEGORY_CALIBRAT
             | NVRAM_CATEGORY_IMPORTANT
             | NVRAM_CATEGORY_IMPORTANT_L4
            #ifdef __NVRAM_CUSTOM_SENSITIVE__
             | NVRAM_CATEGORY_CUSTOM_SENSITIVE
            #endif
            #ifdef __NVRAM_CUSTOM_DISK__
             | NVRAM_CATEGORY_CUSTOM_DISK
            #endif
             ));

    /* check if value is power of 2 */
    if (!IS_POWER_OF_2(value))
    {
        fprintf(stderr,
                "Category inernal & calibrate & important & sensitive can't be used at the same time!, %d, %s\n", ldi->LID, ldi->str_LID);
        exit(3); /* NVRAM_EXIT_CODE_ERROR */

    }


    //***************************************************************************
    // Check II
    //     cannot put the sds data with custom
    //***************************************************************************
#if defined(__NVRAM_SECURE_DATA_STORAGE__)
    if (NVRAM_IS_CATEGORY_BACKUP_SDS(ldi->category))
    {
        if (NVRAM_IS_CATEGORY_CUSTOM_SENSITIVE(ldi->category) ||
            NVRAM_IS_CATEGORY_CUSTOM_DISK(ldi->category)      ||
            NVRAM_IS_CATEGORY_OTP(ldi->category))
        {
            fprintf(stderr,"Error: Sds use with wrong category LID:%s Desc:%s category %d\n",
                ldi->str_LID, ldi->str_LID, ldi->category);

            exit(3); /* NVRAM_EXIT_CODE_ERROR */
        }

        if ((ldi->attr & NVRAM_ATTR_MULTIPLE)   ||
            (ldi->attr & NVRAM_ATTR_RING)       ||
            (ldi->attr & NVRAM_ATTR_PACKAGE)    ||
            (ldi->attr & NVRAM_ATTR_BACKUP_FAT) ||
            (ldi->attr & NVRAM_ATTR_BACKUP_RAW))
        {
            fprintf(stderr,"Error: Sds use with wrong attribute LID:%s Desc:%s attribute %d\n",
                ldi->str_LID, ldi->str_LID, ldi->attr);

            exit(3); /* NVRAM_EXIT_CODE_ERROR */
        }


    #ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
        if (ldi->attr & NVRAM_ATTR_MSP)
        {
                /* 16 byte alignment */
            section_size = ldi->size + NVRAM_CHKSUM_SIZE + NVRAM_MSP_ALIGNMENT_REMAINDER(ldi->size + NVRAM_CHKSUM_SIZE);
        }
        else
    #endif
        {
            section_size = ldi->size + NVRAM_CHKSUM_SIZE;
        }

        if (section_size * ldi->total_records > NVRAM_CUSTOM_CFG_MAX_RECORD_SIZE)
        {
            fprintf(stderr,"Error: Data is too large to put into sds LID:%s Desc:%s %d %d\n",
                ldi->str_LID, ldi->str_LID, ldi->size, ldi->total_records);

            exit(3); /* NVRAM_EXIT_CODE_ERROR */
        }
    }
#endif


    //***************************************************************************
    // Check (III)
    //     Cannot use zero default or ff default with multi default
    //***************************************************************************

    if (ldi->attr & NVRAM_ATTR_MULTI_DEFAULT)
    {
        if (strcmp(ldi->str_default_value, "NVRAM_EF_ZERO_DEFAULT") == 0 ||
            strcmp(ldi->str_default_value, "NVRAM_EF_FF_DEFAULT") == 0)
        {
            fprintf(stderr,
                "Cannot set ZERO_DEFAULT or FF_DEFAULT with multi_default!, %d, %s\n", ldi->LID, ldi->str_LID);
            exit(3);
        }
    }

    //***************************************************************************
    // Check (IV)
    //     The record size cannot bigger than the biggest control buffer
    //***************************************************************************
#ifndef __NVRAM_LARGE_RECORD_SIZE__

#ifdef __NVRAM_BIND_TO_CHIP_CIPHER__
    if (ldi->attr & NVRAM_ATTR_MSP)
    {
            /* 16 byte alignment */
        section_size = ldi->size + NVRAM_CHKSUM_SIZE + NVRAM_MSP_ALIGNMENT_REMAINDER(ldi->size + NVRAM_CHKSUM_SIZE);
    }
    else
#endif
    {
        section_size = ldi->size + NVRAM_CHKSUM_SIZE;
    }



    if (section_size > NVRAM_CUSTOM_CFG_MAX_RECORD_SIZE)
    {
        fprintf(stderr,
                "LID Size is too big!, %d, %s\n", ldi->LID, ldi->str_LID);
        exit(3);
    }
#endif

    //***************************************************************************
    // Check V
    //      Items in custpack cannot use zero default or ff default as the default value
    //***************************************************************************
    if (NVRAM_IS_CATEGORY_CUSTPACK(ldi->category))
    {
        if (strcmp(ldi->str_default_value, "NVRAM_EF_ZERO_DEFAULT") == 0 ||
            strcmp(ldi->str_default_value, "NVRAM_EF_FF_DEFAULT") == 0)
        {
            fprintf(stderr,
                "Cannot set ZERO_DEFAULT or FF_DEFAULT with custpack!, %d, %s\n", ldi->LID, ldi->str_LID);
            exit(3);

        }
    }

    //***************************************************************************
    //  Statistics I
    //      calculate the custpack
    //***************************************************************************
    if (NVRAM_IS_CATEGORY_CUSTPACK(ldi->category))
    {
        custpack_total_to_verify++;
    }
    //***************************************************************************
    //  Statistics II
    //      calculate the secupack
    //***************************************************************************

    if (NVRAM_IS_CATEGORY_SECUPACK(ldi->category))
    {
        secupack_total_to_verify++;

        if (ldi->attr & NVRAM_ATTR_MULTI_DEFAULT)
        {
            secupack_size_to_verify += ldi->size * ldi->total_records + NVRAM_CHKSUM_SIZE;
        }
        else
        {
            secupack_size_to_verify += ldi->size + NVRAM_CHKSUM_SIZE;
        }
    }

    //***************************************************************************
    //  Statistics III
    //      calculate the otp
    //***************************************************************************
#ifdef __NVRAM_OTP__
    if (NVRAM_IS_CATEGORY_OTP(ldi->category))
    {
        otp_total_to_verify++;
        otp_size_to_verify += ldi->size * ldi->total_records;
    }
#endif /* __NVRAM_OTP__ */


    //***************************************************************************
    //  Statistics IV
    //      calculate the vendor reserve size
    //***************************************************************************

#ifdef __NVRAM_VENDOR_SUPPORT__
    if (is_customregion)
    {
        kal_uint32 section_size = ldi->size * ldi->total_records + NVRAM_CHKSUM_SIZE;
        if (section_size < nvram_vendor_reserve_size)
        {
            nvram_vendor_reserve_size -= section_size;
        }
        else
        {
            fprintf(stderr,
                    "My dear, total size for vendor nvram shouldn't be larger than %d!\n", NVRAM_MAX_VENDOR_LID_SIZE);
            exit(3); /* NVRAM_EXIT_CODE_ERROR */
        }
    }
#endif /* __NVRAM_VENDOR_SUPPORT__ */

    //***************************************************************************
    //  Statistics IV
    //      calculate the vendor reserve size
    //***************************************************************************
#if defined(__NVRAM_SECURE_DATA_STORAGE__)
    if (NVRAM_IS_CATEGORY_BACKUP_SDS(ldi->category))
    {
        sds_total_to_verify++;
        sds_size_to_verify += (ldi->size + NVRAM_CHKSUM_SIZE + NVRAM_MSP_ALIGNMENT_REMAINDER(ldi->size + NVRAM_CHKSUM_SIZE)) * ldi->total_records;
    }
#endif

}

/*****************************************************************************
 * FUNCTION
 *  nvram_assign_cat_entry
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
static void nvram_gen_assign_cat_default_value(nvram_lid_enum position, nvram_cat_replace_setting* cat_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (cat_item->size != logical_data_item_table[position].size ||
        cat_item->total_records != logical_data_item_table[position].total_records)
    {
        return;
    }

    logical_data_item_table[position].default_value = cat_item->default_value;

    if (cat_item->is_multi_default)
    {
        logical_data_item_table[position].attr &= NVRAM_ATTR_MULTI_DEFAULT;
    }
    else
    {
        logical_data_item_table[position].attr &= ~NVRAM_ATTR_MULTI_DEFAULT;
    }
}

/*****************************************************************************
* FUNCTION
*  nvram_gen_construct_ltable
* DESCRIPTION
*  To construct ltable.
* PARAMETERS
*  None
* RETURNS
*  None
*****************************************************************************/
void nvram_gen_construct_ltable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern unsigned char nvram_ltable_begin, nvram_ltable_end;
    kal_uint32 i = 0, tbl_idx = 0, tbl_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    logical_data_item_table = (nvram_ltable_entry_struct *)&nvram_ltable_begin;
    tbl_size = (kal_uint32)(&nvram_ltable_end - &nvram_ltable_begin);
    nvram_gen_total_lid = tbl_size/sizeof(nvram_ltable_entry_struct);
    printf("addr = %x, entry size: %d, real size: %d %s result size:%d\n", logical_data_item_table, sizeof(nvram_ltable_entry_struct), tbl_size, tbl_size%sizeof(nvram_ltable_entry_struct)?"!=":"=",nvram_gen_total_lid * sizeof(nvram_ltable_entry_struct));

    do 
    {
        printf("ltable[%d](0x%x) = %s(%d), size = %d, total_records = %d\n",
            i, &logical_data_item_table[i], logical_data_item_table[i].str_LID, logical_data_item_table[i].LID, logical_data_item_table[i].size, logical_data_item_table[i].total_records);

        nvram_gen_assign_entry(&logical_data_item_table[i]);

    }while(++i < nvram_gen_total_lid);

#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  nvram_gen_search_entry
 * DESCRIPTION
 *  To construct ltable.
 * PARAMETERS
 *  None
 * RETURNS
 *  None
 *****************************************************************************/
nvram_ltable_entry_struct* nvram_gen_search_entry(nvram_lid_enum lid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do 
    {
        if (logical_data_item_table[i].LID == lid)
        {
            return &logical_data_item_table[i];
        }

    }while(++i < nvram_gen_total_lid);

    return NULL;
}


#endif /* NVRAM_NOT_PRESENT */
