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
 * tst_file_trans_export.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements the exported functions for TST
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
#ifdef __TST_WRITE_TO_FILE__  //this function is only avaialable when __TST_WRITE_TO_FILE__ is enabled

#include "kal_public_api.h" //MSBB change #include "kal_release.h"      /* Basic data type */

#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"

#include "syscomp_config.h"
#include "task_config.h"      /* Task creation */

#include "kal_public_api.h"   /* Buffer management */

#include "GV.h"
#include "tst_def.h"
#include "tst_ext.h"          /* Dump info*/

#include "fs_errcode.h"
#include "fs_type.h"
#include "fs_func.h"
#include "intrCtrl.h"
#include "tst_file_def.h"
//#pragma arm section code= "PRIMARY_ROCODE" rwdata = "PRIMARY_RW" , rodata = "PRIMARY_RODATA" , zidata = "PRIMARY_ZI" 

/*************************************************************************
* Global variable declaration
 *************************************************************************/
#if defined(__LOGACC_ENABLE__) && !defined(UNIT_TEST) 
  __tstfilezidata kal_uint8* lga_buf_ptr = 0 ;
  __tstfilezidata kal_uint32 lga_buf_len = 0;
  __tstfilerwdata kal_bool b_lga_log_unsent=KAL_FALSE;
#endif  //#if defined(__LOGACC_ENABLE__) && !defined(UNIT_TEST) 

/*************************************************************************
* Extern variable declaration
 *************************************************************************/
extern kal_eventgrpid  tst_event_group;
extern tst_log_to_file_err_enum tst_err_log_to_file;  //the error code
extern tst_dump_info_struct tst_dump_info;
extern kal_eventgrpid  tft_event_group;

/*************************************************************************
* Function declaration
 *************************************************************************/
extern kal_uint32 tst_indicate_only_write_to_file_status_internal(void);
extern void tst_log_to_file_ShowError(void);
extern void tst_dump_to_file_for_crash_internal(void);
extern void tst_file_dump_create_file(void);
extern void tst_file_dump_file(void);

/*************************************************************************
* Function Implementation
 *************************************************************************/

__tstfileFunc tst_write2_sd_option_t tst_file_query_write2file_option(void)
{
  return (tst_dump_info.tst_write2_sd_option);
}

__tstfileFunc void tst_file_init_l1_log_buf(void)
{
  tst_dump_info.nL1BufferWritePtr = 0;
  tst_dump_info.nL1BufferVancancy = TST_L1_BUFFER_SIZE_FOR_WRITE_FILE-1;
}

__tstfileFunc kal_uint32 tst_file_query_l1_log_space(void)
{
  return tst_dump_info.nL1BufferVancancy;  
}

__tstfileFunc kal_uint32 tst_file_query_ps_log_space(void)
{
  return tst_dump_info.nFileFreeSpace;  
}

__tstfileFunc kal_uint32 tst_file_reserve_ps_log_space(kal_uint32 length)
{
  tst_dump_info.nFileFreeSpace -= length;
  
  return length;  
}

__tstfileFunc kal_uint32 tst_file_query_disk_space(void)
{
  return tst_dump_info.nDiskFreeSpace;  
}

__tstfileFunc kal_uint32 tst_file_indicate_write2file_only()
{
  return tst_indicate_only_write_to_file_status_internal();
}

__tstfileFunc void tst_file_set_ps_log_head_packet(kal_bool value)
{
  tst_dump_info.bHeadOfOnePacket = value;
}

__tstfileFunc kal_bool tst_file_get_ps_log_head_packet(void)
{
  return tst_dump_info.bHeadOfOnePacket;
}

__tstfileFunc void tst_dump_reset_file_buf_info(void)
{
  ASSERT(tst_err_log_to_file == NO_LOG_ERROR);  //no error  
  tst_dump_info.nBufferPtr = 0;
}

__tstfileFunc kal_uint32 tst_file_request_file_space_on_disk(kal_uint32 request_space)  //TST_MAX_LOG_SIZE_FOR_SINGLE_FILE
{
  kal_uint32 reserved_space;
  
  if (tst_dump_info.nDiskFreeSpace < request_space)
  {
    tst_dump_info.nFileFreeSpace = tst_dump_info.nDiskFreeSpace - request_space - (1<<12);    
    reserved_space = tst_dump_info.nDiskFreeSpace;
    tst_dump_info.nDiskFreeSpace = 0;
  }
  else
  {
    tst_dump_info.nDiskFreeSpace -= request_space;
    tst_dump_info.nFileFreeSpace = request_space - request_space - (1<<12);
    reserved_space = request_space;
  }
  
  return reserved_space;
}

