/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   fota_partial.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implement the function of FOTA firmware update downlaod 
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/*******************************************
*   Include File      
********************************************/
#if defined(__FOTA_DM__)

#include "kal_general_types.h"
#include "kal_debug.h"
#include <stdio.h>
#include <stdarg.h>
#include "fue_err.h"
#include "fota.h"
#include "flash_opt.h"
#include "fat_fs.h"
#include "custom_fota.h"
#include "custom_img_config.h"
#include "fue.h"
#include "ssf_fue_support.h"
#include "fue_update_support.h"
#if defined(__MAUI_BASIC__)
#include "uart_sw.h"
#endif /* __MAUI_BASIC__ */
#if defined(__HP_FOTA__)
#include "Bitfone_update.h"
#endif

#include "dcl.h"

#ifdef __EMMC_BOOTING__
#include "fue_emmc_adapt.h"
#endif

#define _FUE_PKG_DEBUG_

/*******************************************************************************
 *   Global Function and Structure Definition
 *******************************************************************************/

FOTA_DATA FOTAData={STATUS_FOTA_NOT_INITIAL};

FOTA_NFB_Update_Control    FOTA_Update_Ctrl;
FOTA_Package_Control_st    FOTA_Package_Ctrl;

#pragma arm section zidata = "NONCACHEDZI"

kal_uint32  fota_temp_page_buffer[FOTA_FLASH_MAX_PAGE_SIZE];
kal_uint32  fota_replace_page_buffer[FOTA_FLASH_MAX_PAGE_SIZE];

#pragma arm section zidata

/*******************************************************************************
 *   Static Function and Structure Definition
 *******************************************************************************/
static kal_int32 FOTA_MTD_Read_Buffer(void *Buffer, kal_uint32 read_len);

/* start address of update package reserved area */
extern const kal_uint32 FOTA_PACKAGE_BASE_ADDRESS;

/* Following functions and data varoables are located in FOTA library */
extern FUE_ERROR_CODE FUE_InitializeUpdateRecord(kal_uint32 base_blk, kal_uint32 end_blk, \
                                                 Flash_GAL_st *fgal, dbg_trace_func dbg_trace);
extern FUE_ERROR_CODE FUE_NFB_Flush_Update_Record(FOTA_Custom_Update_Info* info_buffer, \
                                                  dbg_trace_func dbg_trace);
extern FUE_ERROR_CODE FUE_NFB_Get_Update_Record(FOTA_Custom_Update_Info* info_buffer,\
                                                dbg_trace_func dbg_trace);

extern FUE_ERROR_CODE FUE_NFB_Allocate_Block(kal_uint32 begin_block, kal_uint32 end_block, \
                                             kal_uint32 curr_block, kal_uint32 *alloc_block, \
                                             Flash_GAL_st *fgal, IsBlockAvailable_func check_available, \
                                             dbg_trace_func dbg_trace);

extern FUE_ERROR_CODE FUE_BlkInfo_Resume_Package_Blocks(FOTA_Package_Control_st *pkg_ctrl, \
                                                        kal_uint32 *found_blocks, \
                                                        /*FOTA_Package_Location_st *found_list, \*/
                                                        FOTA_Package_List_st *found_list,\
                                                        kal_uint32 *buff_ptr, \
                                                        kal_uint32 *buff_len, \
                                                        /*alloc_pkg_blk alloc_blk, \*/
                                                        dbg_trace_func dbg_trace);

extern kal_bool FUE_NFB_Is_Available_Block(kal_uint32 block_idx, kal_uint32* buff_ptr, Flash_GAL_st *fgal, \
                                           dbg_trace_func dbg_trace);

extern FUE_ERROR_CODE FUE_NFB_Replace_Current_Package_Block(FOTA_Package_Control_st *pkg_ctrl,\
                                                            kal_uint32 *buff_ptr, \
                                                            dbg_trace_func dbg_trace);

extern FUE_ERROR_CODE FUE_NFB_Mark_Package_Block_Complete(FOTA_Package_Control_st *pkg_ctrl, \
                                                          FOTA_Package_Info_st *pkg_info, dbg_trace_func dbg_trace);

extern FUE_ERROR_CODE FUE_NFB_Allocate_PackageBlock(FOTA_Package_Control_st *pkg_ctrl, kal_uint32 start_block, \
                                                    kal_uint32 *alloc_block, dbg_trace_func dbg_trace);

extern FUE_ERROR_CODE FUE_NFB_Create_Package_Block(FOTA_Package_Control_st *pkg_ctrl, kal_uint32 block_index,\
                                                   kal_uint32 last_block, kal_uint32 replace_block, \
                                                   kal_bool add_session, dbg_trace_func dbg_trace);

extern FUE_ERROR_CODE FUE_CreateInitialUpdateRecord(FOTA_NFB_Update_Control *update_ctrl, kal_uint32 start_block, \
                                                    Flash_GAL_st *fgal, dbg_trace_func dbg_trace);

extern FUE_ERROR_CODE FUE_BlkInfo_Is_Package_Block(FOTA_Package_Control_st *pkg_ctrl, kal_uint32 blk_num, dbg_trace_func dbg_trace);

extern FUE_ERROR_CODE FUE_BlkInfo_Is_Update_Block(FOTA_NFB_Update_Control *update_ctrl, kal_uint32 blk_num, dbg_trace_func dbg_trace);

extern kal_uint32 SSF_GetMAUIImageNumber(void);

extern void FUE_Start_Download_State(void);

extern void FUE_Start_Package_Verification_State(void);

extern FOTA_Area_Info_Wrapper_st  FOTA_NFB_Area_Info;

/* For update package block management */
extern FOTA_Package_List_st g_fota_package_blocks[FOTA_PACKAGE_BLOCK_NUMBER];
extern kal_uint32 FOTA_PKG_BLOCKS;

/* Following functions are located in init.c */
extern kal_uint32 INT_GetCurrentTime(void);

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
extern kal_uint32 custom_get_NORFLASH_ROMSpace(void);
extern kal_uint32 custom_get_NORFLASH_Base(void);
#endif

/* the NFI access synchronization is implemented in NAND flash MTD layer */
#define FOTA_LOCK()   
#define FOTA_UNLOCK() 

/* Forward declaration */
Flash_GAL_st *FOTA_Setup_FGAL(void);
static kal_int32 FOTA_MTD_Program_Buffer(void *Buffer, kal_uint32 write_len);

kal_int32 FOTA_InitializeUpdateRecord(void);

kal_int32 FOTA_InitializePackageReservoir(void);
kal_int32 FOTA_FinishPackageBlock(void);
kal_int32 FOTA_CheckAvailablePackageBlocks(kal_uint32 *available_num);
kal_int32 FOTA_ClearPackageReservoir(void);
kal_int32 FOTA_Get_TotalPackageBlock(kal_uint32 *pkg_blks, kal_uint32* pkg_pages);
kal_int32 FOTA_Get_CurrentPackagePosition(kal_uint32 *curr_blks, kal_uint32* curr_pages);
kal_int32 FOTA_ProgramPackagePage(void* buff, kal_uint32 *page_size);

kal_int32 FOTA_GetPackageFlashInfo(kal_uint32 *blk_size, kal_uint32 *page_size);

#if defined(__MAUI_BASIC__)

#if defined(__NOR_FLASH_HARDWARE_TEST__)
extern kal_uint8 PLTestOption; // 0: Random reset 1: reset only in flash busy time.(Only for ESB now)

void PL_Start_Trigger(void)
{
   PLTestOption = 1;
}

void PL_Stop_Trigger(void)
{
   PLTestOption = 0;
}

#elif defined(__NAND_FLASH_HARDWARE_TEST__)

#define PL_ERASE_RATIO    (0x3)
#define PL_PROGRAM_RATIO  (0xF)

kal_uint8 Start_PL_Flag;
kal_uint8 PL_Erase;
kal_uint8 PL_PROGRAM;

#if 0
/* under construction !*/
/* under construction !*/
#endif

kal_uint32 scrambleRandom(void)
{
   kal_uint32 random_val  = 0;
   kal_uint32 counter_32k = 0;
#if 0
/* under construction !*/
/* under construction !*/
#else
   DCL_HANDLE rtc_handler;
   RTC_CTRL_GET_TIME_T rtc_cmd_data3;
#endif

   counter_32k = INT_GetCurrentTime();
   random_val = rand();
   counter_32k -= INT_GetCurrentTime();
   counter_32k ^= INT_GetCurrentTime();
#if 0   
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
   rtc_handler = DclRTC_Open(DCL_RTC, FLAGS_NONE);
   DclRTC_Control(rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *)&rtc_cmd_data3); // New API with CMD & DATA 
   DclRTC_Close(rtc_handler);
   counter_32k += rtc_cmd_data3.u1Hour*3600+rtc_cmd_data3.u1Min*60+rtc_cmd_data3.u1Sec;
#endif
   random_val ^= counter_32k;

   return random_val;
}

void PL_Start_Trigger(void)
{
   Start_PL_Flag = KAL_TRUE;
}

void PL_Stop_Trigger(void)
{
   Start_PL_Flag = KAL_FALSE;
}

void PL_Program_Trigger(void)
{

   if(7 == (scrambleRandom()&PL_PROGRAM_RATIO))
      PL_PROGRAM = KAL_TRUE;
   else
      PL_PROGRAM = KAL_FALSE;
}

void PL_Erase_Trigger(void)
{
   if(3 == (scrambleRandom()&PL_ERASE_RATIO))
      PL_Erase = KAL_TRUE;
   else
      PL_Erase = KAL_FALSE;
}

#endif /* !__NOR_FLASH_HARDWARE_TEST__ && !__NAND_FLASH_HARDWARE_TEST__ */

#endif /*  __MAUI_BASIC__ */
/*****************************************************************
Description : dump trace via kal_print function.
Input       : 
Output      : None
******************************************************************/
kal_char  g_char_buff[512];
void fue_dbg_print(kal_char* fmt, ...)
{
   va_list trace_p;
   va_start(trace_p, fmt);
   vsprintf(g_char_buff, fmt, trace_p);
   va_end(trace_p);
   kal_print(g_char_buff);
#if defined(__MAUI_BASIC__)
   if(KAL_FALSE == kal_query_systemInit())
   {
       while(!UART_CheckTxBufferEmpty(uart_port1)); /* wait for UART dump complete */
   }
#endif
}

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_Package_Blk_Address
DESCRIPTION
   convert to block aligned address
PARAMETER
   NULL
RETURN
   INVALOD_DWORD : out of range
--------------------------------------------------------------------------------- */
kal_uint32 FOTA_Package_Blk_Address(FOTA_Package_Control_st *pkg_ctrl, kal_uint32 dst_addr)
{
   Logical_Flash_info_st  info;
   kal_uint32             blk_idx      = 0;
   kal_uint32             blk_addr     = 0;
   kal_uint32             phy_blk      = 0;
   kal_uint32             curr_blk_num = pkg_ctrl->m_fota_pkg_blocks;
   Flash_GAL_st           *fgal        = pkg_ctrl->m_pkg_fgal;

   ASSERT(fgal);

   fgal->query_info(&info);
   for(blk_idx = 0 ; blk_idx < curr_blk_num ; blk_idx++)
   {
      phy_blk = pkg_ctrl->m_fota_pkg_list[blk_idx].m_pkg_block_position;
      blk_addr += (fgal->block_size(phy_blk)- 2*info.Flash_page_size);
      if(blk_addr >= dst_addr)
         break;
   }
   if( blk_idx == curr_blk_num )
   {
      fue_dbg_print("FOTA_Package_Blk_Idx: address:0x%x is beyond available %dblks!\n\r",
                     dst_addr, curr_blk_num);
      ASSERT(0);
      return INVALID_DWORD;
   }
   else
   {
      if(blk_addr == dst_addr)
         fue_dbg_print("FOTA_Package_Blk_Idx: address:0x%x is on the bounadry of blk:%d(%d)!\n\r",
                        dst_addr, blk_idx, phy_blk);

      return blk_addr;
   }
}

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_Initialize
DESCRIPTION
   FOTA Initialization API
   1. Initialize data structure and progress initial step
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_Initialize(void)
{
   kal_int32              Ret;

   if( STATUS_FOTA_INITIALIZED == FOTAData.Status )
   {
      return ERROR_FOTA_SUCCESS;
   }

   Ret = FOTA_InitializeUpdateRecord();
   if( (ERROR_FOTA_NO_AVAILABLE_BLOCK == Ret) || (ERROR_FUE_OPERATION_STOP == Ret) ||
       (ERROR_FUE_OVER_DESIGN == Ret) )
      return Ret;
   
   Ret = FOTA_InitializePackageReservoir();

   if(ERROR_FOTA_INVALID_PARAMETER == Ret)
   {
      return Ret;
   }
   fue_dbg_print("FOTA_Initialize: %d updatable images!\n\r", SSF_GetMAUIImageNumber());

   FOTAData.SpareCurrWriteAddr = 0; 
   FOTAData.SpareNextWriteBlockAddr = 0;
   FOTAData.SpareCurrReadAddr = 0; 
   FOTAData.SpareNextReadBlockAddr = 0;
   FOTAData.BufferIndex = 0;
   
   if((Ret = FOTA_CustomInitialize()) < 0)
      return Ret;
   else
      FOTAData.Status = STATUS_FOTA_INITIALIZED;
   return ERROR_FOTA_SUCCESS;   
}

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_WriteData
DESCRIPTION
   FOTA write data API
   1. This function is used to write data to spare image pool
   2. This API only allow sequentially writing mechanism
   3. Authentication mechanism is executed during writing
PARAMETER
   Length: the length of writing (Unit: Bytes)
   Buffer: the start address of buffer
RETURN
   0: means pass write success (ERROR_FOTA_SUCCESS)
   < 0: writing action is fail
      ERROR_FOTA_AUTH_ROMINFO: authentication fail, can't find rom info
      ERROR_FOTA_AUTH_FATBEGIN: authentication fail, fat begin address is different
      ERROR_FOTA_AUTH_FATLEN: authentication fail, fat length is different
      ERROR_FOTA_AUTH_HCHECKSUM: authentication fail, header checksum fail
      ERROR_FOTA_AUTH_ID: authentication fail, platform id is different
      ERROR_FOTA_AUTH_VERSION: authentication fail, downgrade is not allowed
      ERROR_FOTA_AUTH_IMAGELEN: authentication fail, image length too large
	 ERROR_FOTA_AUTH_FAIL: authentication fail before
	 ERROR_FOTA_OVERRANGE: write over the spare image pool range
	 ERROR_FOTA_NOT_INITIALIZED: not call FOTA_Initialize before
