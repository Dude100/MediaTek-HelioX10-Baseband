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
 *   Implementation of Control block region facilities
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__) || defined(__SECURE_DATA_STORAGE__)


#if defined(WIN32) && defined(__PC_SIM__)
#include "win32_types.h"
#include "FTL.h"
#define PRINT printf
#define __DEBUG_ASSERT__
#define __CBR_TRANS_MSG__
#elif defined(__UBL__)
#include "bl_types.h"
#include "FTL.h"
#define PRINT dbg_print
extern void dbg_print(kal_char *fmt, ...);
#elif defined(__DOWNLOAD_AGENT__)
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "da_FTL.h"
#define PRINT
#define __DEBUG_ASSERT__
#define __CBR_TRANS_MSG__
#else
#include "kal_general_types.h" 
#include "sw_types.h"
#include "FTL.h"
#define PRINT(...)
#endif

#include "cbr.h"

#ifndef __DOWNLOAD_AGENT__
#include "sds_type.h"
#include "custom_sds_dp.h"
#include <string.h>
#endif

#ifdef __MTK_INTERNAL__
#if defined(__DOWNLOAD_AGENT__)
#define CBR_CREATER 0x47414c44   //DLAG
#elif defined(__NAND_WRITER_SIMULATE__)
#define CBR_CREATER 0x5254574e   //NWTR
#elif defined(__PC_SIM__)
#define CBR_CREATER 0x4d534350   //PCSM
#else
#define CBR_CREATER 0x50484f4e   //PHON
#endif
#endif /* __MTK_INTERNAL__ */

#ifndef CBR_CREATER
#define CBR_CREATER 0x50484f4e   //PHON
#endif

#define ROOT_RECORD_IDENTIFIER   "ROOT1112.1"

#ifdef __DEBUG_ASSERT__
#ifdef ASSERT
#undef ASSERT
#endif
#define ASSERT(expr) do {if(!(expr)) CBR_Assert(ctx, (char *)#expr, (char *)__FILE__, __LINE__); } while (0)
#endif /* __DEBUG_ASSERT__ */



/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

//#define __MAX_RECORD_SUPPORT__
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#define PAGE_SIZE                (ctx->pageSize)
#define PAGE_PER_BLOCK           (ctx->pagePerBlock)

#define LENGTH_IN_PAGE(n)        (((n)+PAGE_SIZE-1)/PAGE_SIZE)

#if defined(__MAX_RECORD_SUPPORT__) || defined(__DOWNLOAD_AGENT__)
#define MAX_RECORD_IN_BLOCK_SUPPORT      64
#else
#define MAX_RECORD_IN_BLOCK_SUPPORT      16
#endif

#define MAX_CB_DEFAULT_SEARCH_BLOCK      32

#define MAX_NORMAL_CB_SUPPORTED  32
#define MAX_FAST_CB_SUPPORTED    2
#define MAX_SPARE_BLOCK_COUNT    20

#ifndef __DEBUG_CBR__
#define MAX_SN                   0xffffffff
#else
#define MAX_SN                   15
#endif

#define PAYLOAD_PAGES            (PAGE_PER_BLOCK-2)
#define FIRST_PAYLOAD_PAGE       (1)
#define LAST_PAYLOAD_PAGE        (PAGE_PER_BLOCK-2)

#define INVALID_GROUP_ID         0xffffffff
#define INVALID_BLOCK_ID         0xffffffff

#define UNINIT_MARK              0x00000000
#define BAD_BLOCK_MARK           0xfffffffe
#define INVALID_BLOCK_IDX        0xffffffff
#define INVALID_PAGE_IDX         0xffff

#define BLOCK_ATTR_END           0x0000001

#define CBR_VER                  (0x0001)
#define CBR_DATE_STR             "2011/09/15"
#define CBR_HEADER_IDENTIFIER    "CBR_IDENTIFIER"

#define SPARE_BLOCK_START        (ctx->params.startBlock + ctx->params.normalCBRBlock*2 + ctx->params.fastCBRBlock)
#define TOTAL_CBR_BLOCK          (ctx->params.normalCBRBlock*2 + ctx->params.fastCBRBlock + ctx->params.spareBlock)

#define MIN(a,b) ((a)<(b)?(a):(b))

#define ROOT_RECORD_ID           0xffff
 

/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

enum
{
   ADD_RECORD,
   REPLACE_RECORD,
   DELETE_RECORD,
   DELETE_RECORD_BY_MASK
};

typedef enum
{
   ST_UNINITIALIZED,
   ST_INITIALIZED,
   ST_CLEANED_UP
} CBR_STATUS;

typedef struct
{
   kal_uint32        op;          //Operation code
   
   kal_uint32        recordIdx;   //For Write/Delete, Add=0, DeleteByMask = 0. Location of the target record in the block
   const kal_uint8   *pData;      //For Write and Add
   kal_uint32        length;      //For Write and Add
   kal_uint16        type;        //For Write and Add
   CBR_DP_INFO       *pDpInfo;    //dpType: for add. pDpArg: for Add/Read/Write

   kal_uint32        recordMask;  //For DeleteByMask
   kal_uint32        recordValue; //For DeleteByMask
   
} FILL_MOVE_INFO_STRUCT;

typedef struct
{
   kal_uint16 recordId;
   kal_uint8  dpType;
   kal_uint8  dpParam;
   kal_uint16 pageStart;
   kal_uint16 attr;
   kal_uint32 recordLen;
   kal_uint32 reserved[1];
} CBR_RECORD_IDX;

typedef struct
{
   kal_char   header[16];
   
   kal_uint16 ver;
   kal_uint16 max_record_in_block;   
   kal_uint32 normalCBRBlockCount;
   kal_uint32 fastCBRBlockCount;
   kal_uint32 spareBlockCount;

   kal_uint32 groupId;
   kal_uint32 blockId;
   kal_uint32 sn;
   kal_uint32 prependLen;
   
   kal_uint32 attribute;
   kal_uint32 recordCount;
   kal_uint32 pagePerBlock;
   kal_uint32 blockAttr;

   kal_uint32 startBlock;
   kal_uint32 blockSize;
   
   kal_uint32 reserved[46];
   
   //-------------------- 256 byte boundary ------------------------------
   
   CBR_RECORD_IDX recordIndexInfo[MAX_RECORD_IN_BLOCK_SUPPORT]; 
   
} CBR_BLOCK_HEADER;

typedef struct
{
   kal_uint32 blockIdx;
} BAD_BLOCK_REPLACEMENT_TBL;

typedef struct
{
   kal_uint32 srcBlockId;     //Block id in group
   kal_uint16 srcPageIndex;
} CB_SRC_BLOCK;

typedef struct
{
   const kal_uint8* srcBuffer;
   kal_uint32       srcBufLen;
   kal_uint32       readOffset;
} CB_SRC_MEM;

typedef struct
{
   union {
       CB_SRC_BLOCK block;         //If the src is aonther page
       CB_SRC_MEM   mem;           //If the src is from a memory buffer
   } source;
   
   //left length of the record in byte
   kal_uint32 recordLen;
   
   kal_uint16 attr;

   //type of record
   kal_uint16 type;

   //DP releated info
   CBR_DP_INFO dpInfo;
   kal_uint8 dpParam;
   
   //Is this record is fully written? if it's non-zero means: 1. it's just written for n pages, 2. Skip write the index in header page in the next block
   kal_uint8 partialWritten;

   kal_uint8 srcIsMem;
   
} CB_MOVEMENT_INFO;

typedef struct {
   kal_uint32 sn[2][MAX_NORMAL_CB_SUPPORTED];
   kal_uint32 valid[2];
   kal_uint32 incomplete[2];
   kal_uint32 validBlockMask[2];
   kal_uint32 badBlockMask[2];
   kal_uint32 endBlockMask[2];

   kal_uint32 badBlocks;
} CBR_Init_BlockInfo;

typedef struct
{
   kal_uint32 index;
   kal_uint32 blockIdx;
   kal_uint32 pageIdx;
   kal_uint32 recordLen;
   kal_uint32 actualLen;
   kal_uint32 dpType;
} RECORD_LOCATION_STRUCT;

typedef struct
{
   kal_uint32 ver;
   kal_uint32 cbr_context;
   kal_uint32 time_stamp;   
   kal_uint32 creater;
   kal_char   identifier[16];
   kal_char   cbrDateStr[16];
} ROOT_RECORD_STRUCT;

#ifdef __CBR_TRANS_LOG__    
typedef struct
{
   kal_uint32 data;
   kal_uint32 len;
   kal_int32 status;
   kal_uint16 checksum;
   kal_uint16 reserved;
} CBR_TRANS_LOG;
#define TRANS_LOG_MAX_COUNT 1024
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct
{
    E_CBRRegionIndex          cbr_context_index;
    
    //CBR current status
    CBR_STATUS                cbr_status;

    //FTL mapping table
    FTL_FuncTbl              *g_ftlFuncTbl;    

    //Page buffer
    kal_uint32               *pGlobalBuffer;
    kal_uint32                pGlobalBufferLen;

    //CBR parameters
    CBR_PARAM_INFO            params;

    //Flash info
    kal_uint32                pageSize;
    kal_uint32                pagePerBlock;

    //Internal structures
    BAD_BLOCK_REPLACEMENT_TBL spareTbl[MAX_SPARE_BLOCK_COUNT];
    kal_uint32                validGroup;
    kal_uint32                currentSN;
    
    CB_MOVEMENT_INFO          cb_move_info[MAX_RECORD_IN_BLOCK_SUPPORT*2];
    kal_uint32                cb_move_info_count;
    
    kal_uint32                dirty_block_map;
    kal_uint32                endBlock;

    FTL_STATUS_CODE           flashErrorCode;

#ifdef __CBR_TRANS_LOG__    
    kal_uint32                trans_log_num;
    CBR_TRANS_LOG             trans_log[TRANS_LOG_MAX_COUNT];
#endif

} CBR_CONTEXT, *CTX;

static CBR_CONTEXT g_Contexts[] = {
#if defined(__SV5_ENABLED__) || defined(__SV5X_ENABLED__) 
                                                { E_CBR_IDX_CBR },
#endif
#if defined(__SECURE_DATA_STORAGE__)
                                                { E_CBR_IDX_SRW },
#endif
};

static const kal_uint32 CBR_TAIL_PATTERN[] = {0xf83f03e0, 0xf83f03e0, 0x07ff001f, 0x07ff001f, 
                                              0x4c494154, 0x00000000, 0x00000000, 0x00000000,
                                              0x00000000, 0x00000000, 0x00000000, 0x00000000, 
                                              0x0000ffff, 0x0000ffff, 0xffc0fc00, 0xffc0fc00 };


/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////

static kal_uint32 ReplaceBadBlock(CTX ctx, kal_uint32 badBlock);
static FTL_STATUS_CODE CopyBlock(CTX ctx, kal_uint32 srcBlock, kal_uint32 dstBlock, kal_uint32 pageCount, kal_uint32 updateDstGroup);
static kal_uint32 GetActiveGroup(CTX ctx);
static kal_int32 GetControlBlockIdx(CTX ctx, kal_int32 group, kal_uint32 id);
static kal_int32 TranslateGroupBlockId(CTX ctx, kal_int32 group, kal_uint32 id);
static kal_int32 ReadCBHeader(CTX ctx, kal_uint32 blockIdx);
static kal_int32 ReadCBTail(CTX ctx, kal_uint32 blockIdx);
static void FillCBRBlockHeader(CTX ctx, CBR_BLOCK_HEADER *pBlockHeader);
static void DoPowerLossRecovery(CTX ctx, kal_uint32 group);
static kal_bool IsSpareBlock(CTX ctx, kal_uint32 phyBlock);
static CTX GetContextFromIdx(E_CBRRegionIndex cbrIdx);
static kal_bool IsEndBlock(CTX ctx, kal_uint32 block);
static kal_bool IsBlockWithPossibleHeader(CTX ctx, kal_uint32 block);
static kal_bool IsForcedEndBlock(void);
static kal_uint32 GetAvailablePage(CTX ctx, CBR_BLOCK_HEADER *pBlockHeader);
static kal_bool IsSpareTableReady(CTX ctx);
static void SearchReplacement(CTX ctx, CBR_Init_BlockInfo *pInfo);


#ifdef __MTK_INTERNAL__

/*************************************************************************
 * Debugging assertion
 *************************************************************************/
#ifdef __DEBUG_ASSERT__
CTX ctx = NULL; //Dummy ctx for those function dons't have ctx

static void CBR_DumpCtxAndInfo(CTX ctx)
{
   #define P(X) PRINT(#X "=%d\n", ctx->X);   

   kal_int32 i;
   
   if(ctx)
   {
      P(cbr_context_index);
      P(cbr_status);
      P(g_ftlFuncTbl);    
      P(params);
      P(params.startBlock);
      P(params.totalBlock);
      P(params.normalCBRBlock);
      P(params.fastCBRBlock);
      P(params.spareBlock);
      P(params.max_record_in_block);
      P(params.roMode);
      P(pageSize);
      P(pagePerBlock);
      for(i=0; i<MAX_SPARE_BLOCK_COUNT; i++)
      {
         PRINT("i=%d\n", i);
         P(spareTbl[i].blockIdx);
      }
      P(validGroup);
      P(currentSN);
      for(i=0; i<MAX_RECORD_IN_BLOCK_SUPPORT*2; i++)
      {
         PRINT("i=%d\n", i);
         P(cb_move_info[i].source);
         P(cb_move_info[i].recordLen);
         P(cb_move_info[i].attr);
         P(cb_move_info[i].type);
         P(cb_move_info[i].dpInfo);
         P(cb_move_info[i].dpParam);
         P(cb_move_info[i].partialWritten);
         P(cb_move_info[i].srcIsMem);
      }
      P(cb_move_info_count);
      P(dirty_block_map);
      P(endBlock);
      P(flashErrorCode);

      PRINT("CBR_Region scan:\n");

      for(i=0; i<TOTAL_CBR_BLOCK; i++)
      {
         PRINT("block %d: ", ctx->params.startBlock+i);
         if(ctx->g_ftlFuncTbl->FTL_CheckGoodBlock(ctx->params.startBlock+i, NULL) == FTL_SUCCESS)
         {
            PRINT("good\n");
         }
         else
         {
            PRINT("bad\n");
         }
      }
   }
   else
   {
      PRINT("No CTX here\n");
   }
}

static void CBR_Assert(CTX ctx, char* expr, char* file, kal_uint32 line)
{

   PRINT("CBR Assert \"%s\" @ %s:%d\n", expr, file, line);

   CBR_DumpCtxAndInfo(ctx);

   PRINT("Assert end\n");

   while(1);


}

#endif

#endif
/*************************************************************************
 * FTL wrapper for better debug visibility
 *************************************************************************/
static FTL_STATUS_CODE FTL_CheckGoodBlock(CTX ctx, kal_uint32 block, FTL_OptParam *opt_param)
{
   return ctx->g_ftlFuncTbl->FTL_CheckGoodBlock(block, opt_param);
}

static FTL_STATUS_CODE FTL_EraseBlock(CTX ctx, kal_uint32 block, FTL_OptParam *opt_param)
{
   return ctx->g_ftlFuncTbl->FTL_EraseBlock(block, opt_param);
}

static FTL_STATUS_CODE FTL_MarkBadBlock(CTX ctx, kal_uint32 block, FTL_OptParam *opt_param)
{
   return ctx->g_ftlFuncTbl->FTL_MarkBadBlock(block, opt_param);
}

static FTL_STATUS_CODE FTL_ReadPage(CTX ctx, kal_uint32 block, kal_uint32 page, kal_uint32 *pBuf, FTL_OptParam *opt_param)
{
   return ctx->g_ftlFuncTbl->FTL_ReadPage(block, page, pBuf, opt_param);
}

static FTL_STATUS_CODE FTL_WritePage(CTX ctx, kal_uint32 block, kal_uint32 page, kal_uint32 *pBuf, FTL_OptParam *opt_param)
{
   return ctx->g_ftlFuncTbl->FTL_WritePage(block, page, pBuf, opt_param);
}

static kal_uint32 FTL_GetPageSize(CTX ctx)
{
   return ctx->g_ftlFuncTbl->FTL_GetPageSize();
}
static kal_uint32 FTL_GetBlockSize(CTX ctx, kal_uint32 block, FTL_OptParam *opt_param)
{
   return ctx->g_ftlFuncTbl->FTL_GetBlockSize(block, opt_param);
}

