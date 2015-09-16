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
 *   sds_main.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Secure data storage, implementation
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __SECURE_DATA_STORAGE__

#include "cbr.h"
#include "FTL.h"
//#include "sds_type.h"

#include "custom_secure_config.h"
//#include "custom_sds_dp.h"

#ifdef __MTK_TARGET__
#include "kal_general_types.h" 
#endif

/*************************************************************************
 * Constant
 *************************************************************************/
#define SDS_PARTITION_DESCRIPTOR_TAG  "__SDS_PARTITION_DESCRIPTOR_TAG__"
#define SDS_PT_DESCRIPTOR_INDEX       (0)
#define SDS_RECORD_START              (1)

/*************************************************************************
 * Structure definition
 *************************************************************************/
typedef struct
{
   kal_uint8 magic_head[32];
   kal_uint32 password_len;
   kal_uint8 password[128];
   kal_uint32 attribute;
} SDS_PARTITION_DESCRIPTOR;

typedef struct
{
   SDS_PARTITION_TYPE partition;
   kal_uint32 count;
} CalRecordCountStruct;

typedef struct
{
   SDS_PARTITION_TYPE partition;
   kal_uint32 count;
   kal_uint32 *pList;
   kal_uint32 listSize;
} GetRecordListStruct;

/*************************************************************************
 * Global variables definition
 *************************************************************************/
static kal_uint32 sdsPageBuff[4096>>2];
#ifdef __MTK_TARGET__
static kal_mutexid sds_mutex;
#endif
#ifdef __PC_SIM__
static kal_uint32 locked = KAL_FALSE;
#endif
/*************************************************************************
 * Internal functions
 *************************************************************************/

/**********************************************************
Description : Get lock to access SDS
Input       : None
Output      : None
***********************************************************/
void SDS_ObtainLock(void)
{
#ifdef __MTK_TARGET__
   if(kal_query_systemInit() == KAL_FALSE)
   {
      kal_take_mutex(sds_mutex);
   }
#endif

#ifdef __PC_SIM__
   ASSERT(locked == KAL_FALSE);
   locked = KAL_TRUE;
#endif
}

/**********************************************************
Description : Release lock to access SDS
Input       : None
Output      : None
***********************************************************/
void SDS_ReleaseLock(void)
{
#ifdef __MTK_TARGET__
   if(kal_query_systemInit() == KAL_FALSE)
   {
      kal_give_mutex(sds_mutex);
   }
#endif
#ifdef __PC_SIM__
   ASSERT(locked == KAL_TRUE);
   locked = KAL_FALSE;
#endif
}

/**********************************************************
Description : Check if the access permission check is supported for the region
Input       : None
Output      : None
***********************************************************/
static kal_bool SDS_IsRegionSupportAccessCtrl(SDS_PARTITION_TYPE partition)
{
   if(partition == SDS_PT_NVRAM_PARTITION)
   {
      return KAL_FALSE;
   }
   
   return KAL_TRUE;
}

/**********************************************************
Description : Check the access permission
Input       : None
Output      : None
***********************************************************/
static kal_int32 SDS_CheckPermission(SDS_PARTITION_TYPE partition, kal_uint32 index, const kal_uint8* pPassword, const void *pDpArg)
{
   kal_int32 status = SDS_SUCCESS;
   SDS_PARTITION_DESCRIPTOR ptDscr;

   if(SDS_IsRegionSupportAccessCtrl(partition))
   {
      if(index == SDS_PT_DESCRIPTOR_INDEX)
      {
         status = SDS_ACCESS_DENIED;
      }
      else
      {
         status = CBR_ReadRecordEx(E_CBR_IDX_SRW, (partition<<SDS_PARTITION_SHIFT)|SDS_PT_DESCRIPTOR_INDEX, (kal_uint8*)&ptDscr, sizeof(ptDscr), KAL_FALSE, pDpArg);

         if(status == sizeof(ptDscr))
         {
            if(pPassword == NULL ||
               memcmp(ptDscr.magic_head, SDS_PARTITION_DESCRIPTOR_TAG, sizeof(SDS_PARTITION_DESCRIPTOR_TAG)-1) != 0 ||
               memcmp(ptDscr.password, pPassword, ptDscr.password_len) != 0)
            {
               status = SDS_ACCESS_DENIED;
            }
            else
            {
               status = SDS_SUCCESS;
            }
         }
         else if(status == CBR_NO_SPECIFIED_RECORD)
         {
            status = SDS_SUCCESS;
         }
      }
   }

   return status;
}