--------------------------------------------------------------------------------- */
kal_int32 FOTA_WriteData(kal_uint32 Length, void* Buffer)
{
   kal_int32  result;
   kal_uint32 buff_addr = (kal_uint32)Buffer;
   kal_uint8  *byte_ptr = NULL;

   if (FOTAData.Status == STATUS_FOTA_NOT_INITIAL)
      return ERROR_FOTA_NOT_INITIALIZED;

   while(Length > 0)
   {
      if ((FOTAData.BufferIndex+Length)>=FOTA_BUFFER_SIZE)
      {
         /* no data in write buffer and user buffer is 4-byte aligned */
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
         if( ( (FOTAData.BufferIndex == 0) && (0 == (buff_addr & 0x03)) ) 
             && ( ( (buff_addr+FOTA_BUFFER_SIZE) <= custom_get_NORFLASH_Base() )
               && ( buff_addr >= (custom_get_NORFLASH_Base()|custom_get_NORFLASH_ROMSpace()) ) ) )
#else /* !__SINGLE_BANK_NOR_FLASH_SUPPORT__ */
         if( (FOTAData.BufferIndex == 0) && (0 == (buff_addr & 0x03)) ) 
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
         {
            result = FOTA_MTD_Program_Buffer((void*)buff_addr, FOTA_BUFFER_SIZE);
         	  if (result < 0)
               return result;
            buff_addr += FOTA_BUFFER_SIZE;
            Length -= FOTA_BUFFER_SIZE;
         }
         else
         {
            if(FOTAData.BufferIndex != FOTA_BUFFER_SIZE)
            {
               byte_ptr = (kal_uint8 *)(((kal_uint32)FOTAData.FOTAWriteBuffer) + FOTAData.BufferIndex);
               //kal_mem_cpy((void*)&FOTAData.FOTABuffer[FOTAData.BufferIndex>>2], Buffer, FOTA_BUFFER_SIZE - FOTAData.BufferIndex);
               kal_mem_cpy(byte_ptr, (void *)buff_addr, FOTA_BUFFER_SIZE - FOTAData.BufferIndex);
               buff_addr += (FOTA_BUFFER_SIZE - FOTAData.BufferIndex);
               Length -= (FOTA_BUFFER_SIZE - FOTAData.BufferIndex);
               FOTAData.BufferIndex = FOTA_BUFFER_SIZE;
            }
            result = FOTA_MTD_Program_Buffer((void*)FOTAData.FOTAWriteBuffer, FOTA_BUFFER_SIZE);
            if (result < 0)
               return result;
            FOTAData.BufferIndex = 0;
         }
      }
      else
      {
         byte_ptr = (kal_uint8 *)(((kal_uint32)FOTAData.FOTAWriteBuffer) + FOTAData.BufferIndex);
         //kal_mem_cpy((void*)&FOTAData.FOTABuffer[FOTAData.BufferIndex/4], Buffer, Length);
         kal_mem_cpy(byte_ptr, (void *)buff_addr, Length);
         FOTAData.BufferIndex += Length;
         buff_addr += Length;
         Length = 0;
      }
   }
   return ERROR_FOTA_SUCCESS;   
}

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_ReadData
DESCRIPTION
   FOTA read data API
   1. This function is used to read data from spare image pool
   2. This API only support sequentially read operation, i.e. from low address to high address
PARAMETER
   Length: the length of reading (Unit: Bytes)
   Buffer: the start address of buffer
RETURN
   0: means pass write success (ERROR_FOTA_SUCCESS)
   < 0: writing action is fail
      ERROR_FOTA_AUTH_ROMINFO: authentication fail, can't find rom info
      ERROR_FOTA_AUTH_FATBEGIN: authentication fail, fat begin address is different
      ERROR_FOTA_AUTH_FATLEN: authentication fail, fat length is different
      ERROR_FOTA_AUTH_HCHECKSUM: authentication fail, header checksum fail
      ERROR_FOTA_AUTH_ID: authentication fail, platform id is different
      ERROR_FOTA_AUTH_VERSION: authentication fail, downgrade is not allowed
      ERROR_FOTA_AUTH_IMAGELEN: authentication fail, image length too large
	 ERROR_FOTA_AUTH_FAIL: authentication fail before
	 ERROR_FOTA_OVERRANGE: write over the spare image pool range
	 ERROR_FOTA_NOT_INITIALIZED: not call FOTA_Initialize before
--------------------------------------------------------------------------------- */
kal_int32 FOTA_ReadData(kal_uint32 Length, void* Buffer)
{
   kal_int32  result      = ERROR_FOTA_SUCCESS;
   kal_uint32 buffer_addr = (kal_uint32)Buffer;
   kal_uint32 read_len    = 0;
   kal_uint32 copy_size   = 0;

   if (FOTAData.Status == STATUS_FOTA_NOT_INITIAL)
      return ERROR_FOTA_NOT_INITIALIZED;

   while(Length > read_len)
   {
      if( ( (Length-read_len) >= FOTA_BUFFER_SIZE) && (0 == ((buffer_addr)&0x03)) )
      {
         /* directly read into user's buffer */
         result = FOTA_MTD_Read_Buffer((void*)buffer_addr, FOTA_BUFFER_SIZE);
         if(result < 0)
            break;
         buffer_addr += FOTA_BUFFER_SIZE;
         read_len    += FOTA_BUFFER_SIZE;
      }
      else
      {
         if( (Length-read_len) >= FOTA_BUFFER_SIZE)
            copy_size = FOTA_BUFFER_SIZE;
         else
            copy_size = (Length-read_len);

         /* read into temporary buffer */
         result = FOTA_MTD_Read_Buffer(FOTAData.FOTAReadBuffer, copy_size);
         if (result < 0)
            break;

         kal_mem_cpy((void *)buffer_addr, FOTAData.FOTAReadBuffer, copy_size);
         buffer_addr += copy_size;
         read_len    += copy_size;
      }
   }

   return result;   
}

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_Finalize
DESCRIPTION
   FOTA finalization API
   1. compare calculated checksum with image checksum in the header after 
       whole image is written 
   2. mark the status to UPDATE_NEEDED 
PARAMETER
   void
RETURN
   0: means pass error check step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_AUTH_FAIL: authentication fail, final step is not allowed
      ERROR_FOTA_IMAGE_CHECKSUM: image checksum error
--------------------------------------------------------------------------------- */
kal_int32 FOTA_Finalize(void)
{
   kal_int32  result = 0;

   if (FOTAData.Status == STATUS_FOTA_NOT_INITIAL)
      return ERROR_FOTA_NOT_INITIALIZED;

   if(FOTAData.BufferIndex != 0)
   {
      result = FOTA_MTD_Program_Buffer((void*)FOTAData.FOTAWriteBuffer, FOTAData.BufferIndex);
      FOTA_FinishPackageBlock();
      if (result < 0)
         return result;
      FOTAData.BufferIndex = 0;
   }

   FOTAData.Status = STATUS_FOTA_FINAL;

   return ERROR_FOTA_SUCCESS;
}

/* --------------------------------------------------------------------------------- *
 * Flash device wrapper functions
 * --------------------------------------------------------------------------------- */

/************************************************************************************
 * NAND flash part
 *************************************************************************************/
static kal_int32 FOTA_MTD_Program_Buffer(void *Buffer, kal_uint32 write_len)
{
   kal_uint32 buff_offset = 0;
   kal_int32 left_length = write_len;
   kal_uint32 page_size = 0;
   kal_int32  ret_code = ERROR_FOTA_SUCCESS;

   if(FOTA_UPDATE_PACKAGE_STATE != FOTA_Package_Ctrl.m_fota_pkg_state)
   {
      ASSERT(0);
      return ERROR_FOTA_NOT_INITIALIZED;
   }

   while(left_length > 0)
   {
      ret_code = FOTA_ProgramPackagePage((void*)(((kal_uint32)Buffer)+buff_offset), &page_size);
      if(ERROR_FOTA_SUCCESS == ret_code)
      {
         buff_offset += page_size;
         left_length -= page_size;
         FOTAData.SpareCurrWriteAddr += page_size;
      }
      else if( (ERROR_FOTA_NO_AVAILABLE_BLOCK == ret_code) || (ERROR_FOTA_FLASH_DEVICE==ret_code) ||
              (ERROR_FOTA_UNSUPPORTED_CASES == ret_code) )
      {
         break;
      }
   }
   return ret_code;

}

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_FinishePackageBlock
DESCRIPTION
   download is finished, complete current package block
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
        ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_FinishPackageBlock(void)
{
   kal_uint32               page_per_blk = 0;
   FOTA_Package_Info_st     *pkg_info    = NULL;
   kal_int32                ret_code     = ERROR_FOTA_SUCCESS;
   FUE_ERROR_CODE           result       = ERROR_FUE_NONE;
   Logical_Flash_info_st     info;
   Flash_GAL_st              *fgal       = FOTA_Package_Ctrl.m_pkg_fgal;

   if(FOTA_UPDATE_PACKAGE_STATE != FOTA_Package_Ctrl.m_fota_pkg_state)
   {
      ASSERT(0);
      return ERROR_FOTA_NOT_INITIALIZED;
   }
   ASSERT(fgal);
   pkg_info = &FOTA_Package_Ctrl.m_fota_pkg_info;;
   //page_per_blk = 1 << FOTA_Package_Ctrl.m_fota_flash_info.Flash_offset_shift;
   fgal->query_info(&info);
   page_per_blk = fgal->block_size(pkg_info->m_pkg_current_block)/info.Flash_page_size;

   if(pkg_info->m_pkg_current_page == page_per_blk)
   {
      /* current package has been marked as complete in last package program operation */
      if( pkg_info->m_pkg_valid_pages == (page_per_blk-3))
      {
         fue_dbg_print("FOTA_FinishPackageBlock: mark blk:%d as complete is already done!\n\r",\
                        pkg_info->m_pkg_current_block);
      }
      #ifdef _FUE_PKG_DEBUG_
      else
      {
         fue_dbg_print("FOTA_FinishPackageBlock: incomplete blk:%d has been marked complete already!\n\r",\
                        pkg_info->m_pkg_current_block);
         #if defined(__FOTA_DEBUG_ASSERT__)
         ASSERT(0);
         #endif /* __FOTA_DEBUG_ASSERT__ */
      }
      #endif /* _FUE_PKG_DEBUG_ */

      /* indicate current package download is done */
      FOTA_Package_Ctrl.m_fota_pkg_index = INVALID_DWORD;
   }
   else
   {
      while(1)
      {
         /* mark this package block as complete */
         result = FUE_NFB_Mark_Package_Block_Complete(&FOTA_Package_Ctrl, pkg_info, fue_dbg_print);
         if(ERROR_FUE_NONE == result)
         {
            fue_dbg_print("FOTA_FinishPackageBlock: mark blk:%d as complete done!\n\r",\
                           pkg_info->m_pkg_current_block);
            /* indicate current package download is done */
            FOTA_Package_Ctrl.m_fota_pkg_index = INVALID_DWORD;
            break;
         }
         else if(ERROR_FUE_PROGRAM_FAILED == result)
         {
            /* block replacement procedure - caused by marking complete function */
            result = FUE_NFB_Replace_Current_Package_Block(&FOTA_Package_Ctrl, fota_replace_page_buffer, \
                                                           fue_dbg_print);
            if( ERROR_FUE_OVER_DESIGN == result )
            {
               ret_code = ERROR_FOTA_UNSUPPORTED_CASES;
               break;
            }
            else if( ERROR_FUE_NO_AVAILABLE_BLOCK == result )
            {
               ret_code = ERROR_FOTA_NO_AVAILABLE_BLOCK;
               break;
            }
            else if(ERROR_FUE_NOT_INITIALIZED == result)
            {
               ret_code = ERROR_FOTA_NOT_INITIALIZED;
               break;
            }
         }
         else
         {
            /* unexpected status, abort current update package */
            fue_dbg_print("FOTA_FinishPackageBlock: unexpected error on blk:%d, Abort!!\n\r",\
                           pkg_info->m_pkg_current_block);
            break;
         }
      }
   }
   return ret_code;
}

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_ProgramPackagePage
DESCRIPTION
   clear downloaded update package
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
        ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_ProgramPackagePage(void* buff, kal_uint32 *page_size)
{
   kal_int32            ret_code     = ERROR_FOTA_SUCCESS;
   kal_uint32           page_per_blk = 0;
   kal_uint32           curr_blk     = INVALID_DWORD;
   kal_uint32           curr_order   = INVALID_DWORD;
   kal_uint32           alloc_block  = INVALID_DWORD;
   FOTA_Package_Info_st *pkg_info    = NULL;
   Logical_Flash_info_st     info;
   Flash_GAL_st          *fgal       = FOTA_Package_Ctrl.m_pkg_fgal;
   _FGAL_ERROR_CODE     status       = ERROR_FGAL_NONE;
   FUE_ERROR_CODE       result       = ERROR_FUE_NONE;
   kal_bool             op_done      = KAL_FALSE;
   
   if(FOTA_UPDATE_PACKAGE_STATE != FOTA_Package_Ctrl.m_fota_pkg_state)
   {
      ASSERT(0);
      return ERROR_FOTA_NOT_INITIALIZED;
   }
   ASSERT(fgal);

   pkg_info     = &FOTA_Package_Ctrl.m_fota_pkg_info;
   fgal         = FOTA_Package_Ctrl.m_pkg_fgal;
   //page_per_blk = 1 << FOTA_Package_Ctrl.m_fota_flash_info.Flash_offset_shift;
   fgal->query_info(&info);
   *page_size   = 0;

   if( INVALID_DWORD != pkg_info->m_pkg_current_block )
   {
      page_per_blk = fgal->block_size(pkg_info->m_pkg_current_block)/info.Flash_page_size;
      if( pkg_info->m_pkg_current_page < (page_per_blk-1) )
      {
         do
         {
            if(pkg_info->m_pkg_current_page == (page_per_blk-2))
            {
               /* mark current package block as complete */
               result = FUE_NFB_Mark_Package_Block_Complete(&FOTA_Package_Ctrl, pkg_info, fue_dbg_print);
               if(ERROR_FUE_NONE == result)
               {
                  break;
               }
            }
            else if(0 == *page_size)
            {
               status = fgal->write_page(buff, pkg_info->m_pkg_current_block, pkg_info->m_pkg_current_page);
               if(ERROR_FGAL_NONE == status)
               {
                  pkg_info->m_pkg_current_page++;
                  pkg_info->m_pkg_valid_pages++;
                  FOTA_Package_Ctrl.m_fota_pkg_pages++;
                  *page_size = info.Flash_page_size;
                  op_done = KAL_TRUE;
               }
               else if(ERROR_FGAL_OPERATION_RETRY == status)
               {
                  ret_code = ERROR_FOTA_FLASH_DEVICE;
                  break;
               }
            }
            else
            {
               /* package page program done */
               break;
            }

            if( (ERROR_FGAL_WRITE_FAILURE == status) || (ERROR_FUE_PROGRAM_FAILED == result) )
            {
               /* copy valid pages in bad block to new package block */
               result = FUE_NFB_Replace_Current_Package_Block(&FOTA_Package_Ctrl, fota_replace_page_buffer, \
                                                              fue_dbg_print);
               if( ERROR_FUE_OVER_DESIGN == result )
               {
                  ret_code = ERROR_FOTA_UNSUPPORTED_CASES;
                  break;
               }
               else if( ERROR_FUE_NO_AVAILABLE_BLOCK == result )
               {
                  ret_code = ERROR_FOTA_NO_AVAILABLE_BLOCK;
                  break;
               }
               else if( ERROR_FUE_NOT_INITIALIZED == result )
               {
                  ret_code = ERROR_FOTA_NOT_INITIALIZED;
                  break;
               }
            }
         }while(1);
      }
   }
   /* 
    * else start to allocate new package block 
    */

   if(!op_done)
   {
      if(INVALID_DWORD == pkg_info->m_pkg_current_block)
      {
         ASSERT(INVALID_DWORD == FOTA_Package_Ctrl.m_fota_pkg_index);
         ASSERT(INVALID_DWORD == pkg_info->m_pkg_block_session);
         curr_blk = FOTA_Package_Ctrl.m_fota_pkg_area.FOTA_pkg_area_base;
         curr_order = INVALID_DWORD;
      }
      else
      {
         ASSERT(INVALID_DWORD != FOTA_Package_Ctrl.m_fota_pkg_index);
         curr_blk = pkg_info->m_pkg_current_block;
         curr_order = FOTA_Package_Ctrl.m_fota_pkg_list[FOTA_Package_Ctrl.m_fota_pkg_index].m_pkg_block_order;
         FOTA_Package_Ctrl.m_fota_pkg_list[FOTA_Package_Ctrl.m_fota_pkg_index].m_pkg_valid_pages = 
                                           pkg_info->m_pkg_valid_pages;
         FOTA_Package_Ctrl.m_fota_pkg_list[FOTA_Package_Ctrl.m_fota_pkg_index].m_pkg_block_complete = 
                                           KAL_TRUE;
      }
      while(1)
      {
         /* allocate new package block */
         result = FUE_NFB_Allocate_PackageBlock(&FOTA_Package_Ctrl, curr_blk, &alloc_block, fue_dbg_print);
         if(ERROR_FUE_NONE == result)
         {
            status = fgal->erase_block(alloc_block);
            if(ERROR_FGAL_ERASE_FAILURE == status)
            {
               fgal->mark_bad(alloc_block);
               curr_blk = alloc_block;
               continue;
            }
            else if(ERROR_FGAL_NONE != status)
            {
               fue_dbg_print("FOTA_ProgramPackagePage: erase operation on block:%d error!\n\r", \
                              alloc_block);
               ret_code = ERROR_FOTA_FLASH_DEVICE;
               break;
            }
            /* create package block */
            result = FUE_NFB_Create_Package_Block(&FOTA_Package_Ctrl, alloc_block, \
                                                  pkg_info->m_pkg_current_block,\
                                                  INVALID_DWORD, KAL_TRUE, fue_dbg_print);
            if( (ERROR_FUE_INSUFFICIENT_BUFFER == result) || (ERROR_FUE_INVALID_PARAMETER == result) )
            {
               ret_code = ERROR_FOTA_INVALID_PARAMETER;
               break;
            }
            else if(ERROR_FUE_NONE == result)
            {
               status = fgal->write_page(buff, alloc_block, 1);
               if(ERROR_FGAL_NONE == status)
               {
                  /* program done, update RAM copy information */
                  FOTA_Package_Ctrl.m_fota_pkg_index++;
                  FOTA_Package_Ctrl.m_fota_pkg_pages++;
                  FOTA_Package_Ctrl.m_fota_pkg_list[FOTA_Package_Ctrl.m_fota_pkg_index].m_pkg_block_position = 
                  alloc_block;
                  FOTA_Package_Ctrl.m_fota_pkg_list[FOTA_Package_Ctrl.m_fota_pkg_index].m_pkg_block_order = 
                  curr_order+1;

                  pkg_info->m_pkg_previous_block = pkg_info->m_pkg_current_block;
                  pkg_info->m_pkg_current_block = alloc_block;
                  pkg_info->m_pkg_current_page = 2;
                  pkg_info->m_pkg_valid_pages = 1;
                  pkg_info->m_pkg_block_session++;
                  *page_size = info.Flash_page_size;

                  fue_dbg_print("FOTA_ProgramPackagePage: program on new package block:%d done!\n\r", \
                                 pkg_info->m_pkg_current_block);
                  break;
               }
            }
            //else if(ERROR_FUE_PROGRAM_FAILED == result)
            if( (ERROR_FUE_PROGRAM_FAILED == result) || (ERROR_FGAL_WRITE_FAILURE == status) )
            {
               /* create package block or program new page failed - try again */
               fgal->erase_block(alloc_block);
               fgal->mark_bad(alloc_block);
               curr_blk = alloc_block;
               continue;
            }
            else if(ERROR_FUE_OPERATION_STOP == result)
            {
               ret_code = ERROR_FOTA_FLASH_DEVICE;
               break;
            }
            else if(ERROR_FUE_OVER_DESIGN == result)
            {
               ret_code = ERROR_FOTA_UNSUPPORTED_CASES;
               break;
            }
         }
         else if(ERROR_FUE_NO_AVAILABLE_BLOCK == result)
         {
            ret_code = ERROR_FOTA_NO_AVAILABLE_BLOCK;
            break;
         }
      }
   }
   return ret_code;
}

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_ReadPackagePage
DESCRIPTION
   clear downloaded update package
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
        ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_ReadPackagePage(void* buff, kal_uint32 page_addr, kal_uint32 *page_size)
{
   kal_int32            ret_code     = ERROR_FOTA_SUCCESS;
   kal_uint32           page_count   = 0;
   kal_int32            left_pages   = 0;
   kal_uint32           blk_idx      = 0;
   kal_uint32           page_idx     = 0;
   kal_uint32           phy_blk      = 0;
   FOTA_Package_Info_st *pkg_info    = NULL;
   Logical_Flash_info_st info;
   FOTA_Package_Access_st *pkg_read  = &FOTA_Package_Ctrl.m_fota_curr_read;
   Flash_GAL_st          *fgal       = FOTA_Package_Ctrl.m_pkg_fgal;
   _FGAL_ERROR_CODE     status       = ERROR_FGAL_NONE;
   
   if(FOTA_UPDATE_PACKAGE_STATE != FOTA_Package_Ctrl.m_fota_pkg_state)
   {
      ASSERT(0);
      return ERROR_FOTA_NOT_INITIALIZED;
   }
   ASSERT(fgal);
   *page_size = 0;

   fgal     = FOTA_Package_Ctrl.m_pkg_fgal;
   pkg_info = &FOTA_Package_Ctrl.m_fota_pkg_info;
   fgal->query_info(&info);
   if( ((pkg_read->m_pkg_curr_addr+info.Flash_page_size) != page_addr) || (INVALID_DWORD == pkg_read->m_pkg_curr_addr))
   {
      page_idx = page_addr/info.Flash_page_size;
      for(blk_idx = 0 ; blk_idx <= FOTA_Package_Ctrl.m_fota_pkg_index ; blk_idx++)
      {
         phy_blk = FOTA_Package_Ctrl.m_fota_pkg_list[blk_idx].m_pkg_block_position;
         page_count = (fgal->block_size(phy_blk)/info.Flash_page_size) - 3;
         if(page_idx < page_count)
            break;
         else
            page_idx -= page_count;
      }
   }
   else
   {
      blk_idx = pkg_read->m_pkg_curr_blk;
      phy_blk = FOTA_Package_Ctrl.m_fota_pkg_list[blk_idx].m_pkg_block_position;
      page_count = (fgal->block_size(phy_blk)/info.Flash_page_size) - 3;
      if( (pkg_read->m_pkg_curr_page+1) == page_count)
      {
         /* advance to next block */
         blk_idx = pkg_read->m_pkg_curr_blk+1;
         page_idx = 0;
      }
      else
      {
         blk_idx = pkg_read->m_pkg_curr_blk;
         page_idx = pkg_read->m_pkg_curr_page+1;
      }
   }

   /* sanity check 
    * !CAUTION! all package blocks are assumed to have same size.
    */
   left_pages = FOTA_Package_Ctrl.m_fota_pkg_pages - blk_idx*page_count;
   if( (blk_idx > FOTA_Package_Ctrl.m_fota_pkg_index) ||
       ((blk_idx == FOTA_Package_Ctrl.m_fota_pkg_index) && ((page_idx+1) > left_pages)) )
   {
      fue_dbg_print("FOTA_ReadPackagePage: read over range:(%d,%d) > (%d,%d)!\n\r", \
                     blk_idx, page_idx, FOTA_Package_Ctrl.m_fota_pkg_index, pkg_info->m_pkg_valid_pages);
      ret_code = ERROR_FOTA_OVERRANGE;
      return ret_code;
   }
   else
   {
      pkg_read->m_pkg_curr_addr = page_addr;
      pkg_read->m_pkg_curr_blk = blk_idx;
      pkg_read->m_pkg_curr_page = page_idx;
      phy_blk = FOTA_Package_Ctrl.m_fota_pkg_list[blk_idx].m_pkg_block_position;
      status = fgal->read_page((kal_uint32 *)buff, phy_blk, page_idx+1);/* plus one to bypass header page */
      if(ERROR_FGAL_NONE == status)
      {
         //*page_size = FOTA_Package_Ctrl.m_fota_flash_info.Flash_page_size;
         *page_size = info.Flash_page_size;
      }
      else if(ERROR_FGAL_READ_FAILURE == status)
      {
         ret_code = ERROR_FOTA_READ;
      }
      else if(ERROR_FGAL_OPERATION_RETRY == status)
      {
         ret_code = ERROR_FOTA_UNSUPPORTED_CASES;
      }
      else if(ERROR_FGAL_INVALID_PARAMETER == status)
      {
         ret_code = ERROR_FOTA_INVALID_PARAMETER;
      }
   }

   return ret_code;
}