static kal_uint32 FTL_AddrToBlockPage(CTX ctx, kal_uint32 addr, kal_uint32 *pBlock, kal_uint32 *pPage, FTL_OptParam *opt_param)
{
   return ctx->g_ftlFuncTbl->FTL_AddrToBlockPage(addr, pBlock, pPage, opt_param);
}


#ifdef __MTK_INTERNAL__
/*************************************************************************
 * Debugging function
 *************************************************************************/

#ifdef __CBR_TRANS_LOG__    

static kal_uint16 CBR_ChecksumFunc(const kal_uint8 *pFn, kal_uint32 len)
{
   kal_uint16 sum1 = 0;
   kal_uint16 sum2 = 0;
   
   while(len--)
   {
      sum1 += *pFn++;
      if (sum1 >= 0xff)
      {
         sum1 -= 0xff;
      }
      sum2 += sum1;
      if(sum2 >= 0xff)
      {
         sum2 -= 0xff;
      }
   }
   return ((sum2 << 8) | sum1);
}


void CBR_LOG(CTX ctx, kal_uint32 action, kal_uint32 id, const kal_uint8* pData, kal_uint32 length, kal_int32 status)
{
   CBR_TRANS_LOG *p = &ctx->trans_log[ctx->trans_log_num];

   if(ctx->trans_log_num >= TRANS_LOG_MAX_COUNT)
   {
      return;
   }

   p->data = ((action<<24) | (id&0x00ffffff));
   p->len  = length;
   p->status = status;
   if(length && pData)
   {
      p->checksum = CBR_ChecksumFunc(pData, length);
   }
   else
   {
      p->checksum = 0;
   }
      
   ctx->trans_log_num++;
   
}

#endif

#ifdef WIN32   
static kal_bool IsEmptyPage(CTX ctx, kal_uint32 *p)
{
   kal_uint32 i;
   for(i=0; i<PAGE_SIZE/4; i++)
   {
      if(p[i] != 0xffffffff)
         return KAL_FALSE;
   }
   return KAL_TRUE;
}
#endif

kal_int32 DumpRecords(kal_uint32 cbrIdx)
{
#ifdef WIN32   
   CTX ctx = GetContextFromIdx(cbrIdx);

   #define MAX_PAGE_SIZE 2048   
   static kal_uint32 buf[2][MAX_PAGE_SIZE];
   
   kal_uint32 i, j, group;
   kal_uint32 n=0;
   kal_uint32 totalEmptyPage = 0;
   
   CBR_BLOCK_HEADER *pBlockHeader;

   pBlockHeader = (CBR_BLOCK_HEADER*)ctx->pGlobalBuffer;

   group = GetActiveGroup(ctx);
      
   for(i=0; i<ctx->params.normalCBRBlock; i++)
   {
      kal_uint32 block;
      
      {
         block = GetControlBlockIdx(ctx, group, i);

         if(i == ctx->endBlock)
         {
            ASSERT( (ReadCBHeader(ctx, block) == CBR_SUCCESS && (pBlockHeader->blockAttr & BLOCK_ATTR_END) && ReadCBTail(ctx, block) == CBR_SUCCESS) || 
                    (ReadCBHeader(ctx, block) != CBR_SUCCESS || ReadCBTail(ctx, block) != CBR_SUCCESS) );
            break;
         }
         
         if(ReadCBHeader(ctx, block) == CBR_SUCCESS)
         {
            if(!(pBlockHeader->blockAttr & BLOCK_ATTR_END))
            {
               //Check if all page ares used unless all record slots are occupied
               if(pBlockHeader->recordCount < ctx->params.max_record_in_block)
               {
                  kal_uint32 emptyPageCount = GetAvailablePage(ctx, pBlockHeader);

                  if(emptyPageCount > 0)
                  {
                     //Only the last block has unused page
                     ASSERT(totalEmptyPage == 0);
                     totalEmptyPage += emptyPageCount;
                  }
               }
               
               for(j=0; j<pBlockHeader->recordCount; j++)
               {
                  PRINT("Record %d, len=%d\n", pBlockHeader->recordIndexInfo[j].recordId, pBlockHeader->recordIndexInfo[j].recordLen);
               }
               PRINT("\n");
            }

            if(ReadCBTail(ctx, block) != CBR_SUCCESS)
            {
               PRINT("123");
            }
            ASSERT(ReadCBTail(ctx, block) == CBR_SUCCESS);
         }

      }
   }

   PRINT("\r\n");
#endif
   return 0;

}


kal_int32 DumpBlocks(kal_uint32 cbrIdx)
{
#ifdef WIN32   
   CTX ctx = GetContextFromIdx(cbrIdx);

   #define MAX_PAGE_SIZE 2048   
   static kal_uint32 buf[2][MAX_PAGE_SIZE];
   
   kal_uint32 i, group;
   kal_uint32 n=0;
   CBR_BLOCK_HEADER *pBlockHeader[2] = { (CBR_BLOCK_HEADER*)buf[0] , (CBR_BLOCK_HEADER*)buf[1] };
   CBR_BLOCK_HEADER *pActive = (CBR_BLOCK_HEADER*)buf[GetActiveGroup(ctx)];
   kal_bool noFurtherData = KAL_FALSE;

   kal_uint32 nextPrepend = 0;

   PRINT("Current SN=%d\n\r", ctx->currentSN);
   
   if(GetActiveGroup(ctx) == 0)
      PRINT("         v\r\n");
   else
      PRINT("                                V\r\n");


   for(i=0; i<ctx->params.normalCBRBlock; i++)
   {
      enum
      {
         HEADER_NONE  = 'N',
         HEADER_OK    = '1',
         HEADER_EMPTY = '-',
         HEADER_EMPTY_MARKER = 'E',
         HEADER_UNKNOWN_DATA = '?',
         HEADER_BAD_BLOCK = 'B'
      };
      
      kal_int32 headerStatus[2] = { HEADER_NONE, HEADER_NONE };
      
      kal_bool tailOK[2] = { KAL_FALSE, KAL_FALSE };   
      kal_bool badBlock[2] = {KAL_FALSE, KAL_FALSE};
      kal_bool replaced[2] = {KAL_FALSE, KAL_FALSE};
      
      kal_uint32 block;


      for(group=0; group<2; group++)
      {
         memset(buf[group], 0x00, PAGE_SIZE);
         memset(pBlockHeader[group], -1, sizeof(CBR_BLOCK_HEADER));
         
         block = GetControlBlockIdx(ctx, group, i);
         
         if(FTL_CheckGoodBlock(ctx, block, NULL) != FTL_SUCCESS)
            badBlock[group] = KAL_TRUE;
         
         if(IsSpareBlock(ctx, block))
            replaced[group] = KAL_TRUE;

         if(badBlock[group])
         {
            headerStatus[group] = HEADER_BAD_BLOCK;
         }
         else
         {
            if(ReadCBHeader(ctx, block) == CBR_SUCCESS)
            {
               memcpy(pBlockHeader[group], ctx->pGlobalBuffer, PAGE_SIZE);

               ASSERT(pBlockHeader[group]->ver == CBR_VER);      
               ASSERT(pBlockHeader[group]->normalCBRBlockCount == ctx->params.normalCBRBlock);
               ASSERT(pBlockHeader[group]->fastCBRBlockCount == ctx->params.fastCBRBlock);
               ASSERT(pBlockHeader[group]->groupId == group);
               ASSERT(pBlockHeader[group]->blockId == i);
               ASSERT(pBlockHeader[group]->prependLen <= PAGE_SIZE*PAYLOAD_PAGES);

               if(pBlockHeader[group]->blockAttr & BLOCK_ATTR_END)
               {
                  headerStatus[group] = HEADER_EMPTY_MARKER;
               }
               else
               {
                  headerStatus[group] = HEADER_OK;
               }
            }
            else if(IsEmptyPage(ctx, ctx->pGlobalBuffer))
            {
               headerStatus[group] = HEADER_EMPTY;
            }
            else
            {
               headerStatus[group] = HEADER_UNKNOWN_DATA;
            }
            
            if(ReadCBTail(ctx, block) == CBR_SUCCESS)
            {
               tailOK[group] = KAL_TRUE;
            }
         }
         
      }

      PRINT("Header st  = %c%c  \t\t Header st  = %c%c  \r\n", headerStatus[0],  replaced[0]?'*':' ', headerStatus[1], replaced[1]?'*':' ');
//      PRINT("Replaced   = %d\t\t Replaced   = %d\r\n", replaced[0], replaced[1]);
      PRINT("SN=          %d  \t\t SN         = %d\r\n", pBlockHeader[0]->sn, pBlockHeader[1]->sn);
      PRINT("prependLen = %d  \t\t prependLen = %d\r\n", pBlockHeader[0]->prependLen, pBlockHeader[1]->prependLen);      
      PRINT("recordCount= %d  \t\t recordCount= %d\r\n", pBlockHeader[0]->recordCount, pBlockHeader[1]->recordCount);            
      PRINT("complete   = %d  \t\t complete   = %d\r\n", tailOK[0], tailOK[1]);

      PRINT("\r\n");

      if(!noFurtherData && headerStatus[GetActiveGroup(ctx)] == HEADER_OK && tailOK[GetActiveGroup(ctx)])
      {
         if(nextPrepend > PAYLOAD_PAGES*PAGE_SIZE)
         {
            ASSERT(pActive->prependLen == PAYLOAD_PAGES*PAGE_SIZE);
            ASSERT(pActive->recordCount == 0);
            nextPrepend -= PAYLOAD_PAGES*PAGE_SIZE;
         }
         else
         {
            ASSERT(pActive->prependLen == nextPrepend);
            nextPrepend = 0;
         }
         
         for(n=0; n<pActive->recordCount; n++)
         {
            ASSERT(pActive->recordIndexInfo[n].pageStart >= 1 && pActive->recordIndexInfo[n].pageStart <= PAGE_PER_BLOCK-1);

            if(n == 0)
            {
               if(pActive->prependLen)
               {
                  ASSERT(LENGTH_IN_PAGE(pActive->prependLen)+1 == pActive->recordIndexInfo[0].pageStart);
               }
            }
            else
            {
               ASSERT(pActive->recordIndexInfo[n].pageStart == pActive->recordIndexInfo[n-1].pageStart + LENGTH_IN_PAGE(pActive->recordIndexInfo[n-1].recordLen));
            }

            if(n == pActive->recordCount-1)
            {
               kal_uint32 leftPage = PAGE_PER_BLOCK - pActive->recordIndexInfo[n].pageStart - 1;

               if(LENGTH_IN_PAGE(pActive->recordIndexInfo[n].recordLen) > leftPage)
               {
                  nextPrepend = pActive->recordIndexInfo[n].recordLen - leftPage*PAGE_SIZE;
               }
            }
         }
      }
      else
      {
         noFurtherData = KAL_TRUE;
      }
      
   }

   PRINT("End: %d\n", ctx->endBlock);

   PRINT("Dirty: ");
   for(i=0; i<ctx->params.normalCBRBlock; i++)
   {
      if(ctx->dirty_block_map & (1<<i))
      {
         PRINT("%d, ", i);
      }
   }
   
   PRINT("\r\n");
   
   PRINT("Bad:\r\n");
   for(i=0; i<ctx->params.spareBlock; i++)
   {
      switch(ctx->spareTbl[i].blockIdx)
      {
         case UNINIT_MARK:
            PRINT("%d uninit\r\n", SPARE_BLOCK_START+i);
            break;
         case INVALID_BLOCK_IDX:
            PRINT("%d available\r\n", SPARE_BLOCK_START+i);
            break;
         case BAD_BLOCK_MARK:
            PRINT("%d bad\r\n", SPARE_BLOCK_START+i);
            break;
         default:
            PRINT("%d replace %d\r\n", SPARE_BLOCK_START+i, ctx->spareTbl[i].blockIdx);
            ASSERT(ctx->spareTbl[i].blockIdx >= ctx->params.startBlock && ctx->spareTbl[i].blockIdx < SPARE_BLOCK_START+ctx->params.spareBlock);
            ASSERT(FTL_CheckGoodBlock(ctx, ctx->spareTbl[i].blockIdx, NULL) != FTL_SUCCESS);
            break;
      }
   }

   PRINT("\r\n");
#endif
   return 0;

}

kal_uint32 GetUsedPagePerBlock(kal_uint32 cbrIdx)
{
   CTX ctx = GetContextFromIdx(cbrIdx);
   return ctx->pagePerBlock;
}

#endif

/*************************************************************************
 * Flash wrapper function
 *************************************************************************/

static FTL_STATUS_CODE My_MarkBad(CTX ctx, kal_uint32 block)
{
   if(FTL_CheckGoodBlock(ctx, block, NULL) != FTL_ERROR_BAD_BLOCK)
   {
      //Erase to prevent confusing data
      FTL_EraseBlock(ctx, block, NULL);

      //Mark it bad anyway
      return FTL_MarkBadBlock(ctx, block, NULL);
   }

   return FTL_SUCCESS;
}

static FTL_STATUS_CODE My_Erase(CTX ctx, kal_uint32 block, kal_bool markBad)
{
   FTL_STATUS_CODE status;

   status = FTL_CheckGoodBlock(ctx, block, NULL);

   if(status == FTL_SUCCESS)
   {
      status = FTL_EraseBlock(ctx, block, NULL);

      if(status == FTL_ERROR_BAD_BLOCK && markBad)
      {
         FTL_MarkBadBlock(ctx, block, NULL);
      }
   }

   return status;
}


/*************************************************************************
 * Translation functions
 *************************************************************************/
static kal_int32 TranslateGroupBlockId(CTX ctx, kal_int32 group, kal_uint32 id)
{
   return ctx->params.startBlock + ctx->params.normalCBRBlock * group + id;
}

static kal_int32 GetControlBlockIdx(CTX ctx, kal_int32 group, kal_uint32 id)
{
   kal_uint32 block = TranslateGroupBlockId(ctx, group, id);
   kal_uint32 i;

   if(IsSpareTableReady(ctx))
   {
      //Search local table 
      for(i=0; i<ctx->params.spareBlock; i++)
      {
         if(ctx->spareTbl[i].blockIdx == block)
         {
            return (SPARE_BLOCK_START + i);
         }
      }
   }

   return block;
}

/*************************************************************************
 * Flash manipulation functions (group based, high level)
 *************************************************************************/

static FTL_STATUS_CODE EraseBlockInGroup(CTX ctx, kal_uint32 group, kal_uint32 id, kal_bool badBlockReplacement)
{
   FTL_STATUS_CODE status;
   kal_uint32 block = GetControlBlockIdx(ctx, group, id);

   while(1)
   {
      status = My_Erase(ctx, block, KAL_TRUE);
      
      if(status == FTL_ERROR_BAD_BLOCK && badBlockReplacement == KAL_TRUE)
      {
         block = ReplaceBadBlock(ctx, block);
         if(block == INVALID_BLOCK_IDX)
         {
            break;
         }
         continue;
      }

      break;
   }

   return status;
}

static FTL_STATUS_CODE WritePageWithReplacement(CTX ctx, kal_uint32 group, kal_uint32 id, kal_uint32 page, kal_uint32 *pBuf, kal_bool *pShouldRetry)
{
   FTL_STATUS_CODE status;
   kal_uint32 block = GetControlBlockIdx(ctx, group, id);
   kal_uint32 origBlock = block;   
   
   kal_bool replacement = KAL_FALSE;

   *pShouldRetry = KAL_FALSE;

   status = FTL_WritePage(ctx, block, page, ctx->pGlobalBuffer, NULL);

   while(status == FTL_ERROR_BAD_BLOCK)
   {
      block = ReplaceBadBlock(ctx, block);
      replacement = KAL_TRUE;

      if(block == INVALID_BLOCK_IDX)
      {
         //No spare block availabe
         break;
      }

      status = My_Erase(ctx, block, KAL_TRUE);
      
      if(status == FTL_SUCCESS)
      {
         status = CopyBlock(ctx, origBlock, block, page, INVALID_GROUP_ID);
      }
      
      if(status == FTL_ERROR_BAD_BLOCK)
      {
         My_MarkBad(ctx, block);
      }
   }

   if(status == FTL_SUCCESS && replacement)
   {
      My_MarkBad(ctx, origBlock);
      *pShouldRetry = KAL_TRUE;
   }

   return status;
}