/**********************************************************
Description : Call function to calcuate the number of total records in a region
Input       : None
Output      : None
***********************************************************/
static kal_int32 SDS_CalRecordCountCB(kal_uint16 type, kal_uint32 recordLen, void *param)
{
   CalRecordCountStruct *pStruct = (CalRecordCountStruct*)param;

   if((type>>SDS_PARTITION_SHIFT) == pStruct->partition)
   {
      if(SDS_IsRegionSupportAccessCtrl(pStruct->partition) && 
         ((type & ~(0xffffffff<<SDS_PARTITION_SHIFT)) == SDS_PT_DESCRIPTOR_INDEX))
      {
         return 0;
      }
      
      pStruct->count++;      
   }
   return 0;
}

/**********************************************************
Description : Call function to generate the list of total record in a region
Input       : None
Output      : None
***********************************************************/
static kal_int32 SDS_GetRecordListCB(kal_uint16 type, kal_uint32 recordLen, void *param)
{
   GetRecordListStruct *pStruct = (GetRecordListStruct*)param;

   if((type>>SDS_PARTITION_SHIFT) == pStruct->partition)
   {
      if(SDS_IsRegionSupportAccessCtrl(pStruct->partition) && 
         (type & ~(0xffffffff<<SDS_PARTITION_SHIFT)) == SDS_PT_DESCRIPTOR_INDEX)
   {
         return 0;
      }
      
      if(pStruct->count < pStruct->listSize)
      {
         pStruct->pList[pStruct->count] = (type & ~(0xffffffff<<SDS_PARTITION_SHIFT));
         pStruct->count++;      
      }
      else
      {
         return -1;
      }
   }
   return 0;
}

/*************************************************************************
 * Exported APIs
 *************************************************************************/

/**********************************************************
Description : Initialization function
Input       : None
Output      : None
***********************************************************/
kal_int32 SDS_Init(void)
{
   kal_int32 status;
   kal_uint32 sdsBlockIdx;
   kal_uint32 sdsTotalBlockCount;
   kal_uint32 sdsNormalBlockCount;
   kal_uint32 sdsReservedBlockCount;
   extern FTL_FuncTbl ftlFuncTbl;   

   ftlFuncTbl.FTL_Init(NULL);

   CBR_SetEnv(E_CBR_IDX_SRW, sdsPageBuff, sizeof(sdsPageBuff), &ftlFuncTbl);

#if defined(_NAND_FLASH_BOOTING_) || defined(__EMMC_BOOTING__)
   {
      kal_uint32 blockSize;

      blockSize = ftlFuncTbl.FTL_GetBlockSize(0, NULL);

      ASSERT(SDS_TOTAL_SIZE % blockSize == 0);
      ASSERT(SDS_START_ADDR % blockSize == 0);   
      ASSERT(SDS_RESERVED_SIZE % blockSize == 0); 

      sdsBlockIdx = SDS_START_ADDR/blockSize;
      sdsTotalBlockCount = SDS_TOTAL_SIZE/blockSize;
      sdsReservedBlockCount = SDS_RESERVED_SIZE/blockSize;
   }
   
#else

   {
      kal_uint32 block, page;
      kal_uint32 i, totalSize;

      ftlFuncTbl.FTL_AddrToBlockPage(SDS_START_ADDR, &block, &page, NULL);
      ASSERT(page == 0);
      sdsBlockIdx = block;

      for(i=0, totalSize=0; totalSize<SDS_TOTAL_SIZE; i++)
      {
         totalSize += ftlFuncTbl.FTL_GetBlockSize(sdsBlockIdx+i, NULL);
      }
      ASSERT(totalSize == SDS_TOTAL_SIZE);
      sdsTotalBlockCount = i;

      ASSERT(SDS_RESERVED_SIZE == 0);
      sdsReservedBlockCount = 0;
   }
   
#endif

   ASSERT(sdsTotalBlockCount >= sdsReservedBlockCount + 2);

   sdsNormalBlockCount = (sdsTotalBlockCount - sdsReservedBlockCount)/2;

   status = CBR_InitEx(E_CBR_IDX_SRW, sdsBlockIdx, sdsTotalBlockCount);

   if(status == CBR_NO_BLOCK_FOUND)
   {
      status = CBR_Create(E_CBR_IDX_SRW, sdsBlockIdx, sdsNormalBlockCount, 0, sdsReservedBlockCount, 0, E_CBR_16_MAX_RECORD_IN_BLOCK, KAL_FALSE);
   }

   ASSERT(status >= 0);

#ifdef __MTK_TARGET__
   sds_mutex = kal_create_mutex("sds_mutex");
#endif

   return status;
}

