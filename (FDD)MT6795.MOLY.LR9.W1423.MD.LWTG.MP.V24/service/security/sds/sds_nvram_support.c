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
 *   sds_nvram_support.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Secure data storage, implementation of specific part for nvram optimization
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
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __SECURE_DATA_STORAGE__
 
#ifdef __SDS_NVRAM_SUPPORT__

#include "cbr.h"
//#include "FTL.h"
#include "sds_type.h"

//#include "custom_secure_config.h"
#include "custom_sds_dp.h"


#ifdef __MTK_TARGET__
#include "kal_general_types.h" 
#endif

#if defined(WIN32) && defined(__PC_SIM__)
#include "win32_fs.h"
#else
#include "fs_type.h"
#include "fs_func.h"
#endif

/*************************************************************************
 * Constant and macro
 *************************************************************************/
#define PACKED_DATA_HEAD_TAG "SDS_PACKED_DATA"
#define MIN(a,b) ((a)<(b)?(a):(b))

/*************************************************************************
 * Structure definition
 *************************************************************************/
typedef struct
{
   kal_uint8   head_tag[16];
   kal_uint32  headDataLen;
   kal_uint32  fileDataLen;
   kal_uint32  fileCount;
   kal_uint32  reserved[1];
   
} PackedDataHeadStruct;

typedef struct
{
   kal_uint32  checksum;
   kal_uint32  offset;
} PACKED_DATA_INDEX;

typedef struct
{
   kal_uint32 fnLen;
   kal_uint32 contentLen;
} FileInfoStruct;

typedef struct
{
   kal_uint32 headDataLen;
   kal_uint32 fileDataLen;
   const kal_uint16 **pDirList;   
   const kal_uint16 **pFileList;

   kal_uint32 currentFile;
   kal_uint32 fileCount;
   kal_uint32 currentOffset;
   kal_uint8  state;
   kal_uint32 offset;

   FileInfoStruct currentFileInfo;

   kal_uint16 fileNameBuf[FS_MAX_PATH/2];

} PackNvramFilesStruct;

enum
{
   SDS_PACK_STATE_DUMP_INFO,         
   SDS_PACK_STATE_DUMP_NAME,         
   SDS_PACK_STATE_DUMP_CONTENT,      
   SDS_PACK_STATE_DUMP_DUMMY_BYTE,   
   SDS_PACK_STATE_LAST = SDS_PACK_STATE_DUMP_DUMMY_BYTE
} SDS_PACK_STATE;

/*************************************************************************
 * Global variables definition
 *************************************************************************/
static PackNvramFilesStruct *g_pPackNvramFileStruct;
static PackNvramFilesStruct g_packNvramData;

/*************************************************************************
 * External reference definition
 *************************************************************************/
extern kal_int32 CBR_Raw_ReadRecord(kal_uint32 cbrIdx, kal_uint16 type, kal_uint32 offset, kal_uint8 **ppData, CBR_RAW_READ_RECORD_HANDLE *pHandle);
extern void SDS_ReleaseLock(void);
extern void SDS_ObtainLock(void);

/*************************************************************************
 * Internal functions
 *************************************************************************/

static kal_int32 SDS_GetFileSize(const kal_uint16 *pFn)
{
   kal_int32 fd = FS_Open(pFn, FS_OPEN_NO_DIR | FS_READ_ONLY);
   kal_uint32 fileSize = 0;

   if(fd < 0)
   {
      return SDS_FILE_SYSTEM_ERROR;
   }

   if(FS_GetFileSize(fd, &fileSize) < 0)
   {
      FS_Close(fd);      
      return SDS_FILE_SYSTEM_ERROR;
   }

   FS_Close(fd);

   return fileSize;
}

static kal_uint32 SDS_CalcFilenameLen(const kal_uint16 *pFn)
{
   const kal_uint16 *p = pFn;
   
   while(*p)
   {
      p++;
   }

   return p-pFn;
}


static kal_uint32 SDS_CalcFilenameHash(const kal_uint16 *pFn, kal_uint32 len)
{
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
#endif

   //Fletcher
   kal_uint32 sum1 = 0;
   kal_uint32 sum2 = 0;
   
   while(len--)
   {
      sum1 += *pFn++;
      if (sum1 >= 0xffff)
      {
         sum1 -= 0xffff;
      }
      sum2 += sum1;
      if(sum2 >= 0xffff)
      {
         sum2 -= 0xffff;
      }
   }
   return ((sum2 << 16) | sum1);
}



static kal_uint32 SDS_ConcatPathAndFileName(kal_uint16 *pFullPath, const kal_uint16 *pDir, const kal_uint16 *pFile)
{
   kal_uint32 len = 0;
   kal_uint16 *p = pFullPath;
   
   //Count filename length
   if(pDir && *pDir)
   {
      len = SDS_CalcFilenameLen(pDir);
      memcpy(p, pDir, len*2);
      p += len;
      *p++ = '\\';
   }

   len = SDS_CalcFilenameLen(pFile);
   memcpy(p, pFile, len*2);
   p += len;
   *p = '\0';
   
   return p-pFullPath;
}


