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
 * nvram_pseudo_merge.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   NVRAM feature: pseudo merge
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __NVRAM_PSEUDO_MERGE__

#include "string.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"


/*
 * FS head file
 */
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"

#include "nvram_main.h"

/***********************************************************
 * Static Declaration
 ***********************************************************/
/*
 * Define local variable here
 */
static head_info_entry *g_nvram_move_package_lid;
static kal_bool is_need_move = KAL_FALSE;
static kal_uint16 total_package_lid = 0;
static head_info_struct g_head_info_file;

/***********************************************************
 * Global Variable
 **********************************************************/

/***********************************************************
 * Global Function
 **********************************************************/
extern void *kal_tmp_mem_alloc(kal_uint32 size);
extern void kal_tmp_mem_free(void *mem_ptr);

/*****************************************************************************
 * FUNCTION
 *  nvram_make_filename_compare
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void nvram_make_filename_compare(kal_char* buf, kal_char* prefix, kal_char* verno) 
{
   buf[0] = prefix[0];       
   buf[1] = prefix[1];       
   buf[2] = prefix[2];       
   buf[3] = prefix[3];       
   buf[4] = verno[0];        
   buf[5] = verno[1];        
   buf[6] = verno[2];        
   buf[7] = '\0';                            
};
/*****************************************************************************
 * FUNCTION
 *  nvram_make_package_filename
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void nvram_make_package_filename(kal_char* buf, kal_char M) 
{       
   buf[0] = 'P';                    
   buf[1] = 'A';                    
   buf[2] = 'C';                    
   buf[3] = 'K';                    
   buf[4] = M;         
   buf[5] = 'L';                    
   buf[6] = 'I';                    
   buf[7] = 'D';                    
   buf[8] = '\0';                   
};

/*****************************************************************************
 * FUNCTION
 *  nvram_make_package_info_filename
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void nvram_make_package_info_filename(kal_char* buf, kal_char M) 
{  
   buf[0] = 'I';                    
   buf[1] = 'N';                    
   buf[2] = 'F';                    
   buf[3] = 'O';                    
   buf[4] = M;         
   buf[5] = 'L';                    
   buf[6] = 'I';                    
   buf[7] = 'D';                    
   buf[8] = '\0';                   
};

/*****************************************************************************
 * FUNCTION
 *  naram_make_temp_filename
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void naram_make_temp_filename(kal_char* buf, kal_char M)
{  
   buf[0] = 'T';                    
   buf[1] = 'E';                    
   buf[2] = 'M';                    
   buf[3] = 'P';                    
   buf[4] = M;         
   buf[5] = 'L';                    
   buf[6] = 'I';                    
   buf[7] = 'D';                    
   buf[8] = '\0';                   
};

/*****************************************************************************
 * FUNCTION
 *  nvram_sort_order_head_info
 * DESCRIPTION
 *
 * PARAMETERS
 *  lid_info        [?]
 *  info_index      [IN]        info_index [0, total_num - 1], <==> loop_index
 *  file_index      [IN]
 * RETURNS
 *
 *****************************************************************************/
