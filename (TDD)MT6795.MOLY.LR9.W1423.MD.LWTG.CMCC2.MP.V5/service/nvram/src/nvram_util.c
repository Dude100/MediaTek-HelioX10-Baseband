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
 * nvram_util.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is utility for NVRAM
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
* Include
*****************************************************************************/
#include "stdio.h"
#include "stdarg.h"
#include "kal_general_types.h"
#include "kal_internal_api.h"  /* basename */
#include "kal_public_api.h"
#include "kal_trace.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "nvram_main.h"

#include "dcl.h"


extern void InitDebugPrint(void);
extern void DebugPrint(kal_uint8, kal_uint8, kal_uint8*);
extern kal_bool INT_QueryExceptionStatus(void);
#define NVRAM_TRC_SIZE 256

kal_bool nvram_util_next_data_item(nvram_ltable_entry_struct **entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_ltable_entry_struct *ldi = *entry;
    kal_uint32 end = (kal_uint32)logical_data_item_table + nvram_ptr->ltable.area_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
		if (ldi == NULL)
		{
			ldi = &logical_data_item_table[0];
        if (ldi->fileprefix[0])
        {
            *entry = ldi;
            return KAL_TRUE;
        }
		}

    while((kal_uint32)++ldi < end)
    {
        if (ldi->fileprefix[0])
        {
            *entry = ldi;
            return KAL_TRUE;
        }
    }

    *entry = NULL;
    return KAL_FALSE;
}


kal_bool nvram_util_get_data_item(nvram_ltable_entry_struct **ldi, nvram_lid_enum LID)    
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0, count = 0;
    kal_uint32 end = (kal_uint32)logical_data_item_table + nvram_ptr->ltable.area_size;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    do 
    {
        if (logical_data_item_table[i].fileprefix[0])
        {
            count++;

            if (logical_data_item_table[i].LID == LID)
            {
                if (ldi)
                    *ldi = &logical_data_item_table[i];

                return KAL_TRUE;
            }
        }
        i++;
    }while(count < nvram_ptr->ltable.total_LID && ((kal_uint32)&logical_data_item_table[i] < end));

    if (ldi)
        *ldi = NULL;

    return KAL_FALSE;
}



/*****************************************************************************
 * FUNCTION
 *  nvram_drval_caculate_checksum
 * DESCRIPTION
 *  produce the check sum of the given record.
 * PARAMETERS
 *  checksum        [?]
 *  buf             [?]
 *  size            [IN]
 * RETURNS
 *  checksum(?)
 *****************************************************************************/
kal_uint16 nvram_util_caculate_checksum(const kal_uint8 *buf, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;
    kal_uint16 chksum = 0;
    kal_uint8 *byte_chksum = (kal_uint8*) &chksum;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (buf == NVRAM_EF_ZERO_DEFAULT)
    {
        return 0xCDEF;
    }
    else if (buf == NVRAM_EF_FF_DEFAULT)
    {
        for (i = 0 ;i < size; i++)
        {
            if (i & 0x1)
            {
                *(byte_chksum + 1) += 0xFF;
            }
            else
            {
                *byte_chksum += 0xFF;
            }
        }
        return chksum;
     }

    for (i = 0; i < size; i++)
    {
        if (i & 0x1)
        {
            *(byte_chksum + 1) += *(buf + i);
        }
        else
        {
            *byte_chksum += *(buf + i);
        }
    }
    
    if (chksum == 0)
        return 0xCDEF;
    else
        return chksum;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_make_lid_filename
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void nvram_util_make_lid_filename(nvram_ltable_entry_struct *ldi, NVRAM_FILE_NAME nvramname, kal_bool first_copy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (ldi == NULL)
    {
        ASSERT(0);
        return;
    }

#ifdef __NVRAM_PSEUDO_MERGE__
    if (NVRAM_IS_ATTR_PACKAGE(ldi->attr))
    {
        nvram_make_package_filename(nvramname, 'A');
        return;
    }
#endif

    if (NVRAM_IS_ATTR_MULTIPLE(ldi->attr))
    {
        if (first_copy)
        {
            nvram_util_make_filename(nvramname, ldi->fileprefix, 'A', ldi->fileverno);
        }
        else
        {
            nvram_util_make_filename(nvramname, ldi->fileprefix, 'B', ldi->fileverno);
        }
    }
    else
    {
        nvram_util_make_filename(nvramname, ldi->fileprefix, '_', ldi->fileverno);
    }

    return;

}

/*****************************************************************************
 * FUNCTION
 *  nvram_make_lid_filename
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void nvram_util_make_filename(NVRAM_FILE_NAME buf, kal_char* prefix, kal_char M, kal_char* verno) 
{
   buf[0] = prefix[0];  
   buf[1] = prefix[1];  
   buf[2] = prefix[2];  
   buf[3] = prefix[3];  
   buf[4] = M;             
   buf[5] = verno[0];   
   buf[6] = verno[1];   
   buf[7] = verno[2];   
   buf[8] = '\0';    
};


/*****************************************************************************
 * FUNCTION
 *  nvram_util_is_usbboot
 * DESCRIPTION
 *  old function name: INT_USBBoot
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
kal_bool nvram_util_is_usbboot(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PW_CTRL_IS_USB_BOOT CtrlVal;
    DCL_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle=DclPW_Open(DCL_PW, FLAGS_NONE);
    DclPW_Control(handle, PW_CMD_IS_USB_BOOT,(DCL_CTRL_DATA_T *)&CtrlVal);
    DclPW_Close(handle);
    return ((kal_bool)CtrlVal.val);
}

/*****************************************************************************
 * FUNCTION
 *  nvram_util_poweron
 * DESCRIPTION
 *  old function name: DRV_POWERON
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
kal_bool nvram_util_poweron(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DCL_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle=DclPW_Open(DCL_PW, FLAGS_NONE);
    DclPW_Control(handle,PW_CMD_POWERON,NULL);
    DclPW_Close(handle);
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_util_poweron
 * DESCRIPTION
 *  old function name: DRV_POWERON
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void nvram_util_poweroff(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    DCL_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle=DclPW_Open(DCL_PW, FLAGS_NONE);
    DclPW_Control(handle,PW_CMD_POWEROFF,NULL);
    DclPW_Close(handle);
}

/*****************************************************************************
 * FUNCTION
 *  nvram_get_total_num_lid
 * DESCRIPTION
 *  Get the total LID number
 * PARAMETERS
 *  void
 * RETURNS
 *  nvram_lid_enum
 *****************************************************************************/
nvram_lid_enum nvram_get_total_num_lid(void)
{
    return nvram_ptr->ltable.total_LID;
}

nvram_lid_enum nvram_util_get_IMEISV_LID(void)
{
    return NVRAM_EF_IMEI_IMEISV_LID;
}

kal_uint32 nvram_util_get_IMEISV_size(void)
{
    return NVRAM_EF_IMEI_IMEISV_SIZE;
}

kal_uint32 nvram_util_get_IMEI_size(void)
{
    return NVRAM_EF_IMEI_IMEI_SIZE;
}

void nvram_util_take_mutex(kal_mutexid ext_mutex_id_ptr)
{
    if (!INT_QueryExceptionStatus() && !kal_query_systemInit() && ext_mutex_id_ptr)
    {
        kal_take_mutex(ext_mutex_id_ptr);
    }
}

void nvram_util_give_mutex(kal_mutexid ext_mutex_id_ptr)
{
    if (!INT_QueryExceptionStatus() && !kal_query_systemInit() && ext_mutex_id_ptr)
    {
        kal_give_mutex(ext_mutex_id_ptr);
    }
}