static kal_int32 SDS_RawReadCBRDataStream(kal_uint32 cbrIdx, kal_uint16 type, kal_uint32 offset, kal_uint8 *pData, kal_uint32 len, CBR_RAW_READ_RECORD_HANDLE *pHandle)
{
   kal_uint8 *pBuf;
   kal_int32 status;
   kal_uint32 copyLen;
   kal_uint32 toRead = len;

   while(toRead > 0)
   {
      status = CBR_Raw_ReadRecord(E_CBR_IDX_SRW, type, offset, &pBuf, pHandle);

      if(status <= 0)
      {
         return status;
      }
      copyLen = MIN((kal_uint32)status, toRead);
      memcpy(pData, pBuf, copyLen);
      pData += copyLen;
      offset += copyLen;
      toRead -= copyLen;
   }

   return len;   
}

/*************************************************************************
 * Internal DP call back for packing/unpacking the nvram files
 *************************************************************************/
 
static void SDS_NvramPack_GetInitInfo(kal_uint32 actual_src_len, kal_uint32 *p_occupied_src_len)
{
    *p_occupied_src_len = actual_src_len;
}


static kal_int32 SDS_NvramPack_Init(kal_uint32 attr, const void *p_arg, kal_uint32 *p_block_size)
{
    *p_block_size = 1;
    g_pPackNvramFileStruct = (PackNvramFilesStruct*)p_arg;
    return 0;
}

static void  SDS_NvramPack_DeInit(kal_uint32 attr)
{
    
}

static kal_int32 SDS_NvramPack_RdPostProcess(kal_uint8 *p_dst, kal_uint32 actual_dst_len, kal_uint32 dst_offset, const kal_uint8 *p_src, kal_uint32 len)
{
   kal_uint32 writtenLen;

   if(dst_offset == 0)
   {
      ASSERT(len >= sizeof(PackedDataHeadStruct));
   
      g_pPackNvramFileStruct->fileCount = ((PackedDataHeadStruct*)(p_src))->fileCount;
      g_pPackNvramFileStruct->headDataLen = ((PackedDataHeadStruct*)(p_src))->headDataLen;
      g_pPackNvramFileStruct->fileDataLen = ((PackedDataHeadStruct*)(p_src))->fileDataLen;
   }
   
   if(dst_offset < g_pPackNvramFileStruct->headDataLen)
   {
      if(dst_offset + len > g_pPackNvramFileStruct->headDataLen)
      {
         p_src += (g_pPackNvramFileStruct->headDataLen - dst_offset);
         len -= (g_pPackNvramFileStruct->headDataLen - dst_offset);
         g_pPackNvramFileStruct->state = 0;
      }
      else
      {
         p_src += len;
         len = 0;
      }
   }


   while(len)
   {
      kal_uint8 *pDst = NULL;
      kal_uint32 copyLen = 0;
      kal_bool stageDone = KAL_FALSE;
      kal_uint32 dummy = 0xcdcdcdcd;
      
      switch(g_pPackNvramFileStruct->state)
      {
         case SDS_PACK_STATE_DUMP_INFO:
         {
            pDst = (kal_uint8*)(&g_pPackNvramFileStruct->currentFileInfo) + g_pPackNvramFileStruct->offset;
            copyLen = sizeof(g_pPackNvramFileStruct->currentFileInfo) - g_pPackNvramFileStruct->offset;
         }
         break;

         case SDS_PACK_STATE_DUMP_NAME:
         {
            pDst = (kal_uint8*)(&g_pPackNvramFileStruct->fileNameBuf) + g_pPackNvramFileStruct->offset;
            copyLen = g_pPackNvramFileStruct->currentFileInfo.fnLen - g_pPackNvramFileStruct->offset;
         }
         break;

         case SDS_PACK_STATE_DUMP_CONTENT:
         {
            pDst = NULL;
            copyLen = g_pPackNvramFileStruct->currentFileInfo.contentLen - g_pPackNvramFileStruct->offset;
         }
         break;

         case SDS_PACK_STATE_DUMP_DUMMY_BYTE:
         {
            pDst = (kal_uint8*)&dummy;
            copyLen = (4-(g_pPackNvramFileStruct->currentFileInfo.fnLen + g_pPackNvramFileStruct->currentFileInfo.contentLen) % 4) % 4;
         }
         break;
      }

      if(copyLen > len)
      {
         copyLen = len;
      }
      else
      {
         stageDone = KAL_TRUE;
      }

      if(g_pPackNvramFileStruct->state != SDS_PACK_STATE_DUMP_CONTENT)
      {
         memcpy(pDst, p_src, copyLen);
      }
      else
      {
         kal_int32 fsRet;
         kal_int32 fd = -1;

         if(g_pPackNvramFileStruct->offset == 0)
         {
            fd = FS_Open(g_pPackNvramFileStruct->fileNameBuf, FS_OPEN_NO_DIR | FS_CREATE_ALWAYS);
         }
         else
         {
            fd = FS_Open(g_pPackNvramFileStruct->fileNameBuf, FS_OPEN_NO_DIR | FS_READ_WRITE);
         }

         if(fd >= 0)
         {
            fsRet = FS_Seek(fd, g_pPackNvramFileStruct->offset, FS_FILE_BEGIN);
            if(fsRet >= 0)
            {
               fsRet = FS_Write(fd, (void*)p_src, copyLen, &writtenLen);
            }
            FS_Close(fd);
         }

         if(fd < 0 || fsRet < 0 || copyLen != writtenLen)
         {
            goto _fsError;
         }
      }

      g_pPackNvramFileStruct->offset += copyLen;
      len -= copyLen;
      p_src += copyLen;

      if(stageDone)
      {
         if(g_pPackNvramFileStruct->state == SDS_PACK_STATE_LAST)
         {
            g_pPackNvramFileStruct->state = 0;
            g_pPackNvramFileStruct->currentFile++;
         }
         else
         {
            g_pPackNvramFileStruct->state++;
         }
         g_pPackNvramFileStruct->offset = 0;
      }      
      
   }

   return len;
   
_fsError:
   return SDS_WRITE_FS_ERROR;
}

