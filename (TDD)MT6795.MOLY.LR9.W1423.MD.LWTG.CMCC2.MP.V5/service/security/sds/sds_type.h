/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   sds_type.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Declaration of SDS data type
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
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SDS_TYPE_H__
#define __SDS_TYPE_H__

#if defined(WIN32) && defined(__PC_SIM__)
#include "win32_types.h"
#define PRINT printf
#elif defined(__UBL__)
#include "bl_types.h"
#elif defined(__DOWNLOAD_AGENT__)
#include "da_FTL.h"
#else
#include "sw_types.h"
#endif

#if defined(__MTK_TARGET__) || defined(__DOWNLOAD_AGENT__)
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#endif

#include "custom_sds_type.h"

//==============================================================================
// SDS error code
//==============================================================================
#define SDS_SUCCESS                           0   
#define SDS_FULL                             -1000
#define SDS_NO_SPECIFIED_RECORD              -1001
#define SDS_FAIL                             -1002
#define SDS_RECORD_EXISTING                  -1003
#define SDS_BUF_TOO_SMALL                    -1008
#define SDS_OUT_OF_SPACE                     -10000
#define SDS_PASSWORD_TOO_LONG                -10001
#define SDS_PASSWORD_HAS_SET                 -10002
#define SDS_ACCESS_DENIED                    -10003
#define SDS_FILE_SYSTEM_ERROR                -10004
#define SDS_INVALID_PACKED_DATA_HEAD         -10005
#define SDS_FILE_NOT_FOUND_IN_PACKED_RECORD  -10006
#define SDS_WRITE_FS_ERROR                   -10007
#define SDS_READ_FS_ERROR                    -10008

//==============================================================================
// SDS data type declaration
//==============================================================================

#define SDS_MAX_RECORD_INDEX    4094
#define SDS_PARTITION_SHIFT     12
//==============================================================================
// SDS APIs
//==============================================================================

/* Basic version */
kal_int32 SDS_AddRecord(SDS_PARTITION_TYPE partition, kal_uint32 index, const kal_uint8 *pData, kal_uint32 length, SDS_DP_TYPE dpType);
kal_int32 SDS_UpdateRecord(SDS_PARTITION_TYPE partition, kal_uint32 index, const kal_uint8 *pData, kal_uint32 length);
kal_int32 SDS_ReadRecord(SDS_PARTITION_TYPE partition, kal_uint32 index, kal_uint8 *pData, kal_uint32 length);
kal_int32 SDS_DelRecord(SDS_PARTITION_TYPE partition, kal_uint32 index);
kal_int32 SDS_FormatPartition(SDS_PARTITION_TYPE partition);
kal_int32 SDS_GetRecordCount(SDS_PARTITION_TYPE partition);
kal_int32 SDS_GetRecordList(SDS_PARTITION_TYPE partition, kal_uint32 *pIndexList, kal_uint32 num);
kal_int32 SDS_GetRecordLen(SDS_PARTITION_TYPE partition, kal_uint32 index);

/* Advance version with access control and customized key supprot */
kal_int32 SDS_AddRecordEx(SDS_PARTITION_TYPE partition, kal_uint32 index, const kal_uint8 *pData, kal_uint32 length, const kal_uint8 *pPassword, SDS_DP_TYPE dpType, const void *pDpArg);
kal_int32 SDS_UpdateRecordEx(SDS_PARTITION_TYPE partition, kal_uint32 index, const kal_uint8 *pData, kal_uint32 length, const kal_uint8 *pPassword, const void *pDpArg);
kal_int32 SDS_ReadRecordEx(SDS_PARTITION_TYPE partition, kal_uint32 index, kal_uint8 *pData, kal_uint32 length, const kal_uint8 *pPassword, const void *pDpArg);
kal_int32 SDS_DelRecordEx(SDS_PARTITION_TYPE partition, kal_uint32 index, const kal_uint8 *pPassword, const void *pDpArg);
kal_int32 SDS_FormatPartitionEx(SDS_PARTITION_TYPE partition, const kal_uint8 *pPassword, const void *pDpArg);
kal_int32 SDS_GetRecordCountEx(SDS_PARTITION_TYPE partition, const kal_uint8 *pPassword, const void *pDpArg);
kal_int32 SDS_GetRecordListEx(SDS_PARTITION_TYPE partition, kal_uint32 *pIndexList, kal_uint32 num, const kal_uint8 *pPassword, const void *pDpArg);
kal_int32 SDS_GetRecordLenEx(SDS_PARTITION_TYPE partition, kal_uint32 index, const kal_uint8 *pPassword, const void *pDpArg);
kal_int32 SDS_SetPassword(SDS_PARTITION_TYPE partition, void *pPassword, kal_uint32 passwordLen, SDS_DP_TYPE dpType, void *pDpArg);
#endif