static FTL_STATUS_CODE CompleteBlockInGroup(CTX ctx, kal_uint32 group, kal_uint32 id)
{
   FTL_STATUS_CODE status;
   kal_bool toRetry;

   do
   {
      memset(ctx->pGlobalBuffer, 0x00, PAGE_SIZE);
      memcpy(ctx->pGlobalBuffer, CBR_TAIL_PATTERN, sizeof(CBR_TAIL_PATTERN));

      status = WritePageWithReplacement(ctx, group, id, PAGE_PER_BLOCK-1, ctx->pGlobalBuffer, &toRetry);
      
   } while(toRetry);

   return status;
}

static FTL_STATUS_CODE CompleteBlocksInGroup(CTX ctx, kal_uint32 group, kal_uint32 blockMask)
{
   kal_int32 i;
   FTL_STATUS_CODE status = FTL_SUCCESS;

   for(i=ctx->params.normalCBRBlock-1; status==FTL_SUCCESS && i>=0; i--)
   {
      if(blockMask&(1<<i))
      {
         PRINT("Complete %d\r\n", i);
         status = CompleteBlockInGroup(ctx, group, i);
      }
   }
   return status;
}

static kal_bool IsBlockReplaced(CTX ctx, kal_uint32 group, kal_uint32 id)
{
   kal_uint32 block;
   
   block = GetControlBlockIdx(ctx, group, id);

   return IsSpareBlock(ctx, block);
}

static FTL_STATUS_CODE MakeEndMark(CTX ctx, kal_uint32 group, kal_uint32 id)
{
   FTL_STATUS_CODE status = FTL_SUCCESS;
   kal_uint32 block;
   kal_bool makeItEnd = KAL_FALSE;

   PRINT("Make a end mark on %d\r\n", id);

   block = GetControlBlockIdx(ctx, group, id);

   if(FTL_CheckGoodBlock(ctx, block, NULL) == FTL_SUCCESS)
   {
      //Readable
      if(IsSpareBlock(ctx, block) || IsForcedEndBlock())
      {
         if(IsEndBlock(ctx, block) == KAL_FALSE)
         {
            makeItEnd = KAL_TRUE;
         }
      }
      else
      {
         if(IsBlockWithPossibleHeader(ctx, block) == KAL_TRUE)
         {
            makeItEnd = KAL_TRUE;
         }
      }
   }
   else
   {
      //Bad block and not replaced
      makeItEnd = KAL_TRUE;
   }

   if(makeItEnd)
   {
      status = EraseBlockInGroup(ctx, group, id, KAL_TRUE);
      
      if(status == FTL_SUCCESS && (IsBlockReplaced(ctx, group, id) || IsForcedEndBlock()))
      {
         CBR_BLOCK_HEADER *pBlockHeader = (CBR_BLOCK_HEADER*)(ctx->pGlobalBuffer);         
         kal_bool toRetry;

         do
         {
            kal_uint32 block = GetControlBlockIdx(ctx, group, id);
            FillCBRBlockHeader(ctx, pBlockHeader);
            pBlockHeader->groupId = group;
            pBlockHeader->blockId = id;
            pBlockHeader->blockAttr |= BLOCK_ATTR_END;
            pBlockHeader->blockSize = FTL_GetBlockSize(ctx, block, NULL);

            status = WritePageWithReplacement(ctx, group, id, 0, (kal_uint32*)pBlockHeader, &toRetry);
            
         } while(toRetry);

         if(status == FTL_SUCCESS)
         {
            status = CompleteBlockInGroup(ctx, group, id);
         }
      }
   }


   return status;
}
         

/*************************************************************************
 * Utilities
 *************************************************************************/


static kal_uint32 GetActiveGroup(CTX ctx)
{
   return ctx->validGroup;
}

static kal_uint32 GetInactiveGroup(CTX ctx)
{
   return !ctx->validGroup;
}

static void SwitchActiveGroup(CTX ctx)
{
   ctx->validGroup = !ctx->validGroup;

}

static kal_bool IsForcedEndBlock(void)
{
#ifdef __DEBUG_CBR__   
   extern kal_bool forcedEndBlock;
   return forcedEndBlock;
#else

#ifndef __NAND_WRITER_SIMULATE__
   return KAL_FALSE;
#else
   return KAL_TRUE;
#endif

#endif
}

static kal_bool CompareWithBitError(const void *p1, const void *p2, kal_uint32 len, kal_uint32 maxBitError)
{
   kal_uint32 i;
   kal_uint32 bit_error = 0;

   for(i=0; i<len; i++)
   {
      kal_uint8 r = ((kal_uint8*)p1)[i] ^ ((kal_uint8*)p2)[i];
      while (r)
      {
         bit_error++;
         if(bit_error >= maxBitError)
         {
            return KAL_FALSE;
         }
         r &= r-1;
      }
   }

   return KAL_TRUE;            
}

/*************************************************************************
 * Control block related routine (FTL block index based, low level)
 *************************************************************************/

/*************************************************************************
* FUNCTION
*  ReadCBHeader
*
* DESCRIPTION
*  This function read the header page and check its validity
*
* PARAMETERS
*  blockIdx: the block index
*
* RETURNS
*  TRUE:  this is a valid header page
*
* NOTES
*  None
*
*************************************************************************/
static kal_int32 ReadCBHeader(CTX ctx, kal_uint32 blockIdx)
{
   FTL_STATUS_CODE status;
   CBR_BLOCK_HEADER *pBlockHeader = (CBR_BLOCK_HEADER*)(ctx->pGlobalBuffer);   
   status = FTL_ReadPage(ctx, blockIdx, 0, ctx->pGlobalBuffer, NULL);

   if(status == FTL_SUCCESS)
   {
      if(memcmp(pBlockHeader->header, CBR_HEADER_IDENTIFIER, sizeof(CBR_HEADER_IDENTIFIER)) == 0)
      {
         //0825 New
         ctx->pagePerBlock = pBlockHeader->pagePerBlock;
         
         return CBR_SUCCESS;
      }
   }
   return CBR_NO_VALID_HEADER;
}

/*************************************************************************
* FUNCTION
*  ReadCBTail
*
* DESCRIPTION
*  This function read the tail page and check its validity
*
* PARAMETERS
*  blockIdx: the block index
*
* RETURNS
*  TRUE:  this is a valid tail page
*
* NOTES
*  This is must be called after ReadCBHeader, which update the position of the last available page
*  since it may differ between block and block
*
*************************************************************************/
static kal_int32 ReadCBTail(CTX ctx, kal_uint32 blockIdx)
{
   FTL_STATUS_CODE status;

   memset(ctx->pGlobalBuffer, 0x00, PAGE_SIZE);
   
   status = FTL_ReadPage(ctx, blockIdx, PAGE_PER_BLOCK-1, ctx->pGlobalBuffer, NULL);

   if(status == FTL_SUCCESS || status == FTL_ERROR_READ_FAILURE)
   {
      kal_uint32 i;
      kal_uint32 idxes[] = {0x0, 0x30/4};
      kal_uint32 bit_error = 0;

      for (i=0; i<sizeof(idxes)/sizeof(*idxes); i++)
      {
         kal_uint32 base = idxes[i];            
         if(CompareWithBitError(&ctx->pGlobalBuffer[base], &CBR_TAIL_PATTERN[base], 16, 12) == KAL_FALSE)
         {
            return CBR_UNRECOGNIZED_TAIL;
         }
      }

      if(bit_error)
      {
         PRINT("Tail bit error=%d\n\r", bit_error);
      }
      
      return CBR_SUCCESS;
   }
   
   return CBR_NO_VALID_TAIL;
}

/*************************************************************************
* FUNCTION
*  
*
* DESCRIPTION
*  
*
* PARAMETERS
*  blockIdx: the block index
*
* RETURNS
*  TRUE:
*
* NOTES
*  
*  
*
*************************************************************************/

static kal_bool IsBlockWithPossibleHeader(CTX ctx, kal_uint32 block)
{
   CBR_BLOCK_HEADER *pBlockHeader = (CBR_BLOCK_HEADER*)(ctx->pGlobalBuffer);   
   
   memset(pBlockHeader, 0x00, sizeof(CBR_BLOCK_HEADER));

   FTL_ReadPage(ctx, block, 0, (kal_uint32*)pBlockHeader, NULL);

   //For the case that only write the first page which is with bit flipping
   if(CompareWithBitError(&pBlockHeader->header, CBR_HEADER_IDENTIFIER, sizeof(CBR_HEADER_IDENTIFIER), 12) == KAL_TRUE)
   {
      return KAL_TRUE;
   }

   return KAL_FALSE;
}

/*************************************************************************
* FUNCTION
*  
*
* DESCRIPTION
*  
*
* PARAMETERS
*  blockIdx: the block index
*
* RETURNS
*  TRUE:
*
* NOTES
*  
*  
*
*************************************************************************/

static kal_bool IsEndBlock(CTX ctx, kal_uint32 block)
{
   CBR_BLOCK_HEADER *pBlockHeader = (CBR_BLOCK_HEADER*)(ctx->pGlobalBuffer);  
   
   if(ReadCBHeader(ctx, block) == CBR_SUCCESS)
   {
      if((pBlockHeader->blockAttr & BLOCK_ATTR_END) == 0)
      {
         return KAL_FALSE;
      }
      
      if(ReadCBTail(ctx, block) == CBR_SUCCESS)
      {
         return KAL_TRUE;
      }
   }

   return KAL_FALSE;
}

static kal_bool IsSpareBlock(CTX ctx, kal_uint32 phyBlock)
{
   if(phyBlock >= SPARE_BLOCK_START && phyBlock < SPARE_BLOCK_START+ctx->params.spareBlock)
   {
      return KAL_TRUE;
   }
   return KAL_FALSE;
}

static kal_bool IsSpareTableReady(CTX ctx)
{
   if(ctx->params.spareBlock==0 || ctx->spareTbl[0].blockIdx != UNINIT_MARK)
   {
      return KAL_TRUE;
   }

   return KAL_FALSE;
}

static void InitSpareTable(CTX ctx)
{
   //Sanity test
   ASSERT(ctx->spareTbl[0].blockIdx == UNINIT_MARK);
      
   //Initialize it as all INVALID_BLOCK_IDX (available)
   memset(&ctx->spareTbl, 0xff, sizeof(ctx->spareTbl));
}

/*************************************************************************
 * Control block related routine
 *************************************************************************/

//Search if some record in the specified CB, with the side effect of loading header page
static kal_int32 SearchRecordInCB(CTX ctx, CBR_BLOCK_HEADER *pBlockHeader, kal_uint16 type)
{
   kal_uint32 i;

   ASSERT(pBlockHeader->recordCount <= ctx->params.max_record_in_block);

   for(i=0 ;i<pBlockHeader->recordCount; i++)
   {
      if(pBlockHeader->recordIndexInfo[i].recordId == type)
      {
         return i;
      }
   }

   return -1;
}

static void FillCBRBlockHeader(CTX ctx, CBR_BLOCK_HEADER *pBlockHeader)
{
   memset(pBlockHeader->header, 0, sizeof(pBlockHeader->header));
   memcpy(pBlockHeader->header, CBR_HEADER_IDENTIFIER, sizeof(CBR_HEADER_IDENTIFIER));
   pBlockHeader->ver                 = CBR_VER;
   pBlockHeader->max_record_in_block = ctx->params.max_record_in_block;
   pBlockHeader->normalCBRBlockCount = ctx->params.normalCBRBlock;
   pBlockHeader->fastCBRBlockCount   = ctx->params.fastCBRBlock;
   pBlockHeader->spareBlockCount     = ctx->params.spareBlock;

   pBlockHeader->groupId             = INVALID_GROUP_ID;
   pBlockHeader->blockId             = INVALID_BLOCK_ID;
   pBlockHeader->sn                  = ctx->currentSN;
   pBlockHeader->prependLen          = 0;

   pBlockHeader->attribute           = 0;
   pBlockHeader->recordCount         = 0;   
   pBlockHeader->pagePerBlock        = PAGE_PER_BLOCK;
   pBlockHeader->blockAttr           = 0;
   
   pBlockHeader->startBlock          = ctx->params.startBlock;
   
   memset(pBlockHeader->reserved,0xAB, sizeof(pBlockHeader->reserved));
   
   memset(pBlockHeader->recordIndexInfo, 0x00, sizeof(pBlockHeader->recordIndexInfo));
}

static kal_uint32 GetAvailablePage(CTX ctx, CBR_BLOCK_HEADER *pBlockHeader)
{
   kal_uint32 pageEnd;
   kal_int32 freePage;
   
   if(pBlockHeader->recordCount == ctx->params.max_record_in_block)
   {
      return 0;
   }
   if(pBlockHeader->recordCount == 0)
   {
      return PAYLOAD_PAGES-LENGTH_IN_PAGE(pBlockHeader->prependLen);
   }
   
   pageEnd = pBlockHeader->recordIndexInfo[pBlockHeader->recordCount-1].pageStart + LENGTH_IN_PAGE(pBlockHeader->recordIndexInfo[pBlockHeader->recordCount-1].recordLen);

   freePage = PAYLOAD_PAGES-(pageEnd-1);

   return (freePage>0) ? freePage : 0;
}

/*************************************************************************
 * Bad block management
 *************************************************************************/
static kal_uint32 ReplaceBadBlock(CTX ctx, kal_uint32 badBlock)
{
   kal_uint32 i;
   kal_uint32 toReplace = badBlock;

   ASSERT(!ctx->params.roMode);
   ASSERT(badBlock >= ctx->params.startBlock && badBlock < ctx->params.startBlock+TOTAL_CBR_BLOCK);

   ASSERT(IsSpareTableReady(ctx) == KAL_TRUE);
   
   if(badBlock>=SPARE_BLOCK_START && badBlock<SPARE_BLOCK_START+ctx->params.spareBlock)
   {
      toReplace = ctx->spareTbl[badBlock-SPARE_BLOCK_START].blockIdx;
      ctx->spareTbl[badBlock-SPARE_BLOCK_START].blockIdx = BAD_BLOCK_MARK;
   }

   //Sanity test
   for(i=0; i<ctx->params.spareBlock; i++)
   {
      ASSERT(ctx->spareTbl[i].blockIdx != badBlock);
   }
   
   for(i=0; i<ctx->params.spareBlock; i++)
   {
      if(ctx->spareTbl[i].blockIdx == INVALID_BLOCK_IDX)
      {
         ctx->spareTbl[i].blockIdx = toReplace;
         PRINT("Replacement: %d->%d\r\n", SPARE_BLOCK_START+i, toReplace);
         return (SPARE_BLOCK_START+i);
      }
   }
   
   return INVALID_BLOCK_IDX;
}

/*************************************************************************
 * Block copying/writing facility
 *************************************************************************/
//Copy block from one to another for 2 given FTL block index
//Copy page0 to page n-1, and update the data in block header by the way
//Do not take care of bad block
static FTL_STATUS_CODE CopyBlock(CTX ctx, kal_uint32 srcBlock, kal_uint32 dstBlock, kal_uint32 pageCount, kal_uint32 updateDstGroup)
{
   FTL_STATUS_CODE status = FTL_SUCCESS; 
   kal_uint32 page;

   ASSERT(srcBlock!=INVALID_BLOCK_IDX && dstBlock!=INVALID_BLOCK_IDX);
   ASSERT(pageCount <= PAGE_PER_BLOCK);

   for(page=0; status==FTL_SUCCESS && page<pageCount; page++)
   {
      status = FTL_ReadPage(ctx, srcBlock, page, ctx->pGlobalBuffer, NULL);

      if(status == FTL_SUCCESS)
      {
         if(page == 0)
         {
            CBR_BLOCK_HEADER *pBlockHeader = (CBR_BLOCK_HEADER*)ctx->pGlobalBuffer;
            pBlockHeader->sn = ctx->currentSN;
            if(updateDstGroup != INVALID_GROUP_ID)
            {
               pBlockHeader->groupId = updateDstGroup;
            }
            pBlockHeader->blockSize = FTL_GetBlockSize(ctx, dstBlock, NULL);
         }

         status = FTL_WritePage(ctx, dstBlock, page, ctx->pGlobalBuffer, NULL);
      }
   }

   return status;
}