static kal_int32 SDS_NvramPack_WrPreProcess(const kal_uint8 *p_src, kal_uint32 actual_src_len, kal_uint32 src_offset, kal_uint8 *p_dst, kal_uint32 len)
{
    kal_uint32 i, n;

/*
    Packed data structure:
    HEAD_PART>>
       Head structure
       Index * n
    CONTENT_PART
       {
         FileInfoStruct
         Filename m bytes, NULL
         File Content
       } * n
*/    

   PackedDataHeadStruct *pPackedDataHead = NULL;
   PACKED_DATA_INDEX *pIndex = NULL;

   kal_uint32 readLen;

   if(src_offset < sizeof(PackedDataHeadStruct) + sizeof(PACKED_DATA_INDEX)*g_pPackNvramFileStruct->fileCount)
   {
      //Still in head part
      if(src_offset == 0)
      {
         pPackedDataHead = (PackedDataHeadStruct*)p_dst;
         pIndex = (PACKED_DATA_INDEX*)(pPackedDataHead+1);
               
         ASSERT(len > sizeof(PackedDataHeadStruct) /* && (len - sizeof(PackedDataHeadStruct) % sizeof(PACKED_DATA_INDEX)) == 0 Todo */);

         memset(pPackedDataHead, 0x00, sizeof(PackedDataHeadStruct));
         memcpy(pPackedDataHead->head_tag, PACKED_DATA_HEAD_TAG, sizeof(PACKED_DATA_HEAD_TAG));

         pPackedDataHead->fileCount = g_pPackNvramFileStruct->fileCount;
         pPackedDataHead->headDataLen = g_pPackNvramFileStruct->headDataLen;
         pPackedDataHead->fileDataLen = g_pPackNvramFileStruct->fileDataLen;

         n = (len-sizeof(PackedDataHeadStruct))/sizeof(PACKED_DATA_INDEX);
         
         g_pPackNvramFileStruct->currentOffset = g_pPackNvramFileStruct->headDataLen;

      }
      else
      {
         ASSERT(len % sizeof(PACKED_DATA_INDEX) == 0);

         pIndex = (PACKED_DATA_INDEX*)p_dst;
         n = len/sizeof(PACKED_DATA_INDEX);
      }

      for(i=0; i<n; i++)
      {
         kal_uint32 fnLen = SDS_ConcatPathAndFileName(g_pPackNvramFileStruct->fileNameBuf, 
            g_pPackNvramFileStruct->pDirList[g_pPackNvramFileStruct->currentFile], 
            g_pPackNvramFileStruct->pFileList[g_pPackNvramFileStruct->currentFile]);
         
         kal_int32 fileLen = SDS_GetFileSize(g_pPackNvramFileStruct->fileNameBuf);

         if(fileLen < 0)
         {
            goto _fsError;
         }
         
         pIndex->checksum = SDS_CalcFilenameHash(g_pPackNvramFileStruct->fileNameBuf, fnLen);
         pIndex->offset   = g_pPackNvramFileStruct->currentOffset;

         g_pPackNvramFileStruct->currentOffset += (((sizeof(FileInfoStruct) + (fnLen+1)*2 + fileLen)+3)>>2)<<2;
         g_pPackNvramFileStruct->currentFile++;

         pIndex++;

         if(g_pPackNvramFileStruct->currentFile == g_pPackNvramFileStruct->fileCount)
         {
            break;
         }
      }

      if(g_pPackNvramFileStruct->currentFile == g_pPackNvramFileStruct->fileCount)
      {
         //All files are indexed, switch to body part
         //Reset to process the file contents
         g_pPackNvramFileStruct->currentFile = 0;
      }
      len -= ((kal_uint8*)pIndex - p_dst);
      p_dst = (kal_uint8*)pIndex;
   }

   while(len)
   {
      kal_uint8 *pSrc = NULL;
      kal_uint32 copyLen = 0;
      kal_bool stageDone = KAL_FALSE;
      kal_uint32 dummy = 0xcdcdcdcd;

      switch(g_pPackNvramFileStruct->state)
      {
         case SDS_PACK_STATE_DUMP_INFO:
         {
            SDS_ConcatPathAndFileName(g_pPackNvramFileStruct->fileNameBuf, 
               g_pPackNvramFileStruct->pDirList[g_pPackNvramFileStruct->currentFile], 
               g_pPackNvramFileStruct->pFileList[g_pPackNvramFileStruct->currentFile]);
            
            pSrc = (kal_uint8*)(&g_pPackNvramFileStruct->currentFileInfo) + g_pPackNvramFileStruct->offset;
            copyLen = sizeof(g_pPackNvramFileStruct->currentFileInfo) - g_pPackNvramFileStruct->offset;

            if(g_pPackNvramFileStruct->offset == 0)
            {
               kal_int32 fileLen = SDS_GetFileSize(g_pPackNvramFileStruct->fileNameBuf);
               
               if(fileLen < 0)
               {
                  goto _fsError;
               }
               
               g_pPackNvramFileStruct->currentFileInfo.contentLen = fileLen;
               g_pPackNvramFileStruct->currentFileInfo.fnLen = (SDS_CalcFilenameLen(g_pPackNvramFileStruct->fileNameBuf)+1)*2;
            }

         }
         break;

         case SDS_PACK_STATE_DUMP_NAME:
         {
            pSrc = (kal_uint8*)(g_pPackNvramFileStruct->fileNameBuf) + g_pPackNvramFileStruct->offset;
            copyLen = g_pPackNvramFileStruct->currentFileInfo.fnLen - g_pPackNvramFileStruct->offset;
            
         }
         break;

         case SDS_PACK_STATE_DUMP_CONTENT:
         {
            pSrc = NULL;
            copyLen = g_pPackNvramFileStruct->currentFileInfo.contentLen - g_pPackNvramFileStruct->offset;
         }
         break;

         case SDS_PACK_STATE_DUMP_DUMMY_BYTE:
         {
            pSrc = (kal_uint8*)&dummy;
            copyLen = (4-(g_pPackNvramFileStruct->currentFileInfo.fnLen + g_pPackNvramFileStruct->currentFileInfo.contentLen) % 4) % 4;
         }
      }

      if(copyLen > len)
      {
         copyLen = len;
      }
      else
      {
         stageDone = KAL_TRUE;
      }

      if(g_pPackNvramFileStruct->state != SDS_PACK_STATE_DUMP_CONTENT)
      {
         memcpy(p_dst, pSrc, copyLen);
      }
      else
      {
         kal_int32 fsRet;
         kal_int32 fd = -1;
         
         fd = FS_Open(g_pPackNvramFileStruct->fileNameBuf, FS_OPEN_NO_DIR | FS_READ_ONLY);

         if(fd >= 0)
         {
            fsRet = FS_Seek(fd, g_pPackNvramFileStruct->offset, FS_FILE_BEGIN);
            if(fsRet >= 0)
            {
               fsRet = FS_Read(fd, p_dst, copyLen, &readLen);
            }
            FS_Close(fd);
         }

         if(fd < 0 || fsRet < 0 || copyLen != readLen)
         {
            goto _fsError;
         }
      }

      g_pPackNvramFileStruct->offset += copyLen;
      len -= copyLen;
      p_dst += copyLen;

      if(stageDone)
      {
         
         if(g_pPackNvramFileStruct->state == SDS_PACK_STATE_LAST)
         {
            g_pPackNvramFileStruct->state = 0;
            g_pPackNvramFileStruct->currentFile++;
         }
         else
         {
            g_pPackNvramFileStruct->state++;
         }
         g_pPackNvramFileStruct->offset = 0;
      }

   }

   return len;
   
_fsError:
   return SDS_READ_FS_ERROR;
}