/* --------------------------------------------------------------------------------- */
static kal_int32 FOTA_MTD_Read_Buffer(void *Buffer, kal_uint32 read_len)
{
   kal_uint32 buff_offset       = 0;
   kal_int32 left_length        = read_len;
   kal_int32  result            = 0;
   kal_uint32 page_size         = 0;
   kal_uint32 buff_addr         = (kal_uint32)Buffer;

   while(left_length > 0)
   {
      result = FOTA_ReadPackagePage((void*)(buff_addr+buff_offset), FOTAData.SpareCurrReadAddr, \
                                    &page_size);

      if(ERROR_FOTA_SUCCESS == result)
      {
         buff_offset += page_size;
         left_length -= page_size;
         FOTAData.SpareCurrReadAddr += page_size;
      }
      else
         break;
   }
   return result;
}

/* --------------------------------------------------------------------------------- *
 * Update package download module
 * --------------------------------------------------------------------------------- */
/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_InitializePackageReservoir
DESCRIPTION
   find out whether any update record block exists
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_InitializePackageReservoir(void)
{
   kal_uint32               idx         = 0;
   kal_int32                ret_code    = ERROR_FOTA_SUCCESS;

   /* set package module control to default value */
   FOTA_Package_Ctrl.m_fota_pkg_info.m_pkg_block_session  = INVALID_DWORD;
   FOTA_Package_Ctrl.m_fota_pkg_info.m_pkg_previous_block = INVALID_DWORD;
   FOTA_Package_Ctrl.m_fota_pkg_info.m_pkg_current_block  = INVALID_DWORD;
   FOTA_Package_Ctrl.m_fota_pkg_info.m_pkg_valid_pages    = INVALID_DWORD;
   FOTA_Package_Ctrl.m_fota_pkg_info.m_pkg_current_page   = INVALID_DWORD;

   FOTA_Package_Ctrl.m_fota_pkg_index                     = INVALID_DWORD;
   FOTA_Package_Ctrl.m_fota_pkg_pages                     = 0;

   FOTA_Package_Ctrl.m_fota_curr_read.m_pkg_curr_addr = INVALID_DWORD;
   FOTA_Package_Ctrl.m_fota_curr_read.m_pkg_curr_blk = INVALID_DWORD;
   FOTA_Package_Ctrl.m_fota_curr_read.m_pkg_curr_page = INVALID_DWORD;

   for(idx = 0 ; idx < FOTA_PKG_BLOCKS ; idx++)
   {
      FOTA_Package_Ctrl.m_fota_pkg_list[idx].m_pkg_block_order = INVALID_DWORD;
      FOTA_Package_Ctrl.m_fota_pkg_list[idx].m_pkg_block_position = INVALID_DWORD;
      FOTA_Package_Ctrl.m_fota_pkg_list[idx].m_pkg_valid_pages = INVALID_DWORD;
      FOTA_Package_Ctrl.m_fota_pkg_list[idx].m_pkg_block_complete = KAL_FALSE;
   }

   /* initialize FGAL driver */
   FOTA_Package_Ctrl.m_pkg_fgal = FOTA_Setup_FGAL();

   /* get initial reserved area information */
   FOTA_Package_Ctrl.m_fota_pkg_area.FOTA_pkg_area_base = FOTA_NFB_Area_Info.m_fota_pkg_area.m_pkg_area_start;
   FOTA_Package_Ctrl.m_fota_pkg_area.FOTA_pkg_area_end = FOTA_NFB_Area_Info.m_fota_pkg_area.m_pkg_area_end;

   /* get flash information */
   //FOTA_Package_Ctrl.m_pkg_fgal->query_info(&FOTA_Package_Ctrl.m_fota_flash_info);

   FOTA_Package_Ctrl.m_fota_pkg_state = FOTA_UPDATE_PACKAGE_STATE;

   return ret_code;
}

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_ResumeUpdatePackage
DESCRIPTION
   find out whether any valid update package blocks exist
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_ResumeUpdatePackage(void)
{
   kal_uint32               pkg_blocks  = INVALID_DWORD;
   kal_uint32               buff_len    = FOTA_FLASH_MAX_PAGE_SIZE;
   kal_uint32               idx         = 0;
   kal_uint32               start_idx   = INVALID_DWORD;
   kal_uint32               blk_order   = 0;
   FUE_ERROR_CODE           result      = ERROR_FUE_NONE;
   kal_int32                ret_code    = ERROR_FOTA_SUCCESS;
   kal_uint32               pkg_pages   = 0;
   FOTA_Package_List_st     *pkg_list   = NULL;
   Logical_Flash_info_st    info;
   Flash_GAL_st             *fgal       = FOTA_Package_Ctrl.m_pkg_fgal;

   if(FOTA_UPDATE_PACKAGE_STATE != FOTA_Package_Ctrl.m_fota_pkg_state)
   {
      ret_code = ERROR_FOTA_NOT_INITIALIZED;
      return ret_code;
   }

   /* try to resume interrupted download process */
   /* update current package state to RAM copy   */
   result = FUE_BlkInfo_Resume_Package_Blocks(&FOTA_Package_Ctrl, &pkg_blocks, g_fota_package_blocks,
                                              fota_temp_page_buffer, &buff_len,
                                              fue_dbg_print);
   if(ERROR_FUE_NONE == result)
   {
      if( pkg_blocks )
      {
         /* get first element index */
         for(idx = 0 ; idx < FOTA_PKG_BLOCKS ; idx++)
         {
            if( INVALID_DWORD == g_fota_package_blocks[idx].m_pkg_prev_idx )
            {
               if( INVALID_DWORD != g_fota_package_blocks[idx].m_pkg_block_order )
               {
                  start_idx = idx;
                  break;
               }
            }
         }
         #ifdef _FUE_PKG_DEBUG_
         if( INVALID_DWORD == start_idx )
         {
            fue_dbg_print("FOTA_ResumeUpdatePackage: first valid block not found in %d blocks!\n\r", pkg_blocks);
            #if defined(__FOTA_DEBUG_ASSERT__)
            ASSERT(0);
            #endif /* __FOTA_DEBUG_ASSERT__ */
         }
         #endif

         pkg_list = FOTA_Package_Ctrl.m_fota_pkg_list;
         while(blk_order < pkg_blocks)
         {
            idx = start_idx;
            while(1)
            {
               if(blk_order == g_fota_package_blocks[idx].m_pkg_block_order)
               {
                  pkg_list[blk_order].m_pkg_block_order = g_fota_package_blocks[idx].m_pkg_block_order;
                  pkg_list[blk_order].m_pkg_block_position = g_fota_package_blocks[idx].m_pkg_block_position;
                  pkg_list[blk_order].m_pkg_valid_pages = g_fota_package_blocks[idx].m_pkg_valid_pages;
                  pkg_list[blk_order].m_pkg_block_complete = g_fota_package_blocks[idx].m_pkg_block_complete;
                  pkg_pages += pkg_list[blk_order].m_pkg_valid_pages;
                  if( (INVALID_DWORD == pkg_list[blk_order].m_pkg_valid_pages) ||
                      (0 == pkg_list[blk_order].m_pkg_valid_pages) )
                  {
                     #ifdef _FUE_PKG_DEBUG_
                     fue_dbg_print("FOTA_ResumeUpdatePackage: resume operation failed on %dth blk:%d\n\r", \
                                   blk_order, pkg_list[blk_order].m_pkg_block_position);
                     #endif /* _FUE_PKG_DEBUG_ */
                     #if defined(__FOTA_DEBUG_ASSERT__)
                     ASSERT(0);
                     #endif /* __FOTA_DEBUG_ASSERT__ */
                  }
                  blk_order++;
                  break;
                  /*TODO: remove this element from g_fota_package_blocks to save searching time */
               }
               idx = g_fota_package_blocks[idx].m_pkg_next_idx;
               if(INVALID_DWORD == idx)
               {
                  #ifdef _FUE_PKG_DEBUG_
                  fue_dbg_print("FOTA_ResumeUpdatePackage: downloading sequence is lost!(%d,%d)\n\r", \
                                blk_order, pkg_blocks);
                  #if defined(__FOTA_DEBUG_ASSERT__)
                  ASSERT(0);
                  #endif /* __FOTA_DEBUG_ASSERT__ */
                  #endif /* _FUE_PKG_DEBUG_ */
                  /* package block order is lost, re-download package from the beggining  */
                  ret_code = ERROR_FOTA_NO_UPDATE_PACKAGE;
                  break;
               }
            }
         }

         #ifdef _FUE_PKG_DEBUG_
         #if 0 /* removed since we do not update m_fota_pkg_info during FUE_BlkInfo_Resume_Package_Blocks() */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
         #endif /* removed */
         #endif
         if(INVALID_DWORD != FOTA_Package_Ctrl.m_fota_pkg_list[blk_order-1].m_pkg_block_position)
         {
            FOTA_Package_Ctrl.m_fota_pkg_info.m_pkg_current_block = 
               FOTA_Package_Ctrl.m_fota_pkg_list[blk_order-1].m_pkg_block_position;
            if(pkg_list[blk_order-1].m_pkg_block_complete)
            {
               fgal->query_info(&info);
               FOTA_Package_Ctrl.m_fota_pkg_info.m_pkg_current_page = 
               fgal->block_size(FOTA_Package_Ctrl.m_fota_pkg_info.m_pkg_current_block)/info.Flash_page_size;
            }
            else
            {
            FOTA_Package_Ctrl.m_fota_pkg_info.m_pkg_current_page = pkg_list[blk_order-1].m_pkg_valid_pages+1;
            }

            FOTA_Package_Ctrl.m_fota_pkg_info.m_pkg_valid_pages = pkg_list[blk_order-1].m_pkg_valid_pages;
            FOTA_Package_Ctrl.m_fota_pkg_info.m_pkg_block_session = blk_order-1;
            FOTA_Package_Ctrl.m_fota_pkg_info.m_pkg_previous_block = (blk_order > 1) ? 
               FOTA_Package_Ctrl.m_fota_pkg_list[blk_order-2].m_pkg_block_position : INVALID_DWORD;
         }
         FOTA_Package_Ctrl.m_fota_pkg_index = blk_order-1;
         FOTA_Package_Ctrl.m_fota_pkg_blocks = pkg_blocks;
         FOTA_Package_Ctrl.m_fota_pkg_pages = pkg_pages;

         //FOTA_Package_Ctrl.m_fota_pkg_info.m_pkg_valid_pages = ;
         if(pkg_blocks != blk_order)
         {
            #ifdef _FUE_PKG_DEBUG_
            fue_dbg_print("FOTA_ResumeUpdatePackage: blk number:%d <-> blk order:%d!\n\r", \
                          pkg_blocks, blk_order);
            #endif /* _FUE_PKG_DEBUG_ */
            #if defined(__FOTA_DEBUG_ASSERT__)
            ASSERT(0);
            #endif /* __FOTA_DEBUG_ASSERT__ */
            ret_code = ERROR_FOTA_NO_UPDATE_PACKAGE;
         }
         #ifdef _FUE_PKG_DEBUG_
         fue_dbg_print("FOTA_ResumeUpdatePackage: %dth package blk:%d!\n\r",
                        FOTA_Package_Ctrl.m_fota_pkg_info.m_pkg_block_session, \
                        FOTA_Package_Ctrl.m_fota_pkg_info.m_pkg_current_block);
         #endif
      }
      else
      {
         ret_code = ERROR_FOTA_NO_UPDATE_PACKAGE;
      }
   }
   else if((ERROR_FUE_INSUFFICIENT_BUFFER == result) || (ERROR_FUE_INVALID_PARAMETER == result))
   {
      ret_code = ERROR_FOTA_INVALID_PARAMETER;
      FOTA_Package_Ctrl.m_fota_pkg_state = INVALID_DWORD;
   }
   else if( (ERROR_FUE_NOT_FOUND == result) || (ERROR_FUE_TOO_MANY_PACKAGE_BLOCKS == result) )
   {
      ret_code = ERROR_FOTA_NO_UPDATE_PACKAGE;
   }
   else if( (ERROR_FUE_OPERATION_STOP == result) || (ERROR_FUE_READ_FAILURE == result) )
   {
      ret_code = ERROR_FOTA_UNSUPPORTED_CASES;
   }

   return ret_code;
}
/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_CheckAvailablePackageBlocks
DESCRIPTION
   scan all block in package reservoir area to estimate the available storage size
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_CheckAvailablePackageBlocks(kal_uint32 *available_num)
{
   kal_int32  ret_code       = ERROR_FOTA_SUCCESS;
   kal_uint32 base_blk       = INVALID_DWORD;
   kal_uint32 end_blk        = INVALID_DWORD;
   kal_uint32 blk_idx        = 0;
   kal_uint32 blk_num        = 0;
   _FGAL_ERROR_CODE   status = ERROR_FGAL_NONE;
   Flash_GAL_st  *fgal  = NULL;
   //Logical_Flash_info_st  info;

   if(FOTA_UPDATE_PACKAGE_STATE != FOTA_Package_Ctrl.m_fota_pkg_state)
   {
      ASSERT(0);
      return ERROR_FOTA_NOT_INITIALIZED;
   }

   base_blk = FOTA_Package_Ctrl.m_fota_pkg_area.FOTA_pkg_area_base;
   end_blk  = FOTA_Package_Ctrl.m_fota_pkg_area.FOTA_pkg_area_end;

   fgal = FOTA_Package_Ctrl.m_pkg_fgal;

   //fgal->query_info(&info);
   *available_num = 0;

   for(blk_idx = base_blk ; blk_idx < (end_blk+1) ; blk_idx++)
   {
      status = fgal->check_block(blk_idx);
      if(ERROR_FGAL_NONE == status)
      {
         /* check whether it is occupied */
         if(FUE_NFB_Is_Available_Block(blk_idx, fota_temp_page_buffer, fgal, fue_dbg_print))
         {
            blk_num++;
         }
      }
      else if(ERROR_FGAL_READ_FAILURE == status)
      {
         ret_code = ERROR_FOTA_READ;
         break;
      }
      else if(ERROR_FGAL_OPERATION_RETRY == status)
      {
         ret_code = ERROR_FOTA_FLASH_DEVICE;
         break;
      }
   }
   if(blk_idx == (end_blk+1))
      *available_num = blk_num;

   return ret_code;
}

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_ClearPackageReservoir
DESCRIPTION
   clear downloaded update package
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
        ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_ClearPackageReservoir(void)
{
   kal_int32  ret_code         = ERROR_FOTA_SUCCESS;
   kal_uint32 base_blk         = INVALID_DWORD;
   kal_uint32 end_blk          = INVALID_DWORD;
   kal_uint32 index            = 0;
   kal_uint32 blk_idx          = 0;
   kal_uint32 erase_round      = 0;
   kal_uint32 pkg_num          = FOTA_PKG_BLOCKS;
   kal_uint32 erased_blk       = 0;
   FUE_ERROR_CODE  result      = ERROR_FUE_NOT_FOUND;
   _FGAL_ERROR_CODE       status   = ERROR_FGAL_NONE;
   Flash_GAL_st           *fgal    = NULL;

   if(FOTA_UPDATE_PACKAGE_STATE != FOTA_Package_Ctrl.m_fota_pkg_state)
   {
      return ERROR_FOTA_NOT_INITIALIZED;
   }

   base_blk = FOTA_Package_Ctrl.m_fota_pkg_area.FOTA_pkg_area_base;
   end_blk  = FOTA_Package_Ctrl.m_fota_pkg_area.FOTA_pkg_area_end;

   fgal = FOTA_Package_Ctrl.m_pkg_fgal;

   /* try to erase all blocks occupied by update package */
   for( blk_idx = base_blk ; blk_idx <= end_blk ; blk_idx++ )
   {
       status = fgal->check_block(blk_idx);
       if(ERROR_FGAL_NONE == status)
       {
           result = FUE_BlkInfo_Is_Update_Block(&FOTA_Update_Ctrl, blk_idx, fue_dbg_print);
           if(ERROR_FUE_NOT_FOUND == result) /* in this flash space, only package or update blocks exist */
           {
               /* erase block */
               status = fgal->erase_block(blk_idx);
               if(ERROR_FGAL_ERASE_FAILURE == status)
               {
                   fgal->mark_bad(blk_idx);
                   #ifdef _FUE_PKG_DEBUG_
                   fue_dbg_print("FOTA_ClearPackageReservoir: erase failed on block:%d!\n\r", blk_idx);
                   #endif
               }
               else if(ERROR_FGAL_OPERATION_RETRY == status)
               {
                   #ifdef _FUE_PKG_DEBUG_
                   fue_dbg_print("FOTA_ClearPackageReservoir: erase operation stopped on block:%d!\n\r", blk_idx);
                   #endif
                   ret_code = ERROR_FOTA_FLASH_DEVICE;
                   break;
               }
               erased_blk++;
           }
           else if( (ERROR_FUE_OPERATION_STOP == result) || (ERROR_FUE_OVER_DESIGN == result) )
           {
               #ifdef _FUE_PKG_DEBUG_
               fue_dbg_print("FOTA_ClearPackageReservoir: read operation stopped on block:%d!\n\r", blk_idx);
               #endif
               ret_code = ERROR_FOTA_FLASH_DEVICE;
               break;
           }
           else if(ERROR_FUE_NONE == result)
           {
               continue;
           }
           else
           {
               #ifdef _FUE_PKG_DEBUG_
               fue_dbg_print("FOTA_ClearPackageReservoir: unexpected error on block:%d!\n\r", blk_idx);
               #endif
               ret_code = ERROR_FOTA_UNSUPPORTED_CASES;
               break;
           }
       }
       else if(ERROR_FGAL_READ_FAILURE == status)
       {
           ret_code = ERROR_FOTA_READ;
           break;
       }
       else if(ERROR_FGAL_OPERATION_RETRY == status)
       {
           ret_code = ERROR_FOTA_FLASH_DEVICE;
           break;
       }
   }
   #ifdef _FUE_PKG_DEBUG_
   fue_dbg_print("FOTA_ClearPackageReservoir: clear %d in %d blocks!\n\r", erased_blk, blk_idx-base_blk);
   #endif
   return ret_code;
}

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_Get_TotalPackageBlock
DESCRIPTION
   return current package block number
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_Get_TotalPackageBlock(kal_uint32 *pkg_blks, kal_uint32* pkg_pages)
{
   if(FOTA_UPDATE_PACKAGE_STATE != FOTA_Package_Ctrl.m_fota_pkg_state)
   {
      ASSERT(0);
      return ERROR_FOTA_NOT_INITIALIZED;
   }

   if(INVALID_DWORD != FOTA_Package_Ctrl.m_fota_pkg_info.m_pkg_valid_pages)
   {
      *pkg_blks = FOTA_Package_Ctrl.m_fota_pkg_blocks-1;
      *pkg_pages = FOTA_Package_Ctrl.m_fota_pkg_info.m_pkg_valid_pages;
   }
   else
   {
      *pkg_blks = FOTA_Package_Ctrl.m_fota_pkg_blocks;
      *pkg_pages = 0;
   }
   
   return ERROR_FOTA_SUCCESS;
}

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_Get_CurrentPackagePosition
DESCRIPTION
   return current package block position
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_Get_CurrentPackagePosition(kal_uint32 *curr_blk, kal_uint32* curr_page)
{
   if(FOTA_UPDATE_PACKAGE_STATE != FOTA_Package_Ctrl.m_fota_pkg_state)
   {
      ASSERT(0);
      return ERROR_FOTA_NOT_INITIALIZED;
   }

   *curr_blk = FOTA_Package_Ctrl.m_fota_pkg_info.m_pkg_current_block;
   *curr_page = FOTA_Package_Ctrl.m_fota_pkg_info.m_pkg_current_page;
   
   return ERROR_FOTA_SUCCESS;
}

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_Get_AvailablePackageSpace
DESCRIPTION
   return currently downloaded package size
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_Get_AvailablePackageSpace(kal_uint32 *avail_size)
{
   Logical_Flash_info_st   info;
   kal_int32               ret_code  = ERROR_FOTA_SUCCESS;
   kal_uint32              page_size;
   kal_uint32              blk_idx   = 0;
   kal_uint32              start_blk = 0;
   kal_uint32              end_blk   = 0;
   kal_uint32              free_size = 0;
   _FGAL_ERROR_CODE        status    = ERROR_FGAL_NONE;
   Flash_GAL_st            *fgal     = NULL;

   if(FOTA_UPDATE_PACKAGE_STATE != FOTA_Package_Ctrl.m_fota_pkg_state)
   {
      ASSERT(0);
      return ERROR_FOTA_NOT_INITIALIZED;
   }

   fgal = FOTA_Package_Ctrl.m_pkg_fgal;

   fgal->query_info(&info);
   page_size = info.Flash_page_size;
   start_blk = FOTA_Package_Ctrl.m_fota_pkg_area.FOTA_pkg_area_base;
   end_blk  = FOTA_Package_Ctrl.m_fota_pkg_area.FOTA_pkg_area_end;

   /* try to erase all blocks occupied by update package */
   for( blk_idx = start_blk ; blk_idx <= end_blk ; blk_idx++ )
   {
      status = fgal->check_block(blk_idx);
      if(ERROR_FGAL_NONE == status)
      {
         /* check whether it is occupied */
         if( FUE_NFB_Is_Available_Block(blk_idx, fota_temp_page_buffer, fgal, fue_dbg_print) ||
         	   FUE_BlkInfo_Is_Package_Block(&FOTA_Package_Ctrl, blk_idx, fue_dbg_print) )
         {
            free_size += fgal->block_size(blk_idx)-3*page_size;/* header and end mark pages are reserved */
         }
      }
      else if(ERROR_FGAL_READ_FAILURE == status)
      {
         ret_code = ERROR_FOTA_READ;
         break;
      }
      else if(ERROR_FGAL_OPERATION_RETRY == status)
      {
         ret_code = ERROR_FOTA_FLASH_DEVICE;
         break;
      }
   }

   FOTA_Get_CurrentPackagePosition(&start_blk, &end_blk);
   if(INVALID_DWORD != start_blk)
   {
      /* header, end mark and current valid pages are excluded */
      free_size += fgal->block_size(start_blk)-(end_blk+3)*page_size; 
   }

   *avail_size = free_size;

   return ret_code;
}

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_Get_TotalPackageSpace
DESCRIPTION
   return currently downloaded package size
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_Get_TotalPackageSpace(kal_uint32 *avail_size)
{
   Logical_Flash_info_st   info;
   kal_int32               ret_code  = ERROR_FOTA_SUCCESS;
   kal_uint32              page_size;
   kal_uint32              blk_idx   = 0;
   kal_uint32              start_blk = 0;
   kal_uint32              end_blk   = 0;
   kal_uint32              free_size = 0;
   _FGAL_ERROR_CODE        status    = ERROR_FGAL_NONE;
   Flash_GAL_st            *fgal     = NULL;

   if(FOTA_UPDATE_PACKAGE_STATE != FOTA_Package_Ctrl.m_fota_pkg_state)
   {
      ASSERT(0);
      return ERROR_FOTA_NOT_INITIALIZED;
   }

   fgal = FOTA_Package_Ctrl.m_pkg_fgal;

   fgal->query_info(&info);
   page_size = info.Flash_page_size;
   start_blk = FOTA_Package_Ctrl.m_fota_pkg_area.FOTA_pkg_area_base;
   end_blk  = FOTA_Package_Ctrl.m_fota_pkg_area.FOTA_pkg_area_end;

   /* try to erase all blocks occupied by update package */
   for( blk_idx = start_blk ; blk_idx <= end_blk ; blk_idx++ )
   {
      status = fgal->check_block(blk_idx);
      if(ERROR_FGAL_NONE == status)
      {
         /* check whether it is occupied */
         if( (ERROR_FUE_NONE == FUE_NFB_Is_Available_Block(blk_idx, fota_temp_page_buffer, fgal, fue_dbg_print)) ||
             (ERROR_FUE_NONE == FUE_BlkInfo_Is_Package_Block(&FOTA_Package_Ctrl, blk_idx, fue_dbg_print)) )
         {
            free_size += fgal->block_size(blk_idx)-3*page_size;/* header and end mark pages are reserved */
         }
      }
      else if(ERROR_FGAL_READ_FAILURE == status)
      {
         ret_code = ERROR_FOTA_READ;
         break;
      }
      else if(ERROR_FGAL_OPERATION_RETRY == status)
      {
         ret_code = ERROR_FOTA_FLASH_DEVICE;
         break;
      }
   }

   /* one block is reserved for update state record replacement */
   *avail_size = free_size-(fgal->block_size(start_blk)-3*page_size);/* header and end mark pages are reserved */

   return ret_code;
}

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_Get_DownloadedPackageSize
DESCRIPTION
   return currently downloaded package size
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_Get_DownloadedPackageSize(kal_uint32 *curr_size)
{
   Logical_Flash_info_st   info;
   if(FOTA_UPDATE_PACKAGE_STATE != FOTA_Package_Ctrl.m_fota_pkg_state)
   {
      ASSERT(0);
      return ERROR_FOTA_NOT_INITIALIZED;
   }

   FOTA_Package_Ctrl.m_pkg_fgal->query_info(&info);
   if(INVALID_DWORD != FOTA_Package_Ctrl.m_fota_pkg_pages)
      *curr_size = FOTA_Package_Ctrl.m_fota_pkg_pages*info.Flash_page_size;
   else
       *curr_size = 0;
  
   return ERROR_FOTA_SUCCESS;
}

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
#endif
/* --------------------------------------------------------------------------------- *
 * Update staus record control module
 * --------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_InitializeUpdateRecord
DESCRIPTION
   create an update record block or find out the existing update record block 
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_InitializeUpdateRecord(void)
{
   kal_uint32              start_block = INVALID_DWORD;
   kal_uint32              end_block   = INVALID_DWORD;
   FUE_ERROR_CODE          result      = ERROR_FUE_NONE;
   _FGAL_ERROR_CODE        status      = ERROR_FGAL_NONE;

   /* initialize FGAL driver */
   FOTA_Update_Ctrl.m_update_fgal = FOTA_Setup_FGAL();

   /* get initial reserved area information */
   start_block = FOTA_NFB_Area_Info.m_fota_pkg_area.m_pkg_area_start;
   end_block = FOTA_NFB_Area_Info.m_fota_pkg_area.m_pkg_area_end;
   //FOTA_Update_Ctrl.m_update_fgal->query_info(&FOTA_Update_Ctrl.m_nand_flash_info);

   /* set up update record module */
   result = FUE_InitializeUpdateRecord(start_block, end_block, \
                                       FOTA_Update_Ctrl.m_update_fgal/*&FOTA_Nand_Fgal*/,\
                                       fue_dbg_print);
   if(ERROR_FUE_NO_AVAILABLE_BLOCK == result)
   {
      status = ERROR_FOTA_NO_AVAILABLE_BLOCK;
   }
   else if(ERROR_FUE_OPERATION_STOP == result)
   {
      status = ERROR_FOTA_FLASH_DEVICE;
   }
   else if(ERROR_FUE_OVER_DESIGN == result)
   {
      status = ERROR_FOTA_UNSUPPORTED_CASES;
   }
   else
   {
      FOTA_Update_Ctrl.FOTA_UPDATE_ID = UPDATE_STATE_RECORD_ID;
   }

   return status;
}

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_WriteUpdateRecord
DESCRIPTION
   FOTA update state information write API
   download client and update agent use this information to communicate with each other
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_WriteUpdateRecord(FOTA_Custom_Update_Info* record)
{
   kal_int32 ret            = ERROR_FOTA_SUCCESS;
   FUE_ERROR_CODE  result   = ERROR_FUE_NONE;

   /* check whether FOTA is initialized */
   if(UPDATE_STATE_RECORD_ID != FOTA_Update_Ctrl.FOTA_UPDATE_ID)
   {
      ret = ERROR_FOTA_NOT_INITIALIZED;
   }
   else
   {
      result = FUE_NFB_Flush_Update_Record(record, fue_dbg_print);

      if(ERROR_FUE_NONE == result )
      {
         ret = ERROR_FOTA_SUCCESS;
      }
      else if(ERROR_FUE_OPERATION_STOP == result)
      {
         #ifdef FOTA_DEBUG
         ASSERT(0);
         #endif
         ret = ERROR_FOTA_FLASH_DEVICE;
      }
   }
   return ret;
}

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_ReadUpdateRecord
DESCRIPTION
   FOTA update state information read API
   download client and update agent use this information to communicate with each other
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_ReadUpdateRecord(FOTA_Custom_Update_Info* record)
{
   kal_int32       ret     = ERROR_FOTA_SUCCESS;
   FUE_ERROR_CODE  result  = ERROR_FUE_NONE;

   /* check whether FOTA is initialized */
   if(UPDATE_STATE_RECORD_ID != FOTA_Update_Ctrl.FOTA_UPDATE_ID)
   {
      ret = ERROR_FOTA_NOT_INITIALIZED;
   }
   else
   {
      result = FUE_NFB_Get_Update_Record(record, fue_dbg_print);

      if(ERROR_FUE_UNRECOVERABLE_ECC == result)
      {
         ret = ERROR_FOTA_READ;
      }
      else if(ERROR_FUE_OPERATION_STOP == result)
      {
        ret = ERROR_FOTA_FLASH_DEVICE;
      }
   }
   return ret;
}

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_Inform_Update_State
DESCRIPTION
   Download client use this function to query the result of update process
