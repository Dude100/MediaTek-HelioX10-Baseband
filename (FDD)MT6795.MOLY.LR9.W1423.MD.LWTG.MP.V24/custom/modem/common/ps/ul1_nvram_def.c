/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 * ul1_nvram_def.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file contains `vendor' defined logical data items stored in NVRAM.
 *    These logical data items are used in object code of Protocol Stack software.
 *
 *    As for customizable logical data items, they are defined in nvram_user_config.c
 *
 * Author:
 * -------
 * 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef NVRAM_NOT_PRESENT

/* In case of that not to build this file in 2G projects or 3G TDD projects */
#if defined (__MTK_UL1_FDD__)


/*
 *   Include Headers
 */

#include "kal_general_types.h"

/*
 *   NVRAM Basic Headers
 */
#ifdef NVRAM_AUTO_GEN
#include "nvram_auto_gen.h"
#endif

#include "nvram_enums.h"
#include "nvram_defs.h"
#include "nvram_data_items.h"

/*
 *   User Headers
 */
#include "ul1_nvram_def.h"
#include "ul1d_rf_cid.h"

/*
 *   Default value
 */
/* Custpack LIDs' default value should left in nvram_cust_pack.c */ 
#if (defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__))
    extern U_sUl1dRfCustomInputData COMMON_NVRAM_EF_UL1_3G_RF_PARAMETER_DEFAULT[];
#endif

#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
    extern U_sUl1IotCustomSupportStruct COMMON_NVRAM_EF_UL1_IOT_CUSTOMIZATION_DEFAULT[];
#endif

#if defined (__UL1_HS_PLUS_PLATFORM__) || defined (__UL1_HS_PLATFORM__)
    extern nvram_ef_ul1_hspa_category_struct COMMON_NVRAM_EF_UL1_HSPA_CATEGORY_DEFAULT[];
#endif

#if defined (__UL1_PLATFORM__)
	#if defined (__MTK_UL1_FDD__)
		extern nvram_ef_ul1_rf_custpack_data_select_struct COMMON_NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_DEFAULT[];
		extern nvram_ef_ul1_rf_custom_data_struct COMMON_NVRAM_EF_UL1_RF_CUSTOM_DATA_DEFAULT[];
	#endif
#endif

/*
 *   Function extern
 */
extern void nvram_get_uL1_default_value_to_write(nvram_lid_enum lid, kal_uint8 * buffer, kal_uint16 buffer_size);

/*
 *   LID table
 */

ltable_entry_struct logical_data_item_table_ul1[] =
{
#if defined (__UL1_PLATFORM__)
    {
        NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_LID,
        NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_TOTAL,
        NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_DEFAULT),
        NVRAM_CATEGORY_USER| NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        "MT2Q",
        VER(NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_LID)
    },

    {
        NVRAM_EF_UL1_RF_CUSTOM_DATA_LID,
        NVRAM_EF_UL1_RF_CUSTOM_DATA_TOTAL,
        NVRAM_EF_UL1_RF_CUSTOM_DATA_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_UL1_RF_CUSTOM_DATA_DEFAULT),
        NVRAM_CATEGORY_USER| NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        "MT2R",
        VER(NVRAM_EF_UL1_RF_CUSTOM_DATA_LID)
    },
#endif /* #if defined (__UL1_PLATFORM__) */

#if (defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__))
    {
        NVRAM_EF_UL1_3G_RF_PARAMETER_LID,
        NVRAM_EF_UL1_3G_RF_PARAMETER_TOTAL,
        NVRAM_EF_UL1_3G_RF_PARAMETER_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "MT2S",
        VER(NVRAM_EF_UL1_3G_RF_PARAMETER_LID)
    },
#endif /* #if (defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)) */

#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
    {
        NVRAM_EF_UL1_IOT_CUSTOMIZATION_LID,
        NVRAM_EF_UL1_IOT_CUSTOMIZATION_TOTAL,
        NVRAM_EF_UL1_IOT_CUSTOMIZATION_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_UL1_IOT_CUSTOMIZATION_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "MT2T",
        VER(NVRAM_EF_UL1_IOT_CUSTOMIZATION_LID)
    },
#endif /* #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__) */

#if defined (__UL1_HS_PLUS_PLATFORM__) || defined (__UL1_HS_PLATFORM__)
   {
       NVRAM_EF_UL1_HSPA_CATEGORY_LID,
       NVRAM_EF_UL1_HSPA_CATEGORY_TOTAL,
       NVRAM_EF_UL1_HSPA_CATEGORY_SIZE,
       NVRAM_CUSTPACK(COMMON_NVRAM_EF_UL1_HSPA_CATEGORY_DEFAULT),
       NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
       NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
       "MT2U",
       VER(NVRAM_EF_UL1_HSPA_CATEGORY_LID)
    },
#endif
#if defined (__UL1_HS_PLUS_PLATFORM__) || defined (__UL1_HS_PLATFORM__)
    {
        NVRAM_EF_UL1_CUSTOM_DYNAMIC_INIT_DEBUG_LID,
        NVRAM_EF_UL1_CUSTOM_DYNAMIC_INIT_DEBUG_TOTAL,
        NVRAM_EF_UL1_CUSTOM_DYNAMIC_INIT_DEBUG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT), // NVRAM_NORMAL for data not in secupack and custpack
        NVRAM_CATEGORY_USER,
        /* Attribute NVRAM_ATTR_MULTIPLE for double copy on flash */
        NVRAM_ATTR_AVERAGE,
        /* Category NVRAM_CATEGORY_CUSTPACK for using default value from custpack */
        "MT2V",
        VER(NVRAM_EF_UL1_CUSTOM_DYNAMIC_INIT_DEBUG_LID)
        //"UL1 Custom Dynamic Init Debug",
        //NVRAM_APP_RESERVED
    },
#endif
#if (IS_3G_MIPI_SUPPORT)
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
 #endif
    {
        NVRAM_EF_UL1_MIPI_TPC_HIGHBAND1_LID,
        NVRAM_EF_UL1_MIPI_TPC_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_TPC_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULM1",
        VER(NVRAM_EF_UL1_MIPI_TPC_HIGHBAND1_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_TPC_HIGHBAND2_LID,
        NVRAM_EF_UL1_MIPI_TPC_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_TPC_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULM2",
        VER(NVRAM_EF_UL1_MIPI_TPC_HIGHBAND2_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_TPC_HIGHBAND3_LID,
        NVRAM_EF_UL1_MIPI_TPC_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_TPC_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULM3",
        VER(NVRAM_EF_UL1_MIPI_TPC_HIGHBAND3_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_TPC_LOWBAND1_LID,
        NVRAM_EF_UL1_MIPI_TPC_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_TPC_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULM4",
        VER(NVRAM_EF_UL1_MIPI_TPC_LOWBAND1_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_TPC_LOWBAND2_LID,
        NVRAM_EF_UL1_MIPI_TPC_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_TPC_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULM5",
        VER(NVRAM_EF_UL1_MIPI_TPC_LOWBAND2_LID)
    },
#endif /* IS_3G_MIPI_SUPPORT */
#if (IS_3G_ET_NVRAM_SUPPORT)
    {
        NVRAM_EF_UL1_MIPI_ET_HIGHBAND1_LID,
        NVRAM_EF_UL1_MIPI_ET_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_ET_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULM6",
        VER(NVRAM_EF_UL1_MIPI_ET_HIGHBAND1_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_ET_HIGHBAND2_LID,
        NVRAM_EF_UL1_MIPI_ET_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_ET_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULM7",
        VER(NVRAM_EF_UL1_MIPI_ET_HIGHBAND2_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_ET_HIGHBAND3_LID,
        NVRAM_EF_UL1_MIPI_ET_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_ET_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULM8",
        VER(NVRAM_EF_UL1_MIPI_ET_HIGHBAND3_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_ET_LOWBAND1_LID,
        NVRAM_EF_UL1_MIPI_ET_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_ET_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULM9",
        VER(NVRAM_EF_UL1_MIPI_ET_LOWBAND1_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_ET_LOWBAND2_LID,
        NVRAM_EF_UL1_MIPI_ET_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_ET_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMA",
        VER(NVRAM_EF_UL1_MIPI_ET_LOWBAND2_LID)
    },
#endif /* IS_3G_ET_NVRAM_SUPPORT */
#if (IS_3G_MIPI_NVRAM_FULL_SUPPORT)
    {
        NVRAM_EF_UL1_MIPI_RX_EVENT_HIGHBAND1_LID,
        NVRAM_EF_UL1_MIPI_RX_EVT_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_RX_EVT_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMB",
        VER(NVRAM_EF_UL1_MIPI_RX_EVENT_HIGHBAND1_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_RX_EVENT_HIGHBAND2_LID,
        NVRAM_EF_UL1_MIPI_RX_EVT_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_RX_EVT_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMC",
        VER(NVRAM_EF_UL1_MIPI_RX_EVENT_HIGHBAND2_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_RX_EVENT_HIGHBAND3_LID,
        NVRAM_EF_UL1_MIPI_RX_EVT_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_RX_EVT_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMD",
        VER(NVRAM_EF_UL1_MIPI_RX_EVENT_HIGHBAND3_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_RX_EVENT_LOWBAND1_LID,
        NVRAM_EF_UL1_MIPI_RX_EVT_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_RX_EVT_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULME",
        VER(NVRAM_EF_UL1_MIPI_RX_EVENT_LOWBAND1_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_RX_EVENT_LOWBAND2_LID,
        NVRAM_EF_UL1_MIPI_RX_EVT_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_RX_EVT_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMF",
        VER(NVRAM_EF_UL1_MIPI_RX_EVENT_LOWBAND2_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_RX_DATA_HIGHBAND1_LID,
        NVRAM_EF_UL1_MIPI_RX_DATA_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_RX_DATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMG",
        VER(NVRAM_EF_UL1_MIPI_RX_DATA_HIGHBAND1_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_RX_DATA_HIGHBAND2_LID,
        NVRAM_EF_UL1_MIPI_RX_DATA_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_RX_DATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMH",
        VER(NVRAM_EF_UL1_MIPI_RX_DATA_HIGHBAND2_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_RX_DATA_HIGHBAND3_LID,
        NVRAM_EF_UL1_MIPI_RX_DATA_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_RX_DATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMI",
        VER(NVRAM_EF_UL1_MIPI_RX_DATA_HIGHBAND3_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_RX_DATA_LOWBAND1_LID,
        NVRAM_EF_UL1_MIPI_RX_DATA_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_RX_DATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMJ",
        VER(NVRAM_EF_UL1_MIPI_RX_DATA_LOWBAND1_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_RX_DATA_LOWBAND2_LID,
        NVRAM_EF_UL1_MIPI_RX_DATA_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_RX_DATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMK",
        VER(NVRAM_EF_UL1_MIPI_RX_DATA_LOWBAND2_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_TX_EVENT_HIGHBAND1_LID,
        NVRAM_EF_UL1_MIPI_TX_EVT_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_TX_EVT_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULML",
        VER(NVRAM_EF_UL1_MIPI_TX_EVENT_HIGHBAND1_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_TX_EVENT_HIGHBAND2_LID,
        NVRAM_EF_UL1_MIPI_TX_EVT_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_TX_EVT_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMM",
        VER(NVRAM_EF_UL1_MIPI_TX_EVENT_HIGHBAND2_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_TX_EVENT_HIGHBAND3_LID,
        NVRAM_EF_UL1_MIPI_TX_EVT_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_TX_EVT_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMN",
        VER(NVRAM_EF_UL1_MIPI_TX_EVENT_HIGHBAND3_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_TX_EVENT_LOWBAND1_LID,
        NVRAM_EF_UL1_MIPI_TX_EVT_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_TX_EVT_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMO",
        VER(NVRAM_EF_UL1_MIPI_TX_EVENT_LOWBAND1_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_TX_EVENT_LOWBAND2_LID,
        NVRAM_EF_UL1_MIPI_TX_EVT_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_TX_EVT_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMP",
        VER(NVRAM_EF_UL1_MIPI_TX_EVENT_LOWBAND2_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_TX_DATA_HIGHBAND1_LID,
        NVRAM_EF_UL1_MIPI_TX_DATA_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_TX_DATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMQ",
        VER(NVRAM_EF_UL1_MIPI_TX_DATA_HIGHBAND1_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_TX_DATA_HIGHBAND2_LID,
        NVRAM_EF_UL1_MIPI_TX_DATA_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_TX_DATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMR",
        VER(NVRAM_EF_UL1_MIPI_TX_DATA_HIGHBAND2_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_TX_DATA_HIGHBAND3_LID,
        NVRAM_EF_UL1_MIPI_TX_DATA_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_TX_DATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMS",
        VER(NVRAM_EF_UL1_MIPI_TX_DATA_HIGHBAND3_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_TX_DATA_LOWBAND1_LID,
        NVRAM_EF_UL1_MIPI_TX_DATA_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_TX_DATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMT",
        VER(NVRAM_EF_UL1_MIPI_TX_DATA_LOWBAND1_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_TX_DATA_LOWBAND2_LID,
        NVRAM_EF_UL1_MIPI_TX_DATA_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_TX_DATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMU",
        VER(NVRAM_EF_UL1_MIPI_TX_DATA_LOWBAND2_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_ASM_ISOLATION_HIGHBAND1_LID,
        NVRAM_EF_UL1_MIPI_ASM_ISOLATION_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_ASM_ISOLATION_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMV",
        VER(NVRAM_EF_UL1_MIPI_ASM_ISOLATION_HIGHBAND1_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_ASM_ISOLATION_HIGHBAND2_LID,
        NVRAM_EF_UL1_MIPI_ASM_ISOLATION_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_ASM_ISOLATION_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMW",
        VER(NVRAM_EF_UL1_MIPI_ASM_ISOLATION_HIGHBAND2_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_ASM_ISOLATION_HIGHBAND3_LID,
        NVRAM_EF_UL1_MIPI_ASM_ISOLATION_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_ASM_ISOLATION_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMX",
        VER(NVRAM_EF_UL1_MIPI_ASM_ISOLATION_HIGHBAND3_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_ASM_ISOLATION_LOWBAND1_LID,
        NVRAM_EF_UL1_MIPI_ASM_ISOLATION_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_ASM_ISOLATION_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMY",
        VER(NVRAM_EF_UL1_MIPI_ASM_ISOLATION_LOWBAND1_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_ASM_ISOLATION_LOWBAND2_LID,
        NVRAM_EF_UL1_MIPI_ASM_ISOLATION_BAND_TOTAL,
        NVRAM_EF_UL1_MIPI_ASM_ISOLATION_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULMZ",
        VER(NVRAM_EF_UL1_MIPI_ASM_ISOLATION_LOWBAND2_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_INIT_CW_LID,
        NVRAM_EF_UL1_MIPI_INIT_CW_TOTAL,
        NVRAM_EF_UL1_MIPI_INIT_CW_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULN1",
        VER(NVRAM_EF_UL1_MIPI_INIT_CW_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_SLEEP_CW_LID,
        NVRAM_EF_UL1_MIPI_SLEEP_CW_TOTAL,
        NVRAM_EF_UL1_MIPI_SLEEP_CW_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULN2",
        VER(NVRAM_EF_UL1_MIPI_SLEEP_CW_LID)
    },
#if (IS_3G_ET_NVRAM_SUPPORT)
    {
        NVRAM_EF_UL1_MIPI_ET_ON_CW_LID,
        NVRAM_EF_UL1_MIPI_ET_ON_CW_TOTAL,
        NVRAM_EF_UL1_MIPI_ET_ON_CW_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULN3",
        VER(NVRAM_EF_UL1_MIPI_ET_ON_CW_LID)
    },
    {
        NVRAM_EF_UL1_MIPI_ET_OFF_CW_LID,
        NVRAM_EF_UL1_MIPI_ET_OFF_CW_TOTAL,
        NVRAM_EF_UL1_MIPI_ET_OFF_CW_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULN4",
        VER(NVRAM_EF_UL1_MIPI_ET_OFF_CW_LID)
    },
#endif /* IS_3G_ET_NVRAM_SUPPORT */
#if (IS_3G_VPA_SEL_BY_BAND_SUPPORT)
    {
        NVRAM_EF_UL1_VPA_SRC_SEL_HIGHBAND1_LID,
        NVRAM_EF_UL1_VPA_SRC_SEL_BAND_TOTAL,
        NVRAM_EF_UL1_VPA_SRC_SEL_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULN5",
        VER(NVRAM_EF_UL1_VPA_SRC_SEL_HIGHBAND1_LID)
    },
    {
        NVRAM_EF_UL1_VPA_SRC_SEL_HIGHBAND2_LID,
        NVRAM_EF_UL1_VPA_SRC_SEL_BAND_TOTAL,
        NVRAM_EF_UL1_VPA_SRC_SEL_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULN6",
        VER(NVRAM_EF_UL1_VPA_SRC_SEL_HIGHBAND2_LID)
    },
    {
        NVRAM_EF_UL1_VPA_SRC_SEL_HIGHBAND3_LID,
        NVRAM_EF_UL1_VPA_SRC_SEL_BAND_TOTAL,
        NVRAM_EF_UL1_VPA_SRC_SEL_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULN7",
        VER(NVRAM_EF_UL1_VPA_SRC_SEL_HIGHBAND3_LID)
    },
    {
        NVRAM_EF_UL1_VPA_SRC_SEL_LOWBAND1_LID,
        NVRAM_EF_UL1_VPA_SRC_SEL_BAND_TOTAL,
        NVRAM_EF_UL1_VPA_SRC_SEL_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULN8",
        VER(NVRAM_EF_UL1_VPA_SRC_SEL_LOWBAND1_LID)
    },
    {
        NVRAM_EF_UL1_VPA_SRC_SEL_LOWBAND2_LID,
        NVRAM_EF_UL1_VPA_SRC_SEL_BAND_TOTAL,
        NVRAM_EF_UL1_VPA_SRC_SEL_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULN9",
        VER(NVRAM_EF_UL1_VPA_SRC_SEL_LOWBAND2_LID)
    },
#endif/*IS_3G_VPA_SEL_BY_BAND_SUPPORT*/

#endif /* IS_3G_MIPI_NVRAM_FULL_SUPPORT */
#if (IS_3G_TAS_NVRAM_SUPPORT)
    {
        NVRAM_EF_UL1_TAS_RF_LID,
        NVRAM_EF_UL1_TAS_RF_TOTAL,
        NVRAM_EF_UL1_TAS_RF_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULNA",
        VER(NVRAM_EF_UL1_TAS_RF_LID)
    },
    {
        NVRAM_EF_UL1_TAS_CUSTOM_LID,
        NVRAM_EF_UL1_TAS_CUSTOM_TOTAL,
        NVRAM_EF_UL1_TAS_CUSTOM_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_uL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_MULTI_DEFAULT,
        "ULNB",
        VER(NVRAM_EF_UL1_TAS_CUSTOM_LID)
    },
#endif /* IS_3G_TAS_NVRAM_SUPPORT */

};

#endif /* #if defined (__MTK_UL1_FDD__) */

#endif /* NVRAM_NOT_PRESENT */