static const SDS_DP_Callback SDS_NvramPack_Callbacks = { SDS_NvramPack_GetInitInfo, SDS_NvramPack_Init, SDS_NvramPack_DeInit, SDS_NvramPack_RdPostProcess, SDS_NvramPack_WrPreProcess };

/*************************************************************************
 * Exported APIs for SDS NVRAM support
 *************************************************************************/

/**********************************************************
Description : Pack nvram files to a record
Input       : None
Output      : None
Note        : 1. Copy all files specified by 'pFileList' into one record  in SDS nvram partition
              2. All files should be with full path
              3. Target record in SDS will always be overwritten
***********************************************************/
kal_int32 SDS_PackNvramFilesToRecord(kal_uint32 index, const kal_uint16 **pDirList, const kal_uint16 **pFileList, kal_int32 fileCount)
{
   kal_int32 status;
   kal_int32 len;
   kal_int32 i;
   kal_int32 length;

   memset(&g_packNvramData, 0x00, sizeof(g_packNvramData));
   g_packNvramData.headDataLen = sizeof(PackedDataHeadStruct);
   g_packNvramData.fileDataLen = 0;
   g_packNvramData.pDirList = pDirList;
   g_packNvramData.pFileList = pFileList;
   g_packNvramData.fileCount = fileCount;

   for(i=0; i<fileCount; i++)
   {
      kal_uint32 fnLen = SDS_ConcatPathAndFileName(g_packNvramData.fileNameBuf, pDirList[i], pFileList[i]);
      kal_int32 fileSize = SDS_GetFileSize(g_packNvramData.fileNameBuf);
      
      if(fileSize < 0)
      {
         return fileSize;
      }

      //Prepare filename buffer
      g_packNvramData.headDataLen += sizeof(PACKED_DATA_INDEX);
      g_packNvramData.fileDataLen += (((sizeof(FileInfoStruct) + (fnLen+1)*2 + fileSize)+3)>>2)<<2;
   }

   length = g_packNvramData.headDataLen + g_packNvramData.fileDataLen;

   len = SDS_GetRecordLen(SDS_PT_NVRAM_PARTITION, index);

   if(len == SDS_NO_SPECIFIED_RECORD)
   {
      status = SDS_AddRecordEx(SDS_PT_NVRAM_PARTITION, index, (kal_uint8*)(&SDS_NvramPack_Callbacks), length, NULL, SDS_DP_EXTERNAL, &g_packNvramData);
   }
   else
   {
      status = SDS_UpdateRecordEx(SDS_PT_NVRAM_PARTITION, index, (kal_uint8*)(&SDS_NvramPack_Callbacks), length, NULL, &g_packNvramData);
   }
   
   if(status >= SDS_SUCCESS)
   {
      status = SDS_SUCCESS;
   }

   return status;
   
}

