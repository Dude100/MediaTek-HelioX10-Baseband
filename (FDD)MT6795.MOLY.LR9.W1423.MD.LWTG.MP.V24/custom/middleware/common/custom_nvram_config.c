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

/*******************************************************************************
 * Filename:
 * ---------
 * custom_nvram_config.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   The file contains nvram configuration default value.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef NVRAM_NOT_PRESENT

#include "kal_general_types.h"

#include "nvram_enums.h"            /* NVRAM_CLEAN_FOLDER_FACTORY */
#include "custom_nvram_config.h"
#include "nvram_data_items.h"
#include "fs_gprot.h"

#if defined(__MMI_FMI__)
#include "nvram_common_defs.h"
#include "nvram_user_defs.h"
#include "MMI_features.h"
#include "custom_mmi_default_value.h"
#include "resource_verno.h"     /* ENTRY_PREAMBLE */
#include "resource_custpack_jtbl.h"     /* CUSTPACK_NVRAM */

#endif

/*
 * Restore factory begin
 */
#ifdef __MMI_IMPS__
__fs_align(2)
static kal_wchar IMPS_FOLDER[] = L"Z:\\@imps\\setting.dat";
#endif
#if defined (__MMI_FTS_SUPPORT__) || defined (__MMI_FTC_SUPPORT__)
__fs_align(2)
static kal_wchar FTP_FOLDER[] = L"Z:\\@ftp\\shared_file_path";
#endif
#ifdef __EMAIL__
__fs_align(2)
static kal_wchar EMAIL_FOLDER[] = L"Z:\\@email_sys\\sort.dat";
#endif
#ifdef SYNCML_DM_SUPPORT
__fs_align(2)
static kal_wchar DM_SERVERID_FOLDER[] = L"Z:\\@dm\\serverid.dat";
#endif

#ifdef __CERTMAN_SUPPORT__
__fs_align(2)
static kal_wchar CERTMAN_FOLDER[] = L"Z:\\@certman";
#endif

#ifdef __TCPIP__
__fs_align(2)
static kal_wchar DTCNT_SRV_FOLDER[] = L"Z:\\@Dtcnt\\DB\\SIM";
#endif

#ifdef __QQMOVIE_SUPPORT__
#if defined(MT6235)
static kal_wchar QQM_SETTING_FOLDER[] = L"C:\\QQMovie\\setting";
#elif defined(MT6238)
static kal_wchar QQM_SETTING_FOLDER[] = L"D:\\QQMovie\\setting";
#endif
#endif

const nvram_clean_folder_entry nvram_clean_folder_list[] =
{
#ifdef __MMI_IMPS__
    {NVRAM_CLEAN_FOLDER_FACTORY, IMPS_FOLDER},
#endif
#if defined (__MMI_FTS_SUPPORT__) || defined (__MMI_FTC_SUPPORT__)
    {NVRAM_CLEAN_FOLDER_FACTORY, FTP_FOLDER},
#endif
#ifdef __EMAIL__
    {NVRAM_CLEAN_FOLDER_FACTORY, EMAIL_FOLDER},
#endif
#ifdef SYNCML_DM_SUPPORT
    {NVRAM_CLEAN_FOLDER_FACTORY, DM_SERVERID_FOLDER},
#endif
#ifdef __CERTMAN_SUPPORT__
		{NVRAM_CLEAN_FOLDER_FACTORY, CERTMAN_FOLDER},
#endif

#ifdef __TCPIP__
		{NVRAM_CLEAN_FOLDER_FACTORY, DTCNT_SRV_FOLDER},
#endif

#ifdef __QQMOVIE_SUPPORT__
    {NVRAM_CLEAN_FOLDER_FACTORY, QQM_SETTING_FOLDER},
#endif

    /* Add above this */
    {NVRAM_CLEAN_FOLDER_SYSTEM | NVRAM_CLEAN_FOLDER_FACTORY | NVRAM_CLEAN_FOLDER_BRANCH , NULL}
};
/*
 * Restore factory end
 */