__tstfileFunc kal_bool tst_file_reserve_disk_space(kal_uint32 length)
{    
  if (tst_dump_info.nDiskFreeSpace <= length)
  {
    return KAL_FALSE;
  }
  else  //decrease the diskspace
  {
    tst_dump_info.nDiskFreeSpace -= length;
    return KAL_TRUE;
  }
}

/*************************************************************************
* FUNCTION                                                            
*  tst_file_dump_log_to_file
*
* DESCRIPTION                                                           
*   dump data to the log file
*   This API may be called under TFT (Under LogAcc usage) or TST context
* PARAMETERS
*  None
* 
*
* RETURNS
*  None
*
*
*****************************************************************************/
__tstfileFunc void tst_file_dump_log_to_file(kal_uint8 *buffer, kal_uint32 length, kal_uint32 caller_context)
{
  kal_uint32  event_group;  

  if (tst_dump_info.tst_write2_sd_option == TST_Write2File_None) return;
    
  if(kal_query_boot_mode() != NORMAL_BOOT) 
    return;  
        
  if (length > tst_dump_info.nFileFreeSpace)
  {
    if (tst_dump_info.bHeadOfOnePacket)
    {
      if (caller_context ==0) //TST
      {
        //invoke TST File Transfer to move data to files  
        kal_set_eg_events(tst_event_group, TST_EVENT_WRITE_CREATE_TO_FILE, KAL_OR);
        //wait for moving complete
        kal_retrieve_eg_events(  tst_event_group,
                                TST_EVENT_WRITE_CREATE_TO_FILE_OK,
                                KAL_OR_CONSUME,
                                  &event_group,
                                KAL_SUSPEND);        
      } 
      else
      { //TFT
        tst_file_dump_create_file();  
      }             
      
      if (tst_err_log_to_file != NO_LOG_ERROR)  //some error occurs
      {
        goto FAIL_EXIT;
      }   
      
      if (tst_dump_info.nDiskFreeSpace < TST_MAX_LOG_SIZE_FOR_SINGLE_FILE)
      {
        tst_dump_info.nFileFreeSpace = tst_dump_info.nDiskFreeSpace - length - (1<<12);
        tst_dump_info.nDiskFreeSpace = 0;
      }
      else
      {
        tst_dump_info.nDiskFreeSpace -= TST_MAX_LOG_SIZE_FOR_SINGLE_FILE;
        tst_dump_info.nFileFreeSpace = TST_MAX_LOG_SIZE_FOR_SINGLE_FILE - length - (1<<12);
      }
 
                     
    }
    else  //if (tst_dump_info.bHeadOfOnePacket)
    {
      if (tst_dump_info.nDiskFreeSpace < (length - tst_dump_info.nFileFreeSpace))
      {
        tst_err_log_to_file = DISK_FULL;
        goto FAIL_EXIT;
      }
      tst_dump_info.nDiskFreeSpace -= (length - tst_dump_info.nFileFreeSpace);
      tst_dump_info.nFileFreeSpace = 0;
    }  //end of if (tst_dump_info.bHeadOfOnePacket)
  }
  else  //if (length > tst_dump_info.nFileFreeSpace)
  {
    tst_dump_info.nFileFreeSpace -= length;
  }  //end of if (length > tst_dump_info.nFileFreeSpace)
  
  if (tst_dump_info.nBufferPtr + length < TST_FSWRITE_BUFFER_SIZE)
  {
    kal_mem_cpy(tst_dump_info.buffer + tst_dump_info.nBufferPtr, buffer, length);
    tst_dump_info.nBufferPtr += length;
  }
  else
  {
    kal_uint32 nHalfLen;
    kal_uint32 left_len= length;
    
    while((tst_dump_info.nBufferPtr+left_len) >= TST_FSWRITE_BUFFER_SIZE)
    {
      nHalfLen = TST_FSWRITE_BUFFER_SIZE - tst_dump_info.nBufferPtr;
      kal_mem_cpy(tst_dump_info.buffer + tst_dump_info.nBufferPtr, buffer+(length-left_len), nHalfLen);
      
      if (caller_context ==0)
      { //TST
        //invoke TST File Transfer to move data to files  
        kal_set_eg_events(tst_event_group, TST_EVENT_WRITE_TO_FILE, KAL_OR);
        //wait for moving complete
        kal_retrieve_eg_events( tst_event_group,
                                TST_EVENT_WRITE_TO_FILE_OK,
                                KAL_OR_CONSUME,
                                &event_group,
                                KAL_SUSPEND);
      }
      else
      { //TFT
        tst_file_dump_file();
      }
        
      if (tst_err_log_to_file != NO_LOG_ERROR)  //some error occurs
      {
        goto FAIL_EXIT;
      }  
      
      tst_dump_info.nBufferPtr = 0;
      left_len -= nHalfLen;
    }
    
    if (left_len > 0)
    {
      kal_mem_cpy(tst_dump_info.buffer, buffer + (length-left_len), left_len);
      tst_dump_info.nBufferPtr = left_len;
    }
  }
  
  return;
  
FAIL_EXIT:  
  {
    tst_dump_info.tst_write2_sd_option = TST_Write2File_None;
    if (caller_context ==0)
      tst_log_to_file_ShowError();
  }
  return;
}