/**********************************************************
Description : Unpack nvram files from a record
Input       : None
Output      : None
Note        : 1. Restore all files packed in SDS record to their original position in the FAT
              2. All files will be overwritten
***********************************************************/
kal_int32 SDS_RestoreNvramFilesFromRecord(kal_uint32 index)
{
   kal_int32 status;

   memset(&g_packNvramData, 0x00, sizeof(g_packNvramData));

   status = SDS_GetRecordLen(SDS_PT_NVRAM_PARTITION, index);

   if(status >= SDS_SUCCESS)
   {
      kal_int32 len = status;
      status = SDS_ReadRecordEx(SDS_PT_NVRAM_PARTITION, index, (kal_uint8*)(&SDS_NvramPack_Callbacks), len, NULL, &g_packNvramData);
      
      if(status == len)
      {
         status = SDS_SUCCESS;
      }
   }
   
   return status;
   
}


/**********************************************************
Description : Read a file in speified record directly
Input       : None
Output      : None
Note        : 1. Read a specific nvram file from packed data in SDS record
              2. Return failure if no such file exists
              3. The filename is with full path and should be exactly the same as that was provided in invoking SDS_PackNvramFilesToRecord (case sensitive)
***********************************************************/
kal_int32 SDS_ReadNvramFileInRecord(kal_uint32 index, const kal_uint16 *pFilename, kal_uint8* pBuf, kal_uint32 bufLen)
{
   kal_int32 status;
   CBR_RAW_READ_RECORD_HANDLE rawReadHandle;
   kal_uint32 cbrRecord;
   kal_uint32 i, n;
   kal_uint32 fnLen, fnChecksum;
   kal_uint32 dataLen = 0xffffffff;
   kal_uint32 offset;
   PackedDataHeadStruct *pHead;
   
   ASSERT(index <= SDS_MAX_RECORD_INDEX);
   ASSERT((pBuf == NULL && bufLen == 0) || (pBuf != NULL && bufLen != 0));

   fnLen = SDS_CalcFilenameLen(pFilename);
   fnChecksum = SDS_CalcFilenameHash(pFilename, fnLen );

   cbrRecord = (SDS_PT_NVRAM_PARTITION<<SDS_PARTITION_SHIFT)|index;

   memset(&rawReadHandle, 0x00, sizeof(rawReadHandle));
   memset(&g_packNvramData, 0x00, sizeof(g_packNvramData));

   SDS_ObtainLock();

   status = CBR_Raw_ReadRecord(E_CBR_IDX_SRW, cbrRecord, 0, (kal_uint8**)&pHead, &rawReadHandle);

   if(status <= 0)
   {
      goto _error;
   }

   //According to design, offset=0 imply CBR RAW Read will read the whole page,
   //PackedDataHeadStruct size should be always smaller than it
   ASSERT(status >= sizeof(PackedDataHeadStruct));

   if(memcmp(pHead->head_tag, PACKED_DATA_HEAD_TAG, sizeof(PACKED_DATA_HEAD_TAG)) != 0)
   {
      status = SDS_INVALID_PACKED_DATA_HEAD;
      goto _error;
   }

   g_packNvramData.fileCount = pHead->fileCount;
   g_packNvramData.headDataLen = pHead->headDataLen;
   g_packNvramData.fileDataLen = pHead->fileDataLen;

   offset = sizeof(PackedDataHeadStruct);
   n = 0;

   while(dataLen == 0xffffffff && n < g_packNvramData.fileCount) 
   {
      kal_uint32 toReadRecord;
      PACKED_DATA_INDEX indexes[10];

      toReadRecord = MIN(g_packNvramData.fileCount-n, sizeof(indexes)/sizeof(indexes[0]));
      
      status = SDS_RawReadCBRDataStream(E_CBR_IDX_SRW, cbrRecord, offset, (kal_uint8*)indexes, sizeof(indexes[0])*toReadRecord, &rawReadHandle);

      if(status <= 0)
      {
         goto _error;
      }

      for(i=0; i<toReadRecord; i++, n++, offset += sizeof(FileInfoStruct))
      {
         if(indexes[i].checksum == fnChecksum)
         {
            FileInfoStruct fileInfo;
            //Same checksum, double confirm the file name
            status = SDS_RawReadCBRDataStream(E_CBR_IDX_SRW, cbrRecord, indexes[i].offset, (kal_uint8*)&fileInfo, sizeof(fileInfo), &rawReadHandle);

            if(status >= 0)
            {
               status = SDS_RawReadCBRDataStream(E_CBR_IDX_SRW, cbrRecord, indexes[i].offset + sizeof(fileInfo), (kal_uint8*)&g_packNvramData.fileNameBuf, MIN(fileInfo.fnLen, sizeof(g_packNvramData.fileNameBuf)), &rawReadHandle);
            }
            
            if(status >= 0)
            {
               if(memcmp(g_packNvramData.fileNameBuf, pFilename, fileInfo.fnLen) == 0)
               {
                  //Found it
                  offset = indexes[i].offset + sizeof(fileInfo) + fileInfo.fnLen;
                  dataLen = fileInfo.contentLen;
                  break;
               }
            }

            if(status < 0)
            {
               goto _error;
            }
         }
      }
      
   }

   if(dataLen == 0xffffffff)
   {
      status = SDS_FILE_NOT_FOUND_IN_PACKED_RECORD;
      goto _error;
   }

   if(pBuf)
   {
      if(bufLen < dataLen)
      {
         status = SDS_BUF_TOO_SMALL;
         goto _error;
      }
      
      status = SDS_RawReadCBRDataStream(E_CBR_IDX_SRW, cbrRecord, offset, pBuf, dataLen, &rawReadHandle);

      if(status <= 0)
      {
         goto _error;
      }
   }

   SDS_ReleaseLock();
   return dataLen;

_error: 
   
   SDS_ReleaseLock();
   return status;
   
}