//Assume the target block has been erased
static FTL_STATUS_CODE CopyBlockToInactiveGroup(CTX ctx, kal_uint32 id)
{
   FTL_STATUS_CODE status = FTL_SUCCESS;

   kal_uint32 srcGroup = GetActiveGroup(ctx);
   kal_uint32 dstGroup = GetInactiveGroup(ctx);
   kal_uint32 srcBlock = GetControlBlockIdx(ctx, srcGroup, id);
   kal_uint32 dstBlock = GetControlBlockIdx(ctx, dstGroup, id);

   ASSERT(srcBlock != INVALID_BLOCK_IDX);

   do {
      status = CopyBlock(ctx, srcBlock, dstBlock, PAGE_PER_BLOCK-1, dstGroup);

      if(status == FTL_SUCCESS)
      {
         break;
      }

      while(status == FTL_ERROR_BAD_BLOCK)
      {
         My_MarkBad(ctx, dstBlock);
         dstBlock = ReplaceBadBlock(ctx, dstBlock);
         
         if(dstBlock == INVALID_BLOCK_IDX)
         {
            break;
         }
         status = My_Erase(ctx, dstBlock, KAL_FALSE);
      }
   } while(dstBlock != INVALID_BLOCK_IDX);

   return status;
}

#ifdef _DP_TEST_
#ifdef __MTK_INTERNAL__
static void DefaultDP_GetInitInfo(kal_uint32 actual_src_len, kal_uint32 *p_occupied_src_len)
{
    *p_occupied_src_len = ((actual_src_len + 15)>>4)<<4;
}


static kal_int32 DefaultDP_Init(kal_uint32 attr, const void *p_arg, kal_uint32 *p_block_size)
{
    *p_block_size = 16;
    return 0;
}

static void  DefaultDP_DeInit(kal_uint32 attr)
{
    
}

static kal_int32 DefaultDP_RdPostProcess(kal_uint8 *p_dst, kal_uint32 actual_dst_len, kal_uint32 dst_offset, const kal_uint8 *p_src, kal_uint32 len)
{
    kal_uint32 i;
    kal_uint32 copy_len = len;
    if(dst_offset + copy_len > actual_dst_len)
    {
        copy_len = actual_dst_len - dst_offset;
    }

    memcpy(p_dst + dst_offset, p_src, copy_len);

    for(i=0; i<copy_len; i++)
    {
        *(p_dst + dst_offset + i) -= 0x20;
    }

    return copy_len;
}

static kal_int32 DefaultDP_WrPreProcess(const kal_uint8 *p_src, kal_uint32 actual_src_len, kal_uint32 src_offset, kal_uint8 *p_dst, kal_uint32 len)
{
    kal_uint32 i;

    memcpy(p_dst, p_src+src_offset, len);

    for(i=0; i<len; i++)
    {
        *(p_dst + i) += 0x20;
    }

    return len;
}

#endif
#else
static void DefaultDP_GetInitInfo(kal_uint32 actual_src_len, kal_uint32 *p_occupied_src_len)
{
    *p_occupied_src_len = actual_src_len;
}


static kal_int32 DefaultDP_Init(kal_uint32 attr, const void *p_arg, kal_uint32 *p_block_size)
{
    *p_block_size = 1;
    return 0;
}

static void DefaultDP_DeInit(kal_uint32 attr)
{
    
}

static kal_int32 DefaultDP_RdPostProcess(kal_uint8 *p_dst, kal_uint32 actual_dst_len, kal_uint32 dst_offset, const kal_uint8 *p_src, kal_uint32 len)
{
    ASSERT(dst_offset + len <= actual_dst_len);
    memcpy(p_dst + dst_offset, p_src, len);
    return len;
}

static kal_int32 DefaultDP_WrPreProcess(const kal_uint8 *p_src, kal_uint32 actual_src_len, kal_uint32 src_offset, kal_uint8 *p_dst, kal_uint32 len)
{
    memcpy(p_dst, p_src+src_offset, len);
    return len;
}
#endif

static SDS_DP_Callback defaultDp = { DefaultDP_GetInitInfo, DefaultDP_Init, DefaultDP_DeInit, DefaultDP_RdPostProcess, DefaultDP_WrPreProcess };

static const SDS_DP_Callback *GetCallbackFromDPType(SDS_DP_TYPE dpType)
{
   const SDS_DP_Callback *pDpCallback = &defaultDp;
   
#if !defined(__UBL__) && !defined(__DOWNLOAD_AGENT__)
   if(dpType != SDS_DP_NONE)
   {
      ASSERT(dpType != SDS_DP_EXTERNAL);
      
      pDpCallback = SDS_DP_GetCallback(dpType);
   }
#endif

   return pDpCallback;
}


 //Sub routine to copy pages from memory to some page, skip the tail
static FTL_STATUS_CODE CopyPageFromMem(CTX ctx, CB_SRC_MEM src, CBR_DP_INFO *pDpInfo, kal_uint8 dpParam, kal_uint32 dstBlockIndex, kal_uint32 dstPage, kal_uint32 dataLen, kal_uint32 *pPageCount)
{
   FTL_STATUS_CODE status = FTL_SUCCESS;
   kal_uint32 occupiedLen = src.srcBufLen + dpParam;
   kal_uint32 readOffset = occupiedLen - dataLen;

   const SDS_DP_Callback *pDpCallback = NULL;
   kal_uint32 dpBlockSize = 0;
   
   ASSERT( src.srcBuffer && dstPage<PAGE_PER_BLOCK );
   ASSERT( *pPageCount == LENGTH_IN_PAGE(dataLen) );

   ASSERT(readOffset == src.readOffset);

   if(pDpInfo->dpType != SDS_DP_EXTERNAL)
   {
      pDpCallback = GetCallbackFromDPType(pDpInfo->dpType);
      if(!pDpCallback)
      {
         return FTL_ERROR_READ_FAILURE;
      }
   }
   else
   {
      pDpCallback = (SDS_DP_Callback*)src.srcBuffer;
   }

   for(; status==FTL_SUCCESS && *pPageCount; (*pPageCount)--, readOffset+=PAGE_SIZE, dstPage++)
   {
      if(dstPage >= PAGE_PER_BLOCK-1)
      {
         break;
      }

      if(pDpCallback && readOffset == 0)
      {
         pDpCallback->m_init(0, pDpInfo->pDpArg, &dpBlockSize);
         if(PAGE_SIZE % dpBlockSize)
         {
            return FTL_ERROR_READ_FAILURE;
         }
      }

      if(status == FTL_SUCCESS)
      {
         if(dataLen > PAGE_SIZE)
         {
            pDpCallback->m_wr_pre_process((const kal_uint8*)src.srcBuffer, src.srcBufLen, readOffset, (kal_uint8*)ctx->pGlobalBuffer, PAGE_SIZE);
         }
         else
         {
            memset(ctx->pGlobalBuffer, 0xFF, PAGE_SIZE);
            pDpCallback->m_wr_pre_process((const kal_uint8*)src.srcBuffer, src.srcBufLen, readOffset, (kal_uint8*)ctx->pGlobalBuffer, dataLen);            
            pDpCallback->m_deinit(0);
         }

         status = FTL_WritePage(ctx, dstBlockIndex, dstPage, ctx->pGlobalBuffer, NULL);
         
         dataLen -= PAGE_SIZE;
      }
   }

   return status;

}

//Sub routine to copy pages starting from (group, block, page) to (blockIndex, page), skip the tail
//srcBlockId is in-group ID, however dstBlock is physical
//When source cross the block boundary, it will continue with the next block, but if the target block is full, it just returns
static FTL_STATUS_CODE CopyPages(CTX ctx, kal_uint32 group, kal_uint32 srcBlockId, kal_uint32 srcPage, kal_uint32 dstBlockIndex, kal_uint32 dstPage, kal_uint32 *pPageCount)
{
   FTL_STATUS_CODE status = FTL_SUCCESS;
   kal_uint32 srcBlockIdx;
   
   ASSERT( srcPage<PAGE_PER_BLOCK-1 && dstPage<PAGE_PER_BLOCK-1);
   ASSERT( srcBlockId<ctx->params.normalCBRBlock) ;

   srcBlockIdx = GetControlBlockIdx(ctx, group, srcBlockId);

   for(; status==FTL_SUCCESS && *pPageCount; (*pPageCount)--, srcPage++, dstPage++)
   {
      if(dstPage >= PAGE_PER_BLOCK-1)
      {
         break;
      }

      if(srcPage >= PAGE_PER_BLOCK-1)
      {
         srcPage = 1;
         srcBlockId++;
         ASSERT( srcBlockId<ctx->params.normalCBRBlock) ;
         srcBlockIdx = GetControlBlockIdx(ctx, group, srcBlockId);
      }
         
      status = FTL_ReadPage(ctx, srcBlockIdx, srcPage, ctx->pGlobalBuffer, NULL);

      if(status == FTL_SUCCESS)
      {
         status = FTL_WritePage(ctx, dstBlockIndex, dstPage, ctx->pGlobalBuffer, NULL);
      }
   }

   return status;

}

static void AddPageBlock(CTX ctx, kal_uint16 *pPage, kal_uint32 *pBlock, kal_uint32 pageCount)
{
   kal_uint32 i;
   for(i=0; i<pageCount; i++)
   {
      (*pPage)++;
      if(*pPage == PAGE_PER_BLOCK-1)
      {
         *pPage = 1;
         (*pBlock)++;
      }
   }
}

//Move cbr_debug_records (specified in ctx->cb_move_info) to the target block
static FTL_STATUS_CODE DoBlockMove(CTX ctx, kal_uint32 group, kal_int32 id, CB_MOVEMENT_INFO *pMoveInfo, kal_uint32 n, kal_uint32 *pCompletedRecord)
{
   FTL_STATUS_CODE status;
   kal_uint32 i;
   kal_uint32 record;

   kal_uint32 targetBlock = GetControlBlockIdx(ctx, group, id);

   PRINT("Update %d\r\n", id);

   while(1)
   {
      kal_uint32 pageIdx = 1; //Starting for the second page
      CBR_BLOCK_HEADER *pBlockHeader = (CBR_BLOCK_HEADER*)ctx->pGlobalBuffer;
      
      memset(ctx->pGlobalBuffer, 0xCD, sizeof(CBR_BLOCK_HEADER));   //Debug

      FillCBRBlockHeader(ctx, pBlockHeader);
      pBlockHeader->blockId = id;
      pBlockHeader->groupId = group;
      pBlockHeader->blockSize = FTL_GetBlockSize(ctx, targetBlock, NULL);
      
      record = 0;
      for(i=0; i<n && record<ctx->params.max_record_in_block && pageIdx<PAGE_PER_BLOCK-1; i++)
      {
         if(pMoveInfo[i].partialWritten)
         {
            kal_uint32 len;
            ASSERT(i == 0); //Should only happens on the first record

            len = MIN(pMoveInfo[i].recordLen, PAYLOAD_PAGES*PAGE_SIZE);
            pageIdx += LENGTH_IN_PAGE(len);
            pBlockHeader->prependLen = len; 
            continue;
         }
         pBlockHeader->recordIndexInfo[record].recordId  = pMoveInfo[i].type;
         pBlockHeader->recordIndexInfo[record].dpType    = pMoveInfo[i].dpInfo.dpType;
         pBlockHeader->recordIndexInfo[record].dpParam   = pMoveInfo[i].dpParam;
         pBlockHeader->recordIndexInfo[record].pageStart = pageIdx;
         pBlockHeader->recordIndexInfo[record].recordLen = pMoveInfo[i].recordLen;
         pBlockHeader->recordIndexInfo[record].attr      = pMoveInfo[i].attr;
         pageIdx += LENGTH_IN_PAGE(pMoveInfo[i].recordLen);
         record++;
      }
      pBlockHeader->recordCount = record;

      status = FTL_CheckGoodBlock(ctx, targetBlock, NULL);

      if(status == FTL_SUCCESS)
      {
         status = My_Erase(ctx, targetBlock, KAL_FALSE);
      }

      if(status == FTL_SUCCESS)
      {
         status = FTL_WritePage(ctx, targetBlock, 0, ctx->pGlobalBuffer, NULL);
      }

      //This block can only hanlde first some cbr_debug_records
      n = i;

      //Write all other pages
      pageIdx = 1;
      
      for(i=0; status==FTL_SUCCESS && i<n; i++)
      {
         kal_uint32 writtenPage;
         kal_uint32 pageToCopy = LENGTH_IN_PAGE(pMoveInfo[i].recordLen);

         
         if(pMoveInfo[i].srcIsMem)
         {
//            status = CopyPageFromMem((kal_uint8*)(pMoveInfo[i].srcBlockId), targetBlock, pageIdx, pMoveInfo[i].recordLen, &pageToCopy);
            status = CopyPageFromMem(ctx, pMoveInfo[i].source.mem, &pMoveInfo[i].dpInfo, pMoveInfo[i].dpParam, targetBlock, pageIdx, pMoveInfo[i].recordLen, &pageToCopy);
         }
         else
         {
            status = CopyPages(ctx, GetActiveGroup(ctx), pMoveInfo[i].source.block.srcBlockId, pMoveInfo[i].source.block.srcPageIndex, targetBlock, pageIdx, &pageToCopy);
         }


         if(status == FTL_SUCCESS)
         {
            writtenPage = LENGTH_IN_PAGE(pMoveInfo[i].recordLen) - pageToCopy;
            
            pageIdx += writtenPage;

            if(pageToCopy != 0)
            {
               //Some page will be placed in the next block

               //pageIdx must indicate a full block
               ASSERT(pageIdx == PAGE_PER_BLOCK-1);
               //This must happen on the last item of ctx->cb_move_info
               ASSERT(i == n-1);

               //Mark this record is partial written
               pMoveInfo[i].partialWritten = 1;
               if(pMoveInfo[i].srcIsMem)
               {
                  pMoveInfo[i].source.mem.readOffset += writtenPage*PAGE_SIZE;
               }
               else                
               {
                  AddPageBlock(ctx, &pMoveInfo[i].source.block.srcPageIndex, &pMoveInfo[i].source.block.srcBlockId, writtenPage);
                  ASSERT(pMoveInfo[i].source.block.srcBlockId<ctx->params.normalCBRBlock);
               }

               pMoveInfo[i].recordLen -= writtenPage*PAGE_SIZE;
               
               *pCompletedRecord = n-1;
               return status;
            }
         }
      }


      if(status == FTL_ERROR_BAD_BLOCK)
      {
         My_MarkBad(ctx, targetBlock);
         
         targetBlock = ReplaceBadBlock(ctx, targetBlock);
         if(targetBlock != INVALID_BLOCK_IDX)
         {
            continue;
         }
      }

      *pCompletedRecord = n;

      break;
   }

   return status;
}



static kal_uint32 CalPageCountInMoveInfo(CTX ctx)
{
   kal_uint32 i;
   kal_uint32 pageCount = 0;
   for(i=0; i<ctx->cb_move_info_count; i++)
   {
      pageCount += LENGTH_IN_PAGE(ctx->cb_move_info[i].recordLen);
   }

   return pageCount;
      
}

static kal_uint32 CalRecordCountInMoveInfo(CTX ctx)
{
   kal_uint32 i;
   kal_uint32 recordCount = 0;
   for(i=0; i<ctx->cb_move_info_count; i++)
   {
      if(!ctx->cb_move_info[i].partialWritten)
      {
         recordCount++;
      }
   }

   //Sanity test: There should be 1 partial written item at least at the begining if any
   ASSERT(ctx->cb_move_info_count == 0 || 
          recordCount == ctx->cb_move_info_count - (ctx->cb_move_info[0].partialWritten ? 1 : 0));
   
   return recordCount;
      
}