/*************************************************************************
* FUNCTION                                                            
*  tst_file_check_and_dump_isr_log
*
* DESCRIPTION                                                           
*   check if there is data in bufer for L1 to dump data to the log file
*
* PARAMETERS
*  None
* 
*
* RETURNS
*  None
*
*
*****************************************************************************/
__tstfileFunc void tst_file_check_and_dump_isr_log(void)
{
  kal_uint8 *dataPtr;
  kal_uint32 nPreHalfLen;
  kal_uint32 nLen;
  kal_uint32 _savedMask;
  kal_bool   bWrap;
  
  bWrap = KAL_FALSE;
  nPreHalfLen = 0;
  
  if (tst_dump_info.tst_write2_sd_option == TST_Write2File_None)
  {
    return;
  }
  
  _savedMask = SaveAndSetIRQMask();  
  nLen = (TST_L1_BUFFER_SIZE_FOR_WRITE_FILE - 1) - tst_dump_info.nL1BufferVancancy;
  if (tst_dump_info.nL1BufferWritePtr >= nLen)
  {
    dataPtr = &tst_dump_info.L1Buffer[0] + tst_dump_info.nL1BufferWritePtr - nLen;
  }
  else
  {
    bWrap = KAL_TRUE;
    nPreHalfLen = nLen - tst_dump_info.nL1BufferWritePtr;
    dataPtr = &tst_dump_info.L1Buffer[0] + TST_L1_BUFFER_SIZE_FOR_WRITE_FILE
                                         - nPreHalfLen;
  }  
  RestoreIRQMask(_savedMask);
  if (nLen == 0) return;
  
  //TST can never preempt L1, so the packet must be complete
  tst_dump_info.bHeadOfOnePacket = KAL_TRUE;
  
  if (bWrap)
  {
    tst_file_dump_log_to_file(dataPtr, nPreHalfLen, 0);
    tst_dump_info.bHeadOfOnePacket = KAL_FALSE;
    
    dataPtr = &tst_dump_info.L1Buffer[0];
    tst_file_dump_log_to_file(dataPtr, nLen - nPreHalfLen, 0);
  }
  else
  {
    tst_file_dump_log_to_file(dataPtr, nLen, 0);
    tst_dump_info.bHeadOfOnePacket = KAL_FALSE;
  }
    
  _savedMask = SaveAndSetIRQMask();  
  tst_dump_info.nL1BufferVancancy += nLen;
  RestoreIRQMask(_savedMask);
  ASSERT(tst_dump_info.nL1BufferVancancy < TST_L1_BUFFER_SIZE_FOR_WRITE_FILE);
  
}