/**********************************************************
Description : Get the length a file in speified record
Input       : None
Output      : None
***********************************************************/
kal_int32 SDS_GetNvramFileLengthInRecord(kal_uint32 index, const kal_uint16 *pFilename)
{
   return SDS_ReadNvramFileInRecord(index, pFilename, 0, 0);
}


/*************************************************************************
 * Test codes for UT
 *************************************************************************/
#ifdef __MTK_INTERNAL__

kal_int32 SDS_RawReadCBRForTest(kal_uint32 index, kal_uint8 *pData, kal_uint32 len)
{
   CBR_RAW_READ_RECORD_HANDLE readHandle;
   kal_uint16 cbrRecord = (SDS_PT_NVRAM_PARTITION<<SDS_PARTITION_SHIFT)|index;
   
   memset(&readHandle, 0x00, sizeof(readHandle));

   return SDS_RawReadCBRDataStream(E_CBR_IDX_SRW, cbrRecord, 0, pData, len, &readHandle);
}

kal_int32 SDS_RestoreNvramFilesFromRecord_Sim(kal_uint32* pBuf)
{
   kal_uint8 *p = (kal_uint8*)pBuf;
   kal_int32 fd;
   kal_uint32 len;
   kal_uint32 fileCount = 0;
   
   PackedDataHeadStruct *pHead;
   FileInfoStruct *pFileInfo = NULL;

   kal_uint16 buf[FS_MAX_PATH];
   
   ASSERT( ((kal_uint32)p)%4 == 0);
   
   pHead = (PackedDataHeadStruct*)p;

   p += pHead->headDataLen;


   while(fileCount < pHead->fileCount)
   {
      pFileInfo = (FileInfoStruct*)p;
      p += sizeof(FileInfoStruct);

      memcpy(buf, p, pFileInfo->fnLen);
      p += pFileInfo->fnLen;

      fd = FS_Open(buf, FS_OPEN_NO_DIR | FS_READ_ONLY);

      ASSERT(fd>=0);

      FS_GetFileSize(fd, &len);

      ASSERT(len == pFileInfo->contentLen);

      while(len)
      {
         kal_uint32 readLen = 0;
         kal_uint32 n = len;
         kal_int32 fsRet;
         
         if(n > sizeof(buf))
         {
            n = sizeof(buf);
         }

         memset(buf, 0xcd, sizeof(buf));
         fsRet = FS_Read(fd, buf, n, &readLen);

         ASSERT(fsRet >=0 && readLen == n);
         ASSERT(memcmp(p, buf, n) == 0);

         p += n;
         len -= n;
      }

      FS_Close(fd);
      p += (4-(pFileInfo->fnLen + pFileInfo->contentLen) % 4) % 4;

      fileCount++;
   }

   return fileCount;
}

