/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *   bl_time_stamp_util.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Time stamp measurement utility (Bootloader Only)
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/

#ifdef __TIME_STAMP__

#include "br_sw_types.h"
#include "br_time_stamp.h"
#include "bl_time_stamp_id.h"
#include "bl_common.h"
#include "bl_custom.h"

static const char * TS_GetTsidName(TSID tsid)
{
    switch(tsid) {

        BR_ENUM_TO_CASE_STRING(TSID_LAST_SINGLE_SIG_HASH)
        BR_ENUM_TO_CASE_STRING(TSID_LAST_SINGLE_SIG_CIPHER)
        
        BR_ENUM_TO_CASE_STRING(TSID_BL_TOTAL)

        BR_ENUM_TO_CASE_STRING(TSID_BL_BOOTLOADER)
        BR_ENUM_TO_CASE_STRING(TSID_BL_EXT_BOOTLOADER)

        BR_ENUM_TO_CASE_STRING(TSID_BL_SET_PLLEMI)
        BR_ENUM_TO_CASE_STRING(TSID_BL_INIT)
        BR_ENUM_TO_CASE_STRING(TSID_BL_INIT2)        
        BR_ENUM_TO_CASE_STRING(TSID_BL_LOAD_EXT_BOOTLOADER)
        BR_ENUM_TO_CASE_STRING(TSID_BL_VERIFY_EXT_BOOTLOADER)
        BR_ENUM_TO_CASE_STRING(TSID_BL_PRINT_WELCOME)
        BR_ENUM_TO_CASE_STRING(TSID_BL_EXT_INIT)
        BR_ENUM_TO_CASE_STRING(TSID_BL_LOAD_ILB_CBR)
        BR_ENUM_TO_CASE_STRING(TSID_BL_LOAD_MAUI_FIRST_PART)
        BR_ENUM_TO_CASE_STRING(TSID_BL_GET_FATURE_COMINATION)
        BR_ENUM_TO_CASE_STRING(TSID_BL_FACTORY_PROCEDURE)
        BR_ENUM_TO_CASE_STRING(TSID_BL_PREPARE_BOOTUP)
        BR_ENUM_TO_CASE_STRING(TSID_BL_PREPARE_LATCH_POWER)
        BR_ENUM_TO_CASE_STRING(TSID_BL_LATCH_POWER)
        BR_ENUM_TO_CASE_STRING(TSID_BL_CACHE_INIT)
        BR_ENUM_TO_CASE_STRING(TSID_BL_DISPLAY_LOGO)        
        BR_ENUM_TO_CASE_STRING(TSID_BL_BOOT_AND_HANDOVER)
        
        BR_ENUM_TO_CASE_STRING(TSID_BL_SET_EMI)
        BR_ENUM_TO_CASE_STRING(TSID_BL_SET_PLL)
        BR_ENUM_TO_CASE_STRING(TSID_BL_SET_ADVEMI)
        BR_ENUM_TO_CASE_STRING(TSID_BL_INIT_MINI_FLASH_DRV)
        BR_ENUM_TO_CASE_STRING(TSID_BL_LOAD_EXT_BOOTLOADER_BODY)
        BR_ENUM_TO_CASE_STRING(TSID_BL_READ_FLASH_LAYOUT_INFO)
        
#ifdef __SV5_ENABLED__
        BR_ENUM_TO_CASE_STRING(TSID_BL_INIT_EXT_FLASH_DRV)
        BR_ENUM_TO_CASE_STRING(TSID_BL_INIT_CBR)
        BR_ENUM_TO_CASE_STRING(TSID_BL_LOAD_MAUI_BODY)
#else
        BR_ENUM_TO_CASE_STRING(TSID_BL_VERIFY_NFB_IMAGE_CONTENT)
        BR_ENUM_TO_CASE_STRING(TSID_BL_MULTIPLE_PAGE_READ)
#endif
        BR_ENUM_TO_CASE_STRING(TSID_BL_VERIFY_MAUI)
        BR_ENUM_TO_CASE_STRING(TSID_BL_LOAD_FOTA_IMAGE)

        BR_ENUM_TO_CASE_STRING(TSID_CALC_EXT_BOOTLOADER_CRC)                
        BR_ENUM_TO_CASE_STRING(TSID_SINGLE_SIG_HASH_IN_BL)
        BR_ENUM_TO_CASE_STRING(TSID_SINGLE_SIG_CIPHER_IN_BL)
        BR_ENUM_TO_CASE_STRING(TSID_SINGLE_SIG_HASH_IN_EBL)
        BR_ENUM_TO_CASE_STRING(TSID_SINGLE_SIG_CIPHER_IN_EBL)        

        default:
            return "UNKNOWN";
    }
}