/*************************************************************************
* FUNCTION                                                            
*  tst_file_dump_isr_log_to_file
*
* DESCRIPTION                                                           
*   dump data to the log file under the HISR context
*   No waiting is allowed.
* PARAMETERS
*  None
* 
*
* RETURNS
*  the address of unsent pointer, 0 for complete
*
*
*****************************************************************************/
__tstfileFunc kal_uint32 tst_file_dump_isr_log_to_file(kal_uint8 *buffer, kal_uint32 length)
{
  if (tst_dump_info.tst_write2_sd_option == TST_Write2File_None) return 0;
  
  if(kal_query_boot_mode() != NORMAL_BOOT) 
    return 0;  
  
  if (length > tst_dump_info.nFileFreeSpace)
  {    
    kal_bool LOG_DISK_FULL  = KAL_FALSE;
    ASSERT(LOG_DISK_FULL);    
  }
  else  //if (length > tst_dump_info.nFileFreeSpace)
  {
    tst_dump_info.nFileFreeSpace -= length;
  }  //end of if (length > tst_dump_info.nFileFreeSpace)
  
  if (tst_dump_info.nBufferPtr + length < TST_FSWRITE_BUFFER_SIZE)
  {
    kal_mem_cpy(tst_dump_info.buffer + tst_dump_info.nBufferPtr, buffer, length);
    tst_dump_info.nBufferPtr += length;
  }
  else
  {
    kal_uint32 nHalfLen;
    nHalfLen = TST_FSWRITE_BUFFER_SIZE - tst_dump_info.nBufferPtr;
    kal_mem_cpy(tst_dump_info.buffer + tst_dump_info.nBufferPtr, buffer, nHalfLen);
      
    //invoke TST File Transfer to move data to files          
    kal_set_eg_events(tst_event_group, TST_EVENT_WRITE_TO_FILE, KAL_OR);      

    return nHalfLen;
  }
  
  return 0;  
}

__tstfileFunc void tst_file_set_tst_write2_sd_option(tst_write2_sd_option_t tst_write2_sd_option)
{
  tst_dump_info.tst_write2_sd_option = tst_write2_sd_option;
}

__tstfileFunc kal_bool tst_file_query_if_write2sd_start(void)
{
  if (tst_dump_info.cDriveLetter == 0xFF)
    return KAL_FALSE;
  else
    return KAL_TRUE;  
}

__tstfileFunc kal_uint32 tst_file_query_omit_pkt(void)
{
  return tst_dump_info.nOmitPacketCount;  
}

__tstfileFunc FS_HANDLE tst_file_query_write_handler(void)
{
  return tst_dump_info.fHandle;
}

__tstfileFunc void tst_file_set_write_handler(FS_HANDLE fHandle)
{
  tst_dump_info.fHandle = fHandle;
}

__tstfileFunc WCHAR* tst_file_query_assert_folder_name(void)
{
  return tst_dump_info.strAssertFolderName;  
}

__tstfileFunc kal_int32 tst_file_store_unsaved_log(void)
{
  kal_int32 res = FS_NO_ERROR;
  
  if (tst_dump_info.nBufferPtr > 0)
  {
    res = FS_Write(tst_dump_info.fHandle, tst_dump_info.buffer, tst_dump_info.nBufferPtr, NULL);    
  }
  
  return res;
}

__tstfileFunc kal_bool tst_file_set_already_dump(void)
{
  if (tst_dump_info.bAlreadyAssertDump)
  {
    tst_dump_info.tst_write2_sd_option = TST_Write2File_None;
    return KAL_TRUE;
  }
  else
  {
    tst_dump_info.bAlreadyAssertDump = KAL_TRUE;    
    return KAL_FALSE;
  }
}

//export functions for exception handler
__tstfileFunc void tst_dump_to_file_for_crash(void)
{
  tst_dump_to_file_for_crash_internal();
}

__tstfileFunc int tst_lga_save_logs(kal_uint8* buf, kal_uint32 len)
{
#if defined(__LOGACC_ENABLE__) && !defined(UNIT_TEST)   
  kal_uint32 _savedMask = 0;  
  
  if (tst_dump_info.tst_write2_sd_option == TST_Write2File_None) return -1;
  
  //some pending data
  if (b_lga_log_unsent) return -2;
    
  //Save the buffer position and length
  lga_buf_ptr = buf;
  lga_buf_len = len;
  
  _savedMask = SaveAndSetIRQMask();  
  b_lga_log_unsent = KAL_TRUE;
  RestoreIRQMask(_savedMask);
  
  //trigger TFT to move data
  //TFT will activate LGA HISR afterward
  kal_set_eg_events(tst_event_group, TST_EVENT_LGA_LOG2FILE_REQ, KAL_OR);      
#endif  //#if defined(__LOGACC_ENABLE__) && !defined(UNIT_TEST) 

  return 0;
}