kal_int32 SDS_PackNvramFilesToRecord_Sim(kal_uint32* pBuf, const kal_uint16 **pDirList, const kal_uint16 **pFileList, kal_int32 fileCount)
{
   kal_int32 i;
   kal_uint8 *p = (kal_uint8*)pBuf;

   PackedDataHeadStruct *pHead;
   PACKED_DATA_INDEX *pIndex;

   ASSERT( ((kal_uint32)p)%4 == 0);
   
   pHead = (PackedDataHeadStruct*)p;
   memset(pHead, 0x00, sizeof(PackedDataHeadStruct));
   pHead->fileCount = fileCount;
   memcpy(pHead->head_tag, PACKED_DATA_HEAD_TAG, sizeof(PACKED_DATA_HEAD_TAG));
   
   p += sizeof(PackedDataHeadStruct);
   
   pIndex = (PACKED_DATA_INDEX*)p;
   p += sizeof(PACKED_DATA_INDEX)*fileCount;

   pHead->headDataLen = p-(kal_uint8*)pBuf;
      
   for(i=0; i<fileCount; i++)
   {
      kal_uint16 fileNameBuf[FS_MAX_PATH]; 
      FileInfoStruct fileInfo;
      kal_uint32 fnLen = SDS_ConcatPathAndFileName(fileNameBuf, pDirList[i], pFileList[i]);
      kal_int32 fileLen = SDS_GetFileSize(fileNameBuf);
      pIndex[i].checksum = SDS_CalcFilenameHash(fileNameBuf, fnLen);
      pIndex[i].offset = (kal_uint32)(p-(kal_uint8*)pBuf);

      fileInfo.contentLen = fileLen;
      fileInfo.fnLen = (fnLen+1)*2;

      memcpy(p, &fileInfo, sizeof(fileInfo));
      p += sizeof(fileInfo);

      memcpy(p, fileNameBuf, fileInfo.fnLen);
      p += fileInfo.fnLen;

      {
         kal_int32 status;
         kal_uint32 readLen;
         
         kal_int32 fd = FS_Open(fileNameBuf, FS_OPEN_NO_DIR | FS_READ_ONLY);
         ASSERT(fd >= 0);
         status = FS_Read(fd, p, fileLen, &readLen);
         ASSERT(status >= 0 && readLen == fileLen);
         FS_Close(fd);

         p += fileLen;
      }

      while((kal_uint32)p % 4)
      {
         *p++ = 0xcd;
      }
   }
   
   pHead->fileDataLen = p-(kal_uint8*)pBuf - pHead->headDataLen;

   return p-(kal_uint8*)pBuf;
}

kal_int32 SDS_ReadNvramFileInRecord_sim(const kal_uint16 *pFilename, kal_uint8* pBuf, kal_uint32 bufLen)
{
   kal_int32 status;
   kal_uint32 readLen, fileLen;
   
   kal_int32 fd = FS_Open(pFilename, FS_OPEN_NO_DIR | FS_READ_ONLY);
   ASSERT(fd >= 0);
   
   status = FS_GetFileSize(fd, &fileLen);
   ASSERT(status >= 0);

   if(pBuf == NULL && bufLen == 0)
   {
      return fileLen;
   }

   if(bufLen < fileLen)
   {
      return SDS_BUF_TOO_SMALL;
   }
   
   status = FS_Read(fd, pBuf, fileLen, &readLen);
   ASSERT(status >= 0 && readLen == fileLen);
   
   FS_Close(fd);

   return readLen;
}