static kal_int32 FillCBMoveInfo(CTX ctx, kal_uint32 srcGroup, kal_uint32 *pSrcBlockId, FILL_MOVE_INFO_STRUCT *pOpParam, kal_bool first)
{
   kal_uint32 i;

   if(*pSrcBlockId >= ctx->params.normalCBRBlock)
   {
      return CBR_SUCCESS;
   }
   
   do
   {
      CBR_BLOCK_HEADER *pBlockHeader = (CBR_BLOCK_HEADER*)ctx->pGlobalBuffer;
      kal_uint32 blockIdx;

      blockIdx = GetControlBlockIdx(ctx, srcGroup, *pSrcBlockId);

      if(*pSrcBlockId != ctx->endBlock && ReadCBHeader(ctx, blockIdx) >= 0)
      {
         if(first && pBlockHeader->prependLen)
         {
            //Make a partialWritten entry for the data belonged to previous block
            ASSERT(ctx->cb_move_info_count < sizeof(ctx->cb_move_info)/sizeof(ctx->cb_move_info[0]));
            memset(&ctx->cb_move_info[ctx->cb_move_info_count], 0x00, sizeof(ctx->cb_move_info[ctx->cb_move_info_count]));
            ctx->cb_move_info[ctx->cb_move_info_count].srcIsMem                   = 0;
            ctx->cb_move_info[ctx->cb_move_info_count].source.block.srcBlockId    = *pSrcBlockId;
            ctx->cb_move_info[ctx->cb_move_info_count].source.block.srcPageIndex  = 1;
            ctx->cb_move_info[ctx->cb_move_info_count].recordLen                  = pBlockHeader->prependLen;
            ctx->cb_move_info[ctx->cb_move_info_count].type                       = 0;
            ctx->cb_move_info[ctx->cb_move_info_count].partialWritten             = 1;
            ctx->cb_move_info[ctx->cb_move_info_count].attr                       = 0;
            ctx->cb_move_info[ctx->cb_move_info_count].dpInfo.dpType              = SDS_DP_NONE;
            ctx->cb_move_info[ctx->cb_move_info_count].dpInfo.pDpArg              = NULL;
            ctx->cb_move_info[ctx->cb_move_info_count].dpParam                    = 0;
            
            ctx->cb_move_info_count++;

            if(pBlockHeader->recordCount)
            {
               ASSERT(pBlockHeader->recordIndexInfo[0].pageStart == LENGTH_IN_PAGE(pBlockHeader->prependLen)+1);
            }
            
         }
         
         for(i=0;i <pBlockHeader->recordCount; i++)
         {
            //It's impossible that ctx->cb_move_info is full
            ASSERT(ctx->cb_move_info_count < sizeof(ctx->cb_move_info)/sizeof(ctx->cb_move_info[0]));
            
            memset(&ctx->cb_move_info[ctx->cb_move_info_count], 0x00, sizeof(ctx->cb_move_info[ctx->cb_move_info_count]));
            
            if(pOpParam && pOpParam->op == REPLACE_RECORD && i == pOpParam->recordIdx)
            {
               kal_uint32 occupiedLen;
               const SDS_DP_Callback *pDpCallback = NULL;

               if(pBlockHeader->recordIndexInfo[i].dpType != SDS_DP_EXTERNAL)
               {
                  pDpCallback = GetCallbackFromDPType((SDS_DP_TYPE)pBlockHeader->recordIndexInfo[i].dpType);
                  if(!pDpCallback)
                  {
                     return CBR_DP_CANNOT_GET_CALLBACK;
                  }
               }
               else
               {
                  pDpCallback = (SDS_DP_Callback*)pOpParam->pData;
               }

               pDpCallback->m_get_init_info(pOpParam->length, &occupiedLen);
               
               ctx->cb_move_info[ctx->cb_move_info_count].srcIsMem              = 1;
               ctx->cb_move_info[ctx->cb_move_info_count].source.mem.srcBuffer  = pOpParam->pData;
               ctx->cb_move_info[ctx->cb_move_info_count].source.mem.srcBufLen  = pOpParam->length;
               ctx->cb_move_info[ctx->cb_move_info_count].source.mem.readOffset = 0;
               ctx->cb_move_info[ctx->cb_move_info_count].recordLen             = occupiedLen;
               ctx->cb_move_info[ctx->cb_move_info_count].type                  = pOpParam->type;
               ctx->cb_move_info[ctx->cb_move_info_count].attr                  = pBlockHeader->recordIndexInfo[i].attr;
               ctx->cb_move_info[ctx->cb_move_info_count].dpInfo.dpType         = (SDS_DP_TYPE)pBlockHeader->recordIndexInfo[i].dpType;
               ctx->cb_move_info[ctx->cb_move_info_count].dpInfo.pDpArg         = pOpParam->pDpInfo->pDpArg;
               ctx->cb_move_info[ctx->cb_move_info_count].dpParam               = (kal_uint8)(occupiedLen - pOpParam->length);
               
               ASSERT(pBlockHeader->recordIndexInfo[i].recordId == pOpParam->type); //Debug

               //Operation done
               pOpParam = NULL;
            }
            else if(pOpParam && pOpParam->op == DELETE_RECORD && i == pOpParam->recordIdx)
            {
               //Skip this record
               
               //Operation done
               pOpParam = NULL;
               continue;
            }
            else if(pOpParam && pOpParam->op == DELETE_RECORD_BY_MASK && 
                    (pBlockHeader->recordIndexInfo[i].recordId & pOpParam->recordMask) == pOpParam->recordValue &&
                     pBlockHeader->recordIndexInfo[i].recordId != ROOT_RECORD_ID)
            {
               //Skip this record
               continue;
            }
            else
            {
               ctx->cb_move_info[ctx->cb_move_info_count].srcIsMem                   = 0;
               ctx->cb_move_info[ctx->cb_move_info_count].source.block.srcBlockId    = *pSrcBlockId;
               ctx->cb_move_info[ctx->cb_move_info_count].source.block.srcPageIndex  = pBlockHeader->recordIndexInfo[i].pageStart;
               ctx->cb_move_info[ctx->cb_move_info_count].recordLen                  = pBlockHeader->recordIndexInfo[i].recordLen;
               ctx->cb_move_info[ctx->cb_move_info_count].type                       = pBlockHeader->recordIndexInfo[i].recordId;                  
               ctx->cb_move_info[ctx->cb_move_info_count].attr                       = pBlockHeader->recordIndexInfo[i].attr;
               ctx->cb_move_info[ctx->cb_move_info_count].dpInfo.dpType              = (SDS_DP_TYPE)pBlockHeader->recordIndexInfo[i].dpType;
               ctx->cb_move_info[ctx->cb_move_info_count].dpParam                    = pBlockHeader->recordIndexInfo[i].dpParam;
            }

            ctx->cb_move_info_count++;
            
         }
         (*pSrcBlockId)++;
      }
      else
      {
         //Mark it finished
         *pSrcBlockId = ctx->params.normalCBRBlock;
      }

      first = KAL_FALSE;

      if(*pSrcBlockId >= ctx->params.normalCBRBlock)
      {
         //All record read
         if(pOpParam && pOpParam->op == ADD_RECORD)
         {
            kal_uint32 occupiedLen;
            const SDS_DP_Callback *pDpCallback = NULL;
            
            ASSERT(ctx->cb_move_info_count < sizeof(ctx->cb_move_info)/sizeof(ctx->cb_move_info[0]));
            
            memset(&ctx->cb_move_info[ctx->cb_move_info_count], 0x00, sizeof(ctx->cb_move_info[ctx->cb_move_info_count]));

            if(pOpParam->pDpInfo->dpType != SDS_DP_EXTERNAL)
            {
               pDpCallback = GetCallbackFromDPType(pOpParam->pDpInfo->dpType);
               if(!pDpCallback)
               {
                  return CBR_DP_CANNOT_GET_CALLBACK;
               }
            }
            else
            {
               pDpCallback = (SDS_DP_Callback*)pOpParam->pData;
            }

            pDpCallback->m_get_init_info(pOpParam->length, &occupiedLen);
            
            ctx->cb_move_info[ctx->cb_move_info_count].srcIsMem              = 1;
            ctx->cb_move_info[ctx->cb_move_info_count].source.mem.srcBuffer  = pOpParam->pData;
            ctx->cb_move_info[ctx->cb_move_info_count].source.mem.srcBufLen  = pOpParam->length;
            ctx->cb_move_info[ctx->cb_move_info_count].source.mem.readOffset = 0;
            ctx->cb_move_info[ctx->cb_move_info_count].recordLen             = occupiedLen;
            ctx->cb_move_info[ctx->cb_move_info_count].type                  = pOpParam->type;
            ctx->cb_move_info[ctx->cb_move_info_count].attr                  = 0;
            ctx->cb_move_info[ctx->cb_move_info_count].dpInfo                = *(pOpParam->pDpInfo);
            ctx->cb_move_info[ctx->cb_move_info_count].dpParam               = (kal_uint8)(occupiedLen - pOpParam->length);

            ctx->cb_move_info_count++;
         }
         break;
      }
      
   } while(CalRecordCountInMoveInfo(ctx)<ctx->params.max_record_in_block && CalPageCountInMoveInfo(ctx)<PAYLOAD_PAGES);

   return CBR_SUCCESS;
}

static kal_bool ChangedItemUpdated(CTX ctx)
{
   kal_uint32 i;
   for(i=0; i<ctx->cb_move_info_count; i++)
   {
      if(ctx->cb_move_info[i].srcIsMem)
      {
         return KAL_FALSE;
      }
   }
   return KAL_TRUE;
}



static kal_int32 UpdateCBRRecordInternal(CTX ctx, kal_uint32 op, kal_uint16 type, const kal_uint8 *pData, kal_uint32 length, kal_uint32 extraParam, CBR_DP_INFO *pDpInfo)
{
   kal_int32 status = CBR_SUCCESS;
   kal_uint32 srcBlockId = 0, dstBlockId = 0, i;
   kal_int32 recordOffset = -1;
   kal_uint32 endBlockId = INVALID_BLOCK_ID;

   kal_uint32 lengthInPage = LENGTH_IN_PAGE(length);
   kal_uint32 complete_block_map  = 0;
   kal_uint32 updated_block_map = 0;

   FTL_STATUS_CODE ftlStatus = FTL_SUCCESS;
   kal_uint32 blockIdx;
   FILL_MOVE_INFO_STRUCT param, *pParam = NULL;

   kal_bool noBlockShift = KAL_FALSE;
      
   kal_uint32 recognizedBlock = 0;
   kal_bool finished = KAL_FALSE;

   CBR_BLOCK_HEADER *pBlockHeader = (CBR_BLOCK_HEADER*)ctx->pGlobalBuffer;

   memset(&param, 0x00, sizeof(param));

   //Parameter check
   if(op == ADD_RECORD)
   {
      ASSERT(type != ROOT_RECORD_ID && pData != NULL && length != 0 && pDpInfo != NULL);
   }
   if(op == REPLACE_RECORD)
   {
      ASSERT(type != ROOT_RECORD_ID && pData != NULL && length != 0 && pDpInfo != NULL && pDpInfo->dpType == SDS_DP_NONE);    
   }
   if(op == DELETE_RECORD)
   {
      ASSERT(type != ROOT_RECORD_ID && pData == NULL && length == 0 && pDpInfo == NULL);
   }
   if(op == DELETE_RECORD_BY_MASK)
   {
      ASSERT(pData == NULL && length == 0 && pDpInfo == NULL);
   }

   DoPowerLossRecovery(ctx, GetInactiveGroup(ctx));

   ctx->cb_move_info_count = 0;
   
   // Find the block and offset inside it of the target record
   if(op == ADD_RECORD || op == REPLACE_RECORD || op == DELETE_RECORD)
   {
      for(srcBlockId=0; srcBlockId<ctx->params.normalCBRBlock; srcBlockId++)
      {
         blockIdx = GetControlBlockIdx(ctx, GetActiveGroup(ctx), srcBlockId);
   
         if(srcBlockId == ctx->endBlock || (ReadCBHeader(ctx, blockIdx) < 0 ))
         {
            break;
         }
   
         recognizedBlock++;
         
         recordOffset = SearchRecordInCB(ctx, (CBR_BLOCK_HEADER*)ctx->pGlobalBuffer, type);
         
         if(recordOffset != -1)
         {
            break;
         }
      }
   }

   //Fill the param structure intructing how fill the moving info   
   if(op == ADD_RECORD)
   {
      kal_uint32 availablePage;
      
      if(recordOffset != -1)
      {
         return CBR_RECORD_EXISTING;
      }
	  
      srcBlockId = recognizedBlock-1;
      blockIdx = GetControlBlockIdx(ctx, GetActiveGroup(ctx), srcBlockId);
      if(ReadCBHeader(ctx, blockIdx) < 0)
      {
         ASSERT(0);
      }

      availablePage = GetAvailablePage(ctx, pBlockHeader);
      
      if(availablePage == 0)
      {
         //No space in this block, try the next one
         srcBlockId++;
         if(srcBlockId >= ctx->params.normalCBRBlock)
         {
            return CBR_FULL;
         }
      }
      else if(availablePage >= lengthInPage)
      {
         noBlockShift = KAL_TRUE;
      }

      dstBlockId = srcBlockId;

      param.op = op;
      param.pData = pData;
      param.recordIdx = recordOffset;
      param.length = length;
      param.type = type;
      param.pDpInfo = pDpInfo;

      status = FillCBMoveInfo(ctx, GetActiveGroup(ctx), &srcBlockId, &param, KAL_TRUE);

   }

   if(op == REPLACE_RECORD || op == DELETE_RECORD)
   {
      if(recordOffset == -1)
      {
         //No such record found
         return CBR_NO_SPECIFIED_RECORD;
      }
      
      dstBlockId = srcBlockId;

      if(op == REPLACE_RECORD && LENGTH_IN_PAGE(pBlockHeader->recordIndexInfo[recordOffset].recordLen) == lengthInPage)
      {
         noBlockShift = KAL_TRUE;
      }

      param.op = op;
      param.pData = pData;
      param.recordIdx = recordOffset;
      param.length = length;
      param.type = type;
      param.pDpInfo = pDpInfo;

      status = FillCBMoveInfo(ctx, GetActiveGroup(ctx), &srcBlockId, &param, KAL_TRUE);
   }

   if(op == DELETE_RECORD_BY_MASK)
   {
      param.op = op;
      param.pData = pData;
      param.recordIdx = recordOffset;
      param.length = length;
      param.recordValue = type;
      param.recordMask  = extraParam;
      param.pDpInfo = NULL;

      status = FillCBMoveInfo(ctx, GetActiveGroup(ctx), &srcBlockId, &param, KAL_TRUE);
      
      //Also use this param for each move info fill
      pParam = &param;
   }

   if(status != CBR_SUCCESS)
   {
      //Something worng in preparation of data. May be DP error
      return status;
   }
   
   //Copy blocks
   while(!finished && ctx->cb_move_info_count && ftlStatus==FTL_SUCCESS)
   {
      kal_uint32 recordFinished;

      //Consumer
      do
      {
         if(dstBlockId >= ctx->params.normalCBRBlock)
         {
            ctx->dirty_block_map |= updated_block_map;
            return CBR_FULL;
         }

         updated_block_map |= (1<<dstBlockId);
         complete_block_map |= (1<<dstBlockId); 
         
         ftlStatus = DoBlockMove(ctx, GetInactiveGroup(ctx), dstBlockId, ctx->cb_move_info, ctx->cb_move_info_count, &recordFinished);

         //Sanity: All finished record should contain no more than 30 pages
         if(ftlStatus == FTL_SUCCESS)
         {
            kal_uint32 pc = 0;
            for(i=0; i<recordFinished; i++)
            {
               pc += LENGTH_IN_PAGE(ctx->cb_move_info[i].recordLen);
            }
            ASSERT(pc<=PAYLOAD_PAGES);

            if(recordFinished && recordFinished < ctx->cb_move_info_count && recordFinished < ctx->params.max_record_in_block)
            {
               if(pc != PAYLOAD_PAGES)
               {
                  ASSERT(ctx->cb_move_info[recordFinished].partialWritten);
               }
            }
         }

         if(ftlStatus == FTL_SUCCESS)
         {
            //Remove written record
            ctx->cb_move_info_count -= recordFinished;
            memmove(&ctx->cb_move_info[0], &ctx->cb_move_info[recordFinished], sizeof(ctx->cb_move_info[0])*ctx->cb_move_info_count);

            //Switch to next target block
            dstBlockId++;
            if(noBlockShift && ChangedItemUpdated(ctx))
            {
               finished = KAL_TRUE;
            }
         }
         else
         {
            //Error, skip it
            finished = KAL_TRUE;
         }


      //to remove} while(!finished && (ctx->cb_move_info_count>=ctx->params.max_record_in_block || CalPageCountInMoveInfo(ctx)>=PAYLOAD_PAGES) );
      } while(!finished && (ctx->cb_move_info_count>ctx->params.max_record_in_block || CalPageCountInMoveInfo(ctx)>=PAYLOAD_PAGES) );

      if(finished == KAL_TRUE)
      {
         break;
      }
      //Producer
      status = FillCBMoveInfo(ctx, GetActiveGroup(ctx), &srcBlockId, pParam, KAL_FALSE);

      //There should no DP error in existing records
      ASSERT(status == CBR_SUCCESS);
   }

   //Mark the end of group
   if(ftlStatus == FTL_SUCCESS)
   {
      if(noBlockShift)
      {
         //The block keeps the same position
         endBlockId = ctx->endBlock;

         if(endBlockId != INVALID_BLOCK_IDX)
         {
            ftlStatus = MakeEndMark(ctx, GetInactiveGroup(ctx), endBlockId);
         }
      }
      else if(dstBlockId<ctx->params.normalCBRBlock)
      {
         endBlockId = dstBlockId;
         ftlStatus = MakeEndMark(ctx, GetInactiveGroup(ctx), dstBlockId);
         if(!updated_block_map)
         {
            ctx->dirty_block_map |= 1;
         }
         updated_block_map |= (1<<dstBlockId);         
      }
   }
   
   if(ftlStatus == FTL_SUCCESS)
   {
      //Special handling for wrapped SN
      if(ctx->currentSN == MAX_SN || ctx->currentSN == 0 || ctx->currentSN == 1)
      {
         ctx->dirty_block_map = 0xffffffff;
      }
   }

   //Copy dirty blocks that were not be updated in above procedure   
   for(i=0; ftlStatus==FTL_SUCCESS && i<ctx->params.normalCBRBlock && i != endBlockId; i++)
   {
      if((ctx->dirty_block_map&(~updated_block_map))&(1<<i))
      {
         blockIdx = GetControlBlockIdx(ctx, GetActiveGroup(ctx), i);

         if(ReadCBHeader(ctx, blockIdx) == CBR_SUCCESS && ReadCBTail(ctx, blockIdx) == CBR_SUCCESS)
         {
            ftlStatus = EraseBlockInGroup(ctx, GetInactiveGroup(ctx), i, KAL_TRUE);
            if(ftlStatus == FTL_SUCCESS)
            {
               PRINT("Copy %d\r\n", i);
               ftlStatus = CopyBlockToInactiveGroup(ctx, i);
               complete_block_map |= (1<<i);
            }
         }
      }
   }
      
   //Complete all blocks
   if(ftlStatus == FTL_SUCCESS)
   {
      ftlStatus = CompleteBlocksInGroup(ctx, GetInactiveGroup(ctx), complete_block_map);
   }

   if(ftlStatus == FTL_SUCCESS)
   {
      SwitchActiveGroup(ctx);
      ctx->currentSN++;

      if(ctx->currentSN > MAX_SN)
      {
         ctx->currentSN = 0;
      }
      
      ctx->dirty_block_map = updated_block_map;
      ctx->endBlock = endBlockId;
      PRINT("TEST end =%d\n", endBlockId);

      //All cbr_debug_records should be copied
      ASSERT(ctx->cb_move_info_count == 0 || finished);
      return CBR_SUCCESS;
   }
   else
   {
      //Some block has been written, should mark them dirty
      ctx->dirty_block_map |= updated_block_map;
      
      if(ftlStatus == FTL_ERROR_BAD_BLOCK)
      {
         return CBR_TOO_MANY_BAD_BLOCKS;
      }

      ctx->flashErrorCode = ftlStatus;
      return CBR_FLASH_ERROR;
   }
}


