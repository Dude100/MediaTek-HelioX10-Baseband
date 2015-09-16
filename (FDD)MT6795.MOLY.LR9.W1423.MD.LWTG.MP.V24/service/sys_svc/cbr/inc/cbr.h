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
 *   CBR.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Declaration of Control block region facilities
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#ifndef _CBR_H_
#define _CBR_H_

#if defined(__DOWNLOAD_AGENT__)
#include "Cbr_record_def.h"
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "cbr_da_dummy.h"
#else
#include "kal_general_types.h" 
#include "Cbr_record_def.h"
#include "sds_type.h"
#endif

#define CBR_SUCCESS                         0   
#define CBR_FULL                           -1000
#define CBR_NO_SPECIFIED_RECORD            -1001
#define CBR_FAIL                           -1002
#define CBR_RECORD_EXISTING                -1003
#define CBR_UNRECOGNIZED_TAIL              -1004
#define CBR_NO_BLOCK_FOUND                 -1005
#define CBR_TOO_MANY_BAD_BLOCKS            -1006
#define CBR_NO_VALID_DATA                  -1007
#define CBR_BUF_TOO_SMALL                  -1008
#define CBR_EXCEED_MAX_SUPPORT_SPARE_BLOCK -1009
#define CBR_NO_VALID_HEADER                -1010
#define CBR_NO_VALID_TAIL                  -1011
#define CBR_UNSUPPORTED_MAX_RECORD         -1012
#define CBR_NOT_INITIALIZED                -1013
#define CBR_INITIALIZED                    -1014
#define CBR_BUF_NOT_ENOUGH                 -1015
#define CBR_PAGE_SIZE_TOO_SMALL            -1016
#define CBR_DP_CANNOT_GET_CALLBACK         -1017
#define CBR_DP_BAD_BLOCK_SIZE              -1018
#define CBR_TRAVERSE_CB_FAIL               -1019
#define CBR_READ_DATA_ERROR                -1020
#define CBR_INVALID_OFFSET                 -1021
#define CBR_INVALID_GROUP_OR_IDX           -1022
#define CBR_UNSUPPORTED_VERSION            -1023
#define CBR_MISMATCH_CBR_PARAMETER         -1024
#define CBR_INVALID_CBR_PARAMETER          -1025
#define CBR_INVALID_FLASH_CONFIGURATION    -1026
#define CBR_INVALID_ADDRESS                -1027
#define CBR_UNALIGNED_ADDRESS              -1028
#define CBR_UNALIGNED_SIZE                 -1029
#define CBR_INVALID_PARAMETER              -1030
#define CBR_REGION_TOO_LARGE               -1031
#define CBR_REGION_TOO_SMALL               -1032
#define CBR_CREATE_EMPTY_BLOCK_FAIL        -1033
#define CBR_CREATE_ROOT_RECORD_FAIL        -1034
#define CBR_CREATE_SPARE_MARKER_FAIL       -1035
#define CBR_FLASH_ERROR                    -1036
#define CBR_INTERNAL_FAILURE               -1037
 
typedef enum
{
   E_CBR_IDX_CBR = 0,
   E_CBR_IDX_SRW
} E_CBRRegionIndex;

typedef enum 
{
   E_CBR_16_MAX_RECORD_IN_BLOCK = 16,
   E_CBR_64_MAX_RECORD_IN_BLOCK = 64,
} E_CBRMaxRecordMode;

typedef struct
{
   kal_uint32 startBlock;
   kal_uint32 totalBlock;
   kal_uint32 normalCBRBlock;
   kal_uint32 fastCBRBlock;
   kal_uint32 spareBlock;
   kal_uint32 max_record_in_block;
   kal_bool   roMode;
} CBR_PARAM_INFO;

typedef struct
{
   SDS_DP_TYPE dpType;
   const void *pDpArg;
} CBR_DP_INFO;

typedef struct
{
   kal_uint32 index;
   kal_uint32 blockIdx;
   kal_uint32 pageIdx;
   kal_uint32 recordLen;
   kal_uint32 actualLen;
   kal_uint32 dpType;
} CBR_RECORD_LOCATION_STRUCT;

typedef struct
{
   kal_bool initialized;
   kal_uint32 currentPos;
   CBR_RECORD_LOCATION_STRUCT recordLocationStruct;
} CBR_RAW_READ_RECORD_HANDLE;

typedef kal_int32 (*CBR_TRAVERSE_CB)(kal_uint16 type, kal_uint32 recordLen, void *param);

typedef struct FTL_FuncTbl *FTL_FuncTblPtr;
kal_int32 CBR_SetEnv(kal_uint32 cbrIdx, kal_uint32 *pBufAddr, kal_uint32 bufLen, FTL_FuncTblPtr pFtlFunc);
kal_int32 CBR_Init(kal_uint32 cbrIdx, kal_uint32 initialBlock);
kal_int32 CBR_InitEx(kal_uint32 cbrIdx, kal_uint32 initialBlock, kal_uint32 maxSearchBlock);
kal_int32 CBR_Create(kal_uint32 cbrIdx, kal_uint32 initialBlock, kal_uint32 normal, kal_uint32 fast, kal_uint32 spare, kal_uint32 autoExtendSpareMax, E_CBRMaxRecordMode maxRecordInRecord, kal_bool roMode);
kal_int32 CBR_WriteRecord(kal_uint32 cbrIdx, kal_uint16 type, const kal_uint8 *pData, kal_uint32 length, const void *pDpArg);
kal_int32 CBR_AddRecord(kal_uint32 cbrIdx, kal_uint16 type, const kal_uint8 *pData, kal_uint32 length, SDS_DP_TYPE dpType, const void *pDpArg);
kal_int32 CBR_DelRecord(kal_uint32 cbrIdx, kal_uint16 type);
kal_int32 CBR_ReadRecord(kal_uint32 cbrIdx, kal_uint16 type, kal_uint8 *pData, kal_uint32 length, const void *pDpArg);
kal_int32 CBR_ReadRecordEx(kal_uint32 cbrIdx, kal_uint16 type, kal_uint8 *pData, kal_uint32 length, kal_bool readPartial, const void *pDpArg);
kal_int32 CBR_GetRecordLen(kal_uint32 cbrIdx, kal_uint16 type);
kal_int32 CBR_GetParamInfo(kal_uint32 cbrIdx, CBR_PARAM_INFO *pParam);
kal_int32 CBR_DelRecordByMask(kal_uint32 cbrIdx, kal_uint16 typeMask, kal_uint16 typeValue);
kal_int32 CBR_TrverseRecord(kal_uint32 cbrIdx, CBR_TRAVERSE_CB cbFunc, void *param);
kal_int32 CBR_CalculateBlockParameter(kal_uint32 cbrIdx, kal_uint32 cbrRegionStart, kal_uint32 cbrRegionLen, kal_uint32 cbrFastLen, kal_uint32 cbrSpareLen,
                                      CBR_PARAM_INFO *pParam);

#endif /* _CBR_H_ */