#if 1
static kal_uint8 SDS_Nvram_TestBuf[4096];

kal_int32 SDS_NvramSupportTest(void)
{
   #define TEST_IDX 123
   kal_int32 status;
   const kal_uint16 *filelist[] = {L"test0", L"test1", L"test2", L"test3"};
   const kal_uint16 *dirlist[] = {L"Z:", L"Z:", L"Z:", L"Z:"};
   const kal_uint32  filesize[] = {0, 2048, 4097, 128*1024};

   kal_int32 fd, fsRet = 0, i, j;
   kal_uint32 toWrite, writtenLen;
   kal_uint32 toRead, readLen;   

   for(i=0; i<sizeof(filelist)/sizeof(*filelist); i++)
   {
      kal_uint16 buf[FS_MAX_PATH];
      SDS_ConcatPathAndFileName(buf, dirlist[i], filelist[i]);
      
      memset(SDS_Nvram_TestBuf, i, sizeof(SDS_Nvram_TestBuf));
      
      fd = FS_Open(buf, FS_OPEN_NO_DIR | FS_CREATE_ALWAYS);

      ASSERT(fd >= 0);
      
      if(fd >=0)
      {
         toWrite = filesize[i];
         while(toWrite && fsRet >= 0)
         {
            fsRet = FS_Write(fd, SDS_Nvram_TestBuf, toWrite<sizeof(SDS_Nvram_TestBuf)?toWrite:sizeof(SDS_Nvram_TestBuf), &writtenLen);
            toWrite -= writtenLen;
         }
      }

      FS_Close(fd);
   }

   status = SDS_PackNvramFilesToRecord(TEST_IDX, dirlist, filelist, sizeof(filelist)/sizeof(*filelist));
   ASSERT(status == 0);

   for(i=0; i<sizeof(filelist)/sizeof(*filelist); i++)
   {
      kal_uint16 buf[FS_MAX_PATH];
      SDS_ConcatPathAndFileName(buf, dirlist[i], filelist[i]);
      
      memset(SDS_Nvram_TestBuf, 0, sizeof(SDS_Nvram_TestBuf));

      ASSERT(SDS_GetNvramFileLengthInRecord(TEST_IDX, buf) == filesize[i]);

      status = SDS_ReadNvramFileInRecord(TEST_IDX, buf, SDS_Nvram_TestBuf, sizeof(SDS_Nvram_TestBuf));

      if(status >= 0)
      {
         for(j=0; j<filesize[i]; j++)
         {
            ASSERT(SDS_Nvram_TestBuf[j] == i);
         }
      }
      else if(status == SDS_BUF_TOO_SMALL)
      {
         ASSERT(filesize[i] > sizeof(SDS_Nvram_TestBuf));
      }
      else
      {
         ASSERT(0);
      }
   }

   //Destory the originial file
   for(i=0; i<sizeof(filelist)/sizeof(*filelist); i++)
   {
      kal_uint16 buf[FS_MAX_PATH];
      SDS_ConcatPathAndFileName(buf, dirlist[i], filelist[i]);
      
      memset(SDS_Nvram_TestBuf, 0xcd, sizeof(SDS_Nvram_TestBuf));
      
      fd = FS_Open(buf, FS_OPEN_NO_DIR | FS_CREATE_ALWAYS);

      ASSERT(fd >= 0);
      
      if(fd >=0)
      {
         FS_Write(fd, SDS_Nvram_TestBuf, 16, &writtenLen);
      }

      FS_Close(fd);

      if(i%2)
      {
//         FS_DeletFile?
      }
   }

   status = SDS_RestoreNvramFilesFromRecord(TEST_IDX);
   ASSERT(status >= 0);

   for(i=0; i<sizeof(filelist)/sizeof(*filelist); i++)
   {
      kal_uint16 buf[FS_MAX_PATH];
      SDS_ConcatPathAndFileName(buf, dirlist[i], filelist[i]);
      
      memset(SDS_Nvram_TestBuf, 0xcd, sizeof(SDS_Nvram_TestBuf));
      
      fd = FS_Open(buf, FS_OPEN_NO_DIR);

      ASSERT(fd >= 0);
      
      if(fd >=0)
      {
         FS_Seek(fd, 0, 0);
         
         toRead = filesize[i];
         while(toRead && fsRet >= 0)
         {
            fsRet = FS_Read(fd, SDS_Nvram_TestBuf, MIN(toRead, sizeof(SDS_Nvram_TestBuf)), &readLen);
            toRead -= readLen;

            for(j=0; j<readLen; j++)
            {
               ASSERT(SDS_Nvram_TestBuf[j] == i);
            }
         }
      }

      FS_Close(fd);
   }
   
   return 0;
}
#endif

#endif /* __MTK_INTERNAL__ */


#endif /* __SDS_NVRAM_SUPPORT__ */
#endif /* __SECURE_DATA_STORAGE__ */