static FTL_STATUS_CODE CreateRootRecord(CTX ctx)
{
   FTL_STATUS_CODE status;
   CBR_BLOCK_HEADER *pBlockHeader = (CBR_BLOCK_HEADER*)ctx->pGlobalBuffer;
   kal_uint32 dstBlock = GetControlBlockIdx(ctx, ctx->validGroup, 0);
   kal_uint32 pageIdx = 0;
   kal_uint32 written = 0;
   kal_uint32 *p;
   ROOT_RECORD_STRUCT defaultRootRecord = { 1 };

   //Although this function supports the structure larger than a page, root record should be as small as possible
   ASSERT(sizeof(ROOT_RECORD_STRUCT) < PAGE_SIZE);

   defaultRootRecord.cbr_context = ctx->cbr_context_index;
   defaultRootRecord.creater     = CBR_CREATER;
   memcpy(defaultRootRecord.identifier, ROOT_RECORD_IDENTIFIER, sizeof(ROOT_RECORD_IDENTIFIER));
   memcpy(defaultRootRecord.cbrDateStr, CBR_DATE_STR, sizeof(CBR_DATE_STR));
   
   for(pageIdx=0; written<sizeof(ROOT_RECORD_STRUCT); pageIdx++)
   {
      memset(ctx->pGlobalBuffer, 0x00, PAGE_SIZE);
      
      if(pageIdx == 0)
      {
         FillCBRBlockHeader(ctx, pBlockHeader);
         pBlockHeader->groupId = ctx->validGroup;
         pBlockHeader->blockId = 0;
         pBlockHeader->recordCount = 1;
         pBlockHeader->recordIndexInfo[0].pageStart = 1;
         pBlockHeader->recordIndexInfo[0].recordId = ROOT_RECORD_ID;
         pBlockHeader->recordIndexInfo[0].recordLen = sizeof(ROOT_RECORD_STRUCT);
         pBlockHeader->blockSize = FTL_GetBlockSize(ctx, dstBlock, NULL);
         
         p = ctx->pGlobalBuffer;
      }
      else
      {
         p = ((kal_uint32*)&defaultRootRecord) + written/4;

         if(sizeof(ROOT_RECORD_STRUCT)-written < PAGE_SIZE)
         {
            memcpy(ctx->pGlobalBuffer, p, sizeof(ROOT_RECORD_STRUCT)-written);
            p = ctx->pGlobalBuffer;
         }
         
         written += PAGE_SIZE;
      }

      while(1)
      {
         status = FTL_CheckGoodBlock(ctx, dstBlock, NULL);
         
         if(status == FTL_SUCCESS)         
         {
            status = FTL_WritePage(ctx, dstBlock, pageIdx, p, NULL);
         }

         if(status == FTL_SUCCESS)
         {
            break;
         }

         while(status == FTL_ERROR_BAD_BLOCK)
         {
            My_MarkBad(ctx, dstBlock);
            dstBlock = ReplaceBadBlock(ctx, dstBlock);
            
            if(dstBlock == INVALID_BLOCK_IDX)
            {
               break;
            }
            status = My_Erase(ctx, dstBlock, KAL_FALSE);
         }

         if(status != FTL_SUCCESS)
         {
            return status;
         }
      }
   }

   if(status == FTL_SUCCESS)
   {
      status = MakeEndMark(ctx, ctx->validGroup, 1);
   }

   if(status == FTL_SUCCESS)
   {
      status = CompleteBlockInGroup(ctx, ctx->validGroup, 0);
   }

   if(status == FTL_SUCCESS)
   {
      ctx->endBlock = 1;
   }

   return status;
}

static void DoPowerLossRecovery(CTX ctx, kal_uint32 group)
{
   ASSERT(ctx->cbr_status != ST_UNINITIALIZED);

   if(ctx->cbr_status == ST_INITIALIZED)
   {
      //Stage 1, clean up the spare area if it's not scanned
      if(IsSpareTableReady(ctx) == KAL_FALSE)
      {
         //Unscanned spare area means we don't have any block which is needed to be replaced for current state
         //Just erase all spare blocks for writting
         kal_uint32 i;

         PRINT("Clean up\r\n");
         
         SearchReplacement(ctx, NULL);
         
         for(i=0; i<ctx->params.spareBlock; i++)
         {
            if(ctx->spareTbl[i].blockIdx != BAD_BLOCK_MARK && ctx->spareTbl[i].blockIdx != INVALID_BLOCK_IDX)
            {
               if(FTL_EraseBlock(ctx, SPARE_BLOCK_START+i, NULL) == FTL_SUCCESS)
               {
                  ctx->spareTbl[i].blockIdx = INVALID_BLOCK_IDX;
               }
               else
               {
                  ctx->spareTbl[i].blockIdx = BAD_BLOCK_MARK;
               }
            }
         }
      }
      
      ctx->cbr_status = ST_CLEANED_UP;
   }
   
}

static void InitCBRContext(CTX ctx)
{
   memset(&ctx->params, 0x00, sizeof(ctx->params));

   ctx->dirty_block_map = 0xffffffff;
   ctx->endBlock = INVALID_BLOCK_ID;    
   ctx->flashErrorCode = FTL_SUCCESS;

   memset(&ctx->spareTbl, 0x00, sizeof(ctx->spareTbl));

#ifdef __CBR_TRANS_LOG__    
   ctx->trans_log_num = 0;
#endif
    
}

static CTX GetContextFromIdx(E_CBRRegionIndex cbrIdx)
{
   kal_uint32 i;
   
   for(i=0; i<sizeof(g_Contexts)/sizeof(g_Contexts[0]); i++)
   {
      if(g_Contexts[i].cbr_context_index == cbrIdx)
      {
         return &g_Contexts[i];        
      }
   }

   ASSERT(0);

   return NULL;

}

static kal_int32 GetRecordLocation(kal_uint32 cbrIdx, kal_uint16 type, CBR_RECORD_LOCATION_STRUCT *pRecordLocationStruct)
{
   CTX ctx = GetContextFromIdx((E_CBRRegionIndex)cbrIdx);

   kal_uint32 index;
   kal_uint32 blockIdx = 0;
   kal_int32 recordOffset = -1;
   CBR_BLOCK_HEADER *pBlockHeader = (CBR_BLOCK_HEADER*)ctx->pGlobalBuffer;   

   ASSERT(pRecordLocationStruct);
   ASSERT(ctx->cbr_status != ST_UNINITIALIZED);

   for(index=0; index<ctx->params.normalCBRBlock; index++)
   {
      blockIdx = GetControlBlockIdx(ctx, GetActiveGroup(ctx), index);

      if(ReadCBHeader(ctx, blockIdx) < 0)
      {
         break;
      }
      
      recordOffset = SearchRecordInCB(ctx, (CBR_BLOCK_HEADER*)ctx->pGlobalBuffer, type);
      if(recordOffset != -1)
      {
         break;
      }
   }

   if(recordOffset != -1)
   {
      pRecordLocationStruct->index     = index;
      pRecordLocationStruct->blockIdx  = blockIdx;
      pRecordLocationStruct->pageIdx   = pBlockHeader->recordIndexInfo[recordOffset].pageStart;
      pRecordLocationStruct->recordLen = pBlockHeader->recordIndexInfo[recordOffset].recordLen;;
      pRecordLocationStruct->actualLen = pBlockHeader->recordIndexInfo[recordOffset].recordLen - (kal_int8)(pBlockHeader->recordIndexInfo[recordOffset].dpParam);
      pRecordLocationStruct->dpType    = pBlockHeader->recordIndexInfo[recordOffset].dpType;
   }
   else
   {
      return CBR_NO_SPECIFIED_RECORD;
   }

   return CBR_SUCCESS;
}

static void SearchReplacement(CTX ctx, CBR_Init_BlockInfo *pInfo)
{
   kal_uint32 i;
   CBR_BLOCK_HEADER blockHeader;
   kal_uint32 block;

   if(IsSpareTableReady(ctx))
   {
      //Spare area has been scanned
      return;
   }

   InitSpareTable(ctx);
   
   //Find all replaced bad block
   for(i=0; i<ctx->params.spareBlock; i++)
   {
      block = SPARE_BLOCK_START+i;

      PRINT("Read spare=%d\n\r", block);

      if(FTL_CheckGoodBlock(ctx, block, NULL) != FTL_SUCCESS)
      {
         PRINT("Bad\n\r");
         ctx->spareTbl[i].blockIdx = BAD_BLOCK_MARK;
         continue;
      }

      if(ReadCBHeader(ctx, block) == CBR_SUCCESS)
      {
         memcpy(&blockHeader, ctx->pGlobalBuffer, sizeof(CBR_BLOCK_HEADER));
         
         if(ReadCBTail(ctx, block) == CBR_SUCCESS)
         {
            if(blockHeader.groupId == INVALID_GROUP_ID && blockHeader.blockId == INVALID_BLOCK_ID)
            {
               //Reach the end of used spare region. The blocks starting from here are not used
               PRINT("Spare End=%d\r\n", block);
               break;
            }
            
            ASSERT(blockHeader.groupId < 2 && blockHeader.blockId < ctx->params.normalCBRBlock);
            ASSERT(blockHeader.sn <= MAX_SN);

            PRINT("Found spare for (%d, %d)\n\r", blockHeader.groupId, blockHeader.blockId);

            ASSERT(ctx->spareTbl[i].blockIdx == INVALID_BLOCK_IDX);
               
            ctx->spareTbl[i].blockIdx = TranslateGroupBlockId(ctx, blockHeader.groupId, blockHeader.blockId);

            if(pInfo)
            {
               pInfo->sn[blockHeader.groupId][blockHeader.blockId] = blockHeader.sn;
               pInfo->validBlockMask[blockHeader.groupId] |= (1<<blockHeader.blockId);
               if(blockHeader.blockAttr & BLOCK_ATTR_END)
               {
                  pInfo->endBlockMask[blockHeader.groupId] |= (1<<blockHeader.blockId);               
               }
            }
         }
      }
   }
}

/*************************************************************************
 * Exported public APIs for MAUI/DA
 *************************************************************************/

kal_int32 CBR_SetEnv(kal_uint32 cbrIdx, kal_uint32 *pBufAddr, kal_uint32 bufLen, FTL_FuncTblPtr pFtlFunc)
{
   CTX ctx = GetContextFromIdx((E_CBRRegionIndex)cbrIdx);

   ctx->cbr_status = ST_UNINITIALIZED;
   
   ctx->g_ftlFuncTbl = pFtlFunc;
   ctx->pGlobalBuffer = pBufAddr;
   ctx->pGlobalBufferLen = bufLen;
   
   return CBR_SUCCESS;
}

kal_int32 CBR_GetVersion(kal_uint32 cbrIdx, kal_uint32 cbrBlock)
{
   //Causion: This function could be used before CBR_Init, be aware of not using any functions which needs initializaion
   
   CTX ctx = GetContextFromIdx((E_CBRRegionIndex)cbrIdx);
   CBR_BLOCK_HEADER *pBlockHeader = (CBR_BLOCK_HEADER*)ctx->pGlobalBuffer;

   if(ReadCBHeader(ctx, cbrBlock) == CBR_SUCCESS)
   {
      return pBlockHeader->ver;
   }

   return -1;
}

kal_int32 CBR_DeInit(kal_uint32 cbrIdx)
{
   CTX ctx = GetContextFromIdx((E_CBRRegionIndex)cbrIdx);
   
   ctx->cbr_status = ST_UNINITIALIZED;

   return CBR_SUCCESS;
}


kal_int32 CBR_CalculateBlockParameter(kal_uint32 cbrIdx, kal_uint32 cbrRegionStart, kal_uint32 cbrRegionLen, kal_uint32 cbrFastLen,  kal_uint32 cbrSpareLen, CBR_PARAM_INFO *pParam)
{
   CTX ctx = GetContextFromIdx((E_CBRRegionIndex)cbrIdx);

   kal_uint32 block;
   kal_uint32 totalSize;
   kal_uint32 startBlock, page;

   ASSERT(pParam);

   if(cbrRegionLen <= cbrSpareLen)
   {
      return CBR_INVALID_CBR_PARAMETER;
   }

   if(FTL_AddrToBlockPage(ctx, cbrRegionStart, &startBlock, &page, NULL) == FTL_SUCCESS)
   {
      kal_uint32 storageSize = cbrRegionLen - cbrSpareLen;
      kal_uint32 blockSize = 0;
      
      if(page)
      {
         return CBR_UNALIGNED_ADDRESS;
      }

      block = 0;
      for(totalSize=0; totalSize<storageSize; totalSize += blockSize)
      {
          blockSize = FTL_GetBlockSize(ctx, startBlock+block, NULL);
          if(totalSize + blockSize > storageSize)
          {
             break;
          }
          block++;
      }

      //If it is the NAND case, the block size should be constant over the region
      if(cbrSpareLen)
      {
         if((totalSize != storageSize) || (cbrSpareLen % blockSize) || (cbrSpareLen < blockSize))
         {
            return CBR_UNALIGNED_SIZE;
         }
      }

      memset(pParam, 0x0, sizeof(*pParam));

      pParam->startBlock = startBlock;      
      pParam->normalCBRBlock = block/2;
      pParam->fastCBRBlock = 0;      
      pParam->spareBlock = cbrSpareLen/blockSize;
      pParam->totalBlock = pParam->normalCBRBlock*2 + pParam->spareBlock;

      if(pParam->normalCBRBlock == 0)
      {
         return CBR_REGION_TOO_SMALL;
      }

      if(pParam->spareBlock > MAX_SPARE_BLOCK_COUNT || pParam->normalCBRBlock > MAX_NORMAL_CB_SUPPORTED)
      {
         return CBR_REGION_TOO_LARGE;
      }

      return CBR_SUCCESS;
   }
   else
   {
      return CBR_INVALID_ADDRESS;
   }
}