static kal_bool nvram_sort_order_head_info(LID_info_struct *lid_info, kal_uint16 info_index, nvram_lid_enum file_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    head_info_entry headinfo_temp;
    kal_uint32 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    headinfo_temp.file_offset = lid_info->file_offset;
    headinfo_temp.record_size = lid_info->record_size;
    headinfo_temp.total_records = lid_info->total_records;
    headinfo_temp.area = lid_info->area;
    headinfo_temp.LID = file_index;

//    NVRAM_BLOCKING_ASSERT(info_index <= total_package_lid, 0, 0, 0);

    if (info_index == 0)
    {
        g_nvram_move_package_lid[0] = headinfo_temp;
    }
    else
    {
        for (temp = (kal_uint32)info_index; temp > 0; temp--)
        {
            if (headinfo_temp.file_offset < g_nvram_move_package_lid[temp - 1].file_offset)     /* last one */
            {
                g_nvram_move_package_lid[temp] = headinfo_temp;
                break;
            }
            else
            {
                g_nvram_move_package_lid[temp] = g_nvram_move_package_lid[temp - 1];
                g_nvram_move_package_lid[temp - 1] = headinfo_temp;
            }
        }
    }
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_compare_filename_chksum
 * DESCRIPTION
 *  To judge which table (core/comm/cust) has been changed (add LID or del LID)
 *  By compare filename's chksum.
 * PARAMETERS
 *  void
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
 static kal_bool nvram_compare_filename_chksum(head_info_struct *head_info)
 {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    //for compatible with 10A & 11A, only use CORE variable after 11B
    head_info->chksum_core += (head_info->chksum_comm + head_info->chksum_cust);
    head_info->total_size_core += (head_info->total_size_comm + head_info->total_size_cust);
    
    //for compatible with 10A & 11A, only use CORE variable after 11B
    if ((head_info->chksum_core != g_head_info_file.chksum_core) ||
        (head_info->total_size_core != g_head_info_file.total_size_core))
    {
        nvram_ptr->sw_status |= NVRAM_SW_PACKAGE_CHANGE;
    }

    return KAL_TRUE;
 }

/*****************************************************************************
 * FUNCTION
 *  nvram_create_package_file
 * DESCRIPTION
 *  To create package_file and information_package_file.
 * PARAMETERS
 *  M_name      [IN]        
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
kal_bool nvram_create_package_file(kal_char M_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    NVRAM_FILE_NAME nvramname;

    nvram_drv_status_enum drv_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* open package file/backup file,if no exist, create it */
    nvram_make_package_filename(nvramname, M_name);

    drv_status = nvram_drv_fat_write(
                    nvramname,
                    NVRAM_NVD_DATA,
                    0,
                    1,
                    1,
                    sizeof(head_info_struct),
                    (kal_uint8*) &g_head_info_file,
                    NVRAM_ATTR_AVERAGE,
                    KAL_TRUE);
    if (drv_status != NVRAM_DRV_OK)
    {
        return KAL_FALSE;
    }

    /* open information file/backup file,if no exist, create it */
    nvram_make_package_info_filename(nvramname, M_name);

    drv_status = nvram_drv_fat_write(
                    nvramname,
                    NVRAM_NVD_DATA,
                    0,
                    1,
                    1,
                    sizeof(head_info_struct),
                    (kal_uint8*) &g_head_info_file,
                    NVRAM_ATTR_AVERAGE,
                    KAL_TRUE);
    if (drv_status != NVRAM_DRV_OK)
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_open_package_file
 * DESCRIPTION
 *  To open package_file and backup_package_file.
 * PARAMETERS
 *  nvramname       [IN]         
 *  openOption      [IN]        
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
static kal_bool nvram_open_package_file(kal_char *nvramname, kal_uint32 openOption)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar filename[NVRAM_MAX_PATH_LEN];

    FS_HANDLE hFile = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_query_file_name(NVRAM_NVD_DATA, nvramname, filename);

    hFile = FS_Open((const kal_wchar*)filename, openOption);

    if (hFile <= FS_NO_ERROR)
    {
        nvram_trace(TRACE_FUNC, MERGE_OPEN_PKG_FILE_RESULT, hFile);
        return KAL_FALSE;
    }

    FS_Close(hFile);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_check_data_item
 * DESCRIPTION
 *  To check which data item valid. 1.Write back to file. OR 2. Create big array ?????
 * PARAMETERS
 *  total_num       [IN]        
 *  data_offset     [IN/OUT]         
 *  sw_change       [IN]        
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
static kal_bool nvram_check_data_item(kal_bool sw_change)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_lid_enum temp;
    kal_uint32 package_temp;
    nvram_ltable_entry_struct *ldi = NULL;

    kal_uint32 Offset;

    LID_info_struct lid_info;
    kal_char filename_compare[8];
    NVRAM_FILE_NAME nvramname;
    nvram_drv_status_enum drv_status;
    kal_bool lid_is_valid;  /* can find in logical table, means lid is still valid */
    kal_uint16 info_index = 0;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_make_package_info_filename(nvramname, 'A');

    for (package_temp = (kal_uint32)total_package_lid; package_temp > 0; package_temp--)
    {
        /* 1. Read LID information */

        /* seek to the record start,from top to bottom */
        Offset = (sizeof(head_info_struct) + NVRAM_CHKSUM_SIZE) + 
                 (package_temp - 1) * (sizeof(LID_info_struct) + NVRAM_CHKSUM_SIZE); 
        
        lid_is_valid = KAL_FALSE;   /* first, Assume every lid is invalid */

        drv_status = nvram_drv_fat_read(
                        nvramname,
                        NVRAM_NVD_DATA,
                        Offset,
                        1,
                        1,
                        sizeof(LID_info_struct),
                        (kal_uint8*) &lid_info,
                        NVRAM_DRV_READ_TYPE_DATA,
                        NVRAM_ATTR_AVERAGE);
        /* Success!! Great!! */
        if (drv_status == NVRAM_DRV_OK)
        {
            if (lid_info.area != NVRAM_AREA_INVALID)
            {
                /* Step 1: try to find out corresponding LID */
	            ldi = &logical_data_item_table[0];
                do
                {

                    if (NVRAM_IS_ATTR_PACKAGE(ldi->attr))
                    {
                        nvram_make_filename_compare(filename_compare, ldi->fileprefix, ldi->fileverno);
                        if (!strcmp(filename_compare, lid_info.itemname))       /* Compatible */
                        {
                            if (lid_info.record_size * lid_info.total_records == ldi->size * ldi->total_records)
                            {
                                lid_is_valid = KAL_TRUE;    /* means current LID is valid */
                            }
                            break;  /* break out for loop */
                        }
                    }
                }while(nvram_util_next_data_item(&ldi));

                /* Step 2: if software change,
                 *     case a: item is invalid, set it as invalid and register it into g_nvram_move_package_lid
                 *     case b: item is valid, set the offset into ltable.
                 */

                if (sw_change)
                {
                    if (!lid_is_valid)
                    {
                        is_need_move = KAL_TRUE;
                        lid_info.area = NVRAM_AREA_INVALID;

                        drv_status = nvram_drv_fat_write(
                                        nvramname,
                                        NVRAM_NVD_DATA,
                                        Offset,
                                        1,
                                        1,
                                        sizeof(LID_info_struct),
                                        (kal_uint8*) &lid_info,
                                        NVRAM_ATTR_AVERAGE,
                                        KAL_FALSE);
                        if (drv_status != NVRAM_DRV_OK)
                        {
                        }
                    }

                    //nvram_sort_order_head_info(&lid_info, info_index, temp);
                    nvram_sort_order_head_info(&lid_info, info_index, ldi->LID);
                    info_index++;
                }
                else
                {
                    if (lid_is_valid)
                    {
                        ldi->description = (kal_char *)(lid_info.file_offset);
                    }
                    else
                    {
                        //EXT_ASSERT(0, lid_info.record_size, lid_info.file_offset, lid_info.area);
                        ASSERT(0);
                        return KAL_FALSE;
                    }
                }
            }
            else
            {
                if (sw_change)
                {
                    is_need_move = KAL_TRUE;
                    /*
                     * If in the previous three cases, before write action poweroff suddenly happened,
                     * when next power-on, it will run into this case. this LID will be invalid and
                     * will be truncated in movement action.
                     */
                    temp = 0xFF;
                    nvram_sort_order_head_info(&lid_info, info_index, temp);
                    info_index++;
                }
            }
        }
        else    /* Sigh. Failed..... */
        {
            //NVRAM_BLOCKING_ASSERT(KAL_FALSE, 0, 0, 0);
            //EXT_ASSERT(KAL_FALSE, 0, 0, 0);
            return KAL_FALSE;
        }

    }
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_set_offset_to_ltable
 * DESCRIPTION
 *  Read out file offset from file, and set it to ltable
 * PARAMETERS
 *  void
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
static kal_bool nvram_set_offset_to_ltable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return nvram_check_data_item(KAL_FALSE);
}