TSID TS_RemapTSID(TSID id)
{
#if defined(__MINI_BOOTLOADER__)
   
    switch(id)
    {
        case TSID_LAST_SINGLE_SIG_HASH:
            id = TSID_SINGLE_SIG_HASH_IN_BL;
            break;
   
        case TSID_LAST_SINGLE_SIG_CIPHER:
            id = TSID_SINGLE_SIG_CIPHER_IN_BL;
            break;
    }
    
#elif defined(__EXT_BOOTLOADER__)
   
    switch(id)
    {
        case TSID_LAST_SINGLE_SIG_HASH:
            id = TSID_SINGLE_SIG_HASH_IN_EBL;
            break;
    
        case TSID_LAST_SINGLE_SIG_CIPHER:
            id = TSID_SINGLE_SIG_CIPHER_IN_EBL;
            break;
    }
   
#endif

   return id;   
}

void TS_Record_BLWrapper(TSID id, TS_TIME_ANCHOR anchor)
{
    TS_Record(TS_RemapTSID(id), anchor);
}

void TS_UpdateInfo_BLWrapper(TSID id, U32 data1, U32 data2, U32 data3)
{
    TS_UpdateInfo(TS_RemapTSID(id), data1, data2, data3);
}   


void TS_DumpTimeStamps(void)
{
    U32 i;
    const TS_Unit *p;
    const TS_RecordTable *pRecordTable = TS_GetRecordTable();
    kal_uint32 lastTSvalue = 0;

    BL_PRINT(LOG_DEBUG, "\r\n");
    
    for(i=0; i<TSID_NUM; i++)
    {
        p = (pRecordTable->m_record + i);

        if(p->m_id == TSID_NONE)
        {
            continue;
        }

        if(p->m_begin_tick < lastTSvalue)
        {
            BL_PRINT(LOG_DEBUG, "BL> --------------------------------\r\n");
        }
        
        lastTSvalue = p->m_begin_tick;

        BL_PRINT(LOG_DEBUG, "BL> %s, dur=%d, (s=%d, e=%d)", TS_GetTsidName(p->m_id), p->m_duration, p->m_begin_tick, p->m_end_tick);

        switch(p->m_id)
        {
        case TSID_CALC_EXT_BOOTLOADER_CRC:
        case TSID_LAST_SINGLE_SIG_HASH:
        case TSID_LAST_SINGLE_SIG_CIPHER:
        case TSID_SINGLE_SIG_HASH_IN_BL:
        case TSID_SINGLE_SIG_CIPHER_IN_BL:
        case TSID_SINGLE_SIG_HASH_IN_EBL:
        case TSID_SINGLE_SIG_CIPHER_IN_EBL:
        case TSID_BL_LOAD_EXT_BOOTLOADER_BODY:
#ifdef __SV5_ENABLED__
        case TSID_BL_LOAD_MAUI_BODY:
#else
        case TSID_BL_MULTIPLE_PAGE_READ:
#endif
            BL_PRINT(LOG_DEBUG, ", size=%d", p->m_info2);
            BL_PRINT(LOG_DEBUG, ", throughput=%d KB/s", (U32)(p->m_info2*(1000.0/1024)/p->m_duration));
            break;
        }

        BL_PRINT(LOG_DEBUG, "\r\n");
    }
}

#endif