PARAMETER
   NULL
RETURN
--------------------------------------------------------------------------------- */
FOTA_update_result  FOTA_Inform_Update_State(void)
{
   FOTA_update_result  ret     = FOTA_UPDATE_NONE;
   FUE_ERROR_CODE      result  = ERROR_FUE_NONE;
   FOTA_Custom_Update_Info   upt_info;

   /* check whether FOTA is initialized */
   if(UPDATE_STATE_RECORD_ID != FOTA_Update_Ctrl.FOTA_UPDATE_ID)
   {
      ret = FOTA_UPDATE_NONE;
   }
   else
   {
      result = FOTA_ReadUpdateRecord(&upt_info);

      if(ERROR_FUE_NONE == result)
      {
         /* check customer's state */
         if( FUE_UA_COMPLETE_PHASE == upt_info.FOTA_test_info1 )
         {
            ret = FOTA_UPDATE_SUCCEEDED;
         }
         else
         {
#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            {
               ret = FOTA_UPDATE_FAILED;
            }
         }
      }
      else
      {
         ret = FOTA_UPDATE_NONE;
      }
   }
   
   return ret;
}

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_Start_Download_State
DESCRIPTION
   Download client use this function to query the result of update process
PARAMETER
   NULL
RETURN
--------------------------------------------------------------------------------- */
kal_int32 FOTA_Start_Download_State(void)
{
   kal_int32           ret     = ERROR_FOTA_SUCCESS;
   FOTA_Custom_Update_Info   upt_info;

   if(UPDATE_STATE_RECORD_ID != FOTA_Update_Ctrl.FOTA_UPDATE_ID)
   {
      ret = ERROR_FOTA_NOT_INITIALIZED;
   }
   else
   {
      kal_mem_set(&upt_info,0xff,sizeof(FOTA_Custom_Update_Info));
      FUE_Start_Download_State();
      ret = FOTA_WriteUpdateRecord(&upt_info);
   }

   return ret;
}

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_Start_Update_State
DESCRIPTION
   Download client use this function to query the result of update process