/**********************************************************
Description : Enable the access control on a region by setting a password
Input       : None
Output      : None
***********************************************************/
kal_int32 SDS_SetPassword(SDS_PARTITION_TYPE partition, void *pPassword, kal_uint32 passwordLen, SDS_DP_TYPE dpType, void *pDpArg)
{
   kal_int32 status;
   SDS_PARTITION_DESCRIPTOR ptDscr;

   ASSERT((partition == SDS_PT_NVRAM_PARTITION) ||
          (partition >= SDS_PT_CUSTOMER_DEFINE_START && partition <= SDS_PT_CUSTOMER_DEFINE_END));

   SDS_ObtainLock();

   status = CBR_ReadRecordEx(E_CBR_IDX_SRW, (partition<<SDS_PARTITION_SHIFT)|SDS_PT_DESCRIPTOR_INDEX, (kal_uint8*)&ptDscr, sizeof(ptDscr), KAL_FALSE, pDpArg);

   if(status == CBR_NO_SPECIFIED_RECORD)
   {
      if(passwordLen <= sizeof(ptDscr.password))
      {
         memcpy(ptDscr.magic_head, SDS_PARTITION_DESCRIPTOR_TAG, sizeof(SDS_PARTITION_DESCRIPTOR_TAG)-1);
         ptDscr.password_len = passwordLen;
         memcpy(ptDscr.password, pPassword, passwordLen);
         ptDscr.attribute = 0;
            
         status = CBR_AddRecord(E_CBR_IDX_SRW, (partition<<SDS_PARTITION_SHIFT)|SDS_PT_DESCRIPTOR_INDEX, (kal_uint8*)&ptDscr, sizeof(ptDscr), dpType, pDpArg);
      }
      else
      {
         status = SDS_PASSWORD_TOO_LONG;         
      }
   }
   else
   {
      status = SDS_PASSWORD_HAS_SET;
   }

   SDS_ReleaseLock();

   return status;
   
}

/**********************************************************
Description : Add a record to SDS
Input       : None
Output      : None
***********************************************************/
kal_int32 SDS_AddRecordEx(SDS_PARTITION_TYPE partition, kal_uint32 index, const kal_uint8 *pData, kal_uint32 length, const kal_uint8 *pPassword, SDS_DP_TYPE dpType, const void *pDpArg)
{
   kal_int32 status;

   ASSERT((partition == SDS_PT_NVRAM_PARTITION) ||
          (partition >= SDS_PT_CUSTOMER_DEFINE_START && partition <= SDS_PT_CUSTOMER_DEFINE_END));
   
   ASSERT(index <= SDS_MAX_RECORD_INDEX);

   SDS_ObtainLock();
   
   status = SDS_CheckPermission(partition, index, pPassword, pDpArg);

   if(status == SDS_SUCCESS)
   {
      status = CBR_AddRecord(E_CBR_IDX_SRW, (partition<<SDS_PARTITION_SHIFT)|index, pData, length, dpType, pDpArg);
   }
   
   SDS_ReleaseLock();
   
   return status;
}

kal_int32 SDS_AddRecord(SDS_PARTITION_TYPE partition, kal_uint32 index, const kal_uint8 *pData, kal_uint32 length, SDS_DP_TYPE dpType)
{
   return SDS_AddRecordEx(partition, index, pData, length, NULL, dpType, NULL);
}