kal_int32 CBR_Create(kal_uint32 cbrIdx, kal_uint32 initialBlock, kal_uint32 normal, kal_uint32 fast, kal_uint32 spare, kal_uint32 autoExtendSpareMax, E_CBRMaxRecordMode maxRecordInRecord, kal_bool roMode)
{
   CTX ctx = GetContextFromIdx((E_CBRRegionIndex)cbrIdx);
   
   FTL_STATUS_CODE status = FTL_SUCCESS;
   kal_uint32 i;
   kal_uint32 totalBlock = normal*(roMode?1:2) + fast + spare;

   ASSERT(roMode == KAL_FALSE);  //Not supported yet
   ASSERT(fast == 0);            //Not supported yet

   ASSERT(maxRecordInRecord == E_CBR_16_MAX_RECORD_IN_BLOCK || maxRecordInRecord == E_CBR_64_MAX_RECORD_IN_BLOCK);
   ASSERT(maxRecordInRecord <= MAX_RECORD_IN_BLOCK_SUPPORT);

   ASSERT(totalBlock > 0);

   ASSERT(autoExtendSpareMax == 0 || (autoExtendSpareMax <= MAX_SPARE_BLOCK_COUNT && spare <= autoExtendSpareMax));

   ASSERT(ctx->g_ftlFuncTbl);

   if(normal > MAX_NORMAL_CB_SUPPORTED || 
      fast > MAX_FAST_CB_SUPPORTED || 
      spare > MAX_SPARE_BLOCK_COUNT)
   {
      return CBR_INVALID_PARAMETER;
   }

   if(ctx->cbr_status != ST_UNINITIALIZED)
   {
      return CBR_INITIALIZED;
   }

   //Initialize ctx

   InitCBRContext(ctx);

   ctx->pageSize       = FTL_GetPageSize(ctx);
   ctx->pagePerBlock   = 0xffffffff;

   if(ctx->pGlobalBufferLen < ctx->pageSize)
   {
      return CBR_BUF_NOT_ENOUGH;
   }

   if(ctx->pageSize < 512)
   {
      return CBR_PAGE_SIZE_TOO_SMALL;
   }

   ctx->params.startBlock = initialBlock;
   ctx->params.max_record_in_block = maxRecordInRecord;
   
   ctx->params.normalCBRBlock = normal ;
   ctx->params.fastCBRBlock   = fast;
   ctx->params.spareBlock     = spare;
  
   ctx->currentSN      = 0;
   ctx->validGroup     = 0;

   //Always init it since the following operation will fill in this table
   InitSpareTable(ctx);
   
   for(i=0; i<totalBlock; i++)
   {
      kal_uint32 pages = FTL_GetBlockSize(ctx, initialBlock+i, NULL)/ctx->pageSize;

      //Find the smallest block for NOR with differenct block size
      if(pages < ctx->pagePerBlock)
      {
         ctx->pagePerBlock = pages;
      }

      status = FTL_CheckGoodBlock(ctx, initialBlock+i, NULL);

      if(status == FTL_SUCCESS)
      {
         //Erase following block: 1, first one, 2.dirty, 3.spare
         if(i==0 || IsBlockWithPossibleHeader(ctx, initialBlock+i) == KAL_TRUE || initialBlock+i >= SPARE_BLOCK_START)
         {
            status = My_Erase(ctx, initialBlock+i, KAL_TRUE);
         }
      }

      if(status == FTL_ERROR_BAD_BLOCK)
      {
         if(autoExtendSpareMax != 0)
         {
            totalBlock++;
            ctx->params.spareBlock++;

            if(ctx->params.spareBlock > autoExtendSpareMax)
            {
               return CBR_TOO_MANY_BAD_BLOCKS;
            }
         }

         if(initialBlock+i >= SPARE_BLOCK_START)
         {
            ctx->spareTbl[initialBlock+i-SPARE_BLOCK_START].blockIdx = BAD_BLOCK_MARK;
         }
      }
      else if(status != FTL_SUCCESS)
      {
         ctx->flashErrorCode = status;
         return CBR_CREATE_EMPTY_BLOCK_FAIL;
      }
   }


   //Write default mark in the spare region
   for(i=0; i<ctx->params.spareBlock; i++)
   {
      kal_uint32 block = SPARE_BLOCK_START+i;
      CBR_BLOCK_HEADER *pBlockHeader = (CBR_BLOCK_HEADER*)ctx->pGlobalBuffer;      

      if(ctx->spareTbl[i].blockIdx == BAD_BLOCK_MARK)
      {
         continue;
      }

      FillCBRBlockHeader(ctx, pBlockHeader);
      pBlockHeader->groupId = INVALID_GROUP_ID;
      pBlockHeader->blockId = INVALID_BLOCK_ID;
      pBlockHeader->blockSize = FTL_GetBlockSize(ctx, block, NULL);

      status = FTL_WritePage(ctx, block, 0, ctx->pGlobalBuffer, NULL);

      if(status == FTL_SUCCESS)
      {
         memset(ctx->pGlobalBuffer, 0x00, PAGE_SIZE);
         memcpy(ctx->pGlobalBuffer, CBR_TAIL_PATTERN, sizeof(CBR_TAIL_PATTERN));
         
         status = FTL_WritePage(ctx, block, PAGE_PER_BLOCK-1, ctx->pGlobalBuffer, NULL);
      }

      if(status == FTL_ERROR_BAD_BLOCK)
      {
         ctx->spareTbl[i].blockIdx = BAD_BLOCK_MARK;
      }
      
      if(status != FTL_SUCCESS && status != FTL_ERROR_BAD_BLOCK)
      {
         ctx->flashErrorCode = status;
      	 return CBR_CREATE_SPARE_MARKER_FAIL;
      }
   }

   //Write the CBR root record
   status = CreateRootRecord(ctx);

   if(status == FTL_SUCCESS)
   {
      ctx->currentSN++;
      ctx->cbr_status = ST_CLEANED_UP;
      return totalBlock;
   }
   else
   {
      ctx->flashErrorCode = status;
      return CBR_CREATE_ROOT_RECORD_FAIL;
   }
}


static kal_int32 CBR_BlockHeaderSanityTest(CTX ctx, CBR_BLOCK_HEADER *pBlockHeader)
{
   if(pBlockHeader->ver > CBR_VER)
   {
      return CBR_UNSUPPORTED_VERSION;
   }

   if(pBlockHeader->max_record_in_block != ctx->params.max_record_in_block)
   {
      return CBR_MISMATCH_CBR_PARAMETER;
   }

   if(pBlockHeader->normalCBRBlockCount != ctx->params.normalCBRBlock)
   {
      return CBR_MISMATCH_CBR_PARAMETER;      
   }

   if(pBlockHeader->fastCBRBlockCount != ctx->params.fastCBRBlock)
   {
      return CBR_MISMATCH_CBR_PARAMETER;      
   }

   if(pBlockHeader->spareBlockCount != ctx->params.spareBlock)
   {
      return CBR_MISMATCH_CBR_PARAMETER;      
   }

   if(pBlockHeader->sn > MAX_SN)
   {
      return CBR_INVALID_CBR_PARAMETER;      
   }

   if(pBlockHeader->recordCount > ctx->params.max_record_in_block)
   {
      return CBR_INVALID_CBR_PARAMETER;      
   }
   
   return CBR_SUCCESS;
}

kal_int32 CBR_InitEx(kal_uint32 cbrIdx, kal_uint32 initialBlock, kal_uint32 maxSearchBlock)
{
   CTX ctx = GetContextFromIdx((E_CBRRegionIndex)cbrIdx);
   
   kal_uint32 i, group, block;
   CBR_BLOCK_HEADER blockHeader;
   
   CBR_Init_BlockInfo info;

   kal_uint32 maxSn[2] = {0, 0};
   kal_uint32 minSn[2] = {MAX_SN, MAX_SN};

   memset(&info, 0x00, sizeof(info));
   info.valid[0] = info.valid[1] = KAL_TRUE;
   
   ASSERT(ctx->g_ftlFuncTbl);

   if(ctx->cbr_status != ST_UNINITIALIZED)
   {
      return CBR_INITIALIZED;
   }

   //Initialize ctx
   
   InitCBRContext(ctx);
   
   ctx->pageSize       = FTL_GetPageSize(ctx);
   ctx->pagePerBlock   = FTL_GetBlockSize(ctx, initialBlock, NULL)/ctx->pageSize;
   ctx->params.startBlock = initialBlock;

   //Note that CBR_Init doesn't init spare table. It will be init when necessary (either in SearchReplacement or DoPowerLossRecovery)
   
   if(ctx->pGlobalBufferLen < ctx->pageSize)
   {
      return CBR_BUF_NOT_ENOUGH;
   }

   if(ctx->pageSize < 512)
   {
      return CBR_PAGE_SIZE_TOO_SMALL;
   }

   if(maxSearchBlock == 0)
   {
      maxSearchBlock = MAX_CB_DEFAULT_SEARCH_BLOCK;
   }

   for(i=0; i<maxSearchBlock; i++)
   {
      if(FTL_CheckGoodBlock(ctx, initialBlock+i, NULL) != FTL_SUCCESS)
      {
         continue;
      }

      if(ReadCBHeader(ctx, initialBlock+i) == CBR_SUCCESS)
      {
         CBR_PARAM_INFO tmpInfo;
         kal_uint32 tmpPagePerBlock;
         CBR_BLOCK_HEADER *pBlockHeader = (CBR_BLOCK_HEADER*)ctx->pGlobalBuffer;

         if(pBlockHeader->blockId != INVALID_BLOCK_ID && pBlockHeader->groupId != INVALID_GROUP_ID)
         {
            kal_uint32 blockSize = FTL_GetBlockSize(ctx, initialBlock+i, NULL);

            //Preserve the values since we have to check tail with the same buffer
            tmpInfo.startBlock          = pBlockHeader->startBlock;
            tmpInfo.max_record_in_block = pBlockHeader->max_record_in_block;
            tmpInfo.normalCBRBlock      = pBlockHeader->normalCBRBlockCount;
            tmpInfo.fastCBRBlock        = pBlockHeader->fastCBRBlockCount;
            tmpInfo.spareBlock          = pBlockHeader->spareBlockCount;
            tmpPagePerBlock             = pBlockHeader->pagePerBlock;

            //Pre-test for invalid situation
            if(pBlockHeader->pagePerBlock > blockSize/ctx->pageSize)
            {
               return CBR_INVALID_FLASH_CONFIGURATION;
            }

            if(pBlockHeader->blockSize != 0xabababab && pBlockHeader->blockSize != 0 && 
               pBlockHeader->blockSize != blockSize )
            {
               return CBR_INVALID_FLASH_CONFIGURATION;
            }

            if(ReadCBTail(ctx, initialBlock+i) == CBR_SUCCESS)
            {
               if(tmpInfo.max_record_in_block != E_CBR_16_MAX_RECORD_IN_BLOCK &&
                  tmpInfo.max_record_in_block != E_CBR_64_MAX_RECORD_IN_BLOCK)
               {
                  return CBR_UNSUPPORTED_MAX_RECORD;
               }
               
               if(MAX_RECORD_IN_BLOCK_SUPPORT < tmpInfo.max_record_in_block)
               {
                  return CBR_UNSUPPORTED_MAX_RECORD;
               }

               //Note: to be compatible with previous version of CBR.
               //Todo: should be removed after W1144
               if(tmpInfo.startBlock != 0xabababab && tmpInfo.startBlock != 0)
               {
                  ctx->params.startBlock       = tmpInfo.startBlock;               
               }
               ctx->params.max_record_in_block = tmpInfo.max_record_in_block;
               ctx->params.normalCBRBlock      = tmpInfo.normalCBRBlock;
               ctx->params.fastCBRBlock        = tmpInfo.fastCBRBlock;
               ctx->params.spareBlock          = tmpInfo.spareBlock;
               ctx->pagePerBlock               = tmpPagePerBlock;      //0825 new
               
               break;               
            }
         }
      }
   }

   if(i == maxSearchBlock)
   {
      return CBR_NO_BLOCK_FOUND;
   }

   //Scan CBR and find bad blocks
   for(group=0; group<2; group++)
   {
      for(i=0; i<ctx->params.normalCBRBlock; i++)
      {
         block = TranslateGroupBlockId(ctx, group, i);
         
         if(FTL_CheckGoodBlock(ctx, block, NULL) != FTL_SUCCESS)
         {
            kal_uint32 replacement;

            info.badBlocks++;
            info.badBlockMask[group] |= (1<<i);
            
            if(info.badBlocks == 1)
            {
               SearchReplacement(ctx, &info);
            }

            replacement = GetControlBlockIdx(ctx, group, i);
            if(replacement == block)
            {
               //No replacement for this bad block, treat it as a incomplete goup
               info.incomplete[group] = KAL_TRUE;
               info.valid[group] = KAL_FALSE;
               break;
            }
            else if(info.endBlockMask[group] & (1<<i))
            {
               //Replaced with an endmark
               break;
            }
            else
            {
               //Replaced with a normal block, it's good
               continue;
            }
         }

         if(ReadCBHeader(ctx, block) == CBR_SUCCESS)
         {
            memcpy(&blockHeader, ctx->pGlobalBuffer, sizeof(CBR_BLOCK_HEADER));
            
            if(ReadCBTail(ctx, block) == CBR_SUCCESS)
            {
               kal_int32 sanityTestResult = CBR_BlockHeaderSanityTest(ctx, &blockHeader);

               if(sanityTestResult != CBR_SUCCESS)
               {
                  return sanityTestResult;
               }
               
               if(blockHeader.groupId != group || blockHeader.blockId != i)
               {
                  return CBR_INVALID_GROUP_OR_IDX;
               }

               info.sn[group][i] = blockHeader.sn;
               info.validBlockMask[group] |= (1<<i);

               if(blockHeader.blockAttr & BLOCK_ATTR_END)
               {
                  info.endBlockMask[group] |= (1<<i);
                  break;
               }
            }
            else
            {
               info.incomplete[group] = KAL_TRUE;
               info.valid[group] = KAL_FALSE;
               break;
            }
         }
         else
         {  
            //End mark
            info.endBlockMask[group] |= (1<<i);            
            break;
         }
      }
   }

   //Mark sure the group that has valid combination
   for(i=0; i<2; i++)
   {
      kal_uint32 validMask = info.validBlockMask[i];
      kal_uint32 endBlockMask = info.endBlockMask[i];
      kal_uint32 blockId = 0;

      //block id 0 must has something
      if((validMask&1) == 0)
      {
         info.valid[i] = KAL_FALSE;
      }

      //Find the max/min sn in the valid blocks
      while(validMask&1 && !(endBlockMask&1))
      {
         if(info.sn[i][blockId] > maxSn[i])
         {
            maxSn[i] = info.sn[i][blockId];
         }
         if(info.sn[i][blockId] < minSn[i])
         {
            minSn[i] = info.sn[i][blockId];
         }
         blockId++;
         validMask>>=1;
         endBlockMask>>=1;
      }
   }

   //Debug
   for(i=0; i<2; i++)
   {
      PRINT("%d: valid=%d, maxSn=%d, minSn=%d, validBlockMask=%x, endBlockMask=%x, badBlockMask=%x\r\n", i, info.valid[i], maxSn[i], minSn[i], info.validBlockMask[i], info.endBlockMask[i], info.badBlockMask[i]);
   }
   PRINT("Bad block found=%d\r\n", info.badBlocks);

   if(info.valid[0] != info.valid[1])
   {
      ctx->validGroup = info.valid[0] ? 0 : 1;
   }
   else
   {
      if(!info.valid[0])
      {
         return CBR_NO_VALID_DATA;
      }
      
      if(maxSn[0] > maxSn[1])
      {
         ctx->validGroup = 0;
      }
      else
      {
         ctx->validGroup = 1;
      }


      //Special handling for wrapped SN
      if(maxSn[0] == minSn[0] && maxSn[1] == minSn[1])
      {
         if(maxSn[0] == MAX_SN && maxSn[1] == 0)
         {
            ctx->validGroup = 1;
         }
         if(maxSn[1] == MAX_SN && maxSn[0] == 0)
         {
            ctx->validGroup = 0;
         }
      }
   }

   ctx->currentSN = maxSn[ctx->validGroup]+1;
   
   if(ctx->currentSN > MAX_SN)
   {
      ctx->currentSN = 0;
   }

   //Reset dirty block mask and end block index
   ctx->dirty_block_map = 0;
   for(i=0; i<ctx->params.normalCBRBlock; i++)
   {
      ctx->dirty_block_map |= (1<<i);
      
      if(info.endBlockMask[ctx->validGroup] & (1<<i))
      {
         ctx->endBlock = i;
         break;
      }

      //Sanity test
      if(!(info.validBlockMask[ctx->validGroup] & (1<<i)))
      {
#if defined(__MTK_INTERNAL__) && defined(__DEBUG_ASSERT__)         
         CBR_DumpCtxAndInfo(ctx);
#endif
         return CBR_INTERNAL_FAILURE;
      }
   }
   
   ctx->cbr_status = ST_INITIALIZED;
   return CBR_SUCCESS;
}