PARAMETER
   NULL
RETURN
--------------------------------------------------------------------------------- */
kal_int32 FOTA_Start_Update_State(void)
{
   kal_int32           ret     = ERROR_FOTA_SUCCESS;
   FOTA_Custom_Update_Info   upt_info;

   if(UPDATE_STATE_RECORD_ID != FOTA_Update_Ctrl.FOTA_UPDATE_ID)
   {
      ret = ERROR_FOTA_NOT_INITIALIZED;
   }
   else
   {
      kal_mem_set(&upt_info,0xff,sizeof(FOTA_Custom_Update_Info));
      FUE_Start_Package_Verification_State();
      ret = FOTA_WriteUpdateRecord(&upt_info);
   }

   return ret;
}


/* --------------------------------------------------------------------------------- *
 * Flash Generic Access Layer 
 * --------------------------------------------------------------------------------- */
#define FOTA_FGAL_READY   (0x59445246)
kal_uint32 g_FOTA_fgal_state;

#if defined(_NAND_FLASH_BOOTING_) || (defined(__UP_PKG_ON_NAND__) && defined(NAND_SUPPORT))

#if !defined(__NAND_FDM_50__)
#include "NAND_FDM.h"
#include "nand_mtd.h"
#include "nand_mtd_internal.h"
#else
#include "NAND_MTD_FDM50.h"
#include "NAND_DAL.h"
#include "NAND_MTD_FDM50_internal.h"
#include "NAND_DAL_internal.h"

extern kal_uint8 IsGoodBlock(void* D, void * Spare);
#endif /* !__NAND_FDM_50__ */

/* Following functions and variables are located in NAND_MTD.c */
extern int NFB_ReadPhysicalPage(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data);
extern int NFB_ReadPhysicalSpare(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data, kal_bool chksum);
extern int NFB_ProgramPhysicalPage(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data, kal_bool DALRemap);
extern int NFB_ProgramPhysicalSpare(kal_uint32 PhyBlock, kal_uint32 PhyPage, void * Data, kal_bool chksum, kal_bool DALRemap);
extern int NFB_ErasePhysicalBlock(kal_uint32 PhyBlock, kal_bool DALRemap);
extern void get_NFI_bus(void);
extern void free_NFI_bus(void);

extern int NFBPageSize;
extern int NFBBlockSize;

#if defined(__NAND_FDM_50__)

extern flash_info_2 Flash_Info;

#else /* NAND FDM 4.x */

extern NAND_FLASH_DRV_DATA  NANDFlashDriveData;

#endif

/* Forward declaration */
_FGAL_ERROR_CODE FOTA_NAND_Init_func(void);
_FGAL_ERROR_CODE FOTA_NAND_Page_Read_func(kal_uint32* ptr, kal_uint32 blk, kal_uint32 page);
_FGAL_ERROR_CODE FOTA_NAND_Query_Info_func(Logical_Flash_info_st* info);
_FGAL_ERROR_CODE FOTA_NAND_Page_Program_func(kal_uint32* ptr, kal_uint32 blk, kal_uint32 page);
_FGAL_ERROR_CODE FOTA_NAND_Is_Good_Block_func(kal_uint32 blk);
_FGAL_ERROR_CODE FOTA_NAND_Mark_Bad_Block_func(kal_uint32 blk);
_FGAL_ERROR_CODE FOTA_NAND_Erase_Block_func(kal_uint32 blk);
_FGAL_ERROR_CODE FOTA_NAND_Is_Page_Empty_func(kal_uint32 *buff, kal_uint32 blk, kal_uint32 page);
_FGAL_ERROR_CODE FOTA_NAND_Lock_Block_func(kal_uint32 blk, kal_bool locked);
kal_uint32 FOTA_NAND_Block_Size_func(kal_uint32 blk);
kal_uint32 FOTA_NAND_Block_Index_func(kal_uint32 blk_addr);

/*
 * Macro definition
 */
#define FOTA_NAND_STATE_VALID   (0x5644544D)

#define FOTA_MAX_SPARE_SIZE      (64)

/*
 * Global variable definition
 */
kal_uint32 g_FOTA_NAND_MTD_STATE;

kal_uint32 g_fota_spare_buffer[FOTA_MAX_SPARE_SIZE>>2];

/* For flash generic access layer */
Flash_GAL_st          FOTA_Nand_Fgal;

/*****************************************************************
Description : wait for a specific period counted by 32Khz tick.
Input       : 
Output      : None
******************************************************************/
static void delay32KHzTick(kal_uint32 count)
{
	kal_uint32 begin_time = 0;
	kal_uint32 current_time = 0;
	
	begin_time = INT_GetCurrentTime();
	do
	{
	   current_time = INT_GetCurrentTime();
	   if(current_time > begin_time)
	   {
	      if( (current_time-begin_time) > count )
	         break;
	   }
	   else
	   {
	      if( (0xFFFFFFFF - begin_time + current_time + 1) > count)
	         break;
	   }
	}while(1);
}

/*****************************************************************
Description : set up FGAL structure.
Input       : 
Output      : None
******************************************************************/


Flash_GAL_st *FOTA_Setup_FGAL(void)
{
   if(FOTA_FGAL_READY == g_FOTA_fgal_state)
      return &FOTA_Nand_Fgal;

   /* set up FGAL */
   FOTA_Nand_Fgal.init_drv = FOTA_NAND_Init_func;
   FOTA_Nand_Fgal.query_info = FOTA_NAND_Query_Info_func;
   FOTA_Nand_Fgal.read_page = FOTA_NAND_Page_Read_func;
   FOTA_Nand_Fgal.write_page = FOTA_NAND_Page_Program_func;
   FOTA_Nand_Fgal.check_block = FOTA_NAND_Is_Good_Block_func;
   FOTA_Nand_Fgal.mark_bad = FOTA_NAND_Mark_Bad_Block_func;
   FOTA_Nand_Fgal.erase_block = FOTA_NAND_Erase_Block_func;
   FOTA_Nand_Fgal.check_empty_page = FOTA_NAND_Is_Page_Empty_func;
   FOTA_Nand_Fgal.block_size = FOTA_NAND_Block_Size_func;
   FOTA_Nand_Fgal.block_index = FOTA_NAND_Block_Index_func;
   FOTA_Nand_Fgal.lock_block = FOTA_NAND_Lock_Block_func;

   /* initialize FGAL driver */
   FOTA_Nand_Fgal.init_drv();

   g_FOTA_fgal_state = FOTA_FGAL_READY;
   return &FOTA_Nand_Fgal;
}