nvram_shutdown_cb_struct nvram_shutdown_cb_table[] =
{
    {0, NULL}
};


/*****************************************************************************
 * FUNCTION
 *  nvram_custom_max_clean_folder_size
 * DESCRIPTION
 *  Return the maximum clean folder size
 * PARAMETERS
 * RETURNS
 *  maximum record size
 *****************************************************************************/
kal_uint32 nvram_custom_max_clean_folder_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return sizeof(nvram_clean_folder_list) / sizeof(nvram_clean_folder_entry);
}

/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  nvram_lid_enum
 *****************************************************************************/
nvram_lid_enum nvram_get_first_core_lid(void)
{
    return NVRAM_EF_START;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_get_last_core_lid
 * DESCRIPTION
 *  Get the last core lid
 * PARAMETERS
 *  void
 * RETURNS
 *  nvram_lid_enum
 *****************************************************************************/
nvram_lid_enum nvram_get_last_core_lid(void)
{
    return NVRAM_EF_LAST_LID_CORE;
}

#if defined(__MMI_FMI__)
/*****************************************************************************
 * FUNCTION
 *  nvram_get_first_comm_lid
 * DESCRIPTION
 *  Get the first common lid
 * PARAMETERS
 *  void
 * RETURNS
 *  nvram_lid_enum
 *****************************************************************************/
nvram_lid_enum nvram_get_first_comm_lid(void)
{
    return NVRAM_LID_COMMAPP_BEGIN;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_get_last_comm_lid
 * DESCRIPTION
 *  Get the last common lid
 * PARAMETERS
 *  void
 * RETURNS
 *  nvram_lid_enum
 *****************************************************************************/
nvram_lid_enum nvram_get_last_comm_lid(void)
{
    return NVRAM_EF_LAST_LID_COMMAPP;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_get_first_cust_lid
 * DESCRIPTION
 *  Get the first custom lid
 * PARAMETERS
 *  void
 * RETURNS
 *  nvram_lid_enum
 *****************************************************************************/
nvram_lid_enum nvram_get_first_cust_lid(void)
{
    return NVRAM_LID_CUST_BEGIN;
}
#endif

#ifdef NEPTUNE_MMI
/*****************************************************************************
 * FUNCTION
 *  nvram_get_total_byte
 * DESCRIPTION
 *  Get the total byte number
 * PARAMETERS
 *  void
 * RETURNS
 *  nvram_lid_enum
 *****************************************************************************/
kal_uint16 nvram_get_total_byte(void)
{
    return NVRAM_LAST_BYTE_ELEMENT;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_get_total_short
 * DESCRIPTION
 *  Get the total short number
 * PARAMETERS
 *  void
 * RETURNS
 *  nvram_lid_enum
 *****************************************************************************/
kal_uint16 nvram_get_total_short(void)
{
    return NVRAM_LAST_SHORT_ELEMENT;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_get_total_double
 * DESCRIPTION
 *  Get the total double number
 * PARAMETERS
 *  void
 * RETURNS
 *  nvram_lid_enum
 *****************************************************************************/

kal_uint16 nvram_get_total_double(void)
{
    return NVRAM_LAST_DOUBLE_ELEMENT;
}
#endif

#ifdef __NVRAM_SUPPORT_CUSTPACK__
/*****************************************************************************
 * FUNCTION
 *  nvram_ltable_init
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern void nvram_custpack_int_init(custpack_nvram_header *custpack_ptr);

void nvram_custpack_init()
{
    custpack_nvram_header *custpack_header_ptr;
    void **custpack_header = NULL;


    custpack_header = (void **)GET_ResCUSTPACK_Addr(ENTRY_PREAMBLE);
    custpack_header_ptr = (custpack_nvram_header*) custpack_header[CUSTPACK_NVRAM];

    nvram_custpack_int_init(custpack_header_ptr);

   
}


sys_indirect_init_func g_nvram_custpack_init = nvram_custpack_init;

#endif  /* __NVRAM_SUPPORT_CUSTPACK__ */

#endif /* NVRAM_NOT_PRESENT */