/*****************************************************************************
 * FUNCTION
 *  nvram_read_head_information
 * DESCRIPTION
 *  
 * PARAMETERS
 *  head_info       [IN/OUT]         
 *  openOption      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool nvram_read_head_information(head_info_struct *head_info, kal_uint32 openOption)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    NVRAM_FILE_NAME nvramname;
    nvram_drv_status_enum drv_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_make_package_info_filename(nvramname, 'A');
    
    drv_status = nvram_drv_fat_read(
                    nvramname,
                    NVRAM_NVD_DATA,
                    0,
                    1,
                    1,
                    sizeof(head_info_struct),
                    (kal_uint8*) head_info,
                    NVRAM_DRV_READ_TYPE_DATA,
                    NVRAM_ATTR_AVERAGE);

    if (drv_status != NVRAM_DRV_OK)
    {
        return KAL_FALSE;
    }                
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_calculate_write_data_offset
 * DESCRIPTION
 *  1. Fill in all offset to ldi->description.
 *  2. Update the header in package file
 *  3. Update the info file
 *  4. return the maximum offset of the package file now. All new item will be added
 *     after this offset.
 * PARAMETERS
 *  offset_for_add_lid  [OUT]   the offset to add new lid
 *  is_init             [IN]    is init or not
 * RETURNS
 *  KAL_FALSE: fail
 *  KAL_TRUE: successful
 *****************************************************************************/