/*****************************************************************
Description : check whether the provided buffer comes from empty page.
Input       : 
Output      : None
******************************************************************/
kal_bool FOTA_NAND_MTD_Check_Page_Empty(kal_uint8* page_buffer, kal_uint8* spare_buffer)
{
   kal_uint32   spare_len  = 0;
   kal_uint32   idx = 0, j = 0;
   kal_uint32*  long_ptr   = NULL;
   kal_int32    byte_count = 0;
   kal_int32    long_len   = 0;
   kal_uint32   page_size  = NFBPageSize;

   switch(page_size)
   {
      case 4096:
         spare_len = 128;
      break;    
      case 2048:
         spare_len = 64;
      break;
      case 512:
         spare_len = 16;
      break;
      default:
         ASSERT(0);
   }
   /* compare with 0xFF */
   if(page_buffer)
   {
      long_ptr = (kal_uint32 *)(((kal_uint32)page_buffer+3) & ~(0x03));
      long_len = ((((kal_uint32)page_buffer+page_size) & ~(0x03)) - (kal_uint32)long_ptr) >> 2;
      byte_count = (kal_uint32)long_ptr - (kal_uint32)page_buffer;
      /* chech page content */
      if(byte_count > 0)
      {
         for(j = 0 ; j < byte_count ; j++)
         {
            if(page_buffer[j] != 0xFF)
               return KAL_FALSE;
         }
      }
      for(idx = 0 ; idx < long_len ; idx++)
      {
         if(long_ptr[idx] != 0xFFFFFFFF)
            return KAL_FALSE;
      }
      byte_count = page_size - byte_count - (long_len<<2);
      if(byte_count > 0)
      {
         for(j = byte_count ; j > 0 ; j--)
         {
            if(page_buffer[page_size-j] != 0xFF)
               return KAL_FALSE;
         }
      }
   }

   if(spare_buffer)
   {
      /* check spare content */
      long_ptr = (kal_uint32 *)(((kal_uint32)spare_buffer+3) & ~(0x03));
      long_len = ((((kal_uint32)spare_buffer+spare_len) & ~(0x03)) - (kal_uint32)long_ptr) >> 2;
      byte_count = (kal_uint32)long_ptr - (kal_uint32)spare_buffer;
      if(byte_count > 0)
      {
         for(j = 0 ; j < byte_count ; j++)
         {
            if(spare_buffer[j] != 0xFF)
               return KAL_FALSE;
         }
      }
      for(idx = 0 ; idx < long_len ; idx++)
      {
         if(long_ptr[idx] != 0xFFFFFFFF)
            return KAL_FALSE;
      }
      byte_count = spare_len - byte_count - (long_len<<2);
      if(byte_count > 0)
      {
         for(j = byte_count ; j > 0 ; j--)
         {
            if(spare_buffer[page_size-j] != 0xFF)
               return KAL_FALSE;
         }
      }
   }
   return KAL_TRUE;;
}

/*****************************************************************
Description : check whether the provided buffer comes from spare area of bad block.
Input       : 
Output      : None
******************************************************************/
void FOTA_NAND_MTD_Set_Spare_Bad_Mark(kal_uint8* spare_buffer)
{
   kal_uint8          *byte_ptr  = spare_buffer;
   kal_bool            word_flag = KAL_FALSE;
#if !defined(__NAND_FDM_50__)
   flash_info_struct  *nand_info = &NANDFlashDriveData.flash_info;

   if(IO_ACCESS_16BIT == nand_info->io_width)
   {
      word_flag = KAL_TRUE;
   }

#else

   if(Flash_Info.deviceInfo_CE[0].IOWidth == 16)
   {
      word_flag = KAL_TRUE;
   }

#endif /* __NAND_FDM_50__ */

   if(512 == NFBPageSize)
   {
      if(!word_flag)
      {
         byte_ptr[5] = 0x0B;
      }
      else
      {
         byte_ptr[0] = 0x0B;
         byte_ptr[10] = 0x0B;
      }
   }
   else if((2048 == NFBPageSize)||(4096 == NFBPageSize))
   {
      if(!word_flag)
      {
         byte_ptr[0] = 0x0B;
      }
      else
      {
         byte_ptr[0] = 0x0B;
         byte_ptr[1] = 0x0B;
      }
   }
}
/*************************************************************************
* FUNCTION
*  FOTA_NAND_Init_func
*
* DESCRIPTION
* Initialze NAND flash MTD driver
 ************************************************************************/
_FGAL_ERROR_CODE FOTA_NAND_Init_func(void)
{
   kal_int32   status = -1;

   status = NFB_ReadPhysicalPage(0xFFFFFFFF, 0xFFFFFFFF, NULL);

   g_FOTA_NAND_MTD_STATE = FOTA_NAND_STATE_VALID;

   #if defined(__NAND_FDM_50__)
   NFBPageSize = Flash_Info.pageSize;
   //NFBBlockSize = Flash_Info.pageSize*Flash_Info.blockPage;
   #endif /* __NAND_FDM_50__ */

   #if defined(__UP_PKG_ON_NAND__)
   FOTA_NFB_Area_Info.m_fota_pkg_area.m_pkg_area_start = FOTA_NAND_Block_Index_func(FOTA_PACKAGE_STORAGE_BASE);
   FOTA_NFB_Area_Info.m_fota_pkg_area.m_pkg_area_end = FOTA_NAND_Block_Index_func(FOTA_PACKAGE_STORAGE_BASE+FOTA_PACKAGE_STORAGE_SIZE)-1;
   #endif /* __UP_PKG_ON_NAND__ */

   return ERROR_FGAL_NONE;
}

/*************************************************************************
* FUNCTION
*  FOTA_NAND_Page_Read_func
*
* DESCRIPTION
* Read one page from NAND flash
 ************************************************************************/
_FGAL_ERROR_CODE FOTA_NAND_Page_Read_func(kal_uint32* ptr, kal_uint32 blk, kal_uint32 page)
{
   _FGAL_ERROR_CODE   result = ERROR_FGAL_NONE;
   kal_int32          status = 0;
   #if !defined(__NFI_VERSION2__) && !defined(__NFI_VERSION3_1__)
   static kal_uint32  empty_spare[64>>2];
   #endif /* !__NFI_VERSION2__ && !__NFI_VERSION3_1__*/

   ASSERT( FOTA_NAND_STATE_VALID == g_FOTA_NAND_MTD_STATE);

   status = NFB_ReadPhysicalPage(blk, page, ptr);

   switch(status)
   {
      case ERROR_NFB_BAD_BLOCK:
         result = ERROR_FGAL_BAD_BLOCK;
         /* should not happen */
         EXT_ASSERT(0, 0, 0, 0);
         break;
      case ERROR_NFB_READ:
         #if !defined(__NFI_VERSION2__) && !defined(__NFI_VERSION3_1__)
         /* empty page read will generate ECC failure on NFI version1 */
         kal_mem_set(empty_spare, 0xFF, 64);
         NFB_ReadPhysicalSpare(blk, page, empty_spare, KAL_FALSE);
         if(FOTA_NAND_MTD_Check_Page_Empty((kal_uint8 *)ptr, (kal_uint8 *)empty_spare))
         {
            result = ERROR_FGAL_NONE;
         }
         else
         {
            result = ERROR_FGAL_ECC_FAILURE;
         }
         #else /* __NFI_VERSION2__ || __NFI_VERSION3_1__*/
         result = ERROR_FGAL_ECC_FAILURE;
         #endif /* !__NFI_VERSION2__ && !__NFI_VERSION3_1__*/
         break;
      default:
         if(NFBPageSize == status)
            result = ERROR_FGAL_NONE;
         else
         {
            ASSERT(0);
            result = ERROR_FGAL_OPERATION_RETRY;
         }
   }
   
   return result;
}

/*************************************************************************
* FUNCTION
*  FOTA_NAND_Query_Info_func
*
* DESCRIPTION
* Query NAND flash device information
 ************************************************************************/
_FGAL_ERROR_CODE FOTA_NAND_Query_Info_func(Logical_Flash_info_st* info)
{
   _FGAL_ERROR_CODE   result      = ERROR_FGAL_NONE;
   kal_uint32         page_size   = 0;
   kal_uint32         offset      = 0;
   kal_uint32         pages_per_block = 0;
   kal_uint32         page_shift = 0;
#if !defined(__NAND_FDM_50__)
   flash_info_struct  *nand_info  = &NANDFlashDriveData.flash_info;
#endif /* __NAND_FDM_50__ */

   ASSERT( FOTA_NAND_STATE_VALID == g_FOTA_NAND_MTD_STATE);

#if defined(__NAND_FDM_50__)

   page_size = Flash_Info.pageSize;
   if(4096 == page_size)
   {
      page_shift = 12;
   }
   else if(2048 == page_size)
   {
      page_shift = 11;
   }
   else if(512 == page_size)
   {
      page_shift = 9;
   }
   else
   {
      /* incorrect device configuration */
      ASSERT(0);
   }

   pages_per_block = Flash_Info.blockPage;

   info->Flash_page_size = page_size;
   info->Flash_block_size = page_size*pages_per_block;
   info->Flash_io_width = Flash_Info.deviceInfo_CE[0].IOWidth;

#else /* NAND FDM 4 */

   if(PAGE_2K == nand_info->page_type)
   {
      page_size = 2048;
      page_shift = 11;
   }
   else if(PAGE_512 == nand_info->page_type)
   {
      page_size = 512;
      page_shift = 9;
   }
   else
   {
      /* incorrect device configuration */
      ASSERT(0);
   }

   pages_per_block = nand_info->pages_per_block;

   info->Flash_page_size = page_size;
   info->Flash_block_size = page_size*nand_info->pages_per_block;
   info->Flash_io_width = nand_info->io_width;

#endif

   /* Assumptions: pages per block is power of 2 */
   info->Flash_offset_shift = INVALID_DWORD;
   for( offset = 0 ; offset < 32 ; offset++)
   {
      if( (1 << offset) == pages_per_block )
      {
         info->Flash_offset_shift = offset;
         info->Flash_block_shift = offset+page_shift;
         break;
      }
   }
   if(INVALID_DWORD == info->Flash_offset_shift)
      ASSERT(0); /* incorrect device configuration */

   return result;
}

/*************************************************************************
* FUNCTION
*  FOTA_NAND_Page_Program_func
*
* DESCRIPTION
* Write one page to NAND flash
 ************************************************************************/
_FGAL_ERROR_CODE FOTA_NAND_Page_Program_func(kal_uint32* ptr, kal_uint32 blk, kal_uint32 page)
{
   _FGAL_ERROR_CODE   result = ERROR_FGAL_NONE;
   kal_int32          status = 0;

   ASSERT( FOTA_NAND_STATE_VALID == g_FOTA_NAND_MTD_STATE);

   status = NFB_ProgramPhysicalPage(blk, page, ptr, KAL_TRUE);

   switch(status)
   {
      case ERROR_NFB_BAD_BLOCK:
         result = ERROR_FGAL_BAD_BLOCK;
         /* should not happen */
         EXT_ASSERT(0, 0, 0, 0);
         break;
      case ERROR_NFB_PROGRAM:
         result = ERROR_FGAL_WRITE_FAILURE;
         break;
      default:
         if(NFBPageSize == status)
            result = ERROR_FGAL_NONE;
         else
         {
            ASSERT(0);
            result = ERROR_FGAL_OPERATION_RETRY;
         }
   }

   return result;
}

/*************************************************************************
* FUNCTION
*  FOTA_NAND_Is_Good_Block_func
*
* DESCRIPTION
* Check whether block is good or bad.
 ************************************************************************/
_FGAL_ERROR_CODE FOTA_NAND_Is_Good_Block_func(kal_uint32 blk)
{
   _FGAL_ERROR_CODE   result    = ERROR_FGAL_NONE;
   kal_int32          status    = 0;
   kal_uint8          *byte_ptr = (kal_uint8 *)g_fota_spare_buffer;
#if !defined(__NAND_FDM_50__)
   void *nand_info = (void *)&NANDFlashDriveData;
#else /* !__NAND_FDM_50__ */
   void *nand_info = (void *)&Flash_Info;
#endif 

   ASSERT( FOTA_NAND_STATE_VALID == g_FOTA_NAND_MTD_STATE);

   status = NFB_ReadPhysicalSpare(blk, 0, g_fota_spare_buffer, KAL_FALSE);
   if(ERROR_NFB_SUCCESS == status)
   {
      if(IsGoodBlock(nand_info, byte_ptr) > 0)
      {
         status = NFB_ReadPhysicalSpare(blk, 1, g_fota_spare_buffer, KAL_FALSE);
         if(ERROR_NFB_SUCCESS == status)
         {
            if(IsGoodBlock(nand_info, byte_ptr) > 0)
            {
               result = ERROR_FGAL_NONE;
            }
            else
            {
               result = ERROR_FGAL_BAD_BLOCK;
            }
         }
      }
      else
      {
         result = ERROR_FGAL_BAD_BLOCK;
      }
   }
   else
   {
      if(ERROR_NFB_READ == status)
         result = ERROR_FGAL_READ_FAILURE;
      else
         ASSERT(0);
   }

   return result;
}

/*************************************************************************
* FUNCTION
*  FOTA_NAND_Mark_Bad_Block_func
*
* DESCRIPTION
* Read one page from NAND flash
 *************************************************************************/
_FGAL_ERROR_CODE FOTA_NAND_Mark_Bad_Block_func(kal_uint32 blk)
{
   _FGAL_ERROR_CODE   result    = ERROR_FGAL_NONE;
   kal_int32          status    = 0;
   kal_uint8          *byte_ptr = (kal_uint8 *)g_fota_spare_buffer;

   ASSERT( FOTA_NAND_STATE_VALID == g_FOTA_NAND_MTD_STATE);

   NFB_ErasePhysicalBlock(blk, KAL_TRUE);

   kal_mem_set(g_fota_spare_buffer, 0xFF, FOTA_MAX_SPARE_SIZE);
   FOTA_NAND_MTD_Set_Spare_Bad_Mark(byte_ptr);
   
   status = NFB_ProgramPhysicalSpare(blk, 0, byte_ptr, KAL_FALSE, KAL_TRUE);
   if(ERROR_NFB_SUCCESS == status)
   {
      status = NFB_ProgramPhysicalSpare(blk, 1, byte_ptr, KAL_FALSE, KAL_TRUE);
   }

   switch(status)
   {
      case ERROR_NFB_BAD_BLOCK:
         result = ERROR_FGAL_BAD_BLOCK;
         /* should not happen */
         EXT_ASSERT(0, 0, 0, 0);
         break;
      case ERROR_NFB_PROGRAM:
         result = ERROR_FGAL_WRITE_FAILURE;
         break;
      case ERROR_NFB_SUCCESS:
         result = ERROR_FGAL_NONE;
         break;
      default:
         ASSERT(0);
         result = ERROR_FGAL_OPERATION_RETRY;
   }

   return result;
}

/*************************************************************************
* FUNCTION
*  FOTA_NAND_Erase_Block_func
*
* DESCRIPTION
* Erase one block on NAND flash
 *************************************************************************/
_FGAL_ERROR_CODE FOTA_NAND_Erase_Block_func(kal_uint32 blk)
{
   kal_uint32         trial = 0;
   kal_int32          status = -1;
   _FGAL_ERROR_CODE   result = ERROR_FGAL_NONE;

   ASSERT( FOTA_NAND_STATE_VALID == g_FOTA_NAND_MTD_STATE);

   for(trial = 0 ; trial < 3 ; trial++)
   {
      status = NFB_ErasePhysicalBlock(blk, KAL_TRUE);
      if(ERROR_NFB_ERASE != status)
         break;
      delay32KHzTick(1000);
   }

   switch(status)
   {
      case ERROR_NFB_BAD_BLOCK:
         result = ERROR_FGAL_BAD_BLOCK;
         /* should not happen */
         EXT_ASSERT(0, 0, 0, 0);
         break;
      case ERROR_NFB_ERASE:
         result = ERROR_FGAL_ERASE_FAILURE;
         break;
      case ERROR_NFB_SUCCESS:
         result = ERROR_FGAL_NONE;
         break;
      default:
         ASSERT(0);
         result = ERROR_FGAL_OPERATION_RETRY;
   }

   return result;
}

/*************************************************************************
* FUNCTION
*  FOTA_NAND_Is_Page_Empty_func
*
* DESCRIPTION
* Read one page from NAND flash
 *************************************************************************/