/**********************************************************
Description : Update an existing record ino SDS
Input       : None
Output      : None
***********************************************************/
kal_int32 SDS_UpdateRecordEx(SDS_PARTITION_TYPE partition, kal_uint32 index, const kal_uint8 *pData, kal_uint32 length, const kal_uint8 *pPassword, const void *pDpArg)
{
   kal_int32 status;

   ASSERT((partition == SDS_PT_NVRAM_PARTITION) ||
          (partition >= SDS_PT_CUSTOMER_DEFINE_START && partition <= SDS_PT_CUSTOMER_DEFINE_END));
   
   ASSERT(index <= SDS_MAX_RECORD_INDEX);

   SDS_ObtainLock();
   
   status = SDS_CheckPermission(partition, index, pPassword, pDpArg);

   if(status == SDS_SUCCESS)
   {
      status = CBR_WriteRecord(E_CBR_IDX_SRW, (partition<<SDS_PARTITION_SHIFT)|index, pData, length, pDpArg);
   }
   
   SDS_ReleaseLock();
   
   return status;
}

kal_int32 SDS_UpdateRecord(SDS_PARTITION_TYPE partition, kal_uint32 index, const kal_uint8 *pData, kal_uint32 length)
{
   return SDS_UpdateRecordEx(partition, index, pData, length, NULL, NULL);
}

/**********************************************************
Description : Read an existing record in SDS
Input       : None
Output      : None
***********************************************************/
kal_int32 SDS_ReadRecordEx(SDS_PARTITION_TYPE partition, kal_uint32 index, kal_uint8 *pData, kal_uint32 length, const kal_uint8 *pPassword, const void *pDpArg)
{
   kal_int32 status;

   ASSERT((partition == SDS_PT_NVRAM_PARTITION) ||
          (partition >= SDS_PT_CUSTOMER_DEFINE_START && partition <= SDS_PT_CUSTOMER_DEFINE_END));
   
   ASSERT(index <= SDS_MAX_RECORD_INDEX);

   SDS_ObtainLock();
   
   status = SDS_CheckPermission(partition, index, pPassword, pDpArg);
   
   if(status == SDS_SUCCESS)   
   {
      status = CBR_ReadRecord(E_CBR_IDX_SRW, (partition<<SDS_PARTITION_SHIFT)|index, pData, length, pDpArg);
   }
   
   SDS_ReleaseLock();
   
   return status;
}

kal_int32 SDS_ReadRecord(SDS_PARTITION_TYPE partition, kal_uint32 index, kal_uint8 *pData, kal_uint32 length)
{
   return SDS_ReadRecordEx(partition, index, pData, length, NULL, NULL);
}

/**********************************************************
Description : Delete an existing record in SDS
Input       : None
Output      : None
***********************************************************/
kal_int32 SDS_DelRecordEx(SDS_PARTITION_TYPE partition, kal_uint32 index, const kal_uint8 *pPassword, const void *pDpArg)
{
   kal_int32 status;

   ASSERT((partition == SDS_PT_NVRAM_PARTITION) ||
          (partition >= SDS_PT_CUSTOMER_DEFINE_START && partition <= SDS_PT_CUSTOMER_DEFINE_END));

   ASSERT(index <= SDS_MAX_RECORD_INDEX);

   SDS_ObtainLock();
   
   status = SDS_CheckPermission(partition, index, pPassword, pDpArg);

   if(status == SDS_SUCCESS)
   {
      status = CBR_DelRecord(E_CBR_IDX_SRW, (partition<<SDS_PARTITION_SHIFT)|index);
   }
   
   SDS_ReleaseLock();
   
   return status;
}

kal_int32 SDS_DelRecord(SDS_PARTITION_TYPE partition, kal_uint32 index)
{
   return SDS_DelRecordEx(partition, index, NULL, NULL);
}

/**********************************************************
Description : Delete all records in a given partition
Input       : None
Output      : None
Note that this function will remove all data and make the region as a whole new one
***********************************************************/
kal_int32 SDS_FormatPartitionEx(SDS_PARTITION_TYPE partition, const kal_uint8 *pPassword, const void *pDpArg)
{
   kal_int32 status;
   
   ASSERT((partition == SDS_PT_NVRAM_PARTITION) ||
          (partition >= SDS_PT_CUSTOMER_DEFINE_START && partition <= SDS_PT_CUSTOMER_DEFINE_END));

   SDS_ObtainLock();
   
   status = SDS_CheckPermission(partition, SDS_RECORD_START, pPassword, pDpArg);

   if(status == SDS_SUCCESS)
   {
      status = CBR_DelRecordByMask(E_CBR_IDX_SRW, (0xffff << SDS_PARTITION_SHIFT)&0xffff, partition<<SDS_PARTITION_SHIFT);
   }
   
   SDS_ReleaseLock();
   
   return status;
}