kal_bool nvram_calculate_write_data_offset(kal_uint32 *offset_for_add_lid, kal_bool is_init)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    NVRAM_FILE_NAME nvramname;
    nvram_ltable_entry_struct *ldi;
    LID_info_struct lid_info_temp;
    kal_uint32 file_idx;
    nvram_drv_status_enum drv_status;
    kal_uint32 info_offset = 0;
    kal_uint16 info_index = 0;
    kal_uint32 file_offset = 0;



    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (is_init)    /* write Init */
    {
        nvram_make_package_info_filename(nvramname, 'A');
        nvram_create_package_file('A');
        file_offset = sizeof(head_info_struct) + NVRAM_CHKSUM_SIZE;
    }
    else    /* write backup information file */
    {
        nvram_make_package_info_filename(nvramname, 'B');   /* 1. need move 2. add new lid */
        nvram_create_package_file('B');

        if (is_need_move)   /* 1. need move, has invalid lid */
        {
            file_offset = sizeof(head_info_struct) + NVRAM_CHKSUM_SIZE;
        }

        for (file_idx = 0; file_idx < total_package_lid; file_idx++)
        {

            if (g_nvram_move_package_lid[file_idx].area != NVRAM_AREA_INVALID)
            {
                nvram_util_get_data_item(&ldi, g_nvram_move_package_lid[file_idx].LID);

                if (is_need_move)   /* 1. need move, has invalid lid */
                {
                    ldi->description = (kal_char *)(file_offset);
                    file_offset += (ldi->size + NVRAM_CHKSUM_SIZE) * ldi->total_records;
                }
                else
                {
                    ldi->description = (kal_char *)(g_nvram_move_package_lid[file_idx].file_offset);
                }
            }
        }


        if (!is_need_move)    /* 2. No need move, only add new lid */
        {
            nvram_util_get_data_item(&ldi, g_nvram_move_package_lid[0].LID);
            file_offset = g_nvram_move_package_lid[0].file_offset + (ldi->size + NVRAM_CHKSUM_SIZE) * ldi->total_records;
        }

    }

    if (offset_for_add_lid)
    {
        /* Assign file_offset for add new lid */
        *offset_for_add_lid = file_offset;
    }

    /* 2.write package LID information */
    ldi = &logical_data_item_table[0];
    do 
    {
//        if (ltable_entry)
//        {
//            nvram_util_get_data_item(&ldi, file_idx);
            if (!NVRAM_IS_ATTR_PACKAGE(ldi->attr))
            {
                continue;
            }

            info_offset = (sizeof(head_info_struct) + NVRAM_CHKSUM_SIZE) + info_index * (sizeof(lid_info_temp) + NVRAM_CHKSUM_SIZE);
            info_index++;
        
            lid_info_temp.record_size = ldi->size;
            lid_info_temp.total_records = ldi->total_records;
            nvram_make_filename_compare(lid_info_temp.itemname, ldi->fileprefix, ldi->fileverno);
        
            if (ldi->description)   /* already in package file */
            {
                lid_info_temp.file_offset = (kal_uint32) (ldi->description);
            }
            else    /* newly add [do not set file_offset in ltable, because add_new_package_lid need this information] */
            {
                lid_info_temp.file_offset = (kal_uint32) (ldi->description) = file_offset;
                file_offset += ((ldi->size + NVRAM_CHKSUM_SIZE) * (ldi->total_records));
            }
        
            drv_status = nvram_drv_fat_write(
                            nvramname,
                            NVRAM_NVD_DATA,
                            info_offset,
                            1,
                            1,
                            sizeof(LID_info_struct),
                            (kal_uint8*) &lid_info_temp,
                            NVRAM_ATTR_AVERAGE,
                            KAL_FALSE);
            if (drv_status != NVRAM_DRV_OK)
            {
                return KAL_FALSE;
            }

//        }
    
    }while(nvram_util_next_data_item(&ldi));

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_init_all_package_lid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool nvram_init_all_package_lid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_reset_data_items(NVRAM_RESET_PACKAGE, NVRAM_APP_RESERVED, 0, 0, 0);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_construct_head_info_table
 * DESCRIPTION
 *  
 * PARAMETERS
 *  total_num       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool nvram_construct_head_info_table(kal_uint32 total_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_nvram_move_package_lid = (head_info_entry *)kal_tmp_mem_alloc(sizeof(head_info_entry) * total_num);

    if (!g_nvram_move_package_lid)
    {
        return KAL_FALSE;
    }

    kal_mem_set(g_nvram_move_package_lid, 0, total_num * sizeof(head_info_entry));

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_destruct_head_info_table
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool nvram_destruct_head_info_table(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_nvram_move_package_lid)
    {
        kal_tmp_mem_free(g_nvram_move_package_lid);
        g_nvram_move_package_lid = NULL;
    }

    return KAL_TRUE;
}