_FGAL_ERROR_CODE FOTA_NAND_Is_Page_Empty_func(kal_uint32 *buff, kal_uint32 blk, kal_uint32 page)
{
   _FGAL_ERROR_CODE   result = ERROR_FGAL_NONE;
   kal_int32          status = ERROR_NFB_READ;
   kal_int32          status2 = ERROR_NFB_READ;

   ASSERT( FOTA_NAND_STATE_VALID == g_FOTA_NAND_MTD_STATE);

   kal_mem_set(g_fota_spare_buffer, 0x0, FOTA_MAX_SPARE_SIZE);
   kal_mem_set(buff, 0x0, NFBPageSize);

   status = NFB_ReadPhysicalPage(blk, page, buff);
   status2 = NFB_ReadPhysicalSpare(blk, page, g_fota_spare_buffer, KAL_FALSE);

   if( (NFBPageSize == status) && (ERROR_NFB_SUCCESS == status2) )
   {
      status = ERROR_NFB_SUCCESS;
   }
   else
   {
      status = ERROR_NFB_READ;
   }

   switch(status)
   {
      case ERROR_NFB_BAD_BLOCK:
         result = ERROR_FGAL_BAD_BLOCK;
         /* should not happen */
         EXT_ASSERT(0, 0, 0, 0);
         break;
      case ERROR_NFB_READ: /* empty page in 28/29 is covered here */
         if(!FOTA_NAND_MTD_Check_Page_Empty((kal_uint8 *)buff, (kal_uint8 *)g_fota_spare_buffer))
            result = ERROR_FGAL_NON_EMPTY;
         break;
      case ERROR_NFB_SUCCESS:
         if(!FOTA_NAND_MTD_Check_Page_Empty((kal_uint8 *)buff, (kal_uint8 *)g_fota_spare_buffer))
            result = ERROR_FGAL_NON_EMPTY_CHECK;
         break;
      default:
         ASSERT(0);
         result = ERROR_FGAL_OPERATION_RETRY;
   }

   return result;
}

/*************************************************************************
* FUNCTION
*  FOTA_NAND_Lock_Block_func
*
* DESCRIPTION
* Lock one block on NAND flash
 *************************************************************************/
_FGAL_ERROR_CODE FOTA_NAND_Lock_Block_func(kal_uint32 blk, kal_bool locked)
{
   return ERROR_FGAL_NONE;
}

/*************************************************************************
* FUNCTION
*  FOTA_NAND_Block_Size_func
*
* DESCRIPTION
* Erase one block on NAND flash
 *************************************************************************/
kal_uint32 FOTA_NAND_Block_Size_func(kal_uint32 blk)
{
   kal_uint32          blk_size   = 0;
#if !defined(__NAND_FDM_50__)
   flash_info_struct  *nand_info  = &NANDFlashDriveData.flash_info;

   if(PAGE_2K == nand_info->page_type)
   {
      blk_size = 2048*nand_info->pages_per_block;
   }
   else if(PAGE_512 == nand_info->page_type)
   {
      blk_size = 512*nand_info->pages_per_block;
   }
   else
      ASSERT(0); /* incorrect configuration */

#else

   blk_size = Flash_Info.pageSize*Flash_Info.blockPage;

#endif

   return blk_size;
}

/*************************************************************************
* FUNCTION
*  FOTA_NAND_Block_Index_func
*
* DESCRIPTION
* Erase one block on NAND flash
 *************************************************************************/
kal_uint32 FOTA_NAND_Block_Index_func(kal_uint32 blk_addr)
{
   kal_uint32          blk_size   = 0;
#if !defined(__NAND_FDM_50__)
   flash_info_struct  *nand_info  = &NANDFlashDriveData.flash_info;

   if(PAGE_2K == nand_info->page_type)
   {
      blk_size = 2048*nand_info->pages_per_block;
   }
   else if(PAGE_512 == nand_info->page_type)
   {
      blk_size = 512*nand_info->pages_per_block;
   }
   else
      ASSERT(0); /* incorrect configuration */

#else

   blk_size = Flash_Info.pageSize*Flash_Info.blockPage;

#endif

   ASSERT(blk_size);/* incorrect device configuration */

   return blk_addr/blk_size;
}

#elif defined(__EMMC_BOOTING__)

/* For flash generic access layer */
Flash_GAL_st          FOTA_eMMC_Fgal;

Flash_GAL_st *FOTA_Setup_FGAL(void)
{
   if(FOTA_FGAL_READY == g_FOTA_fgal_state)
      return &FOTA_eMMC_Fgal;

   /* set up FGAL */
   FOTA_eMMC_Fgal.init_drv = FGAL2FTL_Init;
   FOTA_eMMC_Fgal.query_info = FGAL2FTL_Query_Info;
   FOTA_eMMC_Fgal.read_page = FGAL2FTL_Read_Page;
   FOTA_eMMC_Fgal.write_page = FGAL2FTL_Write_Page;
   FOTA_eMMC_Fgal.check_block = FGAL2FTL_Is_Good_Block;
   FOTA_eMMC_Fgal.mark_bad = FGAL2FTL_Mard_Bad_Block;
   FOTA_eMMC_Fgal.erase_block = FGAL2FTL_Erase_Block;
   FOTA_eMMC_Fgal.check_empty_page = FGAL2FTL_Is_Empty_Page;
   FOTA_eMMC_Fgal.block_size = FGAL2FTL_Block_Size;
   FOTA_eMMC_Fgal.block_index = FGAL2FTL_Block_Index;
   FOTA_eMMC_Fgal.lock_block = FGAL2FTL_Lock_Block;

   /* initialize FGAL driver */
   FOTA_eMMC_Fgal.init_drv();

   g_FOTA_fgal_state = FOTA_FGAL_READY;
   return &FOTA_eMMC_Fgal;
}


#else /* !_NAND_FLASH_BOOTING_ */

#include "custom_MemoryDevice.h"
#include "DrvFlash.h"
#include "reg_base.h"
#include "fue_init.h"

/* Forward declaration */
_FGAL_ERROR_CODE FOTA_NOR_Init_func(void);
_FGAL_ERROR_CODE FOTA_NOR_Page_Read_func(kal_uint32* ptr, kal_uint32 blk, kal_uint32 page);
_FGAL_ERROR_CODE FOTA_NOR_Query_Info_func(Logical_Flash_info_st* info);
_FGAL_ERROR_CODE FOTA_NOR_Page_Program_func(kal_uint32* ptr, kal_uint32 blk, kal_uint32 page);
_FGAL_ERROR_CODE FOTA_NOR_Is_Good_Block_func(kal_uint32 blk);
_FGAL_ERROR_CODE FOTA_NOR_Mark_Bad_Block_func(kal_uint32 blk);
_FGAL_ERROR_CODE FOTA_NOR_Erase_Block_func(kal_uint32 blk);
_FGAL_ERROR_CODE FOTA_NOR_Is_Page_Empty_func(kal_uint32 *buff, kal_uint32 blk, kal_uint32 page);
_FGAL_ERROR_CODE FOTA_NOR_Lock_Block_func(kal_uint32 blk, kal_bool locked);
kal_uint32 FOTA_NOR_Block_Size_func(kal_uint32 blk);
kal_uint32 FOTA_NOR_Block_Index_func(kal_uint32 blk_addr);

/* Following functions and variables are located in custom_blconfig.c */
extern kal_uint32 custom_Block_Size(kal_uint32 nor_addr);
extern kal_uint32 custom_get_NORFLASH_ROMSpace(void);
extern kal_uint32 custom_get_NORFLASH_Base(void);

/*
 * Macro definition
 */
#define FOTA_NOR_STATE_VALID   (0x5644544D)

#define FOTA_MAX_SPARE_SIZE      (64)

/*
 * Global variable definition
 */
kal_uint32 g_FOTA_NOR_MTD_STATE;
/* 
 * For flash generic access layer 
 */
Flash_GAL_st          FOTA_Nor_Fgal;

NOR_FLASH_DRV_Data    NORFlashDriveData;
NOR_Flash_MTD_Data    FOTA_nor_mtdflash;

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
kal_bool            FOTA_Flash_busy = KAL_FALSE;
extern kal_uint32 NOR_ResumeQueueErase(void);
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

/* 
 * External variable reference
 */

extern NOR_MTD_Driver NORFlashMtd;

#if ( defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )

kal_uint32  NOR_counter;

#pragma arm section code = "SNORCODE"

void NORTEST_Delay_us(kal_uint32 count)
{
   kal_uint32 begin_val = 0;
   kal_uint32 diff_val   = 0;

   begin_val = *(volatile kal_uint16 *)(TDMA_base + 0x00);
   do{
      diff_val = *(volatile kal_uint16 *)(TDMA_base + 0x00);
      if(diff_val > begin_val)
      {
         diff_val -= begin_val;
      }
      else if(diff_val < begin_val)
      {
         diff_val += (*(volatile kal_uint16 *)(TDMA_base + 0x04))-begin_val;
      }
      else
      {
         diff_val = 0;
      }
      if(diff_val >= count)
         break;
   }while(1);
}

void NORTEST_Delay_30us(kal_uint32 count)
{
   kal_uint32 begin_val = 0;
   kal_uint32 diff_val   = 0;

   begin_val = *(volatile kal_uint32*)COUNTER_32K;
   do{
      diff_val = *(volatile kal_uint32*)COUNTER_32K;
      if(diff_val > begin_val)
      {
         diff_val -= begin_val;
      }
      else if(diff_val < begin_val)
      {
         diff_val += (0xFFFFFFFF-begin_val);
      }
      else
      {
         diff_val = 0;
      }
      if(diff_val >= count)
         break;
   }while(1);
}

#pragma arm section code
#endif /* __NOR_FLASH_HARDWARE_TEST__ && __MAUI_BASIC__ */

/*****************************************************************
Description : acquire FDM synchronization lock.
Input       : 
Output      : None
******************************************************************/
void retrieve_FDM_lock(void)
{
   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

   extern void GetFDMLock(void);
   GetFDMLock();

   #elif defined(__NOR_FDM5__)

   extern void nFDM_LOCK(void);
   nFDM_LOCK();

   #else

   extern void FDM_LOCK(void);
   FDM_LOCK();

   #endif
}

/*****************************************************************
Description : relieve FDM synchronization lock.
Input       : 
Output      : None
******************************************************************/
void release_FDM_lock(void)
{
   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)

   extern void FreeFDMLock(void);
   FreeFDMLock();

   #elif defined(__NOR_FDM5__)

   extern void nFDM_UNLOCK(void);
   nFDM_UNLOCK();

   #else

   extern void FDM_UNLOCK(void);
   FDM_UNLOCK();

   #endif
}

/*****************************************************************
Description : Wait device ready before operation
Input       : 
Output      : None
******************************************************************/
void FOTA_WaitEraseDone(void)
{
   #if (defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) || defined(__NOR_FDM5__))

   return;

   #else // !__SINGLE_BANK_NOR_FLASH_SUPPORT__ && __NOR_FDM4__

   extern NOR_FLASH_DRV_Data FlashDriveData;
   extern void WaitEraseDone(NOR_FLASH_DRV_Data * D, kal_uint32 frame_tick);
   //#define INVALID_BLOCK_INDEX   0xFFFFFFFF
   if( FlashDriveData.ReclaimBlockID != 0xFFFFFFFF )
   { 
      WaitEraseDone(&FlashDriveData,70);
   }
   #endif
}

/*****************************************************************
Description : set up FGAL structure.
Input       : 
Output      : None
******************************************************************/
#define FOTA_FGAL_READY   (0x59445246)
kal_uint32 g_FOTA_fgal_state;
extern kal_uint8 RandomNum;

Flash_GAL_st *FOTA_Setup_FGAL(void)
{
#if ( (defined(__NOR_FLASH_HARDWARE_TEST__) || defined(__NAND_FLASH_HARDWARE_TEST__)) && defined(__MAUI_BASIC__) )

#if 0
/* under construction !*/
/* under construction !*/
#else
   DCL_HANDLE rtc_handler;
   RTC_CTRL_GET_TIME_T rtc_cmd_data3;
#endif

   kal_char  test_text[64];
#endif

   if(FOTA_FGAL_READY == g_FOTA_fgal_state)
      return &FOTA_Nor_Fgal;

  /* set up FGAL */
   FOTA_Nor_Fgal.init_drv = FOTA_NOR_Init_func;
   FOTA_Nor_Fgal.query_info = FOTA_NOR_Query_Info_func;
   FOTA_Nor_Fgal.read_page = FOTA_NOR_Page_Read_func;
   FOTA_Nor_Fgal.write_page = FOTA_NOR_Page_Program_func;
   FOTA_Nor_Fgal.check_block = FOTA_NOR_Is_Good_Block_func;
   FOTA_Nor_Fgal.mark_bad = FOTA_NOR_Mark_Bad_Block_func;
   FOTA_Nor_Fgal.erase_block = FOTA_NOR_Erase_Block_func;
   FOTA_Nor_Fgal.check_empty_page = FOTA_NOR_Is_Page_Empty_func;
   FOTA_Nor_Fgal.block_size = FOTA_NOR_Block_Size_func;
   FOTA_Nor_Fgal.block_index = FOTA_NOR_Block_Index_func;
   FOTA_Nor_Fgal.lock_block = FOTA_NOR_Lock_Block_func;

   /* initialize FGAL driver */
   FOTA_Nor_Fgal.init_drv();

   g_FOTA_fgal_state = FOTA_FGAL_READY;

#if ( defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
   rtc_handler = DclRTC_Open(DCL_RTC, FLAGS_NONE);
	DclRTC_Control(rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T *)&rtc_cmd_data3); // New API with CMD & DATA 
	DclRTC_Close(rtc_handler);

   kal_sprintf(test_text,"Time %d:%d:%d:%d \n\r", rtc_cmd_data3.u1Day, rtc_cmd_data3.u1Hour, rtc_cmd_data3.u1Min, rtc_cmd_data3.u1Sec);
   kal_print(test_text);

   srand(*(volatile kal_uint16 *)(TDMA_base + 0x00) + rtc_cmd_data3.u1Sec+ (rtc_cmd_data3.u1Min*60));
   
#endif

#endif /* __NOR_FLASH_HARDWARE_TEST__ && __MAUI_BASIC__ */

   return &FOTA_Nor_Fgal;
}

/*************************************************************************
* FUNCTION
*  FOTA_NOR_Init_func
*
* DESCRIPTION
* Initialze NOR flash MTD driver
 ************************************************************************/

#if (defined(__COMBO_MEMORY_SUPPORT__) || defined(__SERIAL_FLASH__))

extern FlashRegionInfo CMEM_FOTA_NORRegionInfo[];

_FGAL_ERROR_CODE FOTA_NOR_Init_func(void)
{

   if( (FOTA_NOR_STATE_VALID == g_FOTA_NOR_MTD_STATE) &&
       (~((kal_uint32)CMEM_FOTA_NORRegionInfo) == ((NOR_Flash_MTD_Data*)(NORFlashDriveData.MTDData))->Signature) )
      return ERROR_FGAL_NONE;

   g_FOTA_NOR_MTD_STATE = FOTA_NOR_STATE_VALID;

   /* Initialize MTD data table */
   CMEM_Init_FOTA();

   /* prepare update package area information */
   // RegionInfo must be assigned before invoke FOTA_NOR_Block_Index_func
   FOTA_NFB_Area_Info.m_fota_pkg_area.m_pkg_area_start = FOTA_NOR_Block_Index_func(FOTA_PACKAGE_STORAGE_BASE);
   FOTA_NFB_Area_Info.m_fota_pkg_area.m_pkg_area_end = FOTA_NOR_Block_Index_func(FOTA_PACKAGE_STORAGE_BASE+FOTA_PACKAGE_STORAGE_SIZE)-1;

   NORFlashDriveData.FlashInfo.baseUnlockBlock = FOTA_NFB_Area_Info.m_fota_pkg_area.m_pkg_area_start;
   NORFlashDriveData.FlashInfo.endUnlockBlock = FOTA_NFB_Area_Info.m_fota_pkg_area.m_pkg_area_end;

   NORFlashDriveData.MTDDriver->MountDevice(NORFlashDriveData.MTDData, (void*)&NORFlashDriveData.FlashInfo);
   /* prepare update package area information */
   //FOTA_NFB_Area_Info.m_fota_pkg_area.m_pkg_area_start = FOTA_NOR_Block_Index_func(FOTA_PACKAGE_STORAGE_BASE);
   //FOTA_NFB_Area_Info.m_fota_pkg_area.m_pkg_area_end = FOTA_NOR_Block_Index_func(FOTA_PACKAGE_STORAGE_BASE+FOTA_PACKAGE_STORAGE_SIZE)-1;
   /* TODO: unlock all blocks reserved for update package */
   return ERROR_FGAL_NONE;
}