//This function is used by USB driver under data card projects.
//On data card projects, MS reports itself as CDROM in the begining.
//Then SD card is locked. 
//SD card will be unlocked if we set it as 3 comports
//If we don't wait it for ready, we can't do logging
__tstfileFunc kal_uint32 tst_file_notify_sd_ready(void)
{
#ifdef __USB_MODEM_CARD_SUPPORT__    
  if (tst_dump_info.tst_write2_sd_option != TST_Write2File_None)
  {
    kal_set_eg_events(tft_event_group, TFT_EVENT_SD_CARD_READY, KAL_OR); //Set the event
    return 1;
  }
#endif  //#ifdef __USB_MODEM_CARD_SUPPORT__  
  
  return 0;
}


#else //#ifdef __TST_WRITE_TO_FILE__
#include "kal_public_api.h"
#include "tst_ext.h"
#include "tst_file_def.h"

//#pragma arm section code= "PRIMARY_ROCODE" rwdata = "PRIMARY_RW" , rodata = "PRIMARY_RODATA" , zidata = "PRIMARY_ZI" 

__tstfileFunc tst_write2_sd_option_t tst_file_query_write2file_option(void) { return TST_Write2File_None;}
__tstfileFunc kal_uint32 tst_file_query_l1_log_space(void){ return 0xFFFFFFFF; }
__tstfileFunc kal_uint32 tst_file_query_ps_log_space(void){ return 0xFFFFFFFF; }
__tstfileFunc void tst_file_init_l1_log_buf(void){}
__tstfileFunc void tst_file_sp_check_sd_ready(void){}
__tstfileFunc kal_uint32 tst_file_check_if_output2uart(void){return 0;}
__tstfileFunc kal_uint32 tst_file_indicate_write2file_only(void){return 0;}
__tstfileFunc kal_uint32 tst_file_dump_isr_log_to_file(kal_uint8 *buffer, kal_uint32 length){return 0;}
__tstfileFunc void tst_dump_reset_file_buf_info(void){}
__tstfileFunc kal_bool tst_file_get_ps_log_head_packet(void){ return KAL_FALSE;}
__tstfileFunc kal_uint32 tst_file_request_file_space_on_disk(kal_uint32 request_space){return 0;}
__tstfileFunc kal_uint32 tst_file_query_disk_space(void){return 0;}
__tstfileFunc void tst_file_discard_rest_file_space(void){}
__tstfileFunc kal_uint32 tst_file_reserve_ps_log_space(kal_uint32 length){return 0;}
__tstfileFunc void tst_file_set_tst_write2_sd_option(tst_write2_sd_option_t tst_write2_sd_option){}
__tstfileFunc kal_bool tst_file_query_if_write2sd_start(void){return KAL_FALSE;}
__tstfileFunc kal_uint32 tst_file_query_omit_pkt(void){return 0;}
__tstfileFunc FS_HANDLE tst_file_query_write_handler(void){return NULL;}
__tstfileFunc WCHAR* tst_file_query_assert_folder_name(void){ return NULL;}
__tstfileFunc kal_uint32 tst_file_query_nBufferPtr(void){return 0;}
__tstfileFunc kal_bool tst_file_set_already_dump(void){return KAL_FALSE;}
__tstfileFunc kal_bool tst_file_reserve_disk_space(kal_uint32 length){return KAL_FALSE;}
__tstfileFunc void tst_file_dump_log_to_file(kal_uint8 *buffer, kal_uint32 length, kal_uint32 caller_context){}
__tstfileFunc void tst_dump_to_file_for_crash(void){}
__tstfileFunc void tst_file_set_write_handler(FS_HANDLE fHandle){}
__tstfileFunc kal_int32 tst_file_store_unsaved_log(void){}
__tstfileFunc void tst_file_check_and_dump_isr_log(void){}
__tstfileFunc void tst_file_set_ps_log_head_packet(kal_bool value){}
__tstfileFunc int tst_lga_save_logs(kal_uint8* buf, kal_uint32 len){return 0;}
__tstfileFunc kal_uint32 tst_file_notify_sd_ready(void){return 0;}
#endif //end of #ifdef __TST_WRITE_TO_FILE__