/*****************************************************************************
 * FUNCTION
 *  nvram_del_rename_package_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool nvram_del_rename_package_file(kal_bool is_exist_package_file)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    NVRAM_FILE_NAME packagename;
    NVRAM_FILE_NAME backupname;
    kal_wchar pack_filename[NVRAM_MAX_PATH_LEN];
    kal_wchar back_filename[NVRAM_MAX_PATH_LEN];
    kal_int32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* package file */
    if (is_exist_package_file)
    {
        nvram_make_package_filename(packagename, 'A');
        nvram_make_package_filename(backupname, 'B');
        nvram_query_file_name(NVRAM_NVD_DATA, packagename, pack_filename);
        nvram_query_file_name(NVRAM_NVD_DATA, backupname, back_filename);

        ret = FS_Delete(pack_filename);
        if (ret < 0)
        {
            return KAL_FALSE;
        }

        FS_Rename(back_filename, pack_filename);
        if (ret < 0)
        {
            return KAL_FALSE;
        }
    }

    /* information file */
    nvram_make_package_info_filename(packagename, 'A');
    nvram_make_package_info_filename(backupname, 'B');
    nvram_query_file_name(NVRAM_NVD_DATA, packagename, pack_filename);
    nvram_query_file_name(NVRAM_NVD_DATA, backupname, back_filename);

    ret = FS_Delete(pack_filename);
    if (ret < 0)
    {
        return KAL_FALSE;
    }
    
    FS_Rename(back_filename, pack_filename);
    if (ret < 0)
    {
        return KAL_FALSE;
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_del_temporary_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool nvram_del_temporary_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    NVRAM_FILE_NAME tempname;
    kal_wchar temp_filename[NVRAM_MAX_PATH_LEN];
    kal_int32 ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    naram_make_temp_filename(tempname, 'A');
    nvram_query_file_name(NVRAM_NVD_DATA, tempname, temp_filename);
    
    ret = FS_Delete(temp_filename);
    if (ret < 0)
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_write_temporary_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  loopindex       [IN]        moving index of g_nvram_move_package_lid[index]
 *                              adding index of logical table[index]
 *  Is_moving       [IN]        KAL_TRUE:  Now is moving, loopindex is moving index
 *                              KAL_FALSE: Now is adding new LID, loopindex is adding index
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool nvram_write_temporary_record(kal_uint16 loopindex, kal_bool Is_moving)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    NVRAM_FILE_NAME tempname;
    temp_info_struct temp_info;
    nvram_drv_status_enum drv_status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    naram_make_temp_filename(tempname, 'A');

    if (Is_moving)
    {
        temp_info.lid_moving_index = loopindex + 1;
        temp_info.lid_adding_index = 0;
    }
    else
    {
        temp_info.lid_moving_index = 0;
        temp_info.lid_adding_index = loopindex + 1;
    }
    
    drv_status = nvram_drv_fat_write(
                    tempname,
                    NVRAM_NVD_DATA,
                    0,
                    1,
                    1,
                    sizeof(temp_info_struct),
                    (kal_uint8 *)(&temp_info),
                    NVRAM_ATTR_AVERAGE,
                    KAL_FALSE);

    if (drv_status != NVRAM_DRV_OK)
    {
        nvram_trace(
            TRACE_FUNC, 
            MERGE_WRITE_TEMP_RESULT, 
            temp_info.lid_moving_index, 
            temp_info.lid_adding_index, 
            nvram_drv_fat_get_last_err(), 
            __LINE__);
        return KAL_FALSE;
    }

    return KAL_TRUE;
}

 
/*****************************************************************************
 * FUNCTION
 *  nvram_add_package_lid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  Is_moving       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool nvram_add_package_lid(kal_uint32 *file_offset, kal_bool Is_moving)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_drv_status_enum drv_status;
    nvram_ltable_entry_struct *ldi;

    NVRAM_FILE_NAME backupname;
    kal_uint16 default_value_buffer_size;
    kal_uint8 *default_value_buffer;

    kal_uint32 record_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Cannot allocate memory! */
    if ((default_value_buffer_size = MAX_NVRAM_RECORD_SIZE) & 1)
    {
        default_value_buffer_size += 1;
    }

        default_value_buffer = (kal_uint8*) get_ctrl_buffer(default_value_buffer_size);
    
    if (Is_moving)
    {
        nvram_make_package_filename(backupname, 'B');
    }
    else
    {
        nvram_make_package_filename(backupname, 'A');
    }

    ldi = &logical_data_item_table[0];
    do
    {

        if (!NVRAM_IS_ATTR_PACKAGE(ldi->attr))
        {
            continue;
        }

        if ((kal_uint32)ldi->description < (*file_offset))   /* Already in package file */
        {
            continue;
        }


        for (record_index = ldi->total_records; record_index > 0; record_index--)
        {
            nvram_get_default_value_to_write(ldi, (kal_uint16)record_index, default_value_buffer, default_value_buffer_size);

            drv_status = nvram_drv_fat_write(
                            backupname,
                            NVRAM_NVD_DATA,
                            (kal_uint32)(ldi->description),
                            (kal_uint16)(record_index),
                            1,
                            ldi->size,
                            default_value_buffer,
                            //NVRAM_ATTR_AVERAGE,
                            ldi->attr,
                            KAL_FALSE);
            if (drv_status == NVRAM_DRV_OK)
            {
            }
            else
            {
                return KAL_FALSE;
            }
        }
        /* write temp record, only when need moving, if just add LID, don't write temp record */
        if (Is_moving)
        {
            nvram_write_temporary_record(ldi->LID, KAL_FALSE);
        }
    }while(nvram_util_next_data_item(&ldi));
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_truncate_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  loopindex       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool nvram_truncate_file(kal_uint16 loopindex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hFileSrc = 0;
    NVRAM_FILE_NAME packagename;
    kal_wchar filename[NVRAM_MAX_PATH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_make_package_filename(packagename, 'A');
    nvram_query_file_name(NVRAM_NVD_DATA, packagename, filename);
    
    hFileSrc = FS_Open(filename, FS_OPEN_NO_DIR | FS_READ_WRITE | FS_PROTECTION_MODE);
    if (hFileSrc <= FS_NO_ERROR)
    {
        nvram_trace(TRACE_FUNC, MERGE_TRUNK_STATUS, hFileSrc);
        FS_Close(hFileSrc);
        return KAL_FALSE;
    }

    FS_Seek(hFileSrc, g_nvram_move_package_lid[loopindex].file_offset, FS_FILE_BEGIN);
    FS_Truncate(hFileSrc);

    FS_Close(hFileSrc);

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_move_certain_date_item
 * DESCRIPTION
 *  This is nvram_move_certain_date_item() function of NVRAM module.
 *  This function will copy certain valid data from src file to dest.
 * PARAMETERS
 *  loopindex   [IN]
 * RETURNS
 *  KAL_TRUE        if move (copy, write) successfully.
 *  KAL_FALSE       if move (copy, write) failure.
 *****************************************************************************/
static kal_bool nvram_move_certain_date_item(kal_uint16 loopindex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 record_index;
    NVRAM_FILE_NAME packagename;
    NVRAM_FILE_NAME backupname;
    nvram_ltable_entry_struct *ldi;
    kal_uint8 *buffer = NULL;
    nvram_drv_status_enum drv_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_make_package_filename(packagename, 'A');
    nvram_make_package_filename(backupname, 'B');

    nvram_util_get_data_item(&ldi, g_nvram_move_package_lid[loopindex].LID);

    buffer = (kal_uint8 *) get_ctrl_buffer(ldi->size);
    
    /* g_nvram_move_package_lid[loopindex].total_records */
    for (record_index = 0; record_index < ldi->total_records; record_index++)
    {
        drv_status = nvram_drv_fat_read(
                        packagename,
                        NVRAM_NVD_DATA,
                        g_nvram_move_package_lid[loopindex].file_offset, 
                        (kal_uint16)(record_index + 1), 
//                        (kal_uint16)(record_index), 
                        (kal_uint16)1,
                        ldi->size, 
                        buffer, 
                        NVRAM_DRV_READ_TYPE_DATA, 
                        NVRAM_ATTR_AVERAGE);
                        
        if (drv_status != NVRAM_DRV_OK)
        {
//            ASSERT(0);
            EXT_ASSERT(0, DISPLAY_ERROR(drv_status), NVRAM_LOC_READ_PACKED_FILE_FAIL, ldi->LID);
            return KAL_FALSE;
        }
        
        /* Write to Dest file */
        drv_status = nvram_drv_fat_write(
                        backupname,
                        NVRAM_NVD_DATA,
                        (kal_uint32)(ldi->description),
                        (kal_uint16)(record_index + 1),
                        1,
//                        (kal_uint16)(record_index), 
                        ldi->size, 
                        buffer, 
                        NVRAM_ATTR_AVERAGE,
                        //ldi->attr,
                        KAL_FALSE);
                        
        if (drv_status != NVRAM_DRV_OK)
        {
            return KAL_FALSE;
        }
    }

    if (buffer)
        free_ctrl_buffer(buffer);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_move_date_item
 * DESCRIPTION
 *  This is nvram_move_date_item() function of NVRAM module.
 *  This function will copy valid data from src file to dest.
 * PARAMETERS
 *  temp_info          [IN]
 *  total_package_lid  [IN]
 *  init_move          [IN]
 * RETURNS
 *  KAL_TRUE        if move (copy, write) successfully.
 *  KAL_FALSE       if move (copy, write) failure.
 *****************************************************************************/
static kal_bool nvram_move_data_item(temp_info_struct *temp_info, kal_bool init_move)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    NVRAM_FILE_NAME packagename;
    NVRAM_FILE_NAME backupname;
    NVRAM_FILE_NAME tempname;
    kal_wchar filename[NVRAM_MAX_PATH_LEN];
    kal_int32 openOption = FS_OPEN_NO_DIR | FS_READ_WRITE | FS_PROTECTION_MODE;

    kal_uint16 loopindex;
    kal_uint16 loopstart;
    kal_uint16 loopend = total_package_lid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    nvram_make_package_filename(packagename, 'A');
    nvram_make_package_filename(backupname, 'B');
    naram_make_temp_filename(tempname, 'A');

    if (init_move)  /* first time, move valid data *//* logical error */
    {
        loopstart = 0;
    }
    else
    {
        loopstart = temp_info->lid_moving_index;
    }
    /* step 1: open src file, if failed, reset all package lid */
    if (nvram_open_package_file(packagename, openOption))
    {
        /* step 2: open/create dest file, if failed, delete src file and reset all package lid */
        if (nvram_open_package_file(backupname, openOption))
        {
            /* Move valid LID package file */
            for (loopindex = loopstart; loopindex < loopend; loopindex++)
            {
                if (g_nvram_move_package_lid[loopindex].area == NVRAM_AREA_INVALID)
                {
                
                  /* May be suddenly power off between this two function */
                  /* 1. truncate file 
                   * nvram_truncate_file(loopindex);
                   * 2. write index to file 
                   * nvram_write_temporary_record(loopindex, KAL_TRUE);
                   */
                   
                    /* 1. write index to file */
                    nvram_write_temporary_record(loopindex, KAL_TRUE);
                    /* 2. truncate file */
                    nvram_truncate_file(loopindex);
                }
                else
                {
                    if (nvram_move_certain_date_item(loopindex))
                    {
                        /* 1. write index to file */
                        nvram_write_temporary_record(loopindex, KAL_TRUE);
                        /* 2. truncate file */
                        nvram_truncate_file(loopindex);
                    }
                    else
                    {
                        /* if move certain data item failure, return KAL_FALSE, and All pachage LID will be reset */
                        return KAL_FALSE;
                    }
                }
            }
        }
        else
        {
            nvram_query_file_name(NVRAM_NVD_DATA, packagename, filename);
            FS_Delete(filename);
            /* return KAL_FALSE, and All pachage LID will be reset */
            return KAL_FALSE;
        }
    }
    else
    {
        /* return KAL_FALSE, and All pachage LID will be reset */
        return KAL_FALSE;
    }
/*  */

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_deal_with_exception
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
static kal_bool nvram_deal_with_exception(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    NVRAM_FILE_NAME temp_file;
    temp_info_struct temp_info;
    head_info_struct head_info;
    kal_int32 openOption = FS_OPEN_NO_DIR | FS_READ_ONLY;
    kal_uint32 data_offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    naram_make_temp_filename(temp_file, 'A');

    nvram_drv_fat_read(
        temp_file,
        NVRAM_NVD_DATA,
        0,
        1,
        1,
        sizeof(temp_info_struct),
        (kal_uint8*) &temp_info,
        NVRAM_DRV_READ_TYPE_DATA,
        NVRAM_ATTR_AVERAGE);

    if (nvram_read_head_information(&head_info, openOption))
    {
        total_package_lid = head_info.total_pack_lid;

        /* maybe have bug */
        nvram_compare_filename_chksum(&head_info);

        if (nvram_construct_head_info_table(total_package_lid))
        {
            nvram_check_data_item(KAL_TRUE);

            nvram_calculate_write_data_offset(&data_offset, KAL_FALSE);

            if (temp_info.lid_moving_index)    /* moving */
            {
                if (nvram_move_data_item(&temp_info, KAL_FALSE))
                {
                    /* 1. Add new LID */
                    if (nvram_add_package_lid(&data_offset, KAL_TRUE))
                    {
                        /* 2. Delete Src file and Rename Dest file*/
                        nvram_del_rename_package_file(KAL_TRUE);
                        /* 3. Delete temp file */
                        nvram_del_temporary_file();
                    }
                }
                else
                {
                    /* What should i do */
                    nvram_init_all_package_lid();
                }
            }
            else    /* moved, add new lid */
            {
                if (nvram_add_package_lid(&data_offset, KAL_TRUE))  /* need move-->package file B */
                {
                    nvram_del_rename_package_file(KAL_TRUE);
                    nvram_del_temporary_file();
                }
            }
        }
        else    /* else of nvram_construct_head_info_table */
        {
            nvram_init_all_package_lid();
        }   /* end of nvram_construct_head_info_table */

        nvram_destruct_head_info_table();
    }
    else
    {
        nvram_init_all_package_lid();
    }   /* end of nvram_read_head_information */

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_compare_filename_chksum
 * DESCRIPTION
 *  To perform filename's chksum incompatible.(1. add LID 2. del LID)
 * PARAMETERS
 *  void
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
static kal_bool nvram_chksum_conflict_resolve(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 offset_for_add_lid = 0;
    kal_bool result=KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (nvram_construct_head_info_table(total_package_lid))
    {
        if (!nvram_check_data_item(KAL_TRUE))
        {
            result=KAL_FALSE;
            goto out;
        }

        /* After check out all valid LID, need moving or not */
        if (is_need_move)
        {
            if (nvram_create_package_file('B'))
            {
                temp_info_struct temp_info;

                nvram_calculate_write_data_offset(&offset_for_add_lid, KAL_FALSE);
                if (nvram_move_data_item(&temp_info, KAL_TRUE))
                {
                    /* 1.Add new LID */
                    if (nvram_add_package_lid(&offset_for_add_lid, is_need_move))    /* is_need_move =KAL_TRUE */
                    {
                        /* 2.Delete Src file and Rename Dest file */
                        nvram_del_rename_package_file(KAL_TRUE);
                        /* 3.Delete temp file */
                        nvram_del_temporary_file();
                    }
                }
                else
                {
                    nvram_init_all_package_lid();
                }
            }
            else    /* Create back file failure */
            {
                nvram_init_all_package_lid();
            }   /* end of nvram_create_package_file */
        }   /* is_need_move */
        else
        {
            nvram_calculate_write_data_offset(&offset_for_add_lid, KAL_FALSE);
            if (nvram_add_package_lid(&offset_for_add_lid, is_need_move))        /* is_need_move =KAL_FALSE */
            {
                nvram_del_rename_package_file(KAL_FALSE);
                /* nvram_del_temporary_file(); *//* in this case, not have temp file */
            }
        }   /* is_need_move = KAL_FALSE */
    }
    else
    {
        /* What should i do */
        //NVRAM_BLOCKING_ASSERT(0, total_package_lid, 0, 0);
        ASSERT(0);
        return KAL_FALSE;
    }   /* nvram_construct_head_info_table(&head_info) */

out:

    nvram_destruct_head_info_table();

    return result;
}

#define NVRAM_PSEUDO_MERGE_EXTERN_FUNCTION
/*****************************************************************************
 * FUNCTION
 *  nvram_calculate_filename_chksum
 * DESCRIPTION
 *  Calculate chksum, and turn off attr multiple, turn on attr package
 * PARAMETERS
 *  chksum          [IN/OUT]
 *  ldi             [IN/OUT]
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 nvram_calculate_filename_chksum(nvram_ltable_entry_struct *ldi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;
    kal_uint32 chksum = 0;
    kal_uint16 *word_chksum = (kal_uint16 *) &chksum;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    *(word_chksum + 1) = nvram_util_caculate_checksum(ldi->fileverno, 3);
    *word_chksum = nvram_util_caculate_checksum(ldi->fileprefix, 4);
    
    return chksum;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_query_lid_merge
 * DESCRIPTION
 *  Query certain data item should be merge or not
 * PARAMETERS
 *  ldi             [IN]
 *  lid_size        [OUT]
 * RETURNS
 *  KAL_TRUE    : merge
 *  KAL_FALSE   : not merge
 *****************************************************************************/
kal_bool nvram_query_lid_merge(nvram_ltable_entry_struct *ldi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 lid_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    lid_size = (ldi->size + NVRAM_CHKSUM_SIZE) * ldi->total_records;

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
          lid_size < NVRAM_CLUSTER_SIZE)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  nvram_assign_package_entry
 * DESCRIPTION
 *  calculate the checksum and setup the attribute
 * PARAMETERS
 *  area        [IN]    in MT/MP/Custom table
 *  ldi         [IN]    data item
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_assign_package_entry(nvram_ltable_entry_struct *ldi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 ldi_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_head_info_file.total_pack_lid++;

    ldi_size = (ldi->size + NVRAM_CHKSUM_SIZE) * ldi->total_records;

    //for compatible with 10A & 11A, only use CORE variable after 11B
    g_head_info_file.total_size_core += ldi_size;
    g_head_info_file.chksum_core += nvram_calculate_filename_chksum(ldi);
    
     //for compatible with 10A & 11A, only use CORE variable after 11B
    g_head_info_file.total_size_comm = 0;
    g_head_info_file.chksum_comm = 0;

    g_head_info_file.total_size_cust = 0;
    g_head_info_file.chksum_cust = 0;


    ldi->attr |= NVRAM_ATTR_PACKAGE;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_pseudo_merge
 * DESCRIPTION
 *  pseudo merge init function
 * PARAMETERS
 *  void
 * RETURNS
 *  Success or Fail
 *****************************************************************************/
kal_bool nvram_pseudo_merge(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 openOption = FS_OPEN_NO_DIR | FS_READ_ONLY;
    NVRAM_FILE_NAME pack_file;
    head_info_struct head_info;
    kal_wchar filename[NVRAM_MAX_PATH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    naram_make_temp_filename(pack_file, 'A');
    nvram_query_file_name(NVRAM_NVD_DATA, pack_file, filename);

    if (FS_GetAttributes(filename) >= FS_NO_ERROR) /* can find backup file, indicate suddenly power off last time */
    {
        nvram_deal_with_exception();
    }
    else    /* no find, last time is OK */
    {
        nvram_make_package_filename(pack_file, 'A');        /* 'A' means package file */
        nvram_query_file_name(NVRAM_NVD_DATA, pack_file, filename);
        if (FS_GetAttributes(filename) >= FS_NO_ERROR)
        {
            /* 1. Read out head information */
            /* 2. Compare three chksum */

            if (nvram_read_head_information(&head_info, openOption))
            {
                total_package_lid = head_info.total_pack_lid;
                nvram_compare_filename_chksum(&head_info);

                if (nvram_ptr->sw_status)
                {
                    /* chksum error, deal with it */
                    return nvram_chksum_conflict_resolve();
                }
                else    /* No change, but also need know file offset */
                {
                    return nvram_set_offset_to_ltable();
                }   /* end of nvram_ptr->sw_status */
            }
            else
            {
                /* Read fail,Assume all chksum error */
                nvram_ptr->sw_status |= NVRAM_SW_PACKAGE_CHANGE;
                /* nvram should init all package LID */
                nvram_init_all_package_lid();
            }   /* end of read head information */
        }
        else    /* can not find package file, indicate first power on */
        {
            /* nvram should init all package LID */
            nvram_init_all_package_lid();
        }
    }

    return KAL_TRUE;
}

#endif /* __NVRAM_PSEUDO_MERGE__ */