#else // !__COMBO_MEMORY_SUPPORT__ && !__SERIAL_FLASH__
_FGAL_ERROR_CODE FOTA_NOR_Init_func(void)
{
   if( (FOTA_NOR_STATE_VALID == g_FOTA_NOR_MTD_STATE) &&
       (~((kal_uint32)NORRegionInfo) == FOTA_nor_mtdflash.Signature) )
      return ERROR_FGAL_NONE;

   g_FOTA_NOR_MTD_STATE = FOTA_NOR_STATE_VALID;
   /* Initialize MTD data table */
   FOTA_nor_mtdflash.Signature = ~((kal_uint32)NORRegionInfo);

   NORFlashDriveData.MTDDriver = &NORFlashMtd;
   NORFlashDriveData.MTDData = &FOTA_nor_mtdflash;

#ifdef __MTK_TARGET__
#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
//   NOR_Flash_Base_Address =INT_RetrieveFlashBaseAddr();
#endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */
   FOTA_nor_mtdflash.BaseAddr = (BYTE *)INT_RetrieveFlashBaseAddr();
#endif /* __MTK_TARGET__ */

   FOTA_nor_mtdflash.RegionInfo = (FlashRegionInfo *)NORRegionInfo;
#if  defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__) && defined(__MULTI_BANK_NOR_DEVICE__)
   FOTA_nor_mtdflash.BankInfo = (FlashBankInfo*)FOTANORBankInfo;
#endif
   /* prepare update package area information */
   FOTA_NFB_Area_Info.m_fota_pkg_area.m_pkg_area_start = FOTA_NOR_Block_Index_func(FOTA_PACKAGE_STORAGE_BASE);
   FOTA_NFB_Area_Info.m_fota_pkg_area.m_pkg_area_end = FOTA_NOR_Block_Index_func(FOTA_PACKAGE_STORAGE_BASE+FOTA_PACKAGE_STORAGE_SIZE)-1;

   NORFlashDriveData.FlashInfo.baseUnlockBlock = FOTA_NFB_Area_Info.m_fota_pkg_area.m_pkg_area_start;
   NORFlashDriveData.FlashInfo.endUnlockBlock = FOTA_NFB_Area_Info.m_fota_pkg_area.m_pkg_area_end;

   NORFlashDriveData.MTDDriver->MountDevice(NORFlashDriveData.MTDData, (void*)&NORFlashDriveData.FlashInfo);
   /* prepare update package area information */
   //FOTA_NFB_Area_Info.m_fota_pkg_area.m_pkg_area_start = FOTA_NOR_Block_Index_func(FOTA_PACKAGE_STORAGE_BASE);
   //FOTA_NFB_Area_Info.m_fota_pkg_area.m_pkg_area_end = FOTA_NOR_Block_Index_func(FOTA_PACKAGE_STORAGE_BASE+FOTA_PACKAGE_STORAGE_SIZE)-1;
   /* TODO: unlock all blocks reserved for update package */
   return ERROR_FGAL_NONE;
}
#endif //__COMBO_MEMORY_SUPPORT__ || __SERIAL_FLASH__

/*************************************************************************
* FUNCTION
*  FOTA_NOR_Page_Read_func
*
* DESCRIPTION
* Read one page from NOR flash
 ************************************************************************/
_FGAL_ERROR_CODE FOTA_NOR_Page_Read_func(kal_uint32* ptr, kal_uint32 blk, kal_uint32 page)
{
   NOR_Flash_MTD_Data *mtdflash = (NOR_Flash_MTD_Data *)NORFlashDriveData.MTDData;
   _FGAL_ERROR_CODE   result = ERROR_FGAL_NONE;
   kal_int32          status = 0;
   kal_uint32         blk_size = 0;
   kal_uint32         src_addr = 0;

   ASSERT( FOTA_NOR_STATE_VALID == g_FOTA_NOR_MTD_STATE);
   retrieve_FDM_lock();

   FOTA_WaitEraseDone();

   blk_size = BlockSize(mtdflash, blk);
   ASSERT(page < (blk_size/FOTA_FLASH_MAX_PAGE_SIZE));
   src_addr = (kal_uint32)BlockAddress(mtdflash, blk) + page*FOTA_FLASH_MAX_PAGE_SIZE;
   kal_mem_cpy(ptr, (void *)src_addr, FOTA_FLASH_MAX_PAGE_SIZE);

   release_FDM_lock();
   return result;
}

/*************************************************************************
* FUNCTION
*  FOTA_NOR_Query_Info_func
*
* DESCRIPTION
* Query NOR flash device information
* The information is specific for flash area reserved for update package 
 ************************************************************************/
_FGAL_ERROR_CODE FOTA_NOR_Query_Info_func(Logical_Flash_info_st* info)
{
   _FGAL_ERROR_CODE   result      = ERROR_FGAL_NONE;
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
   #else
   info->Flash_page_size = FOTA_FLASH_MAX_PAGE_SIZE;
   info->Flash_io_width = 16;
   #endif

   return result;
}

/*************************************************************************
* FUNCTION
*  FOTA_NOR_Page_Program_func
*
* DESCRIPTION
* Write one page to NOR flash
 ************************************************************************/
_FGAL_ERROR_CODE FOTA_NOR_Page_Program_func(kal_uint32* ptr, kal_uint32 blk, kal_uint32 page)
{
   _FGAL_ERROR_CODE   result    = ERROR_FGAL_NONE;
   kal_int32          status    = 0;
   kal_uint32         blk_size  = 0;
   kal_uint32         dst_addr  = 0;
   kal_uint32         src_addr  = (kal_uint32)ptr;
   kal_uint32         left_len  = FOTA_FLASH_MAX_PAGE_SIZE;
   kal_uint32         write_len = 0;
   kal_uint32         pbp_len   = 0;
   NOR_MTD_Driver     *mtd_drv  = NORFlashDriveData.MTDDriver;
   NOR_Flash_MTD_Data *mtdflash = (NOR_Flash_MTD_Data *)NORFlashDriveData.MTDData;

   ASSERT( FOTA_NOR_STATE_VALID == g_FOTA_NOR_MTD_STATE);
   blk_size = BlockSize(mtdflash, blk);
   ASSERT(page < (blk_size/FOTA_FLASH_MAX_PAGE_SIZE));

   MapWindow(mtdflash, blk, 0);
   //mtdflash->CurrAddr = (BYTE *)BlockAddress(mtdflash, blk);

   dst_addr = (kal_uint32)mtdflash->CurrAddr + page*FOTA_FLASH_MAX_PAGE_SIZE;

   retrieve_FDM_lock();

   FOTA_WaitEraseDone();

   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   FOTA_Flash_busy = KAL_TRUE;
   NOR_ResumeQueueErase();
   #endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

   #if ( defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )
   RandomNum = rand();
   #endif /* __NOR_FLASH_HARDWARE_TEST__ && __MAUI_BASIC__ */

   if(BUFFER_PROGRAM_ITERATION_LENGTH)
   {
      pbp_len = BUFFER_PROGRAM_ITERATION_LENGTH<<1;
   }
   else
   {
      pbp_len = 2;
   }

   while(left_len)
   {
      if(left_len > pbp_len)
      {
         write_len = pbp_len;
      }
      else
      {
         write_len = left_len;
      }

      status = mtd_drv->ProgramData(mtdflash, (void *)dst_addr, (void *)src_addr, write_len);
      if(RESULT_FLASH_FAIL == status)
      {
         break;
      }
      else
      {
         left_len -= write_len;
         dst_addr += write_len;
         src_addr += write_len;
      }
   }

   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   FOTA_Flash_busy = KAL_FALSE;
   #endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

   release_FDM_lock();

   if(RESULT_FLASH_FAIL == status)
   {
      result = ERROR_FGAL_WRITE_FAILURE;
   }

   return result;
}

/*************************************************************************
* FUNCTION
*  FOTA_NOR_Is_Good_Block_func
*
* DESCRIPTION
* Check whether block is good or bad.
* Always return good since no bad block is allowed in NOR flash
 ************************************************************************/
_FGAL_ERROR_CODE FOTA_NOR_Is_Good_Block_func(kal_uint32 blk)
{
   ASSERT( FOTA_NOR_STATE_VALID == g_FOTA_NOR_MTD_STATE);

   return ERROR_FGAL_NONE;
}

/*************************************************************************
* FUNCTION
*  FOTA_NOR_Mark_Bad_Block_func
*
* DESCRIPTION
* mark a block as bad, should not be called on NOR flash
 *************************************************************************/
_FGAL_ERROR_CODE FOTA_NOR_Mark_Bad_Block_func(kal_uint32 blk)
{
   ASSERT( FOTA_NOR_STATE_VALID == g_FOTA_NOR_MTD_STATE);

   /* should not happen */
   EXT_ASSERT(0, 0, 0, 0);

   return ERROR_FGAL_OPERATION_RETRY;
}

/*************************************************************************
* FUNCTION
*  FOTA_NOR_Erase_Block_func
*
* DESCRIPTION
* Erase one block on NOR flash
 *************************************************************************/
_FGAL_ERROR_CODE FOTA_NOR_Erase_Block_func(kal_uint32 blk)
{
   kal_uint32         trial = 0;
   kal_int32          status = -1;
   _FGAL_ERROR_CODE   result = ERROR_FGAL_NONE;
   NOR_MTD_Driver     *mtd_drv  = NORFlashDriveData.MTDDriver;
   NOR_Flash_MTD_Data *mtdflash = (NOR_Flash_MTD_Data *)NORFlashDriveData.MTDData;

   MapWindow(mtdflash, blk, 0);

   ASSERT( FOTA_NOR_STATE_VALID == g_FOTA_NOR_MTD_STATE);
   retrieve_FDM_lock();

   FOTA_WaitEraseDone();

   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   FOTA_Flash_busy = KAL_TRUE;
   NOR_ResumeQueueErase();
   #endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

   #if ( defined(__NOR_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )
   RandomNum = rand();
   #endif /* __NOR_FLASH_HARDWARE_TEST__ && __MAUI_BASIC__ */

   status = mtd_drv->EraseBlock(mtdflash, blk);

   #if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
   FOTA_Flash_busy = KAL_FALSE;
   #endif /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

   release_FDM_lock();

   return result;
}

/*************************************************************************
* FUNCTION
*  FOTA_NOR_Is_Page_Empty_func
*
* DESCRIPTION
* Read one page from NOR flash
 *************************************************************************/
_FGAL_ERROR_CODE FOTA_NOR_Is_Page_Empty_func(kal_uint32 *buff, kal_uint32 blk, kal_uint32 page)
{
   kal_uint32         *page_ptr = NULL;
   kal_uint32         blk_size  = 0;
   kal_uint32           idx     = 0;
   _FGAL_ERROR_CODE   result    = ERROR_FGAL_NONE;
   NOR_Flash_MTD_Data *mtdflash = (NOR_Flash_MTD_Data *)NORFlashDriveData.MTDData;

   ASSERT( FOTA_NOR_STATE_VALID == g_FOTA_NOR_MTD_STATE);
   blk_size = BlockSize(mtdflash, blk);
   ASSERT(page < (blk_size/FOTA_FLASH_MAX_PAGE_SIZE));

   mtdflash->CurrAddr = (BYTE *)BlockAddress(mtdflash, blk);
   page_ptr = (kal_uint32 *)((kal_uint32)mtdflash->CurrAddr + page*FOTA_FLASH_MAX_PAGE_SIZE);

   retrieve_FDM_lock();

   FOTA_WaitEraseDone();  

   for(idx = 0 ; idx < (FOTA_NOR_FLASH_PAGE_SIZE>>2) ; idx++)
   {
      if(*(page_ptr+idx) != INVALID_DWORD)
      {
         result = ERROR_FGAL_NON_EMPTY_CHECK;
         break;
      }
   }

   release_FDM_lock();

   if(ERROR_FGAL_NON_EMPTY_CHECK == result)
   {
      kal_mem_cpy(buff, page_ptr, FOTA_FLASH_MAX_PAGE_SIZE);
   }

   return result;
}

/*************************************************************************
* FUNCTION
*  FOTA_NOR_Lock_Block_func
*
* DESCRIPTION
* Erase one block on NOR flash
 *************************************************************************/
_FGAL_ERROR_CODE FOTA_NOR_Lock_Block_func(kal_uint32 blk, kal_bool locked)
{
   _FGAL_ERROR_CODE   result = ERROR_FGAL_NONE;
   kal_uint32         blk_addr = 0;
   kal_uint32         blk_action = 0;
   NOR_Flash_MTD_Data *mtdflash = (NOR_Flash_MTD_Data *)NORFlashDriveData.MTDData;
   NOR_MTD_Driver     *mtd_drv  = NORFlashDriveData.MTDDriver;

   ASSERT( FOTA_NOR_STATE_VALID == g_FOTA_NOR_MTD_STATE);
   blk_addr = (kal_uint32)BlockAddress(mtdflash, blk);
   if(locked)
   {
      blk_action = ACTION_LOCK;
   }
   else
   {
      blk_action = ACTION_UNLOCK;
   }

   retrieve_FDM_lock();

   FOTA_WaitEraseDone();

   mtd_drv->LockEraseBlkAddr(mtdflash, (void *)blk_addr, blk_action);

   release_FDM_lock();
   return ERROR_FGAL_NONE;
}

/*************************************************************************
* FUNCTION
*  FOTA_NOR_Block_Size_func
*
* DESCRIPTION
* Erase one block on NAND flash
 *************************************************************************/
kal_uint32 FOTA_NOR_Block_Size_func(kal_uint32 blk)
{
   NOR_Flash_MTD_Data *mtdflash = (NOR_Flash_MTD_Data *)NORFlashDriveData.MTDData;
   ASSERT( FOTA_NOR_STATE_VALID == g_FOTA_NOR_MTD_STATE);

   return BlockSize((void *)mtdflash, blk);
}

/*************************************************************************
* FUNCTION
*  FOTA_NOR_Block_Index_func
*
* DESCRIPTION
* Erase one block on NAND flash
 *************************************************************************/
kal_uint32 FOTA_NOR_Block_Index_func(kal_uint32 blk_addr)
{
   NOR_Flash_MTD_Data *mtdflash = (NOR_Flash_MTD_Data *)NORFlashDriveData.MTDData;
   ASSERT( FOTA_NOR_STATE_VALID == g_FOTA_NOR_MTD_STATE);

   return BlockIndex((void *)mtdflash, blk_addr & (~((kal_uint32)mtdflash->BaseAddr)));
   //return BlockIndex((void *)mtdflash, blk_addr - FOTA_PACKAGE_STORAGE_BASE);
}

#endif /* NAND_FLASH_BOOTING */


#endif /* __FOTA_DM__ */