kal_int32 CBR_Init(kal_uint32 cbrIdx, kal_uint32 initialBlock)
{
   return CBR_InitEx(cbrIdx, initialBlock, 0);
}

kal_int32 GetFlashErrorCode(kal_uint32 cbrIdx)
{
   CTX ctx = GetContextFromIdx((E_CBRRegionIndex)cbrIdx);
   return (kal_int32)ctx->flashErrorCode;
}

kal_int32 CBR_WriteRecord(kal_uint32 cbrIdx, kal_uint16 type, const kal_uint8 *pData, kal_uint32 length, const void *pDpArg)
{
   CTX ctx = GetContextFromIdx((E_CBRRegionIndex)cbrIdx);
   CBR_DP_INFO dpInfo;
   kal_int32 status;

   ASSERT(length && pData);
   
   if(ctx->cbr_status == ST_UNINITIALIZED)
   {
      return CBR_NOT_INITIALIZED;
   }

   dpInfo.dpType = SDS_DP_NONE;
   dpInfo.pDpArg = pDpArg;

   status = UpdateCBRRecordInternal(ctx, REPLACE_RECORD, type, pData, length, 0, &dpInfo);

#if defined(__MTK_INTERNAL__)

#if defined(__CBR_TRANS_LOG__)
   CBR_LOG(ctx, REPLACE_RECORD, type, pData, length, status);
#endif

#if defined(__CBR_TRANS_MSG__)
   PRINT("<<CBR_WriteRecord>> type=%d, length=%d, status=%d\n", type, length, status);
#endif

#endif

   return status;
}

kal_int32 CBR_AddRecord(kal_uint32 cbrIdx, kal_uint16 type, const kal_uint8 *pData, kal_uint32 length, SDS_DP_TYPE dpType, const void *pDpArg)
{
   CTX ctx = GetContextFromIdx((E_CBRRegionIndex)cbrIdx);
   CBR_DP_INFO dpInfo;
   kal_int32 status;
   
   ASSERT(length && pData);
   
   if(ctx->cbr_status == ST_UNINITIALIZED)
   {
      return CBR_NOT_INITIALIZED;
   }

   dpInfo.dpType = dpType;
   dpInfo.pDpArg = pDpArg;

   status = UpdateCBRRecordInternal(ctx, ADD_RECORD, type, pData, length, 0, &dpInfo);

#if defined(__MTK_INTERNAL__)

#if defined(__CBR_TRANS_LOG__)
   CBR_LOG(ctx, ADD_RECORD, type, pData, length, status);
#endif

#if defined(__CBR_TRANS_MSG__)
   PRINT("<<CBR_AddRecord>> type=%d, length=%d, status=%d\n", type, length, status);
#endif

#endif

   return status;
}

kal_int32 CBR_DelRecord(kal_uint32 cbrIdx, kal_uint16 type)
{
   CTX ctx = GetContextFromIdx((E_CBRRegionIndex)cbrIdx);
   kal_int32 status;
   
   ASSERT(type != ROOT_RECORD_ID);
   
   if(ctx->cbr_status == ST_UNINITIALIZED)
   {
      return CBR_NOT_INITIALIZED;
   }

   status = UpdateCBRRecordInternal(ctx, DELETE_RECORD, type, NULL, 0, 0, NULL);

#if defined(__MTK_INTERNAL__)

#if defined(__CBR_TRANS_LOG__)
   CBR_LOG(ctx, DELETE_RECORD, type, NULL, 0, status);
#endif

#if defined(__CBR_TRANS_MSG__)
   PRINT("<<CBR_DelRecord>> type=%d, status=%d\n", type, status);
#endif

#endif

   return status;
}

kal_int32 CBR_DelRecordByMask(kal_uint32 cbrIdx, kal_uint16 typeMask, kal_uint16 typeValue)
{
   CTX ctx = GetContextFromIdx((E_CBRRegionIndex)cbrIdx);
   kal_int32 status;
  
   if(ctx->cbr_status == ST_UNINITIALIZED)
   {
      return CBR_NOT_INITIALIZED;
   }

   status = UpdateCBRRecordInternal(ctx, DELETE_RECORD_BY_MASK, typeValue, NULL, 0, typeMask, NULL);

#if defined(__MTK_INTERNAL__)

#if defined(__CBR_TRANS_LOG__)
   CBR_LOG(ctx, DELETE_RECORD_BY_MASK, typeMask, NULL, typeValue, status);
#endif

#if defined(__CBR_TRANS_MSG__)
   PRINT("<<CBR_DelRecordByMask>> typeMask=%d, typeValue=%d, status=%d\n", typeMask, typeValue, status);
#endif

#endif

   return status;
}

kal_int32 CBR_ReadRecordEx(kal_uint32 cbrIdx, kal_uint16 type, kal_uint8 *pData, kal_uint32 length, kal_bool readPartial, const void *pDpArg)
{
   CTX ctx = GetContextFromIdx((E_CBRRegionIndex)cbrIdx);

   kal_int32 status;   
   kal_uint32 index;
   kal_uint32 blockIdx;
   kal_uint32 page;
   
   const SDS_DP_Callback *pDpCallback = NULL;
   CBR_RECORD_LOCATION_STRUCT recordLocationStruct;

   if(ctx->cbr_status == ST_UNINITIALIZED)
   {
      return CBR_NOT_INITIALIZED;
   }

   status = GetRecordLocation(cbrIdx, type, &recordLocationStruct);

   if(status == CBR_SUCCESS)
   {
      kal_uint32 toRead;
      kal_uint32 dpBlockSize;
      kal_uint32 offset = 0;

      if(length == 0 && pData == NULL)
      {
         return recordLocationStruct.actualLen;
      }

      if(length < recordLocationStruct.actualLen)
      {
         if(readPartial == KAL_FALSE)
         {
            return CBR_BUF_TOO_SMALL;
         }
      }
      else
      {
         length = recordLocationStruct.recordLen;         
      }

      if(recordLocationStruct.dpType != SDS_DP_EXTERNAL)
      {
         pDpCallback = GetCallbackFromDPType((SDS_DP_TYPE)recordLocationStruct.dpType);
         if(!pDpCallback)
         {
            return CBR_DP_CANNOT_GET_CALLBACK;
         }
      }
      else
      {
         pDpCallback = (SDS_DP_Callback*)pData;
      }

      pDpCallback->m_init(0, pDpArg, &dpBlockSize);
      if(length % dpBlockSize)
      {
         return CBR_DP_BAD_BLOCK_SIZE;
      }

      //Start to read data
      blockIdx = recordLocationStruct.blockIdx;
      page     = recordLocationStruct.pageIdx;
      index    = recordLocationStruct.index;

      while(length)
      {
         kal_int32 ftlStatus;
         
         toRead = MIN(length, PAGE_SIZE);
         
         ftlStatus = FTL_ReadPage(ctx, blockIdx, page, ctx->pGlobalBuffer, NULL);

         if(ftlStatus < 0)
         {
            return CBR_READ_DATA_ERROR;
         }
         
         pDpCallback->m_rd_post_process(pData, recordLocationStruct.actualLen, offset, (const kal_uint8*)ctx->pGlobalBuffer, toRead);

         offset += toRead;
         length -= toRead;

         if(page == LAST_PAYLOAD_PAGE)
         {
            index++;
            page = FIRST_PAYLOAD_PAGE;
            blockIdx = GetControlBlockIdx(ctx, GetActiveGroup(ctx), index);
         }
         else
         {
            page++;
         }
      }

      pDpCallback->m_deinit(0);
      
      return recordLocationStruct.actualLen;
      
   }

   return status;

}

kal_int32 CBR_ReadRecord(kal_uint32 cbrIdx, kal_uint16 type, kal_uint8 *pData, kal_uint32 length, const void *pDpArg)
{
   return CBR_ReadRecordEx(cbrIdx, type, pData, length, KAL_FALSE, pDpArg);
}

kal_int32 CBR_GetRecordLen(kal_uint32 cbrIdx, kal_uint16 type)
{
   return CBR_ReadRecord(cbrIdx, type, NULL, 0, NULL);
}

kal_int32 CBR_GetParamInfo(kal_uint32 cbrIdx, CBR_PARAM_INFO *pParam)
{
   CTX ctx = GetContextFromIdx((E_CBRRegionIndex)cbrIdx);
   
   ASSERT(pParam);
   
   if(ctx->cbr_status == ST_UNINITIALIZED)
   {
      return CBR_NOT_INITIALIZED;
   }

   *pParam = ctx->params;
   pParam->totalBlock = TOTAL_CBR_BLOCK;

   return CBR_SUCCESS;
}

kal_int32 CBR_TrverseRecord(kal_uint32 cbrIdx, CBR_TRAVERSE_CB cbFunc, void *param)
{
   CTX ctx = GetContextFromIdx((E_CBRRegionIndex)cbrIdx);

   kal_uint32 index, i;
   kal_uint32 blockIdx;
   CBR_BLOCK_HEADER *pBlockHeader = (CBR_BLOCK_HEADER*)ctx->pGlobalBuffer;   
   CBR_BLOCK_HEADER blockHeader;
   
   for(index=0; index<ctx->params.normalCBRBlock; index++)
   {
      blockIdx = GetControlBlockIdx(ctx, GetActiveGroup(ctx), index);

      if(index == ctx->endBlock || ReadCBHeader(ctx, blockIdx) < 0)
      {
         break;
      }

      memcpy(&blockHeader, pBlockHeader, sizeof(*pBlockHeader));
      
      if(ReadCBTail(ctx, blockIdx) < 0)
      {
         break;
      }
      
      for(i=0; i<blockHeader.recordCount; i++)
      {
         kal_uint16 recordId = blockHeader.recordIndexInfo[i].recordId;
         kal_uint32 recordLen = blockHeader.recordIndexInfo[i].recordLen - (kal_int8)(blockHeader.recordIndexInfo[i].dpParam);

         if(recordId == ROOT_RECORD_ID)
         {
            continue;
         }
         
         if(cbFunc(recordId, recordLen, param) < 0)
         {
            return CBR_TRAVERSE_CB_FAIL;
         }
      }
   }

   return CBR_SUCCESS;
}

kal_int32 CBR_Raw_ReadRecord(kal_uint32 cbrIdx, kal_uint16 type, kal_uint32 offset, kal_uint8 **ppData, CBR_RAW_READ_RECORD_HANDLE *pHandle)
{
   CTX ctx = GetContextFromIdx((E_CBRRegionIndex)cbrIdx);
   kal_int32 status = CBR_SUCCESS;
   kal_uint32 pageOffset;
   kal_uint32 page;
   kal_uint32 index;
   kal_uint32 blockIdx;

   ASSERT(pHandle);
   
   if(ctx->cbr_status == ST_UNINITIALIZED)
   {
      return CBR_NOT_INITIALIZED;
   }

   if(pHandle->initialized == KAL_FALSE)
   {
      pHandle->currentPos = 0xffffffff;
      status = GetRecordLocation(cbrIdx, type, &pHandle->recordLocationStruct);
   }

   if(status == CBR_SUCCESS)
   {
      if(offset == 0 && ppData == NULL)
      {
         return pHandle->recordLocationStruct.recordLen;
      }

      if(offset >= pHandle->recordLocationStruct.recordLen)
      {
         status = CBR_INVALID_OFFSET;
      }
      
   }

   if(status == CBR_SUCCESS && !(offset >= pHandle->currentPos && offset < pHandle->currentPos + PAGE_SIZE))
   {
      kal_int32 ftlStatus = FTL_SUCCESS;
      
      pHandle->initialized = KAL_TRUE;

      pageOffset = offset/PAGE_SIZE;
      page = pHandle->recordLocationStruct.pageIdx;
      index = pHandle->recordLocationStruct.index;

      while(page + pageOffset > LAST_PAYLOAD_PAGE)
      {
         pageOffset -= (LAST_PAYLOAD_PAGE - page + 1);
         page = FIRST_PAYLOAD_PAGE;
         index++;
      }

      page += pageOffset;
      blockIdx = GetControlBlockIdx(ctx, GetActiveGroup(ctx), index);
      ftlStatus = FTL_ReadPage(ctx, blockIdx, page, ctx->pGlobalBuffer, NULL);

      if(ftlStatus >= 0)
      {
         pHandle->currentPos = (offset/PAGE_SIZE)*PAGE_SIZE;
      }
      else
      {
         status = CBR_READ_DATA_ERROR;
      }
   }
   
   if(status == CBR_SUCCESS)
   {
      *ppData = ((kal_uint8*)ctx->pGlobalBuffer) + (offset % PAGE_SIZE);
      return MIN(PAGE_SIZE - (offset % PAGE_SIZE), pHandle->recordLocationStruct.recordLen - offset);
   }

   return status;
}

#ifdef __MTK_INTERNAL__
#ifdef __NAND_WRITER_SIMULATE__
kal_int32 CBR_Finalize(kal_uint32 cbrIdx)
{
   CTX ctx = GetContextFromIdx((E_CBRRegionIndex)cbrIdx);
   
   kal_int32 status = CBR_SUCCESS;
   CBR_BLOCK_HEADER *pBlockHeader = (CBR_BLOCK_HEADER*)ctx->pGlobalBuffer;      
   kal_uint32 block0;
   kal_uint32 block1;
   kal_uint32 i;
   FTL_STATUS_CODE ftlStatus = FTL_SUCCESS;

   if(ctx->cbr_status == ST_UNINITIALIZED)
   {
      return CBR_NOT_INITIALIZED;
   }

   //Make sure there was no bad block, which is true for nand writter simulator
   for(i=0; i<ctx->params.spareBlock; i++)
   {
      ASSERT(ctx->spareTbl[i].blockIdx == INVALID_BLOCK_IDX || ctx->spareTbl[i].blockIdx == UNINIT_MARK);
   }
   
   for(i=0; status == FTL_SUCCESS && i<ctx->params.normalCBRBlock; i++)
   {
      block0 = TranslateGroupBlockId(ctx, 0, i);
      block1 = TranslateGroupBlockId(ctx, 1, i);

      if(i>ctx->endBlock)
      {
         ftlStatus = My_Erase(ctx, block0, KAL_FALSE);
      }
      else if(GetActiveGroup(ctx) != 0)
      {
         ftlStatus = My_Erase(ctx, block0, KAL_FALSE);
         
         if(ftlStatus == FTL_SUCCESS && (i<ctx->endBlock || IsEndBlock(ctx, block1)))
         {
            ftlStatus = CopyBlock(ctx, block1, block0, PAGE_PER_BLOCK, 0);
         }
      }
   }

   ctx->dirty_block_map = 0xffffffff;
   
   if(ftlStatus == FTL_SUCCESS)
   {
      ctx->validGroup = 0;
   }
   
   for(i=0; status == FTL_SUCCESS && i<ctx->params.normalCBRBlock; i++)
   {
      ftlStatus = My_Erase(ctx, TranslateGroupBlockId(ctx, 1, i), KAL_FALSE);
   }
   
   if(ftlStatus == FTL_SUCCESS)
   {
      return CBR_SUCCESS;
   }
   else
   {
      ctx->flashErrorCode = ftlStatus;
      return CBR_FLASH_ERROR;
   }
}

#endif
#endif

#endif /* __SV5_ENABLED__ || __SV5X_ENABLED__ || __SECURE_DATA_STORAGE__ */

