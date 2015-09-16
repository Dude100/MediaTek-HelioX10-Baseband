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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _NVRAM_PSEUDO_MERGE_H
#define _NVRAM_PSEUDO_MERGE_H

#ifdef __NVRAM_PSEUDO_MERGE__

#include "kal_general_types.h"
#include "nvram_defs.h"
#include "nvram_internal.h"

/*****************************************************************************
 *  Include
 ****************************************************************************/
/*****************************************************************************
 *  Define
 ****************************************************************************/
#define NVRAM_CLUSTER_SIZE   900
#define NVRAM_LTABLE_NUMBLE  3   /* core comm cust */
#define NVRAM_FILE_HEAD_SIZE (sizeof(head_info_struct) + NVRAM_CHKSUM_SIZE)

/*****************************************************************************
 *  Typedef
 ****************************************************************************/

typedef kal_uint8 nvram_area_enum;
#define NVRAM_AREA_CORE         0x01
#define NVRAM_AREA_COMM         0x02
#define NVRAM_AREA_CUST         0x04
#define NVRAM_AREA_IMPORTANT    0x08
#define NVRAM_AREA_INVALID      0xFF

typedef struct
{
    kal_uint32      file_offset;
    kal_uint32      record_size;
    kal_uint16      total_records;
    kal_char        itemname[8];
    nvram_area_enum area;
}LID_info_struct;

typedef struct
{
    kal_uint32  chksum_core;
    kal_uint32  chksum_comm;
    kal_uint32  chksum_cust;
    kal_uint32  total_size_core;
    kal_uint32  total_size_comm;
    kal_uint32  total_size_cust;
    kal_uint16  total_pack_lid;
}head_info_struct;

typedef struct
{
    kal_uint32      file_offset;
    kal_uint32      record_size;        /* will be removed */
    kal_uint16      total_records;      /* will be removed */
    nvram_lid_enum  LID;
    nvram_area_enum area;
}head_info_entry;

typedef struct
{
    kal_uint16  lid_moving_index;
    kal_uint16  lid_adding_index;
}temp_info_struct;


/*****************************************************************************
 *  Global Function
 ****************************************************************************/
extern kal_bool nvram_query_lid_merge(nvram_ltable_entry_struct *ldi);
extern void nvram_assign_package_entry(nvram_ltable_entry_struct *ldi);
extern kal_bool nvram_pseudo_merge(void);
extern kal_bool nvram_create_package_file(kal_char M_name);
extern kal_bool nvram_calculate_write_data_offset(kal_uint32 *offset_for_add_lid, kal_bool is_init);
extern kal_uint32 nvram_calculate_filename_chksum(nvram_ltable_entry_struct *ldi);
extern void nvram_make_filename_compare(kal_char* buf, kal_char* prefix, kal_char* verno);
extern void nvram_make_package_filename(kal_char* buf, kal_char M);
extern void nvram_make_package_info_filename(kal_char* buf, kal_char M);
extern void naram_make_temp_filename(kal_char* buf, kal_char M);


#endif /* __NVRAM_PSEUDO_MERGE__ */ 
#endif