kal_int32 SDS_FormatPartition(SDS_PARTITION_TYPE partition)
{
   return SDS_FormatPartitionEx(partition, NULL, NULL);
}

/**********************************************************
Description : Get the number of records in a partition
Input       : None
Output      : None
***********************************************************/
kal_int32 SDS_GetRecordCountEx(SDS_PARTITION_TYPE partition, const kal_uint8 *pPassword, const void *pDpArg)
{
   kal_int32 status;
   CalRecordCountStruct cbParam;;
   
   ASSERT((partition == SDS_PT_NVRAM_PARTITION) ||
          (partition >= SDS_PT_CUSTOMER_DEFINE_START && partition <= SDS_PT_CUSTOMER_DEFINE_END));

   cbParam.partition = partition;
   cbParam.count = 0;

   SDS_ObtainLock();
   
   status = SDS_CheckPermission(partition, SDS_RECORD_START, pPassword, pDpArg);

   if(status == SDS_SUCCESS)
   {
      status = CBR_TrverseRecord(E_CBR_IDX_SRW, SDS_CalRecordCountCB, &cbParam);
   }

   SDS_ReleaseLock();

   if(status == CBR_SUCCESS)
   {
      return cbParam.count;
   }
   else
   {
      return status;
   }
}

kal_int32 SDS_GetRecordCount(SDS_PARTITION_TYPE partition)
{
   return SDS_GetRecordCountEx(partition, NULL, NULL);
}

/**********************************************************
Description : Get a list of all records in a partition
Input       : None
Output      : None
***********************************************************/
kal_int32 SDS_GetRecordListEx(SDS_PARTITION_TYPE partition, kal_uint32 *pIndexList, kal_uint32 num, const kal_uint8 *pPassword, const void *pDpArg)
{
   kal_int32 status;
   GetRecordListStruct cbParam;;
   
   ASSERT((partition == SDS_PT_NVRAM_PARTITION) ||
          (partition >= SDS_PT_CUSTOMER_DEFINE_START && partition <= SDS_PT_CUSTOMER_DEFINE_END));

   cbParam.partition = partition;
   cbParam.count     = 0;
   cbParam.pList     = pIndexList;
   cbParam.listSize  = num;

   SDS_ObtainLock();
   
   status = SDS_CheckPermission(partition, SDS_RECORD_START, pPassword, pDpArg);

   if(status == SDS_SUCCESS)
   {
      status = CBR_TrverseRecord(E_CBR_IDX_SRW, SDS_GetRecordListCB, &cbParam);
   }

   SDS_ReleaseLock();

   if(status == CBR_SUCCESS)
   {
      return cbParam.count;
   }
   else
   {
      if(cbParam.count == num)
      {
         return SDS_OUT_OF_SPACE;
      }
      
      return status;
   }
}

kal_int32 SDS_GetRecordList(SDS_PARTITION_TYPE partition, kal_uint32 *pIndexList, kal_uint32 num)
{
   return SDS_GetRecordListEx(partition, pIndexList, num, NULL, NULL);
}

/**********************************************************
Description : Get the length of a record
Input       : None
Output      : None
***********************************************************/
kal_int32 SDS_GetRecordLenEx(SDS_PARTITION_TYPE partition, kal_uint32 index, const kal_uint8 *pPassword, const void *pDpArg)
{
   kal_int32 status;
   
   ASSERT((partition == SDS_PT_NVRAM_PARTITION) ||
          (partition >= SDS_PT_CUSTOMER_DEFINE_START && partition <= SDS_PT_CUSTOMER_DEFINE_END));
   
   ASSERT(index <= SDS_MAX_RECORD_INDEX);

   SDS_ObtainLock();
   
   status = SDS_CheckPermission(partition, index, pPassword, pDpArg);

   if(status == SDS_SUCCESS)
   {
      status = CBR_GetRecordLen(E_CBR_IDX_SRW, (partition<<SDS_PARTITION_SHIFT)|index);
   }
   
   SDS_ReleaseLock();
   
   return status;
}

kal_int32 SDS_GetRecordLen(SDS_PARTITION_TYPE partition, kal_uint32 index)
{
   return SDS_GetRecordLenEx(partition, index, NULL, NULL);
}

/*************************************************************************
 * Test codes for UT
 *************************************************************************/
 
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

#endif

